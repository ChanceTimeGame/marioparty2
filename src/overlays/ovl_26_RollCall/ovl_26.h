#ifndef _OVL_26_H
#define _OVL_26_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/board.h"

/* Roll Call, a 4P game: count the Toads (D_800FA656 0), Bob-ombs (1) or Koopas (2; these sometimes
   hatch and leave) wandering round the field before the time runs out, then they file past one by
   one (sorted) while the counter climbs; the players whose count equals the total win 10 coins.
   One retail file, 1F71A0.c; .data (0x1FE760) is at the end of the file, .rodata from 0x1FED70. */

/* One slot of D_8010A5B0_1FEF50_RollCall (100 of them, stride 0x48): every actor's state, indexed by
   obj->work[0]. Slots 0-3 players, 4 the backdrop sprite, 6 the HUD counter, 10+ the crowd,
   40+ the scenery, 45-49 the puffs of smoke. Meaning of the fields depends on the actor. */
typedef struct RCSlot {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 sprite;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 unk_20;  /* animation step; on players 0 idle, 1 thinking, 2 won, 3 lost */
    /* 0x22 */ u16 unk_22;  /* walk timer; players: result shown */
    /* 0x24 */ u16 unk_24;  /* 1 stands still */
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;  /* player's count */
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ s16 alpha;   /* also the HUD's sprite */
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} RCSlot; /* size = 0x48 */

typedef struct RCPose {
    /* 0x00 */ u8 pose;
    /* 0x01 */ char unk_01;
} RCPose; /* size = 0x2 */

typedef struct RCCharData { /* D_800CD438, one per character */
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0xC];
} RCCharData; /* size = 0x18 */

/* main */
extern RCCharData D_800CD438_CE038[];
extern u8 D_800FA656;
extern s16 D_800FA606_FB206;
extern f32 D_800FA610_FB210;
extern u16 D_801011FC_101DFC;
extern u16 ContBtnTrg[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_8002D4D0_2E0D0(s16 n);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_8003F57C_4017C(s16 arg0, s16 arg1);
void func_8002D0A0_2DCA0(s16, u8);
void func_800298A4_2A4A4(s16, s32, s32);
s16 func_8003DBE8_3E7E8(HmfData* arg0, u16 arg1, s16 arg2, char* arg3);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
u16 func_80078EA8_79AA8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8002D124_2DD24(s16 index);
void func_80029AFC_2A6FC(s16 arg0);
void func_80029A8C_2A68C(s16);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
f32 func_800B7890_B8490(f32);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
f32 func_800B1830_B2430(f32);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
f32 func_80029E3C_2AA3C(s16);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_8006D518_6E118(void);
void func_8006D4D0_6E0D0(s16);
s32 func_80069538_6A138(void);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80026DAC_279AC(s32, s32, s32, s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_80079614_7A214(s16 time);
omObjData* func_800732D4_73ED4(u32 arg0, s16 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
s32 func_80029E14_2AA14(s16 arg0);
f32 func_80029D0C_2A90C(s16);
f32 func_80029CE4_2A8E4(s16);
void func_80029C74_2A874(s16, f32);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80026D28_27928(s32);
void func_80020D20_21920(s16 arg0);
s16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprAttrReset(s16 group, s16 member, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 PlaySound(s32);
f32 HuMathSin(f32);
void HuMemMemoryFreePerm(void* ptr);

void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprBankSet(s16 group, s16 member, u16 bank);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);

/* An angle back into 0-360. */
#define RC_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))
#define RC_WRAPD(a) ((a) >= 360.0 ? (a) - 360.0 : (a) < 0.0 ? (a) + 360.0 : (a))

/* .data */
extern s32 D_80109DC0_1FE760_RollCall[6][5];   /* motion files per character */
extern Vec D_80109E38_1FE7D8_RollCall[4];      /* the players' four places */
extern s32 D_80109E68_1FE808_RollCall[6];      /* voice base per character */
extern u16 D_80109E80_1FE820_RollCall[4];
extern s16 D_80109E88_1FE828_RollCall[8][13];  /* Toad walk frames per direction */
extern Vec2f D_80109F58_1FE8F8_RollCall[30];   /* Toad grid */
extern s16 D_8010A048_1FE9E8_RollCall[32];     /* Bob-omb cycle */
extern Vec2f D_8010A088_1FEA28_RollCall[30];
extern s16 D_8010A178_1FEB18_RollCall[8][13];
extern s16 D_8010A248_1FEBE8_RollCall[62];
extern s16 D_8010A2C4_1FEC64_RollCall[12];
extern Vec2f D_8010A2DC_1FEC7C_RollCall[30];
extern u8 D_8010A3CC_1FED6C_RollCall;

/* .rodata */
extern const char D_8010A400_1FEDA0_RollCall[24];
extern const char D_8010A480_1FEE20_RollCall[];
extern const char D_8010A488_1FEE28_RollCall[];
extern const char D_8010A490_1FEE30_RollCall[];

/* .bss */
extern RCPose D_8010A4C0_1FEE60_RollCall[4];   /* the player's random pose */
extern s16 D_8010A4C8_1FEE68_RollCall;         /* state timer */
extern u8 D_8010A4CA_1FEE6A_RollCall;          /* game state */
extern u8 D_8010A4CB_1FEE6B_RollCall;          /* state increment, applied by func_80108DC4_1FD764_RollCall */
extern u8 D_8010A4CC_1FEE6C_RollCall;
extern u8 D_8010A4CD_1FEE6D_RollCall;
extern u8 D_8010A4CF_1FEE6F_RollCall;
extern u8 D_8010A4D0_1FEE70_RollCall;
extern u8 D_8010A4D1_1FEE71_RollCall;
extern u8 D_8010A4D2_1FEE72_RollCall;          /* how many in the crowd */
extern s16 D_8010A4D4_1FEE74_RollCall;
extern s16 D_8010A4D6_1FEE76_RollCall;
extern s16 D_8010A4DA_1FEE7A_RollCall;
extern s16 D_8010A4DC_1FEE7C_RollCall;
extern s16 D_8010A4DE_1FEE7E_RollCall;
extern u8 D_8010A4E0_1FEE80_RollCall[30];      /* grid cells taken */
extern u8 D_8010A4FE_1FEE9E_RollCall;          /* parade over */
extern u8 D_8010A4FF_1FEE9F_RollCall;          /* parade sorted */
extern s8 D_8010A500_1FEEA0_RollCall[30];      /* parade order */
extern u8 D_8010A51E_1FEEBE_RollCall;          /* parade count */
extern u8 D_8010A51F_1FEEBF_RollCall;          /* parade delay */
extern u8 D_8010A520_1FEEC0_RollCall;          /* HUD shows */
extern u8 D_8010A521_1FEEC1_RollCall;          /* variant */
extern u8 D_8010A522_1FEEC2_RollCall;          /* Koopas gone */
extern u16 D_8010A524_1FEEC4_RollCall;
extern u16 D_8010A526_1FEEC6_RollCall;
extern u16 D_8010A528_1FEEC8_RollCall;
extern f32 D_8010A52C_1FEECC_RollCall;         /* camera yaw */
extern u8 D_8010A530_1FEED0_RollCall;
extern u8 D_8010A531_1FEED1_RollCall;
extern u8 D_8010A532_1FEED2_RollCall[4];       /* player places taken */
extern u8 D_8010A536_1FEED6_RollCall;          /* winners */
extern u8 D_8010A537_1FEED7_RollCall;          /* Koopas hatched */
extern s16 D_8010A540_1FEEE0_RollCall[56];
extern RCSlot D_8010A5B0_1FEF50_RollCall[100];

void func_80102800_1F71A0_RollCall(void);
void func_8010281C_1F71BC_RollCall(omObjData* obj);
void func_80102968_1F7308_RollCall(omObjData* obj);
void func_80102994_1F7334_RollCall(omObjData* obj);
void func_80102A9C_1F743C_RollCall(void);
void func_80102AD8_1F7478_RollCall(omObjData* obj);
void func_80102C58_1F75F8_RollCall(omObjData* obj);
void func_80102DD8_1F7778_RollCall(void);
void func_80102E14_1F77B4_RollCall(omObjData* obj);
void func_80102E54_1F77F4_RollCall(omObjData* obj);
void func_80103168_1F7B08_RollCall(omObjData* obj);
void func_801031C0_1F7B60_RollCall(omObjData* obj);
void func_80103238_1F7BD8_RollCall(omObjData* obj);
void func_8010327C_1F7C1C_RollCall(omObjData* obj);
void func_8010331C_1F7CBC_RollCall(omObjData* obj);
void func_80103368_1F7D08_RollCall(omObjData* obj);
void func_801033B8_1F7D58_RollCall(omObjData* obj);
void func_80103434_1F7DD4_RollCall(omObjData* obj);
void func_80103894_1F8234_RollCall(omObjData* obj);
void func_801039E4_1F8384_RollCall(omObjData* obj);
void func_80103B24_1F84C4_RollCall(omObjData* obj);
void func_80103E98_1F8838_RollCall(omObjData* obj);
void func_801041E0_1F8B80_RollCall(void);
void func_801042EC_1F8C8C_RollCall(omObjData* obj);
void func_8010439C_1F8D3C_RollCall(omObjData* obj);
void func_801045E8_1F8F88_RollCall(void);
void func_80104698_1F9038_RollCall(omObjData* obj);
void func_80104BFC_1F959C_RollCall(omObjData* obj);
void func_80104D34_1F96D4_RollCall(omObjData* obj);
void func_80104E38_1F97D8_RollCall(omObjData* obj);
void func_8010516C_1F9B0C_RollCall(omObjData* obj);
void func_8010562C_1F9FCC_RollCall(void);
void func_80105738_1FA0D8_RollCall(omObjData* obj);
void func_8010583C_1FA1DC_RollCall(omObjData* obj);
void func_80105D44_1FA6E4_RollCall(void);
void func_80105DF4_1FA794_RollCall(omObjData* obj);
void func_80106078_1FAA18_RollCall(omObjData* obj);
void func_80106138_1FAAD8_RollCall(void);
void func_801061E8_1FAB88_RollCall(omObjData* obj);
void func_801067D0_1FB170_RollCall(omObjData* obj);
void func_80106900_1FB2A0_RollCall(omObjData* obj);
void func_80106ADC_1FB47C_RollCall(omObjData* obj);
void func_80106B14_1FB4B4_RollCall(f32 x, f32 y, f32 z, f32 scale);
void func_80106BD8_1FB578_RollCall(omObjData* obj);
void func_801070B8_1FBA58_RollCall(omObjData* obj);
void func_80107400_1FBDA0_RollCall(void);
void func_801074EC_1FBE8C_RollCall(omObjData* obj);
void func_8010759C_1FBF3C_RollCall(omObjData* obj);
void func_801077EC_1FC18C_RollCall(void);
void func_8010789C_1FC23C_RollCall(s32 player);
void func_8010791C_1FC2BC_RollCall(omObjData* obj, u32 motion);
void func_80107958_1FC2F8_RollCall(omObjData* obj, u16 motion, s16 arg2, s16 arg3);
f32 func_801079DC_1FC37C_RollCall(omObjData* obj);
void func_80107A3C_1FC3DC_RollCall(omObjData* obj);
void func_80107B94_1FC534_RollCall(omObjData* obj);
void func_80107BD0_1FC570_RollCall(omObjData* obj);
void func_80107C0C_1FC5AC_RollCall(omObjData* obj);
void func_80107C48_1FC5E8_RollCall(omObjData* obj);
void func_80107DE4_1FC784_RollCall(omObjData* obj);
void func_80107EFC_1FC89C_RollCall(omObjData* obj);
void func_801081B8_1FCB58_RollCall(omObjData* obj);
void func_80108478_1FCE18_RollCall(omObjData* obj);
void func_80108C04_1FD5A4_RollCall(void);
void func_80108D10_1FD6B0_RollCall(void);
void func_80108D34_1FD6D4_RollCall(omObjData* obj);
void func_80108D6C_1FD70C_RollCall(omObjData* obj);
void func_80108DC4_1FD764_RollCall(void);
void func_80108DEC_1FD78C_RollCall(void);
void func_80108FEC_1FD98C_RollCall(void);
void func_80109198_1FDB38_RollCall(void);
void func_80109338_1FDCD8_RollCall(omObjData* obj);
void func_8010945C_1FDDFC_RollCall(void);
void func_80109538_1FDED8_RollCall(omObjData* obj);
void func_80109660_1FE000_RollCall(void);
f32 func_80109844_1FE1E4_RollCall(f32 x);
void func_80109994_1FE334_RollCall(Vec* from, Vec* to, Vec* out);
void func_80109D10_1FE6B0_RollCall(void);
void func_80109D94_1FE734_RollCall(void);
#endif /* _OVL_26_H */
