/* A7FC0: from Mario Party 1 src/lib/2.0I/io/viblack.c */
#include "include_asm.h"
#include <PR/os_internal.h>

#include "viint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

void osViBlack(u8 active) {
    register u32 saveMask = __osDisableInt();
    
    if (active) {
        __osViNext->state |= VI_STATE_BLACK;
    } else {
        __osViNext->state &= ~VI_STATE_BLACK;
    }

    __osRestoreInt(saveMask);
}
