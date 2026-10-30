#include "ovl_1A.h"

/* A team's camera: starts behind its car (MP1 func_800FAF9C). */
void func_80109BC0_1A2950_HandcarHavoc(omObjData* obj, u16 team) {
    HHCam* c;
    HHCar* w;
    f32 ry;

    c = obj->unk_50 = func_80027154_27D54(sizeof(HHCam), 0x7918);
    c->cam = team;
    w = D_8010D820_1A65B0_HandcarHavoc[team]->unk_50;
    D_80102770_103370[team].x = c->rx = w->rot.x + w->rot.z - 25.0f;
    ry = w->rot.y;
    D_80102774_103374[team].x = c->ry = ry;
    D_801013B0_101FB0[team].x = D_8010D820_1A65B0_HandcarHavoc[team]->trans.x - HuMathSin(ry) * 300.0f;
    D_801013B4_101FB4[team].x = D_8010D820_1A65B0_HandcarHavoc[team]->trans.y;
    D_801013B8_101FB8[team].x =
        D_8010D820_1A65B0_HandcarHavoc[team]->trans.z - func_800B7890_B8490(D_80102774_103374[team].x) * 300.0f;
    obj->func_ptr = func_80109D10_1A2AA0_HandcarHavoc;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_80109D10_1A2AA0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A200_1A2F90_HandcarHavoc);

void func_8010A400_1A3190_HandcarHavoc(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A408_1A3198_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A440_1A31D0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A5B8_1A3348_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A6A4_1A3434_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A75C_1A34EC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A7D8_1A3568_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A870_1A3600_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AA30_1A37C0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010ABC8_1A3958_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AD1C_1A3AAC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AE30_1A3BC0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B024_1A3DB4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B0FC_1A3E8C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B108_1A3E98_HandcarHavoc);
