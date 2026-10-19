#include "common.h"
#include "process.h"

/* Pause-menu start (MP1 src/72D90.c GamePauseStart); the rest of the unit has no exact reference. */

extern Process* D_800FA6E0_FB2E0;

void omPrcSetStatBit(Process* process, s32 value);
void func_80072874_73474(void);

INCLUDE_ASM("asm/nonmatchings/733F0", func_800727F0_733F0);

void GamePauseStart(void) {
    D_800FA6E0_FB2E0 = omAddPrcObj(func_80072874_73474, 0x3FFF, 0x800, 0);
    omPrcSetStatBit(D_800FA6E0_FB2E0, 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/733F0", func_80072874_73474);

INCLUDE_ASM("asm/nonmatchings/733F0", func_80072E20_73A20);

INCLUDE_ASM("asm/nonmatchings/733F0", func_80072E58_73A58);
