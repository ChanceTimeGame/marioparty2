#include "common.h"
#include "ovl_50.h"

void func_80104280_344AE0_name_50(void) {
    D_8010105C_101C5C = D_80101300_101F00 = 0.85f;
    func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    func_80020D20_21920(0x10);
    func_801044DC_344D3C_name_50();
    func_80105900_346160_name_50();
    func_80105E58_3466B8_name_50();
    func_80106A90_3472F0_name_50();
    func_80106CF8_347558_name_50();
    func_80106FDC_34783C_name_50();
    func_801077E0_348040_name_50();
    func_80107A3C_34829C_name_50();
    func_8010804C_3488AC_name_50();
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
}

/* Board 2's setup: only the winner's player model, and the host's (D_8011274C). */
void func_80104324_344B84_name_50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80111C88_3524E8_name_50[gPlayers[i].character], 2);
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
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80028, 13, 0.8f, 0.8f, D_80111CA0_352500_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80111D00_352560_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
}

__asm__(".section .rodata");
const char D_801124F0_352D50_name_50[16] = "item_hook";

__asm__(".section .rodata");
const char D_80112500_352D60_name_50[] = "c005_000-bmerge4";

__asm__(".section .rodata");
const char D_80112514_352D74_name_50[] = "Luigi1-migi-te1_2";

__asm__(".section .rodata");
const char D_80112528_352D88_name_50[] = "c003_000-bmerge1_13_1";

__asm__(".section .rodata");
const char D_80112540_352DA0_name_50[] = "C002_000b-bmerge14";

__asm__(".section .rodata");
const char D_80112554_352DB4_name_50[] = "c001_000-migi-te2_2";

__asm__(".section .rodata");
const char D_80112568_352DC8_name_50[16] = "migi-te2_4";

/* Board 2's scene, part 1: the host (D_80112748) walks in and turns, a ghost (0x800C1) fades in
   and floats to the centre, music 0x3C; the partner (D_8011275C) arrives, the host's spell
   (func_80108290/80108448/80108630/80108830) changes it into a new model (0xA022D) which hops
   away with the host as the doors (0xA018E) slide. Messages 0x2E6-0x2EE. */
void func_801044DC_344D3C_name_50(void) {
    s32 flags[2];
    Vec dir;
    MBModel* door1;
    MBModel* door2;
    MBModel* ghost;
    s16 alpha;
    MBModel* morph1;
    MBModel* morph2;
    s16 win2;
    s32 i;
    s32 wait;
    s32 jumping;
    s32 n;
    f32 vel;

    func_80050E00_51A00(0x13);
    alpha = 0;
    func_8005321C_53E1C(80.0f, 8000.0f);
    MBModelKill(D_8011274C_352FAC_name_50);
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80028, 13, 0.8f, 0.8f, D_80111CA0_352500_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80111D00_352560_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
    door1 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door1);
    door1->pos.x = D_80111D74_3525D4_name_50[0].x;
    door1->pos.y = D_80111D74_3525D4_name_50[0].y;
    door1->pos.z = D_80111D74_3525D4_name_50[0].z;
    door1->attr |= 4;
    door2 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door2);
    door2->pos.x = D_80111D74_3525D4_name_50[0].x;
    door2->pos.y = D_80111D74_3525D4_name_50[0].y;
    door2->pos.z = D_80111D74_3525D4_name_50[0].z;
    door2->attr |= 4;
    D_80112748_352FA8_name_50 = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_80111CAC_35250C_name_50);
    HmfModelObjAttrSet(*D_80112748_352FA8_name_50->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*D_80112748_352FA8_name_50->obj->model);
    func_8002A00C_2AC0C(*D_80112748_352FA8_name_50->obj->model);
    func_8005AB50_5B750(D_80112748_352FA8_name_50, 2, 7, D_80111D08_352568_name_50);
    func_8002D1EC_2DDEC(*D_80112748_352FA8_name_50->obj->model, 1);
    D_80112748_352FA8_name_50->pos.x = D_80111D2C_35258C_name_50[0].x;
    D_80112748_352FA8_name_50->pos.y = D_80111D2C_35258C_name_50[0].y;
    D_80112748_352FA8_name_50->pos.z = D_80111D2C_35258C_name_50[0].z;
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &D_80111D2C_35258C_name_50[1], &D_80112748_352FA8_name_50->rot);
    MBMotionSet(D_80112748_352FA8_name_50, 11, 2);
    ghost = MBModelFileCreate(0x800C1, 13, 1.0f, 1.2f, D_80111D8C_3525EC_name_50);
    MBMotionSet(ghost, 0, 2);
    ghost->pos.x = D_80111D44_3525A4_name_50[0].x;
    ghost->pos.y = 0.0f;
    ghost->pos.z = D_80111D44_3525A4_name_50[0].z;
    ghost->jumpY = 275.0f;
    func_8002D124_2DD24(*ghost->obj->model);
    func_8002D124_2DD24(*ghost->shadow->model);
    func_8002D0A0_2DCA0(*ghost->obj->model, 0);
    func_8002D0A0_2DCA0(*ghost->shadow->model, 0);
    func_80056658_57258(&ghost->pos, &D_80111D44_3525A4_name_50[1], &ghost->rot);
    morph1 = MBModelFileCreate(0xA022D, 13, 1.0f, 1.3f, NULL);
    morph2 = MBModelFileCreate(0xA022D, 13, 1.0f, 1.3f, D_80111D20_352580_name_50);
    HmfModelObjAttrSet(*morph1->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*morph1->obj->model);
    func_8002A00C_2AC0C(*morph1->obj->model);
    func_80029E80_2AA80(*morph2->obj->model, 1, 1);
    MBModelDispOff(morph1);
    MBModelDispOff(morph2);
    D_8011275C_352FBC_name_50 = MBModelFileCreate(0x8005A, 13, 1.0f, 3.0f, D_80111CE4_352544_name_50);
    HmfModelObjAttrSet(*D_8011275C_352FBC_name_50->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*D_8011275C_352FBC_name_50->obj->model);
    func_8002A00C_2AC0C(*D_8011275C_352FBC_name_50->obj->model);
    func_8005AB50_5B750(D_8011275C_352FBC_name_50, 2, 9, D_80111D14_352574_name_50);
    MBMotionSet(D_8011275C_352FBC_name_50, 0, 2);
    func_80043DAC_449AC(D_8011275C_352FBC_name_50);
    func_8002D1EC_2DDEC(*D_8011275C_352FBC_name_50->obj->model, 1);
    D_8011275C_352FBC_name_50->pos.x = D_80111D5C_3525BC_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_80111D5C_3525BC_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_80111D5C_3525BC_name_50.z;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &D_80112748_352FA8_name_50->pos, &D_8011275C_352FBC_name_50->rot);
    MBModelDispOff(D_8011275C_352FBC_name_50);
    D_80112750_352FB0_name_50 = LoadFormFile(0xA0231, 0x489);
    func_8005AA48_5B648(D_8011275C_352FBC_name_50, D_801124F0_352D50_name_50, D_80112750_352FB0_name_50);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 4);
    func_80026D50_27950(1, 1, 1);
    func_80026E00_27A00(1, -37.0f, 8.0f, -113.0f);
    func_80026D50_27950(3, 1, 1);
    func_80026E00_27A00(3, -5.0f, 109.0f, 48.0f);
    func_80026DAC_279AC(3, 0x3C, 0x9C, 0xFF);
    PlaySound(0x3E9);
    InitFadeIn(3, 16);
    HuPrcSleep(16);
    while (func_8005A5E8_5B1E8(D_80112748_352FA8_name_50, &D_80111D38_352598_name_50, 6.0f) == 0) {
        HuPrcVSleep();
    }
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &D_80111D50_3525B0_name_50, &dir);
    dir.x = -dir.x;
    dir.z = -dir.z;
    MBMotionShiftSet(D_80112748_352FA8_name_50, -1, 0, 8, 2);
    dir.x = dir.x * 500.0f + D_80111D50_3525B0_name_50.x;
    dir.z = dir.z * 500.0f + D_80111D50_3525B0_name_50.z;
    while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &dir, 5.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80112748_352FA8_name_50, 4, 0, 8, 2);
    HuPrcSleep(15);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2E6);
    win2 = func_8005AAC0_5B6C0((320 - D_80112752_352FB2_name_50[0]) / 2, 60, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2E6, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    while (func_8005A5E8_5B1E8(ghost, &D_80111D50_3525B0_name_50, 15.0f) == 0) {
        ghost->jumpY -= 2.4166667f;
        alpha += 11;
        if (alpha >= 256) {
            alpha = 255;
        }
        func_8002D0A0_2DCA0(*ghost->obj->model, alpha);
        func_8002D0A0_2DCA0(*ghost->shadow->model, alpha);
        HuPrcVSleep();
    }
    PlaySound(0xEB);
    HuPrcSleep(15);
    MBMotionShiftSet(D_80112748_352FA8_name_50, -1, 0, 4, 2);
    while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &ghost->pos, 20.0f) == 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(10);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2E7);
    win2 = func_8005AAC0_5B6C0(50, 70, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2E7, -1, -1);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 7, 0, 2, 2);
    PlaySound(0xE7);
    HuPrcSleep(10);
    PlaySound(0xE7);
    HuPrcSleep(10);
    PlaySound(0xE7);
    HuPrcSleep(20);
    func_8008CCA8_8D8A8(win2);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 3, 0, 4, 2);
    HuPrcSleep(20);
    PlayMusic(0x3C);
    for (i = 0; i < 15; i++) {
        alpha -= 16;
        func_8002D0A0_2DCA0(*ghost->obj->model, alpha);
        func_8002D0A0_2DCA0(*ghost->shadow->model, alpha);
        HuPrcVSleep();
    }
    MBModelKill(ghost);
    MBModelDispOn(D_8011275C_352FBC_name_50);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 0);
    while (func_8005A5E8_5B1E8(D_8011275C_352FBC_name_50, &D_80111D68_3525C8_name_50, 20.0f) == 0) {
        HuPrcVSleep();
    }
    {
        s32 winA;
        s32 winB;

        func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2E8);
        winA = func_8005AAC0_5B6C0(80, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
        func_800890CC_89CCC(winA, 0x2E8, -1, -1);
        PlaySound(0x124);
        HuPrcSleep(20);
        MBMotionShiftSet(D_80112748_352FA8_name_50, -1, 0, 4, 2);
        HuPrcSleep(15);
        func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2E9);
        winB = func_8005AAC0_5B6C0(110, 80, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
        func_800890CC_89CCC(winB, 0x2E9, -1, -1);
        PlaySound(0xE7);
        HuPrcSleep(15);
        while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &D_8011275C_352FBC_name_50->pos, 15.0f) == 0) {
            HuPrcVSleep();
        }
        MBMotionSet(D_8011275C_352FBC_name_50, 1, 0);
        HuPrcSleep(20);
        func_8008CCA8_8D8A8(winA);
        func_8008CCA8_8D8A8(winB);
    }
    MBMotionShiftSet(D_80112748_352FA8_name_50, 7, 0, 2, 2);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2EA);
    win2 = func_8005AAC0_5B6C0(140, 80, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2EA, -1, -1);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 4, 2);
    PlaySound(0xE7);
    HuPrcSleep(10);
    PlaySound(0xE7);
    HuPrcSleep(10);
    func_8008CCA8_8D8A8(win2);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 3, 0, 2, 2);
    PlaySound(0xE7);
    HuPrcSleep(15);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2EB);
    win2 = func_8005AAC0_5B6C0(100, 40, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2EB, -1, -1);
    PlaySound(0x123);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 3, 0, 4, 0);
    HuPrcSleep(19);
    PlaySound(0x3DB);
    func_80108290_348AF0_name_50(D_8011275C_352FBC_name_50->pos.x + 230.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f);
    HuPrcSleep(10);
    func_8008CCA8_8D8A8(win2);
    func_80108448_348CA8_name_50(D_8011275C_352FBC_name_50->pos.x + 230.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f, -66.0f);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, 50.0f, 91.0f, -59.0f);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0xFB, 0x14, 0xFB);
    for (i = 0; i < 10; i++) {
        D_801125D8_352E38_name_50->scale.x += 0.4f;
        HuPrcVSleep();
    }
    func_80108630_348E90_name_50(D_80112748_352FA8_name_50->pos.x, D_80112748_352FA8_name_50->pos.y + 45.0f, D_80112748_352FA8_name_50->pos.z, 0);
    func_8002D2B4_2DEB4(*D_80112748_352FA8_name_50->obj->model, 42.0f, 21.0f, 110.0f);
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0xFB, 0x14, 0xFB);
    HuPrcSleep(45);
    func_80079848_7A448(D_801125D2_352E32_name_50);
    func_801087FC_34905C_name_50();
    func_801085FC_348E5C_name_50();
    func_80108414_348C74_name_50();
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0, 0, 0);
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0, 0, 0);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 4, 2);
    PlaySound(0x3DC);
    func_80108830_349090_name_50(D_80112748_352FA8_name_50->pos.x + 70.0f, D_80112748_352FA8_name_50->pos.y, D_80112748_352FA8_name_50->pos.z + 150.0f);
    HuPrcSleep(5);
    morph1->pos = D_80112748_352FA8_name_50->pos;
    morph2->pos = morph1->pos;
    morph1->rot = D_80112748_352FA8_name_50->rot;
    morph2->rot = morph1->rot;
    D_801125E8_352E48_name_50 = D_80112748_352FA8_name_50->pos;
    D_801125F4_352E54_name_50 = D_80112748_352FA8_name_50->rot;
    for (i = 0; i < 11; i++) {
        func_8002AC10_2B810(*D_80112748_352FA8_name_50->obj->model, i * 0.07f, i, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        HuPrcVSleep();
    }
    MBModelKill(D_80112748_352FA8_name_50);
    MBModelDispOn(morph1);
    for (i = 0; i < 11; i++) {
        func_8002AC10_2B810(*morph1->obj->model, 1.0f - i * 0.07f, 10.0f - i, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        HuPrcVSleep();
    }
    MBModelKill(morph1);
    MBModelDispOn(morph2);
    MBMotionSet(morph2, -1, 2);
    HuPrcSleep(15);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 2, 0, 4, 2);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2EC);
    i = func_8005AAC0_5B6C0(180, 110, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(i, 0x2EC, -1, -1);
    PlaySound(0x3D8);
    HuPrcSleep(35);
    func_8008CCA8_8D8A8(i);
    while (func_8005A5E8_5B1E8(door1, &D_80111D80_3525E0_name_50, 10.0f) == 0) {
        func_8005A5E8_5B1E8(door2, &D_80111D80_3525E0_name_50, 10.0f);
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    wait = 30;
    flags[1] = 0;
    flags[0] = 0;
    jumping = 0;
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 12, 2);
    n = 0;
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_80111D0C_35256C_name_50);
    while (1) {
        if (func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &door1->pos, 6.0f) != 0) {
            n = 1;
            if (flags[0] == 0) {
                flags[0] = 1;
                func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2ED);
                i = func_8005AAC0_5B6C0(120, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
                func_800890CC_89CCC(i, 0x2ED, -1, -1);
                PlaySound(0x125);
            }
        }
        if (wait == 0) {
            if (jumping == 0) {
                MBMotionShiftSet(morph2, 0, 0, 4, 0);
                vel = 42.0f;
                jumping = 1;
            }
            morph2->jumpY += vel;
            vel -= 6.5f;
            if (morph2->jumpY < 0.0f) {
                morph2->jumpY = 0.0f;
            }
            n += func_8005A7E8_5B3E8(morph2, &door1->pos, 10.0f) != 0;
        } else {
            wait--;
        }
        if (n == 2) {
            morph2->jumpY = 0.0f;
            break;
        }
        n = 0;
        HuPrcVSleep();
    }
    MBMotionShiftSet(morph2, -1, 0, 4, 2);
    HuPrcSleep(18);
    func_800794A8_7A0A8(0x78);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2EE);
    win2 = func_8005AAC0_5B6C0(126, 90, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2EE, -1, -1);
    PlaySound(0x3D8);
    HuPrcSleep(80);
    func_8008CCA8_8D8A8(i);
    func_8008CCA8_8D8A8(win2);
    func_801089CC_34922C_name_50();
    MBModelKill(door1);
    MBModelKill(door2);
    MBModelDispOff(D_8011275C_352FBC_name_50);
    MBModelKill(morph2);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 4);
    MBDBackKill();
}

/* Board 2's scene, part 2: the winner (holding item 0xA0230) is introduced with the camera on
   them (music 0x3B, message 0x2EF with the character's name), then a beam effect
   (func_80108A00) and the winner fades out of the scene (func_80108F2C). */
void func_80105900_346160_name_50(void) {
    Vec cam;
    Vec pos;
    Vec rot;
    MBModel* model;
    s16 win2;

    func_80050E00_51A00(0x14);
    func_8005321C_53E1C(80.0f, 8000.0f);
    MBPlayerModelCreate(D_8011275A_352FBA_name_50, D_80111C88_3524E8_name_50[gPlayers[D_8011275A_352FBA_name_50].character], 2);
    func_8005ABC0_5B7C0(&gPlayers[D_8011275A_352FBA_name_50], 2, 11);
    func_80043DAC_449AC(OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50));
    gPlayers[D_8011275A_352FBA_name_50].flags |= 2;
    func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->obj->model, 1);
    model = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    MBMotionSet(model, 5, 2);
    D_80112758_352FB8_name_50 = LoadFormFile(0xA0230, 0x489);
    func_8002D1EC_2DDEC(D_80112758_352FB8_name_50, 1);
    func_8005AA48_5B648(model, D_801124F0_352D50_name_50, D_80112758_352FB8_name_50);
    model->pos.x = D_80111D94_3525F4_name_50.x;
    model->pos.y = D_80111D94_3525F4_name_50.y;
    model->pos.z = D_80111D94_3525F4_name_50.z;
    MBModelDispOn(model);
    func_80026E00_27A00(3, 7.0f, 53.0f, 107.0f);
    cam.x = 0.0f;
    cam.y = 105.0f;
    cam.z = 0.0f;
    func_8005A950_5B550(&cam, 3.0f, 1.0f, 8);
    PlayMusic(0x3B);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2EF);
    win2 = func_8005AAC0_5B6C0(45, 40, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_80089308_89F08(win2, D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_800890CC_89CCC(win2, 0x2EF, -1, -1);
    PlaySound(0x3D8);
    HuPrcSleep(60);
    func_8008CCA8_8D8A8(win2);
    func_8005A950_5B550(&cam, 1.0f, 1.4f, 8);
    MBMotionShiftSet(model, 6, 0, 2, 0);
    HuPrcSleep(30);
    pos.x = model->pos.x + D_80111DA0_352600_name_50[gPlayers[D_8011275A_352FBA_name_50].character].x;
    pos.y = model->pos.y + D_80111DA0_352600_name_50[gPlayers[D_8011275A_352FBA_name_50].character].y;
    pos.z = model->pos.z + D_80111DA0_352600_name_50[gPlayers[D_8011275A_352FBA_name_50].character].z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 300.0f, 15, 0, 0.2f, 3.0f, 10.0f, func_80042BE0_437E0(&rot));
    D_801125D0_352E30_name_50 = PlaySound(0x3DA);
    func_8002D2B4_2DEB4(*model->obj->model, 9.0f, -8.0f, 119.0f);
    func_8002D274_2DE74(*model->obj->model, 0xF5, 0xF5, 0);
    func_8002D2B4_2DEB4(D_80112758_352FB8_name_50, 9.0f, -8.0f, 119.0f);
    func_8002D274_2DE74(D_80112758_352FB8_name_50, 0xF5, 0xF5, 0);
    HuPrcSleep(45);
    MBDBackKill();
    func_80108F2C_34978C_name_50();
    MBModelDispOff(model);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 4);
    func_8002D274_2DE74(D_80112758_352FB8_name_50, 0, 0, 0);
    func_8002D274_2DE74(*model->obj->model, 0, 0, 0);
}

/* Board 2's scene, part 3: the changed partner (0xA022D) turns back into the host (D_80112748)
   in a beam, the winner walks in to the partner (message 0x2F0), the partner's spell
   (0x2F2) sends a second beam at the winner. */
void func_80105E58_3466B8_name_50(void) {
    Vec pos;
    Vec rot;
    MBModel* winner;
    MBModel* morph;
    s32 i;
    s32 turned;
    s32 win2;

    func_80050E00_51A00(0x13);
    func_8005321C_53E1C(80.0f, 8000.0f);
    func_80026E00_27A00(3, -5.0f, 109.0f, 48.0f);
    D_80112748_352FA8_name_50 = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_80111CAC_35250C_name_50);
    func_8005AB50_5B750(D_80112748_352FA8_name_50, 2, 7, D_80111D08_352568_name_50);
    func_8002D1EC_2DDEC(*D_80112748_352FA8_name_50->obj->model, 1);
    D_80112748_352FA8_name_50->scale.x = D_80112748_352FA8_name_50->scale.y = D_80112748_352FA8_name_50->scale.z = 0.5f;
    D_80112748_352FA8_name_50->pos = D_801125E8_352E48_name_50;
    D_80112748_352FA8_name_50->rot = D_801125F4_352E54_name_50;
    MBModelDispOff(D_80112748_352FA8_name_50);
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    morph = MBModelFileCreate(0xA022D, 13, 1.0f, 1.3f, D_80111D20_352580_name_50);
    HmfModelObjAttrSet(*morph->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*morph->obj->model);
    func_8002A00C_2AC0C(*morph->obj->model);
    morph->pos.x = D_80111D38_352598_name_50.x;
    morph->pos.y = D_80111D38_352598_name_50.y;
    morph->pos.z = D_80111D38_352598_name_50.z;
    func_80056658_57258(&morph->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &morph->rot);
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &morph->pos, &D_8011275C_352FBC_name_50->rot);
    MBModelDispOn(D_8011275C_352FBC_name_50);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 0);
    pos.x = morph->pos.x + 40.0f;
    pos.y = morph->pos.y + 45.0f;
    pos.z = morph->pos.z + 80.0f;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 300.0f, 15, 0, 10.0f, 0.2f, 10.0f, func_80042BE0_437E0(&rot));
    func_80056658_57258(&morph->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_8002D2B4_2DEB4(*D_80112748_352FA8_name_50->obj->model, rot.x, rot.y, rot.z);
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0xA0, 0xA0, 0);
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, rot.x, rot.y, rot.z);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0xA0, 0xA0, 0);
    HuPrcSleep(45);
    func_80108F1C_34977C_name_50();
    while (D_801125E4_352E44_name_50->work[1] == 1) {
        HuPrcVSleep();
    }
    func_80108F2C_34978C_name_50();
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0, 0, 0);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0, 0, 0);
    PlaySound(0x3DC);
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &D_80112748_352FA8_name_50->rot);
    MBMotionSet(D_80112748_352FA8_name_50, 9, 2);
    func_80108830_349090_name_50(morph->pos.x + 70.0f, morph->pos.y, morph->pos.z + 150.0f);
    HuPrcSleep(5);
    for (i = 0; i < 11; i++) {
        func_8002AC10_2B810(*morph->obj->model, i * 0.1f, i, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        if (i >= 6) {
            MBModelDispOn(D_80112748_352FA8_name_50);
            D_80112748_352FA8_name_50->scale.x += 0.1f;
            D_80112748_352FA8_name_50->scale.y += 0.1f;
            D_80112748_352FA8_name_50->scale.z += 0.1f;
        }
        HuPrcVSleep();
    }
    MBModelKill(morph);
    HuPrcSleep(40);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2F0);
    win2 = func_8005AAC0_5B6C0(126, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2F0, -1, -1);
    PlaySound(0xE7);
    winner->pos.x = D_80111DF4_352654_name_50[0].x;
    winner->pos.y = D_80111DF4_352654_name_50[0].y;
    winner->pos.z = D_80111DF4_352654_name_50[0].z;
    MBMotionSet(winner, 1, 2);
    func_80056658_57258(&winner->pos, &D_80111DF4_352654_name_50[1], &winner->rot);
    turned = 0;
    MBMotionShiftSet(D_80112748_352FA8_name_50, 2, 0, 2, 2);
    while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &D_80111DE8_352648_name_50, 12.0f) == 0) {
        if (++turned == 10) {
            PlaySound(0xE7);
            turned = 0;
        }
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 0);
    MBModelDispOn(winner);
    while (func_8005A5E8_5B1E8(D_80112748_352FA8_name_50, &D_80111DE8_352648_name_50, 19.0f) == 0) {
        func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &winner->pos, 4.0f);
        if (func_8005A5E8_5B1E8(winner, &D_80111E00_352660_name_50, 16.0f) == 1 && func_8005A7E8_5B3E8(winner, &D_8011275C_352FBC_name_50->pos, 15.0f) == 1) {
            turned = 1;
            MBMotionShiftSet(winner, -1, 0, 4, 2);
        }
        HuPrcVSleep();
    }
    func_8008CCA8_8D8A8(win2);
    while (func_8005A5E8_5B1E8(winner, &D_80111E00_352660_name_50, 16.0f) == 0) {
        func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &winner->pos, 3.0f);
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(winner, &D_8011275C_352FBC_name_50->pos, 15.0f) == 0) {
        HuPrcVSleep();
    }
    if (turned == 0) {
        MBMotionShiftSet(winner, -1, 0, 4, 2);
    }
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 3, 0, 4, 0);
    MBMotionShiftSet(winner, 6, 0, 4, 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2F2);
    win2 = func_8005AAC0_5B6C0(160, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2F2, -1, -1);
    PlaySound(0x125);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    func_80108290_348AF0_name_50(D_8011275C_352FBC_name_50->pos.x + 245.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f);
    func_80108448_348CA8_name_50(D_8011275C_352FBC_name_50->pos.x + 245.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f, -40.0f);
    pos.x = winner->pos.x + D_80111E18_352678_name_50[gPlayers[D_8011275A_352FBA_name_50].character].x;
    pos.y = winner->pos.y + D_80111E18_352678_name_50[gPlayers[D_8011275A_352FBA_name_50].character].y;
    pos.z = winner->pos.z + D_80111E18_352678_name_50[gPlayers[D_8011275A_352FBA_name_50].character].z;
    func_80056658_57258(&pos, &D_80111E0C_35266C_name_50, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 350.0f, 6, 2, 0.5f, 3.0f, 40.0f, 90.0f);
    D_801125D0_352E30_name_50 = PlaySound(0x3E3);
    D_801125D2_352E32_name_50 = PlaySound(0x3E5);
    for (i = 0; i < 10; i++) {
        D_801125D8_352E38_name_50->scale.x += 0.25f;
        HuPrcVSleep();
    }
    func_80108630_348E90_name_50(D_80111E0C_35266C_name_50.x + 60.0f, D_80111E0C_35266C_name_50.y - 0.0f, D_80111E0C_35266C_name_50.z + 150.0f, 1);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, 114.0f, 23.0f, -28.0f);
    func_8002D2B4_2DEB4(*winner->obj->model, -59.0f, 95.0f, 42.0f);
    for (i = 0; i < 60; i++) {
        func_80108F98_3497F8_name_50();
        HuPrcVSleep();
    }
    func_80108F1C_34977C_name_50();
    while (D_801125E4_352E44_name_50->work[1] == 1) {
        HuPrcVSleep();
    }
    func_80108F2C_34978C_name_50();
    func_80108414_348C74_name_50();
    func_801085FC_348E5C_name_50();
    func_801087FC_34905C_name_50();
    func_80079848_7A448(D_801125D0_352E30_name_50);
    func_80079848_7A448(D_801125D2_352E32_name_50);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0, 0, 0);
    func_8002D274_2DE74(*winner->obj->model, 0, 0, 0);
    HuPrcSleep(20);
    MBModelDispOff(winner);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 4);
    func_801089CC_34922C_name_50();
    MBDBackKill();
}

/* Board 2's scene, part 4: the partner casts a spell at the camera (message 0x2F3). */
void func_80106A90_3472F0_name_50(void) {
    Vec cam;
    s16 win2;

    func_80050E00_51A00(0x14);
    func_8005321C_53E1C(80.0f, 8000.0f);
    func_80026E00_27A00(3, 7.0f, 53.0f, 107.0f);
    D_8011275C_352FBC_name_50->pos.x = D_80111E60_3526C0_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_80111E60_3526C0_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_80111E60_3526C0_name_50.z;
    MBMotionSet(D_8011275C_352FBC_name_50, -1, 2);
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &D_8011275C_352FBC_name_50->rot);
    cam.x = 0.0f;
    cam.y = 600.0f;
    cam.z = 0.0f;
    func_8005A950_5B550(&cam, 1.0f, 1.3f, 8);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2F3);
    win2 = func_8005AAC0_5B6C0((320 - D_80112752_352FB2_name_50[0]) / 2, 160, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2F3, -1, -1);
    PlaySound(0x124);
    HuPrcSleep(30);
    PlaySound(0x125);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 3, 0, 4, 0);
    HuPrcSleep(19);
    PlaySound(0x3E6);
    func_80108290_348AF0_name_50(D_8011275C_352FBC_name_50->pos.x - 55.0f, D_8011275C_352FBC_name_50->pos.y + 375.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, -55.0f, 95.0f, 47.0f);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0xDC, 0x28, 0xDC);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    func_80108414_348C74_name_50();
    MBModelDispOff(D_8011275C_352FBC_name_50);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 4);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0, 0, 0);
    MBDBackKill();
}

/* Board 2's scene, part 5: the winner, in front of the camera, sends a third beam. */
void func_80106CF8_347558_name_50(void) {
    Vec cam;
    Vec pos;
    Vec rot;
    MBModel* model;

    func_80050E00_51A00(0x14);
    func_8005321C_53E1C(80.0f, 8000.0f);
    model = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    model->pos.x = D_80111D94_3525F4_name_50.x;
    model->pos.y = D_80111D94_3525F4_name_50.y;
    model->pos.z = D_80111D94_3525F4_name_50.z;
    func_80056658_57258(&model->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &model->rot);
    MBModelDispOn(model);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 0);
    cam.x = 0.0f;
    cam.y = 105.0f;
    cam.z = 0.0f;
    func_8005A950_5B550(&cam, 2.0f, 1.2f, 1);
    MBMotionShiftSet(model, 7, 0, 2, 0);
    HuPrcSleep(30);
    pos.x = model->pos.x + D_80111E6C_3526CC_name_50[gPlayers[D_8011275A_352FBA_name_50].character].x;
    pos.y = model->pos.y + D_80111E6C_3526CC_name_50[gPlayers[D_8011275A_352FBA_name_50].character].y;
    pos.z = model->pos.z + D_80111E6C_3526CC_name_50[gPlayers[D_8011275A_352FBA_name_50].character].z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 300.0f, 8, 1, 0.2f, 3.0f, 20.0f, 0.0f);
    D_801125D0_352E30_name_50 = PlaySound(0x3E4);
    func_8002D2B4_2DEB4(*model->obj->model, -3.0f, -35.0f, 114.0f);
    func_8002D274_2DE74(*model->obj->model, 0xF0, 0xF0, 0x3C);
    func_8002D2B4_2DEB4(D_80112758_352FB8_name_50, -3.0f, -35.0f, 114.0f);
    func_8002D274_2DE74(D_80112758_352FB8_name_50, 0xF0, 0xF0, 0x3C);
    HuPrcSleep(60);
    MBDBackKill();
    func_80108F2C_34978C_name_50();
    MBModelDispOff(model);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 4);
}

/* Board 2's scene, part 6: the partner and the winner cast at each other; the winner's beam
   (func_80108A00's object D_801125E4) pushes and pulls three times before it wins out. */
void func_80106FDC_34783C_name_50(void) {
    Vec tra;
    Vec pos;
    Vec rot;
    MBModel* winner;
    Ovl50BeamWork* beam;
    s32 i;
    s32 j;

    func_80050E00_51A00(0x13);
    func_8005321C_53E1C(80.0f, 8000.0f);
    func_80026E00_27A00(3, -5.0f, 109.0f, 48.0f);
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    winner->pos.x = D_80111E00_352660_name_50.x;
    winner->pos.y = D_80111E00_352660_name_50.y;
    winner->pos.z = D_80111E00_352660_name_50.z;
    D_8011275C_352FBC_name_50->pos.x = D_80111D68_3525C8_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_80111D68_3525C8_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_80111D68_3525C8_name_50.z;
    func_80056658_57258(&winner->pos, &D_8011275C_352FBC_name_50->pos, &winner->rot);
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &winner->pos, &D_8011275C_352FBC_name_50->rot);
    func_800298A4_2A4A4(D_80112750_352FB0_name_50, 4, 0);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 0);
    MBModelDispOn(D_8011275C_352FBC_name_50);
    MBModelDispOn(winner);
    PlaySound(0x3E7);
    func_80108290_348AF0_name_50(D_8011275C_352FBC_name_50->pos.x + 238.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f);
    func_80108448_348CA8_name_50(D_8011275C_352FBC_name_50->pos.x + 238.0f, D_8011275C_352FBC_name_50->pos.y + 355.0f, D_8011275C_352FBC_name_50->pos.z + 200.0f, -41.0f);
    pos.x = winner->pos.x + D_80111EB4_352714_name_50[gPlayers[D_8011275A_352FBA_name_50].character].x;
    pos.y = winner->pos.y + D_80111EB4_352714_name_50[gPlayers[D_8011275A_352FBA_name_50].character].y;
    pos.z = winner->pos.z + D_80111EB4_352714_name_50[gPlayers[D_8011275A_352FBA_name_50].character].z;
    func_80056658_57258(&pos, &D_80111E0C_35266C_name_50, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 350.0f, 2, 2, 0.5f, 3.0f, 60.0f, 90.0f);
    for (i = 0; i < 10; i++) {
        D_801125D8_352E38_name_50->scale.x += 0.2f;
        HuPrcVSleep();
    }
    func_80108630_348E90_name_50(D_80111E0C_35266C_name_50.x + 90.0f, D_80111E0C_35266C_name_50.y - 40.0f, D_80111E0C_35266C_name_50.z + 150.0f, 1);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, 114.0f, 23.0f, -28.0f);
    func_8002D2B4_2DEB4(*winner->obj->model, -59.0f, 95.0f, 42.0f);
    for (i = 0; i < 15; i++) {
        func_80108F98_3497F8_name_50();
        HuPrcVSleep();
    }
    beam = D_801125E4_352E44_name_50->unk_50;
    for (i = 0; i < 20; i++) {
        beam->length -= 10.0f;
        D_801125D8_352E38_name_50->scale.x += 0.12f;
        tra = pos;
        tra.x += rot.x * beam->length + 90.0f;
        tra.y += rot.y * beam->length - 40.0f;
        tra.z += rot.z * beam->length + 150.0f;
        omSetTra(D_801125DC_352E3C_name_50, tra.x, tra.y, tra.z);
        func_80108F98_3497F8_name_50();
        HuPrcVSleep();
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 20; i++) {
            beam->length += 10.0f;
            D_801125D8_352E38_name_50->scale.x -= 0.12f;
            tra = pos;
            tra.x += rot.x * beam->length + 90.0f;
            tra.y += rot.y * beam->length - 40.0f;
            tra.z += rot.z * beam->length + 150.0f;
            omSetTra(D_801125DC_352E3C_name_50, tra.x, tra.y, tra.z);
            func_80108F98_3497F8_name_50();
            HuPrcVSleep();
        }
        for (i = 0; i < 20; i++) {
            beam->length -= 10.0f;
            D_801125D8_352E38_name_50->scale.x += 0.12f;
            tra = pos;
            tra.x += rot.x * beam->length + 90.0f;
            tra.y += rot.y * beam->length - 40.0f;
            tra.z += rot.z * beam->length + 150.0f;
            omSetTra(D_801125DC_352E3C_name_50, tra.x, tra.y, tra.z);
            func_80108F98_3497F8_name_50();
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 30; i++) {
        beam->length += 10.0f;
        D_801125D8_352E38_name_50->scale.x -= 0.12f;
        tra = pos;
        tra.x += rot.x * beam->length + 90.0f;
        tra.y += rot.y * beam->length - 40.0f;
        tra.z += rot.z * beam->length + 150.0f;
        omSetTra(D_801125DC_352E3C_name_50, tra.x, tra.y, tra.z);
        func_80108F98_3497F8_name_50();
        HuPrcVSleep();
    }
    func_80079848_7A448(D_801125D2_352E32_name_50);
    MBModelDispOff(winner);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 4);
    func_80108F2C_34978C_name_50();
    func_80108414_348C74_name_50();
    func_801085FC_348E5C_name_50();
    func_801087FC_34905C_name_50();
    MBDBackKill();
}

/* Board 2's scene, part 7: the partner, beaten, is caught in the beam (message 0x2F4). */
void func_801077E0_348040_name_50(void) {
    Vec cam;
    Vec pos;
    Vec rot;
    s16 win2;

    func_80050E00_51A00(0x14);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_8011275C_352FBC_name_50->pos.x = D_80111E60_3526C0_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_80111E60_3526C0_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_80111E60_3526C0_name_50.z + 250.0f;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &D_8011275C_352FBC_name_50->rot);
    cam.x = 0.0f;
    cam.y = 600.0f;
    cam.z = 0.0f;
    func_8005A950_5B550(&cam, 1.0f, 1.3f, 1);
    pos.x = D_8011275C_352FBC_name_50->pos.x + 0.0f;
    pos.y = D_8011275C_352FBC_name_50->pos.y + 170.0f;
    pos.z = D_8011275C_352FBC_name_50->pos.z + 250.0f;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    func_80108A00_349260_name_50(&pos, &rot, 300.0f, 4, 0, 10.0f, 0.2f, 30.0f, 0.0f);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, 0xF0, 0xF0, 0xB4);
    func_8002D2B4_2DEB4(*D_8011275C_352FBC_name_50->obj->model, -5.0f, -13.0f, 119.0f);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2F4);
    win2 = func_8005AAC0_5B6C0((320 - D_80112752_352FB2_name_50[0]) / 2, 160, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2F4, -1, -1);
    PlaySound(0x123);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    MBDBackKill();
    func_80108F2C_34978C_name_50();
    func_80079848_7A448(D_801125D0_352E30_name_50);
}

/* Board 2's scene, part 8: the partner turns into the changed model (0xA022D), which hops
   away twice (message 0x2F5). */
void func_80107A3C_34829C_name_50(void) {
    MBModel* winner;
    MBModel* morph1;
    MBModel* morph2;
    s32 i;
    s32 j;
    s32 win2;

    func_80050E00_51A00(0x13);
    i = 0;
    func_8005321C_53E1C(80.0f, 8000.0f);
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    MBMotionSet(winner, -1, 2);
    D_8011275C_352FBC_name_50->pos.x = D_80111D68_3525C8_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_80111D68_3525C8_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_80111D68_3525C8_name_50.z;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &winner->pos, &D_8011275C_352FBC_name_50->rot);
    MBModelDispOn(winner);
    func_800298A4_2A4A4(D_80112758_352FB8_name_50, 4, 0);
    func_8002D274_2DE74(*winner->obj->model, 0, 0, 0);
    morph1 = MBModelFileCreate(0xA022D, 13, 1.0f, 1.3f, NULL);
    HmfModelObjAttrSet(*morph1->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*morph1->obj->model);
    func_8002A00C_2AC0C(*morph1->obj->model);
    func_80029E80_2AA80(*morph1->obj->model, 1, 1);
    MBModelDispOff(morph1);
    PlaySound(0x3DC);
    func_80108830_349090_name_50(D_8011275C_352FBC_name_50->pos.x + 70.0f, D_8011275C_352FBC_name_50->pos.y, D_8011275C_352FBC_name_50->pos.z + 150.0f);
    HuPrcSleep(5);
    morph1->pos = D_8011275C_352FBC_name_50->pos;
    morph1->rot = D_8011275C_352FBC_name_50->rot;
    func_8005AA98_5B698(D_80112750_352FB0_name_50);
    func_800283DC_28FDC(D_80112750_352FB0_name_50);
    for (; i < 11; i++) {
        func_8002AC10_2B810(*D_8011275C_352FBC_name_50->obj->model, i * 0.07f, i, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        HuPrcVSleep();
    }
    MBModelKill(D_8011275C_352FBC_name_50);
    MBModelDispOn(morph1);
    for (i = 0; i < 11; i++) {
        func_8002AC10_2B810(*morph1->obj->model, 1.0f - i * 0.07f, 10.0f - i, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        if (i >= 6) {
            D_8011275C_352FBC_name_50->scale.x -= 0.2f;
            D_8011275C_352FBC_name_50->scale.y -= 0.2f;
            D_8011275C_352FBC_name_50->scale.z -= 0.2f;
        }
        HuPrcVSleep();
    }
    MBModelKill(morph1);
    morph2 = MBModelFileCreate(0xA022D, 13, 1.0f, 1.3f, D_80111D20_352580_name_50);
    morph2->pos.x = D_80111D68_3525C8_name_50.x;
    morph2->pos.y = D_80111D68_3525C8_name_50.y;
    morph2->pos.z = D_80111D68_3525C8_name_50.z;
    func_80056658_57258(&morph2->pos, &winner->pos, &morph2->rot);
    HuPrcSleep(30);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x2F5);
    win2 = func_8005AAC0_5B6C0(140, 120, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x2F5, -1, -1);
    PlaySound(0x3D8);
    MBMotionShiftSet(morph2, 1, 0, 2, 0);
    PlaySound(0x3D9);
    for (i = 0; i < 15; i++) {
        if (morph2->jumpY < 0.0f) {
            morph2->jumpY = 0.0f;
        }
        func_8005A5E8_5B1E8(morph2, &winner->pos, 20.0f);
        HuPrcVSleep();
    }
    morph2->jumpY = 0.0f;
    morph2->rot.x = -morph2->rot.x;
    HuPrcSleep(4);
    for (j = 0; j < 2; j++) {
        func_80029C74_2A874(*morph2->obj->model, 0.0f);
        PlaySound(0x3D9);
        for (i = 0; i < 15; i++) {
            if (morph2->jumpY < 0.0f) {
                morph2->jumpY = 0.0f;
            }
            morph2->pos.x += morph2->rot.x * 20.0f;
            morph2->pos.y += morph2->rot.y * 20.0f;
            morph2->pos.z += morph2->rot.z * 20.0f;
            HuPrcVSleep();
        }
        morph2->jumpY = 0.0f;
        HuPrcSleep(4);
    }
    func_800794A8_7A0A8(0x3C);
    MBModelKill(morph2);
    HuPrcSleep(30);
    func_801089CC_34922C_name_50();
    func_8008CCA8_8D8A8(win2);
    MBDBackKill();
}

/* Board 2's scene, the end: the other players' models, music 0x10, and the winner placed for
   the shared winner scene. */
void func_8010804C_3488AC_name_50(void) {
    Vec target;
    MBModel* model;
    s32 i;

    func_80050E00_51A00(0x14);
    i = 0;
    func_8005321C_53E1C(80.0f, 8000.0f);
    model = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    for (; i < 4; i++) {
        if (i != D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80111C88_3524E8_name_50[gPlayers[i].character], 2);
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
    PlayMusic(0x10);
    D_80111960_3521C0_name_50 = 0x10;
    target.x = target.y = 0.0f;
    target.z = 2500.0f;
    model->pos.x = D_80111AE4_352344_name_50.x;
    model->pos.y = D_80111AE4_352344_name_50.y;
    model->pos.z = D_80111AE4_352344_name_50.z;
    func_80056658_57258(&model->pos, &target, &model->rot);
    func_8005ACD0_5B8D0(&gPlayers[D_8011275A_352FBA_name_50], 0);
    func_80026E00_27A00(1, -8.0f, 76.0f, 91.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108290_348AF0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108414_348C74_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108448_348CA8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801085FC_348E5C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108630_348E90_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801087FC_34905C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108830_349090_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801089CC_34922C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108A00_349260_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108C6C_3494CC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F1C_34977C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F2C_34978C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F98_3497F8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80109070_3498D0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801090FC_34995C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80109290_349AF0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A2A4_34AB04_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A580_34ADE0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A9B8_34B218_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010AB4C_34B3AC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010B230_34BA90_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CD24_34D584_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CE28_34D688_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CF08_34D768_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CFE8_34D848_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010D198_34D9F8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010D320_34DB80_name_50);
