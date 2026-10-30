#include "common.h"
#include "ovl_0F.h"

/* .data (0x14C0E0-0x14C130, 8010A750-8010A7A0). D_8010A75C (inside D_8010A758) is an
   undefined_syms.txt alias. */

s8 D_8010A750_14C0E0_RainbowRun = 0;
s8 D_8010A751_14C0E1_RainbowRun = 0;
s16 D_8010A752_14C0E2_RainbowRun = 0;
f32 D_8010A754_14C0E4_RainbowRun = 0.0f;
f32 D_8010A758_14C0E8_RainbowRun[8] = { 10.0f, 10.0f, -10.0f, 10.0f, 10.0f, -10.0f, -10.0f, -10.0f };
s8 D_8010A778_14C108_RainbowRun = 0;
s8 D_8010A77C_14C10C_RainbowRun[8] = { 0 };
s8 D_8010A784_14C114_RainbowRun[8] = { 0 };
s8 D_8010A78C_14C11C_RainbowRun = 0;
u16 D_8010A78E_14C11E_RainbowRun = 0;
u32 D_8010A790_14C120_RainbowRun = 0;

void func_801057F0_147180_RainbowRun(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    D_800FA610_FB210 = D_8010AA10_14C3A0_RainbowRun = zoom;
    D_800FD474_FE074.x = D_8010AC10_14C5A0_RainbowRun = rx;
    D_800FD474_FE074.y = D_8010ABF8_14C588_RainbowRun = ry;
    D_800FD474_FE074.z = D_8010ABF4_14C584_RainbowRun = rz;
    D_8010274C_10334C.x = D_8010ACBC_14C64C_RainbowRun = cx;
    D_8010274C_10334C.y = D_8010ABEC_14C57C_RainbowRun = cy;
    D_8010274C_10334C.z = D_8010AC04_14C594_RainbowRun = cz;
}

/* The camera: a short shake while D_8010A751 is set. */
void func_80105870_147200_RainbowRun(void) {
    if (D_8010A751_14C0E1_RainbowRun == 1) {
        f32 dx = D_8010A758_14C0E8_RainbowRun[(D_8010A752_14C0E2_RainbowRun & 3) * 2];
        f32 dy = D_8010A75C_14C0EC_RainbowRun[(D_8010A752_14C0E2_RainbowRun & 3) * 2];

        D_8010274C_10334C.x = dx + D_8010ACBC_14C64C_RainbowRun;
        D_8010274C_10334C.y = dy + D_8010ABEC_14C57C_RainbowRun;
        if (++D_8010A752_14C0E2_RainbowRun >= 11) {
            D_8010A751_14C0E1_RainbowRun = 0;
            D_8010A752_14C0E2_RainbowRun = 0;
        }
    } else {
        D_8010274C_10334C.x = D_8010ACBC_14C64C_RainbowRun;
        D_8010274C_10334C.y = D_8010ABEC_14C57C_RainbowRun;
    }
    D_800FA610_FB210 = D_8010AA10_14C3A0_RainbowRun;
    D_800FD474_FE074.x = D_8010AC10_14C5A0_RainbowRun;
    D_800FD474_FE074.y = D_8010ABF8_14C588_RainbowRun;
    D_800FD474_FE074.z = D_8010ABF4_14C584_RainbowRun;
    D_80102750_103350[1] = D_8010AC04_14C594_RainbowRun;
}

/* Ends the minigame once the result is in: fade out, then return. */
void func_80105978_147308_RainbowRun(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_8010A778_14C108_RainbowRun == 0) {
            InitFadeOut(0, 0x14);
            D_8010A778_14C108_RainbowRun = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* The shadow: smaller the higher the object is. */
void func_801059F0_147380_RainbowRun(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], scale, 0.0f, scale);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}

/* The stick direction of player 0's port, averaged over 8 frames (-1 near the centre). */
f32 func_80105A74_147404_RainbowRun(void) {
    s8 port = RR_WORK(D_800FFFD8_100BD8[0])->unk_57;
    s8 y = ContStkY[port];
    s8 x = ContStkX[port];
    f32 sumX;
    f32 sumY;
    f32 angle;
    s16 i;

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
    D_8010A77C_14C10C_RainbowRun[D_8010A78C_14C11C_RainbowRun] = (f32)x;
    D_8010A784_14C114_RainbowRun[D_8010A78C_14C11C_RainbowRun] = (f32)y;
    D_8010A78C_14C11C_RainbowRun = (D_8010A78C_14C11C_RainbowRun + 1) & 7;
    sumX = sumY = 0.0f;
    for (i = 0; i < 8; i++) {
        sumX += D_8010A77C_14C10C_RainbowRun[i];
        sumY += D_8010A784_14C114_RainbowRun[i];
    }
    sumX /= 8.0f;
    sumY /= 8.0f;
    if (sumX * sumX + sumY * sumY > 100.0f) {
        angle = func_800B75A8_B81A8(sumX, -sumY) + 180.0f;
    } else {
        angle = -1.0f;
    }
    return angle;
}

/* Rotation of angle about axis, translated (retail uses pos->z where pos->x would be expected, as
   MP1's func_800F8F70_TightropeTreachery). */
void func_80105C40_1475D0_RainbowRun(Vec* pos, Vec* axis, f32 angle, Matrix4f m) {
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
    f32 txy;
    f32 txz;
    f32 tyz;

    func_800B8070_B8C70(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    xz = z * x;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[0][0] = t * xx + c;
    txy = t * xy;
    m[0][1] = txy + zs;
    txz = t * xz;
    m[0][2] = txz - ys;
    m[1][0] = txy - zs;
    m[1][1] = t * yy + c;
    tyz = t * yz;
    m[1][2] = tyz + xs;
    m[2][0] = txz + ys;
    m[2][1] = tyz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - txy) - pz * (txz + ys);
    m[3][1] = -pz * (txy + zs) + py * t * (1.0f - yy) + pz * (xs - tyz);
    m[3][2] = pz * (ys - txz) - py * (tyz + xs) + pz * t * (1.0f - zz);
}

/* A CPU player presses nothing but Z. */
void func_80105E38_1477C8_RainbowRun(RRPlayerWork* work) {
    u16 btn = 0;

    if (ContBtn[work->unk_57] & 0x1000) {
        btn |= 0x1000;
    }
    ContBtnTrg[work->unk_57] = ContBtn[work->unk_57] = btn;
    ContBtnTrg[work->unk_57] = btn & (btn ^ D_8010A78E_14C11E_RainbowRun);
    D_8010A78E_14C11E_RainbowRun = btn;
    ContStkX[work->unk_57] = 0;
    ContStkY[work->unk_57] = 0;
}

void func_80105ED4_147864_RainbowRun(omObjData* obj, f32 dist) {
    D_8010A754_14C0E4_RainbowRun -= dist;
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_8000BF24_CB24)(obj, -4000.0f, -800.0f, -1200.0f, 800.0f, D_8010A754_14C0E4_RainbowRun + 1200.0f);
    func_8000BFF0_CBF0(obj);
}

/* Park-Miller minimal standard generator (Schrage's method). */
u32 func_80105F4C_1478DC_RainbowRun(u32 seed) {
    s32 hi;
    s32 lo;

    if (seed == 0) {
        seed = rand8();
        seed = seed ^ guRandom();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    seed = seed - lo * 16807;
    return seed;
}

u32 func_80106020_1479B0_RainbowRun(void) {
    return D_8010A790_14C120_RainbowRun = func_80105F4C_1478DC_RainbowRun(D_8010A790_14C120_RainbowRun);
}
