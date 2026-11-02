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

void func_80104D88_E5FC8_RollOutTheBarrels(omObjData* obj) {
    Vec goal;
    Vec mid;
    Vec from;
    MgWork* w;
    RBPlayer* pl;
    RBBarrel* b;
    Vec* p;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 angle;
    f32 bx;
    f32 ox;
    s32 i;
    s32 n;

    w = obj->unk_50;
    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    ContStkX[w->unk_57] = ContStkY[w->unk_57] = 0;
    ContBtn[w->unk_57] = ContBtnTrg[w->unk_57] = 0;
    b = &D_80112D68_F3FA8_RollOutTheBarrels[(s16)func_80109824_EAA64_RollOutTheBarrels(pl->target)];
    switch (pl->state) {
        case 0:
            if (fabs(b->pos.z - -500.0) < 100.0) {
                goal.x = b->pos.x;
                goal.y = b->pos.y;
                goal.z = b->pos.z;
                pl->unk_04 = 0;
            } else {
                goal.x = b->pos.x;
                goal.y = b->pos.y;
                goal.z = -500.0f;
                pl->unk_04 = 1;
            }
            mid.x = goal.x;
            mid.y = goal.y;
            mid.z = obj->trans.z;
            from.x = obj->trans.x;
            from.y = obj->trans.y;
            from.z = obj->trans.z;
            dx = goal.x - from.x;
            dz = goal.z - from.z;
            pl->pathLen = sqrtf(dx * dx + dz * dz) / 100.0;
            if (pl->pathLen < 2) {
                pl->pathLen = 2;
            } else if (pl->pathLen >= 0x10) {
                pl->pathLen = 0x10;
            }
            if (pl->path == NULL) {
                pl->path = func_80111448_F2688_RollOutTheBarrels(0xC0);
            }
            for (i = 0; i < pl->pathLen; i++) {
                func_80112000_F3240_RollOutTheBarrels((f32)i / (f32)pl->pathLen, (f32*)&from, (f32*)&mid, (f32*)&goal, (f32*)&pl->path[i]);
            }
            pl->pathIdx = 0;
            pl->state++;
        case 1:
            for (i = pl->pathIdx; i < pl->pathLen; i++) {
                p = &pl->path[pl->pathIdx];
                dx = p->x - obj->trans.x;
                dz = p->z - obj->trans.z;
                if (dx * dx + dz * dz < 400.0) {
                    pl->pathIdx++;
                } else {
                    angle = func_80111F28_F3168_RollOutTheBarrels(dx, -dz);
                    ContStkX[w->unk_57] = HuMathSin(angle) * 80.0f;
                    ContStkY[w->unk_57] = func_800B7890_B8490(angle) * 80.0f;
                    break;
                }
            }
            if (pl->pathIdx >= pl->pathLen) {
                pl->pathIdx = 0;
                pl->state++;
                func_80104D88_E5FC8_RollOutTheBarrels(obj);
            }
            break;
        case 2:
            bx = b->pos.x;
            ox = obj->trans.x;
            dz = b->pos.z - obj->trans.z;
            angle = func_80111F28_F3168_RollOutTheBarrels(bx - ox, -dz);
            ContStkX[w->unk_57] = HuMathSin(angle) * 80.0f;
            ContStkY[w->unk_57] = func_800B7890_B8490(angle) * 80.0f;
            break;
    }
    dx = b->pos.x - obj->trans.x;
    dz = b->pos.z - obj->trans.z;
    dist = sqrtf(dx * dx + dz * dz);
    angle = func_80111F28_F3168_RollOutTheBarrels(dx, -dz);
    n = pl->unk_06;
    if (n < 3) {
        if (n >= 0) {
            if (dist < b->shape->radius + w->unk_48 + w->unk_64 + RB_W68(w)) {
                if (angle > 180.0) {
                    angle -= 360.0;
                }
                if (fabs(angle) <= 30.0) {
                    ContBtn[w->unk_57] |= 0x4000;
                    ContBtnTrg[w->unk_57] |= 0x4000;
                }
            }
            return;
        }
    }
    if (obj->trans.y <= 4.0) {
        if (dist < 250.0) {
            ContBtn[w->unk_57] |= 0x8000;
            ContBtnTrg[w->unk_57] |= 0x8000;
        }
    } else {
        ContBtn[w->unk_57] |= 0x8000;
        if (dist < 20.0) {
            ContBtn[w->unk_57] |= 0x2000;
            ContBtnTrg[w->unk_57] |= 0x2000;
        }
    }
}

s32 func_8010541C_E665C_RollOutTheBarrels(omObjData* obj) {
    MgWork* w;
    RBPlayer* pl;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 angle;

    w = obj->unk_50;
    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    ContStkX[w->unk_57] = ContStkY[w->unk_57] = 0;
    ContBtn[w->unk_57] = ContBtnTrg[w->unk_57] = 0;
    D_800F8FD0_F9BD0 = 1;
    dx = D_80112168_F33A8_RollOutTheBarrels.x - obj->trans.x;
    dz = D_80112168_F33A8_RollOutTheBarrels.z - obj->trans.z;
    angle = func_80111F28_F3168_RollOutTheBarrels(dx, -dz);
    dist = sqrtf(dx * dx + dz * dz);
    switch (pl->state) {
        case 0:
            ContStkX[w->unk_57] = HuMathSin(angle) * 80.0f;
            ContStkY[w->unk_57] = func_800B7890_B8490(angle) * 80.0f;
            if (dist < 20.0) {
                func_80019B9C_1A79C(obj, 0x11);
                func_800191D4_19DD4(obj, 4, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, w->unk_3C + 180.0f);
                pl->unk_12 = 0;
                pl->state++;
            }
            return 0;
        case 1:
            if (++pl->unk_12 >= 0xF) {
                pl->unk_12 = 0;
                pl->state++;
            }
            return 1;
        case 2:
            w->unk_3C = func_80111678_F28B8_RollOutTheBarrels(0.0f, w->unk_3C, 20.0f);
            w->unk_40 = 0.0f;
            if (fabs(func_80111838_F2A78_RollOutTheBarrels(w->unk_40, w->unk_3C)) < 2.0) {
                pl->state++;
            }
            return 2;
        default:
            pl->unk_12 = 0;
            pl->state = 0;
            w->unk_40 = 0.0f;
            return 3;
    }
}

void func_801056BC_E68FC_RollOutTheBarrels(omObjData* obj) {
    RBPlayer* pl;
    MgWork* w;
    HmfModel* m;
    s32 i;
    f32 zero;

    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    w = obj->unk_50;
    m = &D_800FC834_FD434[obj->model[0]];
    ContBtn[D_80112DC8_F4008_RollOutTheBarrels] = ContBtnTrg[D_80112DC8_F4008_RollOutTheBarrels] = 0;
    ContStkX[D_80112DC8_F4008_RollOutTheBarrels] = ContStkY[D_80112DC8_F4008_RollOutTheBarrels] = 0;
    i = 0;
    if (pl->pushDone < pl->pushDist) {
        w->unk_40 = 0.0f;
        obj->trans.x = HuMathSin(pl->pushAngle) * pl->pushSpeed + obj->trans.x;
        obj->trans.z = func_800B7890_B8490(pl->pushAngle) * pl->pushSpeed + obj->trans.z;
        pl->pushDone = pl->pushDone + pl->pushSpeed;
        if (pl->pushCount >= 0xB) {
            pl->pushCount = 0xA;
        }
        pl->pushSpeed = func_800B7890_B8490((f32)pl->pushCount * 9.0f) * pl->pushSpeed;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (pl->unk_30[i] != -1) {
            switch (pl->motState) {
                case 0:
                    if (func_80019B9C_1A79C(obj, pl->unk_30[i]) != 0) {
                        pl->motState++;
                    }
                    break;
                case 1:
                    if (m->unk04 != pl->unk_30[i]) {
                        pl->motState++;
                    }
                    break;
                case 2:
                    if (m->unk02 == pl->unk_30[i]) {
                        if ((f32)D_800F92B4_F9EB4[m->unk02].unk02 <= m->unk40) {
                            pl->motState = 0;
                            pl->unk_30[i] = -1;
                        }
                    }
                    break;
            }
            break;
        }
    }
    if (i >= 4) {
        zero = 0.0f;
        pl->pushSpeed = zero;
        pl->pushDone = zero;
        pl->pushDist = zero;
        pl->pushed = 0;
    }
}

void func_80105928_E6B68_RollOutTheBarrels(omObjData* obj, f32 angle, f32 dist) {
    RBPlayer* pl;

    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    pl->pushed = 1;
    pl->pushAngle = angle;
    pl->pushSpeed = dist * 0.05;
    pl->motState = 0;
    pl->pushDist = fabs(dist);
    pl->pushDone = 0.0f;
    pl->pushCount = 0;
}

void func_80105998_E6BD8_RollOutTheBarrels(omObjData* obj, s16 mot, s16 now) {
    RBPlayer* pl;
    s32 i;

    pl = func_801113F4_F2634_RollOutTheBarrels(obj);
    if (now != 0) {
        for (i = 0; i < 4; i++) {
            if (pl->unk_30[i] == -1) {
                pl->unk_30[i] = mot;
                if (i != 0) {
                    if (func_80019B9C_1A79C(obj, pl->unk_30[i]) != 0) {
                        pl->motState = 2;
                        pl->unk_30[i] = -1;
                    }
                    break;
                }
            }
        }
    } else {
        func_80019B9C_1A79C(obj, mot);
        pl->unk_30[0] = -1;
        pl->motState = 0;
    }
}

void func_80105A70_E6CB0_RollOutTheBarrels(void) {
    D_80112D3C_F3F7C_RollOutTheBarrels = D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0, 7, 0, -1, func_80105AD8_E6D18_RollOutTheBarrels);
    func_8000C018_CC18(0);
}

void func_80105AD8_E6D18_RollOutTheBarrels(omObjData* obj) {
    RBShape* shape;
    GroundWork* w;
    s32 t;

    obj->func_ptr = func_80105CE8_E6F28_RollOutTheBarrels;
    obj->model[0] = func_80018A30_19630(0x120000, 0x99);
    obj->model[1] = func_80018A30_19630(0x120002, 0x9D);
    func_8010E4C0_EF700_RollOutTheBarrels(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    t = func_8011005C_F129C_RollOutTheBarrels(obj->model[1]);
    obj->model[2] = (D_80112DB8_F3FF8_RollOutTheBarrels = t, (u16)D_80112DB8_F3FF8_RollOutTheBarrels);
    func_8002A00C_2AC0C(obj->model[2]);
    func_80029714_2A314(obj->model[2], 0.0f, -40.0f, -2350.0f);
    obj->work[0] = func_8010DCCC_EEF0C_RollOutTheBarrels(0x120008);
    obj->work[1] = func_8010DCCC_EEF0C_RollOutTheBarrels(0x120009);
    obj->model[3] = func_80018A30_19630(0x120003, 0x99);
    obj->model[4] = func_80018A30_19630(0x120004, 0x99);
    obj->model[5] = func_80018A30_19630(0x120005, 0x99);
    shape = func_80106114_E7354_RollOutTheBarrels(NULL, &D_80112174_F33B4_RollOutTheBarrels, func_801066B4_E78F4_RollOutTheBarrels);
    func_801061B0_E73F0_RollOutTheBarrels(shape, &D_80112180_F33C0_RollOutTheBarrels, D_8011218C_F33CC_RollOutTheBarrels);
    shape->solid = 0;
    w = func_80027154_27D54(0xB4, 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = 0;
    func_8000BF24_CB24(obj, 0.0f, -800.0f, -1500.0f, 800.0f, 300.0f);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    InitFadeIn(0, 0x10);
}

void func_80105CE8_E6F28_RollOutTheBarrels(omObjData* obj) {
    RBAnim* a;
    RBAnim* b;
    s32 i;

    i = 0;
    a = SprAnimGet(obj->work[0]);
    b = SprAnimGet(obj->work[1]);
    func_8010E944_EFB84_RollOutTheBarrels(obj->model[1], D_801121B8_F33F8_RollOutTheBarrels % 360);
    func_80110530_F1770_RollOutTheBarrels(obj->model[2], obj->model[1], D_801121C0_F3400_RollOutTheBarrels, D_801121C8_F3408_RollOutTheBarrels, D_801121D0_F3410_RollOutTheBarrels, D_801121D8_F3418_RollOutTheBarrels, a, b);
    do {
        func_80029714_2A314(obj->model[3 + i], D_80112194_F33D4_RollOutTheBarrels[i].x, func_80105F80_E71C0_RollOutTheBarrels(D_80112194_F33D4_RollOutTheBarrels[i].x, D_80112194_F33D4_RollOutTheBarrels[i].z) * D_80112194_F33D4_RollOutTheBarrels[i].y, D_80112194_F33D4_RollOutTheBarrels[i].z);
        i++;
    } while (i < 3);
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_801121B8_F33F8_RollOutTheBarrels++;
        D_801121C0_F3400_RollOutTheBarrels += 0.0875;
        D_801121C8_F3408_RollOutTheBarrels += 0.075;
        D_801121D0_F3410_RollOutTheBarrels -= 0.0875;
        D_801121D8_F3418_RollOutTheBarrels += 0.075;
        D_801121C0_F3400_RollOutTheBarrels = func_800B0D98_B1998(D_801121C0_F3400_RollOutTheBarrels, a->w);
        D_801121C8_F3408_RollOutTheBarrels = func_800B0D98_B1998(D_801121C8_F3408_RollOutTheBarrels, a->w);
        D_801121D0_F3410_RollOutTheBarrels = func_800B0D98_B1998(D_801121D0_F3410_RollOutTheBarrels, b->w);
        D_801121D8_F3418_RollOutTheBarrels = func_800B0D98_B1998(D_801121D8_F3418_RollOutTheBarrels, b->h);
    }
}

f32 func_80105F80_E71C0_RollOutTheBarrels(f32 x, f32 z) {
    HmfModel* m;
    HmfData* d;
    HmfVtx* v;
    u16 n;
    u16 i;
    u16 cnt;
    f64 sum;
    f64 r;
    f32 ax;
    f32 az;

    m = &D_800FC834_FD434[D_80112DB8_F3FF8_RollOutTheBarrels];
    d = m->hmf;
    v = d->unk44[D_800FDBE0_FE7E0];
    n = d->unk18;
    cnt = 0;
    sum = 0.0;
    x -= m->pos.x;
    z -= m->pos.z;
    for (i = 0; i < n; i++, v++) {
        r = D_80112DAC_F3FEC_RollOutTheBarrels[0] * 1.5;
        ax = fabsf(v->unk00 - x);
        az = fabsf(v->unk04 - z);
        if (ax < r && az < r) {
            sum += v->unk02;
            cnt++;
            if (cnt >= 10) {
                break;
            }
        }
    }
    return sum / cnt + m->pos.y;
}

void func_801060B8_E72F8_RollOutTheBarrels(void) {
    RBShape* s;
    s32 i;
    f32 zero;

    s = D_80112D6C_F3FAC_RollOutTheBarrels;
    for (i = 0, zero = 0.0f; i < 16; i++, s++) {
        s->used = s->hit = 0;
        s->solid = 0;
        s->radius = zero;
        s->height = zero;
        s->pos.x = s->pos.y = s->pos.z = zero;
        s->offset.x = s->offset.y = s->offset.z = zero;
        s->parent = NULL;
        s->hook = NULL;
    }
}

RBShape* func_80106114_E7354_RollOutTheBarrels(omObjData* parent, Vec* pos, void (*hook)()) {
    RBShape* s;
    s32 i;

    s = D_80112D6C_F3FAC_RollOutTheBarrels;
    for (i = 0; i < 16; i++, s++) {
        if (s->used == 0) {
            s->used = 1;
            s->hit = 0;
            if (pos != NULL) {
                s->pos.x = pos->x;
                s->pos.y = pos->y;
                s->pos.z = pos->z;
            } else {
                s->pos.x = s->pos.y = s->pos.z = 0.0f;
            }
            s->offset.x = s->offset.y = s->offset.z = 0.0f;
            s->radius = 50.0f;
            s->height = 50.0f;
            s->solid = 1;
            s->parent = parent;
            s->hook = hook;
            break;
        }
    }
    return i < 16 ? s : NULL;
}

void func_801061B0_E73F0_RollOutTheBarrels(RBShape* shape, Vec* offset, f32* size) {
    if (shape != NULL) {
        if (offset != NULL) {
            shape->offset.x = offset->x;
            shape->offset.y = offset->y;
            shape->offset.z = offset->z;
        } else {
            shape->offset.x = shape->offset.y = shape->offset.z = 0.0f;
        }
        if (size != NULL) {
            shape->radius = size[0];
            shape->height = size[1];
        } else {
            shape->radius = shape->height = 0.0f;
        }
    }
}

RBShape* func_80106224_E7464_RollOutTheBarrels(omObjData* obj, Vec* prev) {
    RBShape* s;
    MgWork* w;
    f32 y;
    f32 r;
    f32 dx;
    f32 dz;
    f32 ax;
    f32 az;
    s32 i;

    s = D_80112D6C_F3FAC_RollOutTheBarrels;
    w = obj->unk_50;
    for (i = 0; i < 16; i++, s++) {
        if (s->used != 0) {
            s->hit = 0;
            if (s->parent != NULL) {
                s->pos.x = s->parent->trans.x;
                s->pos.y = s->parent->trans.y;
                s->pos.z = s->parent->trans.z;
            }
            dx = s->pos.x + s->offset.x;
            y = s->pos.y + s->offset.y;
            dz = s->pos.z + s->offset.z;
            r = s->radius + w->unk_48;
            dx -= obj->trans.x;
            ax = fabsf(dx);
            dz -= obj->trans.z;
            az = fabsf(dz);
            if ((r < ax) & (r < az)) {
                continue;
            }
            if (obj->trans.y + w->unk_34 < y) {
                continue;
            }
            if (y + s->height < obj->trans.y) {
                continue;
            }
            if (ax * ax + az * az <= r * r) {
                s->hit = 1;
                if (s->hook != NULL) {
                    s->hook(s, obj, prev);
                }
                return s;
            }
        }
    }
    return NULL;
}

// float register allocation (masked 8: r and az swapped), class 4
#ifdef NON_MATCHING
RBShape* func_801063B0_E75F0_RollOutTheBarrels(omObjData* obj, Vec* prev) {
    RBShape* s;
    MgWork* w;
    f32 frame;
    f32 y;
    f32 dx;
    f32 dz;
    f32 ax;
    f32 az;
    f32 r;
    f32 a;
    s32 i;

    s = D_80112D6C_F3FAC_RollOutTheBarrels;
    w = obj->unk_50;
    if (w->unk_5C == 0x40) {
        frame = func_80029CE4_2A8E4(obj->model[0]);
        if (D_800FC834_FD434[obj->model[0]].unk04 == 0xFF) {
            if ((frame < 16.0f) | (frame > 20.0f)) {
                return NULL;
            }
            for (i = 0; i < 16; i++, s++) {
                if (s->used != 0 && s->solid != 0) {
                    s->hit = 0;
                    if (s->parent != NULL) {
                        s->pos.x = s->parent->trans.x;
                        s->pos.y = s->parent->trans.y;
                        s->pos.z = s->parent->trans.z;
                    }
                    dx = s->pos.x + s->offset.x;
                    y = s->pos.y + s->offset.y;
                    dz = s->pos.z + s->offset.z;
                    r = s->radius + w->unk_48 + w->unk_64 + RB_W68(w);
                    dx -= obj->trans.x;
                    ax = fabsf(dx);
                    dz -= obj->trans.z;
                    az = fabsf(dz);
                    a = func_800B0D98_B1998(func_80111F28_F3168_RollOutTheBarrels(dx, dz) - w->unk_3C + 360.0, 360.0);
                    if (a >= 180.0) {
                        a -= 360.0;
                    }
                    if (fabs(a) >= 40.0) {
                        continue;
                    }
                    if ((r < ax) & (r < az)) {
                        continue;
                    }
                    if (obj->trans.y + w->unk_34 < y) {
                        continue;
                    }
                    if (y + s->height < obj->trans.y) {
                        continue;
                    }
                    if (ax * ax + az * az <= r * r) {
                        s->hit = 5;
                        if (s->hook != NULL) {
                            s->hook(s, obj, prev);
                        }
                        return s;
                    }
                }
            }
        }
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801063B0_E75F0_RollOutTheBarrels);
#endif

void func_801066B4_E78F4_RollOutTheBarrels(RBShape* shape, omObjData* obj, Vec* prev) {
    MgWork* w;
    f32 x;
    f32 z;
    f32 r;
    f32 dx;
    f32 dz;
    f64 d;
    f32 k;

    w = obj->unk_50;
    x = shape->pos.x + shape->offset.x;
    z = shape->pos.z + shape->offset.z;
    r = shape->radius + w->unk_48;
    dx = obj->trans.x - x;
    dz = obj->trans.z - z;
    d = sqrtf(dx * dx + dz * dz);
    if (d != 0.0) {
        k = r / d;
    } else {
        dz = r;
        k = 1.0f;
    }
    obj->trans.x = x + dx * k;
    obj->trans.z = z + dz * k;
}

// float register allocation (masked 16: dx, dz and the angle rotated; a shared divide tail), class 4
#ifdef NON_MATCHING
void func_801067BC_E79FC_RollOutTheBarrels(RBShape* shape, omObjData* obj, Vec* prev) {
    MgWork* w;
    s32 hit;
    f32 x;
    f32 y;
    f32 z;
    f32 r;
    f32 a;
    f32 dx;
    f32 dz;
    f32 k;
    f32 sx;
    f64 d;

    w = obj->unk_50;
    hit = shape->hit;
    shape->hit = 1;
    x = shape->pos.x + shape->offset.x;
    y = shape->pos.y + shape->offset.y;
    z = shape->pos.z + shape->offset.z;
    r = shape->radius + w->unk_48;
    dx = obj->trans.x - x;
    dz = obj->trans.z - z;
    a = func_80111F28_F3168_RollOutTheBarrels(dx, dz);
    if (y + shape->height < prev->y) {
        if (r * r > (x - prev->x) * (x - prev->x) + (z - prev->z) * (z - prev->z)) {
            if (w->unk_5C == 0x200) {
                shape->hit = 2;
            }
            obj->trans.y = y + shape->height + 20.0;
            w->unk_38 = -1.3f;
            if (shape->hit == 2) {
                func_80105928_E6B68_RollOutTheBarrels(obj, 0.0f, 260.0f);
                func_800191D4_19DD4(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
            } else {
                if (a > 30.0 && a < 150.0) {
                    a = dz < 0.0 ? 150.0f : 30.0f;
                } else if (a > 210.0 && a < 330.0) {
                    a = dz < 0.0 ? 210.0f : 330.0f;
                }
                func_80105928_E6B68_RollOutTheBarrels(obj, a, 229.99999999999997 - sqrtf(dx * dx + dz * dz));
                sx = x + (f64)(HuMathSin(a) * r) * 0.5;
                func_800191D4_19DD4(obj, 6, sx, obj->trans.y, z + (f64)(func_800B7890_B8490(a) * r) * 0.5, 60.0f, a);
            }
            func_80105998_E6BD8_RollOutTheBarrels(obj, 6, 0);
            return;
        }
    }
    if (hit == 5 && w->unk_5C == 0x40) {
        shape->hit = 3;
    }
    if (shape->hit == 3) {
        d = sqrtf(dx * dx + dz * dz);
        if (d != 0.0) {
            k = r * 1.2 / d;
        } else {
            dz = r;
            k = 1.0f;
        }
    } else {
        d = sqrtf(dx * dx + dz * dz);
        if (d != 0.0) {
            k = r / d;
        } else {
            dz = r;
            k = 1.0f;
        }
    }
    obj->trans.x = x + dx * k;
    obj->trans.z = z + dz * k;
    if (w->unk_38 != 1000.0f) {
        if (shape->hit == 3) {
            func_80105928_E6B68_RollOutTheBarrels(obj, a, 50.0f);
            func_80105998_E6BD8_RollOutTheBarrels(obj, 6, 0);
            sx = x + (f64)(HuMathSin(a) * r) * 0.5;
            func_800191D4_19DD4(obj, 6, sx, obj->trans.y, z + (f64)(func_800B7890_B8490(a) * r) * 0.5, 60.0f, a);
        }
    } else if (shape->hit == 3) {
        func_80105928_E6B68_RollOutTheBarrels(obj, a, 50.0f);
        func_80105998_E6BD8_RollOutTheBarrels(obj, 0x21, 0);
        sx = x + (f64)(HuMathSin(a) * r) * 0.5;
        func_800191D4_19DD4(obj, 6, sx, 100.0f, z + (f64)(func_800B7890_B8490(a) * r) * 0.5, 90.0f, a);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_RollOutTheBarrels/E3A40", func_801067BC_E79FC_RollOutTheBarrels);
#endif

void func_80106DE4_E8024_RollOutTheBarrels(void) {
    RBRoller* r;
    RBAnim* spr;
    Vec* v;
    s32 i;
    s32 j;
    f32 s;

    r = D_80112D64_F3FA4_RollOutTheBarrels;
    D_80112D74_F3FB4_RollOutTheBarrels[0] = func_8010DCCC_EEF0C_RollOutTheBarrels(0x120007) & 0xFFFF;
    spr = SprAnimGet((s16)D_80112D74_F3FB4_RollOutTheBarrels[0]);
    for (i = 0; i < 6; i++, r++) {
        r->used = 0;
        r->kind = 0;
        r->state = 0;
        r->timer = 0;
        r->unk_0C = 0;
        r->unk_2A = 0;
        r->pathLen = 0;
        r->pathIdx = 0;
        r->path = NULL;
        r->hook = NULL;
        if (i == 0) {
            r->mdl[0] = func_8010EBE8_EFE28_RollOutTheBarrels(spr, 1.0f);
        } else {
            r->mdl[0] = func_8010F81C_F0A5C_RollOutTheBarrels(spr, D_80112D64_F3FA4_RollOutTheBarrels->mdl[0], 1.0f);
        }
        for (j = 1; j < 12; j++) {
            r->mdl[j] = -1;
        }
        r->shadow = -1;
        func_800297E8_2A3E8(r->mdl[0], 1.3f, 1.3f, 1.3f);
        func_800298A4_2A4A4(r->mdl[0], 4, 4);
    }
    for (i = 0; i < 5; i++) {
        s = 1.3 - (f32)i / 5.0f * 0.3;
        D_80112D88_F3FC8_RollOutTheBarrels[i] = func_8010F81C_F0A5C_RollOutTheBarrels(spr, D_80112D64_F3FA4_RollOutTheBarrels->mdl[0], 0.0f);
        func_800297E8_2A3E8(D_80112D88_F3FC8_RollOutTheBarrels[i], s, s, s);
        func_800298A4_2A4A4(D_80112D88_F3FC8_RollOutTheBarrels[i], 4, 4);
    }
    for (i = 0; i < 10; i++) {
        v = &D_80112D84_F3FC4_RollOutTheBarrels[i];
        v->x = v->y = v->z = 0.0f;
    }
    D_80112D44_F3F84_RollOutTheBarrels = omAddObj(6, 1, 0, -1, func_8010704C_E828C_RollOutTheBarrels);
}

void func_8010704C_E828C_RollOutTheBarrels(omObjData* obj) {
    RBRoller* r;
    HmfModel* m;
    s32 i;

    r = D_80112D64_F3FA4_RollOutTheBarrels;
    for (i = 0; i < 6; i++, r++) {
        if (r->used != 0 && r->mdl[0] != -1) {
            m = &D_800FC834_FD434[r->mdl[0]];
            if (r->hook != NULL) {
                r->hook(r);
            }
            if (r->kind == -1 && !(m->unk18 & 4) && m->unk04 == 0xFF && func_80029D0C_2A90C(r->mdl[0]) <= m->unk40) {
                m->unk40 = m->unk48;
            }
        }
    }
}

void func_80107140_E8380_RollOutTheBarrels(RBRoller* r) {
    Vec goal;
    Vec mid;
    Vec from;
    HmfModel* m;
    Vec* p;
    f32 dx;
    f32 dz;
    s32 i;

    if (r->kind != -1) {
        r->hook = func_80107AE0_E8D20_RollOutTheBarrels;
        return;
    }
    m = &D_800FC834_FD434[r->mdl[0]];
    switch (r->state) {
        case 0:
            m->unk02 = func_80029E14_2AA14(r->mdl[1]);
            func_801096D8_EA918_RollOutTheBarrels(r->unk_2A, &goal);
            goal.x -= 80.0;
            goal.z -= 50.0;
            from.x = m->pos.x;
            from.y = m->pos.y;
            from.z = m->pos.z;
            mid.x = from.x;
            mid.y = goal.y;
            mid.z = goal.z;
            dx = goal.x - from.x;
            dz = goal.z - from.z;
            r->pathLen = sqrtf(dx * dx + dz * dz) / 100.0;
            if (r->pathLen < 2) {
                r->pathLen = 2;
            } else if (r->pathLen >= 0x10) {
                r->pathLen = 0x10;
            }
            if (r->path == NULL) {
                r->path = func_80111448_F2688_RollOutTheBarrels(0xC0);
            }
            for (i = 0; i < r->pathLen; i++) {
                func_80112000_F3240_RollOutTheBarrels((f32)i / (f32)r->pathLen, (f32*)&from, (f32*)&mid, (f32*)&goal, (f32*)&r->path[i]);
            }
            r->pathIdx = 0;
            r->state++;
        case 1:
            for (i = r->pathIdx; i < r->pathLen; i++) {
                p = &r->path[r->pathIdx];
                dx = p->x - m->pos.x;
                dz = p->z - m->pos.z;
                if (dx * dx + dz * dz < 400.0) {
                    r->pathIdx++;
                } else {
                    m->rot.y = func_80111F28_F3168_RollOutTheBarrels(dx, dz);
                    m->pos.x = m->pos.x + HuMathSin(m->rot.y) * 100.0 * 0.1325;
                    m->pos.z = m->pos.z + func_800B7890_B8490(m->rot.y) * 100.0 * 0.1325;
                    break;
                }
            }
            if (r->pathIdx >= r->pathLen) {
                func_80029BF0_2A7F0(r->mdl[0], func_80029E14_2AA14(r->mdl[4]), 0, 0x1E, 0);
                r->pathIdx = 0;
                r->state++;
            }
            break;
        case 2:
            if (fabs(m->rot.y) > 1.0) {
                m->rot.y = func_80111678_F28B8_RollOutTheBarrels(0.0f, m->rot.y, 30.0f);
            } else {
                m->rot.y = 0.0f;
                HuMemFree(r->path);
                r->path = NULL;
                r->pathLen = 0;
                r->pathIdx = 0;
                r->state++;
            }
            break;
        case 3:
            r->state = 0;
            r->hook = NULL;
            break;
    }
    if (r->shadow != -1) {
        func_80029714_2A314(r->shadow, m->pos.x, 0.0f, m->pos.z);
    }
}

void func_80107564_E87A4_RollOutTheBarrels(RBRoller* r) {
    HmfModel* m;
    f32 base;
    f32 dir;
    f32 to;
    f32 steer;
    f32 d;

    if (r != NULL && r->used != 0) {
        if (r->kind != -1) {
            r->hook = func_80107AE0_E8D20_RollOutTheBarrels;
            return;
        }
        m = &D_800FC834_FD434[r->mdl[0]];
        switch (r->state) {
            case 0:
                m->unk02 = func_80029E14_2AA14(r->mdl[2]);
                m->unk40 = func_80029D0C_2A90C(r->mdl[0]);
                m->unk44 = 1.0f;
                r->state++;
            case 1:
                func_80029BF0_2A7F0(r->mdl[0], func_80029E14_2AA14(r->mdl[1]), 0, 0x1E, 0);
                r->state++;
                break;
            case 2:
                if (m->unk04 != 0xFF) {
                    r->state++;
                }
                break;
            case 3:
                if (fabs(m->pos.x) > 650.0) {
                    base = 0.0f;
                    dir = m->pos.x >= 0.0 ? 1.0f : -1.0f;
                } else if (m->pos.x >= 0.0) {
                    base = 60.0f;
                    dir = 1.0f;
                } else {
                    base = -60.0f;
                    dir = -1.0f;
                }
                to = func_80111F28_F3168_RollOutTheBarrels(D_800FFFD8_100BD8[0]->trans.x - m->pos.x, D_800FFFD8_100BD8[0]->trans.z - m->pos.z);
                if (to <= 45.0f) {
                    to = -to;
                }
                steer = 0.0f;
                do {
                    d = func_800B0D98_B1998(to - (base + steer) + 360.0, 360.0);
                    if (180.0 < d) {
                        d -= 360.0;
                    }
                    if (30.0 <= fabs(d)) {
                        break;
                    }
                    steer = steer + dir * 15.0;
                } while (fabs(steer) < 90.0);
                m->rot.y = func_80111678_F28B8_RollOutTheBarrels(base + steer, m->rot.y, 30.0f);
                m->pos.x = m->pos.x + HuMathSin(m->rot.y) * 100.0 * 0.1325;
                m->pos.z = m->pos.z + func_800B7890_B8490(m->rot.y) * 100.0 * 0.1325;
                if (1000.0 <= fabs(m->pos.x) || 300.0 <= m->pos.z) {
                    func_800298A4_2A4A4(r->mdl[0], 4, 4);
                    if (r->shadow != -1) {
                        func_800298A4_2A4A4(r->shadow, 4, 4);
                    }
                    r->state = 0;
                    r->used = 0;
                    r->hook = NULL;
                }
                break;
        }
        if (r->shadow != -1) {
            func_80029714_2A314(r->shadow, m->pos.x, 0.0f, m->pos.z);
        }
    }
}

void func_801079D0_E8C10_RollOutTheBarrels(RBRoller* r) {
    HmfModel* m;

    if (r != NULL && r->used != 0) {
        if (r->kind != -1) {
            r->hook = func_80107AE0_E8D20_RollOutTheBarrels;
            return;
        }
        m = &D_800FC834_FD434[r->mdl[0]];
        switch (r->state) {
            case 0:
                m->unk02 = func_80029E14_2AA14(r->mdl[2]);
                m->unk40 = 0.0f;
                m->unk44 = 1.0f;
                r->state++;
            case 1:
                func_80029BF0_2A7F0(r->mdl[0], func_80029E14_2AA14(r->mdl[3]), 0, 0x1E, 0);
                r->state++;
                break;
            case 2:
                break;
        }
        if (r->shadow != -1) {
            func_80029714_2A314(r->shadow, m->pos.x, 0.0f, m->pos.z);
        }
    }
}

void func_80107AE0_E8D20_RollOutTheBarrels(RBRoller* r) {
    RBAnim* spr;
    HmfModel* m;
    f32 s;

    s = 0.0f;
    if (r != NULL && r->used != 0) {
        if (r->kind == -1) {
            r->hook = func_80107564_E87A4_RollOutTheBarrels;
            return;
        }
        spr = SprAnimGet((s16)D_80112D74_F3FB4_RollOutTheBarrels[0]);
        m = &D_800FC834_FD434[r->mdl[0]];
        switch (r->state) {
            case 0:
                func_8010DF18_EF158_RollOutTheBarrels(-1, m->pos.x, -100.0f, m->pos.z + 20.0);
                r->timer = 0;
                r->state++;
            case 1:
                s = 1.0 - (f32)r->timer / 30.0;
                if (s < 0.0) {
                    s = 0.0f;
                }
                s = HuMathSin(s * 90.0);
                func_8010FA9C_F0CDC_RollOutTheBarrels(r->mdl[0], spr, r->kind, s * s);
                if (++r->timer >= 0x1E) {
                    r->timer = 0;
                    r->state++;
                }
                break;
            case 2:
                func_800298A4_2A4A4(r->mdl[0], 4, 4);
                if (r->shadow != -1) {
                    func_800298A4_2A4A4(r->shadow, 4, 4);
                }
                r->used = 0;
                r->hook = NULL;
                r->timer = 0;
                r->state = 0;
                break;
        }
        if (r->shadow != -1) {
            func_80029714_2A314(r->shadow, m->pos.x, 0.0f, m->pos.z);
            if (r->state == 1) {
                func_800297E8_2A3E8(r->shadow, s * s, s * s, s * s);
            }
        }
    }
}

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
