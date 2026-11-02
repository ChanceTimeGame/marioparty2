#include "ovl_02.h"

__asm__(".section .rodata");
const char D_80112440_F3680_RollOutTheBarrels[] = "\202r\202s\202`\202q\202s";

__asm__(".section .rodata");
const char D_8011244C_F368C_RollOutTheBarrels[] = "\202e\202h\202m\202h\202r\202g";

__asm__(".section .rodata");
const char D_8011245C_F369C_RollOutTheBarrels[] = "\202h\202s\202d\202l\202f\202d\202s\201I\201H";

void func_80102800_E3A40_RollOutTheBarrels(void) {
    s32 cam;

    func_8002D4D0_2E0D0(0x32);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_80020D20_21920(0x40);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, -56.0f, 50.0f, 56.0f);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 5000.0f);
    func_80103094_E42D4_RollOutTheBarrels();
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FA606_FB206 = 0;
    D_80112D78_F3FB8_RollOutTheBarrels = 0;
    D_80112D7A_F3FBA_RollOutTheBarrels = 0x149;
    D_80112D7C_F3FBC_RollOutTheBarrels = 0;
    D_80112D80_F3FC0_RollOutTheBarrels = -1;
    D_80112D8C_F3FCC_RollOutTheBarrels = -1;
    D_80112D90_F3FD0_RollOutTheBarrels = -1;
    D_80112D94_F3FD4_RollOutTheBarrels = -1;
    D_80112D98_F3FD8_RollOutTheBarrels = 0;
    D_80112D9C_F3FDC_RollOutTheBarrels = 0x1E;
    D_80112DA0_F3FE0_RollOutTheBarrels = 0;
    D_80112DA4_F3FE4_RollOutTheBarrels = 0;
    D_80112DBC_F3FFC_RollOutTheBarrels = 0;
    D_80112DBE_F3FFE_RollOutTheBarrels = 0;
    D_80112DD0_F4010_RollOutTheBarrels = -1;
    D_80112E28_F4068_RollOutTheBarrels = 0;
    D_80112D60_F3FA0_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x38);
    D_80112D64_F3FA4_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x150);
    D_80112D68_F3FA8_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x240);
    D_80112D6C_F3FAC_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x300);
    D_80112D70_F3FB0_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x480);
    D_80112D84_F3FC4_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x78);
    D_80112D74_F3FB4_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x80);
    D_80112D88_F3FC8_RollOutTheBarrels = func_80111448_F2688_RollOutTheBarrels(0x14);
    D_80112D38_F3F78_RollOutTheBarrels = omAddObj(0x20, 0, 0, -1, func_80102B2C_E3D6C_RollOutTheBarrels);
    func_8007273C_7333C((u8*)D_80112440_F3680_RollOutTheBarrels, 1);
    func_8007273C_7333C((u8*)D_8011244C_F368C_RollOutTheBarrels, 1);
    func_8007273C_7333C((u8*)D_8011245C_F369C_RollOutTheBarrels, 1);
    func_80026D28_27928(2);
    func_80026DAC_279AC(0, 0x40, 0x40, 0x40);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -64.0f, 47.0f, 89.0f);
    func_80026DAC_279AC(2, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(2, 0.0f, 104.0f, -58.0f);
}

void func_80102B2C_E3D6C_RollOutTheBarrels(omObjData* obj) {
    obj->func_ptr = func_80102BB0_E3DF0_RollOutTheBarrels;
    func_801041D0_E5410_RollOutTheBarrels();
    func_801060B8_E72F8_RollOutTheBarrels();
    func_80105A70_E6CB0_RollOutTheBarrels();
    func_80106DE4_E8024_RollOutTheBarrels();
    func_80108D00_E9F40_RollOutTheBarrels();
    func_8010DD10_EEF50_RollOutTheBarrels();
    func_8010E260_EF4A0_RollOutTheBarrels();
    func_8002CA48_2D648(0, 0xB4, 0xA0);
    if (_CheckFlag(0xC) != 0) {
        D_80112DBC_F3FFC_RollOutTheBarrels = 1;
    }
    PlayMusic(0x28);
}

void func_80102BB0_E3DF0_RollOutTheBarrels(omObjData* obj) {
    s32 t;

    func_80102FEC_E422C_RollOutTheBarrels(obj);
    switch (D_80112D78_F3FB8_RollOutTheBarrels) {
        case 0:
            if (D_80112150_F3390_RollOutTheBarrels == 0 && func_8008F618_90218() == 0) {
                D_80112150_F3390_RollOutTheBarrels++;
            }
            break;
        case 2:
            if (func_80069538_6A138() == 0) {
                func_800691FC_69DFC(0xA, D_80112D7A_F3FBA_RollOutTheBarrels / 30, 0xA0, 0x20);
                D_80112D78_F3FB8_RollOutTheBarrels = 3;
                D_800F8FD0_F9BD0 = 1;
                D_80112150_F3390_RollOutTheBarrels = 0;
            }
            break;
        case 3:
            if (D_80112D7C_F3FBC_RollOutTheBarrels == 0) {
                func_8006D4D0_6E0D0(D_80112D7A_F3FBA_RollOutTheBarrels / 30);
                if (--D_80112D7A_F3FBA_RollOutTheBarrels < 0x1A) {
                    func_8006D518_6E118();
                    D_80112D7C_F3FBC_RollOutTheBarrels = 1;
                }
            }
            break;
        case 7:
            if (D_80112150_F3390_RollOutTheBarrels == 0) {
                D_80112150_F3390_RollOutTheBarrels = 1;
            } else if (func_80108C00_E9E40_RollOutTheBarrels(D_80112D8C_F3FCC_RollOutTheBarrels) != 0) {
                D_80112D78_F3FB8_RollOutTheBarrels = 8;
                D_80112150_F3390_RollOutTheBarrels = 0;
            }
            break;
        case 8:
            if (func_80069538_6A138() != 0) {
                break;
            }
            if (D_80112D8C_F3FCC_RollOutTheBarrels >= 0 && D_80112D90_F3FD0_RollOutTheBarrels != -1) {
                if (D_80112D90_F3FD0_RollOutTheBarrels != 3) {
                    func_800691FC_69DFC(0x17);
                    D_80112DD0_F4010_RollOutTheBarrels = 0x26;
                    func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, (s16)D_80112DC4_F4004_RollOutTheBarrels, D_80112120_F3360_RollOutTheBarrels[D_80112DC4_F4004_RollOutTheBarrels]);
                    PlayMusic(0x53);
                    func_800732B0_73EB0(D_80112D50_F3F90_RollOutTheBarrels[0]);
                    t = 0x87;
                } else {
                    func_800691FC_69DFC(0x18);
                    D_80112DD0_F4010_RollOutTheBarrels = 0x28;
                    func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, (s16)D_80112DC4_F4004_RollOutTheBarrels, D_80112138_F3378_RollOutTheBarrels[D_80112DC4_F4004_RollOutTheBarrels]);
                    PlayMusic(0x54);
                    t = 0x90;
                }
                D_80112154_F3394_RollOutTheBarrels = t;
                gPlayers[D_80112DC0_F4000_RollOutTheBarrels].coins_mg_bonus = (u16)D_80112D90_F3FD0_RollOutTheBarrels;
                D_80112D7A_F3FBA_RollOutTheBarrels = 0x3C;
            } else {
                func_800691FC_69DFC(0x10);
                D_80112DD0_F4010_RollOutTheBarrels = 0x27;
                func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, (s16)D_80112DC4_F4004_RollOutTheBarrels, D_80112138_F3378_RollOutTheBarrels[D_80112DC4_F4004_RollOutTheBarrels]);
                PlayMusic(0x56);
                gPlayers[D_80112DC0_F4000_RollOutTheBarrels].coins_mg_bonus = -1;
                D_80112D7A_F3FBA_RollOutTheBarrels = 0x2D;
                D_80112154_F3394_RollOutTheBarrels = 0x84;
            }
            D_80112D78_F3FB8_RollOutTheBarrels = 9;
        case 9:
            if (D_80112154_F3394_RollOutTheBarrels <= 0) {
                D_80112D78_F3FB8_RollOutTheBarrels = 0xA;
                InitFadeOut(0, 0x14);
            } else {
                D_80112154_F3394_RollOutTheBarrels--;
            }
            break;
        case 10:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80102FB8_E41F8_RollOutTheBarrels;
            }
            break;
        case 11:
            break;
    }
}

void func_80102FB8_E41F8_RollOutTheBarrels(omObjData* obj) {
    func_8002CA48_2D648(0, 0, 0);
    func_80079464_7A064();
    omOvlReturnEx(1);
}

void func_80102FEC_E422C_RollOutTheBarrels(omObjData* obj) {
    if (D_80112158_F3398_RollOutTheBarrels != 0) {
        if (D_80112158_F3398_RollOutTheBarrels == 1) {
            obj->func_ptr = func_80102FB8_E41F8_RollOutTheBarrels;
        }
        D_80112158_F3398_RollOutTheBarrels--;
    } else if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_80112158_F3398_RollOutTheBarrels = 0x14;
        InitFadeOut(0, (s16)D_80112158_F3398_RollOutTheBarrels);
        func_800794A8_7A0A8((s16)D_80112158_F3398_RollOutTheBarrels);
        func_80079614_7A214((s16)D_80112158_F3398_RollOutTheBarrels);
    }
}

void func_80103094_E42D4_RollOutTheBarrels(void) {
    HuCamera* cam;
    s32 i;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 328.2f;
    D_8010274C_10334C.z = -70.0f;
    D_800FD474_FE074.x = 329.25f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1616.0f;
    func_80103DF4_E5034_RollOutTheBarrels(0);
    func_80103DF4_E5034_RollOutTheBarrels(1);
    D_80112E24_F4064_RollOutTheBarrels = 0;
    D_80112E20_F4060_RollOutTheBarrels = 0;
    omAddObj(0x1F, 0, 0, -1, func_801039F0_E4C30_RollOutTheBarrels);
    cam = D_800C9B80_CA780;
    for (i = 1; i < D_800FDBCA_FE7CA; i++) {
        cam->viewports[i].vp.vscale[0] = cam->viewports[0].vp.vscale[0];
        cam->viewports[i].vp.vscale[1] = cam->viewports[0].vp.vscale[1];
        cam->viewports[i].vp.vscale[2] = cam->viewports[0].vp.vscale[2];
        cam->viewports[i].vp.vtrans[0] = cam->viewports[0].vp.vtrans[0];
        cam->viewports[i].vp.vtrans[1] = cam->viewports[0].vp.vtrans[1];
        cam->viewports[i].vp.vtrans[2] = cam->viewports[0].vp.vtrans[2];
    }
}

void func_801031B4_E43F4_RollOutTheBarrels(void) {
    RBCamera c = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f };
    f32 speed = 1.0f;

    switch (D_8011215C_F339C_RollOutTheBarrels) {
        case 1:
            if (ContBtn[0] & 0x8000) {
                speed = 2.0f;
            }
            if (ContBtn[0] & 0x4000) {
                speed = 0.5f;
            }
            if (ContBtnTrg[0] & 0x1000) {
                D_8010274C_10334C.x = 0.0f;
                D_8010274C_10334C.y = 191.2f;
                D_8010274C_10334C.z = 0.2f;
                D_800FD474_FE074.x = -14.5f;
                D_800FD474_FE074.y = 0.0f;
                D_800FD474_FE074.z = 0.0f;
                D_800FA610_FB210 = 1069.0f;
            } else {
                c.rot.x = (f32)ContStkY[0] * 0.125 * speed;
                c.rot.y = (f32)ContStkX[0] * 0.125 * speed;
                if (ContBtn[0] & 0x200) {
                    c.center.x = 2.0 * speed;
                }
                if (ContBtn[0] & 0x100) {
                    c.center.x = -(2.0 * speed);
                }
                if (ContBtn[0] & 0x800) {
                    c.center.z = -(2.0 * speed);
                }
                if (ContBtn[0] & 0x400) {
                    c.center.z = 2.0 * speed;
                }
                if (ContBtn[0] & 8) {
                    c.center.y = 2.0 * speed;
                }
                if (ContBtn[0] & 4) {
                    c.center.y = -(2.0 * speed);
                }
                if (ContBtn[0] & 1) {
                    c.zoom = 2.0 * speed;
                }
                if (ContBtn[0] & 2) {
                    c.zoom = -(2.0 * speed);
                }
                c.center.x += D_8010274C_10334C.x;
                c.center.y += D_8010274C_10334C.y;
                c.center.z += D_8010274C_10334C.z;
                c.rot.x += D_800FD474_FE074.x;
                c.rot.y += D_800FD474_FE074.y;
                c.rot.z += D_800FD474_FE074.z;
                c.zoom += D_800FA610_FB210;
                func_80103FE0_E5220_RollOutTheBarrels(c.center.x, c.center.y, c.center.z, c.rot.x, c.rot.y, c.rot.z, c.zoom, 1);
            }
            sprintf(pfStrBuf, "CAMERA TEST_MODE");
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 104, pfStrBuf);
            D_800F8FD0_F9BD0 = 0;
            break;
        case 2:
            if ((ContBtn[0] & 0x100) || (ContBtn[0] & 1)) {
                D_80112160_F33A0_RollOutTheBarrels++;
            }
            if (ContBtn[0] & 0x202) {
                D_80112160_F33A0_RollOutTheBarrels--;
            }
            if (ContBtn[0] & 0x404) {
                D_80112164_F33A4_RollOutTheBarrels++;
            }
            if (ContBtn[0] & 0x808) {
                D_80112164_F33A4_RollOutTheBarrels--;
            }
            fontcolor = 8;
            sprintf(pfStrBuf, "CAMERA TEST_MODE ");
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_80112160_F33A0_RollOutTheBarrels + 20, (u16)D_80112164_F33A4_RollOutTheBarrels + 104, pfStrBuf);
            break;
        default:
            D_800F8FD0_F9BD0 = 1;
            break;
    }
    if (ContBtnTrg[0] & 0x10) {
        if (D_8011215C_F339C_RollOutTheBarrels & 1) {
            osSyncPrintf("CAMERA TEST_MODE \n");
            osSyncPrintf(" CENTER X>%3.3f Y>%3.3f Z>%3.3f \n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            osSyncPrintf(" ROT    X>%3.3f Y>%3.3f Z>%3.3f \n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            osSyncPrintf(" ZOOM   %3.3f \n\n", D_800FA610_FB210);
        }
        if (++D_8011215C_F339C_RollOutTheBarrels >= 3) {
            D_8011215C_F339C_RollOutTheBarrels = 0;
        }
    }
}

void func_801039F0_E4C30_RollOutTheBarrels(omObjData* obj) {
    Vec unused;
    f32 t;

    if (D_80112E24_F4064_RollOutTheBarrels > 0) {
        if (D_80112E20_F4060_RollOutTheBarrels == 0) {
            D_8010274C_10334C.x = D_80112DD8_F4018_RollOutTheBarrels[0].center.x;
            D_8010274C_10334C.y = D_80112DD8_F4018_RollOutTheBarrels[0].center.y;
            D_8010274C_10334C.z = D_80112DD8_F4018_RollOutTheBarrels[0].center.z;
            D_800FD474_FE074.x = D_80112DD8_F4018_RollOutTheBarrels[0].rot.x;
            D_800FD474_FE074.y = D_80112DD8_F4018_RollOutTheBarrels[0].rot.y;
            D_800FD474_FE074.z = D_80112DD8_F4018_RollOutTheBarrels[0].rot.z;
            D_800FA610_FB210 = D_80112DD8_F4018_RollOutTheBarrels[0].zoom;
            RB_WRAP(D_800FD474_FE074.x);
            RB_WRAP(D_800FD474_FE074.y);
            RB_WRAP(D_800FD474_FE074.z);
            D_80112E24_F4064_RollOutTheBarrels = 0;
        } else {
            t = (f32)D_80112E20_F4060_RollOutTheBarrels / (f32)D_80112E24_F4064_RollOutTheBarrels;
            D_8010274C_10334C.x = D_80112DD8_F4018_RollOutTheBarrels[1].center.x + t * (D_80112DD8_F4018_RollOutTheBarrels[0].center.x - D_80112DD8_F4018_RollOutTheBarrels[1].center.x);
            D_8010274C_10334C.y = D_80112DD8_F4018_RollOutTheBarrels[1].center.y + t * (D_80112DD8_F4018_RollOutTheBarrels[0].center.y - D_80112DD8_F4018_RollOutTheBarrels[1].center.y);
            D_8010274C_10334C.z = D_80112DD8_F4018_RollOutTheBarrels[1].center.z + t * (D_80112DD8_F4018_RollOutTheBarrels[0].center.z - D_80112DD8_F4018_RollOutTheBarrels[1].center.z);
            D_800FD474_FE074.x = D_80112DD8_F4018_RollOutTheBarrels[1].rot.x + t * (D_80112DD8_F4018_RollOutTheBarrels[0].rot.x - D_80112DD8_F4018_RollOutTheBarrels[1].rot.x);
            D_800FD474_FE074.y = D_80112DD8_F4018_RollOutTheBarrels[1].rot.y + t * (D_80112DD8_F4018_RollOutTheBarrels[0].rot.y - D_80112DD8_F4018_RollOutTheBarrels[1].rot.y);
            D_800FD474_FE074.z = D_80112DD8_F4018_RollOutTheBarrels[1].rot.z + t * (D_80112DD8_F4018_RollOutTheBarrels[0].rot.z - D_80112DD8_F4018_RollOutTheBarrels[1].rot.z);
            D_800FA610_FB210 = D_80112DD8_F4018_RollOutTheBarrels[1].zoom + t * (D_80112DD8_F4018_RollOutTheBarrels[0].zoom - D_80112DD8_F4018_RollOutTheBarrels[1].zoom);
            RB_WRAP(D_800FD474_FE074.x);
            RB_WRAP(D_800FD474_FE074.y);
            RB_WRAP(D_800FD474_FE074.z);
            if (D_80112E20_F4060_RollOutTheBarrels > 0) {
                D_80112E20_F4060_RollOutTheBarrels--;
            } else {
                D_80112E20_F4060_RollOutTheBarrels++;
            }
        }
    }
}

void func_80103DF4_E5034_RollOutTheBarrels(s32 idx) {
    RB_WRAP(D_800FD474_FE074.x);
    RB_WRAP(D_800FD474_FE074.y);
    RB_WRAP(D_800FD474_FE074.z);
    D_80112DD8_F4018_RollOutTheBarrels[idx].center.x = D_8010274C_10334C.x;
    D_80112DD8_F4018_RollOutTheBarrels[idx].center.y = D_8010274C_10334C.y;
    D_80112DD8_F4018_RollOutTheBarrels[idx].center.z = D_8010274C_10334C.z;
    D_80112DD8_F4018_RollOutTheBarrels[idx].rot.x = D_800FD474_FE074.x;
    D_80112DD8_F4018_RollOutTheBarrels[idx].rot.y = D_800FD474_FE074.y;
    D_80112DD8_F4018_RollOutTheBarrels[idx].rot.z = D_800FD474_FE074.z;
    D_80112DD8_F4018_RollOutTheBarrels[idx].zoom = D_800FA610_FB210;
    D_80112DD8_F4018_RollOutTheBarrels[idx].unk_1C = D_80112DD8_F4018_RollOutTheBarrels[idx].unk_20 = 0.0f;
}

void func_80103FE0_E5220_RollOutTheBarrels(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames) {
    if (frames > 0) {
        D_80112E20_F4060_RollOutTheBarrels = frames - 1;
        D_80112E24_F4064_RollOutTheBarrels = frames;
        if (cx != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.x = cx;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.x = D_8010274C_10334C.x;
        }
        if (cy != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.y = cy;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.y = D_8010274C_10334C.y;
        }
        if (cz != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.z = cz;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].center.z = D_8010274C_10334C.z;
        }
        if (rx != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.x = rx;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.x = D_800FD474_FE074.x;
        }
        if (ry != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.y = ry;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.y = D_800FD474_FE074.y;
        }
        if (rz != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.z = rz;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].rot.z = D_800FD474_FE074.z;
        }
        if (zoom != 65535.0f) {
            D_80112DD8_F4018_RollOutTheBarrels[0].zoom = zoom;
        } else {
            D_80112DD8_F4018_RollOutTheBarrels[0].zoom = D_800FA610_FB210;
        }
        func_80103DF4_E5034_RollOutTheBarrels(1);
    }
}

void func_801041D0_E5410_RollOutTheBarrels(void) {
    func_8000C578_D178(1);
    func_8000C460_D060();
    D_800BF7A4_C03A4 = 1.5f;
    D_800BF7A8_C03A8 = 0.17f;
    D_800BF7D4_C03D4 = 1.7f;
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x10, 0xA, 0x3C, -1, func_80104270_E54B0_RollOutTheBarrels);
}

// register allocation (masked 3, one extra move at the end), class 4
#ifdef NON_MATCHING
void func_80104270_E54B0_RollOutTheBarrels(omObjData* obj) {
    s32 mot[2];
    s16 time[2];
    u16 i;
    u16 player;
    s32 dir;
    MgWork* w;
    RBPlayer* pl;
    s32 r;
    s16 t;
    s32 file;
    s32 chr;

    mot[0] = 0x55;
    mot[1] = 0x56;
    time[0] = 0x3E7;
    time[1] = 0x3E7;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
        case 0:
            player = 0;
            break;
        case 1:
            player = 1;
            break;
        case 2:
            player = 2;
            break;
        case 3:
            player = 3;
            break;
        default:
            player = 0;
            break;
    }
    D_80112DC0_F4000_RollOutTheBarrels = player;
    D_80112DC8_F4008_RollOutTheBarrels = gPlayers[player].port;
    if (gPlayers[player].flags & 1) {
        D_80112DCC_F400C_RollOutTheBarrels = 1;
    } else {
        D_80112DCC_F400C_RollOutTheBarrels = 0;
    }
    chr = gPlayers[player].character;
    D_80112DC4_F4004_RollOutTheBarrels = chr;
    dir = D_800CD438_CE038[chr].dir;
    file = D_800CD438_CE038[chr].unk_10;
    func_8000C6FC_D2FC(obj, dir, file, player, 0x689, 0x689);
    obj->func_ptr = func_80104958_E5B98_RollOutTheBarrels;
    w = obj->unk_50;
    w->unk_EC = NULL;
    w->unk_3C = 180.0f;
    w->unk_64 = 2.0 * w->unk_64;
    obj->model[3] = LoadFormFile(7, 0x68D);
    obj->model[4] = LoadFormFile(8, 0x68D);
    obj->model[6] = LoadFormFile(9, 0x68D);
    obj->model[5] = LoadFormFile(0xA, 0x68D);
    obj->model[7] = LoadFormFile(0xC, 0x68D);
    obj->model[8] = LoadFormFile(0xB, 0x68D);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1B);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 0x14, dir | 0x2B, 0, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x54, 1, 0x3E7);
    D_80112D50_F3F90_RollOutTheBarrels[0] = dir | 0x54;
    func_80019E84_1AA84(obj, 0x27, dir | 0x57, 1, 0x3E7);
    D_80112D50_F3F90_RollOutTheBarrels[1] = dir | 0x57;
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 0x28, dir | mot[r], 1, time[r]);
    D_80112D50_F3F90_RollOutTheBarrels[2] = dir | mot[r];
    func_801113D4_F2614_RollOutTheBarrels(obj, D_80112D60_F3FA0_RollOutTheBarrels);
    pl = D_80112D60_F3FA0_RollOutTheBarrels;
    pl->target = -1;
    pl->unk_02 = pl->unk_04 = pl->unk_06 = 0;
    pl->pathIdx = pl->pathLen = 0;
    pl->unk_14 = 0;
    pl->path = 0;
    pl->pushed = pl->motState = 0;
    pl->state = pl->unk_12 = 0;
    pl->pushSpeed = pl->pushAngle = 0.0f;
    for (i = 0; i < 4; i++) {
        pl->unk_30[i] = -1;
    }
    if (D_80112DCC_F400C_RollOutTheBarrels != 0) {
        pl->unk_06 = rand8() % 5;
        switch (gPlayers[player].cpu_difficulty) {
            case 0:
                if (rand8() % 100 < 30) {
                    pl->unk_02 = 1;
                }
                break;
            case 1:
                if (rand8() % 100 < 20) {
                    pl->unk_02 = 1;
                }
                break;
            case 2:
                if (rand8() % 100 < 10) {
                    pl->unk_02 = 1;
                }
                break;
            default:
                if (rand8() % 100 < 5) {
                    pl->unk_02 = 1;
                }
                break;
        }
        t = -1;
        if (pl->unk_02 == 0) {
            t = func_80111494_F26D4_RollOutTheBarrels();
        }
        pl->target = t;
    }
    func_8000C35C_CF5C(obj, 0.0f, 0.0f, 0.0f);
    func_8000C36C_CF6C(obj, 0.0f, 0.0f, 0.0f);
    func_8000C024_CC24(obj, 0, 2);
    D_800F8FD0_F9BD0 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80104270_E54B0_RollOutTheBarrels);
#endif

void func_80104958_E5B98_RollOutTheBarrels(omObjData* obj) {
    Vec prev;
    Vec pos;
    struct {
        f32 unk_00;
        char unk_04[4];
        f32 unk_08;
        f32 unk_0C;
    } out;
    RBPlayer* pl;
    MgWork* w;
    RBShape* shape;
    s32 n;

    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    w = obj->unk_50;
    if (pl->pushed != 0) {
        func_801056BC_E68FC_RollOutTheBarrels(obj);
    }
    prev.x = obj->trans.x;
    prev.y = obj->trans.y;
    prev.z = obj->trans.z;
    switch (D_80112D78_F3FB8_RollOutTheBarrels) {
        case 3:
            if (D_80112DCC_F400C_RollOutTheBarrels != 0) {
                func_80104D88_E5FC8_RollOutTheBarrels(obj);
            }
            func_80007790_8390(obj);
            shape = func_80106224_E7464_RollOutTheBarrels(obj, &prev);
            if (shape == NULL || shape->hit == 1) {
                shape = func_801063B0_E75F0_RollOutTheBarrels(obj, &prev);
            }
            if (shape != NULL) {
                if (shape->hit >= 2) {
                    D_800F8FD0_F9BD0 = 0;
                    pl->state = 0;
                }
            } else if (D_80112D7C_F3FBC_RollOutTheBarrels == 1 && obj->trans.y <= 0.0) {
                D_800F8FD0_F9BD0 = 0;
                pl->state = 0;
                D_80112D7C_F3FBC_RollOutTheBarrels = 2;
            }
            break;
        case 6:
            n = func_8010541C_E665C_RollOutTheBarrels(obj);
            if (n < 3) {
                if (n >= 0) {
                    goto run;
                }
            }
            func_80007790_8390(obj);
            D_80112D78_F3FB8_RollOutTheBarrels = 7;
            D_800F8FD0_F9BD0 = 0;
            break;
        case 7:
            D_800F8FD0_F9BD0 = 0;
            goto run;
        case 4:
        case 5:
        case 8:
            D_800F8FD0_F9BD0 = 0;
            w->unk_40 = 0.0f;
        default:
        run:
            func_80007790_8390(obj);
            break;
    }
    if (D_80112DD0_F4010_RollOutTheBarrels != -1) {
        func_80019B9C_1A79C(obj, (u16)D_80112DD0_F4010_RollOutTheBarrels);
    }
    func_80104C80_E5EC0_RollOutTheBarrels(obj);
    func_80019378_19F78(obj);
    if (obj->trans.z > 100.0) {
        obj->trans.z = 100.0f;
    } else if (obj->trans.z < -1200.0) {
        obj->trans.z = -1200.0f;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    func_80111B40_F2D80_RollOutTheBarrels(0, &pos, &out);
    if (out.unk_00 <= 30.0) {
        obj->trans.x = obj->trans.x + (30.0 - out.unk_00) * out.unk_08 * 0.01;
    }
    if (out.unk_00 >= 290.0) {
        obj->trans.x = obj->trans.x - (out.unk_00 - 290.0) * out.unk_08 * 0.01;
    }
}

void func_80104C80_E5EC0_RollOutTheBarrels(omObjData* obj) {
    MgWork* w;
    s32 x;
    s32 y;

    w = obj->unk_50;
    if (D_800F8FD0_F9BD0 != 0 || D_80112D78_F3FB8_RollOutTheBarrels != 3) {
        x = ContStkX[w->unk_57];
        y = ContStkY[w->unk_57];
        if (x > 60) {
            x = 60;
        } else if (x < -60) {
            x = -60;
        } else {
            x = abs(x) >= 8 ? x : 0;
        }
        if (y > 60) {
            y = 60;
        } else if (y < -60) {
            y = -60;
        } else {
            y = abs(y) >= 8 ? y : 0;
        }
        if ((x == 0) & (y == 0)) {
            if (func_8000CDC8_D9C8(obj, x, y) == 0) {
                w->unk_40 = 0.0f;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80104D88_E5FC8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010541C_E665C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801056BC_E68FC_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105928_E6B68_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105998_E6BD8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105A70_E6CB0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105AD8_E6D18_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105CE8_E6F28_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80105F80_E71C0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801060B8_E72F8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80106114_E7354_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801061B0_E73F0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80106224_E7464_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801063B0_E75F0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801066B4_E78F4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801067BC_E79FC_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80106DE4_E8024_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010704C_E828C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80107140_E8380_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80107564_E87A4_RollOutTheBarrels);

__asm__(".section .rodata");
const u32 D_801127D8_F3A18_RollOutTheBarrels[1] = { 0x40668000 };

__asm__(".section .rodata");
const char D_801127DC_F3A1C_RollOutTheBarrels[] = "";

__asm__(".section .rodata");
const char D_801127E0_F3A20_RollOutTheBarrels[] = "@>";

__asm__(".section .rodata");
const char D_801127E4_F3A24_RollOutTheBarrels[] = "";

__asm__(".section .rodata");
const char D_801127E8_F3A28_RollOutTheBarrels[] = "@.";

__asm__(".section .rodata");
const char D_801127EC_F3A2C_RollOutTheBarrels[] = "";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_801127F0_F3A30_RollOutTheBarrels[2] = { 0x40568000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_801127F8_F3A38_RollOutTheBarrels[8] = "@Y";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80112800_F3A40_RollOutTheBarrels[2] = { 0x3FC0F5C2, 0x8F5C28F6 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80112808_F3A48_RollOutTheBarrels[2] = { 0x408F4000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_80112810_F3A50_RollOutTheBarrels[2] = { 0x4072C000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801079D0_E8C10_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80107AE0_E8D20_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80107D2C_E8F6C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108808_E9A48_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010898C_E9BCC_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108A08_E9C48_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108A78_E9CB8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108AEC_E9D2C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108B68_E9DA8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108C00_E9E40_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108C5C_E9E9C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108D00_E9F40_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80108F88_EA1C8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80109504_EA744_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801096D8_EA918_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80109738_EA978_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80109824_EAA64_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80109868_EAAA8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80109DA4_EAFE4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010A2E0_EB520_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010A7C4_EBA04_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010ACA8_EBEE8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010B5B0_EC7F0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010BEB8_ED0F8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010C448_ED688_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010C9D8_EDC18_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010CA90_EDCD0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010CB58_EDD98_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010CC18_EDE58_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010CC94_EDED4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010CE40_EE080_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010D054_EE294_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010D204_EE444_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010D3D0_EE610_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010D604_EE844_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010D740_EE980_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DB74_EEDB4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DBAC_EEDEC_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DBE0_EEE20_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DC1C_EEE5C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DC48_EEE88_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DC78_EEEB8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DCCC_EEF0C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DD10_EEF50_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DE84_EF0C4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010DF18_EF158_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E080_EF2C0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E260_EF4A0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E390_EF5D0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E434_EF674_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E4C0_EF700_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010E944_EFB84_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010EBE8_EFE28_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010F81C_F0A5C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010FA9C_F0CDC_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8010FC44_F0E84_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8011005C_F129C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80110530_F1770_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801113D4_F2614_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801113F4_F2634_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111448_F2688_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111494_F26D4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_8011154C_F278C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801115EC_F282C_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111678_F28B8_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111838_F2A78_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801118C8_F2B08_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801119B4_F2BF4_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111AA0_F2CE0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111B40_F2D80_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111F28_F3168_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80111FA0_F31E0_RollOutTheBarrels);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_80112000_F3240_RollOutTheBarrels);
