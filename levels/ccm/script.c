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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bob, generic), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bob), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 32, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 31, WARP_NO_CHECKPOINT),
		WARP_NODE(25, LEVEL_CCM, 1, 26, WARP_NO_CHECKPOINT),
		WARP_NODE(26, LEVEL_CCM, 1, 25, WARP_NO_CHECKPOINT),
		WARP_NODE(24, LEVEL_CCM, 1, 23, WARP_NO_CHECKPOINT),
		WARP_NODE(23, LEVEL_CCM, 1, 24, WARP_NO_CHECKPOINT),
		WARP_NODE(19, LEVEL_CCM, 2, 18, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_CCM, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CCM, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_CCM, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CCM, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1045, 3317, -6355, 0, 0, 0, 0x00000000, bhvCS),
		OBJECT(212, -153, 762, 3144, 0, -85, 0, 0x0, bhv1Up),
		OBJECT(140, -13322, 2397, 2389, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(188, 6480, 1154, 4530, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, 5150, 1154, 4543, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(MODEL_1UP, 5811, -201, 3200, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 5763, 3595, 382, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(223, -11611, 3036, 3187, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -11582, 3036, -851, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 2981, 2562, 383, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 5018, 2562, 3108, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 6422, 2562, 3116, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 8445, 2562, 710, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -1035, 1272, -1706, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 10424, 890, -2304, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 10355, 878, 3232, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -3291, 937, 1061, 0, -85, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 9817, 937, 399, 0, 89, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 5751, 1357, -2693, 0, 179, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 5855, 1154, 4460, 0, 89, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3091, 2562, 3110, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 8526, 2562, 3120, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 3100, 2562, 352, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 8539, 2562, 397, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -9553, -29, 5472, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 5151, 230, -12167, 0, 0, 0, 0x40000, bhvFadingWarp),
		OBJECT(0, 5775, 1728, -3701, 0, 0, 0, 0x30000, bhvFadingWarp),
		OBJECT(0, -13573, 5340, -52, 0, 0, 0, 0x190000, bhvFadingWarp),
		OBJECT(0, -13573, 417, -52, 0, 0, 0, 0x1a0000, bhvFadingWarp),
		OBJECT(180, 3086, 2807, 3116, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 8528, 2807, 3116, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(207, -13529, 437, 2090, 0, 90, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(207, 8528, 2562, -2399, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(220, 5786, 512, -8069, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(220, 11568, 900, 625, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(192, 5785, 512, -5373, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, 5591, 512, -6794, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(0, 9898, 67, 1622, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 3177, 67, 624, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1851, 612, 941, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -12400, 36, -1464, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, -13302, 2386, -309, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -13318, 2389, 228, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -13309, 2392, 762, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -13309, 2395, 1292, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -13837, 2419, -316, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, 6626, 2761, -497, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 7480, 2562, -1353, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5963, 2962, 377, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5563, 2962, 377, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5763, 2962, 577, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5763, 2962, 177, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5963, 2962, 577, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5963, 2962, 177, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5563, 2962, 577, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5563, 2962, 177, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, 5743, 1920, -15608, 0, 0, 0, 0x2000000, bhvHiddenStar),
		OBJECT(0, 6614, 240, -13659, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, 6446, 412, -14461, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, 5184, 600, -14450, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, 4996, 1200, -13670, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, 5787, 1560, -14028, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(124, 5153, 39, -12507, 0, 32, 0, 0x350000, bhvMessagePanel),
		OBJECT(124, -8438, 3036, 3197, 0, 171, 0, 0x240000, bhvMessagePanel),
		OBJECT(124, 6686, 4554, 10473, 0, 98, 0, 0x4e0000, bhvMessagePanel),
		OBJECT(124, -13913, 244, 1055, 0, 90, 0, 0x360000, bhvMessagePanel),
		OBJECT(124, 13011, 285, 2527, 0, -180, 0, 0x3d0000, bhvMessagePanel),
		OBJECT(116, 6628, 240, -13655, 0, 68, 0, 0x0, bhvOneCoin),
		OBJECT(116, 6444, 412, -14451, 0, 68, 0, 0x0, bhvOneCoin),
		OBJECT(116, 5177, 600, -14449, 0, 68, 0, 0x0, bhvOneCoin),
		OBJECT(116, 4999, 1200, -13653, 0, 68, 0, 0x0, bhvOneCoin),
		OBJECT(116, 5799, 1479, -14008, 0, 68, 0, 0x0, bhvOneCoin),
		OBJECT(116, 260, 756, 2891, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 146, 900, 3035, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 25, 1044, 3192, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -107, 1188, 3359, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(0, -11523, 36, 2448, 0, 90, 0, 0x0, bhvOpenableGrill),
		OBJECT(0, 3840, 0, 2094, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 4147, 515, -1163, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 7502, 0, 2151, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 7630, 392, -1528, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -7242, -36, 4239, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -9464, 36, -2200, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -12739, 36, 1517, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 6334, 39, -12164, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(120, 12905, 672, -1156, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(0, 5823, 0, 3192, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -8451, 3498, -858, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 13444, 4230, 791, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, 5765, 905, 389, 0, 0, 0, 0x0, bhvStar),
		OBJECT(27, -10809, -29, 5580, 0, 160, 0, 0x0, bhvTree),
		OBJECT(27, -8299, -29, 5451, 0, -147, 0, 0x0, bhvTree),
		OBJECT(0, 5818, -62, 3192, 0, 0, 0, 0x1210000, bhvWarp),
		OBJECT(22, 5849, 3947, 5165, 0, -180, 0, 0x130000, bhvWarpPipe),
		OBJECT(22, -10409, 1163, -4265, 0, 0, 0, 0x170000, bhvWarpPipe),
		OBJECT(22, -13571, 4742, 2104, 0, 0, 0, 0x180000, bhvWarpPipe),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2E),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 32, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 31, WARP_NO_CHECKPOINT),
		WARP_NODE(18, LEVEL_CCM, 1, 19, WARP_CHECKPOINT),
		WARP_NODE(10, LEVEL_CCM, 2, 0, WARP_NO_CHECKPOINT),
		OBJECT(188, 1184, -1816, 614, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, -347, -1816, 2295, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(129, -2166, -6151, 2369, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -1844, -6151, 2810, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(223, 3650, -1772, 5531, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 1172, -1772, 5497, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -1314, -1772, 5488, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(194, -3665, -1816, 3400, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(194, -2424, -1816, 5544, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(0, -3729, -5933, 2112, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -101, -4210, 2950, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1189, -5933, 5199, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 956, -6151, -11519, 0, 0, 0, 0x4000000, bhvEyerokBoss),
		OBJECT(180, 2540, -1772, 5570, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -32, -1772, 5574, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 484, -6151, -11291, 0, 88, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1440, -6151, -11282, 0, 88, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 476, -6151, -10320, 0, 88, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1436, -6151, -10308, 0, 88, 0, 0x0, bhvFireSpitter),
		OBJECT(0, -1523, -6024, 936, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1280, -1628, 5605, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar),
		OBJECT(194, 272, -6151, -10804, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, 1616, -6151, -10801, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(124, 2150, -1370, 2910, 0, -120, 0, 0x80000, bhvMessagePanel),
		OBJECT(124, 667, -5189, 818, 0, -66, 0, 0x470000, bhvMessagePanel),
		OBJECT(124, -3835, -1772, 2453, 0, 90, 0, 0xf0000, bhvMessagePanel),
		OBJECT(0, -3284, -1772, 2291, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(116, -227, -6151, -10797, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 2144, -6151, -10792, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(215, -3165, -1906, 4681, 0, 90, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1018, -1139, 2262, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3831, -1892, 1843, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2114, -1523, 2276, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4278, -1201, 5692, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1160, -2633, -1161, 0, -165, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3856, -1129, 5745, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1269, -1877, 5088, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -3380, -3600, 3405, 0, 0, 0, 0x0, bhvSandSoundLoop),
		OBJECT(0, -2402, -3600, 5210, 0, 0, 0, 0x0, bhvSandSoundLoop),
		OBJECT(0, 1589, -1816, 2567, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, 1581, -1370, 2572, 0, 0, 0, 0x120000, bhvWarpPipe),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 41),
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
