#include "common.h"

extern board_overlay_entrypoint D_80112BF0_31D0A0_name_49[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_30CCB0_name_49(void) {
    ExecBoardScene(D_80112BF0_31D0A0_name_49, D_800CD414_CE014);
}
