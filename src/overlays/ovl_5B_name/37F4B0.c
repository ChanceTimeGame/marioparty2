#include "common.h"
#include "ovl_5B.h"

/* .data (0x38F320-0x38F340): the overlay's scene table */
board_overlay_entrypoint D_80112670_38F320_name_5B[] = {
    { 0, func_80102830_37F4E0_name_5B },
    { 1, func_80102BD0_37F880_name_5B },
    { 2, func_80102C34_37F8E4_name_5B },
    { -1, NULL },
};

void func_80102800_37F4B0_name_5B(void) {
    ExecBoardScene(D_80112670_38F320_name_5B, D_800CD414_CE014);
}
