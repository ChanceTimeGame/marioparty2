#include "common.h"
#include "ovl_13.h"

void func_80106640_16B3E0_LookAway(void) {
    LAObj* p = D_80106CD0_16BA70_LookAway;
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
        p->state = 0;
        p->unk_22 = 0;
        p->unk_24 = 0;
        p->unk_26 = 0;
        p->timer = 0;
        p->unk_2A = 0;
        p->com = 0;
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

void func_801066C4_16B464_LookAway(void) {
    s16* p = D_80106C68_16BA08_LookAway;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
