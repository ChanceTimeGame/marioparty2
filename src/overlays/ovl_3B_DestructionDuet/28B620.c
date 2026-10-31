#include "common.h"
#include "ovl_3B.h"

#define DD_CLAMP(x, lo, hi) x = (x < lo) ? lo##f : ((x > hi) ? hi##f : x)
#define DD_TEAMX(s) ((s) / 2 != 0 ? 282.5f : -282.5f)
#define DD_RUN_MODE(p, v)                                                      \
    if (((p)->difficulty == 2 && !(rand8() & 1)) || (p)->difficulty == 3) { \
        v = 2;                                                                 \
    } else {                                                                   \
        v = 1;                                                                 \
    }


#define DD_RUBBLE_Z (D_80108B0C_29192C_DestructionDuet == 0 ? -377.5f : (D_80108B0C_29192C_DestructionDuet == 1 ? -295.0f : -320.0f))


#define DD_TIER(hp) ((u8)((1.0 - ((hp) < 0.0 ? 0.0 : (hp)) / (D_80108B0C_29192C_DestructionDuet * 30.0 + 30.0)) * 6.0))


#define DD_TEAM(g) (D_80108B60_291980_DestructionDuet[1]->unk_50 == (g) || D_80108B60_291980_DestructionDuet[3]->unk_50 == (g) ? 1 : 0)


__asm__(".section .rodata");
const char D_80108430_291250_DestructionDuet[] = "\202`\202a\202b\202c\202d\202e\202f\202g\202h\202i\202j\202k\202l\202m\202n\202o\202p\202q\202r\202s\202t\202u\202v\202w\202x\202y";

void func_80102800_28B620_DestructionDuet(void) {
    u8 cam;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x64, 0);
    func_80079128_79D28();
    func_80029708_2A308(1);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    D_800BF7C0_C03C0 = 15.0f;
    D_800BF7C4_C03C4 = 11.25f;
    D_800BF7C8_C03C8 = 7.5f;
    D_800BF7CC_C03CC = 3.75f;
    D_800BF7BC_C03BC = 4.0f;
    func_8000C578_D178(1);
    func_80026D28_27928(2);
    func_80026E00_27A00(0, 0.0f, 80.0f, 130.0f);
    func_80026DAC_279AC(0, 0x5F, 0x42, 0x6A);
    func_80026E00_27A00(1, 0.0f, 80.0f, 110.0f);
    func_80026DAC_279AC(1, 0, 0, 0);
    omAddObj(0, 0, 0, -1, func_80102D40_28BB60_DestructionDuet);
    omSetStatBit(omAddObj(8, 0, 0, -1, func_80104A2C_28D84C_DestructionDuet), 0xA0);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108AFC_29191C_DestructionDuet = omAddObj(2, 0xE, 0xE, -1, func_80104204_28D024_DestructionDuet);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108AF0_291910_DestructionDuet = omAddObj(2, 1, 1, -1, func_80104550_28D370_DestructionDuet);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108B60_291980_DestructionDuet[0] = omAddObj(2, 3, 3, -1, func_80104668_28D488_DestructionDuet);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108B60_291980_DestructionDuet[1] = omAddObj(2, 3, 3, -1, func_80104684_28D4A4_DestructionDuet);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108B60_291980_DestructionDuet[2] = omAddObj(2, 3, 3, -1, func_801046A0_28D4C0_DestructionDuet);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_80108B60_291980_DestructionDuet[3] = omAddObj(2, 3, 3, -1, func_801046BC_28D4DC_DestructionDuet);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80108B48_291968_DestructionDuet[0] = omAddObj(3, 0xC, 0x3C, -1, func_80106044_28EE64_DestructionDuet);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80108B48_291968_DestructionDuet[1] = omAddObj(3, 0xC, 0x3C, -1, func_801060E0_28EF00_DestructionDuet);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80108B48_291968_DestructionDuet[2] = omAddObj(3, 0xC, 0x3C, -1, func_80106180_28EFA0_DestructionDuet);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80108B48_291968_DestructionDuet[3] = omAddObj(3, 0xC, 0x3C, -1, func_80106220_28F040_DestructionDuet);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_8010835C_29117C_DestructionDuet), 0xA0);
    InitFadeIn(0, 0x1E);
    func_8007273C_7333C(D_80108430_291250_DestructionDuet, 1);
}

void func_80102D40_28BB60_DestructionDuet(omObjData* obj) {
    s32 i;
    DDPlayer** pp;
    DDPlayer** pp2;
    DDPlayer* p;
    s8 team0;
    s8 team1;

    team0 = 0;
    team1 = 2;
    D_80108B18_291938_DestructionDuet = 0;
    D_80108B92_2919B2_DestructionDuet = 0;
    D_80108B14_291934_DestructionDuet = 0;
    D_80108AE4_291904_DestructionDuet = 5;
    D_80108BB8_2919D8_DestructionDuet = 0;
    D_80108AE5_291905_DestructionDuet = 1;
    D_80108B0C_29192C_DestructionDuet = D_800FA656;
    D_80108B04_291924_DestructionDuet[0] = D_80108B04_291924_DestructionDuet[1] = D_80108B0C_29192C_DestructionDuet * 30.0 + 30.0;
    D_80108B1A_29193A_DestructionDuet[0] = D_80108B1A_29193A_DestructionDuet[1] = D_80108B1A_29193A_DestructionDuet[2] = D_80108B1A_29193A_DestructionDuet[3] = 0;
    D_80108B58_291978_DestructionDuet[0] = D_80108B58_291978_DestructionDuet[1] = D_80108B58_291978_DestructionDuet[2] = D_80108B58_291978_DestructionDuet[3] = 0;
    D_80108AE0_291900_DestructionDuet[0] = D_80108AE0_291900_DestructionDuet[1] = D_80108AE0_291900_DestructionDuet[2] = D_80108AE0_291900_DestructionDuet[3] = 0;
    D_80108AED_29190D_DestructionDuet = 0;
    D_80108B7C_29199C_DestructionDuet = 0;
    D_80108B28_291948_DestructionDuet[0].x = D_80108B28_291948_DestructionDuet[0].y = D_80108B28_291948_DestructionDuet[0].z = 0.0f;
    D_80108B28_291948_DestructionDuet[1].x = D_80108B28_291948_DestructionDuet[1].y = D_80108B28_291948_DestructionDuet[1].z = 0.0f;
    D_80108AE8_291908_DestructionDuet = 1.0f;
    D_80108B90_2919B0_DestructionDuet[0] = 6;
    D_80108B90_2919B0_DestructionDuet[1] = 6;
    D_80108B40_291960_DestructionDuet[0] = rand8() & 1;
    D_80108B40_291960_DestructionDuet[1] = rand8() & 1;
    D_80108B40_291960_DestructionDuet[2] = rand8() & 1;
    D_80108B40_291960_DestructionDuet[3] = rand8() & 1;
    for (i = 0; i < 4; i++) {
        D_80108AD0_2918F0_DestructionDuet[i] = &D_80108A50_291870_DestructionDuet[i];
        bzero(D_80108AD0_2918F0_DestructionDuet[i], sizeof(DDPlayer));
        D_80108B80_2919A0_DestructionDuet[i * 2] = D_80108B82_2919A2_DestructionDuet[i * 2] = 0x3C;
    }
    for (i = 0; i < 4; i++) {
        pp = &D_80108AD0_2918F0_DestructionDuet[i];
        (*pp)->player = i;
        (*pp)->port = gPlayers[i].port;
        (*pp)->character = gPlayers[i].character;
        (*pp)->slot = gPlayers[i].group == 0 ? team0++ : team1++;
        pp2 = &D_80108AD0_2918F0_DestructionDuet[i];
        D_80108B0D_29192D_DestructionDuet[(*pp2)->slot] = i;
        p = *pp2;
        p->difficulty = (gPlayers[p->player].flags & 1) ? gPlayers[p->player].cpu_difficulty : -1;
    }
    D_80108AEC_29190C_DestructionDuet = 0;
    D_80108B70_291990_DestructionDuet.x = 0.0f;
    D_80108B70_291990_DestructionDuet.y = 1500.0f;
    D_80108B70_291990_DestructionDuet.z = 3500.0f;
    D_80108B94_2919B4_DestructionDuet.x = 0.0f;
    D_80108B94_2919B4_DestructionDuet.y = 377.0f;
    D_80108B94_2919B4_DestructionDuet.z = 92.5f;
    D_80108B00_291920_DestructionDuet = 16.0f;
    obj->func_ptr = func_801030E4_28BF04_DestructionDuet;
}

void func_801030E4_28BF04_DestructionDuet(void) {
    s16 i;
    u8 a;
    u8 b;

    switch (D_80108B92_2919B2_DestructionDuet) {
    case 0:
        if (D_80108B14_291934_DestructionDuet == 1) {
            func_8000C3B8_CFB8();
            func_8000C3C8_CFC8();
        }
        if (D_80108B14_291934_DestructionDuet == 0x28) {
            for (i = 0; i < 4; i++) {
                omVibrate(D_80108AD0_2918F0_DestructionDuet[i]->player, 1, 4, 0x78);
            }
        }
        if (D_80108B14_291934_DestructionDuet == 0x28) {
            PlaySound(0x30C);
        }
        if (D_80108B14_291934_DestructionDuet == 0x32) {
            for (i = 0; i < 4; i++) {
                func_80019B9C_1A79C(D_80108B48_291968_DestructionDuet[i], 0xC);
            }
        }
        if (D_80108B14_291934_DestructionDuet == 0x64) {
            for (i = 0; i < 4; i++) {
                func_80019B9C_1A79C(D_80108B48_291968_DestructionDuet[i], 0x1F);
            }
        }
        if (D_80108B14_291934_DestructionDuet == 0x64) {
            PlaySound(0x30D);
        }
        if (D_80108B14_291934_DestructionDuet == 0x64 && D_80108B18_291938_DestructionDuet == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x29);
        }
        if (D_80108B14_291934_DestructionDuet == 0x64) {
            for (i = 0; i < 4; i++) {
                omVibrate(D_80108AD0_2918F0_DestructionDuet[i]->player, 2, 2, 0x14);
            }
        }
        if (D_80108B14_291934_DestructionDuet == 0xAC) {
            func_800691FC_69DFC(0);
        }
        if (D_80108B14_291934_DestructionDuet != 0xD9) {
            break;
        }
        D_80108B92_2919B2_DestructionDuet = 1;
        D_80108B14_291934_DestructionDuet = 0;
    case 1:
        if (D_80108B04_291924_DestructionDuet[0] <= 0.0f || D_80108B04_291924_DestructionDuet[1] <= 0.0f) {
            D_80108B92_2919B2_DestructionDuet = 2;
            D_80108B14_291934_DestructionDuet = 0;
            if (D_80108B04_291924_DestructionDuet[0] == D_80108B04_291924_DestructionDuet[1]) {
                D_80108AE4_291904_DestructionDuet = rand8() & 1;
            } else {
                D_80108AE4_291904_DestructionDuet = D_80108B04_291924_DestructionDuet[0] > D_80108B04_291924_DestructionDuet[1];
            }
        } else if (D_80108B14_291934_DestructionDuet >= 0x708) {
            D_80108B92_2919B2_DestructionDuet = 3;
            D_80108B14_291934_DestructionDuet = 0;
            func_8006D4D0_6E0D0(0);
        }
        if (D_80108B14_291934_DestructionDuet == 1) {
            func_800691FC_69DFC(0xA, 0x3C, 0xA0, 0x20);
        }
        if (D_80108B92_2919B2_DestructionDuet != 3) {
            if ((0x708 - D_80108B14_291934_DestructionDuet) / 30 + 1 == 0) {
                if (D_80108B92_2919B2_DestructionDuet == 1) {
                    func_8006D4D0_6E0D0(0);
                }
            } else if (D_80108B92_2919B2_DestructionDuet == 1) {
                func_8006D4D0_6E0D0((0x708 - D_80108B14_291934_DestructionDuet) / 30 + 1);
            }
        }
        break;
    case 2:
        if (D_80108B14_291934_DestructionDuet == 1) {
            func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[11], D_80108AE4_291904_DestructionDuet == 0 ? -282.5f : 282.5f, 125.0f, -345.0f);
            func_800297E8_2A3E8(D_80108AFC_29191C_DestructionDuet->model[11], 5.0f, 5.0f, 5.0f);
            func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[11], 4, 0);
            func_80029E80_2AA80(D_80108AFC_29191C_DestructionDuet->model[11], 3, 0);
            func_800798F8_7A4F8(PlaySound(0x30E), D_80108AE4_291904_DestructionDuet == 0 ? 0x30 : 0x50);
            func_800794A8_7A0A8(0x2D);
            omVibrate(D_80108AD0_2918F0_DestructionDuet[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet]]->player, 0x14, 0, 0x14);
            omVibrate(D_80108AD0_2918F0_DestructionDuet[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet + 1]]->player, 0x14, 0, 0x14);
        }
        if (D_80108B14_291934_DestructionDuet == 0xF) {
            ((GroundWork*)D_80108B60_291980_DestructionDuet[D_80108AE4_291904_DestructionDuet]->unk_50)->unk_14 = 27.5f;
            ((GroundWork*)D_80108B60_291980_DestructionDuet[D_80108AE4_291904_DestructionDuet + 2]->unk_50)->unk_14 = 27.5f;
            func_800298A4_2A4A4(D_80108B60_291980_DestructionDuet[D_80108AE4_291904_DestructionDuet]->model[1], 4, 4);
            func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[2], D_80108AE4_291904_DestructionDuet == 0 ? -282.5f : 282.5f, 0.0f, -345.0f);
            func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[2], 4, 0);
        }
        if (D_80108B14_291934_DestructionDuet == 0x32) {
            D_80108B92_2919B2_DestructionDuet = 3;
            D_80108B14_291934_DestructionDuet = 0;
        }
        break;
    case 3:
        if (D_80108B14_291934_DestructionDuet == 1) {
            if (D_80108AE4_291904_DestructionDuet >= 2) {
                func_800794A8_7A0A8(0x2D);
            }
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
        }
        if (_CheckFlag(0xC) != 0 && D_80108B14_291934_DestructionDuet >= 0x3C) {
            D_80108B92_2919B2_DestructionDuet = 7;
            D_80108B14_291934_DestructionDuet = 0;
        }
        if (D_80108B14_291934_DestructionDuet >= 0xF1) {
            if (D_80108AE4_291904_DestructionDuet == 5) {
                a = DD_TIER(D_80108B04_291924_DestructionDuet[0]);
                b = DD_TIER(D_80108B04_291924_DestructionDuet[1]);
                if (a == b) {
                    D_80108AE4_291904_DestructionDuet = 4;
                    D_80108B92_2919B2_DestructionDuet = 5;
                    D_80108B14_291934_DestructionDuet = 0;
                    for (i = 0; i < 4; i++) {
                        func_80019F0C_1AB0C(D_80108B48_291968_DestructionDuet[i], 0xE, D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[i]->character].unk_04 | 0x55, 1, 0x78);
                    }
                } else {
                    D_80108AE4_291904_DestructionDuet = a < b;
                    D_80108B92_2919B2_DestructionDuet = 4;
                    D_80108B14_291934_DestructionDuet = 0;
                }
            } else {
                D_80108B92_2919B2_DestructionDuet = 4;
                D_80108B14_291934_DestructionDuet = 0;
            }
            if (D_80108B92_2919B2_DestructionDuet == 4 && D_80108B14_291934_DestructionDuet == 0) {
                for (i = 0; i < 4; i++) {
                    if (D_80108AE4_291904_DestructionDuet != D_80108AD0_2918F0_DestructionDuet[i]->slot / 2) {
                        func_80019F0C_1AB0C(D_80108B48_291968_DestructionDuet[i], 0xE, D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[i]->character].unk_04 | 0x55, 1, 0x78);
                    } else {
                        omObjData** o = &D_80108B48_291968_DestructionDuet[i];
                        s32 d = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[i]->character].unk_04;

                        func_8001A12C_1AD2C(*o, 0xD, D_80108B40_291960_DestructionDuet[i] != 0 ? d | 0x4E : d | 0x4F, 1, 0x78, 1);
                        func_8000BDC4_C9C4(D_80108B48_291968_DestructionDuet[i], 9, D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[i]->character].unk_04 | D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[i]->character].unk_0C, 0x4A9, 2750.0f);
                        func_8000CC74_D874(D_80108B48_291968_DestructionDuet[i], D_80108B48_291968_DestructionDuet[i]->model[9], 1);
                        func_80029AFC_2A6FC(D_80108B48_291968_DestructionDuet[i]->model[9]);
                    }
                }
            }
        }
        break;
    case 7:
        if (D_80108B14_291934_DestructionDuet == 1) {
            if (D_80108AE4_291904_DestructionDuet == 5) {
                a = DD_TIER(D_80108B04_291924_DestructionDuet[0]);
                b = DD_TIER(D_80108B04_291924_DestructionDuet[1]);
                if (a == b) {
                    D_80108AE4_291904_DestructionDuet = 4;
                } else {
                    D_80108AE4_291904_DestructionDuet = a < b;
                }
            }
            InitFadeOut(0, 0x14);
            if (D_80108AE4_291904_DestructionDuet != 4) {
                gPlayers[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2]].coins_mg_bonus += 10;
                gPlayers[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2 + 1]].coins_mg_bonus += 10;
            }
        } else if (D_80108B14_291934_DestructionDuet >= 0x19) {
            D_80108B18_291938_DestructionDuet = 1;
        }
        break;
    case 4:
        if (D_80108B14_291934_DestructionDuet == 1) {
            if (D_80108B18_291938_DestructionDuet == 0 && D_801011FC_101DFC == 0) {
                PlayMusic(0x52);
            }
            func_800691FC_69DFC(0x11, D_80108AD0_2918F0_DestructionDuet[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2]]->character, D_80108AD0_2918F0_DestructionDuet[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2 + 1]]->character);
            func_80079518_7A118(0x7F);
            gPlayers[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2]].coins_mg_bonus += 10;
            gPlayers[D_80108B0D_29192D_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2 + 1]].coins_mg_bonus += 10;
        } else if (D_80108B14_291934_DestructionDuet == 0xA8) {
            InitFadeOut(0, 0x14);
        } else if (D_80108B14_291934_DestructionDuet >= 0xC1) {
            D_80108B18_291938_DestructionDuet = 1;
        }
        break;
    case 5:
        if (D_80108B14_291934_DestructionDuet == 1) {
            for (i = 0; i < 4; i++) {
            }
            if (D_80108B18_291938_DestructionDuet == 0 && D_801011FC_101DFC == 0) {
                PlayMusic(0x57);
            }
            func_800691FC_69DFC(0x13);
            func_80079518_7A118(0x7F);
        } else if (D_80108B14_291934_DestructionDuet == 0x78) {
            InitFadeOut(0, 0x14);
        } else if (D_80108B14_291934_DestructionDuet >= 0x91) {
            D_80108B18_291938_DestructionDuet = 1;
        }
        break;
    }
    D_80108B14_291934_DestructionDuet++;
    if (D_80108B18_291938_DestructionDuet != 0 || D_801011FC_101DFC != 0) {
        if (D_801011FC_101DFC != 0) {
            if (D_80108B7C_29199C_DestructionDuet == 0) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_80108B7C_29199C_DestructionDuet++;
            if (D_80108B7C_29199C_DestructionDuet < 0x19) {
                return;
            }
        } else {
            func_800794A8_7A0A8(0x28);
        }
        omOvlReturnEx(1);
    }
}

void func_80104204_28D024_DestructionDuet(omObjData* obj) {
    GroundWork* w;
    s16 i;

    obj->model[0] = func_80018A30_19630(0x4B0006, 0x499);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], 0.0f, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    func_8000BF24_CB24(obj, 0.0f, -670.0f, -380.0f, 670.0f, 250.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    func_8000BFF0_CBF0(obj);
    w->unk_04 = 0;
    obj->model[1] = func_80018A30_19630(0x4B0005, 0x4B9);
    HmfModelObjAttrSet(obj->model[1], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[1], 3, 2);
    func_8002D1EC_2DDEC(obj->model[1], 1);
    func_8002D274_2DE74(obj->model[1], 0xFF, 0xFF, 0xFF);
    func_8002D2B4_2DEB4(obj->model[1], 0.0f, 0.0f, 127.0f);
    for (i = 0; i < 8; i++) {
        obj->model[i + 3] = func_80018A30_19630(0x4B0000, 0x83D);
        HmfModelObjAttrSet(obj->model[i + 3], 0x600, 0x200);
        func_80029E80_2AA80(obj->model[i + 3], 3, 0);
    }
    obj->model[11] = func_80018A30_19630(0x4B0001, 0x83D);
    HmfModelObjAttrSet(obj->model[11], 0x600, 0x200);
    obj->model[2] = func_80018A30_19630(0x4B0007, 0x4BD);
    HmfModelObjAttrSet(obj->model[2], 0x600, 0x400);
    obj->model[12] = func_80018A30_19630(0x4B0008, 0x4B9);
    HmfModelObjAttrSet(obj->model[12], 0x600, 0x400);
    func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[12], -283.5f, 0.0f, -300.0f);
    func_800297E8_2A3E8(D_80108AFC_29191C_DestructionDuet->model[12], 0.8f, 1.0f, 0.8f);
    obj->model[13] = func_80018A30_19630(0x4B0008, 0x4B9);
    HmfModelObjAttrSet(obj->model[13], 0x600, 0x400);
    func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[13], 283.5f, 0.0f, -300.0f);
    func_800297E8_2A3E8(D_80108AFC_29191C_DestructionDuet->model[13], 0.8f, 1.0f, 0.8f);
    obj->func_ptr = NULL;
}

void func_80104550_28D370_DestructionDuet(omObjData* obj) {
    GroundWork* w;

    *obj->model = -1;
    omSetTra(obj, 0.0f, 600.0f, 0.0f);
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    if (obj == D_80108AF0_291910_DestructionDuet) {
        func_8000BF54_CB54(obj, 300.0f, 300.0f, -1000.0f, -1000.0f, 1000.0f, 1000.0f);
    } else {
        func_8000BF54_CB54(obj, 300.0f, 400.0f, -1000.0f, -1000.0f, -100.0f, -250.0f);
    }
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    func_8000BFF0_CBF0(obj);
    w->unk_04 = 0;
}

void func_80104668_28D488_DestructionDuet(omObjData* obj) {
    func_801046D8_28D4F8_DestructionDuet(obj, 0);
}

void func_80104684_28D4A4_DestructionDuet(omObjData* obj) {
    func_801046D8_28D4F8_DestructionDuet(obj, 1);
}

void func_801046A0_28D4C0_DestructionDuet(omObjData* obj) {
    func_801046D8_28D4F8_DestructionDuet(obj, 2);
}

void func_801046BC_28D4DC_DestructionDuet(omObjData* obj) {
    func_801046D8_28D4F8_DestructionDuet(obj, 3);
}

void func_801046D8_28D4F8_DestructionDuet(omObjData* obj, s32 idx) {
    GroundWork* w;

    obj->model[0] = -1;
    omSetTra(obj, !(idx & 1) ? -282.5f : 282.5f, 0.0f, -270.0f);
    if (idx / 2 == 0) {
        obj->model[1] = func_80018A30_19630((4 - D_80108B0C_29192C_DestructionDuet) | 0x4B0000, 0x104B9);
        func_8002CDF0_2D9F0(obj->model[1], 0, 0, 0, 0);
        func_80029714_2A314(obj->model[1], !(idx & 1) ? -282.5f : 282.5f, 1000.0f, D_80108B0C_29192C_DestructionDuet == 0 ? -377.5f : (D_80108B0C_29192C_DestructionDuet == 1 ? -295.0f : -320.0f));
        HmfModelObjAttrSet(obj->model[1], 0x600, 0x400);
        if (idx / 2 == 0) {
            func_8002D1EC_2DDEC(obj->model[1], 1);
            func_8002D274_2DE74(obj->model[1], 0xFF, 0xA2, 0);
            func_8002D2B4_2DEB4(obj->model[1], idx == 0 ? 64.0f : -64.0f, 64.0f, 0.0f);
        }
    }
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    if (idx / 2 == 0) {
        f64 t = D_80108B0C_29192C_DestructionDuet * 40.0 + 250.0;

        func_8000BF54_CB54(obj, t, t * 1.25, -85.0f, -300.0f, 85.0f, 85.0f);
    } else {
        f64 t = D_80108B0C_29192C_DestructionDuet * 40.0 + 250.0;

        func_8000BF54_CB54(obj, t * 0.5, t * 0.75, -85.0f, -900.0f, 85.0f, -800.0f);
    }
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    w->unk_04 = idx % 2 + 1;
}

void func_80104A2C_28D84C_DestructionDuet(omObjData* obj) {
    obj->func_ptr = func_80104A3C_28D85C_DestructionDuet;
}

/* NON_MATCHING: same logic; hoisting of the 50.0 literal and float register choice differ. */
#ifdef NON_MATCHING
void func_80104A3C_28D85C_DestructionDuet(void) {
    s16 i;
    f32 scale;
    f32 t;
    f64 r;
    f64 dv;
    GroundWork* w;
    f64 h;

    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet < 0x28) {
        f32 sn = HuMathSin(D_80108B14_291934_DestructionDuet / 50.0f * 5.0 + 85.0);
        f32 k = (f32)((1.0 - sn) / (1.0 - HuMathSin(85.0f))) / 2.0;

        D_80108B70_291990_DestructionDuet.y = 1500.0 - k * 100.0;
        D_80108B94_2919B4_DestructionDuet.y = k * 100.0 + 377.0;
        D_80108B00_291920_DestructionDuet = 16.0 - k * 10.0;
    } else if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0x28 < 0x1E) {
        f64 d = (D_80108AE5_291905_DestructionDuet * D_80108BB8_2919D8_DestructionDuet) * 3.6875 / 2.0;
        D_80108B70_291990_DestructionDuet.y = d + 1500.0;
        D_80108B94_2919B4_DestructionDuet.y = d + 377.0;
        D_80108AE5_291905_DestructionDuet = -D_80108AE5_291905_DestructionDuet;
        D_80108BB8_2919D8_DestructionDuet = 1;
    } else if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0x46 < 0x1E) {
        f64 d = (D_80108AE5_291905_DestructionDuet * D_80108BB8_2919D8_DestructionDuet) * 3.6875 / 2.0;
        D_80108B70_291990_DestructionDuet.y = d + 1500.0;
        D_80108B94_2919B4_DestructionDuet.y = d + 377.0;
        D_80108AE5_291905_DestructionDuet = -D_80108AE5_291905_DestructionDuet;
        D_80108BB8_2919D8_DestructionDuet = 2;
        if (D_80108B14_291934_DestructionDuet >= 0x60) {
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[0]->model[1], -282.5f, (0x64 - D_80108B14_291934_DestructionDuet) * 200.0 + 25.0, DD_RUBBLE_Z);
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[1]->model[1], 282.5f, (0x64 - D_80108B14_291934_DestructionDuet) * 200.0 + 25.0, DD_RUBBLE_Z);
        }
    } else if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0x64 < 0x1E) {
        f32 angle = rand8() % 360;

        if (D_80108B14_291934_DestructionDuet == 0x64) {
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[0]->model[1], -282.5f, 25.0f, DD_RUBBLE_Z);
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[1]->model[1], 282.5f, 25.0f, DD_RUBBLE_Z);
            D_80108BB8_2919D8_DestructionDuet = 0x14;
            angle = 0.0f;
            for (i = 0; i < 4; i++) {
                func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], (i % 2) * 150.0 + (i / 2 == 1 ? -282.5 : 282.5) - 50.0, 10.0f, -345.0f);
                func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 4, 0);
                func_80029C74_2A874(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 14.0f);
                func_80108318_291138_DestructionDuet(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 0xE);
                D_80108B80_2919A0_DestructionDuet[D_80108AED_29190D_DestructionDuet] = 0;
                D_80108AED_29190D_DestructionDuet = D_80108AED_29190D_DestructionDuet == 7 ? 0 : D_80108AED_29190D_DestructionDuet + 1;
            }
        }
        D_80108B70_291990_DestructionDuet.x = HuMathSin(angle) * 3.6875 / 3.0 * D_80108BB8_2919D8_DestructionDuet;
        D_80108B70_291990_DestructionDuet.y = func_800B7890_B8490(angle) * 3.6875 / 3.0 * D_80108BB8_2919D8_DestructionDuet + 1500.0;
        D_80108B94_2919B4_DestructionDuet.x = HuMathSin(angle) * 3.6875 / 3.0 * D_80108BB8_2919D8_DestructionDuet;
        D_80108B94_2919B4_DestructionDuet.y = func_800B7890_B8490(angle) * 3.6875 / 3.0 * D_80108BB8_2919D8_DestructionDuet + 377.0;
        if (D_80108BB8_2919D8_DestructionDuet > 0) {
            D_80108BB8_2919D8_DestructionDuet--;
        }
    } else if (D_80108B92_2919B2_DestructionDuet == 2 && D_80108B14_291934_DestructionDuet < 0x1F) {
        f64 d;

        D_80108AE5_291905_DestructionDuet = -D_80108AE5_291905_DestructionDuet;
        D_80108BB8_2919D8_DestructionDuet = D_80108B14_291934_DestructionDuet < 0xF ? 8 : (0x1E - D_80108B14_291934_DestructionDuet) * 7 / 15;
        d = (D_80108AE5_291905_DestructionDuet * D_80108BB8_2919D8_DestructionDuet) * 3.6875 / 2.0;
        D_80108B70_291990_DestructionDuet.y = d + 1500.0;
        D_80108B94_2919B4_DestructionDuet.y = d + 377.0;
        func_8002979C_2A39C(D_80108B60_291980_DestructionDuet[D_80108AE4_291904_DestructionDuet]->model[1], -D_80108B14_291934_DestructionDuet / 15.0f * 45.0, 0.0f, 0.0f);
    } else if (D_80108B92_2919B2_DestructionDuet == 4 && D_80108B14_291934_DestructionDuet < 0x32) {
        f32 sn = HuMathSin(D_80108B14_291934_DestructionDuet / 50.0f * 5.0 + 85.0);
        f32 k = 1.0 - (f32)((1.0 - sn) / (1.0 - HuMathSin(85.0f)));

        D_80108B70_291990_DestructionDuet.x = k * (D_80108AE4_291904_DestructionDuet == 1 ? -320.0 : 320.0);
        D_80108B70_291990_DestructionDuet.y = 1500.0 - k * 1150.0;
        D_80108B70_291990_DestructionDuet.z = 3500.0 - k * 2150.0;
        D_80108B94_2919B4_DestructionDuet.x = (D_80108420_291240_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2] + D_80108420_291240_DestructionDuet[D_80108AE4_291904_DestructionDuet * 2 + 1]) / 2.0 * k;
        D_80108B94_2919B4_DestructionDuet.y = (1.0 - k) * 377.0 + k * 150.0;
        D_80108B94_2919B4_DestructionDuet.z = (1.0 - k) * 92.5 + k * 15.0;
        D_80108B00_291920_DestructionDuet = 2.0 * k + 16.0;
    } else if (D_80108B92_2919B2_DestructionDuet < 4) {
        D_80108B70_291990_DestructionDuet.y = 1500.0f;
        D_80108B94_2919B4_DestructionDuet.y = 377.0f;
        D_80108AE5_291905_DestructionDuet = -D_80108AE5_291905_DestructionDuet;
        D_80108BB8_2919D8_DestructionDuet -= D_80108AE5_291905_DestructionDuet * -1 == 1 && D_80108BB8_2919D8_DestructionDuet > 0;
    }
    for (i = 0; i < 8; i++) {
        u16* q = &D_80108B80_2919A0_DestructionDuet[i];
        u16 v = *q;
        u16 n = v + 1;
        u16* r;

        if (v >= 0x2D) {
            n = v;
        }
        *q = n;
        r = &D_80108B80_2919A0_DestructionDuet[i];
        if (*r < 0x1E) {
            func_80029C74_2A874(D_80108AFC_29191C_DestructionDuet->model[i + 3], *r / 30.0 * 70.0 + 14.0);
            func_80108318_291138_DestructionDuet(D_80108AFC_29191C_DestructionDuet->model[i + 3], (s32)(*r / 30.0 * 80.0) + 0xA);
        }
        if (D_80108B80_2919A0_DestructionDuet[i] == 0x1E) {
            func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[i + 3], 4, 4);
        }
    }
    for (i = 0; i < 2; i++) {
        t = DD_TIER(D_80108B04_291924_DestructionDuet[i]);
        dv = 50.0;
        if ((t != D_80108B90_2919B0_DestructionDuet[i]) & (t > 0.0f)) {
            D_80108BB8_2919D8_DestructionDuet = 5;
        }
        r = (D_80108B04_291924_DestructionDuet[i] < 0.0 ? 0.0 : D_80108B04_291924_DestructionDuet[i]) / (D_80108B0C_29192C_DestructionDuet * 30.0 + 30.0);
        scale = 1.0 - (1.0 - r) * 6.0 / dv;
        D_80108B90_2919B0_DestructionDuet[i] = t;
        func_80029C74_2A874(D_80108B60_291980_DestructionDuet[i]->model[1], t > 5.0 ? 75.0f : t * 15.0);
        func_800297E8_2A3E8(D_80108B60_291980_DestructionDuet[i]->model[1], scale * (D_80108B0C_29192C_DestructionDuet == 1 ? 0.9 : (D_80108B0C_29192C_DestructionDuet == 2 ? 0.86 : 1.0)), scale * (D_80108B0C_29192C_DestructionDuet == 1 ? 0.975 : (D_80108B0C_29192C_DestructionDuet == 2 ? 0.95 : 1.0)), scale * (D_80108B0C_29192C_DestructionDuet != 1 && D_80108B0C_29192C_DestructionDuet == 2 ? 0.86 : 0.9));
        if (t >= 4.0f) {
            func_8002CD78_2D978(D_80108B60_291980_DestructionDuet[i]->model[1], t == 4.0f ? 0x1B : 0x32, 0, 0, 0);
        }
        if (D_80108B92_2919B2_DestructionDuet == 1) {
            w = D_80108B60_291980_DestructionDuet[i]->unk_50;
            h = (D_80108B0C_29192C_DestructionDuet * 40.0 + 250.0) * scale;
            w->unk_14 = h;
            w->unk_98 = h * 1.25;
            w = D_80108B60_291980_DestructionDuet[i + 2]->unk_50;
            w->unk_14 = h * 0.5;
            w->unk_98 = h * 0.75;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3B_DestructionDuet/28B620", func_80104A3C_28D85C_DestructionDuet);

__asm__(".section .rodata");
const char D_80108780_2915A0_DestructionDuet[] = "@>";

__asm__(".section .rodata");
const char D_80108784_2915A4_DestructionDuet[] = "";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80108788_2915A8_DestructionDuet[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80108790_2915B0_DestructionDuet[2] = { 0x40180000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80108798_2915B8_DestructionDuet[2] = { 0x41E00000, 0x00000000 };

__asm__(".section .rodata");
const char D_801087A0_2915C0_DestructionDuet[] = "@H";

__asm__(".section .rodata");
const char D_801087A4_2915C4_DestructionDuet[] = "";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087A8_2915C8_DestructionDuet[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_801087B0_2915D0_DestructionDuet[8] = "@.";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087B8_2915D8_DestructionDuet[2] = { 0x3FEB851E, 0xB851EB85 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087C0_2915E0_DestructionDuet[2] = { 0x3FECCCCC, 0xCCCCCCCD };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087C8_2915E8_DestructionDuet[2] = { 0x3FEE6666, 0x66666666 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087D0_2915F0_DestructionDuet[2] = { 0x3FEF3333, 0x33333333 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087D8_2915F8_DestructionDuet[2] = { 0x3FEB851E, 0xB851EB85 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087E0_291600_DestructionDuet[2] = { 0x3FECCCCC, 0xCCCCCCCD };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_801087E8_291608_DestructionDuet[8] = "@D";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_801087F0_291610_DestructionDuet[8] = "@o@";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801087F8_291618_DestructionDuet[2] = { 0x3FF40000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80108800_291620_DestructionDuet[2] = { 0x3FE00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80108808_291628_DestructionDuet[2] = { 0x3FE80000, 0x00000000 };
#endif

void func_80105CFC_28EB1C_DestructionDuet(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    s32 mdl = 0x4B9;
    s32 mtn = 0x49D;

    func_8000C6FC_D2FC(obj, dir, file, player, mdl, mtn);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA2, 0);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, 127.0f, 0.0f);
    func_8000E0C0_ECC0(obj->unk_50, 6, func_80107F48_290D68_DestructionDuet);
    func_8000E0C0_ECC0(obj->unk_50, 9, func_801081F0_291010_DestructionDuet);
    func_8000E0C0_ECC0(obj->unk_50, 0xF, func_80108258_291078_DestructionDuet);
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 7, dir | 5, 1, 0x22);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1B);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 1, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 2, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 2, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019F0C_1AB0C(obj, 0xC, dir | 0x41, 1, 0x78);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 2);
}

void func_80106044_28EE64_DestructionDuet(omObjData* obj) {
    s32 file = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[0]->character].unk_08;
    s32 dir = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[0]->character].unk_04;

    func_80105CFC_28EB1C_DestructionDuet(obj, dir, file, 0, D_80108420_291240_DestructionDuet[D_80108AD0_2918F0_DestructionDuet[0]->slot], 0.0f, -350.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 0;
    obj->func_ptr = func_801063CC_28F1EC_DestructionDuet;
}

void func_801060E0_28EF00_DestructionDuet(omObjData* obj) {
    s32 file = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[1]->character].unk_08;
    s32 dir = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[1]->character].unk_04;

    func_80105CFC_28EB1C_DestructionDuet(obj, dir, file, 1, D_80108420_291240_DestructionDuet[D_80108AD0_2918F0_DestructionDuet[1]->slot], 0.0f, -350.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 1;
    obj->func_ptr = func_801063CC_28F1EC_DestructionDuet;
}

void func_80106180_28EFA0_DestructionDuet(omObjData* obj) {
    s32 file = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[2]->character].unk_08;
    s32 dir = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[2]->character].unk_04;

    func_80105CFC_28EB1C_DestructionDuet(obj, dir, file, 2, D_80108420_291240_DestructionDuet[D_80108AD0_2918F0_DestructionDuet[2]->slot], 0.0f, -350.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 2;
    obj->func_ptr = func_801063CC_28F1EC_DestructionDuet;
}

void func_80106220_28F040_DestructionDuet(omObjData* obj) {
    s32 file = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[3]->character].unk_08;
    s32 dir = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[3]->character].unk_04;

    func_80105CFC_28EB1C_DestructionDuet(obj, dir, file, 3, D_80108420_291240_DestructionDuet[D_80108AD0_2918F0_DestructionDuet[3]->slot], 0.0f, -350.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 3;
    obj->func_ptr = func_801063CC_28F1EC_DestructionDuet;
}

void func_801062C0_28F0E0_DestructionDuet(omObjData* obj, s32 player) {
    s32 file = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[player]->character].unk_08;
    s32 dir = D_800CD438_CE038[D_80108AD0_2918F0_DestructionDuet[player]->character].unk_04;
    f32 x[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    f32 y[4] = { 10.0f, 30.0f, 0.0f, 20.0f };
    f32 z[4] = { 10.0f, -20.0f, 30.0f, 40.0f };
    f32 a = x[player];
    f32 b = y[player];
    f32 c = z[player];

    func_80105CFC_28EB1C_DestructionDuet(obj, dir, file, player, a, b, c);
    obj->func_ptr = func_801063CC_28F1EC_DestructionDuet;
}

#define DD_HITBY(w) (*(s8*)&(w)->unk_55)

/* NON_MATCHING: same logic; register allocation and one stack slot differ. */
#ifdef NON_MATCHING
__asm__(".section .rodata");
const DDVoice D_80108840_291660_DestructionDuet = { { 2, 3, 7, 4, 5, 6 } };

__asm__(".section .rodata");
const DDSpeed D_80108858_291678_DestructionDuet = { { 35.0f, 47.0f, 57.0f, 68.0f } };

__asm__(".section .rodata");
const DDByte4 D_80108868_291688_DestructionDuet = { { 0xF, 0xB, 7, 7 } };

__asm__(".section .rodata");
const DDByte4 D_8010886C_29168C_DestructionDuet = { { 0xD, 8, 8, 3 } };

void func_801063CC_28F1EC_DestructionDuet(omObjData* obj) {
    MgWork* w = obj->unk_50;
    s16 idx = (s8)*(u8*)&w->unk_59;
    DDPlayer* p = D_80108AD0_2918F0_DestructionDuet[idx];
    u16 btn;
    u16 trg;
    u16 btn2;
    u8 stkX;
    u8 stkY;
    u16 stkX16;
    u16 stkY16;
    f32 dist;
    u8 u;
    s16* cd;
    s16 c;
    s32 k;
    u16 dl;
    DDVoice voice;
    DDSpeed speed;
    DDByte4 mods;
    DDByte4 base;
    f32 fx;
    f32 fz;
    f64 v;
    u32 s;
    f32* hp;
    f32 old;

    if (D_80108B92_2919B2_DestructionDuet != 0 || D_80108B14_291934_DestructionDuet >= 2) {
        btn = ContBtn[p->port];
        trg = ContBtnTrg[p->port];
        btn2 = D_800FD410_FE010[p->port];
        stkX = ContStkX[p->port];
        stkY = ContStkY[p->port];
        stkX16 = D_800FC9BE_FD5BE[p->port];
        stkY16 = D_800FD468_FE068[p->port];
        DD_CLAMP(obj->trans.x, -550.0, 550.0);
        DD_CLAMP(obj->trans.z, -320.0, 190.0);
        if (p->difficulty != -1 || D_80108B92_2919B2_DestructionDuet != 1) {
            ContBtn[p->port] = 0;
            ContBtnTrg[p->port] = 0;
            D_800FD410_FE010[p->port] = 0;
            ContStkX[p->port] = 0;
            ContStkY[p->port] = 0;
            D_800FC9BE_FD5BE[p->port] = 0;
            D_800FD468_FE068[p->port] = 0;
        }
        if (D_80108B58_291978_DestructionDuet[idx] == 0 && (D_80108B92_2919B2_DestructionDuet == 4 || D_80108B92_2919B2_DestructionDuet == 5) && w->unk_38 == 1000.0) {
            voice = D_80108840_291660_DestructionDuet;
            D_80108B58_291978_DestructionDuet[idx] = 1;
            w->unk_3C = 0.0f;
            p->mode = 0;
            func_80019B9C_1A79C(obj, D_80108AE4_291904_DestructionDuet == D_80108AD0_2918F0_DestructionDuet[idx]->slot / 2 ? 0xD : 0xE);
            if (D_80108AE4_291904_DestructionDuet == D_80108AD0_2918F0_DestructionDuet[idx]->slot / 2) {
                s32 vc = voice.v[D_80108AD0_2918F0_DestructionDuet[idx]->character] << 16;

                func_800732B0_73EB0(D_80108B40_291960_DestructionDuet[idx] != 0 ? vc | 0x4E : vc | 0x4F);
            }
        }
        if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet < 0x28) {
            ContStkY[p->port] = -0x1E;
        }
        if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0x78 < 0xB) {
            v = (0.5 - func_800B7890_B8490((D_80108B14_291934_DestructionDuet - 0x78) / 15.0f * 180.0) * 0.5) * 180.0;
            if (p->slot & 1) {
                v = -v;
            }
            w->unk_3C = v;
        }
        if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0x96 < 0x14) {
            ContStkY[p->port] = 0x32;
        }
        if (D_80108B92_2919B2_DestructionDuet == 0 && D_80108B14_291934_DestructionDuet - 0xAA < 0xB) {
            v = 180.0 - (D_80108B14_291934_DestructionDuet - 0xAA) * 90.0 / 10.0;
            if (p->slot & 1) {
                v = -v;
            }
            w->unk_3C = v;
        }
        if ((p->difficulty != -1 && D_80108B92_2919B2_DestructionDuet == 1) || (D_80108B92_2919B2_DestructionDuet == 3 && D_80108B14_291934_DestructionDuet >= 0xF)) {
                        func_800B1830_B2430((p->targetX - obj->trans.x) * (p->targetX - obj->trans.x) + (p->targetZ - obj->trans.z) * (p->targetZ - obj->trans.z));
            if (p->mode == 0 && D_80108B92_2919B2_DestructionDuet == 1) {
                DD_RUN_MODE(p, p->mode);
                p->delay = rand8() & 3;
                p->targetX = DD_TEAMX(p->slot);
                p->targetZ = -250.0f;
                p->radius = 150.0f;
            }
            if (D_80108B92_2919B2_DestructionDuet == 3 && D_80108B14_291934_DestructionDuet == 0xF) {
                if (_CheckFlag(0xC) != 0) {
                    p->mode = 0;
                } else if (((p->slot / 2 == 0 && obj->trans.x > 282.5) || (p->slot / 2 == 1 && obj->trans.x < -282.5)) && obj->trans.z < -260.0) {
                    p->mode = 6;
                    p->targetX = p->slot / 2 != 0 ? -300.0f : 300.0f;
                    p->targetZ = 300.0f;
                    p->radius = 125.0f;
                } else {
                    p->mode = 8;
                    p->targetX = D_80108420_291240_DestructionDuet[p->slot];
                    p->targetZ = 15.0f;
                    p->radius = 25.0f;
                }
            } else if (((p->slot / 2 == 0 && obj->trans.x > 282.5) || (p->slot / 2 == 1 && obj->trans.x < -282.5)) && obj->trans.z < -260.0 && D_80108B92_2919B2_DestructionDuet == 1) {
                p->mode = 3;
                p->targetX = p->slot / 2 != 0 ? -350.0f : 350.0f;
                p->targetZ = -40.0f;
                p->radius = 125.0f;
            }
            if (w->unk_38 == 1000.0 && obj->trans.y > 100.0 && D_80108B92_2919B2_DestructionDuet == 1 && (p->mode == 1 || p->mode == 2)) {
                p->mode = 4;
                p->targetX = D_80108420_291240_DestructionDuet[p->slot];
                p->targetZ = 15.0f;
                p->radius = 25.0f;
            }
            if (w->unk_38 != 1000.0 && D_80108B92_2919B2_DestructionDuet == 1 && p->mode == 4) {
                DD_RUN_MODE(p, p->mode);
                p->targetX = DD_TEAMX(p->slot);
                p->targetZ = -250.0f;
                p->radius = 150.0f;
            }
            if (D_80108B92_2919B2_DestructionDuet == 3 && p->mode == 9) {
                                if (func_800B1830_B2430((p->targetX - obj->trans.x) * (p->targetX - obj->trans.x) + (p->targetZ - obj->trans.z) * (p->targetZ - obj->trans.z)) > 40.0) {
                    p->mode = 8;
                    p->targetX = D_80108420_291240_DestructionDuet[p->slot];
                    p->targetZ = 15.0f;
                    p->radius = 25.0f;
                }
            }
                        dist = func_800B1830_B2430((p->targetX - obj->trans.x) * (p->targetX - obj->trans.x) + (p->targetZ - obj->trans.z) * (p->targetZ - obj->trans.z));
            if (dist < p->radius && p->delay == 0 && (D_80108B92_2919B2_DestructionDuet != 1 || D_80108B14_291934_DestructionDuet >= 4)) {
                switch (p->mode) {
                case 1:
                    if (rand8() % 3 != 0) {
                        break;
                    }
                case 2:
                    ContBtn[p->port] |= 0x4000;
                    ContBtnTrg[p->port] |= 0x4000;
                    break;
                case 3:
                    DD_RUN_MODE(p, p->mode);
                    p->targetX = DD_TEAMX(p->slot);
                    p->targetZ = -250.0f;
                    p->radius = 150.0f;
                    break;
                case 6:
                    p->mode = 8;
                    p->targetX = D_80108420_291240_DestructionDuet[p->slot];
                    p->targetZ = 15.0f;
                    p->radius = 25.0f;
                    break;
                case 8:
                    p->mode = 9;
                    p->targetX = obj->trans.x;
                    p->targetZ = obj->trans.z;
                    p->radius = 10000.0f;
                    p->delay = 0xA;
                    break;
                case 9:
                    p->mode = 0;
                    w->unk_3C = 0.0f;
                    break;
                }
            }
            if (D_80108B92_2919B2_DestructionDuet == 3 && D_80108B14_291934_DestructionDuet < 0xE1 && _CheckFlag(0xC) == 0 && D_80108AD0_2918F0_DestructionDuet[0]->mode == 0 && D_80108AD0_2918F0_DestructionDuet[1]->mode == 0 && D_80108AD0_2918F0_DestructionDuet[2]->mode == 0 && D_80108AD0_2918F0_DestructionDuet[3]->mode == 0) {
                D_80108B14_291934_DestructionDuet = 0xE1;
            }
            if (p->mode == 2 && dist < p->radius + 12.5 && p->delay == 0 && rand8() % 3 == 0) {
                ContBtn[p->port] |= 0x8000;
                ContBtnTrg[p->port] |= 0x8000;
            }
            if (p->frames % (p->mode == 6 || p->mode == 8 ? 20 : 30) == (p->mode == 6 || p->mode == 8 ? 19 : 29)) {
                D_80108B58_291978_DestructionDuet[idx] = 0xA;
            }
            if (D_80108B58_291978_DestructionDuet[idx] != 0) {
                ContBtn[p->port] |= 0x8000;
                ContBtnTrg[p->port] |= 0x8000;
            }
            k = idx;
            u = D_80108B58_291978_DestructionDuet[k];
            if (u != 0) {
                u--;
            }
            D_80108B58_291978_DestructionDuet[k] = u;
            if (p->mode != 0 && p->delay == 0) {
                speed = D_80108858_291678_DestructionDuet;
                fx = (p->targetX - obj->trans.x) / dist * (p->mode < 6 ? (p->difficulty != -1 ? speed.v[p->difficulty] : 0.0f) : 45.0);
                fz = (p->targetZ - obj->trans.z) / dist * -(p->mode < 6 ? (p->difficulty != -1 ? speed.v[p->difficulty] : 0.0f) : 45.0);
                if (w->unk_40 > 10.0 && p->mode == 2 && dist < p->radius + 20.0 && p->delay == 0) {
                    fx = fx * 0.5;
                    fz = fz * 0.5;
                }
                ContStkX[p->port] = fx * 0.5 + p->stickX * 0.5;
                ContStkY[p->port] = fz * 0.5 + p->stickY * 0.5;
            }
            dl = p->delay;
            if (dl != 0) {
                dl--;
            }
            p->delay = dl;
        }
        func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[0]);
        func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[1]);
        func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[2]);
        func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[3]);
        if (!(func_80019000_19C00(obj) & 0x40)) {
            D_80108BC0_2919E0_DestructionDuet[idx].x = D_80108B48_291968_DestructionDuet[idx]->trans.x;
            D_80108BC0_2919E0_DestructionDuet[idx].y = D_80108B48_291968_DestructionDuet[idx]->trans.y;
            D_80108BC0_2919E0_DestructionDuet[idx].z = D_80108B48_291968_DestructionDuet[idx]->trans.z;
        }
        func_80007790_8390(obj);
        if (func_80019000_19C00(obj) & 0x40) {
            D_80108B48_291968_DestructionDuet[idx]->trans.x = D_80108BC0_2919E0_DestructionDuet[idx].x;
            D_80108B48_291968_DestructionDuet[idx]->trans.y = D_80108BC0_2919E0_DestructionDuet[idx].y;
            D_80108B48_291968_DestructionDuet[idx]->trans.z = D_80108BC0_2919E0_DestructionDuet[idx].z;
        }
        p->stickX = ContStkX[p->port];
        p->stickY = ContStkY[p->port];
        p->frames = w->unk_54 == -1 ? 0 : p->frames + 1;
        func_8002D2B4_2DEB4(obj->model[0], 0.0f - obj->trans.x, 300.0f - obj->trans.y, -380.0f - obj->trans.z);
        if (D_800FC834_FD434[obj->model[1]].pos.y > 100.0) {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        } else {
            func_800298A4_2A4A4(obj->model[1], 4, 0);
        }
        cd = &D_80108B1A_29193A_DestructionDuet[idx];
        c = *cd;
        if (c > 0) {
            c--;
        }
        *cd = c;
        if (DD_HITBY(w) > 0) {
            if (func_80019000_19C00(obj) & 0x100) {
                w->unk_40 = w->unk_40 * D_80108AE8_291908_DestructionDuet;
            } else {
                w->unk_40 = 0.0f;
            }
            if (func_80019000_19C00(obj) & 0x40) {
                func_80029714_2A314(obj->model[6], D_800FC834_FD434[obj->model[6]].pos.x, D_800FC834_FD434[obj->model[6]].pos.y, D_800FC834_FD434[obj->model[6]].pos.z + 50.0);
            }
            if (D_80108B1A_29193A_DestructionDuet[idx] == 0) {
                mods = D_80108868_291688_DestructionDuet;
                base = D_8010886C_29168C_DestructionDuet;
                s = rand8() & 3;
                if (D_80108B92_2919B2_DestructionDuet == 1) {
                    hp = &(&D_80108B00_291920_DestructionDuet)[DD_HITBY(w)];
                    old = *hp;
                    *hp = old - ((func_80019000_19C00(obj) & 0x100) ? 2.0f : 1.0f);
                }
                D_80108B1A_29193A_DestructionDuet[idx] = 0xA;
                func_80079848_7A448(w->unk_C5);
                func_800798F8_7A4F8(PlaySound(s == 0 ? 0x30F : (s == 1 ? 0x310 : (s == 2 ? 0x311 : 0x312))), DD_HITBY(w) == 1 ? 0x30 : 0x50);
                D_80108B28_291948_DestructionDuet[DD_HITBY(w) - 1].x = D_80108B28_291948_DestructionDuet[DD_HITBY(w) - 1].x + (obj->trans.x - (DD_HITBY(w) == 1 ? -282.5 : 282.5)) / 150.0;
                D_80108B28_291948_DestructionDuet[DD_HITBY(w) - 1].z = D_80108B28_291948_DestructionDuet[DD_HITBY(w) - 1].z + (obj->trans.z - -345.0) / 150.0;
                if (p->difficulty != -1) {
                    if ((p->mode != 6) & (p->mode != 8) && p->mode != 9) {
                        DD_RUN_MODE(p, p->mode);
                        p->delay = rand8() % mods.v[p->difficulty] + base.v[p->difficulty];
                    }
                }
                func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], (obj->trans.x + (DD_HITBY(w) == 1 ? -282.5 : 282.5)) / 2.0, (obj->trans.y + 115.0 + D_80108B0C_29192C_DestructionDuet * 25.0) / 2.0, (obj->trans.z + -345.0) / 2.0);
                func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 4, 0);
                func_80029C74_2A874(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 9.0f);
                func_80108318_291138_DestructionDuet(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 9);
                D_80108B80_2919A0_DestructionDuet[D_80108AED_29190D_DestructionDuet] = 0;
                D_80108AED_29190D_DestructionDuet = D_80108AED_29190D_DestructionDuet == 7 ? 0 : D_80108AED_29190D_DestructionDuet + 1;
            }
        }
        ContBtn[p->port] = btn;
        ContBtnTrg[p->port] = trg;
        D_800FD410_FE010[p->port] = btn2;
        ContStkX[p->port] = stkX;
        ContStkY[p->port] = stkY;
        D_800FC9BE_FD5BE[p->port] = stkX16;
        D_800FD468_FE068[p->port] = stkY16;
        if (idx == 3 && D_80108B92_2919B2_DestructionDuet == 1) {
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[0]->model[1], D_80108B28_291948_DestructionDuet[0].x + -282.5, D_80108B28_291948_DestructionDuet[0].y + 25.0, D_80108B28_291948_DestructionDuet[0].z + (D_80108B0C_29192C_DestructionDuet == 0 ? -377.5 : (D_80108B0C_29192C_DestructionDuet == 1 ? -295.0 : -320.0)));
            func_80029714_2A314(D_80108B60_291980_DestructionDuet[1]->model[1], D_80108B28_291948_DestructionDuet[1].x + 282.5, D_80108B28_291948_DestructionDuet[1].y + 25.0, D_80108B28_291948_DestructionDuet[1].z + (D_80108B0C_29192C_DestructionDuet == 0 ? -377.5 : (D_80108B0C_29192C_DestructionDuet == 1 ? -295.0 : -320.0)));
            D_80108B28_291948_DestructionDuet[0].x = D_80108B28_291948_DestructionDuet[0].y = D_80108B28_291948_DestructionDuet[0].z = 0.0f;
            D_80108B28_291948_DestructionDuet[1].x = D_80108B28_291948_DestructionDuet[1].y = D_80108B28_291948_DestructionDuet[1].z = 0.0f;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108840_291660_DestructionDuet[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

__asm__(".section .rodata");
const u32 D_80108858_291678_DestructionDuet[4] = { 0x420C0000, 0x423C0000, 0x42640000, 0x42880000 };

__asm__(".section .rodata");
const u32 D_80108868_291688_DestructionDuet[1] = { 0x0F0B0707 };

__asm__(".section .rodata");
const u32 D_8010886C_29168C_DestructionDuet[1] = { 0x0D080803 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3B_DestructionDuet/28B620", func_801063CC_28F1EC_DestructionDuet);
#endif

s32 func_80107F48_290D68_DestructionDuet(omObjData* obj, GroundWork* ground) {
    MgWork* w = obj->unk_50;

    if (D_80108B60_291980_DestructionDuet[0]->unk_50 == ground || D_80108B60_291980_DestructionDuet[1]->unk_50 == ground || D_80108B60_291980_DestructionDuet[2]->unk_50 == ground || D_80108B60_291980_DestructionDuet[3]->unk_50 == ground) {
        if (D_80108B92_2919B2_DestructionDuet == 1) {
            D_80108B04_291924_DestructionDuet[DD_TEAM(ground)] = D_80108B04_291924_DestructionDuet[DD_TEAM(ground)] - 3.0f;
        }
        D_80108B1A_29193A_DestructionDuet[w->unk_59] = 0xA;
        D_80108B28_291948_DestructionDuet[DD_TEAM(ground)].y = D_80108B28_291948_DestructionDuet[DD_TEAM(ground)].y - 2.0;
        func_80029714_2A314(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800298A4_2A4A4(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 4, 0);
        func_80029C74_2A874(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 4.0f);
        func_80108318_291138_DestructionDuet(D_80108AFC_29191C_DestructionDuet->model[D_80108AED_29190D_DestructionDuet + 3], 4);
        D_80108B80_2919A0_DestructionDuet[D_80108AED_29190D_DestructionDuet] = 0;
        D_80108AED_29190D_DestructionDuet = D_80108AED_29190D_DestructionDuet == 7 ? 0 : D_80108AED_29190D_DestructionDuet + 1;
    }
    return 0;
}

s32 func_801081F0_291010_DestructionDuet(void) {
    GroundWork* w;

    w = D_80108B60_291980_DestructionDuet[0]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[1]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[2]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[3]->unk_50;
    w->unk_06 &= 0xFDFF;
    return 0;
}

s32 func_80108258_291078_DestructionDuet(omObjData* obj) {
    GroundWork* w;

    w = D_80108B60_291980_DestructionDuet[0]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[1]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[2]->unk_50;
    w->unk_06 &= 0xFDFF;
    w = D_80108B60_291980_DestructionDuet[3]->unk_50;
    w->unk_06 &= 0xFDFF;
    func_800098D0_A4D0(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[0]);
    func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[1]);
    func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[2]);
    func_8000BFF0_CBF0(D_80108B60_291980_DestructionDuet[3]);
    return 1;
}

void func_80108318_291138_DestructionDuet(s16 model, s16 frame) {
    s32 off = model * sizeof(HmfModel);
    HmfModel* m = (HmfModel*)(off + (u8*)D_800FC834_FD434);

    m->hmf->unk9C->unk08 = frame;
}

void func_8010835C_29117C_DestructionDuet(void) {
    Vec up;

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    D_800FA5BC_FB1BC[0] = D_80108B70_291990_DestructionDuet.x;
    D_800FA5BC_FB1BC[1] = D_80108B70_291990_DestructionDuet.z;
    D_800FA5BC_FB1BC[-1] = 0;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    Hu3DCamSetPerspective(0, D_80108B00_291920_DestructionDuet, 1000.0f, 6000.0f);
    Hu3DCamSetPositionOrientation(0, &D_80108B70_291990_DestructionDuet, &D_80108B94_2919B4_DestructionDuet, &up);
    Hu3DCamUpdateMtx(0);
}
