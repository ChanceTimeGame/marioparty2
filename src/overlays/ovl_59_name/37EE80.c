#include "common.h"
#include "ovl_59.h"

/* MP3 storydebug func_801059D0 */
void func_80102830_37EEB0_name_59(void) {
    omInitObjMan(10, 10);
    func_80079128_79D28();
    func_80020070_20C70(1);
    CameraScissorSet(0, &D_80102BC0_37F240_name_59);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 120, 120, 120);
    func_80026DAC_279AC(1, 64, 64, 96);
    func_80026E00_27A00(1, -100.0f, 100.0f, 100.0f);
    omAddPrcObj(func_80102ACC_37F14C_name_59, 0xE000, 0, 0);
    omAddObj(0x4001, 0, 0, -1, func_80102BA4_37F224_name_59);
    omAddObj(0x500, 0, 0, -1, func_80102B78_37F1F8_name_59);
    InitFadeIn(0, 0);
}

/* MP3 storydebug func_80105A98 */
void func_80102918_37EF98_name_59(void) {
    s32 var_s2;
    s32 i, j;

    var_s2 = D_80102BD0_37F250_name_59;
    fontcolor = 15;

    for (i = 0; i < 16 && (i * 8) < ARRAY_COUNT(D_80102C10_37F290_name_59); i++) {
        sprintf(pfStrBuf, "%3X:", var_s2);
        DrawDebugText(40, (i * 10 + 48), pfStrBuf);
        for (j = 0; j < 8; j++) {
            sprintf(pfStrBuf, "%02X", D_80102C10_37F290_name_59[var_s2 + j]);
            DrawDebugText((j * 24 + 80), (i * 10 + 48), pfStrBuf);
        }
        var_s2 += 8;
    }
}

void func_80102A34_37F0B4_name_59(void) {
    sprintf(pfStrBuf, "P:%3X", 0x78);
    DrawDebugText(40, 16, pfStrBuf);
    sprintf(pfStrBuf, "S:%3X", 0x1C8);
    DrawDebugText(40, 24, pfStrBuf);
    sprintf(pfStrBuf, "Q:%3X", 0x1F0);
    DrawDebugText(40, 32, pfStrBuf);
}

void func_80102ACC_37F14C_name_59(void) {
    func_8001B078_1BC78(0, (UnkEep*)D_80102C10_37F290_name_59, 0x200);
    while (TRUE) {
        HuPrcVSleep();
        if (ContBtn[0] & 4) {
            D_80102BD0_37F250_name_59 += 8;
        }
        if (ContBtn[0] & 8) {
            D_80102BD0_37F250_name_59 -= 8;
            if (D_80102BD0_37F250_name_59 < 0) {
                D_80102BD0_37F250_name_59 = 0;
            }
        }
        func_80102918_37EF98_name_59();
        func_80102A34_37F0B4_name_59();
    }
}

/* MP3 storydebug func_80106108 */
void func_80102B78_37F1F8_name_59(omObjData* arg0) {
    if (D_801011FC_101DFC != 0) {
        omOvlReturnEx(1);
    }
}

void func_80102BA4_37F224_name_59(omObjData* arg0) {
}
