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

extern u8 D_800F851A_F911A;  /* board window/marker busy flag (426A0, 4D660, 565E0) */
extern u8 D_80102720_103320; /* cleared by objmain, tested by 4D660 */

#endif
