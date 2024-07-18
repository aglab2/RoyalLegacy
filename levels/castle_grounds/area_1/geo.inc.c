#include "src/game/envfx_snow.h"

const GeoLayout castle_grounds_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0, castle_grounds_dl_HubWorld_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, castle_grounds_dl_HubWorld_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 1000, -32000, 32000, -2500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 1000, -32000, 32000, -2500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_002_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(1000, 32000, -32000, 32000, -32000, -2500, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_003_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 1000, -32000, 32000, -32000, -2500, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_004_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(1000, 32000, -32000, 32000, -2500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_005_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(1000, 32000, -32000, 32000, -32000, -2500, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_006_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 32000, -32000, -1900, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_007_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 32000, -2800, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_008_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 1000, -32000, 32000, -2500, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_grounds_dl_HubWorld_009_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 2325, 3743, -5052, 90, 0, 0, castle_grounds_dl_HubWorld_010_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 1126, 276, 156, 90, 0, 0, castle_grounds_dl_HubWorld_011_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2325, 3743, -5052, 90, 0, 0, castle_grounds_dl_HubWorld_015_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_grounds_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_grounds_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
