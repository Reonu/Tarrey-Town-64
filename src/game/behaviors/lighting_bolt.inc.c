#include "point_lights.h"
#include "sounds.h"
u8 renderBolt;
void bhv_lighting_bolt_loop(void) {
    f32 rand = random_float();
    Vec3f pos = {gMarioState->pos[0], gMarioState->pos[1] + 500, gMarioState->pos[2]};
    
    if ((renderBolt == 0) && (rand < 0.005f)) {
        renderBolt = 1;
    }
    if ((renderBolt != 0) && (renderBolt <= 3)) {
        renderBolt++;
        emit_light(pos, 255, 255, 255, 0, 0, 0); 
    }
    if ((renderBolt >= 4) && (renderBolt <= 30)) {
        renderBolt++;
        if (renderBolt == 29 ) {
            play_sound(SOUND_MARIO_PRESS_START_TO_PLAY, gMarioObject->header.gfx.cameraToObject);
            renderBolt == 0;
        }
    }
    if (renderBolt == 31) {
        renderBolt = 0;
    }
}