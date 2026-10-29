#include "common.h"
#include "ovl_47.h"

/* .data (0x305250-0x305280): the overlay's scene table */
board_overlay_entrypoint D_80110950_305250_name_47[6] = {
    { 0, func_801058A4_2FA1A4_name_47 },
    { 1, func_801058E0_2FA1E0_name_47 },
    { 2, func_80105C5C_2FA55C_name_47 },
    { 3, func_80105CBC_2FA5BC_name_47 },
    { 4, func_80110310_304C10_name_47 },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_2F7100_name_47(void) {
    ExecBoardScene(D_80110950_305250_name_47, D_800CD414_CE014);
}
