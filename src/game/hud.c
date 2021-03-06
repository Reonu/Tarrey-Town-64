#include <PR/ultratypes.h>

#include "sm64.h"
#include "actors/common1.h"
#include "gfx_dimensions.h"
#include "game_init.h"
#include "level_update.h"
#include "camera.h"
#include "print.h"
#include "ingame_menu.h"
#include "hud.h"
#include "segment2.h"
#include "area.h"
#include "save_file.h"
#include "print.h"
#include "engine/surface_load.h"

#define HUD_BOTTOM_Y 20

/* @file hud.c
 * This file implements HUD rendering and power meter animations.
 * That includes stars, lives, coins, camera status, power meter, timer
 * cannon reticle, and the unused keys.
 **/

// ------------- FPS COUNTER ---------------
// To use it, call print_fps(x,y); every frame.
#define FRAMETIME_COUNT 30

OSTime frameTimes[FRAMETIME_COUNT];
u8 curFrameTimeIndex = 0;

#include "PR/os_convert.h"

// Call once per frame
f32 calculate_and_update_fps()
{
    OSTime newTime = osGetTime();
    OSTime oldTime = frameTimes[curFrameTimeIndex];
    frameTimes[curFrameTimeIndex] = newTime;

    curFrameTimeIndex++;
    if (curFrameTimeIndex >= FRAMETIME_COUNT)
        curFrameTimeIndex = 0;


    return ((f32)FRAMETIME_COUNT * 1000000.0f) / (s32)OS_CYCLES_TO_USEC(newTime - oldTime);
}

void print_fps(s32 x, s32 y)
{
    f32 fps = calculate_and_update_fps();
    char text[10];

    sprintf(text, "%2.2f", fps);

    print_text(x, y, text);
}

// ------------ END OF FPS COUNER -----------------

struct PowerMeterHUD {
    s8 animation;
    s16 x;
    s16 y;
    f32 unused;
};

struct UnusedHUDStruct {
    u32 unused1;
    u16 unused2;
    u16 unused3;
};

struct CameraHUD {
    s16 status;
};

// Stores health segmented value defined by numHealthWedges
// When the HUD is rendered this value is 8, full health.
static s16 sPowerMeterStoredHealth;

static struct PowerMeterHUD sPowerMeterHUD = {
    POWER_METER_HIDDEN,
    30,
    166,
    1.0,
};

// Power Meter timer that keeps counting when it's visible.
// Gets reset when the health is filled and stops counting
// when the power meter is hidden.
s32 sPowerMeterVisibleTimer = 0;

static struct UnusedHUDStruct sUnusedHUDValues = { 0x00, 0x0A, 0x00 };

static struct CameraHUD sCameraHUD = { CAM_STATUS_NONE };

/**
 * Renders a rgba16 16x16 glyph texture from a table list.
 */
void render_hud_tex_lut(s32 x, s32 y, u8 *texture) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gSPDisplayList(gDisplayListHead++, &dl_hud_img_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 15) << 2, (y + 15) << 2,
                        G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders a rgba16 8x8 glyph texture from a table list.
 */
void render_hud_small_tex_lut(s32 x, s32 y, u8 *texture) {
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                        0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders power meter health segment texture using a table list.
 */
void render_power_meter_health_segment(s16 numHealthWedges) {
    u8 *(*healthLUT)[];

    healthLUT = segmented_to_virtual(&power_meter_health_segments_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       (*healthLUT)[numHealthWedges - 1]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(gDisplayListHead++, 0, 1, 2, 0);
    gSP1Triangle(gDisplayListHead++, 0, 2, 3, 0);
}

/**
 * Renders power meter display lists.
 * That includes the "POWER" base and the colored health segment textures.
 */
void render_dl_power_meter(s16 numHealthWedges) {
    Mtx *mtx;

    mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sPowerMeterHUD.x, (f32) sPowerMeterHUD.y, 0);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gDisplayListHead++, &dl_power_meter_base);

    if (numHealthWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_begin);
        render_power_meter_health_segment(numHealthWedges);
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_end);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Power meter animation called when there's less than 8 health segments
 * Checks its timer to later change into deemphasizing mode.
 */
void animate_power_meter_emphasized(void) {
    s16 hudDisplayFlags;
    hudDisplayFlags = gHudDisplay.flags;

    if (!(hudDisplayFlags & HUD_DISPLAY_FLAG_EMPHASIZE_POWER)) {
        if (sPowerMeterVisibleTimer == 45.0) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
        }
    } else {
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Power meter animation called after emphasized mode.
 * Moves power meter y pos speed until it's at 200 to be visible.
 */
static void animate_power_meter_deemphasizing(void) {
    s16 speed = 5;

    if (sPowerMeterHUD.y >= 181) {
        speed = 3;
    }

    if (sPowerMeterHUD.y >= 191) {
        speed = 2;
    }

    if (sPowerMeterHUD.y >= 196) {
        speed = 1;
    }

    sPowerMeterHUD.y += speed;

    if (sPowerMeterHUD.y >= 201) {
        sPowerMeterHUD.y = 200;
        sPowerMeterHUD.animation = POWER_METER_VISIBLE;
    }
}

/**
 * Power meter animation called when there's 8 health segments.
 * Moves power meter y pos quickly until it's at 301 to be hidden.
 */
static void animate_power_meter_hiding(void) {
    sPowerMeterHUD.y += 20;
    if (sPowerMeterHUD.y >= 301) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Handles power meter actions depending of the health segments values.
 */
void handle_power_meter_actions(s16 numHealthWedges) {
    // Show power meter if health is not full, less than 8
    if (numHealthWedges < 8 && sPowerMeterStoredHealth == 8 && sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        sPowerMeterHUD.animation = POWER_METER_EMPHASIZED;
        sPowerMeterHUD.y = 166;
    }

    // Show power meter if health is full, has 8
    if (numHealthWedges == 8 && sPowerMeterStoredHealth == 7) {
        sPowerMeterVisibleTimer = 0;
    }

    // After health is full, hide power meter
    if (numHealthWedges == 8 && sPowerMeterVisibleTimer > 45.0) {
        sPowerMeterHUD.animation = POWER_METER_HIDING;
    }

    // Update to match health value
    sPowerMeterStoredHealth = numHealthWedges;

    // If Mario is swimming, keep power meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sPowerMeterHUD.animation == POWER_METER_HIDDEN
            || sPowerMeterHUD.animation == POWER_METER_EMPHASIZED) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
            sPowerMeterHUD.y = 166;
        }
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Renders the power meter that shows when Mario is in underwater
 * or has taken damage and has less than 8 health segments.
 * And calls a power meter animation function depending of the value defined.
 */
void render_hud_power_meter(void) {
    s16 shownHealthWedges = gHudDisplay.wedges;

    if (sPowerMeterHUD.animation != POWER_METER_HIDING) {
        handle_power_meter_actions(shownHealthWedges);
    }

    if (sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        return;
    }

    switch (sPowerMeterHUD.animation) {
        case POWER_METER_EMPHASIZED:
            animate_power_meter_emphasized();
            break;
        case POWER_METER_DEEMPHASIZING:
            animate_power_meter_deemphasizing();
            break;
        case POWER_METER_HIDING:
            animate_power_meter_hiding();
            break;
        default:
            break;
    }

    render_dl_power_meter(shownHealthWedges);

    sPowerMeterVisibleTimer += 1;
}

#ifdef VERSION_JP
#define HUD_TOP_Y 210
#else
#define HUD_TOP_Y 209
#define HUD_BOTTOM_Y 20
#endif
void render_credits(void) {
    if (gCreditsTimer > 0 && gCreditsTimer < 120 ) {
        print_text(10, 220, "HACK BY REONU");
        print_text(10, 200, "LIGHTING ENGINE BY");
        print_text(10, 180, "WISEGUY");
    }
    if (gCreditsTimer > 120 && gCreditsTimer < 240 ) {
        print_text(10, 220, "SPECIAL THANKS TO");
        print_text(10, 200, "WISEGUY");
        print_text(10, 180, "LIGHTING ENGINE & HELP");
    }
    if (gCreditsTimer > 240 && gCreditsTimer < 360 ) {
        print_text(10, 220, "SPECIAL THANKS TO");
        print_text(10, 200, "ANONYMOUS_MOOSE & BEEF");
        print_text(10, 180, "BLENDER HELP");
    }
    if (gCreditsTimer > 360 && gCreditsTimer < 480 ) {
        print_text(10, 220, "SPECIAL THANKS TO");
        print_text(10, 200, "THECOZIES");
        print_text(10, 180, "CODE HELP");
    }
    if (gCreditsTimer > 480 && gCreditsTimer < 600 ) {
        print_text(10, 220, "SPECIAL THANKS TO");
        print_text(10, 200, "PYRO & MRCOMIT");
        print_text(10, 180, "ADVICE & HELP");
    }
    if (gCreditsTimer > 600 && gCreditsTimer < 680 ) {
        print_text(10, 220, "SPECIAL THANKS TO");
        print_text(10, 200, "YOSHI MILKMAN");
        print_text(10, 180, "KOOPA MODEL");
    }
}
/**111
 * Renders the amount of lives Mario has.
 */
extern u8 renderBolt;
void render_hud_mario_lives(void) {
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(22), HUD_TOP_Y, ","); // 'Mario Head' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(38), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(54), HUD_TOP_Y, "%d", renderBolt);
}
extern u32 gObjectCounter;
void render_debug_mode(void) {
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(170), HUD_BOTTOM_Y, "DEBUG MODE");
    print_text(10,60,"Z");
    print_text_fmt_int(25, 60, "%d", gMarioState->pos[2]);
    print_text(10,80,"Y");
    print_text_fmt_int(25, 80, "%d", gMarioState->pos[1]);
    print_text(10,100,"X");
    print_text_fmt_int(25, 100, "%d", gMarioState->pos[0]);
    print_text_fmt_int(10, 120, "%d", gCustomCameraMode);
    print_fps(10,160);
}
/**
 * Renders the amount of coins collected.
 */
#define HUD_COINS 20

void render_hud_coins(void) {
    print_text(HUD_COINS, HUD_BOTTOM_Y+20, "+"); // 'Coin' glyph
    print_text(HUD_COINS+16, HUD_BOTTOM_Y+20, "*"); // 'X' glyph
    print_text_fmt_int(HUD_COINS+30, HUD_BOTTOM_Y+20, "%d", ((gMarioState->floor->force >> 8) & 0xFF));
}

#ifdef VERSION_JP
#define HUD_STARS_X 73
#else
#define HUD_STARS_X 20
#endif

/**
 * Renders the amount of stars collected.
 * Disables "X" glyph when Mario has 100 stars or more.
 */
void render_hud_stars(void) {
    s8 showX = 0;

    if (gHudFlash == 1 && gGlobalTimer & 0x08) {
        return;
    }

    if (gHudDisplay.stars < 100) {
        showX = 1;
    }

    print_text((HUD_STARS_X), HUD_BOTTOM_Y, "-"); // 'Star' glyph
    if (showX == 1) {
        print_text((HUD_STARS_X) + 16, HUD_BOTTOM_Y, "*"); // 'X' glyph
    }
    print_text_fmt_int((showX * 14) + (HUD_STARS_X + 16),
                       HUD_BOTTOM_Y, "%d", gHudDisplay.stars);
}

/**
 * Unused function that renders the amount of keys collected.
 * Leftover function from the beta version of the game.
 */
void render_hud_keys(void) {
    s16 i;

    for (i = 0; i < gHudDisplay.keys; i++) {
        print_text((i * 16) + 220, 142, "/"); // unused glyph - beta key
    }
}

/**
 * Renders the timer when Mario start sliding in PSS.
 */
void render_hud_timer(void) {
    u8 *(*hudLUT)[58];
    u16 timerValFrames;
    u16 timerMins;
    u16 timerSecs;
    u16 timerFracSecs;

    hudLUT = segmented_to_virtual(&main_hud_lut);
    timerValFrames = gHudDisplay.timer;
#ifdef VERSION_EU
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
            break;
        case LANGUAGE_FRENCH:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(155), 185, "TEMPS");
            break;
        case LANGUAGE_GERMAN:
            print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "ZEIT");
            break;
    }
#endif
    timerMins = timerValFrames / (30 * 60);
    timerSecs = (timerValFrames - (timerMins * 1800)) / 30;

    timerFracSecs = ((timerValFrames - (timerMins * 1800) - (timerSecs * 30)) & 0xFFFF) / 3;
#ifndef VERSION_EU
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
#endif
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(91), 185, "%0d", timerMins);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(71), 185, "%02d", timerSecs);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(37), 185, "%d", timerFracSecs);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(81), 32, (*hudLUT)[GLYPH_APOSTROPHE]);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(46), 32, (*hudLUT)[GLYPH_DOUBLE_QUOTE]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

/**
 * Sets HUD status camera value depending of the actions
 * defined in update_camera_status.
 */
void set_hud_camera_status(s16 status) {
    sCameraHUD.status = status;
}

/**
 * Renders camera HUD glyphs using a table list, depending of
 * the camera status called, a defined glyph is rendered.
 */
void render_hud_camera_status(void) {
    u8 *(*cameraLUT)[6];
    s32 x;
    s32 y;

    cameraLUT = segmented_to_virtual(&main_hud_camera_lut);
    x = GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(54);
    y = 205;

    if (sCameraHUD.status == CAM_STATUS_NONE) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(x, y, (*cameraLUT)[GLYPH_CAM_CAMERA]);

    switch (sCameraHUD.status & CAM_STATUS_MODE_GROUP) {
        case CAM_STATUS_MARIO:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_MARIO_HEAD]);
            break;
        case CAM_STATUS_LAKITU:
            if (gCustomCameraMode) {
                render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_FIXED]);
            } else {
                render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_LAKITU_HEAD]);
            }
            
            break;
        case CAM_STATUS_FIXED:
            
            break;
    }

    switch (sCameraHUD.status & CAM_STATUS_C_MODE_GROUP) {
        case CAM_STATUS_C_DOWN:
            render_hud_small_tex_lut(x + 4, y + 16, (*cameraLUT)[GLYPH_CAM_ARROW_DOWN]);
            break;
        case CAM_STATUS_C_UP:
            render_hud_small_tex_lut(x + 4, y - 8, (*cameraLUT)[GLYPH_CAM_ARROW_UP]);
            break;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

extern int gPointLightCompatibilityMode;

/**
 * Render HUD strings using hudDisplayFlags with it's render functions,
 * excluding the cannon reticle which detects a camera preset for it.
 */

#include <plugin_catcher.h>

static char pluginErrorMsg[] = PLUGIN_ERROR_MESSAGE;
extern u8 gDialogCharWidths[];

const Gfx dl_load_text_tex[] = {
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 3, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, ((16 * 8 + G_IM_SIZ_4b_INCR) >> G_IM_SIZ_4b_SHIFT) - 1, CALC_DXT(16, G_IM_SIZ_4b_BYTES)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_4b, 1, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 3, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 4, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (16 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

static void render_blocker_generic_char(u8 c, s32 x, s32 y, void **fontLUT) {
    void *packedTexture;

    packedTexture = segmented_to_virtual(fontLUT[c]);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, dl_load_text_tex);
    gSPTextureRectangleFlip(gDisplayListHead++, x << 2, (y - 16) << 2,
                            (x + 8) << 2, y << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 0xFFFF << 10, 0xFFFF << 10);
}

void print_blocker_text(void) {
    u32 j;
    s32 x = 30;
    s32 y = 60;
    s32 pos = 0;
    s32 asciiChar, dialogChar;
    void **fontLUT = segmented_to_virtual(main_font_lut);

    for (j = 0; j < sizeof(pluginErrorMsg) - 1; j++) {
        asciiChar = pluginErrorMsg[j];
        dialogChar = 0;
        switch (asciiChar) {
            case '\n':
                pos = 0;
                y += 20;
                break;
            case ' ':
                pos += gDialogCharWidths[DIALOG_CHAR_SPACE];
                break;
            case '.':
                dialogChar = 0x3F;
                break;
            case '\'':
                dialogChar = 0x3E;
                break;
            case ',':
                dialogChar = DIALOG_CHAR_COMMA;
                break;
            case '-':
                dialogChar = 0x9F;
                break;
            case '(':
                dialogChar = 0xE1;
                break;
            case ')':
                dialogChar = 0xE3;
                break;
            default:
                dialogChar = ASCII_TO_DIALOG(asciiChar);
                break;
        }
        if (dialogChar != 0) {
            render_blocker_generic_char(dialogChar, x + pos, y, fontLUT);
            pos += gDialogCharWidths[dialogChar];
        }
    }
}

void block_plugins(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    // // only blocks gliden64 lol
    // gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_XLU_SURF2);
    // gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);

    // // only passes jabo
    // gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    // gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);

    // Block Jabo, PJ64 Video, LINK's GLideN64
#if defined(CATCH_ALL_BAD_PLUGINS) || defined(CATCH_JABO)
    // Block Jabo
    // Jabo sets shade alpha to 255 for fillrects instead of 0, so this only shows up on that plugin
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE);
    gDPFillRectangle(gDisplayListHead++, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 1);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, 1, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, 1, 0, ENVIRONMENT, 0);
    // gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0,   COMBINED, 0, ENVIRONMENT, 0,   0, 0, 0, TEXEL0,   COMBINED, 0, ENVIRONMENT, 0);
    print_blocker_text();
    gDPPipeSync(gDisplayListHead++);
#endif
#if defined(CATCH_ALL_BAD_PLUGINS) || defined(CATCH_GLIDE64_PJ64VIDEO)
    // Block PJ64 Video, Glide64
    // This combiner/render mode combo doesn't show up in any plugin except Glide64/PJ64 Video
    gDPSetFogColor(gDisplayListHead++, 0, 0, 0, 0);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetRenderMode(gDisplayListHead++, CVG_DST_CLAMP | IM_RD | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | TEX_EDGE | AA_EN | GBL_c1(G_BL_0, G_BL_0, G_BL_A_FOG, G_BL_1MA), GBL_c2(G_BL_0, G_BL_0, G_BL_A_FOG, G_BL_1MA));
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT);
    gDPFillRectangle(gDisplayListHead++, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0,   COMBINED, 0, COMBINED, 0,   0, 0, 0, TEXEL0,   COMBINED, 0, COMBINED, 0);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP); // Turn on bilerp because Glide64 looks bad with point filtered texrects
    print_blocker_text();
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
#endif
#if defined(CATCH_ALL_BAD_PLUGINS) || defined(CATCH_OLD_LINKS_GLIDEN64)
    // Block Old (4.0) LINK's GLideN64
    // LINK's GLideN64 4.0 replaces the second combiner cycle with 0, 0, 0, COMBINED unconditionally, so this only shows up on that plugin
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_TEX_EDGE2);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, COMBINED, 0, 0, 0, 0);
    gDPFillRectangle(gDisplayListHead++, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, 1,   0, 0, 0, TEXEL0,   0, 0, 0, COMBINED,   0, 0, 0, 0);
    // gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    print_blocker_text();
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
#endif
    // Restore render mode
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
}

void render_hud(void) {
    s16 hudDisplayFlags;
#ifdef VERSION_EU
    Mtx *mtx;
#endif

    if (!gIsConsole) {
        block_plugins();
    }

    hudDisplayFlags = gHudDisplay.flags;

    if (hudDisplayFlags == HUD_DISPLAY_NONE) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterStoredHealth = 8;
        sPowerMeterVisibleTimer = 0;
    } else {
#ifdef VERSION_EU
        // basically create_dl_ortho_matrix but guOrtho screen width is different

        mtx = alloc_display_list(sizeof(*mtx));
        if (mtx == NULL) {
            return;
        }
        create_dl_identity_matrix();
        guOrtho(mtx, -16.0f, SCREEN_WIDTH + 16, 0, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx),
                G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
#else
        create_dl_ortho_matrix();
#endif

        if (gCurrentArea != NULL && gCurrentArea->camera->mode == CAMERA_MODE_INSIDE_CANNON) {
            render_hud_cannon_reticle();
        }

        /*if (hudDisplayFlags & HUD_DISPLAY_FLAG_LIVES) {
            render_hud_mario_lives();
        }*/

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_COIN_COUNT) {
            //render_hud_coins();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_STAR_COUNT) {
            //render_hud_stars();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_KEYS) {
            render_hud_keys();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_CAMERA_AND_POWER) {
            render_hud_power_meter();
            render_hud_camera_status();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_TIMER) {
            render_hud_timer();
        }

        if (gSurfacePoolError & NOT_ENOUGH_ROOM_FOR_SURFACES)
        {
            print_text(10, 40, "SURFACE POOL FULL");
        }
        if (gSurfacePoolError & NOT_ENOUGH_ROOM_FOR_NODES)
        {
            print_text(10, 60, "SURFACE NODE POOL FULL");
        }
        if (gCustomDebugMode) {
            render_debug_mode();
        }
    }
}
