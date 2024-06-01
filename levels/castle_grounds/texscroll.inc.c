void scroll_castle_grounds_dl_HubWorld_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 70;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_HubWorld_001_mesh_layer_1_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_grounds_dl_HubWorld_002_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 26;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_HubWorld_002_mesh_layer_1_vtx_6);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_castle_grounds_dl_HubWorld_001_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(castle_grounds_dl_HubWorld_001_mesh_layer_1);

	shift_s_down(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_castle_grounds() {
	scroll_castle_grounds_dl_HubWorld_001_mesh_layer_1_vtx_0();
	scroll_castle_grounds_dl_HubWorld_002_mesh_layer_1_vtx_6();
	scroll_gfx_castle_grounds_dl_HubWorld_001_mesh_layer_1();
};
