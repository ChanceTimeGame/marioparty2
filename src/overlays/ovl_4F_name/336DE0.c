#include "ovl_4F.h"

void func_801041A0_336DE0_name_4F(void) {
    func_80104324_336F64_name_4F();
    func_80104A0C_33764C_name_4F();
    func_80104C48_337888_name_4F();
    func_80104E84_337AC4_name_4F();
    func_80104E8C_337ACC_name_4F();
    func_80105B4C_33878C_name_4F();
}

void func_801041E4_336E24_name_4F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        MBPlayerModelCreate(i, D_8010FAA8_3426E8_name_4F[gPlayers[i].character], 2);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        func_80043DAC_449AC(OVL4F_PLAYER_MODEL(i));
        gPlayers[i].flags |= 2;
        MBModelDispOff(OVL4F_PLAYER_MODEL(i));
    }
    D_80110560_3431A0_name_4F = MBModelFileCreate(0x8000E, 13, 0.8f, 0.8f, D_8010FAC0_342700_name_4F);
    func_8005AB50_5B750(D_80110560_3431A0_name_4F, 2, 8, D_8010FB04_342744_name_4F);
    func_80043DAC_449AC(D_80110560_3431A0_name_4F);
    MBModelDispOff(D_80110560_3431A0_name_4F);
}

void func_80104324_336F64_name_4F(void) {
    MBModel* models[2];
    s32 flags[2];
    MBModel* model;
    MBModel* door1;
    MBModel* door2;
    omObjData* obj;
    Ovl4FFlyWork* work;
    s32 win;
    s32 win2;
    s32 i;
    s32 n;
    s32 delay;
    s32 started;

    func_80050E00_51A00(5);
    func_8005321C_53E1C(80.0f, 8000.0f);
    model = MBModelFileCreate(0xA018C, -1, 0.75f, 0.0f, NULL);
    model->pos.x = D_8010FB78_3427B8_name_4F.x;
    model->pos.y = D_8010FB78_3427B8_name_4F.y;
    model->pos.z = D_8010FB78_3427B8_name_4F.z;
    D_80110580_3431C0_name_4F = MBModelFileCreate(0x8004C, 13, 1.0f, 3.0f, D_8010FB10_342750_name_4F);
    func_8005AB50_5B750(D_80110580_3431C0_name_4F, 2, 9, D_8010FB74_3427B4_name_4F);
    func_80043DAC_449AC(D_80110580_3431C0_name_4F);
    D_80110580_3431C0_name_4F->pos.x = D_8010FB24_342764_name_4F.x;
    D_80110580_3431C0_name_4F->pos.y = D_8010FB24_342764_name_4F.y;
    D_80110580_3431C0_name_4F->pos.z = D_8010FB24_342764_name_4F.z;
    MBMotionSet(D_80110580_3431C0_name_4F, 0, 2);
    func_80056658_57258(&D_80110580_3431C0_name_4F->pos, &D_8010FB30_342770_name_4F, &D_80110580_3431C0_name_4F->rot);
    D_80110584_3431C4_name_4F = LoadFormFile(0xA0190, 0x689);
    func_8005AA48_5B648(D_80110580_3431C0_name_4F, D_801103B0_342FF0_name_4F, D_80110584_3431C4_name_4F);
    D_80110568_3431A8_name_4F = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010FAD4_342714_name_4F);
    func_8005AB50_5B750(D_80110568_3431A8_name_4F, 2, 7, D_8010FB0C_34274C_name_4F);
    func_80043DAC_449AC(D_80110568_3431A8_name_4F);
    D_80110568_3431A8_name_4F->pos.x = D_8010FB30_342770_name_4F.x;
    D_80110568_3431A8_name_4F->pos.y = D_8010FB30_342770_name_4F.y;
    D_80110568_3431A8_name_4F->pos.z = D_8010FB30_342770_name_4F.z;
    MBMotionSet(D_80110568_3431A8_name_4F, 3, 2);
    func_80056658_57258(&D_80110568_3431A8_name_4F->pos, &D_8010FB24_342764_name_4F, &D_80110568_3431A8_name_4F->rot);
    for (i = 0; i < 2; i++) {
        models[i] = MBModelFileCreate(0xA018D, 13, 1.0f, 1.4f, NULL);
        func_80043DAC_449AC(models[i]);
        models[i]->pos.x = D_8010FB3C_34277C_name_4F[i].x;
        models[i]->pos.y = D_8010FB3C_34277C_name_4F[i].y;
        models[i]->pos.z = D_8010FB3C_34277C_name_4F[i].z;
    }
    door1 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door1);
    door1->pos.x = D_8010FB54_342794_name_4F.x;
    door1->pos.y = D_8010FB54_342794_name_4F.y;
    door1->pos.z = D_8010FB54_342794_name_4F.z;
    door1->attr |= 4;
    door2 = MBModelFileCreate(0xA018E, -1, 1.0f, 0.0f, NULL);
    func_80043DAC_449AC(door2);
    door2->pos.x = D_8010FB54_342794_name_4F.x;
    door2->pos.y = D_8010FB54_342794_name_4F.y;
    door2->pos.z = D_8010FB54_342794_name_4F.z;
    door2->attr |= 4;
    InitFadeIn(3, 16);
    HuPrcSleep(16);
    PlayMusic(0x3C);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BA);
    win = func_8005AAC0_5B6C0(0x82, 0x60, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2BA, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(25);
    model->obj->func_ptr = NULL;
    obj = omAddObj(0x1F4, 0, 0, -1, func_80105D14_338954_name_4F);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Ovl4FFlyWork), 0x7918);
    work->model = model;
    work->target = &D_8010FB78_3427B8_name_4F;
    work->speed = 6.75f;
    work->rate = 1.0f;
    work->vel = 0.0f;
    work->delay = 45;
    HuPrcSleep(65);
    func_8005762C_5822C(win);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BB);
    win = func_8005AAC0_5B6C0(0x32, 0x32, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2BB, -1, -1);
    PlaySound(0x122);
    HuPrcSleep(90);
    func_8005762C_5822C(win);
    while (func_8005A5E8_5B1E8(door1, &D_8010FB60_3427A0_name_4F, 10.0f) == 0) {
        HuPrcVSleep();
    }
    func_8005A5E8_5B1E8(door2, &D_8010FB60_3427A0_name_4F, 10.0f);
    HuPrcSleep(20);
    delay = 30;
    flags[1] = 0;
    flags[0] = 0;
    started = 0;
    func_8005AC6C_5B86C(D_80110580_3431C0_name_4F, D_8010FB6C_3427AC_name_4F);
    while (1) {
        n = 0;
        if (func_8005A7E8_5B3E8(D_80110580_3431C0_name_4F, &door1->pos, 6.0f) != 0) {
            n = 1;
            if (flags[0] == 0) {
                flags[0] = 1;
                PlaySound(0x125);
                func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BC);
                win = func_8005AAC0_5B6C0(0x38, 0x32, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
                func_800890CC_89CCC(win, 0x2BC, -1, -1);
            }
        }
        if (delay == 0) {
            if (started == 0) {
                started = 1;
                MBMotionShiftSet(D_80110568_3431A8_name_4F, 0, 0, 5, 2);
            }
            n += func_8005A7E8_5B3E8(D_80110568_3431A8_name_4F, &door1->pos, 10.0f) != 0;
        } else {
            delay--;
        }
        if (n == 2) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(18);
    func_800794A8_7A0A8(0x78);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BD);
    win2 = func_8005AAC0_5B6C0(0x7E, 0x5A, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win2, 0x2BD, -1, -1);
    PlaySound(0xE7);
    HuPrcSleep(80);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win2);
    MBDBackKill();
    MBModelKill(D_80110568_3431A8_name_4F);
    for (i = 0; i < 2; i++) {
        MBModelKill(models[i]);
    }
    MBModelDispOff(D_80110580_3431C0_name_4F);
    func_800298A4_2A4A4(D_80110584_3431C4_name_4F, 4, 4);
    MBModelKill(door1);
    MBModelKill(door2);
}

__asm__(".section .rodata");
const char D_801103B0_342FF0_name_4F[] = "item_hook";

void func_80104A0C_33764C_name_4F(void) {
    Vec v;
    MBModel* winner;
    s32 win;

    func_80050E00_51A00(7);
    func_8005321C_53E1C(80.0f, 8000.0f);
    winner = OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F);
    MBMotionSet(winner, 0, 2);
    winner->pos.x = D_8010FB90_3427D0_name_4F.x;
    winner->pos.y = D_8010FB90_3427D0_name_4F.y;
    winner->pos.z = D_8010FB90_3427D0_name_4F.z;
    D_8011058A_3431CA_name_4F = LoadFormFile(0xA0191, 0x699);
    func_8005ACD0_5B8D0(&gPlayers[D_80110564_3431A4_name_4F], 11);
    MBModelDispOn(winner);
    func_800298A4_2A4A4(D_8011058A_3431CA_name_4F, 4, 4);
    PlayMusic(0x3B);
    v.x = 0.0f;
    v.y = 105.0f;
    v.z = 0.0f;
    func_8005A950_5B550(&v, 3.0f, 1.0f, 8);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BE);
    win = func_8005AAC0_5B6C0(0x2D, 0x28, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2BE, -1, -1);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    PlaySound(0xE7);
    HuPrcSleep(6);
    PlaySound(0xE7);
    HuPrcSleep(54);
    func_8008CCA8_8D8A8(win);
    MBModelDispOff(winner);
    MBDBackKill();
}

void func_80104C48_337888_name_4F(void) {
    MBModel* models[2];
    s32 win;
    s32 i;

    func_80050E00_51A00(5);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 2; i++) {
        models[i] = MBModelFileCreate(0xA018D, 13, 1.0f, 1.4f, NULL);
        func_80043DAC_449AC(models[i]);
        models[i]->pos.x = D_8010FB3C_34277C_name_4F[i].x;
        models[i]->pos.y = D_8010FB3C_34277C_name_4F[i].y;
        models[i]->pos.z = D_8010FB3C_34277C_name_4F[i].z;
    }
    D_80110568_3431A8_name_4F = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010FAD4_342714_name_4F);
    func_8005AB50_5B750(D_80110568_3431A8_name_4F, 2, 7, D_8010FB0C_34274C_name_4F);
    func_80043DAC_449AC(D_80110568_3431A8_name_4F);
    D_80110568_3431A8_name_4F->pos.x = D_8010FB30_342770_name_4F.x;
    D_80110568_3431A8_name_4F->pos.y = D_8010FB30_342770_name_4F.y;
    D_80110568_3431A8_name_4F->pos.z = D_8010FB30_342770_name_4F.z;
    MBMotionSet(D_80110568_3431A8_name_4F, -1, 2);
    func_80056658_57258(&D_80110568_3431A8_name_4F->pos, &D_8010FB60_3427A0_name_4F, &D_80110568_3431A8_name_4F->rot);
    MBModelDispOn(D_80110580_3431C0_name_4F);
    func_800298A4_2A4A4(D_80110584_3431C4_name_4F, 4, 0);
    HuPrcSleep(13);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2BF);
    win = func_8005AAC0_5B6C0(0x78, 0x2D, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2BF, -1, -1);
    PlaySound(0x123);
    HuPrcSleep(90);
    func_8008CCA8_8D8A8(win);
    MBDBackKill();
    for (i = 0; i < 2; i++) {
        MBModelKill(models[i]);
    }
}

void func_80104E84_337AC4_name_4F(void) {
}

#ifdef NON_MATCHING
/* same code but register allocation: retail keeps winner in s8 and spills orig, fly1, fly2 and the second loop's steps */
void func_80104E8C_337ACC_name_4F(void) {
    MBModel* winner;
    MBModel* models[2];
    Vec v;
    MBModel* model;
    omObjData* obj;
    Ovl4FFlyWork* work;
    omObjData* puff1;
    omObjData* puff2;
    omObjData* fly1;
    omObjData* fly2;
    s32 win;
    s32 i;
    s32 n;
    s16 vol;
    s16 volMax;
    u16 orig;
    u16 cur;
    s32 stepV;
    s32 stepM;

    func_80050E00_51A00(5);
    func_8005321C_53E1C(80.0f, 8000.0f);
    model = MBModelFileCreate(0xA018C, -1, 0.75f, 0.0f, NULL);
    model->pos.x = D_8010FB78_3427B8_name_4F.x;
    model->pos.y = D_8010FB78_3427B8_name_4F.y;
    model->pos.z = D_8010FB78_3427B8_name_4F.z;
    winner = OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F);
    winner->pos.x = D_8010FB9C_3427DC_name_4F.x;
    winner->pos.y = D_8010FB9C_3427DC_name_4F.y;
    winner->pos.z = D_8010FB9C_3427DC_name_4F.z;
    D_80110580_3431C0_name_4F->pos.x = D_8010FBA8_3427E8_name_4F.x;
    D_80110580_3431C0_name_4F->pos.y = D_8010FBA8_3427E8_name_4F.y;
    D_80110580_3431C0_name_4F->pos.z = D_8010FBA8_3427E8_name_4F.z;
    func_80056658_57258(&winner->pos, &D_80110580_3431C0_name_4F->pos, &winner->rot);
    func_80056658_57258(&D_80110580_3431C0_name_4F->pos, &winner->pos, &D_80110580_3431C0_name_4F->rot);
    MBMotionSet(D_80110580_3431C0_name_4F, 0, 2);
    MBModelDispOn(winner);
    for (i = 0; i < 2; i++) {
        models[i] = MBModelFileCreate(0xA018D, 13, 1.0f, 1.4f, NULL);
        func_80043DAC_449AC(models[i]);
        models[i]->pos.x = D_8010FB3C_34277C_name_4F[i].x;
        models[i]->pos.y = D_8010FB3C_34277C_name_4F[i].y;
        models[i]->pos.z = D_8010FB3C_34277C_name_4F[i].z;
    }
    func_80056658_57258(&D_80110568_3431A8_name_4F->pos, &models[0]->pos, &D_80110568_3431A8_name_4F->rot);
    MBMotionShiftSet(D_80110568_3431A8_name_4F, 5, 0, 5, 2);
    v.x = 80.0f;
    v.y = 50.0f;
    v.z = 438.0f;
    func_8005A950_5B550(&v, 3.0f, 3.0f, 1);
    HuPrcSleep(25);
    func_8005A950_5B550(&v, 3.0f, 1.0f, 30);
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2C0);
    win = func_8005AAC0_5B6C0(0xB4, 0x4B, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2C0, -1, -1);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_80110564_3431A4_name_4F].character], 0);
    PlaySound(0xE7);
    HuPrcSleep(35);
    func_8005762C_5822C(win);
    HuPrcSleep(30);
    PlaySound(0x39F);
    MBMotionSet(D_80110568_3431A8_name_4F, 4, 0);
    HuPrcSleep(50);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2C4);
    win = func_8005AAC0_5B6C0(0x50, 0x2D, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2C4, -1, -1);
    PlaySound(0x125);
    func_800794A8_7A0A8(45);
    MBModelDispOff(model);
    model->obj->func_ptr = NULL;
    obj = omAddObj(0x1F4, 0, 0, -1, func_80105D14_338954_name_4F);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Ovl4FFlyWork), 0x7918);
    work->model = model;
    work->target = &D_8010FB78_3427B8_name_4F;
    work->speed = 4.5f;
    work->rate = 1.0f;
    work->vel = 0.0f;
    work->delay = 45;
    HuPrcSleep(27);
    func_8005762C_5822C(win);
    vol = volMax = 110;
    MBDBackKill();
    func_80050E00_51A00(9);
    func_8005321C_53E1C(80.0f, 8000.0f);
    i = 0;
    func_8005AD58_5B958(D_80110580_3431C0_name_4F);
    work->rate = 0.1f;
    func_8005AA48_5B648(winner, D_801103B0_342FF0_name_4F, D_8011058A_3431CA_name_4F);
    func_800298A4_2A4A4(D_8011058A_3431CA_name_4F, 4, 0);
    MBMotionShiftSet(winner, 5, 0, 5, 0);
    MBMotionShiftSet(D_80110580_3431C0_name_4F, 1, 0, 5, 0);
    func_80029FE4_2ABE4(*winner->obj->model, 0.1f);
    func_80029FE4_2ABE4(*D_80110580_3431C0_name_4F->obj->model, 0.1f);
    PlayMusic(0x3C);
    HuPrcVSleep();
    orig = func_80011308_11F08(D_800FA188_FAD88);
    cur = orig;
    for (; i < 230.0f; i++) {
        vol -= (volMax - 45) / 30;
        if (vol < 45) {
            vol = 45;
        }
        cur -= ((s16)orig - 96) / 30;
        if ((s16)cur < 96) {
            cur = 96;
        }
        func_800794F0_7A0F0(cur);
        func_8007954C_7A14C(vol);
        HuPrcVSleep();
    }
    PlaySound(0x3A0);
    v = D_8010FBB4_3427F4_name_4F;
    puff1 = func_801063AC_338FEC_name_4F(&v, 0.0050000004f, 0.425f, 0);
    v = D_8010FBC0_342800_name_4F[gPlayers[D_80110564_3431A4_name_4F].character];
    puff2 = func_801063AC_338FEC_name_4F(&v, 0.0050000004f, 0.425f, 0);
    MBModelDispOff(((Ovl4FPuffWork*)puff1->unk_50)->model);
    MBModelDispOff(((Ovl4FPuffWork*)puff2->unk_50)->model);
    v = D_8010FBB4_3427F4_name_4F;
    fly1 = func_80105F60_338BA0_name_4F(&v, D_80110580_3431C0_name_4F, 500.0f, 2.0f);
    fly1->work[0] = 0;
    v = D_8010FBC0_342800_name_4F[gPlayers[D_80110564_3431A4_name_4F].character];
    fly2 = func_80105F60_338BA0_name_4F(&v, winner,
                                        func_800B1830_B2430((D_80110580_3431C0_name_4F->pos.x - winner->pos.x) *
                                                                (D_80110580_3431C0_name_4F->pos.x - winner->pos.x) +
                                                            (D_80110580_3431C0_name_4F->pos.z - winner->pos.z) *
                                                                (D_80110580_3431C0_name_4F->pos.z - winner->pos.z)) -
                                            160.0f,
                                        2.0f);
    fly2->work[0] = 1;
    n = 0;
    stepV = (volMax - 45) / 10;
    stepM = ((s16)orig - 96) / 10;
    while (1) {
        if (MBMotionCheck(D_80110580_3431C0_name_4F) & 1) {
            if (n++ == 40) {
                func_801065C8_339208_name_4F(puff1, 0.05f, 4.25f);
                func_801065C8_339208_name_4F(puff2, 0.05f, 4.25f);
                n = 41;
                func_80106360_338FA0_name_4F(fly1, 20.0f);
                func_80106360_338FA0_name_4F(fly2, 20.0f);
                work->rate = 1.0f;
                MBDBackKill();
                func_80050E00_51A00(5);
                func_8005321C_53E1C(80.0f, 8000.0f);
            }
        }
        if (puff1->stat & 8) {
            func_801065D8_339218_name_4F(puff1);
            func_801065D8_339218_name_4F(puff2);
            break;
        }
        if (n >= 40) {
            vol += stepV;
            if (vol > volMax) {
                vol = volMax;
            }
            cur += stepM;
            if ((s16)orig < (s16)cur) {
                cur = orig;
            }
            func_800794F0_7A0F0(cur);
            func_8007954C_7A14C(vol);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    func_8005AC6C_5B86C(D_80110580_3431C0_name_4F, D_8010FB70_3427B0_name_4F);
    func_8005AD84_5B984(D_80110580_3431C0_name_4F);
    func_80029FE4_2ABE4(*D_80110568_3431A8_name_4F->obj->model, 1.0f);
    func_80029FE4_2ABE4(*winner->obj->model, 1.0f);
    func_80029FE4_2ABE4(*D_80110580_3431C0_name_4F->obj->model, 1.0f);
    MBMotionShiftSet(D_80110580_3431C0_name_4F, 2, 0, 6, 0);
    PlaySound(0x125);
    HuPrcSleep(40);
    v.x = D_80110580_3431C0_name_4F->pos.x;
    v.y = D_80110580_3431C0_name_4F->pos.y;
    v.z = D_80110580_3431C0_name_4F->pos.z + 60.0f;
    func_801063AC_338FEC_name_4F(&v, 0.13333334f, 8.5f, 1);
    v.x = D_80110580_3431C0_name_4F->pos.x - 20.0f;
    v.y = D_80110580_3431C0_name_4F->pos.y;
    v.z = D_80110580_3431C0_name_4F->pos.z + 60.0f;
    func_801063AC_338FEC_name_4F(&v, 0.14285715f, 9.107142f, 1);
    v.x = D_80110580_3431C0_name_4F->pos.x + 90.0f;
    v.y = D_80110580_3431C0_name_4F->pos.y;
    v.z = D_80110580_3431C0_name_4F->pos.z + 80.0f;
    func_801063AC_338FEC_name_4F(&v, 0.121212125f, 7.7272725f, 1);
    func_8007954C_7A14C(volMax);
    func_800794F0_7A0F0(orig);
    func_8008DACC_8E6CC(1, D_80110586_3431C6_name_4F, 0x2C1);
    win = func_8005AAC0_5B6C0(0x6E, 0x32, D_80110586_3431C6_name_4F[0], D_80110586_3431C6_name_4F[1]);
    func_800890CC_89CCC(win, 0x2C1, -1, -1);
    PlaySound(0x124);
    HuPrcSleep(46);
    func_800794A8_7A0A8(45);
    HuPrcSleep(44);
    func_8008CCA8_8D8A8(win);
    MBDBackKill();
    for (i = 0; i < 2; i++) {
        MBModelKill(models[i]);
    }
    func_8005AA98_5B698(D_80110584_3431C4_name_4F);
    func_800283DC_28FDC(D_80110584_3431C4_name_4F);
    MBModelKill(D_80110580_3431C0_name_4F);
    MBModelDispOff(winner);
    MBModelDispOff(D_80110568_3431A8_name_4F);
    func_8010636C_338FAC_name_4F(fly1);
    func_8010636C_338FAC_name_4F(fly2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80104E8C_337ACC_name_4F);
#endif

void func_80105B4C_33878C_name_4F(void) {
    Vec v;
    MBModel* winner;

    func_80050E00_51A00(7);
    func_8005321C_53E1C(80.0f, 8000.0f);
    PlayMusic(0x10);
    D_8010F750_342390_name_4F = 0x10;
    D_80110560_3431A0_name_4F = MBModelFileCreate(0x8000E, 13, 0.8f, 0.8f, D_8010FAC0_342700_name_4F);
    func_8005AB50_5B750(D_80110560_3431A0_name_4F, 2, 8, D_8010FB08_342748_name_4F);
    func_80043DAC_449AC(D_80110560_3431A0_name_4F);
    MBModelDispOff(D_80110560_3431A0_name_4F);
    winner = OVL4F_PLAYER_MODEL(D_80110564_3431A4_name_4F);
    v.x = v.y = 0.0f;
    v.z = 2500.0f;
    winner->pos.x = D_8010F8D4_342514_name_4F.x;
    winner->pos.y = D_8010F8D4_342514_name_4F.y;
    winner->pos.z = D_8010F8D4_342514_name_4F.z;
    func_80056658_57258(&winner->pos, &v, &winner->rot);
    MBModelDispOn(winner);
    HuPrcSleep(30);
    func_8005ACD0_5B8D0(&gPlayers[D_80110564_3431A4_name_4F], 0);
    MBMotionSet(winner, 6, 0);
    while (!(MBMotionCheck(winner) & 1)) {
        HuPrcVSleep();
    }
    func_8005AA98_5B698(D_8011058A_3431CA_name_4F);
    func_800283DC_28FDC(D_8011058A_3431CA_name_4F);
    MBMotionSet(winner, 0, 2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80105D14_338954_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80105F60_338BA0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80106054_338C94_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80106198_338DD8_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80106360_338FA0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010636C_338FAC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801063AC_338FEC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801064C0_339100_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801065C8_339208_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801065D8_339218_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80106610_339250_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801066A4_3392E4_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80106840_339480_name_4F);

__asm__(".section .rodata");
const char D_801103BC_342FFC_name_4F[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801072C0_339F00_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010763C_33A27C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801078B0_33A4F0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801079D4_33A614_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80107BE8_33A828_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80107DD8_33AA18_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80107FC8_33AC08_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801084F4_33B134_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80108900_33B540_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_801089AC_33B5EC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_80108B30_33B770_name_4F);

__asm__(".section .rodata");
const u32 D_801103C8_343008_name_4F[5] = { 0x41400000, 0x41600000, 0x41700000, 0x41800000, 0x41700000 };

__asm__(".section .rodata");
const char D_801103DC_34301C_name_4F[] = "e000p15_IA44";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010A150_33CD90_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010A4A8_33D0E8_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010A6A0_33D2E0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010A8AC_33D4EC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010ADA0_33D9E0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010AED4_33DB14_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010B4E8_33E128_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010B620_33E260_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010C7CC_33F40C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010CA90_33F6D0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010CC2C_33F86C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010CDD4_33FA14_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010CE1C_33FA5C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010CFC4_33FC04_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D114_33FD54_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D15C_33FD9C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D210_33FE50_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D248_33FE88_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D3E8_340028_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D4D8_340118_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D528_340168_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010D6FC_34033C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010DA90_3406D0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010DD7C_3409BC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010DDCC_340A0C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010DFCC_340C0C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E430_341070_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E5D8_341218_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E610_341250_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E660_3412A0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E70C_34134C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010E950_341590_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010EF9C_341BDC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010F128_341D68_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/336DE0", func_8010F188_341DC8_name_4F);
