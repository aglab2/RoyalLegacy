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
#include "levels/sa/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sa_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bob, generic), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bob), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(241, LEVEL_PSS, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, -2272, 28, 9477, -180, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(212, -397, 2742, 1297, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(212, 2909, 5112, 9335, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(0, 1232, 2770, -9271, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 1403, 2770, -9858, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 1152, 2822, -10382, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 1691, 2854, -10730, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 1068, 2873, -11681, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 6605, 4788, 7782, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 6935, 5028, 7958, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 6607, 5274, 8158, 0, 0, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(188, -1823, 88, 8278, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(129, -1456, 0, 6049, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(0, -2914, 78, 7675, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(137, 1384, 3296, -13037, 0, 0, 0, 0x30000, bhvExclamationBox),
		OBJECT(137, 7599, 3125, -3444, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(180, 1341, 2839, -4842, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(144, 7045, 4911, 10573, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 7062, 4911, 11042, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 3684, 3707, 11043, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(144, 3671, 3707, 10569, 0, 0, 0, 0x0, bhvFlame),
		OBJECT(0, 809, 3178, -6220, 0, 90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 1900, 3112, -8126, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 3331, 2758, -3850, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 6164, 2758, -2924, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(207, -1620, 88, 7266, 0, 0, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(207, -3081, 0, 6056, 0, 0, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(207, -3216, -72, 8556, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, -2910, 78, 7697, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -2554, 1094, 644, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1059, 1094, 328, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1378, 2983, -13041, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 3464, 3109, 8570, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 3544, 3109, 9990, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 5762, 3024, 9926, 0, 0, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, 7362, 3024, 9008, 0, 0, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, -2286, 0, 6216, 0, 0, 0, 0x0, bhvOpenableGrill),
		OBJECT(120, -1453, 60, 6044, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(101, 1243, 2839, -4620, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1359, 2983, -8161, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1345, 2839, -5067, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(100, 1398, 3475, -7193, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1203, 3455, -10940, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1431, 3503, -12055, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1162, 2993, -1988, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1330, 2741, -553, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1531, 2741, 1386, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1327, 2807, 4427, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(0, -2310, 912, 6300, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0),
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
