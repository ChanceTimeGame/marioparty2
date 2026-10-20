#include "common.h"
#include "game/gamework.h"

/* Minigame records and unlock bits, board play counts. C from MP1 src/59E80.c and MP3 src/save.c
   (GW* functions); the rest have no reference or differ (near) and stay asm. */

extern s32 D_800E2040_E2C40;

void GWMgBitGet(s16, s16*, s16*);
u16* func_800680F8_68CF8(s16);
s32 HuGetPadInserted(s16);


extern u8 D_800F8CD8[];

INCLUDE_ASM("asm/nonmatchings/68990", func_80067D90_68990);

INCLUDE_ASM("asm/nonmatchings/68990", func_80067E6C_68A6C);

INCLUDE_ASM("asm/nonmatchings/68990", GWMgBitGet);

void func_80067EF8_68AF8(s32 arg0) {
    s16 var0;
    s16 var1;

    GWMgBitGet(arg0, &var0, &var1);
    D_800F8C60.mgBits1[var0] = (D_800F8C60.mgBits1[var0] | (1 << var1));
}

s16 func_80067F4C_68B4C(s16 arg0) {
    s16 var0;
    s16 var1;

    GWMgBitGet(arg0, &var0, &var1);
    return D_800F8C60.mgBits1[var0] & (1 << var1);
}

void func_80067F94_68B94(s16 arg0) {
    s16 var0;
    s16 var1;

    GWMgBitGet(arg0, &var0, &var1);
    D_800F8C60.mgBits2[var0] = (D_800F8C60.mgBits2[var0] | (1 << var1));
}

void GWMgUnlockReset(s16 bitPos) {
    s16 outBytePos;
    s16 outBitPos;

    GWMgBitGet(bitPos, &outBytePos, &outBitPos);
    D_800F8C60.mgBits2[outBytePos] &= ~(1 << outBitPos);
}

s16 func_80068040_68C40(s16 arg0) {
    s16 var0;
    s16 var1;

    GWMgBitGet(arg0, &var0, &var1);
    return D_800F8C60.mgBits2[var0] & (1 << var1);
}

void GWMgRecordSet(s16 arg0, s16 arg1) {
    if (_CheckFlag(21) == 0) {
        D_800F8C60.mgRecord[arg0] = arg1;
    }
}

u16 func_800680D4_68CD4(s16 index) {
    return D_800F8C60.mgRecord[index];
}

INCLUDE_ASM("asm/nonmatchings/68990", func_800680EC_68CEC);

u16* func_800680F8_68CF8(s16 index) {
    if (index < 0) {
        index = GwSystem.current_board_index;
    }
    return &D_800F8C60.boardRecord[index][0];
}

u16 func_80068128_68D28(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_800680F8_68CF8(index);
    return *ptr & 0x3FF;
}

void func_80068150_68D50(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_800680F8_68CF8(index);
    if (index < 0) {
        index = GwSystem.current_board_index;
    }
    if (index < 8) {
        {
            u16 uVar;
            u16 uVarAnd;

            uVarAnd = *ptr & 0xFC00;
            uVar = *ptr & 0x3FF;

            if (++uVar > 999) {
                uVar = 999;
            }
            *ptr = uVar | uVarAnd;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/68990", func_800681D8_68DD8);

s32 func_80068268_68E68(s16 index, u16 param_2) {
    u16 *ptr;
    u16 ret;
    u32 andr;

    ptr = (u16 *)func_800680F8_68CF8(index);
    ret = *ptr & 0xFC00;
    return ret & (andr = param_2); // ?
}

void func_800682A4_68EA4(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_800680F8_68CF8(index);
    *ptr |= param_2 & 0xFC00;
}

void func_800682E0_68EE0(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_800680F8_68CF8(index);
    *ptr &= ~(param_2 & 0xFC00);
}

void func_80068320_68F20(void) {
}

s32 _CheckFlag(s32 arg0) {
    return D_800F8CD8[arg0 / 8] & (1 << (arg0 % 8));
}

void _SetFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800F8CD8[byteIndex] = D_800F8CD8[byteIndex] | (1 << (input - (bitIndex)));
}

void _ClearFlag(s32 input) {
    s32 adjustedInput;
    s32 byteIndex;
    s32 bitIndex;

    // Adjust input if negative to handle division by 8 correctly
    if (input < 0) {
        adjustedInput = input + 7;
    } else {
        adjustedInput = input;
    }
    
    // Calculate the byte index in the array
    byteIndex = adjustedInput >> 3; // Same as dividing by 8
    
    // Temporary variable to handle bit position calculation
    bitIndex = input;
    
    if (input < 0) {
        bitIndex = input + 7;
    }
    
    // Calculate the bit position within the byte
    bitIndex = bitIndex >> 3 << 3;
    
    // Set the specific bit in the byte at byteIndex
    D_800F8CD8[byteIndex] = D_800F8CD8[byteIndex] & ~(1 << (input - (bitIndex)));
}

void GWContErrorSet(void) {
    if (HuGetPadInserted(0) != FALSE) {
        D_800E2040_E2C40 = TRUE;
        return;
    }
    D_800E2040_E2C40 = FALSE;
}

INCLUDE_ASM("asm/nonmatchings/68990", func_80068448_69048);
