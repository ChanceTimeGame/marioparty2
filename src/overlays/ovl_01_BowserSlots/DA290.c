#include "common.h"
#include "ovl_01.h"

/* Scene setup: camera, lights, the reel/sprite work buffers and the flow object. */
void func_80102800_DA290_BowserSlots(void) {
    u8 cam;

    func_8002D4D0_2E0D0(50);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80020D20_21920(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026DAC_279AC(0, 255, 255, 255);
    func_80026DAC_279AC(1, 255, 255, 255);
    func_80026E00_27A00(1, -56.0f, 50.0f, 56.0f);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 4000.0f);
    func_80103000_DAA90_BowserSlots();
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FA606_FB206 = 0;
    D_8010C058_E3AE8_BowserSlots = 0;
    D_8010C05A_E3AEA_BowserSlots = 0;
    D_8010C040_E3AD0_BowserSlots = 0;
    D_8010C0D0_E3B60_BowserSlots = func_80027154_27D54(0xB4, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C0D0_E3B60_BowserSlots, 0, 0xB4);
    D_8010C174_E3C04_BowserSlots = func_80027154_27D54(0x1B0, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C174_E3C04_BowserSlots, 0, 0x1B0);
    D_8010C170_E3C00_BowserSlots = func_80027154_27D54(0x300, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C170_E3C00_BowserSlots, 0, 0x300);
    D_8010C17E_E3C0E_BowserSlots = 1;
    D_8010C180_E3C10_BowserSlots = -1;
    D_8010C18E_E3C1E_BowserSlots = -1;
    D_800F8FD0_F9BD0 = 0;
    D_8010C030_E3AC0_BowserSlots = omAddObj(0x20, 0, 0, -1, func_80102A70_DA500_BowserSlots);
    func_8007273C_7333C("\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1); /* SJIS "START" */
    func_8007273C_7333C("\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* SJIS "FINISH" */
    func_8007273C_7333C("\x82\x68\x82\x73\x82\x64\x82\x6C\x82\x66\x82\x64\x82\x73\x81\x49\x81\x48", 1); /* SJIS "ITEMGET!?" */
}

void func_80102A70_DA500_BowserSlots(omObjData* obj) {
    obj->func_ptr = func_80102ACC_DA55C_BowserSlots;
    func_8010A0B8_E1B48_BowserSlots();
    func_80103D84_DB814_BowserSlots();
    func_8010475C_DC1EC_BowserSlots();
    func_8010A1F4_E1C84_BowserSlots();
    if (_CheckFlag(0xC) != 0) {
        D_8010C058_E3AE8_BowserSlots = 1;
    }
    PlayMusic(0x28);
}

/* The flow: start message, wait for the three reels, the result (item won or not), fade out. */
void func_80102ACC_DA55C_BowserSlots(omObjData* obj) {
    func_80102F58_DA9E8_BowserSlots(obj);
    func_8010A53C_E1FCC_BowserSlots();
    switch (D_8010B7BC_E324C_BowserSlots) {
        case 0:
            if (func_8008F618_90218() == 0) {
                func_80106084_DDB14_BowserSlots();
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 1:
            if (func_801067A4_DE234_BowserSlots() != 0) {
                func_800691FC_69DFC(0);
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 2:
            if (func_80069538_6A138() == 0) {
                D_800F8FD0_F9BD0 = 1;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 3:
            if (func_801067DC_DE26C_BowserSlots() != 0) {
                D_800F8FD0_F9BD0 = 0;
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(40);
                D_8010B7BC_E324C_BowserSlots++;
            } else if (func_800153CC_15FCC(0x127) == -1) {
                D_8010C18E_E3C1E_BowserSlots = func_80079798_7A398(0x127, 0);
            }
            break;
        case 4:
            if (func_80069538_6A138() == 0) {
                if (D_8010C0E0_E3B70_BowserSlots != -1) {
                    func_801060A4_DDB34_BowserSlots();
                }
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 5:
            if (D_8010B7C0_E3250_BowserSlots >= 3) {
                if (D_8010C0E0_E3B70_BowserSlots != -1) {
                    gPlayers[D_8010C05C_E3AEC_BowserSlots].coins_mg_bonus = func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots);
                    func_801076EC_DF17C_BowserSlots();
                } else {
                    gPlayers[D_8010C05C_E3AEC_BowserSlots].coins_mg_bonus = -1;
                    func_801060A4_DDB34_BowserSlots();
                }
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 6:
            if (D_8010C0E0_E3B70_BowserSlots != -1) {
                if (func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots) != 3) {
                    if (D_8010B7C0_E3250_BowserSlots >= 60) {
                        D_8010C190_E3C20_BowserSlots = 0x26;
                        func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B78C_E321C_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                        PlayMusic(0x53);
                        func_800732B0_73EB0(D_8010C048_E3AD8_BowserSlots[0]);
                        func_800691FC_69DFC(0x17);
                        D_8010B7C0_E3250_BowserSlots = 0;
                        D_8010B7BC_E324C_BowserSlots++;
                        D_8010B7C4_E3254_BowserSlots = 135;
                    }
                } else if (D_8010B7C0_E3250_BowserSlots >= 75.0) {
                    D_8010C190_E3C20_BowserSlots = 0x28;
                    func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B7A4_E3234_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                    PlayMusic(0x54);
                    func_800691FC_69DFC(0x18);
                    D_8010B7C0_E3250_BowserSlots = 0;
                    D_8010B7BC_E324C_BowserSlots++;
                    D_8010B7C4_E3254_BowserSlots = 144;
                }
            } else if (D_8010B7C0_E3250_BowserSlots >= 3) {
                D_8010C190_E3C20_BowserSlots = 0x29;
                func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B7A4_E3234_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                PlayMusic(0x56);
                func_80106110_DDBA0_BowserSlots();
                func_800691FC_69DFC(0x10);
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
                D_8010B7C4_E3254_BowserSlots = 132;
            }
            break;
        case 7:
            if (D_8010B7C4_E3254_BowserSlots <= 0) {
                InitFadeOut(0, 20);
                D_8010B7BC_E324C_BowserSlots++;
            } else {
                D_8010B7C4_E3254_BowserSlots--;
            }
            break;
        case 8:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80102F34_DA9C4_BowserSlots;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
    }
    D_8010B7C0_E3250_BowserSlots = (D_8010B7C0_E3250_BowserSlots + 1) & 0x7FFF;
    D_8010C040_E3AD0_BowserSlots = (D_8010C040_E3AD0_BowserSlots + 1) & 0x7FFF;
}

void func_80102F34_DA9C4_BowserSlots(omObjData* obj) {
    func_80079464_7A064();
    omOvlReturnEx(1);
}

/* Debug exit (D_801011FC == 1): fade out and return. */
void func_80102F58_DA9E8_BowserSlots(omObjData* obj) {
    if (D_8010B7C8_E3258_BowserSlots != 0) {
        if (D_8010B7C8_E3258_BowserSlots == 1) {
            obj->func_ptr = func_80102F34_DA9C4_BowserSlots;
        }
        D_8010B7C8_E3258_BowserSlots--;
        return;
    }
    if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_8010B7C8_E3258_BowserSlots = 20;
        InitFadeOut(0, (s16)D_8010B7C8_E3258_BowserSlots);
        func_800794A8_7A0A8((s16)D_8010B7C8_E3258_BowserSlots);
        func_80079614_7A214((s16)D_8010B7C8_E3258_BowserSlots);
    }
}

/* Camera start position; the blend object 801038FC. */
void func_80103000_DAA90_BowserSlots(void) {
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 427.2f;
    D_8010274C_10334C.z = 14.2f;
    D_800FD474_FE074.x = 2.25f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1890.0f;
    func_8010B1D4_E2C64_BowserSlots(&D_800FD474_FE074);
    func_80103A9C_DB52C_BowserSlots(0);
    func_80103A9C_DB52C_BowserSlots(1);
    D_8010C0C4_E3B54_BowserSlots = 0;
    D_8010C0C0_E3B50_BowserSlots = 0;
    omAddObj(0x1F, 0, 0, -1, func_801038FC_DB38C_BowserSlots);
}

/* Debug camera (not called in retail): Z cycles the mode; mode 1 moves the camera with the stick,
   C and the D-pad (R doubles, Z... START resets), mode 2 moves the text; mode 1 prints on Z. */
void func_801030C0_DAB50_BowserSlots(void) {
    BSCamera c = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f };
    f32 speed = 1.0f;

    switch (D_8010B7CC_E325C_BowserSlots) {
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
                func_80103B4C_DB5DC_BowserSlots(c.center.x, c.center.y, c.center.z, c.rot.x, c.rot.y, c.rot.z, c.zoom, 1);
            }
            sprintf(pfStrBuf, "CAMERA TEST_MODE");
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 104, pfStrBuf);
            D_800F8FD0_F9BD0 = 0;
            break;
        case 2:
            if ((ContBtn[0] & 0x100) || (ContBtn[0] & 1)) {
                D_8010B7D0_E3260_BowserSlots++;
            }
            if (ContBtn[0] & 0x202) {
                D_8010B7D0_E3260_BowserSlots--;
            }
            if (ContBtn[0] & 0x404) {
                D_8010B7D4_E3264_BowserSlots++;
            }
            if (ContBtn[0] & 0x808) {
                D_8010B7D4_E3264_BowserSlots--;
            }
            fontcolor = 8;
            sprintf(pfStrBuf, "CAMERA TEST_MODE ");
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_8010B7D0_E3260_BowserSlots + 20, (u16)D_8010B7D4_E3264_BowserSlots + 104, pfStrBuf);
            break;
        default:
            D_800F8FD0_F9BD0 = 1;
            break;
    }
    if (ContBtnTrg[0] & 0x10) {
        if (D_8010B7CC_E325C_BowserSlots & 1) {
            osSyncPrintf("CAMERA TEST_MODE \n");
            osSyncPrintf(" CENTER X>%3.3f Y>%3.3f Z>%3.3f \n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            osSyncPrintf(" ROT    X>%3.3f Y>%3.3f Z>%3.3f \n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            osSyncPrintf(" ZOOM   %3.3f \n\n", D_800FA610_FB210);
        }
        if (++D_8010B7CC_E325C_BowserSlots >= 3) {
            D_8010B7CC_E325C_BowserSlots = 0;
        }
    }
}

/* Camera blend object: from D_8010C078[1] (the start) to D_8010C078[0] over D_8010C0C4 frames. */
void func_801038FC_DB38C_BowserSlots(omObjData* obj) {
    f32 t;

    if (D_8010C0C4_E3B54_BowserSlots > 0) {
        if (D_8010C0C0_E3B50_BowserSlots == 0) {
            D_8010274C_10334C.x = D_8010C078_E3B08_BowserSlots[0].center.x;
            D_8010274C_10334C.y = D_8010C078_E3B08_BowserSlots[0].center.y;
            D_8010274C_10334C.z = D_8010C078_E3B08_BowserSlots[0].center.z;
            D_800FD474_FE074.x = D_8010C078_E3B08_BowserSlots[0].rot.x;
            D_800FD474_FE074.y = D_8010C078_E3B08_BowserSlots[0].rot.y;
            D_800FD474_FE074.z = D_8010C078_E3B08_BowserSlots[0].rot.z;
            D_800FA610_FB210 = D_8010C078_E3B08_BowserSlots[0].zoom;
            func_8010B1D4_E2C64_BowserSlots(&D_800FD474_FE074);
            D_8010C0C4_E3B54_BowserSlots = 0;
            return;
        }
        t = (f32)D_8010C0C0_E3B50_BowserSlots / (f32)D_8010C0C4_E3B54_BowserSlots;
        D_8010274C_10334C.x = D_8010C078_E3B08_BowserSlots[1].center.x + t * (D_8010C078_E3B08_BowserSlots[0].center.x - D_8010C078_E3B08_BowserSlots[1].center.x);
        D_8010274C_10334C.y = D_8010C078_E3B08_BowserSlots[1].center.y + t * (D_8010C078_E3B08_BowserSlots[0].center.y - D_8010C078_E3B08_BowserSlots[1].center.y);
        D_8010274C_10334C.z = D_8010C078_E3B08_BowserSlots[1].center.z + t * (D_8010C078_E3B08_BowserSlots[0].center.z - D_8010C078_E3B08_BowserSlots[1].center.z);
        D_800FD474_FE074.x = D_8010C078_E3B08_BowserSlots[1].rot.x + t * (D_8010C078_E3B08_BowserSlots[0].rot.x - D_8010C078_E3B08_BowserSlots[1].rot.x);
        D_800FD474_FE074.y = D_8010C078_E3B08_BowserSlots[1].rot.y + t * (D_8010C078_E3B08_BowserSlots[0].rot.y - D_8010C078_E3B08_BowserSlots[1].rot.y);
        D_800FD474_FE074.z = D_8010C078_E3B08_BowserSlots[1].rot.z + t * (D_8010C078_E3B08_BowserSlots[0].rot.z - D_8010C078_E3B08_BowserSlots[1].rot.z);
        D_800FA610_FB210 = D_8010C078_E3B08_BowserSlots[1].zoom + t * (D_8010C078_E3B08_BowserSlots[0].zoom - D_8010C078_E3B08_BowserSlots[1].zoom);
        func_8010B1D4_E2C64_BowserSlots(&D_800FD474_FE074);
        if (D_8010C0C0_E3B50_BowserSlots > 0) {
            D_8010C0C0_E3B50_BowserSlots--;
        } else {
            D_8010C0C0_E3B50_BowserSlots++;
        }
    }
}

/* Saves the current camera in D_8010C078[idx]. */
void func_80103A9C_DB52C_BowserSlots(s32 idx) {
    D_8010C078_E3B08_BowserSlots[idx].center.x = D_8010274C_10334C.x;
    D_8010C078_E3B08_BowserSlots[idx].center.y = D_8010274C_10334C.y;
    D_8010C078_E3B08_BowserSlots[idx].center.z = D_8010274C_10334C.z;
    D_8010C078_E3B08_BowserSlots[idx].rot.x = D_800FD474_FE074.x;
    D_8010C078_E3B08_BowserSlots[idx].rot.y = D_800FD474_FE074.y;
    D_8010C078_E3B08_BowserSlots[idx].rot.z = D_800FD474_FE074.z;
    D_8010C078_E3B08_BowserSlots[idx].zoom = D_800FA610_FB210;
    D_8010C078_E3B08_BowserSlots[idx].unk_1C = D_8010C078_E3B08_BowserSlots[idx].unk_20 = 0.0f;
}

/* Starts a camera blend to the given position over `frames` frames; 65535.0f keeps a value. */
void func_80103B4C_DB5DC_BowserSlots(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames) {
    if (frames > 0) {
        func_8010B1D4_E2C64_BowserSlots(&D_800FD474_FE074);
        D_8010C0C0_E3B50_BowserSlots = frames - 1;
        D_8010C0C4_E3B54_BowserSlots = frames;
        if (cx != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].center.x = cx;
        } else {
            D_8010C078_E3B08_BowserSlots[0].center.x = D_8010274C_10334C.x;
        }
        if (cy != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].center.y = cy;
        } else {
            D_8010C078_E3B08_BowserSlots[0].center.y = D_8010274C_10334C.y;
        }
        if (cz != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].center.z = cz;
        } else {
            D_8010C078_E3B08_BowserSlots[0].center.z = D_8010274C_10334C.z;
        }
        if (rx != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].rot.x = rx;
        } else {
            D_8010C078_E3B08_BowserSlots[0].rot.x = D_800FD474_FE074.x;
        }
        if (ry != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].rot.y = ry;
        } else {
            D_8010C078_E3B08_BowserSlots[0].rot.y = D_800FD474_FE074.y;
        }
        if (rz != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].rot.z = rz;
        } else {
            D_8010C078_E3B08_BowserSlots[0].rot.z = D_800FD474_FE074.z;
        }
        if (zoom != 65535.0f) {
            D_8010C078_E3B08_BowserSlots[0].zoom = zoom;
        } else {
            D_8010C078_E3B08_BowserSlots[0].zoom = D_800FA610_FB210;
        }
        func_80103A9C_DB52C_BowserSlots(1);
    }
}

void func_80103D84_DB814_BowserSlots(void) {
    func_8000C460_D060();
    func_8000C578_D178(1);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x10, 9, 60, -1, func_80103DEC_DB87C_BowserSlots);
}

/* The player object: picks the playing player (the first in group 0), CPU settings, motions. */
void func_80103DEC_DB87C_BowserSlots(omObjData* obj) {
    s32 jump[2] = { 0x4E, 0x4F };
    u16 jumpTime[2] = { 999, 999 };
    s32 land[2] = { 0x55, 0x56 };
    u16 landTime[2] = { 999, 999 };
    u16 i;
    u16 player;
    s32 dir;
    s32 r;
    s32 chance;
    s32 chr;
    s32 file;

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
    D_8010C05A_E3AEA_BowserSlots = D_8010C05C_E3AEC_BowserSlots = player;
    D_8010C064_E3AF4_BowserSlots = gPlayers[player].port;
    if (gPlayers[player].flags & 1) {
        D_8010C068_E3AF8_BowserSlots = 1;
        if ((D_8010C06C_E3AFC_BowserSlots = func_8010B38C_E2E1C_BowserSlots()) <= 0) {
            D_8010C06C_E3AFC_BowserSlots = 1;
        } else if (D_8010C06C_E3AFC_BowserSlots >= 6) {
            D_8010C06C_E3AFC_BowserSlots = 5;
        }
        D_8010C070_E3B00_BowserSlots = gPlayers[player].cpu_difficulty;
        D_8010C074_E3B04_BowserSlots = 0;
        switch (D_8010C070_E3B00_BowserSlots) {
            case 0:
                chance = (u8)(rand8() % 100) < 50;
                break;
            case 1:
                chance = (u8)(rand8() % 100) < 30;
                break;
            case 2:
                chance = (u8)(rand8() % 100) < 10;
                break;
            default:
                chance = (u8)(rand8() % 100) < 5;
                break;
        }
        if (chance) {
            D_8010C074_E3B04_BowserSlots = 1;
        }
    } else {
        D_8010C068_E3AF8_BowserSlots = 0;
        D_8010C06C_E3AFC_BowserSlots = -1;
    }
    D_8010C060_E3AF0_BowserSlots = chr = gPlayers[player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_10;
    func_8000C6FC_D2FC(obj, dir, file, player, 0x689, 0x689);
    obj->func_ptr = func_80104460_DBEF0_BowserSlots;
    ((BSPlayerWork*)obj->unk_50)->unk_EC = 0;
    obj->model[3] = LoadFormFile(7, 0x68D);
    obj->model[4] = LoadFormFile(8, 0x68D);
    obj->model[6] = LoadFormFile(9, 0x68D);
    obj->model[5] = LoadFormFile(10, 0x68D);
    obj->model[7] = LoadFormFile(12, 0x68D);
    obj->model[8] = LoadFormFile(11, 0x68D);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 0x14, dir | 0x2B, 0, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x54, 1, 999);
    D_8010C048_E3AD8_BowserSlots[0] = dir | 0x54;
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 0x27, dir | jump[r], 1, jumpTime[r]);
    D_8010C048_E3AD8_BowserSlots[1] = dir | jump[r];
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 0x28, dir | land[r], 1, landTime[r]);
    D_8010C048_E3AD8_BowserSlots[2] = dir | land[r];
    func_80019E84_1AA84(obj, 0x29, dir | 0x57, 1, 999);
    D_8010C048_E3AD8_BowserSlots[3] = dir | 0x57;
    func_8000C35C_CF5C(obj, 0.0f, 0.0f, -10.0f);
    func_8000C36C_CF6C(obj, 0.0f, 0.0f, 0.0f);
    func_8000C024_CC24(obj, 0, 2);
    D_8010C190_E3C20_BowserSlots = -1;
}

void func_80104460_DBEF0_BowserSlots(omObjData* obj) {
    BSPlayerWork* work = obj->unk_50;

    if (D_8010C068_E3AF8_BowserSlots != 0) {
        func_80104520_DBFB0_BowserSlots(obj);
    }
    if (D_800F8FD0_F9BD0 == 1) {
        ContStkX[work->unk_57] = ContStkY[work->unk_57] = 0;
    } else if (D_8010C190_E3C20_BowserSlots != -1 && func_80019B9C_1A79C(obj, (u16)D_8010C190_E3C20_BowserSlots) != 0) {
        D_8010C190_E3C20_BowserSlots = -1;
    }
    func_80007790_8390(obj);
    func_80019378_19F78(obj);
    func_80104DDC_DC86C_BowserSlots(obj);
}

/* CPU input: press A when the wanted symbol is one face before the line (or at random). */
#ifdef NON_MATCHING
/* masked 0: v0/v1 swapped in the first branch's ContBtn |= 0x8000 */
void func_80104520_DBFB0_BowserSlots(omObjData* obj) {
    BSPlayerWork* work = obj->unk_50;
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s32 face = -1;
    s32 press;
    s32 i;

    ContBtn[work->unk_57] = ContBtnTrg[work->unk_57] = 0;
    press = 0;
    if (D_800F8FD0_F9BD0 != 1) {
        return;
    }
    if (D_8010B7D8_E3268_BowserSlots > 0) {
        ContBtn[work->unk_57] |= 0x8000;
        D_8010B7D8_E3268_BowserSlots--;
        goto wait;
    }
    if (D_8010B7DC_E326C_BowserSlots != 0) {
        D_8010B7DC_E326C_BowserSlots--;
    wait:
        D_8010B7E0_E3270_BowserSlots = D_8010C06C_E3AFC_BowserSlots;
        return;
    }
    for (i = 0; i < 3; i++, reel++) {
        if (reel->state == 2) {
            face = func_8010648C_DDF1C_BowserSlots(reel->angle);
            if (D_8010C074_E3B04_BowserSlots == 0) {
                if (D_8010C06C_E3AFC_BowserSlots == func_801065D8_DE068_BowserSlots(i, face + 1) && D_8010B7E0_E3270_BowserSlots != face) {
                    press = 1;
                }
            } else if (!(D_8010C040_E3AD0_BowserSlots & 0x3F)) {
                press = 1;
            }
            if (press) {
                ContBtn[work->unk_57] |= 0x8000;
                ContBtnTrg[work->unk_57] |= 0x8000;
                D_8010B7D8_E3268_BowserSlots = 10;
                D_8010B7DC_E326C_BowserSlots = rand8() % 30 + 45.0;
            }
            break;
        }
    }
    if (i < 3) {
        D_8010B7E0_E3270_BowserSlots = face;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104520_DBFB0_BowserSlots);
#endif

void func_8010475C_DC1EC_BowserSlots(void) {
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0, 1, 0, -1, func_80104834_DC2C4_BowserSlots);
    func_8000C018_CC18(0);
    D_8010C034_E3AC4_BowserSlots = omAddObj(1, 7, 0, -1, func_80104914_DC3A4_BowserSlots);
    D_8010C038_E3AC8_BowserSlots = omAddObj(2, 8, 0, -1, func_80105088_DCB18_BowserSlots);
    D_8010C03C_E3ACC_BowserSlots = omAddObj(3, 0x15, 0, -1, func_80106820_DE2B0_BowserSlots);
}

/* The stage (ground) object. */
void func_80104834_DC2C4_BowserSlots(omObjData* obj) {
    BSGroundWork* work;

    obj->func_ptr = NULL;
    obj->model[0] = func_80018A30_19630(0x110008, 0x9D);
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    work->unk_03 = 1;
    work->unk_04 = 0;
    func_8000BF24_CB24(obj, 0.0f, -500.0f, -500.0f, 500.0f, 500.0f);
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 5.0f;
}

/* The block object: Bowser's "?" block the player jumps into (model[2]) and two sprite banners. */
void func_80104914_DC3A4_BowserSlots(omObjData* obj) {
    s32 anim1;
    s32 anim2;

    obj->func_ptr = func_80104BAC_DC63C_BowserSlots;
    obj->model[0] = func_80018A30_19630(0x110003, 0x99);
    obj->model[1] = func_80018A30_19630(0x110002, 0x4CD);
    func_800298A4_2A4A4(obj->model[1], 4, 0);
    func_80029714_2A314(obj->model[1], 0.0f, 250.0f, 0.0f);
    BS_MODEL(obj->model[1])->unk40 = 0.0f;
    BS_MODEL(obj->model[1])->unk44 = 0.0f;
    D_8010C0F0_E3B80_BowserSlots[0] = anim1 = func_8010A074_E1B04_BowserSlots(0x11000D) & 0xFFFF;
    obj->model[2] = func_80108EE4_E0974_BowserSlots(SprAnimGet(anim1), 1.0f);
    func_80109AF8_E1588_BowserSlots(obj->model[2], SprAnimGet(anim1), 0);
    obj->model[3] = func_80109BC8_E1658_BowserSlots(obj->model[3], obj->model[2]);
    func_80029714_2A314(obj->model[2], -790.0f, 900.0f, -1600.0f);
    func_80029714_2A314(obj->model[3], 790.0f, 900.0f, -1600.0f);
    D_8010C0F0_E3B80_BowserSlots[1] = anim2 = func_8010A074_E1B04_BowserSlots(0x11000C) & 0xFFFF;
    obj->model[4] = func_80108EE4_E0974_BowserSlots(SprAnimGet(anim2), 0.25f);
    obj->model[5] = func_80109BC8_E1658_BowserSlots(obj->model[5], obj->model[4]);
    func_80029714_2A314(obj->model[4], -780.0f, 830.0f, -1550.0f);
    func_80029714_2A314(obj->model[5], 780.0f, 830.0f, -1550.0f);
    func_800297E8_2A3E8(obj->model[4], 3.0f, 3.0f, 1.0f);
    func_800297E8_2A3E8(obj->model[5], 3.0f, 3.0f, 1.0f);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    obj->work[2] = anim1;
    obj->work[3] = anim2;
    InitFadeIn(0, 16);
}

/* Block object: work[0] drops the block back down after a hit, work[1] waits for its bump
   animation; the banners pulse. */
void func_80104BAC_DC63C_BowserSlots(omObjData* obj) {
    HmfModel* block = BS_MODEL(obj->model[1]);
    f32 scale;

    switch (obj->work[0]) {
        case 1:
            block->pos.y = 310.0f;
            D_8010C0C8_E3B58_BowserSlots = 0.0f;
            obj->work[0]++;
        case 2:
            block->pos.y += D_8010C0C8_E3B58_BowserSlots;
            D_8010C0C8_E3B58_BowserSlots -= 6.0;
            if (block->pos.y <= 250.0) {
                block->pos.y = 250.0f;
                D_8010C0C8_E3B58_BowserSlots = 0.0f;
                obj->work[0]++;
            }
            break;
    }
    if (obj->work[1] == 1 && func_80029D0C_2A90C(obj->model[1]) <= block->unk40) {
        block->unk18 |= 4;
        obj->work[1] = 0;
    }
    if (++D_8010B7E4_E3274_BowserSlots >= 16) {
        D_8010B7E4_E3274_BowserSlots = 0;
    }
    func_80109AF8_E1588_BowserSlots(obj->model[2], SprAnimGet(obj->work[2]), (u16)D_8010B7E4_E3274_BowserSlots);
    obj->model[3] = func_80109BC8_E1658_BowserSlots(obj->model[3], obj->model[2]);
    D_8010B7E8_E3278_BowserSlots += 30;
    if (D_8010B7E8_E3278_BowserSlots >= 360) {
        D_8010B7E8_E3278_BowserSlots -= 360;
    }
    scale = HuMathSin(D_8010B7E8_E3278_BowserSlots) * 0.3 + 3.0;
    func_800297E8_2A3E8(obj->model[4], scale, scale, 1.0f);
    func_800297E8_2A3E8(obj->model[5], scale, scale, 1.0f);
}

/* The player against the block: landing on it from below stops a reel (func_80106254), the
   sides push the player out. */
void func_80104DDC_DC86C_BowserSlots(omObjData* obj) {
    BSPlayerWork* work = obj->unk_50;
    HmfModel* block = BS_MODEL(D_8010C034_E3AC4_BowserSlots->model[1]);
    s32 under = 0;
    f32 dx;
    f32 dz;

    if (D_8010C034_E3AC4_BowserSlots->work[1] == 0) {
        if (block->pos.y <= obj->trans.y + D_8010B7EC_E327C_BowserSlots[D_8010C060_E3AF0_BowserSlots]) {
            under = 1;
        }
        dx = obj->trans.x - block->pos.x;
        dz = obj->trans.z - block->pos.z;
        if (fabs(dx) <= 60.0 && fabs(dz) <= 60.0) {
            if (under) {
                if (D_8010B804_E3294_BowserSlots == 0 && work->unk_38 < 0.0) {
                    obj->trans.y = block->pos.y - D_8010B7EC_E327C_BowserSlots[D_8010C060_E3AF0_BowserSlots] * 1.1;
                    work->unk_38 = 0.0f;
                    D_8010C034_E3AC4_BowserSlots->work[0] = 1;
                    if (func_80106254_DDCE4_BowserSlots() >= 2) {
                        func_80105034_DCAC4_BowserSlots();
                    }
                } else if (under) {
                    if (dz < dx) {
                        if (dx >= 0.0) {
                            obj->trans.x = block->pos.x + 60.0;
                        } else {
                            obj->trans.x = block->pos.x - 60.0;
                        }
                    } else {
                        if (dz >= 0.0) {
                            obj->trans.z = block->pos.z + 60.0;
                        } else {
                            obj->trans.z = block->pos.z - 60.0;
                        }
                    }
                }
            }
        }
        D_8010B804_E3294_BowserSlots = under;
    }
}

/* Starts the block's bump animation. */
void func_80105034_DCAC4_BowserSlots(void) {
    HmfModel* block = BS_MODEL(D_8010C034_E3AC4_BowserSlots->model[1]);

    if (D_8010C034_E3AC4_BowserSlots->work[1] == 0) {
        block->unk40 = 0.0f;
        block->unk44 = 1.0f;
        D_8010C034_E3AC4_BowserSlots->work[1] = 1;
    }
}

/* The machine object: the slot machine, its lever and lamps, the item sprite and the three
   reels (a texture of the eight faces' items on each, func_80107D68). */
#ifdef NON_MATCHING
/* masked 4: the lever model id is kept in s6 sign-extended at once and copied to s0 for two calls; GCC extends it at the copy */
void func_80105088_DCB18_BowserSlots(omObjData* obj) {
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s16 model;
    s32 anim;
    s32 i;
    s32 j;

    omSetStatBit(obj, 0xA0);
    obj->func_ptr = func_801054E8_DCF78_BowserSlots;
    obj->model[0] = func_80018A30_19630(0x110000, 0xB9);
    D_8010C0CC_E3B5C_BowserSlots = func_80027154_27D54(10, BS_MODEL(obj->model[0])->hmf->unk0E);
    for (i = 0; i < 5; i++) {
        D_8010C0CC_E3B5C_BowserSlots[i] = D_800CAFD8[i];
    }
    model = func_80018A30_19630(0x110001, 0x8D);
    obj->model[1] = model;
    HmfModelObjAttrSet(model, 0x20000, 0x20000);
    func_80029A8C_2A68C(model);
    D_8010C0F8_E3B88_BowserSlots[0] = func_8010A074_E1B04_BowserSlots(0x11000A) & 0xFFFF;
    anim = D_8010C0F8_E3B88_BowserSlots[0];
    obj->model[2] = func_80018A30_19630(0x110004, 0xB9);
    BS_MODEL(obj->model[2])->unk44 = 0.0f;
    BS_MODEL(obj->model[2])->unk40 = 0.0f;
    obj->model[3] = func_80018A30_19630(0x110005, 0xB9);
    BS_MODEL(obj->model[3])->unk44 = 0.0f;
    BS_MODEL(obj->model[3])->unk40 = 0.0f;
    obj->model[4] = func_80018A30_19630(0x110007, 0x9D);
    obj->model[5] = func_80018A30_19630(0x110006, 0x9D);
    func_80029714_2A314(obj->model[4], 0.0f, 550.0f, -400.0f);
    func_8002A00C_2AC0C(obj->model[4]);
    func_801078F0_DF380_BowserSlots(obj->model[4], obj->model[5]);
    D_8010C0F8_E3B88_BowserSlots[1] = func_8010A074_E1B04_BowserSlots(0x11000B) & 0xFFFF;
    obj->model[6] = func_8010879C_E022C_BowserSlots(SprAnimGet((s16)D_8010C0F8_E3B88_BowserSlots[1]), 1.0f);
    func_800298A4_2A4A4(obj->model[6], 4, 4);
    for (i = 0; i < 3; i++, reel++) {
        for (j = 0; j < 8; j++) {
            D_8010BFB0_E3A40_BowserSlots[j] = func_8010770C_DF19C_BowserSlots(D_8010B6D0_E3160_BowserSlots[i][j]);
        }
        reel->model = func_80107D68_DF7F8_BowserSlots(model, anim, D_8010B818_E32A8_BowserSlots[i], D_8010BFB0_E3A40_BowserSlots) & 0xFFFF;
        reel->state = 6;
        reel->timer = -2;
        reel->turns = 0;
        reel->passed = 0;
        reel->symbol = -1;
        reel->face = -1;
        reel->target = -1;
        reel->unk_20 = 0;
        reel->angle = (u8)(rand8() % 7) * 45.0;
        reel->offset = 135.0f;
        reel->speed = 0.0f;
        reel->accel = 0.0f;
        reel->maxSpeed = 7.0f;
        reel->part = func_8002A9F4_2B5F4(model, D_8010B818_E32A8_BowserSlots[i]);
    }
    D_8010C0D4_E3B64_BowserSlots = 0;
    D_8010C0D8_E3B68_BowserSlots = -1;
    D_8010C0DC_E3B6C_BowserSlots = -1;
    D_8010C0E0_E3B70_BowserSlots = -1;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105088_DCB18_BowserSlots);
#endif

void func_801054E8_DCF78_BowserSlots(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        func_80105568_DCFF8_BowserSlots(obj);
        if (obj->work[0] != 0) {
            func_80105AE4_DD574_BowserSlots(obj);
        }
        if (obj->work[1] != 0) {
            func_80105C28_DD6B8_BowserSlots(obj);
        }
    }
    if (obj->work[2] != 0) {
        func_80105D5C_DD7EC_BowserSlots(obj);
    }
}

/* Reel update. A reel starts when the previous one has passed a face; each stop sets the
   next reel's spin time; after the third the result is read (three equal symbols win). */
#ifdef NON_MATCHING
/* masked 25, logic checked: retail hoists the constants 3 and 1 out of the reel loop into s5/s4, GCC 3 and -2 */
void func_80105568_DCFF8_BowserSlots(omObjData* obj) {
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s32 face;
    s32 i;

    if (((reel[1].state == 0) | (reel[1].state == 6)) && reel[0].state == 2 && reel[0].passed > 0) {
        reel[0].maxSpeed = 7.0f;
        reel[0].state = 1;
        reel[1].state = 1;
    }
    if (((D_8010C0D0_E3B60_BowserSlots[2].state == 0) | (D_8010C0D0_E3B60_BowserSlots[2].state == 6)) && D_8010C0D0_E3B60_BowserSlots[1].state == 2 && D_8010C0D0_E3B60_BowserSlots[1].passed > 0) {
        D_8010C0D0_E3B60_BowserSlots[2].state = 1;
    }
    for (i = 0; i < 3; i++, reel++) {
        switch (reel->state) {
            case 0:
                if (i < 2) {
                    if (reel->timer >= 0) {
                        func_80079798_7A398(0x128, 1);
                        reel->timer = -2;
                        if (D_8010C0D0_E3B60_BowserSlots[i + 1].state == 2) {
                            D_8010C0D0_E3B60_BowserSlots[i + 1].timer = ((rand8() << 8) | rand8()) % 30 + 870;
                        }
                    }
                } else if (reel->timer >= 0) {
                    if (D_8010C18E_E3C1E_BowserSlots >= 0) {
                        func_80079848_7A448(D_8010C18E_E3C1E_BowserSlots);
                        D_8010C18E_E3C1E_BowserSlots = -1;
                    }
                    func_80079798_7A398(0x128, 1);
                    if (D_8010C0D8_E3B68_BowserSlots == func_801063CC_DDE5C_BowserSlots(i, reel->angle)) {
                        D_8010C0E0_E3B70_BowserSlots = D_8010C0D8_E3B68_BowserSlots;
                        D_8010C180_E3C10_BowserSlots = func_8010770C_DF19C_BowserSlots(D_8010C0D8_E3B68_BowserSlots);
                        if (func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots) != 3) {
                            func_80079798_7A398(0x12A, 3);
                        }
                    } else {
                        D_8010C180_E3C10_BowserSlots = -1;
                    }
                    func_80105034_DCAC4_BowserSlots();
                    D_8010C17E_E3C0E_BowserSlots = 0;
                    reel->timer = -2;
                }
                if (i == 1 && D_8010C0D4_E3B64_BowserSlots == 0) {
                    if ((D_8010C0D4_E3B64_BowserSlots = func_80106750_DE1E0_BowserSlots()) != 0) {
                        D_8010C17E_E3C0E_BowserSlots = 3;
                        D_8010C182_E3C12_BowserSlots = func_8010770C_DF19C_BowserSlots(D_8010C0D8_E3B68_BowserSlots);
                    }
                }
                break;
            case 1:
                if (reel->accel < reel->maxSpeed * 0.1) {
                    reel->accel += reel->maxSpeed * 0.02;
                }
                reel->speed += reel->accel;
                if (reel->maxSpeed <= reel->speed) {
                    reel->speed = reel->maxSpeed;
                    reel->state = 2;
                }
            case 2:
                if (reel->timer >= 0 && --reel->timer == 0) {
                    reel->state = 3;
                }
                reel->angle += reel->speed;
                if (reel->angle >= 360.0) {
                    reel->angle -= 360.0;
                    reel->turns++;
                }
                if (reel->face != func_8010648C_DDF1C_BowserSlots(reel->angle)) {
                    reel->passed++;
                }
                break;
            case 3:
                reel->angle += reel->speed;
                if (reel->angle >= 360.0) {
                    reel->angle -= 360.0;
                    reel->turns++;
                }
                if (reel->face != func_8010648C_DDF1C_BowserSlots(reel->angle)) {
                    goto snap;
                }
                break;
            case 4:
                reel->angle += reel->speed;
                if (reel->angle >= 360.0) {
                    reel->angle -= 360.0;
                    reel->turns++;
                }
                if (reel->target == func_8010648C_DDF1C_BowserSlots(reel->angle)) {
                    goto snap;
                }
                break;
            case 5:
            snap:
                reel->angle = func_80106524_DDFB4_BowserSlots(reel->angle);
                reel->speed = 0.0f;
                reel->state = 0;
                reel->timer = 1;
                break;
        }
        reel->symbol = func_801063CC_DDE5C_BowserSlots(i, reel->angle);
        reel->face = func_8010648C_DDF1C_BowserSlots(reel->angle);
        reel->part->unk34.x = reel->angle + reel->offset + 0.0;
        func_8010B148_E2BD8_BowserSlots(reel->part);
        func_80030CD4_318D4((f32(*)[4])BS_MODEL(reel->model)->mtx, reel->part->unk58);
    }
    if (D_8010C0D4_E3B64_BowserSlots != 0) {
        face = func_8010648C_DDF1C_BowserSlots(D_8010C0D0_E3B60_BowserSlots[2].angle);
        for (i = 0; i < 8; i++) {
            if (D_8010C0D8_E3B68_BowserSlots == func_801065D8_DE068_BowserSlots(2, face + i)) {
                D_8010C0DC_E3B6C_BowserSlots = i;
                break;
            }
        }
        if (D_8010C0DC_E3B6C_BowserSlots >= 8) {
            D_8010C0DC_E3B6C_BowserSlots = -1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105568_DCFF8_BowserSlots);
#endif

/* The lever (model[3]): pulled when the block is hit; at frame 110 the reels start. */
void func_80105AE4_DD574_BowserSlots(omObjData* obj) {
    HmfModel* lever = BS_MODEL(obj->model[3]);

    switch (obj->work[0]) {
        case 1:
            lever->unk40 = 0.0f;
            lever->unk44 = 1.0f;
            lever->unk48 = 150.0f;
            PlaySound(0x126);
            obj->work[0]++;
            break;
        case 2:
            if (lever->unk40 >= 45.0) {
                obj->work[0]++;
            }
            break;
        case 3:
            if (lever->unk40 >= 110.0) {
                func_80106148_DDBD8_BowserSlots();
                obj->work[0]++;
            }
            break;
        case 4:
            if (lever->unk40 >= 150.0) {
                lever->unk44 = 0.0f;
                lever->unk40 = 0.0f;
                lever->unk48 = 0.0f;
                obj->work[0] = 0;
            }
            break;
    }
}

/* The machine's door (model[2]): opens (states 1-2) and closes (4-5). */
void func_80105C28_DD6B8_BowserSlots(omObjData* obj) {
    HmfModel* door = BS_MODEL(obj->model[2]);

    switch (obj->work[1]) {
        case 1:
            door->unk40 = 0.0f;
            door->unk44 = 3.0f;
            door->unk48 = 60.0f;
            obj->work[1]++;
            break;
        case 2:
            if (door->unk40 >= 60.0) {
                door->unk44 = 0.0f;
                door->unk40 = 60.0f;
                door->unk48 = 60.0f;
                obj->work[1]++;
            }
            break;
        case 4:
            door->unk40 = 60.0f;
            door->unk44 = -3.0f;
            door->unk48 = 0.0f;
            obj->work[1]++;
            break;
        case 5:
            if (door->unk40 <= 0.0) {
                door->unk44 = 0.0f;
                door->unk40 = 0.0f;
                door->unk48 = 0.0f;
                obj->work[1] = 0;
            }
            break;
    }
}

/* The "no item" lamp (work[2]): model[4] and the sprite model[6] flash and turn. */
void func_80105D5C_DD7EC_BowserSlots(omObjData* obj) {
    f32 s;

    switch (obj->work[2]) {
        case 1:
            func_800298A4_2A4A4(obj->model[4], 4, 0);
            func_800298A4_2A4A4(obj->model[6], 4, 0);
            func_800297E8_2A3E8(obj->model[6], 1.5f, 1.5f, 1.5f);
            D_8010B844_E32D4_BowserSlots = 15.0f;
            D_8010B834_E32C4_BowserSlots = 0;
            D_8010B830_E32C0_BowserSlots = 0;
            D_8010B838_E32C8_BowserSlots = 0;
            D_8010B83C_E32CC_BowserSlots = 90.0f;
            D_8010B840_E32D0_BowserSlots = 1.0f;
            obj->work[2]++;
        case 2:
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                D_8010B830_E32C0_BowserSlots += (s32)D_8010B844_E32D4_BowserSlots;
                if (D_8010B830_E32C0_BowserSlots >= 360) {
                    D_8010B830_E32C0_BowserSlots -= 360;
                }
            }
            s = HuMathSin(D_8010B830_E32C0_BowserSlots);
            if (s < 0.0) {
                s = -(f64)s;
            }
            if ((D_8010B830_E32C0_BowserSlots >= 90 && D_8010B834_E32C4_BowserSlots < 90) || (D_8010B830_E32C0_BowserSlots >= 270 && D_8010B834_E32C4_BowserSlots < 270)) {
                D_8010B838_E32C8_BowserSlots = 1;
            }
            if ((D_8010B830_E32C0_BowserSlots >= 180 && D_8010B834_E32C4_BowserSlots < 180) || (D_8010B830_E32C0_BowserSlots < 90 && D_8010B834_E32C4_BowserSlots >= 271)) {
                D_8010B83C_E32CC_BowserSlots += 180.0;
                if (D_8010B83C_E32CC_BowserSlots >= 360.0) {
                    D_8010B83C_E32CC_BowserSlots -= 360.0;
                } else if (D_8010B83C_E32CC_BowserSlots < 0.0) {
                    D_8010B83C_E32CC_BowserSlots += 360.0;
                }
            }
            if (D_8010B838_E32C8_BowserSlots != 0) {
                s = s * 0.7 + 0.3;
            }
            func_8002A15C_2AD5C(obj->model[4], obj->model[5], s);
            func_80107BCC_DF65C_BowserSlots(obj->model[4], obj->model[6], D_8010B83C_E32CC_BowserSlots, s * D_8010B840_E32D0_BowserSlots, s);
            D_8010B834_E32C4_BowserSlots = D_8010B830_E32C0_BowserSlots;
            break;
    }
}

void func_80106084_DDB14_BowserSlots(void) {
    if (D_8010C038_E3AC8_BowserSlots->work[0] == 0) {
        D_8010C038_E3AC8_BowserSlots->work[0] = 1;
    }
}

void func_801060A4_DDB34_BowserSlots(void) {
    if (D_8010C038_E3AC8_BowserSlots->work[1] == 0) {
        omVibrate(D_8010C05E_E3AEE_BowserSlots, 10, 0, 10);
        D_8010C038_E3AC8_BowserSlots->work[1] = 1;
    }
}

void func_801060F0_DDB80_BowserSlots(void) {
    if (D_8010C038_E3AC8_BowserSlots->work[1] != 0) {
        D_8010C038_E3AC8_BowserSlots->work[1] = 4;
    }
}

void func_80106110_DDBA0_BowserSlots(void) {
    if (D_8010C038_E3AC8_BowserSlots->work[2] == 0) {
        D_8010C038_E3AC8_BowserSlots->work[2] = 1;
        func_80079798_7A398(0x12C, 3);
    }
}

/* Starts the reels (the lever's frame 110): the first spins 870-899 frames. */
void func_80106148_DDBD8_BowserSlots(void) {
    s32 i;

    if (func_801067DC_DE26C_BowserSlots() != 0) {
        D_8010C0D0_E3B60_BowserSlots[0].maxSpeed = 5.6f;
        D_8010C0D0_E3B60_BowserSlots[0].state = 1;
        D_8010C0D0_E3B60_BowserSlots[0].timer = ((rand8() << 8) | rand8()) % 30 + 870;
        for (i = 1; i < 3; i++) {
            D_8010C0D0_E3B60_BowserSlots[i].timer = -1;
        }
        D_8010C0D4_E3B64_BowserSlots = 0;
        D_8010C17E_E3C0E_BowserSlots = 2;
        if (D_8010C18E_E3C1E_BowserSlots < 0) {
            D_8010C18E_E3C1E_BowserSlots = func_80079798_7A398(0x127, 0);
        }
    }
}

/* A hit on the block stops the first spinning reel; once the first two match, the third may
   stop on the matching symbol (within 20 degrees) or slide one or two faces to it, at the
   difficulty's chance. Returns the reel's index (3: none spinning). */
s32 func_80106254_DDCE4_BowserSlots(void) {
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s32 face;
    s32 i;

    for (i = 0; i < 3; i++, reel++) {
        if (reel->state == 2) {
            if (i < 2) {
                reel->state = 3;
            } else if (D_8010C0D4_E3B64_BowserSlots == 0) {
                reel->state = 3;
            } else {
                face = func_8010648C_DDF1C_BowserSlots(reel->angle);
                if (D_8010C0D8_E3B68_BowserSlots == func_801065D8_DE068_BowserSlots(i, face)) {
                    if (reel->angle - func_80106524_DDFB4_BowserSlots(reel->angle) < 20.0) {
                        reel->state = 5;
                        reel->target = face;
                    } else {
                        reel->state = 3;
                    }
                } else if (D_8010C0D8_E3B68_BowserSlots == func_801065D8_DE068_BowserSlots(i, face + 1)) {
                    reel->state = 4;
                    reel->target = func_80106638_DE0C8_BowserSlots(D_8010C0D8_E3B68_BowserSlots, face, 1);
                } else if (D_8010C0D8_E3B68_BowserSlots == func_801065D8_DE068_BowserSlots(i, face + 2)) {
                    reel->state = 4;
                    reel->target = func_80106638_DE0C8_BowserSlots(D_8010C0D8_E3B68_BowserSlots, face, 2);
                } else {
                    reel->state = 3;
                }
                if (reel->target >= 8) {
                    reel->target -= 8;
                }
            }
            break;
        }
    }
    return i;
}

/* The symbol under the line at `angle` on reel `reel` (MP1 func_800FC7A8 + func_800FC8C8). */
s32 func_801063CC_DDE5C_BowserSlots(s32 reel, f32 angle) {
    s32 i;

    if (angle >= 360.0) {
        angle -= 360.0;
    } else if (angle < 0.0) {
        angle += 360.0;
    }
    for (i = 0; i < 8; i++) {
        if (angle < D_8010B6B0_E3140_BowserSlots[i]) {
            break;
        }
    }
    return D_8010B6D0_E3160_BowserSlots[reel][i];
}

/* The face under the line at `angle` (MP1 func_800FC7A8). */
s32 func_8010648C_DDF1C_BowserSlots(f32 angle) {
    s32 i;

    if (angle >= 360.0) {
        angle -= 360.0;
    } else if (angle < 0.0) {
        angle += 360.0;
    }
    for (i = 0; i < 8; i++) {
        if (angle < D_8010B6B0_E3140_BowserSlots[i]) {
            break;
        }
    }
    return i;
}

/* The start angle of the face under the line at `angle`. */
f32 func_80106524_DDFB4_BowserSlots(f32 angle) {
    s32 i;

    if (angle >= 360.0) {
        angle -= 360.0;
    } else if (angle < 0.0) {
        angle += 360.0;
    }
    for (i = 0; i < 8; i++) {
        if (angle < D_8010B6B0_E3140_BowserSlots[i]) {
            break;
        }
    }
    return i != 0 ? D_8010B6B0_E3140_BowserSlots[i - 1] : 0.0f;
}

/* The symbol of `face` on `reel`, both wrapped once (MP1 func_800FC8C8). */
s32 func_801065D8_DE068_BowserSlots(s32 reel, s32 face) {
    if (reel >= 3) {
        reel -= 3;
    } else if (reel < 0) {
        reel += 3;
    }
    if (face >= 8) {
        face -= 8;
    } else if (face < 0) {
        face += 8;
    }
    return D_8010B6D0_E3160_BowserSlots[reel][face];
}

/* Where the third reel stops when the matching symbol is `dist` faces away: on it at the
   symbol's chance (D_8010B73C), else one face short. */
s32 func_80106638_DE0C8_BowserSlots(s32 symbol, s32 face, s32 dist) {
    s32 chance = D_8010B73C_E31CC_BowserSlots[symbol];

    switch (dist) {
        case 1:
            if ((u8)(rand8() % 100) < chance + (100 - chance) / 2) {
                return face + 1;
            }
            return face + 2;
        case 2:
            if ((u8)(rand8() % 100) < chance) {
                return face + 3;
            }
            if (rand8() & 1) {
                return face + 3;
            }
            return face + 1;
    }
    return 0;
}

/* After the second reel stops: do the first two show the same symbol? */
s32 func_80106750_DE1E0_BowserSlots(void) {
    if (D_8010C0D4_E3B64_BowserSlots != 0) {
        return 1;
    }
    if (D_8010C0D0_E3B60_BowserSlots[0].symbol == D_8010C0D0_E3B60_BowserSlots[1].symbol && D_8010C0D0_E3B60_BowserSlots[0].state == 0 && D_8010C0D0_E3B60_BowserSlots[1].state == 0) {
        D_8010C0D8_E3B68_BowserSlots = D_8010C0D0_E3B60_BowserSlots[0].symbol;
        return 1;
    }
    return 0;
}

/* All three reels spinning. */
s32 func_801067A4_DE234_BowserSlots(void) {
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s32 i;

    for (i = 0; i < 3; i++, reel++) {
        if (reel->state != 2) {
            return 0;
        }
    }
    return 1;
}

/* All three reels stopped. */
s32 func_801067DC_DE26C_BowserSlots(void) {
    BSReel* reel = D_8010C0D0_E3B60_BowserSlots;
    s32 i;

    for (i = 0; i < 3; i++, reel++) {
        if ((reel->state != 0) & (reel->state != 6)) {
            return 0;
        }
    }
    return 1;
}

/* The item object: five trail sprites (model[0-4]) and sixteen sparkles (model[5-20]). */
void func_80106820_DE2B0_BowserSlots(omObjData* obj) {
    s32 anim;
    s32 i;
    f32 f;
    f32 z;
    f32 s;
    HmfModel* m;

    obj->func_ptr = func_80106B30_DE5C0_BowserSlots;
    D_8010C100_E3B90_BowserSlots = func_8010A074_E1B04_BowserSlots(0x110009) & 0xFFFF;
    anim = D_8010C100_E3B90_BowserSlots;
    for (i = 0; i < 5; i++) {
        f = i;
        z = 1.0 - f * 0.2f;
        obj->model[i] = func_80108EE4_E0974_BowserSlots(SprAnimGet(anim), z);
        func_8010A0EC_E1B7C_BowserSlots(obj->model[i], 2, 0x400);
        s = 1.3 - f * 0.060000002f;
        func_800297E8_2A3E8(obj->model[i], s, s, z);
        func_80029F2C_2AB2C(obj->model[i], 0);
        func_80109AF8_E1588_BowserSlots(obj->model[i], SprAnimGet(anim), 0);
        func_80029714_2A314(obj->model[i], 300.0f, 0.0f, 0.0f);
        func_800298A4_2A4A4(obj->model[i], 4, 4);
    }
    for (i = 5; i < 21; i++) {
        obj->model[i] = LoadFormFile(0x1001F, D_8010B848_E32D8_BowserSlots[(i - 5) / 5] | 0x99);
        func_80029F2C_2AB2C(obj->model[i], 0x800);
        HmfModelObjAttrSet(obj->model[i], 0x600, 0x400);
        m = BS_MODEL(obj->model[i]);
        m->unk40 = 0.0f;
        m->unk44 = 1.0f;
        func_800298A4_2A4A4(obj->model[i], 4, 4);
    }
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    obj->scale.x = obj->scale.y = 1.3f;
    obj->scale.z = 1.0f;
    obj->work[3] = anim;
}

/* The item flight (work[0]): 1 starts at the machine, 2 arcs up out of it, 3 falls to the player
   on a Bezier curve (x uses 6 where 3 belongs: retail), 4 bobs over the player's head. The five
   trail sprites follow ten frames of positions; sparkles are left behind. */
#ifdef NON_MATCHING
/* masked 2: the sparkle loop's hoisted constants come out in another order (20.0 after the two table addresses) */
void func_80106B30_DE5C0_BowserSlots(omObjData* obj) {
    HmfModel* m;
    void* anim;
    s32 item;
    s32 sparkle;
    s32 bob;
    s32 i;
    s32 k;
    f32 x2;
    f32 t;
    f32 u;
    f32 x;
    f32 y;
    f32 x1;
    f32 y1;
    f32 y2;
    f32 amp;
    f32 a;
    Vec pos;

    sparkle = 0;
    bob = 0;
    if (obj->work[0] == 0) {
        return;
    }
    if (D_8010B8B4_E3344_BowserSlots == -1) {
        D_8010B8B4_E3344_BowserSlots = (s16)PlaySound(0x12E);
    }
    switch (obj->work[0]) {
        case 1:
            obj->trans.x = D_8010B874_E3304_BowserSlots.x;
            obj->trans.y = D_8010B874_E3304_BowserSlots.y;
            obj->trans.z = D_8010B874_E3304_BowserSlots.z;
            for (i = 0; i < 10; i++) {
                D_8010BFB8_E3A48_BowserSlots[i].x = obj->trans.x;
                D_8010BFB8_E3A48_BowserSlots[i].y = obj->trans.y;
                D_8010BFB8_E3A48_BowserSlots[i].z = obj->trans.z;
            }
            for (i = 0; i < 5; i++) {
                func_800298A4_2A4A4(obj->model[i], 4, 0);
            }
            D_8010B898_E3328_BowserSlots = -30.0f;
            D_8010B89C_E332C_BowserSlots = 240.0f;
            goto next;
        case 2:
            t = (f32)D_8010B8AC_E333C_BowserSlots / (f32)D_8010B8A0_E3330_BowserSlots;
            obj->trans.x = D_8010B874_E3304_BowserSlots.x + t * (D_8010B880_E3310_BowserSlots.x - D_8010B874_E3304_BowserSlots.x);
            obj->trans.z = D_8010B874_E3304_BowserSlots.z + t * (D_8010B880_E3310_BowserSlots.z - D_8010B874_E3304_BowserSlots.z);
            obj->trans.y = D_8010B874_E3304_BowserSlots.y + 2.0 * (HuMathSin(t * 180.0 * 0.85) * 100.0);
            if ((f64)D_8010B8AC_E333C_BowserSlots > D_8010B8A0_E3330_BowserSlots * 0.2 && !(D_8010B8AC_E333C_BowserSlots & 7)) {
                sparkle = 1;
            }
            if (D_8010B8AC_E333C_BowserSlots == 10) {
                func_8010A138_E1BC8_BowserSlots(-1, -1);
            }
            if (D_8010B8AC_E333C_BowserSlots >= D_8010B8A0_E3330_BowserSlots) {
                D_8010B880_E3310_BowserSlots.y = obj->trans.y;
                obj->work[0]++;
                D_8010B8AC_E333C_BowserSlots = 3;
            }
            break;
        case 3:
            if (!(D_8010B8AC_E333C_BowserSlots & 3)) {
                sparkle = 1;
            }
            amp = 0.0f;
            if (D_8010B8C8_E3358_BowserSlots != 0) {
                D_8010B8B8_E3348_BowserSlots[0] = D_8010B88C_E331C_BowserSlots.x;
                D_8010B8C0_E3350_BowserSlots[0] = D_8010B88C_E331C_BowserSlots.y;
                D_8010B8B8_E3348_BowserSlots[1] = D_8010B880_E3310_BowserSlots.x;
                D_8010B8C0_E3350_BowserSlots[1] = D_8010B880_E3310_BowserSlots.y;
                D_8010B8C8_E3358_BowserSlots = 0;
            }
            x1 = D_8010B8B8_E3348_BowserSlots[0] * 0.5 + 200.0;
            y1 = D_8010B8C0_E3350_BowserSlots[0] * 0.5 + 60.0;
            x2 = D_8010B8B8_E3348_BowserSlots[1];
            y2 = D_8010B8C0_E3350_BowserSlots[1] - 50.0;
            if (D_8010B8AC_E333C_BowserSlots >= 0) {
                u = 1.0 - (f32)D_8010B8AC_E333C_BowserSlots / (f32)D_8010B8A4_E3334_BowserSlots;
                u = (u > 1.0) ? 1.0f : u;
                x = D_8010B8B8_E3348_BowserSlots[0] * (1.0 - u) * (1.0 - u) * (1.0 - u) + x1 * 6.0 * u * (1.0 - u) * (1.0 - u) +
                    x2 * 3.0 * u * u * (1.0 - u) + u * D_8010B8B8_E3348_BowserSlots[1] * u * u;
                y = D_8010B8C0_E3350_BowserSlots[0] * (1.0 - u) * (1.0 - u) * (1.0 - u) + y1 * 3.0 * u * (1.0 - u) * (1.0 - u) +
                    y2 * 3.0 * u * u * (1.0 - u) + (D_8010B8C0_E3350_BowserSlots[1] + -20.0f) * u * u * u;
            } else {
                amp = (amp - 0.25 < 8.0) ? 8.0f : amp - 0.25;
                x = D_8010B8B8_E3348_BowserSlots[1];
                y = D_8010B8C0_E3350_BowserSlots[1] + -20.0f +
                    HuMathSin(HuMathSin(-D_8010B8AC_E333C_BowserSlots * 6.0 + 30.0) < HuMathSin(-D_8010B8AC_E333C_BowserSlots * 6.0) * amp
                                  ? -D_8010B8AC_E333C_BowserSlots * 6.0 + 30.0
                                  : -D_8010B8AC_E333C_BowserSlots * 6.0) * amp + 1.0f;
            }
            obj->trans.x = x;
            obj->trans.y = y;
            if (D_8010B8AC_E333C_BowserSlots < 11) {
                a = D_8010B8AC_E333C_BowserSlots / 10.0f;
                pos.x = obj->trans.x;
                pos.y = obj->trans.y;
                obj->trans.x = a * (pos.x - D_8010B880_E3310_BowserSlots.x) + D_8010B880_E3310_BowserSlots.x;
                obj->trans.y = a * (pos.y - D_8010B880_E3310_BowserSlots.y) + D_8010B880_E3310_BowserSlots.y;
            }
            if (D_8010B8AC_E333C_BowserSlots >= D_8010B8A4_E3334_BowserSlots) {
                func_801060F0_DDB80_BowserSlots();
                obj->trans.x = D_8010B8B8_E3348_BowserSlots[0];
                obj->trans.y = D_8010B8C0_E3350_BowserSlots[0];
            next:
                obj->work[0]++;
                D_8010B8AC_E333C_BowserSlots = 0;
            }
            break;
        case 4:
            if (D_8010B8AC_E333C_BowserSlots >= 45) {
                D_8010B8AC_E333C_BowserSlots -= 45;
            }
            bob = 1;
            y = HuMathSin(D_8010B8AC_E333C_BowserSlots * 8 - 180) * 1.2 * 20.0;
            obj->trans.y = y + D_8010B88C_E331C_BowserSlots.y;
            if (!(D_8010B8AC_E333C_BowserSlots & 0xF)) {
                sparkle = 1;
            }
            break;
    }
    if (D_8010C0E0_E3B70_BowserSlots >= 0 && obj->work[0] != 0) {
        anim = SprAnimGet((s16)D_8010C100_E3B90_BowserSlots);
        item = func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots);
        for (i = 0; i < 5; i++) {
            func_80109AF8_E1588_BowserSlots(obj->model[i], anim, (u16)item);
            if (i != 0) {
                k = D_8010B8B0_E3340_BowserSlots - i;
                while (k < 0) {
                    k += 10;
                }
                func_80029714_2A314(obj->model[i], D_8010BFB8_E3A48_BowserSlots[k].x, D_8010BFB8_E3A48_BowserSlots[k].y, obj->trans.z - (f32)i * 10.0);
                if (bob && D_8010BFB8_E3A48_BowserSlots[k].x == D_8010B88C_E331C_BowserSlots.x && D_8010BFB8_E3A48_BowserSlots[k].y == D_8010B88C_E331C_BowserSlots.y) {
                    func_800298A4_2A4A4(obj->model[i], 4, 4);
                }
            }
        }
    }
    if (sparkle) {
        for (i = 5; i < 21; i++) {
            m = BS_MODEL(obj->model[i]);
            if (m->unk18 & 4) {
                if (!bob) {
                    m->pos.x = obj->trans.x;
                    m->pos.y = obj->trans.y;
                } else {
                    if (++D_8010B8A8_E3338_BowserSlots >= 4) {
                        D_8010B8A8_E3338_BowserSlots -= 4;
                    }
                    m->pos.x = obj->trans.x + D_8010B854_E32E4_BowserSlots[D_8010B8A8_E3338_BowserSlots];
                    m->pos.y = obj->trans.y + D_8010B864_E32F4_BowserSlots[D_8010B8A8_E3338_BowserSlots];
                }
                m->pos.z = obj->trans.z + 20.0;
                m->unk44 = 1.5f;
                m->unk18 &= ~4;
                break;
            }
        }
    }
    for (i = 5; i < 21; i++) {
        m = BS_MODEL(obj->model[i]);
        if (!(m->unk18 & 4) && func_80029D0C_2A90C(obj->model[i]) <= m->unk40) {
            m->unk18 |= 4;
            m->unk40 = 0.0f;
        }
    }
    D_8010BFB8_E3A48_BowserSlots[D_8010B8B0_E3340_BowserSlots].x = obj->trans.x;
    D_8010BFB8_E3A48_BowserSlots[D_8010B8B0_E3340_BowserSlots].y = obj->trans.y;
    D_8010BFB8_E3A48_BowserSlots[D_8010B8B0_E3340_BowserSlots].z = obj->trans.z;
    if (++D_8010B8B0_E3340_BowserSlots >= 10) {
        D_8010B8B0_E3340_BowserSlots = 0;
    }
    D_8010B8AC_E333C_BowserSlots = (D_8010B8AC_E333C_BowserSlots + 1) & 0x7FFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106B30_DE5C0_BowserSlots);
#endif

void func_801076EC_DF17C_BowserSlots(void) {
    if (D_8010C03C_E3ACC_BowserSlots->work[0] == 0) {
        D_8010C03C_E3ACC_BowserSlots->work[0] = 1;
    }
}

/* Symbol 1-5 -> its prize item (clamped). */
s32 func_8010770C_DF19C_BowserSlots(s32 symbol) {
    symbol--;
    if (symbol >= 5) {
        symbol = 4;
    }
    if (symbol < 0) {
        symbol = 0;
    }
    return (u16)D_8010C0CC_E3B5C_BowserSlots[symbol];
}

/* Builds the wobble weights of a model's vertices: (height / max height)^2 and the vertex's angle
   around the y axis (0-360). */
void func_80107740_DF1D0_BowserSlots(s32 model) {
    HmfData* hmf = BS_MODEL(model)->hmf;
    s32 n = hmf->unk18;
    s32 size = n * 8;
    HmfVtx* v;
    BSVtxWeight* w;
    f32 max;
    f32 t;
    s32 i;

    D_8010C0E4_E3B74_BowserSlots = func_80027154_27D54(size, hmf->unk0E + 1);
    func_800B0EF0_B1AF0(D_8010C0E4_E3B74_BowserSlots, 0, size);
    max = 0.0f;
    v = hmf->unk40;
    for (i = 0; i < n; i++, v++) {
        if (max < v->unk02) {
            max = v->unk02;
        }
    }
    w = D_8010C0E4_E3B74_BowserSlots;
    v = hmf->unk40;
    for (i = 0; i < n; i++, w++, v++) {
        t = v->unk02 / max;
        w->weight = t * t;
        w->angle = func_800B75A8_B81A8(v->unk00, -v->unk04);
        if (w->angle >= 360.0) {
            w->angle -= 360.0;
        } else if (w->angle < 0.0) {
            w->angle += 360.0;
        }
    }
}

/* Records the heights of two models (D_8010C0E8), then builds the first one's weights. */
void func_801078F0_DF380_BowserSlots(s32 model, s32 model2) {
    s32 models[2];
    HmfData* hmf;
    HmfVtx* v;
    s32 n;
    s32 i;
    s32 j;

    models[0] = model;
    models[1] = model2;
    for (i = 0; i < 2; i++) {
        hmf = BS_MODEL(models[i])->hmf;
        n = hmf->unk18;
        v = hmf->unk40;
        D_8010C0E8_E3B78_BowserSlots[i] = 0;
        for (j = 0; j < n; j++, v++) {
            if (D_8010C0E8_E3B78_BowserSlots[i] < v->unk02) {
                D_8010C0E8_E3B78_BowserSlots[i] = v->unk02;
            }
        }
    }
    func_80107740_DF1D0_BowserSlots(model);
}

/* Bends the model's current vertex frame toward direction `angle` by `amp`, squashing by `squash`. */
void func_801079B8_DF448_BowserSlots(s32 model, f32 angle, f32 amp, f32 squash) {
    BSVtxWeight* w = D_8010C0E4_E3B74_BowserSlots;
    f32 inv180 = 1.0f / 180.0f;
    HmfData* hmf = BS_MODEL(model)->hmf;
    s32 n = hmf->unk18;
    HmfVtx* v = hmf->unk44[D_800FDBE0_FE7E0];
    f32 d;
    s32 i;

    for (i = 0; i < n; i++, v++, w++) {
        v->unk00 += HuMathSin(angle) * amp * 100.0 * w->weight;
        v->unk04 += func_800B7890_B8490(angle) * amp * 100.0 * w->weight;
        d = 180.0 - func_8010B2FC_E2D8C_BowserSlots(angle, w->angle);
        if (d < 0.0) {
            d += 360.0;
        }
        if (d > 180.0) {
            d = 180.0f;
        }
        v->unk02 -= d * inv180 * w->weight * squash * 100.0;
    }
}

/* Moves model2 (the top part) onto the bent model, then bends the model. */
void func_80107BCC_DF65C_BowserSlots(s32 model, s32 model2, f32 angle, f32 amp, f32 squash) {
    HmfModel* m;
    HmfModel* top;
    f32 s;
    f32 c;

    if (model2 != -1) {
        m = BS_MODEL(model);
        top = BS_MODEL(model2);
        top->pos.x = m->pos.x;
        top->pos.y = m->pos.y;
        top->pos.z = m->pos.z;
        s = HuMathSin(angle) * amp;
        c = func_800B7890_B8490(angle) * amp;
        top->pos.x += s * 100.0 * m->scale.x;
        top->pos.z += c * 100.0 * m->scale.z;
        top->rot.x = c * 30.0;
        top->rot.z = -(s * 30.0);
        top->pos.y += ((D_8010C0E8_E3B78_BowserSlots[1] + squash * (D_8010C0E8_E3B78_BowserSlots[0] - D_8010C0E8_E3B78_BowserSlots[1])) + -80.0) * m->scale.y;
    }
    func_801079B8_DF448_BowserSlots(model, angle, amp, squash);
}

/* Builds a reel model (model file 0xC1) from the part `part` of `model`: a copy of the part's
   vertices per frame buffer with texture coordinates for one sprite frame per quad, and a display
   list drawing each quad with the frame of items[face], the face being the one the quad points to. */
s32 func_80107D68_DF7F8_BowserSlots(u16 model, u16 anim, char* part, u8* items) {
    s32 uv[4][2] = { { 1, 1 }, { 1, 0 }, { 0, 0 }, { 0, 1 } };
    f32 angles[16];
    HmfData* dst;
    HuSprite_Unk84_Struct* spr;
    Gfx* buf;
    Gfx* gfx;
    s32 idx;
    HmfData* hmf;
    s32 p;
    s32 n;
    HuSprite_Unk84_Unk00_Struct* frame;
    HmfVtx* to;
    HmfVtx* from;
    HmfMotionObj* obj;
    f32 sy;
    f32 sz;
    s32 size;
    s32 face;
    s32 sel;
    s32* t;
    s32 i;
    s32 j;

    spr = SprAnimGet(anim);
    buf = gfx = HuMemAlloc(0x10000);
    idx = func_80027FA4_28BA4(0xC1, buf, 4);
    dst = BS_MODEL(idx)->hmf;
    dst->unk64->unk50 |= 0x01000000;
    hmf = BS_MODEL(model)->hmf;
    p = func_80038398_38F98(hmf, part);
    n = hmf->unk64[p].unk0C;
    frame = &spr->unk00[*items];
    for (j = 0; j < D_800FDBCA_FE7CA; j++) {
        to = dst->unk44[j] = func_80027154_27D54(n * 16, dst->unk0E);
        from = &hmf->unk40[hmf->unk64[p].unk0A];
        sy = sz = 0.0f;
        for (i = 0; i < n; i++, to++) {
            *to = *from++;
            t = uv[i & 3];
            to->unk08 = (frame->unk04 * t[0]) << 6;
            to->unk0A = (frame->unk06 * t[1]) << 6;
            if (j == 0) {
                if ((i & 3) == 0) {
                    sy = sz = 0.0f;
                }
                sy += to->unk02;
                sz += to->unk04;
                if ((i & 3) == 3) {
                    angles[i >> 2] = func_800B75A8_B81A8(sz * 0.25, sy * 0.25);
                    if (angles[i >> 2] < 0.0) {
                        angles[i >> 2] += 360.0;
                    }
                }
            }
        }
    }
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010B9C0_E3450_BowserSlots));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_NOOP2);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, spr->unk0C);
    gDPPipeSync(gfx++);
    for (j = 0; j < n >> 2; j++) {
        sel = 0;
        for (face = 0; face < 8; face++) {
            if (func_8010B2FC_E2D8C_BowserSlots(angles[j], (7 - face) * 45.0) < 10.0) {
                sel = face;
                break;
            }
        }
        if ((u32)sel >= 8) {
            sel = 7;
        }
        if (items[sel] >= spr->unk10) {
            items[sel] = spr->unk10 - 1;
        }
        frame = &spr->unk00[items[sel]];
        gSPSegment(gfx++, 0x04, osVirtualToPhysical(frame->unk00));
        gDPLoadTextureBlock(gfx++, 0x04000000, G_IM_FMT_CI, G_IM_SIZ_8b, frame->unk04, frame->unk06, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x01, osVirtualToPhysical(&dst->unk44[0][j * 4]));
        gSPVertex(gfx++, 0x01000000, 4, 0);
        gSP2Triangles(gfx++, 0, 2, 1, 0, 0, 3, 2, 0);
    }
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    dst->unk3C->unk00[0] = func_80027154_27D54(size, dst->unk0E);
    bcopy(buf, dst->unk3C->unk00[0], size);
    HuMemFree(buf);
    obj = func_8002A9F4_2B5F4(model, part);
    func_800B37C0_B43C0(BS_MODEL(model)->mtx);
    BS_MODEL(idx)->mtx[12] = obj->unk58[3][0];
    BS_MODEL(idx)->mtx[13] = obj->unk58[3][1];
    BS_MODEL(idx)->mtx[14] = obj->unk58[3][2];
    return (u16)idx;
}

/* A flat model (file 0x4C1) drawing the sprite animation's frames, one quad per frame, alpha
   `alpha` (MP3 motor_rooter's func_8010E888). */
s32 func_8010879C_E022C_BowserSlots(HuSprite_Unk84_Struct* spr, f32 alpha) {
    HmfData* hmf;
    Gfx* buf;
    Gfx* gfx;
    u32 count;
    s32 size;
    s32 tlutSize;
    s32 idx;
    s32 i;

    buf = gfx = HuMemAlloc(0x10000);
    idx = func_80027FA4_28BA4(0x4C1, buf, 4);
    hmf = BS_MODEL(idx)->hmf;
    hmf->unk64->unk50 |= 0x01010000;
    count = func_80109C5C_E16EC_BowserSlots(spr, hmf, 1.0f, 0, 0x64);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010B9C0_E3450_BowserSlots));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, alpha * 255.0f);
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    if (spr->unk1A >= 2) {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        tlutSize = 0x800;
        if (spr->unk18 == 4) {
            gDPLoadTLUT_pal16(gfx++, 0, spr->unk0C);
        } else {
            gDPLoadTLUT_pal256(gfx++, spr->unk0C);
        }
    } else {
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        tlutSize = 0x1000;
    }
    gDPPipeSync(gfx++);
    for (i = 0; i < count; i++) {
        gSPSegment(gfx++, 0x04, osVirtualToPhysical((u8*)spr->unk08 + tlutSize * i));
        gDPLoadTextureBlock(gfx++, 0x04000000, G_IM_FMT_CI, G_IM_SIZ_8b, spr->unk00->unk04, spr->unk00->unk06 / count, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x01, osVirtualToPhysical(&hmf->unk44[0][i * 4]));
        gSPVertex(gfx++, 0x01000000, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    }
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    hmf->unk3C->unk00[0] = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk00[0], size);
    HuMemFree(buf);
    return idx;
}

/* A flat model (file 0x4C1) showing one sprite frame, with one display list per vertex buffer
   (MP3 motor_rooter's func_8010EFF8). */
s32 func_80108EE4_E0974_BowserSlots(HuSprite_Unk84_Struct* spr, f32 alpha) {
    HmfData* hmf;
    Gfx* buf;
    Gfx* gfx;
    s32 size;
    s32 idx;
    s32 fmt;
    s32 i;

    buf = gfx = HuMemAlloc(0x10000);
    idx = func_80027FA4_28BA4(0x4C1, buf, 4);
    hmf = BS_MODEL(idx)->hmf;
    hmf->unk64->unk50 |= 0x01010000;
    HuMemFree(hmf->unk3C);
    hmf->unk3C = func_80027154_27D54(0x14, D_800FA1AA_FADAA);
    func_80109C5C_E16EC_BowserSlots(spr, hmf, 1.0f, 0, 0x1E);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010B9C0_E3450_BowserSlots));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (spr->unk1A >= 2) {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, alpha * 255.0f);
    } else {
        if (spr->unk18 & 0x8000) {
            gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        } else {
            gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        }
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, alpha * 255.0f);
    }
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    if (spr->unk1A >= 2) {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        if (spr->unk18 == 4) {
            gDPLoadTLUT_pal16(gfx++, 0, spr->unk0C);
        } else {
            gDPLoadTLUT_pal256(gfx++, spr->unk0C);
        }
        gDPPipeSync(gfx++);
        fmt = 2;
    } else {
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPPipeSync(gfx++);
        fmt = (spr->unk18 & 0x8000) ? 4 : 0;
    }
    switch (spr->unk18 & 0xFFF) {
        case 4:
            gDPLoadTextureBlock_4b(gfx++, 0x04000000, fmt, spr->unk00->unk04, spr->unk00->unk06, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 8:
            gDPLoadTextureBlock(gfx++, 0x04000000, fmt, G_IM_SIZ_8b, spr->unk00->unk04, spr->unk00->unk06, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 16:
            gDPLoadTextureBlock(gfx++, 0x04000000, fmt, G_IM_SIZ_16b, spr->unk00->unk04, spr->unk00->unk06, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            break;
    }
    gDPPipeSync(gfx++);
    gSPSegment(gfx++, 0x01, osVirtualToPhysical(hmf->unk44[0]));
    gSPVertex(gfx++, 0x01000000, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    hmf->unk3C->unk00[0] = hmf->unk3C->unk10 = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk00[0], size);
    HuMemFree(buf);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = hmf->unk3C->unk00[i + 1] = func_80027154_27D54(0x100, hmf->unk0E);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x04, osVirtualToPhysical(spr->unk00->unk00));
        gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk10));
        gSPEndDisplayList(gfx++);
    }
    hmf->unk3C->unk00[0] = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    return idx;
}

/* Points the model's current list at its per-buffer list showing sprite frame `frame`
   (MP3 motor_rooter's func_801107FC). */
void func_80109AF8_E1588_BowserSlots(u16 model, HuSprite_Unk84_Struct* spr, u16 frame) {
    HmfModel* m = BS_MODEL(model);
    HmfData* hmf = m->hmf;
    Gfx* gfx = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];

    hmf->unk3C->unk00[0] = gfx;
    gDPPipeSync(&gfx[0]);
    gSPSegment(&gfx[1], 0x04, osVirtualToPhysical(spr->unk00[frame].unk00));
    gSPDisplayList(&gfx[2], osVirtualToPhysical(hmf->unk3C->unk10));
    gDPPipeSync(&gfx[3]);
    gSPEndDisplayList(&gfx[4]);
}

/* Makes `model` (a new flat model if -1) draw `src`'s current list. */
s32 func_80109BC8_E1658_BowserSlots(s32 model, s32 src) {
    HmfData* dst;
    HmfData* from;

    if (model == -1) {
        model = func_80027FA4_28BA4(0x4C1, NULL, 4);
    }
    dst = BS_MODEL(model)->hmf;
    from = BS_MODEL(src)->hmf;
    dst->unk64->unk50 = from->unk64->unk50;
    dst->unk3C->unk00[0] = from->unk3C->unk00[0];
    return model;
}

/* Builds the vertex buffers of a flat sprite model: the frame strip cut into `count` quads that
   fit texture memory, 100/32 units per texel times scale, centred, offset by (x, y); returns the quad count (MP3 motor_rooter's
   func_80110A00). */
s32 func_80109C5C_E16EC_BowserSlots(HuSprite_Unk84_Struct* spr, HmfData* hmf, f32 scale, u16 x, u16 y) {
    Vtx* buf;
    Vtx* v;
    Vtx_t* to;
    Vtx_t* from;
    s32 tmem;
    s32 bpp;
    s32 w;
    s32 h;
    s32 sw;
    s32 sh;
    s32 size;
    s32 count;
    s32 qh;
    s32 qsh;
    s32 n;
    s32 i;
    s32 j;

    if (spr->unk1A >= 2) {
        tmem = 0x800;
    } else {
        tmem = 0x1000;
    }
    w = spr->unk00->unk04;
    h = spr->unk00->unk06;
    sw = w * 100.0 * scale / 32.0;
    sh = h * 100.0 * scale / 32.0;
    bpp = spr->unk18 & 0x7FFF;
    if ((spr->unk18 & 0xFFF) == 4) {
        size = ((w + 1) & 0xFFFE) * h * bpp;
    } else {
        size = w * h * spr->unk18;
    }
    size = (size < 0) ? (size + 7) : size;
    size >>= 3;
    count = size / tmem;
    if (count <= 0) {
        count = 1;
    }
    qh = h / count;
    qsh = sh / count;
    n = count * 4;
    buf = v = HuMemMemoryAllocPerm(n * sizeof(Vtx));
    func_800B0EF0_B1AF0(buf, 0, n * sizeof(Vtx));
    for (i = 0; i < count; i++, v += 4) {
        v[0].v.ob[0] = (s32)(sw * 0.5);
        v[0].v.ob[1] = (s32)(sh * 0.5 - qsh * i);
        v[0].v.tc[0] = (w - 1) * 64;
        v[0].v.tc[1] = 0;
        v[1].v.ob[0] = (s32)(sw * 0.5);
        v[1].v.ob[1] = (s32)(sh * 0.5 - qsh * (i + 1));
        v[1].v.tc[0] = (w - 1) * 64;
        v[1].v.tc[1] = (qh - 1) * 64;
        v[2].v.ob[0] = (s32) - (sw * 0.5);
        v[2].v.ob[1] = (s32)(sh * 0.5 - qsh * i);
        v[2].v.tc[0] = 0;
        v[2].v.tc[1] = 0;
        v[3].v.ob[0] = (s32) - (sw * 0.5);
        v[3].v.ob[1] = (s32)(sh * 0.5 - qsh * (i + 1));
        v[3].v.tc[0] = 0;
        v[3].v.tc[1] = (qh - 1) * 64;
        for (j = 0; j < 4; j++) {
            v[j].v.ob[0] += x;
            v[j].v.ob[1] += y;
            v[j].v.ob[2] = 0;
            v[j].v.flag = 0;
            v[j].v.cn[3] = 0xFF;
            v[j].v.cn[0] = v[j].v.cn[1] = v[j].v.cn[2] = 0;
        }
    }
    v = buf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        hmf->unk44[i] = func_80027154_27D54(n * sizeof(Vtx), hmf->unk0E);
        to = (Vtx_t*)hmf->unk44[i];
        from = &v->v;
        for (j = 0; j < n; j++) {
            *(to++) = *(from++);
        }
    }
    HuMemMemoryFreePerm(buf);
    return count;
}

/* Loads a sprite animation from a file (MP1 KnockBlockTower's func_800FB20C). */
s32 func_8010A074_E1B04_BowserSlots(s32 file) {
    void* data;
    s16 anim;

    data = DataRead(file);
    anim = SprAnimRead(data);
    DataClose(data);
    return (u16)anim;
}

/* Clears the model list (D_8010C170). */
void func_8010A0B8_E1B48_BowserSlots(void) {
    BSModelSlot* slot = D_8010C170_E3C00_BowserSlots;
    s32 i;

    for (i = 0; i < 64; i++, slot++) {
        slot->model = -1;
        slot->group = -1;
        slot->attr = 0;
    }
}

/* Adds a model to the list with its group and the attribute (-1: 0) func_8010A138 applies. */
void func_8010A0EC_E1B7C_BowserSlots(s32 model, s32 group, s32 attr) {
    BSModelSlot* slot = D_8010C170_E3C00_BowserSlots;
    s32 i;

    for (i = 0; i < 64; i++, slot++) {
        if (slot->model == -1) {
            slot->model = model;
            slot->group = group;
            if (attr == -1) {
                slot->attr = 0;
            } else {
                slot->attr = attr;
            }
            return;
        }
    }
}

/* Applies attr (-1: each model's own) to the listed models of `group` (-1: every group). */
void func_8010A138_E1BC8_BowserSlots(s32 group, s32 attr) {
    BSModelSlot* slot = D_8010C170_E3C00_BowserSlots;
    s32 i;

    for (i = 0; i < 64; i++, slot++) {
        if (slot->model == -1) {
            continue;
        }
        if (slot->group == -1) {
            continue;
        }
        if ((slot->group != group) & (group != -1)) {
            continue;
        }
        if (attr == -1) {
            func_80029F2C_2AB2C((s16)slot->model, slot->attr);
        } else {
            func_80029F2C_2AB2C((s16)slot->model, attr);
        }
    }
}

/* Sets up the six effect sprites (MP1 SlotMachine's func_800FD248). */
void func_8010A1F4_E1C84_BowserSlots(void) {
    void* data;
    BSFx* fx;
    s32 i;

    data = DataRead(0x11000E);
    D_8010C178_E3C08_BowserSlots = SprAnimRead(data);
    DataClose(data);
    D_8010C17A_E3C0A_BowserSlots = SprCreate(6, 0);
    for (fx = D_8010C174_E3C04_BowserSlots, i = 0; i < 6; fx++, i++) {
        fx->unk_02 = fx->unk_01 = fx->unk_03 = fx->unk_00 = 0;
        fx->unk_04 = fx->unk_08 = fx->unk_0C = 0.0f;
        fx->unk_10 = fx->unk_14 = 0.0f;
        fx->unk_18 = fx->unk_1C = 1.0f;
        fx->unk_20 = 0.0f;
        fx->unk_24 = 1.0f;
        fx->unk_28 = fx->unk_2C = fx->unk_30 = fx->unk_34 = 0.0f;
        fx->unk_3A = fx->unk_3C = fx->unk_38 = 0;
        fx->unk_3E = fx->unk_40 = fx->unk_42 = fx->unk_44 = 0;
        SprAnimSet(D_8010C17A_E3C0A_BowserSlots, i, D_8010C178_E3C08_BowserSlots, 0);
        SprPosSet(D_8010C17A_E3C0A_BowserSlots, i, 160, 120);
        SprScaleSet(D_8010C17A_E3C0A_BowserSlots, i, 1.0f, 1.0f);
        func_80082488_83088(D_8010C17A_E3C0A_BowserSlots, i, 0x100);
        SprAttrSet(D_8010C17A_E3C0A_BowserSlots, i, 0x9008);
        func_8008225C_82E5C(D_8010C17A_E3C0A_BowserSlots, i, 0);
    }
    D_8010C17C_E3C0C_BowserSlots = D_8010C17E_E3C0E_BowserSlots;
    D_8010C182_E3C12_BowserSlots = D_8010C186_E3C16_BowserSlots = -1;
    D_8010C184_E3C14_BowserSlots = D_8010C188_E3C18_BowserSlots = 0;
    D_8010C18C_E3C1C_BowserSlots = 0;
    D_8010C18A_E3C1A_BowserSlots = -1;
}

/* Draws the visible effect sprites (MP1 SlotMachine's func_800FD420). */
void func_8010A3CC_E1E5C_BowserSlots(void) {
    BSFx* fx;
    s32 i;

    for (fx = D_8010C174_E3C04_BowserSlots, i = 0; i < 6; fx++, i++) {
        if ((fx->unk_00 & 0xC0) == 0xC0) {
            SprAttrReset(D_8010C17A_E3C0A_BowserSlots, i, 0x8000);
            SprBankSet(D_8010C17A_E3C0A_BowserSlots, i, fx->unk_03);
            SprPosSet(D_8010C17A_E3C0A_BowserSlots, i, fx->unk_10 + 160.0f, fx->unk_14 + 120.0f);
            SprScaleSet(D_8010C17A_E3C0A_BowserSlots, i, fx->unk_18, fx->unk_1C);
            func_80082488_83088(D_8010C17A_E3C0A_BowserSlots, i, (s32)(fx->unk_24 * 256.0f));
            SprRotSet(D_8010C17A_E3C0A_BowserSlots, i, fx->unk_20);
        } else {
            SprAttrSet(D_8010C17A_E3C0A_BowserSlots, i, 0x8000);
        }
    }
}

/* Runs the effect sprites over the reels (MP1 SlotMachine's func_800FD590): a burst when a symbol
   is won or matched, sprites flying from the screen edge to the reels, then pulsing until the
   machine stops showing them. */
/* NON_MATCHING: GCC hoists the 0.8f constant out of the sprite loop into f28 (retail reloads it at
   each use), which grows the frame by 8; the rest is register choice (`done`, i % 3). As in MP1's
   func_800FD590 (NON_MATCHING there too). */
#ifdef NON_MATCHING
void func_8010A53C_E1FCC_BowserSlots(void) {
    f32 pos[3][2];
    BSFx* fx;
    s32 i;
    s32 burst;
    s32 done;
    s32 b;
    BSFx* e;
    s32 k;
    s16 sym;
    s16 kind;
    u8 frame;
    f32 a;

    func_8010B43C_E2ECC_BowserSlots(0, &D_8010BA00_E3490_BowserSlots, pos[0]);
    func_8010B43C_E2ECC_BowserSlots(0, &D_8010BA0C_E349C_BowserSlots, pos[1]);
    func_8010B43C_E2ECC_BowserSlots(0, &D_8010BA18_E34A8_BowserSlots, pos[2]);
    burst = 0;
    if (D_8010C17E_E3C0E_BowserSlots != D_8010C17C_E3C0C_BowserSlots) {
        D_8010C17C_E3C0C_BowserSlots = D_8010C17E_E3C0E_BowserSlots;
        switch (D_8010C17E_E3C0E_BowserSlots) {
            case 3:
                D_8010C18C_E3C1C_BowserSlots = 0;
                break;
            case 1:
            case 2:
                D_8010C184_E3C14_BowserSlots = 0;
                break;
            case 0:
                if (D_8010C180_E3C10_BowserSlots < 0) {
                    D_8010C18C_E3C1C_BowserSlots = -1;
                } else {
                    if (D_8010C184_E3C14_BowserSlots == 0) {
                        D_8010C182_E3C12_BowserSlots = D_8010C180_E3C10_BowserSlots;
                    }
                    D_8010C186_E3C16_BowserSlots = D_8010C180_E3C10_BowserSlots;
                    D_8010C188_E3C18_BowserSlots = 20;
                }
                break;
        }
    }
    if (D_8010C182_E3C12_BowserSlots >= 0 && D_8010C184_E3C14_BowserSlots == 0) {
        sym = D_8010C182_E3C12_BowserSlots;
        kind = D_8010BA24_E34B4_BowserSlots[sym].unk_00;
        frame = D_8010BA24_E34B4_BowserSlots[sym].unk_03;
        for (fx = D_8010C174_E3C04_BowserSlots, i = 0; i < D_8010BA50_E34E0_BowserSlots[kind].unk_00; fx++, i++) {
            k = i % 3;
            fx->unk_00 = 0xC0;
            fx->unk_01 = kind;
            fx->unk_03 = frame;
            fx->unk_02 = 0;
            fx->unk_38 = sym;
            if (D_8010BA60_E34F0_BowserSlots[kind][0][0] == 0x7F) {
                fx->unk_28 = fx->unk_10 = pos[k][0];
                fx->unk_2C = fx->unk_14 = pos[k][1];
            } else {
                fx->unk_28 = fx->unk_10 = (D_8010BA60_E34F0_BowserSlots + kind)[0][k][0] * 10.0;
                fx->unk_2C = fx->unk_14 = (D_8010BA60_E34F0_BowserSlots + kind)[0][k][1] * 10.0;
            }
            fx->unk_24 = D_8010BA50_E34E0_BowserSlots[kind].unk_01 * 0.1;
            fx->unk_30 = fx->unk_18 = D_8010BA50_E34E0_BowserSlots[kind].unk_02 * 0.1;
            fx->unk_34 = fx->unk_1C = D_8010BA50_E34E0_BowserSlots[kind].unk_03 * 0.1;
            fx->unk_20 = 0.0f;
            fx->unk_3A = fx->unk_3C = 0;
            fx->unk_3E = fx->unk_40 = fx->unk_42 = fx->unk_44 = 0;
        }
        for (; i < 6; i++) {
            D_8010C174_E3C04_BowserSlots[i].unk_00 = 0;
        }
        burst = 1;
        D_8010C18A_E3C1A_BowserSlots = -1;
        D_8010C184_E3C14_BowserSlots = burst;
        func_80079798_7A398(0x129, 2);
    } else if (D_8010C188_E3C18_BowserSlots != 0) {
        for (i = 0; i < 3; i++) {
            if (D_8010C174_E3C04_BowserSlots[i].unk_02 != 1) {
                break;
            }
        }
        if (i >= 3 && --D_8010C188_E3C18_BowserSlots == 0) {
            if (D_8010C18A_E3C1A_BowserSlots & 0x1F) {
                D_8010C188_E3C18_BowserSlots++;
            } else {
                for (fx = D_8010C174_E3C04_BowserSlots, i = 0; i < 3; fx++, i++) {
                    fx->unk_02 = 2;
                    fx->unk_3A = fx->unk_3C = 0;
                }
                for (; i < 6; i++) {
                    D_8010C174_E3C04_BowserSlots[i].unk_00 = 0;
                }
                D_8010C186_E3C16_BowserSlots = -1;
            }
        }
    }
    if (D_8010C18A_E3C1A_BowserSlots >= 0) {
        D_8010C18A_E3C1A_BowserSlots = (D_8010C18A_E3C1A_BowserSlots + 1) & 0x7FFF;
    }
    b = burst;
    fx = D_8010C174_E3C04_BowserSlots;
    for (i = 0; i < 6; i++) {
        e = &fx[i];
        if (e->unk_00 == 0) {
            continue;
        }
        e->unk_3A++;
        if (e->unk_02 == 0) {
            done = 0;
            if (i % 3 == 2 && D_8010C18C_E3C1C_BowserSlots < 0) {
                e->unk_00 = 0;
            }
            if ((e->unk_40 == 0 || e->unk_3E != 0) && D_8010C18C_E3C1C_BowserSlots < 0) {
                e->unk_00 = 0;
                continue;
            }
            if (!b) {
                if (e->unk_40 == 0) {
                    if (D_8010C0D0_E3B60_BowserSlots[i % 3].state == 0 || D_8010C0D0_E3B60_BowserSlots[i % 3].state == 6) {
                        e->unk_40++;
                    }
                    continue;
                }
                if (e->unk_3E != 0) {
                    e->unk_3E--;
                    continue;
                }
                a = e->unk_24 + 0.1;
                if (a >= 1.0) {
                    a = 1.0f;
                    e->unk_3C++;
                    done = 1;
                }
                e->unk_24 = a;
            }
            a = e->unk_24;
            switch (e->unk_01) {
                case 0:
                case 1:
                    if (b) {
                        if (i >= 3) {
                            e->unk_3E = 5;
                        } else {
                            e->unk_3E = 0;
                        }
                        continue;
                    }
                    e->unk_10 = (pos[i % 3][0] - e->unk_28) * a + e->unk_28;
                    e->unk_14 = (pos[i % 3][1] - e->unk_2C) * a + e->unk_2C;
                case 2:
                case 3:
                    e->unk_18 = e->unk_30 + (1.0 - e->unk_30) * a;
                    e->unk_1C = e->unk_34 + (1.0 - e->unk_34) * a;
                    break;
            }
            if (done) {
                e->unk_02 = 1;
                if (i < 3) {
                    e->unk_01 = D_8010BA24_E34B4_BowserSlots[e->unk_38].unk_01;
                } else {
                    e->unk_01 = 0;
                }
                if (D_8010C18A_E3C1A_BowserSlots < 0) {
                    D_8010C18A_E3C1A_BowserSlots = 0;
                }
                e->unk_3A = D_8010C18A_E3C1A_BowserSlots;
                e->unk_3C = 0;
            }
        } else if (e->unk_02 == 1) {
            if (e->unk_3C == 0) {
                e->unk_24 = 0.8f;
                e->unk_3C++;
                e->unk_18 = e->unk_1C = 1.0f;
            }
            switch (e->unk_01) {
                case 0:
                    e->unk_24 = (f32)(D_8010C18A_E3C1A_BowserSlots & 0xF) / 16.0 * 0.6 + 0.2;
                    e->unk_20 = HuMathSin((D_8010C18A_E3C1A_BowserSlots & 0x1F) * 360.0 / 32.0) * 15.0;
                    break;
                case 1:
                    e->unk_18 = e->unk_1C = HuMathSin((D_8010C18A_E3C1A_BowserSlots & 0xF) * 90.0 / 16.0) * 0.6 + 1.0;
                    e->unk_24 = (1.0 - (f32)(D_8010C18A_E3C1A_BowserSlots & 0xF) / 16.0) * 0.8;
                    e->unk_20 = HuMathSin((D_8010C18A_E3C1A_BowserSlots & 0x1F) * 360.0 / 32.0) * 15.0;
                    break;
                case 2:
                    e->unk_20 = HuMathSin((D_8010C18A_E3C1A_BowserSlots & 0xF) * 360.0 / 16.0) * 30.0;
                    break;
                case 4:
                    e->unk_20 = HuMathSin((D_8010C18A_E3C1A_BowserSlots & 0x1F) * 360.0 / 32.0) * 30.0;
                case 3:
                    e->unk_1C = (func_800B7890_B8490((D_8010C18A_E3C1A_BowserSlots & 0xF) * 360.0 / 16.0 - 90.0) + 1.0) * 0.15 + 1.0;
                    break;
            }
            if (D_8010C18C_E3C1C_BowserSlots < 0 && i % 3 != 2) {
                e->unk_02 = 3;
                e->unk_3C = 0;
            }
        } else if (e->unk_02 == 2) {
            if (e->unk_3C == 0) {
                if (i >= 3) {
                    e->unk_00 = 0;
                }
                e->unk_3C++;
                e->unk_24 = 0.8f;
                e->unk_18 = e->unk_1C = 1.0f;
                e->unk_20 = 0.0f;
                e->unk_28 = e->unk_2C = 1.0f;
                e->unk_3A = 0;
            }
            if (e->unk_3A >= i * 2) {
                e->unk_18 = e->unk_1C = e->unk_2C;
                e->unk_2C += 0.2;
                e->unk_24 = e->unk_28 * 0.8;
                if ((e->unk_28 -= 0.1) <= 0.0f) {
                    e->unk_00 = 0;
                }
            }
        } else if (e->unk_02 == 3) {
            if (e->unk_3C == 0) {
                if (i >= 3) {
                    e->unk_00 = 0;
                }
                e->unk_3C++;
                e->unk_24 = 0.8f;
                e->unk_18 = e->unk_1C = 1.0f;
                e->unk_20 = 0.0f;
                e->unk_28 = 1.0f;
            }
            e->unk_24 = e->unk_28 * 0.8;
            e->unk_1C = e->unk_28;
            if ((e->unk_28 -= 0.2) <= 0.0f) {
                e->unk_00 = 0;
            }
        }
    }
    func_8010A3CC_E1E5C_BowserSlots();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A53C_E1FCC_BowserSlots);
#endif

/* Rebuilds a motion object's matrix from its rotation and scale, keeping its translation
   (MP1 SlotMachine's func_800FC9A8). */
void func_8010B148_E2BD8_BowserSlots(HmfMotionObj* part) {
    f32 x = part->unk58[3][0];
    f32 y = part->unk58[3][1];
    f32 z = part->unk58[3][2];

    func_800B37C0_B43C0(part->unk58);
    part->unk58[3][0] = x;
    part->unk58[3][1] = y;
    part->unk58[3][2] = z;
    func_80025884_26484(part->unk58, part->unk34.x, part->unk34.y, part->unk34.z);
    func_80025830_26430(part->unk58, part->unk40.x, part->unk40.y, part->unk40.z);
}

/* Wraps each angle of `rot` into 0-360 (one step). */
void func_8010B1D4_E2C64_BowserSlots(Vec* rot) {
    if (rot->x >= 360.0) {
        rot->x -= 360.0;
    } else if (rot->x < 0.0) {
        rot->x += 360.0;
    }
    if (rot->y >= 360.0) {
        rot->y -= 360.0;
    } else if (rot->y < 0.0) {
        rot->y += 360.0;
    }
    if (rot->z >= 360.0) {
        rot->z -= 360.0;
    } else if (rot->z < 0.0) {
        rot->z += 360.0;
    }
}

/* The angle between two angles (0-180). */
f32 func_8010B2FC_E2D8C_BowserSlots(f32 a, f32 b) {
    f32 d = b - a;

    if (d >= 360.0) {
        d -= 360.0;
    } else if (d < 0.0) {
        d += 360.0;
    }
    if (d >= 180.0) {
        d = 360.0 - d;
    }
    return d;
}

/* A random symbol 1-5 by main's chance table (D_800CAFE4, percent per item). */
s32 func_8010B38C_E2E1C_BowserSlots(void) {
    s16 i;
    s16 sum;
    u8 r;

    r = rand8() % 100;
    i = 0;
    sum = 0;
    for (; i < 4; i++) {
        sum += D_800CAFE4[i];
        if (r < sum) {
            break;
        }
    }
    return i + 1;
}

/* Projects a world position to screen offsets from the centre for camera `camera`
   (MP1 SlotMachine's func_800FCA34). */
void func_8010B43C_E2ECC_BowserSlots(s16 camera, Vec* pos, f32* out) {
    f32 v[3];
    Matrix4f mtx;
    HuCamera* cam;
    f32 t;
    f32 d;

    cam = &D_800C9B80_CA780[camera];
    func_800B1960_B2560(mtx, cam->pos.x, cam->pos.y, cam->pos.z, cam->at.x, cam->at.y, cam->at.z, cam->up.x,
                        cam->up.y, cam->up.z);
    func_8010B60C_E309C_BowserSlots(mtx, pos->x, pos->y, pos->z, v);
    t = HuMathSin(cam->fov[0] * 0.5);
    t /= func_800B7890_B8490(cam->fov[0] * 0.5);
    d = t * v[2];
    if (d < 0.0f) {
        d = -d;
    }
    out[0] = cam->viewports[D_800FFFD6_100BD6].vp.vscale[0] / 4.0 * v[0] / d * 0.75;
    out[1] = cam->viewports[D_800FFFD6_100BD6].vp.vscale[1] / 4.0 * -v[1] / d;
}

/* out = (x, y, z) * m (MP1 SlotMachine's func_800FCBFC). */
void func_8010B60C_E309C_BowserSlots(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
