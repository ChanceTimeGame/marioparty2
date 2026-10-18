#include "common.h"

/* HuVecNeg, from MP3 src/libhmath/vecneg.c. */
void HuVecNeg(Vec *out, Vec *a) {

    float x = -a->x;
    float y = -a->y;
    float z = -a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
