#include "common.h"
#include "game/hmfman.h"

/* Model collision grids and matrix helpers. Same code as Mario Party 1's src/29C90.c (MP1 names in
   the comments); func_8002E1F8 and func_8002EDA8 stay asm. MP2's model struct has MP3's layout
   (HmfModel, size 0xC0). */

typedef f32 Matrix4f[4][4];

typedef struct ColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} ColTri;

/* One cell of a collision grid: a run of polygons in the grid's polygon stream. */
typedef struct HitCell {
    /* 0x00 */ s32 offset;
    /* 0x04 */ s16 count;
} HitCell; /* size = 0x8 */

/* Collision grid built from a model's hit data (func_8002D5B4). */
typedef struct HitGrid {
    /* 0x00 */ s32 w;
    /* 0x04 */ s32 h;
    /* 0x08 */ f32 cw;
    /* 0x0C */ f32 ch;
    /* 0x10 */ u16* polys;
    /* 0x14 */ s16* map0;
    /* 0x18 */ s16* map1;
    /* 0x1C */ s16* map2;
    /* 0x20 */ HitCell* cells;
} HitGrid; /* size = 0x24 */

/* Result list of func_8002F2C4 (callers declare it as an s32). */
typedef struct HitList {
    /* 0x00 */ u16** list;
    /* 0x04 */ u16 count;
    /* 0x06 */ u16 pos;
} HitList;

typedef struct HitProbe {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
} HitProbe;

/* MP1 unk2C0C0Struct40 (start). */

/* MP3 HmfData / MP1 unk2C0C0StructC0 (only the fields used here). */

/* MP3 HmfModel / MP1 unk_ovl_2D_struct. */

extern s16 D_800DEFA0_DFBA0;
extern s16 D_800DEFA2_DFBA2;
extern s16 D_800DEFA4_DFBA4;
extern s16* D_800DEFA8_DFBA8;
extern HitGrid* D_800FD2B8_FDEB8;
extern s32 D_800F64C4_F70C4;
extern s16 D_800FFFD6_100BD6;
extern void* D_800FD83C_FE43C;
extern s16 D_800F928C_F9E8C;

void* func_80027154_27D54(s32, s16);
void HuMemFree(void*);
void func_80027274_27E74(s16);
void func_80025770_26370(Matrix4f, f32, f32, f32); /* MP1 MtxTranslate */
void func_80025830_26430(Matrix4f, f32, f32, f32); /* MP1 MtxScale */
void func_80025884_26484(Matrix4f, f32, f32, f32); /* MP1 MtxRotate */
void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f); /* MP1 MtxMult */
f32 func_800B1830_B2430(f32);
s32 func_8002D9AC_2E5AC(Vec*);
f32 func_8002F648_30248(ColVtx*, s16, s16, s16, f32*, f32*);
s32 func_8002EC00_2F800(f32, f32, ColVtx*);
void func_80026F00_27B00(HmfData_UnkD0* arg0);
void func_80031FD8_32BD8(HmfData*, s16, void*, Matrix4f); /* MP1 func_8002D2CC */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void guMtxIdentF(float mf[4][4]);

/* Draw-culling view passed by the model draw callbacks (MP1 HitViewFan). */
typedef struct HitViewFan {
    /* 0x00 */ f32 angle;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 fov;
    /* 0x10 */ f32 len;
    /* 0x14 */ f32 back;
} HitViewFan;

#define CLAMP_S16(v) if ((v) > 0x7FFF) { (v) = 0x7FFF; } else if ((v) < -0x8000) { (v) = -0x8000; }

/* exact c: marioparty func_80029090 (src/29C90.c) */
void func_8002D4D0_2E0D0(s16 n) {
    s32 i;

    D_800DEFA2_DFBA2 = 0;
    D_800FD2B8_FDEB8 = func_80027154_27D54(n * sizeof(HitGrid), 0x55F0);
    D_800DEFA0_DFBA0 = n;
    D_800DEFA8_DFBA8 = func_80027154_27D54(n * 2, 0x55F0);
    for (i = 0; i < n; i++) {
        D_800DEFA8_DFBA8[i] = i + 1;
    }
    D_800DEFA4_DFBA4 = 0;
}

/* exact c: marioparty func_80029140 (src/29C90.c) */
s32 func_8002D580_2E180(s16 idx) {
    return D_800FD2B8_FDEB8[idx].w == D_800FD2B8_FDEB8[idx].h;
}

/* MP1 func_80029174 (src/29C90.c): build a collision grid from a model's MAP1 chunk (big-endian
   bytes, read bytewise). */
s16 func_8002D5B4_2E1B4(s16 mi) {
    s16 idx;
    u8* p;
    u32 size;
    HitGrid* g;
    HitCell* cell;
    u16 y;
    u16 x;
    u16* dst;
    u32 i;
    union {
        s32 i;
        f32 f;
    } u;

    if (D_800DEFA2_DFBA2 != D_800DEFA0_DFBA0) {
        idx = D_800DEFA4_DFBA4;
        D_800DEFA4_DFBA4 = D_800DEFA8_DFBA8[idx];
        p = D_800FC834_FD434[mi].hmf->unk38;
        size = ((p[4] << 24) | (p[5] << 16) | (p[6] << 8) | p[7]) - 0x10;
        g = &D_800FD2B8_FDEB8[idx];
        g->w = (p[8] << 8) | p[9];
        g->h = (p[10] << 8) | p[11];
        u.i = (p[16] << 24) | (p[17] << 16) | (p[18] << 8) | p[19];
        g->cw = u.f;
        u.i = (p[20] << 24) | (p[21] << 16) | (p[22] << 8) | p[23];
        g->ch = u.f;
        cell = g->cells = func_80027154_27D54((g->h << 3) * g->w, 0x55F0);
        p += 0x18;
        g->map0 = func_80027154_27D54((g->h << 1) * g->w, 0x55F0);
        g->map1 = func_80027154_27D54((g->h << 1) * g->w, 0x55F0);
        g->map2 = func_80027154_27D54((g->h << 1) * g->w, 0x55F0);
        for (y = 0; y < g->h; y++) {
            for (x = 0; x < g->w; x++) {
                g->map0[y * g->w + x] = (p[0] << 8) | p[1];
                g->map1[y * g->w + x] = (p[2] << 8) | p[3];
                g->map2[y * g->w + x] = (p[4] << 8) | p[5];
                cell->offset = (p[6] << 24) | (p[7] << 16) | (p[8] << 8) | p[9];
                cell->count = (p[10] << 8) | p[11];
                p += 0xC;
                cell++;
                size -= 0xC;
            }
        }
        dst = g->polys = func_80027154_27D54(size, 0x55F0);
        for (i = 0; i < size; i += 2) {
            *dst = (p[0] << 8) | p[1];
            dst++;
            p += 2;
        }
        D_800DEFA2_DFBA2++;
        return idx;
    }
    return -1;
}

/* exact c: marioparty func_80029518 (src/29C90.c) */
f32 func_8002D958_2E558(f32 angle) {
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

/* exact c: marioparty func_8002956C (src/29C90.c) */
s32 func_8002D9AC_2E5AC(Vec* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 len = func_800B1830_B2430(x * x + y * y + z * z);
    s32 ret = 0;

    if (len != 0.0f) {
        v->x /= len;
        v->y /= len;
        v->z /= len;
        ret = 1;
    }
    return ret;
}

/* exact c: marioparty func_800295FC (src/29C90.c) */
void func_8002DA3C_2E63C(ColVtx* a, ColVtx* b, ColVtx* c, Vec* n) {
    f32 abx = (f32)b->x - (f32)a->x;
    f32 aby = (f32)b->y - (f32)a->y;
    f32 abz = (f32)b->z - (f32)a->z;
    f32 acx = (f32)c->x - (f32)a->x;
    f32 acy = (f32)c->y - (f32)a->y;
    f32 acz = (f32)c->z - (f32)a->z;

    n->x = aby * acz - abz * acy;
    n->y = abz * acx - abx * acz;
    n->z = abx * acy - aby * acx;
    func_8002D9AC_2E5AC(n);
}

/* exact c: marioparty func_800296FC (src/29C90.c) */
f32 func_8002DB3C_2E73C(f32 x, f32 z, ColVtx* a, ColVtx* b) {
    f32 ax = a->x - x;
    f32 az = a->z - z;
    f32 bx = b->x - x;
    f32 bz = b->z - z;

    return -(az * bx - ax * bz);
}

/* exact c: marioparty func_80029764 (src/29C90.c) */
f32 func_8002DBA4_2E7A4(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri) {
    Vec n;
    Vec p;
    f32 nx;
    f32 ny;
    f32 nz;
    ColVtx* v = &verts[tri->v[0]];

    p.x = v->x;
    p.y = v->y;
    p.z = v->z;
    func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    return y + (nx * (p.x - x) + ny * (p.y - y) + nz * (p.z - z)) / ny;
}

/* exact c: marioparty func_80029874 (src/29C90.c) */
s32 func_8002DCB4_2E8B4(f32 x, f32 z, s16* poly, ColVtx* verts) {
    Vec n;
    s32 cnt;
    s32 i;
    s32 j;

    func_8002DA3C_2E63C(&verts[poly[1]], &verts[poly[2]], &verts[poly[3]], &n);
    if (n.y == 0.0f) {
        return 0;
    }
    cnt = ((u16)poly[0] >> 14) + 2;
    poly++;
    if (func_8002DB3C_2E73C(x, z, &verts[poly[0]], &verts[poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[poly[i]], &verts[poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[poly[i]], &verts[poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

/* same c: marioparty func_80029AEC (src/29C90.c) */
void func_8002DF2C_2EB2C(HmfModel* m, Matrix4f mtx) {
    Matrix4f tmp;
    HitXform* xf;

    D_800F64C4_F70C4 = m->unk18;
    guMtxL2F(mtx, (Mtx*)((u8*)D_800FD2A8_FDEA8 + D_800FFFD6_100BD6 * 0x80 + 0xF8));
    if (m->pos.x != 0.0f || m->pos.y != 0.0f || m->pos.z != 0.0f) {
        func_80025770_26370(mtx, m->pos.x, m->pos.y, m->pos.z);
    }
    if (m->rot.x != 0.0f || m->rot.y != 0.0f || m->rot.z != 0.0f) {
        func_80025884_26484(mtx, m->rot.x, m->rot.y, m->rot.z);
    }
    if (m->scale.x != 1.0f || m->scale.y != 1.0f || m->scale.z != 1.0f) {
        func_80025830_26430(mtx, m->scale.x, m->scale.y, m->scale.z);
    }
    func_80025BA4_267A4((f32(*)[4])m->mtx, mtx, mtx);
    xf = m->hmf->unk6C;
    guMtxIdentF(tmp);
    if (xf->unk08.x == 0.0f || xf->unk08.y == 0.0f || xf->unk08.z == 0.0f) {
        func_80025770_26370(tmp, xf->unk08.x, xf->unk08.y, xf->unk08.z);
    }
    if (xf->unk14.x == 0.0f || xf->unk14.y == 0.0f || xf->unk14.z == 0.0f) {
        func_80025884_26484(tmp, xf->unk14.x, xf->unk14.y, xf->unk14.z);
    }
    if (xf->unk20.x != 1.0f || xf->unk20.y != 1.0f || xf->unk20.z != 1.0f) {
        func_80025830_26430(tmp, xf->unk20.x, xf->unk20.y, xf->unk20.z);
    }
    guMtxCatF(tmp, mtx, mtx);
    guMtxF2L(mtx, (Mtx*)((u8*)D_800FD83C_FE43C + D_800F928C_F9E8C * 0x40));
}

INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002E1F8_2EDF8);

/* NON_MATCHING: register allocation (view and model swap saved registers, as in MP1; masked 1). */
#ifdef NON_MATCHING
/* MP1 func_8002A0E4 (src/29C90.c, NON_MATCHING there): draw the grid cells inside the view fan.
   MP2 first hands the model's lights to its data. */
void func_8002E544_2F144(HitViewFan* view, HmfModel* m) {
    ColVtx tri[3];
    Matrix4f mtx;
    Matrix4f ident;
    f32* fan;
    s16 gi;
    s32 t;
    s32 x;
    s32 z;
    s32 idx;
    s32 id;
    f32 x0;
    f32 x1;
    f32 z0;
    f32 z1;

    m->hmf->unkD0 = m->unkB4;
    if (m->unkB4 != NULL) {
        func_80026F00_27B00(m->unkB4);
    }
    fan = &view->fov;
    gi = m->unk10;
    func_8002DF2C_2EB2C(m, mtx);
    guMtxIdentF(ident);
    HuMathSin(view->angle);
    t = (D_800FD2B8_FDEB8[gi].w * D_800FD2B8_FDEB8[gi].cw) / 2.0f;
    func_800B7890_B8490(view->angle);
    tri[0].y = tri[1].y = tri[2].y = 0;
    t = (D_800FD2B8_FDEB8[gi].w * D_800FD2B8_FDEB8[gi].cw) / 2.0f + view->x + HuMathSin(view->angle) * fan[2];
    CLAMP_S16(t);
    tri[0].x = t;
    t = (D_800FD2B8_FDEB8[gi].h * D_800FD2B8_FDEB8[gi].ch) / 2.0f + view->z + func_800B7890_B8490(view->angle) * fan[2];
    CLAMP_S16(t);
    tri[0].z = t;
    t = tri[0].x - HuMathSin(fan[0] / 2.0f + view->angle) * fan[1];
    CLAMP_S16(t);
    tri[1].x = t;
    t = tri[0].z - func_800B7890_B8490(fan[0] / 2.0f + view->angle) * fan[1];
    CLAMP_S16(t);
    tri[1].z = t;
    t = tri[0].x - HuMathSin(view->angle - fan[0] / 2.0f) * fan[1];
    CLAMP_S16(t);
    tri[2].x = t;
    t = tri[0].z - func_800B7890_B8490(view->angle - fan[0] / 2.0f) * fan[1];
    CLAMP_S16(t);
    tri[2].z = t;
    for (z = 0; z < D_800FD2B8_FDEB8[gi].h; z++) {
        z0 = z * D_800FD2B8_FDEB8[gi].ch + m->pos.z;
        z1 = z0 + D_800FD2B8_FDEB8[gi].ch;
        for (x = 0; x < D_800FD2B8_FDEB8[gi].w; x++) {
            idx = z * D_800FD2B8_FDEB8[gi].w + x;
            x0 = x * D_800FD2B8_FDEB8[gi].cw + m->pos.x;
            x1 = x0 + D_800FD2B8_FDEB8[gi].cw;
            id = D_800FD2B8_FDEB8[gi].map0[idx];
            if (id != -1 && (func_8002EC00_2F800(x0, z0, tri) == 1 || func_8002EC00_2F800(x1, z0, tri) == 1 ||
                             func_8002EC00_2F800(x0, z1, tri) == 1 || func_8002EC00_2F800(x1, z1, tri) == 1)) {
                func_80031FD8_32BD8(m->hmf, id, (u8*)D_800FD83C_FE43C + D_800F928C_F9E8C * 0x40, ident);
            }
            id = D_800FD2B8_FDEB8[gi].map1[idx];
            if (id != -1 && (func_8002EC00_2F800(x0, z0, tri) == 1 || func_8002EC00_2F800(x1, z0, tri) == 1 ||
                             func_8002EC00_2F800(x0, z1, tri) == 1 || func_8002EC00_2F800(x1, z1, tri) == 1)) {
                func_80031FD8_32BD8(m->hmf, id, (u8*)D_800FD83C_FE43C + D_800F928C_F9E8C * 0x40, mtx);
            }
            id = D_800FD2B8_FDEB8[gi].map2[idx];
            if (id != -1 && (func_8002EC00_2F800(x0, z0, tri) == 1 || func_8002EC00_2F800(x1, z0, tri) == 1 ||
                             func_8002EC00_2F800(x0, z1, tri) == 1 || func_8002EC00_2F800(x1, z1, tri) == 1)) {
                func_80031FD8_32BD8(m->hmf, id, (u8*)D_800FD83C_FE43C + D_800F928C_F9E8C * 0x40, mtx);
            }
        }
    }
    D_800F928C_F9E8C++;
}
#else
INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002E544_2F144);
#endif

/* exact c: marioparty func_8002A784 (src/29C90.c) */
s32 func_8002EC00_2F800(f32 x, f32 z, ColVtx* v) {
    s32 i;
    s32 j;
    f32 f;

    if (func_8002DB3C_2E73C(x, z, &v[0], &v[1]) > 0.0f) {
        for (i = 1; i < 3; i++) {
            j = (i + 1) % 3;
            f = func_8002DB3C_2E73C(x, z, &v[i], &v[j]);
            if (f == 0.0f) {
                return 1;
            }
            if (f < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < 3; i++) {
            j = (i + 1) % 3;
            f = func_8002DB3C_2E73C(x, z, &v[i], &v[j]);
            if (f == 0.0f) {
                return 1;
            }
            if (f > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002EDA8_2F9A8);

/* exact c: marioparty func_8002AD04 (src/29C90.c) */
void func_8002F1A4_2FDA4(void) {
    func_80027274_27E74(0x55F0);
    D_800DEFA0_DFBA0 = 0;
    D_800DEFA2_DFBA2 = 0;
}

/* exact c: marioparty func_8002AD30 (src/29C90.c) */
void func_8002F1D0_2FDD0(s16 idx) {
    HitGrid* g;

    if (D_800DEFA2_DFBA2 != 0) {
        g = &D_800FD2B8_FDEB8[idx];
        HuMemFree(g->cells);
        HuMemFree(g->map0);
        HuMemFree(g->map1);
        HuMemFree(g->map2);
        HuMemFree(g->polys);
        D_800DEFA2_DFBA2--;
        D_800DEFA8_DFBA8[idx] = D_800DEFA4_DFBA4;
        D_800DEFA4_DFBA4 = idx;
    }
}

/* exact c: marioparty func_8002ADF0 (src/29C90.c) */
void func_8002F290_2FE90(s32* arg0, s32 n) {
    ((HitList*)arg0)->list = func_80027154_27D54((u16)n * sizeof(u16*), 0x55F0);
}

/* MP1 func_8002AE24 (NON_MATCHING there too): the HitList copy of arg1 is scheduled after the
   stores of a2/a3 in retail; with l as the parameter the order matches but s7/s8 swap. */
#ifdef NON_MATCHING
void func_8002F2C4_2FEC4(s16 mi, HitList* l, s32 (*cb)(s32, u16*, ColVtx*, HitProbe*), HitProbe* probe) {
    s32 x0;
    s32 z1;
    HmfData* mdl;
    HmfModel* m;
    HitGrid* g;
    HitCell* cell;
    u16** out;
    u16* p;
    s32 x1;
    s32 z0;
    s32 x;
    s32 z;
    s32 i;

    l->pos = 0;
    l->count = 0;
    mdl = (D_800FC834_FD434 + mi)->hmf;
    m = D_800FC834_FD434 + mi;
    g = &D_800FD2B8_FDEB8[m->unk10];
    x = ((g->w * g->cw) / 2.0f + probe->x) / g->cw;
    z = ((g->h * g->ch) / 2.0f + probe->z) / g->ch;
    x0 = x - 1;
    x1 = x + 2;
    z0 = z - 1;
    z1 = z + 2;
    if (x0 < 0) {
        x0 = 0;
    }
    if (z0 < 0) {
        z0 = 0;
    }
    if (g->w < x1) {
        x1 = g->w;
    }
    if (g->h < z1) {
        z1 = g->h;
    }
    out = l->list;
    for (z = z0; z < z1; z++) {
        for (x = x0; x < x1; x++) {
            cell = &g->cells[z * g->w + x];
            if (cell->count != 0) {
                p = &g->polys[cell->offset];
                for (i = 0; i < cell->count; i++) {
                    if (cb((*p >> 14) + 2, p + 1, mdl->unk54, probe) != 0) {
                        *out++ = p;
                        l->count++;
                    }
                    p += (*p >> 14) + 3;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002F2C4_2FEC4);
#endif

/* exact c: marioparty func_8002B074 (src/29C90.c) */
s32 func_8002F514_30114(u16 n, s16* idx, ColVtx* verts, HitProbe* probe) {
    f32 cx;
    f32 cz;
    f32 r;

    if (n == 4) {
        r = func_8002F648_30248(verts, idx[0], idx[2], idx[3], &cx, &cz) + probe->r;
        cx -= probe->x;
        cz -= probe->z;
        if (cx * cx + cz * cz < r * r) {
            return 1;
        }
    }
    r = func_8002F648_30248(verts, idx[0], idx[1], idx[2], &cx, &cz) + probe->r;
    cx -= probe->x;
    cz -= probe->z;
    return cx * cx + cz * cz < r * r;
}

/* exact c: marioparty func_8002B1A8 (src/29C90.c) */
f32 func_8002F648_30248(ColVtx* verts, s16 a, s16 b, s16 c, f32* cx, f32* cz) {
    f32 dx;
    f32 dz;
    f32 ex;
    f32 ez;

    *cx = (verts[a].x + verts[b].x + verts[c].x) / 3;
    *cz = (verts[a].z + verts[b].z + verts[c].z) / 3;
    dx = verts[a].x - *cx;
    dz = verts[a].z - *cz;
    ex = verts[b].x - *cx;
    ez = verts[b].z - *cz;
    if (dx * dx + dz * dz < ex * ex + ez * ez) {
        dx = ex;
        dz = ez;
    }
    ex = verts[c].x - *cx;
    ez = verts[c].z - *cz;
    if (dx * dx + dz * dz < ex * ex + ez * ez) {
        dx = ex;
        dz = ez;
    }
    return func_800B1830_B2430(dx * dx + dz * dz);
}

/* exact c: marioparty func_8002B3A8 (src/29C90.c) */
u16* func_8002F848_30448(HitList* l) {
    if (l->pos != l->count) {
        return l->list[l->pos++];
    }
    return NULL;
}

/* exact c: marioparty func_8002B3DC (src/29C90.c) */
void func_8002F87C_3047C(HitList* l, s32 off, u16 mode) {
    s32 t;

    switch (mode) {
        case 0:
            if (off >= 0 && off + l->pos < l->count) {
                l->pos = off;
            }
            break;
        case 1:
            if (off + l->pos >= 0 && off + l->pos < l->count) {
                l->pos += off;
            }
            break;
        case 2:
            if (off <= 0 && off + l->pos >= 0) {
                t = off + 0xFFFF; /* == off - 1 as a u16 */
                l->pos = l->count + t;
            }
            break;
    }
}

/* exact c: marioparty func_8002B498 (src/29C90.c) */
void func_8002F938_30538(HitList* l) {
    HuMemFree(l->list);
}
