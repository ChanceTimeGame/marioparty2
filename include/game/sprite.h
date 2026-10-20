#ifndef _GAME_SPRITE_H
#define _GAME_SPRITE_H

#include "ultra64.h"
#include "common_structs.h"

/* Sprite manager. MP2's sprite object has MP3's layout (include/game/sprite.h, MP3 field
   names) but is 0x208 bytes, and its group has MP1's layout (members at 0xC). */

typedef struct {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
} HuSprite_Unk84_Unk00_Struct; // size 0xC

typedef struct HuSprCelFrame {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
} HuSprCelFrame; // size 0x8

typedef struct HuSprCelAnm {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ HuSprCelFrame* unk04;
} HuSprCelAnm; // size 0x8

typedef struct {
    /* 0x00 */ HuSprite_Unk84_Unk00_Struct* unk00;
    /* 0x04 */ HuSprCelAnm** unk04;
    /* 0x08 */ void* unk08;
    /* 0x0C */ void* unk0C;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
} HuSprite_Unk84_Struct; // size 0x1C

typedef struct HuSprAnm {
    /* 0x00 */ HuSprite_Unk84_Struct* unk00;
    /* 0x04 */ u8 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
} HuSprAnm; // size 0x1C

typedef struct HuSprAnmEntry {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ struct HuSprAnmEntry** unk04;
} HuSprAnmEntry; // size 0x8

typedef struct HuSprAnmDesc {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ HuSprAnmEntry** unk04;
    /* 0x08 */ u16 unk08;
    /* 0x0C */ void* unk0C;
} HuSprAnmDesc; // size 0x10

typedef struct HuSprite {
    /* 0x000 */ s16 unk_00;
    /* 0x002 */ s16 unk_02;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s16 unk_0C;
    /* 0x00E */ s16 unk_0E;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ u16 prio;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ f32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ u8 unk_28[4];
    /* 0x02C */ u16 unk_2C;
    /* 0x02E */ s16 unk_2E;
    /* 0x030 */ f32 unk_30;
    /* 0x034 */ f32 unk_34;
    /* 0x038 */ s16 unk_38;
    /* 0x03A */ s16 unk_3A;
    /* 0x03C */ s16 unk_3C;
    /* 0x03E */ s16 unk_3E;
    /* 0x040 */ u16 unk_40;
    /* 0x042 */ u16 unk_42;
    /* 0x044 */ s32 unk_44;
    /* 0x048 */ f32 unk_48;
    /* 0x04C */ f32 unk_4C;
    /* 0x050 */ f32 unk_50;
    /* 0x054 */ f32 unk_54;
    /* 0x058 */ f32 unk_58;
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ f32 unk_60;
    /* 0x064 */ f32 unk_64;
    /* 0x068 */ HuSprAnm unk_68;
    /* 0x084 */ HuSprite_Unk84_Struct* unk_84;
    /* 0x088 */ u8 unk_88;
    /* 0x08A */ s16 unk_8A;
    /* 0x08C */ f32 unk_8C;
    /* 0x090 */ s16 unk_90;
    /* 0x092 */ s8 unk_92;
    /* 0x093 */ u8 unk_93;
    /* 0x094 */ u8 unk_94;
    /* 0x098 */ HuSprAnmDesc* unk_98;
    /* 0x09C */ u16 unk_9C[0x10];
    /* 0x0BC */ s32 unk_BC[0x10];
    /* 0x0FC */ f32 unk_FC;
    /* 0x100 */ s16 unk_100;
    /* 0x104 */ s32 unk_104;
    /* 0x108 */ void* unk_108[3];
    /* 0x114 */ s16 unk_114; // next sibling in the group's tree
    /* 0x116 */ s16 unk_116; // first child
    /* 0x118 */ struct HuSprite* unk_118; // next in the priority-sorted draw list
    /* 0x11C */ struct HuSprite* unk_11C; // previous in the draw list
    /* 0x120 */ void* unk_120;
    /* 0x124 */ void* unk_124;
    /* 0x128 */ void* unk_128[3];
    /* 0x134 */ void* unk_134[3];
    /* 0x140 */ Mtx unk_140[3];
    /* 0x200 */ s32 unk_200; /* unk_24 as of the last func_80083748_84348 */
    /* 0x204 */ char unk_204[4];
} HuSprite; // size 0x208

typedef struct HuSprGrp {
    /* 0x00 */ struct HuSprGrp* prev; /* MP1 order; MP3 names 0x00 next */
    /* 0x04 */ struct HuSprGrp* next;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 count;
    /* 0x0C */ HuSprite* members[1]; /* unknown size; MP3 has them at 0x10 */
} HuSprGrp;

/* Sprite-model slot (21920; MP1 src/1EA70.c). */
typedef struct unk_800ECDE0 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ s8 unk16;
    /* 0x17 */ s8 unk17;
    /* 0x18 */ s8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u32 unk20; /* key-frame list */
} unk_800ECDE0; /* size = 0x24 */

extern unk_800ECDE0* D_800F86D8_F92D8;

extern HuSprGrp* HuSprGrpData[256]; /* MP1 D_800EE330 */

#endif
