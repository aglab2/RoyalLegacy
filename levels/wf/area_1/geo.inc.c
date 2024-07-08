#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_aWinterLevel_2020version_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_bWinterLevel_2020version_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_bWinterLevel_2020version_mesh_layer_4),
		GEO_CULL(-3100, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_bWinterLevel_2020version_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_cWinterLevel_2020version_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, 200, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_cWinterLevel_2020version_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, 200, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_cWinterLevel_2020version_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, -10000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_dWinterLevel_2020version_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -1100, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, wf_dl_gWinterLevel_2020version_002_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_gWinterLevel_2020version_006_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -32000, 200, 16),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_low_poly_1_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, 32000, -32000, 32000, -32000, 200, 16),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_low_poly_2_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -32000, 32000, 16),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_low_poly_3_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, 1100, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, wf_dl_snowman_face_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, -1600, -32000, 2200, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_WinterLevel_2020version_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wf_dl_WinterLevel_2020version_002_mesh_layer_5),
		GEO_CULL(5000, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_003_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-3100, 32000, -32000, 32000, -32000, 500, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-32000, -1600, -32000, 2200, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_005_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-2000, 32000, -32000, 32000, -32000, 500, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_006_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_007_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_008_mesh_layer_1),
		GEO_CULL(-2900, 32000, -32000, 32000, -32000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_009_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_010_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_011_mesh_layer_1),
		GEO_CULL(-10000, 32000, -32000, 32000, 1100, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_012_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-1550, 32000, -32000, 32000, -32000, 500, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_WinterLevel_2020version_013_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-10000, 32000, -32000, 450, -1000, 32000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_zWinterLevel_2020version_007_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, wf_dl_zzWinterLevel_2020version_013_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_FORCE, wf_dl_zzWinterLevel_2020version_014_mesh_layer_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 45000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wf_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_SNOW_BLIZZARD, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
