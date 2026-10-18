/* A8E90: from Mario Party 1 src/9AC00.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#ifndef OS_IM_RCP

#define OS_IM_RCP 0x00000401

#endif

/* __osResetGlobalIntMask */
void __osResetGlobalIntMask(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __OSGlobalIntMask &= ~(mask & ~OS_IM_RCP);
    __osRestoreInt(saveMask);
}
