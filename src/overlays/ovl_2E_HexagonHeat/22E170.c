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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_801035D8_22EF48_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_8010370C_22F07C_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80103ACC_22F43C_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80103AF8_22F468_HexagonHeat);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HexagonHeat/22E170", func_80103DEC_22F75C_HexagonHeat);

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
