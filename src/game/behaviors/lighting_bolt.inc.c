#include "point_lights.h"
#include "sounds.h"
u32 renderBolt = 30;
void bhv_lighting_bolt_loop(void) {
    Vec3f pos = {gMarioState->pos[0], gMarioState->pos[1] + 500, gMarioState->pos[2]};
    renderBolt++;
    if ((renderBolt >30 ) && (random_float()< 0.005f)) {
        renderBolt = 1;
    }
    if ((renderBolt <= 3)) {
        emit_light(pos, 255, 255, 255, 0, 0, 0); 
    } else  if (renderBolt == 29 ) {
            play_sound(SOUND_MARIO_PRESS_START_TO_PLAY, gMarioObject->header.gfx.cameraToObject);
    }
}