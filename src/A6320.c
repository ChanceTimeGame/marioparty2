/* A6320: from Mario Party 1 src/lib/2.0I/os/createmesgqueue.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msgBuf, s32 count) {
    mq->mtqueue = (OSThread*)&__osThreadTail;
    mq->fullqueue = (OSThread*)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msgBuf;
}
