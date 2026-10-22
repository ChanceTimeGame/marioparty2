#ifndef _OVL_2A_H
#define _OVL_2A_H

/* Overlay 2A (2111A0.c): Bumper Balls, descended from MP1's ovl_1E_BumperBalls (191700.c for the
   game, 196300.c for the water mesh). .data stays asm; .rodata is carved
   ([0x218A40, .rodata, 2111A0]). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"

/* ---- main-segment API used by 2A ---- */

omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void* DataRead(s32 dirAndFile);
void HuMemMemoryFreePerm(void*);
void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_80020718_21318(s16, void*, void*);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32); /* MP1 func_8005DB44: the object group's list */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8003DF08_3EB08(void*);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80029708_2A308(s32);
void func_8002E544_2F144(void);
void func_8006D4D0_6E0D0(s16); /* MP1 func_80079078: the seconds counter */

void espDispOff(u16);
u8 rand8(void);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029A8C_2A68C(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029E80_2AA80(s16, s32, s32);
void func_8002BB4C_2C74C(s16 arg0, char* arg1, char* arg2); /* texture swap */
void func_8003C8E0_3D4E0(s16);
f32 func_800B75A8_B81A8(f32, f32); /* atan2 */
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f64 fabs(f64);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16 arg0, f32 arg1);
s16 func_800797DC_7A3DC(s32, s16); /* MP1 func_80060618: player voice */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
f32 func_80029CE4_2A8E4(s16); /* model motion time */
f32 func_80029D0C_2A90C(s16); /* model motion length */
void func_8002A15C_2AD5C(s16 arg0, s16 arg1, f32 arg2); /* MP1 func_80026174: blend two models */
void func_80076E54_77A54(omObjData*, s32); /* MP1 func_8005DC18 */
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void); /* MP1 GMesStatAllGet */
void func_8006D518_6E118(void); /* MP1 func_800790C0 */
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80079848_7A448(s16 arg0); /* stop the music */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_80026D50_27950(s16 arg0, u8 arg1, u8 arg2);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002A00C_2AC0C(s16);
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6); /* texture scroll */
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8003EAF0_3F6F0(char* arg0, void* arg1); /* the size of the texture named arg0 */
u16 func_80078EA8_79AA8(void);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8007A7FC_7B3FC(void*);

/* 1AE60.c's esprite slot */
typedef struct BumperBallsEspSlot {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* sprite group */
    /* 0x06 */ char unk_06[0x1E];
} BumperBallsEspSlot; /* size = 0x24 */

/* func_8003EAF0_3F6F0's output */
typedef struct BumperBallsTexSize {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
} BumperBallsTexSize;

extern s32 D_800F9D30_FA930[];
extern BumperBallsEspSlot* D_800F93FC_F9FFC;
extern f32 D_8010105C_101C5C;
extern f32 D_80101300_101F00;
extern u8 D_80102720_103320;
extern s32 D_800FA5B8_FB1B8;
extern u8 D_800FA656; /* minigame variant: 0 plays the music, 2 adds the rescue boats */
extern u8 D_800FD8AC[]; /* CPU difficulty when flag 0xC is set */

/* A player's ball work (func_801035AC, 0x98 bytes). MP1's BumperBallsWork with fields added at
   0x42-0x4F: MP1's 0x42-0x4C sit 0xE later, its 0x50-0x5A 0xC later. */
typedef struct BumperBallsWork {
    /* 0x00 */ u16 unk_00; /* state: 0 idle, 1 roll, 2 fast, 3 falling, 4 floating, 5 rescued, 6 winner */
    /* 0x02 */ s16 character;
    /* 0x04 */ u16 player;
    /* 0x06 */ char pad_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C; /* heading */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14; /* wanted heading */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20; /* radius */
    /* 0x24 */ f32 unk_24; /* velocity x */
    /* 0x28 */ f32 unk_28; /* velocity y */
    /* 0x2C */ f32 unk_2C; /* velocity z */
    /* 0x30 */ f32 unk_30; /* ball rotation */
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ u8 unk_40[2];
    /* 0x42 */ s16 unk_42; /* ground surface (func_80106C88): 0x200 at start, 0x900 slows the ball */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* CPU mode (MP1 0x42) */
    /* 0x52 */ u16 unk_52;
    /* 0x54 */ u16 unk_54;
    /* 0x56 */ u16 unk_56;
    /* 0x58 */ u16 unk_58;
    /* 0x5A */ u16 unk_5A;
    /* 0x5C */ f32 unk_5C; /* CPU heading (bob phase once floating) (MP1 0x50) */
    /* 0x60 */ omObjData* unk_60; /* CPU target (MP1 0x54) */
    /* 0x64 */ u16 unk_64; /* MP1 0x58 */
    /* 0x66 */ u16 unk_66; /* MP1 0x5A */
    /* 0x68 */ f32 unk_68; /* variant 0: glow light position (func_80109D80) */
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ u8 unk_74[3]; /* glow light colour, brighter away from the centre */
    /* 0x77 */ u8 unk_77;
    /* 0x78 */ u16 unk_78; /* frames to the next lava ring */
    /* 0x7A */ u8 unk_7A[4]; /* lava rings (model[6 + i]) in use */
    /* 0x7E */ char pad_7E[2];
    /* 0x80 */ f32 unk_80[4]; /* ring scale */
    /* 0x90 */ s32 unk_90; /* motion file of slot 3 */
    /* 0x94 */ s32 unk_94; /* motion file of slot 6 */
} BumperBallsWork; /* size = 0x98 */

/* The rescue boats' work (func_80105700, 0x20 bytes). */
typedef struct BumperBallsBoatWork {
    /* 0x00 */ u16 player;
    /* 0x02 */ u16 state;
    /* 0x04 */ u16 side;
    /* 0x06 */ u16 model;
    /* 0x08 */ u16 model2;
    /* 0x0A */ char pad_0A[2];
    /* 0x0C */ f32 angle;
    /* 0x10 */ f32 speed;
    /* 0x14 */ f32 dx;
    /* 0x18 */ f32 dy;
    /* 0x1C */ f32 endX;
} BumperBallsBoatWork; /* size = 0x20 */

/* Per-character data, 0x18 bytes each (ovl_34's CTCharData, ovl_6F's BRCharData). */
typedef struct BumperBallsCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
} BumperBallsCharData; /* size = 0x18 */
extern BumperBallsCharData D_800CD438_CE038[];

/* ---- overlay .data ---- */

extern Vec D_80109FE0_218980_BumperBalls[4]; /* start positions */
extern char* D_8010A010_2189B0_BumperBalls[6]; /* ball texture per character */
extern s32 D_8010A028_2189C8_BumperBalls[3]; /* the island model per variant */
extern u8 D_8010A034_2189D4_BumperBalls[4]; /* start positions taken */
extern u8 D_8010A038_2189D8_BumperBalls; /* 3: take the start positions in order */
extern u16 D_8010A03A_2189DA_BumperBalls; /* entries in D_8010A03C */
extern u16 D_8010A03C_2189DC_BumperBalls[4]; /* winners */
extern u16 D_8010A080_218A20_BumperBalls; /* the minigame is over */

/* ---- overlay .bss ---- */

extern s16 D_8010A250_218BF0_BumperBalls;
extern u16 D_8010A252_218BF2_BumperBalls; /* the winner */
extern f32 D_8010A254_218BF4_BumperBalls; /* the winner's turn step */
extern omObjData* D_8010A258_218BF8_BumperBalls; /* the winner's ball */
extern u16 D_8010A25C_218BFC_BumperBalls; /* end timer */
extern s16 D_8010A25E_218BFE_BumperBalls; /* MP1 D_800FCD0E */
extern u16 D_8010A260_218C00_BumperBalls; /* balls still on the island (MP1 D_800FCD10) */

extern s16 D_8010A262_218C02_BumperBalls; /* _CheckFlag(0xC) */
extern u16 D_8010A264_218C04_BumperBalls; /* frames to the next second */
extern u16 D_8010A266_218C06_BumperBalls; /* seconds left */
extern s16 D_8010A268_218C08_BumperBalls;
extern s16 D_8010A26A_218C0A_BumperBalls;
extern s16 D_8010A26C_218C0C_BumperBalls;
extern s16 D_8010A26E_218C0E_BumperBalls;
extern u16 D_8010A270_218C10_BumperBalls; /* variant 1: the backdrop sprite */ /* humans still on the island (MP1 D_800FCD1E) */
extern u16 D_8010A272_218C12_BumperBalls; /* D_800FA656 */
extern s16 D_8010A274_218C14_BumperBalls; /* music handle */
extern f32 D_8010A278_218C18_BumperBalls; /* variant 0: lava texture scroll */
extern f32 D_8010A27C_218C1C_BumperBalls;
extern BumperBallsTexSize D_8010A280_218C20_BumperBalls; /* "152_yougan2_IA44" */
extern BumperBallsTexSize D_8010A284_218C24_BumperBalls; /* "152_yougan1_DEF" */
extern omObjData* D_8010A290_218C30_BumperBalls; /* the island */
extern omObjData* D_8010A294_218C34_BumperBalls; /* the start object (func_80105EBC) */
extern omObjData* D_8010A298_218C38_BumperBalls; /* the end object (func_80105FB0) */
extern omObjData** D_8010A29C_218C3C_BumperBalls; /* the balls */
extern omObjData** D_8010A2A0_218C40_BumperBalls; /* the boats */
extern u16 D_8010A560_218F00_BumperBalls; /* end state: 10 one winner, 13 none */
extern u16 D_8010A562_218F02_BumperBalls; /* game state: 0 start, 1 play, 2 end */
extern u16 D_8010A564_218F04_BumperBalls; /* start object state (MP1 D_800FCFF0) */

/* MG2A-B: types, data and main-segment API of 80106730 on */

#include "game/camera.h"

/* func_8002F2C4's probe point (2E0D0.c's HitProbe) */
typedef struct BumperBallsHitProbe {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
} BumperBallsHitProbe;

void func_800794A8_7A0A8(s32);
s32 func_8008F618_90218(void); /* fade still running */
s16 func_80079798_7A398(s16 sfx, s16 player); /* play a sound effect for a player */
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_8002F2C4_2FEC4(s16 model, s32* list, void* filter, void* probe); /* collect the model's faces */
u16* func_8002F848_30448(s32* list); /* next face, NULL at the end */
f32 func_8002DBA4_2E7A4(f32 x, f32 y, f32 z, ColVtx* verts, u16* tri); /* height on a face */
void func_8002DA3C_2E63C(ColVtx* a, ColVtx* b, ColVtx* c, Vec* n); /* face normal */
f32 func_8002DB3C_2E73C(f32 x, f32 z, ColVtx* a, ColVtx* b); /* side of an edge */
f32 fabsf(f32);

extern u16 D_801011FC_101DFC; /* set: skip the minigame */
extern s16 gNumOfControllers;
extern u16 D_8010A044_2189E4_BumperBalls; /* the end fade has started */
extern u16 D_8010A048_2189E8_BumperBalls[8]; /* CPU behaviours, by difficulty and humans left */
extern u16 D_8010A058_2189F8_BumperBalls[8];
extern u16 D_8010A068_218A08_BumperBalls[8];
extern f32 D_8010A288_218C28_BumperBalls; /* CPU: the predicted position */
extern f32 D_8010A28C_218C2C_BumperBalls;

/* Water mesh (MP1 196300.c): wave phases of the 6 x 6 mesh, per row the near edge's 6 pairs then
   the far edge's 6. func_8010851C indexes the far pairs as half-rows of 6 from the splat label
   D_8010A2E0 (= D_8010A2B0 + 0x30; far edge of row r = D_8010A2E0[2r]); func_80109868 as rows of
   12 (BB_WAVE_FAR). On a host build D_8010A2E0 is a view into D_8010A2B0, not its own array. */
typedef struct BumperBallsAnglePair {
    f32 first;
    f32 second;
} BumperBallsAnglePair;
extern BumperBallsAnglePair D_8010A2B0_218C50_BumperBalls[6][12];
extern BumperBallsAnglePair D_8010A2E0_218C80_BumperBalls[][6];
#define BB_WAVE_FAR ((BumperBallsAnglePair(*)[12])D_8010A2E0_218C80_BumperBalls)
extern HmfTex* D_8010A4F0_218E90_BumperBalls; /* "47mt003_DEF" (water) */
extern HmfTex* D_8010A4F4_218E94_BumperBalls; /* "47mt002_IA44" */
extern Gfx* D_8010A4F8_218E98_BumperBalls[8]; /* water display list per screen */
extern Vtx* D_8010A518_218EB8_BumperBalls[8]; /* water vertices per screen */
extern Vtx* D_8010A538_218ED8_BumperBalls[8]; /* their copy for the textured pass */
extern s32 D_8010A558_218EF8_BumperBalls; /* the water model */
/* Water texture scroll (.data): s/t of the near edge, of the far edge (+1024), per-frame steps. */
extern f32 D_8010A084_218A24_BumperBalls;
extern f32 D_8010A088_218A28_BumperBalls;
extern f32 D_8010A08C_218A2C_BumperBalls;
extern f32 D_8010A090_218A30_BumperBalls;
extern f32 D_8010A094_218A34_BumperBalls;
extern f32 D_8010A098_218A38_BumperBalls;
extern const char D_8010A220_218BC0_BumperBalls[];
extern const char D_8010A22C_218BCC_BumperBalls[];

extern u8 D_800FDBCA_FE7CA; /* screen count */
extern u8 D_800FDBE0_FE7E0; /* frame buffer index */
extern HmfTex* D_800FD89C_FE49C; /* the texture table, 128 entries */
/* gDPLoadBlock/gDPSetTile parameters of the texture size (MP1 D_800ED568 ...) */
extern u32 D_800F92E0_F9EE0; /* load block size */
extern u32 D_800F956C_FA16C; /* increment */
extern u32 D_801026D0_1032D0; /* bytes per texel */
extern u32 D_800F60A4_F6CA4; /* line bytes */
extern u32 D_800FDBD4_FE7D4; /* shift */
s16 func_8001F4AC_200AC(char*); /* name hash */
#ifndef INTEGER_LOG2
#define INTEGER_LOG2(x) ((x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : 8)
#endif
s32 func_800B0FD0_B1BD0(char*, char*); /* strcmp */
s16 func_80027FA4_28BA4(u32, void*, u8); /* display-list model */
f64 func_800B0D98_B1998(f64, f64); /* fmod */

/* CPU: turn away from the island's edge for 15-29 frames. */
#define BB_FLEE_EDGE(object, work, stickX, stickY)                                                  \
    {                                                                                                \
        work->unk_5C = func_80108384_216D24_BumperBalls(object);                                     \
        *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;                                         \
        *stickY = -HuMathSin(work->unk_5C) * 80.0f;                                                  \
        work->unk_54 = (u8)(rand8() % 15) + 15;                                                      \
    }

/* ---- overlay functions (fork A: 80102800-80105FB0; fork B: 80106730 on) ---- */

void func_80102800_2111A0_BumperBalls(void);
void func_80102C5C_2115FC_BumperBalls(omObjData* arg0);
void func_80102CB0_211650_BumperBalls(omObjData* arg0);
void func_80102F98_211938_BumperBalls(omObjData* arg0);
void func_80103414_211DB4_BumperBalls(omObjData* arg0);
void func_80103430_211DD0_BumperBalls(omObjData* arg0);
void func_8010351C_211EBC_BumperBalls(omObjData* arg0);
void func_80103558_211EF8_BumperBalls(omObjData* arg0);
void func_80103574_211F14_BumperBalls(omObjData* arg0);
void func_80103590_211F30_BumperBalls(omObjData* arg0);
void func_801035AC_211F4C_BumperBalls(omObjData* arg0, s32 player);
void func_80103D68_212708_BumperBalls(omObjData* arg0);
void func_801046B8_213058_BumperBalls(omObjData* arg0);
void func_80104950_2132F0_BumperBalls(omObjData* arg0);
void func_80104B70_213510_BumperBalls(omObjData* arg0);
void func_80104E04_2137A4_BumperBalls(omObjData* arg0);
void func_8010515C_213AFC_BumperBalls(omObjData* arg0);
void func_80105244_213BE4_BumperBalls(omObjData* arg0);
void func_8010545C_213DFC_BumperBalls(omObjData* arg0);
void func_801054DC_213E7C_BumperBalls(omObjData* arg0);
void func_80105604_213FA4_BumperBalls(omObjData* arg0);
void func_80105690_214030_BumperBalls(omObjData* arg0);
void func_801056AC_21404C_BumperBalls(omObjData* arg0);
void func_801056C8_214068_BumperBalls(omObjData* arg0);
void func_801056E4_214084_BumperBalls(omObjData* arg0);
void func_80105700_2140A0_BumperBalls(omObjData* arg0, s32 player);
void func_80105948_2142E8_BumperBalls(omObjData* arg0);
void func_80105EBC_21485C_BumperBalls(omObjData* arg0);
void func_80105FB0_214950_BumperBalls(omObjData* arg0);
/* fork B (inferred from the asm and MP1's twins: check yours) */
void func_80106730_2150D0_BumperBalls(omObjData* arg0);
u16 func_801067D8_215178_BumperBalls(omObjData* arg0);
void func_80106AD8_215478_BumperBalls(f32 arg0, u16 arg1);
f32 func_80106C88_215628_BumperBalls(s16* surface, f32* push, f32 x, f32 y, f32 z); /* ground height under (x, z) */
u16 func_80106E94_215834_BumperBalls(omObjData* arg0);
s32 func_80106FCC_21596C_BumperBalls(s32 arg0, u16* polygon, ColVtx* vertices, BumperBallsHitProbe* probe);
s32 func_80106FEC_21598C_BumperBalls(BumperBallsHitProbe* probe, u16* poly, ColVtx* verts);
u16 func_80107204_215BA4_BumperBalls(void); /* every ball has fallen */
void func_80107254_215BF4_BumperBalls(omObjData* arg0);
u16 func_801076A0_216040_BumperBalls(omObjData* arg0);
u16 func_801076D4_216074_BumperBalls(omObjData* arg0, f32 arg1);
void func_80107868_216208_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_801078FC_21629C_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80107C3C_2165DC_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80107DD4_216774_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80108074_216A14_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
f32 func_80108384_216D24_BumperBalls(omObjData* arg0);
void func_80108410_216DB0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_801084C8_216E68_BumperBalls(omObjData* arg0);
void func_80108500_216EA0_BumperBalls(omObjData* arg0);
void func_8010851C_216EBC_BumperBalls(char* tex, char* tex2, s32 arg2); /* water mesh (MP1 func_800FB2EC) */
void func_80108C70_217610_BumperBalls(void);
void func_80109868_218208_BumperBalls(void);
void func_80109D80_218720_BumperBalls(omObjData* arg0);

#endif
