#ifndef _GAME_GAMEWORK_H
#define _GAME_GAMEWORK_H

#include "ultra64.h"

/* MP2's common game work (MP1 GwCommon, MP3 GW_COMMON in include/game/gamework_data.h);
   saved to EEPROM whole (692F0, 7E850). */
typedef struct GW_COMMON {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ u16 mgRecord[13];
    /* 0x1C */ u8 mgBits1[9]; /* MP1 mgBuy */
    /* 0x25 */ u8 mgBits2[9]; /* MP1 mgBuy, MP3 mgUnlock */
    /* 0x2E */ char unk2E[0x48];
    /* 0x76 */ s8 unk76;
    /* 0x77 */ char unk77[0x4D];
} GW_COMMON; /* size = 0xC4 */

extern GW_COMMON D_800F8C60; /* GwCommon */

#endif
