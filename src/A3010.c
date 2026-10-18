/* A3010: from Mario Party 1 src/lib/2.0I/io/contsetch.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "controller.h"

#include "siint.h"

s32 osContSetCh(u8 ch) {
    s32 ret = 0;

    __osSiGetAccess();

    if (ch > MAXCONTROLLERS) {
        __osMaxControllers = MAXCONTROLLERS;
    } else {
        __osMaxControllers = ch;
    }

    __osContLastCmd = CONT_CMD_END;
    __osSiRelAccess();
    return ret;
}
