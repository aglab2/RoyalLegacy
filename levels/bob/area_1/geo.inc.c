#include "src/game/envfx_snow.h"

const GeoLayout bob_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 2278, 3503, -3871),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, 2000, 32000, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aatrees_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 32000, 2000, 32000, -32000, 800, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_aflowers_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_btops_mesh_layer_1),
		GEO_CULL(-32000, 32000, -32000, 32000, -32000, 1000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_btops_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_bwater_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -654, 1828, 1671, bob_dl_etree_pink_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -654, 1828, 1671),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 4364, 300, 32000, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_etrees_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 1463, 0, bob_dl_fgrass_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 4421, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 2000, -4400, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_gmush_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 4421, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(0, 32000, -32000, 32000, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_gmush_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1969, 1911, -6540, bob_dl_groof_mesh_layer_1),
		GEO_CULL(-32000, 4364, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_gwood_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 4364, -32000, 1600, -32000, 200, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_gwood_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 938, 0, -3531, bob_dl_h_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_h_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-800, 32000, -32000, 1700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_h_001_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1700, -32000, -1200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_002_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(0, 32000, -32000, 32000, -32000, -1200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_003_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 32000, -32000, 200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_h_004_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_005_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_006_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 938, 0, -3531),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1700, 600, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_h_006_because_texture_poking_through_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 32000, -32000, 1600, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_lflowers_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 32000, -32000, 1700, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_lflowers2_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -2598, 523, -6813),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 0, -32000, 32000, -32000, -3200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_lplat_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bob_dl_lsign_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_lsign2_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 706, 0, -2953),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1600, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_ltrees_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_minside_mesh_layer_1),
		GEO_CULL(576, 3132, -100, 2000, -7800, -4917, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_minside2_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 32000, -32000, 1000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bob_dl_nweed_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_nzbg_mesh_layer_1),
		GEO_CULL(-32000, 32000, -32000, 1700, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_nzbg_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 0, 0, -3223, bob_dl_water_texture_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x294F),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
