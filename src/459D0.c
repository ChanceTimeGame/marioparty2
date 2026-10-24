#include "common.h"
#include "game/malloc.h"
#include "game/pad.h"

/* Debug text with a drop shadow, the button-sequence watcher and the debug readouts, from MP1
   src/3F5B0.c (func_80044F5C and func_80044F78 are MP1 func_8003EE3C and func_8003EE58). */

typedef struct ButtonSeqWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ u16* sequence;
    /* 0x08 */ s16 index;
} ButtonSeqWork;

extern s32 fontcolor;

s16 DrawDebugText(u16, u16, char*); /* MP1 print8 */
GW_PLAYER* BoardPlayerGet(s32);
s16 GetSumOfPlayerStars(void);

extern char pfStrBuf[];
extern s16 starBlockSpaceIndex;
extern s16 coinBlockSpaceIndex;
extern s16 D_800FD898_FE498;
extern s16 D_800FA60A_FB20A;
extern s16 D_801026D6_1032D6;
extern s16 D_800F9560_FA160;
extern s16 D_800FD2B4_FDEB4;
extern s16 D_800FDBD8_FE7D8; /* MP1 kakusiMasuStar */
extern s16 D_800FFDF8_1009F8; /* MP1 kakusiMasuCoin */

void func_80044DD0_459D0(u16 arg0, u16 arg1, char* arg2, u8 arg3, u8 arg4) {
    fontcolor = arg4;
    DrawDebugText((arg0 + 1), (arg1 + 1), arg2);
    fontcolor = arg3;
    DrawDebugText(arg0, arg1, arg2);
}

void func_80044E50_45A50(void) {
    ButtonSeqWork* work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        if (ContBtnTrg[0] != 0) {
            if (ContBtnTrg[0] == work->sequence[work->index]) {
                work->index++;
                if (work->sequence[work->index] == 0) {
                    work->index = -1;
                    break;
                }
            } else {
                work->index = 0;
            }
        }
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

void* func_80044EFC_45AFC(s32* sequence) {
    Process* process = omAddPrcObj(func_80044E50_45A50, 0xEFFF, 0, 0x40);
    ButtonSeqWork* work = HuMemMemoryAlloc(process->heap, sizeof(ButtonSeqWork));

    process->user_data = work;
    work->sequence = (u16*)sequence;
    work->index = 0;
    work->process = process;
    return work;
}

void func_80044F5C_45B5C(void* work) {
    omDelPrcObj(((ButtonSeqWork*)work)->process);
}

s32 func_80044F78_45B78(void* work) {
    return ((ButtonSeqWork*)work)->index == -1;
}

void func_80044F88_45B88(s16 x, s16 y) {
    s32 i;
    GW_PLAYER* player;

    sprintf(pfStrBuf, "   GAM COI  ?  R BL  !  K BTL I BN");
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
    for (i = 0; i < 4; ) {
        player = BoardPlayerGet(i);
        i++;
        sprintf(pfStrBuf, "%d: %3d %3d %2d %2d %2d %2d %2d %2d %2d %2d", i, player->coins_total, player->coins_max,
                (s8)player->happening_spaces_landed_on, (s8)player->red_spaces_landed_on,
                (s8)player->blue_spaces_landed_on, (s8)player->chance_spaces_landed_on,
                (s8)player->bowser_spaces_landed_on, (s8)player->battle_spaces_landed_on,
                (s8)player->item_spaces_landed_on, (s8)player->bank_spaces_landed_on);
        func_80044DD0_459D0(x * 8, (y + i) * 8, pfStrBuf, 15, 9);
    }
}

void func_800450C0_45CC0(s16 x, s16 y) {
    sprintf(pfStrBuf, "KMS: %d", starBlockSpaceIndex);
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "KMC: %d", coinBlockSpaceIndex);
    func_80044DD0_459D0(x * 8, (y + 1) * 8, pfStrBuf, 15, 9);
}

void func_80045184_45D84(s16 x, s16 y) {
    sprintf(pfStrBuf, "STAR:%2d", GetSumOfPlayerStars());
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
}

/* Board event counters (MP1 func_8003F07C); retail prints the "4" line twice at row y + 3. */
void func_800451F8_45DF8(s16 x, s16 y) {
    sprintf(pfStrBuf, "1VS3:%2d", D_800FD898_FE498);
    func_80044DD0_459D0(x * 8, (y + 1) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "2VS2:%2d", D_800FA60A_FB20A);
    func_80044DD0_459D0(x * 8, (y + 2) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "4   :%2d", D_801026D6_1032D6);
    func_80044DD0_459D0(x * 8, (y + 3) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "4   :%2d", D_801026D6_1032D6);
    func_80044DD0_459D0(x * 8, (y + 3) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "BTL :%2d", D_800F9560_FA160);
    func_80044DD0_459D0(x * 8, (y + 4) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "ITEM:%2d", D_800FD2B4_FDEB4);
    func_80044DD0_459D0(x * 8, (y + 5) * 8, pfStrBuf, 15, 9);
}

void func_800453C4_45FC4(s16 x, s16 y) {
    sprintf(pfStrBuf, "YOBIDASI COIN:%2d", D_800FDBD8_FE7D8);
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "YOBIDASI STAR:%2d", D_800FFDF8_1009F8);
    func_80044DD0_459D0(x * 8, (y + 1) * 8, pfStrBuf, 15, 9);
}

void func_80045488_46088(s16 x, s16 y) {
    sprintf(pfStrBuf, "1P STAR:%2d", gPlayers[0].stars);
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "2P STAR:%2d", gPlayers[1].stars);
    func_80044DD0_459D0(x * 8, (y + 1) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "3P STAR:%2d", gPlayers[2].stars);
    func_80044DD0_459D0(x * 8, (y + 2) * 8, pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "4P STAR:%2d", gPlayers[3].stars);
    func_80044DD0_459D0(x * 8, (y + 3) * 8, pfStrBuf, 15, 9);
}

void func_800455CC_461CC(s16 x, s16 y) {
    sprintf(pfStrBuf, "MAP: %d    TURN: %d", GwSystem.current_board_index + 1, GwSystem.current_turn - 1);
    func_80044DD0_459D0(x * 8, y * 8, pfStrBuf, 15, 9);
}
