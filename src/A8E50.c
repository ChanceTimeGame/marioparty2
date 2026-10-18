/* A8E50: from Mario Party 1 src/9AC50.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

void __osSetGlobalIntMask(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __OSGlobalIntMask |= mask;
    __osRestoreInt(saveMask);
}
