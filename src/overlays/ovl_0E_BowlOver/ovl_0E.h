#ifndef _OVL_0E_H
#define _OVL_0E_H

/* Overlay 0E: Bowl Over (1 vs 3), descended from MP1's ovl_11_BowlOver (13EFB0.c, 142EA0.c,
   BowlOver.h). The solo player rolls a shell down one of three alleys at six pins; the other three
   players stand on pin slots and jump out of its way. Two retail files: 13CB90.c (setup, the
   bowler, the shell, camera; MP1 13EFB0.c) and 141320.c (from 80106F90: alley, pins, pin players;
   MP1 142EA0.c). .data stays asm; .rodata is carved per file. */

#include "common.h"
#include "game/object.h"

typedef f32 Matrix4f[4][4];

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's work (obj->unk_50, 0x15C, MP2's minigame player work; MP1 BowlPlayerWork 0xE8:
   MP1 fields from 0x56 on are +1, from 0x90 on +0x10). */
typedef struct BOPlayerWork {
    /* 0x000 */ char unk_00[0x38];
    /* 0x038 */ f32 unk_38;
    /* 0x03C */ char unk_3C[0x14];
    /* 0x050 */ u16 unk_50;
    /* 0x052 */ u8 unk_52;
    /* 0x053 */ char unk_53[4];
    /* 0x057 */ u8 port;
    /* 0x058 */ char unk_58;
    /* 0x059 */ s8 player;
    /* 0x05A */ char unk_5A[0x52];
    /* 0x0AC */ f32 unk_AC;
    /* 0x0B0 */ char unk_B0[4];
    /* 0x0B4 */ f32 unk_B4;
    /* 0x0B8 */ char unk_B8[0x18];
    /* 0x0D0 */ u16 unk_D0;
    /* 0x0D2 */ char unk_D2[0x16];
    /* 0x0E8 */ void* unk_E8; /* motion table */
    /* 0x0EC */ char unk_EC[0x70];
} BOPlayerWork; /* size = 0x15C */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct BOCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08; /* its model file */
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} BOCharData; /* size = 0x18 */
extern BOCharData D_800CD438_CE038[];

#define BO_WORK(obj) ((BOPlayerWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Data (.data, 13CB90.c: 80109960-80109A40)
   --------------------------------------------------------------------------------------------- */

extern s16 D_80109960_143CF0_BowlOver;
extern s32 D_80109964_143CF4_BowlOver;
extern u16 D_80109968_143CF8_BowlOver;
extern u16 D_8010996C_143CFC_BowlOver;
extern s16 D_8010996E_143CFE_BowlOver;
extern s8 D_80109970_143D00_BowlOver;
extern s8 D_80109971_143D01_BowlOver;
extern s8 D_80109972_143D02_BowlOver;
extern s8 D_80109973_143D03_BowlOver;
extern s8 D_80109974_143D04_BowlOver;
extern s8 D_80109975_143D05_BowlOver;
extern s8 D_80109976_143D06_BowlOver;
extern s8 D_80109977_143D07_BowlOver;
extern s8 D_80109978_143D08_BowlOver;
extern s8 D_80109979_143D09_BowlOver;
extern s8 D_8010997A_143D0A_BowlOver;
extern s32 D_8010997C_143D0C_BowlOver;
extern s32 D_80109980_143D10_BowlOver;
extern s32 D_80109984_143D14_BowlOver;
extern s32 D_80109988_143D18_BowlOver; /* throw timer (MP1 D_800FD300) */
extern s32 D_8010998C_143D1C_BowlOver; /* bowler state (MP1 D_800FD304) */
extern u16 D_80109990_143D20_BowlOver;
extern s16 D_80109992_143D22_BowlOver;
extern s16 D_80109994_143D24_BowlOver;
extern u8 D_80109996_143D26_BowlOver;
extern u8 D_80109997_143D27_BowlOver;
extern u8 D_80109998_143D28_BowlOver;
extern u16 D_8010999C_143D2C_BowlOver;
extern s32 D_801099A0_143D30_BowlOver;
extern f32 D_801099A4_143D34_BowlOver;
extern u8 D_801099A8_143D38_BowlOver;
extern f32 D_801099AC_143D3C_BowlOver;
extern f32 D_801099B0_143D40_BowlOver;
extern f32 D_801099B4_143D44_BowlOver;
extern f32 D_801099B8_143D48_BowlOver;
extern f32 D_801099BC_143D4C_BowlOver;
extern s8 D_801099C0_143D50_BowlOver;
extern s8 D_801099C1_143D51_BowlOver;
extern f32 D_801099C4_143D54_BowlOver[2][3]; /* viewport scale (640, 480, 511) */
extern f32 D_801099DC_143D6C_BowlOver[2][3]; /* viewport translate */
extern f32 D_801099F4_143D84_BowlOver[11];

/* ---------------------------------------------------------------------------------------------
   Data (.data, 141320.c: 80109A40-80109AC0)
   --------------------------------------------------------------------------------------------- */

extern u8 D_80109A40_143DD0_BowlOver; /* alley (0-2; main's D_800FA656) */
extern u8 D_80109A41_143DD1_BowlOver;
extern s16 D_80109A50_143DE0_BowlOver;

/* ---------------------------------------------------------------------------------------------
   Bss (asm)
   --------------------------------------------------------------------------------------------- */

extern Vec3f D_80109E00_144190_BowlOver;
extern Vec3f D_80109E0C_14419C_BowlOver;
extern u16 D_80109E18_1441A8_BowlOver;
extern s16 D_80109E1A_1441AA_BowlOver;
extern f32 D_80109E1C_1441AC_BowlOver;
extern s16 D_80109EF8_144288_BowlOver[40];
extern Vec3f D_8010A09C_14442C_BowlOver; /* bowler start position */
extern omObjData* D_8010A0A8_144438_BowlOver; /* the shell */
extern s16 D_8010A0AC_14443C_BowlOver;
extern s8 D_8010A0AE_14443E_BowlOver[4]; /* [0] bowler, [1..3] pin players */
extern omObjData* D_8010A0B8_144448_BowlOver[6]; /* the six pins */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800FC7B0_FD3B0[];
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u8 D_800FA656;
extern f32 D_8010105C_101C5C;
extern f32 D_80101300_101F00;

void func_8002D4D0_2E0D0(s16 n, s8* players);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C018_CC18(u16);
void func_8007273C_7333C(u8* arg0, u8 arg1);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void espDispOn(u16);
void espDispOff(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 LoadFormFile(s32, s32);
void* func_80027154_27D54(s32 size, s16 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BEBC_CABC(omObjData*, f32);
void func_8000BEC8_CAC8(omObjData*, f32);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029EDC_2AADC(s16, s32);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079848_7A448(s16 arg0);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
s32 PlaySound(s32);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x);
u8 rand8(void);

/* ---------------------------------------------------------------------------------------------
   Overlay functions (13CB90.c)
   --------------------------------------------------------------------------------------------- */

void func_80102800_13CB90_BowlOver(void);
void func_80102E04_13D194_BowlOver(omObjData* obj);
void func_801040A0_13E430_BowlOver(omObjData* obj);
void func_801041CC_13E55C_BowlOver(omObjData* obj);
void func_801042F0_13E680_BowlOver(omObjData* obj);
void func_8010487C_13EC0C_BowlOver(omObjData* obj);
void func_80104D78_13F108_BowlOver(omObjData* obj, s32 dir, s32 file, s32 file2, u16 player, f32 x, f32 y, f32 z);
void func_801051B4_13F544_BowlOver(omObjData* obj);
void func_80105974_13FD04_BowlOver(omObjData* obj);
void func_80105AFC_13FE8C_BowlOver(void);
void func_80105D14_1400A4_BowlOver(omObjData* obj);
void func_80105EE4_140274_BowlOver(s16* arg0);
void func_801063D0_140760_BowlOver(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_80106450_1407E0_BowlOver(omObjData* obj);
void func_801064C8_140858_BowlOver(omObjData* obj);
void func_8010655C_1408EC_BowlOver(omObjData* obj, f32 x, f32 y, f32 z);
s32 func_80106648_1409D8_BowlOver(omObjData* obj, omObjData* ball);
f32 func_80106704_140A94_BowlOver(void);
f32 func_801068D0_140C60_BowlOver(void);
s32 func_801069D0_140D60_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_80106C94_141024_BowlOver(Vec3f* pos, Vec3f* axis, f32 angle, Matrix4f out);
s32 func_80106E8C_14121C_BowlOver(u32 seed);
u32 func_80106F60_1412F0_BowlOver(void);

/* ---------------------------------------------------------------------------------------------
   Overlay functions (141320.c; inferred from registers and MP1 142EA0.c: check them)
   --------------------------------------------------------------------------------------------- */

void func_80106F90_141320_BowlOver(void);
void func_801070DC_14146C_BowlOver(omObjData* obj);
void func_801072F0_141680_BowlOver(omObjData* obj);
void func_80107390_141720_BowlOver(void);
void func_80107570_141900_BowlOver(void);
void func_80107738_141AC8_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_8010782C_141BBC_BowlOver(omObjData* obj, f32 dx, f32 dz);
void func_801079EC_141D7C_BowlOver(omObjData* obj);
void func_80107DB4_142144_BowlOver(omObjData* obj);
void func_801082B8_142648_BowlOver(omObjData* obj, void* jump, u8* sx, u8* sy);
void func_801087A0_142B30_BowlOver(omObjData* obj);
void func_80108DCC_14315C_BowlOver(omObjData* obj);
void func_80108ECC_14325C_BowlOver(omObjData* obj, s32 dir, s32 file, s8 player, u16 slot, u16 pin);
void func_80109148_1434D8_BowlOver(omObjData* obj);
void func_80109354_1436E4_BowlOver(omObjData* obj);
void func_8010947C_14380C_BowlOver(omObjData* obj, s16 slot, s8 pin);
void func_801096A0_143A30_BowlOver(void);
void func_8010977C_143B0C_BowlOver(omObjData* obj);
void func_801097F4_143B84_BowlOver(omObjData* obj);
void func_80109870_143C00_BowlOver(omObjData* obj);
void func_801098EC_143C7C_BowlOver(omObjData* obj);
void func_80109910_143CA0_BowlOver(omObjData* obj);
void func_80109934_143CC4_BowlOver(omObjData* obj);

#endif
