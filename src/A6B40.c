/* A6B40: from Mario Party 1 src/95E50.c */
#include "include_asm.h"
#include "macros.h"

#include "PR/os_internal.h"

#define SI_Q_BUF_LEN 1

extern u32 __osSiAccessQueueEnabled;

              /* __osSiAccessQueueEnabled */
extern OSMesg siAccessBuf[SI_Q_BUF_LEN];

 /* siAccessBuf */
extern OSMesgQueue __osSiAccessQueue;

      /* __osSiAccessQueue */

void __osSiCreateAccessQueue(void) {
    __osSiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osSiAccessQueue, siAccessBuf, SI_Q_BUF_LEN);
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg dummyMesg;

    if (!__osSiAccessQueueEnabled) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&__osSiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
