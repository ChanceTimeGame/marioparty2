#include "PR/os_internal.h"
#include "PR/R4300.h"
#include "PR/rcp.h"
#include "PR/viint.h"

/* __osViInit: libultra io/vi.c, from MP1 src/95CE0.c. The static vi[2] and the Lan1 modes are in
   the data asm. */

extern __OSViContext D_800CF3C0_CFFC0[2]; /* vi */
extern OSViMode D_800CF430_D0030;         /* osViModeNtscLan1 */
extern OSViMode D_800CF480_D0080;         /* osViModePalLan1 */
extern OSViMode D_800CF4D0_D00D0;         /* osViModeMpalLan1 */

void __osViInit(void) {
    bzero(D_800CF3C0_CFFC0, sizeof(D_800CF3C0_CFFC0));
    __osViCurr = &D_800CF3C0_CFFC0[0];
    __osViNext = &D_800CF3C0_CFFC0[1];
    __osViNext->retraceCount = 1;
    __osViCurr->retraceCount = 1;
    __osViNext->framep = (void*)K0BASE;
    __osViCurr->framep = (void*)K0BASE;
    if (osTvType == OS_TV_PAL) {
        __osViNext->modep = &D_800CF480_D0080;
    } else if (osTvType == OS_TV_MPAL) {
        __osViNext->modep = &D_800CF4D0_D00D0;
    } else {
        __osViNext->modep = &D_800CF430_D0030;
    }
    __osViNext->state = VI_STATE_BLACK;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    while (IO_READ(VI_CURRENT_REG) > 10) {
    }
    IO_WRITE(VI_CONTROL_REG, 0);
    __osViSwapContext();
}
