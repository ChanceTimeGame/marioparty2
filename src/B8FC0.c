#include "common.h"

/* HuMathSin (MP3 src/libhmath/sin.c, asm there): sine of an angle in degrees from a one-degree
   sine table plus a second-order correction. It also leaves the sign of the angle's cosine in
   D_800F6070_F6C70, which func_800B8070_B8C70 (sincos) uses. Retail built it with IDO (cfc1/ctc1
   around each float-to-int conversion), so KMC GCC cannot match it. */

extern f32 D_800CFC60_D0860[]; /* sin of 0..90 degrees; D_800CFDC8_D09C8 is its entry 90 */
extern f32 D_800F6070_F6C70;   /* 1.0f or -1.0f: sign of the cosine of HuMathSin's last angle */

// IDO-compiled: KMC GCC cannot reproduce it. Constants D_800D4BE0_D57E0 (1 / 360) and
// D_800D4BE4_D57E4 (pi / 180).
#ifdef NON_MATCHING
f32 HuMathSin(f32 angle) {
    f32 result;
    f32 deg;
    f32 err;
    f32 errSq;
    s32 negate;

    negate = FALSE;
    angle -= (s32)(angle * (1.0f / 360.0f)) * 360.0f;
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    if (angle < 90.0f || angle > 270.0f) {
        D_800F6070_F6C70 = 1.0f;
    } else {
        D_800F6070_F6C70 = -1.0f;
    }
    if (angle > 180.0f) {
        negate = TRUE;
        angle -= 180.0f;
    }
    if (angle > 90.0f) {
        angle = 180.0f - angle;
    }
    deg = (s32)(angle + 0.5f);
    err = (angle - deg) * 0.017453292f;
    errSq = err * err;
    result = D_800CFC60_D0860[(s32)deg] * (1.0f - (0.125f * errSq * (errSq + 4.0f))) +
             (D_800CFC60_D0860[90 - (s32)deg] * err);
    return negate ? -result : result;
}
#else
INCLUDE_ASM("asm/nonmatchings/B8FC0", HuMathSin);
#endif
