#include "common.h"
#include "game/data.h"
#include "game/hmfman.h"

/* Actor motion helpers. Functions with C come from MP1 src/18650.c and MP3
   src/overlays/minigame/B7600.c; MP2's actor work is laid out differently (offsets below). */

typedef struct MotionEntry {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 speed;
    /* 0x04 */ u16 unk_04; /* passed on as MotionReq::unk_06 (s16) */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08; /* key func_80019FA4_1ABA4 looks up */
} MotionEntry; // size 0xC

typedef struct MotionReq {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 motion;
    /* 0x04 */ char unk_04[2];
    /* 0x06 */ s16 unk_06; /* < 0: none; else the 4th argument of func_80025554_26154 */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 speed;
} MotionReq; // size 0x10

typedef struct ActorWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ char unk_3C[0x14];
    /* 0x50 */ u16 flags; /* 1, 2, 4: squash animation */
    /* 0x52 */ u8 unk_52; /* motion changes locked */
    /* 0x53 */ char unk_53[6];
    /* 0x59 */ s8 player;
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ u8 unk_5B;
    /* 0x5C */ s32 unk_5C; /* func_80019000_19C00's motion class */
    /* 0x60 */ char unk_60[0x2C];
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ char unk_90[0x18];
    /* 0xA8 */ u16 unk_A8; /* squash timer */
    /* 0xAA */ char unk_AA[2];
    /* 0xAC */ f32 unk_AC;
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ f32 unk_B8;
    /* 0xBC */ char unk_BC[2];
    /* 0xBE */ u16 unk_BE; /* blink timer */
    /* 0xC0 */ char unk_C0[2];
    /* 0xC2 */ u8 unk_C2; /* blink phase */
    /* 0xC3 */ char unk_C3[5];
    /* 0xC8 */ void* unk_C8; /* MgWork's held item: a pointer, so the host layout agrees */
    /* 0xCC */ char unk_CC[4];
    /* 0xD0 */ u16 cur;
    /* 0xD2 */ u16 count;
    /* 0xD4 */ char unk_D4[2];
    /* 0xD6 */ u16 pending;
    /* 0xD8 */ MotionReq req;
    /* 0xE8 */ MotionEntry* table;
} ActorWork;


void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16); /* 2AA14.c: u8; retail callers re-extend the result */
void func_8002C524_2D124(s16, s16, s16);
s32 func_8002C8B8_2D4B8(void*, s32);
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_80019E04_1AA04(omObjData* obj, s32 a, s32 b);
void func_80019114_19D14(u8 mdl);
u16 func_80018FF0_19BF0(omObjData* obj);
void func_800192E4_19EE4(omObjData* obj);
void func_80025554_26154(s32, s32, s32, s16);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_80029FBC_2ABBC(s16, f32);
f32 func_80029E3C_2AA3C(s16);
f32 func_8002CA14_2D614(s32);
s16 func_80018ACC_196CC(s32);
s32 func_80025684_26284(s32 id); /* 26284.c: s16; retail callers re-extend the result */
void func_8002C6F4_2D2F4(HmfModel*, u16);
void func_80019B28_1A728(omObjData* obj, u8 flags);
void func_80019178_19D78(omObjData* obj);
s16 func_80019FA4_1ABA4(omObjData* obj, s32 id);
void func_80019B44_1A744(MotionReq* req, u16 flags, u16 motion, u16 speed, s16 arg4);
s32 func_80019B88_1A788(ActorWork* w, u16 motion);
extern u16 D_800FD7FC_FE3FC; /* MP1 D_800F370C */
extern s32 D_800C9A70_CA670[][10]; /* per character */
/* Per-character data (D_800CD438_CE038, 0x18 bytes each). */
typedef struct ActorCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ char unk_08[0x10];
} ActorCharData;
extern ActorCharData D_800CD438_CE038[];

u16 func_80018FF0_19BF0(omObjData* obj) {
    return ((ActorWork*)obj->unk_50)->req.motion & 0x3FFF;
}

/* MP1 func_80017A60: the current motion's class as a flag (0 when idle), also kept in unk_5C. */
s32 func_80019000_19C00(omObjData* obj) {
    ActorWork* w = obj->unk_50;
    s32 flags;
    u16 mot;

    if (w->cur == 0xFFFF) {
        return 1;
    } else {
        switch (mot = func_80018FF0_19BF0(obj)) {
            case 0:
            case 11:
            case 24:
                flags = 2;
                break;
            case 16:
                flags = 0x20000;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                flags = 4;
                break;
            case 25:
            case 27:
                flags = 8;
                break;
            case 26:
                flags = 0x10;
                break;
            case 6:
                flags = 0x20;
                break;
            case 20:
                flags = 0x80;
                break;
            case 5:
                flags = 0x40;
                break;
            case 7:
                flags = 0x100;
                break;
            case 8:
                flags = 0x200;
                break;
            case 21:
                flags = 0x10000;
                break;
            case 18:
            case 19:
            case 28:
            case 30:
            case 31:
            case 33:
            case 34:
                flags = 0x8000;
                break;
            case 9:
            case 12:
            case 29:
                flags = 0x400;
                break;
            case 10:
            case 23:
                flags = 0x800;
                break;
            case 13:
            case 14:
            case 15:
                flags = 0x1000;
                break;
            case 17:
                flags = 0x2000;
                break;
            case 32:
                flags = 0x4000;
                break;
            case 35:
                flags = 0x40000;
                break;
            case 36:
                flags = 0x80000;
                break;
            case 37:
                flags = 0x100000;
                break;
            default:
                /* motion 22 gives 0; any motion past 37 gives 0x200000 */
                flags = (mot >= 38) ? 0x200000 : 0;
                break;
        }
        w->unk_5C = flags;
    }
    return flags;
}

void func_80019114_19D14(u8 mdl) {
    f32 cur;

    if (mdl != 0) {
        cur = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= cur) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
}

void func_80019178_19D78(omObjData* obj) {
    s32 i;

    i = 3;
loop:
    if (i < obj->mdlcnt) {
        func_80019114_19D14(obj->model[i++]);
        if (i < 9) {
            goto loop;
        }
    }
}

void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b) {
    u8 mdl = obj->model[idx];
    f32 cur;

    if (obj->mdlcnt > idx) {
        if (mdl != 0) {
            cur = func_80029CE4_2A8E4(mdl);
            if (func_80029D0C_2A90C(mdl) <= cur) {
                if (D_800FC834_FD434[mdl].hmf->unk9C != NULL) {
                    D_800FC834_FD434[mdl].hmf->unk9C->unk08 = 0;
                }
                func_80029C74_2A874(mdl, 0.0f);
            }
            func_800298A4_2A4A4(mdl, 4, 0);
            func_80029714_2A314(mdl, x, y, z);
            func_8002979C_2A39C(mdl, a, b, 0.0f);
        }
    }
}

// flip held in a copy register and sign-extended in both arms only in retail (masked 11)
#ifdef NON_MATCHING
/* MP1 func_80017D1C: shows motion 22 (flipped with the request's flag 1). */
void func_800192E4_19EE4(omObjData* obj) {
    ActorWork* w = obj->unk_50;
    s16* motion = obj->motion;
    s32 flip = (w->req.flags & 1) * 2;

    if (w->table[22].flags & 4) {
        func_8002C524_2D124(obj->model[0], motion[22] & 0x3FFF, flip);
    } else {
        func_8002C524_2D124(obj->model[0], func_80029E14_2AA14(obj->motion[22] & 0x3FFF), flip);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/19BF0", func_800192E4_19EE4);
#endif

/* MP1 func_80017DB0 plus MP2's func_80025554_26154 call. Register allocation: req and spd swap
   s3/s4 (masked match otherwise). */
#ifdef NON_MATCHING
void func_80019378_19F78(omObjData* obj) {
    u16 mdl = obj->model[0];
    ActorWork* w = obj->unk_50;
    u16 spd;
    MotionReq* req;
    s16 mot;
    s32 flip;
    f32 t;
    s32 chr;
    MotionEntry* e;

    if (w->pending != 0) {
        chr = gPlayers[w->player].character;
        flip = 0;
        if (w->count != 0) {
            req = &w->req;
            if (req->flags & 4) {
                spd = (w->unk_B8 = func_8002CA14_2D614(mot = obj->motion[req->motion] & 0x3FFF)) / 5.0f;
            } else {
                mot = func_80029E14_2AA14(obj->motion[req->motion] & 0x3FFF);
                spd = (w->unk_B8 = func_80029D0C_2A90C(obj->motion[req->motion] & 0x3FFF)) / 5.0f;
            }
            if (req->flags & 1) {
                flip = 2;
            }
            if (req->unk_06 >= 0) {
                func_80025554_26154(w->unk_5A, w->unk_5B, chr, req->unk_06);
            }
            func_80029BF0_2A7F0(mdl, mot, 0, spd, flip);
            func_80029FBC_2ABBC(mdl, req->speed);
            if (w->flags & 0x100) {
                func_800192E4_19EE4(obj);
            }
        }
        w->pending = 0;
    } else {
        e = &w->table[func_80018FF0_19BF0(obj)];
        if (!(e->flags & 1)) {
            t = func_80029E3C_2AA3C(mdl);
            if (t == -1.0f) {
                t = func_80029CE4_2A8E4(mdl);
            }
            if (w->unk_B8 <= t) {
                w->cur++;
                if (w->count <= w->cur) {
                    w->count = 0;
                    w->cur = 0xFFFF;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019378_19F78);
#endif

/* MP1 func_8001802C (squash/stretch and blink) plus MP2's idle stretch. */
void func_80019644_1A244(omObjData* obj) {
    ActorWork* w = obj->unk_50;
    u16 lim1;
    u16 lim2;
    f32 sy;
    f32 sxz;
    f32 t;
    s32 off;
    u16 prev;

    if (w->flags & 7) {
        w->unk_A8 += 2;
        lim1 = 60;
        if (w->flags & 2) {
            lim2 = 106;
            sy = 0.6f;
            sxz = w->unk_AC * 1.4f;
        } else {
            lim1 = 120;
            lim2 = 166;
            sy = 0.1f;
            sxz = w->unk_AC * 1.6f;
            if (w->unk_A8 >= 120) {
                if (w->flags & 1) {
                    w->flags = (w->flags & ~1) | 4;
                }
            }
        }
        if (w->unk_A8 < lim2) {
            if (w->unk_A8 <= lim1) {
                obj->scale.x = (obj->scale.z = sxz);
                obj->scale.y = sy;
            } else if (w->unk_A8 <= (lim1 + 10)) {
                t = w->unk_A8 - lim1;
                obj->scale.y = (t * 0.05f) + 0.2;
                obj->scale.z = (obj->scale.x = 1.8 - (t * 0.08f));
            } else if (w->unk_A8 <= (lim1 + 20)) {
                t = w->unk_A8 - (lim1 + 10);
                obj->scale.y = 0.9 - (t * 0.05f);
                obj->scale.z = (obj->scale.x = (t * 0.05f) + 1.0);
            } else if (w->unk_A8 <= (lim1 + 30)) {
                t = w->unk_A8 - (lim1 + 20);
                obj->scale.y = (t * 0.05f) + 0.7;
                obj->scale.z = (obj->scale.x = 1.4 - (t * 0.04f));
            } else if (w->unk_A8 <= (lim1 + 38)) {
                t = w->unk_A8 - (lim1 + 30);
                obj->scale.y = 1.3 - (t * 0.1f);
                obj->scale.z = (obj->scale.x = (t * 0.02f) + 1.0);
            } else {
                t = w->unk_A8 - (lim1 + 38);
                obj->scale.y = (t * 0.1f) + 0.3;
                obj->scale.z = (obj->scale.x = 1.1 - (t * 0.01f));
            }
        } else {
            obj->scale.x = (obj->scale.y = (obj->scale.z = 1.0f));
            w->flags &= ~7;
            w->unk_A8 = 0;
        }
    } else if (w->unk_8C != 65536.0f) {
        if (w->unk_38 == 1000.0f) {
            if (obj->scale.y <= 0.5f) {
                func_80019B28_1A728(obj, 1);
            } else {
                obj->scale.y = w->unk_B0;
                obj->scale.x = (obj->scale.z = (1.0f - w->unk_B0) * 2.0f + 1.0f);
            }
        }
    } else {
        obj->scale.x = (obj->scale.y = (obj->scale.z = 1.0f));
        w->unk_B0 = 1.0f;
    }
    if (w->unk_BE != 0) {
        prev = w->unk_BE;
        w->unk_BE--;
        if (w->unk_BE == 0) {
            if (D_800FD7FC_FE3FC != 0) {
                w->unk_BE = prev;
            } else {
                w->unk_C2 = 1;
            }
        }
        prev = ((w->unk_C2 & 1) == 0) * 4;
        func_800298A4_2A4A4(obj->model[0], 4, off = prev);
        if (off != 0) {
            func_8002C6F4_2D2F4(&D_800FC834_FD434[obj->model[0]], 2);
        }
        w->unk_C2 = (w->unk_C2 + 1) & 3;
    }
    func_80019178_19D78(obj);
}

void func_80019B28_1A728(omObjData* obj, u8 flags) {
    ActorWork* w = obj->unk_50;

    w->flags |= flags;
    w->unk_A8 = 0;
}

void func_80019B44_1A744(MotionReq* req, u16 flags, u16 motion, u16 speed, s16 arg4) {
    req->flags = flags;
    req->motion = motion;
    req->unk_08 = 0;
    req->speed = speed;
    req->unk_06 = arg4;
}

s32 func_80019B70_1A770(omObjData* obj, u16 motion) {
    return ((ActorWork*)obj->unk_50)->req.motion == motion;
}

s32 func_80019B88_1A788(ActorWork* w, u16 motion) {
    return w->req.motion == motion;
}

/* MP1 func_800184BC: starts `motion` unless the current one may not be interrupted. */
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion) {
    ActorWork* w = obj->unk_50;
    MotionEntry* e;
    s32 flags;
    s32 speed;
    s32 unk04;

    if (w->unk_52 == 0) {
        /* MP1's permuter shape: both arms are the same */
        if (obj || obj->unk_50) {
            e = &w->table[func_80018FF0_19BF0(obj)];
        } else {
            e = &w->table[func_80018FF0_19BF0(obj)];
        }
        if (w->cur == 0xFFFF || (!(e->flags & 2) && !func_80019B88_1A788(w, motion))) {
            e = &w->table[motion];
            if ((u16)obj->motion[motion] != 0xFFFF) {
                flags = e->flags;
                speed = e->speed;
                unk04 = e->unk_04;
                w->cur = 0;
                w->count = 1;
                func_80019B44_1A744(&w->req, flags, motion, speed, unk04);
                w->pending = 1;
                return 1;
            }
        }
    }
    return 0;
}

/* MP1 func_800185A4: starts `motion` unconditionally (unless locked or absent). */
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion) {
    ActorWork* w = obj->unk_50;
    MotionEntry* e;
    s32 flags;
    s32 speed;
    s32 unk04;

    if (w->unk_52 != 0 || (e = &w->table[motion], (u16)obj->motion[motion] == 0xFFFF)) {
        return 0;
    }
    flags = e->flags;
    speed = e->speed;
    unk04 = e->unk_04;
    w->cur = 0;
    w->count = 1;
    func_80019B44_1A744(&w->req, flags, motion, speed, unk04);
    w->pending = 1;
    return 1;
}

s32 func_80019D54_1A954(omObjData* obj, u16 motion, u16 next) {
    ActorWork* w = obj->unk_50;

    if (func_80019CA4_1A8A4(obj, motion) == 1) {
        func_80019E04_1AA04(obj, 22, next);
        w->flags |= 0x100;
        return 1;
    }
    return 0;
}

void func_80019DC0_1A9C0(omObjData* obj, s32 src, s32 dst) {
    obj->motion[dst] = obj->motion[src];
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019DE0_1A9E0);

/* MP1 func_800186E4: swaps motion slots a and b with their table entries. */
void func_80019E04_1AA04(omObjData* obj, s32 a, s32 b) {
    ActorWork* w = obj->unk_50;
    s32 tmp;
    MotionEntry* ea;
    MotionEntry* eb;
    u16 flags;
    u16 speed;
    u16 unk04;

    tmp = obj->motion[a];
    obj->motion[a] = obj->motion[b];
    obj->motion[b] = tmp;
    ea = &w->table[a];
    eb = &w->table[b];
    speed = ea->speed;
    flags = ea->flags;
    unk04 = ea->unk_04;
    ea->speed = eb->speed;
    ea->flags = eb->flags;
    ea->unk_04 = eb->unk_04;
    eb->speed = speed;
    eb->flags = flags;
    eb->unk_04 = unk04;
}

// register allocation of the flags/speed parameters (masked 0)
#ifdef NON_MATCHING
/* MP1 func_8001874C: loads motion file `file` into slot idx. */
void func_80019E84_1AA84(omObjData* obj, u16 idx, s32 file, s32 flags, u16 speed) {
    s16 mot;
    ActorWork* w;
    MotionEntry* e;

    mot = func_80018ACC_196CC(file);
    if (mot >= 0) {
        w = obj->unk_50;
        obj->motion[idx] = mot;
        e = &w->table[idx];
        e->flags = flags;
        e->speed = speed;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019E84_1AA84);
#endif

void func_80019F0C_1AB0C(omObjData* arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    ActorWork* temp_a1;
    MotionEntry* temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8002C8B8_2D4B8(DataRead(arg2), 0x18);
    if (temp_v0 < 0) {
        return;
    }
    temp_a1 = (ActorWork*)arg0->unk_50;
    arg0->motion[arg1] = temp_v0;
    temp_v0_2 = &temp_a1->table[arg1];
    temp_v0_2->flags = arg3 | 4;
    temp_v0_2->speed = arg4;
}

/* The motion already loaded for key `id`, else func_80025684_26284(id). */
s16 func_80019FA4_1ABA4(omObjData* obj, s32 id) {
    ActorWork* w = obj->unk_50;
    s32 i;

    for (i = 0; i < obj->mtncnt; i++) {
        if (w->table[i].unk_08 == id) {
            return w->table[i].unk_04;
        }
    }
    return func_80025684_26284(id);
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_8001A014_1AC14);

/* MP1 func_800187D0 plus the character's motion key (D_800C9A70_CA670) for slot `slot`. */
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 flags, u16 speed, s32 arg5) {
    s16 mot = func_8002C8B8_2D4B8(DataRead(file), 0x18);
    ActorWork* w;
    MotionEntry* e;
    s32 chr;
    s32 key;

    if (mot >= 0) {
        w = obj->unk_50;
        obj->motion[slot] = mot;
        e = &w->table[slot];
        e->flags = flags | 4;
        e->speed = speed;
        chr = gPlayers[w->player].character;
        key = D_800C9A70_CA670[chr][(s16)arg5] | D_800CD438_CE038[chr].unk_04;
        e->unk_04 = func_80019FA4_1ABA4(obj, key);
        e->unk_08 = key;
    }
}
