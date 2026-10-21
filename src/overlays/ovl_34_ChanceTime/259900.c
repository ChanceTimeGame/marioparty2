#include "common.h"
#include "ovl_34.h"

void func_80102800_259900_ChanceTime(void) {
    Vec pos;
    Vec rot;
    Vec up;
    s16 i;
    s16 n;
    s32 j;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_80110D6A_267E6A_ChanceTime[0] = 1;
        break;
    case 2:
        D_80110D6A_267E6A_ChanceTime[0] = 2;
        break;
    case 3:
        D_80110D6A_267E6A_ChanceTime[0] = 3;
        break;
    case 0:
    default:
        D_80110D6A_267E6A_ChanceTime[0] = 0;
        break;
    }
    for (i = 1, n = 0; i < 4; i++, n++) {
        if (D_80110D6A_267E6A_ChanceTime[0] == n) {
            n++;
        }
        D_80110D6A_267E6A_ChanceTime[i] = n;
    }
    func_8002D4D0_2E0D0(10);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(60);
    omInitObjMan(40, 60);
    func_80088640_89240();
    func_80079128_79D28();
    func_800615FC_621FC_unproto(-1, -1);
    func_80018E30_19A30(1);
    D_80102708_103308 = 1;
    D_80110060_267160_ChanceTime = _CheckFlag(0x45);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x40);
    func_80026E00_27A00(1, 13.0f, -100.0f, 64.0f);
    ScissorSet(0, 0.0f, 0.0f, 319.0f, 239.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 20.0f, 80.0f, 8000.0f);
    pos.x = 0.0f;
    pos.y = 250.0f;
    pos.z = 2800.0f;
    rot.x = 0.0f;
    rot.y = 0.0f;
    rot.z = 0.0f;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    for (j = 0; j < D_800FDBCA_FE7CA; j++) {
        func_800B3820_B4420(&D_800C9B80_CA780->mtxs[j].perspMtx);
        func_800B3820_B4420(&D_800C9B80_CA780->mtxs[j].lookAtMtx);
    }
    Hu3DCamSetPositionOrientation(0, &pos, &rot, &up);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    D_80110914_267A14_ChanceTime = func_80018A64_19664(0x440009, 0xABD);
    D_80110916_267A16_ChanceTime = func_80018A64_19664(0x44000A, 0xABD);
    D_80110918_267A18_ChanceTime = func_80018A64_19664(0x44000B, 0xABD);
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_8007273C_7333C(D_80110060_267160_ChanceTime != 0 ? D_80110230_267330_ChanceTime : D_80110248_267348_ChanceTime, 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    if (D_80110060_267160_ChanceTime != 0) {
        omAddObj(1, 10, 10, -1, func_8010B02C_26212C_ChanceTime);
    } else {
        D_8011090C_267A0C_ChanceTime = omAddObj(1, 16, 4, -1, func_80103714_25A814_ChanceTime);
        D_80110910_267A10_ChanceTime = omAddObj(1, 16, 4, -1, func_80103398_25A498_ChanceTime);
    }
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(2, 3, 0, -1, func_8010E440_265540_ChanceTime);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(12, 0, 0, -1, func_8010E71C_26581C_ChanceTime);
    func_8010BF50_263050_ChanceTime();
    D_80110D80_267E80_ChanceTime[0] = omAddObj(12, 3, 0, -1, func_8010BF7C_26307C_ChanceTime);
    D_80110D80_267E80_ChanceTime[1] = omAddObj(12, 3, 0, -1, func_8010BFD0_2630D0_ChanceTime);
    if (D_80110060_267160_ChanceTime != 0) {
        /* retail: D_80110D88 through the D_80110D80 base (s0 + 8), as in MP1 */
        D_80110D80_267E80_ChanceTime[2] = omAddObj(12, 3, 0, -1, func_8010C080_263180_ChanceTime);
    } else {
        D_80110D88_267E88_ChanceTime = omAddObj(12, 3, 0, -1, func_8010C008_263108_ChanceTime);
    }
    omAddObj(5, 3, 0, -1, func_8010E0D4_2651D4_ChanceTime);
    omAddObj(1, 0, 0, -1, func_80102E4C_259F4C_ChanceTime);
    D_80110908_267A08_ChanceTime = omAddObj(5, 33, 0, -1, func_801077D8_25E8D8_ChanceTime);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(10, 2, 60, -1, func_8010EED0_265FD0_ChanceTime);
    omAddObj(1, 0, 0, -1, func_8010BF28_263028_ChanceTime);
    InitFadeIn(D_80110060_267160_ChanceTime != 0 ? 3 : 5, 16);
}

/* Two SJIS strings (local char-array initialisers?) as raw words until their user is C */
const u32 D_80110260_267360_ChanceTime[] = { 0x82628267, 0x8260826D, 0x82628264, 0x81408273, 0x8268826C, 0x826481F3, 0x00000000 };
const u32 D_8011027C_26737C_ChanceTime[] = { 0x82628267, 0x8260826D, 0x82628264, 0x81408273, 0x8268826C, 0x82640000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80102E4C_259F4C_ChanceTime);

/* GCC still thinks it is in .rodata after the previous const, but INCLUDE_ASM switched to
 * .text: switch back by hand (harmless once a C function precedes this). */
__asm__(".section .rodata");
const char D_801102A0_2673A0_ChanceTime[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80103398_25A498_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801036C4_25A7C4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80103714_25A814_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80103A64_25AB64_ChanceTime);

/* GCC still thinks it is in .rodata after the previous const, but INCLUDE_ASM switched to
 * .text: switch back by hand (harmless once a C function precedes this). */
__asm__(".section .rodata");
/* 16 vec3 (x, y, z) as raw words until its user is C */
const u32 D_801102AC_2673AC_ChanceTime[] = {
    0x3F64F95D, 0x3EE4F8B6, 0x00000000, 0x3F51B90F, 0x3F12CE46, 0x00000000, 0x3F350481, 
    0x3F350481, 0x00000000, 0x3F12CE46, 0x3F51B90F, 0x00000000, 0x3EE4F8B6, 0x3F64F95D, 
    0x00000000, 0x3F64F95D, 0x3EE4F8B6, 0x3F800000, 0x3F51B90F, 0x3F12CE46, 0x3F800000, 
    0x3F350481, 0x3F350481, 0x3F800000, 0x3F12CE46, 0x3F51B90F, 0x3F800000, 0x3EE4F8B6, 
    0x3F64F95D, 0x3F800000, 0x3F64F95D, 0x3EE4F8B6, 0xBF800000, 0x3F51B90F, 0x3F12CE46, 
    0xBF800000, 0x3F350481, 0x3F350481, 0xBF800000, 0x3F12CE46, 0x3F51B90F, 0xBF800000, 
    0x3EE4F8B6, 0x3F64F95D, 0xBF800000, 0x3F64F95D, 0x3EE4F8B6, 0x3F000000
};

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80103ADC_25ABDC_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801052B4_25C3B4_ChanceTime);

/* GCC still thinks it is in .rodata after the previous const, but INCLUDE_ASM switched to
 * .text: switch back by hand (harmless once a C function precedes this). */
__asm__(".section .rodata");
const char D_80110414_267514_ChanceTime[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801060E0_25D1E0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106434_25D534_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106548_25D648_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106604_25D704_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106B5C_25DC5C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80107594_25E694_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801077D8_25E8D8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80107B00_25EC00_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109718_260818_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801097F8_2608F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010985C_26095C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109CC4_260DC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109D84_260E84_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B02C_26212C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B214_262314_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B28C_26238C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B328_262428_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B3C4_2624C4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B7F8_2628F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BB0C_262C0C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BB74_262C74_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BF28_263028_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BF50_263050_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BF7C_26307C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BF98_263098_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BFB4_2630B4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BFD0_2630D0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BFEC_2630EC_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C008_263108_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C024_263124_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C080_263180_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C09C_26319C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C268_263368_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C44C_26354C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010CCF4_263DF4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010DFF8_2650F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E0D4_2651D4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E214_265314_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E440_265540_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E668_265768_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E71C_26581C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E7C0_2658C0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010EED0_265FD0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010EF84_266084_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F304_266404_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F4B4_2665B4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F760_266860_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F82C_26692C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F8F8_2669F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F9C4_266AC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FC18_266D18_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FD28_266E28_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FE50_266F50_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FF1C_26701C_ChanceTime);

/* GCC still thinks it is in .rodata after the previous const, but INCLUDE_ASM switched to
 * .text: switch back by hand (harmless once a C function precedes this). */
__asm__(".section .rodata");
/* Read only by .data (a texture-name table): rodata order is source order. */
const char D_80110680_267780_ChanceTime[] = "tex3_DEF";
const char D_8011068C_26778C_ChanceTime[] = "tex2_DEF";
const char D_80110698_267798_ChanceTime[] = "tex1_DEF";
const char D_801106A4_2677A4_ChanceTime[] = "tex0_DEF";
