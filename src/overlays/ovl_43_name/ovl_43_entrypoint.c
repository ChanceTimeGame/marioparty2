#include "common.h"
#include "ovl_43.h"

/* .data (0x2D8F90-0x2D8FC0): the overlay's scene table */
board_overlay_entrypoint D_80113AA0_2D8F90_name_43[6] = {
    { 0, func_80105BF0_2CB0E0_name_43 },
    { 1, func_80105C2C_2CB11C_name_43 },
    { 2, func_80106004_2CB4F4_name_43 },
    { 3, func_801060C8_2CB5B8_name_43 },
    { 4, func_80113460_2D8950_name_43 },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_2C7CF0_name_43(void) {
    ExecBoardScene(D_80113AA0_2D8F90_name_43, D_800CD414_CE014);
}
