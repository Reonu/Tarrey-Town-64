#include "game/camera.h"
#include "point_lights.h"
void bhv_car_loop (void) {
    u8 bparam1 = (o->oBehParams >> 24) & 0xFF;
    s8 move1, move2;
    Vec3f pos = {o->oPosX + 300, o->oPosY + 200, o->oPosZ};
    Vec3f pos2 = {o->oPosX - 300, o->oPosY + 200, o->oPosZ};
    switch (bparam1) {
        case 0x00:
            move1 = 100;
            move2 = -100;
            break;
        case 0x01:
            move1 = -100;
            move2 = 100;
            break;
        default:
            move1 = 100;
            move2 = -100;
    }
    if (o->oTimer < 350) {
        o->oPosX += move1;
        o->oFaceAngleYaw = DEGREES(90);
        switch (bparam1) {
            case 0x00:
                emit_light(pos, 255, 255, 255, 0, 0, 15);
                o->oPosZ = o->oHomeZ;
                break;
            case 0x01:
                emit_light(pos2, 255, 255, 255, 0, 0, 15);
                o->oPosZ = o->oHomeZ - 2000;
                break;
        }
    } else if (o->oTimer < 700) {
        o->oPosX += move2;
        o->oFaceAngleYaw = DEGREES(270);
        switch (bparam1) {
            case 0x00:
                emit_light(pos2, 255, 255, 255, 0, 0, 15);
                o->oPosZ = o->oHomeZ + 2000;
                break;
            case 0x01:
                emit_light(pos, 255, 255, 255, 0, 0, 15);
                o->oPosZ = o->oHomeZ;
                break;
        }
    } else {
        o->oTimer = -1;
    }
}