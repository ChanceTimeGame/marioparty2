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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80105090_11E1A0_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106004_11F114_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106600_11F710_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106B80_11FC90_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106C90_11FDA0_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106CB4_11FDC4_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106CEC_11FDFC_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106D44_11FE54_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80106F9C_1200AC_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_801070EC_1201FC_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_8010765C_12076C_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_801079A8_120AB8_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_801079D0_120AE0_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80107A74_120B84_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80107BB8_120CC8_BumperBalloonCars);

__asm__(".section .rodata");
const char D_801085F0_121700_BumperBalloonCars[] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80107CCC_120DDC_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80107EBC_120FCC_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80107F34_121044_BumperBalloonCars);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_BumperBalloonCars/11B910", func_80108084_121194_BumperBalloonCars);
