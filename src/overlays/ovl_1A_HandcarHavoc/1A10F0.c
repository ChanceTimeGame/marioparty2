#include "ovl_1A.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108360_1A10F0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108398_1A1128_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_801083B4_1A1144_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_801085F8_1A1388_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108730_1A14C0_HandcarHavoc);

/* The two wheel spots of one side (D_8010B184), placed on the car (MP1 func_800FD888). */
// NON_MATCHING: stack addressing of the unused copy array tmp (as MP1 func_800FD888)
#ifdef NON_MATCHING
void func_80108A1C_1A17AC_HandcarHavoc(omObjData* obj, u16 side, Vec* out) {
    HHMtx m;
    f32 v[4];
    f32 t[4];
    Vec tmp[2];
    HHCar* w;
    f32 rx;
    f32 ry;
    f32 rz;
    s32 k;
    s32 i;
    s32 j;

    w = obj->unk_50;
    rx = HuMathSin(w->rot.y) + w->rot.x;
    ry = w->rot.y;
    rz = func_800B7890_B8490(ry) + w->rot.z;
    if (rx < 0.0f) {
        rx += 360.0f;
    }
    if (rx >= 360.0f) {
        rx -= 360.0f;
    }
    if (ry < 0.0f) {
        ry += 360.0f;
    }
    if (ry >= 360.0f) {
        ry -= 360.0f;
    }
    if (rz < 0.0f) {
        rz += 360.0f;
    }
    if (rz >= 360.0f) {
        rz -= 360.0f;
    }
    for (k = 0; k < 2; k++) {
        v[0] = D_8010B184_1A3F14_HandcarHavoc[side * 2 + k].x;
        v[1] = D_8010B188_1A3F18_HandcarHavoc[side * 2 + k].x;
        v[2] = D_8010B18C_1A3F1C_HandcarHavoc[side * 2 + k].x;
        v[3] = 1.0f;
        guMtxIdentF(m);
        func_80025884_26484(m, 0.0f, ry, 0.0f);
        for (j = 0; j < 4; j++) {
            t[j] = 0;
            for (i = 0; i < 4; i++) {
                t[j] += v[i] * m[i][j];
            }
        }
        guMtxIdentF(m);
        func_80025884_26484(m, rx, 0.0f, rz);
        for (j = 0; j < 4; j++) {
            v[j] = 0;
            for (i = 0; i < 4; i++) {
                v[j] += t[i] * m[i][j];
            }
        }
        tmp[k].x = out[k].x = obj->trans.x + v[0];
        tmp[k].y = out[k].y = obj->trans.y + v[1];
        tmp[k].z = out[k].z = obj->trans.z + v[2];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108A1C_1A17AC_HandcarHavoc);
#endif

/* Pumps the levers by the car's speed and pump power (MP1 func_800FDBC8). */
// NON_MATCHING: retail keeps the lever model zero-extended and sign-extends it at each use (as MP1)
#ifdef NON_MATCHING
void func_80108D5C_1A1AEC_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 pump;
    s32 mdl;

    w = obj->unk_50;
    func_80108E80_1A1C10_HandcarHavoc(obj->model[0], w->leverDir, fabs(w->speed) / 20.0);
    pump = w->pump;
    mdl = obj->model[1];
    w->lever1Dir = func_80108E80_1A1C10_HandcarHavoc(mdl, w->lever1Dir, pump);
    w->lever2Dir = func_80108E80_1A1C10_HandcarHavoc(obj->model[2], w->lever2Dir, pump);
    D_800FC834_FD434[obj->model[3]].unk40 = 18.0f - D_800FC834_FD434[(s16)mdl].unk40;
    D_800FC834_FD434[obj->model[4]].unk40 = D_800FC834_FD434[(s16)mdl].unk40;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108D5C_1A1AEC_HandcarHavoc);
#endif

/* Steps a model's animation frame back and forth between 0 and its length; returns the
   direction (1 = backwards; MP1 func_800FDCEC). */
u16 func_80108E80_1A1C10_HandcarHavoc(s16 mdl, u16 dir, f32 step) {
    f32 len;

    len = func_80029D0C_2A90C(mdl);
    if (dir) {
        D_800FC834_FD434[mdl].unk40 -= step;
        if (func_80029CE4_2A8E4(mdl) <= 0.0f) {
            dir = 0;
            D_800FC834_FD434[mdl].unk40 = fabsf(func_80029CE4_2A8E4(mdl));
        }
    } else {
        D_800FC834_FD434[mdl].unk40 += step;
        if (len <= func_80029CE4_2A8E4(mdl)) {
            dir = 1;
            D_800FC834_FD434[mdl].unk40 = len + (len - func_80029CE4_2A8E4(mdl));
        }
    }
    return dir;
}

/* Allocates a team's six spark bursts: two vertex sets and a display list per frame buffer, and
   a model for each (MP1 func_800FE8D4, 12 bursts there). */
// NON_MATCHING: register allocation (masked 0: the two loop counters swap s4/s5)
#ifdef NON_MATCHING
void func_80108FBC_1A1D4C_HandcarHavoc(s32 team) {
    s32 i;
    s32 b;
    s32 k;
    s32 file;
    u16 layer;
    Vtx* v;
    Vtx* v2;
    s16 mdl;

    if (team == 0) {
        file = 0x684;
        layer = 1;
    } else {
        file = 0x684;
        layer = 2;
    }
    for (i = 0; i < 6; i++) {
        for (b = 0; b < D_800FDBCA_FE7CA; b++) {
            D_8010B420_1A41B0_HandcarHavoc[team][i][b] = func_80027154_27D54(24 * sizeof(Vtx), 0x7918);
            D_8010B5A0_1A4330_HandcarHavoc[team][i][b] = func_80027154_27D54(24 * sizeof(Vtx), 0x7918);
            D_8010B720_1A44B0_HandcarHavoc[team][i][b] = func_80027154_27D54(50 * sizeof(Gfx), 0x7918);
            v = D_8010B420_1A41B0_HandcarHavoc[team][i][b];
            v2 = D_8010B5A0_1A4330_HandcarHavoc[team][i][b];
            for (k = 0; k < 8; k++) {
                v->v.ob[0] = 0;
                v->v.ob[1] = 0;
                v->v.ob[2] = 0;
                v2->v.ob[0] = 0;
                v2->v.ob[1] = 0;
                v2->v.ob[2] = 0;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0xF5;
                v->v.cn[2] = 0x40;
                v->v.cn[3] = 0xFF;
                v++;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0x20;
                v->v.cn[2] = 0;
                v->v.cn[3] = 0xFF;
                v++;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0x60;
                v->v.cn[2] = 0;
                v->v.cn[3] = 0xFF;
                v++;
                v2->v.cn[0] = 0x80;
                v2->v.cn[1] = 0xF5;
                v2->v.cn[2] = 0xFF;
                v2->v.cn[3] = 0xFF;
                v2++;
                v2->v.cn[0] = 0;
                v2->v.cn[1] = 0x20;
                v2->v.cn[2] = 0xFF;
                v2->v.cn[3] = 0xFF;
                v2++;
                v2->v.cn[0] = 0;
                v2->v.cn[1] = 0x60;
                v2->v.cn[2] = 0xFF;
                v2->v.cn[3] = 0xFF;
                v2++;
            }
        }
        mdl = func_80027FA4_28BA4(file, D_8010B720_1A44B0_HandcarHavoc[team][i][D_800FDBE0_FE7E0], 4);
        D_8010D7C0_1A6550_HandcarHavoc[team][i] = mdl;
        func_80029EDC_2AADC(mdl, layer);
    }
    for (i = 0; i < 6; i++) {
        D_8010B8A0_1A4630_HandcarHavoc[team][i].active = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108FBC_1A1D4C_HandcarHavoc);
#endif

/* Builds a spark burst's display list for one frame buffer (MP1 func_800FEB4C). */
void func_8010929C_1A202C_HandcarHavoc(s32 team, s32 i, s32 buf, s32 set) {
    Gfx* gfx;
    Vtx* vtx;
    s32 k;

    gfx = D_8010B720_1A44B0_HandcarHavoc[team][i][buf];
    if (set == 0) {
        vtx = D_8010B420_1A41B0_HandcarHavoc[team][i][buf];
    } else {
        vtx = D_8010B5A0_1A4330_HandcarHavoc[team][i][buf];
    }
    if (D_8010B8A0_1A4630_HandcarHavoc[team][i].active == 1) {
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552230);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        gSPVertex(gfx++, vtx, 24, 0);
        for (k = 0; k < 24; k += 3) {
            gSP1Triangle(gfx++, k, k + 1, k + 2, 0);
        }
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}

/* Starts a spark burst at a wheel (side 0/1, wheel 0/1) in vertex set `set`; returns its model,
   or -1 when all six are in use (MP1 func_800FECF4). */
s16 func_80109484_1A2214_HandcarHavoc(s32 team, u16 side, u16 wheel, s32 set) {
    HHSparks* p;
    f32 yaw;
    f32 pitch;
    f32 r;
    s32 i;
    s32 k;
    u16 sel;

    sel = side * 2 + wheel;
    for (i = 0; i < 6; i++) {
        if (D_8010B8A0_1A4630_HandcarHavoc[team][i].active == 0) {
            break;
        }
    }
    if (i == 6) {
        return -1;
    }
    p = &D_8010B8A0_1A4630_HandcarHavoc[team][i];
    p->active = 1;
    p->timer = 4;
    p->side = side;
    p->wheel = wheel;
    func_800298A4_2A4A4(D_8010D7C0_1A6550_HandcarHavoc[team][i], 4, 0);
    for (k = 0; k < 8; k++) {
        pitch = (u8)(rand8() % 5) + 3;
        switch (sel) {
            case 0:
                yaw = -5 - (u8)(rand8() % 31);
                break;
            case 1:
                yaw = -(u8)(rand8() % 36) + 5;
                break;
            case 2:
                yaw = (u8)(rand8() % 31) + 5;
                break;
            case 3:
                yaw = (u8)(rand8() % 36) - 5;
                break;
        }
        r = D_8010B1B4_1A3F44_HandcarHavoc[k];
        p->chip[k].a.x = HuMathSin(yaw) * r;
        p->chip[k].a.y = HuMathSin(pitch) * r;
        p->chip[k].a.z = func_800B7890_B8490(yaw) * r;
        p->chip[k].b.x = HuMathSin(yaw + 1.5f) * r;
        p->chip[k].b.y = HuMathSin(pitch) * r;
        p->chip[k].b.z = func_800B7890_B8490(yaw + 1.5f) * r;
    }
    p->set = set;
    return D_8010D7C0_1A6550_HandcarHavoc[team][i];
}

/* Updates a car's spark bursts (vertices, display lists, timers) and their sound (MP1
   func_800FF0AC). */
// NON_MATCHING: loop-invariant hoisting and register allocation (team bases)
#ifdef NON_MATCHING
void func_8010986C_1A25FC_HandcarHavoc(HHCar* w) {
    HHSparks* p;
    HHChip* c;
    s16* mdl;
    Vtx* v;
    s32 team;
    u16 any;
    s32 i;
    s32 k;

    any = 0;
    team = w->team;
    mdl = D_8010D7C0_1A6550_HandcarHavoc[team];
    for (i = 0; i < 6; i++) {
        D_800FC834_FD434[mdl[i]].hmf->unk3C->unk00[0] = D_8010B720_1A44B0_HandcarHavoc[team][i][D_800FDBE0_FE7E0];
        p = &D_8010B8A0_1A4630_HandcarHavoc[team][i];
        if (p->active != 0) {
            any = 1;
            if (p->set == 0) {
                v = D_8010B420_1A41B0_HandcarHavoc[team][i][D_800FDBE0_FE7E0];
            } else {
                v = D_8010B5A0_1A4330_HandcarHavoc[team][i][D_800FDBE0_FE7E0];
            }
            for (k = 0; k < 8; k++) {
                c = &p->chip[k];
                v++;
                v->v.ob[0] = c->a.x;
                v->v.ob[1] = c->a.y;
                v->v.ob[2] = c->a.z;
                v++;
                v->v.ob[0] = c->b.x;
                v->v.ob[1] = c->b.y;
                v->v.ob[2] = c->b.z;
                v++;
            }
            func_8010929C_1A202C_HandcarHavoc(team, i, D_800FDBE0_FE7E0, p->set);
            if (--p->timer == 0) {
                p->active = 0;
                func_800298A4_2A4A4(D_8010D7C0_1A6550_HandcarHavoc[team][i], 4, 4);
                w->chips[p->side][p->wheel]--;
            }
        }
    }
    if (any == 1) {
        if (w->sparkSndOn == 0) {
            w->sparkSnd = func_80079798_7A398(w->team + 0x206, w->team + 2);
            w->sparkSndOn = 1;
        }
    } else if (w->sparkSndOn == 1) {
        func_80079848_7A448(w->sparkSnd);
        w->sparkSndOn = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010986C_1A25FC_HandcarHavoc);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109B88_1A2918_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109BA4_1A2934_HandcarHavoc);
