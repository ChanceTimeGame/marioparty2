#include "common.h"

extern board_overlay_entrypoint D_80103020_325AE0_name_4B[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_3252C0_name_4B(void) {
    ExecBoardScene(D_80103020_325AE0_name_4B, D_800CD414_CE014);
}
