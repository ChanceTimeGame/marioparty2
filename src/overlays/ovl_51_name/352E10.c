#include "ovl_51.h"

/* Scene setup: each player's coins and stars (with the bonus stars) totalled, the board's flag set. */
void func_80102800_352E10_name_51(void) {
    s32 i;

    omInitObjMan(0x64, 0x50);
    if (GwSystem.current_board_index < 6) {
        _SetFlag(D_8010846C_358A7C_name_51[GwSystem.current_board_index]);
    }
    D_80108880_358E90_name_51 = 0;
    for (i = 0; i < 4; i++) {
        D_80108870_358E80_name_51[D_800F8CE4_F98E4[i]] = gPlayers[D_800F8CE4_F98E4[i]].coins;
        D_80108880_358E90_name_51 += D_80108870_358E80_name_51[D_800F8CE4_F98E4[i]];
    }
    D_80108888_358E98_name_51 = 0;
    for (i = 0; i < 4; i++) {
        D_80108888_358E98_name_51 += gPlayers[D_800F8CE4_F98E4[i]].stars + D_800F8CE4_F98E4[D_800F8CE4_F98E4[i] + 10];
    }
    D_8010888C_358E9C_name_51 = 0;
    func_80107FE8_3585F8_name_51();
    func_80088640_89240();
    func_8005E570_5F170();
    MBModelInit();
    func_8005965C_5A25C();
    omAddPrcObj(func_80107090_3576A0_name_51, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_801077A8_357DB8_name_51);
}

/* The cursor's pulse and the scroll arrows' swing (MP1 func_800F678C). */
void func_801029A8_352FB8_name_51(omObjData* obj) {
    if ((obj->trans.x += 10.0f) >= 360.0f) {
        obj->trans.x -= 360.0f;
    }
    func_80082450_83050((s16)D_80108A88_359098_name_51, 0, 0x40, 0x40, HuMathSin(obj->trans.x) * 32.0f + 223.0f);
    if ((obj->trans.y += 20.0f) >= 360.0f) {
        obj->trans.y -= 360.0f;
    }
    D_80108484_358A94_name_51[0] += HuMathSin(obj->trans.y) * 0.75f;
    SprPosSet((s16)D_80108A98_3590A8_name_51, 1, D_801084EC_358AFC_name_51[0][0] + D_80108484_358A94_name_51[0],
              D_801084EC_358AFC_name_51[0][1]);
    SprPosSet((s16)D_80108A98_3590A8_name_51, 2, D_801084EC_358AFC_name_51[1][0] - D_80108484_358A94_name_51[0],
              D_801084EC_358AFC_name_51[1][1]);
}

/* Redraws the table after a scroll (MP1 func_800F6988): arrows, row titles, cursor, the four rows'
   windows (row 11 shows in row 0's window) and the guide's explanation of the cursor row. */
void func_80102B90_3531A0_name_51(void) {
    s32 i;
    s32 row;

    func_8010361C_353C2C_name_51();
    if (D_8010848C_358A9C_name_51 == 0) {
        SprAttrSet((s16)D_80108A98_3590A8_name_51, 1, 0x8000);
    } else {
        SprAttrReset((s16)D_80108A98_3590A8_name_51, 1, 0x8000);
    }
    if (D_8010848C_358A9C_name_51 == 8) {
        SprAttrSet((s16)D_80108A98_3590A8_name_51, 2, 0x8000);
    } else {
        SprAttrReset((s16)D_80108A98_3590A8_name_51, 2, 0x8000);
    }
    for (i = 0; i < 12; i++) {
        SprAttrSet((s16)D_80108AA4_3590B4_name_51, i + 1, 0x8000);
    }
    for (i = 0; i < 4; i++) {
        SprAttrReset((s16)D_80108AA4_3590B4_name_51, i + ((u16)D_8010848C_358A9C_name_51 + 1), 0x8000);
        SprPosSet((s16)D_80108AA4_3590B4_name_51, i + ((u16)D_8010848C_358A9C_name_51 + 1),
                  D_801084A4_358AB4_name_51[i][0] / D_801084F4_358B04_name_51[i + D_8010848C_358A9C_name_51],
                  D_801084A4_358AB4_name_51[i][1] / D_801084F4_358B04_name_51[i + D_8010848C_358A9C_name_51]);
    }
    SprPosSet((s16)D_80108A88_359098_name_51, 0, D_80108494_358AA4_name_51[D_80108490_358AA0_name_51][0],
              D_80108494_358AA4_name_51[D_80108490_358AA0_name_51][1]);
    for (i = 0; i < 11; i++) {
        func_8008D5D8_8E1D8((s16)D_80108AE0_3590F0_name_51[i]);
    }
    for (i = 0; i < 4; i++) {
        row = i + D_8010848C_358A9C_name_51;
        if (row == 11) {
            row = 0;
        }
        func_8008D6F0_8E2F0((s16)D_80108AE0_3590F0_name_51[row]);
        func_800896DC_8A2DC((s16)D_80108AE0_3590F0_name_51[row], D_801084B4_358AC4_name_51[i][0],
                            D_801084B4_358AC4_name_51[i][1]);
    }
    func_8008AD44_8B944(D_80108AD8_3590E8_name_51->amount);
    func_80089A48_8A648(D_80108AD8_3590E8_name_51->amount, 0);
    func_800890CC_89CCC(D_80108AD8_3590E8_name_51->amount,
                        D_801085B0_358BC0_name_51[D_8010848C_358A9C_name_51 + D_80108490_358AA0_name_51], -1, -1);
}

/* Spaces in a number become 0x1A (the font's blank digit). */
void func_80102E7C_35348C_name_51(u8* str) {
    if (*str != 0) {
        do {
            if (*str == ' ') {
                *str = 0x1A;
            }
            str++;
        } while (*str != 0);
    }
}

__asm__(".section .rodata");
const char D_80108770_358D80_name_51[] = "%3d";

/* One row of the stats table: each player's value printed into its digits buffer. */
#define OVL51_STATROW(i, j, cast, field)                                                           \
    for (j = 0; j < 4; j++) {                                                                      \
        sprintf((char*)D_80108B10_359120_name_51[i][j], D_80108770_358D80_name_51,                        \
                (cast)gPlayers[D_800F8CE4_F98E4[j]].field);                                        \
        func_80102E7C_35348C_name_51(D_80108B10_359120_name_51[i][j]);                             \
        func_80089308_89F08((s16)D_80108AE0_3590F0_name_51[i], (char*)D_80108B10_359120_name_51[i][j], j); \
    }                                                                                              \
    D_800F920C_F9E0C[D_80108AE0_3590F0_name_51[i]].unk4C = 8;                                      \
    func_800890CC_89CCC((s16)D_80108AE0_3590F0_name_51[i], 0x61B, 8, 4)

/* Fills the stats table's windows (MP1 func_800F6C70): stars, coins, minigame coins (minus signs
   drawn as '='), max coins, then the blue, red, happening, chance, Bowser, battle and item space
   counts. Row 11 (bank spaces) shares row 0's window: func_8010361C swaps it in. */
void func_80102EB4_3534C4_name_51(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                OVL51_STATROW(i, j, s16, stars);
                break;
            case 1:
                OVL51_STATROW(i, j, s16, coins);
                break;
            case 2:
                for (j = 0; j < 4; j++) {
                    sprintf((char*)D_80108B10_359120_name_51[i][j], "%4d", gPlayers[D_800F8CE4_F98E4[j]].coins_total);
                    func_80102E7C_35348C_name_51(D_80108B10_359120_name_51[i][j]);
                    for (k = 0; k < 4; k++) {
                        if (D_80108B10_359120_name_51[i][j][k] == '-') {
                            D_80108B10_359120_name_51[i][j][k] = '=';
                        }
                    }
                    func_80089308_89F08((s16)D_80108AE0_3590F0_name_51[i], (char*)D_80108B10_359120_name_51[i][j], j);
                }
                D_800F920C_F9E0C[D_80108AE0_3590F0_name_51[i]].unk4C = 4;
                func_800890CC_89CCC((s16)D_80108AE0_3590F0_name_51[i], 0x61B, 3, 4);
                break;
            case 3:
                OVL51_STATROW(i, j, s16, coins_max);
                break;
            case 4:
                OVL51_STATROW(i, j, s8, blue_spaces_landed_on);
                break;
            case 5:
                OVL51_STATROW(i, j, s8, red_spaces_landed_on);
                break;
            case 6:
                OVL51_STATROW(i, j, s8, happening_spaces_landed_on);
                break;
            case 7:
                OVL51_STATROW(i, j, s8, chance_spaces_landed_on);
                break;
            case 8:
                OVL51_STATROW(i, j, s8, bowser_spaces_landed_on);
                break;
            case 9:
                OVL51_STATROW(i, j, s8, battle_spaces_landed_on);
                break;
            case 10:
                OVL51_STATROW(i, j, s8, item_spaces_landed_on);
                break;
        }
    }
}

/* Row 11 (bank spaces) and row 0 (stars) share window 0: rows 4 and 5 at the top bring row 0 or
   row 11 into view, so the window is refilled with the row on screen. */
void func_8010361C_353C2C_name_51(void) {
    s32 j;

    if (D_8010848C_358A9C_name_51 == 4 || D_8010848C_358A9C_name_51 == 5) {
        func_8008AD44_8B944((s16)D_80108AE0_3590F0_name_51[0]);
        if (D_8010848C_358A9C_name_51 == 5) {
            for (j = 0; j < 4; j++) {
                sprintf((char*)D_80108B10_359120_name_51[0][j], D_80108770_358D80_name_51,
                        (s8)gPlayers[D_800F8CE4_F98E4[j]].bank_spaces_landed_on);
                func_80102E7C_35348C_name_51(D_80108B10_359120_name_51[0][j]);
                func_80089308_89F08((s16)D_80108AE0_3590F0_name_51[0], (char*)D_80108B10_359120_name_51[0][j], j);
            }
        } else {
            for (j = 0; j < 4; j++) {
                sprintf((char*)D_80108B10_359120_name_51[0][j], D_80108770_358D80_name_51,
                        (s16)gPlayers[D_800F8CE4_F98E4[j]].stars);
                func_80102E7C_35348C_name_51(D_80108B10_359120_name_51[0][j]);
                func_80089308_89F08((s16)D_80108AE0_3590F0_name_51[0], (char*)D_80108B10_359120_name_51[0][j], j);
            }
        }
        D_800F920C_F9E0C[D_80108AE0_3590F0_name_51[0]].unk4C = 8;
        func_800890CC_89CCC((s16)D_80108AE0_3590F0_name_51[0], 0x61B, 8, 4);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801037E0_353DF0_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_8010418C_35479C_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80104308_354918_name_51);

__asm__(".section .rodata");
const char D_801087A4_358DB4_name_51[] = "RESULTS";

__asm__(".section .rodata");
const char D_801087AC_358DBC_name_51[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80104490_354AA0_name_51);

__asm__(".section .rodata");
const char D_801087B4_358DC4_name_51[] = "X%2d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80104F6C_35557C_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80105468_355A78_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801055E4_355BF4_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801058CC_355EDC_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80105BE0_3561F0_name_51);

__asm__(".section .rodata");
const char D_801087BC_358DCC_name_51[] = "%5d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80105D38_356348_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80105E6C_35647C_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801062AC_3568BC_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80106660_356C70_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80106884_356E94_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80106A60_357070_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80106A9C_3570AC_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80107090_3576A0_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801076B8_357CC8_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801077A8_357DB8_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80107818_357E28_name_51);

__asm__(".section .rodata");
const u32 D_801087C0_358DD0_name_51[4] = { 0x58000000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80107EA4_3584B4_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80107FE8_3585F8_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80108034_358644_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_80108058_358668_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801081CC_3587DC_name_51);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_51_name/352E10", func_801082AC_3588BC_name_51);
