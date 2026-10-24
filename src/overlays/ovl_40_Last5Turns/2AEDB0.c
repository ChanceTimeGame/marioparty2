#include "ovl_40.h"

/* .data (0x2B0EF0-0x2B1010): motions, status-window layouts, places, per-character motion lists */
s32 D_80104940_2B0EF0_Last5Turns = 0x8003A;
s32 D_80104944_2B0EF4_Last5Turns = 0x800BC;
s32 D_80104948_2B0EF8_Last5Turns[4] = {
    0x800A4, 0x800A4, 0x800AD, 0x8007C,
};
L5StatusLayout D_80104958_2B0F08_Last5Turns[2] = {
    { { { -1, -1, -192, -1 }, { -1, -1, -192, -1 }, { -1, -1, -192, -1 }, { -1, -1, -1, 16 } }, 0, 15 },
    { { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, -192, -1 } }, 0, 15 },
};
s32 D_801049A0_2B0F50_Last5Turns = 0;
s32 D_801049A4_2B0F54_Last5Turns = 0;
s16 D_801049A8_2B0F58_Last5Turns[4] = {
    1, 0, 2, 0,
};
Vec D_801049B0_2B0F60_Last5Turns = { 0.0f, 0.0f, 2250.0f };
Vec D_801049BC_2B0F6C_Last5Turns = { 1000.0f, 0.0f, 2000.0f };
Vec D_801049C8_2B0F78_Last5Turns = { 150.0f, 0.0f, 2000.0f };
Vec D_801049D4_2B0F84_Last5Turns = { 150.0f, 0.0f, 1600.0f };
u32 D_801049E0_2B0F90_Last5Turns[5] = {
    0x00000004, 0x00080096, 0x0008008D, 0x00000000, 0x0008009C,
};
u32 D_801049F4_2B0FA4_Last5Turns[5] = {
    0x00000004, 0x0008008C, 0x0008008D, 0x00000000, 0x0008009C,
};
u32 D_80104A08_2B0FB8_Last5Turns[5] = {
    0x00000004, 0x000800BF, 0x000800C0, 0x00000000, 0x00000000,
};
u32 D_80104A1C_2B0FCC_Last5Turns[5] = {
    0x00000004, 0x0008003D, 0x00080043, 0x0008003F, 0x00000000,
};
u32 D_80104A30_2B0FE0_Last5Turns[5] = {
    0x00000003, 0x000800B0, 0x00000000, 0x000800B2, 0x00000000,
};
u32* D_80104A44_2B0FF4_Last5Turns[4] = {
    D_801049E0_2B0F90_Last5Turns, D_801049F4_2B0FA4_Last5Turns,
    D_80104A08_2B0FB8_Last5Turns, D_80104A1C_2B0FCC_Last5Turns,
};

/* Waits until the step a process or object reports in D_80104B18 is done. */
#define WAIT_STEP()                              \
    while (TRUE) {                               \
        if (D_80104B18_2B10C8_Last5Turns != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

/* Shows the message set up in D_80104B24..D_80104B34 through func_80103D60 and waits for it. */
#define SHOW_MESSAGE(variant)                                 \
    D_80104B2C_2B10DC_Last5Turns = (variant);                 \
    omAddPrcObj(func_80103D60_2B0310_Last5Turns, 0x12, 0, 0); \
    D_80104B18_2B10C8_Last5Turns = 0;                         \
    WAIT_STEP();

/* Drops in the status window of rank D_80104B40 and waits for it. */
#define DROP_STATUS()                                           \
    omAddPrcObj(func_80103B98_2B0148_Last5Turns, 0x5000, 0, 0); \
    D_80104B18_2B10C8_Last5Turns = 0;                           \
    WAIT_STEP();

void func_80102800_2AEDB0_Last5Turns(void) {
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
    func_8010294C_2AEEFC_Last5Turns();
    func_80088640_89240();
    func_8005FE10_60A10();
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    omAddPrcObj(func_80102D20_2AF2D0_Last5Turns, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102C40_2AF1F0_Last5Turns);
}

/* Picks the event (D_80104B44) and the player it favours (D_80104B20). Board 5: event 3, a random
   player among those in last place. Otherwise event 0..2 at random (2 only when someone plays
   character 0, who is then the player); events 0 and 1 pick a rank at random, weighted towards
   the lower ranks. */
/* NON_MATCHING: registers (masked 1): retail sets an unused s1 = 3 before the board-5 rank loop and keeps
   the rank in v1 */
#ifdef NON_MATCHING
void func_8010294C_2AEEFC_Last5Turns(void) {
    s32 last[4];
    s32 i;
    s32 n;
    s32 max;
    s32 rank;
    s32 r;

    D_80104B34_2B10E4_Last5Turns = 0;
    D_80104B58_2B1108_Last5Turns = 4;
    for (i = 0; i < 4; i++) {
        D_80104B48_2B10F8_Last5Turns[i] = 1;
    }
    n = 0; /* someone plays character 0 */
    func_8010431C_2B08CC_Last5Turns();
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].character == 0) {
            n = 1;
            break;
        }
    }
    if (GwSystem.current_board_index == 5) {
        D_80104B44_2B10F4_Last5Turns = 3;
    } else {
        r = (u8)(rand8() % 10);
        if (n) {
            if (r < 6) {
                D_80104B44_2B10F4_Last5Turns = 1;
            } else if (r < 8) {
                D_80104B44_2B10F4_Last5Turns = 0;
            } else {
                D_80104B44_2B10F4_Last5Turns = 2;
            }
        } else if (r < 8) {
            D_80104B44_2B10F4_Last5Turns = 1;
        } else {
            D_80104B44_2B10F4_Last5Turns = 0;
        }
    }
    max = 0;
    if (GwSystem.current_board_index == 5) {
        for (i = 0; i < 4; i++) {
            rank = func_80059FD0_5ABD0(i);
            if (max < rank) {
                max = rank;
            }
        }
        for (n = 0, i = 0; i < 4; i++) {
            if (func_80059FD0_5ABD0(i) == max) {
                last[n++] = i;
            }
        }
        D_80104B80_2B1130_Last5Turns = n;
        i = rand8() % n;
        D_80104B20_2B10D0_Last5Turns = last[i];
    } else {
        r = (u8)(rand8() % 100);
        if (D_80104B44_2B10F4_Last5Turns == 1) {
            if (r < 10) {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(1);
            } else if (r < 40) {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(2);
            } else {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(3);
            }
        } else if (D_80104B44_2B10F4_Last5Turns == 0) {
            if (r < 15) {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(0);
            } else if (r < 40) {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(1);
            } else if (r < 70) {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(2);
            } else {
                D_80104B20_2B10D0_Last5Turns = func_80104404_2B09B4_Last5Turns(3);
            }
        } else {
            D_80104B20_2B10D0_Last5Turns = i;
        }
    }
    D_80104B34_2B10E4_Last5Turns = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_40_Last5Turns/2AEDB0", func_8010294C_2AEEFC_Last5Turns);
#endif

void func_80102C40_2AF1F0_Last5Turns(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

/* Unused here (overlay 3F's camera setup). */
void func_80102C94_2AF244_Last5Turns(void) {
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

/* The scene: the host announces the last five turns, the status windows drop in by rank, the
   event's model walks in, the event and its player are announced and the player's window is
   moved to the front; then the scene fades out. */
void func_80102D20_2AF2D0_Last5Turns(void) {
    s32 models[4] = { 0x800A3, 0x8008B, 0x800BE, 0x80049 };
    s32 motions[4] = { 6, 7, 0, 9 };
    f32 scales[4] = { 1.0f, 1.0f, 5.0f, 3.0f };
    Vec pos;
    s32 bgs[6] = { 4, 12, 18, 26, 32, 39 };
    s32 hosts[6] = { 14, 22, 40, 28, 35, 14 };
    s16 unused[6] = { 8, 9, 11, 10, 12, 13 }; /* copied, never read */
    ModelPathWork* path;
    s32 motion;
    s16 count;

    func_80050E00_51A00(bgs[GwSystem.current_board_index]);
    func_8005321C_53E1C(80.0f, 8000.0f);
    if (GwSystem.current_board_index == 5) {
        D_80104B10_2B10C0_Last5Turns = MBModelFileCreate(0x800B0, 13, 1.0f, 1.0f, D_80104A30_2B0FE0_Last5Turns);
        func_8005AB50_5B750(D_80104B10_2B10C0_Last5Turns, 2, 10, D_80104944_2B0EF4_Last5Turns);
    } else {
        D_80104B10_2B10C0_Last5Turns = MBModelFileCreate(hosts[GwSystem.current_board_index] | 0x80000, 13, 1.0f, 1.0f, NULL);
        func_8005AB50_5B750(D_80104B10_2B10C0_Last5Turns, 2, 8, D_80104940_2B0EF0_Last5Turns);
    }
    func_80043DAC_449AC(D_80104B10_2B10C0_Last5Turns);
    D_80104B10_2B10C0_Last5Turns->pos.x = D_801049B0_2B0F60_Last5Turns.x;
    D_80104B10_2B10C0_Last5Turns->pos.y = D_801049B0_2B0F60_Last5Turns.y;
    D_80104B10_2B10C0_Last5Turns->pos.z = D_801049B0_2B0F60_Last5Turns.z;
    func_80056658_57258(&D_80104B10_2B10C0_Last5Turns->pos, &D_801049B0_2B0F60_Last5Turns, &D_80104B10_2B10C0_Last5Turns->rot);
    D_80104B10_2B10C0_Last5Turns->jumpY = D_801049B0_2B0F60_Last5Turns.y;
    D_80104B10_2B10C0_Last5Turns->jumpVel = 0.0f;
    D_80104B10_2B10C0_Last5Turns->jumpAccel = 0.0f;
    D_80104B14_2B10C4_Last5Turns = MBModelFileCreate(models[D_80104B44_2B10F4_Last5Turns], 13, 1.0f, scales[D_80104B44_2B10F4_Last5Turns],
                                                     D_80104A44_2B0FF4_Last5Turns[D_80104B44_2B10F4_Last5Turns]);
    motion = D_80104948_2B0EF8_Last5Turns[D_80104B44_2B10F4_Last5Turns];
    count = motions[D_80104B44_2B10F4_Last5Turns];
    if (count != 0) {
        func_8005AB50_5B750(D_80104B14_2B10C4_Last5Turns, 2, count, motion);
    }
    func_80043DAC_449AC(D_80104B14_2B10C4_Last5Turns);
    D_80104B14_2B10C4_Last5Turns->pos.x = D_801049BC_2B0F6C_Last5Turns.x;
    D_80104B14_2B10C4_Last5Turns->pos.y = D_801049BC_2B0F6C_Last5Turns.y;
    D_80104B14_2B10C4_Last5Turns->pos.z = D_801049BC_2B0F6C_Last5Turns.z;
    PlayMusic(0x13);
    InitFadeIn(0, 16);
    HuPrcSleep(31);

    if (GwSystem.current_board_index == 5) {
        PlaySound(0x363);
        D_80104B30_2B10E0_Last5Turns = 0x2AF;
    } else {
        PlaySound(0x11E);
        D_80104B30_2B10E0_Last5Turns = 0x2A1;
    }
    D_80104B24_2B10D4_Last5Turns = 65;
    D_80104B28_2B10D8_Last5Turns = 90;
    D_80104B34_2B10E4_Last5Turns |= 1;
    SHOW_MESSAGE(0);
    D_80104B40_2B10F0_Last5Turns = 0;
    DROP_STATUS();

    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B0;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2A2;
    }
    D_80104B24_2B10D4_Last5Turns = 140;
    D_80104B28_2B10D8_Last5Turns = 90;
    D_80104B34_2B10E4_Last5Turns &= ~1;
    SHOW_MESSAGE(3);
    D_80104B40_2B10F0_Last5Turns++;
    DROP_STATUS();

    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B1;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2A3;
    }
    D_80104B24_2B10D4_Last5Turns = 140;
    D_80104B28_2B10D8_Last5Turns = 90;
    SHOW_MESSAGE(3);
    D_80104B40_2B10F0_Last5Turns++;
    DROP_STATUS();

    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B2;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2A4;
    }
    D_80104B24_2B10D4_Last5Turns = 140;
    D_80104B28_2B10D8_Last5Turns = 90;
    SHOW_MESSAGE(3);
    D_80104B40_2B10F0_Last5Turns++;
    DROP_STATUS();

    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B3;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2A5;
    }
    D_80104B24_2B10D4_Last5Turns = 140;
    D_80104B28_2B10D8_Last5Turns = 90;
    SHOW_MESSAGE(3);

    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B4;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2A6;
    }
    D_80104B24_2B10D4_Last5Turns = 140;
    D_80104B28_2B10D8_Last5Turns = 90;
    D_80104B34_2B10E4_Last5Turns |= 1;
    SHOW_MESSAGE(4);

    /* The event's model walks to the front and faces the camera. */
    omAddPrcObj(func_801048B8_2B0E68_Last5Turns, 0x12, 0, 0);
    HuPrcSleep(30);
    MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 1, 0, 5, 2);
    if (D_80104B44_2B10F4_Last5Turns != 2 && D_80104B44_2B10F4_Last5Turns != 3) {
        path = func_8005A718_5B318(D_80104B14_2B10C4_Last5Turns, 30.0f, 1, &D_801049C8_2B0F78_Last5Turns);
    } else {
        path = func_8005A718_5B318(D_80104B14_2B10C4_Last5Turns, 10.0f, 1, &D_801049D4_2B0F84_Last5Turns);
    }
    while (!func_8005A778_5B378(path)) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(path);
    MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 0, 0, 5, 2);
    HuVecCopyXYZ(&pos, D_800C9B80_CA780->pos.x, D_80104B14_2B10C4_Last5Turns->pos.y, D_800C9B80_CA780->pos.z);
    func_800446B4_452B4(D_80104B14_2B10C4_Last5Turns, &pos, 10);
    D_80104B18_2B10C8_Last5Turns = 2;
    HuPrcSleep(30);

    /* The event. */
    if (GwSystem.current_board_index == 5) {
        PlaySound(0x122);
        if (D_80104B80_2B1130_Last5Turns == 1) {
            D_80104B30_2B10E0_Last5Turns = 0x2B5;
            D_80104B24_2B10D4_Last5Turns = 150;
            D_80104B28_2B10D8_Last5Turns = 50;
            D_80104B2C_2B10DC_Last5Turns = 0;
        } else {
            D_80104B30_2B10E0_Last5Turns = 0x2B6;
            D_80104B24_2B10D4_Last5Turns = 150;
            D_80104B28_2B10D8_Last5Turns = 50;
            D_80104B2C_2B10DC_Last5Turns = 5;
        }
    } else {
        if (D_80104B44_2B10F4_Last5Turns == 0) {
            MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 3, 0, 5, 2);
            PlaySound(0xE6);
        }
        if (D_80104B44_2B10F4_Last5Turns == 1) {
            MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 3, 0, 5, 2);
            PlaySound(0xE7);
            HuPrcSleep(4);
            PlaySound(0xE7);
        }
        if (D_80104B44_2B10F4_Last5Turns == 2) {
            PlaySound(0xEA);
        }
        D_80104B30_2B10E0_Last5Turns = D_801049A8_2B0F58_Last5Turns[D_80104B44_2B10F4_Last5Turns] + 0x2A7;
        D_80104B24_2B10D4_Last5Turns = 150;
        D_80104B28_2B10D8_Last5Turns = 50;
        if (D_80104B44_2B10F4_Last5Turns == 2) {
            D_80104B2C_2B10DC_Last5Turns = 0;
        } else {
            D_80104B2C_2B10DC_Last5Turns = 5;
        }
    }
    omAddPrcObj(func_80103D60_2B0310_Last5Turns, 0x12, 0, 0);
    D_80104B18_2B10C8_Last5Turns = 0;
    WAIT_STEP();
    if (GwSystem.current_board_index == 5) {
        MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 2, 0, 5, 2);
    }
    if (D_80104B44_2B10F4_Last5Turns == 0 || D_80104B44_2B10F4_Last5Turns == 1) {
        MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 0, 0, 5, 2);
    }

    /* The player's status window moves to the front. */
    D_80104B38_2B10E8_Last5Turns = D_80104B20_2B10D0_Last5Turns;
    func_80104418_2B09C8_Last5Turns(0);
    WAIT_STEP();
    HuVecCopyXYZ(&pos, D_800C9B80_CA780->pos.x, 0.0f, D_800C9B80_CA780->pos.z);
    func_800446B4_452B4(D_80104B10_2B10C0_Last5Turns, &pos, 10);
    HuPrcSleep(10);
    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B7;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2AA;
    }
    D_80104B24_2B10D4_Last5Turns = 70;
    D_80104B28_2B10D8_Last5Turns = 90;
    D_80104B34_2B10E4_Last5Turns &= ~1;
    SHOW_MESSAGE(6);
    func_800614B4_620B4(D_80104B20_2B10D0_Last5Turns, 10);
    HuPrcSleep(30);

    /* Everything goes back. */
    func_80104418_2B09C8_Last5Turns(1);
    HuVecCopyXYZ(&pos, D_801049BC_2B0F6C_Last5Turns.x, 0.0f, D_801049BC_2B0F6C_Last5Turns.z);
    func_800446B4_452B4(D_80104B14_2B10C4_Last5Turns, &pos, 10);
    HuPrcSleep(10);
    if (GwSystem.current_board_index != 5) {
        MBMotionShiftSet(D_80104B14_2B10C4_Last5Turns, 1, 0, 5, 2);
    }
    if (D_80104B44_2B10F4_Last5Turns != 2 && D_80104B44_2B10F4_Last5Turns != 3) {
        path = func_8005A718_5B318(D_80104B14_2B10C4_Last5Turns, 35.0f, 1, &D_801049BC_2B0F6C_Last5Turns);
    } else {
        omAddPrcObj(func_801048B8_2B0E68_Last5Turns, 0x12, 0, 0);
        path = func_8005A718_5B318(D_80104B14_2B10C4_Last5Turns, 10.0f, 1, &D_801049BC_2B0F6C_Last5Turns);
    }
    while (!func_8005A778_5B378(path)) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(path);
    WAIT_STEP();
    if (D_80104B44_2B10F4_Last5Turns == 2 || D_80104B44_2B10F4_Last5Turns == 3) {
        D_80104B18_2B10C8_Last5Turns = 2;
        HuPrcVSleep();
        HuVecCopyXYZ(&pos, D_800C9B80_CA780->pos.x, 0.0f, D_800C9B80_CA780->pos.z);
        func_800446B4_452B4(D_80104B10_2B10C0_Last5Turns, &pos, 10);
    }
    HuPrcSleep(30);
    if (GwSystem.current_board_index == 5) {
        D_80104B30_2B10E0_Last5Turns = 0x2B8;
    } else {
        D_80104B30_2B10E0_Last5Turns = 0x2AB;
    }
    D_80104B24_2B10D4_Last5Turns = 65;
    D_80104B28_2B10D8_Last5Turns = 90;
    D_80104B34_2B10E4_Last5Turns |= 1;
    SHOW_MESSAGE(0);
    if (GwSystem.current_board_index == 5) {
        MBMotionShiftSet(D_80104B10_2B10C0_Last5Turns, 2, 0, 5, 2);
        HuPrcSleep(45);
    }
    func_801047E8_2B0D98_Last5Turns();
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* Drops the status window of rank D_80104B40 in from above with a little bounce. */
void func_80103B98_2B0148_Last5Turns(void) {
    s32 start[4] = { -197, -133, -74, -19 };
    s32 end[4] = { 16, 75, 132, 186 };
    f32 speeds[4] = { 29.4f, 29.4f, 29.4f, 29.4f };
    s32 idx;
    s16 y;
    f32 speed;
    f32 accel;
    s32 player;
    s32 x;

    x = 24;
    idx = D_801049A0_2B0F50_Last5Turns;
    y = start[idx];
    speed = speeds[idx];
    accel = -2.1f;
    player = func_80104404_2B09B4_Last5Turns(D_80104B40_2B10F0_Last5Turns);
    while (TRUE) {
        func_800600F8_60CF8(player, x, y);
        y = y + speed;
        speed += accel;
        if (speed < 0.0f && end[idx] >= y) {
            y = end[idx];
            func_800600F8_60CF8(player, x, y);
            D_801049A0_2B0F50_Last5Turns++;
            D_80104B18_2B10C8_Last5Turns = 1;
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
}

/* Shows message D_80104B30 at (D_80104B24, D_80104B28) with the arguments variant D_80104B2C
   asks for; waits for a press when D_80104B34 bit 0 is set. */
void func_80103D60_2B0310_Last5Turns(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 player;
    s32 win;

    if (D_80104B2C_2B10DC_Last5Turns == 1) {
        sprintf(num, "%d", D_80104B1C_2B10CC_Last5Turns);
        func_8008D974_8E574(num, 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 2) {
        sprintf(num, "%d", D_80104B1C_2B10CC_Last5Turns);
        sprintf(name, "%c%c", 0x18, gPlayers[D_80104B20_2B10D0_Last5Turns].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 3) {
        player = func_80104404_2B09B4_Last5Turns(D_80104B40_2B10F0_Last5Turns);
        D_80104B30_2B10E0_Last5Turns = func_80059FD0_5ABD0(player) + 0x2A2;
        sprintf(num, "%c%c", 0x18, gPlayers[player].character);
        func_8008D974_8E574(num, 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 4) {
        func_8008D974_8E574((char*)(D_80104B44_2B10F4_Last5Turns + 0x2AC), 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 5) {
        sprintf(num, "%c%c", 0x18, gPlayers[D_80104B20_2B10D0_Last5Turns].character);
        func_8008D974_8E574(num, 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 6) {
        sprintf(num, "%c%c", 0x18, gPlayers[D_80104B20_2B10D0_Last5Turns].character);
        func_8008D974_8E574(num, 0);
        func_8008D974_8E574((char*)(D_80104B44_2B10F4_Last5Turns + 0x2AC), 1);
    }
    func_8008DACC_8E6CC(1, size, D_80104B30_2B10E0_Last5Turns);
    win = func_801041B4_2B0764_Last5Turns((s16)D_80104B24_2B10D4_Last5Turns, (s16)D_80104B28_2B10D8_Last5Turns, size[0], size[1], 0, 0, 200);
    if (D_80104B34_2B10E4_Last5Turns & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 1 || D_80104B2C_2B10DC_Last5Turns == 3 || D_80104B2C_2B10DC_Last5Turns == 4 ||
        D_80104B2C_2B10DC_Last5Turns == 5) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 2) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 4) {
        func_80089308_89F08(win, (char*)(D_80104B44_2B10F4_Last5Turns + 0x2AC), 0);
    }
    if (D_80104B2C_2B10DC_Last5Turns == 6) {
        func_80089308_89F08(win, num, 0);
        func_80089308_89F08(win, (char*)(D_80104B44_2B10F4_Last5Turns + 0x2AC), 1);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80104B30_2B10E0_Last5Turns, -1, -1);
    func_80057DA4_589A4((s16)win);
    while (TRUE) {
        if (D_80104B34_2B10E4_Last5Turns & 1) {
            func_8005762C_5822C((s16)win);
        } else {
            func_8008CCA8_8D8A8(win);
        }
        D_80104B18_2B10C8_Last5Turns = 1;
        omDelPrcObj(NULL);
        HuPrcVSleep();
    }
}

/* Opens a message window that only the pads of D_80104B38's player (and D_80104B3C's, never set
   here) can advance. */
/* NON_MATCHING: registers (masked 14), as overlay 3F's func_80104844: retail swaps s0/s1 between arg6 and
   the narrowed window id */
#ifdef NON_MATCHING
s32 func_801041B4_2B0764_Last5Turns(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80104B3C_2B10EC_Last5Turns != -1) {
        mask = (1 << gPlayers[D_80104B38_2B10E8_Last5Turns].port) | (1 << gPlayers[D_80104B3C_2B10EC_Last5Turns].port);
    } else {
        mask = 1 << gPlayers[D_80104B38_2B10E8_Last5Turns].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_40_Last5Turns/2AEDB0", func_801041B4_2B0764_Last5Turns);
#endif

/* Sorts the players by rank into D_80104B60 (ties keep player order). */
void func_8010431C_2B08CC_Last5Turns(void) {
    s32 key[4];
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 4; i++) {
        key[i] = func_80059FD0_5ABD0(i) * 4 + i;
        D_80104B60_2B1110_Last5Turns[i] = i;
    }
    for (i = 0; i < 3; i++) {
        for (j = i; j < 4; j++) {
            if (key[i] > key[j]) {
                t = key[j];
                key[j] = key[i];
                key[i] = t;
                t = D_80104B60_2B1110_Last5Turns[j];
                D_80104B60_2B1110_Last5Turns[j] = D_80104B60_2B1110_Last5Turns[i];
                D_80104B60_2B1110_Last5Turns[i] = t;
            }
        }
    }
}

s32 func_80104404_2B09B4_Last5Turns(s32 rank) {
    return D_80104B60_2B1110_Last5Turns[rank];
}

/* Moves the status windows to layout `layout` of D_80104958: D_80104B38's player takes slot 3,
   D_80104B3C's slot 2, the others slots 0, 1 (listed in D_80104B70). D_80104B18 is set when
   every window has arrived (func_80104750). */
void func_80104418_2B09C8_Last5Turns(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80104B18_2B10C8_Last5Turns = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80104750_2B0D00_Last5Turns);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80104B48_2B10F8_Last5Turns[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80104B38_2B10E8_Last5Turns) {
                if (i == D_80104B3C_2B10EC_Last5Turns) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80104B70_2B1120_Last5Turns[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80104958_2B0F08_Last5Turns[layout].pos[slot][0] != -1) {
                status->xPos = D_80104958_2B0F08_Last5Turns[layout].pos[slot][0];
            }
            if (D_80104958_2B0F08_Last5Turns[layout].pos[slot][1] != -1) {
                status->yPos = D_80104958_2B0F08_Last5Turns[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80104958_2B0F08_Last5Turns[layout].frames - 1;
            if (D_80104958_2B0F08_Last5Turns[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80104958_2B0F08_Last5Turns[layout].pos[slot][2];
            }
            if (D_80104958_2B0F08_Last5Turns[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80104958_2B0F08_Last5Turns[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_801049A4_2B0F54_Last5Turns == 1) {
        status = &D_80101510_102110[D_80104B38_2B10E8_Last5Turns];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80104958_2B0F08_Last5Turns[layout].frames - 1;
    }
}

void func_80104750_2B0D00_Last5Turns(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80104B48_2B10F8_Last5Turns[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80104B58_2B1108_Last5Turns) {
        D_80104B18_2B10C8_Last5Turns = 1;
        omDelObj(obj);
    }
}

void func_801047E8_2B0D98_Last5Turns(void) {
    omAddObj(0x10, 0, 0, -1, func_8010481C_2B0DCC_Last5Turns);
}

void func_8010481C_2B0DCC_Last5Turns(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(45);
        obj->func_ptr = func_80104864_2B0E14_Last5Turns;
    }
}

void func_80104864_2B0E14_Last5Turns(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

/* The host keeps facing the event's model until D_80104B18 is 2. */
void func_801048B8_2B0E68_Last5Turns(void) {
    Vec pos;

    while (D_80104B18_2B10C8_Last5Turns != 2) {
        HuVecCopyXYZ(&pos, D_80104B14_2B10C4_Last5Turns->pos.x, 0.0f, D_80104B14_2B10C4_Last5Turns->pos.z);
        func_800446B4_452B4(D_80104B10_2B10C0_Last5Turns, &pos, 10);
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}
