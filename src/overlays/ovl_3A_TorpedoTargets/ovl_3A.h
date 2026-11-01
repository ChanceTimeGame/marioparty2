#ifndef _OVL_3A_H
#define _OVL_3A_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/pad.h"

typedef struct MgMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08;
} MgMotion; /* C8E0.c, size 0xC */

/* Torpedo Targets, 2 vs 2: each team crews one submarine, split screen. The pilot (group 0, 2)
   steers with the stick and A/B set the throttle; the gunner (group 1, 3) fires a torpedo with A and
   guides it with the stick. A target (model D_8010949C_28B6AC) surfaces on one of four paths; a hit scores one
   point. A torpedo hitting the other sub knocks it about. The clock starts at 60 s (3650, 2 per
   game frame); the higher score wins, 10 coins each; a draw gives no coins. Retail files 284A10.c (setup, flow, camera, the subs),
   289BC0.c (from 801079B0, end poses and the CPUs), 28AB10.c (from 80108900, the target);
   .data is asm, .rodata per file from 0x28B5E0 and 0x28B614. */

/* The submarine, omObjData::unk_50 of func_80103828_285A38/func_80103B2C_285D3C, 0x13C bytes. */
typedef struct TTSub {
    /* 0x000 */ f32 yaw;
    /* 0x004 */ f32 pitch;
    /* 0x008 */ f32 speed;
    /* 0x00C */ f32 accel;
    /* 0x010 */ f32 rudderV;  /* elevator deflection */
    /* 0x014 */ f32 roll;     /* rudder deflection, also the hull's roll */
    /* 0x018 */ char unk_18[4];
    /* 0x01C */ f32 prop;     /* screw speed */
    /* 0x020 */ f32 knock;    /* speed lost to a hit */
    /* 0x024 */ f32 knockRoll;
    /* 0x028 */ f32 tilt;
    /* 0x02C */ f32 camDist;
    /* 0x030 */ char unk_30[4];
    /* 0x034 */ f32 rudder;
    /* 0x038 */ char unk_38[0x10];
    /* 0x048 */ f32 tPitch;   /* torpedo */
    /* 0x04C */ f32 tYaw;
    /* 0x050 */ f32 tAccel;
    /* 0x054 */ f32 tSpeed;
    /* 0x058 */ f32 tSpin;
    /* 0x05C */ f32 tTrail;
    /* 0x060 */ f32 yawHist[20];
    /* 0x0B0 */ s32 yawPos;
    /* 0x0B4 */ f32 pitchHist[20];
    /* 0x104 */ s32 pitchPos;
    /* 0x108 */ char unk_108[0x10];
    /* 0x118 */ u8 score;
    /* 0x119 */ s8 stickX;    /* pilot */
    /* 0x11A */ s8 stickY;
    /* 0x11C */ u16 btn;
    /* 0x11E */ s8 gStickX;   /* gunner */
    /* 0x11F */ s8 gStickY;
    /* 0x120 */ u16 gBtn;     /* edge-triggered */
    /* 0x122 */ u8 hit;       /* struck by the other team's torpedo */
    /* 0x123 */ char unk_123[2];
    /* 0x125 */ s8 unk_125;
    /* 0x126 */ s8 unk_126;
    /* 0x127 */ char unk_127;
    /* 0x128 */ u8 pilot;     /* player index */
    /* 0x129 */ u8 gunner;
    /* 0x12A */ char unk_12A[6];
    /* 0x130 */ omObjData* pilotObj;
    /* 0x134 */ omObjData* gunnerObj;
    /* 0x138 */ u8 team;
    /* 0x139 */ u8 bump;      /* frames until the next sub-on-sub vibration */
} TTSub; /* size = 0x13C */

/* main */
extern s32 D_800F8FD0_F9BD0; /* scene state: 0 intro, 1 play, 2 result, 3 leave */
extern f32 D_800F94A8_FA0A8[]; /* CZoomM */
extern u16 D_800FA606_FB206;
extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near */
extern f32 D_8010105C_101C5C;
extern u16 D_801011FC_101DFC;
extern f32 D_80101300_101F00;
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern u8 D_80102720_103320;
extern Vec3f D_80102770_103370[]; /* CRotM */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

f32 fabsf(f32);
f64 fabs(f64);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
u16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
s16 SprAnimRead(void* arg0);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
u16 func_80078EA8_79AA8(void);
void func_8000BE74_CA74(omObjData* obj, f32 arg1);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
u16 func_80018A30_19630(s32 file, s32 attr);
u8 func_80018F58_19B58(s32);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029AFC_2A6FC(s16);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_80029EDC_2AADC(s16 arg0, s16 arg1); /* main: u8; retail sign-extends the mask */
void func_80029FE4_2ABE4(s16, f32);
void func_8002A00C_2AC0C(s16 model);
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
void func_8002C59C_2D19C(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002CD6C_2D96C(u8 arg0);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
void func_8002D4D0_2E0D0(s16 n);
f32 func_8002D958_2E558(f32);
void func_8002F290_2FE90(s32* arg0, s32 n);
s32 func_80005110_5D10();
void func_8003EAF0_3F6F0(char* arg0, void* arg1);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
void func_800794F0_7A0F0(s32);
void func_80079614_7A214(s16 time);
void func_80079684_7A284(s32);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 func_800B1830_B2430(f32);
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z);
f32 func_800B75A8_B81A8(f32 y, f32 x);
void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* .data (284A10.c 0x28B470, 289BC0.c 0x28B5A0, 28AB10.c 0x28B5C0) */
extern s8 D_80109260_28B470_TorpedoTargets;  /* -2 on a draw */
extern omObjData* D_80109264_28B474_TorpedoTargets[2]; /* the subs */
extern Vec D_8010926C_28B47C_TorpedoTargets[2]; /* torpedo positions */
extern Vec D_80109284_28B494_TorpedoTargets[4]; /* obstacles; the target sits above one in path 3 */
extern s8 D_801092B4_28B4C4_TorpedoTargets;   /* target: 0 appearing, 1 on its path, else counting up to 0 */
extern s8 D_801092B8_28B4C8_TorpedoTargets[4]; /* torpedo: 0 loaded, 1 running, <0 reloading */
extern u8 D_801092BC_28B4CC_TorpedoTargets[4]; /* scores */
extern u8 D_801092C0_28B4D0_TorpedoTargets[4];
extern f32 D_801092C4_28B4D4_TorpedoTargets[2]; /* view roll per team */
extern f32 D_801092D0_28B4E0_TorpedoTargets[2]; /* score pulse */
extern Vec D_801092D8_28B4E8_TorpedoTargets[2]; /* camera positions */
extern u32 D_801092F4_28B504_TorpedoTargets;  /* intro frames */
extern u32 D_801092F8_28B508_TorpedoTargets;  /* time left, 2 per frame */
extern s32 D_801092FC_28B50C_TorpedoTargets;  /* result frames */
extern s32 D_80109300_28B510_TorpedoTargets;
extern f32 D_8010930C_28B51C_TorpedoTargets;  /* wave scroll */
extern f32 D_80109310_28B520_TorpedoTargets;  /* angle of the model circling overhead */
extern s16 D_80109314_28B524_TorpedoTargets;
extern s32 D_80109318_28B528_TorpedoTargets[6]; /* pilot file, by character */
extern s32 D_80109330_28B540_TorpedoTargets[6];
extern s32 D_80109348_28B558_TorpedoTargets[6]; /* gunner */
extern s32 D_80109360_28B570_TorpedoTargets[6];
extern s32 D_80109378_28B588_TorpedoTargets[6]; /* "hit" sprite frames */
extern s32 D_80109390_28B5A0_TorpedoTargets;
extern f32 D_80109394_28B5A4_TorpedoTargets;
extern s32 D_80109398_28B5A8_TorpedoTargets;
extern f32 D_8010939C_28B5AC_TorpedoTargets;
extern s8 D_801093A0_28B5B0_TorpedoTargets[16]; /* gunner CPU aim: 0 target, 1 other sub */
extern s32 D_801093B0_28B5C0_TorpedoTargets;  /* target alpha */
extern u8 D_801093B3_28B5C3_TorpedoTargets;   /* its low byte, by retail's own label */
extern f32 D_801093B4_28B5C4_TorpedoTargets;  /* target bob speed */
extern Vec D_801093B8_28B5C8_TorpedoTargets;  /* target position */
extern s32 D_801093C4_28B5D4_TorpedoTargets;  /* targets so far, doubled */
extern const Vec D_80109404_28B614_TorpedoTargets; /* rodata, in 289BC0.c */

/* .bss */
extern s8 D_80109418_28B628_TorpedoTargets;  /* seabed model */
extern f32 D_8010941C_28B62C_TorpedoTargets;  /* collision push out, separate labels */
extern f32 D_80109420_28B630_TorpedoTargets;
extern f32 D_80109424_28B634_TorpedoTargets;
extern s32 D_8010942C_28B63C_TorpedoTargets;  /* winners */
extern s32 D_80109430_28B640_TorpedoTargets;
extern u16 D_80109434_28B644_TorpedoTargets[2]; /* wave texture size, filled by func_8003EAF0_3F6F0 */
extern s16 D_80109438_28B648_TorpedoTargets[2];
extern s16 D_8010943C_28B64C_TorpedoTargets;
extern s16 D_8010943E_28B64E_TorpedoTargets;
extern s16 D_80109440_28B650_TorpedoTargets[2];
extern s16 D_80109444_28B654_TorpedoTargets;
extern s16 D_80109446_28B656_TorpedoTargets[2];
extern s16 D_8010944A_28B65A_TorpedoTargets[2];
extern s16 D_8010944E_28B65E_TorpedoTargets[2];
extern f32 D_80109460_28B670_TorpedoTargets;
extern f32 D_80109464_28B674_TorpedoTargets;
extern f32 D_80109468_28B678_TorpedoTargets[2]; /* gunner CPU: range at launch */
extern f32 D_80109470_28B680_TorpedoTargets;  /* path 2 speed */
extern f32 D_80109474_28B684_TorpedoTargets;  /* path 0 radius */
extern f32 D_80109478_28B688_TorpedoTargets;  /* path angle */
extern f32 D_8010947C_28B68C_TorpedoTargets;  /* path height */
extern Vec D_80109480_28B690_TorpedoTargets;  /* path 2 direction */
extern f32 D_8010948C_28B69C_TorpedoTargets;  /* path 1 speed */
extern s8 D_80109490_28B6A0_TorpedoTargets;  /* path: 0 orbit, 1 column, 2 line, 3 rock */
extern s8 D_8010949C_28B6AC_TorpedoTargets;  /* target model */

void func_80102800_284A10_TorpedoTargets(void);
void func_80102BC4_284DD4_TorpedoTargets(omObjData* obj);
void func_80102BF0_284E00_TorpedoTargets(omObjData* obj);
void func_80102E54_285064_TorpedoTargets(omObjData* obj);
void func_80103634_285844_TorpedoTargets(omObjData* obj);
void func_80103828_285A38_TorpedoTargets(omObjData* obj);
void func_80103B2C_285D3C_TorpedoTargets(omObjData* obj);
void func_80103E40_286050_TorpedoTargets(omObjData* obj, s32 dir, s32 fileA, s32 fileB, s32 team, s32 player);
void func_801040F0_286300_TorpedoTargets(omObjData* obj, s32 dir, s32 fileA, s32 fileB, s32 team, s32 player);
void func_801043AC_2865BC_TorpedoTargets(omObjData* obj);
void func_80104464_286674_TorpedoTargets(omObjData* obj);
void func_80104524_286734_TorpedoTargets(omObjData* obj);
void func_801045E4_2867F4_TorpedoTargets(omObjData* obj);
void func_801046A4_2868B4_TorpedoTargets(f32 m[4][4], Vec* at, Vec* axis, f32 angle);
void func_8010478C_28699C_TorpedoTargets(omObjData* obj);
void func_80104B9C_286DAC_TorpedoTargets(omObjData* obj, f32 yawD, f32 yaw, f32 pitchD, f32 pitch);
void func_80104EB0_2870C0_TorpedoTargets(omObjData* obj);
void func_80105124_287334_TorpedoTargets(omObjData* obj);
void func_80105398_2875A8_TorpedoTargets(f32 x, f32 y, f32 z, f32 d);
f32 func_80105418_287628_TorpedoTargets(f32 r, f32 x, f32 y, f32 z);
void func_8010552C_28773C_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z);
void func_801055F4_287804_TorpedoTargets(f32 r, f32 x, f32 y, f32 z);
void func_8010578C_28799C_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z);
void func_801058A8_287AB8_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z);
s32 func_80105A54_287C64_TorpedoTargets(omObjData* obj);
void func_80105D0C_287F1C_TorpedoTargets(TTSub* w);
s32 func_80105D70_287F80_TorpedoTargets(omObjData* obj);
f32 func_8010667C_28888C_TorpedoTargets(TTSub* w, f32 v);
f32 func_801066E4_2888F4_TorpedoTargets(TTSub* w, f32 v);
void func_8010674C_28895C_TorpedoTargets(omObjData* obj, f32 in);
void func_8010689C_288AAC_TorpedoTargets(omObjData* obj, f32 in);
void func_801069E4_288BF4_TorpedoTargets(omObjData* obj, f32 in);
void func_80106AAC_288CBC_TorpedoTargets(omObjData* obj);
void func_80106DEC_288FFC_TorpedoTargets(omObjData* obj);
void func_80107368_289578_TorpedoTargets(void);
void func_80107410_289620_TorpedoTargets(s32 i, s16 x, s16 y);
void func_80107494_2896A4_TorpedoTargets(s16 i, s32 on);
s16 func_80107580_289790_TorpedoTargets(s32 i, s32 x, s16 y);
void func_80107764_289974_TorpedoTargets(s16 i, s32 n);
void func_801079B0_289BC0_TorpedoTargets(void);
void func_801079D4_289BE4_TorpedoTargets(omObjData* obj);
void func_80107BAC_289DBC_TorpedoTargets(omObjData* obj);
void func_80107C38_289E48_TorpedoTargets(omObjData* obj);
void func_80107D54_289F64_TorpedoTargets(omObjData* obj);
void func_80107DF0_28A000_TorpedoTargets(Vec* out, s16 level);
void func_80107EDC_28A0EC_TorpedoTargets(omObjData* obj);
void func_80108234_28A444_TorpedoTargets(omObjData* obj);
s32 func_80108900_28AB10_TorpedoTargets(void);
void func_80108934_28AB44_TorpedoTargets(void);
void func_80108F94_28B1A4_TorpedoTargets(s32 n, Vec* out);
void func_80109060_28B270_TorpedoTargets(s32 n, Vec* out);
void func_801090F8_28B308_TorpedoTargets(s32 n, f32* out);
void func_801091F0_28B400_TorpedoTargets(s32 n, Vec* out);
void func_80109214_28B424_TorpedoTargets(void);

#endif
