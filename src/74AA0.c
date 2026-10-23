#include "common.h"

/* Board overlay-call queue, board teardown and the two save-flag byte arrays (MP1 src/5CDB0.c,
   src/59E80.c, ovl_77 2FADB0.c). MP1's names are anonymous or name MP1-only structures, so MP2's
   are kept. */

typedef struct OvlCallEntry {
    /* 0x00 */ s32 overlay;
    /* 0x04 */ s16 event;
    /* 0x06 */ u16 stat;
} OvlCallEntry; // size 8

extern s16 D_800E20D2_E2CD2;
extern s16 D_800E20D4_E2CD4;
extern OvlCallEntry D_800E20D8_E2CD8[5];
extern s16 D_800E2104_E2D04;
extern s16 D_800E2106_E2D06;
extern s16 D_800E2108_E2D08;
extern s32 D_800E210C_E2D0C;
extern s16 D_800E2110_E2D10;
extern Vec D_800E2114_E2D14;
extern s16 D_800FD2A2_FDEA2;
extern s16 D_800FD840_FE440;
extern s8 D_800FD8AA_FE4AA;
extern u8 D_800FD8AD_FE4AD[];
extern u8 D_800FD425_FE025[];

void func_8007E128_7ED28(void);
void func_8006239C_62F9C(void);
void func_8005E584_5F184(void);
void func_8005E2FC_5EEFC(void);
void func_8004340C_4400C(void);
void func_80054AE8_556E8(void);
void func_8005429C_54E9C(void);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_800740AC_74CAC(void);
void func_8007451C_7511C(void);
s32 func_80075390_75F90(s32 flag);
void func_800753D4_75FD4(s32 flag);
void func_80075424_76024(s32 flag);
s32 func_80075478_76078(s32 flag);
void func_80075144_75D44(void);
void func_80073410_74010(s16 index);
GW_PLAYER* BoardPlayerGet(s32);
s32 func_8008F618_90218(void);
void func_800794A8_7A0A8(s32);
void func_800744C0_750C0(void);
void func_80073EA0_74AA0(s32 overlay, s16 event, u16 stat);

extern s16 D_800E20D0_E2CD0;
/* .data (0xCDEC0-0xCDF60); D_800CD2C8 and 0xCDF10 on are used only by the unit's asm */
s32 D_800CD2C0_CDEC0 = 1;
s32 D_800CD2C4_CDEC4 = 0;
s32 D_800CD2C8_CDEC8[2] = { 1, 0x000A0253 }; /* model description */
s32 D_800CD2D0_CDED0 = 0;
s32 D_800CD2D4_CDED4[11] = { 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0, 0 }; /* overlay per chapter */
u8 D_800CD300_CDF00[16] = { 9, 13, 18, 22, 27, 33, 39, 45, 51, 0, 0, 0, 0, 0, 0, 0 }; /* first story flag of each chapter */
s32 D_800CD310_CDF10 = 0;
s16 D_800CD314_CDF14 = 1;
s16 D_800CD316_CDF16 = 0;
u8 D_800CD318_CDF18 = 0xF0;
u8 D_800CD319_CDF19 = 0;
u8 D_800CD31A_CDF1A = 0xFF;
extern const char D_800D34E0_D40E0[]; /* "CAME" */
extern const char D_800D34E8_D40E8[];
char* D_800CD31C_CDF1C[2] = { (char*)D_800D34E8_D40E8, (char*)D_800D34E0_D40E0 };
s16 D_800CD324_CDF24[6] = { 0x10, 0x48, 0xE0, 0x58, 0x98, 0xE8 };
s16 D_800CD330_CDF30[6] = { 0x10, 0x10, 0x10, 0x18, 0x18, 0x18 };
s16 D_800CD33C_CDF3C[6] = { 0x38, 0x60, 0x100, 0x70, 0xC0, 0x108 };
s16 D_800CD348_CDF48[6] = { 0x18, 0x18, 0x18, 0x20, 0x20, 0x20 };
extern s16 D_800E2120_E2D20;
extern s8 D_800FD8AB_FE4AB;
extern s8 D_800FD8B4_FE4B4;
extern s8 D_800FD8B5_FE4B5;
extern u16 D_801011FC_101DFC;
#include "game/gamework.h"
/* D_800FD8A8_FE4A8's fields 0x0E-0x11 (Unk_800FD8A8 unk0E-unk11): retail addresses these
   through their own labels in func_80075060_75C60 and func_800751E0_75DE0 */
extern s8 D_800FD8B6_FE4B6;
extern s8 D_800FD8B7_FE4B7;
extern s8 D_800FD8B8_FE4B8;
extern s8 D_800FD8B9_FE4B9;
extern u8 D_800FD420_FE020[0x12];

void func_80073EA0_74AA0(s32 overlay, s16 event, u16 stat) {
    OvlCallEntry* e = &D_800E20D8_E2CD8[D_800E20D4_E2CD4++];

    e->overlay = overlay;
    e->event = event;
    e->stat = stat;
    if (D_800E20D4_E2CD4 >= 5) {
        D_800E20D4_E2CD4 = 4;
    }
}

void func_80073EF8_74AF8(void) {
    _SetFlag(0xC);
    if (func_80075390_75F90(4) != 0 || func_80075478_76078(4) != 0) {
        func_800753D4_75FD4(6);
    } else {
        func_80075424_76024(6);
    }
    D_800E20D0_E2CD0 = 1;
    D_800E20D4_E2CD4 = 0;
    D_800E20D2_E2CD2 = 2;
    if (func_80075478_76078(4) != 0) {
        func_80073EA0_74AA0(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], 4, 0x192);
    }
    if (func_80075390_75F90(6) == 0) {
        func_80073EA0_74AA0(0x6E, 0, 0x192);
        func_80073EA0_74AA0(0x64, 1, 0x192);
    }
    func_8007451C_7511C();
    func_80075424_76024(6);
    _ClearFlag(0x16);
}

void func_80073FE0_74BE0(void) {
    OvlCallEntry* e;

    if (D_800E20D4_E2CD4 != 0) {
        e = &D_800E20D8_E2CD8[--D_800E20D4_E2CD4];
        omOvlCallEx(e->overlay, e->event, e->stat);
        return;
    }
    if (D_800E20D0_E2CD0 != 0) {
        if (func_80075390_75F90(7) != 0) {
            func_80075424_76024(7);
        }
        omOvlCallEx(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], D_800E20D2_E2CD2, 0x192);
        D_800E20D2_E2CD2 = 2;
        return;
    }
    _ClearFlag(0xC);
    omOvlReturnEx(1);
}

void func_800740AC_74CAC(void) {
    D_800E20D0_E2CD0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_800740B8_74CB8);

void func_8007411C_74D1C(void) {
    func_8007E128_7ED28();
    D_800FD2A2_FDEA2 = -1;
    D_800FD840_FE440 = -1;
}

void func_8007414C_74D4C(void) {
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074154_74D54);

void func_800744C0_750C0(void) {
    func_8006239C_62F9C();
    func_8008CE5C_8DA5C();
    func_8005E584_5F184();
    func_8005E2FC_5EEFC();
    func_8004340C_4400C();
    func_80054AE8_556E8();
    func_8005429C_54E9C();
    MBDBackKill();
    func_80050AE0_516E0();
}

void func_8007451C_7511C(void) {
    GW_SYSTEM* sys = &GwSystem;
    s32 i;

    sys->current_player_index = 0;
    sys->chosenMinigameIndex = -1;
    sys->unk_25 = 0;
    func_80075144_75D44();
    func_80073410_74010(-1);
    D_800E2120_E2D20 = -1;
    D_800CD2C0_CDEC0 = 1;
    D_800CD2C4_CDEC4 = 0;
    D_800CD2D0_CDED0 = 0;
    if (func_80075390_75F90(6) == 0) {
        D_800FD8AA_FE4AA = 0;
        D_800FD8B5_FE4B5 = 0;
        D_800FD8AB_FE4AB = 3;
        D_800FD8B4_FE4B4 = 0;
        for (i = 0; i < 0x34; i++) {
            if (i >= 4) {
                func_80075424_76024(i);
            }
        }
        for (i = 0; i < 4; i++) {
            BoardPlayerGet(i)->coins = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_800745FC_751FC);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074608_75208);

void func_80074614_75214(Vec* pos) {
    D_800E2114_E2D14 = *pos;
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074638_75238);

void func_8007468C_7528C(void) {
    do {
        HuPrcVSleep();
    } while (func_8008F618_90218() != 0);
    while (1) {
        HuPrcVSleep();
        if (D_801011FC_101DFC == 0 && D_800E2104_E2D04 < 0) {
            continue;
        }
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        if (D_800E2108_E2D08 != 0) {
            func_800794A8_7A0A8(0x5A);
        }
        InitFadeOut(D_800E2106_E2D06, 0x10);
        HuPrcSleep(0x11);
        func_800744C0_750C0();
        if (D_800E2104_E2D04 & 0x10) {
            func_800740AC_74CAC();
        }
        if (D_800E2104_E2D04 & 1) {
            func_80073EA0_74AA0(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], 3, 0x192);
            func_80073EA0_74AA0((s16)func_8003F6F0_402F0(GwSystem.chosenMinigameIndex), 0, 0x94);
        }
        if (D_800E2104_E2D04 & 2) {
            func_80073EA0_74AA0(D_800E210C_E2D0C, D_800E2110_E2D10, 0x192);
        }
        _ClearFlag(0x45);
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074808_75408);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074D28_75928);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074DB8_759B8);

void func_80074F7C_75B7C(s32 overlay, s16 event, s16 fade, s16 music) {
    D_800E210C_E2D0C = overlay;
    D_800E2110_E2D10 = event;
    D_800E2104_E2D04 = 2;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
}

void func_80074FAC_75BAC(s8 map, s16 event, s16 fade, s16 music) {
    D_800E2104_E2D04 = 4;
    D_800FD8AA_FE4AA = map;
    D_800E20D2_E2CD2 = event;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
}

void func_80074FDC_75BDC(s16 fade, s16 music) {
    D_800E2104_E2D04 = 8;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
    func_800740AC_74CAC();
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075010_75C10);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_8007501C_75C1C);

/* Records player 1's board position and the story chapter reached (the highest chapter-clear
   flag, D_800CD300_CDF00[chapter - 1] - 1) in the saved block D_800FD8A8_FE4A8. */
void func_80075060_75C60(void) {
    Unk_800FD8A8* p = &D_800FD8A8_FE4A8;

    D_800FD8B6_FE4B6 = gPlayers[0].cur_chain_index;
    D_800FD8B7_FE4B7 = gPlayers[0].cur_space_index;
    if (func_80075390_75F90(0x32) != 0) {
        D_800FD8B8_FE4B8 = 9;
    } else {
        if (func_80075390_75F90(0x2C) != 0) {
            p->unk10 = 8;
        } else if (func_80075390_75F90(0x26) != 0) {
            p->unk10 = 7;
        } else if (func_80075390_75F90(0x20) != 0) {
            p->unk10 = 6;
        } else if (func_80075390_75F90(0x1A) != 0) {
            p->unk10 = 5;
        } else if (func_80075390_75F90(0x15) != 0) {
            p->unk10 = 4;
        } else if (func_80075390_75F90(0x11) != 0) {
            p->unk10 = 3;
        } else if (func_80075390_75F90(0xC) != 0) {
            p->unk10 = 2;
        } else {
            p->unk10 = 1;
        }
    }
    p->unk11 = -1;
}

/* Puts player 1 back where func_80075060_75C60 recorded (two characters, the chapter). */
// retail addresses every field through its own lui (no shared gPlayers / D_800FD8A8_FE4A8
// base register); same loads and stores
#ifdef NON_MATCHING
void func_80075144_75D44(void) {
    gPlayers[0].cur_chain_index = D_800FD8A8_FE4A8.unk0E;
    gPlayers[0].cur_space_index = D_800FD8A8_FE4A8.unk0F;
    gPlayers[0].next_chain_index = D_800FD8A8_FE4A8.unk0E;
    gPlayers[0].next_space_index = D_800FD8A8_FE4A8.unk0F + 1;
    gPlayers[0].character = D_800FD8A8_FE4A8.unk00;
    gPlayers[1].character = D_800FD8A8_FE4A8.unk01;
    D_800FD2A2_FDEA2 = D_800FD8A8_FE4A8.unk10;
    D_800FD840_FE440 = D_800FD8A8_FE4A8.unk11;
}
#else
INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075144_75D44);
#endif

/* As func_80075060_75C60 from the current chapter state (D_800FD2A2_FDEA2/D_800FD840_FE440, -1
   when unknown), then copies the block to D_800FD420_FE020. */
void func_800751E0_75DE0(void) {
    Unk_800FD8A8* p = &D_800FD8A8_FE4A8;

    D_800FD8B6_FE4B6 = gPlayers[0].cur_chain_index;
    D_800FD8B7_FE4B7 = gPlayers[0].cur_space_index;
    D_800FD8B8_FE4B8 = D_800FD2A2_FDEA2;
    D_800FD8B9_FE4B9 = D_800FD840_FE440;
    if (D_800FD2A2_FDEA2 == -1) {
        if (func_80075390_75F90(0x32) != 0) {
            D_800FD8B8_FE4B8 = 9;
        } else if (func_80075390_75F90(0x2C) != 0) {
            p->unk10 = 8;
        } else if (func_80075390_75F90(0x26) != 0) {
            p->unk10 = 7;
        } else if (func_80075390_75F90(0x20) != 0) {
            p->unk10 = 6;
        } else if (func_80075390_75F90(0x1A) != 0) {
            p->unk10 = 5;
        } else if (func_80075390_75F90(0x15) != 0) {
            p->unk10 = 4;
        } else if (func_80075390_75F90(0x11) != 0) {
            p->unk10 = 3;
        } else if (func_80075390_75F90(0xC) != 0) {
            p->unk10 = 2;
        } else {
            p->unk10 = 1;
        }
    }
    if (D_800FD840_FE440 == -1) {
        p->unk11 = 0;
    } else if (func_80075390_75F90(D_800CD300_CDF00[p->unk10 - 1] + p->unk11 - 1) == 0) {
        p->unk11--;
    }
    bcopy(&D_800FD8A8_FE4A8, D_800FD420_FE020, sizeof(D_800FD8A8_FE4A8));
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075354_75F54);

s32 func_80075390_75F90(s32 flag) {
    return (s8)D_800FD8AD_FE4AD[flag / 8] & (1 << (flag % 8));
}

void func_800753D4_75FD4(s32 flag) {
    D_800FD8AD_FE4AD[flag / 8] |= (1 << flag % 8);
}

void func_80075424_76024(s32 flag) {
    D_800FD8AD_FE4AD[flag / 8] &= ~(1 << flag % 8);
}

s32 func_80075478_76078(s32 flag) {
    return (s8)D_800FD425_FE025[flag / 8] & (1 << (flag % 8));
}

void func_800754BC_760BC(s32 flag) {
    D_800FD425_FE025[flag / 8] |= (1 << flag % 8);
}

void func_8007550C_7610C(s32 flag) {
    D_800FD425_FE025[flag / 8] &= ~(1 << flag % 8);
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075560_76160);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075638_76238);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075688_76288);
