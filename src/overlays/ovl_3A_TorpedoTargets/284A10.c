#include "ovl_3A.h"

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
    xy = t * xy;
    m[0][1] = xy + zs;
    m[0][2] = t * zx - ys;
    m[1][0] = xy - zs;
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80105398_2875A8_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80105418_287628_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_8010552C_28773C_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_801055F4_287804_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_8010578C_28799C_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_801058A8_287AB8_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80105A54_287C64_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80105D0C_287F1C_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80105D70_287F80_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_8010667C_28888C_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_801066E4_2888F4_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_8010674C_28895C_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_8010689C_288AAC_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_801069E4_288BF4_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80106AAC_288CBC_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80106DEC_288FFC_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80107368_289578_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80107410_289620_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80107494_2896A4_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80107580_289790_TorpedoTargets);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/284A10", func_80107764_289974_TorpedoTargets);
