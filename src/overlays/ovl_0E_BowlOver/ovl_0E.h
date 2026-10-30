#ifndef _OVL_0E_H
#define _OVL_0E_H

/* Overlay 0E: Bowl Over (1 vs 3), descended from MP1's ovl_11_BowlOver (13EFB0.c, 142EA0.c,
   BowlOver.h). The solo player rolls a shell down one of three alleys at six pins; the other three
   players stand on pin slots and jump out of its way. Two retail files: 13CB90.c (setup, the
   bowler, the shell, camera; MP1 13EFB0.c) and 141320.c (from 80106F90: alley, pins, pin players;
   MP1 142EA0.c). .data stays asm; .rodata is carved per file. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/collision.h"

typedef f32 Matrix4f[4][4];

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's work (obj->unk_50, 0x15C): main's minigame player work, collision.h's MgWork (MP1
   BowlPlayerWork 0xE8: MP1 fields from 0x56 on are +1, from 0x90 on +0x10; the held shell is
   unk_C8, the motion table unk_E8). */
typedef MgWork BOPlayerWork;

/* The shell's work (func_80105974, 0xAC; MP1 BowlBallWork 0x6C, fields from 0x58 on +0x1C). */
typedef struct BOBallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[0x1F];
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ char unk_80[0x2C];
} BOBallWork; /* size = 0xAC */

/* Per-pin state (D_80109E50_1441E0_BowlOver[6], indexed by the pin object's work[3]; MP1 BowlPin
   0xA4, without its coins). */
typedef struct BOPin {
    /* 0x00 */ f32 unk_00; /* tilt */
    /* 0x04 */ f32 unk_04; /* fall direction */
    /* 0x08 */ f32 unk_08; /* tilt target */
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s8 unk_16; /* frames since it fell (blinks) */
    /* 0x17 */ u8 unk_17; /* knocked down */
    /* 0x18 */ u8 unk_18; /* fall finished */
    /* 0x19 */ char unk_19[3];
} BOPin; /* size = 0x1C */

/* A pin player's jump and stick state (D_80109F48_1442D8_BowlOver[6]; MP1 BowlJump, same layout). */
typedef struct BOJump {
    /* 0x00 */ f32 unk_00; /* y speed */
    /* 0x04 */ f32 unk_04; /* spin speed */
    /* 0x08 */ f32 unk_08; /* facing */
    /* 0x0C */ f32 unk_0C; /* CPU: last x */
    /* 0x10 */ f32 unk_10; /* CPU: last z */
    /* 0x14 */ s16 unk_14; /* jumping */
    /* 0x16 */ s16 unk_16; /* spin frames */
    /* 0x18 */ s16 unk_18; /* landed */
    /* 0x1A */ s16 unk_1A; /* spinning */
    /* 0x1C */ s16 unk_1C; /* spin direction */
    /* 0x1E */ char unk_1E[2];
    /* 0x20 */ s8 unk_20;    /* stick history slot */
    /* 0x21 */ s8 unk_21[8]; /* stick x history */
    /* 0x29 */ s8 unk_29[8]; /* stick y history */
    /* 0x31 */ s8 unk_31;    /* CPU: jump now */
    /* 0x32 */ char unk_32;
    /* 0x33 */ s8 unk_33; /* stick x */
    /* 0x34 */ s8 unk_34; /* stick y */
    /* 0x35 */ u8 unk_35; /* CPU mode */
    /* 0x36 */ char unk_36[2];
} BOJump; /* size = 0x38 */

/* Alley and pin-deck collision work (0xB4; main's ground work, collision.h GroundWork). */
typedef struct BOGround {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04; /* ground id */
    /* 0x05 */ char unk_05[0xAB];
    /* 0xB0 */ u16* unk_B0; /* an empty pin slot's slot index (func_8010947C_14380C_BowlOver) */
} BOGround; /* size = 0xB4 */

/* Pin-player model table (D_80109C30_143FC0_BowlOver[6], .rodata; MP1 BowlHead): the character's
   directory, its head file in directory 0x1E, and the two node names func_80023DAC_249AC joins. */
typedef struct BOHead {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x20];
    /* 0x28 */ char unk_28[0x20];
} BOHead; /* size = 0x48 */

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

/* Collision probe for func_8002F2C4_2FEC4 (position and a result word). */
typedef struct BOProbe {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s32 hit;
} BOProbe;

#define BO_WORK(obj) ((BOPlayerWork*)(obj)->unk_50)
#define BO_BALL_WORK(obj) ((BOBallWork*)(obj)->unk_50)
#define BO_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* ---------------------------------------------------------------------------------------------
   Data (.data, 13CB90.c: 80109960-80109A40)
   --------------------------------------------------------------------------------------------- */

extern s16 D_80109960_143CF0_BowlOver; /* the shell is out (1) */
extern s32 D_80109964_143CF4_BowlOver;
extern u16 D_80109968_143CF8_BowlOver; /* the shell reached the pins */
extern u16 D_8010996A_143CFA_BowlOver; /* the view went full screen for it */
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
extern s8 D_8010997A_143D0A_BowlOver; /* game state (func_80102E04_13D194_BowlOver) */
extern s32 D_8010997C_143D0C_BowlOver;
extern s32 D_80109980_143D10_BowlOver;
extern u32 D_80109984_143D14_BowlOver; /* intro frames */
extern s32 D_80109988_143D18_BowlOver; /* throw timer (MP1 D_800FD300) */
extern s32 D_8010998C_143D1C_BowlOver; /* bowler state (MP1 D_800FD304) */
extern u16 D_80109990_143D20_BowlOver;
extern s16 D_80109992_143D22_BowlOver;
extern s16 D_80109994_143D24_BowlOver;
extern u8 D_80109996_143D26_BowlOver;
extern u8 D_80109997_143D27_BowlOver;
extern u8 D_80109998_143D28_BowlOver;
extern u16 D_8010999A_143D2A_BowlOver; /* CPU bowler set up */
extern u16 D_8010999C_143D2C_BowlOver; /* CPU: last buttons */
extern s32 D_801099A0_143D30_BowlOver; /* CPU frames */
extern f32 D_801099A4_143D34_BowlOver; /* CPU stick x, -1 none */
extern u8 D_801099A8_143D38_BowlOver;
extern f32 D_801099AC_143D3C_BowlOver;
extern f32 D_801099B0_143D40_BowlOver;
extern f32 D_801099B4_143D44_BowlOver;
extern f32 D_801099B8_143D48_BowlOver;
extern f32 D_801099BC_143D4C_BowlOver;
extern s8 D_801099C0_143D50_BowlOver; /* rolling sounds stopped */
extern s8 D_801099C1_143D51_BowlOver; /* rolling sounds started */
extern Vec D_801099C4_143D54_BowlOver[2]; /* camera viewport scale (640, 480, 511) */
extern Vec D_801099DC_143D6C_BowlOver[2]; /* camera viewport translate */
extern RectF D_801099F4_143D84_BowlOver[2]; /* camera scissor */

/* ---------------------------------------------------------------------------------------------
   Data (.data, 140760.c: 80109A20-80109A40)
   --------------------------------------------------------------------------------------------- */

extern s8 D_80109A20_143DB0_BowlOver;    /* end fade started */
extern f32 D_80109A24_143DB4_BowlOver;   /* shell throw speed (1.47) */
extern s8 D_80109A28_143DB8_BowlOver[8]; /* stick x history */
extern s8 D_80109A30_143DC0_BowlOver[8]; /* stick y history */
extern s8 D_80109A38_143DC8_BowlOver;    /* history index */
extern u32 D_80109A3C_143DCC_BowlOver;   /* random seed */

/* ---------------------------------------------------------------------------------------------
   Data (.data, 141320.c: 80109A40-80109AC0)
   --------------------------------------------------------------------------------------------- */

extern u8 D_80109A40_143DD0_BowlOver; /* alley (0-2; main's D_800FA656) */
extern s8 D_80109A41_143DD1_BowlOver; /* shells left */
extern s8 D_80109A42_143DD2_BowlOver; /* shells left last frame */
extern s8 D_80109A43_143DD3_BowlOver; /* shell icons faded so far */
extern s8 D_80109A44_143DD4_BowlOver[12]; /* shell icon fading ([0..1] used) */
extern s16 D_80109A50_143DE0_BowlOver; /* pins knocked (sound pitch); an unreferenced s16 follows */
extern Vec3f D_80109A54_143DE4_BowlOver[6]; /* pin slot positions; then two unreferenced words (-300.0f, 0.0f) */
extern f32 D_80109AA4_143E34_BowlOver[6]; /* [0]: pin deck back (z) */
extern f32 D_80109ABC_143E4C_BowlOver;    /* pin deck front (z) */

/* ---------------------------------------------------------------------------------------------
   Bss (asm)
   --------------------------------------------------------------------------------------------- */

extern Vec3f D_80109E00_144190_BowlOver;
extern Vec3f D_80109E0C_14419C_BowlOver;
extern u16 D_80109E18_1441A8_BowlOver; /* wait before the results (demo play) */
extern s16 D_80109E1A_1441AA_BowlOver;
extern f32 D_80109E1C_1441AC_BowlOver; /* CPU aim offset by difficulty */
extern s16 D_80109E20_1441B0_BowlOver[]; /* rolling sound handles */
extern s16 D_80109E30_1441C0_BowlOver[8]; /* shell icon alpha */
extern u16 D_80109E40_1441D0_BowlOver[6]; /* pin slot of each pin object (shuffled) */
extern BOPin D_80109E50_1441E0_BowlOver[6];
extern s16 D_80109EF8_144288_BowlOver[40];
extern BOJump D_80109F48_1442D8_BowlOver[6];
extern u16 D_8010A098_144428_BowlOver[2]; /* shell icon sprites */
extern Vec3f D_8010A09C_14442C_BowlOver; /* bowler start position */
extern omObjData* D_8010A0A8_144438_BowlOver; /* the shell */
extern s16 D_8010A0AC_14443C_BowlOver;
extern s8 D_8010A0AE_14443E_BowlOver[4]; /* [0] bowler, [1..3] pin players */
extern omObjData* D_8010A0B8_144448_BowlOver[6]; /* the six pins */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern u16 D_801011FC_101DFC; /* minigame over */
s32 func_80005110_5D10(s32, u16*, ColVtx*, void*); /* face filter */
void func_8002C570_2D170(s16);
void func_80069770_6A370(void);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
void func_800B8070_B8C70(f32 angle, f32* s, f32* c); /* sin and cos */
extern omObjData* D_800FC7B0_FD3B0[];
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u8 D_800FA656;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_8003B6E8_3C2E8(HmfData* arg0);
extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void InitFadeIn(s32, s32);
/* 1AE60.c's esprite slot */
typedef struct BOEspSlot {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* sprite group */
    /* 0x06 */ char unk_06[0x1E];
} BOEspSlot; /* size = 0x24 */
extern BOEspSlot* D_800F93FC_F9FFC;
extern f32 D_8010105C_101C5C;
extern f32 D_80101300_101F00;

void func_8002D4D0_2E0D0(s16 n);
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
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void func_8001AA08_1B608(u16 spriteId, s16 arg1, s16 arg2, s16 arg3); /* sprite fade */
void func_80023DAC_249AC(s16 model, char* part, s16 target, char* targetPart); /* attach a part */
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1); /* hit box */
f32 sqrtf(f32);
f32 __sinf(f32);
f32 __cosf(f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x);
void func_80018CCC_198CC(omObjData* obj, u16 idx, s32 file);
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80020070_20C70(s32);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void CameraScissorSet(s16 camIndex, RectF* arg1);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
u8 rand8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80079868_7A468(void);
s16 PlayMusic(s16);
s32 _CheckFlag(s32);

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
s16 func_801069D0_140D60_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_80106C94_141024_BowlOver(Vec3f* pos, Vec3f* axis, f32 angle, Matrix4f out);
s32 func_80106E8C_14121C_BowlOver(u32 seed);
u32 func_80106F60_1412F0_BowlOver(void);

/* ---------------------------------------------------------------------------------------------
   Overlay functions (141320.c; inferred from registers and MP1 142EA0.c: check them)
   --------------------------------------------------------------------------------------------- */

void func_80106F90_141320_BowlOver(omObjData* obj);
void func_801070DC_14146C_BowlOver(omObjData* obj);
void func_801072F0_141680_BowlOver(omObjData* obj);
void func_80107390_141720_BowlOver(void);
void func_80107570_141900_BowlOver(void);
void func_80107738_141AC8_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_8010782C_141BBC_BowlOver(omObjData* obj, f32 dx, f32 dz);
void func_801079EC_141D7C_BowlOver(omObjData* obj);
void func_80107DB4_142144_BowlOver(omObjData* obj);
void func_801082B8_142648_BowlOver(omObjData* obj, BOJump* jump, u8* sx, u8* sy);
void func_801087A0_142B30_BowlOver(omObjData* obj);
void func_80108DCC_14315C_BowlOver(omObjData* obj);
void func_80108ECC_14325C_BowlOver(omObjData* obj, s32 dir, s32 file, u16 player, u16 slot, u16 pin);
void func_80109148_1434D8_BowlOver(omObjData* obj);
void func_80109354_1436E4_BowlOver(omObjData* obj);
void func_8010947C_14380C_BowlOver(omObjData* obj, u16 slot, s8 pin);
void func_801096A0_143A30_BowlOver(void);
void func_8010977C_143B0C_BowlOver(omObjData* obj);
void func_801097F4_143B84_BowlOver(omObjData* obj);
void func_80109870_143C00_BowlOver(omObjData* obj);
void func_801098EC_143C7C_BowlOver(omObjData* obj);
void func_80109910_143CA0_BowlOver(omObjData* obj);
void func_80109934_143CC4_BowlOver(omObjData* obj);

#endif
