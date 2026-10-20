#include "common.h"
#include "game/malloc.h"
#include "game/pad.h"
#include "game/gamework.h"

/* Save-file EEPROM wrappers and the message-string directory (MP1 src/59E80.c, MP3 src/36F80.c,
   MP1 src/engine/data.c). MP1's names are anonymous, so MP2's are kept. */

typedef struct StrData {
    /* 0x00 */ u8* string; /* ROM address */
    /* 0x04 */ u16 size;
} StrData;

extern u16 ContDStkTrg[];
extern u8 D_800E2050_E2C50;
extern u32 D_800E2060_E2C60;
extern u32 D_800E2064_E2C64;
extern u32* D_800E2068_E2C68;
extern s32 D_800E206C_E2C6C;

s32 dmaRead(u8* src, u8* dest, s32 size);
void func_8001B078_1BC78(s32 arg0, UnkEep* arg1, s16 arg2);
s32 HuGetPadInserted(s16 port);
u16 func_80068720_69320(void);
void func_8006877C_6937C(void);
void func_80068C48_69848(s32 index, StrData* out);

s32 func_800686F0_692F0(void) {
    return ContDStkTrg[gPlayers[0].port] | (D_800FC9E0_FD5E0[gPlayers[0].port] & 0xF00);
}

u16 func_80068720_69320(void) {
    return GetSaveFileChecksum(0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10);
}

s32 func_80068744_69344(void) {
    u16 sum;

    sum = 0;
    if (D_800E2050_E2C50 != 0) {
        func_8001B078_1BC78((EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10, (UnkEep*)&sum, 2);
    }
    return sum;
}

void func_8006877C_6937C(void) {
    u16 sp10;

    sp10 = func_80068720_69320();
    if (D_800E2050_E2C50 != 0) {
        func_8001AFD8_1BBD8((EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10, (UnkEep*)&sp10, 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/692F0", func_800687B8_693B8);

INCLUDE_ASM("asm/nonmatchings/692F0", func_800687FC_693FC);

void func_80068964_69564(void) {
    if (D_800E2050_E2C50 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
    }
    func_8006877C_6937C();
}

void func_800689A0_695A0(void) {
    if (_CheckFlag(0) != 0) {
        _ClearFlag(0x40);
        if (D_800E2050_E2C50 != 0) {
            func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, sizeof(D_800F8C60));
        }
    } else if (D_800E2050_E2C50 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
    }
    _ClearFlag(0);
    func_8006877C_6937C();
}

void func_80068A20_69620(void) {
    if (D_800E2050_E2C50 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, sizeof(D_800F8C60));
        func_8001AFD8_1BBD8(0xC4, (UnkEep*)gPlayers, 0x104);
        func_8001AFD8_1BBD8(0x1C8, (UnkEep*)&GwSystem, sizeof(GwSystem));
    }
    func_8006877C_6937C();
}

void func_80068A84_69684(void) {
    if (D_800E2050_E2C50 != 0) {
        func_8001B078_1BC78(0x80, (UnkEep*)((u8*)&D_800F8C60 + 0x80), sizeof(D_800F8C60) - 0x80);
        func_8001B078_1BC78(0xC4, (UnkEep*)gPlayers, 0x104);
        func_8001B078_1BC78(0x1C8, (UnkEep*)&GwSystem, sizeof(GwSystem));
    }
}

s16 func_80068AE0_696E0(s16 win) {
    s16 port;
    s32 mask;
    s16 ret;

    mask = 1;
    for (port = 0; port < 4; port++) {
        if (HuGetPadInserted(port) != 0) {
            break;
        }
        mask <<= 1;
    }
    ret = (port != 4) ? port : 0;
    func_8008D59C_8E19C(win, (s16)mask);
    return ret;
}

void func_80068B80_69780(u32 stringsRomPtr) {
    s32 stringDirTableSize;
    u32* stringDirTable;
    u32* stringsHeader;

    D_800E2060_E2C60 = stringsRomPtr;
    stringsHeader = HuMemMemoryAllocPerm(16);
    dmaRead((u8*)stringsRomPtr, (u8*)stringsHeader, 16);
    D_800E2064_E2C64 = *stringsHeader;
    HuMemMemoryFreePerm(stringsHeader);
    stringDirTableSize = D_800E2064_E2C64 * 4;
    D_800E206C_E2C6C = stringDirTableSize;
    stringDirTable = HuMemMemoryAllocPerm(stringDirTableSize);
    D_800E2068_E2C68 = stringDirTable;
    dmaRead((u8*)(stringsRomPtr + 4), (u8*)stringDirTable, D_800E206C_E2C6C);
}

void func_80068C14_69814(u32 ptr) {
    D_800E2060_E2C60 = ptr;
    dmaRead((u8*)(ptr + 4), (u8*)D_800E2068_E2C68, D_800E206C_E2C6C);
}

void func_80068C48_69848(s32 index, StrData* out) {
    u16* buf = HuMemMemoryAllocPerm(0x10);

    out->string = (u8*)(D_800E2060_E2C60 + D_800E2068_E2C68[index]);
    dmaRead(out->string, (u8*)buf, 0x10);
    out->string += 2;
    out->size = *buf;
    HuMemMemoryFreePerm(buf);
}

void* func_80068CD4_698D4(s32 stringIndex) {
    StrData sp10;
    void* temp_v0;

    func_80068C48_69848(stringIndex, &sp10);
    temp_v0 = HuMemMemoryAllocPerm(sp10.size);

    if (temp_v0 != NULL) {
        dmaRead(sp10.string, temp_v0, sp10.size);
    }

    return temp_v0;
}

void func_80068D24_69924(void* file) {
    if (file != NULL) {
        HuMemMemoryFreePerm(file);
    }
}
