/* 9E2C0: from Mario Party 1 src/lib/2.0I/os/sethwinterrupt.c */
#include "include_asm.h"
INCLUDE_ASM("asm/nonmatchings/9E2C0", osSetIntMask);

#include "PR/os_internal.h"

#include "osint.h"

struct __osHwInt {
    s32 (*handler)(void);
    void* stackEnd;
};

extern struct __osHwInt __osHwIntTable[];

void __osSetHWIntrRoutine(OSHWIntr interrupt, s32 (*handler)(void), void* stackEnd) {
    register u32 saveMask = __osDisableInt();
    __osHwIntTable[interrupt].handler = handler;
    __osHwIntTable[interrupt].stackEnd = stackEnd;
    __osRestoreInt(saveMask);
}
