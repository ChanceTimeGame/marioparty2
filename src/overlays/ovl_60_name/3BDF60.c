#include "common.h"
#include "ovl_60.h"

/* .data (0x3CEA00-0x3CEA10): the overlay's scene table */
board_overlay_entrypoint D_801132A0_3CEA00_name_60[] = {
    { 0, func_80108AEC_3C424C_name_60 },
    { -1, NULL },
};

void func_80102800_3BDF60_name_60(void) {
    ExecBoardScene(D_801132A0_3CEA00_name_60, D_800CD414_CE014);
}
