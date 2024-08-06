#include "src/game/envfx_snow.h"

const GeoLayout gemmies_geo[] = {
	GEO_CULLING_RADIUS(100000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gemmies_gems_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
