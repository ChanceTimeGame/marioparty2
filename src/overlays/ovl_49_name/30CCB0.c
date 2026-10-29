#include "common.h"
#include "ovl_49.h"

/* .data (0x31D0D0-0x31EC60): in address order (mp2boarddata.py with data.over; 3E's twin). Decision-tree nodes keep a child
   list in node_data2 as (DtData)pointer. Labels inside objects that C or asm name are undefined_syms.txt
   aliases (the signpost model ids at +1, the steal messages at -0xE, as on 3E and 41). */
s16 D_80112C20_31D0D0_name_49[8] = {
    1, 2, 3, 5, 0, 4, 6, 0,
};
s16 D_80112C30_31D0E0_name_49[8] = {
    0, 0, 0, 0, 1, 1, 1, 0,
};
s16 D_80112C40_31D0F0_name_49[4] = {
    1, 2, -1, 0,
};
s16 D_80112C48_31D0F8_name_49[8] = {
    70, 71, 72, 73, 74, 75, 76, 0,
};
s16 D_80112C58_31D108_name_49[8] = {
    76, 36, 18, 71, 91, 48, 25, 0,
};
s16 D_80112C68_31D118_name_49[8] = {
    98, 109, 120, 122, 123, 124, 125, 0,
};
s32 D_80112C78_31D128_name_49 = 0;
u8 D_80112C7C_31D12C_name_49[3][4] = {
    { 60, 70, 80, 85 }, { 70, 80, 90, 95 }, { 80, 90, 95, 95 },
};
s16 D_80112C88_31D138_name_49[10] = {
    75, 76, 80, 57, 52, 53, 54, 56, -1, 0,
};
s16 D_80112C9C_31D14C_name_49[8] = {
    76, 36, 18, 71, 91, 48, 25, -1,
};
s16 D_80112CAC_31D15C_name_49[7][2] = {
    { 0, -2 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 4, -4 },
    { 2, 0 },
};
s16 D_80112CC8_31D178_name_49[2][2] = {
    { 0, 0 }, { 0, -2 },
};
s16 D_80112CD0_31D180_name_49[2] = {
    0, 2,
};
s16 D_80112CD4_31D184_name_49[2][2] = {
    { 0, 0 }, { 0, 0 },
};
s16 D_80112CDC_31D18C_name_49[3][2] = {
    { 0, -2 }, { 0, 0 }, { 0, 6 },
};
s16 D_80112CE8_31D198_name_49[1][2] = {
    { 0, -2 },
};
s16 D_80112CEC_31D19C_name_49[2][2] = {
    { 148, 74 }, { 132, 51 },
};
s16 D_80112CF4_31D1A4_name_49[8] = {
    98, 109, 120, 122, 123, 124, 125, 0,
};
s16 D_80112D04_31D1B4_name_49[8] = {
    70, 71, 72, 73, 74, 75, 76, 0,
};
s32 D_80112D14_31D1C4_name_49 = -1;
s16 D_80112D18_31D1C8_name_49[2] = {
    117, 116,
};
s16 D_80112D1C_31D1CC_name_49[2] = {
    118, 121,
};
s16 D_80112D20_31D1D0_name_49[2] = {
    119, 0,
};
Vec D_80112D24_31D1D4_name_49[5] = {
    { 0.0f, 0.0f, 0.0f }, { -3.0f, 2.0f, -2.0f }, { 1.0f, 5.5f, -3.0f },
    { 3.5f, 8.0f, 4.0f }, { -1.0f, 12.0f, 11.0f },
};
Vec D_80112D60_31D210_name_49[5] = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -15.0f, 0.0f, 0.0f },
    { 20.0f, 0.0f, -30.0f }, { 45.0f, 0.0f, 45.0f },
};
s16 D_80112D9C_31D24C_name_49[2] = {
    113, 114,
};
u8 D_80112DA0_31D250_name_49[6][2] = {
    { 0, 115 }, { 0, 124 }, { 0, 128 }, { 0, 129 }, { 0, 130 }, { 0, 131 },
};
s32 D_80112DAC_31D25C_name_49[9] = {
    923, 944, 975, 970, 1008, 1029, -1, -1, -1,
};
s32 D_80112DD0_31D280_name_49[9] = {
    -1, -1, -1, -1, 1009, -1, -1, -1, -1,
};
s32 D_80112DF4_31D2A4_name_49[9] = {
    -1, -1, -1, -1, 40, -1, -1, -1, -1,
};
s32 D_80112E18_31D2C8_name_49[9] = {
    924, -1, 976, -1, -1, -1, -1, -1, -1,
};
s16 D_80112E3C_31D2EC_name_49 = 100; /* +2 pad */
s16 D_80112E40_31D2F0_name_49[3] = {
    126, 127, 99,
}; /* +2 pad */
s16 D_80112E48_31D2F8_name_49[1] = {
    101,
}; /* +2 pad */
s16 D_80112E4C_31D2FC_name_49[3] = {
    130, 150, 152,
}; /* +2 pad */
f32 D_80112E54_31D304_name_49[3][3] = {
    { 180.0f, 91.0f, -91.0f }, { 180.0f, -90.0f, 0.0f },
    { 180.0f, 90.0f, 0.0f },
};
DecisionTreeNonLeafNode D_80112E78_31D328_name_49[2] = {
    { 0x0A000000, { (void*)0x7 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80112E90_31D340_name_49[4] = {
    { 0x0A000000, { (void*)0xA }, { 0x3232 } },
    { 0x04000000, { (void*)0x200000 }, { 0x15A3C } },
    { 0x0A000000, { (void*)0x7 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80112EC0_31D370_name_49[5] = {
    { 0x04000000, { (void*)0x100000 }, { (DtData)D_80112E78_31D328_name_49 } },
    { 0x04000000, { (void*)0x100001 }, { (DtData)D_80112E90_31D340_name_49 } },
    { 0x0A000000, { (void*)0x7 }, { 0x3232 } },
    { 0x04000000, { (void*)0x300001 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80112EFC_31D3AC_name_49[4] = {
    { 0x02000000, { (void*)0x1 }, { 0x6446 } },
    { 0x04000000, { (void*)0x1 }, { (DtData)D_80112EC0_31D370_name_49 } },
    { 0x04000000, { (void*)0x2 }, { (DtData)D_80112EC0_31D370_name_49 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80112F2C_31D3DC_name_49[3] = {
    { 0x04000000, { (void*)0x10001 }, { 0x6446 } },
    { 0x04000000, { (void*)0x100000 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x6446 } },
};
DecisionTreeNonLeafNode D_80112F50_31D400_name_49[3] = {
    { 0x03000000, { (void*)0x3 }, { (DtData)D_80112F2C_31D3DC_name_49 } },
    { 0x01000000, { (void*)0x14 }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80112F74_31D424_name_49[4] = {
    { 0x04000000, { (void*)0x10001 }, { 0x16446 } },
    { 0x04000000, { (void*)0x110002 }, { 0x16446 } },
    { 0x04000000, { (void*)0x300001 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x16446 } },
};
DecisionTreeNonLeafNode D_80112FA4_31D454_name_49[3] = {
    { 0x03000000, { (void*)0x7 }, { (DtData)D_80112F74_31D424_name_49 } },
    { 0x01000000, { (void*)0x14 }, { 0x16446 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80112FC8_31D478_name_49[4] = {
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80112F50_31D400_name_49 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_80112FA4_31D454_name_49 } },
    { 0x02000000, { (void*)0x38 }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x1503C } },
};
DecisionTreeNonLeafNode D_80112FF8_31D4A8_name_49[2] = {
    { 0x0A000000, { (void*)0x8 }, { 0x16446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80113010_31D4C0_name_49[2] = {
    { 0x0A000000, { (void*)0xB }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x15A3C } },
};
DecisionTreeNonLeafNode D_80113028_31D4D8_name_49[5] = {
    { 0x04000000, { (void*)0x10001 }, { 0x6446 } },
    { 0x04000000, { (void*)0x110001 }, { 0x6446 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_80113010_31D4C0_name_49 } },
    { 0x0A000000, { (void*)0xD }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x15A3C } },
};
DecisionTreeNonLeafNode D_80113064_31D514_name_49[6] = {
    { 0x0F000000, { (void*)0x1D }, { 0x5050 } },
    { 0x04000000, { (void*)0x10001 }, { 0x16446 } },
    { 0x04000000, { (void*)0x110002 }, { 0x16446 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80112FF8_31D4A8_name_49 } },
    { 0x0A000000, { (void*)0xB }, { 0x16446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_801130AC_31D55C_name_49[8] = {
    { 0x02000000, { (void*)0x1E }, { (DtData)D_80113028_31D4D8_name_49 } },
    { 0x08000000, { (void*)0xFFFFFFFF }, { (DtData)D_80113064_31D514_name_49 } },
    { 0x0F000000, { (void*)0x11 }, { 0x5050 } },
    { 0x04000000, { (void*)0x10001 }, { 0x16446 } },
    { 0x04000000, { (void*)0x110002 }, { 0x16446 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80112FF8_31D4A8_name_49 } },
    { 0x0A000000, { (void*)0xB }, { 0x16446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_8011310C_31D5BC_name_49[2] = {
    { 0x03000000, { (void*)0x20 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x4646 } },
};
DecisionTreeNonLeafNode D_80113124_31D5D4_name_49[2] = {
    { 0x03000000, { (void*)0x2A }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x16446 } },
};
DecisionTreeNonLeafNode D_8011313C_31D5EC_name_49[4] = {
    { 0x03000000, { (void*)0x2A }, { 0x15A3C } },
    { 0x09000000, { (void*)0x40 }, { (DtData)D_8011310C_31D5BC_name_49 } },
    { 0x03000000, { (void*)0x40 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_8011316C_31D61C_name_49[6] = {
    { 0x02000000, { (void*)0x40 }, { 0x6446 } },
    { 0x02000000, { (void*)0x6 }, { (DtData)D_80113124_31D5D4_name_49 } },
    { 0x02000000, { (void*)0x28 }, { (DtData)D_8011313C_31D5EC_name_49 } },
    { 0x09000000, { (void*)0x40 }, { (DtData)D_8011310C_31D5BC_name_49 } },
    { 0x03000000, { (void*)0x40 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x4646 } },
};
DecisionTreeNonLeafNode D_801131B4_31D664_name_49[3] = {
    { 0x02000000, { (void*)0x1 }, { 0x6446 } },
    { 0x03000000, { (void*)0x1 }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x14 } },
};
DecisionTreeNonLeafNode D_801131D8_31D688_name_49[2] = {
    { 0x0F000000, { (void*)0x19 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x15A3C } },
};
DecisionTreeNonLeafNode D_801131F0_31D6A0_name_49[2] = {
    { 0x02000000, { (void*)0x40 }, { (DtData)D_801131D8_31D688_name_49 } },
    { 0x00000000, { (void*)0 }, { 0x5032 } },
};
DecisionTreeNonLeafNode D_80113208_31D6B8_name_49[1] = {
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80113214_31D6C4_name_49[2] = {
    { 0x0E000000, { (void*)0x60005 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x4646 } },
};
DecisionTreeNonLeafNode D_8011322C_31D6DC_name_49[4] = {
    { 0x0E000000, { (void*)0x20007 }, { (DtData)D_80113214_31D6C4_name_49 } },
    { 0x0E000000, { (void*)0x30004 }, { (DtData)D_80113214_31D6C4_name_49 } },
    { 0x0E000000, { (void*)0x40006 }, { (DtData)D_80113214_31D6C4_name_49 } },
    { 0x00000000, { (void*)0 }, { 0x14646 } },
};
DecisionTreeNonLeafNode D_8011325C_31D70C_name_49[2] = {
    { 0x0E000000, { (void*)0xC0006 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x14646 } },
};
DecisionTreeNonLeafNode D_80113274_31D724_name_49[3] = {
    { 0x0E000000, { (void*)0x70005 }, { (DtData)D_8011325C_31D70C_name_49 } },
    { 0x0E000000, { (void*)0xC0006 }, { 0x4646 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80113298_31D748_name_49[2] = {
    { 0x0E000000, { (void*)0xD000D }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x14646 } },
};
DecisionTreeNonLeafNode D_801132B0_31D760_name_49[4] = {
    { 0x0E000000, { (void*)0xF000B }, { (DtData)D_80113298_31D748_name_49 } },
    { 0x0E000000, { (void*)0x100000 }, { (DtData)D_80113298_31D748_name_49 } },
    { 0x0E000000, { (void*)0xD000D }, { 0x4646 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_801132E0_31D790_name_49[3] = {
    { 0x0E000000, { (void*)0x90001 }, { 0x3232 } },
    { 0x0E000000, { (void*)0x10007 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x14646 } },
};
DecisionTreeNonLeafNode D_80113304_31D7B4_name_49[4] = {
    { 0x0E000000, { (void*)0xA0006 }, { (DtData)D_801132E0_31D790_name_49 } },
    { 0x0E000000, { (void*)0x90001 }, { 0x4646 } },
    { 0x0E000000, { (void*)0x10007 }, { 0x4646 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
s16 D_80113334_31D7E4_name_49[4] = {
    77, 27, -1, 0,
};
BoardEventListEntry D_8011333C_31D7EC_name_49[2] = {
    { 1, 2, func_80106D94_311244_name_49 },
    { 0, 0, NULL },
};
s16 D_8011334C_31D7FC_name_49[4] = {
    34, 15, -1, 0,
};
BoardEventListEntry D_80113354_31D804_name_49[2] = {
    { 1, 2, func_80106EAC_31135C_name_49 },
    { 0, 0, NULL },
};
s16 D_80113364_31D814_name_49[4] = {
    60, 40, -1, 0,
};
s16 D_8011336C_31D81C_name_49[4] = {
    25, 81, -1, 0,
};
BoardEventListEntry D_80113374_31D824_name_49[2] = {
    { 1, 2, func_801070D4_311584_name_49 },
    { 0, 0, NULL },
};
s16 D_80113384_31D834_name_49[4] = {
    113, 4, -1, 0,
};
DecisionTreeNonLeafNode D_8011338C_31D83C_name_49[3] = {
    { 0x02000000, { (void*)0x1 }, { 0x6464 } },
    { 0x10000000, { (void*)0x1 }, { 0x1414 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_801133B0_31D860_name_49[1] = {
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
BoardEventListEntry D_801133BC_31D86C_name_49[2] = {
    { 1, 2, func_8010744C_3118FC_name_49 },
    { 0, 0, NULL },
};
s16 D_801133CC_31D87C_name_49[4] = {
    114, 50, -1, 0,
};
BoardEventListEntry D_801133D4_31D884_name_49[2] = {
    { 1, 2, func_80107744_311BF4_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_801133E4_31D894_name_49[2] = {
    { 1, 1, func_80107A3C_311EEC_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_801133F4_31D8A4_name_49[2] = {
    { 1, 1, func_80107A60_311F10_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113404_31D8B4_name_49[2] = {
    { 1, 1, func_80107A84_311F34_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113414_31D8C4_name_49[2] = {
    { 1, 1, func_80107AA8_311F58_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113424_31D8D4_name_49[2] = {
    { 1, 1, func_80107ACC_311F7C_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113434_31D8E4_name_49[2] = {
    { 1, 1, func_80107AF0_311FA0_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113444_31D8F4_name_49[2] = {
    { 1, 1, func_80107B14_311FC4_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113454_31D904_name_49[2] = {
    { 1, 1, func_80107B38_311FE8_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113464_31D914_name_49[2] = {
    { 1, 1, func_80107B5C_31200C_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113474_31D924_name_49[2] = {
    { 1, 1, func_80107B80_312030_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113484_31D934_name_49[2] = {
    { 1, 1, func_80107BA4_312054_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113494_31D944_name_49[2] = {
    { 1, 1, func_80107BC8_312078_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_801134A4_31D954_name_49[2] = {
    { 1, 1, func_80107BEC_31209C_name_49 },
    { 0, 0, NULL },
};
u8 D_801134B4_31D964_name_49[4] = {
    2, 5, 15, 20,
};
BoardEventListEntry D_801134B8_31D968_name_49[2] = {
    { 1, 1, func_80107E10_3122C0_name_49 },
    { 0, 0, NULL },
};
s16 D_801134C8_31D978_name_49[3] = {
    126, 127, 99,
}; /* +2 pad */
BoardEventListEntry D_801134D0_31D980_name_49[2] = {
    { 1, 1, func_80108650_312B00_name_49 },
    { 0, 0, NULL },
};
u8 D_801134E0_31D990_name_49[3][4] = {
    { 0, 0, 1, 1 }, { 1, 2, 3, 3 }, { 4, 5, 6, 6 },
};
u8 D_801134EC_31D99C_name_49[4][3] = {
    { 1, 6, 16 }, { 1, 11, 21 }, { 1, 16, 36 }, { 0, 0, 0 },
};
s8 D_801134F8_31D9A8_name_49[7][5] = {
    { 0, 1, -1, -1, -1 }, { 0, 1, 6, -1, -1 }, { 0, 1, 2, 6, -1 },
    { 0, 1, 4, 6, -1 }, { 0, 1, 2, 4, 6 }, { 0, 1, 4, 5, 6 },
    { 0, 1, 5, 6, 9 },
}; /* +1 pad */
u32 D_8011351C_31D9CC_name_49[7] = {
    0x000001F2, 0x000001F3, 0x000001F4, 0x000001F5, 0x000001F6, 0x000001F7,
    0x000001F8,
};
BoardEventListEntry D_80113538_31D9E8_name_49[2] = {
    { 1, 1, func_80108CA8_313158_name_49 },
    { 0, 0, NULL },
};
u8 D_80113548_31D9F8_name_49[4][3] = {
    { 1, 2, 3 }, { 0, 2, 3 }, { 0, 1, 3 }, { 0, 1, 2 },
};
Unk3EVec2f D_80113554_31DA04_name_49[4] = {
    { 76.0f, 52.0f }, { 244.0f, 52.0f }, { 76.0f, 192.0f }, { 244.0f, 192.0f },
};
Unk3EVec2f D_80113574_31DA24_name_49[4] = {
    { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f },
};
s32 D_80113594_31DA44_name_49[6] = {
    134, 135, 136, 137, 138, 139,
};
Unk3ERange D_801135AC_31DA5C_name_49[6] = {
    { 1, 5, 15 }, { 6, 15, 25 }, { 16, 25, 27 }, { 26, 35, 30 }, { 36, 45, 32 },
    { 46, 50, 35 },
}; /* +2 pad */
Unk3ERange D_801135C0_31DA70_name_49[14] = {
    { 0, 0, 0 }, { 1, 10, 1 }, { 11, 11, 4 }, { 12, 20, 2 }, { 21, 21, 4 },
    { 22, 30, 3 }, { 31, 40, 4 }, { 41, 44, 5 }, { 45, 46, 2 }, { 51, 56, 6 },
    { 57, 61, 5 }, { 62, 70, 7 }, { 71, 71, 8 }, { 72, 255, 9 },
}; /* +2 pad */
Unk3EStealRange D_801135EC_31DA9C_name_49[24] = {
    { 1, 5, 6, 9, 7 }, { 1, 5, 10, 12, 8 }, { 1, 5, 13, 14, 9 },
    { 1, 5, 15, 15, 10 }, { 6, 15, 16, 19, 7 }, { 6, 15, 20, 22, 8 },
    { 6, 15, 23, 24, 9 }, { 6, 15, 25, 25, 10 }, { 16, 25, 18, 21, 7 },
    { 16, 25, 22, 24, 8 }, { 16, 25, 25, 26, 9 }, { 16, 25, 27, 27, 10 },
    { 26, 35, 21, 24, 7 }, { 26, 35, 25, 27, 8 }, { 26, 35, 28, 29, 9 },
    { 26, 35, 30, 30, 10 }, { 36, 45, 23, 26, 7 }, { 36, 45, 27, 29, 8 },
    { 36, 45, 30, 31, 9 }, { 36, 45, 32, 32, 10 }, { 46, 50, 26, 29, 7 },
    { 46, 50, 30, 32, 8 }, { 46, 50, 33, 34, 9 }, { 46, 50, 35, 35, 10 },
};
s16 D_80113664_31DB14_name_49[4] = {
    1723, 1724, 1725, 1726,
};
BoardEventListEntry D_8011366C_31DB1C_name_49[2] = {
    { 1, 1, func_8010ABC0_315070_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_8011367C_31DB2C_name_49[2] = {
    { 1, 1, func_8010B5C0_315A70_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_8011368C_31DB3C_name_49[2] = {
    { 1, 1, func_8010B5DC_315A8C_name_49 },
    { 0, 0, NULL },
};
BoardEventTableEntry D_8011369C_31DB4C_name_49[14] = {
    { 76, D_801134B8_31D968_name_49 },
    { 36, D_801134B8_31D968_name_49 },
    { 18, D_801134B8_31D968_name_49 },
    { 71, D_801134B8_31D968_name_49 },
    { 91, D_801134B8_31D968_name_49 },
    { 48, D_801134B8_31D968_name_49 },
    { 25, D_801134B8_31D968_name_49 },
    { 44, D_801134D0_31D980_name_49 },
    { 68, D_801134D0_31D980_name_49 },
    { 49, D_801134D0_31D980_name_49 },
    { 140, D_80113538_31D9E8_name_49 },
    { 113, D_8011367C_31DB2C_name_49 },
    { 114, D_8011368C_31DB3C_name_49 },
    { -1, NULL },
};
BoardEventTableEntry D_8011370C_31DBBC_name_49[3] = {
    { 149, D_8011366C_31DB1C_name_49 },
    { 133, D_8011366C_31DB1C_name_49 },
    { -1, NULL },
};
Vec2f3E D_80113724_31DBD4_name_49[4] = {
    { 108.0f, 41.0f }, { 244.0f, 41.0f }, { 108.0f, 209.0f },
    { 244.0f, 209.0f },
};
Vec2f3E D_80113744_31DBF4_name_49[4] = {
    { 164.0f, 76.0f }, { 140.0f, 76.0f }, { 164.0f, 76.0f },
    { 140.0f, 76.0f },
};
Vec2f3E D_80113764_31DC14_name_49[4] = {
    { 132.0f, 62.0f }, { 220.0f, 62.0f }, { 132.0f, 180.0f },
    { 220.0f, 180.0f },
};
Vec2f3E D_80113784_31DC34_name_49[4] = {
    { 164.0f, 66.0f }, { 140.0f, 66.0f }, { 164.0f, 66.0f },
    { 140.0f, 66.0f },
};
s32 D_801137A4_31DC54_name_49[6] = {
    709, 732, 762, 791, 823, 855,
};
s16 D_801137BC_31DC6C_name_49[6] = {
    26, 27, 36, 30, 35, 37,
};
s16 D_801137C8_31DC78_name_49[8] = {
    104, 105, 106, 107, 108, 112, 111, 110,
};
s16 D_801137D8_31DC88_name_49[5] = {
    0, 5, 65, 57, 46,
}; /* +2 pad */
s32 D_801137E4_31DC94_name_49[8] = {
    0, 1, 1, 0, 1, 0, 0, 0,
};
u8 D_80113804_31DCB4_name_49[2] = {
    140, 141,
}; /* +2 pad */
BoardEventListEntry D_80113808_31DCB8_name_49[2] = {
    { 3, 2, func_8010F320_3197D0_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113818_31DCC8_name_49[2] = {
    { 3, 2, func_8010F340_3197F0_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113828_31DCD8_name_49[2] = {
    { 3, 2, func_8010F360_319810_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113838_31DCE8_name_49[2] = {
    { 3, 2, func_8010F380_319830_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113848_31DCF8_name_49[2] = {
    { 3, 2, func_8010F3A0_319850_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113858_31DD08_name_49[2] = {
    { 3, 2, func_8010F3C0_319870_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113868_31DD18_name_49[2] = {
    { 3, 2, func_8010F3E0_319890_name_49 },
    { 0, 0, NULL },
};
s16 D_80113878_31DD28_name_49[24] = {
    130, 39, 38, 37, 36, 35, 34, 151, 32, 31, 30, 29, 28, 27,
    129, 66, 55, 44, 33, 22, 11, 0, -1, 0,
};
s16 D_801138A8_31DD58_name_49[18] = {
    130, 60, 61, 62, 63, 64, 65, 134, 67, 68, 69, 70, 71, 72,
    73, 150, -1, 0,
};
s16 D_801138CC_31DD7C_name_49[16] = {
    40, 41, 42, 43, 131, 45, 135, 46, 47, 48, 49, 132, 50, 152, -1, 0,
};
s16 D_801138EC_31DD9C_name_49[22] = {
    7, 6, 5, 149, 4, 148, 147, 3, 2, 140, 1, 88, 77, 129, 66, 55, 44, 33, 22, 11, 0, -1,
};
s16 D_80113918_31DDC8_name_49[22] = {
    8, 9, 10, 12, 13, 14, 151, 32, 31, 30, 29, 28, 27, 129, 66, 55, 44, 33, 22, 11, 0, -1,
};
s16 D_80113944_31DDF4_name_49[8] = {
    21, 23, 24, 153, 25, 26, 0, -1,
};
s16 D_80113954_31DE04_name_49[22] = {
    20, 19, 18, 17, 16, 15, 151, 32, 31, 30, 29, 28, 27, 129, 66, 55, 44, 33,
    22, 11, 0, -1,
};
s16 D_80113980_31DE30_name_49[8] = {
    137, 138, 139, 141, 142, 143, -1, 0,
};
s16* D_80113990_31DE40_name_49[5][3] = {
    { D_80113878_31DD28_name_49, D_80113980_31DE30_name_49, NULL },
    { D_801138A8_31DD58_name_49, D_801138EC_31DD9C_name_49, D_80113980_31DE30_name_49 },
    { D_801138A8_31DD58_name_49, D_80113918_31DDC8_name_49, D_80113980_31DE30_name_49 },
    { D_801138CC_31DD7C_name_49, D_80113944_31DDF4_name_49, D_80113980_31DE30_name_49 },
    { D_801138CC_31DD7C_name_49, D_80113954_31DE04_name_49, D_80113980_31DE30_name_49 },
};
u8 D_801139CC_31DE7C_name_49[16] = {
    145, 146, 147, 148, 149, 150, 0, 0, 151, 152, 152, 152, 154, 155,
    0, 0,
};
s32 D_801139DC_31DE8C_name_49[7] = {
    0, 15, 30, 45, 60, 75, 90,
};
s32 D_801139F8_31DEA8_name_49[7] = {
    0, 15, 30, 42, 54, 66, 81,
};
s32 D_80113A14_31DEC4_name_49[4] = {
    3, 0x800B1, 0x800B2, 0x800B3,
};
Vec D_80113A24_31DED4_name_49[5] = {
    { 0.0f, 0.0f, 0.0f }, { 5.0f, 0.0f, 5.0f }, { -5.0f, 0.0f, -5.0f },
    { 10.0f, 0.0f, 10.0f }, { -10.0f, 0.0f, -10.0f },
};
MBModel* D_80113A60_31DF10_name_49 = NULL;
BoardEventListEntry D_80113A64_31DF14_name_49[2] = {
    { 7, 1, func_8011056C_31AA1C_name_49 },
    { 0, 0, NULL },
};
DecisionTreeNonLeafNode D_80113A74_31DF24_name_49[2] = {
    { 0x04000000, { (void*)0x100000 }, { 0x13C3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80113A8C_31DF3C_name_49[4] = {
    { 0x03000000, { (void*)0xE }, { 0x3232 } },
    { 0x0A000000, { (void*)0x7 }, { 0x3232 } },
    { 0x04000000, { (void*)0x200000 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80113ABC_31DF6C_name_49[2] = {
    { 0x04000000, { (void*)0x300001 }, { 0x15A3C } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
s16 D_80113AD4_31DF84_name_49[3] = {
    115, 102, 103,
}; /* +2 pad */
s16 D_80113ADC_31DF8C_name_49[4] = {
    39, 60, 40, -1,
};
BoardEventListEntry D_80113AE4_31DF94_name_49[2] = {
    { 1, 2, func_80111A78_31BF28_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113AF4_31DFA4_name_49[2] = {
    { 1, 2, func_80111A94_31BF44_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113B04_31DFB4_name_49[2] = {
    { 1, 2, func_80111AB0_31BF60_name_49 },
    { 0, 0, NULL },
};
s16 D_80113B14_31DFC4_name_49[4] = {
    10, 89, -1, 0,
};
s16 D_80113B1C_31DFCC_name_49[2] = {
    89, -1,
};
s16* D_80113B20_31DFD0_name_49[3] = {
    D_80113B14_31DFC4_name_49, D_80113B1C_31DFCC_name_49,
    D_80113B14_31DFC4_name_49,
};
BoardEventListEntry D_80113B2C_31DFDC_name_49[2] = {
    { 3, 2, func_80111C64_31C114_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113B3C_31DFEC_name_49[2] = {
    { 3, 2, func_80111C80_31C130_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113B4C_31DFFC_name_49[2] = {
    { 3, 2, func_80111C9C_31C14C_name_49 },
    { 0, 0, NULL },
};
s16 D_80113B5C_31E00C_name_49[4] = {
    93, 94, 63, -1,
};
s16 D_80113B64_31E014_name_49[4] = {
    94, 63, -1, 0,
};
s16 D_80113B6C_31E01C_name_49[2] = {
    63, -1,
};
s16 D_80113B70_31E020_name_49[4] = {
    136, 94, 63, -1,
};
s16 D_80113B78_31E028_name_49[6] = {
    95, 136, 94, 63, -1, 0,
};
s16* D_80113B84_31E034_name_49[5] = {
    D_80113B5C_31E00C_name_49, D_80113B64_31E014_name_49,
    D_80113B6C_31E01C_name_49, D_80113B70_31E020_name_49,
    D_80113B78_31E028_name_49,
};
BoardEventListEntry D_80113B98_31E048_name_49[2] = {
    { 3, 2, func_80111E50_31C300_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113BA8_31E058_name_49[2] = {
    { 3, 2, func_80111E6C_31C31C_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113BB8_31E068_name_49[2] = {
    { 3, 2, func_80111E88_31C338_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113BC8_31E078_name_49[2] = {
    { 3, 2, func_80111EA4_31C354_name_49 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80113BD8_31E088_name_49[2] = {
    { 3, 2, func_80111EC0_31C370_name_49 },
    { 0, 0, NULL },
};
u8 D_80113BE8_31E098_name_49[5] = {
    0, 1, 3, 5, 8,
}; /* +3 pad */
s16 D_80113BF0_31E0A0_name_49[5] = {
    12, 12, 12, 17, 12,
}; /* +2 pad */
s16 D_80113BFC_31E0AC_name_49[5] = {
    40, 65, 70, 90, 100,
}; /* +2 pad */
s32 D_80113C08_31E0B8_name_49[5] = {
    585, 586, 588, 587, 589,
};
u8 D_80113C1C_31E0CC_name_49[4] = {
    6, 1, 9, 7,
};
s16 D_80113C20_31E0D0_name_49[4] = {
    50, 70, 90, 100,
};
s32 D_80113C28_31E0D8_name_49[4] = {
    591, 592, 593, 594,
};
BoardEventListEntry D_80113C38_31E0E8_name_49[2] = {
    { 1, 2, func_80111EDC_31C38C_name_49 },
    { 0, 0, NULL },
};
BoardEventTableEntry D_80113C48_31E0F8_name_49[39] = {
    { 129, D_8011333C_31D7EC_name_49 },
    { 151, D_80113354_31D804_name_49 },
    { 153, D_80113374_31D824_name_49 },
    { 148, D_801133BC_31D86C_name_49 },
    { 132, D_801133D4_31D884_name_49 },
    { 144, D_801133E4_31D894_name_49 },
    { 7, D_801133F4_31D8A4_name_49 },
    { 14, D_80113404_31D8B4_name_49 },
    { 80, D_80113414_31D8C4_name_49 },
    { 32, D_80113424_31D8D4_name_49 },
    { 20, D_80113434_31D8E4_name_49 },
    { 26, D_80113444_31D8F4_name_49 },
    { 87, D_80113454_31D904_name_49 },
    { 73, D_80113464_31D914_name_49 },
    { 97, D_80113474_31D924_name_49 },
    { 50, D_80113484_31D934_name_49 },
    { 56, D_80113494_31D944_name_49 },
    { 59, D_801134A4_31D954_name_49 },
    { -2, D_80113A64_31DF14_name_49 },
    { 0, D_80113808_31DCB8_name_49 },
    { 5, D_80113818_31DCC8_name_49 },
    { 65, D_80113828_31DCD8_name_49 },
    { 46, D_80113838_31DCE8_name_49 },
    { 86, D_80113848_31DCF8_name_49 },
    { 84, D_80113858_31DD08_name_49 },
    { 82, D_80113868_31DD18_name_49 },
    { 130, D_80113AE4_31DF94_name_49 },
    { 150, D_80113AF4_31DFA4_name_49 },
    { 152, D_80113B04_31DFB4_name_49 },
    { 9, D_80113B2C_31DFDC_name_49 },
    { 10, D_80113B3C_31DFEC_name_49 },
    { 12, D_80113B4C_31DFFC_name_49 },
    { 92, D_80113B98_31E048_name_49 },
    { 93, D_80113BA8_31E058_name_49 },
    { 94, D_80113BB8_31E068_name_49 },
    { 95, D_80113BC8_31E078_name_49 },
    { 96, D_80113BD8_31E088_name_49 },
    { 131, D_80113C38_31E0E8_name_49 },
    { -1, NULL },
};
f32 D_80113D80_31E230_name_49[4] = {
    0.0f, 0.0f, 320.0f, 240.0f,
};
DecisionTreeNonLeafNode D_80113D90_31E240_name_49[1] = {
    { 0x00000000, { (void*)0 }, { 0x5032 } },
};
DecisionTreeNonLeafNode D_80113D9C_31E24C_name_49[3] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x50002 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80113DC0_31E270_name_49[17] = {
    { 0x0F000000, { (void*)0x5 }, { 0 } },
    { 0x0D000000, { (void*)0x30000 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x20307 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0xF }, { 0x1E } },
    { 0x0D000000, { (void*)0x90001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x10003 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0x10407 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60002 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x80004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40003 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x30204 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50306 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x1 }, { (DtData)D_80113D9C_31E24C_name_49 } },
    { 0x0D000000, { (void*)0x50002 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80113E8C_31E33C_name_49[17] = {
    { 0x0F000000, { (void*)0x5 }, { 0 } },
    { 0x0D000000, { (void*)0x30000 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x20307 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0xF }, { 0x1E } },
    { 0x0D000000, { (void*)0x90001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x10003 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0x10407 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60002 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x80004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40003 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x30204 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50306 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x1 }, { (DtData)D_80113D9C_31E24C_name_49 } },
    { 0x0D000000, { (void*)0x50002 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80113F58_31E408_name_49[7] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0xC0001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0406 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50406 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80113FAC_31E45C_name_49[15] = {
    { 0x0F000000, { (void*)0x5 }, { 0 } },
    { 0x0D000000, { (void*)0x110004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x120002 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0xF }, { 0x1E } },
    { 0x0D000000, { (void*)0xD0004 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0xC0205 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x110506 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x2 }, { (DtData)D_80113F58_31E408_name_49 } },
    { 0x0D000000, { (void*)0xC0001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0406 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50406 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80114060_31E510_name_49[3] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0xE0205 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x5032 } },
};
DecisionTreeNonLeafNode D_80114084_31E534_name_49[7] = {
    { 0x0F000000, { (void*)0x25 }, { 0x1E } },
    { 0x0D000000, { (void*)0xC0001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0406 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50406 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801140D8_31E588_name_49[10] = {
    { 0x0F000000, { (void*)0x20 }, { 0x1E } },
    { 0x0D000000, { (void*)0xF0001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xC0205 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x2 }, { (DtData)D_80114084_31E534_name_49 } },
    { 0x0D000000, { (void*)0xC0001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0406 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50406 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80114150_31E600_name_49[12] = {
    { 0x0F000000, { (void*)0x1E }, { 0x1E } },
    { 0x0D000000, { (void*)0x70002 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50306 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x10406 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x25 }, { 0x1E } },
    { 0x0D000000, { (void*)0xF0003 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xC0205 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x110606 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801141E0_31E690_name_49[18] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0xF0509 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x70305 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x100000 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xF0A0B }, { 0x5A3C } },
    { 0x09000000, { (void*)0x4 }, { (DtData)D_80114150_31E600_name_49 } },
    { 0x0D000000, { (void*)0x70002 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xA0006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50306 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x10406 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x25 }, { 0x1E } },
    { 0x0D000000, { (void*)0xF0003 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xC0205 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x110606 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801142B8_31E768_name_49[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_80113D90_31E240_name_49 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80113DC0_31E270_name_49 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_80113E8C_31E33C_name_49 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_80113FAC_31E45C_name_49 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_80114060_31E510_name_49 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_801140D8_31E588_name_49 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_801141E0_31E690_name_49 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80114318_31E7C8_name_49[1] = {
    { 0x00000000, { (void*)0 }, { 0x5032 } },
};
DecisionTreeNonLeafNode D_80114324_31E7D4_name_49[3] = {
    { 0x0D000000, { (void*)0x50002 }, { 0xA } },
    { 0x0E000000, { (void*)0x50002 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80114348_31E7F8_name_49[7] = {
    { 0x0D000000, { (void*)0xC0001 }, { 0xA } },
    { 0x0D000000, { (void*)0x60005 }, { 0xA } },
    { 0x0D000000, { (void*)0x40006 }, { 0xA } },
    { 0x0E000000, { (void*)0xC0001 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_8011439C_31E84C_name_49[7] = {
    { 0x0D000000, { (void*)0x70002 }, { 0xA } },
    { 0x0D000000, { (void*)0x60005 }, { 0xA } },
    { 0x0D000000, { (void*)0x40006 }, { 0xA } },
    { 0x0E000000, { (void*)0x70002 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x60005 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x40006 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_801143F0_31E8A0_name_49[3] = {
    { 0x0D000000, { (void*)0xD000A }, { 0xA } },
    { 0x0E000000, { (void*)0xD000A }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80114414_31E8C4_name_49[3] = {
    { 0x0D000000, { (void*)0xE0009 }, { 0xA } },
    { 0x0E000000, { (void*)0xE0009 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80114438_31E8E8_name_49[3] = {
    { 0x0D000000, { (void*)0xF0008 }, { 0xA } },
    { 0x0E000000, { (void*)0xF0008 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_8011445C_31E90C_name_49[9] = {
    { 0x0D000000, { (void*)0x80004 }, { 0xA } },
    { 0x0D000000, { (void*)0x100000 }, { 0xA } },
    { 0x0D000000, { (void*)0x70005 }, { 0xA } },
    { 0x0D000000, { (void*)0xF070B }, { 0xA } },
    { 0x0E000000, { (void*)0x80004 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x100000 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x70005 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0xF070B }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_801144C8_31E978_name_49[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_80114324_31E7D4_name_49 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80114348_31E7F8_name_49 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_8011439C_31E84C_name_49 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_801143F0_31E8A0_name_49 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_80114414_31E8C4_name_49 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80114438_31E8E8_name_49 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_8011445C_31E90C_name_49 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80114528_31E9D8_name_49[2] = {
    { 0x0D000000, { (void*)0x50002 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80114540_31E9F0_name_49[4] = {
    { 0x0D000000, { (void*)0xC0001 }, { 0 } },
    { 0x0D000000, { (void*)0x60205 }, { 0 } },
    { 0x0D000000, { (void*)0x40306 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80114570_31EA20_name_49[4] = {
    { 0x0D000000, { (void*)0x70002 }, { 0 } },
    { 0x0D000000, { (void*)0x60305 }, { 0 } },
    { 0x0D000000, { (void*)0x40406 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_801145A0_31EA50_name_49[2] = {
    { 0x0D000000, { (void*)0xD040A }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_801145B8_31EA68_name_49[3] = {
    { 0x0D000000, { (void*)0xE0001 }, { 0 } },
    { 0x0D000000, { (void*)0xE0509 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_801145DC_31EA8C_name_49[2] = {
    { 0x0D000000, { (void*)0xF0108 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_801145F4_31EAA4_name_49[5] = {
    { 0x0D000000, { (void*)0x80004 }, { 0 } },
    { 0x0D000000, { (void*)0x100000 }, { 0 } },
    { 0x0D000000, { (void*)0x70305 }, { 0 } },
    { 0x0D000000, { (void*)0xF0A0B }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80114630_31EAE0_name_49[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_80114528_31E9D8_name_49 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80114540_31E9F0_name_49 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_80114570_31EA20_name_49 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_801145A0_31EA50_name_49 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_801145B8_31EA68_name_49 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_801145DC_31EA8C_name_49 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_801145F4_31EAA4_name_49 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80114690_31EB40_name_49[2] = {
    { 0x02000000, { (void*)0x1 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_801146A8_31EB58_name_49[2] = {
    { 0x02000000, { (void*)0x6E }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_801146C0_31EB70_name_49[2] = {
    { 0x01000000, { (void*)0x1E }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
s32 D_801146D8_31EB88_name_49 = 0;
u8 D_801146DC_31EB8C_name_49[12] = {
    9, 6, 0, 7, 4, 8, 2, 5, 1, 0, 0, 0,
};
u8 D_801146E8_31EB98_name_49[12] = {
    9, 1, 6, 7, 4, 8, 0, 2, 5, 0, 0, 0,
};
u8 D_801146F4_31EBA4_name_49[12] = {
    9, 7, 2, 6, 4, 8, 0, 5, 1, 0, 0, 0,
};
u8 D_80114700_31EBB0_name_49[12] = {
    9, 5, 7, 6, 4, 8, 0, 2, 1, 0, 0, 0,
};
u8 D_8011470C_31EBBC_name_49[12] = {
    9, 4, 8, 7, 6, 0, 2, 5, 1, 0, 0, 0,
};
u8 D_80114718_31EBC8_name_49[12] = {
    9, 7, 6, 4, 8, 0, 2, 5, 1, 0, 0, 0,
};
u8* D_80114724_31EBD4_name_49[6] = {
    D_801146DC_31EB8C_name_49, D_801146E8_31EB98_name_49,
    D_801146F4_31EBA4_name_49, D_80114700_31EBB0_name_49,
    D_8011470C_31EBBC_name_49, D_80114718_31EBC8_name_49,
};
s8 D_8011473C_31EBEC_name_49[12] = {
    100, 70, 60, 0, 50, 0, 30, 30, 10, 0, 0, 0,
};
s8 D_80114748_31EBF8_name_49[12] = {
    100, 70, 60, 0, 50, 0, 20, 30, 30, 0, 0, 0,
};
s8 D_80114754_31EC04_name_49[12] = {
    100, 70, 60, 60, 50, 0, 20, 30, 10, 0, 0, 0,
};
s8 D_80114760_31EC10_name_49[12] = {
    100, 70, 60, 60, 50, 0, 20, 30, 10, 0, 0, 0,
};
s8 D_8011476C_31EC1C_name_49[12] = {
    100, 70, 60, 0, 60, 20, 30, 30, 10, 0, 0, 0,
};
s8 D_80114778_31EC28_name_49[12] = {
    100, 70, 60, 50, 0, 20, 30, 30, 10, 0, 0, 0,
};
s8* D_80114784_31EC34_name_49[6] = {
    D_8011473C_31EBEC_name_49, D_80114748_31EBF8_name_49,
    D_80114754_31EC04_name_49, D_80114760_31EC10_name_49,
    D_8011476C_31EC1C_name_49, D_80114778_31EC28_name_49,
};
u8 D_8011479C_31EC4C_name_49[20] = {
    9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s16 func_80102830_30CCE0_name_49(void) {
    return D_80112C68_31D118_name_49[GwSystem.star_spawn_indices[GwSystem.unk_0A]];
}

void func_8010285C_30CD0C_name_49(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = (u8)(rand8() % 7);
        b = (u8)(rand8() % 7);
        if (a != b) {
            if (a >= D_80112C30_31D0E0_name_49[b]) {
                if (b >= D_80112C30_31D0E0_name_49[a]) {
                    temp = D_80112C20_31D0D0_name_49[a];
                    D_80112C20_31D0D0_name_49[a] = D_80112C20_31D0D0_name_49[b];
                    D_80112C20_31D0D0_name_49[b] = temp;

                    temp = D_80112C30_31D0E0_name_49[a];
                    D_80112C30_31D0E0_name_49[a] = D_80112C30_31D0E0_name_49[b];
                    D_80112C30_31D0E0_name_49[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = D_80112C20_31D0D0_name_49[i];
    }

    if (gw->unk_1C == -1) {
        temp = 0;
    retry:
        gw->unk_1C = gw->star_spawn_indices[6 - temp];
        for (i = 0; D_80112C40_31D0F0_name_49[i] != -1; i++) {
            if (gw->unk_1C == D_80112C40_31D0F0_name_49[i]) {
                temp++;
                goto retry;
            }
        }
    }
}

void func_80102A44_30CEF4_name_49(void) {
    u8 order[16];
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    MBArrayShuffle(order, 6);
    gw->unk_0A = 0;
    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = order[i];
    }
    gw->unk_1C = gw->star_spawn_indices[6];
}

void func_80102AB0_30CF60_name_49(void) {
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    gw->unk_1C = gw->star_spawn_indices[gw->unk_0A];
    if (++gw->unk_0A < 7) {
        return;
    }
    temp = gw->star_spawn_indices[6];
    gw->unk_0A = 0;
    _SetFlag(0x44);
    func_8010285C_30CD0C_name_49();
    if (temp != gw->star_spawn_indices[0]) {
        return;
    }
    temp = gw->star_spawn_indices[0];
    gw->star_spawn_indices[0] = gw->star_spawn_indices[6];
    gw->star_spawn_indices[6] = temp;
}

void func_80102B54_30D004_name_49(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 7; i++) {
        _SetFlag(D_80112C48_31D0F8_name_49[i]);
    }
    BoardSpaceTypeSet(D_80112C58_31D108_name_49[gw->star_spawn_indices[gw->unk_0A]], 0xE);
    _ClearFlag(D_80112C48_31D0F8_name_49[gw->star_spawn_indices[gw->unk_0A]]);
    if (gw->unk_1C != -1) {
        BoardSpaceTypeSet(D_80112C58_31D108_name_49[gw->unk_1C], 0xF);
        func_800509C4_515C4(D_80112C58_31D108_name_49[gw->unk_1C]);
    }
}

#ifdef NON_MATCHING
s32 func_80102C3C_30D0EC_name_49(s32 space) {
    s32 i;
    s32 j;
    s16* spaces;
    GW_SYSTEM* gw = &GwSystem;

    i = 0;
    spaces = D_80112C58_31D108_name_49;
    space = (s16)space;
    do {
        if (space == spaces[i]) {
            if (i == gw->star_spawn_indices[gw->unk_0A]) {
                gw->unk_1A = D_80112C48_31D0F8_name_49[i];
                return 1;
            }
            if (i == gw->unk_1C) {
                return 2;
            }
            if (_CheckFlag(0x44)) {
                space = 7;
            } else {
                space = gw->unk_0A;
            }
            for (j = 0; j < space; j++) {
                if (i == gw->star_spawn_indices[j]) {
                    return 3;
                }
            }
            return 0;
        }
        i++;
    } while (i < 7);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80102C3C_30D0EC_name_49);
#endif

void func_80102D28_30D1D8_name_49(void) {
    SpaceData* space;
    MBModel* star;
    ModelEmitterWork* emitter;
    s32 i;
    f32 scale;
    f32 rot;

    space = HuPrcCurrentGet()->user_data;
    PlaySound(0x34E);
    star = func_80043510_44110(0x19, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    func_800B3170_B3D70(&star->pos, &space->coords);
    star->jumpY = 50.0f;
    emitter = func_80049ED4_4AAD4(star, 0);
    emitter->unk18 = 0.1f;
    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    PlaySound(0x32C);
    rot = 0.0f;
    while (1) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.04f;
        if (scale < 0.0f) {
            break;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        star->jumpY -= 1.2f;
        HuPrcVSleep();
    }
    func_80049F90_4AB90(emitter);
    MBModelKill(star);
    D_80114990_31EE40_name_49 = NULL;
    omDelPrcObj(NULL);
}

void func_80102F4C_30D3FC_name_49(UnkMBGuideData* guide) {
    MBModel* obj;

    obj = guide->obj;
    obj->jumpVel = 4.0f;
    obj->jumpAccel = -0.6f;
    HuPrcSleep(3);
    while (obj->jumpAccel != 0.0f) {
        HuPrcVSleep();
    }
    MBMotionSet(guide->obj, 0, 2);
    func_8005B338_5BF38(guide);
}

void func_80102FFC_30D4AC_name_49(void) {
    UnkMBGuideData* guide;
    SpaceData* space;
    Process* proc;
    s32 mes;
    s32 pick;
    GW_SYSTEM* gw = &GwSystem;

    pick = 0;
    D_800CCC18_CD818 = 0;
    guide = func_80050304_50F04(D_800CC6A8_CD2A8[gw->current_board_index], 0);
    guide->obj->rot.x = HuMathSin(D_800CC6C4_CD2C4[gw->current_board_index]);
    guide->obj->rot.z = func_800B7890_B8490(D_800CC6C4_CD2C4[gw->current_board_index]);
    func_8005B338_5BF38(guide);
    PlayMusic(0x11);
    func_80067558_68158();
    InitFadeIn(2, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    func_80053608_54208(3.0f);
    func_80102F4C_30D3FC_name_49(guide);
    if (gw->unk_0A == 0 && !_CheckFlag(0x44)) {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B4 : 0x6B2;
    } else {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B4 : 0x6B3;
    }
    func_800890CC_89CCC(guide->amount, mes, -1, -1);
    func_8008E2DC_8EEDC(guide->amount, 1);
    PlaySound(0x363);
    func_80057DC0_589C0(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_8005B338_5BF38(guide);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8002D4A0_2E0A0(guide->obj->obj->model[0]);
    if (D_800F8D12_F9912 != 0 && (u8)(pick = rand8() & 1) == 0) {
        space = GetSpaceData(D_80112C68_31D118_name_49[gw->unk_1C]);
    } else {
        space = GetSpaceData(D_80112C68_31D118_name_49[gw->star_spawn_indices[gw->unk_0A]]);
    }
    MBDCameraPos3DSet(&space->coords);
    MBCameraSpeedSet(3.5f);
    HuPrcSleep(5);
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    MBMotionSet(guide->obj, 0, 2);
    func_8005B338_5BF38(guide);
    if (D_800F8D12_F9912 == 0) {
        proc = omAddPrcObj(func_80102D28_30D1D8_name_49, 0x4800, 0, 0);
        D_80114990_31EE40_name_49 = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_80114990_31EE40_name_49 = NULL;
    }
    D_800F920C_F9E0C[guide->amount].unk20 = 1;
    HuPrcVSleep();
    func_8008E2DC_8EEDC(guide->amount, 1);
    func_80057DC0_589C0(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_8005B338_5BF38(guide);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8002D4A0_2E0A0(guide->obj->obj->model[0]);
    if (gw->unk_1C != -1) {
        while (D_80114990_31EE40_name_49 != NULL) {
            HuPrcVSleep();
        }
        if (D_800F8D12_F9912 != 0 && (u8)pick == 0) {
            space = GetSpaceData(D_80112C68_31D118_name_49[gw->star_spawn_indices[gw->unk_0A]]);
        } else {
            space = GetSpaceData(D_80112C68_31D118_name_49[gw->unk_1C]);
        }
        MBDCameraPos3DSet(&space->coords);
        MBCameraSpeedSet(3.5f);
        HuPrcSleep(5);
        while (func_80053998_54598() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(5);
        MBMotionSet(guide->obj, 0, 2);
        func_80029FE4_2ABE4(guide->obj->obj->model[0], 2.0f);
        func_8005B338_5BF38(guide);
            D_800F920C_F9E0C[guide->amount].unk20 = 1;
        HuPrcVSleep();
        func_8008E2DC_8EEDC(guide->amount, 1);
        func_80057DC0_589C0(guide->amount);
        func_8008E4D0_8F0D0(guide->amount, 1);
    }
    func_800794A8_7A0A8(90);
    HuPrcSleep(30);
    InitFadeOut(2, 16);
    HuPrcSleep(17);
    D_800CCC18_CD818 = 1;
    func_80067720_68320();
    func_8005057C_5117C(guide);
    func_80063178_63D78();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_80103500_30D9B0_name_49(void) {
    Vec target;
    MBModel* parent;
    GW_PLAYER* player;
    MBModel* star;
    ModelEmitterWork* emitter;
    f32 scale;
    f32 rot;
    s32 i;

    parent = HuPrcCurrentGet()->user_data;
    player = BoardPlayerGet(-1);
    PlaySound(D_80112C78_31D128_name_49 == 0 ? 0x355 : 0x34E);
    star = func_80043510_44110(D_80114994_31EE44_name_49 == 0 ? 0x19 : 0xD, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    HuVecCopyXYZ(&star->pos, parent->pos.x, parent->pos.y + 10.0f, parent->pos.z);
    HuVecCopyXYZ(&target, D_800C9B80_CA780->pos.x, D_800C9B80_CA780->pos.y, D_800C9B80_CA780->pos.z);
    star->jumpY = 15.0f;
    emitter = func_80049ED4_4AAD4(star, 0);
    emitter->unk18 = 0.1f;
    for (scale = 0.0f, i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    PlaySound(0x32C);
    rot = 0.0f;
    HuVecCopyXYZ(&target, ((MBModel*)player->unk_24)->pos.x, ((MBModel*)player->unk_24)->pos.y - 10.0f,
                 ((MBModel*)player->unk_24)->pos.z);
    func_80056D80_57980(&star->pos, &target, &star->pos, 40);
    for (i = 0; i < 40; i++) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    MBModelKill(star);
    func_80049F90_4AB90(emitter);
    func_8005670C_5730C(&((MBModel*)player->unk_24)->rot);
    if (D_80114994_31EE44_name_49 == 0) {
        MBPlayerVibrate(-1, 5);
        if (D_80112C78_31D128_name_49 != 0) {
            func_80079428_7A028(0x5C);
        } else {
            PlayMusic(0x5C);
        }
        gPlayers[GwSystem.current_player_index].stars++;
        if (gPlayers[GwSystem.current_player_index].stars >= 100) {
            gPlayers[GwSystem.current_player_index].stars = 99;
        }
        MBPlayerMotionSet(-1, 6, 0);
        func_80079718_7A318(0xF5, gPlayers[GwSystem.current_player_index].character);
    } else {
        MBPlayerVibrate(-1, 5);
        func_80079428_7A028(0x5D);
        MBPlayerMotionSet(-1, 3, 0);
        func_80079718_7A318(0x111, gPlayers[GwSystem.current_player_index].character);
        HuPrcSleep(30);
    }
    HuPrcSleep(60);
    omDelPrcObj(NULL);
}

void func_80103920_30DDD0_name_49(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80114994_31EE44_name_49 = 0;
    proc = omAddPrcObj(func_80103500_30D9B0_name_49, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_8010399C_30DE4C_name_49(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80114994_31EE44_name_49 = 1;
    proc = omAddPrcObj(func_80103500_30D9B0_name_49, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103A1C_30DECC_name_49(void) {
    Vec target;
    Ovl49StarProcWork* work;
    MBModel* parent;
    Vec* dest;
    GW_PLAYER* player;
    MBModel* star;
    ModelEmitterWork* emitter;
    f32 scale;
    f32 rot;
    s32 i;

    work = HuPrcCurrentGet()->user_data;
    player = BoardPlayerGet(-1);
    parent = work->parent;
    dest = work->pos;
    PlaySound(0x34E);
    star = func_80043510_44110(0x19, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    HuVecCopyXYZ(&star->pos, parent->pos.x, parent->pos.y + 10.0f, parent->pos.z);
    HuVecCopyXYZ(&target, D_800C9B80_CA780->pos.x, D_800C9B80_CA780->pos.y, D_800C9B80_CA780->pos.z);
    star->jumpY = 15.0f;
    emitter = func_80049ED4_4AAD4((Object*)star, 0);
    emitter->unk18 = 0.1f;
    for (scale = 0.0f, i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    PlaySound(0x32C);
    rot = 0.0f;
    func_80056D80_57980(&star->pos, dest, &star->pos, 40);
    for (i = 0; i < 40; i++) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    MBModelKill(star);
    func_80049F90_4AB90(emitter);
    func_8005670C_5730C(&((MBModel*)player->unk_24)->rot);
    gPlayers[GwSystem.current_player_index].stars--;
    func_80079428_7A028(0x5D);
    MBPlayerMotionSet(-1, 3, 0);
    func_80079718_7A318(0x111, gPlayers[GwSystem.current_player_index].character);
    HuPrcSleep(60);
    omDelPrcObj(NULL);
}

void func_80103D28_30E1D8_name_49(MBModel* arg0, Vec* arg1) {
    Vec pos;
    Process* proc;
    Ovl49StarProcWork* work;

    D_800FC734_FD334 = 0;
    func_800B3170_B3D70(&pos, arg1);
    proc = omAddPrcObj(func_80103A1C_30DECC_name_49, 0x4800, 0, 0x40);
    work = HuMemMemoryAlloc(proc->heap, 0x10);
    proc->user_data = work;
    work->parent = arg0;
    work->pos = &pos;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103DBC_30E26C_name_49(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

void func_80103E4C_30E2FC_name_49(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

s32 func_80103EC8_30E378_name_49(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_80103F1C_30E3CC_name_49(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80114998_31EE48_name_49 = func_8004CC7C_4D87C(0, 0x92, 1);
    D_8011499C_31EE4C_name_49 = func_8004CC7C_4D87C(1, 0xA0, 1);
    D_801149A8_31EE58_name_49 = func_8004CC7C_4D87C(0xD, 0xAE, 1);
    D_801149A0_31EE50_name_49 = func_8004CC7C_4D87C(3, 0xBC, 1);
    D_801149A4_31EE54_name_49 = func_8004CC7C_4D87C(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800FA198_FAD98 = 1;
    D_80101058_101C58 = 1;
}

void func_80103FEC_30E49C_name_49(void) {
    D_800FA198_FAD98 = 0;
    D_80101058_101C58 = 0;
    MBHelpWinKill(D_80114998_31EE48_name_49);
    MBHelpWinKill(D_8011499C_31EE4C_name_49);
    MBHelpWinKill(D_801149A8_31EE58_name_49);
    MBHelpWinKill(D_801149A0_31EE50_name_49);
    MBHelpWinKill(D_801149A4_31EE54_name_49);
}

__asm__(".section .rodata");
const u8 D_801147B0_31EC60_name_49[4] = { 1, 2, 4, 8 };

s32 func_8010404C_30E4FC_name_49(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80112828_31CCD8_name_49();
                sp18[gPlayers[GwSystem.current_player_index].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 2; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8008BB48_8C748(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
        if (items[i] != 0) {
            return i;
        }
    }
}

s32 func_80104308_30E7B8_name_49(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80112BA4_31D054_name_49();
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

s32 func_8010452C_30E9DC_name_49(void) {
    s32 com = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                com = 1;
                sp18[gPlayers[i].port] = -0x8000;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (com != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

void func_801046D8_30EB88_name_49(void) {
    s32 i;
    s32 turnBand;
    s32 coinBand;

    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].stars != 0) {
            break;
        }
    }
    if (i != 4 && gPlayers[GwSystem.current_player_index].coins >= 50) {
        if (GwSystem.total_turns == GwSystem.current_turn) {
            D_801149D0_31EE80_name_49 = 1;
            return;
        }
        if (GwSystem.current_turn < 10) {
            turnBand = 0;
        } else if (GwSystem.current_turn < 30) {
            turnBand = 1;
        } else {
            turnBand = 2;
        }
        if (gPlayers[GwSystem.current_player_index].coins < 61) {
            coinBand = 0;
        } else if (gPlayers[GwSystem.current_player_index].coins < 71) {
            coinBand = 1;
        } else {
            coinBand = (gPlayers[GwSystem.current_player_index].coins < 101) ? 2 : 3;
        }
        if (func_80103EC8_30E378_name_49() < D_80112C7C_31D12C_name_49[turnBand][coinBand]) {
            D_801149D0_31EE80_name_49 = 1;
        } else {
            goto coins;
        }
    }
    if (D_801149D0_31EE80_name_49 == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_801149D0_31EE80_name_49 = 0;
    } else {
        D_801149D0_31EE80_name_49 = 2;
    }
}


s32 func_80104918_30EDC8_name_49(void) {
    s32 flags[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 min;

    if (GwSystem.current_player_index != D_801149C0_31EE70_name_49[0]) {
        coins = gPlayers[D_801149C0_31EE70_name_49[0]].coins;
        i = 1;
        flags[0] = 1;
    } else {
        coins = gPlayers[D_801149C0_31EE70_name_49[1]].coins;
        i = 2;
        flags[1] = 1;
    }
    for (; i < 4; i++) {
        if (GwSystem.current_player_index != D_801149C0_31EE70_name_49[i]
            && gPlayers[D_801149C0_31EE70_name_49[i]].coins + 5 >= coins) {
            flags[i] = 1;
        }
    }
    min = 4;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0 && func_80059FD0_5ABD0(D_801149C0_31EE70_name_49[i]) < min) {
            min = func_80059FD0_5ABD0(D_801149C0_31EE70_name_49[i]);
        }
    }
    return min;
}

#ifdef NON_MATCHING
void func_80104AD0_30EF80_name_49(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_80103EC8_30E378_name_49();
    switch (D_801149D0_31EE80_name_49) {
    case 1:
        if (GwSystem.total_turns < GwSystem.current_turn + 5) {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 95 && gPlayers[D_801149B0_31EE60_name_49[2]].stars < 2) {
                    if (gPlayers[D_801149B0_31EE60_name_49[2]].stars != 0) {
                        D_801149D8_31EE88_name_49 = 2;
                        break;
                    }
                }
                D_801149D8_31EE88_name_49 = 1;
                break;
            case 1:
                if (r >= 95 && gPlayers[D_801149B0_31EE60_name_49[2]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 2;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            case 2:
                if (r >= 95 && gPlayers[D_801149B0_31EE60_name_49[1]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 1;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            case 3:
                if (r > 94 && gPlayers[D_801149B0_31EE60_name_49[1]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 1;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            }
        } else {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 80 && gPlayers[D_801149B0_31EE60_name_49[2]].stars < 2) {
                    if (gPlayers[D_801149B0_31EE60_name_49[2]].stars != 0) {
                        D_801149D8_31EE88_name_49 = 2;
                        break;
                    }
                }
                D_801149D8_31EE88_name_49 = 1;
                break;
            case 1:
                if (r >= 90 && gPlayers[D_801149B0_31EE60_name_49[2]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 2;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            case 2:
                if (r >= 90 && gPlayers[D_801149B0_31EE60_name_49[1]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 1;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            case 3:
                if (r >= 95 && gPlayers[D_801149B0_31EE60_name_49[1]].stars != 0) {
                    D_801149D8_31EE88_name_49 = 1;
                } else {
                    D_801149D8_31EE88_name_49 = 0;
                }
                break;
            }
        }
        break;
    case 0:
        count = 0;
        for (i = 0; i < 4; i++) {
            cand[i] = 0;
        }
        if (count == 0 || GwSystem.total_turns == GwSystem.current_turn
            || (GwSystem.total_turns < GwSystem.current_turn + 5 && func_80103EC8_30E378_name_49() < 80)
            || func_80103EC8_30E378_name_49() < 40) {
            if (GwSystem.total_turns < GwSystem.current_turn + 5) {
                if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                    if (gPlayers[D_801149B0_31EE60_name_49[1]].coins == 0) {
                        goto steal;
                    }
                    if (gPlayers[D_801149B0_31EE60_name_49[0]].stars == gPlayers[D_801149B0_31EE60_name_49[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_801149D8_31EE88_name_49 = 1;
                        return;
                    }
                    goto steal;
                }
                if (gPlayers[D_801149B0_31EE60_name_49[0]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_801149B0_31EE60_name_49[0]].stars - 1 <= gPlayers[D_801149B0_31EE60_name_49[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (gPlayers[D_801149B0_31EE60_name_49[0]].stars - 2 == gPlayers[D_801149B0_31EE60_name_49[1]].stars) {
                    if (r < 85) {
                        goto zero;
                    }
                    goto steal;
                }
                if (r < 95) {
                    goto zero;
                }
                goto steal;
            }
            if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                if (gPlayers[D_801149B0_31EE60_name_49[1]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_801149B0_31EE60_name_49[0]].stars != gPlayers[D_801149B0_31EE60_name_49[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_801149D8_31EE88_name_49 = 1;
                return;
            }
            if (gPlayers[D_801149B0_31EE60_name_49[0]].coins == 0) {
                goto steal;
            }
            if (gPlayers[D_801149B0_31EE60_name_49[0]].stars - 1 <= gPlayers[D_801149B0_31EE60_name_49[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (gPlayers[D_801149B0_31EE60_name_49[0]].stars - 2 == gPlayers[D_801149B0_31EE60_name_49[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_801149D8_31EE88_name_49 = 0;
            return;
        steal:
            D_801149D8_31EE88_name_49 = func_80104918_30EDC8_name_49();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_801149B0_31EE60_name_49[i]] != 0) {
                if (--count == 0) {
                    D_801149D8_31EE88_name_49 = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80104AD0_30EF80_name_49);
#endif

#ifdef NON_MATCHING
void func_801052D4_30F784_name_49(void) {
    s32 starRankCount[4];
    s32 coinRankCount[4];
    s32 i;
    s32 j;
    s32 rank;
    s32 coinRank;

    for (i = 0; i < 4; i++) {
        starRankCount[i] = 0;
        coinRankCount[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        starRankCount[func_80059FD0_5ABD0(i)]++;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
        coinRankCount[coinRank]++;
    }
    for (i = 0; i < 4; i++) {
        D_801149B0_31EE60_name_49[i] = -1;
        D_801149C0_31EE70_name_49[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        rank = func_80059FD0_5ABD0(i);
    starSlot:
        if (D_801149B0_31EE60_name_49[rank] != -1) {
            rank++;
            goto starSlot;
        }
        D_801149B0_31EE60_name_49[rank] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
    coinSlot:
        if (D_801149C0_31EE70_name_49[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_801149C0_31EE70_name_49[coinRank] = i;
    }
    D_801149D0_31EE80_name_49 = D_801149D4_31EE84_name_49 = D_801149D8_31EE88_name_49 = -1;
    func_801046D8_30EB88_name_49();
    if (D_801149D8_31EE88_name_49 == -1) {
        func_80104AD0_30EF80_name_49();
    }
    while (starRankCount[D_801149D8_31EE88_name_49] == 0) {
        D_801149D8_31EE88_name_49--;
    }
    rank = func_80059FD0_5ABD0(GwSystem.current_player_index);
    if (rank == D_801149D8_31EE88_name_49) {
        starRankCount[rank]--;
    }
    j = rand8() % starRankCount[D_801149D8_31EE88_name_49];
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            continue;
        }
        if (D_801149D8_31EE88_name_49 != func_80059FD0_5ABD0(i)) {
            continue;
        }
        if (j != 0) {
            j--;
            continue;
        }
        D_801149D4_31EE84_name_49 = i;
        break;
    }
    if (D_801149D0_31EE80_name_49 == 0 && gPlayers[D_801149D4_31EE84_name_49].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
                D_801149D4_31EE84_name_49 = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_801052D4_30F784_name_49);
#endif

s32 func_801056D4_30FB84_name_49(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                func_801052D4_30F784_name_49();
                count = D_801149D0_31EE80_name_49 + 1;
                sp18[gPlayers[GwSystem.current_player_index].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 2; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    i = 0;
    do {
        i = func_8008BB48_8C748(mbDlgWinId, i, 1);
    } while (items[i] == 0);
    return i;
}

s32 func_80105988_30FE38_name_49(s32 arg0, u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = D_801149D4_31EE84_name_49;
                count += count < i;
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        while (count != 0) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 3; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8008BB48_8C748(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
        if (items[i] != 0) {
            return i;
        }
    }
}

void func_80105BFC_3100AC_name_49(void) {
    GwSystem.current_board_index = 5;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_80105C38_3100E8_name_49(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    _SetFlag(0x43);
    func_8010285C_30CD0C_name_49();
    D_800F8CE4_F98E4[0x1E] = 0;
    D_800F8CE4_F98E4[0x1D] = 0;
    D_800F8CE4_F98E4[0x1A] = 0;
    D_800F8CE4_F98E4[0x19] = 0;
    D_800F8CE4_F98E4[0x17] = 0;
    D_800F8CE4_F98E4[0] = 5;
    D_800F8CE4_F98E4[1] = 0;
    D_800F8CE4_F98E4[2] = 0;
    D_800F8CE4_F98E4[3] = 0;
    D_800F8CE4_F98E4[4] = 3;
    omOvlReturnEx(1);
}

void func_80105CE8_310198_name_49(void) {
    s32 i;
    SpaceData* from;
    Vec dir;

    omInitObjMan(0xA0, 0x3C);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(0x25, 0x45, 0x2A, 0);
    func_80055928_56528(D_80112C88_31D138_name_49);
    func_80055980_56580(D_80112C9C_31D14C_name_49);
    from = GetSpaceData(0x83);
    func_80056658_57258(&from->coords, &GetSpaceData(0x65)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    from = GetSpaceData(0x8C);
    func_80056658_57258(&from->coords, &GetSpaceData(0x64)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    func_8004D60C_4E20C(0, func_8010ABC0_315070_name_49);
    func_8004D60C_4E20C(1, func_8010B850_315D00_name_49);
    func_8004D60C_4E20C(8, func_8010BBEC_31609C_name_49);
    func_8004D60C_4E20C(2, func_8010BC5C_31610C_name_49);
    func_8004D60C_4E20C(3, func_8010CFCC_31747C_name_49);
    func_8004D60C_4E20C(4, func_8010D544_3179F4_name_49);
    func_8004D60C_4E20C(5, func_8010D7B4_317C64_name_49);
    func_8004D60C_4E20C(6, func_8010C140_3165F0_name_49);
    func_8004D60C_4E20C(7, func_8010CB68_317018_name_49);
    func_8004D60C_4E20C(9, func_8010D9E8_317E98_name_49);
    func_8004D60C_4E20C(10, func_8010DCFC_3181AC_name_49);
    func_8004D60C_4E20C(12, func_8010E370_318820_name_49);
    func_8004D60C_4E20C(11, func_8010E5A4_318A54_name_49);
    func_8004D60C_4E20C(13, func_8010EAB4_318F64_name_49);
    func_80044D98_45998(func_80112604_31CAB4_name_49);
    for (i = 0; i < 7; i++) {
        func_800542E8_54EE8(i, D_80112C68_31D118_name_49[i]);
    }
    if (_CheckFlag(0x4D)) {
        _ClearFlag(0x4D);
        if (D_800F8D12_F9912 != 0) {
            func_80102A44_30CEF4_name_49();
        } else {
            func_80102AB0_30CF60_name_49();
        }
    }
    func_80102B54_30D004_name_49();
    func_80106210_3106C0_name_49();
    func_80106188_310638_name_49();
    func_80106460_310910_name_49();
    func_80106740_310BF0_name_49();
    func_80106904_310DB4_name_49();
    func_80106AD0_310F80_name_49();
    func_80106B0C_310FBC_name_49();
    func_80106B84_311034_name_49();
    func_80106D34_3111E4_name_49();
}

void func_80105F94_310444_name_49(void) {
    s16 temp = D_800F8CE4_F98E4[0];

    if (temp != 1 || GwSystem.unk_24[0] != 2 || GwSystem.current_player_index != 0 ||
        (func_80062D44_63944() != 0 && func_80062D44_63944() != temp)) {
        PlayMusic(0xD);
    }
    func_800632F0_63EF0(0xD);
    func_80020070_20C70(2);
    func_80105CE8_310198_name_49();
    func_80053AA0_546A0(4);
    EventTableHydrate(D_8011369C_31DB4C_name_49);
    EventTableHydrate(D_80113C48_31E0F8_name_49);
    EventTableHydrate(D_8011370C_31DBBC_name_49);
    func_80066C34_67834(0);
}

void func_80106058_310508_name_49(void) {
    func_80020070_20C70(1);
    func_80105CE8_310198_name_49();
    func_80066C34_67834(1);
}

void func_80106084_310534_name_49(s16 arg0) {
    MBModel* obj;

    if (D_801149F8_31EEA8_name_49[arg0] == NULL) {
        if (D_801149F0_31EEA0_name_49 == NULL) {
            obj = func_80043510_44110(0x17, NULL);
            func_80043DAC_449AC(obj);
            D_801149F0_31EEA0_name_49 = obj;
        } else {
            obj = MBModelParamCreate(D_801149F0_31EEA0_name_49);
        }
        D_801149F8_31EEA8_name_49[arg0] = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80112CF4_31D1A4_name_49[arg0])->coords);
        func_80041AEC_426EC(6, obj, D_80112CAC_31D15C_name_49[arg0][0], D_80112CAC_31D15C_name_49[arg0][1]);
    }
}

void func_80106188_310638_name_49(void) {
    s32 i;

    D_801149F0_31EEA0_name_49 = NULL;
    for (i = 0; i < 7; i++) {
        D_801149F8_31EEA8_name_49[i] = NULL;
        if (_CheckFlag(D_80112D04_31D1B4_name_49[i]) == 0) {
            func_80106084_310534_name_49(i);
        }
    }
}

void func_80106210_3106C0_name_49(void) {
    MBModel* obj;
    GW_SYSTEM* gw = &GwSystem;

    if (gw->unk_1C != -1) {
        obj = func_80043510_44110(D_800F8D12_F9912 != 0 ? 0x17 : 0x1D, NULL);
        func_80043DAC_449AC(obj);
        D_800F64C8_F70C8 = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80112CF4_31D1A4_name_49[gw->unk_1C])->coords);
        D_80112D14_31D1C4_name_49 = func_80041AEC_426EC(0xB, obj, D_80112CAC_31D15C_name_49[gw->unk_1C][0],
                                                       D_80112CAC_31D15C_name_49[gw->unk_1C][1]);
    } else {
        D_800F64C8_F70C8 = NULL;
    }
}

void func_801062F8_3107A8_name_49(void) {
    if (D_800F64C8_F70C8 != NULL) {
        MBModelKill(D_800F64C8_F70C8);
    }
    if (D_80112D14_31D1C4_name_49 != -1) {
        func_80041B40_42740(D_80112D14_31D1C4_name_49);
    }
}

void func_80106340_3107F0_name_49(s16 arg0) {
    MBModel* obj;

    if (D_80114A18_31EEC8_name_49[arg0] != NULL) {
        return;
    }
    if (D_80114A14_31EEC4_name_49 == NULL) {
        obj = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(obj->obj->model[0]);
        func_8002D124_2DD24(obj->shadow->model[0]);
        D_80114A14_31EEC4_name_49 = obj;
    } else {
        obj = MBModelParamCreate(D_80114A14_31EEC4_name_49);
    }
    MBModelDispOff(obj);
    D_80114A18_31EEC8_name_49[arg0] = obj;
    obj->attr |= 2;
    obj->jumpY = 10.0f;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80112D18_31D1C8_name_49[arg0])->coords);
    func_80041AEC_426EC(8, obj, D_80112CC8_31D178_name_49[arg0][0], D_80112CC8_31D178_name_49[arg0][1]);
}

void func_80106460_310910_name_49(void) {
    s32 i;

    D_80114A14_31EEC4_name_49 = NULL;
    for (i = 0; i < 2; i++) {
        D_80114A18_31EEC8_name_49[i] = NULL;
        func_80106340_3107F0_name_49(i);
    }
}

void func_801064C0_310970_name_49(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 3; i++) {
        count = 5 - (D_800F8CE4_F98E4[0x1D] - 1) / 10;
        if (count <= 0) {
            count = 1;
        }
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_80114A28_31EED8_name_49[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_80114A28_31EED8_name_49[i * 5 + j]);
        }
    }
}

void func_801065D4_310A84_name_49(s16 arg0) {
    MBModel* coin;
    Vec* pos;
    s32 bank;
    s16 slot;

    if (D_80114A28_31EED8_name_49[arg0] == NULL) {
        if (D_80114A20_31EED0_name_49 == NULL) {
            coin = func_80043510_44110(0x6C, NULL);
            func_80043DAC_449AC(coin);
            D_80114A20_31EED0_name_49 = coin;
        } else {
            coin = MBModelParamCreate(D_80114A20_31EED0_name_49);
        }
        D_80114A28_31EED8_name_49[arg0] = coin;
        coin->attr |= 2;

        bank = arg0 / 5;
        pos = &coin->pos;
        func_800B3170_B3D70(pos, &GetSpaceData(D_80112D1C_31D1CC_name_49[bank])->coords);

        slot = arg0 % 5;
        HuVecAdd(pos, &D_80112D24_31D1D4_name_49[slot], pos);
        coin->obj->rot.x = D_80112D60_31D210_name_49[slot].x;
        coin->obj->rot.z = D_80112D60_31D210_name_49[slot].z;
        MBModelDispOff(coin);
    }
}

void func_80106740_310BF0_name_49(void) {
    s32 i;

    D_80114A20_31EED0_name_49 = NULL;
    for (i = 0; i < 15; i++) {
        D_80114A28_31EED8_name_49[i] = NULL;
        func_801065D4_310A84_name_49(i);
    }
    func_801064C0_310970_name_49();
}

void func_801067A8_310C58_name_49(s16 arg0) {
    MBModel* obj;
    SpaceData* space;
    char pad[4]; /* frame size, as MP3 func_80108748 (ChillyWaters) */

    if (D_80114A68_31EF18_name_49[arg0] == NULL) {
        if (D_80114A64_31EF14_name_49 == NULL) {
            /* D_80111AED[board * 2]: column 1 of a u8 [][2] table one byte before it */
            obj = func_80043510_44110(D_80112DA1_31D251_name_49[GwSystem.current_board_index * 2], NULL);
            func_80043DAC_449AC(obj);
            D_80114A64_31EF14_name_49 = obj;
        } else {
            obj = MBModelParamCreate(D_80114A64_31EF14_name_49);
        }
        D_80114A68_31EF18_name_49[arg0] = obj;
        obj->attr |= 2;
        func_80029E80_2AA80(obj->obj->model[0], 2, 1);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80112D9C_31D24C_name_49[arg0])->coords);
        space = GetSpaceData(D_80112CEC_31D19C_name_49[arg0][0]);
        func_80056658_57258(&GetSpaceData(D_80112CEC_31D19C_name_49[arg0][1])->coords, &space->coords, &obj->rot);
        func_80041AEC_426EC(0xC, obj, D_80112CD4_31D184_name_49[arg0][0], D_80112CD4_31D184_name_49[arg0][1]);
    }
}

void func_80106904_310DB4_name_49(void) {
    s32 i;

    D_80114A64_31EF14_name_49 = NULL;
    for (i = 0; i < 2; i++) {
        D_80114A68_31EF18_name_49[i] = NULL;
        func_801067A8_310C58_name_49(i);
    }
}

void func_80106964_310E14_name_49(void) {
    HuPrcSleep(D_80112DF4_31D2A4_name_49[GwSystem.current_board_index]);
    PlaySound((s16)D_80112DD0_31D280_name_49[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_801069C0_310E70_name_49(s32 arg0) {
    func_80029E80_2AA80(D_80114A68_31EF18_name_49[arg0]->obj->model[0], 5, 0);
    if (D_80112DAC_31D25C_name_49[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80112DAC_31D25C_name_49[GwSystem.current_board_index]);
    }
    if (D_80112DD0_31D280_name_49[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80106964_310E14_name_49, 0x1000, 0, 0);
    }
}

void func_80106A64_310F14_name_49(s32 arg0) {
    func_80029E80_2AA80(D_80114A68_31EF18_name_49[arg0]->obj->model[0], 1, 4);
    if (D_80112E18_31D2C8_name_49[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80112E18_31D2C8_name_49[GwSystem.current_board_index]);
    }
}

void func_80106AD0_310F80_name_49(void) {
    func_80041B60_42760(9, &GetSpaceData(D_80112E3C_31D2EC_name_49)->coords, D_80112CD0_31D180_name_49[0],
                        D_80112CD0_31D180_name_49[1]);
}

void func_80106B0C_310FBC_name_49(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80041B60_42760(13, &GetSpaceData(D_80112E40_31D2F0_name_49[i])->coords, D_80112CDC_31D18C_name_49[i][0],
                            D_80112CDC_31D18C_name_49[i][1]);
    }
}

void func_80106B84_311034_name_49(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80041B60_42760(14, &GetSpaceData(D_80112E48_31D2F8_name_49[i])->coords, D_80112CE8_31D198_name_49[i][0],
                            D_80112CE8_31D198_name_49[i][1]);
    }
}

void func_80106BF8_3110A8_name_49(s16 arg0) {
    MBModel* obj;

    if (D_80114A74_31EF24_name_49[arg0] == NULL) {
        if (D_80114A70_31EF20_name_49 == NULL) {
            obj = func_80043510_44110(0x90, NULL);
            func_80043DAC_449AC(obj);
            D_80114A70_31EF20_name_49 = obj;
        } else {
            obj = MBModelParamCreate(D_80114A70_31EF20_name_49);
        }
        D_80114A74_31EF24_name_49[arg0] = obj;
        obj->attr |= 2;
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80112E4C_31D2FC_name_49[arg0])->coords);
        obj->rot.x = HuMathSin(D_80112E54_31D304_name_49[arg0][D_800F8CE4_F98E4[arg0 + 1]]);
        obj->rot.z = func_800B7890_B8490(D_80112E54_31D304_name_49[arg0][D_800F8CE4_F98E4[arg0 + 1]]);
    } else {
        MBModelDispOn(D_80114A74_31EF24_name_49[arg0]);
    }
}

void func_80106D34_3111E4_name_49(void) {
    s32 i;

    D_80114A70_31EF20_name_49 = NULL;
    for (i = 0; i < 3; i++) {
        D_80114A74_31EF24_name_49[i] = NULL;
        func_80106BF8_3110A8_name_49(i);
    }
}

void func_80106D94_311244_name_49(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103F1C_30E3CC_name_49();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80113334_31D7E4_name_49);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_8011322C_31D6DC_name_49;
        } else {
            tree = D_80112EFC_31D3AC_name_49;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103FEC_30E49C_name_49();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 6, 0);
    }
    omDelPrcObj(NULL);
}

void func_80106EAC_31135C_name_49(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103F1C_30E3CC_name_49();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_8011334C_31D7FC_name_49);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80113274_31D724_name_49;
        } else {
            tree = D_80112FC8_31D478_name_49;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103FEC_30E49C_name_49();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 12, 0);
    } else {
        SetNextChainAndSpace(-1, 7, 0);
    }
    omDelPrcObj(NULL);
}

void func_80106FC4_311474_name_49(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103F1C_30E3CC_name_49();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80113364_31D814_name_49);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_801132B0_31D760_name_49;
        } else {
            tree = D_801130AC_31D55C_name_49;
        }
        n = (s16)func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103FEC_30E49C_name_49();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 0xD, 0);
    } else {
        SetNextChainAndSpace(-1, 0xF, 0);
    }
}

void func_801070D4_311584_name_49(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103F1C_30E3CC_name_49();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_8011336C_31D81C_name_49);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80113304_31D7B4_name_49;
        } else {
            tree = D_8011316C_31D61C_name_49;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103FEC_30E49C_name_49();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 9, 0);
    } else {
        SetNextChainAndSpace(-1, 10, 0);
    }
    omDelPrcObj(NULL);
}

s32 func_801071EC_31169C_name_49(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80044800_45400(arg0 == 0 ? D_8011338C_31D83C_name_49 : D_801133B0_31D860_name_49) + 1;
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

void func_8010744C_3118FC_name_49(void) {
    GW_SYSTEM* gw = &GwSystem;
    struct unk_8003B8D4Struct* prompt;
    void* cam;
    s32 choice;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    if (gPlayers[gw->current_player_index].item == 1) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x71);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801071EC_31169C_name_49(0);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801069C0_310E70_name_49(0);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103F1C_30E3CC_name_49();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80113384_31D834_name_49);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80113208_31D6B8_name_49;
                } else {
                    tree = D_801131B4_31D664_name_49;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103FEC_30E49C_name_49();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 5, 0);
            } else {
                SetNextChainAndSpace(-1, 3, 0);
                func_80106A64_310F14_name_49(0);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 3, 0);
            break;
        case 2:
            func_80103DBC_30E26C_name_49();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 3, 0);
    }
    omDelPrcObj(NULL);
}

void func_80107744_311BF4_name_49(void) {
    GW_SYSTEM* gw = &GwSystem;
    struct unk_8003B8D4Struct* prompt;
    void* cam;
    s32 choice;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    if (gPlayers[gw->current_player_index].item == 1) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x72);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801071EC_31169C_name_49(1);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801069C0_310E70_name_49(1);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103F1C_30E3CC_name_49();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_801133CC_31D87C_name_49);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80113208_31D6B8_name_49;
                } else {
                    tree = D_801131F0_31D6A0_name_49;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103FEC_30E49C_name_49();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 0x11, 0);
            } else {
                SetNextChainAndSpace(-1, 0x10, 0);
                func_80106A64_310F14_name_49(1);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 0x10, 0);
            break;
        case 2:
            func_80103DBC_30E26C_name_49();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 0x10, 0);
    }
    omDelPrcObj(NULL);
}

void func_80107A3C_311EEC_name_49(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107A60_311F10_name_49(void) {
    SetNextChainAndSpace(-1, 4, 0);
}

void func_80107A84_311F34_name_49(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_80107AA8_311F58_name_49(void) {
    SetNextChainAndSpace(-1, 6, 3);
}

void func_80107ACC_311F7C_name_49(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_80107AF0_311FA0_name_49(void) {
    SetNextChainAndSpace(-1, 8, 0);
}

void func_80107B14_311FC4_name_49(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107B38_311FE8_name_49(void) {
    SetNextChainAndSpace(-1, 6, 3);
}

void func_80107B5C_31200C_name_49(void) {
    SetNextChainAndSpace(-1, 4, 0);
}

void func_80107B80_312030_name_49(void) {
    SetNextChainAndSpace(-1, 14, 0);
}

void func_80107BA4_312054_name_49(void) {
    SetNextChainAndSpace(-1, 8, 0);
}

void func_80107BC8_312078_name_49(void) {
    SetNextChainAndSpace(-1, 12, 3);
}

void func_80107BEC_31209C_name_49(void) {
    SetNextChainAndSpace(-1, 17, 4);
}

void func_80107C10_3120C0_name_49(void) {
    MBModel* obj;
    f32 scale;
    f32 rot;

    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800F64C8_F70C8->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;
    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    func_801062F8_3107A8_name_49();
    D_800F8D12_F9912 = 0;
    ChangeSpaceTextures(0);
    func_80106210_3106C0_name_49();
    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

__asm__(".section .rodata");
const char D_801147D8_31EC88_name_49[] = "%d";

#ifdef NON_MATCHING
void func_80107E10_3122C0_name_49(void) {
    GW_SYSTEM* gw;
    s16 space;
    s32 bank;
    s32 choice;
    s32 roll;
    char buf[16];

    space = func_800558F4_564F4();
    gw = &GwSystem;
    bank = 0;
    if (gw->current_player_index != 4) {
        if ((s16)func_80102C3C_30D0EC_name_49((s16)space) == 1) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, func_80102830_30CCE0_name_49());
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                buf[0] = 0x18;
                buf[1] = gPlayers[gw->current_player_index].character;
                buf[2] = 0;
                func_80056368_56F68(3, 0x231, buf, 0, 0, 0, 0);
                func_80056458_57058();
                MBDlgWinClose();
                func_80056168_56D68();
            } else {
            intro:
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22C);
                }
            }
            if (gPlayers[gw->current_player_index].stars >= 99) {
                PlaySound(0x120);
                MBDlgWinExec(3, 0x22B);
                if (D_800CCC16 != 0) {
                    func_800114E8_120E8(D_800F64B0_F70B0, 60);
                    D_800F64B0_F70B0 = -1;
                }
                goto end;
            }
            if (gPlayers[gw->current_player_index].coins >= 20) {
                PlaySound(0x11E);
            loop:
                MBDlgWinCreate(3, 0x227);
                choice = func_8010452C_30E9DC_name_49();
                MBDlgWinClose();
                func_80056168_56D68();
                switch ((s16)choice) {
                case 0:
                    func_8004CA34_4D634(gw->current_player_index, -20);
                    func_800614B4_620B4(gw->current_player_index, -20);
                    HuPrcSleep(30);
                    if (bank == 0) {
                        MBDlgWinExec(3, 0x229);
                        if (D_800CCC16 != 0) {
                            func_80079464_7A064();
                            func_800114E8_120E8(D_800F64B0_F70B0, 60);
                            D_800F64B0_F70B0 = -1;
                        } else {
                            func_800794A8_7A0A8(90);
                        }
                        func_80103920_30DDD0_name_49(D_801149F0_31EEA0_name_49);
                        func_800573AC_57FAC();
                        func_8006706C_67C6C(2);
                        return;
                    }
                    MBDlgWinExec(3, 0x22D);
                    func_80107C10_3120C0_name_49();
                    HuPrcSleep(30);
                    func_8010399C_30DE4C_name_49(D_800F64C8_F70C8);
                    MBDlgWinExec(5, 0x22E);
                    goto end;
                case 1:
                    if (D_800CCC16 != 0) {
                        func_800114E8_120E8(D_800F64B0_F70B0, 60);
                        D_800F64B0_F70B0 = -1;
                    }
                    MBDlgWinExec(3, 0x22A);
                    goto end;
                case 2:
                    func_80103DBC_30E26C_name_49();
                    goto loop;
                }
            } else {
                PlaySound(0x120);
                MBDlgWinExec(3, 0x228);
                if (D_800CCC16 != 0) {
                    func_800114E8_120E8(D_800F64B0_F70B0, 60);
                    D_800F64B0_F70B0 = -1;
                }
                goto end;
            }
        } else if ((s16)func_80102C3C_30D0EC_name_49((s16)space) == 2) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, D_80112C68_31D118_name_49[gw->unk_1C]);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (D_800F8D12_F9912 == 0) {
                PlaySound(0x363);
            }
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22F);
                    func_80107C10_3120C0_name_49();
                    HuPrcSleep(30);
                    MBDlgWinExec(5, 0x230);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else if (D_800F8D18[0] == 0) {
                    MBDlgWinExec(5, 0x427);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else {
                    sprintf(buf, D_801147D8_31EC88_name_49, D_800F8D18[0]);
                    func_80056368_56F68(5, 0x426, buf, 0, 0, 0, 0);
                    func_80056458_57058();
                    MBDlgWinClose();
                    func_80056168_56D68();
                    func_8004CA34_4D634(gw->current_player_index, D_800F8D18[0]);
                    func_800614B4_620B4(gw->current_player_index, D_800F8D18[0]);
                    D_800F8D18[0] = 0;
                }
                HuPrcSleep(30);
            } else {
                bank = 1;
                if (D_800F8D12_F9912 != 0) {
                    goto intro;
                }
                if (gPlayers[gw->current_player_index].coins == 0) {
                    MBDlgWinExec(5, 0x422);
                } else {
                    MBDlgWinExec(5, 0x421);
                    func_80059120_59D20(D_800F64C8_F70C8, 2.0f, -0.5f);
                    func_80059158_59D58(D_800F64C8_F70C8);
                    func_80059120_59D20(D_800F64C8_F70C8, 2.0f, -0.5f);
                    func_80059158_59D58(D_800F64C8_F70C8);
                    roll = func_80103EC8_30E378_name_49();
                    if (roll >= D_801134B4_31D964_name_49[func_80059FD0_5ABD0(gw->current_player_index)]) {
                        if (gPlayers[gw->current_player_index].coins >= 5) {
                            MBDlgWinExec(5, 0x423);
                            D_800F8D18[0] += 5;
                            func_8004CA34_4D634(gw->current_player_index, -5);
                            func_800614B4_620B4(gw->current_player_index, -5);
                        } else {
                            sprintf(buf, D_801147D8_31EC88_name_49, gPlayers[gw->current_player_index].coins);
                            func_80056368_56F68(5, 0x425, buf, 0, 0, 0, 0);
                            MBDlgWinClose();
                            func_80056168_56D68();
                            D_800F8D18[0] += gPlayers[gw->current_player_index].coins;
                            func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                            func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                        }
                        HuPrcSleep(30);
                    } else {
                        func_80056368_56F68(5, 0x424, NULL, 0, 0, 0, 0);
                        MBDlgWinClose();
                        func_8004CA34_4D634(gw->current_player_index, 5);
                        func_800614B4_620B4(gw->current_player_index, 5);
                        HuPrcSleep(30);
                        func_80056124_56D24();
                        func_80056458_57058();
                        MBDlgWinClose();
                        func_80056168_56D68();
                    }
                }
            }
        end:
            func_8004655C_4715C(gw->current_player_index);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
            HuPrcChildWatch();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80107E10_3122C0_name_49);
#endif

/* Bowser Land's Koopa Bank, Bowser's version: passing the space lends the player 5 coins (20
   if turn_status is set) and adds them to the debt D_800F8CE4[0x1D]; landing on it repays the
   whole debt (all coins when short, else a star, else nothing). */
/* Bowser Land's Koopa Bank, Bowser's version: passing the space lends the player 5 coins (20
   if turn_status is set) and adds them to the debt D_800F8D1A[2] (D_800F8CE4[0x1D]); landing on it repays the
   whole debt (all coins when short, else a star, else nothing). */
/* Bowser Land's Koopa Bank, Bowser's version: passing the space lends the player 5 coins (20
   if turn_status is set) and adds them to the debt D_800F8D1A[2] (D_800F8CE4[0x1D]); landing on it repays the
   whole debt (all coins when short, else a star, else nothing). */
/* Bowser Land's Koopa Bank, Bowser's version: passing the space lends the player 5 coins (20
   if turn_status is set) and adds them to the debt D_800F8D1A[2] (D_800F8CE4[0x1D]); landing on it repays the
   whole debt (all coins when short, else a star, else nothing). */
void func_80108650_312B00_name_49(void) {
    char buf[16];
    s32 space;
    SpaceData* data;
    s32 i;
    GW_SYSTEM* gw;

    i = 0;
    space = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index == 4) {
        return;
    }
    if (func_80047DE8_489E8(gw->current_player_index) <= 0) {
        MBPlayerVibrate(-1, 4);
    }
    MBPlayerMotionSet(-1, -1, 2);
    switch ((s16)space) {
        case 0x2C:
            i = 0;
            break;
        case 0x44:
            i = 1;
            break;
        case 0x31:
            i = 2;
            break;
    }
    data = GetSpaceData(D_801134C8_31D978_name_49[i]);
    func_80056C30_57830(-1, 8, D_801134C8_31D978_name_49[i]);
    HuPrcSleep(8);
    PlaySound(0x363);
    if (func_80047DE8_489E8(gw->current_player_index) <= 0) {
        sprintf(buf, D_801147D8_31EC88_name_49, D_800F8D1A_F991A[2]);
        if (D_800F8D1A_F991A[2] == 0) {
            MBDlgWinExec(0x1F, 0x243);
            return;
        }
        if (gPlayers[gw->current_player_index].coins == 0) {
            if (gPlayers[gw->current_player_index].stars != 0) {
                func_80056368_56F68(0x1F, 0x241, buf, 0, 0, 0, 0);
                func_80056458_57058();
                MBDlgWinClose();
                func_80056168_56D68();
                D_800F8D1A_F991A[2] = 0;
                func_801064C0_310970_name_49();
                func_80103D28_30E1D8_name_49(BoardPlayerGet(-1)->unk_24, &data->coords);
                return;
            }
            func_80056368_56F68(0x1F, 0x242, buf, 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
            D_800F8D1A_F991A[2] = 0;
            func_801064C0_310970_name_49();
            func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
            MBPlayerMotionSet(-1, 5, 0);
            func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
            HuPrcSleep(50);
            return;
        }
        if (gPlayers[gw->current_player_index].coins < D_800F8D1A_F991A[2]) {
            func_80056368_56F68(0x1F, 0x240, buf, 0, 0, 0, 0);
            MBDlgWinClose();
            D_800F8D1A_F991A[2] = 0;
            MBPlayerMotionSet(-1, 3, 0);
            func_801064C0_310970_name_49();
            func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
            func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
        } else {
            func_80056368_56F68(0x1F, 0x23F, buf, 0, 0, 0, 0);
            MBDlgWinClose();
            func_8004CA34_4D634(gw->current_player_index, -D_800F8D1A_F991A[2]);
            func_800614B4_620B4(gw->current_player_index, -D_800F8D1A_F991A[2]);
            D_800F8D1A_F991A[2] = 0;
            MBPlayerMotionSet(-1, 3, 0);
            func_801064C0_310970_name_49();
        }
        func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
        func_80079718_7A318(0xFC, gPlayers[gw->current_player_index].character);
        HuPrcSleep(30);
        func_80056124_56D24();
        func_80056458_57058();
        MBDlgWinClose();
        func_80056168_56D68();
        return;
    }
    func_80046D2C_4792C(gw->current_player_index);
    if (gPlayers[gw->current_player_index].turn_status == 0) {
        D_800F8D1A_F991A[2] += 5;
        sprintf(buf, D_801147D8_31EC88_name_49, D_800F8D1A_F991A[2]);
        func_80056368_56F68(0x1F, 0x23E, buf, 0, 0, 0, 0);
        MBDlgWinClose();
        func_8004CA34_4D634(gw->current_player_index, 5);
        func_800614B4_620B4(gw->current_player_index, 5);
        func_801064C0_310970_name_49();
        HuPrcSleep(30);
        func_80056124_56D24();
        func_80056458_57058();
        MBDlgWinClose();
        func_80056168_56D68();
    } else {
        D_800F8D1A_F991A[2] += 20;
        sprintf(buf, D_801147D8_31EC88_name_49, D_800F8D1A_F991A[2]);
        func_80056368_56F68(0x1F, 0x244, buf, 0, 0, 0, 0);
        func_80056458_57058();
        MBDlgWinClose();
        func_80056168_56D68();
        func_8004CA34_4D634(gw->current_player_index, 20);
        func_800614B4_620B4(gw->current_player_index, 20);
        func_801064C0_310970_name_49();
        HuPrcSleep(30);
    }
    func_8004655C_4715C(gw->current_player_index);
}

s32 func_80108BF0_3130A0_name_49(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_80114A84_31EF34_name_49[i] != 0) {
            if (D_801134F8_31D9A8_name_49[D_80114A80_31EF30_name_49][i] == arg0) {
                return i;
            }
        }
    }
    return -1;
}

s32 func_80108C5C_31310C_name_49(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801134F8_31D9A8_name_49[D_80114A80_31EF30_name_49][i] == -1) {
            break;
        }
    }
    return i;
}

#ifdef NON_MATCHING
void func_80108CA8_313158_name_49(void) {
    u8 enabled[8];
    char names[5][4];
    Vec rot;
    GW_SYSTEM* gw = &GwSystem;
    GW_PLAYER* player;
    s8* item;
    void* data;
    s32 choice;
    s32 sel;
    s32 count;
    s32 band;
    s32 shop;
    s32 i;
    s16 spr;
    s16 anim;

    player = BoardPlayerGet(-1);
    if (gw->current_player_index != 4) {
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x64);
        HuPrcSleep(8);
        func_80046D2C_4792C(gw->current_player_index);
        PlaySound(0xE6);
        if (gw->current_turn == gw->total_turns) {
            MBDlgWinExec(1, 0x1F9);
        } else if (gPlayers[gw->current_player_index].item != -1) {
            MBDlgWinExec(1, 0x1F0);
        } else if (gPlayers[gw->current_player_index].coins < 10) {
            MBDlgWinExec(1, 0x1EF);
        } else {
        loop:
            MBDlgWinCreate(1, 0x1EE);
            choice = func_80104308_30E7B8_name_49();
            MBDlgWinClose();
            func_80056168_56D68();
            switch (choice) {
            case 0:
            shop:
                for (band = 0; band < 2; band++) {
                    if (gw->current_turn >= D_801134EC_31D99C_name_49[gw->current_game_length][band] &&
                        gw->current_turn < D_801134EC_31D99C_name_49[gw->current_game_length][band + 1]) {
                        break;
                    }
                }
                count = 0;
                shop = D_801134E0_31D990_name_49[band][func_80059FD0_5ABD0(gw->current_player_index)];
                for (i = 0; i < 5; i++) {
                    enabled[i] = 1;
                    names[i][0] = 0;
                    if (D_801134F8_31D9A8_name_49[shop][i] != -1) {
                        if (D_800CC000[D_801134F8_31D9A8_name_49[shop][i]] > gPlayers[gw->current_player_index].coins) {
                            enabled[i] = 0;
                            names[i][0] = 1;
                        }
                        names[i][1] = 0;
                        count++;
                    }
                }
                for (; i < 8; i++) {
                    enabled[i] = 1;
                }
                func_8008DAC0_8E6C0(0x28);
                func_80056524_57124(0x28);
                func_80056368_56F68(1, D_8011351C_31D9CC_name_49[shop], names[0], names[1], names[2],
                                    names[3], names[4]);
                func_80056524_57124(0);
                D_80114A80_31EF30_name_49 = shop;
                D_80114A84_31EF34_name_49 = enabled;
                sel = func_8010404C_30E4FC_name_49(enabled);
                MBDlgWinClose();
                func_80056168_56D68();
                if (sel == count) {
                    D_800FC734_FD334 = 0;
                    MBItemDescExec(gw->current_player_index);
                    D_800FC734_FD334 = 1;
                    goto shop;
                }
                if ((sel == count + 1) | (sel == -1)) {
                    goto loop;
                }
                item = &D_801134F8_31D9A8_name_49[shop][sel];
                func_8004CA34_4D634(gw->current_player_index, -D_800CC000[*item]);
                func_800614B4_620B4(gw->current_player_index, -D_800CC000[*item]);
                HuPrcSleep(30);
                gPlayers[gw->current_player_index].item = *item;
                spr = SprCreate(1, 5);
                data = DataRead(D_800CCBDC_CD7DC[*item]);
                anim = SprAnimRead(data);
                DataClose(data);
                SprAnimSet(spr, 0, anim, 0);
                SprPrioSet(spr, 0, 10);
                func_8008225C_82E5C(spr, 0, 0);
                SprAttrSet(spr, 0, 0x1000);
                SprPosSet(spr, 0, 160, 90);
                func_80082488_83088(spr, 0, 0);
                func_8005670C_5730C(&rot);
                func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 10);
                PlaySound(0x19);
                for (i = 0; i < 10; i++) {
                    func_80082488_83088(spr, 0, i * 25);
                    HuPrcVSleep();
                }
                func_80082488_83088(spr, 0, 0x100);
                MBPlayerMotionSet(-1, 5, 0);
                HuPrcSleep(5);
                func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
                HuPrcSleep(45);
                MBPlayerMotionSet(-1, -1, 2);
                HuPrcSleep(10);
                SprAnimKill(anim);
                SprKill(spr);
                break;
            case 1:
                MBDlgWinExec(1, 0x1F1);
                break;
            case 2:
                func_80103DBC_30E26C_name_49();
                goto loop;
            }
        }
        func_8004655C_4715C(gw->current_player_index);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80108CA8_313158_name_49);
#endif

void func_801092B4_313764_name_49(MBModel* model) {
    s32 i;

    MBModelDispOn(model);
    for (i = 0; i < 256; i += 12, HuPrcVSleep()) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0xFF);
}

void func_80109354_313804_name_49(MBModel* model) {
    s32 i;

    for (i = 0xFF; i >= 0; i -= 0xC) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
        HuPrcVSleep();
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0);
    MBModelDispOff(model);
}

#ifdef NON_MATCHING /* NON_MATCHING: float register allocation in the two sine loops (raw 58) */
/* A star flies out of the player's status window (player -1: of every other player that has
   one) and the player loses it. */
s32 func_801093F4_3138A4_name_49(s32 player) {
    s16 sprites[4];
    s32 sprite;
    void* data;
    s32 anim;
    s32 anim2;
    s32 k;
    s32 i;
    s32 j;
    s32 count;
    f32 y;

    if (player == -1) {
        data = DataRead(0xA000B);
        anim = SprAnimRead_s32(data);
        DataClose(data);
        for (i = 0; i < 4; i++) {
            if (i == GwSystem.current_player_index || gPlayers[i].stars == 0) {
                sprites[i] = -1;
            } else {
                SprAnimSet(sprites[i] = SprCreate_s32(1, 5), 0, anim, 0);
                SprPrioSet(sprites[i], 0, 10);
                func_8008225C_82E5C(sprites[i], 0, 0);
                SprAttrSet(sprites[i], 0, 0x1000);
                SprPosSet(sprites[i], 0, D_80113554_31DA04_name_49[i].x, D_80113554_31DA04_name_49[i].y);
                func_80082488_83088(sprites[i], 0, 0);
            }
        }
        PlaySound(0x377);
        for (j = 0; j < 17; j++) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_80113574_31DA24_name_49[i].x + D_80113554_31DA04_name_49[i].x,
                              j * D_80113574_31DA24_name_49[i].y + D_80113554_31DA04_name_49[i].y);
                    func_80082488_83088(sprites[i], 0, j * 16);
                }
            }
            HuPrcVSleep();
        }
        count = 0;
        for (i = 0; i < 4; i++) {
            if (sprites[i] != -1) {
                func_80082488_83088(sprites[i], 0, 255);
                gPlayers[i].stars--;
                count++;
                MBPlayerVibrate(i, 5);
            }
        }
        PlaySound(0xE4);
        for (j = 0; j < 30; j++) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    y = D_80113574_31DA24_name_49[i].y * 16.0f + D_80113554_31DA04_name_49[i].y;
                    SprPosSet(sprites[i], 0, D_80113574_31DA24_name_49[i].x * 16.0f + D_80113554_31DA04_name_49[i].x,
                              y + 2.0f * __sinf(j * 90 * (M_PI / 180.0)));
                }
            }
            HuPrcVSleep();
        }
        for (j = 16; j >= 0; j--) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_80113574_31DA24_name_49[i].x + D_80113554_31DA04_name_49[i].x,
                              j * D_80113574_31DA24_name_49[i].y + D_80113554_31DA04_name_49[i].y);
                    func_80082488_83088(sprites[i], 0, j * 16);
                }
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            if (sprites[i] != -1) {
                SprKill(sprites[i]);
            }
        }
        SprAnimKill(anim);
        return count;
    } else {
        sprite = SprCreate_s32(1, 5);
        data = DataRead(0xA000B);
        anim2 = SprAnimRead_s32(data);
        DataClose(data);
        SprAnimSet(sprite, 0, anim2, 0);
        SprPrioSet(sprite, 0, 10);
        func_8008225C_82E5C(sprite, 0, 0);
        SprAttrSet(sprite, 0, 0x1000);
        SprPosSet(sprite, 0, D_80113554_31DA04_name_49[player].x, D_80113554_31DA04_name_49[player].y);
        func_80082488_83088(sprite, 0, 0);
        PlaySound(0x377);
        for (k = 0; k < 17; k++) {
            SprPosSet(sprite, 0, k * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x,
                      k * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        func_80082488_83088(sprite, 0, 255);
        gPlayers[player].stars--;
        MBPlayerVibrate(player, 5);
        PlaySound(0xE4);
        for (k = 0; k < 30; k++) {
            y = D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y;
            SprPosSet(sprite, 0, D_80113574_31DA24_name_49[player].x * 16.0f + D_80113554_31DA04_name_49[player].x,
                      y + 2.0f * __sinf(k * 90 * (M_PI / 180.0)));
            HuPrcVSleep();
        }
        for (k = 16; k >= 0; k--) {
            SprPosSet(sprite, 0, k * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x,
                      k * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        SprKill(sprite);
        SprAnimKill(anim2);
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_801093F4_3138A4_name_49);
#endif

void func_80109CD0_314180_name_49(void) {
    func_80055E60_56A60();
    omDelPrcObj(NULL);
}

#ifdef NON_MATCHING /* NON_MATCHING */
/* A star hangs above the player's status window for 150 frames while the player (or the CPU, by
   difficulty) presses A; then it returns to the window or leaves. Returns the price from the turn
   and press tables, or -1 when the player cannot pay it. */
s32 func_80109CF4_3141A4_name_49(s32 player) {
    char msg[16];
    u16 star;
    u16 starAnim;
    u16 portrait;
    u16 portraitAnim;
    void* data;
    void* vib;
    s32 i;
    s32 state;
    s16 timer;
    s32 presses;
    s32 shown;
    s32 t;
    s32 frame;
    u16 alpha;
    f32 x;
    f32 y;
    f32 angle;
    s32 price;
    u32 j;

    star = SprCreate_s32(1, 5);
    data = DataRead(0xA000B);
    starAnim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(star, 0, starAnim, 0);
    SprPrioSet(star, 0, 10);
    func_8008225C_82E5C(star, 0, 0);
    SprAttrSet(star, 0, 0x1000);
    SprPosSet(star, 0, D_80113554_31DA04_name_49[player].x, D_80113554_31DA04_name_49[player].y);
    func_80082488_83088(star, 0, 0);
    portrait = SprCreate_s32(1, 5);
    shown = 0;
    data = DataRead(D_80113594_31DA44_name_49[gPlayers[player].character]);
    portraitAnim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(portrait, 0, portraitAnim, 0);
    SprPrioSet(portrait, 0, 10);
    func_8008225C_82E5C(portrait, 0, 1);
    if (player & 1) {
        SprAttrSet(portrait, 0, 0x1001);
    } else {
        SprAttrSet(portrait, 0, 0x1000);
    }
    SprPosSet(portrait, 0, D_80113554_31DA04_name_49[player].x - D_80113574_31DA24_name_49[player].x * 16.0f - 8.0f,
              D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y);
    func_80082488_83088(portrait, 0, 0);
    for (i = 0; i < 17; i++) {
        SprPosSet(star, 0, i * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x,
                  i * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
        alpha = i * 16;
        func_80082488_83088(star, 0, alpha);
        func_80082488_83088(portrait, 0, alpha);
        HuPrcVSleep();
    }
    func_80082488_83088(star, 0, 255);
    func_80082488_83088(portrait, 0, 255);
    msg[0] = 0x18;
    msg[1] = gPlayers[player].character;
    msg[2] = 0;
    MBWinInsertOpen(0x6BA, msg, 0, 0, 0, 0);
    MBPlayerVibrate(player, 2);
    func_80055E3C_56A3C(player);
    presses = 0;
    state = 0;
    PlaySound(0x376);
    vib = func_800672BC_67EBC(player, 3, 5);
    timer = MBRand(10.0f) + 1;
    frame = 0;
    for (i = 0; i < 150; i++) {
        if (timer == 0) {
            PlaySound(0xE4);
            timer = MBRand(15.0f) + 30;
        }
        if (state >= 2) {
            state--;
        }
        if (state == 0) {
            y = D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y;
            SprPosSet(star, 0, D_80113574_31DA24_name_49[player].x * 16.0f + D_80113554_31DA04_name_49[player].x,
                      y + 2.0f * __sinf(i * 90 * (M_PI / 180.0)));
        } else if (state == 9) {
            x = D_80113574_31DA24_name_49[player].x * 16.0f + D_80113554_31DA04_name_49[player].x;
            angle = frame * 90 * (M_PI / 180.0);
            SprPosSet(star, 0, x + 2.0f * __sinf(angle),
                      D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y);
            x = D_80113554_31DA04_name_49[player].x - 8.0f;
            SprPosSet(portrait, 0, x + 2.0f * __sinf(angle),
                      D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y);
            frame++;
        }
        if (gPlayers[player].flags & 1) {
            if (state == 0) {
                goto press;
            }
            if (gPlayers[player].cpu_difficulty2 == 0) {
                if (state < 7) {
                    goto press;
                }
            } else if (gPlayers[player].cpu_difficulty2 == 1) {
                if (state < 8) {
                    goto press;
                }
            } else if (state < 10) {
                goto press;
            }
        } else if (ContDStkTrg[gPlayers[player].port] & 0x8000) {
        press:
            presses++;
            state = 10;
            if (shown == 0) {
                func_800822A8_82EA8(portrait, 0, 1, 0);
                func_8008225C_82E5C(portrait, 0, 1);
                shown = 1;
                SprPosSet(portrait, 0, D_80113554_31DA04_name_49[player].x - 8.0f,
                          D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y);
            }
        }
        if ((state == 0) & (t = (shown == 1))) {
            func_800822A8_82EA8(portrait, 0, 0, 0);
            func_8008225C_82E5C(portrait, 0, 1);
            shown = 0;
            SprPosSet(portrait, 0, D_80113554_31DA04_name_49[player].x - D_80113574_31DA24_name_49[player].x * 16.0f - 8.0f,
                      D_80113574_31DA24_name_49[player].y * 16.0f + D_80113554_31DA04_name_49[player].y);
        }
        HuPrcVSleep();
        timer--;
    }
    func_8006735C_67F5C(vib);
    omAddPrcObj(func_80109CD0_314180_name_49, 0x1000, 0, 0);
    if (presses == 0) {
        for (i = 16; i >= 0; i -= 2) {
            SprPosSet(star, 0, i * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x,
                      i * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
            alpha = i * 16;
            func_80082488_83088(star, 0, alpha);
            func_80082488_83088(portrait, 0, alpha);
            HuPrcVSleep();
        }
    } else {
        for (i = 16; i >= -16; i -= 2) {
            SprPosSet(star, 0, i * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x,
                      i * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
            SprPosSet(portrait, 0,
                      (i - 16) * D_80113574_31DA24_name_49[player].x + D_80113554_31DA04_name_49[player].x - 8.0f,
                      i * D_80113574_31DA24_name_49[player].y + D_80113554_31DA04_name_49[player].y);
            HuPrcVSleep();
        }
        func_800822A8_82EA8(portrait, 0, 0, 0);
        func_8008225C_82E5C(portrait, 0, 1);
        for (i = 16; i >= 0; i -= 2) {
            func_80082488_83088(star, 0, i * 16);
            HuPrcVSleep();
        }
    }
    SprKill(star);
    SprAnimKill(starAnim);
    SprKill(portrait);
    SprAnimKill(portraitAnim);
    for (j = 0; j < 6; j++) {
        if (GwSystem.current_turn >= D_801135AC_31DA5C_name_49[j].min && GwSystem.current_turn <= D_801135AC_31DA5C_name_49[j].max) {
            break;
        }
    }
    price = D_801135AC_31DA5C_name_49[j].value;
    for (j = 0; j < 14; j++) {
        if (presses >= D_801135C0_31DA70_name_49[j].min && presses <= D_801135C0_31DA70_name_49[j].max) {
            break;
        }
    }
    price -= D_801135C0_31DA70_name_49[j].value;
    if (price >= gPlayers[player].coins) {
        price = -1;
    }
    return price;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80109CF4_3141A4_name_49);
#endif

void func_8010AA30_314EE0_name_49(void) {
    MBModel* model;
    f32 angle;
    MBModel* parent;

    parent = HuPrcCurrentGet()->user_data;
    model = MBModelParamCreate(D_80114A88_31EF38_name_49);
    func_800B3170_B3D70(&model->pos, &parent->pos);
    HuVecCopyXYZ(&model->scale, 2.0f, 2.0f, 2.0f);
    model->jumpY = parent->jumpY + 10.0f;
    MBModelDispOn(model);
    angle = MBRand(360.0f);
    while (1) {
        HuPrcVSleep();
        model->jumpY += 1.5;
        if ((parent->jumpY + 35.0f) <= model->jumpY) {
            break;
        }
        angle += 40.0f;
        func_800B39F0_B45F0(D_800FC834_FD434[model->obj->model[0]].mtx, angle);
    }
    MBModelKill(model);
    omDelPrcObj(NULL);
}

Process* func_8010AB84_315034_name_49(void* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_8010AA30_314EE0_name_49, 0x1000, 0, 0);
    proc->user_data = arg0;
    return proc;
}

#ifdef NON_MATCHING /* NON_MATCHING */
/* Boo: for 5 coins steal coins (a minigame decides how many) or, for 50, a star from another
   player. Boo is one of the two board Boos (spaces 0xAF, 0xB4) or, elsewhere, a temporary one. */
void func_8010ABC0_315070_name_49(void) {
    char msgs[4][16];
    u8 items[4];
    s32 flag;
    s32 space;
    s32 boo;
    s16 cam;
    MBModel* model;
    SpaceData* spaceData;
    s16 choice;
    s16 sel;
    s32 i;
    s32 k;
    s32 amount;
    void* vib;
    f32 step;
    f32 acc;
    GW_SYSTEM* gw;

    space = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index == 4) {
        return;
    }
    choice = 0;
    flag = func_80046D2C_4792C(gw->current_player_index);
    MBPlayerMotionSet(-1, -1, 2);
    switch ((s16)space) {
    case 0x95:
        boo = 0;
        cam = 0x75;
        break;
    case 0x85:
        boo = 1;
        cam = 0x74;
        break;
    default:
        boo = -1;
        cam = -1;
        model = MBModelParamCreate(D_80114A14_31EEC4_name_49);
        MBModelDispOff(model);
        model->jumpY = 10.0f;
        spaceData = GetSpaceData(space);
        HuVecCopyXYZ(&model->pos, spaceData->coords.x, spaceData->coords.y + 10.0f, spaceData->coords.z);
        goto created;
    }
    model = D_80114A18_31EEC8_name_49[boo];
created:
    PlaySound(0xEB);
    func_801092B4_313764_name_49(model);
    spaceData = GetSpaceData(space);
    if (cam != -1) {
        func_800446B4_452B4(model, &spaceData->coords, 10);
        func_80056C30_57830(-1, 8, cam);
        HuPrcSleep(10);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
    }
    if (gPlayers[gw->current_player_index].coins < 5) {
        MBDlgWinExec(7, 0x6B6);
    } else {
    menu:
        for (i = 0; i < 4; i++) {
            if (i != gw->current_player_index && gPlayers[i].coins != 0) {
                break;
            }
        }
        if (i == 4) {
            msgs[0][0] = 1;
            items[0] = 0;
        } else {
            msgs[0][0] = 8;
            items[0] = 1;
        }
        msgs[0][1] = 0;
        for (i = 0; i < 4; i++) {
            if (i != gw->current_player_index && gPlayers[i].stars != 0) {
                break;
            }
        }
        if (i == 4 || gPlayers[gw->current_player_index].coins < 50 || gPlayers[gw->current_player_index].stars >= 99) {
            msgs[1][0] = 1;
            items[1] = 0;
        } else {
            msgs[1][0] = 8;
            items[1] = 1;
        }
        msgs[1][1] = 0;
        items[2] = items[3] = 1;
        func_80056368_56F68(7, 0x6B5, msgs[0], msgs[1], 0, 0, 0);
        choice = func_801056D4_30FB84_name_49(items);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
        case 1:
        menu2:
            for (i = 0, k = 0; i < 4; i++) {
                if (i == gw->current_player_index) {
                    continue;
                }
                if (choice == 0) {
                    if (gPlayers[i].coins != 0) {
                        items[k] = 1;
                        goto available;
                    }
                    goto unavailable;
                } else if (gPlayers[i].stars == 0) {
                unavailable:
                    items[k] = 0;
                    msgs[k][0] = 1;
                } else {
                    items[k] = 1;
                available:
                    msgs[k][0] = 8;
                }
                msgs[k][1] = 0x18;
                msgs[k][2] = gPlayers[i].character;
                msgs[k][3] = 0;
                k++;
            }
            items[3] = 1;
            func_80056368_56F68(7, 0x6B8, msgs[0], msgs[1], msgs[2], 0, 0);
            sel = func_80105988_30FE38_name_49(choice, items);
            MBDlgWinClose();
            func_80056168_56D68();
            if (sel == -1) {
                goto menu;
            }
            if (sel == 3) {
                if (boo == -1) {
                    func_80103E4C_30E2FC_name_49();
                    D_800F851A_F911A = 1;
                    func_80078EC8_79AC8();
                } else {
                    func_80103DBC_30E26C_name_49();
                }
                goto menu2;
            }
            if (choice == 0) {
                func_8004CA34_4D634(gw->current_player_index, -5);
                func_800614B4_620B4(gw->current_player_index, -5);
            } else {
                func_8004CA34_4D634(gw->current_player_index, -50);
                func_800614B4_620B4(gw->current_player_index, -50);
            }
            HuPrcSleep(30);
            func_80109354_313804_name_49(model);
            if (choice == 0) {
                amount = func_80109CF4_3141A4_name_49(D_80113548_31D9F8_name_49[gw->current_player_index][sel]);
                func_801092B4_313764_name_49(model);
                if (amount == -1) {
                    amount = gPlayers[D_80113548_31D9F8_name_49[gw->current_player_index][sel]].coins;
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, 0x6BF, msgs[0], 0, 0, 0, 0);
                } else {
                    for (i = 0; i < sizeof(D_801135EC_31DA9C_name_49) / sizeof(D_801135EC_31DA9C_name_49[0]); i++) {
                        if (gw->current_turn >= D_801135EC_31DA9C_name_49[i].turnMin
                            && gw->current_turn <= D_801135EC_31DA9C_name_49[i].turnMax
                            && amount >= D_801135EC_31DA9C_name_49[i].min && amount <= D_801135EC_31DA9C_name_49[i].max) {
                            break;
                        }
                    }
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, D_80113656_31DB06_name_49[D_801135EC_31DA9C_name_49[i].mess], msgs[0], 0,
                                        0, 0, 0);
                }
                MBDlgWinClose();
                func_80056168_56D68();
                step = amount / 90.0f;
                acc = 0.0f;
                D_80114A88_31EF38_name_49 = func_80043510_44110(0x18, NULL);
                func_80043DAC_449AC(D_80114A88_31EF38_name_49);
                MBModelDispOff(D_80114A88_31EF38_name_49);
                vib = func_800672BC_67EBC(D_80113548_31D9F8_name_49[gw->current_player_index][sel], 3, 5);
                while (amount != 0) {
                    acc += step;
                    if (acc >= 1.0f) {
                        acc -= 1.0f;
                        func_8010AB84_315034_name_49(model);
                        func_800614B4_620B4(gw->current_player_index, 1);
                        func_8006135C_61F5C(D_80113548_31D9F8_name_49[gw->current_player_index][sel], -1, 0);
                        amount--;
                    }
                    HuPrcVSleep();
                }
                func_8006735C_67F5C(vib);
                HuPrcSleep(20);
                MBModelKill(D_80114A88_31EF38_name_49);
                func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
                MBPlayerMotionSet(-1, 5, 0);
                HuPrcSleep(5);
                func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
                HuPrcSleep(45);
            } else {
                func_801093F4_3138A4_name_49(D_80113548_31D9F8_name_49[gw->current_player_index][sel]);
                func_801092B4_313764_name_49(model);
                D_80112C78_31D128_name_49 = 1;
                func_80103920_30DDD0_name_49(model);
                D_80112C78_31D128_name_49 = 0;
            }
            if (boo == -1) {
                MBPlayerMotionSet(-1, -1, 2);
            }
            break;
        case 2:
            func_80109354_313804_name_49(model);
            MBDlgWinExec(7, 0x6B7);
            break;
        case 3:
            if (boo == -1) {
                func_80103E4C_30E2FC_name_49();
                D_800F851A_F911A = 1;
                func_80078EC8_79AC8();
            } else {
                func_80103DBC_30E26C_name_49();
            }
            goto menu;
        }
    }
    if (choice != 2) {
        func_80109354_313804_name_49(model);
    }
    func_8005670C_5730C(&model->rot);
    if (boo == -1) {
        MBModelKill(model);
    }
    if (flag != 0) {
        func_8004655C_4715C(gw->current_player_index);
    }
    if (boo != -1) {
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_8010ABC0_315070_name_49);
#endif

void func_8010B5C0_315A70_name_49(void) {
    func_80106A64_310F14_name_49(0);
}

void func_8010B5DC_315A8C_name_49(void) {
    func_80106A64_310F14_name_49(1);
}

omObjData* func_8010B5F8_315AA8_name_49(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel) {
    MBModel* model;
    Unk3EParticle* work;
    omObjData* obj;

    obj = omAddObj(0x1F4, 0, 0, -1, func_8010B738_315BE8_name_49);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Unk3EParticle), 0x7918);
    work->alpha = 255.0f;
    work->scaleSpeed = scaleSpeed;
    work->fadeSpeed = fadeSpeed;
    func_800B3170_B3D70(&work->vel, vel);
    model = MBModelFileCreate(0xA015C, 0, 1.0f, 0.0f, NULL);
    func_800297E8_2A3E8(model->obj->model[0], 0.0f, 0.0f, 0.0f);
    model->pos.x = pos->x;
    model->pos.y = pos->y;
    model->pos.z = pos->z;
    func_8002D124_2DD24(model->obj->model[0]);
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    work->model = model;
    work->kill = kill;
    return obj;
}

void func_8010B738_315BE8_name_49(omObjData* obj) {
    MBModel* model;
    Unk3EParticle* work;
    f32 scale;

    work = obj->unk_50;
    model = work->model;
    HuVecAdd(&model->pos, &model->pos, &work->vel);
    scale = model->scale.z + work->scaleSpeed;
    model->scale.z = scale;
    model->scale.y = scale;
    model->scale.x = scale;
    work->alpha = work->alpha - work->fadeSpeed;
    if (work->alpha < 0.0f) {
        work->alpha = 0.0f;
        if (work->kill != 0) {
            MBModelKill(work->model);
            omDelObj(obj);
            return;
        }
        omSetStatBit(obj, 8);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], work->alpha);
}



void func_8010B850_315D00_name_49(void) {
    Vec pos;
    s16 chain;
    s16 index;
    GW_PLAYER* player;
    MBModel* lamp;
    void* vib;
    s32 angle;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    player = BoardPlayerGet(-1);
    func_8010C4F0_3169A0_name_49();
    lamp = func_80043510_44110(0x71, NULL);
    func_800297E8_2A3E8(lamp->obj->model[0], 0.0f, 0.0f, 0.0f);
    func_800B3170_B3D70(&lamp->pos, &((MBModel*)player->unk_24)->pos);
    for (lamp->pos.y = 100.0f; lamp->pos.y > 30.0f;) {
        lamp->pos.y -= 1.0f;
        HuPrcVSleep();
    }

    PlaySound(0x366);
    func_800114E8_120E8(D_800FA188_FAD88, 0xB4);
    vib = func_800672BC_67EBC(-1, 3, 5);

    angle = 0xB4;
    i = 0;
    while (angle < 0x438) {
        Vec particleDir[8] = {
            { 1.0f, 1.0f, 1.0f },
            { 1.0f, 2.0f, 1.0f },
            { 0.0f, 2.0f, 1.0f },
            { -1.0f, 1.0f, 1.0f },
            { -1.0f, -1.0f, 1.0f },
            { 0.0f, -1.0f, 1.0f },
            { -1.0f, 2.0f, 1.0f },
            { 1.0f, -1.0f, 1.0f },
        };

        lamp->pos.y = (2.0f * HuMathSin(angle)) + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->pos.x, lamp->pos.y, lamp->pos.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_8010B5F8_315AA8_name_49(&pos, 0.1f, 2.0f, 1, &particleDir[(i / 2) & 7]);
        }
        angle += 0x14;
        HuPrcVSleep();
        i++;
    }

    func_8006735C_67F5C(vib);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    func_80054C78_55878(D_80112C58_31D108_name_49[system->star_spawn_indices[system->unk_0A]], &chain, &index);
    player->cur_chain_index = chain;
    player->cur_space_index = index;
    player->next_chain_index = chain;
    player->next_space_index = index + 1;
    func_800650BC_65CBC();
    func_80078FF8_79BF8();

    while (1) {
        Vec particleDir2[8] = {
            { 1.0f, 1.0f, 1.0f },
            { 1.0f, 2.0f, 1.0f },
            { 0.0f, 2.0f, 1.0f },
            { -1.0f, 1.0f, 1.0f },
            { -1.0f, -1.0f, 1.0f },
            { 0.0f, -1.0f, 1.0f },
            { -1.0f, 2.0f, 1.0f },
            { 1.0f, -1.0f, 1.0f },
        };

        lamp->pos.y = (2.0f * HuMathSin(angle)) + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->pos.x, lamp->pos.y, lamp->pos.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_8010B5F8_315AA8_name_49(&pos, 0.1f, 2.0f, 1, &particleDir2[(i / 2) & 7]);
        }
        i++;
        HuPrcVSleep();
        angle += 0x14;
        if (angle == 0x500) {
            func_800115B4_121B4(0);
        }
    }
}

void func_8010BBEC_31609C_name_49(void) {
    GW_SYSTEM* gw = &GwSystem;

    D_800CCC16 = 1;
    func_800556F4_562F4(D_80112C58_31D108_name_49[gw->star_spawn_indices[gw->unk_0A]], 1);
    D_800CCC16 = 0;
    if (func_800670B0_67CB0() >= 0) {
        HuPrcSleep(-1);
    }
}

void func_8010BC5C_31610C_name_49(void) {
    s32 playerNo;
    GW_PLAYER* player;
    s16 space;

    playerNo = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    func_8010C4F0_3169A0_name_49();
    func_80047A50_48650(playerNo);
    _SetFlag(4);
    func_80046F98_47B98(playerNo);
    func_80078FF8_79BF8();
    func_80064FF8_65BF8();
    HuPrcSleep(5);
    MBPlayerVibrate(-1, 3);
    HuPrcSleep(25);
    MBPlayerMotionSet(playerNo, 2, 0);
    func_80059120_59D20(gPlayers[playerNo].unk_24, 2.0f, -0.3f);
    HuPrcSleep(5);
    func_80047BB8_487B8(playerNo);
    func_8005DDEC_5E9EC(playerNo, -1, 0, 10, 2);
    HuPrcSleep(20);
    func_80053F7C_54B7C();
    func_8004CDE0_4D9E0();
    func_8004CE80_4DA80();
    func_8004D5B0_4E1B0();
    func_80053F54_54B54();
    _ClearFlag(4);
    func_80079848_7A448(func_80046F98_47B98(playerNo));
    func_80046EDC_47ADC(playerNo);
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    func_80047D78_48978(playerNo, -1);
    space = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
    func_800558E8_564E8(space);
    func_800556F4_562F4(space, 1);
    if (func_800670B0_67CB0() >= 0) {
        HuPrcSleep(-1);
    }
    func_80045650_46250(playerNo);
}

void func_8010BE48_3162F8_name_49(void) {
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    Unk3EWindowSlide* work;
    s32 i;

    i = 1;
    work = HuPrcCurrentGet()->user_data;
    dx = (f32)(work->x1 - work->x0) / work->frames;
    dy = (f32)(work->y1 - work->y0) / work->frames;
    func_8006296C_6356C(GwSystem.current_player_index, &x, &y);
    for (; i <= work->frames; i++) {
        if (work->sprite != -1) {
            SprPosSet(work->sprite, 0, work->x0 + dx * i, work->y0 + dy * i);
        }
        func_800629AC_635AC(GwSystem.current_player_index, dx * i + x, dy * i + y);
        HuPrcVSleep();
    }
    if (work->sprite != -1) {
        SprPosSet(work->sprite, 0, work->x1, work->y1);
    }
    func_800629AC_635AC(GwSystem.current_player_index, (work->x1 + x) - work->x0, (work->y1 + y) - work->y0);
    omDelPrcObj(NULL);
}

Process* func_8010C094_316544_name_49(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames) {
    Process* process;
    Unk3EWindowSlide* work;

    process = omAddPrcObj(func_8010BE48_3162F8_name_49, 0x4001, 0, 0x40);
    work = process->user_data = HuMemMemoryAlloc(process->heap, sizeof(Unk3EWindowSlide));
    work->x0 = x0;
    work->y0 = y0;
    work->x1 = x1;
    work->y1 = y1;
    work->frames = frames;
    work->sprite = sprite;
    return process;
}

void func_8010C140_3165F0_name_49(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80113594_31DA44_name_49[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80113724_31DBD4_name_49[gw->current_player_index].x, D_80113724_31DBD4_name_49[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(sprite, D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].y,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_800822A8_82EA8(sprite, 0, 0, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, 255 - i * 25);
        func_800628C0_634C0(gw->current_player_index, 0, 2.0f);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    MBPlayerMotionSet(-1, 5, 0);
    func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010C4F0_3169A0_name_49(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 alpha;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80113594_31DA44_name_49[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80113724_31DBD4_name_49[gw->current_player_index].x,
              D_80113724_31DBD4_name_49[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    func_8010C094_316544_name_49(sprite, D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                 D_80113724_31DBD4_name_49[gw->current_player_index].y,
                                 D_80113764_31DC14_name_49[gw->current_player_index].x,
                                 D_80113764_31DC14_name_49[gw->current_player_index].y, 30);
    HuPrcSleep(20);
    for (i = 1; i < 10; i++) {
        alpha = 255 - i * 25;
        func_800629F0_635F0(gw->current_player_index, alpha);
        func_80082488_83088(sprite, 0, alpha);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    func_80082488_83088(sprite, 0, 0);
    HuPrcSleep(2);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010C83C_316CEC_name_49(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80113594_31DA44_name_49[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80113784_31DC34_name_49[gw->current_player_index].x, D_80113784_31DC34_name_49[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(sprite, D_80113784_31DC34_name_49[gw->current_player_index].x,
                                                D_80113784_31DC34_name_49[gw->current_player_index].y,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010CB68_317018_name_49(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 j;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80113594_31DA44_name_49[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80113724_31DBD4_name_49[gw->current_player_index].x, D_80113724_31DBD4_name_49[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(sprite, D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].y,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_800822A8_82EA8(sprite, 0, 0, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    if (gPlayers[gw->current_player_index].item == 7) {
        PlaySound(0x369);
    }
    i = 0;
    do {
        func_80062A28_63628(gw->current_player_index, HuMathSin(i) * 30.0f);
        i += 30;
        HuPrcVSleep();
    } while (i < 1081);
    for (j = 1; j < 10; j++) {
        func_800629F0_635F0(gw->current_player_index, 255 - j * 25);
        func_80062A28_63628(gw->current_player_index, HuMathSin(i) * 30.0f);
        i += 30;
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010CFCC_31747C_name_49(void) {
    s8 others[8];
    char str0[16];
    char str1[16];
    s32 count;
    s32 target;
    s32 i;
    MBModel* chest;
    f32 f;
    f32 x;
    f32 y;
    GW_SYSTEM* gw = &GwSystem;

    count = 0;
    func_8010C4F0_3169A0_name_49();
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(-1, D_80113764_31DC14_name_49[gw->current_player_index].x,
                                                D_80113764_31DC14_name_49[gw->current_player_index].y,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    for (i = 0; i < 4; i++) {
        if (i != gw->current_player_index && gPlayers[i].item != -1) {
            others[count++] = i;
        }
    }
    chest = func_80043510_44110(0x6E, NULL);
    func_800297E8_2A3E8(chest->obj->model[0], 0, 0, 0);
    func_800B3170_B3D70(&chest->pos, &((MBModel*)BoardPlayerGet(-1)->unk_24)->pos);
    func_80029E80_2AA80(chest->obj->model[0], 2, 1);
    chest->jumpY = 100.0f;
    do {
        chest->jumpY -= 1.0f;
        HuPrcVSleep();
    } while (chest->jumpY > 30.0f);
    if (count != 0) {
        PlaySound(0x36B);
        for (i = 0; i < 1081; i += 30) {
            f = i;
            x = HuMathSin(f) / 2.0f + 1.0f;
            y = HuMathSin(f) / 2.0f + 1.0f;
            HuVecCopyXYZ(&chest->scale, x, y, HuMathSin(f) / 2.0f + 1.0f);
            HuPrcVSleep();
        }
    }
    func_80029E80_2AA80(chest->obj->model[0], 1, 0);
    HuPrcSleep(20);
    if (count == 0) {
        MBPlayerMotionSet(-1, 3, 0);
        HuPrcSleep(20);
        MBDlgResultWinExec(0x1E3);
        MBPlayerMotionSet(-1, -1, 2);
        MBModelKill(chest);
        gPlayers[gw->current_player_index].item = -1;
        return;
    }
    target = others[MBRand(count)];
    gPlayers[gw->current_player_index].item = gPlayers[target].item;
    gPlayers[target].item = -1;
    MBPlayerVibrate(target, 3);
    func_800629F0_635F0(target, 0);
    func_80062588_63188(gw->current_player_index);
    func_800629F0_635F0(gw->current_player_index, 0x100);
    PlaySound(0x19);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(-1, D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y,
                                                D_80113784_31DC34_name_49[gw->current_player_index].x,
                                                D_80113784_31DC34_name_49[gw->current_player_index].y, 5));
    HuPrcChildWatch();
    func_80079718_7A318(0xF5, gPlayers[gw->current_player_index].character);
    MBPlayerMotionSet(-1, 5, 0);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    MBModelKill(chest);
    str0[0] = 0x18;
    str0[1] = gPlayers[target].character;
    str0[2] = 0;
    str1[0] = 0x18;
    str1[1] = gPlayers[gw->current_player_index].character;
    str1[2] = 0;
    func_80056368_56F68(-1, 0x1E2, str0, str1, 0, 0, 0);
    MBDlgWinClose();
    func_80056168_56D68();
    func_8010C83C_316CEC_name_49();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_8010CFCC_31747C_name_49);
#endif

void func_8010D544_3179F4_name_49(void) {
    GW_PLAYER* player = BoardPlayerGet(-1);
    MBModel* obj;
    f32 scale;
    f32 rot;

    func_8005070C_5130C();
    MBModelDispOff(D_800CC1F0_CCDF0);
    D_800CC1F0_CCDF0->obj->scale.x = 0.0f;
    D_800CC1F0_CCDF0->obj->scale.y = 0.0f;
    D_800CC1F0_CCDF0->obj->scale.z = 0.0f;
    MBPlayerVibrate(-1, 3);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &((MBModel*)player->unk_24)->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelDispOff(player->unk_24);
    MBModelDispOn(D_800CC1F0_CCDF0);

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelKill(obj);
    HuPrcSleep(20);
    MBKSuitMotionSet(5, 2);
    HuPrcSleep(40);
    MBKSuitMotionSet(-1, 2);
    MBDlgResultWinExec(0x1E6);
}

void func_8010D7B4_317C64_name_49(void) {
    GW_PLAYER* player = BoardPlayerGet(-1);
    Vec fwd;
    MBModel* obj;
    f32 scale;
    f32 rot;

    MBKSuitMotionSet(-1, 2);
    func_8005670C_5730C(&fwd);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &fwd, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &((MBModel*)player->unk_24)->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelDispOn(player->unk_24);
    func_80050860_51460();

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

void func_8010D9E8_317E98_name_49(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    gPlayers[gw->current_player_index].item = 3;
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(1);
    func_800629F0_635F0(gw->current_player_index, 0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(-1, D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].y,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    PlaySound(0x19);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, i * 25);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0x100);
    MBPlayerMotionSet(-1, 3, 0);
    HuPrcSleep(30);
    MBDlgResultWinExec(D_801137A4_31DC54_name_49[gw->current_board_index]);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010C094_316544_name_49(-1, D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                D_80113744_31DBF4_name_49[gw->current_player_index].y,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                D_80113724_31DBD4_name_49[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
}

void func_8010DCFC_3181AC_name_49(void) {
    Vec dir;
    GW_PLAYER* player;
    MBModel* obj;
    SpaceData* space;
    f32 scale;
    f32 rot;
    s32 i;
    s32 j;
    s32 cur;
    GW_SYSTEM* gw;

    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
    HuPrcChildWatch();
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].item == 3) {
            func_80060210_60E10(0x19);
            while (func_800609D8_615D8()) {
                HuPrcVSleep();
            }
            MBStatusItemDispSetAll(1);
            func_800629F0_635F0(i, 0x100);
            func_80060210_60E10(0x1A);
            while (func_800609D8_615D8()) {
                HuPrcVSleep();
            }
            HuPrcSleep(20);
            func_800636F8_642F8(3);
            cur = gw->current_player_index;
            gw->current_player_index = i;
            PlaySound(0x375);
            HuPrcChildLink(HuPrcCurrentGet(),
                           func_8010C094_316544_name_49(-1, D_80113724_31DBD4_name_49[gw->current_player_index].x,
                                                        D_80113724_31DBD4_name_49[gw->current_player_index].y,
                                                        D_80113744_31DBF4_name_49[gw->current_player_index].x,
                                                        D_80113744_31DBF4_name_49[gw->current_player_index].y, 30));
            HuPrcChildWatch();
            HuPrcSleep(20);
            for (j = 1; j < 10; j++) {
                func_800629F0_635F0(i, 255 - j * 25);
                func_800628C0_634C0(i, 0.0f, 2.0f);
                HuPrcVSleep();
            }
            func_800629F0_635F0(i, 0);
            gPlayers[i].item = -1;
            gw->current_player_index = cur;
            func_800636F8_642F8(1);
            break;
        }
    }
    if (D_800F8D12_F9912 != 0) {
        func_80107C10_3120C0_name_49();
        HuPrcSleep(30);
    }
    MBPlayerVibrate(0, 4);
    MBPlayerVibrate(1, 4);
    MBPlayerVibrate(2, 4);
    MBPlayerVibrate(3, 4);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800F64C8_F70C8->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800509FC_515FC();
    MBModelDispOff(D_800F64C8_F70C8);

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    func_80054C78_55878(D_80112C58_31D108_name_49[gw->unk_1C], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    space = GetSpaceData(D_80112C58_31D108_name_49[gw->unk_1C]);
    func_80056658_57258(&((MBModel*)player->unk_24)->pos, &space->coords, &dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBKSuitMotionSet(0, 2);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->pos, 10);
    HuPrcSleep(10);
    MBKSuitMotionSet(-1, 2);
    if (func_8006286C_6346C(0)) {
        func_80060210_60E10(0x19);
        while (func_800609D8_615D8()) {
            HuPrcVSleep();
        }
        MBStatusItemDispSetAll(0);
        func_80060210_60E10(0x1A);
        while (func_800609D8_615D8()) {
            HuPrcVSleep();
        }
    }
    func_8005670C_5730C(&dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBKSuitMotionSet(5, 2);
    HuPrcSleep(30);
    PlaySound(0x123);
    MBDlgWinExec(D_801137BC_31DC6C_name_49[gw->current_board_index], D_801137A4_31DC54_name_49[gw->current_board_index] + 1);
    MBKSuitMotionSet(-1, 2);
    HuPrcVSleep();
    func_800495D8_4A1D8(gw->current_player_index, 3);
}

void func_8010E370_318820_name_49(void) {
    MBModel* obj;
    f32 scale;
    f32 rot;

    func_800794A8_7A0A8(60);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800CC1F0_CCDF0->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800636F8_642F8(3);
    func_80050860_51460();

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    PlayMusic(func_800632FC_63EFC());
    MBDlgResultWinExec(D_801137A4_31DC54_name_49[GwSystem.current_board_index] + 8);
    D_800F8D16_F9916 = 0;
}

#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010E5A4_318A54_name_49(void) {
    s8 hit[8];
    Vec dir;
    char names[4][4];
    GW_PLAYER* player;
    GW_SYSTEM* gw;
    s32 cur;
    s32 count;
    s32 i;
    s32 total;
    s32 best;
    s32 max;
    s32 flag;

    cur = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    count = 0;
    for (i = 0; i < 4; i++) {
        if (GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[cur].cur_chain_index, gPlayers[cur].cur_space_index) ==
            GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[i].cur_chain_index, gPlayers[i].cur_space_index)) {
            hit[count++] = i;
            MBPlayerVibrate(i, 4);
        }
    }
    if (count == 0) {
        return;
    }
    flag = func_80046D2C_4792C(cur);
    MBKSuitMotionSet(-1, 2);
    func_8005670C_5730C(&dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    PlaySound(0x123);
    total = 0;
    for (i = 0; i < count; i++) {
        total += gPlayers[hit[i]].coins;
    }
    if (total == 0) {
        if (count == 1) {
            names[0][0] = 0x18;
            names[0][1] = gPlayers[hit[0]].character;
            names[0][2] = 0;
            func_80056368_56F68(D_801137BC_31DC6C_name_49[gw->current_board_index],
                                D_801137A4_31DC54_name_49[gw->current_board_index] + 6, names[0], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(D_801137BC_31DC6C_name_49[gw->current_board_index],
                         D_801137A4_31DC54_name_49[gw->current_board_index] + 7);
        }
    } else {
        names[0][0] = names[1][0] = names[2][0] = names[3][0] = 0;
        for (i = 0; i < count; i++) {
            names[i][0] = 0x18;
            names[i][1] = gPlayers[hit[i]].character;
            names[i][2] = 0;
        }
        func_80056368_56F68(D_801137BC_31DC6C_name_49[gw->current_board_index],
                            (count + 1) + D_801137A4_31DC54_name_49[gw->current_board_index], names[0],
                            names[1], names[2], names[3], 0);
        func_80056458_57058();
        if (gw->current_board_index == 4) {
            func_80056458_57058();
        }
        best = -1;
        MBDlgWinClose();
        func_80056168_56D68();
        max = 0;
        for (i = 0; i < count; i++) {
            if (max < gPlayers[hit[i]].coins) {
                best = hit[i];
                max = gPlayers[hit[i]].coins;
            }
        }
        for (i = 0; i < count; i++) {
            if (gPlayers[hit[i]].coins >= 5) {
                func_800797DC_7A3DC(0xFC, hit[i]);
            }
            MBPlayerVibrate(hit[i], 3);
            func_8004CA14_4D614(hit[i], -gPlayers[hit[i]].coins);
            if (best == hit[i]) {
                func_8006135C_61F5C(best, -gPlayers[best].coins, 1);
            } else {
                func_8006135C_61F5C(hit[i], -gPlayers[hit[i]].coins, 0);
            }
        }
        MBKSuitMotionSet(5, 2);
        HuPrcSleep(30);
    }
    if (flag != 0) {
        func_8004655C_4715C(GwSystem.current_player_index);
    }
    MBKSuitMotionSet(0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_8010E5A4_318A54_name_49);
#endif

void func_8010EAB4_318F64_name_49(void) {
    s16 grp;
    s16 anim;
    void* data;
    s32 i;
    s32 pick;

    pick = MBRand(6.0f);
    if (pick >= 5) {
        pick = -1;
    }
    if (pick != -1) {
        grp = SprCreate(1, 5);
        data = DataRead(D_800CCBDC_CD7DC[D_800CAFD8[pick]]);
        anim = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(grp, 0, anim, 0);
        SprPrioSet(grp, 0, 10);
        func_8008225C_82E5C(grp, 0, 0);
        SprAttrSet(grp, 0, 0x1000);
        SprPosSet(grp, 0, 160, 90);
        func_80082488_83088(grp, 0, 0);
        for (i = 0; i < 10; i++) {
            func_80082488_83088(grp, 0, i * 25);
            HuPrcVSleep();
        }
        func_80082488_83088(grp, 0, 0x100);
        MBPlayerMotionSet(-1, 5, 0);
        HuPrcSleep(50);
        MBPlayerMotionSet(-1, -1, 2);
        HuPrcSleep(10);
        SprAnimKill(anim);
        SprKill(grp);
        gPlayers[GwSystem.current_player_index].item = D_800CAFD8[pick];
    } else {
        MBPlayerMotionSet(-1, 3, 0);
        HuPrcSleep(50);
    }
}

#ifdef NON_MATCHING
/* NON_MATCHING: register residue only (retail keeps the two SpaceData* and adds 8 later; 2 instrs).
   Warp pipe event: the player jumps into pipe `pipe`, sinks, and comes out of a random one of
   pipes 0-4 other than `exclude` (pipes 5-7 are entrances only), then hops to its landing space. */
#define PIPE_PLAYER ((MBModel*)player->unk_24)
s32 func_8010ECC4_319174_name_49(s32 exclude, s32 pipe) {
    Vec vec[2]; /* [0] a facing, [1] a jump target (one array: retail packs them) */
    char msg[4]; /* retail's is zero-sized (char msg[0]): its three bytes land on the saved $s0 slot */
    GW_PLAYER* player;
    MBModel* model;
    Vec* in;
    Vec* from;
    Vec* to;
    void* vib;
    s32 dest;
    f32 camSpeed;
    f32 camZoom;
    GW_SYSTEM* gw;

    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    msg[0] = 0x18;
    msg[1] = gPlayers[gw->current_player_index].character;
    msg[2] = 0;
    MBWinInsertOpen(0x356, msg, 0, 0, 0, 0);
    func_80055E3C_56A3C(gw->current_player_index);
    func_80055E60_56A60();
    model = func_80043510_44110(D_80113804_31DCB4_name_49[D_801137E4_31DC94_name_49[pipe]], NULL);
    func_800298A4_2A4A4(model->obj->model[0], 0x80000, 0x80000);
    func_80029A8C_2A68C(model->obj->model[0]);
    in = &GetSpaceData(D_801137C8_31DC78_name_49[pipe])->coords;
    func_800B3170_B3D70(&model->pos, in);
    func_80056658_57258(&PIPE_PLAYER->pos, in, &PIPE_PLAYER->rot);
    func_800B3170_B3D70(&vec[1], in);
    vec[1].y += (D_801137E4_31DC94_name_49[pipe] * 10.0f + 40.0f) / 2.0f;
    func_80056D80_57980(&PIPE_PLAYER->pos, &vec[1], &PIPE_PLAYER->pos, 20);
    PIPE_PLAYER->jumpVel = 5.5f;
    PIPE_PLAYER->jumpAccel = -0.5f;
    MBPlayerMotionSet(-1, 2, 0);
    func_800797DC_7A3DC(0x42, gw->current_player_index);
    HuPrcSleep(20);
    MBPlayerMotionSet(-1, -1, 2);
    PIPE_PLAYER->attr |= 1;
    func_800636F8_642F8(0);
    PlaySound(0x408);
    func_8005670C_5730C(&vec[0]);
    func_80056B78_57778(&PIPE_PLAYER->rot, &vec[0], &PIPE_PLAYER->rot, 10);
    vec[1].y = 0.0f;
    func_80056D80_57980(&PIPE_PLAYER->pos, &vec[1], &PIPE_PLAYER->pos, 20);
    vib = func_800672BC_67EBC(gw->current_player_index, 2, 5);
    HuPrcSleep(20);
    func_8006735C_67F5C(vib);
    PIPE_PLAYER->attr &= ~2;
    MBModelDispOff(PIPE_PLAYER);
    do {
        dest = MBRand(5.0f);
    } while (dest == exclude);
    func_80054C78_55878(D_801137D8_31DC88_name_49[dest], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    InitFadeOut(6, 16);
    HuPrcSleep(16);
    MBModelKill(model);
    from = &GetSpaceData(D_801137C8_31DC78_name_49[dest])->coords;
    to = &GetSpaceData(D_801137D8_31DC88_name_49[dest])->coords;
    func_800B3170_B3D70(&PIPE_PLAYER->pos, from);
    PIPE_PLAYER->pos.y += (D_801137E4_31DC94_name_49[dest] * 10.0f + 40.0f) / 2.0f;
    func_8005670C_5730C(&PIPE_PLAYER->rot);
    model = func_80043510_44110(D_80113804_31DCB4_name_49[D_801137E4_31DC94_name_49[dest]], NULL);
    func_800298A4_2A4A4(model->obj->model[0], 0x80000, 0x80000);
    func_80029A8C_2A68C(model->obj->model[0]);
    func_800B3170_B3D70(&model->pos, from);
    func_800517C0_523C0();
    func_80051788_52388();
    camSpeed = MBCameraSpeedGet();
    MBCameraSpeedSet(-1.0f);
    camZoom = func_80053614_54214();
    func_80053608_54208(1.0f);
    func_800514F0_520F0();
    MBDCameraPos3DSet(&PIPE_PLAYER->pos);
    HuPrcVSleep();
    func_80053608_54208(camZoom);
    MBCameraSpeedSet(camSpeed);
    func_80063C40_64840(0, 1);
    func_80063C40_64840(1, 1);
    func_80063C40_64840(2, 1);
    func_80063C40_64840(3, 1);
    func_800B3170_B3D70(&PIPE_PLAYER->pos, from);
    InitFadeIn(6, 16);
    HuPrcSleep(16);
    PIPE_PLAYER->attr |= 2;
    MBModelDispOn(PIPE_PLAYER);
    PlaySound(0x408);
    func_800B3170_B3D70(&vec[1], from);
    vec[1].y += (D_801137E4_31DC94_name_49[dest] * 10.0f + 40.0f) / 2.0f;
    func_80056D80_57980(&PIPE_PLAYER->pos, &vec[1], &PIPE_PLAYER->pos, 20);
    vib = func_800672BC_67EBC(gw->current_player_index, 2, 5);
    HuPrcSleep(20);
    func_8006735C_67F5C(vib);
    PIPE_PLAYER->attr &= ~1;
    MBModelKill(model);
    func_800636F8_642F8(1);
    func_80056658_57258(from, to, &PIPE_PLAYER->rot);
    func_800B3170_B3D70(&vec[1], to);
    func_80056D80_57980(&PIPE_PLAYER->pos, &vec[1], &PIPE_PLAYER->pos, 20);
    PIPE_PLAYER->jumpVel = 5.5f;
    PIPE_PLAYER->jumpAccel = -0.5f;
    MBPlayerMotionSet(-1, 2, 0);
    func_800797DC_7A3DC(0x42, gw->current_player_index);
    HuPrcSleep(20);
    MBPlayerMotionSet(-1, -1, 2);
    HuPrcSleep(5);
    return omDelPrcObj(NULL);
}
#undef PIPE_PLAYER
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_8010ECC4_319174_name_49);
#endif
#undef PIPE_PLAYER
#undef PIPE_PLAYER
#undef PIPE_PLAYER
#undef PIPE_PLAYER
#undef PIPE_PLAYER
#undef PIPE_PLAYER

s32 func_8010F320_3197D0_name_49(void) {
    return func_8010ECC4_319174_name_49(0, 0);
}

s32 func_8010F340_3197F0_name_49(void) {
    return func_8010ECC4_319174_name_49(1, 1);
}

s32 func_8010F360_319810_name_49(void) {
    return func_8010ECC4_319174_name_49(2, 2);
}

s32 func_8010F380_319830_name_49(void) {
    return func_8010ECC4_319174_name_49(4, 4);
}

s32 func_8010F3A0_319850_name_49(void) {
    return func_8010ECC4_319174_name_49(-1, 5);
}

s32 func_8010F3C0_319870_name_49(void) {
    return func_8010ECC4_319174_name_49(-1, 6);
}

s32 func_8010F3E0_319890_name_49(void) {
    return func_8010ECC4_319174_name_49(-1, 7);
}

/* One burst of func_8010F56C: model ids[n] (n = the s16 at user_data + 2) at pos[n], scale[n],
   for 30 frames. */
/* One burst of func_8010F56C: model ids[n] (n = the s16 at user_data + 2) at pos[n], scale[n],
   for 30 frames. */
void func_8010F400_3198B0_name_49(void) {
    s16* work = HuPrcCurrentGet()->user_data;
    Vec pos[5] = {
        { -50.0f, 200.0f, -40.0f }, { 0.0f, 200.0f, -20.0f }, { 50.0f, 200.0f, 0.0f },
        { -30.0f, 200.0f, -10.0f }, { 30.0f, 200.0f, -30.0f },
    };
    Vec scale[5] = {
        { 20.0f, 20.0f, 20.0f }, { 10.0f, 10.0f, 10.0f }, { 20.0f, 20.0f, 20.0f },
        { 15.0f, 15.0f, 15.0f }, { 10.0f, 10.0f, 10.0f },
    };
    u8 ids[6] = { 0x9C, 0x9D, 0x9E, 0x9C, 0x9D, 0x9E };
    MBModel* model;
    s16 n;

    PlaySound(0x409);
    n = work[1];
    model = func_80043510_44110(ids[n], NULL);
    func_800B3170_B3D70(&model->pos, &pos[n]);
    func_800B3170_B3D70(&model->scale, &scale[n]);
    HuPrcSleep(30);
    MBModelKill(model);
    omDelPrcObj(NULL);
}

/* A centred sprite (0xA0220) and five func_8010F400 bursts 5 frames apart. */
void func_8010F56C_319A1C_name_49(void) {
    s32 spr;
    void* data;
    s32 anim;
    Process* proc;
    s16* work;
    s32 i;

    spr = SprCreate_s32(1, 5);
    data = DataRead(0xA0220);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(spr, 0, anim, 0);
    SprPrioSet(spr, 0, 0x10);
    SprAttrSet(spr, 0, 0x5000);
    SprPosSet(spr, 0, 0xA0, 0x78);
    for (i = 0; i < 5; i++) {
        proc = omAddPrcObj(func_8010F400_3198B0_name_49, 0x4800, 0, 0x40);
        work = HuMemMemoryAlloc(proc->heap, 0x20);
        proc->user_data = work;
        work[1] = i;
        HuPrcSleep(5);
    }
    HuPrcSleep(20);
    SprKill(spr);
    SprAnimKill(anim);
}

/* Fills the whole trail with the leader's current position and rotation. */
void func_8010F694_319B44_name_49(void) {
    s32 i;

    D_80115690_31FB40_name_49 = 0;
    for (i = 0; i < 128; i++) {
        D_80114A90_31EF40_name_49[i].x = D_80115698_31FB48_name_49[0]->pos.x;
        D_80114A90_31EF40_name_49[i].y = D_80115698_31FB48_name_49[0]->pos.y;
        D_80114A90_31EF40_name_49[i].z = D_80115698_31FB48_name_49[0]->pos.z;
        D_80115090_31F540_name_49[i].x = D_80115698_31FB48_name_49[0]->rot.x;
        D_80115090_31F540_name_49[i].y = D_80115698_31FB48_name_49[0]->rot.y;
        D_80115090_31F540_name_49[i].z = D_80115698_31FB48_name_49[0]->rot.z;
    }
}

/* Records the leader in the trail and places each follower at its lag behind it. */
void func_8010F754_319C04_name_49(void) {
    s32 i;
    s32 idx;
    s32* lag;

    D_80114A90_31EF40_name_49[D_80115690_31FB40_name_49].x = D_80115698_31FB48_name_49[0]->pos.x;
    D_80114A90_31EF40_name_49[D_80115690_31FB40_name_49].y = D_80115698_31FB48_name_49[0]->pos.y;
    D_80114A90_31EF40_name_49[D_80115690_31FB40_name_49].z = D_80115698_31FB48_name_49[0]->pos.z;
    D_80115090_31F540_name_49[D_80115690_31FB40_name_49].x = D_80115698_31FB48_name_49[0]->rot.x;
    D_80115090_31F540_name_49[D_80115690_31FB40_name_49].y = D_80115698_31FB48_name_49[0]->rot.y;
    D_80115090_31F540_name_49[D_80115690_31FB40_name_49].z = D_80115698_31FB48_name_49[0]->rot.z;
    if (++D_80115690_31FB40_name_49 >= 128) {
        D_80115690_31FB40_name_49 = 0;
    }
    for (i = 1; i < 7; i++) {
        if (D_800F8CE4_F98E4[4] == 2) {
            lag = &D_801139F8_31DEA8_name_49[i];
        } else {
            lag = &D_801139DC_31DE8C_name_49[i];
        }
        idx = D_80115690_31FB40_name_49 - *lag;
        if (idx < 0) {
            idx += 128;
        }
        func_800B3170_B3D70(&D_80115698_31FB48_name_49[i]->pos, &D_80114A90_31EF40_name_49[idx]);
        func_800B3170_B3D70(&D_80115698_31FB48_name_49[i]->rot, &D_80115090_31F540_name_49[idx]);
    }
}

/* Puts the whole chain on space `space` and resets the trail. */
void func_8010F918_319DC8_name_49(s16 space) {
    SpaceData* data = GetSpaceData(space);
    MBModel* model;
    s32 i;

    for (i = 0; i < 7; i++) {
        model = D_80115698_31FB48_name_49[i];
        func_80042BE0_437E0(&model->rot);
        func_800B3170_B3D70(&model->pos, &data->coords);
    }
    func_8010F694_319B44_name_49();
}



/* Starts moving player `player` from space `from` to space `to` (offset by slot `slot`), as a
   child process: an arc (func_80056FD4) when `arc`, else a straight walk; slower (speed / 1.3)
   on a north-south-ish heading. */
void func_8010F9A0_319E50_name_49(s16 from, s16 to, f32 speed, s32 arc, s32 player, s32 slot) {
    Vec dir;
    SpaceData* fromData;
    SpaceData* toData;
    MBModel* model;
    Vec* target;
    Process* proc;
    f32 angle;

    fromData = GetSpaceData(from);
    toData = GetSpaceData(to);
    func_80056658_57258(&fromData->coords, &toData->coords, &dir);
    angle = func_80042BE0_437E0(&dir);
    if ((angle >= 70.0f && angle <= 110.0f) || (angle >= 250.0f && angle <= 290.0f)) {
        speed /= 1.3f;
    }
    model = gPlayers[player].unk_24;
    target = &D_801156B8_31FB68_name_49[player];
    func_800B3170_B3D70(target, &toData->coords);
    D_801156B8_31FB68_name_49[player].x += D_80113A24_31DED4_name_49[slot].x;
    D_801156B8_31FB68_name_49[player].z += D_80113A24_31DED4_name_49[slot].z;
    if (arc) {
        proc = func_80056FD4_57BD4(&model->pos, target, &model->pos, speed);
    } else {
        proc = func_80057150_57D50(&model->pos, &D_801156B8_31FB68_name_49[player], &model->pos, speed);
    }
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    func_80056658_57258(&fromData->coords, &toData->coords, &D_801156E8_31FB98_name_49[player]);
    func_80056B78_57778(&model->rot, &D_801156E8_31FB98_name_49[player], &model->rot, 5);
}

/* func_8010F9A0 for the chain's leader (a loop over one model): moves it from space `from` to
   space `to`, the first move linked as a child process. */
void func_8010FC3C_31A0EC_name_49(s16 from, s16 to, f32 speed, s32 arc) {
    Vec dir;
    SpaceData* fromData;
    SpaceData* toData;
    MBModel* model;
    Process* proc;
    f32 angle;
    s32 i;

    fromData = GetSpaceData(from);
    toData = GetSpaceData(to);
    func_80056658_57258(&fromData->coords, &toData->coords, &dir);
    angle = func_80042BE0_437E0(&dir);
    if ((angle >= 70.0f && angle <= 110.0f) || (angle >= 250.0f && angle <= 290.0f)) {
        speed /= 1.3f;
    }
    for (i = 0; i < 1; i++) {
        model = D_80115698_31FB48_name_49[i];
        func_800B3170_B3D70(&D_80115718_31FBC8_name_49[i], &toData->coords);
        if (arc) {
            proc = func_80056FD4_57BD4(&model->pos, &D_80115718_31FBC8_name_49[i], &model->pos, speed);
        } else {
            proc = func_80057150_57D50(&model->pos, &D_80115718_31FBC8_name_49[i], &model->pos, speed);
        }
        if (i == 0) {
            HuPrcChildLink(HuPrcCurrentGet(), proc);
        }
        func_80056658_57258(&fromData->coords, &toData->coords, &D_80115770_31FC20_name_49[i]);
        func_80056B78_57778(&model->rot, &D_80115770_31FC20_name_49[i], &model->rot, 5);
    }
}

/* Camera process: follows the average position of the chain's leader (a loop over one model). */
void func_8010FE80_31A330_name_49(void) {
    Vec pos;
    s32 i;

    while (1) {
        HuVecCopyXYZ(&pos, 0.0f, 0.0f, 0.0f);
        for (i = 0; i < 1; i++) {
            HuVecAdd(&pos, &pos, &D_80115698_31FB48_name_49[i]->pos);
        }
        pos.x /= 1;
        pos.y /= 1;
        pos.z /= 1;
        MBDCameraPos3DSet(&pos);
        HuPrcVSleep();
    }
}


/* Two small D_80114A20 models (coins) pop out of player work->player's head, spinning, and
   drift apart for 20 frames. */
void func_8010FF2C_31A3DC_name_49(void) {
    DiceProcWork* work = HuPrcCurrentGet()->user_data;
    MBModel* models[2];
    Vec pos[2];
    f32 dx[2] = { -1.0f, 1.0f };
    GW_PLAYER* player;
    s32 i;
    s32 t;

    player = BoardPlayerGet(work->player);
    for (i = 0; i < 2; i++) {
        models[i] = MBModelParamCreate(D_80114A20_31EED0_name_49);
        HuVecCopyXYZ(&models[i]->scale, 0.25f, 0.25f, 0.25f);
        func_800B3170_B3D70(&pos[i], &((MBModel*)player->unk_24)->pos);
        pos[i].y += 12.0f;
        func_800B3170_B3D70(&models[i]->pos, &pos[i]);
        func_80056754_57354(models[i]);
        models[i]->obj->rot.x += 90.0f;
        models[i]->obj->rot.y += MBRand(360.0f);
        models[i]->jumpVel = 5.0f;
        models[i]->jumpAccel = -0.4f;
        models[i]->attr |= 4;
    }
    for (t = 0; t < 20; t++) {
        for (i = 0; i < 2; i++) {
            pos[i].x += dx[i];
            func_800B3170_B3D70(&models[i]->pos, &pos[i]);
            models[i]->obj->rot.y += 20.0f;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 2; i++) {
        MBModelKill(models[i]);
    }
    omDelPrcObj(NULL);
}

void func_80110188_31A638_name_49(s32 player) {
    Process* process = omAddPrcObj(func_8010FF2C_31A3DC_name_49, 0x4800, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x20);

    process->user_data = work;
    work->player = player;
}

#ifdef NON_MATCHING
/* NON_MATCHING: retail reloads D_80113A60 after the wait loop (GCC here reuses the loop's load:
   4 instructions); the logic is complete. */
/* A player's run (process; work Ovl49RunWork): wait for the chain leader to come within 20 of
   the player's space, then hop along the route's legs (a coin pop, func_80110188, on each
   space of types 1, 2, 4-7, 9 and 12), then jump to space 0x80 with one more coin. Reading
   D_80113990[route][3] after the third leg is retail's (it is the next route's first leg). */
void func_801101E0_31A690_name_49(void) {
    Vec target;
    Ovl49RunWork* work;
    s32 player;
    GW_PLAYER* p;
    MBModel* model;
    s32 route;
    s32 leg;
    s32 slot;
    s16* path;
    Vec* leaderPos;
    Process* proc;
    Vec* pos;
    Vec* rot;

    work = HuPrcCurrentGet()->user_data;
    player = work->player;
    p = BoardPlayerGet(player);
    model = p->unk_24;
    route = work->route;
    leg = work->leg;
    slot = work->slot;
    path = work->path;
    if (D_80113A60_31DF10_name_49 == NULL) {
        do {
            HuPrcVSleep();
        } while (D_80113A60_31DF10_name_49 == NULL);
    }
    leaderPos = &D_80113A60_31DF10_name_49->pos;
    proc = HuPrcCurrentGet();
    while (!(HuVecDistance(&GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(p->cur_chain_index, p->cur_space_index))->coords, leaderPos) < 20.0f)) {
        func_80056658_57258(&model->pos, leaderPos, &model->rot);
        HuPrcVSleep();
    }
    func_8006735C_67F5C(D_801149E0_31EE90_name_49[player]);
    D_801149E0_31EE90_name_49[player] = func_800672BC_67EBC(player, 3, 5);
    func_800797DC_7A3DC(0x111, player);
    MBMotionSet(model, 2, 2);
    for (; leg < 3;) {
        while (path[1] != -1) {
            switch (GetSpaceData(path[1])->space_type) {
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 12:
                    D_801157C8_31FC78_name_49[player]++;
                    func_80110188_31A638_name_49(player);
                    break;
            }
            func_8010F9A0_319E50_name_49(path[0], path[1], 2.0f, 1, player, slot);
            HuPrcChildWatch();
            path++;
        }
        path = D_80113990_31DE40_name_49[route][++leg];
        if (path == D_80113980_31DE30_name_49) {
            break;
        }
    }
    func_80110188_31A638_name_49(player);
    D_801157C8_31FC78_name_49[player]++;
    func_800B3170_B3D70(&target, &GetSpaceData(0x80)->coords);
    target.x += D_80113A24_31DED4_name_49[slot].x;
    target.z += D_80113A24_31DED4_name_49[slot].z;
    pos = &model->pos;
    rot = &model->rot;
    func_80056658_57258(pos, &target, rot);
    HuPrcChildLink(proc, func_80056FD4_57BD4(pos, &target, pos, 2.0f));
    HuPrcChildWatch();
    func_8005670C_5730C(&target);
    func_80056B78_57778(rot, &target, rot, 5);
    MBMotionSet(model, 4, 2);
    func_800797DC_7A3DC(0xFC, player);
    func_80054C78_55878(0x80, &p->cur_chain_index, &p->cur_space_index);
    p->next_chain_index = p->cur_chain_index;
    p->next_space_index = p->cur_space_index + 1;
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_801101E0_31A690_name_49);
#endif

/* Bowser's parade, every fifth call (D_800F8CE4[0] counts down from 5): if any player stands on
   the route chosen by D_800F8CE4[1..3], a seven-float parade (layout D_800F8CE4[4], cycling 0-3;
   [0] Bowser's float, [6] a copy of it at the tail) follows the route from space 0x92 while
   each player on it runs ahead (func_801101E0), then everyone it caught pays twice the coins
   they passed (all their coins if short); the player paying most gets the third func_8006135C
   argument set. */
/* Bowser's parade, every fifth call (D_800F8CE4[0] counts down from 5): if any player stands on
   the route chosen by D_800F8CE4[1..3], a seven-float parade (layout D_800F8CE4[4], cycling 0-3;
   [0] Bowser's float, [6] a copy of it at the tail) follows the route from space 0x92 while
   each player on it runs ahead (func_801101E0), then everyone it caught pays twice the coins
   they passed (all their coins if short); the player paying most gets the third func_8006135C
   argument set. */
/* Bowser's parade, every fifth call (D_800F8CE4[0] counts down from 5): if any player stands on
   the route chosen by D_800F8CE4[1..3], a seven-float parade (layout D_800F8CE4[4], cycling 0-3;
   [0] Bowser's float, [6] a copy of it at the tail) follows the route from space 0x92 while
   each player on it runs ahead (func_801101E0), then everyone it caught pays twice the coins
   they passed (all their coins if short); the player paying most gets the third func_8006135C
   argument set. */
/* Bowser's parade, every fifth call (D_800F8CE4[0] counts down from 5): if any player stands on
   the route chosen by D_800F8CE4[1..3], a seven-float parade (layout D_800F8CE4[4], cycling 0-3;
   [0] Bowser's float, [6] a copy of it at the tail) follows the route from space 0x92 while
   each player on it runs ahead (func_801101E0), then everyone it caught pays twice the coins
   they passed (all their coins if short); the player paying most gets the third func_8006135C
   argument set. */
void func_8011056C_31AA1C_name_49(void) {
    MBModel* gates[2];
    u8 order[16];
    s32 i;
    s16* path;
    s32 leg;
    SpaceData* space;
    SpaceData* toward;
    s32 route;
    s32 count;
    s32 worst;
    s32 max;
    s32 k;
    Process* cam;
    f32 camSpeed;
    f32 camZoom;
    GW_SYSTEM* gw = &GwSystem;

    if (--D_800F8CE4_F98E4[0] == 0) {
        D_800F8CE4_F98E4[0] = 5;
        if (D_800F8CE4_F98E4[1] == 0) {
            route = 0;
        } else if (D_800F8CE4_F98E4[1] == 1) {
            route = 2;
            if (D_800F8CE4_F98E4[2] == 0) {
                route = 1;
            }
        } else {
            route = 4;
            if (D_800F8CE4_F98E4[3] == 0) {
                route = 3;
            }
        }
        D_80113A60_31DF10_name_49 = NULL;
        count = 0;
        for (leg = 0; leg < 3; leg++) {
            path = D_80113990_31DE40_name_49[route][leg];
            if (path == NULL) {
                break;
            }
            do {
                for (i = 0; i < 4; i++) {
                    GW_PLAYER* player;
                    Process* proc;
                    Ovl49RunWork* work;

                    D_801157C8_31FC78_name_49[i] = 0;
                    player = BoardPlayerGet(i);
                    if (*path == GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index)) {
                        proc = omAddPrcObj(func_801101E0_31A690_name_49, 0x4800, 0, 0x40);
                        work = HuMemMemoryAlloc(proc->heap, 0x20);
                        proc->user_data = work;
                        work->player = i;
                        work->route = route;
                        work->leg = leg;
                        work->slot = count;
                        work->path = path;
                        count++;
                    }
                }
                path++;
            } while (*path != -1);
        }
        for (i = 0; i < 4; i++) {
            func_80063C40_64840(i, 1);
        }
        func_800636F8_642F8(0);
        func_800517C0_523C0();
        func_80051788_52388();
        camSpeed = MBCameraSpeedGet();
        MBCameraSpeedSet(-1.0f);
        camZoom = func_80053614_54214();
        func_80053608_54208(1.0f);
        func_800514F0_520F0();
        MBDCameraPos3DSet(&GetSpaceData(0x73)->coords);
        HuPrcVSleep();
        func_80053608_54208(camZoom);
        MBCameraSpeedSet(camSpeed);
        InitFadeOut(0xFF, 1);
        HuPrcSleep(2);
        func_8005E310_5EF10();
        func_800794A8_7A0A8(0x20);
        func_80061518_62118();
        InitFadeIn(3, 16);
        HuPrcSleep(16);
        PlaySound(0x40F);
        func_80053F7C_54B7C();
        MBPlayerVibrate(0, 3);
        MBPlayerVibrate(1, 3);
        MBPlayerVibrate(2, 3);
        MBPlayerVibrate(3, 3);
        func_8010F56C_319A1C_name_49();
        func_80053F54_54B54();
        if (count == 0) {
            if (gw->total_turns == gw->current_turn) {
                func_80056030_56C30(5, 0x507);
            } else {
                func_80056030_56C30(5, 0x506);
            }
        } else {
            func_80056030_56C30(5, 0x503);
            PlayMusic(0x3E);
            HuPrcVSleep();
            space = GetSpaceData(0x92);
            toward = GetSpaceData(0x82);
            D_80115698_31FB48_name_49[0] = D_80113A60_31DF10_name_49 = func_80043510_44110(0x7B, D_80113A14_31DEC4_name_49);
            HuVecCopyXYZ(&D_80115698_31FB48_name_49[0]->scale, 1.2f, 1.2f, 1.2f);
            MBMotionSet(D_80115698_31FB48_name_49[0], 1, 2);
            func_80043DAC_449AC(D_80115698_31FB48_name_49[0]);
            func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[0]->rot);
            D_80115698_31FB48_name_49[0]->attr |= 1;
            if (++D_800F8CE4_F98E4[4] >= 4) {
                D_800F8CE4_F98E4[4] = 0;
            }
            switch (D_800F8CE4_F98E4[4]) {
                case 1:
                    MBArrayShuffle(order, 5);
                    for (i = 1; i < 7; i++) {
                        if (i == 6) {
                            D_80115698_31FB48_name_49[i] = MBModelParamCreate(D_80115698_31FB48_name_49[0]);
                            MBMotionSet(D_80115698_31FB48_name_49[i], 1, 2);
                            D_80115698_31FB48_name_49[i]->attr |= 1;
                        } else {
                            D_80115698_31FB48_name_49[i] = func_80043510_44110(D_801139CC_31DE7C_name_49[order[i - 1]], NULL);
                            func_80043DAC_449AC(D_80115698_31FB48_name_49[i]);
                        }
                        func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                    }
                    break;
                case 2:
                    MBArrayShuffle(order, 5);
                    D_80115698_31FB48_name_49[1] = func_80043510_44110(D_801139CC_31DE7C_name_49[order[0]], NULL);
                    func_80043DAC_449AC(D_80115698_31FB48_name_49[1]);
                    func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[1]->rot);
                    for (i = 2; i < 6; i++) {
                        D_80115698_31FB48_name_49[i] = func_80043510_44110(D_801139D2_31DE82_name_49[i], NULL);
                        func_80043DAC_449AC(D_80115698_31FB48_name_49[i]);
                        func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                        if (i == 4) {
                            func_80029C74_2A874(D_80115698_31FB48_name_49[i]->obj->model[0], 15.0f);
                        }
                    }
                    D_80115698_31FB48_name_49[i] = MBModelParamCreate(D_80115698_31FB48_name_49[0]);
                    MBMotionSet(D_80115698_31FB48_name_49[i], 1, 2);
                    D_80115698_31FB48_name_49[i]->attr |= 1;
                    func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                    break;
                case 0:
                    MBArrayShuffle(order, 5);
                    for (i = 1; i < 3; i++) {
                        D_80115698_31FB48_name_49[i] = func_80043510_44110(D_801139D7_31DE87_name_49[i], NULL);
                        func_80043DAC_449AC(D_80115698_31FB48_name_49[i]);
                        func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                    }
                    for (; i < 7; i++) {
                        if (i == 6) {
                            D_80115698_31FB48_name_49[i] = MBModelParamCreate(D_80115698_31FB48_name_49[0]);
                            MBMotionSet(D_80115698_31FB48_name_49[i], 1, 2);
                            D_80115698_31FB48_name_49[i]->attr |= 1;
                        } else {
                            D_80115698_31FB48_name_49[i] = func_80043510_44110(D_801139CC_31DE7C_name_49[order[i - 1]], NULL);
                            func_80043DAC_449AC(D_80115698_31FB48_name_49[i]);
                        }
                        func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                    }
                    break;
                case 3:
                    k = 5;
                    for (i = 1; i < 7; i++) {
                        if (i == 6) {
                            D_80115698_31FB48_name_49[i] = MBModelParamCreate(D_80115698_31FB48_name_49[0]);
                            MBMotionSet(D_80115698_31FB48_name_49[i], 1, 2);
                            D_80115698_31FB48_name_49[i]->attr |= 1;
                        } else {
                            D_80115698_31FB48_name_49[i] = func_80043510_44110(0x99, NULL);
                            func_80043DAC_449AC(D_80115698_31FB48_name_49[i]);
                            func_80029C74_2A874(D_80115698_31FB48_name_49[i]->obj->model[0], k-- * 15.0f);
                        }
                        func_80056658_57258(&space->coords, &toward->coords, &D_80115698_31FB48_name_49[i]->rot);
                    }
                    break;
            }
            func_8010F918_319DC8_name_49(0x92);
            space = GetSpaceData(0x91);
            gates[0] = func_80043510_44110(0x8E, NULL);
            func_800298A4_2A4A4(gates[0]->obj->model[0], 0x80000, 0x80000);
            func_80029A8C_2A68C(gates[0]->obj->model[0]);
            func_800B3170_B3D70(&gates[0]->pos, &space->coords);
            space = GetSpaceData(0x68);
            gates[1] = func_80043510_44110(0x8F, NULL);
            func_800298A4_2A4A4(gates[1]->obj->model[0], 0x80000, 0x80000);
            func_80029A8C_2A68C(gates[1]->obj->model[0]);
            func_800B3170_B3D70(&gates[1]->pos, &space->coords);
            D_801149E0_31EE90_name_49[0] = func_800672BC_67EBC(0, 2, 5);
            D_801149E0_31EE90_name_49[1] = func_800672BC_67EBC(1, 2, 5);
            D_801149E0_31EE90_name_49[2] = func_800672BC_67EBC(2, 2, 5);
            D_801149E0_31EE90_name_49[3] = func_800672BC_67EBC(3, 2, 5);
            func_8010FC3C_31A0EC_name_49(0x92, 0x82, 2.0f, 0);
            while (HuPrcCurrentGet()->oldest_child != NULL) {
                func_8010F754_319C04_name_49();
                HuPrcVSleep();
            }
            D_80115698_31FB48_name_49[0]->attr &= ~1;
            MBCameraSpeedSet(3.0f);
            cam = omAddPrcObj(func_8010FE80_31A330_name_49, 0x1005, 0, 0);
                for (leg = 0; leg < 3; leg++) {
                if (leg == 1) {
                    D_80115698_31FB48_name_49[6]->attr &= ~1;
                }
                path = D_80113990_31DE40_name_49[route][leg];
                if (path == NULL) {
                    break;
                }
                do {
                    func_8010FC3C_31A0EC_name_49(path[0], path[1], 2.0f, 0);
                    while (HuPrcCurrentGet()->oldest_child != NULL) {
                        func_8010F754_319C04_name_49();
                        HuPrcVSleep();
                    }
                    path++;
                    HuPrcVSleep();
                    if (*path == 0) {
                        omDelPrcObj(cam);
                        MBDCameraPos3DSet(&GetSpaceData(0x80)->coords);
                    }
                } while (path[1] != -1);
            }
            func_800794A8_7A0A8(0xC4);
            for (i = 0; i < 98; i++) {
                func_8010F754_319C04_name_49();
                HuPrcVSleep();
            }
            worst = -1;
            func_8006735C_67F5C(D_801149E0_31EE90_name_49[0]);
            func_8006735C_67F5C(D_801149E0_31EE90_name_49[1]);
            func_8006735C_67F5C(D_801149E0_31EE90_name_49[2]);
            func_8006735C_67F5C(D_801149E0_31EE90_name_49[3]);
            max = 0;
            for (i = 0; i < 4; i++) {
                if (D_801157C8_31FC78_name_49[i] != 0) {
                    if (D_801157C8_31FC78_name_49[i] * 2 > gPlayers[i].coins) {
                        if (max < gPlayers[i].coins) {
                            worst = i;
                            max = gPlayers[i].coins;
                        }
                    } else if (max < D_801157C8_31FC78_name_49[i] * 2) {
                        worst = i;
                        max = D_801157C8_31FC78_name_49[i] * 2;
                    }
                }
            }
            func_80061584_62184();
            for (i = 0; i < 4; i++) {
                if (D_801157C8_31FC78_name_49[i] != 0) {
                    if (D_801157C8_31FC78_name_49[i] * 2 > gPlayers[i].coins) {
                        func_8004CA14_4D614(i, -gPlayers[i].coins);
                        if (worst == i) {
                            func_8006135C_61F5C(i, -gPlayers[i].coins, 1);
                        } else {
                            func_8006135C_61F5C(i, -gPlayers[i].coins, 0);
                        }
                    } else {
                        func_8004CA14_4D614(i, -D_801157C8_31FC78_name_49[i] * 2);
                        if (worst == i) {
                            func_8006135C_61F5C(i, -D_801157C8_31FC78_name_49[i] * 2, 1);
                        } else {
                            func_8006135C_61F5C(i, -D_801157C8_31FC78_name_49[i] * 2, 0);
                        }
                    }
                }
            }
            HuPrcSleep(30);
            if (gw->total_turns == gw->current_turn) {
                func_80056030_56C30(5, 0x505);
            } else {
                func_80056030_56C30(5, 0x504);
            }
            MBModelKill(gates[0]);
            MBModelKill(gates[1]);
            for (i = 0; i < 7; i++) {
                MBModelKill(D_80115698_31FB48_name_49[i]);
            }
        }
        func_80015950_16550(30);
        InitFadeOut(3, 16);
        HuPrcSleep(16);
        func_80061584_62184();
        for (i = 0; i < 4; i++) {
            MBMotionSet(gPlayers[i].unk_24, -1, 2);
        }
        func_8005E374_5EF74();
        InitFadeIn(0xFF, 1);
        HuPrcSleep(2);
        MBCameraSpeedSet(-1.0f);
        func_800636F8_642F8(1);
        HuPrcSleep(5);
        PlayMusic(0xD);
    }
    func_80061584_62184();
}

s32 func_80111300_31B7B0_name_49(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;
    DecisionTreeNonLeafNode* tree;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_801147B0_31EC60_name_49;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                switch (arg0) {
                    case 0:
                        tree = D_80113A74_31DF24_name_49;
                        break;
                    case 1:
                        tree = D_80113A8C_31DF3C_name_49;
                        break;
                    case 2:
                    default:
                        tree = D_80113ABC_31DF6C_name_49;
                        break;
                }
                count = (s16)func_80044800_45400(tree) + 1;
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

#ifdef NON_MATCHING
/* NON_MATCHING: GCC here folds several gw-> reads back to GwSystem (lui+lh) where retail keeps
   them on $s4 (409 vs 420 instructions); the logic follows the asm. */
/* Switch event `which` (0-2, spaces D_80113AD4): unless it is the last turn, pay 5 coins (free
   with turn_status set) to throw the switch. Switches 1 and 2 toggle D_800F8CE4[1 + which];
   switch 0 asks for a direction (CPU: a random one weighted by the current setting) and stores
   it there. The switch model D_80114A74[which] turns to its new angle (D_80112E54). Option 2
   shows func_80103DBC and asks again; option 1 declines. */
void func_80111588_31BA38_name_49(s32 which) {
    GW_SYSTEM* gw = &GwSystem;
    char buf[8];
    Vec dir;
    struct unk_8003B8D4Struct* prompt;
    s32 choice;
    s32 n;
    s32 i;
    s32 sel;

    if (GwSystem.current_player_index != 4) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, D_80113AD4_31DF84_name_49[which]);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        PlaySound(0x363);
        sprintf(buf, D_801147D8_31EC88_name_49, D_800F8CE4_F98E4[0]);
        if (gw->current_turn == gw->total_turns) {
            if (gPlayers[gw->current_player_index].turn_status == 0) {
                MBDlgWinExec(5, 0x20A);
            } else {
                MBDlgWinExec(5, 0x20B);
            }
        } else {
            if (gPlayers[gw->current_player_index].coins < 5 && gPlayers[gw->current_player_index].turn_status == 0) {
                func_80056368_56F68(5, 0x206, buf, 0, 0, 0, 0);
                func_80056458_57058();
            } else {
            loop:
                if (gPlayers[gw->current_player_index].turn_status == 0) {
                    MBDlgWinCreate(5, 0x205);
                } else {
                    MBDlgWinCreate(5, 0x209);
                }
                choice = func_80111300_31B7B0_name_49(which);
                MBDlgWinClose();
                func_80056168_56D68();
                switch (choice) {
                    case 0:
                        if (gPlayers[gw->current_player_index].turn_status == 0) {
                            func_8004CA34_4D634(gw->current_player_index, -5);
                            func_800614B4_620B4(gw->current_player_index, -5);
                            HuPrcSleep(30);
                        }
                        if (which != 0) {
                            D_800F8CE4_F98E4[which + 1] ^= 1;
                            dir.x = HuMathSin(D_80112E54_31D304_name_49[which][D_800F8CE4_F98E4[which + 1]]);
                        } else {
                            MBDlgWinExec(5, 0x208);
                            func_80103F1C_30E3CC_name_49();
                            prompt = func_800419A4_425A4(gw->current_player_index, D_80113ADC_31DF8C_name_49, 1);
                            func_800417EC_423EC(prompt, gw->current_player_index, 0);
                            if (PlayerIsCPU(-1) != 0) {
                                n = MBRand(2.0f);
                                switch (D_800F8CE4_F98E4[1]) {
                                    case 0:
                                        n++;
                                        break;
                                    case 1:
                                        n += (n == 1);
                                        break;
                                }
                                for (i = 0; i < n; i++) {
                                    func_80041610_42210(prompt, -2);
                                }
                                func_80041610_42210(prompt, -4);
                            }
                            sel = DirectionPrompt(prompt);
                            func_8004108C_41C8C(prompt);
                            func_80103FEC_30E49C_name_49();
                            D_800F8CE4_F98E4[which + 1] = sel;
                            dir.x = HuMathSin(D_80112E54_31D304_name_49[which][(s16)sel]);
                        }
                        dir.z = func_800B7890_B8490(D_80112E54_31D304_name_49[which][D_800F8CE4_F98E4[which + 1]]);
                        MBPlayerVibrate(gw->current_player_index, 2);
                        func_80056B78_57778(&D_80114A74_31EF24_name_49[which]->rot, &dir, &D_80114A74_31EF24_name_49[which]->rot, 20);
                        PlaySound(0x404);
                        HuPrcSleep(20);
                        break;
                    case 2:
                        func_80103DBC_30E26C_name_49();
                        goto loop;
                    case 1:
                        break;
                }
                func_80056368_56F68(5, 0x207, buf, 0, 0, 0, 0);
            }
            MBDlgWinClose();
            func_80056168_56D68();
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    }
    if (which == 0) {
        func_80106FC4_311474_name_49();
    }
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80111588_31BA38_name_49);
#endif

void func_80111A78_31BF28_name_49(void) {
    func_80111588_31BA38_name_49(0);
}

void func_80111A94_31BF44_name_49(void) {
    func_80111588_31BA38_name_49(1);
}

void func_80111AB0_31BF60_name_49(void) {
    func_80111588_31BA38_name_49(2);
}

/* After message 0x354 the player is carried along path D_80113B20[n] to space 0x59 (one hop of 10 frames per space); everyone else is told to make way
   (func_80063C40(i, 10)) before the last hop. */
void func_80111ACC_31BF7C_name_49(s32 n) {
    Vec rot;
    s16* path = D_80113B20_31DFD0_name_49[n];
    GW_PLAYER* player = BoardPlayerGet(-1);
    SpaceData* space;
    s32 i;

    func_8005670C_5730C(&rot);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBDlgWinExec(0x21, 0x354);
    MBPlayerMotionSet(-1, 0, 2);
    while (*path != -1) {
        space = GetSpaceData(*path);
        func_80056658_57258(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->rot);
        if (path[1] == -1) {
            func_80054C78_55878(0x59, &player->cur_chain_index, &player->cur_space_index);
            player->next_chain_index = player->cur_chain_index;
            player->next_space_index = player->cur_space_index + 1;
            for (i = 0; i < 4; i++) {
                if (i != GwSystem.current_player_index) {
                    func_80063C40_64840(i, 10);
                }
            }
        }
        path++;
        HuPrcChildLink(HuPrcCurrentGet(), func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->pos, 10));
        HuPrcChildWatch();
    }
    MBPlayerMotionSet(-1, -1, 2);
    omDelPrcObj(NULL);
}

void func_80111C64_31C114_name_49(void) {
    func_80111ACC_31BF7C_name_49(0);
}

void func_80111C80_31C130_name_49(void) {
    func_80111ACC_31BF7C_name_49(1);
}

void func_80111C9C_31C14C_name_49(void) {
    func_80111ACC_31BF7C_name_49(2);
}

/* After message 0x355 the player is carried along path D_80113B84[n] to space 0x3F (one hop of 10 frames per space); everyone else is told to make way
   (func_80063C40(i, 10)) before the last hop. */
void func_80111CB8_31C168_name_49(s32 n) {
    Vec rot;
    s16* path = D_80113B84_31E034_name_49[n];
    GW_PLAYER* player = BoardPlayerGet(-1);
    SpaceData* space;
    s32 i;

    func_8005670C_5730C(&rot);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBDlgWinExec(0x21, 0x355);
    MBPlayerMotionSet(-1, 0, 2);
    while (*path != -1) {
        space = GetSpaceData(*path);
        func_80056658_57258(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->rot);
        if (path[1] == -1) {
            func_80054C78_55878(0x3F, &player->cur_chain_index, &player->cur_space_index);
            player->next_chain_index = player->cur_chain_index;
            player->next_space_index = player->cur_space_index + 1;
            for (i = 0; i < 4; i++) {
                if (i != GwSystem.current_player_index) {
                    func_80063C40_64840(i, 10);
                }
            }
        }
        path++;
        HuPrcChildLink(HuPrcCurrentGet(), func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->pos, 10));
        HuPrcChildWatch();
    }
    MBPlayerMotionSet(-1, -1, 2);
    omDelPrcObj(NULL);
}

void func_80111E50_31C300_name_49(void) {
    func_80111CB8_31C168_name_49(0);
}

void func_80111E6C_31C31C_name_49(void) {
    func_80111CB8_31C168_name_49(1);
}

void func_80111E88_31C338_name_49(void) {
    func_80111CB8_31C168_name_49(2);
}

void func_80111EA4_31C354_name_49(void) {
    func_80111CB8_31C168_name_49(3);
}

void func_80111EC0_31C370_name_49(void) {
    func_80111CB8_31C168_name_49(4);
}

#ifdef NON_MATCHING
/* NON_MATCHING: as func_80111588, GCC here reuses the player-index test's load for the first
   call where retail reloads it through $s5; the rest is register numbering. */
/* Bowser's shop (space 0x65): a random item (D_80113BFC odds, never item 3 while anyone holds
   one) is forced on the player for its price D_80113BF0 (all their coins when short, free
   with none); with turn_status set a free item from the second table instead. A player who
   already holds an item only gets message 0x248. */
void func_80111EDC_31C38C_name_49(void) {
    Vec rot;
    GW_PLAYER* player;
    s32 spr;
    s32 anim;
    void* data;
    u32 i;
    s32 r;
    s32 sel;
    s32 hasItem3;
    s32 j;
    GW_SYSTEM* gw;

    gw = &GwSystem;
    hasItem3 = 0;
    if (gw->current_player_index != 4) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x65);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        for (j = 0; j < 4; j++) {
            if (gPlayers[j].item == 3) {
                hasItem3 = 1;
            }
        }
        do {
            i = 0;
            r = MBRand(100.0f);
            for (; i < sizeof(D_80113BFC_31E0AC_name_49) / sizeof(s16); i++) {
                if (r < D_80113BFC_31E0AC_name_49[i]) {
                    break;
                }
            }
            sel = i;
        } while (hasItem3 && D_80113BE8_31E098_name_49[i] == 3);
        PlaySound(0x363);
        if (gPlayers[gw->current_player_index].turn_status != 0) {
            i = 0;
            r = MBRand(100.0f);
            for (; i < sizeof(D_80113C20_31E0D0_name_49) / sizeof(s16); i++) {
                if (r < D_80113C20_31E0D0_name_49[i]) {
                    break;
                }
            }
            sel = i;
            func_80056368_56F68(0x20, 0x24E, (char*)D_80113C28_31E0D8_name_49[i], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else if (gPlayers[gw->current_player_index].item != -1) {
            MBDlgWinExec(0x20, 0x248);
            goto done;
        } else if (gPlayers[gw->current_player_index].coins == 0) {
            func_80056368_56F68(0x20, 0x247, (char*)D_80113C08_31E0B8_name_49[sel], 0, 0, 0, 0);
            func_80056458_57058();
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            if (gPlayers[gw->current_player_index].coins < D_80113BF0_31E0A0_name_49[sel]) {
                func_80056368_56F68(0x20, 0x246, (char*)D_80113C08_31E0B8_name_49[sel], 0, 0, 0, 0);
                func_80056458_57058();
                func_80056458_57058();
                MBDlgWinClose();
                func_80056168_56D68();
                func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
            } else {
                func_80056368_56F68(0x20, 0x245, (char*)D_80113C08_31E0B8_name_49[sel], 0, 0, 0, 0);
                func_80056458_57058();
                MBDlgWinClose();
                func_80056168_56D68();
                func_8004CA34_4D634(gw->current_player_index, -D_80113BF0_31E0A0_name_49[sel]);
                func_800614B4_620B4(gw->current_player_index, -D_80113BF0_31E0A0_name_49[sel]);
            }
            HuPrcSleep(30);
        }
        if (gPlayers[gw->current_player_index].turn_status == 0) {
            gPlayers[gw->current_player_index].item = D_80113BE8_31E098_name_49[sel];
        } else {
            gPlayers[gw->current_player_index].item = D_80113C1C_31E0CC_name_49[sel];
        }
        player = BoardPlayerGet(-1);
        spr = SprCreate_s32(1, 5);
        if (gPlayers[gw->current_player_index].turn_status == 0) {
            data = DataRead(D_800CCBDC_CD7DC[D_80113BE8_31E098_name_49[sel]]);
        } else {
            data = DataRead(D_800CCBDC_CD7DC[D_80113C1C_31E0CC_name_49[sel]]);
        }
        anim = SprAnimRead_s32(data);
        DataClose(data);
        SprAnimSet(spr, 0, anim, 0);
        SprPrioSet(spr, 0, 10);
        func_8008225C_82E5C(spr, 0, 0);
        SprAttrSet(spr, 0, 0x1000);
        SprPosSet(spr, 0, 0xA0, 0x5A);
        func_80082488_83088(spr, 0, 0);
        func_8005670C_5730C(&rot);
        func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 10);
        PlaySound(0x19);
        for (j = 0; j < 10; j++) {
            func_80082488_83088(spr, 0, j * 25);
            HuPrcVSleep();
        }
        func_80082488_83088(spr, 0, 0x100);
        MBPlayerMotionSet(-1, 5, 0);
        HuPrcSleep(5);
        func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
        HuPrcSleep(45);
        MBPlayerMotionSet(-1, -1, 2);
        HuPrcSleep(10);
        SprAnimKill(anim);
        SprKill(spr);
    done:
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    }
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_49_name/30CCB0", func_80111EDC_31C38C_name_49);
#endif

void func_801125B0_31CA60_name_49(void) {
    func_80020070_20C70(2);
    CameraScissorSet(1, D_80113D80_31E230_name_49);
    func_80105CE8_310198_name_49();
    func_80066C34_67834(2);
    omAddPrcObj(func_80102FFC_30D4AC_name_49, 0x1005, 0x1000, 0);
}

s32 func_80112604_31CAB4_name_49(void) {
    s32 cur;
    s32 i;
    GW_SYSTEM* gw;

    cur = GetCurrentPlayerIndex();
    gw = &GwSystem;
    switch (gPlayers[cur].item) {
        case 0:
            if (gw->total_turns != gw->current_turn && !RNGPercentChance(80)) {
                return 0;
            }
            break;
        case -1:
        case 1:
        case 3:
            return 0;
        case 6:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_801142B8_31E768_name_49) != 0) {
                return 0;
            }
            break;
        case 8:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80114318_31E7C8_name_49) != 0) {
                return 0;
            }
            break;
        case 5:
            if (func_80044800_45400(D_801144C8_31E978_name_49) != 0) {
                return 0;
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                if (i != cur && gPlayers[i].item != -1 && gPlayers[i].item != 3) {
                    break;
                }
            }
            if (i == 4) {
                return 0;
            }
            break;
        case 7:
            if (gPlayers[cur].coins < 5) {
                return 0;
            }
            break;
        case 9:
            if (func_80044800_45400(D_80114630_31EAE0_name_49) != 0) {
                return 0;
            }
            if (gPlayers[cur].coins < 20) {
                return 0;
            }
            break;
        case 4:
            if (gPlayers[cur].coins < 10 && GwSystem.total_turns != GwSystem.current_turn) {
                return 0;
            }
            break;
    }
    return 1;
}

s32 func_80112828_31CCD8_name_49(void) {
    GW_PLAYER* player;
    s32 slot;
    s32 i;
    s32 r;
    u8 item;
    GW_SYSTEM* gw = &GwSystem;

    player = BoardPlayerGet(-1);
    slot = -1;
    for (i = 0; i < D_8011479C_31EC4C_name_49[player->character]; i++) {
        item = D_80114724_31EBD4_name_49[player->character][i];
        slot = func_80108BF0_3130A0_name_49(item);
        if (slot == -1) {
            continue;
        }
        if (D_800CC000[item] + 20 > gPlayers[gw->current_player_index].coins) {
            continue;
        }
        if (RNGPercentChance(D_80114784_31EC34_name_49[player->character][i])) {
            break;
        }
    }
    if (i == D_8011479C_31EC4C_name_49[player->character]) {
        slot = -1;
    }
    if (slot != -1) {
        if (func_80108BF0_3130A0_name_49(9) == slot) {
            return slot + 1;
        }
        if (func_80108BF0_3130A0_name_49(7) == slot && D_800CC000[7] + 50 <= gPlayers[gw->current_player_index].coins) {
            return slot + 1;
        }
    }
    if (func_80044800_45400(D_80114690_31EB40_name_49) == 0 && gPlayers[gw->current_player_index].coins >= D_800CC000[1]) {
        r = func_80108BF0_3130A0_name_49(1);
        if (r != -1) {
            return r + 1;
        }
    }
    if (slot != -1) {
        return slot + 1;
    }
    i = func_80044800_45400(D_801146A8_31EB58_name_49);
    if (i == 0) {
        for (; i < D_8011479C_31EC4C_name_49[player->character]; i++) {
            item = D_80114724_31EBD4_name_49[player->character][i];
            slot = func_80108BF0_3130A0_name_49(item);
            if (slot == -1) {
                continue;
            }
            if (D_800CC000[item] > gPlayers[gw->current_player_index].coins) {
                continue;
            }
            if (RNGPercentChance(D_80114784_31EC34_name_49[player->character][i])) {
                return slot + 1;
            }
        }
    }
    if (gw->current_board_index == 4) {
        D_801146D8_31EB88_name_49 = 1;
        return func_80108C5C_31310C_name_49() + 2;
    }
    slot = func_80108BF0_3130A0_name_49(0);
    if (slot != -1) {
        return slot + 1;
    }
    return 1;
}

s32 func_80112BA4_31D054_name_49(void) {
    if (D_801146D8_31EB88_name_49 != 0) {
        D_801146D8_31EB88_name_49 = 0;
        return 2;
    }
    return func_80044800_45400(D_801146C0_31EB70_name_49) + 1;
}
