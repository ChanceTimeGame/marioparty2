#include <PR/ultratypes.h>

/* MP3 src/libhmath/vecmag.c HuVecGetLengthSqr (retail starts it with a nop: the KMC as mul fix) */
f32 func_800B1840_B2440(f32 arg0, f32 arg1, f32 arg2) {
    return (arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2);
}
