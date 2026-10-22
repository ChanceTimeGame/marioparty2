#include "common.h"

extern board_overlay_entrypoint D_80113AA0_2D8F90_name_43[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_2C7CF0_name_43(void) {
    ExecBoardScene(D_80113AA0_2D8F90_name_43, D_800CD414_CE014);
}
