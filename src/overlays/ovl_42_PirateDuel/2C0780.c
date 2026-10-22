#include "ovl_42.h"

void func_80102800_2C0780_PirateDuel(void) {
    omInitObjMan(30, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8010298C_2C090C_PirateDuel();
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
    omAddPrcObj(func_80102CA0_2C0C20_PirateDuel, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102BC0_2C0B40_PirateDuel);
}

void func_8010298C_2C090C_PirateDuel(void) {
    s32 bits;
    s32 i;

    D_80109D94_2C7D14_PirateDuel = -1;
    D_80109D88_2C7D08_PirateDuel = 0;
    D_8010A060_2C7FE0_PirateDuel = 0;
    if (_CheckFlag(0x17) == 0) {
        D_8010A060_2C7FE0_PirateDuel = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_8010A060_2C7FE0_PirateDuel = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_8010A060_2C7FE0_PirateDuel = 1;
        }
    }
    D_80109D90_2C7D10_PirateDuel = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80109D90_2C7D10_PirateDuel++;
    }
    D_80109DA8_2C7D28_PirateDuel = 1;
    D_80109D98_2C7D18_PirateDuel[i] = 1;
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
            D_80109DA8_2C7D28_PirateDuel++;
            D_80109D98_2C7D18_PirateDuel[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80109DE0_2C7D60_PirateDuel[i] = 0;
        D_8010A098_2C8018_PirateDuel[i] = 0;
    }
    if (D_80109DA8_2C7D28_PirateDuel == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80109D98_2C7D18_PirateDuel[i] == 1 && i != D_80109D90_2C7D10_PirateDuel) {
                D_80109D94_2C7D14_PirateDuel = i;
                break;
            }
        }
    }
    D_80109DC4_2C7D44_PirateDuel = GwSystem.current_turn;
}

void func_80102BC0_2C0B40_PirateDuel(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C14_2C0B94_PirateDuel(void) {
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

/* NON_MATCHING: registers only (masked 0, raw 29): retail keeps i * 2 (the hook arrays' index) in s2
   and the character's table offset in s3, GCC swaps them; everything else matches, the drop loop
   included (written with gotos: a while/do loop gets its exit test copied to the top or loses the
   values CSE carries out of it). */
/* The duel scene's flow: duelists and the referee walk in, the five sword moves are dealt, the opponent
   and the stake are chosen, then the duel (fork B's processes) decides D_80109DC8: 1 a draw, 2 the
   challenger wins, 3 the opponent; the winner takes both stakes. */
#ifdef NON_MATCHING
void func_80102CA0_2C0C20_PirateDuel(void) {
    s32 chr;
    ModelPathWork* work[4];
    Vec pos[2];
    s32 counts[3];
    u32 motions[3] = { 2, 0x800A7, 0x800AA };
    s32 files[3] = { 0xA01A8, 0xA01A9, 0xA01AA };
    s32 waits[6] = { 35, 30, 50, 35, 30, 35 };
    MBModel* model;
    s16 mes;
    u16 done;
    s32 snd;
    s32 layout;
    s32 slot;
    s32 move;
    s32 i;

    func_80050E00_51A00(11);
    func_8005321C_53E1C(80.0f, 8000.0f);
    func_80107D00_2C5C80_PirateDuel();
    for (i = 0; i < 4; i++) {
        if (D_80109D98_2C7D18_PirateDuel[i] != 0) {
            chr = gPlayers[i].character;

            MBPlayerModelCreate(i, D_80109AF8_2C7A78_PirateDuel[chr], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 1, 0);
            PLAYER_MODEL(i)->pos.x = -1000.0f;
            PLAYER_MODEL(i)->pos.y = 0.0f;
            PLAYER_MODEL(i)->pos.z = 700.0f;
            gPlayers[i].flags |= 2;
            func_80043DAC_449AC(PLAYER_MODEL(i));
            D_80109DF4_2C7D74_PirateDuel[i] = LoadFormFile(0xA01A2, 0x489);
            D_80109DFC_2C7D7C_PirateDuel[i] = LoadFormFile(0xD, 0x48D);
            func_800297E8_2A3E8(D_80109DFC_2C7D7C_PirateDuel[i], D_80109B80_2C7B00_PirateDuel[chr], 1.0f, D_80109B80_2C7B00_PirateDuel[chr]);
            func_8005AA48_5B648(PLAYER_MODEL(i), "item_hook", D_80109DF4_2C7D74_PirateDuel[i]);
        }
    }
    D_8010A0B4_2C8034_PirateDuel = MBModelFileCreate(0x800A6, 0xD, 1.0f, 1.0f, motions);
    func_8005AB50_5B750(D_8010A0B4_2C8034_PirateDuel, 1, 0xB, 0x800AD);
    D_8010A0B4_2C8034_PirateDuel->pos.x = D_80109B14_2C7A94_PirateDuel.x;
    D_8010A0B4_2C8034_PirateDuel->pos.y = 0.0f;
    D_8010A0B4_2C8034_PirateDuel->pos.z = D_80109B14_2C7A94_PirateDuel.z;
    func_80056658_57258(&D_8010A0B4_2C8034_PirateDuel->pos, &D_80109B14_2C7A94_PirateDuel, &D_8010A0B4_2C8034_PirateDuel->rot);
    if (D_8010A060_2C7FE0_PirateDuel == 0) {
        D_8010A0B4_2C8034_PirateDuel->jumpY = D_80109B14_2C7A94_PirateDuel.y;
        D_8010A0B4_2C8034_PirateDuel->jumpVel = 7.5f;
        D_8010A0B4_2C8034_PirateDuel->jumpAccel = 0.0f;
        D_8010A0B8_2C8038_PirateDuel = MBModelFileCreate(0xA019D, 0xD, 1.0f, 1.0f, NULL);
        D_8010A0B8_2C8038_PirateDuel->pos.x = D_80109B14_2C7A94_PirateDuel.x;
        D_8010A0B8_2C8038_PirateDuel->pos.y = 0.0f;
        D_8010A0B8_2C8038_PirateDuel->pos.z = D_80109B14_2C7A94_PirateDuel.z;
        D_8010A0B8_2C8038_PirateDuel->jumpY = D_80109B14_2C7A94_PirateDuel.y;
        D_8010A0B8_2C8038_PirateDuel->jumpVel = 7.5f;
        D_8010A0B8_2C8038_PirateDuel->jumpAccel = 0.0f;
    }
    /* the five moves: each 0..2, all three used, never three alike in a row */
    for (i = 0; i < 3; i++) {
        D_8010A064_2C7FE4_PirateDuel[i] = func_8001A2F8_1AEF8(files[i]);
    }
    for (i = 0; i < 3; i++) {
        counts[i] = 0;
    }
    while (counts[0] == 0 || counts[1] == 0 || counts[2] == 0) {
        for (i = 0; i < 3; i++) {
            counts[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            D_8010A0A0_2C8020_PirateDuel[i] = -1;
        }
        i = 0;
        move = rand8() % 3;
        do {
            slot = rand8() % 5;
            if (D_8010A0A0_2C8020_PirateDuel[slot] == -1) {
                if (!(slot < 3 && D_8010A0A0_2C8020_PirateDuel[slot + 1] == move && D_8010A0A0_2C8020_PirateDuel[slot + 2] == move)
                    && !(slot - 1 < 3U && D_8010A0A0_2C8020_PirateDuel[slot - 1] == move && D_8010A0A0_2C8020_PirateDuel[slot + 1] == move)
                    && !(slot >= 2 && D_8010A0A0_2C8020_PirateDuel[slot - 1] == move && D_8010A0A0_2C8020_PirateDuel[slot - 2] == move)) {
                    D_8010A0A0_2C8020_PirateDuel[slot] = move;
                    counts[move]++;
                    i++;
                }
            }
            move = (move + 1) % 3;
        } while (i < 5);
    }
    for (i = 0; i < 5; i++) {
        D_8010A070_2C7FF0_PirateDuel[i] = func_8001AAAC_1B6AC(D_8010A064_2C7FE4_PirateDuel[D_8010A0A0_2C8020_PirateDuel[i]], 0, 1);
        D_8010A07A_2C7FFA_PirateDuel[i] = func_8001AAAC_1B6AC(D_8010A064_2C7FE4_PirateDuel[D_8010A0A0_2C8020_PirateDuel[i]], 0, 1);
        espDispOff(D_8010A070_2C7FF0_PirateDuel[i]);
        espDispOff(D_8010A07A_2C7FFA_PirateDuel[i]);
    }
    D_8010A084_2C8004_PirateDuel = func_8001A2F8_1AEF8(0xA01AB);
    D_8010A086_2C8006_PirateDuel = func_8001A2F8_1AEF8(0xA01AC);
    for (i = 0; i < 2; i++) {
        D_8010A088_2C8008_PirateDuel[i] = func_8001AAAC_1B6AC(D_8010A084_2C8004_PirateDuel, 0, 1);
        D_8010A08C_2C800C_PirateDuel[i] = func_8001AAAC_1B6AC(D_8010A086_2C8006_PirateDuel, 0, 1);
        func_8001A96C_1B56C(D_8010A08C_2C800C_PirateDuel[i], 0xFF, 0xFF, 0xFF);
        func_8001A96C_1B56C(D_8010A088_2C8008_PirateDuel[i], 0xE2, 0, 0x7F);
        espDispOff(D_8010A088_2C8008_PirateDuel[i]);
        espDispOff(D_8010A08C_2C800C_PirateDuel[i]);
    }
    PlayMusic(0x25);
    InitFadeIn(0, 0x10);
    if (D_8010A060_2C7FE0_PirateDuel == 0) {
        /* the referee drops in with his hat */
        goto drop;
    fall:
        HuPrcVSleep();
    drop:
        D_8010A0B8_2C8038_PirateDuel->jumpY = D_8010A0B4_2C8034_PirateDuel->jumpY;
        D_8010A0B4_2C8034_PirateDuel->jumpY = D_8010A0B4_2C8034_PirateDuel->jumpY - D_8010A0B4_2C8034_PirateDuel->jumpVel;
        if (!(D_8010A0B4_2C8034_PirateDuel->jumpY <= D_8010A0B4_2C8034_PirateDuel->pos.y)) {
            goto fall;
        }
        D_8010A0B4_2C8034_PirateDuel->jumpY = D_8010A0B4_2C8034_PirateDuel->pos.y;
        func_80105694_2C3614_PirateDuel();
        layout = (D_80109DA8_2C7D28_PirateDuel == 4) ? 0 : -1;
        if (D_80109DA8_2C7D28_PirateDuel == 3) {
            layout = 6;
        }
        if (layout != -1) {
            /* three or four players: the challenger picks the opponent */
            func_801051DC_2C315C_PirateDuel(layout);
            PD_WAIT_STEP();
            PlaySound(0xE8);
            omAddPrcObj(func_801057B4_2C3734_PirateDuel, 0x12, 0, 0);
            D_80109D70_2C7CF0_PirateDuel = 0;
            PD_WAIT_STEP();
            func_801051DC_2C315C_PirateDuel(1);
            PD_WAIT_STEP();
            func_801051DC_2C315C_PirateDuel(2);
            PD_WAIT_STEP();
        } else {
            func_801051DC_2C315C_PirateDuel(7);
            PD_WAIT_STEP();
        }
        MBVsSprCreateY(160.0f, 90.0f);
        HuPrcSleep(10);
        D_80109B10_2C7A90_PirateDuel = 1;
        func_801051DC_2C315C_PirateDuel(3);
        PD_WAIT_STEP();
        omAddPrcObj(func_80105A80_2C3A00_PirateDuel, 0x12, 0, 0);
        D_80109D70_2C7CF0_PirateDuel = 0;
        PD_WAIT_STEP();
        func_801051DC_2C315C_PirateDuel(4);
        MBVsSprKill();
        PD_WAIT_STEP();
    }
    /* the duelists walk to their marks */
    PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->pos.x = -400.0f;
    PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->pos.x = 400.0f;
    MBMotionShiftSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 0, 0, 5, 2);
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 15.0f, 1, D_80109B50_2C7AD0_PirateDuel);
    MBMotionShiftSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 0, 0, 5, 2);
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 15.0f, 1, D_80109B5C_2C7ADC_PirateDuel);
    while (TRUE) {
        done = 0;
        for (i = 0; i < 2; i++) {
            if (func_8005A778_5B378(work[i]) != 0) {
                done++;
            }
        }
        if (done == 2) {
            break;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 2; i++) {
        HuMemMemoryFreePerm(work[i]);
    }
    MBMotionShiftSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 2, 0, 5, 2);
    /* the referee walks to the middle */
    work[0] = func_8005A718_5B318(D_8010A0B4_2C8034_PirateDuel, 30.0f, 1, D_80109B2C_2C7AAC_PirateDuel);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    model = D_8010A0B4_2C8034_PirateDuel;
    model->rot.x = __sinf(0.34906584f); /* 20 degrees */
    model = D_8010A0B4_2C8034_PirateDuel;
    model->rot.y = 0.0f;
    model->rot.z = __cosf(0.34906584f);
    D_8010A0B4_2C8034_PirateDuel->obj->rot.z = 20.0f;
    PlaySound(0xE8);
    D_80109D84_2C7D04_PirateDuel = 0x21A;
    D_80109D78_2C7CF8_PirateDuel = 95;
    D_80109D7C_2C7CFC_PirateDuel = 33;
    D_80109D80_2C7D00_PirateDuel = 1;
    omAddPrcObj(func_80104B88_2C2B08_PirateDuel, 0x12, 0, 0);
    D_80109D70_2C7CF0_PirateDuel = 0;
    PD_WAIT_STEP();
    D_8010A0B4_2C8034_PirateDuel->rot.x = HuMathSin(0.0f);
    D_8010A0B4_2C8034_PirateDuel->rot.y = 0.0f;
    D_8010A0B4_2C8034_PirateDuel->rot.z = func_800B7890_B8490(D_8010A0B4_2C8034_PirateDuel->rot.y);
    D_8010A0B4_2C8034_PirateDuel->obj->rot.z = 0.0f;
    work[0] = func_8005A718_5B318(D_8010A0B4_2C8034_PirateDuel, 30.0f, 1, D_80109B20_2C7AA0_PirateDuel);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    D_8010A0B4_2C8034_PirateDuel->rot.x = HuMathSin(0.0f);
    D_8010A0B4_2C8034_PirateDuel->rot.y = 0.0f;
    D_8010A0B4_2C8034_PirateDuel->rot.z = func_800B7890_B8490(D_8010A0B4_2C8034_PirateDuel->rot.y);
    HuPrcSleep(15);
    D_80109D84_2C7D04_PirateDuel = 0x214;
    D_80109D78_2C7CF8_PirateDuel = 90;
    D_80109D7C_2C7CFC_PirateDuel = 70;
    D_80109D80_2C7D00_PirateDuel = 2;
    omAddPrcObj(func_80104B88_2C2B08_PirateDuel, 0x12, 0, 0);
    D_80109D70_2C7CF0_PirateDuel = 0;
    PD_WAIT_STEP();
    /* both draw their swords */
    PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->attr |= 1;
    func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_80109D90_2C7D10_PirateDuel], 4, 0);
    MBMotionSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 8, 0);
    func_8005ACD0_5B8D0(&gPlayers[D_80109D90_2C7D10_PirateDuel], 0xB);
    func_801088FC_2C687C_PirateDuel(D_80109D90_2C7D10_PirateDuel, 0);
    PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->attr |= 1;
    func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_80109D94_2C7D14_PirateDuel], 4, 0);
    MBMotionSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 8, 0);
    func_8005ACD0_5B8D0(&gPlayers[D_80109D94_2C7D14_PirateDuel], 0xB);
    func_801088FC_2C687C_PirateDuel(D_80109D94_2C7D14_PirateDuel, 0);
    HuPrcSleep(30);
    MBMotionSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 3, 1);
    MBMotionSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 3, 1);
    func_8008CE5C_8DA5C();
    func_800691FC_69DFC(1);
    PD_WAIT_MESSAGE();
    HuPrcSleep(18);
    /* the duel (fork B's processes) */
    func_80109040_2C6FC0_PirateDuel();
    func_8010913C_2C70BC_PirateDuel();
    D_8010A090_2C8010_PirateDuel[0] = 0;
    D_8010A090_2C8010_PirateDuel[1] = 0;
    omAddPrcObj(func_80109214_2C7194_PirateDuel, 0x12, 0, 0);
    D_80109D70_2C7CF0_PirateDuel = 0;
    D_80109DC8_2C7D48_PirateDuel = 0;
    func_801062FC_2C427C_PirateDuel();
    omAddPrcObj(func_80109780_2C7700_PirateDuel, 0x12, 0, 0);
    omAddPrcObj(func_801064E8_2C4468_PirateDuel, 0x12, 0, 0);
    PD_WAIT_STEP();
    HuPrcVSleep();
    switch (D_80109DC8_2C7D48_PirateDuel) {
        case 2:
            D_800FC880_FD480 = D_80109D90_2C7D10_PirateDuel;
            D_800F8C5C_F985C = D_80109D94_2C7D14_PirateDuel;
            break;
        case 3:
            D_800FC880_FD480 = D_80109D94_2C7D14_PirateDuel;
            D_800F8C5C_F985C = D_80109D90_2C7D10_PirateDuel;
            break;
        case 1:
            D_800F8C5C_F985C = D_800FC880_FD480 = -1;
            break;
    }
    if (D_800FC880_FD480 == -1) {
        /* a draw: both get their stake back */
        if (D_8010A060_2C7FE0_PirateDuel == 0) {
            D_80109D70_2C7CF0_PirateDuel = 0;
            func_801051DC_2C315C_PirateDuel(2);
            PD_WAIT_STEP();
        }
        MBMotionSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 8, 4);
        func_80029C74_2A874(*PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->obj->model,
                            func_80029D0C_2A90C(*PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->obj->model));
        MBMotionSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 8, 4);
        func_80029C74_2A874(*PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->obj->model,
                            func_80029D0C_2A90C(*PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->obj->model));
        func_801088FC_2C687C_PirateDuel(D_80109D90_2C7D10_PirateDuel, 3);
        func_801088FC_2C687C_PirateDuel(D_80109D94_2C7D14_PirateDuel, 3);
        MBMotionShiftSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 2, 0, 5, 2);
        HuPrcSleep(40);
        PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->attr &= ~1;
        func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_80109D90_2C7D10_PirateDuel], 4, 4);
        PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->attr &= ~1;
        func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_80109D94_2C7D14_PirateDuel], 4, 4);
        if (D_8010A060_2C7FE0_PirateDuel == 0) {
            MBMotionShiftSet(D_8010A0B4_2C8034_PirateDuel, 1, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_8010A0B4_2C8034_PirateDuel, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_80109D84_2C7D04_PirateDuel = 0x216;
            D_80109D78_2C7CF8_PirateDuel = 85;
            D_80109D7C_2C7CFC_PirateDuel = 70;
            D_80109D80_2C7D00_PirateDuel = 3;
            omAddPrcObj(func_80104B88_2C2B08_PirateDuel, 0x12, 0, 0);
            D_80109D70_2C7CF0_PirateDuel = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_80109D90_2C7D10_PirateDuel, D_80109D74_2C7CF4_PirateDuel);
            func_8006135C_61F5C(D_80109D94_2C7D14_PirateDuel, D_80109D74_2C7CF4_PirateDuel, 0);
            func_800794A8_7A0A8(30);
            HuPrcSleep(30);
        }
        PlayMusic(0x57);
        func_800691FC_69DFC(0x13);
        PD_WAIT_MESSAGE();
    } else {
        /* the winner strikes, the loser falls */
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 4, 0);
        func_801088FC_2C687C_PirateDuel(D_800FC880_FD480, 1);
        omVibrate(D_800F8C5C_F985C, 20, 0, 20);
        HuPrcSleep(2);
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 9, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 8);
        func_801088FC_2C687C_PirateDuel(D_800F8C5C_F985C, 4);
        func_800797DC_7A3DC(0x111, D_800F8C5C_F985C);
        PlaySound(0x3B1);
        func_800794A8_7A0A8(10);
        snd = PlaySound(0x4B5);
        func_800794A8_7A0A8(35);
        D_80109DEC_2C7D6C_PirateDuel = D_800F8C5C_F985C;
        D_80109DF0_2C7D70_PirateDuel = 1;
        omAddPrcObj(func_801086B0_2C6630_PirateDuel, 0x12, 0, 0);
        HuPrcSleep(15);
        HuPrcSleep(11);
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 4, 4);
        func_80029FE4_2ABE4(*PLAYER_MODEL(D_800FC880_FD480)->obj->model, 0.1f);
        func_801088FC_2C687C_PirateDuel(D_800FC880_FD480, 2);
        func_80029C74_2A874(*PLAYER_MODEL(D_800FC880_FD480)->obj->model,
                            func_80029D0C_2A90C(*PLAYER_MODEL(D_800FC880_FD480)->obj->model));
        HuPrcSleep(10);
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 10, 0);
        func_801088FC_2C687C_PirateDuel(D_800F8C5C_F985C, 5);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 0);
        if (D_8010A060_2C7FE0_PirateDuel == 0) {
            D_80109D70_2C7CF0_PirateDuel = 0;
            func_801051DC_2C315C_PirateDuel(2);
            PD_WAIT_STEP();
        }
        HuPrcSleep(20);
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 8, 4);
        func_801088FC_2C687C_PirateDuel(D_800FC880_FD480, 3);
        func_80029C74_2A874(*PLAYER_MODEL(D_800FC880_FD480)->obj->model,
                            func_80029D0C_2A90C(*PLAYER_MODEL(D_800FC880_FD480)->obj->model));
        func_8005ACD0_5B8D0(&gPlayers[D_800FC880_FD480], 0);
        HuPrcSleep(30);
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 2, 2);
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 2, 2);
        PLAYER_MODEL(D_800FC880_FD480)->attr &= ~1;
        func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_800FC880_FD480], 4, 4);
        PLAYER_MODEL(D_800F8C5C_F985C)->attr &= ~1;
        func_800298A4_2A4A4(D_80109DFC_2C7D7C_PirateDuel[D_800F8C5C_F985C], 4, 4);
        func_800298A4_2A4A4(D_80109DF4_2C7D74_PirateDuel[D_800F8C5C_F985C], 4, 4);
        /* both turn to the camera */
        HuVecCopyXYZ(&pos[0], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800FC880_FD480)->pos.y, D_800C9B80_CA780->pos.z);
        HuVecCopyXYZ(&pos[1], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800F8C5C_F985C)->pos.y, D_800C9B80_CA780->pos.z);
        func_800446B4_452B4(PLAYER_MODEL(D_800FC880_FD480), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_800F8C5C_F985C), &pos[1], 10);
        HuPrcSleep(20);
        if (D_8010A060_2C7FE0_PirateDuel == 0) {
            MBMotionShiftSet(D_8010A0B4_2C8034_PirateDuel, 1, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_8010A0B4_2C8034_PirateDuel, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_80109D8C_2C7D0C_PirateDuel = D_800FC880_FD480;
            D_80109D84_2C7D04_PirateDuel = 0x215;
            D_80109D78_2C7CF8_PirateDuel = 90;
            D_80109D7C_2C7CFC_PirateDuel = 70;
            D_80109D80_2C7D00_PirateDuel = 4;
            omAddPrcObj(func_80104B88_2C2B08_PirateDuel, 0x12, 0, 0);
            D_80109D70_2C7CF0_PirateDuel = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_800FC880_FD480, D_80109D74_2C7CF4_PirateDuel * 2);
            if ((s16)snd != -1) {
                func_800799A4_7A5A4(snd, 40);
            }
            HuPrcSleep(30);
        }
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 5, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800FC880_FD480], 1);
        HuPrcSleep(waits[gPlayers[D_800FC880_FD480].character]);
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 6, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 2);
        PlayMusic(0x51);
        mes = func_800797DC_7A3DC(0xF5, D_800FC880_FD480);
        if (D_800FC880_FD480 == D_80109D90_2C7D10_PirateDuel) {
            func_800798F8_7A4F8(mes, 0x2C);
        } else {
            func_800798F8_7A4F8(mes, 0x54);
        }
        mes = func_800797DC_7A3DC(0xFC, D_800F8C5C_F985C);
        if (D_800F8C5C_F985C == D_80109D90_2C7D10_PirateDuel) {
            func_800798F8_7A4F8(mes, 0x2C);
        } else {
            func_800798F8_7A4F8(mes, 0x54);
        }
        func_800691FC_69DFC(6, gPlayers[D_800FC880_FD480].character);
        PD_WAIT_MESSAGE();
    }
    HuPrcSleep(8);
    func_801055AC_2C352C_PirateDuel();
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
__asm__(".section .rodata");
const u32 D_80109BC0_2C7B40_PirateDuel[3] = { 0x00000002, 0x000800A7, 0x000800AA };

__asm__(".section .rodata");
const u32 D_80109BCC_2C7B4C_PirateDuel[3] = { 0x000A01A8, 0x000A01A9, 0x000A01AA };

__asm__(".section .rodata");
const u32 D_80109BD8_2C7B58_PirateDuel[6] = { 0x00000023, 0x0000001E, 0x00000032, 0x00000023, 0x0000001E, 0x00000023 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80102CA0_2C0C20_PirateDuel);
#endif

/* With func_80102CA0 as INCLUDE_ASM, GCC still believes it is in .rodata here (the asm switched to
   .text): switch for real, so the string literals below land in .rodata. */
__asm__(".section .rodata");

/* A message window (3F's func_80105AAC): D_80109D84 at (D_80109D78, D_80109D7C); D_80109D80 is the
   variant: 1 waits for a duelist's press (both CPU: the CPU script), 3 shows the stake, 4 the
   winner's character and the stake, 5 the character; 2-5 close at once. Bit 0 of D_80109D88 keeps
   the window for a press (ShowTextWindow/func_8005762C). */
void func_80104B88_2C2B08_PirateDuel(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_80109D80_2C7D00_PirateDuel == 3) {
        sprintf(num, "%d", D_80109D74_2C7CF4_PirateDuel);
        func_8008D974_8E574(num, 0);
    }
    if (D_80109D80_2C7D00_PirateDuel == 4) {
        sprintf(num, "%d", D_80109D74_2C7CF4_PirateDuel);
        sprintf(name, "%c%c", 0x18, gPlayers[D_80109D8C_2C7D0C_PirateDuel].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    if (D_80109D80_2C7D00_PirateDuel == 5) {
        sprintf(num, "%c%c", 0x18, gPlayers[D_80109D8C_2C7D0C_PirateDuel].character);
        func_8008D974_8E574(num, 0);
    }
    func_8008DACC_8E6CC(1, size, D_80109D84_2C7D04_PirateDuel);
    win = func_80104FB4_2C2F34_PirateDuel((s16)D_80109D78_2C7CF8_PirateDuel, (s16)D_80109D7C_2C7CFC_PirateDuel, size[0], size[1], 0, 0, 200);
    if (D_80109D88_2C7D08_PirateDuel & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80109D80_2C7D00_PirateDuel == 3 || D_80109D80_2C7D00_PirateDuel == 5) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_80109D80_2C7D00_PirateDuel == 4) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80109D84_2C7D04_PirateDuel, -1, -1);
    func_80057A78_58678((s16)win, D_80109D90_2C7D10_PirateDuel, D_80109D94_2C7D14_PirateDuel);
    if (D_80109D80_2C7D00_PirateDuel == 1 && (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) && (gPlayers[D_80109D94_2C7D14_PirateDuel].flags & 1)) {
        func_801070F4_2C5074_PirateDuel(0, 0, 0);
    }
    while (TRUE) {
        switch (D_80109D80_2C7D00_PirateDuel) {
            case 1:
                if ((gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) && (gPlayers[D_80109D94_2C7D14_PirateDuel].flags & 1)) {
                    btn = func_801078C4_2C5844_PirateDuel();
                } else {
                    btn = func_8010511C_2C309C_PirateDuel();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_80109D70_2C7CF0_PirateDuel = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                if (D_80109D88_2C7D08_PirateDuel & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_80109D70_2C7CF0_PirateDuel = 1;
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

/* NON_MATCHING: registers (masked 14), as overlay 40's func_801041B4 and 3F's func_80104844: retail
   keeps arg6 in s0 and the narrowed window id in s1 */
#ifdef NON_MATCHING
s32 func_80104FB4_2C2F34_PirateDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80109D94_2C7D14_PirateDuel != -1) {
        mask = (1 << gPlayers[D_80109D90_2C7D10_PirateDuel].port) | (1 << gPlayers[D_80109D94_2C7D14_PirateDuel].port);
    } else {
        mask = 1 << gPlayers[D_80109D90_2C7D10_PirateDuel].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80104FB4_2C2F34_PirateDuel);
#endif

u16 func_8010511C_2C309C_PirateDuel(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80109D90_2C7D10_PirateDuel].port];
    }
    if (D_80109D94_2C7D14_PirateDuel != -1 && btn == 0) {
        if (!(gPlayers[D_80109D94_2C7D14_PirateDuel].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80109D94_2C7D14_PirateDuel].port];
        }
    }
    return btn;
}

void func_801051DC_2C315C_PirateDuel(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80109D70_2C7CF0_PirateDuel = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80105514_2C3494_PirateDuel);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80109D98_2C7D18_PirateDuel[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80109D90_2C7D10_PirateDuel) {
                if (i == D_80109D94_2C7D14_PirateDuel) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80109DB0_2C7D30_PirateDuel[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][0] != -1) {
                status->xPos = D_801098A0_2C7820_PirateDuel[layout].pos[slot][0];
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][1] != -1) {
                status->yPos = D_801098A0_2C7820_PirateDuel[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_801098A0_2C7820_PirateDuel[layout].frames - 1;
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][2] != -1) {
                status->unk_18 = D_801098A0_2C7820_PirateDuel[layout].pos[slot][2];
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][3] != -1) {
                status->unk_1C = D_801098A0_2C7820_PirateDuel[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80109B10_2C7A90_PirateDuel == 1) {
        status = &D_80101510_102110[D_80109D90_2C7D10_PirateDuel];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_801098A0_2C7820_PirateDuel[layout].frames - 1;
    }
}

void func_80105514_2C3494_PirateDuel(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80109D98_2C7D18_PirateDuel[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80109DA8_2C7D28_PirateDuel) {
        D_80109D70_2C7CF0_PirateDuel = 1;
        omDelObj(obj);
    }
}

void func_801055AC_2C352C_PirateDuel(void) {
    func_80069764_6A364(60);
    omAddObj(0x10, 0, 0, -1, func_801055E8_2C3568_PirateDuel);
}

void func_801055E8_2C3568_PirateDuel(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_8010A060_2C7FE0_PirateDuel != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105640_2C35C0_PirateDuel;
    }
}

void func_80105640_2C35C0_PirateDuel(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105694_2C3614_PirateDuel(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80105724_2C36A4_PirateDuel);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80105724_2C36A4_PirateDuel(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_8010A0B8_2C8038_PirateDuel->scale.x += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->scale.y += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->scale.z += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_8010A0B8_2C8038_PirateDuel);
        omDelObj(obj);
    }
}

void func_801057B4_2C3734_PirateDuel(void) {
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
    win = func_80104FB4_2C2F34_PirateDuel(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80109DA8_2C7D28_PirateDuel - 1;
    if (D_80109DA8_2C7D28_PirateDuel == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80109DA8_2C7D28_PirateDuel; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
        func_801070F4_2C5074_PirateDuel(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_8010511C_2C309C_PirateDuel();
        if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
            btn = func_801078C4_2C5844_PirateDuel();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80109DB0_2C7D30_PirateDuel[sel], 1) != 0) {
            PlaySound(2);
            D_80109D70_2C7CF0_PirateDuel = 1;
            D_80109D94_2C7D14_PirateDuel = D_80109DB0_2C7D30_PirateDuel[sel];
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

void func_80105A80_2C3A00_PirateDuel(void) {
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

    turn = D_80109DC4_2C7D44_PirateDuel;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80109D90_2C7D10_PirateDuel)->coins;
    coins2 = BoardPlayerGet(D_80109D94_2C7D14_PirateDuel)->coins;
    D_80109DCC_2C7D4C_PirateDuel = coins1;
    if (coins2 < coins1) {
        D_80109DCC_2C7D4C_PirateDuel = coins2;
    }
    i++;
    while (D_80109DCC_2C7D4C_PirateDuel < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80109D74_2C7CF4_PirateDuel = D_80109DC0_2C7D40_PirateDuel = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80109DC0_2C7D40_PirateDuel;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80104FB4_2C2F34_PirateDuel(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80109D90_2C7D10_PirateDuel);
    AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -D_80109D74_2C7CF4_PirateDuel);
    AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -D_80109D74_2C7CF4_PirateDuel);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
        func_801070F4_2C5074_PirateDuel(D_80109D74_2C7CF4_PirateDuel, D_80109DCC_2C7D4C_PirateDuel, 3);
    }
    while (TRUE) {
        D_80109D74_2C7CF4_PirateDuel = stake;
        btn = ContDStkTrg[gPlayers[D_80109D90_2C7D10_PirateDuel].port];
        if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
            btn = func_801078C4_2C5844_PirateDuel();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80109D70_2C7CF0_PirateDuel = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80109D90_2C7D10_PirateDuel].coins > 0 && gPlayers[D_80109D94_2C7D14_PirateDuel].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -1);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -1);
            }
        } else if (btn & 0x400) {
            if (D_80109DC0_2C7D40_PirateDuel < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, 1);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80109DC0_2C7D40_PirateDuel) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, 10);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80109D90_2C7D10_PirateDuel].coins >= 10 && gPlayers[D_80109D94_2C7D14_PirateDuel].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -10);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -10);
            }
        }
        HuPrcVSleep();
    }
}

/* Starts the duel's timeline (func_80106B5C): for each duelist, five rows of 30 frames with 7-11
   random frames marked; a marked frame starts the duelist's taunt motion. */
/* NON_MATCHING: masked 4, operand order only: retail adds the row offset and the table base as
   (k * 300) + base, GCC as base + (k * 300). */
#ifdef NON_MATCHING
void func_801062FC_2C427C_PirateDuel(void) {
    omObjData* obj;
    PdTimeline* work;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s16* p;
    s16 (*tl)[150];

    obj = omAddObj(0x10, 0, 0, -1, func_80106B5C_2C4ADC_PirateDuel);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdTimeline), 0x7918);
    D_80109DD0_2C7D50_PirateDuel[D_80109D90_2C7D10_PirateDuel] = 0;
    D_80109DD0_2C7D50_PirateDuel[D_80109D94_2C7D14_PirateDuel] = 0;
    tl = D_80109E08_2C7D88_PirateDuel;
    for (k = 0; k < 2; k++) {
        count = (u8)(rand8() % 5) + 7;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 30; j++) {
                tl[k][i * 30 + j] = 0;
            }
            for (j = 0; j < count; j++) {
                do {
                    p = &tl[k][i * 30 + (u8)(rand8() % 30)];
                } while (*p != 0);
                *p = 1;
            }
        }
    }
    work->frame = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801062FC_2C427C_PirateDuel);
#endif

/* The duel's input process: each duelist answers the sword move shown (A, B or Z for moves 0-2;
   func_80109344 right, func_801094D4 wrong). A CPU answers after a delay from its difficulty,
   and an easy CPU misses one time in eleven. The first to five ends it (D_80109DC8: 1 both at
   once, 2 the challenger, 3 the opponent).
   Retail quirk: the first loop tests `player` before setting it (an uninitialised register on
   the first pass; either way each duelist gets a delay from its own difficulty only by luck). */
/* NON_MATCHING: masked 0, registers only: retail gives the player s0 and the loop counter s1
   (swapped here); declaration order and which counter is shared do not change it. */
#ifdef NON_MATCHING
void func_801064E8_2C4468_PirateDuel(void) {
    s32 btn[3] = { 0x8000, 0x4000, 0x2000 };
    s32 timer[2];
    s32 delay[4] = { 4, 3, 2, 1 };
    s32 sel;
    s32 miss;
    s32 player;
    s32 i;
    s32 k;

    for (i = 0; i < 2; i++) {
        if (player == 0) {
            player = D_80109D90_2C7D10_PirateDuel;
        } else {
            player = D_80109D94_2C7D14_PirateDuel;
        }
        timer[i] = delay[gPlayers[player].cpu_difficulty] * 6 + (u8)(rand8() % 6) - 3;
        if (timer[i] <= 0) {
            timer[i] = 1;
        }
    }
    while (D_80109D70_2C7CF0_PirateDuel == 0) {
        sel = -1;
        k = 0;
        player = D_80109D90_2C7D10_PirateDuel;
        if (D_8010A098_2C8018_PirateDuel[k] == 0) {
            if (!(gPlayers[player].flags & 1)) {
                for (i = 0; i < 3; i++) {
                    if (ContBtnTrg[gPlayers[player].port] == btn[i]) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    if (sel == D_8010A0A0_2C8020_PirateDuel[D_8010A090_2C8010_PirateDuel[k]]) {
                        func_80109344_2C72C4_PirateDuel(k);
                    } else {
                        func_801094D4_2C7454_PirateDuel(k);
                    }
                }
            } else if (--timer[k] == 0) {
                miss = 0;
                if (gPlayers[player].cpu_difficulty == 0) {
                    miss = (u8)(rand8() % 11) == 0;
                }
                if (miss) {
                    func_801094D4_2C7454_PirateDuel(k);
                } else {
                    func_80109344_2C72C4_PirateDuel(k);
                }
                timer[k] = delay[gPlayers[player].cpu_difficulty] * 6 + (u8)(rand8() % 6) - 3;
                if (timer[k] <= 0) {
                    timer[k] = 1;
                }
            }
        }
        sel = -1;
        k = 1;
        player = D_80109D94_2C7D14_PirateDuel;
        if (D_8010A098_2C8018_PirateDuel[k] == 0) {
            if (!(gPlayers[player].flags & 1)) {
                for (i = 0; i < 3; i++) {
                    if (ContBtnTrg[gPlayers[player].port] == btn[i]) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    if (sel == D_8010A0A0_2C8020_PirateDuel[D_8010A090_2C8010_PirateDuel[k]]) {
                        func_80109344_2C72C4_PirateDuel(k);
                    } else {
                        func_801094D4_2C7454_PirateDuel(k);
                    }
                }
            } else if (--timer[k] == 0) {
                miss = 0;
                if (gPlayers[player].cpu_difficulty == 0) {
                    miss = (u8)(rand8() % 11) == 0;
                }
                if (miss) {
                    func_801094D4_2C7454_PirateDuel(k);
                } else {
                    func_80109344_2C72C4_PirateDuel(k);
                }
                timer[k] = delay[gPlayers[player].cpu_difficulty] * 6 + (u8)(rand8() % 6) - 3;
                if (timer[k] <= 0) {
                    timer[k] = 1;
                }
            }
        }
        if (D_8010A090_2C8010_PirateDuel[0] == 5) {
            if (D_8010A090_2C8010_PirateDuel[1] == D_8010A090_2C8010_PirateDuel[0]) {
                D_80109DC8_2C7D48_PirateDuel = 1;
            } else {
                D_80109DC8_2C7D48_PirateDuel = 2;
            }
            break;
        }
        if (D_8010A090_2C8010_PirateDuel[1] == 5) {
            D_80109DC8_2C7D48_PirateDuel = 3;
            break;
        }
        HuPrcVSleep();
    }
    D_80109D70_2C7CF0_PirateDuel = 1;
    for (k = 0; k < 2; k++) {
        espDispOff(D_8010A088_2C8008_PirateDuel[k]);
        espDispOff(D_8010A08C_2C800C_PirateDuel[k]);
    }
    for (k = 0; k < 10; k++) {
        espDispOff(D_8010A070_2C7FF0_PirateDuel[k]);
    }
    omDelPrcObj(NULL);
}
#else
__asm__(".section .rodata");
const u32 D_80109C4C_2C7BCC_PirateDuel[3] = { 0x00008000, 0x00004000, 0x00002000 };
__asm__(".section .rodata");
const u32 D_80109C58_2C7BD8_PirateDuel[4] = { 0x00000004, 0x00000003, 0x00000002, 0x00000001 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801064E8_2C4468_PirateDuel);
#endif

/* The timeline: each frame, the CPU input (func_801078D0); while neither duelist is acting, a
   marked frame starts that duelist's motion 3 until it has played out. */
void func_80106B5C_2C4ADC_PirateDuel(omObjData* obj) {
    PdTimeline* work;

    func_801078D0_2C5850_PirateDuel();
    if (D_8010A098_2C8018_PirateDuel[0] == 0 && D_8010A098_2C8018_PirateDuel[1] == 0) {
        work = obj->unk_50;
        if (D_80109E08_2C7D88_PirateDuel[0][work->frame] != 0) {
            if (D_80109DE0_2C7D60_PirateDuel[0] == 0) {
                MBMotionSet(PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel), 3, 0);
            }
            D_80109DE0_2C7D60_PirateDuel[0] = 1;
        }
        if (D_80109E08_2C7D88_PirateDuel[1][work->frame] != 0) {
            if (D_80109DE0_2C7D60_PirateDuel[1] == 0) {
                MBMotionShiftSet(PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel), 3, 0, 5, 0);
            }
            D_80109DE0_2C7D60_PirateDuel[1] = 1;
        }
        if (func_80029CE4_2A8E4(*PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->obj->model) >=
            func_80029D0C_2A90C(*PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel)->obj->model)) {
            D_80109DE0_2C7D60_PirateDuel[0] = 0;
        }
        if (func_80029CE4_2A8E4(*PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->obj->model) >=
            func_80029D0C_2A90C(*PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel)->obj->model)) {
            D_80109DE0_2C7D60_PirateDuel[1] = 0;
        }
        if (D_80109D70_2C7CF0_PirateDuel == 1) {
            omDelObj(obj);
        }
        work->frame = (work->frame + 1) % 150;
    }
}

s32 func_80106E08_2C4D88_PirateDuel(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
        if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 0 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
            if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 1 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
            if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 2 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
            if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 3 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

/* Starts a CPU duelist's input script (func_80107724, pad triggers in D_80109DE8); 3F's
   func_80107EE4. Mode 2 (the challenger picks an opponent): with 20 coins or more, a random
   opponent with 20 coins among the best-ranked ones, else func_80106E08's choice. Mode 3 (the
   stake): a percentage of the poorer player's coins from the ranks and whether the star counts
   are within one, at least the minimum.
   Retail quirks: equal ranks index row -1 of the ranges; unlike 3F (whose rank-1 pass runs
   twice), the row uses the challenger's rank twice (never the opponent's). */
/* NON_MATCHING: 3F's twin, which does not match either (loop-guard and delay-slot shape). */
#define PD_ABS(x) ((x) < 0 ? -(x) : (x))
#ifdef NON_MATCHING
void func_801070F4_2C5074_PirateDuel(s32 cur, s32 target, s32 mode) {
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

    obj = omAddObj(0x10, 0, 0, -1, func_80107724_2C56A4_PirateDuel);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80109DE8_2C7D68_PirateDuel = 0;
    if (mode == 2) {
        if (gPlayers[D_80109D90_2C7D10_PirateDuel].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80109DB0_2C7D30_PirateDuel[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80109DA8_2C7D28_PirateDuel - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80109DB0_2C7D30_PirateDuel[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80106E08_2C4D88_PirateDuel();
            }
        } else {
            work->target = func_80106E08_2C4D88_PirateDuel();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_80109D90_2C7D10_PirateDuel) * 8;
        row += func_80059FD0_5ABD0(D_80109D90_2C7D10_PirateDuel) * 2;
        diff = PD_ABS(gPlayers[D_80109D90_2C7D10_PirateDuel].stars - gPlayers[D_80109D94_2C7D14_PirateDuel].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_80109DCC_2C7D4C_PirateDuel / 100;
        if (work->target < D_80109DC0_2C7D40_PirateDuel) {
            work->target = D_80109DC0_2C7D40_PirateDuel;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80109C68_2C7BE8_PirateDuel[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

const u32 D_80109CE8_2C7C68_PirateDuel[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

const u32 D_80109CF8_2C7C78_PirateDuel[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801070F4_2C5074_PirateDuel);
#endif

void func_80107724_2C56A4_PirateDuel(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80109DE8_2C7D68_PirateDuel = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80109DE8_2C7D68_PirateDuel = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80109DE8_2C7D68_PirateDuel = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80109DE8_2C7D68_PirateDuel = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80109DE8_2C7D68_PirateDuel = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80109DE8_2C7D68_PirateDuel = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_80109D74_2C7CF4_PirateDuel;
                if (work->cur == work->target) {
                    D_80109DE8_2C7D68_PirateDuel = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80109DE8_2C7D68_PirateDuel = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80109DE8_2C7D68_PirateDuel = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80109DE8_2C7D68_PirateDuel = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80109DE8_2C7D68_PirateDuel = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_801078C4_2C5844_PirateDuel(void) {
    return D_80109DE8_2C7D68_PirateDuel;
}

/* Sword clashes: when one duelist's motion is at the clash frame (D_80109BA4) while the other's
   has just started (under 15), sparks at the hit point (func_80108384) and both models flash
   orange for four frames, lit from the hit. */
void func_801078D0_2C5850_PirateDuel(void) {
    Vec dir;
    Vec pos;
    MBModel* a;
    MBModel* b;
    MBModel* hit;
    MBModel* other;
    f32 timeA;
    f32 timeB;
    f32 rot;
    s32 who;

    a = PLAYER_MODEL(D_80109D90_2C7D10_PirateDuel);
    b = PLAYER_MODEL(D_80109D94_2C7D14_PirateDuel);
    who = -1;
    timeA = func_80029CE4_2A8E4(*a->obj->model);
    timeB = func_80029CE4_2A8E4(*b->obj->model);
    if (timeA == D_80109BA4_2C7B24_PirateDuel && timeB > 0.0f && timeB < 15.0f && D_80109BA8_2C7B28_PirateDuel[0] == 0) {
        who = 0;
        D_80109BA8_2C7B28_PirateDuel[0] = 1;
    }
    if (timeB == D_80109BA4_2C7B24_PirateDuel && timeA > 0.0f && timeA < 15.0f && D_80109BA8_2C7B28_PirateDuel[0] == 0) {
        who = 1;
        D_80109BA8_2C7B28_PirateDuel[0] = 1;
    }
    if (timeA < D_80109BA4_2C7B24_PirateDuel && D_80109BA8_2C7B28_PirateDuel[0] == 1) {
        D_80109BA8_2C7B28_PirateDuel[0] = 0;
    }
    if (D_80109BAC_2C7B2C_PirateDuel == 0 && who >= 0) {
        if (who == 0) {
            other = a;
            hit = b;
        } else {
            other = b;
            hit = a;
        }
        rot = func_80042BE0_437E0(&hit->rot);
        pos.x = D_80109B98_2C7B18_PirateDuel.x;
        pos.y = D_80109B98_2C7B18_PirateDuel.y;
        pos.z = D_80109B98_2C7B18_PirateDuel.z;
        func_80042E44_43A44(&pos, rot);
        pos.x += hit->pos.x;
        pos.y += hit->pos.y;
        pos.z += hit->pos.z;
        func_80108384_2C6304_PirateDuel(pos.x, pos.y, pos.z, 9);
        PlaySound(0x3AE);
        D_80109BAC_2C7B2C_PirateDuel = 4;
        dir.x = D_80109B98_2C7B18_PirateDuel.x;
        dir.y = D_80109B98_2C7B18_PirateDuel.y;
        dir.z = D_80109B98_2C7B18_PirateDuel.z;
        MBVecNormalize(&dir);
        func_80042E44_43A44(&dir, rot);
        func_8002D2B4_2DEB4(*hit->obj->model, dir.x, dir.y, dir.z);
        func_8002D274_2DE74(*hit->obj->model, 240, 150, 80);
        dir.x = hit->pos.x + D_80109B98_2C7B18_PirateDuel.x - other->pos.x;
        dir.y = hit->pos.y + D_80109B98_2C7B18_PirateDuel.y - other->pos.y;
        dir.z = hit->pos.z + D_80109B98_2C7B18_PirateDuel.z - other->pos.z;
        MBVecNormalize(&dir);
        func_80042E44_43A44(&dir, func_80042BE0_437E0(&other->rot) - 180.0f);
        func_8002D2B4_2DEB4(*other->obj->model, dir.x, dir.y, dir.z);
        func_8002D274_2DE74(*other->obj->model, 240, 150, 80);
    }
    if (D_80109BAC_2C7B2C_PirateDuel != 0 && --D_80109BAC_2C7B2C_PirateDuel == 0) {
        func_8002D274_2DE74(*a->obj->model, 0, 0, 0);
        func_8002D274_2DE74(*b->obj->model, 0, 0, 0);
    }
}

/* Creates the streak effect (4F's func_8010D248/func_8010D4D8 for one slot): its object
   D_8010A100 (func_80108000), sixteen streaks, vertices and display lists per frame buffer. */
void func_80107D00_2C5C80_PirateDuel(void) {
    s32 i;

    D_8010A100_2C8080_PirateDuel = omAddObj(0x1F4, 1, 0, -1, func_80108000_2C5F80_PirateDuel);
    D_8010A100_2C8080_PirateDuel->unk_50 = func_80027154_27D54(16 * sizeof(PdStreak), 0x7918);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        D_8010A0C0_2C8040_PirateDuel[i] = func_80027154_27D54(48 * sizeof(Vtx), 0x7918);
        D_8010A0E0_2C8060_PirateDuel[i] = func_80027154_27D54(114 * sizeof(Gfx), 0x7918);
    }
    func_80107E20_2C5DA0_PirateDuel();
    D_8010A100_2C8080_PirateDuel->model[0] = func_80027FA4_28BA4(0x684, D_8010A0E0_2C8060_PirateDuel[D_800FDBE0_FE7E0], 4);
    D_8010A100_2C8080_PirateDuel->work[0] = 0;
}

/* The streaks' display lists: 16 shaded triangles (4F's func_8010D528). */
void func_80107E20_2C5DA0_PirateDuel(void) {
    Gfx* gfx;
    Vtx* vtx;
    s32 i;
    s32 rest;
    s32 n;
    s32 base;
    s32 k;

    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = D_8010A0E0_2C8060_PirateDuel[i];
        vtx = D_8010A0C0_2C8040_PirateDuel[i];
        rest = 48;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        base = 0;
        do {
            n = rest;
            if (rest >= 30) {
                n = 30;
            }
            rest -= n;
            gSPVertex(gfx++, &vtx[base], n, 0);
            for (k = 0; k < n; k += 3) {
                gSP1Triangle(gfx++, k, k + 1, k + 2, 0);
            }
            base += n;
        } while (rest != 0);
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
}

/* The streak effect's update (4F's func_8010D6FC): sixteen coloured streaks fly out from the
   object and fade; the effect object is D_8010A100 (one slot, unlike 4F's four).
   Retail quirk: the third vertex takes the second colour (4F's takes the third). */
/* NON_MATCHING: as 4F's twin, the green and blue fade clamps: retail sign-extends the
   differences as s16 before the clamp (two sll/sra pairs). Logic checked. */
#ifdef NON_MATCHING
void func_80108000_2C5F80_PirateDuel(omObjData* obj) {
    Vec dir;
    Vtx* vtx;
    PdStreak* p;
    s32 i;
    s32 k;
    s32 r;
    s16 g;
    s16 b;

    *(Gfx**)D_800FC834_FD434[obj->model[0]].hmf->unk3C = D_8010A0E0_2C8060_PirateDuel[D_800FDBE0_FE7E0];
    if (D_8010A100_2C8080_PirateDuel->work[0] != 0) {
        vtx = D_8010A0C0_2C8040_PirateDuel[D_800FDBE0_FE7E0];
        p = obj->unk_50;
        for (i = 0; i < 16; i++, p++) {
            dir.x = p->dir.x;
            dir.y = p->dir.y;
            dir.z = p->dir.z;
            MBVecNormalize(&dir);
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[0][k];
            }
            vtx->v.ob[0] = p->pos.x;
            vtx->v.ob[1] = p->pos.y;
            vtx->v.ob[2] = p->pos.z;
            vtx++;
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[1][k];
            }
            vtx->v.ob[0] = dir.x * p->len + p->pos.x;
            vtx->v.ob[1] = dir.y * p->len + p->pos.y;
            vtx->v.ob[2] = dir.z * p->len + p->pos.z;
            vtx++;
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[1][k];
            }
            vtx->v.ob[0] = (dir.x + 0.08f) * (p->len - 15.0f) + p->pos.x;
            vtx->v.ob[1] = (p->len - 15.0f) * dir.y + p->pos.y;
            vtx->v.ob[2] = (p->len - 15.0f) * dir.z + p->pos.z;
            vtx++;
            p->pos.x += dir.x * p->speed;
            p->pos.y += dir.y * p->speed;
            p->pos.z += dir.z * p->speed;
            for (k = 0; k < 3; k++) {
                r = p->col[k][0] - 5;
                if (r < 0) {
                    r = 0;
                }
                p->col[k][0] = r;
                g = p->col[k][1] - 13;
                if (g < 0) {
                    g = 0;
                }
                p->col[k][1] = g;
                b = p->col[k][2] - 18;
                if (b < 0) {
                    b = 0;
                }
                p->col[k][2] = b;
            }
        }
        if (++obj->work[2] >= obj->work[1]) {
            obj->work[0] = 0;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80108000_2C5F80_PirateDuel);
#endif

/* Starts the streak effect at (x, y, z) for `frames` frames (4F's func_8010DA90). */
void func_80108384_2C6304_PirateDuel(f32 x, f32 y, f32 z, u8 frames) {
    PdStreak* p;
    s32 i;
    s32 j;
    s32 k;

    omSetTra(D_8010A100_2C8080_PirateDuel, x, y, z);
    D_8010A100_2C8080_PirateDuel->work[1] = frames;
    D_8010A100_2C8080_PirateDuel->work[0] = 1;
    D_8010A100_2C8080_PirateDuel->work[2] = 0;
    func_800298A4_2A4A4(D_8010A100_2C8080_PirateDuel->model[0], 4, 0);
    p = D_8010A100_2C8080_PirateDuel->unk_50;
    for (i = 0; i < 16; i++, p++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                p->col[j][k] = D_80109BB0_2C7B30_PirateDuel[j][k];
            }
        }
        p->pos.x = p->pos.y = p->pos.z = 0.0f;
        p->len = (u8)(rand8() % 120) - 40;
        p->speed = (u8)(rand8() % 110) - 50;
        p->dir.x = HuMathSin((rand8() + rand8()) % 360);
        p->dir.y = HuMathSin((rand8() + rand8()) % 360);
        p->dir.z = HuMathSin((rand8() + rand8()) % 360);
        if (p->dir.x == 0.0f && p->dir.y == 0.0f && p->dir.z == 0.0f) {
            p->dir.y = 1.0f;
        }
        MBVecNormalize(&p->dir);
    }
}

/* A process: player D_80109DEC's item_hook model (D_80109DF4) is knocked off and falls out of
   view; D_80109DF0 is the style (1 spinning, 2 straight back). */
/* NON_MATCHING: masked 52, constant placement only: retail keeps 20.0f and 45.0f in FPRs and the
   call's 0.0f/90.0f bit patterns in GPRs; GCC here does the reverse for 20.0f and 0.0f. Same
   operations in the same order. */
#ifdef NON_MATCHING
void func_801086B0_2C6630_PirateDuel(void) {
    f32 x;
    f32 y;
    f32 z;
    f32 vy;
    f32 rot;

    func_8005AA98_5B698(D_80109DF4_2C7D74_PirateDuel[D_80109DEC_2C7D6C_PirateDuel]);
    func_8002979C_2A39C(D_80109DF4_2C7D74_PirateDuel[D_80109DEC_2C7D6C_PirateDuel], 0.0f, 0.0f, 0.0f);
    vy = 20.0f;
    if (D_80109DF0_2C7D70_PirateDuel == 2) {
        vy = 0.0f;
    }
    x = PLAYER_MODEL(D_80109DEC_2C7D6C_PirateDuel)->pos.x;
    y = PLAYER_MODEL(D_80109DEC_2C7D6C_PirateDuel)->pos.y + 100.0f;
    z = PLAYER_MODEL(D_80109DEC_2C7D6C_PirateDuel)->pos.z;
    rot = 0.0f;
    while (y > 0.0f) {
        if (D_80109DF0_2C7D70_PirateDuel == 2) {
            x -= 40.0f;
        } else if (D_80109DEC_2C7D6C_PirateDuel != D_80109D90_2C7D10_PirateDuel) {
            x += 20.0f;
        } else {
            x -= 20.0f;
        }
        y += vy;
        vy -= 2.0f;
        if (D_80109DF0_2C7D70_PirateDuel == 1) {
            if (D_80109DEC_2C7D6C_PirateDuel != D_80109D90_2C7D10_PirateDuel) {
                rot += 45.0f;
            } else {
                rot -= 45.0f;
            }
        }
        func_80029714_2A314(D_80109DF4_2C7D74_PirateDuel[D_80109DEC_2C7D6C_PirateDuel], x, y, z);
        func_8002979C_2A39C(D_80109DF4_2C7D74_PirateDuel[D_80109DEC_2C7D6C_PirateDuel], 0.0f, 90.0f, rot);
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801086B0_2C6630_PirateDuel);
#endif

__asm__(".section .rodata");
const u32 D_80109D08_2C7C88_PirateDuel[6] = { 0x425C0000, 0x41F00000, 0x425C0000, 0x42480000, 0x41F00000, 0x41A00000 };

__asm__(".section .rodata");
const u32 D_80109D20_2C7CA0_PirateDuel[6] = { 0x428C0000, 0x42A00000, 0x42A00000, 0x42A00000, 0x428C0000, 0x42480000 };

__asm__(".section .rodata");
const u32 D_80109D38_2C7CB8_PirateDuel[6] = { 0x42200000, 0x41F00000, 0x00000000, 0x00000000, 0x00000000, 0xC1200000 };

__asm__(".section .rodata");
const u32 D_80109D50_2C7CD0_PirateDuel[6] = { 0x41200000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801088FC_2C687C_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80108F98_2C6F18_PirateDuel);

__asm__(".section .rodata");
const u32 D_80109D68_2C7CE8_PirateDuel[2] = { 0x0058002E, 0x00E8002E };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109040_2C6FC0_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_8010913C_2C70BC_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109214_2C7194_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109344_2C72C4_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801093D8_2C7358_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801094D4_2C7454_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109648_2C75C8_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109780_2C7700_PirateDuel);
