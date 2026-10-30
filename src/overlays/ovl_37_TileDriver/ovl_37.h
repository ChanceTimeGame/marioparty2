#ifndef _OVL_37_H
#define _OVL_37_H

/* Overlay 37: Tile Driver (4P free-for-all). Each player has a 3x3 board of three-sided tiles and
   a screen quarter; a sample board (slot 14, shown in the fifth camera) spins through its faces
   during the intro and settles on the target pattern D_80107C10_27A340_TileDriver[4]. Jumping (A) and ground
   pounding (Z) on a tile flips it to its next face; the first player whose nine tiles all show the
   target's centre face D_80107C10_27A340_TileDriver[4][4] wins. All players are CPU-capable (func_8010350C_275C3C_TileDriver).
   30 s timer (D_80107C08_27A338_TileDriver = 1801 in state 2). The winner gets 10 in gPlayers[].coins_mg_bonus; a
   timeout gives everybody 0. _CheckFlag(0xC) keeps the wide camera and skips the win pose.
   Retail is two files: 274F30.c (80102800-80107890) and 279FC0.c (the two table clears; 2-nop
   text pad). .rodata is carved from 0x27A2E0 (274F30.c only).
   N64 offsets are in the comments; structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* One entry of D_80107CF0_27A420_TileDriver[100] (cleared by func_80107890_279FC0_TileDriver). Entries 0-3 are the players, 4 the
   stage, 10-13 the player boards (player + 10), 14 the sample board, 20 the backdrop (both
   backdrop objects store here, the second wins). */
typedef struct TDObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 punched;   /* player: a pound landed; the board clears it when the flip ends */
    /* 0x22 */ u16 posed;     /* player: result motion started */
    /* 0x24 */ u16 chance;    /* CPU: x/20 per frame to jump on a wrong tile */
    /* 0x26 */ u16 jump;      /* CPU: x/10 per frame to pound while falling */
    /* 0x28 */ u16 miss;      /* CPU: x/500 per frame to jump on a right tile */
    /* 0x2A */ u16 walking;   /* CPU: 1 while it walks to a tile */
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 stickX;    /* CPU */
    /* 0x32 */ s16 stickY;
    /* 0x34 */ s16 speed;     /* CPU stick strength */
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;    /* board: flip phase (360 to 0); player (CPU): jump height to hold A to */
    /* 0x3C */ f32 unk_3C;    /* board: the flipping tile's height */
    /* 0x40 */ f32 unk_40;    /* board: the flipping tile's angle */
    /* 0x44 */ f32 unk_44;
} TDObj; /* size = 0x48 (N64) */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct TDCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* its model file */
    /* 0x14 */ char unk_14[4];
} TDCharData; /* size = 0x18 */

#define TD_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

/* ---- .data (0x27A070-0x27A2E0, defined in 274F30.c) ---- */
extern f32 D_80107940_27A070_TileDriver[6][4];  /* screen rectangles x0, y0, x1, y1: four quarters, whole, whole */
extern f32 D_801079A0_27A0D0_TileDriver[6][6];  /* viewports */
extern Vec D_80107A30_27A160_TileDriver[9];     /* tile start positions (labels: D_80107A34_27A164_TileDriver = [0].y) */
extern Vec D_80107A9C_27A1CC_TileDriver[9];     /* tile offsets from a board's centre at scale 1 */
extern Vec D_80107B08_27A238_TileDriver[9];     /* tiles of a player's board */
extern u16 D_80107B74_27A2A4_TileDriver[9];     /* tile model files (label D_80107B72_27A2A2_TileDriver = D_80107B74_27A2A4_TileDriver - 1) */
extern u32 D_80107B88_27A2B8_TileDriver[6];     /* result voice directory by character */
extern u16 D_80107BA0_27A2D0_TileDriver[4];     /* result voice file by D_80107C00_27A330_TileDriver */
extern u8 D_80107BA8_27A2D8_TileDriver;          /* music started */

/* ---- .bss ---- */
extern u8 D_80107C00_27A330_TileDriver[4][2];   /* the win and lose voice picked for each player */
extern s16 D_80107C08_27A338_TileDriver;        /* state timer */
extern s16 D_80107C0A_27A33A_TileDriver;        /* camera zoom timer */
extern u8 D_80107C0C_27A33C_TileDriver;         /* game state: 0 intro, 1 ready, 2 play, 3 stop, 4 result, 5 fade */
extern u8 D_80107C0D_27A33D_TileDriver;         /* state step request */
extern s16 D_80107C0E_27A33E_TileDriver;        /* backdrop alpha (retail reads the low byte by D_80107C0F_27A33F_TileDriver) */
extern u8 D_80107C10_27A340_TileDriver[5][9];   /* faces of the boards; [4] the target (D_80107C34_27A364_TileDriver = [4][0], D_80107C38_27A368_TileDriver = [4][4]) */
extern u8 D_80107C3D_27A36D_TileDriver[9];      /* target tile has settled (D_80107C41_27A371_TileDriver = [4]: the centre) */
extern u8 D_80107C46_27A376_TileDriver;         /* someone won */
extern u8 D_80107C47_27A377_TileDriver[4];      /* player finished */
extern u8 D_80107C4B_27A37B_TileDriver[2][3];   /* colours dealt: [0] target, [1] (D_80107C4E_27A37E_TileDriver) the boards */
extern u8 D_80107C58_27A388_TileDriver[4][9];   /* tile is flipping */
extern u8 D_80107C7C_27A3AC_TileDriver;         /* the winner */
extern u8 D_80107C7D_27A3AD_TileDriver;         /* last CPU difficulty seen */
extern s16 D_80107C80_27A3B0_TileDriver[50];    /* sprite animations */
extern TDObj D_80107CF0_27A420_TileDriver[100];
extern s16 D_80107E14_27A544_TileDriver;        /* = D_80107CF0_27A420_TileDriver[4].spr */

/* ---- main ---- */
extern u8 D_800FA656;  /* the game's tile colour: the target board's start */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A4_C03A4; /* player run scale */
extern s32 D_800F8FD0_F9BD0; /* scene state */
void func_8000BE98_CA98(omObjData*, f32);
void func_8000C460_D060(void);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_80007790_8390(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80026D28_27928(s32);
void func_8002D0A0_2DCA0(s16, u8);
void func_8002D124_2DD24(s16);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_800794A8_7A0A8(s32);
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
s32 func_8008F618_90218(void);

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern s16 D_800FA606_FB206;
extern TDCharData D_800CD438_CE038[];
extern u16 D_801011FC_101DFC;
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_80018E30_19A30(s32);
u16 func_80018A30_19630(s32 file, s32 attr); /* model from a file */
void func_80018F58_19B58(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);                 /* model motion time */
f32 func_80029D0C_2A90C(s16);                 /* motion length */
void func_80029EDC_2AADC(s16 arg0, s16 arg1); /* main: (s16, u8); retail passes an s16 here */
void func_8002D4D0_2E0D0(s16 n);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E560_3F160(s16, u8); /* defined (s16, s32) in 3D6A0.c; retail passes a u8 here */
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16 seconds); /* timer display */
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80079128_79D28(void);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f64 func_800B1820_B2420(f64);     /* sqrt, in double */
f64 func_800B75D0_B81D0(f64);     /* cos of degrees, in double */
f64 func_800B80D0_B8CD0(f64);     /* sin of degrees, in double */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osViBlack(u8 active);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);

/* ---- overlay functions ---- */

void func_80102800_274F30_TileDriver(void);
void func_8010281C_274F4C_TileDriver(void);
void func_80102F84_2756B4_TileDriver(omObjData* obj);
void func_80102FB0_2756E0_TileDriver(omObjData* obj);
void func_8010316C_27589C_TileDriver(void);
void func_801031B4_2758E4_TileDriver(omObjData* obj);
void func_8010323C_27596C_TileDriver(omObjData* obj);
void func_801032BC_2759EC_TileDriver(void);
void func_80103300_275A30_TileDriver(omObjData* obj);
void func_8010339C_275ACC_TileDriver(omObjData* obj);
void func_80103444_275B74_TileDriver(void);
void func_80103488_275BB8_TileDriver(u8 player);
void func_8010350C_275C3C_TileDriver(omObjData* obj);
void func_80103988_2760B8_TileDriver(omObjData* obj);
void func_80103E24_276554_TileDriver(omObjData* obj);
void func_801043A4_276AD4_TileDriver(void);
void func_801044C8_276BF8_TileDriver(omObjData* obj);
void func_801049A0_2770D0_TileDriver(omObjData* obj);
void func_80104E08_277538_TileDriver(void);
void func_80104EA8_2775D8_TileDriver(omObjData* obj);
void func_801053A4_277AD4_TileDriver(omObjData* obj);
void func_801059B4_2780E4_TileDriver(omObjData* obj);
void func_80105C78_2783A8_TileDriver(omObjData* obj);
void func_80105DB0_2784E0_TileDriver(omObjData* obj);
void func_801065EC_278D1C_TileDriver(void);
void func_80106630_278D60_TileDriver(void);
void func_801066F8_278E28_TileDriver(omObjData* obj);
void func_801067B4_278EE4_TileDriver(omObjData* obj);
void func_80106844_278F74_TileDriver(omObjData* obj);
void func_80106984_2790B4_TileDriver(omObjData* obj);
void func_80106A74_2791A4_TileDriver(omObjData* obj);
void func_80106AC0_2791F0_TileDriver(omObjData* obj);
void func_80106B08_279238_TileDriver(omObjData* obj);
void func_80106B7C_2792AC_TileDriver(void);
void func_80106BA0_2792D0_TileDriver(omObjData* obj);
void func_80106BD8_279308_TileDriver(omObjData* obj);
void func_80106C30_279360_TileDriver(void);
void func_80106C58_279388_TileDriver(void);
void func_80106E20_279550_TileDriver(omObjData* obj);
void func_80106ED8_279608_TileDriver(void);
void func_801070A4_2797D4_TileDriver(omObjData* obj);
void func_80107168_279898_TileDriver(void);
f32 func_801073BC_279AEC_TileDriver(f32 x);
void func_8010750C_279C3C_TileDriver(Vec* from, Vec* to, Vec* out);
void func_80107890_279FC0_TileDriver(void);
void func_80107914_27A044_TileDriver(void);

#endif /* _OVL_37_H */
