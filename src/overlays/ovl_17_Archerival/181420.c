#include "common.h"
#include "ovl_17.h"

void func_80102800_181420_Archerival(void) {
    func_801070A8_185CC8_Archerival();
}

void func_8010281C_18143C_Archerival(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

void func_801028A0_1814C0_Archerival(void) {
    s32 i;

    if (D_801073DC_185FFC_Archerival == 0) {
        D_801073DC_185FFC_Archerival = 1;
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 30.0f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = 950.0f;
            D_80102770_103370[i].x = 339.0f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 160.0f;
            D_801013B0_101FB0[i].z = 133.0f;
        }
    }
}

void func_801029B8_1815D8_Archerival(void) {
}

void func_801029C0_1815E0_Archerival(omObjData* obj) {
    GroundWork* gw;

    D_80108730_187350_Archerival[0] = func_8001A2F8_1AEF8(0x27000C);
    D_80107BAC_1867CC_Archerival = SprCreate(1, 0);
    SprAttrReset(D_80107BAC_1867CC_Archerival, 0, -1);
    SprScaleSet(D_80107BAC_1867CC_Archerival, 0, 1.0f, 1.0f);
    SprAnimSet(D_80107BAC_1867CC_Archerival, 0, D_80108730_187350_Archerival[0], 0);
    SprBankSet(D_80107BAC_1867CC_Archerival, 0, 0);
    SprAttrSet(D_80107BAC_1867CC_Archerival, 0, 0x5000);
    SprPosSet(D_80107BAC_1867CC_Archerival, 0, 160, 120);
    func_8008225C_82E5C(D_80107BAC_1867CC_Archerival, 0, 0);
    SprPrioSet(D_80107BAC_1867CC_Archerival, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_801029B8_1815D8_Archerival;
}

void func_80102B78_181798_Archerival(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_80107BA8_1867C8_Archerival = omAddObj(10, 0, 0, -1, func_801029C0_1815E0_Archerival);
}

void func_80102BC0_1817E0_Archerival(Gfx** gfxp) {
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
    gDPLoadTLUT_pal256(gfx++, D_801078F4_186514_Archerival->unk0C);
    for (y = 0; y < 40; y += 8) {
        gDPLoadTextureTile(gfx++, D_801078F4_186514_Archerival->unk08, G_IM_FMT_RGBA, G_IM_SIZ_8b, 192, 40, 0, y, 191,
                           y + 7, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 192 << 2, 8 << 2);
        gSPTextureRectangle(gfx++, 64 << 2, (y + 114) << 2, 256 << 2, (y + 122) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102EE4_181B04_Archerival(void) {
}

void func_80102EEC_181B0C_Archerival(omObjData* obj) {
    D_80108732_187352_Archerival = func_8001A2F8_1AEF8(0x27000D);
    D_801078F4_186514_Archerival = SprAnimGet(D_80108732_187352_Archerival);
    func_80029EDC_2AADC(func_8002838C_28F8C(0, func_80102BC0_1817E0_Archerival, 2), 1);
    obj->func_ptr = func_80102EE4_181B04_Archerival;
}

void func_80102F64_181B84_Archerival(void) {
    D_80107BF0_186810_Archerival = omAddObj(10, 0, 0, -1, func_80102EEC_181B0C_Archerival);
}

/* atan(x) in radians (a continued fraction; Crazy Cutters' func_80106D84_1E61D4_CrazyCutters). */
// NON_MATCHING: register allocation only: retail builds x / (sum + 1) in $f2 and the base in $f0
// (masked 8)
#ifdef NON_MATCHING
f32 func_80102FA0_181BC0_Archerival(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f64 base;
    f64 frac;
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
            base = 1.5707963267948966;
            frac = x / (sum + 1.0f);
            goto done;
        }
        if (sign < 0) {
            frac = x / (sum + 1.0f);
            base = -1.5707963267948966;
        done:
            return base - frac;
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80102FA0_181BC0_Archerival);
#endif

/* The direction from one point to another: out->x = distance, out->y = pitch (0 up, 90 level,
   180 down), out->z = yaw, in degrees. */
// NON_MATCHING: retail schedules the 180.0f load after the delta.y compare (as Crazy Cutters'
// func_80107204_1E6654_CrazyCutters; masked 25, all from that one shift)
#ifdef NON_MATCHING
void func_801030F0_181D10_Archerival(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
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
    horizontal = func_800B1820_B2420(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        yaw = 0.0f;
        pitch = 180.0f;
        horizontal = 0.0f;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = 0.0f;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_80102FA0_181BC0_Archerival(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_80102FA0_181BC0_Archerival(delta.y / horizontal) * 57.29577951308232;
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
    out->x = func_800B1820_B2420(delta.y * delta.y + horizontal * horizontal);
    out->y = pitch;
    out->z = yaw;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801030F0_181D10_Archerival);
#endif

/* The arrow on the title banner: flies up out of the bow and falls away (state D_80107C58). */
void func_80103458_182078_Archerival(omObjData* obj) {
    ARObj* o = &D_80107920_186540_Archerival[11];
    Vec from;
    Vec to;
    Vec dir;

    switch (D_80107C58_186878_Archerival) {
    case 1:
        obj->rot.x = 270.0f;
        obj->rot.z = 180.0f;
        o->state = 2;
        D_801073E0_186000_Archerival = 11.75f;
        D_801073E4_186004_Archerival = 8.0f;
        break;
    case 2:
        from.x = obj->trans.x;
        from.y = obj->trans.y;
        from.z = obj->trans.z;
        to.x = obj->trans.x = obj->trans.x + D_801073E0_186000_Archerival * func_800B80D0_B8CD0(obj->rot.y);
        to.z = obj->trans.z = obj->trans.z + D_801073E0_186000_Archerival * func_800B75D0_B81D0(obj->rot.y);
        to.y = obj->trans.y = obj->trans.y + D_801073E4_186004_Archerival;
        func_801030F0_181D10_Archerival(&from, &to, &dir);
        obj->rot.x = dir.y + 180.0f;
        D_801073E4_186004_Archerival -= 0.53f;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
        if (D_801073E4_186004_Archerival < 0.0f) {
            func_80029EDC_2AADC(obj->model[0], 1);
            if (obj->trans.y < -50.0f) {
                o->state = 0;
            }
        }
        break;
    }
}

void func_80103660_182280_Archerival(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x27000A, 0x2B9);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_80029EDC_2AADC(obj->model[0], 2);
    obj->func_ptr = func_80103458_182078_Archerival;
}

void func_801036C8_1822E8_Archerival(void) {
    D_80107C38_186858_Archerival = omAddObj(200, 1, 0, -1, func_80103660_182280_Archerival);
}

/* Plays motion D_801078F8[motion] on the player model with the character's skeleton name. */
void func_80103704_182324_Archerival(omObjData* obj, u8 motion) {
    s8 chr = gPlayers[obj->work[0]].character;

    func_8003E888_3F488(D_80107904_186524_Archerival);
    D_80107904_186524_Archerival =
        func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_801078F8_186518_Archerival[motion], 0,
                            D_8010760C_18622C_Archerival[chr]);
}

/* Picks one of n slots not yet set in *used at random, sets it and returns it (Look Away's
   func_801028A0_167640_LookAway with a u8 mask). */
u8 func_801037C4_1823E4_Archerival(u8 n, u8* used) {
    u8 m;
    u8 k;
    u8 i;

    m = *used;
    i = n;
    while (m != 0) {
        if (m & 1) {
            i--;
        }
        m >>= 1;
    }
    k = rand8() % i;
    m = *used;
    for (i = 0; i < n; i++) {
        if (m & 1) {
        } else if (k-- == 0) {
            break;
        }
        m >>= 1;
    }
    i = (i < n) ? i : 0;
    *used |= 1 << i;
    return i;
}

/* A CPU archer's target: the nearest target in x (entries 1-5 of D_80107920; 1-3 are the
   players' targets, 4-5 extra ones) that is not yet hit, preferring by difficulty rolls a
   target nobody aims at (D_801073CC) unless D_801073D0 rolls, or one of 1-3 (D_801073C8).
   Also ranks the candidates by distance in D_801078C8. Returns the index, 0 if none. */
// NON_MATCHING: register allocation only (masked 0)
#ifdef NON_MATCHING
u8 func_801038B4_1824D4_Archerival(omObjData* obj) {
    u8 diff;
    u8 rollA;
    u8 rollB;
    u8 rollC;
    u8 nNear;
    u8 nFree;
    u8 nLeft;
    u16 best;
    u8 bestIdx;
    u16 i;
    u16 j;
    u16 d;
    u16 sd;
    u16 si;
    u16 td;
    u16 ti;
    s32 t;
    ARRank* r;
    ARObj* tbl;
    ARObj* p;

    diff = gPlayers[obj->work[0]].cpu_difficulty;
    rollA = (u8)(rand8() % 100) < D_801073C8_185FE8_Archerival[diff];
    rollB = (u8)(rand8() % 100) < D_801073CC_185FEC_Archerival[diff];
    rollC = (u8)(rand8() % 100) < D_801073D0_185FF0_Archerival[diff];
    nNear = 0;
    nFree = 0;
    nLeft = 0;
    best = 0xFFFF;
    bestIdx = 0;
    r = D_801078C8_1864E8_Archerival;
    for (i = 0; i < 5; i++, r++) {
        r->dist = best;
        r->idx = bestIdx;
    }
    for (i = 1, tbl = D_80107920_186540_Archerival; i < 6; i++) {
        p = i + tbl;
        if (p->unk_26 == 0) {
            if (i < 4) {
                if (p->com == 0) {
                    nFree++;
                }
                nNear++;
            }
            nLeft++;
        }
    }
    if (nLeft == 0) {
        return 0;
    }
    rollB = nFree ? rollB : 0;
    rollA = nNear ? rollA : 0;
    rollB = !rollC ? rollB : 0;
    for (i = 1, tbl = D_80107920_186540_Archerival; i < 6; i++) {
        p = i + tbl;
        if (p->unk_26 != 0) {
            continue;
        }
        if (rollB) {
            if (p->com != 0) {
                continue;
            }
        } else if (rollA) {
            if (i >= 4) {
                continue;
            }
        }
        d = t = obj->trans.x + D_801078EC_18650C_Archerival - p->obj->trans.x;
        if (t < 0) {
            d = -d;
        }
        if (d < best) {
            best = d;
            bestIdx = i;
        }
        r = D_801078C8_1864E8_Archerival;
        for (j = 0; j < 5; r++) {
            j++;
            if (d < r->dist) {
                sd = r->dist;
                si = r->idx;
                r->dist = d;
                r->idx = i;
                for (r++; j < 5; j++, r++) {
                    td = r->dist;
                    ti = r->idx;
                    r->dist = sd;
                    r->idx = si;
                    sd = td;
                    si = ti;
                }
                break;
            }
        }
    }
    return bestIdx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801038B4_1824D4_Archerival);
#endif

/* A CPU archer's walk towards its target: returns 1 when within 8 of it, else the x distance
   to walk in *dx; with no target yet, picks one (func_801038B4_1824D4_Archerival). */
// NON_MATCHING: register allocation only (masked 0): retail keeps the distance in $v0
#ifdef NON_MATCHING
s32 func_80103C1C_18283C_Archerival(omObjData* obj, s32 unused, s16* dx, u8* target) {
    s32 d;
    ARObj* p;
    s32 ret = 0;

    if (*target != 0) {
        p = &D_80107920_186540_Archerival[*target];
        d = obj->trans.x + D_801078EC_18650C_Archerival - p->obj->trans.x;
        if (d < 0) {
            d = -d;
        }
        if ((u16)d < 8) {
            ret = 1;
        } else {
            *dx = p->obj->trans.x - (obj->trans.x + D_801078EC_18650C_Archerival);
        }
    } else {
        *target = func_801038B4_1824D4_Archerival(obj);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80103C1C_18283C_Archerival);
#endif

/* Starts motion obj->motion[mot] (Mecha Marathon's func_80103CA8_1F29E8_MechaMarathon). */
void func_80103CF0_182910_Archerival(omObjData* obj, u16 mot, s16 start, s16 speed, s16 flags) {
    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[mot]), start, speed, flags);
}

/* Walks the player along x by 4 a frame in the stick's direction (dir < 0 left, > 0 right),
   clamped to +-200 around the aim offset, with the walk motion and a footstep sound every
   21 frames; dir 0 goes back to the idle motion. *state: 0 idle, 1 walk starting, 2 walking.
   The aiming pose (D_801078E6) has its own walk (4) and idle (3) motions. */
void func_80103D7C_18299C_Archerival(omObjData* obj, s16 dir, s16* state) {
    u16 walk;
    u16 idle;
    f32 t;
    f32 lim;

    walk = 4;
    if (D_801078E6_186506_Archerival == 0) {
        walk = 1;
    }
    idle = D_801078E6_186506_Archerival ? 3 : 0;
    if (dir != 0) {
        switch (*state) {
        case 0:
            func_80103CF0_182910_Archerival(obj, walk, 0, 7, 1);
            *state = 1;
            goto step;
        case 1:
            if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
                func_80029B80_2A780(obj->model[0], obj->motion[walk]);
                func_80029C74_2A874(obj->model[0], 0.0f);
                if (dir > 0) {
                    func_80029E80_2AA80(obj->model[0], 2, 2);
                } else {
                    func_80029E80_2AA80(obj->model[0], 6, 6);
                }
                *state = 2;
            }
            goto tick;
        case 2:
            t = func_80029CE4_2A8E4(obj->model[0]);
            if (func_80029D0C_2A90C(obj->model[0]) <= t) {
                func_80029B80_2A780(obj->model[0], obj->motion[walk]);
                func_80029C74_2A874(obj->model[0], 0.0f);
                if (dir > 0) {
                    func_80029E80_2AA80(obj->model[0], 2, 2);
                } else {
                    func_80029E80_2AA80(obj->model[0], 6, 6);
                }
            }
        tick:
            if (--D_80107870_186490_Archerival == 0) {
            step:
                if (D_80107624_186244_Archerival >= 0) {
                    func_80079848_7A448(D_80107624_186244_Archerival);
                }
                D_80107624_186244_Archerival = func_80079798_7A398(0x34, obj->work[0]);
                D_80107870_186490_Archerival = 21;
            }
            break;
        }
        obj->trans.x += (dir > 0) ? 4.0f : -4.0f;
        if (dir > 0) {
            lim = 200.0f - D_801078EC_18650C_Archerival;
            if (obj->trans.x > lim) {
                obj->trans.x = lim;
                return;
            }
        }
        if (dir < 0) {
            if (obj->trans.x < -(D_801078EC_18650C_Archerival + 200.0f)) {
                obj->trans.x = -(D_801078EC_18650C_Archerival + 200.0f);
            }
        }
    } else if (*state != 0) {
        func_80103CF0_182910_Archerival(obj, idle, 0, 7, 1);
        *state = 0;
        if (D_80107624_186244_Archerival >= 0) {
            func_80079848_7A448(D_80107624_186244_Archerival);
        }
    }
}

__asm__(".section .rodata");
const char D_80107660_186280_Archerival[] = "c005_000-bmerge6";

__asm__(".section .rodata");
const char D_80107674_186294_Archerival[] = "c005_000-cyl1_1_3";

__asm__(".section .rodata");
const char D_80107688_1862A8_Archerival[] = "Luigi1-migi-te1_1";

__asm__(".section .rodata");
const char D_8010769C_1862BC_Archerival[] = "Luigi1-karada_2_1_1";

__asm__(".section .rodata");
const char D_801076B0_1862D0_Archerival[] = "c003_000-bmerge1_8";

__asm__(".section .rodata");
const char D_801076C4_1862E4_Archerival[] = "c003_000-yoshi_body_2_3";

__asm__(".section .rodata");
const char D_801076DC_1862FC_Archerival[] = "C002_000b-bmerge16";

__asm__(".section .rodata");
const char D_801076F0_186310_Archerival[] = "C002_000b-cone7_1_1_1_1_1";

__asm__(".section .rodata");
const char D_8010770C_18632C_Archerival[] = "c001_000-migi-te2_3";

__asm__(".section .rodata");
const char D_80107720_186340_Archerival[] = "c001_000-karada_1";

__asm__(".section .rodata");
const char D_80107734_186354_Archerival[] = "migi-te3_2_1";

__asm__(".section .rodata");
const char D_80107744_186364_Archerival[] = "karada_2_1_1_1";

__asm__(".section .rodata");
const char D_80107754_186374_Archerival[] = "c005l_0_DEF";

__asm__(".section .rodata");
const char D_80107760_186380_Archerival[] = "c004l_0_DEF";

__asm__(".section .rodata");
const char D_8010776C_18638C_Archerival[] = "c003l_0_DEF";

__asm__(".section .rodata");
const char D_80107778_186398_Archerival[] = "c002l_0_DEF";

__asm__(".section .rodata");
const char D_80107784_1863A4_Archerival[] = "c001l_0_DEF";

__asm__(".section .rodata");
const char D_80107790_1863B0_Archerival[] = "c000l_0_DEF";

/* The archer (D_80107920[0]): state D_801078E6. 0 walk (stick or func_80103C1C's CPU walk) until
   A (or the CPU in range) draws the bow; 1 draw, the arrow hooked to the hand; 2 aim (the CPU
   picks its next target, at difficulty 0 sometimes feinting D_80107629 times among the ranked
   ones); 3 aim and walk until A (or the CPU in range) fires; 4 fire: the arrow flies from the
   bow (D_80107920[11].state = 1); 5-6 back to the walk pose. When the game ends (D_801078DE 3):
   7 turn to the camera, 8 win/lose motion, voice and jingle (D_801078E0 1 won, 2 lost), 9 the
   win voice after a per-character delay. Places the shadow / stand (model[1]). */
// NON_MATCHING: correct logic; retail reloads across three branches (case 3 and case 7 fire = 1 sit out of line), register and scheduling residue
#ifdef NON_MATCHING
void func_801040B0_182CD0_Archerival(omObjData* obj) {
    ARObj* tbl;
    ARObj* arrow;
    omObjData* arrowObj;
    s16 dir;
    s16 fire;
    s16 n;
    u8 used;
    f32 t;
    f32 h;

    tbl = D_80107920_186540_Archerival;
    arrow = &tbl[11];
    arrowObj = tbl[11].obj;
    dir = 0;
    fire = 0;
    switch (D_801078E6_186506_Archerival) {
    case 0:
        if (D_801078DE_1864FE_Archerival == 2) {
            if (tbl[0].com == 0) {
                if (arrow->state == 0 && (ContBtnTrg[gPlayers[obj->work[0]].port] & 0x8000)) {
                    fire = 1;
                } else {
                    dir = ContStkX[gPlayers[obj->work[0]].port];
                }
            } else if (arrow->state == 0) {
                fire = func_80103C1C_18283C_Archerival(obj, tbl, &dir, &D_80107628_186248_Archerival);
            }
            if (fire) {
                func_80103CF0_182910_Archerival(obj, 2, 0, 5, 1);
                D_801078E6_186506_Archerival = 1;
            } else {
                func_80103D7C_18299C_Archerival(obj, dir, &D_80107626_186246_Archerival);
            }
        } else if (D_801078DE_1864FE_Archerival == 3) {
            func_80103CF0_182910_Archerival(obj, 0, 0, 5, 1);
            if (_CheckFlag(0xC) == 0) {
                D_801078E6_186506_Archerival = 7;
                tbl[0].unk_30 = (obj->trans.x <= 0.0f) ? -20 : 20;
            } else {
                D_801078E6_186506_Archerival = 9;
            }
        }
        break;
    case 1:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            D_801078E6_186506_Archerival = 2;
            if (arrowObj != NULL) {
                func_80029EDC_2AADC(arrowObj->model[0], 2);
                func_800298A4_2A4A4(arrowObj->model[0], 4, 0);
                func_800298A4_2A4A4(arrowObj->model[0], 0x4000, 0x4000);
                func_8002C628_2D228(arrowObj->model[0], obj->model[0], "item_hook");
            }
        }
        break;
    case 2:
        if (func_80029CE4_2A8E4(obj->model[0]) == 56.0f) {
            PlaySound(0x1D7);
        }
        t = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= t) {
            D_801078E6_186506_Archerival = 3;
            D_80107626_186246_Archerival = 0;
            D_80107629_186249_Archerival = 0;
            if (tbl[0].com != 0) {
                if ((u8)(rand8() % 100) < 50) {
                    D_80107628_186248_Archerival = 0;
                }
                n = 0;
                if (gPlayers[obj->work[0]].cpu_difficulty == 0) {
                loop:
                    if (D_801078CA_1864EA_Archerival[n * 2] != 0) {
                        if (++n < 5) {
                            goto loop;
                        }
                    }
                    if (n >= 2) {
                        if (n < 3) {
                            D_8010762A_18624A_Archerival = n;
                        } else {
                            D_8010762A_18624A_Archerival = 3;
                        }
                        D_8010762B_18624B_Archerival = 0;
                        D_80107628_186248_Archerival = D_801078C8_1864E8_Archerival[func_801037C4_1823E4_Archerival(
                            D_8010762A_18624A_Archerival, &D_8010762B_18624B_Archerival)].idx;
                        D_80107629_186249_Archerival = rand8() % 3;
                    }
                }
            }
        }
        break;
    case 3:
        if (D_801078DE_1864FE_Archerival == 3) {
            fire = 1;
        } else if (tbl[0].com == 0) {
            if (ContBtnTrg[gPlayers[obj->work[0]].port] & 0x8000) {
                fire = 1;
            } else {
                dir = ContStkX[gPlayers[obj->work[0]].port];
            }
        } else {
            fire = func_80103C1C_18283C_Archerival(obj, tbl, &dir, &D_80107628_186248_Archerival);
            if (fire != 0 && D_80107629_186249_Archerival != 0) {
                used = D_8010762B_18624B_Archerival;
                n = func_801037C4_1823E4_Archerival(D_8010762A_18624A_Archerival, &D_8010762B_18624B_Archerival);
                D_8010762B_18624B_Archerival = used ^ D_8010762B_18624B_Archerival;
                D_80107628_186248_Archerival = D_801078C8_1864E8_Archerival[(u8)n].idx;
                D_80107629_186249_Archerival--;
                fire = 0;
            }
        }
        if (fire) {
            func_80103CF0_182910_Archerival(obj, 3, 0, 1, 1);
            D_801078E6_186506_Archerival = 4;
        } else {
            func_80103D7C_18299C_Archerival(obj, dir, &D_80107626_186246_Archerival);
        }
        break;
    case 4:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[3]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80079798_7A398(0x1D8, obj->work[0]);
            if (tbl[0].com == 0) {
                omVibrate(obj->work[0], 20, 0, 20);
            }
            D_801078E6_186506_Archerival = 5;
            if (arrowObj != NULL) {
                func_800298A4_2A4A4(arrowObj->model[0], 0x4000, 0);
                arrow->state = 1;
                arrowObj->trans.x = obj->trans.x + D_801078EC_18650C_Archerival;
                arrowObj->trans.y = obj->trans.y + 100.0f;
                arrowObj->trans.z = obj->trans.z;
                arrowObj->rot.y = obj->rot.y;
            }
        }
        break;
    case 5:
        t = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= t) {
            func_80103CF0_182910_Archerival(obj, 0, 0, 20, 1);
            D_801078E6_186506_Archerival = 6;
        }
        break;
    case 6:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[0]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            D_801078E6_186506_Archerival = 0;
            D_80107626_186246_Archerival = 0;
            D_80107628_186248_Archerival = 0;
        }
        break;
    case 7:
        if (obj->rot.y != 0.0f) {
            obj->rot.y += tbl[0].unk_30;
            if (obj->rot.y >= 360.0f || obj->rot.y <= 0.0f) {
                obj->rot.y = 0.0f;
                fire = 1;
            }
        } else {
            fire = 1;
        }
        if (fire && func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            D_801078E6_186506_Archerival = 8;
        }
        break;
    case 8:
        if (D_801078E0_186500_Archerival == 1) {
            func_80029B80_2A780(obj->model[0], obj->motion[5]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80103704_182324_Archerival(obj, 1);
            switch (gPlayers[obj->work[0]].character) {
            case 0:
                D_80107906_186526_Archerival = 49;
                break;
            case 1:
                D_80107906_186526_Archerival = 58;
                break;
            case 2:
                D_80107906_186526_Archerival = 53;
                break;
            case 3:
                D_80107906_186526_Archerival = 38;
                break;
            case 4:
                D_80107906_186526_Archerival = 45;
                break;
            case 5:
                D_80107906_186526_Archerival = 27;
                break;
            }
            PlayMusic(0x51);
            D_801078E6_186506_Archerival = 9;
        } else if (D_801078E0_186500_Archerival == 2) {
            func_80029B80_2A780(obj->model[0], obj->motion[6]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80103704_182324_Archerival(obj, 2);
            PlayMusic(0x52);
            D_801078E6_186506_Archerival = 9;
        }
        break;
    case 9:
        if (D_801078E0_186500_Archerival == 1 && D_80107906_186526_Archerival > 0) {
            if (--D_80107906_186526_Archerival == 0) {
                func_800797DC_7A3DC(0x103, obj->work[0]);
            }
        }
        break;
    }
    if (D_801078F0_186510_Archerival != 0) {
        if (D_801078E6_186506_Archerival < 7) {
            h = 50.0f;
        } else {
            h = 0.0f;
        }
    } else {
        h = 15.0f;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, tbl[0].unk_38, h + obj->trans.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801040B0_182CD0_Archerival);
__asm__(".section .rodata");
const u32 jtbl_801077B8_1863D8_Archerival[6] = { 0x80104690, 0x80104774, 0x801047CC, 0x80104848, 0x80104908, 0x80104A20 };

__asm__(".section .rodata");
const u32 jtbl_801077D0_1863F0_Archerival[6] = { 0x80104990, 0x80104998, 0x801049A0, 0x801049A8, 0x801049B0, 0x801049B8 };
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80104AEC_18370C_Archerival);

void func_8010506C_183C8C_Archerival(void) {
    ARObj* tbl = D_80107920_186540_Archerival;
    omObjData* o;
    s16 i;
    s16 player;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        player = 1;
        break;
    case 2:
        player = 2;
        break;
    case 3:
        player = 3;
        break;
    case 0:
    default:
        player = 0;
        break;
    }
    o = omAddObj(100, 11, 60, -1, func_80104AEC_18370C_Archerival);
    tbl->player = player;
    o->work[0] = player;
    tbl->obj = o;
    D_800FFFD8_100BD8[D_800FC87A_FD47A] = o;
    D_800FC87A_FD47A++;
}

/* Drops n coins at a broken target, one every 5 frames, if the five slots are not used up. */
void func_80105180_183DA0_Archerival(f32 x, f32 y, f32 z, u8 n) {
    ARCoin* c;
    u16 i;

    for (i = 0; i < n; i++) {
        if (D_801078EB_18650B_Archerival >= 5) {
            break;
        }
        c = &D_80107878_186498_Archerival[D_801078EB_18650B_Archerival++];
        c->x = x;
        c->y = y;
        c->z = z;
        c->active = 1;
        c->delay = i * 5;
    }
}

__asm__(".section .rodata");
const u32 D_801077E8_186408_Archerival[2] = { 0x01DB01DD, 0x01DA0000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010520C_183E2C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010549C_1840BC_Archerival);

__asm__(".section .rodata");
const u32 D_801077F0_186410_Archerival[2] = { 0x00010002, 0x00030000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105878_184498_Archerival);

void func_80105C84_1848A4_Archerival(omObjData* obj, ARObj* p) {
    switch (p->unk_26) {
    case 0:
        func_80105878_184498_Archerival(obj, p);
        break;
    case 1:
        if (obj->rot.y != 0.0f) {
            obj->rot.x += 4.0f;
            if (obj->rot.x >= 120.0f) {
                obj->rot.x = 120.0f;
            }
        } else {
            if (obj->rot.x == 0.0f) {
                obj->rot.x = 360.0f;
            }
            obj->rot.x -= 4.0f;
            if (obj->rot.x <= 240.0f) {
                obj->rot.x = 240.0f;
            }
        }
        obj->trans.y -= 1.3f;
        obj->trans.z += 0.4f;
        if (obj->trans.y < 0.0f) {
            p->unk_26 = 2;
        }
        break;
    case 2:
        break;
    }
}

void func_80105DD0_1849F0_Archerival(omObjData* obj) {
    ARObj* p;
    s16 i;

    for (i = 1; i < 4; i++) {
        p = &D_80107920_186540_Archerival[i];
        if (p->player == obj->work[0]) {
            break;
        }
    }
    func_80105C84_1848A4_Archerival(obj, p);
}

void func_80105E38_184A58_Archerival(omObjData* obj) {
    ARFile files[6] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 } };
    ARObj* p;
    s16 i;
    u8 chr;
    u8 n;

    for (i = 1; i < 4; i++) {
        p = &D_80107920_186540_Archerival[i];
        if (p->player == obj->work[0]) {
            break;
        }
    }
    chr = gPlayers[obj->work[0]].character;
    n = func_801037C4_1823E4_Archerival(5, &D_801078DC_1864FC_Archerival);
    obj->trans.x = D_80107390_185FB0_Archerival[n].x;
    obj->trans.y = D_80107390_185FB0_Archerival[n].y;
    obj->trans.z = D_80107390_185FB0_Archerival[n].z;
    obj->model[0] = LoadFormFile(files[chr].unk_04 | 0x270000, 0x2B9);
    obj->model[1] = LoadFormFile(10, 0x28D);
    func_800297E8_2A3E8(obj->model[1], 0.4f, 0.4f, 0.4f);
    if (gPlayers[obj->work[0]].flags & 1) {
        p->com = 1;
    } else {
        p->com = 0;
        func_8010281C_18143C_Archerival(obj->work[0]);
    }
    p->unk_30 = 0;
    p->unk_2A = 1;
    p->timer = 1;
    p->unk_26 = 0;
    p->unk_24 = 0;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_80105DD0_1849F0_Archerival;
}

// NON_MATCHING: retail copies the switch value first (Look Away's 80105B4C does the same), registers only
#ifdef NON_MATCHING
void func_80106064_184C84_Archerival(void) {
    ARObj* p;
    omObjData* o;
    s32 slot;
    s16 i;
    s16 k;
    s16 player;

    D_801078DC_1864FC_Archerival = 4;
    slot = 1;
    for (i = 0; i < 4; i++) {
        if (D_8010794E_18656E_Archerival != i) {
            p = &D_80107920_186540_Archerival[slot];
            o = omAddObj(300, 2, 1, -1, func_80105E38_184A58_Archerival);
            k = i;
            switch (k) {
            case 1:
                player = 1;
                break;
            case 2:
                player = 2;
                break;
            case 3:
                player = 3;
                break;
            case 0:
            default:
                player = 0;
                break;
            }
            p->player = player;
            o->work[0] = player;
            p->obj = o;
            slot++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106064_184C84_Archerival);
#endif

void func_8010618C_184DAC_Archerival(omObjData* obj) {
    ARObj* p;
    s16 i;

    for (i = 4; i < 6; i++) {
        p = &D_80107920_186540_Archerival[i];
        if (p->player == obj->work[0]) {
            break;
        }
    }
    func_80105C84_1848A4_Archerival(obj, p);
}

void func_801061F4_184E14_Archerival(omObjData* obj) {
    ARFile files[3] = { { 0, 6 }, { 0, 7 }, { 0, 8 } };
    ARObj* p;
    s16 i;
    u8 kind;
    u8 n;

    for (i = 4; i < 6; i++) {
        p = &D_80107920_186540_Archerival[i];
        if (p->player == obj->work[0]) {
            break;
        }
    }
    kind = p->player - 4;
    if (++D_8010762C_18624C_Archerival == 1) {
        D_801078DC_1864FC_Archerival ^= 4;
    }
    n = func_801037C4_1823E4_Archerival(5, &D_801078DC_1864FC_Archerival);
    obj->trans.x = D_80107390_185FB0_Archerival[n].x;
    obj->trans.y = D_80107390_185FB0_Archerival[n].y;
    obj->trans.z = D_80107390_185FB0_Archerival[n].z;
    obj->model[0] = LoadFormFile(files[kind].unk_04 | 0x270000, 0x2B9);
    obj->model[1] = LoadFormFile(10, 0x28D);
    func_800297E8_2A3E8(obj->model[1], 0.4f, 0.4f, 0.4f);
    p->com = 1;
    p->unk_30 = 0;
    p->unk_2A = 1;
    p->timer = p->player - 4;
    p->unk_26 = 0;
    p->unk_24 = 0;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_8010618C_184DAC_Archerival;
}

void func_801063FC_18501C_Archerival(void) {
    ARObj* p;
    omObjData* o;
    s16 i;
    s16 n;
    u8 used;

    i = 0;
    used = 0;
    for (; i < 2; i++) {
        p = &D_80107A40_186660_Archerival[i];
        o = omAddObj(400, 2, 1, -1, func_801061F4_184E14_Archerival);
        n = func_801037C4_1823E4_Archerival(3, &used) + 4;
        p->player = n;
        o->work[0] = n;
        p->obj = o;
    }
}

void func_801064BC_1850DC_Archerival(omObjData* obj) {
    ARObj* p;
    ARCoin* c;
    s16 i;

    for (i = 12; i < 17; i++) {
        p = &D_80107920_186540_Archerival[i];
        if (p->player == obj->work[0]) {
            break;
        }
    }
    c = &D_801077B8_1863D8_Archerival[i];
    switch (p->state) {
    case 0:
        if (c->active != 0) {
            if (c->delay == 0) {
                obj->trans.x = c->x;
                obj->trans.y = c->y;
                obj->trans.z = c->z;
                func_800298A4_2A4A4(obj->model[0], 4, 0);
                p->state = 1;
                p->unk_38 = 15.0f;
                PlaySound(9);
            } else {
                c->delay--;
            }
        }
        break;
    case 1:
        obj->trans.y += p->unk_38;
        p->unk_38 += -1.5f;
        if (p->unk_38 <= 0.0f) {
            p->unk_22 = 8;
            p->state = 2;
        }
        break;
    case 2:
        if (p->unk_22-- == 0) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z + 20.0f);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
            p->state = 3;
        }
        break;
    }
}

// NON_MATCHING: retail keeps the entry's byte offset in s0 across the calls, register and scheduling residue
#ifdef NON_MATCHING
void func_801066C0_1852E0_Archerival(omObjData* obj) {
    u16 idx;

    obj->model[0] = LoadFormFile(7, 0x68D);
    idx = func_80018D64_19964(0xE, 0xA89, 8);
    obj->model[0] = D_800F86D8_F92D8[idx].unk00;
    HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
    func_8003E808_3F408(D_800F86D8_F92D8[idx].unk02, (u32)(((u32)guRandom() >> 4) % 300) / 100);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    obj->model[1] = LoadFormFile(8, 0x68D);
    func_800297E8_2A3E8(obj->model[1], 0.6f, 0.6f, 0.6f);
    func_8002CDF0_2D9F0(obj->model[1], 0x3F, 0x1F, 0, 0x3F);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_801064BC_1850DC_Archerival;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801066C0_1852E0_Archerival);
#endif

void func_8010687C_18549C_Archerival(void) {
    ARObj* p;
    omObjData* o;
    s16 i;

    for (i = 0; i < 5; i++) {
        p = &((ARObj*)&D_80107C80_1868A0_Archerival)[i];
        o = omAddObj(600, 2, 2, -1, func_801066C0_1852E0_Archerival);
        p->player = i;
        o->work[0] = i;
        p->obj = o;
    }
}

void func_8010691C_18553C_Archerival(omObjData* obj) {
    if (D_80107630_186250_Archerival != 0) {
        if (--D_80107630_186250_Archerival == 0) {
            func_8006D518_6E118();
        }
    }
    if (D_801078E4_186504_Archerival != 0) {
        D_801078E4_186504_Archerival--;
    }
}

void func_8010697C_18559C_Archerival(omObjData* obj) {
    if (D_801078E2_186502_Archerival != 0) {
        D_801078E2_186502_Archerival--;
    }
    func_8006D4D0_6E0D0((D_801078E2_186502_Archerival + 29) / 30);
    if (D_801078DE_1864FE_Archerival == 3) {
        D_801078E4_186504_Archerival = 60;
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
        obj->func_ptr = func_8010691C_18553C_Archerival;
        D_801078E2_186502_Archerival = 0;
    }
}

void func_80106A30_185650_Archerival(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    obj->func_ptr = func_8010697C_18559C_Archerival;
}

void func_80106A70_185690_Archerival(omObjData* obj) {
    switch (D_801078DE_1864FE_Archerival) {
    case 1:
        if (D_801078E2_186502_Archerival == 0) {
            func_800691FC_69DFC(0);
            D_801078E2_186502_Archerival++;
        }
        break;
    case 2:
        obj->func_ptr = func_80106A30_185650_Archerival;
        break;
    }
}

void func_80106AE4_185704_Archerival(void) {
    ARObj* tbl;
    omObjData* o;
    s16 win;
    s16 i;

    i = 0;
    tbl = D_80107920_186540_Archerival;
    for (; i < 4; i++) {
        o = tbl[i].obj;
        if (o != NULL) {
            win = 0;
            if (D_801078E0_186500_Archerival == 1) {
                win = gPlayers[o->work[0]].group == 0;
            } else if (gPlayers[o->work[0]].group != 0) {
                win = 1;
            }
            if (win) {
                gPlayers[o->work[0]].coins_mg_bonus = 10;
            }
        }
    }
}

void func_80106BDC_1857FC_Archerival(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80106C00_185820_Archerival(omObjData* obj) {
    s16 i;

    if (func_8008F618_90218() == 0) {
        for (i = 0; i < 3; i++) {
            DataClose(D_801078F8_186518_Archerival[i]);
        }
        obj->func_ptr = func_80106BDC_1857FC_Archerival;
    }
}

void func_80106C80_1858A0_Archerival(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_80106C00_185820_Archerival;
    }
}

// NON_MATCHING: retail keeps k in a2 for func_800691FC's third argument (one instruction fewer), as Look Away's 80106060
#ifdef NON_MATCHING
void func_80106CD8_1858F8_Archerival(omObjData* obj) {
    ARObj* tbl;
    u8 chars[4];
    s16 i;
    s16 k;
    s32 t;

    switch (D_801078DE_1864FE_Archerival) {
    case 0:
        if (D_801078E2_186502_Archerival == 0) {
            PlayMusic(0x20);
        }
        if (D_801078E2_186502_Archerival++ >= 31) {
            D_801078DE_1864FE_Archerival = 1;
            D_801078E2_186502_Archerival = 0;
        }
        break;
    case 1:
        if (func_80069538_6A138() == 0) {
            D_801078DE_1864FE_Archerival = 2;
            D_801078E2_186502_Archerival = 901;
        }
        break;
    case 2:
        if (D_801078E2_186502_Archerival == 0 || D_801078E8_186508_Archerival >= 3) {
            D_801078DE_1864FE_Archerival = 3;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 0 && D_801078E6_186506_Archerival >= 7) {
            D_801078E0_186500_Archerival = (D_801078E8_186508_Archerival == 3) ? 1 : 2;
            D_801078DE_1864FE_Archerival = 4;
            D_801078E2_186502_Archerival = 0;
            if (_CheckFlag(0xC) == 0) {
                k = 0;
                if (D_801078E0_186500_Archerival == 1) {
                    chars[0] = gPlayers[D_80107920_186540_Archerival[0].obj->work[0]].character;
                    func_800691FC_69DFC(6, chars[0], k);
                    D_801078E2_186502_Archerival = 120;
                } else {
                    i = 1;
                    tbl = D_80107920_186540_Archerival;
                    for (; i < 4; i++, k++) {
                        chars[k] = gPlayers[tbl[i].obj->work[0]].character;
                    }
                    func_800691FC_69DFC(0x15, chars[0], chars[1], chars[2]);
                    D_801078E2_186502_Archerival = 168;
                }
            }
            func_80106AE4_185704_Archerival();
            gPlayers[D_80107920_186540_Archerival[0].obj->work[0]].coins_mg = D_801078EA_18650A_Archerival;
        }
        break;
    case 4:
        if (_CheckFlag(0xC) != 0) {
            t = D_801078E4_186504_Archerival;
        } else {
            t = --D_801078E2_186502_Archerival;
        }
        if (t == 0) {
            D_801078DE_1864FE_Archerival = 5;
        }
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106C00_185820_Archerival;
        break;
    }
    func_801028A0_1814C0_Archerival();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106CD8_1858F8_Archerival);
#endif

void func_80106FCC_185BEC_Archerival(omObjData* obj) {
    func_801072E0_185F00_Archerival();
    func_80107364_185F84_Archerival();
    func_80102B78_181798_Archerival();
    func_80102F64_181B84_Archerival();
    func_801036C8_1822E8_Archerival();
    func_8010506C_183C8C_Archerival();
    func_80106064_184C84_Archerival();
    func_801063FC_18501C_Archerival();
    func_8010687C_18549C_Archerival();
    InitFadeIn(0, 16);
    obj->func_ptr = func_80106CD8_1858F8_Archerival;
    D_801078DE_1864FE_Archerival = 0;
    D_801078E2_186502_Archerival = 0;
    D_801078E4_186504_Archerival = 0;
    D_801078E8_186508_Archerival = 0;
    D_801078EA_18650A_Archerival = 0;
    D_801078E0_186500_Archerival = 0;
    D_801078EB_18650B_Archerival = 0;
    D_801078E6_186506_Archerival = 0;
    omAddObj(900, 0, 0, -1, func_80106A70_185690_Archerival);
}

__asm__(".section .rodata");
const char D_80107860_186480_Archerival[16] = "\202`\202a\202b";

void func_801070A8_185CC8_Archerival(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0x40, 0x40, 0x40);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, 0.0f, 100.0f, 100.0f);
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 26.2f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 26.2f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_80106FCC_185BEC_Archerival);
    omAddObj(1000, 0, 0, -1, func_80106C80_1858A0_Archerival);
    func_8007273C_7333C((u8*)D_80107860_186480_Archerival, 0);
    func_8007273C_7333C((u8*)D_80107860_186480_Archerival, 1);
}
