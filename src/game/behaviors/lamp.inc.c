#include "point_lights.h"
void bhv_lamp_loop(void) {
    Vec3f pos = {o->oPosX, o->oPosY, o->oPosZ};
    Vec3f pos2 = {o->oPosX + 50, o->oPosY, o->oPosZ + 50};
    f32 rand = random_float();
    switch ((o->oBehParams >> 24) & 0xFF) {
        case 0x00:
            emit_light(pos, 255, 255, 255, 0, 0, 15);
            break;
        case 0x01:
            if (rand < 0.95) {
                emit_light(pos, 255, 255, 255, 0, 0, 20);
            }
            break;
        case 0x02:
            if (((gGlobalTimer / 4) & 1) == 0) {
                emit_light(pos, 0, 0, 255, 0, 0, 20);
            } else {
                emit_light(pos2, 255, 0, 0, 0, 0, 20);
            }
            break;
        case 0x03:
            emit_light(pos, 255, 255, 255, 0, 0, 5);
            break;
        case 0x04:
            emit_light(pos, 255, 150, 0, 0, 0, 4);
            break;
        case 0x05:
            emit_light(pos, 255, 0, 0, 0, 0, 25);
            break;
    }
}