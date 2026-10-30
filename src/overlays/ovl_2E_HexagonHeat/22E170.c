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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801041BC_22FB2C_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80104384_22FCF4_HexagonHeat);

__asm__(".section .rodata");
const char D_801067CC_23213C_HexagonHeat[20] = "\203}\203O\203}7_bmp";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801047B8_230128_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80104C80_2305F0_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80104D38_2306A8_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801051D0_230B40_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_8010537C_230CEC_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801054F8_230E68_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801056C4_231034_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105B78_2314E8_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105BF0_231560_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105C78_2315E8_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105D00_231670_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105D7C_2316EC_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80105EF0_231860_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106058_2319C8_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106174_231AE4_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801061B0_231B20_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80106204_231B74_HexagonHeat);
