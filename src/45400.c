#include "common.h"

/* func_80044DA4 is MP3 ovl_80_shared_board/F5E80.c's MBItemKoopaRKinokoExec (call item handler 13
   of the table D_800DF4B0 is the 14th entry of); the others have no C reference and stay asm. */

extern void (*D_800DF4B0_E00B0)(void);

INCLUDE_ASM("asm/nonmatchings/45400", func_80044800_45400);

INCLUDE_ASM("asm/nonmatchings/45400", func_80044D98_45998);

void func_80044DA4_459A4(void) {
    D_800DF4B0_E00B0();
}
