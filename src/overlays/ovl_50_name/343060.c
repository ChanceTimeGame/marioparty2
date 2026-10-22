#include "common.h"
#include "ovl_50.h"

void func_80102800_343060_name_50(void) {
    omInitObjMan(30, 0x14);
    func_80079128_79D28();
    func_80111690_351EF0_name_50();
    D_801125B8_352E18_name_50 = NULL;
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    func_80088640_89240();
    omAddPrcObj(func_80102974_3431D4_name_50, 0x5000, 0x2000, 0);
    omAddObj(0x4E20, 0, 0, -1, func_801041C8_344A28_name_50);
    omAddObj(0x7530, 0, 0, -1, func_80102B2C_34338C_name_50);
    D_80112744_352FA4_name_50 = GwSystem.current_board_index;
    D_8011275A_352FBA_name_50 = D_800F8CE4_F98E4[0];
    D_80112756_352FB6_name_50 = D_800F8CE4_F98E4[3];
}

void func_80102974_3431D4_name_50(void) {
    MBModel* model;

    D_801125C0_352E20_name_50 = NULL;
    D_801125BC_352E1C_name_50 = NULL;
    D_80111964_3521C4_name_50[D_80112744_352FA4_name_50]();
    D_8011197C_3521DC_name_50[D_80112744_352FA4_name_50]();
    D_8011274C_352FAC_name_50->pos.x = D_80111B50_3523B0_name_50[0].x;
    D_8011274C_352FAC_name_50->pos.y = D_80111B50_3523B0_name_50[0].y;
    D_8011274C_352FAC_name_50->pos.z = D_80111B50_3523B0_name_50[0].z;
    func_80056658_57258(&D_8011274C_352FAC_name_50->pos, &D_80111B50_3523B0_name_50[1], &D_8011274C_352FAC_name_50->rot);
    MBModelDispOff(D_80112748_352FA8_name_50);
    model = D_80112740_352FA0_name_50 = func_80043510_44110(0x16, NULL);
    model->scale.x = model->scale.y = model->scale.z = 0.75f;
    model->pos.x = D_80111B68_3523C8_name_50[0].x;
    model->pos.y = D_80111B68_3523C8_name_50[0].y;
    model->pos.z = D_80111B68_3523C8_name_50[0].z;
    func_80056658_57258(&model->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &model->rot);
    D_80112740_352FA0_name_50->obj->rot.x = 90.0f;
    func_80102DDC_34363C_name_50();
    func_80102D04_343564_name_50();
    HuPrcSleep(15);
    func_8005A0CC_5ACCC();
    func_80102D94_3435F4_name_50();
    if (D_801125C0_352E20_name_50 != NULL) {
        func_80049F90_4AB90(D_801125C0_352E20_name_50);
        D_801125C0_352E20_name_50 = NULL;
    }
    if (D_801125BC_352E1C_name_50 != NULL) {
        omDelPrcObj(D_801125BC_352E1C_name_50);
    }
    InitFadeOut(0, 20);
    HuPrcSleep(20);
    func_80102BB4_343414_name_50();
    omOvlKill();
    while (1) {
        HuPrcVSleep();
    }
}

void func_80102B2C_34338C_name_50(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        if (D_801125B8_352E18_name_50 != NULL) {
            func_80102D94_3435F4_name_50();
        }
        func_80102BB4_343414_name_50();
        InitFadeOut(0, 1);
        if (D_80111960_3521C0_name_50 != 0x10 && !(D_800CD526_CE126 & 8)) {
            func_800794A8_7A0A8(10);
        }
        func_80015950_16550(10);
    }
}

void func_80102BB4_343414_name_50(void) {
    s32 i;

    MBDBackKill();
    func_80050AE0_516E0();
    /* kill the players' board models; board 5 only the winner's */
    if (D_80112744_352FA4_name_50 != 5) {
        for (i = 0; i < 4; i++) {
            func_8005E260_5EE60(i);
        }
    } else {
        func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    }
    func_80059400_5A000();
    func_8008CE5C_8DA5C();
    omOvlGotoEx(0x51, 0, 0x82);
}

void func_80102C40_3434A0_name_50(omObjData* obj) {
    if (obj->work[0] == 0) {
        obj->trans.x += 20.0f;
        if (obj->trans.x >= 360.0f) {
            obj->trans.x -= 360.0f;
        }
    } else {
        obj->work[0]--;
    }
    func_800598D4_5A4D4(D_801125B0_352E10_name_50[1], 1.0f, __sinf(obj->trans.x * (M_PI / 180.0)) * 0.2f + 0.9f);
}

void func_80102D04_343564_name_50(void) {
    omObjData* obj;

    D_801125B0_352E10_name_50[0] = func_8005973C_5A33C(0xA000E, 5, 0x4E, 0xCA);
    D_801125B0_352E10_name_50[1] = func_8005973C_5A33C(0xA000F, 4, 0xD8, 0xC9);
    obj = D_801125B8_352E18_name_50 = omAddObj(0x2710, 0, 0, -1, func_80102C40_3434A0_name_50);
    obj->trans.x = 0.0f;
    obj->work[0] = 60;
}

void func_80102D94_3435F4_name_50(void) {
    func_80059698_5A298(D_801125B0_352E10_name_50[0]);
    func_80059698_5A298(D_801125B0_352E10_name_50[1]);
    omDelObj(D_801125B8_352E18_name_50);
    D_801125B8_352E18_name_50 = NULL;
}

void func_80102DDC_34363C_name_50(void) {
    Vec v;
    Vec v2;
    s32 dest[4];
    s32 arrived[4];
    MBModel* winner;
    s32 win;
    s32 i;
    s32 k;
    s32 n;
    s32 r;
    s32 timer;
    s32 voiced;

    winner = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    func_8002D1EC_2DDEC(*winner->obj->model, 1);
    func_8002D1EC_2DDEC(*D_80112748_352FA8_name_50->obj->model, 1);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBMotionSet(D_80112748_352FA8_name_50, D_80111A3E_35229E_name_50[D_80112744_352FA4_name_50][2], 2);
    D_80112748_352FA8_name_50->pos.x = D_80111B38_352398_name_50[0].x;
    D_80112748_352FA8_name_50->pos.y = D_80111B38_352398_name_50[0].y;
    D_80112748_352FA8_name_50->pos.z = D_80111B38_352398_name_50[0].z;
    func_80056658_57258(&D_80112748_352FA8_name_50->pos, &D_80111B38_352398_name_50[1], &D_80112748_352FA8_name_50->rot);
    MBModelDispOn(D_80112748_352FA8_name_50);
    MBMotionShiftSet(winner, D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][2], 0, 8, 2);
    v.x = -300.0f;
    v.y = 0.0f;
    v.z = 150.0f;
    while (func_8005A5E8_5B1E8(D_80112748_352FA8_name_50, &D_80111B38_352398_name_50[1], 23.0f) == 0) {
        func_8005A7E8_5B3E8(winner, &v, 2.0f);
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &winner->pos, 8.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80112748_352FA8_name_50, D_80111A3E_35229E_name_50[D_80112744_352FA4_name_50][4], 0, 4, 0);
    func_80059520_5A120(D_80112748_352FA8_name_50, D_80111A3E_35229E_name_50[D_80112744_352FA4_name_50][0], 2);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, D_80111A84_3522E4_name_50[D_80112744_352FA4_name_50]);
    win = func_8005AAC0_5B6C0(0x6E, 0x32, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_800890CC_89CCC(win, D_80111A84_3522E4_name_50[D_80112744_352FA4_name_50], -1, -1);
    if (D_80111AB4_352314_name_50[D_80112744_352FA4_name_50] != -1) {
        PlaySound((s16)D_80111AB4_352314_name_50[D_80112744_352FA4_name_50]);
    }
    HuPrcSleep(15);
    if (D_80111AB4_352314_name_50[D_80112744_352FA4_name_50] != -1) {
        PlaySound((s16)D_80111AB4_352314_name_50[D_80112744_352FA4_name_50]);
    }
    HuPrcSleep(45);
    func_8005762C_5822C(win);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_8008DACC_8E6CC(1, D_80112752_352FB2_name_50, D_80111A9C_3522FC_name_50[D_80112744_352FA4_name_50]);
    win = func_8005AAC0_5B6C0(0x6E, 0x32, D_80112752_352FB2_name_50[0], D_80112752_352FB2_name_50[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_8011275A_352FBA_name_50].character], 0);
    func_800890CC_89CCC(win, D_80111A9C_3522FC_name_50[D_80112744_352FA4_name_50], -1, -1);
    MBModelDispOn(D_8011274C_352FAC_name_50);
    if (D_80111ACC_35232C_name_50[D_80112744_352FA4_name_50] != -1) {
        PlaySound((s16)D_80111ACC_35232C_name_50[D_80112744_352FA4_name_50]);
    }
    MBMotionShiftSet(winner, D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][4], 0, 30, 2);
    MBMotionSet(D_8011274C_352FAC_name_50, D_80111A0E_35226E_name_50[D_80112744_352FA4_name_50][2], 2);
    v.x = 300.0f;
    v.y = 0.0f;
    v.z = 150.0f;
    while (func_8005A5E8_5B1E8(D_8011274C_352FAC_name_50, &D_80111B50_3523B0_name_50[1], 6.0f) == 0) {
        func_8005A7E8_5B3E8(winner, &v, 4.0f);
        HuPrcVSleep();
    }
    v.x = winner->pos.x;
    v.y = winner->pos.y;
    v.z = winner->pos.z + 80.0f;
    while (func_8005A7E8_5B3E8(D_8011274C_352FAC_name_50, &v, 4.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_8011274C_352FAC_name_50, D_80111A0E_35226E_name_50[D_80112744_352FA4_name_50][0], 0, 5, 2);
    HuPrcSleep(60);
    func_8005762C_5822C(win);
    MBMotionShiftSet(winner, D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][0], 0, 30, 2);
    v.x = winner->pos.x;
    v.y = winner->pos.y;
    v.z = winner->pos.z + 100.0f;
    while (func_8005A7E8_5B3E8(winner, &v, 1.0f) == 0) {
        HuPrcVSleep();
    }
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_80103AA4_344304_name_50, 0x5010, 0x2000, 0));
    v.x = D_80112748_352FA8_name_50->pos.x;
    v.y = D_80112748_352FA8_name_50->pos.y;
    v.z = 2500.0f;
    v2.x = D_8011274C_352FAC_name_50->pos.x;
    v2.y = D_8011274C_352FAC_name_50->pos.y;
    v2.z = 2500.0f;
    while (1) {
        n = func_8005A7E8_5B3E8(D_80112748_352FA8_name_50, &v, 2.0f) == 1;
        n += func_8005A7E8_5B3E8(D_8011274C_352FAC_name_50, &v2, 2.0f) == 1;
        if (n == 2) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcChildWatch();
    D_80112740_352FA0_name_50->pos.x = D_80111B68_3523C8_name_50[1].x;
    D_80112740_352FA0_name_50->pos.z = D_80111B68_3523C8_name_50[1].z;
    D_80112740_352FA0_name_50->rot.x = HuMathSin(0.0f);
    D_80112740_352FA0_name_50->rot.z = func_800B7890_B8490(0.0f);
    if (D_80112744_352FA4_name_50 != 5) { /* board 5: the winner alone */
        n = 0;
        for (i = 0; i < 4; i++) {
            if (i != D_8011275A_352FBA_name_50) {
                k = n;
                if (i == D_80112756_352FB6_name_50) {
                    k = 2;
                } else {
                    n++;
                }
                dest[i] = k;
                MBModelDispOn(OVL50_PLAYER_MODEL(i));
                OVL50_PLAYER_MODEL(i)->pos.x = D_80111AF0_352350_name_50[k][0].x;
                OVL50_PLAYER_MODEL(i)->pos.y = D_80111AF0_352350_name_50[k][0].y;
                OVL50_PLAYER_MODEL(i)->pos.z = D_80111AF0_352350_name_50[k][0].z;
                func_80056658_57258(&OVL50_PLAYER_MODEL(i)->pos, &D_80111AF0_352350_name_50[k][1], &OVL50_PLAYER_MODEL(i)->rot);
                MBMotionSet(OVL50_PLAYER_MODEL(i), D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][6], 2);
                arrived[i] = 0;
            } else {
                arrived[i] = 1;
            }
        }
    }
    timer = D_80111B80_3523E0_name_50[gPlayers[D_8011275A_352FBA_name_50].character];
    voiced = 0;
    func_8005ACD0_5B8D0(&gPlayers[D_8011275A_352FBA_name_50], 12);
    MBMotionSet(OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50), D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][8], 0);
    n = 0;
    if (D_80112744_352FA4_name_50 != 5) {
        while (1) {
            for (i = 0; i < 4; i++) {
                if (arrived[i] != 1) {
                    r = func_8005A5E8_5B1E8(OVL50_PLAYER_MODEL(i), &D_80111AF0_352350_name_50[dest[i]][1], 10.0f);
                    if (r == 1) {
                        MBMotionSet(OVL50_PLAYER_MODEL(i), D_80111996_3521F6_name_50[D_80112744_352FA4_name_50][0], 2);
                        v.x = OVL50_PLAYER_MODEL(i)->pos.x;
                        v.y = OVL50_PLAYER_MODEL(i)->pos.y;
                        v.z = OVL50_PLAYER_MODEL(i)->pos.z + 500.0f;
                        func_80056658_57258(&OVL50_PLAYER_MODEL(i)->pos, &v, &OVL50_PLAYER_MODEL(i)->rot);
                        arrived[i] = r;
                        n++;
                    }
                }
            }
            if (n == 3) {
                break;
            }
            if (--timer == 0) {
                func_80079718_7A318(0x10A, gPlayers[D_8011275A_352FBA_name_50].character);
                voiced = 1;
            }
            HuPrcVSleep();
        }
    }
    while (1) {
        if (D_80112740_352FA0_name_50->pos.y > 230.0f) {
            D_80112740_352FA0_name_50->pos.y -= 4.0f;
        } else {
            D_80112740_352FA0_name_50->pos.y = 230.0f;
            break;
        }
        func_80103ED8_344738_name_50(1);
        if (--timer == 0) {
            func_80079718_7A318(0x10A, gPlayers[D_8011275A_352FBA_name_50].character);
            voiced = 1;
        }
        HuPrcVSleep();
    }
    /* wait for the winner's voice if it has not played yet */
    while (voiced == 0) {
        if (--timer == 0) {
            func_80079718_7A318(0x10A, gPlayers[D_8011275A_352FBA_name_50].character);
            voiced = 1;
        }
        HuPrcVSleep();
    }
    D_801125BC_352E1C_name_50 = omAddPrcObj(func_80103E48_3446A8_name_50, 0x5010, 0x2000, 0);
}

#ifdef NON_MATCHING
/* masked 0: angle and rise get each other's float register (f24/f26) */
void func_80103AA4_344304_name_50(void) {
    Vec2f screen;
    f32 angle;
    f32 radius;
    f32 spin;
    f32 rise;
    f32 speed;
    f32 step;
    f32 vol;
    s16 sound;
    s32 done;

    radius = 350.0f;
    spin = 0.0f;
    rise = 1.0f;
    speed = 1.0f;
    done = 0;
    D_801125C0_352E20_name_50 = func_80049ED4_4AAD4(D_80112740_352FA0_name_50, 1);
    angle = 0.0f;
    step = 5.0f;
    sound = PlaySound(0x36F);
    do {
        if (done == 0) {
            D_80112740_352FA0_name_50->pos.x = -func_800B7890_B8490(angle) * radius + D_80111B68_3523C8_name_50[1].x;
            D_80112740_352FA0_name_50->pos.y += rise * 1.304f;
            D_80112740_352FA0_name_50->pos.z = HuMathSin(angle) * radius + D_80111B68_3523C8_name_50[1].z;
            func_800209C4_215C4(0, &D_80112740_352FA0_name_50->pos, &screen);
            vol = screen.unk_00 * 0.3f + 16.0f;
            if (vol < 16.0f) {
                vol = 16.0f;
            }
            if (vol > 112.0f) {
                vol = 112.0f;
            }
            func_800798F8_7A4F8(sound, vol);
            angle += step * speed;
            if (angle <= 720.0f) {
                speed += 0.01f;
                radius -= 1.3f;
            } else if (angle < 1090.0f) {
                speed *= 0.99f;
                rise -= 0.01f;
                radius -= speed * 1.4f;
            } else {
                done = 1;
            }
        } else {
            D_80112740_352FA0_name_50->pos.x += speed;
            D_80112740_352FA0_name_50->pos.y += rise;
            if (D_80112740_352FA0_name_50->pos.x >= 20000.0f) {
                D_80112740_352FA0_name_50->pos.x = 20000.0f;
            }
            speed *= 1.15f;
            rise += 0.5f;
            step = 1.0f;
        }
        spin += 30.0f;
        if (spin >= 360.0f) {
            spin -= 360.0f;
        }
        D_80112740_352FA0_name_50->rot.x = HuMathSin(spin);
        D_80112740_352FA0_name_50->rot.z = func_800B7890_B8490(spin);
        func_80103ED8_344738_name_50(0);
        HuPrcVSleep();
    } while (!(D_80112740_352FA0_name_50->pos.y >= 500.0f));
    D_80112740_352FA0_name_50->pos.y = 500.0f;
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/343060", func_80103AA4_344304_name_50);
#endif

void func_80103E48_3446A8_name_50(void) {
    f32 angle;

    angle = 0.0f;
    while (1) {
        D_80112740_352FA0_name_50->pos.y += HuMathSin(angle);
        angle += 9.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        func_80103ED8_344738_name_50(1);
        HuPrcVSleep();
    }
}

void func_80103ED8_344738_name_50(s32 arg0) {
    MBModel* models[3];
    Vec dir;
    f32 light;
    s32 i;

    models[0] = OVL50_PLAYER_MODEL(D_8011275A_352FBA_name_50);
    models[1] = D_80112748_352FA8_name_50;
    models[2] = D_8011274C_352FAC_name_50;
    for (i = 0; i < 3; i++) {
        light = 1.0f - (func_800B1830_B2430((D_80112740_352FA0_name_50->pos.x - models[i]->pos.x) *
                                                (D_80112740_352FA0_name_50->pos.x - models[i]->pos.x) +
                                            (D_80112740_352FA0_name_50->pos.y - models[i]->pos.y) *
                                                (D_80112740_352FA0_name_50->pos.y - models[i]->pos.y) +
                                            (D_80112740_352FA0_name_50->pos.z - models[i]->pos.z) *
                                                (D_80112740_352FA0_name_50->pos.z - models[i]->pos.z)) -
                        130.9f) /
                           236.17801f;
        if (light < 0.0f) {
            light = 0.0f;
        }
        dir.x = D_80112740_352FA0_name_50->pos.x - models[i]->pos.x;
        dir.y = D_80112740_352FA0_name_50->pos.y - models[i]->pos.y;
        dir.z = D_80112740_352FA0_name_50->pos.z - models[i]->pos.z;
        MBVecNormalize(&dir);
        if (arg0 == 1) {
            light *= 2.0f;
            if (light > 1.0f) {
                light = 1.0f;
            }
        }
        func_8002D2B4_2DEB4(*models[i]->obj->model, dir.x, dir.y, dir.z);
        func_8002D274_2DE74(*models[i]->obj->model, light * 255.0f, light * 250.0f, light * 230.0f);
    }
}

void func_801041C8_344A28_name_50(omObjData* obj) {
    s32 i;

    if (_CheckFlag(D_80111B8C_3523EC_name_50[D_80112744_352FA4_name_50]) != 0) {
        if (func_8008F618_90218() == 0) {
            for (i = 0; i < 4; i++) {
                if (!(gPlayers[i].flags & 1)) {
                    if (ContBtnTrg[gPlayers[i].port] & 0x1000) {
                        D_801011FC_101DFC = 1;
                    }
                }
            }
        }
    }
}
