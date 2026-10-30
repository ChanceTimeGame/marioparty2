#include "common.h"
#include "ovl_14.h"

void func_80105E90_16EDD0_ShockDropOrRoll(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    D_800FA610_FB210 = zoom;
    D_800FD474_FE074.x = rx;
    D_800FD474_FE074.y = ry;
    D_800FD474_FE074.z = rz;
    D_8010274C_10334C.x = cx;
    D_8010274C_10334C.y = cy;
    D_8010274C_10334C.z = cz;
}

/* Ends the minigame once the result is in: fade out, then return. */
void func_80105ED0_16EE10_ShockDropOrRoll(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_80106F60_16FEA0_ShockDropOrRoll == 0) {
            InitFadeOut(0, 0x14);
            D_80106F60_16FEA0_ShockDropOrRoll = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* The shadow: smaller the higher the object is. */
void func_80105F48_16EE88_ShockDropOrRoll(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], scale, 0.0f, scale);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}
