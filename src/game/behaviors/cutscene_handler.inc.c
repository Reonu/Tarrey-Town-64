#include "game/camera.h"
#include "surface_terrains.h"
extern s16 s8DirModeBaseYaw;
extern s16 sYawSpeed;
extern s16 s8DirModeYawOffset;
u8 cameraChange;

s16 approach_yaw(s16 curYaw, s16 target, f32 speed) {
    return (s16) (target - approach_f32_asymptotic(
        (s16) (target - curYaw),
        0,
        speed
    ));
}

void bhv_cutscene_handler_init(void) {
    if (((o->oBehParams >> 24) & 0xFF) == 0x01) {
        gCustomCameraMode = 0;
    } else {
        gCustomCameraMode = 1;
        s8DirModeBaseYaw = DEGREES(180);
    }
    
}

void bhv_cutscene_handler_loop(void) {
        switch ((gMarioState->floor->force >> 8) & 0xFF) {
            case 0x01:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(180), 0.2f);
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x02:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(270), 0.2f); // Rotate left
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x03:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(90), 0.2f); // Rotate right
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x04:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(0), 0.2f); // Backtracking camera
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x06:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(180), 0.2f); //2D camera
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x07:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(180), 0.2f); //Top-down camera
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x08:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(0), 0.2f); //Inverted 2D camera
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x09:
                s8DirModeBaseYaw = approach_yaw(gLakituState.yaw, DEGREES(180), 0.2f); //Normal camera looking up
                gCustomCameraMode = 1;
                s8DirModeYawOffset = 0;
                break;
            case 0x0A:
                gCustomCameraMode = 0;
                break;
        }       
}