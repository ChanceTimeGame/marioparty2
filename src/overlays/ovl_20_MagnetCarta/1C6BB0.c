#include "ovl_20.h"

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801046C8_1C8A78_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80104970_1C8D20_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80104B70_1C8F20_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80104BB4_1C8F64_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80104E5C_1C920C_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80105124_1C94D4_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801051C8_1C9578_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80105470_1C9820_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80105730_1C9AE0_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801057D4_1C9B84_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80105E28_1CA1D8_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80106BE0_1CAF90_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80107140_1CB4F0_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108174_1CC524_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108364_1CC714_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108888_1CCC38_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108A10_1CCDC0_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108A34_1CCDE4_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108A6C_1CCE1C_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80108AC4_1CCE74_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_80109464_1CD814_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_801095E4_1CD994_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010A1AC_1CE55C_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010A8F4_1CECA4_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010A91C_1CECCC_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010A9E0_1CED90_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010AB44_1CEEF4_MagnetCarta);

__asm__(".section .rodata");
const char D_8010B770_1CFB20_MagnetCarta[] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010ACB4_1CF064_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010AEE0_1CF290_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010AF58_1CF308_MagnetCarta);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_MagnetCarta/1C6BB0", func_8010B0A8_1CF458_MagnetCarta);
