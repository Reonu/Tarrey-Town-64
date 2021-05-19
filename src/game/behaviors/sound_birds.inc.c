#include "point_lights.h"
#include "include/seq_ids.h"
// sound_birds.inc.c
void bhv_birds_sound_init(void) {
    extern u8 sCurrentBackgroundMusicSeqId;
    u8 bparam1 = (o->oBehParams >> 24) & 0xFF;
    switch (bparam1) {
        case 0x01:
            stop_background_music(sCurrentBackgroundMusicSeqId);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STREAMED_ANCIENT_TOWN), 30);
            break;  
        case 0x02:  
            stop_background_music(sCurrentBackgroundMusicSeqId);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STREAMED_RESURRECTION_CHASE), 30);
            break;
    }
}


void bhv_birds_sound_loop(void) {
    s32 lightLevel = 0;
    u8 bparam2 = (o->oBehParams >> 16) & 0xFF;
    Vec3f dir = {0.0f, -1.0f, 0.0f};
    switch (bparam2) {
        case 0x01:
            lightLevel = 255;
            set_directional_light(dir, lightLevel, lightLevel, lightLevel);
            set_ambient_light(lightLevel/3,lightLevel/3,lightLevel/3);
            break;
        case 0x00:
            if (gIsConsole) {
                if ((gCurrLevelNum == LEVEL_BOB) && (gCurrAreaIndex == 0x02)) {
                    lightLevel = 110;
                } else {
                    lightLevel = 80;
                }
            } else {
                lightLevel = 55;
            }
            set_directional_light(dir, lightLevel, lightLevel, lightLevel);
            set_ambient_light(lightLevel/3,lightLevel/3,lightLevel/3);
            break;
        case 0x02:
            dir[0] = 0.5f;
            dir[1] = 0.f;
            dir[2] = 0.f;
            
            set_directional_light(dir, 255, 255, 150);
            set_ambient_light(255/3,255/3,150/3);
            break;
        case 0x03:
            dir[0] = 0.f;
            dir[1] = -0.9f;
            dir[2] = 0.f;
            
            set_directional_light(dir, 255, 255, 150);
            set_ambient_light(255/3,255/3,150/3);
            break;
        case 0x30:
            if (o->oTimer == 1) {
                set_mario_action(gMarioState, ACT_READING_AUTOMATIC_DIALOG, 140);
            }
            if (o->oTimer > 1) {
                obj_mark_for_deletion(o);
            }
            break;
        case 0x31:
            if (o->oTimer == 1) {
                set_mario_action(gMarioState, ACT_READING_AUTOMATIC_DIALOG, 141);
            }
            if (o->oTimer > 1) {
                obj_mark_for_deletion(o);
            }
            break;  
    }

}
