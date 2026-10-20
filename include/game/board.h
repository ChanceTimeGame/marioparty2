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

#endif
