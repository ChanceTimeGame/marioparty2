#include "ovl_37.h"

void func_80107890_279FC0_TileDriver(void) {
    TDObj* p = D_80107CF0_27A420_TileDriver;
    u32 i;

    for (i = 0; i < 100; i++, p++) {
        p->obj = NULL;
        p->spr = 0;
        p->unk_08 = 0;
        p->unk_0C = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1C = 0;
        p->punched = 0;
        p->posed = 0;
        p->chance = 0;
        p->jump = 0;
        p->miss = 0;
        p->walking = 0;
        p->unk_2C = 0;
        p->unk_2E = 0;
        p->stickX = 0;
        p->stickY = 0;
        p->speed = 0;
        p->unk_36 = 0;
        p->unk_38 = 0.0f;
        p->unk_3C = 0.0f;
        p->unk_40 = 0.0f;
        p->unk_44 = 0.0f;
    }
}

void func_80107914_27A044_TileDriver(void) {
    s16* p = D_80107C80_27A3B0_TileDriver;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
