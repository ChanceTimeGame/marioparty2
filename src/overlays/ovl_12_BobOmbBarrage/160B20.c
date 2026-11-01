#include "ovl_12.h"

void func_80102800_160B20_BobOmbBarrage(void) {
    func_8010281C_160B3C_BobOmbBarrage();
}

void func_8010281C_160B3C_BobOmbBarrage(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(0x14);
    omInitObjMan(0x1E, 0);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0x14);
    func_80079128_79D28();
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026DAC_279AC(3, 0, 0, 0);
    func_80026E00_27A00(1, 0.0f, 64.0f, 192.0f);
    func_80102DA0_1610C0_BobOmbBarrage();
    D_800FDEAE_FEAAE = 0;
}
