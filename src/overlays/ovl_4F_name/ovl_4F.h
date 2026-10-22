#ifndef _OVL_4F_H
#define _OVL_4F_H

/* Overlay 4F: the board ending of boards 0, 1 and 3 (overlay 52, the bonus stars, goes here after
   those boards; 50 and 51 play the others). It descends from MP1's story-board endings
   (ovl_41_YoshisTropicalIslandEndingScene): the winner is crowned in a scene of the board's own,
   then the shared "star" sequence runs (the winner's motion and messages, the host, a model flying
   around, the other three players walking in), and the overlay goes on to 0x51 (results).

   func_80102800 sets up the scene and the process func_80102974, which calls the board's
   setup and scene from D_8010F754 / D_8010F76C (indexed by D_80110574, the board): board 0 has
   func_801041E4 + func_801041A0 (336DE0.c, fork A), board 1 func_801066A4 + func_80106610 (fork B),
   board 3 func_801089AC + func_80108900 (fork C); the other entries point at board 0's.
   D_80110564 is the winner (gPlayers index), D_8011057C the player D_800F8CE4_F98E4[3] names.

   Retail's overlay is two files: 335440.c (80102800-801040E0) and 336DE0.c (801041A0 on).
   .data and .bss stay asm; both files' .rodata is carved. Every function is global.
   Prototypes past 80105B4C came from the asm's register use only: the fork that owns a
   function fixes its line. */

#include "common.h"
#include "process.h"
#include "game/board.h"
#include "game/object.h"
#include "game/malloc.h"
#include "game/camera.h"
#include "game/sprite.h"
#include "game/pad.h"
#include "game/hmfman.h"

/* ---- types ---- */

/* A player's board model (GW_PLAYER.unk_24 is void* in common_structs.h). */
#define OVL4F_PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

/* Work of a model flying to a target (func_80105D14; 55's Ovl55FlyWork). */
typedef struct Ovl4FFlyWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ Vec* target;
    /* 0x08 */ f32 speed;
    /* 0x0C */ f32 rate;
    /* 0x10 */ f32 vel;
    /* 0x14 */ f32 grav;
    /* 0x18 */ u16 delay;
} Ovl4FFlyWork; /* size = 0x1C */

/* A fading puff (func_801063AC; 55's Ovl55PuffWork). */
typedef struct Ovl4FPuffWork {
    /* 0x00 */ f32 alpha;
    /* 0x04 */ f32 grow;
    /* 0x08 */ f32 fade;
    /* 0x0C */ MBModel* model;
    /* 0x10 */ u16 kill;
} Ovl4FPuffWork; /* size = 0x14 */

/* ---- main-segment API used by 4F ---- */

f32 HuMathSin(f32);
f32 __sinf(f32);
s16 LoadFormFile(s32, s32);
void MBDBackKill(void);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBModelKill(void*);
u16 MBMotionCheck(void* arg0);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerModelCreate(s16, void*, s32);
void MBVecNormalize(Vec*);
s32 PlaySound(s32);
s32 _CheckFlag(s32);
void omDelObj(omObjData*);
s32 func_80011308_11F08(s16); /* 11F08.c: s8; retail keeps the result unextended */
void func_80015950_16550(s32);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_800209C4_215C4(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void func_800283DC_28FDC(s16 arg0);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029FE4_2ABE4(s16, f32);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
MBModel* func_80043510_44110(s32, void*);
void func_80043DAC_449AC(MBModel*);
ModelEmitterWork* func_80049ED4_4AAD4(MBModel*, s16);
void func_80049F90_4AB90(ModelEmitterWork*);
void func_80050AE0_516E0(void);
void func_80050E00_51A00(s32);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_8005762C_5822C(s32 arg0);
void func_80059400_5A000(void);
s32 func_80059520_5A120(MBModel* arg0, s32 arg1, s32 arg2); /* 58080.c: Object* */
void func_80059698_5A298(s32 arg0);
s32 func_8005973C_5A33C(s32 arg0, u16 arg1, s16 arg2, s16 arg3);
void func_800598D4_5A4D4(s32 arg0, f32 arg1, f32 arg2);
void func_8005A0CC_5ACCC(void);
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; 1 on arrival */
s32 func_8005A7E8_5B3E8(MBModel* model, Vec* target, f32 step); /* turn toward; TRUE when facing */
void func_8005A950_5B550(Vec*, f32, f32, s32); /* camera to a point */
void func_8005AA48_5B648(MBModel*, char*, s16);
void func_8005AA98_5B698(s16);
/* A text window; returns its s16 id. Retail callers pass the arguments unnarrowed. */
s32 func_8005AAC0_5B6C0(s32 x, s32 y, s32 w, s32 h);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_8005AC6C_5B86C(MBModel*, s32);
void func_8005ACD0_5B8D0(GW_PLAYER*, s16);
void func_8005AD58_5B958(MBModel*);
void func_8005AD84_5B984(MBModel*);
void func_8005E260_5EE60(s16 playerIndex);
void func_800794F0_7A0F0(s8);
void func_8007954C_7A14C(s16);
void func_80079718_7A318(s32, s32);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089308_89F08(s16, s32, s8); /* window message argument (a name message id) */
void func_8008CCA8_8D8A8(s16);
void func_8008D974_8E574(s32, s16);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 func_800B7890_B8490(f32); /* cos */

/* ---- main data ---- */

extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
extern s32 D_800CC5F8[]; /* per character: the name message */
extern u16 D_800CD526_CE126;
extern s16 D_800F8CE4_F98E4[]; /* [0] the winner, [3] another player (see D_8011057C) */
extern s16 D_800FA188_FAD88;
extern u16 D_801011FC_101DFC; /* set: skip the scene */

/* ---- overlay .data (asm) ---- */

extern s16 D_8010F750_342390_name_4F; /* music set by func_80105B4C (0x10); -1 at start */
extern void (*D_8010F754_342394_name_4F[6])(void); /* per board: scene setup */
extern void (*D_8010F76C_3423AC_name_4F[6])(void); /* per board: scene */
/* The next three are s32 tables in the ROM (0x8010F784 [6][5], 0x8010F7FC [6][2], 0x8010F82C
   [6][3]: motions per board) whose first word has no label; retail reads only the low halves
   (lh at +2), so they are declared as s16 views from the first label: element [b][2 * k] is the
   low half of word k. On a host that swaps words this view is wrong: use the s32 words. */
extern s16 D_8010F786_3423C6_name_4F[6][10]; /* the winner's motions */
extern s16 D_8010F7FE_34243E_name_4F[6][4];  /* D_80110560's motions */
extern s16 D_8010F82E_34246E_name_4F[6][6];  /* D_80110568's motions */
extern s32 D_8010F874_3424B4_name_4F[6];     /* per board: the winner's first message */
extern s32 D_8010F88C_3424CC_name_4F[6];     /* per board: the second message */
extern s32 D_8010F8A4_3424E4_name_4F[6];     /* per board: a sound with the first message, -1 none */
extern s32 D_8010F8BC_3424FC_name_4F[6];     /* per board: a sound with the second */
extern Vec D_8010F8D4_342514_name_4F;
extern Vec D_8010F8E0_342520_name_4F[3][2];  /* the other players: start, end */
/* {start, target} pairs; splat's D_8010F934, D_8010F94C, D_8010F964 are their [1] */
extern Vec D_8010F928_342568_name_4F[2]; /* D_80110568 */
extern Vec D_8010F940_342580_name_4F[2]; /* D_80110560 */
extern Vec D_8010F958_342598_name_4F[2]; /* D_8011056C: start; [1] the centre it circles */
extern u16 D_8010F970_3425B0_name_4F[6];     /* per character: frames to the winner's voice */
extern s32 D_8010F97C_3425BC_name_4F[6];     /* per board: the flag that allows skipping */
extern u32* D_8010FAA8_3426E8_name_4F[6];    /* per character: MBPlayerModelCreate list */
extern u32 D_8010FAC0_342700_name_4F[];
extern u32 D_8010FAD4_342714_name_4F[];
extern s32 D_8010FB04_342744_name_4F;
extern s32 D_8010FB08_342748_name_4F;
extern s32 D_8010FB0C_34274C_name_4F;
extern u32 D_8010FB10_342750_name_4F[];
extern Vec D_8010FB24_342764_name_4F;
extern Vec D_8010FB30_342770_name_4F;
extern Vec D_8010FB3C_34277C_name_4F[2];
extern Vec D_8010FB54_342794_name_4F;
extern Vec D_8010FB60_3427A0_name_4F;
extern s32 D_8010FB6C_3427AC_name_4F;
extern s32 D_8010FB70_3427B0_name_4F;
extern s32 D_8010FB74_3427B4_name_4F;
extern Vec D_8010FB78_3427B8_name_4F;
extern Vec D_8010FB90_3427D0_name_4F;
extern Vec D_8010FB9C_3427DC_name_4F;
extern Vec D_8010FBA8_3427E8_name_4F;
extern Vec D_8010FBB4_3427F4_name_4F;
extern Vec D_8010FBC0_342800_name_4F[6];     /* per character */

/* ---- overlay .bss (asm) ---- */

extern s32 D_80110420_343060_name_4F[2]; /* func_8005973C handles; splat's D_80110424 is [1] */
extern omObjData* D_80110428_343068_name_4F;
extern Process* D_8011042C_34306C_name_4F;
extern ModelEmitterWork* D_80110430_343070_name_4F;
extern MBModel* D_80110560_3431A0_name_4F;
extern u16 D_80110564_3431A4_name_4F; /* the winner */
extern MBModel* D_80110568_3431A8_name_4F;
extern MBModel* D_8011056C_3431AC_name_4F;
extern u16 D_80110574_3431B4_name_4F; /* the board */
extern u16 D_8011057C_3431BC_name_4F;
extern MBModel* D_80110580_3431C0_name_4F;
extern s16 D_80110584_3431C4_name_4F;
extern s16 D_80110586_3431C6_name_4F[2]; /* a message's window size */
extern s16 D_8011058A_3431CA_name_4F;

/* ---- overlay .rodata ---- */

extern const char D_801103B0_342FF0_name_4F[]; /* "item_hook" (336DE0.c) */

/* ---- 335440.c ---- */

void func_80102800_335440_name_4F(void);
void func_80102974_3355B4_name_4F(void);
void func_80102B2C_33576C_name_4F(omObjData* obj);
void func_80102BB4_3357F4_name_4F(void);
void func_80102C18_335858_name_4F(omObjData* obj);
void func_80102CDC_33591C_name_4F(void);
void func_80102D6C_3359AC_name_4F(void);
void func_80102DB4_3359F4_name_4F(void);
void func_801039BC_3365FC_name_4F(void);
void func_80103D60_3369A0_name_4F(void);
void func_80103DF0_336A30_name_4F(s32 arg0);
void func_801040E0_336D20_name_4F(omObjData* obj);

/* ---- 336DE0.c ---- */

void func_801041A0_336DE0_name_4F(void);
void func_801041E4_336E24_name_4F(void);
void func_80104324_336F64_name_4F(void);
void func_80104A0C_33764C_name_4F(void);
void func_80104C48_337888_name_4F(void);
void func_80104E84_337AC4_name_4F(void);
void func_80104E8C_337ACC_name_4F(void);
void func_80105B4C_33878C_name_4F(void);
/* fork B (inferred) */
void func_80105D14_338954_name_4F(omObjData* obj);
omObjData* func_80105F60_338BA0_name_4F(Vec* pos, MBModel* model, f32 arg2, f32 arg3);
void func_80106054_338C94_name_4F(omObjData* obj);
void func_80106198_338DD8_name_4F(omObjData* obj);
void func_80106360_338FA0_name_4F(omObjData* obj, f32 arg1);
void func_8010636C_338FAC_name_4F(omObjData* obj);
omObjData* func_801063AC_338FEC_name_4F(Vec* pos, f32 arg1, f32 arg2, s32 arg3);
void func_801064C0_339100_name_4F(omObjData* obj);
void func_801065C8_339208_name_4F(omObjData* obj, f32 arg1, f32 arg2);
void func_801065D8_339218_name_4F(omObjData* obj);
void func_80106610_339250_name_4F(void);
void func_801066A4_3392E4_name_4F(void);
void func_80106840_339480_name_4F(void);
void func_801072C0_339F00_name_4F(void);
void func_8010763C_33A27C_name_4F(void);
void func_801078B0_33A4F0_name_4F(void);
void func_801079D4_33A614_name_4F(void);
void func_80107BE8_33A828_name_4F(void);
void func_80107DD8_33AA18_name_4F(void);
void func_80107FC8_33AC08_name_4F(void);
void func_801084F4_33B134_name_4F(void);
void func_80108900_33B540_name_4F(void);
void func_801089AC_33B5EC_name_4F(void);
/* fork C (inferred) */
void func_80108B30_33B770_name_4F(void);
void func_8010A150_33CD90_name_4F(void);
void func_8010A4A8_33D0E8_name_4F(void);
void func_8010A6A0_33D2E0_name_4F(void);
void func_8010A8AC_33D4EC_name_4F(void);
void func_8010ADA0_33D9E0_name_4F(void);
void func_8010AED4_33DB14_name_4F(void);
void func_8010B4E8_33E128_name_4F(void);
void func_8010B620_33E260_name_4F(void);
/* fork D */

/* Work of a growing, fading ring (func_8010CE1C). */
typedef struct Ovl4FRingWork {
    /* 0x00 */ f32 grow;
    /* 0x04 */ s16 sprite;
    /* 0x08 */ f32 alpha;
    /* 0x0C */ f32 fade;
} Ovl4FRingWork; /* size = 0x10 */

/* A streak of the effect func_8010D4D8 (16 of them, three vertices each). */
typedef struct Ovl4FStreak {
    /* 0x00 */ u8 col[3][4]; /* the vertices' colours; fade each frame */
    /* 0x0C */ Vec pos;
    /* 0x18 */ f32 len;
    /* 0x1C */ Vec dir;
    /* 0x28 */ f32 speed;
} Ovl4FStreak; /* size = 0x2C */

void* DataRead(s32 dirAndFile);
s16 func_8003DF08_3EB08(void* arg);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 func_80042BE0_437E0(Vec*); /* y angle of a rotation */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void espPosSet(u16 spriteId, s16 x, s16 y);
void espDispOff(u16);
void func_8001AC44_1B844(u16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
void HuMemFree(void*);
s16 func_80027FA4_28BA4(u32, void*, u8);

extern u8 D_800FDBCA_FE7CA; /* number of frame buffers */
extern u8 D_800FDBE0_FE7E0; /* the frame buffer being drawn */

extern u32* D_80110008_342C48_name_4F[6]; /* per character: MBPlayerModelCreate list */
extern u32 D_80110020_342C60_name_4F[];
extern s32 D_80110068_342CA8_name_4F;
extern f32 D_80110454_343094_name_4F;
extern void* D_80110460_3430A0_name_4F[4][8]; /* per effect slot, per frame buffer: vertices */
extern Gfx* D_801104E0_343120_name_4F[4][8];  /* per effect slot, per frame buffer: display list */

void func_8010C7CC_33F40C_name_4F(void);
omObjData* func_8010CA90_33F6D0_name_4F(s16 form, f32 x, f32 y, f32 z, u8 spin, u8 grow, f32 scale);
void func_8010CC2C_33F86C_name_4F(omObjData* obj);
s16 func_8010CDD4_33FA14_name_4F(s32 id);
omObjData* func_8010CE1C_33FA5C_name_4F(Vec* pos, s32 arg1, f32 grow, f32 fade);
void func_8010CFC4_33FC04_name_4F(omObjData* obj);
s32 func_8010D114_33FD54_name_4F(f32 cur, f32 step, f32 target);
void func_8010D15C_33FD9C_name_4F(void);
void func_8010D210_33FE50_name_4F(void);
omObjData* func_8010D248_33FE88_name_4F(void (*init)(omObjData*), void (*func)(omObjData*), s32 nvtx, s32 ngfx);
void func_8010D3E8_340028_name_4F(omObjData* obj);
omObjData* func_8010D4D8_340118_name_4F(void);
void func_8010D528_340168_name_4F(omObjData* obj);
void func_8010D6FC_34033C_name_4F(omObjData* obj);
void func_8010DA90_3406D0_name_4F(void);
s32 func_8010DD7C_3409BC_name_4F(void);
s32 func_8010DDCC_340A0C_name_4F(omObjData* obj);
void func_8010DFCC_340C0C_name_4F(omObjData* obj);
void func_8010E430_341070_name_4F(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8010E5D8_341218_name_4F(s32 arg0);
s32 func_8010E610_341250_name_4F(void);
void func_8010E660_3412A0_name_4F(omObjData* obj);
s32 func_8010E70C_34134C_name_4F(omObjData* obj, s32 arg1, s32 arg2);
void func_8010E950_341590_name_4F(omObjData* obj);
void func_8010EF9C_341BDC_name_4F(omObjData* obj, s32 arg1, s32 arg2, s32 arg3);
void func_8010F128_341D68_name_4F(void);
void func_8010F188_341DC8_name_4F(s32 arg0);

#endif
