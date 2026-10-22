#ifndef _OVL_48_H
#define _OVL_48_H

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
void CameraScissorSet(s16 camIndex, RectF* rect);
void func_80054040_54C40(s16 arg0, s16 arg1); /* camera shake offset */
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
        if (D_80108910_30CCB0_name_48 != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

#define PD_WAIT_MESSAGE()                                                     \
    while (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {     \
        HuPrcVSleep();                                                        \
    }

/* func_80106A64's mash object (func_80106DEC). */
typedef struct MashWork {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 frame;    /* 0..150 */
    /* 0x08 */ s32 alpha[6]; /* the arrows' alpha, up to 255 */
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 fade;     /* alpha step */
} MashWork; /* size 0x2C */

/* ---- 48 data (asm/data/overlays/ovl_48_name/30C870.data.s) ---- */

extern PdStatusLayout D_801084D0_30C870_name_48[8];
extern u32* D_801086B0_30CA50_name_48[6]; /* per character: motion list (count, files) */
extern s32 D_801086C8_30CA68_name_48;
extern Vec D_801086CC_30CA6C_name_48;
extern Vec D_801086D8_30CA78_name_48;
extern Vec D_801086E4_30CA84_name_48[3];
extern Vec D_80108708_30CAA8_name_48;
extern Vec D_80108714_30CAB4_name_48;
extern Vec D_80108720_30CAC0_name_48;
extern Vec D_8010872C_30CACC_name_48; /* splat took it for a string: it is { -215, 0, 700 } */
extern Vec D_80108738_30CAD8_name_48;
extern Vec D_80108744_30CAE4_name_48;
extern Vec D_80108750_30CAF0_name_48[2]; /* the arrows' two columns */
extern s16 D_80108768_30CB08_name_48;
extern s16 D_8010876A_30CB0A_name_48[7];
extern s32 D_80108778_30CB18_name_48;
extern f32 D_8010877C_30CB1C_name_48[5];
extern RectF D_80108790_30CB30_name_48; /* the scene's scissor */
extern f32 D_801087A0_30CB40_name_48[4];

/* ---- 48 bss (asm/data/overlays/ovl_48_name/ovl_48_bss.bss.s) ---- */

extern s32 D_80108910_30CCB0_name_48; /* a step finished */
extern s32 D_80108914_30CCB4_name_48; /* the stake */
/* func_80104B88's message: window x and y (stored as s32, read as s16), variant, id, the
   player it names. */
extern s32 D_80108918_30CCB8_name_48;
extern s32 D_8010891C_30CCBC_name_48;
extern s32 D_80108920_30CCC0_name_48;
extern s32 D_80108924_30CCC4_name_48;
extern s32 D_80108928_30CCC8_name_48;
extern s32 D_8010892C_30CCCC_name_48;
extern s32 D_80108930_30CCD0_name_48; /* the challenger */
extern s32 D_80108934_30CCD4_name_48; /* the opponent, -1 until chosen */
extern s32 D_80108938_30CCD8_name_48[4]; /* players in the scene */
extern s32 D_80108948_30CCE8_name_48; /* how many */
extern s32 D_80108950_30CCF0_name_48[4]; /* opponents to choose from */
extern s32 D_80108960_30CD00_name_48; /* the minimum stake */
extern s32 D_80108964_30CD04_name_48; /* the turn */
extern s32 D_8010896C_30CD0C_name_48; /* the poorer player's coins */
extern s32 D_80108980_30CD20_name_48[2];
extern s32 D_80108988_30CD28_name_48; /* CPU pad triggers */
extern s32 D_80108BEC_30CF8C_name_48; /* no referee (flag 0x17 clear) */
/* the five moves' sprites, the challenger's then the opponent's (D_8010A070[5] is D_8010A07A[0]) */
extern s32 D_80108970_30CD10_name_48[4]; /* presses, per player */
extern s16 D_80108990_30CD30_name_48[2][150]; /* per duelist: the frames a CPU presses on */
extern MBModel* D_80108BF4_30CF94_name_48; /* the referee's hat (scaled away) */
extern s16 D_80108BF8_30CF98_name_48[2];
extern s16 D_80108C00_30CFA0_name_48[6]; /* the six arrow models */
extern s16 D_80108C0E_30CFAE_name_48[2]; /* per duelist: the A prompt sprite */
extern s16 D_80108C12_30CFB2_name_48[2]; /* per duelist: the B prompt sprite */
extern s16 D_80108C18_30CFB8_name_48[2]; /* per duelist: the mash sound */
extern s16 D_80108C1C_30CFBC_name_48[2]; /* per duelist: its pitch */
extern f32 D_80108C20_30CFC0_name_48[6]; /* the arrows' scales */
extern f32 D_80108C40_30CFE0_name_48[2];
extern f32 D_80108C48_30CFE8_name_48;

/* ---- 306BA0.c ---- */

void func_80102800_306BA0_name_48(void);
void func_801029A0_306D40_name_48(void);
void func_80102BD4_306F74_name_48(omObjData* obj);
void func_80102C28_306FC8_name_48(void);
void func_80102CB4_307054_name_48(void); /* the scene's main process */
void func_80105354_3096F4_name_48(void);
/* Returns the window id (an s16) as an int: its caller does not re-extend it. */
s32 func_8010571C_309ABC_name_48(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
u16 func_80105884_309C24_name_48(void); /* the duelists' pad triggers */
void func_80105944_309CE4_name_48(s32 layout);
void func_80105C7C_30A01C_name_48(omObjData* obj);
void func_80105D14_30A0B4_name_48(void);
void func_80105D50_30A0F0_name_48(omObjData* obj);
void func_80105DA8_30A148_name_48(omObjData* obj);
void func_80105DFC_30A19C_name_48(void);
void func_80105E8C_30A22C_name_48(omObjData* obj);
void func_80105F1C_30A2BC_name_48(void);
void func_801061E8_30A588_name_48(void);
void func_80106A64_30AE04_name_48(void);
void func_80106DEC_30B18C_name_48(omObjData* obj);
s32 func_80107508_30B8A8_name_48(void);
void func_801077F4_30BB94_name_48(s32 arg0, s32 arg1, s32 arg2); /* CPU input script */
void func_80107E1C_30C1BC_name_48(omObjData* obj);
s32 func_80107FBC_30C35C_name_48(void); /* CPU pad triggers (D_80108988) */
void func_80107FC8_30C368_name_48(void);
void func_80108168_30C508_name_48(void);
void func_80108220_30C5C0_name_48(void);
void func_8010848C_30C82C_name_48(void);
void func_801084C0_30C860_name_48(omObjData* obj);

#endif
