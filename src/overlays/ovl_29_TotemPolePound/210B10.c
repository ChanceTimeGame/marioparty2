#include "common.h"
#include "ovl_29.h"

void func_80106BC0_210B10_TotemPolePound(void) {
    TPPObj* p = D_801072F0_211240_TotemPolePound;
    u32 i;

    for (i = 0; i < 50; i++, p++) {
        p->obj = NULL;
        p->spr = 0;
        p->unk_08 = 0;
        p->unk_0C = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1C = 0;
        p->unk_20 = 0;
        p->unk_22 = 0;
        p->unk_24 = 0;
        p->unk_26 = 0;
        p->unk_28 = 0;
        p->unk_2A = 0;
        p->unk_2C = 0;
        p->player = 0;
        p->unk_30 = 0;
        p->unk_32 = 0;
        p->unk_34 = 0;
        p->unk_36 = 0;
        p->unk_38 = 0.0f;
        p->unk_3C = 0.0f;
        p->unk_40 = 0.0f;
        p->unk_44 = 0.0f;
    }
}

void func_80106C44_210B94_TotemPolePound(void) {
    s16* p = D_80107260_2111B0_TotemPolePound;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
