#include "point_lights.h"

void bhv_lighting_bolt_loop(void) {
    f32 rand = random_float();
    Vec3f pos = {gMarioState->pos[0], gMarioState->pos[1] + 500, gMarioState->pos[2]};
    emit_light(pos, 255, 255, 255, 0, 0, 0);
    if (rand < 0.5f) {
        //o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    } else {
        //o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
}