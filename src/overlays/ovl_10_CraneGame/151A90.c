#include "ovl_10.h"

void func_80107F70_151A90_CraneGame(void) {
    void* p;

    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
    D_8010C904_156424_CraneGame = 0;
    D_8010C260_155D80_CraneGame = func_8002838C_28F8C(0, func_801082F4_151E14_CraneGame, 2);
    D_8010C8F8_156418_CraneGame.x = D_8010C8F8_156418_CraneGame.y = D_8010C8F8_156418_CraneGame.z = 0.0f;
    D_8010CAF0_156610_CraneGame = 1.0f;
    D_8010C908_156428_CraneGame = 0;
    p = DataRead(0x200012);
    D_8010C8E8_156408_CraneGame = SprAnimRead(p);
    DataClose(p);
    D_8010C8EC_15640C_CraneGame = **SprAnimGet(D_8010C8E8_156408_CraneGame);
}

void func_80108038_151B58_CraneGame(void) {
    s32 i;

    if (D_8010C262_155D82_CraneGame != 0) {
        for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
            HuMemFree(D_8010C4E8_156008_CraneGame[i][0]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][1]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][2]);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]->dl);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]);
        }
    }
    func_800283DC_28FDC(D_8010C260_155D80_CraneGame);
    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
}

void func_80108114_151C34_CraneGame(s16 model) {
    D_8010C268_155D88_CraneGame[D_8010C262_155D82_CraneGame] = model;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].cur = 1.0f;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].target = 1.0f;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][0] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][1] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][2] = NULL;
    D_8010C7E8_156308_CraneGame[D_8010C262_155D82_CraneGame] = NULL;
    D_8010C8F0_156410_CraneGame = D_8010C262_155D82_CraneGame;
    func_80108D18_152838_CraneGame(model);
    D_8010C262_155D82_CraneGame++;
}

void func_801081C8_151CE8_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_80108238_151D58_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].cur = D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_801082B8_151DD8_CraneGame(f32 y) {
    D_8010C908_156428_CraneGame = 1;
    D_8010C90C_15642C_CraneGame = y;
}

void func_801082D0_151DF0_CraneGame(f32 x, f32 y, f32 z) {
    D_8010C8F8_156418_CraneGame.x = x;
    D_8010C8F8_156418_CraneGame.y = y;
    D_8010C8F8_156418_CraneGame.z = z;
}

void func_801082E8_151E08_CraneGame(f32 scale) {
    D_8010CAF0_156610_CraneGame = scale;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801082F4_151E14_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_8010887C_15239C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_80108D18_152838_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_80109024_152B44_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801091D4_152CF4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801093A0_152EC0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801095A4_1530C4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801097A0_1532C0_CraneGame);
