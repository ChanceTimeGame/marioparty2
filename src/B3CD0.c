#include "common.h"

/* HuVecCopyXYZ and HuVecCopy3F, from MP3 src/libhmath/veccopy.c (-O2 -ffast-math).
   func_800B30D0_B3CD0 stays in asm (MP3 asm only). */

INCLUDE_ASM("asm/nonmatchings/B3CD0", func_800B30D0_B3CD0);

void func_800B3160_B3D60(Vec *out, f32 x, f32 y, f32 z) {
    out->x = x;
    out->y = y;
    out->z = z;
}

void func_800B3170_B3D70(Vec *out, Vec *a) {
    *out = *a;
}
