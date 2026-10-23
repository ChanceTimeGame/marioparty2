#include "common.h"
#include "sdk_leo.h"

// libleo command execution (MP1 83960.c, the leocmdex.c family): the C2 (Reed-Solomon) error
// correction and the 64DD command thread. IDO-compiled: every function is NON_MATCHING C with the
// asm in the matching build (see sdk_leo.h). The unit's rodata is defined here so it is one carved
// piece (D4900-D4DD0); the jump tables are the asm functions' and unused by the C.

typedef struct LEOCmdTestUnitReady {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 test;
} LEOCmdTestUnitReady;

/* .data (0xCE930-0xCE98C) */
void func_80098650_99250(void);
void func_800986F8_992F8(void);
void func_8009AD90_9B990(void);
void func_8009AE40_9BA40(void);
void func_8009AEF0_9BAF0(void);
void func_8009AFE0_9BBE0(void);
void func_8009B080_9BC80(void);
void func_8009B210_9BE10(void);
void func_8009B3D0_9BFD0(void);
void func_8009B470_9C070(void);
void func_8009B530_9C130(void);
void func_8009B570_9C170(void);
void func_8009B810_9C410(void);
void func_8009B940_9C540(void);
void func_8009B9FC_9C5FC(void);
void (*D_800CDD30_CE930[16])(void) = { /* command handlers, by command code */
    NULL,
    func_80098650_99250,
    func_8009AD90_9B990,
    func_8009B530_9C130,
    func_8009B3D0_9BFD0,
    func_8009B210_9BE10,
    func_8009B810_9C410,
    func_8009B470_9C070,
    func_8009AEF0_9BAF0,
    func_8009AFE0_9BBE0,
    func_8009B570_9C170,
    func_8009AE40_9BA40,
    func_8009B080_9BC80,
    func_8009B940_9C540,
    func_8009B9FC_9C5FC,
    func_800986F8_992F8,
};
LEOCmdRead D_800CDD70_CE970 = { { 5, 0, 0, 0, 0, 0, 0, 0, NULL }, 12, 1, NULL, 0 }; /* system-area read command template */

void func_8009969C_9A29C(void);
void func_80099770_9A370(void);
void func_800999F0_9A5F0(void);
void func_80099DD8_9A9D8(void);
void func_8009A700_9B300(void* arg);

// GF(256) exponent table, doubled; the divide indexes it from +0xFF
const u8 D_800D3D00_D4900[0x200] __attribute__((section(".rodata"))) = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1D, 0x3A, 0x74, 0xE8, 0xCD, 0x87, 0x13, 0x26,
    0x4C, 0x98, 0x2D, 0x5A, 0xB4, 0x75, 0xEA, 0xC9, 0x8F, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0,
    0x9D, 0x27, 0x4E, 0x9C, 0x25, 0x4A, 0x94, 0x35, 0x6A, 0xD4, 0xB5, 0x77, 0xEE, 0xC1, 0x9F, 0x23,
    0x46, 0x8C, 0x05, 0x0A, 0x14, 0x28, 0x50, 0xA0, 0x5D, 0xBA, 0x69, 0xD2, 0xB9, 0x6F, 0xDE, 0xA1,
    0x5F, 0xBE, 0x61, 0xC2, 0x99, 0x2F, 0x5E, 0xBC, 0x65, 0xCA, 0x89, 0x0F, 0x1E, 0x3C, 0x78, 0xF0,
    0xFD, 0xE7, 0xD3, 0xBB, 0x6B, 0xD6, 0xB1, 0x7F, 0xFE, 0xE1, 0xDF, 0xA3, 0x5B, 0xB6, 0x71, 0xE2,
    0xD9, 0xAF, 0x43, 0x86, 0x11, 0x22, 0x44, 0x88, 0x0D, 0x1A, 0x34, 0x68, 0xD0, 0xBD, 0x67, 0xCE,
    0x81, 0x1F, 0x3E, 0x7C, 0xF8, 0xED, 0xC7, 0x93, 0x3B, 0x76, 0xEC, 0xC5, 0x97, 0x33, 0x66, 0xCC,
    0x85, 0x17, 0x2E, 0x5C, 0xB8, 0x6D, 0xDA, 0xA9, 0x4F, 0x9E, 0x21, 0x42, 0x84, 0x15, 0x2A, 0x54,
    0xA8, 0x4D, 0x9A, 0x29, 0x52, 0xA4, 0x55, 0xAA, 0x49, 0x92, 0x39, 0x72, 0xE4, 0xD5, 0xB7, 0x73,
    0xE6, 0xD1, 0xBF, 0x63, 0xC6, 0x91, 0x3F, 0x7E, 0xFC, 0xE5, 0xD7, 0xB3, 0x7B, 0xF6, 0xF1, 0xFF,
    0xE3, 0xDB, 0xAB, 0x4B, 0x96, 0x31, 0x62, 0xC4, 0x95, 0x37, 0x6E, 0xDC, 0xA5, 0x57, 0xAE, 0x41,
    0x82, 0x19, 0x32, 0x64, 0xC8, 0x8D, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xDD, 0xA7, 0x53, 0xA6,
    0x51, 0xA2, 0x59, 0xB2, 0x79, 0xF2, 0xF9, 0xEF, 0xC3, 0x9B, 0x2B, 0x56, 0xAC, 0x45, 0x8A, 0x09,
    0x12, 0x24, 0x48, 0x90, 0x3D, 0x7A, 0xF4, 0xF5, 0xF7, 0xF3, 0xFB, 0xEB, 0xCB, 0x8B, 0x0B, 0x16,
    0x2C, 0x58, 0xB0, 0x7D, 0xFA, 0xE9, 0xCF, 0x83, 0x1B, 0x36, 0x6C, 0xD8, 0xAD, 0x47, 0x8E, 0x01,
    0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1D, 0x3A, 0x74, 0xE8, 0xCD, 0x87, 0x13, 0x26, 0x4C,
    0x98, 0x2D, 0x5A, 0xB4, 0x75, 0xEA, 0xC9, 0x8F, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x9D,
    0x27, 0x4E, 0x9C, 0x25, 0x4A, 0x94, 0x35, 0x6A, 0xD4, 0xB5, 0x77, 0xEE, 0xC1, 0x9F, 0x23, 0x46,
    0x8C, 0x05, 0x0A, 0x14, 0x28, 0x50, 0xA0, 0x5D, 0xBA, 0x69, 0xD2, 0xB9, 0x6F, 0xDE, 0xA1, 0x5F,
    0xBE, 0x61, 0xC2, 0x99, 0x2F, 0x5E, 0xBC, 0x65, 0xCA, 0x89, 0x0F, 0x1E, 0x3C, 0x78, 0xF0, 0xFD,
    0xE7, 0xD3, 0xBB, 0x6B, 0xD6, 0xB1, 0x7F, 0xFE, 0xE1, 0xDF, 0xA3, 0x5B, 0xB6, 0x71, 0xE2, 0xD9,
    0xAF, 0x43, 0x86, 0x11, 0x22, 0x44, 0x88, 0x0D, 0x1A, 0x34, 0x68, 0xD0, 0xBD, 0x67, 0xCE, 0x81,
    0x1F, 0x3E, 0x7C, 0xF8, 0xED, 0xC7, 0x93, 0x3B, 0x76, 0xEC, 0xC5, 0x97, 0x33, 0x66, 0xCC, 0x85,
    0x17, 0x2E, 0x5C, 0xB8, 0x6D, 0xDA, 0xA9, 0x4F, 0x9E, 0x21, 0x42, 0x84, 0x15, 0x2A, 0x54, 0xA8,
    0x4D, 0x9A, 0x29, 0x52, 0xA4, 0x55, 0xAA, 0x49, 0x92, 0x39, 0x72, 0xE4, 0xD5, 0xB7, 0x73, 0xE6,
    0xD1, 0xBF, 0x63, 0xC6, 0x91, 0x3F, 0x7E, 0xFC, 0xE5, 0xD7, 0xB3, 0x7B, 0xF6, 0xF1, 0xFF, 0xE3,
    0xDB, 0xAB, 0x4B, 0x96, 0x31, 0x62, 0xC4, 0x95, 0x37, 0x6E, 0xDC, 0xA5, 0x57, 0xAE, 0x41, 0x82,
    0x19, 0x32, 0x64, 0xC8, 0x8D, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xDD, 0xA7, 0x53, 0xA6, 0x51,
    0xA2, 0x59, 0xB2, 0x79, 0xF2, 0xF9, 0xEF, 0xC3, 0x9B, 0x2B, 0x56, 0xAC, 0x45, 0x8A, 0x09, 0x12,
    0x24, 0x48, 0x90, 0x3D, 0x7A, 0xF4, 0xF5, 0xF7, 0xF3, 0xFB, 0xEB, 0xCB, 0x8B, 0x0B, 0x16, 0x2C,
    0x58, 0xB0, 0x7D, 0xFA, 0xE9, 0xCF, 0x83, 0x1B, 0x36, 0x6C, 0xD8, 0xAD, 0x47, 0x8E, 0x01, 0x02,
};

// GF(256) logarithm table (the second half is the same table shifted by one, unused here)
const u8 D_800D3F00_D4B00[0x200] __attribute__((section(".rodata"))) = {
    0x00, 0x00, 0x01, 0x19, 0x02, 0x32, 0x1A, 0xC6, 0x03, 0xDF, 0x33, 0xEE, 0x1B, 0x68, 0xC7, 0x4B,
    0x04, 0x64, 0xE0, 0x0E, 0x34, 0x8D, 0xEF, 0x81, 0x1C, 0xC1, 0x69, 0xF8, 0xC8, 0x08, 0x4C, 0x71,
    0x05, 0x8A, 0x65, 0x2F, 0xE1, 0x24, 0x0F, 0x21, 0x35, 0x93, 0x8E, 0xDA, 0xF0, 0x12, 0x82, 0x45,
    0x1D, 0xB5, 0xC2, 0x7D, 0x6A, 0x27, 0xF9, 0xB9, 0xC9, 0x9A, 0x09, 0x78, 0x4D, 0xE4, 0x72, 0xA6,
    0x06, 0xBF, 0x8B, 0x62, 0x66, 0xDD, 0x30, 0xFD, 0xE2, 0x98, 0x25, 0xB3, 0x10, 0x91, 0x22, 0x88,
    0x36, 0xD0, 0x94, 0xCE, 0x8F, 0x96, 0xDB, 0xBD, 0xF1, 0xD2, 0x13, 0x5C, 0x83, 0x38, 0x46, 0x40,
    0x1E, 0x42, 0xB6, 0xA3, 0xC3, 0x48, 0x7E, 0x6E, 0x6B, 0x3A, 0x28, 0x54, 0xFA, 0x85, 0xBA, 0x3D,
    0xCA, 0x5E, 0x9B, 0x9F, 0x0A, 0x15, 0x79, 0x2B, 0x4E, 0xD4, 0xE5, 0xAC, 0x73, 0xF3, 0xA7, 0x57,
    0x07, 0x70, 0xC0, 0xF7, 0x8C, 0x80, 0x63, 0x0D, 0x67, 0x4A, 0xDE, 0xED, 0x31, 0xC5, 0xFE, 0x18,
    0xE3, 0xA5, 0x99, 0x77, 0x26, 0xB8, 0xB4, 0x7C, 0x11, 0x44, 0x92, 0xD9, 0x23, 0x20, 0x89, 0x2E,
    0x37, 0x3F, 0xD1, 0x5B, 0x95, 0xBC, 0xCF, 0xCD, 0x90, 0x87, 0x97, 0xB2, 0xDC, 0xFC, 0xBE, 0x61,
    0xF2, 0x56, 0xD3, 0xAB, 0x14, 0x2A, 0x5D, 0x9E, 0x84, 0x3C, 0x39, 0x53, 0x47, 0x6D, 0x41, 0xA2,
    0x1F, 0x2D, 0x43, 0xD8, 0xB7, 0x7B, 0xA4, 0x76, 0xC4, 0x17, 0x49, 0xEC, 0x7F, 0x0C, 0x6F, 0xF6,
    0x6C, 0xA1, 0x3B, 0x52, 0x29, 0x9D, 0x55, 0xAA, 0xFB, 0x60, 0x86, 0xB1, 0xBB, 0xCC, 0x3E, 0x5A,
    0xCB, 0x59, 0x5F, 0xB0, 0x9C, 0xA9, 0xA0, 0x51, 0x0B, 0xF5, 0x16, 0xEB, 0x7A, 0x75, 0x2C, 0xD7,
    0x4F, 0xAE, 0xD5, 0xE9, 0xE6, 0xE7, 0xAD, 0xE8, 0x74, 0xD6, 0xF4, 0xEA, 0xA8, 0x50, 0x58, 0xAF,
    0xFF, 0x01, 0x19, 0x02, 0x32, 0x1A, 0xC6, 0x03, 0xDF, 0x33, 0xEE, 0x1B, 0x68, 0xC7, 0x4B, 0x04,
    0x64, 0xE0, 0x0E, 0x34, 0x8D, 0xEF, 0x81, 0x1C, 0xC1, 0x69, 0xF8, 0xC8, 0x08, 0x4C, 0x71, 0x05,
    0x8A, 0x65, 0x2F, 0xE1, 0x24, 0x0F, 0x21, 0x35, 0x93, 0x8E, 0xDA, 0xF0, 0x12, 0x82, 0x45, 0x1D,
    0xB5, 0xC2, 0x7D, 0x6A, 0x27, 0xF9, 0xB9, 0xC9, 0x9A, 0x09, 0x78, 0x4D, 0xE4, 0x72, 0xA6, 0x06,
    0xBF, 0x8B, 0x62, 0x66, 0xDD, 0x30, 0xFD, 0xE2, 0x98, 0x25, 0xB3, 0x10, 0x91, 0x22, 0x88, 0x36,
    0xD0, 0x94, 0xCE, 0x8F, 0x96, 0xDB, 0xBD, 0xF1, 0xD2, 0x13, 0x5C, 0x83, 0x38, 0x46, 0x40, 0x1E,
    0x42, 0xB6, 0xA3, 0xC3, 0x48, 0x7E, 0x6E, 0x6B, 0x3A, 0x28, 0x54, 0xFA, 0x85, 0xBA, 0x3D, 0xCA,
    0x5E, 0x9B, 0x9F, 0x0A, 0x15, 0x79, 0x2B, 0x4E, 0xD4, 0xE5, 0xAC, 0x73, 0xF3, 0xA7, 0x57, 0x07,
    0x70, 0xC0, 0xF7, 0x8C, 0x80, 0x63, 0x0D, 0x67, 0x4A, 0xDE, 0xED, 0x31, 0xC5, 0xFE, 0x18, 0xE3,
    0xA5, 0x99, 0x77, 0x26, 0xB8, 0xB4, 0x7C, 0x11, 0x44, 0x92, 0xD9, 0x23, 0x20, 0x89, 0x2E, 0x37,
    0x3F, 0xD1, 0x5B, 0x95, 0xBC, 0xCF, 0xCD, 0x90, 0x87, 0x97, 0xB2, 0xDC, 0xFC, 0xBE, 0x61, 0xF2,
    0x56, 0xD3, 0xAB, 0x14, 0x2A, 0x5D, 0x9E, 0x84, 0x3C, 0x39, 0x53, 0x47, 0x6D, 0x41, 0xA2, 0x1F,
    0x2D, 0x43, 0xD8, 0xB7, 0x7B, 0xA4, 0x76, 0xC4, 0x17, 0x49, 0xEC, 0x7F, 0x0C, 0x6F, 0xF6, 0x6C,
    0xA1, 0x3B, 0x52, 0x29, 0x9D, 0x55, 0xAA, 0xFB, 0x60, 0x86, 0xB1, 0xBB, 0xCC, 0x3E, 0x5A, 0xCB,
    0x59, 0x5F, 0xB0, 0x9C, 0xA9, 0xA0, 0x51, 0x0B, 0xF5, 0x16, 0xEB, 0x7A, 0x75, 0x2C, 0xD7, 0x4F,
    0xAE, 0xD5, 0xE9, 0xE6, 0xE7, 0xAD, 0xE8, 0x74, 0xD6, 0xF4, 0xEA, 0xA8, 0x50, 0x58, 0xAF, 0xFF,
};

// All of the unit's rodata comes first: GCC does not see an INCLUDE_ASM switch to .text, so a
// definition after one would land in .text.
#ifndef NON_MATCHING
// func_80099610_9A210's jump table; the three zero words are the 16-byte padding IDO left after
// its object (KMC GCC caps the alignment of D_800D4120_D4D20 at 8)
const u32 jtbl_800D4100_D4D00[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80099688, 0x80099640, 0x80099650, 0x80099660, 0x80099670, 0, 0, 0,
};
#endif

// system-area lbas tried in turn
const u8 D_800D4120_D4D20[4] __attribute__((aligned(8), section(".rodata"))) = {
    0x00, 0x01, 0x08, 0x09,
};

#ifndef NON_MATCHING
// func_8009A700_9B300's jump tables
const u32 jtbl_800D4128_D4D28[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009A980, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4, 0x8009A9C4,
    0x8009A980, 0x8009A9C4, 0x8009A9C4, 0x8009A980, 0x8009A980, 0x8009A980,
    0x8009A980, 0x8009A980,
};
const u32 jtbl_800D4160_D4D60[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009A980, 0x8009A940, 0x8009A940, 0x8009A940, 0x8009A940, 0x8009A940,
    0x8009A940, 0x8009A940, 0x8009A940, 0x8009A980, 0x8009A940, 0x8009A980,
    0x8009A980, 0x8009A980,
};
const u32 jtbl_800D4198_D4D98[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8009AADC, 0x8009AADC, 0x8009A9F4, 0x8009A9F4, 0x8009A9F4, 0x8009A9F4,
    0x8009AADC, 0x8009A9F4, 0x8009A9F4, 0x8009AADC, 0x8009A9F4, 0x8009AADC,
    0x8009AADC, 0x8009AADC,
};
#endif

#ifdef NON_MATCHING
// leoC2_Correction: by the number of C1 error sectors
u16 func_80099610_9A210(void) {
    switch (D_800F28D0_F34D0.errNum) {
        case 0:
            return 0;
        case 1:
            func_8009969C_9A29C();
            return 0;
        case 2:
            func_80099770_9A370();
            return 0;
        case 3:
            func_800999F0_9A5F0();
            return 0;
        case 4:
            func_80099DD8_9A9D8();
            return 0;
        default:
            return 0xFFFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_80099610_9A210);
#endif

#ifdef NON_MATCHING
// one erroneous sector: XOR the C2 parity back in
void func_8009969C_9A29C(void) {
    u32 s = D_800F28D0_F34D0.errSector[0];
    u32 n;
    u8* p;
    u8* c2;

    if (s >= 0x55) {
        return;
    }
    n = D_800F28D0_F34D0.secBytes;
    p = D_800F28D0_F34D0.dram + (s + 1) * n;
    c2 = D_800F28D0_F34D0.c2end;
    for (; n != 0; n--) {
        c2 -= 4;
        p--;
        *p ^= *c2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_8009969C_9A29C);
#endif

#ifdef NON_MATCHING
// two erroneous sectors: solve for both from the two C2 syndromes
void func_80099770_9A370(void) {
    u32 e1 = D_800F28D0_F34D0.errSector[0];
    u32 e2 = D_800F28D0_F34D0.errSector[1];
    const u8* a2 = &D_800D3D00_D4900[0x58 - e2]; // alpha^(88 - e2)
    u8 k;
    u32 n;
    u8* p1;
    u8* p2;
    u8* c2;
    u8 s0;
    u8 s1;
    u8 v;

    k = D_800D3F00_D4B00[func_8009A6B8_9B2B8(1, D_800D3D00_D4900[0x58 - e2] ^ D_800D3D00_D4900[0x58 - e1])];
    n = D_800F28D0_F34D0.secBytes;
    if (D_800F28D0_F34D0.errSector[1] < 0x55) {
        p2 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[1] + 1) * n;
    } else {
        if (D_800F28D0_F34D0.errSector[0] >= 0x55) {
            return;
        }
        p2 = D_800F29F8_F35F8;
    }
    p1 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[0] + 1) * n;
    c2 = D_800F28D0_F34D0.c2end;
    for (; n != 0; n--) {
        c2 -= 4;
        p1--;
        s0 = c2[0];
        if (s0 != 0) {
            s1 = c2[1] ^ a2[D_800D3F00_D4B00[s0]];
        } else {
            s1 = c2[1];
        }
        p2--;
        if (s1 != 0) {
            v = D_800D3D00_D4900[D_800D3F00_D4B00[s1] + k];
            *p1 ^= v;
            *p2 ^= v ^ s0;
        } else {
            *p2 ^= s0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_80099770_9A370);
#endif

#ifdef NON_MATCHING
// three erroneous sectors: invert the 3x3 Vandermonde system once, then correct each byte column
void func_800999F0_9A5F0(void) {
    u8 a = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[0]];
    u8 b = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[1]];
    u8 c = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[2]];
    u8 a2, b2, c2sq;
    u8 m10, m11, m12; // row coefficients (logs) for sector 1
    u8 m20, m21, m22; // sector 2
    u8 m30, m31, m32; // sector 3
    u8 det;
    u8 d1, d2, d3;
    u32 n;
    u8* p1;
    u8* p2;
    u8* p3;
    u8* c2;
    u8 x, lx;
    u8 v1, v2, v3;

    c2sq = func_8009A674_9B274(c, c);
    b2 = func_8009A674_9B274(b, b);
    a2 = func_8009A674_9B274(a, a);
    d1 = func_8009A674_9B274(c, b2) ^ func_8009A674_9B274(b, c2sq);
    d2 = func_8009A674_9B274(a, c2sq) ^ func_8009A674_9B274(c, a2);
    d3 = func_8009A674_9B274(a, b2) ^ func_8009A674_9B274(b, a2);
    det = func_8009A6B8_9B2B8(1, d1 ^ d2 ^ d3);

    m10 = D_800D3F00_D4B00[d1];
    m11 = D_800D3F00_D4B00[c2sq ^ b2];
    m12 = D_800D3F00_D4B00[b ^ c];
    m20 = D_800D3F00_D4B00[d2];
    m21 = D_800D3F00_D4B00[c2sq ^ a2];
    m22 = D_800D3F00_D4B00[c ^ a];
    m30 = D_800D3F00_D4B00[d3];
    m31 = D_800D3F00_D4B00[b2 ^ a2];
    m32 = D_800D3F00_D4B00[a ^ b];
    det = D_800D3F00_D4B00[det];

    n = D_800F28D0_F34D0.secBytes;
    if (D_800F28D0_F34D0.errSector[2] < 0x55) {
        p3 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[2] + 1) * n;
        p2 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[1] + 1) * n;
    } else {
        p3 = D_800F29F8_F35F8;
        if (D_800F28D0_F34D0.errSector[1] < 0x55) {
            p2 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[1] + 1) * n;
        } else {
            p2 = D_800F29F8_F35F8;
            if (D_800F28D0_F34D0.errSector[0] >= 0x55) {
                return;
            }
        }
    }
    p1 = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[0] + 1) * n;
    c2 = D_800F28D0_F34D0.c2end;
    do {
        c2 -= 4;
        p1--;
        p2--;
        if ((x = c2[0]) != 0) {
            lx = D_800D3F00_D4B00[x];
            v1 = D_800D3D00_D4900[lx + m10];
            v2 = D_800D3D00_D4900[lx + m20];
            v3 = D_800D3D00_D4900[lx + m30];
        } else {
            v1 = v2 = v3 = 0;
        }
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800D3F00_D4B00[x];
            v1 ^= D_800D3D00_D4900[lx + m11];
            v2 ^= D_800D3D00_D4900[lx + m21];
            v3 ^= D_800D3D00_D4900[lx + m31];
        }
        if ((x = c2[2]) != 0) {
            lx = D_800D3F00_D4B00[x];
            v1 ^= D_800D3D00_D4900[lx + m12];
            v2 ^= D_800D3D00_D4900[lx + m22];
            v3 ^= D_800D3D00_D4900[lx + m32];
        }
        p3--;
        if (v1 != 0) {
            *p1 ^= D_800D3D00_D4900[D_800D3F00_D4B00[v1] + det];
        }
        if (v2 != 0) {
            *p2 ^= D_800D3D00_D4900[D_800D3F00_D4B00[v2] + det];
        }
        if (v3 != 0) {
            *p3 ^= D_800D3D00_D4900[D_800D3F00_D4B00[v3] + det];
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_800999F0_9A5F0);
#endif

#define GF_MUL func_8009A674_9B274
#define GF_DIV func_8009A6B8_9B2B8

#ifdef NON_MATCHING
// four erroneous sectors: Lagrange weights per sector, then every syndrome's contribution per byte
void func_80099DD8_9A9D8(void) {
    u8 A1 = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[0]];
    u8 A2 = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[1]];
    u8 A3 = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[2]];
    u8 A4 = D_800D3D00_D4900[0x58 - D_800F28D0_F34D0.errSector[3]];
    u8 one = D_800D3D00_D4900[0];
    u8 iA, iB, iC, iD;
    u8 BC, CD, DB, DA, AC, AB;
    u8 q1[4]; // second-syndrome coefficient values (iB^iC^iD, ...)
    u8 r1[4]; // third-syndrome coefficient values
    u8 t1[4]; // fourth-syndrome coefficient values
    u8 W[4];  // Lagrange weights
    u8 L0[4], L1[4], L2[4], L3[4]; // logs of the weighted coefficients, per syndrome
    u32 i;
    u32 n;
    u8* p[4];
    u8* c2;
    u8 x, lx;
    u8 v[4];

    iA = GF_DIV(one, A1);
    iB = GF_DIV(one, A2);
    iC = GF_DIV(one, A3);
    iD = GF_DIV(one, A4);
    BC = GF_MUL(iB, iC);
    CD = GF_MUL(iC, iD);
    DB = GF_MUL(iD, iB);
    DA = GF_MUL(iD, iA);
    AC = GF_MUL(iA, iC);
    AB = GF_MUL(iA, iB);
    r1[0] = BC ^ CD ^ DB;
    r1[1] = CD ^ DA ^ AC;
    r1[2] = DA ^ AB ^ DB;
    r1[3] = AB ^ BC ^ AC;
    q1[0] = iB ^ iC ^ iD;
    q1[1] = iC ^ iD ^ iA;
    q1[2] = iD ^ iA ^ iB;
    q1[3] = iA ^ iB ^ iC;
    t1[0] = GF_MUL(GF_MUL(iB, iC), iD);
    t1[1] = GF_MUL(GF_MUL(iC, iD), iA);
    t1[2] = GF_MUL(GF_MUL(iD, iA), iB);
    t1[3] = GF_MUL(GF_MUL(iA, iB), iC);

    W[0] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A1, A2) ^ 1, GF_DIV(A1, A3) ^ 1), GF_DIV(A1, A4) ^ 1));
    W[1] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A2, A1) ^ 1, GF_DIV(A2, A3) ^ 1), GF_DIV(A2, A4) ^ 1));
    W[2] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A3, A1) ^ 1, GF_DIV(A3, A2) ^ 1), GF_DIV(A3, A4) ^ 1));
    W[3] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A4, A1) ^ 1, GF_DIV(A4, A2) ^ 1), GF_DIV(A4, A3) ^ 1));

    for (i = 0; i < 4; i++) {
        L1[i] = D_800D3F00_D4B00[GF_MUL(q1[i], W[i])];
        L2[i] = D_800D3F00_D4B00[GF_MUL(r1[i], W[i])];
        L3[i] = D_800D3F00_D4B00[GF_MUL(t1[i], W[i])];
        L0[i] = D_800D3F00_D4B00[W[i]];
    }

    n = D_800F28D0_F34D0.secBytes;
    if (D_800F28D0_F34D0.errSector[3] < 0x55) {
        p[3] = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[3] + 1) * n;
        goto sector3;
    }
    p[3] = D_800F29F8_F35F8;
    if (D_800F28D0_F34D0.errSector[2] < 0x55) {
    sector3:
        p[2] = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[2] + 1) * n;
        goto sector2;
    }
    p[2] = D_800F29F8_F35F8;
    if (D_800F28D0_F34D0.errSector[1] < 0x55) {
    sector2:
        p[1] = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[1] + 1) * n;
    } else {
        p[1] = D_800F29F8_F35F8;
        if (D_800F28D0_F34D0.errSector[0] >= 0x55) {
            return;
        }
    }
    p[0] = D_800F28D0_F34D0.dram + (D_800F28D0_F34D0.errSector[0] + 1) * n;

    c2 = D_800F28D0_F34D0.c2end;
    do {
        c2 -= 4;
        p[0]--;
        p[1]--;
        if ((x = c2[0]) != 0) {
            lx = D_800D3F00_D4B00[x];
            for (i = 0; i < 4; i++) {
                v[i] = D_800D3D00_D4900[lx + L0[i]];
            }
        } else {
            v[0] = v[1] = v[2] = v[3] = 0;
        }
        p[2]--;
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800D3F00_D4B00[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (q1[i] != 0) ? D_800D3D00_D4900[lx + L1[i]] : 0;
            }
        }
        if ((x = c2[2]) != 0) {
            lx = D_800D3F00_D4B00[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (r1[i] != 0) ? D_800D3D00_D4900[lx + L2[i]] : 0;
            }
        }
        if ((x = c2[3]) != 0) {
            lx = D_800D3F00_D4B00[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= D_800D3D00_D4900[lx + L3[i]];
            }
        }
        p[3]--;
        for (i = 0; i < 4; i++) {
            if (v[i] != 0) {
                *p[i] ^= v[i];
            }
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_80099DD8_9A9D8);
#endif

#ifdef NON_MATCHING
// GF(256) multiply
u8 func_8009A674_9B274(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800D3D00_D4900[D_800D3F00_D4B00[b] + D_800D3F00_D4B00[a]];
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_8009A674_9B274);
#endif

#ifdef NON_MATCHING
// GF(256) divide
u8 func_8009A6B8_9B2B8(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800D3D00_D4900[0xFF + D_800D3F00_D4B00[a] - D_800D3F00_D4B00[b]];
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_8009A6B8_9B2B8);
#endif

#ifdef NON_MATCHING
// leomain: the 64DD command thread
void func_8009A700_9B300(void* arg) {
    u32 stat;
    u32 sense;
    u8 command;

    ((u8*)&D_800F2080_F2C80)[0] = *(vu8*)0xA0000010;
    ((u8*)&D_800F2080_F2C80)[1] = *(vu8*)0xA0000090;
    ((u8*)&D_800F2080_F2C80)[2] = *(vu8*)0xA0000110;
    ((u8*)&D_800F2080_F2C80)[3] = *(vu8*)0xA0000190;
    D_800F2068_F2C68 = 0;
    D_800F2064_F2C64 = 0;
    D_800F206C_F2C6C = 0;
    D_800F206D_F2C6D = 0;
    func_80098490_99090();
    D_800F28E0_F34E0 = osLeoDiskInit();
    D_800F28E8_F34E8.hdr.pri = OS_MESG_PRI_HIGH;
    D_800F28E8_F34E8.hdr.retQueue = &D_800F2018_F2C18;
    osEPiReadIo(D_800F28E0_F34E0, 0x05000508, &stat); // LEO_STATUS
    if (!(stat & 0x400000) && (stat & 0x6800000)) {
        func_800983D0_98FD0();
    }

    while (TRUE) {
        osRecvMesg(&D_800F1FD0_F2BD0, (OSMesg*)&D_800F2060_F2C60, OS_MESG_BLOCK);
        D_800F2900_F3500 = LEO_CUR(LEOCmdHeader)->command;
        if (LEO_CUR(LEOCmdHeader)->command == 0) { // clear queue
            func_800983D0_98FD0();
            osRecvMesg(&D_800F1FE8_F2BE8, NULL, OS_MESG_NOBLOCK);
            continue;
        }

        sense = func_80097C5C_9885C(0x10001);
        stat = func_80098400_99000();
        if (stat == 0) {
            if (sense == 0) {
                goto dispatch;
            }
        } else if ((sense != 3) && (sense != 0x25) && (sense != 0x29) && (sense != 0x2B)) {
            if (sense == 0x31) {
                if (func_8009840C_9900C() == 0x2B) {
                    sense = 0x2B;
                }
            } else {
                sense = func_8009840C_9900C();
            }
        }

        command = LEO_CUR(LEOCmdHeader)->command;
        if (sense == 0x2B) { // medium may have changed
            if ((command == 2) || (command == 0xD) || (command == 0xE)) {
                goto dispatch;
            }
            if (command == 0xF) {
                func_80098440_99040();
                goto dispatch;
            }
        } else if (sense == 0x2F) {
            switch (command) {
                case 2:
                case 8:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
            }
        } else if (sense == 0x31) {
            switch (command) {
                case 2:
                case 11:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
                default:
                    sense = 0x2A;
                    break;
            }
        }
        if (command == 3) { // test unit ready
            LEO_CUR(LEOCmdTestUnitReady)->test = func_80098390_98F90();
        }
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        goto done;

    dispatch:
        if (D_800F206C_F2C6C == 0) {
            switch (LEO_CUR(LEOCmdHeader)->command) {
                case 2:
                case 3:
                case 8:
                case 11:
                case 13:
                case 14:
                case 15:
                    break;
                default:
                    // commands that need the system area: read it first
                    if (D_800F2080_F2C80 == 0) {
                        osEPiReadIo(D_800F28E0_F34E0, 0x05000540, &stat); // ASIC_ID_REG
                        if ((stat & 0x70000) != 0x40000) {
                            while (TRUE) {
                            }
                        }
                    }
                    if (func_8009AB7C_9B77C() != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    sense = func_80097FF0_98BF0(0xB0001, D_800F2090_F2C90[5] << 16);
                    LEO_CUR(LEOCmdHeader)->sense_code = sense;
                    if (sense != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    if ((D_800F2090_F2C90[5] & 0xF0) != 0x10) {
                        goto bad_disk;
                    }
                    D_800F207C_F2C7C = D_800F2090_F2C90[5] & 0xF;
                    if (D_800F207C_F2C7C >= 7) {
                    bad_disk:
                        LEO_CUR(LEOCmdHeader)->sense_code = 0xB;
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    D_800F206C_F2C6C = 0xFF;
                    break;
            }
        }
        D_800CDD30_CE930[LEO_CUR(LEOCmdHeader)->command]();

    done:
        if (LEO_CUR(LEOCmdHeader)->control & 0x80) {
            osSendMesg(LEO_CUR(LEOCmdHeader)->post, (OSMesg)(u32)LEO_CUR(LEOCmdHeader)->sense_code,
                       OS_MESG_BLOCK);
        }
        if (D_800F206D_F2C6D != 0) {
            func_80098650_99250();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_8009A700_9B300);
#endif

#ifdef NON_MATCHING
// leoRead_system_area: read the disk's system area into D_800F2090_F2C90, retrying
u8 func_8009AB7C_9B77C(void) {
    LEOCmdRead* saved = D_800F2060_F2C60;
    LEOCmdRead tmp;
    u32 retry = 0;
    s32 phase = 0;
    u8 sense;

    D_800F2060_F2C60 = &tmp;
    while (TRUE) {
        tmp = D_800CDD70_CE970;
        D_800F207C_F2C7C = 0;
        D_800F2090_F2C90[8] = 0;
        D_800F206E_F2C6E = 0x3000;
        if (phase == 0) {
            func_8009B23C_9BE3C(0);
            if (tmp.header.sense_code == 0) {
                retry = 0;
                // as retail: spins forever while the drive ROM id word is non-zero
                while (D_800F2080_F2C80 != 0) {
                }
                phase--;
                continue;
            }
            if (tmp.header.sense_code == 0x17) {
                retry = 0;
                while (D_800F2080_F2C80 == 0) {
                }
                phase--;
                continue;
            }
        } else {
            tmp.lba = D_800D4120_D4D20[retry & 3];
            if (D_800F2080_F2C80 == 0) {
                tmp.lba += 2;
            }
            func_8009B23C_9BE3C(0);
            if (tmp.header.status == LEO_STATUS_GOOD) {
                while (D_800F2080_F2C80 != *(u32*)D_800F2090_F2C90) {
                }
                break;
            }
        }
        while (TRUE) {
            if (func_80098280_98E80(tmp.header.sense_code) != 0) {
                goto end;
            }
            if (retry >= 0x40) {
                goto end;
            }
            retry++;
            if ((retry & 7) != 0) {
                break;
            }
            sense = func_80097FF0_98BF0(0x30001, 0);
            tmp.header.sense_code = sense;
            if (sense == 0) {
                break;
            }
        }
    }
end:
    D_800F2060_F2C60 = saved;
    saved->header.sense_code = tmp.header.sense_code;
    return tmp.header.sense_code;
}
#else
INCLUDE_ASM("asm/nonmatchings/9A210", func_8009AB7C_9B77C);
#endif
