#include "ovl_58.h"

/* Entry: camera, lights, the setup and its processes; the stage from the board index or the
   mode (D_800CD414: 0 free play, 3 uses the saved record). */
void func_80102800_36DF00_MinigameParkSetup(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(25);
    omInitObjMan(51, 25);
    func_80088640_89240();
    func_80079128_79D28();
    D_801135C0_37ECC0_MinigameParkSetup = 49.0f;
    D_80113E24_37F524_MinigameParkSetup = 80.0f;
    D_80113BF4_37F2F4_MinigameParkSetup = 8000.0f;
    Hu3DCamSetPerspective(0, 49.0f, 80.0f, 8000.0f);
    omAddObj(10000, 0, 0, -1, func_801109C8_37C0C8_MinigameParkSetup);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 100, 100, 100);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    omAddPrcObj(func_80102CAC_36E3AC_MinigameParkSetup, 0x3F00, 0x1800, 0);
    omPrcSetStatBit(omAddPrcObj(func_80111D8C_37D48C_MinigameParkSetup, 0x1100, 0x800, 0), 0xA0);
    InitFadeIn(255, 16);
    PlayMusic(7);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0, 0, 0);
    D_80113870_37EF70_MinigameParkSetup = D_80112B4C_37E24C_MinigameParkSetup;
    D_8011381A_37EF1A_MinigameParkSetup = D_800FD80C_FE40C;
    if (D_800CD414_CE014 == 0) {
        D_80113814_37EF14_MinigameParkSetup = GwSystem.current_board_index;
        if (D_80113814_37EF14_MinigameParkSetup == 8) {
            D_80113814_37EF14_MinigameParkSetup = 7;
        }
    } else if (D_800CD414_CE014 == 3) {
        D_80113814_37EF14_MinigameParkSetup = 6;
        GwSystem.current_board_index = 7;
        func_8007E128_7ED28();
        func_8007E0F8_7ECF8(D_800FD420_FE020);
    } else {
        D_80113814_37EF14_MinigameParkSetup = 6;
        GwSystem.current_board_index = 0;
    }
    func_80112950_37E050_MinigameParkSetup();
    D_8011381E_37EF1E_MinigameParkSetup = 0x73;
    D_80113820_37EF20_MinigameParkSetup = 0;
    D_8011381C_37EF1C_MinigameParkSetup = 0;
    D_80113822_37EF22_MinigameParkSetup = 0;
    _ClearFlag(0xC);
    func_80075424_76024(4);
    func_8007550C_7610C(4);
}

/* Reset the setup: inserted pads first (in port order), then the free ports; each player
   starts as its own character. */
void func_80102A60_36E160_MinigameParkSetup(void) {
    s16 i;
    s16 j;
    s16 port;
    s16 n;

    D_80113784_37EE84_MinigameParkSetup = 0;
    D_80113780_37EE80_MinigameParkSetup = 0;
    D_80113782_37EE82_MinigameParkSetup = 0;
    D_80113786_37EE86_MinigameParkSetup = 0;
    D_80113788_37EE88_MinigameParkSetup = 0;
    for (i = 0; i < 4; i++) {
        D_80113958_37F058_MinigameParkSetup.port[i] = 0xFF;
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            D_80113958_37F058_MinigameParkSetup.port[n] = i;
            n++;
        }
        D_80113958_37F058_MinigameParkSetup.character[i] = i;
        D_80113958_37F058_MinigameParkSetup.cpuLevel[i] = 0xFF;
    }
    for (i = 0; i < 4; i++) {
        if (D_80113958_37F058_MinigameParkSetup.port[i] == 0xFF) {
            for (port = 0; port < 4; port++) {
                for (j = 0; j < 4; j++) {
                    if (D_80113958_37F058_MinigameParkSetup.port[j] == port) {
                        break;
                    }
                }
                if (j == 4) {
                    break;
                }
            }
            if (port == 4) {
                osSyncPrintf("pad Error\n");
            }
            D_80113958_37F058_MinigameParkSetup.port[i] = port;
        }
    }
    D_80113958_37F058_MinigameParkSetup.gameLength = 0;
    D_80113958_37F058_MinigameParkSetup.bonus = 0;
    D_80113958_37F058_MinigameParkSetup.padCount = n;
    D_8011381A_37EF1A_MinigameParkSetup = D_80113958_37F058_MinigameParkSetup.port[0];
    for (i = 0; i < 4; i++) {
        D_80113958_37F058_MinigameParkSetup.handicap[i] = 0;
    }
    D_80113816_37EF16_MinigameParkSetup = -1;
}

/* The setup process: scene, panels, then the mode's setup loop. */
void func_80102CAC_36E3AC_MinigameParkSetup(void) {
    s16 i;

    func_80102A60_36E160_MinigameParkSetup();
    D_80112BBC_37E2BC_MinigameParkSetup[0x50] = D_80113364_37EA64_MinigameParkSetup[D_80113814_37EF14_MinigameParkSetup];
    D_80112BBC_37E2BC_MinigameParkSetup[0x6E] = D_80113384_37EA84_MinigameParkSetup[D_80113814_37EF14_MinigameParkSetup];
    func_80112360_37DA60_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup);
    func_80110AF0_37C1F0_MinigameParkSetup(0);
    omAddPrcObj(func_80111328_37CA28_MinigameParkSetup, 0x3F00, 0x800, 0);
    func_80111744_37CE44_MinigameParkSetup(&D_80113798_37EE98_MinigameParkSetup);
    D_80113800_37EF00_MinigameParkSetup = 0;
    for (i = 0; i < 5; i++) {
        D_801137B8_37EEB8_MinigameParkSetup[i] = omAddPrcObj(func_80106AF8_3721F8_MinigameParkSetup, 0x3F00, 0x800, 0);
    }
    D_80113802_37EF02_MinigameParkSetup = 0;
    for (i = 0; i < 6; i++) {
        omAddPrcObj(func_80107180_372880_MinigameParkSetup, 0x3F00, 0x800, 0);
    }
    omAddPrcObj(func_80108C0C_37430C_MinigameParkSetup, 0x3F00, 0x800, 0);
    omAddPrcObj(func_8010903C_37473C_MinigameParkSetup, 0x3F00, 0x800, 0);
    omAddPrcObj(func_8010F358_37AA58_MinigameParkSetup, 0x3F00, 0x400, 0);
    HuPrcSleep(20);
    D_80113790_37EE90_MinigameParkSetup = 0;
    omAddPrcObj(func_8010FB00_37B200_MinigameParkSetup, 0x3F00, 0x800, 0);
    while (D_80113790_37EE90_MinigameParkSetup == 0) {
        HuPrcVSleep();
    }
    if (GwSystem.current_board_index == 8) {
        func_8010395C_36F05C_MinigameParkSetup();
    }
    switch (D_800CD414_CE014) {
    case 0:
        func_80102F00_36E600_MinigameParkSetup();
        break;
    case 1:
        func_80103140_36E840_MinigameParkSetup();
        break;
    case 2:
        func_801033E0_36EAE0_MinigameParkSetup();
        break;
    case 3:
        func_80103ABC_36F1BC_MinigameParkSetup();
        break;
    }
}

/* Mode 0's setup steps: players, characters, CPU levels, handicaps, then length/bonus. */
void func_80102F00_36E600_MinigameParkSetup(void) {
    s16 ret;

    func_80110350_37BA50_MinigameParkSetup(0x52);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_80111750_37CE50_MinigameParkSetup(5);
    while (1) {
        switch (D_80113780_37EE80_MinigameParkSetup) {
        case 0:
            func_80110350_37BA50_MinigameParkSetup(0x54);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80103F38_36F638_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                func_80110350_37BA50_MinigameParkSetup(0x53);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    D_80113780_37EE80_MinigameParkSetup = 0;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                } else {
                    func_8010ED54_37A454_MinigameParkSetup();
                }
            }
            break;
        case 1:
            func_80110350_37BA50_MinigameParkSetup(0x59);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_801052B4_3709B4_MinigameParkSetup() != 0) {
                if (D_80113958_37F058_MinigameParkSetup.cpus == 0) {
                    D_80113780_37EE80_MinigameParkSetup += 2;
                } else {
                    D_80113780_37EE80_MinigameParkSetup++;
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 2:
            if (func_80107644_372D44_MinigameParkSetup(3) != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 3:
            func_80110350_37BA50_MinigameParkSetup(0x69);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80109478_374B78_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                if (D_80113958_37F058_MinigameParkSetup.humans == 4) {
                    D_80113780_37EE80_MinigameParkSetup--;
                }
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 4:
            if (D_80113782_37EE82_MinigameParkSetup == 0) {
                func_80110350_37BA50_MinigameParkSetup(0x6D);
                func_801103A4_37BAA4_MinigameParkSetup();
            }
            ret = func_8010A1E8_3758E8_MinigameParkSetup();
            if (ret == 1) {
                func_8010F0A4_37A7A4_MinigameParkSetup();
            } else if (ret == -1) {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            } else if (D_80113782_37EE82_MinigameParkSetup == 0) {
                func_8010E460_379B60_MinigameParkSetup();
            }
            break;
        }
        HuPrcVSleep();
    }
}

/* Mode 1's setup steps (as mode 0 without the handicap and length steps). */
void func_80103140_36E840_MinigameParkSetup(void) {
    s16 i;

    func_80110350_37BA50_MinigameParkSetup(0x366);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_80111750_37CE50_MinigameParkSetup(5);
    while (1) {
        switch (D_80113780_37EE80_MinigameParkSetup) {
        case 0:
            func_80110350_37BA50_MinigameParkSetup(0x54);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80103F38_36F638_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                func_80110350_37BA50_MinigameParkSetup(0x53);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    D_80113780_37EE80_MinigameParkSetup = 0;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                } else {
                    func_8010ED54_37A454_MinigameParkSetup();
                }
            }
            break;
        case 1:
            func_80110350_37BA50_MinigameParkSetup(0x59);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_801052B4_3709B4_MinigameParkSetup() != 0) {
                if (D_80113958_37F058_MinigameParkSetup.humans == 4) {
                    D_80113780_37EE80_MinigameParkSetup = 5;
                } else {
                    D_80113780_37EE80_MinigameParkSetup++;
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 2:
            if (func_80107644_372D44_MinigameParkSetup(4) != 0) {
                D_80113780_37EE80_MinigameParkSetup = 5;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 5:
            func_80110350_37BA50_MinigameParkSetup(0x71);
            if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                    D_80113804_37EF04_MinigameParkSetup[i] = -1;
                }
                func_80110350_37BA50_MinigameParkSetup(0x72);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    if (D_80113958_37F058_MinigameParkSetup.humans == 4) {
                        D_80113780_37EE80_MinigameParkSetup = 1;
                    } else {
                        D_80113780_37EE80_MinigameParkSetup = 2;
                    }
                    D_80113782_37EE82_MinigameParkSetup = 1;
                } else {
                    func_8010E460_379B60_MinigameParkSetup();
                }
            } else {
                for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                    D_80113804_37EF04_MinigameParkSetup[i] = -1;
                }
                PlaySound(0x125);
                func_8010F0A4_37A7A4_MinigameParkSetup();
            }
            break;
        }
        HuPrcVSleep();
    }
}

/* Mode 2's setup steps: a choice first (8010B6E8, kept in D_80113816), then players,
   characters, CPU levels and handicaps. */
#ifdef NON_MATCHING
/* masked 2: case 7's "humans == 4" branch is laid out inverted (retail cross-jumps the
   "= 2" path, this C the "= 1" path); everything else matches. */
void func_801033E0_36EAE0_MinigameParkSetup(void) {
    s16 i;
    s16 ret;
    s16 n;

    func_80110350_37BA50_MinigameParkSetup(0x687);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_80111750_37CE50_MinigameParkSetup(5);
    D_80113780_37EE80_MinigameParkSetup = 6;
    while (1) {
        switch (D_80113780_37EE80_MinigameParkSetup) {
        case 6:
            func_80110350_37BA50_MinigameParkSetup(0x68A);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_8010B6E8_376DE8_MinigameParkSetup() != 0) {
                func_80110350_37BA50_MinigameParkSetup(D_80113816_37EF16_MinigameParkSetup + 0x691);
                if (func_801103A4_37BAA4_MinigameParkSetup() == 0) {
                    func_80110350_37BA50_MinigameParkSetup(0x694);
                    func_801103A4_37BAA4_MinigameParkSetup();
                    D_80113780_37EE80_MinigameParkSetup = 0;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                } else {
                    D_80113782_37EE82_MinigameParkSetup = 1;
                }
            } else {
                func_80110350_37BA50_MinigameParkSetup(0x68B);
                if (func_801103A4_37BAA4_MinigameParkSetup() == 0) {
                    func_8010ED54_37A454_MinigameParkSetup();
                } else {
                    D_80113780_37EE80_MinigameParkSetup = 6;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                }
            }
            break;
        case 0:
            func_80110350_37BA50_MinigameParkSetup(0x54);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80103F38_36F638_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup = 6;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 1:
            func_80110350_37BA50_MinigameParkSetup(0x59);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_801052B4_3709B4_MinigameParkSetup() != 0) {
                if (D_80113958_37F058_MinigameParkSetup.cpus == 0) {
                    if (D_80113816_37EF16_MinigameParkSetup == 1) {
                        D_80113780_37EE80_MinigameParkSetup = 7;
                    } else {
                        D_80113780_37EE80_MinigameParkSetup = 5;
                    }
                } else {
                    D_80113780_37EE80_MinigameParkSetup++;
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 2:
            n = 4;
            if (D_80113816_37EF16_MinigameParkSetup == 1) {
                n = 3;
            }
            if (func_80107644_372D44_MinigameParkSetup(n) != 0) {
                if (D_80113816_37EF16_MinigameParkSetup == 1) {
                    D_80113780_37EE80_MinigameParkSetup = 7;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                } else {
                    D_80113780_37EE80_MinigameParkSetup = 5;
                }
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 7:
            func_80110350_37BA50_MinigameParkSetup(0x695);
            ret = func_8011042C_37BB2C_MinigameParkSetup();
            if (ret == 0) {
                if (func_8010C6C8_377DC8_MinigameParkSetup() == 0) {
                    D_80113780_37EE80_MinigameParkSetup = 7;
                    D_80113782_37EE82_MinigameParkSetup = 1;
                    break;
                }
            } else {
                for (i = 0; i < 4; i++) {
                    D_80113958_37F058_MinigameParkSetup.handicap[i] = 0;
                }
                for (i = 0; i < 4; i++) {
                    D_8011380C_37EF0C_MinigameParkSetup[i] = -1;
                }
                if (ret == -1) {
                    if (D_80113958_37F058_MinigameParkSetup.humans == 4) {
                        D_80113780_37EE80_MinigameParkSetup = 1;
                    } else {
                        D_80113780_37EE80_MinigameParkSetup = 2;
                    }
                    D_80113782_37EE82_MinigameParkSetup = 1;
                    break;
                }
            }
            D_80113780_37EE80_MinigameParkSetup = 3;
            D_80113782_37EE82_MinigameParkSetup = 0;
            break;
        case 3:
            func_80110350_37BA50_MinigameParkSetup(0x69);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (D_80113782_37EE82_MinigameParkSetup != 0) {
                HuPrcSleep(15);
            }
            if (func_80109478_374B78_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup = 5;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup = 7;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 5:
            func_80110350_37BA50_MinigameParkSetup(0x71);
            if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                if (D_80113816_37EF16_MinigameParkSetup != 1) {
                    for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                        D_80113804_37EF04_MinigameParkSetup[i] = -1;
                    }
                }
                func_80110350_37BA50_MinigameParkSetup(0x72);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    if (D_80113816_37EF16_MinigameParkSetup == 1) {
                        D_80113780_37EE80_MinigameParkSetup = 3;
                    } else if (D_80113958_37F058_MinigameParkSetup.cpus != 0) {
                        D_80113780_37EE80_MinigameParkSetup = 2;
                    } else {
                        D_80113780_37EE80_MinigameParkSetup = 1;
                    }
                    D_80113782_37EE82_MinigameParkSetup = 1;
                } else {
                    if (D_80113816_37EF16_MinigameParkSetup == 1) {
                        for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                            D_80113804_37EF04_MinigameParkSetup[i] = -1;
                        }
                        for (i = 0; i < 4; i++) {
                            D_8011380C_37EF0C_MinigameParkSetup[i] = -1;
                        }
                        func_8010A02C_37572C_MinigameParkSetup(0);
                        if (D_80113816_37EF16_MinigameParkSetup == 1) {
                            func_8010C4B4_377BB4_MinigameParkSetup(0);
                        }
                    }
                    func_8010E460_379B60_MinigameParkSetup();
                }
            } else {
                for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                    D_80113804_37EF04_MinigameParkSetup[i] = -1;
                }
                for (i = 0; i < 4; i++) {
                    D_8011380C_37EF0C_MinigameParkSetup[i] = -1;
                }
                PlaySound(0x125);
                if (D_80113816_37EF16_MinigameParkSetup == 1) {
                    func_8010A02C_37572C_MinigameParkSetup(1);
                }
                func_8010C4B4_377BB4_MinigameParkSetup(1);
                func_8010F0A4_37A7A4_MinigameParkSetup();
            }
            break;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801033E0_36EAE0_MinigameParkSetup);
#endif

/* The board-8 introduction pages before the setup (B on a page asks to skip). */
void func_8010395C_36F05C_MinigameParkSetup(void) {
    TextWindow* win = func_80089674_8A274(D_80113818_37EF18_MinigameParkSetup);

    func_80110350_37BA50_MinigameParkSetup(0x96);
    func_801103A4_37BAA4_MinigameParkSetup();
    if (win->unkA8 & 0x4000) {
        func_80103A88_36F188_MinigameParkSetup();
    }
    func_80110350_37BA50_MinigameParkSetup(0x97);
    func_801103A4_37BAA4_MinigameParkSetup();
    if (win->unkA8 & 0x4000) {
        func_80103A88_36F188_MinigameParkSetup();
    }
    func_80110350_37BA50_MinigameParkSetup(0x98);
    func_801103A4_37BAA4_MinigameParkSetup();
    if (win->unkA8 & 0x4000) {
        func_80103A88_36F188_MinigameParkSetup();
    }
    func_80110350_37BA50_MinigameParkSetup(0x99);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_801074CC_372BCC_MinigameParkSetup(0, 50.0f, 0.0f, 70.0f);
    HuPrcSleep(3);
    func_801074CC_372BCC_MinigameParkSetup(4, 0.0f, 0.0f, -70.0f);
    HuPrcSleep(3);
    func_801074CC_372BCC_MinigameParkSetup(1, -100.0f, 0.0f, -210.0f);
    HuPrcSleep(3);
    func_801074CC_372BCC_MinigameParkSetup(2, -150.0f, 0.0f, -350.0f);
    HuPrcSleep(10);
    func_8010F0A4_37A7A4_MinigameParkSetup();
}

/* Ask whether to quit (message 0x53); yes leaves the setup. */
void func_80103A88_36F188_MinigameParkSetup(void) {
    func_80110350_37BA50_MinigameParkSetup(0x53);
    if (func_801103A4_37BAA4_MinigameParkSetup() == 0) {
        func_8010ED54_37A454_MinigameParkSetup();
    }
}

/* Mode 3's setup steps: continue from the save (D_800FD420) or the story record
   (D_800FD8A8), or start one player against one CPU. */
#ifdef NON_MATCHING
/* masked 46 (403 vs 395 instructions): retail shares more of the step/flag store tails
   between cases 8, 9 and 1 (cross-jumping), and keeps `saved` in v1 until the loop. Logic
   checked against the asm. */
void func_80103ABC_36F1BC_MinigameParkSetup(void) {
    s32 saved;
    s16 ret;

    func_80110350_37BA50_MinigameParkSetup(0x58C);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_80111750_37CE50_MinigameParkSetup(5);
    D_80113958_37F058_MinigameParkSetup.humans = 1;
    D_80113958_37F058_MinigameParkSetup.cpuLevel[0] = 0xFF;
    D_80113958_37F058_MinigameParkSetup.cpus = 1;
    D_80113958_37F058_MinigameParkSetup.cpuLevel[1] = 0;
    if (func_80075390_75F90(0) != 0 || func_80075478_76078(0) != 0) {
        saved = 1;
        D_80113780_37EE80_MinigameParkSetup = 8;
    } else {
        saved = 0;
        D_80113780_37EE80_MinigameParkSetup = 1;
    }
    D_80113816_37EF16_MinigameParkSetup = 2;
    while (1) {
        switch (D_80113780_37EE80_MinigameParkSetup) {
        case 8:
            D_80113824_37EF24_MinigameParkSetup = 8;
            D_8011382D_37EF2D_MinigameParkSetup = -1;
            func_80110350_37BA50_MinigameParkSetup(0x58E);
            ret = func_801103A4_37BAA4_MinigameParkSetup();
            if (ret == -1) {
                D_80113780_37EE80_MinigameParkSetup = 9;
                D_80113782_37EE82_MinigameParkSetup = 1;
            } else {
                if (ret == 1) {
                    func_80075424_76024(4);
                    func_8007550C_7610C(4);
                    func_80110350_37BA50_MinigameParkSetup(0x591);
                    func_801103A4_37BAA4_MinigameParkSetup();
                    D_80113780_37EE80_MinigameParkSetup = 1;
                } else {
                    if (func_80075478_76078(0) != 0 && func_80075390_75F90(0) != 0) {
                        func_80110350_37BA50_MinigameParkSetup(0x58F);
                        ret = func_801103A4_37BAA4_MinigameParkSetup();
                    } else {
                        ret = func_80075390_75F90(0) != 0;
                    }
                    if (ret == -1) {
                        D_80113780_37EE80_MinigameParkSetup = 8;
                    } else {
                        if (ret == 1) {
                            D_8011382D_37EF2D_MinigameParkSetup = 1;
                            D_80113826_37EF26_MinigameParkSetup.chapter = D_800FD8A8_FE4A8.unk10;
                            D_80113826_37EF26_MinigameParkSetup.character[0] = D_800FD8A8_FE4A8.unk00;
                            D_80113826_37EF26_MinigameParkSetup.character[1] = D_800FD8A8_FE4A8.unk01;
                            D_80113826_37EF26_MinigameParkSetup.unk3 = D_800FD8A8_FE4A8.unk02[1];
                            D_80113826_37EF26_MinigameParkSetup.unk4 = D_800FD8A8_FE4A8.unk05[8];
                            D_80113826_37EF26_MinigameParkSetup.unk5 = D_800FD8A8_FE4A8.unk04;
                            D_80113826_37EF26_MinigameParkSetup.step = D_800FD8A8_FE4A8.unk11;
                        } else {
                            D_8011382D_37EF2D_MinigameParkSetup = 0;
                            D_80113826_37EF26_MinigameParkSetup.chapter = D_800FD420_FE020[0x10];
                            D_80113826_37EF26_MinigameParkSetup.character[0] = D_800FD420_FE020[0x00];
                            D_80113826_37EF26_MinigameParkSetup.character[1] = D_800FD420_FE020[0x01];
                            D_80113826_37EF26_MinigameParkSetup.unk3 = D_800FD420_FE020[0x03];
                            D_80113826_37EF26_MinigameParkSetup.unk4 = D_800FD420_FE020[0x0D];
                            D_80113826_37EF26_MinigameParkSetup.unk5 = D_800FD420_FE020[0x04];
                            D_80113826_37EF26_MinigameParkSetup.step = D_800FD420_FE020[0x11];
                        }
                        D_80113958_37F058_MinigameParkSetup.character[0] = D_80113826_37EF26_MinigameParkSetup.character[0];
                        D_80113958_37F058_MinigameParkSetup.character[1] = D_80113826_37EF26_MinigameParkSetup.character[1];
                        func_80075424_76024(4);
                        func_8007550C_7610C(4);
                        if (func_8010D260_378960_MinigameParkSetup() != 0) {
                            if (D_8011382D_37EF2D_MinigameParkSetup == 1) {
                                func_800753D4_75FD4(4);
                            } else {
                                func_800754BC_760BC(4);
                            }
                            D_80113780_37EE80_MinigameParkSetup = 5;
                        } else {
                            D_80113780_37EE80_MinigameParkSetup = 8;
                        }
                    }
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            }
            break;
        case 9:
            func_80110350_37BA50_MinigameParkSetup(0x58D);
            if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                if (saved == 0) {
                    D_80113780_37EE80_MinigameParkSetup = 1;
                } else {
                    D_80113780_37EE80_MinigameParkSetup = 8;
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                func_8010ED54_37A454_MinigameParkSetup();
            }
            break;
        case 1:
            D_80113824_37EF24_MinigameParkSetup = 1;
            D_8011382D_37EF2D_MinigameParkSetup = -1;
            func_80110350_37BA50_MinigameParkSetup(0x59);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_801052B4_3709B4_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup = 5;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                if (saved != 0) {
                    D_80113780_37EE80_MinigameParkSetup = 8;
                } else {
                    D_80113780_37EE80_MinigameParkSetup = 9;
                }
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 5:
            func_80110350_37BA50_MinigameParkSetup(0x71);
            if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                func_80110350_37BA50_MinigameParkSetup(0x72);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[0], 0.0f, 0.0f, -600.0f);
                    func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[1], 0.0f, 0.0f, -600.0f);
                    D_80113780_37EE80_MinigameParkSetup = D_80113824_37EF24_MinigameParkSetup;
                    D_80113782_37EE82_MinigameParkSetup = 1;
                } else {
                    func_8010E460_379B60_MinigameParkSetup();
                }
            } else {
                if (D_8011382D_37EF2D_MinigameParkSetup == -1) {
                    D_800FD8A8_FE4A8.unk00 = D_80113958_37F058_MinigameParkSetup.character[0];
                    D_800FD8A8_FE4A8.unk01 = D_80113958_37F058_MinigameParkSetup.character[1];
                }
                PlaySound(0x125);
                func_8010F0A4_37A7A4_MinigameParkSetup();
            }
            break;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103ABC_36F1BC_MinigameParkSetup);
#endif




__asm__(".section .rodata");
const Ovl58Quad D_80113618_37ED18_MinigameParkSetup = { { 2, 0, 3, 1 } };

__asm__(".section .rodata");
const Ovl58Quad D_80113620_37ED20_MinigameParkSetup = { { 0, 1, 2, 3 } };

__asm__(".section .rodata");
const char D_80113628_37ED28_MinigameParkSetup[] = "p_panel";

#ifdef NON_MATCHING
/* masked 146 (1351 vs 1363 lines): D_801138E0's copy goes through a stack temporary in
   retail (lhu/sh, then lwl/lwr); maxPlayers' spill and the s-register choice of the panel
   loops differ. Logic checked against the asm. */
/* Player count: the four models lift their number panels in, the stick picks a panel
   (1-4 players, 1-2 in mode 3), A takes it (players > count become CPUs), B backs out.
   Returns 1 on A, 0 on B. */
s32 func_80103F38_36F638_MinigameParkSetup(void) {
    Ovl58Quad models;
    Ovl58Quad delayIn;
    Ovl58Quad delayOut;
    s16 done[4];
    s16 panel[4];
    s16 icon[16];
    Vec base[4];
    Vec pos[4];
    s16 sprPanel;
    s16 result;
    s16 maxPlayers;
    s16 sprA;
    s16 sprB;
    s16 i;
    s16 j;
    s16 frame;
    s16 sel;
    s16 n;
    f32 dir;
    f32 t;

    models = D_801138E0_37EFE0_MinigameParkSetup;
    delayIn = D_80113618_37ED18_MinigameParkSetup;
    delayOut = D_80113620_37ED20_MinigameParkSetup;
    n = D_80113958_37F058_MinigameParkSetup.padCount;
    maxPlayers = 4;
    if (D_80113816_37EF16_MinigameParkSetup == 2) {
        if (n >= 3) {
            n = 2;
        }
        maxPlayers = 2;
    }
    for (i = 0; i < n; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 0);
        if (D_80113782_37EE82_MinigameParkSetup == 0) {
            func_8002C9C0_2D5C0(models.v[i], D_801139A8_37F0A8_MinigameParkSetup);
        } else {
            func_8002C9C0_2D5C0(models.v[i], D_801139AA_37F0AA_MinigameParkSetup);
        }
        func_80029C74_2A874(models.v[i], 30.0f);
        func_80029E80_2AA80(models.v[i], 1, 1);
        func_80029760_2A360(models.v[i], &base[i]);
        pos[i] = base[i];
        pos[i].z += 1200.0f;
        func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
        done[i] = 0;
    }
    sprA = func_8001A2F8_1AEF8(0x90082);
    sprB = func_8001A2F8_1AEF8(0x90083);
    sprPanel = func_8001A2F8_1AEF8(0x90081);
    HuPrcVSleep();
    for (i = 0; i < n; i++) {
        panel[i] = func_8001AAAC_1B6AC(sprPanel, 0, 1);
        func_8001A6BC_1B2BC(panel[i], 0x100);
        espPosSet(panel[i], -100, -100);
        for (j = 0; j < 4; j++) {
            if (D_801133A4_37EAA4_MinigameParkSetup[i * 4 + j] == 0) {
                icon[i * 4 + j] = func_8001AAAC_1B6AC(sprA, 0, 1);
            } else {
                icon[i * 4 + j] = func_8001AAAC_1B6AC(sprB, 0, 1);
            }
            func_8001A6BC_1B2BC(icon[i * 4 + j], 0x100);
            espPosSet(icon[i * 4 + j], -100, -100);
            func_8001A7C8_1B3C8(icon[i * 4 + j], 0.5f);
        }
    }
    /* Lift the models in (or back from below after B on the next step). */
    dir = -1.0f;
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        dir = 1.0f;
    }
    frame = 0;
    while (1) {
        for (i = 0; i < n; i++) {
            if (dir > 0.0f) {
                t = frame - delayIn.v[i] * 10;
            } else {
                t = frame - delayOut.v[i] * 10;
            }
            if (t == 0.0f) {
                PlaySound(0xAB);
            }
            if ((t > 0.0f) & (t <= 20.0f)) {
                pos[i].z = (1.0f - HuMathSin(t * 4.5f)) * 1200.0f * dir + base[i].z;
                if (t == 15.0f) {
                    func_80029E80_2AA80(models.v[i], 1, 0);
                    func_80029FE4_2ABE4(models.v[i], 1.5f);
                }
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
            } else if ((done[i] == 0) & (t > 20.0f)) {
                if (func_80029E14_2AA14(models.v[i]) != D_801139A0_37F0A0_MinigameParkSetup) {
                    if (func_80029D0C_2A90C(models.v[i]) <= func_80029CE4_2A8E4(models.v[i])) {
                        func_8002C9C0_2D5C0(models.v[i], D_801139A0_37F0A0_MinigameParkSetup);
                        PlaySound(0xB1);
                    }
                } else if (func_80029CE4_2A8E4(models.v[i]) > 30.0f) {
                    func_80029E80_2AA80(models.v[i], 1, 1);
                    done[i] = 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            func_801104FC_37BBFC_MinigameParkSetup(models.v[i], panel[i], D_80113628_37ED28_MinigameParkSetup);
            for (j = 0; j < 4; j++) {
                func_801051BC_3708BC_MinigameParkSetup(icon[i * 4 + j], i * 4 + j, maxPlayers);
            }
            func_801105B8_37BCB8_MinigameParkSetup(i, panel[i], 10, 20);
        }
        for (i = 0; i < n; i++) {
            if (done[i] == 0) {
                break;
            }
        }
        if (i == n) {
            break;
        }
        frame++;
        HuPrcVSleep();
    }
    /* Pick the count. */
    func_80107604_372D04_MinigameParkSetup();
    D_8011393C_37F03C_MinigameParkSetup = 0;
    func_8011170C_37CE0C_MinigameParkSetup(0);
    D_8011392C_37F02C_MinigameParkSetup = 1;
    HuPrcSleep(5);
    func_80110350_37BA50_MinigameParkSetup(maxPlayers == 4 ? 0x55 : 0x69F);
    func_801103A4_37BAA4_MinigameParkSetup();
    for (j = 0; j < 4; j++) {
        func_8001A7C8_1B3C8(icon[j], 2.0f);
    }
    while (1) {
        if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
            || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
            sel = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, n, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
            if (sel != -1) {
                PlaySound(1);
                func_8011175C_37CE5C_MinigameParkSetup(sel);
                for (j = 0; j < 4; j++) {
                    func_8001A7C8_1B3C8(icon[D_8011393C_37F03C_MinigameParkSetup * 4 + j], 0.5f);
                }
                HuPrcSleep(6);
                D_8011393C_37F03C_MinigameParkSetup = sel;
                for (j = 0; j < 4; j++) {
                    func_8001A7C8_1B3C8(icon[D_8011393C_37F03C_MinigameParkSetup * 4 + j], 2.0f);
                }
                if (maxPlayers == 4) {
                    func_80110350_37BA50_MinigameParkSetup(sel + 0x55);
                } else {
                    func_80110350_37BA50_MinigameParkSetup(sel + 0x69F);
                }
                func_801103A4_37BAA4_MinigameParkSetup();
            }
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x4000) {
            PlaySound(4);
            result = 0;
            sel = -1;
            break;
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x8000) {
            PlaySound(2);
            result = 1;
            sel = D_8011393C_37F03C_MinigameParkSetup;
            for (i = 0; i <= sel; i++) {
                func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[i], 2, 3, 10);
            }
            break;
        }
        HuPrcVSleep();
    }
    D_8011392C_37F02C_MinigameParkSetup = 0;
    PlaySound(0xB1);
    for (i = 0; i < n; i++) {
        if (sel != i) {
            func_80029E80_2AA80(models.v[i], 1, 0);
        }
        func_80029FE4_2ABE4(models.v[i], 2.0f);
        done[i] = 0;
    }
    if (result != 0) {
        /* The chosen model jumps; all sink away. */
        for (frame = 0; frame < 30; frame++) {
            if (frame == 15) {
                PlaySound(0xB1);
                func_80029E80_2AA80(models.v[sel], 1, 0);
            }
            for (i = 0; i < n; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], panel[i], D_80113628_37ED28_MinigameParkSetup);
                for (j = 0; j < 4; j++) {
                    func_801051BC_3708BC_MinigameParkSetup(icon[i * 4 + j], i * 4 + j, maxPlayers);
                }
            }
            HuPrcVSleep();
        }
        for (i = 0; i < n; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139A8_37F0A8_MinigameParkSetup);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 1; frame < 10; frame++) {
            for (i = 0; i < n; i++) {
                D_800FC834_FD434[models.v[i]].pos.z = base[i].z - frame * 100;
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], panel[i], D_80113628_37ED28_MinigameParkSetup);
                for (j = 0; j < 4; j++) {
                    func_801051BC_3708BC_MinigameParkSetup(icon[i * 4 + j], i * 4 + j, maxPlayers);
                }
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            if (sel >= i) {
                D_80113958_37F058_MinigameParkSetup.cpuLevel[i] = 0xFF;
            } else {
                D_80113958_37F058_MinigameParkSetup.cpuLevel[i] = 0;
            }
        }
        D_80113958_37F058_MinigameParkSetup.humans = sel + 1;
        D_80113958_37F058_MinigameParkSetup.cpus = maxPlayers - (sel + 1);
    } else {
        PlaySound(0xB1);
        for (frame = 0; frame < 15; frame++) {
            for (i = 0; i < n; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], panel[i], D_80113628_37ED28_MinigameParkSetup);
                for (j = 0; j < 4; j++) {
                    func_801051BC_3708BC_MinigameParkSetup(icon[i * 4 + j], i * 4 + j, maxPlayers);
                }
            }
            HuPrcVSleep();
        }
        for (i = 0; i < n; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139AA_37F0AA_MinigameParkSetup);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 1; frame < 11; frame++) {
            for (i = 0; i < n; i++) {
                D_800FC834_FD434[models.v[i]].pos.z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 1200.0f + base[i].z;
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], panel[i], D_80113628_37ED28_MinigameParkSetup);
                for (j = 0; j < 4; j++) {
                    func_801051BC_3708BC_MinigameParkSetup(icon[i * 4 + j], i * 4 + j, maxPlayers);
                }
            }
            HuPrcVSleep();
        }
    }
    for (i = 0; i < n; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 4);
        func_8001AC44_1B844(panel[i]);
        for (j = 0; j < 4; j++) {
            func_8001AC44_1B844(icon[i * 4 + j]);
        }
    }
    SprAnimKill(sprPanel);
    SprAnimKill(sprA);
    SprAnimKill(sprB);
    for (i = 0; i < 4; i++) {
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 24, models.v[i]);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103F38_36F638_MinigameParkSetup);
#endif

/* Place sprite `sprite` at panel slot `slot` (D_801133B4, around D_801137B0). With
   mode 2, the slot moves to the second table half and odd pairs are hidden. */
void func_801051BC_3708BC_MinigameParkSetup(s16 sprite, s16 slot, s16 mode) {
    if (mode == 2) {
        slot += 16;
        if (slot & 2) {
            espDispOff(sprite);
        }
    }
    espPosSet(sprite, D_801133B4_37EAB4_MinigameParkSetup[slot][0] + D_801137B0_37EEB0_MinigameParkSetup[0] - 32.0f,
              D_801133B4_37EAB4_MinigameParkSetup[slot][1] + D_801137B0_37EEB0_MinigameParkSetup[1] - 4.0f);
}


__asm__(".section .rodata");
const char D_80113630_37ED30_MinigameParkSetup[] = "c_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801052B4_3709B4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106A00_372100_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106AB4_3721B4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106AF8_3721F8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107014_372714_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107030_372730_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070B0_3727B0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070E0_3727E0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070FC_3727FC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107118_372818_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107134_372834_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107180_372880_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801074CC_372BCC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801075C8_372CC8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107604_372D04_MinigameParkSetup);










__asm__(".section .rodata");
const u32 D_80113638_37ED38_MinigameParkSetup[9] = { 0xC2700000, 0x42C30000, 0x41F00000, 0xC2700000, 0x42C30000, 0xC1A00000, 0xC2700000, 0x42C30000, 0xC28C0000 };

__asm__(".section .rodata");
const u32 D_8011365C_37ED5C_MinigameParkSetup[12] = { 0xC2700000, 0x42C30000, 0x428C0000, 0xC2700000, 0x42C30000, 0x41B80000, 0xC2700000, 0x42C30000, 0xC1B80000, 0xC2700000, 0x42C30000, 0xC28C0000 };

__asm__(".section .rodata");
const u32 D_8011368C_37ED8C_MinigameParkSetup[1] = { 0x18000000 };

__asm__(".section .rodata");
const char D_80113690_37ED90_MinigameParkSetup[] = "cl_panel";

__asm__(".section .rodata");
const char D_8011369C_37ED9C_MinigameParkSetup[] = "time30";

__asm__(".section .rodata");
const char D_801136A4_37EDA4_MinigameParkSetup[] = "time10";

__asm__(".section .rodata");
const char D_801136AC_37EDAC_MinigameParkSetup[] = "time50";

__asm__(".section .rodata");
const char D_801136B4_37EDB4_MinigameParkSetup[] = "time35";

__asm__(".section .rodata");
const char D_801136BC_37EDBC_MinigameParkSetup[] = "time20";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107644_372D44_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80108BA8_3742A8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80108C0C_37430C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010903C_37473C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80109478_374B78_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010A02C_37572C_MinigameParkSetup);


__asm__(".section .rodata");
const char D_801136E8_37EDE8_MinigameParkSetup[] = "bns_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010A1E8_3758E8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6B4_376DB4_MinigameParkSetup);


__asm__(".section .rodata");
const char D_801136F4_37EDF4_MinigameParkSetup[] = "mode_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6E8_376DE8_MinigameParkSetup);

/* Slides the chosen mode panel (D_80113816) out along z, away (dir 0) or towards the camera,
   then hides it and its two sprites. */
void func_8010C4B4_377BB4_MinigameParkSetup(s16 dir) {
    s16 models[3] = { D_80113908_37F008_MinigameParkSetup[0], D_80113908_37F008_MinigameParkSetup[1],
                         D_80113908_37F008_MinigameParkSetup[2] };
    Vec start;
    Vec pos;
    f32 sign;
    s16 i;

    func_80029760_2A360(models[D_80113816_37EF16_MinigameParkSetup], &pos);
    start = pos;
    if (dir != 0) {
        sign = -1.0f;
    } else {
        sign = 1.0f;
    }
    for (i = 0; i < 16; i++) {
        pos.z = (1.0f - func_800B7890_B8490(i * 6.0f)) * (sign * 1200.0f - start.z) + start.z;
        func_80029714_2A314(models[D_80113816_37EF16_MinigameParkSetup], pos.x, pos.y, pos.z);
        func_801104FC_37BBFC_MinigameParkSetup(models[D_80113816_37EF16_MinigameParkSetup],
                                               D_8011383E_37EF3E_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup],
                                               D_801136F4_37EDF4_MinigameParkSetup);
        func_80108BA8_3742A8_MinigameParkSetup(D_8011384A_37EF4A_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup]);
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(models[D_80113816_37EF16_MinigameParkSetup], 4, 4);
    espDispOff(D_8011383E_37EF3E_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup]);
    espDispOff(D_8011384A_37EF4A_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010C6C8_377DC8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010D260_378960_MinigameParkSetup);

__asm__(".section .rodata");
const char D_8011370C_37EE0C_MinigameParkSetup[] = "%2d";


/* Places record panel window i beside the panel (win is unused: retail reloads it). */
void func_8010E1F0_3798F0_MinigameParkSetup(s16 win, s16 i) {
    func_800896DC_8A2DC(D_80113850_37EF50_MinigameParkSetup[i],
                        D_80113554_37EC54_MinigameParkSetup[i].x + D_801137B0_37EEB0_MinigameParkSetup[0] - 68.0f,
                        D_80113554_37EC54_MinigameParkSetup[i].y + D_801137B0_37EEB0_MinigameParkSetup[1] - 3.0f);
}

/* Commits the setup: game length, bonus flag 0x4E, and per player the CPU flag and level,
   pad port, character and starting coins. */
void func_8010E2B8_3799B8_MinigameParkSetup(void) {
    Ovl58Quad levels = D_80113620_37ED20_MinigameParkSetup;
    s16 i;

    GwSystem.current_game_length = D_80113958_37F058_MinigameParkSetup.gameLength;
    if (D_80113958_37F058_MinigameParkSetup.bonus != 0) {
        _SetFlag(0x4E);
    } else {
        _ClearFlag(0x4E);
    }
    for (i = 0; i < 4; i++) {
        if (i < D_80113958_37F058_MinigameParkSetup.humans) {
            gPlayers[i].cpu_difficulty2 = 1;
            gPlayers[i].flags = 0;
        } else {
            gPlayers[i].cpu_difficulty2 = levels.v[D_80113958_37F058_MinigameParkSetup.cpuLevel[i]];
            gPlayers[i].flags = 1;
        }
        gPlayers[i].port = D_80113958_37F058_MinigameParkSetup.port[i];
        gPlayers[i].character = D_80113958_37F058_MinigameParkSetup.character[i];
        gPlayers[i].coins = D_80113958_37F058_MinigameParkSetup.handicap[i];
    }
    *(s16*)&D_800FD390_FDF90[6] = 1;
}



/* Everyone falls: the mode panel goes, the screen shakes and the pads rumble, the four
   character models (and model D_801138C0[0]) jump and drop away one by one at random delays,
   the music slows, then a white fade and the setup restarts: overlay 0x58 again, event = the
   mode, stat 0x1000. */
void func_8010E460_379B60_MinigameParkSetup(void) {
    s16 models[5];
    s16 delay[5];
    Vec pos[5];
    Vec cam;
    f32 jump[5];
    f32 speed[5];
    f32 fall[5];
    s16 shake[4][2] = { { 5, 10 }, { -5, 2 }, { 8, -5 }, { -2, -1 } };
    f32 f;
    f32 t;
    s32 frame;
    s16 i;
    s16 j;
    s16 k;

    D_80113788_37EE88_MinigameParkSetup = 1;
    frame = 0;
    if (D_80113816_37EF16_MinigameParkSetup == -1) {
        HuPrcSleep(10);
    } else {
        func_8010C4B4_377BB4_MinigameParkSetup(0);
    }
    PlaySound(0xBB);
    cam = D_8010274C_10334C;
    for (i = 0; i < 20; i++) {
        if ((i & 7) == 0) {
            for (k = 0; k < D_80113958_37F058_MinigameParkSetup.humans; k++) {
                func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[k], 5, 0, 5);
            }
        }
        f = i * 0.1f;
        if (f > 1.0f) {
            f = 1.0f;
        }
        D_8010274C_10334C.y = shake[frame & 3][0] * f + cam.y;
        D_8010274C_10334C.z = shake[frame & 3][1] * f + cam.z;
        frame++;
        HuPrcVSleep();
    }
    D_8010274C_10334C = cam;
    for (i = 0; i < 5; i++) {
        if (i != 4) {
            /* D_801138C8: one 4-byte slot per character, the model in its first s16 */
            models[i] = ((u16*)D_801138C8_37EFC8_MinigameParkSetup)[D_80113958_37F058_MinigameParkSetup.character[i] * 2];
        } else {
            models[i] = D_801138C0_37EFC0_MinigameParkSetup[0];
        }
        func_80029760_2A360(models[i], &pos[i]);
        jump[i] = rand8() + 200;
        speed[i] = rand8() / 40.0f + (i + 1) * 3;
        delay[i] = (rand8() & 7) + 45;
        fall[i] = -5.0f;
    }
    for (j = 0; j < 90; j++) {
        if ((j & 15) == 0) {
            for (k = 0; k < D_80113958_37F058_MinigameParkSetup.humans; k++) {
                func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[k], 10, 0, 10);
            }
        }
        if (j < 81) {
            D_800FD478_FE078.y = j * -1.125f;
        }
        D_8011378C_37EE8C_MinigameParkSetup -= 3.0f;
        if (j < 50) {
            for (i = 0; i < 4; i++) {
                if (!(pos[i].z < -500.0f)) {
                    func_801075C8_372CC8_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[i], pos[i].x,
                                                           pos[i].y, pos[i].z + speed[i]);
                    func_80029760_2A360(models[i], &pos[i]);
                }
            }
        }
        func_8007954C_7A14C((90 - j) * 0.9111111f + 100.0f);
        for (i = 0; i < 4; i++) {
            if (!(pos[i].z < -500.0f) && j >= delay[i]) {
                k = j - delay[i];
                if (k == 10) {
                    func_800795D8_7A1D8(func_8007975C_7A35C(D_80113958_37F058_MinigameParkSetup.character[i] + 0x115, i), 0x7A);
                }
                t = k;
                func_801075C8_372CC8_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[i], pos[i].x,
                                                       pos[i].y + (1.0f - func_800B7890_B8490(t * 2.25f)) * jump[i],
                                                       pos[i].z - fall[i]);
                t = t * 0.9f + fall[i];
                fall[i] = t;
            }
        }
        if (delay[4] <= j) {
            k = j - delay[4];
            if (k == 10) {
                if (GwSystem.current_board_index != 5) {
                    func_800795D8_7A1D8(PlaySound(0x124), 0x7A);
                }
            }
            t = k;
            func_80029714_2A314(models[4], pos[4].x, (1.0f - func_800B7890_B8490(t * 2.25f)) * jump[4] + pos[4].y,
                                pos[4].z - fall[4]);
            t = t * 0.9f + fall[4];
            fall[4] = t;
        }
        D_8010274C_10334C.y = shake[frame & 3][0] + cam.y;
        D_8010274C_10334C.z = shake[frame & 3][1] + cam.z;
        frame++;
        if (j == 87) {
            func_8008F624_90224(0xFF, 0xFF, 0xFF);
            InitFadeOut(0, 10);
            func_800794A8_7A0A8(60);
            func_80079614_7A214(60);
        }
        HuPrcVSleep();
    }
    for (k = 0; k < D_80113958_37F058_MinigameParkSetup.humans; k++) {
        func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[k], 10, 0, 10);
    }
    D_80112B44_37E244_MinigameParkSetup[0] = 1;
    D_8011381E_37EF1E_MinigameParkSetup = 0x58;
    D_8011381C_37EF1C_MinigameParkSetup = 1;
    D_80113820_37EF20_MinigameParkSetup = D_800CD414_CE014;
    D_80113822_37EF22_MinigameParkSetup = 0x1000;
    D_80112B42_37E242_MinigameParkSetup = 1;
    while (1) {
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
/* masked 0: retail keeps `near` in v1, this build in a1 (register allocation only). */
/* Quit: the camera pulls back past model D_801138BC, then leaves for the main menu (mode 0:
   overlay 0x5B) or 0x5C (mode 1); modes 2 and 3 keep D_8011381E/D_80113820 as they are. */
void func_8010ED54_37A454_MinigameParkSetup(void) {
    s32 played = 0;

    D_80113858_37EF58_MinigameParkSetup = D_8011378C_37EE8C_MinigameParkSetup;
    D_80113788_37EE88_MinigameParkSetup = 1;
    D_80113784_37EE84_MinigameParkSetup = 1;
    HuPrcSleep(10);
    D_80113BF4_37F2F4_MinigameParkSetup = 13000.0f;
    Hu3DCamSetPerspective(0, D_801135C0_37ECC0_MinigameParkSetup, D_80113E24_37F524_MinigameParkSetup, 13000.0f);
    func_80110B98_37C298_MinigameParkSetup(1, 20, 1, func_8010EEF8_37A5F8_MinigameParkSetup);
    while (1) {
        s32 near = 1;
        if (!(D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[5]].pos.z > -2000.0f)) {
            near = 0;
        }
        if (near & (played ^ 1)) {
            played = 1;
            PlaySound(0xBC);
        }
        if (D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[5]].pos.z > -500.0f) {
            break;
        }
        HuPrcVSleep();
    }
    D_8011381C_37EF1C_MinigameParkSetup = 0;
    if (D_800CD414_CE014 == 0) {
        D_8011381E_37EF1E_MinigameParkSetup = 0x5B;
        D_80113820_37EF20_MinigameParkSetup = 0;
    } else if (D_800CD414_CE014 == 1) {
        D_8011381E_37EF1E_MinigameParkSetup = 0x5C;
        D_80113820_37EF20_MinigameParkSetup = 0;
    }
    func_800794A8_7A0A8(60);
    func_8010EF58_37A658_MinigameParkSetup();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010ED54_37A454_MinigameParkSetup);
#endif

/* Camera tween callback (80110B98): sway amplitude = sin(180 * time[0] / time[1]) * start. */
void func_8010EEF8_37A5F8_MinigameParkSetup(s16* time) {
    D_8011378C_37EE8C_MinigameParkSetup = func_800B7890_B8490(180.0f / time[1] * time[0]) * D_80113858_37EF58_MinigameParkSetup;
}

/* Fades out and stops the human pads' rumble, ends a continued mode 3 save, then sets
   D_80112B42 (leave: 80110A28) and idles. */
void func_8010EF58_37A658_MinigameParkSetup(void) {
    s16 i;

    D_80112B44_37E244_MinigameParkSetup[0] = 1;
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeOut(0, 10);
    for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
        func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[i], 2, 3, 10);
    }
    HuPrcSleep(10);
    for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
        func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[i], 2, 3, 10);
    }
    if (D_800CD414_CE014 == 3 && D_8011382D_37EF2D_MinigameParkSetup == 0) {
        func_8007E150_7ED50();
        func_800754BC_760BC(4);
    }
    D_80112B42_37E242_MinigameParkSetup = 1;
    while (1) {
        HuPrcVSleep();
    }
}

/* Done: the closing message (none at stage 7), the camera flies in to model D_801138BA, the
   setup is committed (8010E2B8) and the next overlay chosen: mode 0 board 0x3D, mode 1 0x5D
   event 3, mode 3 0x63, mode 2 by D_80113816 (0: 0x4E; 1: 0x3D with flag 0xD and board 6;
   2: 0x4E event 1). */
void func_8010F0A4_37A7A4_MinigameParkSetup(void) {
    if (D_80113814_37EF14_MinigameParkSetup != 7) {
        if (D_800CD414_CE014 == 0) {
            func_80110350_37BA50_MinigameParkSetup(0x73);
        } else if (D_800CD414_CE014 == 1) {
            func_80110350_37BA50_MinigameParkSetup(0x369);
        } else if (D_800CD414_CE014 == 3) {
            func_80110350_37BA50_MinigameParkSetup(0x594);
        } else if (D_80113816_37EF16_MinigameParkSetup == 0) {
            func_80110350_37BA50_MinigameParkSetup(0x69C);
        } else if (D_80113816_37EF16_MinigameParkSetup == 1) {
            func_80110350_37BA50_MinigameParkSetup(0x69D);
        } else if (D_80113816_37EF16_MinigameParkSetup == 2) {
            func_80110350_37BA50_MinigameParkSetup(0x69E);
        }
        func_801103A4_37BAA4_MinigameParkSetup();
        HuPrcSleep(30);
    }
    D_80113858_37EF58_MinigameParkSetup = D_8011378C_37EE8C_MinigameParkSetup;
    D_80113788_37EE88_MinigameParkSetup = 1;
    HuPrcSleep(10);
    while (1) {
        if (D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[4]].pos.z < 8000.0f) {
            break;
        }
        HuPrcVSleep();
    }
    PlaySound(0xAD);
    func_800794A8_7A0A8(120);
    func_80110B98_37C298_MinigameParkSetup(2, 30, 1, (void*)-1);
    HuPrcSleep(10);
    D_80113786_37EE86_MinigameParkSetup = 1;
    func_80110B98_37C298_MinigameParkSetup(3, 20, 2, (void*)-1);
    while (1) {
        if (D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[4]].pos.z < 500.0f) {
            break;
        }
        HuPrcVSleep();
    }
    func_8010E2B8_3799B8_MinigameParkSetup();
    D_8011381C_37EF1C_MinigameParkSetup = 1;
    if (D_800CD414_CE014 == 0) {
        D_8011381E_37EF1E_MinigameParkSetup = 0x3D;
        D_80113820_37EF20_MinigameParkSetup = 0;
    } else if (D_800CD414_CE014 == 1) {
        D_8011381E_37EF1E_MinigameParkSetup = 0x5D;
        D_80113820_37EF20_MinigameParkSetup = 3;
    } else if (D_800CD414_CE014 == 3) {
        D_8011381E_37EF1E_MinigameParkSetup = 0x63;
        D_80113820_37EF20_MinigameParkSetup = 0;
    } else {
        switch (D_80113816_37EF16_MinigameParkSetup) {
        case 0:
            D_8011381E_37EF1E_MinigameParkSetup = 0x4E;
            D_80113820_37EF20_MinigameParkSetup = 0;
            break;
        case 1:
            D_8011381E_37EF1E_MinigameParkSetup = 0x3D;
            D_80113820_37EF20_MinigameParkSetup = 0;
            _SetFlag(0xD);
            GwSystem.current_board_index = 6;
            break;
        case 2:
            D_8011381E_37EF1E_MinigameParkSetup = 0x4E;
            D_80113820_37EF20_MinigameParkSetup = 1;
            break;
        }
    }
    func_8010EF58_37A658_MinigameParkSetup();
}

#ifdef NON_MATCHING
/* masked 9: in the fade loop retail loads D_801138C0[i] twice (lhu for the call, lh for the
   index); this build loads it once. Logic checked against the asm. */
/* The tunnel process: seven segment models scroll along z by D_8011378C a frame, wrapping
   between -3000 and 5000; once quit (D_80113784, when the scroll has stopped) or done
   (D_80113786) is set they snap into place on a 2000 grid, once. Model D_801138C0[0] fades
   with its distance to the segment seams. */
void func_8010F358_37AA58_MinigameParkSetup(void) {
    f32 z[8];
    s32 snapped = 0;
    s32 hit1, hit2, hit3, hit4;
    f32 d;
    s16 i;

    z[0] = -3000.0f;
    z[1] = -1000.0f;
    z[2] = 1000.0f;
    z[3] = 3000.0f;
    z[4] = 3000.0f;
    z[5] = 0.0f;
    z[6] = 0.0f;
    func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[4], 4, 4);
    func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[5], 4, 4);
    D_8011378C_37EE8C_MinigameParkSetup = 120.0f;
    while (1) {
        for (i = 0; i < 7; i++) {
            u16 model = D_801138B2_37EFB2_MinigameParkSetup[i];
            f32* pos = D_80112BF4_37E2F4_MinigameParkSetup[i];

            z[i] -= D_8011378C_37EE8C_MinigameParkSetup;
            hit1 = 1;
            if (!(z[i] < -3000.0f)) {
                hit1 = 0;
            }
            if (hit1 & (snapped ^ 1)) {
                z[i] += 8000.0f;
            }
            hit2 = 1;
            if (!(z[i] > 5000.0f)) {
                hit2 = 0;
            }
            if (hit2 & (snapped ^ 1)) {
                z[i] -= 8000.0f;
            }
            func_80029714_2A314(model, pos[0], pos[1], z[i]);
        }
        if (D_80113784_37EE84_MinigameParkSetup != 0) {
            hit3 = 1;
            if (!(D_8011378C_37EE8C_MinigameParkSetup <= 0.0f)) {
                hit3 = 0;
            }
            if (hit3 & (snapped ^ 1)) {
                snapped = 1;
                D_80112B40_37E240_MinigameParkSetup = snapped;
                z[0] -= (s16)(z[0] / 2000.0f) * 2000.0f;
                D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[0]].pos.z = z[0];
                if (z[0] <= 0.0f) {
                    z[3] = z[0] + 2000.0f;
                    D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[3]].pos.z = z[3];
                } else {
                    func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[3], 4, 4);
                }
                z[1] = z[0] - 2000.0f;
                D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[1]].pos.z = z[1];
                z[2] = z[1] - 2000.0f;
                D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[2]].pos.z = z[2];
                z[5] = z[2] - 2000.0f;
                D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[5]].pos.z = z[5];
                func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[5], 4, 0);
            }
        }
        hit4 = D_80113786_37EE86_MinigameParkSetup != 0;
        if (hit4 & (snapped ^ 1)) {
            z[0] -= (s16)(z[0] / 2000.0f) * 2000.0f;
            D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[0]].pos.z = z[0];
            snapped = 1;
            if (z[0] >= 0.0f) {
                z[3] = z[0] - 2000.0f;
                D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[3]].pos.z = z[3];
            } else {
                func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[3], 4, 4);
            }
            z[1] = z[0] + 2000.0f;
            D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[1]].pos.z = z[1];
            z[2] = z[1] + 2000.0f;
            D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[2]].pos.z = z[2];
            z[4] = z[2] + 2000.0f;
            D_800FC834_FD434[D_801138B2_37EFB2_MinigameParkSetup[4]].pos.z = z[4];
            func_800298A4_2A4A4(D_801138B2_37EFB2_MinigameParkSetup[4], 4, 0);
        }
        for (i = 0; i < 1; i++) {
            u16 model = D_801138C0_37EFC0_MinigameParkSetup[i];

            d = z[0] + 3000.0f + 500.0f;
            d = 1000.0f - (d - (s16)(d / 1000.0f) * 1000 + D_800FC834_FD434[(s16)D_801138C0_37EFC0_MinigameParkSetup[i]].pos.z);
            if (d > 500.0f) {
                d = 1000.0f - d;
            }
            d = (d < 0.0f) ? -d : d;
            if (i == 1) {
                d = 500.0f - d;
            }
            d = (d - 200.0f) / 300.0f;
            if (d > 1.0f) {
                d = 1.0f;
            }
            if (d < 0.0f) {
                d = 0.0f;
            }
            func_8002D274_2DE74(model, d * 255.0f, d * 255.0f, d * 192.0f);
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010F358_37AA58_MinigameParkSetup);
#endif



__asm__(".section .rodata");
const char D_80113720_37EE20_MinigameParkSetup[] = "c100_1-atama";

__asm__(".section .rodata");
const char D_80113730_37EE30_MinigameParkSetup[] = "c162_000-atama";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010FB00_37B200_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110278_37B978_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110350_37BA50_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801103A4_37BAA4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011042C_37BB2C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104B4_37BBB4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104DC_37BBDC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104FC_37BBFC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801105B8_37BCB8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011060C_37BD0C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110678_37BD78_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801109C8_37C0C8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110A28_37C128_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110AF0_37C1F0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110B98_37C298_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111328_37CA28_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801115BC_37CCBC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011170C_37CE0C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111744_37CE44_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111750_37CE50_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011175C_37CE5C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111768_37CE68_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111D8C_37D48C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112360_37DA60_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112454_37DB54_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112810_37DF10_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112910_37E010_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112950_37E050_MinigameParkSetup);
