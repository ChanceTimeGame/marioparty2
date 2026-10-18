/* 9E3C0: from Mario Party 1 src/lib/2.0I/io/pimgr.c */
#include "include_asm.h"
#include "macros.h"

#include "PR/os_internal.h"

#include "piint.h"

/* libultra pimgr.c (_FINALROM: no ramrom thread). The statics live in the bss asm. */
extern OSThread piThread;

     /* piThread */
extern u8 piEventQueue[];

         /* piEventQueue */
extern u8 piThreadStack[];

         /* piThreadStack[0x1000] */

#define piEventQueue (*(OSMesgQueue*)piEventQueue)

extern OSMesg piEventBuf[1];

    /* piEventBuf */

extern OSMesgQueue __osPiAccessQueue;

extern u32 __osPiAccessQueueEnabled;

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, (OSMesg*)piEventBuf, 1);
    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }
    osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }
    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &piThread;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &piEventQueue;
    __osPiDevMgr.acsQueue = &__osPiAccessQueue;
    __osPiDevMgr.dma = __osPiRawStartDma;
    __osPiDevMgr.edma = __osEPiRawStartDma;
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, piThreadStack + 0x1000, pri);
    osStartThread(&piThread);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}
