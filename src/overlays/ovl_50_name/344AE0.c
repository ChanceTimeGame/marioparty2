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

/* A glow (sprite model 0x689, texture 0xA0249) at a point; D_801125D4. */
void func_80108290_348AF0_name_50(f32 x, f32 y, f32 z) {
    void* data;
    s16 tex;

    data = DataRead(0xA0249);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    D_801125D4_352E34_name_50 = omAddObj(0x1F4, 2, 0, -1, NULL);
    D_801125D4_352E34_name_50->model[1] = func_80020EBC_21ABC((void*)-1, 0x689, 8);
    D_800F86D8_F92D8[D_801125D4_352E34_name_50->model[1]].unk02 = tex;
    func_80021160_21D60(D_801125D4_352E34_name_50->model[1], 6, 0);
    D_801125D4_352E34_name_50->model[0] = D_800F86D8_F92D8[D_801125D4_352E34_name_50->model[1]].unk00;
    HmfModelObjAttrSet(D_801125D4_352E34_name_50->model[0], 0x70000000, 0x70000000);
    func_80021250_21E50(D_801125D4_352E34_name_50->model[1], 0xFF, 0, 0xE6);
    omSetSca(D_801125D4_352E34_name_50, 2.0f, 2.0f, 2.0f);
    omSetTra(D_801125D4_352E34_name_50, x, y, z);
}

void func_80108414_348C74_name_50(void) {
    func_8002308C_23C8C(D_801125D4_352E34_name_50->model[1]);
    omDelObj(D_801125D4_352E34_name_50);
}

/* A flash (0xA024A) at a point, turned to the camera, rotated about z by rotZ; D_801125D8. */
void func_80108448_348CA8_name_50(f32 x, f32 y, f32 z, f32 rotZ) {
    Vec pos;
    Vec rot;
    void* data;
    s16 tex;

    data = DataRead(0xA024A);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    D_801125D8_352E38_name_50 = omAddObj(0x1F4, 2, 0, -1, NULL);
    D_801125D8_352E38_name_50->model[1] = func_80020EBC_21ABC((void*)-1, 0x689, 8);
    D_800F86D8_F92D8[D_801125D8_352E38_name_50->model[1]].unk02 = tex;
    func_80021160_21D60(D_801125D8_352E38_name_50->model[1], 6, 0);
    D_801125D8_352E38_name_50->model[0] = D_800F86D8_F92D8[D_801125D8_352E38_name_50->model[1]].unk00;
    func_80021250_21E50(D_801125D8_352E38_name_50->model[1], 0xFF, 0, 0xE6);
    omSetSca(D_801125D8_352E38_name_50, 1.0f, 2.0f, 1.0f);
    pos.x = x;
    pos.y = y;
    pos.z = z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    D_801125D8_352E38_name_50->rot.y = func_80042BE0_437E0(&rot);
    omSetTra(D_801125D8_352E38_name_50, x, y, z);
    D_801125D8_352E38_name_50->rot.z = rotZ;
}

void func_801085FC_348E5C_name_50(void) {
    func_8002308C_23C8C(D_801125D8_352E38_name_50->model[1]);
    omDelObj(D_801125D8_352E38_name_50);
}

/* The beams' meeting point (0xA024B), turned to the camera; dim is a darker tint. */
void func_80108630_348E90_name_50(f32 x, f32 y, f32 z, u16 dim) {
    Vec pos;
    Vec rot;
    void* data;
    s16 tex;

    data = DataRead(0xA024B);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    D_801125DC_352E3C_name_50 = omAddObj(0x1F4, 2, 0, -1, NULL);
    D_801125DC_352E3C_name_50->model[1] = func_80020EBC_21ABC((void*)-1, 0x689, 8);
    D_800F86D8_F92D8[D_801125DC_352E3C_name_50->model[1]].unk02 = tex;
    func_80021160_21D60(D_801125DC_352E3C_name_50->model[1], 6, 0);
    D_801125DC_352E3C_name_50->model[0] = D_800F86D8_F92D8[D_801125DC_352E3C_name_50->model[1]].unk00;
    if (dim == 0) {
        func_80021250_21E50(D_801125DC_352E3C_name_50->model[1], 0xFF, 0, 0xE6);
    } else {
        func_80021250_21E50(D_801125DC_352E3C_name_50->model[1], 0xFF, 0xA4, 0xE6);
    }
    omSetSca(D_801125DC_352E3C_name_50, 6.5f, 3.5f, 6.5f);
    pos.x = x;
    pos.y = y;
    pos.z = z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    D_801125DC_352E3C_name_50->rot.y = func_80042BE0_437E0(&rot);
    omSetTra(D_801125DC_352E3C_name_50, x, y, z);
}

void func_801087FC_34905C_name_50(void) {
    func_8002308C_23C8C(D_801125DC_352E3C_name_50->model[1]);
    omDelObj(D_801125DC_352E3C_name_50);
}

/* A white burst (0xA024F) at a point, turned to the camera; D_801125E0. */
void func_80108830_349090_name_50(f32 x, f32 y, f32 z) {
    Vec pos;
    Vec rot;
    void* data;
    s16 tex;

    data = DataRead(0xA024F);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    D_801125E0_352E40_name_50 = omAddObj(0x1F4, 2, 0, -1, NULL);
    D_801125E0_352E40_name_50->model[1] = func_80020EBC_21ABC((void*)-1, 0x689, 8);
    D_800F86D8_F92D8[D_801125E0_352E40_name_50->model[1]].unk02 = tex;
    func_80021160_21D60(D_801125E0_352E40_name_50->model[1], 6, 0);
    D_801125E0_352E40_name_50->model[0] = D_800F86D8_F92D8[D_801125E0_352E40_name_50->model[1]].unk00;
    func_80021250_21E50(D_801125E0_352E40_name_50->model[1], 0xFF, 0xFF, 0xFF);
    omSetSca(D_801125E0_352E40_name_50, 8.0f, 8.0f, 8.0f);
    pos.x = x;
    pos.y = y;
    pos.z = z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    D_801125E0_352E40_name_50->rot.y = func_80042BE0_437E0(&rot);
    omSetTra(D_801125E0_352E40_name_50, x, y, z);
}

void func_801089CC_34922C_name_50(void) {
    func_8002308C_23C8C(D_801125E0_352E40_name_50->model[1]);
    omDelObj(D_801125E0_352E40_name_50);
}

/* A beam: every interval frames, while obj->work[0] is 1, a ring (sprite model 0x68D, texture
   0xA024D) starts at start and grows by grow per frame (from scale0 to scale1 over the length);
   mode bit 1 moves it along dir at speed, bit 0 gives 8 rings instead of 4. work[1] is 1 until
   the last ring of a stopped beam has gone. */
void func_80108A00_349260_name_50(Vec* start, Vec* dir, f32 length, u16 interval, u16 mode, f32 scale0, f32 scale1, f32 speed, f32 rotY) {
    Ovl50BeamWork* work;
    void* data;
    s32 i;

    D_801125E4_352E44_name_50 = omAddObj(0x1F4, 0, 0, -1, func_80108C6C_3494CC_name_50);
    work = D_801125E4_352E44_name_50->unk_50 = func_80027154_27D54(sizeof(Ovl50BeamWork), 0x7918);
    data = DataRead(0xA024D);
    work->tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    work->length = length;
    work->mode = mode;
    if (mode & 1) {
        work->count = 8;
    } else {
        work->count = 4;
    }
    for (i = 0; i < work->count; i++) {
        work->slot[i] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
        D_800F86D8_F92D8[work->slot[i]].unk02 = work->tex;
        func_80021160_21D60(work->slot[i], 6, 0);
        work->model[i] = D_800F86D8_F92D8[work->slot[i]].unk00;
        func_80021250_21E50(work->slot[i], 0xFF, 0xE6, 0);
        HmfModelObjAttrSet(work->model[i], 0x70000000, 0);
    }
    for (i = 0; i < 8; i++) {
        work->active[i] = 0;
    }
    work->start = *start;
    work->dir = *dir;
    work->rotY = rotY;
    work->scale0 = scale0;
    work->scale1 = scale1;
    work->speed = speed;
    work->timer = 0;
    work->interval = interval;
    work->grow = (work->scale1 - scale0) / (length / speed);
    D_801125E4_352E44_name_50->work[0] = 1;
}

void func_80108C6C_3494CC_name_50(omObjData* obj) {
    Ovl50BeamWork* work = D_801125E4_352E44_name_50->unk_50;
    s32 idle = 0;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (work->active[i] == 0) {
            idle++;
            continue;
        }
        work->dist[i] += work->speed;
        if (work->length <= work->dist[i]) {
            work->active[i] = 0;
            func_800298A4_2A4A4(work->model[i], 4, 4);
            continue;
        }
        if (work->mode & 2) {
            work->pos[i].x += work->dir.x * work->speed;
            work->pos[i].y += work->dir.y * work->speed;
            work->pos[i].z += work->dir.z * work->speed;
        }
        func_80029714_2A314(work->model[i], work->pos[i].x, work->pos[i].y, work->pos[i].z);
        work->scale[i] += work->grow;
        func_800297E8_2A3E8(work->model[i], work->scale[i], work->scale[i], 1.0f);
    }
    if (work->timer == 0) {
        if (D_801125E4_352E44_name_50->work[0] == 1) {
            D_801125E4_352E44_name_50->work[1] = 1;
            work->timer = work->interval;
            for (i = 0; i < 8; i++) {
                if (work->active[i] == 0) {
                    break;
                }
            }
            if (i != 8) {
                work->active[i] = 1;
                func_800298A4_2A4A4(work->model[i], 4, 0);
                work->scale[i] = work->scale0;
                work->dist[i] = 0.0f;
                work->pos[i] = work->start;
                func_80029714_2A314(work->model[i], work->pos[i].x, work->pos[i].y, work->pos[i].z);
                func_800297E8_2A3E8(work->model[i], work->scale[i], work->scale[i], 1.0f);
                func_8002979C_2A39C(work->model[i], 0.0f, work->rotY, 0.0f);
            }
        }
    } else {
        work->timer--;
    }
    if (idle == 8 && D_801125E4_352E44_name_50->work[0] == 0) {
        D_801125E4_352E44_name_50->work[1] = 0;
    }
}

void func_80108F1C_34977C_name_50(void) {
    D_801125E4_352E44_name_50->work[0] = 0;
}

/* Kills the beam's rings and object. */
void func_80108F2C_34978C_name_50(void) {
    Ovl50BeamWork* work = D_801125E4_352E44_name_50->unk_50;
    s32 i;

    for (i = 0; i < work->count; i++) {
        func_8002308C_23C8C(work->slot[i]);
    }
    omDelObj(D_801125E4_352E44_name_50);
}

/* Flashes the winner and D_8011275C: lit and normal tints in turn. */
void func_80108F98_3497F8_name_50(void) {
    u8 r;
    u8 g;
    u8 b;

    if (D_80111EFC_35275C_name_50 != 0) {
        r = 0xF5;
        g = 0xC8;
        b = 0xF5;
    } else {
        r = 0x78;
        g = 0x64;
        b = 0xF5;
    }
    func_8002D274_2DE74(*OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->obj->model, r, g, b);
    func_8002D274_2DE74(*D_8011275C_352FBC_name_50->obj->model, r, g, b);
    D_80111EFC_35275C_name_50 ^= 1;
}

void func_80109070_3498D0_name_50(void) {
    D_8010105C_101C5C = D_80101300_101F00 = 0.6f;
    func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    func_80020D20_21920(4);
    func_80109290_349AF0_name_50();
    func_8010A2A4_34AB04_name_50();
    func_8010A580_34ADE0_name_50();
    func_8010A9B8_34B218_name_50();
    func_8010AB4C_34B3AC_name_50();
    func_8010B230_34BA90_name_50();
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
}

void func_801090FC_34995C_name_50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80112008_352868_name_50[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
            func_80043DAC_449AC(OVL50_PLAYER_MODEL(i));
            gPlayers[i].flags |= 2;
            MBMotionSet(OVL50_PLAYER_MODEL(i), 0, 2);
            func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(i)->obj->model, 1);
            MBModelDispOff(OVL50_PLAYER_MODEL(i));
        }
    }
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80023, 13, 0.8f, 0.8f, D_80112020_352880_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80112064_3528C4_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
}

/* Board 4's scene, part 1: the host (D_80112748) and D_8011275C meet before a sign (0xA0204)
   with a sparkle (func_8010CFE8); a cage (0xA0205) drops on the host, the doors (0xA018E) open.
   Messages 0x321-0x32B; three sprites (0xA01FA/C/E) show a picture. */
#ifdef NON_MATCHING /* register allocation: retail hoists the constant 2 into s8 and keeps stopped in s4; this spills stopped */
void func_80109290_349AF0_name_50(void) {
    Vec target;
    s16 flags[2];
    MBModel* sign;
    MBModel* door2;
    s16 anim1;
    s16 anim2;
    s16 anim3;
    s16 spr1;
    s16 spr2;
    s16 spr3;
    MBModel* cage;
    MBModel* door1;
    s32 win;
    s32 win3;
    s32 win4;
    s16 win2;
    s32 i;
    s32 turned;
    s32 stopped;
    s32 started;
    f32 speed;

    stopped = 0;
    MBModelKill(D_8011274C_352FAC_name_50);
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80023, 13, 0.8f, 0.8f, D_80112020_352880_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80112064_3528C4_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
    func_80050E00_51A00(0x21);
    func_8005321C_53E1C(80.0f, 8000.0f);
    sign = MBModelFileCreate(0xA0204, 0, 1.5f, 0.0f, NULL);
    sign->pos.x = D_8011208C_3528EC_name_50.x;
    sign->pos.y = D_8011208C_3528EC_name_50.y;
    sign->pos.z = D_8011208C_3528EC_name_50.z;
    D_80112600_352E60_name_50 = func_8010CFE8_34D848_name_50(D_8011208C_3528EC_name_50.x + 15.0f, D_8011208C_3528EC_name_50.y + 230.0f, D_8011208C_3528EC_name_50.z + 100.0f);
    D_80112748_352FA8_name_50 = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_80112034_352894_name_50);
    func_8005AB50_5B750(D_80112748_352FA8_name_50, 2, 7, D_8011206C_3528CC_name_50);
    func_8002D1EC_2DDEC(*D_80112748_352FA8_name_50->obj->model, 1);
    D_80112748_352FA8_name_50->pos.x = D_80112098_3528F8_name_50[0].x;
    D_80112748_352FA8_name_50->pos.y = D_80112098_3528F8_name_50[0].y;
    D_80112748_352FA8_name_50->pos.z = D_80112098_3528F8_name_50[0].z;
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &D_80112098_3528F8_name_50[1], &D_80112748_352FA8_name_50->rot);
    D_8011275C_352FBC_name_50 = MBModelFileCreate(0x80060, 13, 1.0f, 3.0f, D_801120F8_352958_name_50);
    func_8005AB50_5B750(D_8011275C_352FBC_name_50, 2, 9, D_80112070_3528D0_name_50[0]);
    MBMotionSet(D_8011275C_352FBC_name_50, 0, 2);
    func_8002D1EC_2DDEC(*D_8011275C_352FBC_name_50->obj->model, 1);
    D_8011275C_352FBC_name_50->pos.x = D_801120BC_35291C_name_50.x;
    D_8011275C_352FBC_name_50->pos.y = D_801120BC_35291C_name_50.y;
    D_8011275C_352FBC_name_50->pos.z = D_801120BC_35291C_name_50.z;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &D_80112748_352FA8_name_50->pos, &D_8011275C_352FBC_name_50->rot);
    cage = MBModelFileCreate(0xA0205, 0, 1.0f, 0.0f, NULL);
    cage->pos.x = 0.0f;
    cage->pos.y = 2000.0f;
    cage->pos.z = 0.0f;
    door1 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door1);
    door1->pos.x = D_801120E0_352940_name_50.x;
    door1->pos.y = D_801120E0_352940_name_50.y;
    door1->pos.z = D_801120E0_352940_name_50.z;
    door1->attr |= 4;
    door2 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door2);
    door2->pos.x = D_801120E0_352940_name_50.x;
    door2->pos.y = D_801120E0_352940_name_50.y;
    door2->pos.z = D_801120E0_352940_name_50.z;
    door2->attr |= 4;
    anim1 = func_8001A2F8_1AEF8(0xA01FA);
    anim2 = func_8001A2F8_1AEF8(0xA01FC);
    anim3 = func_8001A2F8_1AEF8(0xA01FE);
    spr1 = func_8001AAAC_1B6AC(anim1, 0, 1);
    spr2 = func_8001AAAC_1B6AC(anim2, 0, 1);
    spr3 = func_8001AAAC_1B6AC(anim3, 0, 1);
    espDispOff(spr1);
    espDispOff(spr2);
    espDispOff(spr3);
    target.x = D_8011208C_3528EC_name_50.x;
    target.y = 150.0f;
    target.z = D_8011208C_3528EC_name_50.z;
    func_8005A950_5B550(&target, 3.0f, 3.0f, 1);
    D_80112748_352FA8_name_50->pos.x = D_80112098_3528F8_name_50[1].x;
    D_80112748_352FA8_name_50->pos.y = D_80112098_3528F8_name_50[1].y;
    D_80112748_352FA8_name_50->pos.z = D_80112098_3528F8_name_50[1].z;
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &D_8011208C_3528EC_name_50, &D_80112748_352FA8_name_50->rot);
    InitFadeIn(3, 16);
    HuPrcSleep(16);
    HuPrcSleep(20);
    D_80112600_352E60_name_50->work[0] = 1;
    func_8005A950_5B550(&target, 3.0f, 1.0f, 30);
    HuPrcSleep(30);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x321);
    win = func_8005AAC0_5B6C0(80, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x321, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(15);
    PlaySound(0xE7);
    HuPrcSleep(35);
    func_8008CCA8_8D8A8(win);
    i = 0;
    turned = 0;
    while (func_8005A5E8_5B1E8(D_8011275C_352FBC_name_50, &D_801120C8_352928_name_50[0], 18.0f) == 0) {
        if (i == 15) {
            PlayMusic(0x3C);
            func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x322);
            win = func_8005AAC0_5B6C0(40, 45, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
            func_800890CC_89CCC(win, 0x322, -1, -1);
            PlaySound(0x123);
        }
        if (i >= 15) {
            func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &D_8011275C_352FBC_name_50->pos, 10.0f);
        }
        if (i >= 35) {
            if (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &D_8011275C_352FBC_name_50->pos, 10.0f) == 1 && turned == 0) {
                turned = 1;
                MBMotionShiftSet(D_80112748_352FA8_name_50, 4, 0, 4, 2);
                func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x323);
                win3 = func_8005AAC0_5B6C0(200, 70, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
                func_800890CC_89CCC(win3, 0x323, -1, -1);
                PlaySound(0xE7);
            }
            if (turned == 1 && func_8005A608_5B208(D_80112748_352FA8_name_50, &D_801120B0_352910_name_50, 10.0f) == turned && stopped == 0) {
                MBMotionShiftSet(D_80112748_352FA8_name_50, 3, 0, 8, 2);
                stopped = 1;
            }
        }
        if (i == 65) {
            func_8008CCA8_8D8A8(win);
        }
        i++;
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 4, 2);
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_80112070_3528D0_name_50[2]);
    HuPrcSleep(15);
    func_8008CCA8_8D8A8(win3);
    HuPrcSleep(20);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x324);
    win2 = func_8005AAC0_5B6C0(50, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x324, -1, -1);
    PlaySound(0x125);
    HuPrcSleep(35);
    func_8008CCA8_8D8A8(win2);
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_80112070_3528D0_name_50[0]);
    while (func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &((HuCamera*)D_800FD2A8_FDEA8)->pos, 8.0f) == 0) {
        HuPrcVSleep();
    }
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x326);
    win = func_8005AAC0_5B6C0(32, 170, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x326, -1, -1);
    PlaySound(0x123);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80112748_352FA8_name_50, -1, 0, 4, 2);
    win4 = func_8005AAC0_5B6C0(136, 40, 48, 48);
    espPosSet(spr1, 160, 64);
    espDispOn(spr1);
    PlaySound(0x3F7);
    D_80112604_352E64_name_50 = PlaySound(0x3F8);
    HuPrcSleep(10);
    while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &((HuCamera*)D_800FD2A8_FDEA8)->pos, 15.0f) == 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(50);
    func_80079848_7A448(D_80112604_352E64_name_50);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 5, 0, 4, 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x327);
    win3 = func_8005AAC0_5B6C0(200, 100, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win3, 0x327, -1, -1);
    PlaySound(0xE7);
    while (func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &D_80112748_352FA8_name_50->pos, 6.0f) == 0) {
        HuPrcVSleep();
    }
    i = 0;
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_80112070_3528D0_name_50[2]);
    HuPrcSleep(25);
    func_8008CCA8_8D8A8(win3);
    MBMotionShiftSet(D_80112748_352FA8_name_50, 6, 0, 4, 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x328);
    win3 = func_8005AAC0_5B6C0(200, 100, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win3, 0x328, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(20);
    do {
        func_8001A91C_1B51C(spr1, 1.0f - i * 0.2f, 1.0f);
        i++;
        HuPrcVSleep();
    } while (i < 5);
    espDispOff(spr1);
    espDispOn(spr2);
    espPosSet(spr2, 160, 64);
    i = 0;
    do {
        func_8001A91C_1B51C(spr2, i * 0.2f, 1.0f);
        i++;
        HuPrcVSleep();
    } while (i < 5);
    func_8001A91C_1B51C(spr2, 1.0f, 1.0f);
    HuPrcSleep(25);
    espDispOn(spr3);
    espPosSet(spr3, 160, 64);
    PlaySound(0x3F3);
    HuPrcSleep(20);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win3);
    func_8008CCA8_8D8A8(win4);
    espDispOff(spr2);
    espDispOff(spr3);
    MBMotionShiftSet(D_80112748_352FA8_name_50, -1, 0, 2, 2);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x329);
    win = func_8005AAC0_5B6C0(28, 40, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x329, -1, -1);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 1, 0, 4, 0);
    cage->pos.x = D_80112748_352FA8_name_50->pos.x;
    cage->pos.y = 500.0f;
    cage->pos.z = D_80112748_352FA8_name_50->pos.z;
    PlaySound(0x123);
    HuPrcSleep(25);
    cage->rot = D_80112748_352FA8_name_50->rot;
    speed = 1.3f;
    while (1) {
        cage->pos.y -= speed;
        speed *= 1.2f;
        if (cage->pos.y <= 0.0f) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionSet(D_80112748_352FA8_name_50, 0, 1);
    cage->pos.y = 0.0f;
    PlaySound(0x3F6);
    HuPrcSleep(15);
    MBMotionShiftSet(D_8011275C_352FBC_name_50, 4, 0, 4, 2);
    HuPrcSleep(25);
    func_8008CCA8_8D8A8(win);
    while (func_8005A5E8_5B1E8(door1, &D_801120EC_35294C_name_50, 10.0f) == 0) {
        func_8005A5E8_5B1E8(door2, &D_801120EC_35294C_name_50, 10.0f);
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    i = 30;
    flags[1] = 0;
    flags[0] = 0;
    started = 0;
    MBMotionShiftSet(D_8011275C_352FBC_name_50, -1, 0, 12, 2);
    turned = 0;
    func_8005AC6C_5B86C(D_8011275C_352FBC_name_50, D_80112070_3528D0_name_50[0]);
    while (1) {
        if (func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &door1->pos, 6.0f) != 0) {
            turned = 1;
            if (flags[0] == 0) {
                flags[0] = 1;
                func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32A);
                win = func_8005AAC0_5B6C0(120, 50, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
                func_800890CC_89CCC(win, 0x32A, -1, -1);
                PlaySound(0x125);
            }
        }
        if (i == 0) {
            if (started == 0) {
                started = 1;
            }
            if (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &door1->pos, 10.0f) != 0) {
                turned++;
            }
            cage->rot = D_80112748_352FA8_name_50->rot;
        } else {
            i--;
        }
        if (turned == 2) {
            break;
        }
        turned = 0;
        HuPrcVSleep();
    }
    HuPrcSleep(18);
    func_800794A8_7A0A8(120);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32B);
    win2 = func_8005AAC0_5B6C0(126, 90, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x32B, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(80);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win2);
    MBModelKill(sign);
    MBModelDispOff(D_8011275C_352FBC_name_50);
    MBModelDispOff(D_80112748_352FA8_name_50);
    MBModelKill(cage);
    MBModelKill(door2);
    MBModelKill(door1);
    func_8001AC44_1B844(spr1);
    func_8001AC44_1B844(spr2);
    func_8001AC44_1B844(spr3);
    SprAnimKill(anim1);
    SprAnimKill(anim2);
    SprAnimKill(anim3);
    MBDBackKill();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80109290_349AF0_name_50);
#endif

/* Board 4's scene, part 2 (4F's func_8010A150): the winner alone; message 0x32C names them. */
void func_8010A2A4_34AB04_name_50(void) {
    Vec v;
    MBModel* winner;
    s16 win;

    func_80050E00_51A00(0x22);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80112600_352E60_name_50->work[0] = 0;
    MBPlayerModelCreate(D_8011275A_352FBA_name_50, D_80112008_352868_name_50[gPlayers[D_8011275A_352FBA_name_50].character], 2);
    func_8005ABC0_5B7C0(&gPlayers[D_8011275A_352FBA_name_50], 2, 11);
    func_80043DAC_449AC(OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50));
    gPlayers[D_8011275A_352FBA_name_50].flags |= 2;
    func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->obj->model, 1);
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    winner->pos.x = D_80112110_352970_name_50.x;
    winner->pos.y = D_80112110_352970_name_50.y;
    winner->pos.z = D_80112110_352970_name_50.z;
    MBModelDispOn(winner);
    v.x = 0.0f;
    v.y = 105.0f;
    v.z = 0.0f;
    func_8005A950_5B550(&v, 3.0f, 1.0f, 8);
    PlayMusic(0x3B);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32C);
    win = func_8005AAC0_5B6C0(0x2D, 0x28, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_800890CC_89CCC(win, 0x32C, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(15);
    PlaySound(0xE7);
    HuPrcSleep(45);
    func_8008CCA8_8D8A8(win);
    MBModelDispOff(winner);
    MBDBackKill();
}

/* Board 4's scene, part 3: back at the sign, the caged host hops away (D_80112128) while the
   winner watches; messages 0x32D, 0x32E and a picture (0xA01FA). */
void func_8010A580_34ADE0_name_50(void) {
    s16 anim;
    s16 spr;
    MBModel* sign;
    MBModel* cage;
    MBModel* winner;
    s32 win2;
    s16 win;
    s32 win3;
    f32 vel;

    func_80050E00_51A00(0x21);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80112600_352E60_name_50->work[0] = 1;
    anim = func_8001A2F8_1AEF8(0xA01FA);
    spr = func_8001AAAC_1B6AC(anim, 0, 1);
    espDispOff(spr);
    sign = MBModelFileCreate(0xA0204, 0, 1.5f, 0.0f, NULL);
    sign->pos.x = D_8011208C_3528EC_name_50.x;
    sign->pos.y = D_8011208C_3528EC_name_50.y;
    sign->pos.z = D_8011208C_3528EC_name_50.z;
    cage = MBModelFileCreate(0xA0205, 0, 1.0f, 0.0f, NULL);
    cage->pos.x = 0.0f;
    cage->pos.y = 2000.0f;
    cage->pos.z = 0.0f;
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    cage->pos = D_80112748_352FA8_name_50->pos;
    cage->rot = D_80112748_352FA8_name_50->rot;
    MBModelDispOn(D_80112748_352FA8_name_50);
    MBModelDispOn(D_8011275C_352FBC_name_50);
    D_80112748_352FA8_name_50->pos.x = D_8011211C_35297C_name_50.x;
    D_80112748_352FA8_name_50->pos.y = D_8011211C_35297C_name_50.y;
    D_80112748_352FA8_name_50->pos.z = D_8011211C_35297C_name_50.z;
    cage->pos = D_80112748_352FA8_name_50->pos;
    winner->pos.x = D_80112134_352994_name_50.x;
    winner->pos.y = D_80112134_352994_name_50.y;
    winner->pos.z = D_80112134_352994_name_50.z;
    func_80056658_57258(&winner->pos, &D_8011275C_352FBC_name_50->pos, &winner->rot);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32D);
    win2 = func_8005AAC0_5B6C0(24, 35, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x32D, -1, -1);
    PlaySound(0x125);
    vel = 14.0f;
    while (func_8005A5E8_5B1E8(D_80112748_352FA8_name_50, &D_80112128_352988_name_50, 20.0f) != 1) {
        D_80112748_352FA8_name_50->jumpY += vel;
        vel -= 2.0f;
        if (D_80112748_352FA8_name_50->jumpY <= 0.0f) {
            D_80112748_352FA8_name_50->jumpY = 0.0f;
            vel = 14.0f;
        }
        cage->pos.x = D_80112748_352FA8_name_50->pos.x;
        cage->pos.y = D_80112748_352FA8_name_50->pos.y;
        cage->pos.z = D_80112748_352FA8_name_50->pos.z;
        cage->jumpY = D_80112748_352FA8_name_50->jumpY;
        HuPrcVSleep();
    }
    func_8008CCA8_8D8A8(win2);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32E);
    win = func_8005AAC0_5B6C0(32, 170, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x32E, -1, -1);
    PlaySound(0x123);
    HuPrcSleep(20);
    win3 = func_8005AAC0_5B6C0(136, 40, 48, 48);
    espPosSet(spr, 160, 64);
    espDispOn(spr);
    PlaySound(0x3F7);
    HuPrcSleep(30);
    D_80112604_352E64_name_50 = PlaySound(0x3F8);
    HuPrcSleep(20);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win3);
    func_8001AC44_1B844(spr);
    SprAnimKill(anim);
    MBModelDispOff(D_8011275C_352FBC_name_50);
    MBModelDispOff(D_80112748_352FA8_name_50);
    MBModelKill(cage);
    MBModelKill(sign);
    MBDBackKill();
}

/* Board 4's scene, part 4: the winner faces the camera and poses; a picture (0xA01FD). */
void func_8010A9B8_34B218_name_50(void) {
    Vec v;
    s16 anim;
    s16 spr;
    MBModel* winner;

    func_80050E00_51A00(0x22);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80112600_352E60_name_50->work[0] = 0;
    anim = func_8001A2F8_1AEF8(0xA01FD);
    spr = func_8001AAAC_1B6AC(anim, 0, 1);
    espDispOff(spr);
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    MBModelDispOn(winner);
    winner->pos.x = D_80112110_352970_name_50.x;
    winner->pos.y = D_80112110_352970_name_50.y;
    winner->pos.z = D_80112110_352970_name_50.z;
    func_80056658_57258(&winner->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &winner->rot);
    MBMotionSet(winner, 4, 2);
    HuPrcSleep(60);
    v.x = 0.0f;
    v.y = 105.0f;
    v.z = 0.0f;
    func_8005A950_5B550(&v, 1.0f, 2.0f, 8);
    MBMotionShiftSet(winner, 7, 0, 4, 0);
    HuPrcSleep(4);
    espDispOn(spr);
    espPosSet(spr, 160, 40);
    PlaySound(0x400);
    HuPrcSleep(20);
    func_8001AC44_1B844(spr);
    SprAnimKill(anim);
    MBDBackKill();
}

/* Board 4's scene, part 5: the winner walks to D_80112170 facing D_8011275C, takes the prize
   (form D_80112158[character], hung on part D_80112140[character]) while the picture changes
   (0xA01FA to 0xA01FB); message 0x32F. Then the winner's board model is recreated there. */
void func_8010AB4C_34B3AC_name_50(void) {
    Vec rot;
    s16 anim1;
    s16 anim2;
    MBModel* winner;
    s16 spr2;
    s16 form;
    s16 spr1;
    MBModel* sign;
    s32 win;
    s16 win2;
    s32 i;

    func_80050E00_51A00(0x21);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80112600_352E60_name_50->work[0] = 1;
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    anim1 = func_8001A2F8_1AEF8(0xA01FA);
    anim2 = func_8001A2F8_1AEF8(0xA01FB);
    spr1 = func_8001AAAC_1B6AC(anim1, 0, 1);
    spr2 = func_8001AAAC_1B6AC(anim2, 0, 1);
    espDispOff(spr1);
    espDispOff(spr2);
    form = LoadFormFile(D_80112158_3529B8_name_50[gPlayers[D_8011275A_352FBA_name_50].character], 0x6BD);
    func_8002D1EC_2DDEC(form, 1);
    sign = MBModelFileCreate(0xA0204, 0, 1.5f, 0.0f, NULL);
    sign->pos.x = D_8011208C_3528EC_name_50.x;
    sign->pos.y = D_8011208C_3528EC_name_50.y;
    sign->pos.z = D_8011208C_3528EC_name_50.z;
    winner->pos.x = D_80112134_352994_name_50.x;
    winner->pos.y = D_80112134_352994_name_50.y;
    winner->pos.z = D_80112134_352994_name_50.z;
    func_80056658_57258(&winner->pos, &D_8011275C_352FBC_name_50->pos, &winner->rot);
    MBModelDispOn(D_8011275C_352FBC_name_50);
    win = func_8005AAC0_5B6C0(136, 40, 48, 48);
    espPosSet(spr1, 160, 64);
    espDispOn(spr1);
    MBMotionSet(winner, 2, 2);
    func_80056658_57258(&winner->pos, &D_80112170_3529D0_name_50, &winner->rot);
    while (func_8005A5E8_5B1E8(winner, &D_80112170_3529D0_name_50, 20.0f) == 0) {
        func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &winner->pos, 8.0f);
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(winner, &D_8011275C_352FBC_name_50->pos, 10.0f) == 0) {
        func_8005A7E8_5B3E8(D_8011275C_352FBC_name_50, &winner->pos, 8.0f);
        HuPrcVSleep();
    }
    MBMotionShiftSet(winner, -1, 0, 4, 2);
    rot = winner->rot;
    HuPrcSleep(20);
    MBMotionShiftSet(winner, 8, 0, 4, 0);
    HuPrcSleep(10);
    func_80023DAC_249AC(form, D_80112140_3529A0_name_50[gPlayers[D_8011275A_352FBA_name_50].character], *winner->obj->model,
                        D_80112140_3529A0_name_50[gPlayers[D_8011275A_352FBA_name_50].character]);
    i = 0;
    do {
        func_8001A91C_1B51C(spr1, 1.0f - i * 0.2f, 1.0f);
        i++;
        HuPrcVSleep();
    } while (i < 5);
    espDispOff(spr1);
    espDispOn(spr2);
    espPosSet(spr2, 160, 64);
    i = 0;
    do {
        func_8001A91C_1B51C(spr2, i * 0.2f, 1.0f);
        i++;
        HuPrcVSleep();
    } while (i < 5);
    func_8001A91C_1B51C(spr2, 1.0f, 1.0f);
    HuPrcSleep(10);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x32F);
    win2 = func_8005AAC0_5B6C0(24, 35, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win2, 0x32F, -1, -1);
    PlaySound(0x122);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win2);
    func_8008CCA8_8D8A8(win);
    MBModelKill(sign);
    func_8001AC44_1B844(spr1);
    func_8001AC44_1B844(spr2);
    SprAnimKill(anim1);
    SprAnimKill(anim2);
    MBModelKill(winner);
    func_800283DC_28FDC(form);
    MBDBackKill();
    MBPlayerModelCreate(D_8011275A_352FBA_name_50, D_80112008_352868_name_50[gPlayers[D_8011275A_352FBA_name_50].character], 2);
    func_8005ABC0_5B7C0(&gPlayers[D_8011275A_352FBA_name_50], 2, 11);
    gPlayers[D_8011275A_352FBA_name_50].flags |= 2;
    MBMotionSet(OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50), 0, 2);
    func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->obj->model, 1);
    MBModelDispOff(OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50));
    OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->pos.x = D_80112170_3529D0_name_50.x;
    OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->pos.y = D_80112170_3529D0_name_50.y;
    OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->pos.z = D_80112170_3529D0_name_50.z;
    OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50)->rot = rot;
}

/* Board 4's scene, part 6: D_8011275C spins away into the distance (0x330); back at the sign it
   shrinks to a puff (0x331); a figure (0x800D5) drops in, the sign is struck (0xA0204 fades out),
   a light (0x8B) grows over the winner while two more figures fall and rise again (0x332-0x334);
   a ship (0xA0203, func_8010CF08) descends, carries D_8011275C off and bursts into a star sprite
   (0xA010C). Then the other players' models are made for the shared winner scene. */
#ifdef NON_MATCHING /* register allocation: retail keeps the 10.0f/0.0f/360.0f constants of the first loop in s5/s3/s2 and the scales in other FPRs; the scale-down loop passes a copy of the scale as x */
void func_8010B230_34BA90_name_50(void) {
    MBModel* fig[3];
    Vec v;
    Vec dir;
    Vec2f pos2d;
    MBModel* winner;
    MBModel* sign;
    MBModel* glow;
    MBModel* light;
    MBModel* ship;
    omObjData* shipObj;
    s32 win;
    s16 anim;
    s16 spr;
    s32 i;
    s32 j;
    f32 scale;
    f32 r;
    f32 x;
    f32 angle;
    f32 vel;

    func_80050E00_51A00(0x24);
    i = 0;
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80112600_352E60_name_50->work[0] = 0;
    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    D_8011275C_352FBC_name_50->pos.x = 0.0f;
    D_8011275C_352FBC_name_50->pos.y = -100.0f;
    D_8011275C_352FBC_name_50->pos.z = 3500.0f;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &D_8011275C_352FBC_name_50->rot);
    MBMotionSet(D_8011275C_352FBC_name_50, 2, 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x330);
    win = func_8005AAC0_5B6C0((320 - D_80112752_352FB2_name_50[0]) / 2, 35, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x330, -1, -1);
    PlaySound(0x3F9);
    PlaySound(0x124);
    scale = 1.0f;
    do {
        D_8011275C_352FBC_name_50->obj->rot.z -= 10.0f;
        if (D_8011275C_352FBC_name_50->obj->rot.z < 0.0f) {
            D_8011275C_352FBC_name_50->obj->rot.z += 360.0f;
        }
        scale -= 0.02;
        r = scale * 100.0f;
        x = HuMathSin(D_8011275C_352FBC_name_50->obj->rot.z) * r;
        D_8011275C_352FBC_name_50->pos.x = x;
        D_8011275C_352FBC_name_50->pos.y = -func_800B7890_B8490(D_8011275C_352FBC_name_50->obj->rot.z) * r;
        D_8011275C_352FBC_name_50->pos.z = 3500.0f;
        D_8011275C_352FBC_name_50->scale.x = D_8011275C_352FBC_name_50->scale.y = D_8011275C_352FBC_name_50->scale.z = scale;
        HuPrcVSleep();
        i++;
    } while (i < 40);
    D_8011275C_352FBC_name_50->obj->rot.z = 0.0f;
    D_8011275C_352FBC_name_50->scale.x = D_8011275C_352FBC_name_50->scale.y = D_8011275C_352FBC_name_50->scale.z = 1.0f;
    MBModelDispOff(D_8011275C_352FBC_name_50);
    scale = 1.0f;
    MBDBackKill();
    func_8008CCA8_8D8A8(win);
    func_80050E00_51A00(0x21);
    func_8005321C_53E1C(80.0f, 20000.0f);
    D_80112600_352E60_name_50->work[0] = 1;
    sign = MBModelFileCreate(0xA0204, 0, 1.5f, 0.0f, NULL);
    HmfModelObjAttrSet(*sign->obj->model, 0x22000, 0x20000);
    func_80029A8C_2A68C(*sign->obj->model);
    func_8002A00C_2AC0C(*sign->obj->model);
    sign->pos.x = D_8011208C_3528EC_name_50.x;
    sign->pos.y = D_8011208C_3528EC_name_50.y;
    sign->pos.z = D_8011208C_3528EC_name_50.z;
    D_8011275C_352FBC_name_50->pos.x = D_801120C8_352928_name_50[0].x;
    D_8011275C_352FBC_name_50->pos.y = D_801120C8_352928_name_50[0].y;
    D_8011275C_352FBC_name_50->pos.z = D_801120C8_352928_name_50[0].z;
    func_80056658_57258(&D_8011275C_352FBC_name_50->pos, &D_80112134_352994_name_50, &D_8011275C_352FBC_name_50->rot);
    MBMotionSet(D_8011275C_352FBC_name_50, 3, 0);
    func_80029C74_2A874(*D_8011275C_352FBC_name_50->obj->model, func_80029D0C_2A90C(*D_8011275C_352FBC_name_50->obj->model));
    MBModelDispOn(D_8011275C_352FBC_name_50);
    MBModelDispOn(winner);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x331);
    win = func_8005AAC0_5B6C0((320 - D_80112752_352FB2_name_50[0]) / 2, 35, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x331, -1, -1);
    PlaySound(0x3FA);
    angle = func_80042BE0_437E0(&D_8011275C_352FBC_name_50->rot);
    while (1) {
        D_8011275C_352FBC_name_50->rot.x = HuMathSin(angle);
        D_8011275C_352FBC_name_50->rot.y = 0.0f;
        D_8011275C_352FBC_name_50->rot.z = func_800B7890_B8490(angle);
        angle += 20.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        scale -= 0.025;
        D_8011275C_352FBC_name_50->scale.x = D_8011275C_352FBC_name_50->scale.y = D_8011275C_352FBC_name_50->scale.z = scale;
        if (scale <= 0.2f) {
            break;
        }
        HuPrcVSleep();
    }
    v.x = D_8011275C_352FBC_name_50->pos.x;
    v.y = D_8011275C_352FBC_name_50->pos.y;
    v.z = D_8011275C_352FBC_name_50->pos.z;
    func_8010CD24_34D584_name_50(&v, 0.4f, 20.0f);
    MBModelDispOff(D_8011275C_352FBC_name_50);
    func_8008CCA8_8D8A8(win);
    HuPrcSleep(60);
    fig[0] = MBModelFileCreate(0x800D5, 13, 1.0f, 1.0f, D_8011207C_3528DC_name_50);
    MBMotionSet(fig[0], 0, 2);
    func_8002D1EC_2DDEC(*fig[0]->obj->model, 1);
    fig[0]->pos.x = D_8011217C_3529DC_name_50.x;
    fig[0]->pos.y = 0.0f;
    fig[0]->pos.z = D_8011217C_3529DC_name_50.z;
    fig[0]->jumpY = D_8011217C_3529DC_name_50.y;
    func_8010D320_34DB80_name_50(D_80112600_352E60_name_50);
    vel = 3.0f;
    v.x = D_8011208C_3528EC_name_50.x - 30.0f;
    v.y = 20.0f;
    v.z = D_8011208C_3528EC_name_50.z + 20.0f;
    func_8010CD24_34D584_name_50(&v, 0.2f, 8.0f);
    v.x = D_8011208C_3528EC_name_50.x + 30.0f;
    v.y = 40.0f;
    v.z = D_8011208C_3528EC_name_50.z + 20.0f;
    func_8010CD24_34D584_name_50(&v, 0.2f, 9.0f);
    v.x = D_8011208C_3528EC_name_50.x + 5.0f;
    v.y = 10.0f;
    v.z = D_8011208C_3528EC_name_50.z + 20.0f;
    func_8010CD24_34D584_name_50(&v, 0.3f, 8.5f);
    func_80026E00_27A00(1, -68.0f, 22.0f, -96.0f);
    func_8002D274_2DE74(*winner->obj->model, 0xB8, 0xB8, 0xB8);
    func_8002D274_2DE74(*fig[0]->obj->model, 0xB8, 0xB8, 0xB8);
    i = 0;
    func_8002D2B4_2DEB4(*winner->obj->model, 61.0f, 69.0f, 75.0f);
    func_8002D2B4_2DEB4(*fig[0]->obj->model, 61.0f, 69.0f, 75.0f);
    PlaySound(0x3F5);
    do {
        func_8005A7E8_5B3E8(winner, &sign->pos, 10.0f);
        func_8002AC10_2B810(*sign->obj->model, i * 0.033333335f, i * 0.3f, 2);
        D_800CA02C_CAC2C += 24.0f;
        if (D_800CA02C_CAC2C >= 360.0f) {
            D_800CA02C_CAC2C -= 360.0f;
        }
        fig[0]->jumpY -= vel;
        vel *= 1.2f;
        if (fig[0]->jumpY < 0.0f) {
            fig[0]->jumpY = 0.0f;
        }
        i++;
        HuPrcVSleep();
    } while (i < 30);
    MBModelKill(sign);
    MBMotionShiftSet(fig[0], -1, 0, 4, 2);
    HuPrcSleep(20);
    while (func_8005A7E8_5B3E8(fig[0], &winner->pos, 8.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(fig[0], 1, 0, 4, 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x332);
    win = func_8005AAC0_5B6C0(60, 60, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x332, -1, -1);
    PlaySound(0xE3);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win);
    MBMotionShiftSet(fig[0], -1, 0, 4, 2);
    glow = MBModelFileCreate(13, 0, 1.0f, 0.0f, NULL);
    glow->pos.x = D_8011217C_3529DC_name_50.x;
    glow->pos.y = 0.0f;
    glow->pos.z = D_8011217C_3529DC_name_50.z;
    glow->scale.x = glow->scale.z = 0.0f;
    func_80056658_57258(&glow->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &glow->rot);
    MBMotionShiftSet(fig[0], 2, 0, 4, 0);
    MBMotionShiftSet(winner, 9, 0, 4, 4);
    PlaySound(0x3FF);
    i = 0;
    do {
        glow->scale.x = glow->scale.z = i * 0.5f;
        func_8002D274_2DE74(*winner->obj->model, 184.0f - i * 6.133333f, 184.0f - i * 6.133333f, 184.0f - i * 6.133333f);
        func_8002D274_2DE74(*fig[0]->obj->model, 184.0f - i * 6.133333f, 184.0f - i * 6.133333f, 184.0f - i * 6.133333f);
        i++;
        HuPrcVSleep();
    } while (i < 30);
    light = func_80043510_44110(0x8B, NULL);
    light->pos.x = D_8011217C_3529DC_name_50.x;
    light->pos.y = 0.0f;
    light->pos.z = D_8011217C_3529DC_name_50.z;
    func_80056658_57258(&light->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &light->rot);
    i = 1;
    do {
        fig[i] = MBModelFileCreate(0x800D5, 13, 1.0f, 1.0f, D_8011207C_3528DC_name_50);
        MBMotionSet(fig[i], -1, 2);
        func_8002D1EC_2DDEC(*fig[i]->obj->model, 1);
        func_8002D274_2DE74(*fig[i]->obj->model, 0x3C, 0x3C, 0xFF);
        func_8002D2B4_2DEB4(*fig[i]->obj->model, 69.0f, 69.0f, 69.0f);
        fig[i]->pos.x = D_80112188_3529E8_name_50[i - 1].x;
        fig[i]->pos.y = 0.0f;
        fig[i]->pos.z = D_80112188_3529E8_name_50[i - 1].z;
        func_80056658_57258(&fig[i]->pos, &winner->pos, &fig[i]->rot);
        fig[i]->jumpY = 720.0f;
        i++;
    } while (i < 3);
    func_8002D274_2DE74(*fig[0]->obj->model, 0x3C, 0x3C, 0xFF);
    func_8002D274_2DE74(*winner->obj->model, 0x3C, 0x3C, 0xFF);
    func_8002D2B4_2DEB4(*fig[0]->obj->model, 69.0f, 69.0f, 69.0f);
    i = 2;
    func_8002D2B4_2DEB4(*winner->obj->model, -110.0f, 47.0f, -6.0f);
    PlaySound(0x3EB);
    D_80112604_352E64_name_50 = PlaySound(0x3F4);
    do {
        light->scale.x = i / 30.0f;
        light->scale.y = 4.0f;
        light->scale.z = i / 30.0f;
        HuPrcVSleep();
        i += 3;
    } while (i < 90);
    MBMotionShiftSet(fig[0], -1, 0, 10, 2);
    MBMotionShiftSet(winner, 0, 0, 10, 2);
    light->scale.x = light->scale.z = 3.0f;
    i = 0;
    do {
        for (j = 1; j < 3; j++) {
            fig[j]->jumpY -= 24.0f;
            if (fig[j]->jumpY < 0.0f) {
                fig[j]->jumpY = 0.0f;
            }
        }
        i++;
        HuPrcVSleep();
    } while (i < 30);
    i = 1;
    do {
        fig[i]->scale.x = fig[i]->scale.z = 1.0f;
        i++;
    } while (i < 3);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x333);
    win = func_8005AAC0_5B6C0(80, 60, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x333, -1, -1);
    PlaySound(0x3FB);
    PlaySound(0x3FC);
    HuPrcSleep(10);
    MBMotionShiftSet(fig[1], 1, 0, 2, 0);
    MBMotionShiftSet(fig[2], 1, 0, 2, 0);
    HuPrcSleep(20);
    MBMotionShiftSet(fig[1], -1, 0, 4, 2);
    MBMotionShiftSet(fig[2], -1, 0, 4, 2);
    HuPrcSleep(30);
    func_8008CCA8_8D8A8(win);
    HuPrcSleep(20);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, 0x334);
    win = func_8005AAC0_5B6C0(120, 100, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_800890CC_89CCC(win, 0x334, -1, -1);
    PlaySound(0x3FD);
    HuPrcSleep(35);
    func_8008CCA8_8D8A8(win);
    PlaySound(0x401);
    MBMotionShiftSet(winner, 9, 0, 4, 4);
    i = 0;
    do {
        for (j = 0; j < 3; j++) {
            fig[j]->jumpY += 24.0f;
            if (fig[j]->jumpY > 720.0f) {
                fig[j]->jumpY = 720.0f;
            }
        }
        i++;
        HuPrcVSleep();
    } while (i < 30);
    i = 90;
    do {
        light->scale.x = i / 30.0f;
        light->scale.y = 4.0f;
        light->scale.z = i / 30.0f;
        HuPrcVSleep();
        i -= 3;
    } while (i >= 3);
    light->scale.x = light->scale.z = 0.0f;
    func_8002D274_2DE74(*winner->obj->model, 0, 0, 0);
    i = 0;
    do {
        MBModelKill(fig[i]);
        i++;
    } while (i < 3);
    MBModelKill(light);
    i = 0;
    func_8002D2B4_2DEB4(*winner->obj->model, 61.0f, 69.0f, 75.0f);
    do {
        glow->scale.x = glow->scale.z = 15.0f - i * 0.5f;
        func_8002D274_2DE74(*winner->obj->model, i * 6.133333f, i * 6.133333f, i * 6.133333f);
        i++;
        HuPrcVSleep();
    } while (i < 30);
    func_8002D274_2DE74(*winner->obj->model, 0xB8, 0xB8, 0xB8);
    MBModelKill(glow);
    ship = MBModelFileCreate(0xA0203, 0, 1.0f, 0.0f, NULL);
    ship->pos.x = 0.0f;
    ship->pos.y = 0.0f;
    ship->pos.z = -5200.0f;
    ship->obj->rot.x = -90.0f;
    shipObj = omAddObj(0x1F4, 0, 0, -1, func_8010CF08_34D768_name_50);
    shipObj->rot.z = 0.0f;
    shipObj->work[0] = 0;
    shipObj->unk_50 = ship;
    MBModelDispOff(winner);
    i = 0;
    MBDBackKill();
    func_80050E00_51A00(0x40);
    func_8005321C_53E1C(80.0f, 20000.0f);
    func_800517F8_523F8();
    func_8002CA48_2D648(0x32, 0x43, 0x95);
    do {
        ship->pos.y -= 4.0f;
        HuPrcVSleep();
        i++;
    } while (i < 45);
    MBModelDispOff(ship);
    MBDBackKill();
    func_80050E00_51A00(0x21);
    func_8005321C_53E1C(80.0f, 20000.0f);
    MBModelDispOn(winner);
    ship->pos.x = D_8011217C_3529DC_name_50.x;
    ship->pos.y = 1500.0f;
    ship->pos.z = D_8011217C_3529DC_name_50.z;
    ship->obj->rot.x = 0.0f;
    ship->obj->rot.z = 0.0f;
    shipObj->work[0] = 1;
    MBModelDispOn(ship);
    func_80026E00_27A00(1, 0.0f, 0.0f, 120.0f);
    D_8011217C_3529DC_name_50.y = 0.0f;
    func_80056658_57258(&winner->pos, &D_8011217C_3529DC_name_50, &winner->rot);
    MBMotionShiftSet(winner, 1, 0, 4, 2);
    while (func_8005A5E8_5B1E8(winner, &D_8011217C_3529DC_name_50, 20.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(winner, 0, 0, 4, 2);
    func_80056658_57258(&D_8011217C_3529DC_name_50, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &dir);
    dir.x = -dir.x;
    dir.y = -dir.y;
    dir.z = -dir.z;
    winner->rot.x = dir.x;
    winner->rot.y = dir.y;
    winner->rot.z = dir.z;
    func_800794A8_7A0A8(180);
    i = 0;
    do {
        ship->pos.x += dir.x * 200.0f;
        ship->pos.z += dir.z * 200.0f;
        ship->pos.y += 5.0f;
        HuPrcVSleep();
        i++;
    } while (i < 60);
    i = 0;
    do {
        ship->scale.x = ship->scale.y = ship->scale.z = 1.0f - i * 0.033333335f;
        HuPrcVSleep();
        i++;
    } while (i < 30);
    i = 0;
    MBModelKill(D_8011275C_352FBC_name_50);
    HuPrcSleep(7);
    PlaySound(0x3C9);
    anim = func_8001A2F8_1AEF8(0xA010C);
    spr = func_8001AAAC_1B6AC(anim, 0, 1);
    func_800209C4_215C4(0, &ship->pos, &pos2d);
    espPosSet(spr, pos2d.unk_00, pos2d.unk_04);
    MBModelKill(ship);
    omDelObj(shipObj);
    scale = 0.0f;
    func_8001A96C_1B56C(spr, 0xFF, 0xFF, 0xFF);
    do {
        scale += 0.18333334f;
        func_8001A91C_1B51C(spr, scale, scale);
        i++;
        HuPrcVSleep();
    } while (i < 6);
    i = 0;
    do {
        scale -= 0.18333334f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        func_8001A91C_1B51C(spr, scale, scale);
        i++;
        HuPrcVSleep();
    } while (i < 6);
    func_8001AC44_1B844(spr);
    SprAnimKill(anim);
    HuPrcSleep(3);
    i = 0;
    MBDBackKill();
    do {
        if (i != D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80112008_352868_name_50[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
            func_80043DAC_449AC(OVL50_PLAYER_MODEL(i));
            gPlayers[i].flags |= 2;
            MBMotionSet(OVL50_PLAYER_MODEL(i), 0, 2);
            func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(i)->obj->model, 1);
            func_8002D2B4_2DEB4(*OVL50_PLAYER_MODEL(i)->obj->model, 0.0f, 0.0f, 120.0f);
            func_8002D274_2DE74(*OVL50_PLAYER_MODEL(i)->obj->model, 0xFF, 0xFF, 0xFF);
            MBModelDispOff(OVL50_PLAYER_MODEL(i));
        }
        i++;
    } while (i < 4);
    func_80050E00_51A00(0x22);
    func_8005321C_53E1C(80.0f, 8000.0f);
    v.x = v.y = 0.0f;
    v.z = 2500.0f;
    winner->pos.x = D_80111AE4_352344_name_50.x;
    winner->pos.y = D_80111AE4_352344_name_50.y;
    winner->pos.z = D_80111AE4_352344_name_50.z;
    func_80056658_57258(&winner->pos, &v, &winner->rot);
    D_80112748_352FA8_name_50->jumpY = 0.0f;
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
    func_80029A8C_2A68C(*winner->obj->model);
    func_80029A8C_2A68C(*D_80112748_352FA8_name_50->obj->model);
    func_80029A8C_2A68C(*D_8011274C_352FAC_name_50->obj->model);
    func_8002D2B4_2DEB4(*winner->obj->model, 0.0f, 0.0f, 120.0f);
    func_8002D2B4_2DEB4(*D_80112748_352FA8_name_50->obj->model, 0.0f, 0.0f, 120.0f);
    func_8002D2B4_2DEB4(*D_8011274C_352FAC_name_50->obj->model, 0.0f, 0.0f, 120.0f);
    func_8002D274_2DE74(*winner->obj->model, 0x40, 0x40, 0x40);
    func_8002D274_2DE74(*D_80112748_352FA8_name_50->obj->model, 0x40, 0x40, 0x40);
    func_8002D274_2DE74(*D_8011274C_352FAC_name_50->obj->model, 0x40, 0x40, 0x40);
    func_80026E00_27A00(1, -39.0f, 108.0f, 32.0f);
    PlayMusic(0x10);
    D_80111960_3521C0_name_50 = 0x10;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010B230_34BA90_name_50);
#endif

/* A fading, growing puff at pos (4F's func_801063AC without the kill flag). */
omObjData* func_8010CD24_34D584_name_50(Vec* pos, f32 grow, f32 fade) {
    omObjData* obj;
    Ovl50PuffWork* work;
    MBModel* model;

    obj = omAddObj(500, 0, 0, -1, func_8010CE28_34D688_name_50);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Ovl50PuffWork), 0x7918);
    work->alpha = 255.0f;
    work->grow = grow;
    work->fade = fade;
    model = MBModelFileCreate(0xA015C, 0, 1.0f, 0.0f, NULL);
    model->pos.x = pos->x;
    model->pos.y = pos->y;
    model->pos.z = pos->z;
    func_8002D124_2DD24(*model->obj->model);
    func_8002D0A0_2DCA0(*model->obj->model, 255);
    work->model = model;
    return obj;
}

/* The puff's object: kills itself once faded out. */
void func_8010CE28_34D688_name_50(omObjData* obj) {
    Ovl50PuffWork* work;
    MBModel* model;
    f32 scale;

    work = obj->unk_50;
    model = work->model;
    scale = model->scale.z + work->grow;
    model->scale.z = scale;
    model->scale.y = scale;
    model->scale.x = scale;
    work->alpha = work->alpha - work->fade;
    if (work->alpha < 0.0f) {
        work->alpha = 0.0f;
        MBModelKill(work->model);
        omDelObj(obj);
    } else {
        func_8002D0A0_2DCA0(*model->obj->model, work->alpha);
    }
}

/* The ship's object (func_8010B230): while work[0] is 1 it sways (its model's rot is a
   direction: sin, 0, cos of obj->rot.y), else its model spins about z. */
void func_8010CF08_34D768_name_50(omObjData* obj) {
    MBModel* model = obj->unk_50;

    if (obj->work[0] == 1) {
        obj->rot.y += 2.0f;
        if (obj->rot.y >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        model->rot.x = HuMathSin(obj->rot.y);
        model->rot.y = 0.0f;
        model->rot.z = func_800B7890_B8490(obj->rot.y);
    } else {
        model->obj->rot.z += 1.0f;
        if (model->obj->rot.z >= 360.0f) {
            model->obj->rot.z -= 360.0f;
        }
    }
}

/* The sign's sparkle (sprite model 0x68D, texture 0xA01ED) at a point, turned to the camera;
   func_8010D198 runs it while work[0] is set. */
omObjData* func_8010CFE8_34D848_name_50(f32 x, f32 y, f32 z) {
    Vec pos;
    Vec rot;
    omObjData* obj;
    void* data;
    s16 tex;

    data = DataRead(0xA01ED);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    obj = omAddObj(0x1F4, 2, 0, -1, func_8010D198_34D9F8_name_50);
    obj->model[1] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
    D_800F86D8_F92D8[obj->model[1]].unk02 = tex;
    func_80021160_21D60(obj->model[1], 6, 0);
    obj->model[0] = D_800F86D8_F92D8[obj->model[1]].unk00;
    func_80021250_21E50(obj->model[1], 0xFF, 0xFF, 0xFA);
    func_800211E8_21DE8(obj->model[1], 200);
    omSetTra(obj, x, y, z);
    pos.x = x;
    pos.y = y;
    pos.z = z;
    func_80056658_57258(&pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &rot);
    obj->rot.y = func_80042BE0_437E0(&rot);
    obj->unk_10 = 0;
    obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->rot.z;
    obj->scale.z = 1.0f;
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
    return obj;
}

/* The sparkle: grows to full size and shrinks again while spinning, then waits 90 frames;
   hidden while work[0] is 0. work[1]: shrinking; work[2]: its sound played; unk_10: the wait. */
void func_8010D198_34D9F8_name_50(omObjData* obj) {
    if (obj->work[0] == 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        obj->work[1] = 0;
        obj->rot.z = obj->scale.x = obj->scale.y = 0.0f;
        obj->unk_10 = 0;
    } else {
        if (obj->work[2] == 0) {
            PlaySound(0x3F2);
            obj->work[2] = 1;
        }
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        if (obj->unk_10 == 0) {
            if (obj->work[1] == 0) {
                obj->scale.x = obj->scale.y = obj->scale.y + 0.2f;
                if (obj->scale.x >= 1.0f) {
                    obj->scale.x = obj->scale.y = 1.0f;
                    obj->work[1] = 1;
                }
            } else {
                obj->scale.x = obj->scale.y = obj->scale.y - 0.2f;
                if (obj->scale.x <= 0.0f) {
                    obj->scale.x = obj->scale.y = 0.0f;
                    obj->work[1] = 0;
                    obj->unk_10 = 90;
                    obj->rot.z = 0.0f;
                }
            }
            obj->rot.z += 50.0f;
            if (obj->rot.z >= 360.0f) {
                obj->rot.z -= 360.0f;
            }
        } else {
            obj->unk_10--;
        }
    }
}

void func_8010D320_34DB80_name_50(omObjData* obj) {
    func_8002308C_23C8C(obj->model[1]);
    omDelObj(obj);
}

/* Retail pads the file to 16 bytes. */
__asm__(".balign 16");
