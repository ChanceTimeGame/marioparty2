#ifndef _OVL_6F_H
#define _OVL_6F_H

/* Overlay 6F (40BB00.c, retail "mresult.c"): the battle minigame's coin results, a stand-alone
   scene. func_8010299C ranks the four players from their placements (coins_mg_bonus), picks the
   payout pattern (D_80105750) and pays the pot (D_800F9208) by D_801057D0's percentages; any
   remainder goes to a random player. The scene shows the four characters on pedestals, a hook
   carries each player's coins over, and the totals are drawn as sprite digits.
   The unit's .rodata is carved ([0x40EBB0, .rodata, 40BB00]); .data and .bss stay asm.
   Model and sprite ids are kept in s32 words and read back as s16 (retail's lh of the low half). */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/data.h"

/* ---- main-segment API used by 6F ---- */

void func_80020D20_21920(s16 arg0);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A708_1B308(u16, u16);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void espPosSet(u16 spriteId, s16 x, s16 y);
u16 func_80020EBC_21ABC(void*, s32, u8);
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_80021160_21D60(s16, s32, s32);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800212A4_21EA4(s16 index);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s32 func_80027D3C_2893C(s16); /* s16 elsewhere; retail uses the result unextended */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_8002A00C_2AC0C(s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
s32 func_8002C8B8_2D4B8(void*, s16); /* s16 in 274D0.c; retail uses the result unextended */
void func_8002C9C0_2D5C0(s16, s16);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
s16 func_800797DC_7A3DC(s32, s16);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16, s16, u16, s32);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
void func_800B0EF0_B1AF0(void*, s32, s32); /* bzero-like fill */
void HmfModelObjAttrSet(s16, s32, s32);
s32 PlaySound(s32);
void omDelObj(omObjData*);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osSyncPrintf(const char* fmt, ...);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void SprBankSet(s16 group, s16 member, s32 arg2);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);

extern u16 D_800F9208_F9E08; /* the battle's coin pot (s16 in 63670.c, read lhu here) */

/* Per-character data, 0x18 bytes each (ovl_34's CTCharData). */
typedef struct BRCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
} BRCharData; /* size = 0x18 */
extern BRCharData D_800CD438_CE038[];

typedef struct EspriteSlot6F {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ s16 unk04; /* sprite group */
    /* 0x06 */ char unk06[0x1E];
} EspriteSlot6F; /* size = 0x24 (1AE60.c EspriteSlot) */
extern EspriteSlot6F* D_800F93FC_F9FFC;

/* The coin-drop objects' work (omObjData.unk_50), 0x18 bytes. */
typedef struct BRFallWork {
    /* 0x00 */ f32 vel;  /* fall speed, grows by 0.05 a frame */
    /* 0x04 */ f32 ofs;  /* height offset */
    /* 0x08 */ f32 floor; /* lands when the target's height is below this */
    /* 0x0C */ f32 dx;   /* horizontal step (func_801047C8) */
    /* 0x10 */ s32 vibrate;
    /* 0x14 */ s32 player; /* omVibrate's player (read as s16) */
} BRFallWork;

/* ---- .data (40EA00.data.s) ---- */
extern s32 D_80105700_40EA00_BattleResults[4]; /* message x per rank (read as s16) */
extern Vec D_80105710_40EA10_BattleResults[4]; /* pedestal positions */
extern f32 D_80105740_40EA40_BattleResults[4];
extern s32 D_80105750_40EA50_BattleResults[8][4]; /* rank patterns */
extern s32 D_801057D0_40EAD0_BattleResults[8][4]; /* pot percentage per rank, by pattern */
extern s32 D_80105850_40EB50_BattleResults[]; /* motion file per character (winner) */
extern s32 D_80105868_40EB68_BattleResults[]; /* motion file per character (loser) */
extern s32 D_80105880_40EB80_BattleResults; /* shared coin model, 0x80 = none yet */
extern s32 D_80105884_40EB84_BattleResults; /* shared hook model, 0x80 = none yet */
extern s32 D_80105888_40EB88_BattleResults[4]; /* digit sprite x (read as s16) */
extern s32 D_80105898_40EB98_BattleResults[4]; /* digit sprite y per rank (read as s16) */

/* ---- .bss (ovl_6F_bss.bss.s) ---- */
extern s32 D_80105960_40EC60_BattleResults[4]; /* pedestal models (read as s16) */
extern s32 D_80105970_40EC70_BattleResults[4]; /* pedestal shadows */
extern s32 D_80105980_40EC80_BattleResults[4]; /* character models */
extern s32 D_80105990_40EC90_BattleResults[4];
extern s32 D_801059A0_40ECA0_BattleResults[4]; /* coin-bag models, -1 for none */
extern s32 D_801059B0_40ECB0_BattleResults; /* the hook carrier model */
extern s32 D_801059B4_40ECB4_BattleResults;
extern s32 D_801059B8_40ECB8_BattleResults;
extern s32 D_801059BC_40ECBC_BattleResults; /* sprite models */
extern s32 D_801059C0_40ECC0_BattleResults;
extern Vec D_801059C8_40ECC8_BattleResults[4]; /* per-rank pedestal offsets */
extern s32 D_801059F8_40ECF8_BattleResults[4]; /* rank of each player */
extern s32 D_80105A08_40ED08_BattleResults[4]; /* player at each rank */
extern s32 D_80105A18_40ED18_BattleResults; /* carrier motions (read as s16) */
extern s32 D_80105A1C_40ED1C_BattleResults;
extern s32 D_80105A20_40ED20_BattleResults;
extern s32 D_80105A28_40ED28_BattleResults[4]; /* each character's result motion */
extern s32 D_80105A38_40ED38_BattleResults[4]; /* each player's message, -1 for none */
extern s32 D_80105A48_40ED48_BattleResults[4]; /* coin-count sprite groups */
extern s32 D_80105A58_40ED58_BattleResults[5]; /* coins per rank; [4] (splat D_80105A68) the pot's remainder */
extern s32 D_80105A6C_40ED6C_BattleResults; /* the player who gets it, -1 for none */
extern s32 D_80105A70_40ED70_BattleResults; /* set when the bonus coin has landed */

/* ---- overlay functions ---- */
void func_80102800_40BB00_BattleResults(void);
void func_8010299C_40BC9C_BattleResults(void);
void func_80102E3C_40C13C_BattleResults(s32 rank, f32 x, f32 y);
void func_80102E64_40C164_BattleResults(s32 rank, f32 dx, f32 dy);
s32 func_80102EBC_40C1BC_BattleResults(s32 player);
void func_80102F24_40C224_BattleResults(void);
void func_80103138_40C438_BattleResults(omObjData* obj);
s32 func_8010342C_40C72C_BattleResults(s32 delay, f32 floor, s32 vibrate, s32 player);
void func_80103518_40C818_BattleResults(omObjData* obj);
void func_80103E60_40D160_BattleResults(s16 model, f32 dy);
f32 func_80103EB4_40D1B4_BattleResults(s16 model);
void func_80103EDC_40D1DC_BattleResults(omObjData* obj);
void func_80103FD8_40D2D8_BattleResults(omObjData* obj);
void func_80104064_40D364_BattleResults(void);
void func_801040F8_40D3F8_BattleResults(s32 n, f32 y, s32 arg2);
void func_801041C0_40D4C0_BattleResults(omObjData* obj, s32 rank);
void func_801042B0_40D5B0_BattleResults(omObjData* obj);
void func_801044AC_40D7AC_BattleResults(omObjData* obj);
s32 func_80104770_40DA70_BattleResults(BRFallWork* work, f32 y, f32 floor);
u8 func_801047C8_40DAC8_BattleResults(u8 player);
void func_80104960_40DC60_BattleResults(omObjData* obj);
void func_80104BAC_40DEAC_BattleResults(s16 model, s32 player);
void func_80104C14_40DF14_BattleResults(omObjData* obj);
void func_80104D30_40E030_BattleResults(f32 scale);
void func_801052D8_40E5D8_BattleResults(void);

#endif
