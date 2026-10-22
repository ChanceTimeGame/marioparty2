#include "common.h"
#include "ovl_4A.h"

void func_80102800_31EE40_name_4A(void) {
    omInitObjMan(40, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8010298C_31EFCC_name_4A();
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
    omAddPrcObj(func_80102CA0_31F2E0_name_4A, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102BC0_31F200_name_4A);
}

void func_8010298C_31EFCC_name_4A(void) {
    s32 bits;
    s32 i;

    D_80108CA4_3252E4_name_4A = -1;
    D_80108C98_3252D8_name_4A = 0;
    D_80108F54_325594_name_4A = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108F54_325594_name_4A = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108F54_325594_name_4A = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108F54_325594_name_4A = 1;
        }
    }
    D_80108CA0_3252E0_name_4A = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108CA0_3252E0_name_4A++;
    }
    D_80108CB8_3252F8_name_4A = 1;
    D_80108CA8_3252E8_name_4A[i] = 1;
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
            D_80108CB8_3252F8_name_4A++;
            D_80108CA8_3252E8_name_4A[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108CE8_325328_name_4A[i] = 0;
    }
    if (D_80108CB8_3252F8_name_4A == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108CA8_3252E8_name_4A[i] == 1 && i != D_80108CA0_3252E0_name_4A) {
                D_80108CA4_3252E4_name_4A = i;
                break;
            }
        }
    }
    D_800FC880_FD480 = 0;
    D_800F8C5C_F985C = 0;
    D_80108CD4_325314_name_4A = GwSystem.current_turn;
}

void func_80102BC0_31F200_name_4A(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C14_31F254_name_4A(void) {
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

/* Wait until both duelists' paths (work[0], work[1]) are walked, then free them (44's D44_WAIT_PATHS). */
#define D4A_WAIT_PATHS()                                       \
    while (TRUE) {                                             \
        done = 0;                                              \
        for (i = 0; i < 2; i++) {                              \
            if (func_8005A778_5B378(work[i]) != 0) {           \
                done++;                                        \
            }                                                  \
        }                                                      \
        if (done == 2) {                                       \
            break;                                             \
        }                                                      \
        HuPrcVSleep();                                         \
    }                                                          \
    for (i = 0; i < 2; i++) {                                  \
        HuMemMemoryFreePerm(work[i]);                          \
    }

/* Both duelists walk back to their marks (motion 3) and turn to the camera. */
#define D4A_WALK_BACK(a, b)                                                                                          \
    PLAYER_MODEL(D_80108CA0_3252E0_name_4A)->pos.y = 0.0f;                                                           \
    PLAYER_MODEL(D_80108CA4_3252E4_name_4A)->pos.y = -0.0f;                                                          \
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 3, 0, 5, 2);                                           \
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 15.0f, 1, D_80108A78_3250B8_name_4A);     \
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 3, 0, 5, 2);                                           \
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 15.0f, 1, D_80108A84_3250C4_name_4A);     \
    D4A_WAIT_PATHS();                                                                                                \
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 2, 0, 5, 2);                                           \
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 2, 0, 5, 2);                                           \
    HuVecCopyXYZ(&pos[0], D_800C9B80_CA780->pos.x, PLAYER_MODEL(a)->pos.y, D_800C9B80_CA780->pos.z);                 \
    HuVecCopyXYZ(&pos[1], D_800C9B80_CA780->pos.x, PLAYER_MODEL(b)->pos.y, D_800C9B80_CA780->pos.z);                 \
    func_800446B4_452B4(PLAYER_MODEL(a), &pos[0], 10);                                                               \
    func_800446B4_452B4(PLAYER_MODEL(b), &pos[1], 10);                                                               \
    HuPrcSleep(20)

/* The referee's message (func_801057C8): message id, window position, variant; wait for it. */
#define D4A_MESSAGE(id, x, y, kind)                            \
    D_80108C94_3252D4_name_4A = id;                            \
    D_80108C88_3252C8_name_4A = x;                             \
    D_80108C8C_3252CC_name_4A = y;                             \
    D_80108C90_3252D0_name_4A = kind;                          \
    omAddPrcObj(func_801057C8_321E08_name_4A, 0x12, 0, 0);     \
    D_80108C80_3252C0_name_4A = 0;                             \
    PD_WAIT_STEP()

/* The winner's ending: the stake is paid twice over (the referee's message 0x215 or 0x223), the
   winner cheers and the loser despairs. */
#define D4A_WIN(mesId)                                                                                               \
    if (D_80108F54_325594_name_4A == 0) {                                                                            \
        MBMotionShiftSet(D_80108F58_325598_name_4A, 1, 0, 5, 0);                                                     \
        HuPrcSleep(23);                                                                                              \
        MBMotionShiftSet(D_80108F58_325598_name_4A, 0, 0, 20, 2);                                                    \
        PlaySound(0xE8);                                                                                             \
        func_80088640_89240();                                                                                       \
        D_80102708_103308 = 1;                                                                                       \
        D_80108C9C_3252DC_name_4A = D_800FC880_FD480;                                                                \
        D4A_MESSAGE(mesId, 90, 70, 3);                                                                               \
        func_800614B4_620B4(D_800FC880_FD480, D_80108C84_3252C4_name_4A * 2);                                        \
        if (D_80108F50_325590_name_4A != -1) {                                                                       \
            func_800799A4_7A5A4(D_80108F50_325590_name_4A, 40);                                                      \
        }                                                                                                            \
        HuPrcSleep(30);                                                                                              \
    }                                                                                                                \
    PlayMusic(0x51);                                                                                                 \
    func_800732FC_73EFC(D_80108A20_325060_name_4A[gPlayers[D_800FC880_FD480].character][5],                          \
                        (D_800FC880_FD480 != D_80108CA0_3252E0_name_4A) ? 0x54 : 0x2C, D_800FC880_FD480);            \
    MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 4, 0);                                                               \
    func_8005ACD0_5B8D0(&gPlayers[D_800FC880_FD480], 1);                                                             \
    mes = func_800797DC_7A3DC(0xFC, D_800F8C5C_F985C);                                                               \
    if (D_800F8C5C_F985C == D_80108CA0_3252E0_name_4A) {                                                             \
        func_800798F8_7A4F8(mes, 0x2C);                                                                              \
    } else {                                                                                                         \
        func_800798F8_7A4F8(mes, 0x54);                                                                              \
    }                                                                                                                \
    MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 5, 0);                                                               \
    func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 2);                                                             \
    func_800691FC_69DFC(6, gPlayers[D_800FC880_FD480].character);                                                    \
    PD_WAIT_MESSAGE();                                                                                               \
    finished = TRUE

/* NON_MATCHING: masked 201, registers and block layout, same logic: as 44's func_80102D00 the
   referee's drop swaps f0/f2; GCC hoists the sprite-position bases in the setup loop; the round
   outcome test (D_80108CD8 1-3) sits after the hands' block in retail; the time-out switch and
   the strike's alpha setup are scheduled differently. */
#ifdef NON_MATCHING
/* The duel scene's flow (44's func_80102D00 with a rock-paper-scissors duel): duelists and the
   referee walk in, the opponent and the stake are chosen; then rounds until one is decided: the
   title and hand sprites drop, both pick a hand (func_80106ED8/func_80107224), the two hands
   (D_80108F68[hand * 2 + side]) rise; the winning hand strikes the losing one (which spins away,
   func_80108540) or, on a draw, both sink and the round is replayed. If neither picks in time
   both stakes are returned; if only one picks, that one wins. The winner takes both stakes. */
void func_80102CA0_31F2E0_name_4A(void) {
    s16 hands[3] = { 0, 2, 6 };
    u32 list0[5] = { 4, 0x20000, 0x20003, 0x20005, 0x20008 };
    u32 list1[5] = { 4, 0x70000, 0x7004E, 0, 0x70055 };
    u32 list2[5] = { 4, 0x8003D, 0x80048, 0, 0x80044 };
    u32* lists[3] = { list0, list1, list2 };
    s32 winSide = 0;
    s32 loseSide = 0;
    s16 mdl[3];
    ModelPathWork* work[4];
    Vec pos[2];
    s32 files[3] = { 0xA021F, 0xA021E, 0xA021D };
    f32 angles[2] = { 30.0f, -30.0f };
    u32 motions[3] = { 2, 0x800A7, 0x800AA };
    s16 sounds[3] = { 0x411, 0x410, 0x412 };
    MBModel* model;
    s32 finished;
    s32 rounds;
    s16 mes;
    u16 done;
    s32 layout;
    s32 alpha;
    s32 angle;
    s32 frame;
    f32 y;
    f32 scale;
    s32 i;

    func_80050E00_51A00(0x26);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 4; i++) {
        if (D_80108CA8_3252E8_name_4A[i] != 0) {
            MBPlayerModelCreate(i, D_80108A20_325060_name_4A[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 1, 0);
            PLAYER_MODEL(i)->pos.x = -1000.0f;
            PLAYER_MODEL(i)->pos.y = 0.0f;
            PLAYER_MODEL(i)->pos.z = 700.0f;
            gPlayers[i].flags |= 2;
            MBMotionSet(PLAYER_MODEL(i), 1, 1);
            func_80043DAC_449AC(PLAYER_MODEL(i));
        }
    }
    D_80108F58_325598_name_4A = MBModelFileCreate(0x800A6, 0xD, 1.0f, 1.0f, motions);
    func_8005AB50_5B750(D_80108F58_325598_name_4A, 1, 0xB, 0x800AD);
    func_80056658_57258(&D_80108F58_325598_name_4A->pos, &D_80108A3C_32507C_name_4A, &D_80108F58_325598_name_4A->rot);
    D_80108F58_325598_name_4A->pos.x = D_80108A3C_32507C_name_4A.x;
    D_80108F58_325598_name_4A->pos.y = 0.0f;
    D_80108F58_325598_name_4A->pos.z = D_80108A3C_32507C_name_4A.z;
    if (D_80108F54_325594_name_4A == 0) {
        D_80108F58_325598_name_4A->jumpY = D_80108A3C_32507C_name_4A.y;
        D_80108F58_325598_name_4A->jumpVel = 7.5f;
        D_80108F58_325598_name_4A->jumpAccel = 0.0f;
        D_80108F5C_32559C_name_4A = MBModelFileCreate(0xA019D, 0xD, 1.0f, 1.0f, NULL);
        D_80108F5C_32559C_name_4A->pos.x = D_80108A3C_32507C_name_4A.x;
        D_80108F5C_32559C_name_4A->pos.y = 0.0f;
        D_80108F5C_32559C_name_4A->pos.z = D_80108A3C_32507C_name_4A.z;
        D_80108F5C_32559C_name_4A->jumpY = D_80108A3C_32507C_name_4A.y;
        D_80108F5C_32559C_name_4A->jumpVel = 7.5f;
        D_80108F5C_32559C_name_4A->jumpAccel = 0.0f;
    }
    /* the hand bases, the hand sprites and the title sprite */
    for (i = 0; i < 2; i++) {
        D_80108F60_3255A0_name_4A[i] = func_80043510_44110(0xE, NULL);
        D_80108F60_3255A0_name_4A[i]->pos.x = D_80108AC0_325100_name_4A[i].x;
        D_80108F60_3255A0_name_4A[i]->pos.y = 0.0f;
        D_80108F60_3255A0_name_4A[i]->pos.z = D_80108AC0_325100_name_4A[i].z;
        D_80108F60_3255A0_name_4A[i]->scale.y = 0.0f;
        MBModelDispOff(D_80108F60_3255A0_name_4A[i]);
    }
    D_80108F9C_3255DC_name_4A = func_8001A2F8_1AEF8(0xA0222);
    for (i = 0; i < 2; i++) {
        D_80108FA0_3255E0_name_4A[i] = func_8001AAAC_1B6AC(D_80108F9C_3255DC_name_4A, 1, 1);
        D_80108FA8_3255E8_name_4A[i] = D_80108ADC_32511C_name_4A[i * 2];
        D_80108FB0_3255F0_name_4A[i] = D_80108ADE_32511E_name_4A[i * 2];
        espPosSet(D_80108FA0_3255E0_name_4A[i], D_80108FA8_3255E8_name_4A[i], D_80108FB0_3255F0_name_4A[i]);
        func_8001A788_1B388(D_80108FA0_3255E0_name_4A[i], 0xF000);
    }
    D_80108F90_3255D0_name_4A = func_8001A2F8_1AEF8(0xA0221);
    D_80108F92_3255D2_name_4A = func_8001AAAC_1B6AC(D_80108F90_3255D0_name_4A, 1, 1);
    D_80108F94_3255D4_name_4A = D_80108AD8_325118_name_4A[0][0];
    D_80108F98_3255D8_name_4A = D_80108AD8_325118_name_4A[0][1];
    espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
    func_8001A788_1B388(D_80108F92_3255D2_name_4A, 0xF000);
    /* per hand: the model for each side and its strike effect */
    for (i = 0; i < 3; i++) {
        D_80108F68_3255A8_name_4A[i * 2] = func_80043510_44110((u8)hands[i], lists[i]);
        func_80029F2C_2AB2C(*D_80108F68_3255A8_name_4A[i * 2]->obj->model, 0);
        D_80108F68_3255A8_name_4A[i * 2]->pos.x = 0.0f;
        D_80108F68_3255A8_name_4A[i * 2]->pos.y = 0.0f;
        D_80108F68_3255A8_name_4A[i * 2]->pos.z = 600.0f;
        MBModelDispOff(D_80108F68_3255A8_name_4A[i * 2]);
        D_80108F68_3255A8_name_4A[i * 2]->scale.x = 1.2f;
        D_80108F68_3255A8_name_4A[i * 2]->scale.y = 1.2f;
        D_80108F68_3255A8_name_4A[i * 2]->scale.z = 1.2f;
        D_80108F68_3255A8_name_4A[i * 2 + 1] = MBModelParamCreate(D_80108F68_3255A8_name_4A[i * 2]);
        func_80029F2C_2AB2C(*D_80108F68_3255A8_name_4A[i * 2 + 1]->obj->model, 0);
        D_80108F68_3255A8_name_4A[i * 2 + 1]->pos.x = 0.0f;
        D_80108F68_3255A8_name_4A[i * 2 + 1]->pos.y = 0.0f;
        D_80108F68_3255A8_name_4A[i * 2 + 1]->pos.z = 600.0f;
        MBModelDispOff(D_80108F68_3255A8_name_4A[i * 2 + 1]);
        mdl[i] = LoadFormFile(files[i], 0x689);
        func_8002D124_2DD24(mdl[i]);
        D_80108F68_3255A8_name_4A[i * 2 + 1]->scale.x = 1.2f;
        D_80108F68_3255A8_name_4A[i * 2 + 1]->scale.y = 1.2f;
        D_80108F68_3255A8_name_4A[i * 2 + 1]->scale.z = 1.2f;
    }
    for (i = 0; i < 2; i++) {
        D_80108F80_3255C0_name_4A[i] = LoadFormFile(0xA020D, 0x289);
        func_80029714_2A314(D_80108F80_3255C0_name_4A[i], D_80108AC0_325100_name_4A[i].x, 120.0f, D_80108AC0_325100_name_4A[i].z + 250.0f);
        func_8002D124_2DD24(D_80108F80_3255C0_name_4A[i]);
        func_8002D0A0_2DCA0(D_80108F80_3255C0_name_4A[i], 0x80);
        D_80108F84_3255C4_name_4A[i] = LoadFormFile(0xA020E, 0x699);
        func_80029714_2A314(D_80108F84_3255C4_name_4A[i], D_80108AC0_325100_name_4A[i].x, 0.0f, D_80108AC0_325100_name_4A[i].z - 250.0f);
    }
    D_800FC834_FD434[D_80108F84_3255C4_name_4A[0]].pos.x = D_80108AC0_325100_name_4A[0].x - 50.0f;
    D_800FC834_FD434[D_80108F84_3255C4_name_4A[1]].pos.x = D_80108AC0_325100_name_4A[1].x + 50.0f;
    D_800FC834_FD434[D_80108F80_3255C0_name_4A[0]].pos.x = D_80108AC0_325100_name_4A[0].x + 35.0f;
    D_800FC834_FD434[D_80108F80_3255C0_name_4A[1]].pos.x = D_80108AC0_325100_name_4A[1].x - 35.0f;
    PlayMusic(0x25);
    InitFadeIn(0, 0x10);
    if (D_80108F54_325594_name_4A == 0) {
        /* the referee drops in with his hat */
        goto drop;
    fall:
        HuPrcVSleep();
    drop:
        D_80108F5C_32559C_name_4A->jumpY = D_80108F58_325598_name_4A->jumpY;
        D_80108F58_325598_name_4A->jumpY -= D_80108F58_325598_name_4A->jumpVel;
        if (!(D_80108F58_325598_name_4A->jumpY <= D_80108F58_325598_name_4A->pos.y)) {
            goto fall;
        }
        D_80108F58_325598_name_4A->jumpY = D_80108F58_325598_name_4A->pos.y;
        func_80106270_3228B0_name_4A();
        layout = (D_80108CB8_3252F8_name_4A == 4) ? 0 : -1;
        if (D_80108CB8_3252F8_name_4A == 3) {
            layout = 6;
        }
        if (layout != -1) {
            /* three or four players: the challenger picks the opponent */
            func_80105DB8_3223F8_name_4A(layout);
            PD_WAIT_STEP();
            PlaySound(0xE8);
            omAddPrcObj(func_80106390_3229D0_name_4A, 0x12, 0, 0);
            D_80108C80_3252C0_name_4A = 0;
            PD_WAIT_STEP();
            func_80105DB8_3223F8_name_4A(1);
            PD_WAIT_STEP();
            func_80105DB8_3223F8_name_4A(2);
            PD_WAIT_STEP();
        } else {
            func_80105DB8_3223F8_name_4A(7);
            PD_WAIT_STEP();
        }
        MBVsSprCreateY(160.0f, 90.0f);
        HuPrcSleep(10);
        D_80108A38_325078_name_4A = 1;
        func_80105DB8_3223F8_name_4A(3);
        PD_WAIT_STEP();
        omAddPrcObj(func_8010665C_322C9C_name_4A, 0x12, 0, 0);
        D_80108C80_3252C0_name_4A = 0;
        PD_WAIT_STEP();
        func_80105DB8_3223F8_name_4A(4);
        MBVsSprKill();
        PD_WAIT_STEP();
    }
    /* the duelists walk to their marks */
    PLAYER_MODEL(D_80108CA0_3252E0_name_4A)->pos.x = -400.0f;
    PLAYER_MODEL(D_80108CA4_3252E4_name_4A)->pos.x = 400.0f;
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 0, 0, 5, 2);
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 15.0f, 1, D_80108A78_3250B8_name_4A);
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 0, 0, 5, 2);
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 15.0f, 1, D_80108A84_3250C4_name_4A);
    D4A_WAIT_PATHS();
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 2, 0, 5, 2);
    /* the referee walks to the middle and explains */
    work[0] = func_8005A718_5B318(D_80108F58_325598_name_4A, 30.0f, 1, D_80108A54_325094_name_4A);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    model = D_80108F58_325598_name_4A;
    model->rot.x = __sinf(0.34906584f); /* 20 degrees */
    model = D_80108F58_325598_name_4A;
    model->rot.y = 0.0f;
    model->rot.z = __cosf(0.34906584f);
    D_80108F58_325598_name_4A->obj->rot.z = 20.0f;
    PlaySound(0xE8);
    D4A_MESSAGE(0x220, 90, 47, 2);
    D_80108F58_325598_name_4A->rot.x = HuMathSin(0.0f);
    D_80108F58_325598_name_4A->rot.y = 0.0f;
    D_80108F58_325598_name_4A->rot.z = func_800B7890_B8490(D_80108F58_325598_name_4A->rot.y);
    D_80108F58_325598_name_4A->obj->rot.z = 0.0f;
    work[0] = func_8005A718_5B318(D_80108F58_325598_name_4A, 30.0f, 1, D_80108A48_325088_name_4A);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    D_80108F58_325598_name_4A->rot.x = HuMathSin(0.0f);
    D_80108F58_325598_name_4A->rot.y = 0.0f;
    D_80108F58_325598_name_4A->rot.z = func_800B7890_B8490(D_80108F58_325598_name_4A->rot.y);
    HuPrcSleep(15);
    finished = FALSE;
    rounds = 0;
    do {
        omAddPrcObj(func_801080E8_324728_name_4A, 0x12, 0, 0);
        D4A_MESSAGE(0x221, 85, 70, 0);
        if (rounds == 0) {
            omAddPrcObj(func_80108394_3249D4_name_4A, 0x12, 0, 0);
        }
        MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 0, 0, 5, 2);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 15.0f, 1, &D_80108A90_3250D0_name_4A[0]);
        MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 0, 0, 5, 2);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 15.0f, 1, &D_80108A90_3250D0_name_4A[1]);
        D4A_WAIT_PATHS();
        MBMotionShiftSet(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), 2, 0, 5, 2);
        HuVecCopyXYZ(&pos[0], D_80108AC0_325100_name_4A[0].x, 0.0f, D_80108AC0_325100_name_4A[0].z);
        HuVecCopyXYZ(&pos[1], D_80108AC0_325100_name_4A[1].x, 0.0f, D_80108AC0_325100_name_4A[1].z);
        func_800446B4_452B4(PLAYER_MODEL(D_80108CA0_3252E0_name_4A), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_80108CA4_3252E4_name_4A), &pos[1], 10);
        HuPrcSleep(10);
        func_8008CE5C_8DA5C();
        func_800691FC_69DFC(0);
        PD_WAIT_MESSAGE();
        HuPrcSleep(18);
        /* the hands */
        D_80108C80_3252C0_name_4A = 0;
        D_80108CD8_325318_name_4A = 0;
        func_80106ED8_323518_name_4A();
        while (D_80108CD8_325318_name_4A == 0) {
            HuPrcVSleep();
        }
        if (D_80108F54_325594_name_4A != 0 &&
            (D_80108CD8_325318_name_4A == 4 || D_80108CD8_325318_name_4A == 5 || D_80108CD8_325318_name_4A == 6)) {
            func_800794A8_7A0A8(60);
        }
        omAddPrcObj(func_8010828C_3248CC_name_4A, 0x12, 0, 0);
        HuPrcSleep(60);
        if (D_80108CD8_325318_name_4A < 4) {
            if (D_80108CD8_325318_name_4A >= 2) {
                func_800691FC_69DFC(0xF);
                PD_WAIT_MESSAGE();
            }
        }
        switch (D_80108CD8_325318_name_4A) {
            case 4:
            case 5:
            case 6:
                /* time out */
                switch (D_80108CD8_325318_name_4A) {
                    case 4:
                        D_800FC880_FD480 = -1;
                        D_800F8C5C_F985C = -1;
                        break;
                    case 5:
                        D_800FC880_FD480 = D_80108CA0_3252E0_name_4A;
                        D_800F8C5C_F985C = D_80108CA4_3252E4_name_4A;
                        break;
                    case 6:
                        D_800FC880_FD480 = D_80108CA4_3252E4_name_4A;
                        D_800F8C5C_F985C = D_80108CA0_3252E0_name_4A;
                        break;
                }
                omAddPrcObj(func_80108468_324AA8_name_4A, 0x12, 0, 0);
                HuPrcSleep(30);
                if (D_80108F54_325594_name_4A == 0) {
                    func_80105DB8_3223F8_name_4A(2);
                }
                D4A_WALK_BACK(D_80108CA0_3252E0_name_4A, D_80108CA0_3252E0_name_4A);
                if (D_80108CD8_325318_name_4A == 4) {
                    /* neither picked: both stakes go back */
                    if (D_80108F54_325594_name_4A == 0) {
                        MBMotionShiftSet(D_80108F58_325598_name_4A, 1, 0, 5, 0);
                        HuPrcSleep(23);
                        MBMotionShiftSet(D_80108F58_325598_name_4A, 0, 0, 20, 2);
                        func_80088640_89240();
                        D_80102708_103308 = 1;
                        PlaySound(0xE8);
                        D4A_MESSAGE(0x216, 90, 70, 0);
                        func_800614B4_620B4(D_80108CA0_3252E0_name_4A, D_80108C84_3252C4_name_4A);
                        func_8006135C_61F5C(D_80108CA4_3252E4_name_4A, D_80108C84_3252C4_name_4A, 0);
                        func_800794A8_7A0A8(30);
                        HuPrcSleep(30);
                    }
                    PlayMusic(0x57);
                    func_800691FC_69DFC(0x13);
                    PD_WAIT_MESSAGE();
                    finished = TRUE;
                }
                break;
            case 1:
            case 2:
                D_800FC880_FD480 = D_80108CA0_3252E0_name_4A;
                D_800F8C5C_F985C = D_80108CA4_3252E4_name_4A;
                D_80108FC0_325600_name_4A = D_80108CE0_325320_name_4A[0] * 2;
                D_80108FC4_325604_name_4A = D_80108CE0_325320_name_4A[1] * 2 + 1;
                winSide = 0;
                loseSide = 1;
                break;
            case 3:
                D_800FC880_FD480 = D_80108CA4_3252E4_name_4A;
                D_800F8C5C_F985C = D_80108CA0_3252E0_name_4A;
                D_80108FC0_325600_name_4A = D_80108CE0_325320_name_4A[1] * 2 + 1;
                D_80108FC4_325604_name_4A = D_80108CE0_325320_name_4A[0] * 2;
                winSide = 1;
                loseSide = 0;
                break;
        }
        if (D_80108CD8_325318_name_4A <= 0) {
        } else if (D_80108CD8_325318_name_4A < 4) {
            /* the two hands rise in front of the duelists */
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.x = D_80108AC0_325100_name_4A[winSide].x;
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.y = 0.0f;
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.z = D_80108AC0_325100_name_4A[winSide].z - 25.0f;
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.x = D_80108AC0_325100_name_4A[loseSide].x;
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.y = 0.0f;
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.z = D_80108AC0_325100_name_4A[loseSide].z - 25.0f;
            if (D_80108CE0_325320_name_4A[winSide] == 2) {
                D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->scale.x = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->scale.y = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->scale.z = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.z -= 25.0f;
            }
            MBModelDispOn(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]);
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->rot.x = HuMathSin(angles[winSide]);
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->rot.y = 0.0f;
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->rot.z = func_800B7890_B8490(angles[winSide]);
            if (D_80108CE0_325320_name_4A[loseSide] == 2) {
                D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.x = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.y = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.z = 0.7f;
                D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.z -= 25.0f;
            }
            MBModelDispOn(D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]);
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.x = HuMathSin(angles[loseSide]);
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.y = 0.0f;
            D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.z = func_800B7890_B8490(angles[loseSide]);
            y = 0.0f;
            for (i = 0; i < 15; i++) {
                y += 10.0f;
                D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.y = y;
                D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.y = y;
                HuPrcVSleep();
            }
            if (D_80108CD8_325318_name_4A != 1) {
                /* the winning hand strikes */
                MBMotionShiftSet(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A], 1, 0, 5, 0);
                func_8002CA14_2D614(1);
                HuPrcSleep(10);
                switch (D_80108CE0_325320_name_4A[winSide]) {
                    case 0:
                        func_8007975C_7A35C(0x103, D_800FC880_FD480);
                        break;
                    case 1:
                        func_8007975C_7A35C(0x105, D_800FC880_FD480);
                        break;
                    case 2:
                        func_8007975C_7A35C(0x123, D_800FC880_FD480);
                        break;
                }
                if (D_80108CE0_325320_name_4A[winSide] == 0) {
                    MBMotionShiftSet(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A], 2, 0, 5, 0);
                    func_8002CA14_2D614(2);
                    HuPrcSleep(15);
                } else {
                    HuPrcSleep(10);
                }
                PlaySound(sounds[D_80108CE0_325320_name_4A[winSide]]);
                func_800298A4_2A4A4(mdl[D_80108CE0_325320_name_4A[winSide]], 4, 0);
                alpha = 0xFF;
                func_80029714_2A314(mdl[D_80108CE0_325320_name_4A[winSide]],
                                    D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.x,
                                    D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.y + 75.0f,
                                    D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.z + 100.0f);
                scale = 2.6f;
                do {
                    scale -= 0.2f;
                    func_800297E8_2A3E8(mdl[D_80108CE0_325320_name_4A[winSide]], scale, scale, scale);
                    HuPrcVSleep();
                } while (scale > 1.0f);
                angle = 0;
                omVibrate(D_800F8C5C_F985C, 20, 0, 20);
                omAddPrcObj(func_80108540_324B80_name_4A, 0x12, 0, 0);
                frame = 0;
                while (alpha > 0) {
                    scale = HuMathSin(angle % 360) * 0.3f + 1.0f;
                    func_800297E8_2A3E8(mdl[D_80108CE0_325320_name_4A[winSide]], scale, scale, scale);
                    if (angle >= 540) {
                        alpha -= 8;
                        if (alpha < 0) {
                            alpha = 0;
                        }
                    }
                    func_8002D0A0_2DCA0(mdl[D_80108CE0_325320_name_4A[winSide]], alpha);
                    frame++;
                    angle += 20;
                    if (frame == 30) {
                        switch (D_80108CE0_325320_name_4A[loseSide]) {
                            case 0:
                                func_8007975C_7A35C(0x111, D_800F8C5C_F985C);
                                break;
                            case 1:
                                func_8007975C_7A35C(0x113, D_800F8C5C_F985C);
                                break;
                            case 2:
                                func_8007975C_7A35C(0x124, D_800F8C5C_F985C);
                                break;
                        }
                    }
                    HuPrcVSleep();
                }
                func_800298A4_2A4A4(mdl[D_80108CE0_325320_name_4A[winSide]], 4, 4);
            } else {
                /* a draw: both hands sink */
                HuPrcSleep(30);
                for (i = 0; i < 30; i++) {
                    y -= 5.0f;
                    D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.y = y;
                    D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->pos.y = y;
                    HuPrcVSleep();
                }
                MBModelDispOff(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]);
                MBModelDispOff(D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]);
            }
            if (D_80108F54_325594_name_4A == 0 && D_80108CD8_325318_name_4A != 1) {
                func_80105DB8_3223F8_name_4A(2);
            }
            D4A_WALK_BACK(D_800FC880_FD480, D_800F8C5C_F985C);
            if (D_80108CD8_325318_name_4A != 1) {
                func_800794A8_7A0A8(45);
                D4A_WIN(0x215);
            } else {
                /* a draw: once more */
                MBMotionShiftSet(D_80108F58_325598_name_4A, 1, 0, 5, 0);
                HuPrcSleep(23);
                MBMotionShiftSet(D_80108F58_325598_name_4A, 0, 0, 20, 2);
                PlaySound(0xE8);
                func_80088640_89240();
                D_80102708_103308 = 1;
                D_80108C9C_3252DC_name_4A = D_800FC880_FD480;
                D4A_MESSAGE(0x222, 90, 70, 3);
                rounds++;
            }
        } else if (D_80108CD8_325318_name_4A < 7) {
            if (D_80108CD8_325318_name_4A >= 5) {
                /* only one picked a hand in time: that one wins */
                D_80108F50_325590_name_4A = PlaySound(0x4B5);
                func_800794A8_7A0A8(45);
                D4A_WIN(0x223);
            }
        }
    } while (!finished);
    HuPrcSleep(8);
    func_80106188_3227C8_name_4A();
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108AF0_325130_name_4A[2] = { 0x00000002, 0x00060000 };

__asm__(".section .rodata");
const u32 D_80108AF8_325138_name_4A[5] = { 0x00000004, 0x00020000, 0x00020003, 0x00020005, 0x00020008 };

__asm__(".section .rodata");
const u32 D_80108B0C_32514C_name_4A[5] = { 0x00000004, 0x00070000, 0x0007004E, 0x00000000, 0x00070055 };

__asm__(".section .rodata");
const u32 D_80108B20_325160_name_4A[5] = { 0x00000004, 0x0008003D, 0x00080048, 0x00000000, 0x00080044 };

__asm__(".section .rodata");
const u32 D_80108B34_325174_name_4A[3] = { 0x000A021F, 0x000A021E, 0x000A021D };

__asm__(".section .rodata");
const u32 D_80108B40_325180_name_4A[3] = { 0x00000002, 0x000800A7, 0x000800AA };

__asm__(".section .rodata");
const u32 D_80108B4C_32518C_name_4A[2] = { 0x04110410, 0x04120000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_name/31EE40", func_80102CA0_31F2E0_name_4A);

/* With func_80102CA0 as INCLUDE_ASM, GCC still believes it is in .rodata here (the asm switched to
   .text): switch for real, so the string literals below land in .rodata. */
__asm__(".section .rodata");
#endif

/* The duel's message window (42's func_80104B88): variant 1 names the opponent, 3 the stake and
   the opponent; 2 waits for A (the CPU script presses it when both duelists are CPUs), the others
   close at once. */
void func_801057C8_321E08_name_4A(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_80108C90_3252D0_name_4A == 1) {
        sprintf(num, "%c%c", 0x18, gPlayers[D_80108C9C_3252DC_name_4A].character);
        func_8008D974_8E574(num, 0);
    }
    if (D_80108C90_3252D0_name_4A == 3) {
        sprintf(num, "%d", D_80108C84_3252C4_name_4A);
        sprintf(name, "%c%c", 0x18, gPlayers[D_80108C9C_3252DC_name_4A].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    func_8008DACC_8E6CC(1, size, D_80108C94_3252D4_name_4A);
    win = func_80105B90_3221D0_name_4A((s16)D_80108C88_3252C8_name_4A, (s16)D_80108C8C_3252CC_name_4A, size[0], size[1], 0, 0, 200);
    if (D_80108C98_3252D8_name_4A & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80108C90_3252D0_name_4A == 3) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80108C94_3252D4_name_4A, -1, -1);
    func_80057A78_58678((s16)win, D_80108CA0_3252E0_name_4A, D_80108CA4_3252E4_name_4A);
    if (D_80108C90_3252D0_name_4A == 2 && (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) && (gPlayers[D_80108CA4_3252E4_name_4A].flags & 1)) {
        func_80107918_323F58_name_4A(0, 0, 0);
    }
    while (TRUE) {
        switch (D_80108C90_3252D0_name_4A) {
            case 0:
            case 1:
            case 3:
                if (D_80108C98_3252D8_name_4A & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_80108C80_3252C0_name_4A = 1;
                omDelPrcObj(NULL);
                break;
            case 2:
                if ((gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) && (gPlayers[D_80108CA4_3252E4_name_4A].flags & 1)) {
                    btn = func_801080DC_32471C_name_4A();
                } else {
                    btn = func_80105CF8_322338_name_4A();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_80108C80_3252C0_name_4A = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_80105B90_3221D0_name_4A(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108CA4_3252E4_name_4A != -1) {
        mask = (1 << gPlayers[D_80108CA0_3252E0_name_4A].port) | (1 << gPlayers[D_80108CA4_3252E4_name_4A].port);
    } else {
        mask = 1 << gPlayers[D_80108CA0_3252E0_name_4A].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_name/31EE40", func_80105B90_3221D0_name_4A);
#endif

u16 func_80105CF8_322338_name_4A(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80108CA0_3252E0_name_4A].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80108CA0_3252E0_name_4A].port];
    }
    if (D_80108CA4_3252E4_name_4A != -1 && btn == 0) {
        if (!(gPlayers[D_80108CA4_3252E4_name_4A].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80108CA4_3252E4_name_4A].port];
        }
    }
    return btn;
}

void func_80105DB8_3223F8_name_4A(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108C80_3252C0_name_4A = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_801060F0_322730_name_4A);
    work = func_80027154_27D54(0x34, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108CA8_3252E8_name_4A[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108CA0_3252E0_name_4A) {
                if (i == D_80108CA4_3252E4_name_4A) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108CC0_325300_name_4A[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80108840_324E80_name_4A[layout].pos[slot][0] != -1) {
                status->xPos = D_80108840_324E80_name_4A[layout].pos[slot][0];
            }
            if (D_80108840_324E80_name_4A[layout].pos[slot][1] != -1) {
                status->yPos = D_80108840_324E80_name_4A[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80108840_324E80_name_4A[layout].frames - 1;
            if (D_80108840_324E80_name_4A[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80108840_324E80_name_4A[layout].pos[slot][2];
            }
            if (D_80108840_324E80_name_4A[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80108840_324E80_name_4A[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80108A38_325078_name_4A == 1) {
        status = &D_80101510_102110[D_80108CA0_3252E0_name_4A];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80108840_324E80_name_4A[layout].frames - 1;
    }
}

void func_801060F0_322730_name_4A(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108CA8_3252E8_name_4A[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108CB8_3252F8_name_4A) {
        D_80108C80_3252C0_name_4A = 1;
        omDelObj(obj);
    }
}

void func_80106188_3227C8_name_4A(void) {
    omAddObj(0x10, 0, 0, -1, func_801061C4_322804_name_4A);
    func_80069764_6A364(60);
}

void func_801061C4_322804_name_4A(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_80108F54_325594_name_4A != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_8010621C_32285C_name_4A;
    }
}

void func_8010621C_32285C_name_4A(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80106270_3228B0_name_4A(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80106300_322940_name_4A);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80106300_322940_name_4A(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108F5C_32559C_name_4A->scale.x += work->scaleSpeed;
    D_80108F5C_32559C_name_4A->scale.y += work->scaleSpeed;
    D_80108F5C_32559C_name_4A->scale.z += work->scaleSpeed;
    D_80108F5C_32559C_name_4A->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108F5C_32559C_name_4A);
        omDelObj(obj);
    }
}

void func_80106390_3229D0_name_4A(void) {
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
    win = func_80105B90_3221D0_name_4A(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108CB8_3252F8_name_4A - 1;
    if (D_80108CB8_3252F8_name_4A == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108CB8_3252F8_name_4A; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) {
        func_80107918_323F58_name_4A(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80105CF8_322338_name_4A();
        if (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) {
            btn = func_801080DC_32471C_name_4A();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108CC0_325300_name_4A[sel], 1) != 0) {
            PlaySound(2);
            D_80108C80_3252C0_name_4A = 1;
            D_80108CA4_3252E4_name_4A = D_80108CC0_325300_name_4A[sel];
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

/* The stake (as 3F's func_80105054): the starting amount comes from the turn (turns[] bands) and
   the poorer player's coins (stakes[]); right/left add or take 1, up/down 10, A accepts. Both
   duelists pay the stake as it changes. Retail quirk: at the 999 cap a further raise still takes
   the coin from both players. */
#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, "%d", stake);                                 \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

void func_8010665C_322C9C_name_4A(void) {
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

    turn = D_80108CD4_325314_name_4A;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80108CA0_3252E0_name_4A)->coins;
    coins2 = BoardPlayerGet(D_80108CA4_3252E4_name_4A)->coins;
    D_80108CDC_32531C_name_4A = coins1;
    if (coins2 < coins1) {
        D_80108CDC_32531C_name_4A = coins2;
    }
    i++;
    while (D_80108CDC_32531C_name_4A < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80108C84_3252C4_name_4A = D_80108CD0_325310_name_4A = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108CD0_325310_name_4A;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80105B90_3221D0_name_4A(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80108CA0_3252E0_name_4A);
    AdjustPlayerCoins(D_80108CA0_3252E0_name_4A, -D_80108C84_3252C4_name_4A);
    AdjustPlayerCoins(D_80108CA4_3252E4_name_4A, -D_80108C84_3252C4_name_4A);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) {
        func_80107918_323F58_name_4A(D_80108C84_3252C4_name_4A, D_80108CDC_32531C_name_4A, 3);
    }
    while (TRUE) {
        D_80108C84_3252C4_name_4A = stake;
        btn = ContDStkTrg[gPlayers[D_80108CA0_3252E0_name_4A].port];
        if (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) {
            btn = func_801080DC_32471C_name_4A();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80108C80_3252C0_name_4A = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80108CA0_3252E0_name_4A].coins > 0 && gPlayers[D_80108CA4_3252E4_name_4A].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108CA0_3252E0_name_4A, -1);
                AdjustPlayerCoins(D_80108CA4_3252E4_name_4A, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108CD0_325310_name_4A < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108CA0_3252E0_name_4A, 1);
                AdjustPlayerCoins(D_80108CA4_3252E4_name_4A, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108CD0_325310_name_4A) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108CA0_3252E0_name_4A, 10);
                AdjustPlayerCoins(D_80108CA4_3252E4_name_4A, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80108CA0_3252E0_name_4A].coins >= 10 && gPlayers[D_80108CA4_3252E4_name_4A].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108CA0_3252E0_name_4A, -10);
                AdjustPlayerCoins(D_80108CA4_3252E4_name_4A, -10);
            }
        }
        HuPrcVSleep();
    }
}

/* Start the hands (the process func_80107224): each duelist's hidden table of 5 x 30 frames gets
   a CPU-difficulty number of marked frames per row (3-6, 7-10, 9-12; difficulty 3 keeps the last
   count), a CPU duelist picks its hand at random, and the hand sprite is shown. */
/* NON_MATCHING: masked 17, registers and one hoist: retail keeps the side's table base in its own
   register (one more saved register, so the work pointer lives on the stack); GCC folds it into
   the address each time. */
#ifdef NON_MATCHING
void func_80106ED8_323518_name_4A(void) {
    omObjData* obj;
    D4AHandWork* work;
    s16* frame;
    s32 count;
    s32 player;
    s32 side;
    s32 row;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, func_80107224_323864_name_4A);
    work = obj->unk_50 = func_80027154_27D54(sizeof(D4AHandWork), 0x7918);
    D_80108CE0_325320_name_4A[0] = 0;
    D_80108CE0_325320_name_4A[1] = 0;
    count = 0;
    for (side = 0; side < 2; side++) {
        if (side == 0) {
            player = D_80108CA0_3252E0_name_4A;
        } else {
            player = D_80108CA4_3252E4_name_4A;
        }
        switch (gPlayers[player].cpu_difficulty) {
            case 0:
                count = (rand8() & 3) + 3;
                break;
            case 1:
                count = (rand8() & 3) + 7;
                break;
            case 2:
                count = (rand8() & 3) + 9;
                break;
        }
        for (row = 0; row < 5; row++) {
            for (i = 0; i < 30; i++) {
                D_80108CF8_325338_name_4A[side][row * 30 + i] = 0;
            }
            for (i = 0; i < count; i++) {
                do {
                    frame = &D_80108CF8_325338_name_4A[side][row * 30 + (u8)(rand8() % 30)];
                } while (*frame != 0);
                *frame = 1;
            }
        }
        espDispOn(D_80108F92_3255D2_name_4A);
    }
    work->timer = 0;
    work->unk28 = 5;
    work->unk0 = 0;
    work->picked[0] = 0;
    work->picked[1] = 0;
    if (gPlayers[D_80108CA0_3252E0_name_4A].flags & 1) {
        D_80108CE0_325320_name_4A[0] = (u8)(rand8() % 3);
    }
    if (gPlayers[D_80108CA4_3252E4_name_4A].flags & 1) {
        D_80108CE0_325320_name_4A[1] = (u8)(rand8() % 3);
    }
    D_80108FB8_3255F8_name_4A[0] = -1;
    D_80108FB8_3255F8_name_4A[1] = -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_name/31EE40", func_80106ED8_323518_name_4A);
#endif

/* The hands: a person picks with A, B or Z (0, 1, 2), a CPU after 30 frames; "READY" shows over
   each side that picked. 0 beats 2, otherwise the higher hand wins: D_80108CD8 is 1 for a draw, 2
   when the challenger wins, 3 when the opponent wins; after 900 frames 5 (the opponent did not
   pick), 6 (the challenger did not) or 4 (neither). The countdown starts at frame 750. */
void func_80107224_323864_name_4A(omObjData* obj) {
    D4AHandWork* work = obj->unk_50;

    if (!(gPlayers[D_80108CA0_3252E0_name_4A].flags & 1)) {
        if (work->picked[0] == 0) {
            switch (ContBtnTrg[gPlayers[D_80108CA0_3252E0_name_4A].port]) {
                case 0x8000:
                    D_80108CE0_325320_name_4A[0] = 0;
                    goto picked0;
                case 0x4000:
                    D_80108CE0_325320_name_4A[0] = 1;
                    goto picked0;
                case 0x2000:
                    D_80108CE0_325320_name_4A[0] = 2;
                    goto picked0;
            }
        }
    } else if (work->timer == 30) {
    picked0:
        work->picked[0]++;
        D_80108FB8_3255F8_name_4A[0] = func_800691FC_69DFC(9, "\x82\x71\x82\x64\x82\x60\x82\x63\x82\x78", 100, 96, 1.0, 1.0, 0);
        func_800695D8_6A1D8(D_80108FB8_3255F8_name_4A[0], -1);
    }
    if (!(gPlayers[D_80108CA4_3252E4_name_4A].flags & 1)) {
        if (work->picked[1] == 0) {
            switch (ContBtnTrg[gPlayers[D_80108CA4_3252E4_name_4A].port]) {
                case 0x8000:
                    D_80108CE0_325320_name_4A[1] = 0;
                    goto picked1;
                case 0x4000:
                    D_80108CE0_325320_name_4A[1] = 1;
                    goto picked1;
                case 0x2000:
                    D_80108CE0_325320_name_4A[1] = 2;
                    goto picked1;
            }
        }
    } else if (work->timer == 30) {
    picked1:
        work->picked[1]++;
        D_80108FB8_3255F8_name_4A[1] = func_800691FC_69DFC(9, "\x82\x71\x82\x64\x82\x60\x82\x63\x82\x78", 220, 96, 1.0, 1.0, 0);
        func_800695D8_6A1D8(D_80108FB8_3255F8_name_4A[1], -1);
    }
    if (work->picked[0] != 0 && work->picked[1] != 0) {
        if (D_80108CE0_325320_name_4A[0] == 0 && D_80108CE0_325320_name_4A[1] == 2) {
            D_80108CD8_325318_name_4A = 2;
        } else if (D_80108CE0_325320_name_4A[0] == 2 && D_80108CE0_325320_name_4A[1] == 0) {
            D_80108CD8_325318_name_4A = 3;
        } else if (D_80108CE0_325320_name_4A[0] > D_80108CE0_325320_name_4A[1]) {
            D_80108CD8_325318_name_4A = 2;
        } else if (D_80108CE0_325320_name_4A[0] == D_80108CE0_325320_name_4A[1]) {
            D_80108CD8_325318_name_4A = 1;
        } else {
            D_80108CD8_325318_name_4A = 3;
        }
        work->timer = 30;
        obj->func_ptr = func_801075B0_323BF0_name_4A;
    }
    if (++work->timer == 750) {
        omAddPrcObj(func_80108780_324DC0_name_4A, 0x12, 0, 0);
    }
    if (work->timer == 900) {
        if (work->picked[0] != 0) {
            D_80108CD8_325318_name_4A = 5;
        } else if (work->picked[1] != 0) {
            D_80108CD8_325318_name_4A = 6;
        } else {
            D_80108CD8_325318_name_4A = 4;
        }
        work->timer = 30;
        obj->func_ptr = func_801075B0_323BF0_name_4A;
    }
}

/* After the hands: 30 frames later the "READY" messages close and the object ends. */
void func_801075B0_323BF0_name_4A(omObjData* obj) {
    D4AHandWork* work = obj->unk_50;

    if (--work->timer == 0) {
        if (D_80108FB8_3255F8_name_4A[0] != -1) {
            func_80069654_6A254(D_80108FB8_3255F8_name_4A[0]);
        }
        if (D_80108FB8_3255F8_name_4A[1] != -1) {
            func_80069654_6A254(D_80108FB8_3255F8_name_4A[1]);
        }
        omDelObj(obj);
    }
}

s32 func_8010762C_323C6C_name_4A(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 0 && gPlayers[D_80108CC0_325300_name_4A[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 1 && gPlayers[D_80108CC0_325300_name_4A[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 2 && gPlayers[D_80108CC0_325300_name_4A[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 3 && gPlayers[D_80108CC0_325300_name_4A[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

#define PD_ABS(x) ((x) < 0 ? -(x) : (x))
/* NON_MATCHING: masked 36, the same logic as 42's/44's twin (also NON_MATCHING) with 4A's changes
   (the first rank pass runs over three opponents; the stake row is (rank & 3) << 3 | (opponent's
   rank & 3) << 1 | close in stars). GCC reuses n's register (known 0) for the rank passes' first
   loop test where retail compares D_80108CB8 - 1 with zero, and keeps the star difference in a1. */
#ifdef NON_MATCHING
void func_80107918_323F58_name_4A(s32 cur, s32 target, s32 mode) {
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
    s32 unused[7];
    omObjData* obj;
    PdCpuInput* work;
    s32 diff;
    s32 row;
    s32 n;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, func_80107F3C_32457C_name_4A);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108CF0_325330_name_4A = 0;
    if (mode == 2) {
        if (gPlayers[D_80108CA0_3252E0_name_4A].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < 3; i++) {
                if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108CC0_325300_name_4A[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108CC0_325300_name_4A[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108CB8_3252F8_name_4A - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108CC0_325300_name_4A[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_8010762C_323C6C_name_4A();
            }
        } else {
            work->target = func_8010762C_323C6C_name_4A();
        }
    }
    if (mode == 3) {
        row = (func_80059FD0_5ABD0(D_80108CA0_3252E0_name_4A) & 3) << 3;
        row |= (func_80059FD0_5ABD0(D_80108CA4_3252E4_name_4A) & 3) << 1;
        diff = PD_ABS(gPlayers[D_80108CA0_3252E0_name_4A].stars - gPlayers[D_80108CA4_3252E4_name_4A].stars);
        if (diff < 2) {
            row |= 1;
        }
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_80108CDC_32531C_name_4A / 100;
        if (work->target < D_80108CD0_325310_name_4A) {
            work->target = D_80108CD0_325310_name_4A;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108BE0_325220_name_4A[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_80108C60_3252A0_name_4A[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_80108C70_3252B0_name_4A[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_name/31EE40", func_80107918_323F58_name_4A);
#endif

void func_80107F3C_32457C_name_4A(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108CF0_325330_name_4A = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108CF0_325330_name_4A = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108CF0_325330_name_4A = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108CF0_325330_name_4A = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108CF0_325330_name_4A = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108CF0_325330_name_4A = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_80108C84_3252C4_name_4A;
                if (work->cur == work->target) {
                    D_80108CF0_325330_name_4A = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108CF0_325330_name_4A = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108CF0_325330_name_4A = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108CF0_325330_name_4A = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108CF0_325330_name_4A = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_801080DC_32471C_name_4A(void) {
    return D_80108CF0_325330_name_4A;
}

/* The sprites drop in: the title sprite and the two hand sprites move down 4 a frame for 30
   frames, then the title bounces. */
void func_801080E8_324728_name_4A(void) {
    s32 i;
    s32 j;

    D_80108F98_3255D8_name_4A = D_80108AD8_325118_name_4A[0][1];
    for (i = 0; i < 30; i++) {
        espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
        D_80108F98_3255D8_name_4A += 4;
        for (j = 0; j < 2; j++) {
            espPosSet(D_80108FA0_3255E0_name_4A[j], D_80108FA8_3255E8_name_4A[j], D_80108FB0_3255F0_name_4A[j]);
            D_80108FB0_3255F0_name_4A[j] += 4;
        }
        HuPrcVSleep();
    }
    espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
    D_80108F98_3255D8_name_4A += 4;
    HuPrcVSleep();
    espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
    D_80108F98_3255D8_name_4A -= 4;
    HuPrcVSleep();
    espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
    D_80108F98_3255D8_name_4A += 4;
    HuPrcVSleep();
    espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
    omDelPrcObj(NULL);
}

/* The sprites leave: up 6 a frame for 20 frames; the title goes back to its start. */
void func_8010828C_3248CC_name_4A(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 20; i++) {
        espPosSet(D_80108F92_3255D2_name_4A, D_80108F94_3255D4_name_4A, D_80108F98_3255D8_name_4A);
        D_80108F98_3255D8_name_4A -= 6;
        for (j = 0; j < 2; j++) {
            espPosSet(D_80108FA0_3255E0_name_4A[j], D_80108FA8_3255E8_name_4A[j], D_80108FB0_3255F0_name_4A[j]);
            D_80108FB0_3255F0_name_4A[j] -= 6;
        }
        HuPrcVSleep();
    }
    espPosSet(D_80108F92_3255D2_name_4A, D_80108AD8_325118_name_4A[0][0], D_80108AD8_325118_name_4A[0][1]);
    omDelPrcObj(NULL);
}

/* The two hand models appear and stretch up (scale.y = 0.8 sin(3t)) over 30 frames. */
void func_80108394_3249D4_name_4A(void) {
    f32 s;
    s32 i;
    s32 j;

    for (j = 0; j < 2; j++) {
        MBModelDispOn(D_80108F60_3255A0_name_4A[j]);
    }
    for (i = 0; i < 30; i++) {
        s = HuMathSin(i * 3) * 0.8f;
        for (j = 0; j < 2; j++) {
            D_80108F60_3255A0_name_4A[j]->scale.y = s;
        }
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

/* ... and shrink away again (0.8 sin(3t + 90)), then hide. */
void func_80108468_324AA8_name_4A(void) {
    f32 s;
    s32 i;
    s32 j;

    for (i = 0; i < 30; i++) {
        s = HuMathSin(i * 3 + 90) * 0.8f;
        for (j = 0; j < 2; j++) {
            D_80108F60_3255A0_name_4A[j]->scale.y = s;
        }
        HuPrcVSleep();
    }
    for (j = 0; j < 2; j++) {
        MBModelDispOff(D_80108F60_3255A0_name_4A[j]);
    }
    omDelPrcObj(NULL);
}

/* The loser's hand model (D_80108F68[D_80108FC4]) spins and shrinks to nothing over 60 frames;
   from frame 45 the winner's drops away (sound 0x4B5) and is hidden at frame 59. */
void func_80108540_324B80_name_4A(void) {
    f32 step;
    f32 angle;
    f32 y;
    s32 i;

    if (D_80108CE0_325320_name_4A[D_80108FC4_325604_name_4A] == 0) {
        MBMotionShiftSet(D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A], 3, 0, 5, 2);
    } else {
        MBMotionShiftSet(D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A], 3, 0, 5, 0);
    }
    HuPrcSleep(30);
    step = D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.x / 60.0f;
    angle = 0.0f;
    y = 150.0f;
    for (i = 0; i < 60.0f; i++) {
        angle += 30.0f;
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.x = HuMathSin(angle);
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.y = 0.0f;
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->rot.z = func_800B7890_B8490(angle);
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.x -= step;
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.y -= step;
        D_80108F68_3255A8_name_4A[D_80108FC4_325604_name_4A]->scale.z -= step;
        if (i >= 45 && i < 60) {
            if (i == 45) {
                MBMotionShiftSet(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A], 0, 0, 5, 2);
                D_80108F50_325590_name_4A = PlaySound(0x4B5);
            }
            y -= 10.0f;
            D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]->pos.y = y;
            if (i == 59) {
                MBModelDispOff(D_80108F68_3255A8_name_4A[D_80108FC0_325600_name_4A]);
            }
        }
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    omDelPrcObj(NULL);
}

/* The five-second countdown (42's func_80108DB8 tail): ends early once the step flag is set. */
void func_80108780_324DC0_name_4A(void) {
    s32 timer;
    s32 secs;

    secs = 5;
    timer = 30;
    func_8006961C_6A21C(func_800691FC_69DFC(10, 5, 160, 28), 154.0f, 28.0f);
    PlaySound(8);
    do {
        if (--timer == 0) {
            timer = 30;
            secs--;
        }
        func_8006D4D0_6E0D0(secs);
        if (D_80108C80_3252C0_name_4A != 0) {
            func_8006D518_6E118();
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    } while (secs > 0);
    func_8006D518_6E118();
    omDelPrcObj(NULL);
}
