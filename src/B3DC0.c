#include "common.h"

/* HuVecAdd, from MP3 src/libhmath/vecadd.c. */
void HuVecAdd(Vec *out, Vec *a, Vec *b) {
    float x = a->x + b->x;
    float y = a->y + b->y;
    float z = a->z + b->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
