#include "common.h"
#include "sdk_leo.h"

typedef struct LEOCmdReadCapacity {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 startLBA;
    /* 0x10 */ u32 endLBA;
    /* 0x14 */ u32 nbytes;
} LEOCmdReadCapacity;

extern u16 D_800D3CC8_D48C8[];        // first user lba per disk type
extern u32 D_800D3CD8_D48D8[];        // capacity in bytes per disk type

// leoReadCapacity
void func_8009AFE0_9BBE0(void) {
    LEOCmdReadCapacity* cmd = (LEOCmdReadCapacity*)D_800F2060_F2C60;

    if (cmd->header.control & 1) {
        cmd->startLBA = D_800D3CC8_D48C8[D_800F207C_F2C7C] - 0x18;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = D_800D3CD8_D48D8[D_800F207C_F2C7C];
    } else {
        cmd->startLBA = 0;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = 0x3D78F40;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
