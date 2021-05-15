#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0xa, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_18), 

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_CASTLE_GROUNDS, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_FLAME, 125, 77, -1867, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_TOAD2, 115, 77, -2032, 0, 0, 0, 0x01000000, bhvToad2),
		OBJECT(MODEL_TOAD2, 36, 77, -2008, 0, 0, 0, 0x00000000, bhvToad2),
		OBJECT(MODEL_TOAD2, 274, 77, -2032, 0, 0, 0, 0x02000000, bhvToad2),
		OBJECT(MODEL_TOAD_BUILDER, 536, 77, -2032, 0, 0, 0, 0x02000000, bhvToad2),
		OBJECT(MODEL_TOAD_BUILDER_HAMMER, 733, 77, -2032, 0, 0, 0, 0x03000000, bhvToad2),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -332, 77, -2008, 0, 0, 0, 0x00010000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -662, 77, -2008, 0, 0, 0, 0x00020000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -993, 77, -2008, 0, 0, 0, 0x00030000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -1312, 77, -2543, 0, 0, 0, 0x00040000, bhvWarpPipe),
		OBJECT(MODEL_NONE, 14, -51, -221, 0, 0, 0, 0x00020000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 0, 97, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 97, 0),
		OBJECT(MODEL_NONE, 3985, 362, -1073, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_TARREY_TOWN_1),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, castle_grounds_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_FLAME, 125, 77, -1867, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_TOAD2, 115, 77, -2032, 0, 0, 0, 0x01000000, bhvToad2),
		OBJECT(MODEL_TOAD2, 36, 77, -2008, 0, 0, 0, 0x00000000, bhvToad2),
		OBJECT(MODEL_TOAD2, 2553, 264, -3088, 0, -63, 0, 0x02000000, bhvToad2),
		OBJECT(MODEL_TOAD2, 2449, 466, 2696, 0, -64, 0, 0x02000000, bhvToad2),
		OBJECT(MODEL_TOAD2, -1996, 137, 2152, 0, -171, 0, 0x02000000, bhvToad2),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -306, 77, -2008, 0, 0, 0, 0x00010000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -534, 77, -2008, 0, 0, 0, 0x00020000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -720, 77, -2008, 0, 0, 0, 0x00030000, bhvWarpPipe),
		OBJECT(MODEL_NONE, 14, -51, -221, 0, 0, 0, 0x00010000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 0, 97, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 97, 0),
		OBJECT(MODEL_NONE, 3985, 362, -1073, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		TERRAIN(castle_grounds_area_2_collision),
		MACRO_OBJECTS(castle_grounds_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_TARREY_TOWN_1),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 97, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
