#ifndef _GAME_BOARD_H
#define _GAME_BOARD_H

#include "ultra64.h"
#include "common_structs.h"

/* Board model: MP1's Object view of a board model (MP1 include/object.h). */
typedef struct MBModel {
    /* 0x00 */ struct MBModel* next;
    /* 0x04 */ struct MBModel* prev;
    /* 0x08 */ u8 id;
    /* 0x0A */ u16 attr;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec rot;
    /* 0x24 */ Vec scale;
    /* 0x30 */ f32 jumpY;
    /* 0x34 */ f32 jumpVel;
    /* 0x38 */ f32 jumpAccel;
    /* 0x3C */ omObjData* obj;
    /* 0x40 */ omObjData* shadow;
    /* 0x44 */ s16 baseMot;
    /* 0x46 */ s16 curMot;
} MBModel; /* size = 0x48 */

/* Board HUD icon set (MP1 unk_Struct02; 426A0, 67FA0). */
typedef struct unk_Struct02 {
    /* 0x00 */ void* unk00;
    /* 0x04 */ void* unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16* unk0C;
} unk_Struct02; /* size = 0x10 */

/* Board guide (the host character shown in board scenes): MP3 UnkMBGuideData
   (include/game/board.h; MBGuideCreate/MBGuideKill there are func_80050304_50F04 and
   func_8005057C_5117C here). */
typedef struct UnkMBGuideData {
    /* 0x00 */ MBModel* obj;
    /* 0x04 */ struct Process* unk_04;
    /* 0x08 */ s16 amount; /* the guide's text window */
    /* 0x0A */ s16 spriteGroup;
} UnkMBGuideData; /* size = 0xC */

/* A board's space events: 54CB0.c's EventTableEntry (space -> event list, ended by space -1) and
   MbEventListEntry (ended by activation_type 0). Same layout, board-overlay names. */
typedef struct BoardEventListEntry {
    /* 0x00 */ s16 activation_type;
    /* 0x02 */ s16 execution_type;
    /* 0x04 */ void (*event_fn)();
} BoardEventListEntry; /* size = 0x8 */

typedef struct BoardEventTableEntry {
    /* 0x00 */ s16 spaceIndex;
    /* 0x04 */ BoardEventListEntry* eventList;
} BoardEventTableEntry; /* size = 0x8 */

/* Board status window per player (MP3 MBStatus work; 5F3B0.c, overlay 3F). */
typedef struct BoardStatus {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ u8 unk2[2];
    /* 0x04 */ u8 spaceType; /* MP3 spaceType */
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char pad7[1];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char padA[2];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char padE[2];
    /* 0x10 */ f32 xPos;
    /* 0x14 */ f32 yPos;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ omObjData* unk30;
    /* 0x34 */ char pad34[2];
    /* 0x36 */ s16 unk_36; /* item sprite animation; MBStatusItemDispSet clears it and unk_38 as a pair */
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A; /* digit sprite animation (MP3 unk_3A) */
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ char pad3E[4];
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44[2];
} BoardStatus;

/* Battle/duel participants as bit masks (63670.c, overlay 3F). */
typedef struct BattleTargets {
    /* 0x00 */ s16 targets;  /* bit per player: who can be challenged */
    /* 0x02 */ s16 attacker; /* bit of the challenger */
} BattleTargets;

extern u8 D_800F851A_F911A;  /* board window/marker busy flag (426A0, 4D660, 565E0) */
extern u8 D_80102720_103320; /* cleared by objmain, tested by 4D660 */

/* 41-A: board types boards 3E and 41 share (moved from ovl_3E.h; names kept) */

typedef struct Unk4Bytes {
    u8 b[4];
} Unk4Bytes;

typedef struct Vec2f3E {
    f32 x;
    f32 y;
} Vec2f3E;

/* fork C */
typedef struct Unk3EParticle {
    /* 0x00 */ Vec vel;
    /* 0x0C */ f32 alpha;
    /* 0x10 */ f32 scaleSpeed;
    /* 0x14 */ f32 fadeSpeed;
    /* 0x18 */ MBModel* model;
    /* 0x1C */ u16 kill; /* delete when faded out, else only pause */
    /* 0x1E */ char unk_1E[2];
} Unk3EParticle; /* size 0x20 (MP3 UnkChillyWaters) */

typedef struct Unk3ERange {
    u8 min;
    u8 max;
    u8 value;
} Unk3ERange; /* size 3 */

typedef struct Unk3EStealRange {
    u8 turnMin;
    u8 turnMax;
    u8 min;
    u8 max;
    u8 mess; /* index into D_8011243E */
} Unk3EStealRange; /* size 5 */

typedef struct Unk3EWindowSlide {
    /* 0x00 */ s16 x0;
    /* 0x02 */ s16 y0;
    /* 0x04 */ s16 x1;
    /* 0x06 */ s16 y1;
    /* 0x08 */ s16 frames;
    /* 0x0A */ s16 sprite; /* -1: none */
    /* 0x0C */ char unk_0C[4];
} Unk3EWindowSlide; /* size 0x10 */

/* RunDecisionTree's node (MP1 common_structs.h) */
typedef struct DecisionTreeNonLeafNode {
    u32 type;
    union {
        void (*func)();
        s32 data;
    } node_data1;
    union {
        s32 data;
        s32* node_data;
    } node_data2;
} DecisionTreeNonLeafNode;

typedef struct Unk3Halves {
    s16 v[3];
} Unk3Halves;
typedef Vec2f3E Unk3EVec2f; /* 3E fork C name for Vec2f3E */

#endif
