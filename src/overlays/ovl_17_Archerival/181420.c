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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80103C1C_18283C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80103CF0_182910_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80103D7C_18299C_Archerival);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801040B0_182CD0_Archerival);

__asm__(".section .rodata");
const u32 D_801077B8_1863D8_Archerival[6] = { 0x80104690, 0x80104774, 0x801047CC, 0x80104848, 0x80104908, 0x80104A20 };

__asm__(".section .rodata");
const u32 jtbl_801077D0_1863F0_Archerival[6] = { 0x80104990, 0x80104998, 0x801049A0, 0x801049A8, 0x801049B0, 0x801049B8 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80104AEC_18370C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010506C_183C8C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105180_183DA0_Archerival);

__asm__(".section .rodata");
const u32 D_801077E8_186408_Archerival[2] = { 0x01DB01DD, 0x01DA0000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010520C_183E2C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010549C_1840BC_Archerival);

__asm__(".section .rodata");
const u32 D_801077F0_186410_Archerival[2] = { 0x00010002, 0x00030000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105878_184498_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105C84_1848A4_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105DD0_1849F0_Archerival);

__asm__(".section .rodata");
const u32 D_801077F8_186418_Archerival[12] = { 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000003, 0x00000000, 0x00000004, 0x00000000, 0x00000005 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80105E38_184A58_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106064_184C84_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010618C_184DAC_Archerival);

__asm__(".section .rodata");
const u32 D_80107828_186448_Archerival[6] = { 0x00000000, 0x00000006, 0x00000000, 0x00000007, 0x00000000, 0x00000008 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801061F4_184E14_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801063FC_18501C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801064BC_1850DC_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801066C0_1852E0_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010687C_18549C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010691C_18553C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_8010697C_18559C_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106A30_185650_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106A70_185690_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106AE4_185704_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106BDC_1857FC_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106C00_185820_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106C80_1858A0_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106CD8_1858F8_Archerival);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_80106FCC_185BEC_Archerival);

__asm__(".section .rodata");
const char D_80107860_186480_Archerival[16] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_Archerival/181420", func_801070A8_185CC8_Archerival);
