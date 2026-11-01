#include "common.h"
#include "ovl_09.h"

void func_80102800_11B910_BumperBalloonCars(void) {
    func_80107CCC_120DDC_BumperBalloonCars();
}

/* The camera, every frame. */
void func_8010281C_11B92C_BumperBalloonCars(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 2300.0f;
        D_80102770_103370[i].x = 325.06723f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 76.375f;
        D_801013B0_101FB0[i].z = 62.166f;
    }
}

void func_801028D0_11B9E0_BumperBalloonCars(omObjData* obj) {
    SprPosSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 160, 120);
}

/* The arena: the backdrop sprite and the ground object. */
void func_801028FC_11BA0C_BumperBalloonCars(omObjData* obj) {
    GroundWork* gw;

    D_80108658_121768_BumperBalloonCars[0] = func_8001A2F8_1AEF8(0x19000A);
    D_80108CD4_121DE4_BumperBalloonCars = SprCreate(1, 0);
    SprAttrReset(D_80108CD4_121DE4_BumperBalloonCars, 0, -1);
    SprScaleSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 1.0f, 1.0f);
    SprAnimSet(D_80108CD4_121DE4_BumperBalloonCars, 0, D_80108658_121768_BumperBalloonCars[0], 0);
    SprBankSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 0);
    SprAttrSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 0x5000);
    SprPosSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 160, 120);
    func_8008225C_82E5C(D_80108CD4_121DE4_BumperBalloonCars, 0, 0);
    SprPrioSet(D_80108CD4_121DE4_BumperBalloonCars, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_801028D0_11B9E0_BumperBalloonCars;
}

void func_80102AB4_11BBC4_BumperBalloonCars(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_801086E0_1217F0_BumperBalloonCars[10].obj = omAddObj(10, 2, 0, -1, func_801028FC_11BA0C_BumperBalloonCars);
}

/* Draws the 320x72 4-bit banner, in rows of 8 pixels. */
void func_80102AFC_11BC0C_BumperBalloonCars(Gfx** gfxp) {
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
    gDPLoadTLUT_pal16(gfx++, 0, D_801086C4_1217D4_BumperBalloonCars->unk0C);
    for (y = 0; y < 72; y += 8) {
        gDPLoadTextureTile_4b(gfx++, D_801086C4_1217D4_BumperBalloonCars->unk08, G_IM_FMT_CI, 320, 72, 0, y, 319,
                              y + 7, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 320 << 2, 8 << 2);
        gSPTextureRectangle(gfx++, 0 << 2, (y + 168) << 2, 320 << 2, (y + 176) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102E28_11BF38_BumperBalloonCars(void) {
}

void func_80102E30_11BF40_BumperBalloonCars(omObjData* obj) {
    s32 mdl;

    D_8010865E_12176E_BumperBalloonCars = func_8001A2F8_1AEF8(0x19000B);
    D_801086C4_1217D4_BumperBalloonCars = SprAnimGet(D_8010865E_12176E_BumperBalloonCars);
    obj->func_ptr = func_80102E28_11BF38_BumperBalloonCars;
    mdl = func_8002838C_28F8C(0, func_80102AFC_11BC0C_BumperBalloonCars, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_801086CC_1217DC_BumperBalloonCars = mdl;
}

void func_80102EB4_11BFC4_BumperBalloonCars(void) {
    D_801086E0_1217F0_BumperBalloonCars[15].obj = omAddObj(400, 0, 0, -1, func_80102E30_11BF40_BumperBalloonCars);
}

/* The dust puffs. */
void func_80102EF0_11C000_BumperBalloonCars(omObjData* obj) {
    BBCFxWork* w;
    BBCFx* fx;
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

void func_80103024_11C134_BumperBalloonCars(omObjData* obj) {
    BBCFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80027154_27D54(sizeof(BBCFxWork), 0x7918);
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
    obj->func_ptr = func_80102EF0_11C000_BumperBalloonCars;
}

void func_80103144_11C254_BumperBalloonCars(void) {
    D_8010A59C_1236AC_BumperBalloonCars = omAddObj(600, 0, 0, -1, func_80103024_11C134_BumperBalloonCars);
}

void func_80103180_11C290_BumperBalloonCars(s16 player, f32 x, f32 y, f32 z, u16 type) {
    BBCFxWork* w;
    BBCFx* fx;
    u16 m;
    s16 i;

    w = D_8010A59C_1236AC_BumperBalloonCars->unk_50;
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
const char D_80108570_121680_BumperBalloonCars[] = "signl_3x_DEF";

__asm__(".section .rodata");
const char D_80108580_121690_BumperBalloonCars[] = "signl_2x_DEF";

__asm__(".section .rodata");
const char D_80108590_1216A0_BumperBalloonCars[] = "signl_1x_DEF";

/* The signal comes down, blinks and goes back up. */
void func_80103300_11C410_BumperBalloonCars(omObjData* obj) {
    BBCObj* sig = &D_801086E0_1217F0_BumperBalloonCars[5];
    s32 k;
    s16 i;

    switch (D_8010A588_123698_BumperBalloonCars) {
    case 0:
        PlaySound(0x4A3);
        obj->trans.y -= 6.0f;
        sig->size += 0.02;
        if (obj->trans.y <= 360.0f) {
            obj->trans.y = 360.0f;
            D_8010A588_123698_BumperBalloonCars = 1;
        }
        func_800297E8_2A3E8(obj->model[1], sig->size, 0.0f, sig->size);
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        break;
    case 1:
        obj->trans.y += (f32)sig->lift * 0.1f;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], 1.5f, 0.0f, 1.5f);
        func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
        if (sig->out == 0) {
            if (++sig->lift > 10) {
                sig->out ^= 1;
            }
        } else {
            if (--sig->lift < -10) {
                sig->out ^= 1;
            }
        }
        if (sig->stun == 0) {
            for (i = 0; i < 3; i++) {
                func_8003E4F4_3F0F4(D_801086BC_1217CC_BumperBalloonCars[i], 1, 0);
            }
        } else {
            k = sig->stun;
            if (k == 30) {
                goto beep;
            }
            if (k == 60) {
            beep:
                PlaySound(0x2D9);
            } else if (k == 90) {
                D_80108654_121764_BumperBalloonCars = 1;
                PlaySound(0x2DA);
                PlayMusic(0x1C);
            }
        }
        sig->stun++;
        if (D_801086D2_1217E2_BumperBalloonCars == 2) {
            D_8010A588_123698_BumperBalloonCars = 3;
            sig->stun = 0;
        }
        break;
    case 2:
        sig->stun++;
        if (sig->stun >= 10) {
            D_8010A588_123698_BumperBalloonCars = 3;
        }
        break;
    case 3:
        obj->trans.y += 15.0f;
        sig->size -= 0.05f;
        if (sig->size <= 0.0f) {
            sig->size = 0.0f;
            obj->trans.y = 900.0f;
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], sig->size, 0.0f, sig->size);
        break;
    }
}

void func_801036AC_11C7BC_BumperBalloonCars(omObjData* obj) {
    s16 i;

    obj->model[0] = LoadFormFile(0x190006, 0x2A9);
    for (i = 0; i < 3; i++) {
        D_8010A58C_12369C_BumperBalloonCars[i] = DataRead(D_80108558_121668_BumperBalloonCars[i] | 0x190000);
        D_801086BC_1217CC_BumperBalloonCars[i] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_8010A58C_12369C_BumperBalloonCars[i], 0, D_80108560_121670_BumperBalloonCars[i]);
        func_8003E4F4_3F0F4(D_801086BC_1217CC_BumperBalloonCars[i], 1, 1);
        HuMemMemoryFreePerm(D_8010A58C_12369C_BumperBalloonCars[i]);
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
    D_801086E0_1217F0_BumperBalloonCars[5].size = 0.7f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    D_8010A588_123698_BumperBalloonCars = 0;
    obj->func_ptr = func_80103300_11C410_BumperBalloonCars;
}

void func_80103968_11CA78_BumperBalloonCars(void) {
    D_801086E0_1217F0_BumperBalloonCars[5].obj = omAddObj(600, 2, 1, -1, func_801036AC_11C7BC_BumperBalloonCars);
}

void func_801039A4_11CAB4_BumperBalloonCars(omObjData* obj) {
    if (D_80108652_121762_BumperBalloonCars > 0) {
        if (--D_80108652_121762_BumperBalloonCars == 0) {
            D_80108652_121762_BumperBalloonCars = 0;
            D_80108654_121764_BumperBalloonCars = 1;
        } else if (D_80108652_121762_BumperBalloonCars == 10) {
            func_80079614_7A214(40);
        }
    }
}

void func_80103A10_11CB20_BumperBalloonCars(omObjData* obj) {
    if (D_80108652_121762_BumperBalloonCars > 0) {
        if (--D_80108652_121762_BumperBalloonCars == 165) {
            func_8006D518_6E118();
        }
    }
    if (func_80069538_6A138() == 0) {
        D_80108654_121764_BumperBalloonCars = 1;
        obj->func_ptr = func_801039A4_11CAB4_BumperBalloonCars;
        if (D_8010A58A_12369A_BumperBalloonCars != 0) {
            if (D_8010A58A_12369A_BumperBalloonCars >= 3) {
                PlayMusic(0x51);
                D_80108652_121762_BumperBalloonCars = 120;
                return;
            }
        }
        PlayMusic(0x52);
        D_80108652_121762_BumperBalloonCars = 168;
    }
}

/* Coins: the last car standing gets 3; the placings of the rest go by when they popped. */
void func_80103AC8_11CBD8_BumperBalloonCars(void) {
    BBCObj* p;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        if (p->obj != NULL) {
            o = p->obj;
            if (o->work[3] == 0) {
                if (D_8010A58A_12369A_BumperBalloonCars == 0) {
                    gPlayers[o->work[0]].coins_mg_bonus = 3;
                } else {
                    gPlayers[o->work[0]].coins_mg_bonus = 0;
                }
            } else {
                gPlayers[o->work[0]].coins_mg_bonus = o->work[3] - 4 + D_8010A58A_12369A_BumperBalloonCars;
            }
        }
    }
}

/* The race: 30 s (0x385 / 30), or until three are out. */
void func_80103BDC_11CCEC_BumperBalloonCars(omObjData* obj) {
    BBCObj* p;
    s16 i;

    D_8010A58A_12369A_BumperBalloonCars = 0;
    for (i = 0; i < 4; i++) {
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        if (p->obj != NULL && p->out != 0) {
            D_8010A58A_12369A_BumperBalloonCars++;
        }
    }
    if (D_8010A58A_12369A_BumperBalloonCars >= 3) {
        D_80108654_121764_BumperBalloonCars = 1;
        func_8006D518_6E118();
        func_800691FC_69DFC(3);
        func_80103AC8_11CBD8_BumperBalloonCars();
        obj->func_ptr = func_80103A10_11CB20_BumperBalloonCars;
        D_80108652_121762_BumperBalloonCars = 180;
        func_800794A8_7A0A8(40);
    } else if (D_80108652_121762_BumperBalloonCars > 0) {
        D_80108652_121762_BumperBalloonCars--;
        func_8006D4D0_6E0D0((D_80108652_121762_BumperBalloonCars + 29) / 30);
    } else {
        func_80103AC8_11CBD8_BumperBalloonCars();
        obj->func_ptr = func_80103A10_11CB20_BumperBalloonCars;
        D_80108654_121764_BumperBalloonCars = 1;
        func_8006D4D0_6E0D0(0);
        D_80108652_121762_BumperBalloonCars = 180;
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
    }
}

void func_80103D64_11CE74_BumperBalloonCars(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    D_80108652_121762_BumperBalloonCars = 901;
    obj->func_ptr = func_80103BDC_11CCEC_BumperBalloonCars;
}

void func_80103DB0_11CEC0_BumperBalloonCars(omObjData* obj) {
    if (D_801086D2_1217E2_BumperBalloonCars == 1) {
        if (D_80108652_121762_BumperBalloonCars == 0) {
            func_800691FC_69DFC(0);
            D_80108652_121762_BumperBalloonCars++;
        }
        if (func_80069538_6A138() == 0) {
            D_80108654_121764_BumperBalloonCars = 1;
            D_80108652_121762_BumperBalloonCars = 0;
            obj->func_ptr = func_80103D64_11CE74_BumperBalloonCars;
        }
    }
}

void func_80103E38_11CF48_BumperBalloonCars(omObjData* obj) {
    BBCFxWork* w;
    BBCFx* fx;
    u16 m;
    s16 i;

    w = obj->unk_50;
    for (i = 0; i < 4; i++) {
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

void func_80103F6C_11D07C_BumperBalloonCars(omObjData* obj) {
    BBCFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80027154_27D54(sizeof(BBCFxWork), 0x7918);
    data = DataRead(0x190013);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 4; i++) {
        w->fx[i].model = m = func_80020EBC_21ABC((void*)-1, 0x284, 8);
        func_80021250_21E50(m, 0xFF, 0xFF, 0xFF);
        D_800F86D8_F92D8[m].unk02 = tex;
        func_80021160_21D60(m, 4, 4);
        w->state[i] = 0;
    }
    obj->func_ptr = func_80103E38_11CF48_BumperBalloonCars;
}

void func_8010408C_11D19C_BumperBalloonCars(void) {
    D_8010A598_1236A8_BumperBalloonCars = omAddObj(600, 0, 0, -1, func_80103F6C_11D07C_BumperBalloonCars);
}

/* Retail takes the slots of D_8010A59C_1236AC_BumperBalloonCars, the 20-slot pool, though it scans only four of them. */
void func_801040C8_11D1D8_BumperBalloonCars(s16 player, f32 x, f32 y, f32 z, u16 type) {
    BBCFxWork* w;
    BBCFx* fx;
    u16 m;
    s16 i;

    w = D_8010A59C_1236AC_BumperBalloonCars->unk_50;
    for (i = 0; i < 4; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i != 4) {
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
        func_800297E8_2A3E8(m, 3.0f, 3.0f, 3.0f);
        func_80029EDC_2AADC(m, 1);
        PlaySound(0x14F);
    }
}

/* A car's motion. */
void func_80104244_11D354_BumperBalloonCars(omObjData* obj) {
    BBCObj* p = &D_801086E0_1217F0_BumperBalloonCars[obj->work[0]];
    BBCCar* car = &D_8010A490_1235A0_BumperBalloonCars[obj->work[0]];
    f64 b;
    f64 s;
    f32 x;
    f32 a;
    f32 a2;
    f32 z;
    f32 w;
    f32 g;
    f32 g2;
    f32 t;
    s16 dy;

    if (p->out == 0) {
        if (p->stun == 0) {
            car->steer = 0.0f;
            if (D_801086D2_1217E2_BumperBalloonCars >= 4) {
                obj->rot.y = BBC_WRAP(obj->rot.y - 15.0f);
                if (p->smoke == 0) {
                    a = HuMathSin(obj->rot.y + 180.0f) * 75.0f;
                    x = a + obj->trans.x;
                    func_80103180_11C290_BumperBalloonCars(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f + obj->trans.z, 2);
                    p->smoke++;
                } else if (p->smoke == 2) {
                    p->smoke = 0;
                } else {
                    p->smoke++;
                }
                car->tick++;
                if (D_801086D2_1217E2_BumperBalloonCars != 5) {
                    if (D_8010A58A_12369A_BumperBalloonCars < 3) {
                        if (D_80108652_121762_BumperBalloonCars == 0xA7) {
                            car->sndFwd = func_80079798_7A398(0x155, obj->work[0]);
                        }
                    } else if (D_80108652_121762_BumperBalloonCars == 0x77) {
                        car->sndFwd = func_80079798_7A398(0x155, obj->work[0]);
                    }
                } else if (car->sndFwd != -1) {
                    func_80079848_7A448(car->sndFwd);
                    car->sndFwd = -1;
                }
            } else if (D_801086D2_1217E2_BumperBalloonCars == 2) {
                obj->trans.x += HuMathSin(obj->rot.y) * car->speed;
                obj->trans.z += func_800B7890_B8490(obj->rot.y) * car->speed;
            }
        } else {
            if ((f32)p->stun * car->steer + obj->rot.y >= 360.0f) {
                w = (f32)p->stun * car->steer + obj->rot.y - 360.0f;
            } else {
                z = (f32)p->stun * car->steer;
                w = z + obj->rot.y;
                if (w < 0.0f) {
                    w += 360.0f;
                }
            }
            obj->rot.y = w;
            if (car->speed != 0.0f) {
                b = car->bounce;
                s = (f32)p->stun * 0.1;
                car->speed = (b + s * s * 4.0) - 18.0;
                if (car->speed <= 0.0f) {
                    car->speed = 0.0f;
                    p->stun = 0;
                }
                obj->trans.x -= HuMathSin(car->dir) * car->speed;
                obj->trans.z -= func_800B7890_B8490(car->dir) * car->speed;
                dy = p->stun - 17;
                if (car->bounce > 14.0f || car->bounce < -14.0f) {
                    if (dy < 0) {
                        g = (f32)dy * 0.6f;
                        obj->trans.y -= g * car->bounce * g;
                    } else {
                        g2 = (f32)dy * 0.45f;
                        obj->trans.y += g2 * car->bounce * g2;
                    }
                    if (obj->trans.y < 0.0f) {
                        obj->trans.y = 0.0f;
                    }
                } else {
                    obj->trans.y = 0.0f;
                }
            }
        }
    } else if (car->hits >= 3) {
        if (p->gone == 0) {
            if (car->tick == 0) {
                if (car->sndFwd != -1) {
                    func_80079848_7A448(car->sndFwd);
                    car->sndFwd = -1;
                }
                if (car->sndBack != -1) {
                    func_80079848_7A448(car->sndBack);
                    car->sndBack = -1;
                }
                func_800797DC_7A3DC(0x111, obj->work[0]);
                func_80079798_7A398(0x154, obj->work[0]);
                car->tick++;
            } else if (car->tick < 100) {
                car->tick++;
            }
            obj->rot.x = BBC_WRAP(obj->rot.x + 30.0f);
            obj->rot.y = BBC_WRAP(obj->rot.y + 30.0f);
            obj->trans.x += HuMathSin(car->dir) * 30.0f;
            t = (f32)p->lift;
            t += t;
            obj->trans.y += func_800B1830_B2430(t * t);
            obj->trans.z += func_800B7890_B8490(car->dir) * 30.0f;
            p->lift--;
            if (p->smoke == 0) {
                a2 = HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
                x = a2 + obj->trans.x;
                func_80103180_11C290_BumperBalloonCars(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f + obj->trans.z, 2);
                p->smoke++;
            } else if (p->smoke == 2) {
                p->smoke = 0;
            } else {
                p->smoke++;
            }
        }
        if (obj->trans.y >= 900.0f) {
            p->gone = 1;
            obj->trans.y = 900.0f;
        }
    }
}

/* Steering. With speed on, the stick steers like a tank: forward and back pick which side. */
void func_80104A14_11DB24_BumperBalloonCars(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;

    if (D_8010A490_1235A0_BumperBalloonCars[obj->work[0]].speed == 0.0f) {
        if ((f32)ContStkX[gPlayers[obj->work[0]].port] > 0.0f) {
            obj->rot.y -= 7.0f;
        } else if ((f32)ContStkX[gPlayers[obj->work[0]].port] < 0.0f) {
            obj->rot.y += 7.0f;
        }
    } else {
        from.x = 0.0f;
        from.y = 0.0f;
        from.z = 0.0f;
        to.x = ContStkX[gPlayers[obj->work[0]].port];
        to.y = 0.0f;
        to.z = ContStkY[gPlayers[obj->work[0]].port];
        func_80108084_121194_BumperBalloonCars(&from, &to, &out);
        if (out.z > 30.0f && out.z < 84.0f) {
            obj->rot.y -= 7.0f;
        } else if (out.z > 276.0f && out.z < 330.0f) {
            obj->rot.y += 7.0f;
        } else if (out.z > 96.0f && out.z < 150.0f) {
            obj->rot.y += 7.0f;
        } else if (out.z > 210.0f && out.z < 264.0f) {
            obj->rot.y -= 7.0f;
        }
    }
    if (obj->rot.y > 360.0f) {
        obj->rot.y -= 360.0f;
    } else if (obj->rot.y < 0.0f) {
        obj->rot.y += 360.0f;
    }
}

/* Speed from the stick's y, with dust and the engine sounds. */
void func_80104D40_11DE50_BumperBalloonCars(omObjData* obj) {
    BBCObj* p = &D_801086E0_1217F0_BumperBalloonCars[obj->work[0]];
    BBCCar* car = &D_8010A490_1235A0_BumperBalloonCars[obj->work[0]];
    f32 x;
    f32 t;

    if (ContStkY[gPlayers[obj->work[0]].port] > 20) {
        car->speed = 18.0f;
        if (p->dust == 0) {
            t = HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            x = t + obj->trans.x;
            func_80103180_11C290_BumperBalloonCars(obj->work[0], x, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f + obj->trans.z, 2);
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
            car->sndFwd = func_80079798_7A398(0x152, obj->work[0]);
        }
    } else if (ContStkY[gPlayers[obj->work[0]].port] < -20) {
        car->speed = -18.0f;
        if (p->dust == 0) {
            x = obj->trans.x - HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            func_80103180_11C290_BumperBalloonCars(obj->work[0], x, obj->trans.y, obj->trans.z - func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f, 2);
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
            car->sndBack = func_80079798_7A398(0x150, obj->work[0]);
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
}

/* The COM's stick. */
void func_80105090_11E1A0_BumperBalloonCars(BBCObj* p) {
    omObjData* o = p->obj;
    BBCCar* car;
    BBCObj* q;
    omObjData* t;
    Vec from;
    Vec to;
    Vec res;
    Vec front;
    Vec side;
    s16 i;
    s16 s4;
    s16 s5;
    u8 r;

    s5 = 5;
    ContBtn[gPlayers[o->work[0]].port] = 0;
    ContBtnTrg[gPlayers[o->work[0]].port] = 0;
    s4 = 5;
    if (p->cpuHold != 0 && p->stun == 0 && p->cpuWait == 0) {
        ContStkX[gPlayers[o->work[0]].port] = D_80108634_121744_BumperBalloonCars[o->work[0]];
        ContStkY[gPlayers[o->work[0]].port] = D_80108630_121740_BumperBalloonCars[o->work[0]];
    } else {
        ContStkX[gPlayers[o->work[0]].port] = 0;
        ContStkY[gPlayers[o->work[0]].port] = 0;
        D_80108634_121744_BumperBalloonCars[o->work[0]] = 0;
        D_80108630_121740_BumperBalloonCars[o->work[0]] = 0;
    }
    if (p->stun != 0) {
        goto end;
    }
    if (p->cpuWait != 0) {
        goto end;
    }
    car = &D_8010A490_1235A0_BumperBalloonCars[o->work[0]];
    front.x = 5000.0f;
    side.x = 5000.0f;
    from.x = o->trans.x;
    from.y = 0.0f;
    from.z = o->trans.z;
    for (i = 0; i < 4; i++) {
        q = &D_801086E0_1217F0_BumperBalloonCars[i];
        t = q->obj;
        if (t != NULL && t->work[0] != o->work[0] && q->out == 0) {
            to.x = t->trans.x;
            to.y = 0.0f;
            to.z = t->trans.z;
            func_80108084_121194_BumperBalloonCars(&from, &to, &res);
            if (res.z < BBC_WRAP(o->rot.y + car->arc) && BBC_WRAP(o->rot.y - car->arc) < res.z) {
                if (res.x < front.x) {
                    front.x = res.x;
                    front.z = res.z;
                    front.y = res.y;
                    s4 = i;
                }
            } else if (res.x < side.x) {
                side.x = res.x;
                side.z = res.z;
                side.y = res.y;
                s5 = i;
            }
        }
    }
    if (D_801086D0_1217E0_BumperBalloonCars > 0 || p->cpuHit == 1) {
        if (p->cpuHold == 0) {
            r = rand8() % 10;
            if (r < car->cpuRand >> 1) {
                ContStkY[gPlayers[o->work[0]].port] = -70;
            } else {
                ContStkY[gPlayers[o->work[0]].port] = 70;
            }
            D_80108630_121740_BumperBalloonCars[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if (!(rand8() & 1)) {
                ContStkX[gPlayers[o->work[0]].port] = -70;
            } else {
                ContStkX[gPlayers[o->work[0]].port] = 70;
            }
            D_80108634_121744_BumperBalloonCars[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->cpuHold = 10;
        } else {
            p->cpuHold--;
        }
        p->cpuHit = 0;
        return;
    }
    if (s4 != 5) {
        if (p->cpuHold == 0) {
            ContStkY[gPlayers[o->work[0]].port] = 70;
            D_80108630_121740_BumperBalloonCars[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if (o->rot.y >= 90.0f && o->rot.y <= 270.0f) {
                if (!(BBC_WRAP(o->rot.y - res.z) > 180.0f)) {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                }
            } else {
                if (BBC_WRAP(o->rot.y - res.z) > 180.0f) {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                }
            }
            D_80108634_121744_BumperBalloonCars[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->cpuHold = 30;
        } else {
            p->cpuHold--;
        }
        if (o->rot.y - res.z < 15.0f && o->rot.y - res.z > -15.0f) {
            D_80108634_121744_BumperBalloonCars[o->work[0]] = 0;
            ContStkX[gPlayers[o->work[0]].port] = 0;
        }
    } else if (s5 != 5) {
        if (p->cpuHold == 0) {
            r = rand8() % 10;
            if (r < car->cpuRand >> 1) {
                ContStkY[gPlayers[o->work[0]].port] = -70;
            } else if (car->cpuRand >> 1 < r && r < car->cpuRand) {
                ContStkY[gPlayers[o->work[0]].port] = 0;
            } else {
                ContStkY[gPlayers[o->work[0]].port] = 70;
            }
            D_80108630_121740_BumperBalloonCars[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if (o->rot.y >= 90.0f && o->rot.y <= 270.0f) {
                if (!(BBC_WRAP(o->rot.y - res.z) > 180.0f)) {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                }
            } else {
                if (BBC_WRAP(o->rot.y - res.z) > 180.0f) {
                    ContStkX[gPlayers[o->work[0]].port] = 70;
                } else {
                    ContStkX[gPlayers[o->work[0]].port] = -70;
                }
            }
            D_80108634_121744_BumperBalloonCars[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->cpuHold = 30;
        } else {
            p->cpuHold--;
        }
        if (o->rot.y - res.z < 15.0f && o->rot.y - res.z > -15.0f) {
            D_80108634_121744_BumperBalloonCars[o->work[0]] = 0;
            ContStkX[gPlayers[o->work[0]].port] = 0;
        }
    } else {
        if (p->cpuHold == 0) {
            r = rand8() % 10;
            if (r < car->cpuRand) {
                ContStkY[gPlayers[o->work[0]].port] = -70;
            } else if (car->cpuRand >> 1 < r && r < car->cpuRand) {
                ContStkY[gPlayers[o->work[0]].port] = 0;
            } else {
                ContStkY[gPlayers[o->work[0]].port] = 70;
            }
            D_80108630_121740_BumperBalloonCars[o->work[0]] = ContStkY[gPlayers[o->work[0]].port];
            if (!(rand8() & 1)) {
                ContStkX[gPlayers[o->work[0]].port] = -70;
            } else {
                ContStkX[gPlayers[o->work[0]].port] = 70;
            }
            D_80108634_121744_BumperBalloonCars[o->work[0]] = ContStkX[gPlayers[o->work[0]].port];
            p->cpuHold = 30;
        } else {
            p->cpuHold--;
        }
        return;
    }
    return;
end:
    p->cpuHold = 0;
}

/* A car, every frame. */
void func_80106004_11F114_BumperBalloonCars(omObjData* obj) {
    BBCObj* p = &D_801086E0_1217F0_BumperBalloonCars[obj->work[0]];
    BBCCar* car = &D_8010A490_1235A0_BumperBalloonCars[obj->work[0]];
    f32 s;
    f32 x;
    f32 y;
    f32 b1;
    f32 b2;
    u16 h;

    switch (D_801086D2_1217E2_BumperBalloonCars) {
    case 2:
        if (*(s32*)&p->stun == 0) {
            if (gPlayers[obj->work[0]].flags & 1) {
                func_80105090_11E1A0_BumperBalloonCars(p);
            }
            func_80104D40_11DE50_BumperBalloonCars(obj);
            func_80104A14_11DB24_BumperBalloonCars(obj);
            break;
        }
    case 3:
        if (car->sndFwd != -1) {
            func_80079848_7A448(car->sndFwd);
            car->sndFwd = -1;
        }
        if (car->sndBack != -1) {
            func_80079848_7A448(car->sndBack);
            car->sndBack = -1;
        }
        break;
    }
    func_80104244_11D354_BumperBalloonCars(obj);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    if (p->out == 0) {
        func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    } else {
        s = (f32)p->shadow * 0.06f;
        if (s < 1.5f) {
            func_800297E8_2A3E8(obj->model[1], 1.5f - s, obj->scale.y, 1.5f - s);
            p->shadow++;
            if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 211600.0) {
                func_800298A4_2A4A4(obj->model[1], 4, 4);
            }
        } else {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
    }
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    if (p->out == 1) {
        h = car->hits;
        if (h == 2) {
            func_800298A4_2A4A4(obj->model[3], 4, 4);
            D_80108638_121748_BumperBalloonCars = HuMathSin(obj->rot.y + 180.0f) * 92.875f + obj->trans.x;
            D_8010863C_12174C_BumperBalloonCars = obj->trans.y + 64.3175f;
            D_80108640_121750_BumperBalloonCars = func_800B7890_B8490(obj->rot.y + 180.0f) * 92.875f + obj->trans.z;
            func_801040C8_11D1D8_BumperBalloonCars(obj->work[0], D_80108638_121748_BumperBalloonCars, D_8010863C_12174C_BumperBalloonCars, D_80108640_121750_BumperBalloonCars, h);
            car->hits++;
        } else if (car->hits < 2) {
            if (car->hits == 0) {
                func_800297E8_2A3E8(obj->model[3], 1.5f, 1.5f, 1.5f);
            } else {
                func_800297E8_2A3E8(obj->model[3], 2.0f, 2.0f, 2.0f);
            }
            b1 = HuMathSin(obj->rot.y + 180.0f) * 92.875f;
            x = b1 + obj->trans.x;
            y = obj->trans.y + 64.3175f;
            func_80029714_2A314(obj->model[3], x, y, func_800B7890_B8490(obj->rot.y + 180.0f) * 92.875f + obj->trans.z);
            car->hits++;
        }
    } else {
        b2 = HuMathSin(obj->rot.y + 180.0f) * 92.875f;
        x = b2 + obj->trans.x;
        y = obj->trans.y + 64.3175f;
        func_80029714_2A314(obj->model[3], x, y, func_800B7890_B8490(obj->rot.y + 180.0f) * 92.875f + obj->trans.z);
    }
    if (p->stun != 0) {
        p->stun--;
    } else {
        p->stun = 0;
    }
    if (p->stun == 1 && (gPlayers[obj->work[0]].flags & 1)) {
        p->cpuWait = (u8)(rand8() % 10) + car->cpuWait;
    }
    if (p->cpuWait != 0) {
        p->cpuWait--;
    } else {
        p->cpuWait = 0;
    }
    if (p->rumble > 0) {
        omVibrate(obj->work[0], 2, 2, 20);
        p->rumble--;
    } else {
        p->rumble = 0;
    }
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
    if (p->gone != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        func_800298A4_2A4A4(obj->model[2], 4, 4);
    }
}

void func_80106600_11F710_BumperBalloonCars(omObjData* obj) {
    s16 n = obj->work[0];
    BBCCar* car = &D_8010A490_1235A0_BumperBalloonCars[obj->work[0]];
    u16 c = gPlayers[n].character;
    void* data;
    u8 k;
    f32 x;
    f32 y;
    f32 z;
    f32 a1;
    f32 a2;
    f32 c1;
    f32 c2;

    obj->model[0] = LoadFormFile(D_80108520_121630_BumperBalloonCars[c] | 0x190000, 0x299);
    obj->model[2] = LoadFormFile(0x190009, 0x299);
    obj->model[3] = LoadFormFile(0x19000C, 0x289);
    func_80029E80_2AA80(obj->model[3], 1, 1);
    data = DataRead(D_8010852C_12163C_BumperBalloonCars[c] | 0x190000);
    D_80108650_121760_BumperBalloonCars = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[3]].hmf, data, 0, "baln_tex_mario_00_DEF");
    func_8003E4F4_3F0F4(D_80108650_121760_BumperBalloonCars, 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(obj->model[3]);
    func_80029AFC_2A6FC(obj->model[3]);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
    k = rand8() & 3;
    while (D_8010A580_123690_BumperBalloonCars[k] != 0) {
        k = rand8() & 3;
    }
    D_8010A580_123690_BumperBalloonCars[k] = 1;
    obj->trans.x = D_80108538_121648_BumperBalloonCars[k].x;
    obj->trans.y = D_80108538_121648_BumperBalloonCars[k].y;
    obj->trans.z = D_80108538_121648_BumperBalloonCars[k].z;
    obj->rot.y = D_80108538_121648_BumperBalloonCars[k].rot;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    a1 = HuMathSin(obj->rot.y + 180.0f) * 92.875f;
    x = a1 + obj->trans.x;
    y = obj->trans.y + 64.3175f;
    c1 = func_800B7890_B8490(obj->rot.y + 180.0f) * 92.875f;
    z = c1 + obj->trans.z;
    func_80029714_2A314(obj->model[3], x, y, z);
    func_8002979C_2A39C(obj->model[3], x, y, z);
    a2 = HuMathSin(obj->rot.y + 180.0f) * 92.875f;
    x = a2 + obj->trans.x;
    y = obj->trans.y + 64.3175f;
    c2 = func_800B7890_B8490(obj->rot.y + 180.0f) * 92.875f;
    z = c2 + obj->trans.z;
    func_80029714_2A314(obj->model[3], x, y, z);
    func_8002979C_2A39C(obj->model[3], x, y, z);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[2], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    obj->func_ptr = func_80106004_11F114_BumperBalloonCars;
    if (gPlayers[obj->work[0]].flags & 1) {
        switch (gPlayers[obj->work[0]].cpu_difficulty) {
        case 0:
            car->arc = 30.0f;
            car->cpuRand = 4;
            car->cpuWait = 20;
            break;
        case 1:
            car->arc = 45.0f;
            car->cpuRand = 2;
            car->cpuWait = 10;
            break;
        case 2:
            car->arc = 60.0f;
            car->cpuRand = 1;
            car->cpuWait = 0;
            break;
        default:
            car->arc = 75.0f;
            car->cpuRand = 1;
            car->cpuWait = 0;
            break;
        }
    }
}

void func_80106B80_11FC90_BumperBalloonCars(void) {
    s16 i;
    omObjData* o;
    BBCObj* r;
    u8 n;

    for (i = 0; i < 4; i++) {
        r = D_801086E0_1217F0_BumperBalloonCars + i;
        o = omAddObj(100, 4, 0, -1, func_80106600_11F710_BumperBalloonCars);
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
        r->obj = o;
        D_800FC87A_FD47A++;
    }
}

void func_80106C90_11FDA0_BumperBalloonCars(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80106CB4_11FDC4_BumperBalloonCars(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_80106C90_11FDA0_BumperBalloonCars;
    }
}

void func_80106CEC_11FDFC_BumperBalloonCars(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106CB4_11FDC4_BumperBalloonCars;
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
    }
}

/* Car against car. */
void func_80106D44_11FE54_BumperBalloonCars(void) {
    Vec from;
    Vec to;
    Vec out;
    BBCObj* p;
    BBCObj* q;
    BBCCar* car;
    omObjData* o;
    omObjData* t;
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        if (p->obj != NULL && p->out == 0) {
            o = p->obj;
            car = &D_8010A490_1235A0_BumperBalloonCars[o->work[0]];
            for (j = 0; j < 4; j++) {
                car->hit[j] = 0;
            }
            if (p->stun < 16) {
                for (j = 0; j < 4; j++) {
                    if (i != j) {
                        q = &D_801086E0_1217F0_BumperBalloonCars[j];
                        t = q->obj;
                        if (t != NULL && q->out == 0) {
                            from.x = o->trans.x;
                            from.y = 0.0f;
                            from.z = o->trans.z;
                            to.x = t->trans.x;
                            to.y = 0.0f;
                            to.z = t->trans.z;
                            func_80108084_121194_BumperBalloonCars(&from, &to, &out);
                            if (out.x < 112.5f) {
                                if (car->sndFwd != -1) {
                                    func_80079848_7A448(car->sndFwd);
                                    car->sndFwd = -1;
                                }
                                if (car->sndBack != -1) {
                                    func_80079848_7A448(car->sndBack);
                                    car->sndBack = -1;
                                }
                                func_80079798_7A398(0x151, o->work[0]);
                                if (p->stun == 0) {
                                    p->stun = 20;
                                    p->cpuHit = 1;
                                }
                                car->hit[j] = 1;
                            } else {
                                car->hit[j] = 0;
                            }
                        } else {
                            car->hit[j] = 0;
                        }
                    }
                }
            }
        }
    }
}

/* The rail. */
void func_80106F9C_1200AC_BumperBalloonCars(void) {
    BBCObj* p;
    BBCCar* car;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        if (p->obj != NULL && p->out == 0) {
            o = p->obj;
            car = &D_8010A490_1235A0_BumperBalloonCars[o->work[0]];
            if (o->trans.x * o->trans.x + o->trans.z * o->trans.z > 211600.0) {
                if (car->sndFwd != -1) {
                    func_80079848_7A448(car->sndFwd);
                    car->sndFwd = -1;
                }
                if (car->sndBack != -1) {
                    func_80079848_7A448(car->sndBack);
                    car->sndBack = -1;
                }
                func_80079798_7A398(0x156, o->work[0]);
                car->wall = 1;
                if (p->stun == 0) {
                    p->stun = 20;
                }
            } else {
                car->wall = 0;
            }
        }
    }
}

/* The bounce out of a hit. */
void func_801070EC_1201FC_BumperBalloonCars(void) {
    Vec from;
    Vec to;
    Vec out;
    BBCObj* p;
    BBCObj* q;
    BBCCar* car;
    BBCCar* c2;
    omObjData* o;
    f32 d;
    s16 i;
    s16 j;
    u16 n;
    s32 zero;
    s32 f;

    for (i = 0; i < 4; i++) {
        n = 0;
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        zero = 0;
        if (p->obj != NULL && p->out == 0) {
            o = p->obj;
            car = &D_8010A490_1235A0_BumperBalloonCars[o->work[0]];
            for (j = 0; j < 4; j++) {
                if (car->hit[j] != 0) {
                    q = &D_801086E0_1217F0_BumperBalloonCars[j];
                    c2 = &D_8010A490_1235A0_BumperBalloonCars[q->obj->work[0]];
                    car->prevSpeed = car->speed;
                    if (car->speed == 0.0f) {
                        car->speed = 13.0f;
                    } else if (c2->speed == 0.0f) {
                        car->speed = 15.0f;
                    }
                    car->bounce = func_800B1830_B2430(car->speed * car->speed);
                    car->prevDir = car->dir;
                    from.x = o->trans.x;
                    from.y = 0.0f;
                    from.z = o->trans.z;
                    to.x = q->x;
                    to.y = 0.0f;
                    to.z = q->z;
                    func_80108084_121194_BumperBalloonCars(&from, &to, &out);
                    if (n == 0) {
                        car->dir = out.z;
                        if (out.z == 0.0f) {
                            zero = 1;
                        }
                    } else {
                        if (out.z == 0.0f) {
                            zero = 1;
                        }
                        car->dir = BBC_WRAP((car->dir + out.z) / 2.0f);
                    }
                    n++;
                    if (car->prevSpeed == 0.0f) {
                        d = func_800B1830_B2430((out.z - o->rot.y) * (out.z - o->rot.y));
                        if ((d >= 0.0f && d < 36.5f) || (d >= 90.0f && d < 145.5f) || (d >= 180.0f && d < 214.5f)
                            || (d >= 270.0f && d < 323.5f)) {
                            car->steer = 1.0f;
                        } else {
                            car->steer = -1.0f;
                        }
                    }
                }
            }
            if (n != 0) {
                d = car->dir;
                if (d < 180.0f) {
                    f = d > 90.0f;
                    if (zero & f) {
                        car->dir = BBC_WRAP(car->dir + 180.0f);
                    }
                }
            }
            if (car->wall != 0) {
                car->bounce = func_800B1830_B2430(car->speed * car->speed);
                car->dir = func_80107EBC_120FCC_BumperBalloonCars(o->trans.x, o->trans.z);
                o->trans.x = HuMathSin(car->dir) * 459.0;
                o->trans.z = func_800B7890_B8490(car->dir) * 459.0;
            }
        }
    }
}

/* A bumper in a balloon: the car behind loses air; every car hit in a frame is placed at random. */
void func_8010765C_12076C_BumperBalloonCars(void) {
    Vec from;
    Vec to;
    Vec out;
    u16 hit[4];
    u16 place;
    s32 v;
    BBCObj* p;
    BBCObj* q;
    BBCCar* car;
    omObjData* o;
    omObjData* t;
    omObjData* t1;
    s16 i;
    s16 j;
    u16 n;
    u8 k;

    place = 0;
    n = 0;
    for (i = 0; i < 4; i++) {
        hit[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        p = &D_801086E0_1217F0_BumperBalloonCars[i];
        if (p->obj != NULL && p->out == 0) {
            o = p->obj;
            car = &D_8010A490_1235A0_BumperBalloonCars[o->work[0]];
            for (j = 0; j < 4; j++) {
                if (i != j) {
                    q = &D_801086E0_1217F0_BumperBalloonCars[j];
                    t1 = q->obj;
                    if (t1 != NULL && q->out == 0 && p->out == 0) {
                        t = t1;
                        from.x = HuMathSin(o->rot.y) * -90.0f + o->trans.x;
                        from.y = 0.0f;
                        from.z = func_800B7890_B8490(o->rot.y) * -90.0f + o->trans.z;
                        to.x = HuMathSin(t->rot.y) * 70.0f + t->trans.x;
                        to.y = 0.0f;
                        to.z = func_800B7890_B8490(t->rot.y) * 70.0f + t->trans.z;
                        func_80108084_121194_BumperBalloonCars(&from, &to, &out);
                        if (out.x < 56.25f) {
                            if (!(gPlayers[o->work[0]].flags & 1)) {
                                p->rumble = 15;
                            }
                            p->lift = 30;
                            p->out = 1;
                            car->dir = o->rot.y;
                            n++;
                            hit[i] = 1;
                        }
                    }
                }
            }
        }
    }
    if (n != 0) {
        do {
            k = rand8() & 3;
            if (hit[k] == 1) {
                q = &D_801086E0_1217F0_BumperBalloonCars[k];
                t = q->obj;
                v = 4 - D_8010A58B_12369B_BumperBalloonCars;
                t->work[3] = v - place;
                n--;
                place++;
                hit[k] = 0;
            }
        } while (n != 0);
    }
}

void func_801079A8_120AB8_BumperBalloonCars(void) {
    D_801086D2_1217E2_BumperBalloonCars += D_80108654_121764_BumperBalloonCars;
    D_80108654_121764_BumperBalloonCars = 0;
}

void func_801079D0_120AE0_BumperBalloonCars(omObjData* obj) {
    func_801079A8_120AB8_BumperBalloonCars();
    if (D_801086D2_1217E2_BumperBalloonCars == 5) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106CB4_11FDC4_BumperBalloonCars;
        return;
    }
    if (D_801086D2_1217E2_BumperBalloonCars == 2) {
        func_8010765C_12076C_BumperBalloonCars();
    }
    func_80106F9C_1200AC_BumperBalloonCars();
    func_80106D44_11FE54_BumperBalloonCars();
    func_801070EC_1201FC_BumperBalloonCars();
    if (D_801086D0_1217E0_BumperBalloonCars > 0) {
        D_801086D0_1217E0_BumperBalloonCars--;
        return;
    }
    D_801086D0_1217E0_BumperBalloonCars = 0;
}

void func_80107A74_120B84_BumperBalloonCars(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        D_8010A490_1235A0_BumperBalloonCars[i].dir = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].prevDir = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].steer = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].speed = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].bounce = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].prevSpeed = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].arc = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].cpuRand = 0;
        D_8010A490_1235A0_BumperBalloonCars[i].cpuWait = 0;
        D_8010A490_1235A0_BumperBalloonCars[i].tick = 0;
        D_8010A490_1235A0_BumperBalloonCars[i].hits = 0;
        D_8010A490_1235A0_BumperBalloonCars[i].sndFwd = -1;
        D_8010A490_1235A0_BumperBalloonCars[i].sndBack = -1;
        D_8010A490_1235A0_BumperBalloonCars[i].unk_34 = 0.0f;
        D_8010A490_1235A0_BumperBalloonCars[i].unk_38 = 0;
        for (j = 0; j < 5; j++) {
            D_8010A490_1235A0_BumperBalloonCars[i].hit[j] = 0;
        }
    }
}

void func_80107BB8_120CC8_BumperBalloonCars(omObjData* obj) {
    s16 i;

    func_80108400_121510_BumperBalloonCars();
    func_801084F4_121604_BumperBalloonCars();
    func_80107A74_120B84_BumperBalloonCars();
    D_801086D2_1217E2_BumperBalloonCars = 0;
    func_80103968_11CA78_BumperBalloonCars();
    omAddObj(600, 0, 0, -1, func_80103DB0_11CEC0_BumperBalloonCars);
    D_80108652_121762_BumperBalloonCars = 0;
    D_801086D0_1217E0_BumperBalloonCars = 10;
    D_80108654_121764_BumperBalloonCars = 0;
    for (i = 0; i < 4; i++) {
        D_8010A580_123690_BumperBalloonCars[i] = 0;
    }
    func_80102AB4_11BBC4_BumperBalloonCars();
    func_80106B80_11FC90_BumperBalloonCars();
    func_80103144_11C254_BumperBalloonCars();
    func_8010408C_11D19C_BumperBalloonCars();
    func_80102EB4_11BFC4_BumperBalloonCars();
    InitFadeIn(0, 16);
    obj->func_ptr = func_801079D0_120AE0_BumperBalloonCars;
    omAddObj(50, 0, 0, -1, func_8010281C_11B92C_BumperBalloonCars);
}

__asm__(".section .rodata");
const char D_801085F0_121700_BumperBalloonCars[] = "\202`\202a\202b";

void func_80107CCC_120DDC_BumperBalloonCars(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(70);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 22.386f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 22.386f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_80107BB8_120CC8_BumperBalloonCars);
    omAddObj(1000, 0, 0, -1, func_80106CEC_11FDFC_BumperBalloonCars);
    func_8007273C_7333C((u8*)D_801085F0_121700_BumperBalloonCars, 0);
    func_8007273C_7333C((u8*)D_801085F0_121700_BumperBalloonCars, 1);
}

f32 func_80107EBC_120FCC_BumperBalloonCars(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }
    return a;
}

f32 func_80107F34_121044_BumperBalloonCars(f32 x) {
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

/* Three instructions out of order (the 180.0f load sits after the compare in retail): scheduling. */
#ifdef NON_MATCHING
void func_80108084_121194_BumperBalloonCars(Vec* from, Vec* to, Vec* out) {
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
            yaw = func_80107F34_121044_BumperBalloonCars(delta.x / delta.z) * 57.29577951308232;
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
            pitch = func_80107F34_121044_BumperBalloonCars(delta.y / horizontal) * 57.29577951308232;
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80108084_121194_BumperBalloonCars);
#endif
