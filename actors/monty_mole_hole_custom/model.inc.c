Vtx monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_vtx_cull[8] = {
	{{{-55, 1, -55},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 1, 54},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 1, 54},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-55, 1, -55},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 1, -55},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 1, 54},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 1, 54},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{55, 1, -55},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_vtx_0[17] = {
	{{{0, 1, 0},0, {496, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{45, 1, -31},0, {917, 205},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{26, 1, -49},0, {734, 43},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 1, 0},0, {496, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{55, 1, -7},0, {1004, 434},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{45, 1, -31},0, {917, 205},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{52, 1, 20},0, {975, 678},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{37, 1, 41},0, {836, 879},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{13, 1, 54},0, {619, 993},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-13, 1, 54},0, {373, 993},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-37, 1, 41},0, {156, 879},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-52, 1, 20},0, {17, 678},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-55, 1, -7},0, {-12, 434},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-45, 1, -31},0, {75, 205},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-26, 1, -49},0, {258, 43},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 1, -55},0, {496, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{26, 1, -49},0, {734, 43},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_tri_0[] = {
	gsSPVertex(monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_vtx_0 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 6, 4, 0, 3, 7, 6, 0),
	gsSP2Triangles(3, 8, 7, 0, 3, 9, 8, 0),
	gsSP2Triangles(3, 10, 9, 0, 3, 11, 10, 0),
	gsSP2Triangles(3, 12, 11, 0, 3, 13, 12, 0),
	gsSP2Triangles(3, 14, 13, 0, 3, 15, 14, 0),
	gsSP1Triangle(3, 16, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_monty_mole_hole_custom_black_hole[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 0, 0, 255),
	gsSPEndDisplayList(),
};

Gfx monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_monty_mole_hole_custom_black_hole),
	gsSPDisplayList(monty_mole_hole_custom_Monty_mole_hole_custom_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx monty_mole_hole_custom_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

