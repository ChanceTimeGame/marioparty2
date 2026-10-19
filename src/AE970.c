/* AE970: __osSpDeviceBusy (libultra io/sp.c) from MP1 src/95CC0.c; the two small functions before it
   have no MP1/MP3 C reference and stay in asm. */
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/AE970", func_800ADD70_AE970);

INCLUDE_ASM("asm/nonmatchings/AE970", __osSetWatchLo);

int __osSpDeviceBusy(void) {
    register u32 stat = IO_READ(SP_STATUS_REG);

    if (stat & (SP_STATUS_DMA_BUSY | SP_STATUS_DMA_FULL | SP_STATUS_IO_FULL)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
