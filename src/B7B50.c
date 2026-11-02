#include "common.h"

extern const f64 D_800D4AF0_D56F0;

f64 func_800B6F50_B7B50(f64 y, f64 x);

INCLUDE_ASM("asm/nonmatchings/B7B50", func_800B6F50_B7B50);

/* atan2 in degrees; D_800D4AF0_D56F0 is 180/pi. Class: IDO (libm; lwc1 pairs, ra at 0x14), which KMC GCC
   cannot emit, like its callee above. */
#ifdef NON_MATCHING
f64 func_800B727C_B7E7C(f64 y, f64 x) {
    return func_800B6F50_B7B50(y, x) * D_800D4AF0_D56F0;
}
#else
INCLUDE_ASM("asm/nonmatchings/B7B50", func_800B727C_B7E7C);
#endif
