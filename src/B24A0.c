#include "common.h"

typedef f32 Matrix4f[4][4];

/* HuVecNormalize and HuVecDotProduct, from MP3 src/libhmath/vecnorm.c and vecdot.c (-O2 -ffast-math).
   func_800B1830_B2430 is HuSqrtf. guLookAtF (func_800B1960_B2560) from MP1 src/9CE40.c (NON_MATCHING). */

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

/* guLookAtF: Hudson's copy (MP1 src/9CE40.c HuGuLookAtF): eye - at in single precision */
// register allocation: retail spills xUp/yUp/zUp to their argument slots and keeps
// f30 free (masked 186)
#ifdef NON_MATCHING
void func_800B1960_B2560(Matrix4f matrix, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp,
                         f32 zUp) {
    f32 look[3];
    f32 right[3];
    f32 len;

    look[0] = xEye - xAt;
    look[1] = yEye - yAt;
    look[2] = zEye - zAt;
    len = 1.0f / func_800B1830_B2430(look[0] * look[0] + look[1] * look[1] + look[2] * look[2]);
    look[0] *= len;
    look[1] *= len;
    look[2] *= len;
    matrix[0][2] = look[0];
    matrix[1][2] = look[1];
    matrix[2][2] = look[2];
    matrix[3][2] = -(xEye * look[0] + yEye * look[1] + zEye * look[2]);
    right[0] = yUp * look[2] - zUp * look[1];
    right[1] = zUp * look[0] - xUp * look[2];
    right[2] = xUp * look[1] - yUp * look[0];
    len = 1.0f / func_800B1830_B2430(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]);
    right[0] *= len;
    right[1] *= len;
    right[2] *= len;
    matrix[0][0] = right[0];
    matrix[1][0] = right[1];
    matrix[2][0] = right[2];
    matrix[3][0] = -(xEye * right[0] + yEye * right[1] + zEye * right[2]);
    xUp = look[1] * right[2] - look[2] * right[1];
    yUp = look[2] * right[0] - look[0] * right[2];
    zUp = look[0] * right[1] - look[1] * right[0];
    len = 1.0f / func_800B1830_B2430(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;
    matrix[0][1] = xUp;
    matrix[1][1] = yUp;
    matrix[2][1] = zUp;
    matrix[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    matrix[2][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[3][3] = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/B24A0", func_800B1960_B2560);
#endif
