#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include "ultra64.h"

/* Text windows (src/84FF0.c; MP1 src/6D4E0.c, MP3 src/window.c). MP2's TextWindow is 0x27C bytes
   like MP1's and MP3's, with its own layout. Fields are named where 84FF0's code makes the use
   certain. */

/* a choice entry or a placed sprite (MP1 SubTextWindow) */
typedef struct TWEntry {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
} TWEntry; // size 0x10 (MP1 SubTextWindow)

typedef struct TextWindow {
    /* 0x000 */ u16 unk_00[0x10]; /* palette (RGBA5551), copied from D_800CD874_CE474 */
    /* 0x020 */ u8 unk20;
    /* 0x021 */ u8 unk21; /* controller ports that drive the window */
    /* 0x022 */ u8 unk22; /* text colour */
    /* 0x023 */ s8 unk23;
    /* 0x024 */ u8 unk24; /* current unkE0 buffer */
    /* 0x025 */ u8 unk25;
    /* 0x026 */ u8 unk26;
    /* 0x027 */ u8 unk27;
    /* 0x028 */ u8 unk28;
    /* 0x029 */ u8 unk29;
    /* 0x02A */ u8 unk2A; /* line spacing */
    /* 0x02B */ char pad2B[2];
    /* 0x02D */ u8 unk_2D;
    /* 0x02E */ u8 unk_2E;
    /* 0x02F */ u8 unk_2F;
    /* 0x030 */ s8 unk_30;
    /* 0x031 */ s8 unk_31;
    /* 0x032 */ s8 unk32;
    /* 0x033 */ s8 unk33;
    /* 0x034 */ u8 unk34; /* character spacing */
    /* 0x035 */ u8 unk35; /* tab width */
    /* 0x036 */ char pad36[2];
    /* 0x038 */ u32 unk_38;
    /* 0x03C */ u16 unk3C; /* x */
    /* 0x03E */ u16 unk3E; /* y */
    /* 0x040 */ s16 unk40; /* width */
    /* 0x042 */ s16 unk42; /* height */
    /* 0x044 */ s16 unk44;
    /* 0x046 */ s16 unk46;
    /* 0x048 */ s16 unk48;
    /* 0x04A */ s16 unk4A;
    /* 0x04C */ s16 unk4C;
    /* 0x04E */ s16 unk4E;
    /* 0x050 */ s16 unk50;
    /* 0x052 */ s16 unk52;
    /* 0x054 */ s16 unk54;
    /* 0x056 */ s16 unk56;
    /* 0x058 */ s16 unk58;
    /* 0x05A */ s16 unk5A;
    /* 0x05C */ s16 unk5C;
    /* 0x05E */ s16 unk5E; /* -1 = free */
    /* 0x060 */ u16 unk60; /* sprite priority */
    /* 0x062 */ s16 unk62; /* previous window in the list */
    /* 0x064 */ s16 unk64; /* next window in the list */
    /* 0x066 */ s16 unk66;
    /* 0x068 */ s16 unk68;
    /* 0x06A */ s16 unk6A;
    /* 0x06C */ s16 unk_6C; /* sprite group */
    /* 0x06E */ s16 unk_6E[0x16];
    /* 0x09A */ s16 unk9A;
    /* 0x09C */ s16 unk9C;
    /* 0x09E */ s16 unk9E;
    /* 0x0A0 */ s16 unkA0;
    /* 0x0A2 */ s16 unkA2;
    /* 0x0A4 */ s16 unkA4;
    /* 0x0A6 */ u16 unkA6; /* buttons that also close the window */
    /* 0x0A8 */ u16 unkA8; /* buttons that closed it */
    /* 0x0AA */ s16 unkAA;
    /* 0x0AC */ s8 unkAC;
    /* 0x0AD */ s8 usingStringIDBool[5];
    /* 0x0B2 */ s8 unk_B2[6];
    /* 0x0B8 */ void* unk_B8[5];
    /* 0x0CC */ u8* unkCC; /* text being shown */
    /* 0x0D0 */ void* unkD0; /* text read from the message file, or NULL */
    /* 0x0D4 */ u8 unkD4; /* unkD0 must be freed */
    /* 0x0D5 */ char padD5[3];
    /* 0x0D8 */ u8* unkD8; /* where the text resumes after an inserted string */
    /* 0x0DC */ u8* unkDC; /* window image (4-bit) */
    /* 0x0E0 */ u8* unkE0[3]; /* triple-buffered text image (4-bit) */
    /* 0x0EC */ f32 unkEC;
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ TWEntry unk_F4[0x18];
    /* 0x274 */ s16 unk274;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ char pad278[4];
} TextWindow; // size 0x27C

extern TextWindow* D_800F920C_F9E0C; /* the 14 windows; [0] and [1] are the open list's ends */

#endif
