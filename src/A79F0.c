/* A79F0: from Mario Party 1 src/lib/2.0I/io/visetevent.c */
#include "include_asm.h"
#include <PR/os_internal.h>

#include "viint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

void osViSetEvent(OSMesgQueue *mq, OSMesg m, u32 retraceCount) {
    register u32 saveMask = __osDisableInt();

    __osViNext->msgq = mq;
    __osViNext->msg = m;
    __osViNext->retraceCount = retraceCount;
    __osRestoreInt(saveMask);
}
