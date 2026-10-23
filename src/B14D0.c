#include "common.h"


// KMC libm: a 52-step CORDIC arctangent on 2.60 fixed point, atan and atan2.

/* .data (0xD0160-0xD0360) */
s64 D_800CF560_D0160[64] = { /* atan(2^-i) in 2.60 fixed point */
    0x0C90FDAA22168C00LL, 0x076B19C1586ED3C0LL, 0x03EB6EBF25901BA0LL,
    0x01FD5BA9AAC2F6E0LL, 0x00FFAADDB967EF50LL, 0x007FF556EEA5D894LL,
    0x003FFEAAB776E536LL, 0x001FFFD555BBBA97LL, 0x000FFFFAAAADDDDBLL,
    0x0007FFFF55556EEFLL, 0x0003FFFFEAAAAB77LL, 0x0001FFFFFD55555BLL,
    0x0000FFFFFFAAAAAALL, 0x00007FFFFFF55555LL, 0x00003FFFFFFEAAAALL,
    0x00001FFFFFFFD555LL, 0x00000FFFFFFFFAAALL, 0x000007FFFFFFFF55LL,
    0x000003FFFFFFFFEALL, 0x000001FFFFFFFFFDLL, 0x000000FFFFFFFFFFLL,
    0x0000007FFFFFFFFFLL, 0x0000003FFFFFFFFFLL, 0x0000001FFFFFFFFFLL,
    0x0000000FFFFFFFFFLL, 0x00000007FFFFFFFFLL, 0x00000003FFFFFFFFLL,
    0x0000000200000000LL, 0x0000000100000000LL, 0x0000000080000000LL,
    0x0000000040000000LL, 0x0000000020000000LL, 0x0000000010000000LL,
    0x0000000008000000LL, 0x0000000004000000LL, 0x0000000002000000LL,
    0x0000000001000000LL, 0x0000000000800000LL, 0x0000000000400000LL,
    0x0000000000200000LL, 0x0000000000100000LL, 0x0000000000080000LL,
    0x0000000000040000LL, 0x0000000000020000LL, 0x0000000000010000LL,
    0x0000000000008000LL, 0x0000000000004000LL, 0x0000000000002000LL,
    0x0000000000001000LL, 0x0000000000000800LL, 0x0000000000000400LL,
    0x0000000000000200LL, 0x0000000000000100LL, 0x0000000000000080LL,
    0x0000000000000040LL, 0x0000000000000020LL, 0x0000000000000010LL,
    0x0000000000000008LL, 0x0000000000000004LL, 0x0000000000000002LL,
    0x0000000000000001LL, 0x0000000000000000LL, 0x0000000000000000LL,
    0x0000000000000000LL,
};

f64 func_800B11B0_B1DB0(s32 type, char* name, f64 arg1, f64 arg2, f64 retval); // matherr
s64 __fixdfdi(f64 x);
f64 __floatdidf(s64 x);

// CORDIC: *out = atan(y / x) for x > 0.
void func_800B08D0_B14D0(s64 x0, s64 y0, f64* out) {
    f64* o = out;
    s64 x = x0;
    s64 y = y0;
    s64 z = 0;
    s64 nx;
    s32 i;

    for (i = 0; i < 52; i++) {
        if (y >= 0) {
            nx = x + (y >> i);
            y = y - (x >> i);
            z += D_800CF560_D0160[i];
        } else {
            nx = x - (y >> i);
            y = y + (x >> i);
            z -= D_800CF560_D0160[i];
        }
        x = nx;
    }
    *o = (f64)z / 1152921504606846976.0;
}

// atan
f64 func_800B0A88_B1688(f64 x) {
    s32 sign;
    s64 a;
    s64 b;
    f64 r;

    if (x < 0.0) {
        x = -x;
        sign = -1;
    } else {
        sign = 1;
    }
    if (1e-7 < x) {
        if (1.0 <= x) {
            b = 0x1000000000000000LL;
            a = 1.0 / x * 1152921504606846976.0;
        } else {
            a = 0x1000000000000000LL;
            b = x * 1152921504606846976.0;
        }
        func_800B08D0_B14D0(a, b, &r);
    } else {
        r = x;
    }
    return (sign < 0) ? -r : r;
}

// atan2
f64 func_800B0BA0_B17A0(f64 y, f64 x) {
    f64 r;

    if ((x == 0.0) & (y == 0.0)) {
        return func_800B11B0_B1DB0(1, "atan2", x, y, 0.0);
    }
    if (x == 0.0) {
        if (y > 0.0) {
            return 1.5707963267948966;
        }
        return -1.5707963267948966;
    }
    r = func_800B0A88_B1688(y / x);
    if (x > 0.0) {
        return r;
    }
    if (y == 0.0) {
        return 3.141592653589793;
    }
    if (y > 0.0) {
        return r + 3.141592653589793;
    }
    return r - 3.141592653589793;
}
