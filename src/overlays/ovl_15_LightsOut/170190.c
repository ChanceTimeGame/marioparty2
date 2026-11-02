#include "ovl_15.h"

void func_80102800_170190_LightsOut(void) {
    func_8010B1C8_178B58_LightsOut();
}

void func_8010281C_1701AC_LightsOut(Gfx** gfxp) {
    Gfx* gfx = *gfxp;
    s32 y;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                    G_CULL_BOTH | G_FOG | G_LOD);
    gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, D_8010CCC4_17A654_LightsOut->unk0C);
    for (y = 0; y < 112; y += 8) {
        gDPLoadTextureTile_4b(gfx++, D_8010CCC4_17A654_LightsOut->unk08, G_IM_FMT_CI, 288, 112, 0, y, 287,
                              y + 7, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 288 << 2, 8 << 2);
        gSPTextureRectangle(gfx++, 17 << 2, (y + 120) << 2, 305 << 2, (y + 128) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102B50_1704E0_LightsOut(void) {
}

void func_80102B58_1704E8_LightsOut(omObjData* obj) {
    s32 mdl;

    D_8010CD26_17A6B6_LightsOut = func_8001A2F8_1AEF8(0x250003);
    D_8010CCC4_17A654_LightsOut = SprAnimGet(D_8010CD26_17A6B6_LightsOut);
    obj->func_ptr = func_80102B50_1704E0_LightsOut;
    mdl = func_8002838C_28F8C(0, func_8010281C_1701AC_LightsOut, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_8010EC0C_17C59C_LightsOut = mdl;
}

void func_80102BDC_17056C_LightsOut(void) {
    D_8010D9C0_17B350_LightsOut = omAddObj(400, 0, 0, -1, func_80102B58_1704E8_LightsOut);
}

void func_80102C18_1705A8_LightsOut(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 2120.0f;
        D_80102770_103370[i].x = 333.55f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 57.5f;
        D_801013B0_101FB0[i].z = -105.0f;
    }
}

void func_80102CC4_170654_LightsOut(void) {
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
}

void func_80102CF0_170680_LightsOut(omObjData* obj) {
    GroundWork* gw;

    D_8010CD18_17A6A8_LightsOut[0] = func_8001A2F8_1AEF8(0x250002);
    D_8010D310_17ACA0_LightsOut = SprCreate(1, 0);
    SprAttrReset(D_8010D310_17ACA0_LightsOut, 0, -1);
    SprScaleSet(D_8010D310_17ACA0_LightsOut, 0, 1.0f, 1.0f);
    SprAnimSet(D_8010D310_17ACA0_LightsOut, 0, D_8010CD18_17A6A8_LightsOut[0], 0);
    SprBankSet(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprAttrSet(D_8010D310_17ACA0_LightsOut, 0, 0x5000);
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
    func_8008225C_82E5C(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprPrioSet(D_8010D310_17ACA0_LightsOut, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_80102CC4_170654_LightsOut;
}

void func_80102EB8_170848_LightsOut(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_8010D30C_17AC9C_LightsOut = omAddObj(10, 2, 0, -1, func_80102CF0_170680_LightsOut);
}

void func_80102F00_170890_LightsOut(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

/* The hammer's reach: is (x, y, z) inside the blast cylinder of radius `reach`, 30 either way? */
#ifdef NON_MATCHING
/* register allocation (masked 0): the abs temporary */
s32 func_80102F9C_17092C_LightsOut(f32 x, f32 y, f32 z, f32 reach) {
    f32 out[3];
    f32 d;
    f32 h;

    func_80102F00_170890_LightsOut(D_8010D16C_17AAFC_LightsOut, x, y, z, out);
    D_8010D140_17AAD0_LightsOut = out[0];
    D_8010D144_17AAD4_LightsOut = out[1];
    D_8010D148_17AAD8_LightsOut = out[2];
    if (reach * reach + 3600.0f < (d = out[0] * out[0] + out[2] * out[2])) {
        return 0;
    }
    if (reach + 30.0f < LO_ABS(out[1])) {
        return 0;
    }
    h = LO_ABS(out[1]) - 30;
    if (h <= 0.0f) {
        return 1;
    }
    h = func_800B1830_B2430(h * h + reach * reach);
    if (h * h + 3600.0f < d) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80102F9C_17092C_LightsOut);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80103114_170AA4_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010335C_170CEC_LightsOut);

void func_80103620_170FB0_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x8000;
}

void func_80103648_170FD8_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x4000;
}

void func_80103670_171000_LightsOut(void) {
}

f32 func_80103678_171008_LightsOut(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

void func_801037C8_171158_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    f32 angle = work->unk_3C;
    f32 mag;

    if (D_8010CD84_17A714_LightsOut != 3) {
        switch (gPlayers[work->unk_59].cpu_difficulty) {
            case 0:
                mag = (rand8() & 3) * 5 + 50;
                break;
            case 1:
                mag = (u8)(rand8() % 5) * 5 + 45;
                break;
            default:
                mag = (u8)(rand8() % 6) * 5 + 40;
                break;
        }
    } else {
        mag = 70.0f;
    }
    ContStkX[work->unk_57] = mag * HuMathSin(angle);
    ContStkY[work->unk_57] = -mag * func_800B7890_B8490(angle);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80103968_1712F8_LightsOut);

void func_80103CA8_171638_LightsOut(omObjData* obj, s16 motion, char* name) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    LOMtxSet* set;
    Matrix4f* dst;
    Matrix4f* src;
    s32 i;
    s32 j;

    func_80029B80_2A780(obj->model[0], obj->motion[motion]);
    set = func_800232FC_23EFC(obj->model[0], 2, name);
    for (i = 0; i < 2; i++) {
        if (p->mtxCount[i] == 0) {
            break;
        }
    }
    if (i < 2) {
        p->mtx[i] = dst = func_80027154_27D54((p->mtxCount[i] = set->count) * 64, 0x7918);
        src = set->mtx;
        for (j = 0; j < p->mtxCount[i]; j++) {
            func_80030CD4_318D4(*dst++, *src++);
        }
    }
    func_80023D74_24974(set);
}

f32 func_80103DFC_17178C_LightsOut(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }

    return a;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80103E74_171804_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80104228_171BB8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801045DC_171F6C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80104990_172320_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80104D48_1726D8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80104EEC_17287C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801050E8_172A78_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105340_172CD0_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105438_172DC8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105AF8_173488_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105B00_173490_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105B78_173508_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105BF0_173580_LightsOut);

__asm__(".section .rodata");
const char D_8010CAF8_17A488_LightsOut[16] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80105C14_1735A4_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801062A8_173C38_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801063E8_173D78_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80106BCC_17455C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801073B0_174D40_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80107BB4_175544_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801083A4_175D34_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80108530_175EC0_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010875C_1760EC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801094B8_176E48_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801099F0_177380_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109B28_1774B8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109C30_1775C0_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109F58_1778E8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A090_177A20_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A0CC_177A5C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A4C0_177E50_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A5D0_177F60_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A680_178010_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A6C4_178054_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A980_178310_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AAAC_17843C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ACD0_178660_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AD1C_1786AC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ADA4_178734_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ADC8_178758_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AE00_178790_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AE58_1787E8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B04C_1789DC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B0CC_178A5C_LightsOut);

__asm__(".section .rodata");
const char D_8010CB90_17A520_LightsOut[] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B1C8_178B58_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B3B8_178D48_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B648_178FD8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010BDE8_179778_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010BEA4_179834_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010C070_179A00_LightsOut);
