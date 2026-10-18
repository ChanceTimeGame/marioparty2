/* A6DE0: from Mario Party 1 src/lib/2.0I/os/getthreadpri.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

OSPri osGetThreadPri(OSThread* thread) {
    if (thread == NULL) {
        thread = __osRunningThread;
    }
    return thread->priority;
}
