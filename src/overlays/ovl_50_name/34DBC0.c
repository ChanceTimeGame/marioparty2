#include "common.h"
#include "ovl_50.h"

void func_8010D360_34DBC0_name_50(void) {
    D_8010105C_101C5C = D_80101300_101F00 = 0.9f;
    func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    func_80020D20_21920(0x1A);
    func_8010D614_34DE74_name_50();
    func_8010E164_34E9C4_name_50();
    func_8010E478_34ECD8_name_50();
    func_8010F1A8_34FA08_name_50();
    func_8010F79C_34FFFC_name_50();
    func_801100EC_35094C_name_50();
    func_8011039C_350BFC_name_50();
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
}

/* Board 5's setup: a background model (D_80112618), only the winner's player model, and the
   host's (D_8011274C). */
void func_8010D3F4_34DC54_name_50(void) {
    s32 i;

    D_80112618_352E78_name_50 = MBModelFileCreate(0x8007B, 13, 1.0f, 3.0f, D_8011236C_352BCC_name_50);
    func_800298A4_2A4A4(*D_80112618_352E78_name_50->obj->model, 0x2060, 0x22040);
    func_80029A8C_2A68C(*D_80112618_352E78_name_50->obj->model);
    MBModelDispOff(D_80112618_352E78_name_50);
    for (i = 0; i < 4; i++) {
        if (i == D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80112308_352B68_name_50[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
            func_80043DAC_449AC(OVL50_PLAYER_MODEL(i));
            gPlayers[i].flags |= 2;
            MBMotionSet(OVL50_PLAYER_MODEL(i), 0, 2);
            if (D_8011275A_352FBA_name_50 == i) {
                func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(i)->obj->model, 1);
            }
            MBModelDispOff(OVL50_PLAYER_MODEL(i));
        }
    }
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80000, 13, 0.8f, 0.8f, D_80112320_352B80_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80112398_352BF8_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
}

/* Board 5's scene, part 1: the host and the winner's partner come in, the host turns away and
   back, the doors (0xA018E/0xA018F) slide shut. Messages 0x341-0x347. */
#ifdef NON_MATCHING
/* One instruction short: retail sets t = 0 early and increments it later (s1, never folded to
   t = 1); everything else matches. */
void func_8010D614_34DE74_name_50(void) {
    s32 flags[2];
    s32 win;
    MBModel* door1;
    MBModel* door2;
    s16 win2;
    s32 m;
    s32 t;
    s32 mode;
    s32 n;

    func_80050E00_51A00(40);
    func_8005321C_53E1C(80.0f, 8000.0f);
    t = 0;
    func_80026D50_27950(1, 1, 1);
    func_80026E00_27A00(1, -30.0f, 0.0f, -116.0f);
    mode = 1;
    MBModelKill(D_8011274C_352FAC_name_50);
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80000, 13, 0.8f, 0.8f, D_80112320_352B80_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80112398_352BF8_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
    t++;
    func_8002D274_2DE74(*D_8011274C_352FAC_name_50->obj->model, 0x6E, 0x28, 0x28);
    func_8002D2B4_2DEB4(*D_8011274C_352FAC_name_50->obj->model, 22.0f, -110.0f, 42.0f);
    D_80112748_352FA8_name_50 = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_80112334_352B94_name_50);
    func_8005AB50_5B750(D_80112748_352FA8_name_50, 2, 7, D_801123A0_352C00_name_50);
    func_8002D1EC_2DDEC(*D_80112748_352FA8_name_50->obj->model, 1);
    D_80112748_352FA8_name_50->pos.x = D_801123B8_352C18_name_50[0].x;
    D_80112748_352FA8_name_50->pos.y = D_801123B8_352C18_name_50[0].y;
    D_80112748_352FA8_name_50->pos.z = D_801123B8_352C18_name_50[0].z;
    /* Retail: the direction from the target back to the start (the host starts facing away). */
    func_80056658_57258(&D_801123B8_352C18_name_50[1], &D_801123B8_352C18_name_50[0], &D_80112748_352FA8_name_50->rot);
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0x6E, 0x28, 0x28);
    func_8002D2B4_2DEB4(*D_80112748_352FA8_name_50->obj->model, 22.0f, -110.0f, 42.0f);
    D_8011275C_352FBC_name_50 = MBModelFileCreate(0x80049, 13, 1.0f, 3.0f, D_8011236C_352BCC_name_50);
    func_8005AB50_5B750(D_8011275C_352FBC_name_50, 2, 9, D_801123A4_352C04_name_50[0]);
    MBMotionSet(D_8011275C_352FBC_name_50, 0, 2);
    func_80043DAC_449AC(D_8011275C_352FBC_name_50);
    func_8002D1EC_2DDEC(*D_8011275C_352FBC_name_50->obj->model, 1);
    D_8011275C_352FBC_name_50->pos.x = D_801123DC_352C3C_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_801123DC_352C3C_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_801123DC_352C3C_name_50.z;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &D_80112748_352FA8_name_50->pos, &D_8011275C_352FBC_name_50->rot);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0x6E, 0x28, 0x28);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, 22.0f, -110.0f, 42.0f);
    door1 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door1);
    door1->pos.x = D_80112400_352C60_name_50.x;
    door1->pos.y = D_80112400_352C60_name_50.y;
    door1->pos.z = D_80112400_352C60_name_50.z;
    door1->attr |= 4;
    door2 = MBModelFileCreate(0xA018F, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door2);
    door2->pos.x = D_80112400_352C60_name_50.x;
    door2->pos.y = D_80112400_352C60_name_50.y;
    door2->pos.z = D_80112400_352C60_name_50.z;
    door2->attr |= 4;
    PlaySound(0x414);
    InitFadeIn(3, 16);
    HuPrcSleep(16);
    MBMotionSet(D_80112748_352FA8_name_50, 5, 2);
    func_80029C74_2A874(*D_80112748_352FA8_name_50->obj->model, 0.0f);
    n = 0;
    while (1) {
        if ((t < 30 || mode == 0) && func_8005A608_5B208(D_80112748_352FA8_name_50, &D_801123B8_352C18_name_50[1], 6.0f) == 1) {
            break;
        }
        if (t >= 65) {
            mode ^= 1;
            t = 0;
            if (mode != 0) {
                MBMotionSet(D_80112748_352FA8_name_50, 5, 2);
            } else {
                MBMotionSet(D_80112748_352FA8_name_50, 11, 2);
            }
        }
        n++;
        if (n == 10) {
            PlaySound(0xE7);
            func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x341);
            win = func_8005AAC0_5B6C0(100, 45, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
            func_800890CC_89CCC(win, 0x341, -1, -1);
        }
        if (n >= 70) {
            func_8005A5E8_5B1E8(D_8011275C_352FBC_name_50, &D_801123E8_352C48_name_50[0], 20.0f);
        }
        t++;
        HuPrcVSleep();
    }
    func_8008CCA8_8D8A8(win);
    while (func_8005A5E8_5B1E8(D_8011275C_352FBC_name_50, &D_801123E8_352C48_name_50[0], 20.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 4, 2);
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &D_80112748_352FA8_name_50->pos, &D_8011275C_352FBC_name_50->rot);
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_801123AC_352C0C_name_50);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 9, 0, 4, 0);
    HuPrcSleep(44);
    PlayMusic(0x3C);
    PlaySound(0x125);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x342);
    win2 = func_8005AAC0_5B6C0(70, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x342, -1, -1);
    MBMotionSet(D_80112748_352FA8_name_50, 8, 0);
    HuPrcSleep(23);
    D_80112748_352FA8_name_50->rot.x = -D_80112748_352FA8_name_50->rot.x;
    D_80112748_352FA8_name_50->rot.y = -D_80112748_352FA8_name_50->rot.y;
    D_80112748_352FA8_name_50->rot.z = -D_80112748_352FA8_name_50->rot.z;
    MBMotionSet(D_80112748_352FA8_name_50, 4, 2);
    func_8008CCA8_8D8A8(win2);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x343);
    win = func_8005AAC0_5B6C0(160, 90, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x343, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(10);
    PlaySound(0xE7);
    HuPrcSleep(20);
    func_8008CCA8_8D8A8(win);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x344);
    win2 = func_8005AAC0_5B6C0(50, 40, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x344, -1, -1);
    PlaySound(0x125);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 4, 0, 4, 2);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 0, 0, 4, 2);
    n = 0;
    while (func_8005A608_5B208(D_80112748_352FA8_name_50, &D_801123D0_352C30_name_50, 3.0f) == 0) {
        func_8005A5E8_5B1E8(D_8011275C_352FBC_name_50, &D_80112748_352FA8_name_50->pos, 3.0f);
        n++;
        if (n == 8) {
            func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x345);
            win = func_8005AAC0_5B6C0(160, 90, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
            func_800890CC_89CCC(win, 0x345, -1, -1);
            PlaySound(0xE7);
            m = 0;
        }
        if (n >= 12) {
            func_8005A5E8_5B1E8(door1, &D_8011240C_352C6C_name_50, 10.0f);
            func_8005A5E8_5B1E8(door2, &D_8011240C_352C6C_name_50, 10.0f);
        }
        m += n >= 9;
        if (m == 10) {
            PlaySound(0xE7);
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80112748_352FA8_name_50, 0, 0, 4, 2);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 4, 2);
    while (func_8005A5E8_5B1E8(door1, &D_8011240C_352C6C_name_50, 10.0f) == 0) {
        func_8005A5E8_5B1E8(door2, &D_8011240C_352C6C_name_50, 10.0f);
        HuPrcVSleep();
    }
    func_8008CCA8_8D8A8(win);
    t = 35;
    flags[1] = 0;
    flags[0] = 0;
    mode = 0;
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_801123A4_352C04_name_50[0]);
    n = 0;
    while (1) {
        if (func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &door1->pos, 6.0f) != 0) {
            n = 1;
            if (flags[0] == 0) {
                flags[0] = 1;
                PlaySound(0x125);
                func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x346);
                win = func_8005AAC0_5B6C0(0x38, 0x32, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
                func_800890CC_89CCC(win, 0x346, -1, -1);
            }
        }
        if (t <= 20) {
            if (mode == 0) {
                mode = 1;
                MBMotionShiftSet(D_80112748_352FA8_name_50, 10, 0, 2, 0);
                func_80029FE4_2ABE4(*D_80112748_352FA8_name_50->obj->model, 2.0f);
            }
            if (t <= 0) {
                n += func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &door1->pos, 20.0f) != 0;
            }
            t--;
            n += t == -4;
        } else {
            t--;
        }
        if (n == 2) {
            break;
        }
        n = 0;
        HuPrcVSleep();
    }
    HuPrcSleep(18);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x347);
    win2 = func_8005AAC0_5B6C0(0x7E, 0x5A, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x347, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(80);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win2);
    MBDBackKill();
    MBModelDispOff(D_8011275C_352FBC_name_50);
    MBModelDispOff(D_80112748_352FA8_name_50);
    MBModelKill(door1);
    MBModelKill(door2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010D614_34DE74_name_50);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010E164_34E9C4_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010E478_34ECD8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010F1A8_34FA08_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010F79C_34FFFC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_801100EC_35094C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8011039C_350BFC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8011099C_3511FC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110B1C_35137C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110E5C_3516BC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110E9C_3516FC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110EFC_35175C_name_50);

void func_80110F10_351770_name_50(void) {
    D_80112638_352E98_name_50->work[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110F20_351780_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_801112EC_351B4C_name_50);

void func_80111690_351EF0_name_50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80112640_352EA0_name_50[i][0] = NULL;
        D_801126C0_352F20_name_50[i][0] = NULL;
    }
}

omObjData* func_801116C8_351F28_name_50(void (*init)(omObjData*), void (*func)(omObjData*), s32 nvtx, s32 ngfx) {
    omObjData* obj;
    s16 slot;
    s32 i;

    obj = omAddObj(0x1F4, 1, 0, -1, func);
    for (slot = 0; slot < 4; slot++) {
        if (D_801126C0_352F20_name_50[slot][0] == NULL) {
            break;
        }
    }
    if (slot == 4) {
        return NULL;
    }
    obj->work[0] = 0;
    obj->work[1] = slot;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        D_80112640_352EA0_name_50[slot][i] = func_80027154_27D54(nvtx * sizeof(Vtx), 0x7918);
        D_801126C0_352F20_name_50[slot][i] = func_80027154_27D54(ngfx * sizeof(Gfx), 0x7918);
    }
    if (init != NULL) {
        init(obj);
    }
    obj->model[0] = func_80027FA4_28BA4(0x684, D_801126C0_352F20_name_50[slot][D_800FDBE0_FE7E0], 4);
    return obj;
}

void func_80111868_3520C8_name_50(omObjData* obj) {
    u8 slot = obj->work[1];
    s16 i;

    func_800283DC_28FDC(obj->model[0]);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        if (D_80112640_352EA0_name_50[slot][i] != NULL) {
            HuMemFree(D_80112640_352EA0_name_50[slot][i]);
            D_80112640_352EA0_name_50[slot][i] = NULL;
        }
        if (D_801126C0_352F20_name_50[slot][i] != NULL) {
            HuMemFree(D_801126C0_352F20_name_50[slot][i]);
            D_801126C0_352F20_name_50[slot][i] = NULL;
        }
    }
    omDelObj(obj);
}
