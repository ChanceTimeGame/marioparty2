#ifndef _OVL_3F_H
#define _OVL_3F_H

/* Overlay 3F (2A89A0.c): the duel scene board 3E (Western Land) calls when a player starts a duel.
   The challenger (D_80108C18) picks an opponent if more than one is eligible, both stake coins,
   the duel is played out on a desert stage (a referee model and a rolling tumbleweed), and the
   winner takes the stake; the result is left for the board in D_800FC87C/D_800F8C58 [1].
   Prototypes after 80105054 (fork B) come from the asm's register use; fork B owns them. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/malloc.h"
#include "game/camera.h"
#include "game/gamemes.h"

/* ---- main-segment API used by 3F ---- */

#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

typedef struct BattleTargets {
    /* 0x00 */ s16 targets;  /* bit per player: who can be challenged */
    /* 0x02 */ s16 attacker; /* bit of the challenger */
} BattleTargets; /* 63670.c's type */

/* A path the model walks (func_8005A718_5B318 in 58080). */
typedef struct ModelPathWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 index;
    /* 0x08 */ f32 speed;
    /* 0x0C */ Vec* points;
} ModelPathWork; /* size 0x10 */

extern u16 ContBtn[];
extern u16 ContDStkTrg[];
extern u16 D_801011FC_101DFC;
extern u16 D_800F8FE0_F9BE0;
extern u16 D_800FC87A_FD47A;
extern s16 D_800FA604_FB204;
extern s16 D_800FA606_FB206;
extern BattleTargets D_800F8D1A_F991A;
extern u8 D_01164160[]; /* the board scene font/texture block */
extern BoardStatus D_80101510_102110[];
extern Vec2f D_800FC990_FD590[];
extern Vec2f D_800FD854_FE454[];
extern s8 D_80102708_103308;
/* Minigame result words: [1] is the winner (D_800FC87C) and the loser (D_800F8C58); [0] is a
   pointer in other units (84FF0, 274D0). */
extern s32 D_800FC87C_FD47C[];
extern s32 D_800F8C58_F9858[];

s32 BoardSpaceGet(s32 index, s32 count);
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 __sinf(f32);
f32 __cosf(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
void MBDBackKill(void);
void MBModelDispOff(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerModelCreate(s16, void*, s32);
void MBVsSprCreateY(f32 arg0, f32 arg1);
void MBVsSprKill(void);
s32 PlaySound(s32);
void AdjustPlayerCoins(s32 index, s32 count);
GW_PLAYER* BoardPlayerGet(s32);
f32 __sinf(f32);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80029714_2A314(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80043DAC_449AC(MBModel*);
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_80057730_58330(s16, s32);
void func_80059400_5A000(void);
ModelPathWork* func_8005A718_5B318(MBModel* model, f32 speed, s16 count, Vec* points);
s32 func_8005A778_5B378(ModelPathWork*); /* path finished */
void func_8005AA48_5B648(MBModel*, char*, s16);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_8005ACD0_5B8D0(GW_PLAYER*, s16);
void func_8005FE10_60A10(void);
void func_80060034_60C34(u32, s32);
void func_800600F8_60CF8(s32, s16, s16);
void func_8006135C_61F5C(s32 player, s32 coins, s32);
void func_800614B4_620B4(s32, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
s32 func_800696E4_6A2E4(void);
void func_80069770_6A370(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732FC_73EFC(u32 arg0, s16 arg1, s16 arg2);
s16 func_800797DC_7A3DC(s32, s16);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800799A4_7A5A4(s16, s32);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, s32, s32);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16);
void func_8008CCA8_8D8A8(s16);
void func_8008D88C_8E48C(s16);
void func_8008D974_8E574(s32, s16);
void func_8008DACC_8E6CC(s32, char*, s32);
u32 func_800A5610_A6210(char*); /* strlen */
omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
int sprintf(char* dst, const char* fmt, ...);

/* ---- 3F work types ---- */

/* func_80104354's shrinking-referee object. */
typedef struct Unk3FShrink {
    /* 0x00 */ s32 timer;
    /* 0x04 */ f32 scaleSpeed;
    /* 0x08 */ f32 rotSpeed;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
} Unk3FShrink; /* size 0x14 */

/* The tumbleweed (func_80104D28). */
typedef struct Unk3FTumbleweed {
    /* 0x00 */ s32 active;
    /* 0x04 */ f32 rot;
    /* 0x08 */ f32 startX; /* trans.x starts at 5 times this */
    /* 0x0C */ f32 endX;
    /* 0x10 */ f32 speed;
    /* 0x14 */ s32 count;
} Unk3FTumbleweed; /* size 0x18 */

/* Status-window layouts (D_80108730): four corner positions as from/to pairs, and the frames
   the move takes. */
typedef struct Unk3FStatusLayout {
    /* 0x00 */ s16 pos[4][4]; /* x0, y0, x1, y1; -1 keeps the current value */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 frames;
} Unk3FStatusLayout; /* size 0x24 */

/* ---- 3F data (asm/data/overlays/ovl_3F_DesertDuel/2AE8D0.data.s) ---- */

extern Unk3FStatusLayout D_80108730_2AE8D0_DesertDuel[8];
extern u32* D_80108928_2AEAC8_DesertDuel[]; /* per character: motion list (count, files) */
extern s32 D_80108940_2AEAE0_DesertDuel;
extern s32 D_80108944_2AEAE4_DesertDuel;
extern Vec D_80108948_2AEAE8_DesertDuel; /* the referee's spot */
extern Vec D_80108954_2AEAF4_DesertDuel[1];
extern Vec D_80108960_2AEB00_DesertDuel[3];
extern Vec D_80108984_2AEB24_DesertDuel[1];
extern Vec D_80108990_2AEB30_DesertDuel[1];
extern Vec D_8010899C_2AEB3C_DesertDuel[6];

/* ---- 3F bss (asm/data/overlays/ovl_3F_DesertDuel/ovl_3F_bss.bss.s) ---- */

extern s32 D_80108C10_2AEDB0_DesertDuel;
extern u8 D_80108C14_2AEDB4_DesertDuel;  /* the current player */
extern s32 D_80108C18_2AEDB8_DesertDuel; /* the challenger */
extern s32 D_80108C1C_2AEDBC_DesertDuel; /* the opponent, -1 until chosen */
extern s32 D_80108C20_2AEDC0_DesertDuel[4]; /* opponents to choose from */
extern s32 D_80108C30_2AEDD0_DesertDuel; /* the winner, -1 for a draw */
extern s32 D_80108C34_2AEDD4_DesertDuel; /* the stake */
extern s32 D_80108C38_2AEDD8_DesertDuel[4]; /* players in the scene */
extern s32 D_80108C48_2AEDE8_DesertDuel; /* how many */
extern s32 D_80108C4C_2AEDEC_DesertDuel; /* frame counter / tumbleweed timer */
extern s32 D_80108C50_2AEDF0_DesertDuel; /* a step finished */
extern s16 D_80108C54_2AEDF4_DesertDuel;
extern s32 D_80108C58_2AEDF8_DesertDuel; /* the duel's outcome (1-5) */
extern s32 D_80108C5C_2AEDFC_DesertDuel[2];
extern s32 D_80108C64_2AEE04_DesertDuel;
extern s32 D_80108C68_2AEE08_DesertDuel; /* message for func_80105AAC */
extern s32 D_80108C6C_2AEE0C_DesertDuel;
extern s32 D_80108C70_2AEE10_DesertDuel;
extern s32 D_80108C74_2AEE14_DesertDuel;
extern s32 D_80108C78_2AEE18_DesertDuel;
extern s32 D_80108C7C_2AEE1C_DesertDuel; /* entries in D_80108C88 */
extern s16 D_80108C88_2AEE28_DesertDuel[]; /* game message ids */
extern s32 D_80108C8C_2AEE2C_DesertDuel; /* the minimum stake */
extern s32 D_80108C90_2AEE30_DesertDuel; /* the turn */
extern s32 D_80108C94_2AEE34_DesertDuel; /* the poorer player's coins */
extern s32 D_80108C98_2AEE38_DesertDuel;
extern s32 D_80108C9C_2AEE3C_DesertDuel; /* no referee (flag 0x17 clear) */
extern s16 D_80108CA0_2AEE40_DesertDuel;
extern s16 D_80108CA2_2AEE42_DesertDuel;
extern MBModel* D_80108CA4_2AEE44_DesertDuel; /* the referee */
extern MBModel* D_80108CA8_2AEE48_DesertDuel; /* the referee's hat (scaled away) */
extern omObjData* D_80108CD4_2AEE74_DesertDuel; /* the tumbleweed */
extern s32 D_80108CD8_2AEE78_DesertDuel;
extern omObjData* D_80108CE0_2AEE80_DesertDuel; /* the tumbleweed timer */

/* ---- 2A89A0.c ---- */

void func_80102800_2A89A0_DesertDuel(void);
void func_801029C0_2A8B60_DesertDuel(void);
void func_80102C3C_2A8DDC_DesertDuel(omObjData* obj);
void func_80102C90_2A8E30_DesertDuel(void);
void func_80102D1C_2A8EBC_DesertDuel(void);
void func_80102D48_2A8EE8_DesertDuel(void);
void func_80104354_2AA4F4_DesertDuel(void);
void func_801043E4_2AA584_DesertDuel(omObjData* obj);
void func_80104474_2AA614_DesertDuel(s32 layout);
void func_801047AC_2AA94C_DesertDuel(omObjData* obj);
s16 func_80104844_2AA9E4_DesertDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
void func_801049AC_2AAB4C_DesertDuel(void);
void func_80104C9C_2AAE3C_DesertDuel(void);
void func_80104CE4_2AAE84_DesertDuel(omObjData* obj);
void func_80104D28_2AAEC8_DesertDuel(void);
void func_80104DF4_2AAF94_DesertDuel(omObjData* obj);
void func_80104EF8_2AB098_DesertDuel(omObjData* obj);
void func_80105054_2AB1F4_DesertDuel(void);
void func_801058C8_2ABA68_DesertDuel(void);
void func_80105AAC_2ABC4C_DesertDuel(void);
void func_80105DB8_2ABF58_DesertDuel(void);
void func_80106040_2AC1E0_DesertDuel(void);
void func_80106328_2AC4C8_DesertDuel(omObjData* obj);
void func_80106600_2AC7A0_DesertDuel(void);
void func_80106988_2ACB28_DesertDuel(s32 arg0, s32 arg1);
void func_80106C94_2ACE34_DesertDuel(omObjData* obj);
void func_80107018_2AD1B8_DesertDuel(void);
void func_80107128_2AD2C8_DesertDuel(void);
void func_801071C8_2AD368_DesertDuel(omObjData* obj);
void func_80107314_2AD4B4_DesertDuel(void);
void func_80107350_2AD4F0_DesertDuel(omObjData* obj);
void func_801073A8_2AD548_DesertDuel(void);
void func_801073FC_2AD59C_DesertDuel(void);
u16 func_80107940_2ADAE0_DesertDuel(void); /* the duelists' pad triggers */
void func_80107A00_2ADBA0_DesertDuel(void);
s32 func_80107BF8_2ADD98_DesertDuel(void);
void func_80107EE4_2AE084_DesertDuel(s32 arg0, s32 arg1, s32 arg2); /* CPU input script */
void func_80108580_2AE720_DesertDuel(omObjData* obj);
u16 func_80108720_2AE8C0_DesertDuel(void); /* CPU pad triggers (D_80108C98) */

#endif
