#include "common.h"
#include "ovl_5B.h"

/* Sets up the scene's extra models and processes: 8010DCAC and 80110908, the screen-wide sprite
   D_801144A6, model [0x14] attached to [0x11]'s matrix, the c167/c168 textures on [0x17]/[0x20],
   [0xC]'s motion (D_80114860 picks the second one) and its "rc_ban" texture animation. */
void func_8010A940_3875F0_name_5B(void) {
    void* data;

    omAddPrcObj(func_8010DCAC_38A95C_name_5B, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80110908_38D5B8_name_5B, 0x3F00, 0x800, 0);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], 0.5f);
    D_801144A4_391154_name_5B = func_8001A2F8_1AEF8(0x900FD);
    D_801144A6_391156_name_5B = func_8001AAAC_1B6AC(D_801144A4_391154_name_5B, 0, 1);
    espPosSet(D_801144A6_391156_name_5B, 160, 120);
    espDispOff(D_801144A6_391156_name_5B);
    func_8001A6BC_1B2BC(D_801144A6_391156_name_5B, 256);
    func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx, 30.0f, -8.0f, 0.0f);
    func_80025830_26430((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx, 1.1f, 1.1f, 1.1f);
    func_80030CD4_318D4((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x11]].mtx,
                        (f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx);
    HmfModelObjAttrSet(D_80114758_391408_name_5B[0x14], 0x80000000, 0x80000000);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x14]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x14]);
    HmfModelObjAttrSet(D_80114758_391408_name_5B[0x11], 0x80000000, 0x80000000);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x11]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x11]);
    data = DataRead(0x90064);
    func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0x17]].hmf, data, 0, "c167n_0_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x17]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x17]);
    data = DataRead(0x9006D);
    func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0x20]].hmf, data, 0, "c168n_0_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x20]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x20]);
    if (D_80114860_391510_name_5B == 0) {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xC], D_801147D0_391480_name_5B[0xC]);
    } else {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xC], D_801147D0_391480_name_5B[0xD]);
    }
    func_80029E80_2AA80(D_80114758_391408_name_5B[0xC], 2, 2);
    data = DataRead(0x90051);
    D_801144A8_391158_name_5B = func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0xC]].hmf, data, 0, "rc_ban_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0xC]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0xC]);
    data = DataRead(0x90050);
    D_801144AA_39115A_name_5B = func_8003DF08_3EB08(data);
    DataClose(data);
    func_8003EE44_3FA44(D_800FC834_FD434[D_80114758_391408_name_5B[0xC]].hmf);
    D_80114730_3913E0_name_5B[0] = 0;
}

/* The Mini-Game Park-style submenu (main menu choice 6, D_80114738 = 6): a message window with
   seven choices (cursor D_801148A4, -1 none yet; the stick moves, Z jumps to 4). A confirms the
   choice with its own question and runs its screen (0 8010DF24, 1 8010B654, 2 8010CB88,
   3 8010D8B0, 5 8010DA34, 6 80110AF8); 4 leaves the submenu. First visit (D_80114854) shows the
   introduction and sets flag 0x14. */
#ifdef NON_MATCHING
/* Retail tests a copy of `redraw` (v0) at the loop's two merge points and swaps s1/s2 for
   win/redraw; the rest follows. */
void func_8010ACBC_38796C_name_5B(void) {
    s16 size[2];
    s16 win;
    s16 dir;
    s16 choice;
    s32 redraw;
    s8 stick;

    D_801134D0_390180_name_5B[0] = 0;
    redraw = 0;
    func_80109374_386024_name_5B(D_80113494_390144_name_5B);
    func_80109380_386030_name_5B(15);
    func_8008DBE0_8E7E0(size, 0x4EA, 0x502);
    win = D_801144A2_391152_name_5B = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 180, size[0], size[1], 0);
    func_8008D59C_8E19C(win, 1 << D_80114862_391512_name_5B);
    func_80089284_89E84(win, 32, 32);
    D_800F920C_F9E0C[win].unkAA = 0x9E;
    func_80089A48_8A648(win, 0);
    func_8010933C_385FEC_name_5B(0);
    if (D_80114854_391504_name_5B != 0) {
        func_8008E978_8F578(win);
        D_80114854_391504_name_5B = 0;
        func_800890CC_89CCC(win, 0x4EB, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        func_8008D5D8_8E1D8(win);
        func_80108788_385438_name_5B(13, 20, 1, (void (*)(s16*))-1);
        HuPrcSleep(40);
        func_80108788_385438_name_5B(7, 20, 1, (void (*)(s16*))-1);
        func_8008D6F0_8E2F0(win);
        func_800890CC_89CCC(win, 0x4EC, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        _SetFlag(0x14);
        D_801148A4_391554_name_5B = -1;
        D_801134D0_390180_name_5B[0] = 1;
    } else if (D_8011269C_38F34C_name_5B == 2 && D_801134CE_39017E_name_5B == 0) {
        D_801148A4_391554_name_5B = 5;
        redraw = 1;
        D_801134CE_39017E_name_5B = redraw;
    } else {
        func_8008E978_8F578(win);
        func_800890CC_89CCC(win, 0x4EA, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        D_801148A4_391554_name_5B = -1;
    }
    while (1) {
        HuPrcVSleep();
        D_80114730_3913E0_name_5B[0] = 0;
        stick = ContStkX[D_80114862_391512_name_5B];
        dir = -(stick > 30);
        if (stick < -30) {
            dir = 1;
        }
        if ((ContBtnTrg[D_80114862_391512_name_5B] & 0x4000) && D_801148A4_391554_name_5B != 4) {
            D_801148A4_391554_name_5B = 4;
            D_8011473C_3913EC_name_5B = 1;
            func_8010938C_38603C_name_5B(4);
            func_8008D5D8_8E1D8(win);
            PlaySound(1);
            func_80108788_385438_name_5B(D_801134C0_390170_name_5B[D_801148A4_391554_name_5B], 20, 1, (void (*)(s16*))-1);
            D_80114730_3913E0_name_5B[0] = 1;
            redraw = 1;
        }
        if (dir != 0 || (D_801148A4_391554_name_5B == -1 && (ContBtnTrg[D_80114862_391512_name_5B] & 0x8000))) {
            func_8008D5D8_8E1D8(win);
            PlaySound(1);
            if (D_801148A4_391554_name_5B != -1) {
                if (D_80114742_3913F2_name_5B == 0 && D_801148A4_391554_name_5B + dir == 5) {
                    dir *= 2;
                }
                D_801148A4_391554_name_5B += dir;
                if (D_801148A4_391554_name_5B >= 7) {
                    D_801148A4_391554_name_5B = 0;
                }
                if (D_801148A4_391554_name_5B < 0) {
                    D_801148A4_391554_name_5B = 6;
                }
                D_8011473C_3913EC_name_5B = 1;
                func_8010938C_38603C_name_5B(D_801148A4_391554_name_5B);
                func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 0);
                func_80108788_385438_name_5B(D_801134C0_390170_name_5B[D_801148A4_391554_name_5B], 15, 1, (void (*)(s16*))-1);
                func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 4);
            } else {
                D_801148A4_391554_name_5B = (dir >> 15) & 6;
                func_80108788_385438_name_5B(D_801134C0_390170_name_5B[D_801148A4_391554_name_5B], 15, 1, (void (*)(s16*))-1);
                func_8010933C_385FEC_name_5B(D_801148A4_391554_name_5B);
                D_8011473C_3913EC_name_5B = 1;
            }
            D_80114730_3913E0_name_5B[0] = 1;
            redraw = 1;
            HuPrcVSleep();
            D_80114730_3913E0_name_5B[0] = 0;
        }
        if (redraw == 0 && (ContBtnTrg[D_80114862_391512_name_5B] & 0x8000)) {
            PlaySound(2);
            switch (D_801148A4_391554_name_5B) {
                case 0:
                    D_80113490_390140_name_5B = 1;
                    choice = func_8010B5A8_388258_name_5B(win, 0x4EE, 0);
                    D_80113490_390140_name_5B = 0;
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        func_8008AD44_8B944(win);
                        func_8008D5D8_8E1D8(win);
                        D_8011473C_3913EC_name_5B = 0;
                        func_8010DF24_38ABD4_name_5B();
                    }
                    redraw = 1;
                    break;
                case 1:
                    choice = func_8010B5A8_388258_name_5B(win, 0x4F5, 0);
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        func_8008D5D8_8E1D8(win);
                        D_8011473C_3913EC_name_5B = 0;
                        func_8010B654_388304_name_5B();
                    }
                    redraw = 1;
                    break;
                case 2:
                    choice = func_8010B5A8_388258_name_5B(win, 0x4F3, 0);
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        func_8008AD44_8B944(win);
                        func_8008D5D8_8E1D8(win);
                        D_8011473C_3913EC_name_5B = 0;
                        func_8010CB88_389838_name_5B();
                    }
                    redraw = 1;
                    break;
                case 3:
                    if (D_80114860_391510_name_5B == 0) {
                        choice = func_8010B5A8_388258_name_5B(win, 0x4F0, 0);
                    } else {
                        choice = func_8010B5A8_388258_name_5B(win, 0x4F1, 0);
                    }
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        func_8008D5D8_8E1D8(win);
                        D_8011473C_3913EC_name_5B = 0;
                        D_801134D0_390180_name_5B[0] = 1;
                        func_8010D8B0_38A560_name_5B();
                    }
                    redraw = 1;
                    break;
                case 4:
                    choice = func_8010B5A8_388258_name_5B(win, 0x502, 0);
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        D_8011473C_3913EC_name_5B = 0;
                        func_8008EED8_8FAD8(win, 0);
                        func_8008CCA8_8D8A8(win);
                        func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 0);
                        func_800794A8_7A0A8(20);
                        HuPrcSleep(3);
                        if (D_801134D0_390180_name_5B[0] != 0) {
                            func_8007DF5C_7EB5C();
                        }
                        func_80108788_385438_name_5B(14, 20, 0, (void (*)(s16*))-1);
                        return;
                    }
                    redraw = 1;
                    break;
                case 5:
                    choice = func_8010B5A8_388258_name_5B(win, 0x500, 0);
                    if ((choice == -1) | (choice == 1)) {
                    } else {
                        D_8011473C_3913EC_name_5B = 0;
                        func_8008D5D8_8E1D8(win);
                        func_8010DA34_38A6E4_name_5B();
                    }
                    redraw = 1;
                    break;
                case 6:
                    D_80113492_390142_name_5B = 1;
                    if ((u16)(func_8010B5A8_388258_name_5B(win, 0x4F7, 0) + 1) >= 2) {
                        D_8011473C_3913EC_name_5B = 0;
                        func_8008D5D8_8E1D8(win);
                        func_80110AF8_38D7A8_name_5B();
                    }
                    D_80113492_390142_name_5B = 0;
                default:
                    redraw = 1;
                    break;
            }
            D_8011473C_3913EC_name_5B = 1;
            HuPrcSleep(5);
        }
        if (redraw != 0) {
            func_8008AD44_8B944(win);
            if (func_800892D8_89ED8(win) & 8) {
                func_8008E978_8F578(win);
            }
            func_800890CC_89CCC(win, D_801134B0_390160_name_5B[D_801148A4_391554_name_5B], -1, -1);
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
            redraw = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ACBC_38796C_name_5B);
#endif

/* Shows message `mes` in window `win`, waits for it to finish and returns the choice (default
   `def`). */
s16 func_8010B5A8_388258_name_5B(s16 win, s32 mes, s16 def) {
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, mes, -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    return func_8008BB48_8C748(win, def, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B654_388304_name_5B);



__asm__(".section .rodata");
const char D_801139A4_390654_name_5B[] = "record";

__asm__(".section .rodata");
const char D_801139AC_39065C_name_5B[] = "hari";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010C5D4_389284_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010C828_3894D8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010CB88_389838_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010D6E8_38A398_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010D8B0_38A560_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DA34_38A6E4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DCAC_38A95C_name_5B);


__asm__(".section .rodata");
const char D_801139B4_390664_name_5B[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DF24_38ABD4_name_5B);


__asm__(".section .rodata");
const char D_801139C0_390670_name_5B[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010E618_38B2C8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ED80_38BA30_name_5B);



__asm__(".section .rodata");
const u32 D_801139C8_390678_name_5B[2] = { 0x05256405, 0x00000000 };

__asm__(".section .rodata");
const u32 D_801139D0_390680_name_5B[2] = { 0x05253032, 0x64050000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010F734_38C3E4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_801101E8_38CE98_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110770_38D420_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8011083C_38D4EC_name_5B);


__asm__(".section .rodata");
const char D_801139F4_3906A4_name_5B[28] = "c168_000-atama";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110908_38D5B8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110AF8_38D7A8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112094_38ED44_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112304_38EFB4_name_5B);
