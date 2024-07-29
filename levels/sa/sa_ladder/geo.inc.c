#include "src/game/envfx_snow.h"

const GeoLayout sa_ladder_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULL(1800, 32000, -32000, 32000, -1500, 6200, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, sa_ladder_zone2_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
