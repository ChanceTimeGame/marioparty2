#include "ovl_10.h"

void func_80109A70_153590_CraneGame(void) {
    D_8010CE08_156928_CraneGame = 0;
    D_8010CB00_156620_CraneGame = func_8002838C_28F8C(0, func_80109C00_153720_CraneGame, 2);
}

void func_80109AA8_1535C8_CraneGame(void) {
    CGColGroup* g;
    void* p;
    s32 i;
    s32 j;

    if (D_8010CE08_156928_CraneGame != 0) {
        for (i = 0; i < D_8010CE08_156928_CraneGame; i++) {
            g = D_8010CB08_156628_CraneGame[i].groups;
            for (j = 0; j < D_8010CB08_156628_CraneGame[i].count; j++) {
                p = g->faces;
                g++;
                HuMemMemoryFreePerm(p);
            }
            HuMemMemoryFreePerm(D_8010CB08_156628_CraneGame[i].groups);
            HuMemMemoryFreePerm(D_8010CB08_156628_CraneGame[i].verts);
        }
    }
    D_8010CE08_156928_CraneGame = 0;
    func_800283DC_28FDC(D_8010CB00_156620_CraneGame);
}

void func_80109BAC_1536CC_CraneGame(s16 model) {
    func_80109E48_153968_CraneGame(&D_8010CB08_156628_CraneGame[D_8010CE08_156928_CraneGame], model);
    D_8010CE08_156928_CraneGame++;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_80109C00_153720_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_80109E48_153968_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_80109FF8_153B18_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A43C_153F5C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A4D8_153FF8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A798_1542B8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010A8E8_154408_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010AD5C_15487C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010AE2C_15494C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/153590", func_8010B364_154E84_CraneGame);
