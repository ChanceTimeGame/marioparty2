/* 9E7A0: from Mario Party 1 src/lib/2.0I/io/epiread.c */
#include "include_asm.h"
#include "piint.h"

s32 __osEPiRawReadIo(OSPiHandle*, u32, u32*);

s32 osEPiReadIo(OSPiHandle* pihandle, u32 devAddr, u32* data) {
    register s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawReadIo(pihandle, devAddr, data);
    __osPiRelAccess();

    return ret;
}
