#include "ovl_1C.h"

__asm__(".section .data");
f32 D_8010B1B0_1B4840_SkyPilots = 0.0f;
s32 D_8010B1B4_1B4844_SkyPilots[6] = { 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
s32 D_8010B1CC_1B485C_SkyPilots[6] = { 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23 };
s32 D_8010B1E4_1B4874_SkyPilots[5] = { 0, 0, 0, 0, 0 };
f32 D_8010B1F8_1B4888_SkyPilots[2] = { -500.0f, 500.0f };

/* NON_MATCHING: register allocation (masked 4) */
#ifdef NON_MATCHING
void func_80108A90_1B2120_SkyPilots(s32 i) {
    if (++D_8010AEA8_1B4538_SkyPilots[i] > 0) {
        f32 x;
        f32 z;
        f32 d;

        D_8010AEDC_1B456C_SkyPilots[i].x = D_8010AEAC_1B453C_SkyPilots[i].x * 60.0f + D_8010AEDC_1B456C_SkyPilots[i].x;
        D_8010AEDC_1B456C_SkyPilots[i].y = D_8010AEAC_1B453C_SkyPilots[i].y * 60.0f + D_8010AEDC_1B456C_SkyPilots[i].y;
        D_8010AEDC_1B456C_SkyPilots[i].z = D_8010AEAC_1B453C_SkyPilots[i].z * 60.0f + D_8010AEDC_1B456C_SkyPilots[i].z;
        func_80029714_2A314((s16)D_8010B2F8_1B4988_SkyPilots[i], D_8010AEDC_1B456C_SkyPilots[i].x, D_8010AEDC_1B456C_SkyPilots[i].y, D_8010AEDC_1B456C_SkyPilots[i].z);
        x = D_8010AEDC_1B456C_SkyPilots[i].x;
        z = D_8010AEDC_1B456C_SkyPilots[i].z;
        d = func_800B1830_B2430(x * x + z * z) - SP_RADIUS;
        if (D_8010AEA8_1B4538_SkyPilots[i] >= 0x47 || fabs(d) > 1500.0) {
            func_8010890C_1B1F9C_SkyPilots(i);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1B2120", func_80108A90_1B2120_SkyPilots);
#endif

void func_80108C24_1B22B4_SkyPilots(omObjData* obj) {
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 a = D_8010AE3C_1B44CC_SkyPilots[i].angle;
        s32 mask = 0;
        s32 k;

        for (k = 0; k < 2; k++) {
            f32 h = D_8010B430_1B4AC0_SkyPilots[k];
            f32 lo = h - 5.0f;
            f32 hi = h + 25.0f + 5.0f;

            if ((lo < a) & (a < hi)) {
                mask |= 1 << k;
            }
        }
        func_80029EDC_2AADC(obj->model[i], mask);
        func_80029EDC_2AADC((s16)D_8010B2E8_1B4978_SkyPilots[i], mask);
        func_801084E4_1B1B74_SkyPilots(i);
        if (D_8010AEA8_1B4538_SkyPilots[i] != 0) {
            func_80108A90_1B2120_SkyPilots(i);
            if (D_8010AEA8_1B4538_SkyPilots[i] < 0) {
                continue;
            }
        }
        func_800298A4_2A4A4((s16)D_8010B308_1B4998_SkyPilots[i], 4, 4);
    }
}

void func_80108DB4_1B2444_SkyPilots(omObjData* obj) {
    s32 i;

    for (i = 0; i < 6; i++) {
        f32 a = D_8010ADF4_1B4484_SkyPilots[i].angle;
        s32 mask = 0;
        s32 k;

        for (k = 0; k < 2; k++) {
            f32 h = D_8010B430_1B4AC0_SkyPilots[k];
            f32 lo = h - 5.0f;
            f32 hi = h + 25.0f;

            if ((lo < a) & (a < hi)) {
                mask |= 1 << k;
            }
        }
        func_80029EDC_2AADC(obj->model[i], mask);
    }
}

/* NON_MATCHING: register allocation (masked 10) */
#ifdef NON_MATCHING
void func_80108ECC_1B255C_SkyPilots(omObjData* obj) {
    s32 i;

    for (i = 0; i < 5; i++) {
        f32 a = D_8010AE6C_1B44FC_SkyPilots[i].angle;
        s32 mask = 0;
        s32 k;

        for (k = 0; k < 2; k++) {
            f32 h = D_8010B430_1B4AC0_SkyPilots[k];
            f32 lo = h - 5.0f;
            f32 hi = h + 25.0f;

            if ((lo < a) & (a < hi)) {
                mask |= 1 << k;
            }
        }
        func_80029EDC_2AADC((s16)D_8010B318_1B49A8_SkyPilots[i], mask);
        func_80029EDC_2AADC((s16)D_8010B330_1B49C0_SkyPilots[i], mask);
        if (D_8010ADD4_1B4464_SkyPilots[i] != 0) {
            if (D_8010ADD4_1B4464_SkyPilots[i] == 45) {
                func_800298A4_2A4A4((s16)D_8010B330_1B49C0_SkyPilots[i], 4, 4);
            } else {
                D_8010ADD4_1B4464_SkyPilots[i]++;
            }
        } else {
            f32 y;
            f32 x;
            f32 z;

            D_8010AE6C_1B44FC_SkyPilots[i].extra = HuMathSin(D_8010ADB8_1B4448_SkyPilots[i]) * 400.0f;
            D_8010ADB8_1B4448_SkyPilots[i] += 2.0f;
            y = D_8010AE6C_1B44FC_SkyPilots[i].extra;
            x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[i].angle) * (D_8010AE6C_1B44FC_SkyPilots[i].radius + SP_RADIUS);
            z = func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[i].angle) * (D_8010AE6C_1B44FC_SkyPilots[i].radius + SP_RADIUS);
            func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[i], x, y, z);
            func_80029714_2A314((s16)D_8010B330_1B49C0_SkyPilots[i], x, y, z);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1B2120", func_80108ECC_1B255C_SkyPilots);
#endif

void func_8010916C_1B27FC_SkyPilots(omObjData* obj) {
    f32 x;
    f32 e;

    obj->model[0] = func_80018A30_19630(0x2C0007, 0x208D9);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    obj->trans.x = HuMathSin(D_8010ADDC_1B446C_SkyPilots[0].angle) * (D_8010ADDC_1B446C_SkyPilots[0].radius + SP_RADIUS);
    obj->trans.y = 1000.0f;
    obj->trans.z = func_800B7890_B8490(D_8010ADDC_1B446C_SkyPilots[0].angle) * (D_8010ADDC_1B446C_SkyPilots[0].radius + SP_RADIUS);
    obj->rot.y = D_8010ADDC_1B446C_SkyPilots[0].angle - 90.0f;
    obj->scale.x = D_8010ADDC_1B446C_SkyPilots[0].extra;
    obj->scale.z = D_8010ADDC_1B446C_SkyPilots[0].extra;
    x = HuMathSin(D_8010ADDC_1B446C_SkyPilots[1].angle) * (D_8010ADDC_1B446C_SkyPilots[1].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[1], x, 1000.0f, func_800B7890_B8490(D_8010ADDC_1B446C_SkyPilots[1].angle) * (D_8010ADDC_1B446C_SkyPilots[1].radius + SP_RADIUS));
    func_8002979C_2A39C(obj->model[1], 0.0f, D_8010ADDC_1B446C_SkyPilots[1].angle - 90.0f, 0.0f);
    e = D_8010ADDC_1B446C_SkyPilots[1].extra;
    func_800297E8_2A3E8(obj->model[1], e, 1.0f, e);
    obj->func_ptr = func_801083CC_1B1A5C_SkyPilots;
}

void func_801092F8_1B2988_SkyPilots(omObjData* obj) {
    f32 x;
    f32 z;

    obj->model[0] = func_80018A30_19630(0x2C0009, 0x899);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    obj->model[2] = func_80027D3C_2893C(obj->model[0]);
    obj->model[3] = func_80027D3C_2893C(obj->model[0]);
    D_8010B2E8_1B4978_SkyPilots[0] = func_80018A30_19630(0x2C000A, 0x899);
    D_8010B2E8_1B4978_SkyPilots[1] = func_80027D3C_2893C(D_8010B2E8_1B4978_SkyPilots[0]);
    D_8010B2E8_1B4978_SkyPilots[2] = func_80027D3C_2893C(D_8010B2E8_1B4978_SkyPilots[0]);
    D_8010B2E8_1B4978_SkyPilots[3] = func_80027D3C_2893C(D_8010B2E8_1B4978_SkyPilots[0]);
    D_8010B2F8_1B4988_SkyPilots[0] = func_80018A30_19630(0x1F0006, 0x899);
    D_8010B2F8_1B4988_SkyPilots[1] = func_80027D3C_2893C(D_8010B2F8_1B4988_SkyPilots[0]);
    D_8010B2F8_1B4988_SkyPilots[2] = func_80027D3C_2893C(D_8010B2F8_1B4988_SkyPilots[0]);
    D_8010B2F8_1B4988_SkyPilots[3] = func_80027D3C_2893C(D_8010B2F8_1B4988_SkyPilots[0]);
    D_8010B308_1B4998_SkyPilots[0] = func_80018A30_19630(0x2C0016, 0x89D);
    D_8010B308_1B4998_SkyPilots[1] = func_80018A30_19630(0x2C0016, 0x89D);
    D_8010B308_1B4998_SkyPilots[2] = func_80018A30_19630(0x2C0016, 0x89D);
    D_8010B308_1B4998_SkyPilots[3] = func_80018A30_19630(0x2C0016, 0x89D);
    obj->trans.x = HuMathSin(D_8010AE3C_1B44CC_SkyPilots[0].angle) * (D_8010AE3C_1B44CC_SkyPilots[0].radius + SP_RADIUS);
    obj->trans.y = 0.0f;
    obj->trans.z = func_800B7890_B8490(D_8010AE3C_1B44CC_SkyPilots[0].angle) * (D_8010AE3C_1B44CC_SkyPilots[0].radius + SP_RADIUS);
    obj->rot.y = D_8010AE3C_1B44CC_SkyPilots[0].angle - 90.0f;
    func_80029714_2A314((s16)D_8010B2E8_1B4978_SkyPilots[0], obj->trans.x, 0.0f, obj->trans.z);
    func_80029714_2A314((s16)D_8010B2F8_1B4988_SkyPilots[0], obj->trans.x, 0.0f, obj->trans.z);
    x = HuMathSin(D_8010AE3C_1B44CC_SkyPilots[1].angle) * (D_8010AE3C_1B44CC_SkyPilots[1].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE3C_1B44CC_SkyPilots[1].angle) * (D_8010AE3C_1B44CC_SkyPilots[1].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[1], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2E8_1B4978_SkyPilots[1], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2F8_1B4988_SkyPilots[1], x, 0.0f, z);
    x = HuMathSin(D_8010AE3C_1B44CC_SkyPilots[2].angle) * (D_8010AE3C_1B44CC_SkyPilots[2].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE3C_1B44CC_SkyPilots[2].angle) * (D_8010AE3C_1B44CC_SkyPilots[2].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[2], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2E8_1B4978_SkyPilots[2], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2F8_1B4988_SkyPilots[2], x, 0.0f, z);
    x = HuMathSin(D_8010AE3C_1B44CC_SkyPilots[3].angle) * (D_8010AE3C_1B44CC_SkyPilots[3].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE3C_1B44CC_SkyPilots[3].angle) * (D_8010AE3C_1B44CC_SkyPilots[3].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[3], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2E8_1B4978_SkyPilots[3], x, 0.0f, z);
    func_80029714_2A314((s16)D_8010B2F8_1B4988_SkyPilots[3], x, 0.0f, z);
    func_8002979C_2A39C(obj->model[1], 0.0f, D_8010AE3C_1B44CC_SkyPilots[1].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[2], 0.0f, D_8010AE3C_1B44CC_SkyPilots[2].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[3], 0.0f, D_8010AE3C_1B44CC_SkyPilots[3].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B2E8_1B4978_SkyPilots[0], 0.0f, D_8010AE3C_1B44CC_SkyPilots[0].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B2E8_1B4978_SkyPilots[1], 0.0f, D_8010AE3C_1B44CC_SkyPilots[1].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B2E8_1B4978_SkyPilots[2], 0.0f, D_8010AE3C_1B44CC_SkyPilots[2].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B2E8_1B4978_SkyPilots[3], 0.0f, D_8010AE3C_1B44CC_SkyPilots[3].angle - 90.0f, 0.0f);
    func_80029E80_2AA80((s16)D_8010B2E8_1B4978_SkyPilots[0], 1, 1);
    func_80029E80_2AA80((s16)D_8010B2E8_1B4978_SkyPilots[1], 1, 1);
    func_80029E80_2AA80((s16)D_8010B2E8_1B4978_SkyPilots[2], 1, 1);
    func_80029E80_2AA80((s16)D_8010B2E8_1B4978_SkyPilots[3], 1, 1);
    HmfModelObjAttrSet((s16)D_8010B2F8_1B4988_SkyPilots[0], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B2F8_1B4988_SkyPilots[1], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B2F8_1B4988_SkyPilots[2], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B2F8_1B4988_SkyPilots[3], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B308_1B4998_SkyPilots[0], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B308_1B4998_SkyPilots[1], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B308_1B4998_SkyPilots[2], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B308_1B4998_SkyPilots[3], 0x70000000, 0x70000000);
    obj->func_ptr = func_80108C24_1B22B4_SkyPilots;
}

void func_80109878_1B2F08_SkyPilots(omObjData* obj) {
    f32 x;

    obj->model[0] = func_80018A30_19630(0x2C0008, 0x8D9);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    obj->model[2] = func_80027D3C_2893C(obj->model[0]);
    obj->model[3] = func_80027D3C_2893C(obj->model[0]);
    obj->model[4] = func_80027D3C_2893C(obj->model[0]);
    obj->model[5] = func_80027D3C_2893C(obj->model[0]);
    obj->func_ptr = func_80108DB4_1B2444_SkyPilots;
    obj->trans.x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[0].angle) * (D_8010ADF4_1B4484_SkyPilots[0].radius + SP_RADIUS);
    obj->trans.y = 0.0f;
    obj->trans.z = func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[0].angle) * (D_8010ADF4_1B4484_SkyPilots[0].radius + SP_RADIUS);
    obj->rot.y = D_8010ADF4_1B4484_SkyPilots[0].angle - 90.0f;
    x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[1].angle) * (D_8010ADF4_1B4484_SkyPilots[1].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[1], x, 0.0f, func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[1].angle) * (D_8010ADF4_1B4484_SkyPilots[1].radius + SP_RADIUS));
    x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[2].angle) * (D_8010ADF4_1B4484_SkyPilots[2].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[2], x, 0.0f, func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[2].angle) * (D_8010ADF4_1B4484_SkyPilots[2].radius + SP_RADIUS));
    x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[3].angle) * (D_8010ADF4_1B4484_SkyPilots[3].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[3], x, 0.0f, func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[3].angle) * (D_8010ADF4_1B4484_SkyPilots[3].radius + SP_RADIUS));
    x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[4].angle) * (D_8010ADF4_1B4484_SkyPilots[4].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[4], x, 0.0f, func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[4].angle) * (D_8010ADF4_1B4484_SkyPilots[4].radius + SP_RADIUS));
    x = HuMathSin(D_8010ADF4_1B4484_SkyPilots[5].angle) * (D_8010ADF4_1B4484_SkyPilots[5].radius + SP_RADIUS);
    func_80029714_2A314(obj->model[5], x, 0.0f, func_800B7890_B8490(D_8010ADF4_1B4484_SkyPilots[5].angle) * (D_8010ADF4_1B4484_SkyPilots[5].radius + SP_RADIUS));
    func_8002979C_2A39C(obj->model[1], 0.0f, D_8010ADF4_1B4484_SkyPilots[1].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[2], 0.0f, D_8010ADF4_1B4484_SkyPilots[2].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[3], 0.0f, D_8010ADF4_1B4484_SkyPilots[3].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[4], 0.0f, D_8010ADF4_1B4484_SkyPilots[4].angle - 90.0f, 0.0f);
    func_8002979C_2A39C(obj->model[5], 0.0f, D_8010ADF4_1B4484_SkyPilots[5].angle - 90.0f, 0.0f);
}

void func_80109BBC_1B324C_SkyPilots(omObjData* obj) {
    f32 x;
    f32 z;

    D_8010B318_1B49A8_SkyPilots[0] = func_80018A30_19630(0x2C000B, 0x8D9);
    D_8010B318_1B49A8_SkyPilots[1] = func_80027D3C_2893C(D_8010B318_1B49A8_SkyPilots[0]);
    D_8010B318_1B49A8_SkyPilots[2] = func_80027D3C_2893C(D_8010B318_1B49A8_SkyPilots[0]);
    D_8010B318_1B49A8_SkyPilots[3] = func_80027D3C_2893C(D_8010B318_1B49A8_SkyPilots[0]);
    D_8010B318_1B49A8_SkyPilots[4] = func_80027D3C_2893C(D_8010B318_1B49A8_SkyPilots[0]);
    D_8010B330_1B49C0_SkyPilots[0] = func_80018A30_19630(0x2C0015, 0x8DD);
    D_8010B330_1B49C0_SkyPilots[1] = func_80018A30_19630(0x2C0015, 0x8DD);
    D_8010B330_1B49C0_SkyPilots[2] = func_80018A30_19630(0x2C0015, 0x8DD);
    D_8010B330_1B49C0_SkyPilots[3] = func_80018A30_19630(0x2C0015, 0x8DD);
    D_8010B330_1B49C0_SkyPilots[4] = func_80018A30_19630(0x2C0015, 0x8DD);
    obj->func_ptr = func_80108ECC_1B255C_SkyPilots;
    x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[0].angle) * (D_8010AE6C_1B44FC_SkyPilots[0].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[0].angle) * (D_8010AE6C_1B44FC_SkyPilots[0].radius + SP_RADIUS);
    obj->rot.y = D_8010AE6C_1B44FC_SkyPilots[0].angle - 90.0f;
    func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[0], x, D_8010AE6C_1B44FC_SkyPilots[0].extra, z);
    func_80029714_2A314((s16)D_8010B330_1B49C0_SkyPilots[0], x, D_8010AE6C_1B44FC_SkyPilots[0].extra, z);
    x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[1].angle) * (D_8010AE6C_1B44FC_SkyPilots[1].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[1].angle) * (D_8010AE6C_1B44FC_SkyPilots[1].radius + SP_RADIUS);
    func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[1], x, D_8010AE6C_1B44FC_SkyPilots[1].extra, z);
    func_80029714_2A314((s16)D_8010B330_1B49C0_SkyPilots[1], x, D_8010AE6C_1B44FC_SkyPilots[1].extra, z);
    x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[2].angle) * (D_8010AE6C_1B44FC_SkyPilots[2].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[2].angle) * (D_8010AE6C_1B44FC_SkyPilots[2].radius + SP_RADIUS);
    func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[2], x, D_8010AE6C_1B44FC_SkyPilots[2].extra, z);
    func_80029714_2A314((s16)D_8010B330_1B49C0_SkyPilots[2], x, D_8010AE6C_1B44FC_SkyPilots[2].extra, z);
    x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[3].angle) * (D_8010AE6C_1B44FC_SkyPilots[3].radius + SP_RADIUS);
    func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[3], x, D_8010AE6C_1B44FC_SkyPilots[3].extra, func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[3].angle) * (D_8010AE6C_1B44FC_SkyPilots[3].radius + SP_RADIUS)); /* sic: D_8010B330_1B49C0_SkyPilots[3] stays at the origin */
    x = HuMathSin(D_8010AE6C_1B44FC_SkyPilots[4].angle) * (D_8010AE6C_1B44FC_SkyPilots[4].radius + SP_RADIUS);
    z = func_800B7890_B8490(D_8010AE6C_1B44FC_SkyPilots[4].angle) * (D_8010AE6C_1B44FC_SkyPilots[4].radius + SP_RADIUS);
    func_80029714_2A314((s16)D_8010B318_1B49A8_SkyPilots[4], x, D_8010AE6C_1B44FC_SkyPilots[4].extra, z);
    func_80029714_2A314((s16)D_8010B330_1B49C0_SkyPilots[4], x, D_8010AE6C_1B44FC_SkyPilots[4].extra, z);
    HmfModelObjAttrSet((s16)D_8010B318_1B49A8_SkyPilots[0], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B318_1B49A8_SkyPilots[1], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B318_1B49A8_SkyPilots[2], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B318_1B49A8_SkyPilots[3], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B318_1B49A8_SkyPilots[4], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B330_1B49C0_SkyPilots[0], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B330_1B49C0_SkyPilots[1], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B330_1B49C0_SkyPilots[2], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B330_1B49C0_SkyPilots[3], 0x70000000, 0x70000000);
    HmfModelObjAttrSet((s16)D_8010B330_1B49C0_SkyPilots[4], 0x70000000, 0x70000000);
    func_8002979C_2A39C((s16)D_8010B318_1B49A8_SkyPilots[0], 0.0f, D_8010AE6C_1B44FC_SkyPilots[0].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B318_1B49A8_SkyPilots[1], 0.0f, D_8010AE6C_1B44FC_SkyPilots[1].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B318_1B49A8_SkyPilots[2], 0.0f, D_8010AE6C_1B44FC_SkyPilots[2].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B318_1B49A8_SkyPilots[3], 0.0f, D_8010AE6C_1B44FC_SkyPilots[3].angle - 90.0f, 0.0f);
    func_8002979C_2A39C((s16)D_8010B318_1B49A8_SkyPilots[4], 0.0f, D_8010AE6C_1B44FC_SkyPilots[4].angle - 90.0f, 0.0f);
}

void func_8010A024_1B36B4_SkyPilots(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x2C0006, 0x8D9);
    obj->func_ptr = NULL;
    obj->trans.x = HuMathSin(246.0f) * SP_RADIUS;
    obj->trans.y = 0.0f;
    obj->trans.z = func_800B7890_B8490(246.0f) * SP_RADIUS;
    obj->rot.y = 156.0f;
}

void func_8010A0BC_1B374C_SkyPilots(omObjData* obj) {
    u32 group = gPlayers[0].group;
    s32 file = D_8010B1B4_1B4844_SkyPilots[gPlayers[0].character];
    s32 dir = 0x2C0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80107074_1B0704_SkyPilots(obj, dir, file, team, 0);
        break;
    case 1:
    case 3:
        file = D_8010B1CC_1B485C_SkyPilots[gPlayers[0].character];
        func_801073A8_1B0A38_SkyPilots(obj, dir, file, team, 0);
        break;
    }
}

void func_8010A154_1B37E4_SkyPilots(omObjData* obj) {
    u32 group = gPlayers[1].group;
    s32 file = D_8010B1B4_1B4844_SkyPilots[gPlayers[1].character];
    s32 dir = 0x2C0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80107074_1B0704_SkyPilots(obj, dir, file, team, 1);
        break;
    case 1:
    case 3:
        file = D_8010B1CC_1B485C_SkyPilots[gPlayers[1].character];
        func_801073A8_1B0A38_SkyPilots(obj, dir, file, team, 1);
        break;
    }
}

void func_8010A1F4_1B3884_SkyPilots(omObjData* obj) {
    u32 group = gPlayers[2].group;
    s32 file = D_8010B1B4_1B4844_SkyPilots[gPlayers[2].character];
    s32 dir = 0x2C0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80107074_1B0704_SkyPilots(obj, dir, file, team, 2);
        break;
    case 1:
    case 3:
        file = D_8010B1CC_1B485C_SkyPilots[gPlayers[2].character];
        func_801073A8_1B0A38_SkyPilots(obj, dir, file, team, 2);
        break;
    }
}

void func_8010A294_1B3924_SkyPilots(omObjData* obj) {
    u32 group = gPlayers[3].group;
    s32 file = D_8010B1B4_1B4844_SkyPilots[gPlayers[3].character];
    s32 dir = 0x2C0000;
    s32 team = (group >> 1) & 1;

    switch (group) {
    case 0:
    case 2:
        func_80107074_1B0704_SkyPilots(obj, dir, file, team, 3);
        break;
    case 1:
    case 3:
        file = D_8010B1CC_1B485C_SkyPilots[gPlayers[3].character];
        func_801073A8_1B0A38_SkyPilots(obj, dir, file, team, 3);
        break;
    }
}
