/* A8880: from Mario Party 1 src/lib/2.0I/os/afterprenmi.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

s32 osAfterPreNMI(void) {
    return __osSpSetPc(0);
}
