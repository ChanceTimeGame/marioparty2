#include "ovl_10.h"

void func_80107F70_151A90_CraneGame(void) {
    void* p;

    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
    D_8010C904_156424_CraneGame = 0;
    D_8010C260_155D80_CraneGame = func_8002838C_28F8C(0, func_801082F4_151E14_CraneGame, 2);
    D_8010C8F8_156418_CraneGame.x = D_8010C8F8_156418_CraneGame.y = D_8010C8F8_156418_CraneGame.z = 0.0f;
    D_8010CAF0_156610_CraneGame = 1.0f;
    D_8010C908_156428_CraneGame = 0;
    p = DataRead(0x200012);
    D_8010C8E8_156408_CraneGame = SprAnimRead(p);
    DataClose(p);
    D_8010C8EC_15640C_CraneGame = **SprAnimGet(D_8010C8E8_156408_CraneGame);
}

void func_80108038_151B58_CraneGame(void) {
    s32 i;

    if (D_8010C262_155D82_CraneGame != 0) {
        for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
            HuMemFree(D_8010C4E8_156008_CraneGame[i][0]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][1]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][2]);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]->dl);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]);
        }
    }
    func_800283DC_28FDC(D_8010C260_155D80_CraneGame);
    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
}

void func_80108114_151C34_CraneGame(s16 model) {
    D_8010C268_155D88_CraneGame[D_8010C262_155D82_CraneGame] = model;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].cur = 1.0f;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].target = 1.0f;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][0] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][1] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][2] = NULL;
    D_8010C7E8_156308_CraneGame[D_8010C262_155D82_CraneGame] = NULL;
    D_8010C8F0_156410_CraneGame = D_8010C262_155D82_CraneGame;
    func_80108D18_152838_CraneGame(model);
    D_8010C262_155D82_CraneGame++;
}

void func_801081C8_151CE8_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_80108238_151D58_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].cur = D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_801082B8_151DD8_CraneGame(f32 y) {
    D_8010C908_156428_CraneGame = 1;
    D_8010C90C_15642C_CraneGame = y;
}

void func_801082D0_151DF0_CraneGame(f32 x, f32 y, f32 z) {
    D_8010C8F8_156418_CraneGame.x = x;
    D_8010C8F8_156418_CraneGame.y = y;
    D_8010C8F8_156418_CraneGame.z = z;
}

void func_801082E8_151E08_CraneGame(f32 scale) {
    D_8010CAF0_156610_CraneGame = scale;
}

void func_801082F4_151E14_CraneGame(Gfx** gfx, Mtx* mtx) {
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f inv;
    HmfModel* p;
    HmfData* m;
    s32 i;
    s16 mdl;
    f32 a;

    if (++D_8010C264_155D84_CraneGame >= 3) {
        D_8010C264_155D84_CraneGame = 0;
    }
    D_8010C904_156424_CraneGame = (D_8010C904_156424_CraneGame + 1) & 0xF;
    gDPPipeSync((*gfx)++);
    gSPDisplayList((*gfx)++, D_8010BCE0_155800_CraneGame);
    gDPPipeSync((*gfx)++);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_BACK | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetRenderMode((*gfx)++, G_RM_AA_ZB_XLU_DECAL, G_RM_NOOP2);
    gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*gfx)++, 0x08, 0x08, 0x08, 0x08);
    gDPSetColorDither((*gfx)++, G_CD_NOISE);
    gDPSetAlphaDither((*gfx)++, G_AD_PATTERN);
    gDPSetTexturePersp((*gfx)++, G_TP_PERSP);
    gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xB0);
    gDPLoadTextureBlock_4b((*gfx)++, D_8010C8EC_15640C_CraneGame, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPTexture((*gfx)++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    func_800204C0_210C0(0, gfx);
    func_800B30D0_B3CD0(m1, mtx + 1);
    func_80025770_26370(m1, D_8010C8F8_156418_CraneGame.x, D_8010C8F8_156418_CraneGame.y, D_8010C8F8_156418_CraneGame.z);
    func_800B1F50_B2B50(m2, -m1[3][0], -m1[3][1], -m1[3][2]);
    func_80025F00_26B00(m1, inv);
    func_800B6410_B7010(m2, inv, inv);
    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        D_8010C8F0_156410_CraneGame = i;
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (D_8010C2E8_155E08_CraneGame[i].cur < CG_FADE_TARGET(i)) {
                D_8010C2E8_155E08_CraneGame[i].cur += 0.1;
                if (CG_FADE_TARGET(i) < D_8010C2E8_155E08_CraneGame[i].cur) {
                    D_8010C2E8_155E08_CraneGame[i].cur = CG_FADE_TARGET(i);
                }
            } else {
                D_8010C2E8_155E08_CraneGame[i].cur -= 0.1;
                if (D_8010C2E8_155E08_CraneGame[i].cur < CG_FADE_TARGET(i)) {
                    D_8010C2E8_155E08_CraneGame[i].cur = CG_FADE_TARGET(i);
                }
            }
            CG_FADE_TARGET(i) = 1.0f;
        }
        a = D_8010C2E8_155E08_CraneGame[i].cur;
        D_8010C8F4_156414_CraneGame = a;
        mdl = D_8010C268_155D88_CraneGame[i];
        if (mdl >= 0) {
            p = &D_800FC834_FD434[mdl];
            m = p->hmf;
            if (m != NULL) {
                if (!(p->unk18 & 4)) {
                    if (a != 0.0f) {
                        *gfx = func_8010887C_15239C_CraneGame(*gfx, m, inv);
                    }
                }
            }
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetRenderMode((*gfx)++, 0x404BD8, 0);
    *gfx = func_801097A0_1532C0_CraneGame(*gfx, mtx);
    gDPPipeSync((*gfx)++);
}

/* MP1 func_800FC0A0 (NON_MATCHING there too): MP2 divides the height by 1200, clamps it before the
   texture scale, scales by D_8010CAF0 and fades by 0.5. Residue: retail hoists 16.0f out of the loops
   and reads the part's matrix record in another order (register allocation). */
#ifdef NON_MATCHING
Gfx* func_8010887C_15239C_CraneGame(Gfx* gfx, HmfData* m, Matrix4f inv) {
    Matrix4f mf;
    Matrix4f r;
    Vtx* vbuf;
    Vtx* v;
    CGShadowGroup* grp;
    Mtx* mtx;
    s32 i;
    s32 j;
    f32 h;
    f32 d;
    f32 px;
    f32 pz;
    f64 s;

    vbuf = D_8010C4E8_156008_CraneGame[D_8010C8F0_156410_CraneGame][D_8010C264_155D84_CraneGame];
    gSPSegment(gfx++, 1, osVirtualToPhysical(vbuf));
    grp = D_8010C7E8_156308_CraneGame[D_8010C8F0_156410_CraneGame];
    for (i = 0; i < (m->unk10 & 0x3F); i++, grp++) {
        mtx = D_800F8C58_F9858[D_800FDC48_FE848[m->unk00][m->unk64[i].unk2F].unk02].unk44;
        func_800B30D0_B3CD0(mf, mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_800B6410_B7010(mf, inv, r);
        d = r[3][0];
        if (d < 0.0f) {
            d = -d;
        }
        if (d > 300.0) {
            continue;
        }
        d = r[3][2];
        if (d < 0.0f) {
            d = -d;
        }
        if (d > 300.0) {
            continue;
        }
        v = vbuf + grp->start;
        for (j = 0; j < grp->count; j++, v++) {
            px = (f32)v->v.ob[0] * r[0][0] + (f32)v->v.ob[1] * r[1][0] + (f32)v->v.ob[2] * r[2][0] + r[3][0];
            pz = (f32)v->v.ob[0] * r[0][2] + (f32)v->v.ob[1] * r[1][2] + (f32)v->v.ob[2] * r[2][2] + r[3][2];
            h = -((f32)v->v.ob[0] * r[0][1] + (f32)v->v.ob[1] * r[1][1] + (f32)v->v.ob[2] * r[2][1] + r[3][1]) / 1200.0;
            if (h < 0.0) {
                h = 0.0f;
            } else if (h > 1.0) {
                h = 1.0f;
            }
            s = (h + 1.0) * D_8010CAF0_156610_CraneGame * 120.0;
            v->v.tc[0] = ((s16)(s32)(px * 16.0f / s) << 5) + 0x200;
            v->v.tc[1] = ((s16)(s32)(pz * 16.0f / s) << 5) + 0x200;
            if (h > 1.0) {
                h = 1.0f;
            }
            v->v.cn[3] = (208.0 - h * 208.0f * 0.5) * D_8010C8F4_156414_CraneGame;
        }
        gSPDisplayList(gfx++, grp->dl);
    }
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_8010887C_15239C_CraneGame);
#endif

void func_80108D18_152838_CraneGame(s16 model) {
    CGShadowGroup grp[64];
    s16 offs[64];
    Gfx* gp;
    Gfx* base;
    Gfx* dl;
    CGShadowGroup* g;
    HmfData* m;
    s32 i;
    s32 size;
    Vtx* v;

    m = D_800FC834_FD434[model].hmf;
    D_8010C7E8_156308_CraneGame[D_8010C8F0_156410_CraneGame] = func_80027154_27D54((m->unk10 & 0x3F) * sizeof(CGShadowGroup), m->unk0E);
    base = gp = func_80027154_27D54(0x2000 * sizeof(Gfx), m->unk0E);
    D_8010CA94_1565B4_CraneGame = func_80027154_27D54(0x10000, m->unk0E);
    D_8010CA90_1565B0_CraneGame = func_80027154_27D54(m->unk14 * sizeof(ColVtx), m->unk0E);
    D_8010CA98_1565B8_CraneGame = func_80027154_27D54(0x8000, m->unk0E);
    D_8010CA9C_1565BC_CraneGame = func_80027154_27D54(m->unk14 * 2, m->unk0E);
    D_8010CAA4_1565C4_CraneGame = func_80027154_27D54(0x4000, m->unk0E);
    D_8010CAEC_15660C_CraneGame = 0;
    for (i = 0; i < (m->unk10 & 0x3F); i++) {
        offs[i] = ((u32)gp - (u32)base) >> 3;
        grp[i].start = D_8010CAEC_15660C_CraneGame;
        func_80109024_152B44_CraneGame(&m->unk64[i], m->unk54, m->unk14);
        func_801091D4_152CF4_CraneGame();
        func_801093A0_152EC0_CraneGame(&gp, m);
        grp[i].count = D_8010CAEC_15660C_CraneGame - grp[i].start;
    }
    HuMemFree(D_8010CA90_1565B0_CraneGame);
    HuMemFree(D_8010CA98_1565B8_CraneGame);
    HuMemFree(D_8010CA9C_1565BC_CraneGame);
    HuMemFree(D_8010CAA4_1565C4_CraneGame);
    size = (u8*)gp - (u8*)base;
    dl = func_80027154_27D54(size, m->unk0E);
    bcopy(base, dl, size);
    g = D_8010C7E8_156308_CraneGame[D_8010C8F0_156410_CraneGame];
    for (i = 0; i < (m->unk10 & 0x3F); i++) {
        g[i].dl = dl + offs[i];
        g[i].start = grp[i].start;
        g[i].count = grp[i].count;
    }
    HuMemFree(base);
    for (i = 0; i < 3; i++) {
        size = D_8010CAEC_15660C_CraneGame * sizeof(Vtx);
        v = func_80027154_27D54(size, m->unk0E);
        D_8010C4E8_156008_CraneGame[D_8010C8F0_156410_CraneGame][i] = v;
        bcopy(D_8010CA94_1565B4_CraneGame, v, size);
    }
    HuMemFree(D_8010CA94_1565B4_CraneGame);
}

/* Builds the group's face list over unique vertices (D_8010CA90) and counts how many faces use
   each vertex (D_8010CA9C). Retail's face-type test `(t < 3) & (t >= 5)` is never true, so every
   face is taken. */
void func_80109024_152B44_CraneGame(HmfPart* g, ColVtx* verts, s16 nverts) {
    u16* refs;
    CGShadowOrder* order;
    HmfFaceRec* f;
    u16* dst;
    ColVtx* p;
    ColVtx* u;
    s32 nv;
    s32 i;
    s32 nf;
    s32 j;
    s32 k;
    s32 t;

    refs = D_8010CA9C_1565BC_CraneGame;
    func_800B0EF0_B1AF0(refs, 0, nverts * 2);
    order = D_8010CAA4_1565C4_CraneGame;
    f = g->unk54;
    nv = 0;
    i = 0;
    nf = 0;
    for (; i < (g->unk04 & 0x7FFF); i++, f++) {
        t = f->unk00 & 7;
        if ((t < 3) & (t >= 5)) {
            continue;
        }
        dst = D_8010CA98_1565B8_CraneGame[i].v;
        for (j = 0; j < t; j++) {
            p = &verts[f->unk04[j]];
            u = D_8010CA90_1565B0_CraneGame;
            u[nv].x = p->x;
            u[nv].y = p->y;
            u[nv].z = p->z;
            k = 0;
            while (p->x != u->x || p->y != u->y || p->z != u->z) {
                k++;
                u++;
            }
            nv += (k >= nv);
            refs[k]++;
            if (j == 0) {
                if (t >= 4) {
                    k |= 0x8000;
                }
            }
            *dst++ = k;
        }
        order->key = 0;
        order->face = nf;
        order++;
        nf++;
    }
    D_8010CAA0_1565C0_CraneGame = nv;
    D_8010CAA2_1565C2_CraneGame = nf;
}

/* Sorts the faces far to near by how shared their vertices are (MP1 func_800FC9B0; MP2 masks the
   quad bit off the vertex index, which MP1 did not). Residue: retail copies the vertex count to a
   second register and the key before decrementing it (register allocation). */
#ifdef NON_MATCHING
void func_801091D4_152CF4_CraneGame(void) {
    CGShadowOrder* q;
    CGShadowOrder* best;
    CGShadowOrder* r;
    s16* f;
    s32 key;
    s32 i;
    s32 j;
    s32 n;
    s16 sum;
    s16 t;
    s32 pad[2];

    if (D_8010CAA0_1565C0_CraneGame >= 29) {
        key = D_8010CAA0_1565C0_CraneGame;
        q = D_8010CAA4_1565C4_CraneGame;
        for (i = 0; i < D_8010CAA2_1565C2_CraneGame; i++, q++) {
            f = (s16*)D_8010CA98_1565B8_CraneGame[i].v;
            n = 3;
            if (*f & 0x8000) {
                n = 4;
            }
            sum = 0;
            for (j = 0; j < n; j++, f++) {
                sum += D_8010CA9C_1565BC_CraneGame[*f & 0x7FFF];
            }
            q->key = key-- + (sum * 100) / n;
        }
        q = D_8010CAA4_1565C4_CraneGame;
        for (i = 0; i < D_8010CAA2_1565C2_CraneGame - 1; i++, q++) {
            best = q;
            r = q + 1;
            for (j = i; j < D_8010CAA2_1565C2_CraneGame - 1; j++, r++) {
                if (best->key < r->key) {
                    best = r;
                }
            }
            t = q->key;
            q->key = best->key;
            best->key = t;
            t = q->face;
            q->face = best->face;
            best->face = t;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801091D4_152CF4_CraneGame);
#endif

/* MP1 func_800FCB78 (NON_MATCHING there too). Residue: retail rematerialises the vertex cache's
   address in the loop and has an 8-byte larger frame (register allocation). */
#ifdef NON_MATCHING
/* Emits the faces in draw order as gSP1Triangle/gSP1Quadrangle batches of at most 29 vertices. */
void func_801093A0_152EC0_CraneGame(Gfx** gfx, HmfData* m) {
    u8 (*start)[4];
    u8 (*cur)[4];
    u8* out;
    u16* f;
    CGShadowOrder* q;
    s32 i;
    s32 n;
    s32 k;
    s16 cnt;
    s32 quad;
    s16 idx;
    s16* s;

    start = cur = func_80027154_27D54(D_8010CAA2_1565C2_CraneGame * 4, m->unk0E);
    cnt = 0;
    D_8010CAEA_15660A_CraneGame = 0;
    q = D_8010CAA4_1565C4_CraneGame;
    for (i = 0; i < D_8010CAA2_1565C2_CraneGame; i++, q++) {
        f = D_8010CA98_1565B8_CraneGame[q->face].v;
        out = start[i];
        quad = (*f >> 15) << 7;
        n = 3;
        if (quad != 0) {
            n = 4;
        }
        for (; n > 0; n--) {
            idx = *f++ & 0x7FFF;
            k = 0;
            D_8010CAA8_1565C8_CraneGame[D_8010CAEA_15660A_CraneGame] = idx;
            s = D_8010CAA8_1565C8_CraneGame;
            while (idx != *s++) {
                k++;
            }
            *out++ = quad | k;
            quad = 0;
            if (k >= D_8010CAEA_15660A_CraneGame) {
                D_8010CAEA_15660A_CraneGame++;
            }
        }
        cnt++;
        if (D_8010CAEA_15660A_CraneGame >= 29) {
            *gfx = func_801095A4_1530C4_CraneGame(*gfx, cur, cnt);
            cur += cnt;
            cnt = 0;
        }
    }
    if ((D_8010CAEA_15660A_CraneGame != 0) & (cnt != 0)) {
        *gfx = func_801095A4_1530C4_CraneGame(*gfx, cur, cnt);
    }
    gSPEndDisplayList((*gfx)++);
    HuMemFree(start);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801093A0_152EC0_CraneGame);
#endif

/* MP1 func_800FCD7C (NON_MATCHING there too). Residue: register allocation; retail steps the
   unique-vertex pointer by 2 before reading y and z. */
#ifdef NON_MATCHING
Gfx* func_801095A4_1530C4_CraneGame(Gfx* gfx, u8 (*tri)[4], s16 n) {
    Vtx* v;
    s16* s;
    ColVtx* p;
    s32 i;

    v = D_8010CA94_1565B4_CraneGame + D_8010CAEC_15660C_CraneGame;
    s = D_8010CAA8_1565C8_CraneGame;
    for (i = 0; i < D_8010CAEA_15660A_CraneGame; i++, v++, s++) {
        p = &D_8010CA90_1565B0_CraneGame[*s];
        v->v.ob[0] = p->x;
        v->v.ob[1] = p->y;
        v->v.ob[2] = p->z;
        v->v.tc[0] = v->v.tc[1] = 0;
        v->v.cn[0] = v->v.cn[1] = v->v.cn[2] = 0xFF;
        v->v.cn[3] = 0xA0;
    }
    gSPVertex(gfx++, (Vtx*)(0x01000000 | (D_8010CAEC_15660C_CraneGame * sizeof(Vtx))), D_8010CAEA_15660A_CraneGame, 0);
    D_8010CAEC_15660C_CraneGame += D_8010CAEA_15660A_CraneGame;
    D_8010CAEA_15660A_CraneGame = 0;
    for (i = 0; i < n; i++, tri++) {
        if ((*tri)[0] & 0x80) {
            gSP1Quadrangle(gfx++, (*tri)[0] & 0x7F, (*tri)[1], (*tri)[2], (*tri)[3], 0);
        } else {
            gSP1Triangle(gfx++, (*tri)[0] & 0x7F, (*tri)[1], (*tri)[2], 0);
        }
    }
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801095A4_1530C4_CraneGame);
#endif

/* MP1 func_800FCF78 with MP2's height / 1200, clamp to 1, scale D_8010CAF0, fade 0.5 and an
   unscaled y. Residue: the delay slots after the clamp (scheduling). */
#ifdef NON_MATCHING
/* The claw's round shadow: a triangle under it, wider and fainter the higher it is. */
Gfx* func_801097A0_1532C0_CraneGame(Gfx* gfx, Mtx* mtx) {
    Matrix4f m1;
    Matrix4f m2;
    Vtx* v;
    Vtx* src;
    f32 s;
    f64 sc;
    f64 a;
    s32 i;

    if (D_8010C908_156428_CraneGame == 0) {
        return gfx;
    }
    func_800B30D0_B3CD0(m1, mtx + 1);
    func_800B1F50_B2B50(m2, D_8010C8F8_156418_CraneGame.x, D_8010C90C_15642C_CraneGame, D_8010C8F8_156418_CraneGame.z);
    func_800B6410_B7010(m2, m1, m1);
    func_800B3040_B3C40(m1, &D_8010C9D0_1564F0_CraneGame[D_8010C264_155D84_CraneGame]);
    gSPMatrix(gfx++, osVirtualToPhysical(&D_8010C9D0_1564F0_CraneGame[D_8010C264_155D84_CraneGame]),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    v = D_8010C910_156430_CraneGame[D_8010C264_155D84_CraneGame];
    src = D_8010BD20_155840_CraneGame;
    gSPVertex(gfx++, osVirtualToPhysical(v), 3, 0);
    s = (D_8010C8F8_156418_CraneGame.y - D_8010C90C_15642C_CraneGame) / 1200.0;
    i = 0;
    if (s < 0.0) {
        s = 0.0f;
    } else if (s > 1.0) {
        s = 1.0f;
    }
    sc = s + 1.0;
    a = 176.0 - s * 176.0f * 0.5;
    do {
        v->v.ob[0] = src->v.ob[0] * (sc * D_8010CAF0_156610_CraneGame);
        v->v.ob[1] = src->v.ob[1];
        v->v.ob[2] = src->v.ob[2] * (sc * D_8010CAF0_156610_CraneGame);
        v->v.cn[3] = a;
        v->v.tc[0] = src->v.tc[0];
        v->v.tc[1] = src->v.tc[1];
        v->v.cn[0] = v->v.cn[1] = v->v.cn[2] = 0;
        v++;
        i++;
        src++;
    } while (i < 3);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801097A0_1532C0_CraneGame);
#endif
