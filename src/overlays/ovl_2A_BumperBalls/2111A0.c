#include "common.h"
#include "ovl_2A.h"

__asm__(".section .rodata");
const char D_8010A0A0_218A40_BumperBalls[] = "152_01f_DEF";

__asm__(".section .rodata");
const char D_8010A0AC_218A4C_BumperBalls[] = "152_01e_DEF";

__asm__(".section .rodata");
const char D_8010A0B8_218A58_BumperBalls[] = "152_01d_DEF";

__asm__(".section .rodata");
const char D_8010A0C4_218A64_BumperBalls[] = "152_01c_DEF";

__asm__(".section .rodata");
const char D_8010A0D0_218A70_BumperBalls[] = "152_01b_DEF";

__asm__(".section .rodata");
const char D_8010A0DC_218A7C_BumperBalls[] = "152_01a_DEF";

__asm__(".section .rodata");
const char D_8010A0E8_218A88_BumperBalls[] = "\202`\202a\202b";

void func_80102800_2111A0_BumperBalls(void) {
    void* data;
    s32 i;

    omInitObjMan(32, 0);
    func_80079128_79D28();
    D_8010A26E_218C0E_BumperBalls = 4;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].flags & 1) {
            D_8010A26E_218C0E_BumperBalls--;
        }
    }
    D_8010A272_218C12_BumperBalls = D_800FA656;
    func_8002D4D0_2E0D0(2);
    func_80020D20_21920(24);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    func_8002CA48_2D648(0, 32, 128);
    func_80029708_2A308(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80020718_21318(0, &func_8002E544_2F144, &D_800FA5B8_FB1B8);
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 44, 44, 64);
    func_80076BD0_777D0(0, 4);
    D_8010A29C_218C3C_BumperBalls = func_80076D80_77980(0);
    func_80076BD0_777D0(1, 4);
    D_8010A2A0_218C40_BumperBalls = func_80076D80_77980(1);
    omSetStatBit(omAddObj(100, 0, 0, -1, &func_801084C8_216E68_BumperBalls), 160);
    if ((D_8010A262_218C02_BumperBalls = _CheckFlag(0xC)) != 0) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].flags & 1) {
                gPlayers[i].cpu_difficulty = D_800FD8AC[0];
            }
        }
    }
    omAddObj(20, 13, 7, 0, &func_8010351C_211EBC_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103558_211EF8_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103574_211F14_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103590_211F30_BumperBalls);
    if (D_8010A272_218C12_BumperBalls == 2) {
        omAddObj(10, 7, 0, 1, &func_80105690_214030_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056AC_21404C_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056C8_214068_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056E4_214084_BumperBalls);
    }
    omAddObj(0, 0, 0, -1, &func_80102C5C_2115FC_BumperBalls);
    D_8010A290_218C30_BumperBalls = omAddObj(6, 3, 0, -1, &func_80102F98_211938_BumperBalls);
    omAddObj(0x2710, 0, 0, -1, &func_80106730_2150D0_BumperBalls);
    D_8010A268_218C08_BumperBalls = func_8001A2F8_1AEF8(0x2F);
    data = DataRead(0x10);
    D_8010A26A_218C0A_BumperBalls = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    data = DataRead(0xF);
    D_8010A26C_218C0C_BumperBalls = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    func_8007273C_7333C((u8*)D_8010A0E8_218A88_BumperBalls, 1);
    D_8010A564_218F04_BumperBalls = 0;
    InitFadeIn(0, 16);
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010A274_218C14_BumperBalls = PlaySound(0x4AF);
    }
}

void func_80102C5C_2115FC_BumperBalls(omObjData* arg0) {
    D_8010A562_218F02_BumperBalls = 0;
    D_8010A298_218C38_BumperBalls = NULL;
    D_8010A294_218C34_BumperBalls = NULL;
    D_8010A266_218C06_BumperBalls = 60;
    D_8010A264_218C04_BumperBalls = 30;
    D_8010A25E_218BFE_BumperBalls = 0;
    D_8010A260_218C00_BumperBalls = 4;
    arg0->func_ptr = &func_80102CB0_211650_BumperBalls;
}

void func_80102CB0_211650_BumperBalls(omObjData* arg0) {
    BumperBallsWork* work;
    s32 i;

    func_8006D4D0_6E0D0(D_8010A266_218C06_BumperBalls);
    switch (D_8010A562_218F02_BumperBalls) {
    case 0:
        if (D_8010A294_218C34_BumperBalls == NULL) {
            D_8010A294_218C34_BumperBalls = omAddObj(4, 0, 0, -1, &func_80105EBC_21485C_BumperBalls);
        }
        break;
    case 1:
        if (D_8010A260_218C00_BumperBalls >= 2) {
            D_8010A264_218C04_BumperBalls--;
        }
        if (D_8010A264_218C04_BumperBalls == 0) {
            if (D_8010A266_218C06_BumperBalls != 0) {
                D_8010A266_218C06_BumperBalls--;
            }
            D_8010A264_218C04_BumperBalls = 30;
        }
        if (D_8010A260_218C00_BumperBalls < 2 || D_8010A266_218C06_BumperBalls == 0) {
            if (func_80107204_215BA4_BumperBalls() == 1) {
                if (D_8010A260_218C00_BumperBalls == 0) {
                    D_8010A562_218F02_BumperBalls = 2;
                    D_8010A560_218F00_BumperBalls = 13;
                } else {
                    D_8010A562_218F02_BumperBalls = 2;
                    if (D_8010A260_218C00_BumperBalls == 1) {
                        D_8010A560_218F00_BumperBalls = 10;
                    } else {
                        D_8010A560_218F00_BumperBalls = 13;
                    }
                    for (i = 0; i < 4; i++) {
                        work = D_8010A29C_218C3C_BumperBalls[i]->unk_50;
                        if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                            work->unk_00 = 6;
                        }
                    }
                }
            }
        }
        if (D_8010A262_218C02_BumperBalls != 0 && func_80107204_215BA4_BumperBalls() == 1) {
            work = D_8010A29C_218C3C_BumperBalls[0]->unk_50;
            if (work->player == 0 && (work->unk_00 == 3 || work->unk_00 == 4 || work->unk_00 == 5)) {
                D_8010A562_218F02_BumperBalls = 2;
                D_8010A560_218F00_BumperBalls = 10;
                for (i = 1; i < 4; i++) {
                    work = D_8010A29C_218C3C_BumperBalls[i]->unk_50;
                    if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                        work->unk_00 = 6;
                    }
                }
            }
        }
        break;
    case 2:
        if (D_8010A298_218C38_BumperBalls == NULL) {
            D_8010A298_218C38_BumperBalls = omAddObj(4, 0, 0, -1, &func_80105FB0_214950_BumperBalls);
        }
        break;
    }
}

void func_80102F98_211938_BumperBalls(omObjData* arg0) {
    Vec eye;
    Vec at;
    s32 attr;

    attr = 0x2A9;
    if (D_8010A272_218C12_BumperBalls != 1) {
        attr |= 0x20000;
    }
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 0.6f;
    }
    arg0->model[0] = LoadFormFile(D_8010A028_2189C8_BumperBalls[D_8010A272_218C12_BumperBalls], attr);
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
    }
    eye.x = 0.0f;
    eye.y = 1589.7578f;
    eye.z = 2404.1443f;
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = -140.0f;
    switch (D_8010A272_218C12_BumperBalls) {
    case 0:
        D_8010A278_218C18_BumperBalls = D_8010A27C_218C1C_BumperBalls = 0.0f;
        arg0->model[1] = LoadFormFile(0x3A000C, 0x689);
        func_8003EAF0_3F6F0("152_yougan2_IA44", &D_8010A280_218C20_BumperBalls);
        func_8003EAF0_3F6F0("152_yougan1_DEF", &D_8010A284_218C24_BumperBalls);
        func_8002A00C_2AC0C(arg0->model[1]);
        func_80029714_2A314(arg0->model[1], 0.0f, 0.0f, -500.0f);
        func_8002D1EC_2DDEC(arg0->model[1], 1);
        func_8002D274_2DE74(arg0->model[1], 255, 255, 255);
        func_8002D2B4_2DEB4(arg0->model[1], 0.0f, -127.0f, 0.0f);
        func_80026D50_27950(1, 1, 1);
        func_80026D50_27950(2, 1, 1);
        func_80026E00_27A00(1, -2.0f, 119.0f, -6.0f);
        func_80026DAC_279AC(2, 255, 95, 0);
        func_80026E00_27A00(2, 7.0f, -119.0f, 12.0f);
        func_8007A27C_7AE7C(0x7FDA, 0, NULL, 20.0f, &eye, &at);
        arg0->func_ptr = &func_80103430_211DD0_BumperBalls;
        omSetStatBit(arg0, 0xA0);
        break;
    case 1:
        func_80026DAC_279AC(1, 40, 40, 255);
        func_80026E00_27A00(1, 23.0f, 117.0f, 10.0f);
        func_80026DAC_279AC(2, 80, 60, 255);
        func_80026E00_27A00(2, -73.0f, 94.0f, 2.0f);
        func_80026DAC_279AC(3, 35, 30, 255);
        func_80026E00_27A00(3, 105.0f, 28.0f, 49.0f);
        D_8010A270_218C10_BumperBalls = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x3A000B), 0, 1);
        espDispOff(D_8010A270_218C10_BumperBalls);
        func_8007A27C_7AE7C(0x7FDA, D_800F93FC_F9FFC[(s16)D_8010A270_218C10_BumperBalls].unk_04, &func_8007A7FC_7B3FC, 20.0f, &eye, &at);
        arg0->func_ptr = NULL;
        break;
    case 2:
        func_80026DAC_279AC(1, 96, 96, 16);
        func_80026E00_27A00(1, 100.0f, 80.0f, 100.0f);
        func_80026DAC_279AC(2, 0, 0, 0);
        func_80026E00_27A00(2, 100.0f, 80.0f, 100.0f);
        func_80026DAC_279AC(3, 0, 0, 0);
        func_80026E00_27A00(3, 100.0f, 80.0f, 100.0f);
        arg0->model[1] = LoadFormFile(0x10002, 0x48D);
        arg0->model[2] = LoadFormFile(0x10003, 0x48D);
        func_8010851C_216EBC_BumperBalls("47mt003_DEF", "47mt002_IA44", 0);
        func_8007A27C_7AE7C(0x7FDA, 0, NULL, 20.0f, &eye, &at);
        arg0->func_ptr = &func_80103414_211DB4_BumperBalls;
        break;
    }
}

void func_80103414_211DB4_BumperBalls(omObjData* arg0) {
    func_80109868_218208_BumperBalls();
}

void func_80103430_211DD0_BumperBalls(omObjData* arg0) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_8010A278_218C18_BumperBalls += 0.1f;
        D_8010A27C_218C1C_BumperBalls -= 0.1f;
    }
    func_8002BED4_2CAD4(arg0->model[1], 0.0f, D_8010A278_218C18_BumperBalls, D_8010A280_218C20_BumperBalls.unk_00, D_8010A280_218C20_BumperBalls.unk_02, "152_02map-grid6_1", 0);
    func_8002BED4_2CAD4(arg0->model[1], 0.0f, D_8010A27C_218C1C_BumperBalls, D_8010A284_218C24_BumperBalls.unk_00, D_8010A284_218C24_BumperBalls.unk_02, "152_02map-grid6_1_1", 0);
}

void func_8010351C_211EBC_BumperBalls(omObjData* arg0) {
    LoadFormFile(0x3A0007, 0x69D);
    func_801035AC_211F4C_BumperBalls(arg0, 0);
}

void func_80103558_211EF8_BumperBalls(omObjData* arg0) {
    func_801035AC_211F4C_BumperBalls(arg0, 1);
}

void func_80103574_211F14_BumperBalls(omObjData* arg0) {
    func_801035AC_211F4C_BumperBalls(arg0, 2);
}

void func_80103590_211F30_BumperBalls(omObjData* arg0) {
    func_801035AC_211F4C_BumperBalls(arg0, 3);
}

/* masked 0: pos and chrBase swap s3/s4 (two attempts at declaration order) */
#ifdef NON_MATCHING
void func_801035AC_211F4C_BumperBalls(omObjData* object, s32 player) {
    s32 chrBase;
    BumperBallsWork* work;
    s32 i;
    u8 pos;
    s32 file;
    s32 mot;
    s8 chr;
    f32 zero;

    if (D_8010A038_2189D8_BumperBalls == 3) {
        for (i = 0; i < 4; i++) {
            if (D_8010A034_2189D4_BumperBalls[i] == 0) {
                pos = i;
                break;
            }
        }
    } else {
        do {
            pos = rand8() & 3;
        } while (D_8010A034_2189D4_BumperBalls[pos] != 0);
    }
    D_8010A034_2189D4_BumperBalls[pos] = 1;
    work = object->unk_50 = func_80027154_27D54(sizeof(BumperBallsWork), 0x7918);
    work->unk_00 = 0;
    work->player = player;
    work->unk_20 = 50.0f;
    work->unk_1C = 0.0f;
    zero = work->unk_1C;
    work->unk_30 = work->unk_34 = work->unk_38 = work->unk_24 = work->unk_2C = zero;
    work->unk_3C = 0;
    work->unk_50 = 0;
    work->unk_60 = NULL;
    work->unk_56 = work->unk_5A = work->unk_52 = work->unk_58 = work->unk_54 = 0;
    work->unk_5C = zero;
    work->unk_3E = 0;
    work->unk_64 = 1;
    work->unk_66 = 0;
    work->unk_42 = 0x200;
    work->unk_44 = work->unk_48 = work->unk_4C = zero;
    for (i = 0; i < 2; i++) {
        work->unk_40[i] = 0;
    }
    chr = gPlayers[player].character;
    work->character = chr;
    chrBase = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 0.6f;
    }
    object->model[0] = LoadFormFile(chrBase | file, 0x206B9);
    omSetTra(object, D_80109FE0_218980_BumperBalls[pos].x, D_80109FE0_218980_BumperBalls[pos].y, D_80109FE0_218980_BumperBalls[pos].z);
    if ((u16)D_800CD438_CE038[chr].unk_00 == 5) {
        work->unk_08 = 10.0f;
        omSetSca(object, 0.95f, 0.95f, 0.95f);
        omSetTra(object, D_80109FE0_218980_BumperBalls[pos].x, D_80109FE0_218980_BumperBalls[pos].y - 10.0f,
                 D_80109FE0_218980_BumperBalls[pos].z);
    } else {
        work->unk_08 = 0.0f;
        omSetSca(object, 1.0f, 1.0f, 1.0f);
    }
    object->model[1] = func_80018A64_19664(0xD, 0x689);
    func_8003C8E0_3D4E0(object->model[1]);
    func_800297E8_2A3E8(object->model[1], 1.25f, 1.25f, 1.25f);
    func_80029714_2A314(object->model[1], object->trans.x, 120.0f, object->trans.z);
    object->model[5] = LoadFormFile(8, 0x68D);
    for (i = 0; i < 4; i++) {
        if (player == 0 && i == 0) {
            object->model[6 + i] = LoadFormFile(0x10014, 0x68D);
        } else {
            object->model[6 + i] = func_80027D3C_2893C(D_8010A29C_218C3C_BumperBalls[0]->model[6]);
        }
    }
    for (i = 0; i < 2; i++) {
        if (player == 0 && i == 0) {
            object->model[10 + i] = LoadFormFile(7, 0x68D);
        } else {
            object->model[10 + i] = func_80027D3C_2893C(D_8010A29C_218C3C_BumperBalls[0]->model[10]);
        }
    }
    func_80018CCC_198CC(object, 0, chrBase | 0x5B);
    func_80018CCC_198CC(object, 1, chrBase | 0x5C);
    func_80018CCC_198CC(object, 2, chrBase | 0x5D);
    if (rand8() & 1) {
        mot = chrBase | 0x4E;
    } else {
        mot = chrBase | 0x4F;
    }
    func_80018CCC_198CC(object, 3, mot);
    work->unk_90 = mot;
    if (rand8() & 1) {
        mot = chrBase | 0x55;
    } else {
        mot = chrBase | 0x56;
    }
    func_80018CCC_198CC(object, 6, mot);
    work->unk_94 = mot;
    switch (D_8010A272_218C12_BumperBalls) {
    case 0:
        func_80018CCC_198CC(object, 4, chrBase | 0x1C);
        func_80018CCC_198CC(object, 5, chrBase | 0xA);
        break;
    case 1:
        func_80018CCC_198CC(object, 4, chrBase | 0xE);
        func_80018CCC_198CC(object, 5, chrBase | 0xA);
        break;
    case 2:
        func_80018CCC_198CC(object, 4, chrBase | 0xE);
        func_80018CCC_198CC(object, 5, chrBase | 0xA);
        break;
    }
    object->model[4] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
    D_800F86D8_F92D8[object->model[4]].unk02 = D_8010A26C_218C0C_BumperBalls;
    HmfModelObjAttrSet(D_800F86D8_F92D8[object->model[4]].unk00, 0x40000000, 0x40000000);
    func_80021160_21D60(object->model[4], 4, 4);
    object->model[3] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
    D_800F86D8_F92D8[object->model[3]].unk02 = D_8010A26A_218C0A_BumperBalls;
    HmfModelObjAttrSet(D_800F86D8_F92D8[object->model[3]].unk00, 0x40000000, 0x40000000);
    func_80021160_21D60(object->model[3], 4, 4);
    object->model[2] = LoadFormFile(0x3A0006, 0x206A9);
    func_8002BB4C_2C74C(object->model[2], (char*)D_8010A0DC_218A7C_BumperBalls, D_8010A010_2189B0_BumperBalls[chr]);
    func_80029A8C_2A68C(object->model[2]);
    work->unk_0C = func_800B75A8_B81A8(-object->trans.x, -object->trans.z);
    if (work->unk_0C < 0.0f) {
        work->unk_0C += 360.0f;
    }
    work->unk_34 = work->unk_14 = work->unk_10 = work->unk_0C;
    omSetRot(object, 0.0f, work->unk_0C, 0.0f);
    func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80029714_2A314(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
    func_80029B80_2A780(object->model[0], object->motion[0]);
    func_80029E80_2AA80(object->model[0], 2, 2);
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
        func_8002D1EC_2DDEC(object->model[0], 1);
        func_8002D1EC_2DDEC(object->model[2], 1);
        func_80109D80_218720_BumperBalls(object);
    }
    work->unk_77 = 0;
    work->unk_78 = 0;
    for (i = 0; i < 4; i++) {
        work->unk_7A[i] = 0;
    }
    object->func_ptr = &func_80103D68_212708_BumperBalls;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801035AC_211F4C_BumperBalls);
#endif

/* float registers of the turn-step clamp (diff in f2, not f4; retail reloads 360 - diff), as in
   MP1's NON_MATCHING func_800F74E8; everything after it matches */
#ifdef NON_MATCHING
void func_80103D68_212708_BumperBalls(omObjData* object) {
    BumperBallsWork* work;
    s8 stickX;
    s8 stickY;
    s16 port;
    f32 diff;
    f32 step;
    f32 speed;
    f32 height;
    f32 dx;
    f32 dz;

    work = object->unk_50;
    if (D_8010A562_218F02_BumperBalls != 1) {
        return;
    }
    port = gPlayers[work->player].port;
    if (!(gPlayers[work->player].flags & 1)) {
        stickX = ContStkX[port];
        stickY = ContStkY[port];
    } else {
        if (work->unk_50 == 0) {
            func_80107254_215BF4_BumperBalls(object);
        }
        func_80107868_216208_BumperBalls(object, &stickX, &stickY);
    }
    if (stickX != 0 || stickY != 0) {
        diff = func_800B75A8_B81A8(stickX, -stickY);
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        work->unk_14 = diff;
    }
    if (work->unk_0C != work->unk_14) {
        diff = work->unk_14 - work->unk_0C;
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        if (diff < 180.0f) {
            work->unk_0C = (diff > 30.0f) ? work->unk_0C + 30.0f : diff + work->unk_0C;
        } else {
            if (360.0f - diff > 30.0f) {
                step = 30.0f;
            } else {
                step = 360.0f - diff;
            }
            work->unk_0C = work->unk_0C - step;
        }
        if (work->unk_0C < 0.0f) {
            work->unk_0C += 360.0f;
        }
        if (work->unk_0C >= 360.0f) {
            work->unk_0C -= 360.0f;
        }
        omSetRot(object, object->rot.x, work->unk_0C, object->rot.z);
        work->unk_34 = work->unk_0C;
        func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    }
    speed = func_800B1830_B2430(stickX * stickX + stickY * stickY) / 100.0f;
    if (work->unk_42 == 0x900) {
        speed *= 0.5f;
    }
    work->unk_24 = HuMathSin(work->unk_0C) * speed + work->unk_24;
    work->unk_2C = func_800B7890_B8490(work->unk_0C) * speed + work->unk_2C;
    if (work->unk_42 == 0x200) {
        work->unk_24 *= 0.96f;
    } else {
        work->unk_24 *= 0.998f;
    }
    if (fabs(work->unk_24) < 0.01f) {
        work->unk_24 = 0.0f;
    }
    if (work->unk_42 == 0x200) {
        work->unk_2C *= 0.96f;
    } else {
        work->unk_2C *= 0.998f;
    }
    if (fabs(work->unk_2C) < 0.01f) {
        work->unk_2C = 0.0f;
    }
    work->unk_24 += work->unk_44;
    work->unk_2C += work->unk_4C;
    height = func_80106C88_215628_BumperBalls(&work->unk_42, &work->unk_44, object->trans.x, object->trans.y + -100.0f, object->trans.z);
    if (height < 120.0f) {
        func_801046B8_213058_BumperBalls(object);
        return;
    }
    if (height < object->trans.y + -100.0f) {
        object->trans.y = object->trans.y - 10.0f;
    }
    if (object->trans.y + -100.0f < height) {
        object->trans.y = height - -100.0f;
    }
    if (func_801067D8_215178_BumperBalls(object) == 1) {
        work->unk_50 = 0;
    }
    if (work->unk_2C != 0.0f || work->unk_24 != 0.0f) {
        work->unk_30 = work->unk_30
            - (f32) (func_800B1830_B2430(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) / -50.0f
                     / 3.141592653589793 * 180.0);
        if (work->unk_30 >= 360.0f) {
            work->unk_30 -= 360.0f;
        }
        if (work->unk_30 < 0.0f) {
            work->unk_30 += 360.0f;
        }
    }
    if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
        if (work->unk_00 != 2) {
            work->unk_00 = 2;
            func_80029BF0_2A7F0(object->model[0], func_80029E14_2AA14(object->motion[2]), 0, 0xA, 2);
            func_80029E80_2AA80(object->model[0], 6, 6);
        }
    } else if (fabs(work->unk_2C) + fabs(work->unk_24) > 1.0 || stickX != 0 || stickY != 0) {
        if (work->unk_00 != 1) {
            work->unk_00 = 1;
            func_80029BF0_2A7F0(object->model[0], func_80029E14_2AA14(object->motion[1]), 0, 0xA, 2);
            func_80029E80_2AA80(object->model[0], 6, 6);
        }
    } else if (work->unk_00 == 1 || work->unk_00 == 2) {
        work->unk_00 = 0;
        func_80029BF0_2A7F0(object->model[0], func_80029E14_2AA14(object->motion[0]), 0, 0x1E, 2);
    }
    if (work->unk_3C == 0) {
        if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
            func_801054DC_213E7C_BumperBalls(object);
            work->unk_3C = 3;
        }
    } else {
        work->unk_3C--;
    }
    if (fabs(work->unk_14 - work->unk_10) > 90.0) {
        dx = HuMathSin(work->unk_10) * 18.0f;
        dz = func_800B7890_B8490(work->unk_10) * 18.0f;
        func_800298A4_2A4A4(object->model[5], 4, 0);
        func_80029714_2A314(object->model[5], dx + object->trans.x, 120.0f, dz + object->trans.z);
        func_8002979C_2A39C(object->model[5], object->rot.x, object->rot.y, 0.0f);
        if (D_800FC834_FD434[object->model[5]].hmf->unk9C != NULL) {
            D_800FC834_FD434[object->model[5]].hmf->unk9C->unk08 = 0;
        }
        func_80029C74_2A874(object->model[5], 0.0f);
    }
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80029714_2A314(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
    func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80029714_2A314(object->model[1], object->trans.x, height, object->trans.z);
    work->unk_10 = work->unk_0C;
    if (D_8010A272_218C12_BumperBalls == 0) {
        func_80109D80_218720_BumperBalls(object);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103D68_212708_BumperBalls);
#endif

void func_801046B8_213058_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    f32 angle;

    work->unk_24 *= 1.2f;
    work->unk_2C *= 1.2f;
    if (func_800B1830_B2430(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) < 15.0f) {
        angle = func_800B75A8_B81A8(object->trans.x, object->trans.z);
        if (D_8010A272_218C12_BumperBalls == 1
            && func_800B1830_B2430(object->trans.x * object->trans.x + object->trans.z * object->trans.z) < 220.0f) {
            work->unk_24 = work->unk_24 - HuMathSin(angle) * 9.0f;
            work->unk_2C = work->unk_2C - func_800B7890_B8490(angle) * 9.0f;
        } else {
            work->unk_24 = HuMathSin(angle) * 9.0f + work->unk_24;
            work->unk_2C = func_800B7890_B8490(angle) * 9.0f + work->unk_2C;
        }
    }
    work->unk_28 = -10.0f;
    D_8010A260_218C00_BumperBalls--;
    func_800298A4_2A4A4(object->model[1], 4, 4);
    func_800797DC_7A3DC(0x111, work->player);
    if (!(gPlayers[work->player].flags & 1)) {
        D_8010A26E_218C0E_BumperBalls--;
    }
    switch (D_8010A272_218C12_BumperBalls) {
    case 0:
        work->unk_00 = 4;
        object->func_ptr = &func_80104950_2132F0_BumperBalls;
        break;
    case 1:
        work->unk_00 = 4;
        object->func_ptr = &func_80105244_213BE4_BumperBalls;
        break;
    case 2:
        work->unk_00 = 3;
        func_80029BF0_2A7F0(object->model[0], func_80029E14_2AA14(object->motion[4]), 0, 0x1E, 2);
        object->func_ptr = &func_80104E04_2137A4_BumperBalls;
        break;
    }
}

void func_80104950_2132F0_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    omObjData* obj;

    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80029714_2A314(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
    func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    if (object->trans.y <= -650.0f) {
        obj = omAddObj(0x14, 1, 0, -1, &func_8010545C_213DFC_BumperBalls);
        obj->model[0] = object->model[2];
        omSetTra(obj, object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
        omSetRot(obj, work->unk_30, work->unk_34, work->unk_30);
        work->unk_00 = 4;
        work->unk_5C = 0.0f;
        func_80029BF0_2A7F0(object->model[0], func_80029E14_2AA14(object->motion[4]), 0, 0xF, 0);
        func_80029E80_2AA80(object->model[0], 2, 2);
        work->unk_24 = 2.0f * work->unk_24;
        work->unk_2C = 2.0f * work->unk_2C;
        work->unk_28 = 80.0f;
        object->func_ptr = &func_80104B70_213510_BumperBalls;
        omVibrate(work->player, 2, 2, 0x14);
    }
}

void func_80104B70_213510_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    s32 i;

    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    if (func_800B1830_B2430(object->trans.x * object->trans.x + object->trans.z * object->trans.z) >= 6000.0f) {
        func_800298A4_2A4A4(object->model[0], 4, 4);
        object->func_ptr = NULL;
    }
    if (object->trans.y <= -600.0f) {
        work->unk_28 = 80.0f;
    }
    if (work->unk_78 == 0) {
        for (i = 0; i < 4; i++) {
            if (work->unk_7A[i] == 0) {
                break;
            }
        }
        if (i != 4) {
            work->unk_7A[i] = 1;
            work->unk_80[i] = 0.5f;
            work->unk_78 = 2;
            func_800298A4_2A4A4(object->model[6 + i], 4, 0);
            func_80029714_2A314(object->model[6 + i], object->trans.x, object->trans.y, object->trans.z);
        }
    } else {
        work->unk_78--;
    }
    for (i = 0; i < 4; i++) {
        if (work->unk_7A[i] != 0) {
            func_800297E8_2A3E8(object->model[6 + i], work->unk_80[i], work->unk_80[i], work->unk_80[i]);
            work->unk_80[i] += 0.2f;
            if (work->unk_80[i] > 2.0f) {
                work->unk_7A[i] = 0;
                func_800298A4_2A4A4(object->model[6 + i], 4, 4);
            }
        }
    }
}

void func_80104E04_2137A4_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    omObjData* obj;
    s16 model;

    if (D_8010A562_218F02_BumperBalls != 1) {
        return;
    }
    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80029714_2A314(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
    func_80029714_2A314(object->model[1], object->trans.x, 120.0f, object->trans.z);
    func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    if (func_80106E94_215834_BumperBalls(object) == 1) {
        work->unk_28 = -work->unk_28;
        work->unk_24 *= 1.1f;
        work->unk_2C *= 1.1f;
    }
    if (object->trans.y < -20.0f && work->unk_3E == 0) {
        work->unk_3E = 1;
        model = D_800F86D8_F92D8[object->model[4]].unk00;
        func_80029714_2A314(model, object->trans.x, 0.0f, object->trans.z + 80.0f);
        func_800297E8_2A3E8(model, 5.0f, 5.0f, 5.0f);
        func_800298A4_2A4A4(model, 4, 0);
        omVibrate(work->player, 2, 2, 0x14);
    }
    if (object->trans.y < -80.0f) {
        omSetTra(object, object->trans.x, -80.0f, object->trans.z);
        model = D_800F86D8_F92D8[object->model[3]].unk00;
        func_80029714_2A314(model, object->trans.x, -60.0f, object->trans.z + 160.0f);
        func_800297E8_2A3E8(model, 10.0f, 10.0f, 10.0f);
        func_800298A4_2A4A4(model, 4, 0);
        obj = omAddObj(0x14, 1, 0, -1, &func_8010545C_213DFC_BumperBalls);
        obj->model[0] = object->model[2];
        omSetTra(obj, object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
        omSetRot(obj, work->unk_30, work->unk_34, work->unk_30);
        work->unk_00 = 4;
        work->unk_5C = 0.0f;
        PlaySound(0x28A);
        object->func_ptr = &func_8010515C_213AFC_BumperBalls;
    }
}

void func_8010515C_213AFC_BumperBalls(omObjData* arg0) {
    BumperBallsWork* temp_s1 = arg0->unk_50;
    s32 temp_v1 = arg0->unk_10;

    if (temp_v1 != 0) {
        arg0->unk_10 = 0;
        if (temp_v1 == 1) {
            temp_s1->unk_00 = 5;
            func_80029BF0_2A7F0(arg0->model[0], func_80029E14_2AA14(arg0->motion[5]), 0, 15, 0);
        }
    }
    if (temp_s1->unk_00 != 5) {
        omSetTra(arg0, arg0->trans.x, (2.0f * HuMathSin(temp_s1->unk_5C)) + arg0->trans.y, arg0->trans.z);
        temp_s1->unk_5C = temp_s1->unk_5C + 8.0f;
        if (temp_s1->unk_5C >= 360.0f) {
            temp_s1->unk_5C = temp_s1->unk_5C - 360.0f;
        }
    }
}

void func_80105244_213BE4_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    f32 angle;
    f32 x;
    f32 z;

    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    angle = func_800B75A8_B81A8(object->trans.x, object->trans.z);
    x = object->trans.x + work->unk_24;
    z = object->trans.z + work->unk_2C;
    if (func_800B1830_B2430(x * x + z * z) < (220.0f - object->trans.y) * 0.5f + 528.0f) {
        x = HuMathSin(angle) * ((220.0f - object->trans.y) * 0.5f + 528.0f);
        z = func_800B7890_B8490(angle) * ((220.0f - object->trans.y) * 0.5f + 528.0f);
    }
    omSetTra(object, x, object->trans.y, z);
    func_80029714_2A314(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
    func_8002979C_2A39C(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    if (object->trans.y <= -650.0f) {
        work->unk_00 = 4;
        work->unk_5C = 0.0f;
        func_800298A4_2A4A4(object->model[2], 4, 4);
        func_800298A4_2A4A4(object->model[0], 4, 4);
        object->func_ptr = NULL;
    }
}

void func_8010545C_213DFC_BumperBalls(omObjData* object) {
    omSetTra(object, object->trans.x, object->trans.y - 20.0f, object->trans.z);
    if (object->trans.y < -3000.0f) {
        func_800298A4_2A4A4(object->model[0], 4, 4);
        omDelObj(object);
    }
}

void func_801054DC_213E7C_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    omObjData* obj;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (work->unk_40[i] == 0) {
            break;
        }
    }
    if (i == 2) {
        return;
    }
    work->unk_40[i] = 1;
    obj = omAddObj(0x28, 0, 0, -1, &func_80105604_213FA4_BumperBalls);
    obj->work[0] = object->model[10 + i];
    obj->work[1] = work->player;
    obj->work[2] = i;
    func_80029714_2A314(obj->work[0], object->trans.x, 120.0f, object->trans.z);
    func_8002979C_2A39C(obj->work[0], object->rot.x, object->rot.y, 0.0f);
    func_800298A4_2A4A4(obj->work[0], 4, 0);
    if (D_800FC834_FD434[obj->work[0]].hmf->unk9C != NULL) {
        D_800FC834_FD434[obj->work[0]].hmf->unk9C->unk08 = 0;
    }
    func_80029C74_2A874(obj->work[0], 0.0f);
}

void func_80105604_213FA4_BumperBalls(omObjData* object) {
    f32 time = func_80029CE4_2A8E4(object->work[0]);

    if (func_80029D0C_2A90C(object->work[0]) <= time) {
        ((BumperBallsWork*)D_8010A29C_218C3C_BumperBalls[object->work[1]]->unk_50)->unk_40[object->work[2]] = 0;
        func_800298A4_2A4A4(object->work[0], 4, 4);
        omDelObj(object);
    }
}

void func_80105690_214030_BumperBalls(omObjData* arg0) {
    func_80105700_2140A0_BumperBalls(arg0, 0);
}

void func_801056AC_21404C_BumperBalls(omObjData* arg0) {
    func_80105700_2140A0_BumperBalls(arg0, 1);
}

void func_801056C8_214068_BumperBalls(omObjData* arg0) {
    func_80105700_2140A0_BumperBalls(arg0, 2);
}

void func_801056E4_214084_BumperBalls(omObjData* arg0) {
    func_80105700_2140A0_BumperBalls(arg0, 3);
}

void func_80105700_2140A0_BumperBalls(omObjData* object, s32 player) {
    BumperBallsBoatWork* work;
    s32 i;

    omSetStatBit(object, 0xA0);
    work = object->unk_50 = func_80027154_27D54(sizeof(BumperBallsBoatWork), 0x7918);
    work->player = player;
    work->state = 0;
    work->model = 1;
    work->model2 = 2;
    work->angle = 0.0f;
    work->speed = 10.0f;
    object->model[0] = -1;
    if (player == 0) {
        object->model[1] = LoadFormFile(0x3A0000, 0x69D);
        object->model[2] = LoadFormFile(0x3A0001, 0x69D);
        object->model[3] = LoadFormFile(0x3A0002, 0x69D);
        object->model[4] = LoadFormFile(0x3A0003, 0x69D);
        object->model[5] = LoadFormFile(0x3A0004, 0x69D);
        object->model[6] = LoadFormFile(0x3A0005, 0x69D);
    } else {
        object->model[1] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[1]);
        object->model[2] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[2]);
        object->model[3] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[3]);
        object->model[4] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[4]);
        object->model[5] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[5]);
        object->model[6] = func_80027D3C_2893C(D_8010A2A0_218C40_BumperBalls[0]->model[6]);
    }
    for (i = 1; i < 7; i++) {
        func_800297E8_2A3E8(object->model[i], 0.7f, 0.7f, 0.7f);
    }
    func_8002A00C_2AC0C(object->model[1]);
    func_8002A00C_2AC0C(object->model[3]);
    func_8002A00C_2AC0C(object->model[5]);
    object->func_ptr = &func_80105948_2142E8_BumperBalls;
}

/* case 4's arrival test: retail joins both compares at one bc1f (j to the branch); GCC here
   branches in each arm (+5 instructions). Everything else matches (MP1 func_800F87F4 is NON_MATCHING too) */
#ifdef NON_MATCHING
void func_80105948_2142E8_BumperBalls(omObjData* object) {
    BumperBallsBoatWork* work = object->unk_50;
    omObjData* ball = D_8010A29C_218C3C_BumperBalls[work->player];
    BumperBallsWork* ballWork = ball->unk_50;
    f32 x;

    if (ballWork->unk_00 != 4 && ballWork->unk_00 != 5) {
        return;
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_8002A15C_2AD5C(object->model[work->model], object->model[work->model2], HuMathSin(work->angle));
        return;
    }
    switch (work->state) {
    case 0:
        work->state = 1;
        if (ball->trans.x < 0.0f) {
            work->side = 1;
            work->dx = 10.0f;
            x = -1200.0f;
            if (ball->trans.x <= -1200.0f) {
                x = -1360.0f;
            }
        } else {
            work->side = 0;
            work->dx = -10.0f;
            x = 1200.0f;
            if (ball->trans.x >= 1200.0f) {
                x = 1360.0f;
            }
        }
        omSetTra(object, x, -150.0f, ball->trans.z);
        work->endX = x;
        func_800298A4_2A4A4(object->model[work->model], 4, 0);
        break;
    case 1:
        object->trans.x = HuMathSin(work->angle) * 4.0f + work->dx + object->trans.x;
        if (func_800B1830_B2430((ball->trans.x - object->trans.x) * (ball->trans.x - object->trans.x)
                                + (ball->trans.z - object->trans.z) * (ball->trans.z - object->trans.z)) <= 80.0f) {
            work->state = 3;
            if (work->side == 1) {
                work->model2 = 3;
            } else {
                work->model2 = 5;
            }
            work->angle = 0.0f;
            work->speed = 5.0f;
            func_80076E54_77A54(ball, 1);
            work->dy = (ball->trans.y - object->trans.y) / (90.0f / work->speed);
        }
        break;
    case 3:
        if (work->side == 1) {
            omSetTra(ball, object->trans.x + 80.0f, object->trans.y + work->dy, object->trans.z);
        } else {
            omSetTra(ball, object->trans.x - 80.0f, object->trans.y + work->dy, object->trans.z);
        }
        if (work->angle + work->speed >= 90.0f) {
            work->state = 2;
            func_800298A4_2A4A4(object->model[work->model], 4, 4);
            if (work->side == 1) {
                work->model = 3;
                work->model2 = 4;
            } else {
                work->model = 5;
                work->model2 = 6;
            }
            work->angle = 0.0f;
            work->speed = 15.0f;
            object->trans.y += 20.0f;
            func_800298A4_2A4A4(object->model[work->model], 4, 0);
        }
        break;
    case 2:
        work->state = 4;
        if (work->side == 1) {
            omSetTra(ball, object->trans.x + 80.0f, object->trans.y, object->trans.z);
        } else {
            omSetTra(ball, object->trans.x - 80.0f, object->trans.y, object->trans.z);
        }
        break;
    case 4:
        object->trans.x = object->trans.x - (HuMathSin(work->angle) * 4.0f + work->dx);
        if (work->side == 1) {
            omSetTra(ball, object->trans.x + 80.0f, object->trans.y, object->trans.z);
        } else {
            omSetTra(ball, object->trans.x - 80.0f, object->trans.y, object->trans.z);
        }
        if ((work->side == 1) ? (object->trans.x < work->endX) : (object->trans.x > work->endX)) {
            func_800298A4_2A4A4(object->model[work->model], 4, 4);
            work->state = 5;
        }
        break;
    case 5:
        return;
    }
    func_8002A15C_2AD5C(object->model[work->model], object->model[work->model2], HuMathSin(work->angle));
    func_80029714_2A314(object->model[work->model], object->trans.x, object->trans.y, object->trans.z);
    work->angle += work->speed;
    if (work->angle >= 360.0f) {
        work->angle -= 360.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105948_2142E8_BumperBalls);
#endif

void func_80105EBC_21485C_BumperBalls(omObjData* arg0) {
    switch (D_8010A564_218F04_BumperBalls) {
    case 0:
        D_8010A564_218F04_BumperBalls = 1;
        break;
    case 1:
        if (func_8008F618_90218() == 0) {
            D_8010A564_218F04_BumperBalls = 2;
            func_800691FC_69DFC(0);
            PlayMusic(0x1E);
        }
        break;
    case 2:
        if (func_80069538_6A138() == 0) {
            D_8010A562_218F02_BumperBalls = 1;
            omDelObj(arg0);
            D_8010A294_218C34_BumperBalls = NULL;
            if (D_8010A272_218C12_BumperBalls == 0) {
                func_80079848_7A448(D_8010A274_218C14_BumperBalls);
            }
            func_800691FC_69DFC(10, D_8010A266_218C06_BumperBalls, 0xA0, 0x20);
        }
        break;
    }
}

void func_80105FB0_214950_BumperBalls(omObjData* arg0) {
    BumperBallsWork* work;
    s32 i;

    switch (D_8010A560_218F00_BumperBalls) {
    case 10:
        if (D_8010A260_218C00_BumperBalls == 1) {
            for (i = 0; i < 4; i++) {
                work = D_8010A29C_218C3C_BumperBalls[i]->unk_50;
                if (work->unk_00 == 6) {
                    D_8010A252_218BF2_BumperBalls = i;
                }
            }
            gPlayers[D_8010A252_218BF2_BumperBalls].coins_mg_bonus += 10;
            func_800794A8_7A0A8(0x96);
            func_800691FC_69DFC(3);
            if (D_8010A262_218C02_BumperBalls == 0) {
                D_8010A560_218F00_BumperBalls = 0;
            } else {
                D_8010A560_218F00_BumperBalls = 12;
                func_80029BF0_2A7F0(D_8010A29C_218C3C_BumperBalls[D_8010A252_218BF2_BumperBalls]->model[0],
                                    func_80029E14_2AA14(D_8010A29C_218C3C_BumperBalls[D_8010A252_218BF2_BumperBalls]->motion[0]), 0, 0x14, 2);
            }
        } else {
            if (D_8010A262_218C02_BumperBalls == 0) {
                func_800691FC_69DFC(0x13);
                D_8010A560_218F00_BumperBalls = 11;
            } else {
                func_800794A8_7A0A8(0x96);
                func_800691FC_69DFC(3);
                D_8010A560_218F00_BumperBalls = 12;
            }
            for (i = 0; i < 4; i++) {
                omObjData* ball = D_8010A29C_218C3C_BumperBalls[i];

                work = ball->unk_50;
                if (work->unk_00 == 6) {
                    func_80029BF0_2A7F0(D_8010A29C_218C3C_BumperBalls[i]->model[0], func_80029E14_2AA14(ball->motion[0]), 0, 0x14, 2);
                }
            }
        }
        func_8006D518_6E118();
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            omObjData* ball = D_8010A29C_218C3C_BumperBalls[i];

            work = ball->unk_50;
            if (work->unk_00 == 6) {
                D_8010A258_218BF8_BumperBalls = ball;
            }
        }
        work = D_8010A258_218BF8_BumperBalls->unk_50;
        if (work->unk_0C > 180.0f) {
            work->unk_0C -= 360.0f;
        }
        if (fabs(work->unk_0C) > 7.0) {
            if (work->unk_0C < 0.0f) {
                D_8010A254_218BF4_BumperBalls = 7.0f;
            } else {
                D_8010A254_218BF4_BumperBalls = -7.0f;
            }
        } else {
            D_8010A254_218BF4_BumperBalls = work->unk_0C;
        }
        D_8010A560_218F00_BumperBalls = 1;
        func_80029BF0_2A7F0(D_8010A258_218BF8_BumperBalls->model[0], func_80029E14_2AA14(D_8010A258_218BF8_BumperBalls->motion[1]), 0, 0xA, 2);
        func_80029E80_2AA80(D_8010A258_218BF8_BumperBalls->model[0], 6, 6);
        break;
    case 1:
        work = D_8010A258_218BF8_BumperBalls->unk_50;
        work->unk_0C += D_8010A254_218BF4_BumperBalls;
        if (D_8010A254_218BF4_BumperBalls < 0.0f) {
            if (work->unk_0C <= 0.0f) {
                work->unk_0C = 0.0f;
                func_80029BF0_2A7F0(D_8010A258_218BF8_BumperBalls->model[0], func_80029E14_2AA14(D_8010A258_218BF8_BumperBalls->motion[0]), 0, 0x14, 2);
                D_8010A560_218F00_BumperBalls = 11;
            }
        } else if (work->unk_0C >= 0.0f) {
            work->unk_0C = 0.0f;
            func_80029BF0_2A7F0(D_8010A258_218BF8_BumperBalls->model[0], func_80029E14_2AA14(D_8010A258_218BF8_BumperBalls->motion[0]), 0, 0x14, 2);
            D_8010A560_218F00_BumperBalls = 11;
        }
        omSetRot(D_8010A258_218BF8_BumperBalls, 0.0f, work->unk_0C, 0.0f);
        break;
    case 11:
        if (func_80069538_6A138() & 2) {
            D_8010A560_218F00_BumperBalls = 2;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            omObjData* ball = D_8010A29C_218C3C_BumperBalls[i];

            work = ball->unk_50;
            if (work->unk_00 == 6) {
                if (D_8010A260_218C00_BumperBalls == 1) {
                    func_80029BF0_2A7F0(D_8010A29C_218C3C_BumperBalls[i]->model[0], func_80029E14_2AA14(ball->motion[3]), 0, 0x1E, 0);
                    func_800732B0_73EB0(work->unk_90);
                    D_8010A252_218BF2_BumperBalls = work->player;
                } else {
                    func_80029BF0_2A7F0(D_8010A29C_218C3C_BumperBalls[i]->model[0],
                                        func_80029E14_2AA14(D_8010A29C_218C3C_BumperBalls[i]->motion[6]), 0, 0x1E, 0);
                    func_800732B0_73EB0(work->unk_94);
                }
                D_8010A03C_2189DC_BumperBalls[D_8010A03A_2189DA_BumperBalls++] = work->player;
            }
        }
        if (D_8010A260_218C00_BumperBalls == 1) {
            PlayMusic(0x51);
            func_800691FC_69DFC(6, gPlayers[D_8010A252_218BF2_BumperBalls].character);
        } else {
            PlayMusic(0x57);
        }
        D_8010A25C_218BFC_BumperBalls = 0x78;
        D_8010A560_218F00_BumperBalls = 8;
        D_8010A250_218BF0_BumperBalls = 0;
        break;
    case 6:
        if (func_80069538_6A138() & 2) {
            D_8010A560_218F00_BumperBalls = 7;
        }
        break;
    case 7:
        D_8010A560_218F00_BumperBalls = 8;
        break;
    case 8:
        if (--D_8010A25C_218BFC_BumperBalls == 0) {
            D_8010A080_218A20_BumperBalls = 1;
        }
        break;
    case 9:
        if (func_8008F618_90218() == 0) {
            D_8010A080_218A20_BumperBalls = 1;
        }
        break;
    case 12:
        D_8010A25C_218BFC_BumperBalls = 0x3C;
        D_8010A560_218F00_BumperBalls = 8;
        break;
    case 13:
        func_800794A8_7A0A8(0x96);
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        for (i = 0; i < 4; i++) {
            omObjData* ball = D_8010A29C_218C3C_BumperBalls[i];

            work = ball->unk_50;
            if (work->unk_00 == 6) {
                func_80029BF0_2A7F0(D_8010A29C_218C3C_BumperBalls[i]->model[0], func_80029E14_2AA14(ball->motion[0]), 0, 0x14, 2);
            }
        }
        if (D_8010A262_218C02_BumperBalls != 0) {
            D_8010A560_218F00_BumperBalls = 12;
        } else {
            D_8010A560_218F00_BumperBalls = 14;
        }
        break;
    case 14:
        if (func_80069538_6A138() & 2) {
            D_8010A560_218F00_BumperBalls = 10;
        }
        break;
    }
}

/* Retail's .rodata pads to 16 bytes after 80105FB0's literals: "47mt003_DEF" (8010A220) starts the
   next retail file's .rodata (MP1's water mesh, 196300.c). No function in between has rodata. */
__asm__(".section .rodata\n\t.balign 16\n\t.text");

/* Ends the minigame when it is over or skipped: fade out, then return to the board. */
void func_80106730_2150D0_BumperBalls(omObjData* arg0) {
    if (D_8010A080_218A20_BumperBalls != 0 || D_801011FC_101DFC != 0) {
        if (D_8010A044_2189E4_BumperBalls == 0) {
            D_8010A044_2189E4_BumperBalls = 1;
            D_8010A562_218F02_BumperBalls = 2;
            D_8010A560_218F00_BumperBalls = 8;
            InitFadeOut(0, 20);
            if (D_8010A262_218C02_BumperBalls == 0) {
                func_800794A8_7A0A8(20);
            }
        } else if (func_8008F618_90218() == 0) {
            func_80108500_216EA0_BumperBalls(0);
        }
    }
}

/* Ball collision: bounces this ball off the first rolling ball it touches. */
u16 func_801067D8_215178_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    BumperBallsWork* otherWork;
    omObjData* other;
    f32 x;
    f32 z;
    f32 dist;
    f32 otherSpeed;
    f32 len;
    f32 nx;
    f32 nz;
    s32 i;

    x = object->trans.x + work->unk_24;
    z = object->trans.z + work->unk_2C;
    for (i = 0; i < 4; i++) {
        other = D_8010A29C_218C3C_BumperBalls[i];
        if (other == object) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 != 1 && otherWork->unk_00 != 2) {
            continue;
        }
        dist = func_800B1830_B2430((other->trans.x - x) * (other->trans.x - x) + (other->trans.z - z) * (other->trans.z - z));
        if (!(dist <= func_800B1830_B2430((work->unk_20 + otherWork->unk_20) * (work->unk_20 + otherWork->unk_20)))) {
            continue;
        }
        dist = func_800B1830_B2430(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C);
        otherSpeed = func_800B1830_B2430(otherWork->unk_24 * otherWork->unk_24 + otherWork->unk_2C * otherWork->unk_2C);
        if (otherSpeed <= dist) {
            func_80106AD8_215478_BumperBalls(dist, work->player);
        } else {
            func_80106AD8_215478_BumperBalls(otherSpeed, otherWork->player);
        }
        omVibrate(work->player, 0xA, 0, 0xA);
        omVibrate(otherWork->player, 0xA, 0, 0xA);
        x = otherWork->unk_24;
        z = otherWork->unk_2C;
        otherWork->unk_24 = work->unk_24 * 1.1f - x * 0.4f;
        otherWork->unk_2C = work->unk_2C * 1.1f - otherWork->unk_2C * 0.4f;
        work->unk_24 = x * 1.1f - work->unk_24 * 0.4f;
        work->unk_2C = z * 1.1f - work->unk_2C * 0.4f;
        if (D_8010A26E_218C0E_BumperBalls == 0) {
            otherWork->unk_24 *= 1.01f;
            otherWork->unk_2C *= 1.01f;
        }
        len = func_800B1830_B2430(otherWork->unk_24 * otherWork->unk_24 + otherWork->unk_2C * otherWork->unk_2C);
        if (len > 22.0f) {
            nx = otherWork->unk_24 / len;
            nz = otherWork->unk_2C / len;
            otherWork->unk_24 = nx * 22.0f;
            otherWork->unk_2C = nz * 22.0f;
        }
        len = func_800B1830_B2430(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C);
        if (len > 22.0f) {
            nx = work->unk_24 / len;
            nz = work->unk_2C / len;
            work->unk_24 = nx * 22.0f;
            work->unk_2C = nz * 22.0f;
        }
        return 1;
    }
    return 0;
}

/* The bump sound, pitched and loudened by the impact speed. */
void func_80106AD8_215478_BumperBalls(f32 speed, u16 player) {
    s16 sound;
    s16 pitch;
    s16 volume;

    if (speed < 8.0f) {
        sound = func_80079798_7A398(0x289, player);
        if (speed < 4.0f) {
            pitch = speed * -25.0f;
        } else {
            pitch = (speed - 4.0f) * 75.0f;
        }
        if (pitch > 300) {
            pitch = 300;
        }
    } else {
        sound = func_80079798_7A398(0x288, player);
        if (speed < 12.0f) {
            pitch = (speed - 8.0f) * -25.0f;
        } else {
            pitch = (speed - 12.0f) * 150.0f;
        }
        if (pitch > 600) {
            pitch = 600;
        }
    }
    volume = speed * 1.9375f;
    if (volume > 31) {
        volume = 31;
    }
    func_800796F0_7A2F0(sound, pitch);
    func_800795D8_7A1D8(sound, volume + 0x60);
}

/* The island's ground height under (x, z), -10000 off the island; the face's surface type goes to
   *surface and a downhill push from its slope to push[0], push[2]. */
f32 func_80106C88_215628_BumperBalls(s16* surface, f32* push, f32 x, f32 y, f32 z) {
    BumperBallsHitProbe probe;
    Vec normal;
    ColVtx* verts;
    u16* tri;
    u16* found;
    f32 best;
    f32 angle;
    f32 h;
    s16 model;

    best = -10000.0f;
    probe.x = x;
    probe.y = y;
    probe.z = z;
    model = D_8010A290_218C30_BumperBalls->model[0];
    verts = D_800FC834_FD434[model].hmf->unk54;
    func_8002F2C4_2FEC4(model, D_800F9D30_FA930, func_80106FCC_21596C_BumperBalls, &probe);
    goto next;
    do {
        h = func_8002DBA4_2E7A4(x, y, z, verts, tri);
        if (best < h) {
            best = h;
            *surface = tri[0] & 0x3FFF;
            found = tri;
        }
    next:
        tri = func_8002F848_30448(D_800F9D30_FA930);
    } while (tri != NULL);
    if (best != -10000.0f) {
        func_8002DA3C_2E63C(&verts[(s16)found[1]], &verts[(s16)found[2]], &verts[(s16)found[3]], &normal);
        angle = func_800B75A8_B81A8(normal.x, normal.z);
        push[0] = -HuMathSin(angle) * (1.0f - normal.y) * -4.0f;
        push[2] = -func_800B7890_B8490(angle) * (1.0f - normal.y) * -4.0f;
    } else {
        push[0] = 0.0f;
        push[1] = 0.0f;
        push[2] = 0.0f;
    }
    return best;
}

/* Lifts the ball onto a floating (or rescued) ball it lands on. */
u16 func_80106E94_215834_BumperBalls(omObjData* object) {
    omObjData* other;
    BumperBallsWork* otherWork;
    f32 top;
    f32 dx;
    f32 dz;
    f32 dist;
    s32 i;

    for (i = 0; i < 4; i++) {
        other = D_8010A29C_218C3C_BumperBalls[i];
        if (object == other) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 != 4 && otherWork->unk_00 != 5) {
            continue;
        }
        dx = other->trans.x;
        top = other->trans.y;
        dz = other->trans.z;
        dx -= object->trans.x;
        dx *= dx;
        dz -= object->trans.z;
        dist = func_800B1830_B2430(dx + dz * dz);
        if (dist <= func_800B1830_B2430(10000.0f)) {
            if (top + 50.0f >= object->trans.y + -50.0f) {
                object->trans.y = object->trans.y + fabs(top + 50.0f - (object->trans.y + -50.0f));
                return 1;
            }
        }
    }
    return 0;
}

/* func_8002F2C4's face filter: the probe's (x, z) inside the face. */
s32 func_80106FCC_21596C_BumperBalls(s32 arg0, u16* polygon, ColVtx* vertices, BumperBallsHitProbe* probe) {
    return func_80106FEC_21598C_BumperBalls(probe, polygon - 1, vertices);
}

s32 func_80106FEC_21598C_BumperBalls(BumperBallsHitProbe* probe, u16* poly, ColVtx* verts) {
    f32 x = probe->x;
    f32 z = probe->z;
    s32 cnt = (poly[0] >> 14) + 2;
    s32 i;
    s32 j;

    poly++;
    if (func_8002DB3C_2E73C(x, z, &verts[(s16)poly[0]], &verts[(s16)poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[(s16)poly[i]], &verts[(s16)poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[(s16)poly[i]], &verts[(s16)poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

/* Whether every ball has fallen (state 3). */
u16 func_80107204_215BA4_BumperBalls(void) {
    u16 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (((BumperBallsWork*)D_8010A29C_218C3C_BumperBalls[i]->unk_50)->unk_00 != 3) {
            count++;
        }
    }
    return (count < 4) ^ 1;
}

/* CPU: picks the next behaviour (1 chase the outermost ball, 2 wait, 3 chase one ball, 4 dodge)
   from the difficulty's table. */
/* register allocation: work and table swap s0/s1 (masked 0; MP1 func_800F9F30 has the same) */
#ifdef NON_MATCHING
void func_80107254_215BF4_BumperBalls(omObjData* object) {
    u16* table;
    BumperBallsWork* work = object->unk_50;
    u16 candidates[4];
    s32 bias;
    u16 count;
    s32 i;

    work->unk_54 = 0;
    if (D_8010A26E_218C0E_BumperBalls != 0) {
        switch (gPlayers[work->player].cpu_difficulty) {
        case 0:
            table = D_8010A048_2189E8_BumperBalls;
            bias = 5;
            break;
        case 1:
            table = D_8010A048_2189E8_BumperBalls;
            bias = 4;
            break;
        case 2:
            table = D_8010A068_218A08_BumperBalls;
            bias = 3;
            break;
        case 3:
            table = D_8010A068_218A08_BumperBalls;
            bias = 2;
            break;
        }
    } else {
        switch (gPlayers[work->player].cpu_difficulty) {
        case 0:
            table = D_8010A058_2189F8_BumperBalls;
            bias = 4;
            break;
        case 1:
            table = D_8010A058_2189F8_BumperBalls;
            bias = 3;
            break;
        case 2:
            table = D_8010A068_218A08_BumperBalls;
            bias = 2;
            break;
        case 3:
            table = D_8010A068_218A08_BumperBalls;
            bias = 2;
            break;
        }
    }
    if (work->unk_64 == 1) {
        work->unk_64 = 0;
        table = D_8010A068_218A08_BumperBalls;
    }
    work->unk_50 = table[rand8() & 7];
    while (1) {
        switch (work->unk_50) {
        case 1:
            work->unk_56 = ((u8)(rand8() % 180) + 180) >> 1;
            work->unk_52 = bias;
            work->unk_58 = 1;
            work->unk_66 = 0;
            return;
        case 2:
            if (work->unk_66 < 3) {
                work->unk_56 = ((u8)(rand8() % 21) + 20) >> 1;
                work->unk_66++;
                return;
            }
            work->unk_50 = 1;
            continue;
        case 3:
            count = 0;
            work->unk_56 = ((u8)(rand8() % 180) + 180) >> 1;
            for (i = 0; i < 4; i++) {
                omObjData* other = D_8010A29C_218C3C_BumperBalls[i];
                BumperBallsWork* otherWork;

                if (object == other) {
                    continue;
                }
                otherWork = other->unk_50;
                if (otherWork->unk_00 == 3 || otherWork->unk_00 == 4) {
                    continue;
                }
                if (otherWork->unk_00 == 5 || otherWork->unk_00 == 6) {
                    continue;
                }
                candidates[count++] = i;
            }
            work->unk_66 = 0;
            if (count == 0) {
                work->unk_50 = 2;
                continue;
            }
            work->unk_60 = D_8010A29C_218C3C_BumperBalls[candidates[rand8() % count]];
            work->unk_52 = bias;
            work->unk_58 = 1;
            return;
        case 4:
            work->unk_56 = ((u8)(rand8() % 180) + 60) >> 1;
            work->unk_66 = 0;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107254_215BF4_BumperBalls);
#endif

/* Whether the ball is out of play (fallen, floating or rescued). */
u16 func_801076A0_216040_BumperBalls(omObjData* arg0) {
    BumperBallsWork* temp_v1 = arg0->unk_50;

    if (temp_v1->unk_00 == 3 || temp_v1->unk_00 == 4 || temp_v1->unk_00 == 5) {
        return 1;
    } else {
        return 0;
    }
}

/* CPU: whether the ball, carried scale times its speed further, is still over the island. */
u16 func_801076D4_216074_BumperBalls(omObjData* object, f32 scale) {
    BumperBallsWork* work = object->unk_50;
    f32 push[3];
    s16 surface;
    f32 t;

    switch (gPlayers[work->player].cpu_difficulty) {
    case 0:
        scale *= 0.65f;
        break;
    case 1:
        scale *= 0.8f;
        break;
    case 2:
        scale *= 0.95f;
        break;
    }
    if (D_8010A26E_218C0E_BumperBalls == 0) {
        scale *= 0.8f;
    }
    t = func_800B1830_B2430(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) * scale;
    D_8010A288_218C28_BumperBalls = t * work->unk_24 + object->trans.x;
    D_8010A28C_218C2C_BumperBalls = t * work->unk_2C + object->trans.z;
    if (func_80106C88_215628_BumperBalls(&surface, push, D_8010A288_218C28_BumperBalls, object->trans.y + -100.0f,
                                         D_8010A28C_218C2C_BumperBalls) < 120.0f) {
        return 0;
    }
    return 1;
}

/* CPU: runs the current behaviour, steering through the stick. */
void func_80107868_216208_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY) {
    switch (((BumperBallsWork*)arg0->unk_50)->unk_50) {
    case 1:
        func_801078FC_21629C_BumperBalls(arg0, stickX, stickY);
        return;
    case 2:
        func_80107C3C_2165DC_BumperBalls(arg0, stickX, stickY);
        return;
    case 3:
        func_80107DD4_216774_BumperBalls(arg0, stickX, stickY);
        return;
    case 4:
        func_80108074_216A14_BumperBalls(arg0, stickX, stickY);
        return;
    }
}

/* CPU behaviour 1: chase the ball farthest from the island's centre. */
void func_801078FC_21629C_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work;
    omObjData* other;
    omObjData* target;
    BumperBallsWork* otherWork;
    f32 best;
    f32 dist;
    s32 i;

    best = -100000.0f;
    work = object->unk_50;
    if (work->unk_54 != 0) {
        *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
        *stickY = -HuMathSin(work->unk_5C) * 80.0f;
        work->unk_54--;
        return;
    }
    if (--work->unk_56 == 0) {
        work->unk_50 = 0;
        func_80107254_215BF4_BumperBalls(object);
        return;
    }
    for (i = 0; i < 4; i++) {
        other = D_8010A29C_218C3C_BumperBalls[i];
        if (other == object) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 == 3 || otherWork->unk_00 == 4) {
            continue;
        }
        if (otherWork->unk_00 == 5) {
            continue;
        }
        dist = func_800B1830_B2430(other->trans.x * other->trans.x + other->trans.z * other->trans.z);
        if (best < dist) {
            target = other;
            best = dist;
        }
    }
    if (best == -100000.0f) {
        *stickX = *stickY = 0;
        return;
    }
    if (--work->unk_58 == 0) {
        work->unk_5C = func_800B75A8_B81A8(target->trans.z - object->trans.z, target->trans.x - object->trans.x);
        if (work->unk_52 < 2) {
            work->unk_58 = 1;
        } else {
            work->unk_58 = rand8() % work->unk_52 + 1;
        }
    }
    if (func_801076D4_216074_BumperBalls(object, 1.05f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
    *stickY = -HuMathSin(work->unk_5C) * 80.0f;
}

/* CPU behaviour 2: wait, keeping away from the edge. */
void func_80107C3C_2165DC_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;

    if (work->unk_54 != 0) {
        *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
        *stickY = -HuMathSin(work->unk_5C) * 80.0f;
        if (--work->unk_54 == 0) {
            work->unk_50 = 0;
        }
        return;
    }
    if (--work->unk_56 == 0) {
        work->unk_50 = 0;
        func_80107254_215BF4_BumperBalls(object);
        return;
    }
    if (func_801076D4_216074_BumperBalls(object, 1.2f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
    } else {
        *stickX = *stickY = 0;
    }
}

/* CPU behaviour 3: chase the chosen ball (unk_60). */
void func_80107DD4_216774_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;
    omObjData* target;

    if (work->unk_54 != 0) {
        *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
        *stickY = -HuMathSin(work->unk_5C) * 80.0f;
        work->unk_54--;
        return;
    }
    if (--work->unk_56 == 0) {
        work->unk_50 = 0;
        func_80107254_215BF4_BumperBalls(object);
        return;
    }
    if (func_801076A0_216040_BumperBalls(work->unk_60) == 1) {
        func_80107254_215BF4_BumperBalls(object);
        func_80107868_216208_BumperBalls(object, stickX, stickY);
        return;
    }
    if (--work->unk_58 == 0) {
        target = work->unk_60;
        work->unk_5C = func_800B75A8_B81A8(target->trans.z - object->trans.z, target->trans.x - object->trans.x);
        if (work->unk_52 < 2) {
            work->unk_58 = 1;
        } else {
            work->unk_58 = rand8() % work->unk_52 + 1;
        }
    }
    if (func_801076D4_216074_BumperBalls(object, 1.1f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
    *stickY = -HuMathSin(work->unk_5C) * 80.0f;
}

/* CPU behaviour 4: dodge, turning in 20-degree steps until no rolling ball lies ahead. */
void func_80108074_216A14_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;
    omObjData* other;
    f32 angles[4];
    u16 count;
    u16 i;
    u16 j;

    if (work->unk_54 != 0) {
        *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
        *stickY = -HuMathSin(work->unk_5C) * 80.0f;
        work->unk_54--;
        return;
    }
    if (--work->unk_56 == 0) {
        work->unk_50 = 0;
        func_80107254_215BF4_BumperBalls(object);
        return;
    }
    count = 0;
    for (i = 0; i < 4; i++) {
        other = D_8010A29C_218C3C_BumperBalls[i];
        if (object != other) {
            u16 state = ((BumperBallsWork*)other->unk_50)->unk_00;

            if (state == 1 || state == 2) {
                angles[count++] = func_800B75A8_B81A8(other->trans.z - object->trans.z, other->trans.x - object->trans.x);
            }
        }
    }
    if (count == 0) {
        work->unk_50 = 0;
        return;
    }
    j = 0;
    do {
        for (i = 0; i < count; i++) {
            if (fabsf(angles[i] - work->unk_5C) <= 20.0f) {
                break;
            }
        }
        if (i == count) {
            break;
        }
        work->unk_5C += 20.0f;
    } while (++j < 18);
    if (func_801076D4_216074_BumperBalls(object, 1.3f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800B7890_B8490(work->unk_5C) * 80.0f;
    *stickY = -HuMathSin(work->unk_5C) * 80.0f;
}

/* A heading away from the island's centre, randomised over 90 degrees. */
f32 func_80108384_216D24_BumperBalls(omObjData* object) {
    f32 angle = func_800B75A8_B81A8(-object->trans.z, -object->trans.x) - 45.0f;

    return angle + (u8)(rand8() % 90);
}

/* Sets the camera (MP1 func_800FB1E0). */
void func_80108410_216DB0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_80018E30_19A30(1);
    func_80018E78_19A78();
    D_800FA610_FB210 = arg1;
    D_800FD474_FE074.x = arg2;
    D_800FD474_FE074.y = arg3;
    D_800FD474_FE074.z = arg4;
    D_8010274C_10334C.x = arg5;
    D_8010274C_10334C.y = arg6;
    D_8010274C_10334C.z = arg7;
    D_800C9B80_CA780->fov[0] = arg0;
}

/* An empty loop over the controllers (MP1 func_800FB298). */
void func_801084C8_216E68_BumperBalls(omObjData* arg0) {
    s32 i;

    for (i = 0; i < gNumOfControllers; i++) {}
}

void func_80108500_216EA0_BumperBalls(omObjData* arg0) {
    omOvlReturnEx(1);
}

__asm__(".section .rodata");
const char D_8010A220_218BC0_BumperBalls[] = "47mt003_DEF";

__asm__(".section .rodata");
const char D_8010A22C_218BCC_BumperBalls[] = "47mt002_IA44";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_8010851C_216EBC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108C70_217610_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80109868_218208_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80109D80_218720_BumperBalls);
