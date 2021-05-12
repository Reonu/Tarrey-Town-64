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
#include "levels/bob/header.h"

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x02, 14550, -300, -4699),
		OBJECT(MODEL_NONE, -1467, -236, -1410, 0, 0, 0, 0x02000000, bhvCutsceneHandler),
		OBJECT(MODEL_RED_FLAME, -7463, 824, 3842, 0, 0, 0, 0x00000000, bhvFlameBig),
		OBJECT(MODEL_RED_FLAME, -7510, 676, 4687, 0, 0, 0, 0x00000000, bhvFlameBig),
		OBJECT(MODEL_RED_FLAME, -7866, 644, 4512, 0, 0, 0, 0x00000000, bhvFlameBig),
		OBJECT(MODEL_RED_FLAME, -7493, 626, 3387, 0, 0, 0, 0x00000000, bhvFlameBig),
		OBJECT(MODEL_NONE, -69, -948, 976, 0, 0, 0, 0x00000000, bhvLightingBolt),
		OBJECT(MODEL_KOOPA_WITH_SHELL, 1240, 0, 842, 0, 0, 0, 0x00010000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITH_SHELL, 1061, 0, 842, 0, 0, 0, 0x07000000, bhvKoopaToad),
		OBJECT(MODEL_KOOPA_WITH_SHELL, -4575, 634, 2902, 0, 0, 0, 0x07000000, bhvKoopaToad),
		OBJECT(MODEL_NONE, 2897, 555, 2892, 0, 0, 0, 0x01000000, bhvLamp),
		OBJECT(MODEL_NONE, -2258, 837, 2871, 0, 0, 0, 0x01000000, bhvLamp),
		OBJECT(MODEL_NONE, -3543, 1088, 2900, 0, 0, 0, 0x01000000, bhvLamp),
		OBJECT(MODEL_NONE, -351, 513, 6318, 0, 0, 0, 0x02000000, bhvLamp),
		OBJECT(MODEL_NONE, -1085, -388, -1410, 0, 0, 0, 0x00000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 1125, 717, -4619, 0, 0, 0, 0x00000000, bhvLamp),
		OBJECT(MODEL_NONE, 1019, 692, -1480, 0, 0, 0, 0x00000000, bhvLamp),
		OBJECT(MODEL_NONE, -1224, 717, 1492, 0, -180, 0, 0x00000000, bhvLamp),
		OBJECT(MODEL_NONE, -1119, 692, -1647, 0, -180, 0, 0x00000000, bhvLamp),
		OBJECT(MODEL_NONE, -1224, 717, -4644, 0, -180, 0, 0x00000000, bhvLamp),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -2630, 686, 4684, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4209, 686, 4684, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -3406, 686, 4684, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_NONE, 14, 200, -4595, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 14, 200, -4595),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_RESURRECTION_RAIN),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x03, 4419, -1353, -7489),
		OBJECT(MODEL_NONE, 9080, -830, 7498, 0, 0, 0, 0x00FF0000, bhvPoleGrabbing),
		OBJECT(MODEL_FLOATING_BOX, 2485, -1047, 7000, 0, 93, 0, 0x04000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, 4787, -1047, 7717, 0, 93, 0, 0x02000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, 6832, -1047, 7191, 0, 93, 0, 0x01000000, bhvFloatingBox),
		OBJECT(MODEL_WOOD_PLATFORM, 9076, -1047, 7504, 0, 0, 0, 0x06000000, bhvWoodPlatform),
		OBJECT(MODEL_PLANK, -6448, -965, 5501, 0, 103, 0, 0x04000000, bhvPlank),
		OBJECT(MODEL_STOOL, -2045, -1047, 165, 0, 31, 0, 0x02000000, bhvFloatingStool),
		OBJECT(MODEL_STOOL, -5180, -1047, 6727, 0, 39, 0, 0x06000000, bhvFloatingStool),
		OBJECT(MODEL_STOOL, -1203, -1047, 7763, 0, 39, 0, 0x03000000, bhvFloatingStool),
		OBJECT(MODEL_WOOD_PLATFORM, 367, -1047, -13, 0, 0, 0, 0x04000000, bhvWoodPlatform),
		OBJECT(MODEL_STOOL, 1532, -1047, -13, 0, 0, 0, 0x05000000, bhvFloatingStool),
		OBJECT(MODEL_FLOATING_BOX, -3655, -1047, 7541, 0, 39, 0, 0x02000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, -3080, -1047, 429, 0, 49, 0, 0x00000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, -406, -1047, 7883, 0, 39, 0, 0x06000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, 267, -1047, 7261, 0, -31, 0, 0x05000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, 1679, -639, 7872, 0, 20, 0, 0x05000000, bhvFloatingBox),
		OBJECT(MODEL_FLOATING_BOX, -6164, -1036, 6743, 0, 49, 0, 0x00000000, bhvFloatingBox),
		OBJECT(MODEL_WOOD_PLATFORM, -2012, -1047, 7705, 0, 39, 0, 0x06000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -1141, -1047, 165, 0, 31, 0, 0x03000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -4277, -1047, 852, 0, 24, 0, 0x02000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -5141, -1047, 1289, 0, 24, 0, 0x01000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -5864, -1047, 1926, 0, 24, 0, 0x02000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -6477, -1047, 2950, 0, 39, 0, 0x03000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, -6729, -1047, 3899, 0, 39, 0, 0x04000000, bhvWoodPlatform),
		OBJECT(MODEL_NONE, 9111, 445, -1183, 0, 0, 0, 0x01000000, bhvCutsceneHandler),
		OBJECT(MODEL_NONE, 9064, -490, 28, 0, 0, 0, 0x03000000, bhvLamp),
		OBJECT(MODEL_NONE, 6585, 141, 970, 0, 0, 0, 0x03000000, bhvLamp),
		OBJECT(MODEL_NONE, 6585, 141, -1036, 0, 0, 0, 0x03000000, bhvLamp),
		OBJECT(MODEL_NONE, 2683, 141, 970, 0, 0, 0, 0x03000000, bhvLamp),
		OBJECT(MODEL_NONE, 2558, 141, -1036, 0, 0, 0, 0x03000000, bhvLamp),
		OBJECT(MODEL_NONE, 9076, -563, -1060, 0, 0, 0, 0x01000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 10682, -1036, -1060, 0, 0, 0, 0x000A0000, bhvInstantActiveWarp),
		OBJECT(MODEL_WOOD_PLATFORM, 2658, -1047, -13, 0, 0, 0, 0x06000000, bhvWoodPlatform),
		OBJECT(MODEL_WOOD_PLATFORM, 9076, -1047, -13, 0, 0, 0, 0x06000000, bhvWoodPlatform),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_RESURRECTION),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 11124, 593, 321, 0, 0, 0, 0x01000000, bhvLamp),
		OBJECT(MODEL_NONE, 11162, 464, 472, 0, 0, 0, 0xFFFF0000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 11202, 0, 499, 0, 0, 0, 0x01000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_GREEN_SPRING, 11202, 0, 301, 0, 0, 0, 0x01000000, bhvGreenSpring),
		OBJECT(MODEL_NONE, 12499, 0, 9, 0, 0, 0, 0x000A0000, bhvInstantActiveWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_RESURRECTION_RAIN),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 14, 200, -4595),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
