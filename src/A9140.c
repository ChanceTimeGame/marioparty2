#include "PR/os_internal.h"
#include "PR/piint.h"

/* __osEPiRawWriteIo: libultra io/epirawwrite.c, from MP1 src/9A0C0.c. */

s32 __osEPiRawWriteIo(OSPiHandle* pihandle, u32 devAddr, u32 data) {
    register u32 stat;
    register u32 domain;

    EPI_SYNC(pihandle, stat, domain);
    IO_WRITE(pihandle->baseAddress | devAddr, data);
    return 0;
}
