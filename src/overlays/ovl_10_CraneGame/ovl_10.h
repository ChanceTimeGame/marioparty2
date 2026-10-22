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

/* gSPLine3D(pkt, 0, 1, 0): the SDK's F3DEX2 __gsSPLine3D_w1 spells _SHIFT for _SHIFTL. */
#define CG_SP_LINE3D_01(pkt)                                                                     \
    {                                                                                            \
        Gfx* _g = (Gfx*)(pkt);                                                                   \
        _g->words.w0 = _SHIFTL(G_LINE3D, 24, 8) | _SHIFTL(0 * 2, 16, 8) | _SHIFTL(1 * 2, 8, 8); \
        _g->words.w1 = 0;                                                                        \
    }

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
void func_800204C0_210C0(s32, Gfx**);
s16 LoadFormFile(s32, s32);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->rot */
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->scale */
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
f32 func_80029D0C_2A90C(s16); /* motion length */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
s32 PlaySound(s32);
void func_80079848_7A448(s16 id); /* stop a sound (MP1 func_8006071C) */
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void func_80079718_7A318(s32, s32); /* character voice */
f64 func_800B0D98_B1998(f64, f64); /* fmod */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80019378_19F78(omObjData* obj); /* MP1 func_80017DB0 */
void func_80025770_26370(Matrix4f m, f32 x, f32 y, f32 z); /* translate (MP1 MtxTranslate) */
void func_80025884_26484(Matrix4f m, f32 x, f32 y, f32 z); /* rotate (MP1 MtxRotate) */

/* Per-character data, 0x18 bytes each (as 2C's TipsyCharData). */
typedef struct CGCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* motion file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk_10[8];
} CGCharData;
extern CGCharData D_800CD438_CE038[];
extern u16 D_800F9564_FA164; /* the model being drawn */

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

/* Work of the prizes (D_800F9CE0_FA8E0, func_80106F00) and of the claw operator (func_80104854):
   main's minigame work (0x15C bytes; MP1's 0xE8 with fields from 0x50 moved). Fields from the asm. */
typedef struct CGWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34; /* half width */
    /* 0x38 */ f32 unk38; /* half depth */
    /* 0x3C */ f32 unk3C; /* move angle, -1 none */
    /* 0x40 */ f32 unk40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ s16 unk50; /* state; < 0 out of play */
    /* 0x52 */ u8 unk52;
    /* 0x53 */ s8 unk53; /* shape: 0 three contact points, 1 four */
    /* 0x54 */ char unk_54[3];
    /* 0x57 */ s8 unk57; /* controller port */
    /* 0x58 */ char unk_58[1];
    /* 0x59 */ s8 unk59; /* player */
    /* 0x5A */ char unk_5A[0x76];
    /* 0xD0 */ u16 unkD0; /* MP1 0xC0 */
    /* 0xD2 */ char unk_D2[0x16];
    /* 0xE8 */ void* unkE8; /* per motion blocks (MP1 0xD8) */
    /* 0xEC */ char unk_EC[0x70];
} CGWork; /* size = 0x15C */

#define CG_WORK(obj) ((CGWork*)(obj)->unk_50)

double fabs(double);
float fabsf(float);

/* The claw block (MP1 CGClaw, HuMemDirectMalloc(0x5C) there; func_80107DD4/80107F40 here), kept in
   D_8010CE30_156950_CraneGame. MP1's layout: MG10-B, check it against 80107DD4. */
typedef struct CGClaw {
    /* 0x00 */ s16 unk0; /* 1 once initialised */
    /* 0x02 */ u16 unk2; /* flags: 1/2 clamped by func_801035C0, 4 empty-handed */
    /* 0x04 */ s16 unk4; /* grab radius */
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8; /* state */
    /* 0x0A */ u16 unkA; /* index in D_8010CE30_156950_CraneGame */
    /* 0x0C */ f32 unkC; /* claw position */
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C; /* lowest height */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char pad30[0xC];
    /* 0x3C */ s16 unk3C; /* timer */
    /* 0x3E */ s16 unk3E; /* frames moving one way */
    /* 0x40 */ s16 unk40; /* grip level */
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44; /* motor sound, -1 none */
    /* 0x46 */ s16 unk46; /* motor volume step */
    /* 0x48 */ s16 unk48; /* cable sound, -1 none */
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C; /* grip frames left */
    /* 0x4E */ s16 unk4E; /* grip frames per level */
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58; /* CPU target (D_800F9CE0_FA8E0 index) */
    /* 0x5A */ s16 unk5A; /* grabbed prize (D_800F9CE0_FA8E0 index), -1 none */
} CGClaw; /* size = 0x5C */

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
extern s16 D_8010B978_155498_CraneGame[]; /* grip strength per grab quality */
extern f32 D_8010B980_1554A0_CraneGame[]; /* claw depth per character */
extern Gfx D_8010B8E8_155408_CraneGame[];
extern f32 D_8010B998_1554B8_CraneGame[3][2]; /* contact points, three-point prizes */
extern f32 D_8010B9B0_1554D0_CraneGame[4][2]; /* contact points, four-point prizes */
extern Gfx D_8010B928_155448_CraneGame[];

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
extern CGClaw* D_8010CE30_156950_CraneGame[256]; /* claws (MP1 D_80100BC0) */
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
void func_80103FC8_14DAE8_CraneGame(Gfx** gfx);
s16 func_8010422C_14DD4C_CraneGame(f32 x, f32 y, f32 z, f32 r);
s16 func_801043D8_14DEF8_CraneGame(f32 x, f32 z, f32 r, s16 i); /* grab quality of prize i */
f32 func_801044E0_14E000_CraneGame(Vec* a, Vec* b); /* highest ground around a */
s16 func_801046E8_14E208_CraneGame(omObjData* obj); /* the CPU's target prize (obj unused) */
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
CGClaw* func_80107DD4_1518F4_CraneGame(omObjData* obj);               /* MP1 func_800F704C (claw alloc) */
void func_80107EC0_1519E0_CraneGame(void);                           /* MP1 func_800F7138 */
CGClaw* func_80107F40_151A60_CraneGame(omObjData* obj);               /* MP1 func_800F71B8 (claw get) */
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
