#ifndef _OVL_34_H
#define _OVL_34_H

/* Overlay 34 (259900.c): the Chance Time board event, a stand-alone scene (its own omInitObjMan)
   descended from MP1's ovl_01 ChanceTime (src/overlays/ovl_01_ChanceTime/, D51E0.c mostly).
   D_80110060 (_CheckFlag(0x45)) picks between the two variants of the event, as in MP1.
   The unit's .rodata is carved ([0x267360, .rodata, 259900]); .data and .bss stay asm. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/camera.h"
#include "game/gamemes.h"

/* ---- main-segment API used by 34 ---- */

/* func_800615FC_621FC is defined (void) in 5F3B0.c; retail passes (-1, -1) here (MP1's
   func_80055A40_unproto). */
#define func_800615FC_621FC_unproto ((void (*)(s32, s32))func_800615FC_621FC)

void func_800615FC_621FC(void);
void func_800616C4_622C4(void);
void func_8000C018_CC18(u16); /* stores the low byte (C8E0: player object count) */
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C690_D290(void);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_800B3820_B4420(Mtx* arg0); /* guMtxIdent */
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069770_6A370(void);
f32 func_800B7890_B8490(f32); /* cos */
s32 PlaySound(s32);
s16 LoadFormFile(s32, s32);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* 2DE74.c: s8; retail passes 255 */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_80025684_26284(s32 id); /* 26284.c: s16; retail callers re-extend the result */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_800298A4_2A4A4(s16, s32, s32);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
void func_8002C3A0_2CFA0(s16 arg0);
void func_80029A8C_2A68C(s16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_80025554_26154(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
f32 func_80029D0C_2A90C(s16 arg0); /* motion length */
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80079848_7A448(s16 arg0);
f32 HuMathSin(f32);
f32 func_800B75A8_B81A8(f32, f32); /* atan2 */
s32 func_80057480_58080(s32 arg0, s32 arg1, s32 arg2, s32 arg3); /* 58080.c: s16; retail callers re-extend the window id */
void ShowTextWindow(s32 arg0);
void func_8005762C_5822C(s32 arg0);
void func_80057730_58330(s16, s32);
void func_8008D4DC_8E0DC(char* dst, char* src); /* strcpy (8E0DC.c: u8*) */
void func_80089308_89F08(s16, char*, s32); /* window message argument */
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089A48_8A648(s16, s16);
int sprintf(char* dst, const char* fmt, ...);
void func_80061584_62184(void);
void func_80061720_62320(s32 arg0, s32 arg1); /* stores both words (D_800CC990, D_800CC994) */
void func_80061734_62334(void);
void func_80061750_62350(void);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val); /* ((u8*)obj->unk_50)[idx] = val */
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* util.c: (UnkUtil*, ...) loads obj->motion[slot] */

extern s8 D_80102708_103308;
extern u16 D_800F8FE0_F9BE0;           /* player object count (C8E0) */
extern omObjData* D_800FC7B0_FD3B0[];  /* (C8E0) */
extern u16 D_800FC87A_FD47A;           /* player object count */
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern s16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern u8 D_800FDBCA_FE7CA;            /* matrix set count (30560) */
extern s32 D_800F8FD0_F9BD0;           /* scene state (C8E0 func_8000C3C8 copies it) */

/* ---- 34 work types ---- */

/* A motion slot of CTPlayerWork::unk_E8 (C8E0.c's MgMotion). */
typedef struct CTMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08;
} CTMotion; /* size = 0xC */

/* omObjData::unk_50 of the player objects and of the two block holders (C8E0.c's MgWork,
   0x15C bytes; MP1 CTPlayerWork). One pointer, at 0xE8: later fields shift on the host. */
typedef struct CTPlayerWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34; /* height of the hit box centre (fork D) */
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[0x13];
    /* 0x57 */ s8 unk_57; /* controller port */
    /* 0x58 */ char unk_58;
    /* 0x59 */ s8 unk_59; /* player index (fork D) */
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ u8 unk_5B;
    /* 0x5C */ s32 unk_5C; /* flags (& 6 tested) */
    /* 0x60 */ char unk_60[0x88];
    /* 0xE8 */ CTMotion* unk_E8; /* [obj->mtncnt] */
    /* 0xEC */ char unk_EC[0x70];
} CTPlayerWork; /* size = 0x15C */

#define CT_PWORK(obj) ((CTPlayerWork*)(obj)->unk_50)

/* ---- .data (267160.data.s, asm) ---- */
extern s8 D_80110060_267160_ChanceTime; /* _CheckFlag(0x45): the event's second variant */
extern s8 D_80110062_267162_ChanceTime; /* state of the two block holders (1 spin, 2 stop) */
extern s8 D_80110063_267163_ChanceTime;
extern s8 D_80110064_267164_ChanceTime;
extern s8 D_80110065_267165_ChanceTime;
extern s8 D_80110066_267166_ChanceTime;
extern s8 D_80110067_267167_ChanceTime;
extern s8 D_80110068_267168_ChanceTime;
extern u32 D_801100F0_2671F0_ChanceTime; /* func_80102E4C frame counter */
extern s32 D_801100F4_2671F4_ChanceTime;
extern u16 D_80110150_267250_ChanceTime[3]; /* the three blocks stopped (MP1 D_801012B0) */
extern s8 D_801100F8_2671F8_ChanceTime;
extern s8 D_801100F9_2671F9_ChanceTime;
extern s8 D_801100FA_2671FA_ChanceTime;
extern s8 D_801100FB_2671FB_ChanceTime;
extern s8 D_801100FC_2671FC_ChanceTime;
extern f32 D_80110100_267200_ChanceTime;
extern s16 D_80110104_267204_ChanceTime; /* 0xFF: title alpha; retail reads (u8) as D_80110105 */
extern GAMEMES* D_80110108_267208_ChanceTime; /* the title message */
/* 0x80110070: the second variant's holder walks from path[0] (0x80110074) to path[1]; splat
   labels path[1] D_80110080 (retail addresses both from &path[1]). */
typedef struct CTPath70 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec path[2];
} CTPath70;
extern CTPath70 D_80110070_267170_ChanceTime;
/* The block holders walk from [0] to [1] (x mirrored for the second); splat labels [1]
   D_80110098, and retail addresses [0] from &[1]. */
extern Vec D_8011008C_26718C_ChanceTime[2];
extern Vec D_801100A4_2671A4_ChanceTime; /* the two players' places (x mirrored for the second) */
extern Vec D_801100B0_2671B0_ChanceTime; /* where they walk to (x mirrored) */
extern s8 D_801100BC_2671BC_ChanceTime;
extern u32 D_8011010C_26720C_ChanceTime; /* func_80103ADC state */
extern s32 D_80110110_267210_ChanceTime; /* func_80103ADC sub-state */
extern s32 D_80110114_267214_ChanceTime; /* func_80103ADC frame counter */
extern s32 D_80110118_267218_ChanceTime;
extern s16 D_8011011C_26721C_ChanceTime;
extern u32 D_80110120_267220_ChanceTime; /* func_801052B4 state */
extern s32 D_80110124_267224_ChanceTime; /* func_801052B4 frame counter */
extern s8 D_80110128_267228_ChanceTime; /* the two players arrived */
extern s8 D_80110129_267229_ChanceTime;
extern s8 D_80110156_267256_ChanceTime;
extern u8 D_80110180_267280_ChanceTime; /* the two chosen players (MP1 D_801012E0/E1) */
extern u8 D_80110181_267281_ChanceTime;
extern u8 D_80110182_267282_ChanceTime; /* the outcome (MP1 D_801012E2) */
extern char* D_801100C8_2671C8_ChanceTime[6]; /* [character]: "MARIO" .. "DK" */
extern char D_80110214_267314_ChanceTime[]; /* SJIS window words for D_80110067 */
extern char D_80110224_267324_ChanceTime[];
extern char D_80110228_267328_ChanceTime[];
extern u8 D_80110230_267330_ChanceTime[]; /* SJIS "ＣＨＡＮＣＥＴＩＭＥ？" */
extern u8 D_80110248_267348_ChanceTime[]; /* SJIS "ＣＨＡＮＣＥＴＩＭＥ" */

/* ---- .bss (ovl_34_bss.bss.s) ---- */
extern s16 D_801106B0_2677B0_ChanceTime; /* title message */
extern s16 D_801106B2_2677B2_ChanceTime; /* sound */
extern f32 D_801106B4_2677B4_ChanceTime; /* sway angle of the scenery copies */
extern f32 D_801106B8_2677B8_ChanceTime; /* sway damping */
extern Vec D_801106C0_2677C0_ChanceTime[10]; /* the ten scenery copies: position */
extern Vec D_80110738_267838_ChanceTime[10]; /* rotation */
extern s16 D_801107B0_2678B0_ChanceTime; /* sound */
extern char D_801107B8_2678B8_ChanceTime[16]; /* the outcome window's sprintf buffers */
extern char D_801107C8_2678C8_ChanceTime[16];
extern char D_801107D8_2678D8_ChanceTime[16];
extern s8 D_80110850_267950_ChanceTime; /* swap the names' order */
extern omObjData* D_80110908_267A08_ChanceTime;
extern omObjData* D_8011090C_267A0C_ChanceTime; /* the two block holders */
extern omObjData* D_80110910_267A10_ChanceTime;
#define HOLDER0 D_8011090C_267A0C_ChanceTime
#define HOLDER1 D_80110910_267A10_ChanceTime
extern s16 D_80110914_267A14_ChanceTime; /* three models (0x440009..B) */
extern s16 D_80110916_267A16_ChanceTime;
extern s16 D_80110918_267A18_ChanceTime;
/* CPU controller state per controller port (MP1 D_80101AB8 / AB2 / ACE / A9C) */
extern s16 D_80110B14_267C14_ChanceTime[4]; /* buttons pressed */
extern s8 D_80110D56_267E56_ChanceTime[4]; /* stick x */
extern s8 D_80110D62_267E62_ChanceTime[2]; /* the two players' D_800FFFD8 indices (MP1 D_80101AA4) */
extern s8 D_80110D6A_267E6A_ChanceTime[4]; /* player order */
extern s8 D_80110D6E_267E6E_ChanceTime[4]; /* stick y */
extern s16 D_80110D72_267E72_ChanceTime[4]; /* buttons held */
/* The panels' objects; retail writes the third (D_80110D88) as [2] in one branch. */
extern omObjData* D_80110D80_267E80_ChanceTime[2];
extern omObjData* D_80110D88_267E88_ChanceTime;

/* fork D */
/* omObjData::unk_50 of the hit-box objects (0xB4 bytes; C8E0 func_8000BF24 writes 0x06, 0x14,
   0xA0..0xAC). */
typedef struct CTBoxWork {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk_05[3];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0xA8];
} CTBoxWork; /* size = 0xB4 */

void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1); /* hit box */
void func_8000BFF0_CBF0(omObjData* obj);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A708_1B308(u16, u16);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);

extern s16 D_80110198_267298_ChanceTime[3]; /* the three blocks' scale animation running */
extern s16 D_801101A0_2672A0_ChanceTime[3]; /* its frame (0..16) */
extern s8 D_801101BC_2672BC_ChanceTime[3]; /* it finished */
extern s8 D_801101C0_2672C0_ChanceTime;
extern u16 D_801109C0_267AC0_ChanceTime; /* sprite */
extern s16 D_801109C2_267AC2_ChanceTime;

extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup (MP1 func_8000979C) */
void func_8000CC74_D874(omObjData* obj, s16 model, s32 arg2);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion (MP1 func_8001874C) */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
extern f32 D_800BF7A4_C03A4; /* jump speed (MP1 D_800B8964) */
extern f32 D_800BF7A8_C03A8; /* MP1 D_800B8968 */
/* Per character (0x18 bytes; ovl_00 D57F0.c's UnkDebug0): motion and model file bases. */
typedef struct CTCharFiles {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* motion file base (MP1 D_800C59AC unk_00) */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C; /* MP1 D_800C59AC unk_04 */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
} CTCharFiles;
extern CTCharFiles D_800CD438_CE038[];

extern s8 D_80110061_267161_ChanceTime; /* the holder landed */
extern s8 D_801101D7_2672D7_ChanceTime; /* func_8010FC18 state */
extern s8 D_801101D8_2672D8_ChanceTime; /* func_8010FD28 state */
extern s8 D_801101D9_2672D9_ChanceTime; /* func_8010FF1C state */
extern s32 D_801101DC_2672DC_ChanceTime; /* func_8010FF1C frame counter */
extern CTPlayerWork* D_801109DC_267ADC_ChanceTime; /* the walk processes' player work */
extern CTPlayerWork* D_801109E0_267AE0_ChanceTime;
extern CTPlayerWork* D_801109E4_267AE4_ChanceTime;
/* The CPU holder's block run (MP1 D_80101266, D_80101268, D_8010126C, D_8010126A) */
extern u16 D_801101D0_2672D0_ChanceTime; /* the block order is chosen */
extern u16 D_801101D2_2672D2_ChanceTime; /* buttons last frame */
extern u16 D_801101D4_2672D4_ChanceTime; /* 1: under a block, waiting */
extern u8 D_801101D6_2672D6_ChanceTime; /* blocks hit so far */
extern u8 D_801109D0_267AD0_ChanceTime[3]; /* block order (MP1 D_801016F8); [2] MP1 D_801016FA */
extern s32 D_801109D4_267AD4_ChanceTime; /* wait counter (MP1 D_801016F4) */
extern s16 D_801109D8_267AD8_ChanceTime; /* wait length (MP1 D_801016FC) */
/* saved real controller state per port, restored after the update (MP1 D_80101AA6 ...) */
extern u16 D_80110D5A_267E5A_ChanceTime[4];
extern s8 D_80110B10_267C10_ChanceTime[4];
extern s8 D_80110D66_267E66_ChanceTime[4];
extern u16 D_801109F0_267AF0_ChanceTime[4];

/* ---- overlay functions (all 62; signatures past fork A's range are inferred) ---- */
/* fork A */
void func_80102800_259900_ChanceTime(void); /* scene setup */
void func_80102E4C_259F4C_ChanceTime(omObjData* obj); /* event flow (MP1 func_800F6B00) */
void func_80103398_25A498_ChanceTime(omObjData* obj);
void func_801036C4_25A7C4_ChanceTime(omObjData* obj);
void func_80103714_25A814_ChanceTime(omObjData* obj);
void func_80103A64_25AB64_ChanceTime(omObjData* obj);
void func_80103ADC_25ABDC_ChanceTime(omObjData* obj, s8 arg1);
void func_801052B4_25C3B4_ChanceTime(omObjData* obj);
void func_801060E0_25D1E0_ChanceTime(void); /* process */
/* fork B */
s32 func_80106434_25D534_ChanceTime(s8 arg0);
void func_80106548_25D648_ChanceTime(omObjData* obj);
s32 func_80106604_25D704_ChanceTime(omObjData* obj, s8 dir, s16 count);
s32 func_80106B5C_25DC5C_ChanceTime(omObjData* obj, s16 a, s16 b);
s8 func_80107594_25E694_ChanceTime(omObjData* obj);
void func_801077D8_25E8D8_ChanceTime(omObjData* obj);
void func_80107B00_25EC00_ChanceTime(omObjData* obj);
void func_80109718_260818_ChanceTime(s8 arg0, s8 arg1);
s8 func_801097F8_2608F8_ChanceTime(s8 arg0, s8 arg1);
void func_8010985C_26095C_ChanceTime(void); /* process */
s8 func_80109CC4_260DC4_ChanceTime(s16 arg0, s16 arg1);
/* fork C */
void func_80109D84_260E84_ChanceTime(void); /* process */
void func_8010B02C_26212C_ChanceTime(omObjData* obj);
void func_8010B214_262314_ChanceTime(omObjData* obj);
void func_8010B28C_26238C_ChanceTime(void); /* process */
void func_8010B328_262428_ChanceTime(void); /* process */
void func_8010B3C4_2624C4_ChanceTime(s16 arg0, s16* arg1);
void func_8010B7F8_2628F8_ChanceTime(void); /* process */
void func_8010BB0C_262C0C_ChanceTime(s16 arg0, s16* arg1, s16* arg2);
void func_8010BB74_262C74_ChanceTime(void); /* process */
void func_8010BF28_263028_ChanceTime(omObjData* obj);
void func_8010BF50_263050_ChanceTime(void);
void func_8010BF7C_26307C_ChanceTime(omObjData* obj);
void func_8010BF98_263098_ChanceTime(omObjData* obj);
void func_8010BFB4_2630B4_ChanceTime(omObjData* obj);
void func_8010BFD0_2630D0_ChanceTime(omObjData* obj);
void func_8010BFEC_2630EC_ChanceTime(omObjData* obj);
void func_8010C008_263108_ChanceTime(omObjData* obj);
void func_8010C024_263124_ChanceTime(omObjData* obj);
void func_8010C080_263180_ChanceTime(omObjData* obj);
void func_8010C09C_26319C_ChanceTime(void);
void* func_8010C268_263368_ChanceTime(void);
void func_8010C44C_26354C_ChanceTime(omObjData* obj, s8 arg1);
/* fork D */
void func_8010CCF4_263DF4_ChanceTime(omObjData* obj, s8 arg1);
s32 func_8010DFF8_2650F8_ChanceTime(omObjData* obj, f32 size, omObjData* other);
void func_8010E0D4_2651D4_ChanceTime(omObjData* obj);
void func_8010E214_265314_ChanceTime(omObjData* obj);
void func_8010E440_265540_ChanceTime(omObjData* obj);
void func_8010E668_265768_ChanceTime(omObjData* obj);
void func_8010E71C_26581C_ChanceTime(omObjData* obj);
void func_8010E7C0_2658C0_ChanceTime(omObjData* obj);
void func_8010EED0_265FD0_ChanceTime(omObjData* obj);
void func_8010EF84_266084_ChanceTime(omObjData* obj, u32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_8010F304_266404_ChanceTime(omObjData* obj);
void func_8010F4B4_2665B4_ChanceTime(omObjData* obj, u32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_8010F760_266860_ChanceTime(omObjData* obj);
void func_8010F82C_26692C_ChanceTime(omObjData* obj);
void func_8010F8F8_2669F8_ChanceTime(omObjData* obj);
void func_8010F9C4_266AC4_ChanceTime(s8* state, s8 target);
void func_8010FC18_266D18_ChanceTime(void); /* process */
void func_8010FD28_266E28_ChanceTime(void); /* process */
void func_8010FE50_266F50_ChanceTime(s16 arg0);
void func_8010FF1C_26701C_ChanceTime(void); /* process */

#endif
