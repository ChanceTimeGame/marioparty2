#ifndef _OVL_01_H
#define _OVL_01_H

/* Overlay 01 (DA290.c): Bowser Slots, the item minigame a board event starts. One player stands
   under Bowser's three-reel slot machine and jumps into its block to stop each reel; three equal
   symbols win an item (D_8010C0CC, a copy of main's item table D_800CAFD8), which flies out of the
   machine to the player and is left in gPlayers[].coins_mg_bonus (-1 for none). A CPU player
   presses A by itself (func_80104520), aiming for D_8010C06C's symbol.
   Retail is one file. The reel code descends from MP1's ovl_02 SlotMachine (E5DA0.c: the face
   tables, the reel sprites, the camera projection); the flow, the player and the camera blend are
   new. The .rodata is carved ([0xE3510, .rodata, DA290]); .data and .bss stay asm. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/pad.h"
#include "game/data.h"

/* ---- main-segment API used by 01 ---- */

typedef f32 Matrix4f[4][4]; /* as in 30560.c */

typedef struct BSCharData { /* = ovl_34's CTCharData (D_800CD438, one per character) */
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* motion file base */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* passed to func_8000C6FC as its file */
    /* 0x14 */ char unk_14[4];
} BSCharData; /* size = 0x18 */
extern BSCharData D_800CD438_CE038[];

/* omObjData::unk_50 of the player object (C8E0.c's MgWork, 0x15C bytes) */
typedef struct BSPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed */
    /* 0x3C */ char unk_3C[0x1B];
    /* 0x57 */ s8 unk_57; /* controller port */
    /* 0x58 */ char unk_58[0x94];
    /* 0xEC */ s32 unk_EC;
} BSPlayerWork;

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s32 D_800F8FD0_F9BD0; /* 1: the players' input is cleared (scene not started) */
extern u16 D_800F8FE0_F9BE0;
extern u16 D_800FC87A_FD47A;
extern s16 D_800FA606_FB206;
extern s16 D_800FA1AA_FADAA; /* heap tag for func_80027154 */
extern u16 D_801011FC_101DFC;
extern omObjData* D_800FC7B0_FD3B0[];
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern u16 D_800CAFD8[]; /* item ids */
extern u8 D_80102720_103320;
extern s32 fontcolor;
extern char pfStrBuf[];

void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80079614_7A214(s16 time); /* music fade-out */
s32 func_800153CC_15FCC(s32 defNo);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
omObjData* func_800732B0_73EB0(u32 arg0);
s16 func_80079798_7A398(s16, s16);
void func_80079848_7A448(s16 arg0);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->rot */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000BE8C_CA8C(omObjData* obj, f32 arg1);
void func_8000BEA4_CAA4(omObjData* obj, f32 arg1);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1); /* hit box */
void func_80007790_8390(omObjData* obj);
void func_80019378_19F78(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s16 LoadFormFile(s32, s32);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void* SprAnimGet(s16 animIdx);
s16 SprAnimRead(void*);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
f32 func_80029D0C_2A90C(s16);
void func_80029A8C_2A68C(s16);
void func_8002A00C_2AC0C(s16);
void func_80029F2C_2AB2C(s16, s32);
void func_8002A15C_2AD5C(s16 arg0, s16 arg1, f32 arg2);
void* func_8002A9F4_2B5F4(s16 arg0, char* arg1);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80030CD4_318D4(Matrix4f, Matrix4f);
u16 func_80078EA8_79AA8(void);
f32 HuMathSin(f32);
f64 fabs(f64);
s32 PlaySound(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 DrawDebugText(u16, u16, char*);

/* ---- overlay types ---- */

/* omObjData::unk_50 of the stage object (0xB4 bytes, cleared) */
typedef struct BSGroundWork {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk_05[0xAF];
} BSGroundWork; /* size = 0xB4 */

/* One reel (D_8010C0D0, three of them, 0xB4 bytes). */
typedef struct BSReel {
    /* 0x00 */ s32 model;   /* the reel texture's model */
    /* 0x04 */ s32 state;   /* 0 stopped, 1 speeding up, 2 spinning, 3 stopping, 4 stopping at
                               unk_1C, 5 snapping to a face, 6 */
    /* 0x08 */ s32 timer;   /* frames left in state 2; -1 none, -2 the stop was handled */
    /* 0x0C */ s32 turns;
    /* 0x10 */ s32 passed;  /* faces passed in state 2 */
    /* 0x14 */ s32 symbol;  /* symbol under the line */
    /* 0x18 */ s32 face;    /* face under the line (0-7) */
    /* 0x1C */ s32 target;  /* face to stop on (state 4) */
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 angle;
    /* 0x28 */ f32 offset;  /* drawn angle = angle + offset */
    /* 0x2C */ f32 speed;
    /* 0x30 */ f32 accel;
    /* 0x34 */ f32 maxSpeed;
    /* 0x38 */ HmfMotionObj* part; /* the reel's motion object ("r1".."r3") */
} BSReel; /* size = 0x3C */

/* A camera position (D_8010C078: [0] the target, [1] the start of a blend). */
typedef struct BSCamera {
    /* 0x00 */ Vec center;
    /* 0x0C */ Vec rot;
    /* 0x18 */ f32 zoom;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} BSCamera; /* size = 0x24 */

#define BS_MODEL(i) (&D_800FC834_FD434[i])

/* ---- .data ---- */
extern f32 D_8010B6B0_E3140_BowserSlots[8];       /* face boundary angles 45..360 */
extern f32 D_8010B6AC_E313C_BowserSlots[];        /* = D_8010B6B0 - 1 (the face's start angle) */
extern s32 D_8010B6D0_E3160_BowserSlots[3][9];    /* reel -> face -> symbol */
extern s32 D_8010B73C_E31CC_BowserSlots[8];       /* per difficulty: stop chance (%) */
extern s32 D_8010B78C_E321C_BowserSlots[];        /* per character: winning motion */
extern s32 D_8010B7A4_E3234_BowserSlots[];        /* per character: losing motion */
extern s32 D_8010B7BC_E324C_BowserSlots;          /* flow state */
extern s32 D_8010B7C0_E3250_BowserSlots;          /* flow frame counter */
extern s32 D_8010B7C4_E3254_BowserSlots;          /* flow wait */
extern s32 D_8010B7C8_E3258_BowserSlots;          /* exit countdown */
extern s32 D_8010B7CC_E325C_BowserSlots;          /* camera test mode */
extern s32 D_8010B7D0_E3260_BowserSlots;
extern s32 D_8010B7D4_E3264_BowserSlots;
extern s32 D_8010B7D8_E3268_BowserSlots;          /* CPU: A held frames */
extern s32 D_8010B7DC_E326C_BowserSlots;          /* CPU: wait frames */
extern s32 D_8010B7E0_E3270_BowserSlots;          /* CPU: last face seen */
extern s32 D_8010B7E4_E3274_BowserSlots;
extern s32 D_8010B7E8_E3278_BowserSlots;          /* sine angle */
extern f32 D_8010B7EC_E327C_BowserSlots[];        /* per character: height */
extern s32 D_8010B804_E3294_BowserSlots;          /* player was under the block */
extern char D_8010B818_E32A8_BowserSlots[3][8];   /* "r1".."r3" */
extern s32 D_8010B830_E32C0_BowserSlots;
extern s32 D_8010B834_E32C4_BowserSlots;
extern s32 D_8010B838_E32C8_BowserSlots;
extern f32 D_8010B83C_E32CC_BowserSlots;
extern f32 D_8010B840_E32D0_BowserSlots;
extern f32 D_8010B844_E32D4_BowserSlots;
extern s32 D_8010B848_E32D8_BowserSlots[3];
extern f32 D_8010B854_E32E4_BowserSlots[4];
extern f32 D_8010B864_E32F4_BowserSlots[4];
extern Vec D_8010B874_E3304_BowserSlots;
extern Vec D_8010B880_E3310_BowserSlots;
extern Vec D_8010B88C_E331C_BowserSlots;
extern f32 D_8010B898_E3328_BowserSlots;
extern f32 D_8010B89C_E332C_BowserSlots;
extern s32 D_8010B8A0_E3330_BowserSlots;
extern s32 D_8010B8A4_E3334_BowserSlots;
extern s32 D_8010B8A8_E3338_BowserSlots;
extern s32 D_8010B8AC_E333C_BowserSlots;
extern s32 D_8010B8B0_E3340_BowserSlots;
extern s32 D_8010B8B4_E3344_BowserSlots;
extern f32 D_8010B8B8_E3348_BowserSlots[2];
extern f32 D_8010B8C0_E3350_BowserSlots[2];
extern s32 D_8010B8C8_E3358_BowserSlots;

/* ---- .bss ---- */
extern u8 D_8010BFB0_E3A40_BowserSlots[8];        /* items of the eight faces */
extern Vec D_8010BFB8_E3A48_BowserSlots[10];      /* item trail */
extern omObjData* D_8010C030_E3AC0_BowserSlots;   /* the flow object */
extern omObjData* D_8010C034_E3AC4_BowserSlots;   /* the block object */
extern omObjData* D_8010C038_E3AC8_BowserSlots;   /* the machine object */
extern omObjData* D_8010C03C_E3ACC_BowserSlots;   /* the item object */
extern s32 D_8010C040_E3AD0_BowserSlots;          /* frame counter */
extern s32 D_8010C048_E3AD8_BowserSlots[4];       /* the player's motions */
extern s16 D_8010C058_E3AE8_BowserSlots;          /* flag 0xC (debug) */
extern s16 D_8010C05A_E3AEA_BowserSlots;          /* player index */
extern s32 D_8010C05C_E3AEC_BowserSlots;          /* player index */
extern s16 D_8010C05E_E3AEE_BowserSlots;
extern s32 D_8010C060_E3AF0_BowserSlots;          /* character */
extern s16 D_8010C062_E3AF2_BowserSlots;
extern s32 D_8010C064_E3AF4_BowserSlots;          /* controller port */
extern s32 D_8010C068_E3AF8_BowserSlots;          /* CPU player */
extern s32 D_8010C06C_E3AFC_BowserSlots;          /* CPU: wanted symbol */
extern s32 D_8010C070_E3B00_BowserSlots;          /* CPU difficulty */
extern s32 D_8010C074_E3B04_BowserSlots;          /* CPU: presses at random */
extern BSCamera D_8010C078_E3B08_BowserSlots[2];
extern s32 D_8010C0C0_E3B50_BowserSlots;          /* camera blend frame */
extern s32 D_8010C0C4_E3B54_BowserSlots;          /* camera blend length */
extern f32 D_8010C0C8_E3B58_BowserSlots;
extern u16* D_8010C0CC_E3B5C_BowserSlots;         /* prize items (5) */
extern BSReel* D_8010C0D0_E3B60_BowserSlots;
extern s32 D_8010C0D4_E3B64_BowserSlots;          /* the first two reels match */
extern s32 D_8010C0D8_E3B68_BowserSlots;          /* their symbol */
extern s32 D_8010C0DC_E3B6C_BowserSlots;
extern s32 D_8010C0E0_E3B70_BowserSlots;          /* won symbol, -1 none */
extern s32 D_8010C0E4_E3B74_BowserSlots;
extern s32 D_8010C0E8_E3B78_BowserSlots;
extern s32 D_8010C0EC_E3B7C_BowserSlots;
extern s32 D_8010C0F0_E3B80_BowserSlots[2];       /* sprite animations of the block object */
extern s32 D_8010C0F8_E3B88_BowserSlots[2];       /* sprite animations of the machine */
extern s16 D_8010C100_E3B90_BowserSlots;          /* sprite animation of the item object */
extern s16 D_8010C102_E3B92_BowserSlots;
extern void* D_8010C170_E3C00_BowserSlots;
extern void* D_8010C174_E3C04_BowserSlots;
extern s16 D_8010C17E_E3C0E_BowserSlots;
extern s16 D_8010C180_E3C10_BowserSlots;
extern s16 D_8010C182_E3C12_BowserSlots;
extern s16 D_8010C18E_E3C1E_BowserSlots;          /* sound 0x127, -1 none */
extern s32 D_8010C190_E3C20_BowserSlots;          /* player motion to wait for, -1 none */

/* ---- overlay functions (fork A: 80102800-80106B30) ---- */
void func_80102800_DA290_BowserSlots(void);
void func_80102A70_DA500_BowserSlots(omObjData* obj);
void func_80102ACC_DA55C_BowserSlots(omObjData* obj);
void func_80102F34_DA9C4_BowserSlots(omObjData* obj);
void func_80102F58_DA9E8_BowserSlots(omObjData* obj);
void func_80103000_DAA90_BowserSlots(void);
void func_801030C0_DAB50_BowserSlots(void);
void func_801038FC_DB38C_BowserSlots(omObjData* obj);
void func_80103A9C_DB52C_BowserSlots(s32 idx);
void func_80103B4C_DB5DC_BowserSlots(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames);
void func_80103D84_DB814_BowserSlots(void);
void func_80103DEC_DB87C_BowserSlots(omObjData* obj);
void func_80104460_DBEF0_BowserSlots(omObjData* obj);
void func_80104520_DBFB0_BowserSlots(omObjData* obj);
void func_8010475C_DC1EC_BowserSlots(void);
void func_80104834_DC2C4_BowserSlots(omObjData* obj);
void func_80104914_DC3A4_BowserSlots(omObjData* obj);
void func_80104BAC_DC63C_BowserSlots(omObjData* obj);
void func_80104DDC_DC86C_BowserSlots(omObjData* obj);
void func_80105034_DCAC4_BowserSlots(void);
void func_80105088_DCB18_BowserSlots(omObjData* obj);
void func_801054E8_DCF78_BowserSlots(omObjData* obj);
void func_80105568_DCFF8_BowserSlots(omObjData* obj);
void func_80105AE4_DD574_BowserSlots(omObjData* obj);
void func_80105C28_DD6B8_BowserSlots(omObjData* obj);
void func_80105D5C_DD7EC_BowserSlots(omObjData* obj);
void func_80106084_DDB14_BowserSlots(void);
void func_801060A4_DDB34_BowserSlots(void);
void func_801060F0_DDB80_BowserSlots(void);
void func_80106110_DDBA0_BowserSlots(void);
void func_80106148_DDBD8_BowserSlots(void);
s32 func_80106254_DDCE4_BowserSlots(void);
s32 func_801063CC_DDE5C_BowserSlots(s32 reel, f32 angle);
s32 func_8010648C_DDF1C_BowserSlots(f32 angle);
f32 func_80106524_DDFB4_BowserSlots(f32 angle);
s32 func_801065D8_DE068_BowserSlots(s32 reel, s32 face);
s32 func_80106638_DE0C8_BowserSlots(s32 difficulty, s32 face, s32 dist);
s32 func_80106750_DE1E0_BowserSlots(void);
s32 func_801067A4_DE234_BowserSlots(void);
s32 func_801067DC_DE26C_BowserSlots(void);
void func_80106820_DE2B0_BowserSlots(omObjData* obj);
void func_80106B30_DE5C0_BowserSlots(omObjData* obj);

/* ---- fork B (80106B30+): inferred from register use, check against the asm ---- */
void func_801076EC_DF17C_BowserSlots(void);
s32 func_8010770C_DF19C_BowserSlots(s32 symbol); /* symbol -> item (retail callers use it unprototyped: int) */
void func_80107740_DF1D0_BowserSlots(s32 model);
void func_801078F0_DF380_BowserSlots(s32 model, s32 arg1);
void func_801079B8_DF448_BowserSlots(s32 model, f32 arg1, f32 arg2, f32 arg3);
void func_80107BCC_DF65C_BowserSlots(s32 model, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_80107D68_DF7F8_BowserSlots(u16 model, u16 anim, char* part, u8* items); /* returns a u16 (callers re-mask it) */
s16 func_8010879C_E022C_BowserSlots(void* anim, f32 scale);
s16 func_80108EE4_E0974_BowserSlots(void* anim, f32 scale);
void func_80109AF8_E1588_BowserSlots(u16 model, void* anim, s32 frame);
s16 func_80109BC8_E1658_BowserSlots(s32 model, s32 src);
s32 func_80109C5C_E16EC_BowserSlots(void* arg0, void* arg1, f32 arg2, u16 arg3, u16 arg4);
s32 func_8010A074_E1B04_BowserSlots(s32 file); /* sprite animation from a file; returns a u16 (callers re-mask it: retail called it unprototyped) */
void func_8010A0B8_E1B48_BowserSlots(void);
void func_8010A0EC_E1B7C_BowserSlots(s32 arg0, s32 arg1, s32 arg2);
void func_8010A138_E1BC8_BowserSlots(s32 arg0, s32 arg1);
void func_8010A1F4_E1C84_BowserSlots(void);
void func_8010A3CC_E1E5C_BowserSlots(void);
void func_8010A53C_E1FCC_BowserSlots(void);
void func_8010B148_E2BD8_BowserSlots(HmfMotionObj* part);
void func_8010B1D4_E2C64_BowserSlots(Vec* rot);
f32 func_8010B2FC_E2D8C_BowserSlots(f32 arg0, f32 arg1);
s32 func_8010B38C_E2E1C_BowserSlots(void);
void func_8010B43C_E2ECC_BowserSlots(s16 camera, Vec* pos, f32* out);
void func_8010B60C_E309C_BowserSlots(Matrix4f m, f32 x, f32 y, f32 z, f32* out);

#endif
