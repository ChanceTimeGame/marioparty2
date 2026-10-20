#include "common.h"
#include "game/board.h"

/* Board HUD icon helpers. C from MP1 src/59710.c and ovl_33_PaddleBattle 2341E0.c; the rest have no
   reference or differ (near) and stay asm. */

void HuMemDirectFree(void*);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void func_80067558_68158(void);
void func_80067720_68320(void);
void func_8005390C_5450C(s32);
void func_80061584_62184(void);


INCLUDE_ASM("asm/nonmatchings/67FA0", func_800673A0_67FA0);

void func_800674BC_680BC(void) {
    ((void (*)(void))HuMemDirectFree)();
}

void func_800674D8_680D8(unk_Struct02* icons, u16 mask) {
    s32 i;

    i = 0;
    do {
        if ((mask >> i) & 1) {
            SprAttrSet(icons->unk0A, i, 0x8000);
            i++;
        } else {
            SprAttrReset(icons->unk0A, i, 0x8000);
            i++;
        }
    } while (i < 4);
}

INCLUDE_ASM("asm/nonmatchings/67FA0", func_80067558_68158);

INCLUDE_ASM("asm/nonmatchings/67FA0", func_80067720_68320);

void func_80067804_68404(void) {
    func_80067558_68158();
}

void func_80067820_68420(void) {
    func_80067720_68320();
    func_8005390C_5450C(0xFF);
    func_80061584_62184();
}

INCLUDE_ASM("asm/nonmatchings/67FA0", func_8006784C_6844C);

INCLUDE_ASM("asm/nonmatchings/67FA0", func_80067C18_68818);

INCLUDE_ASM("asm/nonmatchings/67FA0", func_80067C6C_6886C);
