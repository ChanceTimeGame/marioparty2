#include "ovl_4F.h"

void func_80102800_335440_name_4F(void) {
    omInitObjMan(0x23, 0x14);
    func_80079128_79D28();
    func_8010D210_33FE50_name_4F();
    D_80110428_343068_name_4F = NULL;
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
    omAddPrcObj(func_80102974_3355B4_name_4F, 0x5000, 0x2000, 0);
    omAddObj(0x4E20, 0, 0, -1, func_801040E0_336D20_name_4F);
    omAddObj(0x7530, 0, 0, -1, func_80102B2C_33576C_name_4F);
    D_80110574_3431B4_name_4F = GwSystem.current_board_index;
    D_80110564_3431A4_name_4F = D_800F8CE4_F98E4[0];
    D_8011057C_3431BC_name_4F = D_800F8CE4_F98E4[3];
}

void func_80102974_3355B4_name_4F(void) {
    MBModel* model;

    D_80110430_343070_name_4F = NULL;
    D_8011042C_34306C_name_4F = NULL;
    D_8010F754_342394_name_4F[D_80110574_3431B4_name_4F]();
    D_8010F76C_3423AC_name_4F[D_80110574_3431B4_name_4F]();
    D_80110560_3431A0_name_4F->pos.x = D_8010F940_342580_name_4F[0].x;
    D_80110560_3431A0_name_4F->pos.y = D_8010F940_342580_name_4F[0].y;
    D_80110560_3431A0_name_4F->pos.z = D_8010F940_342580_name_4F[0].z;
    func_80056658_57258(&D_80110560_3431A0_name_4F->pos, &D_8010F940_342580_name_4F[1], &D_80110560_3431A0_name_4F->rot);
    MBModelDispOff(D_80110568_3431A8_name_4F);
    model = D_8011056C_3431AC_name_4F = func_80043510_44110(0x16, NULL);
    model->scale.x = model->scale.y = model->scale.z = 0.75f;
    model->pos.x = D_8010F958_342598_name_4F.x;
    model->pos.y = D_8010F958_342598_name_4F.y;
    model->pos.z = D_8010F958_342598_name_4F.z;
    func_80056658_57258(&model->pos, &((HuCamera*)D_800FD2A8_FDEA8)->pos, &model->rot);
    D_8011056C_3431AC_name_4F->obj->rot.x = 90.0f;
    func_80102DB4_3359F4_name_4F();
    func_80102CDC_33591C_name_4F();
    HuPrcSleep(15);
    func_8005A0CC_5ACCC();
    func_80102D6C_3359AC_name_4F();
    if (D_80110430_343070_name_4F != NULL) {
        func_80049F90_4AB90(D_80110430_343070_name_4F);
        D_80110430_343070_name_4F = NULL;
    }
    if (D_8011042C_34306C_name_4F != NULL) {
        omDelPrcObj(D_8011042C_34306C_name_4F);
    }
    InitFadeOut(0, 20);
    HuPrcSleep(20);
    func_80102BB4_3357F4_name_4F();
    omOvlKill();
    while (1) {
        HuPrcVSleep();
    }
}

void func_80102B2C_33576C_name_4F(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        if (D_80110428_343068_name_4F != NULL) {
            func_80102D6C_3359AC_name_4F();
        }
        func_80102BB4_3357F4_name_4F();
        InitFadeOut(0, 1);
        if (D_8010F750_342390_name_4F != 0x10 && !(D_800CD526_CE126 & 8)) {
            func_800794A8_7A0A8(10);
        }
        func_80015950_16550(10);
    }
}

void func_80102BB4_3357F4_name_4F(void) {
    s32 i;

    MBDBackKill();
    func_80050AE0_516E0();
    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    func_80059400_5A000();
    func_8008CE5C_8DA5C();
    omOvlGotoEx(0x51, 0, 0x82);
}

void func_80102C18_335858_name_4F(omObjData* obj) {
    if (obj->work[0] == 0) {
        obj->trans.x += 20.0f;
        if (obj->trans.x >= 360.0f) {
            obj->trans.x -= 360.0f;
        }
    } else {
        obj->work[0]--;
    }
    func_800598D4_5A4D4(D_80110420_343060_name_4F[1], 1.0f, __sinf(obj->trans.x * (M_PI / 180.0)) * 0.2f + 0.9f);
}

void func_80102CDC_33591C_name_4F(void) {
    omObjData* obj;

    D_80110420_343060_name_4F[0] = func_8005973C_5A33C(0xA000E, 5, 0x4E, 0xCA);
    D_80110420_343060_name_4F[1] = func_8005973C_5A33C(0xA000F, 4, 0xD8, 0xC9);
    obj = D_80110428_343068_name_4F = omAddObj(0x2710, 0, 0, -1, func_80102C18_335858_name_4F);
    obj->trans.x = 0.0f;
    obj->work[0] = 60;
}

void func_80102D6C_3359AC_name_4F(void) {
    func_80059698_5A298(D_80110420_343060_name_4F[0]);
    func_80059698_5A298(D_80110420_343060_name_4F[1]);
    omDelObj(D_80110428_343068_name_4F);
    D_80110428_343068_name_4F = NULL;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/335440", func_80102DB4_3359F4_name_4F);

#ifdef NON_MATCHING
/* masked 0: angle and rise get each other's float register (f24/f26) */
void func_801039BC_3365FC_name_4F(void) {
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
    D_80110430_343070_name_4F = func_80049ED4_4AAD4(D_8011056C_3431AC_name_4F, 1);
    angle = 0.0f;
    step = 5.0f;
    sound = PlaySound(0x36F);
    do {
        if (done == 0) {
            D_8011056C_3431AC_name_4F->pos.x = -func_800B7890_B8490(angle) * radius + D_8010F964_3425A4_name_4F.x;
            D_8011056C_3431AC_name_4F->pos.y += rise * 1.304f;
            D_8011056C_3431AC_name_4F->pos.z = HuMathSin(angle) * radius + D_8010F964_3425A4_name_4F.z;
            func_800209C4_215C4(0, &D_8011056C_3431AC_name_4F->pos, &screen);
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
            D_8011056C_3431AC_name_4F->pos.x += speed;
            D_8011056C_3431AC_name_4F->pos.y += rise;
            if (D_8011056C_3431AC_name_4F->pos.x >= 20000.0f) {
                D_8011056C_3431AC_name_4F->pos.x = 20000.0f;
            }
            speed *= 1.15f;
            rise += 0.5f;
            step = 1.0f;
        }
        spin += 30.0f;
        if (spin >= 360.0f) {
            spin -= 360.0f;
        }
        D_8011056C_3431AC_name_4F->rot.x = HuMathSin(spin);
        D_8011056C_3431AC_name_4F->rot.z = func_800B7890_B8490(spin);
        func_80103DF0_336A30_name_4F(0);
        HuPrcVSleep();
    } while (!(D_8011056C_3431AC_name_4F->pos.y >= 500.0f));
    D_8011056C_3431AC_name_4F->pos.y = 500.0f;
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/335440", func_801039BC_3365FC_name_4F);
#endif

void func_80103D60_3369A0_name_4F(void) {
    f32 angle;

    angle = 0.0f;
    while (1) {
        D_8011056C_3431AC_name_4F->pos.y += HuMathSin(angle);
        angle += 9.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        func_80103DF0_336A30_name_4F(1);
        HuPrcVSleep();
    }
}

void func_80103DF0_336A30_name_4F(s32 arg0) {
    MBModel* models[3];
    Vec dir;
    f32 light;
    s32 i;

    models[0] = OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F);
    models[1] = D_80110568_3431A8_name_4F;
    models[2] = D_80110560_3431A0_name_4F;
    for (i = 0; i < 3; i++) {
        light = 1.0f - (func_800B1830_B2430((D_8011056C_3431AC_name_4F->pos.x - models[i]->pos.x) *
                                                (D_8011056C_3431AC_name_4F->pos.x - models[i]->pos.x) +
                                            (D_8011056C_3431AC_name_4F->pos.y - models[i]->pos.y) *
                                                (D_8011056C_3431AC_name_4F->pos.y - models[i]->pos.y) +
                                            (D_8011056C_3431AC_name_4F->pos.z - models[i]->pos.z) *
                                                (D_8011056C_3431AC_name_4F->pos.z - models[i]->pos.z)) -
                        130.9f) /
                           236.17801f;
        if (light < 0.0f) {
            light = 0.0f;
        }
        dir.x = D_8011056C_3431AC_name_4F->pos.x - models[i]->pos.x;
        dir.y = D_8011056C_3431AC_name_4F->pos.y - models[i]->pos.y;
        dir.z = D_8011056C_3431AC_name_4F->pos.z - models[i]->pos.z;
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

void func_801040E0_336D20_name_4F(omObjData* obj) {
    s32 i;

    if (_CheckFlag(D_8010F97C_3425BC_name_4F[D_80110574_3431B4_name_4F]) != 0) {
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
