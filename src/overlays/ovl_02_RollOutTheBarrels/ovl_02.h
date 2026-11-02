#ifndef _OVL_02_H
#define _OVL_02_H

/* Overlay 02: Roll Out the Barrels. One retail file, E3A40.c; .data up to 0xF3680, .rodata carved
   from there. D_80112D78_F3FB8_RollOutTheBarrels is the flow state, D_80112D7A_F3FBA_RollOutTheBarrels the timer in frames. N64 offsets
   are in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* MgWork 0x68: a float there, char padding in collision.h. */
#define RB_W68(w) (*(f32*)(w)->unk_68)

#define RB_WRAP(v)                 \
    if ((v) >= 360.0) {            \
        (v) -= 360.0;              \
    } else if ((v) < 0.0) {        \
        (v) += 360.0;              \
    }

/* log2 of a texture side, rounded up: a tile's mask. */
#define RB_LOG2(x)                                                                                             \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 0x11 ? 4 : (x) < 0x21 ? 5 : (x) < 0x41 ? 6 : (x) < 0x81 ? 7 \
                                                                                 : (x) < 0x101 ? 8 : 9)

/* A pointer retail packs byte by byte: a 4-byte value built in a register. */
typedef struct RBBytes {
    u32 a : 8;
    u32 b : 8;
    u32 c : 8;
    u32 d : 8;
} RBBytes;

typedef union RBPack {
    void* p;
    RBBytes b;
} RBPack;

/* A camera position (D_80112DD8_F4018_RollOutTheBarrels: [0] the target, [1] the start of a blend). */
typedef struct RBCamera {
    /* 0x00 */ Vec center;
    /* 0x0C */ Vec rot;
    /* 0x18 */ f32 zoom;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} RBCamera; /* size = 0x24 */

typedef struct RBCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;
    /* 0x08 */ s32 model;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} RBCharData; /* size = 0x18 */

/* The player's own state (D_80112D60_F3FA0_RollOutTheBarrels, 0x38 bytes, kept packed in the object's work[]). */
typedef struct RBPlayer {
    /* 0x00 */ s16 target; /* -1 none */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 pathIdx;
    /* 0x0A */ s16 pathLen;
    /* 0x0C */ Vec* path; /* 0xC0 bytes */
    /* 0x10 */ s16 state;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 pushed;
    /* 0x1C */ f32 pushSpeed;
    /* 0x20 */ f32 pushAngle;
    /* 0x24 */ f32 pushDist;
    /* 0x28 */ f32 pushDone;
    /* 0x2C */ s16 pushCount;
    /* 0x2E */ s16 motState;
    /* 0x30 */ s16 unk_30[4];
} RBPlayer; /* size = 0x38 */

/* A collision cylinder (D_80112D6C_F3FAC_RollOutTheBarrels, 16). */
typedef struct RBShape {
    /* 0x00 */ s16 used;
    /* 0x02 */ s16 hit;
    /* 0x04 */ s16 solid;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 radius;
    /* 0x0C */ f32 height;
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec offset;
    /* 0x28 */ omObjData* parent; /* its position is copied to pos */
    /* 0x2C */ void (*hook)();
} RBShape; /* size = 0x30 */

/* D_80112D64_F3FA4_RollOutTheBarrels, 6: the things rolling down the course. */
typedef struct RBRoller {
    /* 0x00 */ s16 used;
    /* 0x02 */ s16 kind; /* -1 none yet */
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 timer;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s16 mdl[12]; /* model, then its motions */
    /* 0x28 */ s16 shadow; /* -1 none */
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ s16 pathIdx;
    /* 0x2E */ s16 pathLen;
    /* 0x30 */ Vec* path; /* 0xC0 bytes */
    /* 0x34 */ void (*hook)(struct RBRoller*);
} RBRoller; /* size = 0x38 */

/* A barrel (D_80112D68_F3FA8_RollOutTheBarrels, 6). */
typedef struct RBBarrel {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ RBShape* shape;
    /* 0x08 */ s16 idx;
    /* 0x0A */ s16 kind; /* the prize inside, -1 none */
    /* 0x0C */ s16 roller; /* D_80112D64_F3FA4_RollOutTheBarrels index */
    /* 0x0E */ s16 unk_0E; /* flags: 1, 2 rest pose, 4 and up */
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec rot;
    /* 0x34 */ Vec scale;
    /* 0x40 */ s32 unk_40[4];
    /* 0x50 */ f32 unk_50[4];
} RBBarrel; /* size = 0x60 */

/* One step of the barrel shuffle. */
typedef void (*RBStep)(omObjData*);

/* What SprAnimGet returns: only the size is read here. */
typedef struct RBAnim {
    /* 0x00 */ HuSprite_Unk84_Unk00_Struct* unk00;
    /* 0x04 */ void* unk04;
    /* 0x08 */ void* tlut; /* the 16-bit texture of the course scroll */
    /* 0x0C */ void* unk0C;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 w;
    /* 0x16 */ u16 h;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
} RBAnim;

/* D_80112D70, 48: dust and spark sprites. */
typedef struct RBSpark {
    /* 0x00 */ s32 spr; /* read as its low half */
    /* 0x04 */ s32 used;
    /* 0x08 */ s32 life;
    /* 0x0C */ Vec pos;
} RBSpark; /* size = 0x18 */

/* The course mesh's vertices: their column and row (D_80112DA8). */
typedef struct RBMeshVtx {
    /* 0x0 */ s16 move; /* 0 on the edge */
    /* 0x2 */ s16 col;
    /* 0x4 */ s16 row;
} RBMeshVtx; /* size = 6 */

/* Main. */
extern RBCharData D_800CD438_CE038[];
extern u8 D_800FDBCA_FE7CA;
extern u16 D_800FA606_FB206;
extern s16 D_800FA1AA_FADAA;
extern s32 D_800F8FD0_F9BD0;
extern u16 D_801011FC_101DFC;
extern u16 D_800FC87A_FD47A;
extern omObjData* D_800FFFD8_100BD8[];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_800FDBE0_FE7E0;
extern s16 D_800CAFD8[];
extern u8 D_80102720_103320;
extern s32 fontcolor;
extern char pfStrBuf[];
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7D4_C03D4;

s16 DrawDebugText(u16, u16, char*);
void HuMemFree(void*);
s32 PlaySound(s32);
RBAnim* SprAnimGet(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
f32 func_800B75A8_B81A8(f32 y, f32 x);
f64 func_800B0D98_B1998(f64 x, f64 y);
void func_800B0EF0_B1AF0(void*, s32, s32);
void* memcpy(void*, const void*, u32);
f32 fabsf(f32);
f64 fabs(f64);
s16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80007790_8390(omObjData* obj);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
s32 func_8000CDC8_D9C8(omObjData* obj, s16 x, s16 y);
u16 func_80018A30_19630(s32 file, s32 attr);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80019378_19F78(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80020D20_21920(s16 arg0);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
s32 func_80027FA4_28BA4(u32 file, void* gfx, u8 arg2);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
void func_8002A00C_2AC0C(s16 model);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_800732B0_73EB0(s32);
u16 func_80078EA8_79AA8(void);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_80079848_7A448(s16 arg0);
void func_8008221C_82E1C(s16 group, s16 member, f32 alpha);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);

void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_800824B4_830B4(s16 group, s16 member, u8 r, u8 g, u8 b, u8 a);
extern s16 D_800FFFD6_100BD6; /* current viewport */
void func_800B1FA0_B2BA0(Mtx* m, f32 x, f32 y, f32 z); /* guTranslate */
int abs(int);
extern f32 D_800CA02C_CAC2C;
extern u16 D_800CAFE4[];

/* .data */
extern Vec D_801120A0_F32E0_RollOutTheBarrels[7]; /* the barrel slots */
extern s32 D_80112120_F3360_RollOutTheBarrels[6]; /* win voice per character */
extern s32 D_80112138_F3378_RollOutTheBarrels[6]; /* lose voice per character */
extern s32 D_80112150_F3390_RollOutTheBarrels;
extern s32 D_80112154_F3394_RollOutTheBarrels;
extern s32 D_80112158_F3398_RollOutTheBarrels;
extern s32 D_8011215C_F339C_RollOutTheBarrels;
extern s32 D_80112160_F33A0_RollOutTheBarrels;
extern s32 D_80112164_F33A4_RollOutTheBarrels;
extern Vec D_80112168_F33A8_RollOutTheBarrels; /* the player's start */
extern Vec D_80112174_F33B4_RollOutTheBarrels;
extern Vec D_80112180_F33C0_RollOutTheBarrels;
extern f32 D_8011218C_F33CC_RollOutTheBarrels[2];
extern Vec D_80112194_F33D4_RollOutTheBarrels[3];
extern u16 D_801121B8_F33F8_RollOutTheBarrels;
extern f64 D_801121C0_F3400_RollOutTheBarrels;
extern f64 D_801121C8_F3408_RollOutTheBarrels;
extern f64 D_801121D0_F3410_RollOutTheBarrels;
extern f64 D_801121D8_F3418_RollOutTheBarrels;
extern f32 D_801121E0_F3420_RollOutTheBarrels[2];
extern f32 D_801121E8_F3428_RollOutTheBarrels[2];
extern f32 D_801121F0_F3430_RollOutTheBarrels[2];
extern f32 D_801121F8_F3438_RollOutTheBarrels[3][4];
extern f32 D_80112228_F3468_RollOutTheBarrels[4];
extern s32 D_80112238_F3478_RollOutTheBarrels;
extern Vec D_8011223C_F347C_RollOutTheBarrels;
extern f32 D_80112248_F3488_RollOutTheBarrels[2];
extern RBStep* D_80112250_F3490_RollOutTheBarrels[4]; /* the shuffle steps of each round */
extern u8 D_80112264_F34A4_RollOutTheBarrels[16]; /* step lengths */
extern s32 D_80112274_F34B4_RollOutTheBarrels;
extern s32 D_80112278_F34B8_RollOutTheBarrels;
extern s32 D_8011227C_F34BC_RollOutTheBarrels;

/* .bss */
extern f32 D_80112CD0_F3F10_RollOutTheBarrels[2];
extern RBStep D_80112CD8_F3F18_RollOutTheBarrels[24]; /* the shuffle, null ended */
extern omObjData* D_80112D38_F3F78_RollOutTheBarrels;
extern omObjData* D_80112D3C_F3F7C_RollOutTheBarrels;
extern omObjData* D_80112D40_F3F80_RollOutTheBarrels;
extern omObjData* D_80112D44_F3F84_RollOutTheBarrels;
extern s32 D_80112D50_F3F90_RollOutTheBarrels[4]; /* the player's fall/voice motions */
extern RBPlayer* D_80112D60_F3FA0_RollOutTheBarrels;
extern RBRoller* D_80112D64_F3FA4_RollOutTheBarrels;
extern RBBarrel* D_80112D68_F3FA8_RollOutTheBarrels;
extern RBShape* D_80112D6C_F3FAC_RollOutTheBarrels;
extern RBSpark* D_80112D70_F3FB0_RollOutTheBarrels;
extern s32* D_80112D74_F3FB4_RollOutTheBarrels; /* 0x80 bytes; [0] the barrel sprite, [1] the dust sprite, read by their low halves */
extern s16 D_80112D78_F3FB8_RollOutTheBarrels;
extern s16 D_80112D7A_F3FBA_RollOutTheBarrels;
extern s8 D_80112D7C_F3FBC_RollOutTheBarrels;
extern s32 D_80112D80_F3FC0_RollOutTheBarrels;
extern Vec* D_80112D84_F3FC4_RollOutTheBarrels; /* 10 */
extern s32* D_80112D88_F3FC8_RollOutTheBarrels; /* 5 */
extern s32 D_80112D8C_F3FCC_RollOutTheBarrels;
extern s32 D_80112D90_F3FD0_RollOutTheBarrels;
extern s32 D_80112D94_F3FD4_RollOutTheBarrels;
extern s32 D_80112D98_F3FD8_RollOutTheBarrels;
extern s32 D_80112D9C_F3FDC_RollOutTheBarrels;
extern s32 D_80112DA0_F3FE0_RollOutTheBarrels;
extern s32 D_80112DA4_F3FE4_RollOutTheBarrels;
extern f32 D_80112DAC_F3FEC_RollOutTheBarrels[2];
extern s32 D_80112DB8_F3FF8_RollOutTheBarrels;
extern s16 D_80112DBC_F3FFC_RollOutTheBarrels;
extern s16 D_80112DBE_F3FFE_RollOutTheBarrels;
extern s32 D_80112DC0_F4000_RollOutTheBarrels; /* the solo player */
extern s32 D_80112DC4_F4004_RollOutTheBarrels; /* its character */
extern s32 D_80112DC8_F4008_RollOutTheBarrels; /* its port */
extern s32 D_80112DCC_F400C_RollOutTheBarrels; /* it is a CPU */
extern s32 D_80112DD0_F4010_RollOutTheBarrels;
extern RBCamera D_80112DD8_F4018_RollOutTheBarrels[2];
extern s32 D_80112E20_F4060_RollOutTheBarrels;
extern s32 D_80112E24_F4064_RollOutTheBarrels;
extern RBStep D_80112E28_F4068_RollOutTheBarrels;
extern Vec4f D_80112E30_F4070_RollOutTheBarrels[4];
extern Vec4f D_80112E70_F40B0_RollOutTheBarrels[4];
extern RBBarrel* D_80112EB0_F40F0_RollOutTheBarrels[4];
extern RBBarrel* D_80112EC0_F4100_RollOutTheBarrels[4];

/* S4-02B. */
extern f32 D_801120E8_F3328_RollOutTheBarrels[3];
extern f32 D_801120F4_F3334_RollOutTheBarrels[3];
extern Vec D_80112280_F34C0_RollOutTheBarrels[3];
extern Vec D_801122A4_F34E4_RollOutTheBarrels;
extern Vec D_801122B0_F34F0_RollOutTheBarrels[3];
extern f32 D_801122D4_F3514_RollOutTheBarrels[3];
extern Gfx D_801123D0_F3610_RollOutTheBarrels[]; /* a sprite model's setup list */
extern f32 D_80112410_F3650_RollOutTheBarrels[4][2];
extern f32 D_80112430_F3670_RollOutTheBarrels;
extern omObjData* D_80112D48_F3F88_RollOutTheBarrels;
extern RBMeshVtx* D_80112DA8_F3FE8_RollOutTheBarrels;
extern s16 D_80112DB4_F3FF4_RollOutTheBarrels[2]; /* the mesh's columns and rows */

void func_80102800_E3A40_RollOutTheBarrels(void);
void func_80102B2C_E3D6C_RollOutTheBarrels(omObjData* obj);
void func_80102BB0_E3DF0_RollOutTheBarrels(omObjData* obj);
void func_80102FB8_E41F8_RollOutTheBarrels(omObjData* obj);
void func_80102FEC_E422C_RollOutTheBarrels(omObjData* obj);
void func_80103094_E42D4_RollOutTheBarrels(void);
void func_801031B4_E43F4_RollOutTheBarrels(void);
void func_801039F0_E4C30_RollOutTheBarrels(omObjData* obj);
void func_80103DF4_E5034_RollOutTheBarrels(s32 idx);
void func_80103FE0_E5220_RollOutTheBarrels(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames);
void func_801041D0_E5410_RollOutTheBarrels(void);
void func_80104270_E54B0_RollOutTheBarrels(omObjData* obj);
void func_80104958_E5B98_RollOutTheBarrels(omObjData* obj);
void func_80104C80_E5EC0_RollOutTheBarrels(omObjData* obj);
void func_80104D88_E5FC8_RollOutTheBarrels(omObjData* obj);
s32 func_8010541C_E665C_RollOutTheBarrels(omObjData* obj);
void func_801056BC_E68FC_RollOutTheBarrels(omObjData* obj);
void func_80105928_E6B68_RollOutTheBarrels(omObjData* obj, f32 angle, f32 dist);
void func_80105998_E6BD8_RollOutTheBarrels(omObjData* obj, s16 mot, s16 now);
void func_80105A70_E6CB0_RollOutTheBarrels(void);
void func_80105AD8_E6D18_RollOutTheBarrels(omObjData* obj);
void func_80105CE8_E6F28_RollOutTheBarrels(omObjData* obj);
f32 func_80105F80_E71C0_RollOutTheBarrels(f32 x, f32 z);
void func_801060B8_E72F8_RollOutTheBarrels(void);
RBShape* func_80106114_E7354_RollOutTheBarrels(omObjData* parent, Vec* pos, void (*hook)());
void func_801061B0_E73F0_RollOutTheBarrels(RBShape* shape, Vec* offset, f32* size);
RBShape* func_80106224_E7464_RollOutTheBarrels(omObjData* obj, Vec* prev);
RBShape* func_801063B0_E75F0_RollOutTheBarrels(omObjData* obj, Vec* prev);
void func_801066B4_E78F4_RollOutTheBarrels(RBShape* shape, omObjData* obj, Vec* prev);
void func_801067BC_E79FC_RollOutTheBarrels(RBShape* shape, omObjData* obj, Vec* prev);
void func_80106DE4_E8024_RollOutTheBarrels(void);
void func_8010704C_E828C_RollOutTheBarrels(omObjData* obj);
void func_80107140_E8380_RollOutTheBarrels(RBRoller* r);
void func_80107564_E87A4_RollOutTheBarrels(RBRoller* r);
void func_801079D0_E8C10_RollOutTheBarrels(RBRoller* r);
void func_80107AE0_E8D20_RollOutTheBarrels(RBRoller* r);
void func_80107D2C_E8F6C_RollOutTheBarrels(RBRoller* r);
s32 func_80108808_E9A48_RollOutTheBarrels(s16 arg0);
void func_8010898C_E9BCC_RollOutTheBarrels(s32 idx, f32 x, f32 y, f32 z);
void func_80108A08_E9C48_RollOutTheBarrels(s32 arg0);
void func_80108A78_E9CB8_RollOutTheBarrels(s32 arg0);
void func_80108AEC_E9D2C_RollOutTheBarrels(u16 idx, s32 a, s32 b);
void func_80108B68_E9DA8_RollOutTheBarrels(s32 arg0, s32 arg1);
s32 func_80108C00_E9E40_RollOutTheBarrels(s32 arg0);
void func_80108C5C_E9E9C_RollOutTheBarrels(s32 idx, s32 shadow);
void func_80108D00_E9F40_RollOutTheBarrels(void);
void func_80108F88_EA1C8_RollOutTheBarrels(omObjData* obj);
void func_80109504_EA744_RollOutTheBarrels(RBBarrel* b);
void func_801096D8_EA918_RollOutTheBarrels(s16 arg0, Vec* out);
s32 func_80109738_EA978_RollOutTheBarrels(s16 arg0);
s32 func_80109824_EAA64_RollOutTheBarrels(s16 arg0);
void func_80109868_EAAA8_RollOutTheBarrels(omObjData* obj);
void func_80109DA4_EAFE4_RollOutTheBarrels(omObjData* obj);
void func_8010A2E0_EB520_RollOutTheBarrels(omObjData* obj);
void func_8010A7C4_EBA04_RollOutTheBarrels(omObjData* obj);
void func_8010ACA8_EBEE8_RollOutTheBarrels(omObjData* obj);
void func_8010B5B0_EC7F0_RollOutTheBarrels(omObjData* obj);
void func_8010BEB8_ED0F8_RollOutTheBarrels(omObjData* obj);
void func_8010C448_ED688_RollOutTheBarrels(omObjData* obj);
void func_8010C9D8_EDC18_RollOutTheBarrels(omObjData* obj);
void func_8010CA90_EDCD0_RollOutTheBarrels(omObjData* obj);
void func_8010CB58_EDD98_RollOutTheBarrels(omObjData* obj);
void func_8010CC18_EDE58_RollOutTheBarrels(omObjData* obj);
void func_8010CC94_EDED4_RollOutTheBarrels(omObjData* obj);
void func_8010CE40_EE080_RollOutTheBarrels(omObjData* obj);
void func_8010D054_EE294_RollOutTheBarrels(omObjData* obj);
void func_8010D204_EE444_RollOutTheBarrels(omObjData* obj);
void func_8010D3D0_EE610_RollOutTheBarrels(omObjData* obj);
void func_8010D604_EE844_RollOutTheBarrels(omObjData* obj);
void func_8010D740_EE980_RollOutTheBarrels(omObjData* obj);
s32 func_8010DB74_EEDB4_RollOutTheBarrels(void* arg0);
void func_8010DBAC_EEDEC_RollOutTheBarrels(RBStep step);
s32 func_8010DBE0_EEE20_RollOutTheBarrels(s32 arg0);
f32 func_8010DC1C_EEE5C_RollOutTheBarrels(void);
f32 func_8010DC48_EEE88_RollOutTheBarrels(void);
s32 func_8010DC78_EEEB8_RollOutTheBarrels(void);
u16 func_8010DCCC_EEF0C_RollOutTheBarrels(s32 file);
void func_8010DD10_EEF50_RollOutTheBarrels(void);
void func_8010DE84_EF0C4_RollOutTheBarrels(omObjData* obj);
s32 func_8010DF18_EF158_RollOutTheBarrels(s32 kind, f32 x, f32 y, f32 z);
void func_8010E080_EF2C0_RollOutTheBarrels(Vec* pos, s32 size);
void func_8010E260_EF4A0_RollOutTheBarrels(void);
void func_8010E390_EF5D0_RollOutTheBarrels(omObjData* obj);
void func_8010E434_EF674_RollOutTheBarrels(f32 arg0, f32 arg1, f32 arg2);
void func_8010E4C0_EF700_RollOutTheBarrels(s16 model);
void func_8010E944_EFB84_RollOutTheBarrels(s16 model, s32 angle);
s32 func_8010EBE8_EFE28_RollOutTheBarrels(RBAnim* spr, f32 alpha);
s32 func_8010F81C_F0A5C_RollOutTheBarrels(RBAnim* spr, u16 src, f32 alpha);
void func_8010FA9C_F0CDC_RollOutTheBarrels(u16 mdl, RBAnim* spr, u16 frame, f32 alpha);
s32 func_8010FC44_F0E84_RollOutTheBarrels(RBAnim* spr, HmfData* hmf, f32 scale, u16 x, u16 y);
s32 func_8011005C_F129C_RollOutTheBarrels(s32 model);
void func_80110530_F1770_RollOutTheBarrels(s32 a, s32 b, f32 u0, f32 v0, f32 u1, f32 v1, RBAnim* tex0, RBAnim* tex1);
void func_801113D4_F2614_RollOutTheBarrels(omObjData* obj, void* p);
void* func_801113F4_F2634_RollOutTheBarrels(omObjData* obj);
void* func_80111448_F2688_RollOutTheBarrels(s32 size);
s32 func_80111494_F26D4_RollOutTheBarrels(void);
void func_8011154C_F278C_RollOutTheBarrels(s16 arg0, s16 arg1);
void func_801115EC_F282C_RollOutTheBarrels(s16 model, Vec* offset);
f32 func_80111678_F28B8_RollOutTheBarrels(f32 from, f32 to, f32 step);
f32 func_80111838_F2A78_RollOutTheBarrels(f32 a, f32 b);
void func_801118C8_F2B08_RollOutTheBarrels(s32* list, u32 n, u32 times);
s32 func_801119B4_F2BF4_RollOutTheBarrels(u8* arg0, u32 arg1, u32 arg2);
void func_80111AA0_F2CE0_RollOutTheBarrels(s16* a, u16 n);
void func_80111B40_F2D80_RollOutTheBarrels(s32 cam, Vec* pos, Vec* screen);
f32 func_80111F28_F3168_RollOutTheBarrels(f32 y, f32 x);
f32 func_80111FA0_F31E0_RollOutTheBarrels(f32 t, f32 a, f32 b, f32 c);
void func_80112000_F3240_RollOutTheBarrels(f32 t, Vec* a, Vec* b, Vec* c, Vec* out);

#endif
