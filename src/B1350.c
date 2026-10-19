#include "common.h"

// KMC libm: asin, acos (domain errors go to matherr, func_800B11B0_B1DB0), from MP1 src/9BBD0.c. The
// unit's rodata (D55E0-D5620) is carved out of the data blob.

f64 func_800B11B0_B1DB0(s32 type, char* name, f64 arg1, f64 arg2, f64 retval); // matherr
f64 func_800B0BA0_B17A0(f64 y, f64 x);                                         // atan2 (B14D0.c)
f64 sqrt(f64 x);

// asin
f64 func_800B0750_B1350(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        return func_800B11B0_B1DB0(1, "asin", x, 0.0, 0.0);
    }
    return func_800B0BA0_B17A0(x, sqrt(1.0 - x * x));
}

// acos
f64 func_800B0828_B1428(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        return func_800B11B0_B1DB0(1, "acos", x, 0.0, 0.0);
    }
    return 1.5707963267948966 - func_800B0750_B1350(x);
}
