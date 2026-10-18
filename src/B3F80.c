#include "common.h"

/* HuVecGetLengthSqr3F, from MP3 src/libhmath/vecmags3f.c. */
f32 HuVecGetLengthSqr3F(Vec *vec) {
    f32 x;
    f32 y;
    f32 z;

    x = vec->x;
    y = vec->y;
    z = vec->z;

    return (x * x) + (y * y) + (z * z);
}
