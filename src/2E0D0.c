#include "common.h"

/* Model collision grids and matrix helpers. Same code as Mario Party 1's src/29C90.c (MP1 names in
   the comments); func_8002D5B4, func_8002E1F8, func_8002E544 and func_8002EDA8 have no MP1 C
   equivalent and stay asm. MP2's model struct has MP3's layout (HmfModel, size 0xC0). */

typedef f32 Matrix4f[4][4];

typedef struct ColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} ColVtx;

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
typedef struct HitXform {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec unk_08;
    /* 0x14 */ Vec unk_14;
    /* 0x20 */ Vec unk_20;
} HitXform;

/* MP3 HmfData / MP1 unk2C0C0StructC0 (only the fields used here). */
typedef struct HmfData {
    /* 0x00 */ char unk_00[0x54];
    /* 0x54 */ ColVtx* unk_54; /* MP1 unk_78 */
    /* 0x58 */ char unk_58[0x14];
    /* 0x6C */ HitXform* unk_6C; /* MP1 unk_88 */
} HmfData;

/* MP3 HmfModel / MP1 unk_ovl_2D_struct. */
typedef struct HmfModel {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s16 unk_10; /* hit grid; MP1 unk_04 */
    /* 0x12 */ char unk_12[6];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[0x24];
    /* 0x64 */ HmfData* unk_64;
    /* 0x68 */ char unk_68[0xC];
    /* 0x74 */ Matrix4f unk_74;
    /* 0xB4 */ char unk_B4[0xC];
} HmfModel; /* size = 0xC0 */

extern s16 D_800DEFA0_DFBA0;
extern s16 D_800DEFA2_DFBA2;
extern s16 D_800DEFA4_DFBA4;
extern s16* D_800DEFA8_DFBA8;
extern HitGrid* D_800FD2B8_FDEB8;
extern HmfModel* D_800FC834_FD434;
extern s32 D_800F64C4_F70C4;
extern void* D_800FD2A8_FDEA8;
extern s16 D_800FFFD6_100BD6;
extern void* D_800FD83C_FE43C;
extern s16 D_800F928C_F9E8C;

void* func_80027154_27D54(s32, s16);
void func_800271D8_27DD8(void*);
void func_80027274_27E74(s16);
void func_80025770_26370(Matrix4f, f32, f32, f32); /* MP1 MtxTranslate */
void func_80025830_26430(Matrix4f, f32, f32, f32); /* MP1 MtxScale */
void func_80025884_26484(Matrix4f, f32, f32, f32); /* MP1 MtxRotate */
void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f); /* MP1 MtxMult */
f32 func_800B1830_B2430(f32);
s32 func_8002D9AC_2E5AC(Vec*);
f32 func_8002F648_30248(ColVtx*, s16, s16, s16, f32*, f32*);
s32 func_8002EC00_2F800(f32, f32, ColVtx*);

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

INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002D5B4_2E1B4);

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

    D_800F64C4_F70C4 = m->unk_18;
    guMtxL2F(mtx, (Mtx*)((u8*)D_800FD2A8_FDEA8 + D_800FFFD6_100BD6 * 0x80 + 0xF8));
    if (m->unk_1C != 0.0f || m->unk_20 != 0.0f || m->unk_24 != 0.0f) {
        func_80025770_26370(mtx, m->unk_1C, m->unk_20, m->unk_24);
    }
    if (m->unk_28 != 0.0f || m->unk_2C != 0.0f || m->unk_30 != 0.0f) {
        func_80025884_26484(mtx, m->unk_28, m->unk_2C, m->unk_30);
    }
    if (m->unk_34 != 1.0f || m->unk_38 != 1.0f || m->unk_3C != 1.0f) {
        func_80025830_26430(mtx, m->unk_34, m->unk_38, m->unk_3C);
    }
    func_80025BA4_267A4(m->unk_74, mtx, mtx);
    xf = m->unk_64->unk_6C;
    guMtxIdentF(tmp);
    if (xf->unk_08.x == 0.0f || xf->unk_08.y == 0.0f || xf->unk_08.z == 0.0f) {
        func_80025770_26370(tmp, xf->unk_08.x, xf->unk_08.y, xf->unk_08.z);
    }
    if (xf->unk_14.x == 0.0f || xf->unk_14.y == 0.0f || xf->unk_14.z == 0.0f) {
        func_80025884_26484(tmp, xf->unk_14.x, xf->unk_14.y, xf->unk_14.z);
    }
    if (xf->unk_20.x != 1.0f || xf->unk_20.y != 1.0f || xf->unk_20.z != 1.0f) {
        func_80025830_26430(tmp, xf->unk_20.x, xf->unk_20.y, xf->unk_20.z);
    }
    guMtxCatF(tmp, mtx, mtx);
    guMtxF2L(mtx, (Mtx*)((u8*)D_800FD83C_FE43C + D_800F928C_F9E8C * 0x40));
}

INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002E1F8_2EDF8);

INCLUDE_ASM("asm/nonmatchings/2E0D0", func_8002E544_2F144);

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
        func_800271D8_27DD8(g->cells);
        func_800271D8_27DD8(g->map0);
        func_800271D8_27DD8(g->map1);
        func_800271D8_27DD8(g->map2);
        func_800271D8_27DD8(g->polys);
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
    mdl = (D_800FC834_FD434 + mi)->unk_64;
    m = D_800FC834_FD434 + mi;
    g = &D_800FD2B8_FDEB8[m->unk_10];
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
                    if (cb((*p >> 14) + 2, p + 1, mdl->unk_54, probe) != 0) {
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
    func_800271D8_27DD8(l->list);
}
