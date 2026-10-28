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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010C4B4_377BB4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010C6C8_377DC8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010D260_378960_MinigameParkSetup);

__asm__(".section .rodata");
const char D_8011370C_37EE0C_MinigameParkSetup[] = "%2d";


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E1F0_3798F0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E2B8_3799B8_MinigameParkSetup);


__asm__(".section .rodata");
const u32 D_80113710_37EE10_MinigameParkSetup[4] = { 0x0005000A, 0xFFFB0002, 0x0008FFFB, 0xFFFEFFFF };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E460_379B60_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010ED54_37A454_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010EEF8_37A5F8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010EF58_37A658_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010F0A4_37A7A4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010F358_37AA58_MinigameParkSetup);



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
