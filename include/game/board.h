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
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ u8 unk_38[12];
    /* 0x44 */ s16 unk_44[2];
} BoardStatus;

extern u8 D_800F851A_F911A;  /* board window/marker busy flag (426A0, 4D660, 565E0) */
extern u8 D_80102720_103320; /* cleared by objmain, tested by 4D660 */

#endif
