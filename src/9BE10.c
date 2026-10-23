#include "common.h"
#include "sdk_leo.h"

void func_8009B23C_9BE3C(u32 start); // leoRead_common

INCLUDE_ASM("asm/nonmatchings/9BE10", func_8009B210_9BE10);

// leoRead_common (MP1 src/83960.c func_8008499C). IDO-compiled (t-register temporaries): KMC GCC
// cannot reproduce it.
#ifdef NON_MATCHING
void func_8009B23C_9BE3C(u32 start) {
    LEOCmdRead* cmd = D_800F2060_F2C60;
    u32 lba = cmd->lba;
    u32 xfer = cmd->xfer_blks;
    OSMesg msg;

    if ((((lba | xfer) >> 16) != 0) || ((lba += start) + xfer > 0x10DC)) {
        goto out_of_range;
    }
    if (xfer == 0) {
        if (lba >= 0x10DC) {
            goto out_of_range;
        }
        cmd->header.sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    D_800F2070_F2C70.lba = lba;
    D_800F206E_F2C6E &= 0x3FFF;
    osSendMesg(&D_800F1408_F2008, NULL, OS_MESG_NOBLOCK);
    osStartThread(&D_800F1620_F2220);
    while (TRUE) {
        osRecvMesg(&D_800F2000_F2C00, &msg, OS_MESG_BLOCK);
        if ((u32)msg != 0x80000) {
            break;
        }
        func_80099610_9A210();
        D_800F206E_F2C6E &= ~0x4000;
        osSendMesg(&D_800F1408_F2008, NULL, OS_MESG_NOBLOCK);
    }
    if ((u32)msg == 0x90000) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = (u32)msg;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
    return;

out_of_range:
    cmd->header.sense_code = 0x20;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/9BE10", func_8009B23C_9BE3C);
#endif
