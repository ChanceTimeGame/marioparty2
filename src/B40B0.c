#include "common.h"

/* HuVecDot3F, HuVecCross and HuVecIsEqual, from MP3 src/libhmath/vecdot3f.c, veccross.c and veceq.c
   (-O2 -ffast-math). HuVecDistance from MP3 vecdist.c too (NON_MATCHING). */

f32 func_800B1830_B2430(f32);

// scheduling: retail moves the prologue after the subtractions (masked 4; MP3 did not match it)
#ifdef NON_MATCHING
f32 HuVecDistance(Vec* a, Vec* b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = a->x - b->x;
    dy = a->y - b->y;
    dz = a->z - b->z;
    return func_800B1830_B2430((dx * dx) + (dy * dy) + (dz * dz));
}
#else
INCLUDE_ASM("asm/nonmatchings/B40B0", HuVecDistance);
#endif

f32 func_800B3500_B4100(Vec *a, Vec *b) {
    return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

void func_800B3530_B4130(Vec *out, Vec *a, Vec *b) {
    f32 vector1Y = a->y;
    f32 vector2Z = b->z;
    f32 vector1Z = a->z;
    f32 vector2Y = b->y;
    f32 vector2X = b->x;
    f32 vector1X = a->x;

    out->x = (vector1Y * vector2Z) - (vector1Z * vector2Y);
    out->y = (vector1Z * vector2X) - (vector1X * vector2Z);
    out->z = (vector1X * vector2Y) - (vector1Y * vector2X);
}

s32 func_800B3580_B4180(Vec *a, Vec *b) {
    if ((a->x == b->x) && (a->y == b->y) && (a->z == b->z)) {
        return TRUE;
    }
    return FALSE;
}
