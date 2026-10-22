#ifndef _OVL_55_H
#define _OVL_55_H

/* Overlay 55: the board-start scene, played once before turn 1 of every board (main's board-index
   table sends board indices 9-16 here). It descends from MP1's ovl_62_BoardIntro (2A2500.c): the
   host and the four players walk in (skippable with START once _CheckFlag(5 + board) is set), a
   board-specific explanation runs, then the players drop in, hit dice blocks for the turn order
   (func_80104B1C, MP1 func_800F8334), the player records are sorted into that order and everyone
   gets 10 coins. D_8010C58A is GwSystem.current_board_index (0-6; 5 and 6 have their own
   variants); the tables D_8010B780.. hold one function per board: board 0 in 364580.c, 1 and 2
   in 365650.c, 3 and 4 in 367540.c, 5 and 6 in 3693E0.c.

   Retail's overlay is five files (split at the 16-byte text pads): 3616F0.c (fork A),
   364580.c + 365650.c (fork B), 367540.c + 3693E0.c (fork C). Every function is global.
   .data and .bss stay asm; 3616F0.c's and 365650.c's .rodata are carved.
   Prototypes for 364580.c-3693E0.c came from the asm's register use only: the fork that owns a
   function fixes its line. */

#include "common.h"
#include "process.h"
#include "game/board.h"
#include "game/object.h"
#include "game/malloc.h"
#include "game/camera.h"
#include "game/sprite.h"
#include "game/pad.h"

/* ---- types ---- */

/* A player's board model (GW_PLAYER.unk_24 is void* in common_structs.h). */
#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)
#define OVL55_CAMERA ((HuCamera*)D_800FD2A8_FDEA8)

/* Motion-shift waiters in main (58080.c's local Unk4E530Motion, MP1 4E530.c): func_801055A4 is
   55's copy of func_80059520 with a repeat count in work[1]. */
typedef struct Ovl55MotionWait {
    /* 0x00 */ s16 motion;
    /* 0x02 */ s16 shiftAttr;
    /* 0x04 */ MBModel* model;
    /* 0x08 */ omObjData* obj;
} Ovl55MotionWait; /* size = 0xC */

/* ev-C: the board 3/4 explanation sign (D_8010C570 holds it while it shows). */
typedef struct Ovl55Banner {
    /* 0x00 */ s16 file[3];
    /* 0x06 */ u16 spr[3]; /* [0] the sign, [1] the scrolling strip, [2] the title */
    /* 0x0C */ char unk0C[0xC];
    /* 0x18 */ s16 scrollY;
    /* 0x1C */ f32 alpha;
    /* 0x20 */ Process* proc;
} Ovl55Banner; /* size = 0x24 */

/* ev-C: board 4's sign (D_8010C570). */
typedef struct Ovl55Sign4 {
    /* 0x00 */ s16 file[2];
    /* 0x04 */ s16 spr[2]; /* [0] the sign, [1] its backing */
} Ovl55Sign4; /* size = 0x8 */

/* ev-C: board 5's item table entry (D_8010C3CC); only the model is known. */
typedef struct Ovl55Item {
    /* 0x00 */ u8 unk00[3];
    /* 0x03 */ u8 model;
} Ovl55Item; /* size = 0x4 */

/* ev-C: a view of main's sprite slot (1AE60.c's local EspriteSlot, D_800F93FC). */
typedef struct Ovl55EspSlot {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 grp;
    /* 0x06 */ char unk06[0x1E];
} Ovl55EspSlot; /* size = 0x24 */

/* ev-C: board 4's bubble object work (omObjData.unk_50). */
typedef struct Ovl55Bubbles {
    /* 0x00 */ u16 delay[12]; /* frames until the bubble restarts; 0 = growing */
    /* 0x18 */ f32 scale[12];
} Ovl55Bubbles; /* size = 0x48 */

/* ---- main-segment API used by 55 ---- */

GW_PLAYER* BoardPlayerGet(s32);
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f32 HuMathSin(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecDistance(Vec* a, Vec* b);
s16 LoadFormFile(s32, s32);
void MBDBackKill(void);
u16 MBDCameraPos3DSet(Vec*);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBModelKill(void*);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerModelCreate(s16, void*, s32);
s32 PlaySound(s32);
void ShowTextWindow(s32 arg0);
void SprAnimKill(s16 animIdx);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A708_1B308(u16, u16);
void func_8001A748_1B348(u16 arg0, u16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void func_8001A9C0_1B5C0(u16 spriteId, f32 arg1);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001AC44_1B844(u16 arg0);
void func_80023124_23D24();
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_800283DC_28FDC(s16 arg0);
void func_80029708_2A308(s32 arg0);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16 arg0, f32 arg1);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16 arg0); /* motion length */
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
MBModel* func_80043510_44110(s32, void*);
void func_80043DAC_449AC(MBModel*);
void func_800461C8_46DC8(void);
void func_80046238_46E38(void);
void func_80046308_46F08(s32 arg0);
void func_80046CD8_478D8(s32 arg0);
s32 func_80046D2C_4792C(s32);
s16 func_80046F98_47B98(s32);
void func_80047B78_48778(void);
void func_80047BB8_487B8(s32);
void func_80047D2C_4892C(void);
s32 func_80047DE8_489E8(s32);
void func_80050AE0_516E0(void);
void func_80050E00_51A00(s32);
void func_80051500_52100(void);
void func_8005321C_53E1C(f32, f32);
u16 func_800536E4_542E4(Vec2f* arg0); /* 51630.c: Vec2fxy*, same layout */
void func_800537A0_543A0(Vec2f* arg0); /* 51630.c: Vec2fxy* */
void func_80054040_54C40(s16 arg0, s16 arg1);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
void func_8005762C_5822C(s32 arg0);
void func_80057DA4_589A4(s32 arg0);
void func_80059400_5A000(void);
s32 func_80059520_5A120(MBModel* arg0, s32 arg1, s32 arg2); /* 58080.c: Object* */
void func_800595E8_5A1E8(void* arg0, s32 arg1, s32 arg2);
void func_800599F0_5A5F0(void);
s32 func_80059A68_5A668(s32 arg0, s32 arg1);
void func_80059B08_5A708(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4);
void func_80059BCC_5A7CC(s32 arg0);
s32 func_80059E7C_5AA7C(Vec* arg0, Vec* arg1, f32 arg2);
void func_8005A4EC_5B0EC(s32 arg0, s32 arg1);
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; 1 on arrival */
s32 func_8005A608_5B208(MBModel* model, Vec* target, f32 speed); /* the same, rotation discarded */
s32 func_8005A7E8_5B3E8(MBModel* model, Vec* target, f32 step); /* turn toward; TRUE when facing */
/* A text window; returns its s16 id. 58080.c narrows the arguments itself; retail callers pass
   them unnarrowed and keep the result as an int. */
s32 func_8005AAC0_5B6C0(s32 x, s32 y, s32 w, s32 h);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_8005FE10_60A10(void);
void func_8005FF9C_60B9C(void);
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void func_8006135C_61F5C(s32 player, s32 coins, s32);
void func_800614B4_620B4(s32, s32);
Process* func_80076F14_77B14(process_func arg0, u16 arg1, s32 arg2, s32 arg3, Process* arg4);
void func_80079614_7A214(s16 time); /* music fade-out */
void func_80079718_7A318(s32, s32);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089308_89F08(s16, char*, s8); /* window message argument (slot; retail narrows it to s8) */
void func_80089A48_8A648(s16, s16);
s16 func_8008BA30_8C630(s16 winId);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
void func_800B2060_B2C60(f32 (*)[4], f32, f32, f32); /* 274D0.c's prototype */
void func_800B3170_B3D70(Vec*, Vec*);
f32 func_800B7890_B8490(f32); /* cos */
void omDelObj(omObjData*);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---- main data ---- */

extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
extern char* D_800CC5F8[]; /* character names, by GW_PLAYER.character */
extern HuSprite_Unk84_Struct* D_800F60B0_F6CB0[256];
extern void* D_800F93FC_F9FFC; /* 1AE60.c: EspriteSlot* */
extern void* D_800FD2A8_FDEA8; /* the camera being drawn (hmfman.h: void*); its Vec at 0xC */
extern Ovl55MotionWait D_800FDCD8_FE8D8[16];
extern u16 D_801011FC_101DFC;

/* ---- overlay data (36A640.data.s) ---- */

extern s32 D_8010B750_36A640_name_55; /* turn order decided: main's func_8005FF9C on exit */
extern s32 D_8010B754_36A644_name_55; /* players arrived */
extern s16 D_8010B758_36A648_name_55[4]; /* player model replaced */
extern s16 D_8010B760_36A650_name_55; /* host model gone */
extern s16 D_8010B762_36A652_name_55; /* START may skip */
extern s32 D_8010B764_36A654_name_55[7]; /* per board: the flag that allows the skip */
extern void (*D_8010B780_36A670_name_55[7])(void); /* per board: scene setup */
/* per board: the player's model; retail calls it unprototyped (no s16 narrowing of the index). */
extern void (*D_8010B79C_36A68C_name_55[7])();
extern void (*D_8010B7B8_36A6A8_name_55[6])(void);
extern Vec D_8010B7D0_36A6C0_name_55[5][2]; /* walk-in: host, players: start, target */
extern Vec D_8010B848_36A738_name_55[5][2]; /* walk-on: start, target */
extern Vec D_8010B8C0_36A7B0_name_55;
extern s32 D_8010B8CC_36A7BC_name_55; /* walkers finished */
extern Vec D_8010B8D0_36A7C0_name_55[5][2]; /* board 5's walk-in */
extern Vec D_8010B948_36A838_name_55[5][2];
extern Vec D_8010B9C0_36A8B0_name_55;
extern void (*D_8010B9CC_36A8BC_name_55[7])(void); /* per board: explanation */
extern s32 D_8010B9E8_36A8D8_name_55[7];
extern void (*D_8010BA04_36A8F4_name_55[7])(void);
extern void (*D_8010BA20_36A910_name_55[7])(void);
extern s32 D_8010BA3C_36A92C_name_55[7]; /* per board: message */
extern s32 D_8010BA58_36A948_name_55[7]; /* per board: message */
extern Vec D_8010BA74_36A964_name_55[7]; /* per board: drop point */
extern Vec D_8010BAC8_36A9B8_name_55;
extern Vec D_8010BAD4_36A9C4_name_55;
extern Vec D_8010BAE0_36A9D0_name_55[4];
extern Vec D_8010BB10_36AA00_name_55[4];
extern Vec D_8010BB40_36AA30_name_55[4];
extern Vec D_8010BB70_36AA60_name_55[4];
/* Symbols B and C use (raw: retype them from the asm). */
extern void* D_8010BC78_36AB68_name_55[6];
extern s32 D_8010BC90_36AB80_name_55[];
extern s32 D_8010BCA0_36AB90_name_55[];
extern s32 D_8010BCB8_36ABA8_name_55[];
extern f32 D_8010BCC0_36ABB0_name_55;
extern f32 D_8010BCC4_36ABB4_name_55;
extern f32 D_8010BCC8_36ABB8_name_55;
extern void* D_8010BDC8_36ACB8_name_55[6];
extern s32 D_8010BDE0_36ACD0_name_55[];
extern s32 D_8010BDF0_36ACE0_name_55[];
extern s32 D_8010BE08_36ACF8_name_55[];
extern s32 D_8010BE10_36AD00_name_55[];
extern s32 D_8010BE1C_36AD0C_name_55[];
extern f32 D_8010BE28_36AD18_name_55;
extern f32 D_8010BE2C_36AD1C_name_55;
extern s32 D_8010BE50_36AD40_name_55[];
extern void* D_8010BF48_36AE38_name_55[6];
extern s32 D_8010BF60_36AE50_name_55[];
extern s32 D_8010BF70_36AE60_name_55[];
extern s32 D_8010BF88_36AE78_name_55[];
extern s32 D_8010BF94_36AE84_name_55[];
extern s32 D_8010BFA0_36AE90_name_55[];
extern void* D_8010C088_36AF78_name_55[6];
extern u32 D_8010C0A0_36AF90_name_55[]; /* board 3: host's motions */
extern Vec D_8010C0B0_36AFA0_name_55[2]; /* board 3: camera from, to */
extern u32 D_8010C0C8_36AFB8_name_55[]; /* board 3: host model's motions */
extern void* D_8010C1B8_36B0A8_name_55[6];
extern u32 D_8010C1D0_36B0C0_name_55[]; /* board 4: host's motions */
extern Vec D_8010C1E0_36B0D0_name_55[2]; /* board 4: camera from, to */
extern Vec D_8010C1F8_36B0E8_name_55; /* board 4: host start */
extern Vec D_8010C204_36B0F4_name_55; /* board 4: host target */
extern Vec D_8010C210_36B100_name_55; /* board 4: follower start */
extern u32 D_8010C21C_36B10C_name_55[]; /* board 4: host model's motions */
extern f32 D_8010C22C_36B11C_name_55[12]; /* board 4: bubble columns (x) */
extern void* D_8010C338_36B228_name_55[6];
extern u32 D_8010C350_36B240_name_55[]; /* board 5: host's motions */
extern u32 D_8010C360_36B250_name_55[]; /* board 5: stand-in's motions */
extern Vec D_8010C370_36B260_name_55[2]; /* board 5: camera from, to */
extern Vec D_8010C388_36B278_name_55; /* board 5: host start */
extern Vec D_8010C394_36B284_name_55; /* board 5: host target */
extern u32 D_8010C3A0_36B290_name_55[]; /* board 5: host model's motions */
extern s32 D_8010C3B0_36B2A0_name_55[7]; /* board 5: queue spacing ([1..6]) */
extern Ovl55Item D_8010C3CC_36B2BC_name_55[6]; /* board 5: the queue's items */
extern void* D_8010C4C8_36B3B8_name_55[6];
extern s32 D_8010C4E0_36B3D0_name_55[];

/* ---- overlay bss (ovl_55_bss.bss.s) ---- */

extern s16 D_8010C530_36B420_name_55[4]; /* text window size (func_8008DACC) */
/* Walker done flags: [0..3] players, [4] the host (D_8010C548, which retail also names). */
extern s32 D_8010C538_36B428_name_55[5];
extern s32 D_8010C54C_36B43C_name_55; /* board 5: a player walker finished */
extern omObjData* D_8010C550_36B440_name_55[4]; /* ev-C: [0] board 4's bubble object */
extern u16 D_8010C560_36B450_name_55; /* sprite */
extern MBModel* D_8010C564_36B454_name_55; /* the host's walk-in model */
extern omObjData* D_8010C568_36B458_name_55; /* START watcher: work[0] = 1 when skipped */
extern MBModel* D_8010C56C_36B45C_name_55; /* the host */
extern void* D_8010C570_36B460_name_55; /* the explanation sign (ev-C: an Ovl55Banner on boards 3-4) */
extern u16 D_8010C588_36B478_name_55; /* sprite */
extern u16 D_8010C58A_36B47A_name_55; /* GwSystem.current_board_index */

/* ---- 3616F0.c (fork A) ---- */

void func_80102800_3616F0_name_55(void);
void func_80102968_361858_name_55(void);
void func_801029F4_3618E4_name_55(omObjData* obj);
void func_80102AB4_3619A4_name_55(omObjData* obj);
void func_80102AE0_3619D0_name_55(void);
void func_80102B58_361A48_name_55(void);
void func_80102F34_361E24_name_55(void);
void func_8010308C_361F7C_name_55(void);
void func_801036B4_3625A4_name_55(void);
void func_8010390C_3627FC_name_55(void);
void func_80103D08_362BF8_name_55(void);
void func_80103D94_362C84_name_55(void);
void func_80104B1C_363A0C_name_55(void);
void func_80105074_363F64_name_55(void);
void func_80105284_364174_name_55(void);
void func_80105328_364218_name_55(s32 a, s32 b);
void func_801053B0_3642A0_name_55(void);
void func_801054B4_3643A4_name_55(omObjData* obj);
s32 func_801055A4_364494_name_55(MBModel* model, s16 motion, s16 shiftAttr, u8 count);

/* ---- 364580.c (fork B) ---- */

void func_80105690_364580_name_55(void);
void func_801057E0_3646D0_name_55(s16 player);
void func_80105870_364760_name_55(void);
void func_801059D0_3648C0_name_55(void);
void func_80105CE0_364BD0_name_55(void);
void func_80105FC4_364EB4_name_55(void);
f32 func_8010633C_36522C_name_55(s16 arg0, f32 arg1, s16 arg2, s32 arg3);
void func_80106508_3653F8_name_55(omObjData* obj);

/* ---- 365650.c (fork B) ---- */

void func_80106760_365650_name_55(void);
void func_801068B0_3657A0_name_55(s16 player);
void func_80106940_365830_name_55(void);
void func_80106AA0_365990_name_55(void);
void func_80106F44_365E34_name_55(void);
void func_801071E0_3660D0_name_55(void* arg0, f32 arg1);
void func_80107330_366220_name_55(void);
omObjData* func_80107630_366520_name_55(Vec* pos, f32 arg1, f32 arg2, s16 arg3);
void func_80107744_366634_name_55(omObjData* obj);
void func_80107850_366740_name_55(void);
void func_801079A0_366890_name_55(s16 player);
void func_80107A30_366920_name_55(void);
void func_80107B90_366A80_name_55(void);
void func_80107ED0_366DC0_name_55(void);
void func_80108238_367128_name_55(void);
void func_801084B4_3673A4_name_55(omObjData* obj);

/* ---- 367540.c (fork C) ---- */

void func_80108650_367540_name_55(void);
void func_801087A0_367690_name_55(s32 player);
void func_80108830_367720_name_55(void);
void func_80108990_367880_name_55(void);
void func_80108DB0_367CA0_name_55(void);
void func_8010912C_36801C_name_55(void);
void func_801091B4_3680A4_name_55(void);
void func_80109380_368270_name_55(void);
void func_801094D0_3683C0_name_55(s32 player);
void func_80109560_368450_name_55(void);
void func_801096C0_3685B0_name_55(void);
void func_80109C58_368B48_name_55(void);
omObjData* func_80109F30_368E20_name_55(void);
void func_8010A064_368F54_name_55(omObjData* obj);
void func_8010A2E0_3691D0_name_55(void);

/* ---- 3693E0.c (fork C) ---- */

void func_8010A4F0_3693E0_name_55(void);
void func_8010A614_369504_name_55(s32 player);
void func_8010A6A4_369594_name_55(void);
void func_8010A804_3696F4_name_55(void);
void func_8010AE68_369D58_name_55(void);
void func_8010B3B4_36A2A4_name_55(void);
void func_8010B444_36A334_name_55(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8010B518_36A408_name_55(omObjData* obj);
void func_8010B5C0_36A4B0_name_55(void);
void func_8010B6C0_36A5B0_name_55(s16 player);

#endif
