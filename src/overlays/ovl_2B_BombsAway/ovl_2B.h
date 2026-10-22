#ifndef _OVL_2B_H
#define _OVL_2B_H

/* Overlay 2B: Bombs Away, MP1's ovl_22_BombsAway (1AA2A0.c, 1AF980.c, 1B02A0.c) ported to MP2's
   main API. Retail is two files: 218BF0.c (game, players, platform; MP1 1AA2A0.c) and 21EA10.c
   from 80108620 (model helpers, camera, cannon, bombs, water; MP1 1AF980.c + 1B02A0.c).
   .data stays asm (223080); .rodata is carved per file. Up to 4 players stand on a tilting
   platform at sea; a cannon fires bombs whose landing marks show first; a bomb's blast throws
   or stuns the players near it, and the platform tilts under them. Last standing wins.

   Types from the asm's accesses; MP1 names and offsets in the comments. Records with pointers
   are reached through their fields only (never a literal stride): the host strides pointers 8. */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/pad.h"

typedef f32 Matrix4f[4][4];

/* ---- main-segment API used by 2B (missing from include/) ---- */

omObjData* omAddObj(s16, u16, u16, s16, void*);
void omSetTra(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void* DataRead(s32 dirAndFile);
void DataClose(void* data);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s32);
void func_80018E30_19A30(s32);
s32 func_80018E78_19A78(void);
void func_80079E60_7AA60(void);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_800B37C0_B43C0(Matrix4f m); /* identity */
u16 func_80018A30_19630(s32, s32); /* model load */
void func_8000C018_CC18(u16);
void func_8007273C_7333C(u8* arg0, u8 arg1);
s16 SprAnimRead(void*);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
u16 func_80078EA8_79AA8(void);
void func_80079614_7A214(s32);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_8006D4D0_6E0D0(s16);           /* the seconds counter */
void func_8006D518_6E118(void);
omObjData* func_800732B0_73EB0(u32 arg0);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 sqrtf(f32);

u8 rand8(void);
u16 func_80018FF0_19BF0(omObjData* obj); /* current motion */
s32 func_80019B70_1A770(omObjData* obj, u8 motion); /* retail masks the argument (definition: u16) */
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void func_800283DC_28FDC(s16 arg0);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
void PlayMusic(s16);
void func_800794A8_7A0A8(s32);
s32 func_8008F618_90218(void);
void func_80079464_7A064(void);

void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800298A4_2A4A4(s16, s32, s32);

void func_8000C460_D060(void);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z); /* MP1 func_8009EA40 */
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4); /* MP1 func_80009340 */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* MP1 func_8001874C */
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);

/* Per-character data, 0x18 bytes each (as 2C's TipsyCharData). */
typedef struct BaCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* motion file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0xC];
} BaCharData;
extern BaCharData D_800CD438_CE038[];

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s16 D_800FC9BE_FD5BE[4]; /* stick x as s16 (MP1 D_800F2CE2) */
extern s16 D_800FD468_FE068[4]; /* stick y as s16 (MP1 D_800F33CC) */

extern HmfModel* D_800FC834_FD434;
extern omObjData* D_800FFFD8_100BD8[];
extern s32 D_800F9D30_FA930[];
extern u16 D_800FA606_FB206;
extern u16 D_800FC87A_FD47A;
extern u16 D_800F8FE0_F9BE0;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern omObjData* D_800FC7B0_FD3B0[];
extern Vec D_8010274C_10334C; /* Center */
extern Vec D_800FD474_FE074;  /* CRot */
extern f32 D_800FA610_FB210;  /* CZoom */
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;

/* A 16-bit random number from two rand8() calls (the first is the high byte). */
#define BA_RAND16() ((rand8() << 8) | rand8())

/* ---- structs ---- */

/* D_8010D940: the game state (MP1 BaGame). */
typedef struct BaGame {
    /* 0x00 */ s16 unk_00; /* state: 0 intro, 1 play, 2 finish, 3 results */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* frames in the state (wraps below 0x7800) */
    /* 0x06 */ s16 unk_06; /* time left in frames (900 at start) */
} BaGame; /* size = 0x8 */

/* D_8010D950[4]: one per player, 0x70 each (MP1 BaPlayer, same layout). unk_48 is a pointer, so
   the host record is larger: index the array, never step 0x70. Flags unk_00: 1 set up,
   2 fallen off / hit, 0x10 ?, 0x80 first frame done. States unk_02: 3 stunned, 5 falling,
   7 out, 9 hit by a blast. */
typedef struct BaPlayer {
    /* 0x00 */ u16 unk_00; /* flags */
    /* 0x02 */ s16 unk_02; /* state */
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 unk_05; /* 1: scripted (func_801055FC), 0: player/CPU control (func_80104CD0) */
    /* 0x06 */ u8 unk_06; /* player index */
    /* 0x07 */ char unk_07;
    /* 0x08 */ f32 unk_08; /* radius (50.0) */
    /* 0x0C */ f32 unk_0C; /* velocity x */
    /* 0x10 */ f32 unk_10; /* velocity y */
    /* 0x14 */ f32 unk_14; /* velocity z */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[0xC];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s16 unk_34; /* toggles 0/1: which of unk_36/unk_38 takes the next motion */
    /* 0x36 */ s16 unk_36; /* motion kept */
    /* 0x38 */ s16 unk_38; /* motion kept */
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C; /* frames in the state */
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ s16 unk_44; /* 12 at setup (MP1 0x42) */
    /* 0x46 */ s16 unk_46; /* -1 at setup (MP1 0x44) */
    /* 0x48 */ omObjData* unk_48; /* the player's object */
    /* 0x4C */ f32 unk_4C; /* CPU stick angle */
    /* 0x50 */ f32 unk_50; /* CPU stick magnitude */
    /* 0x54 */ s16 unk_54; /* CPU: press A this frame */
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58; /* CPU target x */
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60; /* CPU target z */
    /* 0x64 */ char unk_64[4];
    /* 0x68 */ s16 unk_68; /* corner slot (1..5, D_8010DCBE) */
    /* 0x6A */ s16 unk_6A;
    /* 0x6C */ char unk_6C[4];
} BaPlayer; /* size = 0x70 (N64) */

/* D_8010DB28: the tilting platform, 0x194 bytes (MP1 BaStage). Splat labels inside are its
   fields: D_8010DB44 (+0x1C), D_8010DB54 (+0x2C), D_8010DB58/5C (+0x30/34), D_8010DB60/64/68
   (+0x38 pos), D_8010DB6C (+0x44 rot), D_8010DBB8 (+0x90), D_8010DC38..44 (+0x110 plane),
   D_8010DC58 (+0x130). No pointers. */
typedef struct BaWeight {
    /* 0x00 */ f32 unk_00; /* x */
    /* 0x04 */ f32 unk_04; /* weight */
    /* 0x08 */ f32 unk_08; /* z */
} BaWeight;

typedef struct BaStage {
    /* 0x000 */ f32 unk_00; /* bob angle */
    /* 0x004 */ f32 unk_04; /* wobble angle */
    /* 0x008 */ f32 unk_08; /* wobble angle */
    /* 0x00C */ f32 unk_0C; /* tilt direction (degrees) */
    /* 0x010 */ f32 unk_10; /* tilt amount (0..1) */
    /* 0x014 */ f32 unk_14; /* hit direction */
    /* 0x018 */ f32 unk_18; /* hit wobble angle */
    /* 0x01C */ f32 unk_1C; /* hit strength */
    /* 0x020 */ f32 unk_20; /* hit sign (+1/-1) */
    /* 0x024 */ char unk_24[4];
    /* 0x028 */ f32 unk_28; /* shake */
    /* 0x02C */ s16 unk_2C; /* hit frames */
    /* 0x02E */ char unk_2E[2];
    /* 0x030 */ f32 unk_30; /* surface height */
    /* 0x034 */ f32 unk_34; /* slide factor */
    /* 0x038 */ Vec unk_38; /* position (= the stage object's trans) */
    /* 0x044 */ Vec unk_44; /* rotation */
    /* 0x050 */ Matrix4f unk_50; /* platform matrix */
    /* 0x090 */ Matrix4f unk_90; /* its inverse */
    /* 0x0D0 */ Matrix4f unk_D0; /* last frame's inverse */
    /* 0x110 */ f32 unk_110[4]; /* surface plane a, b, c, d */
    /* 0x120 */ f32 unk_120; /* 1 / |normal| */
    /* 0x124 */ Vec unk_124; /* unit normal */
    /* 0x130 */ s32 unk_130; /* weights this frame */
    /* 0x134 */ BaWeight unk_134[8];
} BaStage; /* size = 0x194 */

/* D_8010DCE0: bomb-carrier slots (MP1 BaSlots). unk_00[i]: NULL free, (omObjData*)1 taken, else
   the player waiting; unk_10[i] (splat's D_8010DCF0): the player holding it. */
typedef struct BaSlots {
    /* 0x00 */ omObjData* unk_00[4];
    /* 0x10 */ omObjData* unk_10[4];
} BaSlots; /* size = 0x20 (N64) */

/* D_8010DD00[8]: blasts (func_80103FC4 adds, func_80103BD4 ages and tests). MP1 BaShock plus
   unk_14. */
typedef struct BaShock {
    /* 0x00 */ s16 unk_00; /* frames left, 0 = free */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* y */
    /* 0x0C */ f32 unk_0C; /* z */
    /* 0x10 */ f32 unk_10; /* radius */
    /* 0x14 */ s16 unk_14; /* 0 sphere, else a column (radius capped at 150, height from func_80103F10) */
    /* 0x16 */ char unk_16[2];
} BaShock; /* size = 0x18 (MP1 0x14) */

/* D_8010DDC0[12]: stun sparkles, three per player (func_801082EC; sprite group D_8010DF1C). */
typedef struct BaSparkle {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02; /* phase */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
} BaSparkle; /* size = 0x14 */

/* D_8010DEB8[8]: bomb landing marks (func_80103508). */
typedef struct BaMark {
    /* 0x00 */ s16 unk_00; /* age, 0 = free */
    /* 0x02 */ s16 unk_02; /* frames to impact */
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* z */
} BaMark; /* size = 0xC */

/* .data: a firing pattern (new in MP2; D_8010CCA0 .. D_8010CEF8, listed by D_8010CF5C). A phase
   lasts unk_08 frames; shot j fires at frame unk_0C[j] (unk_5C shots); unk_60 is the next shot.
   Kind unk_00 picks the bomb (D_8010CF84 scale, D_8010CF94 mark time) and the aim. No pointers. */
typedef struct BaPattern {
    /* 0x00 */ s32 unk_00; /* bomb kind 1..3 */
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08; /* phase length in frames */
    /* 0x0C */ s32 unk_0C[20]; /* shot frames, rising */
    /* 0x5C */ s32 unk_5C; /* shots */
    /* 0x60 */ s32 unk_60; /* next shot */
} BaPattern; /* size = 0x64 */

/* .data D_8010CF94[4]: per bomb kind. */
typedef struct BaKindInfo {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02; /* mark frames to impact */
} BaKindInfo;

/* bss D_8010DF38[4]: per player (new in MP2). */
typedef struct BaResult {
    /* 0x00 */ u32 unk_00; /* func_800732B0_73EB0's argument */
    /* 0x04 */ char unk_04[0xC];
} BaResult; /* size = 0x10 */

/* A player's work (obj->unk_50): main's MgWork (MP2 layout, as 2C's TipsyWork); no pointers
   below 0x60. */
typedef struct BaPlayerWork {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ char unk_52[5];
    /* 0x57 */ s8 unk_57; /* controller port */
    /* 0x58 */ char unk_58;
    /* 0x59 */ s8 unk_59; /* player index */
    /* 0x5A */ char unk_5A[2];
    /* 0x5C */ s32 unk_5C;
} BaPlayerWork;

/* The ground object's work (D_800FC7B0_FD3B0[0]->unk_50, func_801060C8). No pointers. */
typedef struct BaGroundWork {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ f32 unk_14; /* ground height under the player being moved (MP1 0x10) */
} BaGroundWork;

/* ---- overlay .data (223080) ---- */

extern s16 D_8010CC90_223080_BombsAway[4]; /* players out, in order (func_80102DDC) */
extern s32 D_8010CC98_223088_BombsAway;    /* skip fade-out countdown; read as s16 (+2) */
extern s32 D_8010CC9C_22308C_BombsAway;    /* finish sub-state / results timer */
extern BaPattern D_8010CCA0_223090_BombsAway; /* random patterns (func_8010392C) */
extern BaPattern D_8010CD04_2230F4_BombsAway;
extern s32 D_8010CCAC_22309C_BombsAway; /* splat label = D_8010CCA0.unk_0C[0] */
extern s32 D_8010CD10_223100_BombsAway; /* splat label = D_8010CD04.unk_0C[0] */
extern BaPattern* D_8010CF5C_22334C_BombsAway[10]; /* per phase; [0] NULL */
extern f32 D_8010CF84_223374_BombsAway[4];          /* bomb scale per kind */
extern BaKindInfo D_8010CF94_223384_BombsAway[4];
extern f32 D_8010CFA4_223394_BombsAway[][2]; /* CPU target offsets (x, z) per corner slot (MP1 D_800FFA7C); asm also reads D_8010CFA8 = [0][1] */
extern u8 D_8010CFD4_2233C4_BombsAway[][2]; /* MP1 D_800FFAAC; asm reads D_8010CFD5 = [0][1] */
extern s32 D_8010CFF0_2233E0_BombsAway; /* intro camera state (func_80109264) */
extern s32 D_8010CFF4_2233E4_BombsAway; /* intro frames */
extern Vec D_8010CFF8_2233E8_BombsAway[2]; /* intro shots ([1] = D_8010D004) */
extern s32 D_8010D004_2233F4_BombsAway[];
extern Vec D_8010D010_223400_BombsAway[4]; /* cannon: intro start, play pos; [2], [3] their rotations */
extern s32 D_8010D01C_22340C_BombsAway[];
extern s16 D_8010D040_223430_BombsAway; /* title sprite y */
extern s32 D_8010D044_223434_BombsAway[];
extern s32 D_8010D1F8_2235E8_BombsAway[];
extern s32 D_8010D238_223628_BombsAway[];
extern u16 D_8010D248_223638_BombsAway;
extern s32 D_8010D24C_22363C_BombsAway;
extern s32 D_8010D250_223640_BombsAway;
extern s32 D_8010D254_223644_BombsAway; /* random seed (MP1 D_800FFB2C) */
extern u16 D_8010D258_223648_BombsAway;
extern f32 D_8010D25C_22364C_BombsAway[];
extern f32 D_8010D26C_22365C_BombsAway[];
extern s16 D_8010D27E_22366E_BombsAway;
extern f32 D_8010D28C_22367C_BombsAway[];
extern s16 D_8010D29C_22368C_BombsAway;
extern s32 D_8010D2A4_223694_BombsAway;

/* ---- overlay .bss (ovl_2B_bss, 0x8010D940..0x8010E650); MP1 address + 0xD800 up to the blasts,
   + 0xD820 after them, + 0xD860 from D_8010DF80 ---- */

extern BaGame D_8010D940_223D30_BombsAway;
extern s16 D_8010D948_223D38_BombsAway; /* _CheckFlag(0xC) != 0 */
extern s16 D_8010D94A_223D3A_BombsAway;
extern BaPlayer D_8010D950_223D40_BombsAway[4];
extern s32 D_8010DB10_223F00_BombsAway; /* players set up */
extern s32 D_8010DB14_223F04_BombsAway; /* players left */
extern s32 D_8010DB18_223F08_BombsAway; /* frame in the firing phase */
extern s32 D_8010DB1C_223F0C_BombsAway; /* firing phase (D_8010CF5C index) */
extern s32 D_8010DB20_223F10_BombsAway;
extern s16 D_8010DB24_223F14_BombsAway; /* model */
extern BaStage D_8010DB28_223F18_BombsAway;
/* Splat labels inside D_8010DB28 that retail addresses with their own lui/%lo (no shared base
   register): the same address as the field. */
extern s32 D_8010DC58_224048_BombsAway; /* = D_8010DB28.unk_130 */
extern s16 D_8010DCBC_2240AC_BombsAway;
extern s16 D_8010DCBE_2240AE_BombsAway[6]; /* corner slots, bits 1/2 */
extern s16 D_8010DCD0_2240C0_BombsAway[8]; /* models (func_80107918) */
extern BaSlots D_8010DCE0_2240D0_BombsAway;
extern BaShock D_8010DD00_2240F0_BombsAway[8];
extern BaSparkle D_8010DDC0_2241B0_BombsAway[12];
extern s16 D_8010DEB0_2242A0_BombsAway;
extern s16 D_8010DEB2_2242A2_BombsAway;
extern s16 D_8010DEB4_2242A4_BombsAway;
extern BaMark D_8010DEB8_2242A8_BombsAway[8];
extern s16 D_8010DF18_224308_BombsAway; /* newest mark, -1 none */
extern s16 D_8010DF1A_22430A_BombsAway; /* sparkle animation */
extern s16 D_8010DF1C_22430C_BombsAway; /* sprite group (SprCreate(12, 0)) */
extern s16 D_8010DF20_224310_BombsAway[9]; /* [3..5] = D_8010DF26: shared player models */
extern BaResult D_8010DF38_224328_BombsAway[4];
extern Matrix4f D_8010DF80_224370_BombsAway; /* camera look-at (MP1 D_80100720) */
extern f32 D_8010DFC0_2243B0_BombsAway;
extern f32 D_8010DFD0_2243C0_BombsAway;
extern s16 D_8010DFD4_2243C4_BombsAway;
extern s16 D_8010DFD8_2243C8_BombsAway;
extern s16 D_8010DFDC_2243CC_BombsAway;
extern s16 D_8010DFDE_2243CE_BombsAway;
extern u8 D_8010DFE0_2243D0_BombsAway;
extern u16 D_8010DFE2_2243D2_BombsAway;
extern u16 D_8010DFE4_2243D4_BombsAway;
extern s16 D_8010DFE6_2243D6_BombsAway;
extern s16 D_8010DFE8_2243D8_BombsAway;
extern struct BaCannon D_8010DFF0_2243E0_BombsAway; /* the cannon (MP1 D_80100790) */
extern s32 D_8010E004_2243F4_BombsAway[];
extern s32 D_8010E008_2243F8_BombsAway[];
extern s32 D_8010E010_224400_BombsAway[];
extern s32 D_8010E068_224458_BombsAway[];
extern s32 D_8010E070_224460_BombsAway[];
extern s32 D_8010E098_224488_BombsAway[];
extern s32 D_8010E0A4_224494_BombsAway[];
extern s16 D_8010E398_224788_BombsAway[]; /* effects (MP1 BaEffect D_80100990)? */
extern s32 D_8010E518_224908_BombsAway[];
extern s32 D_8010E51A_22490A_BombsAway[];
extern s16 D_8010E520_224910_BombsAway;
extern s32 D_8010E524_224914_BombsAway;
extern s32 D_8010E528_224918_BombsAway[];
extern s16 D_8010E530_224920_BombsAway;
extern s16 D_8010E532_224922_BombsAway;
extern s16 D_8010E534_224924_BombsAway;
extern s32 D_8010E538_224928_BombsAway[];
extern s16 D_8010E550_224940_BombsAway; /* 1 while bombs may fall (cleared at the finish) */
extern s32 D_8010E558_224948_BombsAway[];

/* ---- functions: 218BF0.c ---- */

void func_80102800_218BF0_BombsAway(void);
void func_80102D54_219144_BombsAway(void);
void func_80102DB4_2191A4_BombsAway(omObjData* obj);
void func_80102DDC_2191CC_BombsAway(omObjData* obj);
void func_801034B0_2198A0_BombsAway(omObjData* obj);
void func_801034E4_2198D4_BombsAway(void);
void func_80103508_2198F8_BombsAway(void);
void func_8010392C_219D1C_BombsAway(void);
void func_80103AC8_219EB8_BombsAway(BaPattern** list, s32 lo, s32 hi);
void func_80103BD4_219FC4_BombsAway(void);
f32 func_80103F10_21A300_BombsAway(f32 r, f32 h, f32 d);
void func_80103FC4_21A3B4_BombsAway(s16 time, f32 x, f32 y, f32 z, f32 radius, u16 column);
BaPlayer* func_80104058_21A448_BombsAway(omObjData* obj);
void func_801040A0_21A490_BombsAway(omObjData* obj, s32 motion);
void func_80104198_21A588_BombsAway(omObjData* obj, s32 m1, s32 m2);
void func_80104284_21A674_BombsAway(void);
void func_801043A8_21A798_BombsAway(omObjData* obj);
void func_801043C4_21A7B4_BombsAway(omObjData* obj);
void func_801043E0_21A7D0_BombsAway(omObjData* obj);
void func_801043FC_21A7EC_BombsAway(omObjData* obj);
void func_80104418_21A808_BombsAway(omObjData* obj);
void func_8010488C_21AC7C_BombsAway(omObjData* obj, s16 player);
void func_80104CD0_21B0C0_BombsAway(omObjData* obj);
void func_801055FC_21B9EC_BombsAway(omObjData* obj);
void func_801060C8_21C4B8_BombsAway(omObjData* obj);
void func_80106228_21C618_BombsAway(omObjData* obj);
f32 func_80106D78_21D168_BombsAway(Vec* pos);
f32 func_80106DB0_21D1A0_BombsAway(Vec* pos);
s32 func_80106E10_21D200_BombsAway(Vec* a, Vec* b);
s32 func_80106ED4_21D2C4_BombsAway(Vec* pos);
s32 func_80106F60_21D350_BombsAway(Vec* pos);
s32 func_80106FC8_21D3B8_BombsAway(Vec* pos);
s32 func_80107060_21D450_BombsAway(Vec* pos, Vec* out);
s32 func_8010714C_21D53C_BombsAway(Vec* a, Vec* b, Vec* c, s16 arg3);
s32 func_801074D8_21D8C8_BombsAway(Vec* a, Vec* b, Vec* c);
void func_8010770C_21DAFC_BombsAway(f32 x, f32 z, f32 weight);
void func_80107758_21DB48_BombsAway(f32 x, f32 z, f32 weight);
void func_80107918_21DD08_BombsAway(void);
void func_80107A34_21DE24_BombsAway(omObjData* obj);
s16 func_80107A84_21DE74_BombsAway(void);
void func_80107B00_21DEF0_BombsAway(s16 slot);
void func_80107B28_21DF18_BombsAway(omObjData* obj);
void func_80107B44_21DF34_BombsAway(omObjData* obj);
void func_80107B60_21DF50_BombsAway(omObjData* obj, u8 arg1);
void func_80107C48_21E038_BombsAway(omObjData* obj);
void func_801082EC_21E6DC_BombsAway(void);

/* ---- functions: 21EA10.c (inferred from MP1 and the asm; fork C checks them) ---- */

s16 func_80108620_21EA10_BombsAway(HmfData* model, const char* name);
HmfMotionObj* func_801086A0_21EA90_BombsAway(HmfData* model, s16 index, s32 arg2);
HmfMotionObj* func_80108794_21EB84_BombsAway(s16 model, const char* name);
Vec* func_80108810_21EC00_BombsAway(s16 model, const char* name);
Vec* func_8010883C_21EC2C_BombsAway(s16 model, const char* name);
void func_80108868_21EC58_BombsAway(s16 model, s16 src, s16 motion, f32 t);
void func_801088FC_21ECEC_BombsAway(Matrix4f m, f32 x, f32 y, f32 z, f32* out);
void func_80108998_21ED88_BombsAway(Vec* v);
f32 func_80108A4C_21EE3C_BombsAway(f32 x, f32 z);
void func_80108ACC_21EEBC_BombsAway(Vec* dir, f32* angles);
void func_80108B54_21EF44_BombsAway(Matrix4f m, Vec* v);
void func_80108CFC_21F0EC_BombsAway(s16 arg0);
void func_80108DE0_21F1D0_BombsAway(Vec* a, Vec* b);
void func_80108E98_21F288_BombsAway(s16 model, Vec* v);
void func_80108F40_21F330_BombsAway(void);
void func_80109118_21F508_BombsAway(omObjData* obj);
void func_80109128_21F518_BombsAway(void);
void func_80109164_21F554_BombsAway(void);
void func_80109180_21F570_BombsAway(void);
void func_801091F4_21F5E4_BombsAway(void);
void func_80109264_21F654_BombsAway(omObjData* obj);
void func_80109810_21FC00_BombsAway(void);
void func_80109908_21FCF8_BombsAway(void);
void func_801099C4_21FDB4_BombsAway(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_80109A68_21FE58_BombsAway(void);
void func_8010A0D0_2204C0_BombsAway(s32 arg0, s32* arg1, s32 arg2);
void func_8010A198_220588_BombsAway(f32 x, f32 y, f32 z, f32 scale);
void func_8010A1EC_2205DC_BombsAway(void);
void func_8010A298_220688_BombsAway(void);
void func_8010A350_220740_BombsAway(f32 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8010A4BC_2208AC_BombsAway(void);
void func_8010A4CC_2208BC_BombsAway(void);
void func_8010AA9C_220E8C_BombsAway(omObjData* obj);
void func_8010AB08_220EF8_BombsAway(omObjData* obj);
void func_8010AC2C_22101C_BombsAway(void);
void func_8010AC60_221050_BombsAway(void);
void func_8010AD18_221108_BombsAway(void);
s16 func_8010ADF8_2211E8_BombsAway(s16 kind, f32 x, f32 y, f32 z, f32 arg4, s16 arg5, f32 arg6);
u16 func_8010B1AC_22159C_BombsAway(u32 range);
void func_8010B214_221604_BombsAway(omObjData* obj);
void func_8010B3B8_2217A8_BombsAway(omObjData* obj);
s32 func_8010B6FC_221AEC_BombsAway(f32 x, f32 z, f32 scale, u16 kind);
void func_8010B7BC_221BAC_BombsAway(s32 arg0, f32 x, f32 y, f32 z, u16 arg4);
void func_8010BD44_222134_BombsAway(u16 arg0, u16 arg1);
void func_8010BE7C_22226C_BombsAway(void);
void func_8010BFAC_22239C_BombsAway(void);
void func_8010C444_222834_BombsAway(s16 arg0);
void func_8010C8A0_222C90_BombsAway(s16 arg0, s32 arg1, s16* arg2);
void func_8010CBF0_222FE0_BombsAway(s16* arg0, u16 arg1);

/* MG2B-C */
/* main API 21EA10.c uses (missing from include/) */
#include "game/camera.h"
s32 func_800B0FD0_B1BD0(void*, void*); /* strcmp */
f32 func_800B75A8_B81A8(f32, f32);     /* atan2 (degrees) */
void func_800B1960_B2560(Matrix4f m, f32 px, f32 py, f32 pz, f32 ax, f32 ay, f32 az, f32 ux, f32 uy,
                         f32 uz); /* look-at (MP1 HuGuLookAtF) */
void func_8002A15C_2AD5C(s16 model, s16 motion, f32 t);
void func_800798F8_7A4F8(s16 sound, s16 pan); /* MP1 func_800607C4 */

void SprPosSet(s16, s16, s16, s16);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void omSetStatBit(omObjData* obj, u16 stat);

/* D_8010DFF0: the cannon (MP1 BaCannon). Splat labels: D_8010DFF8 (+8), D_8010E004 (+0x14),
   D_8010E008 (+0x18). */
typedef struct BaCannon {
    /* 0x00 */ Vec unk_00; /* position */
    /* 0x0C */ Vec unk_0C; /* rotation */
    /* 0x18 */ f32 unk_18; /* velocity x */
    /* 0x1C */ char unk_1C[4];
} BaCannon;

#endif
