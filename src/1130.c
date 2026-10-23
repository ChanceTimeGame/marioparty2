#include "common.h"
#include "game/collision.h"

/* Collision and minigame actor physics. MP1 src/1130.c's collision helpers (func_80002218_2E18
   on) grown by an item actor (func_80000530_1130 .. func_80002178_2D78, MP3's minigame overlay
   twins) and the player's ground search (func_800023CC_2FCC .. func_8000312C_3D2C). */

f64 fabs(f64);
f32 fabsf(f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);               /* cos */
f32 func_800B75A8_B81A8(f32, f32);          /* atan2 (degrees) */
f32 func_800B1830_B2430(f32);               /* sqrtf */
f32 func_800B3500_B4100(Vec3f*, Vec3f*);    /* dot product */
void HuVecAdd(Vec3f*, Vec3f*, Vec3f*);
void HuVecSubtract(Vec3f*, Vec3f*, Vec3f*);
void* func_80027154_27D54(s32 size, s32 tag);
void func_800B0EF0_B1AF0(void*, s32, s32);  /* memset */
void PlaySound(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_80018A64_19664(s32, s32);
void func_80021160_21D60(s16, s32, s32);
void func_80021198_21D98(s16, s32);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80029714_2A314(s16 idx, f32 x, f32 y, f32 z); /* model position */
void func_800297E8_2A3E8(s16 idx, f32 x, f32 y, f32 z); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_8003C984_3D584(s16, Vec3f* n);
void func_80009684_A284(f32 dx, f32 dz, f32 d); /* MP1 func_800078E8 */
void func_8000C11C_CD1C(omObjData*, s32, s32, s32);
void func_8000C2A0_CEA0(omObjData*, s32, s32, s32, s32);
void func_8000C35C_CF5C(omObjData*, f32, f32, f32);
void func_8000C37C_CF7C(omObjData*, f32, f32, f32);
void func_8000D434_E034(f32 (*)[4], f32 (*)[4], Vec3f*, omObjData*);
void func_8000D6D0_E2D0(f32 (*)[4], Vec3f*);
void func_8000D74C_E34C(f32 (*)[4], Vec3f*);
void func_8000D7E0_E3E0(f32 (*)[4], Vec3f*);
s32 func_8000DA98_E698(HmfPart*, Vec3f*);
s32 func_8000DB30_E730(HmfPart*, Vec3f*, f32);
s32 func_8000DC10_E810(Vec3f*, GroundWork*);
s32 func_80005110_5D10();
s32 func_80005700_6300();
void func_80005D60_6960(omObjData*, Vec4f*);
void func_800061E4_6DE4(omObjData*, Vec4f*);
void func_800062F0_6EF0(omObjData*, Vec4f*, f32);
void func_800066BC_72BC(omObjData*, Vec4f*, f32);

extern f32 D_800BF780_C0380;
extern f32 D_800BF784_C0384;
extern f32 D_800BF788_C0388;
extern f32 D_800BF78C_C038C;
extern u8 D_800BF794_C0394;
extern s16 D_800BF796_C0396; /* contact count */
extern u8 D_800BF798_C0398;
extern u8 D_800BF799_C0399;
extern f32 D_800BF7A0_C03A0;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7D0_C03D0;
extern f32 D_800BF7D8_C03D8;
extern f32 D_800BF7DC_C03DC;
extern Vec3f D_800D5750_D6350;   /* the actor's position at the start of its step */
extern Vec3f D_800FD8C8_FE4C8[]; /* contact points */

f32 func_800007D4_13D4(omObjData* obj, f32 x, f32 y, f32 z);
void func_80000834_1434(omObjData* obj, Vec3f* n);
void func_800008E0_14E0(omObjData* obj, Vec3f* n);
void func_80000A44_1644(ColActorWork* w);
void func_80000ACC_16CC(omObjData* obj);
void func_80000BB0_17B0(omObjData* obj);
f32 func_80000C70_1870(omObjData* obj, Vec4f* p);
void func_80000D48_1948(omObjData* obj, f32 x, f32 y, f32 z, f32 g, Vec3f* n);
f32 func_80000E6C_1A6C(omObjData* obj, Vec4f* p, Vec3f* n);
void func_80001468_2068(omObjData* obj, f32 x, f32 y, f32 z);
void func_800015D4_21D4(omObjData* obj, Vec4f* p);
void func_80001964_2564(omObjData* obj);
void func_80001A98_2698(omObjData* obj);
f32 func_80002218_2E18(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri, Vec3f* dir, Vec3f* out);
f32 func_80002040_2C40(omObjData* g, MgWork* w, f32 y);
f32 func_80002178_2D78(omObjData* g, MgWork* w, f32 h, f32 y, Vec3f* n);
f32 func_800023CC_2FCC(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* n);
f32 func_80003910_4510(omObjData* obj, f32 y);
s32 func_80004168_4D68(omObjData* obj, f32 x, f32 y, f32 z);
void func_80005034_5C34(omObjData* obj);
s32 func_80006F34_7B34(omObjData* obj, Vec4f* p, f32 arg2);
void func_8000755C_815C(omObjData* obj, Vec3f* n);
void func_8000BA38_C638(omObjData* obj, f32 y);
void func_8000BAF0_C6F0(omObjData* obj, f32 x, f32 y, f32 z, f32 shadowY, Vec3f* n);
void func_8000C398_CF98(void);
void func_8000C584_D184(MgWork* w, s32 state);
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion);

void func_80000530_1130(omObjData* obj) {
    ColActorWork* w = obj->unk_50;
    s32 ret = 1;
    f32 x, y, z;
    f32 rot;
    f32 vy;
    f32 h;

    if (w->unk_50 & 0x20) {
        if (w->unk_50 & 0x10) {
            return;
        }
    }
    {
        D_800F94A0_FA0A0 = D_80101308_101F08 = 0.0f;
        D_800D5750_D6350.x = x = obj->trans.x;
        D_800D5750_D6350.y = y = obj->trans.y;
        D_800D5750_D6350.z = z = obj->trans.z;
        rot = w->unk_3C;
        if (w->unk_84[0] != NULL && w->unk_84[0](obj) == 1) {
            return;
        }
        x += HuMathSin(rot) * w->unk_40;
        z += func_800B7890_B8490(rot) * w->unk_40;
        func_80000A44_1644(w);
        vy = w->unk_38;
        if (vy != 1000.0f) {
            y += vy * vy * ((vy >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800BF78C_C038C;
            if (D_800BF780_C0380 < w->unk_38) {
                w->unk_38 = D_800BF780_C0380;
            }
            h = func_800007D4_13D4(obj, x, y, z);
            if (y < h) {
                if (w->unk_84[4] != NULL) {
                    ret = w->unk_84[4](obj);
                }
                y = h;
                if (ret != 1) {
                    w->unk_38 = -w->unk_38 * 0.7f;
                    if (w->unk_38 >= -0.4f) {
                        w->unk_38 = 1000.0f;
                    }
                    /* retail passes the work, not the object (see func_80000ACC_16CC) */
                    func_80000ACC_16CC((omObjData*)w);
                }
            }
        } else {
            y = func_800007D4_13D4(obj, x, y, z);
            func_80000ACC_16CC(obj);
            func_80000BB0_17B0(obj);
        }
        func_8000C35C_CF5C(obj, x + D_800F94A0_FA0A0, y, z + D_80101308_101F08);
        func_80001A98_2698(obj);
        if (w->unk_84[1] != NULL) {
            w->unk_84[1](obj);
        }
    }
}

f32 func_800007D4_13D4(omObjData* obj, f32 x, f32 y, f32 z) {
    ColActorWork* w = obj->unk_50;
    Vec4f p;

    p.x = x;
    p.y = y;
    p.z = z;
    p.w = w->unk_48;
    func_80001468_2068(obj, x, y, z);
    func_800015D4_21D4(obj, &p);
    return func_80000C70_1870(obj, &p);
}

void func_80000834_1434(omObjData* obj, Vec3f* n) {
    ColActorWork* w = obj->unk_50;
    GroundWork* gw;

    if (w->unk_53 >= 0 && w->unk_38 == 1000.0f) {
        gw = D_800FC7B0_FD3B0[w->unk_53]->unk_50;
        w->unk_5C = n->x * gw->unk_10;
        w->unk_60 = n->y;
        w->unk_64 = n->z * gw->unk_10;
        if (gw->unk_06 & 0x400) {
            func_800008E0_14E0(obj, n);
        }
    } else {
        w->unk_5C = 0.0f;
        w->unk_60 = 0.0f;
        w->unk_64 = 0.0f;
    }
}

void func_800008E0_14E0(omObjData* obj, Vec3f* n) {
    ColActorWork* w = obj->unk_50;
    f32 ax = -(func_800B75A8_B81A8(n->y, n->z) - 90.0f);
    f32 az = func_800B75A8_B81A8(n->y, n->x) - 90.0f;
    f32 cx = w->unk_68;
    f32 cz = w->unk_70;

    if (cx < ax) {
        w->unk_68 = cx + D_800BF788_C0388;
        if (ax < w->unk_68) {
            w->unk_68 = ax;
        }
    } else if (ax < cx) {
        w->unk_68 -= D_800BF788_C0388;
        if (w->unk_68 < ax) {
            w->unk_68 = ax;
        }
    }
    if (cz < az) {
        w->unk_70 += D_800BF788_C0388;
        if (az < w->unk_70) {
            w->unk_70 = az;
        }
    } else if (az < cz) {
        w->unk_70 -= D_800BF788_C0388;
        if (w->unk_70 < az) {
            w->unk_70 = az;
        }
    }
    obj->rot.x = w->unk_68;
    obj->rot.z = w->unk_70;
}

void func_80000A44_1644(ColActorWork* w) {
    if (fabs(w->unk_5C) > 1.0) {
        D_800F94A0_FA0A0 += w->unk_5C * w->unk_58;
    }
    if (fabs(w->unk_64) > 1.0) {
        D_80101308_101F08 += w->unk_64 * w->unk_58;
    }
}

/* Retail tests w->unk_53 before it loads w: the work pointer is whatever the caller left in
   s0, which both callers (func_80000530_1130) have set to this actor's work. One caller passes
   the work as obj. Host hazard: the read of the uninitialised w is undefined in C. */
void func_80000ACC_16CC(omObjData* obj) {
    ColActorWork* w;
    f32 f;

    if (w->unk_53 != -1) {
        w = obj->unk_50;
        if (w->unk_84[2] == NULL || w->unk_84[2](obj) != 1) {
            f = ((GroundWork*)D_800FC7B0_FD3B0[w->unk_53]->unk_50)->unk_08;
            if (f != 0.0f) {
                w->unk_40 = w->unk_40 - f;
            } else {
                w->unk_40 = w->unk_40 - D_800BF7A0_C03A0;
            }
            if (w->unk_40 < D_800BF7D0_C03D0) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
            if (w->unk_40 > D_800BF784_C0384) {
                w->unk_40 = D_800BF784_C0384;
            }
        }
    }
}

void func_80000BB0_17B0(omObjData* obj) {
    ColActorWork* w = obj->unk_50;
    Vec3f v;

    if (w->unk_84[3] == NULL || w->unk_84[3](obj) != 1) {
        v.x = -D_800F94A0_FA0A0;
        v.y = 0.0f;
        v.z = -D_80101308_101F08;
        func_8002D9AC_2E5AC(&v);
        v.x = HuMathSin(w->unk_3C) - v.x / 20.0f;
        v.z = func_800B7890_B8490(w->unk_3C) - v.z / 20.0f;
        w->unk_3C = func_800B75A8_B81A8(v.x, v.z);
    }
}

f32 func_80000C70_1870(omObjData* obj, Vec4f* p) {
    ColActorWork* w = obj->unk_50;
    Vec3f n;
    f32 y = p->y;
    f32 h = func_80000E6C_1A6C(obj, p, &n);
    f32 g = h;

    if (h < y - w->unk_34 || y + w->unk_34 <= h) {
        if (w->unk_38 == 1000.0f) {
            w->unk_38 = 0.0f;
        }
        h = y;
    }
    func_80000D48_1948(obj, p->x, h, p->z, g, &n);
    return h;
}

void func_80000D48_1948(omObjData* obj, f32 x, f32 y, f32 z, f32 g, Vec3f* n) {
    ColActorWork* w = obj->unk_50;
    f32 s = 1.0f;
    f32 d;

    if (obj->model[1] != 0) {
        d = y - g;
        if (d != 0.0f) {
            if (d > 400.0f) {
                s = 0.6f;
            } else {
                s = 1.0 - fabs(d) / 1000.0;
            }
            w->unk_53 = -1;
        }
        func_80029714_2A314(obj->model[1], x, g + 2.0f, z);
        func_800297E8_2A3E8(obj->model[1], s, 1.0f, s);
        func_8003C984_3D584(obj->model[1], n);
    }
}

f32 func_80000E6C_1A6C(omObjData* obj, Vec4f* p, Vec3f* n) {
    Vec3f q;
    s32 pad[8]; /* unused stack space in retail */
    Vec3f a;
    Vec3f d;
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;
    ColActorWork* w = obj->unk_50;
    f32 best = -65536.0f;
    s16 i;
    omObjData* g;
    GroundWork* gw;
    f32 h;
    s16 mdl;
    ColVtx* verts;
    ColTri* tri;
    u8 moved;

    w->unk_53 = -1;
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        g = D_800FC7B0_FD3B0[i];
        gw = g->unk_50;
        if (w->unk_00[i] & 1) {
            continue;
        }
        q.x = x;
        q.y = y;
        q.z = z;
        func_8000D434_E034(D_800FC838_FD438, D_800F94C8_FA0C8, &q, g);
        if ((gw->unk_06 & 4) && func_8000DA98_E698(D_800FC834_FD434[*g->model].hmf->unk64, &q) == 0) {
            continue;
        }
        if (gw->unk_06 & 0x7A) {
            if ((gw->unk_06 & 0x50) && func_8000DC10_E810(&q, gw) == 0) {
                continue;
            }
            h = gw->unk_14;
            if (g->trans.x != 0.0f || g->trans.y != 0.0f || g->trans.z != 0.0f || g->rot.x != 0.0f ||
                g->rot.y != 0.0f || g->rot.z != 0.0f) {
                q.y = h;
                func_8000D7E0_E3E0(D_800FC838_FD438, &q);
                if (best <= q.y && q.y < y + 150.0f) {
                    best = q.y;
                    w->unk_53 = i;
                    if (n != NULL) {
                        a.x = 0.0f;
                        a.y = 1.0f;
                        a.z = 0.0f;
                        func_8000D6D0_E2D0(D_800FC838_FD438, &a);
                        n->x = a.x;
                        n->y = a.y;
                        n->z = a.z;
                        func_8002D9AC_2E5AC(n);
                    }
                }
            } else if (best <= h && h < y + 150.0f) {
                best = h;
                w->unk_53 = i;
                if (n != NULL) {
                    n->x = 0.0f;
                    n->y = 1.0f;
                    n->z = 0.0f;
                }
            }
        } else {
            mdl = *g->model;
            verts = D_800FC834_FD434[mdl].hmf->unk54;
            func_8002F2C4_2FEC4(mdl, D_800F9D30_FA930, func_80005110_5D10, &q);
            for (tri = func_8002F848_30448(D_800F9D30_FA930); tri != NULL; tri = func_8002F848_30448(D_800F9D30_FA930)) {
                HmfModel* m = &D_800FC834_FD434[mdl];

                moved = 0;
                if (m->pos.x != 0.0f || m->pos.y != 0.0f || m->pos.z != 0.0f || m->rot.x != 0.0f ||
                    m->rot.y != 0.0f || m->rot.z != 0.0f) {
                    a.x = x;
                    a.y = y + 10.0f;
                    a.z = z;
                    func_8000D74C_E34C(D_800F94C8_FA0C8, &a);
                    d.x = a.x - q.x;
                    d.y = a.y - q.y;
                    d.z = a.z - q.z;
                    func_8002D9AC_2E5AC(&d);
                    func_80002218_2E18(q.x, q.y, q.z, verts, tri, &d, &q);
                    func_8000D7E0_E3E0(D_800FC838_FD438, &q);
                    h = q.y;
                    moved = 1;
                } else {
                    h = func_8002DBA4_2E7A4(q.x, q.y, q.z, verts, tri);
                }
                if (best <= h && h < y + 150.0f) {
                    best = h;
                    w->unk_53 = i;
                    if (n != NULL) {
                        func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], n);
                        if (moved == 1) {
                            a.x = n->x;
                            a.y = n->y;
                            a.z = n->z;
                            func_8000D6D0_E2D0(D_800FC838_FD438, &a);
                            n->x = a.x;
                            n->y = a.y;
                            n->z = a.z;
                            func_8002D9AC_2E5AC(n);
                        }
                    }
                }
            }
        }
    }
    func_80000834_1434(obj, n);
    return best;
}

// register allocation (masked 0): x/z and the 0.0f constant in other float registers
#ifdef NON_MATCHING
void func_80001468_2068(omObjData* obj, f32 x, f32 y, f32 z) {
    ColActorWork* w = obj->unk_50;
    omObjData* o;
    MgWork* ow;
    f32 dx, dz;
    f32 d;
    s32 i;

    if (!(w->unk_52 & 7)) {
        for (i = 0; i < D_800FC87A_FD47A; i++) {
            o = D_800FFFD8_100BD8[i];
            ow = o->unk_50;
            dx = o->trans.x - (x + D_800F94A0_FA0A0);
            dz = o->trans.z - (z + D_80101308_101F08);
            d = func_800B1830_B2430(dx * dx + dz * dz) - (w->unk_48 + ow->unk_48);
            if (d < 0.0f && w->unk_38 == 1000.0f && ow->unk_38 == 1000.0f) {
                func_80009684_A284(dx, dz, d);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80001468_2068);
#endif

/* Ground objects with a primitive shape (GroundWork.unk_06 8/0x10/0x20/0x40) or a face list push
   the actor out; each new contact point (D_800FD8C8_FE4C8) is moved to world space. Retail adds
   the z push to the probe's y (not z) before the primitive tests. */
void func_800015D4_21D4(omObjData* obj, Vec4f* p) {
    ColActorWork* w = obj->unk_50;
    Vec4f base;
    Vec4f probe;
    Vec3f save;
    s16 i;
    omObjData* g;
    GroundWork* gw;
    s16 prev;

    base.x = p->x;
    base.y = w->unk_34 / 2.0f + p->y;
    base.z = p->z;
    base.w = p->w;
    D_800BF796_C0396 = 0;
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        g = D_800FC7B0_FD3B0[i];
        gw = g->unk_50;
        if (gw->unk_06 & 2) {
            continue;
        }
        if (w->unk_00[i] & 1) {
            continue;
        }
        prev = D_800BF796_C0396;
        probe.x = save.x = p->x;
        probe.y = save.y = w->unk_34 / 2.0f + p->y;
        probe.z = save.z = p->z;
        probe.w = base.w = p->w;
        func_8000D434_E034(D_800FC838_FD438, D_800F94C8_FA0C8, (Vec3f*)&probe, g);
        if ((gw->unk_06 & 4) &&
            func_8000DB30_E730(D_800FC834_FD434[*g->model].hmf->unk64, (Vec3f*)&probe, w->unk_48) == 0) {
            continue;
        }
        if (gw->unk_06 & 8) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_80005D60_6960(g, &probe);
        } else if (gw->unk_06 & 0x10) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800066BC_72BC(g, &probe, w->unk_34 / 2.0f);
        } else if (gw->unk_06 & 0x20) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800061E4_6DE4(g, &probe);
        } else if (gw->unk_06 & 0x40) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800062F0_6EF0(g, &probe, w->unk_34 / 2.0f);
        } else {
            func_8002F2C4_2FEC4(*D_800FC7B0_FD3B0[i]->model, D_800F9D30_FA930, func_80005700_6300, &probe);
        }
        if (prev != D_800BF796_C0396) {
            func_8000D6D0_E2D0(D_800FC838_FD438, &D_800FD8C8_FE4C8[prev]);
        }
    }
    func_80001964_2564(obj);
}

void func_80001964_2564(omObjData* obj) {
    ColActorWork* w;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    f32 d;

    if (D_800BF796_C0396 != 0) {
        w = obj->unk_50;
        if (w->unk_84[5] == NULL || w->unk_84[5](obj) != 1) {
            a.x = D_800FD8C8_FE4C8[0].x;
            a.y = b.y = 0.0f;
            a.z = D_800FD8C8_FE4C8[0].z;
            b.x = HuMathSin(w->unk_3C + 180.0f);
            b.z = func_800B7890_B8490(w->unk_3C + 180.0f);
            d = func_800B3500_B4100(&a, &b);
            a.x *= d;
            a.z *= d;
            HuVecSubtract(&c, &a, &b);
            HuVecAdd(&c, &a, &c);
            w->unk_3C = func_800B75A8_B81A8(c.x, c.z);
            w->unk_40 *= 0.8f;
        }
    }
}

/* Lifetime: the last 45 frames blink the model, then the actor is switched off. */
void func_80001A98_2698(omObjData* obj) {
    ColActorWork* w = obj->unk_50;
    s32 left;

    w->unk_78++;
    if (w->unk_84[7] == NULL || w->unk_84[7](obj) != 1) {
        if (w->unk_7C > 0) {
            left = w->unk_7C - w->unk_78;
            if (left < 45) {
                switch (left & 2) {
                    case 0:
                        func_800298A4_2A4A4(obj->model[0], 4, 4);
                        break;
                    case 2:
                        func_800298A4_2A4A4(obj->model[0], 4, 0);
                        break;
                }
                if (w->unk_7C <= w->unk_78) {
                    w->unk_54 = 0;
                    func_800298A4_2A4A4(obj->model[0], 4, 4);
                    func_800298A4_2A4A4(obj->model[1], 4, 4);
                }
            }
        }
    }
}

/* A player (obj) touches an item actor: coins of kinds 3-6 pay 1, 3, 2, 5. */
void func_80001B84_2784(omObjData* obj, omObjData* actor) {
    ColActorWork* aw = actor->unk_50;
    MgWork* w = obj->unk_50;
    u8 slot;
    u8 mdl;

    if (aw->unk_84[8] == NULL || aw->unk_84[8](obj, actor) != 1) {
        slot = aw->unk_24;
        mdl = actor->model[3];
        func_800298A4_2A4A4(mdl, 4, 0);
        func_80021198_21D98(slot, 0);
        func_80021160_21D60(slot, 4, 4);
        func_80029714_2A314(mdl, actor->trans.x, actor->trans.y, actor->trans.z);
        func_800297E8_2A3E8(mdl, 5.0f, 5.0f, 5.0f);
        switch (aw->unk_52) {
            case 3:
                gPlayers[w->unk_59].coins_mg += 1;
                PlaySound(9);
                break;
            case 4:
                gPlayers[w->unk_59].coins_mg += 3;
                PlaySound(0xA);
                break;
            case 5:
                gPlayers[w->unk_59].coins_mg += 2;
                PlaySound(0x11);
                break;
            case 6:
                gPlayers[w->unk_59].coins_mg += 5;
                PlaySound(0x15);
                omVibrate(w->unk_59, 2, 3, 10);
                break;
        }
        aw->unk_54 = 0;
        aw->unk_78 = 0;
        func_800298A4_2A4A4(actor->model[0], 4, 4);
        func_800298A4_2A4A4(actor->model[1], 4, 4);
    }
}

// retail keeps 0x299 in s2 and ORs 0x400 at run time (masked 1); same value
#ifdef NON_MATCHING
void func_80001DE0_29E0(omObjData* obj, s32 kind) {
    ColActorWork* w;
    s16 shadow = 0x299;
    s32 i;

    obj->unk_50 = func_80027154_27D54(sizeof(ColActorWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(ColActorWork));
    w = obj->unk_50;
    w->unk_A8 = func_80027154_27D54(4, 0x7918);
    if (kind == 3) {
        func_8000C11C_CD1C(obj, 0xE, 0x689, 8);
        func_8000C2A0_CEA0(obj, 3, 0x14, shadow | 0x400, 8);
        func_800211E8_21DE8(w->unk_24, 0xF0);
        func_80021250_21E50(w->unk_24, 0xFF, 0xFF, 0x86);
    }
    if (D_800BF799_C0399 == 0) {
        obj->model[1] = func_80018A64_19664(1, shadow);
    } else {
        obj->model[1] = func_80018A64_19664(0xD, shadow);
    }
    w->unk_44 = 0.0f;
    w->unk_48 = 20.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_78 = 0;
    w->unk_52 = kind;
    w->unk_7C = 300;
    w->unk_50 = 0;
    w->unk_40 = 0.0f;
    func_8000C37C_CF7C(obj, 2.0f, 2.0f, 2.0f);
    for (i = 0; i < 9; i++) {
        w->unk_84[i] = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80001DE0_29E0);
#endif

/* Launch an item actor from a player: it takes the player's heading and speed (at least
   D_800BF7C0_C03C0) and starts on top of the player. */
// register allocation (masked 0): s2/s3 swapped
#ifdef NON_MATCHING
void func_80001F44_2B44(omObjData* obj, omObjData* actor) {
    MgWork* w;
    ColActorWork* aw;

    aw = actor->unk_50;
    w = obj->unk_50;

    if (aw->unk_84[6] == NULL || aw->unk_84[6](obj, actor) != 1) {
        aw->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
        aw->unk_3C = w->unk_3C;
        aw->unk_40 = w->unk_40;
        if (aw->unk_40 < D_800BF7C0_C03C0) {
            aw->unk_40 = D_800BF7C0_C03C0;
        }
        aw->unk_80 = 0;
        actor->trans.x = obj->trans.x;
        actor->trans.y = w->unk_34 + aw->unk_48 + obj->trans.y;
        actor->trans.z = obj->trans.z;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80001F44_2B44);
#endif

void func_80002024_2C24(ColActorWork* w, s32 slot, s32 (*fn)()) {
    if (slot < 9) {
        w->unk_84[slot] = fn;
    }
}

/* Height of a primitive ground object under a player; a ceiling (unk_14 - unk_98) within the
   player's height is recorded in w->unk_8C / unk_56. */
f32 func_80002040_2C40(omObjData* g, MgWork* w, f32 y) {
    GroundWork* gw = g->unk_50;
    Vec3f v;
    f32 c;

    if (gw->unk_06 & 0x50) {
        c = gw->unk_14 - gw->unk_98;
        if ((c < y + w->unk_34) & (y < c)) {
            v.x = 0.0f;
            v.y = c;
            v.z = 0.0f;
            if (g->trans.x != v.x || g->trans.y != v.x || g->trans.z != v.x || g->rot.x != v.x ||
                g->rot.y != v.x || g->rot.z != v.x) {
                func_8000D7E0_E3E0(D_800FC838_FD438, &v);
            }
            w->unk_8C = v.y;
            w->unk_56 = gw->unk_04;
        }
    }
    return gw->unk_14;
}

/* A face height h under a player: a downward-facing face (n->y < 0) within the player's height
   is a ceiling instead (w->unk_8C), and the floor result is -65536.0f. */
f32 func_80002178_2D78(omObjData* g, MgWork* w, f32 h, f32 y, Vec3f* n) {
    GroundWork* gw = g->unk_50;
    Vec3f v;

    if ((h < y + w->unk_34) & (y < h)) {
        if (n->y < 0.0f) {
            v.x = 0.0f;
            v.y = h;
            v.z = 0.0f;
            w->unk_8C = h;
            w->unk_56 = gw->unk_04;
            return -65536.0f;
        }
    }
    return h;
}

f32 func_80002218_2E18(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri, Vec3f* dir, Vec3f* out) {
    Vec3f n;
    f32 vx, vy, vz;
    f32 dx, dy, dz;
    f32 t;
    f32 d;
    f32 nx, ny, nz;
    ColVtx* v = &verts[tri->v[0]];

    vx = v->x;
    vy = v->y;
    vz = v->z;
    dx = dir->x;
    dy = dir->y;
    dz = dir->z;
    func_8002DA3C_2E63C(v, &verts[tri->v[1]], &verts[tri->v[2]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    d = nx * dx + ny * dy + nz * dz;
    t = (nx * (vx - x) + ny * (vy - y) + nz * (vz - z)) / d;
    x += dx * t;
    out->x = x;
    y += dy * t;
    out->y = y;
    z += dz * t;
    out->z = z;
    return y;
}

/* Highest floor of the ground objects under a player at (x, y, z), skipping D_800BF794_C0394;
   n receives its normal. A downward face or a primitive's underside within the player's height
   is recorded as a ceiling (func_80002040_2C40, func_80002178_2D78). */
f32 func_800023CC_2FCC(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* n) {
    Vec4f q;
    Vec3f a;
    Vec3f d;
    MgWork* w = obj->unk_50;
    f32 best = -65536.0f;
    s16 i;
    omObjData* g;
    GroundWork* gw;
    f32 h;
    s16 mdl;
    ColVtx* verts;
    ColTri* tri;
    u8 moved;

    q.w = 10.0f;
    w->unk_53 = -1;
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        g = D_800FC7B0_FD3B0[i];
        gw = g->unk_50;
        if (i == D_800BF794_C0394) {
            continue;
        }
        if (w->unk_00[i] & 1) {
            continue;
        }
        q.x = x;
        q.y = y;
        q.z = z;
        func_8000D434_E034(D_800FC838_FD438, D_800F94C8_FA0C8, (Vec3f*)&q, g);
        if ((gw->unk_06 & 4) && func_8000DA98_E698(D_800FC834_FD434[*g->model].hmf->unk64, (Vec3f*)&q) == 0) {
            continue;
        }
        if (gw->unk_06 & 0x7A) {
            if ((gw->unk_06 & 0x50) && func_8000DC10_E810((Vec3f*)&q, gw) == 0) {
                continue;
            }
            h = func_80002040_2C40(g, w, q.y);
            if (g->trans.x != 0.0f || g->trans.y != 0.0f || g->trans.z != 0.0f || g->rot.x != 0.0f ||
                g->rot.y != 0.0f || g->rot.z != 0.0f) {
                q.y = h;
                func_8000D7E0_E3E0(D_800FC838_FD438, (Vec3f*)&q);
                if (best <= q.y && q.y < y + 150.0f) {
                    best = q.y;
                    w->unk_53 = D_800BF798_C0398 = i;
                    if (n != NULL) {
                        n->z = n->x = 0.0f;
                        n->y = 1.0f;
                        func_8000D6D0_E2D0(D_800FC838_FD438, n);
                        func_8002D9AC_2E5AC(n);
                    }
                }
            } else if (best <= h && h < y + 150.0f) {
                best = h;
                D_800BF798_C0398 = i;
                w->unk_53 = i;
                if (n != NULL) {
                    n->x = 0.0f;
                    n->y = 1.0f;
                    n->z = 0.0f;
                }
            }
        } else {
            mdl = *g->model;
            verts = D_800FC834_FD434[mdl].hmf->unk54;
            func_8002F2C4_2FEC4(mdl, D_800F9D30_FA930, func_80005110_5D10, &q);
            goto next;
            do {
                moved = 0;
                if (g->trans.x != 0.0f || g->trans.y != 0.0f || g->trans.z != 0.0f || g->rot.x != 0.0f ||
                    g->rot.y != 0.0f || g->rot.z != 0.0f) {
                    a.x = x;
                    a.y = y + 101.23f;
                    a.z = z;
                    func_8000D74C_E34C(D_800F94C8_FA0C8, &a);
                    d.x = a.x - q.x;
                    d.y = a.y - q.y;
                    d.z = a.z - q.z;
                    func_8002D9AC_2E5AC(&d);
                    func_80002218_2E18(q.x, q.y, q.z, verts, tri, &d, (Vec3f*)&q);
                    func_8000D7E0_E3E0(D_800FC838_FD438, (Vec3f*)&q);
                    func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &d);
                    func_8000D6D0_E2D0(D_800FC838_FD438, &d);
                    h = func_80002178_2D78(g, w, q.y, y, &d);
                    moved = 1;
                } else {
                    h = func_8002DBA4_2E7A4(q.x, q.y, q.z, verts, tri);
                }
                if (best <= h && h < y + 150.0f) {
                    best = h;
                    D_800BF798_C0398 = i;
                    w->unk_53 = i;
                    if (n != NULL) {
                        func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], n);
                        if (moved == 1) {
                            a.x = n->x;
                            a.y = n->y;
                            a.z = n->z;
                            func_8000D6D0_E2D0(D_800FC838_FD438, &a);
                            n->x = a.x;
                            n->y = a.y;
                            n->z = a.z;
                            func_8002D9AC_2E5AC(n);
                        }
                    }
                }
            next:;
            } while ((tri = func_8002F848_30448(D_800F9D30_FA930)) != NULL);
        }
    }
    return best;
}

/* A player's step (MP1 func_80002C48): move along the heading, push out of walls, find the floor
   and the shadow under the new position. Retail never initialises normal (passed to
   func_8000BAF0_C6F0 when nothing was found) and adds the push to x/z twice when
   func_80004168_4D68 returns 2. Host hazard: the uninitialised normal. */
// block layout (masked 36): retail places the floorY == -65536.0f block inline
#ifdef NON_MATCHING
f32 func_80002A28_3628(omObjData* obj, f32 x, f32 y, f32 z) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    MgWork* w;
    GroundWork* gw;
    Vec3f* normal;
    f32 speed;
    f32 sa, sb, sc;
    f32 nx, nz;
    f32 floorY, shadowY;
    f32 h;
    s16 mdl;
    ColVtx* verts;
    ColTri* tri;

    w = obj->unk_50;
    w->unk_53 = w->unk_54 = -1;
    w->unk_8C = 65536.0f;
    sa = w->unk_40;
    sb = w->unk_4C;
    sc = w->unk_B4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sb;
    } else {
        speed = sa * sb;
    }
    speed *= sc;
    nx = x + HuMathSin(w->unk_3C) * speed + D_800F94A0_FA0A0;
    nz = z + func_800B7890_B8490(w->unk_3C) * speed + D_80101308_101F08;
    shadowY = floorY = -65536.0f;
    if (func_80004168_4D68(obj, nx, y, nz) != 2) {
        func_80005034_5C34(obj);
        sa = w->unk_40;
        sb = w->unk_4C;
        sc = w->unk_B4;
        if (w->unk_50 & 6) {
            speed = sa * 0.6f * sb;
        } else {
            speed = sa * sb;
        }
        speed *= sc;
        nx = x + HuMathSin(w->unk_3C) * speed;
        nz = z + func_800B7890_B8490(w->unk_3C) * speed;
        probe.x = nx;
        probe.y = y;
        probe.z = nz;
        probe.w = w->unk_48;
        func_80006F34_7B34(obj, &probe, 0);
        func_80005034_5C34(obj);
        probe.x = nx + D_800F94A0_FA0A0;
        probe.y = y;
        probe.z = nz + D_80101308_101F08;
        if (!(w->unk_00[D_800BF794_C0394] & 1)) {
            gw = D_800FC7B0_FD3B0[D_800BF794_C0394]->unk_50;
            if (gw->unk_06 & 0x7A) {
                if (func_8000DC10_E810((Vec3f*)&probe, gw) == 1) {
                    h = gw->unk_14;
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800BF798_C0398 = D_800BF794_C0394;
                        if (shadowY < floorY && shadowY < y + 35.0f) {
                            shadowY = floorY;
                            n.x = 0.0f;
                            n.y = 1.0f;
                            n.z = 0.0f;
                            normal = &n;
                        }
                    }
                }
            } else {
                mdl = *D_800FC7B0_FD3B0[D_800BF794_C0394]->model;
                verts = D_800FC834_FD434[mdl].hmf->unk54;
                func_8002F2C4_2FEC4(mdl, D_800F9D30_FA930, func_80005110_5D10, &probe);
                for (tri = func_8002F848_30448(D_800F9D30_FA930); tri != NULL; tri = func_8002F848_30448(D_800F9D30_FA930)) {
                    h = func_8002DBA4_2E7A4(nx + D_800F94A0_FA0A0, y, nz + D_80101308_101F08, verts, tri);
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800BF798_C0398 = D_800BF794_C0394;
                    }
                    if (shadowY < h && shadowY < y + 35.0f) {
                        shadowY = h;
                        func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
                        normal = &n;
                    }
                }
                if (floorY == -65536.0f) {
                    floorY = -65536.0f;
                }
            }
        }
        h = func_800023CC_2FCC(obj, nx + D_800F94A0_FA0A0, y, nz + D_80101308_101F08, &n2);
        if (floorY < h && h < y + 150.0f) {
            floorY = h;
        } else {
            w->unk_53 = -1;
        }
        if (shadowY < h && h < y + 150.0f) {
            shadowY = h;
            normal = &n2;
        }
        if (floorY == -65536.0f) {
            shadowY = -65536.0f;
            w->unk_4C = D_800BF7D8_C03D8;
            if (w->unk_38 < 0.0f) {
                w->unk_38 = 0.0f;
            }
        } else if (y < floorY) {
            w->unk_53 = D_800BF798_C0398;
            y = func_80003910_4510(obj, floorY);
            w->unk_38 = 1000.0f;
            w->unk_50 &= ~8;
            if (w->unk_00[(s8)D_800BF798_C0398] & 8) {
                func_8000C398_CF98();
            }
            goto done;
        }
        w->unk_53 = -1;
        if (w->unk_8C != 65536.0f) {
            y = w->unk_8C - w->unk_34;
            func_8000BA38_C638(obj, y);
        }
    done:;
    } else {
        probe.x = nx + D_800F94A0_FA0A0;
        probe.y = y;
        probe.z = nz + D_80101308_101F08;
        probe.w = w->unk_48;
        func_80006F34_7B34(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        func_8000BAF0_C6F0(obj, nx, y, nz, shadowY, normal);
    }
    obj->rot.x = obj->rot.z = w->unk_9C = w->unk_A4 = w->unk_90 = w->unk_94 = w->unk_98 = 0.0f;
    return y;
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80002A28_3628);
#endif

/* A player's step with the ground's conveyor push (MP1 func_80002C48): move along rot, push out of
   walls, land on the floor within 35 units or start falling (returns 65536.0f). */
f32 func_8000312C_3D2C(omObjData* obj, f32 rot, f32 x, f32 y, f32 z) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    MgWork* w;
    GroundWork* gw;
    GroundWork* cur;
    ColVtx* verts;
    ColTri* tri;
    s16 mdl;
    Vec3f* normal;
    s32 ground;
    f32 speed;
    f32 sa, sb;
    f32 floorY, shadowY;
    f32 h;
    f32 nx, nz;

    ground = -1;
    w = obj->unk_50;
    w->unk_54 = ground;
    w->unk_53 = ground;
    w->unk_8C = 65536.0f;
    normal = NULL;
    sa = w->unk_40;
    sb = w->unk_B4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sb;
    } else {
        speed = sa * sb;
    }
    if (fabs(w->unk_90) > 1.0) {
        D_800F94A0_FA0A0 += w->unk_90;
    }
    if (fabs(w->unk_98) > 1.0) {
        D_80101308_101F08 += w->unk_98;
    }
    nx = x + HuMathSin(rot) * speed + D_800F94A0_FA0A0;
    nz = z + func_800B7890_B8490(rot) * speed + D_80101308_101F08;
    shadowY = floorY = -65536.0f;
    if (func_80004168_4D68(obj, nx, y, nz) != 2) {
        func_80005034_5C34(obj);
        sa = w->unk_40;
        sb = w->unk_B4;
        if (w->unk_50 & 6) {
            speed = sa * 0.6f * sb;
        } else {
            speed = sa * sb;
        }
        nx = x + HuMathSin(rot) * speed;
        nz = z + func_800B7890_B8490(rot) * speed;
        probe.x = nx + D_800F94A0_FA0A0;
        probe.y = y;
        probe.z = nz + D_80101308_101F08;
        probe.w = w->unk_48;
        func_80006F34_7B34(obj, &probe, 0);
        func_80005034_5C34(obj);
        probe.x = nx + D_800F94A0_FA0A0;
        probe.y = y;
        probe.z = nz + D_80101308_101F08;
        if (!(w->unk_00[D_800BF794_C0394] & 1)) {
            gw = D_800FC7B0_FD3B0[D_800BF794_C0394]->unk_50;
            if (gw->unk_06 & 0x7A) {
                if (func_8000DC10_E810((Vec3f*)&probe, gw) == 1) {
                    h = gw->unk_14;
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        ground = D_800BF794_C0394;
                        if (shadowY < floorY && shadowY < y + 35.0f) {
                            shadowY = floorY;
                            n.x = 0.0f;
                            n.y = 1.0f;
                            n.z = 0.0f;
                            normal = &n;
                        }
                    }
                }
            } else {
                mdl = *D_800FC7B0_FD3B0[D_800BF794_C0394]->model;
                verts = D_800FC834_FD434[mdl].hmf->unk54;
                func_8002F2C4_2FEC4(mdl, D_800F9D30_FA930, func_80005110_5D10, &probe);
                for (tri = func_8002F848_30448(D_800F9D30_FA930); tri != NULL; tri = func_8002F848_30448(D_800F9D30_FA930)) {
                    h = func_8002DBA4_2E7A4(nx, y, nz, verts, tri);
                    if (floorY < h) {
                        floorY = h;
                        ground = D_800BF794_C0394;
                    }
                    if (shadowY < h && shadowY < y + 35.0f) {
                        shadowY = h;
                        func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
                        normal = &n;
                    }
                }
                if (floorY == -65536.0f) {
                    floorY = -65536.0f;
                }
            }
        }
        h = func_800023CC_2FCC(obj, nx + D_800F94A0_FA0A0, y, nz + D_80101308_101F08, &n2);
        if (floorY < h && h < y + 35.0f) {
            ground = D_800BF798_C0398;
            floorY = h;
        } else {
            if (h < y + 150.0f && y + 35.0f < h) {
                floorY = 65536.0f;
            }
            w->unk_53 = -1;
        }
        if (shadowY < h && h < y + 35.0f) {
            shadowY = h;
            normal = &n2;
        }
        if (y - 35.0f < floorY && floorY < y + 35.0f) {
            if ((s8)ground != -1) {
                w->unk_53 = ground;
            }
            y = func_80003910_4510(obj, floorY);
            if (w->unk_00[(s8)ground] & 8) {
                func_8000C398_CF98();
            }
            w->unk_38 = 1000.0f;
            if (w->unk_8C != 65536.0f) {
                func_8000BA38_C638(obj, y);
            }
        } else {
            func_80019B9C_1A79C(obj, 6);
            w->unk_38 = D_800BF7DC_C03DC;
            w->unk_53 = -1;
            func_8000C584_D184(w, 13);
            return 65536.0f;
        }
    } else {
        probe.x = nx + D_800F94A0_FA0A0;
        probe.y = y;
        probe.z = nz + D_80101308_101F08;
        probe.w = w->unk_48;
        func_80006F34_7B34(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        func_8000BAF0_C6F0(obj, nx, y, nz, shadowY, normal);
    }
    if (w->unk_53 >= 0) {
        cur = D_800FC7B0_FD3B0[w->unk_53]->unk_50;
        w->unk_90 = normal->x * cur->unk_10;
        w->unk_94 = normal->y;
        w->unk_98 = normal->z * cur->unk_10;
        if (cur->unk_06 & 0x400) {
            func_8000755C_815C(obj, normal);
        }
    } else {
        obj->rot.x = obj->rot.z = w->unk_9C = w->unk_A4 = w->unk_90 = w->unk_94 = w->unk_98 = 0.0f;
    }
    return y;
}

f32 func_80003910_4510(omObjData* obj, f32 y) {
    u8* w = obj->unk_50;
    f32 r = obj->trans.y;

    if (w[w[0x53]] & 2) {
        r = y;
    }
    return r;
}

s32 func_8000393C_453C(Vec3f* pos, ColTri* tri, ColVtx* verts) {
    Vec3f n;
    ColVtx* v;
    f32 vx, vy, vz;
    f32 dx, dy, dz;
    s32 ret;

    func_8002DA3C_2E63C(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
    v = &verts[tri->v[0]];
    vx = v->x;
    vy = v->y;
    vz = v->z;
    dx = vx - pos->x;
    dy = vy - pos->y;
    dz = vz - pos->z;
    ret = 1;
    if (dx * n.x + dy * n.y + dz * n.z < 0.0f) {
        ret = -1;
    }
    return ret;
}

s32 func_80003A54_4654(Vec4f* s, s16* tri, ColVtx* verts) {
    s32 side = -1;
    Vec3f n;
    ColVtx* v;
    f32 dx, dy, dz;
    f32 vx, vy, vz;
    f32 d;
    f32 t;

    if ((tri[0] & 0x3F00) <= 0x200) {
        return 0;
    }
    func_8002DA3C_2E63C(&verts[tri[1]], &verts[tri[2]], &verts[tri[3]], &n);
    v = &verts[tri[1]];
    vx = v->x;
    vy = dx = v->y; // dx is reassigned below; the extra copy (decomp-permuter) reproduces retail's registers
    vz = v->z;
    dx = vx - s->x;
    dy = vy - s->y;
    dz = vz - s->z;
    d = dx * n.x + dy * n.y + dz * n.z;
    if (d >= 0.0f) {
        side = 1;
    }
    if (fabsf(d) > s->w) {
        return 0;
    }
    t = dx * n.x + dy * n.y + dz * n.z;
    s->x += t * n.x;
    s->y += t * n.y;
    s->z += t * n.z;
    return side;
}

f32 func_80003C04_4804(f32 x, f32 y, f32 z, ColVtx* a, ColVtx* b, Vec3f* n) {
    f32 ax = a->x - x;
    f32 ay = a->y - y;
    f32 az = a->z - z;
    f32 bx = b->x - x;
    f32 by = b->y - y;
    f32 bz = b->z - z;

    return (ay * bz - az * by) * n->x + (az * bx - ax * bz) * n->y + (ax * by - ay * bx) * n->z;
}

s32 func_80003CE0_48E0(Vec3f* p, s16* idx, ColVtx* verts, Vec3f* n) {
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;
    s32 cnt = ((u16)*idx >> 14) + 2;
    s32 i;
    s32 j;

    idx++;
    if (func_80003C04_4804(x, y, z, &verts[idx[0]], &verts[idx[1]], n) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_80003C04_4804(x, y, z, &verts[idx[i]], &verts[idx[j]], n) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_80003C04_4804(x, y, z, &verts[idx[i]], &verts[idx[j]], n) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_80003F40_4B40(Vec3f* p, ColTri* tri, ColVtx* verts) {
    f32 x, z;
    s32 cnt;
    s16* idx;
    s32 i;
    s32 j;

    idx = (s16*)tri;
    if (((u16)*idx & 0x3F00) > 0x200) {
        return 0;
    }
    x = p->x;
    z = p->z;
    cnt = ((u16)*idx >> 14) + 2;
    idx++;
    if (func_8002DB3C_2E73C(x, z, &verts[idx[0]], &verts[idx[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[idx[i]], &verts[idx[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_8002DB3C_2E73C(x, z, &verts[idx[i]], &verts[idx[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

/* func_80004168_4D68 .. func_8000776C_836C (wave H2 fork F) */
s32 func_8001B434_1C034(f32 tri[3][3], Vec3f* pos, f32 r, Vec3f* hit);  /* sphere against a triangle (MP1 func_80019964) */
s32 func_8001B9AC_1C5AC(f32 quad[4][3], Vec3f* pos, f32 r, Vec3f* hit); /* sphere against a quad (MP1 func_80019EDC) */
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
void func_80009DB0_A9B0(f32 nx, f32 ny, f32 nz); /* add a contact normal (normalised) */
void func_80009E0C_AA0C(f32 x, f32 y, f32 z);    /* add a contact point */
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7CC_C03CC;
extern Vec3f D_800D5760_D6360;   /* reference point for the face-side test (func_8000776C_836C) */
extern Vec3f D_800F9D40_FA940[]; /* contact points; D_800FD8C8_FE4C8[] holds their normals */
extern s8 D_800FD7F4_FE3F4;      /* surface id of the last ground object touched, -1 none */
s32 func_8000C098_CC98(s8 id);
/* 1130's rodata past fork A's carve, still in the data blob (G carves the tail) */
extern f64 D_800D1770_D2370; /* 0.2 */
extern f64 D_800D1778_D2378; /* 0.5 */
extern f64 D_800D1780_D2380; /* 2.0 */
extern f64 D_800D1788_D2388; /* 0.3 */
extern f64 D_800D1790_D2390; /* 2.0 */
extern f64 D_800D1798_D2398; /* 0.3 */
extern u8 D_800BF795_C0395;
extern f32 D_800BF7C8_C03C8;
extern omObjData* D_800F9CE0_FA8E0[]; /* minigame actors (ColActorWork) */
extern u16 D_800FA606_FB206;          /* their count */
extern u16 D_800FD7FC_FE3FC;          /* actor touches while MgWork.unk_BE is set (MP1 D_800F370C) */
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80019B28_1A728(omObjData* obj, u8 flags);
void func_8000C610_D210(MgWork* work, s32 arg1);
void func_8000D81C_E41C(omObjData* obj, f32 arg1);
void func_8000DCD4_E8D4(omObjData* obj, f32 dx, f32 dz);
void func_8000E030_EC30(omObjData* a, omObjData* b);
s32 func_80005130_5D30(void* arg0, s16* idx, ColVtx* verts, ColSphere* s);
s32 func_80006440_7040(Vec4f* s, GroundWork* g);
void func_80006BF8_77F8(omObjData* obj, ColSphere* s, f32 arg2);

/* The player's step against the minigame actors (D_800F9CE0_FA8E0: hazards, bouncing actors, coins)
   and the other players (D_800FFFD8_100BD8). Returns 2 when the player stomped or bumped another
   player, else 0 (MP1 func_80000F3C). */
// register allocation (masked 19): the first loop's dy/dz and 0.0f swap $f22/$f26/$f30, and the
// last push's delay slot is filled differently (one instruction short); same logic
#ifdef NON_MATCHING
s32 func_80004168_4D68(omObjData* obj, f32 x, f32 y, f32 z) {
    MgWork* w = obj->unk_50;
    f32 radius = w->unk_48;
    f32 speed = w->unk_40;
    f32 py;
    omObjData* o;
    ColActorWork* ow;
    MgWork* ow2;
    f32 dx, dy, dz;
    f32 dist, flat;
    f32 dxx, dzz;
    f32 a;
    f32 dz2;
    u16 i;

    if (w->unk_50 & 6) {
        speed *= 0.6f;
    }
    speed *= (w->unk_38 != 1000.0f) ? w->unk_4C * w->unk_B4 : w->unk_B4;
    x += HuMathSin(w->unk_3C) * speed;
    z += func_800B7890_B8490(w->unk_3C) * speed;
    w->unk_F0 = 0;

    for (i = 0; i < D_800FA606_FB206; i++) {
        o = D_800F9CE0_FA8E0[i];
        ow = o->unk_50;
        if (ow->unk_54 == 0) {
            continue;
        }
        dx = o->trans.x - (x + D_800F94A0_FA0A0);
        dy = o->trans.y - y;
        dz = o->trans.z - (z + D_80101308_101F08);
        flat = 100.0f;
        if (ow->unk_34 != 0.0f && o->trans.y <= y && y <= o->trans.y + ow->unk_34) {
            flat = func_800B1830_B2430(dx * dx + dz * dz) - (radius + ow->unk_48);
        }
        dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz) - (radius + ow->unk_48);
        if ((dist < 0.0f) | (flat < 0.0f)) {
            if (w->unk_EC != NULL && w->unk_EC(obj, o) == 1) {
                continue;
            }
            if (ow->unk_52 == 7) {
                if (w->unk_BE != 0) {
                    D_800FD7FC_FE3FC++;
                    continue;
                }
                if (w->unk_50 & 0x200) {
                    continue;
                }
                a = func_8000DA2C_E62C(HuMathSin(w->unk_3C), func_800B7890_B8490(w->unk_3C), dx, dz);
                if (w->unk_50 & 0x10) {
                    func_8000D81C_E41C(obj, D_800BF7C8_C03C8);
                }
                if (a > 0.0f) {
                    func_80019B9C_1A79C(obj, 9);
                    w->unk_40 = -D_800BF7C0_C03C0;
                } else {
                    func_80019B9C_1A79C(obj, 10);
                    w->unk_40 = D_800BF7C0_C03C0;
                }
                w->unk_38 = -D_800BF7A4_C03A4 * 0.7f;
                w->unk_BE = 105;
                func_800191D4_19DD4(obj, 5, o->trans.x, y, o->trans.z, 0.0f, func_800B75A8_B81A8(dx, dz) + 180.0f);
                func_8000C584_D184(w, 8);
                omVibrate(w->unk_59, 20, 0, 20);
            } else if (ow->unk_50 & 0x20) {
                if (!(ow->unk_50 & 0x10)) {
                    dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz) - (ow->unk_48 + w->unk_48);
                    if (dist < 0.0f) {
                        if (ow->unk_38 < 1000.0f) {
                            ow->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
                            if (func_8000DA2C_E62C(HuMathSin(ow->unk_3C), func_800B7890_B8490(ow->unk_3C), dx, dz) < 0.0f) {
                                ow->unk_40 = -D_800BF7CC_C03CC;
                            } else {
                                ow->unk_40 = D_800BF7CC_C03CC;
                            }
                        } else if (ow->unk_40 == D_800BF7D0_C03D0) {
                            if (w->unk_38 != 1000.0f) {
                                func_8000DCD4_E8D4(obj, dx, dz);
                                func_8000C610_D210(w, 9);
                            } else {
                                if ((dx == 0.0f) & (dz == 0.0f)) {
                                    dx = HuMathSin(w->unk_3C);
                                    dz = func_800B7890_B8490(w->unk_3C);
                                }
                                func_80009684_A284(dx, dz, dist);
                            }
                        } else {
                            ow->unk_40 = -ow->unk_40;
                        }
                    }
                }
            } else if (w->unk_BE != 0) {
                D_800FD7FC_FE3FC++;
            } else {
                func_80001B84_2784(obj, o);
            }
        }
    }

    py = y + w->unk_48;
    if (w->unk_50 & 0x400) {
        return 0;
    }
    for (i = 0; i < D_800FC87A_FD47A; i++) {
        o = D_800FFFD8_100BD8[i];
        ow2 = o->unk_50;
        if (w == ow2) {
            continue;
        }
        dx = o->trans.x - (x + D_800F94A0_FA0A0);
        dy = (o->trans.y + ow2->unk_48) - py;
        dz2 = o->trans.z - (z + D_80101308_101F08);
        if (ow2->unk_50 & 0x400) {
            continue;
        }
        dxx = dx * dx;
        dzz = dz2 * dz2;
        dist = func_800B1830_B2430(dxx + dzz) - (w->unk_48 + ow2->unk_48) * 0.6f;
        flat = func_800B1830_B2430(dxx + dy * dy + dzz) - (ow2->unk_48 + w->unk_48);
        if (((dist < 0.0f) | (flat < 0.0f)) && w->unk_38 != 1000.0f && !(w->unk_50 & 0x8000)) {
            if (py - (ow2->unk_34 + ow2->unk_48) <= o->trans.y && o->trans.y <= (py - w->unk_48) + w->unk_34) {
                if (!(ow2->unk_50 & 7) && w->unk_BE == 0 && ow2->unk_BE == 0) {
                    if (ow2->unk_38 != 1000.0f) {
                        if (w->unk_5C & 0x200) {
                            if (!(dist < 0.0f && dy < -w->unk_34 * 0.5f)) {
                                goto block_93;
                            }
                            func_800191D4_19DD4(obj, 7, x, py, z, 0.0f, 0.0f);
                            if (!(ow2->unk_50 & 0x200)) {
                                func_80019B28_1A728(o, 1);
                                func_80019B9C_1A79C(o, 0x1E);
                                if (ow2->unk_50 & 0x10) {
                                    func_8000D81C_E41C(o, D_800BF7CC_C03CC);
                                }
                            }
                            ow2->unk_38 = w->unk_38;
                            goto block_104;
                        block_93:
                            if (D_800BF795_C0395 != 1) {
                                goto block_78;
                            }
                            func_8000E030_EC30(obj, o);
                            return 0;
                        }
                        if (!(dist < 0.0f && dy < -w->unk_34 * D_800D1770_D2370)) {
                            goto block_93;
                        }
                        if (!(ow2->unk_50 & 0x200)) {
                            func_800191D4_19DD4(obj, 6, x, py, z, -90.0f, 0.0f);
                            func_80019B28_1A728(o, 2);
                            if (ow2->unk_50 & 0x10) {
                                func_8000D81C_E41C(o, D_800BF7CC_C03CC);
                            }
                        }
                        if (ow2->unk_38 < 0.0f) {
                            ow2->unk_38 = 0.0f;
                        }
                    block_104:
                        ow2->unk_40 = D_800BF7D0_C03D0;
                        func_8000DCD4_E8D4(obj, dx, dz2);
                        func_8000C610_D210(w, 9);
                        goto block_105;
                    block_78:
                        func_80009684_A284(dx, dz2, func_800B1830_B2430(dx * dx + dz2 * dz2) - (ow2->unk_48 + w->unk_48));
                        return 0;
                    block_105:
                        omVibrate(w->unk_59, 2, 3, 10);
                        omVibrate(ow2->unk_59, 2, 3, 10);
                        return 2;
                    }
                    if ((dist < 0.0f) & (dy < 0.0f)) {
                        if (!(ow2->unk_50 & 0x200)) {
                            if (w->unk_5C & 0x200) {
                                func_80019B28_1A728(o, 1);
                                func_80019B9C_1A79C(o, 0);
                                func_800191D4_19DD4(obj, 7, x, py, z, 0.0f, 0.0f);
                            } else {
                                func_800191D4_19DD4(obj, 6, x, py, z, -90.0f, 0.0f);
                                func_80019B28_1A728(o, 2);
                            }
                            if (ow2->unk_50 & 0x10) {
                                func_8000D81C_E41C(o, D_800BF7CC_C03CC);
                            }
                        }
                        func_8000DCD4_E8D4(obj, dx, dz2);
                        func_8000C610_D210(w, 9);
                        omVibrate(w->unk_59, 2, 3, 10);
                        omVibrate(ow2->unk_59, 20, 0, 20);
                        return 2;
                    }
                    func_8000DCD4_E8D4(obj, dx, dz2);
                    w->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
                    w->unk_40 = w->unk_40 * D_800D1778_D2378;
                    func_8000C610_D210(w, 9);
                    omVibrate(w->unk_59, 2, 3, 10);
                    omVibrate(ow2->unk_59, 20, 0, 20);
                } else if (w->unk_38 != 1000.0f && ow2->unk_38 != 1000.0f) {
                    if (w->unk_BE != 0 || ow2->unk_BE != 0) {
                        if (D_800BF795_C0395 == 1) {
                            func_8000E030_EC30(obj, o);
                            omVibrate(w->unk_59, 2, 3, 10);
                            return 0;
                        }
                        func_80009684_A284(dx, dz2, flat);
                        return 0;
                    }
                } else {
                    if (w->unk_5C & 0x200) {
                        func_800191D4_19DD4(obj, 7, x, py, z, 0.0f, 0.0f);
                    } else {
                        func_800191D4_19DD4(obj, 6, x, py, z, -90.0f, 0.0f);
                    }
                    omVibrate(w->unk_59, 2, 3, 10);
                    func_8000DCD4_E8D4(obj, dx, dz2);
                    func_8000C610_D210(w, 9);
                }
            } else if (flat < 0.0f) {
                if (D_800BF795_C0395 == 1) {
                    func_8000E030_EC30(obj, o);
                } else {
                    func_80009684_A284(dx, dz2, flat);
                }
            }
        } else {
            flat = func_800B1830_B2430(dx * dx + dy * dy + dz2 * dz2) - (ow2->unk_48 + w->unk_48);
            if (flat < 0.0f && (ow2->unk_38 == 1000.0f || w->unk_38 != 1000.0f)) {
                func_80009684_A284(dx, dz2, flat);
                w->unk_54 = i;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80004168_4D68);
#endif

/* Clamp this frame's push: a push longer than the radius is replaced by one opposite the heading. */
void func_80005034_5C34(omObjData* obj) {
    MgWork* w = obj->unk_50;
    f32 r = w->unk_48;
    f32 rot;

    if (r < func_800B1830_B2430(D_800F94A0_FA0A0 * D_800F94A0_FA0A0 + D_80101308_101F08 * D_80101308_101F08) ||
        fabs(D_800F94A0_FA0A0) > r || fabs(D_80101308_101F08) > r) {
        rot = w->unk_3C;
        D_800F94A0_FA0A0 = -HuMathSin(rot) * w->unk_40;
        D_80101308_101F08 = -func_800B7890_B8490(rot) * w->unk_40;
    }
}

s32 func_80005110_5D10(void* arg0, s16* idx, ColVtx* verts, Vec3f* p) {
    return func_80003F40_4B40(p, (ColTri*)(idx - 1), verts);
}

/* Face filter for a face list in world space: push the sphere out of the face, recording the
   contact point and the face normal (MP1 func_80002080). */
s32 func_80005130_5D30(void* arg0, s16* idx, ColVtx* verts, ColSphere* s) {
    Vec4f sph;
    Vec3f pos;
    Vec3f hitPos;
    f32 quad[4][3];
    f32 tri3[3][3];
    Vec3f dir;
    s16* tri;
    s32 side;
    s32 hit;
    f32 pen, dz, dx;

    pos.x = sph.x = s->x + D_800F94A0_FA0A0;
    pos.y = sph.y = s->y;
    pos.z = sph.z = s->z + D_80101308_101F08;
    sph.w = s->r;
    tri = idx - 1;
    side = func_80003A54_4654(&sph, tri, verts);
    if (side == 0) {
        return 0;
    }
    if (((u16)*tri >> 14) + 2 == 4) {
        quad[0][0] = verts[idx[0]].x;
        quad[0][1] = verts[idx[0]].y;
        quad[0][2] = verts[idx[0]].z;
        quad[1][0] = verts[idx[1]].x;
        quad[1][1] = verts[idx[1]].y;
        quad[1][2] = verts[idx[1]].z;
        quad[2][0] = verts[idx[2]].x;
        quad[2][1] = verts[idx[2]].y;
        quad[2][2] = verts[idx[2]].z;
        quad[3][0] = verts[idx[3]].x;
        quad[3][1] = verts[idx[3]].y;
        quad[3][2] = verts[idx[3]].z;
        hit = func_8001B9AC_1C5AC(quad, (Vec3f*)&pos, sph.w, &hitPos);
    } else {
        tri3[0][0] = verts[idx[0]].x;
        tri3[0][1] = verts[idx[0]].y;
        tri3[0][2] = verts[idx[0]].z;
        tri3[1][0] = verts[idx[1]].x;
        tri3[1][1] = verts[idx[1]].y;
        tri3[1][2] = verts[idx[1]].z;
        tri3[2][0] = verts[idx[2]].x;
        tri3[2][1] = verts[idx[2]].y;
        tri3[2][2] = verts[idx[2]].z;
        hit = func_8001B434_1C034(tri3, (Vec3f*)&pos, sph.w, &hitPos);
    }
    if (hit == 1) {
        func_80009E0C_AA0C(hitPos.x, hitPos.y, hitPos.z);
        func_8002DA3C_2E63C(&verts[idx[0]], &verts[idx[1]], &verts[idx[2]], &D_800FD8C8_FE4C8[D_800BF796_C0396]);
        D_800BF796_C0396++;
        dx = hitPos.x - pos.x;
        dz = hitPos.z - pos.z;
        pen = sph.w - func_800B1830_B2430(dx * dx + dz * dz);
        if (side > 0) {
            idx--;
            if (func_8000393C_453C(&D_800D5760_D6360, (ColTri*)idx, verts) < 0) {
                dir.x = D_800D5760_D6360.x - pos.x;
                dir.y = D_800D5760_D6360.y - pos.y;
                dir.z = D_800D5760_D6360.z - pos.z;
                func_8002D9AC_2E5AC(&dir);
                if (func_80003CE0_48E0(&pos, idx, verts, &dir) == hit) {
                    pen = func_800B1830_B2430(dx * dx + dz * dz) + sph.w;
                }
            } else {
                pen = 0.0f;
            }
        }
        func_80009684_A284(-dx, -dz, pen);
    }
    return hit;
}

/* func_80005130_5D30 for a ground object's local face list: the hit is moved to world space with
   D_800FC838_FD438 and the reference point to local space (MP1 func_8000261C). */
s32 func_80005700_6300(void* arg0, s16* idx, ColVtx* verts, ColSphere* s) {
    Vec4f sph;
    Vec4f pos;
    Vec3f hitPos;
    f32 quad[4][3];
    f32 tri3[3][3];
    Vec3f dir;
    s16* tri;
    s32 side;
    s32 hit;
    f32 pen, dz, dx;

    pos.x = sph.x = s->x + D_800F94A0_FA0A0;
    pos.y = sph.y = s->y;
    pos.z = sph.z = s->z + D_80101308_101F08;
    sph.w = pos.w = s->r;
    tri = idx - 1;
    side = func_80003A54_4654(&sph, tri, verts);
    if (side == 0) {
        return 0;
    }
    if (((u16)*tri >> 14) + 2 == 4) {
        quad[0][0] = verts[idx[0]].x;
        quad[0][1] = verts[idx[0]].y;
        quad[0][2] = verts[idx[0]].z;
        quad[1][0] = verts[idx[1]].x;
        quad[1][1] = verts[idx[1]].y;
        quad[1][2] = verts[idx[1]].z;
        quad[2][0] = verts[idx[2]].x;
        quad[2][1] = verts[idx[2]].y;
        quad[2][2] = verts[idx[2]].z;
        quad[3][0] = verts[idx[3]].x;
        quad[3][1] = verts[idx[3]].y;
        quad[3][2] = verts[idx[3]].z;
        hit = func_8001B9AC_1C5AC(quad, (Vec3f*)&pos, sph.w, &hitPos);
    } else {
        tri3[0][0] = verts[idx[0]].x;
        tri3[0][1] = verts[idx[0]].y;
        tri3[0][2] = verts[idx[0]].z;
        tri3[1][0] = verts[idx[1]].x;
        tri3[1][1] = verts[idx[1]].y;
        tri3[1][2] = verts[idx[1]].z;
        tri3[2][0] = verts[idx[2]].x;
        tri3[2][1] = verts[idx[2]].y;
        tri3[2][2] = verts[idx[2]].z;
        hit = func_8001B434_1C034(tri3, (Vec3f*)&pos, sph.w, &hitPos);
    }
    if (hit == 1) {
        pos.x = s->x2 + D_800F94A0_FA0A0;
        pos.y = s->y2;
        pos.z = s->z2 + D_80101308_101F08;
        func_8000D74C_E34C(D_800FC838_FD438, &hitPos);
        func_80009E0C_AA0C(hitPos.x, hitPos.y, hitPos.z);
        func_8002DA3C_2E63C(&verts[idx[0]], &verts[idx[1]], &verts[idx[2]], &D_800FD8C8_FE4C8[D_800BF796_C0396]);
        D_800BF796_C0396++;
        dx = hitPos.x - pos.x;
        dz = hitPos.z - pos.z;
        pen = sph.w - func_800B1830_B2430(dx * dx + dz * dz);
        if (side > 0) {
            sph.x = D_800D5760_D6360.x;
            sph.y = D_800D5760_D6360.y;
            sph.z = D_800D5760_D6360.z;
            func_8000D74C_E34C(D_800F94C8_FA0C8, (Vec3f*)&sph);
            idx--;
            if (func_8000393C_453C((Vec3f*)&sph, (ColTri*)idx, verts) < 0) {
                dir.x = sph.x - pos.x;
                dir.y = sph.y - pos.y;
                dir.z = sph.z - pos.z;
                func_8002D9AC_2E5AC(&dir);
                if (func_80003CE0_48E0((Vec3f*)&pos, idx, verts, &dir) == hit) {
                    pen = func_800B1830_B2430(dx * dx + dz * dz) + sph.w;
                }
            } else {
                pen = 0.0f;
            }
        }
        if (pen >= 0.0f) {
            func_80009684_A284(-dx, -dz, pen);
        }
    }
    return hit;
}

/* Shape 8: the inside walls of a box (GroundWork.unk_A0..unk_AC); each wall the sphere reaches adds
   a contact (pushing harder when none did) and pushes it back in (MP1 func_80003460). */
void func_80005D60_6960(omObjData* obj, Vec4f* s) {
    s32 i = D_800BF796_C0396;
    GroundWork* g = obj->unk_50;
    f32 x0 = g->unk_A0 + s->w;
    f32 z0 = g->unk_A4 + s->w;
    f32 x1 = g->unk_A8 - s->w;
    f32 z1 = g->unk_AC - s->w;
    f32 half;

    if (s->x <= x0) {
        func_80009E0C_AA0C(g->unk_A0, s->y, s->z);
        func_80009DB0_A9B0(1.0f, 0.0f, 0.0f);
        D_800BF796_C0396++;
    }
    if (x1 <= s->x) {
        func_80009E0C_AA0C(g->unk_A8, s->y, s->z);
        func_80009DB0_A9B0(-1.0f, 0.0f, 0.0f);
        D_800BF796_C0396++;
    }
    if (s->z <= z0) {
        func_80009E0C_AA0C(s->x, s->y, g->unk_A4);
        func_80009DB0_A9B0(0.0f, 0.0f, 1.0f);
        D_800BF796_C0396++;
    }
    if (z1 <= s->z) {
        func_80009E0C_AA0C(s->x, s->y, g->unk_AC);
        func_80009DB0_A9B0(0.0f, 0.0f, -1.0f);
        D_800BF796_C0396++;
    }
    if (i == D_800BF796_C0396) {
        half = s->w * 0.5f;
        if (s->x <= x0 - half) {
            func_80009E0C_AA0C(g->unk_A0, s->y, s->z);
            func_80009DB0_A9B0(1.0f, 0.0f, 0.0f);
            D_800BF796_C0396++;
        }
        if (x1 + half <= s->x) {
            func_80009E0C_AA0C(g->unk_A8, s->y, s->z);
            func_80009DB0_A9B0(-1.0f, 0.0f, 0.0f);
            D_800BF796_C0396++;
        }
        if (s->z <= z0 - half) {
            func_80009E0C_AA0C(s->x, s->y, g->unk_A4);
            func_80009DB0_A9B0(0.0f, 0.0f, 1.0f);
            D_800BF796_C0396++;
        }
        if (z1 + half <= s->z) {
            func_80009E0C_AA0C(s->x, s->y, g->unk_AC);
            func_80009DB0_A9B0(0.0f, 0.0f, -1.0f);
            D_800BF796_C0396++;
        }
    }
    for (; i < D_800BF796_C0396; i++) {
        x0 = D_800F9D40_FA940[i].x - s->x;
        z0 = D_800F9D40_FA940[i].z - s->z;
        func_80009684_A284(-x0, -z0, s->w - func_800B1830_B2430(x0 * x0 + z0 * z0));
        if (obj->trans.x != 0.0f || obj->trans.y != 0.0f || obj->trans.z != 0.0f || obj->rot.x != 0.0f ||
            obj->rot.y != 0.0f || obj->rot.z != 0.0f) {
            func_8000D74C_E34C(D_800FC838_FD438, &D_800F9D40_FA940[i]);
        }
    }
}

/* Shape 0x20: the inside wall of a cylinder (radius GroundWork.unk_9C) around the object. The
   contact point scales the probe by the unit direction (retail; not the radius). */
void func_800061E4_6DE4(omObjData* obj, Vec4f* s) {
    GroundWork* g = obj->unk_50;
    f32 x = s->x;
    f32 z = s->z;
    f32 d;
    Vec3f n;

    d = g->unk_9C - (func_800B1830_B2430(x * x + z * z) + s->w);
    if (d <= 0.0f) {
        func_80009684_A284(x, z, d);
        n.x = x;
        n.y = 0.0f;
        n.z = z;
        func_8002D9AC_2E5AC(&n);
        func_80009E0C_AA0C(s->x * n.x, s->y, s->z * n.z);
        func_80009DB0_A9B0(-s->x, 0.0f, -s->z);
        D_800BF796_C0396++;
    }
}

/* Shape 0x40: the outside of a cylinder (radius GroundWork.unk_9C, top unk_14, height unk_98). */
void func_800062F0_6EF0(omObjData* obj, Vec4f* s, f32 h) {
    GroundWork* g = obj->unk_50;
    f32 x = s->x;
    f32 z = s->z;
    f32 d;
    Vec3f n;

    if (s->y < h + g->unk_14 && g->unk_14 - g->unk_98 - h < s->y) {
        d = func_800B1830_B2430(x * x + z * z) - g->unk_9C;
        if (d >= 0.0f && d <= s->w) {
            func_80009684_A284(x, z, s->w - d);
            n.x = x;
            n.y = 0.0f;
            n.z = z;
            func_8002D9AC_2E5AC(&n);
            func_80009E0C_AA0C(-s->x * n.x, s->y, -s->z * n.z);
            func_80009DB0_A9B0(s->x, 0.0f, s->z);
            D_800BF796_C0396++;
        }
    }
}

/* Box corners: a probe beyond a corner of the box (GroundWork.unk_A0..unk_AC) touching it adds the
   corner as a contact and returns 0; otherwise 1 (MP1 func_8000396C). */
s32 func_80006440_7040(Vec4f* s, GroundWork* g) {
    f32 x = s->x;
    f32 y = s->y;
    f32 z = s->z;
    f32 dx, dz;

    if (x <= g->unk_A0) {
        dx = g->unk_A0 - x;
        dz = g->unk_A4;
        if (z <= dz) {
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dz * dz) - s->w < 0.0f) {
                func_80009E0C_AA0C(g->unk_A0, y, g->unk_A4);
                func_80009DB0_A9B0(x - g->unk_A0, 0.0f, z - g->unk_A4);
                D_800BF796_C0396++;
                return 0;
            }
        } else if ((dz = g->unk_AC) <= z) {
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dz * dz) - s->w < 0.0f) {
                func_80009E0C_AA0C(g->unk_A0, y, g->unk_AC);
                func_80009DB0_A9B0(x - g->unk_A0, 0.0f, z - g->unk_AC);
                D_800BF796_C0396++;
                return 0;
            }
        }
    } else if (s->x >= g->unk_A8) {
        dx = g->unk_A8 - x;
        dz = g->unk_A4;
        if (z <= dz) {
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dz * dz) - s->w < 0.0f) {
                func_80009E0C_AA0C(g->unk_A8, y, g->unk_A4);
                func_80009DB0_A9B0(x - g->unk_A8, 0.0f, z - g->unk_A4);
                D_800BF796_C0396++;
                return 0;
            }
        } else if ((dz = g->unk_AC) <= z) {
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dz * dz) - s->w < 0.0f) {
                func_80009E0C_AA0C(g->unk_A8, y, g->unk_AC);
                func_80009DB0_A9B0(x - g->unk_A8, 0.0f, z - g->unk_AC);
                D_800BF796_C0396++;
                return 0;
            }
        }
    }
    return 1;
}

/* Shape 0x10: the outside of a box (GroundWork.unk_A0..unk_AC, top unk_14, height unk_98): a corner
   (func_80006440_7040) or the face the sphere is beyond adds a contact; then the sphere is pushed
   out (MP1 func_80003C08). */
void func_800066BC_72BC(omObjData* obj, Vec4f* s, f32 h) {
    s32 i = D_800BF796_C0396;
    GroundWork* g = obj->unk_50;
    f32 x = s->x;
    f32 z = s->z;
    f32 x0, z0, x1, z1;
    f32 cx, cz;

    if (s->y < h + g->unk_14 && g->unk_14 - g->unk_98 - h < s->y) {
        x0 = g->unk_A0 - s->w;
        z0 = g->unk_A4 - s->w;
        x1 = g->unk_A8 + s->w;
        z1 = g->unk_AC + s->w;
        if ((x0 <= x) & (x < x1)) {
            if ((z0 < z) & (z < z1)) {
                if (func_80006440_7040(s, g) == 1) {
                    if (x0 <= x && x <= (cx = g->unk_A0)) {
                        if (g->unk_A4 <= s->z && s->z <= g->unk_AC) {
                            if (cx == s->x) {
                                cx += 1.0f;
                            }
                            func_80009E0C_AA0C(cx, s->y, s->z);
                            func_80009DB0_A9B0(-1.0f, 0.0f, 0.0f);
                            D_800BF796_C0396++;
                        }
                    } else if (x <= x1 && (cx = g->unk_A8) <= x) {
                        if (g->unk_A4 <= s->z && s->z <= g->unk_AC) {
                            if (cx == s->x) {
                                cx -= 1.0f;
                            }
                            func_80009E0C_AA0C(cx, s->y, s->z);
                            func_80009DB0_A9B0(1.0f, 0.0f, 0.0f);
                            D_800BF796_C0396++;
                        }
                    } else if (z0 <= z && z <= g->unk_A4) {
                        if (g->unk_A0 <= s->x && s->x <= g->unk_A8) {
                            cz = g->unk_A4;
                            if (cz == s->z) {
                                cz += 1.0f;
                            }
                            func_80009E0C_AA0C(s->x, s->y, cz);
                            func_80009DB0_A9B0(0.0f, 0.0f, -1.0f);
                            D_800BF796_C0396++;
                        }
                    } else if (z <= z1 && g->unk_AC <= z) {
                        if (g->unk_A0 <= s->x && s->x <= g->unk_A8) {
                            cz = g->unk_AC;
                            if (cz == s->z) {
                                cz -= 1.0f;
                            }
                            func_80009E0C_AA0C(s->x, s->y, cz);
                            func_80009DB0_A9B0(0.0f, 0.0f, 1.0f);
                            D_800BF796_C0396++;
                        }
                    }
                }
                for (; i < D_800BF796_C0396; i++) {
                    x0 = D_800F9D40_FA940[i].x - s->x;
                    z0 = D_800F9D40_FA940[i].z - s->z;
                    func_80009684_A284(x0, z0, func_800B1830_B2430(x0 * x0 + z0 * z0) - s->w);
                    if (obj->trans.x != 0.0f || obj->trans.y != 0.0f || obj->trans.z != 0.0f ||
                        obj->rot.x != 0.0f || obj->rot.y != 0.0f || obj->rot.z != 0.0f) {
                        func_8000D74C_E34C(D_800FC838_FD438, &D_800F9D40_FA940[i]);
                    }
                }
            }
        }
    }
}

/* After the wall pushes: a fast player running into a wall bounces off it (MP1 func_8000423C). */
void func_80006BF8_77F8(omObjData* obj, ColSphere* s, f32 arg2) {
    MgWork* w;
    f32 speed;
    f32 sa, sb;
    f32 dx, dy, dz;
    f32 lim;
    f32 nx;
    s32 i;

    if (D_800BF796_C0396 == 0) {
        return;
    }
    w = obj->unk_50;
    if (w->unk_52 == 0) {
        sa = w->unk_40;
        sb = w->unk_B4;
        if (w->unk_50 & 6) {
            speed = sa * 0.6f * sb;
        } else {
            speed = sa * sb;
        }
    } else {
        speed = w->unk_40;
    }
    if (w->unk_38 != 1000.0f) {
        speed *= w->unk_4C;
    }
    for (i = 0; i < D_800BF796_C0396; i++) {
        dx = D_800F9D40_FA940[i].x - s->x;
        dy = D_800F9D40_FA940[i].y - s->y;
        dz = D_800F9D40_FA940[i].z - s->z;
        func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        nx = HuMathSin(w->unk_3C) * speed + D_800F94A0_FA0A0;
        if (func_8000DA2C_E62C(nx, func_800B7890_B8490(w->unk_3C) * speed + D_80101308_101F08, dx, dz) > 0.9f &&
            w->unk_38 != 1000.0f && w->unk_40 > D_800BF7C4_C03C4) {
            lim = w->unk_40;
            if (w->unk_50 & 6) {
                lim *= 0.6f;
            }
            lim *= w->unk_4C * w->unk_B4 * 0.98f;
            if (func_800B1830_B2430(D_800F94A0_FA0A0 * D_800F94A0_FA0A0 + D_80101308_101F08 * D_80101308_101F08) < lim) {
                if (w->unk_50 & 8) {
                    w->unk_40 = -D_800BF7C0_C03C0;
                } else {
                    w->unk_40 = -D_800BF7CC_C03CC;
                }
                func_80019B9C_1A79C(obj, 0x1E);
                func_8000C584_D184(w, 7);
                omVibrate(w->unk_59, 5, 0, 5);
                return;
            }
        }
        if (arg2 != 0.0f) {
            w->unk_40 = arg2;
            func_8000C584_D184(w, 7);
            omVibrate(w->unk_59, 2, 3, 10);
            return;
        }
    }
}

/* Push the player's sphere out of every ground object: the one it stands on (D_800BF794_C0394, in
   world space) first, then the others in their local space. Returns the surface id of the last
   object touched (-1 none); func_80006BF8_77F8 then handles a wall hit (MP1 func_80004D1C). */
s32 func_80006F34_7B34(omObjData* obj, Vec4f* p, f32 arg2) {
    Vec4f s;
    ColSphere s2;
    MgWork* w = obj->unk_50;
    omObjData* o;
    GroundWork* g;
    s16 prev;
    s16 i;

    s.x = p->x;
    s.y = w->unk_34 / 2.0f + p->y;
    s.z = p->z;
    s.w = p->w;
    D_800FD7F4_FE3F4 = -1;
    D_800BF796_C0396 = 0;
    prev = D_800BF796_C0396;
    if (!(w->unk_00[D_800BF794_C0394] & 1)) {
        o = D_800FC7B0_FD3B0[D_800BF794_C0394];
        g = o->unk_50;
        if (g->unk_06 & 8) {
            s.x += D_800F94A0_FA0A0;
            s.y += D_80101308_101F08;
            func_80005D60_6960(o, &s);
        } else if (g->unk_06 & 0x10) {
            s.x += D_800F94A0_FA0A0;
            s.y += D_80101308_101F08;
            func_800066BC_72BC(o, &s, w->unk_34 / 2.0f);
        } else if (g->unk_06 & 0x20) {
            s.x += D_800F94A0_FA0A0;
            s.y += D_80101308_101F08;
            func_800061E4_6DE4(o, &s);
        } else if (g->unk_06 & 0x40) {
            s.x += D_800F94A0_FA0A0;
            s.y += D_80101308_101F08;
            func_800062F0_6EF0(o, &s, w->unk_34 / 2.0f);
        } else if (!(g->unk_06 & 2)) {
            func_8002F2C4_2FEC4(*D_800FC7B0_FD3B0[D_800BF794_C0394]->model, D_800F9D30_FA930, func_80005130_5D30, &s);
        }
        if (prev != D_800BF796_C0396) {
            D_800FD7F4_FE3F4 = g->unk_04;
        }
    }
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        o = D_800FC7B0_FD3B0[i];
        g = o->unk_50;
        if (i == D_800BF794_C0394 || (g->unk_06 & 2) || (w->unk_00[i] & 1)) {
            continue;
        }
        prev = D_800BF796_C0396;
        s2.x = s2.x2 = p->x;
        s2.y = s2.y2 = w->unk_34 / 2.0f + p->y;
        s2.z = s2.z2 = p->z;
        s2.r = s.w = p->w;
        func_8000D434_E034(D_800FC838_FD438, D_800F94C8_FA0C8, (Vec3f*)&s2, o);
        if ((g->unk_06 & 4) && func_8000DB30_E730(D_800FC834_FD434[*o->model].hmf->unk64, (Vec3f*)&s2, w->unk_48) == 0) {
            continue;
        }
        if (g->unk_06 & 8) {
            s2.x += D_800F94A0_FA0A0;
            s2.y += D_80101308_101F08;
            func_80005D60_6960(o, (Vec4f*)&s2);
        } else if (g->unk_06 & 0x10) {
            s2.x += D_800F94A0_FA0A0;
            s2.y += D_80101308_101F08;
            func_800066BC_72BC(o, (Vec4f*)&s2, w->unk_34 / 2.0f);
        } else if (g->unk_06 & 0x20) {
            s2.x += D_800F94A0_FA0A0;
            s2.y += D_80101308_101F08;
            func_800061E4_6DE4(o, (Vec4f*)&s2);
        } else if (g->unk_06 & 0x40) {
            s2.x += D_800F94A0_FA0A0;
            s2.y += D_80101308_101F08;
            func_800062F0_6EF0(o, (Vec4f*)&s2, w->unk_34 / 2.0f);
        } else {
            func_8002F2C4_2FEC4(*D_800FC7B0_FD3B0[i]->model, D_800F9D30_FA930, func_80005700_6300, &s2);
        }
        if (prev != D_800BF796_C0396) {
            D_800FD7F4_FE3F4 = g->unk_04;
            func_8000D6D0_E2D0(D_800FC838_FD438, &D_800FD8C8_FE4C8[D_800BF796_C0396 - 1]);
        }
    }
    s.x = p->x + D_800F94A0_FA0A0;
    s.y = w->unk_34 / 2.0f + p->y;
    s.z = p->z + D_80101308_101F08;
    s.w = p->w;
    if (func_8000C098_CC98(D_800FD7F4_FE3F4) == 1) {
        func_80006BF8_77F8(obj, (ColSphere*)&s, arg2);
    }
    return D_800FD7F4_FE3F4;
}

/* Tilt the player toward the floor normal (MP1 func_800057F4). The doubles are 1130's rodata
   (2.0, 0.3, 2.0, 0.3) still in the data blob: G's tail carve takes them (written as externs so
   this builds before it). */
void func_8000755C_815C(omObjData* obj, Vec3f* n) {
    MgWork* w = obj->unk_50;
    f32 rx, rz;
    f32 cx, cz;

    if (w->unk_40 > D_800BF7C4_C03C4) {
        rx = -(func_800B75A8_B81A8(n->y, n->z) - 90.0f);
        rz = func_800B75A8_B81A8(n->y, n->x);
        cx = w->unk_9C;
        cz = w->unk_A4;
        rz -= 90.0f;
        if (cx < rx) {
            w->unk_9C += 4.0f;
            if (rx < w->unk_9C) {
                w->unk_9C = rx;
            }
        } else if (rx < cx) {
            w->unk_9C -= 4.0f;
            if (w->unk_9C < rx) {
                w->unk_9C = rx;
            }
        }
        if (cz < rz) {
            w->unk_A4 += 4.0f;
            if (rz < w->unk_A4) {
                w->unk_A4 = rz;
            }
        } else if (rz < cz) {
            w->unk_A4 -= 4.0f;
            if (w->unk_A4 < rz) {
                w->unk_A4 = rz;
            }
        }
    } else {
        if (fabs(w->unk_9C) > D_800D1780_D2380) {
            obj->rot.x = w->unk_9C = w->unk_9C * D_800D1788_D2388;
        }
        if (fabs(w->unk_A4) > D_800D1790_D2390) {
            obj->rot.z = w->unk_A4 = w->unk_A4 * D_800D1798_D2398;
        }
    }
    obj->rot.x = w->unk_9C;
    obj->rot.z = w->unk_A4;
}

void func_8000776C_836C(omObjData* obj) {
    D_800D5760_D6360.x = obj->trans.x;
    D_800D5760_D6360.y = obj->trans.y;
    D_800D5760_D6360.z = obj->trans.z;
}

INCLUDE_ASM("asm/nonmatchings/1130", func_80007790_8390);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009684_A284);

INCLUDE_ASM("asm/nonmatchings/1130", func_800096F0_A2F0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009744_A344);

INCLUDE_ASM("asm/nonmatchings/1130", func_800097EC_A3EC);

INCLUDE_ASM("asm/nonmatchings/1130", func_800098D0_A4D0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009DB0_A9B0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009E0C_AA0C);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009E48_AA48);
