#include "PR/os_internal.h"
#include "PR/siint.h"

/* __osSiRawReadIo: libultra io/sirawread.c, from MP1 src/9AB60.c. */

s32 __osSiRawReadIo(u32 devAddr, u32* data) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    *data = IO_READ(devAddr);
    return 0;
}
