#include "point_lights.h"
#include "include/seq_ids.h"
// sound_birds.inc.c
void bhv_birds_sound_init(void) {
    extern u8 sCurrentBackgroundMusicSeqId;
    u8 bparam1 = (o->oBehParams >> 24) & 0xFF;
    switch (bparam1) {
        case 0x01:
            stop_background_music(sCurrentBackgroundMusicSeqId);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STREAMED_ANCIENT_TOWN), 30);
            break;  
        case 0x02:  
            stop_background_music(sCurrentBackgroundMusicSeqId);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STREAMED_RESURRECTION_CHASE), 30);
    }
}


void bhv_birds_sound_loop(void) {
    if (gIsConsole) {
        Vec3f dir = {0.0f, -1.0f, 0.0f};
        set_directional_light(dir, 65, 65, 65);
        set_ambient_light(65/3,65/3,65/3);
    } else {
        Vec3f dir = {0.0f, -1.0f, 0.0f};
        set_directional_light(dir, 55, 55, 55);
        set_ambient_light(55/3,55/3,55/3);
    }

}
