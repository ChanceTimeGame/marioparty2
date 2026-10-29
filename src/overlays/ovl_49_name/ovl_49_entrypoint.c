#include "common.h"
#include "ovl_49.h"

/* .data (0x31D0A0-0x31D0D0): the overlay's scene table */
board_overlay_entrypoint D_80112BF0_31D0A0_name_49[6] = {
    { 0, func_80105BFC_3100AC_name_49 },
    { 1, func_80105C38_3100E8_name_49 },
    { 2, func_80105F94_310444_name_49 },
    { 3, func_80106058_310508_name_49 },
    { 4, func_801125B0_31CA60_name_49 },
    { -1, NULL },
};
void ExecBoardScene(void*, s16);

void func_80102800_30CCB0_name_49(void) {
    ExecBoardScene(D_80112BF0_31D0A0_name_49, D_800CD414_CE014);
}
