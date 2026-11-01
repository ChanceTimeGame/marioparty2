#include "ovl_08.h"

void func_80102800_113C80_LavaTileIsle(void) {
    func_8002D4D0_2E0D0(0x20);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    D_800FA606_FB206 = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 0x10, 0x10, 0x10);
    func_80026E00_27A00(1, -32.0f, 99.0f, 59.0f);
    func_80026DAC_279AC(1, 0, 0, 0);
    func_8000C38C_CF8C();
    D_800F8FD0_F9BD0 = 0;
    func_8010291C_113D9C_LavaTileIsle();
    func_801029A8_113E28_LavaTileIsle();
    D_8010A60C_11BA8C_LavaTileIsle = 2;
    D_8010A618_11BA98_LavaTileIsle = 0;
    D_8010A619_11BA99_LavaTileIsle = -1;
    func_80102AB0_113F30_LavaTileIsle();
    func_801046E0_115B60_LavaTileIsle();
    func_801031C0_114640_LavaTileIsle();
    InitFadeIn(0, 0x10);
}

void func_8010291C_113D9C_LavaTileIsle(void) {
    D_8010A580_11BA00_LavaTileIsle[0].x = 0.0f;
    D_8010A580_11BA00_LavaTileIsle[0].y = -120.0f;
    D_8010A580_11BA00_LavaTileIsle[0].z = 0.0f;
    D_8010A580_11BA00_LavaTileIsle[1].x = 0.0f;
    D_8010A580_11BA00_LavaTileIsle[1].y = -120.0f;
    D_8010A580_11BA00_LavaTileIsle[1].z = -240.0f;
    D_8010A580_11BA00_LavaTileIsle[2].x = -240.0f;
    D_8010A580_11BA00_LavaTileIsle[2].y = -120.0f;
    D_8010A580_11BA00_LavaTileIsle[2].z = -240.0f;
    D_8010A500_11B980_LavaTileIsle[0].x = 240.0f;
    D_8010A500_11B980_LavaTileIsle[0].y = -120.0f;
    D_8010A500_11B980_LavaTileIsle[0].z = 240.0f;
    D_8010A500_11B980_LavaTileIsle[1].x = 0.0f;
    D_8010A500_11B980_LavaTileIsle[1].y = -120.0f;
    D_8010A500_11B980_LavaTileIsle[1].z = 240.0f;
    D_8010A500_11B980_LavaTileIsle[2].x = -240.0f;
    D_8010A500_11B980_LavaTileIsle[2].y = -120.0f;
    D_8010A500_11B980_LavaTileIsle[2].z = 240.0f;
    D_8010A500_11B980_LavaTileIsle[3].x = 240.0f;
    D_8010A500_11B980_LavaTileIsle[3].y = -120.0f;
    D_8010A500_11B980_LavaTileIsle[3].z = -240.0f;
}

void func_801029A8_113E28_LavaTileIsle(void) {
    D_8010A530_11B9B0_LavaTileIsle[0].id = 0;
    D_8010A530_11B9B0_LavaTileIsle[0].x0 = -360.0f;
    D_8010A530_11B9B0_LavaTileIsle[0].z0 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[0].x1 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[0].z1 = 120.0f;
    D_8010A530_11B9B0_LavaTileIsle[1].id = 1;
    D_8010A530_11B9B0_LavaTileIsle[1].x0 = -360.0f;
    D_8010A530_11B9B0_LavaTileIsle[1].z0 = -360.0f;
    D_8010A530_11B9B0_LavaTileIsle[1].x1 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[1].z1 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[2].id = 2;
    D_8010A530_11B9B0_LavaTileIsle[2].x0 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[2].z0 = -360.0f;
    D_8010A530_11B9B0_LavaTileIsle[2].x1 = 120.0f;
    D_8010A530_11B9B0_LavaTileIsle[2].z1 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[3].id = 3;
    D_8010A530_11B9B0_LavaTileIsle[3].x0 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[3].z0 = -120.0f;
    D_8010A530_11B9B0_LavaTileIsle[3].x1 = 120.0f;
    D_8010A530_11B9B0_LavaTileIsle[3].z1 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[0].id = 0;
    D_8010A5A8_11BA28_LavaTileIsle[0].x0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[0].z0 = -120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[0].x1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[0].z1 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[1].id = 1;
    D_8010A5A8_11BA28_LavaTileIsle[1].x0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[1].z0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[1].x1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[1].z1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[2].id = 2;
    D_8010A5A8_11BA28_LavaTileIsle[2].x0 = -120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[2].z0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[2].x1 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[2].z1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[3].id = 3;
    D_8010A5A8_11BA28_LavaTileIsle[3].x0 = -360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[3].z0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[3].x1 = -120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[3].z1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[4].id = 4;
    D_8010A5A8_11BA28_LavaTileIsle[4].x0 = 120.0f;
    D_8010A5A8_11BA28_LavaTileIsle[4].z0 = -360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[4].x1 = 360.0f;
    D_8010A5A8_11BA28_LavaTileIsle[4].z1 = -120.0f;
}

void func_80102AB0_113F30_LavaTileIsle(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 150.0f;
    D_8010274C_10334C.z = 250.0f;
    D_800FD474_FE074.x = -45.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1600.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 30.0f, 80.0f, 8000.0f);
}

/* Control flow (class 3): retail copies the result to a0 in a branch delay slot, and its frame has 8 more bytes. */
#ifdef NON_MATCHING
void func_80102BD0_114050_LavaTileIsle(omObjData* obj) {
    s32 i;
    s32 left;
    s32 secs = 0;
    s16 t;

    switch (D_8010A1CA_11B64A_LavaTileIsle) {
    case 0:
        if (D_801011FC_101DFC == 1) {
            func_80079868_7A468();
            func_800794A8_7A0A8(0x28);
            InitFadeOut(0, 0x14);
            D_8010A1CA_11B64A_LavaTileIsle = 1;
        }
        break;
    case 1:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
            D_8010A1CA_11B64A_LavaTileIsle = 2;
        }
        break;
    }
    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_8010A1B4_11B634_LavaTileIsle == 0x10) {
            D_8010A496_11B916_LavaTileIsle = PlaySound(0x4AF);
            PlayMusic(0x27);
        } else if (D_8010A1B4_11B634_LavaTileIsle == 0x1E) {
            func_800799A4_7A5A4(D_8010A496_11B916_LavaTileIsle, 0x1E);
        }
        if (D_8010A1B4_11B634_LavaTileIsle == 0x3C) {
            func_800691FC_69DFC(0);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        } else if (D_8010A1B4_11B634_LavaTileIsle >= 0x78) {
            func_8000C3B8_CFB8();
        }
        D_8010A1B4_11B634_LavaTileIsle++;
        break;
    case 1:
        if (D_8010A1BC_11B63C_LavaTileIsle == 0) {
            func_800691FC_69DFC(0xA, D_8010A1B0_11B630_LavaTileIsle, 0xA0, 0x20);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        } else if (D_8010A1BC_11B63C_LavaTileIsle == D_8010A1B0_11B630_LavaTileIsle * 30) {
            func_8000C398_CF98();
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            left = D_8010A1B0_11B630_LavaTileIsle * 30 - D_8010A1BC_11B63C_LavaTileIsle;
            /* retail: both sides subtract the frame counter, so this tests the limit itself */
            if (left == 150 - D_8010A1BC_11B63C_LavaTileIsle || left == 300 - D_8010A1BC_11B63C_LavaTileIsle ||
                left == 450 - D_8010A1BC_11B63C_LavaTileIsle) {
                t = func_80079574_7A174() + 5;
                D_8010A494_11B914_LavaTileIsle = t;
                func_8007954C_7A14C(t);
            }
            secs = left / 30;
            D_8010A1BC_11B63C_LavaTileIsle++;
        }
        if (secs < 0) {
            func_8000C398_CF98();
        } else {
            func_8006D4D0_6E0D0(secs);
        }
        break;
    case 2:
        if (D_8010A1B8_11B638_LavaTileIsle == 0) {
            func_8000C690_D290();
            func_8006D518_6E118();
            func_800794A8_7A0A8(0x28);
            func_800691FC_69DFC(3);
        } else if (D_8010A1B8_11B638_LavaTileIsle == 0x32) {
            D_8010A1C4_11B644_LavaTileIsle = 0;
            for (i = 0; i < 4; i++) {
                if (D_800FFFD8_100BD8[i]->trans.y >= 0.0f) {
                    D_8010A1C4_11B644_LavaTileIsle++;
                }
            }
            if (D_8010A1C4_11B644_LavaTileIsle == 1) {
                for (i = 0; i < 4; i++) {
                    if (D_800FFFD8_100BD8[i]->trans.y >= 0.0f) {
                        gPlayers[i].coins_mg_bonus += 10;
                        D_8010A490_11B910_LavaTileIsle = i;
                    }
                }
            }
        } else if (D_8010A1B8_11B638_LavaTileIsle > 0x32 && D_8010A619_11BA99_LavaTileIsle == -1 &&
                   (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2))) {
            if (secs >= 0 && D_8010A1C4_11B644_LavaTileIsle == 1) {
                if (_CheckFlag(0xC) == 0) {
                    PlayMusic(0x51);
                    func_8006961C_6A21C(func_800691FC_69DFC(6, gPlayers[D_8010A490_11B910_LavaTileIsle].character), 160.0f, 160.0f);
                }
                D_8010A619_11BA99_LavaTileIsle = 0;
            } else {
                if (_CheckFlag(0xC) == 0) {
                    PlayMusic(0x57);
                    func_800691FC_69DFC(0x13);
                }
                D_8010A619_11BA99_LavaTileIsle = 1;
            }
        }
        if (_CheckFlag(0xC) != 0 && D_8010A1B8_11B638_LavaTileIsle == 0x3C) {
            InitFadeOut(0, 0x14);
            func_8000C3A8_CFA8();
        }
        i = D_8010A619_11BA99_LavaTileIsle;
        if (i != -1) {
            if ((u32)i < 2 && D_8010A1C8_11B648_LavaTileIsle == 0x78) {
                InitFadeOut(0, 0x14);
                func_8000C3A8_CFA8();
            }
            D_8010A1C8_11B648_LavaTileIsle++;
        }
        D_8010A1B8_11B638_LavaTileIsle++;
        break;
    case 3:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        D_8010A1C0_11B640_LavaTileIsle++;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/113C80", func_80102BD0_114050_LavaTileIsle);
#endif
