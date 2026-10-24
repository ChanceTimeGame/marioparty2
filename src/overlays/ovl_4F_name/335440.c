#include "ovl_4F.h"

/* .data (0x342390-0x3425E0) */
s16 D_8010F750_342390_name_4F = -1;
void (*D_8010F754_342394_name_4F[6])(void) = {
    func_801041E4_336E24_name_4F, func_801066A4_3392E4_name_4F, func_801041E4_336E24_name_4F, func_801089AC_33B5EC_name_4F,
    func_801041E4_336E24_name_4F, func_801041E4_336E24_name_4F,
};
void (*D_8010F76C_3423AC_name_4F[6])(void) = {
    func_801041A0_336DE0_name_4F, func_80106610_339250_name_4F, func_801041A0_336DE0_name_4F, func_80108900_33B540_name_4F,
    func_801041A0_336DE0_name_4F, func_801041A0_336DE0_name_4F,
};
/* per board: motions; retail reads the low half of each word (lh at +2) */
s32 D_8010F784_3423C4_name_4F[6][5] = {
    { 0, 8, 9, 2, 3 },
    { 0, 7, 8, 2, 3 },
    { 0, 8, 9, 2, 3 },
    { 0, 7, 8, 2, 3 },
    { 0, 8, 9, 2, 3 },
    { 0, 8, 9, 2, 3 },
};
s32 D_8010F7FC_34243C_name_4F[6][2] = {
    { 0, 1 },
    { 0, 1 },
    { 0, 1 },
    { 4, 1 },
    { 4, 1 },
    { 0, 1 },
};
s32 D_8010F82C_34246C_name_4F[6][3] = {
    { 0, 2, 10 },
    { 0, 2, 12 },
    { 0, 2, 10 },
    { 0, 2, 10 },
    { 0, 2, 10 },
    { 0, 2, 10 },
};
s32 D_8010F874_3424B4_name_4F[6] = {
    0x2C2, 0x2DA, 0x2C2, 0x315, 0x2C2, 0x2C2,
};
s32 D_8010F88C_3424CC_name_4F[6] = {
    0x2C3, 0x2DB, 0x2C3, 0x316, 0x2C3, 0x2C3,
};
s32 D_8010F8A4_3424E4_name_4F[6] = {
    0xE7, 0xE7, -1, 0xE7, -1, 0xE7,
};
s32 D_8010F8BC_3424FC_name_4F[6] = {
    0x11E, 0x11E, -1, 0x11E, -1, 0x11E,
};
Vec D_8010F8D4_342514_name_4F = { 0.0f, 0.0f, -250.0f };
Vec D_8010F8E0_342520_name_4F[3][2] = {
    {
        { -500.0f, 0.0f, -600.0f },
        { -100.0f, 0.0f, -600.0f },
    },
    {
        { 590.0f, 0.0f, -600.0f },
        { 110.0f, 0.0f, -600.0f },
    },
    {
        { 500.0f, 0.0f, -725.0f },
        { 65.0f, 0.0f, -725.0f },
    },
};
Vec D_8010F928_342568_name_4F[2] = {
    { -300.0f, 0.0f, 150.0f },
    { -170.0f, 0.0f, -350.0f },
};
Vec D_8010F940_342580_name_4F[2] = {
    { 350.0f, 0.0f, -350.0f },
    { 140.0f, 0.0f, -350.0f },
};
Vec D_8010F958_342598_name_4F[2] = {
    { -400.0f, 0.0f, 0.0f },
    { 0.0f, 500.0f, -350.0f },
};
u16 D_8010F970_3425B0_name_4F[6] = {
    0x3D, 0x1D, 0x27, 0x48, 0x2E, 0x22,
};
s32 D_8010F97C_3425BC_name_4F[6] = {
    5, 6, 7, 8, 9, 10,
};


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
    model->pos.x = D_8010F958_342598_name_4F[0].x;
    model->pos.y = D_8010F958_342598_name_4F[0].y;
    model->pos.z = D_8010F958_342598_name_4F[0].z;
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

void func_80102DB4_3359F4_name_4F(void) {
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

    winner = OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F);
    func_8002D1EC_2DDEC(*winner->obj->model, 1);
    func_8002D1EC_2DDEC(*D_80110568_3431A8_name_4F->obj->model, 1);
    func_8002D1EC_2DDEC(*D_80110560_3431A0_name_4F->obj->model, 1);
    MBMotionSet(D_80110568_3431A8_name_4F, D_8010F82C_34246C_name_4F[D_80110574_3431B4_name_4F][1], 2);
    D_80110568_3431A8_name_4F->pos.x = D_8010F928_342568_name_4F[0].x;
    D_80110568_3431A8_name_4F->pos.y = D_8010F928_342568_name_4F[0].y;
    D_80110568_3431A8_name_4F->pos.z = D_8010F928_342568_name_4F[0].z;
    func_80056658_57258(&D_80110568_3431A8_name_4F->pos, &D_8010F928_342568_name_4F[1], &D_80110568_3431A8_name_4F->rot);
    MBModelDispOn(D_80110568_3431A8_name_4F);
    MBMotionShiftSet(winner, D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][1], 0, 8, 2);
    v.x = -300.0f;
    v.y = 0.0f;
    v.z = 150.0f;
    while (func_8005A5E8_5B1E8(D_80110568_3431A8_name_4F, &D_8010F928_342568_name_4F[1], 23.0f) == 0) {
        func_8005A7E8_5B3E8(winner, &v, 2.0f);
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(D_80110568_3431A8_name_4F, &winner->pos, 8.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80110568_3431A8_name_4F, D_8010F82C_34246C_name_4F[D_80110574_3431B4_name_4F][2], 0, 4, 0);
    func_80059520_5A120(D_80110568_3431A8_name_4F, (s16)D_8010F82C_34246C_name_4F[D_80110574_3431B4_name_4F][0], 2);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, D_8010F874_3424B4_name_4F[D_80110574_3431B4_name_4F]);
    win = func_8005AAC0_5B6C0(0x6E, 0x32, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_800890CC_89CCC(win, D_8010F874_3424B4_name_4F[D_80110574_3431B4_name_4F], -1, -1);
    if (D_8010F8A4_3424E4_name_4F[D_80110574_3431B4_name_4F] != -1) {
        PlaySound((s16)D_8010F8A4_3424E4_name_4F[D_80110574_3431B4_name_4F]);
    }
    HuPrcSleep(44);
    HuPrcSleep(16);
    func_8005762C_5822C(win);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, D_8010F88C_3424CC_name_4F[D_80110574_3431B4_name_4F]);
    win = func_8005AAC0_5B6C0(0x6E, 0x32, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_800890CC_89CCC(win, D_8010F88C_3424CC_name_4F[D_80110574_3431B4_name_4F], -1, -1);
    MBModelDispOn(D_80110560_3431A0_name_4F);
    if (D_8010F8BC_3424FC_name_4F[D_80110574_3431B4_name_4F] != -1) {
        PlaySound((s16)D_8010F8BC_3424FC_name_4F[D_80110574_3431B4_name_4F]);
    }
    MBMotionShiftSet(winner, D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][2], 0, 30, 2);
    MBMotionSet(D_80110560_3431A0_name_4F, D_8010F7FC_34243C_name_4F[D_80110574_3431B4_name_4F][1], 2);
    v.x = 300.0f;
    v.y = 0.0f;
    v.z = 150.0f;
    while (func_8005A5E8_5B1E8(D_80110560_3431A0_name_4F, &D_8010F940_342580_name_4F[1], 6.0f) == 0) {
        func_8005A7E8_5B3E8(winner, &v, 4.0f);
        HuPrcVSleep();
    }
    v.x = winner->pos.x;
    v.y = winner->pos.y;
    v.z = winner->pos.z + 80.0f;
    while (func_8005A7E8_5B3E8(D_80110560_3431A0_name_4F, &v, 4.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80110560_3431A0_name_4F, D_8010F7FC_34243C_name_4F[D_80110574_3431B4_name_4F][0], 0, 5, 2);
    HuPrcSleep(60);
    func_8005762C_5822C(win);
    MBMotionShiftSet(winner, D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][0], 0, 30, 2);
    v.x = winner->pos.x;
    v.y = winner->pos.y;
    v.z = winner->pos.z + 100.0f;
    while (func_8005A7E8_5B3E8(winner, &v, 1.0f) == 0) {
        HuPrcVSleep();
    }
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_801039BC_3365FC_name_4F, 0x5010, 0x2000, 0));
    v.x = D_80110568_3431A8_name_4F->pos.x;
    v.y = D_80110568_3431A8_name_4F->pos.y;
    v.z = 2500.0f;
    v2.x = D_80110560_3431A0_name_4F->pos.x;
    v2.y = D_80110560_3431A0_name_4F->pos.y;
    v2.z = 2500.0f;
    while (1) {
        n = func_8005A7E8_5B3E8(D_80110568_3431A8_name_4F, &v, 2.0f) == 1;
        n += func_8005A7E8_5B3E8(D_80110560_3431A0_name_4F, &v2, 2.0f) == 1;
        if (n == 2) {
            break;
        }
        HuPrcVSleep();
    }
    n = 0;
    HuPrcChildWatch();
    D_8011056C_3431AC_name_4F->pos.x = D_8010F958_342598_name_4F[1].x;
    D_8011056C_3431AC_name_4F->pos.z = D_8010F958_342598_name_4F[1].z;
    D_8011056C_3431AC_name_4F->rot.x = HuMathSin(0.0f);
    D_8011056C_3431AC_name_4F->rot.z = func_800B7890_B8490(0.0f);
    for (i = 0; i < 4; i++) {
        if (i != D_80110564_3431A4_name_4F) {
            k = n;
            if (i == D_8011057C_3431BC_name_4F) {
                k = 2;
            } else {
                n++;
            }
            dest[i] = k;
            MBModelDispOn(OVL4F_PLAYER_MODEL(i));
            OVL4F_PLAYER_MODEL(i)->pos.x = D_8010F8E0_342520_name_4F[k][0].x;
            OVL4F_PLAYER_MODEL(i)->pos.y = D_8010F8E0_342520_name_4F[k][0].y;
            OVL4F_PLAYER_MODEL(i)->pos.z = D_8010F8E0_342520_name_4F[k][0].z;
            func_80056658_57258(&OVL4F_PLAYER_MODEL(i)->pos, &D_8010F8E0_342520_name_4F[k][1], &OVL4F_PLAYER_MODEL(i)->rot);
            MBMotionSet(OVL4F_PLAYER_MODEL(i), D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][3], 2);
            arrived[i] = 0;
        } else {
            arrived[i] = 1;
        }
    }
    timer = D_8010F970_3425B0_name_4F[gPlayers[D_80110564_3431A4_name_4F].character];
    func_8005ACD0_5B8D0(&gPlayers[D_80110564_3431A4_name_4F], 12);
    MBMotionSet(OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F), D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][4], 0);
    n = 0;
    while (1) {
        for (i = 0; i < 4; i++) {
            if (arrived[i] != 1) {
                r = func_8005A5E8_5B1E8(OVL4F_PLAYER_MODEL(i), &D_8010F8E0_342520_name_4F[dest[i]][1], 10.0f);
                if (r == 1) {
                    MBMotionSet(OVL4F_PLAYER_MODEL(i), D_8010F784_3423C4_name_4F[D_80110574_3431B4_name_4F][0], 2);
                    v.x = OVL4F_PLAYER_MODEL(i)->pos.x;
                    v.y = OVL4F_PLAYER_MODEL(i)->pos.y;
                    v.z = OVL4F_PLAYER_MODEL(i)->pos.z + 500.0f;
                    func_80056658_57258(&OVL4F_PLAYER_MODEL(i)->pos, &v, &OVL4F_PLAYER_MODEL(i)->rot);
                    arrived[i] = r;
                    n++;
                }
            }
        }
        if (--timer == 0) {
            func_80079718_7A318(0x10A, gPlayers[D_80110564_3431A4_name_4F].character);
        }
        if (n == 3) {
            break;
        }
        HuPrcVSleep();
    }
    while (1) {
        if (D_8011056C_3431AC_name_4F->pos.y > 230.0f) {
            D_8011056C_3431AC_name_4F->pos.y -= 4.0f;
        } else {
            D_8011056C_3431AC_name_4F->pos.y = 230.0f;
            break;
        }
        func_80103DF0_336A30_name_4F(1);
        if (--timer == 0) {
            func_80079718_7A318(0x10A, gPlayers[D_80110564_3431A4_name_4F].character);
        }
        HuPrcVSleep();
    }
    D_8011042C_34306C_name_4F = omAddPrcObj(func_80103D60_3369A0_name_4F, 0x5010, 0x2000, 0);
}

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
            D_8011056C_3431AC_name_4F->pos.x = -func_800B7890_B8490(angle) * radius + D_8010F958_342598_name_4F[1].x;
            D_8011056C_3431AC_name_4F->pos.y += rise * 1.304f;
            D_8011056C_3431AC_name_4F->pos.z = HuMathSin(angle) * radius + D_8010F958_342598_name_4F[1].z;
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
