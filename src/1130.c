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

INCLUDE_ASM("asm/nonmatchings/1130", func_80007790_8390);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009684_A284);

INCLUDE_ASM("asm/nonmatchings/1130", func_800096F0_A2F0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009744_A344);

INCLUDE_ASM("asm/nonmatchings/1130", func_800097EC_A3EC);

INCLUDE_ASM("asm/nonmatchings/1130", func_800098D0_A4D0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009DB0_A9B0);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009E0C_AA0C);

INCLUDE_ASM("asm/nonmatchings/1130", func_80009E48_AA48);
