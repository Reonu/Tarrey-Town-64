#include "game/camera.h"
void bhv_cutscene_handler_loop(void) {
    extern s16 s8DirModeBaseYaw;
    if (gCustomCameraMode = 1) {
        s8DirModeBaseYaw = DEGREES(180);
    }
}