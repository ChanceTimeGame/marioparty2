#include "ovl_62.h"

/* .data (0x3E3530-0x3E3550): the overlay's scene table */
board_overlay_entrypoint D_80111010_3E3530_TitleScreenAndIntro[] = {
    { 0, func_80102998_3D4EB8_TitleScreenAndIntro },
    { 1, func_801029C0_3D4EE0_TitleScreenAndIntro },
    { -1, NULL },
};

void func_80102800_3D4D20_TitleScreenAndIntro(void) {
    ExecBoardScene(D_80111010_3E3530_TitleScreenAndIntro, D_800CD414_CE014);
}
