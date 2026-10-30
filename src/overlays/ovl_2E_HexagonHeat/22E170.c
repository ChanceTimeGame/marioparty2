#include "ovl_2E.h"

void func_80102800_22E170_HexagonHeat(void) {
    u8 cam;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    func_80026E00_27A00(0, 100.0f, 47.0f, 45.0f);
    func_80026DAC_279AC(0, 0xFF, 0, 0);
    func_80026E00_27A00(1, 45.0f, 47.0f, 100.0f);
    func_80026DAC_279AC(1, 0xFF, 0x3C, 0x3C);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    D_800BF7D4_C03D4 = 1.46f;
    func_8000C56C_D16C(1);
    D_800BF7DC_C03DC = 0.0f;
    func_8000C578_D178(0);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 5, 0, -1, func_801047B8_230128_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105D7C_2316EC_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 0, -1, func_80105EF0_231860_HexagonHeat);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 2, 2, -1, func_80106058_2319C8_HexagonHeat);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0x10, 0x3C, -1, func_80105B78_2314E8_HexagonHeat);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0x10, 0x3C, -1, func_80105BF0_231560_HexagonHeat);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0x10, 0x3C, -1, func_80105C78_2315E8_HexagonHeat);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0x10, 0x3C, -1, func_80105D00_231670_HexagonHeat);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    D_800F8FD0_F9BD0 = 0;
    D_800BF79C_C039C = 10.0f;
    InitFadeIn(0, 0x10);
}

void func_80102D30_22E6A0_HexagonHeat(void) {
    MgWork* w;
    omObjData* obj;
    s16 tempo;
    s32 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        switch (D_80106528_231E98_HexagonHeat) {
        case 0:
            if (D_8010652C_231E9C_HexagonHeat == 65 - D_801066C4_232034_HexagonHeat) {
                D_80106528_231E98_HexagonHeat = 2;
                tempo = func_80079574_7A174() + 5;
                if (tempo >= 131) {
                    tempo = 130;
                }
                func_8007954C_7A14C(tempo);
                D_801066C0_232030_HexagonHeat += 2.0f;
                D_801066C4_232034_HexagonHeat++;
                if (D_801066C0_232030_HexagonHeat > 25.0f) {
                    D_801066C0_232030_HexagonHeat = 25.0f;
                }
                D_801067E0_232150_HexagonHeat = -2.0f;
                if (D_801066C4_232034_HexagonHeat >= 11) {
                    D_801066C4_232034_HexagonHeat = 10;
                }
                D_801066C8_232038_HexagonHeat = 0;
                D_80106548_231EB8_HexagonHeat = (s16)PlaySound(0x29C);
            }
            D_8010652C_231E9C_HexagonHeat++;
            break;
        case 3:
            if (D_8010652C_231E9C_HexagonHeat == 40) {
                D_80106528_231E98_HexagonHeat = 1;
                D_801067E0_232150_HexagonHeat = 2.0f;
                D_80106548_231EB8_HexagonHeat = (s16)PlaySound(0x29C);
            }
            D_8010652C_231E9C_HexagonHeat++;
            break;
        case 1:
            if (D_801066C0_232030_HexagonHeat >= 12.5f) {
                D_80106524_231E94_HexagonHeat += 25.0f;
            } else {
                D_80106524_231E94_HexagonHeat += D_801066C0_232030_HexagonHeat * 2.0f;
            }
            if (D_80106524_231E94_HexagonHeat > 550.0f) {
                D_80106528_231E98_HexagonHeat = 0;
                D_80106524_231E94_HexagonHeat = 550.0f;
                D_8010652C_231E9C_HexagonHeat = 0;
                PlaySound(0x29D);
                D_80106548_231EB8_HexagonHeat = -1;
            } else {
                func_800796F0_7A2F0((s16)D_80106548_231EB8_HexagonHeat, (D_80106538_231EA8_HexagonHeat - 0.5f) * -600.0f);
                func_800795D8_7A1D8((s16)D_80106548_231EB8_HexagonHeat, fabs(1.0f - D_80106538_231EA8_HexagonHeat * 100.0f));
            }
            for (i = 0; i < 4; i++) {
                if (D_8010654C_231EBC_HexagonHeat[i] == 0) {
                    obj = D_800FFFD8_100BD8[i];
                    w = obj->unk_50;
                    if (w->unk_38 == 1000.0f && (u32)(w->unk_53 - 1) < 7 &&
                        w->unk_53 != D_80106520_231E90_HexagonHeat + 1) {
                        obj->trans.y = D_80106524_231E94_HexagonHeat;
                    }
                }
            }
            break;
        case 2:
            D_80106524_231E94_HexagonHeat -= D_801066C0_232030_HexagonHeat;
            if (D_80106524_231E94_HexagonHeat < 50.0f) {
                D_80106528_231E98_HexagonHeat = 3;
                D_80106524_231E94_HexagonHeat = 50.0f;
                D_8010652C_231E9C_HexagonHeat = 0;
                PlaySound(0x29D);
                D_80106548_231EB8_HexagonHeat = -1;
            } else {
                func_800796F0_7A2F0((s16)D_80106548_231EB8_HexagonHeat, (D_80106538_231EA8_HexagonHeat - 0.5f) * -600.0f);
                func_800795D8_7A1D8((s16)D_80106548_231EB8_HexagonHeat, fabs(1.0f - D_80106538_231EA8_HexagonHeat * 100.0f));
            }
            if (++D_801066C8_232038_HexagonHeat >= 16) {
                D_801066C8_232038_HexagonHeat = 0;
                for (i = 0; i < 4; i++) {
                    if (D_8010654C_231EBC_HexagonHeat[i] == 0) {
                        w = D_800FFFD8_100BD8[i]->unk_50;
                        if (w->unk_53 != D_80106520_231E90_HexagonHeat + 1 && w->unk_38 == 1000.0f) {
                            omVibrate(i, 2, 3, 10);
                        }
                    }
                }
            }
            break;
        }
        func_8010370C_22F07C_HexagonHeat();
        D_80106538_231EA8_HexagonHeat = 1.0f - (D_80106524_231E94_HexagonHeat - 50.0f) / 400.0f;
        if (D_80106538_231EA8_HexagonHeat < 0.0f) {
            D_80106538_231EA8_HexagonHeat = 0.0f;
        }
    }
}

void func_801032F8_22EC68_HexagonHeat(omObjData* obj) {
    s32 c;
    u32 r, g, b;
    f32 end;

    if (D_800F8FD0_F9BD0 == 1) {
        if (D_80106528_231E98_HexagonHeat == 0 && D_8010652C_231E9C_HexagonHeat == 20) {
            D_801066CC_23203C_HexagonHeat = 0.0f;
            do {
                c = rand8() % 7;
            } while (c == D_80106520_231E90_HexagonHeat);
            D_80106520_231E90_HexagonHeat = c;
            r = D_80106550_231EC0_HexagonHeat[D_80106520_231E90_HexagonHeat][0];
            g = D_80106550_231EC0_HexagonHeat[D_80106520_231E90_HexagonHeat][1];
            b = D_80106550_231EC0_HexagonHeat[D_80106520_231E90_HexagonHeat][2];
            func_8002C20C_2CE0C(obj->model[1], "c100_1-hata_R", r, g, b, 0);
            D_801066DC_23204C_HexagonHeat = 1;
            PlaySound(0x29A);
        }
        if (D_801066DC_23204C_HexagonHeat == 1) {
            if (D_801066CC_23203C_HexagonHeat >= 15.0f && D_801066CC_23203C_HexagonHeat < 16.0f) {
                D_801066CC_23203C_HexagonHeat += D_801066D4_232044_HexagonHeat;
            } else {
                D_801066CC_23203C_HexagonHeat += D_801066D0_232040_HexagonHeat;
            }
        }
    }
    func_80029C74_2A874(obj->model[1], D_801066CC_23203C_HexagonHeat);
    end = func_80029CE4_2A8E4(obj->model[1]);
    if (func_80029D0C_2A90C(obj->model[1]) <= end) {
        D_801066DC_23204C_HexagonHeat = 0;
    }
}

void func_801035D8_22EF48_HexagonHeat(void) {
    MgWork* w;
    s32 i;
    s32 alive;
    s32 air;

    alive = 0;
    air = 0;
    D_80106544_231EB4_HexagonHeat = -1;
    for (i = 0; i < 4; i++) {
        if (D_8010654C_231EBC_HexagonHeat[i] == 0) {
            alive++;
            D_80106544_231EB4_HexagonHeat = i;
        }
        w = D_800FFFD8_100BD8[i]->unk_50;
        if (!(func_80019000_19C00(D_800FFFD8_100BD8[i]) & 0x200000) && w->unk_38 != 1000.0f) {
            air++;
        }
    }
    switch (alive) {
    case 0:
        D_8010653C_231EAC_HexagonHeat = 2;
        break;
    case 1:
        if (air == 0) {
            D_8010653C_231EAC_HexagonHeat = 1;
            break;
        }
    case 2:
    case 3:
    case 4:
        D_8010653C_231EAC_HexagonHeat = 0;
        break;
    }
}

void func_8010370C_22F07C_HexagonHeat(void) {
    Vec3f v;
    f32 len;
    s32 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_80106524_231E94_HexagonHeat < 200.0f) {
            D_80106534_231EA4_HexagonHeat += D_80106530_231EA0_HexagonHeat;
            if (D_80106534_231EA4_HexagonHeat >= 41) {
                D_80106530_231EA0_HexagonHeat = -4;
            }
            if (D_80106534_231EA4_HexagonHeat < 0) {
                D_80106530_231EA0_HexagonHeat = 4;
            }
        } else if (D_80106534_231EA4_HexagonHeat != 0) {
            D_80106534_231EA4_HexagonHeat *= 0.8f;
        }
    }
    for (i = 0; i < 7; i++) {
        if (D_80106520_231E90_HexagonHeat != i) {
            v.x = 128.0f - D_80106550_231EC0_HexagonHeat[i][0];
            v.y = 32.0f - D_80106550_231EC0_HexagonHeat[i][1];
            v.z = 32.0f - D_80106550_231EC0_HexagonHeat[i][2];
            len = func_800B1830_B2430(v.x * v.x + v.y * v.y + v.z * v.z) * D_80106538_231EA8_HexagonHeat;
            func_8002D9AC_2E5AC(&v);
            D_801065A4_231F14_HexagonHeat[i][0] = len * v.x + D_80106550_231EC0_HexagonHeat[i][0];
            D_801065A4_231F14_HexagonHeat[i][1] = len * v.y + D_80106550_231EC0_HexagonHeat[i][1];
            D_801065A4_231F14_HexagonHeat[i][2] = len * v.z + D_80106550_231EC0_HexagonHeat[i][2];
            v.x = 160.0f - D_80106550_231EC0_HexagonHeat[i][0];
            v.y = 32.0f - D_80106550_231EC0_HexagonHeat[i][1];
            v.z = 32.0f - D_80106550_231EC0_HexagonHeat[i][2];
            len = func_800B1830_B2430(v.x * v.x + v.y * v.y + v.z * v.z) * D_80106538_231EA8_HexagonHeat;
            func_8002D9AC_2E5AC(&v);
            D_801065F8_231F68_HexagonHeat[i][0] = len * v.x + D_80106550_231EC0_HexagonHeat[i][0] + D_80106534_231EA4_HexagonHeat;
            D_801065F8_231F68_HexagonHeat[i][1] = len * v.y + D_80106550_231EC0_HexagonHeat[i][1] + D_80106534_231EA4_HexagonHeat;
            D_801065F8_231F68_HexagonHeat[i][2] = len * v.z + D_80106550_231EC0_HexagonHeat[i][2] + D_80106534_231EA4_HexagonHeat;
        }
    }
    v.x = 32.0f;
    v.y = -64.0f;
    v.z = -64.0f;
    len = func_800B1830_B2430(v.x * v.x + v.y * v.y + v.z * v.z) * D_80106538_231EA8_HexagonHeat;
    func_8002D9AC_2E5AC(&v);
    D_801066B4_232024_HexagonHeat.x = len * v.x + 128.0f + D_80106534_231EA4_HexagonHeat;
    D_801066B4_232024_HexagonHeat.y = len * v.y + 128.0f + D_80106534_231EA4_HexagonHeat;
    D_801066B4_232024_HexagonHeat.z = len * v.z + 128.0f + D_80106534_231EA4_HexagonHeat;
}

void func_80103ACC_22F43C_HexagonHeat(void) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

void func_80103AF8_22F468_HexagonHeat(omObjData* obj) {
    omObjData* stomper;
    Vec3f v;
    f32 x;
    s32 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        for (i = 0; i < 6; i++) {
            stomper = D_800FC7B0_FD3B0[i + 2];
            v.x = D_8010664C_231FBC_HexagonHeat[i][0];
            v.y = 0.0f;
            v.z = D_8010664C_231FBC_HexagonHeat[i][1];
            func_8002D9AC_2E5AC(&v);
            stomper->trans.x = HuMathSin(D_801066E0_232050_HexagonHeat) * v.x * D_801066E4_232054_HexagonHeat + D_8010664C_231FBC_HexagonHeat[i][0];
            stomper->trans.y = 550.0f;
            stomper->trans.z = func_800B7890_B8490(D_801066E0_232050_HexagonHeat) * v.z * D_801066E4_232054_HexagonHeat + D_8010664C_231FBC_HexagonHeat[i][1];
            v.x = D_8010667C_231FEC_HexagonHeat[i + 1][0];
            v.y = 0.0f;
            v.z = D_8010667C_231FEC_HexagonHeat[i + 1][1];
            func_8002D9AC_2E5AC(&v);
            x = HuMathSin(D_801066E0_232050_HexagonHeat) * v.x * D_801066E4_232054_HexagonHeat + D_8010667C_231FEC_HexagonHeat[i + 1][0];
            func_80029714_2A314(stomper->model[1], x, 550.0f,
                                func_800B7890_B8490(D_801066E0_232050_HexagonHeat) * v.z * D_801066E4_232054_HexagonHeat + D_8010667C_231FEC_HexagonHeat[i + 1][1]);
            func_8002979C_2A39C(stomper->model[1], 0.0f, D_801066E0_232050_HexagonHeat, 0.0f);
        }
        if (D_801066E4_232054_HexagonHeat == 0.0f) {
            obj->func_ptr = func_80103DEC_22F75C_HexagonHeat;
            for (i = 0; i < 4; i++) {
                D_800BF7E4_C03E4[i][4] = gPlayers[i].character + 0x50;
            }
        }
        D_801066E4_232054_HexagonHeat -= 40.0f;
        D_801066E0_232050_HexagonHeat -= 2.0f;
        if (D_801066E0_232050_HexagonHeat == 80.0f) {
            PlayMusic(0x1B);
        }
    }
    func_80104384_22FCF4_HexagonHeat(obj);
    func_801041BC_22FB2C_HexagonHeat(obj);
}

void func_80103DEC_22F75C_HexagonHeat(omObjData* obj) {
    s16 music;

    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_801066E8_232058_HexagonHeat == 0) {
            func_800691FC_69DFC(0);
        }
        if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
            func_8000C3B8_CFB8();
        }
        D_801066E8_232058_HexagonHeat += 2;
        break;
    case 1:
        D_801066EC_23205C_HexagonHeat -= 2;
        func_80102D30_22E6A0_HexagonHeat();
        if (D_8010653C_231EAC_HexagonHeat != 0) {
            func_8000C398_CF98();
        }
        if (_CheckFlag(0xC) != 0 && D_8010654C_231EBC_HexagonHeat[0] == 1) {
            func_8000C398_CF98();
        }
        break;
    case 2:
        if (D_801066F0_232060_HexagonHeat == 0) {
            if (D_80106548_231EB8_HexagonHeat != -1) {
                func_80079848_7A448((s16)D_80106548_231EB8_HexagonHeat);
            }
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(40);
        }
        if ((func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) && D_80106540_231EB0_HexagonHeat == 0) {
            if (_CheckFlag(0xC) == 0) {
                if (D_8010653C_231EAC_HexagonHeat == 1) {
                    func_800691FC_69DFC(6, gPlayers[D_80106544_231EB4_HexagonHeat].character);
                    func_80019B9C_1A79C(D_800FFFD8_100BD8[D_80106544_231EB4_HexagonHeat], 0xD);
                    func_800732B0_73EB0(D_80106858_2321C8_HexagonHeat[D_80106544_231EB4_HexagonHeat]);
                    gPlayers[D_80106544_231EB4_HexagonHeat].coins_mg_bonus += 10;
                    music = 0x51;
                } else {
                    func_800691FC_69DFC(0x13);
                    music = 0x57;
                }
                PlayMusic(music);
            }
            D_80106540_231EB0_HexagonHeat++;
        }
        D_801066F0_232060_HexagonHeat += 2;
        if (D_80106540_231EB0_HexagonHeat != 0) {
            if (_CheckFlag(0xC) != 0) {
                if (D_80106540_231EB0_HexagonHeat == 30) {
                    if (D_80106544_231EB4_HexagonHeat == 0) {
                        gPlayers[D_80106544_231EB4_HexagonHeat].coins_mg_bonus += 10;
                    }
                    func_8000C3A8_CFA8();
                }
            } else if (D_80106540_231EB0_HexagonHeat == 120) {
                func_8000C3A8_CFA8();
            }
            D_80106540_231EB0_HexagonHeat++;
        }
        D_801066F0_232060_HexagonHeat += 2;
        break;
    case 3:
        if (D_801066F4_232064_HexagonHeat == 0) {
            func_800794A8_7A0A8(40);
        }
        InitFadeOut(0, 20);
        obj->func_ptr = func_80103ACC_22F43C_HexagonHeat;
        D_801066F4_232064_HexagonHeat += 2;
        break;
    }
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_80079614_7A214(40);
        func_800794A8_7A0A8(60);
        obj->func_ptr = func_80103ACC_22F43C_HexagonHeat;
    }
    func_801035D8_22EF48_HexagonHeat();
    func_80104384_22FCF4_HexagonHeat(obj);
    func_801041BC_22FB2C_HexagonHeat(obj);
}

/* Three background actors (models 1-3) hop between four spots each; retail places the third at
   the second actor's z table ([1] instead of [2]). */
void func_801041BC_22FB2C_HexagonHeat(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_801066F8_232068_HexagonHeat == 0) {
            D_801066F8_232068_HexagonHeat = 20;
            D_801066FC_23206C_HexagonHeat = rand8() & 3;
            func_800298A4_2A4A4(obj->model[1], 4, 0);
        }
        if (D_801066F9_232069_HexagonHeat == 0) {
            D_801066F9_232069_HexagonHeat = 30;
            D_80106700_232070_HexagonHeat = rand8() & 3;
            func_800298A4_2A4A4(obj->model[2], 4, 0);
        }
        if (D_801066FA_23206A_HexagonHeat == 0) {
            D_801066FA_23206A_HexagonHeat = 40;
            D_80106704_232074_HexagonHeat = rand8() & 3;
            func_800298A4_2A4A4(obj->model[3], 4, 0);
        }
        D_801066F8_232068_HexagonHeat--;
        D_801066F9_232069_HexagonHeat--;
        D_801066FA_23206A_HexagonHeat--;
        func_80029714_2A314(obj->model[1], D_801067F8_232168_HexagonHeat[0][D_801066FC_23206C_HexagonHeat][0], 50.0f,
                            D_801067F8_232168_HexagonHeat[0][D_801066FC_23206C_HexagonHeat][1]);
        func_80029714_2A314(obj->model[2], D_801067F8_232168_HexagonHeat[1][D_80106700_232070_HexagonHeat][0], 50.0f,
                            D_801067F8_232168_HexagonHeat[1][D_80106700_232070_HexagonHeat][1]);
        func_80029714_2A314(obj->model[3], D_801067F8_232168_HexagonHeat[2][D_80106704_232074_HexagonHeat][0], 50.0f,
                            D_801067F8_232168_HexagonHeat[1][D_80106704_232074_HexagonHeat][1]);
    }
}

/* The lava: its texture scrolls, and a glow (D_80106712, pulsing up to D_80106710) lights the
   vertices within 800 of a point that moves to a new random spot each time the glow dies out. */
void func_80104384_22FCF4_HexagonHeat(omObjData* obj) {
    HmfData* hmf;
    HmfFace* face;
    HmfVtx* vb;
    HmfVtx* vtx;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 t;
    s32 idx;
    s32 i;
    s32 j;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_80106712_232082_HexagonHeat += D_80106714_232084_HexagonHeat;
        if (D_80106710_232080_HexagonHeat < D_80106712_232082_HexagonHeat) {
            D_80106714_232084_HexagonHeat = -D_80106714_232084_HexagonHeat;
        } else if (D_80106712_232082_HexagonHeat <= 0) {
            D_80106714_232084_HexagonHeat = -D_80106714_232084_HexagonHeat;
            D_80106708_232078_HexagonHeat[0] = HuMathSin(D_80106718_232088_HexagonHeat) * 500.0f;
            D_80106708_232078_HexagonHeat[1] = func_800B7890_B8490(D_80106718_232088_HexagonHeat) * 500.0f - 200.0f;
            D_80106718_232088_HexagonHeat = func_8002D958_2E558(rand8() + D_80106718_232088_HexagonHeat);
        }
        D_80106708_232078_HexagonHeat[1] += 2.0f;
        D_8010671C_23208C_HexagonHeat += 0.1f;
    }
    hmf = D_800FC834_FD434[obj->model[0]].hmf;
    func_8002BED4_2CAD4(obj->model[0], 0.0f, D_8010671C_23208C_HexagonHeat, D_801067E4_232154_HexagonHeat[0],
                        D_801067E4_232154_HexagonHeat[1], "m158_00_lwo", 1);
    for (i = 0; i < hmf->unk1A; i++) {
        face = &hmf->unkB4[i];
        for (j = 0; j < face->unk00; j++) {
            idx = face->unk02[j];
            vb = &hmf->unk44[D_800FDBE0_FE7E0][idx];
            vtx = &hmf->unk40[idx];
            dx = vtx->unk00 - D_80106708_232078_HexagonHeat[0];
            dz = vtx->unk04 - D_80106708_232078_HexagonHeat[1];
            dist = func_800B1830_B2430(dz * dz + dx * dx);
            if (dist < 800.0f) {
                t = (800.0f - dist) / 800.0f;
                vb->unk0C[0] = D_80106712_232082_HexagonHeat * t + 100.0f;
                vb->unk0C[1] = D_80106712_232082_HexagonHeat * t + 90.0f;
                vb->unk0C[2] = D_80106712_232082_HexagonHeat * t + 90.0f;
            } else {
                vb->unk0C[0] = 100;
                vb->unk0C[1] = 90;
                vb->unk0C[2] = 90;
            }
        }
    }
}

__asm__(".section .rodata");
const char D_801067CC_23213C_HexagonHeat[20] = "\203}\203O\203}7_bmp";

/* The stage object: the lava model (model 0) and three background actors (3D sprites, models
   1-3) with four spots each on a circle of 700 around (0, -200); the camera; the intro. */
void func_801047B8_230128_HexagonHeat(omObjData* obj) {
    GroundWork* w;
    void* data;
    f32 a;
    u16 id;
    s32 i;

    a = 45.0f;
    obj->model[0] = func_80018A30_19630(0x3E0000, 0xA89);
    func_8003EAF0_3F6F0(D_801067CC_23213C_HexagonHeat, D_801067E4_232154_HexagonHeat);
    obj->trans.x = obj->trans.y = 0.0f;
    obj->trans.z = -200.0f;
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    obj->func_ptr = func_80103AF8_22F468_HexagonHeat;
    w->unk_03 = 1;
    D_8010274C_10334C.x = 50.0f;
    D_8010274C_10334C.y = 300.0f;
    D_8010274C_10334C.z = -100.0f;
    D_800FD474_FE074.x = 312.7f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 2100.0f;
    func_8000BEF8_CAF8(obj, 2, 0.0f);
    func_8000BE8C_CA8C(obj, 0.2f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 0;
    HmfModelObjAttrSet(obj->model[0], 0x20000, 0x20000);
    func_8002D3C0_2DFC0(obj->model[0]);
    func_80029A8C_2A68C(obj->model[0]);
    func_8002A00C_2AC0C(obj->model[0]);
    data = DataRead(0x3E000B);
    id = func_80020EBC_21ABC(data, 0xA89, 8);
    HuMemMemoryFreePerm(data);
    obj->model[1] = D_800F86D8_F92D8[id].unk00;
    func_80021160_21D60(id, 4, 4);
    id = func_8002109C_21C9C(id, 8);
    obj->model[2] = D_800F86D8_F92D8[id].unk00;
    func_80021160_21D60(id, 4, 4);
    id = func_8002109C_21C9C(id, 8);
    obj->model[3] = D_800F86D8_F92D8[id].unk00;
    func_80021160_21D60(id, 4, 4);
    HmfModelObjAttrSet(obj->model[1], 0x70000000, 0x70000000);
    HmfModelObjAttrSet(obj->model[2], 0x70000000, 0x70000000);
    HmfModelObjAttrSet(obj->model[3], 0x70000000, 0x70000000);
    func_80029714_2A314(obj->model[1], 650.0f, 50.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[1], 6.0f, 6.0f, 6.0f);
    func_80029714_2A314(obj->model[2], -650.0f, 50.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[2], 8.0f, 8.0f, 8.0f);
    func_80029714_2A314(obj->model[3], -650.0f, 50.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[3], 9.0f, 9.0f, 9.0f);
    for (i = 0; i < 4; i++) {
        D_801067F8_232168_HexagonHeat[0][i][0] = HuMathSin(a) * 700.0f;
        D_801067F8_232168_HexagonHeat[0][i][1] = func_800B7890_B8490(a) * 700.0f - 200.0f;
        D_801067F8_232168_HexagonHeat[1][i][0] = HuMathSin(a + 15.0f) * 700.0f;
        D_801067F8_232168_HexagonHeat[1][i][1] = func_800B7890_B8490(a + 15.0f) * 700.0f - 200.0f;
        D_801067F8_232168_HexagonHeat[2][i][0] = HuMathSin(a + 45.0f) * 700.0f;
        D_801067F8_232168_HexagonHeat[2][i][1] = func_800B7890_B8490(a + 45.0f) * 700.0f - 200.0f;
        a += 70.0f;
    }
    omSetStatBit(obj, 0xA0);
    PlaySound(0x4AF);
}

/* The distance from obj to the nearest other player (10000 if none is nearer). */
f32 func_80104C80_2305F0_HexagonHeat(omObjData* obj) {
    omObjData* other;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 min;
    s32 i;

    min = 10000.0f;
    for (i = 0; i < 4; i++) {
        other = D_800FFFD8_100BD8[i];
        if (other != obj) {
            dx = obj->trans.x - other->trans.x;
            dz = obj->trans.z - other->trans.z;
            dist = func_800B1830_B2430(dx * dx + dz * dz);
            if (dist <= min) {
                min = dist;
            }
        }
    }
    return min;
}

/* Player hook 0 (before the pad is read): a COM player's pad is saved (func_801051D0 restores it)
   and replaced: while the stompers rise, a COM of difficulty 2+ heads for the centre once they are
   high enough; otherwise, near the end of the wait, it walks to the flag's colour, holds A in the
   air (difficulty 3 also presses 0x2000 near nobody) and jumps when near enough. */
void func_80104D38_2306A8_HexagonHeat(omObjData* obj) {
    MgWork* w;
    omObjData* target;
    Vec3f v;
    f32 x, y, z;
    f32 dist;
    s32 player;
    s32 ground;
    s32 safe;
    s32 port;
    s32 diff;

    w = obj->unk_50;
    player = w->unk_59;
    ground = w->unk_53;
    safe = D_80106520_231E90_HexagonHeat + 1;
    port = w->unk_57;
    if (D_80106544_231EB4_HexagonHeat == player && D_800F8FD0_F9BD0 == 2) {
        w->unk_3C *= 0.8f;
    }
    if (gPlayers[w->unk_59].flags & 1) {
        D_801067EC_23215C_HexagonHeat = ContBtnTrg[port];
        D_801067E8_232158_HexagonHeat = ContBtn[port];
        D_801067F0_232160_HexagonHeat = ContStkX[port];
        D_801067F4_232164_HexagonHeat = ContStkY[port];
        ContStkY[port] = 0;
        ContStkX[port] = 0;
        ContBtnTrg[port] = 0;
        ContBtn[port] = 0;
        if (D_8010654C_231EBC_HexagonHeat[player] != 1 && D_80106520_231E90_HexagonHeat >= 0) {
            diff = gPlayers[w->unk_59].cpu_difficulty;
            x = obj->trans.x;
            y = obj->trans.y;
            z = obj->trans.z;
            target = D_800FC7B0_FD3B0[D_80106520_231E90_HexagonHeat + 1];
            if ((D_80106528_231E98_HexagonHeat == 1) & (diff >= 2)) {
                if (!(D_80106524_231E94_HexagonHeat < D_80106740_2320B0_HexagonHeat[diff]) && ground != 1) {
                    v.x = -x;
                    v.y = 0.0f;
                    v.z = z;
                    func_800B1830_B2430(v.x * v.x + v.z * v.z);
                    func_8002D9AC_2E5AC(&v);
                    ContStkX[port] = v.x * 60.0f * D_80106720_232090_HexagonHeat[diff];
                    ContStkY[port] = v.z * 60.0f * D_80106720_232090_HexagonHeat[diff];
                }
            } else if (D_8010652C_231E9C_HexagonHeat >= 65 - D_80106730_2320A0_HexagonHeat[diff]) {
                if (ground == safe) {
                    return;
                }
                v.x = -(x - target->trans.x);
                v.y = y - target->trans.y;
                v.z = z - target->trans.z;
                dist = func_800B1830_B2430(v.x * v.x + v.z * v.z);
                func_8002D9AC_2E5AC(&v);
                ContStkX[port] = v.x * 60.0f * D_80106720_232090_HexagonHeat[diff];
                ContStkY[port] = v.z * 60.0f * D_80106720_232090_HexagonHeat[diff];
                if (w->unk_38 != 1000.0f) {
                    ContBtn[port] = 0x8000;
                    if ((dist < 150.0f) & (diff == 3) && func_80104C80_2305F0_HexagonHeat(obj) > 120.0f) {
                        ContBtnTrg[port] |= 0x2000;
                    }
                } else if (dist < D_80106720_232090_HexagonHeat[diff] * 450.0f && v.y != 0.0f &&
                           w->unk_40 > D_800BF7C8_C03C8) {
                    ContBtnTrg[port] = 0x8000;
                }
            }
        }
    }
}

/* Player hook 1: a player in the lava (ground 0), or on a hexagon of another colour when the
   stompers come down, is out (bounced up, model hidden); a COM player's real pad is restored. */
void func_801051D0_230B40_HexagonHeat(omObjData* obj) {
    MgWork* w;
    s32 ground;
    s32 player;

    w = obj->unk_50;
    ground = w->unk_53;
    player = w->unk_59;
    if (D_8010654C_231EBC_HexagonHeat[player] != 1) {
        if (ground == 0) {
            D_8010654C_231EBC_HexagonHeat[player] = 1;
            func_80019CA4_1A8A4(obj, 0x26);
            goto out;
        }
        if (D_80106528_231E98_HexagonHeat == 3 && (u32)(ground - 1) < 7 && ground != D_80106520_231E90_HexagonHeat + 1) {
            D_8010654C_231EBC_HexagonHeat[w->unk_59] = 1;
            func_80019CA4_1A8A4(obj, 0x26);
            w->unk_50 |= 0x400;
        out:
            w->unk_38 = -D_800BF7A4_C03A4;
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            func_800797DC_7A3DC(0x111, w->unk_59);
            omVibrate(w->unk_59, 20, 0, 20);
        }
        if (gPlayers[w->unk_59].flags & 1) {
            ContBtnTrg[w->unk_57] = (u16)D_801067EC_23215C_HexagonHeat;
            ContBtn[w->unk_57] = (u16)D_801067E8_232158_HexagonHeat;
            ContStkX[w->unk_57] = (u8)D_801067F0_232160_HexagonHeat;
            ContStkY[w->unk_57] = (u8)D_801067F4_232164_HexagonHeat;
        }
    }
}

/* A fallen player's lava splash: four drops (models 10-13), each restarting every 9 frames at
   the player's position, scaled by D_80106790 as it grows (staggered by D_80106750's -2/-4/-6). */
/* NON_MATCHING: scheduling only (masked 3): retail sets i = 0 before computing the row pointer */
#ifdef NON_MATCHING
void func_8010537C_230CEC_HexagonHeat(omObjData* obj, f32 x, f32 y, f32 z) {
    s32* t;
    f32 s;
    s32 i;

    t = D_80106750_2320C0_HexagonHeat[((MgWork*)obj->unk_50)->unk_59];
    for (i = 0; i < 4; i++) {
        if (t[i] >= 0) {
            if (t[i] == 0) {
                func_80029714_2A314(obj->model[i + 10], x, y + 30.0f, z);
                func_800298A4_2A4A4(obj->model[i + 10], 4, 0);
            }
            if (t[i] < 8) {
                s = D_80106790_232100_HexagonHeat[t[i] / 2];
                func_800297E8_2A3E8(obj->model[i + 10], s, s, 1.0f);
            }
            if (t[i] >= 8) {
                t[i] = -1;
            }
        }
        t[i]++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_8010537C_230CEC_HexagonHeat);
#endif

/* Player hook 20 (an out player's motion; x, y, z its position): far out it is hidden, else it
   bobs in the lava facing outward and splashes. */
void func_801054F8_230E68_HexagonHeat(omObjData* obj, f32* x, f32* y, f32* z) {
    Vec3f unused; /* retail's frame has room for one */
    MgWork* w;
    f32 v;

    w = obj->unk_50;
    if (func_800B1830_B2430(*x * *x + *z * *z) > 2000.0f) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[10], 4, 4);
        func_800298A4_2A4A4(obj->model[11], 4, 4);
        func_800298A4_2A4A4(obj->model[12], 4, 4);
        func_800298A4_2A4A4(obj->model[13], 4, 4);
        return;
    }
    w->unk_3C = func_800B75A8_B81A8(*x, *z);
    w->unk_40 = 25.0f;
    v = w->unk_38;
    if (v > D_800BF7D4_C03D4) {
        v = D_800BF7D4_C03D4;
    }
    *y += v * v * (w->unk_38 >= 0.0f ? -35.0f : 35.0f);
    if (*y <= 0.0f) {
        w->unk_38 = -D_800BF7A4_C03A4;
        *y = 0.0f;
    }
    w->unk_38 += D_800BF7A8_C03A8;
    func_8010537C_230CEC_HexagonHeat(obj, *x, *y, *z);
}

/* A player object: character model and motions (the win motion 0x4E or 0x4F at random, kept in
   D_80106858), four lava splash drops (models 10-13, copies of one model), the hooks. */
void func_801056C4_231034_HexagonHeat(omObjData* obj, s32 dir, s32 arg2, s32 file, u16 player, f32 x, f32 y, f32 z) {
    MgWork* w;
    s32 mot;
    s32 win;
    s32 i;

    D_8010105C_101C5C = 0.5f;
    D_80101300_101F00 = 0.5f;
    func_8000C6FC_D2FC(obj, dir, file, player, 0xA89, 0xA89);
    func_8000BDC4_C9C4(obj, 9, dir | file, 0xA89, 750.0f);
    func_8000CC74_D874(obj, obj->model[9], 1);
    D_8010105C_101C5C = 1.0f;
    D_80101300_101F00 = 1.0f;
    w = obj->unk_50;
    w->unk_48 = 55.0f;
    mot = rand8() < 128 ? 0x4F : 0x4E;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    D_800BF7E4_C03E4[w->unk_59][4] = 0x2D2;
    for (i = 10; i < 14; i++) {
        if (D_801067A0_232110_HexagonHeat < 0) {
            obj->model[i] = D_801067A0_232110_HexagonHeat = LoadFormFile(0x10014, 0x88D);
        } else {
            obj->model[i] = func_80027D3C_2893C(D_801067A0_232110_HexagonHeat);
        }
    }
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1B);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 3, dir | 0x2C, 1, 0);
    func_80019F0C_1AB0C(obj, 4, dir | 0x2D, 1, 0);
    func_80019F0C_1AB0C(obj, 0x1E, dir | 0x2F, 2, 0);
    func_80019F0C_1AB0C(obj, 0x1F, dir | 0x30, 2, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x20, dir | 0x31, 0, 0);
    func_80019F0C_1AB0C(obj, 0x26, dir | 0x1C, 1, 0);
    win = dir | mot;
    func_80019F0C_1AB0C(obj, 0xD, win, 1, 0x78);
    D_80106858_2321C8_HexagonHeat[player] = win;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 2);
    func_8000C024_CC24(obj, 3, 2);
    func_8000C024_CC24(obj, 4, 2);
    func_8000C024_CC24(obj, 5, 2);
    func_8000C024_CC24(obj, 6, 2);
    func_8000C024_CC24(obj, 7, 2);
    func_8000C024_CC24(obj, 8, 2);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0, 0);
    func_8002D2B4_2DEB4(obj->model[0], -96.0f, -17.0f, 69.0f);
    func_8000E0C0_ECC0(w, 0, func_80104D38_2306A8_HexagonHeat);
    func_8000E0C0_ECC0(w, 1, func_801051D0_230B40_HexagonHeat);
    func_8000E0C0_ECC0(w, 20, func_801054F8_230E68_HexagonHeat);
}

void func_80105B78_2314E8_HexagonHeat(omObjData* obj) {
    func_801056C4_231034_HexagonHeat(obj, D_800CD438_CE038[gPlayers[0].character].unk_04, D_800CD438_CE038[gPlayers[0].character].unk_08,
                                     D_800CD438_CE038[gPlayers[0].character].unk_10, 0, -85.0f, 500.0f, -85.0f);
}

/* NON_MATCHING: scheduling only: retail loads the three register arguments before storing the
   stack ones (func_80105B78, whose player argument is 0, matches) */
#ifdef NON_MATCHING
void func_80105BF0_231560_HexagonHeat(omObjData* obj) {
    u8 c = gPlayers[1].character;

    func_801056C4_231034_HexagonHeat(obj, D_800CD438_CE038[c].unk_04, D_800CD438_CE038[c].unk_08,
                                     D_800CD438_CE038[c].unk_10, 1, -85.0f, 500.0f, 85.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105BF0_231560_HexagonHeat);
#endif

/* NON_MATCHING: scheduling only: retail loads the three register arguments before storing the
   stack ones (func_80105B78, whose player argument is 0, matches) */
#ifdef NON_MATCHING
void func_80105C78_2315E8_HexagonHeat(omObjData* obj) {
    u8 c = gPlayers[2].character;

    func_801056C4_231034_HexagonHeat(obj, D_800CD438_CE038[c].unk_04, D_800CD438_CE038[c].unk_08,
                                     D_800CD438_CE038[c].unk_10, 2, 85.0f, 500.0f, -85.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105C78_2315E8_HexagonHeat);
#endif

/* NON_MATCHING: scheduling only: retail loads the three register arguments before storing the
   stack ones (func_80105B78, whose player argument is 0, matches) */
#ifdef NON_MATCHING
void func_80105D00_231670_HexagonHeat(omObjData* obj) {
    u8 c = gPlayers[3].character;

    func_801056C4_231034_HexagonHeat(obj, D_800CD438_CE038[c].unk_04, D_800CD438_CE038[c].unk_08,
                                     D_800CD438_CE038[c].unk_10, 3, 85.0f, 500.0f, 85.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105D00_231670_HexagonHeat);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105D7C_2316EC_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105EF0_231860_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106058_2319C8_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106174_231AE4_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801061B0_231B20_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106204_231B74_HexagonHeat);
