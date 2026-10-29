#include "ovl_62.h"

void func_80102830_3D4D50_TitleScreenAndIntro(void) {
    omInitObjMan(38, 4);
    func_80020D20_21920(32);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    func_80046238_46E38();
    func_80079464_7A064();
    func_80088640_89240();
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 128, 128, 128);
    func_80026DAC_279AC(1, 64, 64, 96);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026DAC_279AC(3, 0, 0, 0);
    func_80026E00_27A00(1, 0.0f, 64.0f, 192.0f);
    D_800FDEAE_FEAAE = 0;
}

/* entry 0: the title screen */
void func_80102998_3D4EB8_TitleScreenAndIntro(void) {
    D_80111D30_3E4250_TitleScreenAndIntro = 0;
    func_80102830_3D4D50_TitleScreenAndIntro();
    func_80102A38_3D4F58_TitleScreenAndIntro();
}

/* entry 1: the opening */
void func_801029C0_3D4EE0_TitleScreenAndIntro(void) {
    D_80111D30_3E4250_TitleScreenAndIntro = 1;
    func_80102830_3D4D50_TitleScreenAndIntro();
    func_80102A08_3D4F28_TitleScreenAndIntro();
}

s32 func_801029EC_3D4F0C_TitleScreenAndIntro(void) {
    return D_80111D30_3E4250_TitleScreenAndIntro;
}
