#ifndef _OVL_3C_H
#define _OVL_3C_H

/* Overlay 3C: Deep Sea Salvage (four players, each diving for itself), descended from MP1's ovl_30_DeepSeaDivers (218510.c, DeepSeaDivers.h) and
   ovl_04_TreasureDivers. A boat at the surface drops treasure (1- and 5-coin pieces, and a
   hazard) down four lanes; each player's diver swims left/right and kicks up with A, picks a
   treasure up by touching it, and is stunned by the hazard. Two fish swim across. Retail is three
   files: 291870.c (game, divers, boat, treasure, HUD), 294F20.c from 80105EB0 (camera, work
   blocks, random numbers, sea-floor collision, effects) and 296550.c from 801074E0 (fish, MP1
   func_800FEA00 onwards). .data stays asm (one blob for all three files); .rodata is carved per
   file ([0x2976D0, .rodata, 291870], [0x2977E0, .rodata, 294F20], [0x297820, .rodata, 296550]). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/collision.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/pad.h"

typedef f32 Matrix4f[4][4];

/* ---- main-segment API used by 3C (missing from include/) ---- */

void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_80079614_7A214(s32);
extern u16 D_801011FC_101DFC;
void func_8006D4D0_6E0D0(s16); /* the seconds counter (MP1 func_80079078) */
void func_8006D518_6E118(void);
f32 HuMathSin(f32);
f32 fabsf(f32);
f64 fabs(f64); /* GCC builtin (abs.d) */
f64 func_800B80D0_B8CD0(f64); /* sin of degrees, in double */
u16 func_80018A30_19630(s32, s32); /* model load */
s16 LoadFormFile(s32, s32);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2); /* a sprite-model slot (D_800F86D8) from a file */
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029FE4_2ABE4(s16, f32); /* model motion speed */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_8002A00C_2AC0C(s16 model);
void func_80023DAC_249AC(s16 model, char* part, s16 target, char* targetPart); /* attach a part */
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void func_80019378_19F78(omObjData* obj);
void func_8003EAF0_3F6F0(char* arg0, void* arg1); /* the size of the texture named arg0 */
u16 func_8001A2F8_1AEF8(s32 arg0); /* s16 in main; retail callers here zero-extend the result */
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprAttrReset(s16 group, s16 member, s32 flag);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprBankSet(s16 group, s16 member, s16 bank); /* u16 bank in main; retail here sign-extends it */
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
u8 func_80082314_82F14(s16 grpIdx, s16 idx); /* sprite animation status; 2: ended */
s16 SprAnimRead(void*);
void func_8002BED4_2CAD4(s16 model, f32 s, f32 t, u16 w, u16 h, char* part, u8 arg6); /* texture scroll */
f64 func_800B0D98_B1998(f64, f64); /* fmod */
extern u8 D_800FDBE0_FE7E0; /* the vertex buffer being drawn */
void* func_80082550_83150(s16 grpIdx, s16 idx); /* the sprite (HuSprite*); unused here */
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPosPerspectiveSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
s16 func_80079798_7A398(s16 sfx, s16 player); /* play a sound effect for a player */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 PlaySound(s32);
extern s8 ContStkX[4];
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */

/* Per-character data, 0x18 bytes each (as 2C's TipsyCharData). */
typedef struct DSSCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* motion file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk_10[8];
} DSSCharData;
extern DSSCharData D_800CD438_CE038[];

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* Retail keeps a pointer in omObjData.work[0..3] (sw at 0x4C) for the divers and the treasure
   object. Host: a pointer does not fit in those four bytes. */
#define DSS_OBJ_WORK(obj) (*(void**)(obj)->work)

/* A diver's state (player objects, 0x2C, DSS_OBJ_WORK). */
typedef struct DSSDiver {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 vx;      /* -8..8 */
    /* 0x10 */ f32 vy;      /* -10..10; A kicks up by 8 */
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 kick;    /* motion speed, 0..2 */
    /* 0x1C */ s16 state;   /* 0, 1 start countdowns; 2+ play */
    /* 0x1E */ s16 kickWait; /* frames since the last kick, from 8 */
    /* 0x20 */ s16 timer;
    /* 0x22 */ s16 idle;    /* counts while not kicking (bubbles every 8th frame) */
    /* 0x24 */ s16 player;
    /* 0x26 */ s16 target;  /* the CPU's treasure, -1 none */
    /* 0x28 */ s16 stun;    /* frames shaking after the hazard */
    /* 0x2A */ s16 blink;   /* frames blinking after the stun */
} DSSDiver; /* size = 0x2C */

/* A treasure (the treasure object's DSS_OBJ_WORK, 20 of them). */
typedef struct DSSTreasure {
    /* 0x00 */ s16 flags;   /* 0 free; < 0 placed; 0x80 lands on the sea floor */
    /* 0x02 */ s16 taken;   /* a diver touched it */
    /* 0x04 */ s16 state;   /* 0 thrown, 1 sinking, 2 collected */
    /* 0x06 */ s16 kind;    /* 0 one coin, 1 five coins, 2 the hazard */
    /* 0x08 */ s16 lane;    /* 0-3 */
    /* 0x0A */ s16 sprite;  /* sprite-model slot */
    /* 0x0C */ f32 tx;      /* target x */
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 z;
    /* 0x1C */ f32 vx;
    /* 0x20 */ f32 vy;
    /* 0x24 */ f32 vz;
    /* 0x28 */ f32 sx;
    /* 0x2C */ f32 sy;
    /* 0x30 */ f32 sz;
    /* 0x34 */ s16 timer;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ f32 floor;   /* the sea floor's height under it */
} DSSTreasure; /* size = 0x3C */

/* A 2D effect (D_80109CE0[64], stride 0x2C; MP1 DSDFx). */
typedef struct DSSFx {
    /* 0x00 */ s16 flags;  /* 0 free, 1 new, | 0x8000 running */
    /* 0x02 */ s16 type;   /* 0 bubble, 1 splash */
    /* 0x04 */ s16 sprite;
    /* 0x06 */ s16 target;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ f32 sx;
    /* 0x18 */ f32 sy;
    /* 0x1C */ s16 timer;
    /* 0x1E */ s16 fade;
    /* 0x20 */ s16 life;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} DSSFx; /* size = 0x2C */

/* An object's extra work (HuMemMemoryAllocPerm(0x5C), D_8010A7F0; MP1 DSDWork 0x60). Its
   pointer is kept big-endian in obj->work[0..3]. */
typedef struct DSSWork {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA; /* index in D_8010A7F0 */
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ s16 unk3E;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
} DSSWork; /* size = 0x5C */

/* A player's score display (D_8010ABF8[4], stride 0xC). */
typedef struct DSSScore {
    /* 0x00 */ u16 coins;  /* the score */
    /* 0x02 */ u16 shown;  /* the number on screen, counting towards coins */
    /* 0x04 */ u16 state;  /* 1: the number pops (angle in unk8) */
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 angle;
} DSSScore; /* size = 0xC */

/* The HUD's sprites (D_80108EC0, 0xE10 bytes cleared; only the group is used). */
typedef struct DSSHud {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ s16 unk2;
    /* 0x004 */ s16 group;
    /* 0x006 */ char unk6[0xE0A];
} DSSHud; /* size = 0xE10 */

/* A 2D point (func_80106518's crossings; MP1 Vec2f with x, y). */
typedef struct DSSPoint {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} DSSPoint; /* size = 0x8 */

/* func_80079E60_7AA60 is MP3 omOutView(omObjData*) (src/7AA60.c); functions.h declares it void,
   and retail calls it with NULL here. */
#define DSS_OUT_VIEW() (((void (*)(omObjData*))func_80079E60_7AA60)(NULL))

/* A model's placement (D_8010842C[2], .data). */
typedef struct DSSPlace {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec scale;
} DSSPlace;

/* A fish (D_801088F8[2], stride 0x40) and its recorded positions (D_80108978[2][10]); MP1
   DSDFish. */
typedef struct DSSFish {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ char pad18[0x18];
    /* 0x30 */ f32 vx; /* speed: 8-12 plus 10 x the scale, signed by direction */
    /* 0x34 */ char pad34[0xC];
} DSSFish; /* size = 0x40 */

/* ---------------------------------------------------------------------------------------------
   .data (asm, 0x297490-0x2976D0: 291870.c to 80108640, then 296550.c)
   --------------------------------------------------------------------------------------------- */

extern s32 D_80108420_297490_DeepSeaSalvage;     /* the music has started */
extern s32 D_80108424_297494_DeepSeaSalvage[2];  /* the backdrop models' files */
extern f32 D_8010842C_29749C_DeepSeaSalvage[2][6]; /* pos x, y, z, scale x, y, z */
extern char* D_8010845C_2974CC_DeepSeaSalvage[6]; /* per character: the diving mask's part */
extern u16 D_80108474_2974E4_DeepSeaSalvage[6];  /* per character: the diver model's file */
extern f32 D_80108480_2974F0_DeepSeaSalvage[4];  /* per diver: start x */
extern s32 D_80108490_297500_DeepSeaSalvage;     /* voice variant 1-2 (read as s16) */
extern s32 D_80108494_297504_DeepSeaSalvage;     /* the boat's bob counter */
extern u8 D_80108498_297508_DeepSeaSalvage[16];  /* a lane's 13 drops: kinds */
extern u8 D_801084A8_297518_DeepSeaSalvage[6][3]; /* drop triples (lane patterns) */
extern f32 D_801084BC_29752C_DeepSeaSalvage[3];  /* per kind: sinking speed limit */
extern f32 D_801084C8_297538_DeepSeaSalvage[3];  /* per kind: scale */
extern u16 D_801084D4_297544_DeepSeaSalvage[16][2]; /* HUD sprite positions (x, y) */
extern s32 D_80108514_297584_DeepSeaSalvage[7];  /* per character: the HUD face file */
extern Vec D_80108530_2975A0_DeepSeaSalvage[10]; /* the sea floor's left outline */
extern Vec D_801085A8_297618_DeepSeaSalvage[11]; /* the right outline */
extern Vec* D_8010862C_29769C_DeepSeaSalvage[2];
extern s16 D_80108634_2976A4_DeepSeaSalvage[6];
/* 296550.c */
extern s32 D_80108640_2976B0_DeepSeaSalvage[3];  /* per fish: swim angle, degrees (0-360); [2] pads */
extern s32 D_8010864C_2976BC_DeepSeaSalvage[5];  /* per fish: speed, chasing vx by 1 a frame; [2..4] pad */

/* .rodata strings the .data names (291870.c) */
extern const char D_80108678_2976E8_DeepSeaSalvage[];
extern const char D_8010868C_2976FC_DeepSeaSalvage[];
extern const char D_8010869C_29770C_DeepSeaSalvage[];
extern const char D_801086AC_29771C_DeepSeaSalvage[];
extern const char D_801086C4_297734_DeepSeaSalvage[];
extern const char D_801086D8_297748_DeepSeaSalvage[];

/* ---------------------------------------------------------------------------------------------
   .bss (0x80108820-0x8010AC30)
   --------------------------------------------------------------------------------------------- */

extern s16 D_80108820_297890_DeepSeaSalvage; /* game state: 0 intro, 2 start, 3 play, 4 result, 5 end, -1 exit */
extern s16 D_80108822_297892_DeepSeaSalvage; /* state timer */
extern s16 D_80108824_297894_DeepSeaSalvage; /* 1: players frozen (before the start, after the end) */
extern s16 D_80108826_297896_DeepSeaSalvage; /* 0 playing, 1 over, -1 leaving */
extern s16 D_80108828_297898_DeepSeaSalvage; /* time left, frames */
extern s16 D_8010882A_29789A_DeepSeaSalvage; /* _CheckFlag(0xC) */
extern s16 D_8010882C_29789C_DeepSeaSalvage; /* divers made so far */
extern s16 D_8010882E_29789E_DeepSeaSalvage;
extern s16 D_80108830_2978A0_DeepSeaSalvage;
extern s16 D_80108832_2978A2_DeepSeaSalvage;
extern omObjData* D_80108834_2978A4_DeepSeaSalvage; /* the timer object */
extern u8 D_80108838_2978A8_DeepSeaSalvage[4][13]; /* per lane: its drops, shuffled */
extern u8 D_80108870_2978E0_DeepSeaSalvage[23];   /* per throw: lane bits */
extern s16 D_80108888_2978F8_DeepSeaSalvage[4];   /* per lane: drops made */
extern s16 D_80108890_297900_DeepSeaSalvage[20];  /* the treasures a CPU may aim at */
extern s16 D_801088B8_297928_DeepSeaSalvage;      /* their count */
extern s16 D_801088BA_29792A_DeepSeaSalvage[2];   /* a treasure is resting on the left / right slope */
extern s16 D_801088BE_29792E_DeepSeaSalvage[4];   /* per player: treasures collected */
extern Vec D_801088C8_297938_DeepSeaSalvage;
extern Vec D_801088D4_297944_DeepSeaSalvage;
extern s16 D_801088E0_297950_DeepSeaSalvage[5];   /* sprite-model slots: coin, 5 coins, hazard, sparkle, shine */
extern DSSFish D_801088F8_297968_DeepSeaSalvage[2];
extern DSSFish D_80108978_2979E8_DeepSeaSalvage[2][10];
extern s16 D_80108E70_297EE0_DeepSeaSalvage;      /* the fish history's write slot, 0-9 */
extern f32 D_80108E74_297EE4_DeepSeaSalvage[2];   /* per fish: scale (0.75-1.05) */
extern f32 D_80108E7C_297EEC_DeepSeaSalvage;      /* the sea surface's wave angle, degrees */
extern u16 D_80108E80_297EF0_DeepSeaSalvage[2];   /* texture "dmy_I8"'s size (func_8003EAF0) */
extern f32 D_80108E84_297EF4_DeepSeaSalvage;      /* the surface texture's scroll */
extern f32 D_80108E88_297EF8_DeepSeaSalvage;
extern s16 D_80108E90_297F00_DeepSeaSalvage;      /* DSSWork blocks made */
extern s16 D_80108E98_297F08_DeepSeaSalvage[5];   /* sprite anims (func_80106F08): [0] splash 0x4C000F, [3] 0x4C000D,
                                                     [4] bubble 0x4C0010 (splat's D_80108EA0); [1], [2] unused */
extern omObjData* D_80108EB8_297F28_DeepSeaSalvage; /* the treasure object */
extern DSSHud D_80108EC0_297F30_DeepSeaSalvage;
extern omObjData* D_80109CD0_298D40_DeepSeaSalvage; /* the boat */
extern DSSFx D_80109CE0_298D50_DeepSeaSalvage[64];
extern omObjData* D_8010A7E0_299850_DeepSeaSalvage; /* the fade-in object */
extern DSSWork* D_8010A7F0_299860_DeepSeaSalvage[256];
extern DSSScore D_8010ABF8_299C68_DeepSeaSalvage[4];

/* ---------------------------------------------------------------------------------------------
   291870.c
   --------------------------------------------------------------------------------------------- */

void func_80102800_291870_DeepSeaSalvage(void);
void func_80102B48_291BB8_DeepSeaSalvage(omObjData* obj);
void func_80102B74_291BE4_DeepSeaSalvage(omObjData* obj);
void func_80102E7C_291EEC_DeepSeaSalvage(void);
void func_80102EC8_291F38_DeepSeaSalvage(omObjData* obj);
void func_80102F3C_291FAC_DeepSeaSalvage(omObjData* obj);
void func_80102FBC_29202C_DeepSeaSalvage(omObjData* obj);
void func_80103164_2921D4_DeepSeaSalvage(omObjData* obj);
void func_80103180_2921F0_DeepSeaSalvage(omObjData* obj);
void func_801031CC_29223C_DeepSeaSalvage(omObjData* obj);
s16 func_80103480_2924F0_DeepSeaSalvage(s16 sfx, u8 player);
void func_80103508_292578_DeepSeaSalvage(omObjData* obj);
void func_80103DCC_292E3C_DeepSeaSalvage(omObjData* obj);
void func_80104070_2930E0_DeepSeaSalvage(omObjData* obj);
void func_801043A4_293414_DeepSeaSalvage(void);
void func_801044A8_293518_DeepSeaSalvage(void);
void func_80104944_2939B4_DeepSeaSalvage(omObjData* obj);
void func_80104A70_293AE0_DeepSeaSalvage(omObjData* obj);
void func_80105258_2942C8_DeepSeaSalvage(void);
s16 func_801052E8_294358_DeepSeaSalvage(omObjData* boat, s16 kind, s16 lane);
void func_8010536C_2943DC_DeepSeaSalvage(s16 idx);
void func_801056FC_29476C_DeepSeaSalvage(s16 idx);
void func_80105804_294874_DeepSeaSalvage(DSSHud* hud, s16 member, u16 anim, u16 x, s32 y);
void func_801058A0_294910_DeepSeaSalvage(omObjData* obj);
void func_80105BB8_294C28_DeepSeaSalvage(omObjData* obj);
void func_80105E84_294EF4_DeepSeaSalvage(s32 player, s16 coins);

/* ---------------------------------------------------------------------------------------------
   294F20.c
   --------------------------------------------------------------------------------------------- */

void func_80105EB0_294F20_DeepSeaSalvage(void);
void func_80105F14_294F84_DeepSeaSalvage(void);
DSSWork* func_80105F5C_294FCC_DeepSeaSalvage(omObjData* obj);
void func_80106048_2950B8_DeepSeaSalvage(void);
u32 func_801060C8_295138_DeepSeaSalvage(void); /* 16 random bits */
u16 func_80106100_295170_DeepSeaSalvage(u16 n); /* random 0..n-1 */
void func_80106134_2951A4_DeepSeaSalvage(f32* x, f32* y, f32* z);
void func_801061CC_29523C_DeepSeaSalvage(f32* x, f32* y, f32 dist, DSSPoint* pts, s16 n, s16 flag, f32* outx, f32* outy);
s16 func_80106518_295588_DeepSeaSalvage(f32* x, f32* y, s16 r, s16 flag, f32* outx, f32* outy);
f32 func_801069E4_295A54_DeepSeaSalvage(f32 x, f32 y); /* the sea floor's height */
s16 func_80106CC4_295D34_DeepSeaSalvage(f32 x, f32 y); /* the treasure at (x, y), -1 none */
void func_80106D5C_295DCC_DeepSeaSalvage(omObjData* obj, f32 vx, f32 vy);
s16 func_80106EC4_295F34_DeepSeaSalvage(s32 file);
void func_80106F08_295F78_DeepSeaSalvage(void);
s16 func_801070D0_296140_DeepSeaSalvage(s16 type, f32 x, f32 y, f32 z, s16 target);
void func_801072C0_296330_DeepSeaSalvage(s16 idx);
void func_80107318_296388_DeepSeaSalvage(void);

/* ---------------------------------------------------------------------------------------------
   296550.c
   --------------------------------------------------------------------------------------------- */

void func_801074E0_296550_DeepSeaSalvage(omObjData* obj);
void func_801075A4_296614_DeepSeaSalvage(s16 idx, s16 dir);
void func_80107864_2968D4_DeepSeaSalvage(omObjData* obj, s16 idx);
void func_80107A10_296A80_DeepSeaSalvage(omObjData* obj);
void func_8010819C_29720C_DeepSeaSalvage(omObjData* obj);
void func_801081EC_29725C_DeepSeaSalvage(omObjData* obj);

#endif
