void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 121;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_10);

	deltaY = (int)(0.10000002384185791 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_12() {
	int i = 0;
	int count = 58;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_12);

	deltaY = (int)(0.12999999523162842 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_14() {
	int i = 0;
	int count = 78;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_14);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_27() {
	int i = 0;
	int count = 236;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_27);

	deltaX = (int)(0.3700000047683716 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_28() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_28);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_31() {
	int i = 0;
	int count = 110;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_31);

	deltaX = (int)(0.3400000333786011 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_37() {
	int i = 0;
	int count = 130;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_mesh_layer_1_vtx_37);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Bowser_Level_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1584;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Bowser_Level_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000002384185791 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits() {
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_10();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_12();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_14();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_27();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_28();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_31();
	scroll_bits_dl_Bowser_Level_mesh_layer_1_vtx_37();
	scroll_bits_dl_Bowser_Level_001_mesh_layer_1_vtx_0();
};
