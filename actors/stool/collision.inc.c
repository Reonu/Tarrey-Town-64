const Collision stool_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(32),
	COL_VERTEX(-235, -100, 0),
	COL_VERTEX(-166, -100, -166),
	COL_VERTEX(-166, -112, -166),
	COL_VERTEX(-235, -112, 0),
	COL_VERTEX(166, -100, -166),
	COL_VERTEX(235, -100, 0),
	COL_VERTEX(235, -112, 0),
	COL_VERTEX(166, -112, -166),
	COL_VERTEX(235, 112, 0),
	COL_VERTEX(166, 112, -166),
	COL_VERTEX(0, 112, -235),
	COL_VERTEX(-166, 112, -166),
	COL_VERTEX(-235, 112, 0),
	COL_VERTEX(-166, 112, 166),
	COL_VERTEX(0, 112, 235),
	COL_VERTEX(166, 112, 166),
	COL_VERTEX(0, -112, -235),
	COL_VERTEX(166, -112, 166),
	COL_VERTEX(0, -112, 235),
	COL_VERTEX(-166, -112, 166),
	COL_VERTEX(235, 100, 0),
	COL_VERTEX(166, 100, -166),
	COL_VERTEX(-166, 100, -166),
	COL_VERTEX(-235, 100, 0),
	COL_VERTEX(0, -100, 235),
	COL_VERTEX(-166, -100, 166),
	COL_VERTEX(-166, 100, 166),
	COL_VERTEX(0, 100, 235),
	COL_VERTEX(166, -100, 166),
	COL_VERTEX(0, -100, -235),
	COL_VERTEX(166, 100, 166),
	COL_VERTEX(0, 100, -235),
	COL_TRI_INIT(SURFACE_NO_CAM_COLLISION, 60),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(8, 9, 10),
	COL_TRI(10, 11, 12),
	COL_TRI(12, 13, 14),
	COL_TRI(14, 15, 8),
	COL_TRI(8, 10, 12),
	COL_TRI(12, 14, 8),
	COL_TRI(2, 16, 7),
	COL_TRI(7, 6, 17),
	COL_TRI(17, 18, 19),
	COL_TRI(19, 3, 2),
	COL_TRI(2, 7, 17),
	COL_TRI(17, 19, 2),
	COL_TRI(20, 21, 9),
	COL_TRI(20, 9, 8),
	COL_TRI(22, 23, 12),
	COL_TRI(22, 12, 11),
	COL_TRI(24, 25, 19),
	COL_TRI(24, 19, 18),
	COL_TRI(26, 27, 14),
	COL_TRI(26, 14, 13),
	COL_TRI(5, 28, 17),
	COL_TRI(5, 17, 6),
	COL_TRI(1, 29, 16),
	COL_TRI(1, 16, 2),
	COL_TRI(29, 4, 7),
	COL_TRI(29, 7, 16),
	COL_TRI(30, 20, 8),
	COL_TRI(30, 8, 15),
	COL_TRI(31, 22, 11),
	COL_TRI(31, 11, 10),
	COL_TRI(21, 31, 10),
	COL_TRI(21, 10, 9),
	COL_TRI(25, 0, 3),
	COL_TRI(25, 3, 19),
	COL_TRI(23, 26, 13),
	COL_TRI(23, 13, 12),
	COL_TRI(28, 24, 18),
	COL_TRI(28, 18, 17),
	COL_TRI(27, 30, 15),
	COL_TRI(27, 15, 14),
	COL_TRI(28, 30, 27),
	COL_TRI(28, 27, 24),
	COL_TRI(24, 27, 26),
	COL_TRI(24, 26, 25),
	COL_TRI(25, 26, 23),
	COL_TRI(25, 23, 0),
	COL_TRI(0, 23, 22),
	COL_TRI(0, 22, 1),
	COL_TRI(1, 22, 31),
	COL_TRI(1, 31, 29),
	COL_TRI(29, 31, 21),
	COL_TRI(29, 21, 4),
	COL_TRI(4, 21, 20),
	COL_TRI(4, 20, 5),
	COL_TRI(5, 20, 30),
	COL_TRI(5, 30, 28),
	COL_TRI_STOP(),
	COL_END()
};
