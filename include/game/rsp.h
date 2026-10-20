#ifndef _GAME_RSP_H
#define _GAME_RSP_H

#include "ultra64.h"

/* RSP boot microcode bounds and the RSP task buffers set up at boot (1D0B0, 7C9A0). */
extern u64 D_800B8590_B9190[]; /* rspbootTextStart */
extern u64 D_800B8660_B9260[]; /* rspbootTextEnd */
extern u64* D_800FC730_FD330;  /* task dram_stack */
extern u64* D_800FC98C_FD58C;  /* task output_buff */
extern u64* D_800F8430_F9030;  /* task output_buff_size */
extern u64* D_800FA638_FB238;  /* task yield_data_ptr */
extern s32* D_800FCE7C_FDA7C;  /* ucode text/data address pairs */

#endif
