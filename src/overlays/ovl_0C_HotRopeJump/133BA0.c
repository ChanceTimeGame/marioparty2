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

/* The two torches (MP1 func_800FC0B4): flame models at the ends of the floor, each with a light;
   the intro camera's start and end. */
void func_801096E4_1352D4_HotRopeJump(omObjData* obj) {
    s16 pos[2][4] = { { 0, 150, -600, 0 }, { 0, 150, 600, 180 } };
    HRJSeg* seg;
    HmfModel* mdl;
    HuSprite_Unk84_Struct* tex;
    s32 i;

    omSetStatBit(obj, 0xA0);
    obj->func_ptr = func_80109A58_135648_HotRopeJump;
    D_80111834_13D424_HotRopeJump = func_8001A2F8_1AEF8(0x1D0003);
    D_80111836_13D426_HotRopeJump = func_8001A2F8_1AEF8(0x1D0004);
    seg = func_80027154_27D54(13 * sizeof(HRJSeg), 0x7918);
    obj->unk_50 = seg;
    D_80111924_13D514_HotRopeJump = seg;
    func_800B0EF0_B1AF0(seg, 0, 13 * sizeof(HRJSeg));
    for (i = 0; i < 2; i++, seg++) {
        tex = SprAnimGet(D_80111834_13D424_HotRopeJump);
        obj->model[i] = seg->model = func_8010B0A0_136C90_HotRopeJump(D_8010C3C4_137FB4_HotRopeJump, tex, SprAnimGet(D_80111836_13D426_HotRopeJump));
        mdl = &D_800FC834_FD434[seg->model];
        seg->pos.x = seg->base.x = pos[i][0];
        seg->pos.y = seg->base.y = pos[i][1];
        seg->pos.z = seg->base.z = pos[i][2];
        mdl->rot.y = pos[i][3];
        mdl->scale.x = mdl->scale.y = mdl->scale.z = 0.0f;
        seg->anim = ((rand8() << 8) | rand8()) / 1024 & 0x3C;
        func_80029714_2A314(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->rot.x, mdl->rot.y, mdl->rot.z);
            omSetSca(obj, mdl->scale.x, mdl->scale.y, mdl->scale.z);
        }
        seg->light = func_80108850_134440_HotRopeJump(seg->pos.x, seg->pos.y - 50.0, seg->pos.z, 10.0f);
    }
    D_8011188C_13D47C_HotRopeJump.x = D_8010274C_10334C.x;
    D_8011188C_13D47C_HotRopeJump.y = D_8010274C_10334C.y;
    D_8011188C_13D47C_HotRopeJump.z = D_8010274C_10334C.z;
    D_801118A4_13D494_HotRopeJump.x = D_800FD474_FE074.x;
    D_801118A4_13D494_HotRopeJump.y = D_800FD474_FE074.y;
    D_801118A4_13D494_HotRopeJump.z = D_800FD474_FE074.z;
    D_801118B4_13D4A4_HotRopeJump = D_800FA610_FB210;
    D_80111880_13D470_HotRopeJump.x = D_8010274C_10334C.x = 0.0f;
    D_80111880_13D470_HotRopeJump.y = D_8010274C_10334C.y = 100.0f;
    D_80111880_13D470_HotRopeJump.z = D_8010274C_10334C.z = 0.0f;
    D_80111898_13D488_HotRopeJump.x = D_800FD474_FE074.x = -15.0f;
    D_80111898_13D488_HotRopeJump.y = D_800FD474_FE074.y = 0.0f;
    D_80111898_13D488_HotRopeJump.z = D_800FD474_FE074.z = 0.0f;
    D_801118B0_13D4A0_HotRopeJump = D_800FA610_FB210 = 1000.0f;
}

/* The torches (MP1 func_800FC428): the intro camera move and the centre light, then each flame's
   light and list. */
void func_80109A58_135648_HotRopeJump(omObjData* obj) {
    HRJSeg* seg;
    HmfModel* mdl;
    HuSprite_Unk84_Struct* anim;
    s32 i;
    f32 t;
    f32 r;

    func_800B1960_B2560(D_80111840_13D430_HotRopeJump, D_800C9B80_CA780->pos.x, D_800C9B80_CA780->pos.y,
                        D_800C9B80_CA780->pos.z, D_800C9B80_CA780->at.x, D_800C9B80_CA780->at.y,
                        D_800C9B80_CA780->at.z, D_800C9B80_CA780->up.x, D_800C9B80_CA780->up.y,
                        D_800C9B80_CA780->up.z);
    anim = SprAnimGet(D_80111836_13D426_HotRopeJump);
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0 && D_8010C458_138048_HotRopeJump[D_8010C454_138044_HotRopeJump] != 0) {
        switch (D_8010C454_138044_HotRopeJump) {
            case 0:
                t = (f32)(D_8010C456_138046_HotRopeJump - 40) * 0.05;
                if (t > 0.0) {
                    D_8010274C_10334C.x = (D_8011188C_13D47C_HotRopeJump.x - D_80111880_13D470_HotRopeJump.x) * t + D_80111880_13D470_HotRopeJump.x;
                    D_8010274C_10334C.y = (D_8011188C_13D47C_HotRopeJump.y - D_80111880_13D470_HotRopeJump.y) * t + D_80111880_13D470_HotRopeJump.y;
                    D_8010274C_10334C.z = (D_8011188C_13D47C_HotRopeJump.z - D_80111880_13D470_HotRopeJump.z) * t + D_80111880_13D470_HotRopeJump.z;
                    D_800FD474_FE074.x = (D_801118A4_13D494_HotRopeJump.x - D_80111898_13D488_HotRopeJump.x) * t + D_80111898_13D488_HotRopeJump.x;
                    D_800FD474_FE074.y = (D_801118A4_13D494_HotRopeJump.y - D_80111898_13D488_HotRopeJump.y) * t + D_80111898_13D488_HotRopeJump.y;
                    D_800FD474_FE074.z = (D_801118A4_13D494_HotRopeJump.z - D_80111898_13D488_HotRopeJump.z) * t + D_80111898_13D488_HotRopeJump.z;
                    D_800FA610_FB210 = (D_801118B4_13D4A4_HotRopeJump - D_801118B0_13D4A0_HotRopeJump) * t + D_801118B0_13D4A0_HotRopeJump;
                }
                break;
            case 2:
                if (D_8011182C_13D41C_HotRopeJump != 0) {
                    D_8010C454_138044_HotRopeJump++;
                    D_8010C456_138046_HotRopeJump = 0;
                }
                break;
            case 3:
                if (D_8011182C_13D41C_HotRopeJump == 0) {
                    D_8010C454_138044_HotRopeJump++;
                    D_8010C456_138046_HotRopeJump = 0;
                    D_8011141C_13D00C_HotRopeJump = func_80108850_134440_HotRopeJump(0.0f, 100.0f, 0.0f, 10.0f);
                }
                break;
            case 4:
                t = (f32)D_8010C456_138046_HotRopeJump * (1.0 / 30.0);
                func_80108978_134568_HotRopeJump(D_8011141C_13D00C_HotRopeJump, t * 400.0, t * 500.0);
                func_80026D28_27928(3);
                func_80026DAC_279AC(4, (u8)(t * 255.0f), (u8)(t * 160.0f), (u8)(t * 64.0f));
                func_80026E00_27A00(4, 0.0f, 100.0f, 0.0f);
                break;
        }
        if (++D_8010C456_138046_HotRopeJump >= D_8010C458_138048_HotRopeJump[D_8010C454_138044_HotRopeJump]) {
            D_8010C456_138046_HotRopeJump = 0;
            if (++D_8010C454_138044_HotRopeJump == 1) {
                PlaySound(0x16F);
            }
        }
    }
    seg = obj->unk_50;
    for (i = 0; i < 2; i++, seg++) {
        mdl = &D_800FC834_FD434[seg->model];
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (D_8010C454_138044_HotRopeJump == 1) {
                if (mdl->scale.x < 1.0) {
                    mdl->scale.z = mdl->scale.x = mdl->scale.x + 0.1;
                    mdl->scale.y = mdl->scale.x * 1.4;
                } else if (mdl->scale.y > 1.0) {
                    mdl->scale.y = mdl->scale.y - 0.1;
                }
            }
            if (D_8010C454_138044_HotRopeJump > 0) {
                r = (HuMathSin((seg->anim & 0xF) * 11.25) * 0.4 * 100.0 + 180.0) * mdl->scale.x;
                func_80108978_134568_HotRopeJump(seg->light, r, r);
                seg->anim = (seg->anim + 2) & 0x3F;
                if (++seg->timer >= 0x7800) {
                    seg->timer -= 0x800;
                }
            }
        }
        if (i == 0) {
            omSetSca(obj, mdl->scale.x, mdl->scale.y, mdl->scale.z);
        }
        func_8010B754_137344_HotRopeJump(seg, D_8010C3C4_137FB4_HotRopeJump, anim);
    }
}

/* The rope (MP1 func_800FCAC0): 13 flame models with lights, set out on a circle, that then
   gather into the turning rope (func_8010A4E4).
   NON_MATCHING: masked 0; retail swaps $f0/$f2 around the two int-to-float conversions */
#ifdef NON_MATCHING
void func_8010A0F0_135CE0_HotRopeJump(omObjData* obj) {
    Vec unused[2]; /* retail's frame has 0x18 bytes of locals nothing uses */
    HRJSeg* seg;
    HmfModel* mdl;
    HuSprite_Unk84_Struct* tex;
    s32 i;
    f32 t;
    s32 r;

    omSetStatBit(obj, 0xA0);
    obj->func_ptr = func_8010A4E4_1360D4_HotRopeJump;
    D_80111920_13D510_HotRopeJump = func_80027154_27D54(13 * sizeof(HRJSeg), 0x7918);
    func_800B0EF0_B1AF0(D_80111920_13D510_HotRopeJump, 0, 13 * sizeof(HRJSeg));
    D_80111838_13D428_HotRopeJump = func_8001A2F8_1AEF8(0x1D0003);
    D_8011183A_13D42A_HotRopeJump = func_8001A2F8_1AEF8(0x1D0004);
    seg = D_80111920_13D510_HotRopeJump;
    for (i = 0; i < 13;) {
        tex = SprAnimGet(D_80111838_13D428_HotRopeJump);
        obj->model[i] = seg->model = func_8010B0A0_136C90_HotRopeJump(D_8010C468_138058_HotRopeJump, tex, SprAnimGet(D_8011183A_13D42A_HotRopeJump));
        mdl = &D_800FC834_FD434[seg->model];
        mdl->hmf->unk64->unk50 |= 0x71010000;
        mdl->hmf->unk64->unk50 &= ~0x2000;
        seg->unk_30 = (f32)(360.0 - i * 30.0) + 210.0;
        seg->unk_30 = func_800B0D98_B1998(seg->unk_30, 360.0);
        seg->pos.x = seg->base.x = HuMathSin(seg->unk_30) * 100.0 * 3.5;
        seg->pos.z = seg->base.z = func_800B7890_B8490(seg->unk_30) * 100.0 * 3.5;
        seg->pos.y = seg->base.y = 50.0f;
        seg->size = 150.0f;
        seg->anim = ((rand8() << 8) | rand8()) / 2048 & 0x3C;
        t = (f32)(i - 6) / 6.0f;
        seg->angle = t * t * 30.0 - 15.0;
        seg->state = 0;
        seg->delay = i * 4 + 75;
        mdl->scale.x = mdl->scale.y = mdl->scale.z = 0.0f;
        r = ((rand8() << 8) | rand8()) * 160;
        mdl->rot.y = (f32)(r / 65536 - 80) + 270.0f;
        if (i == 0) {
            seg->pos.x = seg->pos.z = 0.0f;
            mdl->rot.y = 0.0f;
        } else {
            seg->vel.y = 7.5f;
        }
        func_80029714_2A314(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            mdl = &D_800FC834_FD434[seg->model];
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->rot.x, mdl->rot.y, mdl->rot.z);
            omSetSca(obj, mdl->scale.x, mdl->scale.y, mdl->scale.z);
        }
        i++;
        seg->light = func_80108850_134440_HotRopeJump(seg->pos.x, seg->pos.y, seg->pos.z, 10.0f);
        rand8();
        seg++;
        rand8();
    }
    PlaySound(0x174);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010A0F0_135CE0_HotRopeJump);
#endif

/* The rope (MP1 func_800FCE98): each flame circles the centre (state 0) until its delay runs
   out, hops to its place (1, 2), settles into the rope (3), turns with it (4) until the round
   ends, then is put out (5). */
void func_8010A4E4_1360D4_HotRopeJump(omObjData* obj) {
    Matrix4f m;
    HRJSeg* seg;
    HmfModel* mdl;
    HuSprite_Unk84_Struct* anim;
    HuCamera* c;
    s32 i;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 a;

    c = D_800C9B80_CA780;
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_8010C4F8_1380E8_HotRopeJump++;
        if (D_8010C4FC_1380EC_HotRopeJump[D_8010C4FA_1380EA_HotRopeJump] != 0 &&
            D_8010C4F8_1380E8_HotRopeJump >= D_8010C4FC_1380EC_HotRopeJump[D_8010C4FA_1380EA_HotRopeJump]) {
            D_8010C4F8_1380E8_HotRopeJump = 0;
            D_8010C4FA_1380EA_HotRopeJump++;
        }
    }
    func_800B1960_B2560(m, c->pos.x, c->pos.y, c->pos.z, c->at.x, c->at.y, c->at.z, c->up.x, c->up.y, c->up.z);
    anim = SprAnimGet(D_80111836_13D426_HotRopeJump); /* the torches' animation, not D_8011183A */
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        seg = D_80111920_13D510_HotRopeJump;
        for (i = 0; i < 13; seg++, i++) {
            mdl = &D_800FC834_FD434[seg->model];
            t = (f32)(i - 6) / 6.0f;
            t = (1.0 - t * t) * 200.0 + 100.0;
            x = func_800B7890_B8490(seg->angle) * t;
            y = HuMathSin(seg->angle) * t + 150.0;
            if (y < 50.0) {
                y = 50.0f;
            }
            z = (i - 6) * 80.0;
            switch (seg->state) {
                case 0:
                    if (i != 0) {
                        seg->unk_30 += 2.0;
                        if (seg->unk_30 >= 360.0) {
                            seg->unk_30 -= 360.0;
                        }
                        mdl->rot.y = seg->unk_30 + 180.0;
                        seg->pos.x = seg->base.x = HuMathSin(seg->unk_30) * 100.0 * 3.5;
                        seg->pos.z = seg->base.z = func_800B7890_B8490(seg->unk_30) * 100.0 * 3.5;
                        seg->pos.y += seg->vel.y;
                        if (seg->pos.y <= 50.0) {
                            seg->pos.y = 50.0f;
                            seg->vel.y = 7.5f;
                        } else {
                            seg->vel.y = seg->vel.y - 2.0;
                        }
                    }
                    mdl->scale.z = mdl->scale.x = D_8010C26C_137E5C_HotRopeJump;
                    mdl->scale.y = mdl->scale.x * 1.4;
                    func_80108978_134568_HotRopeJump(seg->light, seg->size * mdl->scale.x, seg->size * mdl->scale.x);
                    if (seg->delay != 0) {
                        seg->delay--;
                    } else {
                        seg->pos.y = 50.0f;
                        seg->delay = 2;
                        seg->state++;
                    }
                    break;
                case 1:
                    seg->state = 2;
                    seg->timer = 0;
                    seg->vel.x = (x - seg->pos.x) * 0.05;
                    seg->vel.z = (z - seg->pos.z) * 0.05;
                    seg->vel.y = 50.0f;
                    if (seg->delay >= 2) {
                        seg->delay--;
                    }
                    break;
                case 2:
                    mdl->scale.z = mdl->scale.x = D_8010C26C_137E5C_HotRopeJump;
                    mdl->scale.y = mdl->scale.x * 1.4;
                    if (seg->delay != 0) {
                        if (--seg->delay != 0) {
                            break;
                        }
                        seg->timer = 0;
                        if (i == 0) {
                            func_80079798_7A398(0x170, 3);
                        }
                        break;
                    }
                    seg->pos.x += seg->vel.x;
                    seg->pos.y += seg->vel.y;
                    seg->pos.z += seg->vel.z;
                    seg->vel.y = seg->vel.y - 5.0;
                    if (seg->timer < 21) {
                        break;
                    }
                    seg->pos.y = 50.0f;
                    seg->state = 3;
                    seg->timer = 0;
                    break;
                case 3:
                    mdl->scale.z = mdl->scale.x = D_8010C26C_137E5C_HotRopeJump;
                    mdl->scale.y = mdl->scale.x * 1.4;
                    if (seg->timer < 31) {
                        t = (f32)seg->timer / 30.0;
                    } else {
                        t = 1.0f;
                    }
                    seg->pos.x = seg->pos.x + (x - seg->pos.x) * t * 0.2;
                    seg->pos.y = seg->pos.y + (y - seg->pos.y) * t * 0.2;
                    seg->pos.z = seg->pos.z + (z - seg->pos.z) * t * 0.2;
                    a = 270.0 - mdl->rot.y;
                    if (a <= -180.0) {
                        a = a + 360.0;
                    } else if (a > 180.0) {
                        a = a - 360.0;
                    }
                    mdl->rot.y = mdl->rot.y + a * t * 0.2;
                    if (mdl->rot.y >= 360.0) {
                        mdl->rot.y = mdl->rot.y - 360.0;
                    } else if (mdl->rot.y < 0.0) {
                        mdl->rot.y = mdl->rot.y + 360.0;
                    }
                    if (seg->light >= 0 && !(i & 1) && seg->timer == 1) {
                        func_801089EC_1345DC_HotRopeJump(seg->light, 30);
                    }
                    if (D_8011182C_13D41C_HotRopeJump != 0) {
                        seg->state = 4;
                    }
                    break;
                case 4:
                    mdl->scale.z = mdl->scale.x = D_8010C26C_137E5C_HotRopeJump;
                    mdl->scale.y = mdl->scale.x * 1.4;
                    seg->angle = seg->angle + D_80111830_13D420_HotRopeJump * 10.0;
                    if (seg->angle >= 360.0) {
                        seg->angle = seg->angle - 360.0;
                    }
                    if (seg->angle < 0.0) {
                        seg->angle = seg->angle + 360.0;
                    }
                    seg->vel.x = x - seg->pos.x;
                    seg->vel.y = y - seg->pos.y;
                    seg->vel.z = z - seg->pos.z;
                    seg->pos.x = x;
                    seg->pos.y = y;
                    seg->pos.z = z;
                    if (D_8011182C_13D41C_HotRopeJump != 0) {
                        continue;
                    }
                    seg->state = 5;
                    seg->delay = 4;
                    break;
                case 5:
                    if (i == 0 && seg->delay != 0 && --seg->delay == 0) {
                        PlaySound(0x171);
                    }
                    if (!(mdl->scale.x > 0.0)) {
                        continue;
                    }
                    seg->pos.x += seg->vel.x *= 0.9;
                    seg->pos.y += seg->vel.y *= 0.9;
                    seg->pos.z += seg->vel.z *= 0.9;
                    mdl->scale.z = mdl->scale.y = mdl->scale.x = mdl->scale.x - 0.15;
                    if (mdl->scale.x > 0.05) {
                        if (seg->light >= 0) {
                            func_80108978_134568_HotRopeJump(seg->light, seg->size * mdl->scale.x, seg->size * mdl->scale.x);
                        }
                        continue;
                    }
                    if (seg->light >= 0) {
                        func_801089D4_1345C4_HotRopeJump(seg->light);
                        seg->light = -1;
                    }
                    func_800298A4_2A4A4(seg->model, 4, 4);
                    break;
            }
        }
    }
    seg = D_80111920_13D510_HotRopeJump;
    for (i = 0; i < 13; i++, seg++) {
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            seg->base.x = seg->base.x - (seg->base.x - seg->pos.x) * 0.5;
            seg->base.y = seg->base.y - (seg->base.y - seg->pos.y) * 0.5;
            seg->base.z = seg->base.z - (seg->base.z - seg->pos.z) * 0.5;
            seg->anim = (seg->anim + 4) & 0x3F;
            if (++seg->timer >= 0x7800) {
                seg->timer -= 0x800;
            }
        }
        func_8010B754_137344_HotRopeJump(seg, D_8010C468_138058_HotRopeJump, anim);
        func_80029714_2A314(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            mdl = &D_800FC834_FD434[seg->model];
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->rot.x, mdl->rot.y, mdl->rot.z);
            omSetSca(obj, mdl->scale.x, mdl->scale.y, mdl->scale.z);
        }
        if (seg->light >= 0) {
            if (seg->state < 5) {
                func_80108918_134508_HotRopeJump(seg->light, seg->pos.x, seg->pos.y, seg->pos.z);
            } else {
                func_80108918_134508_HotRopeJump(seg->light, seg->pos.x, 50.0f, seg->pos.z);
            }
        }
    }
    seg = D_80111920_13D510_HotRopeJump;
    for (i = 0; i < 12; i++, seg++) {
        seg->dir.x = seg[1].pos.x - seg->pos.x;
        seg->dir.y = seg[1].pos.y - seg->pos.y;
        seg->dir.z = seg[1].pos.z - seg->pos.z;
    }
}

/* A flame model (MP1 func_800FD90C): a five-vertex base quad (segment 2's texture, palette in
   segment 15) and a four-vertex top (tex), with per-frame display lists (func_8010B754). Returns
   the model. Retail copies 10 vertices from a 9-vertex table (the 10th is the next .data; the lists
   use 9): the host must not read past vtx[8]. */
s32 func_8010B0A0_136C90_HotRopeJump(const Vtx_t* vtx, HuSprite_Unk84_Struct* tex, HuSprite_Unk84_Struct* anim) {
    Gfx* buf;
    Gfx* gfx;
    HmfData* m;
    Vtx_t* dst;
    const Vtx_t* src;
    s32 model;
    s32 size;
    s32 i;
    s32 j;

    buf = gfx = HuMemAlloc(0x2000 * sizeof(Gfx));
    model = func_80027FA4_28BA4(0x480, buf, 4);
    m = D_800FC834_FD434[model].hmf;
    m->unk64->unk50 |= 0x71010000;
    m->unk64->unk50 &= ~0x2000;
    HuMemFree(m->unk3C);
    m->unk3C = func_80027154_27D54(8 * sizeof(Gfx*), D_800FA1AA_FADAA);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        dst = m->unk44[i] = func_80027154_27D54(10 * sizeof(Vtx), m->unk0E);
        src = vtx;
        for (j = 0; j < 10; j++) {
            *dst++ = *src++;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, 0x20600);
    gSPSetGeometryMode(gfx++, 0x280205);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombine(gfx++, 0xFF99FF, 0xFF30FE7F);
    gDPSetRenderMode(gfx++, 0x404A50, 0);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, 0x0F000000);
    gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, 32, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000000, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 4, 0, 1, 2, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 3, 0, 4, 2, 3, 0);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)buf;
    m->unk3C->unk00[0] = m->unk3C->unk10 = func_80027154_27D54(size, m->unk0E);
    bcopy(buf, m->unk3C->unk10, size);
    gfx = buf;
    gDPPipeSync(gfx++);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    gDPSetRenderMode(gfx++, 0x443078, 0);
    gDPLoadTLUT_pal16(gfx++, 0, tex->unk0C);
    gDPLoadTextureBlock_4b(gfx++, tex->unk08, G_IM_FMT_CI, 32, 32, 0, G_TX_MIRROR, G_TX_CLAMP, 5, 5, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000000 + 5 * sizeof(Vtx), 4, 5);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)buf;
    m->unk3C->unk14 = func_80027154_27D54(size, m->unk0E);
    bcopy(buf, m->unk3C->unk14, size);
    HuMemFree(buf);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        m->unk3C->unk00[i + 1] = func_80027154_27D54(32 * sizeof(Gfx), m->unk0E);
    }
    return model;
}

/* A flame's per-frame list (MP1 func_800FDFC4): its palette, matrix (facing the camera,
   D_80111840) and animated texture; the top two vertices sway with seg->anim.
   NON_MATCHING: masked 7; retail reloads D_800FDBE0 for the palette segment (GCC reuses it) */
#ifdef NON_MATCHING
void func_8010B754_137344_HotRopeJump(HRJSeg* seg, const Vtx_t* vtx, HuSprite_Unk84_Struct* anim) {
    Matrix4f m;
    Vec d;
    HmfModel* mdl;
    HmfData* md;
    Gfx* gfx;
    HmfVtx* v;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 a;
    f32 r;
    s32 i;

    mdl = &D_800FC834_FD434[seg->model];
    md = mdl->hmf;
    dx = seg->base.x - seg->pos.x;
    dy = seg->base.y - seg->pos.y;
    dz = seg->base.z - seg->pos.z;
    d.x = dx * D_80111840_13D430_HotRopeJump[0][0] + dy * D_80111840_13D430_HotRopeJump[1][0] + dz * D_80111840_13D430_HotRopeJump[2][0];
    d.y = dx * D_80111840_13D430_HotRopeJump[0][1] + dy * D_80111840_13D430_HotRopeJump[1][1] + dz * D_80111840_13D430_HotRopeJump[2][1];
    d.z = dx * D_80111840_13D430_HotRopeJump[0][2] + dy * D_80111840_13D430_HotRopeJump[1][2] + dz * D_80111840_13D430_HotRopeJump[2][2];
    func_800B1F50_B2B50(m, seg->pos.x, seg->pos.y, seg->pos.z);
    func_80025884_26484(m, mdl->rot.x, mdl->rot.y, mdl->rot.z);
    func_80025830_26430(m, mdl->scale.x, mdl->scale.y, mdl->scale.z);
    guMtxCatF(m, D_80111840_13D430_HotRopeJump, m);
    func_800B3040_B3C40(m, &seg->mtx[D_800FDBE0_FE7E0]);
    gfx = md->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    md->unk3C->unk00[0] = gfx;
    gDPPipeSync(&gfx[0]);
    gSPSegment(&gfx[1], 15, osVirtualToPhysical(D_801118B8_13D4A8_HotRopeJump[D_800FDBE0_FE7E0]));
    gSPSegment(&gfx[2], 2, osVirtualToPhysical(anim->unk00[(s16)seg->anim >> 2].unk00));
    gSPDisplayList(&gfx[3], osVirtualToPhysical(md->unk3C->unk10));
    gSPMatrix(&gfx[4], osVirtualToPhysical(&seg->mtx[D_800FDBE0_FE7E0]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(&gfx[5], osVirtualToPhysical(md->unk3C->unk14));
    gDPPipeSync(&gfx[6]);
    gSPEndDisplayList(&gfx[7]);
    v = md->unk44[D_800FDBE0_FE7E0];
    a = (f32)((seg->anim & 0x3F) * 360) * 0.015625 + 90.0;
    r = HRJ_ABS(vtx->ob[0] * 0.4);
    for (i = 0; i < 2; i++) {
        v->unk00 = vtx->ob[0] + func_800B7890_B8490(a) * r + d.x;
        v->unk02 = vtx->ob[1] + HuMathSin(a) * r + d.y;
        a += 180.0;
        if (a >= 360.0) {
            a -= 360.0;
        }
        v++;
        vtx++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010B754_137344_HotRopeJump);
#endif

/* The flames' palette: while the light blend changes, each of the 12 colours moves between its
   two RGBA values and is packed to RGBA5551 (D_8010C568); then it is copied to this frame's
   segment-15 palette. Retail's red mask is ~0x17FF (it also clears bit 12). */
void func_8010BB48_137738_HotRopeJump(f32 t) {
    u16 c[4];
    u16 i;

    if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        for (i = 0; i < 12; i++) {
            c[0] = func_8010BF04_137AF4_HotRopeJump(D_8010C508_1380F8_HotRopeJump[i][0], D_8010C538_138128_HotRopeJump[i][0], t);
            c[1] = func_8010BF04_137AF4_HotRopeJump(D_8010C508_1380F8_HotRopeJump[i][1], D_8010C538_138128_HotRopeJump[i][1], t);
            c[2] = func_8010BF04_137AF4_HotRopeJump(D_8010C508_1380F8_HotRopeJump[i][2], D_8010C538_138128_HotRopeJump[i][2], t);
            c[3] = func_8010BF04_137AF4_HotRopeJump(D_8010C508_1380F8_HotRopeJump[i][3], D_8010C538_138128_HotRopeJump[i][3], t);
            c[0] = (c[0] << 8) & ~0x17FF;
            c[1] = (c[1] << 3) & 0x7C0;
            c[2] = (c[2] >> 2) & 0x3E;
            c[3] = c[3] & 1;
            D_8010C568_138158_HotRopeJump[i] = c[0] | c[1] | c[2] | c[3];
        }
    }
    *(HRJPal*)D_801118B8_13D4A8_HotRopeJump[D_800FDBE0_FE7E0] = *(HRJPal*)D_8010C568_138158_HotRopeJump;
}

/* a + t * (b - a), t clamped to 0..1. */
f32 func_8010BF04_137AF4_HotRopeJump(f32 a, f32 b, f32 t) {
    if (t < 0.0) {
        t = 0.0f;
    } else if (t > 1.0) {
        t = 1.0f;
    }
    return a + t * (b - a);
}

/* The rope turns (func_8010A4E4 state 4). */
void func_8010BF70_137B60_HotRopeJump(void) {
    D_8011182C_13D41C_HotRopeJump = 1;
}

void func_8010BF80_137B70_HotRopeJump(void) {
    D_8011182C_13D41C_HotRopeJump = 0;
}

void func_8010BF8C_137B7C_HotRopeJump(f32 speed) {
    D_80111830_13D420_HotRopeJump = speed;
}

/* Sets the light blend's target to 1 - a (a clamped to 0..1); a sound when a is 1 while the
   target is still 1. */
void func_8010BF98_137B88_HotRopeJump(f32 a) {
    if (D_8010C264_137E54_HotRopeJump == 1.0 && a == 1.0) {
        PlaySound(0x173);
    }
    if (a > 1.0) {
        a = 1.0f;
    } else if (a < 0.0) {
        a = 0.0f;
    }
    D_8010C264_137E54_HotRopeJump = 1.0 - a;
}

/* out = (x, y, z, 1) * m (MP1 func_800FE3B4; MP1 SlotMachine func_800FCBFC).
   NON_MATCHING: masked 3, as MP1's: retail keeps out + 4 in a register */
#ifdef NON_MATCHING
void func_8010C074_137C64_HotRopeJump(Matrix4f m, f32 x, f32 y, f32 z, Vec* out) {
    f32* o = (f32*)out;

    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    o[0] = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    o[1] = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010C074_137C64_HotRopeJump);
#endif
