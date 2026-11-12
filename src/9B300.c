#include "common.h"
#include "sdk_leo.h"

// libleo command thread (MP1 83960.c, the leocmdex.c family). IDO-compiled: every function is
// NON_MATCHING C with the asm in the matching build (see sdk_leo.h), so the unit is still built with
// KMC GCC. Its rodata (D4D20-D4DD0) is defined here so it is one carved piece; it comes before every
// INCLUDE_ASM because GCC does not see an INCLUDE_ASM switch to .text, and the jump tables are the
// asm functions' and unused by the C.

typedef struct LEOCmdTestUnitReady {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 test;
} LEOCmdTestUnitReady;

/* .data (0xCE930-0xCE98C) */
void func_80098650_99250(void);
void func_800986F8_992F8(void);
void func_8009AD90_9B990(void);
void func_8009AE40_9BA40(void);
void func_8009AEF0_9BAF0(void);
void func_8009AFE0_9BBE0(void);
void func_8009B080_9BC80(void);
void func_8009B210_9BE10(void);
void func_8009B3D0_9BFD0(void);
void func_8009B470_9C070(void);
void func_8009B530_9C130(void);
void func_8009B570_9C170(void);
void func_8009B810_9C410(void);
void func_8009B940_9C540(void);
void func_8009B9FC_9C5FC(void);
void (*D_800CDD30_CE930[16])(void) = { /* command handlers, by command code */
    NULL,
    func_80098650_99250,
    func_8009AD90_9B990,
    func_8009B530_9C130,
    func_8009B3D0_9BFD0,
    func_8009B210_9BE10,
    func_8009B810_9C410,
    func_8009B470_9C070,
    func_8009AEF0_9BAF0,
    func_8009AFE0_9BBE0,
    func_8009B570_9C170,
    func_8009AE40_9BA40,
    func_8009B080_9BC80,
    func_8009B940_9C540,
    func_8009B9FC_9C5FC,
    func_800986F8_992F8,
};
LEOCmdRead D_800CDD70_CE970 = { { 5, 0, 0, 0, 0, 0, 0, 0, NULL }, 12, 1, NULL, 0 }; /* system-area read command template */

void func_8009A700_9B300(void* arg);

// system-area lbas tried in turn
const u8 D_800D4120_D4D20[4] __attribute__((aligned(8), section(".rodata"))) = {
    0x00, 0x01, 0x08, 0x09,
};

#ifndef NON_MATCHING
// func_8009A700_9B300's jump tables
const u32 jtbl_800D4128_D4D28[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009A980, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4,
    0x8009A980, 0x8009A9C4, 0x8009A9C4, 0x8009A980, 0x8009A980, 0x8009A980,
    0x8009A980, 0x8009A980,
};
const u32 jtbl_800D4160_D4D60[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009A980, 0x8009A940, 0x8009A940, 0x8009A940, 0x8009A940, 0x8009A940,
    0x8009A940, 0x8009A940, 0x8009A940, 0x8009A980, 0x8009A940, 0x8009A980,
    0x8009A980, 0x8009A980,
};
const u32 jtbl_800D4198_D4D98[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009AADC, 0x8009AADC, 0x8009A9F4, 0x8009A9F4, 0x8009A9F4, 0x8009A9F4,
    0x8009AADC, 0x8009A9F4, 0x8009A9F4, 0x8009AADC, 0x8009A9F4, 0x8009AADC,
    0x8009AADC, 0x8009AADC,
};
#endif

#ifdef NON_MATCHING
// leomain: the 64DD command thread
void func_8009A700_9B300(void* arg) {
    u32 stat;
    u32 sense;
    u8 command;

    ((u8*)&D_800F2080_F2C80)[0] = *(vu8*)0xA0000010;
    ((u8*)&D_800F2080_F2C80)[1] = *(vu8*)0xA0000090;
    ((u8*)&D_800F2080_F2C80)[2] = *(vu8*)0xA0000110;
    ((u8*)&D_800F2080_F2C80)[3] = *(vu8*)0xA0000190;
    D_800F2068_F2C68 = 0;
    D_800F2064_F2C64 = 0;
    D_800F206C_F2C6C = 0;
    D_800F206D_F2C6D = 0;
    func_80098490_99090();
    D_800F28E0_F34E0 = osLeoDiskInit();
    D_800F28E8_F34E8.hdr.pri = OS_MESG_PRI_HIGH;
    D_800F28E8_F34E8.hdr.retQueue = &D_800F2018_F2C18;
    osEPiReadIo(D_800F28E0_F34E0, 0x05000508, &stat); // LEO_STATUS
    if (!(stat & 0x400000) && (stat & 0x6800000)) {
        func_800983D0_98FD0();
    }

    while (TRUE) {
        osRecvMesg(&D_800F1FD0_F2BD0, (OSMesg*)&D_800F2060_F2C60, OS_MESG_BLOCK);
        D_800F2900_F3500 = LEO_CUR(LEOCmdHeader)->command;
        if (LEO_CUR(LEOCmdHeader)->command == 0) { // clear queue
            func_800983D0_98FD0();
            osRecvMesg(&D_800F1FE8_F2BE8, NULL, OS_MESG_NOBLOCK);
            continue;
        }

        sense = func_80097C5C_9885C(0x10001);
        stat = func_80098400_99000();
        if (stat == 0) {
            if (sense == 0) {
                goto dispatch;
            }
        } else if ((sense != 3) && (sense != 0x25) && (sense != 0x29) && (sense != 0x2B)) {
            if (sense == 0x31) {
                if (func_8009840C_9900C() == 0x2B) {
                    sense = 0x2B;
                }
            } else {
                sense = func_8009840C_9900C();
            }
        }

        command = LEO_CUR(LEOCmdHeader)->command;
        if (sense == 0x2B) { // medium may have changed
            if ((command == 2) || (command == 0xD) || (command == 0xE)) {
                goto dispatch;
            }
            if (command == 0xF) {
                func_80098440_99040();
                goto dispatch;
            }
        } else if (sense == 0x2F) {
            switch (command) {
                case 2:
                case 8:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
            }
        } else if (sense == 0x31) {
            switch (command) {
                case 2:
                case 11:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
                default:
                    sense = 0x2A;
                    break;
            }
        }
        if (command == 3) { // test unit ready
            LEO_CUR(LEOCmdTestUnitReady)->test = func_80098390_98F90();
        }
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        goto done;

    dispatch:
        if (D_800F206C_F2C6C == 0) {
            switch (LEO_CUR(LEOCmdHeader)->command) {
                case 2:
                case 3:
                case 8:
                case 11:
                case 13:
                case 14:
                case 15:
                    break;
                default:
                    // commands that need the system area: read it first
                    if (D_800F2080_F2C80 == 0) {
                        osEPiReadIo(D_800F28E0_F34E0, 0x05000540, &stat); // ASIC_ID_REG
                        if ((stat & 0x70000) != 0x40000) {
                            while (TRUE) {
                            }
                        }
                    }
                    if (func_8009AB7C_9B77C() != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    sense = func_80097FF0_98BF0(0xB0001, D_800F2090_F2C90[5] << 16);
                    LEO_CUR(LEOCmdHeader)->sense_code = sense;
                    if (sense != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    if ((D_800F2090_F2C90[5] & 0xF0) != 0x10) {
                        goto bad_disk;
                    }
                    D_800F207C_F2C7C = D_800F2090_F2C90[5] & 0xF;
                    if (D_800F207C_F2C7C >= 7) {
                    bad_disk:
                        LEO_CUR(LEOCmdHeader)->sense_code = 0xB;
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    D_800F206C_F2C6C = 0xFF;
                    break;
            }
        }
        D_800CDD30_CE930[LEO_CUR(LEOCmdHeader)->command]();

    done:
        if (LEO_CUR(LEOCmdHeader)->control & 0x80) {
            osSendMesg(LEO_CUR(LEOCmdHeader)->post, (OSMesg)(u32)LEO_CUR(LEOCmdHeader)->sense_code,
                       OS_MESG_BLOCK);
        }
        if (D_800F206D_F2C6D != 0) {
            func_80098650_99250();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9B300", func_8009A700_9B300);
#endif

#ifdef NON_MATCHING
// leoRead_system_area: read the disk's system area into D_800F2090_F2C90, retrying
u8 func_8009AB7C_9B77C(void) {
    LEOCmdRead* saved = D_800F2060_F2C60;
    LEOCmdRead tmp;
    u32 retry = 0;
    s32 phase = 0;
    u8 sense;

    D_800F2060_F2C60 = &tmp;
    while (TRUE) {
        tmp = D_800CDD70_CE970;
        D_800F207C_F2C7C = 0;
        D_800F2090_F2C90[8] = 0;
        D_800F206E_F2C6E = 0x3000;
        if (phase == 0) {
            func_8009B23C_9BE3C(0);
            if (tmp.header.sense_code == 0) {
                retry = 0;
                // as retail: spins forever while the drive ROM id word is non-zero
                while (D_800F2080_F2C80 != 0) {
                }
                phase--;
                continue;
            }
            if (tmp.header.sense_code == 0x17) {
                retry = 0;
                while (D_800F2080_F2C80 == 0) {
                }
                phase--;
                continue;
            }
        } else {
            tmp.lba = D_800D4120_D4D20[retry & 3];
            if (D_800F2080_F2C80 == 0) {
                tmp.lba += 2;
            }
            func_8009B23C_9BE3C(0);
            if (tmp.header.status == LEO_STATUS_GOOD) {
                while (D_800F2080_F2C80 != *(u32*)D_800F2090_F2C90) {
                }
                break;
            }
        }
        while (TRUE) {
            if (func_80098280_98E80(tmp.header.sense_code) != 0) {
                goto end;
            }
            if (retry >= 0x40) {
                goto end;
            }
            retry++;
            if ((retry & 7) != 0) {
                break;
            }
            sense = func_80097FF0_98BF0(0x30001, 0);
            tmp.header.sense_code = sense;
            if (sense == 0) {
                break;
            }
        }
    }
end:
    D_800F2060_F2C60 = saved;
    saved->header.sense_code = tmp.header.sense_code;
    return tmp.header.sense_code;
}
#else
INCLUDE_ASM("asm/nonmatchings/9B300", func_8009AB7C_9B77C);
#endif
