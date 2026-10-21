#include "common.h"
#include "sdk_leo.h"

// 64DD driver (libleo) read/write thread and mechanism control (MP1 80BE0.c). IDO-compiled: its
// register allocation (t6, t7, ... temporaries, ra at 0x14(sp)) cannot be reproduced, so every
// function except the trivial leoChk_mecha_int is NON_MATCHING C with the asm in the matching
// build. The unit's rodata (D4630-D4728) is defined here so it is one carved piece; it comes before
// every INCLUDE_ASM because GCC does not see an INCLUDE_ASM switch to .text.

#ifndef NON_MATCHING
// func_80098280_98E80's jump tables (its two switches); the two zero words are the padding before
// the microsequences
const u32 jtbl_800D3A30_D4630[] __attribute__((aligned(8), section(".rodata"))) = {
    0x800982F4, 0x80098384, 0x80098384, 0x80098384, 0x800982F4, 0x800982F4,
    0x800982E0, 0x80098384, 0x80098384, 0x80098384, 0x80098384, 0x80098384,
    0x800982F4,
};
const u32 jtbl_800D3A64_D4664[] __attribute__((section(".rodata"))) = {
    0x80098374, 0x80098384, 0x80098384, 0x80098384, 0x80098374, 0x80098374,
    0x8009834C, 0x80098384, 0x80098384, 0x80098384, 0x80098360, 0x80098384,
    0x80098374, 0, 0,
};
#endif

// read microsequence (loaded by func_800984A0_990A0)
const u32 D_800D3AA0_D46A0[16] __attribute__((aligned(8), section(".rodata"))) = {
    0x00010000, 0x00020200, 0x80030100, 0x82040000, 0xA8050000, 0xA0060600,
    0x31760000, 0x00020300, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x04060000,
};

// write microsequence
const u32 D_800D3AE0_D46E0[16] __attribute__((aligned(8), section(".rodata"))) = {
    0x40020000, 0x00020000, 0x40130B00, 0x42140100, 0x68050000, 0x50060600,
    0x401702FF, 0x01870000, 0x40020000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x040F0000,
};

// unreferenced; ends this unit's piece of the rodata
const char D_800D3B20_D4720[] __attribute__((section(".rodata"))) = "B014A26";

// IDO-compiled libleo (read/write command thread)
#ifdef NON_MATCHING
void func_80097160_97D60(void* arg) {
    u32 blocks;
    u32 n;
    u32 sense;

    osCreateMesgQueue(&D_800F1408_F2008, &D_800F1400_F2000, 1);
    while (TRUE) {
        osStopThread(&D_800F1620_F2220);
        blocks = D_800F2060_F2C60->xfer_blks;
        D_800F205C_F2C5C = D_800F2060_F2C60->buff_ptr;
        while (TRUE) {
            func_80098770_99370(D_800F2070_F2C70.lba);
            if (D_800F206E_F2C6E & 0x8000) {
                sense = func_8009818C_98D8C(1);
            } else {
                sense = func_8009818C_98D8C(0);
            }
            if (sense != 0) {
                break;
            }
            if (D_800F206E_F2C6E & 0x2000) {
                n = 1;
                D_800F2070_F2C70.rdwr_blocks = 1;
            } else {
                n = D_800F2070_F2C70.rdwr_blocks;
                if (blocks < n) {
                    n = blocks & 0xFF;
                    D_800F2070_F2C70.rdwr_blocks = blocks;
                }
            }
            blocks -= n;
            D_800F2070_F2C70.lba += n;
            sense = func_800972F0_97EF0();
            if (sense != 0) {
                break;
            }
            D_800F2060_F2C60->rw_bytes = D_800F205C_F2C5C - D_800F2060_F2C60->buff_ptr;
            if (blocks == 0) {
                sense = 0x90000;
                break;
            }
        }
        osSendMesg(&D_800F2000_F2C00, (OSMesg)sense, OS_MESG_BLOCK);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097160_97D60);
#endif

// IDO-compiled libleo (one sector transfer with C1/C2 error handling and retries)
#ifdef NON_MATCHING
u32 func_800972F0_97EF0(void) {
    LEORwInfo info;
    u32 sense;
    u16 blkBytes;
    s32 retry;
    s32 i;
    __OSBlockInfo* blk;
    u8* c2;
    u32* c2w;

    blkBytes = D_800F2070_F2C70.blk_bytes;
    info.secBytes = D_800F2070_F2C70.sec_bytes;
    if (D_800F206E_F2C6E & 0x2000) {
        blkBytes = info.secBytes;
    }
    info.dram = D_800F205C_F2C5C;
    D_800F205C_F2C5C += blkBytes;
    info.blkBytes = blkBytes;
    if (D_800F2070_F2C70.rdwr_blocks == 2) {
        D_800F205C_F2C5C += blkBytes;
        info.blkBytes = blkBytes;
    }
    retry = 0;

    while (TRUE) {
        D_800F28E0_F34E0->transferInfo.transferMode = 1;
        D_800F28E0_F34E0->transferInfo.blockNum = 0;
        D_800F28E0_F34E0->transferInfo.block[0].C1ErrNum = 0;
        D_800F28E0_F34E0->transferInfo.block[0].sectorSize = info.secBytes;
        D_800F28E0_F34E0->transferInfo.block[0].dramAddr = info.dram;
        D_800F28E0_F34E0->transferInfo.block[0].C2Addr = D_800F2180_F2D80;
        if (D_800F206E_F2C6E & 0x2000) {
            D_800F2070_F2C70.rdwr_blocks = 1;
            D_800F28E0_F34E0->transferInfo.transferMode = 3;
        } else if (D_800F2070_F2C70.rdwr_blocks == 2) {
            D_800F28E0_F34E0->transferInfo.transferMode = 2;
            D_800F28E0_F34E0->transferInfo.block[1] = D_800F28E0_F34E0->transferInfo.block[0];
            D_800F28E0_F34E0->transferInfo.block[1].C2Addr = D_800F2520_F3120;
            D_800F28E0_F34E0->transferInfo.block[1].dramAddr = (u8*)D_800F28E0_F34E0->transferInfo.block[1].dramAddr + info.blkBytes;
        }

        sense = func_800978EC_984EC();
        if (sense == 0) {
            if (D_800F206E_F2C6E & 0x8000) {
                func_800984A0_990A0(1);
            } else {
                func_800984A0_990A0(0);
            }
            func_80097954_98554();
            D_800F28E0_F34E0->transferInfo.bmCtlShadow = D_800F2064_F2C64;
            D_800F28E0_F34E0->transferInfo.seqCtlShadow = D_800F2068_F2C68;
            if (D_800F206E_F2C6E & 0x8000) {
                D_800F28E0_F34E0->transferInfo.cmdType = OS_WRITE;
                osWritebackDCache(info.dram, info.blkBytes * D_800F2070_F2C70.rdwr_blocks);
                osEPiStartDma(D_800F28E0_F34E0, &D_800F28E8_F34E8, OS_WRITE);
                osRecvMesg(&D_800F2018_F2C18, NULL, OS_MESG_BLOCK);
                D_800F2064_F2C64 = D_800F28E0_F34E0->transferInfo.bmCtlShadow;
                D_800F2068_F2C68 = D_800F28E0_F34E0->transferInfo.seqCtlShadow;
                sense = D_800F28E0_F34E0->transferInfo.block[D_800F28E0_F34E0->transferInfo.blockNum].errStatus;
                if (sense == 0) {
                    return 0;
                }
                goto error;
            }

            i = 0;
            if (D_800F206E_F2C6E & 0x4000) {
                osRecvMesg(&D_800F1408_F2008, NULL, OS_MESG_BLOCK);
                osSendMesg(&D_800F1408_F2008, NULL, OS_MESG_NOBLOCK);
            }
            D_800F28E0_F34E0->transferInfo.cmdType = OS_READ;
            osInvalDCache(info.dram, info.blkBytes * D_800F2070_F2C70.rdwr_blocks);
            osEPiStartDma(D_800F28E0_F34E0, &D_800F28E8_F34E8, OS_READ);
            if (D_800F2070_F2C70.rdwr_blocks == 0) {
                return 0;
            }
            while (TRUE) {
                osRecvMesg(&D_800F2018_F2C18, NULL, OS_MESG_BLOCK);
                blk = &D_800F28E0_F34E0->transferInfo.block[i];
                D_800F2064_F2C64 = D_800F28E0_F34E0->transferInfo.bmCtlShadow;
                D_800F2068_F2C68 = D_800F28E0_F34E0->transferInfo.seqCtlShadow;
                sense = blk->errStatus;
                if (sense != 0) {
                    goto error;
                }
                if (D_800F206E_F2C6E & 0x2000) {
                    return 0;
                }
                if (blk->C1ErrNum != 0) {
                    if (blk->C1ErrSector[0] < 0x55) {
                        if (D_800F2070_F2C70.rdwr_blocks == 1) {
                            osEPiReadIo(D_800F28E0_F34E0, 0x05000514, &sense);
                            if (sense & 0x10000000) {
                                sense = 4;
                                goto error;
                            }
                        }
                        if (i == 0) {
                            c2 = D_800F2180_F2D80;
                        } else {
                            c2 = D_800F2520_F3120;
                        }
                        info.c2end = c2 + info.secBytes * 4;
                        osInvalDCache(c2, info.secBytes * 4);
                        blk = &D_800F28E0_F34E0->transferInfo.block[i];
                        info.errNum = blk->C1ErrNum;
                        info.errSector[0] = blk->C1ErrSector[0];
                        info.errSector[1] = blk->C1ErrSector[1];
                        info.errSector[2] = blk->C1ErrSector[2];
                        info.errSector[3] = blk->C1ErrSector[3];
                        osRecvMesg(&D_800F1408_F2008, NULL, OS_MESG_BLOCK);
                        D_800F206E_F2C6E |= 0x4000;
                        D_800F28D0_F34D0 = info;
                        osSendMesg(&D_800F2000_F2C00, (OSMesg)0x80000, OS_MESG_BLOCK);
                    }
                } else if (D_800F2070_F2C70.rdwr_blocks == 1) {
                    c2w = (u32*)(D_800F2180_F2D80 + i * 0x3A0);
                    if ((c2w[3] | c2w[0] | c2w[1] | c2w[2]) != 0) {
                        sense = 0x17;
                        goto error;
                    }
                }
                i++;
                info.dram += info.blkBytes;
                D_800F2070_F2C70.start_block ^= 1;
                D_800F2070_F2C70.rdwr_blocks--;
                if (D_800F2070_F2C70.rdwr_blocks == 0) {
                    return 0;
                }
            }
        }

    error:
        if (sense == 0x16) {
            sense = func_80097A3C_9863C();
        }
        while (TRUE) {
            if (func_80098280_98E80(sense) != 0 || (D_800F206E_F2C6E & 0x1000)) {
                return sense;
            }
            if (retry == 0x40) {
                return sense;
            }
            retry++;
            if ((retry & 7) == 0) {
                sense = func_80097FF0_98BF0(0x30001, 0);
                if (sense != 0) {
                    continue;
                }
            }
            if (sense == 0x18 || (sense == 0x17 && retry == 0x20)) {
                sense = func_80098114_98D14();
                if (sense != 0) {
                    continue;
                }
            }
            if (D_800F206E_F2C6E & 0x8000) {
                sense = func_8009818C_98D8C(1);
            } else {
                sense = func_8009818C_98D8C(0);
            }
            if (sense == 0) {
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_800972F0_97EF0);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_800978EC_984EC(void) {
    u32 stat;
    u8 sense;

    sense = func_80097FA0_98BA0(0x10001);
    if (sense == 0) {
        osEPiReadIo(D_800F28E0_F34E0, 0x0500050C, &stat);
        if ((stat & 0x60000000) != 0x60000000) {
            sense = 0x18;
        }
    }
    return sense;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_800978EC_984EC);
#endif

// IDO-compiled libleo (buffer manager control register)
#ifdef NON_MATCHING
void func_80097954_98554(void) {
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000510, D_800F2064_F2C64 | 0x10000000);
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000510, D_800F2064_F2C64);
    if (D_800F2070_F2C70.start_block != 0) {
        D_800F2064_F2C64 = 0x5A0000;
    } else {
        D_800F2064_F2C64 = 0;
    }
    if (!(D_800F206E_F2C6E & 0x8000)) {
        D_800F2064_F2C64 |= 0x40000000;
    }
    if (D_800F2070_F2C70.rdwr_blocks == 2) {
        D_800F2064_F2C64 |= 0x02000000;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000510, D_800F2064_F2C64);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097954_98554);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_80097A3C_9863C(void) {
    u32 stat;
    u32 bmStat;

    osEPiReadIo(D_800F28E0_F34E0, 0x05000514, &bmStat);
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000510, D_800F2064_F2C64 | 0x10000000);
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000510, D_800F2064_F2C64);
    if (bmStat & 0x04000000) {
        return 0x31;
    }
    if (bmStat & 0x10000000) {
        return 4;
    }
    if (bmStat & 0x42000000) {
        if (D_800F206E_F2C6E & 0x8000) {
            return 0x16;
        }
        return 0x17;
    }
    if (!(bmStat & 0x80000000)) {
        osEPiReadIo(D_800F28E0_F34E0, 0x0500050C, &stat);
        if ((stat & 0x60000000) == 0x60000000) {
            return 0x19;
        }
    }
    return 0x18;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097A3C_9863C);
#endif

// IDO-compiled libleo (leoAnalize_asic_status)
#ifdef NON_MATCHING
u8 func_80097B50_98750(void) {
    u32 stat;

    osEPiReadIo(D_800F28E0_F34E0, 0x05000508, &D_800F1420_F2020);
    stat = D_800F1420_F2020 ^ 0x01000000;
    if (stat & 0x01C3FFFF) {
        if (stat & 0x01C1FFFF) {
            D_800F206C_F2C6C = 0;
        }
        if (stat & 0xFFFF) {
            return 0x29;
        }
        if ((stat & 0xC00000) == 0x800000) {
            return 3;
        }
        if (stat & 0x400000) {
            D_800F1424_F2024 |= 2;
            return 0x2B;
        }
        if (stat & 0x01000000) {
            return 0x31;
        }
        if (stat & 0x10000) {
            D_800F1424_F2024 |= 1;
            return 0x2F;
        }
        if (stat & 0x20000) {
            return 0x15;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097B50_98750);
#endif

// IDO-compiled libleo (leoChk_asic_ready)
#ifdef NON_MATCHING
u8 func_80097C5C_9885C(u32 asic_cmd) {
    u32 sense;

    sense = func_80097B50_98750();
    switch (sense) {
        case 0x15:
            return 0;
        case 0x2F:
            if (asic_cmd == 0x80000) {
                return 0;
            }
            // fallthrough
        case 0x2B:
            if (D_800F1420_F2020 & 0x800000) {
                return sense;
            }
            if (asic_cmd == 0x90000) {
                return 0;
            }
            if (func_8009822C_98E2C(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800F28E0_F34E0, 0x05000508, 0x90000);
            if (func_8009822C_98E2C(1) != 0) {
                return 0x25;
            }
            return sense;
        case 0x31:
            if (asic_cmd & 1) {
                return sense;
            }
            return 0;
        default:
            return sense;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097C5C_9885C);
#endif

// IDO-compiled libleo (leoChk_done_status)
#ifdef NON_MATCHING
u8 func_80097D44_98944(u32 asic_cmd) {
    u32 sense;
    u32 data;
    u8 sense2;

    sense = func_80097B50_98750();
    switch (sense) {
        case 0x2B:
        case 0x2F:
            if (D_800F1420_F2020 & 0x800000) {
                return sense;
            }
            if (func_8009822C_98E2C(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800F28E0_F34E0, 0x05000508, 0x90000);
            if (func_8009822C_98E2C(1) != 0) {
                return 0x25;
            }
            return sense;
        case 0x31:
            if (!(asic_cmd & 1)) {
                return 0;
            }
            return sense;
        case 0x15:
            osEPiWriteIo(D_800F28E0_F34E0, 0x05000500, 0);
            if (func_8009822C_98E2C(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800F28E0_F34E0, 0x05000508, 0xC0000);
            if (func_8009822C_98E2C(1) != 0) {
                return 0x25;
            }
            osEPiReadIo(D_800F28E0_F34E0, 0x05000500, &data);
            sense2 = func_80097C5C_9885C(0xC0000);
            if (sense2 != 0) {
                return sense2;
            }
            if (data & 0x10000) {
                return 2;
            }
            if (data & 0x20000) {
                return 0x18;
            }
            if (data & 0x40000) {
                return 1;
            }
            if (data & 0x80000) {
                return 0x15;
            }
            if (data & 0x200000) {
                return 0xB;
            }
            return 0x29;
        default:
            return sense;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097D44_98944);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_i)
#ifdef NON_MATCHING
u8 func_80097EF8_98AF8(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80097C5C_9885C(asic_cmd);
    if (sense != 0) {
        D_800F2060_F2C60->header.sense_code = sense;
        return D_800F2060_F2C60->header.sense_code;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000500, asic_data);
    if (func_8009822C_98E2C(0) != 0) {
        D_800F2060_F2C60->header.sense_code = 0x25;
        return D_800F2060_F2C60->header.sense_code;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000508, asic_cmd);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097EF8_98AF8);
#endif

// IDO-compiled libleo (leoWait_mecha_cmd_done)
#ifdef NON_MATCHING
u8 func_80097FA0_98BA0(u32 asic_cmd) {
    u8 sense;

    if (func_8009822C_98E2C(1) != 0) {
        return 0x25;
    }
    sense = func_80097D44_98944(asic_cmd);
    if (sense != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097FA0_98BA0);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_w)
#ifdef NON_MATCHING
u8 func_80097FF0_98BF0(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80097EF8_98AF8(asic_cmd, asic_data);
    if (sense != 0) {
        return sense;
    }
    return func_80097FA0_98BA0(asic_cmd);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80097FF0_98BF0);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_w_nochkDiskChange)
#ifdef NON_MATCHING
u8 func_80098028_98C28(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80097C5C_9885C(asic_cmd);
    if (sense != 0x2F && sense != 0) {
        D_800F2060_F2C60->header.sense_code = sense;
        return D_800F2060_F2C60->header.sense_code;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000500, asic_data);
    if (func_8009822C_98E2C(0) != 0) {
        D_800F2060_F2C60->header.sense_code = 0x25;
        return D_800F2060_F2C60->header.sense_code;
    }
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000508, asic_cmd);
    if (func_8009822C_98E2C(1) != 0) {
        return 0x25;
    }
    sense = func_80097D44_98944(asic_cmd);
    if (sense != 0x2F && sense != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098028_98C28);
#endif

// IDO-compiled libleo (leoDetect_index_w)
#ifdef NON_MATCHING
u8 func_80098114_98D14(void) {
    return func_80097FF0_98BF0(0xE0001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098114_98D14);
#endif

// IDO-compiled libleo (leoRecal_i)
#ifdef NON_MATCHING
u8 func_8009813C_98D3C(void) {
    return func_80097EF8_98AF8(0x30001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_8009813C_98D3C);
#endif

// IDO-compiled libleo (leoRecal_w)
#ifdef NON_MATCHING
u8 func_80098164_98D64(void) {
    return func_80097FF0_98BF0(0x30001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098164_98D64);
#endif

// IDO-compiled libleo (leoSeek_i)
#ifdef NON_MATCHING
u8 func_8009818C_98D8C(u16 rwmode) {
    u32 tgt_tk = ((D_800F2070_F2C70.head << 12) + D_800F2070_F2C70.cylinder) << 16;

    if (rwmode == 0) {
        return func_80097EF8_98AF8(0x10001, tgt_tk);
    } else {
        return func_80097EF8_98AF8(0x20001, tgt_tk);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_8009818C_98D8C);
#endif

// IDO-compiled libleo (leoSeek_w)
#ifdef NON_MATCHING
u8 func_800981F0_98DF0(void) {
    u8 sense;

    sense = func_8009818C_98D8C(0);
    if (sense != 0) {
        return sense;
    }
    return func_80097FA0_98BA0(0x10001);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_800981F0_98DF0);
#endif

// IDO-compiled libleo (leoRecv_event_mesg)
#ifdef NON_MATCHING
s32 func_8009822C_98E2C(s32 control) {
    OSMesg msg;

    if (osRecvMesg(&D_800F1FE8_F2BE8, &msg, control) == 0 && msg == (OSMesg)0xA0000) {
        func_800983D0_98FD0();
        return 0xFF;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_8009822C_98E2C);
#endif

// IDO-compiled libleo (leoChk_err_retry)
#ifdef NON_MATCHING
s32 func_80098280_98E80(u32 sense) {
    if (D_800F2900_F3500 == 0xC || D_800F2900_F3500 == 8) {
        switch (sense) {
            case 0x2B:
                D_800F1424_F2024 |= 2;
                // fallthrough
            case 2:
            case 3:
            case 0x25:
            case 0x29:
            case 0x2A:
            case 0x31:
                D_800F206C_F2C6C = 0;
                return -1;
        }
    } else {
        switch (sense) {
            case 0x2B:
                D_800F1424_F2024 |= 2;
                // fallthrough
            case 0x2F:
                D_800F1424_F2024 |= 1;
                // fallthrough
            case 2:
            case 3:
            case 0x25:
            case 0x29:
            case 0x2A:
            case 0x31:
                D_800F206C_F2C6C = 0;
                return -1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098280_98E80);
#endif

// IDO-compiled libleo (leoChk_cur_drvmode)
#ifdef NON_MATCHING
u8 func_80098390_98F90(void) {
    u8 mode = 0;

    if (!(D_800F1420_F2020 & 0x01000000)) {
        mode = 1;
    }
    if (D_800F1420_F2020 & 0x80000) {
        mode |= 2;
    }
    if (D_800F1420_F2020 & 0x100000) {
        mode |= 4;
    }
    return mode;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098390_98F90);
#endif

// IDO-compiled libleo (leoDrive_reset)
#ifdef NON_MATCHING
void func_800983D0_98FD0(void) {
    osEPiWriteIo(D_800F28E0_F34E0, 0x05000520, 0xAAAA0000);
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_800983D0_98FD0);
#endif

// leoChk_mecha_int: the only function here GCC emits identically
u32 func_80098400_99000(void) {
    return D_800F1424_F2024;
}

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_8009840C_9900C(void) {
    if (D_800F1424_F2024 & 2) {
        return 0x2B;
    }
    if (D_800F1424_F2024 & 1) {
        return 0x2F;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_8009840C_9900C);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_80098440_99040(void) {
    D_800F1424_F2024 &= ~2;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098440_99040);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_8009845C_9905C(void) {
    D_800F1424_F2024 &= ~1;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_8009845C_9905C);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_80098478_99078(void) {
    D_800F1424_F2024 |= 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098478_99078);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_80098490_99090(void) {
    D_800F1424_F2024 = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098490_99090);
#endif

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
INCLUDE_ASM("asm/nonmatchings/97D60", func_800984A0_990A0);
#endif

// IDO-compiled libleo (flush the command queue: every pending command is terminated)
#ifdef NON_MATCHING
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
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_80098650_99250);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_800986F8_992F8(void) {
    u8 sense;

    sense = func_80097B50_98750();
    switch (sense) {
        case 3:
        case 0x29:
        case 0x2B:
            D_800F2060_F2C60->header.sense_code = sense;
            D_800F2060_F2C60->header.status = 2;
            break;
        default:
            D_800F2060_F2C60->header.sense_code = 0;
            D_800F2060_F2C60->header.status = 0;
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/97D60", func_800986F8_992F8);
#endif
