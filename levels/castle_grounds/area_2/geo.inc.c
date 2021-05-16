#include "src/game/envfx_snow.h"

const GeoLayout castle_grounds_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(5, -55, 408, -402, castle_grounds_dl_000AAALake_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(5, -55, 408, -402, castle_grounds_dl_AAARiver_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2134, 197, 2613, castle_grounds_dl_AWIPHouse_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2993, 525, 2742, castle_grounds_dl_AWipHouse_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3276, 197, -3198, castle_grounds_dl_AWipHouse_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 117, 178, -2169, castle_grounds_dl_Cube_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 2816, 201, -3375, castle_grounds_dl_Cube_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(4, -55, 408, -402, castle_grounds_dl_FenceVisual_mesh_layer_4),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 129, 364, -1867),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -6, -263, 1),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-2048, 4000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(1, castle_grounds_dl_Fireplace_002_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -6, -309, 1),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(4000, 32700),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(1, castle_grounds_dl_FireplaceLOD_001_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 2772, 275, -3381),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-2048, 6000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(1, castle_grounds_dl_LittleBricks_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(1, -55, 408, -402, castle_grounds_dl_Plane_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -2874, 180, 313, castle_grounds_dl_Tent_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -1981, 180, -2195, castle_grounds_dl_Tent_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 1925, 180, 221, castle_grounds_dl_Tent_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, 3065, 508, 1452, castle_grounds_dl_Tent_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -55, 408, -402, castle_grounds_dl_ZOOb_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -55, 408, -402, castle_grounds_dl_ZOOb_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(1, -656, 1201, -18855, castle_grounds_dl_ZZZBuildings_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_PURPLE_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 71083, 0, -100, 71083, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_grounds_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(4, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, castle_grounds_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, castle_grounds_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
