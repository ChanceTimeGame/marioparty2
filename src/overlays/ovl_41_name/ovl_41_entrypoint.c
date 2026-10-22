#include "common.h"

extern board_overlay_entrypoint D_80110A30_2BF2F0_name_41[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_2B10C0_name_41(void) {
    ExecBoardScene(D_80110A30_2BF2F0_name_41, D_800CD414_CE014);
}
