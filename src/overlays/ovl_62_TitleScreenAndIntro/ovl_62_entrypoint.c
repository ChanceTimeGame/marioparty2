#include "common.h"

extern board_overlay_entrypoint D_80111010_3E3530_TitleScreenAndIntro[]; /* the overlay's scene table, the first .data */
void ExecBoardScene(void*, s16);

void func_80102800_3D4D20_TitleScreenAndIntro(void) {
    ExecBoardScene(D_80111010_3E3530_TitleScreenAndIntro, D_800CD414_CE014);
}
