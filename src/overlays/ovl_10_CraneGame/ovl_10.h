#ifndef _OVL_10_H
#define _OVL_10_H

/* Overlay 10: Crane Game, descended from MP1's ovl_23_CraneGame (1B3E00.c game, 1B9050.c shadows,
   1BAA60.c collision and camera). Retail is two files: 14C320.c (game, claw, prizes, shadows) and
   153590.c from 80109A70 (collision meshes, MP1 1BAA60.c). .data stays asm (155280); .rodata is
   carved per file. Types from the asm's accesses; MP1 names and offsets in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"

typedef f32 Matrix4f[4][4];

/* ---- main-segment API used by 10 (missing from include/) ---- */

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s32);
void func_80018E30_19A30(s32);
s32 func_80018E78_19A78(void);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
u8 rand8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_80079614_7A214(s32);
extern u16 D_801011FC_101DFC;
void SprAnimKill(s16 animIdx);
void SprKill(s16);
void func_8006D4D0_6E0D0(s16); /* the seconds counter (MP1 func_80079078) */
void func_8006D518_6E118(void);
f32 sqrtf(f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
extern u8 D_800FDBE0_FE7E0; /* the frame's buffer index */
extern u8 D_800FDBCA_FE7CA; /* frame buffers */
u16 func_80018A30_19630(s32, s32); /* model load */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_8002A00C_2AC0C(s16 model);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
s32 func_8002838C_28F8C(s32, void*, s32);
void* HuMemAlloc(s32 size);
void HuMemFree(void*);

extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern s32 D_800F9D30_FA930[];
extern u16 D_800FA606_FB206;
extern u16 D_800FC87A_FD47A;
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FC7B0_FD3B0[];
extern omObjData* D_800F9CE0_FA8E0[]; /* MP1 D_800EDE70: the prize objects */
extern Vec D_8010274C_10334C; /* Center */
extern Vec D_800FD474_FE074;  /* CRot */
extern f32 D_800FA610_FB210;  /* CZoom */

/* ---- structs ---- */

/* A hanging prize model of the backdrop (D_8010B764_155284, func_80103974). */
typedef struct CGHang {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 scale;
} CGHang; /* size = 0xC */

/* Per hanging model state (func_80103974). */
typedef struct CGPair {
    /* 0x00 */ f32 a;
    /* 0x04 */ f32 b;
} CGPair;

/* ---- overlay data (155280.data.s, asm) ---- */

extern s32 D_8010B760_155280_CraneGame; /* the hurry-up music started */
extern CGHang D_8010B764_155284_CraneGame[7];
extern s32 D_8010B7B8_1552D8_CraneGame[7]; /* their model files */

/* ---- overlay bss (ovl_10_bss, 8010C170) ---- */

extern omObjData* D_8010C170_155C90_CraneGame;
extern s16 D_8010C174_155C94_CraneGame; /* game state (MP1 D_800FFE24) */
extern s16 D_8010C176_155C96_CraneGame;
extern s16 D_8010C178_155C98_CraneGame; /* 1: timer stopped (MP1 D_800FFE28) */
extern s16 D_8010C17A_155C9A_CraneGame; /* game over (MP1 D_800FFE2C) */
extern s16 D_8010C17C_155C9C_CraneGame; /* time left in frames (MP1 D_800FFE2E) */
extern s16 D_8010C17E_155C9E_CraneGame; /* state timer (MP1 D_800FFE30) */
extern s16 D_8010C180_155CA0_CraneGame;
extern s16 D_8010C182_155CA2_CraneGame; /* _CheckFlag(0xC) (MP1 D_800FFE34, flag 0x2B) */
extern s16 D_8010C184_155CA4_CraneGame;
extern s16 D_8010C186_155CA6_CraneGame; /* the crane's model (MP1 D_800FFE70) */
extern s16 D_8010C188_155CA8_CraneGame[6]; /* shuffled prize order (MP1 D_800FFE72) */
extern s16 D_8010C194_155CB4_CraneGame; /* the solo player (MP1 D_800FFE7E) */
extern s16 D_8010C196_155CB6_CraneGame[3]; /* the other players (MP1 D_800FFE80) */
extern s16 D_8010C19C_155CBC_CraneGame;
extern s16 D_8010C19E_155CBE_CraneGame;
extern s16 D_8010C1A0_155CC0_CraneGame;
extern s32 D_8010C1A4_155CC4_CraneGame; /* the shadow model (func_8002838C) */
extern CGPair D_8010C1A8_155CC8_CraneGame[7];
extern f32 D_8010C1E0_155D00_CraneGame[7];
extern CGPair D_8010C200_155D20_CraneGame[7];
extern f32 D_8010C238_155D58_CraneGame[7];
extern f32 D_8010C254_155D74_CraneGame;
extern s16 D_8010C258_155D78_CraneGame;
extern void* D_8010CE30_156950_CraneGame[256]; /* claws (MP1 D_80100BC0) */
extern omObjData* D_8010D230_156D50_CraneGame;
extern s16 D_8010D234_156D54_CraneGame;

/* ---- overlay functions ---- */
/* MG10-A's range (to 80106F00) checked against the asm; MG10-B's inferred from the asm's register
   use and MP1's twins: check yours. */

/* 14C320.c */
void func_80102800_14C320_CraneGame(void);
void func_80102CFC_14C81C_CraneGame(omObjData* obj);
void func_80102D28_14C848_CraneGame(omObjData* obj);
void func_801031B8_14CCD8_CraneGame(void);
void func_801031EC_14CD0C_CraneGame(void);
void func_80103250_14CD70_CraneGame(omObjData* obj);
void func_801032C8_14CDE8_CraneGame(omObjData* obj);
s32 func_80103338_14CE58_CraneGame(omObjData* obj);
s16 func_801033E4_14CF04_CraneGame(f32 arg0);
s16 func_801035C0_14D0E0_CraneGame(f32* x, f32* y, f32* z, f32 dx, f32 dy, f32 dz, f32 r, s16 mode);
void func_801038FC_14D41C_CraneGame(void);
void func_80103974_14D494_CraneGame(omObjData* obj);
void func_80103CB8_14D7D8_CraneGame(omObjData* obj);
void func_80103F38_14DA58_CraneGame(void);
void func_80103FC8_14DAE8_CraneGame(omObjData* obj);
s16 func_8010422C_14DD4C_CraneGame(f32 x, f32 y, f32 z, f32 r);
s16 func_801043D8_14DEF8_CraneGame(f32 x, f32 y, f32 z, s16 arg3);
f32 func_801044E0_14E000_CraneGame(Vec* a, Vec* b);
s32 func_801046E8_14E208_CraneGame(void);
void func_80104854_14E374_CraneGame(omObjData* obj);
void func_80104CB0_14E7D0_CraneGame(omObjData* obj);
s32 func_80106268_14FD88_CraneGame(omObjData* obj, Vec* out);
void func_8010646C_14FF8C_CraneGame(s16 n, Vec* v);
s16 func_80106568_150088_CraneGame(omObjData* obj);
void func_80106A28_150548_CraneGame(omObjData* obj);
f32 func_80106C98_1507B8_CraneGame(f32 x, f32 z);
void func_80106D58_150878_CraneGame(Matrix4f m, Vec* out);
void func_80106F00_150A20_CraneGame(omObjData* obj);
/* MG10-B's range (inferred) */
void func_80107460_150F80_CraneGame(omObjData* obj, s16 arg1);       /* MP1 func_800FA684 */
void func_8010755C_15107C_CraneGame(omObjData* obj);                 /* MP1 func_800FA770 */
void* func_80107DD4_1518F4_CraneGame(omObjData* obj);                /* MP1 func_800F704C (claw alloc) */
void func_80107EC0_1519E0_CraneGame(void);                           /* MP1 func_800F7138 */
void* func_80107F40_151A60_CraneGame(omObjData* obj);                /* MP1 func_800F71B8 (claw get) */
void func_80107F70_151A90_CraneGame(void);                           /* MP1 func_800FB830 */
void func_80108038_151B58_CraneGame(void);                           /* MP1 func_800FB8E8 */
void func_80108114_151C34_CraneGame(s16 model);                      /* MP1 func_800FB9C4 */
void func_801081C8_151CE8_CraneGame(s16 model, f32 arg1);
void func_80108238_151D58_CraneGame(s16 model, f32 arg1);            /* MP1 func_800FBA78 */
void func_801082B8_151DD8_CraneGame(f32 y);                          /* MP1 func_800FBAE8 */
void func_801082D0_151DF0_CraneGame(f32 x, f32 y, f32 z);            /* MP1 func_800FBB00 */
void func_801082E8_151E08_CraneGame(f32 arg0);
void func_801082F4_151E14_CraneGame(Gfx** gfx, Mtx* mtx);            /* MP1 func_800FBB18 */
Gfx* func_8010887C_15239C_CraneGame(Gfx* gfx, void* m, Matrix4f inv); /* MP1 func_800FC0A0 */
void func_80108D18_152838_CraneGame(s16 model);                      /* MP1 func_800FC4F4 */
void func_80109024_152B44_CraneGame(void* g, void* verts, s16 n);    /* MP1 func_800FC800 */
s32 func_801091D4_152CF4_CraneGame(void);                            /* MP1 func_800FC9B0 */
void func_801093A0_152EC0_CraneGame(Gfx** gfx, void* m);             /* MP1 func_800FCB78 */
Gfx* func_801095A4_1530C4_CraneGame(Gfx* gfx, u8 (*tri)[4], s16 n);  /* MP1 func_800FCD7C */
Gfx* func_801097A0_1532C0_CraneGame(Gfx* gfx, Mtx* mtx);             /* MP1 func_800FCF78 */

/* 153590.c (MP1 1BAA60.c) */
void func_80109A70_153590_CraneGame(void);                           /* MP1 func_800FD240 */
void func_80109AA8_1535C8_CraneGame(void);                           /* MP1 func_800FD278 */
void func_80109BAC_1536CC_CraneGame(s16 model);                      /* MP1 func_800FD37C */
void func_80109C00_153720_CraneGame(Gfx** gfx, Mtx* mtx);            /* MP1 func_800FD3D0 */
void func_80109E48_153968_CraneGame(void* col, s16 model);           /* MP1 func_800FD604 */
void func_80109FF8_153B18_CraneGame(void* verts, void* out, u8* f, s16 n); /* MP1 func_800FD7B4 */
void func_8010A43C_153F5C_CraneGame(Matrix4f m, f32 x, f32 y, f32 z, Vec* out); /* MP1 func_800FDBF8 */
s32 func_8010A4D8_153FF8_CraneGame(Vec* pos, f32 dx, f32 dy, f32 dz, s16 skip); /* MP1 func_800FDC94 */
s32 func_8010A798_1542B8_CraneGame(Vec* p, Vec* d, f32 r);           /* MP1 func_800FDF54 */
void func_8010A8E8_154408_CraneGame(void* f, s16 n, Vec* p, Vec* d);   /* MP1 func_800FE0A4 */
void func_8010AD5C_15487C_CraneGame(Matrix4f m, f32 x, f32 y, f32 z, f32* ox, f32* oy, f32* oz, f32* ow);
s32 func_8010AE2C_15494C_CraneGame(f32 a, f32 b, f32 c, f32 d, s32 arg4, s32 arg5);
f32 func_8010B364_154E84_CraneGame(f32 a, f32 b, f32 c, f32 d);

#endif
