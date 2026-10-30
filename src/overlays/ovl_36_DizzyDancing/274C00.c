#include "ovl_36.h"

void func_80107520_274C00_DizzyDancing(void) {
    DDActor* p;
    u32 i;

    p = D_80107870_274F50_DizzyDancing;
    for (i = 0; i < 50; i++) {
        p->obj = NULL;
        p->unk_04 = 0;
        p->unk_08[0] = 0;
        p->unk_08[1] = 0;
        p->unk_08[2] = 0;
        p->unk_08[3] = 0;
        p->unk_08[4] = 0;
        p->unk_08[5] = 0;
        p->state = 0;
        p->unk_22 = 0;
        p->unk_24 = 0;
        p->unk_26 = 0;
        p->unk_28 = 0;
        p->unk_2A = 0;
        p->unk_2C = 0;
        p->unk_2E = 0;
        p->unk_30 = 0;
        p->unk_32 = 0;
        p->unk_34 = 0;
        p->unk_36 = 0;
        p->unk_38 = 0.0f;
        p->unk_3C = 0.0f;
        p->unk_40 = 0.0f;
        p->unk_44 = 0.0f;
        p++;
    }
}

void func_801075A4_274C84_DizzyDancing(void) {
    s16* p;
    u32 i;

    p = D_80108680_275D60_DizzyDancing;
    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
