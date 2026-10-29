#ifndef _OVL_42_H
#define _OVL_42_H

/* Overlay 42 (2C0780.c): board 41's duel scene, the successor of board 3E's (overlay 3F, ovl_3F.h):
   a stand-alone scene (its own omInitObjMan) with a referee. The challenger
   (D_800F8D1A.attacker) picks an opponent when several are eligible, both stake coins, then the
   duel is played (fork B's processes 80109214/80109780/801064E8) until D_80109DC8 decides it;
   the winner takes both stakes. The result is left for the board in D_800FC880 (winner) and
   D_800F8C5C (loser), -1 both for a draw.
   The unit's .rodata is carved ([0x2C7B40, .rodata, 2C0780]); leftovers are defined raw in C by
   tools/mp2rodefs.py beside their first user. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/malloc.h"
#include "game/camera.h"
#include "game/gamemes.h"
#include "game/hmfman.h"

/* ---- main-segment API used by 42 ---- */

#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

/* A path the model walks (func_8005A718_5B318 in 58080); same as ovl_3F.h's. */
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
extern BoardStatus D_80101510_102110[];
extern Vec2f D_800FC990_FD590[];
extern Vec2f D_800FD854_FE454[];
extern s8 D_80102708_103308;
/* The duel's result for the board: the winner and the loser (-1 both for a draw). */
extern s32 D_800FC880_FD480;
extern s32 D_800F8C5C_F985C;

s32 BoardSpaceGet(s32 index, s32 count);
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
f32 __sinf(f32);
f32 __cosf(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
void MBDBackKill(void);
void MBModelDispOff(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerModelCreate(s16, void*, s32);
void MBVsSprCreateY(f32 arg0, f32 arg1);
void MBVsSprKill(void);
s32 PlaySound(s32);
void AdjustPlayerCoins(s32 index, s32 count);
GW_PLAYER* BoardPlayerGet(s32);
void espDispOff(u16);
void espDispOn(u16);
void ShowTextWindow(s32 arg0);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A96C_1B56C(u16, u8, u8, u8); /* sprite colour */
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
void func_80029FE4_2ABE4(s16, f32);
f32 func_80042BE0_437E0(Vec*); /* y angle of a rotation */
void func_80043DAC_449AC(MBModel*);
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_8005762C_5822C(s32 arg0); /* close a window that waited for a press */
void func_80057730_58330(s16, s32);
void func_80057A78_58678(s32, s32, s32); /* both duelists' portraits in a window */
void func_800581A0_58DA0(void);
void func_80059120_59D20(void*, f32, f32); /* jump: velocity, gravity */
void func_80059158_59D58(void*); /* start the jump */
void func_800593C0_59FC0(void);
void func_80059400_5A000(void);
s32 func_8005A7E8_5B3E8(MBModel* model, Vec* target, f32 step); /* turn toward; TRUE when facing */
s32 func_80059FD0_5ABD0(s32 player); /* the player's rank, 0 = first */
ModelPathWork* func_8005A718_5B318(MBModel* model, f32 speed, s16 count, Vec* points);
s32 func_8005A778_5B378(ModelPathWork*); /* path finished */
void func_8005AA48_5B648(MBModel*, char*, s16);
void func_8005AC6C_5B86C(MBModel*, s32);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_8005ACD0_5B8D0(GW_PLAYER*, s16);
void func_8005E2B8_5EEB8(void);
void func_8005FE10_60A10(void);
void func_80060034_60C34(u32, s32);
void func_800600F8_60CF8(s32, s16, s16);
void func_8006135C_61F5C(s32 player, s32 coins, s32);
void func_800614B4_620B4(s32, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_800695D8_6A1D8(s16 mesId, s16 time);
s32 func_80069538_6A138(void);
s32 func_800696E4_6A2E4(void);
void func_80069764_6A364(s16 time);
void func_80069770_6A370(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
/* Defined (u32, s16, s16) in 73BA0.c; retail passes full words here. */
omObjData* func_800732FC_73EFC(u32 arg0, s32 arg1, s32 arg2);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32, s16);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800799A4_7A5A4(s16, s32);
void func_80088640_89240(void);
/* s16 in 58080.c; retail re-extends the result here, as if it were an int. */
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, void*, s32, s32); /* a message id or a string */
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s32); /* window message argument */
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16);
void func_8008CCA8_8D8A8(s16);
void func_8008D88C_8E48C(s16);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
u32 func_800A5610_A6210(char*); /* strlen */
omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
int sprintf(char* dst, const char* fmt, ...);

/* ---- 42 work types ---- */

/* Status-window layouts (D_801098A0): four slots as from/to positions, and the frames the move
   takes (ovl_3F.h's Unk3FStatusLayout). */
typedef struct PdStatusLayout {
    /* 0x00 */ s16 pos[4][4]; /* x0, y0, x1, y1; -1 keeps the current value */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 frames;
} PdStatusLayout; /* size 0x24 */

/* func_80105694's shrinking-hat object (ovl_3F.h's Unk3FShrink). */
typedef struct PdShrink {
    /* 0x00 */ s32 timer;
    /* 0x04 */ f32 scaleSpeed;
    /* 0x08 */ f32 rotSpeed;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
} PdShrink; /* size 0x14 */

/* ---- 42-B ---- */

extern u16 ContBtnTrg[];
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_80042E44_43A44(Vec* v, f32 angle); /* rotate v about y */
extern u8 D_800FDBE0_FE7E0; /* the frame buffer being drawn */
extern u8 D_800FDBCA_FE7CA; /* number of frame buffers */
s16 func_80027FA4_28BA4(u32, void*, u8);
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_8005AA98_5B698(s16);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y); /* sprite scale */
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y);
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_800794A8_7A0A8(s32);
void MBVecNormalize(Vec*);
void omSetTra(omObjData*, f32, f32, f32);

/* The CPU input script (func_801070F4/func_80107724; ovl_3F.h's Unk3FCpuInput): mode 0 presses
   Start, 2 moves the cursor to an opponent and presses A, 3 raises the stake to a target. */
typedef struct PdCpuInput {
    /* 0x00 */ s32 timer;
    /* 0x04 */ s32 cur;    /* the cursor row / the stake now */
    /* 0x08 */ s32 target; /* the row / the stake wanted */
    /* 0x0C */ s32 mode;
} PdCpuInput; /* size 0x10 */

/* func_801062FC's timeline object (func_80106B5C). */
typedef struct PdTimeline {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 frame; /* 0..149 */
} PdTimeline; /* size 0x08 */

/* func_801088FC's slide (func_80108F98). */
typedef struct PdSlideWork {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 player;
    /* 0x08 */ f32 x;     /* the shadow's x at the start */
    /* 0x0C */ s32 frame;
    /* 0x10 */ f32 offs[100];
} PdSlideWork; /* size 0x1A0 */

/* A move sprite's pop (func_80109344/func_801093D8) or a wrong move's pause
   (func_801094D4/func_80109648). */
typedef struct PdMoveWork {
    /* 0x00 */ s32 side;  /* 0 the challenger, 1 the opponent */
    /* 0x04 */ s32 timer;
    /* 0x08 */ s32 slot;  /* the move's sprite; for a wrong move, the player */
    /* 0x0C */ f32 angle;
} PdMoveWork; /* size 0x10 */

/* A streak of the effect func_80108000 (ovl_4F.h's Ovl4FStreak). */
typedef struct PdStreak {
    /* 0x00 */ u8 col[3][4]; /* the vertices' colours; fade each frame */
    /* 0x0C */ Vec pos;
    /* 0x18 */ f32 len;
    /* 0x1C */ Vec dir;
    /* 0x28 */ f32 speed;
} PdStreak; /* size 0x2C */

/* Wait for the step flag (D_80109D70) / for the message to finish (3F's WAIT_STEP/WAIT_MESSAGE). */
#define PD_WAIT_STEP()                           \
    while (TRUE) {                               \
        if (D_80109D70_2C7CF0_PirateDuel != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

#define PD_WAIT_MESSAGE()                                                     \
    while (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {     \
        HuPrcVSleep();                                                        \
    }

/* ---- 42 data (asm/data/overlays/ovl_42_PirateDuel/2C7820.data.s) ---- */

extern PdStatusLayout D_801098A0_2C7820_PirateDuel[8];
extern u32* D_80109AF8_2C7A78_PirateDuel[6]; /* per character: motion list (count, files) */
extern s32 D_80109B10_2C7A90_PirateDuel;
extern Vec D_80109B14_2C7A94_PirateDuel; /* the referee's spot */
extern Vec D_80109B20_2C7AA0_PirateDuel[1];
extern Vec D_80109B2C_2C7AAC_PirateDuel[3];
extern Vec D_80109B50_2C7AD0_PirateDuel[1];
extern Vec D_80109B5C_2C7ADC_PirateDuel[3];
extern f32 D_80109B80_2C7B00_PirateDuel[6]; /* per character: the sword's scale */
/* fork B's (raw) */
extern Vec D_80109B98_2C7B18_PirateDuel; /* the sword tip, from the hitting model */
extern f32 D_80109BA4_2C7B24_PirateDuel; /* the clash frame of motion 3 */
extern s32 D_80109BA8_2C7B28_PirateDuel[1]; /* a clash is under way */
extern s32 D_80109BAC_2C7B2C_PirateDuel; /* flash frames left */
extern u8 D_80109BB0_2C7B30_PirateDuel[3][4]; /* the streaks' start colours */

/* ---- 42 bss (asm/data/overlays/ovl_42_PirateDuel/ovl_42_bss.bss.s) ---- */

extern s32 D_80109D70_2C7CF0_PirateDuel; /* a step finished */
extern s32 D_80109D74_2C7CF4_PirateDuel; /* the stake */
/* func_80104B88's message: window x and y (stored as s32, read as s16), variant, id, the
   player it names. */
extern s32 D_80109D78_2C7CF8_PirateDuel;
extern s32 D_80109D7C_2C7CFC_PirateDuel;
extern s32 D_80109D80_2C7D00_PirateDuel;
extern s32 D_80109D84_2C7D04_PirateDuel;
extern s32 D_80109D88_2C7D08_PirateDuel;
extern s32 D_80109D8C_2C7D0C_PirateDuel;
extern s32 D_80109D90_2C7D10_PirateDuel; /* the challenger */
extern s32 D_80109D94_2C7D14_PirateDuel; /* the opponent, -1 until chosen */
extern s32 D_80109D98_2C7D18_PirateDuel[4]; /* players in the scene */
extern s32 D_80109DA8_2C7D28_PirateDuel; /* how many */
extern s32 D_80109DB0_2C7D30_PirateDuel[4]; /* opponents to choose from */
extern s32 D_80109DC0_2C7D40_PirateDuel; /* the minimum stake */
extern s32 D_80109DC4_2C7D44_PirateDuel; /* the turn */
extern s32 D_80109DC8_2C7D48_PirateDuel; /* the outcome: 1 draw, 2 challenger wins, 3 opponent wins */
extern s32 D_80109DCC_2C7D4C_PirateDuel; /* the poorer player's coins */
extern s32 D_80109DD0_2C7D50_PirateDuel[4];
extern s32 D_80109DE0_2C7D60_PirateDuel[2];
extern s32 D_80109DE8_2C7D68_PirateDuel; /* CPU pad triggers */
extern s32 D_80109DEC_2C7D6C_PirateDuel;
extern s32 D_80109DF0_2C7D70_PirateDuel;
extern s16 D_80109DF4_2C7D74_PirateDuel[4]; /* each player's item_hook model */
extern s16 D_80109DFC_2C7D7C_PirateDuel[4]; /* each player's second model */
extern s16 D_80109E08_2C7D88_PirateDuel[2][150]; /* per duelist: the timeline's marked frames */
extern s32 D_8010A060_2C7FE0_PirateDuel; /* no referee (flag 0x17 clear) */
extern s16 D_8010A064_2C7FE4_PirateDuel[3]; /* the three sword sprite files */
/* the five moves' sprites, the challenger's then the opponent's (D_8010A070[5] is D_8010A07A[0]) */
extern s16 D_8010A070_2C7FF0_PirateDuel[10];
extern s16 D_8010A07A_2C7FFA_PirateDuel[5];
extern s16 D_8010A084_2C8004_PirateDuel;
extern s16 D_8010A086_2C8006_PirateDuel;
extern s16 D_8010A088_2C8008_PirateDuel[2];
extern s16 D_8010A08C_2C800C_PirateDuel[2];
extern s32 D_8010A090_2C8010_PirateDuel[2];
extern s32 D_8010A098_2C8018_PirateDuel[2];
extern s32 D_8010A0A0_2C8020_PirateDuel[5]; /* the five moves: 0..2 each */
extern MBModel* D_8010A0B4_2C8034_PirateDuel; /* the referee */
extern MBModel* D_8010A0B8_2C8038_PirateDuel; /* the referee's hat (scaled away) */
extern Vtx* D_8010A0C0_2C8040_PirateDuel[8]; /* the streaks' vertices, per frame buffer */
extern Gfx* D_8010A0E0_2C8060_PirateDuel[8]; /* their display list, per frame buffer */
extern omObjData* D_8010A100_2C8080_PirateDuel;

/* ---- 2C0780.c ---- */

void func_80102800_2C0780_PirateDuel(void);
void func_8010298C_2C090C_PirateDuel(void);
void func_80102BC0_2C0B40_PirateDuel(omObjData* obj);
void func_80102C14_2C0B94_PirateDuel(void);
void func_80102CA0_2C0C20_PirateDuel(void);
void func_80104B88_2C2B08_PirateDuel(void);
/* Returns the window id (an s16) as an int: its caller does not re-extend it. */
s32 func_80104FB4_2C2F34_PirateDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
u16 func_8010511C_2C309C_PirateDuel(void); /* the duelists' pad triggers */
void func_801051DC_2C315C_PirateDuel(s32 layout);
void func_80105514_2C3494_PirateDuel(omObjData* obj);
void func_801055AC_2C352C_PirateDuel(void);
void func_801055E8_2C3568_PirateDuel(omObjData* obj);
void func_80105640_2C35C0_PirateDuel(omObjData* obj);
void func_80105694_2C3614_PirateDuel(void);
void func_80105724_2C36A4_PirateDuel(omObjData* obj);
void func_801057B4_2C3734_PirateDuel(void);
void func_80105A80_2C3A00_PirateDuel(void);
/* fork B's (inferred from the asm and callers) */
void func_801062FC_2C427C_PirateDuel(void);
void func_801064E8_2C4468_PirateDuel(void);
void func_80106B5C_2C4ADC_PirateDuel(omObjData* obj);
s32 func_80106E08_2C4D88_PirateDuel(void);
void func_801070F4_2C5074_PirateDuel(s32 arg0, s32 arg1, s32 arg2); /* CPU input script */
void func_80107724_2C56A4_PirateDuel(omObjData* obj);
s32 func_801078C4_2C5844_PirateDuel(void); /* CPU pad triggers (D_80109DE8) */
void func_801078D0_2C5850_PirateDuel(void);
void func_80107D00_2C5C80_PirateDuel(void);
void func_80107E20_2C5DA0_PirateDuel(void);
void func_80108000_2C5F80_PirateDuel(omObjData* obj);
void func_80108384_2C6304_PirateDuel(f32 x, f32 y, f32 z, u8 frames);
void func_801086B0_2C6630_PirateDuel(void);
void func_801088FC_2C687C_PirateDuel(s32 player, s32 move);
void func_80108F98_2C6F18_PirateDuel(omObjData* obj);
void func_80109040_2C6FC0_PirateDuel(void);
void func_8010913C_2C70BC_PirateDuel(void);
void func_80109214_2C7194_PirateDuel(void);
void func_80109344_2C72C4_PirateDuel(s32 side);
void func_801093D8_2C7358_PirateDuel(omObjData* obj);
void func_801094D4_2C7454_PirateDuel(s32 side);
void func_80109648_2C75C8_PirateDuel(omObjData* obj);
void func_80109780_2C7700_PirateDuel(void);

#endif
