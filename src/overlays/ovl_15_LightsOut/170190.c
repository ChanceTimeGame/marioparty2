#include "ovl_15.h"

/* .data (0x179B90-0x17A410, 8010C200-8010CA80) */
u8 D_8010C200_179B90_LightsOut[24] = {
    0x1E, 0x00, 0x96, 0x01, 0x1E, 0x00, 0x96, 0x01, 0x1E, 0x00, 0x96, 0x01,
    0x1E, 0x00, 0x96, 0x01, 0x1E, 0x00, 0x96, 0x01, 0xFF, 0x00, 0x00, 0x00,
};
u8 D_8010C218_179BA8_LightsOut[24] = {
    0x0A, 0x13, 0x06, 0x0B, 0x0A, 0x13, 0x06, 0x0B, 0x0A, 0x13, 0x06, 0x0B,
    0x0A, 0x13, 0x06, 0x0B, 0x0A, 0x13, 0x06, 0x0B, 0x0A, 0x13, 0x06, 0x0B,
};
LOStart D_8010C230_179BC0_LightsOut[4] = {
    { 0x01A4, 0x0000, 0x0000, 0x010E },
    { -0x01A4, 0x0000, 0x0000, 0x005A },
    { 0x0000, 0x0000, 0x01A4, 0x00B4 },
    { 0x0000, 0x0000, -0x01A4, 0x0000 },
};
s32 D_8010C250_179BE0_LightsOut[6] = { 0x20000, 0x30000, 0x70000, 0x40000, 0x50000, 0x60000 };
u16 D_8010C268_179BF8_LightsOut[4] = { 0x4E, 0x4F, 0x55, 0x56 };
u8 D_8010C270_179C00_LightsOut = 0;
s32 D_8010C274_179C04_LightsOut = 0;
/* 32x64 I4 light mask: edited in RAM, so writable; bytes in ROM order */
u8 D_8010C278_179C08_LightsOut[2056] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xED, 0xCC, 0xCB, 0xBB,
    0xBB, 0xBC, 0xCC, 0xDE, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFE, 0xCC, 0xBA, 0xA9, 0x98, 0x88,
    0x88, 0x89, 0x9A, 0xAB, 0xCC, 0xEF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFD, 0xCB, 0xA9, 0x87, 0x77, 0x66, 0x66,
    0x66, 0x66, 0x77, 0x78, 0x9A, 0xBC, 0xDF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFD, 0xCA, 0x98, 0x76, 0x65, 0x54, 0x44, 0x44,
    0x44, 0x44, 0x45, 0x56, 0x67, 0x89, 0xAC, 0xDF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
    0xCB, 0x98, 0x76, 0x54, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x24, 0x45, 0x67, 0x89, 0xBC,
    0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDB,
    0xA8, 0x76, 0x54, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x45, 0x67, 0x8A,
    0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xB9,
    0x76, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x67,
    0x9B, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCA, 0x87,
    0x54, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x45,
    0x78, 0xAC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xA8, 0x65,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x56, 0x8A, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCA, 0x86, 0x53,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x68, 0xAC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xA8, 0x65, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x56, 0x8A, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xDB, 0x86, 0x52, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x25, 0x68, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFE, 0xB9, 0x75, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x57, 0x9B, 0xEF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFC, 0xA7, 0x54, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x45, 0x7A, 0xCF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xDB, 0x86, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x68, 0xBD, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xC9, 0x75, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x57, 0x9C, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFD, 0xA8, 0x64, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x46, 0x8A, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x97, 0x50, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x05, 0x79, 0xCF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xEB, 0x86, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x68, 0xBE, 0xFF, 0xFF,
    0xFF, 0xFF, 0xCA, 0x75, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x57, 0xAC, 0xFF, 0xFF,
    0xFF, 0xFF, 0xC9, 0x64, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x46, 0x9C, 0xFF, 0xFF,
    0xFF, 0xFE, 0xB8, 0x64, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x46, 0x8B, 0xEF, 0xFF,
    0xFF, 0xFD, 0xA7, 0x52, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x25, 0x7A, 0xDF, 0xFF,
    0xFF, 0xFC, 0xA7, 0x50, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x7A, 0xCF, 0xFF,
    0xFF, 0xFC, 0x97, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x79, 0xCF, 0xFF,
    0xFF, 0xFC, 0x96, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x69, 0xCF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFB, 0x86, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x68, 0xBF, 0xFF,
    0xFF, 0xFC, 0x96, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x69, 0xCF, 0xFF,
    0xFF, 0xFC, 0x97, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x79, 0xCF, 0xFF,
    0xFF, 0xFC, 0xA7, 0x50, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x05, 0x7A, 0xCF, 0xFF,
    0xFF, 0xFD, 0xA7, 0x52, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x25, 0x7A, 0xDF, 0xFF,
    0xFF, 0xFE, 0xB8, 0x64, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x46, 0x8B, 0xEF, 0xFF,
    0xFF, 0xFF, 0xC9, 0x64, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x46, 0x9C, 0xFF, 0xFF,
    0xFF, 0xFF, 0xCA, 0x75, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x57, 0xAC, 0xFF, 0xFF,
    0xFF, 0xFF, 0xEB, 0x86, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x68, 0xBE, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x97, 0x50, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x05, 0x79, 0xCF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFD, 0xA8, 0x64, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x46, 0x8A, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xC9, 0x75, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x57, 0x9C, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xDB, 0x86, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x68, 0xBD, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFC, 0xA7, 0x54, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x45, 0x7A, 0xCF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFE, 0xB9, 0x75, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x57, 0x9B, 0xEF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xDB, 0x86, 0x52, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x25, 0x68, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xA8, 0x65, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x56, 0x8A, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCA, 0x86, 0x53,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x68, 0xAC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xA8, 0x65,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x56, 0x8A, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCA, 0x87,
    0x54, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x45,
    0x78, 0xAC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xB9,
    0x76, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x67,
    0x9B, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDB,
    0xA8, 0x76, 0x54, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x45, 0x67, 0x8A,
    0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
    0xCB, 0x98, 0x76, 0x54, 0x42, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x24, 0x45, 0x67, 0x89, 0xBC,
    0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFD, 0xCA, 0x98, 0x76, 0x65, 0x54, 0x44, 0x44,
    0x44, 0x44, 0x45, 0x56, 0x67, 0x89, 0xAC, 0xDF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFD, 0xCB, 0xA9, 0x87, 0x77, 0x66, 0x66,
    0x66, 0x66, 0x77, 0x78, 0x9A, 0xBC, 0xDF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFE, 0xCC, 0xBA, 0xA9, 0x98, 0x88,
    0x88, 0x89, 0x9A, 0xAB, 0xCC, 0xEF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xED, 0xCC, 0xCB, 0xBB,
    0xBB, 0xBC, 0xCC, 0xDE, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void func_80102800_170190_LightsOut(void) {
    func_8010B1C8_178B58_LightsOut();
}

void func_8010281C_1701AC_LightsOut(Gfx** gfxp) {
    Gfx* gfx = *gfxp;
    s32 y;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                    G_CULL_BOTH | G_FOG | G_LOD);
    gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, D_8010CCC4_17A654_LightsOut->unk0C);
    for (y = 0; y < 112; y += 8) {
        gDPLoadTextureTile_4b(gfx++, D_8010CCC4_17A654_LightsOut->unk08, G_IM_FMT_CI, 288, 112, 0, y, 287,
                              y + 7, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 288 << 2, 8 << 2);
        gSPTextureRectangle(gfx++, 17 << 2, (y + 120) << 2, 305 << 2, (y + 128) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_80102B50_1704E0_LightsOut(void) {
}

void func_80102B58_1704E8_LightsOut(omObjData* obj) {
    s32 mdl;

    D_8010CD26_17A6B6_LightsOut = func_8001A2F8_1AEF8(0x250003);
    D_8010CCC4_17A654_LightsOut = SprAnimGet(D_8010CD26_17A6B6_LightsOut);
    obj->func_ptr = func_80102B50_1704E0_LightsOut;
    mdl = func_8002838C_28F8C(0, func_8010281C_1701AC_LightsOut, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_8010EC0C_17C59C_LightsOut = mdl;
}

void func_80102BDC_17056C_LightsOut(void) {
    D_8010D9C0_17B350_LightsOut = omAddObj(400, 0, 0, -1, func_80102B58_1704E8_LightsOut);
}

void func_80102C18_1705A8_LightsOut(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 2120.0f;
        D_80102770_103370[i].x = 333.55f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 57.5f;
        D_801013B0_101FB0[i].z = -105.0f;
    }
}

void func_80102CC4_170654_LightsOut(void) {
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
}

void func_80102CF0_170680_LightsOut(omObjData* obj) {
    GroundWork* gw;

    D_8010CD18_17A6A8_LightsOut[0] = func_8001A2F8_1AEF8(0x250002);
    D_8010D310_17ACA0_LightsOut = SprCreate(1, 0);
    SprAttrReset(D_8010D310_17ACA0_LightsOut, 0, -1);
    SprScaleSet(D_8010D310_17ACA0_LightsOut, 0, 1.0f, 1.0f);
    SprAnimSet(D_8010D310_17ACA0_LightsOut, 0, D_8010CD18_17A6A8_LightsOut[0], 0);
    SprBankSet(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprAttrSet(D_8010D310_17ACA0_LightsOut, 0, 0x5000);
    SprPosSet(D_8010D310_17ACA0_LightsOut, 0, 160, 120);
    func_8008225C_82E5C(D_8010D310_17ACA0_LightsOut, 0, 0);
    SprPrioSet(D_8010D310_17ACA0_LightsOut, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->func_ptr = func_80102CC4_170654_LightsOut;
}

void func_80102EB8_170848_LightsOut(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_8010D30C_17AC9C_LightsOut = omAddObj(10, 2, 0, -1, func_80102CF0_170680_LightsOut);
}

void func_80102F00_170890_LightsOut(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

/* The hammer's reach: is (x, y, z) inside the blast cylinder of radius `reach`, 30 either way? */
#ifdef NON_MATCHING
/* register allocation (masked 0, raw 24): the abs temporary is v0 in retail, v1 here, and out[0] and
 * reach * reach + 3600 swap $f4/$f6. Tried: a ternary abs (worse, 113 instructions), d assigned before
 * the test (masked 8). Class 4. */
s32 func_80102F9C_17092C_LightsOut(f32 x, f32 y, f32 z, f32 reach) {
    f32 out[3];
    f32 d;
    f32 h;

    func_80102F00_170890_LightsOut(D_8010D16C_17AAFC_LightsOut, x, y, z, out);
    D_8010D140_17AAD0_LightsOut = out[0];
    D_8010D144_17AAD4_LightsOut = out[1];
    D_8010D148_17AAD8_LightsOut = out[2];
    if (reach * reach + 3600.0f < (d = out[0] * out[0] + out[2] * out[2])) {
        return 0;
    }
    if (reach + 30.0f < LO_ABS(out[1])) {
        return 0;
    }
    h = LO_ABS(out[1]) - 30;
    if (h <= 0.0f) {
        return 1;
    }
    h = func_800B1830_B2430(h * h + reach * reach);
    if (h * h + 3600.0f < d) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80102F9C_17092C_LightsOut);
#endif

void func_80103114_170AA4_LightsOut(void) {
    LOSlot* host;
    LOSlot* p;
    omObjData* t;
    omObjData* obj;
    MgWork* work;
    Vec pos;
    Vec rot;
    s32 i;

    if (D_8010D1B4_17AB44_LightsOut != 0) {
        for (i = 0; i < 4; i++) {
            host = &D_8010CD90_17A720_LightsOut[i];
            if (host->unk_74 == 1) {
                break;
            }
        }
        if (i < 4) {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                t = p->obj;
                if (t != NULL && p->unk_74 == 0) {
                    obj = t;
                    work = obj->unk_50;
                    if (obj->work[2] == 0 && func_80102F9C_17092C_LightsOut(obj->trans.x, obj->trans.y + host->unk_30, obj->trans.z, host->unk_30) != 0) {
                        if (host->unk_76 == 2 && work->unk_38 == 1000.0f) {
                            obj->work[2] = 1;
                            pos.x = obj->trans.x;
                            pos.y = obj->trans.y + host->unk_30;
                            pos.z = obj->trans.z;
                            rot.x = -90.0f;
                            rot.y = rot.z = 0.0f;
                            PlaySound(0x1CC);
                            D_8010CCB4_17A644_LightsOut = 1;
                        } else if (host->unk_76 == 1 && work->unk_38 == 1000.0f) {
                            obj->work[2] = 2;
                            pos.x = obj->trans.x;
                            pos.y = obj->trans.y + host->unk_30;
                            pos.z = obj->trans.z;
                            rot.x = rot.z = 0.0f;
                            rot.y = obj->rot.y;
                            PlaySound(0x1CC);
                            D_8010CCB4_17A644_LightsOut = 1;
                        } else {
                            return;
                        }
                        func_800191D4_19DD4(obj, 5, pos.x, pos.y, pos.z, rot.x, rot.y);
                    }
                }
            }
        }
    }
}

/* The darkness: the current I4 texture over the whole screen, drawn from a hook; func_8010B648 edits
   the textures in RAM every frame. */
void func_8010335C_170CEC_LightsOut(Gfx** gfxp) {
    Gfx* gfx;
    s32 y;
    u16 alpha;

    if (D_8010CD04_17A694_LightsOut != 0) {
        alpha = 255;
        if (D_8010CC88_17A618_LightsOut < 256) {
            alpha = D_8010CC88_17A618_LightsOut;
        }
        gfx = *gfxp;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                        G_CULL_BOTH | G_FOG | G_LOD);
        gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        for (y = 0; y < 240; y += 10) {
            gDPLoadTextureTile_4b(gfx++, D_8010CCC8_17A658_LightsOut[D_8010CC80_17A610_LightsOut], G_IM_FMT_I, 320, 240, 0, y, 319,
                                  y + 9, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 320 << 2, 10 << 2);
            gSPTextureRectangle(gfx++, 0 << 2, y << 2, 320 << 2, (y + 10) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        }
        *gfxp = gfx;
    }
}

void func_80103620_170FB0_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x8000;
}

void func_80103648_170FD8_LightsOut(omObjData* obj) {
    ContBtnTrg[((MgWork*)obj->unk_50)->unk_57] |= 0x4000;
}

void func_80103670_171000_LightsOut(omObjData* obj) {
}

f32 func_80103678_171008_LightsOut(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

void func_801037C8_171158_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    f32 angle = work->unk_3C;
    f32 mag;

    if (D_8010CD84_17A714_LightsOut != 3) {
        switch (gPlayers[work->unk_59].cpu_difficulty) {
            case 0:
                mag = (rand8() & 3) * 5 + 50;
                break;
            case 1:
                mag = (u8)(rand8() % 5) * 5 + 45;
                break;
            default:
                mag = (u8)(rand8() % 6) * 5 + 40;
                break;
        }
    } else {
        mag = 70.0f;
    }
    ContStkX[work->unk_57] = mag * HuMathSin(angle);
    ContStkY[work->unk_57] = -mag * func_800B7890_B8490(angle);
}

#ifdef NON_MATCHING
/* register/schedule (masked 3): retail loads 180.0f between the compare and its branch */
void func_80103968_1712F8_LightsOut(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_80103678_171008_LightsOut(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_80103678_171008_LightsOut(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80103968_1712F8_LightsOut);
#endif

void func_80103CA8_171638_LightsOut(omObjData* obj, s16 motion, char* name) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    LOMtxSet* set;
    Matrix4f* dst;
    Matrix4f* src;
    s32 i;
    s32 j;

    func_80029B80_2A780(obj->model[0], obj->motion[motion]);
    set = func_800232FC_23EFC(obj->model[0], 2, name);
    for (i = 0; i < 2; i++) {
        if (p->mtxCount[i] == 0) {
            break;
        }
    }
    if (i < 2) {
        p->mtx[i] = dst = func_80027154_27D54((p->mtxCount[i] = set->count) * 64, 0x7918);
        src = set->mtx;
        for (j = 0; j < p->mtxCount[i]; j++) {
            func_80030CD4_318D4(*dst++, *src++);
        }
    }
    func_80023D74_24974(set);
}

f32 func_80103DFC_17178C_LightsOut(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }

    return a;
}

/* A CPU hammer player: aim at the nearest live player, swing when one is close or the timer runs out. */
void func_80103E74_171804_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 160.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 150) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 5) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 20;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 160.0f) {
                if ((u8)(rand8() % 6) < 5) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 20;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104228_171BB8_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 160.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 150) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 5) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 30;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 160.0f) {
                if ((u8)(rand8() % 6) < 5) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 30;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_801045DC_171F6C_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 140.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 120) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 6) < 3) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 45;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 140.0f) {
                if ((u8)(rand8() % 5) < 3) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 45;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104990_172320_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    f32 best = 1000.0f;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* t;
    omObjData* o;
    s16 i;
    s16 aim;
    s16 human;
    s16 close;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    aim = 5;
    human = 5;
    close = 5;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            if (out.x < best && o->work[2] == 0) {
                best = out.x;
                if (best < 140.0f) {
                    close = i;
                }
                if (p->unk_80 == 0) {
                    human = i;
                }
                aim = i;
            }
        }
        if (human != 5) {
            aim = human;
        }
        if (close != 5) {
            aim = close;
        }
        if (D_8010CC9A_17A62A_LightsOut >= 105) {
            D_8010CC9A_17A62A_LightsOut = 0;
            if ((u8)(rand8() % 5) < 2) {
                if (!(work->unk_50 & 6)) {
                    func_80103648_170FD8_LightsOut(obj);
                }
            } else if (!(work->unk_50 & 6)) {
                func_80103620_170FB0_LightsOut(obj);
            }
            if (!(work->unk_50 & 6)) {
                slot->unk_8A = 53;
            }
        } else if (aim != 5) {
            p = &D_8010CD90_17A720_LightsOut[aim];
            o = p->obj;
            tgt.x = o->trans.x;
            tgt.y = 0.0f;
            tgt.z = o->trans.z;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z);
            if (out.x < 120.0f) {
                if ((u8)(rand8() % 5) < 2) {
                    if (!(work->unk_50 & 6)) {
                        func_80103648_170FD8_LightsOut(obj);
                    }
                } else if (!(work->unk_50 & 6)) {
                    func_80103620_170FB0_LightsOut(obj);
                }
                if (!(work->unk_50 & 6)) {
                    slot->unk_8A = 53;
                }
                D_8010CC9A_17A62A_LightsOut = 0;
            }
        }
        D_8010CC9A_17A62A_LightsOut++;
    }
}

void func_80104D48_1726D8_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;

    LO_PAD_CLEAR(obj);
    if (slot->unk_8A <= 0) {
        switch (gPlayers[work->unk_59].cpu_difficulty) {
            case 0:
                func_80104990_172320_LightsOut(slot);
                break;
            case 1:
                func_801045DC_171F6C_LightsOut(slot);
                break;
            case 2:
                func_80104228_171BB8_LightsOut(slot);
                break;
            default:
                func_80103E74_171804_LightsOut(slot);
                break;
        }
        func_801037C8_171158_LightsOut(slot->obj);
    }
    slot->unk_8A--;
}

/* Loser and winner idles of the hammer player. */
void func_80104EEC_17287C_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    f32 d;
    f32 x;
    f32 z;
    f32 a;

    if (D_8010CD84_17A714_LightsOut == 4 && p->unk_8C == 0.0f) {
        func_80019B9C_1A79C(obj, 0xE);
        p->unk_8C = 1.0f;
    }
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    func_80007790_8390(obj);
    x = obj->trans.x;
    d = x * x;
    z = obj->trans.z;
    d += z * z;
    if (d > 211600.0) {
        a = func_80103DFC_17178C_LightsOut(x, z);
        obj->trans.x = HuMathSin(a) * 460.0;
        obj->trans.z = func_800B7890_B8490(a) * 460.0;
    }
}

void func_801050E8_172A78_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    f32 d;
    f32 x;
    f32 z;
    f32 a;

    if (D_8010CD84_17A714_LightsOut == 4 && p->unk_8C == 0.0f) {
        func_80019B9C_1A79C(obj, 0xD);
        func_800732B0_73EB0(D_8010C250_179BE0_LightsOut[gPlayers[obj->work[0]].character] | D_8010C268_179BF8_LightsOut[D_8010CCB9_17A649_LightsOut[obj->work[0]][0]]);
        p->unk_8C = 1.0f;
    }
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    func_80007790_8390(obj);
    x = obj->trans.x;
    d = x * x;
    z = obj->trans.z;
    d += z * z;
    if (d > 211600.0) {
        a = func_80103DFC_17178C_LightsOut(x, z);
        obj->trans.x = HuMathSin(a) * 460.0;
        obj->trans.z = func_800B7890_B8490(a) * 460.0;
    }
}

/* The intro: two practice swings, the music, then the state moves on. */
void func_80105340_172CD0_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    if (p->unk_8A == 0 && obj->work[1] == 0) {
        func_80103620_170FB0_LightsOut(obj);
        p->unk_8A = 1;
    } else if (p->unk_8A == 1 && obj->work[1] == 0) {
        func_80103620_170FB0_LightsOut(obj);
        p->unk_8A = 2;
        PlayMusic(0x1E);
    } else if (p->unk_8A == 2 && obj->work[1] == 0) {
        func_80103648_170FD8_LightsOut(obj);
        p->unk_8A = 3;
    } else if (p->unk_8A == 3 && obj->work[1] == 0) {
        D_8010CD84_17A714_LightsOut = 1;
        p->unk_8A = 0;
    }
}

void func_80105438_172DC8_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    MgWork* work = obj->unk_50;
    omObjData* wave = D_8010CD90_17A720_LightsOut[6].obj;
    LOSlot* q;
    s16 i;
    s16 count;
    f32 x;

    if (D_8010C270_179C00_LightsOut == 0) {
        func_8000D900_E500(obj, wave);
        D_8010C270_179C00_LightsOut = 1;
    }
    switch (D_8010CD84_17A714_LightsOut) {
        case 0:
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            func_80105340_172CD0_LightsOut(obj);
            break;
        case 1:
        case 5:
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            break;
        case 2:
            if (obj->work[3] == 0) {
                work->unk_3C = obj->rot.y;
                obj->rot.y = 0.0f;
                obj->work[3] = 1;
            }
            if (p->unk_80 == 1) {
                func_80104D48_1726D8_LightsOut(p);
            }
            break;
        case 3:
            func_8002C570_2D170(obj->model[0]);
            func_800298A4_2A4A4(wave->model[0], 0x4000, 0);
            func_80019B9C_1A79C(obj, 0);
            work->unk_50 &= 0xFEAF;
            obj->work[1] = 0;
            p->unk_8C = 0.0f;
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            work->unk_3C = 0.0f;
            count = 0;
            for (i = 0; i < 4; i++) {
                q = &D_8010CD90_17A720_LightsOut[i];
                if (q->obj->work[2] != 0 && q->unk_74 == 0) {
                    count++;
                }
            }
            if (_CheckFlag(0xC) == 0) {
                if (count >= 3) {
                    obj->func_ptr = func_801050E8_172A78_LightsOut;
                } else {
                    obj->func_ptr = func_80104EEC_17287C_LightsOut;
                }
            }
            break;
    }
    p->unk_78++;
    if (!(func_80019000_19C00(obj) & 0xC0000)) {
        p->unk_76 = 0;
        p->unk_78 = 0;
        obj->work[1] = 0;
    }
    if (obj->work[1] != 0 && p->unk_76 == 2 && D_8010CC98_17A628_LightsOut == 1) {
        if (D_8010CCB4_17A644_LightsOut == 0) {
            PlaySound(0x1CB);
        }
        x = HuMathSin(work->unk_3C) * 70.0f + obj->trans.x;
        func_800191D4_19DD4(obj, 5, x, 0.0f, func_800B7890_B8490(work->unk_3C) * 70.0f + obj->trans.z, 0.0f, 0.0f);
    }
    if (ContStkX[gPlayers[obj->work[0]].port] >= 50) {
        ContStkX[gPlayers[obj->work[0]].port] = 50;
    }
    if (ContStkY[gPlayers[obj->work[0]].port] >= 50) {
        ContStkY[gPlayers[obj->work[0]].port] = 50;
    }
    if (ContStkX[gPlayers[obj->work[0]].port] < -49) {
        ContStkX[gPlayers[obj->work[0]].port] = -50;
    }
    if (ContStkY[gPlayers[obj->work[0]].port] < -49) {
        ContStkY[gPlayers[obj->work[0]].port] = -50;
    }
    func_80007790_8390(obj);
    LO_KEEP_IN(obj);
}

s32 func_80105AF8_173488_LightsOut(void) {
    return 1;
}

s32 func_80105B00_173490_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    p->unk_76 = 2;
    p->unk_78 = 0;
    obj->work[1] = 1;
    work->unk_40 = D_800BF7D0_C03D0;
    func_80079798_7A398(0x1CD, obj->work[0]);
    D_8010CCB4_17A644_LightsOut = 0;
    return 0;
}

s32 func_80105B78_173508_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];

    p->unk_76 = 1;
    p->unk_78 = 0;
    obj->work[1] = 1;
    work->unk_40 = D_800BF7D0_C03D0;
    func_80079798_7A398(0x1CD, obj->work[0]);
    D_8010CCB4_17A644_LightsOut = 0;
    return 0;
}

s32 func_80105BF0_173580_LightsOut(omObjData* obj) {
    func_8002C570_2D170(obj->model[0]);
    return 1;
}

__asm__(".section .rodata");
const char D_8010CAF8_17A488_LightsOut[16] = "item_hook";

void func_80105C14_1735A4_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    s32 dir;
    s32 file;
    MgWork* work;
    u16 c = gPlayers[obj->work[0]].character;
    u8 r;

    if (gPlayers[obj->work[0]].flags & 1) {
        p->unk_80 = 1;
    } else {
        p->unk_80 = 0;
    }
    dir = D_800CD438_CE038[c].unk_04;
    file = D_800CD438_CE038[c].unk_08;
    func_8000C460_D060();
    func_8000C6FC_D2FC(obj, dir, file, obj->work[0], 0x699, 0x689);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    work = obj->unk_50;
    work->unk_EC = NULL;
    func_800298A4_2A4A4(obj->model[1], 0x60, 0x20);
    func_800298A4_2A4A4(obj->model[1], 0x180, 0);
    obj->model[3] = LoadFormFile(7, 0x2BD);
    obj->model[4] = LoadFormFile(8, 0x2BD);
    obj->model[6] = LoadFormFile(9, 0x2BD);
    obj->model[5] = LoadFormFile(10, 0x2BD);
    obj->model[7] = LoadFormFile(12, 0x2BD);
    obj->model[8] = LoadFormFile(11, 0x2BD);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 0, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    if ((rand8() & 3) < 3) {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4E, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 0;
    } else {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 1;
    }
    if ((rand8() & 3) < 3) {
        func_80019E84_1AA84(obj, 0xE, dir | 0x55, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][1] = 2;
    } else {
        func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][1] = 3;
    }
    func_80019E84_1AA84(obj, 0x23, dir | 0x1A, 0, 0);
    func_80019E84_1AA84(obj, 0x24, dir | 0x1B, 0, 0);
    func_80019E84_1AA84(obj, 0x16, dir | 0x19, 1, 0);
    r = rand8() & 3;
    D_8010CD00_17A690_LightsOut[r] = 1;
    obj->trans.x = D_8010C230_179BC0_LightsOut[r].x;
    obj->trans.y = D_8010C230_179BC0_LightsOut[r].y;
    obj->trans.z = D_8010C230_179BC0_LightsOut[r].z;
    obj->rot.y = D_8010C230_179BC0_LightsOut[r].rotY;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8000C024_CC24(obj, 0, 2);
    func_80103CA8_171638_LightsOut(obj, 0x24, (char*)D_8010CAF8_17A488_LightsOut);
    func_80103CA8_171638_LightsOut(obj, 0x23, (char*)D_8010CAF8_17A488_LightsOut);
    func_80019B9C_1A79C(obj, 0);
    D_800F8FD0_F9BD0 = 1;
    obj->work[1] = 0;
    p->unk_74 = 1;
    p->unk_76 = 0;
    p->unk_78 = 0;
    p->unk_30 = 60.0f;
    D_8010CC9A_17A62A_LightsOut = 0;
    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    func_80029EDC_2AADC(obj->model[4], 1);
    func_80029EDC_2AADC(obj->model[6], 1);
    func_80029EDC_2AADC(obj->model[5], 2);
    func_80029EDC_2AADC(obj->model[7], 1);
    func_80029EDC_2AADC(obj->model[8], 1);
    obj->func_ptr = func_80105438_172DC8_LightsOut;
    func_8000E0C0_ECC0(work, 0x13, func_80105AF8_173488_LightsOut);
    func_8000E0C0_ECC0(work, 0xA, func_80105B00_173490_LightsOut);
    func_8000E0C0_ECC0(work, 0xB, func_80105B78_173508_LightsOut);
    func_8000E0C0_ECC0(work, 0xC, func_80105BF0_173580_LightsOut);
    func_8000E0C0_ECC0(work, 0xD, func_80105BF0_173580_LightsOut);
}

/* The hammer player is the one of group 0. */
void func_801062A8_173C38_LightsOut(void) {
    LOSlot* p;
    omObjData* obj;
    s16 i;
    s16 player;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
        case 0:
            player = 0;
            break;
        case 1:
            player = 1;
            break;
        case 2:
            player = 2;
            break;
        case 3:
            player = 3;
            break;
        default:
            player = 0;
            break;
    }
    p = &D_8010CD90_17A720_LightsOut[i];
    obj = omAddObj(100, 9, 60, -1, func_80105C14_1735A4_LightsOut);
    p->unk_82 = player;
    D_8010CD86_17A716_LightsOut = obj->work[0] = player;
    p->obj = obj;
    D_800FFFD8_100BD8[D_800FC87A_FD47A] = obj;
    D_800FC87A_FD47A++;
}

/* A CPU runner: it wanders, turns away from the hammer player, other players and the wall. */
#ifdef NON_MATCHING
/* register/schedule (masked 2): one andi placement in the fused test (retail masks r - 1, this masks r
 * first). Tried: (u8) casts without r2, a u8 r2, a logical or (worse). Class 4. */
void func_801063E8_173D78_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* host;
    omObjData* o;
    s16 i;
    s32 r;
    s32 r2;
    u16 t;
    f32 f;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    host = D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut].obj;
    if (host != NULL) {
        tgt.x = host->trans.x;
        tgt.y = 0.0f;
        tgt.z = host->trans.z;
        func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
        if (out.x < 200.0f) {
            if (work->unk_38 == 1000.0f) {
                work->unk_3C = LO_WRAP((rand8() & 1) * 24 - 12 + work->unk_3C);
                D_8010CC86_17A616_LightsOut = (rand8() & 1) * 16 - 8;
                slot->unk_7C = 60;
                r = rand8() % 10;
                r2 = r - 1;
                if (((u32)(r2 & 0xFF) < 2) | ((r & 0xFF) == 3)) {
                    func_80103670_171000_LightsOut(obj);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                o = p->obj;
                if (o != NULL && p->unk_74 == 0 && obj->work[0] != o->work[0]) {
                    tgt.x = o->trans.x;
                    tgt.y = 0.0f;
                    tgt.z = o->trans.z;
                    func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
                    if (out.x < 100.0f) {
                        work->unk_3C = LO_WRAP((rand8() & 1) * 24 - 12 + work->unk_3C);
                        D_8010CC86_17A616_LightsOut = (rand8() & 1) * 16 - 8;
                        slot->unk_7C = 60;
                        if ((u8)(rand8() % 5) < 2) {
                            func_80103670_171000_LightsOut(obj);
                        }
                        break;
                    }
                }
            }
        }
        if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 211600.0) {
            tgt.x = 0.0f;
            tgt.y = 0.0f;
            tgt.z = 0.0f;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z - ((rand8() & 1) * 120 - 60));
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        } else if (slot->unk_7C == 0) {
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        }
        if (D_8010CC86_17A616_LightsOut >= 361) {
            D_8010CC86_17A616_LightsOut -= 360;
        } else if (D_8010CC86_17A616_LightsOut < 0) {
            D_8010CC86_17A616_LightsOut += 360;
        }
        if (slot->unk_7C >= 26 && work->unk_38 != 1000.0f) {
            func_80103670_171000_LightsOut(obj);
        }
        if (slot->unk_7C >= 101) {
            slot->unk_7C = 0;
            return;
        }
        t = slot->unk_7C--;
        if (t >= 17 && t < 62) {
            f = D_8010CC86_17A616_LightsOut + work->unk_3C;
            if (f >= 360.0f) {
                f -= 360.0f;
            } else {
                f = D_8010CC86_17A616_LightsOut + work->unk_3C;
                if (f < 0.0f) {
                    f += 360.0f;
                }
            }
            work->unk_3C = f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_801063E8_173D78_LightsOut);
#endif

#ifdef NON_MATCHING
/* register/schedule (masked 2): same as func_801063E8 */
void func_80106BCC_17455C_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* host;
    omObjData* o;
    s16 i;
    s32 r;
    s32 r2;
    u16 t;
    f32 f;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    host = D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut].obj;
    if (host != NULL) {
        tgt.x = host->trans.x;
        tgt.y = 0.0f;
        tgt.z = host->trans.z;
        func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
        if (out.x < 180.0f) {
            if (work->unk_38 == 1000.0f) {
                work->unk_3C = LO_WRAP((rand8() & 1) * 24 - 12 + work->unk_3C);
                D_8010CC86_17A616_LightsOut = (rand8() & 1) * 16 - 8;
                slot->unk_7C = 60;
                r = rand8() % 10;
                r2 = r - 1;
                if (((u32)(r2 & 0xFF) < 2) | ((r & 0xFF) == 3)) {
                    func_80103670_171000_LightsOut(obj);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                o = p->obj;
                if (o != NULL && p->unk_74 == 0 && obj->work[0] != o->work[0]) {
                    tgt.x = o->trans.x;
                    tgt.y = 0.0f;
                    tgt.z = o->trans.z;
                    func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
                    if (out.x < 100.0f) {
                        work->unk_3C = LO_WRAP((rand8() & 1) * 24 - 12 + work->unk_3C);
                        D_8010CC86_17A616_LightsOut = (rand8() & 1) * 16 - 8;
                        slot->unk_7C = 60;
                        if ((u8)(rand8() % 5) < 2) {
                            func_80103670_171000_LightsOut(obj);
                        }
                        break;
                    }
                }
            }
        }
        if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 211600.0) {
            tgt.x = 0.0f;
            tgt.y = 0.0f;
            tgt.z = 0.0f;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z - ((rand8() & 1) * 120 - 60));
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        } else if (slot->unk_7C == 0) {
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        }
        if (D_8010CC86_17A616_LightsOut >= 361) {
            D_8010CC86_17A616_LightsOut -= 360;
        } else if (D_8010CC86_17A616_LightsOut < 0) {
            D_8010CC86_17A616_LightsOut += 360;
        }
        if (slot->unk_7C >= 26 && work->unk_38 != 1000.0f) {
            func_80103670_171000_LightsOut(obj);
        }
        if (slot->unk_7C >= 101) {
            slot->unk_7C = 0;
            return;
        }
        t = slot->unk_7C--;
        if (t >= 17 && t < 62) {
            f = D_8010CC86_17A616_LightsOut + work->unk_3C;
            if (f >= 360.0f) {
                f -= 360.0f;
            } else {
                f = D_8010CC86_17A616_LightsOut + work->unk_3C;
                if (f < 0.0f) {
                    f += 360.0f;
                }
            }
            work->unk_3C = f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80106BCC_17455C_LightsOut);
#endif

void func_801073B0_174D40_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* host;
    omObjData* o;
    s16 i;
    s32 r;
    u16 t;
    f32 f;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    host = D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut].obj;
    if (host != NULL) {
        tgt.x = host->trans.x;
        tgt.y = 0.0f;
        tgt.z = host->trans.z;
        func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
        if (out.x < 160.0f) {
            if (work->unk_38 == 1000.0f) {
                work->unk_3C = LO_WRAP((rand8() & 1) * 30 - 15 + work->unk_3C);
                D_8010CC86_17A616_LightsOut = (rand8() & 1) * 12 - 6;
                slot->unk_7C = 60;
                r = rand8() % 10;
                if ((u8)(r - 2) < 2) {
                    func_80103670_171000_LightsOut(obj);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                o = p->obj;
                if (o != NULL && p->unk_74 == 0 && obj->work[0] != o->work[0]) {
                    tgt.x = o->trans.x;
                    tgt.y = 0.0f;
                    tgt.z = o->trans.z;
                    func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
                    if (out.x < 100.0f) {
                        rand8();
                        work->unk_3C = LO_WRAP((rand8() & 1) * 30 - 15 + work->unk_3C);
                        D_8010CC86_17A616_LightsOut = (rand8() & 1) * 12 - 6;
                        slot->unk_7C = 60;
                        if ((u8)(rand8() % 10) < 2) {
                            func_80103670_171000_LightsOut(obj);
                        }
                        break;
                    }
                }
            }
        }
        if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 211600.0) {
            tgt.x = 0.0f;
            tgt.y = 0.0f;
            tgt.z = 0.0f;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z - ((rand8() & 1) * 90 - 45));
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        } else if (slot->unk_7C == 0) {
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        }
        if (D_8010CC86_17A616_LightsOut >= 361) {
            D_8010CC86_17A616_LightsOut -= 360;
        } else if (D_8010CC86_17A616_LightsOut < 0) {
            D_8010CC86_17A616_LightsOut += 360;
        }
        if (slot->unk_7C >= 26 && work->unk_38 != 1000.0f) {
            func_80103670_171000_LightsOut(obj);
        }
        if (slot->unk_7C >= 101) {
            slot->unk_7C = 0;
            return;
        }
        t = slot->unk_7C--;
        if (t >= 17 && t < 62) {
            f = D_8010CC86_17A616_LightsOut + work->unk_3C;
            if (f >= 360.0f) {
                f -= 360.0f;
            } else {
                f = D_8010CC86_17A616_LightsOut + work->unk_3C;
                if (f < 0.0f) {
                    f += 360.0f;
                }
            }
            work->unk_3C = f;
        }
    }
}

#ifdef NON_MATCHING
/* register allocation (masked 2): retail hoists the % 10 multiplier into s4; class 4 */
void func_80107BB4_175544_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;
    Vec pos;
    Vec tgt;
    Vec out;
    LOSlot* p;
    omObjData* host;
    omObjData* o;
    s16 i;
    u8 r;
    u16 t;
    f32 f;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    host = D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut].obj;
    if (host != NULL) {
        tgt.x = host->trans.x;
        tgt.y = 0.0f;
        tgt.z = host->trans.z;
        func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
        if (out.x < 140.0f) {
            if (work->unk_38 == 1000.0f) {
                work->unk_3C = LO_WRAP((rand8() & 1) * 36 - 18 + work->unk_3C);
                D_8010CC86_17A616_LightsOut = (rand8() & 1) * 12 - 6;
                slot->unk_7C = 60;
                r = rand8() % 10;
                if (r == 2) {
                    func_80103670_171000_LightsOut(obj);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                o = p->obj;
                if (o != NULL && p->unk_74 == 0 && obj->work[0] != o->work[0]) {
                    tgt.x = o->trans.x;
                    tgt.y = 0.0f;
                    tgt.z = o->trans.z;
                    func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
                    if (out.x < 100.0f) {
                        rand8();
                        work->unk_3C = LO_WRAP((rand8() & 1) * 36 - 18 + work->unk_3C);
                        D_8010CC86_17A616_LightsOut = (rand8() & 1) * 12 - 6;
                        slot->unk_7C = 60;
                        r = rand8() % 10;
                        if (r == 0) {
                            func_80103670_171000_LightsOut(obj);
                        }
                        break;
                    }
                }
            }
        }
        if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 211600.0) {
            tgt.x = 0.0f;
            tgt.y = 0.0f;
            tgt.z = 0.0f;
            func_80103968_1712F8_LightsOut(&pos, &tgt, &out);
            work->unk_3C = LO_WRAP(out.z - ((rand8() & 1) * 120 - 60));
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        } else if (slot->unk_7C == 0) {
            D_8010CC86_17A616_LightsOut = (rand8() & 1) * 6 - 3;
            slot->unk_7C = 60;
        }
        if (D_8010CC86_17A616_LightsOut >= 361) {
            D_8010CC86_17A616_LightsOut -= 360;
        } else if (D_8010CC86_17A616_LightsOut < 0) {
            D_8010CC86_17A616_LightsOut += 360;
        }
        if (slot->unk_7C >= 26 && work->unk_38 != 1000.0f) {
            func_80103670_171000_LightsOut(obj);
        }
        if (slot->unk_7C >= 101) {
            slot->unk_7C = 0;
            return;
        }
        t = slot->unk_7C--;
        if (t >= 17 && t < 62) {
            f = D_8010CC86_17A616_LightsOut + work->unk_3C;
            if (f >= 360.0f) {
                f -= 360.0f;
            } else {
                f = D_8010CC86_17A616_LightsOut + work->unk_3C;
                if (f < 0.0f) {
                    f += 360.0f;
                }
            }
            work->unk_3C = f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80107BB4_175544_LightsOut);
#endif

void func_801083A4_175D34_LightsOut(LOSlot* slot) {
    omObjData* obj = slot->obj;
    MgWork* work = obj->unk_50;

    LO_PAD_CLEAR(obj);
    switch (gPlayers[work->unk_59].cpu_difficulty) {
        case 0:
            func_80107BB4_175544_LightsOut(slot);
            break;
        case 1:
            func_801073B0_174D40_LightsOut(slot);
            break;
        case 2:
            func_80106BCC_17455C_LightsOut(slot);
            break;
        default:
            func_801063E8_173D78_LightsOut(slot);
            break;
    }
    func_801037C8_171158_LightsOut(slot->obj);
}

/* A runner's game-over state. */
void func_80108530_175EC0_LightsOut(omObjData* obj) {
    MgWork* work = obj->unk_50;

    LO_PAD_CLEAR(obj);
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    if (D_8010CD84_17A714_LightsOut == 4 && work->unk_38 == 1000.0f && obj->work[1] == 0) {
        func_80019B9C_1A79C(obj, 0xD);
        func_800732B0_73EB0(D_8010C250_179BE0_LightsOut[gPlayers[obj->work[0]].character] | D_8010C268_179BF8_LightsOut[D_8010CCB9_17A649_LightsOut[obj->work[0]][0]]);
        obj->work[1] = 1;
    }
    func_80007790_8390(obj);
    LO_KEEP_IN(obj);
}

/* A runner. work[2]: 1 flattened by the hammer, 2 flung by the shock wave. */
void func_8010875C_1760EC_LightsOut(omObjData* obj) {
    LOSlot* p;
    LOSlot* bulb;
    omObjData* bulbObj;
    MgWork* work;
    omObjData* host;
    Vec a;
    Vec b;
    Vec c;
    f32 unused[1]; /* pad: retail's frame is 8 bytes larger */
    LOSlot* q;
    omObjData* t;
    s16* timer;
    f32 d;
    f32 x;
    f32 z;
    f32 ang;
    u8 n;

    ContBtnTrg[gPlayers[obj->work[0]].port] = 0;
    n = obj->work[0];
    p = &D_8010CD90_17A720_LightsOut[n];
    work = obj->unk_50;
    q = &D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut];
    t = q->obj;
    if (t == NULL) {
        return;
    }
    host = t;
    bulb = &D_8010CD90_17A720_LightsOut[n + 30];
    bulbObj = bulb->obj;
    if (D_8010CC90_17A620_LightsOut[n] == 0) {
        func_800298A4_2A4A4(bulbObj->model[0], 0x4000, 0x4000);
        func_8002C628_2D228(bulbObj->model[0], obj->model[0], (char*)D_8010CAF8_17A488_LightsOut);
        func_8002C524_2D124(obj->model[0], D_800FC834_FD434[obj->motion[22]].unk02, 1);
        D_8010CC90_17A620_LightsOut[obj->work[0]] = 1;
    }
    switch (D_8010CD84_17A714_LightsOut) {
        case 0:
        case 1:
        case 5:
            LO_PAD_CLEAR(obj);
            work->unk_40 = 0.0f;
            break;
        case 2:
            if (obj->work[3] == 0) {
                work->unk_3C = obj->rot.y;
                obj->rot.y = 0.0f;
                obj->work[3] = 1;
            }
            if (obj->work[2] == 0 && p->unk_80 == 1) {
                func_801083A4_175D34_LightsOut(p);
            }
            break;
        case 3:
            obj->work[1] = 0;
            LO_PAD_CLEAR(obj);
            if (work->unk_38 == 1000.0f) {
                if (obj->work[2] == 0) {
                    work->unk_40 = 0.0f;
                    work->unk_3C = 0.0f;
                    func_8002C570_2D170(obj->model[0]);
                    func_800298A4_2A4A4(bulbObj->model[0], 0x4000, 0);
                    func_80019B9C_1A79C(obj, 0);
                    if (_CheckFlag(0xC) == 0) {
                        obj->func_ptr = func_80108530_175EC0_LightsOut;
                    }
                }
            } else {
                if (obj->work[2] == 0 && p->unk_8C == 0.0f) {
                    a.x = obj->trans.x;
                    a.y = obj->trans.y;
                    a.z = obj->trans.z;
                    b.x = 0.0f;
                    b.y = 0.0f;
                    b.z = 0.0f;
                    func_80103968_1712F8_LightsOut(&a, &b, &c);
                    work->unk_3C = c.z;
                    p->unk_8C = 1.0f;
                    if (obj->trans.x == 0.0f) {
                        if (obj->trans.z < 0.0f) {
                            work->unk_3C = 0.0f;
                        } else {
                            work->unk_3C = 180.0f;
                        }
                    }
                    if (obj->trans.z == 0.0f) {
                        if (obj->trans.x < 0.0f) {
                            work->unk_3C = 90.0f;
                        } else {
                            work->unk_3C = 270.0f;
                        }
                    }
                }
                func_801037C8_171158_LightsOut(obj);
            }
            break;
    }
    if (obj->work[2] != 0) {
        LO_PAD_CLEAR(obj);
        work->unk_40 = 0.0f;
        if (obj->work[2] == 1) {
            if (p->unk_7A == 0) {
                obj->trans.y = 0.0f;
                work->unk_38 = 1000.0f;
                func_8002C570_2D170(obj->model[0]);
                func_800298A4_2A4A4(bulbObj->model[0], 0x4000, 0);
                *(u8*)&bulbObj->unk_50 = 1;
                func_80019B9C_1A79C(obj, 0);
                bulb->unk_76 = 1;
                obj->scale.x = 1.2f;
                obj->scale.y = 0.1f;
                obj->scale.z = 1.2f;
                work->unk_50 |= 0x400;
                func_800797DC_7A3DC(0x111, obj->work[0]);
                p->unk_7A = 3;
                if (!(gPlayers[obj->work[0]].flags & 1)) {
                    omVibrate(work->unk_59, 30, 0, 30);
                }
            }
        } else if (obj->work[2] == 2) {
            if (p->unk_7A == 0) {
                obj->trans.y = 0.0f;
                work->unk_38 = 1000.0f;
                func_8002C570_2D170(obj->model[0]);
                func_800298A4_2A4A4(bulbObj->model[0], 0x4000, 0);
                *(u8*)&bulbObj->unk_50 = 1;
                func_80019B9C_1A79C(obj, 0x2A);
                bulb->unk_76 = 1;
                func_800797DC_7A3DC(0x111, obj->work[0]);
                p->unk_7A = 1;
                if (!(gPlayers[obj->work[0]].flags & 1)) {
                    omVibrate(work->unk_59, 30, 0, 30);
                }
            }
        }
    }
    if (obj->work[2] == 2 && p->unk_7A == 1) {
        a.x = obj->trans.x;
        a.y = 0.0f;
        a.z = obj->trans.z;
        b.x = D_8010D140_17AAD0_LightsOut;
        b.y = 0.0f;
        b.z = D_8010D148_17AAD8_LightsOut;
        func_80103968_1712F8_LightsOut(&a, &b, &c);
        work->unk_3C = LO_WRAP(c.z + 180.0f);
        if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z - (host->trans.x * host->trans.x + host->trans.z * host->trans.z) < 0.0f) {
            work->unk_3C = c.z;
        } else {
            work->unk_3C = LO_WRAP(c.z + 180.0f);
        }
        p->unk_7A = 2;
        work->unk_40 = 40.0f;
    } else if (p->unk_7A == 2) {
        work->unk_40 = 40.0f;
        obj->rot.y += 60.0f;
        func_800191D4_19DD4(obj, 4, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
        D_8010CC9C_17A62C_LightsOut[obj->work[0]]++;
    }
    timer = D_8010CCA4_17A634_LightsOut;
    if (D_8010CCA4_17A634_LightsOut[obj->work[0]] > 0) {
        LO_PAD_CLEAR(obj);
        if (timer[obj->work[0]] == 30) {
            a.x = obj->trans.x;
            a.y = 0.0f;
            a.z = obj->trans.z;
            b.x = 0.0f;
            b.y = 0.0f;
            b.z = 0.0f;
            func_80103968_1712F8_LightsOut(&a, &b, &c);
            work->unk_3C = c.z;
        }
        D_8010CCA4_17A634_LightsOut[obj->work[0]]--;
    } else {
        D_8010CCA4_17A634_LightsOut[obj->work[0]] = 0;
    }
    if (work->unk_38 != 1000.0f) {
        D_8010CCAC_17A63C_LightsOut[obj->work[0]]++;
    } else {
        D_8010CCAC_17A63C_LightsOut[obj->work[0]] = 0;
    }
    if (D_8010CCAC_17A63C_LightsOut[obj->work[0]] >= 91) {
        D_8010CCA4_17A634_LightsOut[obj->work[0]] = 30;
        work->unk_40 = 18.0f;
    }
    func_80007790_8390(obj);
    if (obj->work[2] != 0) {
        if (obj->work[2] == 1) {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    }
    if (obj->work[2] == 1) {
        obj->scale.x = 1.2f;
        obj->scale.y = 0.1f;
        obj->scale.z = 1.2f;
    }
    x = obj->trans.x;
    d = x * x;
    z = obj->trans.z;
    d += z * z;
    if (d > 211600.0) {
        ang = func_80103DFC_17178C_LightsOut(x, z);
        obj->trans.x = HuMathSin(ang) * 460.0;
        obj->trans.z = func_800B7890_B8490(ang) * 460.0;
        if (obj->work[2] != 0 && p->unk_7A != 3) {
            if (D_8010CC9C_17A62C_LightsOut[obj->work[0]] < 10) {
                work->unk_3C = LO_WRAP(work->unk_3C - 180.0f);
            } else if (obj->work[2] == 2) {
                work->unk_40 = 0.0f;
                p->unk_7A = 3;
            }
        }
    }
}

void func_801094B8_176E48_LightsOut(omObjData* obj) {
    LOSlot* p = &D_8010CD90_17A720_LightsOut[obj->work[0]];
    s32 dir;
    s32 file;
    u16 c = gPlayers[obj->work[0]].character;
    u8 r;

    if (gPlayers[obj->work[0]].flags & 1) {
        p->unk_80 = 1;
    } else {
        p->unk_80 = 0;
    }
    dir = D_800CD438_CE038[c].unk_04;
    file = D_800CD438_CE038[c].unk_08;
    func_8000C460_D060();
    func_8000C6FC_D2FC(obj, dir, file, obj->work[0], 0x699, 0x689);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    ((MgWork*)obj->unk_50)->unk_EC = NULL;
    func_800298A4_2A4A4(obj->model[1], 0x60, 0x20);
    func_800298A4_2A4A4(obj->model[1], 0x180, 0);
    obj->model[3] = LoadFormFile(7, 0x2BD);
    obj->model[4] = LoadFormFile(8, 0x2BD);
    obj->model[6] = LoadFormFile(9, 0x2BD);
    obj->model[5] = LoadFormFile(10, 0x2BD);
    obj->model[7] = LoadFormFile(12, 0x2BD);
    obj->model[8] = LoadFormFile(11, 0x2BD);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 0, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x16, dir | 0x13, 1, 0);
    if ((rand8() & 3) < 3) {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4E, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 0;
    } else {
        func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x8C);
        D_8010CCB9_17A649_LightsOut[obj->work[0]][0] = 1;
    }
    func_80019F0C_1AB0C(obj, 0x29, dir | 7, 1, 0x28);
    func_80019F0C_1AB0C(obj, 0x2A, dir | 0x16, 1, 0);
    do {
        r = rand8() & 3;
    } while (D_8010CD00_17A690_LightsOut[r] != 0);
    D_8010CD00_17A690_LightsOut[r] = 1;
    obj->trans.x = D_8010C230_179BC0_LightsOut[r].x;
    obj->trans.y = D_8010C230_179BC0_LightsOut[r].y;
    obj->trans.z = D_8010C230_179BC0_LightsOut[r].z;
    obj->rot.y = D_8010C230_179BC0_LightsOut[r].rotY;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8000C024_CC24(obj, 0, 2);
    func_80019B9C_1A79C(obj, 0);
    D_800F8FD0_F9BD0 = 1;
    obj->work[2] = 0;
    obj->work[3] = 0;
    p->unk_74 = 0;
    D_8010CC90_17A620_LightsOut[obj->work[0]] = 0;
    D_8010CCA4_17A634_LightsOut[obj->work[0]] = 0;
    D_8010CCAC_17A63C_LightsOut[obj->work[0]] = 0;
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[3], 1);
    func_80029EDC_2AADC(obj->model[4], 1);
    func_80029EDC_2AADC(obj->model[6], 1);
    func_80029EDC_2AADC(obj->model[5], 2);
    func_80029EDC_2AADC(obj->model[7], 1);
    func_80029EDC_2AADC(obj->model[8], 1);
    D_8010CC9C_17A62C_LightsOut[obj->work[0]] = 0;
    obj->func_ptr = func_8010875C_1760EC_LightsOut;
}

void func_801099F0_177380_LightsOut(void) {
    LOSlot* p;
    omObjData* obj;
    s16 i;
    s16 player;

    for (i = 0; i < 4; i++) {
        if (D_8010CD86_17A716_LightsOut != i) {
            p = &D_8010CD90_17A720_LightsOut[i];
            obj = omAddObj(300, 9, 60, -1, func_801094B8_176E48_LightsOut);
            switch (i) {
                case 0:
                    player = 0;
                    break;
                case 1:
                    player = 1;
                    break;
                case 2:
                    player = 2;
                    break;
                case 3:
                    player = 3;
                    break;
                default:
                    player = 0;
                    break;
            }
            p->unk_82 = player;
            obj->work[0] = player;
            p->obj = obj;
            D_800FFFD8_100BD8[D_800FC87A_FD47A] = obj;
            D_800FC87A_FD47A++;
        }
    }
}

/* The shock wave's collision matrix: the inverse of the hammer head's world matrix. */
void func_80109B28_1774B8_LightsOut(omObjData* obj, Matrix4f m) {
    Matrix4f t;
    f32 (*inv)[4];
    MgWork* work = obj->unk_50;

    guMtxIdentF(t);
    func_80025770_26370(t, obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025884_26484(t, obj->rot.x, work->unk_3C, obj->rot.z);
    func_80025830_26430(t, obj->scale.x, obj->scale.y, obj->scale.z);
    guMtxCatF(m, t, t);
    inv = D_8010D16C_17AAFC_LightsOut;
    guMtxIdentF(inv);
    func_80025F00_26B00(t, inv);
    func_800B1F50_B2B50(t, -t[3][0], -t[3][1], -t[3][2]);
    guMtxCatF(t, inv, inv);
    D_8010D1A4_17AB34_LightsOut += -70.0f;
}

/* The shock wave: follows the hammer's swing, timed per character from D_8010C218. */
#ifdef NON_MATCHING
/* register allocation (masked 0): retail keeps the loop's object in a0, one register up from here; class 4 */
void func_80109C30_1775C0_LightsOut(omObjData* obj) {
    omObjData* o;
    LOSlot* p;
    LOSlot* wave = &D_8010CD90_17A720_LightsOut[6];
    omObjData* host;
    u16 i;
    u8 c;

    c = 0;
    switch (D_8010CD84_17A714_LightsOut) {
        case 2:
            for (i = 0; i < 4; i++) {
                p = &D_8010CD90_17A720_LightsOut[i];
                o = p->obj;
                if (p->unk_74 == 1) {
                    c = gPlayers[o->work[0]].character;
                    break;
                }
            }
            if (i < 4) {
                if (p->unk_76 == 0) {
                    wave->unk_76 = 0;
                } else if (wave->unk_76 == 0) {
                    if (p->unk_76 == 1) {
                        wave->unk_84 = D_8010C218_179BA8_LightsOut[(c * 4) | 2];
                        wave->unk_86 = D_8010C219_179BA9_LightsOut[(c * 4) | 2];
                        wave->unk_76 = 1;
                    } else if (p->unk_76 == 2) {
                        wave->unk_84 = D_8010C218_179BA8_LightsOut[c * 4];
                        wave->unk_86 = D_8010C219_179BA9_LightsOut[c * 4];
                        wave->unk_76 = 1;
                    }
                } else {
                    if (wave->unk_84 > 0) {
                        wave->unk_84--;
                    } else if (wave->unk_84 == 0) {
                        wave->unk_7C = 1;
                        wave->unk_84 = -1;
                    }
                    if (wave->unk_86 > 0) {
                        wave->unk_86--;
                        D_8010CC98_17A628_LightsOut = 0;
                        if (wave->unk_86 == 5) {
                            D_8010CC98_17A628_LightsOut = 1;
                        }
                    } else if (wave->unk_86 == 0) {
                        D_8010CC98_17A628_LightsOut = 0;
                        wave->unk_7C = 0;
                        wave->unk_86 = -1;
                    }
                }
                if (wave->unk_7C != 0) {
                    func_80109B28_1774B8_LightsOut(p->obj, p->mtx[p->unk_76 - 1][p->unk_78]);
                }
            }
            break;
        case 3:
            host = D_8010CD90_17A720_LightsOut[D_8010CD86_17A716_LightsOut].obj;
            if (wave->unk_82 == 0) {
                obj->trans.x = host->trans.x;
                obj->trans.y = host->trans.y + 150.0f;
                obj->trans.z = host->trans.z;
                wave->unk_82 = 1;
            } else {
                obj->trans.y += 8.0f;
                obj->rot.x += 60.0f;
            }
            if (obj->trans.y >= 310.0f) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                obj->trans.y = 310.0f;
            } else {
                func_800191D4_19DD4(host, 4, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
                func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
            }
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_80109C30_1775C0_LightsOut);
#endif

void func_80109F58_1778E8_LightsOut(omObjData* obj) {
    LOWaveWork* work;

    obj->unk_50 = func_80027154_27D54(sizeof(ColActorWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(ColActorWork));
    work = obj->unk_50;
    work->unk_44 = 0.1f;
    work->unk_48 = 30.0f;
    work->unk_34 = 50.0f;
    work->unk_3C = 0.0f;
    work->unk_78 = 0;
    work->unk_38 = 1000.0f;
    work->unk_52 = 3;
    work->unk_7C = 0;
    work->unk_4C = 0.5f;
    work->unk_50 = 0x60;
    work->unk_74 = 0.8f;
    obj->model[0] = LoadFormFile(0x10012, 0x299);
    D_8010D1AC_17AB3C_LightsOut = 0;
    D_8010D1AE_17AB3E_LightsOut = 0;
    D_8010D1BC_17AB4C_LightsOut = -1;
    D_8010D1BE_17AB4E_LightsOut = -1;
    D_8010D1B4_17AB44_LightsOut = 0;
    D_8010CCB4_17A644_LightsOut = 0;
    D_8010CC98_17A628_LightsOut = 0;
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_80109C30_1775C0_LightsOut;
}

void func_8010A090_177A20_LightsOut(void) {
    D_8010D138_17AAC8_LightsOut = omAddObj(200, 1, 0, -1, func_80109F58_1778E8_LightsOut);
}

/* A light bulb. work[0] the player; it hangs on his head until he is out, then flies up. */
#ifdef NON_MATCHING
/* register allocation (masked 0, raw 10): the two slot pointers swap s1 and s2 (retail: q s2, t s1);
 * declaration order does not move them. Class 4. */
void func_8010A0CC_177A5C_LightsOut(omObjData* obj) {
    LOSlot* t;
    LOSlot* q = &D_8010DFD8_17B968_LightsOut[obj->work[0]];
    omObjData* o;

    switch (D_8010CD84_17A714_LightsOut) {
        case 2:
            func_800298A4_2A4A4(obj->model[1], 0x4004, 4);
            func_800298A4_2A4A4(obj->model[2], 0x4004, 4);
            if (D_8010CD04_17A694_LightsOut != 0) {
                obj->model[0] = obj->model[1];
            } else {
                obj->model[0] = obj->model[2];
            }
            t = &D_8010CD90_17A720_LightsOut[obj->work[0]];
            if (*(u8*)&obj->unk_50 == 0) {
                func_800298A4_2A4A4(obj->model[0], 0x4004, 0x4000);
                func_8002C628_2D228(obj->model[0], t->obj->model[0], (char*)D_8010CAF8_17A488_LightsOut);
            } else {
                func_800298A4_2A4A4(obj->model[0], 0x4004, 0);
            }
            if (q->unk_76 == 1) {
                o = D_8010CD90_17A720_LightsOut[obj->work[0]].obj;
                if (o != NULL) {
                    if (q->unk_74 == 0) {
                        obj->trans.x = o->trans.x;
                        obj->trans.y = o->trans.y + 150.0f;
                        obj->trans.z = o->trans.z;
                        q->unk_74 = 1;
                    } else if (q->unk_74 == 1) {
                        obj->trans.y += 8.0f;
                        obj->rot.x += 60.0f;
                    }
                    if (obj->trans.y >= 310.0f) {
                        func_800298A4_2A4A4(obj->model[0], 4, 4);
                        obj->trans.y = 310.0f;
                        q->unk_74 = 2;
                    } else {
                        func_800191D4_19DD4(o, 4, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
                        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                        func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
                        func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                        func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                        func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
                    }
                }
            }
            break;
        case 3:
            o = D_8010CD90_17A720_LightsOut[obj->work[0]].obj;
            if (o != NULL) {
                if (q->unk_74 == 0) {
                    obj->trans.x = o->trans.x;
                    obj->trans.y = o->trans.y + 150.0f;
                    obj->trans.z = o->trans.z;
                    q->unk_74 = 1;
                } else {
                    obj->trans.y += 8.0f;
                    obj->rot.x += 60.0f;
                }
                if (obj->trans.y >= 310.0f) {
                    func_800298A4_2A4A4(obj->model[0], 4, 4);
                    obj->trans.y = 310.0f;
                    q->unk_74 = 2;
                } else {
                    func_800191D4_19DD4(o, 4, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
                    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                }
            }
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010A0CC_177A5C_LightsOut);
#endif

void func_8010A4C0_177E50_LightsOut(omObjData* obj) {
    omObjData* o = D_8010DFD8_17B968_LightsOut[obj->work[0]].obj;

    o->model[1] = LoadFormFile(0x250000, 0x689);
    o->model[2] = LoadFormFile(0x250001, 0x689);
    func_800298A4_2A4A4(o->model[1], 4, 4);
    o->model[0] = o->model[2];
    o->trans.x = o->work[0] * 200 - 200;
    o->trans.y = 200.0f;
    o->trans.z = o->work[0] * 200 - 200;
    func_80029EDC_2AADC(o->model[0], 1);
    o->func_ptr = func_8010A0CC_177A5C_LightsOut;
}

void func_8010A5D0_177F60_LightsOut(void) {
    LOSlot* p;
    omObjData* o;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_8010CD86_17A716_LightsOut != i) {
            p = &D_8010DFD8_17B968_LightsOut[i];
            o = omAddObj(400, 4, 0, -1, func_8010A4C0_177E50_LightsOut);
            o->work[0] = i;
            p->obj = o;
        }
    }
}

void func_8010A680_178010_LightsOut(void) {
    if (D_8010CD08_17A698_LightsOut > 0) {
        D_8010CD08_17A698_LightsOut--;
        if (D_8010CD08_17A698_LightsOut == 0) {
            D_8010CD08_17A698_LightsOut = 0;
            D_8010CD84_17A714_LightsOut = 5;
        }
    }
}

void func_8010A6C4_178054_LightsOut(omObjData* obj) {
    u8 chars[4];
    s16 i;
    s16 n;
    LOSlot* p;
    omObjData* o;

    if (_CheckFlag(0xC) != 0) {
        if (D_8010CD08_17A698_LightsOut > 0) {
            D_8010CD08_17A698_LightsOut--;
            if (D_8010CD08_17A698_LightsOut == 165) {
                func_8006D518_6E118();
            }
            if (D_8010CD08_17A698_LightsOut == 120) {
                D_8010CD08_17A698_LightsOut = 0;
                D_8010CD84_17A714_LightsOut = 5;
            }
        }
    } else {
        if (D_8010CD08_17A698_LightsOut > 0) {
            D_8010CD08_17A698_LightsOut--;
            if (D_8010CD08_17A698_LightsOut == 165) {
                func_8006D518_6E118();
            }
        }
        if (func_80069538_6A138() == 0) {
            D_8010CD84_17A714_LightsOut = 4;
            obj->func_ptr = func_8010A680_178010_LightsOut;
            if (D_8010CC84_17A614_LightsOut < 3) {
                PlayMusic(0x52);
                D_8010CD08_17A698_LightsOut = 168;
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (gPlayers[i].group != 0) {
                        p = &D_8010CD90_17A720_LightsOut[i];
                        o = p->obj;
                        if (o != NULL) {
                            chars[n] = gPlayers[o->work[0]].character;
                            n++;
                        }
                    }
                }
                func_800691FC_69DFC(0x15, chars[0], chars[1], chars[2]);
            } else {
                PlayMusic(0x51);
                D_8010CD08_17A698_LightsOut = 120;
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (gPlayers[i].group == 0) {
                        p = &D_8010CD90_17A720_LightsOut[i];
                        if (p->obj != NULL) {
                            chars[n] = gPlayers[p->obj->work[0]].character;
                            break;
                        }
                    }
                }
                func_800691FC_69DFC(6, chars[0]);
            }
        }
    }
}

/* Coins: ten to every runner if the hammer fell short of all three, else ten to the hammer. */
void func_8010A980_178310_LightsOut(void) {
    LOSlot* p;
    omObjData* o;
    s16 i;

    if (D_8010C274_179C04_LightsOut == 1) {
        if (D_8010CD90_17A720_LightsOut[0].obj != NULL) {
            gPlayers[D_8010CD90_17A720_LightsOut[0].obj->work[0]].coins_mg_bonus = 0;
        }
    } else {
        for (i = 0; i < 4; i++) {
            p = &D_8010CD90_17A720_LightsOut[i];
            o = p->obj;
            if (o != NULL) {
                if (p->unk_74 == 1) {
                    if (D_8010CC84_17A614_LightsOut < 3) {
                        gPlayers[o->work[0]].coins_mg_bonus = 0;
                    } else {
                        gPlayers[o->work[0]].coins_mg_bonus = 10;
                    }
                } else if (D_8010CC84_17A614_LightsOut < 3) {
                    gPlayers[o->work[0]].coins_mg_bonus = 10;
                } else {
                    gPlayers[o->work[0]].coins_mg_bonus = 0;
                }
            }
        }
    }
}

/* The game: 30 seconds, or until all three runners are out. */
void func_8010AAAC_17843C_LightsOut(omObjData* obj) {
    LOSlot* p;
    omObjData* o;
    s16 i;

    D_8010CC84_17A614_LightsOut = 0;
    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        o = p->obj;
        if (p->unk_74 == 0 && o->work[2] != 0 && p->unk_7A != 0) {
            D_8010CC84_17A614_LightsOut++;
        }
    }
    if (D_8010CC84_17A614_LightsOut >= 3) {
        D_8010CD84_17A714_LightsOut = 3;
        func_8006D518_6E118();
        func_800691FC_69DFC(3);
        obj->func_ptr = func_8010A6C4_178054_LightsOut;
        D_8010CD08_17A698_LightsOut = 180;
        func_800794A8_7A0A8(0x28);
    } else if (_CheckFlag(0xC) != 0 && D_800FD8AC[0] == 2 && (o = D_8010CD90_17A720_LightsOut[0].obj, D_8010CE04_17A794_LightsOut == 0) && o->work[2] != 0 && D_8010CE0A_17A79A_LightsOut != 0) {
        D_8010CD84_17A714_LightsOut = 3;
        func_8006D518_6E118();
        func_800691FC_69DFC(3);
        obj->func_ptr = func_8010A6C4_178054_LightsOut;
        D_8010CD08_17A698_LightsOut = 180;
        func_800794A8_7A0A8(0x28);
        D_8010C274_179C04_LightsOut = 1;
    } else if (D_8010CD08_17A698_LightsOut > 0) {
        D_8010CD08_17A698_LightsOut--;
        func_8006D4D0_6E0D0((D_8010CD08_17A698_LightsOut + 29) / 30);
        return;
    } else {
        obj->func_ptr = func_8010A6C4_178054_LightsOut;
        D_8010CD84_17A714_LightsOut = 3;
        _CheckFlag(0xC);
        func_800691FC_69DFC(3);
        func_8006D4D0_6E0D0(0);
        D_8010CD08_17A698_LightsOut = 180;
        func_800794A8_7A0A8(0x28);
    }
    func_8010A980_178310_LightsOut();
}

void func_8010ACD0_178660_LightsOut(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    D_8010CD08_17A698_LightsOut = 901;
    obj->func_ptr = func_8010AAAC_17843C_LightsOut;
}

void func_8010AD1C_1786AC_LightsOut(omObjData* obj) {
    if (D_8010CD84_17A714_LightsOut == 1) {
        if (D_8010CD08_17A698_LightsOut == 0) {
            func_800691FC_69DFC(0);
            D_8010CD08_17A698_LightsOut++;
        }
        if (func_80069538_6A138() == 0) {
            D_8010CD84_17A714_LightsOut = 2;
            D_8010CD08_17A698_LightsOut = 0;
            obj->func_ptr = func_8010ACD0_178660_LightsOut;
        }
    }
}

void func_8010ADA4_178734_LightsOut(void) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_8010ADC8_178758_LightsOut(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_8010ADA4_178734_LightsOut;
    }
}

void func_8010AE00_178790_LightsOut(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_8010ADC8_178758_LightsOut;
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
    }
}

/* A player the shock wave has flung stays out while another one stands within 100 of him. */
void func_8010AE58_1787E8_LightsOut(void) {
    LOSlot* p;
    LOSlot* r;
    omObjData* t;
    omObjData* o;
    omObjData* q;
    MgWork* work;
    Vec a;
    Vec b;
    Vec c;
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        if (D_8010CCB5_17A645_LightsOut[i] == 0) {
            p = &D_8010CD90_17A720_LightsOut[i];
            t = p->obj;
            if (t != NULL) {
                o = t;
                work = o->unk_50;
                if (o->work[2] == 1) {
                    D_8010CCB5_17A645_LightsOut[i] = 1;
                } else if (o->work[2] == 2 && p->unk_7A == 3) {
                    a.x = o->trans.x;
                    a.y = 0.0f;
                    a.z = o->trans.z;
                    for (j = 0; j < 4; j++) {
                        if (i != j) {
                            r = &D_8010CD90_17A720_LightsOut[j];
                            q = r->obj;
                            if (q != NULL && q->work[2] == 0) {
                                b.x = q->trans.x;
                                b.y = 0.0f;
                                b.z = q->trans.z;
                                func_80103968_1712F8_LightsOut(&a, &b, &c);
                                if (c.x < 100.0f) {
                                    work->unk_50 |= 0x400;
                                    break;
                                }
                            }
                        }
                    }
                    if (j >= 4) {
                        D_8010CCB5_17A645_LightsOut[i] = 1;
                        work->unk_50 &= 0xFBFF;
                    }
                }
            }
        }
    }
}

void func_8010B04C_1789DC_LightsOut(omObjData* obj) {
    if (D_8010CD84_17A714_LightsOut == 5) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_8010ADC8_178758_LightsOut;
    }
    if (D_8010CD84_17A714_LightsOut == 2 && D_8010CD08_17A698_LightsOut >= 3) {
        func_80103114_170AA4_LightsOut();
    }
    func_8010AE58_1787E8_LightsOut();
}

void func_8010B0CC_178A5C_LightsOut(omObjData* obj) {
    s16 i;

    func_8010C0B0_179A40_LightsOut();
    func_8010C1C8_179B58_LightsOut();
    D_8010CD84_17A714_LightsOut = 0;
    func_80102EB8_170848_LightsOut();
    func_801062A8_173C38_LightsOut();
    func_801099F0_177380_LightsOut();
    func_8010A090_177A20_LightsOut();
    func_8010A5D0_177F60_LightsOut();
    func_80102BDC_17056C_LightsOut();
    func_8010C070_179A00_LightsOut();
    InitFadeIn(0, 16);
    obj->func_ptr = func_8010B04C_1789DC_LightsOut;
    D_8010CD08_17A698_LightsOut = 0;
    omAddObj(50, 0, 0, -1, func_80102C18_1705A8_LightsOut);
    omAddObj(600, 0, 0, -1, func_8010AD1C_1786AC_LightsOut);
    for (i = 0; i < 4; i++) {
        D_8010CCB5_17A645_LightsOut[i] = 0;
    }
}

__asm__(".section .rodata");
const char D_8010CB90_17A520_LightsOut[] = "\202`\202a\202b";

void func_8010B1C8_178B58_LightsOut(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 26.2f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 26.2f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_8010B0CC_178A5C_LightsOut);
    omAddObj(1000, 0, 0, -1, func_8010AE00_178790_LightsOut);
    func_8007273C_7333C((u8*)D_8010CB90_17A520_LightsOut, 0);
    func_8007273C_7333C((u8*)D_8010CB90_17A520_LightsOut, 1);
}

void func_8010B3B8_178D48_LightsOut(s16 cam, f32 x, f32 y, f32 z, f32* out) {
    Mtx mtx;
    HuCamera* c = &D_800C9B80_CA780[cam];
    Mtx* view = &c->mtxs[D_800FFFD6_100BD6].lookAtMtx;
    Mtx* m = &mtx;
    HuCamera* vp;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 d;
    f64 t;

    func_800B1FA0_B2BA0(m, x, y, z);
    guMtxCatL(m, view, m);
    sx = (s32)((((u16*)&mtx)[12] << 16) | ((u16*)&mtx)[28]) >> 16;
    sy = (s32)((((u16*)&mtx)[13] << 16) | ((u16*)&mtx)[29]) >> 16;
    sz = (s32)((((u16*)&mtx)[14] << 16) | ((u16*)&mtx)[30]) >> 16;
    t = func_800B80D0_B8CD0(D_800C9B80_CA780[cam].fov[0] / 2.0);
    d = fabs(sz * t / func_800B7890_B8490(D_800C9B80_CA780[cam].fov[0] / 2.0));
    if (d != 0.0) {
        vp = (HuCamera*)((u8*)c + D_800FFFD6_100BD6 * 16);
        out[0] = (s16)(vp->viewports[0].vp.vscale[0] / 4.0 * sx / d / 1.3333334f) + vp->viewports[0].vp.vtrans[0] / 4.0;
        out[1] = (s16)(vp->viewports[0].vp.vscale[1] / 4.0 * -sy / d) + vp->viewports[0].vp.vtrans[1] / 4.0;
    }
}

/* Each frame: the screen positions of the lights, and the darkness texture redrawn: last frame's
   circles filled back in, this frame's cut with the mask; then the lightning script. */
#ifdef NON_MATCHING
/* branch scheduling (raw 1): the fade-in ternary gives beqzl where retail has beqz with li v0,256 in the
 * delay slot. The alpha = 256; if (< 230) alpha += form instead keeps alpha in v1 (raw 4); a block-local
 * or s32 alpha and an if/else were no better. Class 4. */
void func_8010B648_178FD8_LightsOut(void) {
    s32 offs[4];
    f32 pos[2];
    omObjData* t;
    omObjData* o;
    LOSlot* p;
    s32 half;
    s32 size;
    f32 scaleY;
    f32 scaleX;
    s32 half2;
    s32 size2;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 k;
    s32 row;
    u16 alpha;
    f32 sx;
    f32 sy;

    for (i = 0; i < 4; i++) {
        p = &D_8010CD90_17A720_LightsOut[i];
        t = p->obj;
        if (t != NULL && p->unk_74 == 0) {
            o = t;
            func_8010B3B8_178D48_LightsOut(0, o->trans.x, o->trans.y + 75.0f, o->trans.z, pos);
            D_8010CCE8_17A678_LightsOut[i] = pos[0];
            D_8010CCD8_17A668_LightsOut[i] = sy = pos[1];
            sx = D_8010CCE8_17A678_LightsOut[i];
            if (sx < 0.0f) {
                D_8010CCF8_17A688_LightsOut[i] = 1;
            } else if (sx > 319.0f) {
                D_8010CCF8_17A688_LightsOut[i] = 1;
            } else if (sy < 0.0f) {
                D_8010CCF8_17A688_LightsOut[i] = 1;
            } else if (sy > 239.0f) {
                D_8010CCF8_17A688_LightsOut[i] = 1;
            } else if (o->work[2] == 0) {
                D_8010CCF8_17A688_LightsOut[i] = 0;
            } else {
                D_8010CCF8_17A688_LightsOut[i] = 1;
            }
        } else {
            D_8010CCF8_17A688_LightsOut[i] = -1;
        }
    }
    half = 32;
    size = 64;
    scaleY = 1.0f;
    scaleX = 0.5f;
    half2 = 32;
    size2 = 64;
    if (D_8010CC8E_17A61E_LightsOut == 0) {
        for (i = 0; i < 3; i++) {
            y = 0;
            k = 0;
            for (; y < 240; y++) {
                for (x = 0; x < 320; x += 2) {
                    D_8010CCC8_17A658_LightsOut[i][k] = 0xFF;
                    k++;
                }
            }
            for (y = 0; y < 4; y++) {
                if (D_8010CCF8_17A688_LightsOut[y] != -1) {
                    D_8010CC20_17A5B0_LightsOut[i][y] = D_8010CCE8_17A678_LightsOut[y];
                    D_8010CC50_17A5E0_LightsOut[i][y] = D_8010CCD8_17A668_LightsOut[y];
                }
            }
        }
        D_8010CC8E_17A61E_LightsOut = 1;
    } else {
        for (i = 0; i < 4; i++) {
            if (D_8010CCF8_17A688_LightsOut[i] != -1) {
                offs[i] = (D_8010CC50_17A5E0_LightsOut[D_8010CC80_17A610_LightsOut][i] - half) * 320;
                for (y = 0; y < size; y++) {
                    k = (D_8010CC20_17A5B0_LightsOut[D_8010CC80_17A610_LightsOut][i] - half + offs[i]) * 0.5;
                    for (x = 0; x < size; x += 2) {
                        if ((u32)k <= 0x95FF) {
                            D_8010CCC8_17A658_LightsOut[D_8010CC80_17A610_LightsOut][k] = 0xFF;
                        }
                        k++;
                    }
                    offs[i] += 320;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_8010CCF8_17A688_LightsOut[i] == 0) {
            offs[i] = (D_8010CCD8_17A668_LightsOut[i] - half2) * 320.0f;
            for (y = 0; y < size2; y++) {
                row = (s32)(y * scaleY) * half;
                k = (offs[i] + (D_8010CCE8_17A678_LightsOut[i] - half2)) * 0.5;
                for (x = 0; x < size2; x += 2) {
                    j = row + x * scaleX;
                    if ((u32)k <= 0x95FF) {
                        D_8010CCC8_17A658_LightsOut[D_8010CC80_17A610_LightsOut][k] &= D_8010C278_179C08_LightsOut[j];
                    }
                    k++;
                }
                offs[i] += 320;
            }
        }
        if (D_8010CCF8_17A688_LightsOut[i] != -1) {
            D_8010CC20_17A5B0_LightsOut[D_8010CC80_17A610_LightsOut][i] = D_8010CCE8_17A678_LightsOut[i];
            D_8010CC50_17A5E0_LightsOut[D_8010CC80_17A610_LightsOut][i] = D_8010CCD8_17A668_LightsOut[i];
        }
    }
    if (D_8010C200_179B90_LightsOut[D_8010CC8C_17A61C_LightsOut] == 0xFF) {
        if (D_8010CC8A_17A61A_LightsOut == 0) {
            D_8010CC88_17A618_LightsOut = 256;
        }
    } else {
        if (D_8010CC8A_17A61A_LightsOut >= D_8010C200_179B90_LightsOut[D_8010CC8C_17A61C_LightsOut]) {
            D_8010CC8C_17A61C_LightsOut += 2;
            D_8010CC8A_17A61A_LightsOut = 0;
        }
        if (D_8010C201_179B91_LightsOut[D_8010CC8C_17A61C_LightsOut] == 0) {
            if (D_8010CC8A_17A61A_LightsOut == 0 && D_8010CC8C_17A61C_LightsOut != 0) {
                D_8010CC88_17A618_LightsOut = 256;
                PlaySound(0x1CF);
            }
            if (D_8010CC88_17A618_LightsOut < 21) {
                D_8010CD04_17A694_LightsOut = 0;
            } else {
                D_8010CD04_17A694_LightsOut = 1;
                alpha = D_8010CC88_17A618_LightsOut - 20;
                D_8010CC88_17A618_LightsOut = alpha;
            }
        } else {
            D_8010CD04_17A694_LightsOut = 1;
            if (D_8010CC8A_17A61A_LightsOut == 0) {
                D_8010CC88_17A618_LightsOut = 0;
                PlaySound(0x1CE);
            } else {
                switch (D_8010C200_179B90_LightsOut[D_8010CC8C_17A61C_LightsOut] - D_8010CC8A_17A61A_LightsOut) {
                    case 1:
                    case 2:
                    case 3:
                    case 7:
                    case 8:
                    case 9:
                    case 13:
                    case 14:
                    case 15:
                        D_8010CC88_17A618_LightsOut = 125;
                        break;
                    default:
                        D_8010CC88_17A618_LightsOut = 256;
                        break;
                }
            }
            D_8010CC88_17A618_LightsOut = (D_8010CC88_17A618_LightsOut < 230) ? D_8010CC88_17A618_LightsOut + 20 : 256;
        }
        D_8010CC8A_17A61A_LightsOut++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_LightsOut/170190", func_8010B648_178FD8_LightsOut);
#endif

void func_8010BDE8_179778_LightsOut(void) {
    switch (D_8010CD84_17A714_LightsOut) {
        case 2:
            D_8010CC80_17A610_LightsOut = (D_8010CC80_17A610_LightsOut + 1) % 3;
            func_8010B648_178FD8_LightsOut();
            break;
        case 3:
            if (D_8010CC88_17A618_LightsOut < 21) {
                D_8010CD04_17A694_LightsOut = 0;
            } else {
                D_8010CD04_17A694_LightsOut = 1;
                D_8010CC88_17A618_LightsOut -= 20;
            }
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            break;
    }
}

void func_8010BEA4_179834_LightsOut(omObjData* obj) {
    s32 i;
    s32 mdl;

    for (i = 0; i < 3; i++) {
        D_8010CCC8_17A658_LightsOut[i] = func_80027154_27D54(0x9600, 0x7918);
    }
    D_8010CD18_17A6A8_LightsOut[2] = func_8001A2F8_1AEF8(0x10018);
    D_8010D1D8_17AB68_LightsOut = SprCreate(1, 0);
    SprAttrReset(D_8010D1D8_17AB68_LightsOut, 0, 0x8000);
    SprScaleSet(D_8010D1D8_17AB68_LightsOut, 0, 1.0f, 1.0f);
    SprAnimSet(D_8010D1D8_17AB68_LightsOut, 0, D_8010CD18_17A6A8_LightsOut[2], 0);
    SprBankSet(D_8010D1D8_17AB68_LightsOut, 0, 0);
    SprAttrSet(D_8010D1D8_17AB68_LightsOut, 0, 0x180C);
    D_8010D1DC_17AB6C_LightsOut = 160.0f;
    D_8010D1E0_17AB70_LightsOut = 120.0f;
    SprPosSet(D_8010D1D8_17AB68_LightsOut, 0, 160, 120);
    func_8008225C_82E5C(D_8010D1D8_17AB68_LightsOut, 0, 0);
    SprPrioSet(D_8010D1D8_17AB68_LightsOut, 0, 0xFFF0);
    func_80082488_83088(D_8010D1D8_17AB68_LightsOut, 0, 0);
    D_8010CC8A_17A61A_LightsOut = 0;
    D_8010CC8C_17A61C_LightsOut = 0;
    D_8010CD04_17A694_LightsOut = 0;
    D_8010CC8E_17A61E_LightsOut = 0;
    obj->func_ptr = func_8010BDE8_179778_LightsOut;
    mdl = func_8002838C_28F8C(0, func_8010335C_170CEC_LightsOut, 2);
    func_80029EDC_2AADC((s16)mdl, 1);
    D_8010CD10_17A6A0_LightsOut = mdl;
}

void func_8010C070_179A00_LightsOut(void) {
    D_8010D1D4_17AB64_LightsOut = omAddObj(500, 0, 0, -1, func_8010BEA4_179834_LightsOut);
}
