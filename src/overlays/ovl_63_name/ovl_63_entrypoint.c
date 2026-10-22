#include "common.h"

extern board_overlay_entrypoint D_801028B0_3E4300_name_63[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_3E4250_name_63(void) {
    ExecBoardScene(D_801028B0_3E4300_name_63, D_800CD414_CE014);
}
