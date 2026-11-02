#ifndef _OVL_4C_H
#define _OVL_4C_H

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "process.h"
#include "game/gamemes.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/pad.h"

/* Overlay 4C: the tutorial board (board index 8, MP1's FirstMap, MP3's w10). The host walks four CPU
   players through the rules on a short chain of spaces: dice, coins, items, the bank, minigame choice;
   START (any pad) offers to skip through a yes/no window. Ends with omOvlReturnEx(1). */

#define PLAYER_MODEL_4C(i) ((MBModel*)BoardPlayerGet(i)->unk_24)

/* the three sprites of a tutorial tip */
typedef struct Ovl4CTip {
    /* 0x00 */ s16 group;
    /* 0x02 */ s16 anim0;
    /* 0x04 */ s16 anim1;
    /* 0x06 */ s16 anim2;
} Ovl4CTip; /* size = 0x8 */

/* a window backdrop from func_8005E688 */
typedef struct Ovl4CBox {
    /* 0x00 */ char pad00[0xA];
    /* 0x0A */ s16 group;
    /* 0x0C */ s16* anims;
} Ovl4CBox;

/* main */
GW_PLAYER* BoardPlayerGet(s32);
extern u16 ContDStkTrg[4];
extern u8 D_800F8C56_F9856; /* fade mode */
extern s16 D_800F8CE4_F98E4[];
s32 DirectionPrompt(struct unk_8003B8D4Struct*);
void EventTableHydrate(BoardEventTableEntry* table);
void ExecBoardScene(void*, s16);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
s16 GetCurrentPlayerIndex(void);
SpaceData* GetSpaceData(s16);
void HuMemDirectFree(void* p);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void MBCameraSpeedSet(f32);
u16 MBDCameraPos3DSet(Vec*);
Process* MBDCameraZoomMotStart(f32);
void MBMasuArrowAngleAdd(f32);
u16 MBMotionCheck(void* arg0);
void MBMotionSet(void*, s16, u16);
void MBMotionShiftSet(void* ptr, s16 a, s16 b, s16 c, u16 d);
void MBPlayerForwardSet(s16 playerNo);
void MBPlayerMotionSet(s32 index, s16 animation, s32 unk);
void MBVsSprKill(void);
s32 PlaySound(s32);
s32 PlayerIsCPU(s16);
void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void SprAnimKill(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16, s16, s32);
s16 SprCreate(s32 num, s32 attr);
void SprKill(s16 idx);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80020070_20C70(s32);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D0A0_2DCA0(s16, u8);
void func_8002D124_2DD24(s16 index);
void func_8002D4A0_2E0A0(s16);
void func_8004108C_41C8C(struct unk_8003B8D4Struct*);
s32 func_80041610_42210(struct unk_8003B8D4Struct*, s32);
s32 func_800417EC_423EC(struct unk_8003B8D4Struct*, s16, s16);
struct unk_8003B8D4Struct* func_80041A74_42674(s16, s16*);
f32 func_80042BE0_437E0(Vec*);
MBModel* func_80043510_44110(s32, void*);
void func_80043DAC_449AC(MBModel*);
void func_80046E2C_47A2C(s32 arg0);
void func_80047DB0_489B0(s32 arg0, s32 arg1);
s32 func_80047DE8_489E8(s32);
Process* func_80048800_49400(s32 player);
Process* func_80049028_49C28(s32 arg0);
Process* func_80049408_4A008(s32 arg0);
u8 func_80049470_4A070(void);
void func_8004947C_4A07C(void);
void func_8004948C_4A08C(void);
void func_80049498_4A098(s32 arg0);
void func_800494FC_4A0FC(s32 arg0);
void func_8004A9EC_4B5EC(void);
void func_8004AD34_4B934(s32);
void func_8004B214_4BE14(void);
Process* func_8004C00C_4CC0C(); /* retail passes no argument; it ignores its s32 */
void func_8004CA34_4D634(s32, s32);
Process* func_800500CC_50CCC(u32 arg0);
UnkMBGuideData* func_80050304_50F04(void*, s32);
void func_8005057C_5117C(UnkMBGuideData*);
void func_800505C4_511C4(UnkMBGuideData* guide, s16 y, s16 arg2);
void func_800514F0_520F0(void);
void func_80051500_52100(void);
void func_80052E68_53A68(f32);
void func_80053608_54208(f32);
u16 func_800536E4_542E4(Vec2f* arg0);
void func_800537A0_543A0(Vec2f* arg0);
s32 func_80053998_54598(void);
void func_800553A8_55FA8(s16 spaceIndex);
s32 func_800556F4_562F4(s16, s16);
void func_800558E8_564E8(s16);
void func_8005660C_5720C(s16, s16);
void func_80056658_57258(Vec*, Vec*, Vec*);
void func_8005670C_5730C(Vec*);
void func_80056754_57354(MBModel*);
void func_80056884_57484(s16 playerNo, s16 spaceType);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
void func_80056E34_57A34(s16 arg0, s32 arg1);
void func_8005812C_58D2C(s32 arg0);
void func_80059120_59D20(void*, f32, f32);
void func_80059158_59D58(void*);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
Process* func_8005E478_5F078(void);
Process* func_8005E544_5F144(void);
void* func_8005E688_5F288(u16 a, u16 b);
void func_80060034_60C34(u32, s32);
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void);
void func_80060B04_61704(void);
void func_80061078_61C78(s32 arg0);
void func_800614B4_620B4(s32, s32);
void func_80061518_62118(void);
void func_80062E10_63A10(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_80063C40_64840(s32, s32);
s32 func_80063F88_64B88(s32);
void func_800670BC_67CBC(Vec* arg0);
void func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
void func_800794F0_7A0F0(s32);
void func_800797DC_7A3DC(s32, s16);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
void func_800824B4_830B4(s16 group, s16 member, s32, s32, s32, s32);
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089A48_8A648(s16, s16);
void func_80089A7C_8A67C(s16 winId, s16 prio);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16 win);
s16 func_8008BA30_8C630(s16 winId);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008CCA8_8D8A8(s16);
void func_8008D88C_8E48C(s16);
void func_8008DACC_8E6CC(s32, s16*, s32);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008F624_90224(s32, s32, s32);
void func_800B3170_B3D70(Vec*, Vec*);
void func_800B3B80_B4780(f32* mtx, f32 angle);
void omPrcSetStatBit(Process*, s32);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
void MBModelKill(void*);

/* data */
extern board_overlay_entrypoint D_801054D0_328890_name_4C[]; /* scene table */
extern s16 D_801054F0_3288B0_name_4C[]; /* characters */
extern s32 D_801054F8_3288B8_name_4C[]; /* guide motions */
extern s32 D_80105500_3288C0_name_4C[]; /* model 6's motion list */
extern s16 D_8010552C_3288EC_name_4C[]; /* prompt spaces */
extern s16 D_80105534_3288F4_name_4C[]; /* CPU cursor moves */
extern BoardEventTableEntry D_8010554C_32890C_name_4C[];
extern s32 D_8010556C_32892C_name_4C[]; /* 10 tip sprites */
extern s32 D_80105594_328954_name_4C[]; /* 3 sprites */
extern s32 D_801055A0_328960_name_4C[]; /* guide */
extern s16 D_801055B8_328978_name_4C; /* guide motion request */
extern s32 D_801055BC_32897C_name_4C; /* START skip allowed */

/* bss */
extern MBModel* D_80105670_328A30_name_4C;
extern MBModel* D_80105674_328A34_name_4C;
extern MBModel* D_80105678_328A38_name_4C;
extern MBModel* D_8010567C_328A3C_name_4C;
extern s16 D_80105680_328A40_name_4C;
extern s16 D_80105682_328A42_name_4C;
extern s16 D_80105684_328A44_name_4C; /* camera target space, <0 the player */
extern UnkMBGuideData* D_80105688_328A48_name_4C;

/* overlay */
void func_80102800_325BC0_name_4C(void);
void func_80102830_325BF0_name_4C(void);
void func_8010286C_325C2C_name_4C(void);
void func_8010291C_325CDC_name_4C(void);
void func_8010298C_325D4C_name_4C(void);
void func_801029AC_325D6C_name_4C(void);
void func_80102A44_325E04_name_4C(void);
void func_80102A64_325E24_name_4C(void);
void func_80102ACC_325E8C_name_4C(void);
void func_80102AEC_325EAC_name_4C(void);
void func_80102B68_325F28_name_4C(void);
void func_80102B88_325F48_name_4C(void);
void func_80102BAC_325F6C_name_4C(void);
void func_80102BD0_325F90_name_4C(void);
void func_80102C14_325FD4_name_4C(void);
void func_80102C1C_325FDC_name_4C(void);
void func_80102D2C_3260EC_name_4C(void);
void func_80102D70_326130_name_4C(void);
void func_80102DAC_32616C_name_4C(void);
Ovl4CTip* func_80102DE8_3261A8_name_4C(s16 tip, s16 x, s16 y);
void func_80102FF8_3263B8_name_4C(Ovl4CTip* work);
void func_80103040_326400_name_4C(s16 index, s16 x, s16 y);
void func_80103124_3264E4_name_4C(void);
void func_80103150_326510_name_4C(void);
void func_80103230_3265F0_name_4C(s16 space);
void func_8010325C_32661C_name_4C(void);
void func_801032A8_326668_name_4C(void);
void func_801032F0_3266B0_name_4C(void);
void func_80103334_3266F4_name_4C(void);
void func_801033DC_32679C_name_4C(Vec* arg0);
void func_801033F8_3267B8_name_4C(void);
void func_8010343C_3267FC_name_4C(s16 roll);
void func_801034C8_326888_name_4C(void);
void func_801037E4_326BA4_name_4C(void);
void func_801038C8_326C88_name_4C(UnkMBGuideData* guide, s32 mess);
void func_80103930_326CF0_name_4C(UnkMBGuideData* guide, s32 mess);
void func_8010396C_326D2C_name_4C(UnkMBGuideData* guide);
void func_801039B4_326D74_name_4C(UnkMBGuideData* guide);
void func_80103A48_326E08_name_4C(UnkMBGuideData* guide, s16 y);
void func_80103B74_326F34_name_4C(void);
void func_80103C90_327050_name_4C(s16 request);
void func_80103C9C_32705C_name_4C(void);
void func_80104CC4_328084_name_4C(UnkMBGuideData* guide);
s32 func_80104E50_328210_name_4C(s32 pad);
void func_80105164_328524_name_4C(void);
void func_801052CC_32868C_name_4C(void);

#endif /* _OVL_4C_H */
