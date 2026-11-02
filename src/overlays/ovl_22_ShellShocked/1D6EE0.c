#include "ovl_22.h"

void func_80102800_1D6EE0_ShellShocked(void) {
    func_80102824_1D6F04_ShellShocked();
}

void func_8010281C_1D6EFC_ShellShocked(void) {
}

void func_80102824_1D6F04_ShellShocked(void) {
    func_80020070_20C70(4);
    func_8002D4D0_2E0D0(0x14);
    omInitObjMan(0x1E, 0);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0x14);
    func_80079128_79D28();
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026DAC_279AC(3, 0, 0, 0);
    func_80026E00_27A00(1, 0.0f, 64.0f, 192.0f);
    func_80103904_1D7FE4_ShellShocked();
    if (func_80103944_1D8024_ShellShocked() != 0 && func_80103938_1D8018_ShellShocked() == 0) {
        D_8010D570_1E1C50_ShellShocked[0] = omAddObj(6, 0x10, 0, -1, func_8010386C_1D7F4C_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[1] = omAddObj(0x7FDA, 0, 0, -1, func_80105014_1D96F4_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[2] = omAddObj(6, 0x10, 0, -1, func_801091F0_1DD8D0_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[3] = omAddObj(6, 0x10, 0, -1, func_8010A19C_1DE87C_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[4] = omAddObj(6, 0x10, 0, -1, func_801091E0_1DD8C0_ShellShocked);
        func_8010386C_1D7F4C_ShellShocked(D_8010D570_1E1C50_ShellShocked[0]);
        func_80105014_1D96F4_ShellShocked(D_8010D570_1E1C50_ShellShocked[1]);
        func_801091F0_1DD8D0_ShellShocked(D_8010D570_1E1C50_ShellShocked[2]);
        func_8010A19C_1DE87C_ShellShocked(D_8010D570_1E1C50_ShellShocked[3]);
    } else if (func_80103938_1D8018_ShellShocked() != 0) {
        D_8010D570_1E1C50_ShellShocked[0] = omAddObj(6, 0x10, 0, -1, func_80103500_1D7BE0_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[1] = omAddObj(0x7FDA, 0, 0, -1, func_80105014_1D96F4_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[2] = omAddObj(6, 0x10, 0, -1, func_801091F0_1DD8D0_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[3] = omAddObj(6, 0x10, 0, -1, func_8010A19C_1DE87C_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[4] = omAddObj(6, 0x10, 0, -1, func_801091E0_1DD8C0_ShellShocked);
        func_80103500_1D7BE0_ShellShocked(D_8010D570_1E1C50_ShellShocked[0]);
        func_80105014_1D96F4_ShellShocked(D_8010D570_1E1C50_ShellShocked[1]);
        func_801091F0_1DD8D0_ShellShocked(D_8010D570_1E1C50_ShellShocked[2]);
        func_8010A19C_1DE87C_ShellShocked(D_8010D570_1E1C50_ShellShocked[3]);
    } else {
        D_8010D570_1E1C50_ShellShocked[0] = omAddObj(6, 0x10, 0, -1, func_801031A4_1D7884_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[1] = omAddObj(0x7FDA, 0, 0, -1, func_80105014_1D96F4_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[2] = omAddObj(6, 0x10, 0, -1, func_801091F0_1DD8D0_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[3] = omAddObj(6, 0x10, 0, -1, func_8010A19C_1DE87C_ShellShocked);
        D_8010D570_1E1C50_ShellShocked[4] = omAddObj(6, 0x10, 0, -1, func_801091E0_1DD8C0_ShellShocked);
        func_801031A4_1D7884_ShellShocked(D_8010D570_1E1C50_ShellShocked[0]);
        func_80105014_1D96F4_ShellShocked(D_8010D570_1E1C50_ShellShocked[1]);
        func_801091F0_1DD8D0_ShellShocked(D_8010D570_1E1C50_ShellShocked[2]);
        func_8010A19C_1DE87C_ShellShocked(D_8010D570_1E1C50_ShellShocked[3]);
    }
    D_800FDEAE_FEAAE = 0;
}

void func_80102B8C_1D726C_ShellShocked(void) {
    switch (D_8010D5B0_1E1C90_ShellShocked) {
    case 4:
    case 5:
        if (D_801011FC_101DFC == 1) {
            D_8010D5B0_1E1C90_ShellShocked = 0xF;
        }
        break;
    }
}

void func_80102BC8_1D72A8_ShellShocked(omObjData* obj) {
    s32 i;
    s32 n;
    s32 winner;

    func_80102B8C_1D726C_ShellShocked();
    switch (D_8010D5B0_1E1C90_ShellShocked) {
    case 0:
        func_801038A4_1D7F84_ShellShocked(-1);
        PlayMusic(0x1B);
        D_8010D5B0_1E1C90_ShellShocked = 1;
        break;
    case 1:
        InitFadeIn(0, 0x10);
        D_8010D5B0_1E1C90_ShellShocked = 2;
        break;
    case 2:
        if (func_8008F618_90218() == 0) {
            D_8010DFE4_1E26C4_ShellShocked.seconds = 0x3C;
            D_8010DFE4_1E26C4_ShellShocked.frames = 0x1D;
            func_8006D4D0_6E0D0((s16)D_8010DFE4_1E26C4_ShellShocked.seconds);
            if (func_80105068_1D9748_ShellShocked(-1) == 0) {
                D_8010D5B0_1E1C90_ShellShocked = 3;
                func_800691FC_69DFC(0);
            }
        }
        break;
    case 3:
        if (func_80069538_6A138() == 0) {
            func_8010C57C_1E0C5C_ShellShocked();
            D_8010D5B0_1E1C90_ShellShocked = 4;
            PlayMusic(0x1B);
            func_800691FC_69DFC(0xA, D_8010DFE4_1E26C4_ShellShocked.seconds, 0xA0, 0x20);
            D_800FDEAE_FEAAE = 1;
            omSetStatBit(D_8010D570_1E1C50_ShellShocked[1], 0xA0);
        }
        break;
    case 4:
        func_8006D4D0_6E0D0((s16)D_8010DFE4_1E26C4_ShellShocked.seconds);
        if (D_8010DFE4_1E26C4_ShellShocked.seconds == 0) {
            D_8010D5B0_1E1C90_ShellShocked = 7;
            func_8010C604_1E0CE4_ShellShocked();
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            D_800FDEAE_FEAAE = 0;
            break;
        }
        for (i = 0, n = 0; i < 4; i++) {
            n += func_8010C1F0_1E08D0_ShellShocked(i) != 0;
        }
        if (n >= 3) {
            func_801038BC_1D7F9C_ShellShocked(8);
            D_8010D5B0_1E1C90_ShellShocked = 5;
            func_8010C604_1E0CE4_ShellShocked();
        }
        if (--D_8010DFE4_1E26C4_ShellShocked.frames < 0) {
            D_8010DFE4_1E26C4_ShellShocked.frames = 0x1D;
            D_8010DFE4_1E26C4_ShellShocked.seconds--;
        }
        break;
    case 5:
        if (func_801038F8_1D7FD8_ShellShocked() > 0) {
            func_801038C8_1D7FA8_ShellShocked();
            break;
        }
        func_8010C7AC_1E0E8C_ShellShocked();
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) != 0) {
                n++;
            } else {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n == 4) {
            func_801038A4_1D7F84_ShellShocked(-1);
            func_800794A8_7A0A8(0x28);
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        D_800FDEAE_FEAAE = 0;
        break;
    case 6:
        if (func_80069538_6A138() == 0) {
            if (func_801038B0_1D7F90_ShellShocked() != -1) {
                for (i = 0; i < 4; i++) {
                    func_80105044_1D9724_ShellShocked(i, 0x14);
                }
                func_801038BC_1D7F9C_ShellShocked(0);
                D_8010D5B0_1E1C90_ShellShocked = 8;
                func_800794A8_7A0A8(0x28);
                break;
            }
            D_8010D5B0_1E1C90_ShellShocked = 9;
        }
        break;
    case 7:
        for (i = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
            }
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C100_1E07E0_ShellShocked(i) == 2) {
                n++;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n == 1) {
            break;
        }
        if (n >= 2) {
            func_801038A4_1D7F84_ShellShocked(-1);
            break;
        }
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C100_1E07E0_ShellShocked(i) == 1) {
                n++;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n != 1) {
            func_800794A8_7A0A8(0x28);
            func_801038A4_1D7F84_ShellShocked(-1);
        }
        break;
    case 8:
        if (func_801038E0_1D7FC0_ShellShocked() > 0x50) {
            for (i = 0; i < 4; i++) {
                func_80105044_1D9724_ShellShocked(i, 0x16);
            }
            func_801038BC_1D7F9C_ShellShocked(0x50);
            D_8010D5B0_1E1C90_ShellShocked = 9;
        }
        break;
    case 9:
        winner = func_801038B0_1D7F90_ShellShocked();
        if (winner == -1) {
            func_801038BC_1D7F9C_ShellShocked(0x78);
            func_800691FC_69DFC(0x13);
            PlayMusic(0x57);
        } else {
            func_801038BC_1D7F9C_ShellShocked(0x78);
            func_800691FC_69DFC(6, gPlayers[winner].character);
            PlayMusic(0x51);
            func_800797DC_7A3DC(0x103, winner);
            gPlayers[winner].coins_mg_bonus += 0xA;
        }
        D_8010D5B0_1E1C90_ShellShocked = 0xA;
        break;
    case 10:
        if (func_801038F8_1D7FD8_ShellShocked() > 0) {
            func_801038C8_1D7FA8_ShellShocked();
            break;
        }
        if ((func_80069538_6A138() == 0 || func_80069538_6A138() == 2) && func_800696E4_6A2E4() != 0) {
            D_8010D5B0_1E1C90_ShellShocked = 0xB;
        }
        break;
    case 11:
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        D_8010D5B0_1E1C90_ShellShocked = 0xC;
        func_8010C7AC_1E0E8C_ShellShocked();
        break;
    case 12:
        if (func_8008F618_90218() == 0) {
            D_8010D5B0_1E1C90_ShellShocked = 0xD;
        }
        break;
    case 15:
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        D_8010D5B0_1E1C90_ShellShocked = 0x10;
        func_8010C7AC_1E0E8C_ShellShocked();
        break;
    case 16:
        if (func_8008F618_90218() == 0) {
            D_8010D5B0_1E1C90_ShellShocked = 0x11;
        }
        break;
    case 13:
    case 17:
        func_80079868_7A468();
        omOvlReturnEx(1);
        break;
    }
}

void func_801031A4_1D7884_ShellShocked(omObjData* obj) {
    D_8010D5B0_1E1C90_ShellShocked = 0;
    obj->func_ptr = func_80102BC8_1D72A8_ShellShocked;
}

void func_801031BC_1D789C_ShellShocked(omObjData* obj) {
    s32 i;
    s32 n;

    func_80102B8C_1D726C_ShellShocked();
    switch (D_8010D5B0_1E1C90_ShellShocked) {
    case 4:
        func_8006D4D0_6E0D0((s16)D_8010DFE4_1E26C4_ShellShocked.seconds);
        if (D_8010DFE4_1E26C4_ShellShocked.seconds == 0) {
            D_8010D5B0_1E1C90_ShellShocked = 7;
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            D_800FDEAE_FEAAE = 0;
            break;
        }
        if (func_8010C1F0_1E08D0_ShellShocked(0) != 0) {
            func_801038BC_1D7F9C_ShellShocked(8);
            D_8010D5B0_1E1C90_ShellShocked = 5;
            func_8010C604_1E0CE4_ShellShocked();
        }
        for (i = 1, n = 0; i < 4; i++) {
            n += func_8010C1F0_1E08D0_ShellShocked(i) != 0;
        }
        if (n >= 3) {
            func_801038BC_1D7F9C_ShellShocked(8);
            D_8010D5B0_1E1C90_ShellShocked = 5;
            func_8010C604_1E0CE4_ShellShocked();
        }
        if (--D_8010DFE4_1E26C4_ShellShocked.frames < 0) {
            D_8010DFE4_1E26C4_ShellShocked.frames = 0x1D;
            D_8010DFE4_1E26C4_ShellShocked.seconds--;
        }
        break;
    case 5:
        if (func_801038F8_1D7FD8_ShellShocked() > 0) {
            func_801038C8_1D7FA8_ShellShocked();
            break;
        }
        func_8010C7AC_1E0E8C_ShellShocked();
        for (i = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
            }
        }
        func_801038A4_1D7F84_ShellShocked(0);
        for (i = 1; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                func_801038A4_1D7F84_ShellShocked(-1);
                break;
            }
        }
        if (func_8010C1F0_1E08D0_ShellShocked(0) != 0) {
            func_801038A4_1D7F84_ShellShocked(-1);
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        func_800794A8_7A0A8(0x28);
        D_800FDEAE_FEAAE = 0;
        break;
    case 6:
        if (func_80069538_6A138() == 0) {
            func_801038BC_1D7F9C_ShellShocked(0);
            D_8010D5B0_1E1C90_ShellShocked = 0xB;
            if (func_801038B0_1D7F90_ShellShocked() == 0) {
                gPlayers[0].coins_mg_bonus += 0xA;
            }
            func_800794A8_7A0A8(0x28);
        }
        break;
    case 7:
        for (i = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
            }
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        func_800794A8_7A0A8(0x28);
        func_801038A4_1D7F84_ShellShocked(0);
        if (func_8010C1F0_1E08D0_ShellShocked(0) != 0) {
            func_801038A4_1D7F84_ShellShocked(-1);
        }
        for (i = 1; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                func_801038A4_1D7F84_ShellShocked(-1);
            }
        }
        break;
    default:
        func_80102BC8_1D72A8_ShellShocked(obj);
        break;
    }
}

void func_80103500_1D7BE0_ShellShocked(omObjData* obj) {
    D_8010D5B0_1E1C90_ShellShocked = 0;
    obj->func_ptr = func_801031BC_1D789C_ShellShocked;
}

void func_80103518_1D7BF8_ShellShocked(omObjData* obj) {
    s32 i;
    s32 n;

    func_80102B8C_1D726C_ShellShocked();
    switch (D_8010D5B0_1E1C90_ShellShocked) {
    case 4:
        func_8006D4D0_6E0D0((s16)D_8010DFE4_1E26C4_ShellShocked.seconds);
        if (D_8010DFE4_1E26C4_ShellShocked.seconds == 0) {
            D_8010D5B0_1E1C90_ShellShocked = 7;
            func_8010C604_1E0CE4_ShellShocked();
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            D_800FDEAE_FEAAE = 0;
            break;
        }
        for (i = 0, n = 0; i < 4; i++) {
            n += func_8010C1F0_1E08D0_ShellShocked(i) != 0;
        }
        if (n >= 3) {
            func_801038BC_1D7F9C_ShellShocked(8);
            D_8010D5B0_1E1C90_ShellShocked = 5;
            func_8010C604_1E0CE4_ShellShocked();
        }
        if (func_8010C1F0_1E08D0_ShellShocked(0) != 0) {
            func_801038A4_1D7F84_ShellShocked(-1);
            D_8010D5B0_1E1C90_ShellShocked = 6;
            func_8010C604_1E0CE4_ShellShocked();
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            D_800FDEAE_FEAAE = 0;
            break;
        }
        if (--D_8010DFE4_1E26C4_ShellShocked.frames < 0) {
            D_8010DFE4_1E26C4_ShellShocked.frames = 0x1D;
            D_8010DFE4_1E26C4_ShellShocked.seconds--;
        }
        break;
    case 5:
        if (func_801038F8_1D7FD8_ShellShocked() > 0) {
            func_801038C8_1D7FA8_ShellShocked();
            break;
        }
        func_8010C7AC_1E0E8C_ShellShocked();
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) != 0) {
                n++;
            } else {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n == 4) {
            func_801038A4_1D7F84_ShellShocked(-1);
            func_800794A8_7A0A8(0x28);
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        D_800FDEAE_FEAAE = 0;
        break;
    case 6:
        if (func_80069538_6A138() == 0) {
            func_801038BC_1D7F9C_ShellShocked(0);
            if (func_801038B0_1D7F90_ShellShocked() == 0) {
                gPlayers[0].coins_mg_bonus += 0xA;
            }
            func_800794A8_7A0A8(0x28);
            D_8010D5B0_1E1C90_ShellShocked = 0xB;
        }
        break;
    case 7:
        for (i = 0; i < 4; i++) {
            if (func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
                D_8010DA80_1E2160_ShellShocked[i].state = 3;
            }
        }
        D_8010D5B0_1E1C90_ShellShocked = 6;
        func_800794A8_7A0A8(0x28);
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C100_1E07E0_ShellShocked(i) == 2) {
                n++;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n == 1) {
            break;
        }
        if (n >= 2) {
            func_801038A4_1D7F84_ShellShocked(-1);
            break;
        }
        for (i = 0, n = 0; i < 4; i++) {
            if (func_8010C100_1E07E0_ShellShocked(i) == 1) {
                n++;
                func_801038A4_1D7F84_ShellShocked(i);
            }
        }
        if (n != 1) {
            func_801038A4_1D7F84_ShellShocked(-1);
        }
        break;
    default:
        func_80102BC8_1D72A8_ShellShocked(obj);
        break;
    }
}

void func_8010386C_1D7F4C_ShellShocked(omObjData* obj) {
    D_8010D5B0_1E1C90_ShellShocked = 0;
    obj->func_ptr = func_80103518_1D7BF8_ShellShocked;
}

omObjData* func_80103884_1D7F64_ShellShocked(s32 i) {
    return D_8010D570_1E1C50_ShellShocked[i];
}

s32 func_80103898_1D7F78_ShellShocked(void) {
    return D_8010D5B0_1E1C90_ShellShocked;
}

void func_801038A4_1D7F84_ShellShocked(s32 player) {
    D_8010D5B4_1E1C94_ShellShocked = player;
}

s32 func_801038B0_1D7F90_ShellShocked(void) {
    return D_8010D5B4_1E1C94_ShellShocked;
}

void func_801038BC_1D7F9C_ShellShocked(s32 n) {
    D_8010D5B8_1E1C98_ShellShocked = n;
}

void func_801038C8_1D7FA8_ShellShocked(void) {
    D_8010D5B8_1E1C98_ShellShocked--;
}

s32 func_801038E0_1D7FC0_ShellShocked(void) {
    return ++D_8010D5B8_1E1C98_ShellShocked;
}

s32 func_801038F8_1D7FD8_ShellShocked(void) {
    return D_8010D5B8_1E1C98_ShellShocked;
}

void func_80103904_1D7FE4_ShellShocked(void) {
    D_8010D5BC_1E1C9C_ShellShocked = _CheckFlag(0xE);
    D_8010D5C0_1E1CA0_ShellShocked = _CheckFlag(0xC);
}

s32 func_80103938_1D8018_ShellShocked(void) {
    return D_8010D5BC_1E1C9C_ShellShocked;
}

s32 func_80103944_1D8024_ShellShocked(void) {
    return D_8010D5C0_1E1CA0_ShellShocked;
}

u8 func_80103950_1D8030_ShellShocked(s32 i) {
    if (D_8010D5BC_1E1C9C_ShellShocked != 0) {
        if (i != 0) {
            return 6;
        }
        return gPlayers[0].character;
    }
    return gPlayers[i].character;
}

u8 func_80103998_1D8078_ShellShocked(s32 i) {
    return gPlayers[i].cpu_difficulty;
}

f32 func_801039BC_1D809C_ShellShocked(void) {
    return rand8() * 0.00390625f;
}

// register allocation: a0/a1 swapped for the search index (masked 0)
#ifdef NON_MATCHING
s32* func_801039F8_1D80D8_ShellShocked(void) {
    s32 order[4];
    s32 i;
    s32 n;
    s32 t;
    s32* p;

    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    rand8();
    rand8();
    n = func_801039BC_1D809C_ShellShocked() * 4.0f;
    D_8010D5C8_1E1CA8_ShellShocked[0] = order[n];
    for (i = 0, n = 0; i < 4; i++) {
        if (i != D_8010D5C8_1E1CA8_ShellShocked[0]) {
            order[n++] = i;
        }
    }
    n = func_801039BC_1D809C_ShellShocked() * 3.0f;
    D_8010D5C8_1E1CA8_ShellShocked[1] = order[n];
    for (i = 0, n = 0; i < 4; i++) {
        if (i != D_8010D5C8_1E1CA8_ShellShocked[0] && i != D_8010D5C8_1E1CA8_ShellShocked[1]) {
            order[n++] = i;
        }
    }
    n = 2.0f * func_801039BC_1D809C_ShellShocked();
    p = &D_8010D5C8_1E1CA8_ShellShocked[2];
    t = order[n];
    *p++ = t;
    if (t == order[0]) {
        *p = order[1];
    } else {
        *p = order[0];
    }
    return D_8010D5C8_1E1CA8_ShellShocked;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D6EE0", func_801039F8_1D80D8_ShellShocked);
#endif

__asm__(".section .rodata\n\t.balign 16\n\t.text");
