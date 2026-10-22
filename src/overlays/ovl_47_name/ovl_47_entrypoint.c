#include "common.h"

extern board_overlay_entrypoint D_80110950_305250_name_47[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_2F7100_name_47(void) {
    ExecBoardScene(D_80110950_305250_name_47, D_800CD414_CE014);
}
