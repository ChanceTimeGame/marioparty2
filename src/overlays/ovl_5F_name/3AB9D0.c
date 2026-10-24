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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105B94_3AED34_name_5F);

__asm__(".section .rodata");
const u32 D_801147D8_3BD978_name_5F[1] = { 0xFF000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801072C8_3B0468_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107C84_3B0E24_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107F74_3B1114_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107FE0_3B1180_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108170_3B1310_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108458_3B15F8_name_5F);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010879C_3B193C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010881C_3B19BC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108AEC_3B1C8C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108B80_3B1D20_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108C24_3B1DC4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108C8C_3B1E2C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108D50_3B1EF0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108DCC_3B1F6C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108E50_3B1FF0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801092B0_3B2450_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010938C_3B252C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801093D4_3B2574_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109424_3B25C4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010946C_3B260C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801094B4_3B2654_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801094F4_3B2694_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801098FC_3B2A9C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109988_3B2B28_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109A04_3B2BA4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109A80_3B2C20_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109FA0_3B3140_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A000_3B31A0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A038_3B31D8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A0C4_3B3264_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A1A0_3B3340_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A2B0_3B3450_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A2EC_3B348C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A45C_3B35FC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A4F0_3B3690_name_5F);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A628_3B37C8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A818_3B39B8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AAA0_3B3C40_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AC44_3B3DE4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AEF8_3B4098_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AF84_3B4124_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B168_3B4308_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B30C_3B44AC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B33C_3B44DC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B460_3B4600_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B4F0_3B4690_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B624_3B47C4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B798_3B4938_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010BA24_3B4BC4_name_5F);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010BCF0_3B4E90_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010C2A8_3B5448_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010C40C_3B55AC_name_5F);

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
            p->model = func_80018A30_19630(dir | D_800CD438_CE038[ch].unk_08, 0xA9D);
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
            p->unk8C = 0;
            p->unk98 = 300.0f;
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
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->unk98, model->pos.z);
        }
    }
    if (obj->work[1] == 12) {
        func_80029714_2A314(p->model, p->pos.x, p->pos.y, p->pos.z);
        func_8002979C_2A39C(p->model, p->rot.x, p->rot.y, p->rot.z);
    } else if (obj->work[1] == 0) {
        if (D_800FC8A0_FD4A0 != 0) {
            p->baseY = model->pos.y;
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
            p->unk98 -= 10.0f;
            if (p->unk98 < 0.0f) {
                p->unk8C = 1;
                p->unk98 = 0.0f;
                obj->work[1] = 2;
            }
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->unk98, model->pos.z);
            break;
        case 2:
            model->pos.y += 10.0f;
            if (model->pos.y > p->baseY + 100.0f) {
                model->pos.y = p->baseY + 100.0f;
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
            if (model->pos.y < p->baseY + 30.0f) {
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 2, 0);
                obj->work[1] = 5;
            }
            break;
        case 5:
            model->pos.y -= 5.0f;
            if (model->pos.y < p->baseY) {
                model->pos.y = p->baseY;
                p->timer = 20;
                obj->work[1] = 6;
            }
            break;
        case 6:
            if (--p->timer == -1) {
                obj->work[1] = 7;
            }
            break;
        case 7:
            model->pos.y += 5.0f;
            if (model->pos.y > p->baseY + 100.0f) {
                model->pos.y = p->baseY + 100.0f;
                func_80029BF0_2A7F0(p->model, p->mot[1], 0, 2, 0);
                p->timer = 20;
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
            if (--p->timer == -1) {
                obj->work[1] = 3;
            }
            break;
        }
        if (p->unk8C != 0) {
            func_80029714_2A314(p->model2, model->pos.x, model->pos.y + 504.00003f + p->unk98, model->pos.z);
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
        p->unk8C = 0;
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
            if (p->unk8C != dir && dir != 0) {
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
        p->unk8C = dir;
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
            p->model2 = func_80018A30_19630(dir | D_800CD438_CE038[ch].unk_08, 0x69D);
            func_800297E8_2A3E8(p->model2, 0.4f, 0.4f, 0.4f);
            func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[p->model].mtx, 0.0f, 70.0f, 0.0f);
            func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[p->model2].mtx, 0.0f, 70.0f, 0.0f);
        } else {
            p->model = func_80018A30_19630(dir | D_800CD438_CE038[ch].unk_08, 0x69D);
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
        p->unk94 = model->pos.x;
        p->unk98 = model->pos.y;
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
                if (model->pos.x > p->unk94 + 10.0f) {
                    model->pos.x = p->unk94 + 10.0f;
                }
            } else {
                func_80029714_2A314(p->model, model->pos.x - 2.0f, model->pos.y, model->pos.z);
                if (model->pos.x < p->unk94 - 10.0f) {
                    model->pos.x = p->unk94 - 10.0f;
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
            p->unk94 = 0.0f;
            p->unk98 = 0.0f;
            break;
        case 1:
            p->unk94 = 45.0f;
            p->unk98 = 0.0f;
            break;
        case 2:
            p->unk94 = 0.0f;
            p->unk98 = 90.0f;
            break;
        case 3:
            p->unk94 = -45.0f;
            p->unk98 = 0.0f;
            break;
        case 4:
            p->unk94 = 0.0f;
            p->unk98 = -90.0f;
            break;
        }
        if (p->unk94 == 0.0f) {
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
        if (p->unk98 == 0.0f) {
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
        if (p->unk94 > 0.0f) {
            p->rot.x += 10.0f;
            if (p->rot.x > p->unk94) {
                p->rot.x = p->unk94;
            }
        }
        if (p->unk94 < 0.0f) {
            p->rot.x -= 10.0f;
            if (p->rot.x < p->unk94) {
                p->rot.x = p->unk94;
            }
        }
        if (p->unk98 > 0.0f) {
            p->rot.y += 10.0f;
            if (p->rot.y > p->unk98) {
                p->rot.y = p->unk98;
            }
        }
        if (p->unk98 < 0.0f) {
            p->rot.y -= 10.0f;
            if (p->rot.y < p->unk98) {
                p->rot.y = p->unk98;
            }
        }
        if (OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 0)) > 10.0f
            || OVL5F_ABS(func_80108C8C_3B1E2C_name_5F(i, 1)) > 10.0f) {
            p->unk94 = func_800B75A8_B81A8(func_80108C8C_3B1E2C_name_5F(i, 0), -func_80108C8C_3B1E2C_name_5F(i, 1)) + 45.0f;
            p->unk94 = func_8002D958_2E558(p->unk94);
            if (p->unk94 < 360.0f) {
                obj->work[2] = 4;
            }
            if (p->unk94 < 270.0f) {
                obj->work[2] = 3;
            }
            if (p->unk94 < 180.0f) {
                obj->work[2] = 2;
            }
            if (p->unk94 < 90.0f) {
                obj->work[2] = 1;
            }
        } else {
            obj->work[2] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010EEB4_3B8054_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F0C8_3B8268_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F1A4_3B8344_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F488_3B8628_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F578_3B8718_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F668_3B8808_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F8BC_3B8A5C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010FDD8_3B8F78_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110050_3B91F0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110480_3B9620_name_5F);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110784_3B9924_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110F2C_3BA0CC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011126C_3BA40C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011137C_3BA51C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801116B0_3BA850_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801119A8_3BAB48_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80111A00_3BABA0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112080_3BB220_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011238C_3BB52C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801123E4_3BB584_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112A1C_3BBBBC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112B20_3BBCC0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112C64_3BBE04_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112E68_3BC008_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112FE8_3BC188_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80113004_3BC1A4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80113020_3BC1C0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011303C_3BC1DC_name_5F);
