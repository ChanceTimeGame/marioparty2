#include "common.h"
#include "ovl_3E.h"

/* .data (0x2A6BF0-0x2A6C20): the overlay's scene table */
board_overlay_entrypoint D_80111920_2A6BF0_name_3E[] = {
    { 0, func_801058A4_29AB74_name_3E },
    { 1, func_801058DC_29ABAC_name_3E },
    { 2, func_80105B9C_29AE6C_name_3E },
    { 3, func_80105C24_29AEF4_name_3E },
    { 4, func_801112E4_2A65B4_name_3E },
    { -1, NULL },
};

void func_80102800_297AD0_name_3E(void) {
    ExecBoardScene(D_80111920_2A6BF0_name_3E, D_800CD414_CE014);
}
