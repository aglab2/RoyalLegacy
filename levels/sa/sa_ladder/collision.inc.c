const Collision sa_ladder_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(4100, 2066, 2456),
	COL_VERTEX(3825, 2066, 2668),
	COL_VERTEX(3956, 1094, 2989),
	COL_VERTEX(4231, 1094, 2778),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};