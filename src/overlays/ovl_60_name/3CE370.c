#include "common.h"
#include "ovl_60.h"

#ifdef NON_MATCHING
void func_80112C10_3CE370_name_60(s16 mg) {
    s16 chars[4];
    Ovl60QuestGame* q;
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
    idx = D_80113DC0_3CF520_name_60[mg];
    if (idx == -1) {
        osSyncPrintf("instquest.c : qgameno error\n");
        while (1) {
        }
    }
    c2 = (s8)D_800FD8A8_FE4A8.unk01;
    c1 = (s8)D_800FD8A8_FE4A8.unk00;
    switch (D_800FD8A8_FE4A8.unk04) {
    case 0:
        q = &D_80113E0C_3CF56C_name_60[idx];
        break;
    case 1:
        q = &D_80113EA8_3CF608_name_60[idx];
        break;
    default:
        q = &D_80114010_3CF770_name_60[idx];
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
        switch (D_80114AB0_3D0210_name_60[0]) {
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
    switch (D_80114AB0_3D0210_name_60[0]) {
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_60_name/3CE370", func_80112C10_3CE370_name_60);
#endif

void func_80113264_3CE9C4_name_60(s16 mg) {
    D_80114AB0_3D0210_name_60[0] = D_80114AC0_3D0220_name_60;
    func_80112C10_3CE370_name_60(mg);
}
