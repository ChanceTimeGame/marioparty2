#include "common.h"
#include "sdk_leo.h"

// libleo leoLba_to_phys and leoLba_to_vzone (MP1 src/821F0.c), built with IDO 5.3. The tables are
// this unit's rodata (D4728 on), left in the data blob.

extern u8 D_800D3B28_D4728[];      // sector bytes per zone
extern u16 D_800D3B34_D4734[];     // block bytes per zone
extern u16 D_800D3B46_D4746[];     // D_800D3B48_D4748 one element back (start lba of the previous vzone)
extern u16 D_800D3B48_D4748[][16]; // end lba of each vzone, per disk type
extern u16 D_800D3C28_D4828[];     // start cylinder of each physical zone
extern u8 D_800D3C48_D4848[][16];  // physical zone of each vzone, per disk type
extern u16 D_800D3CB6_D48B6[];     // outer cylinder of each zone for head 1 (indexed from 1)

u16 func_80098964_99564(u32 lba);

// Register allocation and the cylinder stores (direct, not through the LEOtgt_param base) differ.
// Layout-dependent: D_800D3B46_D4746 and D_800D3CB6_D48B6 are labels one u16 before a table.
#ifdef NON_MATCHING
u16 func_80098770_99370(u32 lba) {
    u16 vzone;
    u16 zone_slba;
    u16 zone_scyl;
    u16 bad_tk_num;
    u16 def_offset;
    u8 def_zone_no;

    D_800F2070_F2C70.rdwr_blocks = 2 - (lba & 1);
    switch (lba & 3) {
        case 0:
        case 3:
            D_800F2070_F2C70.start_block = 0;
            break;
        default:
            D_800F2070_F2C70.start_block = 1;
            break;
    }
    vzone = func_80098964_99564(lba);
    D_800F2070_F2C70.zone = def_zone_no = D_800D3C48_D4848[D_800F207C_F2C7C][vzone];
    D_800F2070_F2C70.head = 0;
    if (D_800F2070_F2C70.zone > 7) {
        D_800F2070_F2C70.zone -= 7;
        D_800F2070_F2C70.head = 1;
    }
    zone_scyl = D_800D3C28_D4828[def_zone_no];
    if (vzone != 0) {
        zone_slba = D_800D3B46_D4746[D_800F207C_F2C7C * 16 + vzone];
    } else {
        zone_slba = 0;
    }
    if (D_800F2070_F2C70.head != 0) {
        D_800F2070_F2C70.cylinder = zone_scyl - ((lba - zone_slba) >> 1);
        zone_scyl = D_800D3CB6_D48B6[D_800F2070_F2C70.zone];
    } else {
        D_800F2070_F2C70.cylinder = zone_scyl + ((lba - zone_slba) >> 1);
    }
    if (def_zone_no != 0) {
        def_offset = D_800F2090_F2C90[7 + def_zone_no];
    } else {
        def_offset = 0;
    }
    bad_tk_num = D_800F2090_F2C90[8 + def_zone_no] - def_offset;
    while (bad_tk_num != 0) {
        if (D_800F2070_F2C70.cylinder < (u16)(zone_scyl + D_800F2090_F2C90[0x20 + def_offset])) {
            break;
        }
        D_800F2070_F2C70.cylinder++;
        def_offset++;
        bad_tk_num--;
    }
    D_800F2070_F2C70.sec_bytes = D_800D3B28_D4728[D_800F2070_F2C70.zone];
    D_800F2070_F2C70.blk_bytes = D_800D3B34_D4734[D_800F2070_F2C70.zone];
    if (D_800F2080_F2C80 == 0 && lba < 12) {
        D_800F2070_F2C70.sec_bytes = 0xC0;
        D_800F2070_F2C70.blk_bytes = 0x3FC0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/99370", func_80098770_99370);
#endif

// leoLba_to_vzone
u16 func_80098964_99564(u32 lba) {
    u16 i;
    u16* ptr;

    ptr = D_800D3B48_D4748[D_800F207C_F2C7C];
    for (i = 0; i < 16; i++, ptr++) {
        if (lba < *ptr) {
            return i;
        }
    }
    return 0xFF;
}
