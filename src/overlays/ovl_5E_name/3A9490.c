#include "common.h"
#include "ovl_5E.h"

void func_80102830_3A9490_name_5E(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0x19);
    func_80088640_89240();
    func_80079128_79D28();
    omAddObj(0x2710, 0, 0, -1, func_80103E08_3AAA68_name_5E);
    func_80026D28_27928(1);
    D_80104DF8_3ABA58_name_5E = 8000.0f;
    D_80104D30_3AB990_name_5E = 17.0f;
    D_80104DE4_3ABA44_name_5E = 500.0f;
    Hu3DCamSetPerspective(0, 17.0f, 500.0f, 8000.0f);
    omPrcSetStatBit(omAddPrcObj(func_80104390_3AAFF0_name_5E, 0x1100, 0x800, 0), 0xA0);
    InitFadeIn(0, 0x10);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
    D_80104DF4_3ABA54_name_5E = D_800FD80C_FE40C;
    D_80104DFC_3ABA5C_name_5E = 1;
    D_80104DF6_3ABA56_name_5E = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
    D_80104E18_3ABA78_name_5E = 0;
    D_80104D96_3AB9F6_name_5E = GwSystem.chosenMinigameIndex - 1;
    if (D_80104D96_3AB9F6_name_5E == 0x38) {
        PlayMusic(0x3A);
    } else {
        PlayMusic(0x16);
    }
    D_80104D9A_3AB9FA_name_5E = ((D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0x7FFF) >> 12) + 1;
    if (D_80104D9A_3AB9FA_name_5E != 1) {
        omAddPrcObj(func_80102A64_3A96C4_name_5E, 0x3F00, 0x2000, 0);
    } else {
        omAddPrcObj(func_80102E34_3A9A94_name_5E, 0x3F00, 0x2000, 0);
    }
}

void func_801029F8_3A9658_name_5E(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0x19);
    omOvlHisChg(0, 0x5E, 0, 0x114);
    omOvlCallEx((s16)func_8003F6F0_402F0(GwSystem.chosenMinigameIndex), 0, 0x111);
}

void func_80102A64_3A96C4_name_5E(void) {
    s16 size[2];
    s16 win;
    u16 spr;

    D_80104D98_3AB9F8_name_5E = D_800CAFEE;
    if (D_80104D98_3AB9F8_name_5E < 0) {
        D_80104D98_3AB9F8_name_5E = 0;
    }
    if (D_80104D96_3AB9F6_name_5E != 0x38) {
        spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0011), 0, 1);
        espPosSet(spr, 160, 120);
        func_8001A788_1B388(spr, 0x7000);
    }
    D_80104D9C_3AB9FC_name_5E = 0;
    omAddPrcObj(func_80103A4C_3AA6AC_name_5E, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80103174_3A9DD4_name_5E, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80103388_3A9FE8_name_5E, 0x3F00, 0x800, 0);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80103A1C_3AA67C_name_5E(60, 110, 260, 110);
    D_80104D92_3AB9F2_name_5E = 0;
    D_80104D94_3AB9F4_name_5E = 0;
    HuPrcSleep(10);
    func_8008DACC_8E6CC(1, size, D_80104D04_3AB964_name_5E[D_80104C74_3AB8D4_name_5E[D_80104D96_3AB9F6_name_5E]]);
    win = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 180, size[0], size[1], 0);
    func_80089A48_8A648(win, 0);
    func_8008E978_8F578(win);
    func_800890CC_89CCC(win, (void*)D_80104D04_3AB964_name_5E[D_80104C74_3AB8D4_name_5E[D_80104D96_3AB9F6_name_5E]], -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    D_80104D90_3AB9F0_name_5E = 1;
    while (1) {
        if (ContStkX[D_80104DF4_3ABA54_name_5E] > 30 || ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 1) {
            PlaySound(1);
            D_80104D9C_3AB9FC_name_5E = 1;
            goto turn;
        } else if (ContStkX[D_80104DF4_3ABA54_name_5E] < -30 || ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 2) {
            PlaySound(1);
            D_80104D9C_3AB9FC_name_5E = -1;
        turn:
            D_80104D90_3AB9F0_name_5E = 0;
            HuPrcSleep(10);
            D_80104D90_3AB9F0_name_5E = 1;
        }
        if (ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 0x8000) {
            PlaySound(2);
            D_800CAFEE = D_80104D98_3AB9F8_name_5E;
            break;
        }
        if (ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 0x4000) {
            PlaySound(4);
            D_800CAFEE = -1;
            D_80104DFC_3ABA5C_name_5E = 0;
            D_80104C70_3AB8D0_name_5E = 1;
            while (1) {
                HuPrcVSleep();
            }
        }
        HuPrcVSleep();
    }
    func_80103C7C_3AA8DC_name_5E();
    func_8008CCA8_8D8A8(win);
    D_80104DFC_3ABA5C_name_5E = 2;
    D_80104DF6_3ABA56_name_5E = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
    D_80104E18_3ABA78_name_5E = 0;
    D_80104C70_3AB8D0_name_5E = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_80102E34_3A9A94_name_5E(void) {
    s16 size[2];
    s16 win;
    s16 i;
    u16 spr;
    s16 shot;

    if (D_80104D96_3AB9F6_name_5E != 0x38) {
        spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0011), 0, 1);
        espPosSet(spr, 160, 120);
        func_8001A788_1B388(spr, 0x7000);
    }
    D_800CAFEE = -1;
    omAddPrcObj(func_80103174_3A9DD4_name_5E, 0x3F00, 0x800, 0);
    shot = func_80104964_3AB5C4_name_5E();
    func_80104A5C_3AB6BC_name_5E(D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0xFFF);
    espPosSet(shot, 0, -100);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80103A1C_3AA67C_name_5E(60, 110, 260, 110);
    D_80104D92_3AB9F2_name_5E = 0;
    for (i = 0; i < 11; i++) {
        espPosSet(shot, HuMathSin(i * 9.0f) * 240.0f - 80.0f, 115);
        HuPrcVSleep();
    }
    func_8008DACC_8E6CC(1, size, 0x52C);
    win = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 180, size[0], size[1], 0);
    func_80089A48_8A648(win, 0);
    func_8008E978_8F578(win);
    func_800890CC_89CCC(win, (void*)0x52C, -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    while (1) {
        if (ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 0x8000) {
            PlaySound(2);
            break;
        }
        if (ContBtnTrg[D_80104DF4_3ABA54_name_5E] & 0x4000) {
            PlaySound(4);
            D_80104DFC_3ABA5C_name_5E = 0;
            D_80104C70_3AB8D0_name_5E = 1;
            while (1) {
                HuPrcVSleep();
            }
        }
        HuPrcVSleep();
    }
    func_80103C7C_3AA8DC_name_5E();
    func_8008CCA8_8D8A8(win);
    D_80104DFC_3ABA5C_name_5E = 2;
    D_80104DF6_3ABA56_name_5E = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
    D_80104E18_3ABA78_name_5E = 0;
    D_80104C70_3AB8D0_name_5E = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_80103174_3A9DD4_name_5E(void) {
    GAMEMES mes;
    f32 y;
    s16 id;
    s16 i;
    void* str;

    str = func_80068CD4_698D4(D_80104D96_3AB9F6_name_5E + 0x3D9);
    func_8010331C_3A9F7C_name_5E(str);
    id = func_8006A608_6B208(&mes, str, 0, -1, -1);
    SprPosSet(mes.strGId[id], 0, 0, -100);
    func_80068D24_69924(str);
    D_80104D92_3AB9F2_name_5E = -1;
    if (D_80104D9A_3AB9FA_name_5E != 1) {
        y = 28.0f;
    } else {
        y = 44.0f;
    }
    while (1) {
        if (D_80104D92_3AB9F2_name_5E == 0) {
            for (i = 0; i < 11; i++) {
                SprPosSet(mes.strGId[id], 0, HuMathSin(i * 9.0f) * 160.0f, y);
                HuPrcVSleep();
            }
            D_80104D92_3AB9F2_name_5E = -1;
        }
        HuPrcVSleep();
    }
}

void func_8010331C_3A9F7C_name_5E(u8* str) {
    u8* out = str;
    u8* in = str;
    u8 c;

    while (*in != 0) {
        *out = *in;
        c = *in;
        if (c >= 0x20 || c == 0x10 || c == 0x20 || c == 0x11) {
            out++;
        }
        in++;
    }
    *out = 0;
}

#ifdef NON_MATCHING
/* register allocation (masked 9 with a mul-fix nop): the caption walk reads through s3, retail s0, and
   the opening slide's sub.s/trunc swap f0/f2; tried str/p chained or for (p = str), fx dropped or split
   (S3-Q03). The D_800CAD96 relocations are split-label names of D_800CAD90[].unk_06, not a difference */
void func_80103388_3A9FE8_name_5E(void) {
    Ovl5EPageText text;
    f32 fx;
    s16 i;
    s16 x;
    s16 shot;
    u8* str;
    u8* p;

    for (i = 0; i < D_80104D9A_3AB9FA_name_5E; i++) {
        if (D_80104D96_3AB9F6_name_5E == 0x19 || D_80104D96_3AB9F6_name_5E == 0x11) {
            p = func_80068CD4_698D4(D_80104D18_3AB978_name_5E[D_80104C74_3AB8D4_name_5E[D_80104D96_3AB9F6_name_5E]] + i);
        } else {
            p = func_80068CD4_698D4(D_80104D18_3AB978_name_5E[D_80104C74_3AB8D4_name_5E[D_80104D96_3AB9F6_name_5E]]);
        }
        str = p;
        func_8010331C_3A9F7C_name_5E(str);
        for (; *p != 0; p++) {
            if (*p == 0x11) {
                *p = i + '1';
            }
        }
        text.id[i] = func_8006A608_6B208(&text.mes[i], str, 0, -1, -1);
        SprPosSet(text.mes[i].strGId[text.id[i]], 0, 0, -100);
        func_80068D24_69924(str);
    }
    D_80104D92_3AB9F2_name_5E = -1;
    shot = func_80104964_3AB5C4_name_5E();
    if (D_80104D96_3AB9F6_name_5E == 0x19 || D_80104D96_3AB9F6_name_5E == 0x11) {
        func_80104A5C_3AB6BC_name_5E(D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0xFFF);
    } else {
        func_80104A5C_3AB6BC_name_5E((D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0xFFF) + D_80104D98_3AB9F8_name_5E * 2);
    }
    espDispOff(shot);
    D_80104D94_3AB9F4_name_5E = -1;
    while (1) {
        if (D_80104D94_3AB9F4_name_5E == 0) {
            espDispOn(shot);
            for (i = 0; i < 11; i++) {
                fx = HuMathSin(i * 9.0f) * 240.0f - 80.0f;
                x = fx;
                espPosSet(shot, x, 115);
                SprPosSet(text.mes[D_80104D98_3AB9F8_name_5E].strGId[text.id[D_80104D98_3AB9F8_name_5E]], 0, x, 47);
                HuPrcVSleep();
            }
            D_80104D94_3AB9F4_name_5E = -1;
        }
        if (D_80104D9C_3AB9FC_name_5E != 0) {
            for (i = 1; i < 6; i++) {
                x = (1.0f - func_800B7890_B8490(i * 18.0f)) * 240.0f * D_80104D9C_3AB9FC_name_5E + 160.0f;
                espPosSet(shot, x, 115);
                SprPosSet(text.mes[D_80104D98_3AB9F8_name_5E].strGId[text.id[D_80104D98_3AB9F8_name_5E]], 0, x, 50);
                HuPrcVSleep();
            }
            SprPosSet(text.mes[D_80104D98_3AB9F8_name_5E].strGId[text.id[D_80104D98_3AB9F8_name_5E]], 0, 0, -100);
            D_80104D98_3AB9F8_name_5E += D_80104D9C_3AB9FC_name_5E;
            if (D_80104D98_3AB9F8_name_5E >= D_80104D9A_3AB9FA_name_5E) {
                D_80104D98_3AB9F8_name_5E = 0;
            }
            if (D_80104D98_3AB9F8_name_5E < 0) {
                D_80104D98_3AB9F8_name_5E = D_80104D9A_3AB9FA_name_5E - 1;
            }
            if (D_80104D96_3AB9F6_name_5E == 0x19 || D_80104D96_3AB9F6_name_5E == 0x11) {
                func_80104A5C_3AB6BC_name_5E(D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0xFFF);
            } else {
                func_80104A5C_3AB6BC_name_5E((D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_06 & 0xFFF) + D_80104D98_3AB9F8_name_5E * 2);
            }
            for (i = 1; i < 6; i++) {
                x = -(1.0f - HuMathSin(i * 18.0f)) * 240.0f * D_80104D9C_3AB9FC_name_5E + 160.0f;
                espPosSet(shot, x, 115);
                SprPosSet(text.mes[D_80104D98_3AB9F8_name_5E].strGId[text.id[D_80104D98_3AB9F8_name_5E]], 0, x, 50);
                HuPrcVSleep();
            }
            D_80104D9C_3AB9FC_name_5E = 0;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5E_name/3A9490", func_80103388_3A9FE8_name_5E);
#endif

void func_80103A1C_3AA67C_name_5E(s16 x0, s16 y0, s16 x1, s16 y1) {
    D_80104D9E_3AB9FE_name_5E = x0;
    D_80104DA0_3ABA00_name_5E = x1;
    D_80104DA2_3ABA02_name_5E = y0;
    D_80104DA4_3ABA04_name_5E = y1;
    D_80104D8E_3AB9EE_name_5E = 1;
}

void func_80103A4C_3AA6AC_name_5E(void) {
    s8 shown = 0;
    s8 fading = 0;
    s16 a0;
    s16 a1;
    s16 left;
    s16 right;
    s16 alpha;
    s16 last;
    s32 step;

    D_80104D90_3AB9F0_name_5E = 0;
    D_80104D8E_3AB9EE_name_5E = 0;
    a0 = func_8001A2F8_1AEF8(0x900C7);
    a1 = func_8001A2F8_1AEF8(0x900C8);
    left = func_8001AAAC_1B6AC(a0, 0, 1);
    right = func_8001AAAC_1B6AC(a1, 0, 1);
    func_8001A788_1B388(left, 0x4800);
    func_8001A788_1B388(right, 0x4800);
    espPosSet(left, 160, 120);
    espPosSet(right, 160, 120);
    espDispOff(left);
    espDispOff(right);
    alpha = 0;
    step = 0;
    while (1) {
        HuPrcVSleep();
        if (shown != D_80104D90_3AB9F0_name_5E) {
            shown = D_80104D90_3AB9F0_name_5E;
            fading = 1;
            step = -63;
            if (D_80104D90_3AB9F0_name_5E != 0) {
                step = 63;
            }
        }
        last = alpha;
        if (fading != 0) {
            alpha += step;
            if (alpha >= 255) {
                fading = 0;
                alpha = 255;
            } else if (alpha <= 0) {
                fading = 0;
                alpha = 0;
            }
            if (alpha != 0) {
                if (last == 0) {
                    espDispOn(left);
                    espDispOn(right);
                }
                func_8001A6BC_1B2BC(left, alpha);
                func_8001A6BC_1B2BC(right, alpha);
            } else {
                espDispOff(left);
                espDispOff(right);
            }
        }
        if (D_80104D8E_3AB9EE_name_5E != 0) {
            espPosSet(left, D_80104D9E_3AB9FE_name_5E, D_80104DA2_3ABA02_name_5E);
            espPosSet(right, D_80104DA0_3ABA00_name_5E, D_80104DA4_3ABA04_name_5E);
            D_80104D8E_3AB9EE_name_5E = 0;
        }
    }
}

void func_80103C7C_3AA8DC_name_5E(void) {
    s16 type = D_800CAD90[D_80104D96_3AB9F6_name_5E].unk_04;
    s16 i;

    if (type == 1 || type == 2) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].group >= 2) {
                break;
            }
        }
        if (i != 4) {
            switch (type) {
                case 1:
                    for (i = 0; i < 4; i++) {
                        if (gPlayers[i].group != 0) {
                            gPlayers[i].group = 1;
                        }
                    }
                    break;
                default:
                    for (i = 0; i < 4; i++) {
                        if (gPlayers[i].group < 2) {
                            gPlayers[i].group = 0;
                        } else {
                            gPlayers[i].group = 1;
                        }
                    }
                    break;
            }
        }
    }
}

void func_80103E08_3AAA68_name_5E(omObjData* obj) {
    if (D_80104C70_3AB8D0_name_5E != 0 || D_801011FC_101DFC != 0) {
        if (D_80104C72_3AB8D2_name_5E == 0) {
            InitFadeOut(0, 8);
            if (D_80104D96_3AB9F6_name_5E == 0x38 || D_80104DFC_3ABA5C_name_5E == 0) {
                func_800794A8_7A0A8(0x3C);
            }
        }
        obj->func_ptr = func_80103E98_3AAAF8_name_5E;
    }
}

void func_80103E98_3AAAF8_name_5E(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        func_80104B90_3AB7F0_name_5E();
        func_8008CE5C_8DA5C();
        switch (D_80104DFC_3ABA5C_name_5E) {
            case 0:
                omOvlReturnEx(1);
                break;
            case 2:
                omOvlCallEx(D_80104DF6_3ABA56_name_5E, D_80104E18_3ABA78_name_5E, 0x111);
                break;
            case 1:
                omOvlGotoEx(D_80104DF6_3ABA56_name_5E, D_80104E18_3ABA78_name_5E, 0x111);
                break;
        }
    }
}

void func_80103F50_3AABB0_name_5E(void) {
    s16 last = -1;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;
    s16* to;

    D_80104DE0_3ABA40_name_5E = 0;
    D_80104E04_3ABA64_name_5E = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_80104E04_3ABA64_name_5E, 1);
    espPosSet(D_80104E04_3ABA64_name_5E, 160, 120);
    espDispOff(D_80104E04_3ABA64_name_5E);
    D_80104DB4_3ABA14_name_5E = 160;
    D_80104DB6_3ABA16_name_5E = 120;
    D_80104DB8_3ABA18_name_5E = 10;
    omAddPrcObj(func_801041E4_3AAE44_name_5E, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_80104DE0_3ABA40_name_5E != 0) {
            if (last != D_80104DBA_3ABA1A_name_5E && D_80104DBA_3ABA1A_name_5E != -1) {
                x0 = D_80104DB4_3ABA14_name_5E;
                y0 = D_80104DB6_3ABA16_name_5E;
                to = D_80104DB0_3ABA10_name_5E[D_80104DBA_3ABA1A_name_5E];
                dx = to[0] - x0;
                dy = to[1] - y0;
                for (i = 1; i <= D_80104DB8_3ABA18_name_5E; i++) {
                    s = HuMathSin(90.0f / D_80104DB8_3ABA18_name_5E * i);
                    D_80104DB4_3ABA14_name_5E = x0 + dx * s;
                    D_80104DB6_3ABA16_name_5E = y0 + dy * s;
                    espPosSet(D_80104E04_3ABA64_name_5E, D_80104DB4_3ABA14_name_5E, D_80104DB6_3ABA16_name_5E);
                    HuPrcVSleep();
                }
                last = D_80104DBA_3ABA1A_name_5E;
            }
        } else {
            last = D_80104DBA_3ABA1A_name_5E;
        }
        espPosSet(D_80104E04_3ABA64_name_5E, D_80104DB4_3ABA14_name_5E, D_80104DB6_3ABA16_name_5E);
    }
}

void func_801041E4_3AAE44_name_5E(void) {
    s16 shown;
    s16 i;

    shown = 0;
    while (1) {
        HuPrcVSleep();
        if (shown == D_80104DE0_3ABA40_name_5E) {
            continue;
        }
        if (D_80104DE0_3ABA40_name_5E != 0) {
            espDispOn(D_80104E04_3ABA64_name_5E);
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80104E04_3ABA64_name_5E, i * 63.75f);
                HuPrcVSleep();
            }
        } else {
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80104E04_3ABA64_name_5E, 255.0f - i * 63.75f);
                HuPrcVSleep();
            }
            espDispOff(D_80104E04_3ABA64_name_5E);
        }
        shown = D_80104DE0_3ABA40_name_5E;
    }
}

void func_80104334_3AAF94_name_5E(s16 n) {
    D_80104DB4_3ABA14_name_5E = D_80104DB0_3ABA10_name_5E[n][0];
    D_80104DB6_3ABA16_name_5E = D_80104DB0_3ABA10_name_5E[n][1];
    D_80104DBA_3ABA1A_name_5E = n;
}

void func_8010436C_3AAFCC_name_5E(s16 (*table)[2]) {
    D_80104DB0_3ABA10_name_5E = table;
}

void func_80104378_3AAFD8_name_5E(s16 frames) {
    D_80104DB8_3ABA18_name_5E = frames;
}

void func_80104384_3AAFE4_name_5E(s16 slot) {
    D_80104DBA_3ABA1A_name_5E = slot;
}

void func_80104390_3AAFF0_name_5E(void) {
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 ux;
    f32 uy;
    f32 uz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    while (1) {
        if (D_80104D34_3AB994_name_5E[0] == 0) {
            rx = D_800FD474_FE074.x;
            ry = D_800FD474_FE074.y;
            rz = D_800FD474_FE074.z;
            pos.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            pos.y = D_8010274C_10334C.y + -HuMathSin(rx) * D_800FA610_FB210;
            pos.z = D_8010274C_10334C.z + func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            at.x = D_8010274C_10334C.x;
            at.y = D_8010274C_10334C.y;
            at.z = D_8010274C_10334C.z;
            ux = HuMathSin(ry) * HuMathSin(rx);
            uy = func_800B7890_B8490(rx);
            uz = func_800B7890_B8490(ry) * HuMathSin(rx);
            dx = at.x - pos.x;
            dy = at.y - pos.y;
            dz = at.z - pos.z;
            dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            dx /= dist;
            dy /= dist;
            dz /= dist;
            up.x = ux * (dx * dx + (1.0f - dx * dx) * func_800B7890_B8490(rz))
                 + uy * (dx * dy * (1.0f - func_800B7890_B8490(rz)) - dz * HuMathSin(rz))
                 + uz * (dx * dz * (1.0f - func_800B7890_B8490(rz)) + dy * HuMathSin(rz));
            up.y = ux * (dx * dy * (1.0f - func_800B7890_B8490(rz)) + dz * HuMathSin(rz))
                 + uy * (dy * dy + (1.0f - dy * dy) * func_800B7890_B8490(rz))
                 + uz * (dy * dz * (1.0f - func_800B7890_B8490(rz)) - dx * HuMathSin(rz));
            up.z = ux * (dx * dz * (1.0f - func_800B7890_B8490(rz)) - dy * HuMathSin(rz))
                 + uy * (dy * dz * (1.0f - func_800B7890_B8490(rz)) + dx * HuMathSin(rz))
                 + uz * (dz * dz + (1.0f - dz * dz) * func_800B7890_B8490(rz));
        } else {
            pos = D_80104E24_3ABA84_name_5E;
            at = D_80104E08_3ABA68_name_5E;
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
        }
        D_800FA5BC_FB1BC[0] = pos.x;
        D_800FA5BC_FB1BC[1] = pos.z;
        D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
        D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
        D_800FA5BC_FB1BC[3] = D_80101078_101C78;
        D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
        Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
        Hu3DCamUpdateMtx(0);
        HuPrcVSleep();
    }
}

s16 func_80104964_3AB5C4_name_5E(void) {
    s16 spr;
    s16 i;

    D_80104DBC_3ABA1C_name_5E = func_8001A2F8_1AEF8(0x900C9);
    spr = func_8001AAAC_1B6AC(D_80104DBC_3ABA1C_name_5E, 0, 1);
    D_80104DBE_3ABA1E_name_5E = spr;
    for (i = 0; i < 3; i++) {
        D_80104DC4_3ABA24_name_5E[i] = func_80027154_27D54(0x6000, 0x7918);
    }
    D_80104DD0_3ABA30_name_5E = func_80082550_83150(D_800F93FC_F9FFC[spr].unk4, 0)->unk_84->unk00->unk00;
    D_80104DC0_3ABA20_name_5E = 0;
    espDispOff(spr);
    return spr;
}

void func_80104A5C_3AB6BC_name_5E(s16 file) {
    void* code;
    void* header;
    void* work;

    code = DataRead(file | 0xB0000);
    header = DataRead((file + 1) | 0xB0000);
    func_80096C10_97810(0xFF);
    func_80096708_97308(header);
    work = HuMemMemoryAllocPerm(0xC00);
    func_80096188_96D88(code, D_80104DC4_3ABA24_name_5E[D_80104DC0_3ABA20_name_5E], 0x80, work);
    HuMemMemoryFreePerm(work);
    DataClose(code);
    DataClose(header);
    func_80082550_83150(D_800F93FC_F9FFC[D_80104DBE_3ABA1E_name_5E].unk4, 0)->unk_84->unk00->unk00 = D_80104DC4_3ABA24_name_5E[D_80104DC0_3ABA20_name_5E];
    D_80104DC0_3ABA20_name_5E++;
    if (D_80104DC0_3ABA20_name_5E >= 3) {
        D_80104DC0_3ABA20_name_5E = 0;
    }
    espDispOn(D_80104DBE_3ABA1E_name_5E);
}

void func_80104B90_3AB7F0_name_5E(void) {
    s16 i;

    func_80082550_83150(D_800F93FC_F9FFC[D_80104DBE_3ABA1E_name_5E].unk4, 0)->unk_84->unk00->unk00 = D_80104DD0_3ABA30_name_5E;
    func_8001AC44_1B844(D_80104DBE_3ABA1E_name_5E);
    SprAnimKill(D_80104DBC_3ABA1C_name_5E);
    for (i = 0; i < 3; i++) {
        HuMemFree(D_80104DC4_3ABA24_name_5E[i]);
    }
}

/* .data (0x3AB8B0-0x3AB9A0, 80104C50-80104D40) */
board_overlay_entrypoint D_80104C50_3AB8B0_name_5E[4] = {
    { 0, func_80102830_3A9490_name_5E }, { 1, func_801029F8_3A9658_name_5E }, { -1, NULL }, { 0, NULL },
};
u16 D_80104C70_3AB8D0_name_5E = 0;
s16 D_80104C72_3AB8D2_name_5E = 0;
s16 D_80104C74_3AB8D4_name_5E[72] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4,
    4, -1, 1, -1, -1, 2, -1, -1, -1, -1, -1, -1,
    -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 1, -1, -1, 4, -1, -1, -1, 1, -1, -1,
    -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,
};
s32 D_80104D04_3AB964_name_5E[5] = { 0x6A5, 0x6A7, 0x6AC, 0x6AC, 0x6AE };
s16 D_80104D18_3AB978_name_5E[12] = { 0x6A4, 0x6A6, 0x6A8, 0x6AA, 0x6AD };
f32 D_80104D30_3AB990_name_5E = 58.0f;
s8 D_80104D34_3AB994_name_5E[12] = { 0 };
