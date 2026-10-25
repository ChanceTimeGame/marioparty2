#include "common.h"
#include "ovl_5F.h"

/* .data (0x3BC8A0-0x3BC8B0): the overlay's scene table */
board_overlay_entrypoint D_80113700_3BC8A0_name_5F[] = {
    { 0, func_80108AEC_3B1C8C_name_5F },
    { -1, NULL },
};

void func_80102800_3AB9A0_name_5F(void) {
    ExecBoardScene(D_80113700_3BC8A0_name_5F, D_800CD414_CE014);
}
