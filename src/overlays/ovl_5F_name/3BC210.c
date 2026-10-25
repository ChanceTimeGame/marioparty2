#include "common.h"
#include "ovl_5F.h"

/* Mini-Game Coaster: set up the players for the chosen minigame from the quest tables. */
/* NON_MATCHING: retail zero-extends the two rand8() & 3 indices again (an extra andi 0xff
   each); everything else matches. */
#ifdef NON_MATCHING
void func_80113070_3BC210_name_5F(s16 mg) {
    s16 chars[4];
    Ovl5FQuestGame* q;
    s16 idx;
    s16 c2;
    s16 c1;
    s16 i;
    s16 n;
    u8 a;
    u8 b;
    s16 tmp;

    if (_CheckFlag(0xE) != 0) {
        mg = 0x48;
    }
    idx = D_80114250_3BD3F0_name_5F[mg];
    if (idx == -1) {
        osSyncPrintf("instquest.c : qgameno error\n");
        while (1) {
        }
    }
    c2 = (s8)D_800FD8A8_FE4A8.unk01;
    c1 = (s8)D_800FD8A8_FE4A8.unk00;
    switch (D_800FD8A8_FE4A8.unk04) {
    case 0:
        q = &D_8011429C_3BD43C_name_5F[idx];
        break;
    case 1:
        q = &D_80114338_3BD4D8_name_5F[idx];
        break;
    default:
        q = &D_801144A0_3BD640_name_5F[idx];
        break;
    }
    D_800FC890_FD490->mes[0] = q->mes[0];
    D_800FC890_FD490->mes[1] = q->mes[1];
    D_800FC890_FD490->mes[2] = q->mes[2];
    D_800FA656 = q->variant;
    gPlayers[0].character = c1;
    gPlayers[0].group = q->group;
    if (_CheckFlag(0xE) == 0) {
        for (i = 0; i < 4; i++) {
            gPlayers[i].cpu_difficulty = q->cpu;
        }
    }
    n = 0;
    for (i = 0; i < 6; i++) {
        if ((i == c1) | (i == c2)) {
            continue;
        }
        chars[n++] = i;
    }
    for (i = 0; i < 20; i++) {
        a = rand8() & 3;
        b = rand8() & 3;
        tmp = chars[a];
        chars[a] = chars[b];
        chars[b] = tmp;
    }
    for (i = 1; i < 4; i++) {
        gPlayers[i].flags |= 1;
    }
    if (q->group2 == -1) {
        switch (D_80114F60_3BE100_name_5F[0]) {
        case 2:
            if (q->group != 0) {
                gPlayers[1].group = 1;
                gPlayers[2].group = gPlayers[3].group = 0;
            } else {
                gPlayers[1].group = 0;
                gPlayers[2].group = gPlayers[3].group = 1;
            }
            break;
        case 1:
            if (q->group == 0) {
                gPlayers[1].group = gPlayers[2].group = gPlayers[3].group = 1;
            } else {
                gPlayers[1].group = 0;
                gPlayers[2].group = gPlayers[3].group = 1;
            }
            break;
        default:
            for (i = 1; i < 4; i++) {
                gPlayers[i].group = i;
            }
            break;
        }
        for (i = 1; i < 4; i++) {
            gPlayers[i].character = chars[i];
        }
        return;
    }
    gPlayers[1].cpu_difficulty = q->cpu2;
    gPlayers[1].character = c2;
    switch (D_80114F60_3BE100_name_5F[0]) {
    case 2:
        switch (idx) {
        case 7:
            gPlayers[0].group = 0;
            gPlayers[1].group = 1;
            gPlayers[2].group = 2;
            gPlayers[3].group = 3;
            break;
        case 21:
            gPlayers[0].group = 0;
            gPlayers[1].group = 1;
            gPlayers[2].group = 2;
            gPlayers[3].group = 3;
            break;
        case 8:
        case 22:
            gPlayers[0].group = 1;
            gPlayers[1].group = 0;
            gPlayers[2].group = 2;
            gPlayers[3].group = 3;
            break;
        case 23:
            if (rand8() & 1) {
                gPlayers[0].group = 0;
                gPlayers[1].group = 1;
            } else {
                gPlayers[0].group = 1;
                gPlayers[1].group = 0;
            }
            gPlayers[2].group = 2;
            gPlayers[3].group = 3;
            break;
        default:
            if (q->group == 0) {
                gPlayers[1].group = q->group2;
                gPlayers[2].group = gPlayers[3].group = 1;
            } else {
                gPlayers[1].group = q->group2;
                gPlayers[2].group = gPlayers[3].group = 0;
            }
            break;
        }
        break;
    case 1:
        if (q->group == 0) {
            gPlayers[1].group = gPlayers[2].group = gPlayers[3].group = 1;
        } else {
            gPlayers[2].group = 0;
            gPlayers[0].group = gPlayers[1].group = gPlayers[3].group = 1;
            gPlayers[1].cpu_difficulty = gPlayers[3].cpu_difficulty = q->cpu2;
        }
        break;
    default:
        for (i = 1; i < 4; i++) {
        gPlayers[i].group = i;
        }
        break;
    }
    for (i = 2; i < 4; i++) {
        gPlayers[i].character = chars[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3BC210", func_80113070_3BC210_name_5F);
#endif

void func_801136C4_3BC864_name_5F(s16 mg) {
    D_80114F60_3BE100_name_5F[0] = D_80114F72_3BE112_name_5F;
    func_80113070_3BC210_name_5F(mg);
}

/* .data (0x3BD3F0-0x3BD850, 80114250-801146B0) */

s8 D_80114250_3BD3F0_name_5F[76] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1,
    9, 27, 29, 10, 26, 25, 28, 11, -1, 23, 19, 20, -1, 6, 21, 8,
    4, -1, -1, 18, 40, 33, 17, 13, 31, 1, 32, 35, 15, 0, -1, 41,
    14, 30, 39, 34, 3, 37, 38, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 7, 22, 5, 16, 2, 24, 36, 42, 0, 0, 0,
};
Ovl5FQuestGame D_8011429C_3BD43C_name_5F[13] = {
    { 0, -1, 0, 3, 0, 0, { 0x543, 0x169, 0x16A } },
    { 0, -1, 2, 3, 0, 0, { 0x544, 0x15B, 0x15D } },
    { 0, -1, 0, 3, 0, 0, { 0x545, 0x18C, 0x18D } },
    { 0, -1, 0, 3, 0, 0, { 0x546, 0x180, 0x181 } },
    { 0, 0, 0, 3, 0, 0, { 0x547, 0x139, 0x13A } },
    { 0, 0, 0, 3, 0, 0, { 0x548, 0x149, 0x14A } },
    { 0, 0, 0, 3, 0, 0, { 0x549, 0x12F, 0x130 } },
    { 0, 0, 0, 3, 0, 0, { 0x54A, 0x142, 0x143 } },
    { 0, 1, 0, 3, 0, 0, { 0x54B, 0x136, 0x137 } },
    { 0, -1, 0, 3, 0, 0, { 0x54C, 0x54D, 0x108 } },
    { 0, -1, 0, 3, 0, 0, { 0x54E, 0x111, 0x112 } },
    { 0, -1, 0, 3, 0, 0, { 0x54F, 0x550, 0x121 } },
    { 0, -1, 0, 3, 0, 0, { 0x551, 0x552, 0x553 } },
};
Ovl5FQuestGame D_80114338_3BD4D8_name_5F[30] = {
    { 0, -1, 1, 3, 0, 0, { 0x543, 0x169, 0x16B } },
    { 0, -1, 1, 3, 1, 0, { 0x544, 0x15B, 0x15E } },
    { 0, -1, 1, 3, 1, 0, { 0x545, 0x18C, 0x18D } },
    { 0, -1, 1, 3, 0, 0, { 0x546, 0x180, 0x181 } },
    { 0, 0, 0, 3, 1, 0, { 0x547, 0x139, 0x13A } },
    { 0, 0, 1, 3, 1, 0, { 0x548, 0x149, 0x14A } },
    { 0, 0, 0, 3, 1, 0, { 0x549, 0x12F, 0x130 } },
    { 0, 0, 0, 3, 1, 0, { 0x54A, 0x142, 0x143 } },
    { 0, 1, 0, 3, 1, 0, { 0x54B, 0x136, 0x137 } },
    { 0, -1, 0, 3, 1, 0, { 0x54C, 0x54D, 0x108 } },
    { 0, -1, 0, 3, 1, 0, { 0x54E, 0x111, 0x112 } },
    { 0, -1, 0, 3, 1, 0, { 0x54F, 0x550, 0x121 } },
    { 0, -1, 1, 3, 1, 0, { 0x551, 0x552, 0x553 } },
    { 0, -1, 0, 3, 1, 0, { 0x554, 0x155, 0x156 } },
    { 0, -1, 0, 3, 1, 0, { 0x555, 0x174, 0x175 } },
    { 0, -1, 0, 3, 1, 0, { 0x556, 0x166, 0x167 } },
    { 0, -1, 0, 3, 1, 0, { 0x557, 0x189, 0x18A } },
    { 0, -1, 1, 3, 1, 0, { 0x558, 0x152, 0x153 } },
    { 0, 0, 0, 3, 0, 0, { 0x559, 0x1AE, 0x55B } },
    { 0, 0, 0, 3, 1, 0, { 0x55C, 0x126, 0x127 } },
    { 0, 0, 0, 3, 1, 0, { 0x55D, 0x129, 0x12A } },
    { 0, 0, 0, 3, 1, 0, { 0x55E, 0x55F, 0x560 } },
    { 0, 0, 0, 3, 1, 0, { 0x561, 0x562, 0x563 } },
    { 0, 0, 0, 3, 0, 0, { 0x564, 0x123, 0x124 } },
    { 1, -1, 0, 3, 0, 0, { 0x565, 0x567, 0x568 } },
    { 0, -1, 0, 3, 1, 0, { 0x569, 0x56B, 0x56D } },
    { 1, 1, 0, 3, 1, 0, { 0x56F, 0x571, 0x573 } },
    { 1, 1, 0, 3, 1, 0, { 0x575, 0x577, 0x578 } },
    { 0, -1, 0, 3, 1, 0, { 0x57A, 0x57B, 0x11D } },
    { 0, -1, 0, 3, 1, 0, { 0x57C, 0x57D, 0x57E } },
};
Ovl5FQuestGame D_801144A0_3BD640_name_5F[43] = {
    { 0, -1, 2, 3, 0, 0, { 0x543, 0x169, 0x16C } },
    { 0, -1, 0, 3, 2, 0, { 0x544, 0x15B, 0x15C } },
    { 0, -1, 2, 3, 2, 0, { 0x545, 0x18C, 0x18D } },
    { 0, -1, 2, 3, 0, 0, { 0x546, 0x180, 0x181 } },
    { 0, 0, 0, 3, 2, 0, { 0x547, 0x139, 0x13A } },
    { 0, 0, 2, 3, 2, 0, { 0x548, 0x149, 0x14A } },
    { 0, 0, 0, 3, 2, 0, { 0x549, 0x12F, 0x130 } },
    { 0, 0, 0, 3, 2, 0, { 0x54A, 0x142, 0x143 } },
    { 0, 1, 0, 3, 2, 0, { 0x54B, 0x136, 0x137 } },
    { 0, -1, 0, 3, 2, 0, { 0x54C, 0x54D, 0x108 } },
    { 0, -1, 0, 3, 1, 0, { 0x54E, 0x111, 0x112 } },
    { 0, -1, 0, 3, 2, 0, { 0x54F, 0x550, 0x121 } },
    { 0, -1, 2, 3, 2, 0, { 0x551, 0x552, 0x553 } },
    { 0, -1, 0, 3, 2, 0, { 0x554, 0x155, 0x156 } },
    { 0, -1, 0, 3, 2, 0, { 0x555, 0x174, 0x175 } },
    { 0, -1, 0, 3, 2, 0, { 0x556, 0x166, 0x167 } },
    { 0, -1, 0, 3, 2, 0, { 0x557, 0x189, 0x18A } },
    { 0, -1, 0, 3, 2, 0, { 0x558, 0x152, 0x153 } },
    { 0, 0, 0, 3, 1, 0, { 0x55A, 0x1AE, 0x55B } },
    { 0, 0, 0, 3, 2, 0, { 0x55C, 0x126, 0x127 } },
    { 0, 0, 0, 3, 2, 0, { 0x55D, 0x129, 0x12A } },
    { 0, 0, 0, 3, 2, 0, { 0x55E, 0x55F, 0x560 } },
    { 0, 0, 0, 3, 2, 0, { 0x561, 0x562, 0x563 } },
    { 0, 0, 1, 3, 1, 0, { 0x564, 0x123, 0x124 } },
    { 1, -1, 0, 3, 1, 0, { 0x566, 0x567, 0x568 } },
    { 1, 1, 0, 3, 2, 0, { 0x56A, 0x56C, 0x56E } },
    { 1, 1, 0, 3, 2, 0, { 0x570, 0x572, 0x574 } },
    { 1, 1, 1, 3, 2, 0, { 0x576, 0x577, 0x579 } },
    { 0, -1, 0, 3, 2, 0, { 0x57A, 0x57B, 0x11D } },
    { 0, -1, 0, 3, 2, 0, { 0x57C, 0x57D, 0x57E } },
    { 0, -1, 0, 3, 1, 0, { 0x57F, 0x177, 0x178 } },
    { 0, -1, 0, 3, 1, 0, { 0x580, 0x158, 0x159 } },
    { 0, -1, 0, 3, 1, 0, { 0x581, 0x160, 0x161 } },
    { 0, -1, 0, 3, 2, 0, { 0x582, 0x14F, 0x150 } },
    { 0, -1, 0, 3, 1, 0, { 0x583, 0x17D, 0x17E } },
    { 0, -1, 0, 3, 1, 0, { 0x584, 0x163, 0x164 } },
    { 0, -1, 0, 3, 1, 0, { 0x585, 0x1B8, 0x1B9 } },
    { 0, -1, 0, 3, 2, 0, { 0x586, 0x183, 0x184 } },
    { 0, -1, 0, 3, 1, 0, { 0x587, 0x186, 0x187 } },
    { 0, -1, 0, 3, 2, 0, { 0x589, 0x17A, 0x17B } },
    { 0, -1, 0, 3, 2, 0, { 0x588, 0x14C, 0x14D } },
    { 0, -1, 0, 3, 2, 0, { 0x58A, 0x171, 0x172 } },
    { 0, -1, 2, 3, 2, 0, { 0x58B, 0x152, 0x153 } },
};
