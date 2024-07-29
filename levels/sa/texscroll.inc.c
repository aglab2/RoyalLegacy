void scroll_sa_dl_zone1water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 59;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sa_dl_zone1water_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sa_dl_zone3_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 79;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sa_dl_zone3_mesh_layer_1_vtx_10);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sa_dl_zone3_extra_cull_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 192;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sa_dl_zone3_extra_cull_mesh_layer_1_vtx_6);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sa_dl_zone3_extra_cull_2_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 87;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sa_dl_zone3_extra_cull_2_mesh_layer_1_vtx_2);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sa_dl_zone4water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 21;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(sa_dl_zone4water_mesh_layer_5_vtx_0);

	deltaX = (int)(0.30000001192092896 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sa_dl_skybox4sh_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 178;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(sa_dl_skybox4sh_mesh_layer_0_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sa() {
	scroll_sa_dl_zone1water_mesh_layer_5_vtx_0();
	scroll_sa_dl_zone3_mesh_layer_1_vtx_10();
	scroll_sa_dl_zone3_extra_cull_mesh_layer_1_vtx_6();
	scroll_sa_dl_zone3_extra_cull_2_mesh_layer_1_vtx_2();
	scroll_sa_dl_zone4water_mesh_layer_5_vtx_0();
	scroll_sa_dl_skybox4sh_mesh_layer_0_vtx_0();
};
