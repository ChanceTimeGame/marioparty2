#include "common.h"

/* HuMathCos (MP3 src/8EFF0.c, asm there; MP1 src/AFBD0.c func_800AEFD0): cosine of an angle in
   degrees from a one-degree sine table plus a second-order correction. Retail built it with IDO
   (cfc1/ctc1 around each float-to-int conversion), so KMC GCC cannot match it. */

extern f32 D_800CFC60_D0860[]; /* sin of 0..90 degrees; D_800CFDC8_D09C8 is its entry 90 */

// IDO-compiled: KMC GCC cannot reproduce it. Constants D_800D4B70_D5770 (1 / 360) and
// D_800D4B74_D5774 (pi / 180).
#ifdef NON_MATCHING
f32 func_800B7890_B8490(f32 angle) {
    f32 result;
    f32 deg;
    f32 err;
    f32 errSq;
    s32 negate;

    negate = FALSE;
    angle = (angle > 0.0f) ? angle : -angle;
    angle -= (s32)(angle * (1.0f / 360.0f)) * 360.0f;
    if (angle > 270.0f) {
        angle -= 270.0f;
    } else if (angle > 90.0f) {
        negate = TRUE;
        if (angle > 180.0f) {
            angle = 270.0f - angle;
        } else {
            angle -= 90.0f;
        }
    } else {
        angle = 90.0f - angle;
    }
    deg = (s32)(angle + 0.5f);
    err = (angle - deg) * 0.017453292f;
    errSq = err * err;
    result = D_800CFC60_D0860[(s32)deg] * (1.0f - (0.125f * errSq * (errSq + 4.0f))) +
             (D_800CFC60_D0860[90 - (s32)deg] * err);
    return negate ? -result : result;
}
#else
INCLUDE_ASM("asm/nonmatchings/B8490", func_800B7890_B8490);
#endif
