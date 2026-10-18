/* A7670: from Mario Party 1 src/lib/2.0I/io/vigetnextframebuf.c */
#include "include_asm.h"
#include <PR/os_internal.h>

#include "viint.h"

void *osViGetNextFramebuffer(void) {
    register u32 saveMask = __osDisableInt();
    void *framep = __osViNext->framep;
    
    __osRestoreInt(saveMask);
    return framep;
}
