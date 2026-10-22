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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801036B4_3625A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_8010390C_3627FC_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80103D08_362BF8_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80103D94_362C84_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80104B1C_363A0C_name_55);

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
