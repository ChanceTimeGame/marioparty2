#include "common.h"
#include "ovl_48.h"

/* .data (0x30C870-0x30CB30): status-window layouts, per-character motion lists, scene data (mp2boarddata.py; 3F's twin) */
PdStatusLayout D_801084D0_30C870_name_48[8] = {
    { { { 512, 16, 184, 16 }, { 512, 74, 184, 74 }, { 512, 132, 184, 132 }, { -192, 74, 24, 74 } }, 0, 30 },
    { { { -1, -1, 512, -1 }, { -1, -1, 512, -1 }, { -1, -1, -1, 74 }, { -1, -1, -1, 74 } }, 0, 10 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, 176, -1 }, { -1, -1, 32, -1 } }, 0, 5 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, -1, 24 }, { -1, -1, -1, 24 } }, 0, 20 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, 512, -1 }, { -1, -1, -192, -1 } }, 0, 20 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, 176, -1 }, { -1, -1, 24, -1 } }, 0, 30 },
    { { { 512, 43, 184, 43 }, { 512, 105, 184, 105 }, { -1, -1, -1, -1 }, { -192, 74, 24, 74 } }, 0, 30 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { 512, 74, 184, 74 }, { -192, 74, 24, 74 } }, 0, 30 },
};
u32 D_801085F0_30C990_name_48[8] = {
    0x00000007, 0x00020001, 0x000200AD, 0x00020000, 0x00020002, 0x0002004E,
    0x00020055, 0x000200AE,
};
u32 D_80108610_30C9B0_name_48[8] = {
    0x00000007, 0x00030001, 0x000300AD, 0x00030000, 0x00030002, 0x0003004E,
    0x00030055, 0x000300AE,
};
u32 D_80108630_30C9D0_name_48[8] = {
    0x00000007, 0x00070001, 0x000700AD, 0x00070000, 0x00070002, 0x0007004E,
    0x00070055, 0x000700AE,
};
u32 D_80108650_30C9F0_name_48[8] = {
    0x00000007, 0x00040001, 0x000400AD, 0x00040000, 0x00040002, 0x0004004E,
    0x00040055, 0x000400AE,
};
u32 D_80108670_30CA10_name_48[8] = {
    0x00000007, 0x00050001, 0x000500AD, 0x00050000, 0x00050002, 0x0005004E,
    0x00050055, 0x000500AE,
};
u32 D_80108690_30CA30_name_48[8] = {
    0x00000007, 0x00060001, 0x000600AD, 0x00060000, 0x00060002, 0x0006004E,
    0x00060055, 0x000600AE,
};
u32* D_801086B0_30CA50_name_48[6] = {
    D_801085F0_30C990_name_48, D_80108610_30C9B0_name_48,
    D_80108630_30C9D0_name_48, D_80108650_30C9F0_name_48,
    D_80108670_30CA10_name_48, D_80108690_30CA30_name_48,
};
s32 D_801086C8_30CA68_name_48 = 0;
Vec D_801086CC_30CA6C_name_48 = { 0.0f, 500.0f, 500.0f };
Vec D_801086D8_30CA78_name_48 = { 0.0f, 0.0f, 500.0f };
Vec D_801086E4_30CA84_name_48[3] = {
    { -120.0f, 0.0f, 890.0f }, { -200.0f, 0.0f, 750.0f },
    { 200.0f, 0.0f, 750.0f },
};
Vec D_80108708_30CAA8_name_48 = { -130.0f, 0.0f, 700.0f };
Vec D_80108714_30CAB4_name_48 = { 130.0f, 0.0f, 700.0f };
Vec D_80108720_30CAC0_name_48 = { -215.0f, 0.0f, 700.0f };
Vec D_8010872C_30CACC_name_48 = { 215.0f, 0.0f, 700.0f };
Vec D_80108738_30CAD8_name_48 = { -500.0f, 0.0f, 700.0f };
Vec D_80108744_30CAE4_name_48 = { 500.0f, 0.0f, 700.0f };
Vec D_80108750_30CAF0_name_48[2] = {
    { -250.0f, 750.0f, 100.0f }, { 250.0f, 750.0f, 100.0f },
};
s16 D_80108768_30CB08_name_48[4][2] = {
    { 100, 50 }, { 50, 90 }, { 260, 50 }, { 210, 90 },
};
s32 D_80108778_30CB18_name_48 = 0;
f32 D_8010877C_30CB1C_name_48[5] = {
    -5.0f, 5.0f, 0.0f, 360.0f, 0.0f,
};

void func_80102800_306BA0_name_48(void) {
    RectF scissor = { 8.0f, 8.0f, 312.0f, 232.0f };

    omInitObjMan(40, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    CameraScissorSet(0, &scissor);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_801029A0_306D40_name_48();
    func_80088640_89240();
    func_8005FE10_60A10();
    func_80060034_60C34(0, (u8)gPlayers[0].player_space_color);
    func_80060034_60C34(1, (u8)gPlayers[1].player_space_color);
    func_80060034_60C34(2, (u8)gPlayers[2].player_space_color);
    func_80060034_60C34(3, (u8)gPlayers[3].player_space_color);
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    omAddPrcObj(func_80102CB4_307054_name_48, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102BD4_306F74_name_48);
}

void func_801029A0_306D40_name_48(void) {
    s32 bits;
    s32 i;

    D_80108934_30CCD4_name_48 = -1;
    D_80108928_30CCC8_name_48 = 0;
    D_80108BEC_30CF8C_name_48 = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108BEC_30CF8C_name_48 = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108BEC_30CF8C_name_48 = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108BEC_30CF8C_name_48 = 1;
        }
    }
    D_80108930_30CCD0_name_48 = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108930_30CCD0_name_48++;
    }
    D_80108948_30CCE8_name_48 = 1;
    D_80108938_30CCD8_name_48[i] = 1;
    bits = D_800F8D1A_F991A.targets;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 0xE;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((bits >> i) & 1) {
            D_80108948_30CCE8_name_48++;
            D_80108938_30CCD8_name_48[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108980_30CD20_name_48[i] = 0;
    }
    if (D_80108948_30CCE8_name_48 == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108938_30CCD8_name_48[i] == 1 && i != D_80108930_30CCD0_name_48) {
                D_80108934_30CCD4_name_48 = i;
                break;
            }
        }
    }
    D_800FC880_FD480 = 0;
    D_800F8C5C_F985C = 0;
    D_80108964_30CD04_name_48 = GwSystem.current_turn;
}

void func_80102BD4_306F74_name_48(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C28_306FC8_name_48(void) {
    Vec pos;
    Vec rot;
    Vec up;

    pos.x = 0.0f;
    pos.y = 150.0f;
    pos.z = 1300.0f;
    rot.x = rot.z = pos.x;
    rot.y = 100.0f;
    up.x = pos.x;
    up.y = 1.0f;
    up.z = pos.x;
    Hu3DCamSetPositionOrientation(0, &pos, &rot, &up);
    Hu3DCamUpdateMtx(0);
}

/* Wait until both duelists' paths (work[0], work[1]) are walked, then free them. */
#define D48_WAIT_PATHS()                               \
    while (TRUE) {                                     \
        done = 0;                                      \
        for (i = 0; i < 2; i++) {                      \
            if (func_8005A778_5B378(work[i]) != 0) {   \
                done++;                                \
            }                                          \
        }                                              \
        if (done == 2) {                               \
            break;                                     \
        }                                              \
        HuPrcVSleep();                                 \
    }                                                  \
    for (i = 0; i < 2; i++) {                          \
        HuMemMemoryFreePerm(work[i]);                  \
    }

/* The duel scene's flow (42's func_80102CA0): the duelists and the referee walk in, the opponent
   and the stake are chosen, the two signs crash down, then the mash (func_80106A64, the countdown
   func_80107FC8) decides D_80108968: 1 a draw, 2 the challenger wins, 3 the opponent. On a win
   both signs slide out and back, the loser's sign flies off, the winner's spins (func_80108220)
   and the winner takes both stakes; on a draw the signs fly up and the stakes go back. */
/* NON_MATCHING: masked 13, scheduling and registers only: the referee's drop loop keeps the new
   height in f2 (GCC f0), the winner's sound table entry is loaded before the 0x2C/0x54 choice (GCC
   fills the call's delay slot with it), two delay-slot placements. Logic checked against the asm. */
#ifdef NON_MATCHING
void func_80102CB4_307054_name_48(void) {
    s32 side = 0;
    ModelPathWork* work[4];
    Vec pos[2];
    f32 dx[4] = { -30.0f, 30.0f, 50.0f, -50.0f };
    u32 motions[3] = { 2, 0x800A7, 0x800AA };
    s32 i;
    s32 j;
    u16 done;
    s32 layout;
    s16 mes;
    s32 winner;
    f32 scale;
    f32 vel;
    f32 z;
    MBModel* model;

    func_80050E00_51A00(31);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 4; i++) {
        if (D_80108938_30CCD8_name_48[i] != 0) {
            MBPlayerModelCreate(i, D_801086B0_30CA50_name_48[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 1, 0);
            PLAYER_MODEL(i)->pos.x = -1000.0f;
            PLAYER_MODEL(i)->pos.y = 0.0f;
            PLAYER_MODEL(i)->pos.z = 700.0f;
            gPlayers[i].flags |= 2;
            MBMotionSet(PLAYER_MODEL(i), 1, 1);
            func_80043DAC_449AC(PLAYER_MODEL(i));
        }
    }
    D_80108BF0_30CF90_name_48 = MBModelFileCreate(0x800A6, 0xD, 1.0f, 1.0f, motions);
    func_8005AB50_5B750(D_80108BF0_30CF90_name_48, 1, 0xB, 0x800AD);
    func_80056658_57258(&D_80108BF0_30CF90_name_48->pos, &D_801086CC_30CA6C_name_48, &D_80108BF0_30CF90_name_48->rot);
    D_80108BF0_30CF90_name_48->pos.x = D_801086CC_30CA6C_name_48.x;
    D_80108BF0_30CF90_name_48->pos.y = 0.0f;
    D_80108BF0_30CF90_name_48->pos.z = D_801086CC_30CA6C_name_48.z;
    if (D_80108BEC_30CF8C_name_48 == 0) {
        D_80108BF0_30CF90_name_48->jumpY = D_801086CC_30CA6C_name_48.y;
        D_80108BF0_30CF90_name_48->jumpVel = 7.5f;
        D_80108BF0_30CF90_name_48->jumpAccel = 0.0f;
        D_80108BF4_30CF94_name_48 = MBModelFileCreate(0xA019D, 0xD, 1.0f, 1.0f, NULL);
        D_80108BF4_30CF94_name_48->pos.x = D_801086CC_30CA6C_name_48.x;
        D_80108BF4_30CF94_name_48->pos.y = 0.0f;
        D_80108BF4_30CF94_name_48->pos.z = D_801086CC_30CA6C_name_48.z;
        D_80108BF4_30CF94_name_48->jumpY = D_801086CC_30CA6C_name_48.y;
        D_80108BF4_30CF94_name_48->jumpVel = 7.5f;
        D_80108BF4_30CF94_name_48->jumpAccel = 0.0f;
    }
    /* the two signs, high up, and their shadows (scaled to nothing) */
    scale = 0.0f;
    for (i = 0; i < 2; i++) {
        D_80108BF8_30CF98_name_48[i] = LoadFormFile(0xA0202, 0x699);
        D_80108BFC_30CF9C_name_48[i] = LoadFormFile(0xD, 0x699);
        func_80029714_2A314(D_80108BF8_30CF98_name_48[i], D_80108750_30CAF0_name_48[i].x, D_80108750_30CAF0_name_48[i].y + 237.02071f, D_80108750_30CAF0_name_48[i].z);
        func_80029714_2A314(D_80108BFC_30CF9C_name_48[i], D_80108750_30CAF0_name_48[i].x, 0.0f, D_80108750_30CAF0_name_48[i].z);
        func_800297E8_2A3E8(D_80108BFC_30CF9C_name_48[i], scale, 1.0f, scale);
    }
    for (i = 0; i < 6; i++) {
        D_80108C00_30CFA0_name_48[i] = LoadFormFile(0xA0208, 0x68D);
        func_8002D124_2DD24(D_80108C00_30CFA0_name_48[i]);
    }
    D_80108C0C_30CFAC_name_48 = func_8001A2F8_1AEF8(0xA01F8);
    D_80108C16_30CFB6_name_48 = func_8001A2F8_1AEF8(0xA01F9);
    for (i = 0; i < 2; i++) {
        D_80108C0E_30CFAE_name_48[i] = func_8001AAAC_1B6AC(D_80108C0C_30CFAC_name_48, 1, 1);
        D_80108C12_30CFB2_name_48[i] = func_8001AAAC_1B6AC(D_80108C16_30CFB6_name_48, 1, 1);
        espPosSet(D_80108C0E_30CFAE_name_48[i], D_80108768_30CB08_name_48[i * 2][0], D_80108768_30CB08_name_48[i * 2][1]);
        espPosSet(D_80108C12_30CFB2_name_48[i], D_80108768_30CB08_name_48[i * 2 + 1][0], D_80108768_30CB08_name_48[i * 2 + 1][1]);
        espDispOff(D_80108C0E_30CFAE_name_48[i]);
        espDispOff(D_80108C12_30CFB2_name_48[i]);
    }
    PlayMusic(0x25);
    InitFadeIn(0, 0x10);
    if (D_80108BEC_30CF8C_name_48 == 0) {
        /* the referee drops in with his hat */
        goto drop;
    fall:
        HuPrcVSleep();
    drop:
        D_80108BF4_30CF94_name_48->jumpY = D_80108BF0_30CF90_name_48->jumpY;
        D_80108BF0_30CF90_name_48->jumpY = D_80108BF0_30CF90_name_48->jumpY - D_80108BF0_30CF90_name_48->jumpVel;
        if (!(D_80108BF0_30CF90_name_48->jumpY <= D_80108BF0_30CF90_name_48->pos.y)) {
            goto fall;
        }
        D_80108BF0_30CF90_name_48->jumpY = D_80108BF0_30CF90_name_48->pos.y;
        func_80105DFC_30A19C_name_48();
        layout = (D_80108948_30CCE8_name_48 == 4) ? 0 : -1;
        if (D_80108948_30CCE8_name_48 == 3) {
            layout = 6;
        }
        if (layout != -1) {
            /* three or four players: the challenger picks the opponent */
            func_80105944_309CE4_name_48(layout);
            PD_WAIT_STEP();
            PlaySound(0xE8);
            omAddPrcObj(func_80105F1C_30A2BC_name_48, 0x12, 0, 0);
            D_80108910_30CCB0_name_48 = 0;
            PD_WAIT_STEP();
            func_80105944_309CE4_name_48(1);
            PD_WAIT_STEP();
            func_80105944_309CE4_name_48(2);
            PD_WAIT_STEP();
        } else {
            func_80105944_309CE4_name_48(7);
            PD_WAIT_STEP();
        }
        MBVsSprCreateY(160.0f, 90.0f);
        HuPrcSleep(10);
        D_801086C8_30CA68_name_48 = 1;
        func_80105944_309CE4_name_48(3);
        PD_WAIT_STEP();
        omAddPrcObj(func_801061E8_30A588_name_48, 0x12, 0, 0);
        D_80108910_30CCB0_name_48 = 0;
        PD_WAIT_STEP();
        func_80105944_309CE4_name_48(4);
        MBVsSprKill();
        PD_WAIT_STEP();
    }
    /* the duelists walk to their marks */
    PLAYER_MODEL(D_80108930_30CCD0_name_48)->pos.x = -500.0f;
    PLAYER_MODEL(D_80108934_30CCD4_name_48)->pos.x = 500.0f;
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 0, 0, 5, 2);
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108930_30CCD0_name_48), 15.0f, 1, &D_80108708_30CAA8_name_48);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 0, 0, 5, 2);
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108934_30CCD4_name_48), 15.0f, 1, &D_80108714_30CAB4_name_48);
    D48_WAIT_PATHS();
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 2, 0, 5, 2);
    /* the referee walks to the middle */
    work[0] = func_8005A718_5B318(D_80108BF0_30CF90_name_48, 30.0f, 1, D_801086E4_30CA84_name_48);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    model = D_80108BF0_30CF90_name_48;
    model->rot.x = __sinf(0.34906584f); /* 20 degrees */
    model = D_80108BF0_30CF90_name_48;
    model->rot.y = 0.0f;
    model->rot.z = __cosf(0.34906584f);
    D_80108BF0_30CF90_name_48->obj->rot.z = 20.0f;
    PlaySound(0xE8);
    D_80108924_30CCC4_name_48 = 0x21D;
    D_80108918_30CCB8_name_48 = 90;
    D_8010891C_30CCBC_name_48 = 47;
    D_80108920_30CCC0_name_48 = 2;
    omAddPrcObj(func_80105354_3096F4_name_48, 0x12, 0, 0);
    D_80108910_30CCB0_name_48 = 0;
    PD_WAIT_STEP();
    D_80108BF0_30CF90_name_48->rot.x = HuMathSin(0.0f);
    D_80108BF0_30CF90_name_48->rot.y = 0.0f;
    D_80108BF0_30CF90_name_48->rot.z = func_800B7890_B8490(D_80108BF0_30CF90_name_48->rot.y);
    D_80108BF0_30CF90_name_48->obj->rot.z = 0.0f;
    work[0] = func_8005A718_5B318(D_80108BF0_30CF90_name_48, 30.0f, 1, &D_801086D8_30CA78_name_48);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    D_80108BF0_30CF90_name_48->rot.x = HuMathSin(0.0f);
    D_80108BF0_30CF90_name_48->rot.y = 0.0f;
    D_80108BF0_30CF90_name_48->rot.z = func_800B7890_B8490(D_80108BF0_30CF90_name_48->rot.y);
    HuPrcSleep(15);
    /* the signs crash down */
    vel = 0.0f;
    D_80108C48_30CFE8_name_48 = D_80108750_30CAF0_name_48[0].y;
    while (D_80108C48_30CFE8_name_48 > 0.0f) {
        for (i = 0; i < 2; i++) {
            D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].pos.y = D_80108C48_30CFE8_name_48 + 237.02071f;
            func_800297E8_2A3E8(D_80108BFC_30CF9C_name_48[i], scale, 1.0f, scale);
        }
        D_80108C48_30CFE8_name_48 -= vel;
        if (D_80108C48_30CFE8_name_48 < 0.0f) {
            D_80108C48_30CFE8_name_48 = 0.0f;
        }
        scale += 0.14285714285714285;
        vel += 2.0;
        HuPrcVSleep();
    }
    for (i = 0; i < 2; i++) {
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].pos.y = 237.02071f;
    }
    omVibrate(D_80108930_30CCD0_name_48, 20, 0, 20);
    omVibrate(D_80108934_30CCD4_name_48, 20, 0, 20);
    PlaySound(0x3CD);
    for (i = 0; i < 8; i++) {
        func_80054040_54C40(0, 8 - i);
        HuPrcVSleep();
        func_80054040_54C40(0, i - 8);
        HuPrcVSleep();
    }
    func_80054040_54C40(0, 0);
    /* the duelists step up to their signs */
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 0, 0, 5, 2);
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108930_30CCD0_name_48), 15.0f, 1, &D_80108720_30CAC0_name_48);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 0, 0, 5, 2);
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108934_30CCD4_name_48), 15.0f, 1, &D_8010872C_30CACC_name_48);
    D48_WAIT_PATHS();
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 2, 0, 5, 2);
    HuVecCopyXYZ(&pos[0], D_80108750_30CAF0_name_48[0].x, 0.0f, D_80108750_30CAF0_name_48[0].z);
    HuVecCopyXYZ(&pos[1], D_80108750_30CAF0_name_48[1].x, 0.0f, D_80108750_30CAF0_name_48[1].z);
    func_800446B4_452B4(PLAYER_MODEL(D_80108930_30CCD0_name_48), &pos[0], 10);
    func_800446B4_452B4(PLAYER_MODEL(D_80108934_30CCD4_name_48), &pos[1], 10);
    HuPrcSleep(10);
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 1, 0, 5, 0);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 1, 0, 5, 0);
    HuPrcSleep(10);
    D_80108924_30CCC4_name_48 = 0x21E;
    D_80108918_30CCB8_name_48 = 85;
    D_8010891C_30CCBC_name_48 = 70;
    D_80108920_30CCC0_name_48 = 0;
    omAddPrcObj(func_80105354_3096F4_name_48, 0x12, 0, 0);
    D_80108910_30CCB0_name_48 = 0;
    PD_WAIT_STEP();
    func_8008CE5C_8DA5C();
    func_800691FC_69DFC(0);
    PD_WAIT_MESSAGE();
    HuPrcSleep(18);
    /* the mash */
    D_80108C18_30CFB8_name_48[0] = func_8007975C_7A35C(0x3CE, D_80108930_30CCD0_name_48);
    D_80108C18_30CFB8_name_48[1] = func_8007975C_7A35C(0x3CE, D_80108934_30CCD4_name_48);
    func_800796F0_7A2F0(D_80108C18_30CFB8_name_48[0], 0);
    func_800796F0_7A2F0(D_80108C18_30CFB8_name_48[1], 0);
    omAddPrcObj(func_80107FC8_30C368_name_48, 0x12, 0, 0);
    func_80106A64_30AE04_name_48();
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 6, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 6, 0, 5, 2);
    D_80108910_30CCB0_name_48 = 0;
    D_80108968_30CD08_name_48 = 0;
    func_8010848C_30C82C_name_48();
    PD_WAIT_STEP();
    HuPrcVSleep();
    MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 2, 0, 5, 2);
    switch (D_80108968_30CD08_name_48) {
        case 2:
            D_800FC880_FD480 = D_80108930_30CCD0_name_48;
            D_800F8C5C_F985C = D_80108934_30CCD4_name_48;
            D_80108778_30CB18_name_48 = 0;
            side = 1;
            break;
        case 3:
            D_800FC880_FD480 = D_80108934_30CCD4_name_48;
            D_800F8C5C_F985C = D_80108930_30CCD0_name_48;
            D_80108778_30CB18_name_48 = 1;
            side = 0;
            break;
        case 1:
            D_800FC880_FD480 = -1;
            break;
    }
    func_80079614_7A214(45);
    if (D_800FC880_FD480 == -1) {
        /* a draw: the signs fly up, both get their stake back */
        if (D_80108BEC_30CF8C_name_48 != 0) {
            func_800794A8_7A0A8(60);
        }
        vel = 80.0f;
        D_80108C48_30CFE8_name_48 = 0.0f;
        do {
            for (i = 0; i < 2; i++) {
                D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].pos.y = D_80108C48_30CFE8_name_48 + 237.02071f;
                func_800297E8_2A3E8(D_80108BFC_30CF9C_name_48[i], scale, 1.0f, scale);
            }
            scale -= 0.1;
            D_80108C48_30CFE8_name_48 += vel;
            vel -= 2.0f;
            HuPrcVSleep();
        } while (vel > 0.0f);
        for (i = 0; i < 2; i++) {
            func_800298A4_2A4A4(D_80108BFC_30CF9C_name_48[i], 4, 4);
        }
        if (D_80108BEC_30CF8C_name_48 == 0) {
            func_80105944_309CE4_name_48(2);
        }
        PLAYER_MODEL(D_80108930_30CCD0_name_48)->pos.y = 0.0f;
        PLAYER_MODEL(D_80108934_30CCD4_name_48)->pos.y = -0.0f;
        MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 3, 0, 5, 2);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108930_30CCD0_name_48), 15.0f, 1, &D_80108708_30CAA8_name_48);
        MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 3, 0, 5, 2);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108934_30CCD4_name_48), 15.0f, 1, &D_80108714_30CAB4_name_48);
        D48_WAIT_PATHS();
        MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 2, 0, 5, 2);
        HuPrcSleep(40);
        if (D_80108BEC_30CF8C_name_48 == 0) {
            MBMotionShiftSet(D_80108BF0_30CF90_name_48, 1, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_80108BF0_30CF90_name_48, 0, 0, 20, 2);
            PlaySound(0xE8);
            func_80088640_89240();
            D_80102708_103308 = 1;
            D_80108924_30CCC4_name_48 = 0x216;
            D_80108918_30CCB8_name_48 = 90;
            D_8010891C_30CCBC_name_48 = 70;
            D_80108920_30CCC0_name_48 = 0;
            omAddPrcObj(func_80105354_3096F4_name_48, 0x12, 0, 0);
            D_80108910_30CCB0_name_48 = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_80108930_30CCD0_name_48, D_80108914_30CCB4_name_48);
            func_8006135C_61F5C(D_80108934_30CCD4_name_48, D_80108914_30CCB4_name_48, 0);
            func_800794A8_7A0A8(30);
            HuPrcSleep(30);
        }
        PlayMusic(0x57);
        func_800691FC_69DFC(0x13);
        PD_WAIT_MESSAGE();
    } else {
        /* the duelists walk back to their signs' sides */
        MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 0, 0, 5, 2);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108930_30CCD0_name_48), 15.0f, 1, &D_80108738_30CAD8_name_48);
        MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 0, 0, 5, 2);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108934_30CCD4_name_48), 15.0f, 1, &D_80108744_30CAE4_name_48);
        D48_WAIT_PATHS();
        MBMotionShiftSet(D_80108BF0_30CF90_name_48, 1, 0, 5, 0);
        HuPrcSleep(23);
        MBMotionShiftSet(D_80108BF0_30CF90_name_48, 0, 0, 20, 2);
        func_80088640_89240();
        D_80102708_103308 = 1;
        PlaySound(0xE8);
        D_80108924_30CCC4_name_48 = 0x21F;
        D_80108918_30CCB8_name_48 = 85;
        D_8010891C_30CCBC_name_48 = 70;
        D_80108920_30CCC0_name_48 = 0;
        omAddPrcObj(func_80105354_3096F4_name_48, 0x12, 0, 0);
        D_80108910_30CCB0_name_48 = 0;
        PD_WAIT_STEP();
        /* both signs rise, slide out tilting and come back */
        D_80108C48_30CFE8_name_48 = 0.0f;
        for (i = 0; i < 8; i++) {
            D_80108C48_30CFE8_name_48 += 4.0f;
            for (j = 0; j < 2; j++) {
                D_800FC834_FD434[D_80108BF8_30CF98_name_48[j]].pos.y = D_80108C48_30CFE8_name_48 + 237.02071f;
            }
            HuPrcVSleep();
        }
        HuPrcSleep(15);
        for (i = 0; i < 2; i++) {
            D_80108C38_30CFD8_name_48[i] = D_80108750_30CAF0_name_48[i].x;
            D_80108C40_30CFE0_name_48[i] = D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].rot.y;
        }
        while (D_80108C38_30CFD8_name_48[0] > -1000.0f) {
            for (i = 0; i < 2; i++) {
                D_80108C38_30CFD8_name_48[i] += dx[i];
                /* retail quirk: both signs tilt while the first one is under 45 degrees */
                if (D_80108C40_30CFE0_name_48[0] >= -45.0f) {
                    D_80108C40_30CFE0_name_48[i] += D_8010877C_30CB1C_name_48[i];
                }
                D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].pos.x = D_80108C38_30CFD8_name_48[i];
                D_800FC834_FD434[D_80108BFC_30CF9C_name_48[i]].pos.x = D_80108C38_30CFD8_name_48[i];
                D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].rot.y = D_80108C40_30CFE0_name_48[i];
            }
            HuPrcVSleep();
        }
        HuPrcSleep(15);
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[0]].rot.y = 90.0f;
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[1]].rot.y = 270.0f;
        while (D_80108C38_30CFD8_name_48[0] < -245.0f) {
            for (i = 0; i < 2; i++) {
                D_80108C38_30CFD8_name_48[i] += dx[i + 2];
                D_800FC834_FD434[D_80108BF8_30CF98_name_48[i]].pos.x = D_80108C38_30CFD8_name_48[i];
                D_800FC834_FD434[D_80108BFC_30CF9C_name_48[i]].pos.x = D_80108C38_30CFD8_name_48[i];
            }
            HuPrcVSleep();
        }
        /* the signs clash: the loser's flies off, the winner's spins */
        omVibrate(D_80108930_30CCD0_name_48, 20, 0, 20);
        omVibrate(D_80108934_30CCD4_name_48, 20, 0, 20);
        omAddPrcObj(func_80108168_30C508_name_48, 0x12, 0, 0);
        PlaySound(0x3CD);
        D_80108BE8_30CF88_name_48 = PlaySound(0x4B5);
        vel = 160.0f;
        z = D_80108750_30CAF0_name_48[side].z;
        D_80108C48_30CFE8_name_48 = 0.0f;
        D_80108C38_30CFD8_name_48[0] = D_80108750_30CAF0_name_48[side].x;
        while (fabs(D_80108C38_30CFD8_name_48[0]) <= 2000.0) {
            func_80029714_2A314(D_80108BF8_30CF98_name_48[side], D_80108C38_30CFD8_name_48[0], D_80108C48_30CFE8_name_48 + 237.02071f, z);
            func_80029714_2A314(D_80108BFC_30CF9C_name_48[side], D_80108C38_30CFD8_name_48[0], 0.0f, z);
            func_800297E8_2A3E8(D_80108BFC_30CF9C_name_48[side], scale, 1.0f, scale);
            scale = 4.0f - D_80108C48_30CFE8_name_48 / 100.0f;
            if (scale < 0.0f) {
                scale = 0.0f;
            }
            D_80108C48_30CFE8_name_48 += vel;
            if (side == 0) {
                D_80108C38_30CFD8_name_48[0] -= 400.0f;
            } else {
                D_80108C38_30CFD8_name_48[0] += 400.0f;
            }
            HuPrcVSleep();
        }
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[side]].pos.y = 0.0f;
        func_800298A4_2A4A4(D_80108BF8_30CF98_name_48[side], 4, 4);
        HuPrcSleep(15);
        omAddPrcObj(func_80108220_30C5C0_name_48, 0x12, 0, 0);
        HuPrcSleep(15);
        func_800794A8_7A0A8(45);
        if (D_80108BEC_30CF8C_name_48 == 0) {
            D_80108910_30CCB0_name_48 = 0;
            func_80105944_309CE4_name_48(2);
        }
        PLAYER_MODEL(D_80108930_30CCD0_name_48)->pos.y = 0.0f;
        PLAYER_MODEL(D_80108934_30CCD4_name_48)->pos.y = -0.0f;
        MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 3, 0, 5, 2);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108930_30CCD0_name_48), 15.0f, 1, &D_80108708_30CAA8_name_48);
        MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 3, 0, 5, 2);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108934_30CCD4_name_48), 15.0f, 1, &D_80108714_30CAB4_name_48);
        D48_WAIT_PATHS();
        MBMotionShiftSet(PLAYER_MODEL(D_80108930_30CCD0_name_48), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_80108934_30CCD4_name_48), 2, 0, 5, 2);
        /* both turn to the camera */
        HuVecCopyXYZ(&pos[0], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800FC880_FD480)->pos.y, D_800C9B80_CA780->pos.z);
        HuVecCopyXYZ(&pos[1], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800F8C5C_F985C)->pos.y, D_800C9B80_CA780->pos.z);
        func_800446B4_452B4(PLAYER_MODEL(D_800FC880_FD480), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_800F8C5C_F985C), &pos[1], 10);
        HuPrcSleep(20);
        if (D_80108BEC_30CF8C_name_48 == 0) {
            PlaySound(0xE8);
            func_80088640_89240();
            D_80102708_103308 = 1;
            D_8010892C_30CCCC_name_48 = D_800FC880_FD480;
            D_80108924_30CCC4_name_48 = 0x215;
            D_80108918_30CCB8_name_48 = 90;
            D_8010891C_30CCBC_name_48 = 70;
            D_80108920_30CCC0_name_48 = 3;
            omAddPrcObj(func_80105354_3096F4_name_48, 0x12, 0, 0);
            D_80108910_30CCB0_name_48 = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_800FC880_FD480, D_80108914_30CCB4_name_48 * 2);
            if (D_80108BE8_30CF88_name_48 != -1) {
                func_800799A4_7A5A4(D_80108BE8_30CF88_name_48, 40);
            }
            HuPrcSleep(30);
        }
        PlayMusic(0x51);
        winner = D_800FC880_FD480;
        func_800732FC_73EFC(D_801086B0_30CA50_name_48[gPlayers[winner].character][5],
                            (winner == D_80108930_30CCD0_name_48) ? 0x2C : 0x54, winner);
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 4, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800FC880_FD480], 1);
        mes = func_800797DC_7A3DC(0xFC, D_800F8C5C_F985C);
        if (D_800F8C5C_F985C == D_80108930_30CCD0_name_48) {
            func_800798F8_7A4F8(mes, 0x2C);
        } else {
            func_800798F8_7A4F8(mes, 0x54);
        }
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 5, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 2);
        func_800691FC_69DFC(6, gPlayers[D_800FC880_FD480].character);
        PD_WAIT_MESSAGE();
    }
    HuPrcSleep(8);
    func_80105D14_30A0B4_name_48();
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
__asm__(".section .rodata");
const u32 D_801087A0_30CB40_name_48[4] = { 0xC1F00000, 0x41F00000, 0x42480000, 0xC2480000 };

__asm__(".section .rodata");
const u32 D_801087B0_30CB50_name_48[3] = { 0x00000002, 0x000800A7, 0x000800AA };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_80102CB4_307054_name_48);
#endif

__asm__(".section .rodata");
const char D_801087E8_30CB88_name_48[] = "%c%c";

__asm__(".section .rodata");
const char D_801087F0_30CB90_name_48[] = "%d";

void func_80105354_3096F4_name_48(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_80108920_30CCC0_name_48 == 1) {
        sprintf(num, D_801087E8_30CB88_name_48, 0x18, gPlayers[D_8010892C_30CCCC_name_48].character);
        func_8008D974_8E574(num, 0);
    }
    if (D_80108920_30CCC0_name_48 == 3) {
        sprintf(num, D_801087F0_30CB90_name_48, D_80108914_30CCB4_name_48);
        sprintf(name, D_801087E8_30CB88_name_48, 0x18, gPlayers[D_8010892C_30CCCC_name_48].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    func_8008DACC_8E6CC(1, size, D_80108924_30CCC4_name_48);
    win = func_8010571C_309ABC_name_48((s16)D_80108918_30CCB8_name_48, (s16)D_8010891C_30CCBC_name_48, size[0], size[1], 0, 0, 200);
    if (D_80108928_30CCC8_name_48 & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80108920_30CCC0_name_48 == 3) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, (void*)D_80108924_30CCC4_name_48, -1, -1);
    func_80057A78_58678((s16)win, D_80108930_30CCD0_name_48, D_80108934_30CCD4_name_48);
    if (D_80108920_30CCC0_name_48 == 2 && (gPlayers[D_80108930_30CCD0_name_48].flags & 1) && (gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
        func_801077F4_30BB94_name_48(0, 0, 0);
    }
    while (TRUE) {
        switch (D_80108920_30CCC0_name_48) {
            case 0:
            case 1:
            case 3:
                if (D_80108928_30CCC8_name_48 & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_80108910_30CCB0_name_48 = 1;
                omDelPrcObj(NULL);
                break;
            case 2:
                if ((gPlayers[D_80108930_30CCD0_name_48].flags & 1) && (gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
                    btn = func_80107FBC_30C35C_name_48();
                } else {
                    btn = func_80105884_309C24_name_48();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_80108910_30CCB0_name_48 = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_8010571C_309ABC_name_48(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108934_30CCD4_name_48 != -1) {
        mask = (1 << gPlayers[D_80108930_30CCD0_name_48].port) | (1 << gPlayers[D_80108934_30CCD4_name_48].port);
    } else {
        mask = 1 << gPlayers[D_80108930_30CCD0_name_48].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_8010571C_309ABC_name_48);
#endif

u16 func_80105884_309C24_name_48(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80108930_30CCD0_name_48].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80108930_30CCD0_name_48].port];
    }
    if (D_80108934_30CCD4_name_48 != -1 && btn == 0) {
        if (!(gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80108934_30CCD4_name_48].port];
        }
    }
    return btn;
}

void func_80105944_309CE4_name_48(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108910_30CCB0_name_48 = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80105C7C_30A01C_name_48);
    work = func_80027154_27D54(44, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108938_30CCD8_name_48[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108930_30CCD0_name_48) {
                if (i == D_80108934_30CCD4_name_48) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108950_30CCF0_name_48[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][0] != -1) {
                status->xPos = D_801084D0_30C870_name_48[layout].pos[slot][0];
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][1] != -1) {
                status->yPos = D_801084D0_30C870_name_48[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_801084D0_30C870_name_48[layout].frames - 1;
            if (D_801084D0_30C870_name_48[layout].pos[slot][2] != -1) {
                status->unk_18 = D_801084D0_30C870_name_48[layout].pos[slot][2];
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][3] != -1) {
                status->unk_1C = D_801084D0_30C870_name_48[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_801086C8_30CA68_name_48 == 1) {
        status = &D_80101510_102110[D_80108930_30CCD0_name_48];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_801084D0_30C870_name_48[layout].frames - 1;
    }
}

void func_80105C7C_30A01C_name_48(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108938_30CCD8_name_48[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108948_30CCE8_name_48) {
        D_80108910_30CCB0_name_48 = 1;
        omDelObj(obj);
    }
}

void func_80105D14_30A0B4_name_48(void) {
    omAddObj(0x10, 0, 0, -1, func_80105D50_30A0F0_name_48);
    func_80069764_6A364(60);
}

void func_80105D50_30A0F0_name_48(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_80108BEC_30CF8C_name_48 != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105DA8_30A148_name_48;
    }
}

void func_80105DA8_30A148_name_48(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105DFC_30A19C_name_48(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80105E8C_30A22C_name_48);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80105E8C_30A22C_name_48(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108BF4_30CF94_name_48->scale.x += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->scale.y += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->scale.z += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108BF4_30CF94_name_48);
        omDelObj(obj);
    }
}

void func_80105F1C_30A2BC_name_48(void) {
    s32 ys4[3] = { 32, 90, 148 };
    s32 ys3[2] = { 59, 121 };
    s32 ys[4];
    s16 size[2];
    s32* src;
    s32 win;
    s16 spr;
    u16 btn;
    s32 sel;
    s32 count;
    s32 i;

    func_8008DACC_8E6CC(1, size, 0x212);
    win = func_8010571C_309ABC_name_48(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, (void*)0x212, -1, -1);
    sel = 0;
    count = D_80108948_30CCE8_name_48 - 1;
    if (D_80108948_30CCE8_name_48 == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108948_30CCE8_name_48; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
        func_801077F4_30BB94_name_48(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80105884_309C24_name_48();
        if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
            btn = func_80107FBC_30C35C_name_48();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108950_30CCF0_name_48[sel], 1) != 0) {
            PlaySound(2);
            D_80108910_30CCB0_name_48 = 1;
            D_80108934_30CCD4_name_48 = D_80108950_30CCF0_name_48[sel];
            espDispOff(spr);
            func_8008CCA8_8D8A8(win);
            omDelPrcObj(NULL);
        }
        if (btn & 0x400) {
            PlaySound(1);
            sel++;
            if (sel >= count) {
                sel = 0;
            }
        }
        if (btn & 0x800) {
            PlaySound(1);
            sel--;
            if (sel < 0) {
                sel = count - 1;
            }
        }
        espPosSet(spr, 184, ys[sel]);
        D_800F851A_F911A = 1;
        HuPrcVSleep();
    }
}

/* The stake (as 42's func_80105A80 and 3F's func_80105054): the starting amount comes from the
   turn (turns[] bands) and the poorer player's coins (stakes[]); right/left add or take 1, up/down
   10, A accepts. Both duelists pay the stake as it changes. Retail quirk: at the 999 cap a further
   raise still takes the coin from both players. */
#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, D_801087F0_30CB90_name_48, stake);                         \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, buf, x, y)

void func_801061E8_30A588_name_48(void) {
    s32 stakes[6] = { 1, 5, 10, 20, 30, 50 };
    s32 turns[4] = { 11, 21, 36, 46 };
    char buf[0x200];
    char mess[0x20];
    s16 size[2];
    char num[8];
    char pad[16];
    s32 win;
    s32 coins1;
    s32 coins2;
    u16 btn;
    s32 stake;
    s32 len;
    s32 turn;
    s32 y;
    s32 x;
    s32 i;
    s32 j;

    turn = D_80108964_30CD04_name_48;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80108930_30CCD0_name_48)->coins;
    coins2 = BoardPlayerGet(D_80108934_30CCD4_name_48)->coins;
    D_8010896C_30CD0C_name_48 = coins1;
    if (coins2 < coins1) {
        D_8010896C_30CD0C_name_48 = coins2;
    }
    i++;
    while (D_8010896C_30CD0C_name_48 < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80108914_30CCB4_name_48 = D_80108960_30CD00_name_48 = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108960_30CD00_name_48;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_8010571C_309ABC_name_48(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, (void*)0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80108930_30CCD0_name_48);
    AdjustPlayerCoins(D_80108930_30CCD0_name_48, -D_80108914_30CCB4_name_48);
    AdjustPlayerCoins(D_80108934_30CCD4_name_48, -D_80108914_30CCB4_name_48);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
        func_801077F4_30BB94_name_48(D_80108914_30CCB4_name_48, D_8010896C_30CD0C_name_48, 3);
    }
    while (TRUE) {
        D_80108914_30CCB4_name_48 = stake;
        btn = ContDStkTrg[gPlayers[D_80108930_30CCD0_name_48].port];
        if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
            btn = func_80107FBC_30C35C_name_48();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80108910_30CCB0_name_48 = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80108930_30CCD0_name_48].coins > 0 && gPlayers[D_80108934_30CCD4_name_48].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, -1);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108960_30CD00_name_48 < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, 1);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108960_30CD00_name_48) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, 10);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80108930_30CCD0_name_48].coins >= 10 && gPlayers[D_80108934_30CCD4_name_48].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, -10);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, -10);
            }
        }
        HuPrcVSleep();
    }
}

/* Starts the mash (func_80106DEC): clears both duelists' press counts and, for each, marks the
   frames of a 150-frame timeline on which the CPU presses (30-40, 42-57, 58-65 or 60-75 presses by
   difficulty); shows the first button prompts, and sets the six arrows' scales and positions. */
/* NON_MATCHING: masked 23: retail recomputes the row address k * 300 inside the count loop from
   hoisted k * 5 and k * 80 and keeps the % 150 multiplier out of a register; GCC hoists both. Logic
   checked against the asm. */
#ifdef NON_MATCHING
void func_80106A64_30AE04_name_48(void) {
    f32 scale[3] = { 1.4f, 1.0f, 1.0f };
    omObjData* obj;
    MashWork* work;
    s32 player;
    s32 count;
    s32 i;
    s32 k;
    s16* p;
    s16 (*tl)[150];

    obj = omAddObj(0x10, 0, 0, -1, func_80106DEC_30B18C_name_48);
    work = obj->unk_50 = func_80027154_27D54(sizeof(MashWork), 0x7918);
    D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] = 0;
    D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48] = 0;
    count = 0;
    tl = D_80108990_30CD30_name_48;
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            player = D_80108930_30CCD0_name_48;
        } else {
            player = D_80108934_30CCD4_name_48;
        }
        switch (gPlayers[player].cpu_difficulty) {
            case 3:
                count = (rand8() & 0xF) + 60;
                break;
            case 2:
                count = (rand8() & 7) + 58;
                break;
            case 1:
                count = (rand8() & 0xF) + 42;
                break;
            case 0:
                count = (u8)(rand8() % 11) + 30;
                break;
        }
        for (i = 0; i < 150; i++) {
            tl[k][i] = 0;
        }
        for (i = 0; i < count; i++) {
            do {
                p = &tl[k][(u8)(rand8() % 150)];
            } while (*p != 0);
            *p = 1;
        }
        espDispOn(D_80108C0E_30CFAE_name_48[k]);
        func_800298A4_2A4A4(D_80108C00_30CFA0_name_48[k], 4, 0);
        for (i = 0; i < 150; i++) {
        }
    }
    for (i = 0; i < 6; i++) {
        D_80108C20_30CFC0_name_48[i] = scale[i >> 1];
        func_80029714_2A314(D_80108C00_30CFA0_name_48[i], D_80108750_30CAF0_name_48[i & 1].x, 237.02071f, D_80108750_30CAF0_name_48[i & 1].z);
        func_800297E8_2A3E8(D_80108C00_30CFA0_name_48[i], D_80108C20_30CFC0_name_48[i], D_80108C20_30CFC0_name_48[i], D_80108C20_30CFC0_name_48[i]);
        work->alpha[i] = 0;
    }
    work->frame = 0;
    work->fade = 5;
}
#else
__asm__(".section .rodata");
const u32 D_80108838_30CBD8_name_48[3] = { 0x3FB33333, 0x3F800000, 0x3F800000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_80106A64_30AE04_name_48);
#endif

/* The mash, one frame: a duelist presses A and B alternately (a CPU presses on its timeline's
   marked frames); each press raises the duelist's sound pitch (presses / 80 * 500, up to 500),
   swaps the A/B prompt and speeds the arrows up. The six arrows shrink from 1.4 towards 1.1 and
   fade in; one that reaches 1.25 restarts the arrow two behind it. After 150 frames the one with
   more presses wins (D_80108968: 2 the challenger, 3 the opponent); a tie is a draw (1) at zero
   presses and a coin toss otherwise. */
void func_80106DEC_30B18C_name_48(omObjData* obj) {
    s32 btn[2] = { 0x8000, 0x4000 };
    MashWork* work;
    f32 speed;
    s32 i;
    s32 j;

    work = obj->unk_50;
    speed = 0.005f;
    if ((!(gPlayers[D_80108930_30CCD0_name_48].flags & 1) &&
         (ContBtnTrg[gPlayers[D_80108930_30CCD0_name_48].port] & btn[D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] & 1])) ||
        ((gPlayers[D_80108930_30CCD0_name_48].flags & 1) && D_80108990_30CD30_name_48[0][work->frame] != 0)) {
        D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48]++;
        D_80108C1C_30CFBC_name_48[0] = (f32)D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] / 80.0f * 500.0f;
        if (D_80108C1C_30CFBC_name_48[0] > 500.0f) {
            D_80108C1C_30CFBC_name_48[0] = 500;
        }
        func_800796F0_7A2F0(D_80108C18_30CFB8_name_48[0], D_80108C1C_30CFBC_name_48[0]);
        if (D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] & 1) {
            espDispOff(D_80108C0E_30CFAE_name_48[0]);
            espDispOn(D_80108C12_30CFB2_name_48[0]);
        } else {
            espDispOn(D_80108C0E_30CFAE_name_48[0]);
            espDispOff(D_80108C12_30CFB2_name_48[0]);
        }
        speed += 0.01f;
    }
    if ((!(gPlayers[D_80108934_30CCD4_name_48].flags & 1) &&
         (ContBtnTrg[gPlayers[D_80108934_30CCD4_name_48].port] & btn[D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48] & 1])) ||
        ((gPlayers[D_80108934_30CCD4_name_48].flags & 1) && D_80108990_30CD30_name_48[1][work->frame] != 0)) {
        D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48]++;
        D_80108C1C_30CFBC_name_48[1] = (f32)D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48] / 80.0f * 500.0f;
        if (D_80108C1C_30CFBC_name_48[1] > 500.0f) {
            D_80108C1C_30CFBC_name_48[1] = 500;
        }
        func_800796F0_7A2F0(D_80108C18_30CFB8_name_48[1], D_80108C1C_30CFBC_name_48[1]);
        if (D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48] & 1) {
            espDispOff(D_80108C0E_30CFAE_name_48[1]);
            espDispOn(D_80108C12_30CFB2_name_48[1]);
        } else {
            espDispOn(D_80108C0E_30CFAE_name_48[1]);
            espDispOff(D_80108C12_30CFB2_name_48[1]);
        }
        speed += 0.01f;
    }
    for (i = 0; i < 6; i++) {
        if (D_80108C20_30CFC0_name_48[i] > 1.1f) {
            D_80108C20_30CFC0_name_48[i] -= speed;
            if (D_80108C20_30CFC0_name_48[i] < 1.1f) {
                func_800298A4_2A4A4(D_80108C00_30CFA0_name_48[i], 4, 4);
            }
        }
        if (D_80108C20_30CFC0_name_48[i] <= 1.25f) {
            j = i - 2;
            if (j < 0) {
                j = i + 4;
            }
            if (D_80108C20_30CFC0_name_48[j] <= 1.1f) {
                D_80108C20_30CFC0_name_48[j] = 1.4f;
                work->alpha[j] = 0;
                func_800298A4_2A4A4(D_80108C00_30CFA0_name_48[j], 4, 0);
            }
        }
        func_800297E8_2A3E8(D_80108C00_30CFA0_name_48[i], D_80108C20_30CFC0_name_48[i], D_80108C20_30CFC0_name_48[i], D_80108C20_30CFC0_name_48[i]);
        func_8002D0A0_2DCA0(D_80108C00_30CFA0_name_48[i], work->alpha[i]);
        work->alpha[i] += work->fade;
        if (work->alpha[i] > 255) {
            work->alpha[i] = 255;
        }
    }
    if (++work->frame == 150) {
        if (D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] > D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48]) {
            D_80108968_30CD08_name_48 = 2;
        }
        if (D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] < D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48]) {
            D_80108968_30CD08_name_48 = 3;
        }
        if (D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] == D_80108970_30CD10_name_48[D_80108934_30CCD4_name_48]) {
            if (D_80108970_30CD10_name_48[D_80108930_30CCD0_name_48] == 0) {
                D_80108968_30CD08_name_48 = 1;
            } else if (rand8() & 1) {
                D_80108968_30CD08_name_48 = 3;
            } else {
                D_80108968_30CD08_name_48 = 2;
            }
        }
        for (i = 0; i < 2; i++) {
            espDispOff(D_80108C0E_30CFAE_name_48[i]);
            espDispOff(D_80108C12_30CFB2_name_48[i]);
        }
        for (i = 0; i < 6; i++) {
            func_800298A4_2A4A4(D_80108C00_30CFA0_name_48[i], 4, 4);
        }
        omDelObj(obj);
    }
}

s32 func_80107508_30B8A8_name_48(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 1 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 2 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 3 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

/* NON_MATCHING: masked 34, as 42's and 3F's twins: the rank loops' guards and the n != 0 exits
   (retail threads them with bnezl/blez); logic checked against the asm. Unlike 42, the flag-clearing
   loop runs over all D_80108948 entries, not D_80108948 - 1. */
#define PD_ABS(x) ((x) < 0 ? -(x) : (x))
#ifdef NON_MATCHING
void func_801077F4_30BB94_name_48(s32 cur, s32 target, s32 mode) {
    s32 cand[4];
    s32 flag[4];
    s32 rows[32] = {
        -1, 1, 3, 2, 3, 3, 3, 3,
        0, 1, -1, 1, 1, 2, 1, 2,
        0, 1, 0, 1, -1, 1, 1, 2,
        0, 0, 0, 1, 0, 1, -1, -1,
    };
    s32 range[4] = { 10, 20, 20, 9 };
    s32 base[4] = { 90, 60, 20, 1 };
    s32 unused[8];
    omObjData* obj;
    PdCpuInput* work;
    s32 diff;
    s32 row;
    s32 n;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, func_80107E1C_30C1BC_name_48);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108988_30CD28_name_48 = 0;
    if (mode == 2) {
        if (gPlayers[D_80108930_30CCD0_name_48].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108948_30CCE8_name_48; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80107508_30B8A8_name_48();
            }
        } else {
            work->target = func_80107508_30B8A8_name_48();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_80108930_30CCD0_name_48) * 8;
        row += func_80059FD0_5ABD0(D_80108930_30CCD0_name_48) * 2;
        diff = PD_ABS(gPlayers[D_80108930_30CCD0_name_48].stars - gPlayers[D_80108934_30CCD4_name_48].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_8010896C_30CD0C_name_48 / 100;
        if (work->target < D_80108960_30CD00_name_48) {
            work->target = D_80108960_30CD00_name_48;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108844_30CBE4_name_48[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_801088C4_30CC64_name_48[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_801088D4_30CC74_name_48[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_801077F4_30BB94_name_48);
#endif

void func_80107E1C_30C1BC_name_48(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108988_30CD28_name_48 = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108988_30CD28_name_48 = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108988_30CD28_name_48 = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108988_30CD28_name_48 = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_80108914_30CCB4_name_48;
                if (work->cur == work->target) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108988_30CD28_name_48 = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108988_30CD28_name_48 = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108988_30CD28_name_48 = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108988_30CD28_name_48 = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_80107FBC_30C35C_name_48(void) {
    return D_80108988_30CD28_name_48;
}

/* The countdown: full-width 5 to 0 in the centre, one a second. */
void func_80107FC8_30C368_name_48(void) {
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x54", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x53", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x52", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x51", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x50", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x4F", 160, 56, 1.0, 1.0, 1), 30);
    D_80108910_30CCB0_name_48 = 1;
    omDelPrcObj(NULL);
}

/* Shake the camera: four rounds of up, down, left, right, each smaller. */
void func_80108168_30C508_name_48(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80054040_54C40(0, 8 - i * 2);
        HuPrcVSleep();
        func_80054040_54C40(0, i * 2 - 8);
        HuPrcVSleep();
        func_80054040_54C40(8 - i, 0);
        HuPrcVSleep();
        func_80054040_54C40(i - 8, 0);
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

/* Spin the winner's sign (model D_80108BF8[D_80108778]) a quarter turn to face front, then drop it
   32 units in eight steps. */
void func_80108220_30C5C0_name_48(void) {
    s32 i;

    if (D_80108778_30CB18_name_48 == 0) {
        D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] = 90.0f;
        do {
            D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] += D_8010877C_30CB1C_name_48[D_80108778_30CB18_name_48];
            D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48];
            HuPrcVSleep();
        } while (D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] > 0.0f);
    } else {
        D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] = 270.0f;
        do {
            D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] += D_8010877C_30CB1C_name_48[D_80108778_30CB18_name_48];
            D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48];
            HuPrcVSleep();
        } while (D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] < 360.0f);
    }
    D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = 0.0f;
    HuPrcSleep(15);
    D_80108C48_30CFE8_name_48 = 32.0f;
    for (i = 0; i < 8; i++) {
        D_80108C48_30CFE8_name_48 -= 4.0f;
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].pos.y = D_80108C48_30CFE8_name_48 + 237.02071f;
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

void func_8010848C_30C82C_name_48(void) {
    omAddObj(0x10, 0, 0, -1, func_801084C0_30C860_name_48);
}

void func_801084C0_30C860_name_48(omObjData* obj) {
}
