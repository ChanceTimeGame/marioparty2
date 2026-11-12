#include "common.h"
#include "PR/piint.h"
#include "PR/osint.h"

// libultra 64DD interrupt handling (leointerrupt.c) and osLeoDiskInit (leodiskinit.c), as MP1
// 82AF0.c. Built with IDO 5.3 with libleo.

#define LEO_IO_READ(addr) (*(vu32*)((addr) | 0xA0000000))
#define LEO_IO_WRITE(addr, data) (*(vu32*)((addr) | 0xA0000000) = (u32)(data))

#define LEO_STATUS 0x05000508
#define LEO_BM_CTL 0x05000510
#define LEO_BM_STATUS 0x05000510
#define LEO_C2_BUFF 0x05000000
#define LEO_SECTOR_BUFF 0x05000400

#define LEO_STATUS_DATA_REQUEST 0x40000000
#define LEO_STATUS_C2_TRANSFER 0x10000000
#define LEO_STATUS_BUFFER_MANAGER_ERROR 0x08000000
#define LEO_STATUS_MECHANIC_INTERRUPT 0x02000000
#define LEO_BM_STATUS_C1SINGLE 0x00400000
#define LEO_BM_STATUS_C1DOUBLE 0x00200000
#define LEO_BM_STATUS_MICRO 0x02000000
#define LEO_BM_CTL_RESET 0x10000000
#define LEO_BM_CTL_CLR_MECHANIC_INTR 0x01000000

#define LEO_CMD_TYPE_0 0
#define LEO_CMD_TYPE_1 1
#define LEO_CMD_TYPE_2 2
#define LEO_TRACK_MODE 2
#define LEO_SECTOR_MODE 3

#define WAIT_ON_IOBUSY(stat)                                                           \
    while (stat = LEO_IO_READ(PI_STATUS_REG), stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) \
        ;

extern OSPiHandle D_800F3A00_F4600;      // LeoDiskHandle
extern OSPiHandle* D_800F3A74_F4674;     // __osDiskHandle
extern OSMesgQueue* D_80101378_101F78;    // __osEventStateTab[OS_EVENT_PI].messageQueue
extern OSMesg D_8010137C_101F7C;          // __osEventStateTab[OS_EVENT_PI].message
extern OSThread* __osRunQueue;

s32 __osEPiRawStartDma(OSPiHandle* pihandle, s32 direction, u32 devAddr, void* dramAddr, u32 size);
void __osEnqueueThread(OSThread** queue, OSThread* t);
OSThread* __osPopThread(OSThread** queue);

void __osLeoAbnormalResume(void);
void __osLeoResume(void);

s32 __osLeoInterrupt(void) {
    u32 stat = 0;
    volatile u32 pi_stat;
    u32 bm_stat;
    __OSTranxInfo* info = &D_800F3A74_F4674->transferInfo;
    __OSBlockInfo* blockInfo = &info->block[info->blockNum];

    pi_stat = LEO_IO_READ(PI_STATUS_REG);
    if (pi_stat & PI_STATUS_DMA_BUSY) {
        __OSGlobalIntMask = __OSGlobalIntMask & ~0x800; // SR_IBIT4: cartridge interrupt
        blockInfo->errStatus = 29;
        __osLeoResume();
        return 1;
    }
    WAIT_ON_IOBUSY(pi_stat);
    stat = LEO_IO_READ(LEO_STATUS);
    if (stat & LEO_STATUS_MECHANIC_INTERRUPT) {
        WAIT_ON_IOBUSY(pi_stat);
        LEO_IO_WRITE(LEO_BM_CTL, info->bmCtlShadow | LEO_BM_CTL_CLR_MECHANIC_INTR);
        blockInfo->errStatus = 0;
        return 0;
    }
    if (info->cmdType == LEO_CMD_TYPE_2) {
        return 1;
    }
    if (stat & LEO_STATUS_BUFFER_MANAGER_ERROR) {
        WAIT_ON_IOBUSY(pi_stat);
        stat = LEO_IO_READ(LEO_STATUS);
        blockInfo->errStatus = 22;
        __osLeoResume();
        LEO_IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
        __OSGlobalIntMask |= OS_IM_PI;
        return 1;
    }
    if (info->cmdType == LEO_CMD_TYPE_1) {
        if ((stat & LEO_STATUS_DATA_REQUEST) == 0) {
            if (info->sectorNum + 1 != info->transferMode * 85) {
                blockInfo->errStatus = 24;
                __osLeoAbnormalResume();
                return 1;
            }
            LEO_IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
            __OSGlobalIntMask |= OS_IM_PI;
            blockInfo->errStatus = 0;
            __osLeoResume();
            return 1;
        } else {
            blockInfo->dramAddr = (void*)((u32)blockInfo->dramAddr + blockInfo->sectorSize);
            info->sectorNum++;
            __osEPiRawStartDma(D_800F3A74_F4674, OS_WRITE, LEO_SECTOR_BUFF, blockInfo->dramAddr, blockInfo->sectorSize);
            return 1;
        }
    } else if (info->cmdType == LEO_CMD_TYPE_0) {
        if (info->transferMode == LEO_SECTOR_MODE) {
            if (info->sectorNum > (s32)blockInfo->C1ErrNum + 17) {
                blockInfo->errStatus = 0;
                __osLeoAbnormalResume();
                return 1;
            }
            if ((stat & LEO_STATUS_DATA_REQUEST) == 0) {
                blockInfo->errStatus = 23;
                __osLeoAbnormalResume();
                return 1;
            }
        } else {
            blockInfo->dramAddr = (void*)((u32)blockInfo->dramAddr + blockInfo->sectorSize);
        }
        bm_stat = LEO_IO_READ(LEO_BM_STATUS);
        if (((bm_stat & LEO_BM_STATUS_C1DOUBLE) && (bm_stat & LEO_BM_STATUS_C1SINGLE)) ||
            (bm_stat & LEO_BM_STATUS_MICRO)) {
            if (blockInfo->C1ErrNum > 3) {
                if ((info->transferMode != LEO_SECTOR_MODE) || (info->sectorNum > 0x52)) {
                    blockInfo->errStatus = 23;
                    __osLeoAbnormalResume();
                    return 1;
                }
            } else {
                int errNum = blockInfo->C1ErrNum;
                blockInfo->C1ErrSector[errNum] = info->sectorNum + 1;
            }
            blockInfo->C1ErrNum++;
        }
        if (stat & LEO_STATUS_C2_TRANSFER) {
            if (info->sectorNum + 1 != 88) {
                blockInfo->errStatus = 24;
                __osLeoAbnormalResume();
                return 1;
            }
            if ((info->transferMode == LEO_TRACK_MODE) && (info->blockNum == 0)) {
                info->blockNum = 1;
                info->sectorNum = -1;
                info->block[1].dramAddr = (void*)((u32)info->block[1].dramAddr - info->block[1].sectorSize);
                blockInfo->errStatus = 22;
            } else {
                LEO_IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
                __OSGlobalIntMask |= OS_IM_PI;
                info->cmdType = LEO_CMD_TYPE_2;
                blockInfo->errStatus = 0;
            }
            __osEPiRawStartDma(D_800F3A74_F4674, OS_READ, LEO_C2_BUFF, blockInfo->C2Addr, blockInfo->sectorSize * 4);
            return 1;
        }
        if ((info->sectorNum == -1) && (info->transferMode == LEO_TRACK_MODE) && (info->blockNum == 1)) {
            __OSBlockInfo* bptr = &info->block[0];

            if (bptr->C1ErrNum == 0) {
                if (((u32*)bptr->C2Addr)[0] | ((u32*)bptr->C2Addr)[1] | ((u32*)bptr->C2Addr)[2] |
                    ((u32*)bptr->C2Addr)[3]) {
                    bptr->errStatus = 23;
                    __osLeoAbnormalResume();
                    return 1;
                }
            }
            bptr->errStatus = 0;
            __osLeoResume();
        }
        info->sectorNum++;
        if (stat & LEO_STATUS_DATA_REQUEST) {
            if (info->sectorNum > 0x54) {
                blockInfo->errStatus = 24;
                __osLeoAbnormalResume();
                return 1;
            }
            __osEPiRawStartDma(D_800F3A74_F4674, OS_READ, LEO_SECTOR_BUFF, blockInfo->dramAddr, blockInfo->sectorSize);
            blockInfo->errStatus = 0;
            return 1;
        } else if (info->sectorNum <= 0x54) {
            blockInfo->errStatus = 24;
            __osLeoAbnormalResume();
            return 1;
        }
        return 1;
    } else {
        blockInfo->errStatus = 4;
        __osLeoAbnormalResume();
        return 1;
    }
}

void __osLeoAbnormalResume(void) {
    __OSTranxInfo* info = &D_800F3A74_F4674->transferInfo;
    u32 pi_stat;

    WAIT_ON_IOBUSY(pi_stat);
    LEO_IO_WRITE(LEO_BM_CTL, info->bmCtlShadow | LEO_BM_CTL_RESET);
    WAIT_ON_IOBUSY(pi_stat);
    LEO_IO_WRITE(LEO_BM_CTL, info->bmCtlShadow);
    __osLeoResume();
    LEO_IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
    __OSGlobalIntMask |= OS_IM_PI;
}

void __osLeoResume(void) {
    OSMesgQueue* mq = D_80101378_101F78;
    s32 last;

    if ((mq == NULL) || (mq->validCount >= mq->msgCount)) {
        return;
    }
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = D_8010137C_101F7C;
    mq->validCount++;
    if (mq->mtqueue->next != NULL) {
        __osEnqueueThread(&__osRunQueue, __osPopThread(&mq->mtqueue));
    }
}

OSPiHandle* osLeoDiskInit(void) {
    u32 saveMask;

    D_800F3A00_F4600.type = DEVICE_TYPE_64DD;
    D_800F3A00_F4600.baseAddress = 0xA5000000; // PHYS_TO_K1(PI_DOM2_ADDR1)
    D_800F3A00_F4600.latency = 3;
    D_800F3A00_F4600.pulse = 6;
    D_800F3A00_F4600.pageSize = 6;
    D_800F3A00_F4600.relDuration = 2;
    D_800F3A00_F4600.domain = PI_DOMAIN2;
    D_800F3A00_F4600.speed = 0;
    bzero(&D_800F3A00_F4600.transferInfo, sizeof(__OSTranxInfo));
    saveMask = __osDisableInt();
    D_800F3A00_F4600.next = __osPiTable;
    __osPiTable = &D_800F3A00_F4600;
    D_800F3A74_F4674 = &D_800F3A00_F4600;
    __osRestoreInt(saveMask);
    return &D_800F3A00_F4600;
}
