#include "game/camera.h"
#include "surface_terrains.h"
extern s16 s8DirModeBaseYaw;
u8 cameraChange;
void bhv_cutscene_handler_init(void) {
    s8DirModeBaseYaw = DEGREES(180);
}

void bhv_cutscene_handler_loop(void) {
    if (gCustomCameraMode = 1) {
        if (gMarioState->floor->type == SURFACE_CAMERA_ROTATE_LEFT) {
            s8DirModeBaseYaw = DEGREES(270);
            cameraChange = 1;
        }
        if (gMarioState->floor->type == SURFACE_CAMERA_MIDDLE) {
            s8DirModeBaseYaw = DEGREES(180);
            cameraChange = 0;
        }
        if ((cameraChange == 1 && gMarioState->floor->type != SURFACE_CAMERA_ROTATE_LEFT)) {
            s8DirModeBaseYaw = DEGREES(180);
            cameraChange = 0;
        }
    }
}