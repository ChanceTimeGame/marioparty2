#include "common.h"
#include "ovl_45.h"

/* .data (0x2EF400-0x2EF430): the overlay's scene table */
board_overlay_entrypoint D_80110CD0_2EF400_name_45[6] = {
    { 0, func_801058A4_2E3FD4_name_45 },
    { 1, func_801058E0_2E4010_name_45 },
    { 2, func_80105CA4_2E43D4_name_45 },
    { 3, func_80105D0C_2E443C_name_45 },
    { 4, func_80110690_2EEDC0_name_45 },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_2E0F30_name_45(void) {
    ExecBoardScene(D_80110CD0_2EF400_name_45, D_800CD414_CE014);
}
