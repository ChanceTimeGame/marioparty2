#include "common.h"
#include "sdk_leo.h"

typedef struct LEOCmdInquiry {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 dev_type;
    /* 0x0D */ u8 version;
    /* 0x0E */ u8 dev_num;
    /* 0x0F */ u8 leo_bios_ver;
    /* 0x10 */ u32 reserve5[2];
} LEOCmdInquiry; // sizeof 0x18

typedef struct LEOCmdModeSelect {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 page;
    /* 0x0D */ u8 reserve1;
    /* 0x0E */ u8 standby_time;
    /* 0x0F */ u8 sleep_time;
    /* 0x10 */ u32 led_on_time;
} LEOCmdModeSelect;


// leoInquiry
void func_8009AD90_9B990(void) {
    u32 asic_id;
    u32 asic_data;

    osEPiReadIo(D_800F28E0_F34E0, 0x05000540, &asic_id); // ASIC_ID_REG
    if (func_80097FF0_98BF0(0x1B0000, 0) == 0) {
        osEPiReadIo(D_800F28E0_F34E0, 0x05000500, &asic_data); // ASIC_DATA
        if (asic_data & 0x10000) {
            asic_id |= 0x100000;
        }
    }
    LEO_CUR(LEOCmdInquiry)->dev_type = 0;
    LEO_CUR(LEOCmdInquiry)->version = asic_id >> 16;
    LEO_CUR(LEOCmdInquiry)->dev_num = 1;
    LEO_CUR(LEOCmdInquiry)->leo_bios_ver = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}

// leoMode_sel
void func_8009AE40_9BA40(void) {
    u8 sense;

    if (((sense = func_80098028_98C28(0x60000, LEO_CUR(LEOCmdModeSelect)->standby_time << 16)) != 0) ||
        ((sense = func_80098028_98C28(0x70000, LEO_CUR(LEOCmdModeSelect)->sleep_time << 16)) != 0) ||
        ((sense = func_80098028_98C28(0x150000, LEO_CUR(LEOCmdModeSelect)->led_on_time)) != 0)) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
