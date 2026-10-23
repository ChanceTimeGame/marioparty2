#include "common.h"

f32 func_800B1830_B2430(f32);

/* HuVecNormalize3F (MP3 src/libhmath/vecnorm3f.c, NONMATCHING there) */
// scheduling: retail interleaves the prologue's register saves with the loads (masked 6; MP3
// did not match it either)
#ifdef NON_MATCHING
void func_800B33E0_B3FE0(Vec* vec) {
    f32 x;
    f32 y;
    f32 z;
    f32 invMag;

    x = vec->x;
    y = vec->y;
    z = vec->z;
    invMag = 1.0f / func_800B1830_B2430((x * x) + (y * y) + (z * z));

    vec->x = invMag * x;
    vec->y = invMag * y;
    vec->z = invMag * z;
}
#else
INCLUDE_ASM("asm/nonmatchings/B3FE0", func_800B33E0_B3FE0);
#endif
