#ifndef _OVL_0F_H
#define _OVL_0F_H

/* Overlay 0F: Rainbow Run. Its game code descends from MP1's ovl_1F_TightropeTreachery (197E20.c,
   19A360.c, 19ACC0.c, 19D510.c). Retail is four files: 144190.c, 147180.c from 801057F0 (MP1's
   19A360.c), 1479E0.c from 80106050 and 149120.c from 80107790 (MP1's 19D510.c). .data is C in each
   file (14C080); .rodata is carved per file. Every prototype is checked against its definition. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/malloc.h"

typedef f32 Matrix4f[4][4];

/* ---- structs ---- */

/* A player object's work: main's minigame work (0x15C bytes; MP1's 0xE8 TTPlayerWork with fields
   from 0x50 moved). Fields from the asm. */
typedef struct RRPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 angle; /* facing angle (degrees) */
    /* 0x40 */ f32 speed;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 radius;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[4];
    /* 0x57 */ s8 port; /* controller port */
    /* 0x58 */ char unk_58[1];
    /* 0x59 */ s8 player; /* player index */
    /* 0x5A */ char unk_5A[6];
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ char unk_64[0x50];
    /* 0xB4 */ f32 unk_B4; /* MP1 0xA4 */
    /* 0xB8 */ char unk_B8[6];
    /* 0xBE */ u16 unk_BE; /* stun timer after a hit (MP1 0xAE) */
    /* 0xC0 */ char unk_C0[0xC];
    /* 0xCC */ f32 unk_CC; /* MP1 0xBC */
    /* 0xD0 */ u16 unk_D0; /* MP1 0xC0 */
    /* 0xD2 */ char unk_D2[0x1A];
    /* 0xEC */ s32 (*unk_EC)(omObjData*, omObjData*); /* collision callback (MP1 0xDC) */
    /* 0xF0 */ char unk_F0[0x68];
    /* 0x158 */ struct RRTeamWork* team; /* a follower's state (D_8010AA18_14C3A8_RainbowRun[]; MP1 0xE4) */
} RRPlayerWork; /* size = 0x15C */

/* A follower's state (D_8010AA18_14C3A8_RainbowRun[], RRPlayerWork::team; MP1 TTTeamWork, rebuilt:
   followers run along a looping path (func_80109240) instead of standing on the shore). No pointers. */
typedef struct RRTeamWork {
    /* 0x00 */ char unk_00[0x20];
    /* 0x20 */ f32 push[2];   /* zeroed only */
    /* 0x28 */ f32 angle;     /* facing (degrees) */
    /* 0x2C */ f32 turn;      /* added to the facing each frame */
    /* 0x30 */ Vec ofs;       /* offset from the path (z: pulled back when the course is pulled) */
    /* 0x3C */ Vec pos;       /* point on the path */
    /* 0x48 */ f32 target;    /* CPU stick angle, < 0: none */
    /* 0x4C */ char unk_4C[0xC];
    /* 0x58 */ f32 seg;       /* path segment 0..3 */
    /* 0x5C */ f32 t;         /* position in the segment, 0..240 */
    /* 0x60 */ f32 aim;       /* CPU aim error (degrees) */
    /* 0x64 */ s32 timer;     /* CPU frames since the last throw */
    /* 0x68 */ s32 aimWait;   /* CPU frames before a new aim error */
    /* 0x6C */ u16 throwWait; /* CPU frames between throws */
    /* 0x6E */ char unk_6E[2];
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ u16 btn;       /* CPU buttons */
    /* 0x76 */ u16 prevBtn;
    /* 0x78 */ u16 idx;       /* 0..2 */
    /* 0x7A */ s16 flash;     /* stunned (hit by a bomb) */
    /* 0x7C */ s16 wait;      /* frames before the follower moves on */
    /* 0x7E */ s16 aimTimer;
    /* 0x80 */ u8 unk_80[8];
    /* 0x88 */ u8 unk_88[8];
    /* 0x90 */ s8 port;
    /* 0x91 */ s8 player;
    /* 0x92 */ s8 unk_92;
    /* 0x93 */ char unk_93;
    /* 0x94 */ s8 sway;
    /* 0x95 */ s8 swayDir;
    /* 0x96 */ s8 noCtrl;
    /* 0x97 */ s8 hasSpot;
    /* 0x98 */ s8 spot;      /* D_8010A87C_14C20C_RainbowRun index */
    /* 0x99 */ s8 aimed;
    /* 0x9A */ s8 done;
    /* 0x9B */ char unk_9B;
} RRTeamWork; /* size = 0x9C */

#define RR_WORK(obj) ((RRPlayerWork*)(obj)->unk_50)

/* A bomb's state (D_8010AC20_14C5B0_RainbowRun[3], RRItemWork::bomb; MP1 TTBomb). No pointers. */
typedef struct RRBomb {
    /* 0x00 */ s8 active; /* the follower pressed A */
    /* 0x01 */ s8 lit;    /* thrown */
    /* 0x02 */ u16 idx;   /* the follower (D_8010AC14 index) */
    /* 0x04 */ s16 sound; /* the fuse sound's owner (func_80079798_7A398's second argument) */
    /* 0x06 */ s16 mdl[3]; /* 3D sprites (func_80021198_21D98): fuse, splash, explosion */
    /* 0x0C */ f32 ang;
    /* 0x10 */ f32 dir[3];
    /* 0x1C */ f32 pos[3];
    /* 0x28 */ f32 vy;
    /* 0x2C */ s32 timer;
    /* 0x30 */ f32 speed;
} RRBomb; /* size = 0x34 */

/* A thrown object's work: main's minigame work view, the state pointer at 0xA8 (MP1 0x68). */
typedef struct RRItemWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[6];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[0x23];
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ char unk_80[0x28];
    /* 0xA8 */ RRBomb* bomb;
} RRItemWork; /* size = 0xAC on the N64 */

#define RR_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* func_8007A27C_7AE7C's camera sprite work (src/7AA60.c's CamSprWork). */
typedef struct RRCamSprWork {
    /* 0x00 */ s16 sprId;
    /* 0x04 */ f32 scaleX;
    /* 0x08 */ f32 scaleY;
    /* 0x0C */ f32 baseScaleX;
    /* 0x10 */ f32 baseScaleY;
    /* 0x14 */ f32 baseZoom;
    /* 0x18 */ f32 offsetX;
    /* 0x1C */ f32 offsetY;
    /* 0x20 */ Vec planePos;
    /* 0x2C */ void (*draw)(struct RRCamSprWork*);
    /* 0x30 */ HuCamera* cam;
} RRCamSprWork; /* size 0x34 */

/* ---- overlay functions ---- */

/* 144190.c */
void func_80102800_144190_RainbowRun(void);
void func_80102F3C_1448CC_RainbowRun(RRCamSprWork* work);
void func_80103648_144FD8_RainbowRun(omObjData* obj);
s32 func_801036CC_14505C_RainbowRun(omObjData* obj, omObjData* other);
void func_8010393C_1452CC_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80103E1C_1457AC_RainbowRun(omObjData* obj);
void func_801041E4_145B74_RainbowRun(omObjData* obj);
void func_80104FB4_146944_RainbowRun(omObjData* obj);

/* 147180.c */
void func_801057F0_147180_RainbowRun(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_80105870_147200_RainbowRun(void);
void func_80105978_147308_RainbowRun(omObjData* obj);
void func_801059F0_147380_RainbowRun(omObjData* obj);
f32 func_80105A74_147404_RainbowRun(void);
void func_80105C40_1475D0_RainbowRun(Vec* pos, Vec* axis, f32 angle, Matrix4f m);
void func_80105E38_1477C8_RainbowRun(RRPlayerWork* work);
void func_80105ED4_147864_RainbowRun(omObjData* obj, f32 dist);
u32 func_80105F4C_1478DC_RainbowRun(u32 seed);
u32 func_80106020_1479B0_RainbowRun(void);

/* 1479E0.c */
void func_80106050_1479E0_RainbowRun(s16 model);
void func_801060D8_147A68_RainbowRun(omObjData* obj);
void func_80106838_1481C8_RainbowRun(void);
void func_80106CB8_148648_RainbowRun(omObjData* obj);
void func_80106D60_1486F0_RainbowRun(omObjData* obj);
void func_80106E70_148800_RainbowRun(omObjData* obj);
void func_80106E8C_14881C_RainbowRun(omObjData* obj);
void func_80107018_1489A8_RainbowRun(omObjData* obj);
void func_801075FC_148F8C_RainbowRun(omObjData* obj);

/* 149120.c */
s8 func_80107790_149120_RainbowRun(omObjData* obj);
void func_80107878_149208_RainbowRun(void);
void func_80107A68_1493F8_RainbowRun(omObjData* obj);
void func_80107C5C_1495EC_RainbowRun(omObjData* obj);
void func_80108094_149A24_RainbowRun(omObjData* obj);
void func_8010815C_149AEC_RainbowRun(omObjData* obj, s16 arg1, s16 arg2);
void func_801087A8_14A138_RainbowRun(omObjData* obj);
void func_801087CC_14A15C_RainbowRun(omObjData* obj);
void func_801087F0_14A180_RainbowRun(omObjData* obj);
void func_80108814_14A1A4_RainbowRun(omObjData* obj);
Vec func_80109240_14ABD0_RainbowRun(s8 path, s16 seg, f32 t);
void func_80109534_14AEC4_RainbowRun(omObjData* obj);
void func_80109CC4_14B654_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 idx);
void func_8010A42C_14BDBC_RainbowRun(omObjData* obj);
void func_8010A514_14BEA4_RainbowRun(omObjData* obj);
void func_8010A600_14BF90_RainbowRun(omObjData* obj);

/* MG0F-A */

/* ---- main-segment API used by 0F (missing from include/) ---- */

extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern u16 D_801011FC_101DFC;
extern f32 D_80102750_103350[]; /* D_8010274C_10334C + 4: [1] is its z by retail's own label */
void func_80069770_6A370(void);
/* func_8000BF24_CB24: its second argument (s32 in main) is a float that retail passes in a1: callers
   cast (on the host the s32 slot would get a converted value, not the bits) */
void func_8000BF24_CB24(omObjData*, s32, f32, f32, f32, f32);
void func_8000BFF0_CBF0(omObjData*);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
u8 rand8(void);
u16 func_80078EA8_79AA8(void);
extern u8 D_80102720_103320;
extern u8 D_800FDBE0_FE7E0; /* current vertex buffer */
extern s32 D_800F8FD0_F9BD0; /* scene state */
void func_8000C3B8_CFB8(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_80079848_7A448(s16 arg0); /* stop a sound */
extern u16 D_800FD410_FE010[4];
void func_80019E04_1AA04(omObjData* obj, s32 slot, s32 motion);
void func_80019CA4_1A8A4(omObjData* obj, s32 arg1);
void func_80019378_19F78(omObjData* obj); /* MP1 func_80017DB0 */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
void func_800797DC_7A3DC(s32, s16);
/* the player motion constants (MP1 D_800B895C..D_800B898C) */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A0_C03A0;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7B0_C03B0;
extern f32 D_800BF7BC_C03BC;
extern f32 D_800BF7C0_C03C0; /* top speed */
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
f32 sqrtf(f32);
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_80079798_7A398(s16, s16);
s32 PlaySound(s32);
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80021198_21D98(s16 index, u16 arg1);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
extern u16 D_800BF7E4_C03E4[][14]; /* per player sound ids */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8000CC74_D874(omObjData* obj, s16 model, s32 arg2);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
s16 func_8001A2F8_1AEF8(s32 arg0);
void espDispOff(u16);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8000C38C_CF8C(void);
void func_8000C3C8_CFC8(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_8000C018_CC18(u16);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
extern f32 D_800BF7AC_C03AC;
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
extern s32 D_800F9D30_FA930[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FC7B0_FD3B0[];
extern omObjData* D_800F9CE0_FA8E0[]; /* collision list, D_800FA606_FB206 entries */

/* An esprite slot (D_800F93FC_F9FFC[], 0x24 bytes). */
typedef struct RREspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} RREspSlot;
extern RREspSlot* D_800F93FC_F9FFC;

/* Per-character data, 0x18 bytes each. */
typedef struct RRCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} RRCharData;
extern RRCharData D_800CD438_CE038[];
void func_800B8070_B8C70(f32 angle, f32* sin, f32* cos);
void func_8002A00C_2AC0C(s16 model);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

/* ---- .data (14C080; in C per file: 144190 to A750, 147180 to A7A0, 1479E0 to A830, 149120) ---- */

extern s16 D_8010A6F0_14C080_RainbowRun; /* the game is over */
extern s8 D_8010A6F2_14C082_RainbowRun;
extern s8 D_8010A6F3_14C083_RainbowRun; /* the start message is done */
extern s8 D_8010A6F4_14C084_RainbowRun; /* the runner reached its start */
extern s8 D_8010A6F5_14C085_RainbowRun; /* the runner cannot be hit */
extern s8 D_8010A6F6_14C086_RainbowRun; /* result: 1 fell, 2 time up, 3 reached the goal */
extern s8 D_8010A6F7_14C087_RainbowRun; /* the timer is stopped */
extern s8 D_8010A6F8_14C088_RainbowRun; /* the course is being pulled forward */
extern f32 D_8010A6FC_14C08C_RainbowRun; /* this frame's camera advance */
extern s8 D_8010A700_14C090_RainbowRun;
extern s8 D_8010A701_14C091_RainbowRun;
extern s8 D_8010A702_14C092_RainbowRun; /* the runner reached the goal */
extern s8 D_8010A703_14C093_RainbowRun;
extern s32 D_8010A704_14C094_RainbowRun[2]; /* the title sprite's scroll x, y */
extern s8 D_8010A70C_14C09C_RainbowRun; /* the runner leans sideways */
extern s8 D_8010A70D_14C09D_RainbowRun;
extern s8 D_8010A70E_14C09E_RainbowRun; /* the runner is falling */
extern s8 D_8010A70F_14C09F_RainbowRun;
extern s8 D_8010A710_14C0A0_RainbowRun; /* the music is stopped */
extern s8 D_8010A711_14C0A1_RainbowRun;
extern s8 D_8010A712_14C0A2_RainbowRun;
extern s8 D_8010A713_14C0A3_RainbowRun;
extern s8 D_8010A714_14C0A4_RainbowRun; /* the run-in's motions are set */
extern s8 D_8010A715_14C0A5_RainbowRun; /* run-in frames with button 0x8000 */
extern f32 D_8010A718_14C0A8_RainbowRun; /* z of the next course pull */
extern s32 D_8010A71C_14C0AC_RainbowRun;
extern f32 D_8010A720_14C0B0_RainbowRun;
extern s16 D_8010A724_14C0B4_RainbowRun; /* course pulls so far */
extern u32 D_8010A728_14C0B8_RainbowRun; /* frames before the start message */
extern s8 D_8010A72C_14C0BC_RainbowRun; /* the fade-out started */
extern s8 D_8010A72D_14C0BD_RainbowRun; /* the result is paid */
extern s32 D_8010A730_14C0C0_RainbowRun; /* time left, frames */
extern s32 D_8010A734_14C0C4_RainbowRun;
extern s8 D_8010A738_14C0C8_RainbowRun;
extern s32 D_8010A73C_14C0CC_RainbowRun; /* frames to show the result */
extern s32 D_8010A740_14C0D0_RainbowRun;
extern s16 D_8010A744_14C0D4_RainbowRun; /* opening pan frame */
extern s8 D_8010A746_14C0D6_RainbowRun;
extern s8 D_8010A747_14C0D7_RainbowRun;
extern s8 D_8010A750_14C0E0_RainbowRun; /* the followers are being pulled */
extern s8 D_8010A751_14C0E1_RainbowRun; /* the camera shakes */
extern s16 D_8010A752_14C0E2_RainbowRun; /* shake frame */
extern f32 D_8010A754_14C0E4_RainbowRun;
extern f32 D_8010A758_14C0E8_RainbowRun[]; /* shake offsets x, y: [i * 2] */
extern f32 D_8010A75C_14C0EC_RainbowRun[]; /* [i * 2] (D_8010A758 + 4, retail's own label) */
extern s8 D_8010A778_14C108_RainbowRun; /* the fade-out started */
extern s8 D_8010A77C_14C10C_RainbowRun[8]; /* stick x history */
extern s8 D_8010A784_14C114_RainbowRun[8]; /* stick y history */
extern s8 D_8010A78C_14C11C_RainbowRun; /* next slot of the stick histories */
extern u16 D_8010A78E_14C11E_RainbowRun; /* func_80105E38's last buttons */
extern u32 D_8010A790_14C120_RainbowRun; /* random seed */
extern s8 D_8010A7A4_14C134_RainbowRun;
extern s16 D_8010A7A6_14C136_RainbowRun; /* a sound to stop */
extern s8 D_8010A7A8_14C138_RainbowRun; /* the goal was reached (set up) */
extern f32 D_8010A7D0_14C160_RainbowRun; /* x of the course's middle */
extern f32 D_8010A7D4_14C164_RainbowRun; /* y of the course */
extern f32 D_8010A7D8_14C168_RainbowRun; /* last frame's D_8010A7D0 */
extern f32 D_8010A7DC_14C16C_RainbowRun; /* D_8010A7D0's change this frame */
extern f32 D_8010A7E0_14C170_RainbowRun; /* the rainbow's sway, -20..20 */
extern f32 D_8010A7E4_14C174_RainbowRun; /* the ripple's phase */
extern s8 D_8010A7E8_14C178_RainbowRun; /* the sway's direction */
extern s8 D_8010A7E9_14C179_RainbowRun; /* the runner passed z -1150 */

/* ---- .bss ---- */

extern Vec D_8010A990_14C320_RainbowRun; /* the title camera's eye */
extern Vec D_8010A99C_14C32C_RainbowRun; /* the title camera's target */
extern f32 D_8010A9A8_14C338_RainbowRun; /* the goal camera's rot x step */
extern f32 D_8010A9AC_14C33C_RainbowRun; /* centre y step */
extern f32 D_8010A9B0_14C340_RainbowRun; /* centre z step */
extern f32 D_8010ABFC_14C58C_RainbowRun[2]; /* wind drift x, z */
extern f32 D_8010AC0C_14C59C_RainbowRun; /* the sway (copy) */
extern omObjData* D_8010AC14_14C5A4_RainbowRun[3]; /* the followers */
extern s8 D_8010ACC0_14C650_RainbowRun[4]; /* [0] the player of group 0, [1..3] the others */
extern omObjData* D_8010ACC4_14C654_RainbowRun[3];

extern f32 D_8010AA10_14C3A0_RainbowRun; /* camera zoom */
extern f32 D_8010ABEC_14C57C_RainbowRun; /* camera centre y */
extern f32 D_8010ABF4_14C584_RainbowRun; /* camera rot z */
extern f32 D_8010ABF8_14C588_RainbowRun; /* camera rot y */
extern f32 D_8010AC04_14C594_RainbowRun; /* camera centre z */
extern f32 D_8010AC10_14C5A0_RainbowRun; /* camera rot x */
extern f32 D_8010ACBC_14C64C_RainbowRun; /* camera centre x */
extern ColVtx* D_8010A9C0_14C350_RainbowRun; /* the rainbow's base vertices (func_80106050) */

/* MG0F-B */

void func_800795D8_7A1D8(s16 sound, s16 volume); /* sound volume */
extern f32 D_8010A7AC_14C13C_RainbowRun[7]; /* wind directions */
extern s8 D_8010A7C8_14C158_RainbowRun; /* wind direction (6: none) */
extern f32 D_8010A7CC_14C15C_RainbowRun; /* wind strength */
extern s8 D_8010A7EA_14C17A_RainbowRun; /* the wind sound fades out */
extern s8 D_8010A7EB_14C17B_RainbowRun; /* wind sound volume */
extern s8 D_8010A7EC_14C17C_RainbowRun; /* the wind blows */
extern s8 D_8010A7ED_14C17D_RainbowRun; /* waiting for the next gust */
extern s8 D_8010A7EE_14C17E_RainbowRun; /* this gust's direction */
extern s8 D_8010A7EF_14C17F_RainbowRun; /* the last gust's direction */
extern s8 D_8010A7F0_14C180_RainbowRun; /* the wind is set up */
extern s32 D_8010A7F4_14C184_RainbowRun; /* gust frame */
extern s32 D_8010A7F8_14C188_RainbowRun; /* gust length */
extern s32 D_8010A7FC_14C18C_RainbowRun; /* frames between gusts */
extern s32 D_8010A800_14C190_RainbowRun; /* the goal's model is hidden */

/* A ground object's work (func_80027154_27D54(0xB4); MP1 TTGroundWork's 0x04/0x05 at 0x03/0x04).
   No pointers. */
typedef struct RRGround {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04; /* ground id */
    /* 0x05 */ char unk_05[0xAF];
} RRGround; /* size = 0xB4 */

/* Main's collision grids (src/2E0D0.c's HitGrid; only the cell width is used here). */
typedef struct RRHitGrid {
    /* 0x00 */ s32 w;
    /* 0x04 */ s32 h;
    /* 0x08 */ f32 cw;
    /* 0x0C */ f32 ch;
    /* 0x10 */ char unk_10[0x14]; /* pointers on the N64 */
} RRHitGrid;
extern RRHitGrid* D_800FD2B8_FDEB8;
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
s16 LoadFormFile(s32, s32);
u16 func_80018A30_19630(s32, s32); /* model load */
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);

/* S4-0F */

f32 func_8002662C_2722C(f32* keys, f32* times, f32 t); /* spline through four keys */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029E80_2AA80(s16, s32, s32);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_8000BE74_CA74(omObjData*, f32);
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BEBC_CABC(omObjData*, f32);
void func_8000BEC8_CAC8(omObjData*, f32);
void func_80020070_20C70(s32); /* camera setup */
extern f32 D_8010A804_14C194_RainbowRun[4][2]; /* the clouds' x, z: [0] the group, [1..3] offsets */
extern f32 D_8010A808_14C198_RainbowRun[]; /* D_8010A804 + 4, retail's own label */
extern s8 D_8010A824_14C1B4_RainbowRun; /* the clouds are shown */
extern Vec D_8010A830_14C1C0_RainbowRun[6]; /* the followers' path points (retail's own labels D_8010A834/838: .y, .z) */
/* the four spots (angles 20, 50, 310, 340); the code addresses the used flags by the +4 label
   D_8010A87C (an undefined_syms.txt alias) */
typedef struct RRSpot {
    /* 0x00 */ f32 angle;
    /* 0x04 */ s8 used;
} RRSpot;
extern RRSpot D_8010A878_14C208_RainbowRun[4];
extern s8 D_8010A87C_14C20C_RainbowRun[][8];
extern s8 D_8010A898_14C228_RainbowRun[4]; /* a bomb's fuse sound is playing */
extern s8 D_8010A89C_14C22C_RainbowRun[6][4]; /* the paths: four of D_8010A830's points each */
extern f32 D_8010A9D0_14C360_RainbowRun[4]; /* func_80109240's spline keys */
extern f32 D_8010A9E0_14C370_RainbowRun[4]; /* func_80109240's spline times */
/* the bombs' shared models and sprites: [0] bomb, [1] shadow, [2..4] fuse/splash/explosion sprite ids
   (retail's own labels D_8010A9F4/9F6/9F8); -1 until loaded */
extern s16 D_8010A9F0_14C380_RainbowRun[8];
extern s16 D_8010AA00_14C390_RainbowRun[3]; /* the followers' shared shadow model */
extern RRTeamWork D_8010AA18_14C3A8_RainbowRun[3];
extern s8 D_8010ABF0_14C580_RainbowRun; /* path set: 0 or 3 */
extern f32 D_8010AC00_14C590_RainbowRun; /* D_8010ABFC[1] by retail's own label */
extern s8 D_8010AC08_14C598_RainbowRun[3]; /* the followers' paths, shuffled (+ D_8010ABF0) */
extern RRBomb D_8010AC20_14C5B0_RainbowRun[3]; /* splat labels its fields (D_8010AC21..AC4C) */
void HmfModelObjAttrSet(s16, s32, s32);
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4); /* MP1 func_80009340 */
u16 func_80018A64_19664(s32 arg0, s32 arg1);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2); /* 3D sprite (MP1 func_8001E00C) */
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);

#endif
