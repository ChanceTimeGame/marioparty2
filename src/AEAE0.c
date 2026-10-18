#include "PR/os_internal.h"
#include "PR/siint.h"

/* __osSiRawWriteIo: libultra io/sirawwrite.c, from MP1 src/9ABB0.c. */

s32 __osSiRawWriteIo(u32 devAddr, u32 data) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    IO_WRITE(devAddr, data);
    return 0;
}
