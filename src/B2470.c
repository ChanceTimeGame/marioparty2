#include "common.h"

/* A second HuVecGetLength3F (MP3 src/libhmath/vecmag3f.c) over its own copy of
   HuVecGetLengthSqr3F (func_800B1840_B2440). func_800B1830_B2430 is HuSqrtf. */

f32 func_800B1830_B2430(f32);
f32 func_800B1840_B2440(Vec *vec);

float func_800B1870_B2470(Vec *vec) {
    return func_800B1830_B2430(func_800B1840_B2440(vec));
}
