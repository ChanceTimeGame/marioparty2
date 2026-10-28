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

/* The music room (submenu choice 1): builds the song list by category (D_801144D0, songs in
   D_80114588; the extra categories need D_80113F84 >= 20, flags 0xF-0x11, flag 0xB), lifts the
   record player (model [0x12], arm [0x14]) and lists one category per page in window 1 (D-pad
   left/right one category, C-left/C-right two, turning the player); A plays the chosen song
   (switching the sound bank when needed), B leaves and restores the menu music. */
#ifdef NON_MATCHING
/* Same flow and calls; differs in which locals get s-registers and stack slots (retail spills
   win1/win2/ncat/prev in that order) and in the bank store. */
void func_8010B654_388304_name_5B(void) {
    u16 mdl;
    u16 arm;
    s16 i;
    s16 n;
    s16 cat;
    s16 ncat;
    s16 sel;
    s16 delta;
    s16 bank;
    s16 cur;
    s16 prev;
    s16 win1;
    s16 win2;
    Ovl5BSong* song;
    f32 sx;
    f32 sz;

    mdl = D_80114758_391408_name_5B[0x12];
    arm = D_80114758_391408_name_5B[0x14];
    func_80112304_38EFB4_name_5B();
    n = 0;
    for (i = 0; i < 6; i++) {
        D_801144D0_391180_name_5B[i] = D_80113774_390424_name_5B[i];
        for (song = D_80113774_390424_name_5B[i].songs; song->song >= 0; song++, n++) {
            D_80114588_391238_name_5B[n] = *song;
            D_801144D0_391180_name_5B[i].count++;
        }
    }
    cat = 6;
    if (D_80113F84_390C34_name_5B >= 20) {
        D_801144D0_391180_name_5B[cat] = D_801137BC_39046C_name_5B;
        for (song = D_801137BC_39046C_name_5B.songs; song->song >= 0; song++, n++) {
            D_80114588_391238_name_5B[n] = *song;
            D_801144D0_391180_name_5B[cat].count++;
        }
        cat++;
        if (_CheckFlag(0xF) && _CheckFlag(0x10) && _CheckFlag(0x11)) {
            D_801144D0_391180_name_5B[cat] = D_801137C8_390478_name_5B;
            for (song = D_801137C8_390478_name_5B.songs; song->song >= 0; song++, n++) {
                D_80114588_391238_name_5B[n] = *song;
                D_801144D0_391180_name_5B[cat].count++;
            }
            cat++;
        }
    }
    if (_CheckFlag(0xB)) {
        D_801144D0_391180_name_5B[cat] = D_801137D4_390484_name_5B[0];
        for (song = D_801137D4_390484_name_5B[0].songs; song->song >= 0; song++, n++) {
            D_80114588_391238_name_5B[n] = *song;
            D_801144D0_391180_name_5B[cat].count++;
        }
        cat++;
    }
    D_801144D0_391180_name_5B[cat].songs = (Ovl5BSong*)-1;
    D_801144D0_391180_name_5B[cat].msg = -1;
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)mdl].pos.y += 5.0f;
        HuPrcVSleep();
    }
    sz = 1.0f;
    sx = sz;
    func_8002C9C0_2D5C0(mdl, D_801147D0_391480_name_5B[0x12]);
    while (func_80029CE4_2A8E4(mdl) < 30.0f) {
        sz -= 0.03f;
        func_800297E8_2A3E8(arm, sx, 1.0f, sz);
        HuPrcVSleep();
    }
    D_801144AC_39115C_name_5B = 0;
    D_801144AE_39115E_name_5B = mdl;
    D_801144C0_391170_name_5B.x = D_800FC834_FD434[(s16)mdl].rot.x;
    D_801144C0_391170_name_5B.y = D_800FC834_FD434[(s16)mdl].rot.y;
    D_801144C0_391170_name_5B.z = D_800FC834_FD434[(s16)mdl].rot.z;
    D_801144B4_391164_name_5B.x = D_800FC834_FD434[(s16)mdl].pos.x;
    D_801144B4_391164_name_5B.y = D_800FC834_FD434[(s16)mdl].pos.y;
    D_801144B4_391164_name_5B.z = D_800FC834_FD434[(s16)mdl].pos.z;
    D_801144B0_391160_name_5B[0] = arm;
    PlaySound(0xA4);
    PlaySound(0xA8);
    func_80108788_385438_name_5B(15, 20, 0, func_8010D6E8_38A398_name_5B);
    win1 = func_800888A8_894A8(160, 32, 128, 170, 0, 0);
    func_8008D59C_8E19C(win1, 1 << D_80114862_391512_name_5B);
    func_80089284_89E84(win1, 0x8020, 0x8020);
    D_800F920C_F9E0C[win1].unkAA = -1;
    func_80089B2C_8A72C(win1, 0);
    func_80089A48_8A648(win1, 0);
    func_80089C78_8A878(win1, 1);
    func_80089DA0_8A9A0(win1, 160, 160, 144);
    win2 = func_800888A8_894A8(160, 172, 128, 36, 0, 0);
    func_80089B2C_8A72C(win2, 0);
    func_80089A48_8A648(win2, 0);
    func_80089C78_8A878(win2, 1);
    func_80089DA0_8A9A0(win2, 160, 160, 144);
    ncat = cat;
    sel = 0;
    delta = 0;
    bank = D_800CD52C_CE12C;
    D_800CD528_CE128 = 1;
    cur = -1;
    prev = -2;
    while (1) {
        func_800890CC_89CCC(win1, D_801144D0_391180_name_5B[D_801137EC_39049C_name_5B].msg, -1, -1);
        func_800890CC_89CCC(win2, 0x42E, -1, 0x90);
        while (func_8008BA30_8C630(win2) != 0) {
            HuPrcVSleep();
        }
        func_8008DF9C_8EB9C(win1, 0x303);
        func_8008BB48_8C748(win1, sel, 0);
        if (D_800F920C_F9E0C[win1].unkA8 & 0x4000) {
            break;
        }
        if (D_800F920C_F9E0C[win1].unkA8 & 0x8000) {
            cur = 0;
            for (i = 0; i < D_801137EC_39049C_name_5B; i++) {
                cur += D_801144D0_391180_name_5B[i].count;
            }
            cur += D_800F920C_F9E0C[win1].unk32;
            if (prev != cur) {
                prev = cur;
                func_800794A8_7A0A8(20);
                func_8010C5D4_389284_name_5B();
                HuPrcSleep(10);
                if (bank != D_80114588_391238_name_5B[cur].bank) {
                    D_800CD52C_CE12C = bank = D_80114588_391238_name_5B[cur].bank;
                    func_80079464_7A064();
                    func_80079868_7A468();
                    HuPrcSleep(10);
                    while (func_8000E930_F530() != 0) {
                        HuPrcVSleep();
                    }
                    func_80079DB4_7A9B4();
                }
                func_8010C828_3894D8_name_5B(cur & 1);
            } else {
                func_800794A8_7A0A8(20);
                HuPrcSleep(20);
            }
            PlayMusic(D_80114588_391238_name_5B[cur].song);
        }
        if ((D_800F920C_F9E0C[win1].unkA8 & 0x200) && D_801137EC_39049C_name_5B > 0) {
            D_801137EC_39049C_name_5B--;
            delta = -1;
        } else if ((D_800F920C_F9E0C[win1].unkA8 & 0x100)
                   && D_801144D0_391180_name_5B[D_801137EC_39049C_name_5B + 1].msg != -1) {
            D_801137EC_39049C_name_5B++;
            delta = 1;
        } else if (D_800F920C_F9E0C[win1].unkA8 & 2) {
            if (D_801137EC_39049C_name_5B < 2) {
                delta = -D_801137EC_39049C_name_5B;
                D_801137EC_39049C_name_5B = 0;
            } else {
                D_801137EC_39049C_name_5B -= 2;
                delta = -2;
            }
        } else if (D_800F920C_F9E0C[win1].unkA8 & 1) {
            if (D_801137EC_39049C_name_5B + 2 < ncat) {
                D_801137EC_39049C_name_5B += 2;
                delta = 2;
            } else {
                delta = ncat - (D_801137EC_39049C_name_5B + 1);
                D_801137EC_39049C_name_5B = ncat - 1;
            }
        }
        if (delta != 0) {
            func_8008D5D8_8E1D8(win1);
            func_8008D5D8_8E1D8(win2);
            for (i = 0; i < ((delta < 0) ? -delta : delta); i++) {
                func_8002C9C0_2D5C0(mdl, D_801147D0_391480_name_5B[0x13]);
                func_80029FE4_2ABE4(mdl, (delta >= 0) ? delta : -delta);
                PlaySound((bank == 1) ? 0xA4 : 0x354);
                if (delta > 0) {
                    while (func_80029CE4_2A8E4(mdl) < func_80029D0C_2A90C(mdl)) {
                        HuPrcVSleep();
                    }
                } else {
                    func_80029C74_2A874(mdl, func_80029D0C_2A90C(mdl));
                    func_80029E80_2AA80(mdl, 4, 4);
                    while (func_80029CE4_2A8E4(mdl) != 0.0f) {
                        HuPrcVSleep();
                    }
                }
            }
            func_8008D6F0_8E2F0(win1);
            func_8008D6F0_8E2F0(win2);
            delta = 0;
        }
        sel = D_800F920C_F9E0C[win1].unk32;
        if (sel >= D_801144D0_391180_name_5B[D_801137EC_39049C_name_5B].count) {
            D_800F920C_F9E0C[win1].unk32 = D_801144D0_391180_name_5B[D_801137EC_39049C_name_5B].count - 1;
            sel = D_800F920C_F9E0C[win1].unk32;
        }
    }
    D_800CD528_CE128 = 5;
    if (cur != -1) {
        func_800794A8_7A0A8(20);
        func_8010C5D4_389284_name_5B();
        HuPrcSleep(10);
        if (bank != 1) {
            D_800CD52C_CE12C = 1;
            func_80079464_7A064();
            func_80079868_7A468();
            HuPrcSleep(10);
            while (func_8000E930_F530() != 0) {
                HuPrcVSleep();
            }
            func_80079DB4_7A9B4();
            func_8010C828_3894D8_name_5B(0);
        }
        PlayMusic(4);
    }
    func_8008CCA8_8D8A8(win1);
    func_8008CCA8_8D8A8(win2);
    func_8002C9C0_2D5C0(mdl, D_801147D0_391480_name_5B[0x12]);
    func_80029C74_2A874(mdl, func_80029D0C_2A90C(mdl));
    func_80029E80_2AA80(mdl, 4, 4);
    func_8002979C_2A39C(mdl, D_801144C0_391170_name_5B.x, D_801144C0_391170_name_5B.y, D_801144C0_391170_name_5B.z);
    D_801144AC_39115C_name_5B = 1;
    PlaySound(0xA9);
    func_80108788_385438_name_5B(9, 15, 0, func_8010D6E8_38A398_name_5B);
    while (func_80029CE4_2A8E4(mdl) != 0.0f) {
        sz += 0.03f;
        func_800297E8_2A3E8(arm, sx, 1.0f, sz);
        HuPrcVSleep();
    }
    func_800297E8_2A3E8(arm, 1.0f, 1.0f, 1.0f);
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)mdl].pos.y -= 5.0f;
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B654_388304_name_5B);
#endif



__asm__(".section .rodata");
const char D_801139A4_390654_name_5B[] = "record";

__asm__(".section .rodata");
const char D_801139AC_39065C_name_5B[] = "hari";

/* Opens the record book (model [12]): the cover ("hari") swings while the "record" part lifts
   towards the camera. */
void func_8010C5D4_389284_name_5B(void) {
    s16 model = D_80114758_391408_name_5B[12];
    s16 frame;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    frame = func_80029E14_2AA14(model);
    func_80029E80_2AA80(model, 1, 1);
    func_8003B72C_3C32C(model, frame, D_801139A4_390654_name_5B, 0x4C, 0x47);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC2 : 0x370);
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        hari->unk28.y = hariY + HuMathSin(angle) * 10.0f;
        record->unk28.x = x + HuMathSin(angle) * dx;
        record->unk28.y = y + t / 10.0f * dy;
        record->unk28.z = z + HuMathSin(angle) * dz;
        if (i >= 4) {
            record->unk10.z = (i - 3) * 12.857142f;
        }
        HuPrcVSleep();
    }
}

/* Closes the record book (model [12]), the reverse of 8010C5D4. mode 0 restores the model's
   textures; otherwise its texture animation slot D_801144A8 is reset to frame D_801144AA (mode
   1) or D_801144A8 (mode 2). */
void func_8010C828_3894D8_name_5B(s16 mode) {
    u16 model = D_80114758_391408_name_5B[12];
    TexAnimSlot* slot;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    if (mode == 0) {
        func_8003EE44_3FA44(D_800FC834_FD434[(s16)model].hmf);
    } else {
        func_8003EEA4_3FAA4(D_800FC834_FD434[(s16)model].hmf);
        slot = &D_800FD7F8_FE3F8[D_801144A8_391158_name_5B];
        if (mode == 1) {
            slot->unk_00 = D_801144AA_39115A_name_5B;
        } else {
            slot->unk_00 = D_801144A8_391158_name_5B;
        }
        slot->unk_04 = 0;
        slot->unk_0A = 0;
        slot->unk_06 = 0;
        slot->unk_02 = 0;
    }
    func_80029E14_2AA14(model);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        record->unk28.x = x + func_800B7890_B8490(angle) * dx;
        record->unk28.y = y + (1.0f - t / 10.0f) * dy;
        record->unk28.z = z + func_800B7890_B8490(angle) * dz;
        if (i < 8) {
            record->unk10.z = 90.0f - t * 12.857142f;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 6; i++) {
        hari->unk28.y = hariY + func_800B7890_B8490(i * 18.0f) * 10.0f;
        HuPrcVSleep();
    }
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC1 : 0x320);
    func_80029E80_2AA80(model, 1, 0);
    HuPrcSleep(10);
}

/* The record book's sound test (model [15], its shadow [17]): the book rises, a page window
   lists the page's sounds (D_801137F0: message and sound count per page, -1 ends; the last page
   only with flag 0xB). A plays the chosen sound, the pad's left/right (0x200/0x100) turn one page,
   C-left/C-right (2/1) two; each turned page plays the page motion. B closes the book. */
#ifdef NON_MATCHING
/* NON_MATCHING: logic complete; GCC's loop-invariant hoisting differs (retail hoists the table
   addresses in the page loops and only two window offsets) and the branch layout of the C-right
   case. */
void func_8010CB88_389838_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[15];
    u16 shadow = D_80114758_391408_name_5B[17];
    s16 i;
    f32 scale;
    f32 one;
    s16 win;
    s16 win2;
    s16 sound;
    s16 pages;
    s16 choice;
    s16 step;
    s16 sum;
    s16 idx;
    TextWindow* w;

    sound = -1;
    if (!_CheckFlag(0xB)) {
        D_801137F0_3904A0_name_5B[15][0] = D_801137F0_3904A0_name_5B[15][1] = sound;
    }
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)model].pos.y += 5.0f;
        HuPrcVSleep();
    }
    one = scale = 1.0f;
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[15]);
    while (func_80029CE4_2A8E4(model) < 30.0f) {
        scale -= 0.03f;
        func_800297E8_2A3E8(shadow, one, 1.0f, scale);
        HuPrcVSleep();
    }
    D_801144AC_39115C_name_5B = 0;
    D_801144AE_39115E_name_5B = model;
    D_801144C0_391170_name_5B.x = D_800FC834_FD434[(s16)model].rot.x;
    D_801144C0_391170_name_5B.y = D_800FC834_FD434[(s16)model].rot.y;
    D_801144C0_391170_name_5B.z = D_800FC834_FD434[(s16)model].rot.z;
    D_801144B4_391164_name_5B.x = D_800FC834_FD434[(s16)model].pos.x;
    D_801144B4_391164_name_5B.y = D_800FC834_FD434[(s16)model].pos.y;
    D_801144B4_391164_name_5B.z = D_800FC834_FD434[(s16)model].pos.z;
    D_801144B0_391160_name_5B[0] = shadow;
    PlaySound(0xA4);
    PlaySound(0xA8);
    func_80108788_385438_name_5B(15, 20, 0, func_8010D6E8_38A398_name_5B);
    win = func_800888A8_894A8(0xA0, 0x20, 0x80, 0xAA, 0, 0);
    func_8008D59C_8E19C(win, 1 << D_80114862_391512_name_5B);
    func_80089284_89E84(win, 0x8020, 0x8020);
    D_800F920C_F9E0C[win].unkAA = -1;
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 0xA0, 0xA0, 0x90);
    win2 = func_800888A8_894A8(0xA0, 0xAC, 0x80, 0x24, 0, 0);
    func_80089B2C_8A72C(win2, 0);
    func_80089A48_8A648(win2, 0);
    func_80089C78_8A878(win2, 1);
    func_80089DA0_8A9A0(win2, 0xA0, 0xA0, 0x90);
    pages = 0;
    while (D_801137F0_3904A0_name_5B[pages][0] != -1) {
        pages++;
    }
    choice = 0;
    step = 0;
    func_800890CC_89CCC(win, D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][0], -1, -1);
    func_800794A8_7A0A8(20);
    func_8010C5D4_389284_name_5B();
    D_800CD52C_CE12C = 0;
    HuPrcSleep(10);
    func_80079464_7A064();
    func_80079868_7A468();
    HuPrcSleep(10);
    while (func_8000E930_F530()) {
        HuPrcVSleep();
    }
    func_80079DB4_7A9B4();
    func_8010C828_3894D8_name_5B(2);
    while (1) {
        func_800890CC_89CCC(win, D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][0], -1, -1);
        func_800890CC_89CCC(win2, 0x676, -1, 0x90);
        while (func_8008BA30_8C630(win)) {
            HuPrcVSleep();
        }
        func_8008DF9C_8EB9C(win, 0x303);
        func_8008BB48_8C748(win, choice, 0);
        if (D_800F920C_F9E0C[win].unkA8 & 0x4000) {
            break;
        }
        if (D_800F920C_F9E0C[win].unkA8 & 0x8000) {
            for (i = 0, sum = 0; i < D_80113834_3904E4_name_5B; i++) {
                sum += D_801137F0_3904A0_name_5B[i][1];
            }
            idx = sum + D_800F920C_F9E0C[win].unk32;
            func_80079868_7A468();
            sound = PlaySound(D_801135E0_390290_name_5B[idx]);
        }
        if ((D_800F920C_F9E0C[win].unkA8 & 0x200) && D_80113834_3904E4_name_5B > 0) {
            D_80113834_3904E4_name_5B--;
            step = -1;
        } else if ((D_800F920C_F9E0C[win].unkA8 & 0x100)
                   && D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B + 1][0] != -1) {
            D_80113834_3904E4_name_5B++;
            step = 1;
        } else if (D_800F920C_F9E0C[win].unkA8 & 2) {
            step = -D_80113834_3904E4_name_5B;
            if (D_80113834_3904E4_name_5B < 2) {
                D_80113834_3904E4_name_5B = 0;
            } else {
                D_80113834_3904E4_name_5B -= 2;
                step = -2;
            }
        } else if (D_800F920C_F9E0C[win].unkA8 & 1) {
            step = 2;
            if (D_80113834_3904E4_name_5B + 2 >= pages) {
                step = pages - (D_80113834_3904E4_name_5B + 1);
                D_80113834_3904E4_name_5B = pages - 1;
            } else {
                D_80113834_3904E4_name_5B += 2;
            }
        }
        if (step != 0) {
            func_8008D5D8_8E1D8(win);
            func_8008D5D8_8E1D8(win2);
            for (i = 0; i < (step < 0 ? -step : step); i++) {
                PlaySound(0x354);
                func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[16]);
                func_80029FE4_2ABE4(model, (step >= 0) ? step : -step);
                if (step > 0) {
                    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
                        HuPrcVSleep();
                    }
                } else {
                    func_80029C74_2A874(model, func_80029D0C_2A90C(model));
                    func_80029E80_2AA80(model, 4, 4);
                    while (func_80029CE4_2A8E4(model) != 0.0f) {
                        HuPrcVSleep();
                    }
                }
            }
            func_8008D6F0_8E2F0(win);
            func_8008D6F0_8E2F0(win2);
            step = 0;
        }
        w = &D_800F920C_F9E0C[win];
        choice = w->unk32;
        if (choice >= D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][1]) {
            w->unk32 = D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][1] - 1;
            choice = w->unk32;
        }
    }
    func_800794A8_7A0A8(20);
    if (sound != -1) {
        func_80079848_7A448(sound);
    }
    func_8010C5D4_389284_name_5B();
    HuPrcSleep(10);
    D_800CD52C_CE12C = 1;
    func_80079464_7A064();
    func_80079868_7A468();
    HuPrcSleep(10);
    while (func_8000E930_F530()) {
        HuPrcVSleep();
    }
    func_80079DB4_7A9B4();
    func_8010C828_3894D8_name_5B(0);
    PlayMusic(4);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win2);
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[15]);
    func_80029C74_2A874(model, func_80029D0C_2A90C(model));
    func_80029E80_2AA80(model, 4, 4);
    func_8002979C_2A39C(model, D_801144C0_391170_name_5B.x, D_801144C0_391170_name_5B.y, D_801144C0_391170_name_5B.z);
    D_801144AC_39115C_name_5B = 1;
    PlaySound(0xA9);
    func_80108788_385438_name_5B(10, 15, 0, func_8010D6E8_38A398_name_5B);
    while (func_80029CE4_2A8E4(model) != 0.0f) {
        scale += 0.03f;
        func_800297E8_2A3E8(shadow, one, 1.0f, scale);
        HuPrcVSleep();
    }
    func_800297E8_2A3E8(shadow, 1.0f, 1.0f, 1.0f);
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)model].pos.y -= 5.0f;
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010CB88_389838_name_5B);
#endif

/* 80108788's per-frame callback while the camera moves to the record book: moves the book (and
   its shadow) between its place and a point 145 in front of the camera at screen (316, 208);
   towards the camera when D_801144AC is 0 (the book then faces the camera), back otherwise. */
void func_8010D6E8_38A398_name_5B(s16* arg0) {
    Ovl5BCamStep* step = (Ovl5BCamStep*)arg0;
    f32 screen[2];
    f32 t;
    f32 x, y, z;

    if (step->frame == 0) {
        screen[0] = 316.0f;
        screen[1] = 208.0f;
        if (D_801144AC_39115C_name_5B == 0) {
            func_8010A53C_3871EC_name_5B(15, 145.0f, screen, &step->to);
            step->from.x = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.x;
            step->from.y = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.y;
            step->from.z = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.z;
        } else {
            func_8010A53C_3871EC_name_5B(15, 145.0f, screen, &step->from);
            step->to = D_801144B4_391164_name_5B;
        }
    }
    t = HuMathSin(step->frame * 90.0f / step->len);
    x = t * (step->to.x - step->from.x) + step->from.x;
    y = t * (step->to.y - step->from.y) + step->from.y;
    z = t * (step->to.z - step->from.z) + step->from.z;
    func_80029714_2A314(D_801144AE_39115E_name_5B, x, y, z);
    func_80029714_2A314(D_801144B0_391160_name_5B[0], x, 104.0f, z);
    if (D_801144AC_39115C_name_5B == 0) {
        func_8002979C_2A39C(D_801144AE_39115E_name_5B, D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
    }
}

/* Toggles the record book's mono/stereo switch (D_80114860; flag 2 set = stereo): plays the
   switch motion forwards (mono) or backwards (stereo), then its idle motion for the new state. */
void func_8010D8B0_38A560_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[12];

    D_80114860_391510_name_5B ^= 1;
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[14]);
    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
    if (D_80114860_391510_name_5B != 0) {
        _ClearFlag(2);
        func_8000EA88_F688(1);
        while (func_80029CE4_2A8E4(model) != func_80029D0C_2A90C(model)) {
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[13]);
    } else {
        _SetFlag(2);
        func_8000EA88_F688(0);
        func_80029C74_2A874(model, func_80029D0C_2A90C(model));
        func_80029E80_2AA80(model, 4, 4);
        while (func_80029CE4_2A8E4(model) != 0.0f) {
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[12]);
    }
    func_80029E80_2AA80(model, 2, 2);
}

/* Leaves the menu for overlay 0x61 through models [7] and [8]: [8] plays its motion, then both
   shake for 100 frames (rumble every 8) while the music fades and a white wipe closes at frame
   60. Sets flag 0x1A; returns to 5B's entry 2 afterwards (history). Does not return. */
void func_8010DA34_38A6E4_name_5B(void) {
    s16 model = D_80114758_391408_name_5B[8];
    f32 shake = 1.0f;
    f32 x, y, z;
    f32 sx, sz;
    s16 i;

    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[8]);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], shake);
    PlaySound(0xB9);
    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
        HuPrcVSleep();
    }
    PlaySound(0xBA);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], 3.0f);
    x = D_800FC834_FD434[model].pos.x;
    y = D_800FC834_FD434[model].pos.y;
    z = D_800FC834_FD434[model].pos.z;
    for (i = 0; i < 100; i++) {
        if ((i & 7) == 0) {
            func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
        }
        sx = x + shake;
        sz = z + shake;
        func_80029714_2A314(D_80114758_391408_name_5B[7], sx, y, sz);
        func_80029714_2A314(model, sx, y, sz);
        shake = -shake;
        if (i == 60) {
            func_80079614_7A214(70);
            func_800794A8_7A0A8(80);
            func_8008F624_90224(0xFF, 0xFF, 0xFF);
            InitFadeOut(0, 40);
        }
        HuPrcVSleep();
    }
    _SetFlag(0x1A);
    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
    D_8011269A_38F34A_name_5B = 1;
    HuPrcSleep(3);
    if (D_801134D0_390180_name_5B[0] != 0) {
        func_8007DF5C_7EB5C();
    }
    omOvlHisChg(0, 0x5B, 2, 0x1014);
    D_80114850_391500_name_5B = 2;
    D_8011473A_3913EA_name_5B = 0x61;
    D_80112690_38F340_name_5B = 1;
    while (1) {
        HuPrcVSleep();
    }
}

/* The host's idle process (model [23], its parts [21] and [22]): every 30-120 frames picks the
   next idle motion; on screen 6 with D_80113490 set it alternates motions 25 (played to its end)
   and 26 (looping) instead. Restarts when D_80114730[0] is set or D_80113490 changes. */
void func_8010DCAC_38A95C_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[23];
    s16 timer = 0;
    s16 state = 0;
    s16 prev;
    s16 next;
    f32 stop;

    D_80113490_390140_name_5B = 0;
    while (1) {
        prev = D_80113490_390140_name_5B;
        HuPrcVSleep();
        if (D_80113838_3904E8_name_5B == 0) {
            continue;
        }
        if (D_80114730_3913E0_name_5B[0] != 0 || prev != D_80113490_390140_name_5B) {
            state = 0;
            timer = 0;
        }
        if (timer == 0) {
            timer = (rand8() & 3) * 30 + 30;
            next = state + 1;
            state = (next < 2) ? next : 0;
            if (D_80113490_390140_name_5B != 0 && D_80114738_3913E8_name_5B == 6) {
                if (state == 0) {
                    func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[25], 0, 10, 0);
                    timer = func_8002CA14_2D614(D_801147D0_391480_name_5B[25]);
                } else {
                    func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[26], 0, 10, 2);
                    timer = -1;
                }
                func_80029FE4_2ABE4(D_80114758_391408_name_5B[21], stop = 0.0f);
                func_80029FE4_2ABE4(D_80114758_391408_name_5B[22], stop);
            } else {
                if (state == 1 && (rand8() & 3) != 0) {
                    state = 0;
                }
                switch (state) {
                    case 0:
                        func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[23], 0, 10, 2);
                        func_80029FE4_2ABE4(D_80114758_391408_name_5B[21], 1.0f);
                        func_80029FE4_2ABE4(D_80114758_391408_name_5B[22], 1.0f);
                        break;
                    case 1:
                        func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[24], 0, 10, 2);
                        func_80029FE4_2ABE4(D_80114758_391408_name_5B[21], 3.0f);
                        func_80029FE4_2ABE4(D_80114758_391408_name_5B[22], 3.0f);
                        break;
                }
            }
        }
        if (timer >= 0) {
            timer--;
        }
    }
}


__asm__(".section .rodata");
const char D_801139B4_390664_name_5B[] = "item_hook";

/* The records screen: the host (model [23]) pulls out the record board (model [41], hung on its
   "item_hook"; [21], [22] stop) while the title sprite D_801144A6 grows from the board to
   (160, 28). Pages 0-3 (8010E618, 8010ED80, 8010F734, 801101E8; page 3 only once
   func_80068040(0x38)) turn with C-left/C-right (2/1) and wrap; B (0x4000) puts the board away
   and restores the host's motion. D_80113838 is 0 meanwhile (the idle process 8010DCAC waits). */
void func_8010DF24_38ABD4_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[23];
    s32 btn = 0;
    s16 motion;
    s16 frame;
    s16 n;
    s16 page;
    f32 scale;
    Vec2f scr;
    Vec2f pos;
    f32 mtx[4][4];

    D_80113838_3904E8_name_5B = 0;
    motion = func_80029E14_2AA14(model);
    func_8002C628_2D228(D_80114758_391408_name_5B[41], model, D_801139B4_390664_name_5B);
    func_80029E80_2AA80(D_80114758_391408_name_5B[21], 1, 1);
    func_80029E80_2AA80(D_80114758_391408_name_5B[22], 1, 1);
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[27]);
    scale = 1.0f;
    n = 0;
    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
        frame = func_80029CE4_2A8E4(model);
        if (frame == 40) {
            PlaySound(0x9F);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 4, 0);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 0x4000, 0x4000);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[22], 4, 4);
        }
        if (frame > 50 && frame < 90) {
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 0x4000, 0);
            espDispOn(D_801144A6_391156_name_5B);
            func_80023554_24154(model, func_80029CE4_2A8E4(model), D_801139B4_390664_name_5B, mtx);
            func_8010A8F4_3875A4_name_5B(model, &scr, mtx);
            espPosSet(D_801144A6_391156_name_5B, scr.unk_00, scr.unk_04);
            func_8001A91C_1B51C(D_801144A6_391156_name_5B, scale, scale);
            scale += 0.34f;
        }
        if (frame >= 90) {
            pos.unk_00 = (160.0f - scr.unk_00) / 5.0f * n + scr.unk_00;
            pos.unk_04 = (28.0f - scr.unk_04) / 5.0f * n + scr.unk_04;
            espPosSet(D_801144A6_391156_name_5B, pos.unk_00, pos.unk_04);
            n++;
            func_8001A91C_1B51C(D_801144A6_391156_name_5B, scale, scale);
            scale += 0.34f;
        }
        HuPrcVSleep();
    }
    espPosSet(D_801144A6_391156_name_5B, 160, 28);
    func_8001A91C_1B51C(D_801144A6_391156_name_5B, 8.5f, 8.5f);
    HuPrcVSleep();
    page = 0;
    while (1) {
        switch (page) {
            case 0:
                btn = func_8010E618_38B2C8_name_5B();
                break;
            case 1:
                btn = func_8010ED80_38BA30_name_5B();
                break;
            case 2:
                btn = func_8010F734_38C3E4_name_5B();
                break;
            case 3:
                btn = func_801101E8_38CE98_name_5B();
                break;
        }
        HuPrcSleep(4);
        if (btn & 0x4000) {
            break;
        }
        if (btn & 2) {
            page--;
            if (page < 0) {
                page = func_80068040_68C40(0x38) ? 3 : 2;
            }
        } else if (btn & 1) {
            page++;
            if (func_80068040_68C40(0x38)) {
                page = (page < 4) ? page : 0;
            } else {
                page = (page < 3) ? page : 0;
            }
        }
    }
    func_80029C74_2A874(model, func_80029D0C_2A90C(model));
    func_80029E80_2AA80(model, 4, 4);
    while (func_80029CE4_2A8E4(model) != 0.0f) {
        if (func_80029CE4_2A8E4(model) == 40.0f) {
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 0x4000, 0);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 4, 4);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[22], 4, 0);
        }
        if (func_80029CE4_2A8E4(model) == 50.0f) {
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 0x4000, 0x4000);
            espDispOff(D_801144A6_391156_name_5B);
        }
        if (func_80029CE4_2A8E4(model) > 50.0f) {
            func_800298A4_2A4A4(D_80114758_391408_name_5B[41], 0x4000, 0);
            espDispOn(D_801144A6_391156_name_5B);
            func_80023554_24154(model, func_80029CE4_2A8E4(model), D_801139B4_390664_name_5B, mtx);
            func_8010A8F4_3875A4_name_5B(model, &scr, mtx);
            espPosSet(D_801144A6_391156_name_5B, scr.unk_00, scr.unk_04);
            func_8001A91C_1B51C(D_801144A6_391156_name_5B, scale, scale);
            scale -= 0.34f;
        }
        HuPrcVSleep();
    }
    if (motion == D_801147D0_391480_name_5B[25] || motion == D_801147D0_391480_name_5B[26]) {
        motion = D_801147D0_391480_name_5B[23];
    }
    func_80029BF0_2A7F0(model, motion, 0, 10, 2);
    func_80029E80_2AA80(D_80114758_391408_name_5B[21], 1, 0);
    func_80029E80_2AA80(D_80114758_391408_name_5B[22], 1, 0);
    D_80113838_3904E8_name_5B = 1;
}


__asm__(".section .rodata");
const char D_801139C0_390670_name_5B[] = "%d";

/* Records page 0: the six boards (D_8011383C order; their names D_80113848) with each board's
   record GwCommon.boardRecord[b][0] (capped at 999, right-aligned in 3 with 0x1A); the last board
   only when D_80114740 is set. Fades in, waits for B or C-left/C-right (or the stick past 30),
   fades out (the alpha goes negative: retail's (s16)(i * -50) wraps to 206..6) and returns the
   button (0x4000, 2, 1). */
#ifdef NON_MATCHING
/* NON_MATCHING: register allocation in the first two loops (retail keeps the sprite and window
   ids in fewer callee-saved registers); masked 17. */
s32 func_8010E618_38B2C8_name_5B(void) {
    s16 win[6];
    char text[6][8];
    char buf[8];
    s16 anim[6];
    u16 spr[6];
    s16 titleAnim;
    u16 sp;
    s32 w;
    u16 title;
    s16 i;
    s16 j;
    s16 k;
    s16 c;
    s16 len;
    s16 n;
    s16 left;
    s16 right;
    s32 btn;
    f32 alpha;

    titleAnim = func_8001A2F8_1AEF8(0x9004E);
    title = func_8001AAAC_1B6AC(titleAnim, 0, 1);
    espPosSet(title, 160, 38);
    func_8001A6BC_1B2BC(title, 0);
    for (i = 0; i < 6; i++) {
        anim[i] = func_8001A2F8_1AEF8(D_80113848_3904F8_name_5B[i]);
        spr[i] = func_8001AAAC_1B6AC(anim[i], 0, 1);
        sp = spr[i];
        espPosSet(sp, 54, i * 23 + 59);
        func_8001A6BC_1B2BC(sp, 0);
    }
    for (i = 0; i < 6; i++) {
        w = win[i] = func_800888A8_894A8(84, i * 23 + 49, 220, 20, 0, 8);
        func_80089A7C_8A67C(w, 5);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089DA0_8A9A0(w, 0xC0, 0xC0, 0xC0);
        n = D_800F8C60.boardRecord[D_8011383C_3904EC_name_5B[i]][0];
        if ((s16)D_800F8C60.boardRecord[D_8011383C_3904EC_name_5B[i]][0] >= 1000) {
            n = 999;
        }
        sprintf(buf, D_801139C0_390670_name_5B, n);
        len = func_800A5610_A6210(buf);
        k = 0;
        for (c = 0; c < 3 - len; c++) {
            text[i][k++] = 0x1A;
        }
        for (c = 0; c < len; c++) {
            text[i][k++] = buf[c];
        }
        text[i][k] = 0;
        func_80089308_89F08(w, text[i], 0);
        func_800890CC_89CCC(w, i + 0x52E, -1, -1);
    }
    if (D_80114740_3913F0_name_5B == 0) {
        espDispOff(spr[5]);
        func_8008D5D8_8E1D8(win[5]);
    }
    left = func_80110770_38D420_name_5B(60, 184);
    right = func_8011083C_38D4EC_name_5B(60, 196);
    HuPrcVSleep();
    func_8008D6F0_8E2F0(left);
    func_8008D6F0_8E2F0(right);
    for (i = 0; i < 6; i++) {
        alpha = i * 51.0f;
        func_8001A6BC_1B2BC(title, alpha);
        for (j = 0; j < 6; j++) {
            func_8001A6BC_1B2BC(spr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_80089BBC_8A7BC(win[j], (s16)alpha);
        }
        func_80089BBC_8A7BC(left, (s16)alpha);
        func_80089BBC_8A7BC(right, (s16)alpha);
        HuPrcVSleep();
    }
    while (1) {
        btn = ContBtnTrg[D_80114862_391512_name_5B] & 0x4003;
        if (btn != 0) {
            break;
        }
        if (ContStkX[D_80114862_391512_name_5B] < -30) {
            btn = 2;
            break;
        }
        if (ContStkX[D_80114862_391512_name_5B] > 30) {
            btn = 1;
            break;
        }
        HuPrcVSleep();
    }
    PlaySound((btn & 0x4000) ? 4 : 1);
    for (i = 1; i < 6; i++) {
        alpha = i * -50.0f;
        func_8001A6BC_1B2BC(title, alpha);
        for (j = 0; j < 6; j++) {
            func_8001A6BC_1B2BC(spr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_80089BBC_8A7BC(win[j], (s16)alpha);
        }
        func_80089BBC_8A7BC(left, (s16)alpha);
        func_80089BBC_8A7BC(right, (s16)alpha);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(title);
    SprAnimKill(titleAnim);
    for (i = 0; i < 6; i++) {
        func_8008CCA8_8D8A8(win[i]);
        func_8001AC44_1B844(spr[i]);
        SprAnimKill(anim[i]);
    }
    func_8008CCA8_8D8A8(left);
    func_8008CCA8_8D8A8(right);
    return btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010E618_38B2C8_name_5B);
#endif

/* Records page 1: wins per character (rows, D_80113864 icons) and board (columns, D_80113848
   names in D_8011383C order; the last board only when D_80114740 is set), each capped at 99,
   with each row's total. Fades in, waits for B or C-left/C-right (or the stick past 30), fades
   out and returns the button (0x4000, 2, 1), as 8010E618. */
#ifdef NON_MATCHING
/* NON_MATCHING: register allocation (retail's func_8001A2F8/func_8001AAAC results are not
   re-extended: s32 returns here) and the wins table address form; masked 44. The asm path
   carries D_801139C4 ("  ") in its own .s. */
__asm__(".section .rodata");
const char D_801139C4_390674_name_5B[] = "  ";

s32 func_8010ED80_38BA30_name_5B(void) {
    s16 win[6];
    s16 boardAnim[7];
    s16 charAnim[6];
    s16 boardSpr[7];
    s16 charSpr[6];
    char text[8][32];
    char buf[8];
    s16 titleAnim;
    s16 title;
    s32 sp;
    s32 w;
    s16 i;
    s16 j;
    s16 k;
    s16 c;
    s16 len;
    s16 sum;
    s32 n;
    s16 left;
    s16 right;
    s32 btn;
    f32 alpha;

    titleAnim = func_8001A2F8_1AEF8(0x9004F);
    title = func_8001AAAC_1B6AC(titleAnim, 0, 1);
    espPosSet(title, 160, 38);
    func_8001A6BC_1B2BC(title, 0);
    for (i = 0; i < 7; i++) {
        sp = func_8001AAAC_1B6AC(boardAnim[i] = func_8001A2F8_1AEF8(D_80113848_3904F8_name_5B[i]), 0, 1);
        boardSpr[i] = sp;
        espPosSet(sp, i * 30 + 82, 58);
        func_8001A6BC_1B2BC(sp, 0);
    }
    espPosSet(sp, 272, 58);
    for (i = 0; i < 6; i++) {
        sp = func_8001AAAC_1B6AC(charAnim[i] = func_8001A2F8_1AEF8(D_80113864_390514_name_5B[i]), 0, 1);
        charSpr[i] = sp;
        espPosSet(sp, 47, i * 20 + 76);
        func_8001A6BC_1B2BC(sp, 0);
    }
    for (i = 0; i < 6; i++) {
        w = func_800888A8_894A8(62, i * 20 + 66, 230, 22, 0, 8);
        win[i] = w;
        func_80089A7C_8A67C(w, 5);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089CAC_8A8AC(w, 4, 0, 0xA0, 0);
        func_80089DA0_8A9A0(w, 0xC0, 0xC0, 0xC0);
        sum = 0;
        k = 0;
        for (j = 0; j < 7; j++) {
            if (j != 6) {
                if (j == 5 && D_80114740_3913F0_name_5B == 0) {
                    sprintf(buf, D_801139C4_390674_name_5B);
                } else {
                    text[i][k++] = (j & 1) ? 4 : 2;
                    /* the wins: boardRecord[b] bytes 2-7 (Ovl5BBoardRecord.wins) */
                    n = ((u8*)&D_800F8C60.boardRecord[D_8011383C_3904EC_name_5B[j]][1])[i];
                    if (n >= 100) {
                        n = 99;
                    }
                    sum += n;
                    sprintf(buf, D_801139C0_390670_name_5B, n);
                }
            } else {
                text[i][k++] = 0x1A;
                text[i][k++] = 5;
                sprintf(buf, D_801139C0_390670_name_5B, sum);
            }
            len = func_800A5610_A6210(buf);
            for (c = 0; c < 3 - len; c++) {
                text[i][k++] = 0x1A;
            }
            for (c = 0; c < len; c++) {
                text[i][k++] = buf[c];
            }
        }
        text[i][k] = 0;
        func_800890CC_89CCC(w, (s32)text[i], -1, -1); /* a string pointer in an s32 */
    }
    left = func_80110770_38D420_name_5B(60, 184);
    right = func_8011083C_38D4EC_name_5B(60, 196);
    if (D_80114740_3913F0_name_5B == 0) {
        espDispOff(boardSpr[5]);
    }
    HuPrcVSleep();
    func_8008D6F0_8E2F0(left);
    func_8008D6F0_8E2F0(right);
    for (i = 0; i < 6; i++) {
        alpha = i * 51.0f;
        func_8001A6BC_1B2BC(title, alpha);
        for (j = 0; j < 7; j++) {
            func_8001A6BC_1B2BC(boardSpr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_8001A6BC_1B2BC(charSpr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_80089BBC_8A7BC(win[j], (s16)alpha);
        }
        func_80089BBC_8A7BC(left, (s16)alpha);
        func_80089BBC_8A7BC(right, (s16)alpha);
        HuPrcVSleep();
    }
    while (1) {
        btn = ContBtnTrg[D_80114862_391512_name_5B] & 0x4003;
        if (btn != 0) {
            break;
        }
        if (ContStkX[D_80114862_391512_name_5B] < -30) {
            btn = 2;
            break;
        }
        if (ContStkX[D_80114862_391512_name_5B] > 30) {
            btn = 1;
            break;
        }
        HuPrcVSleep();
    }
    PlaySound((btn & 0x4000) ? 4 : 1);
    for (i = 1; i < 6; i++) {
        alpha = i * -50.0f;
        func_8001A6BC_1B2BC(title, alpha);
        for (j = 0; j < 7; j++) {
            func_8001A6BC_1B2BC(boardSpr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_8001A6BC_1B2BC(charSpr[j], alpha);
        }
        for (j = 0; j < 6; j++) {
            func_80089BBC_8A7BC(win[j], (s16)alpha);
        }
        func_80089BBC_8A7BC(left, (s16)alpha);
        func_80089BBC_8A7BC(right, (s16)alpha);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(title);
    SprAnimKill(titleAnim);
    for (i = 0; i < 6; i++) {
        func_8008CCA8_8D8A8(win[i]);
        func_8001AC44_1B844(charSpr[i]);
        SprAnimKill(charAnim[i]);
    }
    for (i = 0; i < 7; i++) {
        func_8001AC44_1B844(boardSpr[i]);
        SprAnimKill(boardAnim[i]);
    }
    func_8008CCA8_8D8A8(left);
    func_8008CCA8_8D8A8(right);
    return btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ED80_38BA30_name_5B);
#endif



__asm__(".section .rodata");
const char D_801139C8_390678_name_5B[] = "\x05%d\x05";

__asm__(".section .rodata");
const char D_801139D0_390680_name_5B[] = "\x05%02d\x05";

s32 func_8010F734_38C3E4_name_5B(void) {
    s16 win[7];
    char buf[21][32];
    u16 grp;
    s16 spr;
    s16 i;
    s16 j;
    s16 t;
    s16 hi;
    s16 rest;
    s16 mid;
    s32 w;
    f32 val;
    s16 win1;
    s16 win2;
    s16 btn;
    f32 fade;

    grp = func_8001A2F8_1AEF8(0x90052);
    spr = func_8001AAAC_1B6AC(grp, 0, 1);
    espPosSet(spr, 160, 38);
    func_8001A6BC_1B2BC(spr, 0);
    for (i = 0; i < 7; i++) {
        win[i] = w = func_800888A8_894A8(54, i * 17 + 58, 260, 22, 0, 8);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089A7C_8A67C(w, 5);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089CAC_8A8AC(w, 4, 0, 160, 0);
        func_80089DA0_8A9A0(w, 192, 192, 192);
        if (func_80067F4C_68B4C((s16)D_8011387C_39052C_name_5B[i]) == 0) {
            func_800890CC_89CCC(w, 0x3A2, -1, -1);
        } else {
            switch (i) {
            case 0:
                t = func_800680D4_68CD4(1);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 1:
                t = func_800680D4_68CD4(2);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 2:
                t = func_800680D4_68CD4(3);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 3:
                t = func_800680D4_68CD4(4);
                if (t == 0) {
                    t = 0x1400;
                }
                hi = t >> 8;
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi);
                func_80089308_89F08(w, buf[i * 3], 0);
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, t & 0xFF);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                break;
            case 4:
                t = func_800680D4_68CD4(5);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 5:
                t = func_800680D4_68CD4(6);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 6:
                t = func_800680D4_68CD4(7);
                sprintf(buf[i * 3], D_801139C8_390678_name_5B, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            }
            func_800890CC_89CCC(w, i + 0x3A3, -1, -1);
        }
    }
    win1 = func_80110770_38D420_name_5B(60, 184);
    win2 = func_8011083C_38D4EC_name_5B(60, 196);
    HuPrcVSleep();
    func_8008D6F0_8E2F0(win1);
    func_8008D6F0_8E2F0(win2);
    for (i = 0; i < 6; i++) {
        fade = i * 51.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 7; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    while (1) {
        btn = ContBtnTrg[D_80114862_391512_name_5B] & 0x4003;
        if (btn == 0) {
            if (ContStkX[D_80114862_391512_name_5B] < -30) {
                btn = 2;
            } else if (ContStkX[D_80114862_391512_name_5B] > 30) {
                btn = 1;
            } else {
                HuPrcVSleep();
                continue;
            }
        }
        break;
    }
    if (btn & 0x4000) {
        PlaySound(4);
    } else {
        PlaySound(1);
    }
    for (i = 1; i < 6; i++) {
        fade = i * -50.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 7; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(spr);
    SprAnimKill(grp);
    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8(win[i]);
    }
    func_8008CCA8_8D8A8(win1);
    func_8008CCA8_8D8A8(win2);
    return btn;
}

s32 func_801101E8_38CE98_name_5B(void) {
    s16 win[5];
    char buf[15][32];
    u16 grp;
    s16 spr;
    s16 i;
    s16 j;
    s16 t;
    s16 w;
    s16 win1;
    s16 win2;
    s16 btn;
    s16 n;
    f32 fade;

    grp = func_8001A2F8_1AEF8(0x90053);
    spr = func_8001AAAC_1B6AC(grp, 0, 1);
    espPosSet(spr, 160, 38);
    func_8001A6BC_1B2BC(spr, 0);
    for (i = 0; i < 5; i++) {
        w = win[i] = func_800888A8_894A8(35, i * 20 + 58, 250, 22, 0, 8);
        func_80089A7C_8A67C(w, 5);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089CAC_8A8AC(w, 4, 0, 160, 0);
        func_80089DA0_8A9A0(w, 192, 192, 192);
        t = func_800680D4_68CD4((s16)(i + 8));
        n = t == 0;
        sprintf(buf[i * 3], D_801139C8_390678_name_5B, n);
        func_80089308_89F08(w, buf[i * 3], 0);
        n = (t >> 12) * 10 + ((t & 0xF00) >> 8);
        sprintf(buf[i * 3 + 1], D_801139D0_390680_name_5B, n);
        func_80089308_89F08(w, buf[i * 3 + 1], 1);
        n = ((t & 0xF0) >> 4) * 10 + (t & 0xF);
        sprintf(buf[i * 3 + 2], D_801139D0_390680_name_5B, n);
        func_80089308_89F08(w, buf[i * 3 + 2], 2);
        func_800890CC_89CCC(w, i + 0x3AA, -1, -1);
    }
    win1 = func_80110770_38D420_name_5B(60, 184);
    win2 = func_8011083C_38D4EC_name_5B(60, 196);
    HuPrcVSleep();
    func_8008D6F0_8E2F0(win1);
    func_8008D6F0_8E2F0(win2);
    for (i = 0; i < 6; i++) {
        fade = i * 51.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 5; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    while (1) {
        btn = ContBtnTrg[D_80114862_391512_name_5B] & 0x4003;
        if (btn == 0) {
            if (ContStkX[D_80114862_391512_name_5B] < -30) {
                btn = 2;
            } else if (ContStkX[D_80114862_391512_name_5B] > 30) {
                btn = 1;
            } else {
                HuPrcVSleep();
                continue;
            }
        }
        break;
    }
    if (btn & 0x4000) {
        PlaySound(4);
    } else {
        PlaySound(1);
    }
    for (i = 1; i < 6; i++) {
        fade = i * -50.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 5; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(spr);
    SprAnimKill(grp);
    for (i = 0; i < 5; i++) {
        func_8008CCA8_8D8A8(win[i]);
    }
    func_8008CCA8_8D8A8(win1);
    func_8008CCA8_8D8A8(win2);
    return btn;
}

s16 func_80110770_38D420_name_5B(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 32, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_8008D5D8_8E1D8(win);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, 0x534, -2, -1);
    return win;
}

s16 func_8011083C_38D4EC_name_5B(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 20, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_8008D5D8_8E1D8(win);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, 0x535, -2, -1);
    return win;
}


__asm__(".section .rodata");
const char D_801139F4_3906A4_name_5B[28] = "c168_000-atama";

void func_80110908_38D5B8_name_5B(void) {
    s16 model = (u16)D_80114758_391408_name_5B[0x20];
    s16 prev;
    HmfMotionObj* mot;

    while (1) {
        prev = D_80113492_390142_name_5B;
        HuPrcVSleep();
        if (D_80113898_390548_name_5B[0] != 0 && D_80114730_3913E0_name_5B[0] != 0) {
            if (D_801148A4_391554_name_5B == 6 && D_80114738_3913E8_name_5B == D_801148A4_391554_name_5B) {
                func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 10, 2);
            } else {
                func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x20], 0, 10, 2);
            }
        }
        if (prev == D_80113492_390142_name_5B) {
            continue;
        }
        if (D_80113492_390142_name_5B != 0) {
            func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x20], 0, 10, 2);
            func_80029E80_2AA80(model, 2, 2);
            func_8003B72C_3C32C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x45);
            func_8003B72C_3C32C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x46);
            mot = func_8002A9F4_2B5F4(model, D_801139F4_3906A4_name_5B);
            mot->unk10.y = 13.0f;
            mot->unk10.x = -10.0f;
        } else {
            func_8003B76C_3C36C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x45);
            func_8003B76C_3C36C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x46);
            func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 10, 2);
        }
    }
}

void func_80110AF8_38D7A8_name_5B(void) {
    f32 mtx[4][4];
    Vec a;
    Vec b;
    Vec c;
    u16 host;
    u16 player;
    s16 i;
    s16 j;
    s16 r;
    f32 rot;
    f32 scale;
    f32 rotY;
    f32 baseY;
    f32 s;
    f32 savedRotY;

    host = D_80114758_391408_name_5B[0x17];
    player = D_80114758_391408_name_5B[0x20];
    D_80113838_3904E8_name_5B = 0;
    D_80113898_390548_name_5B[0] = 0;
    func_80108788_385438_name_5B(0x11, 10, 1, (void (*)(s16*))-1);
    func_8002C628_2D228(D_80114758_391408_name_5B[0x29], host, D_801139B4_390664_name_5B);
    func_8002C628_2D228(D_80114758_391408_name_5B[0x2A], host, D_801139B4_390664_name_5B);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x15], 1, 1);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x16], 1, 1);
    func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x1C], 0, 5, 0);
    for (i = 0; i < 35; i++) {
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 0x4000);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x16], 4, 4);
    PlaySound(0xB4);
    for (i = 0; i < 30; i++) {
        HuPrcVSleep();
    }
    PlaySound(0xB4);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 4);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4004, 0x4000);
    while (func_80029CE4_2A8E4(host) < func_80029D0C_2A90C(host)) {
        HuPrcVSleep();
    }
    func_8008AD44_8B944(D_801144A2_391152_name_5B);
    func_8008E978_8F578(D_801144A2_391152_name_5B);
    r = func_8010B5A8_388258_name_5B(D_801144A2_391152_name_5B, 0x4F8, 0);
    if (r == -1 || r == 0) {
        func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
        func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x1E], 0, 5, 0);
        for (i = 0; i < 19; i++) {
            HuPrcVSleep();
        }
        PlaySound(0xB5);
        func_80023554_24154(host, 0x26, D_801139B4_390664_name_5B, mtx);
        func_8010A7F4_3874A4_name_5B(host, &a, mtx);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4000, 0);
        func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x17], 0, 5, 2);
        func_80029BF0_2A7F0(player, D_801147D0_391480_name_5B[0x24], 0, 10, 0);
        D_800FC834_FD434[(s16)player].unk50 = 4.0f;
        b.x = 2229.0f;
        b.y = D_800FC834_FD434[D_80114758_391408_name_5B[0xC]].pos.y + 20.0f;
        b.z = 989.0f;
        rot = D_800FC834_FD434[D_80114758_391408_name_5B[0x2A]].rot.x;
        for (i = 0; i < 25; i++) {
            c.x = (b.x - a.x) / 20.0f * i + a.x;
            c.y = (b.y - a.y) / 20.0f * i + a.y;
            c.y += HuMathSin(i * 9.0f) * 150.0f;
            if (c.y < b.y) {
                c.y = b.y;
            }
            c.z = (b.z - a.z) / 20.0f * i + a.z;
            func_80029714_2A314(D_80114758_391408_name_5B[0x2A], c.x, c.y, c.z);
            rot += 20.0f;
            if (rot > 360.0f) {
                rot -= 360.0f;
            }
            D_800FC834_FD434[D_80114758_391408_name_5B[0x2A]].rot.x = rot;
            HuPrcVSleep();
        }
        HuPrcSleep(30);
        func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x1E], 45, 15, 0);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 0x4000);
        PlaySound(0xBE);
        for (i = 0; i < 50; i++) {
            HuPrcVSleep();
        }
        func_80029E80_2AA80(host, 1, 1);
        func_8008AD44_8B944(D_801144A2_391152_name_5B);
        func_8008E978_8F578(D_801144A2_391152_name_5B);
        func_800890CC_89CCC(D_801144A2_391152_name_5B, 0x4F9, -1, -1);
        D_800FC834_FD434[(s16)player].unk50 = 1.0f;
        func_80029BF0_2A7F0(player, D_801147D0_391480_name_5B[0x20], 0, 10, 2);
        while (func_8008BA30_8C630(D_801144A2_391152_name_5B) != 0) {
            HuPrcVSleep();
        }
        func_80029E80_2AA80(host, 1, 0);
        while (func_80029CE4_2A8E4(host) < 190.0f) {
            HuPrcVSleep();
        }
        func_800298A4_2A4A4(D_80114758_391408_name_5B[0x16], 4, 0);
        func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
        func_80112094_38ED44_name_5B(0);
        return;
    }
    func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
    func_8002C9C0_2D5C0(host, D_801147D0_391480_name_5B[0x1D]);
    func_8002C9C0_2D5C0(player, D_801147D0_391480_name_5B[0x27]);
    func_80023554_24154(host, 0x28, D_801139B4_390664_name_5B, mtx);
    func_8010A7F4_3874A4_name_5B(host, &a, mtx);
    func_80023554_24154(player, 0x32, D_801139B4_390664_name_5B, mtx);
    func_8010A7F4_3874A4_name_5B(player, &b, mtx);
    for (i = 0; i < 20; i++) {
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4000, 0);
    rot = D_800FC834_FD434[D_80114758_391408_name_5B[0x2A]].rot.x;
    PlaySound(0xA0);
    for (i = 0; i < 15; i++) {
        c.x = (b.x - a.x) / 15.0f * i + a.x;
        c.y = (b.y - a.y) / 15.0f * i + a.y;
        c.y += HuMathSin(i * 12.0f) * 150.0f;
        c.z = (b.z - a.z) / 15.0f * i + a.z;
        func_80029714_2A314(D_80114758_391408_name_5B[0x2A], c.x, c.y, c.z);
        rot += 20.0f;
        if (rot > 360.0f) {
            rot -= 360.0f;
        }
        D_800FC834_FD434[D_80114758_391408_name_5B[0x2A]].rot.x = rot;
        HuPrcVSleep();
    }
    func_8002C628_2D228(D_80114758_391408_name_5B[0x2A], player, D_801139B4_390664_name_5B);
    func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x17], 0, 5, 0);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4000, 0x4000);
    func_80029E80_2AA80(player, 4, 4);
    while (func_80029CE4_2A8E4(player) > 0.0f) {
        HuPrcVSleep();
    }
    func_80029BF0_2A7F0(player, D_801147D0_391480_name_5B[0x20], 0, 5, 2);
    D_80114718_3913C8_name_5B[0].x = a.x = D_800FC834_FD434[(s16)player].pos.x;
    D_80114718_3913C8_name_5B[0].y = a.y = D_800FC834_FD434[(s16)player].pos.y;
    D_80114718_3913C8_name_5B[0].z = a.z = D_800FC834_FD434[(s16)player].pos.z;
    b.x = 1953.0f;
    b.y = 0.0f;
    b.z = 1218.0f;
    for (i = 0; i < 6; i++) {
        c.x = (b.x - a.x) / 5.0f * i + a.x;
        c.y = (b.y - a.y) / 5.0f * i + a.y;
        c.y += HuMathSin(i * 36.0f) * 10.0f;
        c.z = (b.z - a.z) / 5.0f * i + a.z;
        func_80029714_2A314(player, c.x, c.y, c.z);
        func_80029714_2A314(D_80114758_391408_name_5B[0x28], c.x, 0.0f, c.z);
        HuPrcVSleep();
    }
    PlaySound(0xA1);
    func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xA], D_801147D0_391480_name_5B[0xA]);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[0xA], 2.0f);
    func_8008AD44_8B944(D_801144A2_391152_name_5B);
    func_8008E978_8F578(D_801144A2_391152_name_5B);
    func_800890CC_89CCC(D_801144A2_391152_name_5B, 0x4FA, -1, -1);
    while (1) {
        if (ContBtnTrg[D_80114862_391512_name_5B] & 0x4000) {
            func_80029BF0_2A7F0(player, D_801147D0_391480_name_5B[0x24], 0, 5, 0);
            HuPrcSleep(10);
            func_800890CC_89CCC(D_801144A2_391152_name_5B, 0x4FB, -1, -1);
            while (func_8008BA30_8C630(D_801144A2_391152_name_5B) != 0) {
                HuPrcVSleep();
            }
            func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
            func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x1A], 0, 20, 2);
            func_8008AD44_8B944(D_801144A2_391152_name_5B);
            func_8008E978_8F578(D_801144A2_391152_name_5B);
            func_800890CC_89CCC(D_801144A2_391152_name_5B, 0x4FC, -1, -1);
            while (func_8008BA30_8C630(D_801144A2_391152_name_5B) != 0) {
                HuPrcVSleep();
            }
            PlaySound(0xBE);
            func_80029BF0_2A7F0(host, D_801147D0_391480_name_5B[0x1E], 45, 15, 0);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 0x4000);
            HuPrcSleep(50);
            func_80029E80_2AA80(host, 1, 1);
            func_800890CC_89CCC(D_801144A2_391152_name_5B, 0x4FD, -1, -1);
            while (func_8008BA30_8C630(D_801144A2_391152_name_5B) != 0) {
                HuPrcVSleep();
            }
            func_80029E80_2AA80(host, 1, 0);
            func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
            func_80112094_38ED44_name_5B(1);
            return;
        }
        if (ContBtnTrg[D_80114862_391512_name_5B] & 0x1000) {
            break;
        }
        HuPrcVSleep();
    }
    func_8008D5D8_8E1D8(D_801144A2_391152_name_5B);
    a.x = D_800FC834_FD434[(s16)player].pos.x;
    a.y = D_800FC834_FD434[(s16)player].pos.y;
    a.z = D_800FC834_FD434[(s16)player].pos.z;
    savedRotY = D_800FC834_FD434[(s16)player].rot.y;
    func_801086E0_385390_name_5B(0x11);
    PlaySound(0xA2);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4000, 0x4000);
    rotY = D_800FC834_FD434[(s16)player].rot.y;
    for (j = 0; j < 1; j++) {
        func_8002C9C0_2D5C0(player, D_801147D0_391480_name_5B[0x25]);
        scale = 1.0f;
        D_800FC834_FD434[(s16)player].rot.y = rotY;
        for (i = 0; i < 11; i++) {
            func_80029714_2A314(player, a.x, HuMathSin(i * 9.0f) * 200.0f + a.y, a.z);
            scale -= 0.05f;
            func_800297E8_2A3E8(D_80114758_391408_name_5B[0x28], scale, 1.0f, scale);
            if (i == 5) {
                func_80029E80_2AA80(player, 1, 1);
            }
            if (i < 5) {
                D_800FC834_FD434[(s16)player].rot.y += 18.0f;
            }
            HuPrcVSleep();
        }
    }
    func_801086E0_385390_name_5B(0x11);
    HuPrcSleep(3);
    func_80029E80_2AA80(player, 1, 0);
    func_80023554_24154(player, 0xF, D_801139B4_390664_name_5B, mtx);
    func_8010A7F4_3874A4_name_5B(player, &b, mtx);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4000, 0);
    c.x = 1914.0f;
    c.y = 50.0f;
    c.z = 1316.0f;
    for (i = 0; i < 4; i++) {
        func_80029714_2A314(D_80114758_391408_name_5B[0x2A], (c.x - b.x) / 3.0f * i + b.x, (c.y - b.y) / 3.0f * i + b.y,
                            (c.z - b.z) / 3.0f * i + b.z);
        HuPrcVSleep();
    }
    rot = 30.0f;
    j = 0;
    baseY = D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].pos.y;
    PlaySound(0xA3);
    func_80088604_89204(D_80114862_391512_name_5B, 20, 0, 20);
    for (i = 0; i < 4; i++) {
        if (i == 2) {
            func_80029E80_2AA80(player, 1, 1);
        }
        s = HuMathSin(j * 36.0f) * rot;
        D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].pos.y = (s < 0.0f) ? baseY - s : baseY + s;
        D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].rot.x = -HuMathSin(j++ * 36.0f) * rot;
        rot -= 2.0f;
        if (rot < 0.0f) {
            break;
        }
        j++;
        HuPrcVSleep();
    }
    PlaySound(0xB6);
    func_801086E0_385390_name_5B(0x11);
    func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xA], D_801147D0_391480_name_5B[0xB]);
    PlaySound(0xB7);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeOut(0, 40);
    D_8011269A_38F34A_name_5B = 1;
    func_80029E80_2AA80(player, 1, 0);
    b.x = D_80114718_3913C8_name_5B[0].x;
    b.y = D_80114718_3913C8_name_5B[0].y;
    b.z = D_80114718_3913C8_name_5B[0].z;
    for (i = 0; i < 16; i++) {
        c.x = (b.x - a.x) / 15.0f * i + a.x;
        c.z = (b.z - a.z) / 15.0f * i + a.z;
        func_80029714_2A314(player, c.x, HuMathSin(i * 6.0f + 90.0f) * 200.0f + a.y, c.z);
        if (i == 5) {
            func_80029E80_2AA80(player, 1, 0);
        }
        D_800FC834_FD434[(s16)player].rot.y -= 6.0f;
        func_80029714_2A314(D_80114758_391408_name_5B[0x28], c.x, 0.0f, c.z);
        scale += 1.0f / 30.0f;
        func_800297E8_2A3E8(D_80114758_391408_name_5B[0x28], scale, 1.0f, scale);
        s = HuMathSin(j * 36.0f) * rot;
        D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].pos.y = (s < 0.0f) ? baseY - s : baseY + s;
        D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].rot.x = -HuMathSin(j++ * 36.0f) * rot;
        rot -= 2.0f;
        if (rot < 0.0f) {
            rot = 0.0f;
        }
        HuPrcVSleep();
    }
    D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].rot.x = 0.0f;
    D_800FC834_FD434[D_80114758_391408_name_5B[0xA]].pos.y = baseY;
    D_800FC834_FD434[(s16)player].rot.y = savedRotY;
    func_800297E8_2A3E8(D_80114758_391408_name_5B[0x28], 1.0f, 1.0f, 1.0f);
    func_80029BF0_2A7F0(player, D_801147D0_391480_name_5B[0x22], 0, 5, 2);
    func_800794A8_7A0A8(20);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_8007DCE8_7E8E8();
    D_80114850_391500_name_5B = 0;
    D_8011473A_3913EA_name_5B = 0;
    D_80112690_38F340_name_5B = 1;
    func_80112094_38ED44_name_5B(0);
    while (1) {
        HuPrcVSleep();
    }
}

void func_80112094_38ED44_name_5B(s32 jump) {
    u16 model = D_80114758_391408_name_5B[0x20];
    s16 i;
    Vec start;
    Vec end;
    Vec cur;

    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4004, 4);
    func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 5, 2);
    if (jump != 0) {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xA], D_801147D0_391480_name_5B[0xB]);
        PlaySound(0xB7);
        start.x = D_800FC834_FD434[(s16)model].pos.x;
        start.y = D_800FC834_FD434[(s16)model].pos.y;
        start.z = D_800FC834_FD434[(s16)model].pos.z;
        end.x = D_80114718_3913C8_name_5B[0].x;
        end.y = D_80114718_3913C8_name_5B[0].y;
        end.z = D_80114718_3913C8_name_5B[0].z;
        for (i = 0; i < 6; i++) {
            cur.x = (end.x - start.x) / 5.0f * i + start.x;
            cur.y = (end.y - start.y) / 5.0f * i + start.y;
            cur.y += HuMathSin(i * 36.0f) * 10.0f;
            cur.z = (end.z - start.z) / 5.0f * i + start.z;
            func_80029714_2A314(model, cur.x, cur.y, cur.z);
            func_80029714_2A314(D_80114758_391408_name_5B[0x28], cur.x, 0.0f, cur.z);
            HuPrcVSleep();
        }
    }
    func_80108788_385438_name_5B(0x10, 10, 1, (void (*)(s16*))-1);
    D_80113838_3904E8_name_5B = 1;
    D_80113898_390548_name_5B[0] = 1;
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 4);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x16], 4, 0);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x15], 1, 0);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x16], 1, 0);
}

void func_80112304_38EFB4_name_5B(void) {
    s16 cat;
    s16 i;

    for (i = 0; i < 9; i++) {
        D_80113F40_390BF0_name_5B[i] = D_80113F58_390C08_name_5B[i] = D_80113F70_390C20_name_5B[i] = 0;
    }
    D_801144A0_391150_name_5B = 0;
    D_80113F86_390C36_name_5B = 0;
    D_80113F84_390C34_name_5B = 0;
    D_80113F82_390C32_name_5B = 0;
    for (i = 0; i < 72; i++) {
        if (D_800CAD90[i].unk_00 == 0 || i == 15) {
            continue;
        }
        if (i == 0x22) {
            continue;
        }
        cat = D_800CAD90[i].unk_04;
        if (func_80067F4C_68B4C(i) != 0) {
            if (func_80068040_68C40(i) != 0) {
                D_80113F90_390C40_name_5B[cat][D_80113F70_390C20_name_5B[cat]] = i;
                D_80113F70_390C20_name_5B[cat]++;
                D_80113F84_390C34_name_5B++;
            } else {
                D_80113A30_3906E0_name_5B[cat][D_80113F40_390BF0_name_5B[cat]] = i;
                D_80113F40_390BF0_name_5B[cat]++;
                D_80113F82_390C32_name_5B++;
            }
            D_801144A0_391150_name_5B++;
        }
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[cat]++;
    }
    if (func_80068040_68C40(15) != 0) {
        D_80113F90_390C40_name_5B[1][D_80113F70_390C20_name_5B[1]] = 15;
        D_80113F70_390C20_name_5B[1]++;
        D_80113F84_390C34_name_5B++;
        D_801144A0_391150_name_5B++;
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[1]++;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_80113F90_390C40_name_5B[2][D_80113F70_390C20_name_5B[2]] = 0x22;
        D_80113F70_390C20_name_5B[2]++;
        D_80113F84_390C34_name_5B++;
        D_801144A0_391150_name_5B++;
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[2]++;
    }
}
