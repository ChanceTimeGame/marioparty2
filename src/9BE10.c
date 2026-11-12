#include "common.h"
#include "sdk_leo.h"

void func_8009B23C_9BE3C(u32 start); // leoRead_common

// leoRead
void func_8009B210_9BE10(void) {
    D_800F206E_F2C6E = 0;
    func_8009B23C_9BE3C(24);
}

// leoRead_common (MP1 src/83960.c func_8008499C). Under IDO 5.3 the frame is one saved register
// short: retail keeps &LEOcur_command in s6 across the calls.
#ifdef NON_MATCHING
void func_8009B23C_9BE3C(u32 start) {
    u32 lba = LEO_CUR(LEOCmdRead)->lba;
    u32 xfer = LEO_CUR(LEOCmdRead)->xfer_blks;
    u32 msg;

    if ((lba | xfer) & 0xFFFF0000) {
        goto out_of_range;
    }
    lba += start;
    if (lba + xfer > 0x10DC) {
    out_of_range:
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (xfer == 0) {
        if (lba < 0x10DC) {
            LEO_CUR(LEOCmdHeader)->sense_code = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        } else {
            goto out_of_range;
        }
        return;
    }
    D_800F2070_F2C70.lba = lba;
    D_800F206E_F2C6E &= 0x3FFF;
    osSendMesg(&D_800F1408_F2008, NULL, OS_MESG_NOBLOCK);
    osStartThread(&D_800F1620_F2220);
    while (TRUE) {
        osRecvMesg(&D_800F2000_F2C00, (OSMesg*)&msg, OS_MESG_BLOCK);
        switch (msg) {
            case 0x80000:
                func_80099610_9A210();
                D_800F206E_F2C6E &= ~0x4000;
                osSendMesg(&D_800F1408_F2008, NULL, OS_MESG_NOBLOCK);
                break;
            case 0x90000:
                LEO_CUR(LEOCmdHeader)->sense_code = 0;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
                return;
            default:
                LEO_CUR(LEOCmdHeader)->sense_code = msg;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9BE10", func_8009B23C_9BE3C);
#endif
