#include "common.h"
#include "game/board.h"

/* func_80044DA4 is MP3 ovl_80_shared_board/F5E80.c's MBItemKoopaRKinokoExec (call item handler 13
   of the table D_800DF4B0 is the 14th entry of); the others have no C reference and stay asm. */

extern void (*D_800DF4B0_E00B0)(void);
/* .data (0xCC880-0xCC890) */
s16 D_800CBC80_CC880[7] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C }; /* flags tested by node type 2 (MP1 D_800C4C30) */
extern s16 D_800F8CE4_F98E4[]; /* board work (MP1 GwCommon.boardWork) */
extern s32 D_80100028_100C28;
s32 BoardSpaceGet(s32 index, s32 count);
s16 GetCurrentPlayerIndex(void);
s16 GetTurnsElapsed(void);
s16 RNGPercentChance(s8 arg0);
s32 func_80059FD0_5ABD0(s32);
GW_PLAYER* BoardPlayerGet(s32 playerIndex);

/* NON_MATCHING: layout and register allocation (masked ~113: retail's frame is 0x20 larger, keeps
   cases 13 and 17 apart and shares case 7's compare with case 10). Retail reads node_data1's bytes
   with lbu (offsets 4-7); this C extracts them with shifts so it reads the same values on the host.
   Its jump tables stay in the data blob (jtbl_800D2390_D2F90, jtbl_800D23D8_D2FD8). */
#ifdef NON_MATCHING
/* MP1 src/3F5B0.c's RunDecisionTree, grown to 18 node types. Host: a node's node_data2 is either
   a packed outcome or (negative as s32 on the N64) a pointer to the next node list. */
s16 func_80044800_45400(DecisionTreeNonLeafNode* node) {
    s32 i;
    s32 idx;
    s16 val;
    u32 data;
    u32 op;
    s32 chance;
    s16 ret;
    GW_PLAYER* p;
    u8 chain;
    u8 lo;
    u8 hi;

    for (;; node++) {
        switch (node->type >> 24) {
        case 1:
            if (BoardSpaceGet(-1, node->node_data1.data) != 0) {
                break;
            }
            continue;
        case 2:
            for (i = 0; i < 7; i++) {
                if ((1 << i) & node->node_data1.data) {
                    if (!_CheckFlag(D_800CBC80_CC880[i])) {
                        break;
                    }
                }
            }
            if (i == 7) {
                continue;
            }
            break;
        case 3:
            if ((1 << (D_80100028_100C28 - 1)) & node->node_data1.data) {
                break;
            }
            continue;
        case 4:
            data = node->node_data1.data;
            idx = data >> 20;
            val = node->node_data1.data;
            op = (data >> 16) & 0xF;
            idx &= 0xFF;
            switch (op) {
            case 0:
                if (D_800F8CE4_F98E4[idx] == val) {
                    break;
                }
                continue;
            case 1:
                if (D_800F8CE4_F98E4[idx] != val) {
                    break;
                }
                continue;
            case 2:
                if (D_800F8CE4_F98E4[idx] < val) {
                    break;
                }
                continue;
            case 3:
                if (D_800F8CE4_F98E4[idx] <= val) {
                    break;
                }
                continue;
            case 4:
                if (D_800F8CE4_F98E4[idx] > val) {
                    break;
                }
                continue;
            case 5:
                if (D_800F8CE4_F98E4[idx] < val) {
                    continue;
                }
                break;
            }
            break;
        case 5:
            if ((1 << func_80059FD0_5ABD0(GetCurrentPlayerIndex())) & node->node_data1.data) {
                break;
            }
            continue;
        case 6:
            if (((s32 (*)(void))node->node_data1.func)() != 0) {
                break;
            }
            continue;
        case 7:
            if ((u32)GetTurnsElapsed() < (u32)node->node_data1.data) {
                continue;
            }
            break;
        case 8:
            if (gPlayers[GwSystem.current_player_index].item == node->node_data1.data) {
                break;
            }
            continue;
        case 9:
            for (i = 0; i < 7; i++) {
                if ((1 << i) & node->node_data1.data) {
                    if (GwSystem.unk_1C == i) {
                        break;
                    }
                }
            }
            if (i == 7) {
                continue;
            }
            break;
        case 10:
            if ((u32)D_80100028_100C28 < (u32)node->node_data1.data) {
                continue;
            }
            break;
        case 11:
            lo = (node->node_data1.data >> 8) & 0xFF;
            hi = node->node_data1.data & 0xFF;
            p = BoardPlayerGet(-1);
            if (p->cur_chain_index != lo) {
                continue;
            }
            if (p->cur_space_index == hi) {
                break;
            }
            continue;
        case 12:
            /* retail: the inner break only leaves the loop, so this node never succeeds */
            lo = (node->node_data1.data >> 8) & 0xFF;
            hi = node->node_data1.data & 0xFF;
            for (i = 0; i < 4; i++) {
                if (i == GetCurrentPlayerIndex()) {
                    continue;
                }
                p = BoardPlayerGet(i);
                if (p->cur_chain_index == lo && p->cur_space_index == hi) {
                    break;
                }
            }
            continue;
        case 13:
            chain = (node->node_data1.data >> 16) & 0xFF;
            lo = (node->node_data1.data >> 8) & 0xFF;
            hi = node->node_data1.data & 0xFF;
            p = BoardPlayerGet(-1);
            if (p->cur_chain_index != chain) {
                continue;
            }
            if (p->cur_space_index < lo) {
                continue;
            }
            if (hi < p->cur_space_index) {
                continue;
            }
            break;
        case 14:
            /* retail: as case 12, never succeeds */
            chain = (node->node_data1.data >> 16) & 0xFF;
            lo = (node->node_data1.data >> 8) & 0xFF;
            hi = node->node_data1.data & 0xFF;
            for (i = 0; i < 4; i++) {
                if (i == GetCurrentPlayerIndex()) {
                    continue;
                }
                p = BoardPlayerGet(i);
                if (p->cur_chain_index == chain && !(p->cur_space_index < lo) && !(hi < p->cur_space_index)) {
                    break;
                }
            }
            continue;
        case 15:
            if (BoardSpaceGet(-1, node->node_data1.data) == 0) {
                break;
            }
            continue;
        case 16:
            if (gPlayers[GetCurrentPlayerIndex()].character == node->node_data1.data) {
                break;
            }
            continue;
        case 17:
            chain = (node->node_data1.data >> 16) & 0xFF;
            lo = (node->node_data1.data >> 8) & 0xFF;
            hi = node->node_data1.data & 0xFF;
            p = BoardPlayerGet((u8)(node->node_data1.data >> 24));
            if (p->cur_chain_index != chain) {
                continue;
            }
            if (p->cur_space_index < lo) {
                continue;
            }
            if (hi < p->cur_space_index) {
                continue;
            }
            break;
        }
        if (node->node_data2.data < 0) {
            node = (DecisionTreeNonLeafNode*)node->node_data2.data - 1;
        } else {
            switch (BoardPlayerGet(-1)->cpu_difficulty2) {
            case 0:
                chance = node->node_data2.data & 0xFF;
                break;
            case 1:
            case 2:
                chance = node->node_data2.data >> 8;
                break;
            default:
                chance = 0;
                break;
            }
            if (RNGPercentChance(chance) != 0) {
                ret = (node->node_data2.data >> 16) & 1;
            } else {
                ret = ((node->node_data2.data >> 16) ^ 1) & 1;
            }
            return ret;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/45400", func_80044800_45400);
#endif

void func_80044D98_45998(void (*fn)(void)) {
    D_800DF4B0_E00B0 = fn;
}

void func_80044DA4_459A4(void) {
    D_800DF4B0_E00B0();
}
