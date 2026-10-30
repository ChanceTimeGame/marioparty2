#include "ovl_0D.h"

void func_80102800_138530_HotBobOmb(void) {
    func_8002D4D0_2E0D0(4);
    func_80020D20_21920(0x50);
    omInitObjMan(0x20, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    omAddObj(0xA, 0, 0, -1, func_80102D10_138A40_HotBobOmb);
    func_8002CA48_2D648(0, 0, 0);
    func_80102B30_138860_HotBobOmb();
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 30.0f, 115.0f);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_801032EC_13901C_HotBobOmb();
    func_801028D4_138604_HotBobOmb();
    func_80102E94_138BC4_HotBobOmb();
    func_8010322C_138F5C_HotBobOmb();
    InitFadeIn(0, 0x10);
}

/* Each round's fuse (seconds) and the fuse sprite's bob period, drawn at random. */
void func_801028D4_138604_HotBobOmb(void) {
    D_80106E90_13CBC0_HotBobOmb[0] = (u8)(rand8() % 9) + 10;
    D_80106E90_13CBC0_HotBobOmb[1] = (u8)(rand8() % 9) + 8;
    D_80106E90_13CBC0_HotBobOmb[2] = (u8)(rand8() % 9) + 6;
    D_80106E90_13CBC0_HotBobOmb[3] = (u8)(rand8() % 7) + 4;
    D_80106E88_13CBB8_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[D_80106E80_13CBB0_HotBobOmb];
    D_80106E8C_13CBBC_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[3];
    D_80106EA0_13CBD0_HotBobOmb = 0x28;
    D_80106EA2_13CBD2_HotBobOmb = 0x1E;
    omAddObj(0, 0, 0, -1, func_80102A74_1387A4_HotBobOmb);
}

/* Counts the fuse down one second every 30 frames. */
void func_80102A28_138758_HotBobOmb(omObjData* obj) {
    D_80106EA2_13CBD2_HotBobOmb--;
    if (D_80106EA2_13CBD2_HotBobOmb == 0) {
        D_80106EA2_13CBD2_HotBobOmb = 0x1E;
        if (D_80106E88_13CBB8_HotBobOmb > 0) {
            D_80106E88_13CBB8_HotBobOmb--;
        }
    }
}

/* The start message; once it closes the game runs and the fuse starts. */
void func_80102A74_1387A4_HotBobOmb(omObjData* obj) {
    if (D_80106EA0_13CBD0_HotBobOmb == 0x28) {
        D_80106E86_13CBB6_HotBobOmb = PlaySound(0x4A3);
    }
    if (D_80106EA0_13CBD0_HotBobOmb != 0) {
        D_80106EA0_13CBD0_HotBobOmb--;
        if (D_80106EA0_13CBD0_HotBobOmb == 0) {
            func_800799A4_7A5A4(D_80106E86_13CBB6_HotBobOmb, 0x5A);
            func_800691FC_69DFC(0);
        }
    }
    if ((s16)func_80069538_6A138() == 2) {
        D_8010700C_13CD3C_HotBobOmb = 1;
        obj->func_ptr = func_80102A28_138758_HotBobOmb;
    }
}

void func_80102B30_138860_HotBobOmb(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = 20.0f;
    D_800FD474_FE074.x = -52.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1050.0f;
    D_80106F9C_13CCCC_HotBobOmb.x = 0.0f;
    D_80106F9C_13CCCC_HotBobOmb.y = 50.0f;
    D_80106F9C_13CCCC_HotBobOmb.z = 50.0f;
    D_80106FBC_13CCEC_HotBobOmb.x = 0.0f;
    D_80106FBC_13CCEC_HotBobOmb.y = 0.0f;
    D_80106FBC_13CCEC_HotBobOmb.z = -120.0f;
    D_80106FD8_13CD08_HotBobOmb.x = 0.0f;
    D_80106FD8_13CD08_HotBobOmb.y = 1.0f;
    D_80106FD8_13CD08_HotBobOmb.z = 0.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 45.0f, 80.0f, 8000.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
}

/* Unused: applies the camera. */
void func_80102CD4_138A04_HotBobOmb(void) {
    Hu3DCamSetPositionOrientation(0, &D_80106F9C_13CCCC_HotBobOmb, &D_80106FBC_13CCEC_HotBobOmb,
                                  &D_80106FD8_13CD08_HotBobOmb);
    Hu3DCamUpdateMtx(0);
}

void func_80102D10_138A40_HotBobOmb(omObjData* obj) {
    if (D_80106F90_13CCC0_HotBobOmb != 0) {
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
    } else if (D_801011FC_101DFC == 1) {
        func_80079614_7A214(0x3C);
        func_800794A8_7A0A8(0x3C);
        InitFadeOut(0, 0x14);
        D_80106F90_13CCC0_HotBobOmb = 1;
    }
}

/* The stage model's object, once loaded: starts the music. */
void func_80102D8C_138ABC_HotBobOmb(omObjData* obj) {
    func_8000C3C8_CFC8();
    if (D_80106C54_13C984_HotBobOmb == 0) {
        PlayMusic(0x1B);
        D_80106C54_13C984_HotBobOmb = 1;
    }
}

/* The fuse sprite. */
s16 func_80102DCC_138AFC_HotBobOmb(void) {
    s16 spr;
    void* data;
    s16 anim;

    spr = SprCreate(1, 5);
    data = DataRead(0x1C0004);
    anim = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, anim, 0);
    SprPosSet(spr, 0, 0xA0, 0xC8);
    SprAttrReset(spr, 0, 0xFFFF);
    SprAttrSet(spr, 0, 8);
    SprPrioSet(spr, 0, 0x7000);
    return spr;
}

void func_80102E94_138BC4_HotBobOmb(void) {
    void* data;

    D_80106F92_13CCC2_HotBobOmb = SprCreate(1, 5);
    data = DataRead(0x1C0003);
    D_80106FCC_13CCFC_HotBobOmb = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(D_80106F92_13CCC2_HotBobOmb, 0, D_80106FCC_13CCFC_HotBobOmb, 0);
    SprPosSet(D_80106F92_13CCC2_HotBobOmb, 0, 0xA0, 0x78);
    SprAttrReset(D_80106F92_13CCC2_HotBobOmb, 0, 0xFFFF);
    SprAttrSet(D_80106F92_13CCC2_HotBobOmb, 0, 0x4000);
    SprPrioSet(D_80106F92_13CCC2_HotBobOmb, 0, 0x8000);
    D_80106ED8_13CC08_HotBobOmb = func_80102DCC_138AFC_HotBobOmb();
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 4, 0, -1, func_80102FF0_138D20_HotBobOmb);
    D_80106C44_13C974_HotBobOmb = 280.0f;
    omAddObj(1, 4, 0, -1, func_80103034_138D64_HotBobOmb);
}

void func_80102FF0_138D20_HotBobOmb(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x1C0001, 0x28D);
    obj->func_ptr = func_80102D8C_138ABC_HotBobOmb;
}

/* The fuse sprite: slides in, then bobs (faster as the round ends).
   NON_MATCHING: retail keeps min in s0 and max in s1, and reloads the period for the divide
   (address CSE'd, value not); masked 4. */
#ifdef NON_MATCHING
void func_80103034_138D64_HotBobOmb(omObjData* obj) {
    s32 max;
    s32 min;

    switch (D_8010700C_13CD3C_HotBobOmb) {
    case 0:
        D_80106C44_13C974_HotBobOmb =
            (D_80106C44_13C974_HotBobOmb > 200.0f) ? D_80106C44_13C974_HotBobOmb - 4.0f : 200.0f;
        min = 10;
        max = 16;
        break;
    case 1:
        D_80106C44_13C974_HotBobOmb = 200.0f;
        min = 8;
        max = 16;
        break;
    case 2:
        min = 4;
        D_80106C44_13C974_HotBobOmb = 200.0f;
        max = 6;
        break;
    }
    if (--D_80106E8C_13CBBC_HotBobOmb == 0) {
        if (D_80106EE8_13CC18_HotBobOmb == 7) {
            D_80106E8C_13CBBC_HotBobOmb = 4;
        } else {
            D_80106E8C_13CBBC_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[3] = rand8() % (max - min + 1) + min;
        }
    }
    obj->trans.y = HuMathSin(((f32)D_80106E90_13CBC0_HotBobOmb[3] - (f32)D_80106E8C_13CBBC_HotBobOmb) /
                                 (f32)D_80106E90_13CBC0_HotBobOmb[3] * 180.0f) * 8.0f +
                   D_80106C44_13C974_HotBobOmb;
    SprPosSet(D_80106ED8_13CC08_HotBobOmb, 0, 0xA0, obj->trans.y);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80103034_138D64_HotBobOmb);
#endif

void func_8010322C_138F5C_HotBobOmb(void) {
    s32 i;

    D_80106C30_13C960_HotBobOmb = 0;
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 1, 0x14, -1, func_8010349C_1391CC_HotBobOmb);
    }
    D_80106ED4_13CC04_HotBobOmb = omAddObj(2, 0xC, 0xA, -1, func_80105124_13AE54_HotBobOmb);
}

void func_801032EC_13901C_HotBobOmb(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80106E70_13CBA0_HotBobOmb[i] = gPlayers[i].port;
        D_80106FA8_13CCD8_HotBobOmb[i] = 0;
        D_80106FE8_13CD18_HotBobOmb[i] = 1;
        D_80106F28_13CC58_HotBobOmb[i] = 0;
        D_80106FE8_13CD18_HotBobOmb[i] = 1;
        D_80106EC0_13CBF0_HotBobOmb[i] = 0;
        D_80106EF0_13CC20_HotBobOmb[i] = 1;
        D_80106F7C_13CCAC_HotBobOmb = D_80106BE0_13C910_HotBobOmb[i][D_80107028_13CD58_HotBobOmb];
        D_80106F80_13CCB0_HotBobOmb[i] = 0;
        if (!(gPlayers[i].flags & 1)) {
            D_80107010_13CD40_HotBobOmb[i] = 1;
        } else {
            D_80107010_13CD40_HotBobOmb[i] = 0;
        }
    }
    D_8010700C_13CD3C_HotBobOmb = 0;
    D_80106FB8_13CCE8_HotBobOmb = 2;
    D_80106EE4_13CC14_HotBobOmb = 0;
    D_80106E80_13CBB0_HotBobOmb = 0;
    D_80107028_13CD58_HotBobOmb = 0;
    D_80106FFC_13CD2C_HotBobOmb = -1;
    D_80106F78_13CCA8_HotBobOmb = 0;
    D_80106F90_13CCC0_HotBobOmb = 0;
    D_80106FE8_13CD18_HotBobOmb[0] = 1;
    D_80106F28_13CC58_HotBobOmb[0] = 3;
    if (_CheckFlag(0xC) != 0) {
        D_80106E84_13CBB4_HotBobOmb = 1;
    } else {
        D_80106E84_13CBB4_HotBobOmb = 0;
    }
}

/* A player object: the character's model and motions, placed at its seat. */
void func_8010349C_1391CC_HotBobOmb(omObjData* obj) {
    s32 dir;
    s32 mot;

    dir = D_800CD438_CE038[(s8)gPlayers[D_80106B10_13C840_HotBobOmb[D_80106C30_13C960_HotBobOmb]].character].unk_04;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[(s8)gPlayers[D_80106B10_13C840_HotBobOmb[D_80106C30_13C960_HotBobOmb]].character].unk_08, 0x2D9);
    obj->model[1] = func_80018A64_19664(0xD, 0x2D9);
    obj->work[0] = 0;
    func_80018CCC_198CC(obj, 4, dir);
    func_80018CCC_198CC(obj, 0, dir | 0x16);
    func_80018CCC_198CC(obj, 6, dir | 0x48);
    func_80018CCC_198CC(obj, 7, dir | 0x47);
    if (!(rand8() & 1)) {
        D_80106F08_13CC38_HotBobOmb[D_80106C30_13C960_HotBobOmb] = mot = dir | 0x4E;
    } else {
        D_80106F08_13CC38_HotBobOmb[D_80106C30_13C960_HotBobOmb] = mot = dir | 0x4F;
    }
    func_80018CCC_198CC(obj, 8, mot);
    func_80018CCC_198CC(obj, 0xA, dir | 0x55);
    func_80018CCC_198CC(obj, 0xB, dir | 0x61);
    func_80018CCC_198CC(obj, 0xC, dir | 0x62);
    func_80018CCC_198CC(obj, 0xD, dir | 0x63);
    func_80018CCC_198CC(obj, 0xE, dir | 0x64);
    func_80018CCC_198CC(obj, 0xF, dir | 0x65);
    func_80018CCC_198CC(obj, 0x10, dir | 0x66);
    func_80018CCC_198CC(obj, 0x11, dir | 0x67);
    func_80018CCC_198CC(obj, 0x12, dir | 0x68);
    func_80018CCC_198CC(obj, 0x13, dir | 0x69);
    obj->scale.x = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].scale;
    obj->scale.y = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].scale;
    obj->scale.z = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].scale;
    obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].pos.x;
    obj->trans.y = 0.0f;
    obj->trans.z = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].pos.z;
    obj->rot.y = D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb].rot;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029B80_2A780(obj->model[0], obj->motion[4]);
    obj->unk_50 = &D_80106B20_13C850_HotBobOmb[D_80106C30_13C960_HotBobOmb];
    D_80106C30_13C960_HotBobOmb++;
    obj->func_ptr = func_801037D0_139500_HotBobOmb;
}

/* A player object's frame: the player state machine (D_80106F28_13CC58_HotBobOmb[player]):
   0 idle, 1 blown up, 2 back to idle, 3 bomb incoming (B dodges), 4 dodging, 5 catch, 6 throw,
   7 dodge recovered (the bomb drops at the seat), 8 dodged, 9 holding. */
void func_801037D0_139500_HotBobOmb(omObjData* obj) {
    s32 dur[3] = { 16, 14, 12 };
    HBSeat* seat;
    s32 player;
    s32 i;
    f32 frame;
    f32 end;
    s32 n;

    seat = obj->unk_50;
    player = seat->player;
    D_80106F7C_13CCAC_HotBobOmb = D_80106BE0_13C910_HotBobOmb[player][D_80107028_13CD58_HotBobOmb];
    if (D_8010700C_13CD3C_HotBobOmb == 1) {
        func_80104790_13A4C0_HotBobOmb(player);
    }
    switch (D_80106F28_13CC58_HotBobOmb[player]) {
    case 0:
        if (D_80106FE8_13CD18_HotBobOmb[player] != 0 && player != D_80107028_13CD58_HotBobOmb) {
            D_80106FE8_13CD18_HotBobOmb[player] = 0;
            func_80029E80_2AA80(obj->model[0], 6, 2);
            if (D_80106F7C_13CCAC_HotBobOmb == 1) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[7]), 0,
                                    (s16)D_80106FD4_13CD04_HotBobOmb + 8, 2);
            } else if (D_80106F7C_13CCAC_HotBobOmb == 0) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[6]), 0,
                                    (s16)D_80106FD4_13CD04_HotBobOmb + 8, 2);
            } else {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[4]), 0,
                                    (s16)D_80106FD4_13CD04_HotBobOmb + 8, 2);
            }
        }
        break;
    case 2:
        if (D_80106FE8_13CD18_HotBobOmb[player] == 0) {
            D_80106EC0_13CBF0_HotBobOmb[player] = 0;
            D_80106FE8_13CD18_HotBobOmb[player] = 1;
            D_80106F28_13CC58_HotBobOmb[player] = 0;
        }
        break;
    case 3:
        if (D_80106FE8_13CD18_HotBobOmb[player] != 0) {
            D_80106FE8_13CD18_HotBobOmb[player] = 0;
            func_80029E80_2AA80(obj->model[0], 2, 0);
            if (D_80106FB8_13CCE8_HotBobOmb == 0) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[12]), 0, 8, 0);
            } else if (D_80106FB8_13CCE8_HotBobOmb == 1) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[13]), 0, 8, 0);
            } else {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[11]), 0, 8, 0);
            }
            D_80106EA4_13CBD4_HotBobOmb = 2;
        }
        if (D_80106FD0_13CD00_HotBobOmb == 0 && D_80106F94_13CCC4_HotBobOmb == 0) {
            if (D_80106EE8_13CC18_HotBobOmb == 0 || D_80106EE8_13CC18_HotBobOmb == 9) {
                for (i = 0; i < 4; i++) {
                    if (D_80106F28_13CC58_HotBobOmb[i] == 0) {
                        D_80106EF0_13CC20_HotBobOmb[i] = 1;
                    }
                }
                D_80106FE8_13CD18_HotBobOmb[player] = 1;
                D_80106F28_13CC58_HotBobOmb[player] = 5;
            } else if (D_80106EA4_13CBD4_HotBobOmb == 0) {
                if (D_80106FB8_13CCE8_HotBobOmb == 0) {
                    func_80029B80_2A780(obj->model[0], obj->motion[18]);
                } else if (D_80106FB8_13CCE8_HotBobOmb == 1) {
                    func_80029B80_2A780(obj->model[0], obj->motion[19]);
                } else {
                    func_80029B80_2A780(obj->model[0], obj->motion[17]);
                }
                func_80029E80_2AA80(obj->model[0], 4, 0);
                func_80029E80_2AA80(obj->model[0], 2, 0);
                D_80106FF8_13CD28_HotBobOmb = player;
                D_80106FA8_13CCD8_HotBobOmb[player] = 0x2D;
                D_80106F28_13CC58_HotBobOmb[player] = 7;
                D_80106FD0_13CD00_HotBobOmb = 4;
                D_80106EE8_13CC18_HotBobOmb = 3;
                func_80015710_16310((s16)PlaySound(0x17B), D_80106C34_13C964_HotBobOmb[player]);
            }
            if (D_80106EA4_13CBD4_HotBobOmb != 0) {
                D_80106EA4_13CBD4_HotBobOmb--;
            }
        }
        break;
    case 4:
        if (D_80106FD0_13CD00_HotBobOmb < 8) {
            if (D_80106FD0_13CD00_HotBobOmb > 0) {
                D_80106F28_13CC58_HotBobOmb[player] = 8;
            } else if (D_80106F94_13CCC4_HotBobOmb != 0) {
                D_80106FE8_13CD18_HotBobOmb[player] = 1;
                D_80106F28_13CC58_HotBobOmb[player] = 5;
            }
        } else {
            D_80106FE8_13CD18_HotBobOmb[player] = 0;
            D_80106EA4_13CBD4_HotBobOmb = 0;
            D_80106F28_13CC58_HotBobOmb[player] = 3;
        }
        break;
    case 5:
        D_80106EF0_13CC20_HotBobOmb[player] = 1;
        D_80106FF8_13CD28_HotBobOmb = player;
        if (D_80106FE8_13CD18_HotBobOmb[player] != 0) {
            D_80106FE8_13CD18_HotBobOmb[player] = 0;
            func_80029E80_2AA80(obj->model[0], 4, 4);
            func_80029E80_2AA80(obj->model[0], 2, 0);
            if (D_80106FB8_13CCE8_HotBobOmb == 0) {
                func_80029B80_2A780(obj->model[0], obj->motion[15]);
            } else if (D_80106FB8_13CCE8_HotBobOmb == 1) {
                func_80029B80_2A780(obj->model[0], obj->motion[16]);
            } else {
                func_80029B80_2A780(obj->model[0], obj->motion[14]);
            }
            func_80015710_16310((s16)PlaySound(0x17A), D_80106C34_13C964_HotBobOmb[player]);
        }
        frame = func_80029CE4_2A8E4(obj->model[0]);
        func_80029D0C_2A90C(obj->model[0]);
        if (frame == 6.0f) {
            for (i = 0; i < 5; i++) {
                func_8002C628_2D228(D_80106EA6_13CBD6_HotBobOmb[i], obj->model[0], "item_hook");
                func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0x4000);
            }
        }
        if (frame == 14.0f) {
            func_80029E80_2AA80(obj->model[0], 8, 8);
            if (D_80106EE8_13CC18_HotBobOmb != 0 && D_80106EE8_13CC18_HotBobOmb != 9) {
                D_80106FA8_13CCD8_HotBobOmb[player] = 0x1E;
            }
            D_80106EE8_13CC18_HotBobOmb = 1;
            D_80106F28_13CC58_HotBobOmb[player] = 9;
        }
        break;
    case 7:
        D_80106EF0_13CC20_HotBobOmb[player] = 0;
        D_80106FE8_13CD18_HotBobOmb[player] = 0;
        frame = func_80029CE4_2A8E4(obj->model[0]);
        end = func_80029D0C_2A90C(obj->model[0]);
        if (frame == 0.0f) {
            for (i = 0; i < 5; i++) {
                func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0);
            }
        }
        if (frame == 48.0f) {
            for (i = 0; i < 5; i++) {
                func_8002C628_2D228(D_80106EA6_13CBD6_HotBobOmb[i], obj->model[0], "item_hook");
                func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0x4000);
            }
        }
        if (frame == end) {
            for (i = 0; i < 5; i++) {
                func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0);
            }
            D_80106ED4_13CC04_HotBobOmb->trans.x = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.x;
            D_80106ED4_13CC04_HotBobOmb->trans.y = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.y;
            D_80106EE8_13CC18_HotBobOmb = 1;
            D_80106EF0_13CC20_HotBobOmb[player] = 1;
            D_80106F28_13CC58_HotBobOmb[player] = 9;
        }
        break;
    case 6:
        if (D_80106FF8_13CD28_HotBobOmb + D_80107028_13CD58_HotBobOmb == 3) {
            D_80106F78_13CCA8_HotBobOmb = 1;
        } else {
            D_80106F78_13CCA8_HotBobOmb = 0;
        }
        if (player == D_80106FF8_13CD28_HotBobOmb) {
            if (D_80106FE8_13CD18_HotBobOmb[player] != 0) {
                D_80106FE8_13CD18_HotBobOmb[player] = 0;
                func_80029E80_2AA80(obj->model[0], 8, 0);
                if (D_80106FB8_13CCE8_HotBobOmb == 0) {
                    func_80029B80_2A780(obj->model[0], obj->motion[16]);
                } else if (D_80106FB8_13CCE8_HotBobOmb == 1) {
                    func_80029B80_2A780(obj->model[0], obj->motion[15]);
                } else {
                    func_80029B80_2A780(obj->model[0], obj->motion[14]);
                }
                func_80029E80_2AA80(obj->model[0], 6, 0);
                func_8002C6F4_2D2F4(&D_800FC834_FD434[obj->model[0]], 2);
                if (D_80106FA8_13CCD8_HotBobOmb[player] == 0) {
                    func_8002C6F4_2D2F4(&D_800FC834_FD434[obj->model[0]], 0xE);
                }
                for (i = 0; i < 5; i++) {
                    func_8002C628_2D228(D_80106EA6_13CBD6_HotBobOmb[i], obj->model[0], "item_hook");
                    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0x4000);
                }
                for (i = 0; i < 4; i++) {
                    if (D_80106F28_13CC58_HotBobOmb[i] == 0) {
                        D_80106FE8_13CD18_HotBobOmb[i] = 1;
                    }
                }
                func_80015710_16310((s16)PlaySound(0x179), D_80106C34_13C964_HotBobOmb[player]);
            }
            if (func_80029CE4_2A8E4(obj->model[0]) == func_80029D0C_2A90C(obj->model[0])) {
                for (i = 0; i < 5; i++) {
                    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 0x4000, 0);
                }
                D_80106FA8_13CCD8_HotBobOmb[player] = 0xF;
                D_80106F28_13CC58_HotBobOmb[player] = 2;
                D_80106FE8_13CD18_HotBobOmb[D_80107028_13CD58_HotBobOmb] = 1;
                D_80106FA8_13CCD8_HotBobOmb[D_80107028_13CD58_HotBobOmb] = 0;
                D_80106F28_13CC58_HotBobOmb[D_80107028_13CD58_HotBobOmb] = 3;
                D_80106EE8_13CC18_HotBobOmb = 2;
                n = dur[D_80106E80_13CBB0_HotBobOmb] -
                    (dur[D_80106E80_13CBB0_HotBobOmb] - D_80106E88_13CBB8_HotBobOmb) * 0.2;
                D_80106FD4_13CD04_HotBobOmb = n;
                D_80106EB0_13CBE0_HotBobOmb = (f32)D_80106FD4_13CD04_HotBobOmb - (f32)D_80106FD0_13CD00_HotBobOmb;
                D_80106FD0_13CD00_HotBobOmb = n;
                D_80106F94_13CCC4_HotBobOmb = 0;
            }
        }
        break;
    case 8:
        D_80106EF0_13CC20_HotBobOmb[player] = 0;
        if (D_80106FD0_13CD00_HotBobOmb == 0) {
            D_80106FE8_13CD18_HotBobOmb[player] = 1;
            D_80106EF0_13CC20_HotBobOmb[player] = 1;
            D_80106F28_13CC58_HotBobOmb[player] = 5;
        }
        break;
    case 9:
        D_80106FF8_13CD28_HotBobOmb = player;
        if (D_80106FA8_13CCD8_HotBobOmb[player] == 0) {
            D_80106ED4_13CC04_HotBobOmb->trans.x = D_80106B20_13C850_HotBobOmb[player].bomb.x;
            func_80029E80_2AA80(obj->model[0], 8, 0);
        }
        break;
    case 1:
        D_80106EF0_13CC20_HotBobOmb[player] = 0;
        if (D_80106FE8_13CD18_HotBobOmb[player] != 0) {
            func_80029E80_2AA80(obj->model[0], 8, 0);
            for (i = 0; i < 5; i++) {
                func_800298A4_2A4A4(D_80106ED4_13CC04_HotBobOmb->model[i], 0x4000, 0);
            }
            D_80106FE8_13CD18_HotBobOmb[player] = 0;
            D_80107028_13CD58_HotBobOmb = func_80104674_13A3A4_HotBobOmb(player, 0);
            func_80029B80_2A780(obj->model[0], obj->motion[0]);
            func_80029E80_2AA80(obj->model[0], 2, 2);
        }
        break;
    case 10:
        break;
    }
    if (seat->t > 1.0f) {
        seat->t = 0.0f;
    } else {
        seat->t += 0.033333335f;
    }
    if (D_80106FA8_13CCD8_HotBobOmb[player] != 0) {
        D_80106FA8_13CCD8_HotBobOmb[player]--;
    }
    if (D_80107018_13CD48_HotBobOmb[player] != 0) {
        D_80107018_13CD48_HotBobOmb[player]--;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
}

/* The stick's direction as a 3x3 grid index (4 = centre); from MP1 func_800F99F4 (dead zone 8).
   NON_MATCHING: retail reuses x/y's registers for dx/dy and fills the branch delay slots
   differently (beql dy = 0; bgtz with dy = 1 in the slot); masked 16-24 in three shapes. MP1's
   copy is NON_MATCHING too. */
#ifdef NON_MATCHING
s32 func_801045B0_13A2E0_HotBobOmb(s8 arg0, s8 arg1) {
    s32 x;
    s32 y;
    s32 ax;
    s32 ay;
    s32 dx;
    s32 dy;

    x = arg0;
    y = arg1;
    ax = x;
    if (ax < 0) {
        ax = -ax;
    }
    ay = y;
    if (ay < 0) {
        ay = -ay;
    }
    if (ay < ax) {
        if (ax / 2 < ay) {
            dy = 1;
            if (y <= 0) {
                dy = -1;
            }
        } else {
            dy = 0;
        }
        if (x > 8) {
            dx = 1;
        } else {
            dx = -(x < -8);
        }
    } else {
        if (ay / 2 < ax) {
            dx = 1;
            if (x <= 0) {
                dx = -1;
            }
        } else {
            dx = 0;
        }
        if (y > 8) {
            dy = 1;
        } else {
            dy = -(y < -8);
        }
    }
    return (dy + 1) * 3 + 1 + dx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801045B0_13A2E0_HotBobOmb);
#endif

/* GCC does not see INCLUDE_ASM switch to .text: its local tables must land in .rodata */
__asm__(".section .rodata");

/* The player a throw in stick direction dir reaches; an eliminated target passes to the next
   player round the table, and with none left the thrower keeps it. */
s32 func_80104674_13A3A4_HotBobOmb(s32 player, u32 dir) {
    s32 tbl[4][9] = {
        { 3, 3, 2, 3, 2, 1, 3, 1, 1 },
        { 3, 3, 2, 0, 3, 2, 0, 0, 2 },
        { 3, 3, 3, 3, 0, 1, 0, 1, 1 },
        { 2, 2, 2, 0, 1, 2, 0, 0, 1 },
    };
    s32 next[4][4] = {
        { 1, 2, 3, 0 },
        { 2, 3, 0, 1 },
        { 3, 0, 1, 2 },
        { 0, 1, 2, 3 },
    };
    s32 ret;
    s32 i;

    if (dir >= 10) {
        dir = 4;
    }
    ret = tbl[player][dir];
    i = 0;
    while (D_80106F28_13CC58_HotBobOmb[ret] == 1) {
        if (i >= 3) {
            ret = player;
            break;
        }
        ret = next[player][i++];
    }
    return ret;
}

/* A player's input for the frame (pad, or the CPU), and A (throw) / B (dodge). */
void func_80104790_13A4C0_HotBobOmb(s32 player) {
    s32 r;

    D_80106F00_13CC30_HotBobOmb[player] = 0;
    D_80106F88_13CCB8_HotBobOmb[player] = 0;
    D_80106F20_13CC50_HotBobOmb[D_80106E70_13CBA0_HotBobOmb[player]] = 0;
    D_80107014_13CD44_HotBobOmb[D_80106E70_13CBA0_HotBobOmb[player]] = 0;
    func_80104674_13A3A4_HotBobOmb(player, func_801045B0_13A2E0_HotBobOmb(D_80106F20_13CC50_HotBobOmb[player],
                                                                        D_80107014_13CD44_HotBobOmb[player]));
    if (D_80107010_13CD40_HotBobOmb[player] == 1) {
        D_80106F00_13CC30_HotBobOmb[player] = ContBtn[D_80106E70_13CBA0_HotBobOmb[player]];
        D_80106F88_13CCB8_HotBobOmb[player] = ContBtnTrg[D_80106E70_13CBA0_HotBobOmb[player]];
        D_80106F20_13CC50_HotBobOmb[player] = ContStkX[D_80106E70_13CBA0_HotBobOmb[player]];
        D_80107014_13CD44_HotBobOmb[player] = ContStkY[D_80106E70_13CBA0_HotBobOmb[player]];
    } else {
        func_80104A50_13A780_HotBobOmb(player);
    }
    if ((D_80106F88_13CCB8_HotBobOmb[player] & 0x8000) && D_80106F28_13CC58_HotBobOmb[player] == 9) {
        r = func_80104674_13A3A4_HotBobOmb(player, func_801045B0_13A2E0_HotBobOmb(D_80106F20_13CC50_HotBobOmb[player],
                                                                                D_80107014_13CD44_HotBobOmb[player]));
        D_80107028_13CD58_HotBobOmb = r;
        D_80106FA8_13CCD8_HotBobOmb[player] = 0;
        D_80106FB8_13CCE8_HotBobOmb = D_80106BE0_13C910_HotBobOmb[player][r];
        D_80106FE8_13CD18_HotBobOmb[player] = 1;
        func_80029E80_2AA80(D_800FFFD8_100BD8[player]->model[0], 6, 0);
        D_80106F28_13CC58_HotBobOmb[player] = 6;
    }
    if (D_80106F88_13CCB8_HotBobOmb[player] & 0x4000) {
        if (D_80106EC0_13CBF0_HotBobOmb[player] == 0 && D_80106F28_13CC58_HotBobOmb[player] == 3 &&
            D_80106EF0_13CC20_HotBobOmb[player] != 0) {
            D_80106FA8_13CCD8_HotBobOmb[player] = 0xF;
            D_80106FE8_13CD18_HotBobOmb[player] = 1;
            if (D_80106FD0_13CD00_HotBobOmb >= 7) {
                D_80106EC0_13CBF0_HotBobOmb[player]++;
            }
            D_80106F28_13CC58_HotBobOmb[player] = 4;
        }
    }
}

/* A CPU player: dodges an incoming bomb at a difficulty-scaled chance, and throws after a random
   hold. */
void func_80104A50_13A780_HotBobOmb(s32 player) {
    s32 chance;
    s32 r;

    chance = gPlayers[player].cpu_difficulty;
    switch (gPlayers[player].cpu_difficulty) {
    case 0:
        chance = 10;
        break;
    case 1:
        chance = 20;
        break;
    case 2:
        chance = 30;
        break;
    case 3:
        chance = 40;
        break;
    }
    if (D_80106F28_13CC58_HotBobOmb[player] == 3) {
        if (D_80106FD0_13CD00_HotBobOmb < (rand8() & 3) + 5 && rand8() % (chance + 1) != 0) {
            D_80106FA8_13CCD8_HotBobOmb[player] = 0xF;
            D_80106FE8_13CD18_HotBobOmb[player] = 1;
            D_80106F28_13CC58_HotBobOmb[player] = 4;
        }
        D_80107018_13CD48_HotBobOmb[player] = rand8() % (D_80106E88_13CBB8_HotBobOmb + 9) + 10;
    }
    if (D_80106F28_13CC58_HotBobOmb[player] == 9) {
        D_80106FF8_13CD28_HotBobOmb = player;
        if (D_80106E88_13CBB8_HotBobOmb != 0 && D_80107018_13CD48_HotBobOmb[player] == 0) {
            r = func_80104674_13A3A4_HotBobOmb(player, rand8() & 7);
            D_80107028_13CD58_HotBobOmb = r;
            D_80106FB8_13CCE8_HotBobOmb = D_80106BE0_13C910_HotBobOmb[player][r];
            D_80106FA8_13CCD8_HotBobOmb[player] = 0;
            D_80106FE8_13CD18_HotBobOmb[player] = 1;
            func_80029E80_2AA80(D_800FFFD8_100BD8[player]->model[0], 6, 0);
            D_80106F28_13CC58_HotBobOmb[player] = 6;
        }
    }
}

/* Unused: creates the three explosion models. */
void func_80104CD4_13AA04_HotBobOmb(void) {
    HmfModel* m;
    s32 i;

    for (i = 0; i < 3; i++) {
        D_80106EB4_13CBE4_HotBobOmb[i] = func_80018A30_19630(0x3B000E, 0x99);
        func_800298A4_2A4A4(D_80106EB4_13CBE4_HotBobOmb[i], 4, 4);
        m = &D_800FC834_FD434[D_80106EB4_13CBE4_HotBobOmb[i]];
        m->unk40 = 0.0f;
        m->unk44 = 0.0f;
        if (m->hmf->unk9C != NULL) {
            m->hmf->unk9C->unk08 = 0.0f;
        }
    }
}

/* Hides each explosion model whose animation has ended. */
void func_80104D80_13AAB0_HotBobOmb(void) {
    HmfModel* m;
    s32 i;

    for (i = 0; i < 3; i++) {
        m = &D_800FC834_FD434[D_80106EB4_13CBE4_HotBobOmb[i]];
        if (func_80029D0C_2A90C(D_80106EB4_13CBE4_HotBobOmb[i]) <= m->unk40) {
            func_800298A4_2A4A4(D_80106EB4_13CBE4_HotBobOmb[i], 4, 4);
            m->unk40 = 0.0f;
            m->unk44 = 0.0f;
            if (m->hmf->unk9C != NULL) {
                m->hmf->unk9C->unk08 = 0.0f;
            }
        }
    }
}

/* Starts the explosion at (x, y, z), larger nearer the camera. */
void func_80104E34_13AB64_HotBobOmb(f32 x, f32 y, f32 z, f32 scale) {
    HmfModel* m;
    s32 i;

    i = 0;
    m = &D_800FC834_FD434[D_80106EB4_13CBE4_HotBobOmb[0]];
    if (y < 0.0) {
        y = 0.0f;
    }
    scale = scale * ((z + 600.0) / 600.0);
    func_800298A4_2A4A4(D_80106EB4_13CBE4_HotBobOmb[i], 4, 0);
    func_80029714_2A314(D_80106EB4_13CBE4_HotBobOmb[i], x, y + 8.0 + 100.0, z + 100.0f);
    func_800297E8_2A3E8(D_80106EB4_13CBE4_HotBobOmb[i], scale, scale, scale);
    m->unk44 = 1.0f;
}

/* The bomb's models follow the object; the fuse spark animates at half speed. From MP1
   func_800F77B8. */
void func_80104F7C_13ACAC_HotBobOmb(omObjData* obj, s32 unused) {
    HmfModel* m;
    s32 i;

    if (obj->scale.x > 2.0f) {
        obj->scale.x = 2.0f;
        obj->scale.y = 2.0f;
        obj->scale.z = 2.0f;
    }
    for (i = 0; i < 4; i++) {
        m = &D_800FC834_FD434[obj->model[i]];
        if (++D_80106C6C_13C99C_HotBobOmb >= D_800F92B4_F9EB4[m->unk02].unk02 * 2) {
            D_80106C6C_13C99C_HotBobOmb = 0;
        }
        m->unk40 = D_80106C6C_13C99C_HotBobOmb / 2;
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_8002979C_2A39C(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80029714_2A314(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
    }
    func_800297E8_2A3E8(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002979C_2A39C(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
}

/* The bomb object: five bomb models (each with its texture animation), three explosion models and
   a shadow, above the table. */
void func_80105124_13AE54_HotBobOmb(omObjData* obj) {
    u16 mdl;
    void* data;
    HmfModel* m;
    s16 fx;
    s32 attr;
    s32 i;

    attr = 0x99;
    D_80106EA6_13CBD6_HotBobOmb[0] = obj->model[0] = LoadFormFile(0x1C0000, 0x68D);
    D_80106EA6_13CBD6_HotBobOmb[1] = obj->model[1] = LoadFormFile(0x1C0000, 0x68D);
    D_80106EA6_13CBD6_HotBobOmb[2] = obj->model[2] = LoadFormFile(0x1C0000, 0x68D);
    D_80106EA6_13CBD6_HotBobOmb[3] = obj->model[3] = LoadFormFile(0x1C0000, 0x68D);
    D_80106EA6_13CBD6_HotBobOmb[4] = obj->model[4] = LoadFormFile(0x1C0000, 0x28D);
    mdl = obj->model[0];
    data = DataRead(0x1C0005);
    D_80106EDA_13CC0A_HotBobOmb[0] = func_8003D8F0_3E4F0(D_800FC834_FD434[mdl].hmf, data, 0, "c104_n0_DEF");
    func_8003E4F4_3F0F4(D_80106EDA_13CC0A_HotBobOmb[0], 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(mdl);
    mdl = obj->model[1];
    data = DataRead(0x1C0006);
    D_80106EDA_13CC0A_HotBobOmb[1] = func_8003D8F0_3E4F0(D_800FC834_FD434[mdl].hmf, data, 0, "c104_n0_DEF");
    func_8003E4F4_3F0F4(D_80106EDA_13CC0A_HotBobOmb[1], 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(mdl);
    mdl = obj->model[2];
    data = DataRead(0x1C0007);
    D_80106EDA_13CC0A_HotBobOmb[2] = func_8003D8F0_3E4F0(D_800FC834_FD434[mdl].hmf, data, 0, "c104_n0_DEF");
    func_8003E4F4_3F0F4(D_80106EDA_13CC0A_HotBobOmb[2], 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(mdl);
    mdl = obj->model[3];
    data = DataRead(0x1C0008);
    D_80106EDA_13CC0A_HotBobOmb[3] = func_8003D8F0_3E4F0(D_800FC834_FD434[mdl].hmf, data, 0, "c104_n0_DEF");
    func_8003E4F4_3F0F4(D_80106EDA_13CC0A_HotBobOmb[3], 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(mdl);
    mdl = obj->model[4];
    data = DataRead(0x1C0009);
    D_80106EDA_13CC0A_HotBobOmb[4] = func_8003D8F0_3E4F0(D_800FC834_FD434[mdl].hmf, data, 0, "c104_n0_DEF");
    func_8003E4F4_3F0F4(D_80106EDA_13CC0A_HotBobOmb[4], 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(mdl);
    for (i = 0; i < 3; i++) {
        fx = func_80018A30_19630(0x3B000E, attr);
        D_80106EB4_13CBE4_HotBobOmb[i] = obj->model[i + 6] = fx;
        func_800298A4_2A4A4(fx, 4, 4);
        func_800298A4_2A4A4(D_80106EB4_13CBE4_HotBobOmb[i], 0x70000000, 0x70000000);
        m = &D_800FC834_FD434[D_80106EB4_13CBE4_HotBobOmb[i]];
        m->unk40 = 0.0f;
        m->unk44 = 0.0f;
        if (m->hmf->unk9C != NULL) {
            m->hmf->unk9C->unk08 = 0.0f;
        }
    }
    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[0], 4, 0);
    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[1], 4, 4);
    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[2], 4, 4);
    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[3], 4, 4);
    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[4], 4, 4);
    obj->model[5] = func_80018A64_19664(0xD, 0x2D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 500.0f;
    obj->trans.z = 700.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    obj->rot.y = 0.0f;
    func_80018CCC_198CC(obj, 8, 0x1C0002);
    for (i = 0; i < 5; i++) {
        func_80029714_2A314(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_8002979C_2A39C(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_80029B80_2A780(obj->model[i], obj->motion[8]);
        func_80029E80_2AA80(obj->model[i], 2, 2);
    }
    func_80029714_2A314(obj->model[5], obj->trans.x, 1.0f, obj->trans.z);
    func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[5], obj->scale.x, obj->scale.y, obj->scale.z);
    D_80106EE8_13CC18_HotBobOmb = 0;
    D_80106FD0_13CD00_HotBobOmb = 0x1A;
    D_80106F1C_13CC4C_HotBobOmb = 0;
    D_80106FD4_13CD04_HotBobOmb = 0x1A;
    D_80106FD0_13CD00_HotBobOmb = 0x1A;
    D_80106F94_13CCC4_HotBobOmb = 0;
    obj->func_ptr = func_801056C8_13B3F8_HotBobOmb;
}

/* The bomb object's frame: its state (D_80106EE8_13CC18_HotBobOmb) 0 drops in at the first
   holder, 1 held, 2 in flight to the catcher (t = flight progress), 3 dodged: drops at the seat,
   4 bounces, 5/6 picked up, 7 swells and explodes, 8 after the blast (next round or the end),
   9 next round starts, 10 the end. Then the fuse flicker, the swell pulse and the shadow.
   NON_MATCHING: retail ends case 2 with a dead `lw D_80107028; sll` before the break (3
   instructions GCC does not emit here) and sets i = 0 one slot later at the end; masked 72, all
   from that 4-instruction shift. */
#ifdef NON_MATCHING
void func_801056C8_13B3F8_HotBobOmb(omObjData* obj) {
    Vec start[4] = {
        { 340.0f, 500.0f, 700.0f },
        { -340.0f, 500.0f, 700.0f },
        { -340.0f, 500.0f, -700.0f },
        { 340.0f, 500.0f, -700.0f },
    };
    Vec* p;
    f32 t;
    f32 s;
    f32 v;
    s32 i;
    s32 k;
    s32 q;
    s32 n;
    s32 lim;

    t = ((f32)D_80106FD4_13CD04_HotBobOmb - (f32)D_80106FD0_13CD00_HotBobOmb - 1.0f) /
        ((f32)D_80106FD4_13CD04_HotBobOmb - 1.0f);
    D_80106E68_13CB98_HotBobOmb = 0;
    func_80104D80_13AAB0_HotBobOmb();
    switch (D_80106EE8_13CC18_HotBobOmb) {
    case 1:
        D_80106FD0_13CD00_HotBobOmb = 0;
        if (D_80106E88_13CBB8_HotBobOmb == 0) {
            D_80106EE8_13CC18_HotBobOmb = 7;
        }
        break;
    case 2:
        if (D_80106F78_13CCA8_HotBobOmb != 0) {
            obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].pos.x * (1.0f - t) +
                           t * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].pos.x;
        } else {
            obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.x * (1.0f - t) +
                           t * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.x;
        }
        obj->trans.z = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.z * (1.0f - t) +
                       t * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.z;
        obj->rot.y = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].rot * (1.0f - t) +
                     t * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].rot;
        obj->trans.y = HuMathSin(t * 180.0f) * D_80106EB0_13CBE0_HotBobOmb * D_80106EB0_13CBE0_HotBobOmb +
                       D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.y;
        if (D_80106FD0_13CD00_HotBobOmb == 0 && D_80106F94_13CCC4_HotBobOmb == 0) {
            D_80106F94_13CCC4_HotBobOmb = 4;
        }
        break;
    case 3:
        if (D_80106FD0_13CD00_HotBobOmb != 0) {
            if (D_80106F78_13CCA8_HotBobOmb != 0) {
                obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].pos.x;
            } else {
                obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.x;
            }
            obj->trans.z = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.z;
            obj->trans.y = (1.0f - t) * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.y + t * 0.0f;
            D_80106E64_13CB94_HotBobOmb = 1.0f;
        } else {
            D_80106E68_13CB98_HotBobOmb = 1;
        }
        break;
    case 4:
        obj->trans.y = HuMathSin(D_80106E64_13CB94_HotBobOmb * 180.0f) * 100.0f;
        if (D_80106E64_13CB94_HotBobOmb > 0.0f) {
            D_80106E64_13CB94_HotBobOmb -= 0.1f;
        }
        break;
    case 5:
        if (D_80106FD0_13CD00_HotBobOmb == 0) {
            D_80106FD0_13CD00_HotBobOmb = 8;
            D_80106EE8_13CC18_HotBobOmb = 6;
        }
        break;
    case 6:
        if (D_80106FD0_13CD00_HotBobOmb != 0) {
            if (D_80106F78_13CCA8_HotBobOmb != 0) {
                obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].pos.x;
            } else {
                obj->trans.x = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.x;
            }
            obj->trans.z = D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.z;
            obj->trans.y = (1.0f - t) * 0.0f + t * D_80106B20_13C850_HotBobOmb[D_80107028_13CD58_HotBobOmb].bomb.y;
        }
        break;
    case 7:
        D_80106FD0_13CD00_HotBobOmb = 0;
        for (i = 0; i < 4; i++) {
            D_80106EF0_13CC20_HotBobOmb[i] = 0;
        }
        if (obj->scale.x < 2.5 && obj->scale.y < 2.5 && obj->scale.z < 2.5) {
            obj->scale.x = obj->scale.x * obj->scale.x / (f32)((rand8() & 1) + 17) + obj->scale.x;
            obj->scale.y = obj->scale.y * obj->scale.y / (f32)((rand8() & 1) + 17) + obj->scale.y;
            obj->scale.z = obj->scale.z * obj->scale.z / (f32)((rand8() & 1) + 17) + obj->scale.z;
        } else {
            PlaySound(0x17C);
            func_80104E34_13AB64_HotBobOmb(obj->trans.x, obj->trans.y, obj->trans.z, obj->scale.x);
            for (i = 0; i < 5; i++) {
                func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[i], 4, 4);
            }
            func_800298A4_2A4A4(obj->model[5], 4, 4);
            obj->scale.x = 1.0f;
            obj->scale.y = 1.0f;
            obj->scale.z = 1.0f;
            for (i = 0; i < 5; i++) {
                func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
                func_8002979C_2A39C(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
                func_80029714_2A314(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
            }
            D_80106EA0_13CBD0_HotBobOmb = 0x3C;
            D_80106EE8_13CC18_HotBobOmb = 8;
            D_80106FE8_13CD18_HotBobOmb[D_80106FF8_13CD28_HotBobOmb] = 1;
            func_80015710_16310(func_800797DC_7A3DC(0xFC, (s16)D_80106FF8_13CD28_HotBobOmb),
                                D_80106C34_13C964_HotBobOmb[D_80106FF8_13CD28_HotBobOmb]);
            PlaySound(0xA8);
            omVibrate((s16)D_80106FF8_13CD28_HotBobOmb, 0x14, 0, 0x14);
            D_80106F28_13CC58_HotBobOmb[D_80106FF8_13CD28_HotBobOmb] = 1;
            D_80106F80_13CCB0_HotBobOmb[D_80106FF8_13CD28_HotBobOmb] = 3 - (u16)D_80106E80_13CBB0_HotBobOmb;
        }
        break;
    case 8:
        D_80106EA0_13CBD0_HotBobOmb--;
        if (D_80106EA0_13CBD0_HotBobOmb == 0) {
            D_80106C70_13C9A0_HotBobOmb = 0.0f;
            D_80106C74_13C9A4_HotBobOmb = -1.0f;
            D_80106C78_13C9A8_HotBobOmb = 0.0f;
            D_80106C7C_13C9AC_HotBobOmb = 0;
            D_80106C80_13C9B0_HotBobOmb = 0;
            D_80106C84_13C9B4_HotBobOmb = -1;
            D_80106F1C_13CC4C_HotBobOmb = D_80106E80_13CBB0_HotBobOmb;
            if (D_80106E80_13CBB0_HotBobOmb < 2) {
                D_80106FD4_13CD04_HotBobOmb = 0x1A;
                D_80106FD0_13CD00_HotBobOmb = 0x1A;
                D_80106E80_13CBB0_HotBobOmb++;
                D_80106FF8_13CD28_HotBobOmb = D_80107028_13CD58_HotBobOmb;
                D_80107028_13CD58_HotBobOmb = 4;
                D_80106FB8_13CCE8_HotBobOmb = 2;
                D_80106FE8_13CD18_HotBobOmb[D_80106FF8_13CD28_HotBobOmb] = 1;
                D_80106F28_13CC58_HotBobOmb[D_80106FF8_13CD28_HotBobOmb] = 3;
                D_80106FD4_13CD04_HotBobOmb = 0x1A;
                D_80106FD0_13CD00_HotBobOmb = 0x1A;
                D_80106E88_13CBB8_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[D_80106E80_13CBB0_HotBobOmb];
                obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
                for (i = 0; i < 4; i++) {
                    if (D_80106F28_13CC58_HotBobOmb[i] == 0) {
                        D_80106FE8_13CD18_HotBobOmb[i] = 1;
                        D_80106EF0_13CC20_HotBobOmb[i] = 1;
                    }
                }
                D_80106EE8_13CC18_HotBobOmb = 9;
            } else {
                D_80106FFC_13CD2C_HotBobOmb = D_80107028_13CD58_HotBobOmb;
                D_80106F28_13CC58_HotBobOmb[D_80107028_13CD58_HotBobOmb] = 0xA;
                D_80106EE8_13CC18_HotBobOmb = 0xA;
                D_8010700C_13CD3C_HotBobOmb = 2;
            }
        }
        break;
    case 9:
        func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[0], 4, 0);
        func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[1], 4, 4);
        func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[2], 4, 4);
        func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[3], 4, 4);
        func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[4], 4, 4);
        func_800298A4_2A4A4(obj->model[5], 4, 0);
        /* fallthrough */
    case 0:
        p = &start[D_80106FF8_13CD28_HotBobOmb];
        obj->trans.x = (1.0f - t) * p->x + t * D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.x;
        obj->trans.z = (1.0f - t) * p->z + t * D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.z;
        obj->trans.y = HuMathSin(t * 180.0f) * 500.0f + D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].bomb.y;
        obj->rot.y = D_80106B20_13C850_HotBobOmb[D_80106FF8_13CD28_HotBobOmb].rot;
        break;
    case 10:
        D_80106FC8_13CCF8_HotBobOmb = 0;
        obj->func_ptr = func_80106750_13C480_HotBobOmb;
        break;
    }
    if (D_80106EE8_13CC18_HotBobOmb < 7) {
        if (D_80106C7C_13C9AC_HotBobOmb == 0) {
            k = D_80106F1C_13CC4C_HotBobOmb++;
            q = k / 3;
            if (k == q * 3) {
                if (q != 0 && q < 5) {
                    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[q], 4, 0);
                    func_800298A4_2A4A4(D_80106EA6_13CBD6_HotBobOmb[q - 1], 4, 4);
                }
            }
            lim = D_80106E90_13CBC0_HotBobOmb[D_80106E80_13CBB0_HotBobOmb] * 0.8;
            if (D_80106E88_13CBB8_HotBobOmb < lim) {
                D_80106E60_13CB90_HotBobOmb = (f32)(lim - D_80106E88_13CBB8_HotBobOmb) / (f32)lim + 0.1f;
            } else {
                D_80106E60_13CB90_HotBobOmb = 0.1f;
            }
            D_80106C7C_13C9AC_HotBobOmb++;
        }
        s = HuMathSin(2.0f * D_80106C70_13C9A0_HotBobOmb) * D_80106E60_13CB90_HotBobOmb /
            (f32)D_80106C7C_13C9AC_HotBobOmb;
        if (s > 1.0f) {
            s = 1.0f;
        }
        if (s < 0.0f) {
            s = -s;
        }
        if (D_80106EE8_13CC18_HotBobOmb != 2) {
            obj->scale.x = obj->scale.y = obj->scale.z = s + 1.0f;
        }
        D_80106C80_13C9B0_HotBobOmb++;
        if (obj->scale.x > D_80106C78_13C9A8_HotBobOmb) {
            if (D_80106C74_13C9A4_HotBobOmb == -1.0f) {
                D_80106C7C_13C9AC_HotBobOmb++;
                if (D_80106C84_13C9B4_HotBobOmb == -1) {
                    if (D_80106C80_13C9B0_HotBobOmb >= 11) {
                        D_80106C80_13C9B0_HotBobOmb = 0;
                        D_80106C7C_13C9AC_HotBobOmb = 0;
                        D_80106C84_13C9B4_HotBobOmb = 0;
                    }
                } else if (D_80106C7C_13C9AC_HotBobOmb >= 5 - D_80106E80_13CBB0_HotBobOmb) {
                    D_80106C80_13C9B0_HotBobOmb = 0;
                    D_80106C7C_13C9AC_HotBobOmb = 0;
                }
            }
            v = 1.0f;
        } else {
            v = -1.0f;
        }
        D_80106C74_13C9A4_HotBobOmb = v;
        D_80106C78_13C9A8_HotBobOmb = obj->scale.x;
        n = 16 - D_80106C7C_13C9AC_HotBobOmb * 2;
        D_80106C70_13C9A0_HotBobOmb += 0.6f / (f32)(n - D_80106E80_13CBB0_HotBobOmb);
        if (D_80106E68_13CB98_HotBobOmb != 0) {
            obj->scale.x = HuMathSin(D_80106E64_13CB94_HotBobOmb * 180.0f) + obj->scale.x;
            obj->scale.z = HuMathSin(D_80106E64_13CB94_HotBobOmb * 180.0f) + obj->scale.z;
            obj->scale.y = (1.0f - HuMathSin(D_80106E64_13CB94_HotBobOmb * 180.0f)) + D_80106E64_13CB94_HotBobOmb;
            if (D_80106E64_13CB94_HotBobOmb > 0.0f) {
                D_80106E64_13CB94_HotBobOmb -= 0.1f;
            } else {
                D_80106E68_13CB98_HotBobOmb = 0;
                D_80106E64_13CB94_HotBobOmb = 1.0f;
                D_80106EE8_13CC18_HotBobOmb = 4;
            }
        }
        func_80104F7C_13ACAC_HotBobOmb(obj, D_80106C48_13C978_HotBobOmb);
        if (++D_80106C48_13C978_HotBobOmb >= 4) {
            D_80106C48_13C978_HotBobOmb = 0;
        }
    }
    if (D_80106FD0_13CD00_HotBobOmb > 0) {
        D_80106FD0_13CD00_HotBobOmb--;
    }
    if (D_80106F94_13CCC4_HotBobOmb > 0) {
        D_80106F94_13CCC4_HotBobOmb--;
    }
    if (obj->trans.y > 0.0 && obj->trans.y < 400.0f) {
        t = 1.0f - obj->trans.y * 0.0025f;
    } else {
        t = 0.0f;
    }
    func_80029714_2A314(obj->model[5], obj->trans.x, 1.0f, obj->trans.z);
    func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[5], t * obj->scale.x, t * obj->scale.y, t * obj->scale.z);
    i = 0;
    if (D_80106EE8_13CC18_HotBobOmb == 7) {
        for (; i < 5; i++) {
            func_800297E8_2A3E8(obj->model[i], t * obj->scale.x, t * obj->scale.y, t * obj->scale.z);
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80106DD4_13CB04_HotBobOmb[13] = { 0x43AA0000, 0x43FA0000, 0x442F0000, 0xC3AA0000, 0x43FA0000, 0x442F0000, 0xC3AA0000, 0x43FA0000, 0xC42F0000, 0x43AA0000, 0x43FA0000, 0xC42F0000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801056C8_13B3F8_HotBobOmb);
#endif

/* The end: the loser's motion and the others' win motions, coins to gPlayers[].coins_mg_bonus,
   then fade out and return. */
void func_80106750_13C480_HotBobOmb(omObjData* obj) {
    omObjData* p;

    switch (D_80106FC8_13CCF8_HotBobOmb) {
    case 0:
        func_800794A8_7A0A8(0x28);
        D_80106F98_13CCC8_HotBobOmb = 0x1E;
        D_80106FC8_13CCF8_HotBobOmb++;
        break;
    case 1:
        if (--D_80106F98_13CCC8_HotBobOmb < 0) {
            func_800691FC_69DFC(3);
            func_80079614_7A214(4);
            if (D_80106E84_13CBB4_HotBobOmb == 1) {
                D_80106FC8_13CCF8_HotBobOmb += 2;
                D_80106F98_13CCC8_HotBobOmb = 0x3C;
            } else {
                D_80106FC8_13CCF8_HotBobOmb++;
            }
        }
        break;
    case 2:
        if (func_80069538_6A138() == 2) {
            p = D_800FFFD8_100BD8[D_80106FFC_13CD2C_HotBobOmb];
            func_80029B80_2A780(p->model[0], p->motion[8]);
            func_80029B80_2A780(D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 1) % 4]->model[0],
                                D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 1) % 4]->motion[10]);
            func_80029B80_2A780(D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 2) % 4]->model[0],
                                D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 2) % 4]->motion[10]);
            func_80029B80_2A780(D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 3) % 4]->model[0],
                                D_800FFFD8_100BD8[(D_80106FFC_13CD2C_HotBobOmb + 3) % 4]->motion[10]);
            func_800732B0_73EB0(D_80106F08_13CC38_HotBobOmb[D_80106FFC_13CD2C_HotBobOmb]);
            gPlayers[0].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[0];
            gPlayers[1].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[1];
            gPlayers[2].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[2];
            gPlayers[3].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[3];
            D_800FFFD8_100BD8[D_80106FFC_13CD2C_HotBobOmb]->rot.y = 0.0f;
            PlayMusic(0x51);
            D_80106F98_13CCC8_HotBobOmb = 0x78;
            D_80106FC8_13CCF8_HotBobOmb += 2;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 2) {
            gPlayers[0].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[0];
            gPlayers[1].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[1];
            gPlayers[2].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[2];
            gPlayers[3].coins_mg_bonus = D_80106F80_13CCB0_HotBobOmb[3];
            D_80106FC8_13CCF8_HotBobOmb++;
        }
        break;
    case 4:
        if (--D_80106F98_13CCC8_HotBobOmb == 0x54) {
            func_80079684_7A284(0x7F);
        }
        if (D_80106F98_13CCC8_HotBobOmb < 0) {
            InitFadeOut(0, 0x14);
            D_80106FC8_13CCF8_HotBobOmb++;
        }
        break;
    case 5:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        break;
    }
}
