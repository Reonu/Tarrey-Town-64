#include "point_lights.h"
void bhv_lamp_loop(void) {
    Vec3f pos = {o->oPosX, o->oPosY, o->oPosZ};
    f32 rand = random_float();
    switch ((o->oBehParams >> 24) & 0xFF) {
        case 0x00:
            emit_light(pos, 255, 255, 255, 0, 0, 20);
            break;
        case 0x01:
            if (rand < 0.95) {
                emit_light(pos, 255, 255, 255, 0, 0, 20);
            }
            break;
        case 0x02:
            if (rand > 0.5) {
            emit_light(pos, 0, 0, 255, 0, 0, 20);
            }
            break;
    }
}