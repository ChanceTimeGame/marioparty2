#include "ovl_55.h"

void func_80102800_3616F0_name_55(void) {
    omObjData* obj;

    omInitObjMan(40, 12);
    func_80079128_79D28();
    D_8010C570_36B460_name_55 = 0;
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    func_80046238_46E38();
    func_80079464_7A064();
    func_80088640_89240();
    omAddPrcObj(func_80102968_361858_name_55, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102AB4_3619A4_name_55);
    obj = omAddObj(900, 0, 0, -1, func_801029F4_3618E4_name_55);
    D_8010C568_36B458_name_55 = obj;
    obj->work[0] = 0;
    D_8010C58A_36B47A_name_55 = GwSystem.current_board_index;
}

void func_80102968_361858_name_55(void) {
    func_80102B58_361A48_name_55();
    if (D_8010C58A_36B47A_name_55 != 6) {
        func_80103D08_362BF8_name_55();
    }
    func_80103D94_362C84_name_55();
    func_80104B1C_363A0C_name_55();
    func_80105074_363F64_name_55();
    func_800794A8_7A0A8(40);
    InitFadeOut(0, 20);
    HuPrcSleep(20);
    func_80102AE0_3619D0_name_55();
    omOvlKill();
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_801029F4_3618E4_name_55(omObjData* obj) {
    s32 i;

    if (_CheckFlag(D_8010B764_36A654_name_55[D_8010C58A_36B47A_name_55]) && D_8010B762_36A652_name_55 != 0) {
        for (i = 0; i < 4; i++) {
            if (!(gPlayers[i].flags & 1) && (ContBtnTrg[gPlayers[i].port] & 0x1000)) {
                obj->work[0] = 1;
            }
        }
    }
}

void func_80102AB4_3619A4_name_55(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        func_80102AE0_3619D0_name_55();
    }
}

void func_80102AE0_3619D0_name_55(void) {
    MBDBackKill();
    func_80050AE0_516E0();
    func_80047B78_48778();
    if (D_8010C58A_36B47A_name_55 == 5) {
        func_8010B3B4_36A2A4_name_55();
    }
    func_80059400_5A000();
    func_8008CE5C_8DA5C();
    if (D_8010B750_36A640_name_55 != 0) {
        func_8005FF9C_60B9C();
    }
    omOvlReturnEx(1);
}

void func_80102B58_361A48_name_55(void) {
    Process* procs[5];
    Process* cam;
    Process* cur;
    s16* flag;
    s32 i;

    cam = omAddPrcObj(func_801053B0_3642A0_name_55, 0x1001, 0x2000, 0);
    D_8010B780_36A670_name_55[D_8010C58A_36B47A_name_55]();
    if (D_8010C58A_36B47A_name_55 == 6) {
        return;
    }
    D_8010B7B8_36A6A8_name_55[D_8010C58A_36B47A_name_55]();
    cur = HuPrcCurrentGet();
    for (i = 0; i < 5; i++) {
        D_8010C538_36B428_name_55[i] = 0;
    }
    if (D_8010C58A_36B47A_name_55 != 5) {
        procs[4] = func_80076F14_77B14(func_80102F34_361E24_name_55, 0x5001, 0x2000, 0, cur);
        for (i = 0; i < 4; i++) {
            procs[i] = func_80076F14_77B14(func_8010308C_361F7C_name_55, 0x5001, 0x2000, 0, cur);
            procs[i]->user_data = (void*)i;
        }
    } else {
        procs[4] = func_80076F14_77B14(func_801036B4_3625A4_name_55, 0x5001, 0x2000, 0, cur);
        for (i = 0; i < 4; i++) {
            procs[i] = func_80076F14_77B14(func_8010390C_3627FC_name_55, 0x5001, 0x2000, 0, cur);
            procs[i]->user_data = (void*)i;
        }
    }
    while (D_8010B8CC_36A7BC_name_55 < 5) {
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            break;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 1) {
        for (i = 0; i < 5; i++) {
            if (D_8010C538_36B428_name_55[i] == 0) {
                omDelPrcObj(procs[i]);
            }
        }
    } else {
        func_8008F624_90224(255, 255, 255);
        InitFadeOut(0, 20);
        HuPrcSleep(20);
        func_800794A8_7A0A8(20);
    }
    if (D_8010C568_36B458_name_55->work[0] == 1) {
        for (i = 0; i < 4; i++) {
            if (D_8010B758_36A648_name_55[i] != 1) {
                if (D_8010C58A_36B47A_name_55 != 5) {
                    MBModelKill(PLAYER_MODEL(i));
                    D_8010B79C_36A68C_name_55[D_8010C58A_36B47A_name_55](i);
                }
                MBModelDispOff(PLAYER_MODEL(i));
                D_8010B758_36A648_name_55[i] = 1;
            }
        }
        flag = &D_8010B760_36A650_name_55;
        if (*flag == 0) {
            MBModelKill(D_8010C564_36B454_name_55);
            *flag = 1;
        }
    }
    func_8001AC44_1B844(D_8010C588_36B478_name_55);
    func_8001AC44_1B844(D_8010C560_36B450_name_55);
    omDelPrcObj(cam);
    for (i = 0; i < 4; i++) {
        MBModelDispOff(PLAYER_MODEL(i));
    }
    MBModelDispOff(D_8010C56C_36B45C_name_55);
}

/* The host's walk-in (all boards but 5). */
void func_80102F34_361E24_name_55(void) {
    MBMotionSet(D_8010C564_36B454_name_55, 0, 2);
    D_8010C564_36B454_name_55->pos.x = D_8010B7D0_36A6C0_name_55[0][0].x;
    D_8010C564_36B454_name_55->pos.y = D_8010B7D0_36A6C0_name_55[0][0].y;
    D_8010C564_36B454_name_55->pos.z = D_8010B7D0_36A6C0_name_55[0][0].z;
    MBModelDispOn(D_8010C564_36B454_name_55);
    while (func_8005A5E8_5B1E8(D_8010C564_36B454_name_55, &D_8010B7D0_36A6C0_name_55[0][1], 35.0f) != 1) {
        HuPrcVSleep();
    }
    MBModelKill(D_8010C564_36B454_name_55);
    MBMotionSet(D_8010C56C_36B45C_name_55, 0, 2);
    D_8010C56C_36B45C_name_55->pos.x = D_8010B848_36A738_name_55[0][0].x;
    D_8010C56C_36B45C_name_55->pos.y = D_8010B848_36A738_name_55[0][0].y;
    D_8010C56C_36B45C_name_55->pos.z = D_8010B848_36A738_name_55[0][0].z;
    MBModelDispOn(D_8010C56C_36B45C_name_55);
    D_8010B760_36A650_name_55 = 1;
    HuPrcSleep(36);
    while (func_8005A5E8_5B1E8(D_8010C56C_36B45C_name_55, &D_8010B848_36A738_name_55[0][1], 20.0f) == 0) {
        HuPrcVSleep();
    }
    D_8010B8CC_36A7BC_name_55++;
    D_8010C538_36B428_name_55[4] = 1;
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* A player's walk-in (all boards but 5): once all four have arrived each one's model is swapped
   for the board's own (D_8010B79C), then they walk on, face the camera and bow. */
void func_8010308C_361F7C_name_55(void) {
    Vec pos;
    s32 i;
    u32 j;

    i = (s32)HuPrcCurrentGet()->user_data;
    MBMotionSet(PLAYER_MODEL(i), 4, 2);
    PLAYER_MODEL(i)->pos.x = D_8010B7D0_36A6C0_name_55[i + 1][0].x;
    PLAYER_MODEL(i)->pos.y = D_8010B7D0_36A6C0_name_55[i + 1][0].y;
    PLAYER_MODEL(i)->pos.z = D_8010B7D0_36A6C0_name_55[i + 1][0].z;
    MBModelDispOn(PLAYER_MODEL(i));
    while (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010B7D0_36A6C0_name_55[i + 1][1], 35.0f) != 1) {
        HuPrcVSleep();
    }
    PLAYER_MODEL(i)->pos.x = D_8010B848_36A738_name_55[i + 1][0].x;
    PLAYER_MODEL(i)->pos.y = D_8010B848_36A738_name_55[i + 1][0].y;
    PLAYER_MODEL(i)->pos.z = D_8010B848_36A738_name_55[i + 1][0].z;
    D_8010B754_36A644_name_55++;
    if (i == 3) {
        PlaySound(0x31E);
    }
    for (j = 0; j < 36; j++) {
        if (D_8010B754_36A644_name_55 >= 4 && D_8010B758_36A648_name_55[i] == 0) {
            pos.x = PLAYER_MODEL(i)->pos.x;
            pos.y = PLAYER_MODEL(i)->pos.y;
            pos.z = PLAYER_MODEL(i)->pos.z;
            MBModelKill(PLAYER_MODEL(i));
            D_8010B79C_36A68C_name_55[D_8010C58A_36B47A_name_55](i);
            MBMotionSet(PLAYER_MODEL(i), 4, 2);
            PLAYER_MODEL(i)->pos.x = pos.x;
            PLAYER_MODEL(i)->pos.y = pos.y;
            PLAYER_MODEL(i)->pos.z = pos.z;
            D_8010B758_36A648_name_55[i] = 1;
        }
        HuPrcVSleep();
    }
    j = 0;
    while (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010B848_36A738_name_55[i + 1][1], 20.0f) == 0) {
        j++;
        if (j == 15) {
            if (i == 0) {
                PlaySound(0x4B4);
            }
        }
        if (D_8010B754_36A644_name_55 == 4 && D_8010B758_36A648_name_55[i] == 0) {
            pos.x = PLAYER_MODEL(i)->pos.x;
            pos.y = PLAYER_MODEL(i)->pos.y;
            pos.z = PLAYER_MODEL(i)->pos.z;
            MBModelKill(PLAYER_MODEL(i));
            D_8010B79C_36A68C_name_55[D_8010C58A_36B47A_name_55](i);
            MBMotionSet(PLAYER_MODEL(i), 4, 2);
            PLAYER_MODEL(i)->pos.x = pos.x;
            PLAYER_MODEL(i)->pos.y = pos.y;
            PLAYER_MODEL(i)->pos.z = pos.z;
            D_8010B758_36A648_name_55[i] = 1;
        }
        HuPrcVSleep();
    }
    pos.x = PLAYER_MODEL(i)->pos.x;
    pos.y = PLAYER_MODEL(i)->pos.y;
    pos.z = PLAYER_MODEL(i)->pos.z - 100.0f;
    while (func_8005A7E8_5B3E8(PLAYER_MODEL(i), &pos, 20.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(PLAYER_MODEL(i), 2, 0, 5, 2);
    HuPrcSleep(20);
    MBMotionSet(PLAYER_MODEL(i), 4, 2);
    while (func_8005A7E8_5B3E8(PLAYER_MODEL(i), &D_8010B8C0_36A7B0_name_55, 20.0f) == 0) {
        HuPrcVSleep();
    }
    while (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010B8C0_36A7B0_name_55, 20.0f) == 0) {
        HuPrcVSleep();
    }
    D_8010B8CC_36A7BC_name_55++;
    D_8010C538_36B428_name_55[i] = 1;
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* Board 5's walk-in: the host walks across and hides, its stand-in walks on and turns round. */
void func_801036B4_3625A4_name_55(void) {
    Vec pos;

    MBMotionSet(D_8010C56C_36B45C_name_55, 0, 2);
    D_8010C56C_36B45C_name_55->pos.x = D_8010B8D0_36A7C0_name_55[0][0].x;
    D_8010C56C_36B45C_name_55->pos.y = D_8010B8D0_36A7C0_name_55[0][0].y;
    D_8010C56C_36B45C_name_55->pos.z = D_8010B8D0_36A7C0_name_55[0][0].z;
    MBModelDispOn(D_8010C56C_36B45C_name_55);
    while (func_8005A5E8_5B1E8(D_8010C56C_36B45C_name_55, &D_8010B8D0_36A7C0_name_55[0][1], 40.0f) != 1) {
        HuPrcVSleep();
    }
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    MBMotionSet(D_8010C564_36B454_name_55, 0, 2);
    D_8010C564_36B454_name_55->pos.x = D_8010B948_36A838_name_55[0][0].x;
    D_8010C564_36B454_name_55->pos.y = D_8010B948_36A838_name_55[0][0].y;
    D_8010C564_36B454_name_55->pos.z = D_8010B948_36A838_name_55[0][0].z;
    MBModelDispOn(D_8010C564_36B454_name_55);
    HuPrcSleep(36);
    while (func_8005A5E8_5B1E8(D_8010C564_36B454_name_55, &D_8010B948_36A838_name_55[0][1], 25.0f) == 0) {
        HuPrcVSleep();
    }
    pos.x = D_8010C564_36B454_name_55->pos.x;
    pos.y = D_8010C564_36B454_name_55->pos.y;
    pos.z = D_8010C564_36B454_name_55->pos.z - 100.0f;
    while (func_8005A7E8_5B3E8(D_8010C564_36B454_name_55, &pos, 20.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_8010C564_36B454_name_55, -1, 0, 5, 2);
    HuPrcSleep(20);
    MBMotionSet(D_8010C564_36B454_name_55, 0, 2);
    while (func_8005A7E8_5B3E8(D_8010C564_36B454_name_55, &D_8010B9C0_36A8B0_name_55, 20.0f) == 0) {
        HuPrcVSleep();
    }
    while (func_8005A5E8_5B1E8(D_8010C564_36B454_name_55, &D_8010B9C0_36A8B0_name_55, 25.0f) == 0) {
        HuPrcVSleep();
    }
    MBModelKill(D_8010C564_36B454_name_55);
    D_8010B760_36A650_name_55 = 1;
    D_8010B8CC_36A7BC_name_55++;
    D_8010C538_36B428_name_55[4] = 1;
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* Board 5's player walk-in: 8010308C's shape with the model swap's calls gone (the position is
   still saved and written back), and no bow. Sets D_8010C54C, not the player's done flag. */
void func_8010390C_3627FC_name_55(void) {
    Vec pos;
    s32 i;
    u32 j;

    i = (s32)HuPrcCurrentGet()->user_data;
    MBMotionSet(PLAYER_MODEL(i), 4, 2);
    PLAYER_MODEL(i)->pos.x = D_8010B8D0_36A7C0_name_55[i + 1][0].x;
    PLAYER_MODEL(i)->pos.y = D_8010B8D0_36A7C0_name_55[i + 1][0].y;
    PLAYER_MODEL(i)->pos.z = D_8010B8D0_36A7C0_name_55[i + 1][0].z;
    MBModelDispOn(PLAYER_MODEL(i));
    while (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010B8D0_36A7C0_name_55[i + 1][1], 40.0f) != 1) {
        HuPrcVSleep();
    }
    PLAYER_MODEL(i)->pos.x = D_8010B948_36A838_name_55[i + 1][0].x;
    PLAYER_MODEL(i)->pos.y = D_8010B948_36A838_name_55[i + 1][0].y;
    PLAYER_MODEL(i)->pos.z = D_8010B948_36A838_name_55[i + 1][0].z;
    D_8010B754_36A644_name_55++;
    if (i == 3) {
        PlaySound(0x31E);
    }
    for (j = 0; j < 36; j++) {
        if (D_8010B754_36A644_name_55 >= 4 && D_8010B758_36A648_name_55[i] == 0) {
            pos.x = PLAYER_MODEL(i)->pos.x;
            pos.y = PLAYER_MODEL(i)->pos.y;
            pos.z = PLAYER_MODEL(i)->pos.z;
            PLAYER_MODEL(i)->pos.x = pos.x;
            PLAYER_MODEL(i)->pos.y = pos.y;
            PLAYER_MODEL(i)->pos.z = pos.z;
            D_8010B758_36A648_name_55[i] = 1;
        }
        HuPrcVSleep();
    }
    j = 0;
    while (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010B948_36A838_name_55[i + 1][1], 25.0f) == 0) {
        j++;
        if (j == 1) {
            if (i == 0) {
                PlaySound(0x4B4);
            }
        }
        if (D_8010B754_36A644_name_55 == 4 && D_8010B758_36A648_name_55[i] == 0) {
            pos.x = PLAYER_MODEL(i)->pos.x;
            pos.y = PLAYER_MODEL(i)->pos.y;
            pos.z = PLAYER_MODEL(i)->pos.z;
            PLAYER_MODEL(i)->pos.x = pos.x;
            PLAYER_MODEL(i)->pos.y = pos.y;
            PLAYER_MODEL(i)->pos.z = pos.z;
            D_8010B758_36A648_name_55[i] = 1;
        }
        HuPrcVSleep();
    }
    D_8010B8CC_36A7BC_name_55++;
    D_8010C54C_36B43C_name_55 = 1;
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_80103D08_362BF8_name_55(void) {
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        PlayMusic(0x3A);
        D_8010B9CC_36A8BC_name_55[D_8010C58A_36B47A_name_55]();
    }
    func_8008F624_90224(0, 0, 0);
    func_800794A8_7A0A8(60);
    func_80079614_7A214(60);
    InitFadeOut(2, 20);
    HuPrcSleep(20);
    MBDBackKill();
}

/* The players' entrance: model 0xE (a pipe?) rises at the board's drop point, the host and the four players
   jump out to their places, it sinks, the players fall onto the board; the host's
   greeting, the players line up (D_8010BB40), the board's explanation (D_8010BA04, D_8010BA58,
   D_8010BA20), then they walk to their starting places (D_8010BB70) and face away. */
/* NON_MATCHING: the host's fall loop (jumpY -= speed until <= 0) only: GCC hoists its 1.2f and
   0.0f into $f22/$f20, retail rematerialises them each pass (the loop's shape matches). */
#ifdef NON_MATCHING
void func_80103D94_362C84_name_55(void) {
    s32 done[4];
    s32 delay[4];
    f32 speed[4];
    Vec dir;
    Vec target;
    MBModel* pipe;
    f32 dist;
    s32 win;
    s32 y;
    s32 i;
    s32 j;
    s32 n;

    func_80050E00_51A00(D_8010B9E8_36A8D8_name_55[D_8010C58A_36B47A_name_55]);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 4; i++) {
        PLAYER_MODEL(i)->pos.x = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].x;
        PLAYER_MODEL(i)->pos.y = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].y;
        PLAYER_MODEL(i)->pos.z = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].z;
        func_80056658_57258(&PLAYER_MODEL(i)->pos, &OVL55_CAMERA->pos, &PLAYER_MODEL(i)->rot);
    }
    D_8010C56C_36B45C_name_55->pos.x = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].x;
    D_8010C56C_36B45C_name_55->pos.y = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].y;
    D_8010C56C_36B45C_name_55->pos.z = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].z;
    func_80056658_57258(&D_8010C56C_36B45C_name_55->pos, &OVL55_CAMERA->pos, &D_8010C56C_36B45C_name_55->rot);
    InitFadeIn(2, 16);
    HuPrcSleep(16);
    pipe = func_80043510_44110(0xE, NULL);
    pipe->pos.x = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].x;
    pipe->pos.y = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].y;
    pipe->pos.z = D_8010BA74_36A964_name_55[D_8010C58A_36B47A_name_55].z;
    pipe->scale.y = 0.0f;
    PlaySound(0x326);
    for (i = 0; i < 6; i++) {
        pipe->scale.y += 1.0f / 6.0f;
        HuPrcVSleep();
    }
    PlaySound(0x328);
    MBModelDispOn(D_8010C56C_36B45C_name_55);
    dist = HuVecDistance(&D_8010C56C_36B45C_name_55->pos, &D_8010BAC8_36A9B8_name_55) / 6.0f;
    func_80056658_57258(&D_8010C56C_36B45C_name_55->pos, &D_8010BAC8_36A9B8_name_55, &dir);
    for (i = 0; i < 6; i++) {
        D_8010C56C_36B45C_name_55->pos.x += dist * dir.x;
        D_8010C56C_36B45C_name_55->jumpY += dist * dir.y;
        D_8010C56C_36B45C_name_55->pos.z += dist * dir.z;
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        MBMotionSet(PLAYER_MODEL(i), 0, 0);
        MBModelDispOn(PLAYER_MODEL(i));
        dist = HuVecDistance(&PLAYER_MODEL(i)->pos, &D_8010BAE0_36A9D0_name_55[i]) / 6.0f;
        func_80056658_57258(&PLAYER_MODEL(i)->pos, &D_8010BAE0_36A9D0_name_55[i], &dir);
        PlaySound(0x328);
        for (j = 0; j < 6; j++) {
            PLAYER_MODEL(i)->pos.x += dist * dir.x;
            PLAYER_MODEL(i)->jumpY += dist * dir.y;
            PLAYER_MODEL(i)->pos.z += dist * dir.z;
            HuPrcVSleep();
        }
    }
    PlaySound(0x327);
    for (i = 0; i < 6; i++) {
        pipe->scale.y -= 1.0f / 6.0f;
        HuPrcVSleep();
    }
    MBModelKill(pipe);
    speed[0] = 0.59f;
    speed[1] = 1.21f;
    speed[2] = 0.77f;
    speed[3] = 1.0f;
    for (i = 0; i < 4; i++) {
        PLAYER_MODEL(i)->pos.x = D_8010BB10_36AA00_name_55[i].x;
        PLAYER_MODEL(i)->pos.z = D_8010BB10_36AA00_name_55[i].z;
    }
    j = 0;
    while (TRUE) {
        j++;
        if (j == 20 && D_8010C58A_36B47A_name_55 == 6) {
            PlayMusic(0xE);
        }
        n = 0;
        for (i = 0; i < 4; i++) {
            PLAYER_MODEL(i)->jumpY -= speed[i];
            if (PLAYER_MODEL(i)->jumpY <= 0.0f) {
                PLAYER_MODEL(i)->jumpY = 0.0f;
                if (speed[i] != 0.0f) {
                    MBMotionShiftSet(PLAYER_MODEL(i), 2, 0, 5, 2);
                    omVibrate(i, 5, 0, 5);
                }
                speed[i] = 0.0f;
                n++;
            }
            speed[i] *= 1.1f;
        }
        if (n == 4) {
            break;
        }
        HuPrcVSleep();
    }
    speed[0] = 1.0f;
    D_8010C56C_36B45C_name_55->jumpY -= speed[0];
    if (D_8010C56C_36B45C_name_55->jumpY <= 0.0f) {
        D_8010C56C_36B45C_name_55->jumpY = 0.0f;
    } else {
        do {
            speed[0] *= 1.2f;
            HuPrcVSleep();
            D_8010C56C_36B45C_name_55->jumpY -= speed[0];
        } while (!(D_8010C56C_36B45C_name_55->jumpY <= 0.0f));
        D_8010C56C_36B45C_name_55->jumpY = 0.0f;
    }
    if (D_8010C58A_36B47A_name_55 != 5) {
        MBMotionSet(D_8010C56C_36B45C_name_55, 1, 2);
    } else {
        MBMotionSet(D_8010C56C_36B45C_name_55, 1, 0);
        func_80059520_5A120(D_8010C56C_36B45C_name_55, -1, 2);
    }
    if (D_8010C58A_36B47A_name_55 != 6) {
        PlayMusic(0xE);
    }
    func_8008DACC_8E6CC(1, D_8010C530_36B420_name_55, D_8010BA3C_36A92C_name_55[D_8010C58A_36B47A_name_55]);
    win = func_8005AAC0_5B6C0((320 - D_8010C530_36B420_name_55[0]) / 2, 50, D_8010C530_36B420_name_55[0],
                              D_8010C530_36B420_name_55[1]);
    func_800890CC_89CCC(win, D_8010BA3C_36A92C_name_55[D_8010C58A_36B47A_name_55], -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    PlaySound(D_8010C58A_36B47A_name_55 != 5 ? 0x11F : 0x364);
    for (i = 0; i < 4; i++) {
        done[i] = 0;
        MBMotionSet(PLAYER_MODEL(i), 3, 2);
        delay[i] = 0;
    }
    while (TRUE) {
        n = 0;
        for (i = 0; i < 4; i++) {
            if (func_8005A7E8_5B3E8(PLAYER_MODEL(i), &D_8010BB40_36AA30_name_55[i], 15.0f) == 1) {
                if (delay[i] == 0) {
                    if (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010BB40_36AA30_name_55[i], 10.0f) == 1) {
                        if (done[i] == 0) {
                            done[i] = 1;
                            MBMotionShiftSet(PLAYER_MODEL(i), 2, 0, 5, 2);
                        }
                        n++;
                    }
                } else {
                    delay[i]--;
                }
            }
        }
        if (n == 4) {
            break;
        }
        HuPrcVSleep();
    }
    func_80057DA4_589A4(win);
    func_8005762C_5822C(win);
    if (D_8010C58A_36B47A_name_55 != 3) {
        MBMotionShiftSet(D_8010C56C_36B45C_name_55, 2, 0, 5, 2);
        while (func_8005A5E8_5B1E8(D_8010C56C_36B45C_name_55, &D_8010BAD4_36A9C4_name_55, 30.0f) == 0) {
            HuPrcVSleep();
        }
        while (func_8005A7E8_5B3E8(D_8010C56C_36B45C_name_55, &OVL55_CAMERA->pos, 12.0f) == 0) {
            HuPrcVSleep();
        }
        if (D_8010C58A_36B47A_name_55 != 5) {
            MBMotionShiftSet(D_8010C56C_36B45C_name_55, 1, 0, 5, 2);
        } else {
            MBMotionShiftSet(D_8010C56C_36B45C_name_55, -1, 0, 5, 2);
        }
    }
    if (D_8010C58A_36B47A_name_55 != 6) {
        y = 50;
        D_8010BA04_36A8F4_name_55[D_8010C58A_36B47A_name_55]();
        switch (D_8010C58A_36B47A_name_55) {
            case 2:
            case 3:
            case 4:
                y = 125;
                break;
        }
        if (D_8010C58A_36B47A_name_55 == 5) {
            MBMotionSet(D_8010C56C_36B45C_name_55, 1, 0);
            func_801055A4_364494_name_55(D_8010C56C_36B45C_name_55, -1, 2, 2);
        }
        func_8008DACC_8E6CC(1, D_8010C530_36B420_name_55, D_8010BA58_36A948_name_55[D_8010C58A_36B47A_name_55]);
        win = func_8005AAC0_5B6C0((320 - D_8010C530_36B420_name_55[0]) / 2, y, D_8010C530_36B420_name_55[0],
                                  D_8010C530_36B420_name_55[1]);
        func_800890CC_89CCC(win, D_8010BA58_36A948_name_55[D_8010C58A_36B47A_name_55], -1, -1);
        func_80089A48_8A648(win, 0);
        ShowTextWindow(win);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        func_80057DA4_589A4(win);
        func_8005762C_5822C(win);
        if (D_8010C58A_36B47A_name_55 != 5 && D_8010C58A_36B47A_name_55 != 6) {
            D_8010BA20_36A910_name_55[D_8010C58A_36B47A_name_55]();
        }
    }
    for (i = 0; i < 4; i++) {
        done[i] = 0;
        MBMotionSet(PLAYER_MODEL(i), 4, 2);
    }
    while (TRUE) {
        n = 0;
        for (i = 0; i < 4; i++) {
            if (func_8005A5E8_5B1E8(PLAYER_MODEL(i), &D_8010BB70_36AA60_name_55[i], 15.0f) == 1) {
                target.x = PLAYER_MODEL(i)->pos.x;
                target.y = PLAYER_MODEL(i)->pos.y;
                target.z = PLAYER_MODEL(i)->pos.z + 500.0f;
                if (func_8005A7E8_5B3E8(PLAYER_MODEL(i), &target, 15.0f) == 1) {
                    if (done[i] == 0) {
                        done[i] = 1;
                        MBMotionShiftSet(PLAYER_MODEL(i), 2, 0, 5, 2);
                    }
                    n++;
                }
            }
        }
        if (n == 4) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80103D94_362C84_name_55);
#endif

/* The turn order (MP1 func_800F8334): each player hits a dice block (CPUs after a random 5-34
   frames), the players are ranked by their numbers, GW_PLAYER.unk_1C[0] gets each one's place
   and the records are sorted into it (80105284); then each player is introduced in turn. */
void func_80104B1C_363A0C_name_55(void) {
    s32 state[4];
    s32 count[4];
    s32 timers[4];
    s32 order[4];
    s32 i;
    s32 j;
    s32 tmp;
    s32 win;

    func_800461C8_46DC8();
    for (i = 0; i < 4; i++) {
        func_80046F98_47B98(i);
        func_80046308_46F08(i);
    }
    func_80047D2C_4892C();
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        state[i] = 1;
        count[i] = 0;
        timers[i] = (u8)(rand8() % 30) + 5;
    }
    while (TRUE) {
        for (i = 0; i < 4; i++) {
            timers[i]--;
            if (state[i] == 1) {
                if (gPlayers[i].flags & 1) {
                    if (timers[i] <= 0) {
                        goto press;
                    }
                } else if (ContBtnTrg[gPlayers[i].port] & 0x8000) {
                press:
                    state[i] = 2;
                    MBMotionSet(PLAYER_MODEL(i), 5, 0);
                    func_80059520_5A120(PLAYER_MODEL(i), 2, 2);
                }
            } else if (state[i] == 2) {
                count[i]++;
                if (count[i] == 5) {
                    func_80047BB8_487B8(i);
                    state[i] = 0;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (state[i] != 0) {
                break;
            }
        }
        if (i == 4) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        state[i] = func_80047DE8_489E8(i);
        order[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (state[i] < state[j]) {
                tmp = state[i];
                state[i] = state[j];
                state[j] = tmp;
                tmp = order[i];
                order[i] = order[j];
                order[j] = tmp;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        gPlayers[order[i]].unk_1C[0] = i;
        func_80046CD8_478D8(i);
    }
    func_80105284_364174_name_55();
    func_8005FE10_60A10();
    D_8010B750_36A640_name_55 = 1;
    for (i = 0; i < 4; i++) {
        HidePlayerHUDVisibility(i, 1);
    }
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        func_8008D974_8E574(D_800CC5F8[gPlayers[i].character], i);
        if (D_8010C58A_36B47A_name_55 != 5) {
            func_8008DACC_8E6CC(1, D_8010C530_36B420_name_55, i + 0x4DA);
        } else {
            func_8008DACC_8E6CC(1, D_8010C530_36B420_name_55, i + 0x238);
        }
        win = func_8005AAC0_5B6C0(30, 70, D_8010C530_36B420_name_55[0], D_8010C530_36B420_name_55[1]);
        if (D_8010C58A_36B47A_name_55 != 5) {
            func_800890CC_89CCC(win, i + 0x4DA, -1, -1);
        } else {
            func_800890CC_89CCC(win, i + 0x238, -1, -1);
        }
        func_80089308_89F08(win, D_800CC5F8[gPlayers[i].character], i);
        ShowTextWindow(win);
        func_80057DA4_589A4(win);
        func_8005762C_5822C(win);
        func_800595E8_5A1E8(PLAYER_MODEL(i), 6, 0);
        func_80059520_5A120(PLAYER_MODEL(i), 2, 2);
        func_80079718_7A318(0x103, gPlayers[i].character);
        func_80046D2C_4792C(order[i]);
        func_80060210_60E10(i + 10);
        while (func_800609D8_615D8() != 0) {
            HuPrcVSleep();
        }
        omVibrate(i, 2, 2, 20);
        HuPrcSleep(20);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105074_363F64_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105284_364174_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105328_364218_name_55);

__asm__(".section .rodata");
const u32 D_8010C4F0_36B3E0_name_55[3] = { 0x3F800000, 0x00000000, 0x00000000 };

__asm__(".section .rodata");
const u32 D_8010C4FC_36B3EC_name_55[3] = { 0x00000000, 0x42C80000, 0x44FA0000 };

__asm__(".section .rodata");
const u32 D_8010C508_36B3F8_name_55[6] = { 0x00000000, 0x42C80000, 0xC4610000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801053B0_3642A0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801054B4_3643A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801055A4_364494_name_55);
