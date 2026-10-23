#ifndef _GAME_COLLISION_H
#define _GAME_COLLISION_H

#include "ultra64.h"
#include "common_structs.h"
#include "game/object.h"
#include "game/hmfman.h" /* ColVtx, HmfModel, HmfData */

/* Collision and minigame actor physics (src/1130.c; MP1 src/1130.c, MP3's minigame overlay).
   Layouts are MP1's, checked against MP2's offsets. */

/* A collision face of a model's HmfData.unk54 vertex list: flags (bits 14-15: vertex count - 2,
   bits 8-13: surface type), then 3 or more vertex indices. */
typedef struct ColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} ColTri;

typedef struct Vec4f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
    /* 0xC */ f32 w; /* radius */
} Vec4f;

/* Collision probe: a sphere plus a second (previous?) position. */
typedef struct ColSphere {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
    /* 0x10 */ f32 x2;
    /* 0x14 */ f32 y2;
    /* 0x18 */ f32 z2;
} ColSphere;

/* omObjData::unk_50 of a ground / platform object in D_800FC7B0_FD3B0 (MP1 D_800F2AF8). */
typedef struct GroundWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02;
    /* 0x03 */ u8 unk_03;  /* 2: landing on it calls func_80009744_A344 */
    /* 0x04 */ u8 unk_04;  /* surface id copied to MgWork.unk_56 */
    /* 0x05 */ char unk_05;
    /* 0x06 */ u16 unk_06; /* flags: 2 skip, 4 test the part list, 8/0x10/0x20/0x40 primitive
                              shapes, 0x50 needs func_8000DC10_E810, 0x400 tilts the rider */
    /* 0x08 */ f32 unk_08; /* friction (0: the default D_800BF7A0_C03A0) */
    /* 0x0C */ f32 unk_0C; /* run acceleration divisor (0: the default D_800BF79C_C039C) */
    /* 0x10 */ f32 unk_10; /* conveyor factor applied to the floor normal */
    /* 0x14 */ f32 unk_14; /* top surface height */
    /* 0x18 */ char unk_18[0x80];
    /* 0x98 */ f32 unk_98; /* subtracted from unk_14 for a player's ceiling test */
    /* 0x9C */ f32 unk_9C; /* cylinder radius (shapes 0x20, 0x40) */
    /* 0xA0 */ f32 unk_A0; /* box min x (shapes 8, 0x10) */
    /* 0xA4 */ f32 unk_A4; /* box min z */
    /* 0xA8 */ f32 unk_A8; /* box max x */
    /* 0xAC */ f32 unk_AC; /* box max z */
} GroundWork; /* size unknown */

/* omObjData::unk_50 of a minigame item actor (coins and the like), 0xAC bytes, allocated by
   func_80001DE0_29E0. unk_84[] are per-actor hooks; a hook returning 1 skips the default step.
   Their arguments differ by slot (the object, or the toucher and the actor). */
typedef struct ColActorWork {
    /* 0x00 */ u8 unk_00[0x20]; /* per ground object flags: 1 ignore it, 8 hazard */
    /* 0x20 */ char unk_20[4];
    /* 0x24 */ u8 unk_24;       /* sprite / effect slot */
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;      /* height */
    /* 0x38 */ f32 unk_38;      /* vertical speed; 1000.0f on the ground */
    /* 0x3C */ f32 unk_3C;      /* heading (degrees) */
    /* 0x40 */ f32 unk_40;      /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;      /* radius */
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;      /* flags */
    /* 0x52 */ u8 unk_52;       /* kind (3-6: coin values) */
    /* 0x53 */ s8 unk_53;       /* ground object index, -1 none */
    /* 0x54 */ u8 unk_54;       /* active */
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;      /* ground velocity scale */
    /* 0x5C */ f32 unk_5C;      /* ground velocity */
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;      /* tilt x */
    /* 0x6C */ char unk_6C[4];
    /* 0x70 */ f32 unk_70;      /* tilt z */
    /* 0x74 */ char unk_74[4];
    /* 0x78 */ s32 unk_78;      /* age (frames) */
    /* 0x7C */ s32 unk_7C;      /* lifetime (frames) */
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 (*unk_84[9])();
    /* 0xA8 */ void* unk_A8;
} ColActorWork; /* size = 0xAC */

/* omObjData::unk_50 of a minigame player (C8E0.c's MgWork, 0x15C bytes; MP1 PlayerWork 0xE8).
   C8E0.c and B6E0.c still declare their own copies; this one adds 1130.c's fields. */
typedef struct MgWork {
    /* 0x00 */ u8 unk_00[0x20]; /* per ground object flags: 1 ignore it, 8 hazard */
    /* 0x20 */ char unk_20[0x14];
    /* 0x34 */ f32 unk_34;  /* height */
    /* 0x38 */ f32 unk_38;  /* vertical speed; 1000.0f on the ground */
    /* 0x3C */ f32 unk_3C;  /* heading */
    /* 0x40 */ f32 unk_40;  /* speed */
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48;  /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;  /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;   /* ground object index, -1 none */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ u8 unk_56;   /* surface id of the ceiling (GroundWork.unk_04) */
    /* 0x57 */ s8 unk_57;   /* controller port (MP1 0x56) */
    /* 0x58 */ u8 unk_58;   /* stick sample index (MP1 0x57) */
    /* 0x59 */ s8 unk_59;   /* player (MP1 0x58) */
    /* 0x5A */ char unk_5A[2];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;  /* attack reach (func_800098D0_A4D0) */
    /* 0x68 */ char unk_68[0xC];
    /* 0x74 */ s32 unk_74[6]; /* packed (x << 16) | (y & 0xFFFF) stick samples (MP1 0x6C) */
    /* 0x8C */ f32 unk_8C;  /* ceiling height, 65536.0f none */
    /* 0x90 */ f32 unk_90;  /* ground velocity (MP1 0x84) */
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[4];
    /* 0xAC */ f32 unk_AC;
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ f32 unk_B4;  /* speed factor */
    /* 0xB8 */ char unk_B8[4];
    /* 0xBC */ u16 unk_BC;  /* frames running, at most 200 (MP1 0xAC) */
    /* 0xBE */ u16 unk_BE;  /* 105 after a hazard actor hit, counting down; while set, touches only count D_800FD7FC_FE3FC */
    /* 0xC0 */ u16 unk_C0;  /* spin countdown (flags 0x100000) */
    /* 0xC2 */ char unk_C2;
    /* 0xC3 */ s8 unk_C3;
    /* 0xC4 */ s8 unk_C4;   /* MP1 0xB2 */
    /* 0xC5 */ s8 unk_C5;   /* MP1 0xB3 */
    /* 0xC6 */ s16 unk_C6;  /* turn lean, -12..12 (MP1 0xB4) */
    /* 0xC8 */ char unk_C8[4];
    /* 0xCC */ f32 unk_CC;
    /* 0xD0 */ u16 unk_D0;
    /* 0xD2 */ char unk_D2[0x16];
    /* 0xE8 */ void* unk_E8; /* C8E0.c's MgMotion* */
    /* 0xEC */ s32 (*unk_EC)(omObjData* obj, omObjData* actor); /* actor touch hook; 1 skips the default */
    /* 0xF0 */ u16 unk_F0;
    /* 0xF2 */ char unk_F2[0x12];
    /* 0x104 */ s32 unk_104[21];
    /* 0x158 */ char unk_158[4];
} MgWork; /* size = 0x15C */

extern omObjData* D_800FC7B0_FD3B0[]; /* ground objects (MP1 D_800F2AF8) */
extern u16 D_800F8FE0_F9BE0;          /* their count */
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern u16 D_800FC87A_FD47A;           /* their count */
extern f32 D_800F94A0_FA0A0;           /* push x this frame (MP1 D_800ED6B8) */
extern f32 D_80101308_101F08;          /* push z this frame (MP1 D_800F5254) */
extern s32 D_800F9D30_FA930[];         /* face query state (func_8002F2C4_2FEC4) */
extern f32 D_800FC838_FD438[4][4];          /* ground object: local to world (func_8000D434_E034 builds both) */
extern f32 D_800F94C8_FA0C8[4][4];          /* ground object: world to local */

void func_8002DA3C_2E63C(ColVtx* a, ColVtx* b, ColVtx* c, Vec3f* n); /* face normal (MP1 func_800295FC) */
void func_8002D9AC_2E5AC(Vec3f* v);                                 /* normalise (MP1 func_8002956C) */
f32 func_8002DB3C_2E73C(f32 x, f32 z, ColVtx* a, ColVtx* b);         /* MP1 func_800296FC */
f32 func_8002DBA4_2E7A4(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri); /* face height (MP1 func_80029764) */
void func_8002F2C4_2FEC4(s16 mdl, s32* query, void* filter, void* arg); /* MP1 func_8002AE24 */
ColTri* func_8002F848_30448(s32* query);                            /* next face (MP1 func_8002B3A8) */

#endif
