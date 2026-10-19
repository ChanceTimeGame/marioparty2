#include "common.h"

/* HuVecNormalize and HuVecDotProduct, from MP3 src/libhmath/vecnorm.c and vecdot.c (-O2 -ffast-math).
   func_800B1830_B2430 is HuSqrtf. guLookAtF (func_800B1960_B2560) stays in asm (MP3 asm only). */

f32 func_800B1830_B2430(f32);

void func_800B18A0_B24A0(f32 *x, f32 *y, f32 *z) {
    f32 oldX;
    f32 oldY;
    f32 oldZ;
    f32 invMag;

    oldX = *x;
    oldY = *y;
    oldZ = *z;
    invMag = 1.0f / func_800B1830_B2430((oldX * oldX) + (oldY * oldY) + (oldZ * oldZ));

    *x *= invMag;
    *y *= invMag;
    *z *= invMag;
}

f32 func_800B1930_B2530(f32 aX, f32 aY, f32 aZ, f32 bX, f32 bY, f32 bZ) {
    return (aX * bX) + (aY * bY) + (aZ * bZ);
}

INCLUDE_ASM("asm/nonmatchings/B24A0", func_800B1960_B2560);
