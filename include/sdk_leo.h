#ifndef SDK_LEO_H
#define SDK_LEO_H

#include "common.h"

// libleo (64DD driver) internals shared by the libleo units (97D60.c, 9A210.c, ...). Every libleo
// unit was built with IDO, not KMC GCC, so its C is NON_MATCHING (logic-equivalent) and the
// matching build keeps the asm; layouts and names follow MP1's include/sdk_leo.h.

typedef struct LEOCmdHeader {
    /* 0x00 */ u8 command;
    /* 0x01 */ u8 reserve1;
    /* 0x02 */ u8 control;
    /* 0x03 */ u8 reserve3;
    /* 0x04 */ u8 status;
    /* 0x05 */ u8 sense_code;
    /* 0x06 */ u8 reserve6;
    /* 0x07 */ u8 reserve7;
    /* 0x08 */ OSMesgQueue* post;
} LEOCmdHeader; // sizeof 0xC

typedef struct LEOCmdRead {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 xfer_blks;
    /* 0x14 */ u8* buff_ptr;
    /* 0x18 */ u32 rw_bytes;
} LEOCmdRead; // sizeof 0x1C

// Current transfer target (LEOtgt_param)
typedef struct LEOTgtParam {
    /* 0x00 */ u16 lba;
    /* 0x02 */ u16 cylinder;
    /* 0x04 */ u16 blk_bytes;
    /* 0x06 */ u8 sec_bytes;
    /* 0x07 */ u8 head;
    /* 0x08 */ u8 zone;
    /* 0x09 */ u8 rdwr_blocks;
    /* 0x0A */ u8 start_block; // toggled per block transferred
} LEOTgtParam;

// C1 error report of the last read, handed to the C2 correction (9A210.c)
typedef struct LEORwInfo {
    /* 0x00 */ u8* dram;
    /* 0x04 */ u8* c2end;
    /* 0x08 */ u8 errSector[4];
    /* 0x0C */ u8 errNum;
    /* 0x0D */ u8 secBytes;
    /* 0x0E */ u16 blkBytes;
} LEORwInfo; // sizeof 0x10

#define LEO_CUR(type) ((type*)D_800F2060_F2C60)
#define LEO_STATUS_GOOD 0
#define LEO_STATUS_CHECK_CONDITION 2

extern OSMesg D_800F1400_F2000;
extern OSMesgQueue D_800F1408_F2008;    // C2 correction interlock
extern u32 D_800F1420_F2020;            // last ASIC status
extern u32 D_800F1424_F2024;            // mechanism interrupt flags (1, 2)
extern u32 D_800F1430_F2030[16];        // microsequence being loaded
extern OSThread D_800F1620_F2220;       // read/write thread
extern OSMesgQueue D_800F1FD0_F2BD0;    // command queue
extern OSMesgQueue D_800F1FE8_F2BE8;    // event queue
extern OSMesgQueue D_800F2000_F2C00;    // read/write thread replies
extern OSMesgQueue D_800F2018_F2C18;    // DMA completion
extern u8* D_800F205C_F2C5C;            // transfer DRAM cursor
extern LEOCmdRead* D_800F2060_F2C60;    // LEOcur_command
extern u32 D_800F2064_F2C64;            // buffer manager control shadow
extern u32 D_800F2068_F2C68;            // sequencer control shadow
extern u8 D_800F206C_F2C6C;             // non-zero once the system area has been read
extern u8 D_800F206D_F2C6D;
extern u16 D_800F206E_F2C6E;            // transfer mode flags
extern LEOTgtParam D_800F2070_F2C70;    // LEOtgt_param
extern u8 D_800F207C_F2C7C;             // disk type
extern u32 D_800F2080_F2C80;            // drive ROM id bytes (compared with the system area's)
extern u8 D_800F2090_F2C90[];           // system area
extern u8 D_800F2180_F2D80[0x3A0];      // C2 buffer, block 0
extern u8 D_800F2520_F3120[0x3A0];      // C2 buffer, block 1
extern LEORwInfo D_800F28D0_F34D0;
extern OSPiHandle* D_800F28E0_F34E0;    // LEOPiInfo
extern OSIoMesg D_800F28E8_F34E8;
extern s32 D_800F2900_F3500;            // current command code
extern u8 D_800F29F8_F35F8[];           // scratch sector (end) for an out-of-range erasure

// 97D60.c
u32 func_800972F0_97EF0(void);
u8 func_800978EC_984EC(void);
void func_80097954_98554(void);
u8 func_80097A3C_9863C(void);
u8 func_80097B50_98750(void);
u8 func_80097C5C_9885C(u32 asic_cmd);
u8 func_80097D44_98944(u32 asic_cmd);
u8 func_80097EF8_98AF8(u32 asic_cmd, u32 asic_data);
u8 func_80097FA0_98BA0(u32 asic_cmd);
u8 func_80097FF0_98BF0(u32 asic_cmd, u32 asic_data);
u8 func_80098028_98C28(u32 asic_cmd, u32 asic_data);
u8 func_80098114_98D14(void);
u8 func_8009813C_98D3C(void);
u8 func_80098164_98D64(void);
u8 func_8009818C_98D8C(u16 rwmode);
u8 func_800981F0_98DF0(void);
s32 func_8009822C_98E2C(s32 control);
s32 func_80098280_98E80(u32 sense);
u8 func_80098390_98F90(void);
void func_800983D0_98FD0(void);
u32 func_80098400_99000(void);
u8 func_8009840C_9900C(void);
void func_80098440_99040(void);
void func_8009845C_9905C(void);
void func_80098478_99078(void);
void func_80098490_99090(void);
void func_800984A0_990A0(u16 rwmode);
void func_80098650_99250(void);
void func_800986F8_992F8(void);

// 99370.c
u16 func_80098770_99370(u32 lba); // leoLba_to_phys

// 9A210.c
u16 func_80099610_9A210(void);
u8 func_8009A674_9B274(u8 a, u8 b);
u8 func_8009A6B8_9B2B8(u8 a, u8 b);
u8 func_8009AB7C_9B77C(void);

// 9BE10.c
void func_8009B23C_9BE3C(u32 start); // leoRead_common

#endif
