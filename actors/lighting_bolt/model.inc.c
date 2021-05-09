Vtx lighting_bolt_Plane_mesh_layer_1_vtx_cull[8] = {
	{{{-676, -1185, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-676, -1185, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-676, 1012, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-676, 1012, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{641, -1185, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{641, -1185, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{641, 1012, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{641, 1012, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx lighting_bolt_Plane_mesh_layer_1_vtx_0[11] = {
	{{{-676, 1012, 0},0, {-16, 59},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-340, 1012, 0},0, {-16, 293},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-93, 351, 0},0, {213, 465},{0x0, 0x0, 0x81, 0xFF}}},
	{{{206, 135, 0},0, {288, 672},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-27, 213, 0},0, {261, 511},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-380, 437, 0},0, {184, 265},{0x0, 0x0, 0x81, 0xFF}}},
	{{{166, -429, 0},0, {484, 644},{0x0, 0x0, 0x81, 0xFF}}},
	{{{431, -631, 0},0, {554, 829},{0x0, 0x0, 0x81, 0xFF}}},
	{{{242, -561, 0},0, {530, 697},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-170, -356, 0},0, {459, 411},{0x0, 0x0, 0x81, 0xFF}}},
	{{{641, -1185, 0},0, {746, 974},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx lighting_bolt_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(lighting_bolt_Plane_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 2, 4, 0),
	gsSP2Triangles(6, 5, 4, 0, 4, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 8, 9, 6, 0),
	gsSP1Triangle(8, 10, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lighting_bolt_lighting[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 226, 104, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lighting_bolt_lighting[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx lighting_bolt_Plane_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(lighting_bolt_Plane_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_lighting_bolt_lighting),
	gsSPDisplayList(lighting_bolt_Plane_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_lighting_bolt_lighting),
	gsSPEndDisplayList(),
};

Gfx lighting_bolt_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

