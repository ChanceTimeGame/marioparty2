#include "ovl_2C.h"

/* .data (0x2290B0-0x2292C0): drift scale, tile states, ball state, timer, the platform display
   list, CPU state. D_80107BB0 (D_80107B88[1]) and D_80107C54/C58 (D_80107C50[0].y/.z) are asm views:
   undefined_syms aliases. */
f32 D_80107B80_2290B0_TipsyTourney = 20.0f;
s16 D_80107B84_2290B4_TipsyTourney = 0;
s16 D_80107B88_2290B8_TipsyTourney[4][5][5] = {
    { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } },
};
Vec3f D_80107C50_229180_TipsyTourney[4] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
};
s8 D_80107C80_2291B0_TipsyTourney = -1;
s32 D_80107C84_2291B4_TipsyTourney = 0;
s32 D_80107C88_2291B8_TipsyTourney = 0x744;
s32 D_80107C8C_2291BC_TipsyTourney = 0;
s32 D_80107C90_2291C0_TipsyTourney = 0;
Gfx D_80107C98_2291C8_TipsyTourney[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0, TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};
Vec3f D_80107CD8_229208_TipsyTourney[4] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
};
f32 D_80107D08_229238_TipsyTourney[4] = {
    0.0f, 0.0f, 0.0f, 0.0f,
};
Vec3f D_80107D18_229248_TipsyTourney[4] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
};
f32 D_80107D48_229278_TipsyTourney[4] = {
    0.0f, 0.0f, 0.0f, 0.0f,
};
u16 D_80107D58_229288_TipsyTourney[4] = {
    0, 0, 0, 0,
};
f32 D_80107D60_229290_TipsyTourney[4] = {
    1.0f, 1.0f, -1.0f, -1.0f,
};
s16 D_80107D70_2292A0_TipsyTourney[4] = {
    0, 0, 0, 0,
};
TipsyDash D_80107D78_2292A8_TipsyTourney[4] = {
    { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
};

void func_80102800_223D30_TipsyTourney(void) {
    omObjData* obj;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_8000C38C_CF8C();
    func_80018ED0_19AD0(5);
    func_80018F58_19B58(5);
    ScissorSet(0, 8.0f, 8.0f, 160.0f, 120.0f);
    ViewportSet(0, 320.0f, 240.0f, 511.0f, 320.0f, 240.0f, 511.0f);
    Hu3DCamSetPerspective(0, 20.0f, 80.0f, 8000.0f);
    ScissorSet(1, 160.0f, 8.0f, 312.0f, 120.0f);
    ViewportSet(1, 320.0f, 240.0f, 511.0f, 960.0f, 240.0f, 511.0f);
    Hu3DCamSetPerspective(1, 20.0f, 80.0f, 8000.0f);
    ScissorSet(2, 8.0f, 120.0f, 160.0f, 232.0f);
    ViewportSet(2, 320.0f, 240.0f, 511.0f, 320.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(2, 20.0f, 80.0f, 8000.0f);
    ScissorSet(3, 160.0f, 120.0f, 312.0f, 232.0f);
    ViewportSet(3, 320.0f, 240.0f, 511.0f, 960.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(3, 20.0f, 80.0f, 8000.0f);
    ScissorSet(4, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(4, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(4, 25.0f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    func_8000C56C_D16C(1);
    D_800BF7D4_C03D4 = 1.0f;
    func_8000C578_D178(1);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xC8, 1, 0, -1, func_801032FC_22482C_TipsyTourney);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xC8, 2, 0, -1, func_801034E8_224A18_TipsyTourney);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xC8, 2, 0, -1, func_801036A8_224BD8_TipsyTourney);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xC8, 2, 0, -1, func_80103864_224D94_TipsyTourney);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xC8, 2, 0, -1, func_80103A24_224F54_TipsyTourney);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(0x190, 3, 0, -1, func_80104458_225988_TipsyTourney);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(0x190, 3, 0, -1, func_80104520_225A50_TipsyTourney);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(0x190, 3, 0, -1, func_801045EC_225B1C_TipsyTourney);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(0x190, 3, 0, -1, func_801046BC_225BEC_TipsyTourney);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_80103EAC_2253DC_TipsyTourney);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_80103FC4_2254F4_TipsyTourney);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_801040E0_225610_TipsyTourney);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_801041FC_22572C_TipsyTourney);
    D_800BF79C_C039C = 10.0f;
    omSetStatBit(omAddObj(0x1F4, 0, 0, -1, func_8010478C_225CBC_TipsyTourney), 0xA0);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    obj->work[0] = 5;
    omSetStatBit(obj, 0xA0);
    func_8002CD6C_2D96C(1);
}

void func_80102ED0_224400_TipsyTourney(void) {
    func_800691FC_69DFC(0xA, 0x1E, 0xA0, 0x18);
}

void func_80102EF8_224428_TipsyTourney(void) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

void func_80102F24_224454_TipsyTourney(omObjData* obj, u8 state, u32 time) {
    switch (state) {
    case 0:
        if (time == 0) {
            func_800691FC_69DFC(0);
            PlayMusic(0x2B);
        }
        break;
    case 1:
        func_8006D4D0_6E0D0(time / 60);
        break;
    }
}

void func_80102F94_2244C4_TipsyTourney(omObjData* obj) {
    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (func_8008F618_90218() != 0) {
            return;
        }
        func_80102F24_224454_TipsyTourney(obj, (u8)D_800F8FD0_F9BD0, D_80107C84_2291B4_TipsyTourney);
        if (D_80107C84_2291B4_TipsyTourney == 0x50) {
            func_80102ED0_224400_TipsyTourney();
            func_8000C3B8_CFB8();
        }
        D_80107C84_2291B4_TipsyTourney += 2;
        break;
    case 1:
        if (D_80107C88_2291B8_TipsyTourney <= 0) {
            func_8000C398_CF98();
        }
        func_80102F24_224454_TipsyTourney(obj, (u8)D_800F8FD0_F9BD0, D_80107C88_2291B8_TipsyTourney);
        D_80107C88_2291B8_TipsyTourney -= 2;
        break;
    case 2:
        if (D_80107C8C_2291BC_TipsyTourney == 0) {
            func_800691FC_69DFC(3);
            func_8002CD6C_2D96C(5);
            func_800794A8_7A0A8(0x28);
            func_80105BA8_2270D8_TipsyTourney();
            func_8006D518_6E118();
        }
        func_80102F24_224454_TipsyTourney(obj, (u8)D_800F8FD0_F9BD0, D_80107C8C_2291BC_TipsyTourney);
        if ((func_80069538_6A138() == 0 || func_80069538_6A138() & 2) && _CheckFlag(0xC) == 0 &&
            D_80107B84_2290B4_TipsyTourney == 0) {
            if (D_80107C88_2291B8_TipsyTourney > 0) {
                PlayMusic(0x51);
                func_800691FC_69DFC(6, gPlayers[D_80107C80_2291B0_TipsyTourney].character);
            } else {
                func_800691FC_69DFC(0x13);
                PlayMusic(0x57);
            }
            D_80107B84_2290B4_TipsyTourney++;
        }
        func_80105C40_227170_TipsyTourney();
        D_80107C8C_2291BC_TipsyTourney += 2;
        if (D_80107B84_2290B4_TipsyTourney != 0) {
            if (D_80107B84_2290B4_TipsyTourney == 0x78) {
                func_8000C3A8_CFA8();
            }
            D_80107B84_2290B4_TipsyTourney++;
        }
        if (_CheckFlag(0xC) != 0 && (func_80069538_6A138() == 0 || func_80069538_6A138() & 2)) {
            if (D_80107B84_2290B4_TipsyTourney == 0x3C) {
                func_8000C3A8_CFA8();
            }
            D_80107B84_2290B4_TipsyTourney++;
        }
        break;
    case 3:
        if (D_80107C90_2291C0_TipsyTourney == 0) {
            func_800794A8_7A0A8(0x28);
        }
        InitFadeOut(0, 0x14);
        obj->func_ptr = func_80102EF8_224428_TipsyTourney;
        func_80102F24_224454_TipsyTourney(obj, (u8)D_800F8FD0_F9BD0, D_80107C8C_2291BC_TipsyTourney);
        D_80107C90_2291C0_TipsyTourney += 2;
        break;
    }
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
        obj->func_ptr = func_80102EF8_224428_TipsyTourney;
    }
}

void func_801032FC_22482C_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    obj->model[0] = func_80018A30_19630(0x3C0003, 0x499);
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    obj->func_ptr = func_80102F94_2244C4_TipsyTourney;
    work->unk_03 = 1;
    func_8000BEF8_CAF8(obj, 2, -400.0f);
    func_8000BE8C_CA8C(obj, 0.6f);
    func_8000BEA4_CAA4(obj, 25.0f);
    work->unk_04 = 0;
    InitFadeIn(0, 0x10);
    D_801013B0_101FB0[0].x = 1000.0f;
    D_801013B0_101FB0[0].y = 500.0f;
    D_801013B0_101FB0[0].z = 600.0f;
    D_80102770_103370[0].x = 320.0f;
    D_80102770_103370[0].y = 0.0f;
    D_80102770_103370[0].z = 0.0f;
    D_800F94A8_FA0A8[0] = 750.0f;
    D_801013B0_101FB0[1].x = -1000.0f;
    D_801013B0_101FB0[1].y = 500.0f;
    D_801013B0_101FB0[1].z = 600.0f;
    D_80102770_103370[1].x = 320.0f;
    D_80102770_103370[1].y = 0.0f;
    D_80102770_103370[1].z = 0.0f;
    D_800F94A8_FA0A8[1] = 750.0f;
    D_801013B0_101FB0[2].x = 3000.0f;
    D_801013B0_101FB0[2].y = 500.0f;
    D_801013B0_101FB0[2].z = 600.0f;
    D_80102770_103370[2].x = 320.0f;
    D_80102770_103370[2].y = 0.0f;
    D_80102770_103370[2].z = 0.0f;
    D_800F94A8_FA0A8[2] = 750.0f;
    D_801013B0_101FB0[3].x = -3000.0f;
    D_801013B0_101FB0[3].y = 500.0f;
    D_801013B0_101FB0[3].z = 600.0f;
    D_80102770_103370[3].x = 320.0f;
    D_80102770_103370[3].y = 0.0f;
    D_80102770_103370[3].z = 0.0f;
    D_800F94A8_FA0A8[3] = 750.0f;
    D_801013B0_101FB0[4].x = 0.0f;
    D_801013B0_101FB0[4].y = 0.0f;
    D_801013B0_101FB0[4].z = 0.0f;
    D_80102770_103370[4].x = 270.0f;
    D_80102770_103370[4].y = 0.0f;
    D_80102770_103370[4].z = 0.0f;
    D_800F94A8_FA0A8[4] = 180.0f;
    func_80029EDC_2AADC(obj->model[0], 0x10);
}

void func_801034E8_224A18_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_80018A30_19630(0x3C0002, 0xAB9);
    obj->model[1] = func_80018A30_19630(0x3C0001, 0xA89);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = 1000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    obj->func_ptr = func_8010643C_22796C_TipsyTourney;
    work->unk_03 = 1;
    func_8000BF24_CB24(obj, 5.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.3f);
    func_8000C37C_CF7C(obj, 1.0f, 1.0f, 1.0f);
    func_8000BEA4_CAA4(obj, 25.0f);
    work->unk_04 = 1;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    HmfModelObjAttrSet(obj->model[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    func_80105D28_227258_TipsyTourney(obj->model[1], work->unk_04 - 1);
    func_8000BFF0_CBF0(obj);
}

void func_801036A8_224BD8_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_80018A30_19630(0x3C0002, 0xAB9);
    obj->model[1] = func_80018A30_19630(0x3C0001, 0xA89);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = -1000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    obj->func_ptr = func_8010643C_22796C_TipsyTourney;
    work->unk_03 = 1;
    func_8000BF24_CB24(obj, 5.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.3f);
    func_8000C37C_CF7C(obj, 1.0f, 1.0f, 1.0f);
    func_8000BEA4_CAA4(obj, 25.0f);
    work->unk_04 = 2;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[1], 2);
    HmfModelObjAttrSet(obj->model[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    func_80105D28_227258_TipsyTourney(obj->model[1], work->unk_04 - 1);
    func_8000BFF0_CBF0(obj);
}

void func_80103864_224D94_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_80018A30_19630(0x3C0002, 0xAB9);
    obj->model[1] = func_80018A30_19630(0x3C0001, 0xA89);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = 3000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    obj->func_ptr = func_8010643C_22796C_TipsyTourney;
    work->unk_03 = 1;
    func_8000BF24_CB24(obj, 5.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.3f);
    func_8000C37C_CF7C(obj, 1.0f, 1.0f, 1.0f);
    func_8000BEA4_CAA4(obj, 25.0f);
    work->unk_04 = 3;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], 4);
    func_80029EDC_2AADC(obj->model[1], 4);
    HmfModelObjAttrSet(obj->model[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    func_80105D28_227258_TipsyTourney(obj->model[1], work->unk_04 - 1);
    func_8000BFF0_CBF0(obj);
}

void func_80103A24_224F54_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_80018A30_19630(0x3C0002, 0xAB9);
    obj->model[1] = func_80018A30_19630(0x3C0001, 0xA89);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = -3000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(work, 0, 0xB4);
    obj->func_ptr = func_8010643C_22796C_TipsyTourney;
    work->unk_03 = 1;
    func_8000BF24_CB24(obj, 5.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.3f);
    func_8000C37C_CF7C(obj, 1.0f, 1.0f, 1.0f);
    func_8000BEA4_CAA4(obj, 25.0f);
    work->unk_04 = 4;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], 8);
    func_80029EDC_2AADC(obj->model[1], 8);
    HmfModelObjAttrSet(obj->model[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    func_80105D28_227258_TipsyTourney(obj->model[1], work->unk_04 - 1);
    func_8000BFF0_CBF0(obj);
}

void func_80103BE4_225114_TipsyTourney(omObjData* obj, s32 dir, s32 file0, s32 file1, u16 idx, f32 x, f32 y, f32 z) {
    TipsyWork* work;
    s32 motion;
    s32 motion2;
    s32 attr0 = 0x20A89;
    s32 attr1 = 0x20A99;

    func_8000C6FC_D2FC(obj, dir, file0, idx, attr0, attr1);
    work = obj->unk_50;
    obj->model[3] = LoadFormFile(7, 0xA8D);
    obj->model[4] = LoadFormFile(8, 0xA8D);
    obj->model[5] = LoadFormFile(0xA, 0xA8D);
    func_8000BDC4_C9C4(obj, 9, dir | file1, 0x20A89, 850.0f);
    func_8000CC74_D874(obj, obj->model[9], 1);
    motion = ((rand8() & 0xFF) < 0x80U) ? 0x4F : 0x4E;
    motion2 = ((rand8() & 0xFF) >= 0x80U) ? 0x55 : 0x56;
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 3, dir | 0x2C, 1, 0);
    func_80019F0C_1AB0C(obj, 4, dir | 0x2D, 1, 0);
    func_80019F0C_1AB0C(obj, 0x20, dir | 0x31, 0, 0);
    func_8001A12C_1AD2C(obj, 0xE, dir | motion2, 1, 0x78, 2);
    func_8001A12C_1AD2C(obj, 0xD, dir | motion, 1, 0x78, 1);
    D_80107E28_229358_TipsyTourney[idx] = dir | motion;
    D_80107E38_229368_TipsyTourney[idx] = dir | motion2;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->func_ptr = func_80104AEC_22601C_TipsyTourney;
    work->unk_EC = func_80107A0C_228F3C_TipsyTourney;
    func_8000C024_CC24(obj, 0, 2);
}

void func_80103EAC_2253DC_TipsyTourney(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[0].character].unk_08;
    s32 dir = D_800CD438_CE038[gPlayers[0].character].unk_04;
    s32 file1 = D_800CD438_CE038[gPlayers[0].character].unk_10;

    func_80103BE4_225114_TipsyTourney(obj, dir, file, file1, 0, 1150.0f, 0.0f, 150.0f);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 1);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    func_80029EDC_2AADC(obj->model[4], 1);
    func_80029EDC_2AADC(obj->model[5], 1);
}

void func_80103FC4_2254F4_TipsyTourney(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[1].character].unk_08;
    s32 dir = D_800CD438_CE038[gPlayers[1].character].unk_04;
    s32 file1 = D_800CD438_CE038[gPlayers[1].character].unk_10;

    func_80103BE4_225114_TipsyTourney(obj, dir, file, file1, 1, -850.0f, 0.0f, 150.0f);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 2);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 1);
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[1], 2);
    func_80029EDC_2AADC(obj->model[3], 2);
    func_80029EDC_2AADC(obj->model[4], 2);
    func_80029EDC_2AADC(obj->model[5], 2);
}

void func_801040E0_225610_TipsyTourney(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[2].character].unk_08;
    s32 dir = D_800CD438_CE038[gPlayers[2].character].unk_04;
    s32 file1 = D_800CD438_CE038[gPlayers[2].character].unk_10;

    func_80103BE4_225114_TipsyTourney(obj, dir, file, file1, 2, 2850.0f, 0.0f, 150.0f);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 2);
    func_8000C024_CC24(obj, 4, 1);
    func_80029EDC_2AADC(obj->model[0], 4);
    func_80029EDC_2AADC(obj->model[1], 4);
    func_80029EDC_2AADC(obj->model[3], 4);
    func_80029EDC_2AADC(obj->model[4], 4);
    func_80029EDC_2AADC(obj->model[5], 4);
}

void func_801041FC_22572C_TipsyTourney(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[3].character].unk_08;
    s32 dir = D_800CD438_CE038[gPlayers[3].character].unk_04;
    s32 file1 = D_800CD438_CE038[gPlayers[3].character].unk_10;

    func_80103BE4_225114_TipsyTourney(obj, dir, file, file1, 3, -3150.0f, 0.0f, 150.0f);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 2);
    func_80029EDC_2AADC(obj->model[0], 8);
    func_80029EDC_2AADC(obj->model[1], 8);
    func_80029EDC_2AADC(obj->model[3], 8);
    func_80029EDC_2AADC(obj->model[4], 8);
    func_80029EDC_2AADC(obj->model[5], 8);
}

void func_80104318_225848_TipsyTourney(omObjData* obj, s32 file, f32 scale, f32 angle, f32 x, f32 y, f32 z, s32 idx) {
    TipsyBallWork* work;

    obj->unk_50 = func_80027154_27D54(0xAC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xAC);
    obj->func_ptr = func_80106C48_228178_TipsyTourney;
    work = obj->unk_50;
    obj->model[0] = LoadFormFile(file, 0x899);
    obj->model[1] = 0;
    obj->model[2] = LoadFormFile(0xB, 0x88D);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    work->unk_44 = 0.1f;
    work->unk_48 = 45.0f;
    work->unk_34 = 45.0f;
    work->unk_3C = angle;
    work->unk_52 = 7;
    work->unk_78 = idx;
    work->unk_54 = 1;
    func_8000C37C_CF7C(obj, scale, scale, scale);
}

void func_80104458_225988_TipsyTourney(omObjData* obj) {
    func_80104318_225848_TipsyTourney(obj, 0x3C0000, 1.5f, 180.0f, 1000.0f, 0.0f, 0.0f, 0);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[2], 1);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 1);
}

void func_80104520_225A50_TipsyTourney(omObjData* obj) {
    func_80104318_225848_TipsyTourney(obj, 0x3C0000, 1.5f, 180.0f, -1000.0f, 0.0f, 0.0f, 1);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[2], 2);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 2);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 1);
}

void func_801045EC_225B1C_TipsyTourney(omObjData* obj) {
    func_80104318_225848_TipsyTourney(obj, 0x3C0000, 1.5f, 180.0f, 3000.0f, 0.0f, 0.0f, 2);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 4);
    func_80029EDC_2AADC(obj->model[2], 4);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 2);
    func_8000C024_CC24(obj, 4, 1);
}

void func_801046BC_225BEC_TipsyTourney(omObjData* obj) {
    func_80104318_225848_TipsyTourney(obj, 0x3C0000, 1.5f, 180.0f, -3000.0f, 0.0f, 0.0f, 3);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 8);
    func_80029EDC_2AADC(obj->model[2], 8);
    func_8000C024_CC24(obj, 1, 1);
    func_8000C024_CC24(obj, 2, 1);
    func_8000C024_CC24(obj, 3, 1);
    func_8000C024_CC24(obj, 4, 2);
}

void func_8010478C_225CBC_TipsyTourney(omObjData* obj) {
    D_80107F10_229440_TipsyTourney = func_8001AAAC_1B6AC((s16)func_8001A2F8_1AEF8(0x3C0004), 0, 1);
    espDispOff(D_80107F10_229440_TipsyTourney);
    obj->work[1] = 0;
    obj->func_ptr = func_801047F0_225D20_TipsyTourney;
}

void func_801047F0_225D20_TipsyTourney(void) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* frame;
    s16 i;
    s16 x;
    s16 y;

    spr = func_80082550_83150(D_80107F10_229440_TipsyTourney, 0);
    frame = &spr->unk_84->unk00[spr->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_80107C98_2291C8_TipsyTourney);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    for (i = 0; i < 16; i++) {
        func_8003F710_40310(&D_800FDBCC_FE7CC, (u8*)frame->unk00 + i * 0x640, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 160, 0, 0, 160,
                            10, 0, 2, 2, 0, 0, 0, 0);
        for (y = i * 10; y < 240; y += 160) {
            for (x = 0; x < 320; x += 160) {
                gSPTextureRectangle(D_800FDBCC_FE7CC++, x * 4, y * 4, (x + 160) * 4, (y + 10) * 4, G_TX_RENDERTILE, 0, 0,
                                    0x400, 0x400);
            }
        }
    }
}

// scheduling: one sll before the lui of ContBtnTrg's address (masked 1, as in MP1)
#ifdef NON_MATCHING
void func_80104AEC_22601C_TipsyTourney(omObjData* obj) {
    TipsyWork* work = obj->unk_50;
    u16* trg;
    u16* btn;
    u16 savedTrg;
    u16 savedBtn;
    s32 savedX;
    s32 savedY;
    s32 player;
    s32* file;
    f32 cx;
    f32 dx;
    f32 dy;
    f32 dz;

    switch (D_800F8FD0_F9BD0) {
    case 1:
        if (gPlayers[work->unk_59].flags & 1) {
            player = work->unk_57;
            trg = ContBtnTrg + player;
            savedTrg = *trg;
            btn = &ContBtn[player];
            savedBtn = *btn;
            savedX = ContStkX[player];
            savedY = ContStkY[player];
            ContStkY[player] = 0;
            ContStkX[player] = 0;
            *trg = 0;
            *btn = 0;
            func_80107048_228578_TipsyTourney(obj);
            func_80007790_8390(obj);
            *trg = savedTrg;
            *btn = savedBtn;
            ContStkX[player] = savedX;
            ContStkY[player] = savedY;
            return;
        }
        break;
    case 2:
        player = work->unk_59;
        if (D_80107B84_2290B4_TipsyTourney != 0 && _CheckFlag(0xC) == 0 && work->unk_38 == 1000.0f) {
            if (player == D_80107C80_2291B0_TipsyTourney) {
                func_80019B9C_1A79C(obj, 0xD);
                file = D_80107E28_229358_TipsyTourney;
            } else {
                func_80019B9C_1A79C(obj, 0xE);
                file = D_80107E38_229368_TipsyTourney;
            }
            func_800732B0_73EB0(file[player]);
            file[player] = -1;
        }
        work->unk_40 = D_800BF7D0_C03D0;
        work->unk_3C = 0.0f;
        D_800F94A8_FA0A8[player] -= D_800F94A8_FA0A8[player] * 0.01f;
        if (D_800F94A8_FA0A8[player] < 600.0f) {
            D_800F94A8_FA0A8[player] = 600.0f;
        }
        cx = D_801013B0_101FB0[player].x;
        dx = cx - obj->trans.x;
        dy = D_801013B0_101FB0[player].y - obj->trans.y;
        dz = D_801013B0_101FB0[player].z - obj->trans.z;
        if (dx > 20.0f) {
            D_801013B0_101FB0[player].x = cx - dx * 0.05f;
        } else if (dx < -20.0f) {
            D_801013B0_101FB0[player].x -= dx * 0.05f;
        }
        if (player == D_80107C80_2291B0_TipsyTourney) {
            dy = D_801013B0_101FB0[player].y - (obj->trans.y + 80.0f);
            if (dy > 100.0f) {
                D_801013B0_101FB0[player].y = D_801013B0_101FB0[player].y - dy * 0.05f;
            } else if (dy < -100.0f) {
                D_801013B0_101FB0[player].y -= dy * 0.05f;
            }
        } else {
            if (dy > 100.0f) {
                goto movey;
            }
            if (dy < -100.0f) {
            movey:
                D_801013B0_101FB0[player].y -= dy * 0.05f;
            }
        }
        if (dz > 100.0f) {
            goto movez;
        }
        if (dz < -100.0f) {
        movez:
            D_801013B0_101FB0[player].z -= dz * 0.05f;
        }
        D_80102770_103370[player].x += 0.5f;
        if (D_80102770_103370[player].x > 330.0f) {
            D_80102770_103370[player].x = 330.0f;
        }
        break;
    }
    func_80007790_8390(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_TipsyTourney/223D30", func_80104AEC_22601C_TipsyTourney);
#endif

void func_80104FC4_2264F4_TipsyTourney(omObjData* obj, f32 dx, f32 dz) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        obj->rot.x += dx;
        obj->rot.z += dz;
        if (obj->rot.x > 15.0f) {
            obj->rot.x = 15.0f;
        }
        if (obj->rot.x < -15.0f) {
            obj->rot.x = -15.0f;
        }
        if (obj->rot.z > 15.0f) {
            obj->rot.z = 15.0f;
        }
        if (obj->rot.z < -15.0f) {
            obj->rot.z = -15.0f;
        }
    }
}

f32 func_801050C4_2265F4_TipsyTourney(omObjData* obj) {
    Matrix4f m;
    Matrix4f inv;
    Vec3f pos;
    f32 tilt;
    f32 acc;
    f32 d;
    f32 a;
    f32 x;
    f32 z;
    s16 i;
    u8 plat;
    omObjData* p;

    acc = 0.0f;
    plat = TIPSY_BG(obj)->unk_04;
    tilt = obj->rot.x;
    for (i = 0; i < D_800FC87A_FD47A; i++) {
        p = D_800FFFD8_100BD8[i];
        if (TIPSY_WORK(p)->unk_53 == plat) {
            pos.x = p->trans.x;
            pos.y = p->trans.y;
            pos.z = p->trans.z;
            func_8000D434_E034(m, inv, &pos, obj);
            x = pos.x;
            z = pos.z;
            d = func_800B1830_B2430(x * x + z * z);
            if (d != 0.0f) {
                a = func_800B75A8_B81A8(pos.x, -pos.z);
                if ((a > 120.0f) | (a < -120.0f)) {
                    acc += d / 400.0f;
                } else if ((a < 60.0f) & (a > -60.0f)) {
                    acc += -d / 400.0f;
                }
            }
            break;
        }
    }
    if ((fabsf(tilt) > 15.0f) & (acc != 0.0f)) {
        acc = 0.0f;
    } else if ((tilt != 0.0f) & (acc == 0.0f)) {
        acc = -tilt / 15.0f;
    }
    return acc;
}

f32 func_80105378_2268A8_TipsyTourney(omObjData* obj) {
    Matrix4f m;
    Matrix4f inv;
    Vec3f pos;
    f32 tilt;
    f32 acc;
    f32 d;
    f32 a;
    f32 x;
    f32 z;
    s16 i;
    u8 plat;
    omObjData* p;

    acc = 0.0f;
    plat = TIPSY_BG(obj)->unk_04;
    tilt = obj->rot.z;
    for (i = 0; i < D_800FC87A_FD47A; i++) {
        p = D_800FFFD8_100BD8[i];
        if (TIPSY_WORK(p)->unk_53 == plat) {
            pos.x = p->trans.x;
            pos.y = p->trans.y;
            pos.z = p->trans.z;
            func_8000D434_E034(m, inv, &pos, obj);
            x = pos.x;
            z = pos.z;
            d = func_800B1830_B2430(x * x + z * z);
            if (d != 0.0f) {
                a = func_800B75A8_B81A8(pos.x, -pos.z);
                if ((a < 150.0f) & (a > 30.0f)) {
                    acc += -d / 400.0f;
                } else if ((a > -150.0f) & (a < -30.0f)) {
                    acc += d / 400.0f;
                }
            }
            break;
        }
    }
    if ((fabs(tilt) > 15.0) & (acc != 0.0f)) {
        acc = 0.0f;
    } else if ((tilt != 0.0f) & (acc == 0.0f)) {
        acc = -tilt / 15.0f;
    }
    return acc;
}

void func_80105628_226B58_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    s32 r;
    s32 c;
    s32 n;
    omObjData* ball;
    TipsyBallWork* bw;

    for (r = 0, n = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            n += D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][r][c] != 0;
        }
    }
    if (n == 25) {
        func_8000C398_CF98();
        if (D_80107C80_2291B0_TipsyTourney == -1) {
            D_80107C80_2291B0_TipsyTourney = work->unk_04 - 1;
            gPlayers[work->unk_04 - 1].coins_mg_bonus += 10;
            for (n = 0; n < D_800FA606_FB206; n++) {
                ball = D_800F9CE0_FA8E0[n];
                bw = ball->unk_50;
                if (bw->unk_54 != 0) {
                    bw->unk_54 = 0;
                    func_800298A4_2A4A4(ball->model[0], 4, 4);
                    func_800298A4_2A4A4(ball->model[2], 4, 0);
                    func_80029714_2A314(ball->model[2], ball->trans.x, ball->trans.y + 50.0f, ball->trans.z);
                    func_80029C74_2A874(ball->model[2], 0.0f);
                }
            }
        }
    }
}

// address association: retail hoists D_80107B88 - 0x32 into a saved register (out of the loop) and adds the tile offset to it (masked 8 with that pointer written out; as in MP1)
#ifdef NON_MATCHING
void func_801057F4_226D24_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    u8 plat = work->unk_04;
    s16 i;
    omObjData* ball;
    TipsyBallWork* bw;
    Vec3f pos;
    f32 fx;
    f32 fz;
    s16 cx;
    s16 cz;
    s16* tile;

    for (i = 0; i < D_800FA606_FB206; i++) {
        ball = D_800F9CE0_FA8E0[i];
        bw = ball->unk_50;
        if (bw->unk_53 == plat) {
            pos.x = ball->trans.x;
            pos.y = ball->trans.y;
            pos.z = ball->trans.z;
            func_8000D434_E034(D_80107DA8_2292D8_TipsyTourney, D_80107DE8_229318_TipsyTourney, &pos, obj);
            fx = (pos.x + 250.0f) / 100.0f;
            cx = fx;
            fz = (pos.z + 250.0f) / 100.0f;
            cz = fz;
            fx -= cx;
            fz -= cz;
            D_80107C50_229180_TipsyTourney[bw->unk_78].x = pos.x;
            D_80107C50_229180_TipsyTourney[bw->unk_78].y = pos.y;
            D_80107C50_229180_TipsyTourney[bw->unk_78].z = pos.z;
            if ((fx > 0.0f) & (fx < 1.0f)) {
                if ((fz > 0.0f) & (fz < 1.0f)) {
                    tile = &D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][cz][cx];
                    if (*tile == 0) {
                        (*tile)++;
                        func_80079798_7A398(0x295, plat);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_TipsyTourney/223D30", func_801057F4_226D24_TipsyTourney);
#endif

void func_80105AC0_226FF0_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    s32 r;
    s32 c;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][r][c] > 0) {
                    D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][r][c] += 2;
                    if (D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][r][c] >= 0x37) {
                        D_80107B88_2290B8_TipsyTourney[work->unk_04 - 1][r][c] = -1;
                    }
                }
            }
        }
    }
}

void func_80105BA8_2270D8_TipsyTourney(void) {
    s32 p;
    s32 r;
    s32 c;

    for (p = 0; p < 4; p++) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_80107B88_2290B8_TipsyTourney[p][r][c] == 0) {
                    D_80107B88_2290B8_TipsyTourney[p][r][c]++;
                }
            }
        }
    }
}

void func_80105C40_227170_TipsyTourney(void) {
    s32 p;
    s32 r;
    s32 c;
    s32 left;

    for (p = 0, left = 0; p < 4; p++) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_80107B88_2290B8_TipsyTourney[p][r][c] != -1) {
                    left = 1;
                }
            }
        }
        if (left == 0) {
            func_800298A4_2A4A4(D_800FC7B0_FD3B0[p + 1]->model[1], 4, 4);
        }
    }
}

// register reuse: retail copies the loop start with move, this reloads it with lhu (masked 2, as in MP1)
#ifdef NON_MATCHING
void func_80105D28_227258_TipsyTourney(s16 model, s32 p) {
    HmfData* m = D_800FC834_FD434[model].hmf;
    HmfFace* g;
    f32 minX;
    f32 minZ;
    f32 maxX;
    f32 maxZ;
    f32 w;
    f32 h;
    f32 lx;
    f32 lz;
    s16 start;
    s16 k;
    s16 r;
    s16 c;

    minZ = 10000.0f;
    minX = 10000.0f;
    maxZ = -10000.0f;
    maxX = -10000.0f;
    g = &m->unkB4[start = m->unk64->unk0E];
    for (k = start; k < (s16)m->unk64->unk10; k++, g++) {
        if (g->unk0C < minX) {
            minX = g->unk0C;
        }
        if (g->unk14 < minZ) {
            minZ = g->unk14;
        }
        if (maxX < g->unk0C) {
            maxX = g->unk0C;
        }
        if (maxZ < g->unk14) {
            maxZ = g->unk14;
        }
    }
    w = (maxX - minX) / 5.0f;
    h = (maxZ - minZ) / 5.0f;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            g = &m->unkB4[start = m->unk64->unk0E];
            for (k = start; k < (s16)m->unk64->unk10; k++, g++) {
                lx = minX + w * c;
                if (lx <= g->unk0C && g->unk0C <= lx + w) {
                    lz = minZ + h * r;
                    if (lz <= g->unk14 && g->unk14 <= lz + h) {
                        break;
                    }
                }
            }
            if (k != (s16)m->unk64->unk10) {
                D_80107E48_229378_TipsyTourney[p][c][r] = k;
            }
            D_80107B88_2290B8_TipsyTourney[p][c][r] = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_TipsyTourney/223D30", func_80105D28_227258_TipsyTourney);
#endif

void func_80105FF0_227520_TipsyTourney(s16 model, s32 p) {
    HmfData* m = D_800FC834_FD434[model].hmf;
    HmfFace* g;
    HmfVtx* dst;
    HmfVtx* src;
    s16 r;
    s16 c;
    s16 k;
    s16 v;
    s16 idx;
    s16 t;
    s32 drop;
    f32 spin;
    f32 scale;
    f32 a;
    f32 d;
    f32 dx;
    f32 dz;

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            v = D_80107B88_2290B8_TipsyTourney[p][r][c];
            if (v != 0) {
                g = &m->unkB4[D_80107E48_229378_TipsyTourney[p][c][r]];
                if (v < 0) {
                    for (k = 0; k < g->unk00; k++) {
                        idx = g->unk02[k];
                        dst = &m->unk44[D_800FDBE0_FE7E0][idx];
                        src = &m->unk40[idx];
                        dst->unk08 = (u16)src->unk08 + 0x600;
                    }
                } else {
                    spin = D_80107B88_2290B8_TipsyTourney[p][r][c] * (((r | c) & 1) ? 10.0f : -10.0f);
                    t = D_80107B88_2290B8_TipsyTourney[p][r][c];
                    scale = 1.0f - t / 54.0f;
                    drop = t >> 3;
                    if (drop > 10) {
                        drop = 10;
                    }
                    for (k = 0; k < g->unk00; k++) {
                        dst = &m->unk44[D_800FDBE0_FE7E0][idx = g->unk02[k]];
                        src = &m->unk40[idx];
                        a = func_800B75A8_B81A8(g->unk0C - src->unk00, g->unk14 - src->unk04);
                        dx = g->unk0C - src->unk00;
                        dz = g->unk14 - src->unk04;
                        d = func_800B1830_B2430(dx * dx + dz * dz) * scale;
                        a += spin;
                        dst->unk00 = HuMathSin(a) * d + g->unk0C;
                        dst->unk04 = func_800B7890_B8490(a) * d + g->unk14;
                        dst->unk02 = src->unk02 - drop;
                    }
                }
            }
        }
    }
}

void func_8010643C_22796C_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    f32 dz;

    if (D_800F8FD0_F9BD0 == 1) {
        func_801057F4_226D24_TipsyTourney(obj);
        func_80105628_226B58_TipsyTourney(obj);
        func_8000BEA4_CAA4(obj, 30.0f);
        D_80107DA0_2292D0_TipsyTourney = func_801050C4_2265F4_TipsyTourney(obj);
        D_80107DA4_2292D4_TipsyTourney = dz = func_80105378_2268A8_TipsyTourney(obj);
        func_80104FC4_2264F4_TipsyTourney(obj, D_80107DA0_2292D0_TipsyTourney, dz);
        func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    } else {
        func_8000BEA4_CAA4(obj, 0.0f);
    }
    func_80105AC0_226FF0_TipsyTourney(obj);
    func_80105FF0_227520_TipsyTourney(obj->model[1], work->unk_04 - 1);
}

f32 func_80106514_227A44_TipsyTourney(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal) {
    TipsyBallWork* work = obj->unk_50;
    Vec4f s;
    f32 ret;
    f32 h;

    ret = -10000.0f;
    s.x = x;
    s.y = y;
    s.z = z;
    s.w = work->unk_48;
    if (work->unk_54 != 0) {
        func_801078DC_228E0C_TipsyTourney(&s);
    }
    func_80006F34_7B34(obj, &s, 0.0f);
    h = func_800023CC_2FCC(obj, x + D_800F94A0_FA0A0, y, z + D_80101308_101F08, normal);
    if (ret < h) {
        ret = h;
    }
    return ret;
}

void func_80106600_227B30_TipsyTourney(omObjData* obj, Vec3f* normal) {
    s32 idx = ((TipsyBallWork*)obj->unk_50)->unk_78;
    f32 tx;
    f32 tz;
    f32 x;
    f32 z;

    tx = -(func_800B75A8_B81A8(normal->y, normal->z) - 90.0f);
    tz = func_800B75A8_B81A8(normal->y, normal->x) - 90.0f;
    x = D_80107CD8_229208_TipsyTourney[idx].x;
    z = D_80107CD8_229208_TipsyTourney[idx].z;
    if (x < tx) {
        x += 4.0f;
        if (tx < x) {
            x = tx;
        }
    } else if (tx < x) {
        x -= 4.0f;
        if (x < tx) {
            x = tx;
        }
    }
    if (z < tz) {
        z += 4.0f;
        if (tz < z) {
            z = tz;
        }
    } else if (tz < z) {
        z -= 4.0f;
        if (z < tz) {
            z = tz;
        }
    }
    obj->rot.x = D_80107CD8_229208_TipsyTourney[idx].x = x;
    obj->rot.z = D_80107CD8_229208_TipsyTourney[idx].z = z;
}

void func_8010678C_227CBC_TipsyTourney(omObjData* obj) {
    TipsyBallWork* work = obj->unk_50;
    f32 x;
    f32 y;
    f32 z;
    f32 vy;
    f32 angle;
    f32 speed;
    f32 ground;
    f32 h;
    s32 idx;

    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    ground = -10000.0f;
    idx = work->unk_78;
    vy = work->unk_38;
    angle = work->unk_3C;
    speed = work->unk_40;
    D_800F94A0_FA0A0 = D_80101308_101F08 = 0.0f;
    if (vy < 1000.0f) {
        if (vy > 1.0f) {
            vy = 1.0f;
        }
        y += vy * vy * ((vy >= 0.0f) ? -35.0f : 35.0f);
        vy += 0.04f;
        x += HuMathSin(angle) * speed;
        z += func_800B7890_B8490(angle) * speed;
        h = func_80106514_227A44_TipsyTourney(obj, x, y, z, &D_80107D18_229248_TipsyTourney[idx]);
        if (h != -65536.0f) {
            ground = h;
            if (y < h) {
                y = ground;
                if (fabs(vy) < 0.6) {
                    vy = 1000.0f;
                } else {
                    vy = -vy * 0.2f;
                }
            } else {
                work->unk_53 = -1;
            }
        } else {
            work->unk_53 = -1;
        }
    } else {
        x += (HuMathSin(angle) * speed + D_80107D18_229248_TipsyTourney[idx].x * D_80107B80_2290B0_TipsyTourney);
        z += (func_800B7890_B8490(angle) * speed + D_80107D18_229248_TipsyTourney[idx].z * D_80107B80_2290B0_TipsyTourney);
        h = func_80106514_227A44_TipsyTourney(obj, x, y, z, &D_80107D18_229248_TipsyTourney[idx]);
        if (h != -65536.0f) {
            if (y < h + 35.0f) {
                y = h;
            } else {
                vy = 0.2f;
                work->unk_53 = -1;
            }
        } else {
            vy = 0.2f;
        }
        ground = y;
        angle = func_800B75A8_B81A8(x, z);
    }
    obj->trans.x = x + D_800F94A0_FA0A0;
    obj->trans.y = y;
    obj->trans.z = z + D_80101308_101F08;
    work->unk_38 = vy;
    work->unk_3C = angle;
    work->unk_40 = speed;
    D_80107D08_229238_TipsyTourney[idx] = func_8002D958_2E558(D_80107D08_229238_TipsyTourney[idx] + 4.0f);
    if ((obj->model[1] != 0) & (ground != -10000.0f)) {
        func_80029714_2A314(obj->model[1], x + D_800F94A0_FA0A0, ground, z + D_80101308_101F08);
        func_800297E8_2A3E8(obj->model[1], 0.3f, 0.3f, 0.3f);
        func_8003C984_3D584(obj->model[1], &D_80107D18_229248_TipsyTourney[idx]);
    }
    func_80106600_227B30_TipsyTourney(obj, &D_80107D18_229248_TipsyTourney[idx]);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, D_80107D08_229238_TipsyTourney[idx], 0.0f);
}

void func_80106C48_228178_TipsyTourney(omObjData* obj) {
    TipsyBallWork* work;

    if (D_800F8FD0_F9BD0 < 2) {
        D_80107B80_2290B0_TipsyTourney = 30.0f;
    } else {
        work = obj->unk_50;
        if (work->unk_54 != 0) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[2], 4, 0);
            func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y + 50.0f, obj->trans.z);
            func_80029C74_2A874(obj->model[2], 0.0f);
            work->unk_54 = 0;
        }
        D_80107B80_2290B0_TipsyTourney = 0.0f;
    }
    func_8010678C_227CBC_TipsyTourney(obj);
}

// address association in the first loop (the base's lui after p * 0x32; masked 3, as in MP1)
#ifdef NON_MATCHING
s32 func_80106D14_228244_TipsyTourney(s32 p) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        if (D_80107B88_2290B8_TipsyTourney[p][0][i] == 0) {
            return 0;
        }
    }
    for (i = 0, j = 0; i < 5; i++) {
        if (D_80107B88_2290B8_TipsyTourney[p][i][j] == 0) {
            return 0;
        }
    }
    for (i = 0; i < 5; i++) {
        if (D_80107B88_2290B8_TipsyTourney[p][4][i] == 0) {
            return 0;
        }
    }
    for (i = 0, j = 4; i < 5; i++) {
        if (D_80107B88_2290B8_TipsyTourney[p][i][j] == 0) {
            return 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_TipsyTourney/223D30", func_80106D14_228244_TipsyTourney);
#endif

s32 func_80106E64_228394_TipsyTourney(s32 p) {
    if (D_80107B88_2290B8_TipsyTourney[p][1][1] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][1][2] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][1][3] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][2][1] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][2][3] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][3][1] == 0) {
        return 0;
    }
    if (D_80107B88_2290B8_TipsyTourney[p][3][2] != 0) {
        return D_80107B88_2290B8_TipsyTourney[p][3][3] != 0;
    }
    return 0;
}

s32 func_80106F94_2284C4_TipsyTourney(s32 p) {
    s32 n;

    n = D_80107B88_2290B8_TipsyTourney[p][1][1] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][1][2] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][1][3] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][2][1] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][2][3] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][3][1] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][3][2] == 0;
    n += D_80107B88_2290B8_TipsyTourney[p][3][3] == 0;
    return n;
}

void func_80107048_228578_TipsyTourney(omObjData* obj) {
    TipsyWork* work = obj->unk_50;
    TipsyBgWork* pw;
    omObjData* plat;
    Vec3f pos;
    Vec3f dir;
    f32 mul;
    f32 a;
    f32 dist;
    s32 dx;
    s32 dz;
    s32 port;
    s32 diff;
    u8 r;

    port = work->unk_57;
    switch (gPlayers[work->unk_59].cpu_difficulty) {
    case 0:
        mul = 0.6f;
        break;
    case 1:
        mul = 0.7f;
        break;
    case 2:
        mul = 0.8f;
        break;
    default:
        mul = 0.9f;
        break;
    }
    if (work->unk_53 >= 0) {
        plat = D_800FC7B0_FD3B0[work->unk_53];
        pw = plat->unk_50;
        pos.x = obj->trans.x;
        pos.y = obj->trans.y;
        pos.z = obj->trans.z;
        func_8000D434_E034(D_80107DA8_2292D8_TipsyTourney, D_80107DE8_229318_TipsyTourney, &pos, plat);
        dir.y = 0.0f;
        if (func_80106D14_228244_TipsyTourney(pw->unk_04 - 1) == 0) {
            a = func_800B75A8_B81A8(pos.x, pos.z) + D_80107D60_229290_TipsyTourney[work->unk_59] * 15.0f;
            dir.x = HuMathSin(a) * 250.0f - pos.x;
            dir.z = func_800B7890_B8490(a) * 250.0f - pos.z;
            func_8002D9AC_2E5AC(&dir);
            dir.x *= mul * 60.0f;
            dir.z *= mul * 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        } else {
            diff = gPlayers[work->unk_59].cpu_difficulty;
            if (diff < 4) {
                if (diff >= 2 && func_80106E64_228394_TipsyTourney(pw->unk_04 - 1) == 0) {
                    a = func_800B75A8_B81A8(pos.x, pos.z) + D_80107D60_229290_TipsyTourney[work->unk_59] * 15.0f;
                    dir.x = HuMathSin(a) * 165.0f - pos.x;
                    dir.z = func_800B7890_B8490(a) * 165.0f - pos.z;
                    func_8002D9AC_2E5AC(&dir);
                    if (func_80106F94_2284C4_TipsyTourney(pw->unk_04 - 1) >= 3) {
                        dir.x *= 39.0f;
                        dir.z *= 39.0f;
                        ContStkX[port] = dir.x;
                        ContStkY[port] = -dir.z;
                        return;
                    }
                }
            }
            dx = D_80107C50_229180_TipsyTourney[pw->unk_04 - 1].x - pos.x;
            dz = D_80107C50_229180_TipsyTourney[pw->unk_04 - 1].z - pos.z;
            dist = func_800B1830_B2430(dx * dx + dz * dz);
            if (dist > 500.0f) {
                dist = 0.0f;
                dir.z = 0.0f;
                dir.x = 0.0f;
            } else if (dist < 150.0f && D_80107D70_2292A0_TipsyTourney[work->unk_59] < 0) {
                ContBtnTrg[port] = 0x8000;
                D_80107D70_2292A0_TipsyTourney[work->unk_59] = 0x5A;
                dir.x = HuMathSin(work->unk_3C);
                dir.z = -func_800B7890_B8490(work->unk_3C);
                D_80107D78_2292A8_TipsyTourney[work->unk_59].x = dir.x *= 60.0f;
                D_80107D78_2292A8_TipsyTourney[work->unk_59].z = dir.z *= 60.0f;
            } else {
                a = func_800B75A8_B81A8(pos.x, pos.z) + D_80107D60_229290_TipsyTourney[work->unk_59] * 10.0f;
                dir.x = HuMathSin(a) * 165.0f - pos.x;
                dir.z = func_800B7890_B8490(a) * 165.0f - pos.z;
                func_8002D9AC_2E5AC(&dir);
                if (D_80107D58_229288_TipsyTourney[work->unk_59] == 0.0f) {
                    r = rand8();
                    switch (r >> 6) {
                    case 0:
                        D_80107D48_229278_TipsyTourney[work->unk_59] = mul * 0.9f;
                        D_80107D58_229288_TipsyTourney[work->unk_59] = mul * 90.0f;
                        break;
                    case 1:
                        D_80107D48_229278_TipsyTourney[work->unk_59] = mul * 0.8f;
                        D_80107D58_229288_TipsyTourney[work->unk_59] = mul * 90.0f;
                        break;
                    case 2:
                        D_80107D48_229278_TipsyTourney[work->unk_59] = mul * 0.75f;
                        D_80107D58_229288_TipsyTourney[work->unk_59] = mul * 90.0f;
                        break;
                    default:
                        D_80107D48_229278_TipsyTourney[work->unk_59] = 0.0f;
                        D_80107D58_229288_TipsyTourney[work->unk_59] = 0x2D;
                        break;
                    }
                    if (r > 0x80) {
                        if (D_80107D60_229290_TipsyTourney[work->unk_59] > 0.0) {
                            D_80107D60_229290_TipsyTourney[work->unk_59] = -1.0f;
                        } else {
                            D_80107D60_229290_TipsyTourney[work->unk_59] = 1.0f;
                        }
                    }
                } else {
                    D_80107D70_2292A0_TipsyTourney[work->unk_59]--;
                    D_80107D58_229288_TipsyTourney[work->unk_59]--;
                }
                dist = D_80107D48_229278_TipsyTourney[work->unk_59];
            }
            dir.x *= dist * 60.0f;
            dir.z *= dist * 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        }
    } else {
        ContBtn[port] = 0x8000;
        ContStkX[port] = (s8)D_80107D78_2292A8_TipsyTourney[work->unk_59].x;
        ContStkY[port] = (s8)D_80107D78_2292A8_TipsyTourney[work->unk_59].z;
    }
}

void func_801078DC_228E0C_TipsyTourney(Vec4f* s) {
    s32 i;
    omObjData* p;
    TipsyWork* pw;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    for (i = 0; i < D_800FC87A_FD47A; i++) {
        p = D_800FFFD8_100BD8[i];
        pw = p->unk_50;
        dx = p->trans.x - s->x;
        dy = p->trans.y - s->y;
        dz = p->trans.z - s->z;
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz) - (s->w + pw->unk_48);
        if (d < 0.0f && pw->unk_38 == 1000.0f) {
            func_80009684_A284(dx, dz, d);
        }
    }
}

s32 func_80107A0C_228F3C_TipsyTourney(omObjData* obj, omObjData* other) {
    TipsyWork* work = obj->unk_50;
    TipsyWork* ow = other->unk_50;
    f32 speed;
    f32 px;
    f32 pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    speed = work->unk_40;
    if (work->unk_50 & 6) {
        speed *= 0.6f;
    }
    px = HuMathSin(work->unk_3C) * speed + obj->trans.x;
    pz = func_800B7890_B8490(work->unk_3C) * speed + obj->trans.z;
    dx = other->trans.x - px;
    dy = other->trans.y - obj->trans.y;
    dz = other->trans.z - pz;
    d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz) - (ow->unk_48 + work->unk_48);
    if (d < 0.0f) {
        if (work->unk_38 != 1000.0f) {
            func_8000DCD4_E8D4(obj, dx, dz);
            omVibrate(work->unk_59, 2, 3, 0xA);
        } else {
            func_80009684_A284(dx, dz, d);
        }
    }
    return 1;
}

