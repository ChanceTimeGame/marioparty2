#include "common.h"
#include "ovl_0A.h"

void func_80102800_121740_RakinEmIn(void) {
    func_801069D8_125918_RakinEmIn();
}

void func_8010281C_12175C_RakinEmIn(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

/* Picks one of the first n bits still clear in *used at random, sets it and returns it. */
u8 func_801028A0_1217E0_RakinEmIn(u8 n, u64* used) {
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

/* atan(x) by a continued fraction. */
/* NON_MATCHING: retail keeps the quotient in $f2 and converts it in the goto's delay slot (f64
   register allocation, masked 8; MP1's func_800FDBF4_name_2A and ovl_23's twin are the same). */
#ifdef NON_MATCHING
f32 func_801029F0_121930_RakinEmIn(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
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
            frac = x / (sum + 1.0f);
            base = 1.5707963267948966;
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801029F0_121930_RakinEmIn);
#endif

/* From `from` to `to`: out = { distance, pitch + 90 (degrees), yaw (degrees) }. */
/* NON_MATCHING: the 180.0f load is scheduled before the near-zero test, not into its delay
   slots (masked 25; ovl_23's func_80106EB0 has the same residue). */
#ifdef NON_MATCHING
void func_80102B40_121A80_RakinEmIn(Vec* from, Vec* to, Vec* out) {
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
            yaw = func_801029F0_121930_RakinEmIn(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f || delta.y != 0.0f) {
            pitch = func_801029F0_121930_RakinEmIn(delta.y / horizontal) * 57.29577951308232;
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80102B40_121A80_RakinEmIn);
#endif

/* angle + add, wrapped to [0, 360). */
f32 func_80102EB4_121DF4_RakinEmIn(f32 angle, f32 add) {
    angle += add;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

void func_80102F0C_121E4C_RakinEmIn(void) {
    s32 i;

    if (D_80106F74_125EB4_RakinEmIn == 0) {
        D_80106F74_125EB4_RakinEmIn = 1;
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 24.287f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = 2560.929f;
            D_80102770_103370[i].x = 324.783f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 83.450005f;
            D_801013B0_101FB0[i].z = 61.75f;
        }
    }
}

void func_8010302C_121F6C_RakinEmIn(RIObj* o, s16 member, u16 anim, u16 x, s32 y) {
    D_801071E0_126120_RakinEmIn[(u16)(member + 10)] = anim;
    SprAnimSet(o->spr, member, anim, 0);
    SprAttrSet(o->spr, member, 0x1000);
    SprPosSet(o->spr, member, x, y);
    SprPrioSet(o->spr, member, 0xFFF4);
}

/* The scores: count the shown number one step towards the score (left-aligned digits), then
   pop it. */
void func_801030E4_122024_RakinEmIn(omObjData* obj) {
    RIObj* hud;
    RIScore* sc;
    f32 s;
    s16 i;
    s16 m;
    s16 lead;
    u16 n;
    u16 d;

    hud = &D_80107AC0_126A00_RakinEmIn;
    for (i = 0; i < 4; i++) {
        sc = &D_801071B0_1260F0_RakinEmIn[i];
        switch (sc->state) {
        case 0:
            if (sc->shown != sc->score) {
                if (sc->shown < sc->score) {
                    n = sc->shown + 1;
                } else {
                    n = sc->shown - 1;
                }
                lead = 0;
                m = i * 3 + 12;
                d = n / 100;
                if (d != 0) {
                    SprBankSet(hud->spr, m++, d);
                    lead = 1;
                } else {
                    SprAttrSet(hud->spr, m + 2, 0x8000);
                }
                if ((d = (u16)(n % 100) / 10) != 0) {
                    goto show;
                }
                if (lead != 0) {
                show:
                    SprBankSet(hud->spr, m++, d);
                } else {
                    SprAttrSet(hud->spr, m + 1, 0x8000);
                }
                d = n % 10;
                SprBankSet(hud->spr, m, d);
                SprAttrReset(hud->spr, m, 0x8000);
                sc->shown = n;
                sc->state = 1;
            }
            break;
        case 1:
            m = i + 4;
            sc->angle += 40.0f;
            if (sc->angle > 180.0f) {
                sc->angle = 0.0f;
                sc->state = 0;
            }
            s = func_800B80D0_B8CD0(sc->angle) + 1.0;
            SprScaleSet(hud->spr, m, s, s);
            break;
        }
    }
}

/* The HUD: four faces, four basket icons, four "x" signs and three digits per player. */
void func_801033B0_1222F0_RakinEmIn(omObjData* obj) {
    s16 i;
    s16 j;
    u16 anim;
    RIObj* hud;

    hud = &D_80107AC0_126A00_RakinEmIn;
    func_800B0EF0_B1AF0(D_801071B0_1260F0_RakinEmIn, 0, 0x30);
    D_80107AC4_126A04_RakinEmIn = SprCreate(24, 0);
    for (i = 0; i < 4; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i,
                                       func_8001A2F8_1AEF8(D_80106F5C_125E9C_RakinEmIn[gPlayers[i].character]),
                                       D_80106F1C_125E5C_RakinEmIn[i][0], D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x17000F);
    for (; i < 8; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[i][0],
                                       D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x170010);
    for (; i < 12; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[i][0],
                                       D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x43);
    for (j = i; j < 16; j++) {
        func_8010302C_121F6C_RakinEmIn(hud, i++, anim, D_80106F1C_125E5C_RakinEmIn[j][0],
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[j][0] + 12,
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        SprAttrSet(hud->spr, i++, 0x8000);
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[j][0] + 24,
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        SprAttrSet(hud->spr, i++, 0x8000);
    }
    obj->func_ptr = func_801030E4_122024_RakinEmIn;
}

void func_801036B8_1225F8_RakinEmIn(void) {
    D_80107AC0_126A00_RakinEmIn.obj = omAddObj(600, 0, 0, -1, func_801033B0_1222F0_RakinEmIn);
}

/* The rakes' angle window: the yaw of (62.5, 0, 0) seen from the centre (then fixed at 90). */
void func_801036F4_122634_RakinEmIn(void) {
    Vec a;
    Vec b;
    Vec out;
    f32 zero;

    D_801070A8_125FE8_RakinEmIn = 0.0f;
    zero = 0.0f;
    D_801070A8_125FE8_RakinEmIn = func_800B1820_B2420(zero);
    a.x = zero;
    a.y = zero;
    a.z = zero;
    b.x = 62.5f;
    b.y = zero;
    b.z = D_801070A8_125FE8_RakinEmIn;
    func_80102B40_121A80_RakinEmIn(&a, &b, &out);
    D_801070AC_125FEC_RakinEmIn = out.z;
    D_801070A8_125FE8_RakinEmIn = zero;
    D_801070AC_125FEC_RakinEmIn = 90.0f;
}

/* The table: turn it and every item on it by 0.75 degrees; an item 450 or more from the centre
   falls off. */
/* NON_MATCHING: `it` and `o` take each other's saved registers (s1/s2; masked 0, raw 29). */
#ifdef NON_MATCHING
void func_8010378C_1226CC_RakinEmIn(omObjData* obj) {
    Vec c;
    Vec p;
    Vec d;
    RIItem* it;
    RIObj* o;
    omObjData* io;
    u16 frame;
    s16 i;

    it = D_801070B8_125FF8_RakinEmIn;
    for (i = 0; i < 20; i++, it++) {
        it->flags ^= 2;
    }
    obj->rot.y = func_80102EB4_121DF4_RakinEmIn(obj->rot.y, 0.75f);
    c.x = obj->trans.x;
    c.y = obj->trans.y;
    c.z = obj->trans.z;
    for (i = 0; i < 20; i++) {
        it = &D_801070B8_125FF8_RakinEmIn[i];
        if (!(it->flags & 4)) {
            o = &D_80107520_126460_RakinEmIn[i];
            io = o->obj;
            p.x = io->trans.x;
            p.y = io->trans.y;
            p.z = io->trans.z;
            func_80102B40_121A80_RakinEmIn(&c, &p, &d);
            it->dist = d.x;
            d.z = func_80102EB4_121DF4_RakinEmIn(d.z, 0.75f);
            io->trans.x = it->dist * func_800B80D0_B8CD0(d.z);
            io->trans.z = it->dist * func_800B75D0_B81D0(d.z);
            it->angle = d.z < 90.0f ? d.z : d.z < 180.0f ? d.z - 90.0f : d.z < 270.0f ? d.z - 180.0f : d.z - 270.0f;
            io->rot.y = func_80102EB4_121DF4_RakinEmIn(io->rot.y, 0.75f);
            if (io->rot.y >= 240.0f) {
                frame = io->rot.y - 240.0f;
            } else if (io->rot.y >= 120.0f) {
                frame = io->rot.y - 120.0f;
            } else {
                frame = io->rot.y;
            }
            o->unk_22 = frame / 3.75;
            func_8003E560_3F160(o->unk_20, o->unk_22);
            if (d.x >= 450.0f) {
                o->unk_40 = (io->trans.x > 0.0f) ? 6.5f : -6.5f;
                o->unk_44 = (io->trans.z > 0.0f) ? 6.5f : -6.5f;
                o->unk_38 = -1.0f;
                o->unk_3C = 0.0f;
                o->com = 1;
                it->flags |= 4;
            } else {
                o->unk_40 = io->trans.x;
                o->unk_44 = io->trans.z;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_8010378C_1226CC_RakinEmIn);
#endif

void func_80103BB0_122AF0_RakinEmIn(omObjData* obj) {
    GroundWork* gw;

    func_800B0EF0_B1AF0(D_801070B8_125FF8_RakinEmIn, 0, sizeof(D_801070B8_125FF8_RakinEmIn));
    func_801036F4_122634_RakinEmIn();
    D_801071A8_1260E8_RakinEmIn = 3;
    D_801071A9_1260E9_RakinEmIn = 2;
    D_801071AA_1260EA_RakinEmIn = 18;
    D_801071AC_1260EC_RakinEmIn = 0;
    D_801071AB_1260EB_RakinEmIn = 0;
    D_801071E0_126120_RakinEmIn[0] = func_8001A2F8_1AEF8(0x1A0000);
    D_80107374_1262B4_RakinEmIn = SprCreate(1, 0);
    SprAttrReset(D_80107374_1262B4_RakinEmIn, 0, -1);
    SprScaleSet(D_80107374_1262B4_RakinEmIn, 0, 1.0f, 1.0f);
    SprAnimSet(D_80107374_1262B4_RakinEmIn, 0, D_801071E0_126120_RakinEmIn[0], 0);
    SprBankSet(D_80107374_1262B4_RakinEmIn, 0, 0);
    SprAttrSet(D_80107374_1262B4_RakinEmIn, 0, 0x5000);
    SprPosSet(D_80107374_1262B4_RakinEmIn, 0, 160, 120);
    func_8008225C_82E5C(D_80107374_1262B4_RakinEmIn, 0, 0);
    SprPrioSet(D_80107374_1262B4_RakinEmIn, 0, 0xFFF0);
    obj->model[0] = LoadFormFile(0x1A0001, 0x6B9);
    obj->model[1] = LoadFormFile(0x1A0002, 0x6B9);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_8010378C_1226CC_RakinEmIn;
}

void func_80103E04_122D44_RakinEmIn(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_80107370_1262B0_RakinEmIn = omAddObj(10, 2, 0, -1, func_80103BB0_122AF0_RakinEmIn);
}

/* A player: swing with its rake (state 1), or the result motion. */
void func_80103E4C_122D8C_RakinEmIn(omObjData* obj) {
    RIObj* p = &D_80107250_126190_RakinEmIn[obj->work[0]];
    RIObj* r = &D_80107250_126190_RakinEmIn[obj->work[0] + 5];
    f32 t;

    switch (p->state) {
    case 0:
        if (r->state != 0 && r->state < 3) {
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029C74_2A874(obj->model[0], 0.0f);
            p->state = 1;
        } else if (r->unk_24 != 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[r->unk_24]);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029C74_2A874(obj->model[0], 0.0f);
            p->state = 2;
        }
        break;
    case 1:
        t = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= t) {
            func_80029E80_2AA80(obj->model[0], 0, 1);
            p->state = 0;
        }
        break;
    case 2:
        break;
    }
}

void func_80103F9C_122EDC_RakinEmIn(omObjData* obj) {
    RIObj* p = &D_80107250_126190_RakinEmIn[obj->work[0]];
    s8 chr = gPlayers[obj->work[0]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 ovl = 0x1A0000;
    s32 mdl = D_800CD438_CE038[chr].unk_08;
    RIStation* st;
    MgWork* w;

    obj->unk_50 = func_80027154_27D54(0x15C, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0x15C);
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 0xC, 0x7918);
    w->unk_57 = gPlayers[obj->work[0]].port;
    obj->model[0] = LoadFormFile(dir | mdl, 0x6B9);
    func_80018CCC_198CC(obj, 0, D_80106F78_125EB8_RakinEmIn[chr][0] | ovl);
    func_80018CCC_198CC(obj, 1, D_80106F7A_125EBA_RakinEmIn[chr * 2] | ovl);
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_8000C024_CC24(obj, 0, 2);
    st = &D_80106CC0_125C00_RakinEmIn[obj->work[0]];
    obj->rot.y = st->angle;
    obj->trans.x = st->pos.x + func_800B80D0_B8CD0(obj->rot.y) * -3.0 * 5.0;
    obj->trans.y = st->pos.y + 37.5;
    obj->trans.z = st->pos.z + func_800B75D0_B81D0(obj->rot.y) * -3.0 * 5.0;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.1f;
    func_8010281C_12175C_RakinEmIn(obj->work[0]);
    p->com = gPlayers[obj->work[0]].flags & 1;
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_80103E4C_122D8C_RakinEmIn;
}

void func_8010428C_1231CC_RakinEmIn(void) {
    RIObj* p = D_80107250_126190_RakinEmIn;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        o = omAddObj(200, 1, 3, -1, func_80103F9C_122EDC_RakinEmIn);
        /* retail never advances p: entry 0 ends up holding player 3 (the rakes and items use [i]) */
        p->player = i;
        o->work[0] = i;
        p->obj = o;
        D_800FFFD8_100BD8[i] = o;
        D_800FC87A_FD47A++;
    }
}

/* CPU: whether `player` lets item `item` pass. */
s16 func_80104340_123280_RakinEmIn(s16 player, s16 item) {
    RIStation* st = &D_80106CC0_125C00_RakinEmIn[player];
    s16 found = 0;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (st->target[i] == item) {
            found = 1;
            break;
        }
    }
    return found;
}

void func_801043B0_1232F0_RakinEmIn(s16 player, s16 item) {
    RIStation* st = &D_80106CC0_125C00_RakinEmIn[player];
    s16 i;

    for (i = 0; i < 4; i++) {
        if (st->target[i] == -1) {
            st->target[i] = item;
            return;
        }
    }
}

void func_80104418_123358_RakinEmIn(s16 player) {
    RIStation* st = &D_80106CC0_125C00_RakinEmIn[player];
    s16 i;

    for (i = 0; i < 4; i++) {
        st->target[i] = -1;
    }
}

/* CPU: by difficulty, a random reach error and the number of items it lets pass. */
void func_80104474_1233B4_RakinEmIn(RIObj* o) {
    u16 miss[4] = { 15, 30, 50, 70 };
    u16 pass[4] = { 60, 40, 20, 10 };
    u16 most[4] = { 2, 1, 1, 1 };
    f32 err;
    s16 n;

    err = 0.0f;
    o->unk_26 = 0;
    if ((u8)(rand8() % 100) > miss[o->unk_28]) {
        err = (u8)(rand8() % 10) + 10;
        if (rand8() & 1) {
            err = -err;
        }
    }
    if ((u8)(rand8() % 100) < pass[o->unk_28]) {
        n = most[o->unk_28];
        if (n != 0) {
            o->unk_26 = rand8() % n + 1;
        } else {
            o->unk_26 = n;
        }
    }
    o->unk_40 = err;
}

/* CPU: whether to swing now (an item in its quarter has turned into reach). */
/* NON_MATCHING: retail copies hit into v0 at the switch's join and keeps it->angle in a register (delay slots) */
#ifdef NON_MATCHING
s16 func_8010468C_1235CC_RakinEmIn(RIObj* o, s16 player) {
    RIItem* it;
    RIObj* o2;
    omObjData* io;
    f32 reach;
    s32 hit;
    s16 i;

    hit = 0;
    for (i = 0; i < 20; i++) {
        it = &D_801070B8_125FF8_RakinEmIn[i];
        if (it->flags & 4) {
            continue;
        }
        if (D_801071AA_1260EA_RakinEmIn >= 5 && func_80104340_123280_RakinEmIn(player, i) != 0) {
            continue;
        }
        o2 = &D_80107520_126460_RakinEmIn[i];
        if (o2->unk_28 == 1) {
            continue;
        }
        io = o2->obj;
        hit = 0;
        switch (player) {
        case 0:
            if (io->trans.x < 0.0f && io->trans.z < 0.0f) {
                hit = 1;
            }
            break;
        case 1:
            if (io->trans.x > 0.0f && io->trans.z < 0.0f) {
                hit = 1;
            }
            break;
        case 2:
            if (io->trans.x < 0.0f && io->trans.z > 0.0f) {
                hit = 1;
            }
            break;
        default:
            if (io->trans.x > 0.0f && io->trans.z > 0.0f) {
                hit = 1;
            }
            break;
        }
        if (!hit) {
            continue;
        }
        reach = (450.0f - it->dist) / 18.75f + o->unk_40;
        if (reach < 0.0f) {
            reach = 0.0f;
        }
        if (reach <= it->angle && it->angle <= reach + 0.75f) {
            break;
        }
        hit = 0;
    }
    if (D_801071AA_1260EA_RakinEmIn >= 5 && hit) {
        if (o->unk_26 != 0) {
            func_801043B0_1232F0_RakinEmIn(player, i);
            o->unk_26--;
            hit = 0;
        } else {
            func_80104418_123358_RakinEmIn(player);
        }
    }
    return hit;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_8010468C_1235CC_RakinEmIn);
#endif

/* Items within 75 of `obj` (item `item`) are pushed by it. */
/* NON_MATCHING: 5625.0f hoisted to the top, v0/v1 swap in the abs */
#ifdef NON_MATCHING
void func_80104950_123890_RakinEmIn(omObjData* obj, s16 item) {
    RIItem* it;
    omObjData* io;
    f32 dx;
    f32 dz;
    s32 d;
    s16 i;
    u8 fl;

    for (i = 0; i < 20; i++) {
        if (i == item) {
            continue;
        }
        it = &D_801070B8_125FF8_RakinEmIn[i];
        fl = it->flags;
        if (fl & 4) {
            continue;
        }
        io = (D_80107520_126460_RakinEmIn + i)->obj;
        if (it->flags == 0) {
            d = io->trans.x - obj->trans.x;
            if (d < 0) {
                d = -d;
            }
            dx = d;
            d = io->trans.z - obj->trans.z;
            if (d < 0) {
                d = -d;
            }
            dz = d;
            if (dx * dx + dz * dz <= 5625.0f) {
                it->flags = fl | 1;
                it->by = item;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104950_123890_RakinEmIn);
#endif

/* Whether `angle` lies within `range` of `center` (degrees, wrapping at 360). */
u8 func_80104A6C_1239AC_RakinEmIn(f32 center, f32 angle, f32 range) {
    f32 lo = center - range;
    f32 hi = center + range;
    s32 in = 0;

    if (lo < 0.0f) {
        if ((angle >= 0.0f) & (angle <= hi)) {
            in = 1;
        } else if (lo + 360.0f <= angle) {
            in = 1;
        }
    } else if (hi > 360.0f) {
        if ((lo <= angle) & (angle <= 360.0f)) {
            in = 1;
        } else if (angle <= hi - 360.0f) {
            in = 1;
        }
    } else if ((lo <= angle) & (angle <= hi)) {
        in = 1;
    }
    return in;
}

/* A rake (obj->work[0] = player + 5): A (or the CPU) swings it; while it sweeps (state 2) the
   head moves in from the reach and catches every item near it inside the angle window. At the
   end the winners' rakes play the win motion. */
/* NON_MATCHING: the item loop keeps i and a sign-extended copy in s5/s1 and hoists 10000.0f (registers only) */
#ifdef NON_MATCHING
void func_80104BCC_123B0C_RakinEmIn(omObjData* obj) {
    Vec a;
    Vec b;
    Vec d;
    RIObj* r = &D_80107250_126190_RakinEmIn[obj->work[0]];
    u16 pan[4] = { 32, 96, 48, 80 };
    s16 player = obj->work[0] - 5;
    RIStation* head = &D_80106CF0_125C30_RakinEmIn[player];
    RIItem* it;
    omObjData* io;
    f32 len;
    f32 dx;
    f32 dz;
    s32 n;
    s16 swing;
    s16 i;

    swing = 0;
    switch (r->state) {
    case 0:
        if (D_801070A0_125FE0_RakinEmIn == 2) {
            if (r->com != 0) {
                swing = func_8010468C_1235CC_RakinEmIn(r, player);
            } else if (ContBtnTrg[gPlayers[player].port] & 0x8000) {
                swing = 1;
            }
            if (swing != 0) {
                func_80029E80_2AA80(obj->model[0], 1, 0);
                func_80029C74_2A874(obj->model[0], 0.0f);
                r->unk_3C = (func_80029D0C_2A90C(obj->model[0]) - 10.0f) / 2.0f;
                r->state = 1;
                func_80079798_7A398(0x159, player);
            }
        } else if (D_801070A0_125FE0_RakinEmIn == 4) {
            r->state = _CheckFlag(0xC) ? 4 : 3;
        }
        break;
    case 1:
        if (r->unk_3C <= func_80029CE4_2A8E4(obj->model[0])) {
            r->unk_3C = func_80029D0C_2A90C(obj->model[0]);
            r->state = 2;
            r->unk_38 = D_801070A8_125FE8_RakinEmIn + 600.0f;
        }
        break;
    case 2:
        if (r->unk_3C <= func_80029CE4_2A8E4(obj->model[0])) {
            func_80029E80_2AA80(obj->model[0], 0, 1);
            r->state = 0;
            func_80104474_1233B4_RakinEmIn(r);
        }
        break;
    case 3:
        if (D_801071B0_1260F0_RakinEmIn[player].score == D_801071AC_1260EC_RakinEmIn) {
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029C74_2A874(obj->model[0], 0.0f);
            r->unk_24 = 1;
            if (D_801071AB_1260EB_RakinEmIn >= 2) {
                func_800798F8_7A4F8(func_800797DC_7A3DC(0x103, player), pan[player]);
            } else if (D_801071AB_1260EB_RakinEmIn == 1) {
                func_800797DC_7A3DC(0x103, player);
            }
        } else {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029C74_2A874(obj->model[0], 0.0f);
        }
        r->state = 4;
        break;
    case 4:
        break;
    }
    if (r->state == 2) {
        head->pos.x = obj->trans.x + func_800B80D0_B8CD0(obj->rot.y) * r->unk_38;
        head->pos.z = obj->trans.z + func_800B75D0_B81D0(obj->rot.y) * r->unk_38;
        r->unk_38 -= 12.5f;
        len = 100.0f;
        for (i = 0; i < 20; i++) {
            it = &D_801070B8_125FF8_RakinEmIn[i];
            if (it->flags & 4) {
                continue;
            }
            io = D_80107520_126460_RakinEmIn[i].obj;
            n = io->trans.x - head->pos.x;
            if (n < 0) {
                n = -n;
            }
            dx = n;
            n = io->trans.z - head->pos.z;
            if (n < 0) {
                n = -n;
            }
            dz = n;
            if (dx * dx + dz * dz <= 10000.0f) {
                a.x = head->pos.x;
                a.y = head->pos.y;
                a.z = head->pos.z;
                b.x = io->trans.x;
                b.y = io->trans.y;
                b.z = io->trans.z;
                func_80102B40_121A80_RakinEmIn(&a, &b, &d);
                if (func_80104A6C_1239AC_RakinEmIn(func_80102EB4_121DF4_RakinEmIn(obj->rot.y, 180.0f), d.z,
                                                   D_801070AC_125FEC_RakinEmIn)) {
                    io->trans.x = head->pos.x + len * func_800B80D0_B8CD0(d.z);
                    io->trans.z = head->pos.z + len * func_800B75D0_B81D0(d.z);
                    it->flags |= 2;
                    func_80104950_123890_RakinEmIn(io, i);
                }
            }
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80107008_125F48_RakinEmIn[2] = { 0x00200060, 0x00300050 }; /* pan[4] */

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104BCC_123B0C_RakinEmIn);
#endif

__asm__(".section .rodata");
const char D_80107024_125F64_RakinEmIn[] = "arm_tex_00_DEF";

void func_801051D8_124118_RakinEmIn(omObjData* obj) {
    RIObj* r = &D_80107250_126190_RakinEmIn[obj->work[0]];
    s16 player = obj->work[0];
    s32 dir = 0x1A0000;
    RIStation* st;
    void* data;
    f64 a;
    f64 b;
    s8 chr;

    player -= 5;
    r->com = gPlayers[player].flags & 1;
    if (r->com != 0) {
        r->unk_28 = gPlayers[player].cpu_difficulty;
        func_80104474_1233B4_RakinEmIn(r);
    }
    chr = gPlayers[player].character;
    obj->model[0] = LoadFormFile(dir | 3, 0x6A9);
    data = DataRead(dir | D_80106DE0_125D20_RakinEmIn[chr]);
    func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, D_80107024_125F64_RakinEmIn);
    DataClose(data);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    st = &D_80106CC0_125C00_RakinEmIn[player];
    obj->trans.x = st->pos.x;
    obj->trans.y = st->pos.y;
    obj->trans.z = st->pos.z;
    obj->rot.y = st->angle;
    func_80018CCC_198CC(obj, 1, dir | 4);
    func_80018CCC_198CC(obj, 2, dir | 5);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    st->base.x = obj->trans.x + func_800B80D0_B8CD0(obj->rot.y) * 30.0 * 5.0;
    st->base.y = obj->trans.y;
    st->base.z = obj->trans.z + func_800B75D0_B81D0(obj->rot.y) * 30.0 * 5.0;
    a = func_80102EB4_121DF4_RakinEmIn(obj->rot.y, 90.0f);
    st->left.x = st->base.x + func_800B80D0_B8CD0(a) * 15.0 * 5.0;
    st->left.y = st->base.y;
    st->left.z = st->base.z + func_800B75D0_B81D0(a) * 15.0 * 5.0;
    b = func_80102EB4_121DF4_RakinEmIn(obj->rot.y, -90.0f);
    st->right.x = st->base.x + func_800B80D0_B8CD0(b) * 15.0 * 5.0;
    st->right.y = st->base.y;
    st->right.z = st->base.z + func_800B75D0_B81D0(b) * 15.0 * 5.0;
    r->unk_38 = D_801070A8_125FE8_RakinEmIn + 225.0f;
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_80104BCC_123B0C_RakinEmIn;
}

void func_80105550_124490_RakinEmIn(void) {
    RIObj* r;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        r = &D_801073B8_1262F8_RakinEmIn[i];
        o = omAddObj(100, 1, 3, -1, func_801051D8_124118_RakinEmIn);
        o->work[0] = r->player = i + 5;
        r->obj = o;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801055F4_124534_RakinEmIn);

__asm__(".section .rodata");
const char D_80107070_125FB0_RakinEmIn[] = "kin0_001_DEF";

/* An item: its kind (the kind 2 and kind 1 quotas first, then kind 0), its model and texture, and
   a free start position. */
void func_80105E98_124DD8_RakinEmIn(omObjData* obj) {
    RIObj* r = &D_80107250_126190_RakinEmIn[obj->work[0]];
    Vec* pos;
    void* data;
    s32 dir;
    u8 kind = 2;

    if (D_801071A8_1260E8_RakinEmIn != 0) {
        D_801071A8_1260E8_RakinEmIn--;
    } else {
        kind = 1;
        if (D_801071A9_1260E9_RakinEmIn != 0) {
            D_801071A9_1260E9_RakinEmIn--;
        } else {
            kind = 0;
        }
    }
    dir = 0x1A0000;
    obj->model[0] = func_80018A30_19630(0x1A000C, 0x6A9);
    data = DataRead(D_80106F14_125E54_RakinEmIn[kind] | dir);
    r->unk_20 = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, D_80107070_125FB0_RakinEmIn);
    DataClose(data);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_8003E4F4_3F0F4(r->unk_20, 1, 1);
    func_8003E560_3F160(r->unk_20, r->unk_22);
    pos = D_80106DEC_125D2C_RakinEmIn;
    pos = &pos[func_801028A0_1217E0_RakinEmIn(24, &D_801070B0_125FF0_RakinEmIn)];
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    r->unk_28 = kind;
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_801055F4_124534_RakinEmIn;
}

void func_80106060_124FA0_RakinEmIn(void) {
    RIObj* r;
    omObjData* o;
    s16 i;

    for (i = 0; i < 20; i++) {
        r = &D_80107520_126460_RakinEmIn[i];
        o = omAddObj(300, 1, 0, -1, func_80105E98_124DD8_RakinEmIn);
        o->work[0] = r->player = i + 10;
        r->obj = o;
    }
}

void func_80106104_125044_RakinEmIn(omObjData* obj) {
    if (D_80106F90_125ED0_RakinEmIn != 0) {
        if (--D_80106F90_125ED0_RakinEmIn == 0) {
            func_8006D518_6E118();
        }
    }
    if (D_801070A4_125FE4_RakinEmIn != 0) {
        D_801070A4_125FE4_RakinEmIn--;
    }
}

void func_80106164_1250A4_RakinEmIn(omObjData* obj) {
    if (D_801070A2_125FE2_RakinEmIn != 0) {
        D_801070A2_125FE2_RakinEmIn--;
    }
    func_8006D4D0_6E0D0((D_801070A2_125FE2_RakinEmIn + 29) / 30);
    if (D_801070A0_125FE0_RakinEmIn == 3) {
        D_801070A4_125FE4_RakinEmIn = 60;
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
        obj->func_ptr = func_80106104_125044_RakinEmIn;
        D_801070A2_125FE2_RakinEmIn = 0;
    }
}

void func_80106218_125158_RakinEmIn(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    obj->func_ptr = func_80106164_1250A4_RakinEmIn;
}

void func_80106258_125198_RakinEmIn(omObjData* obj) {
    switch (D_801070A0_125FE0_RakinEmIn) {
    case 1:
        if (D_801070A2_125FE2_RakinEmIn == 0) {
            func_800691FC_69DFC(0);
            D_801070A2_125FE2_RakinEmIn++;
        }
        break;
    case 2:
        obj->func_ptr = func_80106218_125158_RakinEmIn;
        break;
    }
}

/* Sets each player's bonus rank from the scores. */
void func_801062CC_12520C_RakinEmIn(void) {
    u16 scores[4];
    s16 i;
    s16 j;
    u16 mask;
    RIScore* s;
    u16 t;

    for (s = D_801071B0_1260F0_RakinEmIn, j = 0; j < 4; j++, s++) {
        scores[j] = s->score;
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (scores[i] == scores[j]) {
                scores[j] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 3; i < j; j--) {
            if (scores[j] > scores[j - 1]) {
                t = scores[j];
                scores[j] = scores[j - 1];
                scores[j - 1] = t;
            }
        }
    }
    for (i = 0, mask = 0; i < 4; i++) {
        for (s = D_801071B0_1260F0_RakinEmIn, j = 0; j < 4; j++, s++) {
            if (!((mask >> j) & 1) && s->score == scores[i]) {
                gPlayers[j].coins_mg_bonus = i;
                mask |= 1 << j;
            }
        }
    }
}

/* 1 when no rake, item or score display is busy. */
u8 func_801064C8_125408_RakinEmIn(void) {
    u8 busy = 0;
    u8 i;
    RIObj* o;
    RIScore* s;

    for (i = 0, o = D_801073B8_1262F8_RakinEmIn; i < 4; i++) {
        if (o[i].state != 0) {
            busy = 1;
            break;
        }
    }
    if (busy == 0) {
        for (i = 0, o = D_80107520_126460_RakinEmIn; i < 20; i++) {
            if (o[i].com & 3) {
                busy = 1;
                break;
            }
        }
    }
    if (busy == 0) {
        for (i = 0, s = D_801071B0_1260F0_RakinEmIn; i < 4; i++) {
            if (s[i].state != 0) {
                busy = 1;
                break;
            }
        }
    }
    return busy ^ 1;
}

void func_801065BC_1254FC_RakinEmIn(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_801065E0_125520_RakinEmIn(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_801065BC_1254FC_RakinEmIn;
    }
}

void func_80106618_125558_RakinEmIn(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_801065E0_125520_RakinEmIn;
    }
}

/* The game's states: 0 the wait before the start, 1 the start banner, 2 play, 3 the end banner
   and the wait for everything to settle (best score and winners counted here), 4 the result
   wait, 5 fade out. */
void func_80106670_1255B0_RakinEmIn(omObjData* obj) {
    s16 i;
    RIScore* s;

    switch (D_801070A0_125FE0_RakinEmIn) {
    case 0:
        if (D_801070A2_125FE2_RakinEmIn == 0) {
            PlaySound(0x4A1);
        }
        if (D_801070A2_125FE2_RakinEmIn++ >= 31) {
            D_801070A0_125FE0_RakinEmIn = 1;
            PlayMusic(0x2B);
            D_801070A2_125FE2_RakinEmIn = 0;
        }
        break;
    case 1:
        if (func_80069538_6A138() == 0) {
            D_801070A0_125FE0_RakinEmIn = 2;
            D_801070A2_125FE2_RakinEmIn = 901;
        }
        break;
    case 2:
        if (D_801070A2_125FE2_RakinEmIn == 0 || D_801071AA_1260EA_RakinEmIn == 0) {
            D_801070A0_125FE0_RakinEmIn = 3;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 0 && func_801064C8_125408_RakinEmIn()
            && (D_801070A2_125FE2_RakinEmIn >= 20 || ++D_801070A2_125FE2_RakinEmIn >= 20)) {
            for (i = 0; i < 4; i++) {
                s = &D_801071B0_1260F0_RakinEmIn[i];
                if (s->score == D_801071AC_1260EC_RakinEmIn) {
                    D_801071AB_1260EB_RakinEmIn++;
                } else if (s->score > D_801071AC_1260EC_RakinEmIn) {
                    D_801071AC_1260EC_RakinEmIn = s->score;
                    D_801071AB_1260EB_RakinEmIn = 1;
                }
            }
            D_801070A0_125FE0_RakinEmIn = 4;
            if (_CheckFlag(0xC) == 0) {
                D_801070A2_125FE2_RakinEmIn = D_801071AB_1260EB_RakinEmIn == 1 ? 120 : 168;
                PlayMusic(D_801071AB_1260EB_RakinEmIn >= 2 ? 0x52 : 0x51);
            }
            func_801062CC_12520C_RakinEmIn();
        }
        break;
    case 4:
        if ((_CheckFlag(0xC) != 0 ? D_801070A4_125FE4_RakinEmIn : --D_801070A2_125FE2_RakinEmIn) == 0) {
            D_801070A0_125FE0_RakinEmIn = 5;
        }
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_801065E0_125520_RakinEmIn;
        break;
    }
    func_80102F0C_121E4C_RakinEmIn();
}

void func_80106920_125860_RakinEmIn(omObjData* obj) {
    func_80106C10_125B50_RakinEmIn();
    func_80106C94_125BD4_RakinEmIn();
    D_801070B0_125FF0_RakinEmIn = 0;
    func_80103E04_122D44_RakinEmIn();
    func_8010428C_1231CC_RakinEmIn();
    func_80105550_124490_RakinEmIn();
    func_80106060_124FA0_RakinEmIn();
    func_801036B8_1225F8_RakinEmIn();
    InitFadeIn(0, 16);
    obj->func_ptr = func_80106670_1255B0_RakinEmIn;
    D_801070A0_125FE0_RakinEmIn = 0;
    D_801070A2_125FE2_RakinEmIn = 0;
    D_801070A4_125FE4_RakinEmIn = 0;
    omAddObj(900, 0, 0, -1, func_80106258_125198_RakinEmIn);
}

__asm__(".section .rodata");
const char D_80107098_125FD8_RakinEmIn[] = "\202`\202a\202b";

void func_801069D8_125918_RakinEmIn(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0, 0, 0);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
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
    omAddObj(0x3E8, 0, 0, -1, func_80106920_125860_RakinEmIn);
    omAddObj(0x3E8, 0, 0, -1, func_80106618_125558_RakinEmIn);
    func_8007273C_7333C(D_80107098_125FD8_RakinEmIn, 0);
    func_8007273C_7333C(D_80107098_125FD8_RakinEmIn, 1);
}
