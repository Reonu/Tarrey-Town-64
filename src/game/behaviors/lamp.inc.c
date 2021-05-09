#include "point_lights.h"
void bhv_lamp_loop(void) {
    Vec3f pos = {o->oPosX, o->oPosY, o->oPosZ};
    f32 rand = random_float();
    if (rand < 0.95) {
        emit_light(pos, 255, 255, 255, 10, 0, 0);
    }
    
}