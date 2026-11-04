#include "ovl_3A.h"

/* .data (0x28B470-0x28B5A0, 80109260-80109390) */
s8 D_80109260_28B470_TorpedoTargets = -1;
s8 D_80109261_28B471_TorpedoTargets = -1;
s8 D_80109262_28B472_TorpedoTargets = 0;
s8 D_80109263_28B473_TorpedoTargets = 0;
omObjData* D_80109264_28B474_TorpedoTargets[2] = { NULL, NULL };
Vec D_8010926C_28B47C_TorpedoTargets[2] = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
Vec D_80109284_28B494_TorpedoTargets[4] = {
    { -617.0f, -1279.0f, 1903.15f }, { 1618.5f, -853.0f, 1174.25f },
    { 1608.15f, -1232.0f, -1181.0f }, { -621.0f, -915.0f, -1901.5f },
};
s8 D_801092B4_28B4C4_TorpedoTargets = -0x1E;
s8 D_801092B5_28B4C5_TorpedoTargets = 0;
s8 D_801092B6_28B4C6_TorpedoTargets = 0;
s8 D_801092B7_28B4C7_TorpedoTargets = 0;
s8 D_801092B8_28B4C8_TorpedoTargets[4] = { 0, 0, 0, 0 };
u8 D_801092BC_28B4CC_TorpedoTargets[4] = { 0, 0, 0, 0 };
u8 D_801092C0_28B4D0_TorpedoTargets[4] = { 0, 0, 0, 0 };
f32 D_801092C4_28B4D4_TorpedoTargets[2] = { 0.0f, 0.0f };
u32 D_801092CC_28B4DC_TorpedoTargets = 0xFFFF0000;
f32 D_801092D0_28B4E0_TorpedoTargets[2] = { 0.0f, 0.0f };
Vec D_801092D8_28B4E8_TorpedoTargets[2] = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
f32 D_801092F0_28B500_TorpedoTargets = 0.0f;
u32 D_801092F4_28B504_TorpedoTargets = 0;
u32 D_801092F8_28B508_TorpedoTargets = 0xE42;
s32 D_801092FC_28B50C_TorpedoTargets = 0;
s32 D_80109300_28B510_TorpedoTargets = 0;
s32 D_80109304_28B514_TorpedoTargets = 0;
s32 D_80109308_28B518_TorpedoTargets = 0;
f32 D_8010930C_28B51C_TorpedoTargets = 0.0f;
f32 D_80109310_28B520_TorpedoTargets = 0.0f;
s16 D_80109314_28B524_TorpedoTargets = -1;
s16 D_80109316_28B526_TorpedoTargets = 0;
s32 D_80109318_28B528_TorpedoTargets[6] = { 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
s32 D_80109330_28B540_TorpedoTargets[6] = { 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23 };
s32 D_80109348_28B558_TorpedoTargets[6] = { 0x24, 0x25, 0x26, 0x27, 0x28, 0x29 };
s32 D_80109360_28B570_TorpedoTargets[6] = { 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F };
s32 D_80109378_28B588_TorpedoTargets[6] = { 0, 0, 0, 0, (s32)0xC3FA0000, 0x43FA0000 };

__asm__(".section .rodata");
const char D_801093D0_28B5E0_TorpedoTargets[] = "\202q\202d\202`\202c\202x\202f\202n\202v\202k\201I";

void func_80102800_284A10_TorpedoTargets(void) {
    omObjData* obj;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0x14, 0x14, 0x1E);
    ScissorSet(0, 8.0f, 8.0f, 312.0f, 119.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 240.0f, 511.0f);
    Hu3DCamSetPerspective(0, 40.0f, 80.0f, 12000.0f);
    ScissorSet(1, 8.0f, 121.0f, 312.0f, 232.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(1, 40.0f, 80.0f, 12000.0f);
    func_80107368_289578_TorpedoTargets();
    func_80107580_289790_TorpedoTargets(0, 0x24, 0x1C);
    func_80107580_289790_TorpedoTargets(1, 0x24, 0x8A);
    func_80107410_289620_TorpedoTargets(0, 0x40, 0x64);
    func_80107410_289620_TorpedoTargets(1, 0x40, 0xD2);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 8, 0, -1, func_80103634_285844_TorpedoTargets);
    omAddObj(2, 9, 0x3C, -1, func_80103828_285A38_TorpedoTargets);
    omAddObj(2, 9, 0x3C, -1, func_80103B2C_285D3C_TorpedoTargets);
    omAddObj(3, 0xA, 0x3C, -1, func_801043AC_2865BC_TorpedoTargets);
    omAddObj(3, 0xA, 0x3C, -1, func_80104464_286674_TorpedoTargets);
    omAddObj(3, 0xA, 0x3C, -1, func_80104524_286734_TorpedoTargets);
    omAddObj(3, 0xA, 0x3C, -1, func_801045E4_2867F4_TorpedoTargets);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_8010478C_28699C_TorpedoTargets);
    obj->work[0] = 2;
    omSetStatBit(obj, 0xA0);
    func_8002C59C_2D19C(0x3E3, 0x3E7, 0x14, 0x14, 0x1E);
    func_8002CD6C_2D96C(4);
    func_8007273C_7333C(D_801093D0_28B5E0_TorpedoTargets, 1);
    func_80026DAC_279AC(0, 0x60, 0x60, 0xC0);
    func_80026DAC_279AC(1, 0xC8, 0xC8, 0xF0);
    func_80026E00_27A00(1, 23.0f, 94.0f, 70.0f);
    func_800794F0_7A0F0(0x7F);
    func_80079684_7A284(0x7F);
    D_800F94A8_FA0A8[0] = 700.0f;
    D_800F94A8_FA0A8[1] = 700.0f;
    D_80102770_103370[0].x = 0.0f;
    D_80102770_103370[1].x = 0.0f;
}

void func_80102BC4_284DD4_TorpedoTargets(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

void func_80102BF0_284E00_TorpedoTargets(omObjData* obj) {
    Vec3f dir;
    s32 m1;
    s32 m0;
    s32 i;

    m0 = 0;
    m1 = 0;
    for (i = 0; i < 2; i++) {
        omObjData* sub = D_80109264_28B474_TorpedoTargets[i];

        if (sub->trans.y < -1000.0f) {
            m1 |= 1 << i;
        } else if (sub->trans.y < 1650.0f && D_80102770_103370[i].x < -10.0f) {
            m1 |= 1 << i;
        } else if (D_80102770_103370[i].x > -2.0f) {
            if (sub->trans.y < -300.0f) {
                m1 |= 1 << i;
            }
        } else if (sub->trans.y < 1000.0f) {
            m1 |= 1 << i;
        }
        dir.x = D_801092D8_28B4E8_TorpedoTargets[i].x - D_801013B0_101FB0[i].x;
        dir.y = D_801092D8_28B4E8_TorpedoTargets[i].y - D_801013B0_101FB0[i].y;
        dir.z = D_801092D8_28B4E8_TorpedoTargets[i].z - D_801013B0_101FB0[i].z;
        func_8002D9AC_2E5AC(&dir);
        if (!((m1 >> i) & 1) || dir.y < -0.3f) {
            m0 |= 1 << i;
        }
    }
    func_80029EDC_2AADC(obj->model[1], m0);
    func_80029EDC_2AADC(obj->model[2], m1);
}

void func_80102E54_285064_TorpedoTargets(omObjData* obj) {
    omObjData* sub;
    TTSub* w;
    s32 i;
    f32 x;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 zero;
    f32 twelve;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        func_8000C3C8_CFC8();
        switch (D_800F8FD0_F9BD0) {
        case 0:
            if (D_801092F4_28B504_TorpedoTargets == 5) {
                InitFadeIn(0, 0x10);
                D_80109314_28B524_TorpedoTargets = PlaySound(0x30A);
            }
            if (D_801092F4_28B504_TorpedoTargets >= 6) {
                if (func_8008F618_90218() != 0) {
                    return;
                }
                if (D_801092F4_28B504_TorpedoTargets == 0x2D) {
                    PlayMusic(0x2A);
                }
                if (D_801092F4_28B504_TorpedoTargets == 0x50) {
                    func_800691FC_69DFC(0);
                }
                if (D_801092F4_28B504_TorpedoTargets >= 0x79) {
                    func_801079B0_289BC0_TorpedoTargets();
                    func_800691FC_69DFC(0xA, 0x3C, 0xA0, 0x18);
                    func_8000C3B8_CFB8();
                }
            }
            D_801092F4_28B504_TorpedoTargets++;
            break;
        case 1:
            func_8006D4D0_6E0D0(D_801092F8_28B508_TorpedoTargets / 60);
            func_80108934_28AB44_TorpedoTargets();
            D_801092F8_28B508_TorpedoTargets -= 2;
            if (D_801092F8_28B508_TorpedoTargets == 0) {
                func_8000C398_CF98();
            }
            break;
        case 2:
            if (D_801092FC_28B50C_TorpedoTargets == 0) {
                if (D_801092BC_28B4CC_TorpedoTargets[0] == D_801092BC_28B4CC_TorpedoTargets[1]) {
                    D_80109264_28B474_TorpedoTargets[0]->func_ptr = func_80107D54_289F64_TorpedoTargets;
                    D_80109264_28B474_TorpedoTargets[1]->func_ptr = func_80107D54_289F64_TorpedoTargets;
                    D_80109260_28B470_TorpedoTargets = -2;
                } else {
                    if (D_801092BC_28B4CC_TorpedoTargets[0] > D_801092BC_28B4CC_TorpedoTargets[1]) {
                        D_80109264_28B474_TorpedoTargets[0]->func_ptr = func_80107C38_289E48_TorpedoTargets;
                        D_80109264_28B474_TorpedoTargets[1]->func_ptr = func_80107D54_289F64_TorpedoTargets;
                        sub = D_80109264_28B474_TorpedoTargets[0];
                    } else {
                        D_80109264_28B474_TorpedoTargets[1]->func_ptr = func_80107C38_289E48_TorpedoTargets;
                        D_80109264_28B474_TorpedoTargets[0]->func_ptr = func_80107D54_289F64_TorpedoTargets;
                        sub = D_80109264_28B474_TorpedoTargets[1];
                    }
                    w = sub->unk_50;
                    D_8010942C_28B63C_TorpedoTargets = w->pilot;
                    D_80109430_28B640_TorpedoTargets = w->gunner;
                }
                func_800794A8_7A0A8(0x28);
                func_8006D518_6E118();
                func_800691FC_69DFC(3);
            } else if (_CheckFlag(0xC) != 0) {
                if (D_801092FC_28B50C_TorpedoTargets == 0x3C) {
                    if (D_801092BC_28B4CC_TorpedoTargets[0] > D_801092BC_28B4CC_TorpedoTargets[1]) {
                        gPlayers[D_8010942C_28B63C_TorpedoTargets].coins_mg_bonus += 10;
                        gPlayers[D_80109430_28B640_TorpedoTargets].coins_mg_bonus += 10;
                    }
                    func_8000C3A8_CFA8();
                }
            } else if (D_80109260_28B470_TorpedoTargets == -2) {
                if (D_801092FC_28B50C_TorpedoTargets == 0x32) {
                    func_800691FC_69DFC(0x13);
                    PlayMusic(0x57);
                }
                if (D_801092FC_28B50C_TorpedoTargets == 0xAA) {
                    func_8000C3A8_CFA8();
                }
            } else {
                if (D_801092FC_28B50C_TorpedoTargets == 0x32) {
                    func_800691FC_69DFC(0x11, gPlayers[D_8010942C_28B63C_TorpedoTargets].character,
                                        gPlayers[D_80109430_28B640_TorpedoTargets].character);
                    gPlayers[D_8010942C_28B63C_TorpedoTargets].coins_mg_bonus += 10;
                    gPlayers[D_80109430_28B640_TorpedoTargets].coins_mg_bonus += 10;
                    PlayMusic(0x52);
                }
                if (D_801092FC_28B50C_TorpedoTargets == 0xD7) {
                    func_8000C3A8_CFA8();
                }
            }
            func_80109214_28B424_TorpedoTargets();
            D_801092FC_28B50C_TorpedoTargets++;
            break;
        case 3:
            InitFadeOut(0, 0x14);
            func_800794A8_7A0A8(0x28);
            func_80079614_7A214(0x28);
            obj->func_ptr = func_80102BC4_284DD4_TorpedoTargets;
            D_80109300_28B510_TorpedoTargets += 2;
            break;
        }
        D_8010930C_28B51C_TorpedoTargets += 0.3f;
        x = HuMathSin(D_80109310_28B520_TorpedoTargets) * 2500.0f;
        func_80029714_2A314(obj->model[7], x, 1800.0f, func_800B7890_B8490(D_80109310_28B520_TorpedoTargets) * 2500.0f);
        func_8002979C_2A39C(obj->model[7], 0.0f, D_80109310_28B520_TorpedoTargets + 90.0f, 0.0f);
        D_80109310_28B520_TorpedoTargets += 0.25f;
        w = D_80109264_28B474_TorpedoTargets[0]->unk_50;
        func_80107764_289974_TorpedoTargets(0, w->score);
        w = D_80109264_28B474_TorpedoTargets[1]->unk_50;
        func_80107764_289974_TorpedoTargets(1, w->score);
        i = 0;
        twelve = 12.0f;
        zero = 0.0f;
        do {
            f32 frame = func_80029CE4_2A8E4(obj->model[4 + i]);

            if (func_80029D0C_2A90C(obj->model[4 + i]) <= frame) {
                x2 = rand8() & 0xFF;
                x2 *= twelve;
                z2 = rand8() & 0xFF;
                z2 *= twelve;
                y2 = func_80105418_287628_TorpedoTargets(20.0f, x2, 0.0f, z2) - 100.0f;
                func_80029714_2A314(obj->model[4 + i], x2, y2, z2);
                func_80029C74_2A874(obj->model[4 + i], zero);
                D_800FC834_FD434[obj->model[4 + i]].hmf->unk9C->unk08 = zero;
            }
        } while (++i < 3);
        func_80107494_2896A4_TorpedoTargets(0, 0);
        func_80107494_2896A4_TorpedoTargets(1, 0);
    }
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
        obj->func_ptr = func_80102BC4_284DD4_TorpedoTargets;
    }
    func_8002BED4_2CAD4(obj->model[1], D_8010930C_28B51C_TorpedoTargets, 0.0f, D_80109434_28B644_TorpedoTargets[0],
                        D_80109434_28B644_TorpedoTargets[1], "m177_005-grid1", 1);
    func_80102BF0_284E00_TorpedoTargets(obj);
}

void func_80103634_285844_TorpedoTargets(omObjData* obj) {
    obj->model[0] = D_80109418_28B628_TorpedoTargets = func_80018A30_19630(0x4A0010, 0x99);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->model[1] = func_80018A30_19630(0x4A0011, 0x99);
    func_80029714_2A314(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_8003EAF0_3F6F0("nami1_DEF", D_80109434_28B644_TorpedoTargets);
    func_8002A00C_2AC0C(obj->model[1]);
    obj->model[2] = func_80018A30_19630(0x4A0012, 0x99);
    func_80029714_2A314(obj->model[2], 0.0f, 0.0f, 0.0f);
    obj->model[3] = D_8010949C_28B6AC_TorpedoTargets = func_80018A30_19630(0x4A000C, 0x8CD);
    func_800297E8_2A3E8(obj->model[3], 2.0f, 2.0f, 2.0f);
    func_8002D124_2DD24(D_8010949C_28B6AC_TorpedoTargets);
    func_80029714_2A314(D_8010949C_28B6AC_TorpedoTargets, D_801093B8_28B5C8_TorpedoTargets.x,
                        D_801093B8_28B5C8_TorpedoTargets.y, D_801093B8_28B5C8_TorpedoTargets.z);
    func_80029AFC_2A6FC(D_8010949C_28B6AC_TorpedoTargets);
    obj->model[4] = func_80018A30_19630(0x4A0016, 0x899);
    obj->model[5] = func_80027D3C_2893C(obj->model[4]);
    obj->model[6] = func_80027D3C_2893C(obj->model[4]);
    obj->model[7] = func_80018A30_19630(0x4A0017, 0x899);
    func_80029E80_2AA80(obj->model[7], 2, 2);
    obj->func_ptr = func_80102E54_285064_TorpedoTargets;
}

void func_80103828_285A38_TorpedoTargets(omObjData* obj) {
    TTSub* w;

    w = obj->unk_50 = func_80027154_27D54(sizeof(TTSub), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(TTSub));
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(0x4A0000, 0x208D9);
    obj->model[1] = LoadFormFile(0x4A0001, 0x208D9);
    obj->model[2] = LoadFormFile(0x4A0002, 0x208D9);
    obj->model[3] = LoadFormFile(0x4A0003, 0x2089D);
    obj->model[4] = LoadFormFile(0x4A0004, 0x20899);
    obj->model[5] = LoadFormFile(0x4A0014, 0x20899);
    obj->model[6] = LoadFormFile(0x4A000A, 0x2089D);
    obj->model[7] = LoadFormFile(0x4A0015, 0x2089D);
    obj->model[8] = LoadFormFile(0x4A0013, 0x2089D);
    obj->func_ptr = func_80107BAC_289DBC_TorpedoTargets;
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    func_80029E80_2AA80(obj->model[5], 2, 2);
    func_80029E80_2AA80(obj->model[7], 1, 1);
    HmfModelObjAttrSet(obj->model[8], 0x70000000, 0x70000000);
    func_800297E8_2A3E8(obj->model[8], 2.0f, 2.0f, 2.0f);
    w->yaw = 150.0f;
    w->speed = 0.0f;
    w->pilot = 0;
    w->gunner = 0;
    w->pilotObj = NULL;
    w->gunnerObj = NULL;
    w->hit = 0;
    w->unk_125 = 0;
    w->unk_126 = 0;
    w->team = 0;
    w->camDist = 1350.0f;
    D_80109264_28B474_TorpedoTargets[0] = obj;
    obj->trans.x = HuMathSin(0.0f) * 3800.0f;
    obj->trans.y = -1000.0f;
    obj->trans.z = func_800B7890_B8490(0.0f) * 3800.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
    D_80102770_103370[0].x = -5.0f;
    D_80102770_103370[0].y = w->yaw - 180.0f;
}

void func_80103B2C_285D3C_TorpedoTargets(omObjData* obj) {
    TTSub* w;

    w = obj->unk_50 = func_80027154_27D54(sizeof(TTSub), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(TTSub));
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(0x4A0005, 0x208D9);
    obj->model[1] = LoadFormFile(0x4A0006, 0x20899);
    obj->model[2] = LoadFormFile(0x4A0007, 0x20899);
    obj->model[3] = LoadFormFile(0x4A0008, 0x2089D);
    obj->model[4] = LoadFormFile(0x4A0009, 0x20899);
    obj->model[5] = LoadFormFile(0x4A0014, 0x20899);
    obj->model[6] = LoadFormFile(0x4A000B, 0x2089D);
    obj->model[7] = LoadFormFile(0x4A0015, 0x2089D);
    obj->model[8] = LoadFormFile(0x4A0013, 0x2089D);
    obj->func_ptr = func_80107BAC_289DBC_TorpedoTargets;
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    func_80029E80_2AA80(obj->model[5], 2, 2);
    func_80029E80_2AA80(obj->model[7], 1, 1);
    HmfModelObjAttrSet(obj->model[8], 0x70000000, 0x70000000);
    func_800297E8_2A3E8(obj->model[8], 2.0f, 2.0f, 2.0f);
    w->yaw = 330.0f;
    w->speed = 0.0f;
    w->pilot = 0;
    w->gunner = 0;
    w->pilotObj = NULL;
    w->gunnerObj = NULL;
    w->hit = 0;
    w->unk_125 = 0;
    w->unk_126 = 0;
    w->team = 1;
    w->camDist = 1350.0f;
    D_80109264_28B474_TorpedoTargets[1] = obj;
    obj->trans.x = HuMathSin(180.0f) * 3800.0f;
    obj->trans.y = -1000.0f;
    obj->trans.z = func_800B7890_B8490(180.0f) * 3800.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
    D_80102770_103370[1].x = -5.0f;
    D_80102770_103370[1].y = w->yaw - 180.0f;
}

/* Logic right; retail reloads the 1.0f after the call where GCC here keeps it in f20. */
#ifdef NON_MATCHING
void func_80103E40_286050_TorpedoTargets(omObjData* obj, s32 dir, s32 fileA, s32 fileB, s32 team, s32 player) {
    MgWork* w;
    omObjData** sub;
    TTSub* s;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(dir | fileA, 0x20A99);
    obj->model[1] = LoadFormFile(dir | fileB, 0x20A99);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        ((MgMotion*)w->unk_E8)[i].unk_00 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_02 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_04 = -1;
        ((MgMotion*)w->unk_E8)[i].unk_08 = -1;
    }
    obj->func_ptr = func_80104EB0_2870C0_TorpedoTargets;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_60 = 0.0f;
    w->unk_57 = gPlayers[player].port;
    func_8000BE74_CA74(obj, 1000.0f);
    w->unk_9C = w->unk_A0 = w->unk_A4 = 0.0f;
    w->unk_C4 = -1;
    w->unk_59 = player;
    sub = &D_80109264_28B474_TorpedoTargets[team];
    s = (*sub)->unk_50;
    s->pilot = player;
    s->pilotObj = obj;
    obj->trans.x = (*sub)->trans.x;
    obj->trans.y = (*sub)->trans.y;
    obj->trans.z = (*sub)->trans.z;
    obj->rot.x = (*sub)->rot.x;
    obj->rot.y = (*sub)->rot.y;
    obj->rot.z = (*sub)->rot.z;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80103E40_286050_TorpedoTargets);
#endif

/* Logic right; retail reloads the 1.0f after the call where GCC here keeps it in f20. */
#ifdef NON_MATCHING
void func_801040F0_286300_TorpedoTargets(omObjData* obj, s32 dir, s32 fileA, s32 fileB, s32 team, s32 player) {
    MgWork* w;
    omObjData** sub;
    TTSub* s;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(dir | fileA, 0x20A99);
    obj->model[1] = LoadFormFile(dir | fileB, 0x20A99);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        ((MgMotion*)w->unk_E8)[i].unk_00 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_02 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_04 = -1;
        ((MgMotion*)w->unk_E8)[i].unk_08 = -1;
    }
    obj->func_ptr = func_80105124_287334_TorpedoTargets;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_60 = 0.0f;
    w->unk_57 = gPlayers[player].port;
    w->unk_59 = player;
    func_8000BE74_CA74(obj, 1000.0f);
    w->unk_9C = w->unk_A0 = w->unk_A4 = 0.0f;
    w->unk_C4 = -1;
    func_80019B9C_1A79C(obj, 0);
    sub = &D_80109264_28B474_TorpedoTargets[team];
    s = (*sub)->unk_50;
    s->gunnerObj = obj;
    s->gunner = player;
    obj->trans.x = (*sub)->trans.x;
    obj->trans.y = (*sub)->trans.y;
    obj->trans.z = (*sub)->trans.z;
    obj->rot.x = (*sub)->rot.x;
    obj->rot.y = (*sub)->rot.y;
    obj->rot.z = (*sub)->rot.z;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_801040F0_286300_TorpedoTargets);
#endif

void func_801043AC_2865BC_TorpedoTargets(omObjData* obj) {
    u32 group = gPlayers[0].group;
    s32 a = D_80109318_28B528_TorpedoTargets[gPlayers[0].character];
    s32 b = D_80109330_28B540_TorpedoTargets[gPlayers[0].character];
    s32 dir = 0x4A0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80103E40_286050_TorpedoTargets(obj, dir, a, b, team, 0);
        break;
    case 1:
    case 3:
        a = D_80109348_28B558_TorpedoTargets[gPlayers[0].character];
        b = D_80109360_28B570_TorpedoTargets[gPlayers[0].character];
        func_801040F0_286300_TorpedoTargets(obj, dir, a, b, team, 0);
        break;
    }
}

void func_80104464_286674_TorpedoTargets(omObjData* obj) {
    u32 group = gPlayers[1].group;
    s32 a = D_80109318_28B528_TorpedoTargets[gPlayers[1].character];
    s32 b = D_80109330_28B540_TorpedoTargets[gPlayers[1].character];
    s32 dir = 0x4A0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80103E40_286050_TorpedoTargets(obj, dir, a, b, team, 1);
        break;
    case 1:
    case 3:
        a = D_80109348_28B558_TorpedoTargets[gPlayers[1].character];
        b = D_80109360_28B570_TorpedoTargets[gPlayers[1].character];
        func_801040F0_286300_TorpedoTargets(obj, dir, a, b, team, 1);
        break;
    }
}

void func_80104524_286734_TorpedoTargets(omObjData* obj) {
    u32 group = gPlayers[2].group;
    s32 a = D_80109318_28B528_TorpedoTargets[gPlayers[2].character];
    s32 b = D_80109330_28B540_TorpedoTargets[gPlayers[2].character];
    s32 dir = 0x4A0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80103E40_286050_TorpedoTargets(obj, dir, a, b, team, 2);
        break;
    case 1:
    case 3:
        a = D_80109348_28B558_TorpedoTargets[gPlayers[2].character];
        b = D_80109360_28B570_TorpedoTargets[gPlayers[2].character];
        func_801040F0_286300_TorpedoTargets(obj, dir, a, b, team, 2);
        break;
    }
}

void func_801045E4_2867F4_TorpedoTargets(omObjData* obj) {
    u32 group = gPlayers[3].group;
    s32 a = D_80109318_28B528_TorpedoTargets[gPlayers[3].character];
    s32 b = D_80109330_28B540_TorpedoTargets[gPlayers[3].character];
    s32 dir = 0x4A0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80103E40_286050_TorpedoTargets(obj, dir, a, b, team, 3);
        break;
    case 1:
    case 3:
        a = D_80109348_28B558_TorpedoTargets[gPlayers[3].character];
        b = D_80109360_28B570_TorpedoTargets[gPlayers[3].character];
        func_801040F0_286300_TorpedoTargets(obj, dir, a, b, team, 3);
        break;
    }
}

void func_801046A4_2868B4_TorpedoTargets(f32 m[4][4], Vec* at, Vec* axis, f32 angle) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xy;
    f32 yz;
    f32 zx;
    f32 xx;
    f32 yy;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 a;

    func_800B8070_B8C70(angle, &s, &c);
    t = 1.0f - c;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    zx = z * x;
    xx = x * x;
    yy = y * y;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[0][0] = t * xx + c;
    a = t * xy;
    m[0][1] = a + zs;
    m[0][2] = t * zx - ys;
    m[1][0] = a - zs;
    m[1][1] = t * yy + c;
    m[1][2] = t * yz + xs;
}

void func_8010478C_28699C_TorpedoTargets(omObjData* obj) {
    Vec eye;
    Vec at;
    Vec3f up;
    f32 m[4][4];
    Vec3f dir;
    u8 i;

    for (i = 0; i < obj->work[0]; i++) {
        f32 rx = D_80102770_103370[i].x;
        f32 ry = D_80102770_103370[i].y;
        f32 d;

        eye.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        eye.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        eye.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        d = func_800B1830_B2430(eye.x * eye.x + eye.z * eye.z) - 3700.0f;
        if (d > 0.0f) {
            omObjData* sub;
            f32 a;
            f32 dx;
            f32 dz;

            a = d / 23247.768f * 360.0f;
            a += func_800B75A8_B81A8(eye.x, eye.z);
            eye.x = HuMathSin(a) * 3700.0f;
            eye.z = func_800B7890_B8490(a) * 3700.0f;
            sub = D_80109264_28B474_TorpedoTargets[i];
            dx = sub->trans.x - eye.x;
            dz = sub->trans.z - eye.z;
            d = 450.0f - func_800B1830_B2430(dx * dx + dz * dz);
            if (d > 0.0f) {
                eye.y += d;
            }
        }
        D_801092D8_28B4E8_TorpedoTargets[i].x = eye.x;
        D_801092D8_28B4E8_TorpedoTargets[i].y = eye.y;
        D_801092D8_28B4E8_TorpedoTargets[i].z = eye.z;
        dir.x = at.x - eye.x;
        dir.y = at.y - eye.y;
        dir.z = at.z - eye.z;
        func_8002D9AC_2E5AC(&dir);
        func_801046A4_2868B4_TorpedoTargets(m, &at, (Vec*)&dir, D_801092C4_28B4D4_TorpedoTargets[i]);
        up.x = m[1][0];
        up.y = m[1][1];
        up.z = m[1][2];
        func_8002D9AC_2E5AC(&up);
        D_800FC8F8_FD4F8[i][1] = eye.x;
        D_800FC8F8_FD4F8[i][2] = eye.z;
        D_800FC8F8_FD4F8[i][0] = func_800B75A8_B81A8(eye.x - D_801013B0_101FB0[i].x, eye.z - D_801013B0_101FB0[i].z);
        D_800FC8F8_FD4F8[i][3] = 50.0f;
        D_800FC8F8_FD4F8[i][4] = 19000.0f;
        D_800FC8F8_FD4F8[i][5] = 2600.0f;
        Hu3DCamSetPositionOrientation(i, &eye, &at, (Vec*)&up);
        Hu3DCamUpdateMtx(i);
    }
}

/* Logic right; float register choice in the yaw arms. */
#ifdef NON_MATCHING
void func_80104B9C_286DAC_TorpedoTargets(omObjData* obj, f32 yawD, f32 yaw, f32 pitchD, f32 pitch) {
    TTSub* w = obj->unk_50;
    s32 team = w->team;
    f32 lim;

    if (yawD != 0.0f) {
        D_80102770_103370[team].y = yawD * 0.4f + D_80102770_103370[team].y;
    } else {
        f32 d = w->yaw + 181.0f;

        d -= D_80102770_103370[team].y;
        d /= 100.0f;
        D_80102770_103370[team].y = d + D_80102770_103370[team].y;
    }
    lim = w->yaw + 180.0f + 20.0f;
    if (lim < D_80102770_103370[team].y) {
        D_80102770_103370[team].y = lim;
    }
    lim = w->yaw + 180.0f - 20.0f;
    if (D_80102770_103370[team].y < lim) {
        D_80102770_103370[team].y = lim;
    }
    if (pitchD != 0.0f) {
        D_80102770_103370[team].x -= pitchD * 0.3f;
    } else {
        D_80102770_103370[team].x -= (D_80102770_103370[team].x - -5.0f) / 100.0f;
    }
    if (D_80102770_103370[team].x > 20.0f) {
        D_80102770_103370[team].x = 20.0f;
    }
    if (D_80102770_103370[team].x < -30.0f) {
        D_80102770_103370[team].x = -30.0f;
    }
    D_801013B0_101FB0[team].x = obj->trans.x;
    D_801013B0_101FB0[team].y = obj->trans.y - (2.0f * D_80102770_103370[team].x - 20.0f);
    D_801013B0_101FB0[team].z = obj->trans.z;
    D_800F94A8_FA0A8[team] = w->speed * 5.0f + w->camDist;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80104B9C_286DAC_TorpedoTargets);
#endif

void func_80104EB0_2870C0_TorpedoTargets(omObjData* obj) {
    MgWork* m;
    omObjData* sub;
    TTSub* w;
    s32 other;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 mask0;
    s32 mask1;

    mask1 = 0;
    m = obj->unk_50;
    sub = D_80109264_28B474_TorpedoTargets[(gPlayers[m->unk_59].group >> 1) & 1];
    w = sub->unk_50;
    w->stickX = ContStkX[m->unk_57];
    w->stickY = ContStkY[m->unk_57];
    w->btn = ContBtn[m->unk_57];
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, w->tilt, -w->roll);
    obj->trans.x = sub->trans.x;
    obj->trans.y = sub->trans.y;
    obj->trans.z = sub->trans.z;
    obj->rot.x = sub->rot.x;
    obj->rot.y = sub->rot.y;
    obj->rot.z = sub->rot.z;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    other = w->team == 0;
    dx = D_801092D8_28B4E8_TorpedoTargets[other].x - obj->trans.x;
    dy = D_801092D8_28B4E8_TorpedoTargets[other].y - obj->trans.y;
    dz = D_801092D8_28B4E8_TorpedoTargets[other].z - obj->trans.z;
    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 2300.0f) {
        mask0 = (1 << w->team) | (1 << other);
    } else {
        mask0 = 1 << w->team;
        mask1 = 1 << other;
    }
    func_80029EDC_2AADC(obj->model[0], mask0);
    func_80029EDC_2AADC(obj->model[1], mask1);
}

void func_80105124_287334_TorpedoTargets(omObjData* obj) {
    MgWork* m;
    omObjData* sub;
    TTSub* w;
    s32 other;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 mask0;
    s32 mask1;

    mask1 = 0;
    m = obj->unk_50;
    sub = D_80109264_28B474_TorpedoTargets[(gPlayers[m->unk_59].group >> 1) & 1];
    w = sub->unk_50;
    w->gStickX = ContStkX[m->unk_57];
    w->gStickY = ContStkY[m->unk_57];
    w->gBtn = ContBtnTrg[m->unk_57];
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, w->tilt, -w->roll);
    obj->trans.x = sub->trans.x;
    obj->trans.y = sub->trans.y;
    obj->trans.z = sub->trans.z;
    obj->rot.x = sub->rot.x;
    obj->rot.y = sub->rot.y;
    obj->rot.z = sub->rot.z;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    other = w->team == 0;
    dx = D_801092D8_28B4E8_TorpedoTargets[other].x - obj->trans.x;
    dy = D_801092D8_28B4E8_TorpedoTargets[other].y - obj->trans.y;
    dz = D_801092D8_28B4E8_TorpedoTargets[other].z - obj->trans.z;
    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 2300.0f) {
        mask0 = (1 << w->team) | (1 << other);
    } else {
        mask0 = 1 << w->team;
        mask1 = 1 << other;
    }
    func_80029EDC_2AADC(obj->model[0], mask0);
    func_80029EDC_2AADC(obj->model[1], mask1);
}

void func_80105398_2875A8_TorpedoTargets(f32 x, f32 y, f32 z, f32 d) {
    Vec3f v;

    v.x = x;
    v.y = y;
    v.z = z;
    func_8002D9AC_2E5AC(&v);
    D_8010941C_28B62C_TorpedoTargets += d * v.x;
    D_8010941C_28B62C_TorpedoTargets += d * v.y; /* sic: never pushes y */
    D_80109424_28B634_TorpedoTargets += d * v.z;
}

f32 func_80105418_287628_TorpedoTargets(f32 r, f32 x, f32 y, f32 z) {
    f32 probe[3];
    ColVtx* verts;
    ColTri* tri;
    f32 h;
    f32 t;

    probe[0] = x;
    probe[1] = y - r;
    probe[2] = z;
    verts = D_800FC834_FD434[D_80109418_28B628_TorpedoTargets].hmf->unk54;
    func_8002F2C4_2FEC4(D_80109418_28B628_TorpedoTargets, D_800F9D30_FA930, func_80005110_5D10, probe);
    goto next;
loop:
    h = func_8002DBA4_2E7A4(x, y, z, verts, tri);
    t = y - r;
    if (t < h) {
        D_80109420_28B630_TorpedoTargets += h - t;
        return h;
    }
next:
    tri = func_8002F848_30448(D_800F9D30_FA930);
    if (tri != NULL) {
        goto loop;
    }
    return h;
}

void func_8010552C_28773C_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z) {
    f32 d = func_800B1830_B2430(x * x + z * z);

    if (d > 3850.0f) {
        func_80105398_2875A8_TorpedoTargets(x, 0.0f, z, -(d - 3850.0f));
    }
    func_80105418_287628_TorpedoTargets(150.0f, x + D_8010941C_28B62C_TorpedoTargets, y + D_80109420_28B630_TorpedoTargets,
                                        z + D_80109424_28B634_TorpedoTargets);
}

void func_801055F4_287804_TorpedoTargets(f32 r, f32 x, f32 y, f32 z) {
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 dx = D_80109284_28B494_TorpedoTargets[i].x - x;
        f32 dy = D_80109284_28B494_TorpedoTargets[i].y - 100.0f - y;
        f32 dz = D_80109284_28B494_TorpedoTargets[i].z - z;
        f32 d;

        if (dy > 0.0f) {
            d = func_800B1830_B2430(dx * dx + dz * dz);
            if (d < r + 200.0f) {
                func_80105398_2875A8_TorpedoTargets(dx, 0.0f, dz, d - (r + 200.0f));
                return;
            }
        } else {
            d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (d < r + 200.0f) {
                func_80105398_2875A8_TorpedoTargets(dx, dy, dz, d - (r + 200.0f));
                return;
            }
        }
    }
}

/* The deltas reuse the parameters (S3-Q02: separate dx/dy/dz locals swapped f20 and f24). */
void func_8010578C_28799C_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z) {
    TTSub* w = obj->unk_50;
    s32 other = w->team == 0;
    omObjData* sub = D_80109264_28B474_TorpedoTargets[other];
    f32 d;

    x = sub->trans.x - x;
    y = sub->trans.y - y;
    z = sub->trans.z - z;
    d = func_800B1830_B2430(x * x + y * y + z * z);

    if (d < 300.0f) {
        func_80105398_2875A8_TorpedoTargets(x, y, z, d - 300.0f);
        if (w->bump == 0 && D_800F8FD0_F9BD0 == 1) {
            omVibrate(w->pilot, 0xA, 0, 0xA);
            omVibrate(w->gunner, 0xA, 0, 0xA);
            w->bump = 0x14;
        }
    }
}

void func_801058A8_287AB8_TorpedoTargets(omObjData* obj, f32 x, f32 y, f32 z) {
    TTSub* w = obj->unk_50;
    s32 i;

    D_8010941C_28B62C_TorpedoTargets = D_80109420_28B630_TorpedoTargets = D_80109424_28B634_TorpedoTargets = 0.0f;
    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            func_8010578C_28799C_TorpedoTargets(obj, x + D_8010941C_28B62C_TorpedoTargets, y + D_80109420_28B630_TorpedoTargets,
                                                z + D_80109424_28B634_TorpedoTargets);
            break;
        case 1:
            func_801055F4_287804_TorpedoTargets(150.0f, x + D_8010941C_28B62C_TorpedoTargets, y + D_80109420_28B630_TorpedoTargets,
                                                z + D_80109424_28B634_TorpedoTargets);
            break;
        case 2:
            func_8010552C_28773C_TorpedoTargets(obj, x + D_8010941C_28B62C_TorpedoTargets, y + D_80109420_28B630_TorpedoTargets,
                                                z + D_80109424_28B634_TorpedoTargets);
            break;
        }
    }
    if (w->bump != 0) {
        w->bump--;
    }
}

s32 func_80105A54_287C64_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;
    omObjData* sub;
    s32 other;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    D_8010941C_28B62C_TorpedoTargets = D_80109420_28B630_TorpedoTargets = D_80109424_28B634_TorpedoTargets = 0.0f;
    x = D_8010926C_28B47C_TorpedoTargets[w->team].x;
    y = D_8010926C_28B47C_TorpedoTargets[w->team].y;
    z = D_8010926C_28B47C_TorpedoTargets[w->team].z;
    other = w->team == 0;
    sub = D_80109264_28B474_TorpedoTargets[other];
    dx = sub->trans.x - x;
    dy = sub->trans.y - y;
    dz = sub->trans.z - z;
    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 230.0f) {
        return 2;
    }
    if (func_800B1830_B2430(x * x + z * z) > 3920.0f) {
        return 1;
    }
    func_80105418_287628_TorpedoTargets(80.0f, x, y, z);
    func_801055F4_287804_TorpedoTargets(80.0f, x, y, z);
    if (D_8010941C_28B62C_TorpedoTargets != 0.0f || D_80109420_28B630_TorpedoTargets != 0.0f
        || D_80109424_28B634_TorpedoTargets != 0.0f) {
        return 1;
    }
    dx = D_801093B8_28B5C8_TorpedoTargets.x - x;
    dy = D_801093B8_28B5C8_TorpedoTargets.y - y;
    dz = D_801093B8_28B5C8_TorpedoTargets.z - z;
    d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
    if (D_801092B4_28B4C4_TorpedoTargets != 1) {
        return 0;
    }
    if (d < 280.0f) {
        if (D_800F8FD0_F9BD0 == D_801092B4_28B4C4_TorpedoTargets) {
            D_801092BC_28B4CC_TorpedoTargets[w->team]++;
            w->score++;
            omVibrate(w->pilot, 2, 2, 0x14);
            omVibrate(w->gunner, 2, 2, 0x14);
            func_80107494_2896A4_TorpedoTargets(w->team, 1);
            D_801092D0_28B4E0_TorpedoTargets[w->team] = 1.0f;
        }
        return 3;
    }
    return 0;
}

void func_80105D0C_287F1C_TorpedoTargets(TTSub* w) {
    w->tPitch += w->gStickY * 0.005f;
    w->tYaw -= w->gStickX * 0.01f;
}

s32 func_80105D70_287F80_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;
    s32 hit;

    switch (D_801092B8_28B4C8_TorpedoTargets[w->team]) {
    case 0:
        if ((w->gBtn & 0x8000) && w->hit == 0) {
            func_800298A4_2A4A4(obj->model[6], 4, 0);
            func_800298A4_2A4A4(obj->model[3], 4, 0);
            func_800298A4_2A4A4(obj->model[4], 4, 4);
            func_80029E80_2AA80(obj->model[3], 4, 4);
            func_80029C74_2A874(obj->model[3], func_80029D0C_2A90C(obj->model[3]));
            D_801092B8_28B4C8_TorpedoTargets[w->team] = 1;
            func_800298A4_2A4A4(obj->model[7], 4, 0);
            D_801092C0_28B4D0_TorpedoTargets[w->team] = 0;
            w->tYaw = w->yaw;
            w->tPitch = obj->rot.x;
            w->tSpeed = 0.0f;
            w->tAccel = 1.0f;
            w->tSpin = 0.0f;
            w->tTrail = 0.0f;
            func_80029C74_2A874(obj->model[7], w->tTrail);
            D_800FC834_FD434[obj->model[7]].hmf->unk9C->unk08 = 0.0f;
            D_8010926C_28B47C_TorpedoTargets[w->team].x = obj->trans.x;
            D_8010926C_28B47C_TorpedoTargets[w->team].y = obj->trans.y - 122.5f;
            D_8010926C_28B47C_TorpedoTargets[w->team].z = obj->trans.z;
            func_80029714_2A314(obj->model[6], D_8010926C_28B47C_TorpedoTargets[w->team].x, D_8010926C_28B47C_TorpedoTargets[w->team].y,
                                D_8010926C_28B47C_TorpedoTargets[w->team].z);
            func_8002979C_2A39C(obj->model[6], w->tPitch, w->tYaw, 0.0f);
            func_80079798_7A398(0x308, w->gunner);
        }
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[7]].mtx, 0.0f, 0.0f, -w->roll);
        func_80029714_2A314(obj->model[7], D_8010926C_28B47C_TorpedoTargets[w->team].x, D_8010926C_28B47C_TorpedoTargets[w->team].y,
                            D_8010926C_28B47C_TorpedoTargets[w->team].z);
        func_8002979C_2A39C(obj->model[7], 0.0f, obj->rot.y, 0.0f);
        func_800298A4_2A4A4(obj->model[8], 4, 4);
        break;
    case 1:
        D_801092C0_28B4D0_TorpedoTargets[w->team]++;
        func_80105D0C_287F1C_TorpedoTargets(w);
        D_8010926C_28B47C_TorpedoTargets[w->team].x += HuMathSin(w->tYaw) * w->tSpeed;
        D_8010926C_28B47C_TorpedoTargets[w->team].y -= HuMathSin(w->tPitch) * w->tSpeed;
        D_8010926C_28B47C_TorpedoTargets[w->team].z += func_800B7890_B8490(w->tYaw) * w->tSpeed;
        hit = func_80105A54_287C64_TorpedoTargets(obj);
        if (hit != 0) {
            D_801092B8_28B4C8_TorpedoTargets[w->team] = -0x1E;
            func_80029C74_2A874(obj->model[4], 0.0f);
            func_80029C74_2A874(obj->model[8], 0.0f);
            func_800298A4_2A4A4(obj->model[8], 4, 0);
            func_80029714_2A314(obj->model[8], D_8010926C_28B47C_TorpedoTargets[w->team].x, D_8010926C_28B47C_TorpedoTargets[w->team].y,
                                D_8010926C_28B47C_TorpedoTargets[w->team].z);
            PlaySound(0x309);
            if (hit == 3 && D_800F8FD0_F9BD0 == 1) {
                func_80079798_7A398(gPlayers[w->pilot].character + 0x103, w->pilot);
                func_80079798_7A398(gPlayers[w->gunner].character + 0x103, w->gunner);
                PlaySound(0x30B);
            }
            if (hit == 2) {
                s32 other = w->team == 0;
                TTSub* o = D_80109264_28B474_TorpedoTargets[other]->unk_50;

                omVibrate(o->pilot, 2, 2, 0x14);
                omVibrate(o->gunner, 2, 2, 0x14);
                o->hit = 1;
                o->knock = 70.0f;
                o->knockRoll += 720.0f;
                if (D_801092B8_28B4C8_TorpedoTargets[other] == 0) {
                    D_801092B8_28B4C8_TorpedoTargets[other] = -0x1E;
                }
            } else if (hit == 3) {
                D_801092B4_28B4C4_TorpedoTargets = -0x1E;
            }
        }
        func_80029C74_2A874(obj->model[7], w->tTrail);
        func_80029714_2A314(obj->model[6], D_8010926C_28B47C_TorpedoTargets[w->team].x, D_8010926C_28B47C_TorpedoTargets[w->team].y,
                            D_8010926C_28B47C_TorpedoTargets[w->team].z);
        func_8002979C_2A39C(obj->model[6], w->tPitch, w->tYaw, 0.0f);
        func_80029714_2A314(obj->model[7], D_8010926C_28B47C_TorpedoTargets[w->team].x, D_8010926C_28B47C_TorpedoTargets[w->team].y,
                            D_8010926C_28B47C_TorpedoTargets[w->team].z);
        func_8002979C_2A39C(obj->model[7], w->tPitch, w->tYaw, 0.0f);
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[7]].mtx, 0.0f, 0.0f, -w->tSpin);
        w->tAccel *= 1.075f;
        w->tSpeed += w->tAccel;
        w->tSpin = func_8002D958_2E558(w->tAccel * 10.0f + w->tSpin);
        w->tTrail += 0.6f;
        if (w->tAccel > 20.0f) {
            w->tAccel = 20.0f;
        }
        if (w->tSpeed > 70.0f) {
            w->tSpeed = 70.0f;
        }
        if (w->tTrail > 30.0f) {
            w->tTrail = 30.0f;
        }
        break;
    default:
        func_800298A4_2A4A4(obj->model[6], 4, 4);
        func_800298A4_2A4A4(obj->model[3], 4, 4);
        func_800298A4_2A4A4(obj->model[4], 4, 0);
        func_800298A4_2A4A4(obj->model[7], 4, 4);
        func_80029C74_2A874(obj->model[7], 0.0f);
        D_8010926C_28B47C_TorpedoTargets[w->team].x = obj->trans.x;
        D_8010926C_28B47C_TorpedoTargets[w->team].y = obj->trans.y - (D_801092B8_28B4C8_TorpedoTargets[w->team] * 3 + 122.5f);
        D_8010926C_28B47C_TorpedoTargets[w->team].z = obj->trans.z;
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[7]].mtx, 0.0f, 0.0f, -w->roll);
        D_801092B8_28B4C8_TorpedoTargets[w->team]++;
        break;
    }
    return D_801092B8_28B4C8_TorpedoTargets[w->team];
}

f32 func_8010667C_28888C_TorpedoTargets(TTSub* w, f32 v) {
    f32 sum = 0.0f;
    u8 i;

    w->yawHist[w->yawPos++] = v;
    if (w->yawPos >= 20) {
        w->yawPos = 0;
    }
    for (i = 0; i < 20; i++) {
        sum += w->yawHist[i];
    }
    return sum / 20.0f;
}

f32 func_801066E4_2888F4_TorpedoTargets(TTSub* w, f32 v) {
    f32 sum = 0.0f;
    u8 i;

    w->pitchHist[w->pitchPos++] = v;
    if (w->pitchPos >= 20) {
        w->pitchPos = 0;
    }
    for (i = 0; i < 20; i++) {
        sum += w->pitchHist[i];
    }
    return sum / 20.0f;
}

void func_8010674C_28895C_TorpedoTargets(omObjData* obj, f32 in) {
    TTSub* w = obj->unk_50;
    f32 v = in * 10.0f;

    if (v > 10.0f) {
        v = 10.0f;
    }
    if (v < -10.0f) {
        v = -10.0f;
    }
    if (v != 0.0f) {
        w->roll += v * 0.05f;
        if (w->roll > 0.0f) {
            if (w->roll > v) {
                w->roll *= 0.9f;
            }
        } else if (w->roll < v) {
            w->roll *= 0.9f;
        }
    } else {
        w->roll *= 0.9f;
    }
    if ((u32)D_800F8FD0_F9BD0 < 2) {
        w->rudder = 10.0f - w->roll;
    }
    func_80029C74_2A874(obj->model[1], w->rudder);
}

void func_8010689C_288AAC_TorpedoTargets(omObjData* obj, f32 in) {
    TTSub* w = obj->unk_50;
    f32 v = in * 20.0f;

    if (v > 10.0f) {
        v = 10.0f;
    }
    if (v < -10.0f) {
        v = -10.0f;
    }
    if (v != 0.0f) {
        w->rudderV += v * 0.075f;
        if (w->rudderV > 0.0f) {
            if (w->rudderV > v) {
                w->rudderV *= 0.9f;
            }
        } else if (w->rudderV < v) {
            w->rudderV *= 0.9f;
        }
    } else {
        w->rudderV *= 0.9f;
    }
    func_80029C74_2A874(obj->model[2], 10.0f - w->rudderV);
}

void func_801069E4_288BF4_TorpedoTargets(omObjData* obj, f32 in) {
    TTSub* w = obj->unk_50;

    if (obj->trans.y > 1000.0f) {
        obj->trans.y = 1000.0f;
        w->pitch *= 0.9f;
    }
    if (obj->trans.y < -3000.0f) {
        obj->trans.y = -3000.0f;
        w->pitch *= 0.9f;
    }
    if (in == 0.0f) {
        w->pitch *= 0.95f;
    }
}

void func_80106AAC_288CBC_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;
    f32 v = w->speed;
    f32 s;
    f32 f;

    if (w->btn & 0x8000) {
        w->accel += 0.1f;
        if (w->accel > 5.0f) {
            w->accel = 5.0f;
        }
        w->prop += 0.02f;
        if (w->prop > 1.2f) {
            w->prop = 1.2f;
        }
    } else if (w->btn & 0x4000) {
        w->accel -= 0.1f;
        if (w->accel < -5.0f) {
            w->accel = -5.0f;
        }
        w->prop -= 0.02f;
        if (w->prop < -1.2f) {
            w->prop = -1.2f;
        }
    } else {
        w->accel *= 0.9f;
        w->prop *= 0.9f;
    }
    v = (v + w->accel) * 0.95f;
    if (v > 20.0f) {
        v = 20.0f;
    } else if (v < -20.0f) {
        v = -20.0f;
    }
    w->speed = v;
    if (w->accel > 0.5f) {
        func_80029E80_2AA80(obj->model[5], 2, 2);
    } else {
        func_80029E80_2AA80(obj->model[5], 2, 0);
    }
    if (w->prop > 0.0f) {
        func_80029E80_2AA80(obj->model[0], 6, 2);
    } else {
        func_80029E80_2AA80(obj->model[0], 6, 6);
    }
    s = 0.5f;
    if (w->accel > 1.5f) {
        f = func_80029CE4_2A8E4(obj->model[5]);
        if (f > 70.0f) {
            f += 30.0f;
            func_80029C74_2A874(obj->model[5], f - 70.0f);
        }
        s = w->accel * 0.5f;
        if (s < 0.5f) {
            s = 0.5f;
        }
    }
    func_80029FE4_2ABE4(obj->model[0], fabsf(w->prop));
    func_80029FE4_2ABE4(obj->model[5], s);
}

void func_80106DEC_288FFC_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;
    f32 x;
    f32 y;
    f32 sp;
    f32 dYaw;
    f32 dPitch;

    if (D_800F8FD0_F9BD0 == 1) {
        func_80107EDC_28A0EC_TorpedoTargets(obj);
        func_80108234_28A444_TorpedoTargets(obj);
    }
    x = -w->stickX / 64.0f;
    y = w->stickY / 120.0f;
    func_80106AAC_288CBC_TorpedoTargets(obj);
    sp = w->speed;
    if (w->hit == 1) {
        y = 0.0f;
        x = 0.0f;
        sp -= w->knock;
        w->knock -= 1.2f;
        w->knockRoll -= 14.4f;
        if (w->knockRoll < 0.0f) {
            w->knock = 0.0f;
            w->hit = 0;
            w->knockRoll = 0.0f;
        }
    }
    func_8010674C_28895C_TorpedoTargets(obj, x);
    dYaw = func_8010667C_28888C_TorpedoTargets(w, x);
    w->yaw += dYaw;
    D_801092C4_28B4D4_TorpedoTargets[w->team] = dYaw * 5.0f * w->speed * -0.025f;
    func_8010689C_288AAC_TorpedoTargets(obj, y);
    dPitch = func_801066E4_2888F4_TorpedoTargets(w, y);
    w->pitch += dPitch;
    if (w->pitch > 20.0f) {
        w->pitch = 20.0f;
    }
    if (w->pitch < -15.0f) {
        w->pitch = -15.0f;
    }
    func_801069E4_288BF4_TorpedoTargets(obj, y);
    obj->trans.x += HuMathSin(w->yaw) * sp;
    obj->trans.z += func_800B7890_B8490(w->yaw) * sp;
    obj->trans.y -= w->pitch * 0.75f;
    func_801058A8_287AB8_TorpedoTargets(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    obj->trans.x += D_8010941C_28B62C_TorpedoTargets;
    obj->trans.y += D_80109420_28B630_TorpedoTargets;
    obj->trans.z += D_80109424_28B634_TorpedoTargets;
    obj->rot.y = w->yaw;
    obj->rot.x = w->pitch + w->knockRoll;
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[2]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[3]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[4]].mtx, 0.0f, w->tilt, -w->roll);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[5]].mtx, 0.0f, w->tilt, -w->roll);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[3], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80105D70_287F80_TorpedoTargets(obj);
    func_80104B9C_286DAC_TorpedoTargets(obj, dYaw, w->yaw, dPitch, w->pitch);
}

void func_80107368_289578_TorpedoTargets(void) {
    void* data;

    data = DataRead(0x43);
    D_8010944E_28B65E_TorpedoTargets[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x43);
    D_8010944E_28B65E_TorpedoTargets[1] = SprAnimRead(data);
    DataClose(data);
    D_8010943C_28B64C_TorpedoTargets = func_8001A2F8_1AEF8(0x4A000D);
    D_8010943E_28B64E_TorpedoTargets = func_8001A2F8_1AEF8(0x4A000E);
    D_80109444_28B654_TorpedoTargets = func_8001A2F8_1AEF8(0x4A000F);
}

void func_80107410_289620_TorpedoTargets(s32 i, s16 x, s16 y) {
    D_80109446_28B656_TorpedoTargets[i] = func_8001AAAC_1B6AC(D_80109444_28B654_TorpedoTargets, 0, 1);
    espPosSet(D_80109446_28B656_TorpedoTargets[i], x, y);
    func_8001A788_1B388(D_80109446_28B656_TorpedoTargets[i], 6);
}

void func_80107494_2896A4_TorpedoTargets(s16 i, s32 on) {
    if (on != 0) {
        D_80109378_28B588_TorpedoTargets[i] = 1;
        return;
    }
    if (D_80109378_28B588_TorpedoTargets[i] != 0) {
        espDispOn(D_80109446_28B656_TorpedoTargets[i]);
        func_8001A6BC_1B2BC(D_80109446_28B656_TorpedoTargets[i], (D_80109378_28B588_TorpedoTargets[i] * 25) & 0xFF);
        if (++D_80109378_28B588_TorpedoTargets[i] >= 0x33) {
            D_80109378_28B588_TorpedoTargets[i] = 0;
        }
    } else {
        espDispOff(D_80109446_28B656_TorpedoTargets[i]);
        D_80109378_28B588_TorpedoTargets[i] = 0;
    }
}

s16 func_80107580_289790_TorpedoTargets(s32 i, s32 x, s16 y) {
    s16 g;

    D_80109438_28B648_TorpedoTargets[i] = func_8001AAAC_1B6AC(D_8010943C_28B64C_TorpedoTargets, 0, 1);
    espPosSet(D_80109438_28B648_TorpedoTargets[i], x, y);
    func_8001A788_1B388(D_80109438_28B648_TorpedoTargets[i], 6);
    D_80109440_28B650_TorpedoTargets[i] = func_8001AAAC_1B6AC(D_8010943E_28B64E_TorpedoTargets, 0, 1);
    espPosSet(D_80109440_28B650_TorpedoTargets[i], x + 0xE, y);
    func_8001A788_1B388(D_80109440_28B650_TorpedoTargets[i], 6);
    x += 0x18;
    D_8010944A_28B65A_TorpedoTargets[i] = g = SprCreate(2, 5);
    SprAnimSet(g, 0, D_8010944E_28B65E_TorpedoTargets[i], 0);
    SprAttrReset(g, 0, 0xFFFF);
    SprAttrSet(g, 0, 0x8000);
    SprPosSet(g, 0, x, y);
    SprPrioSet(g, 0, 6);
    SprPrioSet(g, 1, 6);
    SprAnimSet(g, 1, D_8010944E_28B65E_TorpedoTargets[i], 0);
    SprPosSet(g, 1, 0xA, 0);
    SprAttrReset(g, 1, 0xFFFF);
    SprAttrSet(g, 1, 0x8000);
    func_800824F4_830F4(g, 1, 0);
    SprAttrReset(g, 1, 0x8000);
    return g;
}

void func_80107764_289974_TorpedoTargets(s16 i, s32 n) {
    f32 scale = 1.0f;
    u16 g = D_8010944A_28B65A_TorpedoTargets[i];
    s32 q;

    espDispOn(D_80109438_28B648_TorpedoTargets[i]);
    if (D_801092D0_28B4E0_TorpedoTargets[i] != 0.0f) {
        scale = HuMathSin(D_801092D0_28B4E0_TorpedoTargets[i]) * 0.8f + 1.0f;
        D_801092D0_28B4E0_TorpedoTargets[i] += 12.0f;
        if (D_801092D0_28B4E0_TorpedoTargets[i] > 180.0f) {
            D_801092D0_28B4E0_TorpedoTargets[i] = 0.0f;
        }
    }
    func_8001A91C_1B51C(D_80109438_28B648_TorpedoTargets[i], scale, scale);
    q = (s16)n;
    if (q >= 10) {
        SprAttrReset(g, 0, 0x8000);
        q = q / 10;
        func_800822A8_82EA8(g, 0, q, 0);
        func_8008225C_82E5C(g, 0, 1);
        n -= (s16)q * 10;
        SprAttrReset(g, 1, 0x8000);
        func_800822A8_82EA8(g, 1, n, 0);
        func_8008225C_82E5C(g, 1, 1);
    } else {
        SprAttrReset(g, 0, 0x8000);
        func_800822A8_82EA8(g, 0, n, 0);
        func_8008225C_82E5C(g, 0, 1);
        SprAttrSet(g, 1, 0x8000);
    }
}
