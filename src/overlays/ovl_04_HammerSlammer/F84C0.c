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
    D_80109C34_FF8F4_HammerSlammer = 0;
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
    D_80109048_FED08_HammerSlammer[0] += D_80109098_FED58_HammerSlammer[D_80109B20_FF7E0_HammerSlammer.character];
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
    D_80109C1C_FF8DC_HammerSlammer = func_80025384_25F84(obj->model[0], 2, D_80109B20_FF7E0_HammerSlammer.character, func_80025718_26318(D_80109B20_FF7E0_HammerSlammer.character, 2, 0) | D_800CD438_CE038[D_80109B20_FF7E0_HammerSlammer.character].unk_04);
    func_80025554_26154(obj->model[0], 2, D_80109B20_FF7E0_HammerSlammer.character, (s16)D_80109C1C_FF8DC_HammerSlammer);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_HammerSlammer/F84C0", func_8010746C_FD12C_HammerSlammer);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_HammerSlammer/F84C0", func_801074B0_FD170_HammerSlammer);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_HammerSlammer/F84C0", func_80107A2C_FD6EC_HammerSlammer);
