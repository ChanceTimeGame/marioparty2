/* 9E740: from Mario Party 1 src/lib/2.0I/io/epiwrite.c */
#include "include_asm.h"
#include "piint.h"

s32 __osEPiRawWriteIo(OSPiHandle*, u32, u32);

s32 osEPiWriteIo(OSPiHandle* pihandle, u32 devAddr, u32 data) {
    register s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawWriteIo(pihandle, devAddr, data);
    __osPiRelAccess();

    return ret;
}
