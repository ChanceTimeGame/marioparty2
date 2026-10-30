#include "ovl_0C.h"

/* Sets up the lights and the floor and torch objects (MP1 func_800FB260). */
void func_80107FB0_133BA0_HotRopeJump(void) {
    HRJLight* l;
    s32 i;

    l = D_80111420_13D010_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        l->used = 0;
        l->z = 0;
        l->y = 0;
        l->x = 0;
        l->radius = l->aspect = l->radiusSq = 0;
        l->fadeFrom = l->fade = l->fadeTime = 0;
    }
    D_8011182C_13D41C_HotRopeJump = 0;
    D_80111830_13D420_HotRopeJump = 1.0f;
    omAddObj(10, 3, 0, -1, func_801085B4_1341A4_HotRopeJump);
    omAddObj(8, 2, 0, -1, func_801096E4_1352D4_HotRopeJump);
    omAddObj(9, 13, 0, -1, func_8010A0F0_135CE0_HotRopeJump);
    func_80026D28_27928(4);
    func_80026DAC_279AC(4, 0, 0, 0);
}

void func_801080A0_133C90_HotRopeJump(void) {
    HuMemFree(D_80111920_13D510_HotRopeJump);
    HuMemFree(D_80111924_13D514_HotRopeJump);
    func_80023D74_24974((s32)D_80111918_13D508_HotRopeJump[0]); /* a pointer (host) */
}

/* The scene lights (MP1 func_800FB354): while the blend changes, the ambient colour and light 3
   move between their two colours (and the lit place-3 player follows light 3); light 3 points
   along the rope's angle. */
void func_801080D8_133CC8_HotRopeJump(f32 angle) {
    Matrix4f m;
    Vec v;
    HuCamera* c;

    c = D_800C9B80_CA780;
    if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        D_80111410_13D000_HotRopeJump[0] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A0_137F90_HotRopeJump[0][0], D_8010C3A4_137F94_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[1] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A1_137F91_HotRopeJump, D_8010C3A5_137F95_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[2] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A2_137F92_HotRopeJump, D_8010C3A6_137F96_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[3] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A8_137F98_HotRopeJump, D_8010C3AC_137F9C_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[4] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A9_137F99_HotRopeJump, D_8010C3AD_137F9D_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[5] = func_8010BF04_137AF4_HotRopeJump(D_8010C3AA_137F9A_HotRopeJump, D_8010C3AE_137F9E_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        func_80026DAC_279AC(0, D_80111410_13D000_HotRopeJump[0], D_80111410_13D000_HotRopeJump[1], D_80111410_13D000_HotRopeJump[2]);
        func_80026DAC_279AC(3, D_80111410_13D000_HotRopeJump[3], D_80111410_13D000_HotRopeJump[4], D_80111410_13D000_HotRopeJump[5]);
        if (D_80111928_13D518_HotRopeJump != -1) {
            func_8002D274_2DE74((s16)D_80111928_13D518_HotRopeJump, D_80111410_13D000_HotRopeJump[3], D_80111410_13D000_HotRopeJump[4], D_80111410_13D000_HotRopeJump[5]);
        }
    }
    func_80026DAC_279AC(2, 0, 0, 0);
    func_800B1960_B2560(m, c->pos.x, c->pos.y, c->pos.z, c->at.x, c->at.y, c->at.z, c->up.x, c->up.y, c->up.z);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    func_8010C074_137C64_HotRopeJump(m, func_800B7890_B8490(angle) * 100.0, HuMathSin(angle) * 100.0, 0.0f, &v);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, 0.0f, 0.0f, -100.0f);
    func_80026E00_27A00(3, v.x, v.y, v.z);
}

/* The floor object's setup (MP1 func_800FB494): floor, its sprite and the two rope models. */
void func_801085B4_1341A4_HotRopeJump(omObjData* obj) {
    obj->func_ptr = func_801086AC_13429C_HotRopeJump;
    omSetStatBit(obj, 0xA0);
    D_80111824_13D414_HotRopeJump = func_8001A2F8_1AEF8(0x1D0002);
    obj->model[0] = func_80109078_134C68_HotRopeJump();
    obj->model[1] = LoadFormFile(0x1D0000, 0x219);
    D_800FC834_FD434[obj->model[1]].unk44 = 0.5f;
    obj->model[2] = LoadFormFile(0x1D0001, 0x219);
    D_800FC834_FD434[obj->model[2]].unk44 = 1.5f;
    D_80111918_13D508_HotRopeJump[0] = func_80105570_131160_HotRopeJump(obj->model[2], 2);
}

/* The floor object (MP1 func_800FB4E0): animates model 2, eases the light blend toward its
   target by 0.05 a frame, and updates the lights. */
void func_801086AC_13429C_HotRopeJump(omObjData* obj) {
    HmfModel* m;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        m = &D_800FC834_FD434[obj->model[2]];
        m->unk40 += m->unk44;
        if (m->unk40 >= 20.0) {
            m->unk40 = 0.0f;
        }
        func_80023A08_24608(obj->model[2], D_80111918_13D508_HotRopeJump[0], m->unk40);
        if (D_8010C260_137E50_HotRopeJump > D_8010C264_137E54_HotRopeJump) {
            D_8010C260_137E50_HotRopeJump -= 0.05;
        } else if (D_8010C260_137E50_HotRopeJump < D_8010C264_137E54_HotRopeJump) {
            D_8010C260_137E50_HotRopeJump += 0.05;
        }
        if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
            D_8010C26C_137E5C_HotRopeJump = 0.9 - D_8010C260_137E50_HotRopeJump * 0.4;
        }
        func_801080D8_133CC8_HotRopeJump(D_80111920_13D510_HotRopeJump[6].angle);
    }
    func_8010BB48_137738_HotRopeJump(D_8010C260_137E50_HotRopeJump);
    if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        D_8010C268_137E58_HotRopeJump = D_8010C260_137E50_HotRopeJump;
    }
}

/* Takes a free floor light (MP1 func_800FB504); -1 when all 32 are used. */
s16 func_80108850_134440_HotRopeJump(f32 x, f32 y, f32 z, f32 radius) {
    HRJLight* l;
    s32 i;

    l = D_80111420_13D010_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        if (l->used == 0) {
            break;
        }
    }
    if (i < 32) {
        l->used = 1;
        func_80108918_134508_HotRopeJump(i, x, y, z);
        func_80108978_134568_HotRopeJump(i, radius, radius);
        D_80111820_13D410_HotRopeJump++;
    } else {
        i = -1;
    }
    return i;
}

void func_80108918_134508_HotRopeJump(s16 id, f32 x, f32 y, f32 z) {
    D_80111420_13D010_HotRopeJump[id].x = x;
    D_80111420_13D010_HotRopeJump[id].y = y;
    D_80111420_13D010_HotRopeJump[id].z = z;
}

void func_80108978_134568_HotRopeJump(s16 id, f32 radius, f32 h) {
    D_80111420_13D010_HotRopeJump[id].radius = radius;
    D_80111420_13D010_HotRopeJump[id].aspect = radius / h;
    D_80111420_13D010_HotRopeJump[id].radiusSq = radius * radius;
    D_80111420_13D010_HotRopeJump[id].used = 1;
}

void func_801089D4_1345C4_HotRopeJump(s16 id) {
    D_80111420_13D010_HotRopeJump[id].used = 0;
}

/* Starts a light's fade over `time` frames (func_80108A44 shrinks it), unless one is running. */
void func_801089EC_1345DC_HotRopeJump(s16 id, s32 time) {
    if (D_80111420_13D010_HotRopeJump[id].fadeTime == 0) {
        D_80111420_13D010_HotRopeJump[id].fade = time;
        D_80111420_13D010_HotRopeJump[id].fadeTime = time;
        D_80111420_13D010_HotRopeJump[id].fadeFrom = D_80111420_13D010_HotRopeJump[id].radius;
    }
}

/* The floor's draw callback (MP1 func_800FB6B4): blends the light colour, runs the lights'
   fades, lights each flagged vertex by the lights over it, then draws the floor.
   Retail quirk kept: a fade sets the radius to (fade / fadeTime) * fadeFrom in integer division,
   so the light drops to radius 0 on its first faded frame.
   NON_MATCHING: masked 49; retail keeps the abs values apart from their differences (bgez/move),
   holds 0x300 in a register and m in $s7 */
#ifdef NON_MATCHING
void func_80108A44_134634_HotRopeJump(Gfx** gfxp) {
    HRJLight* list[33];
    HmfData* m;
    HmfVtx* v;
    HRJLight* l;
    HRJLight** lp;
    s32 n;
    s32 i;
    s32 r;
    s32 dx;
    s32 dz;
    s32 d2;
    s32 t;
    f32 sum;
    f32 f;
    f32 inner;

    if (D_8010C3C0_137FB0_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        for (i = 0; i < 3; i++) {
            D_80111416_13D006_HotRopeJump[i] = (u8)func_8010BF04_137AF4_HotRopeJump(D_8010C3B0_137FA0_HotRopeJump[i], D_8010C3B8_137FA8_HotRopeJump[i], D_8010C260_137E50_HotRopeJump);
        }
        D_8010C3C0_137FB0_HotRopeJump = D_8010C260_137E50_HotRopeJump;
    }
    l = D_80111420_13D010_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        if (l->used != 0 && l->fade != 0) {
            if (--l->fade <= 0) {
                l->fade = 0;
                l->fadeTime = 0;
                l->used = 0;
            } else {
                l->radius = (f32)(l->fade / l->fadeTime) * l->fadeFrom;
            }
        }
    }
    n = 0;
    for (i = 0; i < 32; i++) {
        l = &D_80111420_13D010_HotRopeJump[i];
        if (l->used != 0 && l->radius > 10.0) {
            list[n++] = l;
        }
    }
    list[n] = NULL;
    m = D_800FC834_FD434[D_80111822_13D412_HotRopeJump].hmf;
    v = m->unk44[D_800FDBE0_FE7E0];
    for (i = 0; i < 0x300; i++, v++) {
        sum = 0.0f;
        if (*(u16*)v->unk06 != 0) {
            l = list[0];
            lp = &list[1];
            if (l != NULL) {
                do {
                    dx = l->y + 50;
                    if (dx < 0) {
                        dx = -dx;
                    }
                    r = dx * 0.75 + l->radius;
                    t = v->unk00 - l->x;
                    dx = t;
                    if (t < 0) {
                        dx = -dx;
                    }
                    if (dx < r) {
                        t = (f32)(v->unk04 - l->z) * l->aspect;
                        dz = t;
                        if (t < 0) {
                            dz = -dz;
                        }
                        if (dz < r) {
                            d2 = dx * dx + dz * dz;
                            if (d2 < r * r) {
                                inner = l->radius - r * 2;
                                f = 1.0f;
                                if (inner <= 0.0f || inner * inner < (f32)d2) {
                                    f -= (sqrtf(d2) - inner) / ((f32)r - inner);
                                }
                                sum += f;
                            }
                        }
                    }
                    l = *lp++;
                } while (l != NULL);
            }
        }
        if (sum > 1.0) {
            sum = 1.0f;
        }
        v->unk0C[0] = D_80111416_13D006_HotRopeJump[0] * sum;
        v->unk0C[1] = D_80111418_13D008_HotRopeJump * sum;
        v->unk0C[2] = D_8011141A_13D00A_HotRopeJump * sum;
    }
    gSPDisplayList((*gfxp)++, osVirtualToPhysical(D_8010C360_137F50_HotRopeJump));
    func_800204C0_210C0(0, gfxp);
    gSPSegment((*gfxp)++, 1, osVirtualToPhysical(m->unk44[D_800FDBE0_FE7E0]));
    gSPDisplayList((*gfxp)++, osVirtualToPhysical(D_80111828_13D418_HotRopeJump));
    gDPPipeSync((*gfxp)++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80108A44_134634_HotRopeJump);
#endif

/* Builds the floor (MP1 func_800FBABC): a 2 x 32 x 12 vertex grid (per-frame copies, lit by
   func_80108A44; the vertices off the stage's edge are flagged unlit) and its display list.
   Returns the model.
   NON_MATCHING: masked 27, all in the vertex grid: retail hoists the whole (s32)(step * -16.0)
   out of the loops (into $s5) and allocates the loop counters differently */
#ifdef NON_MATCHING
s16 func_80109078_134C68_HotRopeJump(void) {
    HuSprite_Unk84_Struct* tex;
    Gfx* buf;
    Gfx* gfx;
    HmfData* m;
    HmfVtx* v;
    HmfVtx* src;
    s32 model;
    s32 y;
    s32 step;
    s32 x0;
    s32 s0;
    s32 x;
    s32 z;
    s32 s;
    s32 t;
    s32 half;
    s32 row;
    s32 col;
    s32 i;
    s32 size;
    s32 vtx;
    s32 cur;
    s32 prev;

    step = 60;
    tex = SprAnimGet(D_80111824_13D414_HotRopeJump);
    gfx = buf = HuMemAlloc(0x2000 * sizeof(Gfx));
    model = D_80111822_13D412_HotRopeJump = func_8002838C_28F8C(0x80, func_80108A44_134634_HotRopeJump, 0);
    m = D_800FC834_FD434[model].hmf;
    v = m->unk44[0] = m->unk40 = func_80027154_27D54(0x364 * sizeof(Vtx), m->unk0E);
    y = 0;
    x0 = -step * 12;
    s0 = 0;
    for (half = 0; half < 2; half++) {
        z = step * -16.0;
        t = 0;
        for (row = 0; row < 32; row++) {
            x = x0;
            s = s0;
            for (col = 0; col < 12; col++) {
                v->unk00 = x;
                v->unk02 = y;
                v->unk04 = z;
                v->unk08 = s;
                v->unk0A = t;
                v->unk0C[0] = v->unk0C[1] = v->unk0C[2] = 0xFF;
                v->unk0F = 0xFF;
                x += step;
                s += 0x200;
                if (row == 0 || row == 31) {
                    *(u16*)v->unk06 = 0;
                } else if (row == 1 || row == 30) {
                    *(u16*)v->unk06 = 0;
                } else if (half == 0 && (col == 0 || col == 1)) {
                    *(u16*)v->unk06 = 0;
                } else if (half == 1 && col == 11) {
                    *(u16*)v->unk06 = 0;
                } else {
                    *(u16*)v->unk06 = 1;
                }
                v++;
            }
            z += step;
            t += 0x200;
        }
        x0 += step * 11;
        s0 += 0x1600;
    }
    for (i = 1; i < D_800FDBCA_FE7CA; i++) {
        v = m->unk44[i] = func_80027154_27D54(0x364 * sizeof(Vtx), m->unk0E);
        src = m->unk44[0];
        for (row = 0; row < 0x300; row++) {
            *v++ = *src++;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0x60600);
    gSPSetGeometryMode(gfx++, 0x280004);
    gDPSetRenderMode(gfx++, 0xC084000, 0);
    gDPSetCombine(gfx++, 0x127E24, 0xFFFFF9FC);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, tex->unk0C);
    gDPLoadTextureBlock_4b(gfx++, tex->unk08, G_IM_FMT_CI, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    vtx = 0;
    for (half = 0; half < 2; half++) {
        gSPVertex(gfx++, 0x01000000 | (s16)vtx << 4, 12, 0);
        vtx += 12;
        for (row = 1; row < 32; row++) {
            cur = (row & 1) * 16;
            prev = ((row - 1) & 1) * 16;
            gSPVertex(gfx++, 0x01000000 | (s16)vtx << 4, 12, cur);
            vtx += 12;
            for (col = 1; col < 12; col++) {
                gSP2Triangles(gfx++, cur + col, prev + col - 1, cur + col - 1, 0, prev + col, prev + col - 1,
                              cur + col, 0);
            }
        }
    }
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)buf;
    D_80111828_13D418_HotRopeJump = func_80027154_27D54(size, m->unk0E);
    bcopy(buf, D_80111828_13D418_HotRopeJump, size);
    HuMemFree(buf);
    return model;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80109078_134C68_HotRopeJump);
#endif

__asm__(".section .rodata");
const u32 D_8010C770_138360_HotRopeJump[4] = { 0x00000096, 0xFDA80000, 0x00000096, 0x025800B4 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_801096E4_1352D4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80109A58_135648_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010A0F0_135CE0_HotRopeJump);

__asm__(".section .rodata");
const char D_8010C810_138400_HotRopeJump[] = "@Y";

__asm__(".section .rodata");
const char D_8010C814_138404_HotRopeJump[] = "";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010A4E4_1360D4_HotRopeJump);

__asm__(".section .rodata");
const u32 D_8010C828_138418_HotRopeJump[1] = { 0x3FA99999 };

__asm__(".section .rodata");
const u32 D_8010C82C_13841C_HotRopeJump[1] = { 0x9999999A };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C830_138420_HotRopeJump[2] = { 0x3FC99999, 0x9999999A };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C838_138428_HotRopeJump[2] = { 0x3FECCCCC, 0xCCCCCCCD };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C840_138430_HotRopeJump[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C848_138438_HotRopeJump[8] = "@i";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C850_138440_HotRopeJump[2] = { 0x4062C000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C858_138448_HotRopeJump[8] = "@I";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C860_138450_HotRopeJump[8] = "@T";

__asm__(".section .rodata");
const u32 jtbl_8010C868_138458_HotRopeJump[6] = { 0x8010A764, 0x8010A8F4, 0x8010A960, 0x8010AA30, 0x8010AC04, 0x8010ACF8 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C880_138470_HotRopeJump[2] = { 0x40000000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C888_138478_HotRopeJump[2] = { 0x40668000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C890_138480_HotRopeJump[2] = { 0x400C0000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C898_138488_HotRopeJump[2] = { 0x400C0000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8A0_138490_HotRopeJump[8] = "@I";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8A8_138498_HotRopeJump[2] = { 0x40000000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8B0_1384A0_HotRopeJump[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8B8_1384A8_HotRopeJump[8] = "@>";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8C0_1384B0_HotRopeJump[2] = { 0x4070E000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8C8_1384B8_HotRopeJump[2] = { 0xC0668000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8D0_1384C0_HotRopeJump[2] = { 0x40668000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8D8_1384C8_HotRopeJump[8] = "@$";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8E0_1384D0_HotRopeJump[2] = { 0x3FC33333, 0x33333333 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8E8_1384D8_HotRopeJump[2] = { 0x3FE00000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010B0A0_136C90_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010B754_137344_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BB48_137738_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF04_137AF4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF70_137B60_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF80_137B70_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF8C_137B7C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF98_137B88_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010C074_137C64_HotRopeJump);
