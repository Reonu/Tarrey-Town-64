#include "src/game/envfx_snow.h"

const GeoLayout toad_builder_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 8, 0, 36, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 18, 0, 0, -36, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toad_builder_Torso_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 30, 0, toad_builder_Head_mesh_layer_1),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 10, 15, 0, 176, 1, -73),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toad_builder_Left_arm_mesh_layer_1),
						GEO_CLOSE_NODE(),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 12, -12, -2, 95, 0, 0),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toad_builder_Left_foot_mesh_layer_1),
						GEO_CLOSE_NODE(),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -10, 15, 0, 176, -1, 73),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toad_builder_Right_arm_mesh_layer_1),
						GEO_CLOSE_NODE(),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -12, -12, -2, 95, 0, 0),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toad_builder_Right_foot_mesh_layer_1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, toad_builder_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
