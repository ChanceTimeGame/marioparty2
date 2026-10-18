/* A66F0: from Mario Party 1 src/lib/2.0I/os/seteventmesg.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

extern u32 __osPreNMI;

 /* __osPreNMI */

void osSetEventMesg(OSEvent event, OSMesgQueue* mq, OSMesg msg) {
    register u32 saveMask;
    __OSEventState* es;

    saveMask = __osDisableInt();
    es = &__osEventStateTab[event];
    es->messageQueue = mq;
    es->message = msg;
    if (event == OS_EVENT_PRENMI) {
        if (__osShutdown && !__osPreNMI) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        __osPreNMI = TRUE;
    }
    __osRestoreInt(saveMask);
}
