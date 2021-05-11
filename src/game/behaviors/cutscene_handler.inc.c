#include "game/camera.h"
#include "surface_terrains.h"
extern s16 s8DirModeBaseYaw;
u8 cameraChange;
void bhv_cutscene_handler_init(void) {
    s8DirModeBaseYaw = DEGREES(180);
}

void bhv_cutscene_handler_loop(void) {
    if (gCustomCameraMode = 1) {
        switch ((gMarioState->floor->force >> 8) & 0xFF) {
            case 0x01:
                s8DirModeBaseYaw = DEGREES(180); // Normal camera
                break;
            case 0x02:
                s8DirModeBaseYaw = DEGREES(270); // Rotate left
                break;
            case 0x03:
                s8DirModeBaseYaw = DEGREES(90); // Rotate right
                break;
            case 0x04:
                s8DirModeBaseYaw = DEGREES(0); // Backtracking camera
                break;
            case 0x06:
                s8DirModeBaseYaw = DEGREES(180); //2D camera
                break;
            case 0x07:
                s8DirModeBaseYaw = DEGREES(180); //Top-down camera
                break;
        }       
    }
}