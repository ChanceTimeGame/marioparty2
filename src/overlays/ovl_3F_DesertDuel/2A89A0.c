#include "common.h"
#include "ovl_3F.h"

#ifdef NON_MATCHING /* rodata-pending */
void func_80102800_2A89A0_DesertDuel(void) {
    omInitObjMan(30, 10);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_801029C0_2A8B60_DesertDuel();
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
    omAddPrcObj(func_80102D1C_2A8EBC_DesertDuel, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102C3C_2A8DDC_DesertDuel);
    D_80108C54_2AEDF4_DesertDuel = 0;
    func_80104D28_2AAEC8_DesertDuel();
    D_80108CD8_2AEE78_DesertDuel = 0;
    func_8007273C_7333C("\x82\x60\x82\x61\x82\x62\x81\x49", 1); /* SJIS "ABC!" */
    func_8007273C_7333C("\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58", 1); /* SJIS "0123456789" */
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80102800_2A89A0_DesertDuel);
#endif

/* Who is in the scene: the challenger (D_800F8D1A.attacker's bit), the players it may challenge
   (.targets), and the opponent when there is only one. Flag 0x19 (debug) lets A/B override. */
void func_801029C0_2A8B60_DesertDuel(void) {
    s32 bits;
    s32 i;

    D_800F8FE0_F9BE0 = 0;
    D_800FC87A_FD47A = 0;
    D_800FA606_FB206 = 0;
    D_80108C14_2AEDB4_DesertDuel = GwSystem.current_player_index;
    D_80108C1C_2AEDBC_DesertDuel = -1;
    D_80108C30_2AEDD0_DesertDuel = 0;
    for (i = 0; i < 2; i++) {
        D_80108C5C_2AEDFC_DesertDuel[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        D_80108C38_2AEDD8_DesertDuel[i] = 0;
    }
    D_80108C7C_2AEE1C_DesertDuel = 0;
    D_80108C9C_2AEE3C_DesertDuel = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108C9C_2AEE3C_DesertDuel = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108C9C_2AEE3C_DesertDuel = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108C9C_2AEE3C_DesertDuel = 1;
        }
    }
    D_80108C18_2AEDB8_DesertDuel = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108C18_2AEDB8_DesertDuel++;
    }
    D_80108C48_2AEDE8_DesertDuel = 1;
    D_80108C38_2AEDD8_DesertDuel[i] = 1;
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
            D_80108C48_2AEDE8_DesertDuel++;
            D_80108C38_2AEDD8_DesertDuel[i] = 1;
        }
    }
    if (D_80108C48_2AEDE8_DesertDuel == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108C38_2AEDD8_DesertDuel[i] == 1 && i != D_80108C18_2AEDB8_DesertDuel) {
                D_80108C1C_2AEDBC_DesertDuel = i;
                break;
            }
        }
    }
    D_80108C90_2AEE30_DesertDuel = GwSystem.current_turn;
}

void func_80102C3C_2A8DDC_DesertDuel(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C90_2A8E30_DesertDuel(void) {
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

void func_80102D1C_2A8EBC_DesertDuel(void) {
    func_80102D48_2A8EE8_DesertDuel();
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* NON_MATCHING once carved (masked ~110 of 1995, all scheduling/registers): GCC copies the exit test
   of the referee's drop loop to the loop top (retail keeps only the bottom test), which renames
   registers after it; the per-character table load picks other registers. */
/* The duel: duelists and the referee walk in, the opponent and the stake are chosen, then rounds
   are played until one decides it (D_80108C58, from func_80106600: 1 draw, 3/5 a duelist wins,
   2/4 decided only when D_80108C5C[0]/[1] is 2); the winner takes both stakes. */
#define WAIT_STEP()                              \
    while (TRUE) {                               \
        if (D_80108C50_2AEDF0_DesertDuel != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

#define WAIT_MESSAGE()                                                        \
    while (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {     \
        HuPrcVSleep();                                                        \
    }

#ifdef NON_MATCHING /* NON_MATCHING; also a rodata user (motions, "item_hook", the jump table) */
void func_80102D48_2A8EE8_DesertDuel(void) {
    ModelPathWork* work[4];
    s16 hook[4];
    Vec pos[2];
    u32 motions[4] = { 3, 0x800A7, 0x800AC, 0x800AA };
    MBModel* model;
    s16 mes;
    u16 done;
    s32 rounds;
    s32 layout;
    s32 i;

    func_80050E00_51A00(3);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 4; i++) {
        if (D_80108C38_2AEDD8_DesertDuel[i] != 0) {
            MBPlayerModelCreate(i, D_80108928_2AEAC8_DesertDuel[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 1, 0);
            PLAYER_MODEL(i)->pos.x = -1000.0f;
            PLAYER_MODEL(i)->pos.y = 0.0f;
            PLAYER_MODEL(i)->pos.z = 700.0f;
            gPlayers[i].flags |= 2;
            func_80043DAC_449AC(PLAYER_MODEL(i));
            hook[i] = LoadFormFile(0xA0191, 0x689);
            func_8005AA48_5B648(PLAYER_MODEL(i), "item_hook", hook[i]);
        }
    }
    D_80108CA4_2AEE44_DesertDuel = MBModelFileCreate(0x800A6, 0xD, 1.0f, 1.0f, motions);
    func_8005AB50_5B750(D_80108CA4_2AEE44_DesertDuel, 1, 0xB, D_80108940_2AEAE0_DesertDuel);
    D_80108CA4_2AEE44_DesertDuel->pos.x = D_80108948_2AEAE8_DesertDuel.x;
    D_80108CA4_2AEE44_DesertDuel->pos.y = 0.0f;
    D_80108CA4_2AEE44_DesertDuel->pos.z = D_80108948_2AEAE8_DesertDuel.z;
    func_80056658_57258(&D_80108CA4_2AEE44_DesertDuel->pos, &D_80108948_2AEAE8_DesertDuel, &D_80108CA4_2AEE44_DesertDuel->rot);
    if (D_80108C9C_2AEE3C_DesertDuel == 0) {
        D_80108CA4_2AEE44_DesertDuel->jumpY = D_80108948_2AEAE8_DesertDuel.y;
        D_80108CA4_2AEE44_DesertDuel->jumpVel = 7.5f;
        D_80108CA4_2AEE44_DesertDuel->jumpAccel = 0.0f;
        D_80108CA8_2AEE48_DesertDuel = MBModelFileCreate(0xA019D, 0xD, 1.0f, 1.0f, NULL);
        D_80108CA8_2AEE48_DesertDuel->pos.x = D_80108948_2AEAE8_DesertDuel.x;
        D_80108CA8_2AEE48_DesertDuel->pos.y = 0.0f;
        D_80108CA8_2AEE48_DesertDuel->pos.z = D_80108948_2AEAE8_DesertDuel.z;
        D_80108CA8_2AEE48_DesertDuel->jumpY = D_80108948_2AEAE8_DesertDuel.y;
        D_80108CA8_2AEE48_DesertDuel->jumpVel = 7.5f;
        D_80108CA8_2AEE48_DesertDuel->jumpAccel = 0.0f;
    }
    PlayMusic(0x25);
    InitFadeIn(0, 0x10);
    if (D_80108C9C_2AEE3C_DesertDuel == 0) {
        /* the referee drops in with his hat */
        for (D_80108C4C_2AEDEC_DesertDuel = 0;; D_80108C4C_2AEDEC_DesertDuel++) {
            D_80108CA8_2AEE48_DesertDuel->jumpY = D_80108CA4_2AEE44_DesertDuel->jumpY;
            D_80108CA4_2AEE44_DesertDuel->jumpY -= D_80108CA4_2AEE44_DesertDuel->jumpVel;
            if (D_80108CA4_2AEE44_DesertDuel->jumpY <= D_80108CA4_2AEE44_DesertDuel->pos.y) {
                break;
            }
            if (D_80108C4C_2AEDEC_DesertDuel == 1) {
                func_80104DF4_2AAF94_DesertDuel(D_80108CD4_2AEE74_DesertDuel);
            }
            HuPrcVSleep();
        }
        D_80108CA4_2AEE44_DesertDuel->jumpY = D_80108CA4_2AEE44_DesertDuel->pos.y;
        func_80104354_2AA4F4_DesertDuel();
        layout = (D_80108C48_2AEDE8_DesertDuel == 4) ? 0 : -1;
        if (D_80108C48_2AEDE8_DesertDuel == 3) {
            layout = 6;
        }
        if (layout != -1) {
            /* three or four players: the challenger picks the opponent */
            func_80104474_2AA614_DesertDuel(layout);
            WAIT_STEP();
            PlaySound(0xE8);
            omAddPrcObj(func_801049AC_2AAB4C_DesertDuel, 0x12, 0, 0);
            D_80108C50_2AEDF0_DesertDuel = 0;
            WAIT_STEP();
            func_80104474_2AA614_DesertDuel(1);
            WAIT_STEP();
            func_80104474_2AA614_DesertDuel(2);
            WAIT_STEP();
        } else {
            func_80104474_2AA614_DesertDuel(7);
            WAIT_STEP();
        }
        MBVsSprCreateY(160.0f, 90.0f);
        HuPrcSleep(10);
        D_80108CD8_2AEE78_DesertDuel = 6;
        func_80104474_2AA614_DesertDuel(3);
        WAIT_STEP();
        omAddPrcObj(func_80105054_2AB1F4_DesertDuel, 0x12, 0, 0);
        func_80104C9C_2AAE3C_DesertDuel();
        D_80108C50_2AEDF0_DesertDuel = 0;
        WAIT_STEP();
        func_80104474_2AA614_DesertDuel(4);
        MBVsSprKill();
        if (D_80108C9C_2AEE3C_DesertDuel == 0) {
            omDelObj(D_80108CE0_2AEE80_DesertDuel);
        }
        WAIT_STEP();
    }
    /* the duelists walk to their marks */
    PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel)->pos.x = -400.0f;
    PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel)->pos.x = 400.0f;
    MBMotionShiftSet(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 0, 0, 5, 2);
    work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 15.0f, 1, D_80108984_2AEB24_DesertDuel);
    MBMotionShiftSet(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 0, 0, 5, 2);
    work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 15.0f, 1, D_80108990_2AEB30_DesertDuel);
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
    MBMotionShiftSet(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 2, 0, 5, 2);
    MBMotionShiftSet(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 2, 0, 5, 2);
    /* the referee walks to the middle */
    work[0] = func_8005A718_5B318(D_80108CA4_2AEE44_DesertDuel, 30.0f, 1, D_80108960_2AEB00_DesertDuel);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    model = D_80108CA4_2AEE44_DesertDuel;
    model->rot.x = __sinf(0.34906584f); /* 20 degrees */
    model = D_80108CA4_2AEE44_DesertDuel;
    model->rot.y = 0.0f;
    model->rot.z = __cosf(0.34906584f);
    D_80108CA4_2AEE44_DesertDuel->obj->rot.z = 20.0f;
    PlaySound(0xE8);
    omAddPrcObj(func_801058C8_2ABA68_DesertDuel, 0x12, 0, 0);
    D_80108C50_2AEDF0_DesertDuel = 0;
    WAIT_STEP();
    D_80108CA4_2AEE44_DesertDuel->rot.x = HuMathSin(0.0f);
    D_80108CA4_2AEE44_DesertDuel->rot.y = 0.0f;
    D_80108CA4_2AEE44_DesertDuel->rot.z = func_800B7890_B8490(D_80108CA4_2AEE44_DesertDuel->rot.y);
    D_80108CA4_2AEE44_DesertDuel->obj->rot.z = 0.0f;
    work[0] = func_8005A718_5B318(D_80108CA4_2AEE44_DesertDuel, 30.0f, 1, D_80108954_2AEAF4_DesertDuel);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    rounds = 0;
    HuMemMemoryFreePerm(work[0]);
    D_80108CA4_2AEE44_DesertDuel->rot.x = HuMathSin(0.0f);
    D_80108CA4_2AEE44_DesertDuel->rot.y = 0.0f;
    D_80108CA4_2AEE44_DesertDuel->rot.z = func_800B7890_B8490(D_80108CA4_2AEE44_DesertDuel->rot.y);
    func_8008CE5C_8DA5C();
    do {
        D_80108C78_2AEE18_DesertDuel = 0;
        HuPrcSleep(15);
        func_80088640_89240();
        D_80108C68_2AEE08_DesertDuel = 0x214;
        D_80108C6C_2AEE0C_DesertDuel = 90;
        D_80108C70_2AEE10_DesertDuel = 70;
        D_80108C74_2AEE14_DesertDuel = 4;
        omAddPrcObj(func_80105AAC_2ABC4C_DesertDuel, 0x12, 0, 0);
        D_80108C50_2AEDF0_DesertDuel = 0;
        WAIT_STEP();
        /* face off */
        MBMotionShiftSet(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 0, 0, 5, 2);
        func_8005ACD0_5B8D0(&gPlayers[D_80108C18_2AEDB8_DesertDuel], 0xB);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 5.0f, 1, &D_8010899C_2AEB3C_DesertDuel[0]);
        MBMotionShiftSet(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 0, 0, 5, 2);
        func_8005ACD0_5B8D0(&gPlayers[D_80108C1C_2AEDBC_DesertDuel], 0xB);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 5.0f, 1, &D_8010899C_2AEB3C_DesertDuel[1]);
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
        MBMotionShiftSet(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), 2, 0, 5, 2);
        HuVecCopyXYZ(&pos[0], 0.0f, PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel)->pos.y, PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel)->pos.z);
        HuVecCopyXYZ(&pos[1], 0.0f, PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel)->pos.y, PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel)->pos.z);
        func_800446B4_452B4(PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_80108C1C_2AEDBC_DesertDuel), &pos[1], 10);
        HuPrcSleep(20);
        func_8008CE5C_8DA5C();
        func_800691FC_69DFC(1);
        WAIT_MESSAGE();
        HuPrcSleep(18);
        D_80108C50_2AEDF0_DesertDuel = 0;
        D_80108C58_2AEDF8_DesertDuel = 0;
        func_80106040_2AC1E0_DesertDuel();
        omAddPrcObj(func_80106600_2AC7A0_DesertDuel, 0x12, 0, 0);
        WAIT_STEP();
        switch (D_80108C58_2AEDF8_DesertDuel) {
            case 2:
                rounds += D_80108C5C_2AEDFC_DesertDuel[0] == 2;
                break;
            case 4:
                rounds += D_80108C5C_2AEDFC_DesertDuel[1] == 2;
                break;
            case 3:
                D_80108C30_2AEDD0_DesertDuel = D_80108C18_2AEDB8_DesertDuel;
                rounds++;
                break;
            case 5:
                D_80108C30_2AEDD0_DesertDuel = D_80108C1C_2AEDBC_DesertDuel;
                rounds++;
                break;
            case 1:
                D_80108C30_2AEDD0_DesertDuel = -1;
                if (D_80108C9C_2AEE3C_DesertDuel != 0) {
                    func_800794A8_7A0A8(30);
                    HuPrcSleep(45);
                }
                rounds++;
                break;
        }
    } while (rounds == 0);
    if (D_80108C9C_2AEE3C_DesertDuel == 0) {
        D_80108C50_2AEDF0_DesertDuel = 0;
        func_80104474_2AA614_DesertDuel(2);
        WAIT_STEP();
    }
    if (D_80108C30_2AEDD0_DesertDuel == -1) {
        /* a draw: both get their stake back */
        D_800F8C5C_F985C = D_800FC880_FD480 = D_80108C30_2AEDD0_DesertDuel;
        if (D_80108C9C_2AEE3C_DesertDuel == 0) {
            MBMotionShiftSet(D_80108CA4_2AEE44_DesertDuel, 2, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_80108CA4_2AEE44_DesertDuel, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_80108C68_2AEE08_DesertDuel = 0x216;
            D_80108C6C_2AEE0C_DesertDuel = 85;
            D_80108C70_2AEE10_DesertDuel = 70;
            D_80108C74_2AEE14_DesertDuel = 5;
            omAddPrcObj(func_80105AAC_2ABC4C_DesertDuel, 0x12, 0, 0);
            D_80108C50_2AEDF0_DesertDuel = 0;
            WAIT_STEP();
            func_800614B4_620B4(D_80108C18_2AEDB8_DesertDuel, D_80108C34_2AEDD4_DesertDuel);
            func_8006135C_61F5C(D_80108C1C_2AEDBC_DesertDuel, D_80108C34_2AEDD4_DesertDuel, 0);
            func_800794A8_7A0A8(30);
            HuPrcSleep(30);
        }
        PlayMusic(0x57);
        func_800691FC_69DFC(0x13);
        WAIT_MESSAGE();
    } else {
        D_800FC880_FD480 = D_80108C30_2AEDD0_DesertDuel;
        if (D_80108C30_2AEDD0_DesertDuel == D_80108C18_2AEDB8_DesertDuel) {
            D_800F8C5C_F985C = D_80108C1C_2AEDBC_DesertDuel;
        } else {
            D_800F8C5C_F985C = D_80108C18_2AEDB8_DesertDuel;
        }
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 0);
        MBMotionShiftSet(PLAYER_MODEL(D_80108C30_2AEDD0_DesertDuel), 4, 0, 5, 0);
        MBMotionShiftSet(PLAYER_MODEL(D_800F8C5C_F985C), 4, 0, 5, 0);
        HuPrcSleep(55);
        func_800298A4_2A4A4(hook[D_80108C30_2AEDD0_DesertDuel], 4, 4);
        func_800298A4_2A4A4(hook[D_800F8C5C_F985C], 4, 4);
        /* both turn to the camera; retail takes y from the challenger for both */
        HuVecCopyXYZ(&pos[0], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel)->pos.y, D_800C9B80_CA780->pos.z);
        HuVecCopyXYZ(&pos[1], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_80108C18_2AEDB8_DesertDuel)->pos.y, D_800C9B80_CA780->pos.z);
        func_800446B4_452B4(PLAYER_MODEL(D_80108C30_2AEDD0_DesertDuel), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_800F8C5C_F985C), &pos[1], 10);
        HuPrcSleep(20);
        if (D_80108C9C_2AEE3C_DesertDuel == 0) {
            MBMotionShiftSet(D_80108CA4_2AEE44_DesertDuel, 2, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_80108CA4_2AEE44_DesertDuel, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_80108C68_2AEE08_DesertDuel = 0x215;
            D_80108C6C_2AEE0C_DesertDuel = 90;
            D_80108C70_2AEE10_DesertDuel = 70;
            D_80108C74_2AEE14_DesertDuel = 7;
            omAddPrcObj(func_80105AAC_2ABC4C_DesertDuel, 0x12, 0, 0);
            D_80108C50_2AEDF0_DesertDuel = 0;
            WAIT_STEP();
            func_800614B4_620B4(D_80108C30_2AEDD0_DesertDuel, D_80108C34_2AEDD4_DesertDuel * 2);
            func_800794A8_7A0A8(30);
            if (D_80108CA2_2AEE42_DesertDuel != -1) {
                func_800799A4_7A5A4(D_80108CA2_2AEE42_DesertDuel, 40);
            }
            HuPrcSleep(30);
        }
        PlayMusic(0x51);
        func_800732FC_73EFC(D_80108928_2AEAC8_DesertDuel[gPlayers[D_80108C30_2AEDD0_DesertDuel].character][7],
                            (D_80108C30_2AEDD0_DesertDuel == D_80108C18_2AEDB8_DesertDuel) ? 0x2C : 0x54, D_800FC880_FD480);
        MBMotionShiftSet(PLAYER_MODEL(D_80108C30_2AEDD0_DesertDuel), 6, 0, 5, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_80108C30_2AEDD0_DesertDuel], 1);
        mes = func_800797DC_7A3DC(0xFC, D_800F8C5C_F985C);
        if (D_800F8C5C_F985C == D_80108C18_2AEDB8_DesertDuel) {
            func_800798F8_7A4F8(mes, 0x2C);
        } else {
            func_800798F8_7A4F8(mes, 0x54);
        }
        MBMotionShiftSet(PLAYER_MODEL(D_800F8C5C_F985C), 7, 0, 5, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 2);
        if (D_80108C58_2AEDF8_DesertDuel == 2 || D_80108C58_2AEDF8_DesertDuel == 4) {
            omAddPrcObj(func_80107A00_2ADBA0_DesertDuel, 0x12, 0, 0);
        }
        func_800691FC_69DFC(6, gPlayers[D_80108C30_2AEDD0_DesertDuel].character);
        WAIT_MESSAGE();
    }
    HuPrcSleep(8);
    for (i = 0; i < D_80108C7C_2AEE1C_DesertDuel; i++) {
        D_800F9570_FA170[D_80108C88_2AEE28_DesertDuel[i]].stat |= 2;
    }
    func_80107314_2AD4B4_DesertDuel();
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80102D48_2A8EE8_DesertDuel);
#endif

/* The referee's hat flies off: it shrinks and spins for 15 frames, then hides. */
void func_80104354_2AA4F4_DesertDuel(void) {
    omObjData* obj;
    Unk3FShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_801043E4_2AA584_DesertDuel);
    work = func_80027154_27D54(sizeof(Unk3FShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_801043E4_2AA584_DesertDuel(omObjData* obj) {
    Unk3FShrink* work = obj->unk_50;

    D_80108CA8_2AEE48_DesertDuel->scale.x += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->scale.y += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->scale.z += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108CA8_2AEE48_DesertDuel);
        omDelObj(obj);
    }
}

/* Moves the status windows of the players in the scene to layout `layout` of D_80108730; the
   challenger takes slot 3, the chosen opponent slot 2, the others slots 0, 1 (and are listed in
   D_80108C20). D_80108C50 is set when every window has arrived. */
void func_80104474_2AA614_DesertDuel(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108C50_2AEDF0_DesertDuel = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_801047AC_2AA94C_DesertDuel);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108C38_2AEDD8_DesertDuel[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108C18_2AEDB8_DesertDuel) {
                if (i == D_80108C1C_2AEDBC_DesertDuel) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108C20_2AEDC0_DesertDuel[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][0] != -1) {
                status->xPos = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][0];
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][1] != -1) {
                status->yPos = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80108730_2AE8D0_DesertDuel[layout].frames - 1;
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][2];
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80108CD8_2AEE78_DesertDuel == 6) {
        status = &D_80101510_102110[D_80108C18_2AEDB8_DesertDuel];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80108730_2AE8D0_DesertDuel[layout].frames - 1;
    }
}

void func_801047AC_2AA94C_DesertDuel(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108C38_2AEDD8_DesertDuel[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108C48_2AEDE8_DesertDuel) {
        D_80108C50_2AEDF0_DesertDuel = 1;
        omDelObj(obj);
    }
}

/* Opens a message window that only the duelists' pads can advance. */
/* NON_MATCHING: registers (masked 14): retail keeps the raw window id in s2 and its s16 copy in s1
   (arg6 in s0) and narrows the mask in each branch. */
#ifdef NON_MATCHING
s16 func_80104844_2AA9E4_DesertDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s16 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108C1C_2AEDBC_DesertDuel != -1) {
        mask = (1 << gPlayers[D_80108C18_2AEDB8_DesertDuel].port) | (1 << gPlayers[D_80108C1C_2AEDBC_DesertDuel].port);
    } else {
        mask = 1 << gPlayers[D_80108C18_2AEDB8_DesertDuel].port;
    }
    func_8008D59C_8E19C(win, mask);
    return win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104844_2AA9E4_DesertDuel);
#endif

/* The challenger picks an opponent from D_80108C20 (cursor rows at ys[]); a CPU challenger's
   input comes from func_80107EE4's script. Sets D_80108C1C and D_80108C50, then ends. */
#ifdef NON_MATCHING /* rodata-pending */
void func_801049AC_2AAB4C_DesertDuel(void) {
    s32 ys4[3] = { 32, 90, 148 };
    s32 ys3[2] = { 59, 121 };
    s32 ys[4];
    s16 size[2];
    s32* src;
    s16 win;
    s16 spr;
    u16 btn;
    s32 sel;
    s32 count;
    s32 i;

    func_8008DACC_8E6CC(1, size, 0x212);
    win = func_80104844_2AA9E4_DesertDuel(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108C48_2AEDE8_DesertDuel - 1;
    if (D_80108C48_2AEDE8_DesertDuel == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108C48_2AEDE8_DesertDuel; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espPosSet(spr, 184, ys[sel]);
    espDispOn(spr);
    if (gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) {
        func_80107EE4_2AE084_DesertDuel(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80107940_2ADAE0_DesertDuel();
        if (gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) {
            btn = func_80108720_2AE8C0_DesertDuel();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108C20_2AEDC0_DesertDuel[sel], 1) != 0) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            D_80108C50_2AEDF0_DesertDuel = 1;
            D_80108C1C_2AEDBC_DesertDuel = D_80108C20_2AEDC0_DesertDuel[sel];
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801049AC_2AAB4C_DesertDuel);
#endif

/* A tumbleweed every 210 frames. */
void func_80104C9C_2AAE3C_DesertDuel(void) {
    D_80108C4C_2AEDEC_DesertDuel = 210;
    D_80108CE0_2AEE80_DesertDuel = omAddObj(0x10, 0, 0, -1, func_80104CE4_2AAE84_DesertDuel);
}

void func_80104CE4_2AAE84_DesertDuel(omObjData* obj) {
    if (--D_80108C4C_2AEDEC_DesertDuel == 0) {
        func_80104DF4_2AAF94_DesertDuel(D_80108CD4_2AEE74_DesertDuel);
        D_80108C4C_2AEDEC_DesertDuel = 210;
    }
}

/* The tumbleweed: model 0xA019E with shadow 0x0D. */
void func_80104D28_2AAEC8_DesertDuel(void) {
    omObjData* obj;
    Unk3FTumbleweed* work;

    obj = omAddObj(0x10, 3, 3, -1, func_80104EF8_2AB098_DesertDuel);
    obj->model[0] = LoadFormFile(0xA019E, 0x699);
    obj->model[1] = LoadFormFile(0xD, 0x299);
    work = func_80027154_27D54(sizeof(Unk3FTumbleweed), 0x7918);
    obj->unk_50 = work;
    obj->trans.x = 600.0f;
    obj->trans.y = 45.0f;
    obj->trans.z = 1500.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    work->active = 0;
    work->count = 0;
    D_80108CD4_2AEE74_DesertDuel = obj;
}

/* Starts the tumbleweed across the stage: the first time from the right, then from a random side. */
void func_80104DF4_2AAF94_DesertDuel(omObjData* obj) {
    Unk3FTumbleweed* work = obj->unk_50;

    work->active = 1;
    work->rot = 0.0f;
    work->count &= 0xFF;
    if (work->count == 0 || (rand8() & 1)) {
        work->startX = 140.0f;
        work->endX = -300.0f;
        work->speed = -13.0f;
    } else {
        work->startX = -140.0f;
        work->endX = 300.0f;
        work->speed = 13.0f;
    }
    obj->trans.x = work->startX * 5.0f;
    obj->trans.y = 45.0f;
    obj->trans.z = 1350.0f;
    work->count++;
}

void func_80104EF8_2AB098_DesertDuel(omObjData* obj) {
    Unk3FTumbleweed* work = obj->unk_50;

    if (work->active) {
        obj->trans.x += work->speed;
        obj->trans.y = 36.0f;
        obj->trans.z = 850.0f;
        work->rot -= work->speed;
        if (work->rot < 0.0f) {
            work->rot += 360.0f;
        }
        omSetRot(obj, 0.0f, 0.0f, work->rot);
        omSetSca(obj, 0.8f, 0.8f, 0.8f);
        func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
        if ((work->speed < 0.0f && obj->trans.x < work->endX) || (work->speed > 0.0f && obj->trans.x > work->endX)) {
            work->active = 0;
        }
    }
}

/* The stake: the starting amount comes from the turn (D_80108A68 bands) and the poorer player's
   coins (D_80108A50 amounts); right/left add or take 1, up/down 10, A accepts. Both duelists pay
   the stake as it changes. Retail quirk: at the 999 cap a further raise still takes the coin from
   both players. */
#define DUEL_STAKE_SHOW(win, stake)                                         \
    sprintf(num, "%d", stake);                                              \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

#ifdef NON_MATCHING /* rodata-pending */
void func_80105054_2AB1F4_DesertDuel(void) {
    char buf[0x200];
    char mess[0x20];
    s16 size[2];
    s32 stakes[6] = { 1, 5, 10, 20, 30, 50 };
    s32 turns[4] = { 11, 21, 36, 46 };
    char num[8];
    char pad[16];
    s16 win;
    s32 coins1;
    s32 coins2;
    u16 btn;
    s32 stake;
    s32 len;
    s32 turn;
    s32 x;
    s32 y;
    s32 i;
    s32 j;

    turn = D_80108C90_2AEE30_DesertDuel;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80108C18_2AEDB8_DesertDuel)->coins;
    coins2 = BoardPlayerGet(D_80108C1C_2AEDBC_DesertDuel)->coins;
    D_80108C94_2AEE34_DesertDuel = coins1;
    if (coins2 < coins1) {
        D_80108C94_2AEE34_DesertDuel = coins2;
    }
    i++;
    while (D_80108C94_2AEE34_DesertDuel < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80108C34_2AEDD4_DesertDuel = D_80108C8C_2AEE2C_DesertDuel = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108C8C_2AEE2C_DesertDuel;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80104844_2AA9E4_DesertDuel(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    DUEL_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80108C18_2AEDB8_DesertDuel);
    AdjustPlayerCoins(D_80108C18_2AEDB8_DesertDuel, -D_80108C34_2AEDD4_DesertDuel);
    AdjustPlayerCoins(D_80108C1C_2AEDBC_DesertDuel, -D_80108C34_2AEDD4_DesertDuel);
    func_80089284_89E84(win, 0x10004, 0x10004);
    if (gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) {
        func_80107EE4_2AE084_DesertDuel(D_80108C34_2AEDD4_DesertDuel, D_80108C94_2AEE34_DesertDuel, 3);
    }
    while (TRUE) {
        D_80108C34_2AEDD4_DesertDuel = stake;
        btn = ContDStkTrg[gPlayers[D_80108C18_2AEDB8_DesertDuel].port];
        if (gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) {
            btn = func_80108720_2AE8C0_DesertDuel();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80108C50_2AEDF0_DesertDuel = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80108C18_2AEDB8_DesertDuel].coins > 0 && gPlayers[D_80108C1C_2AEDBC_DesertDuel].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                DUEL_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108C18_2AEDB8_DesertDuel, -1);
                AdjustPlayerCoins(D_80108C1C_2AEDBC_DesertDuel, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108C8C_2AEE2C_DesertDuel < stake) {
                stake--;
                PlaySound(0x37C);
                DUEL_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108C18_2AEDB8_DesertDuel, 1);
                AdjustPlayerCoins(D_80108C1C_2AEDBC_DesertDuel, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108C8C_2AEE2C_DesertDuel) {
                stake -= 10;
                PlaySound(0x37C);
                DUEL_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108C18_2AEDB8_DesertDuel, 10);
                AdjustPlayerCoins(D_80108C1C_2AEDBC_DesertDuel, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80108C18_2AEDB8_DesertDuel].coins >= 10 && gPlayers[D_80108C1C_2AEDBC_DesertDuel].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                DUEL_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108C18_2AEDB8_DesertDuel, -10);
                AdjustPlayerCoins(D_80108C1C_2AEDBC_DesertDuel, -10);
            }
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105054_2AB1F4_DesertDuel);
#endif

/* The duel's opening message (0x219, both duelists named); waits for Start from either duelist (or
   from the CPU script when both are CPUs). */
void func_801058C8_2ABA68_DesertDuel(void) {
    s16 size[2];
    s16 win;
    u16 btn;

    func_8008DACC_8E6CC(1, size, 0x219);
    win = func_80104844_2AA9E4_DesertDuel(100, 40, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x219, -1, -1);
    func_80057A78_58678(win, D_80108C18_2AEDB8_DesertDuel, D_80108C1C_2AEDBC_DesertDuel);
    D_800F851A_F911A = 1;
    if ((gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) && (gPlayers[D_80108C1C_2AEDBC_DesertDuel].flags & 1)) {
        func_80107EE4_2AE084_DesertDuel(0, 0, 0);
    }
    while (TRUE) {
        if ((gPlayers[D_80108C18_2AEDB8_DesertDuel].flags & 1) && (gPlayers[D_80108C1C_2AEDBC_DesertDuel].flags & 1)) {
            btn = func_80108720_2AE8C0_DesertDuel();
        } else {
            btn = func_80107940_2ADAE0_DesertDuel();
        }
        if (btn & 0x1000) {
            PlaySound(2);
            D_80108C50_2AEDF0_DesertDuel = 1;
            func_8008CCA8_8D8A8(win);
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
}

/* A duel message window: message D_80108C68 at (D_80108C6C, D_80108C70); mode D_80108C74 says
   what it shows (5: the stake, 7: the stake and the winner's name) and how it ends (0: when
   D_80108C50 is set, 1: Start, 2/3: A, 4/5/7: at once, 6: at once, leaving the process running). */
#ifdef NON_MATCHING /* rodata-pending */
void func_80105AAC_2ABC4C_DesertDuel(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s16 win;

    if (D_80108C74_2AEE14_DesertDuel == 5) {
        sprintf(num, "%d", D_80108C34_2AEDD4_DesertDuel);
        func_8008D974_8E574(num, 0);
    }
    if (D_80108C74_2AEE14_DesertDuel == 7) {
        sprintf(num, "%d", D_80108C34_2AEDD4_DesertDuel);
        sprintf(name, "%c%c", 0x18, gPlayers[D_80108C30_2AEDD0_DesertDuel].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    func_8008DACC_8E6CC(1, size, D_80108C68_2AEE08_DesertDuel);
    win = func_80104844_2AA9E4_DesertDuel((s16)D_80108C6C_2AEE0C_DesertDuel, (s16)D_80108C70_2AEE10_DesertDuel, size[0], size[1], 0, 0, 200);
    if (D_80108C74_2AEE14_DesertDuel == 5) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_80108C74_2AEE14_DesertDuel == 7) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80108C68_2AEE08_DesertDuel, -1, -1);
    func_80057A78_58678(win, D_80108C18_2AEDB8_DesertDuel, D_80108C1C_2AEDBC_DesertDuel);
    while (TRUE) {
        switch (D_80108C74_2AEE14_DesertDuel) {
            case 0:
                if (D_80108C50_2AEDF0_DesertDuel == 1) {
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 1:
                if (func_80107940_2ADAE0_DesertDuel() & 0x1000) {
                    D_80108C50_2AEDF0_DesertDuel = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 2:
                if (func_80107940_2ADAE0_DesertDuel() & 0x8000) {
                    D_80108C50_2AEDF0_DesertDuel = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 3:
                if (func_80107940_2ADAE0_DesertDuel() & 0x8000) {
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 4:
            case 5:
            case 7:
                func_8008CCA8_8D8A8(win);
                D_80108C50_2AEDF0_DesertDuel = 1;
                omDelPrcObj(NULL);
                break;
            case 6:
                func_8008CCA8_8D8A8(win);
                return;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105AAC_2ABC4C_DesertDuel);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105DB8_2ABF58_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106040_2AC1E0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106328_2AC4C8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106600_2AC7A0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106988_2ACB28_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106C94_2ACE34_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107018_2AD1B8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107128_2AD2C8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801071C8_2AD368_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107314_2AD4B4_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107350_2AD4F0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801073A8_2AD548_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801073FC_2AD59C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107940_2ADAE0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107A00_2ADBA0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107BF8_2ADD98_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107EE4_2AE084_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80108580_2AE720_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80108720_2AE8C0_DesertDuel);
