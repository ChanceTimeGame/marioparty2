#include "ovl_36.h"

#define ACTOR D_80107870_274F50_DizzyDancing
#define MODEL(i) (&D_800FC834_FD434[i])


void func_80102800_26FEE0_DizzyDancing(void) {
    func_801072F0_2749D0_DizzyDancing();
}

void func_8010281C_26FEFC_DizzyDancing(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

u8 func_801028A0_26FF80_DizzyDancing(u8 n, u64* used) {
    u64 m;
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

/* NON_MATCHING: register allocation only (masked 0): retail keeps base in $f0 and the quotient in $f2. */
#ifdef NON_MATCHING
f32 func_801029F0_2700D0_DizzyDancing(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f32 q;
    f64 frac;
    f64 base;
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
            q = x / (sum + 1.0f);
            base = 1.5707963267948966;
            frac = q;
            goto done;
        }
        if (sign < 0) {
            q = x / (sum + 1.0f);
            frac = q;
            base = -1.5707963267948966;
        done:
            return base - frac;
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_801029F0_2700D0_DizzyDancing);
#endif

/* NON_MATCHING: the 180.0f load is scheduled before the near-zero test (same residue as ovl_0A, ovl_23). */
#ifdef NON_MATCHING
void func_80102B40_270220_DizzyDancing(Vec* from, Vec* to, Vec* out) {
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
        horizontal = yaw;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = yaw;
        }
    } else {
        if (delta.x != 0.0f || delta.z != 0.0f) {
            yaw = func_801029F0_2700D0_DizzyDancing(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f || delta.y != 0.0f) {
            pitch = func_801029F0_2700D0_DizzyDancing(delta.y / horizontal) * 57.29577951308232;
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
    horizontal = func_800B1820_B2420(delta.y * delta.y + horizontal * horizontal);
    out->x = horizontal;
    out->y = pitch;
    out->z = yaw;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_80102B40_270220_DizzyDancing);
#endif

f32 func_80102EB4_270594_DizzyDancing(f32 angle, f32 add) {
    angle += add;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

void func_80102F0C_2705EC_DizzyDancing(omObjData* obj, MgWork* w, f32 x, f32 y, f32 z) {
    Vec from;
    Vec to;
    Vec polar;
    f32 yaw;

    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = x;
    to.y = y;
    to.z = z;
    func_80102B40_270220_DizzyDancing(&from, &to, &polar);
    yaw = polar.z;
    if (yaw > 180.0f) {
        yaw -= 360.0f;
    }
    w->unk_3C = yaw;
}

void func_80102F9C_27067C_DizzyDancing(void) {
    Vec from;
    Vec to;
    Vec polar;
    s32 i;

    if (D_801075F0_274CD0_DizzyDancing == 0) {
        from.x = 20.765f;
        from.y = 0.0f;
        from.z = -32.945f;
        to.x = 1991.675f;
        to.y = 0.0f;
        to.z = 1802.175f;
        func_80102B40_270220_DizzyDancing(&from, &to, &polar);
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 25.2f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = polar.x;
            D_80102770_103370[i].x = 360.0f - polar.z;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 20.765f;
            D_801013B0_101FB0[i].z = -32.945f;
        }
        D_801075F0_274CD0_DizzyDancing = 1;
    }
}

void func_8010311C_2707FC_DizzyDancing(Gfx** gfxp) {
    Gfx* gfx;
    s32 y;

    gfx = *gfxp;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0x3F0604);
    gSPSetGeometryMode(gfx++, 0x200404);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetRenderMode(gfx++, 0x553048, 0);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, D_80107868_274F48_DizzyDancing->palette);
    for (y = 0; y < 80; y += 4) {
        gDPLoadTextureTile(gfx++, D_80107868_274F48_DizzyDancing->pixels, G_IM_FMT_RGBA, G_IM_SIZ_8b, 320, 0, 0, y, 319, y + 4, 0,
                           0, 0, 0, 0, 0, 0);
        gDPSetTileSize(gfx++, 0, 0, 0, 0x500, 0x10);
        gSPTextureRectangle(gfx++, 0, (y + 160) * 4, 320 * 4, (y + 164) * 4, 0, 0, 0, 1024, 1024);
    }
    *gfxp = gfx;
}

void func_80103440_270B20_DizzyDancing(omObjData* obj) {
}

void func_80103448_270B28_DizzyDancing(omObjData* obj) {
    D_80108680_275D60_DizzyDancing[1] = func_8001A2F8_1AEF8(0x460001);
    D_80107868_274F48_DizzyDancing = SprAnimGet(D_80108680_275D60_DizzyDancing[1]);
    func_80029EDC_2AADC(func_8002838C_28F8C(0, func_8010311C_2707FC_DizzyDancing, 2), 1);
    obj->func_ptr = func_80103440_270B20_DizzyDancing;
}

void func_801034C0_270BA0_DizzyDancing(void) {
    D_801079D8_2750B8_DizzyDancing = omAddObj(10, 0, 0, -1, func_80103448_270B28_DizzyDancing);
}

void func_801034FC_270BDC_DizzyDancing(omObjData* obj) {
}


void func_80103504_270BE4_DizzyDancing(omObjData* obj) {
    GroundWork* w;
    u8 map[16] = { 0, 1, 0, 1, 0, 2, 3, 4, 2, 1, 2, 1, 2, 0, 3, 4 };

    D_8010785B_274F3B_DizzyDancing = rand8() & 1;
    D_8010785C_274F3C_DizzyDancing = map[D_8010785B_274F3B_DizzyDancing * 8 + (rand8() & 7)];
    D_80108680_275D60_DizzyDancing[0] = func_8001A2F8_1AEF8(0x460000);
    D_80107994_275074_DizzyDancing = SprCreate(1, 0);
    SprAttrReset(D_80107994_275074_DizzyDancing, 0, -1);
    SprScaleSet(D_80107994_275074_DizzyDancing, 0, 1.0f, 1.0f);
    SprAnimSet(D_80107994_275074_DizzyDancing, 0, D_80108680_275D60_DizzyDancing[0], 0);
    SprBankSet(D_80107994_275074_DizzyDancing, 0, 0);
    SprAttrSet(D_80107994_275074_DizzyDancing, 0, 0x5000);
    SprPosSet(D_80107994_275074_DizzyDancing, 0, 160, 120);
    func_8008225C_82E5C(D_80107994_275074_DizzyDancing, 0, 0);
    SprPrioSet(D_80107994_275074_DizzyDancing, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = D_80107858_274F38_DizzyDancing++;
    func_8000BEA4_CAA4(obj, 0.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -532.0f, -523.0f, 532.0f, 523.0f);
    obj->func_ptr = func_801034FC_270BDC_DizzyDancing;
}

void func_80103760_270E40_DizzyDancing(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_80107990_275070_DizzyDancing = omAddObj(10, 0, 0, -1, func_80103504_270BE4_DizzyDancing);
}

/* NON_MATCHING: masked 20: retail copies hit to $v0 before two tests and its $s4 is reused for the actor base. */
#ifdef NON_MATCHING
void func_801037A8_270E88_DizzyDancing(omObjData* obj) {
    Vec from;
    Vec to;
    Vec polar;
    DDActor* p;
    DDActor* t;
    omObjData* o;
    MgWork* w;
    f32 r;
    s16 i;
    s32 a;
    u16 mdl;
    s32 hit;

    t = &D_80107A20_275100_DizzyDancing;
    hit = 0;
    switch (D_80107A40_275120_DizzyDancing) {
    case 0:
        if (t->unk_22++ >= 31) {
            t->state = 1;
            t->unk_22 = 0;
        }
        break;
    case 1:
        t->unk_3C += 0.025f;
        if (t->unk_3C > 0.25f) {
            t->unk_3C = 0.25f;
        }
        if (D_8010785B_274F3B_DizzyDancing != 0) {
            t->unk_38 += t->unk_3C;
            if (t->unk_38 > 20.0f) {
                t->unk_38 = 20.0f;
            }
        } else {
            t->unk_38 -= t->unk_3C;
            if (t->unk_38 < -20.0f) {
                t->unk_38 = -20.0f;
            }
        }
        a = t->unk_38;
        if (a < 0) {
            a = -a;
        }
        t->unk_40 = (f32)a - 15.0f;
        if (t->unk_40 < 0.0f) {
            t->unk_40 = 0.0f;
        } else {
            t->unk_40 = t->unk_40 / 2.0f;
        }
        break;
    case 2:
        if (D_8010785B_274F3B_DizzyDancing != 0) {
            t->unk_38 -= 0.25f;
            if (t->unk_38 <= 1.0f) {
                t->unk_38 = 1.0f;
                t->state = 3;
            }
        } else {
            t->unk_38 += 0.25f;
            if (t->unk_38 >= -1.0f) {
                t->unk_38 = -1.0f;
                t->state = 3;
            }
        }
        break;
    case 3:
        if (D_80107852_274F32_DizzyDancing & 0x18) {
            t->unk_38 = 0.0f;
            t->state = 4;
        }
        break;
    case 4:
        break;
    }
    if (t->unk_38 != 0.0f) {
        mdl = obj->model[1];
        MODEL(mdl)->rot.y = func_80102EB4_270594_DizzyDancing(MODEL(mdl)->rot.y, t->unk_38);
        from.x = obj->trans.x;
        from.y = obj->trans.y + 62.5;
        from.z = obj->trans.z;
        for (i = 0; i < 4; i++) {
            p = &ACTOR[i];
            if (p->unk_30 != 0) {
                o = p->obj;
                to.x = o->trans.x;
                to.y = o->trans.y;
                to.z = o->trans.z;
                func_80102B40_270220_DizzyDancing(&from, &to, &polar);
                if (polar.x > 395.0f) {
                    p->unk_30 = 0;
                    continue;
                }
                polar.z = func_80102EB4_270594_DizzyDancing(polar.z, t->unk_38);
                if (t->state == 1) {
                    r = polar.x + t->unk_40;
                    if (r > 345.0f) {
                        r = 345.0f;
                        if (o->work[1] == 0) {
                            hit = 1;
                        }
                    }
                } else {
                    r = polar.x;
                }
                o->trans.x = r * func_800B80D0_B8CD0(polar.z);
                o->trans.z = r * func_800B75D0_B81D0(polar.z);
                w = o->unk_50;
                w->unk_3C += t->unk_38;
                if (w->unk_3C > 180.0f) {
                    w->unk_3C -= 360.0f;
                }
                if (t->state == 1 && o->work[1] == 0) {
                    if ((a = hit) != 0) {
                        if (D_8010785B_274F3B_DizzyDancing != 0) {
                            if (!(D_801075F4_274CD4_DizzyDancing > 0.0f && o->trans.x < 0.0f)) {
                                hit = 0;
                            }
                        } else if (!(D_801075F8_274CD8_DizzyDancing > 0.0f && o->trans.z < 0.0f)) {
                            hit = 0;
                        }
                    }
                    D_801075F4_274CD4_DizzyDancing = o->trans.x;
                    D_801075F8_274CD8_DizzyDancing = o->trans.z;
                }
            }
        }
        if ((a = hit) != 0) {
            for (i = 0; i < 4; i++) {
                p = &ACTOR[i];
                p->state = 1;
                p->unk_30 = 0;
                func_800797DC_7A3DC(0x111, i);
            }
            t->state = 2;
        }
        D_801075FC_274CDC_DizzyDancing = (f32)(((u8)(rand8() % 3) - 1) * 0.5) + D_801075FC_274CDC_DizzyDancing;
        if (D_801075FC_274CDC_DizzyDancing > 75.0f) {
            D_801075FC_274CDC_DizzyDancing = 75.0f;
        }
        if (D_801075FC_274CDC_DizzyDancing < 65.0f) {
            D_801075FC_274CDC_DizzyDancing = 65.0f;
        }
        D_80107600_274CE0_DizzyDancing = (f32)(((u8)(rand8() % 3) - 1) * 0.5) + D_80107600_274CE0_DizzyDancing;
        if (D_80107600_274CE0_DizzyDancing > 75.0f) {
            D_80107600_274CE0_DizzyDancing = 75.0f;
        }
        if (D_80107600_274CE0_DizzyDancing < 65.0f) {
            D_80107600_274CE0_DizzyDancing = 65.0f;
        }
        MODEL(obj->model[3])->rot.y = D_801075FC_274CDC_DizzyDancing;
        MODEL(obj->model[4])->rot.y = D_80107600_274CE0_DizzyDancing;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_801037A8_270E88_DizzyDancing);
#endif

void func_80103EF8_2715D8_DizzyDancing(omObjData* obj) {
    GroundWork* w;
    s16 i;

    obj->model[1] = LoadFormFile(0x460002, 0x2B9);
    obj->model[2] = LoadFormFile(0x460004, 0x2B9);
    obj->model[3] = LoadFormFile(0x460003, 0x2B9);
    obj->model[4] = LoadFormFile(0x460003, 0x2B9);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = D_80107858_274F38_DizzyDancing++;
    func_8000BEA4_CAA4(obj, 0.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BFA8_CBA8(obj, 62.5f, 62.5f, 395.0f);
    func_80029714_2A314(obj->model[1], 0.0f, 0.0f, 0.0f);
    MODEL(obj->model[3])->rot.y = 70.0f;
    MODEL(obj->model[4])->rot.y = 70.0f;
    for (i = 1; i < 5; i++) {
        func_80029EDC_2AADC(obj->model[i], 1);
    }
    obj->func_ptr = func_801037A8_270E88_DizzyDancing;
}

void func_801040D4_2717B4_DizzyDancing(void) {
    D_80107A20_275100_DizzyDancing.obj = omAddObj(20, 4, 0, -1, func_80103EF8_2715D8_DizzyDancing);
}

void func_80104110_2717F0_DizzyDancing(omObjData* obj) {
}


void func_80104118_2717F8_DizzyDancing(omObjData* obj) {
    Vec table[4] = { { -650.0f, 0.0f, -650.0f }, { 650.0f, 0.0f, -650.0f }, { -650.0f, 0.0f, 650.0f }, { 650.0f, 0.0f, 650.0f } };
    Vec* v;
    GroundWork* w;

    v = &table[obj->work[0]];
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = D_80107858_274F38_DizzyDancing++;
    func_8000BEA4_CAA4(obj, 0.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BFA8_CBA8(obj, 6000.0f, 6000.0f, 190.0f);
    obj->trans.x = v->x * 0.82f;
    obj->trans.y = v->y * 0.82f;
    obj->trans.z = v->z * 0.82f;
    obj->func_ptr = func_80104110_2717F0_DizzyDancing;
}

void func_80104284_271964_DizzyDancing(void) {
    omObjData* o;
    DDActor* p;
    s16 i;

    for (i = 0; i < 4; i++) {
        p = &D_80107AB0_275190_DizzyDancing[i];
        o = omAddObj(30, 1, 0, -1, func_80104118_2717F8_DizzyDancing);
        o->work[0] = i;
        p->obj = o;
    }
}

s16 func_80104320_271A00_DizzyDancing(omObjData* obj, Vec* hit) {
    Vec tri[3];
    Vec ball;
    omObjData* o;
    MgWork* w;

    o = D_80107A68_275148_DizzyDancing.obj;
    w = obj->unk_50;
    HuVecCopyXYZ(&ball, o->trans.x, o->trans.y, o->trans.z);
    HuVecCopyXYZ(&tri[0], obj->trans.x, obj->trans.y, obj->trans.z);
    HuVecCopyXYZ(&tri[1], obj->trans.x + w->unk_48, obj->trans.y + w->unk_34, obj->trans.z);
    HuVecCopyXYZ(&tri[2], obj->trans.x - w->unk_48, obj->trans.y + w->unk_34, obj->trans.z);
    if (func_8001B434_1C034(tri, &ball, 50.0f, hit) != 0) {
        return 1;
    }
    HuVecCopyXYZ(&tri[1], obj->trans.x, obj->trans.y + w->unk_34, obj->trans.z + w->unk_48);
    HuVecCopyXYZ(&tri[2], obj->trans.x, obj->trans.y + w->unk_34, obj->trans.z - w->unk_48);
    return func_8001B434_1C034(tri, &ball, 50.0f, hit);
}

/* NON_MATCHING: masked 2: f32 d is converted once, scheduled differently; $f4/$f6 swapped. */
#ifdef NON_MATCHING
void func_8010449C_271B7C_DizzyDancing(omObjData* obj) {
    Vec hit;
    u64 used;
    DDActor* b;
    DDActor* p;
    f32 s;
    f32 d;
    s16 i;

    b = &D_80107A68_275148_DizzyDancing;
    switch (D_80107A88_275168_DizzyDancing) {
    case 0:
        if (D_80107852_274F32_DizzyDancing & 1) {
            b->state = 1;
            b->unk_22 = 1;
            b->unk_24 = 1;
            b->unk_38 = 10.0f;
        }
        break;
    case 1:
        obj->trans.y -= b->unk_38;
        if (obj->trans.y < 625.0f) {
            b->state = 2;
            D_80107852_274F32_DizzyDancing |= 2;
        }
        break;
    case 2:
        b->unk_38 -= 0.5f;
        if (b->unk_38 < 0.0f) {
            b->unk_38 = 0.0f;
            b->state = 3;
        }
        obj->trans.y -= b->unk_38;
        break;
    case 3:
        used = 0;
        for (i = 0; i < 4; i++) {
            p = &ACTOR[i];
            if (func_80104320_271A00_DizzyDancing(p->obj, &hit) == 0) {
                used |= 1 << i;
            } else {
                PlaySound(0x2F2);
                D_80107852_274F32_DizzyDancing |= 8;
            }
        }
        if (D_80107852_274F32_DizzyDancing & 8) {
            p = &ACTOR[func_801028A0_26FF80_DizzyDancing(4, &used)];
            D_8010785A_274F3A_DizzyDancing = p->obj->work[0];
            if (p->unk_2C == 0) {
                omVibrate(D_8010785A_274F3A_DizzyDancing, 10, 0, 10);
            }
            b->state = 6;
            b->unk_22 = 0;
            b->unk_38 = 1.0f;
            b->unk_3C = 0.0f;
        } else if (D_80107852_274F32_DizzyDancing & 0x10) {
            b->state = 4;
            PlaySound(0x2F4);
        }
        break;
    case 4:
        if (b->unk_38 != 10.0f) {
            b->unk_38 += 0.5f;
            if (b->unk_38 > 10.0f) {
                b->unk_38 = 10.0f;
            }
        }
        obj->trans.y += b->unk_38;
        if (obj->trans.y > 1000.0f) {
            b->state = 5;
            b->unk_22 = 0;
            b->unk_24 = 0;
            omSetSca(obj, 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
        }
        break;
    case 6:
        b->unk_38 += 0.1f;
        if (b->unk_38 > 2.0f) {
            b->state = 7;
        }
        omSetSca(obj, b->unk_38, b->unk_38, b->unk_38);
        break;
    case 7:
        b->unk_3C += 12.0f;
        obj->rot.y += b->unk_3C;
        if (obj->rot.y > 360.0f) {
            obj->rot.y -= 360.0f;
        }
        b->unk_38 *= 0.8f;
        if (b->unk_38 < 0.2f) {
            b->unk_38 = 0.0f;
            b->state = 8;
            b->unk_24 = 0;
            func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
        }
        omSetSca(obj, b->unk_38, b->unk_38, b->unk_38);
        break;
    case 5:
    case 8:
    case 9:
        break;
    }
    if (b->unk_22 != 0) {
        D_80107604_274CE4_DizzyDancing += 2.0f;
        if (D_80107604_274CE4_DizzyDancing > 360.0f) {
            D_80107604_274CE4_DizzyDancing -= 360.0f;
        }
        D_80107608_274CE8_DizzyDancing += 5.0f;
        if (D_80107608_274CE8_DizzyDancing > 360.0f) {
            D_80107608_274CE8_DizzyDancing -= 360.0f;
        }
        s = HuMathSin(D_80107608_274CE8_DizzyDancing) * 0.2f + 1.0f;
        omSetSca(obj, s, 1.0f, HuMathSin(2.0f * D_80107608_274CE8_DizzyDancing + D_80107604_274CE4_DizzyDancing) * 0.2f + 1.0f);
    }
    if (b->unk_24 != 0) {
        d = obj->trans.y * 0.001f;
        func_800297E8_2A3E8(obj->model[1], obj->scale.x + 0.7 - d, obj->scale.y + 0.7 - d, obj->scale.z + 0.7 - d);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_8010449C_271B7C_DizzyDancing);
#endif

void func_80104AB4_272194_DizzyDancing(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x46000B, 0x6B9);
    obj->model[1] = func_80018A30_19630(1, 0xA9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(MODEL(obj->model[1])->mtx, 0.0f, 5.0f, 0.0f);
    obj->trans.y = 1000.0f;
    func_80029714_2A314(obj->model[1], 0.0f, 64.5f, 0.0f);
    func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_8010449C_271B7C_DizzyDancing;
}

void func_80104BCC_2722AC_DizzyDancing(void) {
    D_80107A68_275148_DizzyDancing.obj = omAddObj(50, 2, 0, -1, func_80104AB4_272194_DizzyDancing);
}

u8 func_80104C08_2722E8_DizzyDancing(u16* table) {
    u8 r;
    u8 i;

    r = rand8();
    for (i = 0; i < 5; i++) {
        if (r < *table) {
            break;
        }
        table++;
    }
    return i;
}

#ifndef NON_MATCHING
__asm__(".section .rodata");
const u32 D_80107710_274DF0_DizzyDancing[3] = { 0x00330066, 0x009900CC, 0x01000000 };
const u32 D_8010771C_274DFC_DizzyDancing[3] = { 0x002A0054, 0x007E00A8, 0x00D20100 };
const u32 D_80107728_274E08_DizzyDancing[3] = { 0x00190033, 0x00660099, 0x00CC0100 };
const u32 D_80107734_274E14_DizzyDancing[3] = { 0x00000000, 0x0032007D, 0x01000000 };
const u32 D_80107740_274E20_DizzyDancing[3] = { 0x00000000, 0x000A0064, 0x009C0100 };
const u32 D_8010774C_274E2C_DizzyDancing[3] = { 0x00000000, 0x00320089, 0x00E00100 };
__asm__(".section .text");
#endif
/* NON_MATCHING: register allocation only (masked 0): c and t swap $s0/$s1. */
#ifdef NON_MATCHING
u8 func_80104C5C_27233C_DizzyDancing(omObjData* obj, s16 near) {
    u16* t;
    DDCpu* c = &D_801086F0_275DD0_DizzyDancing[obj->work[0]];
    u16 t0[6] = { 0x33, 0x66, 0x99, 0xCC, 0x100, 0 };
    u16 t1[6] = { 0x2A, 0x54, 0x7E, 0xA8, 0xD2, 0x100 };
    u16 t2[6] = { 0x33, 0x66, 0x99, 0xCC, 0x100, 0 };
    u16 t3[6] = { 0x19, 0x33, 0x66, 0x99, 0xCC, 0x100 };
    u16 t4[6] = { 0, 0, 0x32, 0x7D, 0x100, 0 };
    u16 t5[6] = { 0, 0, 0xA, 0x64, 0x9C, 0x100 };
    u16 t6[6] = { 0, 0, 0x32, 0x89, 0xE0, 0x100 };
    u16 t7[6] = { 0, 0, 0xA, 0x64, 0x9C, 0x100 };
    u8 r;

    switch (gPlayers[obj->work[0]].cpu_difficulty) {
    case 1:
        r = 1;
        if (c->flags & 2) {
            t = t3;
            if (D_80107854_274F34_DizzyDancing >= 601) {
                t = t2;
            }
            if (rand8() < 100 && c->dist > 395.0f) {
                r = 5;
            } else {
                r = func_80104C08_2722E8_DizzyDancing(t);
            }
        } else {
            c->flags |= 2;
        }
        break;
    case 2:
        r = 1;
        if (c->flags & 2) {
            t = t5;
            if (D_80107854_274F34_DizzyDancing >= 751) {
                t = t4;
            }
            if (rand8() < 200 && c->dist > 395.0f) {
                r = 5;
            } else {
                r = func_80104C08_2722E8_DizzyDancing(t);
            }
        } else {
            c->flags |= 2;
        }
        break;
    case 3:
        r = 1;
        if (c->flags & 2) {
            t = t7;
            if (D_80107854_274F34_DizzyDancing >= 811) {
                t = t6;
            }
            if (rand8() < 225 && c->dist > 395.0f) {
                r = 5;
            } else {
                r = func_80104C08_2722E8_DizzyDancing(t);
            }
        } else {
            c->flags |= 2;
        }
        break;
    default:
        if (c->flags & 2) {
            t = t1;
            if (D_80107854_274F34_DizzyDancing >= 451) {
                t = t0;
            }
            if (rand8() < 50 && c->dist > 395.0f) {
                r = 5;
            } else {
                r = func_80104C08_2722E8_DizzyDancing(t);
            }
        } else {
            r = rand8() % 3;
            if (r == 1) {
                c->flags |= 2;
            }
        }
        break;
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_80104C5C_27233C_DizzyDancing);
#endif

/* NON_MATCHING: masked 29: $s2/$s3 swapped; v0/v1 swapped in the 0x4000 press; a delay-slot li. */
#ifdef NON_MATCHING
void func_8010504C_27272C_DizzyDancing(omObjData* obj) {
    Vec polar;
    Vec from;
    Vec to;
    DDActor* a;
    DDActor* q;
    DDCpu* c;
    MgWork* w;
    omObjData* o;
    f32 yaw;
    f32 best;
    f32 speed;
    f32 heading;
    s32 n;
    s16 i;
    s16 near;

    a = &ACTOR[obj->work[0]];
    w = obj->unk_50;
    c = &D_801086F0_275DD0_DizzyDancing[obj->work[0]];
    from.x = obj->trans.x;
    from.y = 0.0f;
    from.z = obj->trans.z;
    to.x = 0.0f;
    to.y = 0.0f;
    to.z = 0.0f;
    func_80102B40_270220_DizzyDancing(&from, &to, &polar);
    c->dist = polar.x;
    yaw = polar.z;
    if (yaw > 180.0f) {
        yaw -= 360.0f;
    }
    c->angle = yaw;
    best = 65535.0f;
    near = -1;
    for (i = 0; i < 4; i++) {
        c->otherDist[i] = 0.0f;
        c->otherAngle[i] = 0.0f;
        if (i != obj->work[0]) {
            q = &ACTOR[i];
            o = q->obj;
            to.x = o->trans.x;
            to.y = 0.0f;
            to.z = o->trans.z;
            func_80102B40_270220_DizzyDancing(&from, &to, &polar);
            c->otherDist[i] = polar.x;
            c->otherAngle[i] = polar.z > 180.0f ? polar.z - 360.0f : polar.z;
            c->otherY[i] = o->trans.y;
            if (c->otherDist[i] < best) {
                best = c->otherDist[i];
                near = i;
            }
        }
    }
    speed = 0.0f;
    heading = w->unk_3C;
    switch (a->unk_2A) {
    case 0:
        switch (func_80104C5C_27233C_DizzyDancing(obj, near)) {
        case 1:
            a->unk_38 = w->unk_3C;
            a->unk_3C = (rand8() & 3) + 6;
            if (rand8() & 1) {
                a->unk_3C = -a->unk_3C;
            }
            a->unk_28 = (u8)(rand8() % 30) + 30;
            a->unk_2A = 1;
            c->flags |= 1;
            speed = 50.0f;
            break;
        case 2:
            heading = (u8)(rand8() % 180);
            if (rand8() & 1) {
                heading = -heading;
            }
            a->unk_28 = 10;
            a->unk_2A = 3;
            ContBtnTrg[w->unk_57] |= 0x8000;
            c->flags |= 1;
            speed = 50.0f;
            break;
        case 3:
            a->unk_28 = (rand8() & 0x1F) + 15;
            a->unk_2A = 4;
            break;
        case 4:
            a->unk_28 = (rand8() & 0x1F) + 15;
            a->unk_2A = 5;
            break;
        case 5:
            a->unk_2A = 7;
            a->unk_28 = (rand8() & 0xF) + 15;
            break;
        default:
            a->unk_28 = (rand8() & 0xF) + 10;
            a->unk_2A = 2;
            break;
        }
        break;
    case 1:
        a->unk_38 += a->unk_3C;
        if (a->unk_38 > 180.0f) {
            a->unk_38 -= 360.0f;
        }
        heading = a->unk_38;
        if (--a->unk_28 == 0) {
            a->unk_2A = 0;
        }
        speed = 50.0f;
        break;
    case 2:
        if (a->unk_28 != 0) {
            a->unk_28--;
        } else if (w->unk_38 == 1000.0f) {
            a->unk_2A = 0;
        }
        break;
    case 3:
        if (a->unk_28 != 0) {
            a->unk_28--;
            speed = 50.0f;
        } else if (w->unk_38 == 1000.0f) {
            a->unk_2A = 0;
        } else {
            speed = 50.0f;
        }
        if (speed != 0.0f) {
            ContBtn[w->unk_57] |= 0x8000;
        }
        break;
    case 4:
        if (--a->unk_28 == 0) {
            a->unk_2A = 0;
        }
        if (c->dist < 470.0f && c->otherY[near] == 62.5 && obj->trans.y != 62.5) {
            ContBtnTrg[w->unk_57] |= 0x8000;
            ContBtn[w->unk_57] |= 0x8000;
        }
        if (c->otherDist[near] < 155.0f && w->unk_38 == 1000.0f) {
            ContBtnTrg[w->unk_57] |= 0x4000;
            n = 15;
        wait:
            a->unk_28 = n;
            a->unk_2A = 2;
        }
        heading = c->otherAngle[near];
        c->flags |= 1;
        speed = 50.0f;
        break;
    case 5:
        if (--a->unk_28 == 0) {
            a->unk_2A = 0;
        }
        if (w->unk_38 != 1000.0f) {
            a->unk_2A = 6;
        }
        if ((c->dist < 470.0f && c->otherY[near] == 62.5 && obj->trans.y != 62.5) || c->otherDist[near] < 170.0f) {
            ContBtnTrg[w->unk_57] |= 0x8000;
            ContBtn[w->unk_57] |= 0x8000;
        }
        heading = c->otherAngle[near];
        c->flags |= 1;
        speed = 50.0f;
        break;
    case 6:
        if (w->unk_38 != 1000.0f) {
            if (c->otherDist[near] < 60.0f) {
                ContBtnTrg[w->unk_57] |= 0x2000;
                n = 20;
                goto wait;
            }
            ContBtn[w->unk_57] |= 0x8000;
        } else {
            n = 20;
            goto wait;
        }
        heading = c->otherAngle[near];
        c->flags |= 1;
        speed = 50.0f;
        break;
    case 7:
        if ((c->dist < 470.0f && obj->trans.y != 62.5) || c->dist < 125.0f) {
            ContBtnTrg[w->unk_57] |= 0x8000;
            ContBtn[w->unk_57] |= 0x8000;
        }
        heading = c->angle;
        c->flags |= 1;
        speed = 50.0f;
        if (--a->unk_28 == 0) {
            a->unk_2A = 0;
        }
        break;
    case 8:
        break;
    }
    if (w->unk_38 == 1000.0f) {
        w->unk_3C = heading;
        c->stkX = ContStkX[w->unk_57] = (s32)(speed * HuMathSin(heading));
        c->stkY = ContStkY[w->unk_57] = (s32)(-speed * func_800B7890_B8490(w->unk_3C));
    } else {
        ContStkX[w->unk_57] = (s8)c->stkX;
        ContStkY[w->unk_57] = (s8)c->stkY;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_8010504C_27272C_DizzyDancing);
#endif

s32 func_80105A4C_27312C_DizzyDancing(omObjData* obj) {
    D_801078A0_274F80_DizzyDancing[obj->work[0] * 0x24] = 1;
    return 0;
}

s32 func_80105A74_273154_DizzyDancing(omObjData* obj) {
    DDActor* p;

    p = &ACTOR[obj->work[0]];
    if (p->state == 2 || p->state == 3) {
        func_80019B9C_1A79C(obj, 0x27);
        return 1;
    } else {
        p->unk_30 = 1;
        return 0;
    }
}

s32 func_80105AD0_2731B0_DizzyDancing(omObjData* obj) {
    D_801078A0_274F80_DizzyDancing[obj->work[0] * 0x24] = 0;
    return 0;
}

void func_80105AF4_2731D4_DizzyDancing(omObjData* obj, u8 player) {
    MgWork* w;
    DDCpu* c;
    s16 port;
    s8 tmp;
    s32 v;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;

    w = obj->unk_50;
    c = &D_801086F0_275DD0_DizzyDancing[obj->work[0]];
    port = gPlayers[obj->work[0]].port;
    if (ContStkX[port] >= 30) {
        ContStkX[port] = 30;
    }
    if (ContStkY[port] >= 30) {
        ContStkY[port] = 30;
    }
    if (ContStkX[port] < -29) {
        ContStkX[port] = -30;
    }
    if (ContStkY[port] < -29) {
        ContStkY[port] = -30;
    }
    if (w->unk_40 >= 7.5) {
        w->unk_40 = 7.5f;
    }
    if (w->unk_40 <= -7.5) {
        w->unk_40 = -7.5f;
    }
    if (!(c->flags & 1)) {
        switch (D_8010785C_274F3C_DizzyDancing) {
        case 1:
            v = ContStkX[port];
            ContStkX[port] = -v;
            v2 = ContStkY[port];
            ContStkY[port] = -v2;
            break;
        case 2:
            tmp = ContStkX[port];
            ContStkX[port] = ContStkY[port];
            v3 = tmp;
            ContStkY[port] = -v3;
            break;
        case 3:
            v3 = ContStkY[port];
            ContStkY[port] = -v3;
            break;
        case 4:
            v4 = ContStkX[port];
            ContStkX[port] = -v4;
            break;
        default:
            tmp = ContStkX[port];
            v5 = ContStkY[port];
            ContStkX[port] = -v5;
            ContStkY[port] = tmp;
            break;
        }
    }
}

void func_80105D70_273450_DizzyDancing(omObjData* obj, u16 a, u16 b) {
    MgWork* w;
    DDMotion* ma;
    DDMotion* mb;
    s16 mo;
    s16 v0;
    s16 v2;

    w = obj->unk_50;
    ma = (DDMotion*)w->unk_E8 + a;
    mb = (DDMotion*)w->unk_E8 + b;
    mo = obj->motion[a];
    v0 = ma->unk_00;
    v2 = ma->unk_02;
    obj->motion[a] = obj->motion[b];
    ma->unk_00 = mb->unk_00;
    ma->unk_02 = mb->unk_02;
    obj->motion[b] = mo;
    mb->unk_00 = v0;
    mb->unk_02 = v2;
}

#ifndef NON_MATCHING
__asm__(".section .rodata");
const u32 D_801077C0_274EA0_DizzyDancing[12] = { 0xC3EB0000, 0x00000000, 0xC3910000, 0x43EB0000, 0x00000000, 0xC3910000, 0xC3EB0000, 0x00000000, 0x43910000, 0x43EB0000, 0x00000000, 0x43910000 };
__asm__(".section .text");
#endif
/* NON_MATCHING: masked 26: one register copy before the flag test. */
#ifdef NON_MATCHING
void func_80105DF0_2734D0_DizzyDancing(omObjData* obj) {
    DDActor* a = &D_80107870_274F50_DizzyDancing[obj->work[0]];
    Vec table[4] = { { -470.0f, 0.0f, -290.0f }, { 470.0f, 0.0f, -290.0f }, { -470.0f, 0.0f, 290.0f }, { 470.0f, 0.0f, 290.0f } };
    Vec to;
    Vec from;
    Vec polar;
    DDCpu* c;
    MgWork* w;
    f32 heading;
    f32 ccw;
    f32 step;
    f32 x;
    s32 flag;
    s16 i;
    u8 p;
    DDActor* q;

    w = obj->unk_50;
    c = &D_801086F0_275DD0_DizzyDancing[obj->work[0]];
    if (D_80107850_274F30_DizzyDancing != 2 || a->unk_2C != 0) {
        func_8010281C_26FEFC_DizzyDancing(obj->work[0]);
    }
    flag = 0;
    switch (a->state) {
    case 1:
        to.x = table[obj->work[1]].x;
        to.y = table[obj->work[1]].y;
        to.z = table[obj->work[1]].z;
        from.x = obj->trans.x;
        from.y = obj->trans.y;
        from.z = obj->trans.z;
        func_80102B40_270220_DizzyDancing(&to, &from, &polar);
        a->unk_38 = polar.z;
        a->unk_3C = polar.x;
        a->state = 2;
        /* fallthrough */
    case 2:
        a->unk_3C -= 80.0f;
        if (a->unk_3C < 0.0f) {
            a->unk_3C = 0.0f;
        }
        obj->trans.x = a->unk_3C * func_800B80D0_B8CD0(a->unk_38) + table[obj->work[1]].x;
        obj->trans.z = a->unk_3C * func_800B75D0_B81D0(a->unk_38) + table[obj->work[1]].z;
        if (a->unk_3C == 0.0f) {
            a->state = 3;
            func_800191D4_19DD4(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
            func_80102F0C_2705EC_DizzyDancing(obj, w, 0.0f, 0.0f, 0.0f);
            func_80105D70_273450_DizzyDancing(obj, 0, 0x26);
            D_80107852_274F32_DizzyDancing |= 1;
            if (a->unk_2C == 0) {
                omVibrate(obj->work[0], 10, 0, 10);
            }
            func_80079798_7A398(0x2F3, obj->work[0]);
        }
        break;
    case 3:
        if (D_80107852_274F32_DizzyDancing & 2) {
            func_80019B9C_1A79C(obj, 0x12);
            a->state = 4;
        }
        break;
    case 4:
        if (func_80019000_19C00(obj) == 1 && func_80018FF0_19BF0(obj) == 0x12) {
            D_80107852_274F32_DizzyDancing |= 4;
            a->state = 5;
        }
        break;
    case 5:
        if (D_80107852_274F32_DizzyDancing & 0x18) {
            func_80105D70_273450_DizzyDancing(obj, 0, 0x26);
            if (func_80018FF0_19BF0(obj) == 0) {
                func_80019CA4_1A8A4(obj, 0);
            }
            a->state = 6;
            a->unk_28 = 1;
        } else if (a->unk_2C != 0 && D_80107850_274F30_DizzyDancing == 2) {
            func_8010504C_27272C_DizzyDancing(obj);
        }
        break;
    case 6:
        if (func_80018FF0_19BF0(obj) == 0) {
            if (D_80107852_274F32_DizzyDancing & 0x10) {
                heading = w->unk_3C;
                func_80102F0C_2705EC_DizzyDancing(obj, w, 0.0f, 0.0f, 0.0f);
                a->unk_44 = w->unk_3C;
                w->unk_3C = heading;
            } else {
                a->unk_44 = 0.0f;
            }
            heading = a->unk_44 - w->unk_3C;
            if (heading < 0.0f) {
                heading += 360.0f;
            }
            ccw = w->unk_3C - a->unk_44;
            if (ccw < 0.0f) {
                ccw += 360.0f;
            }
            if (heading < ccw) {
                a->unk_3C = heading;
                step = 20.0f;
            } else {
                a->unk_3C = ccw;
                step = -20.0f;
            }
            a->unk_40 = step;
            a->unk_38 = w->unk_3C;
            a->state = 7;
            c->flags |= 1;
        } else {
            if (a->unk_28 != 0 && --a->unk_28 == 0) {
                to.x = obj->trans.x;
                to.y = 0.0f;
                to.z = obj->trans.z;
                from.x = 0.0f;
                from.y = 0.0f;
                from.z = 0.0f;
                func_80102B40_270220_DizzyDancing(&to, &from, &polar);
                x = polar.z;
                if (x > 180.0f) {
                    x -= 360.0f;
                }
                w->unk_3C = x;
                c->stkX = (s32)(HuMathSin(x) * 50.0f);
                c->stkY = (s32)(func_800B7890_B8490(w->unk_3C) * -50.0f);
                c->flags |= 1;
            }
            if (w->unk_38 == 1000.0f) {
                c->stkX = 0;
                c->stkY = 0;
            } else {
                ContStkX[w->unk_57] = (s8)c->stkX;
                ContStkY[w->unk_57] = (s8)c->stkY;
            }
        }
        break;
    case 7:
        a->unk_38 += a->unk_40;
        if (a->unk_38 > 180.0f) {
            a->unk_38 -= 360.0f;
        }
        w->unk_3C = a->unk_38;
        a->unk_3C -= 20.0f;
        if (a->unk_3C <= 0.0f) {
            w->unk_3C = a->unk_44;
            a->state = 8;
        }
        break;
    case 8:
        w->unk_3C = a->unk_44;
        if (D_80107850_274F30_DizzyDancing == 4) {
            if (_CheckFlag(0xC) == 0) {
                a->state = 9;
                if ((D_80107852_274F32_DizzyDancing & 0x10) || obj->work[0] != D_8010785A_274F3A_DizzyDancing) {
                    func_80019B9C_1A79C(obj, 0xE);
                } else {
                    func_80019B9C_1A79C(obj, 0xD);
                    p = obj->work[0];
                    func_800732B0_73EB0(D_801075D0_274CB0_DizzyDancing[gPlayers[p].character] | D_801075E8_274CC8_DizzyDancing[D_8010785D_274F3D_DizzyDancing[p][0]]);
                }
            }
        } else if (!(D_80107852_274F32_DizzyDancing & 0x20) && obj->work[0] == 0) {
            for (i = 0; i < 4; i++) {
                q = &ACTOR[i];
                if (q->state != 8) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                D_80107852_274F32_DizzyDancing |= 0x20;
            }
        }
        break;
    case 9:
        break;
    }
    if (a->state < 7) {
        func_80105AF4_2731D4_DizzyDancing(obj, obj->work[0]);
    }
    func_80007790_8390(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_80105DF0_2734D0_DizzyDancing);
#endif

#ifndef NON_MATCHING
__asm__(".section .rodata");
const u32 D_80107814_274EF4_DizzyDancing[7] = { 0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x00000000 };
__asm__(".section .text");
#endif
/* NON_MATCHING: masked 2: the table pointer load is scheduled after the rodata address. */
#ifdef NON_MATCHING
void func_80106650_273D30_DizzyDancing(omObjData* obj) {
    DDActor* a = &D_80107870_274F50_DizzyDancing[obj->work[0]];
    s32 table[6] = { 5, 6, 7, 8, 9, 10 };
    s32* pt = table;
    s32 mask;
    MgWork* w;
    s32 ch;
    s32 dir;
    s32 file;
    s16 i;

    ch = gPlayers[obj->work[0]].character;
    dir = D_800CD438_CE038[ch].unk_04;
    file = D_800CD438_CE038[ch].unk_08;
    func_8000C460_D060();
    mask = 0x460000;
    func_8000C6FC_D2FC(obj, dir, file, obj->work[0], 0x6B9, 0x2A9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(MODEL(obj->model[1])->mtx, 0.0f, 15.0f, 0.0f);
    w = obj->unk_50;
    w->unk_EC = NULL;
    func_800298A4_2A4A4(obj->model[1], 0x60, 0x20);
    func_800298A4_2A4A4(obj->model[1], 0x180, 0x80);
    obj->model[6] = LoadFormFile(9, 0x2BD);
    obj->model[7] = LoadFormFile(0xC, 0x2BD);
    obj->model[8] = LoadFormFile(0xB, 0x2BD);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, pt[ch] | mask, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1D);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1F, dir | 0x30, 0, 0);
    if (rand8() & 1) {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4E, 1, 0x8C);
        func_80019E84_1AA84(obj, 0xE, dir | 0x55, 1, 0x8C);
        D_8010785D_274F3D_DizzyDancing[obj->work[0]][0] = 0;
        D_8010785D_274F3D_DizzyDancing[obj->work[0]][1] = 2;
    } else {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x8C);
        func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x8C);
        D_8010785D_274F3D_DizzyDancing[obj->work[0]][0] = 1;
        D_8010785D_274F3D_DizzyDancing[obj->work[0]][1] = 3;
    }
    func_80019F0C_1AB0C(obj, 0x26, dir | 8, 1, 0);
    func_80019F0C_1AB0C(obj, 0x27, dir | 0x16, 1, 0);
    if (gPlayers[obj->work[0]].flags & 1) {
        a->unk_2C = 1;
    }
    obj->trans.x = D_8010760C_274CEC_DizzyDancing[obj->work[1]][0];
    obj->trans.y = D_8010760C_274CEC_DizzyDancing[obj->work[1]][1];
    obj->trans.z = D_8010760C_274CEC_DizzyDancing[obj->work[1]][2];
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80102F0C_2705EC_DizzyDancing(obj, w, 0.0f, 0.0f, 0.0f);
    for (i = 0; i < D_80107858_274F38_DizzyDancing; i++) {
        func_8000C024_CC24(obj, i, 2);
    }
    func_80019B9C_1A79C(obj, 0);
    func_8010281C_26FEFC_DizzyDancing(obj->work[0]);
    D_800F8FD0_F9BD0 = 1;
    w->unk_40 = 0.0f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[6], 1);
    func_80029EDC_2AADC(obj->model[7], 1);
    func_80029EDC_2AADC(obj->model[8], 1);
    func_8000E0C0_ECC0(obj->unk_50, 3, func_80105A74_273154_DizzyDancing);
    func_8000E0C0_ECC0(obj->unk_50, 2, func_80105AD0_2731B0_DizzyDancing);
    func_8000E0C0_ECC0(obj->unk_50, 7, func_80105A4C_27312C_DizzyDancing);
    obj->func_ptr = func_80105DF0_2734D0_DizzyDancing;
    a->unk_30 = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_80106650_273D30_DizzyDancing);
#endif

/* NON_MATCHING: masked 2: branch-likely in the switch tree. */
#ifdef NON_MATCHING
void func_80106BEC_2742CC_DizzyDancing(void) {
    u64 used;
    omObjData* o;
    DDActor* p;
    s16 i;
    s32 v;

    func_800B0EF0_B1AF0(D_801086F0_275DD0_DizzyDancing, 0, sizeof(D_801086F0_275DD0_DizzyDancing));
    used = 0;
    for (i = 0; i < 4; i++) {
        p = &ACTOR[i];
        o = omAddObj(100, 9, 60, -1, func_80106650_273D30_DizzyDancing);
        switch (i) {
        case 0:
            v = 0;
            break;
        case 1:
            v = 1;
            break;
        case 2:
            v = 2;
            break;
        case 3:
            v = 3;
            break;
        default:
            v = 0;
            break;
        }
        o->work[0] = v;
        o->work[1] = func_801028A0_26FF80_DizzyDancing(4, &used);
        p->obj = o;
        D_800FFFD8_100BD8[D_800FC87A_FD47A] = o;
        D_800FC87A_FD47A += 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DizzyDancing/26FEE0", func_80106BEC_2742CC_DizzyDancing);
#endif

void func_80106D44_274424_DizzyDancing(omObjData* obj) {
    if (D_8010763C_274D1C_DizzyDancing != 0) {
        if (--D_8010763C_274D1C_DizzyDancing == 0) {
            func_8006D518_6E118();
        }
    }
    if (D_80107856_274F36_DizzyDancing != 0) {
        D_80107856_274F36_DizzyDancing -= 1;
    }
}

void func_80106DA4_274484_DizzyDancing(omObjData* obj) {
    if (D_80107854_274F34_DizzyDancing != 0) {
        D_80107854_274F34_DizzyDancing -= 1;
    }
    func_8006D4D0_6E0D0((D_80107854_274F34_DizzyDancing + 29) / 30);
    if (D_80107850_274F30_DizzyDancing == 3) {
        D_80107856_274F36_DizzyDancing = 60;
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
        obj->func_ptr = func_80106D44_274424_DizzyDancing;
        D_80107854_274F34_DizzyDancing = 0;
    }
}

void func_80106E58_274538_DizzyDancing(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    obj->func_ptr = func_80106DA4_274484_DizzyDancing;
}

void func_80106E98_274578_DizzyDancing(omObjData* obj) {
    switch (D_80107850_274F30_DizzyDancing) {
    case 1:
        if (D_80107854_274F34_DizzyDancing == 0) {
            func_800691FC_69DFC(0);
            D_80107854_274F34_DizzyDancing++;
        }
        break;
    case 2:
        obj->func_ptr = func_80106E58_274538_DizzyDancing;
        break;
    }
}

void func_80106F0C_2745EC_DizzyDancing(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80106F30_274610_DizzyDancing(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_80106F0C_2745EC_DizzyDancing;
    }
}

void func_80106F68_274648_DizzyDancing(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_80106F30_274610_DizzyDancing;
    }
}

void func_80106FC0_2746A0_DizzyDancing(omObjData* obj) {
    if (D_8010763E_274D1E_DizzyDancing == 0) {
        PlayMusic(0x2B);
        D_8010763E_274D1E_DizzyDancing = 1;
    }
    switch (D_80107850_274F30_DizzyDancing) {
    case 0:
        if (D_80107852_274F32_DizzyDancing & 4) {
            D_80107850_274F30_DizzyDancing = 1;
        }
        break;
    case 1:
        if (func_80069538_6A138() == 0) {
            D_80107850_274F30_DizzyDancing = 2;
            D_80107854_274F34_DizzyDancing = 901;
        }
        break;
    case 2:
        if (D_80107852_274F32_DizzyDancing & 8) {
            D_80107850_274F30_DizzyDancing = 3;
        } else if (D_80107854_274F34_DizzyDancing == 0) {
            D_80107852_274F32_DizzyDancing |= 0x10;
            D_80107850_274F30_DizzyDancing = 3;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 0 && ((D_80107852_274F32_DizzyDancing & 0x20) || --D_80107640_274D20_DizzyDancing == 0)) {
            D_80107850_274F30_DizzyDancing = 4;
            if (_CheckFlag(0xC) == 0) {
                if (D_80107852_274F32_DizzyDancing & 0x10) {
                    func_800691FC_69DFC(0x13);
                    PlayMusic(0x57);
                    D_80107854_274F34_DizzyDancing = 135;
                } else {
                    func_800691FC_69DFC(6, gPlayers[D_8010785A_274F3A_DizzyDancing].character);
                    PlayMusic(0x51);
                    D_80107854_274F34_DizzyDancing = 120;
                }
            }
            if (!(D_80107852_274F32_DizzyDancing & 0x10)) {
                gPlayers[D_8010785A_274F3A_DizzyDancing].coins_mg_bonus = 10;
            }
        }
        break;
    case 4:
        if (_CheckFlag(0xC) != 0) {
            if (D_80107856_274F36_DizzyDancing == 0) {
                D_80107850_274F30_DizzyDancing = 5;
            }
        } else if (--D_80107854_274F34_DizzyDancing == 0) {
            D_80107850_274F30_DizzyDancing = 5;
        }
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106F30_274610_DizzyDancing;
        break;
    }
    func_80102F9C_27067C_DizzyDancing();
}

void func_80107230_274910_DizzyDancing(omObjData* obj) {
    func_80107520_274C00_DizzyDancing();
    func_801075A4_274C84_DizzyDancing();
    D_80107852_274F32_DizzyDancing = 0;
    D_80107850_274F30_DizzyDancing = 0;
    D_8010785A_274F3A_DizzyDancing = 0;
    D_80107858_274F38_DizzyDancing = 0;
    D_80107854_274F34_DizzyDancing = 0;
    D_80107856_274F36_DizzyDancing = 0;
    func_80103760_270E40_DizzyDancing();
    func_801034C0_270BA0_DizzyDancing();
    func_801040D4_2717B4_DizzyDancing();
    func_80104284_271964_DizzyDancing();
    func_80104BCC_2722AC_DizzyDancing();
    func_80106BEC_2742CC_DizzyDancing();
    omAddObj(900, 0, 0, -1, func_80106E98_274578_DizzyDancing);
    InitFadeIn(0, 16);
    obj->func_ptr = func_80106FC0_2746A0_DizzyDancing;
}

void func_801072F0_2749D0_DizzyDancing(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(30);
    func_80020D20_21920(20);
    omInitObjMan(30, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0, 0, 0);
    func_80026DAC_279AC(1, 64, 64, 96);
    func_80026E00_27A00(1, 0.0f, 20.0f, 100.0f);
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
    omAddObj(1000, 0, 0, -1, func_80107230_274910_DizzyDancing);
    omAddObj(1000, 0, 0, -1, func_80106F68_274648_DizzyDancing);
    func_8007273C_7333C((u8*)"\x82\x60\x82\x61\x82\x62", 0);
    func_8007273C_7333C((u8*)"\x82\x60\x82\x61\x82\x62", 1);
}
