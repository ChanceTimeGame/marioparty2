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

/* Saved to EEPROM at 0x1BC (7E850); read by the final-minigame overlay (ovl_6D). */
typedef struct Unk_800FD8A8 {
    /* 0x00 */ u8 unk00; /* player 1 character */
    /* 0x01 */ u8 unk01; /* player 2 character */
    /* 0x02 */ char unk02[2];
    /* 0x04 */ s8 unk04;
    /* 0x05 */ char unk05[0xD];
} Unk_800FD8A8; /* size = 0x12 */

extern Unk_800FD8A8 D_800FD8A8_FE4A8;

#endif
