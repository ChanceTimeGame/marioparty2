#include "common.h"

/* libultra gu/normalize.c (MP1 src/9CD60.c func_8009C160) */
float sqrtf(float);

void guNormalize(float* x, float* y, float* z) {
    float m;

    m = 1 / sqrtf((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
    *x *= m;
    *y *= m;
    *z *= m;
}
