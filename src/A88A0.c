/* A88A0: libultra os/getmemsize.c (osGetMemSize) and os/initialize.c (createSpeedParam), from
   MP1 src/lib/2.0I/os/. __osInitialize_common stays in asm (near, not an exact match of MP1). */
#define osGetMemSize func_800A7CA0_A88A0
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/R4300.h"
#include "osint.h"
#include "include_asm.h"

extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;

#ifndef DEVICE_TYPE_INIT
#define DEVICE_TYPE_INIT 7
#endif

#define STEP 0x100000
#define SIZE_4MB 0x400000
#define SIZE_8MB 0x800000

u32 osGetMemSize(void) {
    vu32* ptr;
    u32 size = SIZE_4MB;
    u32 data0;
    u32 data1;

    while (size < SIZE_8MB) {
        ptr = (vu32*)(K1BASE + size);
        data0 = *ptr;
        data1 = ptr[STEP / 4 - 1];
        *ptr ^= ~0;
        ptr[STEP / 4 - 1] ^= ~0;
        if ((*ptr != (data0 ^ ~0)) || (ptr[STEP / 4 - 1] != (data1 ^ ~0))) {
            return size;
        }
        *ptr = data0;
        ptr[STEP / 4 - 1] = data1;
        size += STEP;
    }
    return size;
}

INCLUDE_ASM("asm/nonmatchings/A88A0", __osInitialize_common);

void createSpeedParam(void) {
    __Dom1SpeedParam.type = DEVICE_TYPE_INIT;
    __Dom1SpeedParam.latency = IO_READ(PI_BSD_DOM1_LAT_REG);
    __Dom1SpeedParam.pulse = IO_READ(PI_BSD_DOM1_PWD_REG);
    __Dom1SpeedParam.pageSize = IO_READ(PI_BSD_DOM1_PGS_REG);
    __Dom1SpeedParam.relDuration = IO_READ(PI_BSD_DOM1_RLS_REG);
    __Dom2SpeedParam.type = DEVICE_TYPE_INIT;
    __Dom2SpeedParam.latency = IO_READ(PI_BSD_DOM2_LAT_REG);
    __Dom2SpeedParam.pulse = IO_READ(PI_BSD_DOM2_PWD_REG);
    __Dom2SpeedParam.pageSize = IO_READ(PI_BSD_DOM2_PGS_REG);
    __Dom2SpeedParam.relDuration = IO_READ(PI_BSD_DOM2_RLS_REG);
}
