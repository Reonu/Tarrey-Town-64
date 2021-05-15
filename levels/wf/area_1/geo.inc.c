#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_ARoom1_geo),
			GEO_BRANCH(1, wf_dl_BRoom_2_geo),
			GEO_BRANCH(1, wf_dl_CRoom3_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -9598, -4115, -3253),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 11324, 6755, 5669, wf_dl_Room_3_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_ARoom1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11591, -2744, -3419),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 501, -1730, 8316, wf_dl_Cube_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, -196, -3723, 52, wf_dl_Cube_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(5, wf_dl_Cube_001_mesh_layer_5),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, 4073, 2962, 16633, wf_dl_FakeRoom2_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_BRoom_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -1650, 2453, 12801),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -1793, -4595, 264, wf_dl_Cube_002_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 761, -4912, 803, wf_dl_Cube_003_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, -71, -5092, -998, wf_dl_Cube_004_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, -2032, -1737, wf_dl_Cube_005_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 1826, -4967, -1641, wf_dl_Cube_006_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 2253, -4245, 1656, wf_dl_Cube_007_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 4694, 117, -3263, wf_dl_Cube_008_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, -1490, -671, wf_dl_Cube_009_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, -647, -1762, wf_dl_Cube_010_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, -125, -536, wf_dl_Cube_011_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, 195, 832, wf_dl_Cube_012_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, 533, 1978, wf_dl_Cube_013_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 5555, 1129, 831, wf_dl_Cube_014_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 12250, 2767, -392, wf_dl_Cube_015_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 9913, 2767, 1244, wf_dl_Cube_016_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 9192, 2767, -1460, wf_dl_Cube_017_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 13765, 2767, 1581, wf_dl_Cube_018_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 16857, 2676, -232, wf_dl_Cube_019_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 16857, 3112, 554, wf_dl_Cube_020_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 16857, 3644, -244, wf_dl_Cube_021_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 16857, 4048, 576, wf_dl_Cube_022_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, 8352, 4986, -11771, wf_dl_Fake_room_3_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(1, -7863, -2195, -1384, wf_dl_FakeRoom1_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_CRoom3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 7311, 9436, 1187),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -573, -2255, 1997, wf_dl_Fake_room_2_mesh_layer_1),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 950, -2339, -5928),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-5000, 10000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(5, wf_dl_LavaSemitransparent_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(1, -1658, -1587, -6644, wf_dl_Room_3_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wf_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(1, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
