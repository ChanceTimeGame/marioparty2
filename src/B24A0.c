#include "common.h"

typedef f32 Matrix4f[4][4];

/* HuVecNormalize and HuVecDotProduct, from MP3 src/libhmath/vecnorm.c and vecdot.c (-O2 -ffast-math).
   func_800B1830_B2430 is HuSqrtf. guLookAtF (func_800B1960_B2560) from MP1 src/9CE40.c (NON_MATCHING). */

f32 func_800B1830_B2430(f32);
/* Retail inlines HuVecNormalize into guLookAtF below; this non-inline declaration keeps the
   definition external under C99 inline rules (host build) */
void func_800B18A0_B24A0(f32 *x, f32 *y, f32 *z);

inline void func_800B18A0_B24A0(f32 *x, f32 *y, f32 *z) {
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
// Retail inlines HuVecNormalize (func_800B18A0_B24A0) for the three normalisations, so the look,
// right and up vectors live in memory. Remaining: retail copies xUp/yUp/zUp from their incoming
// argument slots into themselves (lwc1/swc1 116-124) in the prologue (6 instructions, masked 15).
// S3-T tried: a K&R definition, the function itself `inline`; neither emits the copy.
#ifdef NON_MATCHING
void func_800B1960_B2560(Matrix4f matrix, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp,
                         f32 zUp) {
    f32 xLook;
    f32 yLook;
    f32 zLook;
    f32 xRight;
    f32 yRight;
    f32 zRight;

    xLook = xEye - xAt;
    yLook = yEye - yAt;
    zLook = zEye - zAt;
    func_800B18A0_B24A0(&xLook, &yLook, &zLook);
    matrix[0][2] = xLook;
    matrix[1][2] = yLook;
    matrix[2][2] = zLook;
    matrix[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);
    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    func_800B18A0_B24A0(&xRight, &yRight, &zRight);
    matrix[0][0] = xRight;
    matrix[1][0] = yRight;
    matrix[2][0] = zRight;
    matrix[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);
    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    func_800B18A0_B24A0(&xUp, &yUp, &zUp);
    matrix[0][1] = xUp;
    matrix[1][1] = yUp;
    matrix[2][1] = zUp;
    matrix[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/B24A0", func_800B1960_B2560);
#endif
