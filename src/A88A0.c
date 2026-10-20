/* A88A0: libultra os/getmemsize.c (osGetMemSize) and os/initialize.c (createSpeedParam), from
   MP1 src/lib/2.0I/os/. __osInitialize_common is MP1's plus a __osSetWatchLo call. */
#define osGetMemSize func_800A7CA0_A88A0
#define __osGetSR func_800ADD60_AE960
#define __osSetFpcCsr func_800ADD70_AE970
#define __osFinalrom D_80101634_102234
#define osClockRate D_800CF0A0_CFCA0
#define osResetType D_8000030C
#define osAppNMIBuffer D_8000031C
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/R4300.h"
#include "osint.h"
#include "include_asm.h"

extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;

typedef struct {
    /* 0x0 */ unsigned int inst1;
    /* 0x4 */ unsigned int inst2;
    /* 0x8 */ unsigned int inst3;
    /* 0xC */ unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble[];
extern u32 __osFinalrom;
extern s32 __osSiRawReadIo(u32, u32*);
extern s32 __osSiRawWriteIo(u32, u32);
extern void osUnmapTLBAll(void);
extern void osMapTLBRdb(void);
extern void __osSetWatchLo(u32);
void createSpeedParam(void);

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

void __osInitialize_common(void) {
    u32 pifdata;

    __osFinalrom = TRUE;
    __osSetSR(__osGetSR() | SR_CU1);
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV | FPCSR_RM_RN);
    __osSetWatchLo(0x4900000);
    while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) {
        ;
    }
    while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8)) {
        ;
    }
    *(__osExceptionVector*)UT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*)XUT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*)ECC_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*)E_VEC = *__osExceptionPreamble;
    osWritebackDCache((void*)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void*)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    createSpeedParam();
    osUnmapTLBAll();
    osMapTLBRdb();
    osClockRate = osClockRate * 3 / 4;
    if (osResetType == 0) {
        bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }
    if (osTvType == OS_TV_PAL) {
        osViClock = VI_PAL_CLOCK;
    } else if (osTvType == OS_TV_MPAL) {
        osViClock = VI_MPAL_CLOCK;
    } else {
        osViClock = VI_NTSC_CLOCK;
    }
    if (__osGetCause() & CAUSE_IP5) {
        while (TRUE) {
            ;
        }
    }
    IO_WRITE(AI_CONTROL_REG, AI_CONTROL_DMA_ON);
    IO_WRITE(AI_DACRATE_REG, AI_MAX_DAC_RATE - 1);
    IO_WRITE(AI_BITRATE_REG, AI_MAX_BIT_RATE - 1);
}

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
