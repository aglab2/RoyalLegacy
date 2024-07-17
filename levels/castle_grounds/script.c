#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common0.h"
#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, castle_inside, inside), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_16), 
	JUMP_LINK(script_func_vo_castle_inside), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SL_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_L, beta_door_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_R, beta_door_r_geo), 
    LOAD_MODEL_FROM_GEO(MODEL_GEM_BLUE,            gem_blue_geo),
    LOAD_MODEL_FROM_GEO(MODEL_GEM_GREEN,            gem_green_geo),
    LOAD_MODEL_FROM_GEO(MODEL_GEM_PURPLE,            gem_purple_geo),
    LOAD_MODEL_FROM_GEO(MODEL_GEM_RED,            gem_red_geo),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 37, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 35, WARP_NO_CHECKPOINT),
		WARP_NODE(44, LEVEL_BBH, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(38, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(18, LEVEL_BITS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(37, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(32, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(31, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_CCM, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(17, LEVEL_JRB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_DOOR_L, 806, -711, -4238, 0, 0, 0, 0x0, bhvEpicDoor),
		OBJECT(MODEL_CASTLE_DOOR_R, 1262, -711, -4238, 0, 0, 0, (1 << 16), bhvEpicDoor),
		OBJECT(0, 2950, 0, -1638, 0, 48, 0, 0x60000, bhvAirborneDeathWarp),
		OBJECT(0, -1117, 0, -1385, 0, -55, 0, 0x40000, bhvAirborneDeathWarp),
		OBJECT(0, -1195, -711, -3770, 0, -90, 0, 0x80000, bhvAirborneDeathWarp),
		OBJECT(0, 3512, -711, -3788, 0, 90, 0, 0x200000, bhvAirborneDeathWarp),
		OBJECT(0, 2946, 0, -1642, 0, 49, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(0, -1116, 0, -1389, 0, -55, 0, 0x30000, bhvAirborneStarCollectWarp),
		OBJECT(0, -1198, -711, -3765, 0, -90, 0, 0x70000, bhvAirborneStarCollectWarp),
		OBJECT(0, 3511, -711, -3790, 0, 90, 0, 0x1f0000, bhvAirborneStarCollectWarp),
		OBJECT(85, 2328, 1923, -4637, 0, 0, 0, 0x0, bhvCapSwitch),
		OBJECT(0, 1049, 0, -506, 0, -180, 0, 0x250000, bhvDeathWarp),
		OBJECT(0, 1044, 767, -5127, 0, -180, 0, 0x260000, bhvDeathWarp),
		OBJECT(34, 245, 0, -1405, 0, 90, 0, 0x0, bhvDoor),
		OBJECT(34, 1849, -2, -1404, 0, -90, 0, 0x0, bhvDoor),
		OBJECT(34, 290, -711, -3790, 0, 90, 0, 0x0, bhvDoor),
		OBJECT(34, 1780, -711, -3788, 0, -90, 0, 0x0, bhvDoor),
		OBJECT(0, 1047, 210, -1048, 0, 0, 0, 0x2c1e00, bhvFadingWarp),
		MARIO_POS(0x01, 0, 1071, 128, -805),
		OBJECT(144, 1048, 201, 650, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 948, 201, 651, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 1148, 201, 653, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 846, 1136, -5436, 0, -1, 0, 0x0, bhvFlame),
		OBJECT(144, 1259, 1136, -5439, 0, -1, 0, 0x0, bhvFlame),
		OBJECT(124, 1046, 0, -1058, 0, 0, 0, 0x310000, bhvMessagePanel),
		OBJECT(0, 1052, 0, -500, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(208, 968, 767, -3194, 0, 0, 0, 0x1e000000, bhvStarDoor),
		OBJECT(208, 1126, 767, -3194, 0, -180, 0, 0x1e000000, bhvStarDoor),
		OBJECT(221, 1044, 685, 746, 0, -180, 0, 0x52000000, bhvToadMessage),
		OBJECT(221, 4033, -233, -3405, 0, -180, 0, 0x4c000000, bhvToadMessage),
		OBJECT(25, 3785, 0, -1604, 0, -119, 0, 0x0, bhvTree),
		OBJECT(25, 3122, 0, -836, 0, -142, 0, 0x0, bhvTree),
		OBJECT(0, -2032, 120, -604, 0, 136, 0, 0xe0000, bhvWarp),
		OBJECT(0, 3651, 60, -1053, 0, -39, 0, 0x100000, bhvWarp),
		OBJECT(0, -1834, -255, -3815, 0, 0, 0, 0x110000, bhvWarp),
		OBJECT(0, 3874, -645, -3791, 0, -90, 0, 0xd0000, bhvWarp),
		OBJECT(0, 1040, 875, -5648, 0, 0, 0, 0x120000, bhvWarp),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2b),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 1071, 128, -805),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
