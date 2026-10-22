#ifndef _OVL_2C_H
#define _OVL_2C_H

/* Overlay 2C (223D30.c): Tipsy Tourney, MP1's ovl_21_TipsyTourney (1A4EB0.c) ported to MP2's
   main API. Four tilting platforms (one per player, split screen), each with a ball the player
   rolls by walking on the platform; flipping all 25 tiles of a platform wins. */

#include "common.h"
#include "game/object.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/hmfman.h"

typedef f32 Matrix4f[4][4];

typedef struct Vec4f {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4f;

/* ---- structs ---- */

/* Work of the board object and of the four platforms (func_80027154_27D54(0xB4)). No pointers. */
typedef struct TipsyBgWork {
    /* 0x00 */ char unk_00[3];
    /* 0x03 */ u8 unk_03; /* MP1 0x04 */
    /* 0x04 */ u8 unk_04; /* platform 1..4 (0 for the board object); D_800FC7B0_FD3B0 index (MP1 0x05) */
    /* 0x05 */ char unk_05[0xAF];
} TipsyBgWork; /* size = 0xB4 (MP1 0x2C) */

/* Work of the players (main's MgWork, C8E0.c) and of the balls in D_800F9CE0_FA8E0. */
typedef struct TipsyWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* platform it is on (TipsyBgWork::unk_05), -1 none */
    /* 0x54 */ u8 unk_54; /* ball: 1 still held up (not yet dropped) */
    /* 0x55 */ char unk_55[2];
    /* 0x57 */ s8 unk_57; /* controller port */
    /* 0x58 */ char unk_58;
    /* 0x59 */ s8 unk_59; /* player */
    /* 0x5A */ char unk_5A[2];
    /* 0x5C */ s32 unk_5C; /* ball: index 0..3 into the per-ball tables */
    /* 0x60 */ char unk_60[0x88];
    /* 0xE8 */ void* unk_E8; /* MgWork motion table (MgMotion*) */
    /* 0xEC */ void* unk_EC; /* collision callback */
    /* 0xF0 */ char unk_F0[0x6C];
} TipsyWork; /* size = 0x15C (N64) */

/* Work of a ball (func_80104318, func_80027154_27D54(0xAC)): TipsyWork's first 0xAC bytes, with
   unk_53 unsigned (0xFF once it has fallen off). No pointers. */
typedef struct TipsyBallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk_3C; /* direction */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* platform it is on (TipsyBgWork::unk_04), -1 none (MP1 u8) */
    /* 0x54 */ u8 unk_54; /* 1 until it is released (the timer runs out or a player wins) */
    /* 0x55 */ char unk_55[0x23];
    /* 0x78 */ s32 unk_78; /* index 0..3 into the per-ball tables (MP1 0x5C) */
    /* 0x7C */ char unk_7C[0x30];
} TipsyBallWork; /* size = 0xAC (MP1 0x6C) */

#define TIPSY_WORK(obj) ((TipsyWork*)(obj)->unk_50)
#define TIPSY_BG(obj) ((TipsyBgWork*)(obj)->unk_50)

/* A CPU's dash direction (D_80107D78_2292A8): retail stores the halves and reads their low
   bytes (D_80107D79 / D_80107D7B) as the stick values. */
typedef struct TipsyDash {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
} TipsyDash;

/* ---- main-segment declarations ---- */

/* Per-character data, 0x18 bytes each (ovl_34's CTCharData); unk_04 is the character's
   file directory. */
typedef struct TipsyCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* motion file directory (MP1 D_800C59AC unk_00) */
    /* 0x08 */ s32 unk_08; /* MP1 D_800C59AC unk_04 */
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} TipsyCharData; /* size = 0x18 */
extern TipsyCharData D_800CD438_CE038[];

void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* MP1 func_8000979C */
void func_8000BDC4_C9C4(omObjData* obj, s32 slot, s32 file, s32 attr, f32 arg4);
void func_8000CC74_D874(omObjData* obj, s16 model, s32 arg2);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);

extern omObjData* D_800F9CE0_FA8E0[]; /* collision list, D_800FA606_FB206 entries (MP1 D_800EDE70) */
extern u16 D_800FA606_FB206;
extern omObjData* D_800FC7B0_FD3B0[];
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern s32 D_800F9D30_FA930[];
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7D4_C03D4;
extern f32 D_800F94A0_FA0A0;
extern f32 D_80101308_101F08;
extern u8 D_80102720_103320;
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Gfx* D_800FDBCC_FE7CC;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z); /* rotate matrix */
extern u8 D_800FDBE0_FE7E0; /* frame buffer index */

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s32);
void func_80029708_2A308(s32);
void func_8000C38C_CF8C(void);
void func_80018ED0_19AD0(s32);
void func_80018F58_19B58(s32);
void func_8000C460_D060(void);
void func_8000C56C_D16C(s32);
void func_8000C578_D178(s32);
void func_8000C018_CC18(u16);
void func_8002CD6C_2D96C(s32);
void func_80079FF4_7ABF4(omObjData* obj);
f32 fabsf(f32);
f64 fabs(f64);
void HmfModelObjAttrSet(s16, s32, s32);
void espDispOff(u16);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BF24_CB24(omObjData*, s32, f32, f32, f32, f32);
void func_8000BFF0_CBF0(omObjData*);
void func_8000C004_CC04(omObjData*);
void func_8000C37C_CF7C(omObjData*, f32, f32, f32);
u16 func_80018A30_19630(s32, s32); /* model load */
void func_80029C74_2A874(s16, f32);
void func_80029EDC_2AADC(s16, s32);
void func_8002A00C_2AC0C(s16);
u16 func_80078EA8_79AA8(void);
void func_8000C3C8_CFC8(void);
s16 func_80079798_7A398(s16 sfx, s16 player); /* play a sound effect for a player */
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* C8E0.c: player motion */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
extern f32 D_800BF7D0_C03D0; /* MP1 D_800B8990 */
void func_8000C3B8_CFB8(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_80079614_7A214(s32);
extern u16 D_801011FC_101DFC;
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
s16 LoadFormFile(s32, s32);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32, f32); /* atan2 */
f32 func_800B1830_B2430(f32); /* sqrtf */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16 arg0);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val); /* ((u8*)obj->unk_50)[idx] = val */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s32 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16, s32, s32);

void func_8000D434_E034(Matrix4f m, Matrix4f out, Vec3f* p, omObjData* obj);
void func_8000DCD4_E8D4(omObjData*, f32, f32);
void func_80009684_A284(f32, f32, f32);
void func_8002D9AC_2E5AC(Vec3f*);
f32 func_8002D958_2E558(f32);
void func_8003C984_3D584(s16, Vec3f*);
s32 func_80006F34_7B34(omObjData*, Vec4f*, f32);
f32 func_800023CC_2FCC(omObjData*, f32, f32, f32, Vec3f*);
void func_8003F710_40310(Gfx** arg0, void* timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                         s32 shiftt);

/* ---- overlay data (.data / .bss, asm) ---- */

extern f32 D_80107B80_2290B0_TipsyTourney;          /* ball drift scale: 20, 30 while playing, 0 after */
extern s16 D_80107B84_2290B4_TipsyTourney;          /* frames since the end */
extern s16 D_80107B88_2290B8_TipsyTourney[4][5][5]; /* tile state per platform: 0 up, >0 sinking, -1 gone */
extern Vec3f D_80107C50_229180_TipsyTourney[4];     /* ball position in its platform's space */
extern s8 D_80107C80_2291B0_TipsyTourney;           /* winner, -1 none */
extern s32 D_80107C84_2291B4_TipsyTourney;
extern s32 D_80107C88_2291B8_TipsyTourney; /* time left */
extern s32 D_80107C8C_2291BC_TipsyTourney;
extern s32 D_80107C90_2291C0_TipsyTourney;
extern Gfx D_80107C98_2291C8_TipsyTourney[];
extern Vec3f D_80107CD8_229208_TipsyTourney[4]; /* ball spin (x, -, z) */
extern f32 D_80107D08_229238_TipsyTourney[4];   /* ball yaw */
extern Vec3f D_80107D18_229248_TipsyTourney[4]; /* ball ground normal */
extern f32 D_80107D48_229278_TipsyTourney[4];   /* CPU stick strength */
extern u16 D_80107D58_229288_TipsyTourney[4];   /* CPU frames before the next choice */
extern f32 D_80107D60_229290_TipsyTourney[4];   /* CPU circling direction (+1 / -1) */
extern s16 D_80107D70_2292A0_TipsyTourney[4];   /* CPU dash cooldown */
extern TipsyDash D_80107D78_2292A8_TipsyTourney[4];

extern f32 D_80107DA0_2292D0_TipsyTourney;
extern f32 D_80107DA4_2292D4_TipsyTourney;
extern Matrix4f D_80107DA8_2292D8_TipsyTourney;
extern Matrix4f D_80107DE8_229318_TipsyTourney;
extern s32 D_80107E28_229358_TipsyTourney[4]; /* motion-0xD file per player */
extern s32 D_80107E38_229368_TipsyTourney[4]; /* motion-0xE file per player */
extern s16 D_80107E48_229378_TipsyTourney[4][5][5]; /* tile -> model part of the platform */
extern s16 D_80107F10_229440_TipsyTourney;          /* background sprite group */

/* ---- functions ---- */

void func_80102800_223D30_TipsyTourney(void);
void func_80102ED0_224400_TipsyTourney(void);
void func_80102EF8_224428_TipsyTourney(void);
void func_80102F24_224454_TipsyTourney(omObjData* obj, u8 state, u32 time);
void func_80102F94_2244C4_TipsyTourney(omObjData* obj);
void func_801032FC_22482C_TipsyTourney(omObjData* obj);
void func_801034E8_224A18_TipsyTourney(omObjData* obj);
void func_801036A8_224BD8_TipsyTourney(omObjData* obj);
void func_80103864_224D94_TipsyTourney(omObjData* obj);
void func_80103A24_224F54_TipsyTourney(omObjData* obj);
void func_80103BE4_225114_TipsyTourney(omObjData* obj, s32 dir, s32 file0, s32 file1, u16 idx, f32 x, f32 y, f32 z);
void func_80103EAC_2253DC_TipsyTourney(omObjData* obj);
void func_80103FC4_2254F4_TipsyTourney(omObjData* obj);
void func_801040E0_225610_TipsyTourney(omObjData* obj);
void func_801041FC_22572C_TipsyTourney(omObjData* obj);
void func_80104318_225848_TipsyTourney(omObjData* obj, s32 file, f32 scale, f32 angle, f32 x, f32 y, f32 z, s32 idx);
void func_80104458_225988_TipsyTourney(omObjData* obj);
void func_80104520_225A50_TipsyTourney(omObjData* obj);
void func_801045EC_225B1C_TipsyTourney(omObjData* obj);
void func_801046BC_225BEC_TipsyTourney(omObjData* obj);
void func_8010478C_225CBC_TipsyTourney(omObjData* obj);
void func_801047F0_225D20_TipsyTourney(void);
void func_80104AEC_22601C_TipsyTourney(omObjData* obj);
void func_80104FC4_2264F4_TipsyTourney(omObjData* obj, f32 dx, f32 dz);
f32 func_801050C4_2265F4_TipsyTourney(omObjData* obj);
f32 func_80105378_2268A8_TipsyTourney(omObjData* obj);
void func_80105628_226B58_TipsyTourney(omObjData* obj);
void func_801057F4_226D24_TipsyTourney(omObjData* obj);
void func_80105AC0_226FF0_TipsyTourney(omObjData* obj);
void func_80105BA8_2270D8_TipsyTourney(void);
void func_80105C40_227170_TipsyTourney(void);
void func_80105D28_227258_TipsyTourney(s16 model, s32 p);
void func_80105FF0_227520_TipsyTourney(s16 model, s32 p);
void func_8010643C_22796C_TipsyTourney(omObjData* obj);
f32 func_80106514_227A44_TipsyTourney(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal);
void func_80106600_227B30_TipsyTourney(omObjData* obj, Vec3f* normal);
void func_8010678C_227CBC_TipsyTourney(omObjData* obj);
void func_80106C48_228178_TipsyTourney(omObjData* obj);
s32 func_80106D14_228244_TipsyTourney(s32 p);
s32 func_80106E64_228394_TipsyTourney(s32 p);
s32 func_80106F94_2284C4_TipsyTourney(s32 p);
void func_80107048_228578_TipsyTourney(omObjData* obj);
void func_801078DC_228E0C_TipsyTourney(Vec4f* p);
s32 func_80107A0C_228F3C_TipsyTourney(omObjData* obj, omObjData* other);

#endif /* _OVL_2C_H */
