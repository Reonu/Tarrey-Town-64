#include "src/game/envfx_snow.h"

const GeoLayout floating_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, floating_box_FloatingBox_mesh_layer_1),
		GEO_DISPLAY_LIST(1, floating_box_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
