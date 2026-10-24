#include "ovl_55.h"

/* .data (0x36AA90-0x36ABE0) */
/* board 0, per character: MBPlayerModelCreate lists */
u32 D_8010BBA0_36AA90_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010BBC4_36AAB4_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010BBE8_36AAD8_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010BC0C_36AAFC_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010BC30_36AB20_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010BC54_36AB44_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010BC78_36AB68_name_55[6] = {
    D_8010BBA0_36AA90_name_55, D_8010BBC4_36AAB4_name_55, D_8010BBE8_36AAD8_name_55, D_8010BC0C_36AAFC_name_55,
    D_8010BC30_36AB20_name_55, D_8010BC54_36AB44_name_55,
};
u32 D_8010BC90_36AB80_name_55[4] = {
    3, 0x80014, 0x80010, 0x80011,
};
Vec D_8010BCA0_36AB90_name_55[2] = {
    { -80.0f, 0.0f, -205.0f },
    { 214.0f, 0.0f, 161.0f },
};
u32 D_8010BCB8_36ABA8_name_55[2] = {
    1, 0x80092,
};
Ovl55Path D_8010BCC0_36ABB0_name_55[2] = {
    { { 500.0f, 0.0f, 1700.0f }, { -500.0f, 0.0f, 1700.0f } },
    { { 625.0f, 0.0f, 1765.0f }, { -500.0f, 0.0f, 1765.0f } },
};

/* Board 0: the player and host models. */
void func_80105690_364580_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010BC78_36AB68_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x8000E, 13, 0.8f, 0.8f, D_8010BC90_36AB80_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x8000E, 13, 0.8f, 0.8f, D_8010BC90_36AB80_name_55);
    func_8005AB50_5B750(D_8010C56C_36B45C_name_55, 2, 8, 0x80039);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 0: a player's board model. */
void func_801057E0_3646D0_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010BC78_36AB68_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 0: the title sprite stretches in, then START may skip. */
void func_80105870_364760_name_55(void) {
    f32 scale;
    s32 i;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA0196), 0, 1);
    func_8001A788_1B388(D_8010C588_36B478_name_55, 0x2000);
    espPosSet(D_8010C588_36B478_name_55, 160, 64);
    func_8001A91C_1B51C(D_8010C588_36B478_name_55, 0.0f, 1.0f);
    func_8008F624_90224(255, 255, 255);
    InitFadeIn(0, 16);
    HuPrcSleep(16);
    scale = 0.0f;
    PlayMusic(0x59);
    for (i = 0; i < 15; i++) {
        if (i == 3) {
            D_8010B762_36A652_name_55 = 1;
        }
        func_8001A91C_1B51C(D_8010C588_36B478_name_55, scale, 1.0f);
        scale += 1.0f / 15.0f;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            return;
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_8010C588_36B478_name_55, 1.0f, 1.0f);
}

/* Board 0: two models and a third walk along z = -162 while the camera pans. */
void func_801059D0_3648C0_name_55(void) {
    Vec target;
    MBModel* a;
    MBModel* b;
    MBModel* c;
    f32 x;
    f32 z;
    f32 cx;
    f32 cy;
    f32 cz;
    s32 i;
    s32 n;

    func_80029708_2A308(0);
    func_80050E00_51A00(2);
    HuPrcSleep(3);
    MBDCameraPos3DSet(&D_8010BCA0_36AB90_name_55[0]);
    a = func_80043510_44110(0x74, NULL);
    func_80043DAC_449AC(a);
    b = func_80043510_44110(0x75, NULL);
    func_80043DAC_449AC(b);
    x = -98.0f;
    z = -162.0f;
    a->pos.x = x;
    a->pos.y = 0.0f;
    a->pos.z = z;
    target.x = x + 100.0f;
    target.y = 0.0f;
    target.z = z;
    func_80056658_57258(&a->pos, &target, &a->rot);
    b->pos.x = x + -23.0f;
    b->pos.y = 0.0f;
    b->pos.z = z;
    func_80056658_57258(&b->pos, &target, &a->rot);
    c = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010BCB8_36ABA8_name_55);
    MBMotionSet(c, 0, 2);
    cx = b->pos.x;
    cy = b->pos.y + 10.0f;
    cz = b->pos.z;
    c->pos.x = cx;
    c->pos.y = cy;
    c->pos.z = cz;
    target.x = cx + 100.0f;
    target.y = 0.0f;
    target.z = cz;
    func_80056658_57258(&c->pos, &target, &c->rot);
    InitFadeIn(0, 16);
    for (i = 0; i < 46; i++) {
        x += 1.5f;
        cx += 1.5f;
        a->pos.x = x;
        a->pos.y = 0.0f;
        a->pos.z = z;
        b->pos.x = x + -23.0f;
        b->pos.y = 0.0f;
        b->pos.z = z;
        c->pos.x = cx;
        c->pos.y = cy;
        c->pos.z = cz;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            break;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        n = func_80059E7C_5AA7C(&D_8010BCA0_36AB90_name_55[0], &D_8010BCA0_36AB90_name_55[1], 3.0f) + 20;
        for (i = 0; i < n; i++) {
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            x += 1.5f;
            cx += 1.5f;
            a->pos.x = x;
            a->pos.y = 0.0f;
            a->pos.z = z;
            b->pos.x = x + -23.0f;
            b->pos.y = 0.0f;
            b->pos.z = z;
            c->pos.x = cx;
            c->pos.y = cy;
            c->pos.z = cz;
            HuPrcVSleep();
        }
    }
    MBModelKill(a);
    MBModelKill(b);
    MBModelKill(c);
}

/* Board 0: the sign drops in and wobbles. */
void func_80105CE0_364BD0_name_55(void) {
    Ovl55Sign* sign;
    f32 vel;
    f32 amp;
    f32 ca;
    f32 sa;
    f32 sx;
    f32 sy;
    s32 i;
    s32 j;

    sign = (Ovl55Sign*)(D_8010C570_36B460_name_55 = HuMemMemoryAllocPerm(sizeof(Ovl55Sign)));
    sign->grp = func_8001A2F8_1AEF8(0xA019A);
    sign->grp2 = func_8001A2F8_1AEF8(0xA019B);
    sign->spr = func_8001AAAC_1B6AC(sign->grp, 0, 1);
    sign->spr2 = func_8001AAAC_1B6AC(sign->grp2, 0, 1);
    func_8001A708_1B308(sign->spr, 0x4000);
    func_8001A788_1B388(sign->spr, 0x2000);
    func_8001A708_1B308(sign->spr2, 0x4000);
    func_8001A788_1B388(sign->spr2, 0x1000);
    sign->x = 160;
    sign->y = -80;
    espPosSet(sign->spr, sign->x, -80);
    espDispOff(sign->spr2);
    vel = 2.0f;
    while (TRUE) {
        sign->y = sign->y + vel;
        if (sign->y >= 175) {
            sign->y = 175;
        }
        vel *= 1.1f;
        espPosSet(sign->spr, sign->x, sign->y);
        if (sign->y >= 175) {
            break;
        }
        HuPrcVSleep();
    }
    PlaySound(0x396);
    sign->x2 = 160;
    sign->y2 = 168;
    espPosSet(sign->spr2, sign->x2, 168);
    espDispOn(sign->spr2);
    for (i = 0; i < 4; i++) {
        func_8005A4EC_5B0EC(i, 2);
    }
    amp = 0.6f;
    ca = 270.0f;
    sa = 180.0f;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            sx = func_800B7890_B8490(ca) * amp + 1.0f;
            sy = HuMathSin(sa) * amp + 1.0f;
            ca += 45.0f;
            sa += 45.0f;
            if (ca >= 360.0f) {
                ca -= 360.0f;
            }
            if (sa >= 360.0f) {
                sa -= 360.0f;
            }
            func_8001A91C_1B51C(sign->spr, sx, sy);
            HuPrcVSleep();
        }
        amp -= 0.15f;
    }
    func_8001A91C_1B51C(sign->spr, 1.0f, 1.0f);
    HuPrcSleep(30);
}

/* Board 0: two models fly to their places and the sign spins away to the left. */
void func_80105FC4_364EB4_name_55(void) {
    Ovl55FlyWork* work[2];
    omObjData* objs[2];
    MBModel* models[2];
    Ovl55Sign* sign;
    omObjData* mobj;
    HuSprite_Unk84_Unk00_Struct* spr;
    u16 h;
    f32 baseY;
    f32 angle;
    s32 i;

    sign = (Ovl55Sign*)D_8010C570_36B460_name_55;
    PlaySound(0x397);
    for (i = 0; i < 2; i++) {
        models[i] = MBModelFileCreate(0xA018C, -1, 0.5f, 0.0f, NULL);
        models[i]->pos.x = D_8010BCC0_36ABB0_name_55[i].start.x;
        models[i]->pos.y = D_8010BCC0_36ABB0_name_55[i].start.y;
        models[i]->pos.z = D_8010BCC0_36ABB0_name_55[i].start.z;
        mobj = models[i]->obj;
        mobj->trans.x = models[i]->pos.x;
        mobj->trans.y = models[i]->pos.y;
        mobj->trans.z = models[i]->pos.z;
        mobj->scale.x = models[i]->scale.x;
        mobj->scale.y = models[i]->scale.y;
        mobj->scale.z = models[i]->scale.z;
        mobj->rot.x = models[i]->rot.x;
        mobj->rot.y = models[i]->rot.y;
        mobj->rot.z = models[i]->rot.z;
    }
    spr = D_800F60B0_F6CB0[sign->grp]->unk00;
    h = spr->unk0A;
    spr->unk0A = (u16)spr->unk06 >> 1;
    sign->y -= h >> 1;
    baseY = sign->y;
    espPosSet(sign->spr, sign->x, sign->y);
    for (i = 0; i < 2; i++) {
        models[i]->obj->func_ptr = NULL;
        objs[i] = omAddObj(500, 0, 0, -1, func_80106508_3653F8_name_55);
        objs[i]->unk_50 = func_80027154_27D54(sizeof(Ovl55FlyWork), 0x7918);
        work[i] = objs[i]->unk_50;
        work[i]->model = models[i];
        work[i]->path = &D_8010BCC0_36ABB0_name_55[i];
        work[i]->speed = 15.0f;
        work[i]->rate = 1.0f;
        work[i]->vel = 0;
        work[i]->delay = 0;
    }
    HuPrcSleep(20);
    PlaySound(0x39D);
    angle = 0.0f;
    do {
        sign->x = sign->x - 5.0f;
        angle += 10.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        espPosSet(sign->spr, sign->x, func_8010633C_36522C_name_55(sign->grp, angle, baseY, 175));
        func_8001A9C0_1B5C0(sign->spr, angle);
        HuPrcVSleep();
    } while (sign->x >= -80);
    func_8001AC44_1B844(sign->spr);
    HuMemMemoryFreePerm(D_8010C570_36B460_name_55);
    D_8010C570_36B460_name_55 = 0;
}

/* The lowest y a sprite group at angle can sit at without its rotated corners passing limit. */
f32 func_8010633C_36522C_name_55(s16 grp, f32 angle, s16 y, s32 limit) {
    f32 corner[2][4];
    f32 rotated[4];
    HuSprite_Unk84_Unk00_Struct* spr;
    s16 w;
    s16 h;
    s16 ox;
    s16 oy;
    s16 room;
    f32 max;
    f32 ret;
    s32 i;

    spr = D_800F60B0_F6CB0[grp]->unk00;
    w = spr->unk04;
    h = spr->unk06;
    oy = (u16)spr->unk0A;
    room = limit - y;
    ox = spr->unk08;
    corner[0][0] = corner[0][3] = -ox;
    corner[0][1] = corner[0][2] = w - ox;
    corner[1][0] = corner[1][1] = -oy;
    corner[1][2] = corner[1][3] = h - oy;
    for (i = 0; i < 4; i++) {
        rotated[i] = HuMathSin(angle) * corner[0][i] + func_800B7890_B8490(angle) * corner[1][i];
    }
    ret = y;
    max = 0.0f;
    for (i = 0; i < 4; i++) {
        if (max < rotated[i]) {
            max = rotated[i];
        }
    }
    if (room < max) {
        ret = y - (max - room);
    }
    return ret;
}

/* A flying model's object: head for path->end, hopping when vel is set. */
void func_80106508_3653F8_name_55(omObjData* obj) {
    Ovl55FlyWork* work;
    MBModel* model;
    omObjData* mobj;
    f32 dist;

    work = obj->unk_50;
    model = work->model;
    mobj = model->obj;
    dist = HuVecDistance(&model->pos, &work->path->end);
    func_80056658_57258(&model->pos, &work->path->end, &model->rot);
    if (work->delay != 0) {
        if (--work->delay == 0) {
            work->vel = 3.5f;
            work->grav = 1.0f;
        }
    }
    if (work->vel != 0.0f || mobj->trans.y != 0.0f) {
        mobj->trans.y += work->vel * work->rate;
        work->vel -= work->grav * work->rate;
    }
    if (mobj->trans.y < 0.0f) {
        work->vel = 0.0f;
        mobj->trans.y = 0.0f;
    }
    if (work->speed <= dist) {
        mobj->trans.x += model->rot.x * work->speed * work->rate;
        mobj->trans.z += model->rot.z * work->speed * work->rate;
        model->pos.x = mobj->trans.x;
        model->pos.y = mobj->trans.y;
        model->pos.z = mobj->trans.z;
        mobj->rot.z += work->speed * 3.0f * work->rate;
        if (mobj->rot.z >= 360.0f) {
            mobj->rot.z -= 360.0f;
        }
    } else {
        mobj->trans.x = work->path->end.x;
        mobj->trans.y = work->path->end.y;
        mobj->trans.z = work->path->end.z;
        model->pos.x = mobj->trans.x;
        model->pos.y = mobj->trans.y;
        model->pos.z = mobj->trans.z;
        MBModelKill(model);
        omDelObj(obj);
    }
}
