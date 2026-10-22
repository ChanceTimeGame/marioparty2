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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104914_DC3A4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104BAC_DC63C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104DDC_DC86C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105034_DCAC4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105088_DCB18_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801054E8_DCF78_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105568_DCFF8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105AE4_DD574_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105C28_DD6B8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105D5C_DD7EC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106084_DDB14_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801060A4_DDB34_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801060F0_DDB80_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106110_DDBA0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106148_DDBD8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106254_DDCE4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801063CC_DDE5C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010648C_DDF1C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106524_DDFB4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801065D8_DE068_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106638_DE0C8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106750_DE1E0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801067A4_DE234_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801067DC_DE26C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106820_DE2B0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106B30_DE5C0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801076EC_DF17C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010770C_DF19C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107740_DF1D0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801078F0_DF380_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801079B8_DF448_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107BCC_DF65C_BowserSlots);

__asm__(".section .rodata");
const u32 D_8010BE08_E3898_BowserSlots[8] = { 0x00000001, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107D68_DF7F8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010879C_E022C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80108EE4_E0974_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109AF8_E1588_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109BC8_E1658_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109C5C_E16EC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A074_E1B04_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A0B8_E1B48_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A0EC_E1B7C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A138_E1BC8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A1F4_E1C84_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A3CC_E1E5C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A53C_E1FCC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B148_E2BD8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B1D4_E2C64_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B2FC_E2D8C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B38C_E2E1C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B43C_E2ECC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B60C_E309C_BowserSlots);
