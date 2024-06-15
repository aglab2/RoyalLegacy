void scroll_ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_1_vtx_19() {
	int i = 0;
	int count = 330;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_1_vtx_19);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 7;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_5_vtx_1);

	deltaX = (int)(0.2200000286102295 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_Desert_Ruins_2020_Area_2__1__mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 497;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Desert_Ruins_2020_Area_2__1__mesh_layer_1_vtx_5);

	deltaX = (int)(0.2200000286102295 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm() {
	scroll_ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_1_vtx_19();
	scroll_ccm_dl_Desert_Ruins_Definitive_Edition_mesh_layer_5_vtx_1();
	scroll_ccm_dl_Desert_Ruins_2020_Area_2__1__mesh_layer_1_vtx_5();
};
