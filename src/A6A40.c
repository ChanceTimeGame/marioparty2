/* A6A40: from Mario Party 1 src/lib/2.0I/io/sptaskyielded.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "PR/sptask.h"

#include "PR/rcp.h"

OSYieldResult osSpTaskYielded(OSTask *tp) {
    u32 status;
    OSYieldResult result;
    
    status = __osSpGetStatus();
    result = status >> 8; 
    result &= 1;

    if (status & SP_STATUS_YIELD) {
        tp->t.flags = ~(OS_TASK_DP_WAIT) & (tp->t.flags | result);
    }
    
    return result;
}
