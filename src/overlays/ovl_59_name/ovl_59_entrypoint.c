#include "common.h"

extern board_overlay_entrypoint D_80102BB0_37F230_name_59[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_37EE80_name_59(void) {
    ExecBoardScene(D_80102BB0_37F230_name_59, D_800CD414_CE014);
}
