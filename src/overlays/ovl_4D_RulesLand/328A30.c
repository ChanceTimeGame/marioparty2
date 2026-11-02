#include "common.h"
#include "ovl_4D.h"

void func_80102800_328A30_RulesLand(void) {
    D_80104004_32A234_RulesLand = GwSystem.current_board_index;
    omInitObjMan(0x32, 10);
    func_80103590_3297C0_RulesLand();
    func_80103438_329668_RulesLand();
    func_80088640_89240();
    omAddPrcObj(func_80103294_3294C4_RulesLand, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_801033E4_329614_RulesLand);
}

void func_80102880_328AB0_RulesLand(s32 a, s32 b) {
    GW_PLAYER* pa;
    GW_PLAYER* pb;
    GW_PLAYER* tmp;

    pa = BoardPlayerGet(a);
    pb = BoardPlayerGet(b);
    tmp = HuMemMemoryAllocPerm(sizeof(GW_PLAYER));
    bcopy(pa, tmp, sizeof(GW_PLAYER));
    bcopy(pb, pa, sizeof(GW_PLAYER));
    bcopy(tmp, pb, sizeof(GW_PLAYER));
    HuMemMemoryFreePerm(tmp);
}

void func_80102908_328B38_RulesLand(void) {
    s32 i;
    s32 j;

    for (i = 3; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if ((u8)gPlayers[j].unk_1C[0] > (u8)gPlayers[j + 1].unk_1C[0]) {
                func_80102880_328AB0_RulesLand(j, j + 1);
            }
        }
    }
}

void func_801029AC_328BDC_RulesLand(MBModel* model) {
    HuPrcSleep(5);
    model->jumpVel = 20.0f;
    model->jumpAccel = -2.5f;
    MBMotionSet(model, 2, 0);
    HuPrcSleep(10);
    model->jumpVel = 0.0f;
    model->jumpAccel = 0.0f;
    while (MBMotionCheck(model) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(model, 0, 2);
    D_80103DD0_32A000_RulesLand = 1;
}

void func_80102A50_328C80_RulesLand(MBModel* model) {
    model->jumpVel = 20.0f;
    model->jumpAccel = -3.0f;
    MBMotionSet(model, 0, 0);
    HuPrcSleep(3);
    while (MBMotionCheck(model) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(model, -1, 2);
}

void func_80102AD4_328D04_RulesLand(void) {
    Vec dir;
    f32 speed[4];
    MBModel* tile;
    Vec* target;
    f32 zero;
    f32 step;
    s32 count;
    s32 i;
    s32 j;

    tile = func_80043510_44110(0xE, NULL);
    func_800B3170_B3D70(&tile->pos, &D_80103DD4_32A004_RulesLand);
    HuVecCopyXYZ(&tile->scale, 0.0f, 0.0f, 0.0f);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeIn(2, 16);
    HuPrcSleep(16);
    PlaySound(0x326);
    for (i = 0; i < 90; i += 10) {
        tile->scale.z = 1.0f;
        tile->scale.x = 1.0f;
        tile->scale.y = __sinf(i * 0.017453292519943295);
        HuPrcVSleep();
    }
    D_80103DA0_329FD0_RulesLand[0] = func_80043510_44110(0xA8, D_80103F0C_32A13C_RulesLand);
    D_80103DA0_329FD0_RulesLand[0]->attr |= 1;
    func_800B3170_B3D70(&D_80103DA0_329FD0_RulesLand[0]->pos, &D_80103DD4_32A004_RulesLand);
    HuVecCopyXYZ(&D_80103DA0_329FD0_RulesLand[0]->scale, 0.65f, 0.65f, 0.65f);
    D_80103DA0_329FD0_RulesLand[0]->obj->rot.x = -10.0f;
    func_80056658_57258(&D_80103DA0_329FD0_RulesLand[0]->pos, (Vec*)((u8*)D_800FD2A8_FDEA8 + 0xC), &D_80103DA0_329FD0_RulesLand[0]->rot);
    for (i = 0; i < 4; i++) {
        func_8005E130_5ED30(i, D_80103EF4_32A124_RulesLand[gPlayers[i].character]);
        func_800B3170_B3D70(&PM(i)->pos, &D_80103DD4_32A004_RulesLand);
        gPlayers[i].flags |= 2;
        func_80056658_57258(&PM(i)->pos, (Vec*)((u8*)D_800FD2A8_FDEA8 + 0xC), &PM(i)->rot);
        MBMotionSet(PM(i), 0, 0);
        MBModelDispOff(PM(i));
        func_80029E80_2AA80(*PM(i)->obj->model, 2, 1);
    }
    PlaySound(0x328);
    MBModelDispOn(D_80103DA0_329FD0_RulesLand[0]);
    step = HuVecDistance(&D_80103DA0_329FD0_RulesLand[0]->pos, &D_80103F1C_32A14C_RulesLand) / 6.0f;
    func_80056658_57258(&D_80103DA0_329FD0_RulesLand[0]->pos, &D_80103F1C_32A14C_RulesLand, &dir);
    for (i = 0; i < 6; i++) {
        D_80103DA0_329FD0_RulesLand[0]->pos.x += step * dir.x;
        D_80103DA0_329FD0_RulesLand[0]->jumpY += step * dir.y;
        D_80103DA0_329FD0_RulesLand[0]->pos.z += step * dir.z;
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        PlaySound(0x328);
        MBMotionSet(PM(i), 0, 0);
        MBModelDispOn(PM(i));
        step = HuVecDistance(&PM(i)->pos, target = &D_80103F28_32A158_RulesLand[i]) / 6.0f;
        func_80056658_57258(&PM(i)->pos, target, &dir);
        for (j = 0; j < 6; j++) {
            PM(i)->pos.x += step * dir.x;
            PM(i)->jumpY += step * dir.y;
            PM(i)->pos.z += step * dir.z;
            HuPrcVSleep();
        }
    }
    PlaySound(0x327);
    for (i = 90; i >= 0; i -= 10) {
        tile->scale.y = __sinf(i * 0.017453292519943295);
        HuPrcVSleep();
    }
    MBModelKill(tile);
    speed[0] = 0.59f;
    speed[1] = 1.21f;
    speed[2] = 0.77f;
    speed[3] = 1.0f;
    for (i = 0; i < 4; i++) {
        PM(i)->pos.x = D_80103DEC_32A01C_RulesLand[i].x;
        PM(i)->pos.z = D_80103DEC_32A01C_RulesLand[i].z;
    }
    while (1) {
        count = 0;
        for (i = 0; i < 4; i++) {
            PM(i)->jumpY -= speed[i];
            if (PM(i)->jumpY <= 0.0f) {
                PM(i)->jumpY = 0.0f;
                if (speed[i] != 0.0f) {
                    MBMotionShiftSet(PM(i), 2, 0, 5, 2);
                }
                speed[i] = 0.0f;
                count++;
            }
            speed[i] *= 1.1f;
        }
        if (count == 4) {
            break;
        }
        HuPrcVSleep();
    }
    speed[0] = 50.0f;
    D_80103DA0_329FD0_RulesLand[0]->pos.x = D_80103DE0_32A010_RulesLand.x;
    D_80103DA0_329FD0_RulesLand[0]->pos.y = D_80103DE0_32A010_RulesLand.y;
    D_80103DA0_329FD0_RulesLand[0]->pos.z = D_80103DE0_32A010_RulesLand.z;
    D_80103DA0_329FD0_RulesLand[0]->jumpY = 700.0f;
    func_80056658_57258(&D_80103DA0_329FD0_RulesLand[0]->pos, (Vec*)((u8*)D_800FD2A8_FDEA8 + 0xC), &D_80103DA0_329FD0_RulesLand[0]->rot);
    goto fall;
    do {
        HuPrcVSleep();
    fall:
        D_80103DA0_329FD0_RulesLand[0]->jumpY -= speed[0];
    } while (!(D_80103DA0_329FD0_RulesLand[0]->jumpY <= (zero = 0.0f)));
    D_80103DA0_329FD0_RulesLand[0]->jumpY = zero;
    MBMotionSet(D_80103DA0_329FD0_RulesLand[0], 0, 2);
}

void func_80103220_329450_RulesLand(void) {
    s32 i;

    func_80102A50_328C80_RulesLand(D_80103DA0_329FD0_RulesLand[0]);
    D_80103DC8_329FF8_RulesLand = 1;
    func_80046238_46E38();
    func_800461C8_46DC8();
    for (i = 0; i < 4; i++) {
        func_80046F98_47B98(i);
        func_80046308_46F08(i);
    }
    func_80047D2C_4892C();
    HuPrcSleep(20);
}

void func_80103294_3294C4_RulesLand(void) {
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80102AD4_328D04_RulesLand();
    PlayMusic(5);
    func_801036E0_329910_RulesLand();
    func_80103220_329450_RulesLand();
    func_80103748_329978_RulesLand();
    D_801011FC_101DFC = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_80103330_329560_RulesLand(void) {
    s32 i;

    if (func_8008F618_90218() == 0) {
        func_8010364C_32987C_RulesLand();
        func_80103464_329694_RulesLand();
        func_8008CE5C_8DA5C();
        if (D_80103DC0_329FF0_RulesLand != 0) {
            func_8005FF9C_60B9C();
        }
        if (D_80103DC4_329FF4_RulesLand != 0) {
            func_8006AE14_6BA14(&D_80103F90_32A1C0_RulesLand);
        }
        for (i = 0; i < 16; i++) {
            if (D_80103D50_329F80_RulesLand[i] != NULL) {
                omDelObj(D_80103D50_329F80_RulesLand[i]);
            }
        }
        omOvlReturnEx(1);
    }
}

void func_801033E4_329614_RulesLand(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        func_8008F624_90224(0xFF, 0xFF, 0xFF);
        InitFadeOut(2, 20);
        obj->func_ptr = func_80103330_329560_RulesLand;
    }
}

void func_80103438_329668_RulesLand(void) {
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
}

void func_80103464_329694_RulesLand(void) {
    s32* sprite;
    MBModel** model;
    omObjData** obj;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    for (i = 0; i < 4; i++) {
        sprite = &D_80103D90_329FC0_RulesLand[i];
        if (*sprite != -1) {
            func_800283DC_28FDC(*sprite);
            *sprite = -1;
        }
        model = &D_80103DA0_329FD0_RulesLand[i];
        if (*model != NULL) {
            MBModelKill(*model);
            *model = NULL;
        }
        obj = &D_80103DB0_329FE0_RulesLand[i];
        if (*obj != NULL) {
            omDelObj(*obj);
            *obj = NULL;
        }
    }
    if (D_80103DC8_329FF8_RulesLand != 0) {
        func_80047B78_48778();
    }
    if (D_80103DCC_329FFC_RulesLand != NULL) {
        omDelPrcObj(D_80103DCC_329FFC_RulesLand);
    }
    func_80059400_5A000();
}

void func_80103590_3297C0_RulesLand(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(0x3C);
    func_8005321C_53E1C(200.0f, 2500.0f);
}

void func_8010364C_32987C_RulesLand(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}

void func_80103670_3298A0_RulesLand(void) {
    if (D_80103DD0_32A000_RulesLand == 0) {
        D_80104006_32A236_RulesLand = func_8008DFC4_8EBC4(0x50, 0xCA, 3);
    } else {
        D_80104006_32A236_RulesLand = func_8008DFC4_8EBC4(0x50, 0xA4, 3);
    }
}

void func_801036B0_3298E0_RulesLand(void) {
    func_8008E4D0_8F0D0(D_80104006_32A236_RulesLand, 1);
    func_8008E6AC_8F2AC(D_80104006_32A236_RulesLand);
}

void func_801036E0_329910_RulesLand(void) {
    func_80103670_3298A0_RulesLand();
    func_800890CC_89CCC(D_80104006_32A236_RulesLand, 0x61C, -1, -1);
    func_80089A48_8A648(D_80104006_32A236_RulesLand, 0);
    func_8008E2DC_8EEDC(D_80104006_32A236_RulesLand, 1);
    func_8005812C_58D2C(D_80104006_32A236_RulesLand);
    func_801036B0_3298E0_RulesLand();
}

void func_80103748_329978_RulesLand(void) {
    s32 timer[4];
    u8 state[4];
    u8 count[4];
    u8 order[4];
    u8* p;
    u8* q;
    s32 i;
    s32 j;
    s32 n;
    s32 left;
    s32 wait;

    func_80103670_3298A0_RulesLand();
    func_800890CC_89CCC(D_80104006_32A236_RulesLand, 0x61D, -1, -1);
    func_80089A48_8A648(D_80104006_32A236_RulesLand, 0);
    func_8008E2DC_8EEDC(D_80104006_32A236_RulesLand, 1);
    func_8005812C_58D2C(D_80104006_32A236_RulesLand);
    func_801036B0_3298E0_RulesLand();
    for (i = 0; i < 4; i++) {
        switch (gPlayers[i].character) {
            case 0:
                n = 10;
                break;
            case 1:
                n = (rand8() & 3) + 6;
                break;
            case 2:
                n = (rand8() & 3) + 2;
                break;
            case 3:
            case 4:
                n = 1;
                break;
            default:
                n = 5;
                break;
        }
        func_80047DB0_489B0(i, n);
    }
    for (i = 0; i < 4; i++) {
        state[i] = 1;
        count[i] = 0;
        timer[i] = 10;
    }
    while (1) {
        for (i = 0; i < 4; i++) {
            left = timer[i] - 1;
            timer[i] = left;
            if (state[i] == 1) {
                if (gPlayers[i].flags & 1) {
                    if (left <= 0) {
                        goto hit;
                    }
                } else if (ContBtnTrg[gPlayers[i].port] & 0x8000) {
                hit:
                    state[i] = 2;
                    MBMotionSet(PM(i), 5, 0);
                    func_80059520_5A120(PM(i), 2, 2);
                }
            } else {
                p = &state[i];
                if (*p == 2) {
                    q = &count[i];
                    *q += 1;
                    if (*q == 5) {
                        func_80047BB8_487B8(i);
                        *p = 0;
                    }
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (state[i] != 0) {
                break;
            }
        }
        if (i == 4) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        state[i] = func_80047DE8_489E8(i);
        order[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (state[i] < state[j]) {
                timer[0] = state[i];
                state[i] = state[j];
                state[j] = timer[0];
                timer[0] = order[i];
                order[i] = order[j];
                order[j] = timer[0];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        gPlayers[order[i]].unk_1C[0] = i;
        func_80046CD8_478D8(i);
    }
    func_80102908_328B38_RulesLand();
    func_8005FE10_60A10();
    D_80103DC0_329FF0_RulesLand = 1;
    for (i = 0; i < 4; i++) {
        HidePlayerHUDVisibility(i, 1);
    }
    HuPrcSleep(5);
    func_80103670_3298A0_RulesLand();
    func_800890CC_89CCC(D_80104006_32A236_RulesLand, 0x61E, -1, -1);
    func_80089A48_8A648(D_80104006_32A236_RulesLand, 0);
    func_8008E2DC_8EEDC(D_80104006_32A236_RulesLand, 1);
    func_8005812C_58D2C(D_80104006_32A236_RulesLand);
    for (i = 0; i < 4; i++) {
        if (i != 0) {
            func_80103670_3298A0_RulesLand();
        } else {
            func_8008AD44_8B944(D_80104006_32A236_RulesLand);
        }
        func_800890CC_89CCC(D_80104006_32A236_RulesLand, i + 0x61F, -1, -1);
        func_80089A48_8A648(D_80104006_32A236_RulesLand, 0);
        if (i != 0) {
            func_8008E2DC_8EEDC(D_80104006_32A236_RulesLand, 1);
        }
        func_8005812C_58D2C(D_80104006_32A236_RulesLand);
        func_801036B0_3298E0_RulesLand();
        func_800595E8_5A1E8(PM(i), 6, 0);
        func_80079718_7A318(0x103, gPlayers[i].character);
        func_80046D2C_4792C(order[i]);
        func_80060210_60E10(i + 10);
        if (i == 2) {
            func_801029AC_328BDC_RulesLand(D_80103DA0_329FD0_RulesLand[0]);
        }
        while (func_800609D8_615D8() != 0) {
            HuPrcVSleep();
        }
        wait = 20;
        if (i == 2) {
            wait = 10;
        }
        HuPrcSleep(wait);
    }
    func_80103670_3298A0_RulesLand();
    func_800890CC_89CCC(D_80104006_32A236_RulesLand, 0x623, -1, -1);
    func_80089A48_8A648(D_80104006_32A236_RulesLand, 0);
    func_8008E2DC_8EEDC(D_80104006_32A236_RulesLand, 1);
    func_8005812C_58D2C(D_80104006_32A236_RulesLand);
    func_801036B0_3298E0_RulesLand();
    func_80047B78_48778();
}
