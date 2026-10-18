#include "common.h"

/* HuVecGetLength3F, from MP3 src/libhmath/vecmag3f.c. func_800B1830_B2430 is HuSqrtf. */

f32 func_800B1830_B2430(f32);
f32 HuVecGetLengthSqr3F(Vec *vec);

float HuVecGetLength3F(Vec *vec) {
    return func_800B1830_B2430(HuVecGetLengthSqr3F(vec));
}
