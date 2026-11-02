#include "ovl_15.h"

void func_80102800_170190_LightsOut(void) {
    func_8010B1C8_178B58_LightsOut();
}

void func_8010281C_1701AC_LightsOut(Gfx** gfxp) {
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
    gDPLoadTLUT_pal16(gfx++, 0, D_8010CCC4_17A654_LightsOut->unk0C);
    for (y = 0; y < 112; y += 8) {
        gDPLoadTextureTile_4b(gfx++, D_8010CCC4_17A654_LightsOut->unk08, G_IM_FMT_CI, 288, 112, 0, y, 287,
                              y + 7, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 288 << 2, 8 << 2);
        gSPTextureRectangle(gfx++, 17 << 2, (y + 120) << 2, 305 << 2, (y + 128) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102B50_1704E0_LightsOut(void) {
}

void func_80102B58_1704E8_LightsOut(omObjData* obj) {
    s32 mdl;

    D_8010CD26_17A6B6_LightsOut = func_8001A2F8_1AEF8(0x250003);
    D_8010CCC4_17A654_LightsOut = SprAnimGet(D_8010CD26_17A6B6_LightsOut);
    obj->func_ptr = func_80102B50_1704E0_LightsOut;
    mdl = func_8002838C_28F8C(0, func_8010281C_1701AC_LightsOut, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_8010EC0C_17C59C_LightsOut = mdl;
}

void func_80102BDC_17056C_LightsOut(void) {
    D_8010D9C0_17B350_LightsOut = omAddObj(400, 0, 0, -1, func_80102B58_1704E8_LightsOut);
}

void func_80102C18_1705A8_LightsOut(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 2120.0f;
        D_80102770_103370[i].x = 333.55f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 57.5f;
        D_801013B0_101FB0[i].z = -105.0f;
    }
}

void func_80102CC4_170654_LightsOut(void) {
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
}

void func_80102CF0_170680_LightsOut(omObjData* obj) {
    GroundWork* gw;

    D_8010CD18_17A6A8_LightsOut[0] = func_8001A2F8_1AEF8(0x250002);
    D_8010D310_17ACA0_LightsOut = SprCreate(1, 0);
    SprAttrReset(D_8010D310_17ACA0_LightsOut, 0, -1);
    SprScaleSet(D_8010D310_17ACA0_LightsOut, 0, 1.0f, 1.0f);
    SprAnimSet(D_8010D310_17ACA0_LightsOut, 0, D_8010CD18_17A6A8_LightsOut[0], 0);
    SprBankSet(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprAttrSet(D_8010D310_17ACA0_LightsOut, 0, 0x5000);
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
    func_8008225C_82E5C(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprPrioSet(D_8010D310_17ACA0_LightsOut, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_80102CC4_170654_LightsOut;
}

void func_80102EB8_170848_LightsOut(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_8010D30C_17AC9C_LightsOut = omAddObj(10, 2, 0, -1, func_80102CF0_170680_LightsOut);
}

void func_80102F00_170890_LightsOut(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

/* The hammer's reach: is (x, y, z) inside the blast cylinder of radius `reach`, 30 either way? */
#ifdef NON_MATCHING
/* register allocation (masked 0): the abs temporary */
s32 func_80102F9C_17092C_LightsOut(f32 x, f32 y, f32 z, f32 reach) {
    f32 out[3];
    f32 d;
    f32 h;

    func_80102F00_170890_LightsOut(D_8010D16C_17AAFC_LightsOut, x, y, z, out);
    D_8010D140_17AAD0_LightsOut = out[0];
    D_8010D144_17AAD4_LightsOut = out[1];
    D_8010D148_17AAD8_LightsOut = out[2];
    if (reach * reach + 3600.0f < (d = out[0] * out[0] + out[2] * out[2])) {
        return 0;
    }
    if (reach + 30.0f < LO_ABS(out[1])) {
        return 0;
    }
    h = LO_ABS(out[1]) - 30;
    if (h <= 0.0f) {
        return 1;
    }
    h = func_800B1830_B2430(h * h + reach * reach);
    if (h * h + 3600.0f < d) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80102F9C_17092C_LightsOut);
#endif

void func_80103114_170AA4_LightsOut(void) {
    LOSlot* host;
    LOSlot* p;
    omObjData* t;
    omObjData* obj;
    MgWork* work;
    Vec pos;
    Vec rot;
    s32 i;

    if (D_8010D1B4_17AB44_LightsOut != 0) {
        for (i = 0; i < 4; i++) {
            host = &D_8010CD90_17A720_LightsOut[i];
            if (host->unk_74 == 1) {
                break;
            }
        }
        if (i < 4) {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                t = p->obj;
                if (t != NULL && p->unk_74 == 0) {
                    obj = t;
                    work = obj->unk_50;
                    if (obj->work[2] == 0 && func_80102F9C_17092C_LightsOut(obj->trans.x, obj->trans.y + host->unk_30, obj->trans.z, host->unk_30) != 0) {
                        if (host->unk_76 == 2 && work->unk_38 == 1000.0f) {
                            obj->work[2] = 1;
                            pos.x = obj->trans.x;
                            pos.y = obj->trans.y + host->unk_30;
                            pos.z = obj->trans.z;
                            rot.x = -90.0f;
                            rot.y = rot.z = 0.0f;
                            PlaySound(0x1CC);
                            D_8010CCB4_17A644_LightsOut = 1;
                        } else if (host->unk_76 == 1 && work->unk_38 == 1000.0f) {
                            obj->work[2] = 2;
                            pos.x = obj->trans.x;
                            pos.y = obj->trans.y + host->unk_30;
                            pos.z = obj->trans.z;
                            rot.x = rot.z = 0.0f;
                            rot.y = obj->rot.y;
                            PlaySound(0x1CC);
                            D_8010CCB4_17A644_LightsOut = 1;
                        } else {
                            return;
                        }
                        func_800191D4_19DD4(obj, 5, pos.x, pos.y, pos.z, rot.x, rot.y);
                    }
                }
            }
        }
    }
}

/* The lightning frame: the current darkness texture over the whole screen, drawn from a hook. */
void func_8010335C_170CEC_LightsOut(Gfx** gfxp) {
    Gfx* gfx;
    s32 y;
    u16 alpha;

    if (D_8010CD04_17A694_LightsOut != 0) {
        alpha = 255;
        if (D_8010CC88_17A618_LightsOut < 256) {
            alpha = D_8010CC88_17A618_LightsOut;
        }
        gfx = *gfxp;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                        G_CULL_BOTH | G_FOG | G_LOD);
        gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        for (y = 0; y < 240; y += 10) {
            gDPLoadTextureTile_4b(gfx++, D_8010CCC8_17A658_LightsOut[D_8010CC80_17A610_LightsOut], G_IM_FMT_I, 320, 240, 0, y, 319,
                                  y + 9, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 320 << 2, 10 << 2);
            gSPTextureRectangle(gfx++, 0 << 2, y << 2, 320 << 2, (y + 10) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        }
        *gfxp = gfx;
    }
}

void func_80103620_170FB0_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x8000;
}

void func_80103648_170FD8_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x4000;
}

void func_80103670_171000_LightsOut(void) {
}

f32 func_80103678_171008_LightsOut(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
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
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

void func_801037C8_171158_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    f32 angle = work->unk_3C;
    f32 mag;

    if (D_8010CD84_17A714_LightsOut != 3) {
        switch (gPlayers[work->unk_59].cpu_difficulty) {
            case 0:
                mag = (rand8() & 3) * 5 + 50;
                break;
            case 1:
                mag = (u8)(rand8() % 5) * 5 + 45;
                break;
            default:
                mag = (u8)(rand8() % 6) * 5 + 40;
                break;
        }
    } else {
        mag = 70.0f;
    }
    ContStkX[work->unk_57] = mag * HuMathSin(angle);
    ContStkY[work->unk_57] = -mag * func_800B7890_B8490(angle);
}

#ifdef NON_MATCHING
/* register/schedule (masked 3): retail loads 180.0f between the compare and its branch */
void func_80103968_1712F8_LightsOut(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
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
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_80103678_171008_LightsOut(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_80103678_171008_LightsOut(delta.y / horizontal) * 57.29577951308232;
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
    horizontal = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80103968_1712F8_LightsOut);
#endif

void func_80103CA8_171638_LightsOut(omObjData* obj, s16 motion, char* name) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    LOMtxSet* set;
    Matrix4f* dst;
    Matrix4f* src;
    s32 i;
    s32 j;

    func_80029B80_2A780(obj->model[0], obj->motion[motion]);
    set = func_800232FC_23EFC(obj->model[0], 2, name);
    for (i = 0; i < 2; i++) {
        if (p->mtxCount[i] == 0) {
            break;
        }
    }
    if (i < 2) {
        p->mtx[i] = dst = func_80027154_27D54((p->mtxCount[i] = set->count) * 64, 0x7918);
        src = set->mtx;
        for (j = 0; j < p->mtxCount[i]; j++) {
            func_80030CD4_318D4(*dst++, *src++);
        }
    }
    func_80023D74_24974(set);
}

f32 func_80103DFC_17178C_LightsOut(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }

    return a;
}

/* A CPU hammer player: aim at the nearest live player, swing when one is close or the timer runs out. */
void func_80103E74_171804_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 160.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 150) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 5) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 20;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 160.0f) {
                if ((u8)(rand8() % 6) < 5) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 20;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104228_171BB8_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 160.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 150) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 5) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 30;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 160.0f) {
                if ((u8)(rand8() % 6) < 5) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 30;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_801045DC_171F6C_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 140.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 120) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 6) < 3) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 45;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 140.0f) {
                if ((u8)(rand8() % 5) < 3) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 45;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104990_172320_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 140.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 105) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 2) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 53;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 120.0f) {
                if ((u8)(rand8() % 5) < 2) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 53;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104D48_1726D8_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;

    LO_PAD_CLEAR(obj);
    if (slot->unk_8A <= 0) {
        switch (gPlayers[work->unk_59].cpu_difficulty) {
            case 0:
                func_80104990_172320_LightsOut(slot);
                break;
            case 1:
                func_801045DC_171F6C_LightsOut(slot);
                break;
            case 2:
                func_80104228_171BB8_LightsOut(slot);
                break;
            default:
                func_80103E74_171804_LightsOut(slot);
                break;
        }
        func_801037C8_171158_LightsOut(slot->obj);
    }
    slot->unk_8A--;
}

/* Loser and winner idles of the hammer player. */
void func_80104EEC_17287C_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    f32 x;
    f32 z;
    f32 a;

    if (D_8010CD84_17A714_LightsOut == 4 && p->unk_8C == 0.0f) {
        func_80019B9C_1A79C(obj, 0xE);
        p->unk_8C = 1.0f;
    }
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    func_80007790_8390(obj);
    x = obj->trans.x;
    if (x * x + (z = obj->trans.z, z * z) > 211600.0) {
        a = func_80103DFC_17178C_LightsOut(x, z);
        obj->trans.x = HuMathSin(a) * 460.0;
        obj->trans.z = func_800B7890_B8490(a) * 460.0;
    }
}

void func_801050E8_172A78_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    f32 x;
    f32 z;
    f32 a;

    if (D_8010CD84_17A714_LightsOut == 4 && p->unk_8C == 0.0f) {
        func_80019B9C_1A79C(obj, 0xD);
        func_800732B0_73EB0(D_8010C250_179BE0_LightsOut[gPlayers[obj->work[0]].character] | D_8010C268_179BF8_LightsOut[D_8010CCB9_17A649_LightsOut[obj->work[0]][0]]);
        p->unk_8C = 1.0f;
    }
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    func_80007790_8390(obj);
    x = obj->trans.x;
    if (x * x + (z = obj->trans.z, z * z) > 211600.0) {
        a = func_80103DFC_17178C_LightsOut(x, z);
        obj->trans.x = HuMathSin(a) * 460.0;
        obj->trans.z = func_800B7890_B8490(a) * 460.0;
    }
}

/* The intro: two practice swings, the music, then the state moves on. */
void func_80105340_172CD0_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    if (p->unk_8A == 0 && obj->work[1] == 0) {
        func_80103620_170FB0_LightsOut(obj);
        p->unk_8A = 1;
    } else if (p->unk_8A == 1 && obj->work[1] == 0) {
        func_80103620_170FB0_LightsOut(obj);
        p->unk_8A = 2;
        PlayMusic(0x1E);
    } else if (p->unk_8A == 2 && obj->work[1] == 0) {
        func_80103648_170FD8_LightsOut(obj);
        p->unk_8A = 3;
    } else if (p->unk_8A == 3 && obj->work[1] == 0) {
        D_8010CD84_17A714_LightsOut = 1;
        p->unk_8A = 0;
    }
}

void func_80105438_172DC8_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    omObjData* wave = D_8010CD90_17A720_LightsOut[6].obj;
    LOSlot* q;
    s16 i;
    s16 count;
    f32 x;

    if (D_8010C270_179C00_LightsOut == 0) {
        func_8000D900_E500(obj, wave);
        D_8010C270_179C00_LightsOut = 1;
    }
    switch (D_8010CD84_17A714_LightsOut) {
        case 0:
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            func_80105340_172CD0_LightsOut(obj);
            break;
        case 1:
        case 5:
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            break;
        case 2:
            if (obj->work[3] == 0) {
                work->unk_3C = obj->rot.y;
                obj->rot.y = 0.0f;
                obj->work[3] = 1;
            }
            if (p->unk_80 == 1) {
                func_80104D48_1726D8_LightsOut(p);
            }
            break;
        case 3:
            func_8002C570_2D170(obj->model[0]);
            func_800298A4_2A4A4(wave->model[0], 0x4000, 0);
            func_80019B9C_1A79C(obj, 0);
            work->unk_50 &= 0xFEAF;
            obj->work[1] = 0;
            p->unk_8C = 0.0f;
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            work->unk_3C = 0.0f;
            count = 0;
            for (i = 0; i < 4; i++) {
                q = &D_8010CD90_17A720_LightsOut[i];
                if (q->obj->work[2] != 0 && q->unk_74 == 0) {
                    count++;
                }
            }
            if (_CheckFlag(0xC) == 0) {
                if (count >= 3) {
                    obj->func_ptr = func_801050E8_172A78_LightsOut;
                } else {
                    obj->func_ptr = func_80104EEC_17287C_LightsOut;
                }
            }
            break;
    }
    p->unk_78++;
    if (!(func_80019000_19C00(obj) & 0xC0000)) {
        p->unk_76 = 0;
        p->unk_78 = 0;
        obj->work[1] = 0;
    }
    if (obj->work[1] != 0 && p->unk_76 == 2 && D_8010CC98_17A628_LightsOut == 1) {
        if (D_8010CCB4_17A644_LightsOut == 0) {
            PlaySound(0x1CB);
        }
        x = HuMathSin(work->unk_3C) * 70.0f + obj->trans.x;
        func_800191D4_19DD4(obj, 5, x, 0.0f, func_800B7890_B8490(work->unk_3C) * 70.0f + obj->trans.z, 0.0f, 0.0f);
    }
    if (ContStkX[gPlayers[obj->work[0]].port] >= 50) {
        ContStkX[gPlayers[obj->work[0]].port] = 50;
    }
    if (ContStkY[gPlayers[obj->work[0]].port] >= 50) {
        ContStkY[gPlayers[obj->work[0]].port] = 50;
    }
    if (ContStkX[gPlayers[obj->work[0]].port] < -49) {
        ContStkX[gPlayers[obj->work[0]].port] = -50;
    }
    if (ContStkY[gPlayers[obj->work[0]].port] < -49) {
        ContStkY[gPlayers[obj->work[0]].port] = -50;
    }
    func_80007790_8390(obj);
    LO_KEEP_IN(obj);
}

s32 func_80105AF8_173488_LightsOut(void) {
    return 1;
}

s32 func_80105B00_173490_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    p->unk_76 = 2;
    p->unk_78 = 0;
    obj->work[1] = 1;
    work->unk_40 = D_800BF7D0_C03D0;
    func_80079798_7A398(0x1CD, obj->work[0]);
    D_8010CCB4_17A644_LightsOut = 0;
    return 0;
}

s32 func_80105B78_173508_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    p->unk_76 = 1;
    p->unk_78 = 0;
    obj->work[1] = 1;
    work->unk_40 = D_800BF7D0_C03D0;
    func_80079798_7A398(0x1CD, obj->work[0]);
    D_8010CCB4_17A644_LightsOut = 0;
    return 0;
}

s32 func_80105BF0_173580_LightsOut(omObjData* obj) {
    func_8002C570_2D170(obj->model[0]);
    return 1;
}

__asm__(".section .rodata");
const char D_8010CAF8_17A488_LightsOut[16] = "item_hook";

void func_80105C14_1735A4_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    s32 dir;
    s32 file;
    MgWork* work;
    u16 c = gPlayers[obj->work[0]].character;
    u8 r;

    if (gPlayers[obj->work[0]].flags & 1) {
        p->unk_80 = 1;
    } else {
        p->unk_80 = 0;
    }
    dir = D_800CD438_CE038[c].unk_04;
    file = D_800CD438_CE038[c].unk_08;
    func_8000C460_D060();
    func_8000C6FC_D2FC(obj, dir, file, obj->work[0], 0x699, 0x689);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    work = obj->unk_50;
    work->unk_EC = NULL;
    func_800298A4_2A4A4(obj->model[1], 0x60, 0x20);
    func_800298A4_2A4A4(obj->model[1], 0x180, 0);
    obj->model[3] = LoadFormFile(7, 0x2BD);
    obj->model[4] = LoadFormFile(8, 0x2BD);
    obj->model[6] = LoadFormFile(9, 0x2BD);
    obj->model[5] = LoadFormFile(10, 0x2BD);
    obj->model[7] = LoadFormFile(12, 0x2BD);
    obj->model[8] = LoadFormFile(11, 0x2BD);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 0, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    if ((rand8() & 3) < 3) {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4E, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 0;
    } else {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 1;
    }
    if ((rand8() & 3) < 3) {
        func_80019E84_1AA84(obj, 0xE, dir | 0x55, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][1] = 2;
    } else {
        func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][1] = 3;
    }
    func_80019E84_1AA84(obj, 0x23, dir | 0x1A, 0, 0);
    func_80019E84_1AA84(obj, 0x24, dir | 0x1B, 0, 0);
    func_80019E84_1AA84(obj, 0x16, dir | 0x19, 1, 0);
    r = rand8() & 3;
    D_8010CD00_17A690_LightsOut[r] = 1;
    obj->trans.x = D_8010C230_179BC0_LightsOut[r].x;
    obj->trans.y = D_8010C230_179BC0_LightsOut[r].y;
    obj->trans.z = D_8010C230_179BC0_LightsOut[r].z;
    obj->rot.y = D_8010C230_179BC0_LightsOut[r].rotY;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8000C024_CC24(obj, 0, 2);
    func_80103CA8_171638_LightsOut(obj, 0x24, (char*)D_8010CAF8_17A488_LightsOut);
    func_80103CA8_171638_LightsOut(obj, 0x23, (char*)D_8010CAF8_17A488_LightsOut);
    func_80019B9C_1A79C(obj, 0);
    D_800F8FD0_F9BD0 = 1;
    obj->work[1] = 0;
    p->unk_74 = 1;
    p->unk_76 = 0;
    p->unk_78 = 0;
    p->unk_30 = 60.0f;
    D_8010CC9A_17A62A_LightsOut = 0;
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    func_80029EDC_2AADC(obj->model[4], 1);
    func_80029EDC_2AADC(obj->model[6], 1);
    func_80029EDC_2AADC(obj->model[5], 2);
    func_80029EDC_2AADC(obj->model[7], 1);
    func_80029EDC_2AADC(obj->model[8], 1);
    obj->func_ptr = func_80105438_172DC8_LightsOut;
    func_8000E0C0_ECC0(work, 0x13, func_80105AF8_173488_LightsOut);
    func_8000E0C0_ECC0(work, 0xA, func_80105B00_173490_LightsOut);
    func_8000E0C0_ECC0(work, 0xB, func_80105B78_173508_LightsOut);
    func_8000E0C0_ECC0(work, 0xC, func_80105BF0_173580_LightsOut);
    func_8000E0C0_ECC0(work, 0xD, func_80105BF0_173580_LightsOut);
}

/* The hammer player is the one of group 0. */
void func_801062A8_173C38_LightsOut(void) {
    LOSlot* p;
    omObjData* obj;
    s16 i;
    s16 player;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
        case 0:
            player = 0;
            break;
        case 1:
            player = 1;
            break;
        case 2:
            player = 2;
            break;
        case 3:
            player = 3;
            break;
        default:
            player = 0;
            break;
    }
    p = &D_8010CD90_17A720_LightsOut[i];
    obj = omAddObj(100, 9, 60, -1, func_80105C14_1735A4_LightsOut);
    p->unk_82 = player;
    D_8010CD86_17A716_LightsOut = obj->work[0] = player;
    p->obj = obj;
    D_800FFFD8_100BD8[D_800FC87A_FD47A] = obj;
    D_800FC87A_FD47A++;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801063E8_173D78_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80106BCC_17455C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801073B0_174D40_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80107BB4_175544_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801083A4_175D34_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80108530_175EC0_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010875C_1760EC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801094B8_176E48_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801099F0_177380_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109B28_1774B8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109C30_1775C0_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109F58_1778E8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A090_177A20_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A0CC_177A5C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A4C0_177E50_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A5D0_177F60_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A680_178010_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A6C4_178054_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A980_178310_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AAAC_17843C_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ACD0_178660_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AD1C_1786AC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ADA4_178734_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010ADC8_178758_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AE00_178790_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010AE58_1787E8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B04C_1789DC_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B0CC_178A5C_LightsOut);

__asm__(".section .rodata");
const char D_8010CB90_17A520_LightsOut[] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B1C8_178B58_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B3B8_178D48_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B648_178FD8_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010BDE8_179778_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010BEA4_179834_LightsOut);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010C070_179A00_LightsOut);
