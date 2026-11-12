#include "common.h"
#include "sdk_leo.h"

// 64DD driver (libleo) microsequence loader (leoSet_mseq and its two tables) and the command
// queue flush (MP1 80BE0.c). Built with IDO 5.3; the tables come first in its rodata, after the
// previous unit's jump tables, so this is a separate file (IDO emits a file's const data before its
// jump tables). func_800984A0_990A0 does not match yet (masked residue 86) and stays asm.

// read microsequence (loaded by func_800984A0_990A0)
const u32 D_800D3AA0_D46A0[16] = {
    0x00010000, 0x00020200, 0x80030100, 0x82040000, 0xA8050000, 0xA0060600,
    0x31760000, 0x00020300, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x04060000,
};

// write microsequence
const u32 D_800D3AE0_D46E0[16] = {
    0x40020000, 0x00020000, 0x40130B00, 0x42140100, 0x68050000, 0x50060600,
    0x401702FF, 0x01870000, 0x40020000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x040F0000,
};

// unreferenced; ends this unit's rodata
const char D_800D3B20_D4720[] = "B014A26";

// IDO-compiled libleo (leoSet_mseq: load the read or write microsequence)
#ifdef NON_MATCHING
void func_800984A0_990A0(u16 rwmode) {
    const u32* src;
    u8 i;
    u32 secm1;
    u32 sec;

    D_800F2068_F2C68 &= ~0x40000000;
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000518, D_800F2068_F2C68);
    if (rwmode == 1) {
        src = D_800D3AE0_D46E0;
    } else {
        src = D_800D3AA0_D46A0;
    }
    for (i = 0; i < 16; i++) {
        D_800F1430_F2030[i] = *src++;
    }
    secm1 = D_800F2070_F2C70.sec_bytes - 1;
    D_800F1430_F2030[4] |= secm1 << 8;
    osWritebackDCache(D_800F1430_F2030, sizeof(D_800F1430_F2030));
    D_800F28E8_F34E8.dramAddr = D_800F1430_F2030;
    D_800F28E8_F34E8.devAddr = 0x05000580;
    D_800F28E8_F34E8.size = sizeof(D_800F1430_F2030);
    D_800F28E0_F34E0->transferInfo.cmdType = OS_OTHERS;
    osEPiStartDma(D_800F28E0_F34E0, &D_800F28E8_F34E8, OS_WRITE);
    osRecvMesg(&D_800F2018_F2C18, NULL, OS_MESG_BLOCK);
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000530, ((secm1 + 7) | 0x5900) << 16);
    sec = secm1 << 8;
    if (D_800F206E_F2C6E & 0x800) {
        sec += 0x100;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000528, sec << 8);
    D_800F2068_F2C68 |= 0x40000000;
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000518, D_800F2068_F2C68);
}
#else
INCLUDE_ASM("asm/nonmatchings/990A0", func_800984A0_990A0);
#endif

// IDO-compiled libleo (flush the command queue: every pending command is terminated)
void func_80098650_99250(void) {
    LEOCmdHeader* cmd;

    while (osRecvMesg(&D_800F1FD0_F2BD0, (OSMesg*)&cmd, OS_MESG_NOBLOCK) == 0) {
        cmd->sense_code = 0x22;
        cmd->status = 2;
        if (cmd->control & 0x80) {
            osSendMesg(cmd->post, (OSMesg)0x22, OS_MESG_BLOCK);
        }
    }
}

// IDO-compiled libleo
void func_800986F8_992F8(void) {
    u32 sense;

    sense = func_80097B50_98750();
    if (sense == 3 || sense == 0x29 || sense == 0x2B) {
        D_800F2060_F2C60->header.sense_code = sense;
        D_800F2060_F2C60->header.status = 2;
    } else {
        D_800F2060_F2C60->header.sense_code = 0;
        D_800F2060_F2C60->header.status = 0;
    }
}
