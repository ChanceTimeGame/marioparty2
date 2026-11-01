#include "ovl_04.h"

__asm__(".section .rodata");
const u8 D_80109190_FEE50_HammerSlammer[] = "\202r\202s\202`\202q\202s";

/* The minigame's set-up. */
void func_80102800_F84C0_HammerSlammer(void) {
    u8 cam;

    func_80020D20_21920(0x20);
    omInitObjMan(0x80, 0xA);
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_80053FC8_54BC8();
    func_80053FE8_54BE8(0x3D);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 15.0f, 2000.0f, 8000.0f);
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 0.0f, 90.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, 0.0f, 65.0f, 90.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    omAddObj(0, 0, 0, -1, func_80102A24_F86E4_HammerSlammer);
    omSetStatBit(omAddObj(8, 0, 0, -1, func_80103484_F9144_HammerSlammer), 0xA0);
    D_80109B50_FF810_HammerSlammer = omAddObj(3, 0x21, 0x21, -1, func_8010363C_F92FC_HammerSlammer);
    D_80109B90_FF850_HammerSlammer = omAddObj(3, 8, 8, -1, func_80103ECC_F9B8C_HammerSlammer);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_8007273C_7333C(D_80109190_FEE50_HammerSlammer, 1);
    InitFadeIn(0, 0x10);
}

/* Picks the player, the items on the panels and, for a CPU, how hard it hits. */
void func_80102A24_F86E4_HammerSlammer(omObjData* obj) {
    s32 i;
    s16 r;

    D_80109B9A_FF85A_HammerSlammer = 0;
    D_80109B54_FF814_HammerSlammer = 0;
    D_80109B94_FF854_HammerSlammer = 0;
    D_80109BF8_FF8B8_HammerSlammer = 0;
    D_80109BD2_FF892_HammerSlammer = 0;
    D_80109C2C_FF8EC_HammerSlammer = 0;
    D_80109C30_FF8F0_HammerSlammer = 0;
    D_80109BD1_FF891_HammerSlammer = 0;
    D_80109C29_FF8E9_HammerSlammer = 1;
    D_80109C38_FF8F8_HammerSlammer[0] = 10;
    D_80109C28_FF8E8_HammerSlammer = 0;
    D_80109B58_FF818_HammerSlammer = 24.0f;
    D_80109B98_FF858_HammerSlammer = 0;
    D_80109BD0_FF890_HammerSlammer = 0;
    for (i = 0; i < 5; i++) {
        D_80109C38_FF8F8_HammerSlammer[i + 1] = D_800CAFD8[i];
    }
    bzero(&D_80109B20_FF7E0_HammerSlammer, 0x2C);
    bzero(D_80109B60_FF820_HammerSlammer, 0x1C);
    bzero(D_80109C00_FF8C0_HammerSlammer, 0x1C);
    bzero(D_80109BB0_FF870_HammerSlammer, 0x1C);
    bzero(D_80109BA0_FF860_HammerSlammer, 0x10);
    bzero(D_80109B80_FF840_HammerSlammer, 0x10);
    D_80109BF0_FF8B0_HammerSlammer = 285.0f;
    D_80109C34_FF8F4_HammerSlammer = 0.0f;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            D_80109B20_FF7E0_HammerSlammer.player = i;
            D_80109B20_FF7E0_HammerSlammer.port = gPlayers[i].port;
            D_80109B20_FF7E0_HammerSlammer.character = gPlayers[i].character;
            break;
        }
    }
    D_80109B20_FF7E0_HammerSlammer.cpu = (gPlayers[D_80109B20_FF7E0_HammerSlammer.player].flags & 1)
        ? gPlayers[D_80109B20_FF7E0_HammerSlammer.player].cpu_difficulty : -1;
    if (D_80109B20_FF7E0_HammerSlammer.cpu != -1) {
        s16 odds[4] = { 30, 20, 10, 5 };

        if ((u8)(rand8() % 100) < odds[D_80109B20_FF7E0_HammerSlammer.cpu]) {
            D_80109B20_FF7E0_HammerSlammer.cpuTimer = 0x21;
            D_80109B98_FF858_HammerSlammer = 1;
        } else {
            f32 lo[8] = { 0.0625f, 5.0f, 11.0f, 17.0f, 22.0f, 27.0f, 30.0f, 255.0f };
            f32 hi[8] = { 10.0f, 18.5f, 22.0f, 25.5f, 28.0f, 30.5f, 32.5f, 42.0f };

            r = (u8)(rand8() % 100);
            for (i = 0; i < 5; i++) {
                if (r < D_800CAFE4[i]) {
                    if ((i == 0 && (u8)(rand8() % 10) < 7) || (i == 1 && (u8)(rand8() % 10) < 3)) {
                        D_80109B20_FF7E0_HammerSlammer.cpuTimer = 0x21;
                        D_80109B98_FF858_HammerSlammer = i + 2;
                    } else {
                        D_80109B20_FF7E0_HammerSlammer.cpuTimer = (lo[i + 1] + lo[i + 2]) / 2.0 + 1.0;
                    }
                    break;
                }
                r -= D_800CAFE4[i];
            }
            if (i == 5) {
                D_80109B20_FF7E0_HammerSlammer.cpuTimer = 0x21;
            }
        }
    }
    D_80109030_FECF0_HammerSlammer[6] += D_80109098_FED58_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character];
    D_8010274C_10334C.x = -11.0f;
    D_8010274C_10334C.y = 230.0f;
    D_8010274C_10334C.z = 0.0f;
    D_800FD474_FE074.x = 0.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 2140.0f;
    func_8002838C_28F8C(0, func_801074B0_FD170_HammerSlammer, 0);
    obj->func_ptr = func_80102FB0_F8C70_HammerSlammer;
}

/* The minigame's state machine: 0 intro, 1 aim, 3 swing, 5 hammer down, 6 item, 7 coin item,
   8 nothing, 9 fade out. */
void func_80102FB0_F8C70_HammerSlammer(omObjData* obj) {
    D_80109BF8_FF8B8_HammerSlammer++;
    switch (D_80109B54_FF814_HammerSlammer) {
    case 0:
        if (D_80109B94_FF854_HammerSlammer == 0 && D_80109B9A_FF85A_HammerSlammer == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x28);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x3C) {
            func_800691FC_69DFC(0);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x87) {
            func_800691FC_69DFC(0xA, 0xA, 0xA0, 0x20);
        }
        if (D_80109B94_FF854_HammerSlammer != 0x96) {
            break;
        }
        D_80109B54_FF814_HammerSlammer = 1;
        D_80109B94_FF854_HammerSlammer = 0;
    case 1:
        if (D_80109B94_FF854_HammerSlammer % 30 == 0 && D_80109B94_FF854_HammerSlammer != 0) {
            func_8006D4D0_6E0D0(10 - D_80109B94_FF854_HammerSlammer / 30);
        }
        break;
    case 3:
        if (D_80109B94_FF854_HammerSlammer == 0) {
            func_8006D518_6E118();
        }
        break;
    case 5:
        if (D_80109B94_FF854_HammerSlammer == 0) {
            func_800794A8_7A0A8(100);
            func_800691FC_69DFC(3);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x29) {
            if ((u8)(D_80109B20_FF7E0_HammerSlammer.result + 1) < 2) {
                D_80109B54_FF814_HammerSlammer = 8;
            } else if (D_80109C38_FF8F8_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] == 3) {
                D_80109B54_FF814_HammerSlammer = 7;
            } else {
                D_80109B54_FF814_HammerSlammer = 6;
            }
            D_80109B94_FF854_HammerSlammer = 0;
            if (D_80109B54_FF814_HammerSlammer != 8) {
                gPlayers[D_80109B20_FF7E0_HammerSlammer.player].coins_mg_bonus = (u16)D_80109C38_FF8F8_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result];
            } else {
                gPlayers[D_80109B20_FF7E0_HammerSlammer.player].coins_mg_bonus = -1;
            }
            if (_CheckFlag(0xC) != 0) {
                D_80109B54_FF814_HammerSlammer = 9;
            }
        }
        break;
    case 8:
        if (D_80109B94_FF854_HammerSlammer == 1) {
            func_800691FC_69DFC(0x10);
        }
        if (D_80109B94_FF854_HammerSlammer == 1 && D_80109B9A_FF85A_HammerSlammer == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x56);
            func_80079518_7A118(0x7F);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x85) {
            D_80109B54_FF814_HammerSlammer = 9;
            D_80109B94_FF854_HammerSlammer = 0;
        }
        break;
    case 7:
        if (D_80109B94_FF854_HammerSlammer == 1) {
            func_800691FC_69DFC(0x18);
        }
        if (D_80109B94_FF854_HammerSlammer == 1 && D_80109B9A_FF85A_HammerSlammer == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x54);
            func_80079518_7A118(0x7F);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x90) {
            D_80109B54_FF814_HammerSlammer = 9;
            D_80109B94_FF854_HammerSlammer = 0;
        }
        break;
    case 6:
        if (D_80109B94_FF854_HammerSlammer == 1) {
            func_800691FC_69DFC(0x17);
        }
        if (D_80109B94_FF854_HammerSlammer == 1 && D_80109B9A_FF85A_HammerSlammer == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x53);
            func_80079518_7A118(0x7F);
        }
        if (D_80109B94_FF854_HammerSlammer == 0x87) {
            D_80109B54_FF814_HammerSlammer = 9;
            D_80109B94_FF854_HammerSlammer = 0;
        }
        break;
    case 9:
        if (D_80109B94_FF854_HammerSlammer == 1) {
            InitFadeOut(0, 0x14);
        } else if (D_80109B94_FF854_HammerSlammer >= 25) {
            D_80109B9A_FF85A_HammerSlammer = 1;
        }
        break;
    }
    D_80109B94_FF854_HammerSlammer++;
    if (D_80109B9A_FF85A_HammerSlammer != 0 || D_801011FC_101DFC != 0) {
        if (D_801011FC_101DFC != 0) {
            if (D_80109BD0_FF890_HammerSlammer == 0) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_80109BD0_FF890_HammerSlammer++;
            if (D_80109BD0_FF890_HammerSlammer < 25) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        MBDBackKill();
        func_80050AE0_516E0();
        omOvlReturnEx(1);
    }
}

/* The HUD and item sprites. */
void func_80103484_F9144_HammerSlammer(omObjData* obj) {
    s16 anim[11];
    s16 i;

    for (i = 0; i < 11; i++) {
        anim[i] = func_8001A2F8_1AEF8(D_801090C8_FED88_HammerSlammer[i]);
        D_80109BD8_FF898_HammerSlammer[i] = func_8001AAAC_1B6AC(anim[i], 0, 0);
        espDispOff(D_80109BD8_FF898_HammerSlammer[i]);
    }
    obj->func_ptr = func_80103554_F9214_HammerSlammer;
}

/* The landing shake: alternates sign each frame and decays. */
void func_80103554_F9214_HammerSlammer(omObjData* obj) {
    func_80054018_54C18(0, -D_80109C29_FF8E9_HammerSlammer * D_80109BD1_FF891_HammerSlammer);
    D_80109BF4_FF8B4_HammerSlammer = (f32)D_80109C29_FF8E9_HammerSlammer * (f32)D_80109BD1_FF891_HammerSlammer;
    D_8010274C_10334C.y = (D_80109C29_FF8E9_HammerSlammer * D_80109BD1_FF891_HammerSlammer) * 2.34375 + 230.0;
    D_80109C29_FF8E9_HammerSlammer = -D_80109C29_FF8E9_HammerSlammer;
    D_80109BD1_FF891_HammerSlammer -= D_80109C29_FF8E9_HammerSlammer == 1 && D_80109BD1_FF891_HammerSlammer > 0;
}

/* Loads every model. */
void func_8010363C_F92FC_HammerSlammer(omObjData* obj) {
    s32 tbl[10][6] = {
        { 0xD1, 0xD1, 0xD1, 0xD1, 0xD1, 0xD1 },
        { 0x71, 0x71, 0x71, 0x71, 0x71, 0x71 },
        { 0x72, 0x72, 0x72, 0x72, 0x72, 0x72 },
        { 0x73, 0x73, 0x73, 0x73, 0x73, 0x73 },
        { 0x19, 0x19, 0x19, 0x19, 0x19, 0x19 },
        { 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0 },
        { 0x57, 0x57, 0x57, 0x57, 0x57, 0x57 },
        { 0x56, 0x56, 0x56, 0x56, 0x56, 0x56 },
        { 0x54, 0x54, 0x54, 0x54, 0x54, 0x54 },
    };
    MgWork* w;
    u8 chr;
    s32 dir;
    s16 i;

    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    chr = gPlayers[D_80109B20_FF7E0_HammerSlammer.player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    obj->model[0] = LoadFormFile(dir | tbl[0][chr], 0x4A9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_80109C1C_FF8DC_HammerSlammer[0] = func_80025384_25F84(obj->model[0], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, 0) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
    func_80025554_26154(obj->model[0], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer[0]);
    omSetTra(obj, 500.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 270.0f, 0.0f);
    D_80109BCC_FF88C_HammerSlammer = 0;
    obj->model[15] = LoadFormFile(dir | tbl[0][chr], 0x4AD);
    HmfModelObjAttrSet(obj->model[15], 0x600, 0x400);
    func_80029714_2A314(obj->model[15], D_80109068_FED28_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] - 400.0, D_80109080_FED40_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character], 0.0f);
    func_8002979C_2A39C(obj->model[15], 0.0f, 270.0f, 0.0f);
    obj->model[16] = LoadFormFile(dir | tbl[0][chr], 0x4AD);
    HmfModelObjAttrSet(obj->model[16], 0x600, 0x400);
    func_80029714_2A314(obj->model[16], D_80109068_FED28_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] - 400.0, D_80109080_FED40_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character], 0.0f);
    func_8002979C_2A39C(obj->model[16], 0.0f, 270.0f, 0.0f);
    obj->model[1] = LoadFormFile(dir | tbl[1][chr], 0x49D);
    obj->model[2] = LoadFormFile(dir | tbl[2][chr], 0x49D);
    obj->model[3] = LoadFormFile(dir | tbl[3][chr], 0x49D);
    func_80019E84_1AA84(obj, 0, dir | tbl[4][chr], 1, 0);
    obj->model[5] = LoadFormFile(dir | tbl[5][chr], 0x49D);
    func_80029E80_2AA80(obj->model[5], 2, 2);
    obj->model[6] = LoadFormFile(dir | tbl[6][chr], 0x49D);
    func_80029E80_2AA80(obj->model[6], 2, 2);
    func_8002C524_2D124(obj->model[D_80109BCC_FF88C_HammerSlammer], D_800FC834_FD434[obj->motion[0]].unk02, 1);
    func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[5]);
    func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
    obj->model[7] = LoadFormFile(dir | tbl[7][chr], 0x49D);
    obj->model[8] = LoadFormFile(dir | tbl[8][chr], 0x49D);
    obj->model[9] = LoadFormFile(dir | tbl[9][chr], 0x49D);
    obj->model[10] = LoadFormFile(0x140001, 0x6A9);
    HmfModelObjAttrSet(obj->model[10], 0x600, 0x400);
    func_800298A4_2A4A4(obj->model[10], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[10], obj->model[0], "item_hook");
    obj->model[11] = LoadFormFile(0x140002, 0x499);
    func_80029E80_2AA80(obj->model[11], 2, 2);
    HmfModelObjAttrSet(obj->model[11], 0x600, 0x400);
    func_80029714_2A314(obj->model[11], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[11], 1.0f, 1.0f, 1.0f);
    obj->model[12] = LoadFormFile(0x140000, 0x49D);
    HmfModelObjAttrSet(obj->model[12], 0x600, 0x400);
    func_80029714_2A314(obj->model[12], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[12], 1.0f, 1.0f, 1.0f);
    obj->model[14] = LoadFormFile(0x140004, 0x499);
    HmfModelObjAttrSet(obj->model[14], 0x600, 0x400);
    obj->model[13] = LoadFormFile(0x140003, 0x499);
    HmfModelObjAttrSet(obj->model[13], 0x600, 0x400);
    obj->model[17] = LoadFormFile(0x140005, 0x499);
    HmfModelObjAttrSet(obj->model[17], 0x600, 0x400);
    func_80029714_2A314(obj->model[17], 0.0f, 0.0f, 0.0f);
    obj->model[18] = LoadFormFile(0x140006, 0x499);
    HmfModelObjAttrSet(obj->model[18], 0x600, 0x400);
    func_80029714_2A314(obj->model[18], 0.0f, 0.0f, 0.0f);
    obj->model[19] = LoadFormFile(0x140007, 0x499);
    HmfModelObjAttrSet(obj->model[19], 0x600, 0x400);
    func_80029714_2A314(obj->model[19], 0.0f, 0.0f, 0.0f);
    obj->model[28] = LoadFormFile(0x800B0, 0x4BD);
    HmfModelObjAttrSet(obj->model[28], 0x600, 0x400);
    func_80029714_2A314(obj->model[28], -240.0f, 80.0f, 30.0f);
    func_8002979C_2A39C(obj->model[28], 0.0f, 7.5f, 0.0f);
    func_800297E8_2A3E8(obj->model[28], 1.0f, 0.95f, 1.0f);
    obj->model[29] = LoadFormFile(0x800B0, 0x49D);
    obj->model[30] = LoadFormFile(0x800B3, 0x49D);
    obj->model[31] = LoadFormFile(0x800B2, 0x49D);
    obj->model[32] = LoadFormFile(0x340000, 0x4BD);
    HmfModelObjAttrSet(obj->model[32], 0x600, 0x200);
    func_80029714_2A314(obj->model[32], -230.0f, 125.0f, 135.0f);
    func_800297E8_2A3E8(obj->model[32], 2.0f, 2.0f, 1.0f);
    func_80029B80_2A780(obj->model[16], obj->model[3]);
    func_80029C74_2A874(obj->model[16], 9.0f);
    for (i = 0; i < 7; i++) {
        obj->model[i + 20] = LoadFormFile(0x3B000E, 0x49D);
        HmfModelObjAttrSet(obj->model[i + 20], 0x600, 0);
        func_800297E8_2A3E8(obj->model[i + 20], 0.75f, 0.75f, 0.75f);
    }
    obj->func_ptr = func_80104000_F9CC0_HammerSlammer;
}

/* Eight spark models. */
void func_80103ECC_F9B8C_HammerSlammer(omObjData* obj) {
    s16 i;

    for (i = 0; i < 8; i++) {
        obj->model[i] = LoadFormFile(0x1001F, 0x49D);
        HmfModelObjAttrSet(obj->model[i], 0x600, 0x400);
        if (i == 0) {
            omSetTra(obj, 0.0f, 100.0f, 0.0f);
            omSetSca(obj, 0.5f, 0.5f, 0.5f);
        } else {
            func_80029714_2A314(obj->model[i], 0.0f, 100.0f, 0.0f);
            func_800297E8_2A3E8(obj->model[i], 0.5f, 0.5f, 0.5f);
        }
    }
    obj->func_ptr = NULL;
}

/* The player, the hammer and the machine, per state: 0 walks in, 1 winds up (A charges the power,
   B swings; a CPU presses until it reaches its target), 2 swing, 3 the puck flies, 4 it hits a
   panel, 5 the item arcs to the player (the win pose), 6 / 7 / 8 the result poses and their voices.
   Then the bell's ring, the Toad's cheer, and the sparkle trail on the arc. */
#ifdef NON_MATCHING
void func_80104000_F9CC0_HammerSlammer(omObjData* obj) {
    s32 press;
    s32 cancel;
    s32 i;
    s32 k;
    u32 j;
    u32 f;
    u32 g;
    f32 ang2;
    f32 ang;
    f32 u;

    press = 0;
    cancel = 0;
    if (D_80109B54_FF814_HammerSlammer != 0 || D_80109B94_FF854_HammerSlammer >= 2) {
        for (i = 0; i < 7; i++) {
            f32 t = D_80109BB0_FF870_HammerSlammer[i];

            if (t != 0.0f) {
                t = t / 24.0;
                t = t * (t * t);
                D_80109B60_FF820_HammerSlammer[i] += t * D_80109C00_FF8C0_HammerSlammer[i];
                D_80109BB0_FF870_HammerSlammer[i] -= 1.0f;
                func_80029714_2A314(obj->model[i + 20], -150.0f, D_80109B60_FF820_HammerSlammer[i], 0.0f);
                func_800297E8_2A3E8(obj->model[i + 20], 0.65 - t * 0.15, 0.65 - t * 0.15, 1.0f);
                if (D_80109BB0_FF870_HammerSlammer[i] == 0.0f) {
                    func_800298A4_2A4A4(obj->model[i + 20], 4, 4);
                }
            }
        }
        if (D_80109C28_FF8E8_HammerSlammer == 0) {
            D_80109C34_FF8F4_HammerSlammer = D_80109C34_FF8F4_HammerSlammer + (D_80109B20_FF7E0_HammerSlammer.vy < 0.0 ? -9.0 : -1.25);
            D_80109BF0_FF8B0_HammerSlammer += D_80109C34_FF8F4_HammerSlammer;
            if (D_80109BF0_FF8B0_HammerSlammer < 285.0) {
                if (D_80109C34_FF8F4_HammerSlammer < -10.0) {
                    PlaySound(0x139);
                    D_80109BF0_FF8B0_HammerSlammer = 285.0f;
                    D_80109C28_FF8E8_HammerSlammer = 1;
                } else {
                    D_80109BF0_FF8B0_HammerSlammer = 285.0f;
                    D_80109C34_FF8F4_HammerSlammer = 0.0f;
                }
            }
        }
        switch (D_80109B54_FF814_HammerSlammer) {
        case 0:
            if (D_80109B94_FF854_HammerSlammer >= 3 && D_80109B94_FF854_HammerSlammer < 61) {
                omSetTra(obj, D_80109068_FED28_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] - D_80109B94_FF854_HammerSlammer / 60.0f * 400.0, D_80109080_FED40_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character], 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer >= 60 && D_80109B94_FF854_HammerSlammer < 81) {
                f32 t = (D_80109B94_FF854_HammerSlammer - 60) / 20.0f;

                omSetRot(obj, 0.0f, (1.0 - (1.0 - t) * (1.0 - t) + t) * 0.5 * 90.0 + -90.0, 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer == 76) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[6]), 0, 10, 0);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
            }
            if (D_80109B94_FF854_HammerSlammer == 95) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[5]), 0, 10, 0);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
            }
            if (D_80109B94_FF854_HammerSlammer >= 100 && D_80109B94_FF854_HammerSlammer < 121) {
                f32 t = (D_80109B94_FF854_HammerSlammer - 100) / 20.0f;

                omSetRot(obj, 0.0f, (1.0 - (1.0 - t) * (1.0 - t) + t) * 0.5 * -90.0, 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer == 116) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[6]), 0, 10, 0);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
            }
            if (D_80109B94_FF854_HammerSlammer == 125) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                func_800298A4_2A4A4(obj->model[15], 4, 0);
                D_80109BCC_FF88C_HammerSlammer = 15;
                D_80109C1C_FF8DC_HammerSlammer[1] = func_80025384_25F84(obj->model[15], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, 3) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
                func_80025554_26154(obj->model[15], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer[1]);
                func_8002C628_2D228(obj->model[10], obj->model[D_80109BCC_FF88C_HammerSlammer], "item_hook");
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[1]);
                func_8002C570_2D170(obj->model[D_80109BCC_FF88C_HammerSlammer]);
            }
            break;
        case 1:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[2]);
            }
            if (D_80109B20_FF7E0_HammerSlammer.cpu != -1) {
                if (D_80109B20_FF7E0_HammerSlammer.cpuTimer <= D_80109B20_FF7E0_HammerSlammer.power[0]) {
                    cancel = 1;
                } else if (D_80109B20_FF7E0_HammerSlammer.cpuDelay > 0) {
                    D_80109B20_FF7E0_HammerSlammer.cpuDelay--;
                } else {
                    s8 lo[4] = { 8, 7, 6, 4 };
                    s8 hi[4] = { 2, 2, 2, 2 };

                    press = 1;
                    D_80109B20_FF7E0_HammerSlammer.cpuDelay = (rand8() % lo[D_80109B20_FF7E0_HammerSlammer.cpu]) / 3 + hi[D_80109B20_FF7E0_HammerSlammer.cpu];
                }
            } else {
                press = ContBtnTrg[D_80109B20_FF7E0_HammerSlammer.port] & 0x8000;
                cancel = ContBtnTrg[D_80109B20_FF7E0_HammerSlammer.port] & 0x4000;
            }
            D_80109B20_FF7E0_HammerSlammer.power[2] = D_80109B20_FF7E0_HammerSlammer.power[1];
            D_80109B20_FF7E0_HammerSlammer.power[1] = D_80109B20_FF7E0_HammerSlammer.power[0];
            if (press && D_80109B20_FF7E0_HammerSlammer.power[0] <= 45.5) {
                D_80109B20_FF7E0_HammerSlammer.power[0] = D_80109B20_FF7E0_HammerSlammer.power[0] + 1.0;
            } else if (D_80109B20_FF7E0_HammerSlammer.power[0] >= 0.1) {
                D_80109B20_FF7E0_HammerSlammer.power[0] = D_80109B20_FF7E0_HammerSlammer.power[0] == 0.0 ? 0.0f : (D_80109B20_FF7E0_HammerSlammer.power[0] - 0.1 < 0.0625 ? 0.0625f : D_80109B20_FF7E0_HammerSlammer.power[0] - 0.1);
            }
            func_80029C74_2A874(obj->model[D_80109BCC_FF88C_HammerSlammer], (D_80109B20_FF7E0_HammerSlammer.power[0] + D_80109B20_FF7E0_HammerSlammer.power[1] + D_80109B20_FF7E0_HammerSlammer.power[2]) / 3.0 * 1.5);
            if (cancel) {
                D_80109B54_FF814_HammerSlammer = 2;
                D_80109B94_FF854_HammerSlammer = 0;
                if (D_80109B20_FF7E0_HammerSlammer.power[0] <= 0.0625) {
                    D_80109B20_FF7E0_HammerSlammer.power[0] = 0.0625f;
                }
            }
            if (D_80109B94_FF854_HammerSlammer / 30 == 10) {
                D_80109B54_FF814_HammerSlammer = 2;
                D_80109B94_FF854_HammerSlammer = 0;
                func_8006D4D0_6E0D0(0);
            }
            break;
        case 2:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[3]), 0, (s16)(D_80109B20_FF7E0_HammerSlammer.power[0] / 8.0 + 10.0), 0);
                D_80109B20_FF7E0_HammerSlammer.swing = D_80109B20_FF7E0_HammerSlammer.power[0] / 9.6 + 11.0;
            }
            if (D_80109B94_FF854_HammerSlammer == D_80109B20_FF7E0_HammerSlammer.swing - 6) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[3]);
            }
            if (D_80109B94_FF854_HammerSlammer == (s32)((1.0 - (1.0 - D_80109B20_FF7E0_HammerSlammer.power[0] / 47.0) * (1.0 - D_80109B20_FF7E0_HammerSlammer.power[0] / 47.0) + D_80109B20_FF7E0_HammerSlammer.power[0] / 55.0) / 2.0 * 7.0 - 0.25) + 1) {
                f32 lo[8] = { 0.0625f, 5.0f, 11.0f, 17.0f, 22.0f, 27.0f, 30.0f, 255.0f };
                f32 hi[8] = { 10.0f, 18.5f, 22.0f, 25.5f, 28.0f, 30.5f, 32.5f, 42.0f };

                D_80109B20_FF7E0_HammerSlammer.swing = D_80109B94_FF854_HammerSlammer < D_80109B20_FF7E0_HammerSlammer.swing ? D_80109B20_FF7E0_HammerSlammer.swing - (u8)D_80109B94_FF854_HammerSlammer : -1;
                D_80109B54_FF814_HammerSlammer = 3;
                D_80109B94_FF854_HammerSlammer = 0;
                D_80109B20_FF7E0_HammerSlammer.y = 0.0f;
                for (k = 0; k < 8; k++) {
                    if (D_80109B20_FF7E0_HammerSlammer.power[0] < lo[k]) {
                        break;
                    }
                }
                D_80109B20_FF7E0_HammerSlammer.result = k - 1;
                if (lo[1] <= D_80109B20_FF7E0_HammerSlammer.power[0] && (lo[6] - lo[5]) / 2.0 + lo[5] >= D_80109B20_FF7E0_HammerSlammer.power[0] && (rand8() & 7) == 7) {
                    if ((lo[k + 1] - lo[k]) / 2.0 + lo[k] > D_80109B20_FF7E0_HammerSlammer.power[0]) {
                        D_80109B20_FF7E0_HammerSlammer.result--;
                    } else {
                        D_80109B20_FF7E0_HammerSlammer.result++;
                    }
                }
                D_80109B20_FF7E0_HammerSlammer.vy = hi[D_80109B20_FF7E0_HammerSlammer.result + 1];
            }
            break;
        case 3:
            if (D_80109B94_FF854_HammerSlammer == 1 && D_80109B20_FF7E0_HammerSlammer.power[0] >= -2.5) {
                func_800298A4_2A4A4(obj->model[12], 4, 0);
                PlaySound(0x13A);
            }
            if (D_80109B94_FF854_HammerSlammer == 2 && D_80109B20_FF7E0_HammerSlammer.power[0] >= -2.5) {
                D_80109C29_FF8E9_HammerSlammer = 1;
                D_80109BD1_FF891_HammerSlammer = 1;
            }
            if (D_80109B94_FF854_HammerSlammer == D_80109B20_FF7E0_HammerSlammer.swing - 6) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[3]);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 1, 1);
            }
            if (D_80109B94_FF854_HammerSlammer >= D_80109B20_FF7E0_HammerSlammer.swing - 6) {
                if (D_80109B20_FF7E0_HammerSlammer.power[0] < 2.5) {
                    f64 d = (f32)((f = D_80109B94_FF854_HammerSlammer + 6) - D_80109B20_FF7E0_HammerSlammer.swing) * ((D_80109B20_FF7E0_HammerSlammer.power[0] - 20.0f) / 25.0 + 1.75) / 9.0 * 4.0 + 6.0;

                    if (d + (D_80109B20_FF7E0_HammerSlammer.character == 4 ? 9.0 : 0.0) < 9.0) {
                        func_80029C74_2A874(obj->model[D_80109BCC_FF88C_HammerSlammer], (f32)((f = D_80109B94_FF854_HammerSlammer + 6) - D_80109B20_FF7E0_HammerSlammer.swing) * ((D_80109B20_FF7E0_HammerSlammer.power[0] - 20.0f) / 25.0 / 2.0 + 0.75) / 9.0 * 4.0 + 6.0);
                    } else {
                        func_80029C74_2A874(obj->model[D_80109BCC_FF88C_HammerSlammer], 9.0f);
                    }
                } else if ((f32)((f = D_80109B94_FF854_HammerSlammer + 6) - D_80109B20_FF7E0_HammerSlammer.swing) * ((D_80109B20_FF7E0_HammerSlammer.power[0] - 20.0f) / 25.0 + 0.75) < 9.0) {
                    func_80029C74_2A874(obj->model[D_80109BCC_FF88C_HammerSlammer], (f32)((f = D_80109B94_FF854_HammerSlammer + 6) - D_80109B20_FF7E0_HammerSlammer.swing) * ((D_80109B20_FF7E0_HammerSlammer.power[0] - 20.0f) / 25.0 / 2.0 + 0.75));
                } else {
                    func_80029C74_2A874(obj->model[D_80109BCC_FF88C_HammerSlammer], 9.0f);
                }
            }
            ang = (f32)(D_80109B94_FF854_HammerSlammer - 1) * -(D_80109B20_FF7E0_HammerSlammer.power[0] / 10.0 + 10.0);
            ang = ang < -35.0 ? -35.0f : ang;
            {
                f32 x = func_800B7890_B8490(-25.0f);
                f32 y;

                ang2 = ang - 25.0;
                x = (-x + func_800B7890_B8490(ang2)) * 90.0;
                y = HuMathSin(-25.0f);
                y = (-y + HuMathSin(ang2)) * 90.0;
                func_80029714_2A314(obj->model[14], x, y, 0.0f);
                func_8002979C_2A39C(obj->model[14], 0.0f, 0.0f, ang);
            }
            if (D_80109B20_FF7E0_HammerSlammer.result == -1) {
                if (D_80109B94_FF854_HammerSlammer < 13) {
                    u = (f32)D_80109B94_FF854_HammerSlammer / 13.0 * 90.0;
                    goto fly;
                }
                if (D_80109B94_FF854_HammerSlammer == 13) {
                    D_80109B20_FF7E0_HammerSlammer.y = -25.0f;
                    D_80109B20_FF7E0_HammerSlammer.vy = -D_80109B20_FF7E0_HammerSlammer.vy * 0.5;
                    {
                        f32 c = func_800B7890_B8490(-15.0f);
                        f32 d = func_800B7890_B8490(75.0f);
                        f32 x = D_80109B94_FF854_HammerSlammer * -4.0 - c * 155.0 + d * 155.0;

                        c = HuMathSin(-15.0f);
                        d = HuMathSin(105.0f);
                        func_80029714_2A314(obj->model[11], x, D_80109B20_FF7E0_HammerSlammer.y - c * 155.0 + d * 155.0, 0.0f);
                    }
                    func_8002979C_2A39C(obj->model[11], 0.0f, 0.0f, 90.0f);
                } else if (D_80109B94_FF854_HammerSlammer < 22) {
                    if (D_80109B94_FF854_HammerSlammer != 21) {
                        u = 90.0 - (f32)(D_80109B94_FF854_HammerSlammer - 13) / 8.0 * 15.0;
                    } else {
                        u = 75.0f;
                    }
                fly:
                    D_80109B20_FF7E0_HammerSlammer.y += D_80109B20_FF7E0_HammerSlammer.vy;
                    D_80109B20_FF7E0_HammerSlammer.vy = D_80109B20_FF7E0_HammerSlammer.vy - 2.0;
                    {
                        f32 c = func_800B7890_B8490(-15.0f);
                        f32 d = func_800B7890_B8490(u - 15.0);
                        f32 x = D_80109B94_FF854_HammerSlammer * -4.0 - c * 155.0 + d * 155.0;

                        c = HuMathSin(-15.0f);
                        d = HuMathSin(u - 15.0);
                        func_80029714_2A314(obj->model[11], x, D_80109B20_FF7E0_HammerSlammer.y - c * 155.0 + d * 155.0, 0.0f);
                    }
                    func_8002979C_2A39C(obj->model[11], 0.0f, 0.0f, u);
                } else if (D_80109B94_FF854_HammerSlammer < 26) {
                    f32 rot[4] = { 82.5f, 90.0f, 90.0f, 90.0f };

                    ang = rot[D_80109B94_FF854_HammerSlammer - 22];
                    {
                        f32 back[4] = { 4.0f, 7.0f, 9.0f, 10.0f };

                        f32 c;
                        f32 d;
                        f32 x;

                        D_80109B20_FF7E0_HammerSlammer.y = -25.0f;
                        c = func_800B7890_B8490(-15.0f);
                        ang2 = ang - 15.0;
                        d = func_800B7890_B8490(ang2);
                        x = -84.0 - back[D_80109B94_FF854_HammerSlammer - 22] - c * 155.0 + d * 155.0;
                        c = HuMathSin(-15.0f);
                        d = HuMathSin(ang2);
                        func_80029714_2A314(obj->model[11], x, D_80109B20_FF7E0_HammerSlammer.y - c * 155.0 + d * 155.0, 0.0f);
                        func_8002979C_2A39C(obj->model[11], 0.0f, 0.0f, ang);
                    }
                } else if (D_80109B94_FF854_HammerSlammer == 30) {
                    D_80109B54_FF814_HammerSlammer = 5;
                    D_80109B94_FF854_HammerSlammer = 0;
                }
            } else if (D_80109B20_FF7E0_HammerSlammer.vy < 0.0 && D_80109B20_FF7E0_HammerSlammer.result + 1 >= (s32)((D_80109B20_FF7E0_HammerSlammer.y + D_80109B20_FF7E0_HammerSlammer.vy - 65.75) / 41.0 + 2.0)) {
                D_80109B20_FF7E0_HammerSlammer.y = D_80109B20_FF7E0_HammerSlammer.result * 41.0 + 65.75;
                D_80109B54_FF814_HammerSlammer = 4;
                D_80109B94_FF854_HammerSlammer = 0;
                D_80109BD2_FF892_HammerSlammer = 11;
                func_80029714_2A314(obj->model[11], 0.0f, D_80109B20_FF7E0_HammerSlammer.y - 2.0, 0.0f);
            } else if (D_80109B94_FF854_HammerSlammer != 1) {
                D_80109B20_FF7E0_HammerSlammer.y += D_80109B20_FF7E0_HammerSlammer.vy;
                D_80109B20_FF7E0_HammerSlammer.vy = D_80109B20_FF7E0_HammerSlammer.vy - 2.0;
                if (D_80109B20_FF7E0_HammerSlammer.y <= 0.0) {
                    D_80109B20_FF7E0_HammerSlammer.y = 0.0f;
                    D_80109B20_FF7E0_HammerSlammer.vy = 0.0f;
                }
                if (D_80109B20_FF7E0_HammerSlammer.y >= D_80109BF0_FF8B0_HammerSlammer) {
                    s16 tbl[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2 };

                    D_80109B20_FF7E0_HammerSlammer.vy += D_80109C34_FF8F4_HammerSlammer;
                    D_80109B20_FF7E0_HammerSlammer.y = D_80109BF0_FF8B0_HammerSlammer = (D_80109BF0_FF8B0_HammerSlammer + D_80109B20_FF7E0_HammerSlammer.y) / 2.0;
                    if (D_80109B20_FF7E0_HammerSlammer.result == 6) {
                        D_80109B20_FF7E0_HammerSlammer.result = D_80109B98_FF858_HammerSlammer != 0 ? D_80109B98_FF858_HammerSlammer - 1 : tbl[(u8)(rand8() % 10)];
                    }
                }
                func_80029714_2A314(obj->model[11], 0.0f, D_80109B20_FF7E0_HammerSlammer.y, 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer == 120) {
                D_80109B20_FF7E0_HammerSlammer.result = -1;
                D_80109B54_FF814_HammerSlammer = 5;
                D_80109B94_FF854_HammerSlammer = 0;
            }
            if (D_80109B20_FF7E0_HammerSlammer.result != -1 && D_80109B94_FF854_HammerSlammer % 2 == 1 && D_80109B94_FF854_HammerSlammer < 15 && D_80109B20_FF7E0_HammerSlammer.vy > 5.0 && (D_80109B20_FF7E0_HammerSlammer.y < 285.0 || D_80109B94_FF854_HammerSlammer / 2 < 5)) {
                j = D_80109B94_FF854_HammerSlammer / 2;
                D_80109B60_FF820_HammerSlammer[j] = D_80109B20_FF7E0_HammerSlammer.y + 10.0;
                D_80109C00_FF8C0_HammerSlammer[j] = -D_80109B20_FF7E0_HammerSlammer.vy * 0.125;
                D_80109BB0_FF870_HammerSlammer[j] = 24.0f;
                func_800298A4_2A4A4(obj->model[j + 20], 4, 0);
                func_80029714_2A314(obj->model[j + 20], -150.0f, D_80109B60_FF820_HammerSlammer[j], 0.0f);
                func_80029C74_2A874(obj->model[j + 20], 35.0f);
                func_8010746C_FD12C_HammerSlammer(obj->model[j + 20], 0x23);
                func_800297E8_2A3E8(obj->model[j + 20], 0.65f, 0.0f, 1.0f);
            }
            break;
        case 4:
            if (D_80109B94_FF854_HammerSlammer == 1 && D_80109B20_FF7E0_HammerSlammer.cpu == -1) {
                omVibrate(D_80109B20_FF7E0_HammerSlammer.player, 2, 2, 0x14);
            }
            if (D_80109B94_FF854_HammerSlammer == 1 && (u8)(D_80109B20_FF7E0_HammerSlammer.result + 1) >= 2) {
                PlaySound(0x13B);
            }
            if (D_80109B94_FF854_HammerSlammer < 3) {
                s32 m = obj->model[11];
                f64 d = 2 - D_80109B94_FF854_HammerSlammer;
                f64 e = d;

                if ((D_80109B94_FF854_HammerSlammer & 1) == 0) {
                    e = -e;
                }
                func_80029714_2A314(m, 0.0f, D_80109B20_FF7E0_HammerSlammer.y + (D_80109B20_FF7E0_HammerSlammer.vy < -30.0 ? e * 2.5 : e), 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer == 15) {
                D_80109B54_FF814_HammerSlammer = 5;
                D_80109B94_FF854_HammerSlammer = 0;
            }
            break;
        case 5:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_800298A4_2A4A4(obj->model[15], 4, 4);
                func_800298A4_2A4A4(obj->model[16], 4, 0);
                D_80109BCC_FF88C_HammerSlammer = 16;
                func_8002C628_2D228(obj->model[10], obj->model[16], "item_hook");
                func_8002D124_2DD24(obj->model[10]);
                func_80029AFC_2A6FC(obj->model[10]);
                func_800298A4_2A4A4(obj->model[10], 0x60, 0);
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[6]), 0, 0x18, 2);
            }
            if (D_80109B94_FF854_HammerSlammer < 15) {
                func_8002D0A0_2DCA0(obj->model[10], 0x80 - (u32)(D_80109B94_FF854_HammerSlammer / 15.0f * 128.0));
            }
            if (D_80109B94_FF854_HammerSlammer == 15) {
                func_800298A4_2A4A4(obj->model[10], 4, 4);
            }
            if (D_80109B94_FF854_HammerSlammer == 60) {
                D_80109B54_FF814_HammerSlammer = 1;
                D_80109B94_FF854_HammerSlammer = 0;
                D_80109B20_FF7E0_HammerSlammer.power[0] = 0.0f;
                D_80109B20_FF7E0_HammerSlammer.y = 0.0f;
                D_80109B20_FF7E0_HammerSlammer.vy = 0.0f;
                D_80109B20_FF7E0_HammerSlammer.result = -2;
                func_80029714_2A314(obj->model[11], D_80109B20_FF7E0_HammerSlammer.power[0], D_80109B20_FF7E0_HammerSlammer.power[0], D_80109B20_FF7E0_HammerSlammer.power[0]);
                func_8002979C_2A39C(obj->model[11], 0.0f, 0.0f, 0.0f);
                func_80029714_2A314(obj->model[14], 0.0f, 0.0f, 0.0f);
                func_8002979C_2A39C(obj->model[14], 0.0f, 0.0f, 0.0f);
                func_8010746C_FD12C_HammerSlammer(obj->model[12], 0);
            }
            if (D_80109B94_FF854_HammerSlammer == 17) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[5]), 0, 10, 0);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
            }
            if (D_80109B94_FF854_HammerSlammer >= 15 && D_80109B94_FF854_HammerSlammer < 36) {
                f32 t = 1.0 - (D_80109B94_FF854_HammerSlammer - 15) / 20.0f;

                func_8002979C_2A39C(obj->model[D_80109BCC_FF88C_HammerSlammer], 0.0f, (1.0 - (1.0 - t) * (1.0 - t) + t) * 0.5 * -90.0, 0.0f);
            }
            if (D_80109B94_FF854_HammerSlammer == 31) {
                func_80029BF0_2A7F0(obj->model[D_80109BCC_FF88C_HammerSlammer], func_80029E14_2AA14(obj->model[6]), 0, 10, 0);
                func_80029E80_2AA80(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, 2);
            }
            break;
        case 8:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[7]);
            }
            {
                s32 unused[6] = { 7, 1, 1, 1, 0x1C, 8 };
                s32 voice[6] = { 2, 8, 2, 2, 5, 2 };

                if (func_80073014_73C14((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x57, NULL) / 2 + 1 == D_80109B94_FF854_HammerSlammer) {
                    D_80109C1C_FF8DC_HammerSlammer[2] = func_80025384_25F84(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, voice[D_80109B20_FF7E0_HammerSlammer.character]) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
                    func_80025554_26154(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer[2]);
                }
                if (D_80109B94_FF854_HammerSlammer == 1) {
                    func_800732B0_73EB0((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x57);
                }
            }
            break;
        case 7:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[8]);
            }
            {
                s32 unused[6] = { 0x12, 1, 1, 1, 1, 1 };
                s32 voice[6] = { 9, 5, 5, 2, 5, 5 };

                if (func_80073014_73C14((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x56, NULL) / 2 + 1 == D_80109B94_FF854_HammerSlammer) {
                    D_80109C1C_FF8DC_HammerSlammer[2] = func_80025384_25F84(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, voice[D_80109B20_FF7E0_HammerSlammer.character]) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
                    func_80025554_26154(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer[2]);
                }
                if (D_80109B94_FF854_HammerSlammer == 1) {
                    func_800732B0_73EB0((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x56);
                }
            }
            break;
        case 6:
            if (D_80109B94_FF854_HammerSlammer == 1) {
                func_80029B80_2A780(obj->model[D_80109BCC_FF88C_HammerSlammer], obj->model[9]);
            }
            {
                s32 unused[6] = { 0x3A, 0x24, 0xFF, 0x2D, 0x13, 0xFF };
                s32 unused2[6] = { 0x3C, 0x20, 0x39, 0x2D, 0x13, 0x36 };

                s32 v = func_80073014_73C14((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x54, NULL) / 2 + 1;
                u32 now = D_80109B94_FF854_HammerSlammer;

                if (D_80109B20_FF7E0_HammerSlammer.character == 0 ? v + 6 == now : v == now) {
                    D_80109C1C_FF8DC_HammerSlammer[2] = func_80025384_25F84(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, 1) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
                    func_80025554_26154(obj->model[D_80109BCC_FF88C_HammerSlammer], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer[2]);
                }
                now = D_80109B94_FF854_HammerSlammer;
                if (D_80109B20_FF7E0_HammerSlammer.character == 0 ? now == 8 : now == 1) {
                    func_800732B0_73EB0((D_801090B0_FED70_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character] << 16) | 0x54);
                }
            }
            break;
        }
        if (D_80109C28_FF8E8_HammerSlammer != 0) {
            D_80109C34_FF8F4_HammerSlammer = D_80109C34_FF8F4_HammerSlammer + (D_80109C34_FF8F4_HammerSlammer < 4.0 ? 0.75 : 1.0);
            if (D_80109C34_FF8F4_HammerSlammer > 0.0) {
                D_80109C28_FF8E8_HammerSlammer = 0;
                D_80109C34_FF8F4_HammerSlammer = 0.0f;
                D_80109BF0_FF8B0_HammerSlammer = 285.0f;
            } else {
                f32 sign[4] = { -1.0f, 1.0f, -1.0f, 1.0f };

                D_80109C28_FF8E8_HammerSlammer++;
                { f32* ps = &sign[D_80109C28_FF8E8_HammerSlammer % 4]; D_80109BF0_FF8B0_HammerSlammer = -D_80109C34_FF8F4_HammerSlammer * *ps * 0.8 + 285.0; }
            }
        }
        func_80029714_2A314(obj->model[19], 0.0f, D_80109BF0_FF8B0_HammerSlammer - 285.0, 0.0f);
        func_80029714_2A314(obj->model[18], 0.0f, (D_80109BF0_FF8B0_HammerSlammer - 285.0) * 11.75, 0.0f);
        func_800297E8_2A3E8(obj->model[18], 1.0f, 1.0 - (D_80109BF0_FF8B0_HammerSlammer - 285.0) / 37.0, 1.0f);
        if (D_80109B54_FF814_HammerSlammer == 5 && D_80109B94_FF854_HammerSlammer == 10 && D_80109B20_FF7E0_HammerSlammer.result == 0) {
            func_800298A4_2A4A4(obj->model[32], 4, 0);
            PlaySound(0x13C);
        }
        if (D_80109B54_FF814_HammerSlammer == 5 && D_80109B94_FF854_HammerSlammer == 20 && D_80109B20_FF7E0_HammerSlammer.result == 0) {
            func_800298A4_2A4A4(obj->model[28], 4, 0);
        }
        if (D_80109B54_FF814_HammerSlammer == 5 && D_80109B94_FF854_HammerSlammer >= 21 && D_80109B20_FF7E0_HammerSlammer.result == 0) {
            f32 h0 = (D_80109B94_FF854_HammerSlammer - 20) / 7.0f;
            f32 h1 = (D_80109B94_FF854_HammerSlammer - 21) / 7.0f;

            h0 = 80.0 - (f32)(h0 * h0) * 80.0;
            h1 = 80.0 - (f32)(h1 * h1) * 80.0;
            func_80029714_2A314(obj->model[28], -240.0f, h0 < 0.0 ? 0.0f : h0, 25.0f);
            if (h0 < 0.0 && h1 >= 0.0) {
                D_80109C2C_FF8EC_HammerSlammer = 1;
                func_80029E80_2AA80(obj->model[28], 1, 0);
            }
        }
        if (D_80109C2C_FF8EC_HammerSlammer != 0 && ++D_80109C2C_FF8EC_HammerSlammer == 22 && _CheckFlag(0xC) == 0) {
            func_80029E80_2AA80(obj->model[31], 3, 2);
            func_80029BF0_2A7F0(obj->model[28], func_80029E14_2AA14(obj->model[31]), 0, 12, 2);
        }
        if ((u8)(D_80109B20_FF7E0_HammerSlammer.result + 1) >= 2 && (D_80109B54_FF814_HammerSlammer == 5 || D_80109B54_FF814_HammerSlammer == 8 || D_80109B54_FF814_HammerSlammer == 6 || D_80109B54_FF814_HammerSlammer == 7 || D_80109B54_FF814_HammerSlammer == 9)) {
            f32 x0;
            f32 y0;
            f32 x1;
            f32 y1;
            f32 x;
            f32 y;
            f32 t;

            if ((u8)D_80109B20_FF7E0_HammerSlammer.result % 2 != 0) {
                x0 = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 - (D_80109B20_FF7E0_HammerSlammer.result == 3 ? 62.5 : 50.0);
                y0 = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + (D_80109B20_FF7E0_HammerSlammer.result == 3 ? 142.5 : 155.0);
                x1 = D_80109030_FECF0_HammerSlammer[6] + 5.0;
                y1 = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 65.0 : 70.0);
            } else {
                x0 = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + 200.0;
                y0 = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + 60.0;
                x1 = D_80109030_FECF0_HammerSlammer[6];
                y1 = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 45.0 : 50.0);
            }
            if (D_80109BD2_FF892_HammerSlammer >= 0) {
                t = 1.0 - D_80109BD2_FF892_HammerSlammer / 30.0;
                t = t > 1.0 ? 1.0f : t;
                x = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * (1.0 - t) * (1.0 - t) * (1.0 - t)
                    + x0 * 3.0 * t * (1.0 - t) * (1.0 - t)
                    + x1 * 3.0 * t * t * (1.0 - t)
                    + t * D_80109030_FECF0_HammerSlammer[6] * t * t;
                y = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * (1.0 - t) * (1.0 - t) * (1.0 - t)
                    + y0 * 3.0 * t * (1.0 - t) * (1.0 - t)
                    + y1 * 3.0 * t * t * (1.0 - t)
                    + (D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 10.0 : 0.0) + -20.0) * t * t * t;
            } else {
                D_80109B58_FF818_HammerSlammer = D_80109B58_FF818_HammerSlammer - 0.25 < 8.0 ? 8.0f : D_80109B58_FF818_HammerSlammer - 0.25;
                x = D_80109030_FECF0_HammerSlammer[6];
                t = HuMathSin(-D_80109BD2_FF892_HammerSlammer * 6.0 + 30.0);
                if (t < HuMathSin(-D_80109BD2_FF892_HammerSlammer * 6.0) * D_80109B58_FF818_HammerSlammer) {
                    y = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 10.0 : 0.0) + -20.0 + HuMathSin(-D_80109BD2_FF892_HammerSlammer * 6.0 + 30.0) * D_80109B58_FF818_HammerSlammer + 1.0;
                } else {
                    y = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 10.0 : 0.0) + -20.0 + HuMathSin(-D_80109BD2_FF892_HammerSlammer * 6.0) * D_80109B58_FF818_HammerSlammer + 1.0;
                }
            }
            f = HS_STEP / 15 != D_80109C30_FF8F0_HammerSlammer / 15 ? (D_80109C30_FF8F0_HammerSlammer / 15 + 1) * 15 : HS_STEP;
            D_80109C30_FF8F0_HammerSlammer = f % 120;
            if (D_80109C30_FF8F0_HammerSlammer % 15 == 0) {
                j = D_80109C30_FF8F0_HammerSlammer / 15;
                func_800298A4_2A4A4(D_80109B90_FF850_HammerSlammer->model[j], 4, 0);
                func_80029C74_2A874(D_80109B90_FF850_HammerSlammer->model[j], 27.0f);
                func_8010746C_FD12C_HammerSlammer(D_80109B90_FF850_HammerSlammer->model[j], 0x1B);
                if (j == 0) {
                    omSetTra(D_80109B90_FF850_HammerSlammer, x * 2.375 + -362.0, 460.0 - y * 2.34375, 0.0f);
                } else {
                    func_80029714_2A314(D_80109B90_FF850_HammerSlammer->model[j], x * 2.375 + -362.0, 460.0 - y * 2.34375, 0.0f);
                }
            }
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80109338_FEFF8_HammerSlammer[1] = { 0x08070604 };

__asm__(".section .rodata");
const u32 D_8010933C_FEFFC_HammerSlammer[1] = { 0x02020202 };

__asm__(".section .rodata");
const u32 D_80109340_FF000_HammerSlammer[4] = { 0x42A50000, 0x42B40000, 0x42B40000, 0x42B40000 };

__asm__(".section .rodata");
const u32 D_80109350_FF010_HammerSlammer[4] = { 0x40800000, 0x40E00000, 0x41100000, 0x41200000 };

__asm__(".section .rodata");
const u32 D_80109360_FF020_HammerSlammer[5] = { 0x00000000, 0x00000000, 0x00000001, 0x00010001, 0x00020002 };

__asm__(".section .rodata");
const u32 D_80109374_FF034_HammerSlammer[6] = { 0x00000007, 0x00000001, 0x00000001, 0x00000001, 0x0000001C, 0x00000008 };

__asm__(".section .rodata");
const u32 D_8010938C_FF04C_HammerSlammer[6] = { 0x00000002, 0x00000008, 0x00000002, 0x00000002, 0x00000005, 0x00000002 };

__asm__(".section .rodata");
const u32 D_801093A4_FF064_HammerSlammer[6] = { 0x00000012, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001 };

__asm__(".section .rodata");
const u32 D_801093BC_FF07C_HammerSlammer[6] = { 0x00000009, 0x00000005, 0x00000005, 0x00000002, 0x00000005, 0x00000005 };

__asm__(".section .rodata");
const u32 D_801093D4_FF094_HammerSlammer[6] = { 0x0000003A, 0x00000024, 0x000000FF, 0x0000002D, 0x00000013, 0x000000FF };

__asm__(".section .rodata");
const u32 D_801093EC_FF0AC_HammerSlammer[6] = { 0x0000003C, 0x00000020, 0x00000039, 0x0000002D, 0x00000013, 0x00000036 };

__asm__(".section .rodata");
const u32 D_80109404_FF0C4_HammerSlammer[5] = { 0xBF800000, 0x3F800000, 0xBF800000, 0x3F800000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_HammerSlammer/F84C0", func_80104000_F9CC0_HammerSlammer);
#endif

void func_8010746C_FD12C_HammerSlammer(s16 model, s16 frame) {
    s32 off = model * sizeof(HmfModel);
    HmfModel* m = (HmfModel*)(off + (u8*)D_800FC834_FD434);

    m->hmf->unk9C->unk08 = frame;
}

/* Draws the six item panels, 32x32 CI8 esp images, except the one the player has taken. */
void func_801074B0_FD170_HammerSlammer(Gfx** gfx, s32 arg1, s32 arg2) {
    HuSprite* spr[6];
    HuSprite_Unk84_Unk00_Struct* frame[6];
    f32 x;
    f32 y;
    s32 i;

    x = 0.0f;
    y = D_80109BF4_FF8B4_HammerSlammer;
    for (i = 0; i < 6; i++) {
        spr[i] = func_80082550_83150(D_800F93FC_F9FFC[D_80109BD8_FF898_HammerSlammer[D_80109C38_FF8F8_HammerSlammer[i]]].unk_04, 0);
        frame[i] = &spr[i]->unk_84->unk00[spr[i]->unk_90];
        if (D_80109B54_FF814_HammerSlammer == 5 || D_80109B54_FF814_HammerSlammer == 8 || D_80109B54_FF814_HammerSlammer == 6 || D_80109B54_FF814_HammerSlammer == 7 || D_80109B54_FF814_HammerSlammer == 9) {
            if (i == D_80109B20_FF7E0_HammerSlammer.result) {
                if ((u8)(D_80109B20_FF7E0_HammerSlammer.result + 1) >= 2) {
                    continue;
                }
                if (i == 0) {
                    if (D_80109B54_FF814_HammerSlammer != 5) {
                        continue;
                    }
                    if (D_80109B94_FF854_HammerSlammer >= 20) {
                        continue;
                    }
                }
            }
        }
        gSPDisplayList(D_800FDBCC_FE7CC++, D_80109140_FEE00_HammerSlammer);
        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
        gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr[i]->unk_84->unk0C);
        gDPLoadTextureBlock(D_800FDBCC_FE7CC++, frame[i]->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
        gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)((x + D_80109030_FECF0_HammerSlammer[i]) * 4.0), (s32)((y + D_8010904C_FED0C_HammerSlammer[i]) * 4.0),
                                (s32)((x + D_80109030_FECF0_HammerSlammer[i] + 32.0) * 4.0), (s32)((y + D_8010904C_FED0C_HammerSlammer[i] + 32.0) * 4.0),
                                G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
    }
    func_80107A2C_FD6EC_HammerSlammer(gfx, arg1, arg2);
}

/* The item the player took: it arcs to the player (a cubic Bezier), its trail, the shake on the
   hammer, and the impact burst of state 4. */
void func_80107A2C_FD6EC_HammerSlammer(Gfx** gfx, s32 arg1, s32 arg2) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* frame;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x;
    f32 y;
    f32 t;
    f32 burst;
    s32 n;
    s32 a;
    s16 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_80109B54_FF814_HammerSlammer == 5 || D_80109B54_FF814_HammerSlammer == 6 || D_80109B54_FF814_HammerSlammer == 7 || D_80109B54_FF814_HammerSlammer == 8 || D_80109B54_FF814_HammerSlammer == 9) {
            s32 v = D_80109BD2_FF892_HammerSlammer;

            D_80109BD2_FF892_HammerSlammer = v < -59 ? v + 59 : v - 1;
        } else {
            s32 v = D_80109BD2_FF892_HammerSlammer;

            if (v > 0) {
                D_80109BD2_FF892_HammerSlammer = v - 1;
            } else {
                D_80109BD2_FF892_HammerSlammer = v;
            }
        }
    }
    if (D_80109B94_FF854_HammerSlammer == 0 && D_80109BD2_FF892_HammerSlammer < 10 && D_80109B54_FF814_HammerSlammer == 5 && D_80109B20_FF7E0_HammerSlammer.result != 0) {
        D_80109BD2_FF892_HammerSlammer = 30;
        for (i = 0; i < 4; i++) {
            D_80109BA0_FF860_HammerSlammer[i] = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result];
            D_80109B80_FF840_HammerSlammer[i] = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result];
        }
    }
    if ((u8)(D_80109B20_FF7E0_HammerSlammer.result + 1) < 2 || (D_80109B54_FF814_HammerSlammer != 5 && D_80109B54_FF814_HammerSlammer != 8 && D_80109B54_FF814_HammerSlammer != 6 && D_80109B54_FF814_HammerSlammer != 7 && D_80109B54_FF814_HammerSlammer != 9)) {
        if (D_80109BD2_FF892_HammerSlammer == 0) {
            return;
        }
        if (D_80109B54_FF814_HammerSlammer != 4) {
            return;
        }
    }
    spr = func_80082550_83150(D_800F93FC_F9FFC[D_80109BD8_FF898_HammerSlammer[D_80109C38_FF8F8_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result]]].unk_04, 0);
    frame = &spr->unk_84->unk00[spr->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_80109140_FEE00_HammerSlammer);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    gDPLoadTextureBlock(D_800FDBCC_FE7CC++, frame->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    if (D_80109B20_FF7E0_HammerSlammer.result != 0 && (D_80109B54_FF814_HammerSlammer == 5 || D_80109B54_FF814_HammerSlammer == 8 || D_80109B54_FF814_HammerSlammer == 6 || D_80109B54_FF814_HammerSlammer == 7 || D_80109B54_FF814_HammerSlammer == 9)) {
        if ((u8)D_80109B20_FF7E0_HammerSlammer.result % 2 != 0) {
            x0 = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 - (D_80109B20_FF7E0_HammerSlammer.result == 3 ? 62.5 : 50.0);
            y0 = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + (D_80109B20_FF7E0_HammerSlammer.result == 3 ? 142.5 : 155.0);
            x1 = D_80109030_FECF0_HammerSlammer[6] + 5.0;
            y1 = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 65.0 : 70.0);
        } else {
            x0 = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + 200.0;
            y0 = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 0.5 + 60.0;
            x1 = D_80109030_FECF0_HammerSlammer[6];
            y1 = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 45.0 : 50.0);
        }
        gDPSetCombineMode(D_800FDBCC_FE7CC++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        n = D_80109BD2_FF892_HammerSlammer < 4 ? (D_80109BD2_FF892_HammerSlammer >= 0 ? 4 - D_80109BD2_FF892_HammerSlammer : 4) : 0;
        for (; n < 4; n++) {
            gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, 0xFF, 0xFF, 0xFF, a = 0xFF - (4 - n) * 48);
            gDPSetBlendColor(D_800FDBCC_FE7CC++, 0, 0, 0, a * 2 / 3);
            x = D_80109BA0_FF860_HammerSlammer[3 - n];
            y = D_80109B80_FF840_HammerSlammer[3 - n];
            gDPPipeSync(D_800FDBCC_FE7CC++);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)(x * 4.0), (s32)(y * 4.0), (s32)((x + 32.0) * 4.0),
                                    (s32)((y + 32.0) * 4.0), G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
        }
        gDPSetCombineMode(D_800FDBCC_FE7CC++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPPipeSync(D_800FDBCC_FE7CC++);
        if (D_80109BD2_FF892_HammerSlammer >= 0) {
            t = 1.0 - D_80109BD2_FF892_HammerSlammer / 30.0;
            t = t > 1.0 ? 1.0f : t;
            x = D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * (1.0 - t) * (1.0 - t) * (1.0 - t)
                + x0 * 3.0 * t * (1.0 - t) * (1.0 - t)
                + x1 * 3.0 * t * t * (1.0 - t)
                + t * D_80109030_FECF0_HammerSlammer[6] * t * t;
            y = D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * (1.0 - t) * (1.0 - t) * (1.0 - t)
                + y0 * 3.0 * t * (1.0 - t) * (1.0 - t)
                + y1 * 3.0 * t * t * (1.0 - t)
                + (D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 10.0 : 0.0) + -20.0) * t * t * t;
        } else {
            D_80109B58_FF818_HammerSlammer = D_80109B58_FF818_HammerSlammer - 0.25 < 8.0 ? 8.0f : D_80109B58_FF818_HammerSlammer - 0.25;
            x = D_80109030_FECF0_HammerSlammer[6];
            y = D_8010904C_FED0C_HammerSlammer[6] - (D_80109B20_FF7E0_HammerSlammer.character == 5 ? 10.0 : 0.0) + -20.0 + HuMathSin(-D_80109BD2_FF892_HammerSlammer * 6.0) * D_80109B58_FF818_HammerSlammer;
        }
        D_80109BA0_FF860_HammerSlammer[3] = D_80109BA0_FF860_HammerSlammer[2];
        D_80109B80_FF840_HammerSlammer[3] = D_80109B80_FF840_HammerSlammer[2];
        D_80109BA0_FF860_HammerSlammer[2] = D_80109BA0_FF860_HammerSlammer[1];
        D_80109B80_FF840_HammerSlammer[2] = D_80109B80_FF840_HammerSlammer[1];
        D_80109BA0_FF860_HammerSlammer[1] = D_80109BA0_FF860_HammerSlammer[0];
        D_80109B80_FF840_HammerSlammer[1] = D_80109B80_FF840_HammerSlammer[0];
        D_80109BA0_FF860_HammerSlammer[0] = x;
        D_80109B80_FF840_HammerSlammer[0] = y;
        gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)(x * 4.0), (s32)(y * 4.0), (s32)((x + 32.0) * 4.0),
                                (s32)((y + 32.0) * 4.0), G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
    } else {
        gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)(D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 4.0), (s32)(D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] * 4.0),
                                (s32)((D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] + 32.0) * 4.0), (s32)((D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] + 32.0) * 4.0),
                                G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
    }
    if (D_80109BD2_FF892_HammerSlammer >= 0 && D_80109B54_FF814_HammerSlammer == 4) {
        gDPSetCombineMode(D_800FDBCC_FE7CC++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        burst = D_80109BD2_FF892_HammerSlammer / 11.0;
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, 0xFF, 0xFF, 0xFF, (u8)(((1.0 - (1.0 - burst) * (1.0 - burst)) * 0.75 + burst * 0.25) * 224.0));
        gDPSetBlendColor(D_800FDBCC_FE7CC++, 0, 0, 0, (u8)(((1.0 - (1.0 - burst) * (1.0 - burst)) * 0.75 + burst * 0.25) * 224.0) * 2 / 3);
        burst = (1.0 - burst * burst) * 22.0;
        gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)((D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] - burst) * 4.0), (s32)((D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] - burst) * 4.0),
                                (s32)((burst + D_80109030_FECF0_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] + 32.0) * 4.0), (s32)((burst + D_8010904C_FED0C_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.result] + 32.0) * 4.0),
                                G_TX_RENDERTILE, 0, 0, (s32)(32.0 / (burst + 32.0 + burst) * 1024.0), (s32)(32.0 / (burst + 32.0 + burst) * 1024.0));
    }
}

/* .data (0xFECF0-0xFEE50, 80109030-80109190) */
f32 D_80109030_FECF0_HammerSlammer[7] = { 47.0f, 122.0f, 47.0f, 122.0f, 47.0f, 122.0f, 186.0f };
f32 D_8010904C_FED0C_HammerSlammer[7] = { 150.0f, 133.0f, 115.0f, 97.0f, 80.0f, 62.0f, 90.0f };
f32 D_80109068_FED28_HammerSlammer[6] = { 480.0f, 495.0f, 470.0f, 477.0f, 471.0f, 480.0f };
f32 D_80109080_FED40_HammerSlammer[6] = { 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, -1.0f };
f32 D_80109098_FED58_HammerSlammer[6] = { 0.0f, 4.0f, -4.0f, -4.0f, -5.0f, -2.0f };
s32 D_801090B0_FED70_HammerSlammer[6] = { 2, 3, 7, 4, 5, 6 };
s32 D_801090C8_FED88_HammerSlammer[11] = { 0x00140009, 0x0014000A, 0x0014000C, 0x0014000D, 0x0014000E, 0x0014000F, 0x00140010, 0x00140011, 0x00140012, 0x00140013, 0x00140008 };
/* the display list at 801090F8 has no label of its own (8-aligned after the table) */
Gfx D_801090F8_FEDB8_HammerSlammer[] = {
    {{ 0xE7000000, 0x00000000 }},
    {{ 0xE3000A01, 0x00000000 }},
    {{ 0xFCFFFFFF, 0xFFFCF279 }},
    {{ 0xE200001C, 0x0F0A4000 }},
    {{ 0xE2001E01, 0x00000000 }},
    {{ 0xE3000C00, 0x00000000 }},
    {{ 0xE3001201, 0x00002000 }},
    {{ 0xED000000, 0x005003C0 }},
    {{ 0xDF000000, 0x00000000 }},
};
Gfx D_80109140_FEE00_HammerSlammer[] = {
    {{ 0xE7000000, 0x00000000 }},
    {{ 0xE3000A01, 0x00000000 }},
    {{ 0xFCFFFFFF, 0xFFFCF279 }},
    {{ 0xE200001C, 0x00504240 }},
    {{ 0xE2001E01, 0x00000001 }},
    {{ 0xE3000C00, 0x00000000 }},
    {{ 0xE3001201, 0x00002000 }},
    {{ 0xED000000, 0x005003C0 }},
    {{ 0xF9000000, 0x000000C0 }},
    {{ 0xDF000000, 0x00000000 }},
};
