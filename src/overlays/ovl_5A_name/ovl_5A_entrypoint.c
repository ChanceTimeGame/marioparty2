#include "common.h"

extern board_overlay_entrypoint D_80102A10_37F4A0_name_5A[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_37F290_name_5A(void) {
    ExecBoardScene(D_80102A10_37F4A0_name_5A, D_800CD414_CE014);
}
