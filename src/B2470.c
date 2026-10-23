#include "common.h"

/* A second HuVecGetLength3F (MP3 src/libhmath/vecmag3f.c) over its own copy of
   HuVecGetLengthSqr3F (func_800B1840_B2440, src/B2440.c). func_800B1830_B2430 is HuSqrtf. The
   callers (ovl_3E) pass three floats. */

f32 func_800B1830_B2430(f32);
f32 func_800B1840_B2440(f32 x, f32 y, f32 z);

float func_800B1870_B2470(f32 x, f32 y, f32 z) {
    return func_800B1830_B2430(func_800B1840_B2440(x, y, z));
}
