#include "common.h"
#include "sdk_leo.h"

// libleo leoLba_to_phys and leoLba_to_vzone (MP1 src/821F0.c). IDO-compiled: KMC GCC cannot
// reproduce it, so the C is NON_MATCHING (logic only) and the matching build keeps the asm. The
// tables are this unit's rodata (D4728 on), left in the data blob.

extern u8 D_800D3B28_D4728[];      // sector bytes per zone
extern u16 D_800D3B34_D4734[];     // block bytes per zone
extern u16 D_800D3B46_D4746[];     // D_800D3B48_D4748 one element back (start lba of the previous vzone)
extern u16 D_800D3B48_D4748[][16]; // end lba of each vzone, per disk type
extern u16 D_800D3C28_D4828[];     // start cylinder of each physical zone
extern u8 D_800D3C48_D4848[][16];  // physical zone of each vzone, per disk type
extern u16 D_800D3CB6_D48B6[];     // outer cylinder of each zone for head 1 (indexed from 1)

u16 func_80098964_99564(u32 lba);

// IDO-compiled (t-register temporaries, ra at 0x14(sp)): KMC GCC cannot reproduce it.
// Layout-dependent: D_800D3B46_D4746 and D_800D3CB6_D48B6 are labels one u16 before a table.
#ifdef NON_MATCHING
u16 func_80098770_99370(u32 lba) {
    u16 vzone;
    u16 pzone;
    u16 zone;
    u16 start;
    u16 cyl;
    u16 n;
    u16 d;

    D_800F2070_F2C70.rdwr_blocks = 2 - (lba & 1);
    if (((lba & 3) == 0) || ((lba & 3) == 3)) {
        D_800F2070_F2C70.start_block = 0;
    } else {
        D_800F2070_F2C70.start_block = 1;
    }
    vzone = func_80098964_99564(lba);
    pzone = D_800D3C48_D4848[D_800F207C_F2C7C][vzone];
    D_800F2070_F2C70.head = 0;
    D_800F2070_F2C70.zone = pzone;
    zone = pzone;
    if (zone >= 8) {
        D_800F2070_F2C70.zone = zone - 7;
        D_800F2070_F2C70.head = 1;
        zone = (u8)(zone - 7);
    }
    cyl = D_800D3C28_D4828[pzone];
    start = (vzone != 0) ? D_800D3B46_D4746[D_800F207C_F2C7C * 16 + vzone] : 0;
    if (D_800F2070_F2C70.head != 0) {
        D_800F2070_F2C70.cylinder = cyl - ((lba - start) >> 1);
        cyl = D_800D3CB6_D48B6[zone];
    } else {
        D_800F2070_F2C70.cylinder = cyl + ((lba - start) >> 1);
    }
    d = (pzone != 0) ? D_800F2090_F2C90[7 + pzone] : 0;
    for (n = D_800F2090_F2C90[8 + pzone] - d; n != 0; n--) {
        if (D_800F2070_F2C70.cylinder < (u16)(D_800F2090_F2C90[0x20 + d] + cyl)) {
            break;
        }
        D_800F2070_F2C70.cylinder++;
        d++;
    }
    D_800F2070_F2C70.sec_bytes = D_800D3B28_D4728[zone];
    D_800F2070_F2C70.blk_bytes = D_800D3B34_D4734[zone];
    if (D_800F2080_F2C80 == 0 && lba < 12) {
        D_800F2070_F2C70.sec_bytes = 0xC0;
        D_800F2070_F2C70.blk_bytes = 0x3FC0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/99370", func_80098770_99370);
#endif

// leoLba_to_vzone. IDO-compiled: KMC GCC cannot reproduce it.
#ifdef NON_MATCHING
u16 func_80098964_99564(u32 lba) {
    u16 vzone;

    for (vzone = 0; vzone < 16; vzone++) {
        if (lba < D_800D3B48_D4748[D_800F207C_F2C7C][vzone]) {
            return vzone;
        }
    }
    return 0xFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/99370", func_80098964_99564);
#endif
