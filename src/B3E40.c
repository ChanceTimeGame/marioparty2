#include "common.h"

/* HuVecMulScalar and HuVecAddScaled, from MP3 src/libhmath/vecmuls.c and vecadds.c (one object here). */

void HuVecMulScalar(Vec *out, f32 scalar, Vec *a) {
    float x = scalar * a->x;
    float y = scalar * a->y;
    float z = scalar * a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}

void HuVecAddScaled(Vec *out, Vec *a, f32 scalar, Vec *b) {
    float x = a->x + (scalar * b->x);
    float y = a->y + (scalar * b->y);
    float z = a->z + (scalar * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}
