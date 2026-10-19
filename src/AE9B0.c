/* AE9B0: libultra io/spgetstat.c, spsetstat.c, spsetpc.c (MP1 src/95CE0.c) and io/sprawdma.c
   (MP1 src/lib/2.0I/io/sprawdma.c). */
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "osint.h"
#include "libc/assert.h"

u32 __osSpGetStatus(void) {
    return IO_READ(SP_STATUS_REG);
}

void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}

s32 __osSpSetPc(u32 pc) {
    register u32 status = IO_READ(SP_STATUS_REG);

    if (!(status & SP_STATUS_HALT)) {
        return -1;
    }
    IO_WRITE(SP_PC_REG, pc);
    return 0;
}

s32 __osSpRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size) {
    // These asserts are present in debug builds, but the line numbers won't match as-is
    // TODO Add an assert spoofing macro that lets you specify a line number
    assert(((u32)devAddr & 0x7) == 0);
    assert(((u32)dramAddr & 0x7) == 0);
    assert(((u32)size & 0x7) == 0);

    if (__osSpDeviceBusy()) {
        return -1;
    }
    
    IO_WRITE(SP_MEM_ADDR_REG, devAddr);
    IO_WRITE(SP_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    
    if (direction == OS_READ) {
        IO_WRITE(SP_WR_LEN_REG, size - 1);
    } else {
        IO_WRITE(SP_RD_LEN_REG, size - 1);
    }

    return 0;
}
