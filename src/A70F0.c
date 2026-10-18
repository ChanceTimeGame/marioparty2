#include "PR/os_internal.h"
#include "PR/osint.h"

/* osYieldThread: libultra os/yieldthread.c, from MP1 src/9AC50.c. */

void osYieldThread(void) {
    register u32 saveMask = __osDisableInt();

    __osRunningThread->state = OS_STATE_RUNNABLE;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(saveMask);
}
