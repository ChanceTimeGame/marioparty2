#include "ovl_3C.h"

void func_80105EB0_294F20_DeepSeaSalvage(void) {
    D_800FA610_FB210 = 8000.0f;
    D_800FD474_FE074.x = 2.9249f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 200.0f;
    D_8010274C_10334C.z = -110.0f;
}

void func_80105F14_294F84_DeepSeaSalvage(void) {
    s16 i;

    D_80108E90_297F00_DeepSeaSalvage = 0;
    for (i = 0; i < 256; i++) {
        D_8010A7F0_299860_DeepSeaSalvage[i] = NULL;
    }
}

/* An extra work block for obj; retail packs its address into obj->work[0..3] (a host pointer
   does not fit there). */
DSSWork* func_80105F5C_294FCC_DeepSeaSalvage(omObjData* obj) {
    DSSWork* w;

    w = HuMemMemoryAllocPerm(sizeof(DSSWork));
    D_8010A7F0_299860_DeepSeaSalvage[D_80108E90_297F00_DeepSeaSalvage] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->unkA = D_80108E90_297F00_DeepSeaSalvage;
    w->unkC = w->unk10 = w->unk14 = 0.0f;
    w->unk18 = w->unk1C = w->unk20 = 0.0f;
    w->unk24 = w->unk28 = w->unk2C = 0.0f;
    w->unk3C = w->unk3E = w->unk40 = w->unk42 = 0;
    w->unk44 = w->unk46 = w->unk48 = w->unk4A = 0;
    w->unk4C = w->unk4E = w->unk50 = w->unk52 = 0;
    w->unk54 = w->unk56 = w->unk58 = w->unk5A = 0;
    D_80108E90_297F00_DeepSeaSalvage++;
    return w;
}

void func_80106048_2950B8_DeepSeaSalvage(void) {
    s16 i;

    for (i = 0; i < D_80108E90_297F00_DeepSeaSalvage; i++) {
        if (D_8010A7F0_299860_DeepSeaSalvage[i] != NULL) {
            HuMemMemoryFreePerm(D_8010A7F0_299860_DeepSeaSalvage[i]);
        }
    }
}

u32 func_801060C8_295138_DeepSeaSalvage(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}

u16 func_80106100_295170_DeepSeaSalvage(u16 n) {
    return (func_801060C8_295138_DeepSeaSalvage() * n) >> 16;
}

/* Keep a point inside the play area. */
void func_80106134_2951A4_DeepSeaSalvage(f32* x, f32* y, f32* z) {
    if (*x < -712.0f) {
        *x = -712.0f;
    }
    if (*x > 712.0f) {
        *x = 712.0f;
    }
    if (*y > 380.0f) {
        *y = 380.0f;
    }
    if (*y < -372.0f) {
        *y = -372.0f;
    }
}

/* Push (x, y) out of the sea floor: the normal of the polyline pts (the points where a circle of
   radius dist crosses an outline), dist from the points' centre (MP1 func_800FC2F8). */
void func_801061CC_29523C_DeepSeaSalvage(f32* x, f32* y, f32 dist, DSSPoint* pts, s16 n, s16 flag, f32* outx, f32* outy) {
    f32 cx;
    f32 cy;
    f32 px;
    f32 py;
    f32 a;
    f32 b;
    f32 dy;
    f32 len;
    f32 nx;
    f32 ny;
    s16 i;

    if (n >= 2) {
        cy = 0.0f;
        cx = 0.0f;
        for (i = 0; i < n; i++) {
            cx += pts[i].x;
            cy += pts[i].y;
        }
        cx /= (f32)n;
        cy /= (f32)n;
        px = pts[0].x;
        py = pts[0].y;
        ny = 0.0f;
        nx = 0.0f;
        for (i = 0; i < n - 1; i++) {
            dy = pts[i + 1].y - py;
            a = -dy;
            b = pts[i + 1].x - px;
            if (a * (*x - cx) + b * (*y - cy) < 0.0) {
                a = dy;
                b = -b;
            }
            len = sqrtf(a * a + b * b);
            if (len != 0.0) {
                a /= len;
                b /= len;
                nx += a;
                ny += b;
            }
            px = pts[i + 1].x;
            py = pts[i + 1].y;
        }
        if (flag != 0 && ny < 0.0) {
            nx = 2.0 * nx;
            len = sqrtf(nx * nx + ny * ny);
            nx = nx / len;
            ny /= len;
        }
        *outx = nx;
        *outy = ny;
        len = sqrtf(nx * nx + ny * ny);
        if (len != 0.0) {
            nx /= len;
            ny /= len;
            *x = cx + nx * dist;
            *y = cy + ny * dist;
        }
    }
}

/* Where a circle of radius r around (x, y) crosses the sea floor's two outlines (D_8010862C, in
   units of 5, 180 down), push (x, y) out along the normal; the number of crossings (MP1
   func_800FC644). */
/* NON_MATCHING: one register copy (retail starts i from total's register, `move s5,s3`;
   GCC loads zero); masked 0. */
#ifdef NON_MATCHING
s16 func_80106518_295588_DeepSeaSalvage(f32* x, f32* y, s16 r, s16 flag, f32* outx, f32* outy) {
    DSSPoint pts[256];
    Vec* line;
    f32 px;
    f32 py;
    f32 dx;
    f32 dy;
    f32 ox;
    f32 oy;
    f32 a;
    f32 b;
    f32 c;
    f32 disc;
    f32 t0;
    f32 t1;
    s16 n = 0;
    s16 total = 0;
    s16 i;
    s16 m;
    s8 j;
    s8 k;

    px = *x;
    py = *y;
    for (i = 0; i < 2; i++) {
        line = D_8010862C_29769C_DeepSeaSalvage[i];
        for (m = 0; m < D_80108634_2976A4_DeepSeaSalvage[i]; m++) {
            j = m;
            k = j + 1;
            k = (k < D_80108634_2976A4_DeepSeaSalvage[i]) ? k : 0;
            dx = (line[k].x - line[j].x) * 5.0;
            dy = (line[k].y - line[j].y) * 5.0;
            ox = line[j].x * 5.0 - px;
            oy = line[j].y * 5.0 + -180.0 - py;
            a = dx * dx + dy * dy;
            b = 2.0f * (dx * ox + dy * oy);
            c = (f32)-(r * r) + ox * ox + oy * oy;
            disc = b * b - a * 4.0 * c;
            if (disc > 0.0f) {
                disc = sqrtf(disc);
                t0 = (-b - disc) / (2.0f * a);
                t1 = (-b + disc) / (2.0f * a);
                if (t0 >= 0.0 && t0 <= 1.0) {
                    pts[n].x = line[j].x * 5.0 + t0 * dx;
                    pts[n].y = line[j].y * 5.0 + -180.0 + t0 * dy;
                    n++;
                    total++;
                }
                if (t1 >= 0.0 && t1 <= 1.0) {
                    pts[n].x = line[j].x * 5.0 + t1 * dx;
                    pts[n].y = line[j].y * 5.0 + -180.0 + t1 * dy;
                    n++;
                    total++;
                }
            }
        }
        if (n >= 2) {
            func_801061CC_29523C_DeepSeaSalvage(x, y, r, pts, n, flag, outx, outy);
            n -= 2;
        }
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106518_295588_DeepSeaSalvage);
#endif

/* The height of the sea floor's highest edge under (x, y), -372 if none (MP1 func_800FCAE8). */
f32 func_801069E4_295A54_DeepSeaSalvage(f32 x, f32 y) {
    Vec* pts;
    s16 found = 0;
    f32 best = -9999.0f;
    f32 h;
    f32 t;
    f32 d;
    s16 i;
    s16 m;
    s8 j;
    s8 k;

    for (i = 0; i < 2; i++) {
        pts = D_8010862C_29769C_DeepSeaSalvage[i];
        for (m = 0; m < D_80108634_2976A4_DeepSeaSalvage[i]; m++) {
            j = m;
            k = j + 1;
            k = (k < D_80108634_2976A4_DeepSeaSalvage[i]) ? k : 0;
            if ((pts[j].x * 5.0 <= x && x < pts[k].x * 5.0) || (x < pts[j].x * 5.0 && pts[k].x * 5.0 <= x)) {
                d = pts[k].x - pts[j].x;
                if (d != 0.0) {
                    t = (x - pts[j].x * 5.0) / (d * 5.0);
                    h = pts[j].y * 5.0 + -180.0 + t * (pts[k].y - pts[j].y) * 5.0;
                    if (((d >= 0.0f) & (h <= y)) && best < h) {
                        best = h;
                        found = 1;
                    }
                }
            }
        }
    }
    if (found != 0) {
        return best;
    }
    return -372.0f;
}

s16 func_80106CC4_295D34_DeepSeaSalvage(f32 x, f32 y) {
    DSSTreasure* t;
    f32 dx;
    f32 dy;
    s16 i;

    t = DSS_OBJ_WORK(D_80108EB8_297F28_DeepSeaSalvage);
    for (i = 0; i < 20; i++, t++) {
        if (t->flags < 0 && t->taken == 0) {
            dx = t->x - x;
            dy = t->y - y;
            if (dx * dx + dy * dy < 7400.0f) {
                return i;
            }
        }
    }
    return -1;
}

/* Push a diver out of the others (radius 90 each); vx and vy are unused. */
void func_80106D5C_295DCC_DeepSeaSalvage(omObjData* obj, f32 vx, f32 vy) {
    DSSDiver* d;
    DSSDiver* o;
    omObjData* other;
    f32 dx;
    f32 dy;
    f32 dist;
    f32 r0;
    f32 r1;
    f32 push;
    f32 nx;
    f32 ny;
    s16 i;

    d = DSS_OBJ_WORK(obj);
    r0 = 90.0f;
    for (i = 0; i < 4; i++) {
        other = D_800FFFD8_100BD8[i];
        o = DSS_OBJ_WORK(other);
        if (obj == other) {
            continue;
        }
        dx = o->x - d->x;
        dy = o->y - d->y;
        r1 = 90.0f;
        dist = sqrtf(dx * dx + dy * dy);
        if (dist < r0 + r1) {
            if (dist != 0.0) {
                dx /= dist;
                dy /= dist;
            }
            push = r0 + r1 - dist;
            nx = d->x - dx * push;
            ny = d->y - dy * push;
            d->x = nx;
            d->y = ny;
        }
    }
}

/* A sprite file's first animation number (MP1 TreasureDivers func_800FBAC8). */
s16 func_80106EC4_295F34_DeepSeaSalvage(s32 file) {
    void* data = DataRead(file);
    s16 anim = SprAnimRead(data);

    DataClose(data);
    return anim & 0xFF;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106F08_295F78_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801070D0_296140_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801072C0_296330_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80107318_296388_DeepSeaSalvage);
