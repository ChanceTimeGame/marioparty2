#include "common.h"
#include "ovl_60.h"

void func_80102830_3BDF90_name_60(void) {
    s32 temp_s0;
    s32 i;

    func_80102A14_3BE174_name_60();
    if ((GwSystem.unk_25 == 1)) {
        func_801085A0_3C3D00_name_60(0);
        return;
    }

    switch (D_801148F2_3D0052_name_60) {
    case 6:
    case 7:
        func_801085A0_3C3D00_name_60(0);
        return;
    }

    PlayMusic(0x16);
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, &func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    temp_s0 = func_80018E78_19A78();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 10.0f, 500.0f, 5000.0f);
    D_800FA610_FB210 = 2500.0f;
    D_800FD474_FE074.x = 0;
    D_800FD474_FE074.y = 0;
    D_800FD474_FE074.z = 0;
    D_8010274C_10334C.x = 0;
    D_8010274C_10334C.y = 0;
    D_8010274C_10334C.z = 0;
    func_80102AF0_3BE250_name_60();
    omAddPrcObj(&func_80105B94_3C12F4_name_60, 0x1001U, 0x800, 0);
    
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }

    D_801148F4_3D0054_name_60 = D_80114AC2_3D0222_name_60 = i;
    InitFadeIn(0, 0x10);
}

void func_80102A14_3BE174_name_60(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x32, 0x14);
    func_80088640_89240();
    D_80102708_103308 = 1;
    D_800FC8A0_FD4A0 = 0;
    D_800F9910_FA510 = 0;
    D_8011497A_3D00DA_name_60 = 0;
    D_801148F0_3D0050_name_60 = D_80114AC4_3D0224_name_60 = GwSystem.chosenMinigameIndex - 1;
    D_801148F2_3D0052_name_60 = D_80114AC0_3D0220_name_60 = D_800CAD90[D_801148F0_3D0050_name_60].unk_04;
    if (_CheckFlag(0xC) != 0) {
        func_80113264_3CE9C4_name_60(D_801148F0_3D0050_name_60);
    } else {
        func_80108170_3C38D0_name_60();
        func_80108458_3C3BB8_name_60();
    }
}

#ifdef NON_MATCHING
void func_80102AF0_3BE250_name_60(void) {
    void* file;
    s32 j;
    s32 i;

    D_80114940_3D00A0_name_60 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0011), 0, 0);
    espPosSet(D_80114940_3D00A0_name_60, 160, 120);
    func_8001A708_1B308(D_80114940_3D00A0_name_60, 0x4000);
    func_8001A6BC_1B2BC(D_80114940_3D00A0_name_60, 0);
    D_801148F8_3D0058_name_60[0] = func_80018A30_19630(0xB000E, 0xA8D);
    func_8002D124_2DD24(D_801148F8_3D0058_name_60[0]);
    func_8002D0A0_2DCA0(D_801148F8_3D0058_name_60[0], 0x80);
    j = 0;
    func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[0]);
    switch (D_801148F2_3D0052_name_60) {
    case 3:
        j = 3;
        break;
    case 5:
        j = 4;
        break;
    case 4:
        j = 2;
        break;
    default:
        if (func_801050DC_3C083C_name_60(D_801148F0_3D0050_name_60) != 0) {
            j = 1;
        }
        break;
    }
    D_801148F8_3D0058_name_60[1] = func_80018A30_19630((u16)j | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_801148F8_3D0058_name_60[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_801148F8_3D0058_name_60[1]);
    func_8002A00C_2AC0C(D_801148F8_3D0058_name_60[1]);
    func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[1]);
    D_801148F8_3D0058_name_60[2] = func_80018A30_19630(((u16)j + 5) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_801148F8_3D0058_name_60[2], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_801148F8_3D0058_name_60[2]);
    func_8002A00C_2AC0C(D_801148F8_3D0058_name_60[2]);
    func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[2]);
    i = 0;
    D_80114948_3D00A8_name_60 = func_80018A30_19630(0xB000A, 0xA9D);
    func_80029E80_2AA80(D_80114948_3D00A8_name_60, 0, 2);
    switch (D_801148F2_3D0052_name_60) {
    case 3:
        i = 2;
        break;
    case 4:
        i = 1;
        break;
    }
    D_801148F8_3D0058_name_60[3] = func_80018A30_19630(((u16)i + 0xB) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_801148F8_3D0058_name_60[3], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_801148F8_3D0058_name_60[3]);
    func_8002A00C_2AC0C(D_801148F8_3D0058_name_60[3]);
    func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[3]);
    D_801148F8_3D0058_name_60[4] = func_80018A30_19630(0xB000B, 0xA8D);
    HmfModelObjAttrSet(D_801148F8_3D0058_name_60[4], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_801148F8_3D0058_name_60[4]);
    func_8002A00C_2AC0C(D_801148F8_3D0058_name_60[4]);
    func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[4]);
    if (D_801148F2_3D0052_name_60 < 3) {
        if (D_801148F2_3D0052_name_60 > 0) {
            if (D_801148F0_3D0050_name_60 != 0x21) {
                D_801148F8_3D0058_name_60[5] = func_80018A30_19630(0xB000B, 0xA8D);
                HmfModelObjAttrSet(D_801148F8_3D0058_name_60[5], 0x20000, 0x20000);
                func_80029A8C_2A68C(D_801148F8_3D0058_name_60[5]);
                func_8002A00C_2AC0C(D_801148F8_3D0058_name_60[5]);
                func_80029AFC_2A6FC(D_801148F8_3D0058_name_60[5]);
            }
        }
    }
    switch (D_801148F2_3D0052_name_60) {
    case 3:
        D_8011494E_3D00AE_name_60 = func_80018A30_19630(0x800A6, 0xAAD);
        D_80114950_3D00B0_name_60[0] = D_800FC834_FD434[D_8011494E_3D00AE_name_60].unk02;
        D_80114950_3D00B0_name_60[1] = func_8002C8B8_2D4B8(DataRead(0x800AA), 0x1D);
        D_80114950_3D00B0_name_60[2] = func_8002C8B8_2D4B8(DataRead(0x800AB), 0x1D);
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 2);
        func_800297E8_2A3E8(D_8011494E_3D00AE_name_60, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800AE);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_8011494E_3D00AE_name_60].hmf, file, 0, "c164m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_8011494E_3D00AE_name_60);
        func_80029AFC_2A6FC(D_8011494E_3D00AE_name_60);
        D_8011495C_3D00BC_name_60 = func_80018A30_19630(0xB0010, 0xA9D);
        func_8002979C_2A39C(D_8011495C_3D00BC_name_60, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(D_8011495C_3D00BC_name_60, 0.8f, 0.8f, 0.8f);
        func_801049F4_3C0154_name_60();
        break;
    case 4:
        D_8011494E_3D00AE_name_60 = func_80018A30_19630(0x800A3, 0xAAD);
        D_80114950_3D00B0_name_60[0] = D_800FC834_FD434[D_8011494E_3D00AE_name_60].unk02;
        D_80114950_3D00B0_name_60[1] = func_8002C8B8_2D4B8(DataRead(0x80093), 0x1D);
        D_80114950_3D00B0_name_60[2] = func_8002C8B8_2D4B8(DataRead(0x80091), 0x1D);
        D_80114950_3D00B0_name_60[3] = func_8002C8B8_2D4B8(DataRead(0x8008E), 0x1D);
        D_80114950_3D00B0_name_60[4] = func_8002C8B8_2D4B8(DataRead(0x800A1), 0x1D);
        func_8002C9C0_2D5C0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[1]);
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 2);
        func_800297E8_2A3E8(D_8011494E_3D00AE_name_60, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800A4);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_8011494E_3D00AE_name_60].hmf, file, 0, "c103m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_8011494E_3D00AE_name_60);
        func_80029AFC_2A6FC(D_8011494E_3D00AE_name_60);
        break;
    default:
        if (_CheckFlag(0xC) != 0) {
            D_8011494E_3D00AE_name_60 = func_80018A30_19630(0x80035, 0xAAD);
        } else {
            D_8011494E_3D00AE_name_60 = func_80018A30_19630(0x80000, 0xAAD);
        }
        D_80114950_3D00B0_name_60[0] = func_8002C8B8_2D4B8(DataRead(0x8002C), 0x1D);
        D_80114950_3D00B0_name_60[1] = func_8002C8B8_2D4B8(DataRead(0x8002D), 0x1D);
        D_80114950_3D00B0_name_60[2] = func_8002C8B8_2D4B8(DataRead(0x8002E), 0x1D);
        D_80114950_3D00B0_name_60[3] = func_8002C8B8_2D4B8(DataRead(0x8002F), 0x1D);
        func_8002C9C0_2D5C0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[0]);
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 2);
        func_800297E8_2A3E8(D_8011494E_3D00AE_name_60, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x80039);
        if (_CheckFlag(0xC) != 0) {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_8011494E_3D00AE_name_60].hmf, file, 0, "c180n_0_DEF");
        } else {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_8011494E_3D00AE_name_60].hmf, file, 0, "c160n_0_DEF");
        }
        DataClose(file);
        func_80029A8C_2A68C(D_8011494E_3D00AE_name_60);
        func_80029AFC_2A6FC(D_8011494E_3D00AE_name_60);
        if (func_801050DC_3C083C_name_60(D_801148F0_3D0050_name_60) != 0) {
            D_8011495C_3D00BC_name_60 = func_80018A30_19630(0xB0012, 0xA9D);
        }
        break;
    }
    D_8011495A_3D00BA_name_60 = func_80018A30_19630(0xB000F, 0xA8D);
    i = D_800CAD90[D_801148F0_3D0050_name_60].unk_06 & 0xFFF;
    if ((D_800CAD90[D_801148F0_3D0050_name_60].unk_06 >> 15) == 1) {
        i += D_800FA656 * 2;
    }
    D_8011497C_3D00DC_name_60 = DataRead((u16)i | 0xB0000);
    D_80114984_3D00E4_name_60 = DataRead(((u16)i + 1) | 0xB0000);
    D_80114980_3D00E0_name_60 = DataRead(0xB0024);
    func_801072C8_3C2A28_name_60(D_8011495A_3D00BA_name_60, D_80114984_3D00E4_name_60, D_8011497C_3D00DC_name_60, D_80114980_3D00E0_name_60);
    D_8011496C_3D00CC_name_60 = func_8008DFC4_8EBC4(0x48, 0xBC, 4);
    func_80089674_8A274(D_8011496C_3D00CC_name_60)->unk29 = 0;
    D_8011496E_3D00CE_name_60[0] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0013, 0x37, -0x28, 0);
    D_8011496E_3D00CE_name_60[1] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0017, 0x37, -0x28, 0);
    D_8011496E_3D00CE_name_60[2] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0021, 0x82, -0x28, 0);
    if (func_80105A14_3C1174_name_60() != 0) {
        D_8011496E_3D00CE_name_60[3] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0022, 0xBE, -0x28, 0);
    }
    D_80114942_3D00A2_name_60 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001D), 0, 1);
    espDispOff(D_80114942_3D00A2_name_60);
    D_80114944_3D00A4_name_60 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001E), 0, 1);
    func_8001A96C_1B56C(D_80114944_3D00A4_name_60, 0, 0, 0x80);
    espDispOff(D_80114944_3D00A4_name_60);
    D_80114946_3D00A6_name_60 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0021), 0, 1);
    espDispOff(D_80114946_3D00A6_name_60);
    D_8011494A_3D00AA_name_60 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900FA), 0, 1);
    espDispOff(D_8011494A_3D00AA_name_60);
    D_8011494C_3D00AC_name_60 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80102AF0_3BE250_name_60);
#endif

void func_8010352C_3BEC8C_name_60(omObjData* obj) {
    Ovl60FallWork* work = obj->unk_50;

    work->pos.x = HuMathSin(work->angle) * obj->work[2] + work->baseX;
    work->angle += work->angleVel;
    work->pos.y += work->vel;
    func_80029714_2A314((s16)work->model, work->pos.x, work->pos.y, work->pos.z);
    if (work->pos.y > work->floor) {
        work->pos.y = work->floor;
        if (obj->work[1] < 3) {
            func_800298A4_2A4A4((s16)work->model, 4, 4);
        }
        func_80029714_2A314((s16)work->model, work->pos.x, work->pos.y, work->pos.z);
        omDelObj(obj);
    }
}

void func_80103608_3BED68_name_60(omObjData* obj) {
    Ovl60FallWork* work = obj->unk_50;

    if (obj->work[0] == 0) {
        work->model = func_80027D3C_2893C(D_801148F8_3D0058_name_60[0]);
    } else {
        work->model = D_801148F8_3D0058_name_60[obj->work[0]];
    }
    func_80029E80_2AA80((s16)work->model, 0, 2);
    func_800298A4_2A4A4((s16)work->model, 4, 0);
    func_80029714_2A314((s16)work->model, work->pos.x, work->pos.y, work->pos.z);
    func_800297E8_2A3E8((s16)work->model, work->scale, work->scale, work->scale);
    work->angle = 0.0f;
    work->angleVel = 6.0f;
    switch (obj->work[1]) {
    case 0:
        work->vel = 10.0f;
        break;
    case 1:
        work->vel = 13.0f;
        break;
    case 2:
        work->vel = 15.0f;
        break;
    default:
        work->vel = (work->floor - work->pos.y) / 30.0f;
        break;
    }
    if (obj->work[3] != 0) {
        work->angleVel = -work->angleVel;
    }
    obj->func_ptr = func_8010352C_3BEC8C_name_60;
}

void func_80103778_3BEED8_name_60(omObjData* obj) {
    s16 model = obj->work[2];
    f32 t;

    switch (obj->work[0]) {
    case 0:
        t = obj->work[1] * 0.05f;
        func_8002AC10_2B810(model, t, t * 10.0f, 1);
        if (obj->work[1]++ > 20) {
            obj->work[0] = 1;
        }
        break;
    case 1:
        func_800298A4_2A4A4(model, 4, 4);
        omDelObj(obj);
        break;
    }
}

void func_8010382C_3BEF8C_name_60(omObjData* obj) {
    s32 alpha;

    alpha = (obj->work[0]++ * 255) / obj->work[1];
    if (obj->work[1] < obj->work[0]) {
        alpha = 255;
    }
    func_8001A6BC_1B2BC(D_80114940_3D00A0_name_60, alpha);
    if (alpha == 255) {
        omDelObj(obj);
    }
}

void func_801038D4_3BF034_name_60(omObjData* obj) {
    if ((u16)func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_80113518_3CEC78_name_60 += 0.3f;
    }
    if (D_80113518_3CEC78_name_60 > 48.0f) {
        D_80113518_3CEC78_name_60 = -48.0f;
    }
    func_8002BED4_2CAD4(D_801148F8_3D0058_name_60[1], D_80113518_3CEC78_name_60, 0.0f, 48, 40, "normal_title2-face3", 0);
}

void func_80103994_3BF0F4_name_60(omObjData* obj) {
    Ovl60HostWork* work = D_800FC890_FD490;
    HmfModel* model;
    Vec v;

    switch (obj->work[1]) {
    case 0:
        work->model = D_8011494E_3D00AE_name_60;
        model = &D_800FC834_FD434[(s16)work->model];
        work->pos.x = model->pos.x;
        work->pos.y = model->pos.y;
        work->pos.z = model->pos.z;
        work->rot.x = model->rot.x;
        work->rot.y = model->rot.y;
        work->rot.z = model->rot.z;
        HuVecCopyXYZ(&v, work->pos.x, 0.0f, work->pos.y);
        work->angle = func_800B75A8_B81A8(v.x, v.z);
        work->count = 7;
        work->step = (work->angle - work->rot.z) / 7.0f;
        obj->work[1] = 1;
        break;
    case 1:
        work->pos.x = HuMathSin(work->angle) * 20.0f + work->pos.x;
        work->pos.y = func_800B7890_B8490(work->angle) * 20.0f + work->pos.y;
        work->rot.y += 20.0f;
        if (work->count != 0) {
            work->count--;
            work->rot.z -= work->step;
        }
        if (work->pos.y < -700.0f) {
            func_800298A4_2A4A4(D_8011494E_3D00AE_name_60, 4, 4);
            omDelObj(obj);
        }
        break;
    }
    func_80029714_2A314(D_8011494E_3D00AE_name_60, work->pos.x, work->pos.y, work->pos.z);
    func_8002979C_2A39C(D_8011494E_3D00AE_name_60, work->rot.x, work->rot.y, work->rot.z);
}

void func_80103B78_3BF2D8_name_60(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[D_8011495C_3D00BC_name_60];
    Vec v;
    f32 angle;

    HuVecCopyXYZ(&v, model->pos.x, 0.0f, model->pos.y);
    angle = func_800B75A8_B81A8(v.x, v.z);
    func_80029714_2A314(D_8011495C_3D00BC_name_60, HuMathSin(angle) * 20.0f + model->pos.x,
                        func_800B7890_B8490(angle) * 20.0f + model->pos.y, model->pos.z);
    if (model->pos.y < -700.0f) {
        func_800298A4_2A4A4(D_8011495C_3D00BC_name_60, 4, 4);
        omDelObj(obj);
    }
}

#ifdef NON_MATCHING
void func_80103C84_3BF3E4_name_60(s16 win, s32 page) {
    s16 extra;
    s16 mes;
    s32 last;
    s32 i;
    s32 n;

    extra = D_801132B0_3CEA10_name_60[D_801148F0_3D0050_name_60][2];
    if (extra == -1 || _CheckFlag(0xC) != 0) {
        last = 2;
    } else {
        last = 3;
    }
    if (D_800FA656 != 0 && last == page) {
        switch (D_801148F0_3D0050_name_60 + 1) {
        case 42:
            D_801148F6_3D0056_name_60 = D_800FA656 + 0x47;
            break;
        case 46:
            D_801148F6_3D0056_name_60 = D_800FA656 + 0x49;
            break;
        default:
            D_801148F6_3D0056_name_60 = D_801148F0_3D0050_name_60;
            break;
        }
        mes = D_801132B0_3CEA10_name_60[D_801148F6_3D0056_name_60][3];
    } else {
        mes = D_801132B0_3CEA10_name_60[D_801148F0_3D0050_name_60][0] + page;
    }
    if (_CheckFlag(0xC) != 0) {
        switch (page) {
        case 0:
            mes = D_800FC890_FD490->mes[0];
            break;
        case 1:
            mes = D_800FC890_FD490->mes[1];
            break;
        case 2:
            mes = D_800FC890_FD490->mes[2];
            break;
        }
    }
    func_800890CC_89CCC(D_8011496C_3D00CC_name_60, mes, -1, -1);
    if (extra != -1 && _CheckFlag(0xC) == 0) {
        if (D_801148F0_3D0050_name_60 == 0x1E || D_801148F0_3D0050_name_60 == 0x42) {
            for (i = 0, n = 0; i < 4; i++) {
                if (page == 1) {
                    if (gPlayers[i].group != 0 && gPlayers[i].group != 2) {
                        continue;
                    }
                } else if (gPlayers[i].group != 1 && gPlayers[i].group != 3) {
                    continue;
                }
                func_80089308_89F08(D_8011496C_3D00CC_name_60, (char*)(gPlayers[i].character + 0x1BA), n++);
            }
        } else if (page == 1) {
            for (i = 0; i < 4; i++) {
                if (gPlayers[i].group == 0) {
                    break;
                }
            }
            if (i >= 4) {
                osSyncPrintf("instmain.c: mainplayer error\n");
                while (1) {
                }
            }
            func_80089308_89F08(D_8011496C_3D00CC_name_60, (char*)(gPlayers[i].character + 0x1BA), 0);
        } else if (page == 2) {
            for (i = 0, n = 0; i < 4; i++) {
                if (gPlayers[i].group != 0) {
                    func_80089308_89F08(D_8011496C_3D00CC_name_60, (char*)(gPlayers[i].character + 0x1BA), n++);
                }
            }
        }
    }
    while (func_8008BA30_8C630(D_8011496C_3D00CC_name_60) != 0) {
        HuPrcVSleep();
    }
    func_80089544_8A144(D_8011496C_3D00CC_name_60, D_8011496E_3D00CE_name_60[1]);
    if (extra == -1 || _CheckFlag(0xC) != 0) {
        if (page == 1) {
            page = 4;
        }
        if (page == 2) {
            page = 3;
        }
    }
    D_8011496E_3D00CE_name_60[1] = func_80089404_8A004(D_8011496C_3D00CC_name_60, (page + 0x14) | 0xB0000, 0x37, -0x28, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80103C84_3BF3E4_name_60);
#endif

void func_801040D0_3BF830_name_60(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[D_801148F8_3D0058_name_60[4]];
    u16 spr = obj->work[0];
    Vec pos;
    Vec2f screen;

    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    espPosSet(spr, (s8)obj->work[1] + screen.unk_00, (s8)obj->work[3] + screen.unk_04);
    espDispOn(spr);
    if (obj->work[2] != 0) {
        omDelObj(obj);
    }
}

void func_801041C4_3BF924_name_60(void) {
    omObjData* obj;
    s32 i;

    for (i = 0; i < 5; i++) {
        obj = omAddObj(0x64, 0, 0, -1, func_801040D0_3BF830_name_60);
        D_8011492C_3D008C_name_60[i] = obj;
        obj->work[0] = D_8011495E_3D00BE_name_60[i];
        obj->work[1] = D_80113544_3CECA4_name_60[i][0];
        obj->work[2] = 0;
        obj->work[3] = D_80113544_3CECA4_name_60[i][1];
    }
}

void func_80104280_3BF9E0_name_60(omObjData* obj) {
    u8 idx = obj->work[0];
    f32* work = obj->unk_50;

    if (D_80114968_3D00C8_name_60 != idx) {
        work[1] = 0.0f;
        work[0] = 1.0f;
    } else {
        work[0] = HuMathSin(work[1]) * 0.2f + 1.0f;
        work[1] += work[2];
        work[1] = func_8002D958_2E558(work[1]);
    }
    func_8001A91C_1B51C(D_8011495E_3D00BE_name_60[idx], work[0], work[0]);
}

#ifdef NON_MATCHING
void func_8010433C_3BFA9C_name_60(void) {
    omObjData* obj;
    f32* work;
    s32 spr;
    s32 i;

    for (i = 0; i < 5; i++) {
        spr = (s16)func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(D_8011351C_3CEC7C_name_60[D_800CAFD8[i]]), 0, 0);
        D_8011495E_3D00BE_name_60[i] = spr;
        SprAttrReset(D_800F93FC_F9FFC[spr].group, 0, 0x1000);
        espDispOff(spr);
        func_8001A708_1B308(spr, 0x4000);
        obj = omAddObj(0x64, 0, 0, -1, func_80104280_3BF9E0_name_60);
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        work = obj->unk_50;
        work[0] = 1.0f;
        work[1] = 0.0f;
        work[2] = 10.0f;
        obj->work[0] = i;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010433C_3BFA9C_name_60);
#endif

void func_80104490_3BFBF0_name_60(omObjData* obj) {
    f32* angle = obj->unk_50;
    Ovl60Esprite* esp = &D_800F93FC_F9FFC[obj->work[0]];

    esp->x = esp->x + HuMathSin(*angle) * 20.0f;
    esp->y = esp->y + func_800B7890_B8490(*angle) * 20.0f;
    if (esp->x < -100) {
        omDelObj(obj);
    }
}

void func_8010456C_3BFCCC_name_60(s32 arg0, s32 spr) {
    omObjData* obj;
    f32* angle;
    Ovl60Esprite* esp;
    Vec v;

    obj = omAddObj(0x64, 0, 0, -1, func_80104490_3BFBF0_name_60);
    obj->unk_50 = func_80027154_27D54(4, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 4);
    angle = obj->unk_50;
    esp = &D_800F93FC_F9FFC[spr];
    HuVecCopyXYZ(&v, esp->x - 160, 0.0f, esp->y - 120);
    *angle = func_800B75A8_B81A8(v.x, v.z);
    obj->work[0] = spr;
}

void func_80104650_3BFDB0_name_60(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_8010456C_3BFCCC_name_60(i, D_8011495E_3D00BE_name_60[i]);
    }
}

#ifdef NON_MATCHING
void func_801046A4_3BFE04_name_60(void) {
    f32 s;
    s32 i;

    D_80114978_3D00D8_name_60 = 1;
    s = 0.0f;
    SprPosSet(D_80114976_3D00D6_name_60, 0, 220, 30);
    while (1) {
        s += 0.1f;
        if (s >= 1.0f) {
            for (i = 0; i < 5; i++) {
                SprScaleSet(D_80114976_3D00D6_name_60, i, 1.0f, 1.0f);
            }
            break;
        }
        for (i = 0; i < 5; i++) {
            SprScaleSet(D_80114976_3D00D6_name_60, i, s, s);
        }
        for (i = 0; i < 3; i++) {
            SprAttrReset(D_80114976_3D00D6_name_60, i, 0x8000);
        }
        if ((s16)((D_8011496A_3D00CA_name_60 / 100) % 10) != 0) {
            SprAttrReset(D_80114976_3D00D6_name_60, 4, 0x8000);
            SprAttrReset(D_80114976_3D00D6_name_60, 3, 0x8000);
        } else if ((s16)((D_8011496A_3D00CA_name_60 / 10) % 10) != 0) {
            SprAttrReset(D_80114976_3D00D6_name_60, 3, 0x8000);
        }
        if (D_80114978_3D00D8_name_60 == 0) {
            break;
        }
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801046A4_3BFE04_name_60);
#endif

#ifdef NON_MATCHING
void func_801048F0_3C0050_name_60(void) {
    f32 s;
    s16 i;

    D_80114978_3D00D8_name_60 = 0;
    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        for (i = 0; i < 5; i++) {
            SprScaleSet(D_80114976_3D00D6_name_60, i, s, s);
        }
        if (D_80114978_3D00D8_name_60 != 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 5; i++) {
        SprAttrSet(D_80114976_3D00D6_name_60, i, 0x8000);
    }
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801048F0_3C0050_name_60);
#endif

#ifdef NON_MATCHING
void func_801049F4_3C0154_name_60(void) {
    s16 coin;
    s16 digit;
    s16 frame;
    s16 grp;
    s16 i;

    if (_CheckFlag(0x13) == 0) {
        D_8011496A_3D00CA_name_60 = D_800F9208_F9E08;
    } else {
        D_8011496A_3D00CA_name_60 = 0;
    }
    D_80114978_3D00D8_name_60 = 0;
    coin = func_8001A2F8_1AEF8(0xB001B);
    digit = func_8001A2F8_1AEF8(0xC000D);
    frame = func_8001A2F8_1AEF8(0xB001C);
    D_80114976_3D00D6_name_60 = grp = SprCreate(5, 5);
    SprAnimSet(grp, 0, coin, 0);
    func_800824F4_830F4(grp, 0, -1);
    SprAttrSet(grp, 0, 0x9000);
    SprAnimSet(grp, 1, frame, 0);
    func_800824F4_830F4(grp, 1, 0);
    SprAttrSet(grp, 1, 0x9000);
    for (i = 2; i < 5; i++) {
        SprAnimSet(grp, i, digit, 0);
        func_800824F4_830F4(grp, i, 0);
        func_8008225C_82E5C(grp, i, 1);
        func_8008221C_82E1C(grp, i, 0.0f);
        SprAttrSet(grp, i, 0x9000);
        SprPosSet(grp, i, -24 - (i - 2) * 10, 0);
    }
    func_800822A8_82EA8(grp, 2, D_8011496A_3D00CA_name_60 % 10, 0);
    func_800822A8_82EA8(grp, 3, (D_8011496A_3D00CA_name_60 / 10) % 10, 0);
    func_800822A8_82EA8(grp, 4, (D_8011496A_3D00CA_name_60 / 100) % 10, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801049F4_3C0154_name_60);
#endif

void func_80104D08_3C0468_name_60(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[obj->work[0]];
    Vec* ofs = obj->unk_50;

    func_80029714_2A314(obj->work[1], model->pos.x + ofs->x, model->pos.y + ofs->y, model->pos.z + ofs->z);
    func_800298A4_2A4A4(obj->work[1], 4, 0);
    if (obj->work[2] != 0) {
        omDelObj(obj);
    }
}

void func_80104DA8_3C0508_name_60(s32 i, s32 player, f32 x, f32 y, f32 z) {
    omObjData* obj;
    Vec* ofs;

    obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
    D_8011492C_3D008C_name_60[i] = obj;
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = x;
    ofs->y = y;
    ofs->z = z;
    /* the player's model: an s32 at 0x24 of its object's work, read as its low byte */
    obj->work[0] = ((s32*)D_80114908_3D0068_name_60[player]->unk_50)[9];
    obj->work[1] = ((u8*)D_800FA640_FB240[i])[0x35];
    obj->work[2] = 0;
}

void func_80104E98_3C05F8_name_60(s32 i) {
    omObjData* obj;

    obj = omAddObj(0x65, 0, 0, -1, func_801040D0_3BF830_name_60);
    D_8011492C_3D008C_name_60[i] = obj;
    obj->work[0] = ((u8*)D_800FA640_FB240[i])[0x6D];
    obj->work[1] = i * 30 - 60;
    obj->work[2] = 0;
    obj->work[3] = 0;
}

#ifdef NON_MATCHING
s32 func_80104F18_3C0678_name_60(s32 btn) {
    s32 ret = 0;
    s32 i;

    if (D_801148F2_3D0052_name_60 < 6) {
        if (D_801148F2_3D0052_name_60 >= 4) {
            if (!(gPlayers[D_801148F4_3D0054_name_60].flags & 1)) {
                ret = ContBtnTrg[gPlayers[D_801148F4_3D0054_name_60].port] & btn;
            }
            return ret;
        }
    }
    for (i = 0; i < 4; i++) {
        if (!(gPlayers[i].flags & 1) && (ret = btn & ContBtnTrg[gPlayers[i].port]) != 0) {
            break;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80104F18_3C0678_name_60);
#endif

#ifdef NON_MATCHING
s32 func_80105008_3C0768_name_60(s32 btn, s32 arg1) {
    s32 ret = 0;
    s32 cpu = 0;
    s32 i;

    if (D_801148F2_3D0052_name_60 < 6 && D_801148F2_3D0052_name_60 >= 4) {
        cpu = gPlayers[D_801148F4_3D0054_name_60].flags & 1;
    }
    for (i = 0; i < 4; i++) {
        if (!(gPlayers[i].flags & 1)) {
            break;
        }
    }
    if (i < 4 && cpu == 0) {
        ret = func_80104F18_3C0678_name_60(btn);
    } else if (arg1 == 0) {
        ret = 1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80105008_3C0768_name_60);
#endif

s32 func_801050DC_3C083C_name_60(s32 minigame) {
    s32 ret = 0;

    switch (minigame) {
    case 0x18:
    case 0x23:
    case 0x37:
    case 0x46:
    case 0x47:
        ret = 1;
        break;
    }
    return ret;
}

void func_80105110_3C0870_name_60(omObjData* obj) {
    HmfModel* model;

    switch (obj->work[0]) {
    case 0:
        model = &D_800FC834_FD434[D_8011494E_3D00AE_name_60];
        func_800298A4_2A4A4(D_8011495C_3D00BC_name_60, 4, 0);
        func_80029714_2A314(D_8011495C_3D00BC_name_60, model->pos.x - 20.0f, model->pos.y, model->pos.z - 100.0f);
        func_800297E8_2A3E8(D_8011495C_3D00BC_name_60, 1.0f, 0.0f, 1.0f);
        obj->work[0] = 1;
        break;
    case 1:
        model = &D_800FC834_FD434[D_8011495C_3D00BC_name_60];
        func_800297E8_2A3E8(D_8011495C_3D00BC_name_60, model->scale.x, model->scale.y + 0.1f, model->scale.z);
        if (model->scale.y >= 1.0f) {
            model->scale.y = 1.0f;
            omDelObj(obj);
        }
        break;
    }
}

#ifdef NON_MATCHING
void func_80105258_3C09B8_name_60(void) {
    HmfModel* model;
    Vec pos;
    Vec2f screen;
    f32 s;

    espDispOn(D_80114942_3D00A2_name_60);
    espDispOn(D_80114944_3D00A4_name_60);
    model = &D_800FC834_FD434[D_801148F8_3D0058_name_60[2]];
    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    espPosSet(D_80114942_3D00A2_name_60, screen.unk_00, 121);
    espPosSet(D_80114944_3D00A4_name_60, screen.unk_00, 121);
    for (s = 0.0f + 0.1f; !(s >= 1.0f); s += 0.1f) {
        func_8001A91C_1B51C(D_80114942_3D00A2_name_60, s, s);
        func_8001A91C_1B51C(D_80114944_3D00A4_name_60, s, s);
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_80114942_3D00A2_name_60, 1.0f, 1.0f);
    func_8001A91C_1B51C(D_80114944_3D00A4_name_60, 1.0f, 1.0f);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80105258_3C09B8_name_60);
#endif

#ifdef NON_MATCHING
void func_801053F0_3C0B50_name_60(void) {
    f32 s;

    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        func_8001A91C_1B51C(D_80114942_3D00A2_name_60, s, s);
        func_8001A91C_1B51C(D_80114944_3D00A4_name_60, s, s);
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_80114942_3D00A2_name_60, 0.0f, 0.0f);
    func_8001A91C_1B51C(D_80114944_3D00A4_name_60, 0.0f, 0.0f);
    espDispOff(D_80114942_3D00A2_name_60);
    espDispOff(D_80114944_3D00A4_name_60);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801053F0_3C0B50_name_60);
#endif

#ifdef NON_MATCHING
void func_801054EC_3C0C4C_name_60(void) {
    HmfModel* model;
    Vec pos;
    Vec2f screen;
    f32 s;
    s32 angle;

    D_8011494C_3D00AC_name_60 = 1;
    model = &D_800FC834_FD434[D_801148F8_3D0058_name_60[2]];
    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    espPosSet(D_8011494A_3D00AA_name_60, screen.unk_00, 70);
    for (s = 0.0f + 0.1f; !(s >= 1.0f); s += 0.1f) {
        func_8001A91C_1B51C(D_8011494A_3D00AA_name_60, s, s);
        espDispOn(D_8011494A_3D00AA_name_60);
        if (D_8011494C_3D00AC_name_60 == 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    angle = 0;
    func_8001A91C_1B51C(D_8011494A_3D00AA_name_60, 1.0f, 1.0f);
    while (1) {
        if (angle > 180) {
            angle -= 180;
        }
        func_8001A6BC_1B2BC(D_8011494A_3D00AA_name_60, HuMathSin(angle) * 255.0f);
        if (D_8011494C_3D00AC_name_60 == 0) {
            omDelPrcObj(NULL);
        }
        angle += 10;
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801054EC_3C0C4C_name_60);
#endif

#ifdef NON_MATCHING
void func_801056A8_3C0E08_name_60(void) {
    f32 s;

    D_8011494C_3D00AC_name_60 = 0;
    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        func_8001A91C_1B51C(D_8011494A_3D00AA_name_60, s, s);
        if (D_8011494C_3D00AC_name_60 != 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_8011494A_3D00AA_name_60, 0.0f, 0.0f);
    espDispOff(D_8011494A_3D00AA_name_60);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801056A8_3C0E08_name_60);
#endif

#ifdef NON_MATCHING
void func_8010578C_3C0EEC_name_60(void) {
    HmfModel* model = &D_800FC834_FD434[D_8011495A_3D00BA_name_60];
    s32 n = 30;
    f32 dx = model->pos.x / n;
    f32 dy = model->pos.y / n;

    do {
        model->pos.x -= dx;
        model->pos.y -= dy;
        model->scale.y = model->scale.z = model->scale.x = model->scale.x + 0.06666667f;
        HuPrcVSleep();
    } while (--n != 0);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010578C_3C0EEC_name_60);
#endif

void func_80105860_3C0FC0_name_60(void) {
    s32 n;

    while (1) {
        while (func_80029CE4_2A8E4(D_8011494E_3D00AE_name_60) < func_80029D0C_2A90C(D_8011494E_3D00AE_name_60)) {
            HuPrcVSleep();
        }
        n = (rand8() & 3) + 1;
        while (n != 0) {
            func_80029C74_2A874(D_8011494E_3D00AE_name_60, 0.0f);
            while (func_80029CE4_2A8E4(D_8011494E_3D00AE_name_60) < func_80029D0C_2A90C(D_8011494E_3D00AE_name_60)) {
                HuPrcVSleep();
            }
            n--;
        }
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[4], 0, 10, 0);
        while (func_80029E3C_2AA3C(D_8011494E_3D00AE_name_60) != -1.0f) {
            HuPrcVSleep();
        }
        while (func_80029CE4_2A8E4(D_8011494E_3D00AE_name_60) < func_80029D0C_2A90C(D_8011494E_3D00AE_name_60)) {
            HuPrcVSleep();
        }
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[0], 0, 10, 0);
        while (func_80029E3C_2AA3C(D_8011494E_3D00AE_name_60) != -1.0f) {
            HuPrcVSleep();
        }
    }
}

s32 func_80105A14_3C1174_name_60(void) {
    s32 ret = D_801148F0_3D0050_name_60 != 0x38;

    if (_CheckFlag(0xC) != 0) {
        ret = 0;
    }
    return ret;
}

s32 func_80105A54_3C11B4_name_60(void) {
    if (func_80105A14_3C1174_name_60() != 0 && func_80104F18_3C0678_name_60(0x10) != 0) {
        _SetFlag(0x15);
        D_8011497A_3D00DA_name_60 = 1;
        D_800F9910_FA510 |= 1;
    }
    return D_8011497A_3D00DA_name_60;
}

void func_80105AB8_3C1218_name_60(void) {
    D_8011497A_3D00DA_name_60 = 0;
    D_800F9910_FA510 &= ~1;
    _ClearFlag(0x15);
    SprAttrReset(func_80089674_8A274(D_8011496C_3D00CC_name_60)->unk_6C, D_8011496E_3D00CE_name_60[2], 0x8000);
    func_80089544_8A144(D_8011496C_3D00CC_name_60, D_8011496E_3D00CE_name_60[3]);
    D_8011496E_3D00CE_name_60[3] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0022, 0xBE, -0x28, 0);
    omAddPrcObj(func_801056A8_3C0E08_name_60, 0x1001, 0x800, 0);
    if (D_801148F2_3D0052_name_60 == 3) {
        omAddPrcObj(func_801046A4_3BFE04_name_60, 0x1001, 0x800, 0);
    }
}

void func_80105B94_3C12F4_name_60(void) {
    omObjData* obj;
    Ovl60FallWork* work;
    Ovl60FallInit* init;
    Vec* ofs;
    s32 i;
    s32 page;
    s32 timer;
    s32 mes;
    s16 btn;
    s32 wait;

    D_80114968_3D00C8_name_60 = -1;
    for (i = 0; i < 8; i++) {
        D_80114920_3D0080_name_60[i] = NULL;
    }
    if (D_801148F2_3D0052_name_60 == 4) {
        func_8010433C_3BFA9C_name_60();
    } else {
        func_80112BE0_3CE340_name_60();
    }
    func_80107C84_3C33E4_name_60(D_801148F0_3D0050_name_60);
    obj = omAddObj(0x64, 0, 0, -1, func_8010382C_3BEF8C_name_60);
    obj->work[0] = 0;
    obj->work[1] = 30;
    for (i = 0; i < 5; i++) {
        obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
        obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
        work = obj->unk_50;
        init = &D_80113574_3CECD4_name_60[i];
        work->pos.x = work->baseX = init->pos.x;
        work->pos.y = init->pos.y;
        work->pos.z = init->pos.z;
        work->scale = init->scale;
        work->floor = init->floor;
        obj->work[0] = init->work[0];
        obj->work[1] = init->work[1];
        obj->work[2] = init->work[2];
        obj->work[3] = init->work[3];
    }

    D_80114908_3D0068_name_60[0] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_80113574_3CECD4_name_60[5].pos.x;
    work->pos.y = D_80113574_3CECD4_name_60[5].pos.y - 500.0f;
    work->pos.z = D_80113574_3CECD4_name_60[5].pos.z;
    work->scale = 0.9f;
    work->floor = D_80113574_3CECD4_name_60[5].pos.y;
    obj->work[0] = 1;
    obj->work[1] = 3;
    obj->work[2] = 50;
    obj->work[3] = 1;

    i = 6;
    switch (D_801148F2_3D0052_name_60) {
    case 1:
        i = 7;
        break;
    case 2:
        if (D_801148F0_3D0050_name_60 != 0x21) {
            i = 8;
        }
        break;
    }
    D_80114908_3D0068_name_60[1] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_80113574_3CECD4_name_60[i].pos.x;
    work->pos.y = D_80113574_3CECD4_name_60[i].pos.y - 600.0f;
    work->pos.z = D_80113574_3CECD4_name_60[i].pos.z;
    work->scale = 1.0f;
    work->floor = D_80113574_3CECD4_name_60[i].pos.y;
    obj->work[0] = 2;
    obj->work[1] = 3;
    obj->work[2] = 80;
    obj->work[3] = 0;

    D_80114908_3D0068_name_60[2] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_80113574_3CECD4_name_60[9].pos.x;
    work->pos.y = D_80113574_3CECD4_name_60[9].pos.y - 400.0f;
    work->pos.z = D_80113574_3CECD4_name_60[9].pos.z;
    work->scale = 0.8f;
    work->floor = D_80113574_3CECD4_name_60[9].pos.y;
    obj->work[0] = 3;
    obj->work[1] = 3;
    obj->work[2] = 50;
    obj->work[3] = 0;

    D_80114908_3D0068_name_60[3] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_80113574_3CECD4_name_60[10].pos.x;
    work->pos.y = D_80113574_3CECD4_name_60[10].pos.y - 400.0f;
    work->pos.z = D_80113574_3CECD4_name_60[10].pos.z;
    work->scale = 1.5f;
    work->floor = D_80113574_3CECD4_name_60[10].pos.y;
    obj->work[0] = 4;
    obj->work[1] = 3;
    obj->work[2] = 70;
    obj->work[3] = 1;

    if (D_801148F2_3D0052_name_60 < 3) {
        if (D_801148F2_3D0052_name_60 > 0 && D_801148F0_3D0050_name_60 != 0x21) {
        D_80114908_3D0068_name_60[4] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3BED68_name_60);
        obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
        work = obj->unk_50;
        work->pos.x = work->baseX = D_80113574_3CECD4_name_60[11].pos.x;
        work->pos.y = D_80113574_3CECD4_name_60[11].pos.y - 400.0f;
        work->pos.z = D_80113574_3CECD4_name_60[11].pos.z;
        work->scale = 1.5f;
        work->floor = D_80113574_3CECD4_name_60[11].pos.y;
        obj->work[0] = 5;
        obj->work[1] = 3;
        obj->work[2] = 70;
        obj->work[3] = 1;
        }
    }
    HuPrcVSleep();

    omAddObj(0x64, 0, 0, -1, func_801038D4_3BF034_name_60);
    D_80114920_3D0080_name_60[0] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    switch (D_801148F2_3D0052_name_60) {
    case 4:
        ofs->y = -70.0f;
        break;
    case 3:
        ofs->y = -20.0f;
        break;
    default:
        ofs->y = -60.0f;
        break;
    }
    ofs->z = -80.0f;
    work = D_80114908_3D0068_name_60[2]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_8011494E_3D00AE_name_60;
    obj->work[2] = 0;
    if (D_801148F2_3D0052_name_60 == 3) {
        D_80114920_3D0080_name_60[7] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        ofs = obj->unk_50;
        ofs->x = 0.0f;
        ofs->y = -20.0f;
        ofs->z = -80.0f;
        work = D_80114908_3D0068_name_60[2]->unk_50; obj->work[0] = work->model;
        obj->work[1] = D_8011495C_3D00BC_name_60;
        obj->work[2] = 0;
    }
    D_80114920_3D0080_name_60[1] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    ofs->y = 0.0f;
    ofs->z = 10.0f;
    work = D_80114908_3D0068_name_60[1]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_8011495A_3D00BA_name_60;
    obj->work[2] = 0;
    D_80114920_3D0080_name_60[2] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    ofs->y = 0.0f;
    ofs->z = 15.0f;
    work = D_80114908_3D0068_name_60[1]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_80114948_3D00A8_name_60;
    obj->work[2] = 0;
    switch (D_801148F2_3D0052_name_60) {
    case 4:
        func_801041C4_3BF924_name_60();
        break;
    case 5:
        D_80114920_3D0080_name_60[3] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3C0468_name_60);
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        ofs = obj->unk_50;
        ofs->x = -20.0f;
        ofs->y = -50.0f;
        ofs->z = -80.0f;
        work = D_80114908_3D0068_name_60[3]->unk_50; obj->work[0] = work->model;
        obj->work[1] = ((u8*)D_800FA640_FB240[0])[0x35];
        obj->work[2] = 0;
        break;
    default:
        func_80112B8C_3CE2EC_name_60();
        break;
    }
    omAddObj(0x64, 0, 0, -1, func_80107FE0_3C3740_name_60);
    HuPrcSleep(30);

    switch (D_801148F2_3D0052_name_60) {
    case 3:
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[1], 0, 2, 0);
        wait = 2;
        break;
    case 4:
        func_8002C9C0_2D5C0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[2]);
        func_80029C74_2A874(D_8011494E_3D00AE_name_60, func_80029D0C_2A90C(D_8011494E_3D00AE_name_60));
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 4);
        wait = 30;
        break;
    default:
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[1], 0, 2, 0);
        wait = 10;
        break;
    }
    HuPrcSleep(wait);

    /* the riders let go */
    switch (D_801148F2_3D0052_name_60) {
    case 3:
    case 4:
        for (i = 0; i < 8; i++) {
            if (D_80114920_3D0080_name_60[i] != NULL) {
                D_80114920_3D0080_name_60[i]->work[2] = 1;
            }
        }
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            if (D_80114920_3D0080_name_60[i] != NULL) {
                D_80114920_3D0080_name_60[i]->work[2] = 1;
            }
        }
        break;
    default:
        for (i = 0; i < 7; i++) {
            if (D_80114920_3D0080_name_60[i] != NULL) {
                D_80114920_3D0080_name_60[i]->work[2] = 1;
            }
        }
        break;
    }
    PlaySound(0x31F);
    switch (D_801148F2_3D0052_name_60) {
    case 4:
        wait = 0xE6;
        break;
    case 3:
        wait = 0xE8;
        break;
    default:
        wait = 0x11E;
        break;
    }
    PlaySound(wait);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3BEED8_name_60);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_801148F8_3D0058_name_60[3];
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3BEED8_name_60);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_801148F8_3D0058_name_60[4];
    if (D_801148F2_3D0052_name_60 < 3) {
        if (D_801148F2_3D0052_name_60 > 0 && D_801148F0_3D0050_name_60 != 0x21) {
        PlaySound(0x329);
        obj = omAddObj(0x64, 0, 0, -1, func_80103778_3BEED8_name_60);
        obj->work[0] = 0;
        obj->work[1] = 0;
        obj->work[2] = D_801148F8_3D0058_name_60[5];
        }
    }
    switch (D_801148F2_3D0052_name_60) {
    case 4:
        HuPrcSleep(20);
        func_8002C9C0_2D5C0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[0]);
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 0);
        D_80114A70_3D01D0_name_60[0] = omAddPrcObj(func_80105860_3C0FC0_name_60, 0x1001, 0x800, 0);
        break;
    case 3:
        HuPrcSleep(20);
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[0], 0, 2, 0);
        func_80029E80_2AA80(D_8011494E_3D00AE_name_60, 0, 2);
        omAddPrcObj(func_801046A4_3BFE04_name_60, 0x1001, 0x800, 0);
        break;
    default:
        HuPrcSleep(10);
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[2], 0, 2, 2);
        break;
    }
    if (func_801050DC_3C083C_name_60(D_801148F0_3D0050_name_60) != 0) {
        omAddObj(0x64, 0, 0, -1, func_80105110_3C0870_name_60)->work[0] = 0;
    }
    if (D_801148F2_3D0052_name_60 != 4) {
        func_80112BA8_3CE308_name_60();
    }
    omAddPrcObj(func_80105258_3C09B8_name_60, 0x1001, 0x800, 0);

    /* the instruction pages */
    page = 0;
    func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, 0);
    func_8008E2DC_8EEDC(D_8011496C_3D00CC_name_60, 1);
    if (D_801148F2_3D0052_name_60 < 6) {
        if (D_801148F2_3D0052_name_60 >= 4) {
            btn = D_8011356C_3CECCC_name_60[gPlayers[D_801148F4_3D0054_name_60].port];
            goto setButtons;
        }
    }
    i = 0;
    btn = 0;
    for (; i < 4; i++) {
        if (!(gPlayers[i].flags & 1)) {
            btn |= D_8011356C_3CECCC_name_60[gPlayers[i].port];
        }
    }
setButtons:
    func_8008D59C_8E19C(D_8011496C_3D00CC_name_60, btn);
    D_800FC8A0_FD4A0 = 1;
    timer = 60;
    while (func_80105008_3C0768_name_60(0x1000, timer--) == 0) {
        if (func_80104F18_3C0678_name_60(1) != 0) {
            D_80114968_3D00C8_name_60 = -1;
            page++;
            if (D_801132B0_3CEA10_name_60[D_801148F0_3D0050_name_60][2] == -1 || _CheckFlag(0xC) != 0) {
                if (page >= 3) {
                    page = 0;
                }
            } else if (page >= 4) {
                page = 0;
            }
            func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, page);
        }
        if (func_80104F18_3C0678_name_60(2) != 0) {
            D_80114968_3D00C8_name_60 = -1;
            page--;
            if (D_801132B0_3CEA10_name_60[D_801148F0_3D0050_name_60][2] == -1 || _CheckFlag(0xC) != 0) {
                if (page < 0) {
                    page = 2;
                }
            } else if (page < 0) {
                page = 3;
            }
            func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, page);
        }
        if (D_801148F2_3D0052_name_60 == 4 && func_80104F18_3C0678_name_60(4) != 0 && page == 0) {
            /* the item list */
            func_80089544_8A144(D_8011496C_3D00CC_name_60, D_8011496E_3D00CE_name_60[1]);
            D_8011496E_3D00CE_name_60[1] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0019, 0x37, -0x28, 0);
            SprAttrSet(func_80089674_8A274(D_8011496C_3D00CC_name_60)->unk_6C, D_8011496E_3D00CE_name_60[2], 0x8000);
            func_800890CC_89CCC(D_8011496C_3D00CC_name_60, D_800CAFD8[0] + 0x1D2, -1, -1);
            do {
                HuPrcVSleep();
            } while (func_8008BA30_8C630(D_8011496C_3D00CC_name_60) != 0);
            i = 0;
            D_80114968_3D00C8_name_60 = 0;
            while (1) {
                if (func_80104F18_3C0678_name_60(4) != 0) {
                    if (++D_80114968_3D00C8_name_60 >= 5) {
                        D_80114968_3D00C8_name_60 = 0;
                    }
                    func_800890CC_89CCC(D_8011496C_3D00CC_name_60, D_800CAFD8[D_80114968_3D00C8_name_60] + 0x1D2, -1, -1);
                    while (func_8008BA30_8C630(D_8011496C_3D00CC_name_60) != 0) {
                        HuPrcVSleep();
                    }
                }
                if (func_80104F18_3C0678_name_60(8) != 0) {
                    D_80114968_3D00C8_name_60 = -1;
                    SprAttrReset(func_80089674_8A274(D_8011496C_3D00CC_name_60)->unk_6C, D_8011496E_3D00CE_name_60[2], 0x8000);
                    func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, page);
                    break;
                }
                if (func_80105008_3C0768_name_60(0x1000, 1) != 0) {
                    i = 1;
                    break;
                }
                if (func_80105A54_3C11B4_name_60() != 0) {
                    D_80114968_3D00C8_name_60 = -1;
                    break;
                }
                HuPrcVSleep();
            }
            if (i != 0) {
                break;
            }
        }
        if (func_80105A54_3C11B4_name_60() != 0) {
            /* START: skip to the minigame, after its last pages */
            PlaySound(2);
            func_8008DF9C_8EB9C(D_8011496C_3D00CC_name_60, 0x1010);
            if (D_801148F2_3D0052_name_60 == 3) {
                omAddPrcObj(func_801048F0_3C0050_name_60, 0x1001, 0x800, 0);
            }
            SprAttrSet(func_80089674_8A274(D_8011496C_3D00CC_name_60)->unk_6C, D_8011496E_3D00CE_name_60[2], 0x8000);
            omAddPrcObj(func_801054EC_3C0C4C_name_60, 0x1001, 0x800, 0);
            func_80089544_8A144(D_8011496C_3D00CC_name_60, D_8011496E_3D00CE_name_60[1]);
            D_8011496E_3D00CE_name_60[1] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB001A, 0x37, -0x28, 0);
            func_80089544_8A144(D_8011496C_3D00CC_name_60, D_8011496E_3D00CE_name_60[3]);
            D_8011496E_3D00CE_name_60[3] = func_80089404_8A004(D_8011496C_3D00CC_name_60, 0xB0023, 0xBE, -0x28, 0);
            switch (D_801148F2_3D0052_name_60) {
            case 4:
                mes = 0x537;
                break;
            case 3:
                mes = 0x53A;
                break;
            default:
                mes = 0x53D;
                if (func_801050DC_3C083C_name_60(D_801148F0_3D0050_name_60) != 0) {
                    mes = 0x540;
                }
                break;
            }
            for (i = 0; ; ) {
                func_800890CC_89CCC(D_8011496C_3D00CC_name_60, mes + i, -1, -1);
                while (func_8008BA30_8C630(D_8011496C_3D00CC_name_60) != 0) {
                    HuPrcVSleep();
                }
                if (D_800F920C_F9E0C[D_8011496C_3D00CC_name_60].unkA8 & 0x10) {
                    i = 200;
                    break;
                }
                if (D_800F920C_F9E0C[D_8011496C_3D00CC_name_60].unkA8 & 0x1000) {
                    i = 100;
                    break;
                }
                if (++i >= 3) {
                    break;
                }
            }
            if (i != 200) {
                if (i == 100) {
                    break;
                }
                if (D_801132B0_3CEA10_name_60[D_801148F0_3D0050_name_60][2] == -1 || _CheckFlag(0xC) != 0) {
                    page = 2;
                } else {
                    page = 3;
                }
                func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, page);
                func_800890CC_89CCC(D_8011496C_3D00CC_name_60, (s32)D_80114348_3CFAA8_name_60, -1, -1);
                while (func_8008BA30_8C630(D_8011496C_3D00CC_name_60) != 0) {
                    HuPrcVSleep();
                }
                if (!(D_800F920C_F9E0C[D_8011496C_3D00CC_name_60].unkA8 & 0x10)) {
                    break;
                }
            }
            /* B: back to the first page */
            page = 0;
            func_80105AB8_3C1218_name_60();
            func_80103C84_3BF3E4_name_60(D_8011496C_3D00CC_name_60, 0);
        }
        HuPrcVSleep();
    }

    if (D_801148F2_3D0052_name_60 != 4) {
        func_80112BC4_3CE324_name_60();
    }
    D_800FC8A0_FD4A0 = 11;
    if (D_801148F2_3D0052_name_60 < 6) {
        if (D_801148F2_3D0052_name_60 >= 4) {
            omVibrate(D_801148F4_3D0054_name_60, 10, 0, 10);
            goto vibrated;
        }
    }
    for (i = 0; i < 4; i++) {
        omVibrate(i, 10, 0, 10);
    }
vibrated:
    HuPrcSleep(4);
    if (D_801148F2_3D0052_name_60 == 4) {
        func_80104650_3BFDB0_name_60();
    }
    switch (D_801148F2_3D0052_name_60) {
    case 4:
        omDelPrcObj(D_80114A70_3D01D0_name_60[0]);
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[3], 0, 3, 2);
        break;
    case 3:
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[2], 0, 3, 2);
        break;
    default:
        func_80029BF0_2A7F0(D_8011494E_3D00AE_name_60, D_80114950_3D00B0_name_60[3], 0, 3, 2);
        break;
    }
    omAddObj(0x7D00, 0, 0, -1, func_80103994_3BF0F4_name_60)->work[1] = 0;
    if (func_801050DC_3C083C_name_60(D_801148F0_3D0050_name_60) != 0 || D_801148F2_3D0052_name_60 == 3) {
        omAddObj(0x7D00, 0, 0, -1, func_80103B78_3BF2D8_name_60);
    }
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3BEED8_name_60);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_801148F8_3D0058_name_60[2];
    func_800298A4_2A4A4(D_80114948_3D00A8_name_60, 4, 4);
    HuPrcSleep(5);
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3BEED8_name_60);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_801148F8_3D0058_name_60[1];
    if (D_801148F2_3D0052_name_60 == 3) {
        omAddPrcObj(func_801048F0_3C0050_name_60, 0x1001, 0x800, 0);
    }
    omAddPrcObj(func_801053F0_3C0B50_name_60, 0x1001, 0x800, 0);
    if (_CheckFlag(0x15) != 0) {
        omAddPrcObj(func_801056A8_3C0E08_name_60, 0x1001, 0x800, 0);
    }
    func_8008E4D0_8F0D0(D_8011496C_3D00CC_name_60, 1);
    omAddPrcObj(func_8010578C_3C0EEC_name_60, 0x1001, 0x800, 0);
    PlaySound(0x345);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeOut(0, 30);
    func_800794A8_7A0A8(25);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80069698_6A298();
    func_801085A0_3C3D00_name_60(1);
    while (1) {
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_80114348_3CFAA8_name_60[4] = "\xFF";

void func_801072C8_3C2A28_name_60(s16 model, void* header, void* code, u8* alpha) {
    HmfData* hmf;
    HmfPart* part;
    u16* buf;
    u16 pix;
    u8* work;
    u8* tex;
    Vtx* vtx;
    Vtx* faceVtx;
    Gfx* gfx;
    s16 partIdx;
    s16 i;
    s16 j;
    s16 w;
    s16 h;
    f32 x;
    f32 y;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;
    f32 baseX;
    f32 baseY;
    f32 rangeX;
    f32 rangeY;
    s16 v;
    s16 uls;
    s16 lrs;
    u16 ult;
    u16 lrt;

    w = 128;
    h = 96;
    hmf = D_800FC834_FD434[model].hmf;
    buf = HuMemMemoryAllocPerm(0x6000);
    func_80096C10_97810(0xFF);
    func_80096708_97308(header);
    work = HuMemMemoryAllocPerm(0xC00);
    func_80096188_96D88(code, buf, 128, work);
    HuMemMemoryFreePerm(work);
    tex = func_80027154_27D54(0xC000, hmf->unk0E);
    alpha += (alpha[0xA] << 16) + alpha[0xB];
    for (y = 0.0f, i = 0; y < h; y += 1.0f) {
        for (x = 0.0f; x < w; x += 1.0f) {
            pix = buf[i];
            tex[i * 4 + 0] = (pix >> 8) & 0xF8;
            tex[i * 4 + 1] = (pix >> 3) & 0xF8;
            tex[i * 4 + 2] = (pix << 2) & ~7;
            tex[i * 4 + 3] = alpha[i];
            i++;
        }
    }
    HuMemMemoryFreePerm(buf);

    partIdx = func_80038398_38F98(hmf, "gameimage-grid1");
    part = &hmf->unk64[partIdx];
    vtx = func_80027154_27D54(0x500, hmf->unk0E);
    hmf->unk3C->unk00[partIdx] = gfx = func_80027154_27D54(0x1000, hmf->unk0E);
    part->unk50 |= 0x10000;
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gSPClearGeometryMode(gfx++, G_LIGHTING);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    /* the part's extent */
    maxX = maxY = -100000.0f;
    minX = minY = 100000.0f;
    for (i = 0; i < part->unk04; i++) {
        for (j = 0; j < part->unk54[i].unk00; j++) {
            v = part->unk54[i].unk04[j];
            if (hmf->unk54[v].x < minX) {
                minX = hmf->unk54[v].x;
            }
            if (maxX < hmf->unk54[v].x) {
                maxX = hmf->unk54[v].x;
            }
            if (hmf->unk54[v].y < minY) {
                minY = hmf->unk54[v].y;
            }
            if (maxY < hmf->unk54[v].y) {
                maxY = hmf->unk54[v].y;
            }
        }
    }
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    baseX = minX;
    baseY = minY;

    /* each face: its vertices, mapped onto the picture, and its tile */
    for (i = 0; i < part->unk04; i++) {
        faceVtx = vtx;
        maxX = maxY = -100000.0f;
        minX = minY = 100000.0f;
        for (j = 0; j < part->unk54[i].unk00; j++) {
            v = part->unk54[i].unk04[j];
            vtx->v.ob[0] = hmf->unk54[v].x;
            x = vtx->v.ob[0];
            vtx->v.ob[1] = hmf->unk54[v].y;
            y = vtx->v.ob[1];
            vtx->v.ob[2] = hmf->unk54[v].z;
            if (x < minX) {
                minX = x;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (y < minY) {
                minY = y;
            }
            if (maxY < y) {
                maxY = y;
            }
            vtx->n.n[0] = vtx->n.n[1] = vtx->n.n[2] = -1;
            x = w - w * ((-x - baseX) / rangeX);
            y = h * ((-y - baseY) / rangeY);
            vtx->v.tc[0] = x * 32.0f;
            vtx->v.tc[1] = y * 32.0f;
            vtx->n.a = 0xFF;
            vtx++;
        }
        minX = (minX - baseX) / rangeX * w;
        maxX = (maxX - baseX) / rangeX * w;
        minY = h - (minY - baseY) / rangeY * h;
        if (minY == h) {
            minY = h - 0.1f;
        }
        maxY = h - (maxY - baseY) / rangeY * h;
        ult = (s32)maxY;
        lrt = (s32)minY;
        lrs = maxX;
        uls = minX;
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPLoadTextureTile(gfx++, tex, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, uls, ult, lrs, lrt, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gfx++, faceVtx, part->unk54[i].unk00, 0);
        if (part->unk54[i].unk00 == 3) {
            gSP1Triangle(gfx++, 0, 1, 2, 0);
        } else {
            gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        }
    }
    gSPEndDisplayList(gfx++);
}

#ifdef NON_MATCHING
void func_80107C84_3C33E4_name_60(s32 minigame) {
    u8* mes;
    u8* start;
    u8* p;
    u8* q;
    GAMEMES* line;
    s16 n;
    s16 id;
    s16 breaks;

    mes = func_80068CD4_698D4((s16)minigame + 0x3D9);
    start = mes + 1;
    breaks = 0;
    for (p = start; *p != 0; p++) {
        if (*p < 0x20) {
            breaks++;
        }
    }
    D_80114988_3D00E8_name_60[0].unk08 = D_80114988_3D00E8_name_60[1].unk08 = -1;
    n = 0;
    for (p = start; *p != 0; p++) {
        if (*p < 0x20) {
            q = p - 1;
            if (*q == 0x10 || *q == 0x20 || *q == 0x1A) {
                *q = 0;
            }
            *p = 0;
            line = &D_80114988_3D00E8_name_60[n];
            id = line->unk08 = func_8006A67C_6B27C(line, (char*)start, 0, -1, -1);
            D_80114988_3D00E8_name_60[n].unk60 = 82.0f;
            D_80114988_3D00E8_name_60[n].unk64 = 40.0f;
            SprPosSet(D_80114988_3D00E8_name_60[n].strGId[id], 0, D_80114988_3D00E8_name_60[n].unk60, 40);
            n++;
            start = p + 1;
        }
    }
    line = &D_80114988_3D00E8_name_60[n];
    id = line->unk08 = func_8006A67C_6B27C(line, (char*)start, 0, -1, -1);
    D_80114988_3D00E8_name_60[n].unk60 = 82.0f;
    D_80114988_3D00E8_name_60[n].unk64 = (breaks != 0) ? 60.0f : 50.0f;
    SprPosSet(D_80114988_3D00E8_name_60[n].strGId[id], 0, D_80114988_3D00E8_name_60[n].unk60, D_80114988_3D00E8_name_60[n].unk64);
    func_80068D24_69924(mes);
    func_80107F74_3C36D4_name_60();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80107C84_3C33E4_name_60);
#endif

void func_80107F74_3C36D4_name_60(void) {
    SprPosSet(D_80114988_3D00E8_name_60[0].strGId[D_80114988_3D00E8_name_60[0].unk08], 0, 0, -200);
    if (D_80114988_3D00E8_name_60[1].unk08 != -1) {
        SprPosSet(D_80114988_3D00E8_name_60[1].strGId[D_80114988_3D00E8_name_60[1].unk08], 0, 0, -200);
    }
}

void func_80107FE0_3C3740_name_60(void) {
    HmfModel* model = &D_800FC834_FD434[D_801148F8_3D0058_name_60[1]];
    Vec pos;
    Vec2f screen;

    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    screen.unk_00 += 5.0f;
    screen.unk_04 -= 8.0f;
    if (D_80114988_3D00E8_name_60[1].unk08 != -1) {
        SprPosSet(D_80114988_3D00E8_name_60[0].strGId[D_80114988_3D00E8_name_60[0].unk08], 0, screen.unk_00, screen.unk_04);
        SprPosSet(D_80114988_3D00E8_name_60[1].strGId[D_80114988_3D00E8_name_60[1].unk08], 0, screen.unk_00, screen.unk_04 + 16.0f);
    } else {
        SprPosSet(D_80114988_3D00E8_name_60[0].strGId[D_80114988_3D00E8_name_60[0].unk08], 0, screen.unk_00, screen.unk_04 + 10.0f);
    }
}

void func_80108170_3C38D0_name_60(void) {
    s32 i;
    s32 n;
    s32 m;
    s32 g;

    switch (D_801148F2_3D0052_name_60) {
    case 4:
        func_8010881C_3C3F7C_name_60(GwSystem.current_player_index);
    case 5:
    case 6:
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = 1;
        }
        gPlayers[GwSystem.current_player_index].group = 0;
        break;
    case 0:
    case 3:
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = i;
        }
        break;
    case 2:
        n = 0;
        for (i = 0; i < 4; i++) {
            n += gPlayers[i].group == 0;
        }
        if (n >= 2) {
            switch (D_801148F0_3D0050_name_60) {
            case 0x19:
            case 0x1E:
            case 0x1F:
            case 0x41:
            case 0x42:
                i = 0;
                n = 0;
                m = 1;
                for (; i < 4; i++) {
                    if (gPlayers[i].group != 0) {
                        gPlayers[i].group = m + gPlayers[i].group;
                        m++;
                    } else {
                        gPlayers[i].group = n + gPlayers[i].group;
                        n++;
                    }
                }
                for (g = 0; g < 3; g += 2) {
                    if (rand8() & 1) {
                        for (i = 0; i < 4; i++) {
                            if (gPlayers[i].group == g) {
                                n = i;
                            }
                            if (gPlayers[i].group == g + 1) {
                                m = i;
                            }
                        }
                        gPlayers[n].group = g + 1;
                        gPlayers[m].group = g;
                    }
                }
                break;
            }
        }
        break;
    }
}

void func_80108458_3C3BB8_name_60(void) {
    s32 r;
    s32 mg;

    if (_CheckFlag(0x15) == 0) {
        r = (rand8() & 0xFF) * 0.00390625f * 100.0f;
        mg = D_801148F0_3D0050_name_60;
        switch (mg) {
        case 0x34:
            if (r < 50) {
                r = 0;
            } else if (r < 80) {
                r = 1;
            } else {
                r = 2;
            }
            break;
        case 0x2D:
            if (r < 60) {
                r = 0;
            } else if (r < 80) {
                r = 1;
            } else {
                r = 2;
            }
            break;
        case 0x26:
            if (r < 40) {
                r = 0;
            } else if (r < 70) {
                r = 1;
            } else {
                r = 2;
            }
            break;
        case 0x11:
        case 0x19:
            r = !(r < 50);
            break;
        case 0xC:
        case 0xE:
        case 0x29:
        case 0x43:
        case 0x45:
            if (r < 33) {
                r = 0;
            } else if (r < 66) {
                r = 1;
            } else {
                r = 2;
            }
            break;
        case 0xB:
            r = rand8() & 3;
            r = gPlayers[r].character;
            break;
        default:
            r = 0;
            break;
        }
        if (D_800CAFEE != -1) {
            r = D_800CAFEE;
        }
        D_800FA656 = r;
    }
}

extern s16 D_801148F0_3D0050_name_60;
extern s16 D_801148F2_3D0052_name_60;
extern s16 D_8011497A_3D00DA_name_60;
extern void* D_8011497C_3D00DC_name_60;
extern void* D_80114980_3D00E0_name_60;
extern void* D_80114984_3D00E4_name_60;

void func_801085A0_3C3D00_name_60(s32 arg0) {
    s16 minigameOverlayID;

    func_8008CE5C_8DA5C();
    func_800727F0_733F0();
    func_80067EF8_68AF8(-1);
    
    if (arg0 != 0) {
        DataClose(D_80114984_3D00E4_name_60);
        DataClose(D_8011497C_3D00DC_name_60);
        DataClose(D_80114980_3D00E0_name_60);
        omOvlKill();
    }
    
    if (D_8011497A_3D00DA_name_60 != 0) {
        omOvlCallEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x14);
        minigameOverlayID = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
        omOvlHisChg(1, minigameOverlayID, 0, 0x14);
        return;
    } 
    
    _ClearFlag(0x15);
    if ((_CheckFlag(0x13) != 0) || !(_CheckFlag(0xC) == 0)) {
        omOvlGotoEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x14);
        return;
    }
    
    switch (D_801148F2_3D0052_name_60) {
        case 6:
        case 5:
        case 4:
            omOvlGotoEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x14);
            return;
        case 7:
            GwSystem.current_board_index = (u16) D_801148F0_3D0050_name_60 - 0x3A;
            D_800F8D18[2] = 1;
            D_800F8D18[1] = 0xE;
            omOvlGotoEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x12);
            return;
            
        case 3:
            omOvlCallEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x14);
            omOvlHisChg(1, 0x6F, 0, 0x14);
            return;
    }
    omOvlCallEx(D_800CAD90[D_801148F0_3D0050_name_60].unk_00, 0, 0x14);
    omOvlHisChg(1, 0x70, 0, 0x14);
}




void func_8010879C_3C3EFC_name_60(s32 player, s32 set) {
    s32 i;
    s32 c = gPlayers[player].character;

    for (i = 0; i < 5; i++) {
        D_800CAFE4[i] = D_80113718_3CEE78_name_60[set][i][c];
    }
}

void func_8010881C_3C3F7C_name_60(s32 player) {
    s32 i;
    s32 len;
    s32 set;

    len = 0;
    if (_CheckFlag(0x17) == 0) {
        if (_CheckFlag(0x15) != 0) {
            set = D_80102758_103358[8];
        } else {
            set = rand8() & 3;
            D_80102758_103358[8] = set;
        }
        goto copy;
    }
    if (_CheckFlag(0x15) != 0) {
        set = D_80102758_103358[8];
    } else {
        switch (GwSystem.current_game_length) {
        case 0:
            len = 0;
            break;
        case 1:
            len = 1;
            break;
        case 2:
            len = 2;
            break;
        }
        for (i = 0; i < 3; i++) {
            if (D_801136C4_3CEE24_name_60[len][i] >= GwSystem.current_turn) {
                break;
            }
        }
        if (i >= 3) {
            osSyncPrintf("instmain.c : minigameitemset error");
            while (1) {
            }
        }
        set = D_801136D8_3CEE38_name_60[func_80059FD0_5ABD0(player)][i];
        if (set == 4) {
            set = (u8)(rand8() % 10) >= 6;
        }
        if (set >= 4) {
            osSyncPrintf("instmain.c : minigameitemset error2");
            while (1) {
            }
        }
        D_80102758_103358[8] = set;
    }
    if (func_8004E94C_4F54C() == 1) {
        for (i = 0; i < 5; i++) {
            if (D_801136F0_3CEE50_name_60[set][i] == 3) {
                break;
            }
        }
        if (i < 5) {
            if (set == 1) {
                D_801136F0_3CEE50_name_60[set][i] = 0;
            } else {
                D_801136F0_3CEE50_name_60[set][i] = 8;
            }
        }
    }
copy:
    i = 0;
    do {
        D_800CAFD8[i] = D_801136F0_3CEE50_name_60[set][i];
        i++;
    } while (i < 5);
    func_8010879C_3C3EFC_name_60(player, set);
}

void func_80108AEC_3C424C_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800FA640_FB240[i] = func_80027154_27D54(0xAC, 0x7918);
        func_800B0EF0_B1AF0(D_800FA640_FB240[i], 0, 0xAC);
    }
    D_800FC890_FD490 = func_80027154_27D54(0x38, 0x7918);
    func_800B0EF0_B1AF0(D_800FC890_FD490, 0, 0x38);
    func_80102830_3BDF90_name_60();
}

#ifdef NON_MATCHING
s32 func_80108B80_3C42E0_name_60(s32 player, s32 btn) {
    s32 ret = 0;

    _CheckFlag(0x15);
    if (!(gPlayers[player].flags & 1) && !(D_800F9910_FA510 & 1)) {
        ret = ContBtnTrg[gPlayers[player].port] & btn;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80108B80_3C42E0_name_60);
#endif

#ifdef NON_MATCHING
s32 func_80108C24_3C4384_name_60(s32 player, s32 btn) {
    s32 ret = 0;

    if (!(gPlayers[player].flags & 1) && !(D_800F9910_FA510 & 1)) {
        ret = ContBtn[gPlayers[player].port] & btn;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80108C24_3C4384_name_60);
#endif

s32 func_80108C8C_3C43EC_name_60(s32 player, s32 axis) {
    s32 ret = 0;
    u8* data;

    if (!(gPlayers[player].flags & 1) && !(D_800F9910_FA510 & 1)) {
        data = D_800FA640_FB240[player];
        if (axis == 0) {
            if (!(*(u16*)(data + 0x30) & 0x40)) {
                ret = ContStkX[gPlayers[player].port];
            }
        } else if (!(*(u16*)(data + 0x30) & 0x80)) {
            ret = ContStkY[gPlayers[player].port];
        }
    }
    return ret;
}

void func_80108D50_3C44B0_name_60(omObjData* obj) {
    Ovl60Attach* hook;

    if (--obj->work[0] == 0xFF) {
        hook = obj->unk_50;
        func_800298A4_2A4A4(hook->model, 4, 0);
        func_800298A4_2A4A4(hook->model, 0x4000, 0x4000);
        func_8002C628_2D228(hook->model, hook->parent, hook->hook);
        omDelObj(obj);
    }
}

f32 func_80108DCC_3C452C_name_60(f32* angle, f32* pos, f32 scale) {
    f32 a;

    a = *angle;
    if (D_800BF7D4_C03D4 < a) {
        a = D_800BF7D4_C03D4;
    }
    *pos = *pos + a * a * (a >= 0.0f ? -35.0f : 35.0f) * scale;
    *angle = *angle + D_800BF7A8_C03A8;
    return a;
}

void func_80108E50_3C45B0_name_60(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[player];
    f32 a;
    s32 t;

    switch (obj->work[1]) {
    case 0:
        func_8002C9C0_2D5C0(p->model, p->mot[4]);
        p->vy = -D_800BF7A4_C03A4;
        obj->work[1] = 1;
        break;
    case 1:
        a = func_80108DCC_3C452C_name_60(&p->vy, &p->pos.y, p->scale);
        if (p->pos.y <= p->unk2C) {
            p->pos.y = p->unk2C;
            func_8002C9C0_2D5C0(p->model, p->mot[8]);
            p->count = func_80029D0C_2A90C(p->model);
            obj->work[1] = 2;
            break;
        }
        t = func_80029CE4_2A8E4(p->model);
        if (t > 5.0f && t < 7.0f) {
            if (!(ContBtn[gPlayers[player].port] & 0x8000) & (a < 0.0f)) {
                p->vy = -D_800BF7A4_C03A4 * 0.2f;
            }
        } else {
            if ((p->flags & 8) && func_80108B80_3C42E0_name_60(player, 0x2000) != 0) {
                p->vy = -D_800BF7A4_C03A4 * 0.1f;
                func_8002C9C0_2D5C0(p->model, p->mot[6]);
                obj->work[1] = 4;
            }
            if ((p->flags & 0x20) && func_80108B80_3C42E0_name_60(player, 0x4000) != 0) {
                p->vy = -D_800BF7A4_C03A4 * 0.1f;
                func_8002C9C0_2D5C0(p->model, p->mot[5]);
                obj->work[1] = 7;
            }
        }
        break;
    case 2:
        if ((f32)p->count <= func_80029CE4_2A8E4(p->model)) {
            func_80029BF0_2A7F0(p->model, p->mot[0], 0, 10, 2);
            obj->work[1] = 10;
        }
        break;
    case 4:
        a = func_80029CE4_2A8E4(p->model);
        if (func_80029D0C_2A90C(p->model) <= a) {
            obj->work[1] = 5;
        }
        break;
    case 5:
        func_80108DCC_3C452C_name_60(&p->vy, &p->pos.y, p->scale);
        if (p->pos.y <= p->unk2C) {
            p->pos.y = p->unk2C;
            p->vy = -D_800BF7A4_C03A4 * 0.6f;
            obj->work[1] = 6;
        }
        break;
    case 6:
        func_80108DCC_3C452C_name_60(&p->vy, &p->pos.y, p->scale);
        if (p->pos.y <= p->unk2C) {
            p->pos.y = p->unk2C;
            func_8002C9C0_2D5C0(p->model, p->mot[7]);
            p->count = func_80029D0C_2A90C(p->model);
            obj->work[1] = 2;
        }
        break;
    case 7:
        a = func_80029CE4_2A8E4(p->model);
        if (func_80029D0C_2A90C(p->model) <= a) {
            func_80029BF0_2A7F0(p->model, p->mot[4], 0, 20, 0);
            obj->work[1] = 8;
        }
        break;
    case 8:
        func_80108DCC_3C452C_name_60(&p->vy, &p->pos.y, p->scale);
        if (p->pos.y <= p->unk2C) {
            p->pos.y = p->unk2C;
            func_8002C9C0_2D5C0(p->model, p->mot[8]);
            p->count = func_80029D0C_2A90C(p->model);
            obj->work[1] = 2;
        }
        break;
    case 10:
        obj->work[1] = 100;
        break;
    }
}

void func_801092B0_3C4A10_name_60(omObjData* obj) {
    Ovl60Player* p = D_800FA640_FB240[obj->work[0]];

    switch (obj->work[1]) {
    case 0:
        func_8002C9C0_2D5C0(p->model, p->mot[3]);
        p->count = func_80029D0C_2A90C(p->model);
        obj->work[1] = 1;
        break;
    case 1:
        if ((f32)p->count <= func_80029CE4_2A8E4(p->model)) {
            func_80029BF0_2A7F0(p->model, p->mot[0], 0, 10, 2);
            obj->work[1] = 100;
        }
        break;
    }
}

void func_8010938C_3C4AEC_name_60(s32 i) {
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];

    model->pos.x = p->pos.x;
    model->pos.y = p->pos.y;
    model->pos.z = p->pos.z;
}

void func_801093D4_3C4B34_name_60(s32 i) {
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];

    p->pos.x = model->pos.x;
    p->pos.y = model->pos.y;
    p->pos.z = model->pos.z;
    p->unk2C = p->pos.y;
}

void func_80109424_3C4B84_name_60(s32 i) {
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];

    model->rot.x = p->rot.x;
    model->rot.y = p->rot.y;
    model->rot.z = p->rot.z;
}

void func_8010946C_3C4BCC_name_60(s32 i) {
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];

    p->rot.x = model->rot.x;
    p->rot.y = model->rot.y;
    p->rot.z = model->rot.z;
}

void func_801094B4_3C4C14_name_60(s32 i) {
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];

    model->scale.x = model->scale.y = model->scale.z = p->scale;
}

void func_801094F4_3C4C54_name_60(s32 i, s32 group) {
    Ovl60Demo* demo;
    Ovl60Player* p;
    s32 chr;
    s32 dir;
    omObjData* obj;

    func_8000C460_D060();
    demo = &D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]];
    p = D_800FA640_FB240[i];
    if (group == 0) {
        p->flags = demo->unk10;
    } else {
        p->flags = demo->unk12;
    }
    chr = gPlayers[i].character;
    p->model = func_80018A30_19630(D_800CD438_CE038[chr].dir | D_800CD438_CE038[chr].model, 0x69D);
    dir = D_800CD438_CE038[gPlayers[i].character].dir;
    if (p->flags & 0x100) {
        p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 8), 0x1D);
    } else {
        p->mot[0] = D_800FC834_FD434[p->model].unk02;
    }
    p->mot[9] = func_8002C8B8_2D4B8(DataRead((p->flags & 0x100) ? dir | 0x16 : dir | 0x41), 0x1D);
    p->mot[10] = func_8002C8B8_2D4B8(DataRead(dir | 0x25), 0x1D);
    if (p->flags & 1) {
        if (p->flags & 0x100) {
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_80113B90_3CF2F0_name_60[chr] | 0x460000), 0x1D);
        } else {
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(dir | 1), 0x1D);
        }
    }
    if (p->flags & 2) {
        p->mot[2] = func_8002C8B8_2D4B8(DataRead(dir | 2), 0x1D);
    }
    if (p->flags & 0x10) {
        p->mot[3] = func_8002C8B8_2D4B8(DataRead(dir | 3), 0x1D);
    }
    if (p->flags & 4) {
        p->mot[4] = func_8002C8B8_2D4B8(DataRead(dir | 4), 0x1D);
        p->mot[8] = func_8002C8B8_2D4B8(DataRead(dir | 0x2E), 0x1D);
        if (p->flags & 8) {
            p->mot[6] = func_8002C8B8_2D4B8(DataRead(dir | 6), 0x1D);
            p->mot[7] = func_8002C8B8_2D4B8(DataRead(dir | 0x10), 0x1D);
        }
        if (p->flags & 0x20) {
            p->mot[5] = func_8002C8B8_2D4B8(DataRead(dir | 5), 0x1D);
        }
    }
    func_8002C9C0_2D5C0(p->model, p->mot[9]);
    func_80029E80_2AA80(p->model, 0, 2);
    p->unk32 = 1;
    p->count = i;
    p->pos.x = p->pos.z = 0.0f;
    p->pos.y = -1000.0f;
    p->rot.x = p->rot.y = p->rot.z = 0.0f;
    p->scale = 0.5f;
    p->unk2C = 0.0f;
    func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
    func_800297E8_2A3E8(p->model, p->scale, p->scale, p->scale);
    func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
    /* func_80108E50 is an object function; 5F-B owns its prototype */
    if (p->flags & 4) {
        p->actA = func_80108E50_3C45B0_name_60;
    } else {
        p->actA = NULL;
    }
    if (p->flags & 0x10) {
        p->actB = func_801092B0_3C4A10_name_60;
    } else {
        p->actB = NULL;
    }
    obj = omAddObj(0x64, 0, 0, -1, demo->unk08);
    obj->work[0] = i;
    obj->work[1] = 0;
    obj->work[2] = 0;
    omAddObj(0x7D00, 0, 0, -1, func_80109FA0_3C5700_name_60)->work[0] = i;
}

void func_801098FC_3C505C_name_60(void) {
    s32 i;
    s32 type;

    type = D_80114AC0_3D0220_name_60;
    for (i = 0; i < 4; i++) {
        switch (type) {
        case 0:
        case 3:
            func_801094F4_3C4C54_name_60(i, 0);
            break;
        default:
            func_801094F4_3C4C54_name_60(i, gPlayers[i].group);
            break;
        }
    }
}

void func_80109988_3C50E8_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Ovl60Player* p = D_800FA640_FB240[i];

        if (p->unk32 & 1) {
            func_80029BF0_2A7F0(p->model, p->mot[0], 0, 5, 2);
        }
    }
}

void func_80109A04_3C5164_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Ovl60Player* p = D_800FA640_FB240[i];

        if (p->unk32 & 1) {
            func_80029BF0_2A7F0(p->model, p->mot[10], 0, 5, 2);
        }
    }
}

void func_80109A80_3C51E0_name_60(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[i];
    Ovl60Demo* demo = &D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]];
    omObjData* act = D_80113B80_3CF2E0_name_60[i];

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        omObjData* end = omAddObj(10, 0, 0, -1, demo->unk0C);

        end->work[0] = i;
        end->work[1] = 0;
        if (act != NULL) {
            omDelObj(act);
        }
        omDelObj(obj);
    } else if (obj->work[1] == 2) {
        if (act->work[1] == 100) {
            omDelObj(act);
            D_80113B80_3CF2E0_name_60[i] = NULL;
            obj->work[1] = 1;
        }
    } else {
        if (p->flags & 1) {
            if (OVL60_STICK_ABS(i, 0) > 10.0f || OVL60_STICK_ABS(i, 1) > 10.0f) {
                p->rot.y = func_800B75A8_B81A8(func_80108C8C_3C43EC_name_60(i, 0), -func_80108C8C_3C43EC_name_60(i, 1));
            }
            if (OVL60_STICK_ABS(i, 0) > 30.0f || OVL60_STICK_ABS(i, 1) > 30.0f) {
                if (p->flags & 2) {
                    if (obj->work[2] != 2) {
                        obj->work[2] = 2;
                        func_80029BF0_2A7F0(p->model, p->mot[2], 0, 5, 2);
                    }
                } else if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_80029BF0_2A7F0(p->model, p->mot[1], 0, 5, 2);
                }
            } else if (OVL60_STICK_ABS(i, 0) > 10.0f || OVL60_STICK_ABS(i, 1) > 10.0f) {
                if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_80029BF0_2A7F0(p->model, p->mot[1], 0, 5, 2);
                }
            } else if (obj->work[2] != 0) {
                obj->work[2] = 0;
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 5, 2);
            }
        }
        if (func_80108B80_3C42E0_name_60(i, 0x8000) && p->actA != NULL) {
            act = D_80113B80_3CF2E0_name_60[i] = omAddObj(10, 0, 0, -1, p->actA);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        } else if (func_80108B80_3C42E0_name_60(i, 0x4000) && p->actB != NULL) {
            act = D_80113B80_3CF2E0_name_60[i] = omAddObj(10, 0, 0, -1, p->actB);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        }
    }
}

void func_80109FA0_3C5700_name_60(omObjData* obj) {
    s32 i = obj->work[0];

    func_801094B4_3C4C14_name_60(i);
    if (D_800FC8A0_FD4A0 == 0) {
        func_801093D4_3C4B34_name_60(i);
        func_8010946C_3C4BCC_name_60(i);
    } else {
        func_8010938C_3C4AEC_name_60(i);
        func_80109424_3C4B84_name_60(i);
    }
}

void func_8010A000_3C5760_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104E98_3C05F8_name_60(i);
    }
}

void func_8010A038_3C5798_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3C0508_name_60(i, 3, i * 60.0f - 100.0f, -50.0f, -80.0f);
    }
}

void func_8010A0C4_3C5824_name_60(void) {
    s32 i;
    s32 n;

    for (i = 0, n = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3C0508_name_60(i, 4, 0.0f, -50.0f, -80.0f);
        } else {
            func_80104DA8_3C0508_name_60(i, 3, n * 60.0f - 100.0f, -50.0f, -80.0f);
            n++;
        }
    }
}

void func_8010A1A0_3C5900_name_60(void) {
    s32 i;
    s32 n0;
    s32 n1;

    for (i = 0, n1 = 0, n0 = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3C0508_name_60(i, 3, n0 * 60.0f - 100.0f, -50.0f, -80.0f);
            n0++;
        } else {
            func_80104DA8_3C0508_name_60(i, 4, n1 * 60.0f + -50.0f, -50.0f, -80.0f);
            n1++;
        }
    }
}

void func_8010A2B0_3C5A10_name_60(void) {
    D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].unk04();
}

void func_8010A2EC_3C5A4C_name_60(omObjData* obj) {
    Vec dir;
    s32 i = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[i];

    switch (obj->work[1]) {
    case 0:
        HuVecCopyXYZ(&dir, p->pos.x, 0.0f, p->pos.y);
        p->angle = func_800B75A8_B81A8(dir.x, dir.z);
        p->count = 7;
        p->vel = (p->angle - p->rot.z) / 7.0f;
        obj->work[1] = 1;
        break;
    case 1:
        p->pos.x += HuMathSin(p->angle) * 20.0f;
        p->pos.y += func_800B7890_B8490(p->angle) * 20.0f;
        p->rot.y += 20.0f;
        func_8010938C_3C4AEC_name_60(i);
        if (p->count != 0) {
            p->count--;
            p->rot.z -= p->vel;
        }
        if (p->pos.y < -600.0f) {
            func_800298A4_2A4A4(p->model, 4, 4);
            omDelObj(obj);
        }
        break;
    }
}

void func_8010A45C_3C5BBC_name_60(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        Ovl60Player* p = D_800FA640_FB240[i];

        p->model = -1;
        p->flags = 0;
        p->unk32 = 0;
        for (j = 0; j < 11; j++) {
            p->mot[j] = -1;
        }
    }
    D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].setup();
}

void func_8010A4F0_3C5C50_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3C0508_name_60(i, 3, i * 60.0f - 100.0f, 0.0f, -80.0f);
    }
}

void func_8010A580_3C5CE0_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3C0508_name_60(i, 3, i * 60.0f - 100.0f, -20.0f, -80.0f);
    }
}

/* Demo setup: each character model (motion 0x15 of its directory) with a form model (blue for
   group 0's players, red for the rest) shrunk under it. */
void func_8010A60C_3C5D6C_name_60(void) {
    s32 i;
    s32 dir;
    Ovl60Player* p;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        dir = D_800CD438_CE038[gPlayers[i].character].dir;
        p = D_800FA640_FB240[i];
        p->model = func_80018A30_19630(dir | D_800CD438_CE038[gPlayers[i].character].model, 0xA9D);
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
        p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 0x15), 0x1D);
        func_8002C9C0_2D5C0(p->model, p->mot[0]);
        func_80029E80_2AA80(p->model, 0, 1);
        p->model2 = func_80018A30_19630(gPlayers[i].group != 0 ? 0x2B0003 : 0x2B0004, 0x1088D);
        HmfModelObjAttrSet(p->model2, 0x600, 0x600);
        func_8002CD78_2D978(p->model2, 0, 0, 0, 0);
        func_8002CDB4_2D9B4(p->model2, 0, 0, 0, 0);
        func_80029A8C_2A68C(p->model2);
        func_80029AFC_2A6FC(p->model2);
        func_800297E8_2A3E8(p->model2, 0.5f, 0.5f, 0.5f);
        func_80029E80_2AA80(p->model2, 0, 1);
        p->count = 0;
        p->vel = 0.0f;
        obj = omAddObj(0x7D00, 0, 0, -1, D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].unk08);
        obj->work[0] = i;
        obj->work[1] = 0;
    }
}

/* Demo player: the form model follows the character; A plays the character's motion forward
   (both models), B or Z back; while it stands still the form blinks. */
void func_8010A834_3C5F94_name_60(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* m = &D_800FC834_FD434[p->model];
    omObjData* end;

    func_800298A4_2A4A4(p->model2, 4, 0);
    func_80029714_2A314(p->model2, m->pos.x, m->pos.y, m->pos.z + 50.0f);
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        end = omAddObj(10, 0, 0, -1, D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].unk0C);
        end->work[0] = i;
        end->work[1] = 0;
        p->pos.x = m->pos.x;
        p->pos.y = m->pos.y;
        p->pos.z = m->pos.z;
        p->rot.x = m->rot.x;
        p->rot.y = m->rot.y;
        p->rot.z = m->rot.z;
    } else {
        if (p->vel == 0.0f) {
            p->count = p->count == 0;
            if (p->count) {
                func_8002CD78_2D978(p->model2, 0x40, 0x40, 0x40, 0);
                func_8002CDB4_2D9B4(p->model2, 0, 0, 0, 0);
            } else {
                func_8002CD78_2D978(p->model2, 0, 0, 0, 0);
                func_8002CDB4_2D9B4(p->model2, 0x10, 0x10, 0x10, 0);
            }
        } else {
            func_8002CD78_2D978(p->model2, 0, 0, 0, 0);
            func_8002CDB4_2D9B4(p->model2, 0, 0, 0, 0);
        }
        if (func_80108C24_3C4384_name_60(i, 0x8000)) {
            p->vel += 2.0f;
            if (func_80029D0C_2A90C(p->model) - 2.0f < p->vel) {
                p->vel = func_80029D0C_2A90C(p->model) - 2.0f;
            }
            func_80029C74_2A874(p->model, p->vel);
            func_80029C74_2A874(p->model2, p->vel);
        }
        if (func_80108C24_3C4384_name_60(i, 0x4000) || func_80108C24_3C4384_name_60(i, 0x2000)) {
            p->vel -= 2.0f;
            if (p->vel < 0.0f) {
                p->vel = 0.0f;
            }
            func_80029C74_2A874(p->model, p->vel);
            func_80029C74_2A874(p->model2, p->vel);
        }
    }
}

/* Rider 0 of a team demo: the stick (clamped to +-10) accelerates its speed, which decays by 0.9
   when the stick is released or overshot; the speed (+-9.5 at most) sets model2's and the form's
   motion speed and the vehicle's yaw and roll. */
void func_8010AB44_3C62A4_name_60(Ovl60TeamDemo* p, f32 stick) {
    f32 t = stick * 10.0f;
    f32 v;

    if (t > 10.0f) {
        t = 10.0f;
    }
    if (t < -10.0f) {
        t = -10.0f;
    }
    if (t != 0.0f) {
        p->vel += t * 0.05f;
        if (p->vel > 0.0f) {
            if (p->vel > t) {
                p->vel *= 0.9f;
            }
        } else if (p->vel < t) {
            p->vel *= 0.9f;
        }
    } else {
        p->vel *= 0.9f;
    }
    t = p->vel;
    if (p->vel >= 9.0f) {
        t = 9.5f;
    }
    if (p->vel <= -9.0f) {
        t = -9.5f;
    }
    v = 10.0f - t;
    func_80029C74_2A874(p->model2, v);
    func_80029C74_2A874(p->form[0], v);
    p->rot.y = 20.0f - v * 20.0f / 10.0f;
    p->rot.z = v * 10.0f / 10.0f + -10.0f;
}

/* Rider 1 of a team demo: as func_8010AB44 with twice the stick, on vel2, model3 and the
   vehicle's pitch. */
void func_8010AD2C_3C648C_name_60(Ovl60TeamDemo* p, f32 stick) {
    f32 t = stick * 20.0f;
    f32 v;

    if (t > 10.0f) {
        t = 10.0f;
    }
    if (t < -10.0f) {
        t = -10.0f;
    }
    if (t != 0.0f) {
        p->vel2 += t * 0.05f;
        if (p->vel2 > 0.0f) {
            if (p->vel2 > t) {
                p->vel2 *= 0.9f;
            }
        } else if (p->vel2 < t) {
            p->vel2 *= 0.9f;
        }
    } else {
        p->vel2 *= 0.9f;
    }
    t = p->vel2;
    if (p->vel2 >= 9.0f) {
        t = 9.5f;
    }
    if (p->vel2 <= -9.0f) {
        t = -9.5f;
    }
    v = 10.0f - t;
    func_80029C74_2A874(p->model3, v);
    p->rot.x = 20.0f - v * 20.0f / 10.0f;
}

/* The vehicle of a team demo: its motion speed follows the stick (clamped to +-1), 0 to 20. */
void func_8010AEF4_3C6654_name_60(Ovl60TeamDemo* p, f32 stick) {
    f32 speed;
    f32 d;

    if (stick > 1.0f) {
        stick = 1.0f;
    }
    if (stick < -1.0f) {
        stick = -1.0f;
    }
    speed = func_80029CE4_2A8E4(p->model);
    d = (stick + 1.0f) * 10.0f - speed;
    if (d > 1.0f) {
        speed += 1.5f;
    } else if (d < -1.0f) {
        speed -= 2.0f;
    }
    if (speed < 0.0f) {
        speed = 0.0f;
    }
    if (speed > 20.0f) {
        speed = 20.0f;
    }
    func_80029C74_2A874(p->model, speed);
    func_80029C74_2A874(p->form[1], speed);
}

/* Team demo setup (two teams of two): per team, the vehicle (model, scale 0.3, yaw 240), its
   two parts and the two riders' forms (by character), every motion at half speed.
   NON_MATCHING: retail loads 0x2C0000 into s4 before the riders' loop (here it stays in the
   loop: masked residue) and keeps the tables in s6/s5. */
#ifdef NON_MATCHING
void func_8010B048_3C67A8_name_60(void) {
    s32 i;
    s32 j;
    Ovl60TeamDemo* p;
    omObjData* obj;
    s32 file;

    for (i = 0; i < 2; i++) {
        p = D_800FA640_FB240[i];
        p->model = func_80018A30_19630(i != 0 ? 0x2C0001 : 0x2C0000, 0xA9D);
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        p->scale = 0.3f;
        func_800297E8_2A3E8(p->model, 0.3f, 0.3f, 0.3f);
        p->rot.x = p->rot.z = 0.0f;
        p->rot.y = 240.0f;
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
        func_80029E80_2AA80(p->model, 0, 1);
        func_80029C74_2A874(p->model, func_80029D0C_2A90C(p->model) / 2.0f);
        p->model2 = func_80018A30_19630(i != 0 ? 0x2C0003 : 0x2C0002, 0xA9D);
        func_8002979C_2A39C(p->model2, p->rot.x, p->rot.y, p->rot.z);
        func_800297E8_2A3E8(p->model2, p->scale, p->scale, p->scale);
        func_80029E80_2AA80(p->model2, 0, 1);
        func_80029C74_2A874(p->model2, func_80029D0C_2A90C(p->model2) / 2.0f);
        p->model3 = func_80018A30_19630(i != 0 ? 0x2C0005 : 0x2C0004, 0xA9D);
        func_8002979C_2A39C(p->model3, p->rot.x, p->rot.y, p->rot.z);
        func_800297E8_2A3E8(p->model3, p->scale, p->scale, p->scale);
        func_80029E80_2AA80(p->model3, 0, 1);
        func_80029C74_2A874(p->model3, func_80029D0C_2A90C(p->model3) / 2.0f);
        for (j = 0; j < 4; j++) {
            if (gPlayers[j].group == i * 2) {
                break;
            }
        }
        p->player[0] = j;
        for (j = 0; j < 4; j++) {
            if (gPlayers[j].group == i * 2 + 1) {
                break;
            }
        }
        p->player[1] = j;
        p->vel = p->vel2 = 0.0f;
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                file = D_80113BB8_3CF318_name_60[gPlayers[p->player[0]].character];
            } else {
                file = D_80113BC4_3CF324_name_60[gPlayers[p->player[1]].character];
            }
            p->form[j] = LoadFormFile(file | 0x2C0000, 0xA9D);
            func_8002979C_2A39C(p->form[j], p->rot.x, p->rot.y, p->rot.z);
            func_800297E8_2A3E8(p->form[j], p->scale, p->scale, p->scale);
            func_80029E80_2AA80(p->form[j], 0, 1);
            /* retail: model3's motion length for both forms */
            func_80029C74_2A874(p->form[j], func_80029D0C_2A90C(p->model3) / 2.0f);
        }
        obj = omAddObj(0x7D00, 0, 0, -1, D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].unk08);
        obj->work[0] = i;
        obj->work[1] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010B048_3C67A8_name_60);
#endif

void func_8010B488_3C6BE8_name_60(void) {
    func_80104DA8_3C0508_name_60(0, 3, -70.0f, 0.0f, -80.0f);
    func_80104DA8_3C0508_name_60(1, 4, -40.0f, 0.0f, -80.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010B4E0_3C6C40_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010B884_3C6FE4_name_60);

void func_8010BAF4_3C7254_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group < 2) {
            func_80104DA8_3C0508_name_60(i, 3, gPlayers[i].group * 60.0f - 100.0f, -25.0f, -80.0f);
        } else {
            func_80104DA8_3C0508_name_60(i, 4, (gPlayers[i].group - 2) * 60.0f + -50.0f, -25.0f, -80.0f);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010BBFC_3C735C_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010BE6C_3C75CC_name_60);

__asm__(".section .rodata");
const char D_8011458C_3CFCEC_name_60[] = "c100_1-atama";

__asm__(".section .rodata");
const char D_8011459C_3CFCFC_name_60[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_801145B0_3CFD10_name_60[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_801145C0_3CFD20_name_60[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_801145D0_3CFD30_name_60[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_801145E8_3CFD48_name_60[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_801145FC_3CFD5C_name_60[12] = "atama_2";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010BFA8_3C7708_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010C284_3C79E4_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010C3A8_3C7B08_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010C634_3C7D94_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010C7F4_3C7F54_name_60);

void func_8010C904_3C8064_name_60(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* m = &D_800FC834_FD434[p->model];
    omObjData* end;

    func_800298A4_2A4A4(p->model2, 4, 0);
    func_800298A4_2A4A4(p->model3, 4, 0);
    func_80029714_2A314(p->model2, m->pos.x, m->pos.y, m->pos.z);
    func_80029714_2A314(p->model3, m->pos.x, m->pos.y, m->pos.z);
    if (obj->work[1] == 12) {
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        end = omAddObj(10, 0, 0, -1, D_80113810_3CEF70_name_60[D_80114A80_3D01E0_name_60[0]].unk0C);
        end->work[0] = i;
        end->work[1] = 0;
    } else {
        if (func_80108C8C_3C43EC_name_60(i, 0) > 10.0f) {
            p->rot.y -= 7.0f;
        }
        if (func_80108C8C_3C43EC_name_60(i, 0) < -10.0f) {
            p->rot.y += 7.0f;
        }
        func_8002979C_2A39C(p->model, 0.0f, p->rot.y, 0.0f);
        func_8002979C_2A39C(p->model2, 0.0f, p->rot.y, 0.0f);
        func_8002979C_2A39C(p->model3, 0.0f, p->rot.y, 0.0f);
    }
}

void func_8010CB10_3C8270_name_60(omObjData* obj) {
    Vec dir;
    s32 i = obj->work[0];
    Ovl60Player* p = D_800FA640_FB240[i];
    HmfModel* m = &D_800FC834_FD434[p->model];

    switch (obj->work[1]) {
    case 0:
        p->pos.x = m->pos.x;
        p->pos.y = m->pos.y;
        p->pos.z = m->pos.z;
        HuVecCopyXYZ(&dir, p->pos.x, 0.0f, p->pos.y);
        p->angle = func_800B75A8_B81A8(dir.x, dir.z);
        p->count = 7;
        p->vel = (p->angle - p->rot.z) / 7.0f;
        obj->work[1] = 1;
        break;
    case 1:
        p->pos.x += HuMathSin(p->angle) * 20.0f;
        p->pos.y += func_800B7890_B8490(p->angle) * 20.0f;
        p->rot.y += 20.0f;
        func_8010938C_3C4AEC_name_60(i);
        if (p->count != 0) {
            p->count--;
            p->rot.z -= p->vel;
        }
        if (p->pos.y < -500.0f) {
            func_800298A4_2A4A4(p->model, 4, 4);
            omDelObj(obj);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010CCB4_3C8414_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010CE78_3C85D8_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010D070_3C87D0_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010D3D0_3C8B30_name_60);

void func_8010D6C0_3C8E20_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3C0508_name_60(i, 3, i * 55.0f - 80.0f, -40.0f, -80.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010D74C_3C8EAC_name_60);

__asm__(".section .rodata");
const char D_80114620_3CFD80_name_60[] = "143tank_kuppa-pipe";

__asm__(".section .rodata");
const char D_80114634_3CFD94_name_60[] = "143tank_kuppa-kat";

__asm__(".section .rodata");
const char D_80114648_3CFDA8_name_60[] = "143tank-bmerge2";

__asm__(".section .rodata");
const char D_80114658_3CFDB8_name_60[] = "143tank-cube8";

__asm__(".section .rodata");
const char D_80114668_3CFDC8_name_60[] = "heiho_mario_head_DEF";

__asm__(".section .rodata");
const char D_80114680_3CFDE0_name_60[] = "heiho_mario_elbow_DEF";

__asm__(".section .rodata");
const char D_80114698_3CFDF8_name_60[] = "heiho_mario_body_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010D994_3C90F4_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010DC98_3C93F8_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010DF64_3C96C4_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010E11C_3C987C_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010E454_3C9BB4_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010E6A0_3C9E00_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010EC90_3CA3F0_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010EDD4_3CA534_name_60);

__asm__(".section .rodata");
const char D_801146C0_3CFE20_name_60[] = "152_01f_DEF";

__asm__(".section .rodata");
const char D_801146CC_3CFE2C_name_60[] = "152_01e_DEF";

__asm__(".section .rodata");
const char D_801146D8_3CFE38_name_60[] = "152_01d_DEF";

__asm__(".section .rodata");
const char D_801146E4_3CFE44_name_60[] = "152_01c_DEF";

__asm__(".section .rodata");
const char D_801146F0_3CFE50_name_60[] = "152_01b_DEF";

__asm__(".section .rodata");
const char D_801146FC_3CFE5C_name_60[] = "152_01a_DEF";

__asm__(".section .rodata");
const char D_80114708_3CFE68_name_60[] = "item_hook";

__asm__(".section .rodata");
const char D_80114714_3CFE74_name_60[] = "m159_05_DEF";

__asm__(".section .rodata");
const char D_80114720_3CFE80_name_60[] = "m159_04_DEF";

__asm__(".section .rodata");
const char D_8011472C_3CFE8C_name_60[] = "m159_03_DEF";

__asm__(".section .rodata");
const char D_80114738_3CFE98_name_60[] = "m159_02_DEF";

__asm__(".section .rodata");
const char D_80114744_3CFEA4_name_60[] = "m159_01_DEF";

__asm__(".section .rodata");
const char D_80114750_3CFEB0_name_60[16] = "m159_00_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010F01C_3CA77C_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010F480_3CABE0_name_60);

void func_8010F63C_3CAD9C_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3C0508_name_60(i, 3, i * 60.0f - 100.0f, -20.0f, -80.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010F6C8_3CAE28_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010FA50_3CB1B0_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010FCC8_3CB428_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_8010FDA8_3CB508_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801100BC_3CB81C_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801102F4_3CBA54_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801105D4_3CBD34_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80110700_3CBE60_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80110858_3CBFB8_name_60);

void func_80110A84_3CC1E4_name_60(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group < 2) {
            func_80104DA8_3C0508_name_60(i, 3, gPlayers[i].group * 90.0f - 100.0f, -50.0f, -80.0f);
        } else {
            func_80104DA8_3C0508_name_60(i, 4, (gPlayers[i].group - 2) * 90.0f + -80.0f, -50.0f, -80.0f);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80110B7C_3CC2DC_name_60);

__asm__(".section .rodata");
const char D_80114780_3CFEE0_name_60[] = "c005_000-bmerge6";

__asm__(".section .rodata");
const char D_80114794_3CFEF4_name_60[] = "c005_000-bmerge4";

__asm__(".section .rodata");
const char D_801147A8_3CFF08_name_60[] = "Luigi1-migi-te1_1";

__asm__(".section .rodata");
const char D_801147BC_3CFF1C_name_60[] = "Luigi1-migi-te1_2";

__asm__(".section .rodata");
const char D_801147D0_3CFF30_name_60[] = "c003_000-bmerge1_8";

__asm__(".section .rodata");
const char D_801147E4_3CFF44_name_60[] = "c003_000-bmerge1_13_1";

__asm__(".section .rodata");
const char D_801147FC_3CFF5C_name_60[] = "C002_000b-bmerge16";

__asm__(".section .rodata");
const char D_80114810_3CFF70_name_60[] = "C002_000b-bmerge14";

__asm__(".section .rodata");
const char D_80114824_3CFF84_name_60[] = "c001_000-migi-te2_3";

__asm__(".section .rodata");
const char D_80114838_3CFF98_name_60[] = "c001_000-migi-te2_2";

__asm__(".section .rodata");
const char D_8011484C_3CFFAC_name_60[] = "migi-te3_2_1";

__asm__(".section .rodata");
const char D_8011485C_3CFFBC_name_60[] = "migi-te2_4";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80110DA8_3CC508_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80110F7C_3CC6DC_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80111228_3CC988_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80111430_3CCB90_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801116F0_3CCE50_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_801118C8_3CD028_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80111A90_3CD1F0_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80111BCC_3CD32C_name_60);

void func_80112100_3CD860_name_60(void) {
    func_80104DA8_3C0508_name_60(0, 3, -70.0f, 0.0f, -80.0f);
    func_80104DA8_3C0508_name_60(1, 4, -40.0f, 0.0f, -80.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80112158_3CD8B8_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80112610_3CDD70_name_60);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3BDF90", func_80112818_3CDF78_name_60);

void func_80112B8C_3CE2EC_name_60(void) {
    func_8010A2B0_3C5A10_name_60();
}

void func_80112BA8_3CE308_name_60(void) {
    func_80109988_3C50E8_name_60();
}

void func_80112BC4_3CE324_name_60(void) {
    func_80109A04_3C5164_name_60();
}

void func_80112BE0_3CE340_name_60(void) {
    D_80114A80_3D01E0_name_60[0] = D_80114AC4_3D0224_name_60 - 29;
    func_8010A45C_3C5BBC_name_60();
}
