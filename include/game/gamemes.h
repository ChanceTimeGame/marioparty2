#ifndef _GAME_GAMEMES_H
#define _GAME_GAMEMES_H

#include "ultra64.h"

/* Game message windows (MP3 gamemes.c; 69950.c, overlay 3F). */

#define GMES_MAX 8
#define GMES_MES_TIMER 10
#define GMES_STAT_NONE 0

typedef struct {
    /* 0x00 */ u8 mesNo;
    /* 0x01 */ u8 stat;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18; /* second timer (func_800708AC_714AC) */
    /* 0x1C */ u8* unk1C; /* message (modes 8, 9) */
    /* 0x20 */ s16 strGId[16];
    /* 0x40 */ s16 strSprId[16];
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70; /* rotation */
} GAMEMES; // size 0x74

extern GAMEMES D_800F9570_FA170[GMES_MAX]; /* MP3 gMesData */

#endif
