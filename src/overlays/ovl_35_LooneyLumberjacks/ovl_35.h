#ifndef _OVL_35_H
#define _OVL_35_H

/* Overlay 35: Looney Lumberjacks. Two teams of two saw through a tree each: the partners press
   opposite ways on the stick (A: D_8010A680_26F630_LooneyLumberjacks) in turn to drag the saw across, each stroke chips the
   tree's strength by the stroke's length; the first tree to fall wins. D_8010AF98_26FF48_LooneyLumberjacks is the flow
   state, D_8010AF9A_26FF4A_LooneyLumberjacks the 61 second timer. One retail file, 2677B0.c; .data up to 0x26FA10,
   .rodata carved from there. N64 offsets are in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

typedef f32 Matrix4f[4][4];

#define LL_WRAP(v)                 \
    if ((v) >= 360.0) {            \
        (v) -= 360.0;              \
    } else if ((v) < 0.0) {        \
        (v) += 360.0;              \
    }

/* Pointers and colours retail packs byte by byte: a 4-byte value built in a register. */
typedef struct LLBytes {
    u32 a : 8;
    u32 b : 8;
    u32 c : 8;
    u32 d : 8;
} LLBytes;

typedef union LLPack {
    void* p;
    LLBytes b;
} LLPack;

typedef struct LLColor {
    u32 r : 8;
    u32 g : 8;
    u32 b : 8;
    u32 a : 8;
} LLColor;

typedef struct LLRgb {
    u8 r;
    u8 g;
    u8 b;
} LLRgb;

/* A tree (D_8010AF40_26FEF0_LooneyLumberjacks, two). */
typedef struct LLTree {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 team;
    /* 0x06 */ s16 used;
    /* 0x08 */ s16 stage; /* how far the cut has gone, 0-6 */
    /* 0x0A */ s16 fall; /* frames since the tree came down */
    /* 0x0C */ f32 angle; /* of the falling top */
    /* 0x10 */ f32 speed;
    /* 0x14 */ f32 hp;
    /* 0x18 */ f32 maxHp;
} LLTree; /* size = 0x1C */

/* A team (D_8010AF3C_26FEEC_LooneyLumberjacks, two). */
typedef struct LLTeam {
    /* 0x00 */ omObjData* obj[2];
    /* 0x08 */ s16 team;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 player[2];
    /* 0x10 */ s16 chr[2];
    /* 0x14 */ s16 port[2];
    /* 0x18 */ s16 spr;
    /* 0x1A */ s16 frame;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 dir; /* the side the saw heads for */
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 stroke; /* length of this stroke */
    /* 0x24 */ s16 phase; /* stage while sawing, -1 to -4 afterwards */
    /* 0x28 */ f32 cut; /* 0-1 */
    /* 0x2C */ f32 pos; /* saw position, in motion frames */
    /* 0x30 */ f32 vel;
    /* 0x34 */ s16 lastDir;
    /* 0x38 */ f32 lastVel;
    /* 0x3C */ s16 comMask; /* bit per CPU partner */
    /* 0x3E */ s16 comDir;
    /* 0x40 */ s16 wrong[2];
    /* 0x44 */ s16 level;
    /* 0x46 */ s16 comSide;
    /* 0x48 */ s16 comA;
    /* 0x4A */ s16 comB;
    /* 0x4C */ s16 comC;
    /* 0x50 */ LLTree* tree;
} LLTeam; /* size = 0x54 */

/* The motion blend buffers of a player (func_80108C40_26DBF0_LooneyLumberjacks). */
typedef struct LLBlendBuf {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ void* unk_08; /* a matrix per motion object */
} LLBlendBuf; /* size = 0xC */

/* A player (D_8010AF38_26FEE8_LooneyLumberjacks, four). */
typedef struct LLPlayer {
    /* 0x00 */ s16 player;
    /* 0x02 */ s16 idx;
    /* 0x04 */ s16 team;
    /* 0x06 */ s16 chr;
    /* 0x08 */ s16 state;
    /* 0x0C */ LLBlendBuf* blend;
    /* 0x10 */ f32 frame;
    /* 0x14 */ s16 motA;
    /* 0x16 */ s16 motB;
    /* 0x18 */ f32 weight;
    /* 0x1C */ Vec head;
    /* 0x28 */ f32 headBack;
    /* 0x2C */ HmfMotionObj* hat;
} LLPlayer; /* size = 0x30 */

/* A 3D sprite effect (D_8010AF44_26FEF4_LooneyLumberjacks, eight). */
typedef struct LLFx {
    /* 0x00 */ s32 spr; /* retail reads the low half */
    /* 0x04 */ s32 used;
    /* 0x08 */ s32 time;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec vel;
} LLFx; /* size = 0x24 */

/* func_801053C8_26A378_LooneyLumberjacks's locals. */
typedef struct LLInput {
    /* 0x00 */ HmfModel* m[2];
    /* 0x08 */ s16 in[2];
} LLInput;

/* A camera position (D_8010AFC0_26FF70_LooneyLumberjacks: [0] the target, [1] the start of a blend). */
typedef struct LLCamera {
    /* 0x00 */ Vec center;
    /* 0x0C */ Vec rot;
    /* 0x18 */ f32 zoom;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} LLCamera; /* size = 0x24 */

/* A viewport (D_8010B018_26FFC8_LooneyLumberjacks: [0] the start of a blend, [1] the target). */
typedef struct LLView {
    /* 0x00 */ Vec scale;
    /* 0x0C */ Vec trans;
} LLView; /* size = 0x18 */

typedef struct LLEndView {
    /* 0x00 */ Vec trans;
    /* 0x0C */ f32 scale;
} LLEndView; /* size = 0x10 */

typedef struct LLPose {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
} LLPose; /* size = 0x18 */

typedef struct LLPoint {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} LLPoint;

typedef struct LLWear {
    /* 0x00 */ f32 limit;
    /* 0x04 */ f32 damage;
} LLWear;

typedef struct LLVoice {
    /* 0x00 */ u32 win;
    /* 0x04 */ u32 lose;
    /* 0x08 */ s32 unk_08[2];
} LLVoice; /* size = 0x10 */

typedef struct LLCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;
    /* 0x08 */ s32 model;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} LLCharData; /* size = 0x18 */

/* Main. */
extern LLCharData D_800CD438_CE038[];
extern u8 D_800FDBCA_FE7CA;
extern u8 D_800FDBE0_FE7E0;
extern s16 D_800FA1AA_FADAA;
extern u16 D_800FA606_FB206;
extern s32 D_800F8FD0_F9BD0;
extern u16 D_801011FC_101DFC;
extern u16 D_800FC87A_FD47A;
extern omObjData* D_800FFFD8_100BD8[];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s32 fontcolor;
extern char pfStrBuf[];
extern Vec D_800C98C4_CA4C4;
extern Vec D_800C990C_CA50C;
extern Matrix4f* D_800FD43C_FE03C;
extern s16* D_800FC8F0_FD4F0;
extern s16 D_800F93D0_F9FD0;
extern Matrix4f D_801016D0_1022D0[];
extern s16 D_800FD470_FE070;

s16 DrawDebugText(u16, u16, char*);
void* HuMemAlloc(s32 size);
void HuMemFree(void*);
s32 PlaySound(s32);
void* SprAnimGet(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPosPerspectiveSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
f64 fabs(f64);
f32 fabsf(f32);
void* memcpy(void*, const void*, u32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
u16 func_80018A30_19630(s32 file, s32 attr);
void func_80019378_19F78(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80020D20_21920(s16 arg0);
void func_80023680_24280(HmfData* arg0, s16 arg1, s16 arg2);
void func_80023A08_24608(s16 arg0, s16* arg1, s16 arg2);
void func_80025770_26370(f32* m, f32 x, f32 y, f32 z);
void func_80025884_26484(f32* m, f32 x, f32 y, f32 z);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
s32 func_80027FA4_28BA4(u32 file, void* gfx, u8 arg2);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
HmfMotionObj* func_8002A9F4_2B5F4(s16 arg0, char* arg1);
void func_8002D4D0_2E0D0(s16 n);
void func_80039B54_3A754(HmfData*, f32, HmfMotionSlot*, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_8008221C_82E1C(s16 group, s16 member, f32 alpha);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800824B4_830B4(s16 grpIdx, s32 idx, u8 r, u8 g, u8 b, u16 a);
f64 func_800B0D98_B1998(f64 x, f64 y);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_800B37C0_B43C0(f32* mtx);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* .data, typed from the code. */
extern LLPose D_8010A610_26F5C0_LooneyLumberjacks[4]; /* where each player stands */
extern LLPoint D_8010A670_26F620_LooneyLumberjacks[2][2]; /* button sprites */
extern u16 D_8010A680_26F630_LooneyLumberjacks[2][2]; /* the buttons to push the saw right / left */
extern f32 D_8010A688_26F638_LooneyLumberjacks[2]; /* -1, 1 */
extern f32 D_8010A690_26F640_LooneyLumberjacks[7]; /* the tree's stages */
extern s16 D_8010A6AC_26F65C_LooneyLumberjacks[4][3]; /* CPU timing, per difficulty; rand & 3 can read one past a row */
extern s16 D_8010A6C4_26F674_LooneyLumberjacks[4][3];
extern s16 D_8010A6DC_26F68C_LooneyLumberjacks[4][3];
extern LLEndView D_8010A6F4_26F6A4_LooneyLumberjacks[2]; /* the viewport the winner's side gets */
extern s32 D_8010A714_26F6C4_LooneyLumberjacks; /* exit countdown; read as s16 */
extern s32 D_8010A718_26F6C8_LooneyLumberjacks; /* camera test mode */
extern s32 D_8010A71C_26F6CC_LooneyLumberjacks;
extern s32 D_8010A720_26F6D0_LooneyLumberjacks;
extern s32 D_8010A724_26F6D4_LooneyLumberjacks; /* view test mode */
extern s16 D_8010A728_26F6D8_LooneyLumberjacks; /* backdrop delay */
extern s16 D_8010A72A_26F6DA_LooneyLumberjacks;
extern s16 D_8010A72C_26F6DC_LooneyLumberjacks[4][4]; /* the orders of a shuffled pairing */
extern s16 D_8010A74C_26F6FC_LooneyLumberjacks[2];
extern s16 D_8010A750_26F700_LooneyLumberjacks[2];
extern f32 D_8010A754_26F704_LooneyLumberjacks[2];
extern Vec D_8010A75C_26F70C_LooneyLumberjacks[2]; /* tree positions */
extern Vec D_8010A774_26F724_LooneyLumberjacks[2]; /* and angles */
extern s32 D_8010A78C_26F73C_LooneyLumberjacks[2]; /* saw models */
extern s16 D_8010A794_26F744_LooneyLumberjacks[4][2]; /* button banks */
extern s16 D_8010A7A4_26F754_LooneyLumberjacks[2];
extern s16 D_8010A7A8_26F758_LooneyLumberjacks[2]; /* sound pan per team */
extern s16 D_8010A7AA_26F75A_LooneyLumberjacks[]; /* D_8010A7AC_26F75C_LooneyLumberjacks[-1] */
extern s16 D_8010A7AC_26F75C_LooneyLumberjacks[5]; /* motion slot per quarter of the cut */
extern char* D_8010A7B8_26F768_LooneyLumberjacks[6]; /* per character: the head part */
extern f32 D_8010A7D0_26F780_LooneyLumberjacks[6];
extern s32 D_8010A7E8_26F798_LooneyLumberjacks[2];
extern s32 D_8010A7F0_26F7A0_LooneyLumberjacks[2];
extern s32 D_8010A7F8_26F7A8_LooneyLumberjacks[7]; /* tree part models */
extern LLWear D_8010A814_26F7C4_LooneyLumberjacks[5]; /* strength lost by stroke length */
extern Vec D_8010A83C_26F7EC_LooneyLumberjacks[2][3]; /* offsets of a burst of dust */
extern Vec D_8010A884_26F834_LooneyLumberjacks[3]; /* speeds of the same */
extern f32 D_8010A8A8_26F858_LooneyLumberjacks[3]; /* sizes */
extern LLRgb D_8010A8B4_26F864_LooneyLumberjacks[3]; /* wood chip colours */
extern Vec D_8010A8C0_26F870_LooneyLumberjacks[2][3]; /* wood chip positions per team */
extern Vec D_8010A908_26F8B8_LooneyLumberjacks[2];
extern Vec D_8010A920_26F8D0_LooneyLumberjacks;
extern Gfx D_8010AA20_26F9D0_LooneyLumberjacks[]; /* a sprite model's setup list */

/* .bss. */
extern omObjData* D_8010AF30_26FEE0_LooneyLumberjacks;
extern omObjData* D_8010AF34_26FEE4_LooneyLumberjacks; /* the sprite models */
extern LLPlayer* D_8010AF38_26FEE8_LooneyLumberjacks;
extern LLTeam* D_8010AF3C_26FEEC_LooneyLumberjacks;
extern LLTree* D_8010AF40_26FEF0_LooneyLumberjacks;
extern LLFx* D_8010AF44_26FEF4_LooneyLumberjacks;
extern LLColor* D_8010AF48_26FEF8_LooneyLumberjacks; /* per sprite model */
extern s16* D_8010AF4C_26FEFC_LooneyLumberjacks; /* sprite anims */
extern s16* D_8010AF50_26FF00_LooneyLumberjacks; /* per player, the motion to play */
extern LLVoice D_8010AF58_26FF08_LooneyLumberjacks[4];
extern s16 D_8010AF98_26FF48_LooneyLumberjacks; /* flow state */
extern s16 D_8010AF9A_26FF4A_LooneyLumberjacks; /* flow timer */
extern s16 D_8010AF9C_26FF4C_LooneyLumberjacks;
extern s16 D_8010AF9E_26FF4E_LooneyLumberjacks; /* winner: 1 or 2 by team bit, 3 both */
extern f32 D_8010AFA0_26FF50_LooneyLumberjacks; /* the saw motion's length */
extern f32 D_8010AFA4_26FF54_LooneyLumberjacks;
extern u8 D_8010AFA8_26FF58_LooneyLumberjacks[4];
extern s16 D_8010AFAC_26FF5C_LooneyLumberjacks; /* practice (no result) */
extern s16 D_8010AFAE_26FF5E_LooneyLumberjacks;
extern s32 D_8010AFB0_26FF60_LooneyLumberjacks;
extern s32 D_8010AFB4_26FF64_LooneyLumberjacks;
extern s32 D_8010AFB8_26FF68_LooneyLumberjacks;
extern s32 D_8010AFBC_26FF6C_LooneyLumberjacks;
extern LLCamera D_8010AFC0_26FF70_LooneyLumberjacks[2];
extern s32 D_8010B008_26FFB8_LooneyLumberjacks;
extern s32 D_8010B00C_26FFBC_LooneyLumberjacks;
extern s32 D_8010B010_26FFC0_LooneyLumberjacks;
extern LLView D_8010B018_26FFC8_LooneyLumberjacks[2];
extern f32 D_8010B048_26FFF8_LooneyLumberjacks;
extern f32 D_8010B04C_26FFFC_LooneyLumberjacks;
extern s32 D_8010B050_270000_LooneyLumberjacks;
extern s32 D_8010B054_270004_LooneyLumberjacks;
extern s32 D_8010B058_270008_LooneyLumberjacks;

void func_80102800_2677B0_LooneyLumberjacks(void);
void func_80102A68_267A18_LooneyLumberjacks(omObjData* obj);
void func_80102AF4_267AA4_LooneyLumberjacks(omObjData* obj);
void func_80103054_268004_LooneyLumberjacks(omObjData* obj);
void func_80103078_268028_LooneyLumberjacks(omObjData* obj);
void func_80103120_2680D0_LooneyLumberjacks(void);
void func_8010324C_2681FC_LooneyLumberjacks(void);
void func_80103A88_268A38_LooneyLumberjacks(omObjData* obj);
void func_80103ED8_268E88_LooneyLumberjacks(s32 idx);
void func_801040C4_269074_LooneyLumberjacks(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames);
void func_801042B4_269264_LooneyLumberjacks(s32 cam);
void func_80104410_2693C0_LooneyLumberjacks(void);
void func_801044B8_269468_LooneyLumberjacks(void);
void func_801046F4_2696A4_LooneyLumberjacks(omObjData* obj);
void func_80104940_2698F0_LooneyLumberjacks(f32 scale, f32 x, f32 y, f32 z, s32 frames);
void func_801049C0_269970_LooneyLumberjacks(s32 idx);
void func_80104A40_2699F0_LooneyLumberjacks(void);
void func_80104B5C_269B0C_LooneyLumberjacks(omObjData* obj);
void func_80104C48_269BF8_LooneyLumberjacks(void);
void func_801053C8_26A378_LooneyLumberjacks(omObjData* obj);
void func_80105EB0_26AE60_LooneyLumberjacks(omObjData* obj);
void func_80106288_26B238_LooneyLumberjacks(omObjData* obj);
void func_80106C0C_26BBBC_LooneyLumberjacks(void);
void func_80106C30_26BBE0_LooneyLumberjacks(omObjData* obj);
void func_80106F9C_26BF4C_LooneyLumberjacks(omObjData* obj);
void func_801071A8_26C158_LooneyLumberjacks(omObjData* obj);
void func_8010730C_26C2BC_LooneyLumberjacks(void);
void func_801073C4_26C374_LooneyLumberjacks(omObjData* obj);
LLTree* func_801077F0_26C7A0_LooneyLumberjacks(Vec* pos, Vec* rot, f32 hp);
s32 func_80107ADC_26CA8C_LooneyLumberjacks(LLTree* tree, f32 stroke);
f32 func_80107C3C_26CBEC_LooneyLumberjacks(LLTree* tree);
void func_80107C8C_26CC3C_LooneyLumberjacks(void);
u16 func_80107D50_26CD00_LooneyLumberjacks(s32 file);
void func_80107CE4_26CC94_LooneyLumberjacks(omObjData* obj);
void func_80107D48_26CCF8_LooneyLumberjacks(void);
void func_80107D94_26CD44_LooneyLumberjacks(void);
void func_80107F24_26CED4_LooneyLumberjacks(omObjData* obj);
s32 func_80107FE8_26CF98_LooneyLumberjacks(s32 anim, Vec* pos, Vec* vel);
void func_8010815C_26D10C_LooneyLumberjacks(Vec* pos, s32 kind);
void func_801082E8_26D298_LooneyLumberjacks(void);
void func_80108418_26D3C8_LooneyLumberjacks(omObjData* obj);
s16 func_80108550_26D500_LooneyLumberjacks(Vec* pos, Vec* rot, Vec* scale);
void func_80108728_26D6D8_LooneyLumberjacks(omObjData* obj);
void func_801088FC_26D8AC_LooneyLumberjacks(f32* a, f32* b, f32* out, f32 t);
f32 func_80108944_26D8F4_LooneyLumberjacks(f32 target, f32 cur, f32 step);
f32 func_801089C0_26D970_LooneyLumberjacks(f32 target, f32 cur, f32 step);
void func_80108B80_26DB30_LooneyLumberjacks(omObjData* obj, void* p);
void* func_80108BA0_26DB50_LooneyLumberjacks(omObjData* obj);
void* func_80108BF4_26DBA4_LooneyLumberjacks(s32 size);
void func_80108C40_26DBF0_LooneyLumberjacks(omObjData* obj);
void func_80108D58_26DD08_LooneyLumberjacks(omObjData* obj);
void func_80108F50_26DF00_LooneyLumberjacks(omObjData* obj, s16 a, s16 b, f32 weight, f32 frame);
s32 func_80109164_26E114_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, f32 alpha);
s32 func_80109D94_26ED44_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, u16 src, f32 alpha);
void func_8010A014_26EFC4_LooneyLumberjacks(u16 mdl, HuSprite_Unk84_Struct* spr, u16 frame, f32 alpha);
void func_8010A1E4_26F194_LooneyLumberjacks(u8 r, u8 g, u8 b);
s32 func_8010A1FC_26F1AC_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, HmfData* hmf, f32 scale, u16 x, u16 y);

#endif
