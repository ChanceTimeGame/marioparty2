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
            D_801013B8_101FB8.unk40 = 0;
        }
    } else {
        D_8010DAB6_335476_name_4E = 0;
        D_8010DBE0_3355A0_name_4E = 2;
        D_801013B8_101FB8.unk40 = 7;
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
    s16 state;
    s16 confirm;

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
            D_801013B8_101FB8.unk40 = 7;
            state = 3;
            break;
        case 1:
            if (func_80103608_32AFC8_name_4E() == 0) {
                state = 0;
                break;
            }
            state = 3;
            if (D_801013B8_101FB8.unk40 < 3) {
                state = (D_801013B8_101FB8.unk40 < 1) ? 3 : 2;
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
                D_801013B8_101FB8.unk40 = D_8010D614_334FD4_name_4E[D_8010E5F2_335FB2_name_4E];
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
    if (D_801013B8_101FB8.unk40 == 1) {
        ofs = D_8010D61C_334FDC_name_4E;
        max = 3;
    } else {
        max = 2;
        ofs = D_8010D628_334FE8_name_4E;
    }
    func_80105090_32CA50_name_4E();
    D_8010DBE3_3355A3_name_4E = 15;
    if (D_801013B8_101FB8.unk40 == 1) {
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
        if (D_801013B8_101FB8.unk40 == 1) {
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
            if (D_801013B8_101FB8.unk40 == 1) {
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
        switch (D_801013B8_101FB8.unk40) {
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

void func_801047B8_32C178_name_4E(s16 x0, s16 y0, s16 x1, s16 y1) {
    D_8010DC22_3355E2_name_4E = x0;
    D_8010DC24_3355E4_name_4E = x1;
    D_8010DC26_3355E6_name_4E = y0;
    D_8010DC28_3355E8_name_4E = y1;
    D_8010DC21_3355E1_name_4E = 1;
}

void func_801047E8_32C1A8_name_4E(void) {
    s16 grp0;
    s16 grp1;
    s16 arrow0;
    s16 arrow1;
    s16 hint;
    s8 prev;
    s8 fading;
    s16 alpha;
    s16 old;
    s32 step;

    prev = 0;
    fading = 0;
    D_8010DC20_3355E0_name_4E = 0;
    D_8010DC21_3355E1_name_4E = 0;
    grp0 = func_8001A2F8_1AEF8(0x900C7);
    grp1 = func_8001A2F8_1AEF8(0x900C8);
    arrow0 = func_8001AAAC_1B6AC(grp0, 0, 1);
    arrow1 = func_8001AAAC_1B6AC(grp1, 0, 1);
    func_8001A788_1B388(arrow0, 0x4800);
    func_8001A788_1B388(arrow1, 0x4800);
    espPosSet(arrow0, 0xA0, 0x78);
    espPosSet(arrow1, 0xA0, 0x78);
    espDispOff(arrow0);
    espDispOff(arrow1);
    hint = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA0160), 0, 1);
    func_8001A788_1B388(hint, 0x4800);
    espDispOff(hint);
    alpha = 0;
    step = 0;
    while (1) {
        HuPrcVSleep();
        if (prev != D_8010DC20_3355E0_name_4E) {
            prev = D_8010DC20_3355E0_name_4E;
            fading = 1;
            step = -63;
            if (D_8010DC20_3355E0_name_4E != 0) {
                step = 63;
            }
        }
        if (fading) {
            old = alpha;
            alpha += step;
            if (alpha >= 255) {
                fading = 0;
                alpha = 255;
            } else if (alpha <= 0) {
                fading = 0;
                alpha = 0;
            }
            if (alpha != 0) {
                if (old == 0) {
                    espDispOn(arrow0);
                    espDispOn(arrow1);
                    if (D_801013B8_101FB8.unk40 == 1) {
                        espPosSet(hint, 0x96, 0x98);
                    } else {
                        espPosSet(hint, 0xA0, 0x98);
                    }
                    espDispOn(hint);
                }
                func_8001A6BC_1B2BC(arrow0, alpha);
                func_8001A6BC_1B2BC(arrow1, alpha);
                func_8001A6BC_1B2BC(hint, alpha);
            } else {
                espDispOff(arrow0);
                espDispOff(arrow1);
                espDispOff(hint);
            }
        }
        if (D_8010DC21_3355E1_name_4E != 0) {
            espPosSet(arrow0, D_8010DC22_3355E2_name_4E, D_8010DC26_3355E6_name_4E);
            espPosSet(arrow1, D_8010DC24_3355E4_name_4E, D_8010DC28_3355E8_name_4E);
            D_8010DC21_3355E1_name_4E = 0;
        }
    }
}

void func_80104A9C_32C45C_name_4E(void) {
    s32 i;
    s16 n;

    for (i = 0; i < 4; i++) {
        n = D_800FC9B8_FD5B8[2 + i];
        gPlayers[i].stars = n;
        gPlayers[i].coins_mg_bonus = n;
    }
}

#ifdef NON_MATCHING
/* After the team menu: pick the minigame (one available: it; otherwise the list, func_8010A660..
   func_8010AB58), set the teams (gPlayers[].group), show its name and messages, then leave:
   D_8010DAB6 (minigame mode) -> event 4 for the chosen minigame; else a duel on board
   D_8010D5FE[chosen] with the D_800FA040 order (event 5). Returns 0 when backed out.
   Retail reloads D_801013F8 with lui/lh in the one-minigame branch where this C keeps its
   address in s0: register allocation only. */
s32 func_80104AF0_32C4B0_name_4E(void) {
    s32 mes;
    s32 i;

    func_8010CF6C_33492C_name_4E();
    if (D_8010DAB6_335476_name_4E == 0 && D_8010DCA0_335660_name_4E[D_801013B8_101FB8.unk40] == 0) {
        return 0;
    }
    D_800F9512_FA112 = 0;
    if (D_8010DCA0_335660_name_4E[D_801013B8_101FB8.unk40] >= 2 && (D_800F904A != 0 || D_8010DAB6_335476_name_4E != 0)) {
        if (D_800FC8F0_FD4F0[2] == 0 && !(D_800CD414_CE014 & 4)) {
            mes = D_8010DC2C_3355EC_name_4E[2];
        } else {
            mes = D_8010DC2C_3355EC_name_4E[3];
        }
        func_8010760C_32EFCC_name_4E(mes);
        func_80107638_32EFF8_name_4E();
    }
    if (D_8010DAB6_335476_name_4E != 0) {
        func_8010A660_332020_name_4E(D_801013B8_101FB8.unk40);
        func_8010AB48_332508_name_4E();
        while (func_8010AB58_332518_name_4E() != -1) {
            HuPrcVSleep();
        }
    } else if (D_8010DCA0_335660_name_4E[D_801013B8_101FB8.unk40] == 1) {
        func_8010760C_32EFCC_name_4E(0xA3);
        func_80107638_32EFF8_name_4E();
        GwSystem.chosenMinigameIndex = D_8010DCC0_335680_name_4E[D_801013B8_101FB8.unk40][0];
    } else if (D_800F904A != 0) {
        func_8010A660_332020_name_4E(D_801013B8_101FB8.unk40);
        func_8010AB48_332508_name_4E();
        while (func_8010AB58_332518_name_4E() != -1) {
            HuPrcVSleep();
        }
    } else {
        func_8010760C_32EFCC_name_4E(0xA6);
        func_80107638_32EFF8_name_4E();
        func_8010AB64_332524_name_4E();
        func_8010AB48_332508_name_4E();
        while (func_8010AB58_332518_name_4E() != -1) {
            HuPrcVSleep();
        }
        if (GwSystem.chosenMinigameIndex < 0) {
            return 0;
        }
    }
    D_8010D1F2_334BB2_name_4E = 9;
    switch (D_801013B8_101FB8.unk40) {
    case 1:
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = 1;
        }
        gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
        break;
    case 2:
        gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
        gPlayers[D_800F9D48_FA948[0x2F9]].group = 0;
        gPlayers[D_800F9D48_FA948[0x2FA]].group = 1;
        gPlayers[D_800F9D48_FA948[0x2FB]].group = 1;
        break;
    case 3:
        D_8010D1F2_334BB2_name_4E = 0xB;
        /* fallthrough */
    case 0:
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = i;
        }
        if (GwSystem.chosenMinigameIndex == 0xB || GwSystem.chosenMinigameIndex == 0x41) {
            func_80104A9C_32C45C_name_4E();
        }
        break;
    }
    func_80107718_32F0D8_name_4E(GwSystem.chosenMinigameIndex + 0x3D8, 0);
    func_8010760C_32EFCC_name_4E(D_8010DC2C_3355EC_name_4E[4]);
    func_80107638_32EFF8_name_4E();
    if (D_8010DAB6_335476_name_4E != 0) {
        func_80089284_89E84(D_8010DB60_335520_name_4E, 1, 1);
        func_8010760C_32EFCC_name_4E(D_8010DC2C_3355EC_name_4E[5]);
        _SetFlag(0x13);
        if (func_80107638_32EFF8_name_4E() != 0) {
            GwSystem.unk_25 = 0;
        } else {
            GwSystem.unk_25 = 1;
        }
        func_80089284_89E84(D_8010DB60_335520_name_4E, 1, 0);
        D_8010DC90_335650_name_4E = 2;
        D_8010E140_335B00_name_4E = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
        D_8010E618_335FD8_name_4E = 0;
        omOvlHisChg(0, 0x4E, 4, 0x11);
    } else {
        D_8010D1F2_334BB2_name_4E = 0xB;
        D_800F8D1A_F991A.attacker = 1 << D_800F9D48_FA948[0x2F8];
        D_800F8D1A_F991A.targets = 1 << D_800F9D48_FA948[0x2F9];
        GwSystem.current_board_index = D_8010D5FE_334FBE_name_4E[GwSystem.chosenMinigameIndex];
        _SetFlag(0x13);
        D_8010DC90_335650_name_4E = 2;
        D_8010E140_335B00_name_4E = D_800CAD90[GwSystem.chosenMinigameIndex - 1].unk_00;
        D_8010E618_335FD8_name_4E = 0;
        omOvlHisChg(0, 0x4E, 5, 0x11);
    }
    D_8010D1F0_334BB0_name_4E = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80104AF0_32C4B0_name_4E);
#endif

void func_80105090_32CA50_name_4E(void) {
    s32 i;

    for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
        D_8010DBE8_3355A8_name_4E[i].x = PLAYER_MODEL(i)->pos.x;
        D_8010DBE8_3355A8_name_4E[i].y = PLAYER_MODEL(i)->pos.y;
        D_8010DBE8_3355A8_name_4E[i].z = PLAYER_MODEL(i)->pos.z;
    }
    D_8010DBE3_3355A3_name_4E = 0;
    D_8010DBE4_3355A4_name_4E = 20;
}

void func_80105148_32CB08_name_4E(void) {
    s32 i;

    for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
        D_8010DA80_335440_name_4E[i] = 0;
    }
    D_8010DBE3_3355A3_name_4E = 0;
    D_8010DBE4_3355A4_name_4E = 20;
    while (1) {
        for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
            if (D_8010DA80_335440_name_4E[i] != 0) {
                if (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010DBE8_3355A8_name_4E[i], D_8010DBE4_3355A4_name_4E) == 1) {
                    PLAYER_MODEL(i)->pos.x = D_8010DBE8_3355A8_name_4E[i].x;
                    PLAYER_MODEL(i)->pos.y = D_8010DBE8_3355A8_name_4E[i].y;
                    PLAYER_MODEL(i)->pos.z = D_8010DBE8_3355A8_name_4E[i].z;
                    MBMotionSet(PLAYER_MODEL(i), 0, 2);
                    func_80056658_57258(&PLAYER_MODEL(i)->pos, &OVL4E_CAMERA->pos, &PLAYER_MODEL(i)->rot);
                    D_8010DA80_335440_name_4E[i] = 0;
                }
            } else if (((D_8010DBE3_3355A3_name_4E >> i) & 1) &&
                       (PLAYER_MODEL(i)->pos.x != D_8010DBE8_3355A8_name_4E[i].x ||
                        PLAYER_MODEL(i)->pos.y != D_8010DBE8_3355A8_name_4E[i].y ||
                        PLAYER_MODEL(i)->pos.z != D_8010DBE8_3355A8_name_4E[i].z)) {
                MBMotionSet(PLAYER_MODEL(i), 1, 2);
                D_8010DA80_335440_name_4E[i] = 1;
            }
        }
        HuPrcVSleep();
    }
}

void func_801053E0_32CDA0_name_4E(s32 player, s16 motion, u16 attr) {
    MBMotionSet(PLAYER_MODEL(player), motion, attr);
    if (motion == 2) {
        func_800797DC_7A3DC(0x103, player);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_80105454_32CE14_name_4E);

s32 func_80105F80_32D940_name_4E(void) {
    s16 winners[4];
    s32 n;
    s32 i;
    s16 target;
    s16 count;
    s16 best;
    s16 score;

    n = 0;
    target = D_8010D448_334E08_name_4E[D_800FA1A8];
    count = 0;
    if (D_801013B8_101FB8.unk40 == 3) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].coins_mg_bonus == 0) {
                winners[n++] = i;
            }
        }
        if (n == 0) {
            return count;
        }
        for (i = 0; i < n; i++) {
            if (D_800FC9B8_FD5B8[2 + winners[i]] + 1 >= target) {
                count++;
            }
        }
    } else if (D_801013B8_101FB8.unk40 == 7) {
        if (D_800FC880_FD480 != -1 && D_800FC880_FD480 < 4) {
            winners[n++] = D_800FC880_FD480;
        }
        if (n != 0) {
            if (n == D_8010DBE0_3355A0_name_4E) {
                return count;
            }
            for (i = 0; i < n; i++) {
                if (D_800FC9B8_FD5B8[2 + winners[i]] + 1 >= target) {
                    count++;
                }
            }
        }
    } else {
        best = 1;
        for (i = 0; i < 4; i++) {
            switch (GwSystem.chosenMinigameIndex) {
            case 0x19:
            case 0x24:
            case 0x38:
            case 0x47:
            case 0x48:
                score = gPlayers[i].coins_mg;
                break;
            default:
                score = gPlayers[i].coins_mg_bonus;
                break;
            }
            if (best <= score) {
                if (best < score) {
                    best = score;
                    n = 0;
                }
                winners[n++] = i;
            }
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_800FC9B8_FD5B8[2 + winners[i]] + 1 >= target) {
                    count++;
                }
            }
        }
    }
    return count;
}

s32 func_80106228_32DBE8_name_4E(u8* wins) {
    s16 winners[4];
    s32 n;
    s32 i;
    s16 best;
    s16 score;

    n = 0;
    if (D_801013B8_101FB8.unk40 == 3) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].coins_mg_bonus == 0) {
                winners[n++] = i;
            }
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                D_800FC9B8_FD5B8[2 + winners[i]]++;
                wins[winners[i]]++;
            }
        }
    } else {
        best = 1;
        if (D_801013B8_101FB8.unk40 == 7) {
            if (D_800FC880_FD480 != -1 && D_800FC880_FD480 < 4) {
                winners[n++] = D_800FC880_FD480;
            }
            if (n == 0 || n == D_8010DBE0_3355A0_name_4E) {
                n = 0;
            } else {
                for (i = 0; i < n; i++) {
                    D_800FC9B8_FD5B8[2 + winners[i]]++;
                    wins[winners[i]]++;
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                switch (GwSystem.chosenMinigameIndex) {
                case 0x19:
                case 0x24:
                case 0x38:
                case 0x47:
                case 0x48:
                    score = gPlayers[i].coins_mg;
                    break;
                default:
                    score = gPlayers[i].coins_mg_bonus;
                    break;
                }
                if (best <= score) {
                    if (best < score) {
                        best = score;
                        n = 0;
                    }
                    winners[n++] = i;
                }
            }
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    D_800FC9B8_FD5B8[2 + winners[i]]++;
                    wins[winners[i]]++;
                }
            }
        }
    }
    return n;
}

#ifdef NON_MATCHING
/* The win stamps: for each winner (wins[player] != 0; a team's members share one stamp in team
   modes 1 and 2) a stamp sprite (D_8010DB20[D_8010DBDE++]) is placed in the player's row at the
   column of their new win count, then shrinks from scale 4 while fading in; when it lands the
   winners react (func_8005A4EC(player, 3)) and sound 0x37A plays.
   Same logic as retail; retail's frame is 32 bytes larger (wins spilled to the stack) and its
   registers differ. */
void func_801064F0_32DEB0_name_4E(u8* wins) {
    s8 who[4][4];
    s16 sprs[4];
    s16 alpha[4];
    f32 scale[4];
    s16 i;
    s32 j;
    f32 delay;
    s32 x0;
    s32 y;
    s16 n;
    s32 k;
    s32 p;
    s16 spr;
    s32 max;
    s16 cnt;
    s32 end;
    s32 left;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            who[i][j] = -1;
        }
    }
    delay = 4.0f;
    x0 = D_8010D4AC_334E6C_name_4E[D_800FA1A8] + 36;
    y = (D_801013B8_101FB8.unk40 == 2) ? 0x56 : 0x40;
    n = 0;
    switch (D_801013B8_101FB8.unk40) {
    case 0:
    case 3:
    case 7:
        for (k = 0; k < D_8010DBE0_3355A0_name_4E; k++) {
            p = D_800F9D48_FA948[0x2F8 + k];
            if (wins[p] != 0) {
                spr = D_8010DB20_3354E0_name_4E[D_8010DBDE_33559E_name_4E++];
                espPosSet(spr, x0 + ((D_800FC9B8_FD5B8[2 + p] - 1) << 5), y);
                func_8001A6BC_1B2BC(spr, 0);
                func_8001A91C_1B51C(spr, 4.0f, 4.0f);
                who[n][0] = p;
                sprs[n] = spr;
                alpha[n] = 0;
                scale[n] = delay;
                delay += 1.0f;
                n++;
            }
            y += 0x2C;
        }
        break;
    case 1:
        p = D_800F9D48_FA948[0x2F8];
        if (wins[p] != 0) {
            spr = D_8010DB20_3354E0_name_4E[D_8010DBDE_33559E_name_4E++];
            espPosSet(spr, x0 + ((D_800FC9B8_FD5B8[2 + p] - 1) << 5), y);
            func_8001A6BC_1B2BC(spr, 0);
            func_8001A91C_1B51C(spr, 4.0f, 4.0f);
            who[n][0] = p;
            sprs[n] = spr;
            alpha[n] = 0;
            scale[n] = delay;
            delay += 1.0f;
            n++;
        }
        max = 0;
        cnt = 0;
        for (k = 1; k < 4; k++) {
            p = D_800F9D48_FA948[0x2F8 + k];
            if (wins[p] != 0) {
                who[n][k - 1] = p;
                cnt++;
            }
            if (max < D_800FC9B8_FD5B8[2 + p]) {
                max = D_800FC9B8_FD5B8[2 + p];
            }
        }
        if (cnt != 0) {
            spr = D_8010DB20_3354E0_name_4E[D_8010DBDE_33559E_name_4E++];
            espPosSet(spr, x0 + ((max - 1) << 5), D_8010D44C_334E0C_name_4E[D_801013B8_101FB8.unk40] + y);
            func_8001A6BC_1B2BC(spr, 0);
            func_8001A91C_1B51C(spr, 4.0f, 4.0f);
            sprs[n] = spr;
            alpha[n] = 0;
            scale[n] = delay;
            n++;
        }
        break;
    case 2:
        k = 0;
        max = 0;
        for (end = 2; end < 5; end += 2) {
            cnt = 0;
            for (; k < end; k++) {
                p = D_800F9D48_FA948[0x2F8 + k];
                if (wins[p] != 0) {
                    who[n][k - (end - 2)] = p;
                    cnt++;
                }
                if (max < D_800FC9B8_FD5B8[2 + p]) {
                    max = D_800FC9B8_FD5B8[2 + p];
                }
            }
            if (cnt != 0) {
                spr = D_8010DB20_3354E0_name_4E[D_8010DBDE_33559E_name_4E++];
                espPosSet(spr, x0 + ((max - 1) << 5), y);
                func_8001A6BC_1B2BC(spr, 0);
                func_8001A91C_1B51C(spr, 4.0f, 4.0f);
                sprs[n] = spr;
                alpha[n] = 0;
                scale[n] = delay;
                delay += 1.0f;
                n++;
            }
            y += D_8010D44C_334E0C_name_4E[D_801013B8_101FB8.unk40];
            max = 0;
        }
        break;
    }
    do {
        HuPrcVSleep();
        left = n;
        for (k = 0; k < n; k++) {
            spr = sprs[k];
            if (alpha[k] >= 256) {
                if (scale[k] <= 0.0f) {
                    func_8001A6BC_1B2BC(spr, 255);
                    func_8001A91C_1B51C(spr, 1.0f, 1.0f);
                    PlaySound(0x37A);
                    for (j = 0; j < 4; j++) {
                        if (who[k][j] < 0) {
                            break;
                        }
                        func_8005A4EC_5B0EC(who[k][j], 3);
                    }
                    scale[k] = 180.0f;
                }
                left--;
            } else {
                scale[k] -= 0.25f;
                if (scale[k] < 4.0f) {
                    alpha[k] += 16;
                    func_8001A6BC_1B2BC(spr, alpha[k]);
                    func_8001A91C_1B51C(spr, scale[k], scale[k]);
                }
            }
        }
    } while (left != 0);
    HuPrcVSleep();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/32A1C0", func_801064F0_32DEB0_name_4E);
#endif

void func_80106BF8_32E5B8_name_4E(u16 spr, s32 dx, s32 dy) {
    Ovl4EEsprite* e = &((Ovl4EEsprite*)D_800F93FC_F9FFC)[spr];

    e->x += dx;
    e->y += dy;
}

void func_80106C30_32E5F0_name_4E(s16 grp, s16 idx, s16 dx, s16 dy) {
    HuSprite* spr = func_80082550_83150(grp, idx);

    spr->unk_48 += dx;
    spr->unk_4C += dy;
}

void func_80106CB0_32E670_name_4E(void) {
    s32 i;
    s32 n;

    for (n = 16; n != 0; n--) {
        func_80106BF8_32E5B8_name_4E(D_8010DB04_3354C4_name_4E, 0, 16);
        func_80106C30_32E5F0_name_4E(D_8010DB88_335548_name_4E[D_8010DBDC_33559C_name_4E], 0, 0, 16);
        for (i = 0; i < 5; i++) {
            if (D_8010DB10_3354D0_name_4E[i] >= 0) {
                func_80106BF8_32E5B8_name_4E(D_8010DB10_3354D0_name_4E[i], 0, 16);
            }
        }
        for (i = 0; i < 32; i++) {
            if (i >= D_8010DBDE_33559E_name_4E) {
                break;
            }
            if (D_8010DB20_3354E0_name_4E[i] >= 0) {
                func_80106BF8_32E5B8_name_4E(D_8010DB20_3354E0_name_4E[i], 0, 16);
            }
        }
        for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
            func_80106BF8_32E5B8_name_4E(D_8010DAFA_3354BA_name_4E[i], 0, 16);
        }
        HuPrcVSleep();
    }
}

void func_80106E18_32E7D8_name_4E(void) {
    s32 i;
    s32 n;

    for (n = 16; n != 0; n--) {
        func_80106BF8_32E5B8_name_4E(D_8010DB04_3354C4_name_4E, 0, -16);
        func_80106C30_32E5F0_name_4E(D_8010DB88_335548_name_4E[D_8010DBDC_33559C_name_4E], 0, 0, -16);
        for (i = 0; i < 5; i++) {
            if (D_8010DB10_3354D0_name_4E[i] >= 0) {
                func_80106BF8_32E5B8_name_4E(D_8010DB10_3354D0_name_4E[i], 0, -16);
            }
        }
        for (i = 0; i < 32; i++) {
            if (D_8010DB20_3354E0_name_4E[i] >= 0) {
                func_80106BF8_32E5B8_name_4E(D_8010DB20_3354E0_name_4E[i], 0, -16);
            }
        }
        for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
            func_80106BF8_32E5B8_name_4E(D_8010DAFA_3354BA_name_4E[i], 0, -16);
        }
        HuPrcVSleep();
    }
    func_8001AC44_1B844(D_8010DB04_3354C4_name_4E);
    SprAnimKill(D_8010DB02_3354C2_name_4E);
    func_80069654_6A254(D_8010DBDC_33559C_name_4E);
    func_8006985C_6A45C((GAMEMES*)D_8010DB68_335528_name_4E);
    for (i = 0; i < 5; i++) {
        if (D_8010DB10_3354D0_name_4E[i] >= 0) {
            func_8001AC44_1B844(D_8010DB10_3354D0_name_4E[i]);
        }
        if (D_8010DB06_3354C6_name_4E[i] >= 0) {
            SprAnimKill(D_8010DB06_3354C6_name_4E[i]);
        }
    }
    for (i = 0; i < 32; i++) {
        if (D_8010DB20_3354E0_name_4E[i] >= 0) {
            func_8001AC44_1B844(D_8010DB20_3354E0_name_4E[i]);
        }
    }
    SprAnimKill(D_8010DB1A_3354DA_name_4E);
    for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
        func_8001AC44_1B844(D_8010DAFA_3354BA_name_4E[i]);
        SprAnimKill(D_8010DAF2_3354B2_name_4E[i]);
    }
    for (i = 5; i != 0; i--) {
        HuPrcVSleep();
    }
}

void func_801070AC_32EA6C_name_4E(u8* list, s16 count) {
    s16 i;
    s32 j;
    s16 slot;
    s16 base;
    s16 model;
    Vec* pos;
    s16 player;

    if (count > 0) {
        D_8010DC1C_3355DC_name_4E = omAddObj(0x17D0, 6, 0, -1, func_80107324_32ECE4_name_4E);
        D_8010DC1C_3355DC_name_4E->model[0] = -1;
        pos = D_8010D4FC_334EBC_name_4E;
        switch (D_801013B8_101FB8.unk40) {
        case 0:
        case 3:
            pos = D_8010D4FC_334EBC_name_4E;
            break;
        case 7:
            pos = D_8010D52C_334EEC_name_4E;
            break;
        case 1:
            pos = D_8010D544_334F04_name_4E;
            break;
        case 2:
            pos = D_8010D574_334F34_name_4E;
            break;
        }
        slot = 1;
        base = -1;
        for (i = 0; i < D_8010DBE0_3355A0_name_4E; i++) {
            player = D_800F9D48_FA948[0x2F8 + i];
            for (j = 0; j < count; j++) {
                if (list[j] == player) {
                    break;
                }
            }
            if (j < count) {
                if (base < 0) {
                    base = model = LoadFormFile(0x340007, 0x4A9);
                } else {
                    model = func_80027D3C_2893C(base);
                }
                D_8010DC1C_3355DC_name_4E->model[slot] = model;
                slot++;
                func_8002979C_2A39C(model, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(model, 0.3f, 0.5f, 0.7f);
                func_80029714_2A314(model, pos[i].x, pos[i].y, pos[i].z - 64.0f);
            }
        }
        D_8010DC1C_3355DC_name_4E->work[0] = slot;
    }
}

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

/* Shows "<name> WON" (the winner's name in message sprites, centred at y 100). */
void func_8010732C_32ECEC_name_4E(s16 player) {
    char won[] = "WON\304 ";
    GAMEMES mes;
    char* name;
    f32 nameLen;
    f32 wonLen;
    f32 x;

    name = D_8010D694_335054_name_4E[gPlayers[player].character];
    nameLen = func_800A5610_A6210(name);
    wonLen = func_800A5610_A6210(won);
    func_8006A608_6B208(&mes, name, 1, -1, -1);
    func_8006A67C_6B27C(&mes, won, 1, -1, -1);
    x = 160.0f - ((nameLen + wonLen + 1.0f) * 22.0f) / 2.0f + (nameLen * 22.0f) / 2.0f;
    mes.unk60 = x;
    mes.unk64 = 100.0f;
    SprPosSet(mes.strGId[0], 0, x, 100.0f);
    mes.unk0C = x + nameLen * 22.0f;
    mes.unk60 = mes.unk0C;
    SprPosSet(mes.strGId[1], 0, mes.unk60, mes.unk64);
}

void func_80107554_32EF14_name_4E(void) {
    s16 win;

    D_8010DB60_335520_name_4E = win = func_8008DFC4_8EBC4(0x41, 0xC8, 2);
    func_8008E644_8F244(win, 0xC0);
    D_8010DB62_335522_name_4E = 0;
    while (1) {
        if (D_8010DB62_335522_name_4E == 1) {
            func_8008E2DC_8EEDC(D_8010DB60_335520_name_4E, 1);
            D_8010DB62_335522_name_4E = 0;
        }
        if (D_8010DA90_335450_name_4E != 0) {
            break;
        }
        HuPrcVSleep();
    }
    func_8008E4D0_8F0D0(D_8010DB60_335520_name_4E, 1);
    while (1) {
        HuPrcVSleep();
    }
}

void func_8010760C_32EFCC_name_4E(s32 mes) {
    func_800890CC_89CCC(D_8010DB60_335520_name_4E, mes, -1, -1);
}

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
