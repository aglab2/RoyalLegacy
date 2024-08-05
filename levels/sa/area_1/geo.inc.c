#include "src/game/envfx_snow.h"

const GeoLayout sa_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_envfx_main),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4230, 0, -4600, 0, -180, 0),
		GEO_ASM(20480, geo_movtex_draw_water_regions),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4230, 0, -4600, 0, -180, 0),
		GEO_ASM(20481, geo_movtex_draw_water_regions),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4230, 0, -4600, 0, -180, 0),
		GEO_ASM(20482, geo_movtex_draw_water_regions),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4230, 0, -4600, 0, -180, 0),
		GEO_ASM(0, geo_cannon_circle_base),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4230, 0, -4600, 0, -180, 0),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(2500, 32000, -32000, 32000, -32000, 0, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone1_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_ALPHA, sa_dl_zone1_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(2500, 32000, -32000, 32000, -32000, 0, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone1flowers_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(2500, 32000, -32000, 32000, -32000, 0, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_zone1water_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(1800, 32000, -32000, 32000, -1500, 6200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone2_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_zone2_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_CULL(1800, 32000, -32000, 32000, -1500, 6200, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_zone2_bulb_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(1800, 32000, -32000, 32000, -1500, 6200, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone2bullseye_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-6000, 32000, -32000, 3800, -5500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone3_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-6000, 2200, -32000, 3800, -5500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone3_extra_cull_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-6000, 32000, -32000, 3800, 4500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone3_extra_cull_2_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 700, -32000, 32000, -10000, 4000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_zone4_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_zone4_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 700, -32000, 32000, -10000, 4000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_zone4water_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1944, 0, 2996, 0, -180, 0, sa_dl_zonepaths_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sa_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x190B),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, sa_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
