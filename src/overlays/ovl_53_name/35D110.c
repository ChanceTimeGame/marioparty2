#include "ovl_53.h"

/* Scene setup: lights, the board's players' HUD hidden, the event process. */
void func_80102800_35D110_name_53(void) {
    omInitObjMan(30, 20);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80026E00_27A00(1, 16.0f, 71.0f, -94.0f);
    func_80026E00_27A00(2, 9.0f, 109.0f, 48.0f);
    func_80026DAC_279AC(2, 0xE2, 0xFB, 0x23);
    func_80026D50_27950(1, 1, 1);
    func_80026D50_27950(2, 1, 1);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    func_8005FE10_60A10();
    func_80060034_60C34(0, (u8)gPlayers[0].player_space_color);
    func_80060034_60C34(1, (u8)gPlayers[1].player_space_color);
    func_80060034_60C34(2, (u8)gPlayers[2].player_space_color);
    func_80060034_60C34(3, (u8)gPlayers[3].player_space_color);
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    func_80088640_89240();
    omAddPrcObj(func_80102A08_35D318_name_53, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102D28_35D638_name_53);
    D_80105DD0_3606E0_name_53 = GwSystem.current_board_index;
    D_80105DD2_3606E2_name_53 = GwSystem.current_player_index;
}

/* The event: Bowser appears and speaks, the roulette runs, the chosen event plays, then leave. */
void func_80102A08_35D318_name_53(void) {
    s32 win;

    func_80050E00_51A00(D_80105B94_3604A4_name_53[D_80105DD0_3606E0_name_53]);
    func_8005321C_53E1C(80.0f, 8000.0f);
    D_80105DD4_3606E4_name_53 = MBModelFileCreate(D_80105BAC_3604BC_name_53[D_80105DD0_3606E0_name_53], 0xD,
                                                  1.0f, 3.0f, D_80105BC4_3604D4_name_53[D_80105DD0_3606E0_name_53]);
    func_8005AB50_5B750(D_80105DD4_3606E4_name_53, 2, 9, D_80105C24_360534_name_53);
    func_80043DAC_449AC(D_80105DD4_3606E4_name_53);
    D_80105DD4_3606E4_name_53->pos.x = 0.0f;
    D_80105DD4_3606E4_name_53->pos.y = 0.0f;
    D_80105DD4_3606E4_name_53->pos.z = 0.0f;
    D_80105DD4_3606E4_name_53->scale.x = D_80105DD4_3606E4_name_53->scale.y = D_80105DD4_3606E4_name_53->scale.z = 2.0f;
    MBMotionSet(D_80105DD4_3606E4_name_53, 0, 2);
    func_80103F00_35E810_name_53();
    func_80104570_35EE80_name_53(D_80105DD2_3606E2_name_53);
    PlayMusic(0x12);
    InitFadeIn(3, 16);
    HuPrcSleep(16);
    if (D_800CD414_CE014 == 1) {
        D_80105DC4_3606D4_name_53 = 10;
    } else {
        PlaySound(0x333);
        func_8008D974_8E574(D_800CC5F8[gPlayers[D_80105DD2_3606E2_name_53].character], 0);
        func_8008DACC_8E6CC(1, D_80105DCC_3606DC_name_53, 0x262);
        win = func_8005AAC0_5B6C0((320 - D_80105DCC_3606DC_name_53[0]) / 2, 45, D_80105DCC_3606DC_name_53[0],
                                  D_80105DCC_3606DC_name_53[1]);
        func_80089308_89F08(win, D_800CC5F8[gPlayers[D_80105DD2_3606E2_name_53].character], 0);
        func_800890CC_89CCC(win, 0x262, -1, -1);
        ShowTextWindow(win);
        func_80057730_58330(win, D_80105DD2_3606E2_name_53);
        func_8005762C_5822C(win);
        PlaySound(0x123);
        MBMotionShiftSet(D_80105DD4_3606E4_name_53, 1, 0, 8, 0);
        func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
        HuPrcSleep(20);
        func_80104A30_35F340_name_53();
        while (D_80105DA8_3606B8_name_53 != NULL) {
            HuPrcVSleep();
        }
    }
    D_80105C2C_36053C_name_53[D_80105DC4_3606D4_name_53]();
    InitFadeOut(3, 20);
    func_800794A8_7A0A8(60);
    HuPrcSleep(20);
    func_80102D54_35D664_name_53();
    omOvlKill();
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_80102D28_35D638_name_53(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        func_80102D54_35D664_name_53();
    }
}

/* Leave the scene: event 2 goes to Chance Time (flag 0x45), event 5 calls the board's overlay. */
void func_80102D54_35D664_name_53(void) {
    s32 i;

    MBDBackKill();
    func_80050AE0_516E0();
    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    func_80059400_5A000();
    func_8008CE5C_8DA5C();
    if (D_80105DC4_3606D4_name_53 == 2) {
        _SetFlag(0x45);
        omOvlGotoEx(0x34, 0, 0x92);
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = 1;
        }
        gPlayers[D_80105DD2_3606E2_name_53].group = 0;
    } else if (D_80105DC4_3606D4_name_53 == 5) {
        omOvlCallEx(D_80105C58_360568_name_53[D_80105DD0_3606E0_name_53], 4, 0x192);
        omOvlHisChg(1, 0x53, 1, 0x192);
    } else {
        omOvlReturnEx(1);
    }
}

/* The roulette's tick (MP1 func_80042B60). */
void func_80102E84_35D794_name_53(void) {
    if (D_800FDC6C_FE86C >= D_80105C70_360580_name_53 + 4) {
        PlaySound(0x324);
        D_80105C70_360580_name_53 = D_800FDC6C_FE86C;
    }
}

/* The roulette object (MP1 func_8004858C): 0 slides the panels in, 1 spins (A or a CPU stops it),
   2 flashes the chosen panel, 4 slides the panels out and records the event. */
void func_80102ED0_35D7E0_name_53(omObjData* obj) {
    Ovl53Box* box;
    s32 i;
    s32 j;
    s32 k;
    s32 r;

    switch (obj->work[0]) {
        case 3:
            break;
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < 5; i++) {
                box = &D_80105D70_360680_name_53[i];
                func_800896DC_8A2DC(box->win, box->x + box->w / 2, box->y + box->h / 2 + (s16)obj->trans.y);
            }
            if (D_80105DB6_3606C6_name_53 != -1) {
                SprPosSet(D_80105DB6_3606C6_name_53, 0, D_80105D70_360680_name_53[0].x + 100,
                          (s32)obj->trans.y + D_80105D70_360680_name_53[0].y + 50);
            }
            if (D_80105DB2_3606C2_name_53 != -1) {
                SprPosSet(D_80105DB2_3606C2_name_53, 0, D_80105D70_360680_name_53[0].x + 100,
                          (s32)obj->trans.y + D_80105D70_360680_name_53[0].y - 30);
            }
            for (i = 0; i < 2; i++) {
                if (D_80105DAC_3606BC_name_53[i] != -1) {
                    SprPosSet(D_80105DAC_3606BC_name_53[i], 0, D_80105D70_360680_name_53[0].x + i * 200,
                              (s32)obj->trans.y + D_80105D70_360680_name_53[0].y - 40);
                }
            }
            if (obj->trans.y >= 288.0f) {
                func_80102E84_35D794_name_53();
                func_8008D6F0_8E2F0(D_80105D6A_36067A_name_53);
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[3] = 0;
                obj->trans.z = 0.0f;
                for (i = 0; i < 5; i++) {
                }
                r = (u8)(rand8() % 50);
                i = rand8();
                if (i < 76.8) {
                    obj->rot.y = 0.0f;
                } else if (i < 115.2) {
                    obj->rot.y = 1.0f;
                } else if (i < 161.28) {
                    obj->rot.y = 2.0f;
                } else if (i < 186.88) {
                    obj->rot.y = 3.0f;
                } else if (i < 199.68) {
                    obj->rot.y = 4.0f;
                } else if (i < 225.28) {
                    obj->rot.y = -1.0f;
                } else if (i < 243.20000000000002) {
                    obj->rot.y = -2.0f;
                } else {
                    obj->rot.y = -3.0f;
                }
                if (r == 25) {
                    /* one roll in 50 aims at a rare event (6 and up) */
                    for (i = 0; i < 5; i++) {
                        if (D_80105DA2_3606B2_name_53[i] >= 6) {
                            j = i - (s32)obj->rot.y;
                            break;
                        }
                    }
                    if (j < 0) {
                        j += 5;
                    } else {
                        j %= 5;
                    }
                } else {
                    do {
                        j = (u8)(rand8() % 5) - (s32)obj->rot.y;
                        if (j < 0) {
                            j += 5;
                        } else {
                            j %= 5;
                        }
                    } while (D_80105DA2_3606B2_name_53[j] >= 6);
                }
                obj->work[2] = j;
                i = rand8();
                if (i < 153.6) {
                    obj->mdlcnt = 20;
                } else if (i < 230.4) {
                    obj->mdlcnt = 14;
                } else {
                    obj->mdlcnt = 8;
                }
                obj->mtncnt = 0;
                func_801044A8_35EDB8_name_53();
            }
            break;
        case 1:
            if (gPlayers[D_80105DC0_3606D0_name_53].flags & 1) {
                obj->trans.z = 1.0f;
            } else if (ContBtnTrg[gPlayers[D_80105DC0_3606D0_name_53].port] & 0x8000) {
                obj->trans.z = 1.0f;
            }
            if (obj->mtncnt != 0) {
                obj->scale.x = obj->mdlcnt / 100.0f;
            }
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= 5;
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 0x80) {
                        obj->work[1] = 4;
                    }
                }
                func_80102E84_35D794_name_53();
            }
            for (i = 0; i < 5; i++) {
                box = &D_80105D70_360680_name_53[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(box->win, 0, 200, 0);
                    func_80089B2C_8A72C(box->win, 0x100);
                    func_80089A7C_8A67C(box->win, 9000);
                } else {
                    func_8008D530_8E130(box->win, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(box->win, 0);
                    func_80089A7C_8A67C(box->win, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                if (obj->trans.z != 0.0f && obj->mtncnt == 0) {
                    obj->scale.x -= 0.02;
                }
            }
            if (obj->scale.x <= 0.08f || obj->mtncnt != 0) {
                if (obj->mtncnt == 0) {
                    obj->scale.x = 0.08f;
                }
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((obj->rot.y > 0.0f ? obj->rot.y : 0.0f - obj->rot.y) <= 0.5f) {
                        PlaySound(0x325);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8008AD44_8B944(D_80105D70_360680_name_53[obj->work[1]].win);
                        if (D_80105DA2_3606B2_name_53[obj->work[1]] == 0) {
                            func_80089308_89F08(D_80105D70_360680_name_53[obj->work[1]].win, (s32)D_80105D60_360670_name_53, 0);
                            func_8008D974_8E574((s32)D_80105D60_360670_name_53, 0);
                        }
                        func_800890CC_89CCC(D_80105D70_360680_name_53[obj->work[1]].win,
                                            D_80105DA2_3606B2_name_53[obj->work[1]] + 0x258, -2, 4);
                        func_80089C78_8A878(D_80105D70_360680_name_53[obj->work[1]].win, 1);
                        func_80089DA0_8A9A0(D_80105D70_360680_name_53[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                        func_8008D530_8E130(D_80105D70_360680_name_53[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                        func_80089A48_8A648(D_80105D70_360680_name_53[obj->work[1]].win, 0);
                        /* the players Bowser's event hits react (3, 4, 5: the victim; 13, 14, 15: everyone) */
                        k = D_80105C74_360584_name_53[D_80105DA2_3606B2_name_53[obj->work[2]]];
                        if (k != 0) {
                            if (k > 10) {
                                for (i = 0; i < 4; i++) {
                                    switch (k - 10) {
                                        case 3:
                                            func_8005A4EC_5B0EC(i, 3);
                                            break;
                                        case 4:
                                            func_8005A4EC_5B0EC(i, 4);
                                            break;
                                        case 5:
                                            func_8005A4EC_5B0EC(i, 5);
                                            break;
                                    }
                                }
                            } else {
                                switch (k) {
                                    case 3:
                                        func_8005A4EC_5B0EC(D_80105DD2_3606E2_name_53, 3);
                                        break;
                                    case 4:
                                        func_8005A4EC_5B0EC(D_80105DD2_3606E2_name_53, 4);
                                        break;
                                    case 5:
                                        func_8005A4EC_5B0EC(D_80105DD2_3606E2_name_53, 5);
                                        break;
                                }
                            }
                        }
                    } else {
                        obj->mtncnt = 1;
                        if (obj->rot.y >= 0.5f) {
                            obj->rot.y -= 1.0f;
                            obj->work[2]++;
                            obj->work[2] %= 5;
                        } else {
                            obj->rot.y += 1.0f;
                            obj->scale.y = 1.0f;
                            obj->work[2]--;
                            if (obj->work[2] >= 0x80) {
                                obj->work[2] = 4;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] == 0) {
                obj->work[0] = 4;
                func_80103FB8_35E8C8_name_53();
            } else {
                obj->work[3]--;
                obj->rot.z += 1.0f;
                if (obj->rot.z >= 13.0f) {
                    obj->rot.z -= 13.0f;
                }
            }
            break;
        case 4:
            obj->trans.y -= 32.0f;
            for (i = 0; i < 5; i++) {
                box = &D_80105D70_360680_name_53[i];
                func_800896DC_8A2DC(box->win, box->x + box->w / 2, box->y + box->h / 2 + (s16)obj->trans.y);
            }
            if (D_80105DB6_3606C6_name_53 != -1) {
                SprPosSet(D_80105DB6_3606C6_name_53, 0, D_80105D70_360680_name_53[0].x + 100,
                          (s32)obj->trans.y + D_80105D70_360680_name_53[0].y + 50);
            }
            if (D_80105DB2_3606C2_name_53 != -1) {
                SprPosSet(D_80105DB2_3606C2_name_53, 0, D_80105D70_360680_name_53[0].x + 100,
                          (s32)obj->trans.y + D_80105D70_360680_name_53[0].y - 30);
            }
            for (i = 0; i < 2; i++) {
                if (D_80105DAC_3606BC_name_53[i] != -1) {
                    SprPosSet(D_80105DAC_3606BC_name_53[i], 0, D_80105D70_360680_name_53[0].x + i * 200,
                              (s32)obj->trans.y + D_80105D70_360680_name_53[0].y - 40);
                }
            }
            if (obj->trans.y <= 0.0f) {
                D_80105DC4_3606D4_name_53 = D_80105DA2_3606B2_name_53[obj->work[2]];
                func_8010401C_35E92C_name_53();
            }
            break;
    }

    if (D_80105DBA_3606CA_name_53 != -1) {
        for (i = 0; !(obj->rot.z < (D_80105B8C_36049C_name_53 + i)->limit); i++) {
        }
        SprPosSet(D_80105DBA_3606CA_name_53, 0, D_80105B8C_36049C_name_53[i].x + 50,
                  D_80105B88_360498_name_53 + obj->work[1] * 20);
    }
}

s32 func_80103ECC_35E7DC_name_53(void) {
    return D_80105DC4_3606D4_name_53;
}

s32 func_80103ED8_35E7E8_name_53(void) {
    return D_80105DC8_3606D8_name_53;
}

s32 func_80103EE4_35E7F4_name_53(void) {
    if (D_80105DA8_3606B8_name_53 == NULL) {
        return -1;
    }
    return D_80105DA8_3606B8_name_53->work[0];
}

void func_80103F00_35E810_name_53(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        D_80105D70_360680_name_53[i].win = -1;
    }
    D_80105DA8_3606B8_name_53 = NULL;
    for (i = 0; i < 2; i++) {
        D_80105DAC_3606BC_name_53[i] = -1;
    }
    D_80105DB0_3606C0_name_53 = -1;
    D_80105DB4_3606C4_name_53 = -1;
    D_80105DB2_3606C2_name_53 = -1;
    D_80105DB8_3606C8_name_53 = -1;
    D_80105DB6_3606C6_name_53 = -1;
    D_80105DBC_3606CC_name_53 = -1;
    D_80105DBA_3606CA_name_53 = -1;
    D_80105DC4_3606D4_name_53 = -1;
    D_80105D6A_36067A_name_53 = -1;
}

void func_80103FB8_35E8C8_name_53(void) {
    if (D_80105DBA_3606CA_name_53 != -1) {
        SprKill(D_80105DBA_3606CA_name_53);
        D_80105DBA_3606CA_name_53 = -1;
    }
    if (D_80105DBC_3606CC_name_53 != -1) {
        SprAnimKill(D_80105DBC_3606CC_name_53);
        D_80105DBC_3606CC_name_53 = -1;
    }
}

void func_8010401C_35E92C_name_53(void) {
    Ovl53Box* box;
    s32 i;

    for (i = 0; i < 5; i++) {
        box = &D_80105D70_360680_name_53[i];
        if (box->win != -1) {
            func_8008CCA8_8D8A8(box->win);
            box->win = -1;
        }
    }
    if (D_80105D6A_36067A_name_53 != -1) {
        func_8008CCA8_8D8A8(D_80105D6A_36067A_name_53);
        D_80105D6A_36067A_name_53 = -1;
    }
    if (D_80105DA8_3606B8_name_53 != NULL) {
        omDelObj(D_80105DA8_3606B8_name_53);
        D_80105DA8_3606B8_name_53 = NULL;
    }
    if (D_80105DB6_3606C6_name_53 != -1) {
        SprKill(D_80105DB6_3606C6_name_53);
        D_80105DB6_3606C6_name_53 = -1;
    }
    if (D_80105DB8_3606C8_name_53 != -1) {
        SprAnimKill(D_80105DB8_3606C8_name_53);
        D_80105DB8_3606C8_name_53 = -1;
    }
    if (D_80105DB2_3606C2_name_53 != -1) {
        SprKill(D_80105DB2_3606C2_name_53);
        D_80105DB2_3606C2_name_53 = -1;
    }
    if (D_80105DB4_3606C4_name_53 != -1) {
        SprAnimKill(D_80105DB4_3606C4_name_53);
        D_80105DB4_3606C4_name_53 = -1;
    }
    for (i = 0; i < 2; i++) {
        if (D_80105DAC_3606BC_name_53[i] != -1) {
            SprKill(D_80105DAC_3606BC_name_53[i]);
            D_80105DAC_3606BC_name_53[i] = -1;
        }
    }
    if (D_80105DB0_3606C0_name_53 != -1) {
        SprAnimKill(D_80105DB0_3606C0_name_53);
        D_80105DB0_3606C0_name_53 = -1;
    }
    func_80103FB8_35E8C8_name_53();
}

void func_801041E4_35EAF4_name_53(void) {
    void* data;
    s32 i;

    if (D_80105DB6_3606C6_name_53 == -1) {
        D_80105DB6_3606C6_name_53 = SprCreate(1, 5);
        data = DataRead(0xA0019);
        D_80105DB8_3606C8_name_53 = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(D_80105DB6_3606C6_name_53, 0, D_80105DB8_3606C8_name_53, 0);
        SprPrioSet(D_80105DB6_3606C6_name_53, 0, 0x4770);
        SprAttrSet(D_80105DB6_3606C6_name_53, 0, 0x1000);
        SprPosSet(D_80105DB6_3606C6_name_53, 0, D_80105D70_360680_name_53[0].x + 100, D_80105D70_360680_name_53[0].y + 50);
        func_80082450_83050(D_80105DB6_3606C6_name_53, 0, 0, 0, 0);
        D_80105DB2_3606C2_name_53 = SprCreate(1, 5);
        data = DataRead(0xA001C);
        D_80105DB4_3606C4_name_53 = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(D_80105DB2_3606C2_name_53, 0, D_80105DB4_3606C4_name_53, 0);
        SprPrioSet(D_80105DB2_3606C2_name_53, 0, 0x4770);
        SprAttrSet(D_80105DB2_3606C2_name_53, 0, 0x1000);
        SprPosSet(D_80105DB2_3606C2_name_53, 0, D_80105D70_360680_name_53[0].x + 100, D_80105D70_360680_name_53[0].y - 30);
        data = DataRead(0xA010D);
        D_80105DB0_3606C0_name_53 = SprAnimRead(data);
        DataClose(data);
        for (i = 0; i < 2; i++) {
            D_80105DAC_3606BC_name_53[i] = SprCreate(1, 5);
            SprAnimSet(D_80105DAC_3606BC_name_53[i], 0, D_80105DB0_3606C0_name_53, 1);
            SprPrioSet(D_80105DAC_3606BC_name_53[i], 0, 0x4770);
            SprAttrSet(D_80105DAC_3606BC_name_53[i], 0, 0x1000);
            SprPosSet(D_80105DAC_3606BC_name_53[i], 0, D_80105D70_360680_name_53[0].x + i * 200,
                      D_80105D70_360680_name_53[0].y - 40);
            func_80082450_83050(D_80105DAC_3606BC_name_53[i], 0, 0xFF, 0, 0);
        }
    }
}

/* The cursor. */
void func_801044A8_35EDB8_name_53(void) {
    void* data;

    if (D_80105DBA_3606CA_name_53 == -1) {
        D_80105DBA_3606CA_name_53 = SprCreate(1, 5);
        data = DataRead(0xA001D);
        D_80105DBC_3606CC_name_53 = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(D_80105DBA_3606CA_name_53, 0, D_80105DBC_3606CC_name_53, 0);
        SprPrioSet(D_80105DBA_3606CA_name_53, 0, 0x100);
        SprAttrSet(D_80105DBA_3606CA_name_53, 0, 0x1000);
        SprPosSet(D_80105DBA_3606CA_name_53, 0, 50, D_80105B88_360498_name_53);
    }
}

__asm__(".section .rodata");
const char D_80105D58_360668_name_53[] = "%d";

/* Build the roulette (MP1 func_800499CC): panels 0 and 1 are coin events (0), panel 2 one of the
   rare events 6-9, panels 3 and 4 events 1-5 by weight (5 always while func_8004E94C is set);
   then shuffle, label, and start the roulette object for the player. */
/* NON_MATCHING: registers only (masked 0): the hoisted constants 2-5 and `prev` land in other
   saved registers */
#ifdef NON_MATCHING
void func_80104570_35EE80_name_53(s32 player) {
    Ovl53Box* box;
    Ovl53Rect* rect;
    omObjData* obj;
    s32 i;
    s32 a;
    s32 b;
    u8 t;
    s32 r;
    u8 prev;

    prev = 0xFF;
    i = 0;
    do {
        box = &D_80105D70_360680_name_53[i];
        rect = D_80105B60_360470_name_53 + i;
        box->x = rect->x;
        box->y = rect->y;
        box->w = rect->w;
        box->h = rect->h;
        box->win = func_800888A8_894A8(box->x + box->w / 2, box->y + box->h / 2, box->w, box->h, 0, 4);
        func_8008D88C_8E48C(box->win);
        func_800898F0_8A4F0(box->win, box->w / 2, box->h / 2);
        func_80089B2C_8A72C(box->win, 0);
        if (i < 2) {
            D_80105DA2_3606B2_name_53[i] = 0;
        } else if (i == 2) {
            D_80105DA2_3606B2_name_53[i] = (rand8() & 3) + 6;
        } else {
            do {
                r = (u8)(rand8() % 150);
                if (r < 50) {
                    D_80105DA2_3606B2_name_53[i] = 1;
                } else if (r < 90) {
                    D_80105DA2_3606B2_name_53[i] = 2;
                } else if (r < 120) {
                    D_80105DA2_3606B2_name_53[i] = 3;
                } else if (func_8004E94C_4F54C() != 0 || r < 140) {
                    D_80105DA2_3606B2_name_53[i] = 5;
                } else {
                    D_80105DA2_3606B2_name_53[i] = 4;
                }
            } while (i == 4 && D_80105DA2_3606B2_name_53[4] == prev);
            if (i == 3) {
                prev = D_80105DA2_3606B2_name_53[i];
            }
        }
        i++;
    } while (i < 5);

    for (i = 0; i < 10; i++) {
        do {
            a = (u8)(rand8() % 5);
            b = (u8)(rand8() % 5);
        } while (a == b);
        t = D_80105DA2_3606B2_name_53[a];
        D_80105DA2_3606B2_name_53[a] = D_80105DA2_3606B2_name_53[b];
        D_80105DA2_3606B2_name_53[b] = t;
    }

    for (i = 0; i < 5; i++) {
        box = &D_80105D70_360680_name_53[i];
        if (D_80105DA2_3606B2_name_53[i] == 0) {
            sprintf(D_80105D60_360670_name_53, D_80105D58_360668_name_53,
                    func_80104A40_35F350_name_53(0, D_80105DD2_3606E2_name_53));
            func_80089308_89F08(box->win, (s32)D_80105D60_360670_name_53, 0);
            func_8008D974_8E574((s32)D_80105D60_360670_name_53, 0);
        }
        func_800890CC_89CCC(box->win, D_80105DA2_3606B2_name_53[i] + 0x258, -2, 4);
        func_80089A48_8A648(box->win, 0);
    }

    obj = D_80105DA8_3606B8_name_53 = omAddObj(-0x8000, 0, 0, -1, func_80102ED0_35D7E0_name_53);
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_801041E4_35EAF4_name_53();
    D_80105DC0_3606D0_name_53 = player;
    D_80105D6A_36067A_name_53 = func_800888A8_894A8(95, 200, 130, 20, 0, 0);
    func_80089B2C_8A72C(D_80105D6A_36067A_name_53, 0);
    func_800890CC_89CCC(D_80105D6A_36067A_name_53, 0x27C, -1, -1);
    func_80089A48_8A648(D_80105D6A_36067A_name_53, 0);
    func_80057730_58330(D_80105D6A_36067A_name_53, D_80105DD2_3606E2_name_53);
    func_8008D5D8_8E1D8(D_80105D6A_36067A_name_53);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_53_name/35D110", func_80104570_35EE80_name_53);
#endif

void func_80104A30_35F340_name_53(void) {
    D_80105DA8_3606B8_name_53->work[0] = 0;
}

/* Coins at stake: by kind, by the game's stage (turn against D_80105CCC) and the player's rank. */
s32 func_80104A40_35F350_name_53(s32 kind, s32 player) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (GwSystem.current_turn <= D_80105CCC_3605DC_name_53[GwSystem.current_game_length][i]) {
            break;
        }
    }
    return D_80105C9C_3605AC_name_53[kind][i][func_80059FD0_5ABD0(player)];
}

/* Event 0: Bowser takes the stake (D_80105D60) from the player; with no coins he gives 10. */
void func_80104AEC_35F3FC_name_53(void) {
    s32 win;
    s32 coins;
    s32 mes1;
    s32 mes2;

    coins = func_80104A40_35F350_name_53(0, D_80105DD2_3606E2_name_53);
    mes1 = 0x263;
    if (gPlayers[D_80105DD2_3606E2_name_53].coins >= coins) {
        mes2 = 0x264;
    } else {
        mes1 = 0x265;
        if (gPlayers[D_80105DD2_3606E2_name_53].coins > 0) {
            mes2 = 0x266;
        } else {
            mes1 = 0x267;
            coins = -10;
            mes2 = 0x268;
        }
    }
    func_8008D974_8E574((s32)D_80105D60_360670_name_53, 0);
    OVL53_MES_WIN(win, mes1);
    func_80089308_89F08(win, (s32)D_80105D60_360670_name_53, 0);
    func_800890CC_89CCC(win, mes1, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8008CCA8_8D8A8(win);
    func_80105B24_360434_name_53();
    MBMotionSet(D_80105DD4_3606E4_name_53, 1, 0);
    func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
    HuPrcSleep(14);
    func_8005A4EC_5B0EC(D_80105DD2_3606E2_name_53, 4);
    func_800614B4_620B4(D_80105DD2_3606E2_name_53, -coins);
    HuPrcSleep(45);
    OVL53_MES_WIN(win, mes2);
    func_800890CC_89CCC(win, mes2, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    PlaySound(0x332);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 2, 0, 6, 2);
    HuPrcSleep(30);
}

/* Event 1: every player pays the stake; with nobody holding coins Bowser gives everyone 10. */
/* NON_MATCHING: registers (masked 1): the count/loop counter pair and the i == who temp land in swapped saved registers */
#ifdef NON_MATCHING
void func_80104D6C_35F67C_name_53(void) {
    s32 win;
    s32 i;
    s32 n;
    s32 mes1;
    s32 mes2;
    s32 coins;
    s32 who;
    s32 d;

    n = 0;
    mes1 = 0x269;
    mes2 = 0x26A;
    coins = func_80104A40_35F350_name_53(1, D_80105DD2_3606E2_name_53);
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].coins < coins) {
            mes2 = 0x26C;
            mes1 = 0x26B;
        }
        n += gPlayers[i].coins == 0;
    }
    if (n == 4) {
        coins = -10;
        mes1 = 0x26D;
        mes2 = 0x26E;
    }
    sprintf(D_80105D60_360670_name_53, D_80105D58_360668_name_53, coins);
    func_8008D974_8E574((s32)D_80105D60_360670_name_53, 0);
    OVL53_MES_WIN(win, mes1);
    func_80089308_89F08(win, (s32)D_80105D60_360670_name_53, 0);
    func_800890CC_89CCC(win, mes1, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8008CCA8_8D8A8(win);
    func_80060210_60E10(0);
    HuPrcSleep(20);
    n = 0;
    who = 0;
    for (i = 0; i < 4; i++) {
        d = gPlayers[i].coins - coins;
        if (n < d) {
            n = d;
            who = i;
        }
    }
    MBMotionSet(D_80105DD4_3606E4_name_53, 1, 0);
    func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
    HuPrcSleep(14);
    for (i = 0; i < 4; i++) {
        n = i == who;
        func_8005A4EC_5B0EC(i, 4);
        func_8006135C_61F5C(i, -coins, n);
    }
    HuPrcSleep(45);
    OVL53_MES_WIN(win, mes2);
    func_800890CC_89CCC(win, mes2, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    PlaySound(0x332);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 2, 0, 6, 2);
    HuPrcSleep(30);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_53_name/35D110", func_80104D6C_35F67C_name_53);
#endif

/* Event 2: Chance Time (func_80102D54 leaves to overlay 0x34). */
void func_80105088_35F998_name_53(void) {
    s32 win;

    OVL53_MES_WIN(win, 0x26F);
    func_800890CC_89CCC(win, 0x26F, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    MBMotionSet(D_80105DD4_3606E4_name_53, 1, 0);
    func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
    HuPrcSleep(20);
}

/* Event 3: Bowser's Revolution, everyone's coins evened out (the rest of the division is lost). */
/* NON_MATCHING: registers only (masked 0): the loop counter and the window/temp variable swap s0/s1 */
#ifdef NON_MATCHING
void func_80105150_35FA60_name_53(void) {
    s32 i;
    s32 win;
    s32 total;
    s32 mes;
    s32 who;
    s32 d;

    total = 0;
    for (i = 0; i < 4; i++) {
        total += gPlayers[i].coins;
    }
    mes = -1;
    if (total == 0) {
        OVL53_MES_WIN(win, 0x274);
        func_800890CC_89CCC(win, 0x274, -1, -1);
        ShowTextWindow(win);
        func_80057730_58330(win, D_80105DD2_3606E2_name_53);
        mes = 0x275;
    } else {
        OVL53_MES_WIN(win, 0x272);
        func_800890CC_89CCC(win, 0x272, -1, -1);
        ShowTextWindow(win);
        func_80057730_58330(win, D_80105DD2_3606E2_name_53);
        func_8005762C_5822C(win);
        func_80060210_60E10(0);
        HuPrcSleep(20);
        MBMotionSet(D_80105DD4_3606E4_name_53, 1, 0);
        func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
        HuPrcSleep(20);
        total /= 4;
        win = 0;
        /* who stays unset when nobody is below the share (retail) */
        for (i = 0; i < 4; i++) {
            func_80060F90_61B90(i);
            d = total - gPlayers[i].coins;
            if (win < d) {
                win = d;
                who = i;
            }
        }
        PlaySound(0x33B);
        for (i = 0; i < 60; i++) {
            win = i % 5;
            func_80060034_60C34(0, win);
            func_80060034_60C34(1, win);
            func_80060034_60C34(2, win);
            func_80060034_60C34(3, win);
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            win = i == who;
            if (total < gPlayers[i].coins) {
                func_8005A4EC_5B0EC(i, 4);
            }
            func_8006135C_61F5C(i, total - gPlayers[i].coins, win);
        }
        for (i = 0; i < 30; i++) {
            win = i % 5;
            func_80060034_60C34(0, win);
            func_80060034_60C34(1, win);
            func_80060034_60C34(2, win);
            func_80060034_60C34(3, win);
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            func_80060034_60C34(i, (u8)gPlayers[i].player_space_color);
            func_80061078_61C78(i);
        }
        HuPrcSleep(45);
        OVL53_MES_WIN(win, 0x273);
        func_800890CC_89CCC(win, 0x273, -1, -1);
        ShowTextWindow(win);
        func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    }
    if (mes != -1) {
        func_8008CCA8_8D8A8(win);
        OVL53_MES_WIN(win, 0x275);
        func_800890CC_89CCC(win, 0x275, -1, -1);
        func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    }
    func_8005762C_5822C(win);
    PlaySound(0x332);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 2, 0, 6, 2);
    HuPrcSleep(30);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_53_name/35D110", func_80105150_35FA60_name_53);
#endif

/* Event 4: Bowser leaps away and sets D_800F8D16. */
void func_8010565C_35FF6C_name_53(void) {
    s32 win;
    s32 i;

    OVL53_MES_WIN(win, 0x276);
    func_800890CC_89CCC(win, 0x276, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8008CCA8_8D8A8(win);
    OVL53_MES_WIN(win, 0x277);
    func_800890CC_89CCC(win, 0x277, -1, -1);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    PlaySound(0x350);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 1, 0, 2, 0);
    HuPrcSleep(18);
    for (i = 0; i < 20; i++) {
        D_80105DD4_3606E4_name_53->jumpY += 120.0f;
        HuPrcVSleep();
    }
    MBModelDispOff(D_80105DD4_3606E4_name_53);
    OVL53_MES_WIN(win, 0x278);
    func_800890CC_89CCC(win, 0x278, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    D_800F8D16_F9916 = 1;
}

/* Event 5: func_80102D54 then calls the board's overlay. */
void func_80105870_360180_name_53(void) {
    s32 win;

    OVL53_MES_WIN(win, 0x279);
    func_800890CC_89CCC(win, 0x279, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    PlaySound(0x122);
    MBMotionSet(D_80105DD4_3606E4_name_53, 1, 0);
    func_80059520_5A120(D_80105DD4_3606E4_name_53, 0, 2);
    HuPrcSleep(20);
    func_80057448_58048();
}

/* Event 10 (the D_800CD414 == 1 skip): Bowser's closing line. */
void func_80105948_360258_name_53(void) {
    s32 win;

    OVL53_MES_WIN(win, 0x27A);
    func_800890CC_89CCC(win, 0x27A, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
    PlaySound(0x332);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 2, 0, 6, 2);
    HuPrcSleep(30);
}

/* Events 6-9: Bowser leaps away. */
void func_80105A10_360320_name_53(void) {
    s32 win;
    s32 i;

    HuPrcSleep(60);
    PlaySound(0x350);
    MBMotionShiftSet(D_80105DD4_3606E4_name_53, 1, 0, 2, 0);
    HuPrcSleep(18);
    for (i = 0; i < 20; i++) {
        D_80105DD4_3606E4_name_53->jumpY += 120.0f;
        HuPrcVSleep();
    }
    MBModelDispOff(D_80105DD4_3606E4_name_53);
    OVL53_MES_WIN(win, 0x27B);
    func_800890CC_89CCC(win, 0x27B, -1, -1);
    ShowTextWindow(win);
    func_80057730_58330(win, D_80105DD2_3606E2_name_53);
    func_8005762C_5822C(win);
}

void func_80105B24_360434_name_53(void) {
    func_800615F0_621F0(D_80105DD2_3606E2_name_53);
    func_80060210_60E10(24);
    func_800615F0_621F0(-1);
    HuPrcSleep(20);
}
