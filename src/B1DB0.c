#include "common.h"

/* From MP1 src/9C630.c. KMC libm's struct exception (math.h). */
typedef struct KmcException {
    s32 type; /* 3 OVERFLOW, 4 UNDERFLOW: ERANGE; anything else: EDOM */
    char* name;
    f64 arg1;
    f64 arg2;
    f64 retval;
} KmcException;

s32 func_800B1810_B2410(KmcException* exc); /* matherr */
extern s32 D_800F8FDC_F9BDC;                /* errno */

/* KMC libm error path: lets matherr see the exception, else sets errno; returns the result. */
f64 func_800B11B0_B1DB0(s32 type, char* name, f64 arg1, f64 arg2, f64 retval) {
    KmcException exc;

    exc.type = type;
    exc.name = name;
    exc.arg1 = arg1;
    exc.arg2 = arg2;
    exc.retval = retval;
    if (func_800B1810_B2410(&exc) == 0) {
        D_800F8FDC_F9BDC = (type == 3 || type == 4) ? 34 : 33;
    }
    return exc.retval;
}

/* func_800B11B0_B1DB0 was its own object: retail has two nops of padding before the hand asm below
   (the asm-only unit carried them in func_800B11B0_B1DB0.s). */
__asm__(".section .text\n.set noreorder\nnop\nnop\n.set reorder\n");

// __muldi3: hand-written asm in the original library
INCLUDE_ASM("asm/nonmatchings/B1DB0", func_800B1224_B1E24);

// KMC libgcc 64-bit unsigned divide/modulo core: hand-written asm in the original library
INCLUDE_ASM("asm/nonmatchings/B1DB0", func_800B1258_B1E58);

// KMC libgcc 64-bit unsigned divide core: hand-written asm in the original library
INCLUDE_ASM("asm/nonmatchings/B1DB0", func_800B1354_B1F54);
