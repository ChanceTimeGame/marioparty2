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
void func_80005D60_6960(omObjData*, Vec3f*);
void func_800061E4_6DE4(omObjData*, Vec3f*);
void func_800062F0_6EF0(omObjData*, Vec3f*, f32);
void func_800066BC_72BC(omObjData*, Vec3f*, f32);

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
void func_80006F34_7B34(omObjData* obj, Vec4f* p, s32 arg2);
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
            func_80005D60_6960(g, (Vec3f*)&probe);
        } else if (gw->unk_06 & 0x10) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800066BC_72BC(g, (Vec3f*)&probe, w->unk_34 / 2.0f);
        } else if (gw->unk_06 & 0x20) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800061E4_6DE4(g, (Vec3f*)&probe);
        } else if (gw->unk_06 & 0x40) {
            probe.x += D_800F94A0_FA0A0;
            probe.y += D_80101308_101F08;
            func_800062F0_6EF0(g, (Vec3f*)&probe, w->unk_34 / 2.0f);
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

INCLUDE_ASM("asm/nonmatchings/1130", func_80004168_4D68);

INCLUDE_ASM("asm/nonmatchings/1130", func_80005034_5C34);

INCLUDE_ASM("asm/nonmatchings/1130", func_80005110_5D10);

INCLUDE_ASM("asm/nonmatchings/1130", func_80005130_5D30);

INCLUDE_ASM("asm/nonmatchings/1130", func_80005700_6300);

INCLUDE_ASM("asm/nonmatchings/1130", func_80005D60_6960);

INCLUDE_ASM("asm/nonmatchings/1130", func_800061E4_6DE4);

INCLUDE_ASM("asm/nonmatchings/1130", func_800062F0_6EF0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80006440_7040);

INCLUDE_ASM("asm/nonmatchings/1130", func_800066BC_72BC);

INCLUDE_ASM("asm/nonmatchings/1130", func_80006BF8_77F8);

INCLUDE_ASM("asm/nonmatchings/1130", func_80006F34_7B34);

INCLUDE_ASM("asm/nonmatchings/1130", func_8000755C_815C);

INCLUDE_ASM("asm/nonmatchings/1130", func_8000776C_836C);

/* ---- fork G (wave H2): func_80007790_8390 to the end of the unit ---- */

/* The rodata of fork F's functions, still assembly here: the doubles of func_80004168_4D68 and
   func_8000755C_815C. They are defined here so that this unit's rodata is one carved piece
   (0xD2340-0xD2400). Not const, so that fork F's "extern f64" declarations of them agree. */
f64 D_800D1770_D2370 __attribute__((section(".rodata"))) = 0.2;
f64 D_800D1778_D2378 __attribute__((section(".rodata"))) = 0.5;
f64 D_800D1780_D2380 __attribute__((section(".rodata"))) = 2.0;
f64 D_800D1788_D2388 __attribute__((section(".rodata"))) = 0.3;
f64 D_800D1790_D2390 __attribute__((section(".rodata"))) = 2.0;
f64 D_800D1798_D2398 __attribute__((section(".rodata"))) = 0.3;

f32 func_80002A28_3628(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000776C_836C(omObjData* obj);
f32 func_800096F0_A2F0(f32 speed);
void func_80009744_A344(omObjData* obj, f32 x, f32 y, f32 z);
void func_800097EC_A3EC(omObjData* obj);
void func_800098D0_A4D0(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000AAE0_B6E0(omObjData* obj, MgWork* w);
void func_8000AB64_B764(omObjData* obj, MgWork* w);
void func_8000AC8C_B88C(omObjData* obj, MgWork* w, GroundWork* g, s16 x, s16 y);
void func_8000AD78_B978(omObjData* obj, MgWork* w);
void func_8000AE58_BA58(omObjData* obj, MgWork* w, GroundWork* g, f32 x, f32 y, f32 z);
void func_8000AF60_BB60(omObjData* obj, MgWork* w, GroundWork* g, f32 x, f32 y, f32 z);
void func_8000AFFC_BBFC(omObjData* obj, MgWork* w);
void func_8000B0E4_BCE4(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000B204_BE04(omObjData* obj, s32 flags, f32 x, f32 y, f32 z);
void func_8000B298_BE98(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000B4D8_C0D8(omObjData* obj, f32 x, f32 y, f32 z);
s32 func_8000B770_C370(omObjData* obj, omObjData* other);
void func_8000B7AC_C3AC(omObjData* obj, omObjData* other, f32 dx, f32 dz, u16 i);
s32 func_8000C098_CC98(s8 id);
void func_8000C610_D210(MgWork* w, s32 arg1);
s32 func_8000CDC8_D9C8(omObjData* obj, s16 x, s16 y);
void func_8000CE80_DA80(s16* x, s16* y);
void func_8000CF58_DB58(omObjData* obj);
s16 func_8000CF84_DB84(s16 player, s16 limit, s8 x, s8 y);
void func_8000D81C_E41C(omObjData* obj, f32 arg1);
s32 func_8000D900_E500(omObjData* obj, omObjData* item);
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
s32 func_80019000_19C00(omObjData* obj);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80019378_19F78(omObjData* obj);
void func_80019644_1A244(omObjData* obj);
void func_800212A4_21EA4(s16 index);
f32 func_80029CE4_2A8E4(s16 mdl); /* model motion time */
f32 func_80029E3C_2AA3C(s16 mdl); /* motion frame, -1 at the end */
f32 func_8002D958_2E558(f32 angle); /* wraps an angle */
void func_80079848_7A448(s16 arg0);
void func_800B2060_B2C60(f32 (*m)[4], f32 x, f32 y, f32 z); /* rotate matrix */
int abs(int);

/* Fork A's prototypes above declare these narrower than the callers below use them: the step
   takes an unused fifth argument (MP1 func_80004578) and the wall push returns the side and takes
   an f32 (MP1 func_80004D1C). Called through these until the prototypes are fixed. */
#define STEP_FLOOR(obj, x, y, z, y0) \
    ((f32 (*)(omObjData*, f32, f32, f32, f32))func_80002A28_3628)(obj, x, y, z, y0)
#define WALL_PUSH(obj, p, push) ((s32 (*)(omObjData*, Vec4f*, f32))func_80006F34_7B34)(obj, p, push)

/* u16 fields inside the padding that fork F's MgWork change leaves (unk_B8[6], unk_C0[3]); make
   them fields when the branches merge. */
#define MGW_UNK_BC(w) (*(u16*)&(w)->unk_B8[4]) /* 0xBC: frames running, at most 200 (MP1 0xAC) */
#define MGW_UNK_C0(w) (*(u16*)&(w)->unk_C0[0]) /* 0xC0: spin countdown (flags 0x100000) */

extern s8 ContStkX[];
extern s8 ContStkY[];
extern u16 ContBtn[];
extern u16 ContBtnTrg[];
extern s32 D_800F8FD0_F9BD0;           /* scene state; 1 = players take input */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A8_C03A8;           /* gravity */
extern f32 D_800BF7AC_C03AC;
extern f32 D_800BF7B0_C03B0;
extern f32 D_800BF7BC_C03BC;
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
extern f32 D_800BF7D4_C03D4;           /* fall speed cap */
extern s8 D_800FD7F4_FE3F4;            /* ground object touched this frame (MP1 D_800F3704) */
extern u16 D_800FD7FC_FE3FC;           /* MP1 D_800F370C */
extern omObjData* D_800F9CE0_FA8E0[];  /* item actors (MP1 D_800EDE70) */
extern u16 D_800FA606_FB206;           /* their count */
extern Vec3f D_800F9D40_FA940[];       /* contact points (MP1 D_800EDED0) */
extern HmfModel* D_800FC834_FD434;
extern f32 D_800BF7B4_C03B4;           /* player radius (debug menu) */
extern f32 D_800BF7B8_C03B8;           /* attack reach (debug menu) */
extern u8 D_800BF79B_C039B;            /* debug menu: homing camera */
extern s8 D_800BF7E0_C03E0;            /* debug menu: row */
extern f32 D_800FA610_FB210;           /* CZoom */
extern Vec D_800FD474_FE074;           /* CRot */
extern Vec D_8010274C_10334C;          /* Center */
extern s32 fontcolor;
extern char pfStrBuf[];
int sprintf(char* s, const char* fmt, ...);
s16 DrawDebugText(u16 x, u16 y, char* str); /* MP1 print8 */

/* A minigame player's step (MP1 func_80005A28): stick and buttons, then one branch per motion
   state (func_80019000_19C00's flags), then the move along the heading. MP2 adds the hooks in
   MgWork.unk_104 ([0] first, [1] last, [20] for flags 0x200000), the spin state 0x100000, the
   states 0xC0000 and 0x1000, and moves several MP1 blocks into B6E0.c helpers. */
// register allocation (masked 0): the cos * mag product in the 0x320 branch takes $f12 instead of
// $f4, as in MP1's NON_MATCHING func_80005A28
#ifdef NON_MATCHING
void func_80007790_8390(omObjData* obj) {
    s16 sx;
    s16 sy;
    f32 x;
    f32 y;
    f32 z;
    MgWork* w = obj->unk_50;
    GroundWork* g;
    GroundWork* gr;
    omObjData* o;
    u8 port = w->unk_57;
    f32 mag = 0.0f;
    u16 mdl;
    f32 vy0;
    u16 btn;
    u16 trg;
    s32 flags;
    s32 ok;
    u16 anim;
    s32 r;
    s16 rx, ry;
    s16 r2;
    f32 dx, dy;
    f32 frame;
    f32 v;
    f32 ny;
    f32 vv1;
    f32 vv;
    f32 v1, ny1, v3, v5, frame5, frame2, frame6;
    omObjData* o7;
    f32 lim;
    f32 acc;
    f32 ang;
    f32 px;

    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    func_8000776C_836C(obj);
    mdl = obj->model[0];
    vy0 = w->unk_38;
    D_800F94A0_FA0A0 = D_80101308_101F08 = mag;
    D_800FD7FC_FE3FC = 0;
    *(s8*)&w->unk_55 = -1; /* s8 here (MP1 s8; collision.h u8) */
    D_800FD7F4_FE3F4 = -1;
    if (w->unk_104[0] != 0) {
        /* host: a hook pointer kept in an s32 slot */
        ((void (*)(omObjData*))w->unk_104[0])(obj);
    }
    if (((D_800F8FD0_F9BD0 == 1) & ((s8)port >= 0)) && !(w->unk_50 & 1)) {
        sx = ContStkX[(s8)port];
        sy = ContStkY[(s8)port];
        if (sx > 60) {
            sx = 60;
        }
        if (sy > 60) {
            sy = 60;
        }
        if (sx < -60) {
            sx = -60;
        }
        if (sy < -60) {
            sy = -60;
        }
        func_8000CE80_DA80(&sx, &sy);
        if (!(w->unk_50 & 6)) {
            trg = ContBtnTrg[(s8)port];
            btn = ContBtn[(s8)port];
        } else {
            btn = 0;
            trg = 0;
        }
    } else {
        sx = sy = 0;
        btn = 0;
        trg = 0;
    }
    flags = func_80019000_19C00(obj);
    if (flags & 1) {
        ok = 1;
        if (w->unk_38 == 1000.0f) {
            if (func_8000312C_3D2C(obj, w->unk_3C, x, y, z) != 65536.0f && (trg & 0x8000)) {
                func_8000AAE0_B6E0(obj, w);
                ok = 0;
            }
        } else {
            v1 = w->unk_38;
            if (v1 > D_800BF7D4_C03D4) {
                v1 = D_800BF7D4_C03D4;
            }
            vv1 = v1 * v1;
            ny1 = y + vv1 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800BF7A8_C03A8;
            if (func_80019B9C_1A79C(obj, 6) == 1) {
                func_8000C584_D184(w, 3);
                ok = 0;
            }
            y = STEP_FLOOR(obj, x, ny1, z, y);
            if (w->unk_38 == 1000.0f) {
                o = D_800FC7B0_FD3B0[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_03 == 2) {
                    func_80009744_A344(obj, x, o->trans.y, z);
                }
            }
        }
        if (ok == 1) {
            func_80019B9C_1A79C(obj, 0);
        }
        w->unk_C6 = 0;
    } else if (flags & 0x100000) {
        MGW_UNK_C0(w)--;
        if (MGW_UNK_C0(w) == 0) {
            func_80019B9C_1A79C(obj, 0x13);
        }
        if (MGW_UNK_C0(w) - 52 < 0) {
            w->unk_40 = D_800BF7D0_C03D0;
            obj->rot.y = 0.0f;
        } else {
            obj->rot.y = func_8002D958_2E558(MGW_UNK_C0(w) * 45.0f);
            if (w->unk_40 < D_800BF7D0_C03D0) {
                w->unk_40 += D_800BF7A0_C03A0 * 0.2f;
                if (D_800BF7D0_C03D0 <= w->unk_40) {
                    w->unk_40 = D_800BF7D0_C03D0;
                }
            } else if (D_800BF7D0_C03D0 <= w->unk_40) {
                w->unk_40 += -D_800BF7A0_C03A0 * 0.2f;
                if (w->unk_40 <= D_800BF7D0_C03D0) {
                    w->unk_40 = D_800BF7D0_C03D0;
                }
            }
        }
        ny = func_8000312C_3D2C(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
        }
    } else if (flags & 0x18C18) {
        if (flags & 0x10000) {
            if (trg & 0x8000) {
                func_8000AAE0_B6E0(obj, w);
            }
        } else if (w->unk_40 == D_800BF7D0_C03D0) {
            if (flags & 0x400) {
                func_80019B9C_1A79C(obj, 0x21);
            } else if (flags & 0x10) {
                func_80019B9C_1A79C(obj, 0x12);
            } else if (flags & 0x800) {
                func_80019B9C_1A79C(obj, 0x22);
            } else if (flags & 8) {
                func_80019B9C_1A79C(obj, 0x13);
            } else {
                func_80019B9C_1A79C(obj, 0);
            }
        } else if (w->unk_40 < D_800BF7D0_C03D0) {
            w->unk_40 += D_800BF7A0_C03A0 * 2.0f;
            if (D_800BF7D0_C03D0 <= w->unk_40) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        } else if (D_800BF7D0_C03D0 <= w->unk_40) {
            w->unk_40 += -D_800BF7A0_C03A0 * 2.0f;
            if (w->unk_40 <= D_800BF7D0_C03D0) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        }
        v3 = w->unk_38;
        if (v3 == 1000.0f) {
            if (flags & 0x10) {
                if (w->unk_40 > D_800BF7C0_C03C0) {
                    w->unk_3C += -(f32)sx / D_800BF7B0_C03B0;
                } else {
                    lim = (w->unk_40 <= D_800BF7CC_C03CC) ? D_800BF7CC_C03CC : w->unk_40;
                    w->unk_3C += -(sx / D_800BF7B0_C03B0) * (lim / D_800BF7C0_C03C0);
                }
            }
            goto ground;
        } else {
            if (v3 > D_800BF7D4_C03D4) {
                v3 = D_800BF7D4_C03D4;
            }
            vv = v3 * v3;
            ny = y + vv * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800BF7A8_C03A8;
            y = STEP_FLOOR(obj, x, ny, z, y);
            if (w->unk_38 != 1000.0f) {
            } else {
                o = D_800FC7B0_FD3B0[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_03 == 2) {
                    func_80009744_A344(obj, x, o->trans.y, z);
                } else if (flags & 0x10) {
                    func_80019B9C_1A79C(obj, 0x12);
                } else if (flags & 8) {
                    func_80019B9C_1A79C(obj, 0x13);
                } else if (flags & 0xC00) {
                } else {
                    func_80019B9C_1A79C(obj, 0);
                }
            }
        }
        w->unk_C6 = 0;
    } else if (flags & 0x6000) {
        func_8000CDC8_D9C8(obj, sx, sy);
        frame = func_80029E3C_2AA3C(mdl);
        if (frame == -1.0f) {
            frame = func_80029CE4_2A8E4(mdl);
        }
        if (flags & 0x4000) {
            w->unk_3C += 25.0f;
            if (frame >= 14.0f) {
                func_80019B9C_1A79C(obj, 1);
                w->unk_40 = D_800BF7CC_C03CC;
                func_8000C584_D184(w, 1);
            }
        } else if (frame >= 10.0f) {
            if (abs(sx) >= 9 || abs(sy) >= 9) {
                if (w->unk_40 < D_800BF7CC_C03CC) {
                    if (func_8000DA2C_E62C(sx, -sy, HuMathSin(w->unk_3C), func_800B7890_B8490(w->unk_3C)) < 0.0f) {
                        func_80019B9C_1A79C(obj, 0x20);
                    }
                }
            }
            if (frame >= 15.0f && w->unk_40 < D_800BF7CC_C03CC) {
                if (abs(sx) >= 9 || abs(sy) >= 9) {
                    if (w->unk_40 < D_800BF7CC_C03CC) {
                        if (func_8000DA2C_E62C(sx, -sy, HuMathSin(w->unk_3C), func_800B7890_B8490(w->unk_3C)) < 0.0f) {
                            func_80019B9C_1A79C(obj, 0x20);
                        } else {
                            func_80019B9C_1A79C(obj, 2);
                            w->unk_40 = D_800BF7C4_C03C4;
                            func_8000C584_D184(w, 1);
                        }
                    }
                } else {
                    func_80019B9C_1A79C(obj, 0);
                }
            }
        }
        if (w->unk_53 >= 0) {
            acc = ((GroundWork*)D_800FC7B0_FD3B0[w->unk_53]->unk_50)->unk_08;
        } else {
            acc = D_800BF7A0_C03A0;
        }
        acc *= 2.0f;
        if (w->unk_40 < D_800BF7D0_C03D0) {
            w->unk_40 = acc + w->unk_40;
            if (D_800BF7D0_C03D0 <= w->unk_40) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        } else if (D_800BF7D0_C03D0 <= w->unk_40) {
            w->unk_40 = w->unk_40 - acc;
            if (w->unk_40 <= D_800BF7D0_C03D0) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        }
        ny = func_8000312C_3D2C(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
            if (trg & 0x8000) {
                func_8000AAE0_B6E0(obj, w);
            } else if (trg & 0x4000) {
                func_8000AB64_B764(obj, w);
                func_8000CF58_DB58(obj);
            }
        }
        w->unk_C6 = 0;
    } else if (flags & 0x320) {
        frame2 = func_80029E3C_2AA3C(mdl);
        if (frame2 == -1.0f) {
            frame2 = func_80029CE4_2A8E4(mdl);
        }
        v = w->unk_38;
        if (!(flags & 0x300)) {
            if (((frame2 > 5.0f) & (frame2 < 7.0f)) && !(btn & 0x8000)) {
                if (!(w->unk_50 & 8) & (v < 0.0f)) {
                    w->unk_38 = -D_800BF7A4_C03A4 * 0.2f;
                }
            }
            if (abs(sx) >= 9 || abs(sy) >= 9) {
                D_800F94A0_FA0A0 = sx / D_800BF7AC_C03AC * w->unk_B4;
                D_80101308_101F08 = -(f32)sy / D_800BF7AC_C03AC * w->unk_B4;
                mag = func_800B1830_B2430(D_800F94A0_FA0A0 * D_800F94A0_FA0A0 + D_80101308_101F08 * D_80101308_101F08);
                ang = func_800B75A8_B81A8(D_800F94A0_FA0A0, D_80101308_101F08) + w->unk_60;
                D_800F94A0_FA0A0 = HuMathSin(ang) * mag;
                D_80101308_101F08 = func_800B7890_B8490(ang) * mag;
                if (w->unk_50 & 8) {
                    D_800F94A0_FA0A0 *= 0.2f;
                    D_80101308_101F08 *= 0.2f;
                }
            }
            if (trg & 0x4000) {
                func_8000AFFC_BBFC(obj, w);
            }
            if ((trg & 0x2000) && !(w->unk_50 & 8)) {
                func_8000AD78_B978(obj, w);
            }
            if (v > D_800BF7D4_C03D4) {
                v = D_800BF7D4_C03D4;
            }
            ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800BF7A8_C03A8;
        } else {
            if (v > D_800BF7D4_C03D4) {
                v = D_800BF7D4_C03D4;
            }
            if (frame2 > 26.0f) {
                ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
                w->unk_38 += D_800BF7A8_C03A8 * 2.0f;
            } else if (flags & 0x100) {
                ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
                w->unk_38 += D_800BF7A8_C03A8 / 2.0f;
            } else {
                ny = y;
            }
            if (flags & 0x100) {
                func_8000B0E4_BCE4(obj, x, ny, z);
            }
        }
        y = STEP_FLOOR(obj, x, ny, z, y);
        if (w->unk_38 != 1000.0f) {
        } else {
            o = D_800FC7B0_FD3B0[w->unk_53];
            g = o->unk_50;
            if (g->unk_03 == 2) {
                func_80009744_A344(obj, x, o->trans.y, z);
            } else if (flags & 0x200) {
                if (!(w->unk_50 & 0x80) && w->unk_BE == 0) {
                    func_8000AE58_BA58(obj, w, g, x, y, z);
                } else {
                    func_8000AF60_BB60(obj, w, g, x, y, z);
                }
            } else {
                func_8000AC8C_B88C(obj, w, g, sx, sy);
            }
        }
        w->unk_C6 = 0;
    } else if (flags & 0xC0) {
        func_8000B204_BE04(obj, flags, x, y, z);
        if (w->unk_38 == 1000.0f) {
            if (w->unk_40 < D_800BF7D0_C03D0) {
                w->unk_40 += D_800BF7A0_C03A0 * 2.0f;
                if (D_800BF7D0_C03D0 < w->unk_40) {
                    w->unk_40 = D_800BF7D0_C03D0;
                }
            } else if (D_800BF7D0_C03D0 < w->unk_40) {
                w->unk_40 += -D_800BF7A0_C03A0 * 2.0f;
                if (w->unk_40 < D_800BF7D0_C03D0) {
                    w->unk_40 = D_800BF7D0_C03D0;
                }
            }
        ground:
            ny = func_8000312C_3D2C(obj, w->unk_3C, x, y, z);
            if (ny != 65536.0f) {
                y = ny;
            }
        } else {
            v5 = w->unk_38;
            if (v5 > D_800BF7D4_C03D4) {
                v5 = D_800BF7D4_C03D4;
            }
            frame5 = func_80029E3C_2AA3C(mdl);
            if (frame5 == -1.0f) {
                frame5 = func_80029CE4_2A8E4(mdl);
            }
            ny = y + v5 * v5 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            if (frame5 > 30.0f) {
                w->unk_38 += D_800BF7A8_C03A8 * 2.0f;
            } else {
                w->unk_38 += D_800BF7A8_C03A8 / 2.0f;
            }
            y = STEP_FLOOR(obj, x, ny, z, y);
            if (w->unk_38 != 1000.0f) {
            } else {
                o = D_800FC7B0_FD3B0[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_03 == 2) {
                    func_80009744_A344(obj, x, o->trans.y, z);
                } else if (abs(sx) < 8 && abs(sy) < 8) {
                    w->unk_40 = D_800BF7D0_C03D0;
                    func_80019B9C_1A79C(obj, 0x15);
                    func_8000C584_D184(w, 4);
                } else {
                    func_80019B9C_1A79C(obj, 1);
                    w->unk_40 = D_800BF7C8_C03C8;
                    func_8000C584_D184(w, 1);
                }
            }
        }
        w->unk_C6 = 0;
    } else if (flags & 6) {
        r = func_8000CDC8_D9C8(obj, sx, sy);
        rx = r >> 16;
        ry = r;
        mag = func_800B1830_B2430(rx * rx + ry * ry) / D_800BF7BC_C03BC;
        if (w->unk_53 >= 0) {
            gr = D_800FC7B0_FD3B0[w->unk_53]->unk_50;
            if (gr->unk_0C != 0.0f) {
                w->unk_40 += mag / gr->unk_0C;
            } else {
                w->unk_40 += mag / D_800BF79C_C039C;
            }
            if (sx | sy) {
                w->unk_40 = w->unk_40 - gr->unk_08;
            } else {
                w->unk_40 = -gr->unk_08 * 3.0f + w->unk_40;
            }
        } else {
            w->unk_40 += mag / D_800BF79C_C039C;
            if (sx | sy) {
                w->unk_40 = w->unk_40 - D_800BF7A0_C03A0;
            } else {
                w->unk_40 = -D_800BF7A0_C03A0 * 3.0f + w->unk_40;
            }
        }
        mag = func_800096F0_A2F0(mag);
        if (w->unk_40 > mag) {
            w->unk_40 = mag;
        }
        if (w->unk_40 < D_800BF7D0_C03D0) {
            w->unk_40 = D_800BF7D0_C03D0;
        }
        if (abs(rx) >= 9 || abs(ry) >= 9) {
            w->unk_3C = func_800B75A8_B81A8(rx, -ry) + w->unk_60;
        }
        ny = func_8000312C_3D2C(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
            if (!(func_80019000_19C00(obj) & 0xC00)) {
                if (trg & 0x8000) {
                    func_8000AAE0_B6E0(obj, w);
                } else if (trg & 0x4000) {
                    func_8000AB64_B764(obj, w);
                } else if (dx = sx - rx, dy = sy - ry, func_800B1830_B2430(dx * dx + dy * dy) > 65.0f) {
                    if (fabs(w->unk_40) >= D_800BF7C4_C03C4) {
                        func_80019B9C_1A79C(obj, 0x11);
                        w->unk_40 = D_800BF7C8_C03C8;
                        func_8000C584_D184(w, 2);
                        px = x + HuMathSin(w->unk_3C) * 70.0f;
                        func_800191D4_19DD4(obj, 4, px, y, z + func_800B7890_B8490(w->unk_3C) * 70.0f, 0.0f, w->unk_3C + 180.0f);
                    }
                } else if (func_800B1830_B2430(rx * rx + ry * ry) > 43.0f && abs(sx) < 8 && abs(sy) < 8) {
                    if (fabs(w->unk_40) >= D_800BF7C4_C03C4) {
                        func_80019B9C_1A79C(obj, 0x11);
                        w->unk_40 = D_800BF7C8_C03C8;
                        func_8000C584_D184(w, 2);
                        px = x + HuMathSin(w->unk_3C) * 70.0f;
                        func_800191D4_19DD4(obj, 4, px, y, z + func_800B7890_B8490(w->unk_3C) * 70.0f, 0.0f, w->unk_3C + 180.0f);
                    }
                } else if (w->unk_40 == D_800BF7D0_C03D0) {
                    w->unk_C6 = 0;
                    func_80019B9C_1A79C(obj, 0);
                    if (w->unk_C4 > 0) {
                        func_80079848_7A448(w->unk_C5);
                        w->unk_C4 = -1;
                    }
                } else if (mag > D_800BF7C4_C03C4) {
                    anim = 2;
                    r2 = func_8000CF84_DB84(w->unk_59, 12, sx, sy);
                    if (r2 > 0) {
                        w->unk_C6++;
                        if (w->unk_C6 >= 0) {
                            if (w->unk_C6 >= 13) {
                                w->unk_C6 = 12;
                                anim = 4;
                            }
                        }
                    } else if (r2 < 0) {
                        w->unk_C6--;
                        if (w->unk_C6 < 0) {
                            if (w->unk_C6 < -12) {
                                w->unk_C6 = -12;
                                anim = 3;
                            }
                        }
                    } else {
                        w->unk_C6 = 0;
                    }
                    if (func_80019B9C_1A79C(obj, anim) == 1) {
                        func_8000C610_D210(w, 1);
                    } else {
                        frame6 = func_80029E3C_2AA3C(mdl);
                        if (frame6 == -1.0f) {
                            frame6 = func_80029CE4_2A8E4(mdl);
                        }
                        if (frame6 == 0.0f) {
                            func_8000C610_D210(w, 1);
                        }
                    }
                    if (MGW_UNK_BC(w) < 60) {
                        px = x - HuMathSin(w->unk_3C) * 20.0f;
                        func_800191D4_19DD4(obj, 3, px, y, z - func_800B7890_B8490(w->unk_3C) * 20.0f, 0.0f, w->unk_3C);
                    }
                    MGW_UNK_BC(w)++;
                    if (MGW_UNK_BC(w) > 200) {
                        MGW_UNK_BC(w) = 200;
                    }
                    if (w->unk_90 > D_800BF7C8_C03C8 || w->unk_98 > D_800BF7C8_C03C8) {
                        px = x - HuMathSin(w->unk_3C) * 20.0f;
                        func_800191D4_19DD4(obj, 3, px, y, z - func_800B7890_B8490(w->unk_3C) * 20.0f, 0.0f, w->unk_3C);
                    }
                } else {
                    w->unk_C6 = 0;
                    if (func_80019B9C_1A79C(obj, 1) == 1) {
                        func_8000C610_D210(w, 0);
                    } else {
                        frame6 = func_80029E3C_2AA3C(mdl);
                        if (frame6 == -1.0f) {
                            frame6 = func_80029CE4_2A8E4(mdl);
                        }
                        if (frame6 == 0.0f) {
                            func_8000C610_D210(w, 0);
                        }
                    }
                    MGW_UNK_BC(w) = 0;
                }
            }
        }
    } else if (flags & 0x20000) {
        o7 = D_800FC7B0_FD3B0[w->unk_53];
        y -= 20.0f;
        if (y < o7->trans.y - 75.0f) {
            y = o7->trans.y - 75.0f;
        }
        if (w->unk_40 > D_800BF7D0_C03D0) {
            w->unk_40 -= D_800BF7A0_C03A0;
            if (w->unk_40 <= D_800BF7D0_C03D0) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        } else if (w->unk_40 < D_800BF7D0_C03D0) {
            w->unk_40 += D_800BF7A0_C03A0;
            if (D_800BF7D0_C03D0 <= w->unk_40) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        }
        if (obj->model[2] != 0) {
            func_80029714_2A314(obj->model[2], x, o7->trans.y - 64.0f, z);
            func_800297E8_2A3E8(obj->model[2], 6.0f, 6.0f, 6.0f);
        }
    } else if (flags & 0xC0000) {
        if (flags & 0x40000) {
            func_8000B298_BE98(obj, x, y, z);
        } else {
            func_8000B4D8_C0D8(obj, x, y, z);
        }
        if (w->unk_40 < D_800BF7D0_C03D0) {
            w->unk_40 += D_800BF7A0_C03A0 * 2.0f;
            if (D_800BF7D0_C03D0 < w->unk_40) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        } else if (D_800BF7D0_C03D0 < w->unk_40) {
            w->unk_40 += -D_800BF7A0_C03A0 * 2.0f;
            if (w->unk_40 < D_800BF7D0_C03D0) {
                w->unk_40 = D_800BF7D0_C03D0;
            }
        }
        ny = func_8000312C_3D2C(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
        }
    } else if (flags & 0x1000) {
        w->unk_40 = D_800BF7D0_C03D0;
    } else if (flags & 0x200000) {
        if (w->unk_104[20] != 0) {
            /* host: a hook pointer kept in an s32 slot */
            ((void (*)(omObjData*, f32*, f32*, f32*))w->unk_104[20])(obj, &x, &y, &z);
        }
    }
    mag = w->unk_40;
    if (w->unk_50 & 6) {
        mag *= 0.6f;
    }
    mag *= (vy0 != 1000.0f) ? w->unk_4C * w->unk_B4 : w->unk_B4;
    x += HuMathSin(w->unk_3C) * mag + D_800F94A0_FA0A0;
    z += func_800B7890_B8490(w->unk_3C) * mag + D_80101308_101F08;
    func_800B2060_B2C60((f32 (*)[4])D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->unk_3C, 0.0f);
    func_8000C35C_CF5C(obj, x, y, z);
    if (w->unk_104[1] != 0) {
        /* host: a hook pointer kept in an s32 slot */
        ((void (*)(omObjData*))w->unk_104[1])(obj);
    }
    func_80019378_19F78(obj);
    func_80019644_1A244(obj);
}

#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80007790_8390);
#endif

/* Adds a push of d along (dx, 0, dz) normalised (MP1 func_800078E8). */
void func_80009684_A284(f32 dx, f32 dz, f32 d) {
    Vec3f v;

    v.x = dx;
    v.y = 0.0f;
    v.z = dz;
    func_8002D9AC_2E5AC(&v);
    D_800F94A0_FA0A0 += d * v.x;
    D_80101308_101F08 += d * v.z;
}

/* Run speed cap for a stick speed: rounded up to the next of the three speed steps
   (MP1 func_80007954). */
f32 func_800096F0_A2F0(f32 speed) {
    if (speed < D_800BF7CC_C03CC) {
        return D_800BF7CC_C03CC;
    }
    if (speed < D_800BF7C8_C03C8) {
        return D_800BF7C8_C03C8;
    }
    if (speed < D_800BF7C4_C03C4) {
        return D_800BF7C4_C03C4;
    }
    return speed;
}

/* MP1 func_800079A8: motion 0x10 on a type-2 ground object; puts model[2] at (x, y, z). */
void func_80009744_A344(omObjData* obj, f32 x, f32 y, f32 z) {
    MgWork* w = obj->unk_50;
    u8 slot;

    func_80019B9C_1A79C(obj, 0x10);
    slot = ((u8*)w->unk_20)[3]; /* 0x23, in MgWork.unk_20 padding: an effect slot (cf. ColActorWork.unk_24) */
    func_800212A4_21EA4(slot);
    func_80021160_21D60(slot, 4, 4);
    func_80029714_2A314(obj->model[2], x, y, z);
    w->unk_40 = D_800BF7D0_C03D0;
    func_8000C398_CF98();
}

/* MP1 func_80007A50: between motion frames 28 and 29 the held item is thrown (func_8000D81C_E41C). */
void func_800097EC_A3EC(omObjData* obj) {
    MgWork* w = obj->unk_50;
    f32 frame = func_80029E3C_2AA3C(obj->model[0]);
    s32 a, b;

    if (frame == -1.0f) {
        frame = func_80029CE4_2A8E4(obj->model[0]);
    }
    a = !(frame >= 28.0f) ? 0 : 1;
    b = !(frame <= 29.0f) ? 0 : 1;
    if (a & b) {
        func_8000D81C_E41C(obj, (w->unk_40 + D_800BF7C8_C03C8) * w->unk_CC);
    }
}

/* MP1 func_80007B34: a player's attack (motion frames 16-20) against the other players and the
   item actors, then a wall push for the attack point. */
// register allocation (masked 0): dx and dz swap $f20 / $f22
#ifdef NON_MATCHING
void func_800098D0_A4D0(omObjData* obj, f32 x, f32 y, f32 z) {
    Vec4f v;
    MgWork* w = obj->unk_50;
    MgWork* ow;
    ColActorWork* aw;
    omObjData* o;
    f32 frame;
    f32 rot;
    f32 len;
    f32 nx, ny, nz;
    f32 dx, dy, dz;
    u16 i;

    frame = func_80029E3C_2AA3C(*obj->model);
    if (frame == -1.0f) {
        frame = func_80029CE4_2A8E4(*obj->model);
    }
    if ((frame < 16.0f) | (frame > 20.0f)) {
        return;
    }
    if (w->unk_BE != 0) {
        D_800FD7FC_FE3FC++;
        return;
    }
    if (w->unk_50 & 0x400) {
        return;
    }
    len = w->unk_64 + w->unk_48;
    rot = w->unk_3C;
    nx = x + HuMathSin(rot) * len;
    ny = y;
    nz = z + func_800B7890_B8490(rot) * len;
    w->unk_F0 = 1;
    for (i = 0; i < D_800FC87A_FD47A; i++) {
        o = D_800FFFD8_100BD8[i];
        ow = o->unk_50;
        if (!(ow->unk_5C & 0x8C00) && !(ow->unk_50 & 7) && ow->unk_BE == 0 && !(ow->unk_50 & 0x400)) {
            if (w == ow) {
                continue;
            }
            if (func_8000B770_C370(obj, o) != 1) {
                continue;
            }
            dx = o->trans.x - nx;
            dy = o->trans.y - ny;
            dz = o->trans.z - nz;
            if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < ow->unk_48 + 30.0f) {
                func_8000B7AC_C3AC(obj, o, dx, dz, i);
            }
        }
    }
    if (!(w->unk_50 & 0x17)) {
        for (i = 0; i < D_800FA606_FB206; i++) {
            o = D_800F9CE0_FA8E0[i];
            aw = o->unk_50;
            if (!(aw->unk_50 & 0x20)) {
                continue;
            }
            if (!(aw->unk_50 & 0x10)) {
                if (w->unk_BE != 0) {
                    D_800FD7FC_FE3FC++;
                } else {
                    dx = o->trans.x - nx;
                    dy = o->trans.y - ny;
                    dz = o->trans.z - nz;
                    len = func_800B1830_B2430(dx * dx + dy * dy + dz * dz) - (aw->unk_48 + w->unk_48);
                    if (len < 0.0f && (w->unk_EC == NULL || w->unk_EC(obj, o) != 1)) {
                        func_8000D900_E500(obj, o);
                    }
                }
            }
        }
    }
    v.x = HuMathSin(rot) * w->unk_48 + obj->trans.x;
    v.y = ny;
    v.z = func_800B7890_B8490(rot) * w->unk_48 + obj->trans.z;
    v.w = w->unk_64;
    w->unk_55 = WALL_PUSH(obj, &v, -D_800BF7C0_C03C0);
    if (D_800BF796_C0396 != 0 && func_8000C098_CC98(D_800FD7F4_FE3F4) == 1) {
        dx = func_800B75A8_B81A8(D_800F9D40_FA940[0].x - obj->trans.x, D_800F9D40_FA940[0].z - obj->trans.z);
        func_800191D4_19DD4(obj, 6, nx, ny, nz, 0.0f, dx + 180.0f);
    }
    D_800BF796_C0396 = 0;
    D_800F94A0_FA0A0 = D_80101308_101F08 = 0.0f;
}

#else
INCLUDE_ASM("asm/nonmatchings/1130", func_800098D0_A4D0);
#endif

/* Records contact normal number D_800BF796_C0396, normalised. */
void func_80009DB0_A9B0(f32 x, f32 y, f32 z) {
    s16 i = D_800BF796_C0396;

    D_800FD8C8_FE4C8[i].x = x;
    D_800FD8C8_FE4C8[i].y = y;
    D_800FD8C8_FE4C8[i].z = z;
    func_8002D9AC_2E5AC(&D_800FD8C8_FE4C8[i]);
}

/* Records contact point number D_800BF796_C0396. */
void func_80009E0C_AA0C(f32 x, f32 y, f32 z) {
    s16 i = D_800BF796_C0396;

    D_800F9D40_FA940[i].x = x;
    D_800F9D40_FA940[i].y = y;
    D_800F9D40_FA940[i].z = z;
}

/* Movement tuning debug menu for port 0 (MP1 func_800081C0): C buttons turn and zoom the camera, L/R
   pick a row (only row 0 is reachable), A/B toggle the homing camera or step the selected value.
   Retail bug: w is only set by the loops in rows 9 and 10, so the homing camera writes through an
   unset pointer (host hazard). */
void func_80009E48_AA48(omObjData* obj, s32 port) {
    MgWork* w;
    s32 i;
    f32 cy;

    if (port != 0) {
        return;
    }
    if (ContBtn[port] & 0x10) {
        D_800FA610_FB210 -= 20.0f;
    }
    if (ContBtn[port] & 0x20) {
        D_800FA610_FB210 += 20.0f;
    }
    if (ContBtn[port] & 8) {
        D_800FD474_FE074.x += 0.3f;
    }
    if (ContBtn[port] & 4) {
        D_800FD474_FE074.x -= 0.3f;
    }
    if (ContBtn[port] & 1) {
        D_800FD474_FE074.y += 1.0f;
    }
    if (ContBtn[port] & 2) {
        D_800FD474_FE074.y -= 1.0f;
    }
    if (ContBtnTrg[port] & 0x800) {
        D_800BF7E0_C03E0--;
    } else if (ContBtnTrg[port] & 0x400) {
        D_800BF7E0_C03E0++;
    }
    if (D_800BF7E0_C03E0 < 0) {
        D_800BF7E0_C03E0 = 0;
    }
    if (D_800BF7E0_C03E0 > 0) {
        D_800BF7E0_C03E0 = 0;
    }
    switch (D_800BF7E0_C03E0) {
        case 0:
            if (ContBtnTrg[port] & 0x300) {
                if (D_800BF79B_C039B != 0) {
                    D_800BF79B_C039B = 0;
                } else {
                    D_800BF79B_C039B = 1;
                }
            }
            break;
        case 2:
            if (ContBtn[port] & 0x100) {
                D_800BF79C_C039C += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF79C_C039C -= 0.1f;
            }
            if (D_800BF79C_C039C > 50.0f) {
                D_800BF79C_C039C = 50.0f;
            }
            if (D_800BF79C_C039C < 1.0f) {
                D_800BF79C_C039C = 1.0f;
            }
            break;
        case 3:
            if (ContBtn[port] & 0x100) {
                D_800BF7A0_C03A0 += 0.001f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7A0_C03A0 -= 0.001f;
            }
            if (D_800BF7A0_C03A0 > 0.999f) {
                D_800BF7A0_C03A0 = 0.999f;
            }
            if (D_800BF7A0_C03A0 < 0.001f) {
                D_800BF7A0_C03A0 = 0.001f;
            }
            break;
        case 4:
            if (ContBtn[port] & 0x100) {
                D_800BF7A4_C03A4 += 0.01f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7A4_C03A4 -= 0.01f;
            }
            if (D_800BF7A4_C03A4 > 2.0f) {
                D_800BF7A4_C03A4 = 2.0f;
            }
            if (D_800BF7A4_C03A4 < 0.7f) {
                D_800BF7A4_C03A4 = 0.7f;
            }
            break;
        case 5:
            if (ContBtn[port] & 0x100) {
                D_800BF7A8_C03A8 += 0.001f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7A8_C03A8 -= 0.001f;
            }
            if (D_800BF7A8_C03A8 > 0.2f) {
                D_800BF7A8_C03A8 = 0.2f;
            }
            if (D_800BF7A8_C03A8 < 0.01f) {
                D_800BF7A8_C03A8 = 0.01f;
            }
            break;
        case 6:
            if (ContBtn[port] & 0x100) {
                D_800BF7AC_C03AC += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7AC_C03AC -= 0.1f;
            }
            if (D_800BF7AC_C03AC > 30.0f) {
                D_800BF7AC_C03AC = 30.0f;
            }
            if (D_800BF7AC_C03AC < 0.0f) {
                D_800BF7AC_C03AC = 0.0f;
            }
            break;
        case 7:
            if (ContBtn[port] & 0x100) {
                D_800BF7B0_C03B0 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7B0_C03B0 -= 0.1f;
            }
            if (D_800BF7B0_C03B0 > 100.0f) {
                D_800BF7B0_C03B0 = 100.0f;
            }
            if (D_800BF7B0_C03B0 < 20.0f) {
                D_800BF7B0_C03B0 = 20.0f;
            }
            break;
        case 8:
            if (ContBtn[port] & 0x100) {
                D_800BF7C0_C03C0 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7C0_C03C0 -= 0.1f;
            }
            if (D_800BF7C0_C03C0 > 30.0f) {
                D_800BF7C0_C03C0 = 30.0f;
            }
            if (D_800BF7C0_C03C0 < 10.0f) {
                D_800BF7C0_C03C0 = 10.0f;
            }
            D_800BF7CC_C03CC = D_800BF7C0_C03C0 / 4.0f;
            D_800BF7C8_C03C8 = D_800BF7C0_C03C0 / 2.0f;
            D_800BF7C4_C03C4 = D_800BF7CC_C03CC * 3.0f;
            D_800BF7BC_C03BC = 60.0f / D_800BF7C0_C03C0;
            break;
        case 9:
            if (ContBtn[port] & 0x100) {
                D_800BF7B4_C03B4 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7B4_C03B4 -= 0.1f;
            }
            if (D_800BF7B4_C03B4 > 100.0f) {
                D_800BF7B4_C03B4 = 100.0f;
            }
            if (D_800BF7B4_C03B4 < 40.0f) {
                D_800BF7B4_C03B4 = 40.0f;
            }
            for (i = 0; i < D_800FC87A_FD47A; i++) {
                w = D_800FFFD8_100BD8[i]->unk_50;
                w->unk_48 = D_800BF7B4_C03B4;
            }
            break;
        case 10:
            if (ContBtn[port] & 0x100) {
                D_800BF7B8_C03B8 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800BF7B8_C03B8 -= 0.1f;
            }
            if (D_800BF7B8_C03B8 > 100.0f) {
                D_800BF7B8_C03B8 = 100.0f;
            }
            if (D_800BF7B8_C03B8 < 10.0f) {
                D_800BF7B8_C03B8 = 40.0f;
            }
            for (i = 0; i < D_800FC87A_FD47A; i++) {
                w = D_800FFFD8_100BD8[i]->unk_50;
                w->unk_64 = D_800BF7B8_C03B8;
            }
            break;
    }
    fontcolor = 15;
    sprintf(pfStrBuf, "*");
    DrawDebugText(16, (D_800BF7E0_C03E0 + 2) * 8, pfStrBuf);
    sprintf(pfStrBuf, "CAMERA :[%s]", D_800BF79B_C039B ? "HOMING" : "LOCK");
    DrawDebugText(24, 16, pfStrBuf);
    if (D_800BF79B_C039B != 0) {
        cy = D_800FC834_FD434[obj->model[1]].pos.y;
        if (cy != D_8010274C_10334C.y) {
            cy = D_8010274C_10334C.y + (cy - D_8010274C_10334C.y) / 20.0f;
        }
        D_8010274C_10334C.x = D_800FC834_FD434[obj->model[1]].pos.x;
        D_8010274C_10334C.y = cy;
        D_8010274C_10334C.z = D_800FC834_FD434[obj->model[1]].pos.z;
        w->unk_60 = D_800FD474_FE074.y;
    }
}
