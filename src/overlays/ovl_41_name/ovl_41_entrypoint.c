#include "common.h"
#include "ovl_41.h"

/* .data (0x2BF2F0-0x2BF320): the overlay's scene table */
board_overlay_entrypoint D_80110A30_2BF2F0_name_41[6] = {
    { 0, func_801058A4_2B4164_name_41 },
    { 1, func_801058E0_2B41A0_name_41 },
    { 2, func_80105BE8_2B44A8_name_41 },
    { 3, func_80105C70_2B4530_name_41 },
    { 4, func_801103EC_2BECAC_name_41 },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_2B10C0_name_41(void) {
    ExecBoardScene(D_80110A30_2BF2F0_name_41, D_800CD414_CE014);
}
