#include "common.h"
#include "sdk_leo.h"

// libleo manager API (MP1 80770.c), built with IDO 5.3.

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);

void func_8009A700_9B300(void*);
void func_80097160_97D60(void*);
void func_800983D0_98FD0(void);
void func_80098650_99250(void);

extern s32 D_800CDD10_CE910;
extern s32 D_800CDD14_CE914;
extern LEOCmdHeader D_800D3A20_D4620;
extern OSMesgQueue D_800F13E0_F1FE0;
extern OSMesg D_800F13F8_F1FF8;
extern OSThread D_800F1470_F2070;
extern OSThread D_800F1620_F2220;
extern u8 D_800F1BD0_F27D0[];
extern OSMesgQueue D_800F1FD0_F2BD0;
extern OSMesgQueue D_800F1FE8_F2BE8;
extern OSMesgQueue D_800F2000_F2C00;
extern OSMesgQueue D_800F2018_F2C18;
extern OSMesgQueue D_800F2030_F2C30;
extern OSMesg D_800F2048_F2C48;
extern OSMesg D_800F204C_F2C4C;
extern OSMesg D_800F2050_F2C50[2];
extern OSMesg D_800F2058_F2C58;

// IDO-compiled libleo (LeoCreateLeoManager)
void func_80096CF0_978F0(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri curPri;
    OSPri myPri;

    if (intPri < comPri) {
        myPri = comPri;
    } else {
        myPri = intPri;
    }
    oldPri = -1;
    curPri = osGetThreadPri(NULL);
    if (curPri < myPri) {
        oldPri = curPri;
        osSetThreadPri(NULL, myPri);
    }
    savedMask = __osDisableInt();
    D_800CDD14_CE914 = 1;
    osCreateMesgQueue(&D_800F1FD0_F2BD0, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&D_800F2000_F2C00, &D_800F204C_F2C4C, 1);
    osCreateMesgQueue(&D_800F1FE8_F2BE8, &D_800F2048_F2C48, 1);
    osCreateMesgQueue(&D_800F2018_F2C18, D_800F2050_F2C50, 2);
    osCreateMesgQueue(&D_800F2030_F2C30, &D_800F2058_F2C58, 1);
    osCreateMesgQueue(&D_800F13E0_F1FE0, &D_800F13F8_F1FF8, 1);
    osCreateThread(&D_800F1470_F2070, 1, func_8009A700_9B300, NULL, D_800F1BD0_F27D0, comPri);
    osStartThread(&D_800F1470_F2070);
    osCreateThread(&D_800F1620_F2220, 1, func_80097160_97D60, NULL, &D_800F1FD0_F2BD0, intPri);
    osStartThread(&D_800F1620_F2220);
    osSetEventMesg(OS_EVENT_CART, &D_800F1FE8_F2BE8, (OSMesg)0x30000);
    osSendMesg(&D_800F2030_F2C30, NULL, OS_MESG_NOBLOCK);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

// IDO-compiled libleo (leoCommand)
void func_80096EC4_97AC4(LEOCmdRead* cmd) {
    if (D_800CDD10_CE910 != 0) {
        cmd->header.status = 2;
        cmd->header.sense_code = 0x25;
        if (cmd->header.control & 0x80) {
            osSendMesg(cmd->header.post, (OSMesg)0x25, OS_MESG_BLOCK);
        }
        return;
    }
    osRecvMesg(&D_800F2030_F2C30, NULL, OS_MESG_BLOCK);
    cmd->header.status = 8;
    cmd->header.sense_code = 0;
    switch (cmd->header.command) {
        case 1:
            D_800F206D_F2C6D = 0xFF;
            func_80098650_99250();
            D_800F206D_F2C6D = 0;
            cmd->header.status = 0;
            if (cmd->header.control & 0x80) {
                osSendMesg(cmd->header.post, NULL, OS_MESG_BLOCK);
            }
            break;
        case 5:
        case 6:
            cmd->rw_bytes = 0;
            goto send;
        default:
            if ((u32)(cmd->header.command - 1) >= 14) {
                cmd->header.sense_code = 0x1F;
                cmd->header.status = 2;
                break;
            }
        send:
            if (osSendMesg(&D_800F1FD0_F2BD0, cmd, OS_MESG_NOBLOCK) != 0) {
                cmd->header.sense_code = 0x23;
                cmd->header.status = 2;
            }
            break;
    }
    osSendMesg(&D_800F2030_F2C30, NULL, OS_MESG_BLOCK);
}

// IDO-compiled libleo (LeoReset)
void func_80097024_97C24(void) {
    D_800CDD10_CE910 = 1;
    if (D_800CDD14_CE914 != 0) {
        D_800F206D_F2C6D = 0xFF;
        func_80098650_99250();
        D_800F206D_F2C6D = 0;
        osRecvMesg(&D_800F1FE8_F2BE8, NULL, OS_MESG_NOBLOCK);
        osSendMesg(&D_800F1FE8_F2BE8, (OSMesg)0xA0000, OS_MESG_BLOCK);
        osSendMesg(&D_800F1FD0_F2BD0, &D_800D3A20_D4620, OS_MESG_BLOCK);
    }
}

// IDO-compiled libleo (LeoResetClear)
s32 func_800970B4_97CB4(void) {
    func_800983D0_98FD0();
    return 0;
}

// IDO-compiled libleo (LeoTestUnitReady)
u8 func_800970D8_97CD8(void) {
    LEOCmdHeader cmd;

    cmd.command = 0xF;
    cmd.control = 0x80;
    cmd.status = 0;
    cmd.post = &D_800F13E0_F1FE0;
    if (osSendMesg(&D_800F1FD0_F2BD0, &cmd, OS_MESG_NOBLOCK) != 0) {
        return 0x23;
    }
    osRecvMesg(&D_800F13E0_F1FE0, NULL, OS_MESG_BLOCK);
    if (cmd.status == 0) {
        return 0;
    }
    return cmd.sense_code;
}
