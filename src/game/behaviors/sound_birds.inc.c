#include "point_lights.h"
// sound_birds.inc.c

void bhv_birds_sound_loop(void) {
    Vec3f dir = {0.0f, -1.0f, 0.0f};
    set_directional_light(dir, 25, 25, 25);
    set_ambient_light(25,25,25);
}
