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
    /* 0x39 */ s8 mdl[7];     /* model indices */
    /* 0x40 */ s8 path;       /* which CPU path table (MP1 0x43) */
    /* 0x41 */ s8 unk41;
    /* 0x42 */ u8 unk42;
    /* 0x43 */ u8 unk43;
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
    /* 0x5A */ s8 unk_5A;     /* character model */
    /* 0x5B */ u8 unk_5B;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ char unk_6C[8];
    /* 0x74 */ s32 unk_74[6]; /* stick samples, (x << 16) | y (MP1 0x6C) */
    /* 0x8C */ char unk_8C[4];
    /* 0x90 */ Vec3f unk_90;  /* ground normal (MP1 0x84) */
    /* 0x9C */ f32 unk_9C;    /* MP1 0x90 */
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0xC];
    /* 0xB4 */ f32 unk_B4;    /* MP1 0xA4 */
    /* 0xB8 */ char unk_B8[0xB];
    /* 0xC3 */ s8 unk_C3;     /* MP1 0xB1 */
    /* 0xC4 */ s8 unk_C4;     /* MP1 0xB2 */
    /* 0xC5 */ u8 unk_C5;
    /* 0xC6 */ s16 unk_C6;    /* MP1 0xB4 */
    /* 0xC8 */ char unk_C8[4];
    /* 0xCC */ f32 unk_CC;    /* MP1 0xBC */
    /* 0xD0 */ u16 unk_D0;    /* MP1 0xC0 */
    /* 0xD2 */ char unk_D2[0x16];
    /* 0xE8 */ BRMotion* unk_E8; /* [obj->mtncnt] (MP1 0xD8) */
    /* 0xEC */ char unk_EC[0x70];
} BRWork; /* size = 0x15C */

/* Work of the course object (func_80027154_27D54(0xB4); MP1 BRGround 0x2C, fields 0x04/0x05
   moved to 0x03/0x04). No pointers. */
typedef struct BRGround {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;     /* ground id (BRWork::unk_53) */
    /* 0x05 */ char unk_05;
    /* 0x06 */ u16 unk_06;    /* flags: 0x1A = flat floor (height unk_14) */
    /* 0x08 */ f32 unk_08;    /* slope drag */
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ f32 unk_10;    /* sideways normal scale (MP1 0x0C) */
    /* 0x14 */ f32 unk_14;    /* flat floor height (MP1 0x10) */
    /* 0x18 */ char unk_18[0x9C];
} BRGround; /* size = 0xB4 */

/* Speed history of one team's camera (bss D_8010CA38 / D_8010CB48, 0x110 apart). Retail
   addresses the samples by their own labels (D_8010CADC / D_8010CBEC). */
typedef struct BRHist {
    /* 0x00 */ s32 idx;
    /* 0x04 */ f32 unk04[40];
    /* 0xA4 */ f32 samples[20]; /* also D_8010CADC / D_8010CBEC */
} BRHist; /* size = 0xF4 */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct BRCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C; /* its model file */
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} BRCharData; /* size = 0x18 */
extern BRCharData D_800CD438_CE038[];

#define BR_WORK(obj) ((BRWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Data (.data, 19AB90.data.s, asm)
   --------------------------------------------------------------------------------------------- */
extern f32 D_8010BFF0_19AB90_BobsledRun; /* camera pitch */
extern s8 D_8010BFF4_19AB94_BobsledRun; /* winning team, -1 none yet */
extern s8 D_8010BFF5_19AB95_BobsledRun; /* result: -1 racing, -2 both crashed, -3 time up */
extern u8 D_8010BFF8_19AB98_BobsledRun[4]; /* background models' alpha */
extern u8 D_8010BFFC_19AB9C_BobsledRun[4]; /* their alpha step (+4 / -4) */
extern f32 D_8010C000_19ABA0_BobsledRun[3]; /* background models' rotation */
extern f32 D_8010C00C_19ABAC_BobsledRun[3]; /* their spin speed */
extern Vec3f D_8010C018_19ABB8_BobsledRun[3]; /* their positions */
extern s8 D_8010C03C_19ABDC_BobsledRun[4]; /* each player's team */
extern f32 D_8010C040_19ABE0_BobsledRun[2]; /* camera field of view, per team */
extern BRTeam D_8010C048_19ABE8_BobsledRun[2];
extern s16 D_8010C0DC_19AC7C_BobsledRun; /* race time (frames) */
/* Sound handles kept as s32; retail reads the low half (D_8010C0E2 / D_8010C0E6). */
extern s32 D_8010C0E0_19AC80_BobsledRun;
extern s32 D_8010C0E4_19AC84_BobsledRun;
extern f32 D_8010C0E8_19AC88_BobsledRun[6]; /* track section i is drawn from this progress */
extern f32 D_8010C100_19ACA0_BobsledRun[6]; /* ... to this one */
extern u32 D_8010C118_19ACB8_BobsledRun;
extern s32 D_8010C11C_19ACBC_BobsledRun;
extern s32 D_8010C120_19ACC0_BobsledRun;
extern s32 D_8010C124_19ACC4_BobsledRun;
extern s32 D_8010C128_19ACC8_BobsledRun;
extern s32 D_8010C12C_19ACCC_BobsledRun;
extern s32 D_8010C130_19ACD0_BobsledRun;
extern s32 D_8010C134_19ACD4_BobsledRun; /* winner's camera height offset (stays 25: s32 += 0.5f) */

/* ---------------------------------------------------------------------------------------------
   Bss (ovl_19_bss)
   --------------------------------------------------------------------------------------------- */
extern u16 D_8010C9F0_19B590_BobsledRun; /* progress bar: track piece */
extern u16 D_8010C9F2_19B592_BobsledRun; /* progress bar: flag */
extern u16 D_8010C9F4_19B594_BobsledRun; /* progress bar: goal */
extern s16 D_8010C9F6_19B596_BobsledRun; /* time digits (race) */
extern s16 D_8010C9F8_19B598_BobsledRun; /* time digits (record) */
extern s16 D_8010C9FA_19B59A_BobsledRun[2]; /* time display groups: race, record */
extern Vec3f D_8010CA20_19B5C0_BobsledRun[2]; /* per-team shove direction */
extern BRHist D_8010CA38_19B5D8_BobsledRun;
extern f32 D_8010CADC_19B67C_BobsledRun[20];
extern BRHist D_8010CB48_19B6E8_BobsledRun;
extern f32 D_8010CBEC_19B78C_BobsledRun[20];
extern s32 D_8010CB30_19B6D0_BobsledRun[4]; /* per player: the character's motion file 0x4E */
extern u16 D_8010CB40_19B6E0_BobsledRun; /* team 1's progress-bar sled */
extern u8 D_8010CB42_19B6E2_BobsledRun[3]; /* the three background models */
extern u16 D_8010CC3C_19B7DC_BobsledRun; /* progress-bar frame (hidden) */
extern u16 D_8010CC3E_19B7DE_BobsledRun; /* team 0's progress-bar sled */

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
u16 func_800680D4_68CD4(s32); /* the minigame record (time) */
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
u16 func_80078EA8_79AA8(void);
extern u8 D_80102720_103320;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_801011FC_101DFC;
void func_8000C3C8_CFC8(void);
void func_8000C3B8_CFB8(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80079848_7A448(s16 arg0);
void func_80079614_7A214(s16 time); /* music fade-out */
void GWMgRecordSet(s32, u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
extern f32 D_800F94A0_FA0A0;
extern f32 D_80101308_101F08;
extern f32 D_8010105C_101C5C;
extern f32 D_80101300_101F00;
extern u8 D_800BF799_C0399;
void func_80009684_A284(f32, f32, f32);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
s16 LoadFormFile(s32, s32);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_8003C8E0_3D4E0(s16);
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
void func_8000BE74_CA74(omObjData*, f32);
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BEBC_CABC(omObjData*, f32);
void func_8000BEC8_CAC8(omObjData*, f32);
void func_8000BED4_CAD4(omObjData*, f32);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
f32 func_8002D958_2E558(f32); /* wraps an angle */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
u16 func_80018A30_19630(s32, s32); /* model load */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029EDC_2AADC(s16, s32);
void func_8000C004_CC04(omObjData*);
void func_8000BFF0_CBF0(omObjData*);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y); /* sprite scale */
void espDispOff(u16);
void* DataRead(s32 dirAndFile);
void DataClose(void* data);
s16 SprAnimRead(void*);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_8001A340_1AF40(s16, f32, f32, f32);
s16 func_80079798_7A398(s16 sfx, s16 player); /* play a sound effect for a player */
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion); /* C8E0.c: player motion */
void func_80029E80_2AA80(s16, s32, s32);
extern f32 D_800BF7A4_C03A4; /* jump speed (MP1 D_800B8964) */
extern f32 D_800BF7D0_C03D0; /* MP1 D_800B8990 */
extern f32 D_800BF7D4_C03D4; /* MP1 D_800B8994 */
f32 func_8000312C_3D2C(omObjData* obj, f32 rot, f32 x, f32 y, f32 z); /* ground height, 65536.0f = none */
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80019E04_1AA04(omObjData* obj, s32 idx, u16 motion);
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z); /* rotate matrix */
void func_8002D9AC_2E5AC(Vec3f*); /* normalize */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_80025718_26318(s16, s16, s16);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val); /* ((u8*)obj->unk_50)[idx] = val */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* MP1 func_8000979C */

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
void func_80104820_1933C0_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, s32 chr);
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
s16 func_80105D88_194928_BobsledRun(s32 x, s16 y);
s16 func_80105F38_194AD8_BobsledRun(s32 x, s16 y);
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
BRGround* func_80107E38_1969D8_BobsledRun(BRWork* work); /* MP1 func_800F6D20: the ground object's work */
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

/* MG19-B */
#include "game/pad.h"
extern s8 ContStkX[4];
extern s8 ContStkY[4];
f64 fabs(f64);
void func_800797DC_7A3DC(s16 sfx, s16 player);
extern s16 D_800FD7FC_FE3FC; /* MP1 D_800F370C */
extern f32 D_8010C0D0_19AC70_BobsledRun; /* strongest shove, team 0 */
extern f32 D_8010C0D4_19AC74_BobsledRun; /* team 1 */
extern s32 D_8010C0D8_19AC78_BobsledRun; /* finish banner shown */
extern f32 D_8010C144_19ACE4_BobsledRun[2]; /* camera tilt, per team */
void func_8000776C_836C(omObjData* obj); /* MP1 func_80005A04 */
void func_8000CE80_DA80(s16* x, s16* y);
s32 func_8000CDC8_D9C8(omObjData* obj, s16 x, s16 y);
s32 func_80019000_19C00(omObjData* obj); /* MP1 func_80017A60 */
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_8000C584_D184(BRWork* work, s32 state);
void func_8000C610_D210(BRWork* work, s32 arg1);
void func_8001AA08_1B608(u16 spriteId, s16 arg1, s16 arg2, s16 arg3); /* sprite fade */
s32 PlaySound(s32);
/* A gate edge, two ColVtx at 0x8010C15C (inside D_8010C144's splat range); retail addresses it
   from the first one's y (D_8010C15E): [-1..1] = first, [2..4] = second. */
extern s16 D_8010C15E_19ACFE_BobsledRun[];
extern Vec3f D_8010C168_19AD08_BobsledRun[6]; /* CPU aim points behind the gate (x 0 = end) */
extern Vec3f D_8010C1BC_19AD5C_BobsledRun[82]; /* CPU path, BRTeam::path != 0 */
extern Vec3f D_8010C4F8_19B098_BobsledRun[82]; /* CPU path, BRTeam::path == 0 */
extern Vec3f D_8010C8C4_19B464_BobsledRun[6]; /* CPU brake zones (top y, bottom y, speed / 80) */
extern Vec3f D_8010C90C_19B4AC_BobsledRun[6];
void func_800B8070_B8C70(f32 angle, f32* s, f32* c); /* sin and cos */
extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near (7AA60.c) */
void Hu3DCamSetPositionOrientation(s16, Vec3f*, Vec3f*, Vec3f*);
void Hu3DCamUpdateMtx(s16 camIndex);
extern f32 D_8010C140_19ACE0_BobsledRun; /* camera pitch on level ground */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
extern u8 D_800BF794_C0394; /* collision: the course object (MP1 D_800B8954) */
extern u8 D_800BF798_C0398; /* MP1 D_800B8958 */
extern ColVtx* D_8010CA00_19B5A0_BobsledRun; /* last floor face's vertices */
extern ColVtx* D_8010CA04_19B5A4_BobsledRun;
extern ColVtx* D_8010CA08_19B5A8_BobsledRun;
extern u16 D_8010CA0C_19B5AC_BobsledRun; /* and their indices */
extern u16 D_8010CA0E_19B5AE_BobsledRun;
extern u16 D_8010CA10_19B5B0_BobsledRun;
s32 func_80006F34_7B34(omObjData* obj, Vec4f* probe, s32, s32); /* MP1 func_80004D1C */
f32 func_800023CC_2FCC(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal); /* MP1 func_800051D4 */
s32 func_8000DC10_E810(Vec4f* probe, BRGround* gw); /* MP1 func_8000A910 */
s32 func_80005110_5D10(s32, u16*, ColVtx*, void*); /* face filter */
void func_8002F2C4_2FEC4(s16 model, s32* list, void* filter, void* probe); /* collect the model's faces */
u16* func_8002F848_30448(s32* list); /* next face, NULL at the end */
f32 func_8002DBA4_2E7A4(f32 x, f32 y, f32 z, ColVtx* verts, u16* tri); /* height on a face */
void func_8002DA3C_2E63C(ColVtx* a, ColVtx* b, ColVtx* c, Vec3f* n); /* face normal */
f32 func_8002DB3C_2E73C(f32 x, f32 z, ColVtx* a, ColVtx* b); /* side of the edge a-b */
f32 func_80029E3C_2AA3C(s16); /* motion frame, -1 at the end */
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void espDispOn(u16);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_800796F0_7A2F0(s16 sound, s16 pitch);

#endif
