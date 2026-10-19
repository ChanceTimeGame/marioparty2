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

void func_80073EA0_74AA0(s32 overlay, s16 event, u16 stat) {
    OvlCallEntry* e = &D_800E20D8_E2CD8[D_800E20D4_E2CD4++];

    e->overlay = overlay;
    e->event = event;
    e->stat = stat;
    if (D_800E20D4_E2CD4 >= 5) {
        D_800E20D4_E2CD4 = 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80073EF8_74AF8);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80073FE0_74BE0);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_800740AC_74CAC);

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

INCLUDE_ASM("asm/nonmatchings/74AA0", func_8007451C_7511C);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_800745FC_751FC);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074608_75208);

void func_80074614_75214(Vec* pos) {
    D_800E2114_E2D14 = *pos;
}

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074638_75238);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_8007468C_7528C);

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

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075060_75C60);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075144_75D44);

INCLUDE_ASM("asm/nonmatchings/74AA0", func_800751E0_75DE0);

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
