#include "ovl_55.h"
#include "game/hmfman.h"

/* .data (0x36ABE0-0x36AEA0) */
/* board 1, per character: MBPlayerModelCreate lists */
u32 D_8010BCF0_36ABE0_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010BD14_36AC04_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010BD38_36AC28_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010BD5C_36AC4C_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010BD80_36AC70_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010BDA4_36AC94_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010BDC8_36ACB8_name_55[6] = {
    D_8010BCF0_36ABE0_name_55, D_8010BD14_36AC04_name_55, D_8010BD38_36AC28_name_55, D_8010BD5C_36AC4C_name_55,
    D_8010BD80_36AC70_name_55, D_8010BDA4_36AC94_name_55,
};
u32 D_8010BDE0_36ACD0_name_55[4] = {
    3, 0x80018, 0x80019, 0x80017,
};
Vec D_8010BDF0_36ACE0_name_55[2] = {
    { -30.0f, 0.0f, -165.0f },
    { 214.0f, 0.0f, 161.0f },
};
u32 D_8010BE08_36ACF8_name_55[2] = {
    1, 0x8008E,
};
Vec D_8010BE10_36AD00_name_55 = { -25.0f, 0.0f, -215.0f };
Vec D_8010BE1C_36AD0C_name_55 = { -128.0f, 10.0f, -310.0f };
Ovl55Pos2 D_8010BE28_36AD18_name_55[5] = {
    { 114.0f, 106.0f }, { 160.0f, 88.0f }, { 136.0f, 148.0f }, { 192.0f, 140.0f },
    { 208.0f, 108.0f },
};
f32 D_8010BE50_36AD40_name_55[5] = {
    145.0f, 90.0f, 225.0f, 320.0f, 47.0f,
};
/* zero filler up to the next 16-byte boundary (probably a retail file boundary) */
s32 D_8010BE64_36AD54_name_55[3] = {
    0, 0, 0,
};
/* board 2, per character: MBPlayerModelCreate lists */
u32 D_8010BE70_36AD60_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010BE94_36AD84_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010BEB8_36ADA8_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010BEDC_36ADCC_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010BF00_36ADF0_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010BF24_36AE14_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010BF48_36AE38_name_55[6] = {
    D_8010BE70_36AD60_name_55, D_8010BE94_36AD84_name_55, D_8010BEB8_36ADA8_name_55, D_8010BEDC_36ADCC_name_55,
    D_8010BF00_36ADF0_name_55, D_8010BF24_36AE14_name_55,
};
u32 D_8010BF60_36AE50_name_55[4] = {
    3, 0x80028, 0x80028, 0x80029,
};
Vec D_8010BF70_36AE60_name_55[2] = {
    { -55.0f, 0.0f, -15.0f },
    { 214.0f, 0.0f, 161.0f },
};
Vec D_8010BF88_36AE78_name_55 = { -8.0f, 0.0f, 22.0f };
Vec D_8010BF94_36AE84_name_55 = { -57.0f, 0.0f, -37.0f };
u32 D_8010BFA0_36AE90_name_55[4] = {
    3, 0x8008D, 0x80090, 0x80094,
};

/* Board 1: the player and host models. */
void func_80106760_365650_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010BDC8_36ACB8_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x80016, 13, 0.8f, 0.8f, D_8010BDE0_36ACD0_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x80016, 13, 0.8f, 0.8f, D_8010BDE0_36ACD0_name_55);
    func_8005AB50_5B750(D_8010C56C_36B45C_name_55, 2, 8, 0x80039);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 1: a player's board model. */
void func_801068B0_3657A0_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010BDC8_36ACB8_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 1: the title sprite stretches in, then START may skip. */
void func_80106940_365830_name_55(void) {
    f32 scale;
    s32 i;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA01A6), 0, 1);
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

/* Board 1: a model walks in, a thing drops and lands, and it spins off while the camera pans. */
void func_80106AA0_365990_name_55(void) {
    Vec target;
    Vec land;
    MBModel* model;
    MBModel* drop;
    s32 fx;
    u16 frame;
    s32 spin;
    f32 x;
    f32 z;
    f32 rot;
    s32 i;
    s32 n;

    drop = NULL;
    frame = 0;
    func_80029708_2A308(0);
    func_80050E00_51A00(10);
    HuPrcSleep(3);
    spin = 0;
    MBDCameraPos3DSet(&D_8010BDF0_36ACE0_name_55[0]);
    i = 0;
    func_800599F0_5A5F0();
    fx = func_80059A68_5A668(0xA015F, 4);
    model = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010BE08_36ACF8_name_55);
    MBMotionSet(model, 0, 2);
    x = 22.0f;
    z = -120.0f;
    model->pos.x = x;
    model->pos.y = 0.0f;
    model->pos.z = z;
    target.x = x - 100.0f;
    target.y = 0.0f;
    target.z = z;
    func_80056658_57258(&model->pos, &target, &model->rot);
    rot = model->obj->rot.y;
    InitFadeIn(0, 16);
    for (i = 0; i < 66; i++) {
        frame++;
        if (frame == 26) {
            land.x = -18.0f;
            land.y = 0.0f;
            land.z = -130.0f;
            func_80107630_366520_name_55(&D_8010BE10_36AD00_name_55, 0.3f, 12.0f, 1);
            drop = func_80043510_44110(0x7F, NULL);
            func_800B3170_B3D70(&drop->pos, &D_8010BE10_36AD00_name_55);
            func_80056D80_57980(&drop->pos, &land, &drop->pos, 10);
            drop->jumpVel = 10.0f;
            drop->jumpAccel = -1.3f;
        }
        if (frame == 36) {
            MBModelKill(drop);
            drop = NULL;
            func_80059B08_5A708(fx, land.x, land.y, land.z, 4);
            spin = 1;
        }
        model->attr |= 1;
        if (spin == 1) {
            rot += 40.0f;
            if (rot >= 360.0f) {
                rot -= 360.0f;
            }
            func_800B2060_B2C60((f32 (*)[4])D_800FC834_FD434[*model->obj->model].mtx, 0.0f, rot, 0.0f);
            model->obj->rot.x = 20.0f;
            model->obj->rot.z = 20.0f;
            func_8005A608_5B208(model, &D_8010BE1C_36AD0C_name_55, 7.0f);
        } else {
            x += -1.0f;
            model->pos.x = x;
            model->pos.y = 0.0f;
            model->pos.z = z;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            break;
        }
        HuPrcVSleep();
    }
    if (drop != NULL) {
        MBModelKill(drop);
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        n = func_80059E7C_5AA7C(&D_8010BDF0_36ACE0_name_55[0], &D_8010BDF0_36ACE0_name_55[1], 3.0f) + 20;
        for (i = 0; i < n; i++) {
            if (spin == 1) {
                rot += 40.0f;
                if (rot >= 360.0f) {
                    rot -= 360.0f;
                }
                func_800B2060_B2C60((f32 (*)[4])D_800FC834_FD434[*model->obj->model].mtx, 0.0f, rot, 0.0f);
                model->obj->rot.x = 20.0f;
                model->obj->rot.z = 20.0f;
                func_8005A608_5B208(model, &D_8010BE1C_36AD0C_name_55, 7.0f);
            } else {
                x += -1.0f;
                model->pos.x = x;
                model->pos.y = 0.0f;
                model->pos.z = z;
            }
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            HuPrcVSleep();
        }
    }
    func_80059BCC_5A7CC(fx);
    func_80023124_23D24();
    MBModelKill(model);
}

/* Board 1: the sign swings in like a pendulum. */
void func_80106F44_365E34_name_55(void) {
    Ovl55Sign8* sign;
    f32 vel;
    f32 angle;
    s32 i;

    sign = (Ovl55Sign8*)(D_8010C570_36B460_name_55 = (s32)HuMemMemoryAllocPerm(0x40));
    sign->grp[0] = func_8001A2F8_1AEF8(0xA01AD);
    sign->grp[1] = func_8001A2F8_1AEF8(0xA01AE);
    sign->grp[2] = func_8001A2F8_1AEF8(0xA01AF);
    sign->grp[3] = func_8001A2F8_1AEF8(0xA01B0);
    sign->grp[4] = func_8001A2F8_1AEF8(0xA01B1);
    sign->grp[5] = func_8001A2F8_1AEF8(0xA01B2);
    sign->grp[6] = func_8001A2F8_1AEF8(0xA01B3);
    sign->grp[7] = func_8001A2F8_1AEF8(0xA01B4);
    for (i = 0; i < 8; i++) {
        sign->spr[i] = func_8001AAAC_1B6AC(sign->grp[i], 0, 1);
        func_8001A708_1B308(sign->spr[i], 0x4000);
        func_8001A788_1B388(sign->spr[i], 0x2000);
    }
    for (i = 2; i < 7; i++) {
        espDispOff(sign->spr[i]);
    }
    espDispOff(sign->spr[7]);
    func_8001A788_1B388(sign->spr[1], 0x3000);
    func_8001A788_1B388(sign->spr[7], 0x1000);
    vel = 0.0f;
    angle = -100.0f;
    PlaySound(0x3B8);
    while (TRUE) {
        func_801071E0_3660D0_name_55(sign, angle);
        vel -= HuMathSin(angle);
        angle += vel;
        if ((angle < 0.0f) & (vel < 0.0f)) {
            vel += 0.4f;
        }
        if ((angle > 0.0f) & (vel > 0.0f)) {
            vel -= 0.4f;
        }
        if (fabs(angle) < 2.0 && fabs(vel) < 1.0) {
            break;
        }
        HuPrcVSleep();
    }
    func_801071E0_3660D0_name_55(sign, 0.0f);
}

/* Board 1: places the sign's board and its hanger for a swing angle. */
void func_801071E0_3660D0_name_55(Ovl55Sign8* sign, f32 angle) {
    f32 x;
    f32 y;

    x = HuMathSin(angle) * 76.0f + HuMathSin(angle) * 32.0f + 160.0f;
    y = func_800B7890_B8490(angle) * 76.0f + func_800B7890_B8490(angle) * 32.0f;
    espPosSet(sign->spr[0], x, y);
    x -= HuMathSin(angle) * 32.0f;
    y = y - 76.0f - func_800B7890_B8490(angle) * 32.0f;
    espPosSet(sign->spr[1], x, y);
    func_8001A9C0_1B5C0(sign->spr[1], angle);
}

/* Board 1: a burst drops onto the sign, which gives way to five pieces flying apart. */
void func_80107330_366220_name_55(void) {
    Ovl55Sign8* sign;
    f32 scale;
    s32 x;
    s32 y;
    s32 i;
    s32 j;

    sign = (Ovl55Sign8*)D_8010C570_36B460_name_55;
    scale = 3.0f;
    x = 160;
    y = -60;
    espDispOn(sign->spr[7]);
    for (i = 0; i < 7; i++) {
        espPosSet(sign->spr[7], x, y);
        y += 24;
        func_8001A91C_1B51C(sign->spr[7], scale, scale);
        scale -= 2.0f / 7.0f;
        HuPrcVSleep();
    }
    espDispOff(sign->spr[1]);
    espDispOff(sign->spr[0]);
    espDispOff(sign->spr[7]);
    for (i = 0; i < 4; i++) {
        func_8005A4EC_5B0EC(i, 2);
    }
    scale = 1.0f;
    for (i = 0; i < 5; i++) {
        espDispOn(sign->spr[i + 2]);
        espPosSet(sign->spr[i + 2], D_8010BE28_36AD18_name_55[i].x, D_8010BE28_36AD18_name_55[i].y);
        func_8001A91C_1B51C(sign->spr[i + 2], scale, scale);
    }
    PlaySound(0x3AA);
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 5; j++) {
            D_8010BE28_36AD18_name_55[j].x += func_800B7890_B8490(D_8010BE50_36AD40_name_55[j]) * 18.0f;
            D_8010BE28_36AD18_name_55[j].y -= HuMathSin(D_8010BE50_36AD40_name_55[j]) * 18.0f;
            espPosSet(sign->spr[j + 2], D_8010BE28_36AD18_name_55[j].x, D_8010BE28_36AD18_name_55[j].y);
            func_8001A91C_1B51C(sign->spr[j + 2], scale, scale);
            if (i == 2) {
                func_8001A748_1B348(sign->spr[j + 2], 0x4000);
            }
        }
        scale += 0.2f;
        HuPrcVSleep();
    }
    for (i = 0; i < 8; i++) {
        func_8001AC44_1B844(sign->spr[i]);
        SprAnimKill(sign->grp[i]);
    }
    HuMemMemoryFreePerm((void*)D_8010C570_36B460_name_55);
    D_8010C570_36B460_name_55 = 0;
}

/* A fading, growing puff at pos (MP3 ChillyWaters func_8010F088 without the drift). */
omObjData* func_80107630_366520_name_55(Vec* pos, f32 grow, f32 fade, s16 kill) {
    omObjData* obj;
    Ovl55PuffWork* work;
    MBModel* model;

    obj = omAddObj(500, 0, 0, -1, func_80107744_366634_name_55);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Ovl55PuffWork), 0x7918);
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
    work->kill = kill;
    return obj;
}

/* The puff's object (MP3 ChillyWaters func_8010F1E4). */
void func_80107744_366634_name_55(omObjData* obj) {
    Ovl55PuffWork* work;
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
        if (work->kill != 0) {
            MBModelKill(work->model);
            omDelObj(obj);
            return;
        }
        omSetStatBit(obj, 8);
    }
    func_8002D0A0_2DCA0(*model->obj->model, work->alpha);
}

/* Retail pads the text to 16 bytes here (0x8010784C): probably a file boundary, board 2 starting
   a file of its own. */
__asm__(".balign 16");

/* Board 2: the player and host models. */
void func_80107850_366740_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010BF48_36AE38_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x80028, 13, 0.8f, 0.8f, D_8010BF60_36AE50_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x80028, 13, 0.8f, 0.8f, D_8010BF60_36AE50_name_55);
    func_8005AB50_5B750(D_8010C56C_36B45C_name_55, 2, 8, 0x80039);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 2: a player's board model. */
void func_801079A0_366890_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010BF48_36AE38_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 2: the title sprite stretches in, then START may skip. */
void func_80107A30_366920_name_55(void) {
    f32 scale;
    s32 i;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA0245), 0, 1);
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

/* Board 2: a model walks up, turns away and bows; a second shot, then the camera pans. */
void func_80107B90_366A80_name_55(void) {
    Vec target;
    MBModel* model;
    s32 i;
    s32 n;

    func_80029708_2A308(0);
    func_80050E00_51A00(16);
    HuPrcSleep(3);
    i = 0;
    MBDCameraPos3DSet(&D_8010BF70_36AE60_name_55[0]);
    model = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010BFA0_36AE90_name_55);
    MBMotionSet(model, 0, 2);
    model->pos.x = D_8010BF88_36AE78_name_55.x;
    model->pos.y = D_8010BF88_36AE78_name_55.y;
    model->pos.z = D_8010BF88_36AE78_name_55.z;
    func_80056658_57258(&model->pos, &D_8010BF94_36AE84_name_55, &model->rot);
    InitFadeIn(0, 16);
    for (i = 0; i < 26; i++) {
        func_8005A5E8_5B1E8(model, &D_8010BF94_36AE84_name_55, 1.0f);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 30; i++) {
        func_8005A5E8_5B1E8(model, &D_8010BF94_36AE84_name_55, 1.0f);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    target.x = D_8010BF94_36AE84_name_55.x;
    target.y = D_8010BF94_36AE84_name_55.y;
    target.z = D_8010BF94_36AE84_name_55.z + 200.0f;
    while (func_8005A7E8_5B3E8(model, &target, 16.0f) == 0) {
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(model, -1, 0, 4, 2);
    HuPrcSleep(15);
    MBMotionShiftSet(model, 2, 0, 4, 2);
    HuPrcSleep(45);
    func_8008F624_90224(255, 255, 255);
    InitFadeOut(13, 20);
    for (i = 0; i < 21; i++) {
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBDBackKill();
    func_80050E00_51A00(21);
    HuPrcSleep(3);
    MBDCameraPos3DSet(&D_8010BF70_36AE60_name_55[0]);
    MBMotionSet(model, 1, 2);
    func_8008F624_90224(0, 0, 0);
    InitFadeIn(14, 16);
    for (i = 0; i < 61; i++) {
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        n = func_80059E7C_5AA7C(&D_8010BF70_36AE60_name_55[0], &D_8010BF70_36AE60_name_55[1], 3.0f) + 20;
        for (i = 0; i < n; i++) {
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            HuPrcVSleep();
        }
    }
end:
    MBModelKill(model);
}

/* Board 2: the sign (a board and two halves) floats down, swaying. */
void func_80107ED0_366DC0_name_55(void) {
    Ovl55Sign3* sign;
    f32 angle;
    s32 i;
    s32 n;

    sign = (Ovl55Sign3*)(D_8010C570_36B460_name_55 = (s32)HuMemMemoryAllocPerm(sizeof(Ovl55Sign3)));
    sign->grp2 = func_8001A2F8_1AEF8(0xA01B5);
    sign->grp = func_8001A2F8_1AEF8(0xA01B6);
    sign->spr[0] = func_8001AAAC_1B6AC(sign->grp, 0, 2);
    sign->spr[1] = func_8001AAAC_1B6AC(sign->grp, 0, 2);
    sign->spr[2] = func_8001AAAC_1B6AC(sign->grp2, 0, 1);
    for (i = 0; i < 3; i++) {
        func_8001A708_1B308(sign->spr[i], 0x4000);
        func_8001A788_1B388(sign->spr[i], (u16)(i * 10 + 0x1000));
        func_8001A91C_1B51C(sign->spr[i], sign->scale, sign->scale);
    }
    func_8001A708_1B308(sign->spr[0], 1);
    sign->x = 160.0f;
    sign->y = -20.0f;
    sign->scale = 0.0f;
    espPosSet(sign->spr[2], sign->x, sign->y);
    espPosSet(sign->spr[0], sign->scale * -72.0f + sign->x, sign->scale * -60.0f + sign->y);
    espPosSet(sign->spr[1], sign->scale * 72.0f + sign->x, sign->scale * -60.0f + sign->y);
    sign->proc = omAddPrcObj(func_801084B4_3673A4_name_55, 0x4FFF, 0x2000, 0);
    sign->proc->user_data = sign;
    angle = 0.0f;
    PlaySound(0x3DE);
    for (i = 0; i < 60.0f; i++) {
        sign->scale += 1.0f / 60.0f;
        angle += 6.0f;
        sign->x = HuMathSin(angle) * 50.0f + 160.0f;
        sign->y += 130.0f / 60.0f;
        for (n = 0; n < 3; n++) {
            func_8001A91C_1B51C(sign->spr[n], sign->scale, sign->scale);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_8005A4EC_5B0EC(i, 1);
    }
    PlaySound(0x3DF);
}

/* Board 2: the board fades and the two halves drift apart. */
void func_80108238_367128_name_55(void) {
    Ovl55Sign3* sign;
    f32 alpha;
    f32 lx;
    f32 rx;
    f32 ly;
    f32 ry;
    f32 dx;
    f32 dy;
    f32 angle;
    s32 i;

    sign = (Ovl55Sign3*)D_8010C570_36B460_name_55;
    alpha = 255.0f;
    for (i = 0; i < 30; i++) {
        alpha -= 8.0f;
        func_8001A6BC_1B2BC(sign->spr[2], alpha);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(sign->spr[2]);
    omDelPrcObj(sign->proc);
    func_8001A708_1B308(sign->spr[1], 1);
    func_8001A748_1B348(sign->spr[0], 1);
    dx = 1.5f;
    dy = -1.5f;
    lx = sign->x + -72.0f;
    rx = sign->x + 72.0f;
    ry = ly = sign->y + -60.0f;
    angle = 0.0f;
    PlaySound(0x3E0);
    for (i = 0; i < 40; i++) {
        lx -= dx;
        rx += dx;
        ly += dy + HuMathSin(angle) * 5.0f;
        ry += dy + HuMathSin(angle) * 5.0f;
        angle += 16.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        espPosSet(sign->spr[0], lx, ly);
        espPosSet(sign->spr[1], rx, ry);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(sign->spr[0]);
    func_8001AC44_1B844(sign->spr[1]);
    SprAnimKill(sign->grp2);
    SprAnimKill(sign->grp);
    HuMemMemoryFreePerm((void*)D_8010C570_36B460_name_55);
    D_8010C570_36B460_name_55 = 0;
}

/* Board 2: the sign's bob (a process; func_80108238 kills it). */
void func_801084B4_3673A4_name_55(void) {
    Ovl55Sign3* sign;
    s16 t;

    t = -2;
    sign = HuPrcCurrentGet()->user_data;
    while (TRUE) {
        if (t < 10) {
            sign->y -= 0.5f;
        } else {
            sign->y += 0.5f;
        }
        if (++t >= 20) {
            t = 0;
        }
        espPosSet(sign->spr[2], sign->x, sign->y);
        espPosSet(sign->spr[0], sign->scale * -72.0f + sign->x, sign->scale * -60.0f + sign->y);
        espPosSet(sign->spr[1], sign->scale * 72.0f + sign->x, sign->scale * -60.0f + sign->y);
        HuPrcVSleep();
    }
}
