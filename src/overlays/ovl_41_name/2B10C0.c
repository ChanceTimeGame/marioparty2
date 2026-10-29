#include "common.h"
#include "ovl_41.h"

/* .data (0x2BF320-0x2C0620), in address order (mp2boarddata.py with data.over; 3E's twin).
   Decision-tree nodes keep a child list in node_data2 as (DtData)pointer. Labels inside these
   objects that C or asm address directly are undefined_syms.txt aliases: D_80110BE9 (= D_80110BE8
   + 1: the signpost model ids are the low bytes of s16s, read with lbu), D_80110F92 (= D_80110FA0
   - 0xE: indexed by a message number 7-10). */
s16 D_80110A60_2BF320_name_41[8] = {
    0, 1, 2, 3, 4, 5, 6, 0,
};
s16 D_80110A70_2BF330_name_41[8] = {
    0, 0, 0, 0, 1, 1, 1, 0,
};
s16 D_80110A80_2BF340_name_41[2] = {
    0, -1,
};
s16 D_80110A84_2BF344_name_41[8] = {
    70, 71, 72, 73, 74, 75, 76, 0,
};
s16 D_80110A94_2BF354_name_41[8] = {
    2, 19, 32, 39, 90, 70, 82, 0,
};
s16 D_80110AA4_2BF364_name_41[8] = {
    91, 102, 106, 107, 108, 109, 110, 0,
};
s32 D_80110AB4_2BF374_name_41 = 0x80039;
s32 D_80110AB8_2BF378_name_41 = 0x8003A;
f32 D_80110ABC_2BF37C_name_41[9] = {
    5.0f, 5.0f, 2.0f, 2.0f, 3.0f, 5.0f, 5.0f, 5.0f, 5.0f,
};
s32 D_80110AE0_2BF3A0_name_41 = 0;
u8 D_80110AE4_2BF3A4_name_41[3][4] = {
    { 60, 70, 80, 85 }, { 70, 80, 90, 95 }, { 80, 90, 95, 95 },
};
s16 D_80110AF0_2BF3B0_name_41[2] = {
    86, -1,
};
s16 D_80110AF4_2BF3B4_name_41[8] = {
    2, 19, 32, 39, 90, 70, 82, -1,
};
s16 D_80110B04_2BF3C4_name_41[7][2] = {
    { 4, -4 }, { -2, 0 }, { -2, -2 }, { -2, 0 }, { -2, -2 }, { 4, -4 },
    { -4, 0 },
};
s16 D_80110B20_2BF3E0_name_41[1][2] = {
    { 6, 0 },
};
s16 D_80110B24_2BF3E4_name_41[2][2] = {
    { 4, 0 }, { 2, -2 },
};
s16 D_80110B2C_2BF3EC_name_41[2] = {
    -2, -2,
};
s16 D_80110B30_2BF3F0_name_41[2][2] = {
    { 0, 0 }, { 0, 0 },
};
s16 D_80110B38_2BF3F8_name_41[2][2] = {
    { 119, 84 }, { 121, 86 },
};
s16 D_80110B40_2BF400_name_41[8] = {
    91, 102, 106, 107, 108, 109, 110, 0,
};
s16 D_80110B50_2BF410_name_41[8] = {
    70, 71, 72, 73, 74, 75, 76, 0,
};
s32 D_80110B60_2BF420_name_41 = -1;
s16 D_80110B64_2BF424_name_41[2] = {
    92, 0,
};
s16 D_80110B68_2BF428_name_41[2] = {
    101, 103,
};
Vec D_80110B6C_2BF42C_name_41[5] = {
    { 0.0f, 0.0f, 0.0f }, { -3.0f, 2.0f, -2.0f }, { 1.0f, 5.5f, -3.0f },
    { 3.5f, 8.0f, 4.0f }, { -1.0f, 12.0f, 11.0f },
};
Vec D_80110BA8_2BF468_name_41[5] = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -15.0f, 0.0f, 0.0f },
    { 20.0f, 0.0f, -30.0f }, { 45.0f, 0.0f, 45.0f },
};
s16 D_80110BE4_2BF4A4_name_41[2] = {
    93, 94,
};
u8 D_80110BE8_2BF4A8_name_41[6][2] = {
    { 0, 115 }, { 0, 124 }, { 0, 128 }, { 0, 129 }, { 0, 130 }, { 0, 131 },
};
s32 D_80110BF4_2BF4B4_name_41[9] = {
    923, 944, 975, 970, 1008, 1029, -1, -1, -1,
};
s32 D_80110C18_2BF4D8_name_41[9] = {
    -1, -1, -1, -1, 1009, -1, -1, -1, -1,
};
s32 D_80110C3C_2BF4FC_name_41[9] = {
    -1, -1, -1, -1, 40, -1, -1, -1, -1,
};
s32 D_80110C60_2BF520_name_41[9] = {
    924, -1, 976, -1, -1, -1, -1, -1, -1,
};
s16 D_80110C84_2BF544_name_41[2] = {
    95, 97,
};
s16 D_80110C88_2BF548_name_41 = 96; /* +2 pad */
s16 D_80110C8C_2BF54C_name_41[2] = {
    111, 112,
};
s16 D_80110C90_2BF550_name_41[2][2] = {
    { 120, 124 }, { 122, 123 },
};
s32 D_80110C98_2BF558_name_41 = 0;
DecisionTreeNonLeafNode D_80110C9C_2BF55C_name_41[4] = {
    { 0x02000000, { (void*)0x41 }, { 0x6464 } },
    { 0x03000000, { (void*)0x94 }, { 0x5050 } },
    { 0x02000000, { (void*)0x18 }, { 0x4646 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80110CCC_2BF58C_name_41[4] = {
    { 0x10000000, { (void*)0x1 }, { (DtData)D_80110C9C_2BF55C_name_41 } },
    { 0x02000000, { (void*)0x41 }, { 0x6446 } },
    { 0x03000000, { (void*)0x94 }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80110CFC_2BF5BC_name_41[2] = {
    { 0x02000000, { (void*)0x71 }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80110D14_2BF5D4_name_41[1] = {
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
s16 D_80110D20_2BF5E0_name_41[4] = {
    93, 7, -1, 0,
};
DecisionTreeNonLeafNode D_80110D28_2BF5E8_name_41[2] = {
    { 0x02000000, { (void*)0x30 }, { 0x16464 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
BoardEventListEntry D_80110D40_2BF600_name_41[2] = {
    { 1, 2, func_80106C40_2B5500_name_41 },
    { 0, 0, NULL },
};
s16 D_80110D50_2BF610_name_41[4] = {
    94, 17, -1, 0,
};
BoardEventListEntry D_80110D58_2BF618_name_41[2] = {
    { 1, 2, func_80106F38_2B57F8_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110D68_2BF628_name_41[2] = {
    { 1, 1, func_80107230_2B5AF0_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110D78_2BF638_name_41[2] = {
    { 1, 1, func_80107254_2B5B14_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110D88_2BF648_name_41[2] = {
    { 1, 1, func_80107278_2B5B38_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110D98_2BF658_name_41[2] = {
    { 1, 1, func_8010729C_2B5B5C_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110DA8_2BF668_name_41[2] = {
    { 1, 1, func_801072C0_2B5B80_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110DB8_2BF678_name_41[2] = {
    { 1, 1, func_801072E4_2B5BA4_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110DC8_2BF688_name_41[2] = {
    { 1, 1, func_80107308_2B5BC8_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110DD8_2BF698_name_41[2] = {
    { 1, 1, func_8010732C_2B5BEC_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110DE8_2BF6A8_name_41[2] = {
    { 1, 1, func_80107350_2B5C10_name_41 },
    { 0, 0, NULL },
};
u8 D_80110DF8_2BF6B8_name_41[4] = {
    2, 5, 15, 20,
};
BoardEventListEntry D_80110DFC_2BF6BC_name_41[2] = {
    { 1, 1, func_80107574_2B5E34_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110E0C_2BF6CC_name_41[2] = {
    { 1, 1, func_80107DB4_2B6674_name_41 },
    { 0, 0, NULL },
};
u8 D_80110E1C_2BF6DC_name_41[3][4] = {
    { 0, 0, 1, 1 }, { 1, 2, 3, 3 }, { 4, 5, 6, 6 },
};
u8 D_80110E28_2BF6E8_name_41[4][3] = {
    { 1, 6, 16 }, { 1, 11, 21 }, { 1, 16, 36 }, { 0, 0, 0 },
};
s8 D_80110E34_2BF6F4_name_41[7][5] = {
    { 0, 1, -1, -1, -1 }, { 0, 1, 6, -1, -1 }, { 0, 1, 2, 6, -1 },
    { 0, 1, 4, 6, -1 }, { 0, 1, 2, 4, 6 }, { 0, 1, 4, 5, 6 },
    { 0, 1, 5, 6, 9 },
}; /* +1 pad */
u32 D_80110E58_2BF718_name_41[7] = {
    0x000001F2, 0x000001F3, 0x000001F4, 0x000001F5, 0x000001F6, 0x000001F7,
    0x000001F8,
};
BoardEventListEntry D_80110E74_2BF734_name_41[2] = {
    { 1, 1, func_80108298_2B6B58_name_41 },
    { 0, 0, NULL },
};
u8 D_80110E84_2BF744_name_41[4][3] = {
    { 1, 2, 3 }, { 0, 2, 3 }, { 0, 1, 3 }, { 0, 1, 2 },
};
Unk3EVec2f D_80110E90_2BF750_name_41[4] = {
    { 76.0f, 52.0f }, { 244.0f, 52.0f }, { 76.0f, 192.0f }, { 244.0f, 192.0f },
};
Unk3EVec2f D_80110EB0_2BF770_name_41[4] = {
    { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f },
};
s32 D_80110ED0_2BF790_name_41[6] = {
    134, 135, 136, 137, 138, 139,
};
Unk3ERange D_80110EE8_2BF7A8_name_41[6] = {
    { 1, 5, 15 }, { 6, 15, 25 }, { 16, 25, 27 }, { 26, 35, 30 }, { 36, 45, 32 },
    { 46, 50, 35 },
}; /* +2 pad */
Unk3ERange D_80110EFC_2BF7BC_name_41[14] = {
    { 0, 0, 0 }, { 1, 10, 1 }, { 11, 11, 4 }, { 12, 20, 2 }, { 21, 21, 4 },
    { 22, 30, 3 }, { 31, 40, 4 }, { 41, 44, 5 }, { 45, 46, 2 }, { 51, 56, 6 },
    { 57, 61, 5 }, { 62, 70, 7 }, { 71, 71, 8 }, { 72, 255, 9 },
}; /* +2 pad */
Unk3EStealRange D_80110F28_2BF7E8_name_41[24] = {
    { 1, 5, 6, 9, 7 }, { 1, 5, 10, 12, 8 }, { 1, 5, 13, 14, 9 },
    { 1, 5, 15, 15, 10 }, { 6, 15, 16, 19, 7 }, { 6, 15, 20, 22, 8 },
    { 6, 15, 23, 24, 9 }, { 6, 15, 25, 25, 10 }, { 16, 25, 18, 21, 7 },
    { 16, 25, 22, 24, 8 }, { 16, 25, 25, 26, 9 }, { 16, 25, 27, 27, 10 },
    { 26, 35, 21, 24, 7 }, { 26, 35, 25, 27, 8 }, { 26, 35, 28, 29, 9 },
    { 26, 35, 30, 30, 10 }, { 36, 45, 23, 26, 7 }, { 36, 45, 27, 29, 8 },
    { 36, 45, 30, 31, 9 }, { 36, 45, 32, 32, 10 }, { 46, 50, 26, 29, 7 },
    { 46, 50, 30, 32, 8 }, { 46, 50, 33, 34, 9 }, { 46, 50, 35, 35, 10 },
};
s16 D_80110FA0_2BF860_name_41[4] = {
    1723, 1724, 1725, 1726,
};
BoardEventListEntry D_80110FA8_2BF868_name_41[2] = {
    { 1, 1, func_8010A1B0_2B8A70_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110FB8_2BF878_name_41[2] = {
    { 1, 1, func_8010AB8C_2B944C_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80110FC8_2BF888_name_41[2] = {
    { 1, 1, func_8010ABA8_2B9468_name_41 },
    { 0, 0, NULL },
};
BoardEventTableEntry D_80110FD8_2BF898_name_41[13] = {
    { 2, D_80110DFC_2BF6BC_name_41 },
    { 19, D_80110DFC_2BF6BC_name_41 },
    { 32, D_80110DFC_2BF6BC_name_41 },
    { 39, D_80110DFC_2BF6BC_name_41 },
    { 90, D_80110DFC_2BF6BC_name_41 },
    { 70, D_80110DFC_2BF6BC_name_41 },
    { 82, D_80110DFC_2BF6BC_name_41 },
    { 77, D_80110E0C_2BF6CC_name_41 },
    { 37, D_80110E0C_2BF6CC_name_41 },
    { 115, D_80110E74_2BF734_name_41 },
    { 93, D_80110FB8_2BF878_name_41 },
    { 94, D_80110FC8_2BF888_name_41 },
    { -1, NULL },
};
BoardEventTableEntry D_80111040_2BF900_name_41[2] = {
    { 125, D_80110FA8_2BF868_name_41 },
    { -1, NULL },
};
Vec2f3E D_80111050_2BF910_name_41[4] = {
    { 108.0f, 41.0f }, { 244.0f, 41.0f }, { 108.0f, 209.0f },
    { 244.0f, 209.0f },
};
Vec2f3E D_80111070_2BF930_name_41[4] = {
    { 164.0f, 76.0f }, { 140.0f, 76.0f }, { 164.0f, 76.0f },
    { 140.0f, 76.0f },
};
Vec2f3E D_80111090_2BF950_name_41[4] = {
    { 132.0f, 62.0f }, { 220.0f, 62.0f }, { 132.0f, 180.0f },
    { 220.0f, 180.0f },
};
Vec2f3E D_801110B0_2BF970_name_41[4] = {
    { 164.0f, 66.0f }, { 140.0f, 66.0f }, { 164.0f, 66.0f },
    { 140.0f, 66.0f },
};
s32 D_801110D0_2BF990_name_41[6] = {
    709, 732, 762, 791, 823, 855,
};
s16 D_801110E8_2BF9A8_name_41[6] = {
    26, 27, 36, 30, 35, 37,
};
DecisionTreeNonLeafNode D_801110F4_2BF9B4_name_41[3] = {
    { 0x06000000, { func_8010E4B4_2BCD74_name_41 }, { 0x5A3C } },
    { 0x06000000, { func_8010E4D4_2BCD94_name_41 }, { 0x1E3C } },
    { 0x00000000, { (void*)0 }, { 0x1E } },
};
DecisionTreeNonLeafNode D_80111118_2BF9D8_name_41[3] = {
    { 0x03000000, { (void*)0x24 }, { 0x15032 } },
    { 0x0A000000, { (void*)0xC }, { (DtData)D_801110F4_2BF9B4_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_8011113C_2BF9FC_name_41[2] = {
    { 0x06000000, { func_8010E4F4_2BCDB4_name_41 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_80111154_2BFA14_name_41[3] = {
    { 0x03000000, { (void*)0x24 }, { 0x15032 } },
    { 0x0A000000, { (void*)0x17 }, { (DtData)D_8011113C_2BF9FC_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80111178_2BFA38_name_41[2] = {
    { 0x03000000, { (void*)0x24 }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80111190_2BFA50_name_41[4] = {
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80111118_2BF9D8_name_41 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_80111154_2BFA14_name_41 } },
    { 0x02000000, { (void*)0x1 }, { (DtData)D_80111178_2BFA38_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x16464 } },
};
DecisionTreeNonLeafNode D_801111C0_2BFA80_name_41[3] = {
    { 0x06000000, { func_8010E534_2BCDF4_name_41 }, { 0x5A3C } },
    { 0x06000000, { func_8010E554_2BCE14_name_41 }, { 0x1E3C } },
    { 0x00000000, { (void*)0 }, { 0x1E } },
};
DecisionTreeNonLeafNode D_801111E4_2BFAA4_name_41[2] = {
    { 0x0A000000, { (void*)0x7 }, { (DtData)D_801111C0_2BFA80_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_801111FC_2BFABC_name_41[4] = {
    { 0x03000000, { (void*)0x4 }, { 0x16446 } },
    { 0x03000000, { (void*)0x40 }, { 0x16446 } },
    { 0x03000000, { (void*)0x1 }, { 0x13232 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_8011122C_2BFAEC_name_41[2] = {
    { 0x0A000000, { (void*)0x15 }, { (DtData)D_801111C0_2BFA80_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80111244_2BFB04_name_41[3] = {
    { 0x03000000, { (void*)0x44 }, { 0x16446 } },
    { 0x03000000, { (void*)0x1 }, { 0x13232 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
DecisionTreeNonLeafNode D_80111268_2BFB28_name_41[5] = {
    { 0x02000000, { (void*)0x10 }, { (DtData)D_801111E4_2BFAA4_name_41 } },
    { 0x02000000, { (void*)0x3 }, { (DtData)D_801111FC_2BFABC_name_41 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_8011122C_2BFAEC_name_41 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_80111244_2BFB04_name_41 } },
    { 0x00000000, { (void*)0 }, { 0x16464 } },
};
BoardEventListEntry D_801112A4_2BFB64_name_41[2] = {
    { 1, 2, func_8010EADC_2BD39C_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_801112B4_2BFB74_name_41[2] = {
    { 1, 1, func_8010F33C_2BDBFC_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_801112C4_2BFB84_name_41[2] = {
    { 1, 1, func_8010F39C_2BDC5C_name_41 },
    { 0, 0, NULL },
};
s16 D_801112D4_2BFB94_name_41[3][2] = {
    { 118, 116 }, { 116, 117 }, { 117, 118 },
};
s16 D_801112E0_2BFBA0_name_41[3][2] = {
    { 98, 99 }, { 99, 100 }, { 100, 98 },
};
s16 D_801112EC_2BFBAC_name_41[3] = {
    20, 29, 3,
}; /* +2 pad */
BoardEventListEntry D_801112F4_2BFBB4_name_41[2] = {
    { 3, 2, func_8010F448_2BDD08_name_41 },
    { 0, 0, NULL },
};
s16 D_80111304_2BFBC4_name_41[16] = {
    8, 9, 10, 12, 13, 14, 15, 58, 59, 60, 61, 62, 63, 64, -1, 0,
};
s16 D_80111324_2BFBE4_name_41[12] = {
    23, 24, 25, 26, 42, 43, 45, 46, 47, 48, -1, 0,
};
s16* D_8011133C_2BFBFC_name_41[2] = {
    D_80111304_2BFBC4_name_41, D_80111324_2BFBE4_name_41,
};
s16 D_80111344_2BFC04_name_41[2] = {
    104, 105,
};
f32 D_80111348_2BFC08_name_41[4][2] = {
    { -12.0f, 15.0f }, { -2.0f, 15.0f }, { -12.0f, 25.0f },
    { -2.0f, 25.0f },
};
f32 D_80111368_2BFC28_name_41[2][2] = {
    { 0.0f, 0.0f }, { -18.0f, 0.0f },
};
BoardEventListEntry D_80111378_2BFC38_name_41[2] = {
    { 3, 2, func_801103B4_2BEC74_name_41 },
    { 0, 0, NULL },
};
BoardEventListEntry D_80111388_2BFC48_name_41[2] = {
    { 3, 2, func_801103D0_2BEC90_name_41 },
    { 0, 0, NULL },
};
BoardEventTableEntry D_80111398_2BFC58_name_41[26] = {
    { 119, D_80110D40_2BF600_name_41 },
    { 121, D_80110D58_2BF618_name_41 },
    { 113, D_80110D68_2BF628_name_41 },
    { 48, D_80110D78_2BF638_name_41 },
    { 112, D_80110D88_2BF648_name_41 },
    { 49, D_80110D98_2BF658_name_41 },
    { 89, D_80110DA8_2BF668_name_41 },
    { 57, D_80110DB8_2BF678_name_41 },
    { 111, D_80110DC8_2BF688_name_41 },
    { 83, D_80110DD8_2BF698_name_41 },
    { 85, D_80110DE8_2BF6A8_name_41 },
    { 16, D_801112B4_2BFB74_name_41 },
    { 23, D_801112C4_2BFB84_name_41 },
    { 120, D_801112A4_2BFB64_name_41 },
    { 122, D_801112A4_2BFB64_name_41 },
    { 3, D_801112F4_2BFBB4_name_41 },
    { 20, D_801112F4_2BFBB4_name_41 },
    { 29, D_801112F4_2BFBB4_name_41 },
    { 9, D_80111378_2BFC38_name_41 },
    { 12, D_80111378_2BFC38_name_41 },
    { 15, D_80111378_2BFC38_name_41 },
    { 60, D_80111378_2BFC38_name_41 },
    { 63, D_80111378_2BFC38_name_41 },
    { 25, D_80111388_2BFC48_name_41 },
    { 47, D_80111388_2BFC48_name_41 },
    { -1, NULL },
};
f32 D_80111468_2BFD28_name_41[4] = {
    0.0f, 0.0f, 320.0f, 240.0f,
};
DecisionTreeNonLeafNode D_80111478_2BFD38_name_41[3] = {
    { 0x0F000000, { (void*)0x1E }, { 0x1E } },
    { 0x0D000000, { (void*)0xB1317 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_8011149C_2BFD5C_name_41[8] = {
    { 0x0F000000, { (void*)0x5 }, { 0 } },
    { 0x0D000000, { (void*)0xB0D12 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x10004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0xB1819 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x40 }, { (DtData)D_80111478_2BFD38_name_41 } },
    { 0x0D000000, { (void*)0xB1317 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801114FC_2BFDBC_name_41[6] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0x20005 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x10D10 }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x23 }, { 0x1E } },
    { 0x0D000000, { (void*)0x1070C }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111544_2BFE04_name_41[5] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x40001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x30001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x20308 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111580_2BFE40_name_41[8] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0x50003 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40205 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x2 }, { (DtData)D_80111544_2BFE04_name_41 } },
    { 0x0D000000, { (void*)0x40001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x30001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x20308 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801115E0_2BFEA0_name_41[4] = {
    { 0x0F000000, { (void*)0x1E }, { 0x1E } },
    { 0x0D000000, { (void*)0x50008 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40205 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111610_2BFED0_name_41[6] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x50909 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x4 }, { (DtData)D_801115E0_2BFEA0_name_41 } },
    { 0x0D000000, { (void*)0x50008 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40205 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111658_2BFF18_name_41[2] = {
    { 0x06000000, { func_8010E4B4_2BCD74_name_41 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111670_2BFF30_name_41[2] = {
    { 0x06000000, { func_8010E514_2BCDD4_name_41 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111688_2BFF48_name_41[5] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x50D0E }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x1E }, { 0x1E } },
    { 0x0D000000, { (void*)0x5090C }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_801116C4_2BFF84_name_41[11] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0x70001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x50F17 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x40005 }, { (DtData)D_80111670_2BFF30_name_41 } },
    { 0x0D000000, { (void*)0x30001 }, { (DtData)D_80111670_2BFF30_name_41 } },
    { 0x0D000000, { (void*)0x20008 }, { (DtData)D_80111670_2BFF30_name_41 } },
    { 0x09000000, { (void*)0x8 }, { (DtData)D_80111688_2BFF48_name_41 } },
    { 0x0D000000, { (void*)0x50D0E }, { 0x5A3C } },
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x5090C }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111748_2C0008_name_41[5] = {
    { 0x0F000000, { (void*)0x19 }, { 0x1E } },
    { 0x0D000000, { (void*)0x90004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x70001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x51517 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111784_2C0044_name_41[11] = {
    { 0x0F000000, { (void*)0x14 }, { 0x1E } },
    { 0x0D000000, { (void*)0xB0006 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x90507 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x20008 }, { (DtData)D_80111658_2BFF18_name_41 } },
    { 0x0D000000, { (void*)0x10E10 }, { (DtData)D_80111658_2BFF18_name_41 } },
    { 0x0D000000, { (void*)0x40205 }, { (DtData)D_80111670_2BFF30_name_41 } },
    { 0x09000000, { (void*)0x10 }, { (DtData)D_80111748_2C0008_name_41 } },
    { 0x0D000000, { (void*)0x90004 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x70001 }, { 0x5A3C } },
    { 0x0D000000, { (void*)0x51517 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111808_2C00C8_name_41[3] = {
    { 0x0F000000, { (void*)0xA }, { 0 } },
    { 0x0D000000, { (void*)0xB000B }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_8011182C_2C00EC_name_41[5] = {
    { 0x0F000000, { (void*)0x5 }, { 0 } },
    { 0x0D000000, { (void*)0xB0C12 }, { 0x5A3C } },
    { 0x09000000, { (void*)0x20 }, { (DtData)D_80111808_2C00C8_name_41 } },
    { 0x0D000000, { (void*)0xB000B }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_80111868_2C0128_name_41[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_8011149C_2BFD5C_name_41 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_801114FC_2BFDBC_name_41 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_80111580_2BFE40_name_41 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_80111610_2BFED0_name_41 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_801116C4_2BFF84_name_41 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80111784_2C0044_name_41 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_8011182C_2C00EC_name_41 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_801118C8_2C0188_name_41[1] = {
    { 0x00000000, { (void*)0 }, { 0x5032 } },
};
DecisionTreeNonLeafNode D_801118D4_2C0194_name_41[3] = {
    { 0x0D000000, { (void*)0x10009 }, { 0xA } },
    { 0x0E000000, { (void*)0x10009 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_801118F8_2C01B8_name_41[7] = {
    { 0x0D000000, { (void*)0x40001 }, { 0xA } },
    { 0x0D000000, { (void*)0x30001 }, { 0xA } },
    { 0x0D000000, { (void*)0x20008 }, { 0xA } },
    { 0x0E000000, { (void*)0x40001 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x30001 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x20008 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_8011194C_2C020C_name_41[3] = {
    { 0x0D000000, { (void*)0x50008 }, { 0xA } },
    { 0x0E000000, { (void*)0x50008 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80111970_2C0230_name_41[3] = {
    { 0x0D000000, { (void*)0x5050E }, { 0xA } },
    { 0x0E000000, { (void*)0x5050E }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80111994_2C0254_name_41[7] = {
    { 0x0D000000, { (void*)0x90004 }, { 0xA } },
    { 0x0D000000, { (void*)0x70001 }, { 0xA } },
    { 0x0D000000, { (void*)0x80003 }, { 0xA } },
    { 0x0E000000, { (void*)0x90004 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x70001 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0x80003 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_801119E8_2C02A8_name_41[3] = {
    { 0x0D000000, { (void*)0xB000B }, { 0xA } },
    { 0x0E000000, { (void*)0xB000B }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80111A0C_2C02CC_name_41[5] = {
    { 0x0D000000, { (void*)0xC0002 }, { 0xA } },
    { 0x0D000000, { (void*)0xB0D17 }, { 0xA } },
    { 0x0E000000, { (void*)0xC0002 }, { 0x5A3C } },
    { 0x0E000000, { (void*)0xB0D17 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_80111A48_2C0308_name_41[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_801118D4_2C0194_name_41 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_801118F8_2C01B8_name_41 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_8011194C_2C020C_name_41 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_80111970_2C0230_name_41 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_80111994_2C0254_name_41 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_801119E8_2C02A8_name_41 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_80111A0C_2C02CC_name_41 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80111AA8_2C0368_name_41[2] = {
    { 0x0D000000, { (void*)0x10409 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111AC0_2C0380_name_41[4] = {
    { 0x0D000000, { (void*)0x40001 }, { 0 } },
    { 0x0D000000, { (void*)0x30001 }, { 0 } },
    { 0x0D000000, { (void*)0x20508 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111AF0_2C03B0_name_41[2] = {
    { 0x0D000000, { (void*)0x50308 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111B08_2C03C8_name_41[2] = {
    { 0x0D000000, { (void*)0x5090E }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111B20_2C03E0_name_41[4] = {
    { 0x0D000000, { (void*)0x90004 }, { 0 } },
    { 0x0D000000, { (void*)0x70101 }, { 0 } },
    { 0x0D000000, { (void*)0x80303 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111B50_2C0410_name_41[2] = {
    { 0x0D000000, { (void*)0xB060B }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111B68_2C0428_name_41[2] = {
    { 0x0D000000, { (void*)0xB1117 }, { 0 } },
    { 0x00000000, { (void*)0 }, { 0x6464 } },
};
DecisionTreeNonLeafNode D_80111B80_2C0440_name_41[8] = {
    { 0x02000000, { (void*)0x1 }, { (DtData)D_80111AA8_2C0368_name_41 } },
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80111AC0_2C0380_name_41 } },
    { 0x02000000, { (void*)0x4 }, { (DtData)D_80111AF0_2C03B0_name_41 } },
    { 0x02000000, { (void*)0x8 }, { (DtData)D_80111B08_2C03C8_name_41 } },
    { 0x02000000, { (void*)0x10 }, { (DtData)D_80111B20_2C03E0_name_41 } },
    { 0x02000000, { (void*)0x20 }, { (DtData)D_80111B50_2C0410_name_41 } },
    { 0x02000000, { (void*)0x40 }, { (DtData)D_80111B68_2C0428_name_41 } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80111BE0_2C04A0_name_41[2] = {
    { 0x02000000, { (void*)0x50 }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80111BF8_2C04B8_name_41[2] = {
    { 0x02000000, { (void*)0x7D }, { 0x5A3C } },
    { 0x00000000, { (void*)0 }, { 0 } },
};
DecisionTreeNonLeafNode D_80111C10_2C04D0_name_41[2] = {
    { 0x01000000, { (void*)0x1E }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x1E } },
};
DecisionTreeNonLeafNode D_80111C28_2C04E8_name_41[5] = {
    { 0x0A000000, { (void*)0xE }, { (DtData)D_80111C10_2C04D0_name_41 } },
    { 0x01000000, { (void*)0x32 }, { 0x6446 } },
    { 0x01000000, { (void*)0x28 }, { 0x503C } },
    { 0x01000000, { (void*)0x1E }, { 0x3232 } },
    { 0x00000000, { (void*)0 }, { 0x1432 } },
};
DecisionTreeNonLeafNode D_80111C64_2C0524_name_41[3] = {
    { 0x02000000, { (void*)0x2 }, { (DtData)D_80111C28_2C04E8_name_41 } },
    { 0x01000000, { (void*)0x1E }, { 0x6446 } },
    { 0x00000000, { (void*)0 }, { 0x5A3C } },
};
s32 D_80111C88_2C0548_name_41 = 0;
u8 D_80111C8C_2C054C_name_41[12] = {
    9, 6, 0, 7, 4, 8, 2, 5, 1, 0, 0, 0,
};
u8 D_80111C98_2C0558_name_41[12] = {
    9, 1, 6, 7, 4, 8, 0, 2, 5, 0, 0, 0,
};
u8 D_80111CA4_2C0564_name_41[12] = {
    9, 7, 2, 6, 4, 8, 0, 5, 1, 0, 0, 0,
};
u8 D_80111CB0_2C0570_name_41[12] = {
    9, 5, 7, 6, 4, 8, 0, 2, 1, 0, 0, 0,
};
u8 D_80111CBC_2C057C_name_41[12] = {
    9, 4, 8, 7, 6, 0, 2, 5, 1, 0, 0, 0,
};
u8 D_80111CC8_2C0588_name_41[12] = {
    9, 7, 6, 4, 8, 0, 2, 5, 1, 0, 0, 0,
};
u8* D_80111CD4_2C0594_name_41[6] = {
    D_80111C8C_2C054C_name_41, D_80111C98_2C0558_name_41,
    D_80111CA4_2C0564_name_41, D_80111CB0_2C0570_name_41,
    D_80111CBC_2C057C_name_41, D_80111CC8_2C0588_name_41,
};
s8 D_80111CEC_2C05AC_name_41[12] = {
    100, 70, 60, 0, 50, 0, 30, 30, 10, 0, 0, 0,
};
s8 D_80111CF8_2C05B8_name_41[12] = {
    100, 70, 60, 0, 50, 0, 20, 30, 30, 0, 0, 0,
};
s8 D_80111D04_2C05C4_name_41[12] = {
    100, 70, 60, 60, 50, 0, 20, 30, 10, 0, 0, 0,
};
s8 D_80111D10_2C05D0_name_41[12] = {
    100, 70, 60, 60, 50, 0, 20, 30, 10, 0, 0, 0,
};
s8 D_80111D1C_2C05DC_name_41[12] = {
    100, 70, 60, 0, 60, 20, 30, 30, 10, 0, 0, 0,
};
s8 D_80111D28_2C05E8_name_41[12] = {
    100, 70, 60, 50, 0, 20, 30, 30, 10, 0, 0, 0,
};
s8* D_80111D34_2C05F4_name_41[6] = {
    D_80111CEC_2C05AC_name_41, D_80111CF8_2C05B8_name_41,
    D_80111D04_2C05C4_name_41, D_80111D10_2C05D0_name_41,
    D_80111D1C_2C05DC_name_41, D_80111D28_2C05E8_name_41,
};
u8 D_80111D4C_2C060C_name_41[20] = {
    9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s16 func_80102830_2B10F0_name_41(void) {
    return D_80110AA4_2BF364_name_41[GwSystem.star_spawn_indices[GwSystem.unk_0A]];
}

void func_8010285C_2B111C_name_41(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = (u8)(rand8() % 7);
        b = (u8)(rand8() % 7);
        if (a != b) {
            if (a >= D_80110A70_2BF330_name_41[b]) {
                if (b >= D_80110A70_2BF330_name_41[a]) {
                    temp = D_80110A60_2BF320_name_41[a];
                    D_80110A60_2BF320_name_41[a] = D_80110A60_2BF320_name_41[b];
                    D_80110A60_2BF320_name_41[b] = temp;

                    temp = D_80110A70_2BF330_name_41[a];
                    D_80110A70_2BF330_name_41[a] = D_80110A70_2BF330_name_41[b];
                    D_80110A70_2BF330_name_41[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = D_80110A60_2BF320_name_41[i];
    }

    if (gw->unk_1C == -1) {
        temp = 0;
    retry:
        gw->unk_1C = gw->star_spawn_indices[6 - temp];
        for (i = 0; D_80110A80_2BF340_name_41[i] != -1; i++) {
            if (gw->unk_1C == D_80110A80_2BF340_name_41[i]) {
                temp++;
                goto retry;
            }
        }
    }
}

void func_80102A44_2B1304_name_41(void) {
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

void func_80102AB0_2B1370_name_41(void) {
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    gw->unk_1C = gw->star_spawn_indices[gw->unk_0A];
    if (++gw->unk_0A < 7) {
        return;
    }
    temp = gw->star_spawn_indices[6];
    gw->unk_0A = 0;
    _SetFlag(0x44);
    func_8010285C_2B111C_name_41();
    if (temp != gw->star_spawn_indices[0]) {
        return;
    }
    temp = gw->star_spawn_indices[0];
    gw->star_spawn_indices[0] = gw->star_spawn_indices[6];
    gw->star_spawn_indices[6] = temp;
}

void func_80102B54_2B1414_name_41(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 7; i++) {
        _SetFlag(D_80110A84_2BF344_name_41[i]);
    }
    BoardSpaceTypeSet(D_80110A94_2BF354_name_41[gw->star_spawn_indices[gw->unk_0A]], 0xE);
    _ClearFlag(D_80110A84_2BF344_name_41[gw->star_spawn_indices[gw->unk_0A]]);
    if (gw->unk_1C != -1) {
        BoardSpaceTypeSet(D_80110A94_2BF354_name_41[gw->unk_1C], 0xF);
        func_800509C4_515C4(D_80110A94_2BF354_name_41[gw->unk_1C]);
    }
}

/* D_80111974 address hoisted out of the loop (masked 10); logic matches */
#ifdef NON_MATCHING
s32 func_80102C3C_2B14FC_name_41(s32 space) {
    s32 i;
    s32 j;
    s16* spaces;
    GW_SYSTEM* gw = &GwSystem;

    i = 0;
    spaces = D_80110A94_2BF354_name_41;
    space = (s16)space;
    do {
        if (space == spaces[i]) {
            if (i == gw->star_spawn_indices[gw->unk_0A]) {
                gw->unk_1A = D_80110A84_2BF344_name_41[i];
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80102C3C_2B14FC_name_41);
#endif

void func_80102D28_2B15E8_name_41(void) {
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
    D_80111EC0_2C0780_name_41 = NULL;
    omDelPrcObj(NULL);
}

void func_80102F4C_2B180C_name_41(UnkMBGuideData* guide) {
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

void func_80102FFC_2B18BC_name_41(void) {
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
    func_8005AB50_5B750(guide->obj, 2, 8, D_80110AB4_2BF374_name_41);
    func_80067558_68158();
    InitFadeIn(2, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    func_80053608_54208(3.0f);
    func_80102F4C_2B180C_name_41(guide);
    if (gw->unk_0A == 0 && !_CheckFlag(0x44)) {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B1 : 0x6AF;
    } else {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B1 : 0x6B0;
    }
    func_800890CC_89CCC(guide->amount, mes, -1, -1);
    func_8008E2DC_8EEDC(guide->amount, 1);
    PlaySound(0x11E);
    func_80057DC0_589C0(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_8005B338_5BF38(guide);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8002D4A0_2E0A0(guide->obj->obj->model[0]);
    if (D_800F8D12_F9912 != 0 && (u8)(pick = rand8() & 1) == 0) {
        space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->unk_1C]);
    } else {
        space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->star_spawn_indices[gw->unk_0A]]);
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
        proc = omAddPrcObj(func_80102D28_2B15E8_name_41, 0x4800, 0, 0);
        D_80111EC0_2C0780_name_41 = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_80111EC0_2C0780_name_41 = NULL;
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
        while (D_80111EC0_2C0780_name_41 != NULL) {
            HuPrcVSleep();
        }
        if (D_800F8D12_F9912 != 0 && (u8)pick == 0) {
            space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->star_spawn_indices[gw->unk_0A]]);
        } else {
            space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->unk_1C]);
        }
        MBDCameraPos3DSet(&space->coords);
        MBCameraSpeedSet(3.5f);
        HuPrcSleep(5);
        while (func_80053998_54598() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(5);
        MBMotionSet(guide->obj, 0, 2);
        func_80029FE4_2ABE4(guide->obj->obj->model[0], D_80110ABC_2BF37C_name_41[gw->current_board_index]);
        func_8005B338_5BF38(guide);
        func_8005AC6C_5B86C(guide->obj, D_80110AB8_2BF378_name_41);
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

void func_80103548_2B1E08_name_41(void) {
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
    PlaySound(D_80110AE0_2BF3A0_name_41 == 0 ? 0x355 : 0x34E);
    star = func_80043510_44110(D_80111EC4_2C0784_name_41 == 0 ? 0x19 : 0xD, NULL);
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
    if (D_80111EC4_2C0784_name_41 == 0) {
        MBPlayerVibrate(-1, 5);
        if (D_80110AE0_2BF3A0_name_41 != 0) {
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

void func_80103968_2B2228_name_41(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80111EC4_2C0784_name_41 = 0;
    proc = omAddPrcObj(func_80103548_2B1E08_name_41, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_801039E4_2B22A4_name_41(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80111EC4_2C0784_name_41 = 1;
    proc = omAddPrcObj(func_80103548_2B1E08_name_41, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103A64_2B2324_name_41(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

void func_80103AF4_2B23B4_name_41(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

s32 func_80103B70_2B2430_name_41(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_80103BC4_2B2484_name_41(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80111EC8_2C0788_name_41 = func_8004CC7C_4D87C(0, 0x92, 1);
    D_80111ECC_2C078C_name_41 = func_8004CC7C_4D87C(1, 0xA0, 1);
    D_80111ED8_2C0798_name_41 = func_8004CC7C_4D87C(0xD, 0xAE, 1);
    D_80111ED0_2C0790_name_41 = func_8004CC7C_4D87C(3, 0xBC, 1);
    D_80111ED4_2C0794_name_41 = func_8004CC7C_4D87C(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800FA198_FAD98 = 1;
    D_80101058_101C58 = 1;
}

void func_80103C94_2B2554_name_41(void) {
    D_800FA198_FAD98 = 0;
    D_80101058_101C58 = 0;
    MBHelpWinKill(D_80111EC8_2C0788_name_41);
    MBHelpWinKill(D_80111ECC_2C078C_name_41);
    MBHelpWinKill(D_80111ED8_2C0798_name_41);
    MBHelpWinKill(D_80111ED0_2C0790_name_41);
    MBHelpWinKill(D_80111ED4_2C0794_name_41);
}

__asm__(".section .rodata");
const u8 D_80111D60_2C0620_name_41[4] = { 1, 2, 4, 8 };

s32 func_80103CF4_2B25B4_name_41(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80110664_2BEF24_name_41();
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

s32 func_80103FB0_2B2870_name_41(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_801109E0_2BF2A0_name_41();
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

s32 func_801041D4_2B2A94_name_41(void) {
    s32 com = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
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

void func_80104380_2B2C40_name_41(void) {
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
            D_80111F00_2C07C0_name_41 = 1;
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
        if (func_80103B70_2B2430_name_41() < D_80110AE4_2BF3A4_name_41[turnBand][coinBand]) {
            D_80111F00_2C07C0_name_41 = 1;
        } else {
            goto coins;
        }
    }
    if (D_80111F00_2C07C0_name_41 == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_80111F00_2C07C0_name_41 = 0;
    } else {
        D_80111F00_2C07C0_name_41 = 2;
    }
}

s32 func_801045C0_2B2E80_name_41(void) {
    s32 flags[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 min;

    if (GwSystem.current_player_index != D_80111EF0_2C07B0_name_41[0]) {
        coins = gPlayers[D_80111EF0_2C07B0_name_41[0]].coins;
        i = 1;
        flags[0] = 1;
    } else {
        coins = gPlayers[D_80111EF0_2C07B0_name_41[1]].coins;
        i = 2;
        flags[1] = 1;
    }
    for (; i < 4; i++) {
        if (GwSystem.current_player_index != D_80111EF0_2C07B0_name_41[i]
            && gPlayers[D_80111EF0_2C07B0_name_41[i]].coins + 5 >= coins) {
            flags[i] = 1;
        }
    }
    min = 4;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0 && func_80059FD0_5ABD0(D_80111EF0_2C07B0_name_41[i]) < min) {
            min = func_80059FD0_5ABD0(D_80111EF0_2C07B0_name_41[i]);
        }
    }
    return min;
}

/* MP1 func_800F6B3C (ovl_65) logic, checked case by case against this asm; retail keeps the
   duplicate cases apart and reloads stars between tests (masked 541) */
#ifdef NON_MATCHING
void func_80104778_2B3038_name_41(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_80103B70_2B2430_name_41();
    switch (D_80111F00_2C07C0_name_41) {
    case 1:
        if (GwSystem.total_turns < GwSystem.current_turn + 5) {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars < 2) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                        D_80111F08_2C07C8_name_41 = 2;
                        break;
                    }
                }
                D_80111F08_2C07C8_name_41 = 1;
                break;
            case 1:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 2;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 2:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 3:
                if (r > 94 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            }
        } else {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 80 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars < 2) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                        D_80111F08_2C07C8_name_41 = 2;
                        break;
                    }
                }
                D_80111F08_2C07C8_name_41 = 1;
                break;
            case 1:
                if (r >= 90 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 2;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 2:
                if (r >= 90 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 3:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
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
            || (GwSystem.total_turns < GwSystem.current_turn + 5 && func_80103B70_2B2430_name_41() < 80)
            || func_80103B70_2B2430_name_41() < 40) {
            if (GwSystem.total_turns < GwSystem.current_turn + 5) {
                if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[1]].coins == 0) {
                        goto steal;
                    }
                    if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_80111F08_2C07C8_name_41 = 1;
                        return;
                    }
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 1 <= gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 2 == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
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
                if (gPlayers[D_80111EE0_2C07A0_name_41[1]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars != gPlayers[D_80111EE0_2C07A0_name_41[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_80111F08_2C07C8_name_41 = 1;
                return;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].coins == 0) {
                goto steal;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 1 <= gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 2 == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_80111F08_2C07C8_name_41 = 0;
            return;
        steal:
            D_80111F08_2C07C8_name_41 = func_801045C0_2B2E80_name_41();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_80111EE0_2C07A0_name_41[i]] != 0) {
                if (--count == 0) {
                    D_80111F08_2C07C8_name_41 = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80104778_2B3038_name_41);
#endif

/* register allocation: i/coin-rank/j registers rotated (masked 0), as in MP1 func_800F7278 */
#ifdef NON_MATCHING
void func_80104F7C_2B383C_name_41(void) {
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
        D_80111EE0_2C07A0_name_41[i] = -1;
        D_80111EF0_2C07B0_name_41[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        rank = func_80059FD0_5ABD0(i);
    starSlot:
        if (D_80111EE0_2C07A0_name_41[rank] != -1) {
            rank++;
            goto starSlot;
        }
        D_80111EE0_2C07A0_name_41[rank] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
    coinSlot:
        if (D_80111EF0_2C07B0_name_41[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_80111EF0_2C07B0_name_41[coinRank] = i;
    }
    D_80111F00_2C07C0_name_41 = D_80111F04_2C07C4_name_41 = D_80111F08_2C07C8_name_41 = -1;
    func_80104380_2B2C40_name_41();
    if (D_80111F08_2C07C8_name_41 == -1) {
        func_80104778_2B3038_name_41();
    }
    while (starRankCount[D_80111F08_2C07C8_name_41] == 0) {
        D_80111F08_2C07C8_name_41--;
    }
    rank = func_80059FD0_5ABD0(GwSystem.current_player_index);
    if (rank == D_80111F08_2C07C8_name_41) {
        starRankCount[rank]--;
    }
    j = rand8() % starRankCount[D_80111F08_2C07C8_name_41];
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            continue;
        }
        if (D_80111F08_2C07C8_name_41 != func_80059FD0_5ABD0(i)) {
            continue;
        }
        if (j != 0) {
            j--;
            continue;
        }
        D_80111F04_2C07C4_name_41 = i;
        break;
    }
    if (D_80111F00_2C07C0_name_41 == 0 && gPlayers[D_80111F04_2C07C4_name_41].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
                D_80111F04_2C07C4_name_41 = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80104F7C_2B383C_name_41);
#endif

s32 func_8010537C_2B3C3C_name_41(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                func_80104F7C_2B383C_name_41();
                count = D_80111F00_2C07C0_name_41 + 1;
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

s32 func_80105630_2B3EF0_name_41(s32 arg0, u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = D_80111F04_2C07C4_name_41;
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

void func_801058A4_2B4164_name_41(void) {
    GwSystem.current_board_index = 1;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_801058E0_2B41A0_name_41(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    _SetFlag(0x43);
    func_8010285C_2B111C_name_41();
    D_800F8CE4_F98E4[0] = 0;
    D_800F8CE4_F98E4[1] = 0;
    D_800F8CE4_F98E4[2] = 0;
    D_800F8CE4_F98E4[0x1E] = 0;
    D_800F8CE4_F98E4[0x1D] = 0;
    D_800F8CE4_F98E4[0x1A] = 0;
    D_800F8CE4_F98E4[0x19] = 0;
    D_800F8CE4_F98E4[0x17] = 0;
    omOvlReturnEx(1);
}

void func_80105980_2B4240_name_41(void) {
    s32 i;
    SpaceData* from;

    omInitObjMan(0xA0, 0x28);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(10, 0x41, 15, 0);
    func_80055928_56528(D_80110AF0_2BF3B0_name_41);
    func_80055980_56580(D_80110AF4_2BF3B4_name_41);
    {
        Vec dir;

        from = GetSpaceData(0x73);
        func_80056658_57258(&from->coords, &GetSpaceData(0x60)->coords, &dir);
        MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    }
    func_8004D60C_4E20C(0, func_8010A1B0_2B8A70_name_41);
    func_8004D60C_4E20C(1, func_8010AE1C_2B96DC_name_41);
    func_8004D60C_4E20C(8, func_8010B1B8_2B9A78_name_41);
    func_8004D60C_4E20C(2, func_8010B228_2B9AE8_name_41);
    func_8004D60C_4E20C(3, func_8010C598_2BAE58_name_41);
    func_8004D60C_4E20C(4, func_8010CB10_2BB3D0_name_41);
    func_8004D60C_4E20C(5, func_8010CD80_2BB640_name_41);
    func_8004D60C_4E20C(6, func_8010B70C_2B9FCC_name_41);
    func_8004D60C_4E20C(7, func_8010C134_2BA9F4_name_41);
    func_8004D60C_4E20C(9, func_8010CFB4_2BB874_name_41);
    func_8004D60C_4E20C(10, func_8010D2C8_2BBB88_name_41);
    func_8004D60C_4E20C(12, func_8010D93C_2BC1FC_name_41);
    func_8004D60C_4E20C(11, func_8010DB70_2BC430_name_41);
    func_8004D60C_4E20C(13, func_8010E080_2BC940_name_41);
    func_80044D98_45998(func_80110440_2BED00_name_41);
    for (i = 0; i < 7; i++) {
        func_800542E8_54EE8(i, D_80110AA4_2BF364_name_41[i]);
    }
    if (_CheckFlag(0x4D)) {
        _ClearFlag(0x4D);
        if (D_800F8D12_F9912 != 0) {
            func_80102A44_2B1304_name_41();
        } else {
            func_80102AB0_2B1370_name_41();
        }
    }
    func_80102B54_2B1414_name_41();
    func_80105E28_2B46E8_name_41();
    func_80105DA0_2B4660_name_41();
    func_80106078_2B4938_name_41();
    func_8010633C_2B4BFC_name_41();
    func_80106500_2B4DC0_name_41();
    func_801066CC_2B4F8C_name_41();
    func_80106744_2B5004_name_41();
    func_80106904_2B51C4_name_41();
}

void func_80105BE8_2B44A8_name_41(void) {
    PlayMusic(9);
    func_800632F0_63EF0(9);
    func_80020070_20C70(2);
    func_80105980_2B4240_name_41();
    omAddObj(1000, 0, 0, -1, func_80106964_2B5224_name_41);
    func_80053AA0_546A0(1);
    EventTableHydrate(D_80110FD8_2BF898_name_41);
    EventTableHydrate(D_80111398_2BFC58_name_41);
    EventTableHydrate(D_80111040_2BF900_name_41);
    func_80066C34_67834(0);
}

void func_80105C70_2B4530_name_41(void) {
    func_80020070_20C70(1);
    func_80105980_2B4240_name_41();
    func_80066C34_67834(1);
}

void func_80105C9C_2B455C_name_41(s16 arg0) {
    MBModel* obj;

    if (D_80111F10_2C07D0_name_41[arg0] == NULL) {
        if (D_80111F0C_2C07CC_name_41 == NULL) {
            obj = func_80043510_44110(0x17, NULL);
            func_80043DAC_449AC(obj);
            D_80111F0C_2C07CC_name_41 = obj;
        } else {
            obj = MBModelParamCreate(D_80111F0C_2C07CC_name_41);
        }
        D_80111F10_2C07D0_name_41[arg0] = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B40_2BF400_name_41[arg0])->coords);
        func_80041AEC_426EC(6, obj, D_80110B04_2BF3C4_name_41[arg0][0], D_80110B04_2BF3C4_name_41[arg0][1]);
    }
}

void func_80105DA0_2B4660_name_41(void) {
    s32 i;

    D_80111F0C_2C07CC_name_41 = NULL;
    for (i = 0; i < 7; i++) {
        D_80111F10_2C07D0_name_41[i] = NULL;
        if (_CheckFlag(D_80110B50_2BF410_name_41[i]) == 0) {
            func_80105C9C_2B455C_name_41(i);
        }
    }
}

void func_80105E28_2B46E8_name_41(void) {
    MBModel* obj;
    GW_SYSTEM* gw = &GwSystem;

    if (gw->unk_1C != -1) {
        obj = func_80043510_44110(D_800F8D12_F9912 != 0 ? 0x17 : 0x1D, NULL);
        func_80043DAC_449AC(obj);
        D_800F64C8_F70C8 = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B40_2BF400_name_41[gw->unk_1C])->coords);
        D_80110B60_2BF420_name_41 = func_80041AEC_426EC(0xB, obj, D_80110B04_2BF3C4_name_41[gw->unk_1C][0],
                                                       D_80110B04_2BF3C4_name_41[gw->unk_1C][1]);
    } else {
        D_800F64C8_F70C8 = NULL;
    }
}

void func_80105F10_2B47D0_name_41(void) {
    if (D_800F64C8_F70C8 != NULL) {
        MBModelKill(D_800F64C8_F70C8);
    }
    if (D_80110B60_2BF420_name_41 != -1) {
        func_80041B40_42740(D_80110B60_2BF420_name_41);
    }
}

void func_80105F58_2B4818_name_41(s16 arg0) {
    MBModel* obj;

    if (D_80111F30_2C07F0_name_41[arg0] != NULL) {
        return;
    }
    if (D_80111F2C_2C07EC_name_41 == NULL) {
        obj = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(obj->obj->model[0]);
        func_8002D124_2DD24(obj->shadow->model[0]);
        D_80111F2C_2C07EC_name_41 = obj;
    } else {
        obj = MBModelParamCreate(D_80111F2C_2C07EC_name_41);
    }
    MBModelDispOff(obj);
    D_80111F30_2C07F0_name_41[arg0] = obj;
    obj->attr |= 2;
    obj->jumpY = 10.0f;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B64_2BF424_name_41[arg0])->coords);
    func_80041AEC_426EC(8, obj, D_80110B20_2BF3E0_name_41[arg0][0], D_80110B20_2BF3E0_name_41[arg0][1]);
}

void func_80106078_2B4938_name_41(void) {
    s32 i;

    D_80111F2C_2C07EC_name_41 = NULL;
    for (i = 0; i < 1; i++) {
        D_80111F30_2C07F0_name_41[i] = NULL;
        func_80105F58_2B4818_name_41(i);
    }
}

void func_801060D4_2B4994_name_41(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 2; i++) {
        count = (D_800F8CE4_F98E4[0x1D] + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_80111F38_2C07F8_name_41[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_80111F38_2C07F8_name_41[i * 5 + j]);
        }
    }
}

void func_801061D0_2B4A90_name_41(s16 arg0) {
    MBModel* coin;
    Vec* pos;
    s32 bank;
    s16 slot;

    if (D_80111F38_2C07F8_name_41[arg0] == NULL) {
        if (D_80111F34_2C07F4_name_41 == NULL) {
            coin = func_80043510_44110(0x6C, NULL);
            func_80043DAC_449AC(coin);
            D_80111F34_2C07F4_name_41 = coin;
        } else {
            coin = MBModelParamCreate(D_80111F34_2C07F4_name_41);
        }
        D_80111F38_2C07F8_name_41[arg0] = coin;
        coin->attr |= 2;

        bank = arg0 / 5;
        pos = &coin->pos;
        func_800B3170_B3D70(pos, &GetSpaceData(D_80110B68_2BF428_name_41[bank])->coords);

        slot = arg0 % 5;
        HuVecAdd(pos, &D_80110B6C_2BF42C_name_41[slot], pos);
        coin->obj->rot.x = D_80110BA8_2BF468_name_41[slot].x;
        coin->obj->rot.z = D_80110BA8_2BF468_name_41[slot].z;
        MBModelDispOff(coin);
    }
}

void func_8010633C_2B4BFC_name_41(void) {
    s32 i;

    D_80111F34_2C07F4_name_41 = NULL;
    for (i = 0; i < 10; i++) {
        D_80111F38_2C07F8_name_41[i] = NULL;
        func_801061D0_2B4A90_name_41(i);
    }
    func_801060D4_2B4994_name_41();
}

void func_801063A4_2B4C64_name_41(s16 arg0) {
    MBModel* obj;
    SpaceData* space;
    char pad[4]; /* frame size, as MP3 func_80108748 (ChillyWaters) */

    if (D_80111F64_2C0824_name_41[arg0] == NULL) {
        if (D_80111F60_2C0820_name_41 == NULL) {
            /* D_80111AED[board * 2]: column 1 of a u8 [][2] table one byte before it */
            obj = func_80043510_44110(D_80110BE9_2BF4A9_name_41[GwSystem.current_board_index * 2], NULL);
            func_80043DAC_449AC(obj);
            D_80111F60_2C0820_name_41 = obj;
        } else {
            obj = MBModelParamCreate(D_80111F60_2C0820_name_41);
        }
        D_80111F64_2C0824_name_41[arg0] = obj;
        obj->attr |= 2;
        func_80029E80_2AA80(obj->obj->model[0], 2, 1);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110BE4_2BF4A4_name_41[arg0])->coords);
        space = GetSpaceData(D_80110B38_2BF3F8_name_41[arg0][0]);
        func_80056658_57258(&GetSpaceData(D_80110B38_2BF3F8_name_41[arg0][1])->coords, &space->coords, &obj->rot);
        func_80041AEC_426EC(0xC, obj, D_80110B30_2BF3F0_name_41[arg0][0], D_80110B30_2BF3F0_name_41[arg0][1]);
    }
}

void func_80106500_2B4DC0_name_41(void) {
    s32 i;

    D_80111F60_2C0820_name_41 = NULL;
    for (i = 0; i < 2; i++) {
        D_80111F64_2C0824_name_41[i] = NULL;
        func_801063A4_2B4C64_name_41(i);
    }
}

void func_80106560_2B4E20_name_41(void) {
    HuPrcSleep(D_80110C3C_2BF4FC_name_41[GwSystem.current_board_index]);
    PlaySound((s16)D_80110C18_2BF4D8_name_41[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_801065BC_2B4E7C_name_41(s32 arg0) {
    func_80029E80_2AA80(D_80111F64_2C0824_name_41[arg0]->obj->model[0], 5, 0);
    if (D_80110BF4_2BF4B4_name_41[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110BF4_2BF4B4_name_41[GwSystem.current_board_index]);
    }
    if (D_80110C18_2BF4D8_name_41[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80106560_2B4E20_name_41, 0x1000, 0, 0);
    }
}

void func_80106660_2B4F20_name_41(s32 arg0) {
    func_80029E80_2AA80(D_80111F64_2C0824_name_41[arg0]->obj->model[0], 1, 4);
    if (D_80110C60_2BF520_name_41[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110C60_2BF520_name_41[GwSystem.current_board_index]);
    }
}

void func_801066CC_2B4F8C_name_41(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80041B60_42760(10, &GetSpaceData(D_80110C84_2BF544_name_41[i])->coords, D_80110B24_2BF3E4_name_41[i][0],
                            D_80110B24_2BF3E4_name_41[i][1]);
    }
}

void func_80106744_2B5004_name_41(void) {
    func_80041B60_42760(9, &GetSpaceData(D_80110C88_2BF548_name_41)->coords, D_80110B2C_2BF3EC_name_41[0],
                        D_80110B2C_2BF3EC_name_41[1]);
}

void func_80106780_2B5040_name_41(s16 arg0) {
    MBModel* obj;
    f32 scale;
    SpaceData* from;
    s32 pad[2]; /* retail's frame has 8 unused bytes */

    if (D_80111F70_2C0830_name_41[arg0] != NULL) {
        return;
    }
    if (D_80111F6C_2C082C_name_41 == NULL) {
        obj = func_80043510_44110(0xB, NULL);
        func_80043DAC_449AC(obj);
        D_80111F6C_2C082C_name_41 = obj;
    } else {
        obj = MBModelParamCreate(D_80111F6C_2C082C_name_41);
    }
    MBModelDispOff(obj);
    D_80111F70_2C0830_name_41[arg0] = obj;
    obj->attr |= 2;
    scale = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (scale > 2.0f) {
        scale = 2.0f;
    }
    HuVecCopyXYZ(&obj->scale, scale, scale, scale);
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110C8C_2BF54C_name_41[arg0])->coords);
    from = GetSpaceData(D_80110C90_2BF550_name_41[arg0][0]);
    func_80056658_57258(&GetSpaceData(D_80110C90_2BF550_name_41[arg0][1])->coords, &from->coords, &obj->rot);
}

void func_80106904_2B51C4_name_41(void) {
    s32 i;

    D_80111F6C_2C082C_name_41 = NULL;
    for (i = 0; i < 2; i++) {
        D_80111F70_2C0830_name_41[i] = NULL;
        func_80106780_2B5040_name_41(i);
    }
}

void func_80106964_2B5224_name_41(void) {
    GW_PLAYER* player;

    player = BoardPlayerGet(-1);
    if (D_80110C98_2BF558_name_41 != 0) {
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->pos, &D_80111F78_2C0838_name_41->pos);
        ((MBModel*)player->unk_24)->jumpY = D_80111F78_2C0838_name_41->jumpY + 7.0f;
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->rot, &D_80111F78_2C0838_name_41->rot);
    }
}

s32 func_801069E8_2B52A8_name_41(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = 1;
                if (arg0 == 0) {
                    count = func_80044800_45400(D_80110D28_2BF5E8_name_41) + 1;
                }
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

/* A gate: open it with the key item (option 0) or turn back (1); option 2 runs func_80103A64 and asks again. */
void func_80106C40_2B5500_name_41(void) {
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
        func_80056C30_57830(-1, 8, 0x5D);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801069E8_2B52A8_name_41(0);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801065BC_2B4E7C_name_41(0);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2B2484_name_41();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80110D20_2BF5E0_name_41);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80110D14_2BF5D4_name_41;
                } else {
                    tree = D_80110CCC_2BF58C_name_41;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2B2554_name_41();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 12, 0);
            } else {
                SetNextChainAndSpace(-1, 2, 0);
                func_80106660_2B4F20_name_41(0);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 2, 0);
            break;
        case 2:
            func_80103A64_2B2324_name_41();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 2, 0);
    }
    omDelPrcObj(NULL);
}

/* A gate: open it with the key item (option 0) or turn back (1); option 2 runs func_80103A64 and asks again. */
void func_80106F38_2B57F8_name_41(void) {
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
        func_80056C30_57830(-1, 8, 0x5E);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801069E8_2B52A8_name_41(1);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801065BC_2B4E7C_name_41(1);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2B2484_name_41();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80110D50_2BF610_name_41);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80110D14_2BF5D4_name_41;
                } else {
                    tree = D_80110CFC_2BF5BC_name_41;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2B2554_name_41();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 8, 0);
            } else {
                SetNextChainAndSpace(-1, 4, 0);
                func_80106660_2B4F20_name_41(1);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 4, 0);
            break;
        case 2:
            func_80103A64_2B2324_name_41();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 4, 0);
    }
    omDelPrcObj(NULL);
}

void func_80107230_2B5AF0_name_41(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107254_2B5B14_name_41(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_80107278_2B5B38_name_41(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_8010729C_2B5B5C_name_41(void) {
    SetNextChainAndSpace(-1, 9, 0);
}

void func_801072C0_2B5B80_name_41(void) {
    SetNextChainAndSpace(-1, 9, 0);
}

void func_801072E4_2B5BA4_name_41(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_80107308_2B5BC8_name_41(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_8010732C_2B5BEC_name_41(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107350_2B5C10_name_41(void) {
    SetNextChainAndSpace(-1, 11, 13);
}

/* MP3 MB1Ev_KSuitEnd's shape: a puff grows over the marker model, the marker is rebuilt, the puff shrinks. */
void func_80107374_2B5C34_name_41(void) {
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
    func_80105F10_2B47D0_name_41();
    D_800F8D12_F9912 = 0;
    ChangeSpaceTextures(0);
    func_80105E28_2B46E8_name_41();
    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

__asm__(".section .rodata");
const char D_80111D88_2C0648_name_41[] = "%d";

/* A star space (func_80102C3C 1: buy a star for 20 coins) or the bank (2: passing pays out the
   bank, D_800F8D18; landing pays in up to 5 coins, or a lucky roll pays 5 out; with the star
   moved there, D_800F8D12, landing sells the star and moves it on).
   NON_MATCHING: GCC cross-jumps the two 20-coin payouts from MBDlgWinExec on where retail shares
   only the func_800614B4 call (6 instructions short), and the star-intro label lands before the
   D_800F8D12 load instead of after it (masked 61). */
#ifdef NON_MATCHING
void func_80107574_2B5E34_name_41(void) {
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
        if ((s16)func_80102C3C_2B14FC_name_41((s16)space) == 1) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, func_80102830_2B10F0_name_41());
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
                choice = func_801041D4_2B2A94_name_41();
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
                        func_80103968_2B2228_name_41(D_80111F0C_2C07CC_name_41);
                        func_800573AC_57FAC();
                        func_8006706C_67C6C(2);
                        return;
                    }
                    MBDlgWinExec(3, 0x22D);
                    func_80107374_2B5C34_name_41();
                    HuPrcSleep(30);
                    func_801039E4_2B22A4_name_41(D_800F64C8_F70C8);
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
                    func_80103A64_2B2324_name_41();
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
        } else if ((s16)func_80102C3C_2B14FC_name_41((s16)space) == 2) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, D_80110AA4_2BF364_name_41[gw->unk_1C]);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (D_800F8D12_F9912 == 0) {
                PlaySound(0x363);
            }
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22F);
                    func_80107374_2B5C34_name_41();
                    HuPrcSleep(30);
                    MBDlgWinExec(5, 0x230);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else if (D_800F8D18[0] == 0) {
                    MBDlgWinExec(5, 0x427);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else {
                    sprintf(buf, D_80111D88_2C0648_name_41, D_800F8D18[0]);
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
                    roll = func_80103B70_2B2430_name_41();
                    if (roll >= D_80110DF8_2BF6B8_name_41[func_80059FD0_5ABD0(gw->current_player_index)]) {
                        if (gPlayers[gw->current_player_index].coins >= 5) {
                            MBDlgWinExec(5, 0x423);
                            D_800F8D18[0] += 5;
                            func_8004CA34_4D634(gw->current_player_index, -5);
                            func_800614B4_620B4(gw->current_player_index, -5);
                        } else {
                            sprintf(buf, D_80111D88_2C0648_name_41, gPlayers[gw->current_player_index].coins);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80107574_2B5E34_name_41);
#endif

/* The coin-collecting space: landing pays the pot (D_800F8CE4[0x1D]) out, passing pays 5 coins in. */
void func_80107DB4_2B6674_name_41(void) {
    GW_SYSTEM* gw;
    s16 space;
    s16 coins;
    char buf[16];
    char buf2[16];

    space = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index != 4) {
        if (func_80047DE8_489E8(gw->current_player_index) <= 0) {
            MBPlayerVibrate(-1, 3);
        }
        MBPlayerMotionSet(-1, -1, 2);
        switch (space) {
        case 0x4D:
            func_80056C30_57830(-1, 8, 0x5F);
            break;
        case 0x25:
            func_80056C30_57830(-1, 8, 0x61);
            break;
        }
        HuPrcSleep(8);
        PlaySound(0xE6);
        if (func_80047DE8_489E8(gw->current_player_index) > 0) {
            func_80046D2C_4792C(gw->current_player_index);
            coins = gPlayers[gw->current_player_index].coins;
            if ((coins != 0) & (coins < 5)) {
                sprintf(buf, D_80111D88_2C0648_name_41, coins);
                sprintf(buf2, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[0x1D] + gPlayers[gw->current_player_index].coins);
                func_80056368_56F68(2, 0x17, (s32)buf, (s32)buf2, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += gPlayers[gw->current_player_index].coins;
                func_801060D4_2B4994_name_41();
                func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                HuPrcSleep(30);
                func_80056124_56D24();
            } else if (gPlayers[gw->current_player_index].coins == 0) {
                sprintf(buf, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[0x1D]);
                func_80056368_56F68(2, 0x18, (s32)buf, 0, 0, 0, 0);
            } else {
                sprintf(buf, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[0x1D] + 5);
                func_80056368_56F68(2, 0x16, (s32)buf, 0, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += 5;
                func_801060D4_2B4994_name_41();
                func_8004CA34_4D634(gw->current_player_index, -5);
                func_800614B4_620B4(gw->current_player_index, -5);
                HuPrcSleep(30);
                func_80056124_56D24();
            }
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
            func_8004655C_4715C(gw->current_player_index);
        } else if (D_800F8CE4_F98E4[0x1D] != 0) {
            sprintf(buf, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[0x1D]);
            func_80056368_56F68(2, 0x19, (s32)buf, 0, 0, 0, 0);
            MBDlgWinClose();
            func_8004CA34_4D634(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            func_800614B4_620B4(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            D_800F8CE4_F98E4[0x1D] = 0;
            func_801060D4_2B4994_name_41();
            func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
            MBPlayerMotionSet(-1, 5, 0);
            func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
            HuPrcSleep(30);
            func_80056124_56D24();
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(2, 0x1A);
        }
    }
}

s32 func_801081E0_2B6AA0_name_41(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_80111F80_2C0840_name_41[i] != 0) {
            if (D_80110E34_2BF6F4_name_41[D_80111F7C_2C083C_name_41][i] == arg0) {
                return i;
            }
        }
    }
    return -1;
}

s32 func_8010824C_2B6B0C_name_41(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_80110E34_2BF6F4_name_41[D_80111F7C_2C083C_name_41][i] == -1) {
            break;
        }
    }
    return i;
}

/* The item shop: items by turn band and rank, the choice window, buying and the item shown.
   NON_MATCHING: register allocation, count and shop swap s2/s3, and the order of the bought
   item's address sum (masked 4). */
#ifdef NON_MATCHING
void func_80108298_2B6B58_name_41(void) {
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
        func_80056C30_57830(-1, 8, 0x9A);
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
            choice = func_80103FB0_2B2870_name_41();
            MBDlgWinClose();
            func_80056168_56D68();
            switch (choice) {
            case 0:
            shop:
                for (band = 0; band < 2; band++) {
                    if (gw->current_turn >= D_80110E28_2BF6E8_name_41[gw->current_game_length][band] &&
                        gw->current_turn < D_80110E28_2BF6E8_name_41[gw->current_game_length][band + 1]) {
                        break;
                    }
                }
                count = 0;
                shop = D_80110E1C_2BF6DC_name_41[band][func_80059FD0_5ABD0(gw->current_player_index)];
                for (i = 0; i < 5; i++) {
                    enabled[i] = 1;
                    names[i][0] = 0;
                    if (D_80110E34_2BF6F4_name_41[shop][i] != -1) {
                        if (D_800CC000[D_80110E34_2BF6F4_name_41[shop][i]] > gPlayers[gw->current_player_index].coins) {
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
                func_80056368_56F68(1, D_80110E58_2BF718_name_41[shop], names[0], (s32)names[1], (s32)names[2],
                                    (s32)names[3], (s32)names[4]);
                func_80056524_57124(0);
                D_80111F7C_2C083C_name_41 = shop;
                D_80111F80_2C0840_name_41 = enabled;
                sel = func_80103CF4_2B25B4_name_41(enabled);
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
                item = &D_80110E34_2BF6F4_name_41[shop][sel];
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
                func_80103A64_2B2324_name_41();
                goto loop;
            }
        }
        func_8004655C_4715C(gw->current_player_index);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80108298_2B6B58_name_41);
#endif

/* MP3 func_8010C914_322484_ChillyWaters: fade a model in */
void func_801088A4_2B7164_name_41(MBModel* model) {
    s32 i;

    MBModelDispOn(model);
    for (i = 0; i < 256; i += 12, HuPrcVSleep()) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0xFF);
}

/* MP3 func_8010DD44_3A30C4_w06: fade a model out */
void func_80108944_2B7204_name_41(MBModel* model) {
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
s32 func_801089E4_2B72A4_name_41(s32 player) {
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
                SprPosSet(sprites[i], 0, D_80110E90_2BF750_name_41[i].x, D_80110E90_2BF750_name_41[i].y);
                func_80082488_83088(sprites[i], 0, 0);
            }
        }
        PlaySound(0x377);
        for (j = 0; j < 17; j++) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_80110EB0_2BF770_name_41[i].x + D_80110E90_2BF750_name_41[i].x,
                              j * D_80110EB0_2BF770_name_41[i].y + D_80110E90_2BF750_name_41[i].y);
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
                    y = D_80110EB0_2BF770_name_41[i].y * 16.0f + D_80110E90_2BF750_name_41[i].y;
                    SprPosSet(sprites[i], 0, D_80110EB0_2BF770_name_41[i].x * 16.0f + D_80110E90_2BF750_name_41[i].x,
                              y + 2.0f * __sinf(j * 90 * (M_PI / 180.0)));
                }
            }
            HuPrcVSleep();
        }
        for (j = 16; j >= 0; j--) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_80110EB0_2BF770_name_41[i].x + D_80110E90_2BF750_name_41[i].x,
                              j * D_80110EB0_2BF770_name_41[i].y + D_80110E90_2BF750_name_41[i].y);
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
        SprPosSet(sprite, 0, D_80110E90_2BF750_name_41[player].x, D_80110E90_2BF750_name_41[player].y);
        func_80082488_83088(sprite, 0, 0);
        PlaySound(0x377);
        for (k = 0; k < 17; k++) {
            SprPosSet(sprite, 0, k * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x,
                      k * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        func_80082488_83088(sprite, 0, 255);
        gPlayers[player].stars--;
        MBPlayerVibrate(player, 5);
        PlaySound(0xE4);
        for (k = 0; k < 30; k++) {
            y = D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y;
            SprPosSet(sprite, 0, D_80110EB0_2BF770_name_41[player].x * 16.0f + D_80110E90_2BF750_name_41[player].x,
                      y + 2.0f * __sinf(k * 90 * (M_PI / 180.0)));
            HuPrcVSleep();
        }
        for (k = 16; k >= 0; k--) {
            SprPosSet(sprite, 0, k * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x,
                      k * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        SprKill(sprite);
        SprAnimKill(anim2);
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801089E4_2B72A4_name_41);
#endif

void func_801092C0_2B7B80_name_41(void) {
    func_80055E60_56A60();
    omDelPrcObj(NULL);
}

// register allocation and spill choice (masked 24 under -DNON_MATCHING, beside the rodata literals)
#ifdef NON_MATCHING /* NON_MATCHING */
/* A star hangs above the player's status window for 150 frames while the player (or the CPU, by
   difficulty) presses A; then it returns to the window or leaves. Returns the price from the turn
   and press tables, or -1 when the player cannot pay it. */
s32 func_801092E4_2B7BA4_name_41(s32 player) {
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
    SprPosSet(star, 0, D_80110E90_2BF750_name_41[player].x, D_80110E90_2BF750_name_41[player].y);
    func_80082488_83088(star, 0, 0);
    portrait = SprCreate_s32(1, 5);
    shown = 0;
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[player].character]);
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
    SprPosSet(portrait, 0, D_80110E90_2BF750_name_41[player].x - D_80110EB0_2BF770_name_41[player].x * 16.0f - 8.0f,
              D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y);
    func_80082488_83088(portrait, 0, 0);
    for (i = 0; i < 17; i++) {
        SprPosSet(star, 0, i * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x,
                  i * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
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
            y = D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y;
            SprPosSet(star, 0, D_80110EB0_2BF770_name_41[player].x * 16.0f + D_80110E90_2BF750_name_41[player].x,
                      y + 2.0f * __sinf(i * 90 * (M_PI / 180.0)));
        } else if (state == 9) {
            x = D_80110EB0_2BF770_name_41[player].x * 16.0f + D_80110E90_2BF750_name_41[player].x;
            angle = frame * 90 * (M_PI / 180.0);
            SprPosSet(star, 0, x + 2.0f * __sinf(angle),
                      D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y);
            x = D_80110E90_2BF750_name_41[player].x - 8.0f;
            SprPosSet(portrait, 0, x + 2.0f * __sinf(angle),
                      D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y);
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
                SprPosSet(portrait, 0, D_80110E90_2BF750_name_41[player].x - 8.0f,
                          D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y);
            }
        }
        if ((state == 0) & (t = (shown == 1))) {
            func_800822A8_82EA8(portrait, 0, 0, 0);
            func_8008225C_82E5C(portrait, 0, 1);
            shown = 0;
            SprPosSet(portrait, 0, D_80110E90_2BF750_name_41[player].x - D_80110EB0_2BF770_name_41[player].x * 16.0f - 8.0f,
                      D_80110EB0_2BF770_name_41[player].y * 16.0f + D_80110E90_2BF750_name_41[player].y);
        }
        HuPrcVSleep();
        timer--;
    }
    func_8006735C_67F5C(vib);
    omAddPrcObj(func_801092C0_2B7B80_name_41, 0x1000, 0, 0);
    if (presses == 0) {
        for (i = 16; i >= 0; i -= 2) {
            SprPosSet(star, 0, i * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x,
                      i * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
            alpha = i * 16;
            func_80082488_83088(star, 0, alpha);
            func_80082488_83088(portrait, 0, alpha);
            HuPrcVSleep();
        }
    } else {
        for (i = 16; i >= -16; i -= 2) {
            SprPosSet(star, 0, i * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x,
                      i * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
            SprPosSet(portrait, 0,
                      (i - 16) * D_80110EB0_2BF770_name_41[player].x + D_80110E90_2BF750_name_41[player].x - 8.0f,
                      i * D_80110EB0_2BF770_name_41[player].y + D_80110E90_2BF750_name_41[player].y);
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
        if (GwSystem.current_turn >= D_80110EE8_2BF7A8_name_41[j].min && GwSystem.current_turn <= D_80110EE8_2BF7A8_name_41[j].max) {
            break;
        }
    }
    price = D_80110EE8_2BF7A8_name_41[j].value;
    for (j = 0; j < 14; j++) {
        if (presses >= D_80110EFC_2BF7BC_name_41[j].min && presses <= D_80110EFC_2BF7BC_name_41[j].max) {
            break;
        }
    }
    price -= D_80110EFC_2BF7BC_name_41[j].value;
    if (price >= gPlayers[player].coins) {
        price = -1;
    }
    return price;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801092E4_2B7BA4_name_41);
#endif

void func_8010A020_2B88E0_name_41(void) {
    MBModel* model;
    f32 angle;
    MBModel* parent;

    parent = HuPrcCurrentGet()->user_data;
    model = MBModelParamCreate(D_80111F84_2C0844_name_41);
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

void func_8010A174_2B8A34_name_41(MBModel* parent) {
    Process* process = omAddPrcObj(func_8010A020_2B88E0_name_41, 0x1000, 0, 0);

    process->user_data = parent;
}

// scheduling of three loop-invariant constants in the player menu (masked 2 under -DNON_MATCHING)
#ifdef NON_MATCHING /* NON_MATCHING */
/* Boo: for 5 coins steal coins (a minigame decides how many) or, for 50, a star from another
   player. Boo is the board Boo (space 0x7D; 3E has two) or, elsewhere, a temporary one. */
void func_8010A1B0_2B8A70_name_41(void) {
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
    case 0x7D:
        boo = 0;
        cam = 0x5C;
        break;
    default:
        boo = -1;
        cam = -1;
        model = MBModelParamCreate(D_80111F2C_2C07EC_name_41);
        MBModelDispOff(model);
        model->jumpY = 10.0f;
        spaceData = GetSpaceData(space);
        HuVecCopyXYZ(&model->pos, spaceData->coords.x, spaceData->coords.y + 10.0f, spaceData->coords.z);
        goto created;
    }
    model = D_80111F30_2C07F0_name_41[boo];
created:
    PlaySound(0xEB);
    func_801088A4_2B7164_name_41(model);
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
        func_80056368_56F68(7, 0x6B5, (s32)msgs[0], (s32)msgs[1], 0, 0, 0);
        choice = func_8010537C_2B3C3C_name_41(items);
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
            func_80056368_56F68(7, 0x6B8, (s32)msgs[0], (s32)msgs[1], (s32)msgs[2], 0, 0);
            sel = func_80105630_2B3EF0_name_41(choice, items);
            MBDlgWinClose();
            func_80056168_56D68();
            if (sel == -1) {
                goto menu;
            }
            if (sel == 3) {
                if (boo == -1) {
                    func_80103AF4_2B23B4_name_41();
                    D_800F851A_F911A = 1;
                    func_80078EC8_79AC8();
                } else {
                    func_80103A64_2B2324_name_41();
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
            func_80108944_2B7204_name_41(model);
            if (choice == 0) {
                amount = func_801092E4_2B7BA4_name_41(D_80110E84_2BF744_name_41[gw->current_player_index][sel]);
                func_801088A4_2B7164_name_41(model);
                if (amount == -1) {
                    amount = gPlayers[D_80110E84_2BF744_name_41[gw->current_player_index][sel]].coins;
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, 0x6BF, (s32)msgs[0], 0, 0, 0, 0);
                } else {
                    for (i = 0; i < sizeof(D_80110F28_2BF7E8_name_41) / sizeof(D_80110F28_2BF7E8_name_41[0]); i++) {
                        if (gw->current_turn >= D_80110F28_2BF7E8_name_41[i].turnMin
                            && gw->current_turn <= D_80110F28_2BF7E8_name_41[i].turnMax
                            && amount >= D_80110F28_2BF7E8_name_41[i].min && amount <= D_80110F28_2BF7E8_name_41[i].max) {
                            break;
                        }
                    }
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, D_80110F92_2BF852_name_41[D_80110F28_2BF7E8_name_41[i].mess], (s32)msgs[0], 0,
                                        0, 0, 0);
                }
                MBDlgWinClose();
                func_80056168_56D68();
                step = amount / 90.0f;
                acc = 0.0f;
                D_80111F84_2C0844_name_41 = func_80043510_44110(0x18, NULL);
                func_80043DAC_449AC(D_80111F84_2C0844_name_41);
                MBModelDispOff(D_80111F84_2C0844_name_41);
                vib = func_800672BC_67EBC(D_80110E84_2BF744_name_41[gw->current_player_index][sel], 3, 5);
                while (amount != 0) {
                    acc += step;
                    if (acc >= 1.0f) {
                        acc -= 1.0f;
                        func_8010A174_2B8A34_name_41(model);
                        func_800614B4_620B4(gw->current_player_index, 1);
                        func_8006135C_61F5C(D_80110E84_2BF744_name_41[gw->current_player_index][sel], -1, 0);
                        amount--;
                    }
                    HuPrcVSleep();
                }
                func_8006735C_67F5C(vib);
                HuPrcSleep(20);
                MBModelKill(D_80111F84_2C0844_name_41);
                func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
                MBPlayerMotionSet(-1, 5, 0);
                HuPrcSleep(5);
                func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
                HuPrcSleep(45);
            } else {
                func_801089E4_2B72A4_name_41(D_80110E84_2BF744_name_41[gw->current_player_index][sel]);
                func_801088A4_2B7164_name_41(model);
                D_80110AE0_2BF3A0_name_41 = 1;
                func_80103968_2B2228_name_41(model);
                D_80110AE0_2BF3A0_name_41 = 0;
            }
            if (boo == -1) {
                MBPlayerMotionSet(-1, -1, 2);
            }
            break;
        case 2:
            func_80108944_2B7204_name_41(model);
            MBDlgWinExec(7, 0x6B7);
            break;
        case 3:
            if (boo == -1) {
                func_80103AF4_2B23B4_name_41();
                D_800F851A_F911A = 1;
                func_80078EC8_79AC8();
            } else {
                func_80103A64_2B2324_name_41();
            }
            goto menu;
        }
    }
    if (choice != 2) {
        func_80108944_2B7204_name_41(model);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010A1B0_2B8A70_name_41);
#endif

void func_8010AB8C_2B944C_name_41(void) {
    func_80106660_2B4F20_name_41(0);
}

void func_8010ABA8_2B9468_name_41(void) {
    func_80106660_2B4F20_name_41(1);
}

omObjData* func_8010ABC4_2B9484_name_41(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel) {
    MBModel* model;
    Unk3EParticle* work;
    omObjData* obj;

    obj = omAddObj(0x1F4, 0, 0, -1, func_8010AD04_2B95C4_name_41);
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

void func_8010AD04_2B95C4_name_41(omObjData* obj) {
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


/* The lamp brings the player to the star (MP3 w06 func_8011068C). */
void func_8010AE1C_2B96DC_name_41(void) {
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
    func_8010BABC_2BA37C_name_41();
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
            func_8010ABC4_2B9484_name_41(&pos, 0.1f, 2.0f, 1, &particleDir[(i / 2) & 7]);
        }
        angle += 0x14;
        HuPrcVSleep();
        i++;
    }

    func_8006735C_67F5C(vib);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    func_80054C78_55878(D_80110A94_2BF354_name_41[system->star_spawn_indices[system->unk_0A]], &chain, &index);
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
            func_8010ABC4_2B9484_name_41(&pos, 0.1f, 2.0f, 1, &particleDir2[(i / 2) & 7]);
        }
        i++;
        HuPrcVSleep();
        angle += 0x14;
        if (angle == 0x500) {
            func_800115B4_121B4(0);
        }
    }
}

void func_8010B1B8_2B9A78_name_41(void) {
    GW_SYSTEM* gw = &GwSystem;

    D_800CCC16 = 1;
    func_800556F4_562F4(D_80110A94_2BF354_name_41[gw->star_spawn_indices[gw->unk_0A]], 1);
    D_800CCC16 = 0;
    if (func_800670B0_67CB0() >= 0) {
        HuPrcSleep(-1);
    }
}

void func_8010B228_2B9AE8_name_41(void) {
    s32 playerNo;
    GW_PLAYER* player;
    s16 space;

    playerNo = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    func_8010BABC_2BA37C_name_41();
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

/* Slides a sprite (when not -1) and the current player's status window by the same offset. */
void func_8010B414_2B9CD4_name_41(void) {
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

Process* func_8010B660_2B9F20_name_41(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames) {
    Process* process;
    Unk3EWindowSlide* work;

    process = omAddPrcObj(func_8010B414_2B9CD4_name_41, 0x4001, 0, 0x40);
    work = process->user_data = HuMemMemoryAlloc(process->heap, sizeof(Unk3EWindowSlide));
    work->x0 = x0;
    work->y0 = y0;
    work->x1 = x1;
    work->y1 = y1;
    work->frames = frames;
    work->sprite = sprite;
    return process;
}

/* The player's portrait fades in and slides off; the status window fades while the player
   celebrates. */
void func_8010B70C_2B9FCC_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_80111050_2BF910_name_41[gw->current_player_index].x, D_80111050_2BF910_name_41[gw->current_player_index].y);
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
                   func_8010B660_2B9F20_name_41(sprite, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 30));
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

/* The player's portrait fades in, slides to the status window and fades out with it. */
/* The player's portrait fades in, slides to the status window and fades out with it. */
void func_8010BABC_2BA37C_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 alpha;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_80111050_2BF910_name_41[gw->current_player_index].x,
              D_80111050_2BF910_name_41[gw->current_player_index].y);
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
    func_8010B660_2B9F20_name_41(sprite, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                 D_80111050_2BF910_name_41[gw->current_player_index].y,
                                 D_80111090_2BF950_name_41[gw->current_player_index].x,
                                 D_80111090_2BF950_name_41[gw->current_player_index].y, 30);
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

/* The player's portrait fades in, slides back and fades out. */
void func_8010BE08_2BA6C8_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_801110B0_2BF970_name_41[gw->current_player_index].x, D_801110B0_2BF970_name_41[gw->current_player_index].y);
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
                   func_8010B660_2B9F20_name_41(sprite, D_801110B0_2BF970_name_41[gw->current_player_index].x,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].y,
                                                D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
void func_8010C134_2BA9F4_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 j;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_80111050_2BF910_name_41[gw->current_player_index].x, D_80111050_2BF910_name_41[gw->current_player_index].y);
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
                   func_8010B660_2B9F20_name_41(sprite, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 30));
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

/* Plunder chest (item event 3): take a random other player's item.
   register allocation only (masked 0): target and its gPlayers offset swap s0/s1. */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010C598_2BAE58_name_41(void) {
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
    func_8010BABC_2BA37C_name_41();
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010B660_2B9F20_name_41(-1, D_80111090_2BF950_name_41[gw->current_player_index].x,
                                                D_80111090_2BF950_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 1));
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
                   func_8010B660_2B9F20_name_41(-1, D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].x,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].y, 5));
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
    func_80056368_56F68(-1, 0x1E2, (s32)str0, (s32)str1, 0, 0, 0);
    MBDlgWinClose();
    func_80056168_56D68();
    func_8010BE08_2BA6C8_name_41();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010C598_2BAE58_name_41);
#endif

/* 41-C: D_80111E18 (8010AE1C's end-of-table bound, the end of D_80111DB8) is the 0.5 literal
   func_8010CB10 emits: a label only, so the asm user still links. */
__asm__(".section .rodata\n\t.globl D_80111E18_2C06D8_name_41\nD_80111E18_2C06D8_name_41:\n\t.text");

/* Bowser suit start (item event 4); MP3 MB1Ev_KSuitStart. */
void func_8010CB10_2BB3D0_name_41(void) {
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

/* Bowser suit end (item event 5); MP3 MB1Ev_KSuitEnd. */
void func_8010CD80_2BB640_name_41(void) {
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

/* Board event 9: the current player gets item 3, shown in their status window. */
void func_8010CFB4_2BB874_name_41(void) {
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
                   func_8010B660_2B9F20_name_41(-1, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    PlaySound(0x19);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, i * 25);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0x100);
    MBPlayerMotionSet(-1, 3, 0);
    HuPrcSleep(30);
    MBDlgResultWinExec(D_801110D0_2BF990_name_41[gw->current_board_index]);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010B660_2B9F20_name_41(-1, D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y,
                                                D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y, 30));
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

/* Board event 10 (Bowser suit, from the item marker): a player holding item 3 loses it, the
   suit appears on the marker and the current player walks to the star space. */
void func_8010D2C8_2BBB88_name_41(void) {
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
                           func_8010B660_2B9F20_name_41(-1, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                        D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                        D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                        D_80111070_2BF930_name_41[gw->current_player_index].y, 30));
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
        func_80107374_2B5C34_name_41();
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
    func_80054C78_55878(D_80110A94_2BF354_name_41[gw->unk_1C], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    space = GetSpaceData(D_80110A94_2BF354_name_41[gw->unk_1C]);
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
    MBDlgWinExec(D_801110E8_2BF9A8_name_41[gw->current_board_index], D_801110D0_2BF990_name_41[gw->current_board_index] + 1);
    MBKSuitMotionSet(-1, 2);
    HuPrcVSleep();
    func_800495D8_4A1D8(gw->current_player_index, 3);
}

/* Board event 12: the Bowser suit wears off (the current player is shown again). */
void func_8010D93C_2BC1FC_name_41(void) {
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
    MBDlgResultWinExec(D_801110D0_2BF990_name_41[GwSystem.current_board_index] + 8);
    D_800F8D16_F9916 = 0;
}

/* Board event 11 (Bowser suit passing players): every player on the current player's space is
   stomped and loses all their coins; the richest one's coins go to the current player.
   Differs only in the message index: retail adds count + 1 to the table entry, GCC here adds 1
   to the entry first (masked 2). */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010DB70_2BC430_name_41(void) {
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
            func_80056368_56F68(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                                D_801110D0_2BF990_name_41[gw->current_board_index] + 6, (s32)names[0], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                         D_801110D0_2BF990_name_41[gw->current_board_index] + 7);
        }
    } else {
        names[0][0] = names[1][0] = names[2][0] = names[3][0] = 0;
        for (i = 0; i < count; i++) {
            names[i][0] = 0x18;
            names[i][1] = gPlayers[hit[i]].character;
            names[i][2] = 0;
        }
        func_80056368_56F68(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                            (count + 1) + D_801110D0_2BF990_name_41[gw->current_board_index], (s32)names[0],
                            (s32)names[1], (s32)names[2], (s32)names[3], 0);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010DB70_2BC430_name_41);
#endif

/* Board event 13: a random item (5 in 6), its picture faded in over the board. */
void func_8010E080_2BC940_name_41(void) {
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

/* CPU: how many coins to put in (board state counter D_800F8CE4[arg0]): a random 1-4 step by
   difficulty and how far the player's coins exceed the counter + 20 / + 40, capped at 999 and at
   the player's coins. */
s32 func_8010E290_2BCB50_name_41(s32 arg0) {
    GW_SYSTEM* gw = &GwSystem;
    s32 r;
    s32 n;

    r = MBRand(100.0f);
    if (D_800F8CE4_F98E4[arg0] + 40 < gPlayers[gw->current_player_index].coins) {
        if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
            if (r < 80) {
                n = 1;
            } else if (r < 95) {
                n = 2;
            } else {
                n = 3;
            }
        } else if (r < 60) {
            n = 1;
        } else if (r < 80) {
            n = 2;
        } else if (r < 90) {
            n = 3;
        } else {
            n = 4;
        }
    } else if (D_800F8CE4_F98E4[arg0] + 20 < gPlayers[gw->current_player_index].coins) {
        if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
            if (r < 80) {
                n = 1;
            } else if (r < 95) {
                n = 2;
            } else {
                n = 3;
            }
        } else if (r < 70) {
            n = 1;
        } else if (r < 90) {
            n = 2;
        } else {
            n = 3;
        }
    } else if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
        n = 1;
    } else if (r < 80) {
        n = 1;
    } else if (r < 95) {
        n = 2;
    } else {
        n = 3;
    }
    n += D_800F8CE4_F98E4[arg0];
    if (n >= 1000) {
        n = 999;
    }
    if (gPlayers[gw->current_player_index].coins < n) {
        n = gPlayers[gw->current_player_index].coins;
    }
    return n;
}

/* Whether space D_800F8CE4[arg0] + arg1 exists. */
s32 func_8010E474_2BCD34_name_41(s16 arg0, s16 arg1) {
    return BoardSpaceGet(-1, D_800F8CE4_F98E4[arg0] + arg1) != 0;
}

s32 func_8010E4B4_2BCD74_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0x18);
}

s32 func_8010E4D4_2BCD94_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0x14);
}

s32 func_8010E4F4_2BCDB4_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0xA);
}

s32 func_8010E514_2BCDD4_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x1E);
}

s32 func_8010E534_2BCDF4_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x18);
}

s32 func_8010E554_2BCE14_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x14);
}

/* CPU: the menu row for decision tree D_80111190 (arg0 == 1) or D_80111268. */
s32 func_8010E574_2BCE34_name_41(s32 arg0) {
    s16 choice;

    if (arg0 == 1) {
        choice = func_80044800_45400(D_80111190_2BFA50_name_41);
    } else {
        choice = func_80044800_45400(D_80111268_2BFB28_name_41);
    }
    return choice + 1;
}

/* 3E's func_80103FB0 with the CPU's choice from func_8010E574(arg0). */
s32 func_8010E5B8_2BCE78_name_41(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_8010E574_2BCE34_name_41(arg0);
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

/* Model D_80111F70[arg0] pops in: a wobble (decaying sine) around a size that grows with
   D_800F8CE4[arg0 + 1] (1 + n / 50, at most 2). */
void func_8010E7E8_2BD0A8_name_41(s32 arg0) {
    MBModel* model = D_80111F70_2C0830_name_41[arg0];
    f32 size;
    f32 amp;
    s32 angle;

    PlaySound(0x36D);
    size = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (size > 2.0f) {
        size = 2.0f;
    }
    MBModelDispOn(model);
    HuVecCopyXYZ(&model->scale, 0.0f, 0.0f, 0.0f);
    for (angle = 0, amp = 1.0f; angle < 1081; angle += 45, amp -= 1.0f / 24) {
        HuVecCopyXYZ(&model->scale, (HuMathSin(angle) * amp + 1.0f) * size,
                     (HuMathSin(angle) * amp + 1.0f) * size, (HuMathSin(angle) * amp + 1.0f) * size);
        HuPrcVSleep();
    }
}

/* Model D_80111F70[arg0] shrinks away (a quarter sine, growing amplitude), then hides. */
void func_8010E960_2BD220_name_41(s32 arg0) {
    MBModel* model = D_80111F70_2C0830_name_41[arg0];
    f32 size;
    f32 amp;
    s32 angle;

    PlaySound(0x36E);
    size = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (size > 2.0f) {
        size = 2.0f;
    }
    MBModelDispOn(model);
    HuVecCopyXYZ(&model->scale, 0.0f, 0.0f, 0.0f);
    for (angle = 180, amp = 0.0f; angle < 271; angle += 5, amp += 1.0f / 18) {
        HuVecCopyXYZ(&model->scale, (HuMathSin(angle) * amp + 1.0f) * size,
                     (HuMathSin(angle) * amp + 1.0f) * size, (HuMathSin(angle) * amp + 1.0f) * size);
        HuPrcVSleep();
    }
    MBModelDispOff(model);
}

__asm__(".section .rodata");
const char D_80111E58_2C0718_name_41[] = "%-3d";

/* The toll event (MP1 Yoshi's Tropical Island Thwomp toll, func_800F6A98): on space 0x78 or 0x7A
   the toll's model (D_80111F70[0/1]) pops up; pay more than the last toll D_800F8CE4[1/2] (up to
   999) to take the toll path (chain 10 / 6), else go round (chain 3 / 5). Choice 2 reads the map
   (func_80103A64). The toll model grows with the toll. Current player 4 (none): just routes. */
void func_8010EADC_2BD39C_name_41(void) {
    char buf[16];
    s32 which;
    s32 cpuAmount;
    GW_SYSTEM* gw;
    s32 motion;
    s32 idx;
    s32 space;
    s32 choice;
    s32 frames;
    s32 amount;
    s32 prev;
    s32 cpuWait;
    f32 size;

    which = 0;
    idx = 0;
    space = func_800558F4_564F4();
    gw = &GwSystem;
    cpuAmount = 0;
    motion = 0;
    if (gw->current_player_index == 4) {
        switch ((s16)space) {
        case 0x78:
            SetNextChainAndSpace(-1, 3, 0);
            break;
        case 0x7A:
            SetNextChainAndSpace(-1, 5, 0);
            break;
        }
    } else {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        switch ((s16)space) {
        case 0x78:
            motion = 0x6F;
            idx = 1;
            which = 0;
            break;
        case 0x7A:
            motion = 0x70;
            idx = 2;
            which = 1;
            break;
        }
        func_8010E7E8_2BD0A8_name_41(which);
        func_80056C30_57830(-1, 8, motion);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        PlaySound(0xE5);
        if (D_800F8CE4_F98E4[idx] >= 999) {
            MBDlgWinExec(0x18, 0x9C);
            if (idx == 1) {
                SetNextChainAndSpace(-1, 3, 0);
            } else {
                SetNextChainAndSpace(-1, 5, 0);
            }
        } else if (D_800F8CE4_F98E4[idx] >= gPlayers[gw->current_player_index].coins) {
            sprintf(buf, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[idx] + 1);
            func_80056368_56F68(0x18, 0x9B, (s32)buf, 0, 0, 0, 0);
            MBDlgWinClose();
            func_80056168_56D68();
            if (idx == 1) {
                SetNextChainAndSpace(-1, 3, 0);
            } else {
                SetNextChainAndSpace(-1, 5, 0);
            }
        } else {
        retry:
            sprintf(buf, D_80111D88_2C0648_name_41, D_800F8CE4_F98E4[idx] + 1);
            func_80056368_56F68(0x18, 0x9A, (s32)buf, 0, 0, 0, 0);
            choice = func_8010E5B8_2BCE78_name_41(idx);
            MBDlgWinClose();
            func_80056168_56D68();
            switch (choice) {
            case 0:
                frames = 0;
                D_800FC734_FD334 = 0;
                choice = -1;
                prev = -1;
                amount = D_800F8CE4_F98E4[idx] + 1;
                if (gPlayers[gw->current_player_index].flags & 1) {
                    cpuAmount = func_8010E290_2BCB50_name_41(idx);
                }
                cpuWait = 0;
                sprintf(buf, D_80111E58_2C0718_name_41, amount);
                func_80056368_56F68(0x18, 0x9E, (s32)buf, 0, 0, 0, 0);
                while (1) {
                    if (prev != amount) {
                        sprintf(buf, D_80111E58_2C0718_name_41, amount);
                        func_8008D974_8E574(buf, 0);
                        prev = amount;
                        func_8008AD44_8B944(mbDlgWinId);
                        func_800890CC_89CCC(mbDlgWinId, 0x9E, -1, -1);
                    }
                    if (gPlayers[gw->current_player_index].flags & 1) {
                        if (cpuWait == 0) {
                            HuPrcSleep(((s32(*)(void))func_80057718_58318)()); /* retail: int return here */
                        }
                        cpuWait++;
                        if (frames == 16) {
                            if (cpuAmount == amount) {
                                choice = 1;
                                PlaySound(3);
                                frames = 0;
                            } else {
                                amount++;
                                frames = 0;
                            }
                        }
                    } else {
                        if (ContBtnTrg[gPlayers[gw->current_player_index].port] & 0x8000) {
                            choice = 1;
                            PlaySound(3);
                        } else if (ContBtnTrg[gPlayers[gw->current_player_index].port] & 0x4000) {
                            choice = 0;
                            PlaySound(4);
                        } else if (D_800FC9E0_FD5E0[gPlayers[gw->current_player_index].port] & 0x800) {
                            if (gPlayers[gw->current_player_index].coins >= amount + 1) {
                                amount++;
                            }
                        } else if (D_800FC9E0_FD5E0[gPlayers[gw->current_player_index].port] & 0x100) {
                            if (gPlayers[gw->current_player_index].coins >= amount + 10) {
                                amount += 10;
                            } else {
                                amount = gPlayers[gw->current_player_index].coins;
                            }
                        } else if (D_800FC9E0_FD5E0[gPlayers[gw->current_player_index].port] & 0x400) {
                            if (D_800F8CE4_F98E4[idx] + 1 <= amount - 1) {
                                amount--;
                            }
                        } else if (D_800FC9E0_FD5E0[gPlayers[gw->current_player_index].port] & 0x200) {
                            if (amount - 10 >= D_800F8CE4_F98E4[idx] + 1) {
                                amount -= 10;
                            } else {
                                amount = D_800F8CE4_F98E4[idx] + 1;
                            }
                        }
                        if (amount >= 1000) {
                            amount = 999;
                        }
                    }
                    if (choice != -1) {
                        break;
                    }
                    if (prev != amount) {
                        PlaySound(1);
                    }
                    frames++;
                    HuPrcVSleep();
                }
                MBDlgWinClose();
                func_80056168_56D68();
                D_800FC734_FD334 = 1;
                if (choice == 0) {
                    goto retry;
                }
                func_8004CA34_4D634(gw->current_player_index, -amount);
                func_800614B4_620B4(gw->current_player_index, -amount);
                HuPrcSleep(30);
                D_800F8CE4_F98E4[idx] = amount;
                size = (D_800F8CE4_F98E4[idx] + 50.0f) / 50.0f;
                if (size > 2.0f) {
                    size = 2.0f;
                }
                HuVecCopyXYZ(&D_80111F70_2C0830_name_41[which]->scale, size, size, size);
                MBDlgWinExec(0x18, 0x9F);
                func_8010E960_2BD220_name_41(which);
                if (idx == 1) {
                    SetNextChainAndSpace(-1, 10, 0);
                } else {
                    SetNextChainAndSpace(-1, 6, 0);
                }
                break;
            case 1:
                MBDlgWinExec(0x18, 0x9D);
                if (idx == 1) {
                    SetNextChainAndSpace(-1, 3, 0);
                } else {
                    SetNextChainAndSpace(-1, 5, 0);
                }
                break;
            case 2:
                func_80103A64_2B2324_name_41();
                goto retry;
            }
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    }
    omDelPrcObj(NULL);
}

void func_8010F318_2BDBD8_name_41(void) {
    func_8010E960_2BD220_name_41(0);
    omDelPrcObj(NULL);
}

void func_8010F33C_2BDBFC_name_41(void) {
    if (GwSystem.current_player_index != 4) {
        omAddPrcObj(func_8010F318_2BDBD8_name_41, 0x1005, 0, 0);
    }
}

void func_8010F378_2BDC38_name_41(void) {
    func_8010E960_2BD220_name_41(1);
    omDelPrcObj(NULL);
}

void func_8010F39C_2BDC5C_name_41(void) {
    if (GwSystem.current_player_index != 4) {
        omAddPrcObj(func_8010F378_2BDC38_name_41, 0x1005, 0, 0);
    }
}

/* Object func: bobs model D_80111F78 (jumpY = sin of a phase in rot.y, 2 degrees a frame). */
void func_8010F3D8_2BDC98_name_41(omObjData* obj) {
    D_80111F78_2C0838_name_41->jumpY = HuMathSin(obj->rot.y);
    obj->rot.y += 2.0f;
    if (obj->rot.y >= 360.0f) {
        obj->rot.y -= 360.0f;
    }
}

#ifdef NON_MATCHING
/* NON_MATCHING: masked 14, all the frame: retail's is 8 bytes larger (an extra spill slot after obj's)
   and computes idx * 4 after the table address; logic checked against the asm.
   The boat ride (event on spaces 3, 20 and 29): the player walks to the pier, the boat
   (D_80111F78, model 0x7E) and its wake (model 0x7D) surface and bob (func_8010F3D8); the fare is
   5 coins (or all the player has); the player jumps aboard, the boat sails to the far pier
   (D_801112E0[i][1]), the player jumps off to D_801112D6's space and lands on space
   D_801112EC[i], where the turn continues; the boat sinks again. */
void func_8010F448_2BDD08_name_41(void) {
    char buf[16];
    Vec rot;
    Vec rot2;
    omObjData* obj;
    GW_SYSTEM* gw;
    s32 i;
    s32 idx;
    s32 space;
    GW_PLAYER* player;
    SpaceData* start;
    SpaceData* pier;
    SpaceData* dest;
    SpaceData* land;
    MBModel* wake;
    void* cam;
    s16* pair;

    idx = 0;
    space = func_800558F4_564F4();
    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    switch ((s16)space) {
    case 3:
        idx = 0;
        break;
    case 20:
        idx = 1;
        break;
    case 29:
        idx = 2;
        break;
    }
    MBPlayerMotionSet(-1, -1, 2);
    pair = D_801112D4_2BFB94_name_41[idx];
    func_80056C30_57830(-1, 8, pair[0]);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
    HuPrcChildWatch();
    start = GetSpaceData(pair[0]);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &start->coords, &((MBModel*)player->unk_24)->pos, 10);
    MBPlayerMotionSet(-1, 0, 2);
    HuPrcSleep(10);
    MBPlayerMotionSet(-1, -1, 2);
    D_80111F78_2C0838_name_41 = func_80043510_44110(0x7E, NULL);
    wake = func_80043510_44110(0x7D, NULL);
    pier = GetSpaceData(D_801112E0_2BFBA0_name_41[idx][0]);
    dest = GetSpaceData(D_801112E0_2BFBA0_name_41[idx][1]);
    func_800B3170_B3D70(&D_80111F78_2C0838_name_41->pos, &pier->coords);
    func_800B3170_B3D70(&wake->pos, &pier->coords);
    func_80056658_57258(&pier->coords, &start->coords, &D_80111F78_2C0838_name_41->rot);
    D_80111F78_2C0838_name_41->jumpY = -25.0f;
    func_800298A4_2A4A4(*wake->obj->model, 0x80000, 0x80000);
    func_80029A8C_2A68C(*wake->obj->model);
    PlaySound(0x3AD);
    while (D_80111F78_2C0838_name_41->jumpY < 0.0f) {
        D_80111F78_2C0838_name_41->jumpY += 1.0f;
        HuPrcVSleep();
    }
    obj = omAddObj(0x6000, 0, 0, -1, func_8010F3D8_2BDC98_name_41);
    obj->rot.y = 0.0f;
    func_80056658_57258(&start->coords, &pier->coords, &rot);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 1);
    HuPrcSleep(1);
    if (gPlayers[gw->current_player_index].coins >= 5) {
        MBDlgWinExec(0x17, 0xFA);
        func_8004CA34_4D634(gw->current_player_index, -5);
        func_800614B4_620B4(gw->current_player_index, -5);
        HuPrcSleep(30);
    } else if (gPlayers[gw->current_player_index].coins != 0) {
        sprintf(buf, D_80111D88_2C0648_name_41, gPlayers[gw->current_player_index].coins);
        func_80056368_56F68(0x17, 0xFB, (s32)buf, 0, 0, 0, 0);
        func_80056458_57058();
        func_80056458_57058();
        MBDlgWinClose();
        func_80056168_56D68();
        func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
        func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
        HuPrcSleep(30);
    } else {
        MBDlgWinExec(0x17, 0xFC);
    }
    func_80056658_57258(&pier->coords, &dest->coords, &rot);
    func_80056B78_57778(&D_80111F78_2C0838_name_41->rot, &rot, &D_80111F78_2C0838_name_41->rot, 30);
    HuPrcSleep(30);
    MBPlayerMotionSet(-1, 2, 0);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pier->coords, &((MBModel*)player->unk_24)->pos, 20);
    ((MBModel*)player->unk_24)->jumpVel = 5.5f;
    ((MBModel*)player->unk_24)->jumpAccel = -0.5f;
    func_800797DC_7A3DC(0x42, gw->current_player_index);
    HuPrcSleep(18);
    ((MBModel*)player->unk_24)->jumpVel = 0.0f;
    ((MBModel*)player->unk_24)->jumpAccel = 0.0f;
    MBPlayerMotionSet(-1, -1, 2);
    ((MBModel*)player->unk_24)->attr |= 1;
    D_80110C98_2BF558_name_41 = 1;
    HuPrcSleep(10);
    cam = func_800672BC_67EBC(-1, 1, 5);
    func_80056D80_57980(&D_80111F78_2C0838_name_41->pos, &dest->coords, &D_80111F78_2C0838_name_41->pos, 60);
    func_80056D80_57980(&wake->pos, &dest->coords, &wake->pos, 60);
    HuPrcSleep(60);
    func_8006735C_67F5C(cam);
    func_80056658_57258(&pier->coords, &start->coords, &rot);
    start = GetSpaceData(D_801112D4_2BFB94_name_41[idx][1]);
    D_80110C98_2BF558_name_41 = 0;
    ((MBModel*)player->unk_24)->attr &= ~1;
    MBPlayerMotionSet(-1, 2, 0);
    func_80056658_57258(&dest->coords, &start->coords, &rot2);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot2, &((MBModel*)player->unk_24)->rot, 10);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &start->coords, &((MBModel*)player->unk_24)->pos, 20);
    ((MBModel*)player->unk_24)->jumpVel = 5.5f;
    ((MBModel*)player->unk_24)->jumpAccel = -0.55f;
    func_800797DC_7A3DC(0x42, gw->current_player_index);
    HuPrcSleep(10);
    PlaySound(0x3AD);
    for (i = 0; i < 10; i++) {
        D_80111F78_2C0838_name_41->pos.y -= 1.0f;
        HuPrcVSleep();
    }
    MBPlayerMotionSet(-1, 0, 2);
    func_80054C78_55878(D_801112EC_2BFBAC_name_41[idx], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    for (i = 0; i < 4; i++) {
        if (i != gw->current_player_index) {
            func_80063C40_64840(i, 10);
        }
    }
    land = GetSpaceData(D_801112EC_2BFBAC_name_41[idx]);
    func_80056658_57258(&start->coords, &land->coords, &rot2);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot2, &((MBModel*)player->unk_24)->rot, 1);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &land->coords, &((MBModel*)player->unk_24)->pos, 10);
    for (i = 0; i < 10; i++) {
        D_80111F78_2C0838_name_41->pos.y -= 1.0f;
        HuPrcVSleep();
    }
    MBPlayerMotionSet(-1, -1, 2);
    omDelObj(obj);
    MBModelKill(D_80111F78_2C0838_name_41);
    MBModelKill(wake);
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010F448_2BDD08_name_41);
#endif

/* a run-over player: hidden when the counter runs out */
void func_8010FC00_2BE4C0_name_41(omObjData* obj) {
    GW_PLAYER* player = BoardPlayerGet(obj->work[0]);

    if (obj->work[1] == 0) {
        MBModelDispOff(player->unk_24);
        omDelObj(obj);
    }
    obj->work[1]--;
}

/* Knocks player `player` back (3E's func_80106DCC without the cart): sound, rumble, a 30-frame
   object (func_8010FC00), a jump toward pos + 100 * (1, 2, 0), back to the chain start. */
void func_8010FC54_2BE514_name_41(s32 player) {
    Vec dir;
    Vec rot;
    GW_PLAYER* p;
    omObjData* obj;

    p = BoardPlayerGet(player);
    func_800797DC_7A3DC(0x111, player);
    PlaySound(0x3AB);
    MBPlayerVibrate(player, 3);
    obj = omAddObj(0x1000, 0, 0, -1, func_8010FC00_2BE4C0_name_41);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = player;
    obj->work[1] = 30;
    dir.x = 1.0f;
    dir.y = 2.0f;
    dir.z = 0.0f;
    HuVecMulScalar(&dir, 100.0f, &dir);
    HuVecAdd(&dir, &((MBModel*)p->unk_24)->pos, &dir);
    func_80056658_57258(&((MBModel*)p->unk_24)->pos, &dir, &rot);
    func_80056D80_57980(&((MBModel*)p->unk_24)->pos, &dir, &((MBModel*)p->unk_24)->pos, 30);
    p->cur_chain_index = 0;
    p->cur_space_index = 0;
    p->next_chain_index = 0;
    p->next_space_index = 1;
    ((MBModel*)p->unk_24)->attr |= 1;
    MBMotionSet(p->unk_24, 4, 2);
}

/* The cannon (arg0: which, D_8011133C[arg0] lists its target spaces, ending -1): the camera
   centres on the targets (their mean + D_80111368[arg0]); for each target space with players on
   it a cannonball (model 0x7F) flies from space D_80111344[arg0], explodes (func_8010ABC4) and
   knocks them back (func_8010FC54). After a fade the hit players are back at the start space
   (chain 0, space 0), offset by D_80111348[player]. */
void func_8010FD98_2BE658_name_41(s32 arg0) {
    Vec pos[4];
    Vec save;
    s16* targets = D_8011133C_2BFBFC_name_41[arg0];
    GW_PLAYER* player = BoardPlayerGet(-1);
    Vec vel[4] = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f } };
    SpaceData* space;
    MBModel* ball;
    s32 i;
    s32 j;
    s32 hit;
    s32 allHit;
    s32 fx;
    SpaceData* cannon;

    i = 0;
    func_80061518_62118();
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.0f));
    HuPrcChildWatch();
    HuVecCopyXYZ(&pos[0], 0.0f, 0.0f, 0.0f);
    while (targets[i] != -1) {
        space = GetSpaceData(targets[i++]);
        pos[0].x += space->coords.x;
        pos[0].y += space->coords.y;
        pos[0].z += space->coords.z;
    }
    pos[0].x /= i;
    pos[0].y /= i;
    pos[0].z /= i;
    pos[0].x += D_80111368_2BFC28_name_41[arg0][0];
    pos[0].z += D_80111368_2BFC28_name_41[arg0][1];
    func_800B3170_B3D70(&save, &((MBModel*)player->unk_24)->pos);
    func_800636F8_642F8(4);
    func_80063734_64334(&pos[0]);
    MBCameraSpeedSet(3.0f);
    HuPrcSleep(5);
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    allHit = 0;
    MBCameraSpeedSet(-1.0f);
    i = 0;
    cannon = GetSpaceData(D_80111344_2BFC04_name_41[arg0]);
    func_800599F0_5A5F0();
    fx = func_80059A68_5A668(0xA015F, 4);
    if (targets[0] != -1) {
        do {
            hit = 0;
            for (j = 0; j < 4; j++) {
                player = BoardPlayerGet(j);
                if (GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index) == targets[i]) {
                    allHit |= 1 << j;
                    hit |= 1 << j;
                }
            }
            if (hit != 0) {
                PlaySound(0x3AA);
                func_8010ABC4_2B9484_name_41(&cannon->coords, 0.1f, 4.0f, 1, vel);
                ball = func_80043510_44110(0x7F, NULL);
                func_800B3170_B3D70(&ball->pos, &cannon->coords);
                func_80056D80_57980(&ball->pos, &GetSpaceData(targets[i])->coords, &ball->pos, 30);
                ball->jumpVel = 9.0f;
                ball->jumpAccel = -0.6f;
                HuPrcSleep(27);
                MBModelDispOff(ball);
                for (j = 0; j < 4; j++) {
                    if (hit & (1 << j)) {
                        player = BoardPlayerGet(j);
                        func_8010FC54_2BE514_name_41(j);
                        func_80059B08_5A708(fx, ((MBModel*)player->unk_24)->pos.x, ((MBModel*)player->unk_24)->pos.y,
                                            ((MBModel*)player->unk_24)->pos.z, 4);
                    }
                }
                HuPrcSleep(3);
                MBModelKill(ball);
            }
            i++;
        } while (targets[i] != -1);
    }
    HuPrcSleep(30);
    func_80059BCC_5A7CC(fx);
    func_80023124_23D24();
    InitFadeOut(4, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_800636F8_642F8(2);
    space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(0, 0));
    func_80063710_64310(&space->coords);
    HuPrcSleep(5);
    func_80061584_62184();
    InitFadeIn(4, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        if (allHit & (1 << i)) {
            MBPlayerForwardSet(i);
            player = BoardPlayerGet(i);
            MBModelDispOn(player->unk_24);
            ((MBModel*)player->unk_24)->attr &= ~1;
            HuVecCopyXYZ(&((MBModel*)player->unk_24)->pos, space->coords.x + D_80111348_2BFC08_name_41[i][0], 120.0f,
                         space->coords.z + D_80111348_2BFC08_name_41[i][1]);
            HuVecCopyXYZ(&pos[i], ((MBModel*)player->unk_24)->pos.x, 0.0f, ((MBModel*)player->unk_24)->pos.z);
            func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->pos, 10);
        }
    }
    for (i = 0; i < 4; i++) {
        if (allHit & (1 << i)) {
            func_800797DC_7A3DC(0xFC, i);
        }
    }
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        if (allHit & (1 << i)) {
            func_80079798_7A398(0xA6, i);
        }
    }
    HuPrcSleep(50);
    omDelPrcObj(NULL);
}

void func_801103B4_2BEC74_name_41(void) {
    func_8010FD98_2BE658_name_41(0);
}

void func_801103D0_2BEC90_name_41(void) {
    func_8010FD98_2BE658_name_41(1);
}

/* Scene setup; MP3 func_8011A848_3AFBC8_w06. */
void func_801103EC_2BECAC_name_41(void) {
    func_80020070_20C70(2);
    CameraScissorSet(1, D_80111468_2BFD28_name_41);
    func_80105980_2B4240_name_41();
    func_80066C34_67834(2);
    omAddPrcObj(func_80102FFC_2B18BC_name_41, 0x1005, 0x1000, 0);
}

/* CPU item check (registered with func_80044D98): 1 = use the held item now. Several items are
   used on the last turn, or when their decision tree D_80111868/801118C8/80111A48/80111B80
   says so, or with enough coins. */
s32 func_80110440_2BED00_name_41(void) {
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
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80111868_2C0128_name_41) != 0) {
                return 0;
            }
            break;
        case 8:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_801118C8_2C0188_name_41) != 0) {
                return 0;
            }
            break;
        case 5:
            if (func_80044800_45400(D_80111A48_2C0308_name_41) != 0) {
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
            if (func_80044800_45400(D_80111B80_2C0440_name_41) != 0) {
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

/* CPU shop choice: the menu row (slot + 1) of an item to buy. Per character, D_80111CD4 lists
   items to try with D_80111D34 percent chances (needing price + 20 coins); then items 9 and 7,
   decision trees D_80111BE0 (item 1) and D_80111BF8 (a second pass at plain price), else on
   board 4 func_8010824C's row, else item 0's row or 1. */
s32 func_80110664_2BEF24_name_41(void) {
    GW_PLAYER* player;
    s32 slot;
    s32 i;
    s32 r;
    u8 item;
    GW_SYSTEM* gw = &GwSystem;

    player = BoardPlayerGet(-1);
    slot = -1;
    for (i = 0; i < D_80111D4C_2C060C_name_41[player->character]; i++) {
        item = D_80111CD4_2C0594_name_41[player->character][i];
        slot = func_801081E0_2B6AA0_name_41(item);
        if (slot == -1) {
            continue;
        }
        if (D_800CC000[item] + 20 > gPlayers[gw->current_player_index].coins) {
            continue;
        }
        if (RNGPercentChance(D_80111D34_2C05F4_name_41[player->character][i])) {
            break;
        }
    }
    if (i == D_80111D4C_2C060C_name_41[player->character]) {
        slot = -1;
    }
    if (slot != -1) {
        if (func_801081E0_2B6AA0_name_41(9) == slot) {
            return slot + 1;
        }
        if (func_801081E0_2B6AA0_name_41(7) == slot && D_800CC000[7] + 50 <= gPlayers[gw->current_player_index].coins) {
            return slot + 1;
        }
    }
    if (func_80044800_45400(D_80111BE0_2C04A0_name_41) == 0 && gPlayers[gw->current_player_index].coins >= D_800CC000[1]) {
        r = func_801081E0_2B6AA0_name_41(1);
        if (r != -1) {
            return r + 1;
        }
    }
    if (slot != -1) {
        return slot + 1;
    }
    i = func_80044800_45400(D_80111BF8_2C04B8_name_41);
    if (i == 0) {
        for (; i < D_80111D4C_2C060C_name_41[player->character]; i++) {
            item = D_80111CD4_2C0594_name_41[player->character][i];
            slot = func_801081E0_2B6AA0_name_41(item);
            if (slot == -1) {
                continue;
            }
            if (D_800CC000[item] > gPlayers[gw->current_player_index].coins) {
                continue;
            }
            if (RNGPercentChance(D_80111D34_2C05F4_name_41[player->character][i])) {
                return slot + 1;
            }
        }
    }
    if (gw->current_board_index == 4) {
        D_80111C88_2C0548_name_41 = 1;
        return func_8010824C_2B6B0C_name_41() + 2;
    }
    slot = func_801081E0_2B6AA0_name_41(0);
    if (slot != -1) {
        return slot + 1;
    }
    return 1;
}

/* The CPU's yes/no answer (1 or 2); MP3 func_8011D1F8_332D68_ChillyWaters. */
s32 func_801109E0_2BF2A0_name_41(void) {
    if (D_80111C88_2C0548_name_41 != 0) {
        D_80111C88_2C0548_name_41 = 0;
        return 2;
    }
    return func_80044800_45400(D_80111C64_2C0524_name_41) + 1;
}
