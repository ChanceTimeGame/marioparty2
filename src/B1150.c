#include "PR/os_internal.h"
#include "PR/rcp.h"

/* __osSiDeviceBusy: libultra io/sirawdma.c's helper, from MP1 src/9AD00.c. */

int __osSiDeviceBusy(void) {
    register u32 stat = IO_READ(SI_STATUS_REG);

    if (stat & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
