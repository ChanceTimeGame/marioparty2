#ifndef _OVL_2D_H
#define _OVL_2D_H

/* Overlay 2D: Honeycomb Havoc (4P). A branch holds a row of fruit (and coins, honeycombs);
   players take turns from the bottom of the branch, a spinning dial (func_80104708) picking one
   or two items. A coin adds to coins_mg; a honeycomb sends the bees after the player, who is
   out. The last player left wins (coins_mg_bonus += 10). No MP1 or MP3 ancestor.
   Retail is two files: 2292D0.c (the game) and 22DD10.c (from 80107240, after a 1-nop pad;
   MP1's camera/controller tail). .data stays asm (0x22DE20); .rodata is carved
   ([0x22DFC0, .rodata, 2292D0]). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"

/* ---- main-segment API used by 2D ---- */

void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void func_80020D20_21920(s16 arg0);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32); /* MP1 func_8005DB44: the object group's list */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void espDispOff(u16);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
u16 func_80018A64_19664(s32 arg0, s32 arg1);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2); /* a sprite-model slot (D_800F86D8) from a file */
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_80021198_21D98(s16 index, u16 arg1);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_800283DC_28FDC(s16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
void func_80029C74_2A874(s16 arg0, f32 arg1);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
HmfMotionObj* func_8002A9F4_2B5F4(s16 arg0, char* arg1);
void func_8002C524_2D124(s16, s16, s16);
void func_8002C570_2D170(s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
f32 func_800B75A8_B81A8(f32, f32); /* atan2 */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f64 func_800B0D98_B1998(f64, f64); /* fmod */
f64 fabs(f64);
s16 func_800797DC_7A3DC(s32, s16); /* MP1 func_80060618: player voice */
s16 func_80079798_7A398(s16, s16);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800799A4_7A5A4(s16, s32);
void func_80079848_7A448(s16 arg0); /* stop a sound */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
void func_8006D4D0_6E0D0(s16); /* MP1 func_80079078: the seconds counter */
void func_8006D518_6E118(void); /* MP1 func_800790C0 */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_8007A2CC_7AECC(s32 prio, s16 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8007A7FC_7B3FC(void*);
void func_8007B818_7C418(Vec* eye, Vec* at, f32* zoom, Vec* rot, Vec* center);

extern u16 D_801011FC_101DFC;
extern s16 gNumOfControllers;
extern Vec D_8010270C_10330C;
extern f32 D_80102750_103350; /* D_8010274C_10334C.y by retail's own label */

/* 1AE60.c's esprite slot */
typedef struct HCEspSlot {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* sprite group */
    /* 0x06 */ char unk_06[0x1E];
} HCEspSlot; /* size = 0x24 */
extern HCEspSlot* D_800F93FC_F9FFC;

/* Per-character data, 0x18 bytes each. */
typedef struct HCCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} HCCharData;
extern HCCharData D_800CD438_CE038[];

/* ---- overlay types ---- */

/* A player's work (func_80102CDC, 0x24 bytes). */
typedef struct HCPlayer {
    /* 0x00 */ u16 state;
    /* 0x02 */ s16 slot;   /* turn order position, 0 = next to the branch */
    /* 0x04 */ u16 player;
    /* 0x06 */ u16 picked; /* the dial was read this turn */
    /* 0x08 */ u16 wait;
    /* 0x0A */ s16 cpuPick; /* CPU's wanted dial value (1 or 2), -1 none */
    /* 0x0C */ f32 time;
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ u16 walking;
    /* 0x16 */ u16 turnCnt;
    /* 0x18 */ f32 turnStep;
    /* 0x1C */ s32 limit; /* turn time limit, frames */
    /* 0x20 */ s8 limitOn;
    /* 0x21 */ s8 out;
} HCPlayer; /* size = 0x24 */

/* An item on the branch (func_80104924, 0x2C bytes). type: 0-4 fruit, 5 coin, 6 honeycomb,
   7 fruit with a sparkle trail. */
typedef struct HCItem {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 slot; /* position on the branch (D_801073C0) */
    /* 0x04 */ u16 timer;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 vx;
    /* 0x0C */ f32 vy;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 angle; /* throw */
    /* 0x1C */ f32 speed;
    /* 0x20 */ f32 x0;
    /* 0x24 */ f32 y0;
    /* 0x28 */ u16 sparkle;
    /* 0x2A */ s16 sparkleMdl;
} HCItem; /* size = 0x2C */

/* The sparkle pool (func_80105844, 0x6C bytes). */
typedef struct HCSparkles {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ s16 model[6];
    /* 0x18 */ s16 active[6];
    /* 0x24 */ Vec pos[6];
} HCSparkles; /* size = 0x6C */

/* The screen shake (func_80105ACC). */
typedef struct HCShake {
    /* 0x00 */ u16 count;
    /* 0x02 */ s16 amp;
} HCShake;

/* The bee swarm (func_80105C04, 0x18 bytes). */
typedef struct HCBees {
    /* 0x00 */ f32 scale;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ f32 angle;
    /* 0x0C */ f32 radius;
    /* 0x10 */ f32 dAngle;
    /* 0x14 */ u16 timer;
    /* 0x16 */ u16 hit;
} HCBees; /* size = 0x18 */

/* A falling leaf (func_801065BC, 0x1C bytes). */
typedef struct HCLeaf {
    /* 0x00 */ f32 dx;
    /* 0x04 */ f32 amp;
    /* 0x08 */ f32 dy;
    /* 0x0C */ f32 fall;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 dAngle;
    /* 0x18 */ u16 timer;
    /* 0x1A */ u16 period;
} HCLeaf; /* size = 0x1C */

/* ---- .data (asm, 0x22DE20) ---- */
extern s16 D_80107350_22DE20_HoneycombHavoc; /* bee buzz sound, -1 none */
extern s16 D_80107352_22DE22_HoneycombHavoc; /* stung voice, -1 none */
extern s8 D_80107354_22DE24_HoneycombHavoc;  /* players left (4) */
extern f32 D_80107358_22DE28_HoneycombHavoc[6]; /* per character: catch height */
extern f32 D_80107370_22DE40_HoneycombHavoc[6]; /* per character: reach */
extern f32 D_80107388_22DE58_HoneycombHavoc[4]; /* per slot: queue x */
extern f32 D_80107398_22DE68_HoneycombHavoc[4]; /* per slot: stop x */
extern u16 D_801073A8_22DE78_HoneycombHavoc[4]; /* slot taken */
extern s16 D_801073B0_22DE80_HoneycombHavoc[8]; /* item model file per type */
extern f32 D_801073C0_22DE90_HoneycombHavoc[33][2]; /* branch positions (x, y) */
extern u32 D_801074C8_22DF98_HoneycombHavoc;
extern u32 D_801074CC_22DF9C_HoneycombHavoc;
extern u16 D_801074D0_22DFA0_HoneycombHavoc[8]; /* [0] intro countdown (16) */
extern u16 D_801074E0_22DFB0_HoneycombHavoc[8]; /* [0] quit request */

/* ---- .rodata ---- */
extern const char D_801074F0_22DFC0_HoneycombHavoc[]; /* "item_hook" */

/* ---- .bss ---- */
extern u16 D_801076A0_22E170_HoneycombHavoc;
extern f32 D_801076A4_22E174_HoneycombHavoc;
extern u16 D_801076A8_22E178_HoneycombHavoc; /* game state: 0 intro, 1 play, 2 end */
extern s16 D_801076AA_22E17A_HoneycombHavoc; /* intro state */
extern s16 D_801076AC_22E17C_HoneycombHavoc; /* end state */
extern s16 D_801076AE_22E17E_HoneycombHavoc; /* winner, -1 none */
extern s16 D_801076B0_22E180_HoneycombHavoc; /* index of the lowest item left */
extern s16 D_801076B2_22E182_HoneycombHavoc; /* leaf model */
extern s32 D_801076B8_22E188_HoneycombHavoc[4]; /* per player: win motion file */
extern f32 D_801076C8_22E198_HoneycombHavoc; /* current player's catch height */
extern f32 D_801076CC_22E19C_HoneycombHavoc; /* current player's reach */
extern f32 D_801076D0_22E1A0_HoneycombHavoc; /* dial speed */
extern u16 D_801076D4_22E1A4_HoneycombHavoc; /* background sprite */
extern omObjData** D_801076D8_22E1A8_HoneycombHavoc; /* players */
extern omObjData** D_801076DC_22E1AC_HoneycombHavoc; /* items */
extern omObjData* D_801076E0_22E1B0_HoneycombHavoc; /* item being thrown */
extern omObjData* D_801076E4_22E1B4_HoneycombHavoc; /* dial */
extern omObjData* D_801076E8_22E1B8_HoneycombHavoc; /* shake */
extern omObjData* D_801076EC_22E1BC_HoneycombHavoc; /* bees */
extern omObjData* D_801076F0_22E1C0_HoneycombHavoc; /* tree */
extern omObjData* D_801076F4_22E1C4_HoneycombHavoc; /* sparkles */
extern omObjData* D_801076F8_22E1C8_HoneycombHavoc; /* camera */
extern omObjData* D_801076FC_22E1CC_HoneycombHavoc; /* intro */
extern omObjData* D_80107700_22E1D0_HoneycombHavoc; /* ending */
extern omObjData* D_80107704_22E1D4_HoneycombHavoc; /* coin sprite */
extern s16 D_80107708_22E1D8_HoneycombHavoc; /* coin sprite slot */
extern s16 D_80107710_22E1E0_HoneycombHavoc[36]; /* item types, bottom first after the reverse */
extern s16 D_80107758_22E228_HoneycombHavoc[8]; /* item model per type, -1 honeycomb (sprite) */
extern s8 D_80107770_22E240_HoneycombHavoc; /* item count */

/* ---- functions ---- */
/* 2292D0.c */
void func_80102800_2292D0_HoneycombHavoc(void);
void func_80102A7C_22954C_HoneycombHavoc(omObjData* obj);
void func_80102B34_229604_HoneycombHavoc(omObjData* obj);
void func_80102B70_229640_HoneycombHavoc(omObjData* obj);
void func_80102C5C_22972C_HoneycombHavoc(omObjData* obj);
void func_80102C7C_22974C_HoneycombHavoc(omObjData* obj);
void func_80102C9C_22976C_HoneycombHavoc(omObjData* obj);
void func_80102CBC_22978C_HoneycombHavoc(omObjData* obj);
void func_80102CDC_2297AC_HoneycombHavoc(s32 player, omObjData* obj);
void func_80102FB4_229A84_HoneycombHavoc(omObjData* obj);
void func_80104180_22AC50_HoneycombHavoc(void);
void func_80104280_22AD50_HoneycombHavoc(void);
void func_801043A0_22AE70_HoneycombHavoc(void);
void func_801044AC_22AF7C_HoneycombHavoc(omObjData* obj);
u16 func_80104684_22B154_HoneycombHavoc(omObjData* obj);
void func_80104708_22B1D8_HoneycombHavoc(void);
void func_8010479C_22B26C_HoneycombHavoc(omObjData* obj);
u8 func_801047EC_22B2BC_HoneycombHavoc(void);
u8 func_8010488C_22B35C_HoneycombHavoc(f32 angle, s32* quarter);
void func_80104924_22B3F4_HoneycombHavoc(void);
void func_80105230_22BD00_HoneycombHavoc(omObjData* obj);
void func_801053BC_22BE8C_HoneycombHavoc(f32 angle, f32 speed);
void func_801055EC_22C0BC_HoneycombHavoc(omObjData* obj);
u16 func_801057AC_22C27C_HoneycombHavoc(void);
s32 func_801057D4_22C2A4_HoneycombHavoc(s32 i, s32 type, s32 arg2);
void func_80105844_22C314_HoneycombHavoc(void);
void func_801058FC_22C3CC_HoneycombHavoc(omObjData* obj);
void func_801059DC_22C4AC_HoneycombHavoc(f32 x, f32 y, f32 z);
void func_80105ACC_22C59C_HoneycombHavoc(void);
void func_80105B24_22C5F4_HoneycombHavoc(omObjData* obj);
void func_80105BD4_22C6A4_HoneycombHavoc(s16 count, s16 amp);
u16 func_80105BEC_22C6BC_HoneycombHavoc(void);
void func_80105C04_22C6D4_HoneycombHavoc(void);
void func_80105CB8_22C788_HoneycombHavoc(omObjData* obj);
void func_801062A8_22CD78_HoneycombHavoc(f32 x, f32 y);
void func_80106324_22CDF4_HoneycombHavoc(void);
void func_801064A0_22CF70_HoneycombHavoc(void);
void func_80106540_22D010_HoneycombHavoc(omObjData* obj);
void func_80106598_22D068_HoneycombHavoc(void);
void func_801065BC_22D08C_HoneycombHavoc(f32 x, f32 y);
void func_801067F4_22D2C4_HoneycombHavoc(omObjData* obj);
void func_801069C8_22D498_HoneycombHavoc(omObjData* obj);
void func_80106AC4_22D594_HoneycombHavoc(omObjData* obj);
void func_80107038_22DB08_HoneycombHavoc(omObjData* obj);
void func_801071B4_22DC84_HoneycombHavoc(omObjData* obj);
void func_801071E0_22DCB0_HoneycombHavoc(omObjData* obj);
/* 22DD10.c */
void func_80107240_22DD10_HoneycombHavoc(f32 fov, f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z);
void func_801072F8_22DDC8_HoneycombHavoc(omObjData* obj);
void func_80107330_22DE00_HoneycombHavoc(omObjData* obj);

#endif
