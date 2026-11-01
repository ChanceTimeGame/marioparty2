#include "ovl_35.h"

void func_80102800_2677B0_LooneyLumberjacks(void) {
    s32 i;
    u8 cam;

    func_8002D4D0_2E0D0(50);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80020D20_21920(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, -56.0f, 50.0f, 56.0f);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 45.0f, 500.0f, 4000.0f);
    func_80104410_2693C0_LooneyLumberjacks();
    func_80103120_2680D0_LooneyLumberjacks();
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FA606_FB206 = 0;
    D_8010AFAC_26FF5C_LooneyLumberjacks = 0;
    D_8010AFAE_26FF5E_LooneyLumberjacks = 0;
    D_8010AF98_26FF48_LooneyLumberjacks = 0;
    D_8010AF9A_26FF4A_LooneyLumberjacks = 1829;
    D_8010AF9C_26FF4C_LooneyLumberjacks = 0;
    D_8010AF9E_26FF4E_LooneyLumberjacks = 0;
    D_8010AFA0_26FF50_LooneyLumberjacks = 0.0f;
    D_8010AF38_26FEE8_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLPlayer) * 4);
    D_8010AF3C_26FEEC_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLTeam) * 2);
    D_8010AF40_26FEF0_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLTree) * 2);
    D_8010AF44_26FEF4_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLFx) * 8);
    D_8010AF48_26FEF8_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLColor) * 13);
    D_8010AF4C_26FEFC_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(0x20);
    D_8010AF50_26FF00_LooneyLumberjacks = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(s16) * 4);
    for (i = 0; i < 4; i++) {
        D_8010AF50_26FF00_LooneyLumberjacks[i] = -1;
    }
    D_8010AF30_26FEE0_LooneyLumberjacks = omAddObj(0x40, 0, 0, -1, func_80102A68_267A18_LooneyLumberjacks);
}

__asm__(".section .rodata");
const char D_8010AA60_26FA10_LooneyLumberjacks[] = "\202r\202s\202`\202q\202s";

__asm__(".section .rodata");
const char D_8010AA6C_26FA1C_LooneyLumberjacks[20] = "\202e\202h\202m\202h\202r\202g";

void func_80102A68_267A18_LooneyLumberjacks(omObjData* obj) {
    obj->func_ptr = func_80102AF4_267AA4_LooneyLumberjacks;
    func_80104A40_2699F0_LooneyLumberjacks();
    func_8010730C_26C2BC_LooneyLumberjacks();
    func_80106C0C_26BBBC_LooneyLumberjacks();
    func_80104C48_269BF8_LooneyLumberjacks();
    func_80107C8C_26CC3C_LooneyLumberjacks();
    func_80107D94_26CD44_LooneyLumberjacks();
    func_801082E8_26D298_LooneyLumberjacks();
    if (_CheckFlag(0xC) != 0) {
        D_8010AFAC_26FF5C_LooneyLumberjacks = 1;
    }
    func_8007273C_7333C((const u8*)D_8010AA60_26FA10_LooneyLumberjacks, 1);
    func_8007273C_7333C((const u8*)D_8010AA6C_26FA1C_LooneyLumberjacks, 1);
}

void func_80102AF4_267AA4_LooneyLumberjacks(omObjData* obj) {
    LLTeam* w;
    LLTeam* l;
    s32 i;
    s32 a;
    s32 b;

    func_80103078_268028_LooneyLumberjacks(obj);
    switch (D_8010AF98_26FF48_LooneyLumberjacks) {
        case 0:
            if (func_8008F618_90218() == 0) {
                func_800691FC_69DFC(0);
                D_8010AF98_26FF48_LooneyLumberjacks = 1;
                PlayMusic(0x2B);
            }
            break;
        case 1:
            if (func_80069538_6A138() == 0) {
                func_800691FC_69DFC(10, (s16)(D_8010AF9A_26FF4A_LooneyLumberjacks / 30), 0xA0, 0x20);
                D_8010AF98_26FF48_LooneyLumberjacks = 2;
            }
            break;
        case 2:
            func_8006D4D0_6E0D0(D_8010AF9A_26FF4A_LooneyLumberjacks / 30);
            D_8010AF9A_26FF4A_LooneyLumberjacks--;
            if (D_8010AF9A_26FF4A_LooneyLumberjacks < 30 && D_8010AF9E_26FF4E_LooneyLumberjacks == 0) {
                func_8006D4D0_6E0D0(0);
                func_8006D518_6E118();
                D_8010AF9C_26FF4C_LooneyLumberjacks = 1;
                D_8010AF98_26FF48_LooneyLumberjacks = 3;
            }
            break;
        case 3:
            if (D_8010AF9C_26FF4C_LooneyLumberjacks == 0) {
                func_8006D518_6E118();
            }
            if (D_8010AF9E_26FF4E_LooneyLumberjacks == 0 && D_8010AFAC_26FF5C_LooneyLumberjacks == 0) {
                a = (s16)func_80107ADC_26CA8C_LooneyLumberjacks(D_8010AF3C_26FEEC_LooneyLumberjacks[0].tree, 0.0f);
                b = (s16)func_80107ADC_26CA8C_LooneyLumberjacks(D_8010AF3C_26FEEC_LooneyLumberjacks[1].tree, 0.0f);
                if (b < a) {
                    D_8010AF9E_26FF4E_LooneyLumberjacks = 1;
                } else if (a < b) {
                    D_8010AF9E_26FF4E_LooneyLumberjacks = 2;
                }
            }
            if (D_8010AF9E_26FF4E_LooneyLumberjacks != 0) {
                if (D_8010AF9E_26FF4E_LooneyLumberjacks == 1) {
                    w = &D_8010AF3C_26FEEC_LooneyLumberjacks[0];
                } else {
                    w = &D_8010AF3C_26FEEC_LooneyLumberjacks[1];
                }
                gPlayers[w->player[0]].coins_mg_bonus += 10;
                gPlayers[w->player[1]].coins_mg_bonus += 10;
            }
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(45);
            if (D_8010AFAC_26FF5C_LooneyLumberjacks == 0) {
                D_8010AF98_26FF48_LooneyLumberjacks = 4;
            } else {
                D_8010AF98_26FF48_LooneyLumberjacks = 6;
                D_8010AF9A_26FF4A_LooneyLumberjacks = 60;
            }
            break;
        case 4:
            if (func_80069538_6A138() == 0) {
                if (D_8010AF9E_26FF4E_LooneyLumberjacks != 0) {
                    if (D_8010AF9E_26FF4E_LooneyLumberjacks == 1) {
                        func_80104940_2698F0_LooneyLumberjacks(D_8010A6F4_26F6A4_LooneyLumberjacks[0].scale, D_8010A6F4_26F6A4_LooneyLumberjacks[0].trans.x, D_8010A6F4_26F6A4_LooneyLumberjacks[0].trans.y, D_8010A6F4_26F6A4_LooneyLumberjacks[0].trans.z, 30);
                        w = &D_8010AF3C_26FEEC_LooneyLumberjacks[0];
                        l = &D_8010AF3C_26FEEC_LooneyLumberjacks[1];
                    } else {
                        func_80104940_2698F0_LooneyLumberjacks(D_8010A6F4_26F6A4_LooneyLumberjacks[1].scale, D_8010A6F4_26F6A4_LooneyLumberjacks[1].trans.x, D_8010A6F4_26F6A4_LooneyLumberjacks[1].trans.y, D_8010A6F4_26F6A4_LooneyLumberjacks[1].trans.z, 30);
                        w = &D_8010AF3C_26FEEC_LooneyLumberjacks[1];
                        l = &D_8010AF3C_26FEEC_LooneyLumberjacks[0];
                    }
                    D_8010AF50_26FF00_LooneyLumberjacks[w->player[0]] = 5;
                    D_8010AF50_26FF00_LooneyLumberjacks[w->player[1]] = 5;
                    func_800732B0_73EB0(D_8010AF58_26FF08_LooneyLumberjacks[w->player[0]].win);
                    func_800732B0_73EB0(D_8010AF58_26FF08_LooneyLumberjacks[w->player[1]].win);
                    D_8010AF50_26FF00_LooneyLumberjacks[l->player[0]] = 6;
                    D_8010AF50_26FF00_LooneyLumberjacks[l->player[1]] = 6;
                    func_800691FC_69DFC(0x11, w->chr[0], w->chr[1]);
                    PlayMusic(0x52);
                    D_8010AF9A_26FF4A_LooneyLumberjacks = 168;
                } else {
                    for (i = 0; i < 4; i++) {
                        D_8010AF50_26FF00_LooneyLumberjacks[i] = 6;
                    }
                    for (i = 0; i < 2; i++) {
                        w = &D_8010AF3C_26FEEC_LooneyLumberjacks[i];
                        func_800732B0_73EB0(D_8010AF58_26FF08_LooneyLumberjacks[w->player[0]].lose);
                        func_800732B0_73EB0(D_8010AF58_26FF08_LooneyLumberjacks[w->player[1]].lose);
                    }
                    func_800691FC_69DFC(0x13);
                    PlayMusic(0x57);
                    D_8010AF9A_26FF4A_LooneyLumberjacks = 120;
                }
                D_8010AF98_26FF48_LooneyLumberjacks = 6;
            }
            break;
        case 6:
            if (D_8010AF9A_26FF4A_LooneyLumberjacks == 0) {
                func_80079614_7A214(40);
                InitFadeOut(0, 20);
                D_8010AF98_26FF48_LooneyLumberjacks = 7;
            } else if (D_8010AF9A_26FF4A_LooneyLumberjacks > 0) {
                D_8010AF9A_26FF4A_LooneyLumberjacks--;
            }
            break;
        case 7:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80103054_268004_LooneyLumberjacks;
            }
            break;
        case 8:
            break;
    }
}

void func_80103054_268004_LooneyLumberjacks(omObjData* obj) {
    func_80079464_7A064();
    omOvlReturnEx(1);
}

void func_80103078_268028_LooneyLumberjacks(omObjData* obj) {
    if (D_8010A714_26F6C4_LooneyLumberjacks != 0) {
        if (D_8010A714_26F6C4_LooneyLumberjacks == 1) {
            obj->func_ptr = func_80103054_268004_LooneyLumberjacks;
        }
        D_8010A714_26F6C4_LooneyLumberjacks--;
        return;
    }
    if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_8010A714_26F6C4_LooneyLumberjacks = 20;
        InitFadeOut(0, (s16)D_8010A714_26F6C4_LooneyLumberjacks);
        func_800794A8_7A0A8((s16)D_8010A714_26F6C4_LooneyLumberjacks);
        func_80079614_7A214((s16)D_8010A714_26F6C4_LooneyLumberjacks);
    }
}

// register allocation (masked 8)
#ifdef NON_MATCHING
void func_80103120_2680D0_LooneyLumberjacks(void) {
    s32 i;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 251.2f;
    D_8010274C_10334C.z = 10.2f;
    D_800FD474_FE074.x = 318.38f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 876.0f;
    func_80103ED8_268E88_LooneyLumberjacks(0);
    func_80103ED8_268E88_LooneyLumberjacks(1);
    D_8010B010_26FFC0_LooneyLumberjacks = 0;
    D_8010B00C_26FFBC_LooneyLumberjacks = 0;
    D_8010B008_26FFB8_LooneyLumberjacks = 0;
    omAddObj(0x1F, 0, 0, -1, func_80103A88_268A38_LooneyLumberjacks);
    for (i = 1; i < D_800FDBCA_FE7CA; i++) {
        D_800C9B80_CA780[0].viewports[i].vp.vscale[0] = D_800C9B80_CA780[0].viewports[0].vp.vscale[0];
        D_800C9B80_CA780[0].viewports[i].vp.vscale[1] = D_800C9B80_CA780[0].viewports[0].vp.vscale[1];
        D_800C9B80_CA780[0].viewports[i].vp.vscale[2] = D_800C9B80_CA780[0].viewports[0].vp.vscale[2];
        D_800C9B80_CA780[0].viewports[i].vp.vtrans[0] = D_800C9B80_CA780[0].viewports[0].vp.vtrans[0];
        D_800C9B80_CA780[0].viewports[i].vp.vtrans[1] = D_800C9B80_CA780[0].viewports[0].vp.vtrans[1];
        D_800C9B80_CA780[0].viewports[i].vp.vtrans[2] = D_800C9B80_CA780[0].viewports[0].vp.vtrans[2];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80103120_2680D0_LooneyLumberjacks);
#endif

void func_8010324C_2681FC_LooneyLumberjacks(void) {
    LLCamera c = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f };
    f32 speed = 1.0f;

    switch (D_8010A718_26F6C8_LooneyLumberjacks) {
        case 1:
            if (ContBtn[0] & 0x8000) {
                speed = 8.0f;
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
                func_801040C4_269074_LooneyLumberjacks(c.center.x, c.center.y, c.center.z, c.rot.x, c.rot.y, c.rot.z, c.zoom, 1);
            }
            sprintf(pfStrBuf, "CAMERA TEST_MODE");
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 104, pfStrBuf);
            D_800F8FD0_F9BD0 = 0;
            break;
        case 2:
            if ((ContBtn[0] & 0x100) || (ContBtn[0] & 1)) {
                D_8010A71C_26F6CC_LooneyLumberjacks++;
            }
            if (ContBtn[0] & 0x202) {
                D_8010A71C_26F6CC_LooneyLumberjacks--;
            }
            if (ContBtn[0] & 0x404) {
                D_8010A720_26F6D0_LooneyLumberjacks++;
            }
            if (ContBtn[0] & 0x808) {
                D_8010A720_26F6D0_LooneyLumberjacks--;
            }
            fontcolor = 8;
            sprintf(pfStrBuf, "CAMERA TEST_MODE ");
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 80, pfStrBuf);
            sprintf(pfStrBuf, " CENTER X>%3.3f Y>%3.3f Z>%3.3f ", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 88, pfStrBuf);
            sprintf(pfStrBuf, " ROT    X>%3.3f Y>%3.3f Z>%3.3f ", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 96, pfStrBuf);
            sprintf(pfStrBuf, " ZOOM   %3.3f ", D_800FA610_FB210);
            DrawDebugText((u16)D_8010A71C_26F6CC_LooneyLumberjacks + 20, (u16)D_8010A720_26F6D0_LooneyLumberjacks + 104, pfStrBuf);
            break;
        default:
            D_800F8FD0_F9BD0 = 1;
            break;
    }
    if (ContBtnTrg[0] & 0x10) {
        if (D_8010A718_26F6C8_LooneyLumberjacks & 1) {
            osSyncPrintf("CAMERA TEST_MODE \n");
            osSyncPrintf(" CENTER X>%3.3f Y>%3.3f Z>%3.3f \n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
            osSyncPrintf(" ROT    X>%3.3f Y>%3.3f Z>%3.3f \n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
            osSyncPrintf(" ZOOM   %3.3f \n\n", D_800FA610_FB210);
        }
        if (++D_8010A718_26F6C8_LooneyLumberjacks >= 3) {
            D_8010A718_26F6C8_LooneyLumberjacks = 0;
        }
    }
}

// register allocation (masked 14)
#ifdef NON_MATCHING
void func_80103A88_268A38_LooneyLumberjacks(omObjData* obj) {
    f32 t;

    if (D_8010B00C_26FFBC_LooneyLumberjacks <= 0) {
        func_801042B4_269264_LooneyLumberjacks(0);
        D_8010B010_26FFC0_LooneyLumberjacks = 0;
        return;
    }
    if (D_8010B008_26FFB8_LooneyLumberjacks == 0) {
        D_8010274C_10334C.x = D_8010AFC0_26FF70_LooneyLumberjacks[0].center.x;
        D_8010274C_10334C.y = D_8010AFC0_26FF70_LooneyLumberjacks[0].center.y;
        D_8010274C_10334C.z = D_8010AFC0_26FF70_LooneyLumberjacks[0].center.z;
        D_800FD474_FE074.x = D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.x;
        D_800FD474_FE074.y = D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.y;
        D_800FD474_FE074.z = D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.z;
        D_800FA610_FB210 = D_8010AFC0_26FF70_LooneyLumberjacks[0].zoom;
        LL_WRAP(D_800FD474_FE074.x);
        LL_WRAP(D_800FD474_FE074.y);
        LL_WRAP(D_800FD474_FE074.z);
        D_8010B00C_26FFBC_LooneyLumberjacks = 0;
    } else {
        t = 1.0 - (f32)D_8010B008_26FFB8_LooneyLumberjacks / (f32)D_8010B00C_26FFBC_LooneyLumberjacks;
        D_8010274C_10334C.x = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].center.x - D_8010AFC0_26FF70_LooneyLumberjacks[1].center.x) + D_8010AFC0_26FF70_LooneyLumberjacks[1].center.x;
        D_8010274C_10334C.y = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].center.y - D_8010AFC0_26FF70_LooneyLumberjacks[1].center.y) + D_8010AFC0_26FF70_LooneyLumberjacks[1].center.y;
        D_8010274C_10334C.z = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].center.z - D_8010AFC0_26FF70_LooneyLumberjacks[1].center.z) + D_8010AFC0_26FF70_LooneyLumberjacks[1].center.z;
        D_800FD474_FE074.x = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.x - D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.x) + D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.x;
        D_800FD474_FE074.y = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.y - D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.y) + D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.y;
        D_800FD474_FE074.z = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.z - D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.z) + D_8010AFC0_26FF70_LooneyLumberjacks[1].rot.z;
        D_800FA610_FB210 = t * (D_8010AFC0_26FF70_LooneyLumberjacks[0].zoom - D_8010AFC0_26FF70_LooneyLumberjacks[1].zoom) + D_8010AFC0_26FF70_LooneyLumberjacks[1].zoom;
        LL_WRAP(D_800FD474_FE074.x);
        LL_WRAP(D_800FD474_FE074.y);
        LL_WRAP(D_800FD474_FE074.z);
        if (D_8010B008_26FFB8_LooneyLumberjacks > 0) {
            D_8010B008_26FFB8_LooneyLumberjacks--;
        } else {
            D_8010B008_26FFB8_LooneyLumberjacks++;
        }
    }
    D_8010B010_26FFC0_LooneyLumberjacks = 1;
    func_801042B4_269264_LooneyLumberjacks(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80103A88_268A38_LooneyLumberjacks);
#endif

void func_80103ED8_268E88_LooneyLumberjacks(s32 idx) {
    LL_WRAP(D_800FD474_FE074.x);
    LL_WRAP(D_800FD474_FE074.y);
    LL_WRAP(D_800FD474_FE074.z);
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].center.x = D_8010274C_10334C.x;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].center.y = D_8010274C_10334C.y;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].center.z = D_8010274C_10334C.z;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].rot.x = D_800FD474_FE074.x;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].rot.y = D_800FD474_FE074.y;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].rot.z = D_800FD474_FE074.z;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].zoom = D_800FA610_FB210;
    D_8010AFC0_26FF70_LooneyLumberjacks[idx].unk_1C = D_8010AFC0_26FF70_LooneyLumberjacks[idx].unk_20 = 0.0f;
}

void func_801040C4_269074_LooneyLumberjacks(f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, f32 zoom, s32 frames) {
    if (frames > 0) {
        D_8010B008_26FFB8_LooneyLumberjacks = frames - 1;
        D_8010B00C_26FFBC_LooneyLumberjacks = frames;
        if (cx != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.x = cx;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.x = D_8010274C_10334C.x;
        }
        if (cy != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.y = cy;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.y = D_8010274C_10334C.y;
        }
        if (cz != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.z = cz;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].center.z = D_8010274C_10334C.z;
        }
        if (rx != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.x = rx;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.x = D_800FD474_FE074.x;
        }
        if (ry != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.y = ry;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.y = D_800FD474_FE074.y;
        }
        if (rz != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.z = rz;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].rot.z = D_800FD474_FE074.z;
        }
        if (zoom != 65535.0f) {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].zoom = zoom;
        } else {
            D_8010AFC0_26FF70_LooneyLumberjacks[0].zoom = D_800FA610_FB210;
        }
        func_80103ED8_268E88_LooneyLumberjacks(1);
    }
}

// register allocation (masked 8)
#ifdef NON_MATCHING
void func_801042B4_269264_LooneyLumberjacks(s32 idx) {
    HuCamera* cam;
    f32 rx;
    f32 ry;

    cam = &D_800C9B80_CA780[idx];
    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    cam->pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210 + D_8010274C_10334C.x;
    cam->pos.y = -HuMathSin(rx) * D_800FA610_FB210 + D_8010274C_10334C.y;
    cam->pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210 + D_8010274C_10334C.z;
    cam->at.x = D_8010274C_10334C.x;
    cam->at.y = D_8010274C_10334C.y;
    cam->at.z = D_8010274C_10334C.z;
    cam->up.x = HuMathSin(ry) * HuMathSin(rx);
    cam->up.y = func_800B7890_B8490(rx);
    cam->up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801042B4_269264_LooneyLumberjacks);
#endif

void func_80104410_2693C0_LooneyLumberjacks(void) {
    D_8010B04C_26FFFC_LooneyLumberjacks = 1.0f;
    D_8010B048_26FFF8_LooneyLumberjacks = 1.0f;
    D_8010B058_270008_LooneyLumberjacks = 0;
    D_8010B054_270004_LooneyLumberjacks = 0;
    D_8010B050_270000_LooneyLumberjacks = 0;
    func_801049C0_269970_LooneyLumberjacks(0);
    func_801049C0_269970_LooneyLumberjacks(1);
    ViewportSet(0, D_8010B018_26FFC8_LooneyLumberjacks[0].scale.x, D_8010B018_26FFC8_LooneyLumberjacks[0].scale.y, D_8010B018_26FFC8_LooneyLumberjacks[0].scale.z, D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x, D_8010B018_26FFC8_LooneyLumberjacks[0].scale.y, D_8010B018_26FFC8_LooneyLumberjacks[0].scale.z);
    omAddObj(0x1E, 0, 0, -1, func_801046F4_2696A4_LooneyLumberjacks);
}

void func_801044B8_269468_LooneyLumberjacks(void) {
    f32 scale;
    f32 x;
    f32 y;

    switch (D_8010A724_26F6D4_LooneyLumberjacks) {
        case 1:
            scale = D_8010B048_26FFF8_LooneyLumberjacks;
            x = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x;
            y = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y;
            if (ContBtn[0] & 0x100) {
                x += 2.0;
            }
            if (ContBtn[0] & 0x200) {
                x -= 2.0;
            }
            if (ContBtn[0] & 0x800) {
                y += 2.0;
            }
            if (ContBtn[0] & 0x400) {
                y -= 2.0;
            }
            if (ContBtn[0] & 2) {
                scale += 0.01;
            }
            if (ContBtn[0] & 1) {
                scale -= 0.01;
            }
            func_80104940_2698F0_LooneyLumberjacks(scale, x, y, 0.0f, 1);
            sprintf(pfStrBuf, "VIEW X>%3.3f, Y>%3.3f Z>%3.3f ", D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x, D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y, D_8010B018_26FFC8_LooneyLumberjacks[0].trans.z);
            DrawDebugText(10, 120, pfStrBuf);
            sprintf(pfStrBuf, "VIEW SCL>%3.3f ", D_8010B048_26FFF8_LooneyLumberjacks);
            DrawDebugText(10, 128, pfStrBuf);
            break;
        case 2:
            D_8010A724_26F6D4_LooneyLumberjacks = 0;
            break;
    }
    if (ContBtnTrg[0] & 0x2000) {
        if (++D_8010A724_26F6D4_LooneyLumberjacks >= 3) {
            D_8010A724_26F6D4_LooneyLumberjacks = 0;
        }
    }
}

void func_801046F4_2696A4_LooneyLumberjacks(omObjData* obj) {
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 t;

    if (D_8010B054_270004_LooneyLumberjacks <= 0) {
        scale = D_8010B048_26FFF8_LooneyLumberjacks;
        x = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x;
        y = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y;
        z = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.z;
        D_8010B058_270008_LooneyLumberjacks = 0;
    } else {
        if (D_8010B050_270000_LooneyLumberjacks == 0) {
            D_8010B048_26FFF8_LooneyLumberjacks = D_8010B04C_26FFFC_LooneyLumberjacks;
            scale = D_8010B04C_26FFFC_LooneyLumberjacks;
            D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.x;
            x = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.x;
            D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.y;
            y = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.y;
            D_8010B018_26FFC8_LooneyLumberjacks[0].trans.z = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.z;
            D_8010B054_270004_LooneyLumberjacks = 0;
            z = D_8010B018_26FFC8_LooneyLumberjacks[1].trans.z;
        } else {
            t = 1.0 - (f32)D_8010B050_270000_LooneyLumberjacks / (f32)D_8010B054_270004_LooneyLumberjacks;
            scale = D_8010B048_26FFF8_LooneyLumberjacks + t * (D_8010B04C_26FFFC_LooneyLumberjacks - D_8010B048_26FFF8_LooneyLumberjacks);
            x = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x + t * (D_8010B018_26FFC8_LooneyLumberjacks[1].trans.x - D_8010B018_26FFC8_LooneyLumberjacks[0].trans.x);
            y = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y + t * (D_8010B018_26FFC8_LooneyLumberjacks[1].trans.y - D_8010B018_26FFC8_LooneyLumberjacks[0].trans.y);
            z = D_8010B018_26FFC8_LooneyLumberjacks[0].trans.z + t * (D_8010B018_26FFC8_LooneyLumberjacks[1].trans.z - D_8010B018_26FFC8_LooneyLumberjacks[0].trans.z);
            if (D_8010B050_270000_LooneyLumberjacks > 0) {
                D_8010B050_270000_LooneyLumberjacks--;
            } else {
                D_8010B050_270000_LooneyLumberjacks++;
            }
        }
        D_8010B058_270008_LooneyLumberjacks = 1;
    }
    sx = scale * D_8010B018_26FFC8_LooneyLumberjacks[1].scale.x;
    sy = scale * D_8010B018_26FFC8_LooneyLumberjacks[1].scale.y;
    sz = D_8010B018_26FFC8_LooneyLumberjacks[1].scale.z;
    ViewportSet(0, sx, sy, sz, x, y, z);
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vscale[0] = sx;
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vscale[1] = sy;
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vscale[2] = sz;
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vtrans[0] = x;
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vtrans[1] = y;
    D_800C9B80_CA780[0].viewports[D_800FDBE0_FE7E0].vp.vtrans[2] = z;
}

void func_80104940_2698F0_LooneyLumberjacks(f32 scale, f32 x, f32 y, f32 z, s32 frames) {
    D_8010B050_270000_LooneyLumberjacks = frames - 1;
    D_8010B054_270004_LooneyLumberjacks = frames;
    func_801049C0_269970_LooneyLumberjacks(0);
    D_8010B04C_26FFFC_LooneyLumberjacks = scale;
    D_8010B018_26FFC8_LooneyLumberjacks[1].trans.x = x;
    D_8010B018_26FFC8_LooneyLumberjacks[1].trans.y = y;
    D_8010B018_26FFC8_LooneyLumberjacks[1].trans.z = z;
}

void func_801049C0_269970_LooneyLumberjacks(s32 idx) {
    D_8010B018_26FFC8_LooneyLumberjacks[idx].scale.x = D_800C98C4_CA4C4.x;
    D_8010B018_26FFC8_LooneyLumberjacks[idx].scale.y = D_800C98C4_CA4C4.y;
    D_8010B018_26FFC8_LooneyLumberjacks[idx].scale.z = D_800C98C4_CA4C4.z;
    D_8010B018_26FFC8_LooneyLumberjacks[idx].trans.x = D_800C990C_CA50C.x;
    D_8010B018_26FFC8_LooneyLumberjacks[idx].trans.y = D_800C990C_CA50C.y;
    D_8010B018_26FFC8_LooneyLumberjacks[idx].trans.z = D_800C990C_CA50C.z;
}

// register allocation (masked 2)
#ifdef NON_MATCHING
void func_80104A40_2699F0_LooneyLumberjacks(void) {
    omObjData* obj;
    s16 g;

    obj = omAddObj(0x20, 0, 0, -1, func_80104B5C_269B0C_LooneyLumberjacks);
    D_8010AF4C_26FEFC_LooneyLumberjacks[5] = func_80107D50_26CD00_LooneyLumberjacks(0x450009);
    g = SprCreate(1, 0);
    SprAnimSet(g, 0, D_8010AF4C_26FEFC_LooneyLumberjacks[5], 0);
    SprAttrSet(g, 0, 0x4000);
    SprScaleSet(g, 0, 1.0f, 1.0f);
    SprPrioSet(g, 0, 0xFFFF);
    func_8008225C_82E5C(g, 0, 0);
    SprPosSet(g, 0, 160, 120);
    SprAnimGet(D_8010AF4C_26FEFC_LooneyLumberjacks[5]);
    D_8010AFA4_26FF54_LooneyLumberjacks = 3.62f;
    obj->work[0] = g;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80104A40_2699F0_LooneyLumberjacks);
#endif

void func_80104B5C_269B0C_LooneyLumberjacks(omObjData* obj) {
    s16 g;
    HuSprite_Unk84_Struct* spr;

    g = obj->work[0];
    spr = SprAnimGet(D_8010AF4C_26FEFC_LooneyLumberjacks[5]);
    if (D_8010A728_26F6D8_LooneyLumberjacks == 0) {
        if ((D_8010B010_26FFC0_LooneyLumberjacks != 0 || D_8010B058_270008_LooneyLumberjacks != 0) && D_8010A72A_26F6DA_LooneyLumberjacks != 0) {
            SprAttrSet(g, 0, 0x800038);
            D_8010A72A_26F6DA_LooneyLumberjacks = 0;
        }
        SprScaleSet(g, 0, D_8010AFA4_26FF54_LooneyLumberjacks, D_8010AFA4_26FF54_LooneyLumberjacks);
        SprPosPerspectiveSet(g, 0, 0, 0.0f, 0.0f, 0.0f);
        spr->unk00->unk0A = 0xAA;
        return;
    }
    D_8010A728_26F6D8_LooneyLumberjacks--;
}

// register allocation (masked 48)
#ifdef NON_MATCHING
void func_80104C48_269BF8_LooneyLumberjacks(void) {
    s32 n0;
    s32 n1;
    s32 n2;
    s32 n3;
    LLTeam* t;
    omObjData* obj;
    omObjData* o;
    LLPlayer* p;
    s32 order[4];
    s32 i;
    s32 j;
    s32 k;

    t = D_8010AF3C_26FEEC_LooneyLumberjacks;
    D_8010AF4C_26FEFC_LooneyLumberjacks[1] = func_80107D50_26CD00_LooneyLumberjacks(0x45000B);
    D_8010AF4C_26FEFC_LooneyLumberjacks[2] = func_80107D50_26CD00_LooneyLumberjacks(0x45000C);
    n3 = 0;
    n2 = 0;
    n1 = 0;
    n0 = 0;
    order[3] = 0;
    order[2] = 0;
    order[1] = 0;
    order[0] = 0;
    for (i = 0; i < 4; i++) {
        switch (gPlayers[i].group) {
            case 0:
                order[0] = i;
                n0++;
                break;
            case 1:
                order[1] = i;
                n1++;
                break;
            case 2:
                order[2] = i;
                n2++;
                break;
            case 3:
                order[3] = i;
                n3++;
                break;
            default:
                order[3] = i;
                n3++;
                break;
        }
        if (n0 >= 2 || n1 >= 2 || n2 >= 2 || n3 >= 2) {
            i = rand8() & 3;
            for (j = 0; j < 4; j++) {
                order[j] = D_8010A72C_26F6DC_LooneyLumberjacks[i][j];
            }
            break;
        }
    }
    for (i = 0; i < 2; i++) {
        obj = omAddObj(i + 8, 6, 0, -1, func_801053C8_26A378_LooneyLumberjacks);
        func_80108B80_26DB30_LooneyLumberjacks(obj, t);
        obj->model[0] = func_80018A30_19630(D_8010A78C_26F73C_LooneyLumberjacks[i] | 0x450000, 0xB9);
        func_80029714_2A314(obj->model[0], D_8010A75C_26F70C_LooneyLumberjacks[i].x, D_8010A75C_26F70C_LooneyLumberjacks[i].y, D_8010A75C_26F70C_LooneyLumberjacks[i].z);
        func_8002979C_2A39C(obj->model[0], D_8010A774_26F724_LooneyLumberjacks[i].x, D_8010A774_26F724_LooneyLumberjacks[i].y, D_8010A774_26F724_LooneyLumberjacks[i].z);
        D_800FC834_FD434[obj->model[0]].unk44 = 0.0f;
        if (i == 0) {
            obj->trans.x = D_8010A75C_26F70C_LooneyLumberjacks[0].x + 85.0;
            obj->trans.y = D_8010A75C_26F70C_LooneyLumberjacks[0].y;
            obj->trans.z = D_8010A75C_26F70C_LooneyLumberjacks[0].z + 204.99999999999997;
        } else {
            obj->trans.x = D_8010A75C_26F70C_LooneyLumberjacks[i].x + 200.0;
            obj->trans.y = D_8010A75C_26F70C_LooneyLumberjacks[i].y;
            obj->trans.z = D_8010A75C_26F70C_LooneyLumberjacks[i].z + 100.0;
        }
        obj->rot.x = D_8010A774_26F724_LooneyLumberjacks[i].x;
        obj->rot.z = D_8010A774_26F724_LooneyLumberjacks[i].z;
        obj->rot.y = D_8010A774_26F724_LooneyLumberjacks[i].y - 90.0;
        t->team = i;
        t->unk_0A = 0;
        t->frame = 0;
        t->unk_1C = D_8010A74C_26F6FC_LooneyLumberjacks[i];
        t->dir = D_8010A750_26F700_LooneyLumberjacks[i];
        t->unk_20 = 0;
        t->stroke = 0;
        t->phase = 0;
        t->cut = 0.0f;
        t->pos = D_8010A754_26F704_LooneyLumberjacks[i];
        t->vel = 0.0f;
        t->lastDir = D_8010A750_26F700_LooneyLumberjacks[i];
        t->lastVel = 0.0f;
        t->comMask = 0;
        t->comDir = D_8010A750_26F700_LooneyLumberjacks[i];
        t->tree = func_801077F0_26C7A0_LooneyLumberjacks(&D_8010A75C_26F70C_LooneyLumberjacks[i], &D_8010A774_26F724_LooneyLumberjacks[i], 300.0f);
        t->spr = SprCreate(2, 0);
        for (j = 0; j < 2; j++) {
            t->player[j] = order[i * 2 + j];
            t->chr[j] = gPlayers[t->player[j]].character;
            t->port[j] = gPlayers[t->player[j]].port;
            if (gPlayers[t->player[j]].flags & 1) {
                t->comMask |= 1 << j;
                t->level += gPlayers[t->player[j]].cpu_difficulty;
            }
            SprAnimSet(t->spr, j, D_8010AF4C_26FEFC_LooneyLumberjacks[1], 0);
            SprAttrSet(t->spr, j, 0x9000);
            SprScaleSet(t->spr, j, 1.0f, 1.0f);
            SprPrioSet(t->spr, j, 0xFFFF);
            func_8008225C_82E5C(t->spr, j, 0);
            SprPosSet(t->spr, j, D_8010A670_26F620_LooneyLumberjacks[i][j].x, D_8010A670_26F620_LooneyLumberjacks[i][j].y);
            k = i * 2 + j;
            o = omAddObj(k + 0x10, 10, 60, -1, func_80106C30_26BBE0_LooneyLumberjacks);
            D_800FFFD8_100BD8[D_800FC87A_FD47A++] = o;
            t->obj[j] = o;
            p = &D_8010AF38_26FEE8_LooneyLumberjacks[t->player[j]];
            func_80108B80_26DB30_LooneyLumberjacks(o, p);
            p->player = t->player[j];
            p->idx = k;
            p->team = i;
            p->chr = t->chr[j];
        }
        t->wrong[1] = 0;
        t->wrong[0] = 0;
        if (t->comMask == 3) {
            t->level /= 2;
            if (t->level >= 4) {
                t->level = 3;
            }
            if (t->level < 0) {
                t->level = 0;
            }
            t->comSide = rand8() & 1;
            t->comA = D_8010A6AC_26F65C_LooneyLumberjacks[t->level][rand8() & 3];
            t->comB = D_8010A6C4_26F674_LooneyLumberjacks[t->level][rand8() & 3];
            t->comC = D_8010A6DC_26F68C_LooneyLumberjacks[t->level][rand8() & 3];
        }
        t++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80104C48_269BF8_LooneyLumberjacks);
#endif

// register allocation (masked 92)
#ifdef NON_MATCHING
void func_801053C8_26A378_LooneyLumberjacks(omObjData* obj) {
    LLTeam* t;
    omObjData** po;
    LLPlayer* p;
    LLInput s;
    LLInput* ps;
    Vec pos;
    f32 inv;
    f32 x;
    f32 y;
    f64 f;
    s16 i;
    s16 which;
    s16 side;
    s32 h;
    s32 team;

    t = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (t == NULL) {
        return;
    }
    s.m[0] = &D_800FC834_FD434[t->obj[0]->model[0]];
    s.m[1] = &D_800FC834_FD434[t->obj[1]->model[0]];
    switch (D_8010AF98_26FF48_LooneyLumberjacks) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        case 0:
            t->stroke = 0;
            if (D_8010A688_26F638_LooneyLumberjacks[t->team] > 0.0) {
                t->pos = 0.0f;
            } else {
                t->pos = D_8010AFA0_26FF50_LooneyLumberjacks;
            }
            break;
        case 1:
            t->stroke = 0;
            if (D_8010A688_26F638_LooneyLumberjacks[t->team] > 0.0) {
                t->pos = 0.0f;
            } else {
                t->pos = D_8010AFA0_26FF50_LooneyLumberjacks;
            }
            break;
        case 2:
            if (D_8010AFA0_26FF50_LooneyLumberjacks < 1.0) {
                D_8010AFA0_26FF50_LooneyLumberjacks = 1.0f;
            } else if (D_8010AFA0_26FF50_LooneyLumberjacks <= (f32)t->stroke) {
                t->stroke = D_8010AFA0_26FF50_LooneyLumberjacks;
            }
            inv = 1.0 / D_8010AFA0_26FF50_LooneyLumberjacks;
            func_80105EB0_26AE60_LooneyLumberjacks(obj);
            which = -1;
            ps = &s;
            for (i = 0; i < 2; i++) {
                ps->in[i] = 0;
                if (D_8010A680_26F630_LooneyLumberjacks[0][i] & ContBtn[t->port[i]]) {
                    ps->in[i] = -1;
                } else if (D_8010A680_26F630_LooneyLumberjacks[1][i] & ContBtn[t->port[i]]) {
                    ps->in[i] = 1;
                }
            }
            if (s.in[0] == -1 && s.in[1] == s.in[0]) {
                t->vel = -2.0f;
                t->dir = 0;
                goto clear;
            }
            if (s.in[0] == 1 && s.in[1] == s.in[0]) {
                t->vel = 2.0f;
                t->dir = 1;
            clear:
                t->wrong[1] = 0;
                t->wrong[0] = 0;
            }
            if (t->dir == 1 && (s.in[0] == -1 || s.in[1] == -1)) {
                t->vel = 0.0f;
                for (i = 0; i < 2; i++) {
                    if (s.in[i] == -1) {
                        which = i;
                        t->wrong[i]++;
                    }
                }
            }
            if (t->dir == 0 && (s.in[0] == 1 || s.in[1] == 1)) {
                t->vel = 0.0f;
                for (i = 0; i < 2; i++) {
                    if (s.in[i] == 1) {
                        which = i;
                        t->wrong[i]++;
                    }
                }
            }
            t->pos += t->vel;
            if ((t->pos > 0.0 && t->vel < 0.0) || (t->pos < D_8010AFA0_26FF50_LooneyLumberjacks && t->vel > 0.0)) {
                t->stroke += fabs(t->vel);
                if (t->lastVel == 0.0) {
                    func_80108728_26D6D8_LooneyLumberjacks(obj);
                    if (t->team == 0) {
                        func_80079798_7A398(0x2EA, t->player[0]);
                    } else {
                        func_80079798_7A398(0x2EB, t->player[0]);
                    }
                    func_80079798_7A398(0x2ED, t->player[1]);
                }
            }
            if (D_8010AFA0_26FF50_LooneyLumberjacks <= t->pos) {
                t->pos = D_8010AFA0_26FF50_LooneyLumberjacks;
                t->comDir = 0;
                t->dir = 0;
                if (t->vel > 0.0 && t->comC == 0) {
                    t->comC = D_8010A6DC_26F68C_LooneyLumberjacks[t->level][rand8() & 3];
                }
                t->vel = 0.0f;
            } else if (t->pos <= 0.0) {
                t->pos = 0.0f;
                t->comDir = 1;
                t->dir = 1;
                if (t->vel < 0.0 && t->comC == 0) {
                    t->comC = D_8010A6DC_26F68C_LooneyLumberjacks[t->level][rand8() & 3];
                }
                t->vel = 0.0f;
            }
            if (t->dir != t->lastDir) {
                t->phase = func_80107ADC_26CA8C_LooneyLumberjacks(t->tree, inv * (f32)t->stroke);
                t->cut = func_80107C3C_26CBEC_LooneyLumberjacks(t->tree);
                t->stroke = 0;
            }
            t->lastVel = t->vel;
            t->lastDir = t->dir;
            side = t->dir;
            if (t->vel > 0.0) {
                side = 1;
            } else if (t->vel < 0.0) {
                side = 0;
            }
            t->frame++;
            for (i = 0; i < 2; i++) {
                f = inv * t->pos;
                x = f * 10.0;
                y = -(D_8010A688_26F638_LooneyLumberjacks[t->team] * (f * 5.0));
                SprAttrReset(t->spr, i, 0x8000);
                if (!(t->frame & 0x1E) && t->phase >= 5) {
                    po = &t->obj[i];
                    p = func_80108BA0_26DB50_LooneyLumberjacks(*po);
                    pos.x = (*po)->trans.x + p->head.x;
                    pos.y = (*po)->trans.y + 100.0;
                    pos.z = (*po)->trans.z + p->head.z;
                    func_8008221C_82E1C(D_8010AF44_26FEF4_LooneyLumberjacks[(s16)func_80107FE8_26CF98_LooneyLumberjacks(3, &pos, NULL)].spr, 0, 2.0f);
                }
                if (which != i) {
                    SprAnimSet(t->spr, i, D_8010AF4C_26FEFC_LooneyLumberjacks[D_8010A7A4_26F754_LooneyLumberjacks[0]], 0);
                    SprBankSet(t->spr, i, D_8010A794_26F744_LooneyLumberjacks[t->team * 2 + i][side]);
                } else {
                    SprAnimSet(t->spr, i, D_8010AF4C_26FEFC_LooneyLumberjacks[D_8010A7A4_26F754_LooneyLumberjacks[1]], 0);
                    SprBankSet(t->spr, i, D_8010A794_26F744_LooneyLumberjacks[t->team * 2 + i][side ^ 1]);
                }
                if (which != -1) {
                    y += (f32)((t->frame & 1) * 3);
                }
                SprPosSet(t->spr, i, (f32)D_8010A670_26F620_LooneyLumberjacks[t->team][i].x + x, (f32)D_8010A670_26F620_LooneyLumberjacks[t->team][i].y + y);
            }
            if (t->phase >= 6 || t->cut >= 1.0) {
                D_8010AF9E_26FF4E_LooneyLumberjacks |= 1 << t->team;
                h = PlaySound(0x2EC);
                if (h >= 0) {
                    func_800798F8_7A4F8(h, D_8010A7A8_26F758_LooneyLumberjacks[t->team]);
                }
            }
            team = t->team;
            if (team == 1 && D_8010AF9E_26FF4E_LooneyLumberjacks != 0) {
                if (D_8010AF9E_26FF4E_LooneyLumberjacks == 3) {
                    D_8010AF9E_26FF4E_LooneyLumberjacks = team << (rand8() & 1);
                }
                D_8010AF98_26FF48_LooneyLumberjacks = 3;
            }
            break;
    }
    if (D_8010AF98_26FF48_LooneyLumberjacks >= 3) {
        if (t->phase >= 0 && D_8010AFAC_26FF5C_LooneyLumberjacks == 0) {
            t->phase = -1;
        }
        if (D_8010AF98_26FF48_LooneyLumberjacks >= 3) {
            for (i = 0; i < 2; i++) {
                SprAttrSet(t->spr, i, 0x8000);
            }
        }
    }
    func_80106288_26B238_LooneyLumberjacks(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801053C8_26A378_LooneyLumberjacks);
#endif

// register allocation (masked 7)
#ifdef NON_MATCHING
void func_80105EB0_26AE60_LooneyLumberjacks(omObjData* obj) {
    LLTeam* t;
    s32 idx[2];
    s32 which;
    s32 idle;
    s32 j;
    s32 i;
    u16 btn;
    u16* b;

    t = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (t == NULL) {
        return;
    }
    switch (t->comMask) {
      case 1:
      case 2:
        if (t->comMask == 1) {
            idx[0] = 0;
            idx[1] = 1;
        } else {
            idx[0] = 1;
            idx[1] = 0;
        }
        for (i = 0; i < 2; i++) {
            j = idx[i];
            if (gPlayers[t->player[j]].flags & 1) {
                ContBtn[t->port[j]] = 0;
                b = &ContBtn[t->port[j]];
                *b |= D_8010A680_26F630_LooneyLumberjacks[t->comDir][j];
            } else {
                t->comDir = t->dir;
                if (!(t->stroke <= 0.0) && !(D_8010AFA0_26FF50_LooneyLumberjacks <= (f32)t->stroke)) {
                    btn = ContBtn[t->port[j]];
                    if (btn & 0x8000) {
                        if (!(btn & 0x4000)) {
                            goto hit;
                        }
                    } else if (ContBtn[t->port[j]] & 0x4000) {
                    hit:
                        if (ContBtn[t->port[j]] & D_8010A680_26F630_LooneyLumberjacks[t->dir][j]) {
                            t->comDir = t->dir;
                        } else {
                            t->comDir = t->dir ^ 1;
                        }
                    }
                }
            }
        }
        break;
      case 3:
        which = -1;
        idle = 0;
        if (t->comC != 0 && t->level < 3) {
            t->comC--;
            idle = 1;
        } else if (t->comB != 0) {
            t->comB--;
        } else if (t->comA != 0) {
            which = t->comSide;
            t->comA--;
        } else {
            t->comSide = rand8() & 2;
            t->comA = D_8010A6AC_26F65C_LooneyLumberjacks[t->level][rand8() & 3];
            t->comB = D_8010A6C4_26F674_LooneyLumberjacks[t->level][rand8() & 3];
        }
        for (i = 0; i < 2; i++) {
            ContBtn[t->port[i]] = 0;
            if (idle != 0) {
                ContBtn[t->port[i]] = 0;
            } else if (which == i) {
                b = &ContBtn[t->port[i]];
                *b |= D_8010A680_26F630_LooneyLumberjacks[t->dir][i ^ 1];
            } else {
                b = &ContBtn[t->port[i]];
                *b |= D_8010A680_26F630_LooneyLumberjacks[t->dir][i];
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80105EB0_26AE60_LooneyLumberjacks);
#endif

// register allocation (masked 52)
#ifdef NON_MATCHING
void func_80106288_26B238_LooneyLumberjacks(omObjData* obj) {
    LLTeam* t;
    HmfModel* m[2];
    HmfModel* tm;
    LLPlayer* p;
    s16 a;
    s16 b;
    s32 i;
    s32 n;
    s32 mot;
    f32 w;
    f32 h;
    f32 y;

    t = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (t == NULL || t->obj[0]->model[0] < 0 || t->obj[1]->model[0] < 0) {
        return;
    }
    m[0] = &D_800FC834_FD434[t->obj[0]->model[0]];
    m[1] = &D_800FC834_FD434[t->obj[1]->model[0]];
    tm = &D_800FC834_FD434[obj->model[0]];
    if (D_8010AFA0_26FF50_LooneyLumberjacks < 1.0f) {
        D_8010AFA0_26FF50_LooneyLumberjacks = 1.0f;
    }
    m[0]->unk44 = 0.0f;
    m[1]->unk44 = 0.0f;
    switch (t->phase) {
        case -1:
            n = t->cut * 4.0f + 0.5f;
            if (n < 0) {
                n = 0;
            } else if (n >= 5) {
                n = 4;
            }
            w = (f32)n * 0.25;
            h = D_8010AFA0_26FF50_LooneyLumberjacks * 0.5;
            if (t->pos == h && t->cut == w) {
                t->phase = -2;
                t->unk_0A = 0;
                return;
            }
            t->pos += func_80108944_26D8F4_LooneyLumberjacks(h, t->pos, 2.0f);
            t->cut += func_80108944_26D8F4_LooneyLumberjacks(w, t->cut, 0.1f);
            y = -(t->cut * 80.0);
            tm->pos.y = y;
            obj->trans.y = y;
            if (D_8010A688_26F638_LooneyLumberjacks[1] > 0.0) {
                tm->unk40 = t->pos;
            } else {
                tm->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
            }
            if (t->cut < 0.0) {
                t->cut = 0.0f;
            }
            if (t->cut > 1.0) {
                t->cut = 1.0f;
            }
            n = t->cut * 4.0f + 1.0f;
            w = t->cut * 4.0f - (f32)(n - 1);
            a = D_8010A7AC_26F75C_LooneyLumberjacks[n - 1];
            b = D_8010A7AC_26F75C_LooneyLumberjacks[n];
            for (i = 0; i < 2; i++) {
                if (D_8010A688_26F638_LooneyLumberjacks[i] > 0.0) {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, w, t->pos);
                } else {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, w, D_8010AFA0_26FF50_LooneyLumberjacks - t->pos);
                }
            }
            return;
        case -2:
            n = t->cut * 4.0f;
            if (n < 0) {
                n = 0;
            } else if (n >= 5) {
                n = 4;
            }
            for (i = 0; i < 2; i++) {
                func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], D_8010A7AC_26F75C_LooneyLumberjacks[n], -1, 0.0f, 0.0f);
                if (D_8010A688_26F638_LooneyLumberjacks[i] > 0.0) {
                    m[i]->unk40 = t->pos;
                } else {
                    m[i]->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
                }
                if (D_8010AFAC_26FF5C_LooneyLumberjacks == 0 && D_8010AF9E_26FF4E_LooneyLumberjacks == (1 << t->team)) {
                    mot = t->obj[i]->motion[8];
                } else {
                    mot = t->obj[i]->motion[7];
                }
                func_80029BF0_2A7F0(t->obj[i]->model[0], func_80029E14_2AA14(mot), 0, 30, 0);
            }
            if (D_8010AFAC_26FF5C_LooneyLumberjacks == 0 && D_8010AF9E_26FF4E_LooneyLumberjacks == (1 << t->team)) {
                t->phase = -4;
                return;
            }
            t->phase = -3;
            return;
        case -3:
            for (i = 0; i < 2; i++) {
                m[i]->unk44 = 1.0f;
            }
            return;
        case -4:
            for (i = 0; i < 2; i++) {
                m[i]->unk44 = 1.0f;
                p = func_80108BA0_26DB50_LooneyLumberjacks(t->obj[i]);
                if (p->state == 0) {
                    p->state = 1;
                }
            }
            return;
        case 0:
            tm->pos.y = 0.0f;
            obj->trans.y = 0.0f;
            if (D_8010A688_26F638_LooneyLumberjacks[1] > 0.0) {
                tm->unk40 = t->pos;
            } else {
                tm->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
            }
            a = D_8010A7AC_26F75C_LooneyLumberjacks[0];
            b = D_8010A7AC_26F75C_LooneyLumberjacks[0];
            for (i = 0; i < 2; i++) {
                if (D_8010A688_26F638_LooneyLumberjacks[i] > 0.0) {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, 0.0f, t->pos);
                } else {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, 0.0f, D_8010AFA0_26FF50_LooneyLumberjacks - t->pos);
                }
            }
            return;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            y = -(t->cut * 80.0);
            tm->pos.y = y;
            obj->trans.y = y;
            if (D_8010A688_26F638_LooneyLumberjacks[1] > 0.0) {
                tm->unk40 = t->pos;
            } else {
                tm->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
            }
            n = t->cut * 4.0f + 1.0f;
            w = t->cut * 4.0f - (f32)(n - 1);
            a = D_8010A7AC_26F75C_LooneyLumberjacks[n - 1];
            b = D_8010A7AC_26F75C_LooneyLumberjacks[n];
            for (i = 0; i < 2; i++) {
                if (D_8010A688_26F638_LooneyLumberjacks[i] > 0.0) {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, w, t->pos);
                } else {
                    func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], a, b, w, D_8010AFA0_26FF50_LooneyLumberjacks - t->pos);
                }
            }
            return;
        default:
            tm->pos.y = -80.0f;
            obj->trans.y = -80.0f;
            if (D_8010A688_26F638_LooneyLumberjacks[1] > 0.0) {
                tm->unk40 = t->pos;
            } else {
                tm->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
            }
            for (i = 0; i < 2; i++) {
                func_80108F50_26DF00_LooneyLumberjacks(t->obj[i], D_8010A7AC_26F75C_LooneyLumberjacks[4], -1, 0.0f, 0.0f);
                if (D_8010A688_26F638_LooneyLumberjacks[i] > 0.0) {
                    m[i]->unk40 = t->pos;
                } else {
                    m[i]->unk40 = D_8010AFA0_26FF50_LooneyLumberjacks - t->pos;
                }
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80106288_26B238_LooneyLumberjacks);
#endif

void func_80106C0C_26BBBC_LooneyLumberjacks(void) {
    func_8000C578_D178(1);
    func_8000C460_D060();
}

void func_80106C30_26BBE0_LooneyLumberjacks(omObjData* obj) {
    LLPlayer* p;
    u16 pl;
    u16 chr;
    s32 dir;
    s32 file;
    LLPose* pose;
    Vec* rot;

    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    pl = p->player;
    D_8010AFB0_26FF60_LooneyLumberjacks = pl;
    D_8010AFB8_26FF68_LooneyLumberjacks = gPlayers[pl].port;
    if (gPlayers[pl].flags & 1) {
        D_8010AFBC_26FF6C_LooneyLumberjacks = 1;
    } else {
        D_8010AFBC_26FF6C_LooneyLumberjacks = 0;
    }
    chr = gPlayers[pl].character;
    D_8010AFB4_26FF64_LooneyLumberjacks = chr;
    if (gPlayers[pl].group == 0) {
        D_8010AFAE_26FF5E_LooneyLumberjacks = pl;
    }
    dir = D_800CD438_CE038[chr].dir;
    file = D_800CD438_CE038[chr].unk_10;
    func_8000C6FC_D2FC(obj, dir, file, pl, 0x6B9, 0x6A9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    obj->func_ptr = func_80106F9C_26BF4C_LooneyLumberjacks;
    ((MgWork*)obj->unk_50)->unk_EC = NULL;
    func_80019E84_1AA84(obj, 0, dir | 0xC0, 1, 999);
    func_80019E84_1AA84(obj, 1, dir | 0xC1, 1, 999);
    func_80019E84_1AA84(obj, 2, dir | 0xC2, 1, 999);
    func_80019E84_1AA84(obj, 3, dir | 0xC3, 1, 999);
    func_80019E84_1AA84(obj, 4, dir | 0xC4, 1, 999);
    rand8();
    func_80019E84_1AA84(obj, 5, dir | D_8010A7E8_26F798_LooneyLumberjacks[0], 1, 999);
    D_8010AF58_26FF08_LooneyLumberjacks[pl].win = dir | D_8010A7E8_26F798_LooneyLumberjacks[0];
    rand8();
    func_80019E84_1AA84(obj, 6, dir | D_8010A7F0_26F7A0_LooneyLumberjacks[0], 1, 999);
    D_8010AF58_26FF08_LooneyLumberjacks[pl].lose = dir | D_8010A7F0_26F7A0_LooneyLumberjacks[0];
    func_80019E84_1AA84(obj, 7, dir, 1, 0);
    func_80019E84_1AA84(obj, 8, dir | 1, 1, 0);
    D_8010AFA0_26FF50_LooneyLumberjacks = func_80029D0C_2A90C(obj->motion[0]);
    func_80108C40_26DBF0_LooneyLumberjacks(obj);
    p->state = 0;
    p->hat = func_8002A9F4_2B5F4(obj->model[0], D_8010A7B8_26F768_LooneyLumberjacks[chr]);
    p->headBack = D_8010A7D0_26F780_LooneyLumberjacks[chr];
    p->head.x = p->head.y = p->head.z = 0.0f;
    pose = &D_8010A610_26F5C0_LooneyLumberjacks[p->idx];
    rot = &D_8010A610_26F5C0_LooneyLumberjacks[p->idx].rot;
    func_8000C35C_CF5C(obj, pose->pos.x, pose->pos.y, pose->pos.z);
    func_8000C36C_CF6C(obj, rot->x, rot->y, rot->z);
}

__asm__(".section .rodata");
const char D_8010AD90_26FD40_LooneyLumberjacks[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010ADA4_26FD54_LooneyLumberjacks[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010ADB4_26FD64_LooneyLumberjacks[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_8010ADC4_26FD74_LooneyLumberjacks[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_8010ADDC_26FD8C_LooneyLumberjacks[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_8010ADF0_26FDA0_LooneyLumberjacks[] = "atama_2";

void func_80106F9C_26BF4C_LooneyLumberjacks(omObjData* obj) {
    LLPlayer* p;
    HmfModel* m;
    s32 mot;
    s32 req;

    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    m = &D_800FC834_FD434[obj->model[0]];
    if (p->state == 1) {
        obj->rot.y = func_801089C0_26D970_LooneyLumberjacks(0.0f, obj->rot.y, 10.0f);
        obj->trans.z += 5.0;
        if (obj->trans.z > 50.0) {
            obj->trans.z = 50.0f;
        }
        if (obj->trans.z >= 50.0 && obj->rot.y == 0.0) {
            func_80019B9C_1A79C(obj, 7);
            p->state++;
        } else {
            mot = m->unk02;
            if (mot == (s16)func_80029E14_2AA14(obj->motion[8])) {
                if (func_80029D0C_2A90C(obj->motion[8]) <= m->unk40) {
                    m->unk40 = 0.0f;
                }
            }
        }
    } else {
        req = D_8010AF50_26FF00_LooneyLumberjacks[p->player];
        if (req >= 0 && func_80019B9C_1A79C(obj, req) != 0) {
            D_8010AF50_26FF00_LooneyLumberjacks[p->player] = -1;
        }
        if (D_8010AF98_26FF48_LooneyLumberjacks >= 5 && D_8010AFAC_26FF5C_LooneyLumberjacks == 0) {
            obj->rot.y = func_801089C0_26D970_LooneyLumberjacks(0.0f, obj->rot.y, 10.0f);
        }
    }
    func_80108D58_26DD08_LooneyLumberjacks(obj);
    func_801071A8_26C158_LooneyLumberjacks(obj);
    func_80019378_19F78(obj);
}

void func_801071A8_26C158_LooneyLumberjacks(omObjData* obj) {
    LLPlayer* p;
    HmfModel* body;
    HmfModel* hat;
    HmfMotionObj* part;
    f32 x;
    f32 z;

    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    body = &D_800FC834_FD434[obj->model[0]];
    hat = &D_800FC834_FD434[obj->model[1]];
    if (D_8010AF98_26FF48_LooneyLumberjacks >= 3 && D_8010AFAC_26FF5C_LooneyLumberjacks == 0) {
        p->headBack += func_80108944_26D8F4_LooneyLumberjacks(0.0f, p->headBack, 0.1f);
    }
    part = p->hat;
    if (part != NULL) {
        x = part->unk58[3][0] * 0.6;
        z = part->unk58[3][2] * 0.6 + p->headBack;
        hat->pos.x = body->pos.x;
        hat->pos.z = body->pos.z;
        func_800B37C0_B43C0(hat->mtx);
        func_80025884_26484(hat->mtx, 0.0f, body->rot.y, 0.0f);
        func_80025770_26370(hat->mtx, x, 0.0f, z);
        p->head.x = hat->mtx[12];
        p->head.y = hat->mtx[13];
        p->head.z = hat->mtx[14];
    }
}

void func_8010730C_26C2BC_LooneyLumberjacks(void) {
    LLTree* tree;
    s32 i;

    tree = D_8010AF40_26FEF0_LooneyLumberjacks;
    for (i = 0; i < 2; i++) {
        tree->obj = omAddObj(i + 2, 8, 0, -1, func_801073C4_26C374_LooneyLumberjacks);
        func_80108B80_26DB30_LooneyLumberjacks(tree->obj, tree);
        tree->team = i;
        tree->used = 0;
        tree->stage = 0;
        tree->fall = 0;
        tree->angle = 0.0f;
        tree->speed = 0.0f;
        tree->hp = tree->maxHp = 0.0f;
        tree++;
    }
}

// register allocation (masked 34)
#ifdef NON_MATCHING
void func_801073C4_26C374_LooneyLumberjacks(omObjData* obj) {
    LLTree* tree;
    HmfModel* m;
    Vec pos;
    s32 i;
    s16 mdl;
    f32 v;
    f64 d;

    tree = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (tree == NULL || tree->used == 0) {
        return;
    }
    for (i = 1; i < 6; i++) {
        mdl = obj->model[i];
        if (tree->stage >= i && !(D_800FC834_FD434[mdl].unk18 & 4)) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
    if (tree->stage >= 6 || tree->hp <= 0.0) {
        m = &D_800FC834_FD434[obj->model[6]];
        if (m->pos.y > 40.0) {
            tree->angle += 10.0;
            m->pos.y -= 10.0;
            m->pos.x += HuMathSin(obj->rot.y) * 80.0 * 0.5 * 0.1;
            m->pos.z += func_800B7890_B8490(obj->rot.y) * 80.0 * 0.5 * 0.1;
        } else {
            if (tree->fall == 0) {
                pos.x = m->pos.x;
                pos.y = m->pos.y;
                pos.z = m->pos.z + 100.0;
                func_8010815C_26D10C_LooneyLumberjacks(&pos, 0);
                omVibrate(D_8010AF3C_26FEEC_LooneyLumberjacks[tree->team].player[0], 10, 0, 10);
                omVibrate(D_8010AF3C_26FEEC_LooneyLumberjacks[tree->team].player[1], 10, 0, 10);
            }
            m->pos.y = 40.0f;
            if (tree->fall >= 3 && tree->angle < 90.0) {
                tree->speed += 1.0;
                tree->angle += tree->speed;
                v = tree->speed * 0.01;
                d = v;
                m->pos.x += HuMathSin(obj->rot.y) * 80.0 * 0.5 * d;
                m->pos.z += func_800B7890_B8490(obj->rot.y) * 80.0 * 0.5 * d;
                if (tree->angle >= 90.0) {
                    tree->angle = 90.0f;
                    pos.x = m->pos.x;
                    pos.y = m->pos.y;
                    pos.z = m->pos.z + 100.0;
                    func_8010815C_26D10C_LooneyLumberjacks(&pos, 1);
                }
            }
            tree->fall++;
        }
        func_800B37C0_B43C0(m->mtx);
        func_80025884_26484(m->mtx, tree->angle, 0.0f, 0.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801073C4_26C374_LooneyLumberjacks);
#endif

// register allocation (masked 18)
#ifdef NON_MATCHING
LLTree* func_801077F0_26C7A0_LooneyLumberjacks(Vec* pos, Vec* rot, f32 hp) {
    LLTree* tree;
    s32 i;
    s32 j;
    f32 x;
    f32 z;

    tree = D_8010AF40_26FEF0_LooneyLumberjacks;
    for (i = 0; i < 2; i++) {
        if (tree->used == 0) {
            tree->used = 1;
            tree->maxHp = hp;
            tree->hp = hp;
            if (i == 0) {
                for (j = 0; j < 7; j++) {
                    tree->obj->model[j] = func_80018A30_19630(D_8010A7F8_26F7A8_LooneyLumberjacks[j] | 0x450000, 0xB9);
                }
            } else {
                for (j = 0; j < 7; j++) {
                    tree->obj->model[j] = func_80027D3C_2893C(D_8010AF40_26FEF0_LooneyLumberjacks[0].obj->model[j]);
                }
            }
            tree->obj->trans.x = pos->x;
            tree->obj->trans.y = pos->y;
            tree->obj->trans.z = pos->z;
            tree->obj->rot.x = rot->x;
            tree->obj->rot.y = rot->y;
            tree->obj->rot.z = rot->z;
            x = HuMathSin(rot->y) * 100.0 * 1.6;
            z = func_800B7890_B8490(rot->y) * 100.0 * 1.6;
            for (j = 1; j < 6; j++) {
                func_80029714_2A314(tree->obj->model[j], x + pos->x, 55.0f + pos->y, z + pos->z);
                func_8002979C_2A39C(tree->obj->model[j], rot->x, rot->y, rot->z);
            }
            x = HuMathSin(rot->y) * 100.0 * 1.8;
            func_80029714_2A314(tree->obj->model[6], x + pos->x, pos->y + 55.0f, func_800B7890_B8490(rot->y) * 100.0 * 1.8 + pos->z);
            func_8002979C_2A39C(tree->obj->model[6], rot->x, rot->y, rot->z);
            return tree;
        }
        tree++;
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801077F0_26C7A0_LooneyLumberjacks);
#endif

s32 func_80107ADC_26CA8C_LooneyLumberjacks(LLTree* tree, f32 stroke) {
    s32 i;

    if (stroke > 1.0) {
        stroke = 1.0f;
    } else if (stroke < 0.0) {
        stroke = 0.0f;
    }
    for (i = 0; i < 5; i++) {
        if (stroke <= D_8010A814_26F7C4_LooneyLumberjacks[i].limit) {
            break;
        }
    }
    tree->hp -= D_8010A814_26F7C4_LooneyLumberjacks[i].damage;
    if (tree->hp < 0.0) {
        tree->hp = 0.0f;
    }
    if (tree->maxHp == 0.0) {
        return 6;
    }
    for (i = 0; i < 7; i++) {
        if (1.0 - tree->hp / tree->maxHp <= D_8010A690_26F640_LooneyLumberjacks[i]) {
            break;
        }
    }
    if (tree->stage < i) {
        tree->stage = i;
    }
    return tree->stage;
}

f32 func_80107C3C_26CBEC_LooneyLumberjacks(LLTree* tree) {
    f32 max;

    max = tree->maxHp;
    return max != 0.0 ? (f32)(1.0 - tree->hp / max) : 0.0f;
}

void func_80107C8C_26CC3C_LooneyLumberjacks(void) {
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 3, 0, -1, func_80107CE4_26CC94_LooneyLumberjacks);
}

void func_80107CE4_26CC94_LooneyLumberjacks(omObjData* obj) {
    obj->func_ptr = func_80107D48_26CCF8_LooneyLumberjacks;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    InitFadeIn(0, 16);
}

void func_80107D48_26CCF8_LooneyLumberjacks(void) {
}

u16 func_80107D50_26CD00_LooneyLumberjacks(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = SprAnimRead(data);
    DataClose(data);
    return ret;
}

void func_80107D94_26CD44_LooneyLumberjacks(void) {
    LLFx* fx;
    s32 i;

    fx = D_8010AF44_26FEF4_LooneyLumberjacks;
    D_8010AF4C_26FEFC_LooneyLumberjacks[0] = func_80107D50_26CD00_LooneyLumberjacks(0x11);
    D_8010AF4C_26FEFC_LooneyLumberjacks[3] = func_80107D50_26CD00_LooneyLumberjacks(0x12);
    for (i = 0; i < 8; i++) {
        fx->spr = SprCreate(1, 0);
        fx->time = 0;
        fx->used = 0;
        fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
        fx->vel.x = fx->vel.y = fx->vel.z = 0.0f;
        SprAnimSet((s16)fx->spr, 0, D_8010AF4C_26FEFC_LooneyLumberjacks[0], 0);
        SprAttrSet((s16)fx->spr, 0, 0x9000);
        SprPosSet((s16)fx->spr, 0, 0, 0);
        func_800824B4_830B4((s16)fx->spr, 0, 0xFF, 0xFF, 0xBE, 0x40);
        SprScaleSet((s16)fx->spr, 0, 1.0f, 1.0f);
        func_8008221C_82E1C((s16)fx->spr, 0, 1.0f);
        SprPrioSet((s16)fx->spr, 0, i - 0x10);
        func_8008225C_82E5C((s16)fx->spr, 0, 1);
        fx++;
    }
    omAddObj(0x30, 0, 0, -1, func_80107F24_26CED4_LooneyLumberjacks);
}

void func_80107F24_26CED4_LooneyLumberjacks(omObjData* obj) {
    LLFx* fx;
    s32 i;

    fx = D_8010AF44_26FEF4_LooneyLumberjacks;
    for (i = 0; i < 8; i++) {
        if (fx->used != 0) {
            SprPos3DSet((s16)fx->spr, 0, 0, fx->pos.x, fx->pos.y, fx->pos.z);
            fx->pos.x += fx->vel.x;
            fx->pos.y += fx->vel.y;
            fx->pos.z += fx->vel.z;
            if (--fx->time < 0) {
                fx->time = 0;
                fx->used = 0;
                SprAttrSet((s16)fx->spr, 0, 0x8000);
            }
        }
        fx++;
    }
}

// register allocation (masked 27)
#ifdef NON_MATCHING
s32 func_80107FE8_26CF98_LooneyLumberjacks(s32 anim, Vec* pos, Vec* vel) {
    LLFx* fx;
    s32 i;

    fx = D_8010AF44_26FEF4_LooneyLumberjacks;
    for (i = 0; i < 8; i++) {
        if (fx->used == 0) {
            fx->used = 1;
            fx->time = 31;
            fx->pos.x = pos->x;
            fx->pos.y = pos->y;
            fx->pos.z = pos->z;
            if (vel != NULL) {
                fx->vel.x = vel->x;
                fx->vel.y = vel->y;
                fx->vel.z = vel->z;
            } else {
                fx->vel.x = fx->vel.y = fx->vel.z = 0.0f;
            }
            SprAnimSet((s16)fx->spr, 0, *(anim >= 0 ? &D_8010AF4C_26FEFC_LooneyLumberjacks[anim] : D_8010AF4C_26FEFC_LooneyLumberjacks), 0);
            SprAttrReset((s16)fx->spr, 0, 0x8000);
            SprPos3DSet((s16)fx->spr, 0, 0, fx->pos.x, fx->pos.y, fx->pos.z);
            func_800824B4_830B4((s16)fx->spr, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            SprScaleSet((s16)fx->spr, 0, 1.0f, 1.0f);
            SprBankSet((s16)fx->spr, 0, 0);
            func_8008221C_82E1C((s16)fx->spr, 0, 1.0f);
            return i;
        }
        fx++;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80107FE8_26CF98_LooneyLumberjacks);
#endif

// register allocation (masked 25)
#ifdef NON_MATCHING
void func_8010815C_26D10C_LooneyLumberjacks(Vec* pos, s32 kind) {
    Vec p;
    f32* size;
    s32 i;
    s32 fx;

    size = D_8010A8A8_26F858_LooneyLumberjacks + kind;
    for (i = 0; i < 3; i++) {
        p.x = D_8010A83C_26F7EC_LooneyLumberjacks[kind][i].x * *size + pos->x;
        p.y = D_8010A83C_26F7EC_LooneyLumberjacks[kind][i].y * *size + pos->y;
        p.z = D_8010A83C_26F7EC_LooneyLumberjacks[kind][i].z * *size + pos->z;
        fx = func_80107FE8_26CF98_LooneyLumberjacks(-1, &p, kind == 0 ? NULL : &D_8010A884_26F834_LooneyLumberjacks[i]);
        if (fx >= 0) {
            SprScaleSet((s16)D_8010AF44_26FEF4_LooneyLumberjacks[fx].spr, 0, *size, *size);
            func_800824B4_830B4((s16)D_8010AF44_26FEF4_LooneyLumberjacks[fx].spr, 0, 0xFF, 0xFF, 0xBE, 0x40);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_8010815C_26D10C_LooneyLumberjacks);
#endif

// register allocation (masked 6)
#ifdef NON_MATCHING
void func_801082E8_26D298_LooneyLumberjacks(void) {
    omObjData* obj;
    HuSprite_Unk84_Struct* spr;
    s32 i;

    D_8010AF4C_26FEFC_LooneyLumberjacks[4] = func_80107D50_26CD00_LooneyLumberjacks(0x45000A);
    spr = SprAnimGet(D_8010AF4C_26FEFC_LooneyLumberjacks[4]);
    obj = D_8010AF34_26FEE4_LooneyLumberjacks = omAddObj(0x1D, 13, 0, -1, func_80108418_26D3C8_LooneyLumberjacks);
    for (i = 1; i < 13; i++) {
        if (i == 1) {
            obj->model[1] = func_80109164_26E114_LooneyLumberjacks(spr, 1.0f);
        } else {
            obj->model[i] = func_80109D94_26ED44_LooneyLumberjacks(spr, obj->model[1], 1.0f);
        }
        func_800298A4_2A4A4(obj->model[i], 4, 4);
        D_800FC834_FD434[obj->model[i]].unk40 = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801082E8_26D298_LooneyLumberjacks);
#endif

// register allocation (masked 10)
#ifdef NON_MATCHING
void func_80108418_26D3C8_LooneyLumberjacks(omObjData* obj) {
    HuSprite_Unk84_Struct* spr;
    HmfModel* m;
    s32 i;

    spr = SprAnimGet(D_8010AF4C_26FEFC_LooneyLumberjacks[4]);
    for (i = 1; i < 13; i++) {
        if (obj->model[i] != -1) {
            m = &D_800FC834_FD434[obj->model[i]];
            if (!(m->unk18 & 4)) {
                func_8010A1E4_26F194_LooneyLumberjacks(D_8010AF48_26FEF8_LooneyLumberjacks[i].r, D_8010AF48_26FEF8_LooneyLumberjacks[i].g, D_8010AF48_26FEF8_LooneyLumberjacks[i].b);
                func_8010A014_26EFC4_LooneyLumberjacks(obj->model[i], spr, (s32)m->unk40, 1.0f);
                m->unk40 += 1.0;
                if ((s32)m->unk40 >= 16) {
                    m->unk40 = 0.0f;
                    m->unk18 |= 4;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80108418_26D3C8_LooneyLumberjacks);
#endif

// register allocation (masked 2)
#ifdef NON_MATCHING
s16 func_80108550_26D500_LooneyLumberjacks(Vec* pos, Vec* rot, Vec* scale) {
    HuSprite_Unk84_Struct* spr;
    HmfModel* m;
    s16* pm;
    LLColor c;
    s32 i;

    spr = SprAnimGet(D_8010AF34_26FEE4_LooneyLumberjacks->work[1]);
    for (i = 1; i < 13; i++) {
        pm = &D_8010AF34_26FEE4_LooneyLumberjacks->model[i];
        m = &D_800FC834_FD434[*pm];
        if (m->unk18 & 4) {
            func_8010A014_26EFC4_LooneyLumberjacks(*pm, spr, 0, 1.0f);
            m->unk40 = 0.0f;
            func_80029714_2A314(D_8010AF34_26FEE4_LooneyLumberjacks->model[i], pos->x, pos->y, pos->z);
            func_8002979C_2A39C(D_8010AF34_26FEE4_LooneyLumberjacks->model[i], rot->x, rot->y, rot->z);
            func_800297E8_2A3E8(D_8010AF34_26FEE4_LooneyLumberjacks->model[i], scale->x, scale->y, scale->z);
            func_800298A4_2A4A4(D_8010AF34_26FEE4_LooneyLumberjacks->model[i], 4, 0);
            c.r = D_8010AFA8_26FF58_LooneyLumberjacks[0];
            c.g = D_8010AFA8_26FF58_LooneyLumberjacks[1];
            c.b = D_8010AFA8_26FF58_LooneyLumberjacks[2];
            D_8010AF48_26FEF8_LooneyLumberjacks[i] = c;
            return D_8010AF34_26FEE4_LooneyLumberjacks->model[i];
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80108550_26D500_LooneyLumberjacks);
#endif

void func_80108728_26D6D8_LooneyLumberjacks(omObjData* obj) {
    LLTeam* t;
    Vec pos;
    s32 i;
    s32 mdl;

    t = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (t != NULL) {
        for (i = 0; i < 3; i++) {
            pos.x = D_8010A8C0_26F870_LooneyLumberjacks[t->team][i].x;
            pos.z = D_8010A8C0_26F870_LooneyLumberjacks[t->team][i].z;
            pos.y = D_8010A8C0_26F870_LooneyLumberjacks[t->team][i].y - t->cut * 80.0 + 40.0;
            func_8010A1E4_26F194_LooneyLumberjacks(D_8010A8B4_26F864_LooneyLumberjacks[i].r, D_8010A8B4_26F864_LooneyLumberjacks[i].g, D_8010A8B4_26F864_LooneyLumberjacks[i].b);
            mdl = (s16)func_80108550_26D500_LooneyLumberjacks(&pos, &D_8010A908_26F8B8_LooneyLumberjacks[t->team], &D_8010A920_26F8D0_LooneyLumberjacks);
            if (mdl >= 0) {
                func_800B37C0_B43C0(D_800FC834_FD434[mdl].mtx);
                if (t->dir == 1) {
                    func_80025884_26484(D_800FC834_FD434[mdl].mtx, 0.0f, 0.0f, -90.0f);
                } else {
                    func_80025884_26484(D_800FC834_FD434[mdl].mtx, 0.0f, 0.0f, 90.0f);
                }
            }
        }
    }
}

void func_801088FC_26D8AC_LooneyLumberjacks(f32* a, f32* b, f32* out, f32 t) {
    s32 i;

    for (i = 0; i < 16; i++) {
        out[i] = a[i] + t * (b[i] - a[i]);
    }
}

// register allocation (raw 2, masked 0)
#ifdef NON_MATCHING
f32 func_80108944_26D8F4_LooneyLumberjacks(f32 target, f32 cur, f32 step) {
    f64 d;

    if (cur < target) {
        if (fabs(target - cur) > step) {
            return step;
        }
        return fabsf(target - cur);
    }
    d = fabs(cur - target);
    if (d > step) {
        return -step;
    }
    return -d;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80108944_26D8F4_LooneyLumberjacks);
#endif

// register allocation (masked 18)
#ifdef NON_MATCHING
f32 func_801089C0_26D970_LooneyLumberjacks(f32 target, f32 cur, f32 step) {
    f32 d;
    f32 v;
    f64 e;

    LL_WRAP(target);
    LL_WRAP(cur);
    d = func_800B0D98_B1998(target - cur + 360.0, 360.0);
    if (d < 180.0) {
        v = step;
        if (d <= step) {
            v = d;
        }
    } else {
        e = 360.0 - d;
        if (e <= step) {
            v = -e;
        } else {
            v = -step;
        }
    }
    cur = v + cur;
    LL_WRAP(cur);
    return cur;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_801089C0_26D970_LooneyLumberjacks);
#endif

void func_80108B80_26DB30_LooneyLumberjacks(omObjData* obj, void* p) {
    obj->work[0] = (u32)p >> 24;
    obj->work[1] = (u32)p >> 16;
    obj->work[2] = (u32)p >> 8;
    obj->work[3] = (u32)p;
}

void* func_80108BA0_26DB50_LooneyLumberjacks(omObjData* obj) {
    LLPack u;

    u.b.a = obj->work[0];
    u.b.b = obj->work[1];
    u.b.c = obj->work[2];
    u.b.d = obj->work[3];
    return u.p;
}

void* func_80108BF4_26DBA4_LooneyLumberjacks(s32 size) {
    void* p;

    p = func_80027154_27D54(size, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(p, 0, size);
    return p;
}

void func_80108C40_26DBF0_LooneyLumberjacks(omObjData* obj) {
    HmfData* hmf;
    HmfMotionSlot* mot;
    LLPlayer* p;
    LLBlendBuf* b;
    s32 i;

    hmf = D_800FC834_FD434[obj->model[0]].hmf;
    mot = &D_800F92B4_F9EB4[D_800FC834_FD434[obj->motion[0]].unk02];
    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    p->frame = 0.0f;
    p->motA = -1;
    p->motB = -1;
    p->weight = 0.0f;
    b = func_80108BF4_26DBA4_LooneyLumberjacks(sizeof(LLBlendBuf) * 3);
    p->blend = b;
    for (i = 0; i < 3; i++) {
        b[i].unk_08 = func_80108BF4_26DBA4_LooneyLumberjacks(hmf->unk16 << 6);
        b[i].unk_04 = func_80108BF4_26DBA4_LooneyLumberjacks(hmf->unk16 * 2);
        b[i].unk_00 = mot->unk02;
        b[i].unk_02 = 1;
    }
}

void func_80108D58_26DD08_LooneyLumberjacks(omObjData* obj) {
    LLPlayer* p;
    HmfData* hmf;
    s32 slot[2];
    s32 i;

    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (p->motA >= 0 && p->motB >= 0) {
        slot[0] = D_800FC834_FD434[obj->motion[p->motA]].unk02;
        slot[1] = D_800FC834_FD434[obj->motion[p->motB]].unk02;
        hmf = D_800FC834_FD434[obj->model[0]].hmf;
        for (i = 0; i < 2; i++) {
            D_800FD43C_FE03C = p->blend[i].unk_08;
            D_800FC8F0_FD4F0 = p->blend[i].unk_04;
            D_800F93D0_F9FD0 = 0;
            guMtxIdentF(D_801016D0_1022D0[0]);
            func_80039B54_3A754(hmf, p->frame, &D_800F92B4_F9EB4[slot[i]], 1);
            D_800FD470_FE070 = 0;
            func_80023680_24280(hmf, 0, -1);
        }
        memcpy(p->blend[2].unk_04, p->blend[1].unk_04, hmf->unk16 * 2);
        for (i = 0; i < hmf->unk16; i++) {
            func_801088FC_26D8AC_LooneyLumberjacks((f32*)p->blend[0].unk_08 + i * 16, (f32*)p->blend[1].unk_08 + i * 16, (f32*)p->blend[2].unk_08 + i * 16, p->weight);
        }
        func_80023A08_24608(obj->model[0], (s16*)&p->blend[2], 0);
    }
}

// register allocation (masked 73)
#ifdef NON_MATCHING
void func_80108F50_26DF00_LooneyLumberjacks(omObjData* obj, s16 a, s16 b, f32 weight, f32 frame) {
    LLPlayer* p;
    s16* mots;
    s16 ma;
    s16 mb;
    s32 n;

    p = func_80108BA0_26DB50_LooneyLumberjacks(obj);
    if (b < 0) {
        p->motB = -1;
        p->motA = -1;
        D_800FC834_FD434[obj->model[0]].unk02 = func_80029E14_2AA14(obj->motion[a]);
        return;
    }
    mots = obj->motion;
    ma = mots[a];
    mb = mots[b];
    if (ma != -1) {
        if (mb != -1) {
            n = D_800F92B4_F9EB4[D_800FC834_FD434[ma].unk02].unk02;
            if ((f32)n <= frame) {
                frame = n - 1;
            }
            n = D_800F92B4_F9EB4[D_800FC834_FD434[mb].unk02].unk02;
            if ((f32)n <= frame) {
                frame = n - 1;
            }
            if (weight < 0.0) {
                weight = 0.0f;
            } else if (weight >= 1.0) {
                weight = 1.0f;
            }
            p->frame = frame;
            p->motA = a;
            p->motB = b;
            p->weight = weight;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_80108F50_26DF00_LooneyLumberjacks);
#endif

s32 func_80109164_26E114_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, f32 alpha) {
    HmfData* hmf;
    Gfx* buf;
    Gfx* gfx;
    s32 size;
    s32 idx;
    s32 fmt;
    s32 i;

    buf = gfx = HuMemAlloc(0x10000);
    idx = func_80027FA4_28BA4(0x4C1, buf, 4);
    hmf = D_800FC834_FD434[idx].hmf;
    hmf->unk64->unk50 |= 0x01010000;
    HuMemFree(hmf->unk3C);
    hmf->unk3C = func_80027154_27D54(sizeof(HmfDisp), D_800FA1AA_FADAA);
    func_8010A1FC_26F1AC_LooneyLumberjacks(spr, hmf, 1.0f, 0, 0);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010AA20_26F9D0_LooneyLumberjacks));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (spr->unk18 & 0x8000) {
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    } else {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    hmf->unk3C->unk10 = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk10, size);
    HuMemFree(buf);
    buf = gfx = HuMemAlloc(0x10000);
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
    hmf->unk3C->unk14 = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk14, size);
    HuMemFree(buf);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = hmf->unk3C->unk00[i + 1] = func_80027154_27D54(0x100, hmf->unk0E);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x04, osVirtualToPhysical(spr->unk00->unk00));
        gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk10));
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, alpha * 255.0f);
        gDPPipeSync(gfx++);
        gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk14));
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
    hmf->unk3C->unk00[0] = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    return idx;
}

s32 func_80109D94_26ED44_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, u16 src, f32 alpha) {
    HmfModel* m;
    HmfData* from;
    HmfData* hmf;
    Gfx* gfx;
    s32 mdl;
    s32 i;

    m = &D_800FC834_FD434[src];
    from = m->hmf;
    mdl = func_80027FA4_28BA4(m->unk18, NULL, 4);
    hmf = D_800FC834_FD434[mdl].hmf;
    hmf->unk64->unk50 = from->unk64->unk50;
    HuMemFree(hmf->unk3C);
    hmf->unk3C = func_80027154_27D54(sizeof(HmfDisp), D_800FA1AA_FADAA);
    hmf->unk3C->unk10 = from->unk3C->unk10;
    hmf->unk3C->unk14 = from->unk3C->unk14;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = hmf->unk3C->unk00[i + 1] = func_80027154_27D54(0x100, hmf->unk0E);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x04, osVirtualToPhysical(spr->unk00->unk00));
        gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk10));
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, alpha * 255.0f);
        gDPPipeSync(gfx++);
        gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk14));
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
    hmf->unk3C->unk00[0] = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    return mdl;
}

// register allocation (masked 6)
#ifdef NON_MATCHING
void func_8010A014_26EFC4_LooneyLumberjacks(u16 mdl, HuSprite_Unk84_Struct* spr, u16 frame, f32 alpha) {
    HmfData* hmf;
    Gfx* gfx;

    hmf = D_800FC834_FD434[mdl].hmf;
    gfx = hmf->unk3C->unk00[0] = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    gDPPipeSync(gfx++);
    gSPSegment(gfx++, 0x04, osVirtualToPhysical(spr->unk00[frame].unk00));
    gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk10));
    gDPSetPrimColor(gfx++, 0, 0, D_8010AFA8_26FF58_LooneyLumberjacks[0], D_8010AFA8_26FF58_LooneyLumberjacks[1], D_8010AFA8_26FF58_LooneyLumberjacks[2], alpha * 255.0f);
    gDPPipeSync(gfx++);
    gSPDisplayList(gfx++, osVirtualToPhysical(hmf->unk3C->unk14));
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_35_LooneyLumberjacks/2677B0", func_8010A014_26EFC4_LooneyLumberjacks);
#endif

void func_8010A1E4_26F194_LooneyLumberjacks(u8 r, u8 g, u8 b) {
    D_8010AFA8_26FF58_LooneyLumberjacks[0] = r;
    D_8010AFA8_26FF58_LooneyLumberjacks[1] = g;
    D_8010AFA8_26FF58_LooneyLumberjacks[2] = b;
}

s32 func_8010A1FC_26F1AC_LooneyLumberjacks(HuSprite_Unk84_Struct* spr, HmfData* hmf, f32 scale, u16 x, u16 y) {
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
        size = ((w + 1) & 0xFFFE) * h * 4;
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
