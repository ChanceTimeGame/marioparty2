#include "ovl_20.h"

extern const char D_8010B674_1CFA24_MagnetCarta[];
extern const char D_8010B684_1CFA34_MagnetCarta[];
extern const char D_8010B694_1CFA44_MagnetCarta[20];

/* .data (0x1CF900-0x1CFA10, 8010B550-8010B660) */
u16 D_8010B550_1CF900_MagnetCarta[6] = { 13, 14, 15, 16, 17, 18 };
MCPost D_8010B55C_1CF90C_MagnetCarta[4] = {
    { 505.3905029f, 290.3901367f },
    { -505.3905029f, 290.3901367f },
    { 505.3905029f, -290.3901367f },
    { -505.3905029f, -290.3901367f },
};
s16 D_8010B57C_1CF92C_MagnetCarta[2] = { 12, 11 };
MCStart D_8010B580_1CF930_MagnetCarta[2] = { { 400, 0, 200, 270 }, { 400, 0, -200, 270 } };
MCStart D_8010B590_1CF940_MagnetCarta[2] = { { -400, 0, 200, 90 }, { -400, 0, -200, 90 } };
MCStart D_8010B5A0_1CF950_MagnetCarta[3] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, -100, 0 } };
MCRing D_8010B5B8_1CF968_MagnetCarta[1][9] = { {
    { 188.25f, { 0.0f, 0.0f }, 0.0f },
    { 188.25f, { 0.0f, 0.0f }, 40.0f },
    { 188.25f, { 0.0f, 0.0f }, 80.0f },
    { 188.25f, { 0.0f, 0.0f }, 120.0f },
    { 188.25f, { 0.0f, 0.0f }, 160.0f },
    { 188.25f, { 0.0f, 0.0f }, 200.0f },
    { 188.25f, { 0.0f, 0.0f }, 240.0f },
    { 188.25f, { 0.0f, 0.0f }, 280.0f },
    { 188.25f, { 0.0f, 0.0f }, 320.0f },
} };
u16 D_8010B648_1CF9F8_MagnetCarta[4] = { 25, 26, 27, 0 };
char* D_8010B650_1CFA00_MagnetCarta[4] = { (char*)D_8010B694_1CFA44_MagnetCarta, (char*)D_8010B684_1CFA34_MagnetCarta, (char*)D_8010B674_1CFA24_MagnetCarta, NULL };

void func_80102800_1C6BB0_MagnetCarta(void) {
    func_8010ACB4_1CF064_MagnetCarta();
}

void func_8010281C_1C6BCC_MagnetCarta(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 3037.9253f;
        D_80102770_103370[i].x = 317.74857f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 52.65f;
        D_801013B0_101FB0[i].z = -82.55f;
    }
}

void func_801028D0_1C6C80_MagnetCarta(omObjData* obj) {
    SprPosSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 160, 120);
}

void func_801028FC_1C6CAC_MagnetCarta(omObjData* obj) {
    GroundWork* gw;

    D_8010BD68_1D0118_MagnetCarta[0] = func_8001A2F8_1AEF8(0x300000);
    D_8010D88C_1D1C3C_MagnetCarta = SprCreate(1, 0);
    SprAttrReset(D_8010D88C_1D1C3C_MagnetCarta, 0, -1);
    SprScaleSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 1.0f, 1.0f);
    SprAnimSet(D_8010D88C_1D1C3C_MagnetCarta, 0, D_8010BD68_1D0118_MagnetCarta[0], 0);
    SprBankSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 0);
    SprAttrSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 0x5000);
    SprPosSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 160, 120);
    func_8008225C_82E5C(D_8010D88C_1D1C3C_MagnetCarta, 0, 0);
    SprPrioSet(D_8010D88C_1D1C3C_MagnetCarta, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_801028D0_1C6C80_MagnetCarta;
}

void func_80102AB0_1C6E60_MagnetCarta(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_8010BDD0_1D0180_MagnetCarta[45].obj = omAddObj(10, 2, 0, -1, func_801028FC_1C6CAC_MagnetCarta);
}

void func_80102AF8_1C6EA8_MagnetCarta(Gfx** gfxp) {
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
    gDPLoadTLUT_pal256(gfx++, D_8010DBC0_1D1F70_MagnetCarta->unk0C);
    for (y = 0; y < 80; y += 4) {
        gDPLoadTextureTile(gfx++, D_8010DBC0_1D1F70_MagnetCarta->unk08, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 80, 0, y, 319,
                           y + 3, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 320 << 2, 4 << 2);
        gSPTextureRectangle(gfx++, 0 << 2, (y + 160) << 2, 320 << 2, (y + 164) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102E14_1C71C4_MagnetCarta(void) {
}

void func_80102E1C_1C71CC_MagnetCarta(omObjData* obj) {
    s32 mdl;

    D_8010BD68_1D0118_MagnetCarta[1] = func_8001A2F8_1AEF8(0x300001);
    D_8010DBC0_1D1F70_MagnetCarta = SprAnimGet(D_8010BD68_1D0118_MagnetCarta[1]);
    obj->func_ptr = func_80102E14_1C71C4_MagnetCarta;
    mdl = func_8002838C_28F8C(0, func_80102AF8_1C6EA8_MagnetCarta, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_8010BD60_1D0110_MagnetCarta = mdl;
}

void func_80102EA0_1C7250_MagnetCarta(void) {
    D_8010BDD0_1D0180_MagnetCarta[46].obj = omAddObj(300, 0, 0, -1, func_80102E1C_1C71CC_MagnetCarta);
}

void func_80102EDC_1C728C_MagnetCarta(omObjData* obj) {
    u8 tens;
    u8 ones;
    s16 i;

    if (D_8010DBBC_1D1F6C_MagnetCarta != D_8010DBA8_1D1F58_MagnetCarta) {
        PlaySound(9);
        D_8010DBBC_1D1F6C_MagnetCarta++;
    }
    if (D_8010BDCE_1D017E_MagnetCarta != D_8010DB98_1D1F48_MagnetCarta) {
        PlaySound(9);
        D_8010BDCE_1D017E_MagnetCarta++;
    }
    tens = D_8010DBBC_1D1F6C_MagnetCarta / 10;
    ones = D_8010DBBC_1D1F6C_MagnetCarta - tens * 10;
    func_8003E560_3F160(D_8010BD50_1D0100_MagnetCarta[0], tens);
    func_8003E560_3F160(D_8010BD50_1D0100_MagnetCarta[1], ones);
    tens = D_8010BDCE_1D017E_MagnetCarta / 10;
    ones = D_8010BDCE_1D017E_MagnetCarta - tens * 10;
    func_8003E560_3F160(D_8010BD50_1D0100_MagnetCarta[2], tens);
    func_8003E560_3F160(D_8010BD50_1D0100_MagnetCarta[3], ones);
    for (i = 0; i < 4; i++) {
        func_80029714_2A314(obj->model[i], obj->trans.x, -10.0f, obj->trans.z);
    }
}

void func_80103064_1C7414_MagnetCarta(omObjData* obj) {
    u16 ids[4] = { 6, 7, 8, 9 };
    void* data;
    f32 zero;
    s16 tex;
    s16 i;

    data = DataRead(0x300005);
    for (i = 0; i < 4; i++) {
        obj->model[i] = LoadFormFile(ids[i] | 0x300000, 0xA9);
        tex = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[i]].hmf, data, 0, "score_DEF");
        D_8010BD50_1D0100_MagnetCarta[i] = tex;
        func_80029A8C_2A68C(obj->model[i]);
        func_8003E4F4_3F0F4(tex, 1, 1);
        func_8003E560_3F160(D_8010BD50_1D0100_MagnetCarta[i], 0);
        func_80029AFC_2A6FC(obj->model[i]);
    }
    HuMemMemoryFreePerm(data);
    zero = 0.0f;
    obj->trans.z = zero;
    obj->trans.x = zero;
    obj->trans.y = -5.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.07f;
    for (i = 0; i < 4; i++) {
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_80029714_2A314(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029EDC_2AADC(obj->model[i], 1);
    }
    obj->func_ptr = func_80102EDC_1C728C_MagnetCarta;
}

void func_80103284_1C7634_MagnetCarta(void) {
    omObjData* o = omAddObj(500, 4, 1, -1, func_80103064_1C7414_MagnetCarta);

    o->work[0] = 30;
    D_8010BDD0_1D0180_MagnetCarta[30].obj = o;
}

void func_801032C8_1C7678_MagnetCarta(omObjData* obj) {
    MCFxWork* w;
    MCFx* fx;
    u16 m;
    s16 i;
    omObjData* o;

    w = obj->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] != 0) {
            fx = &w->fx[i];
            m = D_800F86D8_F92D8[fx->model].unk00;
            switch (w->state[i]) {
            case 1:
                break;
            case 2:
                o = D_8010BDD0_1D0180_MagnetCarta[fx->owner].obj;
                func_80029714_2A314(m, o->trans.x, o->trans.y + 60.0f, o->trans.z);
                if (o->scale.x <= 0.0f) {
                    func_800298A4_2A4A4(m, 4, 4);
                } else {
                    func_800298A4_2A4A4(m, 4, 0);
                    func_800297E8_2A3E8(m, 5.0f, 10.0f, 5.0f);
                }
                break;
            }
            func_800211E8_21DE8(fx->model, fx->alpha);
            if (D_800FC834_FD434[(s16)m].unk18 & 4) {
                w->state[i] = 0;
            }
        }
    }
}

void func_80103494_1C7844_MagnetCarta(omObjData* obj) {
    MCFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80027154_27D54(sizeof(MCFxWork), 0x7918);
    data = DataRead(0x30000A);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 20; i++) {
        w->fx[i].model = m = func_80020EBC_21ABC((void*)-1, 0x284, 8);
        func_80021250_21E50(m, 0xFF, 0xFF, 0x3F);
        D_800F86D8_F92D8[m].unk02 = tex;
        func_80021160_21D60(m, 2, 0);
        w->state[i] = 0;
    }
    obj->func_ptr = func_801032C8_1C7678_MagnetCarta;
}

void func_801035B4_1C7964_MagnetCarta(void) {
    D_8010DBC8_1D1F78_MagnetCarta = omAddObj(600, 0, 0, -1, func_80103494_1C7844_MagnetCarta);
}

void func_801035F0_1C79A0_MagnetCarta(s16 player, f32 x, f32 y, f32 z, u16 type, MCObj* p) {
    MCFxWork* w;
    MCFx* fx;
    u16 m;
    s16 i;
    omObjData* o;

    w = D_8010DBC8_1D1F78_MagnetCarta->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i != 20) {
        fx = &w->fx[i];
        m = D_800F86D8_F92D8[fx->model].unk00;
        o = p->obj;
        fx->x = o->trans.x;
        fx->y = o->trans.y;
        fx->z = o->trans.z;
        fx->vy = 2.0f;
        fx->alpha = 0xFF;
        w->state[i] = type;
        fx->unk_02 = 1;
        fx->owner = o->work[0];
        func_800211E8_21DE8(fx->model, 0);
        func_800298A4_2A4A4(m, 4, 0);
        D_800F86D8_F92D8[fx->model].unk04 = 0;
        func_80029714_2A314(m, o->trans.x, o->trans.y, o->trans.z);
        func_800297E8_2A3E8(m, 5.0f, 10.0f, 5.0f);
        func_80029EDC_2AADC(m, 1);
    }
}

void func_80103760_1C7B10_MagnetCarta(omObjData* obj) {
    MCFxWork* w;
    MCFx* fx;
    u16 m;
    s16 i;

    w = obj->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] != 0) {
            fx = &w->fx[i];
            m = D_800F86D8_F92D8[fx->model].unk00;
            switch (w->state[i]) {
            case 1:
                break;
            case 2:
                fx->y += fx->vy;
                fx->vy += 0.3f;
                func_80029714_2A314(m, fx->x, fx->y, fx->z);
                break;
            }
            func_800211E8_21DE8(fx->model, fx->alpha);
            if (D_800FC834_FD434[(s16)m].unk18 & 4) {
                w->state[i] = 0;
            }
        }
    }
}

void func_80103894_1C7C44_MagnetCarta(omObjData* obj) {
    MCFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80027154_27D54(sizeof(MCFxWork), 0x7918);
    data = DataRead(0x40001C);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 20; i++) {
        w->fx[i].model = m = func_80020EBC_21ABC((void*)-1, 0x284, 8);
        func_80021250_21E50(m, 0xFF, 0xFF, 0xBE);
        D_800F86D8_F92D8[m].unk02 = tex;
        func_80021160_21D60(m, 4, 4);
        w->state[i] = 0;
    }
    obj->func_ptr = func_80103760_1C7B10_MagnetCarta;
}

void func_801039B4_1C7D64_MagnetCarta(void) {
    D_8010DBB0_1D1F60_MagnetCarta = omAddObj(600, 0, 0, -1, func_80103894_1C7C44_MagnetCarta);
}

void func_801039F0_1C7DA0_MagnetCarta(s16 player, f32 x, f32 y, f32 z, u16 type) {
    MCFxWork* w;
    MCFx* fx;
    u16 m;
    s16 i;

    w = D_8010DBB0_1D1F60_MagnetCarta->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i != 20) {
        fx = &w->fx[i];
        m = D_800F86D8_F92D8[fx->model].unk00;
        fx->x = x;
        fx->y = y;
        fx->z = z;
        fx->vy = 2.0f;
        fx->alpha = 0xFF;
        w->state[i] = type;
        fx->unk_02 = 1;
        func_800211E8_21DE8(fx->model, 0);
        func_800298A4_2A4A4(m, 4, 0);
        D_800F86D8_F92D8[fx->model].unk04 = 0;
        func_80029714_2A314(m, x, y, z);
        func_800297E8_2A3E8(m, 2.0f, 2.0f, 2.0f);
        func_80029EDC_2AADC(m, 1);
    }
}

__asm__(".section .rodata");
const char D_8010B674_1CFA24_MagnetCarta[] = "signl_3x_DEF";

__asm__(".section .rodata");
const char D_8010B684_1CFA34_MagnetCarta[] = "signl_2x_DEF";

__asm__(".section .rodata");
const char D_8010B694_1CFA44_MagnetCarta[20] = "signl_1x_DEF";

void func_80103B70_1C7F20_MagnetCarta(omObjData* obj) {
    MCObj* sig = &D_8010BDD0_1D0180_MagnetCarta[40];
    s16 i;

    switch (D_8010DBAC_1D1F5C_MagnetCarta) {
    case 0:
        obj->trans.y -= 6.0f;
        sig->size += 0.02;
        PlayMusic(0x1D);
        if (obj->trans.y <= 360.0f) {
            obj->trans.y = 360.0f;
            D_8010DBAC_1D1F5C_MagnetCarta = 1;
        }
        func_800297E8_2A3E8(obj->model[1], sig->size, 0.0f, sig->size);
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        break;
    case 1:
        obj->trans.y += (f32)sig->lift * 0.1f;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], 1.5f, 0.0f, 1.5f);
        func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
        if (sig->state == 0) {
            if (++sig->lift > 10) {
                sig->state ^= 1;
            }
        } else {
            if (--sig->lift < -10) {
                sig->state ^= 1;
            }
        }
        if (sig->timer == 0) {
            for (i = 0; i < 3; i++) {
                func_8003E4F4_3F0F4(D_8010DB82_1D1F32_MagnetCarta[i], 1, 0);
            }
        } else if (sig->timer == 30) {
            PlaySound(0x2D9);
        } else if (sig->timer == 60) {
            PlaySound(0x2D9);
        } else if (sig->timer == 90) {
            D_8010DBB6_1D1F66_MagnetCarta = 1;
            PlaySound(0x2DA);
        }
        sig->timer++;
        if (D_8010DB80_1D1F30_MagnetCarta == 2) {
            D_8010DBAC_1D1F5C_MagnetCarta = 3;
            sig->timer = 0;
        }
        break;
    case 2:
        sig->timer++;
        if (sig->timer >= 10) {
            D_8010DBAC_1D1F5C_MagnetCarta = 3;
        }
        break;
    case 3:
        obj->trans.y += 20.0f;
        sig->size -= 0.05f;
        if (sig->size <= 0.0f) {
            sig->size = 0.0f;
            obj->trans.y = 1500.0f;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], sig->size, 0.0f, sig->size);
        break;
    }
}

void func_80103F34_1C82E4_MagnetCarta(omObjData* obj) {
    s16 i;

    obj->model[0] = LoadFormFile(0x190006, 0x2A9);
    for (i = 0; i < 3; i++) {
        D_8010DB9C_1D1F4C_MagnetCarta[i] = DataRead(D_8010B648_1CF9F8_MagnetCarta[i] | 0x190000);
        D_8010DB82_1D1F32_MagnetCarta[i] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_8010DB9C_1D1F4C_MagnetCarta[i], 0, D_8010B650_1CFA00_MagnetCarta[i]);
        func_8003E4F4_3F0F4(D_8010DB82_1D1F32_MagnetCarta[i], 1, 1);
        HuMemMemoryFreePerm(D_8010DB9C_1D1F4C_MagnetCarta[i]);
    }
    func_80029A8C_2A68C(obj->model[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029AFC_2A6FC(obj->model[0]);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
    obj->trans.x = 0.0f;
    obj->trans.y = 600.0f;
    obj->trans.z = 0.0f;
    obj->rot.y = 15.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 0.7f, 0.0f, 0.7f);
    D_8010BDD0_1D0180_MagnetCarta[40].size = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    D_8010DBAC_1D1F5C_MagnetCarta = 0;
    obj->func_ptr = func_80103B70_1C7F20_MagnetCarta;
}

void func_801041F0_1C85A0_MagnetCarta(void) {
    D_8010BDD0_1D0180_MagnetCarta[40].obj = omAddObj(600, 2, 1, -1, func_80103F34_1C82E4_MagnetCarta);
}

void func_8010422C_1C85DC_MagnetCarta(void) {
    MCObj* p;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL) {
            o = p->obj;
            if (o->work[3] == 0) {
                gPlayers[o->work[0]].coins_mg = D_8010DB98_1D1F48_MagnetCarta;
            } else {
                gPlayers[o->work[0]].coins_mg = D_8010DBA8_1D1F58_MagnetCarta;
            }
        }
    }
}

void func_801042F4_1C86A4_MagnetCarta(void) {
    if (D_8010DBB8_1D1F68_MagnetCarta > 0) {
        if (--D_8010DBB8_1D1F68_MagnetCarta == 0) {
            D_8010DBB8_1D1F68_MagnetCarta = 0;
            D_8010DBB6_1D1F66_MagnetCarta = 1;
        } else if (D_8010DBB8_1D1F68_MagnetCarta == 10) {
            func_80079614_7A214(40);
        }
    }
}

void func_80104360_1C8710_MagnetCarta(omObjData* obj) {
    if (_CheckFlag(0xC) != 0) {
        if (D_8010DBB8_1D1F68_MagnetCarta > 0) {
            if (--D_8010DBB8_1D1F68_MagnetCarta == 165) {
                func_8006D518_6E118();
            }
            if (D_8010DBB8_1D1F68_MagnetCarta < 121) {
                D_8010DBB8_1D1F68_MagnetCarta = 0;
                D_8010DBB6_1D1F66_MagnetCarta = 2;
            }
        }
    } else {
        if (D_8010DBB8_1D1F68_MagnetCarta > 0) {
            if (--D_8010DBB8_1D1F68_MagnetCarta == 165) {
                func_8006D518_6E118();
            }
        }
        if (func_80069538_6A138() == 0) {
            D_8010DBB6_1D1F66_MagnetCarta = 1;
            obj->func_ptr = func_801042F4_1C86A4_MagnetCarta;
            if (D_8010DBBC_1D1F6C_MagnetCarta != 0 || D_8010BDCE_1D017E_MagnetCarta != 0) {
                PlayMusic(0x52);
                D_8010DBB8_1D1F68_MagnetCarta = 168;
            } else {
                PlayMusic(0x56);
                D_8010DBB8_1D1F68_MagnetCarta = 132;
            }
        }
    }
}

void func_80104490_1C8840_MagnetCarta(omObjData* obj) {
    MCObj* p;
    s16 left = 0;
    s16 i;

    for (i = 4; i < 14; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            left = 1;
            break;
        }
    }
    if (left == 0) {
        D_8010DBB6_1D1F66_MagnetCarta = 1;
        func_8006D518_6E118();
        func_800691FC_69DFC(3);
        obj->func_ptr = func_80104360_1C8710_MagnetCarta;
        D_8010DBB8_1D1F68_MagnetCarta = 180;
        func_800794A8_7A0A8(40);
    } else if (D_8010DBB8_1D1F68_MagnetCarta > 0) {
        D_8010DBB8_1D1F68_MagnetCarta--;
        func_8006D4D0_6E0D0((D_8010DBB8_1D1F68_MagnetCarta + 29) / 30);
    } else {
        obj->func_ptr = func_80104360_1C8710_MagnetCarta;
        D_8010DBB6_1D1F66_MagnetCarta = 1;
        func_8006D4D0_6E0D0(0);
        D_8010DBB8_1D1F68_MagnetCarta = 180;
        if (_CheckFlag(0xC) == 0) {
        }
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
    }
}

void func_801045F4_1C89A4_MagnetCarta(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    D_8010DBB8_1D1F68_MagnetCarta = 901;
    obj->func_ptr = func_80104490_1C8840_MagnetCarta;
}

void func_80104640_1C89F0_MagnetCarta(omObjData* obj) {
    if (D_8010DB80_1D1F30_MagnetCarta == 1) {
        if (D_8010DBB8_1D1F68_MagnetCarta == 0) {
            func_800691FC_69DFC(0);
            D_8010DBB8_1D1F68_MagnetCarta++;
        }
        if (func_80069538_6A138() == 0) {
            D_8010DBB6_1D1F66_MagnetCarta = 1;
            D_8010DBB8_1D1F68_MagnetCarta = 0;
            obj->func_ptr = func_801045F4_1C89A4_MagnetCarta;
        }
    }
}

void func_801046C8_1C8A78_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    MCObj* q;
    omObjData* o;

    if (p->state == 0) {
        if (p->attached == 1) {
            q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
            o = q->obj;
            obj->trans.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
            obj->trans.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
        }
    } else if (p->state == 1) {
        if (p->dust == 0) {
            func_801035F0_1C79A0_MagnetCarta(0, obj->trans.x, 0.0f, obj->trans.z, 2, p);
            p->dust = 3;
        }
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        if (c->bounce <= 0.0f) {
            c->bounce = 0.0f;
        } else {
            c->bounce -= 1.0f;
        }
        if (obj->scale.x <= 0.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            p->timer = 0;
            p->state = 2;
            if (obj->trans.x < 0.0f) {
                D_8010DBA8_1D1F58_MagnetCarta += 10;
            } else {
                D_8010DB98_1D1F48_MagnetCarta += 10;
            }
        } else {
            obj->scale.x -= p->size;
            obj->scale.y -= p->size;
            obj->scale.z -= p->size;
            func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        }
        obj->trans.x = obj->trans.x - HuMathSin(c->dir + 180.0f) * c->bounce;
        obj->trans.z = obj->trans.z - func_800B7890_B8490(c->dir + 180.0f) * c->bounce + 10.0f;
    }
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
}

void func_80104970_1C8D20_MagnetCarta(omObjData* obj) {
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    s32 i;

    obj->model[0] = LoadFormFile(0x300013, 0x2B9);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    i = D_8010DBB7_1D1F67_MagnetCarta;
    obj->trans.x = D_8010B5A0_1CF950_MagnetCarta[i].x;
    obj->trans.y = D_8010B5A0_1CF950_MagnetCarta[i].y;
    obj->trans.z = D_8010B5A0_1CF950_MagnetCarta[i].z;
    obj->rot.y = D_8010B5A0_1CF950_MagnetCarta[i].rot;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.7f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    c->mass = 7.0f;
    obj->func_ptr = func_801046C8_1C8A78_MagnetCarta;
}

void func_80104B70_1C8F20_MagnetCarta(void) {
    omObjData* o = omAddObj(500, 2, 1, -1, func_80104970_1C8D20_MagnetCarta);

    o->work[0] = 4;
    D_8010BDD0_1D0180_MagnetCarta[4].obj = o;
}

void func_80104BB4_1C8F64_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    MCObj* q;
    omObjData* o;

    if (p->state == 0) {
        if (p->attached == 1) {
            q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
            o = q->obj;
            obj->trans.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
            obj->trans.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
        }
    } else if (p->state == 1) {
        if (p->dust == 0) {
            func_801035F0_1C79A0_MagnetCarta(0, obj->trans.x, 0.0f, obj->trans.z, 2, p);
            p->dust = 3;
        }
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        if (c->bounce <= 0.0f) {
            c->bounce = 0.0f;
        } else {
            c->bounce -= 1.0f;
        }
        if (obj->scale.x <= 0.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            p->timer = 0;
            p->state = 2;
            if (obj->trans.x < 0.0f) {
                D_8010DBA8_1D1F58_MagnetCarta += 5;
            } else {
                D_8010DB98_1D1F48_MagnetCarta += 5;
            }
        } else {
            obj->scale.x -= p->size;
            obj->scale.y -= p->size;
            obj->scale.z -= p->size;
            func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        }
        obj->trans.x = obj->trans.x - HuMathSin(c->dir + 180.0f) * c->bounce;
        obj->trans.z = obj->trans.z - func_800B7890_B8490(c->dir + 180.0f) * c->bounce + 10.0f;
    }
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
}

void func_80104E5C_1C920C_MagnetCarta(omObjData* obj) {
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    f32 zero;
    u8 r;

    obj->model[0] = LoadFormFile(0x300003, 0x2B9);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    r = rand8() % 9;
    while (D_8010DB88_1D1F38_MagnetCarta[r] != 0) {
        r = rand8() % 9;
    }
    D_8010DB88_1D1F38_MagnetCarta[r] = 1;
    obj->trans.x = HuMathSin(D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].angle) * D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].r;
    obj->trans.z = func_800B7890_B8490(D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].angle) * D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].r;
    zero = 0.0f;
    obj->rot.y = zero;
    obj->trans.y = zero;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.4f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, zero, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.3f, obj->scale.y, 1.3f);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    c->mass = 5.0f;
    obj->func_ptr = func_80104BB4_1C8F64_MagnetCarta;
}

void func_80105124_1C94D4_MagnetCarta(void) {
    MCObj* p;
    omObjData* o;
    s16 i;

    for (i = 5; i < 9; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        o = omAddObj(500, 2, 0, -1, func_80104E5C_1C920C_MagnetCarta);
        o->work[0] = i;
        p->obj = o;
    }
}

void func_801051C8_1C9578_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    MCObj* q;
    omObjData* o;

    if (p->state == 0) {
        if (p->attached == 1) {
            q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
            o = q->obj;
            obj->trans.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
            obj->trans.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
        }
    } else if (p->state == 1) {
        if (p->dust == 0) {
            func_801035F0_1C79A0_MagnetCarta(0, obj->trans.x, 0.0f, obj->trans.z, 2, p);
            p->dust = 3;
        }
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        if (c->bounce <= 0.0f) {
            c->bounce = 0.0f;
        } else {
            c->bounce -= 1.0f;
        }
        if (obj->scale.x <= 0.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            p->timer = 0;
            p->state = 2;
            if (obj->trans.x < 0.0f) {
                D_8010DBA8_1D1F58_MagnetCarta += 1;
            } else {
                D_8010DB98_1D1F48_MagnetCarta += 1;
            }
        } else {
            obj->scale.x -= p->size;
            obj->scale.y -= p->size;
            obj->scale.z -= p->size;
            func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        }
        obj->trans.x = obj->trans.x - HuMathSin(c->dir + 180.0f) * c->bounce;
        obj->trans.z = obj->trans.z - func_800B7890_B8490(c->dir + 180.0f) * c->bounce + 10.0f;
    }
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
}

void func_80105470_1C9820_MagnetCarta(omObjData* obj) {
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    u8 r;

    obj->model[0] = LoadFormFile(0x300004, 0x2B9);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    r = rand8() % 9;
    while (D_8010DB88_1D1F38_MagnetCarta[r] != 0) {
        r = rand8() % 9;
    }
    D_8010DB88_1D1F38_MagnetCarta[r] = 1;
    obj->trans.x = HuMathSin(D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].angle) * D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].r;
    obj->trans.z = func_800B7890_B8490(D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].angle) * D_8010B5B8_1CF968_MagnetCarta[D_8010DBB7_1D1F67_MagnetCarta][r].r;
    obj->trans.y = 0.0f;
    obj->rot.y = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.2f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.2f, obj->scale.y, 1.2f);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    c->mass = 1.0f;
    obj->func_ptr = func_801051C8_1C9578_MagnetCarta;
}

void func_80105730_1C9AE0_MagnetCarta(void) {
    MCObj* p;
    omObjData* o;
    s16 i;

    for (i = 9; i < 14; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        o = omAddObj(500, 2, 0, -1, func_80105470_1C9820_MagnetCarta);
        o->work[0] = i;
        p->obj = o;
    }
}

// register allocation (masked 0, raw 61): p and car sit in each other's saved register (retail p s2, car s1),
// and x's product goes through f0 before f24. Tried: car assigned first (masked 35), p declared first (same),
// x inlined into the func_801039F0 call (raw 73).
#ifdef NON_MATCHING
void func_801057D4_1C9B84_MagnetCarta(omObjData* obj) {
    MCCar* car;
    MCObj* p;
    MCObj* q;
    omObjData* o;
    f32 x;
    f32 w;
    f32 z;
    f32 t;

    p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    car = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    if (p->timer == 0) {
        car->steer = 0.0f;
        if (D_8010DB80_1D1F30_MagnetCarta == 4) {
            if (p->attached == 1) {
                q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
                p->attached = 0;
                p->target = 0;
                q->attached = 0;
                q->target = 0;
            }
            if (_CheckFlag(0xC) == 0) {
                if (obj->work[3] == 0) {
                    if (D_8010BDCE_1D017E_MagnetCarta != 0) {
                        obj->rot.y = MC_WRAP(obj->rot.y - 15.0f);
                        if (p->spin == 0) {
                            x = HuMathSin(obj->rot.y + 180.0f) * 75.0f + obj->trans.x;
                            func_801039F0_1C7DA0_MagnetCarta(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f + obj->trans.z, 2);
                            p->spin++;
                        } else if (p->spin == 2) {
                            p->spin = 0;
                        } else {
                            p->spin++;
                        }
                        car->tick++;
                        if (D_8010DB80_1D1F30_MagnetCarta != 5) {
                            if (D_8010DBB8_1D1F68_MagnetCarta == 0xA7) {
                                car->sndFwd = func_80079798_7A398(0x24A, obj->work[0]);
                            }
                        } else if (car->sndFwd != -1) {
                            func_80079848_7A448(car->sndFwd);
                            car->sndFwd = -1;
                        }
                    }
                } else if (D_8010DBBC_1D1F6C_MagnetCarta != 0) {
                    obj->rot.y = MC_WRAP(obj->rot.y - 15.0f);
                    if (p->spin == 0) {
                        x = HuMathSin(obj->rot.y + 180.0f) * 75.0f + obj->trans.x;
                        func_801039F0_1C7DA0_MagnetCarta(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f + obj->trans.z, 2);
                        p->spin++;
                    } else if (p->spin == 2) {
                        p->spin = 0;
                    } else {
                        p->spin++;
                    }
                    car->tick++;
                    if (D_8010DB80_1D1F30_MagnetCarta != 5) {
                        if (D_8010DBB8_1D1F68_MagnetCarta == 0xA7) {
                            car->sndFwd = func_80079798_7A398(0x24A, obj->work[0]);
                        }
                    } else if (car->sndFwd != -1) {
                        func_80079848_7A448(car->sndFwd);
                        car->sndFwd = -1;
                    }
                }
            }
        } else if (D_8010DB80_1D1F30_MagnetCarta == 2) {
            obj->trans.x += HuMathSin(obj->rot.y) * car->speed;
            obj->trans.z += func_800B7890_B8490(obj->rot.y) * car->speed;
        } else if (D_8010DB80_1D1F30_MagnetCarta == 5) {
            if (car->sndFwd != -1) {
                func_80079848_7A448(car->sndFwd);
                car->sndFwd = -1;
            }
        }
    } else if (D_8010DB80_1D1F30_MagnetCarta == 2) {
        if ((f32)p->timer * car->steer + obj->rot.y >= 360.0f) {
            w = (f32)p->timer * car->steer + obj->rot.y - 360.0f;
        } else {
            z = (f32)p->timer * car->steer;
            w = z + obj->rot.y;
            if (w < 0.0f) {
                w += 360.0f;
            }
        }
        obj->rot.y = w;
        if (p->attached == 1) {
            o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
            if ((f32)p->timer * car->steer + o->rot.y >= 360.0f) {
                w = (f32)p->timer * car->steer + o->rot.y - 360.0f;
            } else {
                z = (f32)p->timer * car->steer;
                w = z + o->rot.y;
                if (w < 0.0f) {
                    w += 360.0f;
                }
            }
            o->rot.y = w;
        }
        if (car->speed != 0.0f) {
            t = (f32)p->timer * 0.1f;
            car->speed = t * t * 4.0f + car->bounce - 14.0f;
            if (car->speed <= 0.0f) {
                car->speed = 0.0f;
                p->timer = 0;
            }
            obj->trans.x -= HuMathSin(car->dir) * car->speed;
            obj->trans.z -= func_800B7890_B8490(car->dir) * car->speed;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801057D4_1C9B84_MagnetCarta);
#endif

void func_80105E28_1CA1D8_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    Vec from;
    Vec to;
    Vec out;
    omObjData* o;
    s16 turn = 0;

    if (D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]].speed == 0.0f) {
        if (ContStkX[gPlayers[obj->work[0]].port] > 0.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y - 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y - 6.0f);
            }
            turn = 2;
        } else if (ContStkX[gPlayers[obj->work[0]].port] < 0.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y + 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 6.0f);
            }
            turn = 1;
        }
    } else {
        from.x = 0.0f;
        from.y = 0.0f;
        from.z = 0.0f;
        to.x = ContStkX[gPlayers[obj->work[0]].port];
        to.y = 0.0f;
        to.z = ContStkY[gPlayers[obj->work[0]].port];
        func_8010B0A8_1CF458_MagnetCarta(&from, &to, &out);
        if (out.z > 30.0f && out.z < 84.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y - 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y - 6.0f);
            }
            turn = 2;
        } else if (out.z > 276.0f && out.z < 330.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y + 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 6.0f);
            }
            turn = 1;
        } else if (out.z > 96.0f && out.z < 150.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y + 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 6.0f);
            }
            turn = 1;
        } else if (out.z > 210.0f && out.z < 264.0f) {
            obj->rot.y = MC_WRAP(obj->rot.y - 6.0f);
            if (p->attached == 1) {
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y - 6.0f);
            }
            turn = 2;
        }
    }
    if (turn != 0) {
        switch (p->target) {
        case 4:
            if (turn == 1) {
                if (p->attached == 1) {
                    obj->rot.y = MC_WRAP(obj->rot.y - 3.5f);
                    o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                    o->rot.y = MC_WRAP(o->rot.y - 3.5f);
                }
            } else if (p->attached == 1) {
                obj->rot.y = MC_WRAP(obj->rot.y + 3.5f);
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 3.5f);
            }
            break;
        case 5:
        case 6:
        case 7:
            if (turn == 1) {
                if (p->attached == 1) {
                    obj->rot.y = MC_WRAP(obj->rot.y - 2.5f);
                    o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                    o->rot.y = MC_WRAP(o->rot.y - 2.5f);
                }
            } else if (p->attached == 1) {
                obj->rot.y = MC_WRAP(obj->rot.y + 2.5f);
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 2.5f);
            }
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            if (turn == 1) {
                if (p->attached == 1) {
                    obj->rot.y = MC_WRAP(obj->rot.y - 1.0f);
                    o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                    o->rot.y = MC_WRAP(o->rot.y - 1.0f);
                }
            } else if (p->attached == 1) {
                obj->rot.y = MC_WRAP(obj->rot.y + 1.0f);
                o = D_8010BDD0_1D0180_MagnetCarta[p->target].obj;
                o->rot.y = MC_WRAP(o->rot.y + 1.0f);
            }
            break;
        }
    }
}

void func_80106BE0_1CAF90_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    MCCar* car = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    f32 x;
    f32 t;

    if (ContStkY[gPlayers[obj->work[0]].port] > 20) {
        car->speed = 12.0f;
        if (p->dust == 0) {
            t = HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            x = t + obj->trans.x;
            func_801039F0_1C7DA0_MagnetCarta(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f + obj->trans.z, 2);
            p->dust++;
        } else if (p->dust == 2) {
            p->dust = 0;
        } else {
            p->dust++;
        }
        if (car->sndFwd == -1) {
            if (car->sndBack != -1) {
                func_80079848_7A448(car->sndBack);
                car->sndBack = -1;
            }
            car->sndFwd = func_80079798_7A398(0x243, obj->work[0]);
        }
    } else if (ContStkY[gPlayers[obj->work[0]].port] < -20) {
        car->speed = -12.0f;
        if (p->dust == 0) {
            x = obj->trans.x - HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            func_801039F0_1C7DA0_MagnetCarta(obj->work[0], x, obj->trans.y, obj->trans.z - func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f, 2);
            p->dust++;
        } else if (p->dust == 2) {
            p->dust = 0;
        } else {
            p->dust++;
        }
        if (car->sndBack == -1) {
            if (car->sndFwd != -1) {
                func_80079848_7A448(car->sndFwd);
                car->sndFwd = -1;
            }
            car->sndBack = func_80079798_7A398(0x244, obj->work[0]);
        }
    } else {
        car->speed = 0.0f;
        p->dust = 0;
        if (car->sndFwd != -1) {
            func_80079848_7A448(car->sndFwd);
            car->sndFwd = -1;
        }
        if (car->sndBack != -1) {
            func_80079848_7A448(car->sndBack);
            car->sndBack = -1;
        }
    }
    obj->trans.y = 0.0f;
    if (p->attached == 1 && car->speed != obj->trans.y) {
        switch (p->target) {
        case 4:
            if (car->speed > 0.0f) {
                car->speed -= 7.0f;
                if (car->sndFwd != -1) {
                    func_800796F0_7A2F0(car->sndFwd, -600);
                }
            } else {
                car->speed += 7.0f;
                if (car->sndBack != -1) {
                    func_800796F0_7A2F0(car->sndBack, 0);
                }
            }
            break;
        case 5:
        case 6:
        case 7:
            if (car->speed > 0.0f) {
                car->speed -= 5.0f;
                if (car->sndFwd != -1) {
                    func_800796F0_7A2F0(car->sndFwd, -400);
                }
            } else {
                car->speed += 5.0f;
                if (car->sndFwd != -2) { /* sic: both fields */
                    func_800796F0_7A2F0(car->sndBack, 200);
                }
            }
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            if (car->speed > 0.0f) {
                car->speed -= 1.0f;
                if (car->sndFwd != -1) {
                    func_800796F0_7A2F0(car->sndFwd, -200);
                }
            } else {
                car->speed += 1.0f;
                if (car->sndBack != -1) {
                    func_800796F0_7A2F0(car->sndBack, 400);
                }
            }
            break;
        }
    } else if (car->speed > 0.0f) {
        if (car->sndFwd != -1) {
            func_800796F0_7A2F0(car->sndFwd, 0);
        }
    } else if (car->speed < 0.0f) {
        if (car->sndBack != -1) {
            func_800796F0_7A2F0(car->sndBack, 600);
        }
    }
}

void func_80107140_1CB4F0_MagnetCarta(MCObj* p) {
    Vec a;
    Vec b;
    Vec out;
    Vec best;
    MCObj* q;
    MCCar* car;
    omObjData* o;
    omObjData* t;
    f32 d;
    u8 k;
    s16 i;
    s16 goal;

    o = p->obj;
    car = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
    a.x = o->trans.x;
    a.y = 0.0f;
    a.z = o->trans.z;
    ContBtn[gPlayers[o->work[0]].port] = 0;
    ContBtnTrg[gPlayers[o->work[0]].port] = 0;
    goal = 14;
    if (p->unk_7E != 0 && p->timer == 0 && p->cpuWait == 0) {
        ContStkX[gPlayers[o->work[0]].port] = D_8010BD5C_1D010C_MagnetCarta[o->work[0]];
        ContStkY[gPlayers[o->work[0]].port] = D_8010BD58_1D0108_MagnetCarta[o->work[0]];
    } else {
        ContStkX[gPlayers[o->work[0]].port] = 0;
        ContStkY[gPlayers[o->work[0]].port] = 0;
        D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
        D_8010BD58_1D0108_MagnetCarta[o->work[0]] = 0;
    }
    if (p->timer != 0) {
        p->unk_7E = 0;
    } else if (p->cpuWait == 0) {
    if (p->attached == 0) {
        best.x = 5000.0f;
        for (i = 4; i < 14; i++) {
            q = &D_8010BDD0_1D0180_MagnetCarta[i];
            if (q->obj != NULL && q->state == 0 && q->attached == 0) {
                t = q->obj;
                b.x = t->trans.x;
                b.y = 0.0f;
                b.z = t->trans.z;
                func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                if (out.x < best.x) {
                    best.x = out.x;
                    best.z = out.z;
                    best.y = out.y;
                    goal = i;
                }
            }
        }
        if (goal >= 14) {
            for (i = 0; i < 4; i++) {
                q = &D_8010BDD0_1D0180_MagnetCarta[i];
                if (q->obj != NULL && q->obj->work[0] != o->work[0] && o->work[3] != q->obj->work[3] && q->attached == 1) {
                    t = q->obj;
                    b.x = t->trans.x;
                    b.y = 0.0f;
                    b.z = t->trans.z;
                    func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                    if (out.x < best.x) {
                        best.x = out.x;
                        best.z = out.z;
                        best.y = out.y;
                        goal = i;
                    }
                }
            }
        }
    } else {
        goal = 99;
    }
    if (p->hit == 1) {
        if (p->unk_7E == 0) {
        if (p->attached == 0) {
            ContStkY[gPlayers[o->work[0]].port] = 0;
            D_8010BD58_1D0108_MagnetCarta[o->work[0]] = 0;
            p->unk_7E = 20;
        }
        k = rand8() & 1;
        if (k == 0) {
            ContStkX[gPlayers[o->work[0]].port] = -70;
        } else if (k == 1) {
            ContStkX[gPlayers[o->work[0]].port] = 70;
        }
        D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
        p->unk_7E = rand8() % 3 * 12;
        } else {
            p->hit = 0;
            p->unk_7E--;
        }
    } else if (goal < 14) {
        if (p->unk_7E == 0) {
            ContStkY[gPlayers[o->work[0]].port] = 70;
            D_8010BD58_1D0108_MagnetCarta[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if (o->rot.y >= 90.0f && o->rot.y <= 270.0f) {
                if (MC_WRAP(o->rot.y - best.z) > 180.0f) {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                }
            } else if (MC_WRAP(o->rot.y - best.z) > 180.0f) {
                ContStkX[gPlayers[o->work[0]].port] = 70;
            } else {
                ContStkX[gPlayers[o->work[0]].port] = -70;
            }
            D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->unk_7E = 30;
        } else {
            p->unk_7E--;
        }
        d = o->rot.y - best.z;
        if (d < 15.0f) {
            if (d > -15.0f) {
                D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
                ContStkX[gPlayers[o->work[0]].port] = 0;
            }
        }
    } else if (goal == 99) {
        if (p->unk_7E == 0) {
            if (o->work[3] == 0) {
                if (o->rot.y > 100.0f && o->rot.y < 270.0f) {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                } else if (!(o->rot.y > 80.0f) && !(o->rot.y >= 270.0f)) {
                    do {
                    } while (0);
                    if (o->rot.y >= 80.0f && o->rot.y < 90.0f) {
                        ContStkX[gPlayers[o->work[0]].port] = 70;
                    } else {
                        ContStkX[gPlayers[o->work[0]].port] = -70;
                    }
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                }
                D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
                rand8();
                ContStkY[gPlayers[o->work[0]].port] = 70;
                D_8010BD58_1D0108_MagnetCarta[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
                p->unk_7E = 100;
            } else {
                if (o->rot.y >= 90.0f && o->rot.y < 260.0f) {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                } else if (!(o->rot.y < 90.0f) && !(o->rot.y > 280.0f)) {
                    do {
                    } while (0);
                    if (o->rot.y > 270.0f && o->rot.y <= 280.0f) {
                        ContStkX[gPlayers[o->work[0]].port] = -70;
                    } else {
                        ContStkX[gPlayers[o->work[0]].port] = 70;
                    }
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                }
                D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
                ContStkY[gPlayers[o->work[0]].port] = 70;
                D_8010BD58_1D0108_MagnetCarta[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
                p->unk_7E = 100;
            }
        } else {
            p->unk_7E--;
        }
        if (o->work[3] == 0) {
            if (o->trans.z > 0.0f) {
                if (o->rot.y > 100.0f && o->rot.y < 120.0f) {
                    D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
                    ContStkX[gPlayers[o->work[0]].port] = 0;
                }
            } else if (o->rot.y < 80.0f && o->rot.y > 60.0f) {
                D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
                ContStkX[gPlayers[o->work[0]].port] = 0;
            }
        } else if (o->trans.z < 0.0f) {
            if (o->rot.y > 280.0f && o->rot.y < 300.0f) {
                D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
                ContStkX[gPlayers[o->work[0]].port] = 0;
            }
        } else if (o->rot.y < 260.0f && o->rot.y > 240.0f) {
            D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = 0;
            ContStkX[gPlayers[o->work[0]].port] = 0;
        }
    } else if (p->attached == 0) {
        if (p->unk_7E == 0) {
            k = rand8() % 10;
            if (k < car->cpuRand) {
                ContStkY[gPlayers[o->work[0]].port] = -70;
            } else if (k > car->cpuRand >> 1 && k < car->cpuRand) {
                ContStkY[gPlayers[o->work[0]].port] = 0;
            } else {
                ContStkY[gPlayers[o->work[0]].port] = 70;
            }
            D_8010BD58_1D0108_MagnetCarta[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if ((rand8() & 1) == 0) {
                ContStkX[gPlayers[o->work[0]].port] = -70;
            } else {
                ContStkX[gPlayers[o->work[0]].port] = 70;
            }
            D_8010BD5C_1D010C_MagnetCarta[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->unk_7E = 30;
        } else {
            p->unk_7E--;
        }
    }
    } else {
        p->unk_7E = 0;
    }
}

void func_80108174_1CC524_MagnetCarta(omObjData* obj) {
    MCObj* p = &D_8010BDD0_1D0180_MagnetCarta[obj->work[0]];
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];

    switch (D_8010DB80_1D1F30_MagnetCarta) {
    case 2:
        if (*(s32*)&p->timer == 0) {
            if (gPlayers[obj->work[0]].flags & 1) {
                func_80107140_1CB4F0_MagnetCarta(p);
            }
            func_80106BE0_1CAF90_MagnetCarta(obj);
            func_80105E28_1CA1D8_MagnetCarta(obj);
        }
        break;
    case 3:
        if (c->sndFwd != -1) {
            func_80079848_7A448(c->sndFwd);
            c->sndFwd = -1;
        }
        if (c->sndBack != -1) {
            func_80079848_7A448(c->sndBack);
            c->sndBack = -1;
        }
        break;
    }
    func_801057D4_1C9B84_MagnetCarta(obj);
    if (p->timer != 0) {
        p->timer--;
    } else {
        p->timer = 0;
    }
    if (p->timer == 1 && (gPlayers[obj->work[0]].flags & 1)) {
        p->cpuWait = rand8() % 10 + c->cpuWait;
    }
    if (p->cpuWait != 0) {
        p->cpuWait--;
    } else {
        p->cpuWait = 0;
    }
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
}

void func_80108364_1CC714_MagnetCarta(omObjData* obj) {
    MCCar* c = &D_8010B7B0_1CFB60_MagnetCarta[obj->work[0]];
    MCStart* st;
    u8 r;

    do {
    } while (0);
    obj->model[0] = LoadFormFile(D_8010B550_1CF900_MagnetCarta[gPlayers[obj->work[0]].character] | 0x300000, 0x2B9);
    obj->model[2] = LoadFormFile(0x300002, 0x2B9);
    obj->model[3] = LoadFormFile(D_8010B57C_1CF92C_MagnetCarta[obj->work[3]] | 0x300000, 0x2B9);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
    if (obj->work[3] == 0) {
        r = rand8() & 1;
        if (D_8010BDCC_1D017C_MagnetCarta[r] == 0) {
            D_8010BDCC_1D017C_MagnetCarta[r] = 1;
            obj->trans.x = D_8010B580_1CF930_MagnetCarta[r].x;
            obj->trans.y = D_8010B580_1CF930_MagnetCarta[r].y;
            obj->trans.z = D_8010B580_1CF930_MagnetCarta[r].z;
            obj->rot.y = D_8010B580_1CF930_MagnetCarta[r].rot;
        } else {
            if (r == 0) {
                D_8010BDCC_1D017C_MagnetCarta[1] = 1;
                st = &D_8010B580_1CF930_MagnetCarta[1];
            } else {
                D_8010BDCC_1D017C_MagnetCarta[0] = 1;
                st = &D_8010B580_1CF930_MagnetCarta[0];
            }
            obj->trans.x = st->x;
            obj->trans.y = st->y;
            obj->trans.z = st->z;
            obj->rot.y = st->rot;
        }
    } else {
        r = rand8() & 1;
        if (D_8010DBBA_1D1F6A_MagnetCarta[r] == 0) {
            D_8010DBBA_1D1F6A_MagnetCarta[r] = 1;
            obj->trans.x = D_8010B590_1CF940_MagnetCarta[r].x;
            obj->trans.y = D_8010B590_1CF940_MagnetCarta[r].y;
            obj->trans.z = D_8010B590_1CF940_MagnetCarta[r].z;
            obj->rot.y = D_8010B590_1CF940_MagnetCarta[r].rot;
        } else {
            if (r == 0) {
                D_8010DBBA_1D1F6A_MagnetCarta[1] = 1;
                st = &D_8010B590_1CF940_MagnetCarta[1];
            } else {
                D_8010DBBA_1D1F6A_MagnetCarta[0] = 1;
                st = &D_8010B590_1CF940_MagnetCarta[0];
            }
            obj->trans.x = st->x;
            obj->trans.y = st->y;
            obj->trans.z = st->z;
            obj->rot.y = st->rot;
        }
    }
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[3], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[2], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    if (gPlayers[obj->work[0]].flags & 1) {
        switch (gPlayers[obj->work[0]].cpu_difficulty) {
        case 0:
            c->arc = 60.0f;
            c->cpuRand = 2;
            c->cpuWait = 20;
            break;
        case 1:
            c->arc = 90.0f;
            c->cpuRand = 4;
            c->cpuWait = 10;
            break;
        case 2:
            c->arc = 120.0f;
            c->cpuRand = 6;
            c->cpuWait = 0;
            break;
        default:
            c->arc = 150.0f;
            c->cpuRand = 7;
            c->cpuWait = 0;
            break;
        }
    }
    c->mass = 4.0f;
    obj->func_ptr = func_80108174_1CC524_MagnetCarta;
}

void func_80108888_1CCC38_MagnetCarta(void) {
    MCObj* p;
    omObjData* o;
    s16 n;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        o = omAddObj(100, 4, 0, -1, func_80108364_1CC714_MagnetCarta);
        switch (i) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n = 0;
            break;
        }
        o->work[0] = n;
        if (gPlayers[o->work[0]].group == 0) {
            if (D_8010DBA9_1D1F59_MagnetCarta < 2) {
                o->work[3] = 0;
                D_8010DBA9_1D1F59_MagnetCarta++;
            } else {
                o->work[3] = 1;
                D_8010DBC4_1D1F74_MagnetCarta++;
            }
        } else {
            if (D_8010DBC4_1D1F74_MagnetCarta < 2) {
                o->work[3] = 1;
                D_8010DBC4_1D1F74_MagnetCarta++;
            } else {
                o->work[3] = 0;
                D_8010DBA9_1D1F59_MagnetCarta++;
            }
        }
        p->obj = o;
        D_800FC87A_FD47A++;
    }
}

void func_80108A10_1CCDC0_MagnetCarta(void) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80108A34_1CCDE4_MagnetCarta(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_80108A10_1CCDC0_MagnetCarta;
    }
}

void func_80108A6C_1CCE1C_MagnetCarta(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80108A34_1CCDE4_MagnetCarta;
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
    }
}

// register allocation (masked 1, raw 84): o and car swapped (retail o s4, car s3), f22/f24 swapped, and one
// delay slot shifts j another way. Tried: car declared before o (same), car indexed through p->obj before
// o is set (masked 3), o = p->obj hoisted above the test (masked 68).
#ifdef NON_MATCHING
void func_80108AC4_1CCE74_MagnetCarta(void) {
    Vec a;
    Vec b;
    Vec out;
    MCObj* p;
    MCObj* q;
    omObjData* o;
    omObjData* t;
    MCCar* car;
    MCCar* oc;
    s16 k;
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            car = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
            for (j = 0; j < 4; j++) {
                car->hit[j] = 0;
                if (i != j) {
                    q = &D_8010BDD0_1D0180_MagnetCarta[j];
                    if (q->obj != NULL && q->state == 0) {
                        t = q->obj;
                        a.x = o->trans.x;
                        a.y = 0.0f;
                        a.z = o->trans.z;
                        b.x = t->trans.x;
                        b.y = 0.0f;
                        b.z = t->trans.z;
                        func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                        if (out.x < 127.5f) {
                            p->unk_86 = 2;
                            if (car->sndFwd != -1) {
                                func_80079848_7A448(car->sndFwd);
                                car->sndFwd = -1;
                            }
                            if (car->sndBack != -1) {
                                func_80079848_7A448(car->sndBack);
                                car->sndBack = -1;
                            }
                            PlaySound(0x245);
                            p->hit = 1;
                            car->hit[j] = 1;
                            if (p->timer == 0) {
                                p->timer = 20;
                            }
                        }
                    }
                }
            }
            for (j = 4; j < 14; j++) {
                car->hit[j] = 0;
                q = &D_8010BDD0_1D0180_MagnetCarta[j];
                if (q->obj != NULL && q->state == 0) {
                    t = q->obj;
                    oc = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                    a.x = o->trans.x;
                    a.y = 0.0f;
                    a.z = o->trans.z;
                    b.x = t->trans.x;
                    b.y = 0.0f;
                    b.z = t->trans.z;
                    func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                    if (out.x < 127.5f) {
                        if (p->attached == 0 && q->attached == 0 &&
                            (MC_WRAP(o->rot.y - out.z) < 20.0f || MC_WRAP(o->rot.y - out.z) > 340.0f)) {
                            p->attached = 1;
                            p->target = j;
                            q->attached = 1;
                            q->target = i;
                            oc->dir = o->rot.y;
                            if (car->sndFwd != -1) {
                                func_80079848_7A448(car->sndFwd);
                                car->sndFwd = -1;
                            }
                            if (car->sndBack != -1) {
                                func_80079848_7A448(car->sndBack);
                                car->sndBack = -1;
                            }
                            func_80079798_7A398(0x248, o->work[0]);
                            func_80079798_7A398(0x249, o->work[0]);
                            if (!(gPlayers[o->work[0]].flags & 1)) {
                                switch (t->work[0]) {
                                case 4:
                                    omVibrate(o->work[0], 2, 2, 20);
                                    break;
                                case 5:
                                case 6:
                                case 7:
                                case 8:
                                    omVibrate(o->work[0], 10, 0, 10);
                                    break;
                                case 9:
                                case 10:
                                case 11:
                                case 12:
                                case 13:
                                    omVibrate(o->work[0], 2, 3, 10);
                                    break;
                                }
                            }
                        } else if (p->attached == 1) {
                            if (p->target == j) {
                                continue;
                            }
                            if (q->attached != p->attached) {
                                goto touch;
                            }
                            goto stun;
                        } else {
                            if (q->attached == 1) {
                            stun:
                                car->hit[j] = 1;
                                if (p->timer == 0) {
                                    p->timer = 20;
                                    p->unk_86 = 2;
                                    if (car->sndFwd != -1) {
                                        func_80079848_7A448(car->sndFwd);
                                        car->sndFwd = -1;
                                    }
                                    if (car->sndBack != -1) {
                                        func_80079848_7A448(car->sndBack);
                                        car->sndBack = -1;
                                    }
                                    PlaySound(0x245);
                                }
                            } else {
                            touch:
                                car->hit[j] = 1;
                            }
                        }
                    }
                }
            }
            if (p->attached == 1) {
                for (j = 0; j < 4; j++) {
                    if (i != j) {
                        q = &D_8010BDD0_1D0180_MagnetCarta[j];
                        if (q->obj != NULL && q->state == 0) {
                            t = q->obj;
                            a.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                            a.y = 0.0f;
                            a.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                            b.x = t->trans.x;
                            b.y = 0.0f;
                            b.z = t->trans.z;
                            func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                            if (out.x < 127.5f && car->hit[j] == 0) {
                                p->hit = 1;
                                car->hit[j] = 2;
                                if (p->timer == 0) {
                                    p->unk_86 = 2;
                                    if (car->sndFwd != -1) {
                                        func_80079848_7A448(car->sndFwd);
                                        car->sndFwd = -1;
                                    }
                                    if (car->sndBack != -1) {
                                        func_80079848_7A448(car->sndBack);
                                        car->sndBack = -1;
                                    }
                                    PlaySound(0x245);
                                    p->timer = 20;
                                }
                            }
                        }
                    }
                }
                for (j = 4; j < 14; j++) {
                    if (j != p->target) {
                        q = &D_8010BDD0_1D0180_MagnetCarta[j];
                        if (q->obj != NULL && q->state == 0) {
                            t = q->obj;
                            a.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                            a.y = 0.0f;
                            a.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                            b.x = t->trans.x;
                            b.y = 0.0f;
                            b.z = t->trans.z;
                            func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                            if (out.x < 127.5f && car->hit[j] == 0) {
                                p->hit = 1;
                                car->hit[j] = 2;
                                if (q->attached == 1 && p->timer == 0) {
                                    p->unk_86 = 2;
                                    if (car->sndFwd != -1) {
                                        func_80079848_7A448(car->sndFwd);
                                        car->sndFwd = -1;
                                    }
                                    if (car->sndBack != -1) {
                                        func_80079848_7A448(car->sndBack);
                                        car->sndBack = -1;
                                    }
                                    PlaySound(0x245);
                                    p->timer = 20;
                                }
                            }
                        }
                    }
                }
                for (j = 14; j < 18; j++) {
                    car->hit[j] = 0;
                    k = j - 14;
                    a.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                    a.y = 0.0f;
                    a.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                    b.x = D_8010B55C_1CF90C_MagnetCarta[k].x;
                    b.y = 0.0f;
                    b.z = D_8010B55C_1CF90C_MagnetCarta[k].z;
                    func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                    if (out.x < 127.5f && car->hit[j] == 0) {
                        car->hit[j] = 2;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108AC4_1CCE74_MagnetCarta);
#endif

void func_80109464_1CD814_MagnetCarta(void) {
    MCObj* p;
    MCCar* c;
    omObjData* o;
    f32 x;
    f32 z;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            c = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
            c->wall = 0;
            if (o->trans.x * o->trans.x + o->trans.z * o->trans.z > 211600.0) {
                c->wall = 1;
                if (p->attached == 0) {
                    p->hit = 1;
                }
            }
            if (p->attached == 1) {
                x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                if (x * x + z * z > 211600.0) {
                    c->wall = 2;
                }
            }
        }
    }
}

// register allocation (masked 0, raw 86): the loop-invariant float constants get other callee-saved
// registers (retail 180 f22, 127.5 f24, 128.25 f26, 0 f28; here 127.5 f22, 180 f24, 0 f26, 128.25 f28),
// and the stored 1 sits in s6 not s7. Permuter (420) found nothing human-shaped.
#ifdef NON_MATCHING
void func_801095E4_1CD994_MagnetCarta(void) {
    Vec a;
    Vec b;
    Vec out;
    MCObj* p;
    MCObj* q;
    omObjData* o;
    omObjData* t;
    MCCar* car;
    f32 r;
    f32 x;
    f32 z;
    MCCar* oc;
    s16 k;
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            car = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
            car->prevDir = 0.0f;
            for (j = 0; j < 18; j++) {
                if (car->hit[j] != 0) {
                    break;
                }
            }
            if (j < 19) {
                for (j = 0; j < 14; j++) {
                    if (car->hit[j] == 1) {
                        q = &D_8010BDD0_1D0180_MagnetCarta[j];
                        t = q->obj;
                        oc = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                        car->prevSpeed = car->speed;
                        if (car->speed == 0.0f) {
                            car->speed = 10.0f;
                        } else if (oc->speed == 0.0f) {
                            car->speed = 10.0f;
                        }
                        car->bounce = func_800B1830_B2430(car->speed * car->speed);
                        a.x = o->trans.x;
                        a.y = 0.0f;
                        a.z = o->trans.z;
                        b.x = t->trans.x;
                        b.y = 0.0f;
                        b.z = t->trans.z;
                        func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                        car->dir = out.z;
                        if ((j < 4 || q->attached == 0 || q->target != i) && out.x < 127.5f) {
                            o->trans.x = HuMathSin(car->dir + 180.0f) * 128.25f + t->trans.x;
                            o->trans.z = func_800B7890_B8490(car->dir + 180.0f) * 128.25f + t->trans.z;
                            D_8010DBAB_1D1F5B_MagnetCarta = 1;
                        }
                        if (car->prevSpeed == 0.0f) {
                            if (p->attached == 0) {
                                r = MC_WRAP(out.z - o->rot.y);
                                if (((r >= 0.0f) & (r < 36.5f)) || ((r >= 90.0f) & (r < 145.5f)) ||
                                    ((r >= 180.0f) & (r < 214.5f)) || ((r >= 270.0f) & (r < 323.5f))) {
                                    car->steer = 1.0f;
                                } else {
                                    car->steer = -1.0f;
                                }
                            }
                        }
                    } else if (car->hit[j] == 2) {
                        q = &D_8010BDD0_1D0180_MagnetCarta[j];
                        t = q->obj;
                        oc = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                        car->prevSpeed = car->speed;
                        if (car->speed == 0.0f) {
                            car->speed = 5.0f;
                        } else if (oc->speed == 0.0f) {
                            car->speed = 10.0f;
                        }
                        car->bounce = func_800B1830_B2430(car->speed * car->speed);
                        a.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                        a.y = 0.0f;
                        a.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                        b.x = t->trans.x;
                        b.y = 0.0f;
                        b.z = t->trans.z;
                        func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                        car->dir = out.z;
                        if ((j < 4 || q->attached == 0 || q->target != i) && out.x < 127.5f) {
                            o->trans.x = HuMathSin(car->dir + 180.0f) * 128.25f + t->trans.x;
                            o->trans.z = func_800B7890_B8490(car->dir + 180.0f) * 128.25f + t->trans.z;
                            o->trans.x = HuMathSin(o->rot.y + 180.0f) * 127.5f + o->trans.x;
                            o->trans.z = func_800B7890_B8490(o->rot.y + 180.0f) * 127.5f + o->trans.z;
                            D_8010DBAB_1D1F5B_MagnetCarta = 1;
                        }
                        if (car->prevSpeed == 0.0f) {
                                                    r = MC_WRAP(out.z - o->rot.y);
                            if (((r >= 0.0f) & (r < 36.5f)) || ((r >= 90.0f) & (r < 145.5f)) ||
                                ((r >= 180.0f) & (r < 214.5f)) || ((r >= 270.0f) & (r < 323.5f))) {
                                car->steer = 0.5f;
                            } else {
                                car->steer = -0.5f;
                            }
                        }
                    }
                }
                if (car->wall == 1) {
                    car->bounce = func_800B1830_B2430(car->speed * car->speed);
                    car->dir = func_8010AEE0_1CF290_MagnetCarta(o->trans.x, o->trans.z);
                    o->trans.x = HuMathSin(car->dir) * 459.0;
                    o->trans.z = func_800B7890_B8490(car->dir) * 459.0;
                } else if (car->wall == 2) {
                    q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
                    t = q->obj;
                    car->bounce = func_800B1830_B2430(car->speed * car->speed);
                    car->dir = func_8010AEE0_1CF290_MagnetCarta(t->trans.x, t->trans.z);
                    if ((t->trans.z > 225.0f || t->trans.z < -225.0f) &&
                        t->trans.x * t->trans.x + t->trans.z * t->trans.z > 211600.0) {
                        t->trans.x = HuMathSin(car->dir) * 459.0;
                        t->trans.z = func_800B7890_B8490(car->dir) * 459.0;
                        o->trans.x = HuMathSin(o->rot.y + 180.0f) * 127.5f + t->trans.x;
                        o->trans.z = func_800B7890_B8490(o->rot.y + 180.0f) * 127.5f + t->trans.z;
                        D_8010DBAB_1D1F5B_MagnetCarta = 1;
                    } else {
                        x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                        z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                        if (x * x + z * z > 313600.0) {
                            p->attached = 0;
                            p->target = 0;
                            p->unk_7E = 0;
                        }
                    }
                }
                for (j = 14; j < 18; j++) {
                    if (car->hit[j] != 0) {
                        k = j - 14;
                        a.x = HuMathSin(o->rot.y) * 127.5f + o->trans.x;
                        a.y = 0.0f;
                        a.z = func_800B7890_B8490(o->rot.y) * 127.5f + o->trans.z;
                        b.x = D_8010B55C_1CF90C_MagnetCarta[k].x;
                        b.y = 0.0f;
                        b.z = D_8010B55C_1CF90C_MagnetCarta[k].z;
                        func_8010B0A8_1CF458_MagnetCarta(&a, &b, &out);
                        r = out.z;
                        car->dir = r;
                        if (out.x < 127.5f) {
                            o->trans.x = HuMathSin(r + 180.0f) * 128.25f + D_8010B55C_1CF90C_MagnetCarta[k].x;
                            o->trans.z = func_800B7890_B8490(car->dir + 180.0f) * 128.25f + D_8010B55C_1CF90C_MagnetCarta[k].z;
                            o->trans.x = HuMathSin(o->rot.y + 180.0f) * 127.5f + o->trans.x;
                            o->trans.z = func_800B7890_B8490(o->rot.y + 180.0f) * 127.5f + o->trans.z;
                            D_8010DBAB_1D1F5B_MagnetCarta = 1;
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801095E4_1CD994_MagnetCarta);
#endif

void func_8010A1AC_1CE55C_MagnetCarta(void) {
    MCObj* p;
    MCObj* q;
    MCCar* c;
    MCCar* d;
    omObjData* o;
    omObjData* t;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            func_80029714_2A314(o->model[0], o->trans.x, o->trans.y, o->trans.z);
            func_80029714_2A314(o->model[1], o->trans.x, 0.0f, o->trans.z);
            func_800297E8_2A3E8(o->model[1], 1.7f, o->scale.y, 1.7f);
            func_80029714_2A314(o->model[2], o->trans.x, o->trans.y, o->trans.z);
            func_8002979C_2A39C(o->model[2], o->rot.x, o->rot.y, o->rot.z);
            func_80029714_2A314(o->model[3], o->trans.x, o->trans.y, o->trans.z);
            func_8002979C_2A39C(o->model[3], o->rot.x, o->rot.y, o->rot.z);
        }
    }
    p = &D_8010BDD0_1D0180_MagnetCarta[4];
    if (p->obj != NULL && p->state == 0) {
        o = p->obj;
        c = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
        if (p->attached == 1) {
            q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
            if (q->obj != NULL && q->state == 0) {
                t = q->obj;
                d = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                o->trans.x = HuMathSin(t->rot.y) * 127.5f + t->trans.x;
                o->trans.z = func_800B7890_B8490(t->rot.y) * 127.5f + t->trans.z;
                if (q->attached == 0) {
                    c->bounce = 8.0f;
                    c->dir = t->rot.y;
                    p->timer = 20;
                    p->state = 1;
                    p->attached = 0;
                    p->target = 0;
                    p->size = o->scale.x * 0.05f;
                    if (d->sndFwd != -1) {
                        func_80079848_7A448(d->sndFwd);
                        d->sndFwd = -1;
                    }
                    if (d->sndBack != -1) {
                        func_80079848_7A448(d->sndBack);
                        d->sndBack = -1;
                    }
                    func_80079798_7A398(0x24B, t->work[0]);
                }
            }
        }
        func_80029714_2A314(o->model[0], o->trans.x, o->trans.y, o->trans.z);
        func_80029714_2A314(o->model[1], o->trans.x, 0.0f, o->trans.z);
        func_800297E8_2A3E8(o->model[1], 2.0f, o->scale.y, 2.0f);
    }
    for (i = 5; i < 9; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            c = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
            if (p->attached == 1) {
                q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
                if (q->obj != NULL && q->state == 0) {
                    t = q->obj;
                    d = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                    o->trans.x = HuMathSin(t->rot.y) * 127.5f + t->trans.x;
                    o->trans.z = func_800B7890_B8490(t->rot.y) * 127.5f + t->trans.z;
                    if (q->attached == 0) {
                        c->bounce = 8.0f;
                        c->dir = t->rot.y;
                        p->timer = 20;
                        p->state = 1;
                        p->attached = 0;
                        p->target = 0;
                        p->size = o->scale.x * 0.05f;
                        if (d->sndFwd != -1) {
                            func_80079848_7A448(d->sndFwd);
                            d->sndFwd = -1;
                        }
                        if (d->sndBack != -1) {
                            func_80079848_7A448(d->sndBack);
                            d->sndBack = -1;
                        }
                        func_80079798_7A398(0x24B, t->work[0]);
                    }
                }
            }
            func_80029714_2A314(o->model[0], o->trans.x, o->trans.y, o->trans.z);
            func_80029714_2A314(o->model[1], o->trans.x, 0.0f, o->trans.z);
            func_800297E8_2A3E8(o->model[1], 1.3f, o->scale.y, 1.3f);
        }
    }
    for (i = 9; i < 14; i++) {
        p = &D_8010BDD0_1D0180_MagnetCarta[i];
        if (p->obj != NULL && p->state == 0) {
            o = p->obj;
            c = &D_8010B7B0_1CFB60_MagnetCarta[o->work[0]];
            if (p->attached == 1) {
                q = &D_8010BDD0_1D0180_MagnetCarta[p->target];
                if (q->obj != NULL && q->state == 0) {
                    t = q->obj;
                    d = &D_8010B7B0_1CFB60_MagnetCarta[t->work[0]];
                    o->trans.x = HuMathSin(t->rot.y) * 127.5f + t->trans.x;
                    o->trans.z = func_800B7890_B8490(t->rot.y) * 127.5f + t->trans.z;
                    if (q->attached == 0) {
                        c->bounce = 8.0f;
                        c->dir = t->rot.y;
                        p->timer = 20;
                        p->state = 1;
                        p->attached = 0;
                        p->target = 0;
                        p->size = o->scale.x * 0.05f;
                        if (d->sndFwd != -1) {
                            func_80079848_7A448(d->sndFwd);
                            d->sndFwd = -1;
                        }
                        if (d->sndBack != -1) {
                            func_80079848_7A448(d->sndBack);
                            d->sndBack = -1;
                        }
                        func_80079798_7A398(0x1FE, t->work[0]);
                    }
                }
            }
            func_80029714_2A314(o->model[0], o->trans.x, o->trans.y, o->trans.z);
            func_80029714_2A314(o->model[1], o->trans.x, 0.0f, o->trans.z);
            func_800297E8_2A3E8(o->model[1], 1.3f, o->scale.y, 1.3f);
        }
    }
}

void func_8010A8F4_1CECA4_MagnetCarta(void) {
    D_8010DB80_1D1F30_MagnetCarta += D_8010DBB6_1D1F66_MagnetCarta;
    D_8010DBB6_1D1F66_MagnetCarta = 0;
}

void func_8010A91C_1CECCC_MagnetCarta(omObjData* obj) {
    s16 i;

    func_8010A8F4_1CECA4_MagnetCarta();
    if (D_8010DB80_1D1F30_MagnetCarta == 5) {
        func_8010422C_1C85DC_MagnetCarta();
        InitFadeOut(0, 20);
        obj->func_ptr = func_80108A34_1CCDE4_MagnetCarta;
    } else {
        if (D_8010DB80_1D1F30_MagnetCarta == 2) {
            D_8010DBAB_1D1F5B_MagnetCarta = 1;
            i = 0;
            while (D_8010DBAB_1D1F5B_MagnetCarta != 0) {
                D_8010DBAB_1D1F5B_MagnetCarta = 0;
                i++;
                if (i >= 11) {
                    break;
                }
                func_80109464_1CD814_MagnetCarta();
                func_80108AC4_1CCE74_MagnetCarta();
                func_801095E4_1CD994_MagnetCarta();
            }
        }
        func_8010A1AC_1CE55C_MagnetCarta();
    }
}

void func_8010A9E0_1CED90_MagnetCarta(void) {
    s16 i;
    s16 j;

    D_8010DBA9_1D1F59_MagnetCarta = 0;
    D_8010DBC4_1D1F74_MagnetCarta = 0;
    D_8010DBB7_1D1F67_MagnetCarta = 0;
    D_8010DBBC_1D1F6C_MagnetCarta = 0;
    D_8010DBA8_1D1F58_MagnetCarta = 0;
    D_8010BDCE_1D017E_MagnetCarta = 0;
    D_8010DB98_1D1F48_MagnetCarta = 0;
    for (i = 0; i < 18; i++) {
        D_8010B7B0_1CFB60_MagnetCarta[i].dir = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].prevDir = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].steer = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].speed = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].bounce = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].prevSpeed = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].arc = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].mass = 0.0f;
        D_8010B7B0_1CFB60_MagnetCarta[i].cpuRand = 0;
        D_8010B7B0_1CFB60_MagnetCarta[i].cpuWait = 0;
        D_8010B7B0_1CFB60_MagnetCarta[i].tick = 0;
        D_8010B7B0_1CFB60_MagnetCarta[i].sndFwd = -1;
        D_8010B7B0_1CFB60_MagnetCarta[i].sndBack = -1;
        for (j = 0; j < 19; j++) { /* 19: wall too */
            D_8010B7B0_1CFB60_MagnetCarta[i].hit[j] = 0;
        }
    }
}

void func_8010AB44_1CEEF4_MagnetCarta(omObjData* obj) {
    s16 i;

    func_8010B430_1CF7E0_MagnetCarta();
    func_8010B524_1CF8D4_MagnetCarta();
    func_8010A9E0_1CED90_MagnetCarta();
    D_8010DBB8_1D1F68_MagnetCarta = 0;
    D_8010DBB4_1D1F64_MagnetCarta = 10;
    D_8010DBB6_1D1F66_MagnetCarta = 0;
    for (i = 0; i < 2; i++) {
        D_8010BDCC_1D017C_MagnetCarta[i] = 0;
        D_8010DBBA_1D1F6A_MagnetCarta[i] = 0;
    }
    for (i = 0; i < 17; i++) {
        D_8010DB88_1D1F38_MagnetCarta[i] = 0;
    }
    func_80102AB0_1C6E60_MagnetCarta();
    func_80102EA0_1C7250_MagnetCarta();
    func_80103284_1C7634_MagnetCarta();
    func_80108888_1CCC38_MagnetCarta();
    func_801039B4_1C7D64_MagnetCarta();
    func_801035B4_1C7964_MagnetCarta();
    func_80104B70_1C8F20_MagnetCarta();
    func_80105124_1C94D4_MagnetCarta();
    func_80105730_1C9AE0_MagnetCarta();
    InitFadeIn(0, 16);
    obj->func_ptr = func_8010A91C_1CECCC_MagnetCarta;
    omAddObj(50, 0, 0, -1, func_8010281C_1C6BCC_MagnetCarta);
    D_8010DB80_1D1F30_MagnetCarta = 0;
    func_801041F0_1C85A0_MagnetCarta();
    omAddObj(600, 0, 0, -1, func_80104640_1C89F0_MagnetCarta);
}

__asm__(".section .rodata");
const char D_8010B770_1CFB20_MagnetCarta[] = "\202`\202a\202b";

void func_8010ACB4_1CF064_MagnetCarta(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(70);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0x40, 0x40, 0x60);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x40);
    func_80026E00_27A00(1, 0.0f, 0.0f, 100.0f);
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 21.176f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_8010AB44_1CEEF4_MagnetCarta);
    omAddObj(1000, 0, 0, -1, func_80108A6C_1CCE1C_MagnetCarta);
    func_8007273C_7333C((u8*)D_8010B770_1CFB20_MagnetCarta, 0);
    func_8007273C_7333C((u8*)D_8010B770_1CFB20_MagnetCarta, 1);
}

f32 func_8010AEE0_1CF290_MagnetCarta(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }

    return a;
}

f32 func_8010AF58_1CF308_MagnetCarta(f32 x) {
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

/* NON_MATCHING: scheduling (masked 3): retail loads 180.0f after the first near-zero compare; same in ovl_09/0A/20/26/36/37. */
#ifdef NON_MATCHING
void func_8010B0A8_1CF458_MagnetCarta(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_8010AF58_1CF308_MagnetCarta(delta.x / delta.z) * 57.29577951308232;
        } else if (delta.z == 0.0f) {
            if (delta.x >= 0.0f) {
                yaw = 90.0f;
            } else {
                yaw = 270.0f;
            }
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_8010AF58_1CF308_MagnetCarta(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010B0A8_1CF458_MagnetCarta);
#endif
