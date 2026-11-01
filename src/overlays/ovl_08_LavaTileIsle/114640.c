#include "ovl_08.h"

void func_801031C0_114640_LavaTileIsle(void) {
    D_8010A4C0_11B940_LavaTileIsle = func_80018A30_19630(0x180000, 0x8BD);
    D_8010A4C2_11B942_LavaTileIsle = func_80018A30_19630(0x180001, 0x8BD);
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 8, 0, -1, func_80103300_114780_LavaTileIsle);
    omSetStatBit(D_800FC7B0_FD3B0[0], 0xA0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 1, 0, -1, func_80103790_114C10_LavaTileIsle);
    D_8010A614_11BA94_LavaTileIsle = omAddObj(3, 3, 0, -1, func_8010385C_114CDC_LavaTileIsle);
    D_8010A610_11BA90_LavaTileIsle = omAddObj(3, 4, 0, -1, func_801039A4_114E24_LavaTileIsle);
}

void func_80103300_114780_LavaTileIsle(omObjData* obj) {
    GroundWork* w;
    s32 i;

    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_08 = 0.5f;
    w->unk_04 = 0;
    w->unk_0C = 10.0f;
    obj->func_ptr = func_801036B4_114B34_LavaTileIsle;
    obj->trans.x = 0.0f;
    obj->trans.y = -600.0f;
    obj->trans.z = -500.0f;
    D_8010A4D0_11B950_LavaTileIsle = obj->model[0] = func_80018A30_19630(0x3A000C, 0xB9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0, 0);
    func_8002D2B4_2DEB4(obj->model[0], -96.0f, -17.0f, 69.0f);
    func_8002A00C_2AC0C(D_8010A4D0_11B950_LavaTileIsle);
    func_8003EAF0_3F6F0("152_yougan1_DEF", D_8010A4C4_11B944_LavaTileIsle);
    func_8003EAF0_3F6F0("152_yougan2_IA44", D_8010A4C8_11B948_LavaTileIsle);
    D_8010A4CC_11B94C_LavaTileIsle = 0.0f;
    for (i = 1; i < 8; i++) {
        obj->model[i] = func_80027D3C_2893C(D_8010A4C0_11B940_LavaTileIsle);
        func_800298A4_2A4A4(obj->model[i], 4, 0);
        func_8002D1EC_2DDEC(obj->model[i], 1);
        func_8002D274_2DE74(obj->model[i], 0xFF, 0, 0);
        func_8002D2B4_2DEB4(obj->model[i], -10.0f, -17.0f, 69.0f);
    }
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], -750.0f, obj->trans.y, -1200.0f);
    func_80029714_2A314(obj->model[2], 750.0f, obj->trans.y, -1200.0f);
    func_8002979C_2A39C(obj->model[2], 0.0f, 180.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[2], 1.3f, 1.0f, 1.0f);
    func_80029714_2A314(obj->model[3], -700.0f, obj->trans.y, -900.0f);
    func_8002979C_2A39C(obj->model[3], 0.0f, 90.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[3], 0.5f, 0.5f, 0.7f);
    func_80029714_2A314(obj->model[4], 650.0f, obj->trans.y, -500.0f);
    func_8002979C_2A39C(obj->model[4], 0.0f, -90.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[4], 0.4f, 0.2f, 0.4f);
    func_80029714_2A314(obj->model[5], 0.0f, obj->trans.y, -1300.0f);
    func_800297E8_2A3E8(obj->model[5], 1.7f, 0.7f, 0.7f);
    func_80029714_2A314(obj->model[6], -700.0f, obj->trans.y, -300.0f);
    func_800297E8_2A3E8(obj->model[6], 0.5f, 0.5f, 0.8f);
    func_80029714_2A314(obj->model[7], 700.0f, obj->trans.y, -300.0f);
    func_800297E8_2A3E8(obj->model[7], 0.5f, 0.5f, 0.5f);
    func_8000BEF8_CAF8(obj, 2, -600.0f);
}

void func_801036B4_114B34_LavaTileIsle(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_8010A4CC_11B94C_LavaTileIsle += 0.1f;
    }
    func_8002BED4_2CAD4(D_8010A4D0_11B950_LavaTileIsle, 0.0f, D_8010A4CC_11B94C_LavaTileIsle, D_8010A4C4_11B944_LavaTileIsle[0], D_8010A4C4_11B944_LavaTileIsle[1], "152_02map-grid6_1", 0);
    func_8002BED4_2CAD4(D_8010A4D0_11B950_LavaTileIsle, 0.0f, -D_8010A4CC_11B94C_LavaTileIsle, D_8010A4C8_11B948_LavaTileIsle[0], D_8010A4C8_11B948_LavaTileIsle[1], "152_02map-grid6_1_1", 0);
}

void func_80103790_114C10_LavaTileIsle(omObjData* obj) {
    GroundWork* w;

    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = 1;
    w->unk_08 = 0.5f;
    w->unk_0C = 10.0f;
    obj->model[0] = -1;
    obj->func_ptr = func_80102BD0_114050_LavaTileIsle;
    func_8000BF54_CB54(obj, 0.0f, 200.0f, -360.0f, -360.0f, 360.0f, 360.0f);
}

void func_8010385C_114CDC_LavaTileIsle(omObjData* obj) {
    GroundWork* w;
    s32 i;

    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_08 = 0.5f;
    w->unk_04 = 2;
    w->unk_0C = 10.0f;
    for (i = 0; i < 3; i++) {
        obj->model[i] = func_80027D3C_2893C(D_8010A4C2_11B942_LavaTileIsle);
        func_800298A4_2A4A4(obj->model[i], 4, 0);
    }
    obj->func_ptr = func_80103B04_114F84_LavaTileIsle;
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->trans.x = D_8010A580_11BA00_LavaTileIsle[0].x;
    obj->trans.y = D_8010A580_11BA00_LavaTileIsle[0].y;
    obj->trans.z = D_8010A580_11BA00_LavaTileIsle[0].z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], D_8010A580_11BA00_LavaTileIsle[1].x, D_8010A580_11BA00_LavaTileIsle[1].y, D_8010A580_11BA00_LavaTileIsle[1].z);
    func_80029714_2A314(obj->model[2], D_8010A580_11BA00_LavaTileIsle[2].x, D_8010A580_11BA00_LavaTileIsle[2].y, D_8010A580_11BA00_LavaTileIsle[2].z);
}

void func_801039A4_114E24_LavaTileIsle(omObjData* obj) {
    GroundWork* w;
    s32 i;

    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_08 = 0.5f;
    w->unk_04 = 3;
    w->unk_0C = 10.0f;
    for (i = 0; i < 4; i++) {
        obj->model[i] = func_80027D3C_2893C(D_8010A4C2_11B942_LavaTileIsle);
        func_800298A4_2A4A4(obj->model[i], 4, 0);
    }
    obj->func_ptr = func_80104154_1155D4_LavaTileIsle;
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->trans.x = D_8010A500_11B980_LavaTileIsle[0].x;
    obj->trans.y = D_8010A500_11B980_LavaTileIsle[0].y;
    obj->trans.z = D_8010A500_11B980_LavaTileIsle[0].z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], D_8010A500_11B980_LavaTileIsle[1].x, D_8010A500_11B980_LavaTileIsle[1].y, D_8010A500_11B980_LavaTileIsle[1].z);
    func_80029714_2A314(obj->model[2], D_8010A500_11B980_LavaTileIsle[2].x, D_8010A500_11B980_LavaTileIsle[2].y, D_8010A500_11B980_LavaTileIsle[2].z);
    func_80029714_2A314(obj->model[3], D_8010A500_11B980_LavaTileIsle[3].x, D_8010A500_11B980_LavaTileIsle[3].y, D_8010A500_11B980_LavaTileIsle[3].z);
}

void func_80103B04_114F84_LavaTileIsle(omObjData* obj) {
    s32 i;

    switch (D_800F8FD0_F9BD0) {
    case 2:
        if (D_8010A1DC_11B65C_LavaTileIsle == 0) {
            func_80079848_7A448(D_8010A4AC_11B92C_LavaTileIsle);
            func_80079848_7A448(D_8010A4AE_11B92E_LavaTileIsle);
            func_80079848_7A448(D_8010A4B0_11B930_LavaTileIsle);
            D_8010A1DC_11B65C_LavaTileIsle = 1;
        }
        break;
    case 1:
        D_8010A1D4_11B654_LavaTileIsle++;
        D_8010A4A8_11B928_LavaTileIsle = (u16)(D_8010A1D4_11B654_LavaTileIsle / 300) + D_800BF7C8_C03C8;
        switch (obj->work[0]) {
        case 0:
            D_8010A4A0_11B920_LavaTileIsle = D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x;
            D_8010A4A4_11B924_LavaTileIsle = D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z;
            if (D_8010A1D4_11B654_LavaTileIsle > 30) {
                obj->work[0] = 1;
                D_8010A1D4_11B654_LavaTileIsle = 0;
            }
            break;
        case 1:
            if (D_8010A1D4_11B654_LavaTileIsle > 60) {
                obj->work[0] = 2;
                D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].y = -120.0f;
                D_8010A1D8_11B658_LavaTileIsle = 0.0f;
                D_8010A1D4_11B654_LavaTileIsle = 0;
                D_8010A4AC_11B92C_LavaTileIsle = PlaySound(0x14D);
            } else {
                if (D_8010A1D4_11B654_LavaTileIsle == 1) {
                    D_8010A4AE_11B92E_LavaTileIsle = PlaySound(0x14C);
                }
                D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].y += HuMathSin(D_8010A1D8_11B658_LavaTileIsle) * 10.0f;
                D_8010A1D8_11B658_LavaTileIsle += 45.0f;
            }
            break;
        case 2:
            switch (obj->work[2]) {
            case 0:
                if (D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z >= D_8010A4A4_11B924_LavaTileIsle + 240.0f) {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z = D_8010A4A4_11B924_LavaTileIsle + 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z += D_8010A4A8_11B928_LavaTileIsle;
                }
                break;
            case 1:
                if (D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x <= D_8010A4A0_11B920_LavaTileIsle - 240.0f) {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x = D_8010A4A0_11B920_LavaTileIsle - 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x -= D_8010A4A8_11B928_LavaTileIsle;
                }
                break;
            case 2:
                if (D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z <= D_8010A4A4_11B924_LavaTileIsle - 240.0f) {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z = D_8010A4A4_11B924_LavaTileIsle - 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].z -= D_8010A4A8_11B928_LavaTileIsle;
                }
                break;
            case 3:
                if (D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x >= D_8010A4A0_11B920_LavaTileIsle + 240.0f) {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x = D_8010A4A0_11B920_LavaTileIsle + 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].x += D_8010A4A8_11B928_LavaTileIsle;
                }
                break;
            }
            break;
        case 3:
            if (D_8010A1D4_11B654_LavaTileIsle > 30) {
                obj->work[0] = 4;
                D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].y = -120.0f;
                D_8010A1D8_11B658_LavaTileIsle = -120.0f;
                D_8010A1D4_11B654_LavaTileIsle = 0;
                D_8010A4B0_11B930_LavaTileIsle = PlaySound(0x14E);
            } else {
                D_8010A580_11BA00_LavaTileIsle[D_8010A60C_11BA8C_LavaTileIsle].y += HuMathSin(D_8010A1D8_11B658_LavaTileIsle) * 10.0f;
                D_8010A1D8_11B658_LavaTileIsle += 45.0f;
            }
            break;
        case 4:
            obj->work[2]++;
            if (obj->work[2] >= 4) {
                obj->work[2] = 0;
            }
            if (--D_8010A60C_11BA8C_LavaTileIsle < 0) {
                D_8010A60C_11BA8C_LavaTileIsle = 2;
            }
            obj->work[0] = 0;
            break;
        }
        if (obj->work[0] == 3) {
            if (obj->work[2] + 1 >= 4) {
                obj->work[1] = D_8010A1D0_11B650_LavaTileIsle[0];
            } else {
                obj->work[1] = D_8010A1D0_11B650_LavaTileIsle[obj->work[2] + 1];
            }
        } else {
            obj->work[1] = D_8010A1D0_11B650_LavaTileIsle[obj->work[2]];
        }
        obj->trans.x = D_8010A580_11BA00_LavaTileIsle[0].x;
        obj->trans.y = D_8010A580_11BA00_LavaTileIsle[0].y;
        obj->trans.z = D_8010A580_11BA00_LavaTileIsle[0].z;
        for (i = 0; i < 3; i++) {
            func_80029714_2A314(obj->model[i], D_8010A580_11BA00_LavaTileIsle[i].x, D_8010A580_11BA00_LavaTileIsle[i].y, D_8010A580_11BA00_LavaTileIsle[i].z);
        }
        break;
    }
}

void func_80104154_1155D4_LavaTileIsle(omObjData* obj) {
    s32 i;

    if (D_800F8FD0_F9BD0 == 1) {
        D_8010A1F0_11B670_LavaTileIsle++;
        D_8010A4BC_11B93C_LavaTileIsle = (u16)(D_8010A1F0_11B670_LavaTileIsle / 300) + D_800BF7C8_C03C8;
        D_8010A618_11BA98_LavaTileIsle = D_8010A1E0_11B660_LavaTileIsle[obj->work[2]];
        switch (obj->work[0]) {
        case 0:
            D_8010A4B4_11B934_LavaTileIsle = D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x;
            D_8010A4B8_11B938_LavaTileIsle = D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z;
            if (D_8010A1F0_11B670_LavaTileIsle > 30) {
                obj->work[0] = 1;
                D_8010A1F0_11B670_LavaTileIsle = 0;
            }
            break;
        case 1:
            if (D_8010A1F0_11B670_LavaTileIsle > 60) {
                obj->work[0] = 2;
                D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].y = -120.0f;
                D_8010A1F4_11B674_LavaTileIsle = 0.0f;
                D_8010A1F0_11B670_LavaTileIsle = 0;
            } else {
                D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].y += HuMathSin(D_8010A1F4_11B674_LavaTileIsle) * 10.0f;
                D_8010A1F4_11B674_LavaTileIsle += 45.0f;
            }
            break;
        case 2:
            switch (obj->work[2]) {
            case 0:
            case 7:
                if (D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z <= D_8010A4B8_11B938_LavaTileIsle - 240.0f) {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z = D_8010A4B8_11B938_LavaTileIsle - 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z -= D_8010A4BC_11B93C_LavaTileIsle;
                }
                break;
            case 1:
            case 2:
                if (D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x >= D_8010A4B4_11B934_LavaTileIsle + 240.0f) {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x = D_8010A4B4_11B934_LavaTileIsle + 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x += D_8010A4BC_11B93C_LavaTileIsle;
                }
                break;
            case 3:
            case 4:
                if (D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x <= D_8010A4B4_11B934_LavaTileIsle - 240.0f) {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x = D_8010A4B4_11B934_LavaTileIsle - 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].x -= D_8010A4BC_11B93C_LavaTileIsle;
                }
                break;
            case 5:
            case 6:
                if (D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z >= D_8010A4B8_11B938_LavaTileIsle + 240.0f) {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z = D_8010A4B8_11B938_LavaTileIsle + 240.0f;
                    obj->work[0] = 3;
                } else {
                    D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].z += D_8010A4BC_11B93C_LavaTileIsle;
                }
                break;
            }
            break;
        case 3:
            if (D_8010A1F0_11B670_LavaTileIsle > 30) {
                obj->work[0] = 4;
                D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].y = -120.0f;
                D_8010A1F4_11B674_LavaTileIsle = -120.0f;
                D_8010A1F0_11B670_LavaTileIsle = 0;
            } else {
                D_8010A500_11B980_LavaTileIsle[D_8010A618_11BA98_LavaTileIsle].y += HuMathSin(D_8010A1F4_11B674_LavaTileIsle) * 10.0f;
                D_8010A1F4_11B674_LavaTileIsle += 45.0f;
            }
            break;
        case 4:
            obj->work[2]++;
            if (obj->work[2] >= 8) {
                obj->work[2] = 0;
            }
            obj->work[0] = 0;
            break;
        }
        if (obj->work[0] == 3) {
            if (obj->work[2] + 1 >= 8) {
                obj->work[1] = D_8010A1E8_11B668_LavaTileIsle[0];
            } else {
                obj->work[1] = D_8010A1E8_11B668_LavaTileIsle[obj->work[2] + 1];
            }
        } else {
            obj->work[1] = D_8010A1E8_11B668_LavaTileIsle[obj->work[2]];
        }
        obj->trans.x = D_8010A500_11B980_LavaTileIsle[0].x;
        obj->trans.y = D_8010A500_11B980_LavaTileIsle[0].y;
        obj->trans.z = D_8010A500_11B980_LavaTileIsle[0].z;
        for (i = 0; i < 4; i++) {
            func_80029714_2A314(obj->model[i], D_8010A500_11B980_LavaTileIsle[i].x, D_8010A500_11B980_LavaTileIsle[i].y, D_8010A500_11B980_LavaTileIsle[i].z);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801046E0_115B60_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_8010479C_115C1C_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80104C94_116114_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801052A8_116728_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80105400_116880_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801057C0_116C40_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80105E34_1172B4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80105E80_117300_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80105F6C_1173EC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80106120_1175A0_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80106444_1178C4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801066D4_117B54_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801069D8_117E58_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80106F2C_1183AC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80107414_118894_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80107694_118B14_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80107B24_118FA4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80107E3C_1192BC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801081C4_119644_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80108204_119684_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80108388_119808_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80108494_119914_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80108648_119AC8_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_801095BC_11AA3C_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80109E5C_11B2DC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80109E70_11B2F0_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/114640", func_80109F44_11B3C4_LavaTileIsle);
