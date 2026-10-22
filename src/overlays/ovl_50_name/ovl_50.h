#ifndef _OVL_50_H
#define _OVL_50_H

/* Overlay 50: the board ending of boards 2, 4 and 5 (overlay 52, the bonus stars, goes here after
   those boards; 4F plays boards 0, 1, 3 and 51 board 6). It is 4F's sibling and shares its flow:
   func_80102800 sets up the scene and the process func_80102974, which calls the board's setup
   and scene from D_80111964 / D_8011197C (indexed by D_80112744, the board): board 2 has
   func_80104324 + func_80104280 (344AE0.c), board 4 func_801090FC + func_80109070 (344AE0.c),
   board 5 func_8010D3F4 + func_8010D360 (34DBC0.c); the other entries point at board 4's. Then
   the shared winner scene func_80102DDC, a model circles in (func_80103AA4), and the overlay goes
   on to 0x51 (results). D_8011275A is the winner (gPlayers index), D_80112756 the player
   D_800F8CE4_F98E4[3] names.

   Retail's overlay is three files: 343060.c (80102800-801041C8), 344AE0.c (80104280-8010D320) and
   34DBC0.c (8010D360 on: board 5's scene, then the effect-object library 4F keeps in 33FE50.c).
   .data and .bss stay asm; each file's .rodata is carved. Every function is global.
   Prototypes of 344AE0.c's functions came from the asm's register use only: the fork that owns
   a function fixes its line. */

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
#define OVL50_PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

/* ---- main-segment API used by 50 ---- */

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

extern f32 D_80101300_101F00;
extern f32 D_8010105C_101C5C;
f32 HuVecDistance(Vec* a, Vec* b);
f32 func_80042BE0_437E0(Vec*); /* y angle of a rotation; func_80106198 calls it as s32 */
void func_80042E44_43A44(Vec* v, f32 angle); /* rotate v about y */
void func_80020D20_21920(s16 arg0);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
void func_80029C74_2A874(s16, f32);
extern void* D_800FD2A8_FDEA8; /* the camera being drawn (hmfman.h: void*) */
s32 func_8005A608_5B208(MBModel* model, Vec* target, f32 speed); /* func_8005A5E8, rotation discarded */
void func_80026D50_27950(s16, u8, u8);
void func_80026E00_27A00(s16, f32, f32, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
f64 fabs(f64);
u8 rand8(void);
void* DataRead(s32 dirAndFile);
s16 func_8003DF08_3EB08(void* arg);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void espPosSet(u16 spriteId, s16 x, s16 y);
void espDispOff(u16);
void func_8001AC44_1B844(u16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void HuMemFree(void*);
s16 func_80027FA4_28BA4(u32, void*, u8);
extern u8 D_800FDBCA_FE7CA; /* number of frame buffers */
extern u8 D_800FDBE0_FE7E0; /* the frame buffer being drawn */
void HmfModelObjAttrSet(s16, s32, s32);
u8 func_80018DC0_199C0(void* arg0, s32 arg1, char* arg2);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
s16 func_80027D3C_2893C(s16); /* model copy */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_8003E8E4_3F4E4(s16);
void func_80079848_7A448(s16);
void func_800B3170_B3D70(Vec*, Vec*); /* HuVecCopy3F */
void func_80052E68_53A68(f32); /* MBCameraZoomSet */
u16 MBDCameraPos3DSet(Vec*);
s32 omDelPrcObj(void*);

/* ---- main data ---- */

extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
extern s32 D_800CC5F8[]; /* per character: the name message */
extern u16 D_800CD526_CE126;
extern s16 D_800F8CE4_F98E4[]; /* [0] the winner, [3] another player (see D_80112756) */
extern s16 D_800FA188_FAD88;
extern u16 D_801011FC_101DFC; /* set: skip the scene */

/* ---- overlay .data (asm); the layout of 4F's 8010F750-8010F988, 0x2210 higher ---- */

extern s16 D_80111960_3521C0_name_50; /* music; -1 at start */
extern void (*D_80111964_3521C4_name_50[6])(void); /* per board: scene setup */
extern void (*D_8011197C_3521DC_name_50[6])(void); /* per board: scene */
/* The next three are s32 tables in the ROM (0x80111994 [6][5], 0x80111A0C [6][2], 0x80111A3C
   [6][3]: motions per board) whose first word has no label; retail reads only the low halves
   (lh at +2), so they are declared as s16 views from the first label: element [b][2 * k] is the
   low half of word k. On a host that swaps words this view is wrong: use the s32 words. */
extern s16 D_80111996_3521F6_name_50[6][10]; /* the winner's motions */
extern s16 D_80111A0E_35226E_name_50[6][4];  /* D_8011274C's motions */
extern s16 D_80111A3E_35229E_name_50[6][6];  /* D_80112748's motions */
extern s32 D_80111A84_3522E4_name_50[6];     /* per board: the winner's first message */
extern s32 D_80111A9C_3522FC_name_50[6];     /* per board: the second message */
extern s32 D_80111AB4_352314_name_50[6];     /* per board: a sound with the first message, -1 none */
extern s32 D_80111ACC_35232C_name_50[6];     /* per board: a sound with the second */
extern Vec D_80111AE4_352344_name_50;
extern Vec D_80111AF0_352350_name_50[3][2];  /* the other players: start, end */
/* {start, target} pairs; splat's D_80111B44, D_80111B5C, D_80111B74 are their [1] */
extern Vec D_80111B38_352398_name_50[2]; /* D_80112748 */
extern Vec D_80111B50_3523B0_name_50[2]; /* D_8011274C */
extern Vec D_80111B68_3523C8_name_50[2]; /* D_80112740: start; [1] the centre it circles */
extern u16 D_80111B80_3523E0_name_50[6];     /* per character: frames to the winner's voice */
extern s32 D_80111B8C_3523EC_name_50[6];     /* per board: the flag that allows skipping */
extern u32* D_80112308_352B68_name_50[6];    /* board 5, per character: MBPlayerModelCreate list */
extern u32 D_80112320_352B80_name_50[];      /* board 5's host: MBModelFileCreate list */
extern u32 D_8011236C_352BCC_name_50[];      /* board 5's background (0x8007B) */
extern u32 D_80112334_352B94_name_50[];      /* board 5: 0x8008B's MBModelFileCreate list */
extern s32 D_80112398_352BF8_name_50;
extern s32 D_801123A0_352C00_name_50;
extern s32 D_801123A4_352C04_name_50[2];
extern s32 D_801123AC_352C0C_name_50;
extern Vec D_801123B8_352C18_name_50[2]; /* D_80112748: start, target (splat's D_801123C4 is [1]) */
extern Vec D_801123D0_352C30_name_50;
extern Vec D_801123DC_352C3C_name_50;
extern Vec D_801123E8_352C48_name_50[2];
extern Vec D_80112400_352C60_name_50;    /* the doors' start */
extern Vec D_8011240C_352C6C_name_50;    /* the doors' end */

/* ---- overlay .bss (asm) ---- */

extern s32 D_801125B0_352E10_name_50[2]; /* func_8005973C handles; splat's D_801125B4 is [1] */
extern omObjData* D_801125B8_352E18_name_50;
extern Process* D_801125BC_352E1C_name_50;
extern ModelEmitterWork* D_801125C0_352E20_name_50;
extern MBModel* D_80112618_352E78_name_50; /* board 5's background */
extern omObjData* D_80112638_352E98_name_50; /* board 5: an object func_80110EFC..80110F10 flag through work[0] */
extern void* D_80112640_352EA0_name_50[4][8]; /* per effect slot, per frame buffer: vertices */
extern Gfx* D_801126C0_352F20_name_50[4][8];  /* per effect slot, per frame buffer: display list */
extern MBModel* D_80112740_352FA0_name_50; /* the model that circles in (0x16) */
extern u16 D_80112744_352FA4_name_50; /* the board */
extern MBModel* D_80112748_352FA8_name_50;
extern MBModel* D_8011274C_352FAC_name_50;
extern s16 D_80112752_352FB2_name_50[2]; /* a message's window size */
extern u16 D_80112756_352FB6_name_50;
extern u16 D_8011275A_352FBA_name_50; /* the winner */
extern MBModel* D_8011275C_352FBC_name_50; /* board 5 (and 344AE0.c): a third model */

/* ---- 343060.c ---- */

void func_80102800_343060_name_50(void);
void func_80102974_3431D4_name_50(void);
void func_80102B2C_34338C_name_50(omObjData* obj);
void func_80102BB4_343414_name_50(void);
void func_80102C40_3434A0_name_50(omObjData* obj);
void func_80102D04_343564_name_50(void);
void func_80102D94_3435F4_name_50(void);
void func_80102DDC_34363C_name_50(void);
void func_80103AA4_344304_name_50(void);
void func_80103E48_3446A8_name_50(void);
void func_80103ED8_344738_name_50(s32 arg0);
void func_801041C8_344A28_name_50(omObjData* obj);

/* ---- 344AE0.c (forks B and C; inferred from register use) ---- */

void func_80104280_344AE0_name_50(void); /* board 2's scene */
void func_80104324_344B84_name_50(void); /* board 2's setup */
void func_801044DC_344D3C_name_50(void);
void func_80105900_346160_name_50(void);
void func_80105E58_3466B8_name_50(void);
void func_80106A90_3472F0_name_50(void);
void func_80106CF8_347558_name_50(void);
void func_80106FDC_34783C_name_50(void);
void func_801077E0_348040_name_50(void);
void func_80107A3C_34829C_name_50(void);
void func_8010804C_3488AC_name_50(void);
void func_80108290_348AF0_name_50(f32 arg0, f32 arg1, f32 arg2);
void func_80108414_348C74_name_50(void);
void func_80108448_348CA8_name_50(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_801085FC_348E5C_name_50(void);
void func_80108630_348E90_name_50(f32 arg0, f32 arg1, f32 arg2);
void func_801087FC_34905C_name_50(void);
void func_80108830_349090_name_50(f32 arg0, f32 arg1, f32 arg2);
void func_801089CC_34922C_name_50(void);
void func_80108A00_349260_name_50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80108C6C_3494CC_name_50(void);
void func_80108F1C_34977C_name_50(void); /* main's func_8004B214 */
void func_80108F2C_34978C_name_50(void);
void func_80108F98_3497F8_name_50(void);
void func_80109070_3498D0_name_50(void); /* board 4's scene */
void func_801090FC_34995C_name_50(void); /* board 4's setup (also boards 0, 1, 3) */
void func_80109290_349AF0_name_50(void);
void func_8010A2A4_34AB04_name_50(void);
void func_8010A580_34ADE0_name_50(void);
void func_8010A9B8_34B218_name_50(void);
void func_8010AB4C_34B3AC_name_50(void);
void func_8010B230_34BA90_name_50(void);
void func_8010CD24_34D584_name_50(s32 arg0, s32 arg1, s32 arg2);
void func_8010CE28_34D688_name_50(omObjData* obj);
void func_8010CF08_34D768_name_50(omObjData* obj);
omObjData* func_8010CFE8_34D848_name_50(f32 arg0, f32 arg1, f32 arg2);
void func_8010D198_34D9F8_name_50(omObjData* obj);
void func_8010D320_34DB80_name_50(omObjData* obj);

/* ---- 34DBC0.c ---- */

void func_8010D360_34DBC0_name_50(void); /* board 5's scene */
void func_8010D3F4_34DC54_name_50(void); /* board 5's setup */
void func_8010D614_34DE74_name_50(void);
void func_8010E164_34E9C4_name_50(void);
void func_8010E478_34ECD8_name_50(void);
void func_8010F1A8_34FA08_name_50(void);
void func_8010F79C_34FFFC_name_50(void);
void func_801100EC_35094C_name_50(void);
void func_8011039C_350BFC_name_50(void);
void func_8011099C_3511FC_name_50(void);
void func_80110B1C_35137C_name_50(omObjData* obj);
s32 func_80110E5C_3516BC_name_50(void);
void func_80110E9C_3516FC_name_50(void);
void func_80110EFC_35175C_name_50(void);
void func_80110F10_351770_name_50(void);
s16 func_80110F20_351780_name_50(void);
s16 func_801112EC_351B4C_name_50(void);
/* The effect-object library (4F's 33FE50.c): up to four objects (slots) with per-frame-buffer
   vertex/display-list buffers. */
void func_80111690_351EF0_name_50(void);
omObjData* func_801116C8_351F28_name_50(void (*init)(omObjData*), void (*func)(omObjData*), s32 nvtx, s32 ngfx);
void func_80111868_3520C8_name_50(omObjData* obj);

#endif
