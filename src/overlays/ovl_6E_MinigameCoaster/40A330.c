#include "ovl_6E.h"

#define HOST D_80103E00_40B930_MinigameCoaster[0]
#define CAR D_80103E00_40B930_MinigameCoaster[3]

void func_80102800_40A330(void) {
    GwSystem.current_board_index = 7;
    omInitObjMan(50, 10);
    func_80103D34_40B864_MinigameCoaster();
    func_80103C5C_40B78C_MinigameCoaster();
    func_80088640_89240();
    func_8005E570_5F170();
    omAddPrcObj(&func_80103360_40AE90_MinigameCoaster, 0x300U, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_80103C18_40B748_MinigameCoaster);
}

void func_80102884_40A3B4_MinigameCoaster(s16 arg0) {
    s32 thing = 1 << gPlayers[0].port;
    func_8008D59C_8E19C(arg0, thing);
}

void func_801028B8_40A3E8_MinigameCoaster(void) {
    HuPrcSleep(0x16);
    func_80029E80_2AA80(CAR->obj->model[0], 2, 1);
    omDelPrcObj(NULL);
}

/* The arrival: a light (model 0xE) opens, host and players drop in one by one from it, it closes,
   the players fall to the ground; then the host falls in and the players hop aboard. */
void func_801028FC_40A42C_MinigameCoaster(void) {
    Vec dir;
    f32 fall[4];
    Vec pos;
    Vec pos2;
    MBModel* light;
    Vec* dest;
    f32 step;
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < 2; i++) {
        MBPlayerModelCreate(i, D_80103F4C_40BA7C_MinigameCoaster[gPlayers[i].character], 2);
        func_800B3170_B3D70(&PLAYER_MODEL(i)->pos, &D_80103E44_40B974_MinigameCoaster);
        gPlayers[i].flags |= 2;
        func_80056658_57258(&PLAYER_MODEL(i)->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &PLAYER_MODEL(i)->rot);
        MBMotionSet(PLAYER_MODEL(i), 0, 0);
        MBModelDispOff(PLAYER_MODEL(i));
        func_80029E80_2AA80(PLAYER_MODEL(i)->obj->model[0], 2, 1);
    }
    light = func_80043510_44110(0xE, NULL);
    func_800B3170_B3D70(&light->pos, &D_80103E44_40B974_MinigameCoaster);
    HuVecCopyXYZ(&light->scale, 0.0f, 0.0f, 0.0f);
    D_80103E00_40B930_MinigameCoaster[1] = func_80043510_44110(0xB0, NULL);
    func_80043DAC_449AC(D_80103E00_40B930_MinigameCoaster[1]);
    D_80103E00_40B930_MinigameCoaster[2] = func_80043510_44110(0xAF, NULL);
    func_80043DAC_449AC(D_80103E00_40B930_MinigameCoaster[2]);
    CAR = func_80043510_44110(0xAB, NULL);
    func_80043DAC_449AC(CAR);
    D_80103E00_40B930_MinigameCoaster[4] = func_80043510_44110(0xB1, NULL);
    func_800298A4_2A4A4(D_80103E00_40B930_MinigameCoaster[4]->obj->model[0], 0x80000, 0x80000);
    func_80029A8C_2A68C(D_80103E00_40B930_MinigameCoaster[4]->obj->model[0]);
    func_80043DAC_449AC(D_80103E00_40B930_MinigameCoaster[4]);
    func_800B3170_B3D70(&D_80103E00_40B930_MinigameCoaster[1]->pos, &D_80103E2C_40B95C_MinigameCoaster);
    func_800B3170_B3D70(&D_80103E00_40B930_MinigameCoaster[2]->pos, &D_80103E38_40B968_MinigameCoaster);
    func_800B3170_B3D70(&CAR->pos, &D_80103E14_40B944_MinigameCoaster);
    HuVecCopyXYZ(&CAR->scale, 1.3f, 1.3f, 1.3f);
    HuVecCopyXYZ(&CAR->rot, -1.0f, 0.0f, 0.0f);
    func_80029E80_2AA80(D_80103E00_40B930_MinigameCoaster[1]->obj->model[0], 2, 1);
    func_80029E80_2AA80(D_80103E00_40B930_MinigameCoaster[2]->obj->model[0], 2, 1);
    func_80029FE4_2ABE4(CAR->obj->model[0], 4.0f);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeIn(2, 0x10);
    HuPrcSleep(0x10);
    PlaySound(0x326);
    for (i = 0; i < 90; i += 10) {
        light->scale.z = 1.0f;
        light->scale.x = 1.0f;
        light->scale.y = __sinf(i * 0.017453292519943295);
        HuPrcVSleep();
    }
    HOST = func_80043510_44110(0xA7, D_80103F64_40BA94_MinigameCoaster);
    func_800B3170_B3D70(&HOST->pos, &D_80103E44_40B974_MinigameCoaster);
    func_80056658_57258(&HOST->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &HOST->rot);
    MBMotionSet(HOST, 1, 2);
    PlaySound(0x328);
    MBModelDispOn(HOST);
    step = HuVecDistance(&HOST->pos, &D_80103F74_40BAA4_MinigameCoaster) / 6.0f;
    func_80056658_57258(&HOST->pos, &D_80103F74_40BAA4_MinigameCoaster, &dir);
    for (i = 0; i < 6; i++) {
        HOST->pos.x += step * dir.x;
        HOST->jumpY += step * dir.y;
        HOST->pos.z += step * dir.z;
        HuPrcVSleep();
    }
    for (i = 0; i < 2; i++) {
        PlaySound(0x328);
        MBMotionSet(PLAYER_MODEL(i), 0, 0);
        MBModelDispOn(PLAYER_MODEL(i));
        step = HuVecDistance(&PLAYER_MODEL(i)->pos, dest = &D_80103F80_40BAB0_MinigameCoaster[i]) / 6.0f;
        func_80056658_57258(&PLAYER_MODEL(i)->pos, dest, &dir);
        for (j = 0; j < 6; j++) {
            PLAYER_MODEL(i)->pos.x += step * dir.x;
            PLAYER_MODEL(i)->jumpY += step * dir.y;
            PLAYER_MODEL(i)->pos.z += step * dir.z;
            HuPrcVSleep();
        }
    }
    PlaySound(0x327);
    PlaySound(0x457);
    func_8005845C_5905C(0, &D_80103E20_40B950_MinigameCoaster, 0x18, CAR);
    omAddPrcObj(&func_801028B8_40A3E8_MinigameCoaster, 0x300, 0, 0);
    for (i = 90; i >= 0; i -= 10) {
        light->scale.y = __sinf(i * 0.017453292519943295);
        HuPrcVSleep();
    }
    MBModelKill(light);
    fall[0] = 0.59f;
    fall[1] = 1.21f;
    fall[2] = 0.77f;
    fall[3] = 1.0f;
    for (i = 0; i < 2; i++) {
        func_800B3170_B3D70(&PLAYER_MODEL(i)->pos, &D_80103E5C_40B98C_MinigameCoaster[i]);
    }
    while (1) {
        n = 0;
        for (i = 0; i < 2; i++) {
            PLAYER_MODEL(i)->jumpY -= fall[i];
            if (PLAYER_MODEL(i)->jumpY <= 0.0f) {
                PLAYER_MODEL(i)->jumpY = 0.0f;
                if (fall[i] != 0.0f) {
                    MBMotionShiftSet(PLAYER_MODEL(i), 2, 0, 5, 2);
                }
                fall[i] = 0.0f;
                n++;
            }
            fall[i] *= 1.1f;
        }
        if (n == 2) {
            break;
        }
        HuPrcVSleep();
    }
    PlayMusic(0xE);
    fall[0] = 50.0f;
    func_800B3170_B3D70(&HOST->pos, &D_80103E50_40B980_MinigameCoaster);
    HOST->jumpY = 700.0f;
    goto test;
    while (1) {
        if (HOST->jumpY < 200.0f) {
            func_800B3170_B3D70(&pos, &HOST->pos);
            pos.z += 200.0f;
            func_80058F18_59B18(0, &pos, 0xA, PLAYER_MODEL(0));
            func_80058F18_59B18(0, &pos, 0xA, PLAYER_MODEL(1));
            MBMotionSet(PLAYER_MODEL(0), 3, 2);
            MBMotionSet(PLAYER_MODEL(1), 3, 2);
            func_800B3170_B3D70(&PLAYER_MODEL(0)->pos, &D_80103E74_40B9A4_MinigameCoaster[0]);
            func_800B3170_B3D70(&PLAYER_MODEL(1)->pos, &D_80103E74_40B9A4_MinigameCoaster[1]);
        }
        HuPrcVSleep();
    test:
        HOST->jumpY -= fall[0];
        if (HOST->jumpY <= 0.0f) {
            HOST->jumpY = 0.0f;
            break;
        }
    }
    func_800B3170_B3D70(&pos2, &PLAYER_MODEL(0)->pos);
    pos2.z += 200.0f;
    func_80058F18_59B18(0, &pos2, 0xA, HOST);
    HuPrcSleep(5);
    MBMotionShiftSet(PLAYER_MODEL(0), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(1), 2, 0, 5, 2);
    HuPrcSleep(5);
    MBMotionShiftSet(HOST, 0, 0, 5, 2);
}

/* One message box, centred plus x, wait for it, close it (6D's func_80102914). */
void func_801032AC_40ADDC_MinigameCoaster(s32 mess, s32 x, s32 y) {
    s16 size[2];
    s16 win;

    func_8008DACC_8E6CC(1, size, mess);
    win = func_8005AAC0_5B6C0(((0x140 - size[0]) / 2) + x, y, size[0], size[1]);
    func_800890CC_89CCC(win, (void*)mess, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    func_80057730_58330(win, 0);
    func_8005762C_5822C(win);
}

/* NON_MATCHING: control flow (masked 5). The default-course test: retail keeps
   `beqz; j` and a branch over `li 1` where GCC threads the first and turns the second into sltu.
   Tried if/else, goto, an inline helper, s16 widths. Everything else matches; `sel`/`choice` as
   written give register residue (retail copies v0 twice). */
#ifdef NON_MATCHING
#define CONFIRM(mess)                                                                 \
    func_8008DACC_8E6CC(1, size, mess);                                               \
    win = func_8005AAC0_5B6C0((0x140 - size[0]) / 2, 0x96, size[0], size[1]);         \
    func_800890CC_89CCC(win, (void*)(mess), -1, -1);                                  \
    func_80089A48_8A648(win, 0);                                                      \
    ShowTextWindow(win);                                                              \
    func_8005774C_5834C(win, 0);                                                      \
    D_800F920C_F9E0C[win].unk20 = 1;                                                  \
    HuPrcVSleep();                                                                    \
    func_80102884_40A3B4_MinigameCoaster(win);                                        \
    choice = func_8008BB48_8C748(win, 0, 1);                                          \
    func_8005762C_5822C(win)

/* Main process: rules (skippable), course menu with confirm, then the car leaves. */
void func_80103360_40AE90_MinigameCoaster(void) {
    s16 size[2];
    s32 spr[3];
    Vec vec;
    Process* prc;
    s16 win;
    s32 choice;
    s32 sel;

    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_801028FC_40A42C_MinigameCoaster();
    CONFIRM(0x5E4);
    if (choice == 0) {
        func_801032AC_40ADDC_MinigameCoaster(0x5E5, 0x14, 0x96);
        spr[0] = func_8005973C_5A33C(0xA00A3, 0x20, 0x3C, 0x64);
        spr[2] = func_8005973C_5A33C(0xA00A4, 0x20, 0x3C, 0x64);
        func_800598A4_5A4A4(spr[2], 0xFF);
        func_80059914_5A514(spr[2], 0x1000);
        func_800599AC_5A5AC(spr[2], 0xFF, 0xD3, 0x4F);
        spr[1] = func_8005973C_5A33C(0xA00A0, 0x10, 0x3C, 0x5F);
        func_801032AC_40ADDC_MinigameCoaster(0x5E6, 0x1E, 0x96);
        func_80059698_5A298(spr[0]);
        func_80059698_5A298(spr[1]);
        func_80059698_5A298(spr[2]);
        func_801032AC_40ADDC_MinigameCoaster(0x5E7, 0x14, 0x96);
        func_80061DC4_629C4();
        func_801032AC_40ADDC_MinigameCoaster(0x5E8, 0xA, 0x96);
        func_800622E4_62EE4();
        func_80062008_62C08();
        func_801032AC_40ADDC_MinigameCoaster(0x5E9, 0x14, 0x96);
        func_80062340_62F40();
        spr[0] = func_8005973C_5A33C(0xA00A3, 0x20, 0x3C, 0x64);
        spr[2] = func_8005973C_5A33C(0xA00A4, 0x20, 0x3C, 0x64);
        func_800598A4_5A4A4(spr[2], 0xFF);
        func_80059914_5A514(spr[2], 0x1000);
        func_800599AC_5A5AC(spr[2], 0xFF, 0xD3, 0x4F);
        spr[1] = func_8005973C_5A33C(0xA00A2, 0x10, 0x3C, 0x5F);
        func_801032AC_40ADDC_MinigameCoaster(0x5EA, 0x1E, 0x96);
        func_80059698_5A298(spr[0]);
        func_80059698_5A298(spr[1]);
        func_80059698_5A298(spr[2]);
        func_801032AC_40ADDC_MinigameCoaster(0x5EB, 0, 0x96);
    }
    func_801032AC_40ADDC_MinigameCoaster(0x5EC, 0x14, 0x96);
    if (_CheckFlag(0x10) != 0) {
        sel = 2;
    } else {
        sel = 0;
        if (_CheckFlag(0xF) != 0) {
            sel = 1;
        }
    }
retry:
    func_8008DACC_8E6CC(1, size, 0x5ED);
    win = func_8005AAC0_5B6C0(((0x140 - size[0]) / 2) + 0x14, 0x8C, size[0], size[1]);
    func_800890CC_89CCC(win, (void*)0x5ED, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    func_80102884_40A3B4_MinigameCoaster(win);
    sel = choice = func_8008BB48_8C748(win, sel, 1);
    D_800FD8A8_FE4A8.unk04 = choice;
    func_8005762C_5822C(win);
    switch (choice) {
    case 0:
        CONFIRM(0x5EE);
        if (choice != 0) {
            goto retry;
        }
        break;
    case 1:
        CONFIRM(0x5EF);
        if (choice != 0) {
            goto retry;
        }
        break;
    case 2:
        if (_CheckFlag(0x10) == 0) {
            func_801032AC_40ADDC_MinigameCoaster(0x5F0, 0, 0x96);
            goto retry;
        }
        CONFIRM(0x5F1);
        if (choice != 0) {
            goto retry;
        }
        break;
    }
    switch (D_800FD8A8_FE4A8.unk04) {
    case 0:
        func_801032AC_40ADDC_MinigameCoaster(0x5F2, 0, 0x96);
        break;
    case 1:
        func_801032AC_40ADDC_MinigameCoaster(0x5F3, 0, 0x96);
        break;
    case 2:
        func_801032AC_40ADDC_MinigameCoaster(0x5F4, 0, 0x96);
        break;
    }
    func_800794A8_7A0A8(0x3C);
    func_8005670C_5730C(&vec);
    prc = func_80056B78_57778(&HOST->rot, &vec, &HOST->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
    MBMotionSet(HOST, 2, 0);
    func_80029E80_2AA80(D_80103E00_40B930_MinigameCoaster[1]->obj->model[0], 1, 0);
    HuPrcSleep(0xF);
    PlaySound(0x454);
    HuPrcSleep(0xF);
    CAR->jumpY += 1000.0f;
    CAR->pos.y -= 1000.0f;
    PLAYER_MODEL(0)->jumpY += 1000.0f;
    PLAYER_MODEL(0)->pos.y -= 1000.0f;
    PLAYER_MODEL(1)->jumpY += 1000.0f;
    PLAYER_MODEL(1)->pos.y -= 1000.0f;
    func_80029E80_2AA80(D_80103E00_40B930_MinigameCoaster[2]->obj->model[0], 1, 0);
    func_80029FE4_2ABE4(D_80103E00_40B930_MinigameCoaster[2]->obj->model[0], 2.0f);
    PlaySound(0x453);
    HuPrcSleep(0x14);
    CAR->jumpVel = -1.0f;
    CAR->jumpAccel = -5.0f;
    PlaySound(0x452);
    MBPlayerVibrate(-1, 2);
    HuPrcSleep(4);
    PLAYER_MODEL(0)->pos.y += 60.0f;
    PLAYER_MODEL(1)->pos.y += 60.0f;
    MBMotionSet(PLAYER_MODEL(0), 6, 2);
    MBMotionSet(PLAYER_MODEL(1), 6, 2);
    func_800797DC_7A3DC(0x111, 0);
    func_800797DC_7A3DC(0x111, 1);
    HuPrcSleep(3);
    PLAYER_MODEL(0)->jumpVel = -0.0f;
    PLAYER_MODEL(0)->jumpAccel = -5.0f;
    PLAYER_MODEL(1)->jumpVel = -0.0f;
    PLAYER_MODEL(1)->jumpAccel = -5.0f;
    HuPrcSleep(0x1E);
    D_801011FC_101DFC = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6E_MinigameCoaster/40A330", func_80103360_40AE90_MinigameCoaster);
#endif

void func_80103BCC_40B6FC_MinigameCoaster(void) {
    if (func_8008F618_90218() == 0) {
        func_80103DD4_40B904_MinigameCoaster();
        func_80103C98_40B7C8_MinigameCoaster();
        func_8008CE5C_8DA5C();
        func_8005E584_5F184();
        omOvlReturnEx(1);
    }
}

void func_80103C18_40B748_MinigameCoaster(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        InitFadeOut(2, 0x10);
        obj->func_ptr = &func_80103BCC_40B6FC_MinigameCoaster;
    }
}

void func_80103C5C_40B78C_MinigameCoaster(void) {
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_8005965C_5A25C();
    func_800581A0_58DA0();
}

void func_80103C98_40B7C8_MinigameCoaster(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }

    for (i = 0; i < 5; i++) {
        if (D_80103E00_40B930_MinigameCoaster[i] == 0) {
            continue;
        }
        MBModelKill(D_80103E00_40B930_MinigameCoaster[i]);
        D_80103E00_40B930_MinigameCoaster[i] = 0;
    }

    func_80059400_5A000();
    func_80059704_5A304();
    func_800581D0_58DD0();
}

void func_80103D34_40B864_MinigameCoaster(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0, 0, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(0x2E);
}

void func_80103DD4_40B904_MinigameCoaster(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}
