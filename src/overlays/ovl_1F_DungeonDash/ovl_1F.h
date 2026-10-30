#ifndef _OVL_1F_H
#define _OVL_1F_H

/* Overlay 1F: Dungeon Dash (2 vs 2), descended from MP1's ovl_27_DesertDash (1D3990.c, 1D6E30.c,
   DesertDash.h). Each team pulls one shared sled down a corridor, one team per half of the screen
   (cameras 0 and 1); blocks rise and slam down on the course. Two retail files: 1BE380.c and
   1C2D40.c (from 801071C0). .data stays asm (1C6260.data.s); .rodata is carved per file
   ([0x1C6760, .rodata, 1BE380], [0x1C6A40, .rodata, 1C2D40]). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h" /* S4-1FB: HuSprite_Unk84_Struct in the prototypes */

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One team of two (D_8010B068[2], bss; MP1 DDTeam 0x4C): the pair pulls one shared sled. */
typedef struct DDTeam {
    /* 0x00 */ omObjData* obj[2]; /* the two players' objects */
    /* 0x08 */ s8 unk8;           /* both players' input flags (bit per member; 3 = both) */
    /* 0x09 */ u8 player[2];      /* player index of each member */
    /* 0x0B */ u8 unkB[2];        /* character of each member */
    /* 0x0E */ s16 unkE;          /* model */
    /* 0x10 */ s16 unk10;         /* model (copy) */
    /* 0x12 */ s16 unk12;         /* shadow model */
    /* 0x14 */ u16 unk14;         /* state */
    /* 0x16 */ u16 unk16;         /* obstacle ahead (func_80105464) */
    /* 0x18 */ s16 unk18;         /* set to 90/30 when a slam/stun ends (S4-1FA) */
    /* 0x1A */ s16 unk1A;         /* state timer (MP1 unk18) */
    /* 0x1C */ s16 unk1C;         /* pulls missed (MP1 unk1A) */
    /* 0x1E */ s16 unk1E;         /* (rand8() & 7) + 4 on each state change (MP1 unk1C) */
    /* 0x20 */ char unk20[4];
    /* 0x24 */ f32 unk24;         /* sled y, read by the goal camera (S4-1FA) */
    /* 0x28 */ f32 unk28;         /* sled z: the members' mean */
    /* 0x2C */ char unk2C[8];
    /* 0x34 */ f32 unk34;         /* speed factor */
    /* 0x38 */ char unk38[0x14];
} DDTeam; /* size = 0x4C */

/* omObjData::unk_50 of the players (C8E0.c's MgWork, 0x15C bytes; MP1 DDPlayerWork 0xE8). */
typedef struct DDWork {
    /* 0x00 */ char unk_00[0x57];
    /* 0x57 */ s8 unk_57;     /* controller port (MP1 0x56) */
    /* 0x58 */ char unk_58;
    /* 0x59 */ s8 unk_59;     /* player index (MP1 0x58) */
    /* 0x5A */ char unk_5A[0x76];
    /* 0xD0 */ u16 unk_D0;    /* motion (MP1 0xC0) */
    /* 0xD2 */ char unk_D2[0x8A];
} DDWork; /* size = 0x15C */

#define DD_WORK(obj) ((DDWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Data (.data, 1C6260.data.s, asm)
   --------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------
   Bss (ovl_1F_bss)
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_8010B048_1C6BC8_DungeonDash; /* the game-flow object */
extern omObjData* D_8010B04C_1C6BCC_DungeonDash; /* the view object */
extern s32 D_8010B058_1C6BD8_DungeonDash[4];
extern DDTeam D_8010B068_1C6BE8_DungeonDash[2];
extern s16 D_8010B100_1C6C80_DungeonDash;
extern s16 D_8010B102_1C6C82_DungeonDash; /* time left (frames) */
extern s32 D_8010B110_1C6C90_DungeonDash[4]; /* team * 2 + member slot of each player */
extern s32 D_8010B120_1C6CA0_DungeonDash;
extern s32 D_8010B124_1C6CA4_DungeonDash; /* _CheckFlag(0xC) */
extern s32 D_8010B130_1C6CB0_DungeonDash;
extern s32 D_8010B134_1C6CB4_DungeonDash;
extern s32 D_8010B138_1C6CB8_DungeonDash;
extern s8 D_8010B144_1C6CC4_DungeonDash;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_800FC7B0_FD3B0[];
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern s32 D_800F8FD0_F9BD0; /* scene state */
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_8000C018_CC18(u16);
void func_80018ED0_19AD0(s32);
void func_80018F58_19B58(s32);
void func_80079FF4_7ABF4(omObjData* obj); /* omOutViewMulti */
s32 func_8008F618_90218(void);
s16 func_80079798_7A398(s16 sfx, s16 player); /* play a sound effect for a player */
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion); /* C8E0.c: player motion */

/* ---------------------------------------------------------------------------------------------
   Overlay functions (those past 801061A0, MG1F-B's, inferred from the asm: check)
   --------------------------------------------------------------------------------------------- */
/* 1BE380.c */
void func_80102800_1BE380_DungeonDash(void);
void func_80102CF8_1BE878_DungeonDash(omObjData* obj);
void func_80102D94_1BE914_DungeonDash(omObjData* obj);
void func_801030CC_1BEC4C_DungeonDash(omObjData* obj);
void func_80103100_1BEC80_DungeonDash(omObjData* obj);
void func_80103134_1BECB4_DungeonDash(omObjData* obj);
void func_80103168_1BECE8_DungeonDash(omObjData* obj);
void func_8010319C_1BED1C_DungeonDash(omObjData* obj);
void func_801031D0_1BED50_DungeonDash(omObjData* obj, s32 player);
void func_80103354_1BEED4_DungeonDash(omObjData* obj, s32 player);
void func_801036B0_1BF230_DungeonDash(omObjData* obj);
s16 func_80104190_1BFD10_DungeonDash(s32 sfx, s16 player, s32 arg2);
void func_801041F0_1BFD70_DungeonDash(omObjData* obj);
u16 func_80105464_1C0FE4_DungeonDash(f32 z);
void func_80105618_1C1198_DungeonDash(omObjData* obj);
void func_80105E50_1C19D0_DungeonDash(omObjData* obj, s16* stkX, s16* stkY);
void func_801060DC_1C1C5C_DungeonDash(void);
void func_801060F8_1C1C78_DungeonDash(omObjData* obj, DDTeam* team);
DDTeam* func_80106118_1C1C98_DungeonDash(omObjData* obj);
void func_80106144_1C1CC4_DungeonDash(omObjData* obj, s32 motion, f32 speed);
s32 func_801061A0_1C1D20_DungeonDash(s32 team, s32 arg1);
void func_8010676C_1C22EC_DungeonDash(void);
s32 func_80106810_1C2390_DungeonDash(s32 team);
void func_801068E8_1C2468_DungeonDash(void);
void func_80106A28_1C25A8_DungeonDash(void);
void func_80106B6C_1C26EC_DungeonDash(Vec* pos, Vec* vel, f32 scale, s16 time);
void func_80106C3C_1C27BC_DungeonDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_80106D2C_1C28AC_DungeonDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz,
                                      u16 frames);
void func_80106E08_1C2988_DungeonDash(s32 cam);
void func_80106EC4_1C2A44_DungeonDash(s32 cam);
s32 func_80106F80_1C2B00_DungeonDash(omObjData* obj, s32 count);
/* 1C2D40.c */
void func_801071C0_1C2D40_DungeonDash(omObjData* obj);
void func_80107290_1C2E10_DungeonDash(void);
void func_80107358_1C2ED8_DungeonDash(s16 x);
s32 func_80107484_1C3004_DungeonDash(void);
s32 func_80107494_1C3014_DungeonDash(void);
void func_801074BC_1C303C_DungeonDash(void);
u16 func_801074F0_1C3070_DungeonDash(u16 range);
void func_80107560_1C30E0_DungeonDash(u8 seed);
struct DDObstacle;
void func_80107584_1C3104_DungeonDash(struct DDObstacle* o);
void func_801075A8_1C3128_DungeonDash(s16 arg0, f32 arg1);
u16 func_80107608_1C3188_DungeonDash(s32 file);
void func_8010764C_1C31CC_DungeonDash(void);
void func_801077C8_1C3348_DungeonDash(omObjData* obj);
void func_801078BC_1C343C_DungeonDash(omObjData* obj);
void func_80107C6C_1C37EC_DungeonDash(omObjData* obj);
void func_80108054_1C3BD4_DungeonDash(omObjData* obj);
s32 func_80108308_1C3E88_DungeonDash(u16 team, f32 z);
void func_801083B0_1C3F30_DungeonDash(u16 n);
void func_80108574_1C40F4_DungeonDash(void);
void func_80108A14_1C4594_DungeonDash(s32 team, f32 z);
void func_80108B54_1C46D4_DungeonDash(s16 mdl);
void func_80108BFC_1C477C_DungeonDash(s16 mdl);
void func_80108C8C_1C480C_DungeonDash(void);
void func_80108F9C_1C4B1C_DungeonDash(void);
void func_80109884_1C5404_DungeonDash(s32 team, f32 z);
s16 func_80109958_1C54D8_DungeonDash(Vtx_t* vtx, HuSprite_Unk84_Struct* spr, s32 type);
void func_8010A340_1C5EC0_DungeonDash(s16 model, HuSprite_Unk84_Struct* anim, s16 frame);
s32 func_8010A430_1C5FB0_DungeonDash(s32 model, s32 src);
s32 func_8010A4DC_1C605C_DungeonDash(s32 model, s32 src, HuSprite_Unk84_Struct* anim, s32 frame);

/* S4-1FB */
#include "game/data.h"
#include "game/sprite.h"
#include "game/hmfman.h"
f64 fabs(f64); /* GCC builtin (abs.d) */
/* A dust puff (D_8010B13C, 10 of them, func_80027154_27D54(0x168)). No pointers. */
typedef struct DDFx {
    /* 0x00 */ s16 unk0; /* active */
    /* 0x02 */ s16 unk2; /* sprite model */
    /* 0x04 */ s16 unk4; /* frames left */
    /* 0x06 */ s16 unk6; /* animation frame */
    /* 0x08 */ f32 unk8; /* scale */
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec vel;
} DDFx; /* size = 0x24 */

/* A swinging axe blade (D_8010B2E0, 2 of them, func_80027154_27D54(0x40)). No pointers. */
typedef struct DDBlock {
    /* 0x00 */ s16 unk0;  /* active */
    /* 0x02 */ s16 unk2;  /* 60 */
    /* 0x04 */ s16 unk4;  /* phase: 0 swing down, 1 rest, 2 swing back, 3 rest, 0xFF hidden */
    /* 0x06 */ s16 unk6;  /* blade model */
    /* 0x08 */ s16 unk8;  /* dust model */
    /* 0x0A */ s16 unkA;  /* glint model */
    /* 0x0C */ s16 unkC;  /* phase frames */
    /* 0x0E */ char unkE[2];
    /* 0x10 */ f32 unk10; /* swing angle */
    /* 0x14 */ f32 x;
    /* 0x18 */ f32 y;
    /* 0x1C */ f32 unk1C; /* z */
} DDBlock; /* size = 0x20 */

extern DDFx* D_8010B13C_1C6CBC_DungeonDash;
extern s32 D_8010B140_1C6CC0_DungeonDash; /* sprite animation; read as s16 (D_8010B142) */
extern DDBlock* D_8010B2E0_1C6E60_DungeonDash;
/* Camera tweening (80106C3C .. 80106F80), per screen (MP1 D_800FC3D8 ..). */
extern Vec3f D_8010B188_1C6D08_DungeonDash[4]; /* start CenterM */
extern Vec3f D_8010B1B8_1C6D38_DungeonDash[4]; /* target CenterM */
extern Vec3f D_8010B1E8_1C6D68_DungeonDash[4]; /* start CRotM */
extern Vec3f D_8010B218_1C6D98_DungeonDash[4]; /* target CRotM */
extern f32 D_8010B248_1C6DC8_DungeonDash[4];   /* start CZoomM */
extern f32 D_8010B258_1C6DD8_DungeonDash[4];   /* target CZoomM */
extern s16 D_8010B268_1C6DE8_DungeonDash[4];   /* frames left */
extern s16 D_8010B270_1C6DF0_DungeonDash[8];   /* frames total */

extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vtx_t D_8010A750_1C62D0_DungeonDash[10]; /* .data: sprite-model quads (4 used + 1, then 5 spare) */
extern Vtx_t D_8010A89C_1C641C_DungeonDash[10]; /* .data */
extern Vtx_t D_8010A93C_1C64BC_DungeonDash[10]; /* .data */
extern Vtx_t D_8010A7FC_1C637C_DungeonDash[10]; /* .data */
extern Vtx_t D_8010A9DC_1C655C_DungeonDash[10]; /* .data */
f32 func_800B7890_B8490(f32); /* cos */
extern u8 D_800FDBE0_FE7E0; /* the frame's buffer index */
s32 func_80027FA4_28BA4(u32 file, void* gfx, u8 arg2); /* model from a display list; s16 in 274D0.c */
void HuMemFree(void*);
void* HuMemAlloc(s32 size);
extern u8 D_800FDBCA_FE7CA; /* vertex buffer count */
extern Gfx D_8010AB70_1C66F0_DungeonDash[]; /* .data: the sprite models' shared setup list */
f64 func_800B0D98_B1998(f64, f64); /* fmod */
extern s16 D_800FA1AA_FADAA; /* main's heap tag */
extern f32 D_8010A7F4_1C6374_DungeonDash[2]; /* .data: obstacle x by parity {-280, 280} */
extern u8 D_80102720_103320; /* board.h */
u16 func_80078EA8_79AA8(void);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
s16 LoadFormFile(s32, s32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void* func_80027154_27D54(s32 size, s16 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
s16 SprAnimRead(void*);
void* SprAnimGet(s16 animIdx);

/* An obstacle on the course (D_8010B2E4, 5 of them, stride 0x24; MP1 DDObstacle 0x18). */
typedef struct DDObstacle {
    /* 0x00 */ s16 unk0;  /* active */
    /* 0x02 */ s16 unk2;  /* held up (cleared once the race runs) */
    /* 0x04 */ s16 unk4;  /* phase */
    /* 0x06 */ s16 unk6;  /* model */
    /* 0x08 */ s16 unk8;  /* shadow model */
    /* 0x0A */ s16 unkA;  /* dust model */
    /* 0x0C */ char unkC[8];
    /* 0x14 */ f32 unk14; /* phase timer (MP1 0x0C) */
    /* 0x18 */ f32 x;
    /* 0x1C */ f32 y;
    /* 0x20 */ f32 z;
} DDObstacle; /* size = 0x24 */

/* .data (1C2D40.c's part) */
extern u32 D_8010A7F0_1C6370_DungeonDash; /* random seed 0x19971204; 801074F0 reads its low half */
extern u32 D_8010ABB0_1C6730_DungeonDash; /* frames since start (to 80) */
extern u32 D_8010ABB4_1C6734_DungeonDash; /* race frames (to 120) */
extern s16 D_8010ABB8_1C6738_DungeonDash; /* 60 */
extern s16 D_8010ABBA_1C673A_DungeonDash; /* 20 */
extern s16 D_8010ABBC_1C673C_DungeonDash;
extern s16 D_8010ABBE_1C673E_DungeonDash;
extern f32 D_8010ABC0_1C6740_DungeonDash[2][2]; /* per team: [0] curtain alpha, [1] its step */
extern s32 D_8010ABD0_1C6750_DungeonDash;       /* frames both curtains are open */
/* .bss (1C2D40.c's part) */
extern omObjData* D_8010B288_1C6E08_DungeonDash[3]; /* the two track objects and the scenery object */
/* A wall torch (D_8010B29C, 6 of them, func_80027154_27D54(0x90)). No pointers. */
typedef struct DDTorch {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 unk2; /* animation phase 0..359 */
    /* 0x04 */ f32 unk4; /* y rotation */
    /* 0x08 */ f32 unk8; /* scale */
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
} DDTorch; /* size = 0x18 */
extern DDTorch* D_8010B29C_1C6E1C_DungeonDash;
extern s16 D_8010B280_1C6E00_DungeonDash; /* blade animation frame (0..15) */
extern s16 D_8010B2A0_1C6E20_DungeonDash; /* blade sprite animations */
extern s16 D_8010B2A2_1C6E22_DungeonDash;
extern s16 D_8010B2A4_1C6E24_DungeonDash;
extern s16 D_8010B2A6_1C6E26_DungeonDash;
extern s16 D_8010B2A8_1C6E28_DungeonDash;
extern s16 D_8010B2AA_1C6E2A_DungeonDash[4]; /* sprite animations (2F000E, 2F000A, 2F000F, 2F0010) */
extern s16 D_8010B2B2_1C6E32_DungeonDash[3]; /* per-team curtain sprite groups; [2] the start banner (D_8010B2B6) */
extern s16 D_8010B2BA_1C6E3A_DungeonDash; /* MP1 D_800FC650 */
extern s16 D_8010B2BC_1C6E3C_DungeonDash; /* MP1 D_800FC652 */
extern s16 D_8010B2BE_1C6E3E_DungeonDash; /* MP1 D_800FC654 */
extern f64 D_8010B2C0_1C6E40_DungeonDash[2]; /* each team's z */
extern s16 D_8010B2D0_1C6E50_DungeonDash;
extern s16 D_8010B2D2_1C6E52_DungeonDash;
extern DDObstacle* D_8010B2E4_1C6E64_DungeonDash;

extern HuSprite_Unk84_Struct* D_800F60B0_F6CB0[256]; /* sprite animations */
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
s32 PlaySound(s32);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80082488_83088(s16, s16, u16); /* sprite alpha */
f32 HuMathSin(f32);

/* S4-1FA */
#include "game/hmfman.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/sprite.h"
extern s32 D_8010B104_1C6C84_DungeonDash; /* sprite group; read as s16 (D_8010B106) */
extern s32 D_8010B108_1C6C88_DungeonDash; /* sprite group; read as s16 (D_8010B10A) */
extern s32 D_8010B128_1C6CA8_DungeonDash[2];
typedef struct DDCharData {
    /* 0x00 */ s16 unk_00; /* retail reads its low byte */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;
    /* 0x08 */ s32 model;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} DDCharData; /* size = 0x18 (main D_800CD438_CE038) */
extern DDCharData D_800CD438_CE038[];
s16 SprAnimRead(void*);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void SprAttrSet(s16 group, s16 member, s32 flag);
void func_800824B4_830B4(s16 group, s16 member, s32, s32, s32, s32);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
u16 func_80018A30_19630(s32 file, s32 attr);
s16 func_80027D3C_2893C(s16 linkMdlId);
u16 func_80018A64_19664(s32 file, s32 attr);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_80107350_1C2ED0_DungeonDash(void);

s16 LoadFormFile(s32, s32);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
extern s32 D_8010B148_1C6CC8_DungeonDash[4][4]; /* per player: [0] idle motion file, [1] win voice/motion file; D_8010B14C is [p][1] */

/* .data (1C6260.data.s), S4-1FA's */
extern s32 D_8010A6E0_1C6260_DungeonDash; /* game state (MP1 D_800FC000) */
extern s32 D_8010A700_1C6280_DungeonDash; /* state timer (MP1 D_800FC008) */
extern s32 D_8010A704_1C6284_DungeonDash; /* func_80106F80's result (MP1 D_800FC00C) */
extern s32 D_8010A708_1C6288_DungeonDash; /* the seconds counter is shown */
extern s32 D_8010A710_1C6290_DungeonDash; /* MP1 D_800FC014 */
extern s32 D_8010A714_1C6294_DungeonDash; /* time left (9000) */
extern s32 D_8010A718_1C6298_DungeonDash; /* START fade-out countdown; read as s16 (D_8010A71A) */
extern s32 D_8010A71C_1C629C_DungeonDash; /* the result message is up */
extern s32 D_8010B050_1C6BD0_DungeonDash; /* frame counter mod 3 (MP1 D_800FC300) */
extern u16 D_801011FC_101DFC;
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
s32 PlaySound(s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void InitFadeOut(s32, s32);
void func_800794A8_7A0A8(s32);
void func_80079614_7A214(s16 time); /* music fade-out */
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);

/* the goal camera's start pose (D_8010A720, .data) */
typedef struct DDCamPose {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 cx;
    /* 0x10 */ f32 cy;
    /* 0x14 */ f32 cz;
    /* 0x18 */ f32 rx;
    /* 0x1C */ f32 ry;
    /* 0x20 */ f32 rz;
} DDCamPose; /* size = 0x24 */
extern DDCamPose D_8010A720_1C62A0_DungeonDash;
extern s32 D_8010A6E4_1C6264_DungeonDash[6]; /* per character: func_80025384's last argument */
extern u8 D_8010A744_1C62C4_DungeonDash; /* bit per team at the goal (a .data word, read by byte) */
extern s32 D_8010B030_1C6BB0_DungeonDash[2]; /* team marker x offset, +-80 */
extern s32 D_8010B038_1C6BB8_DungeonDash[2]; /* the pull sound; read as s16 (+2) */
extern s32 D_8010B040_1C6BC0_DungeonDash[2]; /* the members' voices; read as s16 (D_8010B042, +6) */
void SprAttrReset(s16 group, s16 member, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank); /* u16 bank in main; retail passes an s16 */
void func_80079848_7A448(s16 id); /* stop a sound */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
omObjData* func_800732B0_73EB0(u32 arg0);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void SprPos3DSet(s16 group, s16 member, s16 camera, f32 x, f32 y, f32 z);
HuSprite* func_80082550_83150(s16 group, s16 member);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);

/* model data; the two sprite groups (s32 globals read by their low halves) */
#define DD_MDL(m) D_800FC834_FD434[m]
#define DD_SPR_A D_8010B106_1C6C86_DungeonDash
#define DD_SPR_B D_8010B10A_1C6C8A_DungeonDash
extern s16 D_8010B106_1C6C86_DungeonDash; /* low half of D_8010B104: retail 801041F0 reads it by this label */
extern s16 D_8010B10A_1C6C8A_DungeonDash; /* low half of D_8010B108 */
extern s16 D_8010B042_1C6BC2_DungeonDash; /* low half of D_8010B040[0]: read by this label */

f32 fabsf(f32);

u16 func_80018FF0_19BF0(omObjData* obj);
s32 func_80019000_19C00(omObjData* obj);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_800298A4_2A4A4(s16, s32, s32);
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_80019378_19F78(omObjData* obj);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */

extern s32 D_8010A748_1C62C8_DungeonDash; /* goal run-out: pulls done */
extern s32 D_8010A74C_1C62CC_DungeonDash; /* goal run-out: step */

#endif
