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

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bits, sky), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bits), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 38, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_BITS, 1, 15, WARP_NO_CHECKPOINT),
		WARP_NODE(15, LEVEL_BITS, 1, 16, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BITS, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BITS, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(69, LEVEL_BOWSER_3, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(39, LEVEL_BITS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 3072, 2454, -11477, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(212, 11477, 5267, -24667, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(65, 14842, 6138, -2474, 0, -90, 0, 0x0, bhvAnimatesOnFloorSwitchPress),
		OBJECT(0, 14837, 4098, -18706, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 14841, 7694, -400, 0, 0, 0, 0x270000, bhvDeathWarp),
		OBJECT(0, 12100, 6492, -14127, 0, 0, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 14833, 6138, -18073, 0, 0, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 17595, 6492, -14126, 0, 0, 0, 0xf0000, bhvFadingWarp),
		OBJECT(0, 14833, 6138, -18073, 0, 0, 0, 0x100000, bhvFadingWarp),
		OBJECT(180, 9728, 2519, -22828, 0, -37, 0, 0x0, bhvFireSpitter),
		OBJECT(0, 7556, 2274, -22443, 0, 89, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 9610, 2274, -22898, 0, -129, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 9923, 2334, -24973, 0, -4, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 12825, 3300, -23068, 0, 178, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 14407, 3504, -24292, 0, -38, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 13917, 3408, -22358, 0, 88, 0, 0x0, bhvFlamethrower),
		OBJECT(207, 14839, 6138, -4088, 0, -180, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(0, 78, 365, -6282, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(124, 17588, 6258, -14129, 0, 0, 0, 0x3e0000, bhvMessagePanel),
		OBJECT(124, 12097, 6258, -14132, 0, 0, 0, 0x3e0000, bhvMessagePanel),
		OBJECT(124, 11478, 5135, -24890, 0, 0, 0, 0x400000, bhvMessagePanel),
		OBJECT(85, 6311, 2763, -11989, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(85, 6507, 3267, -11294, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(85, 7105, 3771, -10506, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(206, -97, 419, -4782, 0, 15, 0, 0x0, bhvSnufit),
		OBJECT(206, 308, 750, -7544, 0, -22, 0, 0x0, bhvSnufit),
		OBJECT(0, 142, 0, -200, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, 14836, 7670, 1800, 0, 0, 0, 0x450000, bhvWarpPipe),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 36),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
