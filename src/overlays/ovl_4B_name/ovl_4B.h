#ifndef _OVL_4B_H
#define _OVL_4B_H

#include "common.h"
#include "game/board.h"

/* Overlay 4B: a small board scene in the shape of MP1's ovl_7F (MinigameStadiumStart): board index 6,
   one model on space 0x17, a second model, nine spectators on fixed spaces that turn to face the
   current player, and three space events (a turn-count message with 10 coins, and two that set or
   clear the player model's attr bit 0). */

#define PLAYER_MODEL_4B(i) ((MBModel*)BoardPlayerGet(i)->unk_24)

/* main */
void HuPrcChildWatch(void);
s32 PlaySound(s32);
s32 omOvlReturnEx(s16);
void omInitObjMan(s32, s32);
void omOvlGotoEx(s32 arg0, s16 arg1, u16 arg2);
void _SetFlag(s32);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2);
void func_80020070_20C70(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
s32 func_80041AEC_426EC(s8 arg0, void* arg1, s16 arg2, s16 arg3); /* space marker */
MBModel* func_80043510_44110(s32, void*);
void func_80043DAC_449AC(MBModel*);
MBModel* MBModelParamCreate(MBModel*);
void func_8004655C_4715C(s32);
s32 func_80046D2C_4792C(s32);
void func_8004CA34_4D634(s32, s32);
void MBPlayerMotionSet(s32 index, s16 animation, s32 unk);
GW_PLAYER* BoardPlayerGet(s32);
void func_80056168_56D68(void);
void func_80056368_56F68(s16, u32, s32, s32, s32, s32, s32); /* message with two string args */
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
void func_80056C30_57830(s16 playerNo, s32 arg1, s16 masuAbsIndex);
s32 func_80059FD0_5ABD0(s32); /* the player's rank */
void MBDlgWinExec(s32, s32);
void MBDlgWinClose(void);
Process* MBDCameraZoomMotStart(f32);
void func_800614B4_620B4(s32, s32);
void func_80062E10_63A10(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_80066C34_67834(u32 arg0);
void EventTableHydrate(BoardEventTableEntry* table);
SpaceData* GetSpaceData(s16);
void func_800B3170_B3D70(Vec*, Vec*);

/* data */
extern s16 D_80103050_325B10_name_4B[]; /* spectator timer bases */
extern f32 D_80103058_325B18_name_4B[]; /* jumpVel * 10 */
extern f32 D_80103064_325B24_name_4B[]; /* jumpAccel * 10 */
extern s16 D_80103070_325B30_name_4B[]; /* spectator spaces */
extern BoardEventTableEntry D_801030C4_325B84_name_4B[];

/* bss */
extern MBModel* D_80103100_325BC0_name_4B;
extern MBModel* D_80103104_325BC4_name_4B;
extern MBModel* D_80103108_325BC8_name_4B; /* spectator model the others copy */
extern MBModel* D_80103110_325BD0_name_4B[]; /* 9 spectators */

/* overlay */
void func_80102830_3252F0_name_4B(void);
void func_80102874_325334_name_4B(void);
void func_801028DC_32539C_name_4B(void);
void func_80102950_325410_name_4B(void);
void func_80102990_325450_name_4B(void);
void func_801029BC_32547C_name_4B(void);
void func_80102A2C_3254EC_name_4B(void);
void func_80102A9C_32555C_name_4B(void);
void func_80102B0C_3255CC_name_4B(void);
void func_80102C6C_32572C_name_4B(s16 index);
void func_80102D64_325824_name_4B(void);
void func_80102DC4_325884_name_4B(void);
void func_80102DE8_3258A8_name_4B(void);
void func_80102FC8_325A88_name_4B(void);
void func_80102FF4_325AB4_name_4B(void);

#endif
