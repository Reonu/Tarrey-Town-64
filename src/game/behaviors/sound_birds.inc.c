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
    Vec3f dir = {0.0f, -1.0f, 0.0f};
    set_directional_light(dir, 25, 25, 25);
    set_ambient_light(25,25,25);
}
