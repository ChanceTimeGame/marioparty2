#include "common.h"

extern board_overlay_entrypoint D_80110CD0_2EF400_name_45[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_2E0F30_name_45(void) {
    ExecBoardScene(D_80110CD0_2EF400_name_45, D_800CD414_CE014);
}
