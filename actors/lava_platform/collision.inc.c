const Collision lava_platform_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-497, 39, 313),
	COL_VERTEX(-497, 19, 313),
	COL_VERTEX(497, 19, 313),
	COL_VERTEX(497, 39, 313),
	COL_VERTEX(497, 39, -313),
	COL_VERTEX(497, 19, -313),
	COL_VERTEX(-497, 19, -313),
	COL_VERTEX(-497, 39, -313),
	COL_VERTEX(497, 94, 0),
	COL_VERTEX(497, 19, 0),
	COL_VERTEX(-497, 19, 0),
	COL_VERTEX(-497, 94, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(8, 9, 5),
	COL_TRI(8, 5, 4),
	COL_TRI(9, 2, 1),
	COL_TRI(9, 1, 10),
	COL_TRI(11, 10, 1),
	COL_TRI(11, 1, 0),
	COL_TRI(11, 8, 4),
	COL_TRI(11, 4, 7),
	COL_TRI(0, 3, 8),
	COL_TRI(0, 8, 11),
	COL_TRI(7, 6, 10),
	COL_TRI(7, 10, 11),
	COL_TRI(5, 9, 10),
	COL_TRI(5, 10, 6),
	COL_TRI(3, 2, 9),
	COL_TRI(3, 9, 8),
	COL_TRI_STOP(),
	COL_END()
};
