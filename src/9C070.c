#include "common.h"
#include "sdk_leo.h"

extern u16 D_800D3B34_D4734[];     // block bytes per zone
extern u16 D_800D3B48_D4748[][16]; // end lba of each vzone, per disk type
extern u8 D_800D3C48_D4848[][16];  // physical zone of each vzone, per disk type
typedef struct LEOCmdTestUnitReady {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 test;
} LEOCmdTestUnitReady;

typedef struct LEOCmdLBAConv {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 in;  // bytes (control & 1) or lbas
    /* 0x14 */ u32 out; // lbas (control & 1) or bytes
} LEOCmdLBAConv;


// leoSeek
void func_8009B470_9C070(void) {
    u8 retry = 20;
    u8 sense;

    if (LEO_CUR(LEOCmdRead)->lba >= 0x10C4) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20; // LBA out of range
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    func_80098770_99370(LEO_CUR(LEOCmdRead)->lba + 0x18);
    do {
        if ((sense = func_800981F0_98DF0()) == 0) {
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80098280_98E80(sense) != 0) {
            break;
        }
    } while (retry--);
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}

// leoTest_unit_rdy
void func_8009B530_9C130(void) {
    LEO_CUR(LEOCmdTestUnitReady)->test = func_80098390_98F90();
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}

#ifdef NON_MATCHING
// leoByte_to_lba / leoLba_to_byte as a command (control & 1: bytes to lbas)
void func_8009B570_9C170(void) {
    LEOCmdLBAConv* cmd = (LEOCmdLBAConv*)D_800F2060_F2C60;
    u32 lba = cmd->lba;
    u32 count = 0;
    u32 bytes = 0;
    u32 n;
    u32 byte_p_blk;
    u16 vzone = 1;
    u16 zone;
    s32 flag = 1;

    if (lba >= 0x10C4) {
        cmd->header.sense_code = 0x20;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    lba += 0x18;
    if (cmd->header.control & 1) {
        bytes = cmd->in;
        while (bytes != 0) {
            if (flag || (D_800D3B48_D4748[D_800F207C_F2C7C][vzone] == lba)) {
                vzone = func_80098964_99564(lba);
                zone = D_800D3C48_D4848[D_800F207C_F2C7C][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800D3B34_D4734[zone];
            }
            if (bytes < byte_p_blk) {
                bytes = 0;
            } else {
                bytes -= byte_p_blk;
            }
            count++;
            lba++;
            if ((bytes != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = count;
    } else {
        n = cmd->in;
        while (n != 0) {
            if (flag || (D_800D3B48_D4748[D_800F207C_F2C7C][vzone] == lba)) {
                vzone = func_80098964_99564(lba);
                zone = D_800D3C48_D4848[D_800F207C_F2C7C][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800D3B34_D4734[zone];
            }
            n--;
            bytes += byte_p_blk;
            lba++;
            if ((n != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = bytes;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/9C070", func_8009B570_9C170);
#endif
