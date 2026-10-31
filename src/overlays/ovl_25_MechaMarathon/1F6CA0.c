#include "ovl_25.h"

void func_80107F60_1F6CA0_MechaMarathon(void) {
    MMActor* a;
    u32 i;

    a = D_801085F0_1F7330_MechaMarathon;
    for (i = 0; i < 50; i++, a++) {
        a->obj = NULL;
        a->unk_04 = 0;
        a->unk_08 = 0;
        a->unk_0C = 0;
        a->unk_10 = 0;
        a->unk_14 = 0;
        a->unk_18 = 0;
        a->unk_1C = 0;
        a->state = 0;
        a->unk_22 = 0;
        a->unk_24 = 0;
        a->unk_26 = 0;
        a->unk_28 = 0;
        a->unk_2A = 0;
        a->unk_2C = 0;
        a->unk_2E = 0;
        a->unk_30 = 0;
        a->unk_32 = 0;
        a->unk_34 = 0;
        a->unk_36 = 0;
        a->unk_38 = 0.0f;
        a->unk_3C = 0.0f;
        a->unk_40 = 0.0f;
        a->unk_44 = 0.0f;
    }
}

void func_80107FE4_1F6D24_MechaMarathon(void) {
    s16* p;
    u32 i;

    p = D_80109400_1F8140_MechaMarathon;
    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
