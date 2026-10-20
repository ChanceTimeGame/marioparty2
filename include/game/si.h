#ifndef _GAME_SI_H
#define _GAME_SI_H

#include "ultra64.h"

/* Serial-interface (controller/EEPROM) request thread (84FF0, 7E850, 169B0). */
typedef s32 (*HuSiFunc)(void*);
typedef s32 (*HuSiFuncVoid)(void);

typedef struct functionListEntryt {
    /* 0x00 */ struct functionListEntryt* child;
    /* 0x04 */ HuSiFuncVoid func;
    /* 0x08 */ s16 type;
} functionListEntry; /* size = 0xC */

typedef struct unkMesg {
    /* 0x00 */ HuSiFunc func;
    /* 0x04 */ void* arg;
    /* 0x08 */ s32 ret;
    /* 0x0C */ OSMesgQueue* recvQueue;
} unkMesg; /* size = 0x10 */

#endif
