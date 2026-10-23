#include "common.h"

void func_801029C8_37F458_name_5A(void);

/* .data (0x37F4A0-0x37F4B0): the overlay's scene table */
board_overlay_entrypoint D_80102A10_37F4A0_name_5A[] = {
    { 0, func_801029C8_37F458_name_5A },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_37F290_name_5A(void) {
    ExecBoardScene(D_80102A10_37F4A0_name_5A, D_800CD414_CE014);
}
