#include "src/game/envfx_snow.h"

const GeoLayout bob_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 7927, 3194, 7286),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -1166, -3400, -7286, bob_dl_EndMesh_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(5, bob_dl_EndMesh_mesh_layer_5),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(4, 1149, -4056, 213, bob_dl_Plane_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 9075, -861, 7498),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -2315, 656, -7498, bob_dl_Cube_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(5, bob_dl_Cube_001_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 7268, 4939, -143),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -507, -5144, 143, bob_dl_Start_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(5, bob_dl_Start_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, -75843, 500, 0, -75843, 400, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(4, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
