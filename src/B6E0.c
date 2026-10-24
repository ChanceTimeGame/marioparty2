#include "common.h"
#include "game/collision.h"

/* Minigame player actions (MP3 src/overlays/minigame/B63A0.c, asm there): each one first offers
   the minigame an override hook in the player's work block (hook returns 1 = handled), then does
   the default. The work block is MgWork (game/collision.h). */

extern f32 D_800BF7A4_C03A4; /* jump speed */
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
extern f32 D_800BF7D0_C03D0;
extern u8 D_800BF799_C0399;
extern u16 D_800FC87A_FD47A;           /* player object count */
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */

s32 func_80019B9C_1A79C(omObjData* obj, s32 motion);
void func_80019B28_1A728(omObjData* obj, u8 flags);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_8000C584_D184(MgWork* work, s32 state);
void func_8000CF58_DB58(omObjData* obj);
void func_8000D81C_E41C(omObjData* obj, f32 arg1);
void func_8000D9F4_E5F4(omObjData* obj);
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
void func_800097EC_A3EC(omObjData* obj);
void func_800098D0_A4D0(omObjData* obj, f32 x, f32 y, f32 z);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_8002C570_2D170(s16);
f32 func_80029E3C_2AA3C(s16);
f32 func_80029CE4_2A8E4(s16);
void func_80029714_2A314(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16 idx, f32 x, f32 y, f32 z);
void func_800298A4_2A4A4(s16, s32, s32);
void func_8003C984_3D584(s16 arg0, Vec* n);
f32 func_8002D958_2E558(f32 angle);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* HuMathCos */
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 func_800B75A8_B81A8(f32, f32); /* atan2 */
int abs(int);

void func_8000ABE8_B7E8(omObjData* obj, MgWork* work);
void func_8000B164_BD64(omObjData* obj, MgWork* work);

void func_8000AAE0_B6E0(omObjData* obj, MgWork* work) {
    if (work->unk_50 & 0x40) {
        if (work->unk_38 == 1000.0f && (work->unk_104[10] == NULL || work->unk_104[10](obj) != 1)) {
            func_80019B9C_1A79C(obj, 0x23);
        }
    } else {
        func_8000ABE8_B7E8(obj, work);
    }
}

void func_8000AB64_B764(omObjData* obj, MgWork* work) {
    if (work->unk_50 & 0x40) {
        if (work->unk_38 == 1000.0f && (work->unk_104[11] == NULL || work->unk_104[11](obj) != 1)) {
            func_80019B9C_1A79C(obj, 0x24);
        }
    } else {
        func_8000B164_BD64(obj, work);
    }
}

/* Jump. */
void func_8000ABE8_B7E8(omObjData* obj, MgWork* work) {
    if (work->unk_104[2] == NULL || work->unk_104[2](obj) != 1) {
        if (work->unk_B0 == 1.0f && func_80019B9C_1A79C(obj, 6) == 1) {
            work->unk_38 = -D_800BF7A4_C03A4;
            work->unk_50 &= ~0x80;
            func_8000C584_D184(work, 3);
        }
    }
}

void func_8000AC8C_B88C(omObjData* obj, MgWork* work, GroundWork* arg2, s16 x, s16 y) {
    if (work->unk_104[3] == NULL || work->unk_104[3](obj, arg2) != 1) {
        if (abs(x) < 8 && abs(y) < 8) {
            work->unk_40 = D_800BF7D0_C03D0;
            func_80019B9C_1A79C(obj, 0x15);
            func_8000C584_D184(work, 4);
            func_8000CF58_DB58(obj);
        } else {
            func_80019B9C_1A79C(obj, 1);
            work->unk_40 = D_800BF7C4_C03C4;
            func_8000C584_D184(work, 1);
        }
    }
}

void func_8000AD78_B978(omObjData* obj, MgWork* work) {
    s32 ret = func_80019B9C_1A79C(obj, 8);

    if (ret == 1 && (work->unk_104[5] == NULL || work->unk_104[5](obj) != ret)) {
        work->unk_40 = D_800BF7D0_C03D0;
        work->unk_38 = -D_800BF7A4_C03A4 * 0.1f;
        if (work->unk_50 & 0x10) {
            func_8000D81C_E41C(obj, D_800BF7CC_C03CC * 0.6f);
        }
        func_8000C584_D184(work, 0xA);
    }
}

void func_8000AE58_BA58(omObjData* obj, MgWork* work, GroundWork* arg2, f32 x, f32 y, f32 z) {
    if (work->unk_104[6] == NULL || work->unk_104[6](obj, arg2) != 1) {
        work->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
        func_800191D4_19DD4(obj, 7, x, y, z, 0.0f, 0.0f);
        func_800191D4_19DD4(obj, 8, x, y, z, 0.0f, 0.0f);
        work->unk_50 |= 0x80;
        func_8000C584_D184(work, 0xB);
        omVibrate(work->unk_59, 0xA, 0, 0xA);
    }
}

void func_8000AF60_BB60(omObjData* obj, MgWork* work, GroundWork* arg2, f32 x, f32 y, f32 z) {
    if (work->unk_104[7] == NULL || work->unk_104[7](obj, arg2) != 1) {
        func_80019B9C_1A79C(obj, 0x12);
        func_800191D4_19DD4(obj, 8, x, y, z, 0.0f, 0.0f);
        work->unk_50 &= ~0x80;
    }
}

void func_8000AFFC_BBFC(omObjData* obj, MgWork* work) {
    if (work->unk_104[14] == NULL || work->unk_104[14](obj) != 1) {
        if (work->unk_50 & 0x10) {
            if (func_80019B9C_1A79C(obj, 0x14) == 1) {
                work->unk_38 = -D_800BF7A4_C03A4 * 0.4f;
                func_8000D9F4_E5F4(obj);
                func_8000C584_D184(work, 0xC);
            }
        } else if (func_80019B9C_1A79C(obj, 7) == 1) {
            work->unk_38 = -D_800BF7A4_C03A4 * 0.4f;
            func_8000C584_D184(work, 6);
        }
    }
}

void func_8000B0E4_BCE4(omObjData* obj, f32 x, f32 y, f32 z) {
    MgWork* work = obj->unk_50;

    if (work->unk_104[15] == NULL || work->unk_104[15](obj) != 1) {
        func_800098D0_A4D0(obj, x, y, z);
    }
}

void func_8000B164_BD64(omObjData* obj, MgWork* work) {
    if (work->unk_104[8] == NULL || work->unk_104[8](obj) != 1) {
        if (work->unk_50 & 0x10) {
            if (func_80019B9C_1A79C(obj, 0x14) == 1) {
                func_8000D9F4_E5F4(obj);
                func_8000C584_D184(work, 0xC);
            }
        } else if (func_80019B9C_1A79C(obj, 5) == 1) {
            func_8000C584_D184(work, 5);
        }
    }
}

void func_8000B204_BE04(omObjData* obj, s32 flags, f32 x, f32 y, f32 z) {
    MgWork* work = obj->unk_50;

    if (work->unk_104[9] == NULL || work->unk_104[9](obj) != 1) {
        if (flags & 0x80) {
            func_800097EC_A3EC(obj);
        } else {
            func_800098D0_A4D0(obj, x, y, z);
        }
    }
}

/* Punch: during motion frames 30-50, knocks down every other player within reach. */
void func_8000B298_BE98(omObjData* obj, f32 x, f32 y, f32 z) {
    MgWork* work = obj->unk_50;
    omObjData* other;
    MgWork* otherWork;
    f32 time;
    f32 dx, dy, dz;
    s32 i;

    if (work->unk_104[12] == NULL || work->unk_104[12](obj, &x, &y, &z) != 1) {
        func_8002C570_2D170(obj->model[0]);
        time = func_80029E3C_2AA3C(obj->model[0]);
        if (time == -1.0f) {
            time = func_80029CE4_2A8E4(obj->model[0]);
        }
        if ((time >= 30.0f) & (time <= 50.0f)) {
            x += HuMathSin(work->unk_3C) * (work->unk_6C + work->unk_48);
            z += func_800B7890_B8490(work->unk_3C) * (work->unk_6C + work->unk_48);
            for (i = 0; i < D_800FC87A_FD47A; i++) {
                other = D_800FFFD8_100BD8[i];
                otherWork = other->unk_50;
                if (work != otherWork) {
                    dx = other->trans.x - x;
                    dy = other->trans.y - y;
                    dz = other->trans.z - z;
                    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < otherWork->unk_48 + work->unk_70) {
                        func_80019B28_1A728(other, 1);
                        func_80019B9C_1A79C(other, 0);
                        func_800191D4_19DD4(obj, 7, x, y, z, 0.0f, 0.0f);
                    }
                }
            }
        }
    }
}

/* Sweep: during motion frames 10-25, the reach turns with the motion and pushes back every
   other player within it. */
void func_8000B4D8_C0D8(omObjData* obj, f32 x, f32 y, f32 z) {
    MgWork* work = obj->unk_50;
    omObjData* other;
    MgWork* otherWork;
    f32 time;
    f32 angle;
    f32 dx, dy, dz;
    s32 i;

    if (work->unk_104[13] == NULL || work->unk_104[13](obj, &x, &y, &z) != 1) {
        func_8002C570_2D170(obj->model[0]);
        time = func_80029E3C_2AA3C(obj->model[0]);
        if (time == -1.0f) {
            time = func_80029CE4_2A8E4(obj->model[0]);
        }
        if ((time >= 10.0f) & (time <= 25.0f)) {
            angle = (work->unk_3C - 90.0f) + (time - 10.0f) * 12.0f;
            x += HuMathSin(angle) * (work->unk_6C + work->unk_48);
            z += func_800B7890_B8490(angle) * (work->unk_6C + work->unk_48);
            for (i = 0; i < D_800FC87A_FD47A; i++) {
                other = D_800FFFD8_100BD8[i];
                otherWork = other->unk_50;
                if (work != otherWork) {
                    dx = other->trans.x - x;
                    dy = other->trans.y - y;
                    dz = other->trans.z - z;
                    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < otherWork->unk_48 + work->unk_70) {
                        func_80019B9C_1A79C(other, 0x25);
                        otherWork->unk_40 = 2.0f * D_800BF7C0_C03C0;
                        otherWork->unk_3C = func_8002D958_2E558(func_800B75A8_B81A8(dx, dz) + 90.0f);
                        otherWork->unk_C0 = 90;
                    }
                }
            }
        }
    }
}

s32 func_8000B770_C370(omObjData* obj) {
    MgWork* work = obj->unk_50;

    if (work->unk_104[16] == NULL || work->unk_104[16](obj) != 1) {
        return 1;
    }
    return 0;
}

/* obj hits other (dx, dz: the hit direction): other is knocked back, away from or along obj's
   facing depending on which side it was hit from. */
void func_8000B7AC_C3AC(omObjData* obj, omObjData* other, f32 dx, f32 dz, u16 arg4) {
    MgWork* work = obj->unk_50;
    MgWork* otherWork = other->unk_50;
    f32 side;

    if (work->unk_104[17] == NULL || work->unk_104[17](obj) != 1) {
        if (!(otherWork->unk_50 & 0x200)) {
            side = func_8000DA2C_E62C(HuMathSin(otherWork->unk_3C), func_800B7890_B8490(otherWork->unk_3C), dx, dz);
            if (otherWork->unk_50 & 0x10) {
                func_8000D81C_E41C(other, D_800BF7C8_C03C8);
            }
            if (side < 0.0f) {
                func_80019B9C_1A79C(other, 0x1E);
                if (otherWork->unk_38 == 1000.0f) {
                    otherWork->unk_40 = -D_800BF7C0_C03C0;
                } else {
                    otherWork->unk_40 = -D_800BF7C0_C03C0;
                    otherWork->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
                }
                otherWork->unk_3C = func_8002D958_2E558(work->unk_3C + 180.0f);
            } else {
                func_80019B9C_1A79C(other, 0x1F);
                if (otherWork->unk_38 == 1000.0f) {
                    otherWork->unk_40 = D_800BF7C0_C03C0;
                } else {
                    otherWork->unk_40 = D_800BF7C0_C03C0;
                    otherWork->unk_38 = -D_800BF7A4_C03A4 * 0.6f;
                }
                otherWork->unk_3C = work->unk_3C;
            }
            func_800191D4_19DD4(obj, 6, other->trans.x, other->trans.y, other->trans.z, 0.0f,
                                func_800B75A8_B81A8(dx, dz) + 180.0f);
            func_8000C584_D184(work, 8);
            omVibrate(work->unk_59, 2, 3, 0xA);
            omVibrate(otherWork->unk_59, 0x14, 0, 0x14);
        }
        work->unk_54 = arg4;
        otherWork->unk_C3 = work->unk_59;
    }
}

/* Landing on ground at height `ground`. */
void func_8000BA38_C638(omObjData* obj, f32 ground) {
    MgWork* work = obj->unk_50;

    if (work->unk_104[4] == NULL || work->unk_104[4](obj, &ground) != 1) {
        if (work->unk_38 == 1000.0f) {
            work->unk_B0 = (work->unk_8C - ground) / work->unk_34;
        } else if (work->unk_38 < 0.0f) {
            work->unk_38 = D_800BF7A4_C03A4 * 0.1f;
        }
    }
}

/* The player's shadow (model 1): on the ground below (x, y, z), shrinking with the height, and
   flattened onto the ground's plane; hidden when there is no ground (-65536.0f). */
void func_8000BAF0_C6F0(omObjData* obj, f32 x, f32 y, f32 z, f32 ground, Vec* normal) {
    MgWork* work = obj->unk_50;
    f32 scale;

    if (work->unk_104[18] == NULL || work->unk_104[18](obj, &x, &y, &z, &ground, normal) != 1) {
        if (ground != -65536.0f) {
            if (y != ground) {
                if (D_800BF799_C0399 == 1) {
                    ground += 2.0f;
                }
                func_80029714_2A314(obj->model[1], x, ground, z);
                ground = y - ground;
                if (ground > 200.0f) {
                    scale = 0.6f;
                } else {
                    scale = 1.0 - fabs(ground) / 500.0;
                }
                func_800297E8_2A3E8(obj->model[1], scale, scale, scale);
            } else {
                if (D_800BF799_C0399 == 1) {
                    ground += 2.0f;
                }
                func_80029714_2A314(obj->model[1], x, ground, z);
            }
            func_8003C984_3D584(obj->model[1], normal);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
        } else {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
    }
}
