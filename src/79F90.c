#include "common.h"
#include "game/pad.h"

/* Audio and controller-copy wrappers (MP3 src/audio.c, MP1 src/objmain.c, src/388E0.c). The
   references' names are anonymous, so MP2's are kept. */

typedef struct UnkAudStruct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ char unk0C[0x24];
} UnkAudStruct; // size 0x30

extern s16 D_800CD524_CE124;
extern u16 D_800CD526_CE126;
extern s16 D_800FA188_FAD88;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s8 D_801026F8_1032F8[4];
extern s8 D_800FD3E4_FDFE4[4];
extern u16 D_800F92D4_F9ED4[4];
extern u16 D_800FA19C_FAD9C[4];
extern u16 D_800F851C_F911C[4];
extern u16 D_800FD410_FE010[4];

void func_80011128_11D28(s16);
void func_80011354_11F54(s8);
void func_80015664_16264(s16, s16);
s32 func_80014B30_15730(s16, UnkAudStruct*);
void func_80015710_16310(s16, s16);
void func_80015868_16468(s16);

void func_800155B8_161B8(s16, s8);
s32 func_80011018_11C18(s16);
void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
extern u16 D_800CD522_CE122;
extern s16 D_800E2140_E2D40[6];

INCLUDE_ASM("asm/nonmatchings/79F90", PlayMusic);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079428_7A028);

void func_80079464_7A064(void) {
    D_800CD524_CE124 = -1;
    func_80011128_11D28(D_800FA188_FAD88);
    D_800CD526_CE126 &= ~(2 | 8);
    D_800CD526_CE126 |= 1;
}

void func_800794A8_7A0A8(s32 speed) {
    D_800CD524_CE124 = -1;
    func_800114E8_120E8(D_800FA188_FAD88, (s16)speed);
    D_800CD526_CE126 |= 8;
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_800794F0_7A0F0);

void func_80079518_7A118(s8 arg0) {
    func_80011354_11F54(arg0);
    D_800CD526_CE126 &= ~8;
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_8007954C_7A14C);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079574_7A174);

INCLUDE_ASM("asm/nonmatchings/79F90", PlaySound);

void func_800795D8_7A1D8(s16 index, s8 val) {
    D_800FA660_FB260[index] = val;
    func_800155B8_161B8(index, val);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079614_7A214);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079684_7A284);

void func_800796F0_7A2F0(s16 arg0, s16 arg1) {
    func_80015664_16264(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079718_7A318);

s32 func_8007975C_7A35C(s16 arg0, s16 arg1) {
    UnkAudStruct sp10;

    sp10.unk00 = 0x200;
    sp10.unk08 = arg1 + 1;
    return func_80014B30_15730(arg0, &sp10);
}

s16 func_80079798_7A398(s16 arg0, s16 arg1) {
    if (D_800CD522_CE122 == 0) {
        return 0;
    }
    return func_8007975C_7A35C(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_800797DC_7A3DC);

void func_80079848_7A448(s16 arg0) {
    func_80015868_16468(arg0);
}

void func_80079868_7A468(void) {
    func_80015868_16468(-1);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079884_7A484);

void func_800798D4_7A4D4(s16 arg0) {
    func_80015710_16310(-1, arg0);
}

void func_800798F8_7A4F8(s16 arg0, s16 arg1) {
    func_80015710_16310(arg0, arg1);
}

void func_80079920_7A520(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_800E2140_E2D40[i] = -1;
    }
    switch (func_80011018_11C18(D_800FA188_FAD88)) {
    case 0:
        D_800CD526_CE126 = (D_800CD526_CE126 | 1) & ~0xA;
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_800799A4_7A5A4);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079A70_7A670);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079B88_7A788);

void func_80079C60_7A860(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_801026F8_1032F8[i] = ContStkX[i];
        D_800FD3E4_FDFE4[i] = ContStkY[i];
        D_800F92D4_F9ED4[i] = ContBtn[i];
        D_800FA19C_FAD9C[i] = ContBtnTrg[i];
        D_800F851C_F911C[i] = D_800FD410_FE010[i];
    }
}

void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3) {
    if (!(gPlayers[player].flags & 1)) {
        func_80088604_89204(gPlayers[player].port, arg1, arg2, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079D7C_7A97C);

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079DB4_7A9B4);
