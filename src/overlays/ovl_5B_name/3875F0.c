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
