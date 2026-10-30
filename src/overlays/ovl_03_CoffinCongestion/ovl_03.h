#ifndef _OVL_03_H
#define _OVL_03_H

/* Overlay 03: Coffin Congestion (item minigame). One player walks a room with six coffins; the
   coffins (items inside, D_800CAFD8) close and shuffle in five rounds, then the player opens one
   and wins its item (gPlayers[].coins_mg_bonus). Two retail files: F3F10.c (the entry,
   80102800) and F3F70.c (the rest, from 80102860 after a 2-nop pad). .data stays asm
   (F7D10.data.s); .rodata is carved ([0xF8410, .rodata, F3F70]). */

#include "common.h"
#include "game/object.h"
#include "game/pad.h"
#include "game/collision.h"

/* ---------------------------------------------------------------------------------------------
   Main API not declared in include/
   --------------------------------------------------------------------------------------------- */

typedef struct CCCharData { /* D_800CD438, one per character (= ovl_34's CTCharData) */
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* motion file base (dir) */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} CCCharData; /* size = 0x18 */

extern CCCharData D_800CD438_CE038[];
extern u16 D_800CAFD8[];        /* item ids (main 3D6A0.c) */
extern s16 D_800CAFE4[];        /* item chances, percent */
extern void* D_800F93FC_F9FFC;  /* esprite slots (0x24 each) */
extern s32 D_800F9D30_FA930[];
extern u16 D_800F8FE0_F9BE0;    /* ground object count */
extern omObjData* D_800FC7B0_FD3B0[]; /* ground objects */
extern u16 D_800FC87A_FD47A;    /* player object count */
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;   /* minigame told to end */
extern u8 D_80102720_103320;
extern f32 D_800BF7A4_C03A4;    /* jump speed */
extern f32 D_800F8410_F9010;
extern f32 D_80101078_101C78;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

f32 HuMathSin(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecGetLength3F(Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void espDispOff(u16);
void func_80007790_8390(omObjData* obj);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C38C_CF8C(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000E0C0_ECC0(MgWork* work, s32 slot, void* hook);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_80023124_23D24(void);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s32 tag);
void func_8002864C_2924C(void);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029FBC_2ABBC(s16, f32);
void func_80029FE4_2ABE4(s16, f32);
s32 func_8002C8B8_2D4B8(void*, s16);
f32 func_8002CA14_2D614(s16);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D0A0_2DCA0(s16, u8);
void func_8002D124_2DD24(s16 index);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F1A4_2FDA4(void);
void func_8002F290_2FE90(s32* arg0, s32 n);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32);
omObjData* func_80076D98_77998(s16 grp, u16 idx);
u16 func_80078EA8_79AA8(void);
void func_80079868_7A468(void);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8007A7FC_7B3FC();
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_800B3170_B3D70(Vec*, Vec*);
void func_800B33E0_B3FE0(Vec*);
void omDelObj(omObjData*);
void omSetSca(omObjData* obj, f32 x, f32 y, f32 z);
void omSetTra(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* State of one room object (CCGround.unk_B0, 0x30 bytes) and of one smoke puff (the puffs'
   omObjData::unk_50 directly). */
typedef struct CCProp {
    /* 0x00 */ Vec pos;
    /* 0x0C */ s16 unk_0C;      /* object index (puffs: in use) */
    /* 0x0E */ s16 unk_0E;      /* alpha 0..255 */
    /* 0x10 */ s16 unk_10;      /* state */
    /* 0x12 */ s16 unk_12;      /* item id in a coffin (-1 none) */
    /* 0x14 */ omObjData* unk_14; /* the player who opened it */
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;      /* 1 once opened */
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[8];
} CCProp; /* size = 0x30 */

/* omObjData::unk_50 of a room object (0xB4 bytes; a collision GroundWork plus the prop). */
typedef struct CCGround {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;       /* object index */
    /* 0x05 */ char unk_05[3];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x9C];
    /* 0xB0 */ CCProp* unk_B0;
} CCGround; /* size = 0xB4 */

/* One entry of the room object table D_80106600[27]. */
typedef struct CCObjDef {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ s32 file;
    /* 0x14 */ s32 attr;
    /* 0x18 */ s16 func;        /* index into D_80106A0C */
    /* 0x1A */ u8 unk_1A;       /* omAddObj mdlcnt */
    /* 0x1B */ u8 unk_1B;       /* omAddObj mtncnt */
} CCObjDef; /* size = 0x1C */

/* The host model's motions (D_8010691C[5]). */
typedef struct CCMotion {
    /* 0x00 */ s32 file;
    /* 0x04 */ s16 len;
    /* 0x06 */ s16 speed;       /* < 0: loop */
} CCMotion; /* size = 8 */

/* A CPU walk target (D_80106A3C[6], D_80106AB4, D_80106AC8). */
typedef struct CCCpuTarget {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
} CCCpuTarget; /* size = 0x14 */

/* MgWork::unk_158 of the player (0x14 bytes): the CPU's plan. */
typedef struct CCCpu {
    /* 0x00 */ s16 unk_00;      /* CPU action, index into D_80106BE8 */
    /* 0x02 */ u16 unk_02;      /* flags: 1 target reached */
    /* 0x04 */ CCCpuTarget* unk_04;
    /* 0x08 */ s8 unk_08;       /* wait timer */
    /* 0x09 */ s8 unk_09;       /* character */
    /* 0x0A */ u8 unk_0A;       /* difficulty */
    /* 0x0B */ char unk_0B;
    /* 0x0C */ s16 unk_0C;      /* state */
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
} CCCpu; /* size = 0x14 */

/* One motion slot of the player (D_80106AEC[15]). */
typedef struct CCMotionDef {
    /* 0x00 */ u16 slot;
    /* 0x04 */ s32 file;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
} CCMotionDef; /* size = 0xC */

typedef struct CCFile {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 attr;
} CCFile;

/* Minigame flow (D_80106DF0, bss). */
typedef struct CCGame {
    /* 0x00 */ u16 mode;        /* index into D_80106CD8 */
    /* 0x02 */ u16 next;
    /* 0x04 */ s16 step;
    /* 0x06 */ s16 timer;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 time;        /* countdown, frames */
    /* 0x0C */ s16 item;        /* result item (-1 none) */
    /* 0x0E */ s16 player;      /* result player */
    /* 0x10 */ s32 frames;
} CCGame; /* size = 0x14 */

/* Scene state (D_80106DB8, bss). */
typedef struct CCScene {
    /* 0x00 */ s16 cur;         /* phase: 1 lids down, 2 shake, 3 lids up */
    /* 0x02 */ s16 prev;
    /* 0x04 */ s32 idx;         /* last coffin slot filled */
    /* 0x08 */ CCProp* slot[6]; /* the coffin in each slot (D_80106DC0) */
} CCScene;

/* Saved controller state, one per port (D_80106E04[4]). */
typedef struct CCPad {
    /* 0x00 */ u16 trg;
    /* 0x02 */ u16 btn;
    /* 0x04 */ s8 stkX;
    /* 0x05 */ s8 stkY;
} CCPad; /* size = 6 */

/* ---------------------------------------------------------------------------------------------
   Data (.data, F7D10.data.s, asm)
   --------------------------------------------------------------------------------------------- */

extern CCObjDef D_80106600_F7D10_CoffinCongestion[27];
extern f32 D_801068BC_F7FCC_CoffinCongestion;
extern f32 D_801068C0_F7FD0_CoffinCongestion;
extern f32 D_801068C4_F7FD4_CoffinCongestion;
extern f32 D_801068C8_F7FD8_CoffinCongestion;
extern s32 D_801068F4_F8004_CoffinCongestion[10]; /* item model files */
extern CCMotion D_8010691C_F802C_CoffinCongestion[5];
extern Vec D_80106944_F8054_CoffinCongestion[6]; /* coffin slots */
extern void (*D_8010698C_F809C_CoffinCongestion[8])(omObjData*, CCProp*);
extern void (*D_801069AC_F80BC_CoffinCongestion[8])(omObjData*, CCProp*);
extern void (*D_801069CC_F80DC_CoffinCongestion[8])(omObjData*, CCProp*);
extern void (*D_801069EC_F80FC_CoffinCongestion[8])(omObjData*, CCProp*);
extern void (*D_80106A0C_F811C_CoffinCongestion[])(omObjData*);
extern Vec D_80106A30_F8140_CoffinCongestion;
extern CCCpuTarget D_80106A3C_F814C_CoffinCongestion[6];
extern CCCpuTarget D_80106AB4_F81C4_CoffinCongestion;
extern CCCpuTarget D_80106AC8_F81D8_CoffinCongestion;
extern u8 D_80106ADC_F81EC_CoffinCongestion[4][4];
extern CCMotionDef D_80106AEC_F81FC_CoffinCongestion[15];
extern CCFile D_80106BA0_F82B0_CoffinCongestion[9];
extern void (*D_80106BE8_F82F8_CoffinCongestion[4])(MgWork*, CCCpu*);
extern void (*D_80106BF8_F8308_CoffinCongestion[8])(omObjData*, MgWork*, CCCpu*);

/* ---------------------------------------------------------------------------------------------
   Bss (ovl_03_bss)
   --------------------------------------------------------------------------------------------- */

extern omObjData** D_80106DB0_F84C0_CoffinCongestion; /* room objects [27] */
extern omObjData** D_80106DB4_F84C4_CoffinCongestion; /* smoke puffs [6], 0 before created */
extern CCScene D_80106DB8_F84C8_CoffinCongestion;
extern f32 D_80106DD8_F84E8_CoffinCongestion;         /* knock-back stick x */
extern s16 D_80106DDC_F84EC_CoffinCongestion;         /* coffin touched */
extern omObjData** D_80106DE0_F84F0_CoffinCongestion; /* player object */
extern CCGame D_80106DF0_F8500_CoffinCongestion;
extern CCPad D_80106E04_F8514_CoffinCongestion[4];

/* ---------------------------------------------------------------------------------------------
   Functions (F3F10.c, F3F70.c)
   --------------------------------------------------------------------------------------------- */

void func_80102800_F3F10_CoffinCongestion(void);
s32 func_80102860_F3F70_CoffinCongestion(omObjData* obj, s32 mot);
void func_80102944_F4054_CoffinCongestion(CCProp* p, Vec* pos);
void func_801029C0_F40D0_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102A20_F4130_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102B28_F4238_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102B90_F42A0_CoffinCongestion(omObjData* obj);
void func_80102C44_F4354_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102C74_F4384_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102E64_F4574_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102EE0_F45F0_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80102F10_F4620_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103080_F4790_CoffinCongestion(omObjData* obj);
void func_80103134_F4844_CoffinCongestion(omObjData* obj);
void func_801031AC_F48BC_CoffinCongestion(omObjData* obj);
void func_801032B8_F49C8_CoffinCongestion(omObjData* obj, CCProp* p);
void func_801032D8_F49E8_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103350_F4A60_CoffinCongestion(omObjData* obj);
void func_80103398_F4AA8_CoffinCongestion(s32 item);
omObjData* func_801034B0_F4BC0_CoffinCongestion(void);
void func_801034F8_F4C08_CoffinCongestion(f32 x, f32 y, f32 z);
void func_80103578_F4C88_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103884_F4F94_CoffinCongestion(omObjData* obj);
void func_80103938_F5048_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103AB8_F51C8_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103BD8_F52E8_CoffinCongestion(omObjData* obj, CCProp* p);
void func_80103D50_F5460_CoffinCongestion(omObjData* obj);
void func_80103DE0_F54F0_CoffinCongestion(omObjData* obj);
void func_80103F88_F5698_CoffinCongestion(void);
void func_80104478_F5B88_CoffinCongestion(void);
void func_801044CC_F5BDC_CoffinCongestion(void);
void func_80104570_F5C80_CoffinCongestion(omObjData* obj);
void func_801045E8_F5CF8_CoffinCongestion(s16 phase);
void func_80104600_F5D10_CoffinCongestion(void);
void func_80104650_F5D60_CoffinCongestion(void);
s32 func_80104684_F5D94_CoffinCongestion(s32 item);
s32 func_801046C8_F5DD8_CoffinCongestion(s32 player);
void func_80104878_F5F88_CoffinCongestion(omObjData* obj, omObjData* ground);
s32 func_8010499C_F60AC_CoffinCongestion(omObjData* obj, CCGround* ground);
s32 func_801049FC_F610C_CoffinCongestion(omObjData* obj, CCGround* ground);
s32 func_80104A7C_F618C_CoffinCongestion(omObjData* obj);
s32 func_80104AD4_F61E4_CoffinCongestion(omObjData* obj);
void func_80104B60_F6270_CoffinCongestion(MgWork* work, CCCpu* cpu);
void func_80104BA8_F62B8_CoffinCongestion(MgWork* work, CCCpu* cpu);
void func_80104C30_F6340_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu);
void func_80104DD8_F64E8_CoffinCongestion(MgWork* work, CCCpu* cpu);
void func_80104E20_F6530_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu);
void func_80104E80_F6590_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu);
void func_80105074_F6784_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu);
void func_801051C0_F68D0_CoffinCongestion(omObjData* obj);
void func_8010524C_F695C_CoffinCongestion(omObjData* obj, s32 player);
void func_801054C4_F6BD4_CoffinCongestion(void);
void func_801055C4_F6CD4_CoffinCongestion(void);
f32 func_801055EC_F6CFC_CoffinCongestion(void);
void func_80105600_F6D10_CoffinCongestion(void);
u16 func_80105638_F6D48_CoffinCongestion(s32 idx, s32 arg1);
void func_80105710_F6E20_CoffinCongestion(void);
void func_801057A0_F6EB0_CoffinCongestion(void);
void func_80105830_F6F40_CoffinCongestion(void);
void func_80105884_F6F94_CoffinCongestion(void);
void func_801059A8_F70B8_CoffinCongestion(void);
void func_80105A98_F71A8_CoffinCongestion(void);
void func_80105AB4_F71C4_CoffinCongestion(void);
void func_80105C6C_F737C_CoffinCongestion(void);
void func_80105CF0_F7400_CoffinCongestion(void);
void func_80105D44_F7454_CoffinCongestion(void);
void func_80105EE0_F75F0_CoffinCongestion(void);
void func_80105F9C_F76AC_CoffinCongestion(omObjData* obj);
void func_8010606C_F777C_CoffinCongestion(omObjData* obj);
void func_8010609C_F77AC_CoffinCongestion(Vec* v);
void func_801060E8_F77F8_CoffinCongestion(void);
void func_80106118_F7828_CoffinCongestion(void);
void func_80106314_F7A24_CoffinCongestion(void);
void func_801064C8_F7BD8_CoffinCongestion(void);
void func_80106534_F7C44_CoffinCongestion(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn);
u16 func_80106570_F7C80_CoffinCongestion(void);
void func_8010657C_F7C8C_CoffinCongestion(u16 mode);
s32 func_801065A8_F7CB8_CoffinCongestion(void);
s16 func_801065B4_F7CC4_CoffinCongestion(void);
void func_801065C0_F7CD0_CoffinCongestion(s16 player, s16 item);
s16 func_801065EC_F7CFC_CoffinCongestion(void);

#endif
