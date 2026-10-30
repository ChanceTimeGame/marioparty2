#include "ovl_0E.h"

void func_801063D0_140760_BowlOver(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    D_800F94A8_FA0A8[cam] = zoom;
    D_80102770_103370[cam].x = rx;
    D_80102770_103370[cam].y = ry;
    D_80102770_103370[cam].z = rz;
    D_801013B0_101FB0[cam].x = cx;
    D_801013B0_101FB0[cam].y = cy;
    D_801013B0_101FB0[cam].z = cz;
}

/* Fades out and returns once the minigame is over. */
void func_80106450_1407E0_BowlOver(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_80109A20_143DB0_BowlOver == 0) {
            InitFadeOut(0, 20);
            D_80109A20_143DB0_BowlOver = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(40);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* The shell's shadow: shrinks with height. */
// load scheduling: retail loads obj->model between the sub.s and the cvt.d (masked 2, as MP1's twin)
#ifdef NON_MATCHING
void func_801064C8_140858_BowlOver(omObjData* obj) {
    f32 s;

    s = (0.4f - obj->trans.y * 0.0015f) * 2.5;
    func_800297E8_2A3E8(obj->model[1], s, 1.0f, s);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/140760", func_801064C8_140858_BowlOver);
#endif

/* The bowler lets go of the shell at (x, y, z). */
void func_8010655C_1408EC_BowlOver(omObjData* obj, f32 x, f32 y, f32 z) {
    BOPlayerWork* w;
    omObjData* ball;
    BOBallWork* bw;

    w = BO_WORK(obj);
    ball = w->unk_C8;
    bw = BO_BALL_WORK(ball);
    w->unk_50 &= ~0x10;
    bw->unk_50 &= ~0x10;
    func_800298A4_2A4A4(ball->model[0], 0x4000, 0);
    func_8002C570_2D170(obj->model[0]);
    bw->unk_38 = -D_80109A24_143DB4_BowlOver * 0.8f;
    bw->unk_3C = w->unk_3C;
    ball->trans.x = x;
    ball->trans.y = y;
    ball->trans.z = z;
    w->unk_C8 = NULL;
    w->unk_B4 = 1.0f;
}

/* The bowler picks the shell up (touch hook): 1 when it does. */
s32 func_80106648_1409D8_BowlOver(omObjData* obj, omObjData* ball) {
    BOPlayerWork* w;
    BOBallWork* bw;
    u16 f;

    w = BO_WORK(obj);
    bw = BO_BALL_WORK(ball);

    if (bw->unk_50 & 0x20) {
        if (!(((volatile BOBallWork*)bw)->unk_50 & 0x10)) { /* retail reloads the flags */
            f = w->unk_50;
            if (f & 0x10) {
                return 0;
            }
            w->unk_50 = f | 0x10;
            bw->unk_50 |= 0x10;
            w->unk_C8 = ball;
            func_8002C628_2D228(ball->model[0], obj->model[0], "item_hook");
            func_800298A4_2A4A4(ball->model[0], 0x4000, 0x4000);
            w->unk_B4 = bw->unk_74;
            return 1;
        }
    }
    return 0;
}

/* Unreferenced (between "item_hook" and the alley limits). */
const f32 D_80109BA4_143F34_BowlOver[3] = { 259.22601318359375f, -281.0872497558594f, -354.08843994140625f };

/* The bowler's stick direction averaged over 8 frames (degrees), -1 when centred. */
f32 func_80106704_140A94_BowlOver(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    s16 i;
    f32 sx;
    f32 sy;

    port = BO_WORK(D_800FFFD8_100BD8[0])->unk_57;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    D_80109A28_143DB8_BowlOver[D_80109A38_143DC8_BowlOver] = (f32)x;
    D_80109A30_143DC0_BowlOver[D_80109A38_143DC8_BowlOver] = (f32)y;
    D_80109A38_143DC8_BowlOver = ((u8)D_80109A38_143DC8_BowlOver + 1) & 7;
    sx = 0.0f;
    sy = 0.0f;
    for (i = 0; i < 8; i++) {
        sx += D_80109A28_143DB8_BowlOver[i];
        sy += D_80109A30_143DC0_BowlOver[i];
    }
    sx /= 8.0f;
    sy /= 8.0f;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B75A8_B81A8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

/* The bowler's stick direction this frame (degrees), -1 when centred. */
f32 func_801068D0_140C60_BowlOver(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    f32 sx;
    f32 sy;

    port = BO_WORK(D_800FFFD8_100BD8[0])->unk_57;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    sx = x;
    sy = y;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B75A8_B81A8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

/* Alley edges per alley (left, right). */
const f32 D_80109BB0_143F40_BowlOver[3][2] = {
    { -435.330810546875f, 369.9980163574219f }, { -325.0f, 437.3025207519531f }, { -450.1575012207031f, 322.17047119140625f }
};

/* The rolling shell against the alley: on the lane (z > -4650) it drops off a side with no floor
   under it (bounce -20/20, near the bowler) or plays the gutter sound once (past z -1020); at the pins it is kept inside the
   alley's edges (bounce 30). 1 when it bounced. */
s16 func_801069D0_140D60_BowlOver(omObjData* obj, f32* dx, f32* dz) {
    BOProbe probe;
    s32 hit;

    hit = 0;
    if (D_8010996C_143CFC_BowlOver == 0) {
        if (obj->trans.z > -4650.0f) {
            if (obj->trans.z < -1020.0f) {
                probe.pos.x = obj->trans.x;
                probe.pos.y = obj->trans.y;
                probe.pos.z = obj->trans.z;
                probe.hit = 0;
                func_8002F2C4_2FEC4(D_800FC7B0_FD3B0[0]->model[0], D_800F9D30_FA930, func_80005110_5D10, &probe);
                if (func_8002F848_30448(D_800F9D30_FA930) == NULL && D_8010996C_143CFC_BowlOver == 0) {
                    PlaySound(0x180);
                    D_8010996C_143CFC_BowlOver = 1;
                }
                return hit;
            } else {
                probe.pos.x = obj->trans.x + 80.0f;
                probe.pos.y = obj->trans.y;
                probe.pos.z = obj->trans.z;
                probe.hit = 0;
                func_8002F2C4_2FEC4(D_800FC7B0_FD3B0[0]->model[0], D_800F9D30_FA930, func_80005110_5D10, &probe);
                if (func_8002F848_30448(D_800F9D30_FA930) == NULL) {
                    *dx = -20.0f;
                } else {
                    probe.pos.x = obj->trans.x - 80.0f;
                    probe.pos.y = obj->trans.y;
                    probe.pos.z = obj->trans.z;
                    probe.hit = 0;
                    func_8002F2C4_2FEC4(D_800FC7B0_FD3B0[0]->model[0], D_800F9D30_FA930, func_80005110_5D10, &probe);
                    if (func_8002F848_30448(D_800F9D30_FA930) != NULL) {
                        return hit;
                    }
                    *dx = 20.0f;
                }
            }
        } else {
            f32 lim = D_80109BB0_143F40_BowlOver[D_80109A40_143DD0_BowlOver][0] + 50.0f;

            if (obj->trans.x + *dx < lim) {
                obj->trans.x = lim;
                *dx = 30.0f;
            } else {
                lim = D_80109BB0_143F40_BowlOver[D_80109A40_143DD0_BowlOver][1] - 50.0f;
                if (!(lim < obj->trans.x + *dx)) {
                    return hit;
                }
                obj->trans.x = lim;
                *dx = -30.0f;
            }
        }
        hit = 1;
        PlaySound(0x187);
    }
    return hit;
}

/* Rotation of angle about axis, translated (retail uses pos->z where pos->x would be expected). */
// byte-identical code, but with this function in C the KMC assembler's mul fix puts a stray nop at the
// start of the file's .text (every function moves by 4)
#ifdef NON_MATCHING
void func_80106C94_141024_BowlOver(Vec3f* pos, Vec3f* axis, f32 angle, Matrix4f m) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 py;
    f32 pz;
    f32 pxy;
    f32 pyz;
    f32 pxz;

    func_800B8070_B8C70(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    pxy = x * y;
    pyz = y * z;
    pxz = z * x;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[0][0] = t * xx + c;
    xy = t * pxy;
    m[0][1] = xy + zs;
    xz = t * pxz;
    m[0][2] = xz - ys;
    m[1][0] = xy - zs;
    m[1][1] = t * yy + c;
    yz = t * pyz;
    m[1][2] = yz + xs;
    m[2][0] = xz + ys;
    m[2][1] = yz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - xy) - pz * (xz + ys);
    m[3][1] = -pz * (xy + zs) + py * t * (1.0f - yy) + pz * (xs - yz);
    m[3][2] = pz * (ys - xz) - py * (yz + xs) + pz * t * (1.0f - zz);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/140760", func_80106C94_141024_BowlOver);
#endif

/* Park-Miller step (16807 mod 2^31 - 1); a zero seed is re-seeded from rand8 and guRandom. */
s32 func_80106E8C_14121C_BowlOver(u32 seed) {
    u32 hi;
    u32 lo;

    if (seed == 0) {
        seed = rand8();
        seed ^= guRandom();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    return seed - lo * 16807;
}

u32 func_80106F60_1412F0_BowlOver(void) {
    return D_80109A3C_143DCC_BowlOver = func_80106E8C_14121C_BowlOver(D_80109A3C_143DCC_BowlOver);
}

/* retail pads the file's .rodata to 16 */
__asm__(".section .rodata\n\t.balign 16\n\t.text");
