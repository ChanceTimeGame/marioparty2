#ifndef _OVL_1F_H
#define _OVL_1F_H

/* Overlay 1F: Dungeon Dash (2 vs 2), descended from MP1's ovl_27_DesertDash (1D3990.c, 1D6E30.c,
   DesertDash.h). Each team pulls one shared sled down a corridor, one team per half of the screen
   (cameras 0 and 1); blocks rise and slam down on the course. Two retail files: 1BE380.c and
   1C2D40.c (from 801071C0). .data stays asm (1C6260.data.s); .rodata is carved per file
   ([0x1C6760, .rodata, 1BE380], [0x1C6A40, .rodata, 1C2D40]). */

#include "common.h"
#include "game/object.h"

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
    /* 0x18 */ s16 unk18;         /* state timer */
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ char unk1E[0xA];
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
s32 func_801061A0_1C1D20_DungeonDash(s16 arg0, s32 arg1);
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
void func_80107358_1C2ED8_DungeonDash(s16 arg0);
s32 func_80107484_1C3004_DungeonDash(void);
s32 func_80107494_1C3014_DungeonDash(void);
void func_801074BC_1C303C_DungeonDash(void);
u16 func_801074F0_1C3070_DungeonDash(u16 range);
void func_80107560_1C30E0_DungeonDash(u8 seed);
void func_80107584_1C3104_DungeonDash(void* arg0);
void func_801075A8_1C3128_DungeonDash(s16 arg0, f32 arg1);
u16 func_80107608_1C3188_DungeonDash(s32 file);
void func_8010764C_1C31CC_DungeonDash(void);
void func_801077C8_1C3348_DungeonDash(omObjData* obj);
void func_801078BC_1C343C_DungeonDash(omObjData* obj);
void func_80107C6C_1C37EC_DungeonDash(omObjData* obj);
void func_80108054_1C3BD4_DungeonDash(omObjData* obj);
s32 func_80108308_1C3E88_DungeonDash(s32 arg0, f32 arg1);
void func_801083B0_1C3F30_DungeonDash(s32 arg0);
void func_80108574_1C40F4_DungeonDash(void);
void func_80108A14_1C4594_DungeonDash(s32 arg0, f32 arg1);
void func_80108B54_1C46D4_DungeonDash(s16 mdl);
void func_80108BFC_1C477C_DungeonDash(s16 arg0);
void func_80108C8C_1C480C_DungeonDash(void);
void func_80108F9C_1C4B1C_DungeonDash(void);
void func_80109884_1C5404_DungeonDash(s32 arg0, f32 arg1);
s16 func_80109958_1C54D8_DungeonDash(void* arg0, void* arg1, s32 arg2);
void func_8010A340_1C5EC0_DungeonDash(s16 arg0, s32* arg1, s16 arg2);
s32 func_8010A430_1C5FB0_DungeonDash(s32 arg0, s32 arg1);
s32 func_8010A4DC_1C605C_DungeonDash(s32 arg0, s32 arg1, s32* arg2, s32 arg3);

/* S4-1FB */
#include "game/data.h"
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

/* A falling block (D_8010B2E0, stride 0x20). */
typedef struct DDBlock {
    /* 0x00 */ char unk0[0x10];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ char unk14[8];
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
extern s16 D_8010A750_1C62D0_DungeonDash[]; /* .data */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void* func_80027154_27D54(s32 size, s16 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
s16 SprAnimRead(void*);
void* SprAnimGet(s16 animIdx);

#endif
