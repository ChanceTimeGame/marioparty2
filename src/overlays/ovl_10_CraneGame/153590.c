#include "ovl_10.h"

#define CG_ABS(x) ((x) < 0.0f ? -(x) : (x))


void func_80109A70_153590_CraneGame(void) {
    D_8010CE08_156928_CraneGame = 0;
    D_8010CB00_156620_CraneGame = func_8002838C_28F8C(0, func_80109C00_153720_CraneGame, 2);
}

void func_80109AA8_1535C8_CraneGame(void) {
    CGColGroup* g;
    void* p;
    s32 i;
    s32 j;

    if (D_8010CE08_156928_CraneGame != 0) {
        for (i = 0; i < D_8010CE08_156928_CraneGame; i++) {
            g = D_8010CB08_156628_CraneGame[i].groups;
            for (j = 0; j < D_8010CB08_156628_CraneGame[i].count; j++) {
                p = g->faces;
                g++;
                HuMemMemoryFreePerm(p);
            }
            HuMemMemoryFreePerm(D_8010CB08_156628_CraneGame[i].groups);
            HuMemMemoryFreePerm(D_8010CB08_156628_CraneGame[i].verts);
        }
    }
    D_8010CE08_156928_CraneGame = 0;
    func_800283DC_28FDC(D_8010CB00_156620_CraneGame);
}

void func_80109BAC_1536CC_CraneGame(s16 model) {
    func_80109E48_153968_CraneGame(&D_8010CB08_156628_CraneGame[D_8010CE08_156928_CraneGame], model);
    D_8010CE08_156928_CraneGame++;
}

/* The draw-pass callback: refreshes each group's world-to-group matrix. */
void func_80109C00_153720_CraneGame(Gfx** gfx, Mtx* mtx) {
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f inv;
    CGCol* e;
    HmfModel* p;
    HmfData* m;
    CGColGroup* g;
    HmfPart* part;
    s32 i;
    s32 j;

    func_800B30D0_B3CD0(m1, mtx + 1);
    func_800B1F50_B2B50(m2, -m1[3][0], -m1[3][1], -m1[3][2]);
    func_80025F00_26B00(m1, inv);
    func_800B6410_B7010(m2, inv, inv);
    for (i = 0; i < D_8010CE08_156928_CraneGame; i++) {
        e = &D_8010CB08_156628_CraneGame[i];
        p = &D_800FC834_FD434[e->model];
        if (p->hmf != NULL && !(p->unk18 & 4)) {
            m = p->hmf;
            if (e->unk2 != 0) {
                e->unk2--;
            }
            for (j = 0; j < (m->unk10 & 0x3F); j++) {
                part = &m->unk64[j];
                g = &e->groups[j];
                func_800B30D0_B3CD0(m1, D_800F8C58_F9858[D_800FDC48_FE848[m->unk00][part->unk2F].unk02].unk44);
                func_800B6410_B7010(m1, inv, m1);
                func_80025F00_26B00(m1, m2);
                func_800B1F50_B2B50(m1, -m1[3][0], -m1[3][1], -m1[3][2]);
                func_800B6410_B7010(m1, m2, g->mtx);
            }
        }
    }
}

/* MP1 func_800FD604 (NON_MATCHING there too, masked 0). Retail stores the group count from the low
   byte of unk10 (a byte read at +1). Residue: retail keeps the vertex count and the group count in
   s0 (register allocation). */
#ifdef NON_MATCHING
/* Registers a model for collision: copies its vertices and builds each group's face planes. */
void func_80109E48_153968_CraneGame(CGCol* e, s16 model) {
    HmfData* m;
    HmfPart* part;
    CGColGroup* g;
    s32 size;
    s32 i;

    m = D_800FC834_FD434[model].hmf;
    e->model = model;
    e->unk2 = 4;
    size = m->unk14 * sizeof(ColVtx);
    e->verts = HuMemMemoryAllocPerm(size);
    bcopy(m->unk54, e->verts, size);
    e->count = (u8)m->unk10;
    e->groups = HuMemMemoryAllocPerm(e->count * sizeof(CGColGroup));
    for (i = 0; i < m->unk10; i++) {
        part = &m->unk64[i];
        g = &e->groups[i];
        g->radius = sqrtf(part->unk48 * part->unk48 + part->unk4A * part->unk4A + part->unk4C * part->unk4C);
        g->n = part->unk04;
        g->faces = HuMemMemoryAllocPerm(g->n * sizeof(CGColFace));
        func_80109FF8_153B18_CraneGame(e->verts, g->faces, part->unk54, g->n);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_80109E48_153968_CraneGame);
#endif

/* The plane (unit normal, distance) and dominant axis of each face. */
void func_80109FF8_153B18_CraneGame(ColVtx* verts, CGColFace* out, HmfFaceRec* f, s16 n) {
    Vec p;
    Vec e1;
    Vec e2;
    f32 inv;
    s32 i;
    s32 j;

    for (i = 0; i < n; out++, i++, f++) {
        for (j = 0; j < 4; j++) {
            out->v[j] = f->unk04[j];
        }
        if ((f->unk00 & 7) < 4U) {
            out->v[3] = -1;
        }
        p.x = verts[out->v[1]].x;
        e1.x = verts[out->v[0]].x - p.x;
        e2.x = verts[out->v[2]].x - p.x;
        p.y = verts[out->v[1]].y;
        e1.y = verts[out->v[0]].y - p.y;
        e2.y = verts[out->v[2]].y - p.y;
        p.z = verts[out->v[1]].z;
        e1.z = verts[out->v[0]].z - p.z;
        e2.z = verts[out->v[2]].z - p.z;
        out->nx = e1.y * e2.z - e1.z * e2.y;
        out->ny = e1.z * e2.x - e1.x * e2.z;
        out->nz = e1.x * e2.y - e1.y * e2.x;
        inv = 1.0 / sqrtf(out->nx * out->nx + out->ny * out->ny + out->nz * out->nz);
        out->nx = inv * out->nx;
        out->ny = inv * out->ny;
        out->nz = inv * out->nz;
        out->d = -(p.x * out->nx + p.y * out->ny + p.z * out->nz);
        if (CG_ABS(out->nx) >= CG_ABS(out->ny)) {
            out->axis = (CG_ABS(out->nx) >= CG_ABS(out->nz)) ? 0 : 2;
        } else {
            out->axis = (CG_ABS(out->ny) >= CG_ABS(out->nz)) ? 1 : 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A43C_153F5C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A4D8_153FF8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A798_1542B8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A8E8_154408_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010AD5C_15487C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010AE2C_15494C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010B364_154E84_CraneGame);
