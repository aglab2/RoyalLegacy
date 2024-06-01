void scroll_gfx_mat_jrb_dl_LavaPools__noflow__001_f3d() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_LavaPools__noflow__001_f3d);

	shift_t(mat, 14, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_jrb_dl_Flowing_Lava_001_f3d() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_Flowing_Lava_001_f3d);

	shift_t(mat, 14, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_jrb_dl_AlsoFlowingLava_001_f3d() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_AlsoFlowingLava_001_f3d);

	shift_t(mat, 14, PACK_TILESIZE(0, 1));

};

void scroll_jrb() {
	scroll_gfx_mat_jrb_dl_LavaPools__noflow__001_f3d();
	scroll_gfx_mat_jrb_dl_Flowing_Lava_001_f3d();
	scroll_gfx_mat_jrb_dl_AlsoFlowingLava_001_f3d();
};
