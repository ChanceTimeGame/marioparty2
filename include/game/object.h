#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "ultra64.h"
#include "common_structs.h"

/* MP1's Object (board/scene object list). Names follow MP3's include/game/object.h
   up to 0x44; MP2 continues past MP3's size (0x48) to 0x90 (4A500). */
typedef struct Object {
    /* 0x00 */ struct Object* prev;
    /* 0x04 */ struct Object* next;
    /* 0x08 */ s16 unk08; /* MP3: u8 unk8, s8 unk9 */
    /* 0x0A */ u16 flags;
    /* 0x0C */ Vec coords;
    /* 0x18 */ Vec rot;
    /* 0x24 */ Vec scale;
    /* 0x30 */ Vec velocity;
    /* 0x3C */ omObjData* omObj1;
    /* 0x40 */ omObjData* omObj2;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ char unk50[3];
    /* 0x53 */ s8 unk53;
    /* 0x54 */ char unk54[0x38];
    /* 0x8C */ struct Object* unk8C;
} Object; /* size = 0x90 */

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

/* Model emitter process work (func_80049ED4_4AAD4 in 4A500, used by 46250). */
typedef struct ModelEmitterWork {
    /* 0x00 */ struct Process* process;
    /* 0x04 */ Object* model;
    /* 0x08 */ Object* parent;
    /* 0x0C */ Vec3f offset;
    /* 0x18 */ f32 unk18; /* scale */
    /* 0x1C */ s16 type;
    /* 0x1E */ s16 flags;
} ModelEmitterWork; /* size = 0x20 */

#endif
