#include "PR/os_internal.h"
#include "PR/piint.h"

/* libultra PI raw access: io/pirawdma.c, io/pigetcmdq.c and io/epirawread.c, from MP1
   src/lib/2.0I/io/pirawdma.c, src/95F40.c and src/99F50.c. */

s32 __osPiRawStartDma(s32 direction, u32 devAddr, void* dramAddr, u32 size) {
    register u32 stat;

    WAIT_ON_IOBUSY(stat);

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS((u32)osRomBase | devAddr));

    switch (direction) {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}

OSMesgQueue* osPiGetCmdQueue(void) {
    if (!__osPiDevMgr.active) {
        return NULL;
    } else {
        return __osPiDevMgr.cmdQueue;
    }
}

s32 __osEPiRawReadIo(OSPiHandle* pihandle, u32 devAddr, u32* data) {
    register u32 stat;
    register u32 domain;

    EPI_SYNC(pihandle, stat, domain);
    *data = IO_READ(pihandle->baseAddress | devAddr);
    return 0;
}
