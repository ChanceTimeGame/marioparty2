/* A71D0: from Mario Party 1 src/lib/2.0I/os/settimer.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

int osSetTimer(OSTimer* t, OSTime countdown, OSTime interval, OSMesgQueue* mq, OSMesg msg) {
    OSTime time;

    t->next = NULL;
    t->prev = NULL;
    t->interval = interval;
    t->value = (countdown != 0) ? countdown : interval;
    t->mq = mq;
    t->msg = msg;
    time = __osInsertTimer(t);
    if (__osTimerList->next == t) {
        __osSetTimerIntr(time);
    }
    return 0;
}
