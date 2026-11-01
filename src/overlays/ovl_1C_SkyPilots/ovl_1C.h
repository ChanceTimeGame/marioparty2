#ifndef _OVL_1C_H
#define _OVL_1C_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/board.h"

/* Sky Pilots, a 2-on-2 race: each team flies one plane (two split-screen views) round a ring of
   radius 12732.405 from heading 30 to 246. The pilot (first player of the team) steers, the gunner
   throttles and fires; touching a ring's gate, a mine or a balloon stuns or boosts; first home wins
   10 coins each. The 1P _CheckFlag(0xC) variant is a time trial against record 3. Three retail
   files: 1ABE90.c, 1B2120.c (from 80108A90, no text pad: found from the .rodata pad of its one
   double, so the boundary could be 80108A00 instead), 1B39D0.c (from 8010A340). */

/* omObjData::unk_50 of a plane (D_8010ADA4_1B4434_SkyPilots[team]) */
typedef struct SPPlane {
    /* 0x000 */ f32 yaw;
    /* 0x004 */ f32 pitch;
    /* 0x008 */ f32 speed;
    /* 0x00C */ f32 brake;
    /* 0x010 */ f32 elevator;
    /* 0x014 */ f32 aileron;
    /* 0x018 */ f32 scale;
    /* 0x01C */ f32 prop;
    /* 0x020 */ f32 spin;
    /* 0x024 */ f32 hitSlow;
    /* 0x028 */ f32 hitSpin;
    /* 0x02C */ f32 progress;   /* 0 start .. 1 finish */
    /* 0x030 */ s32 aileronFrame; /* an f32 read whole; see func_801058EC_1AEF7C_SkyPilots */
    /* 0x034 */ s32 gunFrame;
    /* 0x038 */ u8 unk_38[0x44 - 0x38];
    /* 0x044 */ f32 yawHist[20];
    /* 0x094 */ s32 yawPos;
    /* 0x098 */ f32 pitchHist[20];
    /* 0x0E8 */ s32 pitchPos;
    /* 0x0EC */ f32 pad[4];     /* the gunner's stick, last four frames */
    /* 0x0FC */ s8 stickX;
    /* 0x0FD */ s8 stickY;
    /* 0x0FE */ s8 stickZ;      /* the gunner's */
    /* 0x0FF */ u8 hit;
    /* 0x100 */ u8 unk_100;
    /* 0x101 */ u8 spinKind;    /* 0 none, 1 half loop, 2 loop */
    /* 0x102 */ u8 lastGate;
    /* 0x103 */ u8 timerA;
    /* 0x104 */ u8 timerB;
    /* 0x105 */ u8 pilot;
    /* 0x106 */ u8 gunner;
    /* 0x107 */ u8 unk_107;
    /* 0x108 */ u8 icon[2];     /* sprite of pilot, gunner */
    /* 0x10A */ s8 smoke;
    /* 0x10B */ u8 unk_10B;
    /* 0x10C */ omObjData* pilotObj;
    /* 0x110 */ omObjData* gunnerObj;
    /* 0x114 */ u8 team;
    /* 0x115 */ u8 bump;
    /* 0x116 */ u8 unk_116[2];
} SPPlane; /* size = 0x118 */

/* Courses are polar: angle along the ring, radius offset, one more value. */
typedef struct SPPolar {
    /* 0x0 */ f32 angle;
    /* 0x4 */ f32 radius;
    /* 0x8 */ f32 extra;
} SPPolar;

#define SP_RADIUS 12732.405f

typedef f32 Matrix4f[4][4];

/* MgWork.unk_E8 element */
typedef struct MgMotion {
    /* 0x0 */ s16 unk_00;
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ s16 unk_04;
    /* 0x8 */ s32 unk_08;
} MgMotion;

/* main, not in a shared header */
void func_80018F58_19B58(s32);
void func_8001A340_1AF40(s16, f32, f32, f32);
void func_80025884_26484(Matrix4f m, f32 x, f32 y, f32 z);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void* func_80027154_27D54(s32 size, s32 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029E3C_2AA3C(s16);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002CD6C_2D96C(s32);
void func_8002D4D0_2E0D0(s16 n);
f32 func_8002D958_2E558(f32);
void func_8002F290_2FE90(s32* arg0, s32 n);
s32 func_800680D4_68CD4(s16 index);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
u16 func_80078EA8_79AA8(void);
void func_800794F0_7A0F0(s32);
void func_80079614_7A214(s16 time);
void func_80079684_7A284(s8);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 func_800B1830_B2430(f32);
void func_800B1F50_B2B50(void* m, f32 x, f32 y, f32 z);
void func_800B2060_B2C60(f32 (*m)[4], f32 x, f32 y, f32 z);
void func_800B37C0_B43C0(f32* mtx);
f32 func_800B75A8_B81A8(f32 y, f32 x);
f32 func_800B7890_B8490(f32);
void func_800B8070_B8C70(f32 angle, f32* s, f32* c);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80029708_2A308(s32);
void func_8000BE74_CA74(omObjData*, f32);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void GWMgRecordSet(s16, u16);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16, s16, s32);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
f64 fabs(f64);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
extern f32 D_800F94A8_FA0A8[];
extern Vec D_801013B0_101FB0[];
extern Vec3f D_80102770_103370[];
extern s32 D_800F8FD0_F9BD0;
extern u16 D_801011FC_101DFC;
extern u16 D_800FA606_FB206;
extern f32 D_80101300_101F00;
extern f32 D_8010105C_101C5C;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_8001B170_1BD70(Matrix4f, Matrix4f);

extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near */

/* .data */
extern s8 D_8010ADA0_1B4430_SkyPilots;            /* winner: -1 racing, -2 time up, -3 a plane home */
extern s8 D_8010ADA1_1B4431_SkyPilots;            /* the team ahead */
extern omObjData* D_8010ADA4_1B4434_SkyPilots[2]; /* the planes */
extern f32 D_8010ADAC_1B443C_SkyPilots[2];        /* camera roll */
extern s16 D_8010ADB4_1B4444_SkyPilots;           /* the team home, -1 */
extern f32 D_8010ADB8_1B4448_SkyPilots[5];        /* balloon bob angle */
extern u8 D_8010ADCC_1B445C_SkyPilots[2][4];      /* hits by team on each mine */
extern u8 D_8010ADD4_1B4464_SkyPilots[5];         /* balloon popped, counts to 45 */
extern SPPolar D_8010ADDC_1B446C_SkyPilots[2];    /* the gates (hills?) */
extern SPPolar D_8010ADF4_1B4484_SkyPilots[6];    /* rings */
extern SPPolar D_8010AE3C_1B44CC_SkyPilots[4];    /* mines' launchers */
extern SPPolar D_8010AE6C_1B44FC_SkyPilots[5];    /* balloons */
extern s8 D_8010AEA8_1B4538_SkyPilots[4];         /* mine state: 0 idle, 1.. flying, <0 waiting */
extern Vec D_8010AEAC_1B453C_SkyPilots[4];        /* mine direction */
extern Vec D_8010AEDC_1B456C_SkyPilots[4];        /* mine position */
extern s16 D_8010AF0C_1B459C_SkyPilots;           /* race clock */
extern u32 D_8010AF10_1B45A0_SkyPilots;
extern s32 D_8010AF14_1B45A4_SkyPilots;
extern s32 D_8010AF18_1B45A8_SkyPilots;
extern s32 D_8010AF1C_1B45AC_SkyPilots;
extern s32 D_8010AF20_1B45B0_SkyPilots;           /* new record */
extern s32 D_8010AF24;
extern s32 D_8010AF28_1B45B8_SkyPilots;
extern f32 D_8010AF2C_1B45BC_SkyPilots[11];       /* spin speed curve */
extern u8 D_8010AF58_1B45E8_SkyPilots[60];        /* inner road: what stands on each of the 60 tiles */
extern u8 D_8010AF94_1B4624_SkyPilots[60];        /* outer road */
extern f32 D_8010AFD0_1B4660_SkyPilots[60];       /* inner road's sway phase */
extern f32 D_8010B0C0_1B4750_SkyPilots[60];       /* outer road's */
extern f32 D_8010B1B0_1B4840_SkyPilots;
extern s32 D_8010B1B4_1B4844_SkyPilots[6];        /* character's pilot model file */
extern s32 D_8010B1CC_1B485C_SkyPilots[6];        /* character's gunner model file */
extern s32 D_8010B200_1B4890_SkyPilots;
extern s32 D_8010B204_1B4894_SkyPilots;
extern f32 D_8010B208_1B4898_SkyPilots;
extern f32 D_8010B20C_1B489C_SkyPilots[2];
extern f32 D_8010B214_1B48A4_SkyPilots[2];
extern f32 D_8010B21C_1B48AC_SkyPilots[2];
extern f32 D_8010B224_1B48B4_SkyPilots[3];

/* .bss */
extern f32 D_8010B2C0_1B4950_SkyPilots;           /* push of this frame's collisions */
extern f32 D_8010B2C4_1B4954_SkyPilots;
extern f32 D_8010B2C8_1B4958_SkyPilots;
extern u16 D_8010B2CC_1B495C_SkyPilots[2];        /* position marker sprites */
extern u16 D_8010B2D0_1B4960_SkyPilots[2];
extern u16 D_8010B2D4_1B4964_SkyPilots[2];
extern s16 D_8010B2D8_1B4968_SkyPilots;
extern s16 D_8010B2DA_1B496A_SkyPilots;
extern s32 D_8010B2DC_1B496C_SkyPilots;           /* the winners; read as s16 by the low half label D_8010B2DE_1B496E_SkyPilots */
extern s32 D_8010B2E0_1B4970_SkyPilots;           /* low half D_8010B2E2_1B4972_SkyPilots */
extern s32 D_8010B2E8_1B4978_SkyPilots[4];        /* low halves: model ids */
extern s32 D_8010B2F8_1B4988_SkyPilots[4];
extern s32 D_8010B308_1B4998_SkyPilots[4];
extern s32 D_8010B318_1B49A8_SkyPilots[5];
extern s32 D_8010B330_1B49C0_SkyPilots[5];
extern s16 D_8010B344_1B49D4_SkyPilots;
extern s16 D_8010B346_1B49D6_SkyPilots;
extern s16 D_8010B348_1B49D8_SkyPilots[2];
extern s16 D_8010B34C_1B49DC_SkyPilots[2];
extern s16 D_8010B350_1B49E0_SkyPilots[2];
extern u8 D_8010B354_1B49E4_SkyPilots[2];         /* ring models */
extern u8 D_8010B356_1B49E6_SkyPilots[2][6];      /* per team view: tree models */
extern u8 D_8010B362_1B49F2_SkyPilots[2][6];
extern u8 D_8010B36E_1B49FE_SkyPilots[2][3];
extern u8 D_8010B374_1B4A04_SkyPilots[2][3];
extern u8 D_8010B37A_1B4A0A_SkyPilots[2][2];
extern u8 D_8010B37E_1B4A0E_SkyPilots[2][2];
extern Matrix4f D_8010B388_1B4A18_SkyPilots;
extern Matrix4f D_8010B3C8_1B4A58_SkyPilots;
extern f32 D_8010B410_1B4AA0_SkyPilots[2];
extern f32 D_8010B418_1B4AA8_SkyPilots[2];
extern f32 D_8010B420_1B4AB0_SkyPilots[2];
extern f32 D_8010B428_1B4AB8_SkyPilots;
extern f32 D_8010B42C_1B4ABC_SkyPilots;
extern f32 D_8010B430_1B4AC0_SkyPilots[2];        /* heading round the course, degrees */

/* overlay */
void func_80102800_1ABE90_SkyPilots(void);
void func_80102D3C_1AC3CC_SkyPilots(void);
void func_80102D68_1AC3F8_SkyPilots(void);
void func_80102EF0_1AC580_SkyPilots(omObjData* obj);
void func_8010369C_1ACD2C_SkyPilots(omObjData* obj);
void func_8010394C_1ACFDC_SkyPilots(omObjData* obj);
void func_80103A6C_1AD0FC_SkyPilots(omObjData* obj);
void func_80103BC0_1AD250_SkyPilots(f32 m[4][4], Vec* at, Vec* axis, f32 angle);
void func_80103CA8_1AD338_SkyPilots(s32 team, f32 rx, f32 ry);
void func_80103E34_1AD4C4_SkyPilots(omObjData* obj);
void func_8010413C_1AD7CC_SkyPilots(omObjData* obj, f32 yawD, f32 yaw, f32 pitchD, f32 pitch);
void func_80104454_1ADAE4_SkyPilots(f32 x, f32 y, f32 z, f32 d);
void func_801044D4_1ADB64_SkyPilots(omObjData* obj);
void func_801044EC_1ADB7C_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80104654_1ADCE4_SkyPilots(Vec* v, s32 i);
void func_8010489C_1ADF2C_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80104940_1ADFD0_SkyPilots(omObjData* obj, f32 x, f32 y, f32 z);
void func_80104A4C_1AE0DC_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80104C10_1AE2A0_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80104DC0_1AE450_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80105018_1AE6A8_SkyPilots(omObjData* obj, f32 x, f32 y, f32 z);
f32 func_801051F0_1AE880_SkyPilots(SPPlane* w, f32 v);
f32 func_80105258_1AE8E8_SkyPilots(SPPlane* w, f32 v);
void func_801052C0_1AE950_SkyPilots(omObjData* obj, f32 in);
void func_80105400_1AEA90_SkyPilots(omObjData* obj, f32 in);
void func_80105548_1AEBD8_SkyPilots(omObjData* obj, f32 in);
void func_8010560C_1AEC9C_SkyPilots(omObjData* obj);
void func_80105890_1AEF20_SkyPilots(omObjData* obj);
void func_801058EC_1AEF7C_SkyPilots(omObjData* obj);
void func_8010608C_1AF71C_SkyPilots(); /* old style: retail passes the record unextended */
void func_80106384_1AFA14_SkyPilots(void);
void func_801063C4_1AFA54_SkyPilots(void);
s16 func_8010641C_1AFAAC_SkyPilots(s32 x, s16 y);
s16 func_801065CC_1AFC5C_SkyPilots(s32 x, s16 y);
void func_8010677C_1AFE0C_SkyPilots(void);
s16 func_80106810_1AFEA0_SkyPilots(s32 idx, s16 x, s16 y);
void func_80106A7C_1B010C_SkyPilots(s16 idx, s16 speed);
void func_80106CD0_1B0360_SkyPilots(omObjData* obj);
void func_80106E98_1B0528_SkyPilots(omObjData* obj);
void func_80107074_1B0704_SkyPilots(omObjData* obj, s32 dir, s32 file, s32 team, s32 player);
void func_801073A8_1B0A38_SkyPilots(omObjData* obj, s32 dir, s32 file, s32 team, s32 player);
void func_801076E8_1B0D78_SkyPilots(void);
void func_80107EAC_1B153C_SkyPilots(omObjData* obj);
void func_801083CC_1B1A5C_SkyPilots(omObjData* obj);
void func_801084E4_1B1B74_SkyPilots(s32 i);
void func_8010890C_1B1F9C_SkyPilots(s32 i);
void func_80108A00_1B2090_SkyPilots(s32 i);
void func_80108A90_1B2120_SkyPilots(s32 i);
void func_80108C24_1B22B4_SkyPilots(omObjData* obj);
void func_80108DB4_1B2444_SkyPilots(omObjData* obj);
void func_80108ECC_1B255C_SkyPilots(omObjData* obj);
void func_8010916C_1B27FC_SkyPilots(omObjData* obj);
void func_801092F8_1B2988_SkyPilots(omObjData* obj);
void func_80109878_1B2F08_SkyPilots(omObjData* obj);
void func_80109BBC_1B324C_SkyPilots(omObjData* obj);
void func_8010A024_1B36B4_SkyPilots(omObjData* obj);
void func_8010A0BC_1B374C_SkyPilots(omObjData* obj);
void func_8010A154_1B37E4_SkyPilots(omObjData* obj);
void func_8010A1F4_1B3884_SkyPilots(omObjData* obj);
void func_8010A294_1B3924_SkyPilots(omObjData* obj);
void func_8010A340_1B39D0_SkyPilots(void);
void func_8010A364_1B39F4_SkyPilots(omObjData* obj);
void func_8010A53C_1B3BCC_SkyPilots(omObjData* obj);
void func_8010A6C0_1B3D50_SkyPilots(omObjData* obj);
void func_8010A768_1B3DF8_SkyPilots(omObjData* obj);
void func_8010A8F4_1B3F84_SkyPilots(omObjData* obj);
void func_8010AB84_1B4214_SkyPilots(omObjData* obj);

#endif
