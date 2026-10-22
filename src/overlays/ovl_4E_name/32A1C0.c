#include "ovl_4E.h"

void func_80102800_32A1C0_name_4E(void) {
    s32 i;

    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0x19);
    func_80088640_89240();
    omAddObj(0x2710, 0, 0, -1, func_80107D3C_32F6FC_name_4E);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 0x64, 0x64, 0x64);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    for (i = 0; i < 4; i++) {
        gPlayers[i].cpu_difficulty = gPlayers[i].cpu_difficulty2;
    }
    omAddPrcObj(func_80102B9C_32A55C_name_4E, 0x3F00, 0x1800, 0);
    D_8010E63C_335FFC_name_4E = 80.0f;
    D_8010E150_335B10_name_4E = 8000.0f;
    D_8010D7B0_335170_name_4E = 20.0f;
    Hu3DCamSetPositionOrientation(0, &D_8010D5A4_334F64_name_4E, &D_8010D5B0_334F70_name_4E, &D_8010D5BC_334F7C_name_4E);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    CameraViewportSet(0, &D_8010D5C8_334F88_name_4E, &D_8010D5C8_334F88_name_4E);
    Hu3DCamSetPerspective(0, D_8010D7B0_335170_name_4E, D_8010E63C_335FFC_name_4E, D_8010E150_335B10_name_4E);
    Hu3DCamUpdateMtx(0);
    omAddPrcObj(func_80109778_331138_name_4E, 0x1001, 0x800, 0);
    func_80029708_2A308(0);
    func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
    func_8002C59C_2D19C(0x3DE, 0x3E8, 0xFF, 0xFF, 0xFF);
    D_8010E144_335B04_name_4E = D_8010D1F8_334BB8_name_4E;
    D_8010E5F4_335FB4_name_4E = 0;
    if (!(D_800CD414_CE014 & 1)) {
        D_8010DAB6_335476_name_4E = 1;
        D_8010DBE0_3355A0_name_4E = 4;
        if (!(D_800CD414_CE014 & 4)) {
            D_801013B8_101FB8[0x20] = 0;
        }
    } else {
        D_8010DAB6_335476_name_4E = 0;
        D_8010DBE0_3355A0_name_4E = 2;
        D_801013B8_101FB8[0x20] = 7;
    }
    if (D_800CD414_CE014 < 4) {
        func_8010A244_331C04_name_4E();
        for (i = 0; i < 4; i++) {
            D_800F9D48_FA948[0x2F8 + i] = i;
            D_800FC9B8_FD5B8[2 + i] = 0;
        }
        D_800FC8F0_FD4F0[2] = 0;
        D_8010DBE2_3355A2_name_4E = 1;
        if (D_800CD414_CE014 & 2) {
            D_8010DAB8_335478_name_4E = 0;
            PlayMusic(0x35);
        } else {
            D_8010DAB8_335478_name_4E = 1;
        }
    } else {
        D_8010DAB8_335478_name_4E = 0;
        D_8010D1F4_334BB4_name_4E = func_80105F80_32D940_name_4E();
        if (D_8010D1F4_334BB4_name_4E == 0) {
            PlayMusic(0x35);
        }
        D_8010DBE2_3355A2_name_4E = 0;
    }
    D_8010DC90_335650_name_4E = 0;
    D_8010E140_335B00_name_4E = 0x73;
    D_8010E618_335FD8_name_4E = 0;
}

void func_80102B94_32A554_name_4E(void) {
}

#ifdef NON_MATCHING
/* The overlay's main process: the mode/character setup state machine (state 0 first menu,
   1 second menu, 2 third menu, 3 back, 4 the resumed path, 5 leave). Same logic as retail; the
   residue is the inner switch's compare tree (retail tests 1 first) and one delay slot. */
void func_80102B9C_32A55C_name_4E(void) {
    s16 i;
    s8 state;
    s8 confirm;

    func_80102B94_32A554_name_4E();
    if (D_8010DAB6_335476_name_4E != 0) {
        D_8010DC2C_3355EC_name_4E = D_8010D5D4_334F94_name_4E;
    } else {
        D_8010DC2C_3355EC_name_4E = D_8010D5F4_334FB4_name_4E;
    }
    func_8010A2A0_331C60_name_4E();
    func_8010C618_333FD8_name_4E(D_8010D214_334BD4_name_4E);
    omAddPrcObj(func_8010C218_333BD8_name_4E, 0x3F00, 0x800, 0);
    func_8010C5F4_333FB4_name_4E(D_8010E648_336008_name_4E);
    omAddPrcObj(func_80107554_32EF14_name_4E, 0x3F00, 0x800, 0);
    omAddPrcObj(func_801047E8_32C1A8_name_4E, 0x3F00, 0x800, 0);
    D_8010DBE3_3355A3_name_4E = 0;
    omAddPrcObj(func_80105148_32CB08_name_4E, 0x3F00, 0x800, 0);
    D_8010E5F2_335FB2_name_4E = 0;
    func_80108BE0_3305A0_name_4E();
    func_80107F10_32F8D0_name_4E();
    espDispOn(D_8010DABC_33547C_name_4E);
    if (D_800CD414_CE014 < 4) {
        func_801076E4_32F0A4_name_4E();
        if (D_800CD414_CE014 < 2) {
            espPosSet(D_8010DABC_33547C_name_4E, 0xA0, 0x2E);
            for (i = 0; i < 11; i++) {
                espPosSet(D_8010DABC_33547C_name_4E, 0xA0, 36.0f - (1.0f - HuMathSin(i * 9.0f)) * 80.0f);
                HuPrcVSleep();
            }
        }
        state = 0;
    } else {
        state = 4;
    }
    confirm = 0;
    while (1) {
        switch (state) {
        case 0:
            if (func_80103034_32A9F4_name_4E() == 0) {
                confirm = 1;
                break;
            }
            state = 1;
            if (D_8010DAB6_335476_name_4E != 0) {
                break;
            }
            if (D_800CD414_CE014 & 4) {
                func_80089284_89E84(D_8010DB60_335520_name_4E, 1, 1);
            }
            func_8010760C_32EFCC_name_4E(0xA2);
            i = func_80107638_32EFF8_name_4E();
            if (i < 0) {
                for (i = 0; i < 3; i++) {
                    espPosSet(D_8010DAC4_335484_name_4E[i], -0x50, i * 36 + 0x4F);
                    espDispOff(D_8010DAC4_335484_name_4E[i]);
                }
                state = 0;
                HuPrcVSleep();
                HuPrcVSleep();
                break;
            }
            if (i != 0) {
                D_800F904A = 0;
            } else {
                D_800F904A = 1;
            }
            D_801013B8_101FB8[0x20] = 7;
            state = 3;
            break;
        case 1:
            if (func_80103608_32AFC8_name_4E() == 0) {
                state = 0;
                break;
            }
            state = 3;
            if (D_801013B8_101FB8[0x20] < 3) {
                state = (D_801013B8_101FB8[0x20] < 1) ? 3 : 2;
            }
            break;
        case 2:
            state = (func_80103CD0_32B690_name_4E() != 0) ? 3 : 1;
            break;
        case 3:
            state = 0;
            func_80104AF0_32C4B0_name_4E();
            break;
        case 4:
            switch (func_80105454_32CE14_name_4E()) {
            case 1:
                D_8010DC90_335650_name_4E = 1;
                D_8010E140_335B00_name_4E = 0x4E;
                D_8010E618_335FD8_name_4E = (D_800CD414_CE014 & 1) | 2;
                D_8010D1F0_334BB0_name_4E = 1;
                InitFadeOut(0, 10);
                while (1) {
                    HuPrcVSleep();
                }
            case 0:
                state = 3;
                break;
            default:
                state = 5;
                break;
            }
            break;
        case 5:
        default:
            D_8010DC90_335650_name_4E = 0;
            D_8010E140_335B00_name_4E = 0x5C;
            D_8010E618_335FD8_name_4E = 0;
            D_8010D1F0_334BB0_name_4E = 1;
            HuPrcVSleep();
            break;
        }
        if (confirm) {
            confirm = 0;
            func_8010760C_32EFCC_name_4E(D_8010DC2C_3355EC_name_4E[1]);
            if (func_80107638_32EFF8_name_4E() == 0) {
                D_8010D1F0_334BB0_name_4E = 1;
                state = 5;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80102B9C_32A55C_name_4E);
#endif

/* First menu: three rows (D_8010DAC4) slide in; the stick moves the cursor (D_8010E5F2), A picks
   (D_800FA1A8, returns 1: the others slide out, the chosen one rises), B backs out (returns 0). */
s32 func_80103034_32A9F4_name_4E(void) {
    s16 i;
    s16 j;
    s8 ok;

    if (D_8010DBE2_3355A2_name_4E != 0) {
        PlaySound(0x11E);
        D_8010DBE2_3355A2_name_4E = 0;
    }
    i = 0;
    func_8010760C_32EFCC_name_4E(D_8010DC2C_3355EC_name_4E[0]);
    do {
        for (j = 0; j < 3; j++) {
            if (i >= j * 5 && j * 5 + 10 >= i) {
                espDispOn(D_8010DAC4_335484_name_4E[j]);
                espPosSet(D_8010DAC4_335484_name_4E[j], 160.0f - (1.0f - HuMathSin((i - j * 5) * 9.0f)) * 240.0f, j * 36 + 0x4F);
                func_801078EC_32F2AC_name_4E(j, D_8010DAC4_335484_name_4E[j], 0, 0);
            }
        }
        HuPrcVSleep();
    } while (++i < 21);
    func_801079AC_32F36C_name_4E();
    func_80109750_331110_name_4E(0);
    func_8010C600_333FC0_name_4E(5);
    D_8010E154_335B14_name_4E = 1;
    while (1) {
        if (ABS(ContStkX[D_8010E5F4_335FB4_name_4E]) >= 31 || ABS(ContStkY[D_8010E5F4_335FB4_name_4E]) >= 31) {
            i = func_801079EC_32F3AC_name_4E(D_8010E5F2_335FB2_name_4E, 3, -ContStkX[D_8010E5F4_335FB4_name_4E], ContStkY[D_8010E5F4_335FB4_name_4E]);
            if (i != -1) {
                PlaySound(1);
                func_8010C60C_333FCC_name_4E(i);
                HuPrcSleep(6);
                D_8010E5F2_335FB2_name_4E = i;
            }
        }
        if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x8000) {
            PlaySound(3);
            D_800FA1A8 = D_8010E5F2_335FB2_name_4E;
            D_800FC8F0_FD4F0[2] = 0;
            D_8010E154_335B14_name_4E = 0;
            ok = 1;
            break;
        }
        if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x4000) {
            PlaySound(4);
            D_8010E154_335B14_name_4E = 0;
            ok = 0;
            break;
        }
        HuPrcVSleep();
    }
    i = 0;
    if (ok) {
        do {
            for (j = 0; j < 3; j++) {
                if (j != D_800FA1A8) {
                    espPosSet(D_8010DAC4_335484_name_4E[j], (1.0f - func_800B7890_B8490(i * 9.0f)) * 240.0f + 160.0f, j * 36 + 0x4F);
                    if (i == 10) {
                        espDispOff(D_8010DAC4_335484_name_4E[j]);
                    }
                }
            }
            HuPrcVSleep();
        } while (++i < 11);
        for (i = 0; i < 11; i++) {
            espPosSet(D_8010DAC4_335484_name_4E[D_800FA1A8], 0xA0, (f32)(D_800FA1A8 * 36 + 0x4F) + HuMathSin(i * 9.0f) * (f32)(-9 - D_800FA1A8 * 36));
            HuPrcVSleep();
        }
    } else {
        for (j = 0; j < 3; j++) {
            espPosSet(D_8010DAC4_335484_name_4E[j], -0x50, j * 36 + 0x4F);
            espDispOff(D_8010DAC4_335484_name_4E[j]);
        }
        HuPrcVSleep();
    }
    return ok;
}

s32 func_80103608_32AFC8_name_4E(void) {
    s16 i;
    s16 j;
    s16 n;
    s8 msg;
    s16 ok;

    func_8010760C_32EFCC_name_4E(0x26);
    n = 4;
    func_8010CF6C_33492C_name_4E();
    if (D_8010DCA6_335666_name_4E <= 0) {
        n = 3;
    }
    i = 0;
    do {
        for (j = 0; j < n; j++) {
            if (i >= j * 5 && j * 5 + 10 >= i) {
                espDispOn(D_8010DAD2_335492_name_4E[j]);
                espPosSet(D_8010DAD2_335492_name_4E[j], 160.0f - (1.0f - HuMathSin((i - j * 5) * 9.0f)) * 240.0f, j * 20 + 100);
                func_801078EC_32F2AC_name_4E(j, D_8010DAD2_335492_name_4E[j], 0, 0);
            }
        }
        HuPrcVSleep();
    } while (++i < 26);
    msg = 0;
    func_801079AC_32F36C_name_4E();
    func_80109750_331110_name_4E(0);
    D_8010E154_335B14_name_4E = 1;
    while (1) {
        if (ABS(ContStkX[D_8010E5F4_335FB4_name_4E]) >= 31 || ABS(ContStkY[D_8010E5F4_335FB4_name_4E]) >= 31) {
            i = func_801079EC_32F3AC_name_4E(D_8010E5F2_335FB2_name_4E, n, -ContStkX[D_8010E5F4_335FB4_name_4E], ContStkY[D_8010E5F4_335FB4_name_4E]);
            if (i != -1) {
                PlaySound(1);
                func_8010C60C_333FCC_name_4E(i);
                HuPrcSleep(6);
                D_8010E5F2_335FB2_name_4E = i;
                if (msg) {
                    func_8010760C_32EFCC_name_4E(0x26);
                }
            }
        }
        if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x8000) {
            if (D_8010DCA0_335660_name_4E[D_8010E5F2_335FB2_name_4E] < 3) {
                PlaySound(5);
                func_8010760C_32EFCC_name_4E(0x27);
                msg = 1;
            } else {
                PlaySound(3);
                D_801013B8_101FB8[0x20] = D_8010D614_334FD4_name_4E[D_8010E5F2_335FB2_name_4E];
                D_8010E154_335B14_name_4E = 0;
                ok = 1;
                break;
            }
        }
        if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x4000) {
            PlaySound(4);
            D_8010E154_335B14_name_4E = 0;
            ok = 0;
            break;
        }
        HuPrcVSleep();
    }
    i = 0;
    if (ok) {
        do {
            for (j = 0; j < n; j++) {
                if (j != D_8010E5F2_335FB2_name_4E) {
                    espPosSet(D_8010DAD2_335492_name_4E[j], (1.0f - func_800B7890_B8490(i * 9.0f)) * 240.0f + 160.0f, j * 20 + 100);
                    if (i == 10) {
                        espDispOff(D_8010DAD2_335492_name_4E[j]);
                    }
                }
            }
            HuPrcVSleep();
        } while (++i < 11);
        if (D_8010E5F2_335FB2_name_4E != 0) {
            for (i = 0; i < 11; i++) {
                espPosSet(D_8010DAD2_335492_name_4E[D_8010E5F2_335FB2_name_4E], 0xA0, (f32)(D_8010E5F2_335FB2_name_4E * 24 + 100) + HuMathSin(i * 9.0f) * (f32)(-10 - D_8010E5F2_335FB2_name_4E * 20));
                HuPrcVSleep();
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            espPosSet(D_8010DAD2_335492_name_4E[j], -0x50, j * 20 + 100);
            espDispOff(D_8010DAD2_335492_name_4E[j]);
        }
        for (j = 0; j < 3; j++) {
            espPosSet(D_8010DAC4_335484_name_4E[j], -0x50, j * 36 + 0x4F);
            espDispOff(D_8010DAC4_335484_name_4E[j]);
        }
        HuPrcVSleep();
        HuPrcVSleep();
    }
    return ok;
}

#ifdef NON_MATCHING
/* Third menu (teams): for 1 vs 3 (D_801013F8 == 1) or 2 vs 2, the stick cycles the team layouts
   (sel 0..max: icon order D_8010D634/D_8010D644, slot positions D_8010D654/D_8010D664 into
   D_8010DBE8), sliding the panel out and back in; A stores the order in D_800FA040[] and sets
   gPlayers[].group (returns 1), B resets the positions and the menus (returns 0).
   Same logic as retail; retail keeps dir, max and loop in stack slots (and dir's loop copies in
   s8/s1) where this C keeps dir in s8: register allocation only. */
s32 func_80103CD0_32B690_name_4E(void) {
    s16 sel;
    s16 i;
    s16 j;
    s32 x;
    s16 stkX;
    s16 stkY;
    s16 ok;
    u8 loop;
    u8 dir;
    u8 max;
    s8* icons;
    s16* ofs;
    s8* perm;
    Vec* pos;
    f32 f;
    s32 k;
    u16 spr;
    u16 spr2;

    sel = 0;
    ok = 0;
    loop = 1;
    dir = 1;
    icons = NULL;
    func_8010760C_32EFCC_name_4E(0x28);
    func_801047B8_32C178_name_4E(0x50, 0x74, 0xF0, 0x74);
    if (D_801013B8_101FB8[0x20] == 1) {
        ofs = D_8010D61C_334FDC_name_4E;
        max = 3;
    } else {
        max = 2;
        ofs = D_8010D628_334FE8_name_4E;
    }
    func_80105090_32CA50_name_4E();
    D_8010DBE3_3355A3_name_4E = 15;
    if (D_801013B8_101FB8[0x20] == 1) {
        pos = D_8010D544_334F04_name_4E;
        perm = D_8010D654_335014_name_4E[sel];
    } else {
        perm = D_8010D664_335024_name_4E[sel];
        pos = D_8010D574_334F34_name_4E;
    }
    for (i = 0; i < 4; i++) {
        k = perm[i];
        D_8010DBE8_3355A8_name_4E[k].x = pos[i].x;
        D_8010DBE8_3355A8_name_4E[k].y = pos[i].y;
        D_8010DBE8_3355A8_name_4E[k].z = pos[i].z;
    }
    while (loop) {
        if (D_801013B8_101FB8[0x20] == 1) {
            icons = D_8010D634_334FF4_name_4E[sel];
        } else {
            icons = D_8010D644_335004_name_4E[sel];
        }
        for (i = 0; i < 11; i++) {
            if (dir) {
                x = 160.0f - (1.0f - HuMathSin(i * 9.0f)) * 240.0f;
            } else {
                x = 400.0f - HuMathSin(i * 9.0f) * 240.0f;
            }
            spr = D_8010DAE6_3354A6_name_4E[0];
            espDispOn(spr);
            espPosSet(spr, x, 0x74);
            spr = D_8010DAF0_3354B0_name_4E;
            espDispOn(spr);
            espPosSet(spr, x + ofs[5], 0x74);
            for (j = 0; j < 4; j++) {
                spr2 = D_8010DAE8_3354A8_name_4E[icons[j]];
                espDispOn(spr2);
                espPosSet(spr2, x + ofs[1 + j], 0x74);
            }
            HuPrcVSleep();
        }
        D_8010DC20_3355E0_name_4E = 1;
        while (1) {
            stkX = ContStkX[D_8010E5F4_335FB4_name_4E];
            stkY = ContStkY[D_8010E5F4_335FB4_name_4E];
            if (ABS(stkX) >= 31 || ABS(stkY) >= 31) {
                if (stkX > 30 || stkY > 30) {
                    PlaySound(1);
                    sel++;
                    sel = (sel > max) ? 0 : sel;
                    dir = 1;
                } else {
                    PlaySound(1);
                    if (--sel < 0) {
                        sel = max;
                    }
                    dir = 0;
                }
                break;
            }
            if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x8000) {
                PlaySound(3);
                ok = 1;
                loop = 0;
                dir = 1;
                break;
            }
            if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x4000) {
                PlaySound(4);
                ok = 0;
                loop = 0;
                break;
            }
            HuPrcVSleep();
        }
        D_8010DC20_3355E0_name_4E = 0;
        HuPrcVSleep();
        if (loop || ok) {
            if (D_801013B8_101FB8[0x20] == 1) {
                perm = D_8010D654_335014_name_4E[sel];
                pos = D_8010D544_334F04_name_4E;
            } else {
                perm = D_8010D664_335024_name_4E[sel];
                pos = D_8010D574_334F34_name_4E;
            }
            for (i = 0; i < 4; i++) {
                k = perm[i];
                D_8010DBE8_3355A8_name_4E[k].x = pos[i].x;
                D_8010DBE8_3355A8_name_4E[k].y = pos[i].y;
                D_8010DBE8_3355A8_name_4E[k].z = pos[i].z;
            }
            for (i = 0; i < 11; i++) {
                if (dir) {
                    f = (1.0f - HuMathSin((10 - i) * 9.0f)) * 240.0f + 160.0f;
                } else {
                    f = 160.0f - (1.0f - HuMathSin((10 - i) * 9.0f)) * 240.0f;
                }
                x = f;
                espPosSet(D_8010DAE6_3354A6_name_4E[0], x, 0x74);
                espPosSet(D_8010DAF0_3354B0_name_4E, x + ofs[5], 0x74);
                for (j = 0; j < 4; j++) {
                    espPosSet(D_8010DAE8_3354A8_name_4E[icons[j]], x + ofs[1 + j], 0x74);
                }
                HuPrcVSleep();
            }
            espDispOff(D_8010DAE6_3354A6_name_4E[0]);
            espDispOff(D_8010DAF0_3354B0_name_4E);
            for (j = 0; j < 4; j++) {
                espDispOff(D_8010DAE8_3354A8_name_4E[icons[j]]);
            }
        }
    }
    D_8010DC20_3355E0_name_4E = 0;
    if (ok) {
        for (j = 0; j < 4; j++) {
            D_800F9D48_FA948[0x2F8 + j] = icons[j];
        }
        switch (D_801013B8_101FB8[0x20]) {
        case 1:
            for (j = 0; j < 4; j++) {
                gPlayers[j].group = 1;
            }
            gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
            break;
        case 2:
            gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
            gPlayers[D_800F9D48_FA948[0x2F9]].group = 0;
            gPlayers[D_800F9D48_FA948[0x2FA]].group = 1;
            gPlayers[D_800F9D48_FA948[0x2FB]].group = 1;
            break;
        case 0:
        case 3:
            for (j = 0; j < 4; j++) {
                gPlayers[j].group = j;
            }
            break;
        }
    } else {
        for (i = 0; i < 4; i++) {
            D_8010DBE8_3355A8_name_4E[i].x = D_8010D4FC_334EBC_name_4E[i].x;
            D_8010DBE8_3355A8_name_4E[i].y = D_8010D4FC_334EBC_name_4E[i].y;
            D_8010DBE8_3355A8_name_4E[i].z = D_8010D4FC_334EBC_name_4E[i].z;
        }
        for (j = 0; j < 6; j++) {
            spr = D_8010DAE6_3354A6_name_4E[j];
            espPosSet(spr, -0x50, 0x78);
            espDispOff(spr);
        }
        for (j = 0; j < 4; j++) {
            espPosSet(D_8010DAD2_335492_name_4E[j], -0x50, j * 20 + 100);
            espDispOff(D_8010DAD2_335492_name_4E[j]);
        }
        HuPrcVSleep();
        D_8010DBE3_3355A3_name_4E = 0;
    }
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80103CD0_32B690_name_4E);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801047B8_32C178_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801047E8_32C1A8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80104A9C_32C45C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80104AF0_32C4B0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80105090_32CA50_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80105148_32CB08_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801053E0_32CDA0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80105454_32CE14_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80105F80_32D940_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80106228_32DBE8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801064F0_32DEB0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80106BF8_32E5B8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80106C30_32E5F0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80106CB0_32E670_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80106E18_32E7D8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801070AC_32EA6C_name_4E);

void func_80107324_32ECE4_name_4E(void) {
}

__asm__(".section .rodata");
const char D_8010D9C8_335388_name_4E[] = "  ALL  ";

__asm__(".section .rodata");
const char D_8010D9D0_335390_name_4E[] = "  DK   ";

__asm__(".section .rodata");
const char D_8010D9D8_335398_name_4E[] = " WARIO ";

__asm__(".section .rodata");
const char D_8010D9E0_3353A0_name_4E[] = " YOSHI ";

__asm__(".section .rodata");
const char D_8010D9E8_3353A8_name_4E[] = " PEACH ";

__asm__(".section .rodata");
const char D_8010D9F0_3353B0_name_4E[] = " LUIGI ";

__asm__(".section .rodata");
const char D_8010D9F8_3353B8_name_4E[] = " MARIO ";

__asm__(".section .rodata");
const char D_8010DA00_3353C0_name_4E[] = "WON\304 ";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_8010732C_32ECEC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107554_32EF14_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_8010760C_32EFCC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107638_32EFF8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801076C0_32F080_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801076E4_32F0A4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801076F4_32F0B4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107718_32F0D8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107748_32F108_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107804_32F1C4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801078EC_32F2AC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107940_32F300_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801079AC_32F36C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801079EC_32F3AC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107D3C_32F6FC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107E34_32F7F4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80107F10_32F8D0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_8010832C_32FCEC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_8010896C_33032C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80108A18_3303D8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80108BE0_3305A0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80108E3C_3307FC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80108F24_3308E4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80109750_331110_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80109778_331138_name_4E);
