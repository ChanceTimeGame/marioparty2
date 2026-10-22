#include "common.h"

/* Overlay 63: sets board index 7 and enters overlay 0x63's scene 1 (as ovl_3D does for 0x3D). */

void func_80073EF8_74AF8(void);
void func_80073FE0_74BE0(void);

void func_80102830_3E4280_name_63(void) {
    GwSystem.current_board_index = 7;
    omInitObjMan(10, 0);
    func_80073EF8_74AF8();
    omOvlGotoEx(0x63, 1, 0x192);
    omOvlHisChg(0, 0x63, 1, 0x192);
}

void func_80102888_3E42D8_name_63(void) {
    omInitObjMan(10, 0);
    func_80073FE0_74BE0();
}
