#ifndef _OVL_44_H
#define _OVL_44_H

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

/* ---- main-segment API used by 44 ---- */

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
extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
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
void func_800890CC_89CCC(s16, s32, s32, s32);
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

/* ---- duel work types (copies of the ovl_42.h ones) ---- */

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

/* Wait for the step flag (D_80108E80) / for the message to finish (3F's WAIT_STEP/WAIT_MESSAGE). */
#define PD_WAIT_STEP()                           \
    while (TRUE) {                               \
        if (D_80108E80_2E0F30_name_44 != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

#define PD_WAIT_MESSAGE()                                                     \
    while (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {     \
        HuPrcVSleep();                                                        \
    }

/* ---- 44's duel game ---- */

/* func_801068CC's work: the CPU duelists' answers to the 16-move sequence D_80108F00. */
typedef struct D44CpuWork {
    /* 0x000 */ s32 wait[16];      /* frames before each answer (shared by both sides) */
    /* 0x040 */ s32 unk40[16];
    /* 0x080 */ s32 idx[2];        /* per side: the move being answered */
    /* 0x088 */ s32 wrong[32];     /* [side * 16 + i]: this answer was made wrong */
    /* 0x108 */ s32 moves[32];     /* [side * 16 + i]: the answers */
    /* 0x188 */ s32 timer[2];      /* per side: frames until the next answer */
} D44CpuWork; /* size 0x190 */

/* ---- 44 data (asm/data/overlays/ovl_44_name/2E09D0.data.s) ---- */

extern PdStatusLayout D_80108920_2E09D0_name_44[8];
extern u32* D_80108AD0_2E0B80_name_44[6]; /* per character: motion list (count, files) */
extern s32 D_80108AE8_2E0B98_name_44[16]; /* frames between the beats ([0] is 0) */

/* ---- 44 bss (asm/data/overlays/ovl_44_name/ovl_44_bss.bss.s) ---- */

extern s32 D_80108E80_2E0F30_name_44; /* a step finished */
extern s32 D_80108E84_2E0F34_name_44; /* the stake */
/* func_80105158's message: window x and y (stored as s32, read as s16), variant, id, the
   player it names. */
extern s32 D_80108E88_2E0F38_name_44;
extern s32 D_80108E8C_2E0F3C_name_44;
extern s32 D_80108E90_2E0F40_name_44;
extern s32 D_80108E94_2E0F44_name_44;
extern s32 D_80108E98_2E0F48_name_44;
extern s32 D_80108E9C_2E0F4C_name_44;
extern s32 D_80108EA0_2E0F50_name_44; /* the challenger */
extern s32 D_80108EA4_2E0F54_name_44; /* the opponent, -1 until chosen */
extern s32 D_80108EA8_2E0F58_name_44[4]; /* players in the scene */
extern s32 D_80108EB8_2E0F68_name_44; /* how many */
extern s32 D_80108EC0_2E0F70_name_44[4]; /* opponents to choose from */
extern s32 D_80108ED0_2E0F80_name_44; /* the minimum stake */
extern s32 D_80108ED4_2E0F84_name_44; /* the turn */
extern s32 D_80108ED8_2E0F88_name_44; /* the outcome: 1 draw, 2 challenger wins, 3 opponent wins */
extern s32 D_80108EDC_2E0F8C_name_44; /* the poorer player's coins */
extern s32 D_80108EE0_2E0F90_name_44[2];
extern s32 D_80108EE8_2E0F98_name_44; /* CPU pad triggers */
extern s32 D_80108F00_2E0FB0_name_44[16]; /* the move sequence, 0..2 each */
extern s32 D_80108F58_2E1008_name_44; /* the move expected now */
extern s32 D_80108FB8_2E1068_name_44[2];
extern s32 D_80108FC8_2E1078_name_44[2];
extern s32 D_80108FD0_2E1080_name_44[2];
extern s32 D_80108FD8_2E1088_name_44[2];
extern omObjData* D_80108FC4_2E1074_name_44; /* func_80106C24's object */
extern s32 D_80108FE0_2E1090_name_44;
extern s32 D_80108FE4_2E1094_name_44; /* no referee (flag 0x17 clear) */
extern MBModel* D_80108FF0_2E10A0_name_44; /* the referee's hat (scaled away) */

/* ---- 2DA8B0.c ---- */

void func_80102800_2DA8B0_name_44(void);
void func_8010298C_2DAA3C_name_44(void);
void func_80102C20_2DACD0_name_44(omObjData* obj);
void func_80102C74_2DAD24_name_44(void);
void func_80102D00_2DADB0_name_44(void);
void func_80105158_2DD208_name_44(void);
/* Returns the window id (an s16) as an int: its caller does not re-extend it. */
s32 func_80105584_2DD634_name_44(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
u16 func_801056EC_2DD79C_name_44(void); /* the duelists' pad triggers */
void func_801057AC_2DD85C_name_44(s32 layout);
void func_80105AE4_2DDB94_name_44(omObjData* obj);
void func_80105B7C_2DDC2C_name_44(void);
void func_80105BB8_2DDC68_name_44(omObjData* obj);
void func_80105C10_2DDCC0_name_44(omObjData* obj);
void func_80105C64_2DDD14_name_44(void);
void func_80105CF4_2DDDA4_name_44(omObjData* obj);
void func_80105D84_2DDE34_name_44(void);
void func_80106050_2DE100_name_44(void);
void func_801068CC_2DE97C_name_44(void);
void func_80106C24_2DECD4_name_44(omObjData* obj);
s32 func_80106F1C_2DEFCC_name_44(void);
void func_80107208_2DF2B8_name_44(s32 arg0, s32 arg1, s32 arg2); /* CPU input script */
void func_80107838_2DF8E8_name_44(omObjData* obj);
s32 func_801079D8_2DFA88_name_44(void); /* CPU pad triggers (D_80108EE8) */
void func_801079E4_2DFA94_name_44(void);
void func_80107B1C_2DFBCC_name_44(void);
void func_80107BF4_2DFCA4_name_44(s32 move, s32 side, s32 player, s32 correct);
void func_80107F28_2DFFD8_name_44(void);
void func_8010838C_2E043C_name_44(void);
void func_801085BC_2E066C_name_44(void);
void func_80108750_2E0800_name_44(void);
void func_80108870_2E0920_name_44(void);
void func_801088A4_2E0954_name_44(void);
void func_801088AC_2E095C_name_44(void);

#endif
