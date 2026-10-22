#ifndef _OVL_19_H
#define _OVL_19_H

/* Overlay 19 (1913A0.c): Bobsled Run (2 vs 2), descended from MP1's ovl_1D_BobsledRun
   (188410.c, BobsledRun.h). Two bobsleds race down one track, one team per half of the screen
   (cameras 0 and 1). One retail file; .data stays asm; .rodata is carved
   ([0x19B500, .rodata, 1913A0]). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"

typedef f32 Matrix4f[4][4];

typedef struct Vec4f {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4f;

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One team (D_8010C048[2], .data; MP1 BRTeam 0x48). */
typedef struct BRTeam {
    /* 0x00 */ f32 progress;  /* 0 at the top .. 1 at the goal (from the sled's height) */
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 roll;      /* camera roll offset */
    /* 0x1C */ s16 state;     /* 0 start, 1 racing, 2 crashed out, 3 goal */
    /* 0x1E */ s16 timer;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u16 sprite;
    /* 0x26 */ u16 sprite2;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 sound;     /* sliding sound handle */
    /* 0x32 */ u8 unk32;
    /* 0x33 */ u8 boost;
    /* 0x34 */ s8 anim;
    /* 0x35 */ s8 player[2];  /* the two players */
    /* 0x37 */ s8 port[2];    /* their controller ports */
    /* 0x39 */ s8 mdl[10];    /* model indices */
    /* 0x43 */ s8 path;       /* which CPU path table */
} BRTeam; /* size = 0x44 */

/* A motion slot of BRWork::unk_E8 (C8E0.c's MgMotion). */
typedef struct BRMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08;
} BRMotion; /* size = 0xC */

/* omObjData::unk_50 of the bobsleds and riders (C8E0.c's MgWork, 0x15C bytes; MP1 BRWork 0xE8:
   fields from MP1 0x90 on are shifted). One pointer, at 0xE8: later fields shift on the host. */
typedef struct BRWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;    /* vertical speed; 1000 = on the ground */
    /* 0x3C */ f32 unk_3C;    /* heading */
    /* 0x40 */ f32 unk_40;    /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;    /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;    /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;     /* ground object */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ s8 unk_57;     /* controller port (MP1 0x56) */
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ s8 unk_59;     /* team (MP1 0x58) */
    /* 0x5A */ char unk_5A[2];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ char unk_6C[0x30];
    /* 0x9C */ f32 unk_9C;    /* MP1 0x90 */
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0xC];
    /* 0xB4 */ f32 unk_B4;    /* MP1 0xA4 */
    /* 0xB8 */ char unk_B8[0xB];
    /* 0xC3 */ s8 unk_C3;     /* MP1 0xB1 */
    /* 0xC4 */ s8 unk_C4;     /* MP1 0xB2 */
    /* 0xC5 */ char unk_C5[7];
    /* 0xCC */ f32 unk_CC;    /* MP1 0xBC */
    /* 0xD0 */ u16 unk_D0;    /* MP1 0xC0 */
    /* 0xD2 */ char unk_D2[0x16];
    /* 0xE8 */ BRMotion* unk_E8; /* [obj->mtncnt] (MP1 0xD8) */
    /* 0xEC */ char unk_EC[0x70];
} BRWork; /* size = 0x15C */

#define BR_WORK(obj) ((BRWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Data (.data, 19AB90.data.s, asm)
   --------------------------------------------------------------------------------------------- */
extern f32 D_8010C040_19ABE0_BobsledRun[2]; /* camera field of view, per team */
extern BRTeam D_8010C048_19ABE8_BobsledRun[2];
extern s16 D_8010C0DC_19AC7C_BobsledRun; /* race time (frames) */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_800FC7B0_FD3B0[];
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7AC_C03AC;
extern f32 D_800BF7C0_C03C0;

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_8000C38C_CF8C(void);
void func_80018F58_19B58(s32);
void func_80029708_2A308(s32);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8000C460_D060(void);
void func_8000C018_CC18(u16);
s16 func_800680D4_68CD4(s32);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002CD6C_2D96C(s32);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_800794F0_7A0F0(s8);
void func_80079684_7A284(s8);
void func_80079128_79D28(void);
s32 func_8008F618_90218(void);
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_8000DA2C_E62C(f32, f32, f32, f32);

/* ---------------------------------------------------------------------------------------------
   Overlay functions (B's half, after 801064F0, inferred from the asm: check)
   --------------------------------------------------------------------------------------------- */
void func_80102800_1913A0_BobsledRun(void);
void func_80102D4C_1918EC_BobsledRun(void);
void func_80102D78_191918_BobsledRun(BRWork* work, f32 x, f32 z, f32 ox, f32 oz);
void func_80102EE0_191A80_BobsledRun(omObjData* obj);
s32 func_801038C4_192464_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z);
void func_80103B4C_1926EC_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, u16 flags, u16 motFile);
void func_80103DDC_19297C_BobsledRun(void);
void func_80103F24_192AC4_BobsledRun(omObjData* obj);
void func_80104084_192C24_BobsledRun(omObjData* obj);
void func_80104490_193030_BobsledRun(omObjData* obj);
void func_80104578_193118_BobsledRun(omObjData* obj);
void func_80104660_193200_BobsledRun(omObjData* obj);
void func_80104748_1932E8_BobsledRun(omObjData* obj);
void func_80104820_1933C0_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team);
void func_80104BE0_193780_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 player, u16 team);
void func_80104EAC_193A4C_BobsledRun(omObjData* obj);
void func_801050F8_193C98_BobsledRun(omObjData* obj);
void func_801051BC_193D5C_BobsledRun(omObjData* obj);
void func_80105344_193EE4_BobsledRun(omObjData* obj);
void func_801054D0_194070_BobsledRun(omObjData* obj);
void func_8010557C_19411C_BobsledRun(omObjData* obj);
void func_8010562C_1941CC_BobsledRun(void);
void func_80105720_1942C0_BobsledRun(void);
void func_80105770_194310_BobsledRun(void);
void func_801059F8_194598_BobsledRun(s16 idx, s16 time);
void func_80105CF0_194890_BobsledRun(void);
void func_80105D30_1948D0_BobsledRun(void);
void func_80105D88_194928_BobsledRun(s32 x, s32 y);
void func_80105F38_194AD8_BobsledRun(s32 x, s32 y);
void func_801060E8_194C88_BobsledRun(omObjData* obj, s16 force, f32 minSpeed, f32 rot, f32 x, f32 y, f32 z);
void func_80106438_194FD8_BobsledRun(s32 team, u8 mdl);
void func_801064F0_195090_BobsledRun(omObjData* obj);
f32 func_80107550_1960F0_BobsledRun(s32 team, f32 value);
void func_801075C8_196168_BobsledRun(omObjData* obj);
s32 func_80107720_1962C0_BobsledRun(omObjData* obj);
void func_801077A4_196344_BobsledRun(omObjData* obj);
void func_80107920_1964C0_BobsledRun(omObjData* obj);
void func_80107C6C_19680C_BobsledRun(omObjData* obj);
void func_80107CF4_196894_BobsledRun(omObjData* obj, Vec3f* normal, f32 turn);
void* func_80107E38_1969D8_BobsledRun(BRWork* work); /* MP1 func_800F6D20: the ground object's work */
void func_80107EA4_196A44_BobsledRun(omObjData* obj);
void func_8010982C_1983CC_BobsledRun(omObjData* obj);
s32 func_80109D94_198934_BobsledRun(omObjData* obj, f32 arg1, s8 arg2);
void func_80109F78_198B18_BobsledRun(omObjData* obj, s8 player, s8 port);
void func_8010A3AC_198F4C_BobsledRun(omObjData* obj);
void func_8010A648_1991E8_BobsledRun(Matrix4f m, Vec3f* pos, Vec3f* axis, f32 angle);
void func_8010A840_1993E0_BobsledRun(omObjData* obj);
void func_8010AB30_1996D0_BobsledRun(s8 team, Vec3f* normal);
void func_8010AC18_1997B8_BobsledRun(omObjData* obj);
void func_8010ADD8_199978_BobsledRun(omObjData* obj, Vec3f* normal);
f32 func_8010AF5C_199AFC_BobsledRun(omObjData* obj, f32 rot, f32 x, f32 y, f32 z);
f32 func_8010B630_19A1D0_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z, f32 oldY);
void func_8010BD18_19A8B8_BobsledRun(omObjData* obj, s16 arg1);

#endif
