#include "common.h"

/* atan2f in radians and degrees (MP3 src/8EA10.c _atan2/_atan2d, asm there; MP1 src/B0FC0.c
   func_800B0850/func_800B0CD8). Retail built this unit with IDO (t6/t7 temporaries, arguments
   saved to their home slots), so KMC GCC cannot match it: the C is logic only. */

extern f32 D_800CFAD0_D06D0[]; /* 1.0f / i (index 0 is 0.0f) */

// IDO-compiled: KMC GCC cannot reproduce it. Constants are D_800D4B00_D5700..D_800D4B30_D5730.
#ifdef NON_MATCHING
f32 func_800B72B0_B7EB0(f32 y, f32 x) {
    f32 ratio;
    f32 ratioSq;
    f32 inv;
    f32 term;
    f32 sum;
    f32 t;
    s32 i;

    if (y == 0.0f) {
        return (x > 0.0f) ? 0.0f : 3.1415927f;
    }
    if (x == 0.0f) {
        return (y > 0.0f) ? 1.5707964f : -1.5707964f;
    }
    ratio = y / x;
    if (ratio == 1.0f) {
        return (y > 0.0f) ? 0.7853982f : -2.3561945f;
    }
    if (ratio == -1.0f) {
        return (x > 0.0f) ? -0.7853982f : 2.3561945f;
    }
    if (ratio > 1.0f || ratio < -1.0f) {
        sum = func_800B72B0_B7EB0(x, y);
        if (x > 0.0f) {
            return 1.5707964f - sum;
        }
        return (y > 0.0f) ? (1.5707964f - sum) : (-4.712389f - sum);
    }
    ratioSq = ratio * ratio;
    inv = 1.0f / (ratioSq + 1.0f);
    t = ratioSq * inv;
    sum = 1.0f;
    term = (2.0f * t) / 3.0f;
    for (i = 4; i < 99; i += 2) {
        sum += term;
        if (term <= 1e-7f) {
            break;
        }
        term *= i * t * D_800CFAD0_D06D0[i + 1];
    }
    sum *= ratio * inv;
    return (x > 0.0f) ? sum : ((y > 0.0f) ? (sum + 3.1415927f) : (sum + -3.1415927f));
}
#else
INCLUDE_ASM("asm/nonmatchings/B7EB0", func_800B72B0_B7EB0);
#endif

// IDO-compiled: KMC GCC cannot reproduce it (constant D_800D4B34_D5734 = 180 / pi)
#ifdef NON_MATCHING
f32 func_800B75A8_B81A8(f32 y, f32 x) {
    return func_800B72B0_B7EB0(y, x) * 57.29578f;
}
#else
INCLUDE_ASM("asm/nonmatchings/B7EB0", func_800B75A8_B81A8);
#endif

INCLUDE_ASM("asm/nonmatchings/B7EB0", func_800B75D0_B81D0);
