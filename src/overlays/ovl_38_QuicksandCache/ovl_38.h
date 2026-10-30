#ifndef _OVL_38_H
#define _OVL_38_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

typedef struct QCCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} QCCharData;
extern QCCharData D_800CD438_CE038[];

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800BF7A4_C03A4;
extern u16 D_800BF7EC_C03EC[][14]; /* per player sound ids, index 0 of ... */
extern omObjData* D_800F9CE0_FA8E0[];
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
void func_80000530_1130(omObjData* obj);
void func_8000BF8C_CB8C(omObjData*, s32, f32);
void func_800B3E20_B4A20(void*, Vec3f*);
void func_800B6340_B6F40(void*, Vec3f*, void*);
void HmfModelObjAttrSet(s16, s32, s32);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16, s16, s32);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80007790_8390(omObjData* obj);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BEBC_CABC(omObjData*, f32);
void func_8000BEC8_CAC8(omObjData*, f32);
void func_8000C004_CC04(omObjData*);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C11C_CD1C(omObjData*, s32, s32, s32);
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
u16 func_80018A30_19630(s32, s32);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_80021198_21D98(s16 index, u16 arg1);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80023DAC_249AC(s16 model, char* part, s16 target, char* targetPart);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32, s32);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s32 func_80029E14_2AA14(s16 arg0);
void func_8002A00C_2AC0C(s16);
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069770_6A370(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732FC_73EFC(u32 arg0, s32 arg1, s32 arg2);
u16 func_80078EA8_79AA8(void);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800797DC_7A3DC(s32, s16);
void func_80079868_7A468(void);
void func_800799A4_7A5A4(s16, s32);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 func_800B1830_B2430(f32);
void func_800B2060_B2C60(f32 (*)[4], f32, f32, f32);
f32 func_800B75A8_B81A8(f32, f32);
f32 func_800B7890_B8490(f32);
f64 func_800B80D0_B8CD0(f64);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);


/* Player work's own block, MgWork.unk_158, 0x5C bytes. */
typedef struct QCWork {
    /* 0x00 */ s8 unk_00;       /* swallowed */
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ char unk_03;
    /* 0x04 */ s32 unk_04[3];
    /* 0x10 */ s32 unk_10[3];
    /* 0x1C */ Vec3f unk_1C;    /* sink offset */
    /* 0x28 */ f32 unk_28;      /* distance from the centre */
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s8 unk_30;       /* CPU: side */
    /* 0x31 */ u8 unk_31;
    /* 0x32 */ u8 unk_32;
    /* 0x33 */ u8 unk_33;       /* CPU: goal */
    /* 0x34 */ u8 unk_34;       /* sand ring */
    /* 0x35 */ s8 unk_35;       /* CPU stick */
    /* 0x36 */ s8 unk_36;
    /* 0x37 */ char unk_37;
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u16 unk_3A;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ char unk_3E[2];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ u16 unk_48;
    /* 0x4A */ s16 unk_4A[4];
    /* 0x52 */ s16 unk_52[4];
    /* 0x5A */ char unk_5A[2];
} QCWork; /* size = 0x5C */

/* Sand pit's work (D_80108034), 0x28 bytes: three rings of quicksand. */
typedef struct QCSand {
    /* 0x00 */ f32 unk_00[3];   /* angle */
    /* 0x0C */ f32 unk_0C[3];   /* texture scroll */
    /* 0x18 */ f32 unk_18[3];   /* turning speed */
    /* 0x24 */ f32 unk_24;      /* the solo player's stick */
} QCSand; /* size = 0x28 */

/* Coin / item actor: ColActorWork, whose unk_55 here is the effect's model slot and unk_56 a serial. */
typedef struct QCActor {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ char unk_5C[0x1C];
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ char unk_80[4];
    /* 0x84 */ s32 unk_84[9];
    /* 0xA8 */ char unk_A8[4];
} QCActor; /* size = 0xAC */

/* 0x48 bytes each, 20 of them; only entry 0's unk_04 (the sprite group) is used. */
typedef struct QCSpr {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08[6];
    /* 0x20 */ s16 unk_20[12];
    /* 0x38 */ s32 unk_38[4];
} QCSpr; /* size = 0x48 */

/* Score counter, one per player. */
typedef struct QCScore {
    /* 0x00 */ u16 unk_00;      /* target */
    /* 0x02 */ u16 unk_02;      /* shown */
    /* 0x04 */ u16 unk_04;      /* pop state */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;      /* pop angle */
} QCScore; /* size = 0xC */

/* .data, 27A330.c */
extern s8 D_80107770_27F2A0_QuicksandCache;
extern s8 D_80107771_27F2A1_QuicksandCache;
extern s8 D_80107772_27F2A2_QuicksandCache;
extern s8 D_80107773_27F2A3_QuicksandCache;
extern s8 D_80107774_27F2A4_QuicksandCache;
extern s8 D_80107776_27F2A6_QuicksandCache;
extern s8 D_80107777_27F2A7_QuicksandCache;
extern u32 D_80107778_27F2A8_QuicksandCache;
extern s8 D_8010777C_27F2AC_QuicksandCache;
extern s8 D_8010777D_27F2AD_QuicksandCache;
extern s8 D_8010777E_27F2AE_QuicksandCache;
extern s8 D_8010777F_27F2AF_QuicksandCache;
extern s8 D_80107780_27F2B0_QuicksandCache;
extern s32 D_80107784_27F2B4_QuicksandCache;
extern u32 D_80107788_27F2B8_QuicksandCache;
extern u32 D_8010778C_27F2BC_QuicksandCache;
extern const f32 D_80107910_27F440_QuicksandCache[3];
extern const f32 D_8010791C_27F44C_QuicksandCache[3];
extern const s32 D_80107960_27F490_QuicksandCache[6];
extern const u16 D_80107978_27F4A8_QuicksandCache[4][2];
extern const u16 D_80107988_27F4B8_QuicksandCache[4][2];
extern const u16 D_80107998_27F4C8_QuicksandCache[4][2];
extern const u16 D_801079A8_27F4D8_QuicksandCache[4][2];
extern const s8 D_801079B8_27F4E8_QuicksandCache[8];
extern const s16 D_80107818_27F348_QuicksandCache[4][6];
extern const s8 D_80107848_27F378_QuicksandCache[4][6];
extern char* D_80107790_27F2C0_QuicksandCache[6];
extern char* D_801077A8_27F2D8_QuicksandCache;
extern s8 D_801077AC_27F2DC_QuicksandCache;
extern s8 D_801077AD_27F2DD_QuicksandCache;
extern s8 D_801077AE_27F2DE_QuicksandCache;
extern s16 D_801077B0_27F2E0_QuicksandCache;
extern s8 D_801077B2_27F2E2_QuicksandCache;
extern s16 D_801077B4_27F2E4_QuicksandCache;
extern s32 D_801077B8_27F2E8_QuicksandCache;
/* .data, 27D810.c */
extern u8 D_801077C0_27F2F0_QuicksandCache;
extern u32 D_801077C4_27F2F4_QuicksandCache;
extern s32 D_801077C8_27F2F8_QuicksandCache;
extern s32 D_801077CC_27F2FC_QuicksandCache[2];
extern s32 D_801077D4_27F304_QuicksandCache;
extern f32 D_801077D8_27F308_QuicksandCache;
extern f32 D_801077DC_27F30C_QuicksandCache;
/* .data, 27E2B0.c */
extern s8 D_801077E0_27F310_QuicksandCache;
extern s8 D_801077F0_27F320_QuicksandCache;

/* .bss */
extern s8 D_801079C0_27F4F0_QuicksandCache;
extern s8 D_801079C1_27F4F1_QuicksandCache;
extern u32 D_801079C4_27F4F4_QuicksandCache;
extern s16 D_801079C8_27F4F8_QuicksandCache;
extern s16 D_801079CA_27F4FA_QuicksandCache;
extern s16 D_801079D0_27F500_QuicksandCache;
extern QCSpr D_801079E0_27F510_QuicksandCache[20];
extern s16 D_80107F80_27FAB0_QuicksandCache[52];
extern QCScore D_80107FE8_27FB18_QuicksandCache[4];
extern omObjData* D_80108020_27FB50_QuicksandCache;
extern s8 D_80108024_27FB54_QuicksandCache[4];
extern Vec3f D_80108028_27FB58_QuicksandCache;
extern omObjData* D_80108034_27FB64_QuicksandCache;

void func_80102800_27A330_QuicksandCache(void);
void func_80102EB4_27A9E4_QuicksandCache(omObjData* obj);
void func_80102F28_27AA58_QuicksandCache(omObjData* obj);
void func_80103028_27AB58_QuicksandCache(omObjData* obj);
void func_80103134_27AC64_QuicksandCache(omObjData* obj);
void func_80103240_27AD70_QuicksandCache(omObjData* obj);
void func_80103328_27AE58_QuicksandCache(omObjData* obj);
void func_801038D0_27B400_QuicksandCache(omObjData* obj);
void func_80103FF4_27BB24_QuicksandCache(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, s32 unused);
void func_80104498_27BFC8_QuicksandCache(omObjData* obj);
void func_80104848_27C378_QuicksandCache(omObjData* obj);
void func_80104B90_27C6C0_QuicksandCache(omObjData* obj, u32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80104EA8_27C9D8_QuicksandCache(omObjData* obj);
void func_8010568C_27D1BC_QuicksandCache(omObjData* obj);
void func_801057BC_27D2EC_QuicksandCache(omObjData* obj);
void func_80105BC4_27D6F4_QuicksandCache(omObjData* obj);
void func_80105CA8_27D7D8_QuicksandCache(omObjData* obj);
void func_80105CE0_27D810_QuicksandCache(omObjData* obj, s32 file, f32 a2);
void func_80105F9C_27DACC_QuicksandCache(omObjData* obj);
void func_80106040_27DB70_QuicksandCache(omObjData* obj);
void func_8010609C_27DBCC_QuicksandCache(omObjData* obj);
void func_801060F8_27DC28_QuicksandCache(void);
void func_801062F0_27DE20_QuicksandCache(void);
void func_80106440_27DF70_QuicksandCache(void);
void func_80106648_27E178_QuicksandCache(void);
void func_80106780_27E2B0_QuicksandCache(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);
void func_801067C0_27E2F0_QuicksandCache(omObjData* obj);
void func_80106838_27E368_QuicksandCache(omObjData* obj);
void func_801068C0_27E3F0_QuicksandCache(omObjData* obj);
void func_80106CC0_27E7F0_QuicksandCache(omObjData* obj);
void func_80106E68_27E998_QuicksandCache(omObjData* obj);
void func_80106F14_27EA44_QuicksandCache(omObjData* obj);
void func_80106FC4_27EAF4_QuicksandCache(void);
void func_80107048_27EB78_QuicksandCache(void);
void func_80107074_27EBA4_QuicksandCache(QCSpr* spr, s16 idx, u16 anim, u16 x, u16 y);
void func_8010712C_27EC5C_QuicksandCache(omObjData* obj);
void func_80107410_27EF40_QuicksandCache(omObjData* obj);
void func_8010773C_27F26C_QuicksandCache(void);

#endif
