#include "common.h"
#include "ovl_5F.h"

void func_80102830_3AB9D0_name_5F(void) {
    s32 temp_s0;
    s32 i;

    func_80102A14_3ABBB4_name_5F();
    if (GwSystem.unk_25 == 1) {
        func_801085A0_3B1740_name_5F(0);
        return;
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 6:
    case 7:
        func_801085A0_3B1740_name_5F(0);
        return;
    }
    
    PlayMusic(0x16);
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, func_80079E60_7AA60), 0xA0U);
    func_80018E30_19A30(1);
    temp_s0 = func_80018E78_19A78();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 10.0f, 500.0f, 5000.0f);
    D_800FA610_FB210 = 2500.0f;
    D_800FD474_FE074.x = 0.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = 0.0f;
    func_80102AF0_3ABC90_name_5F();
    omAddPrcObj(&func_80105B94_3AED34_name_5F, 0x1001U, 0x800, 0);
    
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    
    D_80114DC4_3BDF64_name_5F = D_80114F70_3BE110_name_5F = i;
    InitFadeIn(0, 0x10);
}

void func_80102A14_3ABBB4_name_5F(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x32, 0x14);
    func_80088640_89240();
    D_80102708_103308 = 1;
    D_800FC8A0_FD4A0 = 0;
    D_800F9910_FA510 = 0;
    D_80114E4A_3BDFEA_name_5F = 0;
    D_80114DC0_3BDF60_name_5F = D_80114F74_3BE114_name_5F = GwSystem.chosenMinigameIndex - 1;
    D_80114DC2_3BDF62_name_5F = D_80114F72_3BE112_name_5F = D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_04;
    if (_CheckFlag(0xC) != 0) {
        func_801136C4_3BC864_name_5F(D_80114DC0_3BDF60_name_5F);
    } else {
        func_80108170_3B1310_name_5F();
        func_80108458_3B15F8_name_5F();
    }
}

/* NON_MATCHING: register allocation only (the first switch's value is in s1, retail s0 with an
   andi copy to s1). */
#ifdef NON_MATCHING
void func_80102AF0_3ABC90_name_5F(void) {
    void* file;
    s32 j;
    s32 i;

    D_80114E10_3BDFB0_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0011), 0, 0);
    espPosSet(D_80114E10_3BDFB0_name_5F, 160, 120);
    func_8001A708_1B308(D_80114E10_3BDFB0_name_5F, 0x4000);
    func_8001A6BC_1B2BC(D_80114E10_3BDFB0_name_5F, 0);
    D_80114DC8_3BDF68_name_5F[0] = func_80018A30_19630(0xB000E, 0xA8D);
    func_8002D124_2DD24(D_80114DC8_3BDF68_name_5F[0]);
    func_8002D0A0_2DCA0(D_80114DC8_3BDF68_name_5F[0], 0x80);
    j = 0;
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[0]);
    switch (D_80114DC2_3BDF62_name_5F) {
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
        if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
            j = 1;
        }
        break;
    }
    D_80114DC8_3BDF68_name_5F[1] = func_80018A30_19630((u16)j | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[1]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[1]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[1]);
    D_80114DC8_3BDF68_name_5F[2] = func_80018A30_19630(((u16)j + 5) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[2], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[2]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[2]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[2]);
    i = 0;
    D_80114E18_3BDFB8_name_5F = func_80018A30_19630(0xB000A, 0xA9D);
    func_80029E80_2AA80(D_80114E18_3BDFB8_name_5F, 0, 2);
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        i = 2;
        break;
    case 4:
        i = 1;
        break;
    }
    D_80114DC8_3BDF68_name_5F[3] = func_80018A30_19630(((u16)i + 0xB) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[3], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[3]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[3]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[3]);
    D_80114DC8_3BDF68_name_5F[4] = func_80018A30_19630(0xB000B, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[4], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[4]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[4]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[4]);
    if (D_80114DC2_3BDF62_name_5F < 3) {
        if (D_80114DC2_3BDF62_name_5F > 0) {
            if (D_80114DC0_3BDF60_name_5F != 0x21) {
                D_80114DC8_3BDF68_name_5F[5] = func_80018A30_19630(0xB000B, 0xA8D);
                HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[5], 0x20000, 0x20000);
                func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[5]);
                func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[5]);
                func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[5]);
            }
        }
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x800A6, 0xAAD);
        D_80114E20_3BDFC0_name_5F[0] = D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].unk02;
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x800AA), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x800AB), 0x1D);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800AE);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c164m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        D_80114E2C_3BDFCC_name_5F = func_80018A30_19630(0xB0010, 0xA9D);
        func_8002979C_2A39C(D_80114E2C_3BDFCC_name_5F, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(D_80114E2C_3BDFCC_name_5F, 0.8f, 0.8f, 0.8f);
        func_801049F4_3ADB94_name_5F();
        break;
    case 4:
        D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x800A3, 0xAAD);
        D_80114E20_3BDFC0_name_5F[0] = D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].unk02;
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x80093), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x80091), 0x1D);
        D_80114E20_3BDFC0_name_5F[3] = func_8002C8B8_2D4B8(DataRead(0x8008E), 0x1D);
        D_80114E20_3BDFC0_name_5F[4] = func_8002C8B8_2D4B8(DataRead(0x800A1), 0x1D);
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[1]);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800A4);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c103m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        break;
    default:
        if (_CheckFlag(0xC) != 0) {
            D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x80035, 0xAAD);
        } else {
            D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x80000, 0xAAD);
        }
        D_80114E20_3BDFC0_name_5F[0] = func_8002C8B8_2D4B8(DataRead(0x8002C), 0x1D);
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x8002D), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x8002E), 0x1D);
        D_80114E20_3BDFC0_name_5F[3] = func_8002C8B8_2D4B8(DataRead(0x8002F), 0x1D);
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[0]);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x80039);
        if (_CheckFlag(0xC) != 0) {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c180n_0_DEF");
        } else {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c160n_0_DEF");
        }
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
            D_80114E2C_3BDFCC_name_5F = func_80018A30_19630(0xB0012, 0xA9D);
        }
        break;
    }
    D_80114E2A_3BDFCA_name_5F = func_80018A30_19630(0xB000F, 0xA8D);
    i = D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_06 & 0xFFF;
    if ((D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_06 >> 15) == 1) {
        i += D_800FA656 * 2;
    }
    D_80114E4C_3BDFEC_name_5F = DataRead((u16)i | 0xB0000);
    D_80114E54_3BDFF4_name_5F = DataRead(((u16)i + 1) | 0xB0000);
    D_80114E50_3BDFF0_name_5F = DataRead(0xB0024);
    func_801072C8_3B0468_name_5F(D_80114E2A_3BDFCA_name_5F, D_80114E54_3BDFF4_name_5F, D_80114E4C_3BDFEC_name_5F, D_80114E50_3BDFF0_name_5F);
    D_80114E3C_3BDFDC_name_5F = func_8008DFC4_8EBC4(0x48, 0xBC, 4);
    func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk29 = 0;
    D_80114E3E_3BDFDE_name_5F[0] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0013, 0x37, -0x28, 0);
    D_80114E3E_3BDFDE_name_5F[1] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0017, 0x37, -0x28, 0);
    D_80114E3E_3BDFDE_name_5F[2] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0021, 0x82, -0x28, 0);
    if (func_80105A14_3AEBB4_name_5F() != 0) {
        D_80114E3E_3BDFDE_name_5F[3] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0022, 0xBE, -0x28, 0);
    }
    D_80114E12_3BDFB2_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001D), 0, 1);
    espDispOff(D_80114E12_3BDFB2_name_5F);
    D_80114E14_3BDFB4_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001E), 0, 1);
    func_8001A96C_1B56C(D_80114E14_3BDFB4_name_5F, 0, 0, 0x80);
    espDispOff(D_80114E14_3BDFB4_name_5F);
    D_80114E16_3BDFB6_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0021), 0, 1);
    espDispOff(D_80114E16_3BDFB6_name_5F);
    D_80114E1A_3BDFBA_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900FA), 0, 1);
    espDispOff(D_80114E1A_3BDFBA_name_5F);
    D_80114E1C_3BDFBC_name_5F = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80102AF0_3ABC90_name_5F);
#endif

void func_8010352C_3AC6CC_name_5F(omObjData* obj) {
    Ovl5FFallWork* work = obj->unk_50;

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

void func_80103608_3AC7A8_name_5F(omObjData* obj) {
    Ovl5FFallWork* work = obj->unk_50;

    if (obj->work[0] == 0) {
        work->model = func_80027D3C_2893C(D_80114DC8_3BDF68_name_5F[0]);
    } else {
        work->model = D_80114DC8_3BDF68_name_5F[obj->work[0]];
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
    obj->func_ptr = func_8010352C_3AC6CC_name_5F;
}

void func_80103778_3AC918_name_5F(omObjData* obj) {
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

void func_8010382C_3AC9CC_name_5F(omObjData* obj) {
    s32 alpha;

    alpha = (obj->work[0]++ * 255) / obj->work[1];
    if (obj->work[1] < obj->work[0]) {
        alpha = 255;
    }
    func_8001A6BC_1B2BC(D_80114E10_3BDFB0_name_5F, alpha);
    if (alpha == 255) {
        omDelObj(obj);
    }
}

void func_801038D4_3ACA74_name_5F(omObjData* obj) {
    if ((u16)func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_80113978_3BCB18_name_5F += 0.3f;
    }
    if (D_80113978_3BCB18_name_5F > 48.0f) {
        D_80113978_3BCB18_name_5F = -48.0f;
    }
    func_8002BED4_2CAD4(D_80114DC8_3BDF68_name_5F[1], D_80113978_3BCB18_name_5F, 0.0f, 48, 40, "normal_title2-face3", 0);
}

void func_80103994_3ACB34_name_5F(omObjData* obj) {
    Ovl5FHostWork* work = D_800FC890_FD490;
    HmfModel* model;
    Vec v;

    switch (obj->work[1]) {
    case 0:
        work->model = D_80114E1E_3BDFBE_name_5F;
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
            func_800298A4_2A4A4(D_80114E1E_3BDFBE_name_5F, 4, 4);
            omDelObj(obj);
        }
        break;
    }
    func_80029714_2A314(D_80114E1E_3BDFBE_name_5F, work->pos.x, work->pos.y, work->pos.z);
    func_8002979C_2A39C(D_80114E1E_3BDFBE_name_5F, work->rot.x, work->rot.y, work->rot.z);
}

void func_80103B78_3ACD18_name_5F(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[D_80114E2C_3BDFCC_name_5F];
    Vec v;
    f32 angle;

    HuVecCopyXYZ(&v, model->pos.x, 0.0f, model->pos.y);
    angle = func_800B75A8_B81A8(v.x, v.z);
    func_80029714_2A314(D_80114E2C_3BDFCC_name_5F, HuMathSin(angle) * 20.0f + model->pos.x,
                        func_800B7890_B8490(angle) * 20.0f + model->pos.y, model->pos.z);
    if (model->pos.y < -700.0f) {
        func_800298A4_2A4A4(D_80114E2C_3BDFCC_name_5F, 4, 4);
        omDelObj(obj);
    }
}

/* NON_MATCHING: control flow and register allocation differ (frame 56 vs 48); the logic follows the asm */
#ifdef NON_MATCHING
void func_80103C84_3ACE24_name_5F(s16 win, s32 page) {
    s16 extra;
    s16 mes;
    s32 last;
    s32 i;
    s32 n;

    extra = D_80113710_3BC8B0_name_5F[D_80114DC0_3BDF60_name_5F][2];
    if (extra == -1 || _CheckFlag(0xC) != 0) {
        last = 2;
    } else {
        last = 3;
    }
    if (D_800FA656 != 0 && last == page) {
        switch (D_80114DC0_3BDF60_name_5F + 1) {
        case 42:
            D_80114DC6_3BDF66_name_5F = D_800FA656 + 0x47;
            break;
        case 46:
            D_80114DC6_3BDF66_name_5F = D_800FA656 + 0x49;
            break;
        default:
            D_80114DC6_3BDF66_name_5F = D_80114DC0_3BDF60_name_5F;
            break;
        }
        mes = D_80113710_3BC8B0_name_5F[D_80114DC6_3BDF66_name_5F][3];
    } else {
        mes = D_80113710_3BC8B0_name_5F[D_80114DC0_3BDF60_name_5F][0] + page;
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
    func_800890CC_89CCC(D_80114E3C_3BDFDC_name_5F, mes, -1, -1);
    if (extra != -1 && _CheckFlag(0xC) == 0) {
        if (D_80114DC0_3BDF60_name_5F == 0x1E || D_80114DC0_3BDF60_name_5F == 0x42) {
            for (i = 0, n = 0; i < 4; i++) {
                if (page == 1) {
                    if (gPlayers[i].group != 0 && gPlayers[i].group != 2) {
                        continue;
                    }
                } else if (gPlayers[i].group != 1 && gPlayers[i].group != 3) {
                    continue;
                }
                func_80089308_89F08(D_80114E3C_3BDFDC_name_5F, (char*)(gPlayers[i].character + 0x1BA), n++);
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
            func_80089308_89F08(D_80114E3C_3BDFDC_name_5F, (char*)(gPlayers[i].character + 0x1BA), 0);
        } else if (page == 2) {
            for (i = 0, n = 0; i < 4; i++) {
                if (gPlayers[i].group != 0) {
                    func_80089308_89F08(D_80114E3C_3BDFDC_name_5F, (char*)(gPlayers[i].character + 0x1BA), n++);
                }
            }
        }
    }
    while (func_8008BA30_8C630(D_80114E3C_3BDFDC_name_5F) != 0) {
        HuPrcVSleep();
    }
    func_80089544_8A144(D_80114E3C_3BDFDC_name_5F, D_80114E3E_3BDFDE_name_5F[1]);
    if (extra == -1 || _CheckFlag(0xC) != 0) {
        if (page == 1) {
            page = 4;
        }
        if (page == 2) {
            page = 3;
        }
    }
    D_80114E3E_3BDFDE_name_5F[1] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, (page + 0x14) | 0xB0000, 0x37, -0x28, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103C84_3ACE24_name_5F);
#endif

void func_801040D0_3AD270_name_5F(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[D_80114DC8_3BDF68_name_5F[4]];
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

void func_801041C4_3AD364_name_5F(void) {
    omObjData* obj;
    s32 i;

    for (i = 0; i < 5; i++) {
        obj = omAddObj(0x64, 0, 0, -1, func_801040D0_3AD270_name_5F);
        D_80114DFC_3BDF9C_name_5F[i] = obj;
        obj->work[0] = D_80114E2E_3BDFCE_name_5F[i];
        obj->work[1] = D_801139A4_3BCB44_name_5F[i][0];
        obj->work[2] = 0;
        obj->work[3] = D_801139A4_3BCB44_name_5F[i][1];
    }
}

void func_80104280_3AD420_name_5F(omObjData* obj) {
    u8 idx = obj->work[0];
    f32* work = obj->unk_50;

    if (D_80114E38_3BDFD8_name_5F != idx) {
        work[1] = 0.0f;
        work[0] = 1.0f;
    } else {
        work[0] = HuMathSin(work[1]) * 0.2f + 1.0f;
        work[1] += work[2];
        work[1] = func_8002D958_2E558(work[1]);
    }
    func_8001A91C_1B51C(D_80114E2E_3BDFCE_name_5F[idx], work[0], work[0]);
}

/* NON_MATCHING: scheduling only (retail computes the slot offset before loading D_800F93FC) */
#ifdef NON_MATCHING
void func_8010433C_3AD4DC_name_5F(void) {
    omObjData* obj;
    f32* work;
    s32 spr;
    s32 i;

    for (i = 0; i < 5; i++) {
        spr = (s16)func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(D_8011397C_3BCB1C_name_5F[D_800CAFD8[i]]), 0, 0);
        D_80114E2E_3BDFCE_name_5F[i] = spr;
        SprAttrReset(D_800F93FC_F9FFC[spr].group, 0, 0x1000);
        espDispOff(spr);
        func_8001A708_1B308(spr, 0x4000);
        obj = omAddObj(0x64, 0, 0, -1, func_80104280_3AD420_name_5F);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010433C_3AD4DC_name_5F);
#endif

void func_80104490_3AD630_name_5F(omObjData* obj) {
    f32* angle = obj->unk_50;
    Ovl5FEsprite* esp = &D_800F93FC_F9FFC[obj->work[0]];

    esp->x = esp->x + HuMathSin(*angle) * 20.0f;
    esp->y = esp->y + func_800B7890_B8490(*angle) * 20.0f;
    if (esp->x < -100) {
        omDelObj(obj);
    }
}

void func_8010456C_3AD70C_name_5F(s32 arg0, s32 spr) {
    omObjData* obj;
    f32* angle;
    Ovl5FEsprite* esp;
    Vec v;

    obj = omAddObj(0x64, 0, 0, -1, func_80104490_3AD630_name_5F);
    obj->unk_50 = func_80027154_27D54(4, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 4);
    angle = obj->unk_50;
    esp = &D_800F93FC_F9FFC[spr];
    HuVecCopyXYZ(&v, esp->x - 160, 0.0f, esp->y - 120);
    *angle = func_800B75A8_B81A8(v.x, v.z);
    obj->work[0] = spr;
}

void func_80104650_3AD7F0_name_5F(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_8010456C_3AD70C_name_5F(i, D_80114E2E_3BDFCE_name_5F[i]);
    }
}

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801046A4_3AD844_name_5F(void) {
    f32 s;
    s32 i;

    D_80114E48_3BDFE8_name_5F = 1;
    s = 0.0f;
    SprPosSet(D_80114E46_3BDFE6_name_5F, 0, 220, 30);
    while (1) {
        s += 0.1f;
        if (s >= 1.0f) {
            for (i = 0; i < 5; i++) {
                SprScaleSet(D_80114E46_3BDFE6_name_5F, i, 1.0f, 1.0f);
            }
            break;
        }
        for (i = 0; i < 5; i++) {
            SprScaleSet(D_80114E46_3BDFE6_name_5F, i, s, s);
        }
        for (i = 0; i < 3; i++) {
            SprAttrReset(D_80114E46_3BDFE6_name_5F, i, 0x8000);
        }
        if ((s16)((D_80114E3A_3BDFDA_name_5F / 100) % 10) != 0) {
            SprAttrReset(D_80114E46_3BDFE6_name_5F, 4, 0x8000);
            SprAttrReset(D_80114E46_3BDFE6_name_5F, 3, 0x8000);
        } else if ((s16)((D_80114E3A_3BDFDA_name_5F / 10) % 10) != 0) {
            SprAttrReset(D_80114E46_3BDFE6_name_5F, 3, 0x8000);
        }
        if (D_80114E48_3BDFE8_name_5F == 0) {
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801046A4_3AD844_name_5F);
#endif

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801048F0_3ADA90_name_5F(void) {
    f32 s;
    s16 i;

    D_80114E48_3BDFE8_name_5F = 0;
    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        for (i = 0; i < 5; i++) {
            SprScaleSet(D_80114E46_3BDFE6_name_5F, i, s, s);
        }
        if (D_80114E48_3BDFE8_name_5F != 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 5; i++) {
        SprAttrSet(D_80114E46_3BDFE6_name_5F, i, 0x8000);
    }
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801048F0_3ADA90_name_5F);
#endif

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801049F4_3ADB94_name_5F(void) {
    s16 coin;
    s16 digit;
    s16 frame;
    s16 grp;
    s16 i;

    if (_CheckFlag(0x13) == 0) {
        D_80114E3A_3BDFDA_name_5F = D_800F9208_F9E08;
    } else {
        D_80114E3A_3BDFDA_name_5F = 0;
    }
    D_80114E48_3BDFE8_name_5F = 0;
    coin = func_8001A2F8_1AEF8(0xB001B);
    digit = func_8001A2F8_1AEF8(0xC000D);
    frame = func_8001A2F8_1AEF8(0xB001C);
    D_80114E46_3BDFE6_name_5F = grp = SprCreate(5, 5);
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
    func_800822A8_82EA8(grp, 2, D_80114E3A_3BDFDA_name_5F % 10, 0);
    func_800822A8_82EA8(grp, 3, (D_80114E3A_3BDFDA_name_5F / 10) % 10, 0);
    func_800822A8_82EA8(grp, 4, (D_80114E3A_3BDFDA_name_5F / 100) % 10, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801049F4_3ADB94_name_5F);
#endif

void func_80104D08_3ADEA8_name_5F(omObjData* obj) {
    HmfModel* model = &D_800FC834_FD434[obj->work[0]];
    Vec* ofs = obj->unk_50;

    func_80029714_2A314(obj->work[1], model->pos.x + ofs->x, model->pos.y + ofs->y, model->pos.z + ofs->z);
    func_800298A4_2A4A4(obj->work[1], 4, 0);
    if (obj->work[2] != 0) {
        omDelObj(obj);
    }
}

void func_80104DA8_3ADF48_name_5F(s32 i, s32 player, f32 x, f32 y, f32 z) {
    omObjData* obj;
    Vec* ofs;

    obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
    D_80114DFC_3BDF9C_name_5F[i] = obj;
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = x;
    ofs->y = y;
    ofs->z = z;
    /* the player's model: an s32 at 0x24 of its object's work, read as its low byte */
    obj->work[0] = ((s32*)D_80114DD8_3BDF78_name_5F[player]->unk_50)[9];
    obj->work[1] = ((u8*)D_800FA640_FB240[i])[0x35];
    obj->work[2] = 0;
}

void func_80104E98_3AE038_name_5F(s32 i) {
    omObjData* obj;

    obj = omAddObj(0x65, 0, 0, -1, func_801040D0_3AD270_name_5F);
    D_80114DFC_3BDF9C_name_5F[i] = obj;
    obj->work[0] = ((u8*)D_800FA640_FB240[i])[0x6D];
    obj->work[1] = i * 30 - 60;
    obj->work[2] = 0;
    obj->work[3] = 0;
}

/* NON_MATCHING: register allocation and branch-likely layout differ; logic follows the asm */
#ifdef NON_MATCHING
s32 func_80104F18_3AE0B8_name_5F(s32 btn) {
    s32 ret = 0;
    s32 i;

    if (D_80114DC2_3BDF62_name_5F < 6) {
        if (D_80114DC2_3BDF62_name_5F >= 4) {
            if (!(gPlayers[D_80114DC4_3BDF64_name_5F].flags & 1)) {
                ret = ContBtnTrg[gPlayers[D_80114DC4_3BDF64_name_5F].port] & btn;
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104F18_3AE0B8_name_5F);
#endif

/* NON_MATCHING: code shape differs (branch layout); logic follows the asm */
#ifdef NON_MATCHING
s32 func_80105008_3AE1A8_name_5F(s32 btn, s32 arg1) {
    s32 ret = 0;
    s32 cpu = 0;
    s32 i;

    if (D_80114DC2_3BDF62_name_5F < 6 && D_80114DC2_3BDF62_name_5F >= 4) {
        cpu = gPlayers[D_80114DC4_3BDF64_name_5F].flags & 1;
    }
    for (i = 0; i < 4; i++) {
        if (!(gPlayers[i].flags & 1)) {
            break;
        }
    }
    if (i < 4 && cpu == 0) {
        ret = func_80104F18_3AE0B8_name_5F(btn);
    } else if (arg1 == 0) {
        ret = 1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105008_3AE1A8_name_5F);
#endif

s32 func_801050DC_3AE27C_name_5F(s32 minigame) {
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

void func_80105110_3AE2B0_name_5F(omObjData* obj) {
    HmfModel* model;

    switch (obj->work[0]) {
    case 0:
        model = &D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F];
        func_800298A4_2A4A4(D_80114E2C_3BDFCC_name_5F, 4, 0);
        func_80029714_2A314(D_80114E2C_3BDFCC_name_5F, model->pos.x - 20.0f, model->pos.y, model->pos.z - 100.0f);
        func_800297E8_2A3E8(D_80114E2C_3BDFCC_name_5F, 1.0f, 0.0f, 1.0f);
        obj->work[0] = 1;
        break;
    case 1:
        model = &D_800FC834_FD434[D_80114E2C_3BDFCC_name_5F];
        func_800297E8_2A3E8(D_80114E2C_3BDFCC_name_5F, model->scale.x, model->scale.y + 0.1f, model->scale.z);
        if (model->scale.y >= 1.0f) {
            model->scale.y = 1.0f;
            omDelObj(obj);
        }
        break;
    }
}

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_80105258_3AE3F8_name_5F(void) {
    HmfModel* model;
    Vec pos;
    Vec2f screen;
    f32 s;

    espDispOn(D_80114E12_3BDFB2_name_5F);
    espDispOn(D_80114E14_3BDFB4_name_5F);
    model = &D_800FC834_FD434[D_80114DC8_3BDF68_name_5F[2]];
    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    espPosSet(D_80114E12_3BDFB2_name_5F, screen.unk_00, 121);
    espPosSet(D_80114E14_3BDFB4_name_5F, screen.unk_00, 121);
    for (s = 0.0f + 0.1f; !(s >= 1.0f); s += 0.1f) {
        func_8001A91C_1B51C(D_80114E12_3BDFB2_name_5F, s, s);
        func_8001A91C_1B51C(D_80114E14_3BDFB4_name_5F, s, s);
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_80114E12_3BDFB2_name_5F, 1.0f, 1.0f);
    func_8001A91C_1B51C(D_80114E14_3BDFB4_name_5F, 1.0f, 1.0f);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105258_3AE3F8_name_5F);
#endif

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801053F0_3AE590_name_5F(void) {
    f32 s;

    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        func_8001A91C_1B51C(D_80114E12_3BDFB2_name_5F, s, s);
        func_8001A91C_1B51C(D_80114E14_3BDFB4_name_5F, s, s);
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_80114E12_3BDFB2_name_5F, 0.0f, 0.0f);
    func_8001A91C_1B51C(D_80114E14_3BDFB4_name_5F, 0.0f, 0.0f);
    espDispOff(D_80114E12_3BDFB2_name_5F);
    espDispOff(D_80114E14_3BDFB4_name_5F);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801053F0_3AE590_name_5F);
#endif

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801054EC_3AE68C_name_5F(void) {
    HmfModel* model;
    Vec pos;
    Vec2f screen;
    f32 s;
    s32 angle;

    D_80114E1C_3BDFBC_name_5F = 1;
    model = &D_800FC834_FD434[D_80114DC8_3BDF68_name_5F[2]];
    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    espPosSet(D_80114E1A_3BDFBA_name_5F, screen.unk_00, 70);
    for (s = 0.0f + 0.1f; !(s >= 1.0f); s += 0.1f) {
        func_8001A91C_1B51C(D_80114E1A_3BDFBA_name_5F, s, s);
        espDispOn(D_80114E1A_3BDFBA_name_5F);
        if (D_80114E1C_3BDFBC_name_5F == 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    angle = 0;
    func_8001A91C_1B51C(D_80114E1A_3BDFBA_name_5F, 1.0f, 1.0f);
    while (1) {
        if (angle > 180) {
            angle -= 180;
        }
        func_8001A6BC_1B2BC(D_80114E1A_3BDFBA_name_5F, HuMathSin(angle) * 255.0f);
        if (D_80114E1C_3BDFBC_name_5F == 0) {
            omDelPrcObj(NULL);
        }
        angle += 10;
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801054EC_3AE68C_name_5F);
#endif

/* NON_MATCHING: code shape differs (loop/branch layout); logic follows the asm */
#ifdef NON_MATCHING
void func_801056A8_3AE848_name_5F(void) {
    f32 s;

    D_80114E1C_3BDFBC_name_5F = 0;
    for (s = 1.0f - 0.1f; !(s <= 0.0f); s -= 0.1f) {
        func_8001A91C_1B51C(D_80114E1A_3BDFBA_name_5F, s, s);
        if (D_80114E1C_3BDFBC_name_5F != 0) {
            omDelPrcObj(NULL);
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_80114E1A_3BDFBA_name_5F, 0.0f, 0.0f);
    espDispOff(D_80114E1A_3BDFBA_name_5F);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801056A8_3AE848_name_5F);
#endif

/* NON_MATCHING: add.s operand order only (retail: step + scale.x in the other register order) */
#ifdef NON_MATCHING
void func_8010578C_3AE92C_name_5F(void) {
    HmfModel* model = &D_800FC834_FD434[D_80114E2A_3BDFCA_name_5F];
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010578C_3AE92C_name_5F);
#endif

void func_80105860_3AEA00_name_5F(void) {
    s32 n;

    while (1) {
        while (func_80029CE4_2A8E4(D_80114E1E_3BDFBE_name_5F) < func_80029D0C_2A90C(D_80114E1E_3BDFBE_name_5F)) {
            HuPrcVSleep();
        }
        n = (rand8() & 3) + 1;
        while (n != 0) {
            func_80029C74_2A874(D_80114E1E_3BDFBE_name_5F, 0.0f);
            while (func_80029CE4_2A8E4(D_80114E1E_3BDFBE_name_5F) < func_80029D0C_2A90C(D_80114E1E_3BDFBE_name_5F)) {
                HuPrcVSleep();
            }
            n--;
        }
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[4], 0, 10, 0);
        while (func_80029E3C_2AA3C(D_80114E1E_3BDFBE_name_5F) != -1.0f) {
            HuPrcVSleep();
        }
        while (func_80029CE4_2A8E4(D_80114E1E_3BDFBE_name_5F) < func_80029D0C_2A90C(D_80114E1E_3BDFBE_name_5F)) {
            HuPrcVSleep();
        }
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[0], 0, 10, 0);
        while (func_80029E3C_2AA3C(D_80114E1E_3BDFBE_name_5F) != -1.0f) {
            HuPrcVSleep();
        }
    }
}

s32 func_80105A14_3AEBB4_name_5F(void) {
    s32 ret = D_80114DC0_3BDF60_name_5F != 0x38;

    if (_CheckFlag(0xC) != 0) {
        ret = 0;
    }
    return ret;
}

s32 func_80105A54_3AEBF4_name_5F(void) {
    if (func_80105A14_3AEBB4_name_5F() != 0 && func_80104F18_3AE0B8_name_5F(0x10) != 0) {
        _SetFlag(0x15);
        D_80114E4A_3BDFEA_name_5F = 1;
        D_800F9910_FA510 |= 1;
    }
    return D_80114E4A_3BDFEA_name_5F;
}

void func_80105AB8_3AEC58_name_5F(void) {
    D_80114E4A_3BDFEA_name_5F = 0;
    D_800F9910_FA510 &= ~1;
    _ClearFlag(0x15);
    SprAttrReset(func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk_6C, D_80114E3E_3BDFDE_name_5F[2], 0x8000);
    func_80089544_8A144(D_80114E3C_3BDFDC_name_5F, D_80114E3E_3BDFDE_name_5F[3]);
    D_80114E3E_3BDFDE_name_5F[3] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0022, 0xBE, -0x28, 0);
    omAddPrcObj(func_801056A8_3AE848_name_5F, 0x1001, 0x800, 0);
    if (D_80114DC2_3BDF62_name_5F == 3) {
        omAddPrcObj(func_801046A4_3AD844_name_5F, 0x1001, 0x800, 0);
    }
}

/* The screen's main process: the falling models drop in, the host and title appear, then the
   instruction pages run until a player confirms (or skips with START), and the screen fades out
   to the minigame (func_801085A0). */
void func_80105B94_3AED34_name_5F(void) {
    omObjData* obj;
    Ovl5FFallWork* work;
    Ovl5FFallInit* init;
    Vec* ofs;
    s32 i;
    s32 page;
    s32 timer;
    s32 mes;
    s16 btn;
    s32 wait;

    D_80114E38_3BDFD8_name_5F = -1;
    for (i = 0; i < 8; i++) {
        D_80114DF0_3BDF90_name_5F[i] = NULL;
    }
    if (D_80114DC2_3BDF62_name_5F == 4) {
        func_8010433C_3AD4DC_name_5F();
    } else {
        func_8011303C_3BC1DC_name_5F();
    }
    func_80107C84_3B0E24_name_5F(D_80114DC0_3BDF60_name_5F);
    obj = omAddObj(0x64, 0, 0, -1, func_8010382C_3AC9CC_name_5F);
    obj->work[0] = 0;
    obj->work[1] = 30;
    for (i = 0; i < 5; i++) {
        obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
        obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
        work = obj->unk_50;
        init = &D_801139D4_3BCB74_name_5F[i];
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

    D_80114DD8_3BDF78_name_5F[0] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_801139D4_3BCB74_name_5F[5].pos.x;
    work->pos.y = D_801139D4_3BCB74_name_5F[5].pos.y - 500.0f;
    work->pos.z = D_801139D4_3BCB74_name_5F[5].pos.z;
    work->scale = 0.9f;
    work->floor = D_801139D4_3BCB74_name_5F[5].pos.y;
    obj->work[0] = 1;
    obj->work[1] = 3;
    obj->work[2] = 50;
    obj->work[3] = 1;

    i = 6;
    switch (D_80114DC2_3BDF62_name_5F) {
    case 1:
        i = 7;
        break;
    case 2:
        if (D_80114DC0_3BDF60_name_5F != 0x21) {
            i = 8;
        }
        break;
    }
    D_80114DD8_3BDF78_name_5F[1] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_801139D4_3BCB74_name_5F[i].pos.x;
    work->pos.y = D_801139D4_3BCB74_name_5F[i].pos.y - 600.0f;
    work->pos.z = D_801139D4_3BCB74_name_5F[i].pos.z;
    work->scale = 1.0f;
    work->floor = D_801139D4_3BCB74_name_5F[i].pos.y;
    obj->work[0] = 2;
    obj->work[1] = 3;
    obj->work[2] = 80;
    obj->work[3] = 0;

    D_80114DD8_3BDF78_name_5F[2] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_801139D4_3BCB74_name_5F[9].pos.x;
    work->pos.y = D_801139D4_3BCB74_name_5F[9].pos.y - 400.0f;
    work->pos.z = D_801139D4_3BCB74_name_5F[9].pos.z;
    work->scale = 0.8f;
    work->floor = D_801139D4_3BCB74_name_5F[9].pos.y;
    obj->work[0] = 3;
    obj->work[1] = 3;
    obj->work[2] = 50;
    obj->work[3] = 0;

    D_80114DD8_3BDF78_name_5F[3] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
    obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
    work = obj->unk_50;
    work->pos.x = work->baseX = D_801139D4_3BCB74_name_5F[10].pos.x;
    work->pos.y = D_801139D4_3BCB74_name_5F[10].pos.y - 400.0f;
    work->pos.z = D_801139D4_3BCB74_name_5F[10].pos.z;
    work->scale = 1.5f;
    work->floor = D_801139D4_3BCB74_name_5F[10].pos.y;
    obj->work[0] = 4;
    obj->work[1] = 3;
    obj->work[2] = 70;
    obj->work[3] = 1;

    if (D_80114DC2_3BDF62_name_5F < 3) {
        if (D_80114DC2_3BDF62_name_5F > 0 && D_80114DC0_3BDF60_name_5F != 0x21) {
        D_80114DD8_3BDF78_name_5F[4] = obj = omAddObj(0x64, 0, 0, -1, func_80103608_3AC7A8_name_5F);
        obj->unk_50 = func_80027154_27D54(0x28, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0x28);
        work = obj->unk_50;
        work->pos.x = work->baseX = D_801139D4_3BCB74_name_5F[11].pos.x;
        work->pos.y = D_801139D4_3BCB74_name_5F[11].pos.y - 400.0f;
        work->pos.z = D_801139D4_3BCB74_name_5F[11].pos.z;
        work->scale = 1.5f;
        work->floor = D_801139D4_3BCB74_name_5F[11].pos.y;
        obj->work[0] = 5;
        obj->work[1] = 3;
        obj->work[2] = 70;
        obj->work[3] = 1;
        }
    }
    HuPrcVSleep();

    omAddObj(0x64, 0, 0, -1, func_801038D4_3ACA74_name_5F);
    D_80114DF0_3BDF90_name_5F[0] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    switch (D_80114DC2_3BDF62_name_5F) {
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
    work = D_80114DD8_3BDF78_name_5F[2]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_80114E1E_3BDFBE_name_5F;
    obj->work[2] = 0;
    if (D_80114DC2_3BDF62_name_5F == 3) {
        D_80114DF0_3BDF90_name_5F[7] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        ofs = obj->unk_50;
        ofs->x = 0.0f;
        ofs->y = -20.0f;
        ofs->z = -80.0f;
        work = D_80114DD8_3BDF78_name_5F[2]->unk_50; obj->work[0] = work->model;
        obj->work[1] = D_80114E2C_3BDFCC_name_5F;
        obj->work[2] = 0;
    }
    D_80114DF0_3BDF90_name_5F[1] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    ofs->y = 0.0f;
    ofs->z = 10.0f;
    work = D_80114DD8_3BDF78_name_5F[1]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_80114E2A_3BDFCA_name_5F;
    obj->work[2] = 0;
    D_80114DF0_3BDF90_name_5F[2] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
    obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
    ofs = obj->unk_50;
    ofs->x = 0.0f;
    ofs->y = 0.0f;
    ofs->z = 15.0f;
    work = D_80114DD8_3BDF78_name_5F[1]->unk_50; obj->work[0] = work->model;
    obj->work[1] = D_80114E18_3BDFB8_name_5F;
    obj->work[2] = 0;
    switch (D_80114DC2_3BDF62_name_5F) {
    case 4:
        func_801041C4_3AD364_name_5F();
        break;
    case 5:
        D_80114DF0_3BDF90_name_5F[3] = obj = omAddObj(0x65, 0, 0, -1, func_80104D08_3ADEA8_name_5F);
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        ofs = obj->unk_50;
        ofs->x = -20.0f;
        ofs->y = -50.0f;
        ofs->z = -80.0f;
        work = D_80114DD8_3BDF78_name_5F[3]->unk_50; obj->work[0] = work->model;
        obj->work[1] = ((u8*)D_800FA640_FB240[0])[0x35];
        obj->work[2] = 0;
        break;
    default:
        func_80112FE8_3BC188_name_5F();
        break;
    }
    omAddObj(0x64, 0, 0, -1, func_80107FE0_3B1180_name_5F);
    HuPrcSleep(30);

    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[1], 0, 2, 0);
        wait = 2;
        break;
    case 4:
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[2]);
        func_80029C74_2A874(D_80114E1E_3BDFBE_name_5F, func_80029D0C_2A90C(D_80114E1E_3BDFBE_name_5F));
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 4);
        wait = 30;
        break;
    default:
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[1], 0, 2, 0);
        wait = 10;
        break;
    }
    HuPrcSleep(wait);

    /* the riders let go */
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
    case 4:
        for (i = 0; i < 8; i++) {
            if (D_80114DF0_3BDF90_name_5F[i] != NULL) {
                D_80114DF0_3BDF90_name_5F[i]->work[2] = 1;
            }
        }
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            if (D_80114DF0_3BDF90_name_5F[i] != NULL) {
                D_80114DF0_3BDF90_name_5F[i]->work[2] = 1;
            }
        }
        break;
    default:
        for (i = 0; i < 7; i++) {
            if (D_80114DF0_3BDF90_name_5F[i] != NULL) {
                D_80114DF0_3BDF90_name_5F[i]->work[2] = 1;
            }
        }
        break;
    }
    PlaySound(0x31F);
    switch (D_80114DC2_3BDF62_name_5F) {
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
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3AC918_name_5F);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_80114DC8_3BDF68_name_5F[3];
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3AC918_name_5F);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_80114DC8_3BDF68_name_5F[4];
    if (D_80114DC2_3BDF62_name_5F < 3) {
        if (D_80114DC2_3BDF62_name_5F > 0 && D_80114DC0_3BDF60_name_5F != 0x21) {
        PlaySound(0x329);
        obj = omAddObj(0x64, 0, 0, -1, func_80103778_3AC918_name_5F);
        obj->work[0] = 0;
        obj->work[1] = 0;
        obj->work[2] = D_80114DC8_3BDF68_name_5F[5];
        }
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 4:
        HuPrcSleep(20);
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[0]);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 0);
        D_80114F40_3BE0E0_name_5F[0] = omAddPrcObj(func_80105860_3AEA00_name_5F, 0x1001, 0x800, 0);
        break;
    case 3:
        HuPrcSleep(20);
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[0], 0, 2, 0);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        omAddPrcObj(func_801046A4_3AD844_name_5F, 0x1001, 0x800, 0);
        break;
    default:
        HuPrcSleep(10);
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[2], 0, 2, 2);
        break;
    }
    if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
        omAddObj(0x64, 0, 0, -1, func_80105110_3AE2B0_name_5F)->work[0] = 0;
    }
    if (D_80114DC2_3BDF62_name_5F != 4) {
        func_80113004_3BC1A4_name_5F();
    }
    omAddPrcObj(func_80105258_3AE3F8_name_5F, 0x1001, 0x800, 0);

    /* the instruction pages */
    page = 0;
    func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, 0);
    func_8008E2DC_8EEDC(D_80114E3C_3BDFDC_name_5F, 1);
    if (D_80114DC2_3BDF62_name_5F < 6) {
        if (D_80114DC2_3BDF62_name_5F >= 4) {
            btn = D_801139CC_3BCB6C_name_5F[gPlayers[D_80114DC4_3BDF64_name_5F].port];
            goto setButtons;
        }
    }
    i = 0;
    btn = 0;
    for (; i < 4; i++) {
        if (!(gPlayers[i].flags & 1)) {
            btn |= D_801139CC_3BCB6C_name_5F[gPlayers[i].port];
        }
    }
setButtons:
    func_8008D59C_8E19C(D_80114E3C_3BDFDC_name_5F, btn);
    D_800FC8A0_FD4A0 = 1;
    timer = 60;
    while (func_80105008_3AE1A8_name_5F(0x1000, timer--) == 0) {
        if (func_80104F18_3AE0B8_name_5F(1) != 0) {
            D_80114E38_3BDFD8_name_5F = -1;
            page++;
            if (D_80113710_3BC8B0_name_5F[D_80114DC0_3BDF60_name_5F][2] == -1 || _CheckFlag(0xC) != 0) {
                if (page >= 3) {
                    page = 0;
                }
            } else if (page >= 4) {
                page = 0;
            }
            func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, page);
        }
        if (func_80104F18_3AE0B8_name_5F(2) != 0) {
            D_80114E38_3BDFD8_name_5F = -1;
            page--;
            if (D_80113710_3BC8B0_name_5F[D_80114DC0_3BDF60_name_5F][2] == -1 || _CheckFlag(0xC) != 0) {
                if (page < 0) {
                    page = 2;
                }
            } else if (page < 0) {
                page = 3;
            }
            func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, page);
        }
        if (D_80114DC2_3BDF62_name_5F == 4 && func_80104F18_3AE0B8_name_5F(4) != 0 && page == 0) {
            /* the item list */
            func_80089544_8A144(D_80114E3C_3BDFDC_name_5F, D_80114E3E_3BDFDE_name_5F[1]);
            D_80114E3E_3BDFDE_name_5F[1] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0019, 0x37, -0x28, 0);
            SprAttrSet(func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk_6C, D_80114E3E_3BDFDE_name_5F[2], 0x8000);
            func_800890CC_89CCC(D_80114E3C_3BDFDC_name_5F, D_800CAFD8[0] + 0x1D2, -1, -1);
            do {
                HuPrcVSleep();
            } while (func_8008BA30_8C630(D_80114E3C_3BDFDC_name_5F) != 0);
            i = 0;
            D_80114E38_3BDFD8_name_5F = 0;
            while (1) {
                if (func_80104F18_3AE0B8_name_5F(4) != 0) {
                    if (++D_80114E38_3BDFD8_name_5F >= 5) {
                        D_80114E38_3BDFD8_name_5F = 0;
                    }
                    func_800890CC_89CCC(D_80114E3C_3BDFDC_name_5F, D_800CAFD8[D_80114E38_3BDFD8_name_5F] + 0x1D2, -1, -1);
                    while (func_8008BA30_8C630(D_80114E3C_3BDFDC_name_5F) != 0) {
                        HuPrcVSleep();
                    }
                }
                if (func_80104F18_3AE0B8_name_5F(8) != 0) {
                    D_80114E38_3BDFD8_name_5F = -1;
                    SprAttrReset(func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk_6C, D_80114E3E_3BDFDE_name_5F[2], 0x8000);
                    func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, page);
                    break;
                }
                if (func_80105008_3AE1A8_name_5F(0x1000, 1) != 0) {
                    i = 1;
                    break;
                }
                if (func_80105A54_3AEBF4_name_5F() != 0) {
                    D_80114E38_3BDFD8_name_5F = -1;
                    break;
                }
                HuPrcVSleep();
            }
            if (i != 0) {
                break;
            }
        }
        if (func_80105A54_3AEBF4_name_5F() != 0) {
            /* START: skip to the minigame, after its last pages */
            PlaySound(2);
            func_8008DF9C_8EB9C(D_80114E3C_3BDFDC_name_5F, 0x1010);
            if (D_80114DC2_3BDF62_name_5F == 3) {
                omAddPrcObj(func_801048F0_3ADA90_name_5F, 0x1001, 0x800, 0);
            }
            SprAttrSet(func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk_6C, D_80114E3E_3BDFDE_name_5F[2], 0x8000);
            omAddPrcObj(func_801054EC_3AE68C_name_5F, 0x1001, 0x800, 0);
            func_80089544_8A144(D_80114E3C_3BDFDC_name_5F, D_80114E3E_3BDFDE_name_5F[1]);
            D_80114E3E_3BDFDE_name_5F[1] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB001A, 0x37, -0x28, 0);
            func_80089544_8A144(D_80114E3C_3BDFDC_name_5F, D_80114E3E_3BDFDE_name_5F[3]);
            D_80114E3E_3BDFDE_name_5F[3] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0023, 0xBE, -0x28, 0);
            switch (D_80114DC2_3BDF62_name_5F) {
            case 4:
                mes = 0x537;
                break;
            case 3:
                mes = 0x53A;
                break;
            default:
                mes = 0x53D;
                if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
                    mes = 0x540;
                }
                break;
            }
            for (i = 0; ; ) {
                func_800890CC_89CCC(D_80114E3C_3BDFDC_name_5F, mes + i, -1, -1);
                while (func_8008BA30_8C630(D_80114E3C_3BDFDC_name_5F) != 0) {
                    HuPrcVSleep();
                }
                if (D_800F920C_F9E0C[D_80114E3C_3BDFDC_name_5F].unkA8 & 0x10) {
                    i = 200;
                    break;
                }
                if (D_800F920C_F9E0C[D_80114E3C_3BDFDC_name_5F].unkA8 & 0x1000) {
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
                if (D_80113710_3BC8B0_name_5F[D_80114DC0_3BDF60_name_5F][2] == -1 || _CheckFlag(0xC) != 0) {
                    page = 2;
                } else {
                    page = 3;
                }
                func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, page);
                func_800890CC_89CCC(D_80114E3C_3BDFDC_name_5F, (s32)D_801147D8_3BD978_name_5F, -1, -1);
                while (func_8008BA30_8C630(D_80114E3C_3BDFDC_name_5F) != 0) {
                    HuPrcVSleep();
                }
                if (!(D_800F920C_F9E0C[D_80114E3C_3BDFDC_name_5F].unkA8 & 0x10)) {
                    break;
                }
            }
            /* B: back to the first page */
            page = 0;
            func_80105AB8_3AEC58_name_5F();
            func_80103C84_3ACE24_name_5F(D_80114E3C_3BDFDC_name_5F, 0);
        }
        HuPrcVSleep();
    }

    if (D_80114DC2_3BDF62_name_5F != 4) {
        func_80113020_3BC1C0_name_5F();
    }
    D_800FC8A0_FD4A0 = 11;
    if (D_80114DC2_3BDF62_name_5F < 6) {
        if (D_80114DC2_3BDF62_name_5F >= 4) {
            omVibrate(D_80114DC4_3BDF64_name_5F, 10, 0, 10);
            goto vibrated;
        }
    }
    for (i = 0; i < 4; i++) {
        omVibrate(i, 10, 0, 10);
    }
vibrated:
    HuPrcSleep(4);
    if (D_80114DC2_3BDF62_name_5F == 4) {
        func_80104650_3AD7F0_name_5F();
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 4:
        omDelPrcObj(D_80114F40_3BE0E0_name_5F[0]);
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[3], 0, 3, 2);
        break;
    case 3:
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[2], 0, 3, 2);
        break;
    default:
        func_80029BF0_2A7F0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[3], 0, 3, 2);
        break;
    }
    omAddObj(0x7D00, 0, 0, -1, func_80103994_3ACB34_name_5F)->work[1] = 0;
    if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0 || D_80114DC2_3BDF62_name_5F == 3) {
        omAddObj(0x7D00, 0, 0, -1, func_80103B78_3ACD18_name_5F);
    }
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3AC918_name_5F);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_80114DC8_3BDF68_name_5F[2];
    func_800298A4_2A4A4(D_80114E18_3BDFB8_name_5F, 4, 4);
    HuPrcSleep(5);
    PlaySound(0x329);
    obj = omAddObj(0x64, 0, 0, -1, func_80103778_3AC918_name_5F);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = D_80114DC8_3BDF68_name_5F[1];
    if (D_80114DC2_3BDF62_name_5F == 3) {
        omAddPrcObj(func_801048F0_3ADA90_name_5F, 0x1001, 0x800, 0);
    }
    omAddPrcObj(func_801053F0_3AE590_name_5F, 0x1001, 0x800, 0);
    if (_CheckFlag(0x15) != 0) {
        omAddPrcObj(func_801056A8_3AE848_name_5F, 0x1001, 0x800, 0);
    }
    func_8008E4D0_8F0D0(D_80114E3C_3BDFDC_name_5F, 1);
    omAddPrcObj(func_8010578C_3AE92C_name_5F, 0x1001, 0x800, 0);
    PlaySound(0x345);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeOut(0, 30);
    func_800794A8_7A0A8(25);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80069698_6A298();
    func_801085A0_3B1740_name_5F(1);
    while (1) {
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_801147D8_3BD978_name_5F[4] = "\xFF";

/* Builds the demo picture: decodes the minigame's HVQ image (128x96, alpha from `alpha`) into an
   RGBA32 texture and gives part "gameimage-grid1" of model `model` a display list drawing each of
   its faces with the matching tile of that texture. */
void func_801072C8_3B0468_name_5F(s16 model, void* header, void* code, u8* alpha) {
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

/* Sets up the minigame's name (message 0x3D9 + minigame): one GAMEMES per line of the message
   (control characters split it; at most two lines), placed at (82, 40). */
/* NON_MATCHING: register allocation only (masked 0: p and line swap s1/s2) */
#ifdef NON_MATCHING
void func_80107C84_3B0E24_name_5F(s32 minigame) {
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
    D_80114E58_3BDFF8_name_5F[0].unk08 = D_80114E58_3BDFF8_name_5F[1].unk08 = -1;
    n = 0;
    for (p = start; *p != 0; p++) {
        if (*p < 0x20) {
            q = p - 1;
            if (*q == 0x10 || *q == 0x20 || *q == 0x1A) {
                *q = 0;
            }
            *p = 0;
            line = &D_80114E58_3BDFF8_name_5F[n];
            id = line->unk08 = func_8006A67C_6B27C(line, (char*)start, 0, -1, -1);
            D_80114E58_3BDFF8_name_5F[n].unk60 = 82.0f;
            D_80114E58_3BDFF8_name_5F[n].unk64 = 40.0f;
            SprPosSet(D_80114E58_3BDFF8_name_5F[n].strGId[id], 0, D_80114E58_3BDFF8_name_5F[n].unk60, 40);
            n++;
            start = p + 1;
        }
    }
    line = &D_80114E58_3BDFF8_name_5F[n];
    id = line->unk08 = func_8006A67C_6B27C(line, (char*)start, 0, -1, -1);
    D_80114E58_3BDFF8_name_5F[n].unk60 = 82.0f;
    D_80114E58_3BDFF8_name_5F[n].unk64 = (breaks != 0) ? 60.0f : 50.0f;
    SprPosSet(D_80114E58_3BDFF8_name_5F[n].strGId[id], 0, D_80114E58_3BDFF8_name_5F[n].unk60, D_80114E58_3BDFF8_name_5F[n].unk64);
    func_80068D24_69924(mes);
    func_80107F74_3B1114_name_5F();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107C84_3B0E24_name_5F);
#endif

/* Hides the name's lines (MP1 func_800F8DD0). */
void func_80107F74_3B1114_name_5F(void) {
    SprPosSet(D_80114E58_3BDFF8_name_5F[0].strGId[D_80114E58_3BDFF8_name_5F[0].unk08], 0, 0, -200);
    if (D_80114E58_3BDFF8_name_5F[1].unk08 != -1) {
        SprPosSet(D_80114E58_3BDFF8_name_5F[1].strGId[D_80114E58_3BDFF8_name_5F[1].unk08], 0, 0, -200);
    }
}

/* Keeps the name's lines on the title model (D_80114DC8[1]). */
void func_80107FE0_3B1180_name_5F(void) {
    HmfModel* model = &D_800FC834_FD434[D_80114DC8_3BDF68_name_5F[1]];
    Vec pos;
    Vec2f screen;

    pos.x = model->pos.x;
    pos.y = model->pos.y;
    pos.z = model->pos.z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    screen.unk_00 += 5.0f;
    screen.unk_04 -= 8.0f;
    if (D_80114E58_3BDFF8_name_5F[1].unk08 != -1) {
        SprPosSet(D_80114E58_3BDFF8_name_5F[0].strGId[D_80114E58_3BDFF8_name_5F[0].unk08], 0, screen.unk_00, screen.unk_04);
        SprPosSet(D_80114E58_3BDFF8_name_5F[1].strGId[D_80114E58_3BDFF8_name_5F[1].unk08], 0, screen.unk_00, screen.unk_04 + 16.0f);
    } else {
        SprPosSet(D_80114E58_3BDFF8_name_5F[0].strGId[D_80114E58_3BDFF8_name_5F[0].unk08], 0, screen.unk_00, screen.unk_04 + 10.0f);
    }
}

/* Sets the players' minigame groups from the minigame's type (1P minigames: func_8010881C picks
   the item for type 4); in 2-vs-2 minigames 0x19, 0x1E, 0x1F, 0x41, 0x42 each team is split into
   two numbered groups in random order. */
void func_80108170_3B1310_name_5F(void) {
    s32 i;
    s32 n;
    s32 m;
    s32 g;

    switch (D_80114DC2_3BDF62_name_5F) {
    case 4:
        func_8010881C_3B19BC_name_5F(GwSystem.current_player_index);
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
            switch (D_80114DC0_3BDF60_name_5F) {
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

/* Picks the minigame's variant (D_800FA656) at random for the minigames that have one, unless the
   player skipped (flag 0x15); main's D_800CAFEE overrides it when set. */
void func_80108458_3B15F8_name_5F(void) {
    s32 r;
    s32 mg;

    if (_CheckFlag(0x15) == 0) {
        r = (rand8() & 0xFF) * 0.00390625f * 100.0f;
        mg = D_80114DC0_3BDF60_name_5F;
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

void func_801085A0_3B1740_name_5F(s32 arg0) {
    s16 minigameOverlayID;

    func_8008CE5C_8DA5C();
    func_800727F0_733F0();
    func_80067EF8_68AF8(-1);
    
    if (arg0 != 0) {
        DataClose(D_80114E54_3BDFF4_name_5F);
        DataClose(D_80114E4C_3BDFEC_name_5F);
        DataClose(D_80114E50_3BDFF0_name_5F);
        omOvlKill();
    }
    
    if (D_80114E4A_3BDFEA_name_5F != 0) {
        omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
        minigameOverlayID = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
        omOvlHisChg(1, minigameOverlayID, 0, 0x14);
        return;
    } 
    
    _ClearFlag(0x15);
    if ((_CheckFlag(0x13) != 0) || !(_CheckFlag(0xC) == 0)) {
        omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
        return;
    }
    
    switch (D_80114DC2_3BDF62_name_5F) {
        case 6:
        case 5:
        case 4:
            omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
            return;
        case 7:
            GwSystem.current_board_index = (u16) D_80114DC0_3BDF60_name_5F - 0x3A;
            D_800F8D18[2] = 1;
            D_800F8D18[1] = 0xE;
            omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x12);
            return;
            
        case 3:
            omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
            omOvlHisChg(1, 0x6F, 0, 0x14);
            return;
    }
    omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
    omOvlHisChg(1, 0x70, 0, 0x14);
}

/* Item chances for the 1P item minigame: set `set`, by the player's character. */
void func_8010879C_3B193C_name_5F(s32 player, s32 set) {
    s32 i;
    s32 c = gPlayers[player].character;

    for (i = 0; i < 5; i++) {
        D_800CAFE4[i] = D_80113B78_3BCD18_name_5F[set][i][c];
    }
}

/* Chooses the item set of the 1P item minigame (type 4) for `player`: by game length, turn and the
   player's rank (flag 0x17), or at random; kept in D_80102758[8] for a retried minigame (flag
   0x15). Sets main's D_800CAFD8 item list and D_800CAFE4 chances. */
void func_8010881C_3B19BC_name_5F(s32 player) {
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
            if (D_80113B24_3BCCC4_name_5F[len][i] >= GwSystem.current_turn) {
                break;
            }
        }
        if (i >= 3) {
            osSyncPrintf("instmain.c : minigameitemset error");
            while (1) {
            }
        }
        set = D_80113B38_3BCCD8_name_5F[func_80059FD0_5ABD0(player)][i];
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
            if (D_80113B50_3BCCF0_name_5F[set][i] == 3) {
                break;
            }
        }
        if (i < 5) {
            if (set == 1) {
                D_80113B50_3BCCF0_name_5F[set][i] = 0;
            } else {
                D_80113B50_3BCCF0_name_5F[set][i] = 8;
            }
        }
    }
copy:
    i = 0;
    do {
        D_800CAFD8[i] = D_80113B50_3BCCF0_name_5F[set][i];
        i++;
    } while (i < 5);
    func_8010879C_3B193C_name_5F(player, set);
}

/* Overlay setup (D_80113700[1]): the per-player minigame data and the host work, then
   func_80102830. */
void func_80108AEC_3B1C8C_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800FA640_FB240[i] = func_80027154_27D54(0xAC, 0x7918);
        func_800B0EF0_B1AF0(D_800FA640_FB240[i], 0, 0xAC);
    }
    D_800FC890_FD490 = func_80027154_27D54(0x38, 0x7918);
    func_800B0EF0_B1AF0(D_800FC890_FD490, 0, 0x38);
    func_80102830_3AB9D0_name_5F();
}

/* `player`'s newly pressed buttons in `btn`, none for a CPU or once the instructions were
   skipped (D_800F9910 bit 0). Retail reads flag 0x15 and ignores it. */
/* NON_MATCHING: register allocation only (masked 0: the button load goes to the result's register) */
#ifdef NON_MATCHING
s32 func_80108B80_3B1D20_name_5F(s32 player, s32 btn) {
    s32 ret = 0;

    _CheckFlag(0x15);
    if (!(gPlayers[player].flags & 1) && !(D_800F9910_FA510 & 1)) {
        ret = ContBtnTrg[gPlayers[player].port] & btn;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108B80_3B1D20_name_5F);
#endif

/* `player`'s held buttons in `btn` (as func_80108B80). */
/* NON_MATCHING: register allocation only (masked 0: the button load goes to the result's register) */
#ifdef NON_MATCHING
s32 func_80108C24_3B1DC4_name_5F(s32 player, s32 btn) {
    s32 ret = 0;

    if (!(gPlayers[player].flags & 1) && !(D_800F9910_FA510 & 1)) {
        ret = ContBtn[gPlayers[player].port] & btn;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108C24_3B1DC4_name_5F);
#endif

/* `player`'s stick on `axis` (0: x, else y), 0 for a CPU, after a skip, or while its minigame
   data disables that axis (flags 0x40 x, 0x80 y). */
s32 func_80108C8C_3B1E2C_name_5F(s32 player, s32 axis) {
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

/* Counts work[0] down, then attaches the model to its parent's hook node (Ovl5FAttach) and ends. */
void func_80108D50_3B1EF0_name_5F(omObjData* obj) {
    Ovl5FAttach* hook;

    if (--obj->work[0] == 0xFF) {
        hook = obj->unk_50;
        func_800298A4_2A4A4(hook->model, 4, 0);
        func_800298A4_2A4A4(hook->model, 0x4000, 0x4000);
        func_8002C628_2D228(hook->model, hook->parent, hook->hook);
        omDelObj(obj);
    }
}

/* One step of a swing: `*angle` (capped at main's D_800BF7D4) pulls `*pos` back by
   angle * angle * 35 * scale, and `*angle` advances by main's D_800BF7A8. Returns the capped
   angle. */
f32 func_80108DCC_3B1F6C_name_5F(f32* angle, f32* pos, f32 scale) {
    f32 a;

    a = *angle;
    if (D_800BF7D4_C03D4 < a) {
        a = D_800BF7D4_C03D4;
    }
    *pos = *pos + a * a * (a >= 0.0f ? -35.0f : 35.0f) * scale;
    *angle = *angle + D_800BF7A8_C03A8;
    return a;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108E50_3B1FF0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801092B0_3B2450_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010938C_3B252C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801093D4_3B2574_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109424_3B25C4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010946C_3B260C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801094B4_3B2654_name_5F);

/* Set up demo player i: its character model, its motions (by the demo's flags) and its
   control objects. group != 0 picks the demo's second flag set. */
void func_801094F4_3B2694_name_5F(s32 i, s32 group) {
    Ovl5FDemo* demo;
    Ovl5FPlayer* p;
    s32 chr;
    s32 dir;
    omObjData* obj;

    func_8000C460_D060();
    demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
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
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_80113ED8_3BD078_name_5F[chr] | 0x460000), 0x1D);
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
        p->actA = (void (*)(omObjData*))func_80108E50_3B1FF0_name_5F;
    } else {
        p->actA = NULL;
    }
    if (p->flags & 0x10) {
        p->actB = func_801092B0_3B2450_name_5F;
    } else {
        p->actB = NULL;
    }
    obj = omAddObj(0x64, 0, 0, -1, demo->unk08);
    obj->work[0] = i;
    obj->work[1] = 0;
    obj->work[2] = 0;
    omAddObj(0x7D00, 0, 0, -1, func_80109FA0_3B3140_name_5F)->work[0] = i;
}

/* Set up all four demo players (group 0 in a 4P minigame; the real groups otherwise). */
void func_801098FC_3B2A9C_name_5F(void) {
    s32 i;
    s32 type;

    type = D_80114F72_3BE112_name_5F;
    for (i = 0; i < 4; i++) {
        switch (type) {
        case 0:
        case 3:
            func_801094F4_3B2694_name_5F(i, 0);
            break;
        default:
            func_801094F4_3B2694_name_5F(i, gPlayers[i].group);
            break;
        }
    }
}

/* Every demo player that may idle plays its idle motion. */
void func_80109988_3B2B28_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Ovl5FPlayer* p = D_800FA640_FB240[i];

        if (p->unk32 & 1) {
            func_80029BF0_2A7F0(p->model, p->mot[0], 0, 5, 2);
        }
    }
}

void func_80109A04_3B2BA4_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Ovl5FPlayer* p = D_800FA640_FB240[i];

        if (p->unk32 & 1) {
            func_80029BF0_2A7F0(p->model, p->mot[10], 0, 5, 2);
        }
    }
}

/* A demo player's control object: until the demo starts it waits; then the stick turns and
   moves the player (idle, walk, run motions) and A/B start the player's actions; when the
   demo ends (D_800FC8A0 == 11) the demo's end object takes over. */
void func_80109A80_3B2C20_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* act = D_80113EC8_3BD068_name_5F[i];

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
            D_80113EC8_3BD068_name_5F[i] = NULL;
            obj->work[1] = 1;
        }
    } else {
        if (p->flags & 1) {
            if (OVL5F_STICK_ABS(i, 0) > 10.0f || OVL5F_STICK_ABS(i, 1) > 10.0f) {
                p->rot.y = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1));
            }
            if (OVL5F_STICK_ABS(i, 0) > 30.0f || OVL5F_STICK_ABS(i, 1) > 30.0f) {
                if (p->flags & 2) {
                    if (obj->work[2] != 2) {
                        obj->work[2] = 2;
                        func_80029BF0_2A7F0(p->model, p->mot[2], 0, 5, 2);
                    }
                } else if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_80029BF0_2A7F0(p->model, p->mot[1], 0, 5, 2);
                }
            } else if (OVL5F_STICK_ABS(i, 0) > 10.0f || OVL5F_STICK_ABS(i, 1) > 10.0f) {
                if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_80029BF0_2A7F0(p->model, p->mot[1], 0, 5, 2);
                }
            } else if (obj->work[2] != 0) {
                obj->work[2] = 0;
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 5, 2);
            }
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) && p->actA != NULL) {
            act = D_80113EC8_3BD068_name_5F[i] = omAddObj(10, 0, 0, -1, p->actA);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        } else if (func_80108B80_3B1D20_name_5F(i, 0x4000) && p->actB != NULL) {
            act = D_80113EC8_3BD068_name_5F[i] = omAddObj(10, 0, 0, -1, p->actB);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        }
    }
}

/* Every frame: apply the player's pose (shadow/marker updates by the demo state). */
void func_80109FA0_3B3140_name_5F(omObjData* obj) {
    s32 i = obj->work[0];

    func_801094B4_3B2654_name_5F(i);
    if (D_800FC8A0_FD4A0 == 0) {
        func_801093D4_3B2574_name_5F(i);
        func_8010946C_3B260C_name_5F(i);
    } else {
        func_8010938C_3B252C_name_5F(i);
        func_80109424_3B25C4_name_5F(i);
    }
}

void func_8010A000_3B31A0_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104E98_3AE038_name_5F(i);
    }
}

void func_8010A038_3B31D8_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3ADF48_name_5F(i, 3, i * 60.0f - 100.0f, -50.0f, -80.0f);
    }
}

/* Markers over the players: group 0 in the middle, the others in a row. */
void func_8010A0C4_3B3264_name_5F(void) {
    s32 i;
    s32 n;

    for (i = 0, n = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3ADF48_name_5F(i, 4, 0.0f, -50.0f, -80.0f);
        } else {
            func_80104DA8_3ADF48_name_5F(i, 3, n * 60.0f - 100.0f, -50.0f, -80.0f);
            n++;
        }
    }
}

void func_8010A1A0_3B3340_name_5F(void) {
    s32 i;
    s32 n0;
    s32 n1;

    for (i = 0, n1 = 0, n0 = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3ADF48_name_5F(i, 3, n0 * 60.0f - 100.0f, -50.0f, -80.0f);
            n0++;
        } else {
            func_80104DA8_3ADF48_name_5F(i, 4, n1 * 60.0f + -50.0f, -50.0f, -80.0f);
            n1++;
        }
    }
}

void func_8010A2B0_3B3450_name_5F(void) {
    D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk04();
}

/* A player runs off the bottom of the screen (the demo's end). */
void func_8010A2EC_3B348C_name_5F(omObjData* obj) {
    Vec dir;
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];

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
        func_8010938C_3B252C_name_5F(i);
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

/* Reset the four demo players, then run the demo's setup. */
void func_8010A45C_3B35FC_name_5F(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        Ovl5FPlayer* p = D_800FA640_FB240[i];

        p->model = -1;
        p->flags = 0;
        p->unk32 = 0;
        for (j = 0; j < 11; j++) {
            p->mot[j] = -1;
        }
    }
    D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].setup();
}

/* Players plus a character part model hung on each one's hook node. */
void func_8010A4F0_3B3690_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    omObjData* obj;
    Ovl5FAttach* at;

    func_801098FC_3B2A9C_name_5F();
    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        chr = gPlayers[i].character;
        p->model2 = func_80018A30_19630(D_80113EFC_3BD09C_name_5F[chr] | 0x170000, 0x69D);
        obj = omAddObj(0x64, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
        obj->work[0] = 1;
        obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
        at = obj->unk_50;
        at->model = p->model2;
        at->parent = p->model;
        at->hook = D_80113EE4_3BD084_name_5F[chr];
    }
}

__asm__(".section .rodata");
const char D_80114A1C_3BDBBC_name_5F[] = "c005_000-cyl1_1_3";

__asm__(".section .rodata");
const char D_80114A30_3BDBD0_name_5F[] = "Luigi1-karada_2_1_1";

__asm__(".section .rodata");
const char D_80114A44_3BDBE4_name_5F[] = "c003_000-yoshi_body_2_3";

__asm__(".section .rodata");
const char D_80114A5C_3BDBFC_name_5F[] = "C002_000b-cone7_1_1_1_1_1";

__asm__(".section .rodata");
const char D_80114A78_3BDC18_name_5F[] = "c001_000-karada_1";

__asm__(".section .rodata");
const char D_80114A8C_3BDC2C_name_5F[] = "karada_2_1_1_1";

/* Balloon demo setup: each player model with a balloon (model2) and its tinted string
   (model3). */
void func_8010A628_3B37C8_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    void* tex;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        chr = gPlayers[i].character;
        p->model = func_80018A30_19630(D_80113F08_3BD0A8_name_5F[chr] | 0x190000, 0x69D);
        p->model2 = func_80018A30_19630(0x190009, 0x69D);
        p->model3 = func_80018A30_19630(0x19000C, 0x68D);
        tex = DataRead(D_80113F14_3BD0B4_name_5F[chr] | 0x190000);
        func_8003E4F4_3F0F4(func_8003D8F0_3E4F0(D_800FC834_FD434[p->model3].hmf, tex, 0, "baln_tex_mario_00_DEF"), 1, 1);
        DataClose(tex);
        func_80029A8C_2A68C(p->model3);
        func_80029AFC_2A6FC(p->model3);
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        func_800297E8_2A3E8(p->model, 0.4f, 0.4f, 0.4f);
        func_800297E8_2A3E8(p->model2, 0.4f, 0.4f, 0.4f);
        func_800297E8_2A3E8(p->model3, 0.4f, 0.4f, 0.4f);
        p->rot.y = 0.0f;
        obj = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        obj->work[0] = i;
        obj->work[1] = 0;
    }
}

/* Balloon demo player: the stick turns the player; the balloon follows. */
void func_8010A818_3B39B8_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* m = &D_800FC834_FD434[p->model];
    omObjData* end;

    func_800298A4_2A4A4(p->model2, 4, 0);
    func_800298A4_2A4A4(p->model3, 4, 0);
    func_80029714_2A314(p->model2, m->pos.x, m->pos.y, m->pos.z);
    func_80029714_2A314(p->model3, HuMathSin(p->rot.y + 180.0f) * 37.15f + m->pos.x, m->pos.y + 25.727f,
                        func_800B7890_B8490(p->rot.y + 180.0f) * 37.15f + m->pos.z);
    if (obj->work[1] == 12) {
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        end = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        end->work[0] = i;
        end->work[1] = 0;
    } else {
        if (func_80108C8C_3B1E2C_name_5F(i, 0) > 10.0f) {
            p->rot.y -= 7.0f;
        }
        if (func_80108C8C_3B1E2C_name_5F(i, 0) < -10.0f) {
            p->rot.y += 7.0f;
        }
        func_8002979C_2A39C(p->model, 0.0f, p->rot.y, 0.0f);
        func_8002979C_2A39C(p->model2, 0.0f, p->rot.y, 0.0f);
        func_8002979C_2A39C(p->model3, 0.0f, p->rot.y, 0.0f);
    }
}

/* A player runs off the bottom of the screen from its model's place (the demo's end). */
void func_8010AAA0_3B3C40_name_5F(omObjData* obj) {
    Vec dir;
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
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
        func_8010938C_3B252C_name_5F(i);
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

/* Arm demo setup: each player is an arm model (tinted by character) holding the
   character's model.
   NON_MATCHING: register allocation only (masked 0; retail gives tex s0, p s1). */
#ifdef NON_MATCHING
void func_8010AC44_3B3DE4_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        void* tex;

        p = D_800FA640_FB240[i];
        chr = gPlayers[i].character;
        p->model = LoadFormFile(0x1A0003, 0x6AD);
        p->rot.y = 30.0f;
        func_8002979C_2A39C(p->model, 0.0f, 30.0f, 0.0f);
        p->mot[0] = D_800FC834_FD434[p->model].unk02;
        func_80029E80_2AA80(p->model, 0, 1);
        tex = DataRead(D_80113F20_3BD0C0_name_5F[chr] | 0x1A0000);
        func_8003D8F0_3E4F0(D_800FC834_FD434[p->model].hmf, tex, 0, "arm_tex_00_DEF");
        DataClose(tex);
        func_80029A8C_2A68C(p->model);
        func_80029AFC_2A6FC(p->model);
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        p->scale = 0.35f;
        func_800297E8_2A3E8(p->model, 0.35f, 0.35f, 0.35f);
        p->model2 = LoadFormFile(D_800CD438_CE038[gPlayers[i].character].dir | D_800CD438_CE038[gPlayers[i].character].model, 0x69D);
        p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_80113F2C_3BD0CC_name_5F[chr][0] | 0x1A0000), 0x1D);
        func_8002C9C0_2D5C0(p->model2, p->mot[1]);
        func_80029E80_2AA80(p->model2, 0, 1);
        func_8002979C_2A39C(p->model2, 0.0f, p->rot.y, 0.0f);
        func_800297E8_2A3E8(p->model2, p->scale, p->scale, p->scale);
        obj = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        obj->work[0] = i;
        obj->work[1] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AC44_3B3DE4_name_5F);
#endif

void func_8010AEF8_3B4098_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3ADF48_name_5F(i, 3, i * 60.0f - 120.0f, -50.0f, -280.0f);
    }
}

/* Arm demo player: A swings the arm (the held model plays its motion too). */
void func_8010AF84_3B4124_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* m = &D_800FC834_FD434[p->model];
    omObjData* end;

    func_800298A4_2A4A4(p->model2, 4, 0);
    func_80029714_2A314(p->model2, m->pos.x, m->pos.y + 13.1249997764825821, m->pos.z + -5.24999991059303284);
    if (obj->work[1] == 12) {
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        end = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        end->work[0] = i;
        end->work[1] = 0;
    } else {
        if (obj->work[1] == 2 && p->count <= func_80029CE4_2A8E4(p->model)) {
            obj->work[1] = 1;
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) && obj->work[1] == 1) {
            obj->work[1] = 2;
            func_8002C9C0_2D5C0(p->model, p->mot[0]);
            p->count = func_80029D0C_2A90C(p->model);
            func_8002C9C0_2D5C0(p->model2, p->mot[1]);
        }
    }
}

void func_8010B168_3B4308_name_5F(omObjData* obj) {
    Vec dir;
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
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
        func_8010938C_3B252C_name_5F(i);
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

void func_8010B30C_3B44AC_name_5F(omObjData* obj) {
    s32 i = obj->work[0];

    func_8010456C_3AD70C_name_5F(i, ((Ovl5FPlayer*)D_800FA640_FB240[i])->unk6C);
}

/* Players as the character's alternative model (file 0x1B000B + character). */
void func_8010B33C_3B44DC_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        chr = gPlayers[i].character;
        p = D_800FA640_FB240[i];
        p->model = func_80018A30_19630((chr + 0xB) | 0x1B0000, 0xA9D);
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
        obj = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        obj->work[0] = i;
        obj->work[1] = 0;
    }
}

void func_8010B460_3B4600_name_5F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104DA8_3ADF48_name_5F(i, 3, i * 60.0f - 100.0f, 0.0f, -80.0f);
    }
}

/* A player that stays where its model is; at the demo's end its pose is kept. */
void func_8010B4F0_3B4690_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    HmfModel* m = &D_800FC834_FD434[p->model];
    omObjData* end;

    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        end = omAddObj(10, 0, 0, -1, demo->unk0C);
        end->work[0] = i;
        end->work[1] = 0;
        p->pos.x = m->pos.x;
        p->pos.y = m->pos.y;
        p->pos.z = m->pos.z;
        p->rot.x = m->rot.x;
        p->rot.y = m->rot.y;
        p->rot.z = m->rot.z;
    }
}

/* Players with the swing motions (character files 0x64-0x66). */
void func_8010B624_3B47C4_name_5F(void) {
    s32 i;
    Ovl5FPlayer* p;

    func_801098FC_3B2A9C_name_5F();
    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x64), 0x1D);
        p->mot[2] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x66), 0x1D);
        p->mot[3] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x65), 0x1D);
        p->mot[4] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x64), 0x1D);
        func_80029E80_2AA80(p->model, 2, 2);
    }
}

/* Swing demo player: A swings right, left or straight by the stick; B plays mot[1]. */
void func_8010B798_3B4938_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* end;
    s32 mot;

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        end = omAddObj(10, 0, 0, -1, demo->unk0C);
        end->work[0] = i;
        end->work[1] = 0;
        omDelObj(obj);
    } else {
        switch (obj->work[1]) {
        case 2:
            if (--p->count == -1) {
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 5, 2);
                obj->work[1] = 1;
            }
            break;
        case 3:
            if (--p->count == -1) {
                obj->work[1] = 1;
            }
            break;
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) && obj->work[1] == 1) {
            obj->work[1] = 2;
            if (func_80108C8C_3B1E2C_name_5F(i, 0) > 20) {
                func_80029BF0_2A7F0(p->model, p->mot[2], 0, 3, 0);
                mot = p->mot[2];
            } else if (func_80108C8C_3B1E2C_name_5F(i, 0) < -20) {
                func_80029BF0_2A7F0(p->model, p->mot[3], 0, 3, 0);
                mot = p->mot[3];
            } else {
                func_80029BF0_2A7F0(p->model, p->mot[4], 0, 3, 0);
                mot = p->mot[4];
            }
            p->count = func_8002CA14_2D614(mot) + 3.0f;
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x4000) && obj->work[1] == 1) {
            obj->work[1] = 3;
            func_80029BF0_2A7F0(p->model, p->mot[1], 0, 3, 0);
            p->count = func_8002CA14_2D614(p->mot[1]) + 3.0f;
        }
    }
}

/* Group 0 players carry an item (model 5 on "item_hook"); the others are a part model
   between two character nodes (D_80113F44). */
void func_8010BA24_3B4BC4_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    omObjData* obj;
    Ovl5FAttach* at;

    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        chr = gPlayers[i].character;
        if (gPlayers[i].group == 0) {
            func_801094F4_3B2694_name_5F(i, 0);
            p->unk32 = 0;
            p->model2 = func_80018A30_19630(5, 0x69D);
            obj = omAddObj(0x64, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
            obj->work[0] = 1;
            obj->unk_50 = func_80027154_27D54(0xC, 0x7918);
            func_800B0EF0_B1AF0(obj->unk_50, 0, 0xC);
            at = obj->unk_50;
            at->model = p->model2;
            at->parent = p->model;
            at->hook = (char*)D_80114BD0_3BDD70_name_5F;
            p->mot[0] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x36), 0x1D);
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x34), 0x1D);
            func_8002C9C0_2D5C0(p->model, p->mot[0]);
            func_80029E80_2AA80(p->model, 10, 10);
        } else {
            p->model = LoadFormFile(D_80113F44_3BD0E4_name_5F[chr].file | 0x1E0000, 0x6BD);
            p->model2 = LoadFormFile(D_800CD438_CE038[chr].dir | D_800CD438_CE038[chr].model, 0x6BD);
            func_80023DAC_249AC(p->model2, D_80113F44_3BD0E4_name_5F[chr].node, p->model, D_80113F44_3BD0E4_name_5F[chr].hook);
            p->scale = 0.45f;
            func_800297E8_2A3E8(p->model, 0.45f, 0.45f, 0.45f);
            obj = omAddObj(0x64, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
            obj->work[0] = i;
            obj->work[1] = 0;
            omAddObj(0x7D00, 0, 0, -1, func_80109FA0_3B3140_name_5F)->work[0] = i;
        }
    }
}

__asm__(".section .rodata");
const char D_80114AD8_3BDC78_name_5F[] = "114_Bowring1-kaodamy_3";

__asm__(".section .rodata");
const char D_80114AF0_3BDC90_name_5F[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_80114B04_3BDCA4_name_5F[] = "114_Bowring1-kaodamy_1";

__asm__(".section .rodata");
const char D_80114B1C_3BDCBC_name_5F[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_80114B2C_3BDCCC_name_5F[] = "114_Bowring1-kaodamy_5";

__asm__(".section .rodata");
const char D_80114B44_3BDCE4_name_5F[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_80114B54_3BDCF4_name_5F[] = "114_Bowring1-kaodamy";

__asm__(".section .rodata");
const char D_80114B6C_3BDD0C_name_5F[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_80114B84_3BDD24_name_5F[] = "114_Bowring1-kaodamy_2";

__asm__(".section .rodata");
const char D_80114B9C_3BDD3C_name_5F[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_80114BB0_3BDD50_name_5F[] = "114_Bowring0-kaodamy_4";

__asm__(".section .rodata");
const char D_80114BC8_3BDD68_name_5F[] = "atama_2";

__asm__(".section .rodata");
const char D_80114BD0_3BDD70_name_5F[16] = "item_hook";

/* Group 0: A plays the action motion. The others: A jumps (vel 40, gravity 9.8 scaled),
   the landing wobbles (rot.x) for 20 frames; the stick turns them. */
void func_8010BCF0_3B4E90_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* end;
    HmfModel* m;

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        end = omAddObj(10, 0, 0, -1, demo->unk0C);
        end->work[0] = i;
        end->work[1] = 0;
        omDelObj(obj);
    } else if (gPlayers[i].group == 0) {
        if (obj->work[1] == 2) {
            if (p->count <= func_80029CE4_2A8E4(p->model)) {
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 10, 8);
                obj->work[1] = 1;
            }
        } else if (OVL5F_STICK_ABS(i, 0) > 10.0f) {
            func_80029E80_2AA80(p->model, 8, 0);
        } else {
            func_80029BF0_2A7F0(p->model, p->mot[0], 0, 2, 8);
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) && obj->work[1] == 1) {
            obj->work[1] = 2;
            func_80029BF0_2A7F0(p->model, p->mot[1], 0, 2, 0);
            p->count = func_8002CA14_2D614(p->mot[1]);
        }
    } else {
        switch (obj->work[1]) {
        case 1:
            if (func_80108B80_3B1D20_name_5F(i, 0x8000)) {
                obj->work[1] = 2;
                m = &D_800FC834_FD434[p->model];
                p->floor = m->pos.y;
                p->vel = 40.0f;
            }
            break;
        case 2:
            m = &D_800FC834_FD434[p->model];
            m->pos.y += p->vel * p->scale;
            p->vel -= 9.8f;
            if (m->pos.y <= p->floor) {
                m->pos.y = p->floor;
                p->count = -1;
                p->count2 = 0;
                p->vel = 2.5f;
                obj->work[1] = 3;
            }
            p->pos.y = m->pos.y;
            break;
        case 3:
            if (p->count2 > 20) {
                obj->work[1] = 1;
                p->rot.x = 0.0f;
            } else {
                if (p->count < 0) {
                    if (p->rot.x > 8.0f) {
                        p->vel = -4.1f;
                        p->count = ~p->count;
                    }
                } else if (p->rot.x < -8.0f) {
                    p->vel = 4.1f;
                    p->count = ~p->count;
                }
                p->rot.x += p->vel / (p->count2 / 5.0f + 1.0);
                p->count2++;
            }
            break;
        }
        if (obj->work[1] == 1) {
            if (OVL5F_STICK_ABS(i, 0) > 10.0f || OVL5F_STICK_ABS(i, 1) > 10.0f) {
                p->rot.y = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1));
                func_8002979C_2A39C(p->model, 0.0f, p->rot.y, 0.0f);
            }
        }
    }
}

/* A small effect model (model3) in front of player work[2] plays once at 2.5x speed. */
void func_8010C2A8_3B5448_name_5F(omObjData* obj) {
    Ovl5FPlayer* p = D_800FA640_FB240[obj->work[2]];

    switch (obj->work[0]) {
    case 0:
        func_80029714_2A314(p->model3, HuMathSin(p->rot.y) * 30.0f + p->pos.x, p->pos.y + 50.0f,
                            func_800B7890_B8490(p->rot.y) * 30.0f + p->pos.z);
        func_8002979C_2A39C(p->model3, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(p->model3, 0.1f, 0.1f, 0.1f);
        func_800298A4_2A4A4(p->model3, 4, 0);
        func_80029FE4_2ABE4(p->model3, 2.5f);
        func_80029C74_2A874(p->model3, 0.0f);
        obj->work[0] = 1;
        break;
    case 1:
        if (func_80029CE4_2A8E4(p->model3) >= func_80029D0C_2A90C(p->model3)) {
            func_800298A4_2A4A4(p->model3, 4, 4);
            omDelObj(obj);
        }
        break;
    }
}

/* Group 0 players get two action motions; the others are small (0.3) character models
   with a part model and an effect model. */
void func_8010C40C_3B55AC_name_5F(void) {
    s32 i;
    s32 chr;
    Ovl5FPlayer* p;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        chr = gPlayers[i].character;
        if (gPlayers[i].group == 0) {
            func_801094F4_3B2694_name_5F(i, 0);
            p->mot[0] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x39), 0x1D);
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(D_800CD438_CE038[gPlayers[i].character].dir | 0x20), 0x1D);
            func_8002C9C0_2D5C0(p->model, p->mot[0]);
            func_80029E80_2AA80(p->model, 2, 2);
        } else {
            p->model = func_80018A30_19630(D_800CD438_CE038[chr].dir | D_800CD438_CE038[chr].model, 0xA9D);
            p->model2 = LoadFormFile(0x1F0001, 0xA9D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            func_800297E8_2A3E8(p->model, 0.3f, 0.3f, 0.3f);
            func_800297E8_2A3E8(p->model2, 0.3f, 0.3f, 0.3f);
            p->model3 = func_80018A30_19630(0x32000B, 0xA9D);
            obj = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
            obj->work[0] = i;
            obj->work[1] = 0;
        }
        p->scale = 0.5f;
    }
}

void func_8010C61C_3B57BC_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* o;

    if (gPlayers[i].group != 0) {
        func_800298A4_2A4A4(p->model2, 4, 0);
        func_80029714_2A314(p->model2, HuMathSin(p->pos.y) * 9.0f + model->pos.x, model->pos.y - 24.0f,
                            func_800B7890_B8490(p->pos.y) * 9.0f + model->pos.z);
    }
    if (obj->work[1] == 12) {
        if (gPlayers[i].group != 0) {
            func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
            func_80029714_2A314(p->model2, HuMathSin(model->pos.y) * 9.0f + model->pos.x, model->pos.y - 24.0f,
                                func_800B7890_B8490(model->pos.y) * 9.0f + model->pos.z);
        }
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        if (gPlayers[i].group == 0) {
            omDelObj(obj);
        }
    } else {
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
            || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
            p->rot.y = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1));
            func_8002979C_2A39C(p->model, 0.0f, p->rot.y, 0.0f);
        }
        if (gPlayers[i].group == 0) {
            switch (obj->work[1]) {
            case 1:
                if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
                    || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
                    func_80029BF0_2A7F0(p->model, p->mot[1], 0, 3, 2);
                    obj->work[1] = 2;
                }
                break;
            case 2:
                if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) <= 10.0f
                    && OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) <= 10.0f) {
                    func_80029BF0_2A7F0(p->model, p->mot[0], 0, 3, 2);
                    obj->work[1] = 1;
                }
                break;
            }
        } else {
            switch (obj->work[1]) {
            case 1:
                if (func_80108B80_3B1D20_name_5F(i, 0x8000) != 0) {
                    o = omAddObj(1000, 0, 0, -1, func_8010C2A8_3B5448_name_5F);
                    o->work[0] = 0;
                    o->work[2] = i;
                    p->pos.x = model->pos.x;
                    p->pos.y = model->pos.y;
                    p->pos.z = model->pos.z;
                    obj->work[1] = 2;
                    obj->work[2] = 30;
                }
                break;
            case 2:
                if (--obj->work[2] == 255) {
                    obj->work[1] = 1;
                }
                break;
            }
            func_8002979C_2A39C(p->model2, 0.0f, p->rot.y, 0.0f);
        }
    }
}

void func_8010CD08_3B5EA8_name_5F(void) {
    s32 i;
    s32 ch;
    s32 dir;
    Ovl5FPlayer* p;
    omObjData* o;

    for (i = 0; i < 4; i++) {
        ch = gPlayers[i].character;
        dir = D_800CD438_CE038[ch].dir;
        p = D_800FA640_FB240[i];
        if (gPlayers[i].group == 0) {
            p->model = func_80018A30_19630(dir | D_800CD438_CE038[ch].model, 0xA9D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            p->scale = 0.6f;
            func_800297E8_2A3E8(p->model, 0.6f, 0.6f, 0.6f);
            p->model2 = func_80018A30_19630(0x200000, 0x69D);
            func_80029714_2A314(p->model2, 0.0f, -1000.0f, 0.0f);
            func_8002979C_2A39C(p->model2, 0.0f, 50.0f, 0.0f);
            p->scale = 0.3f;
            func_800297E8_2A3E8(p->model2, 0.3f, 0.3f, 0.3f);
            p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 0x26), 0x1D);
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(dir | 0x27), 0x1D);
            func_8002C9C0_2D5C0(p->model, p->mot[0]);
            func_80029E80_2AA80(p->model, 2, 2);
            p->count = 0;
            p->floor = 300.0f;
        } else {
            p->model = func_80018A30_19630(D_80113F8C_3BD12C_name_5F[ch] | 0x200000, 0xA9D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            func_800297E8_2A3E8(p->model, 0.2f, 0.2f, 0.2f);
            func_80029FE4_2ABE4(p->model, 0.0f);
            func_80029C74_2A874(p->model, func_80029D0C_2A90C(p->model));
        }
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
    }
}

void func_8010CFB8_3B6158_name_5F(void) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3ADF48_name_5F(i, 4, 0.0f, -50.0f, -80.0f);
        } else {
            func_80104DA8_3ADF48_name_5F(i, 3, j * 60.0f - 100.0f, 0.0f, -80.0f);
            j++;
        }
    }
}

void func_8010D098_3B6238_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;

    if (gPlayers[i].group == 0) {
        func_800298A4_2A4A4(p->model2, 4, 0);
        if (D_800FC8A0_FD4A0 != 0) {
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->floor, model->pos.z);
        }
    }
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            p->unk2C = model->pos.y;
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
    } else if (gPlayers[i].group == 0) {
        switch (obj->work[1]) {
        case 1:
            p->floor -= 10.0f;
            if (p->floor < 0.0f) {
                p->count = 1;
                p->floor = 0.0f;
                obj->work[1] = 2;
            }
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->floor, model->pos.z);
            break;
        case 2:
            model->pos.y += 10.0f;
            if (model->pos.y > p->unk2C + 100.0f) {
                model->pos.y = p->unk2C + 100.0f;
                obj->work[1] = 3;
            }
            break;
        case 3:
            if (func_80108B80_3B1D20_name_5F(i, 0x8000) != 0) {
                obj->work[1] = 4;
            }
            break;
        case 4:
            model->pos.y -= 5.0f;
            if (model->pos.y < p->unk2C + 30.0f) {
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 2, 0);
                obj->work[1] = 5;
            }
            break;
        case 5:
            model->pos.y -= 5.0f;
            if (model->pos.y < p->unk2C) {
                model->pos.y = p->unk2C;
                p->count2 = 20;
                obj->work[1] = 6;
            }
            break;
        case 6:
            if (--p->count2 == -1) {
                obj->work[1] = 7;
            }
            break;
        case 7:
            model->pos.y += 5.0f;
            if (model->pos.y > p->unk2C + 100.0f) {
                model->pos.y = p->unk2C + 100.0f;
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 2, 0);
                p->count2 = 20;
                obj->work[1] = 8;
            }
            break;
        case 8:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                obj->work[1] = 9;
            }
            break;
        case 9:
            if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
                obj->work[1] = 10;
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 10, 2);
            }
            break;
        case 10:
            if (--p->count2 == -1) {
                obj->work[1] = 3;
            }
            break;
        }
        if (p->count != 0) {
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->floor, model->pos.z);
        }
    } else {
        if (obj->work[1] == 2) {
            if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
                obj->work[1] = 1;
            }
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) != 0 && obj->work[1] == 1) {
            obj->work[1] = 2;
            func_80029FE4_2ABE4(p->model, 1.0f);
            func_80029C74_2A874(p->model, 0.0f);
        }
    }
}

void func_8010D640_3B67E0_name_5F(void) {
    s32 i;
    s32 dir;
    Ovl5FPlayer* p;

    func_801098FC_3B2A9C_name_5F();
    for (i = 0; i < 4; i++) {
        dir = D_800CD438_CE038[gPlayers[i].character].dir;
        p = D_800FA640_FB240[i];
        p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 0x74), 0x1D);
        p->mot[1] = func_8002C8B8_2D4B8(DataRead(dir | 0x7A), 0x1D);
        p->mot[2] = func_8002C8B8_2D4B8(DataRead(dir | 0x7B), 0x1D);
        p->mot[3] = func_8002C8B8_2D4B8(DataRead(dir | 0x7C), 0x1D);
        p->mot[4] = func_8002C8B8_2D4B8(DataRead(dir | 0x76), 0x1D);
        p->mot[5] = func_8002C8B8_2D4B8(DataRead(dir | 0x78), 0x1D);
        p->mot[6] = func_8002C8B8_2D4B8(DataRead(dir | 0x77), 0x1D);
        p->mot[7] = func_8002C8B8_2D4B8(DataRead(dir | 0x79), 0x1D);
        p->count = 0;
    }
}

void func_8010D798_3B6938_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    s32 dir;
    s32 m;

    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
    } else {
        /* the stick's direction in quarters: 0 = none, 1-4 */
        dir = 0;
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 20.0f
            || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 20.0f) {
            dir = func_8002D958_2E558(func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), func_80108C8C_3B1E2C_name_5F(i, 1)) + 45.0f)
                  / 90.0f + 1.0f;
        }
        switch (obj->work[1]) {
        case 1:
            if (func_80108B80_3B1D20_name_5F(i, 0x8000) != 0) {
                obj->work[1] = 2;
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 8, 0);
            }
            if (func_80108B80_3B1D20_name_5F(i, 0x4000) != 0) {
                obj->work[1] = 2;
                func_80029BF0_2A7F0(p->model, p->mot[2], 0, 8, 0);
            }
            if (func_80108B80_3B1D20_name_5F(i, 0x2000) != 0) {
                obj->work[1] = 2;
                func_80029BF0_2A7F0(p->model, p->mot[3], 0, 8, 0);
            }
            if (p->count != dir && dir != 0) {
                switch (dir) {
                case 1:
                    m = 4;
                    break;
                case 2:
                    m = 5;
                    break;
                case 3:
                    m = 6;
                    break;
                case 4:
                    m = 7;
                    break;
                default:
                    m = 4;
                    break;
                }
                obj->work[1] = 2;
                func_80029BF0_2A7F0(p->model, p->mot[m], 0, 8, 0);
            }
            break;
        case 2:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                obj->work[1] = 3;
            }
            break;
        case 3:
            if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
                obj->work[1] = 4;
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 8, 2);
            }
            break;
        case 4:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                obj->work[1] = 1;
            }
            break;
        }
        p->count = dir;
    }
}

void func_8010DC40_3B6DE0_name_5F(void) {
    s32 i;
    s32 ch;
    s32 dir;
    Ovl5FPlayer* p;
    omObjData* o;

    for (i = 0; i < 4; i++) {
        ch = gPlayers[i].character;
        dir = D_800CD438_CE038[ch].dir;
        p = D_800FA640_FB240[i];
        if (gPlayers[i].group == 0) {
            p->model = func_80018A30_19630(0x220003, 0x69D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            func_800297E8_2A3E8(p->model, 0.25f, 0.25f, 0.25f);
            p->model2 = func_80018A30_19630(dir | D_800CD438_CE038[ch].model, 0x69D);
            func_800297E8_2A3E8(p->model2, 0.4f, 0.4f, 0.4f);
            func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[p->model].mtx, 0.0f, 70.0f, 0.0f);
            func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[p->model2].mtx, 0.0f, 70.0f, 0.0f);
        } else {
            p->model = func_80018A30_19630(dir | D_800CD438_CE038[ch].model, 0x69D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            p->rot.x = p->rot.z = 0.0f;
            p->rot.y = 180.0f;
            func_8002979C_2A39C(p->model, p->rot.x, 180.0f, p->rot.z);
            func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
            p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 0x9A), 0x1D);
            p->mot[1] = func_8002C8B8_2D4B8(DataRead(dir | 0x9B), 0x1D);
            func_8002C9C0_2D5C0(p->model, p->mot[0]);
            func_80029E80_2AA80(p->model, 1, 1);
        }
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
    }
}

void func_8010DF10_3B70B0_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    Vec stick;
    Vec* v;
    f32 len;
    f32 angle;

    if (gPlayers[i].group == 0) {
        func_800298A4_2A4A4(p->model2, 4, 0);
        func_80029714_2A314(p->model2, model->pos.x, model->pos.y, model->pos.z);
    }
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
        if (gPlayers[i].group == 0) {
            func_8002979C_2A39C(p->model2, p->rot.x, p->rot.y, p->rot.z);
        }
    } else if (obj->work[1] == 0) {
        p->vel = model->pos.x;
        p->floor = model->pos.y;
        p->unk9C = model->pos.z;
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
    } else if (gPlayers[i].group != 0) {
        v = &stick;
        v->x = func_80108C8C_3B1E2C_name_5F(i, 0);
        v->y = 0.0f;
        v->z = func_80108C8C_3B1E2C_name_5F(i, 1);
        len = HuVecGetLength3F(v);
        if (len > 70.0f) {
            len = 70.0f;
        }
        angle = func_8002D958_2E558(func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1)) - 90.0f);
        if (((angle > 180.0f) & (angle < 360.0f)) && len > 10.0f && (obj->work[1] == 1 || obj->work[1] == 2)) {
            obj->work[1] = 2;
            model->rot.y = angle - 90.0f;
            func_80029C74_2A874(p->model, func_80029D0C_2A90C(p->model) * len / 70.0f);
        }
        switch (obj->work[1]) {
        case 1:
            break;
        case 2:
            if (len < 5.0f) {
                obj->work[1] = 3;
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 8, 0);
            }
            break;
        case 3:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                obj->work[1] = 4;
            }
            break;
        case 4:
            if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
                obj->work[1] = 5;
                func_80029BF0_2A7F0(p->model, p->mot[0], 0, 10, 1);
            }
            break;
        case 5:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                obj->work[1] = 1;
            }
            break;
        }
    } else {
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f) {
            if (func_80108C8C_3B1E2C_name_5F(i, 0) > 0) {
                func_80029714_2A314(p->model, model->pos.x + 2.0f, model->pos.y, model->pos.z);
                if (model->pos.x > p->vel + 10.0f) {
                    model->pos.x = p->vel + 10.0f;
                }
            } else {
                func_80029714_2A314(p->model, model->pos.x - 2.0f, model->pos.y, model->pos.z);
                if (model->pos.x < p->vel - 10.0f) {
                    model->pos.x = p->vel - 10.0f;
                }
            }
        }
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
            if (func_80108C8C_3B1E2C_name_5F(i, 1) < 0) {
                func_80029714_2A314(p->model, model->pos.x, model->pos.y, model->pos.z + 2.0f);
                if (model->pos.z > p->unk9C + 10.0f) {
                    model->pos.z = p->unk9C + 10.0f;
                }
            } else {
                func_80029714_2A314(p->model, model->pos.x, model->pos.y, model->pos.z - 2.0f);
                if (model->pos.z < p->unk9C - 10.0f) {
                    model->pos.z = p->unk9C - 10.0f;
                }
            }
        }
        func_80029714_2A314(p->model2, model->pos.x, model->pos.y, model->pos.z);
    }
}

void func_8010E65C_3B77FC_name_5F(void) {
    s32 i;
    s32 ch;
    Ovl5FPlayer* p;
    void* data;
    omObjData* o;

    for (i = 0; i < 4; i++) {
        p = D_800FA640_FB240[i];
        ch = gPlayers[i].character;
        p->model = LoadFormFile(D_80113F98_3BD138_name_5F[ch] | 0x230000, 0x2A9);
        p->scale = 0.8f;
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        func_800297E8_2A3E8(p->model, 0.8f, 0.8f, 0.8f);
        data = DataRead(D_800CD438_CE038[ch].dir | 0xDF);
        func_8003D8F0_3E4F0(D_800FC834_FD434[p->model].hmf, data, 0, D_80113FA4_3BD144_name_5F[ch]);
        DataClose(data);
        func_80029A8C_2A68C(p->model);
        func_80029AFC_2A6FC(p->model);
        o = omAddObj(0x7918, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
        o->work[2] = 0;
        omAddObj(0x7D00, 0, 0, -1, func_80109FA0_3B3140_name_5F)->work[0] = i;
    }
}

void func_8010E844_3B79E4_name_5F(void) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3ADF48_name_5F(i, 4, 0.0f, -10.0f, -80.0f);
        } else {
            func_80104DA8_3ADF48_name_5F(i, 3, j * 60.0f - 100.0f, -10.0f, -80.0f);
            j++;
        }
    }
}

__asm__(".section .rodata");
const char D_80114C24_3BDDC4_name_5F[] = "c005l_0_DEF";

__asm__(".section .rodata");
const char D_80114C30_3BDDD0_name_5F[] = "c004l_0_DEF";

__asm__(".section .rodata");
const char D_80114C3C_3BDDDC_name_5F[] = "c003l_0_DEF";

__asm__(".section .rodata");
const char D_80114C48_3BDDE8_name_5F[] = "c002l_0_DEF";

__asm__(".section .rodata");
const char D_80114C54_3BDDF4_name_5F[] = "c001l_0_DEF";

__asm__(".section .rodata");
const char D_80114C60_3BDE00_name_5F[16] = "c000l_0_DEF";

void func_8010E920_3B7AC0_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* o;

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        omDelObj(obj);
    } else {
        /* the target tilt for the stick's quarter (work[2]) */
        switch (obj->work[2]) {
        case 0:
            p->vel = 0.0f;
            p->floor = 0.0f;
            break;
        case 1:
            p->vel = 45.0f;
            p->floor = 0.0f;
            break;
        case 2:
            p->vel = 0.0f;
            p->floor = 90.0f;
            break;
        case 3:
            p->vel = -45.0f;
            p->floor = 0.0f;
            break;
        case 4:
            p->vel = 0.0f;
            p->floor = -90.0f;
            break;
        }
        if (p->vel == 0.0f) {
            if (p->rot.x > 0.0f) {
                p->rot.x -= 10.0f;
                if (p->rot.x < 0.0f) {
                    p->rot.x = 0.0f;
                }
            }
            if (p->rot.x < 0.0f) {
                p->rot.x += 10.0f;
                if (p->rot.x > 0.0f) {
                    p->rot.x = 0.0f;
                }
            }
        }
        if (p->floor == 0.0f) {
            if (p->rot.y > 0.0f) {
                p->rot.y -= 10.0f;
                if (p->rot.y < 0.0f) {
                    p->rot.y = 0.0f;
                }
            }
            if (p->rot.y < 0.0f) {
                p->rot.y += 10.0f;
                if (p->rot.y > 0.0f) {
                    p->rot.y = 0.0f;
                }
            }
        }
        if (p->vel > 0.0f) {
            p->rot.x += 10.0f;
            if (p->rot.x > p->vel) {
                p->rot.x = p->vel;
            }
        }
        if (p->vel < 0.0f) {
            p->rot.x -= 10.0f;
            if (p->rot.x < p->vel) {
                p->rot.x = p->vel;
            }
        }
        if (p->floor > 0.0f) {
            p->rot.y += 10.0f;
            if (p->rot.y > p->floor) {
                p->rot.y = p->floor;
            }
        }
        if (p->floor < 0.0f) {
            p->rot.y -= 10.0f;
            if (p->rot.y < p->floor) {
                p->rot.y = p->floor;
            }
        }
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
            || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
            p->vel = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1)) + 45.0f;
            p->vel = func_8002D958_2E558(p->vel);
            if (p->vel < 360.0f) {
                obj->work[2] = 4;
            }
            if (p->vel < 270.0f) {
                obj->work[2] = 3;
            }
            if (p->vel < 180.0f) {
                obj->work[2] = 2;
            }
            if (p->vel < 90.0f) {
                obj->work[2] = 1;
            }
        } else {
            obj->work[2] = 0;
        }
    }
}

void func_8010EEB4_3B8054_name_5F(void) {
    s32 i;
    s32 ch;
    s32 dir;
    Ovl5FPlayer* p;
    omObjData* o;

    for (i = 0; i < 4; i++) {
        ch = gPlayers[i].character;
        dir = D_800CD438_CE038[ch].dir;
        p = D_800FA640_FB240[i];
        if (gPlayers[i].group == 0) {
            p->model2 = func_80018A30_19630(dir | D_800CD438_CE038[ch].model, 0x69D);
            func_8002979C_2A39C(p->model2, 0.0f, -90.0f, 0.0f);
            func_800297E8_2A3E8(p->model2, 0.5f, 0.5f, 0.5f);
            p->model = func_80018A30_19630(0x240006, 0x69D);
            func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
            func_8002979C_2A39C(p->model, 0.0f, 90.0f, 0.0f);
            func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
            p->mot[0] = func_8002C8B8_2D4B8(DataRead(dir | 0x80), 0x1D);
            func_8002C9C0_2D5C0(p->model2, p->mot[0]);
            func_80029E80_2AA80(p->model2, 1, 1);
            func_80029E80_2AA80(p->model, 1, 1);
            func_80029C74_2A874(p->model2, 30.0f);
            func_80029C74_2A874(p->model, 30.0f);
            p->vel = 0.0f;
            o = omAddObj(0x7D00, 0, 0, -1, func_8010F1A4_3B8344_name_5F);
            o->work[0] = i;
            o->work[1] = 0;
        } else {
            func_801094F4_3B2694_name_5F(i, 1);
            func_8002979C_2A39C(p->model, 0.0f, 90.0f, 0.0f);
        }
    }
}

void func_8010F0C8_3B8268_name_5F(void) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            func_80104DA8_3ADF48_name_5F(i, 4, 0.0f, -50.0f, -230.0f);
        } else {
            func_80104DA8_3ADF48_name_5F(i, 3, j * 60.0f - 100.0f, -50.0f, -230.0f);
            j++;
        }
    }
}

void func_8010F1A4_3B8344_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    f32 sum;
    s32 k;

    if (gPlayers[i].group == 0) {
        func_800298A4_2A4A4(p->model2, 4, 0);
        func_80029714_2A314(p->model2, model->pos.x, model->pos.y, model->pos.z - 50.0f);
    }
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
        if (gPlayers[i].group == 0) {
            func_8002979C_2A39C(p->model2, p->rot.x, p->rot.y, p->rot.z);
        }
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
    } else {
        /* the stick's x sets the motion speed, averaged over the last 8 frames */
        p->count = func_80108C8C_3B1E2C_name_5F(i, 0);
        if (p->count < -45) {
            p->count = -45;
        } else if (p->count > 45) {
            p->count = 45;
        }
        sum = (p->count + 45) / 90.0f * 60.0f;
        D_80113FBC_3BD15C_name_5F[D_80113FDC_3BD17C_name_5F] = sum;
        D_80113FDC_3BD17C_name_5F = (D_80113FDC_3BD17C_name_5F + 1) & 7;
        sum = 0.0f;
        for (k = 0; k < 8; k++) {
            sum += D_80113FBC_3BD15C_name_5F[k];
        }
        sum /= 8.0f;
        func_80029C74_2A874(p->model, sum);
        func_80029C74_2A874(p->model2, sum);
    }
}

void func_8010F488_3B8628_name_5F(omObjData* obj) {
    Ovl5FPlayer* p = D_800FA640_FB240[obj->work[0]];

    switch (obj->work[1]) {
    case 0:
        func_8002C570_2D170(p->model);
        func_8002C9C0_2D5C0(p->model, p->mot[4]);
        obj->work[1] = 1;
        break;
    case 1:
        if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
            obj->work[1] = 2;
        }
        break;
    case 2:
        func_8002C9C0_2D5C0(p->model, p->mot[0]);
        func_8002C524_2D124(p->model, p->mot[3], 2);
        obj->work[1] = 100;
        break;
    }
}

void func_8010F578_3B8718_name_5F(omObjData* obj) {
    Ovl5FPlayer* p = D_800FA640_FB240[obj->work[0]];

    switch (obj->work[1]) {
    case 0:
        func_8002C570_2D170(p->model);
        func_8002C9C0_2D5C0(p->model, p->mot[5]);
        obj->work[1] = 1;
        break;
    case 1:
        if (func_80029CE4_2A8E4(p->model) >= func_80029D0C_2A90C(p->model)) {
            obj->work[1] = 2;
        }
        break;
    case 2:
        func_8002C9C0_2D5C0(p->model, p->mot[0]);
        func_8002C524_2D124(p->model, p->mot[3], 2);
        obj->work[1] = 100;
        break;
    }
}

void func_8010F668_3B8808_name_5F(void) {
    s32 i;
    s32 dir;
    Ovl5FPlayer* p;
    omObjData* o;
    Ovl5FAttach* hook;

    func_801098FC_3B2A9C_name_5F();
    for (i = 0; i < 4; i++) {
        dir = D_800CD438_CE038[gPlayers[i].character].dir;
        p = D_800FA640_FB240[i];
        if (gPlayers[i].group == 0) {
            p->mot[3] = func_8002C8B8_2D4B8(DataRead(dir | 0x19), 0x1D);
            p->mot[4] = func_8002C8B8_2D4B8(DataRead(dir | 0x1A), 0x1D);
            p->mot[5] = func_8002C8B8_2D4B8(DataRead(dir | 0x1B), 0x1D);
            p->model2 = func_80018A30_19630(0x10012, 0x69D);
            o = omAddObj(100, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
            o->work[0] = 1;
            o->unk_50 = func_80027154_27D54(sizeof(Ovl5FAttach), 0x7918);
            func_800B0EF0_B1AF0(o->unk_50, 0, sizeof(Ovl5FAttach));
            hook = o->unk_50;
            hook->model = p->model2;
            hook->parent = p->model;
            hook->hook = (char*)D_80114BD0_3BDD70_name_5F;
            func_8002C524_2D124(p->model, p->mot[3], 2);
            p->actA = func_8010F488_3B8628_name_5F;
            p->actB = func_8010F578_3B8718_name_5F;
        } else {
            p->mot[3] = func_8002C8B8_2D4B8(DataRead(dir | 0x13), 0x1D);
            p->model2 = func_80018A30_19630(0x250001, 0x69D);
            o = omAddObj(100, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
            o->work[0] = 1;
            o->unk_50 = func_80027154_27D54(sizeof(Ovl5FAttach), 0x7918);
            func_800B0EF0_B1AF0(o->unk_50, 0, sizeof(Ovl5FAttach));
            hook = o->unk_50;
            hook->model = p->model2;
            hook->parent = p->model;
            hook->hook = (char*)D_80114BD0_3BDD70_name_5F;
            func_8002C524_2D124(p->model, p->mot[3], 2);
        }
        func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
    }
}

void func_8010F8BC_3B8A5C_name_5F(omObjData* obj) {
    s32 i = obj->work[0];
    Ovl5FPlayer* p = D_800FA640_FB240[i];
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    omObjData* act = D_80113EC8_3BD068_name_5F[i];
    omObjData* o;

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
    } else if (D_800FC8A0_FD4A0 == 11) {
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = i;
        o->work[1] = 0;
        if (act != NULL) {
            omDelObj(act);
        }
        omDelObj(obj);
    } else if (obj->work[1] == 2) {
        if (act->work[1] == 100) {
            omDelObj(act);
            D_80113EC8_3BD068_name_5F[i] = NULL;
            obj->work[1] = 1;
        }
    } else {
        if (p->flags & 1) {
            if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
                || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
                p->rot.y = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1));
            }
            if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 30.0f
                || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 30.0f) {
                if (p->flags & 2) {
                    if (obj->work[2] != 2) {
                        obj->work[2] = 2;
                        func_8002C9C0_2D5C0(p->model, p->mot[2]);
                        func_80029E80_2AA80(p->model, 0, 2);
                    }
                } else if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_8002C9C0_2D5C0(p->model, p->mot[1]);
                    func_80029E80_2AA80(p->model, 0, 2);
                }
            } else if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
                       || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
                if (obj->work[2] != 1) {
                    obj->work[2] = 1;
                    func_8002C9C0_2D5C0(p->model, p->mot[1]);
                    func_80029E80_2AA80(p->model, 0, 2);
                }
            } else if (obj->work[2] != 0) {
                obj->work[2] = 0;
                func_8002C9C0_2D5C0(p->model, p->mot[0]);
                func_80029E80_2AA80(p->model, 0, 2);
            }
        }
        if (func_80108B80_3B1D20_name_5F(i, 0x8000) != 0 && p->actA != NULL) {
            act = D_80113EC8_3BD068_name_5F[i] = omAddObj(10, 0, 0, -1, p->actA);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        } else if (func_80108B80_3B1D20_name_5F(i, 0x4000) != 0 && p->actB != NULL) {
            act = D_80113EC8_3BD068_name_5F[i] = omAddObj(10, 0, 0, -1, p->actB);
            act->work[0] = i;
            act->work[1] = 0;
            obj->work[1] = 2;
            obj->work[2] = 0;
        }
    }
}

/* NON_MATCHING: scheduling only (the character index's shift is placed after the player load) */
#ifdef NON_MATCHING
void func_8010FDD8_3B8F78_name_5F(void) {
    s32 i;
    s32 ch;
    Ovl5FPlayer* p;
    omObjData* o;
    Ovl5FAttach* hook;

    for (i = 0; i < 4; i++) {
        ch = gPlayers[i].character;
        p = D_800FA640_FB240[i];
        p->model = LoadFormFile(D_80113FE0_3BD180_name_5F[ch] | 0x260000, 0x69D);
        func_800297E8_2A3E8(p->model, 0.4f, 0.4f, 0.4f);
        p->model2 = func_80018A30_19630(gPlayers[i].group != 0 ? 0x260003 : 0x260002, 0x69D);
        o = omAddObj(100, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
        o->work[0] = 1;
        o->unk_50 = func_80027154_27D54(sizeof(Ovl5FAttach), 0x7918);
        func_800B0EF0_B1AF0(o->unk_50, 0, sizeof(Ovl5FAttach));
        hook = o->unk_50;
        hook->model = p->model2;
        hook->parent = p->model;
        hook->hook = "pengin-item_fook";
        p->mot[0] = func_8002C8B8_2D4B8(DataRead(0x260015), 0x1D);
        p->mot[1] = func_8002C8B8_2D4B8(DataRead(0x260016), 0x1D);
        p->mot[2] = func_8002C8B8_2D4B8(DataRead(0x26001B), 0x1D);
        p->mot[3] = func_8002C8B8_2D4B8(DataRead(0x26001E), 0x1D);
        p->mot[4] = func_8002C8B8_2D4B8(DataRead(0x26001C), 0x1D);
        p->mot[5] = func_8002C8B8_2D4B8(DataRead(0x26001D), 0x1D);
        func_8002C9C0_2D5C0(p->model, p->mot[0]);
        func_80029E80_2AA80(p->model, 0, 2);
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
        o->work[2] = 10;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010FDD8_3B8F78_name_5F);
#endif

void func_80110050_3B91F0_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FDemoPlayer* p = DEMO_PLAYER(player);
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    f32 t;

    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        return;
    }
    switch (obj->work[1]) {
    case 1:
        if (obj->work[2] >= 31) {
            func_80029BF0_2A7F0(p->model, p->unk38, 0, 2, 2);
            obj->work[1] = 2;
        }
        break;
    case 2:
        func_80029FE4_2ABE4(p->model, (obj->work[2] - 10) / 50.0f);
        if (obj->work[2] < 20) {
            func_80029BF0_2A7F0(p->model, p->unk36, 0, 5, 2);
            func_80029FE4_2ABE4(p->model, 1.0f);
            obj->work[1] = 1;
        }
        if (obj->work[2] >= 70) {
            func_80029BF0_2A7F0(p->model, p->unk3A, 0, 2, 2);
            func_80029FE4_2ABE4(p->model, 1.0f);
            obj->work[3] = 20;
            obj->work[1] = 3;
        }
        break;
    case 3:
        if (--obj->work[3] == 0xFF) {
            obj->work[1] = 4;
        }
        break;
    case 4:
        if (obj->work[2] < 60) {
            func_80029BF0_2A7F0(p->model, p->unk38, 0, 5, 2);
            obj->work[1] = 2;
        } else if (obj->work[2] >= 90) {
            func_80029BF0_2A7F0(p->model, p->unk3E, 0, 2, 0);
            obj->work[1] = 5;
        }
        break;
    case 5:
        if (func_80029E3C_2AA3C(p->model) == -1.0f
            && (t = func_80029CE4_2A8E4(p->model), func_80029D0C_2A90C(p->model) <= t)) {
            func_80029BF0_2A7F0(p->model, p->unk40, 0, 2, 0);
            obj->work[1] = 6;
        }
        break;
    case 6:
        if (func_80029E3C_2AA3C(p->model) == -1.0f
            && (t = func_80029CE4_2A8E4(p->model), func_80029D0C_2A90C(p->model) <= t)) {
            func_80029BF0_2A7F0(p->model, p->unk36, 0, 2, 2);
            func_80029FE4_2ABE4(p->model, 1.0f);
            obj->work[2] = 10;
            obj->work[1] = 1;
        }
        break;
    }
    if (func_80108B80_3B1D20_name_5F(player, 0x8000) != 0) {
        obj->work[2] += 15;
        if (obj->work[2] > 100) {
            obj->work[2] = 100;
        }
    }
    obj->work[2] -= 2;
    if (obj->work[2] < 10) {
        obj->work[2] = 10;
    }
}

void func_80110480_3B9620_name_5F(void) {
    Ovl5FDemoPlayer* p;
    omObjData* o;
    s32 dir;
    s32 chr;
    s32 i;

    for (i = 0; i < 4; i++) {
        chr = gPlayers[i].character;
        dir = D_800CD438_CE038[chr].dir;
        p = DEMO_PLAYER(i);
        if (gPlayers[i].group == 0) {
            func_800297E8_2A3E8(p->model = func_80018A30_19630(dir | D_800CD438_CE038[chr].model, 0x69D), 0.5f, 0.5f, 0.5f);
            p->unk4C = LoadFormFile(0x27000A, 0x69D);
            func_80023DAC_249AC(p->unk4E = LoadFormFile(D_80113FFC_3BD19C_name_5F[chr][4][0] | 0x270000, 0x69D),
                                D_801141A0_3BD340_name_5F[chr][0], p->model, D_801141D0_3BD370_name_5F[chr][0]);
            func_80023DAC_249AC(p->unk50 = LoadFormFile(D_80113FFC_3BD19C_name_5F[chr][5][0] | 0x270000, 0x69D),
                                D_801141A0_3BD340_name_5F[chr][1], p->model, D_801141D0_3BD370_name_5F[chr][1]);
            p->unk36 = D_800FC834_FD434[p->model].unk02;
            p->unk38 = func_8002C8B8_2D4B8(DataRead(dir | D_80113FFC_3BD19C_name_5F[chr][1][0]), 0x1D);
            p->unk3A = func_8002C8B8_2D4B8(DataRead(dir | D_80113FFC_3BD19C_name_5F[chr][2][0]), 0x1D);
            p->unk3C = func_8002C8B8_2D4B8(DataRead(dir | D_80113FFC_3BD19C_name_5F[chr][0][0]), 0x1D);
            p->unk3E = func_8002C8B8_2D4B8(DataRead(dir | D_80113FFC_3BD19C_name_5F[chr][3][0]), 0x1D);
            p->unk8C = 0;
        } else {
            p->model = func_80018A30_19630(D_80114204_3BD3A4_name_5F[chr][0] | 0x270000, 0x69D);
            p->rot.x = p->rot.y = p->rot.z = 0.0f;
            func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
            func_800297E8_2A3E8(p->model, 0.8f, 0.8f, 0.8f);
        }
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
    }
}

__asm__(".section .rodata");
const char D_80114CB0_3BDE50_name_5F[] = "c005_000-bmerge6";

__asm__(".section .rodata");
const char D_80114CC4_3BDE64_name_5F[] = "Luigi1-migi-te1_1";

__asm__(".section .rodata");
const char D_80114CD8_3BDE78_name_5F[] = "c003_000-bmerge1_8";

__asm__(".section .rodata");
const char D_80114CEC_3BDE8C_name_5F[] = "C002_000b-bmerge16";

__asm__(".section .rodata");
const char D_80114D00_3BDEA0_name_5F[] = "c001_000-migi-te2_3";

__asm__(".section .rodata");
const char D_80114D14_3BDEB4_name_5F[20] = "migi-te3_2_1";

void func_80110784_3B9924_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FDemoPlayer* p = DEMO_PLAYER(player);
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    HmfModel* model = &D_800FC834_FD434[p->model];
    HmfModel* other;
    omObjData* o;
    f32 t;
    s32 i;

    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        return;
    }
    if (gPlayers[player].group == 0) {
        switch (obj->work[1]) {
        case 1:
            if (func_80108B80_3B1D20_name_5F(player, 0x8000) != 0) {
                p->unk8C = 0;
                obj->work[1] = 2;
                func_80029BF0_2A7F0(p->model, p->unk38, 0, 5, 0);
            } else if (ABS(func_80108C8C_3B1E2C_name_5F(player, 0)) > 10.0f) {
                switch (p->unk8C) {
                case 0:
                    p->unk8C = 1;
                    func_80029BF0_2A7F0(p->model, p->unk3C, 0, 7, 1);
                    break;
                case 1:
                    if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                        func_8002C9C0_2D5C0(p->model, p->unk3C);
                        func_80029C74_2A874(p->model, 0.0f);
                        if (func_80108C8C_3B1E2C_name_5F(player, 0) > 0) {
                            func_80029E80_2AA80(p->model, 6, 6);
                        } else {
                            func_80029E80_2AA80(p->model, 2, 2);
                        }
                        p->unk8C = 2;
                    }
                    break;
                }
            } else if (p->unk8C != 0) {
                p->unk8C = 0;
                func_80029BF0_2A7F0(p->model, p->unk36, 0, 7, 1);
            }
            break;
        case 2:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                func_800298A4_2A4A4(p->unk4C, 4, 0);
                func_800298A4_2A4A4(p->unk4C, 0x4000, 0x4000);
                func_8002C628_2D228(p->unk4C, p->model, (char*)D_80114BD0_3BDD70_name_5F);
                obj->work[1] = 3;
            }
            break;
        case 3:
            t = func_80029CE4_2A8E4(p->model);
            if (func_80029D0C_2A90C(p->model) <= t) {
                obj->work[1] = 4;
            }
            break;
        case 4:
            if (func_80108B80_3B1D20_name_5F(player, 0x8000) != 0) {
                p->unk8C = 0;
                func_80029BF0_2A7F0(p->model, p->unk3A, 0, 5, 0);
                obj->work[1] = 5;
            } else if (ABS(func_80108C8C_3B1E2C_name_5F(player, 0)) > 10.0f) {
                switch (p->unk8C) {
                case 0:
                    p->unk8C = 1;
                    func_80029BF0_2A7F0(p->model, p->unk3E, 0, 7, 1);
                    break;
                case 1:
                    if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                        func_8002C9C0_2D5C0(p->model, p->unk3E);
                        func_80029C74_2A874(p->model, 0.0f);
                        if (func_80108C8C_3B1E2C_name_5F(player, 0) > 0) {
                            func_80029E80_2AA80(p->model, 6, 6);
                        } else {
                            func_80029E80_2AA80(p->model, 2, 2);
                        }
                        p->unk8C = 2;
                    }
                    break;
                }
            } else if (p->unk8C != 0) {
                p->unk8C = 0;
                func_80029BF0_2A7F0(p->model, p->unk3A, 0, 7, 1);
            }
            break;
        case 5:
            if (func_80029E3C_2AA3C(p->model) == -1.0f) {
                func_800298A4_2A4A4(p->unk4C, 4, 4);
                func_800298A4_2A4A4(p->unk4C, 0x4000, 0);
                obj->work[1] = 6;
            }
            break;
        case 6:
            t = func_80029CE4_2A8E4(p->model);
            if (func_80029D0C_2A90C(p->model) <= t) {
                func_80029BF0_2A7F0(p->model, p->unk36, 0, 20, 2);
                obj->work[1] = 1;
            }
            break;
        }
    } else if (ABS(func_80108C8C_3B1E2C_name_5F(player, 0)) > 10.0f) {
        if (func_80108C8C_3B1E2C_name_5F(player, 0) > 0) {
            p->unk94 = model->pos.x + 3.0f;
            p->rot.y = 0.0f;
        } else {
            p->unk94 = model->pos.x - 3.0f;
            p->rot.y = 180.0f;
        }
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
        for (i = 0; i < 4; i++) {
            if (i != player) {
                other = &D_800FC834_FD434[DEMO_PLAYER(i)->model];
                if (ABS(p->unk94 - other->pos.x) < 45.0f || p->unk94 < -250.0f || p->unk94 > -100.0f) {
                    break;
                }
            }
        }
        if (i >= 4) {
            model->pos.x = p->unk94;
        }
    }
}

void func_80110F2C_3BA0CC_name_5F(void) {
    Ovl5FDemoPlayer* p;
    omObjData* o;
    Ovl5FHookWork* w;
    s32 dir;
    s32 group;
    s32 i;

    for (i = 0; i < 4; i++) {
        dir = D_800CD438_CE038[gPlayers[i].character].dir;
        p = DEMO_PLAYER(i);
        group = gPlayers[i].group;
        func_80029714_2A314(p->model = func_80018A30_19630(dir | D_800CD438_CE038[gPlayers[i].character].model, 0xA9D), 0.0f, -1000.0f, 0.0f);
        p->scale = 0.5f;
        func_800297E8_2A3E8(p->model, 0.5f, 0.5f, 0.5f);
        p->unk36 = func_8002C8B8_2D4B8(DataRead((group & 1) ? (dir | 0xA9) : (dir | 0xA6)), 0x1D);
        p->unk38 = func_8002C8B8_2D4B8(DataRead((group & 1) ? (dir | 0xAA) : (dir | 0xA7)), 0x1D);
        func_8002C9C0_2D5C0(p->model, p->unk36);
        func_80029E80_2AA80(p->model, 0, 2);
        p->unk4C = func_80018A30_19630((group & 1) ? ((group < 2) ? 0x28000C : 0x28000D) : 0x28000B, 0xA9D);
        o = omAddObj(0x64, 0, 0, -1, func_80108D50_3B1EF0_name_5F);
        o->work[0] = 1;
        o->unk_50 = func_80027154_27D54(0xC, 0x7918);
        func_800B0EF0_B1AF0(o->unk_50, 0, 0xC);
        w = o->unk_50;
        w->form = p->unk4C;
        w->model = p->model;
        w->hook = D_80114BD0_3BDD70_name_5F;
        if (!(group & 1)) {
            func_800297E8_2A3E8(p->unk4E = func_80018A30_19630((group < 2) ? 0x280006 : 0x280007, 0xA9D), p->scale, p->scale, p->scale);
            func_800297E8_2A3E8(p->unk50 = func_80018A30_19630(0x280008, 0xA9D), p->scale, p->scale, p->scale);
            p->unk3A = func_8002C8B8_2D4B8(DataRead(0x280008), 0x1D);
            p->unk3C = func_8002C8B8_2D4B8(DataRead(0x280009), 0x1D);
            func_8002C9C0_2D5C0(p->unk50, p->unk3A);
            func_80029E80_2AA80(p->unk50, 0, 2);
        }
        p->unk8C = group;
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
    }
}

void func_8011126C_3BA40C_name_5F(void) {
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group < 2) {
            func_80104DA8_3ADF48_name_5F(i, 3, (n = !gPlayers[i].group) * 60.0f - 100.0f, -50.0f, -80.0f);
        } else {
            func_80104DA8_3ADF48_name_5F(i, 4, (gPlayers[i].group - 2) * 60.0f + -50.0f, -50.0f, -80.0f);
        }
    }
}

void func_8011137C_3BA51C_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FDemoPlayer* p = DEMO_PLAYER(player);
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    f32 t;

    if (!(p->unk8C & 1)) {
        func_800298A4_2A4A4(p->unk4E, 4, 0);
        func_800298A4_2A4A4(p->unk50, 4, 0);
        func_80029714_2A314(p->unk4E, model->pos.x, model->pos.y, model->pos.z + 50.0f);
        func_80029714_2A314(p->unk50, model->pos.x, model->pos.y, model->pos.z);
    }
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        return;
    }
    switch (obj->work[1]) {
    case 1:
        if (func_80108B80_3B1D20_name_5F(player, 0x8000) != 0) {
            obj->work[1] = 2;
            func_80029BF0_2A7F0(p->model, p->unk38, 0, 10, 0);
            if (!(p->unk8C & 1)) {
                func_80029BF0_2A7F0(p->unk50, p->unk3C, 0, 8, 0);
            }
        }
        break;
    case 2:
        if (func_80029E3C_2AA3C(p->model) == -1.0f) {
            obj->work[1] = 3;
        }
        break;
    case 3:
        t = func_80029CE4_2A8E4(p->model);
        if (func_80029D0C_2A90C(p->model) <= t) {
            func_80029BF0_2A7F0(p->model, p->unk36, 0, 10, 2);
            if (!(p->unk8C & 1)) {
                func_80029BF0_2A7F0(p->unk50, p->unk3A, 0, 10, 2);
            }
            obj->work[1] = 4;
        }
        break;
    case 4:
        if (func_80029E3C_2AA3C(p->model) == -1.0f) {
            obj->work[1] = 1;
        }
        break;
    }
}

void func_801116B0_3BA850_name_5F(void) {
    s32 members[2];
    Ovl5FPairDemo* p;
    omObjData* o;
    s32 dir;
    s32 chr;
    s32 i;
    s32 n;
    s32 team;

    for (team = 0; team < 2; team++) {
        for (i = 0, n = 0; i < 4; i++) {
            if (gPlayers[i].group == team) {
                members[n++] = i;
            }
        }
        p = PAIR_DEMO(team);
        func_80029714_2A314(p->model = func_80018A30_19630(team | 0x290000, 0xA9D), 0.0f, -1000.0f, 0.0f);
        func_8002979C_2A39C(p->model, 0.0f, -90.0f, 0.0f);
        func_800297E8_2A3E8(p->model, 0.3f, 0.3f, 0.3f);
        for (i = 0; i < 2; i++) {
            chr = gPlayers[members[i]].character;
            dir = D_800CD438_CE038[chr].dir;
            func_800297E8_2A3E8(p->unk4C[i] = LoadFormFile(dir | D_800CD438_CE038[chr].model, 0xA9D), 0.3f, 0.3f, 0.3f);
            func_800297E8_2A3E8(p->unk50[i] = LoadFormFile((chr + 0x17) | 0x290000, 0xA9D), 0.3f, 0.3f, 0.3f);
            p->unk36[i] = func_8002C8B8_2D4B8(DataRead(dir | 0x3B), 0x1D);
            p->unk3A[i] = func_8002C8B8_2D4B8(DataRead(dir | 0x3C), 0x1D);
            p->unk3E[i] = func_8002C8B8_2D4B8(DataRead(dir | 0x3A), 0x1D);
            p->unk42[i] = func_8002C8B8_2D4B8(DataRead(D_80114230_3BD3D0_name_5F[chr] | 0x290000), 0x1D);
            func_8002C9C0_2D5C0(p->unk4C[i], p->unk36[i]);
            func_80029E80_2AA80(p->unk4C[i], 0, 2);
            p->player[0] = members[0];
            p->player[1] = members[1];
            p->unk90 = 0;
            p->unk94 = 0.0f;
        }
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = team;
        o->work[1] = 0;
    }
}

void func_801119A8_3BAB48_name_5F(void) {
    func_80104DA8_3ADF48_name_5F(0, 3, -80.0f, -50.0f, -80.0f);
    func_80104DA8_3ADF48_name_5F(1, 4, -50.0f, -50.0f, -80.0f);
}

void func_80111A00_3BABA0_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FPairDemo* p = PAIR_DEMO(player);
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    f32 t;
    s32 x;

    if (p->unk94 == 0.0f) {
        p->unk94 = 1.0f;
        func_800298A4_2A4A4(p->unk4C[0], 4, 0);
        func_800298A4_2A4A4(p->unk4C[1], 4, 0);
    }
    func_80029714_2A314(p->unk4C[0], HuMathSin(model->rot.y) * -5.0f + model->pos.x, model->pos.y,
                        func_800B7890_B8490(model->rot.y) * 25.0f + model->pos.z);
    func_80029714_2A314(p->unk4C[1], HuMathSin(model->rot.y) * -40.0f + model->pos.x, model->pos.y,
                        func_800B7890_B8490(model->rot.y) * -35.0f + model->pos.z);
    func_80029714_2A314(p->unk50[0], HuMathSin(model->rot.y) * -5.0f + model->pos.x, model->pos.y,
                        func_800B7890_B8490(model->rot.y) * 25.0f + model->pos.z);
    func_80029714_2A314(p->unk50[1], HuMathSin(model->rot.y) * -40.0f + model->pos.x, model->pos.y,
                        func_800B7890_B8490(model->rot.y) * -35.0f + model->pos.z);
    func_8002979C_2A39C(p->unk4C[0], model->rot.x, model->rot.y, model->rot.z);
    func_8002979C_2A39C(p->unk4C[1], model->rot.x, model->rot.y, model->rot.z);
    func_8002979C_2A39C(p->unk50[0], model->rot.x, model->rot.y, model->rot.z);
    func_8002979C_2A39C(p->unk50[1], model->rot.x, model->rot.y, model->rot.z);
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        return;
    }
    switch (obj->work[1]) {
    case 2:
        t = func_80029CE4_2A8E4(p->unk4C[0]);
        if (func_80029D0C_2A90C(p->unk4C[0]) <= t) {
            obj->work[1] = 1;
        }
        break;
    case 3:
        if (func_80029E3C_2AA3C(p->unk4C[0]) == -1.0f) {
            obj->work[1] = 4;
        }
        break;
    case 4:
        t = func_80029CE4_2A8E4(p->unk4C[0]);
        if (func_80029D0C_2A90C(p->unk4C[0]) <= t) {
            func_800298A4_2A4A4(p->unk4C[0], 4, 4);
            func_800298A4_2A4A4(p->unk4C[1], 4, 4);
            func_800298A4_2A4A4(p->unk50[0], 4, 0);
            func_800298A4_2A4A4(p->unk50[1], 4, 0);
            func_8002C9C0_2D5C0(p->unk50[0], p->unk42[0]);
            func_80029E80_2AA80(p->unk50[0], 0, 2);
            func_8002C9C0_2D5C0(p->unk50[1], p->unk42[1]);
            func_80029E80_2AA80(p->unk50[1], 0, 2);
            obj->work[1] = 5;
        }
        break;
    case 5:
        p->unk92 = x = (s16)(func_80108C8C_3B1E2C_name_5F(p->player[0], 0) + func_80108C8C_3B1E2C_name_5F(p->player[1], 0)) / 2;
        if (x > 10.0f) {
            model->rot.y += 3.0f;
            if (model->rot.y > -70.0f) {
                model->rot.y = -70.0f;
            }
        }
        if (p->unk92 < -10.0f) {
            model->rot.y -= 3.0f;
            if (model->rot.y < -110.0f) {
                model->rot.y = -110.0f;
            }
        }
        func_8002979C_2A39C(p->unk4C[0], model->rot.x, model->rot.y, model->rot.z);
        func_8002979C_2A39C(p->unk4C[1], model->rot.x, model->rot.y, model->rot.z);
        break;
    }
    if ((func_80108B80_3B1D20_name_5F(p->player[0], 0x8000) != 0 || func_80108B80_3B1D20_name_5F(p->player[1], 0x8000) != 0)
        && obj->work[1] != 3 && obj->work[1] != 4 && obj->work[1] != 5) {
        if (p->unk90 > 20) {
            obj->work[1] = 3;
            func_80029BF0_2A7F0(p->unk4C[0], p->unk3E[0], 0, 3, 0);
            func_80029BF0_2A7F0(p->unk4C[1], p->unk3E[1], 0, 3, 0);
        } else if (obj->work[1] == 1) {
            obj->work[1] = 2;
            func_80029BF0_2A7F0(p->unk4C[0], p->unk3A[0], 0, 3, 0);
            func_80029BF0_2A7F0(p->unk4C[1], p->unk3A[1], 0, 3, 0);
        }
        p->unk90++;
    }
}

/* NON_MATCHING: register operand order only (retail `addu s0,s3,s0` for &p->unk52[i], ours
   `addu s0,s0,s3`; masked 0). */
#ifdef NON_MATCHING
void func_80112080_3BB220_name_5F(void) {
    s32 members[2];
    Ovl5FPumpDemo* p;
    omObjData* o;
    s32 dir;
    s32 i;
    s32 n;
    s32 team;

    for (team = 0; team < 2; team++) {
        for (i = 0, n = 0; i < 4; i++) {
            if (gPlayers[i].group == team) {
                members[n++] = i;
            }
        }
        p = PUMP_DEMO(team);
        func_80029714_2A314(p->model = func_80018A30_19630(0x2A0002, 0xA9D), 0.0f, -1000.0f, 0.0f);
        func_8002979C_2A39C(p->model, 0.0f, 90.0f, 0.0f);
        p->scale = 0.3f;
        func_800297E8_2A3E8(p->model, 0.3f, 0.3f, 0.3f);
        func_800297E8_2A3E8(p->unk4C = LoadFormFile(0x2A0001, 0xA9D), p->scale, p->scale, p->scale);
        func_80029E80_2AA80(p->unk4C, 0, 1);
        func_80029FE4_2ABE4(p->unk4C, 0.0f);
        func_80029C74_2A874(p->unk4C, 0.0f);
        for (i = 0; i < 2; i++) {
            dir = D_800CD438_CE038[gPlayers[members[i]].character].dir;
            func_800297E8_2A3E8(p->unk52[i] = LoadFormFile(dir | D_800CD438_CE038[gPlayers[members[i]].character].model, 0xA9D),
                                p->scale, p->scale, p->scale);
            func_8002C9C0_2D5C0(p->unk52[i], p->unk36[i] = func_8002C8B8_2D4B8(DataRead(dir | 0x15), 0x1D));
            func_80029E80_2AA80(p->unk52[i], 0, 1);
            func_80029FE4_2ABE4(p->unk52[i], 0.0f);
            if (i == 0) {
                p->unk94 = func_80029D0C_2A90C(p->unk52[0]);
                func_80029C74_2A874(p->unk52[0], p->unk94);
            } else {
                p->unk98 = 0.0f;
                func_80029C74_2A874(p->unk52[i], p->unk98);
            }
            p->unk9C = 0.0f;
            p->player[0] = members[0];
            p->player[1] = members[1];
            p->unk90 = 1;
        }
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = team;
        o->work[1] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112080_3BB220_name_5F);
#endif

void func_8011238C_3BB52C_name_5F(void) {
    func_80104DA8_3ADF48_name_5F(0, 3, -70.0f, -50.0f, -80.0f);
    func_80104DA8_3ADF48_name_5F(1, 4, -40.0f, -50.0f, -80.0f);
}

void func_801123E4_3BB584_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FPumpDemo* p = PUMP_DEMO(player);
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;
    f32 angle;
    s32 x;

    func_800298A4_2A4A4(p->unk4C, 4, 0);
    func_800298A4_2A4A4(p->unk52[0], 4, 0);
    func_800298A4_2A4A4(p->unk52[1], 4, 0);
    func_80029714_2A314(p->unk4C, model->pos.x, model->pos.y, model->pos.z);
    func_80029714_2A314(p->unk52[0], HuMathSin(model->rot.y) * 50.0f + model->pos.x, model->pos.y + 45.0f,
                        func_800B7890_B8490(model->rot.y) * 50.0f + model->pos.z);
    func_8002979C_2A39C(p->unk52[0], 0.0f, 180.0f, 0.0f);
    func_80029714_2A314(p->unk52[1], HuMathSin(model->rot.y + 180.0f) * 50.0f + model->pos.x, model->pos.y + 45.0f,
                        func_800B7890_B8490(model->rot.y + 180.0f) * 50.0f + model->pos.z);
    func_800B2060_B2C60((f32(*)[4])D_800FC834_FD434[p->unk4C].mtx, 0.0f, model->rot.y, 0.0f);
    func_800B2060_B2C60((f32(*)[4])D_800FC834_FD434[p->unk52[0]].mtx, 0.0f, model->rot.y, 0.0f);
    func_800B2060_B2C60((f32(*)[4])D_800FC834_FD434[p->unk52[1]].mtx, 0.0f, model->rot.y, 0.0f);
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
        return;
    }
    p->unk92 = x = (s16)(func_80108C8C_3B1E2C_name_5F(p->player[0], 0) + func_80108C8C_3B1E2C_name_5F(p->player[1], 0)) / 2;
    angle = x / 50.0f * -15.0f;
    func_8002979C_2A39C(p->unk4C, angle, 0.0f, 0.0f);
    func_8002979C_2A39C(p->unk52[0], angle, 180.0f, 0.0f);
    func_8002979C_2A39C(p->unk52[1], angle, 0.0f, 0.0f);
    func_80029714_2A314(p->unk52[0], HuMathSin(model->rot.y) * 50.0f + model->pos.x,
                        func_800B7890_B8490(angle) * 45.0f + model->pos.y,
                        model->pos.z - HuMathSin(angle) * 45.0f + func_800B7890_B8490(model->rot.y) * 50.0f);
    func_80029714_2A314(p->unk52[1], HuMathSin(model->rot.y + 180.0f) * 50.0f + model->pos.x,
                        func_800B7890_B8490(angle) * 45.0f + model->pos.y,
                        model->pos.z - HuMathSin(angle) * 45.0f + func_800B7890_B8490(model->rot.y + 180.0f) * 50.0f);
    if (func_80108B80_3B1D20_name_5F(p->player[0], 0x8000) != 0 || func_80108B80_3B1D20_name_5F(p->player[1], 0x8000) != 0) {
        p->unk9C += 0.3f;
        if (p->unk9C > 5.0f) {
            p->unk9C = 5.0f;
        }
    }
    if (p->unk90 != 0) {
        p->unk94 -= p->unk9C;
        p->unk98 += p->unk9C;
        if (p->unk94 <= 0.0f) {
            p->unk90 = 0;
            p->unk94 = 0.0f;
            p->unk98 = func_80029D0C_2A90C(p->unk52[1]);
        }
    } else {
        p->unk94 += p->unk9C;
        p->unk98 -= p->unk9C;
        if (func_80029D0C_2A90C(p->unk52[0]) <= p->unk94) {
            p->unk90 = 1;
            p->unk94 = func_80029D0C_2A90C(p->unk52[0]);
            p->unk98 = 0.0f;
        }
    }
    func_80029C74_2A874(p->unk52[0], p->unk94);
    func_80029C74_2A874(p->unk52[1], p->unk98);
    func_80029C74_2A874(p->unk4C, p->unk98);
    p->unk9C -= 0.06f;
    if (p->unk9C < 0.0f) {
        p->unk9C = 0.0f;
    }
}

void func_80112A1C_3BBBBC_name_5F(void) {
    Ovl5FDemoPlayer* p;
    omObjData* o;
    s32 i;

    for (i = 0; i < 4; i++) {
        p = DEMO_PLAYER(i);
        p->sprite = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8((gPlayers[i].character + 0x36) | 0x310000), 0, 1);
        func_8001A708_1B308(p->sprite, 0x4000);
        espPosSet(p->sprite, -100, -100);
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
        o->work[2] = 0;
    }
}

void func_80112B20_3BBCC0_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FDemoPlayer* p = DEMO_PLAYER(player);

    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        omAddObj(10, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk0C)->work[0] = player;
        omDelObj(obj);
        return;
    }
    if (func_80108C24_3B1DC4_name_5F(player, 0x8000) == 0 && obj->work[1] == 2) {
        obj->work[1] = 1;
        func_8001A854_1B454(p->sprite, 0, 0);
        func_8001A89C_1B49C(p->sprite, 1);
    }
    if (func_80108B80_3B1D20_name_5F(player, 0x8000) != 0 && obj->work[1] == 1) {
        obj->work[1] = 2;
        func_8001A854_1B454(p->sprite, 1, 0);
        func_8001A89C_1B49C(p->sprite, 1);
    }
}

void func_80112C64_3BBE04_name_5F(void) {
    Ovl5FDemoPlayer* p;
    omObjData* o;
    void* file;
    s32 dir;
    u8 chr;
    s32 i;

    for (i = 0; i < 4; i++) {
        chr = gPlayers[i].character;
        dir = D_800CD438_CE038[chr].dir;
        p = DEMO_PLAYER(i);
        p->model = LoadFormFile(dir | D_800CD438_CE038[chr].model, 0xA9D);
        p->scale = 0.5f;
        func_80029714_2A314(p->model, 0.0f, -1000.0f, 0.0f);
        func_800297E8_2A3E8(p->model, p->scale, p->scale, p->scale);
        func_8002C9C0_2D5C0(p->model, p->unk36 = func_8002C8B8_2D4B8(DataRead(dir | D_8011423C_3BD3DC_name_5F[chr]), 0x1D));
        func_80029E80_2AA80(p->model, 0, 2);
        func_800297E8_2A3E8(p->unk4C = LoadFormFile(0x33001E, 0xA8D), p->scale, p->scale, p->scale);
        file = DataRead(0x330002);
        p->unk8C = func_8003D8F0_3E4F0(D_800FC834_FD434[p->unk4C].hmf, file, 0, "16mt000_DEF");
        func_80029A8C_2A68C(p->unk4C);
        func_80029AFC_2A6FC(p->unk4C);
        HuMemMemoryFreePerm(file);
        o = omAddObj(0x7D00, 0, 0, -1, D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]].unk08);
        o->work[0] = i;
        o->work[1] = 0;
    }
}

void func_80112E68_3BC008_name_5F(omObjData* obj) {
    s32 player = obj->work[0];
    Ovl5FDemoPlayer* p = DEMO_PLAYER(player);
    Ovl5FDemo* demo = &D_80113C70_3BCE10_name_5F[D_80114F50_3BE0F0_name_5F[0]];
    HmfModel* model = &D_800FC834_FD434[p->model];
    omObjData* o;

    func_800298A4_2A4A4(p->unk4C, 4, 0);
    func_80029714_2A314(p->unk4C, model->pos.x, model->pos.y, model->pos.z + 10.0f);
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        return;
    }
    if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            obj->work[1] = 1;
        }
        return;
    }
    if (D_800FC8A0_FD4A0 == 11) {
        obj->work[1] = 12;
        o = omAddObj(10, 0, 0, -1, demo->unk0C);
        o->work[0] = player;
        o->work[1] = 0;
        p->pos.x = model->pos.x;
        p->pos.y = model->pos.y;
        p->pos.z = model->pos.z;
        p->rot.x = model->rot.x;
        p->rot.y = model->rot.y;
        p->rot.z = model->rot.z;
    }
}

void func_80112FE8_3BC188_name_5F(void) {
    func_8010A2B0_3B3450_name_5F();
}

void func_80113004_3BC1A4_name_5F(void) {
    func_80109988_3B2B28_name_5F();
}

void func_80113020_3BC1C0_name_5F(void) {
    func_80109A04_3B2BA4_name_5F();
}

void func_8011303C_3BC1DC_name_5F(void) {
    D_80114F50_3BE0F0_name_5F[0] = D_80114F74_3BE114_name_5F;
    func_8010A45C_3B35FC_name_5F();
}
