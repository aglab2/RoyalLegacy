void scroll_bob_dl_bwater_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_bwater_mesh_layer_1_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_water_texture_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 63;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_water_texture_mesh_layer_5_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_bob_dl_bwater_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(bob_dl_bwater_mesh_layer_1);

	shift_s_down(mat, 13, PACK_TILESIZE(0, 2));

};

void scroll_bob() {
	scroll_bob_dl_bwater_mesh_layer_1_vtx_0();
	scroll_bob_dl_water_texture_mesh_layer_5_vtx_0();
	scroll_gfx_bob_dl_bwater_mesh_layer_1();
};
