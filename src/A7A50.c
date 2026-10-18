/* A7A50: from Mario Party 1 src/lib/2.0I/io/visetmode.c */
#include "include_asm.h"
#include <PR/os_internal.h>

#include "viint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

void osViSetMode(OSViMode *modep) {
    register u32 saveMask = __osDisableInt();

    __osViNext->modep = modep;
    __osViNext->state = VI_STATE_MODE_UPDATED;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(saveMask);
}
