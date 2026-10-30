#include "ovl_38.h"

void func_80106780_27E2B0_QuicksandCache(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    D_800FA610_FB210 = a;
    D_800FD474_FE074.x = b;
    D_800FD474_FE074.y = c;
    D_800FD474_FE074.z = d;
    D_8010274C_10334C.x = e;
    D_8010274C_10334C.y = f;
    D_8010274C_10334C.z = g;
}

void func_801067C0_27E2F0_QuicksandCache(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_801077E0_27F310_QuicksandCache == 0) {
            InitFadeOut(0, 0x14);
            D_801077E0_27F310_QuicksandCache = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

void func_80106838_27E368_QuicksandCache(omObjData* obj) {
    f32 s = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], s, 0.0f, s);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}
