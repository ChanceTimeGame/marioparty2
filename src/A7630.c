/* A7630: from Mario Party 1 src/lib/2.0I/io/vigetcurrframebuf.c */
#include "include_asm.h"
#include <PR/os_internal.h>

#include "viint.h"

void *osViGetCurrentFramebuffer(void) {
    register u32 saveMask = __osDisableInt();
    void *framep = __osViCurr->framep;

    __osRestoreInt(saveMask);
    return framep;
}
