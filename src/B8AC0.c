#include "common.h"

f32 HuMathSin(f32);
f32 func_800B1830_B2430(f32);
extern f32 D_800F6070_F6C70; /* sign of the cosine of HuMathSin's last angle */

INCLUDE_ASM("asm/nonmatchings/B8AC0", func_800B7EC0_B8AC0);

INCLUDE_ASM("asm/nonmatchings/B8AC0", func_800B8000_B8C00);

/* sincos in degrees (MP3 src/8F7D0.c, asm there; MP1 src/AFE60.c func_800AF2E0): the cosine is
   sqrt(1 - sin^2) with the sign HuMathSin left. */
// IDO-compiled (arguments saved to their home slots, t6/t7): KMC GCC cannot reproduce it
#ifdef NON_MATCHING
void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine) {
    f32 s;

    s = *sine = HuMathSin(angle);
    *cosine = func_800B1830_B2430(1.0f - (s * s)) * D_800F6070_F6C70;
}
#else
INCLUDE_ASM("asm/nonmatchings/B8AC0", func_800B8070_B8C70);
#endif

INCLUDE_ASM("asm/nonmatchings/B8AC0", func_800B80D0_B8CD0);
