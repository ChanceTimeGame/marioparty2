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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/343060", func_80102BB4_343414_name_50);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/343060", func_80102DDC_34363C_name_50);

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
