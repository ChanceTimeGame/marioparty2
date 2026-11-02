#ifndef _OVL_15_H
#define _OVL_15_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Lights Out, a 1 vs 3 game: the player of group 0 (D_8010CD86) swings a hammer in the dark while
   the three others, each with a light bulb above, try to hit him; lightning shows the arena now
   and then. Two retail files, 170190.c and 179A40.c (from 8010C0B0, 1-nop pad); .data at 0x179B90,
   .rodata from 0x17A410, all of it 170190.c's. */

typedef f32 Matrix4f[4][4];

/* One slot of D_8010CD90 (50 of them, stride 0x9C): every actor's state, indexed by obj->work[0].
   Slots 0-3 players, 6 the shock wave, 7 the darkness sprite, 9 the backdrop, 30-33 the bulbs.
   N64 offsets; the struct holds pointers, so it changes size on the host. */
typedef struct LOSlot {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 sprite;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ char unk_20[4];
    /* 0x24 */ s16 mtxCount[2];
    /* 0x28 */ Matrix4f* mtx[2];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ Matrix4f unk_34[1];
    /* 0x74 */ u16 unk_74;
    /* 0x76 */ u16 unk_76;
    /* 0x78 */ u16 unk_78;
    /* 0x7A */ u16 unk_7A;
    /* 0x7C */ u16 unk_7C;
    /* 0x7E */ u16 unk_7E;
    /* 0x80 */ u16 unk_80;
    /* 0x82 */ u16 unk_82;
    /* 0x84 */ s16 unk_84;
    /* 0x86 */ s16 unk_86;
    /* 0x88 */ u16 unk_88;
    /* 0x8A */ s16 unk_8A;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ s32 unk_94;
    /* 0x98 */ s32 unk_98;
} LOSlot; /* size = 0x9C */

typedef struct LOMtxSet { /* main's unk1EA70StructC */
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Matrix4f* mtx;
} LOMtxSet;

typedef struct LOCharData { /* D_800CD438, one per character */
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[0xC];
} LOCharData; /* size = 0x18 */

typedef struct LOStart { /* a player's start: position and heading */
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s16 rotY;
} LOStart;

/* main */
extern LOCharData D_800CD438_CE038[];
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7D0_C03D0;
extern HuCamera* D_800C9B80_CA780;
extern s32 D_800F8FD0_F9BD0;
extern u16 D_800F8FE0_F9BE0;
extern f32 D_800F94A8_FA0A8[];
extern s16 D_800FA606_FB206;
extern omObjData* D_800FC7B0_FD3B0[];
extern HmfModel* D_800FC834_FD434;
extern u16 D_800FC87A_FD47A;
extern u8 D_800FD8AC[];
extern s16 D_800FFFD6_100BD6;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_801011FC_101DFC;
extern Vec D_801013B0_101FB0[];
extern Vec D_80102770_103370[];
extern u16 ContBtn[4];
extern u16 ContBtnTrg[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_80007790_8390(omObjData* obj);
void func_8000BE8C_CA8C(omObjData* obj, f32 arg1);
void func_8000BE98_CA98(omObjData* obj, f32 arg1);
void func_8000BEA4_CAA4(omObjData* obj, f32 arg1);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 minX, f32 minZ, f32 maxX, f32 maxZ);
void func_8000C018_CC18(u16 arg0);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000C460_D060(void);
void func_8000C6FC_D2FC(omObjData* obj, u32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5);
s32 func_8000D900_E500(omObjData* obj, omObjData* item);
void func_8000E0C0_ECC0(MgWork* work, s32 slot, void* hook);
void func_80018E30_19A30(s32);
void func_80018F58_19B58(s32);
s32 func_80019000_19C00(omObjData* obj);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion);
void func_80019E84_1AA84(omObjData* obj, u16 idx, s32 file, s32 flags, u16 speed);
void func_80019F0C_1AB0C(omObjData* arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
LOMtxSet* func_800232FC_23EFC(s16 arg0, s16 arg1, char* arg2);
void func_80023D74_24974(LOMtxSet* arg0);
void func_80025770_26370(Matrix4f, f32, f32, f32);
void func_80025830_26430(Matrix4f, f32, f32, f32);
void func_80025884_26484(Matrix4f, f32, f32, f32);
s16 func_80025F00_26B00(Matrix4f a, Matrix4f b);
void* func_80027154_27D54(s32 size, s32 tag);
s32 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2); /* main returns s16; retail does not extend it */
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16 arg0);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029EDC_2AADC(s16, s16);
void func_8002C524_2D124(s16, s16, s16);
void func_8002C570_2D170(s16 arg0);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_80030CD4_318D4(Matrix4f, Matrix4f);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16 arg0);
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80079128_79D28(void);
void func_800794A8_7A0A8(s32);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 arg0, s16 arg1);
s16 func_800797DC_7A3DC(s32, s16);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16, s16, s32);
void func_80082488_83088(s16, s16, u16);
s32 func_8008F618_90218(void);
void func_800B0EF0_B1AF0(void*, s32, s32);
f32 func_800B1830_B2430(f32);
void func_800B1F50_B2B50(Matrix4f, f32, f32, f32);
void func_800B1FA0_B2BA0(Mtx*, f32, f32, f32);
f32 func_800B75A8_B81A8(f32, f32);
f32 func_800B7890_B8490(f32);
f32 __sinf(f32);
f32 __cosf(f32);
f32 HuMathSin(f32);
void HmfModelObjAttrSet(s16, s32, s32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
HuSprite_Unk84_Struct* SprAnimGet(s16 animIdx);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 group, s16 member, s32 attr);
void SprAttrSet(s16 group, s16 member, s32 attr);
void SprBankSet(s16 group, s16 member, s32 arg2);
s16 SprCreate(u16 arg0, u16 arg1);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 group, s16 member, u16 prio);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);

/* .data */
extern u8 D_8010C200_179B90_LightsOut[];      /* lightning script: { frames, lit } pairs, 0xFF ends */
extern u8 D_8010C201_179B91_LightsOut[];      /* its second bytes */
extern u8 D_8010C218_179BA8_LightsOut[];      /* per character: { hit, swing } delays, hammer ... */
extern u8 D_8010C219_179BA9_LightsOut[];
extern LOStart D_8010C230_179BC0_LightsOut[4]; /* start places */
extern s32 D_8010C250_179BE0_LightsOut[6];    /* voice base per character */
extern u16 D_8010C268_179BF8_LightsOut[4];
extern u8 D_8010C270_179C00_LightsOut;        /* the hammer is held */
extern s32 D_8010C274_179C04_LightsOut;       /* the 1P course's early end */
extern u8 D_8010C278_179C08_LightsOut[];      /* 32x64 light mask, 0xFF = dark */

/* .rodata */
extern const char D_8010CAF8_17A488_LightsOut[16];
extern const char D_8010CB90_17A520_LightsOut[];

/* .bss */
extern s32 D_8010CC20_17A5B0_LightsOut[3][4]; /* each texture's light x last drawn, per player */
extern s32 D_8010CC50_17A5E0_LightsOut[3][4]; /* and y */
extern s32 D_8010CC80_17A610_LightsOut;       /* texture being drawn */
extern s16 D_8010CC84_17A614_LightsOut;       /* players knocked out */
extern s16 D_8010CC86_17A616_LightsOut;       /* CPU turn rate */
extern u16 D_8010CC88_17A618_LightsOut;       /* lightning alpha */
extern s16 D_8010CC8A_17A61A_LightsOut;       /* lightning step timer */
extern s16 D_8010CC8C_17A61C_LightsOut;       /* lightning step */
extern s16 D_8010CC8E_17A61E_LightsOut;       /* textures cleared */
extern s16 D_8010CC90_17A620_LightsOut[4];    /* the bulb is hung */
extern s16 D_8010CC98_17A628_LightsOut;       /* the hammer's blast frame */
extern s16 D_8010CC9A_17A62A_LightsOut;       /* CPU swing timer */
extern s16 D_8010CC9C_17A62C_LightsOut[4];
extern s16 D_8010CCA4_17A634_LightsOut[4];
extern s16 D_8010CCAC_17A63C_LightsOut[4];
extern u8 D_8010CCB4_17A644_LightsOut;        /* a swing hit */
extern u8 D_8010CCB5_17A645_LightsOut[4];     /* out of the shockwave check */
extern u8 D_8010CCB9_17A649_LightsOut[4][2];  /* each player's random win / lose voice */
extern HuSprite_Unk84_Struct* D_8010CCC4_17A654_LightsOut;
extern u8* D_8010CCC8_17A658_LightsOut[3];    /* darkness textures, 160x240 I8 */
extern f32 D_8010CCD8_17A668_LightsOut[4];    /* player screen y */
extern f32 D_8010CCE8_17A678_LightsOut[4];    /* player screen x */
extern s16 D_8010CCF8_17A688_LightsOut[4];    /* player's light: 0 draw, 1 hidden, -1 out */
extern u8 D_8010CD00_17A690_LightsOut[4];     /* start places taken */
extern s32 D_8010CD04_17A694_LightsOut;       /* lightning shows */
extern s16 D_8010CD08_17A698_LightsOut;       /* state timer */
extern s32 D_8010CD10_17A6A0_LightsOut;
extern s16 D_8010CD18_17A6A8_LightsOut[50];   /* graphic ids */
extern u16 D_8010CD84_17A714_LightsOut;       /* game state: 0 intro, 1 start, 2 play, 3 over, 4 result, 5 leave */
extern u8 D_8010CD86_17A716_LightsOut;        /* the hammer player */
extern LOSlot D_8010CD90_17A720_LightsOut[50];
/* retail reads these fields of D_8010CD90 by their own labels */
extern omObjData* D_8010D138_17AAC8_LightsOut;  /* [6].obj */
extern f32 D_8010D140_17AAD0_LightsOut;         /* [6].unk_08 */
extern f32 D_8010D144_17AAD4_LightsOut;         /* [6].unk_0C */
extern f32 D_8010D148_17AAD8_LightsOut;         /* [6].unk_10 */
extern Matrix4f D_8010D16C_17AAFC_LightsOut;    /* [6].unk_34 */
extern omObjData* D_8010D1D4_17AB64_LightsOut;  /* [7].obj */
extern s16 D_8010D1D8_17AB68_LightsOut;         /* [7].sprite */
extern f32 D_8010D1DC_17AB6C_LightsOut;         /* [7].unk_08 */
extern f32 D_8010D1E0_17AB70_LightsOut;         /* [7].unk_0C */
extern omObjData* D_8010D30C_17AC9C_LightsOut;  /* [9].obj */
extern s16 D_8010D310_17ACA0_LightsOut;         /* [9].sprite */
extern omObjData* D_8010D9C0_17B350_LightsOut;  /* [20].obj */
extern s16 D_8010CD26_17A6B6_LightsOut;         /* D_8010CD18[7] */
extern u16 D_8010D1B4_17AB44_LightsOut;         /* [6].unk_7C */
extern u8 D_8010EC08_17C598_LightsOut;
extern s32 D_8010EC0C_17C59C_LightsOut;

void func_80102800_170190_LightsOut(void);
void func_8010281C_1701AC_LightsOut(Gfx** gfxp);
void func_80102B50_1704E0_LightsOut(void);
void func_80102B58_1704E8_LightsOut(omObjData* obj);
void func_80102BDC_17056C_LightsOut(void);
void func_80102C18_1705A8_LightsOut(void);
void func_80102CC4_170654_LightsOut(void);
void func_80102CF0_170680_LightsOut(omObjData* obj);
void func_80102EB8_170848_LightsOut(void);
void func_80102F00_170890_LightsOut(Matrix4f m, f32 x, f32 y, f32 z, f32* out);
s32 func_80102F9C_17092C_LightsOut(f32 x, f32 y, f32 z, f32 reach);
void func_80103114_170AA4_LightsOut(void);
void func_8010335C_170CEC_LightsOut(Gfx** gfxp);
void func_80103670_171000_LightsOut(void);
void func_80103620_170FB0_LightsOut(omObjData* obj);
void func_80103648_170FD8_LightsOut(omObjData* obj);
f32 func_80103678_171008_LightsOut(f32 x);
void func_801037C8_171158_LightsOut(omObjData* obj);
void func_80103968_1712F8_LightsOut(Vec* from, Vec* to, Vec* out);
void func_80103CA8_171638_LightsOut(omObjData* obj, s16 motion, char* name);
f32 func_80103DFC_17178C_LightsOut(f32 y, f32 x);
void func_80103E74_171804_LightsOut(LOSlot* slot);
void func_80104228_171BB8_LightsOut(LOSlot* slot);
void func_801045DC_171F6C_LightsOut(LOSlot* slot);
void func_80104990_172320_LightsOut(LOSlot* slot);
void func_80104D48_1726D8_LightsOut(LOSlot* slot);
void func_80104EEC_17287C_LightsOut(omObjData* obj);
void func_801050E8_172A78_LightsOut(omObjData* obj);
void func_80105340_172CD0_LightsOut(omObjData* obj);
void func_80105438_172DC8_LightsOut(omObjData* obj);
s32 func_80105AF8_173488_LightsOut(void);
s32 func_80105B00_173490_LightsOut(omObjData* obj);
s32 func_80105B78_173508_LightsOut(omObjData* obj);
s32 func_80105BF0_173580_LightsOut(omObjData* obj);
void func_80105C14_1735A4_LightsOut(omObjData* obj);
void func_801062A8_173C38_LightsOut(void);
void func_801063E8_173D78_LightsOut(LOSlot* slot);
void func_80106BCC_17455C_LightsOut(LOSlot* slot);
void func_801073B0_174D40_LightsOut(LOSlot* slot);
void func_80107BB4_175544_LightsOut(LOSlot* slot);
void func_801083A4_175D34_LightsOut(LOSlot* slot);
void func_80108530_175EC0_LightsOut(omObjData* obj);
void func_8010875C_1760EC_LightsOut(omObjData* obj);
void func_801094B8_176E48_LightsOut(omObjData* obj);
void func_801099F0_177380_LightsOut(void);
void func_80109B28_1774B8_LightsOut(omObjData* obj, Matrix4f m);
void func_80109C30_1775C0_LightsOut(omObjData* obj);
void func_80109F58_1778E8_LightsOut(omObjData* obj);
void func_8010A090_177A20_LightsOut(void);
void func_8010A0CC_177A5C_LightsOut(omObjData* obj);
void func_8010A4C0_177E50_LightsOut(omObjData* obj);
void func_8010A5D0_177F60_LightsOut(void);
void func_8010A680_178010_LightsOut(void);
void func_8010A6C4_178054_LightsOut(omObjData* obj);
void func_8010A980_178310_LightsOut(void);
void func_8010AAAC_17843C_LightsOut(omObjData* obj);
void func_8010ACD0_178660_LightsOut(omObjData* obj);
void func_8010AD1C_1786AC_LightsOut(omObjData* obj);
void func_8010ADA4_178734_LightsOut(void);
void func_8010ADC8_178758_LightsOut(omObjData* obj);
void func_8010AE00_178790_LightsOut(omObjData* obj);
void func_8010AE58_1787E8_LightsOut(void);
void func_8010B04C_1789DC_LightsOut(omObjData* obj);
void func_8010B0CC_178A5C_LightsOut(omObjData* obj);
void func_8010B1C8_178B58_LightsOut(void);
void func_8010B3B8_178D48_LightsOut(s16 cam, f32 x, f32 y, f32 z, f32* out);
void func_8010B648_178FD8_LightsOut(void);
void func_8010BDE8_179778_LightsOut(void);
void func_8010BEA4_179834_LightsOut(omObjData* obj);
void func_8010C070_179A00_LightsOut(void);
void func_8010C0B0_179A40_LightsOut(void);
void func_8010C1C8_179B58_LightsOut(void);

/* Zero one player's pad; the host's stick and button state are the CPU's output. */
#define LO_PAD_CLEAR(o)                                  \
    do {                                                 \
        ContBtn[gPlayers[(o)->work[0]].port] = 0;        \
        ContBtnTrg[gPlayers[(o)->work[0]].port] = 0;     \
        ContStkX[gPlayers[(o)->work[0]].port] = 0;       \
        ContStkY[gPlayers[(o)->work[0]].port] = 0;       \
    } while (0)

/* Keep a player inside the arena (radius 460). */
#define LO_KEEP_IN(o)                                                   \
    do {                                                                \
        f32 _x = (o)->trans.x;                                          \
        f32 _z;                                                         \
        if (_x * _x + (_z = (o)->trans.z, _z * _z) > 211600.0) {        \
            f32 _a = func_80103DFC_17178C_LightsOut(_x, _z);            \
            (o)->trans.x = HuMathSin(_a) * 460.0;                       \
            (o)->trans.z = func_800B7890_B8490(_a) * 460.0;             \
        }                                                               \
    } while (0)

/* inline abs of a float truncated to int */
#define LO_ABS(v) ({ s32 _a = (s32)(v); if (_a < 0) { _a = -_a; } _a; })
#define LO_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

#endif /* _OVL_15_H */
