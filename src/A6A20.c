/* A6A20: from Mario Party 1 src/lib/2.0I/io/sptaskyield.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "PR/rcp.h"

void osSpTaskYield(void) {
    __osSpSetStatus(SP_SET_YIELD);
}
