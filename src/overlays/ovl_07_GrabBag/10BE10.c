#include "ovl_07.h"

/* .data (0x113910-0x1139E0, 8010A300-8010A3D0) */
s8 D_8010A300_113910_GrabBag = 0;
u8 D_8010A301_pad = 0;
u8 D_8010A302_pad = 0;
u8 D_8010A303_pad = 0;
u32 D_8010A304_113914_GrabBag = 0;
s32 D_8010A308_113918_GrabBag = 0;
s32 D_8010A30C_11391C_GrabBag = 0;
s32 D_8010A310_113920_GrabBag = 0;
s32 D_8010A314_113924_GrabBag = 0;
s8 D_8010A318_113928_GrabBag = 0;
u8 D_8010A319_pad = 0;
u8 D_8010A31A_pad = 0;
u8 D_8010A31B_pad = 0;
u8 D_8010A31C_pad = 0;
u8 D_8010A31D_pad = 0x17;
u8 D_8010A31E_pad = 0;
u8 D_8010A31F_pad = 0x11;
u8 D_8010A320_pad = 0;
u8 D_8010A321_pad = 0x17;
u8 D_8010A322_pad = 0;
u8 D_8010A323_pad = 0x12;
u8 D_8010A324_pad = 0;
u8 D_8010A325_pad = 0x17;
u8 D_8010A326_pad = 0;
u8 D_8010A327_pad = 0x11;
u8 D_8010A328_pad = 0;
u8 D_8010A329_pad = 0x17;
u8 D_8010A32A_pad = 0;
u8 D_8010A32B_pad = 0x12;
s32 D_8010A32C_11393C_GrabBag = 0;
Vec D_8010A330_113940_GrabBag[4] = {
    { -700.0f, 900.0f, 700.0f },
    { 700.0f, 900.0f, 700.0f },
    { 700.0f, 900.0f, -700.0f },
    { -700.0f, 900.0f, -700.0f },
};
f32 D_8010A360_113970_GrabBag[5] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_8010A374_113984_GrabBag[4][5] = {
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
s8 D_8010A3C4_1139D4_GrabBag = 0;
u8 D_8010A3C5_pad = 0;
u8 D_8010A3C6_pad = 0;
u8 D_8010A3C7_pad = 0;
s32 D_8010A3C8_pad[2] = { 0, 0 };

void func_80102800_10BE10_GrabBag(void) {
    s16 slot;

    func_8002D4D0_2E0D0(0x10);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x30, 0);
    func_80079128_79D28();
    D_8010A82F_113E3F_GrabBag = (rand8() & 0xFF) >> 6;
    D_8010A82E_113E3E_GrabBag = 0x1F;
    D_8010A82B_113E3B_GrabBag = 0;
    D_8010A834_113E44_GrabBag = 0;
    D_8010A820_113E30_GrabBag = 0;
    D_8010A82A_113E3A_GrabBag = 0;
    D_8010A680_113C90_GrabBag = D_800F86D8_F92D8[(s16)func_80018D64_19964(0x170011, 0x289, 8)].unk00;
    func_80029714_2A314(D_8010A680_113C90_GrabBag, 1000.0f, 1000.0f, 1000.0f);
    D_8010A684_113C94_GrabBag = slot = func_80018D64_19964(0x14, 0x289, 8);
    D_8010A682_113C92_GrabBag = D_800F86D8_F92D8[slot].unk00;
    func_80029714_2A314(D_8010A682_113C92_GrabBag, 1000.0f, 1000.0f, 1000.0f);
    D_8010A67E_113C8E_GrabBag = func_80018A64_19664(0x170012, 0x28D);
    func_8000C38C_CF8C();
    func_80102998_10BFA8_GrabBag();
    func_80104B20_10E130_GrabBag();
    func_80103004_10C614_GrabBag();
    func_80105E60_10F470_GrabBag();
    func_8002CA48_2D648(0, 0, 0);
    InitFadeIn(0, 0x10);
}

void func_80102998_10BFA8_GrabBag(void) {
    s32 cam;
    HuCamera* c;
    f32 x, y, z;
    f32 len;

    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 27.211f, 80.0f, 8000.0f);
    c = &D_800C9B80_CA780[cam];
    c->pos.x = -1.965f;
    c->pos.y = 1392.72f;
    c->pos.z = 1374.455f;
    c->at.x = -1.965f;
    c->at.y = 60.495f;
    c->at.z = 20.66f;
    x = c->at.x - c->pos.x;
    y = c->at.y - c->pos.y;
    z = c->at.z - c->pos.z;
    len = x * x + y * y;
    len = func_800B1830_B2430(len + z * z);
    x /= len;
    y /= len;
    z /= len;
    c->up.x = x;
    c->up.y = y;
    c->up.z = z;
}

void func_80102B60_10C170_GrabBag(omObjData* obj, s32 t) {
    s32 left = 0x708;

    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (t == 0x10) {
            D_8010A670_113C80_GrabBag = PlaySound(0x4A3);
        } else if (t == 0x5A) {
            func_800799A4_7A5A4(D_8010A670_113C80_GrabBag, 0x1E);
        } else if (t == 0x78) {
            func_800691FC_69DFC(0);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        }
        break;
    case 1:
        if (t == 0) {
            func_800691FC_69DFC(0xA, D_8010A82E_113E3E_GrabBag, 0xA0, 0x20);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            left = D_8010A82E_113E3E_GrabBag * 30 - t;
        }
        if (left <= 0) {
            func_8006D518_6E118();
            func_800794A8_7A0A8(0x28);
            func_8000C398_CF98();
        } else {
            func_8006D4D0_6E0D0(left / 30);
        }
        break;
    case 2:
        if (t == 0) {
            func_8000C690_D290();
            func_8006D518_6E118();
            if (D_8010A300_113910_GrabBag == 0) {
                func_800691FC_69DFC(3);
                D_8010A300_113910_GrabBag = 1;
            }
        } else {
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        }
        break;
    }
}

void func_80102D38_10C348_GrabBag(omObjData* obj) {
    switch (D_8010A318_113928_GrabBag) {
    case 0:
        if (D_801011FC_101DFC == 1) {
            func_80079868_7A468();
            func_800794A8_7A0A8(0x28);
            InitFadeOut(0, 0x14);
            D_8010A318_113928_GrabBag = 1;
        }
        break;
    case 1:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
            D_8010A318_113928_GrabBag = 2;
        }
        break;
    }
    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (D_8010A304_113914_GrabBag >= 0xF0) {
                func_8000C3B8_CFB8();
            } else if (D_8010A304_113914_GrabBag == 0x14) {
                PlayMusic(0x1E);
            }
            func_80102B60_10C170_GrabBag(obj, D_8010A304_113914_GrabBag);
            D_8010A304_113914_GrabBag += 2;
        }
        break;
    case 1:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            func_80102B60_10C170_GrabBag(obj, D_8010A30C_11391C_GrabBag);
            D_8010A30C_11391C_GrabBag += 1;
        }
        break;
    case 2:
        if (D_8010A82B_113E3B_GrabBag == 1) {
            if ((_CheckFlag(0xC) != 0 && D_8010A314_113924_GrabBag == 0x3C) ||
                (D_8010A84C_113E5C_GrabBag == 0 && D_8010A314_113924_GrabBag == 0x78) ||
                (D_8010A84C_113E5C_GrabBag == 1 && D_8010A314_113924_GrabBag == 0xA8)) {
                InitFadeOut(0, 0x14);
                func_8000C3A8_CFA8();
            }
            D_8010A314_113924_GrabBag += 1;
        }
        func_80102B60_10C170_GrabBag(obj, D_8010A308_113918_GrabBag);
        D_8010A308_113918_GrabBag += 2;
        break;
    case 3:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        D_8010A310_113920_GrabBag += 2;
        break;
    }
    Hu3DCamSetPositionOrientation(0, &D_800C9B80_CA780->pos, &D_800C9B80_CA780->at, &D_800C9B80_CA780->up);
    Hu3DCamUpdateMtx(0);
}

void func_80103004_10C614_GrabBag(void) {
    s32 i;

    D_800FA606_FB206 = 0;
    for (i = 0; i < 4; i++) {
        D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(3, 0x10, 0, -1, func_801030F0_10C700_GrabBag);
    }
    for (i = 0; i < 4; i++) {
        D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(4, 0x10, 0, -1, func_8010364C_10CC5C_GrabBag);
    }
}

void func_801030F0_10C700_GrabBag(omObjData* obj) {
    GBItem* w;

    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->func_ptr = func_801032E0_10C8F0_GrabBag;
    obj->unk_50 = func_80027154_27D54(sizeof(GBItem), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(GBItem));
    w = obj->unk_50;
    if (!(D_8010A32C_11393C_GrabBag & 1)) {
        w->unk_55 = (u8)D_8010A680_113C90_GrabBag;
        obj->model[0] = func_80027D3C_2893C(D_8010A680_113C90_GrabBag);
        HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
        obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
        func_800298A4_2A4A4(obj->model[0], 4, 4);
    } else {
        obj->model[0] = func_80027D3C_2893C(D_8010A67E_113C8E_GrabBag);
        obj->scale.x = obj->scale.y = obj->scale.z = 16.0f;
    }
    D_8010A32C_11393C_GrabBag += 1;
    func_8000C2A0_CEA0(obj, 1, 0x14, 0x28D, 8);
    func_80104AA8_10E0B8_GrabBag(w);
    w->unk_52 = D_8010A32C_11393C_GrabBag % 2;
    w->unk_AD = 0;
    w->unk_AC = 0;
    w->unk_AE = -1;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[1], 4.0f, 4.0f, 4.0f);
    func_80021250_21E50(w->unk_22, 0xFF, 0xFF, 0xBE);
}

/* NON_MATCHING: register/schedule (class 4): the slot table load takes a0 where retail keeps the work pointer there (masked 7) */
#ifdef NON_MATCHING
void func_801032E0_10C8F0_GrabBag(omObjData* obj) {
    omObjData* p;
    f32 dx, dz, v;
    s32 snd;
    s16 m;

    D_8010A674_113C84_GrabBag = obj->unk_50;
    m = obj->model[0];
    if (D_800FC834_FD434[m].unk18 & 4) {
        func_80104AA8_10E0B8_GrabBag(D_8010A674_113C84_GrabBag);
        D_8010A674_113C84_GrabBag->unk_AC = D_8010A674_113C84_GrabBag->unk_AD = D_8010A674_113C84_GrabBag->unk_AE = -1;
        return;
    }
    if (D_800FFFD8_100BD8[D_8010A674_113C84_GrabBag->unk_AD] != NULL) {
        D_8010A674_113C84_GrabBag->unk_78++;
        func_80021198_21D98(D_8010A674_113C84_GrabBag->unk_22, D_8010A674_113C84_GrabBag->unk_78 % 8);
        p = D_800FFFD8_100BD8[D_8010A674_113C84_GrabBag->unk_AD];
        dx = obj->trans.x - p->trans.x;
        dz = obj->trans.z - p->trans.z;
        if (D_800BF7C8_C03C8 < dx) {
            obj->trans.x = obj->trans.x - D_800BF7C8_C03C8;
        } else if (dx < -D_800BF7C8_C03C8) {
            obj->trans.x = obj->trans.x + D_800BF7C8_C03C8;
        }
        if (D_800BF7C8_C03C8 < dz) {
            obj->trans.z = obj->trans.z - D_800BF7C8_C03C8;
        } else if (dz < -D_800BF7C8_C03C8) {
            obj->trans.z = obj->trans.z + D_800BF7C8_C03C8;
        }
        v = D_8010A674_113C84_GrabBag->unk_38;
        if (v > 0.9f) {
            v = 0.9f;
        } else if (v < -0.9f) {
            v = -0.9f;
        }
        if (D_8010A674_113C84_GrabBag->unk_78 < 0xF) {
            obj->trans.y = v * v * 35.0f + obj->trans.y;
            D_8010A674_113C84_GrabBag->unk_38 = D_8010A674_113C84_GrabBag->unk_38 + 0.3f;
        } else {
            obj->trans.y = obj->trans.y - v * v * 35.0f;
            D_8010A674_113C84_GrabBag->unk_38 = D_8010A674_113C84_GrabBag->unk_38 - 0.1f;
            if (obj->trans.y < 20.0f) {
                obj->trans.y = 20.0f;
            }
        }
        if (D_8010A674_113C84_GrabBag->unk_78 >= 0x15) {
            snd = 0x149;
            if (D_8010A674_113C84_GrabBag->unk_AE == 0) {
                PlaySound(snd);
            } else if (D_8010A674_113C84_GrabBag->unk_AE == 1) {
                snd = 0x14A;
                PlaySound(snd);
            }
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            D_8010A674_113C84_GrabBag->unk_78 = 0;
            D_8010A674_113C84_GrabBag->unk_AC = D_8010A674_113C84_GrabBag->unk_AD = -1;
            D_8010A674_113C84_GrabBag->unk_AE = -1;
        }
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 24.0f, obj->trans.z);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10BE10", func_801032E0_10C8F0_GrabBag);
#endif

/* p is the search counter; the player's object is indexed directly (S3-Q02). */
void func_8010364C_10CC5C_GrabBag(omObjData* obj) {
    GBItem* w;
    GBPlayer* pw;
    Vec* v;
    s32 p;
    s32 j;

    obj->unk_50 = func_80027154_27D54(sizeof(GBItem), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(GBItem));
    w = obj->unk_50;
    for (p = 0; p < 0x100; p++) {
        if (D_800F9CE0_FA8E0[p] == obj) {
            break;
        }
    }
    p -= 4;
    pw = D_800FFFD8_100BD8[p]->unk_50;
    D_8010A778_113D88_GrabBag[p] = func_801049F0_10E000_GrabBag(
        D_8010A330_113940_GrabBag[pw->unk_15C].x, D_8010A330_113940_GrabBag[pw->unk_15C].y,
        D_8010A330_113940_GrabBag[pw->unk_15C].z, D_800FFFD8_100BD8[p]->trans.x, D_800FFFD8_100BD8[p]->trans.y, D_800FFFD8_100BD8[p]->trans.z);
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    v = D_8010A688_113C98_GrabBag[p];
    obj->trans.x = v->x = D_8010A330_113940_GrabBag[pw->unk_15C].x;
    obj->trans.y = v->y = D_8010A330_113940_GrabBag[pw->unk_15C].y;
    obj->trans.z = v->z = D_8010A330_113940_GrabBag[pw->unk_15C].z;
    func_80104AA8_10E0B8_GrabBag(w);
    for (j = 0; j < 5; j++) {
        obj->model[j] = func_80027D3C_2893C(D_8010A680_113C90_GrabBag);
        HmfModelObjAttrSet(obj->model[j], 0x70000000, 0x70000000);
        func_800298A4_2A4A4(obj->model[j], 4, 0);
        D_8010A688_113C98_GrabBag[p][j].x = D_8010A778_113D88_GrabBag[p].x * 150.0f * j + obj->trans.x;
        D_8010A688_113C98_GrabBag[p][j].y = D_8010A778_113D88_GrabBag[p].y * 150.0f * j + obj->trans.y;
        D_8010A688_113C98_GrabBag[p][j].z = D_8010A778_113D88_GrabBag[p].z * 150.0f * j + obj->trans.z;
        func_80029714_2A314(obj->model[j], D_8010A688_113C98_GrabBag[p][j].x, D_8010A688_113C98_GrabBag[p][j].y,
                            D_8010A688_113C98_GrabBag[p][j].z);
        func_800297E8_2A3E8(obj->model[j], obj->scale.x, obj->scale.y, obj->scale.z);
        obj->model[j + 5] = func_80027D3C_2893C(D_8010A682_113C92_GrabBag);
        HmfModelObjAttrSet(obj->model[j + 5], 0x70000000, 0x70000000);
        w->unk_26[j] = (u8)D_8010A684_113C94_GrabBag;
        func_80029714_2A314(obj->model[j + 5], D_8010A688_113C98_GrabBag[p][j].x, D_8010A688_113C98_GrabBag[p][j].y + 20.0f,
                            D_8010A688_113C98_GrabBag[p][j].z);
        func_800297E8_2A3E8(obj->model[j + 5], 4.0f, 4.0f, 4.0f);
        func_80021250_21E50(w->unk_26[j], 0xFF, 0xFF, 0xBE);
        func_800298A4_2A4A4(obj->model[j + 5], 4, 4);
    }
    obj->model[10] = func_80027D3C_2893C(D_8010A67E_113C8E_GrabBag);
    HmfModelObjAttrSet(obj->model[10], 0x70000000, 0x70000000);
    func_800298A4_2A4A4(obj->model[10], 4, 0);
    func_80029714_2A314(obj->model[10], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[10], 16.0f, 16.0f, 16.0f);
    obj->func_ptr = func_80103B00_10D110_GrabBag;
}


/* NON_MATCHING: control flow then registers (class 3): a delay-slot steal gives retail one more jump before the first loop, and the tbl[p] address is computed after the chain position in the bounds tests; retail's local table is D_8010A530 (masked 93, the frame and calls agree) */
#ifdef NON_MATCHING
void func_80103B00_10D110_GrabBag(omObjData* obj) {
    Vec tbl[4] = { { -550.0f, 120.0f, -450.0f }, { 350.0f, 120.0f, -450.0f }, { -410.0f, 120.0f, 480.0f }, { 240.0f, 120.0f, 480.0f } };
    GBItem* w;
    s32 i, j, p, k, seg;
    s32 best;
    s32 snd;
    MgWork* mw;
    f32 a, b, c;

    D_8010A678_113C88_GrabBag += 1;
    w = obj->unk_50;
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_8010A678_113C88_GrabBag >= 0x14) {
            for (p = 0; p < 0x100; p++) {
                if (D_800F9CE0_FA8E0[p] == obj) {
                    break;
                }
            }
            p -= 4;
            for (j = 0; j < 5; j++) {
                if (D_8010A688_113C98_GrabBag[p][j].y < 100.0f) {
                    func_800298A4_2A4A4(obj->model[j], 4, 4);
                } else {
                    func_800298A4_2A4A4(obj->model[j], 4, 0);
                    D_8010A778_113D88_GrabBag[p] = func_801049F0_10E000_GrabBag(
                        D_8010A688_113C98_GrabBag[p][j].x, D_8010A688_113C98_GrabBag[p][j].y, D_8010A688_113C98_GrabBag[p][j].z,
                        D_800FFFD8_100BD8[p]->trans.x, D_800FFFD8_100BD8[p]->trans.y, D_800FFFD8_100BD8[p]->trans.z);
                    D_8010A688_113C98_GrabBag[p][j].x = D_8010A778_113D88_GrabBag[p].x * 24.0f + D_8010A688_113C98_GrabBag[p][j].x;
                    D_8010A688_113C98_GrabBag[p][j].y = D_8010A778_113D88_GrabBag[p].y * 24.0f + D_8010A688_113C98_GrabBag[p][j].y;
                    D_8010A688_113C98_GrabBag[p][j].z = D_8010A778_113D88_GrabBag[p].z * 24.0f + D_8010A688_113C98_GrabBag[p][j].z;
                    obj->trans.x = D_8010A688_113C98_GrabBag[p][0].x;
                    obj->trans.y = D_8010A688_113C98_GrabBag[p][0].y;
                    obj->trans.z = D_8010A688_113C98_GrabBag[p][0].z;
                    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
                    func_80029714_2A314(obj->model[j], D_8010A688_113C98_GrabBag[p][j].x, D_8010A688_113C98_GrabBag[p][j].y, D_8010A688_113C98_GrabBag[p][j].z);
                    func_800297E8_2A3E8(obj->model[j], obj->scale.x, obj->scale.y, obj->scale.z);
                }
            }
        }
        break;
    case 2:
        if (D_8010A820_113E30_GrabBag == 0 || D_8010A834_113E44_GrabBag != 0) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 5; j++) {
                    D_8010A688_113C98_GrabBag[i][j].x = D_800FFFD8_100BD8[i]->trans.x;
                    D_8010A688_113C98_GrabBag[i][j].y = 100.0f;
                    D_8010A688_113C98_GrabBag[i][j].z = D_800FFFD8_100BD8[i]->trans.z;
                }
            }
            break;
        }
        best = 0;
        for (i = 0; i < 4; i++) {
            if (best < ((GBPlayer*)D_800FFFD8_100BD8[i]->unk_50)->unk_168) {
                best = ((GBPlayer*)D_800FFFD8_100BD8[i]->unk_50)->unk_168;
            }
        }
        for (p = 0; p < 0x100; p++) {
            if (D_800F9CE0_FA8E0[p] == obj) {
                break;
            }
        }
        p -= 4;
        k = D_8010A82A_113E3A_GrabBag % 5;
        seg = k;
        mw = D_800FFFD8_100BD8[p]->unk_50;
        if (D_8010A82F_113E3F_GrabBag == mw->unk_59) {
            if (D_8010A82A_113E3A_GrabBag == 0) {
                seg = 0xA;
                obj->scale.x = obj->scale.y = obj->scale.z = 16.0f;
            }
        }
        for (i = 0; i < 4; i++) {
            if (D_8010A82A_113E3A_GrabBag >= ((GBPlayer*)D_800FFFD8_100BD8[i]->unk_50)->unk_168) {
                D_8010A688_113C98_GrabBag[i][k].x = tbl[i].x;
                D_8010A688_113C98_GrabBag[i][k].y = tbl[i].y;
                D_8010A688_113C98_GrabBag[i][k].z = tbl[i].z;
            }
            if (D_8010A688_113C98_GrabBag[i][k].y == 100.0f) {
                func_800298A4_2A4A4(obj->model[seg], 4, 4);
            }
        }
        if (((p == 0 || p == 2) && D_8010A688_113C98_GrabBag[p][k].x <= tbl[p].x) ||
            ((p == 1 || p == 3) && tbl[p].x <= D_8010A688_113C98_GrabBag[p][k].x)) {
            for (i = 0; i < 0xB; i++) {
                func_800298A4_2A4A4(obj->model[i], 4, 4);
            }
            if (D_8010A688_113C98_GrabBag[0][k].x <= tbl[0].x && tbl[1].x <= D_8010A688_113C98_GrabBag[1][k].x &&
                D_8010A688_113C98_GrabBag[2][k].x <= tbl[2].x && tbl[3].x <= D_8010A688_113C98_GrabBag[3][k].x) {
                for (i = 0; i < 4; i++) {
                    if (D_8010A82A_113E3A_GrabBag < ((GBPlayer*)D_800FFFD8_100BD8[i]->unk_50)->unk_168) {
                        D_8010A688_113C98_GrabBag[i][k].x = D_800FFFD8_100BD8[i]->trans.x;
                        D_8010A688_113C98_GrabBag[i][k].y = 100.0f;
                        D_8010A688_113C98_GrabBag[i][k].z = D_800FFFD8_100BD8[i]->trans.z;
                    }
                    D_8010A360_113970_GrabBag[k] = 0.0f;
                    D_8010A374_113984_GrabBag[i][k] = 0.0f;
                }
                if (D_8010A82A_113E3A_GrabBag < best) {
                    if (D_8010A3C4_1139D4_GrabBag == 0 && D_8010A82A_113E3A_GrabBag == best - 2) {
                        func_800794A8_7A0A8(0x1E);
                        D_8010A3C4_1139D4_GrabBag = 1;
                    }
                    if (D_8010A82A_113E3A_GrabBag > 0) {
                        func_80079848_7A448(D_8010A67C_113C8C_GrabBag);
                    }
                    snd = 0x149;
                    if (D_8010A82A_113E3A_GrabBag == 0) {
                        snd = 0x14A;
                    }
                    D_8010A67C_113C8C_GrabBag = PlaySound(snd);
                    D_8010A82A_113E3A_GrabBag += 1;
                } else {
                    D_8010A834_113E44_GrabBag = 1;
                    func_800298A4_2A4A4(D_8010A680_113C90_GrabBag, 4, 4);
                }
            }
        } else {
            for (i = 0; i < 0xA; i++) {
                if (i == seg || i == seg + 5) {
                    func_800298A4_2A4A4(obj->model[i], 4, 0);
                } else {
                    func_800298A4_2A4A4(obj->model[i], 4, 4);
                }
            }
            if (seg == 0xA) {
                func_800298A4_2A4A4(obj->model[10], 4, 0);
            } else {
                func_800298A4_2A4A4(obj->model[10], 4, 4);
            }
            D_8010A778_113D88_GrabBag[p] = func_801049F0_10E000_GrabBag(
                D_8010A688_113C98_GrabBag[p][k].x, D_8010A688_113C98_GrabBag[p][k].y, D_8010A688_113C98_GrabBag[p][k].z,
                tbl[p].x, tbl[p].y, tbl[p].z);
            D_8010A688_113C98_GrabBag[p][k].x = D_8010A778_113D88_GrabBag[p].x * 25.0f + D_8010A688_113C98_GrabBag[p][k].x;
            D_8010A688_113C98_GrabBag[p][k].y = D_8010A778_113D88_GrabBag[p].y * 25.0f + HuMathSin(D_8010A360_113970_GrabBag[k]) * 20.0f + D_8010A688_113C98_GrabBag[p][k].y;
            D_8010A688_113C98_GrabBag[p][k].z = D_8010A778_113D88_GrabBag[p].z * 25.0f + D_8010A688_113C98_GrabBag[p][k].z;
            obj->trans.x = D_8010A688_113C98_GrabBag[p][0].x;
            obj->trans.y = D_8010A688_113C98_GrabBag[p][0].y;
            obj->trans.z = D_8010A688_113C98_GrabBag[p][0].z;
            if (D_8010A360_113970_GrabBag[k] < 90.0f) {
                D_8010A374_113984_GrabBag[p][k] += 0.1f;
            } else {
                D_8010A374_113984_GrabBag[p][k] -= 0.2f;
            }
            obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
            w->unk_78 = w->unk_78 + 1;
            for (j = 0; j < 5; j++) {
                func_80021198_21D98(w->unk_26[j], w->unk_78 % 8);
            }
            D_8010A360_113970_GrabBag[k] += 5.0f;
            for (i = 0; i < 4; i++) {
                if (((MgWork*)D_800FFFD8_100BD8[i]->unk_50)->unk_59 == D_8010A82F_113E3F_GrabBag && ((D_8010A82A_113E3A_GrabBag == 0) & (seg == 0xA))) {
                    obj->scale.x = obj->scale.y = obj->scale.z = 20.0f;
                }
            }
            a = obj->scale.x + D_8010A374_113984_GrabBag[p][k];
            b = obj->scale.y + D_8010A374_113984_GrabBag[p][k];
            c = obj->scale.z + D_8010A374_113984_GrabBag[p][k];
            if (a < 0.0f) {
                a = 0.0f;
            }
            if (b < 0.0f) {
                b = 0.0f;
            }
            if (c < 0.0f) {
                c = 0.0f;
            }
            func_800297E8_2A3E8(obj->model[seg], a, b, c);
            func_80029714_2A314(obj->model[seg], D_8010A688_113C98_GrabBag[p][k].x, D_8010A688_113C98_GrabBag[p][k].y, D_8010A688_113C98_GrabBag[p][k].z);
            if (seg != 0xA) {
                a = D_8010A374_113984_GrabBag[p][k] + 6.0f;
                b = a;
                c = b;
                if (a < 0.0f) {
                    a = 0.0f;
                }
                if (b < 0.0f) {
                    b = 0.0f;
                }
                if (c < 0.0f) {
                    c = 0.0f;
                }
                func_800297E8_2A3E8(obj->model[seg + 5], a, b, c);
                func_80029714_2A314(obj->model[seg + 5], D_8010A688_113C98_GrabBag[p][k].x, D_8010A688_113C98_GrabBag[p][k].y + 20.0f, D_8010A688_113C98_GrabBag[p][k].z);
            }
        }
        break;
    }
}
#else
__asm__(".section .rodata");
const u32 D_8010A530_113B40_GrabBag[12] = { 0xC4098000, 0x42F00000, 0xC3E10000, 0x43AF0000, 0x42F00000, 0xC3E10000, 0xC3CD0000, 0x42F00000, 0x43F00000, 0x43700000, 0x42F00000, 0x43F00000 };
__asm__(".text");
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10BE10", func_80103B00_10D110_GrabBag);
#endif

Vec func_801049F0_10E000_GrabBag(f32 x, f32 y, f32 z, f32 x2, f32 y2, f32 z2) {
    Vec v;
    f32 len;

    v.x = x2 - x;
    v.y = y2 - y;
    v.z = z2 - z;
    len = func_800B1830_B2430(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x /= len;
    v.y /= len;
    v.z /= len;
    return v;
}

void func_80104AA8_10E0B8_GrabBag(GBItem* w) {
    w->unk_7C = 0;
    w->unk_78 = 0;
    w->unk_3C = 0;
    w->unk_54 = 0;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 500.0f;
    w->unk_40 = D_800BF7C8_C03C8;
    w->unk_38 = 0.0f;
    w->unk_4C = 0.5f;
    w->unk_50 = 0;
    w->unk_74 = 0.5f;
}

