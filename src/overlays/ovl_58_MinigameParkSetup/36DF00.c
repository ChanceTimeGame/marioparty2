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

#ifdef NON_MATCHING
/* masked ~190 of 1777 lines: register allocation and spill slots (retail keeps `cur` and
   one more value on the stack; frame 0x100 vs 0xF8), `ok &= -(...)` becomes a branch, and
   the loop's exit test is laid out the other way round. Logic checked against the asm. */
/* Character select: the host model lifts the character panel in (six character icons,
   D_8011344C), each human moves a cursor (D_801137D0[i], slots D_80113798) and takes a
   character with A (B gives it back; B with nobody chosen leaves); then the controlling
   pad picks the CPUs' characters one by one with cursor 4. Each choice sends that
   character's model forward (801074CC) and tags its icon (player tag D_8011342C[i] or CPU
   tag [i + 4], marker 0x90093). Returns 1 when every player has a character (stored in
   D_80113958.character), 0 on B. */
s32 func_801052B4_3709B4_MinigameParkSetup(void) {
    s16 group[6];
    s16 spr[6];
    s16 tagGroup[8];
    s16 tag[8];
    s16 mark[4];
    s16 chosen[4];
    Vec base;
    s16 model;
    s16 grpPanel;
    s16 sprPanel;
    s16 ok;
    s16 phase;
    s16 cur;
    s16 lastSel;
    s16 maxPlayers;
    s16 grpMark;
    s16 i;
    s16 frame;
    s16 nDone;
    s16 sel;
    f32 dir;

    model = D_801138EC_37EFEC_MinigameParkSetup[0];
    cur = 0;
    lastSel = -1;
    maxPlayers = 2;
    if (D_80113816_37EF16_MinigameParkSetup != 2) {
        maxPlayers = 4;
    }
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
    } else {
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
    }
    func_80029C74_2A874(model, 30.0f);
    func_80029E80_2AA80(model, 1, 1);
    func_80029760_2A360(model, &base);
    grpPanel = func_8001A2F8_1AEF8(0x90084);
    sprPanel = func_8001AAAC_1B6AC(grpPanel, 0, 1);
    func_8001A6BC_1B2BC(sprPanel, 0x100);
    espPosSet(sprPanel, -100, -100);
    HuPrcVSleep();
    for (i = 0; i < 6; i++) {
        group[i] = func_8001A2F8_1AEF8(D_80113414_37EB14_MinigameParkSetup[i]);
        spr[i] = func_8001AAAC_1B6AC(group[i], 0, 1);
        func_8001A6BC_1B2BC(spr[i], 0x100);
        espPosSet(spr[i], -100, -100);
        func_801074CC_372BCC_MinigameParkSetup(i, 0.0f, 0.0f, -600.0f);
        if (i & 1) {
            HuPrcVSleep();
        }
    }
    HuPrcVSleep();
    grpMark = func_8001A2F8_1AEF8(0x90093);
    for (i = 0; i < 4; i++) {
        mark[i] = func_8001AAAC_1B6AC(grpMark, 0, 1);
        func_8001A6BC_1B2BC(mark[i], 0x80);
        espDispOff(mark[i]);
    }
    HuPrcVSleep();
    for (i = 0; i < 8; i++) {
        tagGroup[i] = func_8001A2F8_1AEF8(D_8011342C_37EB2C_MinigameParkSetup[i]);
        tag[i] = func_8001AAAC_1B6AC(tagGroup[i], 0, 1);
        func_8001A6BC_1B2BC(tag[i], 0xE0);
        espDispOff(tag[i]);
        if (i & 1) {
            HuPrcVSleep();
        }
    }
    /* Lift the panel in (or back from below after B on the next step). */
    func_800298A4_2A4A4(model, 4, 0);
    PlaySound(0xAC);
    dir = -1.0f;
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        dir = 1.0f;
    }
    for (frame = 0; frame < 20; frame++) {
        D_800FC834_FD434[model].pos.z = (1.0f - HuMathSin(frame * 4.5f)) * 1200.0f * dir + base.z;
        if (frame == 15) {
            func_80029E80_2AA80(model, 1, 0);
            func_80029FE4_2ABE4(model, 1.5f);
        }
        func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
        for (i = 0; i < 6; i++) {
            func_80106A00_372100_MinigameParkSetup(spr[i], i);
        }
        HuPrcVSleep();
    }
    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
        func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
        for (i = 0; i < 6; i++) {
            func_80106A00_372100_MinigameParkSetup(spr[i], i);
        }
        HuPrcVSleep();
    }
    PlaySound(0xB1);
    func_8002C9C0_2D5C0(model, D_801139AC_37F0AC_MinigameParkSetup);
    while (func_80029CE4_2A8E4(model) < 30.0f) {
        func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
        for (i = 0; i < 6; i++) {
            func_80106A00_372100_MinigameParkSetup(spr[i], i);
            func_801105B8_37BCB8_MinigameParkSetup(i, spr[i], 10, -6);
        }
        HuPrcVSleep();
    }
    func_80029E80_2AA80(model, 1, 1);
    /* Choose. */
    func_80107604_372D04_MinigameParkSetup();
    func_80107134_372834_MinigameParkSetup((s16(*)[2])&D_80113798_37EE98_MinigameParkSetup, 6);
    for (i = 0; i < maxPlayers; i++) {
        chosen[i] = -1;
        if (i < D_80113958_37F058_MinigameParkSetup.humans) {
            func_80107014_372714_MinigameParkSetup(i, 1);
            func_80107030_372730_MinigameParkSetup(i, i);
        }
    }
    phase = 0;
    ok = 1;
    while (1) {
        switch (phase) {
        case 0:
            /* The humans choose at once, each with their own cursor. */
            nDone = 0;
            for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
                nDone += func_801070E0_3727E0_MinigameParkSetup(i);
                sel = func_80107118_372818_MinigameParkSetup(i);
                if (chosen[i] == -1 && func_801070E0_3727E0_MinigameParkSetup(i) == 1) {
                    PlaySound(2);
                    func_80088604_89204(D_80113958_37F058_MinigameParkSetup.port[i], 2, 3, 10);
                    chosen[i] = D_80113958_37F058_MinigameParkSetup.character[i] = sel;
                    func_801074CC_372BCC_MinigameParkSetup(chosen[i], 50 - i * 50, 0.0f, 70 - i * 140);
                    D_801138A0_37EFA0_MinigameParkSetup[chosen[i]] = 16;
                    func_80107014_372714_MinigameParkSetup(i, 0);
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i], spr[sel]);
                    espDispOn(tag[i]);
                    func_80106AB4_3721B4_MinigameParkSetup(mark[i], spr[sel]);
                    espDispOn(mark[i]);
                }
            }
            if (nDone >= D_80113958_37F058_MinigameParkSetup.humans) {
                phase++;
                if (D_80113958_37F058_MinigameParkSetup.humans != maxPlayers) {
                    func_80110350_37BA50_MinigameParkSetup(D_800CD414_CE014 == 3 ? 0x593
                                                           : maxPlayers != 4 ? 0x5C
                                                           : D_80113958_37F058_MinigameParkSetup.humans + 0x59);
                    func_801103A4_37BAA4_MinigameParkSetup();
                    func_80107014_372714_MinigameParkSetup(4, 1);
                    for (i = 0; i < 6; i++) {
                        if (D_801138A0_37EFA0_MinigameParkSetup[i] == -1) {
                            break;
                        }
                    }
                    func_80107030_372730_MinigameParkSetup(4, i);
                    lastSel = -1;
                    cur = D_80113958_37F058_MinigameParkSetup.humans;
                }
            } else {
                if (nDone == 0) {
                    /* Nobody has chosen: B leaves. */
                    for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
                        if (ContBtnTrg[D_80113958_37F058_MinigameParkSetup.port[i]] & 0x4000) {
                            break;
                        }
                    }
                    ok *= (i == D_80113958_37F058_MinigameParkSetup.humans);
                } else {
                    /* B gives a choice back (its slot owner becomes cursor 0, as retail). */
                    for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
                        if (func_801070E0_3727E0_MinigameParkSetup(i) != 0) {
                            if (ContBtnTrg[D_80113958_37F058_MinigameParkSetup.port[i]] & 0x4000) {
                                PlaySound(4);
                                func_801070FC_3727FC_MinigameParkSetup(i, 0);
                                func_801074CC_372BCC_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[i], 0.0f, 0.0f, -600.0f);
                                D_801138A0_37EFA0_MinigameParkSetup[chosen[i]] = 0;
                                chosen[i] = -1;
                                func_80107014_372714_MinigameParkSetup(i, 1);
                                espDispOff(tag[i]);
                                espDispOff(mark[i]);
                            }
                        }
                    }
                }
            }
            break;
        case 1:
            /* The controlling pad chooses for each CPU with cursor 4. */
            if (func_80107118_372818_MinigameParkSetup(4) != lastSel) {
                lastSel = func_80107118_372818_MinigameParkSetup(4);
                if (D_800CD414_CE014 == 0) {
                    func_80110350_37BA50_MinigameParkSetup(func_80107118_372818_MinigameParkSetup(4) + 0x5D);
                } else {
                    func_80110350_37BA50_MinigameParkSetup(func_80107118_372818_MinigameParkSetup(4) + 0x360);
                }
                func_801103A4_37BAA4_MinigameParkSetup();
            }
            if (chosen[cur] == -1 && func_801070E0_3727E0_MinigameParkSetup(4) == 1) {
                PlaySound(2);
                chosen[cur] = D_80113958_37F058_MinigameParkSetup.character[cur] = func_80107118_372818_MinigameParkSetup(4);
                func_801074CC_372BCC_MinigameParkSetup(chosen[cur], 50 - cur * 50, 0.0f, 70 - cur * 140);
                D_801138A0_37EFA0_MinigameParkSetup[chosen[cur]] = 16;
                func_80106AB4_3721B4_MinigameParkSetup(tag[cur + 4], spr[chosen[cur]]);
                espDispOn(tag[cur + 4]);
                func_80106AB4_3721B4_MinigameParkSetup(mark[cur], spr[chosen[cur]]);
                espDispOn(mark[cur]);
                cur++;
                if (cur < maxPlayers) {
                    for (i = 0; i < 6; i++) {
                        if (D_801138A0_37EFA0_MinigameParkSetup[i] == -1) {
                            break;
                        }
                    }
                    func_80107030_372730_MinigameParkSetup(4, i);
                    func_801070FC_3727FC_MinigameParkSetup(4, 0);
                    HuPrcSleep(2);
                }
            }
            if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x4000) {
                PlaySound(4);
                D_801138A0_37EFA0_MinigameParkSetup[chosen[cur - 1]] = -1;
                cur--;
                if (cur < D_80113958_37F058_MinigameParkSetup.humans) {
                    /* Back to the humans: every choice is undone. */
                    func_80107604_372D04_MinigameParkSetup();
                    phase--;
                    func_80107014_372714_MinigameParkSetup(4, 0);
                    for (i = 0; i < D_80113958_37F058_MinigameParkSetup.humans; i++) {
                        func_80107014_372714_MinigameParkSetup(i, 1);
                        func_80107030_372730_MinigameParkSetup(i, chosen[i]);
                        func_801074CC_372BCC_MinigameParkSetup(chosen[i], 0.0f, 0.0f, -600.0f);
                        chosen[i] = -1;
                        espDispOff(tag[i]);
                        espDispOff(mark[i]);
                    }
                    func_80110350_37BA50_MinigameParkSetup(0x59);
                    func_801103A4_37BAA4_MinigameParkSetup();
                } else {
                    func_801074CC_372BCC_MinigameParkSetup(chosen[cur], 0.0f, 0.0f, -600.0f);
                    espDispOff(tag[cur + 4]);
                    espDispOff(mark[cur]);
                    func_80110350_37BA50_MinigameParkSetup(cur - D_80113958_37F058_MinigameParkSetup.humans + 0x63);
                    func_801103A4_37BAA4_MinigameParkSetup();
                    chosen[cur] = -1;
                }
            }
            break;
        }
        /* Icons of taken characters are dimmed. */
        for (i = 0; i < 6; i++) {
            if (D_801138A0_37EFA0_MinigameParkSetup[i] == -1) {
                func_8001A854_1B454(spr[i], 0, 0);
            } else {
                func_8001A854_1B454(spr[i], 1, 0);
            }
            func_8001A89C_1B49C(spr[i], 1);
        }
        for (i = 0; i < maxPlayers; i++) {
            if (chosen[i] == -1) {
                break;
            }
        }
        if (!(i == maxPlayers || ok == 0)) {
            HuPrcVSleep();
            continue;
        }
        break;
    }
    for (i = 0; i < 5; i++) {
        func_80107014_372714_MinigameParkSetup(i, 0);
    }
    for (i = 0; i < maxPlayers; i++) {
        func_80107014_372714_MinigameParkSetup(i, 0);
    }
    func_80029E80_2AA80(model, 1, 0);
    func_80029FE4_2ABE4(model, 2.0f);
    PlaySound(0xB1);
    if (ok != 0) {
        /* The host jumps and the panel sinks away. */
        for (frame = 0; frame < 15; frame++) {
            func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
            for (i = 0; i < 6; i++) {
                func_80106A00_372100_MinigameParkSetup(spr[i], i);
            }
            for (i = 0; i < maxPlayers; i++) {
                if (i < D_80113958_37F058_MinigameParkSetup.humans) {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i], spr[chosen[i]]);
                } else {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i + 4], spr[chosen[i]]);
                }
                func_80106AB4_3721B4_MinigameParkSetup(mark[i], spr[chosen[i]]);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 10; frame++) {
            D_800FC834_FD434[model].pos.z = base.z - frame * 100;
            func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
            for (i = 0; i < 6; i++) {
                func_80106A00_372100_MinigameParkSetup(spr[i], i);
            }
            for (i = 0; i < maxPlayers; i++) {
                if (i < D_80113958_37F058_MinigameParkSetup.humans) {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i], spr[chosen[i]]);
                } else {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i + 4], spr[chosen[i]]);
                }
                func_80106AB4_3721B4_MinigameParkSetup(mark[i], spr[chosen[i]]);
            }
            HuPrcVSleep();
        }
        for (i = 0; i < maxPlayers; i++) {
            D_80113958_37F058_MinigameParkSetup.character[i] = chosen[i];
        }
    } else {
        for (frame = 0; frame < 15; frame++) {
            func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
            for (i = 0; i < 6; i++) {
                func_80106A00_372100_MinigameParkSetup(spr[i], i);
            }
            for (i = 0; i < maxPlayers; i++) {
                if (i < D_80113958_37F058_MinigameParkSetup.humans) {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i], spr[chosen[i]]);
                } else {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i + 4], spr[chosen[i]]);
                }
                func_80106AB4_3721B4_MinigameParkSetup(mark[i], spr[chosen[i]]);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 11; frame++) {
            D_800FC834_FD434[model].pos.z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 1200.0f + base.z;
            func_801104FC_37BBFC_MinigameParkSetup(model, sprPanel, D_80113630_37ED30_MinigameParkSetup);
            for (i = 0; i < 6; i++) {
                func_80106A00_372100_MinigameParkSetup(spr[i], i);
            }
            for (i = 0; i < maxPlayers; i++) {
                if (i < D_80113958_37F058_MinigameParkSetup.humans) {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i], spr[chosen[i]]);
                } else {
                    func_80106AB4_3721B4_MinigameParkSetup(tag[i + 4], spr[chosen[i]]);
                }
                func_80106AB4_3721B4_MinigameParkSetup(mark[i], spr[chosen[i]]);
            }
            HuPrcVSleep();
        }
    }
    func_800298A4_2A4A4(model, 4, 4);
    func_8001AC44_1B844(sprPanel);
    SprAnimKill(grpPanel);
    for (i = 0; i < 6; i++) {
        func_8001AC44_1B844(spr[i]);
        SprAnimKill(group[i]);
    }
    for (i = 0; i < 8; i++) {
        func_8001AC44_1B844(tag[i]);
        SprAnimKill(tagGroup[i]);
    }
    SprAnimKill(grpMark);
    for (i = 0; i < 4; i++) {
        func_8001AC44_1B844(mark[i]);
    }
    func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 30, model);
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801052B4_3709B4_MinigameParkSetup);
#endif

/* Place sprite `sprite` at icon slot `slot` (D_8011344C, around D_801137B0). */
void func_80106A00_372100_MinigameParkSetup(s16 sprite, s16 slot) {
    espPosSet(sprite, D_8011344C_37EB4C_MinigameParkSetup[slot][0] + D_801137B0_37EEB0_MinigameParkSetup[0] - 68.0f,
              D_8011344C_37EB4C_MinigameParkSetup[slot][1] + D_801137B0_37EEB0_MinigameParkSetup[1] - 3.0f);
}

/* Place sprite `sprite` where esprite slot `slot` is. */
void func_80106AB4_3721B4_MinigameParkSetup(s16 sprite, s16 slot) {
    Ovl58Esprite* esp = &((Ovl58Esprite*)D_800F93FC_F9FFC)[slot];

    espPosSet(sprite, esp->x, esp->y);
}

#ifdef NON_MATCHING
/* raw 9: the two hoisted fade constants trade places (retail keeps 127.5
   in s5 and 255.0 in f30). */
/* Process: one selection cursor (D_801137D0[n]). While active it fades in, moves between
   its slots with its pad's stick (D_801138A0 records which cursor is on each slot), and
   sets `done` on A; when deactivated it fades out. */
void func_80106AF8_3721F8_MinigameParkSetup(void) {
    Ovl58Cursor* c;
    s16 n;
    s16 id;
    s16 spr;
    s16 shown;
    s16 i;
    s16 sel;
    f32 x0;
    f32 y0;
    f32 dx;
    f32 dy;
    f32 s;

    D_801137D0_37EED0_MinigameParkSetup[n = D_80113800_37EF00_MinigameParkSetup] = func_80027154_27D54(0x18, 0x7918);
    c = D_801137D0_37EED0_MinigameParkSetup[n];
    c->id = id = D_80113800_37EF00_MinigameParkSetup++;
    if (n < D_80113958_37F058_MinigameParkSetup.padCount) {
        c->port = D_80113958_37F058_MinigameParkSetup.port[n];
    } else {
        c->port = D_8011381B_37EF1B_MinigameParkSetup;
    }
    shown = 0;
    c->active = 0;
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F9), c->id, 1);
    func_8001A788_1B388(spr, 1);
    espPosSet(spr, 160, 120);
    espDispOff(spr);
    c->x = 160.0f;
    c->y = 120.0f;
    c->done = 0;
    c->sel = 0;
    c->prevSel = 0;
    while (1) {
        HuPrcVSleep();
        espPosSet(spr, c->x, c->y);
        if (shown != 0 && c->active == 0) {
            c->prevSel = c->sel;
            for (i = 0; i < 3; i++) {
                func_8001A6BC_1B2BC(spr, 255.0f - i * 127.5f);
                HuPrcVSleep();
            }
            espDispOff(spr);
            shown = 0;
        }
        if (c->active != 0) {
            if (shown == 0 && c->active != 0) {
                c->done = 0;
                espDispOn(spr);
                for (i = 0; i < 5; i++) {
                    func_8001A6BC_1B2BC(spr, i * 63.75f);
                    HuPrcVSleep();
                }
                shown = 1;
                continue;
            }
            if (ContBtnTrg[c->port] & 0x8000) {
                c->done = 1;
                continue;
            }
            if (c->done != 1) {
                if ((ContStkX[c->port] < 0 ? -ContStkX[c->port] : ContStkX[c->port]) >= 31
                    || (ContStkY[c->port] < 0 ? -ContStkY[c->port] : ContStkY[c->port]) >= 31) {
                    sel = func_80110678_37BD78_MinigameParkSetup(c->sel, c->count, -ContStkX[c->port], ContStkY[c->port]);
                    if (sel != -1) {
                        PlaySound(1);
                        c->sel = sel;
                    }
                }
            }
            if (c->prevSel == c->sel) {
                continue;
            }
            if (D_801138A0_37EFA0_MinigameParkSetup[c->prevSel] != 16) {
                D_801138A0_37EFA0_MinigameParkSetup[c->prevSel] = -1;
            }
            D_801138A0_37EFA0_MinigameParkSetup[c->sel] = id;
            x0 = c->x;
            y0 = c->y;
            dx = c->slots[c->sel][0] - x0;
            dy = c->slots[c->sel][1] - y0;
            for (i = 1; i < 6; i++) {
                s = HuMathSin(i * 18.0f);
                c->x = x0 + dx * s;
                c->y = y0 + dy * s;
                espPosSet(spr, c->x, c->y);
                HuPrcVSleep();
            }
        }
        c->prevSel = c->sel;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106AF8_3721F8_MinigameParkSetup);
#endif

void func_80107014_372714_MinigameParkSetup(s16 cursor, s8 active) {
    D_801137D0_37EED0_MinigameParkSetup[cursor]->active = active;
}

/* Put cursor `cursor` on slot `slot` at once. */
void func_80107030_372730_MinigameParkSetup(s16 cursor, s16 slot) {
    Ovl58Cursor* c = D_801137D0_37EED0_MinigameParkSetup[cursor];

    c->x = c->slots[slot][0];
    c->y = c->slots[slot][1];
    c->prevSel = slot;
    c->sel = slot;
    D_801137D0_37EED0_MinigameParkSetup[cursor]->done = 0;
    D_801138A0_37EFA0_MinigameParkSetup[slot] = cursor;
}

/* Move cursor `cursor` to slot `slot` (it slides there). */
void func_801070B0_3727B0_MinigameParkSetup(s16 cursor, s16 slot) {
    D_801137D0_37EED0_MinigameParkSetup[cursor]->sel = slot;
    D_801138A0_37EFA0_MinigameParkSetup[slot] = cursor;
}

s16 func_801070E0_3727E0_MinigameParkSetup(s16 cursor) {
    return D_801137D0_37EED0_MinigameParkSetup[cursor]->done;
}

void func_801070FC_3727FC_MinigameParkSetup(s16 cursor, s16 done) {
    D_801137D0_37EED0_MinigameParkSetup[cursor]->done = done;
}

s16 func_80107118_372818_MinigameParkSetup(s16 cursor) {
    return D_801137D0_37EED0_MinigameParkSetup[cursor]->sel;
}

/* Give all five cursors the slot table `slots` of `count` slots. */
void func_80107134_372834_MinigameParkSetup(s16 (*slots)[2], s8 count) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_801137D0_37EED0_MinigameParkSetup[i]->slots = slots;
        D_801137D0_37EED0_MinigameParkSetup[i]->count = count;
    }
}

/* Process: one model mover (D_801137E8[n]) for the character models D_801138C8: slides the
   model towards its target, accelerating; it is hidden while far out in depth. */
void func_80107180_372880_MinigameParkSetup(void) {
    Ovl58Mover* m;
    Vec* pos;
    Vec* target;
    s16 id;
    s16 model;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    D_801137E8_37EEE8_MinigameParkSetup[id = D_80113802_37EF02_MinigameParkSetup] = func_80027154_27D54(0x20, 0x7918);
    m = D_801137E8_37EEE8_MinigameParkSetup[id];
    D_80113802_37EF02_MinigameParkSetup = id + 1;
    m->id = id;
    pos = &m->pos;
    target = &m->target;
    model = OVL58_CHAR_MODEL(id);
    D_80101300_101F00 = 0.1f;
    D_8010105C_101C5C = 0.3f;
    func_80029A8C_2A68C(model);
    func_80029AFC_2A6FC(model);
    func_8002D1EC_2DDEC(model, 1);
    func_8002D274_2DE74(model, 0xFF, 0xFF, 0xC0);
    func_8002D2B4_2DEB4(model, 0.0f, 100.0f, 0.0f);
    D_8010105C_101C5C = 1.0f;
    D_80101300_101F00 = 1.0f;
    func_8002C9C0_2D5C0(model, D_8011398A_37F08A_MinigameParkSetup[id * 2]);
    func_80029E80_2AA80(model, 2, 2);
    func_800298A4_2A4A4(model, 4, 4);
    func_80029714_2A314(model, 0.0f, 0.0f, -600.0f);
    func_80029760_2A360(model, pos);
    m->target = m->pos;
    while (1) {
        if (pos->z < 500.0f && pos->z > -500.0f) {
            func_800298A4_2A4A4(model, 4, 0);
        } else {
            func_800298A4_2A4A4(model, 4, 4);
        }
        if (pos->x != target->x || pos->y != target->y || pos->z != target->z) {
            dx = target->x - pos->x;
            dy = target->y - pos->y;
            dz = target->z - pos->z;
            dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (dist < m->speed) {
                m->pos = m->target;
            } else {
                pos->x += dx / dist * m->speed;
                pos->y += dy / dist * m->speed;
                pos->z += dz / dist * m->speed;
            }
            m->speed += 1.0f;
        }
        func_80029714_2A314(model, pos->x, pos->y, pos->z);
        HuPrcVSleep();
    }
}

/* Send mover `mover` to (x, y, z); a new depth above -400 plays its sound. */
void func_801074CC_372BCC_MinigameParkSetup(s16 mover, f32 x, f32 y, f32 z) {
    if (z > -400.0f) {
        if (D_801137E8_37EEE8_MinigameParkSetup[mover]->target.z != z) {
            func_8007975C_7A35C(mover + 0x107, D_80113464_37EB64_MinigameParkSetup);
            D_80113464_37EB64_MinigameParkSetup = (D_80113464_37EB64_MinigameParkSetup + 1) & 3;
        }
    }
    D_801137E8_37EEE8_MinigameParkSetup[mover]->target.x = x;
    D_801137E8_37EEE8_MinigameParkSetup[mover]->target.y = y;
    D_801137E8_37EEE8_MinigameParkSetup[mover]->target.z = z;
    D_801137E8_37EEE8_MinigameParkSetup[mover]->speed = 10.0f;
}

/* Put mover `mover` at (x, y, z) at once. */
void func_801075C8_372CC8_MinigameParkSetup(s16 mover, f32 x, f32 y, f32 z) {
    Ovl58Mover* m = D_801137E8_37EEE8_MinigameParkSetup[mover];

    m->target.x = x;
    m->pos.x = x;
    m->target.y = y;
    m->pos.y = y;
    m->target.z = z;
    m->pos.z = z;
}

/* No cursor on any slot. */
void func_80107604_372D04_MinigameParkSetup(void) {
    s16 i;

    for (i = 0; i < 16; i++) {
        D_801138A0_37EFA0_MinigameParkSetup[i] = -1;
    }
}










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

#ifdef NON_MATCHING
/* masked ~230 of 1596 lines: register allocation and spill slots (frame 0x180 vs 0x178),
   the model-table address arithmetic, the order of the two motion-time calls, and the
   choice loop's exit test. Logic checked against the asm. */
/* CPU level: `n` level models (3, or 4 in modes 1-3) lift their "cl_panel" signs in; the
   host asks whether all CPUs share one level (func_801103A4: 0 all, 1 each, -1 B; mode 2
   does not ask). The controlling pad picks a level with the stick and A (B steps back one
   CPU). The levels go to D_80113804[player] and then D_80113958.cpuLevel. Returns 1 when
   done, 0 on B. */
s32 func_80107644_372D44_MinigameParkSetup(s16 n) {
    Ovl58Quad models;
    s16 done[4];
    Ovl58Pos3 pos3;
    Ovl58Pos4 pos4;
    s16 grpPanel[4];
    s16 sprPanel[4];
    s16 sprIcon[4];
    s16 grpIcon[4];
    Vec base[4];
    Vec pos[4];
    Ovl58MsgArg msg;
    s16 all;
    s16 level;
    s16 maxPlayers;
    s16 result;
    s16 cur;
    s16 i;
    s16 frame;
    s16 sel;
    f32 dir;
    f32 t;
    f32 angle;
    f32 s;

    models = *(Ovl58Quad*)D_801138F2_37EFF2_MinigameParkSetup;
    pos3 = *(Ovl58Pos3*)D_80113638_37ED38_MinigameParkSetup;
    pos4 = *(Ovl58Pos4*)D_8011365C_37ED5C_MinigameParkSetup;
    all = 1;
    level = -1;
    msg = *(Ovl58MsgArg*)D_8011368C_37ED8C_MinigameParkSetup;
    maxPlayers = 2;
    if (D_80113816_37EF16_MinigameParkSetup != 2) {
        maxPlayers = 4;
    }
    if (n == 3) {
        for (i = 0; i < 3; i++) {
            ((Ovl58ModelEntry*)D_80112BBC_37E2BC_MinigameParkSetup)[i + 33].pos = pos3.v[i];
            func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 33, models.v[i]);
        }
    } else {
        for (i = 0; i < 4; i++) {
            ((Ovl58ModelEntry*)D_80112BBC_37E2BC_MinigameParkSetup)[i + 33].pos = pos4.v[i];
            func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 33, models.v[i]);
        }
    }
    for (i = 0; i < n; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 0);
        if (D_80113782_37EE82_MinigameParkSetup == 0) {
            func_8002C9C0_2D5C0(models.v[i], D_801139BA_37F0BA_MinigameParkSetup);
        } else {
            func_8002C9C0_2D5C0(models.v[i], D_801139BC_37F0BC_MinigameParkSetup);
        }
        func_80029C74_2A874(models.v[i], 30.0f);
        func_80029E80_2AA80(models.v[i], 1, 1);
        func_80029760_2A360(models.v[i], &base[i]);
        pos[i] = base[i];
        pos[i].z += 1250.0f;
        func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
        done[i] = 0;
    }
    for (i = 0; i < n; i++) {
        grpPanel[i] = func_8001A2F8_1AEF8(0x90088);
        sprPanel[i] = func_8001AAAC_1B6AC(grpPanel[i], 0, 1);
        func_8001A6BC_1B2BC(sprPanel[i], 0x100);
        espPosSet(sprPanel[i], -200, -100);
        grpIcon[i] = func_8001A2F8_1AEF8(D_80113468_37EB68_MinigameParkSetup[i]);
        sprIcon[i] = func_8001AAAC_1B6AC(grpIcon[i], 0, 1);
        func_8001A6BC_1B2BC(sprIcon[i], 0x100);
        espPosSet(sprIcon[i], -200, -100);
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        D_80113804_37EF04_MinigameParkSetup[i] = -1;
    }
    if (D_80113816_37EF16_MinigameParkSetup != 2) {
        func_80110350_37BA50_MinigameParkSetup(0x67);
    } else {
        func_801104DC_37BBDC_MinigameParkSetup();
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
                t = frame - (n - (i + 1)) * 10;
            } else {
                t = frame - i * 10;
            }
            if (t == 0.0f) {
                PlaySound(0xAB);
            }
            if ((t > 0.0f) & (t <= 20.0f)) {
                pos[i].z = (1.0f - HuMathSin(t * 4.5f)) * 1250.0f * dir + base[i].z;
                if (t == 10.0f) {
                    func_80029E80_2AA80(models.v[i], 1, 0);
                    func_80029FE4_2ABE4(models.v[i], 1.5f);
                }
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
            } else if ((done[i] == 0) & (t > 25.0f)) {
                if (func_80029E14_2AA14(models.v[i]) != D_801139B2_37F0B2_MinigameParkSetup[0]) {
                    if (func_80029D0C_2A90C(models.v[i]) <= func_80029CE4_2A8E4(models.v[i])) {
                        PlaySound(0xB1);
                        func_8002C9C0_2D5C0(models.v[i], D_801139B2_37F0B2_MinigameParkSetup[0]);
                    }
                } else if (func_80029D0C_2A90C(models.v[i]) <= func_80029CE4_2A8E4(models.v[i])) {
                    func_80029E80_2AA80(models.v[i], 1, 1);
                    done[i] = 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
            func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
            func_801105B8_37BCB8_MinigameParkSetup(i, sprPanel[i], 10, 20);
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
    /* Choose. */
    do {
        result = 0;
        if (D_80113816_37EF16_MinigameParkSetup != 2) {
            result = func_801103A4_37BAA4_MinigameParkSetup();
        }
        if (result == -1) {
            for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                D_80113804_37EF04_MinigameParkSetup[i] = -1;
            }
            result = 0;
            break;
        }
        func_80107604_372D04_MinigameParkSetup();
        D_8011393C_37F03C_MinigameParkSetup = 1;
        func_8011170C_37CE0C_MinigameParkSetup(1);
        D_8011392C_37F02C_MinigameParkSetup = 1;
        HuPrcSleep(5);
        cur = D_80113958_37F058_MinigameParkSetup.humans;
        if (result != 0) {
            /* One level per CPU: "<character>'s level?" */
            all = 0;
            msg.v[1] = D_80113958_37F058_MinigameParkSetup.character[cur];
            func_801104B4_37BBB4_MinigameParkSetup(msg.v);
            sel = 0x66;
        } else {
            all = 1;
            sel = 0x68;
        }
        func_80110350_37BA50_MinigameParkSetup(sel);
        func_801103A4_37BAA4_MinigameParkSetup();
        angle = 0.0f;
        while (1) {
            if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
                || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
                sel = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, n, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
                if (sel != -1) {
                    PlaySound(1);
                    func_8011175C_37CE5C_MinigameParkSetup(sel);
                    angle = 0.0f;
                    func_8001A91C_1B51C(sprIcon[D_8011393C_37F03C_MinigameParkSetup], 1.0f, 1.0f);
                    HuPrcSleep(6);
                    D_8011393C_37F03C_MinigameParkSetup = sel;
                }
            }
            if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x4000) {
                PlaySound(4);
                cur--;
                D_80113804_37EF04_MinigameParkSetup[cur] = -1;
                if (cur < D_80113958_37F058_MinigameParkSetup.humans || all != 0) {
                    if (all != 0) {
                        for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
                            D_80113804_37EF04_MinigameParkSetup[i] = -1;
                        }
                    }
                    level = -1;
                    if (D_80113816_37EF16_MinigameParkSetup != 2) {
                        func_80110350_37BA50_MinigameParkSetup(0x67);
                    }
                    break;
                }
                if (all == 0) {
                    msg.v[1] = D_80113958_37F058_MinigameParkSetup.character[cur];
                    func_801104B4_37BBB4_MinigameParkSetup(msg.v);
                    func_80110350_37BA50_MinigameParkSetup(0x66);
                    func_801103A4_37BAA4_MinigameParkSetup();
                }
            }
            if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x8000) {
                PlaySound(2);
                level = D_8011393C_37F03C_MinigameParkSetup;
                if (all == 0) {
                    D_80113804_37EF04_MinigameParkSetup[cur] = level;
                } else {
                    for (i = D_80113958_37F058_MinigameParkSetup.humans; i < maxPlayers; i++) {
                        D_80113804_37EF04_MinigameParkSetup[i] = level;
                    }
                }
                cur++;
                if (cur >= 4 || all != 0) {
                    result = 1;
                    break;
                }
                msg.v[1] = D_80113958_37F058_MinigameParkSetup.character[cur];
                func_801104B4_37BBB4_MinigameParkSetup(msg.v);
                func_80110350_37BA50_MinigameParkSetup(0x66);
                func_801103A4_37BAA4_MinigameParkSetup();
            }
            /* The chosen level's icon pulses. */
            s = func_800B7890_B8490(angle) * 0.1f + 0.9f;
            func_8001A91C_1B51C(sprIcon[D_8011393C_37F03C_MinigameParkSetup], s, s);
            angle += 20.0f;
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
            HuPrcVSleep();
        }
        func_8001A91C_1B51C(sprIcon[D_8011393C_37F03C_MinigameParkSetup], 1.0f, 1.0f);
        D_8011392C_37F02C_MinigameParkSetup = 0;
        HuPrcSleep(5);
    } while (!((D_80113816_37EF16_MinigameParkSetup == 2) & (level == -1)) && result != 1);
    PlaySound(0xB1);
    for (i = 0; i < n; i++) {
        func_80029E80_2AA80(models.v[i], 5, 4);
        func_80029FE4_2ABE4(models.v[i], 2.0f);
    }
    if (result != 0) {
        if (all != 0) {
            /* One level for all: its model jumps. */
            func_80029E80_2AA80(models.v[level], 1, 1);
            for (frame = 0; frame < 30; frame++) {
                if (frame == 15) {
                    func_80029E80_2AA80(models.v[level], 5, 4);
                    PlaySound(0xB1);
                }
                for (i = 0; i < n; i++) {
                    func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
                    func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
                }
                HuPrcVSleep();
            }
        } else {
            for (frame = 0; frame < 15; frame++) {
                for (i = 0; i < n; i++) {
                    func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
                    func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
                }
                HuPrcVSleep();
            }
        }
        for (i = 0; i < n; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139BA_37F0BA_MinigameParkSetup);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 0; frame < 10; frame++) {
            for (i = 0; i < n; i++) {
                pos[i].z = base[i].z - frame * 100;
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
                func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
            }
            HuPrcVSleep();
        }
        for (i = 0; i < maxPlayers; i++) {
            D_80113958_37F058_MinigameParkSetup.cpuLevel[i] = D_80113804_37EF04_MinigameParkSetup[i];
        }
    } else {
        for (i = D_80113958_37F058_MinigameParkSetup.humans; i < maxPlayers; i++) {
            D_80113804_37EF04_MinigameParkSetup[i] = -1;
        }
        PlaySound(0xB1);
        for (frame = 0; frame < 15; frame++) {
            for (i = 0; i < n; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
                func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
            }
            HuPrcVSleep();
        }
        for (i = 0; i < n; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139BC_37F0BC_MinigameParkSetup);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 0; frame < 11; frame++) {
            for (i = 0; i < n; i++) {
                pos[i].z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 1250.0f + base[i].z;
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], sprPanel[i], D_80113690_37ED90_MinigameParkSetup);
                func_80108BA8_3742A8_MinigameParkSetup(sprIcon[i]);
            }
            HuPrcVSleep();
        }
    }
    for (i = 0; i < n; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 4);
    }
    for (i = 0; i < n; i++) {
        func_8001AC44_1B844(sprPanel[i]);
        SprAnimKill(grpPanel[i]);
        func_8001AC44_1B844(sprIcon[i]);
        SprAnimKill(grpIcon[i]);
    }
    for (i = 0; i < n; i++) {
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 33, models.v[i]);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107644_372D44_MinigameParkSetup);
#endif

/* Place sprite `sprite` 24 below the panel origin D_801137B0. */
void func_80108BA8_3742A8_MinigameParkSetup(s16 sprite) {
    espPosSet(sprite, D_801137B0_37EEB0_MinigameParkSetup[0], D_801137B0_37EEB0_MinigameParkSetup[1] + 24.0f);
}

#ifdef NON_MATCHING
/* raw 5, masked 2: the first init loop stores owner[i] before the D_80113804 address add
   (retail: after it); scheduling only. */
/* Process: a marker over each player's character model. D_80113804[i] picks player i's
   marker (sprite D_80113478[n]; -1 none): it pops in (state 0), bobs in a small circle
   above the model's head, and shrinks away (state 1) when cleared. */
void func_80108C0C_37430C_MinigameParkSetup(void) {
    s16 group[4];
    s16 spr[4];
    s16 owner[4];
    Vec pos;
    Vec2f scr;
    s16 angle[4];
    s16 state[4];
    s16 timer[4];
    s16 i;
    f32 s;

    for (i = 0; i < 4; i++) {
        group[i] = func_8001A2F8_1AEF8(D_80113478_37EB78_MinigameParkSetup[i]);
    }
    for (i = 0; i < 4; i++) {
        spr[i] = -1;
        owner[i] = -1;
        D_80113804_37EF04_MinigameParkSetup[i] = -1;
        angle[i] = i * 45;
        state[i] = -1;
    }
    while (1) {
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            if (D_80113804_37EF04_MinigameParkSetup[i] != -1 && owner[i] == -1) {
                if (spr[i] != -1) {
                    func_8001AC44_1B844(spr[i]);
                }
                spr[i] = func_8001AAAC_1B6AC(group[D_80113804_37EF04_MinigameParkSetup[i]], 0, 1);
                func_8001A6BC_1B2BC(spr[i], 0x100);
                func_8001A788_1B388(spr[i], 5);
                owner[i] = D_80113804_37EF04_MinigameParkSetup[i];
                timer[i] = 0;
                state[i] = 0;
            }
            if (D_80113804_37EF04_MinigameParkSetup[i] == -1 && owner[i] != -1) {
                owner[i] = D_80113804_37EF04_MinigameParkSetup[i];
                state[i] = 1;
                timer[i] = 0;
            }
            switch (state[i]) {
            case 0:
                if (timer[i] >= 10) {
                    state[i] = -1;
                }
                s = HuMathSin(timer[i] * 9.0f);
                func_8001A91C_1B51C(spr[i], s, s);
                timer[i]++;
                break;
            case 1:
                if (timer[i] >= 10) {
                    state[i] = -1;
                    func_8001AC44_1B844(spr[i]);
                    spr[i] = -1;
                } else {
                    s = HuMathSin(timer[i] * 9.0f + 90.0f);
                    func_8001A91C_1B51C(spr[i], s, s);
                    timer[i]++;
                }
                break;
            }
            if (D_80113804_37EF04_MinigameParkSetup[i] != -1) {
                func_80029760_2A360(OVL58_CHAR_MODEL(D_80113958_37F058_MinigameParkSetup.character[i]), &pos);
                pos.y += 130.0f;
                Hu3DCam3DToScreen(0, &pos, &scr);
                scr.unk_00 += 2.0f * HuMathSin(angle[i]);
                scr.unk_04 += 2.0f * HuMathSin(angle[i]);
                angle[i] += 20;
                if (angle[i] > 360) {
                    angle[i] -= 360;
                }
                espPosSet(spr[i], scr.unk_00, scr.unk_04);
            }
        }
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80108C0C_37430C_MinigameParkSetup);
#endif

/* The character-icon process: for each player, pops in the icon of the character
   D_8011380C[i] (> 0) above the player's model, bobs it, and shrinks it away when
   D_8011380C[i] goes back to -1. */
void func_8010903C_37473C_MinigameParkSetup(void) {
    s16 bank[6];
    s16 spr[4];
    s16 cur[4];
    Vec pos;
    Vec2f scr;
    s16 ang[4];
    s16 mode[4];
    s16 timer[4];
    s16 i;
    f32 s;

    for (i = 0; i < 6; i++) {
        bank[i] = func_8001A2F8_1AEF8(D_80113488_37EB88_MinigameParkSetup[i]);
    }
    for (i = 0; i < 4; i++) {
        spr[i] = -1;
        D_8011380C_37EF0C_MinigameParkSetup[i] = cur[i] = -1;
        ang[i] = i * 45;
        mode[i] = -1;
    }
    while (1) {
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            if (D_8011380C_37EF0C_MinigameParkSetup[i] > 0 && cur[i] == -1) {
                if (spr[i] != -1) {
                    func_8001AC44_1B844(spr[i]);
                }
                spr[i] = func_8001AAAC_1B6AC(bank[D_8011380C_37EF0C_MinigameParkSetup[i]], 0, 1);
                func_8001A6BC_1B2BC(spr[i], 0x100);
                func_8001A788_1B388(spr[i], 5);
                cur[i] = D_8011380C_37EF0C_MinigameParkSetup[i];
                timer[i] = 0;
                mode[i] = 0;
            }
            if (D_8011380C_37EF0C_MinigameParkSetup[i] == -1 && cur[i] > 0) {
                cur[i] = D_8011380C_37EF0C_MinigameParkSetup[i];
                mode[i] = 1;
                timer[i] = 0;
            }
            switch (mode[i]) {
            case 0:
                if (timer[i] >= 10) {
                    mode[i] = -1;
                }
                s = HuMathSin(timer[i] * 9.0f);
                func_8001A91C_1B51C(spr[i], s, s);
                timer[i]++;
                break;
            case 1:
                if (timer[i] >= 10) {
                    mode[i] = -1;
                    func_8001AC44_1B844(spr[i]);
                    spr[i] = -1;
                } else {
                    s = HuMathSin(timer[i] * 9.0f + 90.0f);
                    func_8001A91C_1B51C(spr[i], s, s);
                    timer[i]++;
                }
                break;
            }
            if (D_8011380C_37EF0C_MinigameParkSetup[i] > 0) {
                /* D_801138C8 is s16 pairs (lh of word i): retype it s16 [6][2] */
                func_80029760_2A360(((s16(*)[2])D_801138C8_37EFC8_MinigameParkSetup)[D_80113958_37F058_MinigameParkSetup.character[i]][0], &pos);
                pos.z -= 40.0f;
                pos.y += 150.0f;
                Hu3DCam3DToScreen(0, &pos, &scr);
                scr.unk_00 += HuMathSin(ang[i]) * 2.0f;
                scr.unk_04 += HuMathSin(ang[i]) * 2.0f;
                ang[i] += 30;
                if (ang[i] > 360) {
                    ang[i] -= 360;
                }
                espPosSet(spr[i], scr.unk_00, scr.unk_04);
            }
        }
    }
}

/* Game length: the clock model lifts in, the stick picks one of its three parts (lite,
   standard, full), A spins the clock hands to the choice and stores it in
   D_80113958.gameLength, B sinks the clock away. Returns 1 on A, 0 on B. */
#ifdef NON_MATCHING
/* masked 27: retail keeps result in s7 and tests it through a copy to v0 ("move v0,s7;
   beqz v0") before the A path; this C tests it in place (one instruction short) and the
   allocator then picks s5 for it. Everything else matches. */
s32 func_80109478_374B78_MinigameParkSetup(void) {
    Vec base;
    Vec pos;
    Matrix4f mtx;
    Vec2f scr;
    HmfMotionObj* part[3];
    HmfMotionObj* hand1;
    HmfMotionObj* hand2;
    HmfMotionObj* hand3;
    s16 motion;
    s16 model;
    s16 i;
    s16 j;
    s16 sel;
    s32 result;
    s16 names;
    f32 angle;
    f32 target;
    f32 d;
    f32 total;

    motion = D_801139BE_37F0BE_MinigameParkSetup;
    if (D_800CD414_CE014 != 2) {
        model = D_801138FE_37EFFE_MinigameParkSetup;
    } else {
        model = D_8011390E_37F00E_MinigameParkSetup[0];
    }
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        func_800298A4_2A4A4(model, 4, 0);
        func_8002C9C0_2D5C0(model, motion);
        func_80029E80_2AA80(model, 1, 1);
        func_80029760_2A360(model, &base);
        pos = base;
        pos.z += 1200.0f;
        PlaySound(0xAC);
        func_80029714_2A314(model, pos.x, pos.y, pos.z);
        for (i = 0; i < 21; i++) {
            pos.z = (1.0f - HuMathSin(i * 4.5f)) * 1200.0f + base.z;
            func_80029714_2A314(model, pos.x, pos.y, pos.z);
            HuPrcVSleep();
        }
        func_80029E80_2AA80(model, 1, 0);
        PlaySound(0xB8);
        while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
            HuPrcVSleep();
        }
        func_80029E80_2AA80(model, 1, 1);
    } else {
        if (D_800CD414_CE014 != 2) {
            func_80029760_2A360(model, &base);
            for (i = 0; i < 21; i++) {
                func_80029714_2A314(model, base.x, base.y, base.z - HuMathSin(i * 4.5f) * 300.0f);
                HuPrcVSleep();
            }
        }
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 0x27, model);
        func_80029760_2A360(model, &base);
        pos = base;
    }
    names = D_800CD414_CE014 == 2 ? 3 : 0;
    for (j = 0; j < 3; j++) {
        func_80023554_24154(model, func_80029CE4_2A8E4(model), D_801134A0_37EBA0_MinigameParkSetup[names + j], mtx);
        /* 80112910 is (s16 model, Vec2f* out, Matrix4f mtx) */
        ((void (*)(s16, Vec2f*, Matrix4f))func_80112910_37E010_MinigameParkSetup)(model, &scr, mtx);
        func_8011060C_37BD0C_MinigameParkSetup(j, &scr, 5, 0);
        part[j] = func_8002A9F4_2B5F4(model, D_801134A0_37EBA0_MinigameParkSetup[names + j]);
    }
    func_80107604_372D04_MinigameParkSetup();
    D_8011393C_37F03C_MinigameParkSetup = 0;
    func_8011170C_37CE0C_MinigameParkSetup(0);
    D_8011392C_37F02C_MinigameParkSetup = 1;
    HuPrcSleep(5);
    if (D_800CD414_CE014 != 2) {
        func_80110350_37BA50_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup + 0x6A);
    } else {
        func_80110350_37BA50_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup + 0x6A1);
    }
    func_801103A4_37BAA4_MinigameParkSetup();
    angle = 0.0f;
    while (1) {
        if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
            || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
            j = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, 3, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
            if (j != -1) {
                PlaySound(1);
                part[D_8011393C_37F03C_MinigameParkSetup]->unk40.x = part[D_8011393C_37F03C_MinigameParkSetup]->unk40.y = 1.0f;
                func_8011175C_37CE5C_MinigameParkSetup(j);
                HuPrcSleep(5);
                if (D_800CD414_CE014 != 2) {
                    func_80110350_37BA50_MinigameParkSetup(j + 0x6A);
                } else {
                    func_80110350_37BA50_MinigameParkSetup(j + 0x6A1);
                }
                func_801103A4_37BAA4_MinigameParkSetup();
                D_8011393C_37F03C_MinigameParkSetup = j;
                angle = 0.0f;
            }
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x4000) {
            PlaySound(4);
            result = 0;
            sel = -1;
            break;
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x8000) {
            func_80088604_89204(D_8011381A_37EF1A_MinigameParkSetup, 2, 3, 10);
            sel = D_8011393C_37F03C_MinigameParkSetup;
            result = 1;
            break;
        }
        angle += 30.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        part[D_8011393C_37F03C_MinigameParkSetup]->unk40.x = func_800B7890_B8490(angle) * 0.2f + 1.0f;
        part[D_8011393C_37F03C_MinigameParkSetup]->unk40.y = func_800B7890_B8490(angle) * 0.2f + 1.0f;
        HuPrcVSleep();
    }
    D_8011392C_37F02C_MinigameParkSetup = 0;
    part[D_8011393C_37F03C_MinigameParkSetup]->unk40.x = part[D_8011393C_37F03C_MinigameParkSetup]->unk40.y = 1.0f;
    if (result != 0) {
        PlaySound(0xB2);
        hand1 = func_8002A9F4_2B5F4(model, "tokei_hari");
        hand2 = func_8002A9F4_2B5F4(model, "tokei_hari2");
        hand3 = func_8002A9F4_2B5F4(model, "tokei_hari3");
        if (sel == 0) {
            target = 0.0f;
        } else if (sel == 1) {
            target = 240.0f;
        } else {
            target = 120.0f;
        }
        d = hand1->unk34.z - target;
        if ((d < 0.0f ? -d : d) > 120.0f) {
            d = -(d / 2.0f);
        }
        if (d < 0.0f) {
            d = 240.0f;
        }
        total = d + 360.0f;
        for (i = 0; i < 21; i++) {
            hand1->unk34.z -= total / 20.0f;
            if (hand1->unk34.z < 0.0f) {
                hand1->unk34.z += 360.0f;
            }
            hand2->unk34.z -= total / 40.0f;
            if (hand2->unk34.z < 0.0f) {
                hand2->unk34.z += 360.0f;
            }
            hand3->unk34.z -= total / 10.0f;
            if (hand3->unk34.z < 0.0f) {
                hand3->unk34.z += 360.0f;
            }
            HuPrcVSleep();
        }
        hand1->unk34.z = target;
        PlaySound(0xB3);
        for (i = 0; i < 11; i++) {
            hand1->unk40.x = hand1->unk40.y = hand1->unk40.z = HuMathSin(i * 18.0f) * 0.5f + 1.0f;
            HuPrcVSleep();
        }
        hand1->unk40.x = hand1->unk40.y = hand1->unk40.z = 1.0f;
        if (D_800CD414_CE014 != 2) {
            for (i = 0; i < 11; i++) {
                pos.z = HuMathSin(i * 9.0f) * 300.0f + base.z;
                func_80029714_2A314(model, pos.x, pos.y, pos.z);
                HuPrcVSleep();
            }
        }
        if (sel == 0) {
            D_80113958_37F058_MinigameParkSetup.gameLength = 0;
        } else if (sel == 1) {
            D_80113958_37F058_MinigameParkSetup.gameLength = 1;
        } else {
            D_80113958_37F058_MinigameParkSetup.gameLength = 2;
        }
    } else {
        PlaySound(0xB8);
        func_80029E80_2AA80(model, 5, 4);
        func_80029FE4_2ABE4(model, 2.0f);
        while (func_80029CE4_2A8E4(model) > 0.0f) {
            HuPrcVSleep();
        }
        for (i = 0; i < 11; i++) {
            pos.z = (1.0f - func_800B7890_B8490(i * 9.0f)) * 1200.0f + base.z;
            func_80029714_2A314(model, pos.x, pos.y, pos.z);
            HuPrcVSleep();
        }
        func_800298A4_2A4A4(model, 4, 4);
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 0x27, model);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80109478_374B78_MinigameParkSetup);
#endif

/* Slides the mode's panel model out (dir 0: to z = 1200, else to z = -1200) over 16 frames
   after its motion has run, then parks its motion. */
void func_8010A02C_37572C_MinigameParkSetup(s16 dir) {
    s16 model;
    Vec start;
    Vec pos;
    f32 side;
    s16 i;

    if (D_800CD414_CE014 != 2) {
        model = D_801138FE_37EFFE_MinigameParkSetup;
    } else {
        model = D_8011390E_37F00E_MinigameParkSetup[0];
    }
    func_80029E80_2AA80(model, 5, 4);
    func_80029FE4_2ABE4(model, 2.0f);
    while (func_80029CE4_2A8E4(model) > 0.0f) {
        HuPrcVSleep();
    }
    func_80029760_2A360(model, &pos);
    start = pos;
    if (dir != 0) {
        side = -1.0f;
    } else {
        side = 1.0f;
    }
    for (i = 0; i < 16; i++) {
        pos.z = (1.0f - func_800B7890_B8490(i * 6.0f)) * (side * 1200.0f - start.z) + start.z;
        func_80029714_2A314(model, pos.x, pos.y, pos.z);
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(model, 4, 4);
}


__asm__(".section .rodata");
const char D_801136E8_37EDE8_MinigameParkSetup[] = "bns_panel";

/* Bonus on/off: the two bonus-panel models lift in, the stick picks one, A sends the other
   away and asks 0x71 (all set?); 0x72 then 0x6E brings the other back (returns 0 with
   D_80113782 = 1 to ask again), otherwise everything sinks away, the CPU players' icons
   are cleared and D_80113958.bonus = (choice != 1). B sinks both and returns -1.
   Returns 1 when the setup is done, 0 to go on, -1 to go back. */
#ifdef NON_MATCHING
/* masked 222: D_80113900's copy goes through a stack temporary in retail (lhu/sh, then
   lwl/lwr, as 80103F38's); from there the allocator differs (result spills, the float
   temporaries shift by one register, the sel-indexed addresses of the slide loops are
   hoisted here and recomputed each frame in retail). Logic checked against the asm. */
s32 func_8010A1E8_3758E8_MinigameParkSetup(void) {
    Ovl58Pair models;
    s16 done[2];
    Vec base[2];
    Vec pos[2];
    s16 i;
    s16 frame;
    s16 sel;
    s16 result;
    s16 other;
    f32 t;
    f32 dist;

    models = D_80113900_37F000_MinigameParkSetup;
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        for (i = 0; i < 2; i++) {
            func_800298A4_2A4A4(models.v[i], 4, 0);
            func_8002C9C0_2D5C0(models.v[i], D_801139C4_37F0C4_MinigameParkSetup);
            func_80029C74_2A874(models.v[i], 30.0f);
            func_80029E80_2AA80(models.v[i], 1, 1);
            base[i].x = pos[i].x = D_800FC834_FD434[models.v[i]].pos.x;
            base[i].y = pos[i].y = D_800FC834_FD434[models.v[i]].pos.y;
            base[i].z = pos[i].z = D_800FC834_FD434[models.v[i]].pos.z;
            pos[i].z += 1200.0f;
            func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
            done[i] = 0;
        }
        D_8011382E_37EF2E_MinigameParkSetup[0] = func_8001A2F8_1AEF8(0x90089);
        D_80113832_37EF32_MinigameParkSetup[0] = func_8001AAAC_1B6AC(D_8011382E_37EF2E_MinigameParkSetup[0], 0, 1);
        func_8001A6BC_1B2BC(D_80113832_37EF32_MinigameParkSetup[0], 0x100);
        func_8001A788_1B388(D_80113832_37EF32_MinigameParkSetup[0], 100);
        D_8011382E_37EF2E_MinigameParkSetup[1] = func_8001A2F8_1AEF8(0x9008A);
        D_80113832_37EF32_MinigameParkSetup[1] = func_8001AAAC_1B6AC(D_8011382E_37EF2E_MinigameParkSetup[1], 0, 1);
        func_8001A6BC_1B2BC(D_80113832_37EF32_MinigameParkSetup[1], 0x100);
        func_8001A788_1B388(D_80113832_37EF32_MinigameParkSetup[1], 100);
        frame = 0;
        while (1) {
            for (i = 0; i < 2; i++) {
                t = frame - (2 - i) * 10;
                if (t == 0.0f) {
                    PlaySound(0xAB);
                }
                if ((t > 0.0f) & (t <= 20.0f)) {
                    pos[i].z = (1.0f - HuMathSin(t * 4.5f)) * 1200.0f + base[i].z;
                    if (t == 10.0f) {
                        PlaySound(0xB1);
                        func_80029E80_2AA80(models.v[i], 1, 0);
                        func_80029FE4_2ABE4(models.v[i], 1.5f);
                    }
                    func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                } else if ((done[i] == 0) & (t > 20.0f)) {
                    if (func_80029E14_2AA14(models.v[i]) != D_801139C0_37F0C0_MinigameParkSetup[0]) {
                        if (func_80029CE4_2A8E4(models.v[i]) >= func_80029D0C_2A90C(models.v[i])) {
                            func_8002C9C0_2D5C0(models.v[i], D_801139C0_37F0C0_MinigameParkSetup[0]);
                        }
                    } else if (func_80029CE4_2A8E4(models.v[i]) >= func_80029D0C_2A90C(models.v[i])) {
                        func_80029E80_2AA80(models.v[i], 1, 1);
                        done[i] = 1;
                    }
                }
            }
            for (i = 0; i < 2; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
                func_801105B8_37BCB8_MinigameParkSetup(i, D_80113832_37EF32_MinigameParkSetup[i], 0, 8);
                func_8010B6B4_376DB4_MinigameParkSetup(D_80113832_37EF32_MinigameParkSetup[i], D_80113836_37EF36_MinigameParkSetup[i]);
            }
            if (done[0] != 0 && done[1] != 0) {
                break;
            }
            frame++;
            HuPrcVSleep();
        }
    } else {
        for (i = 0; i < 2; i++) {
            func_80029760_2A360(models.v[i], &pos[i]);
            func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 0x28, models.v[i]);
            func_80029760_2A360(models.v[i], &base[i]);
            func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
        }
    }
    D_80113782_37EE82_MinigameParkSetup = 0;
    func_80107604_372D04_MinigameParkSetup();
    D_8011393C_37F03C_MinigameParkSetup = 0;
    func_8011170C_37CE0C_MinigameParkSetup(0);
    D_8011392C_37F02C_MinigameParkSetup = 1;
    HuPrcSleep(5);
    espPosSet(D_80113832_37EF32_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup],
              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][0],
              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][1] - 3);
    func_80110350_37BA50_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup + 0x6F);
    func_801103A4_37BAA4_MinigameParkSetup();
    while (1) {
        if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
            || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
            i = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, 2, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
            if (i != -1) {
                PlaySound(1);
                func_8011175C_37CE5C_MinigameParkSetup(i);
                for (frame = 1; frame < 4; frame++) {
                    espPosSet(D_80113832_37EF32_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup],
                              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][0],
                              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][1] + frame);
                    HuPrcVSleep();
                }
                for (frame = 1; frame < 4; frame++) {
                    espPosSet(D_80113832_37EF32_MinigameParkSetup[i],
                              D_80113836_37EF36_MinigameParkSetup[i][0],
                              D_80113836_37EF36_MinigameParkSetup[i][1] - frame);
                    HuPrcVSleep();
                }
                func_80110350_37BA50_MinigameParkSetup(i + 0x6F);
                func_801103A4_37BAA4_MinigameParkSetup();
                D_8011393C_37F03C_MinigameParkSetup = i;
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
            func_80088604_89204(D_8011381A_37EF1A_MinigameParkSetup, 2, 3, 10);
            result = 1;
            sel = D_8011393C_37F03C_MinigameParkSetup;
            break;
        }
        HuPrcVSleep();
    }
    D_8011392C_37F02C_MinigameParkSetup = 0;
    espPosSet(D_80113832_37EF32_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup],
              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][0],
              D_80113836_37EF36_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup][1]);
    if (result != 0) {
        PlaySound(0xB1);
        for (i = 0; i < 2; i++) {
            if (sel != i) {
                func_80029E80_2AA80(models.v[i], 5, 4);
            }
            func_80029FE4_2ABE4(models.v[i], 2.0f);
        }
        for (frame = 0; frame < 15; frame++) {
            for (i = 0; i < 2; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
            }
            HuPrcVSleep();
        }
        dist = 1200.0f;
        if (sel == 0) {
            dist = -1200.0f;
        }
        for (frame = 0; frame < 11; frame++) {
            t = frame * 9.0f;
            D_800FC834_FD434[models.v[sel]].pos.z = (1.0f - func_800B7890_B8490(t)) * (-150.0f - base[sel].z) + base[sel].z;
            func_801104FC_37BBFC_MinigameParkSetup(models.v[sel], D_80113832_37EF32_MinigameParkSetup[sel], D_801136E8_37EDE8_MinigameParkSetup);
            D_800FC834_FD434[models.v[sel ^ 1]].pos.z = (1.0f - func_800B7890_B8490(t)) * dist + base[sel ^ 1].z;
            func_801104FC_37BBFC_MinigameParkSetup(models.v[sel ^ 1], D_80113832_37EF32_MinigameParkSetup[sel ^ 1], D_801136E8_37EDE8_MinigameParkSetup);
            HuPrcVSleep();
        }
        func_80110350_37BA50_MinigameParkSetup(0x71);
        if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
            func_80110350_37BA50_MinigameParkSetup(0x72);
            if (func_801103A4_37BAA4_MinigameParkSetup() == 0) {
                result = 0;
            } else {
                /* Change it: the other panel comes back and the choice is asked again. */
                func_80110350_37BA50_MinigameParkSetup(0x6E);
                func_801103A4_37BAA4_MinigameParkSetup();
                other = models.v[sel ^ 1];
                if (sel == 0) {
                    dist = -1200.0f;
                    func_8002C9C0_2D5C0(other, D_801139C4_37F0C4_MinigameParkSetup);
                } else {
                    dist = 1200.0f;
                    func_8002C9C0_2D5C0(other, D_801139C6_37F0C6_MinigameParkSetup[0]);
                }
                func_80029FE4_2ABE4(other, 1.5f);
                func_80029C74_2A874(other, 30.0f);
                for (frame = 0; frame < 11; frame++) {
                    t = frame * 9.0f;
                    D_800FC834_FD434[models.v[sel]].pos.z = func_800B7890_B8490(t) * (-150.0f - base[sel].z) + base[sel].z;
                    func_801104FC_37BBFC_MinigameParkSetup(models.v[sel], D_80113832_37EF32_MinigameParkSetup[sel], D_801136E8_37EDE8_MinigameParkSetup);
                    D_800FC834_FD434[models.v[sel ^ 1]].pos.z = (1.0f - HuMathSin(t)) * dist + base[sel ^ 1].z;
                    func_801104FC_37BBFC_MinigameParkSetup(models.v[sel ^ 1], D_80113832_37EF32_MinigameParkSetup[sel ^ 1], D_801136E8_37EDE8_MinigameParkSetup);
                    HuPrcVSleep();
                }
                while (func_80029CE4_2A8E4(other) < func_80029D0C_2A90C(other)) {
                    func_801104FC_37BBFC_MinigameParkSetup(other, D_80113832_37EF32_MinigameParkSetup[sel ^ 1], D_801136E8_37EDE8_MinigameParkSetup);
                    HuPrcVSleep();
                }
                PlaySound(0xB1);
                func_8002C9C0_2D5C0(other, D_801139C0_37F0C0_MinigameParkSetup[0]);
                func_80029E80_2AA80(other, 5, 0);
                for (frame = 0; frame < 15; frame++) {
                    for (i = 0; i < 2; i++) {
                        func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
                    }
                    HuPrcVSleep();
                }
                D_80113782_37EE82_MinigameParkSetup = 1;
                return 0;
            }
        } else {
            PlaySound(GwSystem.current_board_index == 5 ? 0xC4 : 0x125);
        }
        func_80029E80_2AA80(models.v[sel], 5, 4);
        func_80029E80_2AA80(D_801138FE_37EFFE_MinigameParkSetup, 5, 4);
        func_80029FE4_2ABE4(D_801138FE_37EFFE_MinigameParkSetup, 2.0f);
        for (frame = 0; frame < 15; frame++) {
            for (i = 0; i < 2; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
            }
            HuPrcVSleep();
        }
        PlaySound(0xB8);
        for (i = 0; i < 2; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139C4_37F0C4_MinigameParkSetup);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 1; frame < 11; frame++) {
            t = frame * 100;
            D_800FC834_FD434[models.v[sel]].pos.z -= t;
            func_801104FC_37BBFC_MinigameParkSetup(models.v[sel], D_80113832_37EF32_MinigameParkSetup[sel], D_801136E8_37EDE8_MinigameParkSetup);
            if (result == 0) {
                D_800FC834_FD434[models.v[sel ^ 1]].pos.z -= t;
                func_801104FC_37BBFC_MinigameParkSetup(models.v[sel ^ 1], D_80113832_37EF32_MinigameParkSetup[sel ^ 1], D_801136E8_37EDE8_MinigameParkSetup);
            }
            D_800FC834_FD434[D_801138FE_37EFFE_MinigameParkSetup].pos.z -= 100.0f;
            HuPrcVSleep();
        }
        func_800298A4_2A4A4(D_801138FE_37EFFE_MinigameParkSetup, 4, 4);
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 0x27, D_801138FE_37EFFE_MinigameParkSetup);
        for (i = D_80113958_37F058_MinigameParkSetup.humans; i < 4; i++) {
            D_80113804_37EF04_MinigameParkSetup[i] = -1;
        }
        D_80113958_37F058_MinigameParkSetup.bonus = sel != 1;
    } else {
        PlaySound(0xB1);
        for (i = 0; i < 2; i++) {
            func_80029E80_2AA80(models.v[i], 5, 4);
            func_80029FE4_2ABE4(models.v[i], 2.0f);
        }
        for (frame = 0; frame < 15; frame++) {
            for (i = 0; i < 2; i++) {
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
            }
            HuPrcVSleep();
        }
        PlaySound(0xB8);
        for (i = 0; i < 2; i++) {
            func_8002C9C0_2D5C0(models.v[i], D_801139C6_37F0C6_MinigameParkSetup[0]);
            func_80029FE4_2ABE4(models.v[i], 1.5f);
        }
        for (frame = 0; frame < 11; frame++) {
            for (i = 0; i < 2; i++) {
                pos[i].z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 1200.0f + base[i].z;
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_80113832_37EF32_MinigameParkSetup[i], D_801136E8_37EDE8_MinigameParkSetup);
            }
            HuPrcVSleep();
        }
        result = -1;
    }
    for (i = 0; i < 2; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 4);
    }
    for (i = 0; i < 2; i++) {
        func_8001AC44_1B844(D_80113832_37EF32_MinigameParkSetup[i]);
        SprAnimKill(D_8011382E_37EF2E_MinigameParkSetup[i]);
    }
    for (i = 0; i < 2; i++) {
        func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, i + 0x28, models.v[i]);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010A1E8_3758E8_MinigameParkSetup);
#endif

/* The screen position of esprite spr. */
#ifdef NON_MATCHING
/* masked 4: retail loads D_800F93FC after sign-extending spr and before the index
   arithmetic; every C spelling tried schedules one or the other differently. */
void func_8010B6B4_376DB4_MinigameParkSetup(s16 spr, s16* out) {
    Ovl58Esprite* e;

    e = (Ovl58Esprite*)D_800F93FC_F9FFC;
    out[0] = e[spr].x;
    out[1] = e[spr].y;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6B4_376DB4_MinigameParkSetup);
#endif


__asm__(".section .rodata");
const char D_801136F4_37EDF4_MinigameParkSetup[] = "mode_panel";

/* Mode 2's choice: one to three mode-panel models (by the D_80113898 count and flags
   D_80113926/D_8011394E) lift in, the stick picks one, A lifts it to the front and sends
   the others away (choice in D_80113816), B sinks them all. Returns 1 on A, 0 on B. */
#ifdef NON_MATCHING
/* masked 112: D_80113908's copy goes through a stack temporary in retail (as 80103F38's
   and 8010A1E8's), the frame layout and spills follow from it. Calls and stores agree
   (n64nmcmp); logic checked against the asm. */
s32 func_8010B6E8_376DE8_MinigameParkSetup(void) {
    Ovl58Triple models;
    s16 done[3];
    Vec base[3];
    Vec pos[3];
    s16 i;
    s16 frame;
    s16 cnt;
    s16 sel;
    s16 result;
    s16 n;
    f32 dir;
    f32 t;
    f32 f;
    f32 angle;

    models = *(Ovl58Triple*)D_80113908_37F008_MinigameParkSetup;
    n = 1;
    if (D_80113898_37EF98_MinigameParkSetup[0] >= 20) {
        n = 2;
    }
    if (D_80113898_37EF98_MinigameParkSetup[0] >= 30 && (D_80113926_37F026_MinigameParkSetup[0] != 0 || D_8011394E_37F04E_MinigameParkSetup[0] != 0)) {
        n++;
    }
    for (i = 0; i < n; i++) {
        func_800298A4_2A4A4(models.v[i], 4, 0);
        func_80029E80_2AA80(models.v[i], 2, 2);
        func_80029FE4_2ABE4(models.v[i], 2.0f);
        base[i] = D_801134B8_37EBB8_MinigameParkSetup.pos[n - 1][i];
        pos[i] = base[i];
        pos[i].z += 1200.0f;
        if (D_80113782_37EE82_MinigameParkSetup == 0 || i != D_80113816_37EF16_MinigameParkSetup) {
            func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
        }
        done[i] = 0;
    }
    if (D_80113530_37EC30_MinigameParkSetup[0] == -1) {
        D_80113530_37EC30_MinigameParkSetup[0] = func_8001A2F8_1AEF8(0x90088);
        for (i = 0; i < n; i++) {
            D_8011383E_37EF3E_MinigameParkSetup[i] = func_8001AAAC_1B6AC(D_80113530_37EC30_MinigameParkSetup[0], 0, 1);
            func_8001A788_1B388(D_8011383E_37EF3E_MinigameParkSetup[i], 5);
            func_8001A6BC_1B2BC(D_8011383E_37EF3E_MinigameParkSetup[i], 0x100);
            D_80113844_37EF44_MinigameParkSetup[i] = func_8001A2F8_1AEF8(D_801134B8_37EBB8_MinigameParkSetup.sprite[i]);
            D_8011384A_37EF4A_MinigameParkSetup[i] = func_8001AAAC_1B6AC(D_80113844_37EF44_MinigameParkSetup[i], 0, 1);
            func_8001A788_1B388(D_8011384A_37EF4A_MinigameParkSetup[i], 5);
            func_8001A6BC_1B2BC(D_8011384A_37EF4A_MinigameParkSetup[i], 0x100);
        }
    }
    if (D_80113782_37EE82_MinigameParkSetup != 0) {
        /* Back from a later step: the chosen panel comes back down from the front. */
        func_80029760_2A360(models.v[D_80113816_37EF16_MinigameParkSetup], &base[D_80113816_37EF16_MinigameParkSetup]);
        for (frame = 0; frame < 16; frame++) {
            func_80029714_2A314(models.v[D_80113816_37EF16_MinigameParkSetup],
                                base[D_80113816_37EF16_MinigameParkSetup].x,
                                base[D_80113816_37EF16_MinigameParkSetup].y,
                                (1.0f - func_800B7890_B8490(frame * 6.0f)) * (-1200.0f - base[D_80113816_37EF16_MinigameParkSetup].z) + base[D_80113816_37EF16_MinigameParkSetup].z);
            func_801104FC_37BBFC_MinigameParkSetup(models.v[D_80113816_37EF16_MinigameParkSetup], D_8011383E_37EF3E_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup], D_801136F4_37EDF4_MinigameParkSetup);
            func_80108BA8_3742A8_MinigameParkSetup(D_8011384A_37EF4A_MinigameParkSetup[D_80113816_37EF16_MinigameParkSetup]);
            HuPrcVSleep();
        }
        base[D_80113816_37EF16_MinigameParkSetup] = D_801134B8_37EBB8_MinigameParkSetup.pos[n - 1][D_80113816_37EF16_MinigameParkSetup];
    }
    PlaySound(0xBD);
    dir = -1.0f;
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        dir = 1.0f;
    }
    frame = 0;
    while (1) {
        for (i = 0; i < n; i++) {
            if (dir > 0.0f) {
                t = frame - (2 - i) * 10;
            } else {
                t = frame - i * 10;
            }
            if ((t > 0.0f) & (t <= 20.0f)) {
                pos[i].z = (1.0f - HuMathSin(t * 4.5f)) * 1200.0f * dir + base[i].z;
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
            } else if ((done[i] == 0) & (t > 25.0f)) {
                done[i] = 1;
            }
        }
        for (i = 0, cnt = 0; i < n; i++) {
            func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_8011383E_37EF3E_MinigameParkSetup[i], D_801136F4_37EDF4_MinigameParkSetup);
            func_80108BA8_3742A8_MinigameParkSetup(D_8011384A_37EF4A_MinigameParkSetup[i]);
            func_801105B8_37BCB8_MinigameParkSetup(i, D_8011383E_37EF3E_MinigameParkSetup[i], 10, 20);
            if (done[i] != 0) {
                cnt++;
            }
        }
        if (cnt == n) {
            break;
        }
        frame++;
        HuPrcVSleep();
    }
    func_80107604_372D04_MinigameParkSetup();
    D_8011393C_37F03C_MinigameParkSetup = 0;
    func_8011170C_37CE0C_MinigameParkSetup(0);
    D_8011392C_37F02C_MinigameParkSetup = 1;
    func_80110350_37BA50_MinigameParkSetup(0x68C);
    HuPrcSleep(5);
    angle = 0.0f;
    while (1) {
        if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
            || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
            i = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, n, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
            if (i != -1) {
                PlaySound(1);
                func_8011175C_37CE5C_MinigameParkSetup(i);
                angle = 0.0f;
                func_8001A91C_1B51C(D_8011384A_37EF4A_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup], 1.0f, 1.0f);
                HuPrcSleep(6);
                D_8011393C_37F03C_MinigameParkSetup = i;
                func_80110350_37BA50_MinigameParkSetup(i + 0x68C);
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
            sel = D_8011393C_37F03C_MinigameParkSetup;
            result = 1;
            break;
        }
        f = func_800B7890_B8490(angle) * 0.1f + 0.9f;
        func_8001A91C_1B51C(D_8011384A_37EF4A_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup], f, f);
        angle += 20.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_8011384A_37EF4A_MinigameParkSetup[D_8011393C_37F03C_MinigameParkSetup], 1.0f, 1.0f);
    D_8011392C_37F02C_MinigameParkSetup = 0;
    if (result != 0) {
        /* The chosen panel comes to the front, the others sink away. */
        for (frame = 0; frame < 21; frame++) {
            for (i = 0; i < n; i++) {
                if (i == sel) {
                    if (frame < 16) {
                        f = 1.0f - func_800B7890_B8490(frame * 6.0f);
                        pos[i].y = f * (550.0f - base[i].y) + base[i].y;
                        pos[i].z = f * (380.0f - base[i].z) + base[i].z;
                    }
                } else if (frame >= 6) {
                    f = 1.0f - func_800B7890_B8490((frame - 5) * 6.0f);
                    pos[i].z = f * (-1200.0f - base[i].z) + base[i].z;
                }
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_8011383E_37EF3E_MinigameParkSetup[i], D_801136F4_37EDF4_MinigameParkSetup);
                func_80108BA8_3742A8_MinigameParkSetup(D_8011384A_37EF4A_MinigameParkSetup[i]);
            }
            HuPrcVSleep();
        }
        D_80113816_37EF16_MinigameParkSetup = sel;
    } else {
        for (frame = 0; frame < 11; frame++) {
            for (i = 0; i < n; i++) {
                pos[i].z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 1200.0f + base[i].z;
                func_80029714_2A314(models.v[i], pos[i].x, pos[i].y, pos[i].z);
                func_801104FC_37BBFC_MinigameParkSetup(models.v[i], D_8011383E_37EF3E_MinigameParkSetup[i], D_801136F4_37EDF4_MinigameParkSetup);
                func_80108BA8_3742A8_MinigameParkSetup(D_8011384A_37EF4A_MinigameParkSetup[i]);
            }
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 3; i++) {
        if (sel != i) {
            func_800298A4_2A4A4(models.v[i], 4, 4);
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6E8_376DE8_MinigameParkSetup);
#endif

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

/* Handicaps: the model lifts the coin panel in (six icons, D_8011354C coins), each human in
   turn (message 0x696 + character) picks one with the stick and A; B steps back a player, or
   leaves at the first. Stores the coins in D_80113958.handicap (0 on B) and the picks in
   D_8011380C. Returns 1 when all four are picked, 0 on B. */
s32 func_8010C6C8_377DC8_MinigameParkSetup(void) {
    s16 choice[4];
    s16 anim[6];
    s16 icon[6];
    Vec pos;
    u16 model;
    s16 panelAnim;
    s16 panel;
    s16 result;
    s16 n;
    s16 i;
    s16 frame;
    f32 dir;

    model = D_801138EC_37EFEC_MinigameParkSetup[0];
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
    } else {
        for (i = 0; i < 4; i++) {
            D_8011380C_37EF0C_MinigameParkSetup[i] = -1;
        }
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
    }
    func_801104DC_37BBDC_MinigameParkSetup();
    func_80029C74_2A874(model, 30.0f);
    func_80029E80_2AA80(model, 1, 1);
    func_80029760_2A360(model, &pos);
    panelAnim = func_8001A2F8_1AEF8(0x90084);
    panel = func_8001AAAC_1B6AC(panelAnim, 0, 1);
    func_8001A6BC_1B2BC(panel, 0x100);
    espPosSet(panel, -100, -100);
    for (n = 0; n < 6; n++) {
        anim[n] = func_8001A2F8_1AEF8(D_80113534_37EC34_MinigameParkSetup[n]);
        icon[n] = func_8001AAAC_1B6AC(anim[n], 0, 1);
        func_8001A6BC_1B2BC(icon[n], 0x100);
        espPosSet(icon[n], -100, -100);
        if (n & 1) {
            HuPrcVSleep();
        }
    }
    func_800298A4_2A4A4(model, 4, 0);
    PlaySound(0xAC);
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        dir = 1.0f;
    } else {
        dir = -1.0f;
    }
    for (frame = 0; frame < 20; frame++) {
        D_800FC834_FD434[(s16)model].pos.z = (1.0f - HuMathSin(frame * 4.5f)) * 1200.0f * dir + pos.z;
        if (frame == 15) {
            func_80029E80_2AA80(model, 1, 0);
            func_80029FE4_2ABE4(model, 1.5f);
        }
        func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
        for (n = 0; n < 6; n++) {
            func_80106A00_372100_MinigameParkSetup(icon[n], n);
        }
        HuPrcVSleep();
    }
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model))) {
            break;
        }
        func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
        for (n = 0; n < 6; n++) {
            func_80106A00_372100_MinigameParkSetup(icon[n], n);
        }
        HuPrcVSleep();
    }
    PlaySound(0xB1);
    func_8002C9C0_2D5C0(model, D_801139AC_37F0AC_MinigameParkSetup);
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < 30.0f)) {
            break;
        }
        func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
        for (n = 0; n < 6; n++) {
            func_80106A00_372100_MinigameParkSetup(icon[n], n);
            func_801105B8_37BCB8_MinigameParkSetup(n, icon[n], 0, 2);
        }
        HuPrcVSleep();
    }
    func_80029E80_2AA80(model, 1, 1);
    func_80107604_372D04_MinigameParkSetup();
    func_8011170C_37CE0C_MinigameParkSetup(0);
    D_8011393C_37F03C_MinigameParkSetup = 0;
    D_8011392C_37F02C_MinigameParkSetup = 1;
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        choice[i] = 0;
    }
    n = 0;
    func_80110350_37BA50_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[0] + 0x696);
    func_801103A4_37BAA4_MinigameParkSetup();
    result = -1;
    while (1) {
        if ((ContStkX[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkX[D_8011381A_37EF1A_MinigameParkSetup] : ContStkX[D_8011381A_37EF1A_MinigameParkSetup]) >= 31
            || (ContStkY[D_8011381A_37EF1A_MinigameParkSetup] < 0 ? -ContStkY[D_8011381A_37EF1A_MinigameParkSetup] : ContStkY[D_8011381A_37EF1A_MinigameParkSetup]) >= 31) {
            i = func_80110678_37BD78_MinigameParkSetup(D_8011393C_37F03C_MinigameParkSetup, 6, -ContStkX[D_8011381A_37EF1A_MinigameParkSetup], ContStkY[D_8011381A_37EF1A_MinigameParkSetup]);
            if (i != -1) {
                PlaySound(1);
                func_8011175C_37CE5C_MinigameParkSetup(i);
                HuPrcSleep(6);
                D_8011393C_37F03C_MinigameParkSetup = i;
            }
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x8000) {
            PlaySound(2);
            choice[n] = D_8011393C_37F03C_MinigameParkSetup;
            D_8011380C_37EF0C_MinigameParkSetup[n] = choice[n];
            n++;
            if (n >= 4) {
                result = 1;
                break;
            }
            func_80110350_37BA50_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[n] + 0x696);
            func_801103A4_37BAA4_MinigameParkSetup();
        }
        if (ContBtnTrg[D_8011381A_37EF1A_MinigameParkSetup] & 0x4000) {
            PlaySound(4);
            if (n == 0) {
                result = 0;
                break;
            }
            n--;
            D_8011380C_37EF0C_MinigameParkSetup[n] = -1;
            func_80110350_37BA50_MinigameParkSetup(D_80113958_37F058_MinigameParkSetup.character[n] + 0x696);
            func_801103A4_37BAA4_MinigameParkSetup();
        }
        HuPrcVSleep();
    }
    D_8011392C_37F02C_MinigameParkSetup = 0;
    PlaySound(0xB1);
    func_80029E80_2AA80(model, 1, 0);
    func_80029FE4_2ABE4(model, 2.0f);
    if (result != 0) {
        for (frame = 0; frame < 15; frame++) {
            func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
            for (n = 0; n < 6; n++) {
                func_80106A00_372100_MinigameParkSetup(icon[n], n);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 10; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = pos.z - frame * 100;
            func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
            for (n = 0; n < 6; n++) {
                func_80106A00_372100_MinigameParkSetup(icon[n], n);
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            D_80113958_37F058_MinigameParkSetup.handicap[i] = D_8011354C_37EC4C_MinigameParkSetup[choice[i]];
        }
    } else {
        for (frame = 0; frame < 15; frame++) {
            func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
            for (n = 0; n < 6; n++) {
                func_80106A00_372100_MinigameParkSetup(icon[n], n);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 11; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 600.0f + pos.z;
            func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);
            for (n = 0; n < 6; n++) {
                func_80106A00_372100_MinigameParkSetup(icon[n], n);
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            D_80113958_37F058_MinigameParkSetup.handicap[i] = 0;
        }
    }
    func_800298A4_2A4A4(model, 4, 4);
    func_8001AC44_1B844(panel);
    SprAnimKill(panelAnim);
    for (n = 0; n < 6; n++) {
        func_8001AC44_1B844(icon[n]);
        SprAnimKill(anim[n]);
    }
    func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 30, model);
    return result;
}

extern const char D_8011370C_37EE0C_MinigameParkSetup[]; /* "%2d", defined after this function */

/* One frame of the record panel: the panel on its model, the character icon and the four
   windows placed beside it. */
#define OVL58_RECORD_PANEL_FRAME()                                                                   \
    func_801104FC_37BBFC_MinigameParkSetup(model, panel, D_80113630_37ED30_MinigameParkSetup);    \
    espPosSet(icon, D_801137B0_37EEB0_MinigameParkSetup[0] + 40.0f - 68.0f,                        \
              D_801137B0_37EEB0_MinigameParkSetup[1] + 70.0f - 3.0f);                              \
    for (j = 0; j < 4; j++) {                                                                      \
        func_8010E1F0_3798F0_MinigameParkSetup(D_80113850_37EF50_MinigameParkSetup[j], j);         \
    }                                                                                              \
    HuPrcVSleep()

/* Mode 3's record to continue (D_80113826): the model lifts a panel in with four windows (the
   chapter, or chapter=step for a save; the stage message; the character's coins; the stars),
   the two characters walk in, message 0x590 asks; returns 1 to continue (the model jumps), 0
   for no (the characters walk off; D_80113782 = 1 when B was used). */
s32 func_8010D260_378960_MinigameParkSetup(void) {
    s16 sprIcon[2]; /* written, never read */
    char buf[16];
    char num[8];
    Vec pos;
    s16 w;
    u16 model;
    s16 panelAnim;
    s16 panel;
    s16 result;
    s16 iconAnim;
    s16 icon;
    s16 win;
    s16 i;
    s16 j;
    s16 frame;
    f32 dir;

    model = D_801138EC_37EFEC_MinigameParkSetup[0];
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
    } else {
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
    }
    func_80029C74_2A874(model, 30.0f);
    func_80029E80_2AA80(model, 1, 1);
    func_80029760_2A360(model, &pos);
    panelAnim = func_8001A2F8_1AEF8(0x90084);
    panel = func_8001AAAC_1B6AC(panelAnim, 0, 1);
    func_8001A6BC_1B2BC(panel, 0x100);
    espPosSet(panel, -100, -100);
    for (i = 0; i < 4; i++) {
        HuPrcVSleep();
        win = func_800888A8_894A8(D_80113554_37EC54_MinigameParkSetup[i].x, D_80113554_37EC54_MinigameParkSetup[i].y,
                                  D_80113554_37EC54_MinigameParkSetup[i].w, D_80113554_37EC54_MinigameParkSetup[i].h, 0, 4);
        D_80113850_37EF50_MinigameParkSetup[i] = win;
        func_80089284_89E84(win, 0x10000, 0x10000);
        func_80089A7C_8A67C(win, 5);
        func_80089B2C_8A72C(win, 0);
        func_80089A48_8A648(win, 0);
        func_80089C78_8A878(win, 1);
        func_80089DA0_8A9A0(win, 0xC0, 0xC0, 0xC0);
    }
    HuPrcVSleep();
    iconAnim = func_8001A2F8_1AEF8(D_8011359C_37EC9C_MinigameParkSetup[D_80113826_37EF26_MinigameParkSetup.character[0]]);
    icon = func_8001AAAC_1B6AC(iconAnim, 0, 1);
    func_8001A6BC_1B2BC(icon, 0x100);
    espPosSet(icon, -100, 68);
    HuPrcVSleep();
    if (D_8011382D_37EF2D_MinigameParkSetup == 0) {
        sprintf(buf, "%d=%d", D_80113826_37EF26_MinigameParkSetup.chapter, D_80113826_37EF26_MinigameParkSetup.step);
    } else {
        sprintf(buf, "%d", D_80113826_37EF26_MinigameParkSetup.chapter);
    }
    func_80089308_89F08(D_80113850_37EF50_MinigameParkSetup[0], buf, 0);
    func_8008D974_8E574(buf, 0);
    func_8008DACC_8E6CC(1, &w, D_80113554_37EC54_MinigameParkSetup[0].mess);
    D_80113554_37EC54_MinigameParkSetup[0].x = (136 - w) / 2;
    func_800890CC_89CCC(D_80113850_37EF50_MinigameParkSetup[0], D_80113554_37EC54_MinigameParkSetup[0].mess, -1, -1);
    func_8008DACC_8E6CC(1, &w, D_80113554_37EC54_MinigameParkSetup[1].mess - (D_80113826_37EF26_MinigameParkSetup.unk5 - 2));
    D_80113554_37EC54_MinigameParkSetup[1].x = (136 - w) / 2;
    func_800890CC_89CCC(D_80113850_37EF50_MinigameParkSetup[1],
                        D_80113554_37EC54_MinigameParkSetup[1].mess - (D_80113826_37EF26_MinigameParkSetup.unk5 - 2), -1, -1);
    sprIcon[0] = func_80089404_8A004(D_80113850_37EF50_MinigameParkSetup[2],
                                     D_80113584_37EC84_MinigameParkSetup[D_80113826_37EF26_MinigameParkSetup.character[0]], -9, 10, 0);
    sprintf(num, D_8011370C_37EE0C_MinigameParkSetup, D_80113826_37EF26_MinigameParkSetup.unk3);
    func_80089308_89F08(D_80113850_37EF50_MinigameParkSetup[2], num, 0);
    func_8008D974_8E574(num, 0);
    func_8008DACC_8E6CC(1, &w, D_80113554_37EC54_MinigameParkSetup[2].mess);
    D_80113554_37EC54_MinigameParkSetup[2].x = 80;
    func_800890CC_89CCC(D_80113850_37EF50_MinigameParkSetup[2], D_80113554_37EC54_MinigameParkSetup[2].mess, -1, -1);
    sprIcon[1] = func_80089404_8A004(D_80113850_37EF50_MinigameParkSetup[3], 0xA0172, -9, 10, 0);
    func_8008225C_82E5C(D_800F920C_F9E0C[D_80113850_37EF50_MinigameParkSetup[3]].unk_6C, sprIcon[1], 0);
    /* Retail formats into pos (its x and y are not used again). */
    sprintf((char*)&pos, D_8011370C_37EE0C_MinigameParkSetup, D_80113826_37EF26_MinigameParkSetup.unk4);
    func_8008D974_8E574((char*)&pos, 0);
    func_8008DACC_8E6CC(1, &w, D_80113554_37EC54_MinigameParkSetup[3].mess);
    D_80113554_37EC54_MinigameParkSetup[3].x = 80;
    func_80089308_89F08(D_80113850_37EF50_MinigameParkSetup[3], (char*)&pos, 0);
    func_800890CC_89CCC(D_80113850_37EF50_MinigameParkSetup[3], D_80113554_37EC54_MinigameParkSetup[3].mess, -1, -1);
    func_800298A4_2A4A4(model, 4, 0);
    PlaySound(0xAC);
    if (D_80113782_37EE82_MinigameParkSetup == 0) {
        dir = 1.0f;
    } else {
        dir = -1.0f;
    }
    func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[0], 50.0f, 0.0f, 70.0f);
    for (frame = 0; frame < 20; frame++) {
        if (frame == 10) {
            func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[1], 0.0f, 0.0f, -70.0f);
        }
        D_800FC834_FD434[(s16)model].pos.z = (1.0f - HuMathSin(frame * 4.5f)) * 1200.0f * dir + pos.z;
        if (frame == 15) {
            func_80029E80_2AA80(model, 1, 0);
            func_80029FE4_2ABE4(model, 1.5f);
        }
        OVL58_RECORD_PANEL_FRAME();
    }
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model))) {
            break;
        }
        OVL58_RECORD_PANEL_FRAME();
    }
    PlaySound(0xB1);
    func_8002C9C0_2D5C0(model, D_801139AC_37F0AC_MinigameParkSetup);
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < 30.0f)) {
            break;
        }
        OVL58_RECORD_PANEL_FRAME();
    }
    func_80029E80_2AA80(model, 1, 1);
    func_80110350_37BA50_MinigameParkSetup(0x590);
    result = func_801103A4_37BAA4_MinigameParkSetup();
    if (result == -1) {
        D_80113782_37EE82_MinigameParkSetup = 1;
    } else {
        D_80113782_37EE82_MinigameParkSetup = 0;
    }
    PlaySound(0xB1);
    func_80029E80_2AA80(model, 1, 0);
    func_80029FE4_2ABE4(model, 2.0f);
    if (result == 0) {
        result = 1;
        for (frame = 0; frame < 15; frame++) {
            OVL58_RECORD_PANEL_FRAME();
        }
        func_8002C9C0_2D5C0(model, D_801139AE_37F0AE_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 10; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = pos.z - frame * 100;
            OVL58_RECORD_PANEL_FRAME();
        }
    } else {
        result = 0;
        func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[0], 0.0f, 0.0f, -600.0f);
        func_801074CC_372BCC_MinigameParkSetup(D_80113826_37EF26_MinigameParkSetup.character[1], 0.0f, 0.0f, -600.0f);
        for (frame = 0; frame < 15; frame++) {
            OVL58_RECORD_PANEL_FRAME();
        }
        func_8002C9C0_2D5C0(model, D_801139B0_37F0B0_MinigameParkSetup);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 11; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 600.0f + pos.z;
            OVL58_RECORD_PANEL_FRAME();
        }
    }
    func_800298A4_2A4A4(model, 4, 4);
    func_8001AC44_1B844(panel);
    SprAnimKill(panelAnim);
    func_8001AC44_1B844(icon);
    SprAnimKill(iconAnim);
    for (j = 0; j < 4; j++) {
        func_8008CCA8_8D8A8(D_80113850_37EF50_MinigameParkSetup[j]);
    }
    func_80112454_37DB54_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup, 30, model);
    return result;
}
#undef OVL58_RECORD_PANEL_FRAME

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
