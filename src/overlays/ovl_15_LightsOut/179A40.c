#include "ovl_15.h"

void func_8010C0B0_179A40_LightsOut(void) {
    LOSlot* p = D_8010CD90_17A720_LightsOut;
    u32 i;
    u32 j;
    u32 k;

    for (i = 0; i < 50; i++, p++) {
        p->obj = NULL;
        p->sprite = 0;
        p->unk_08 = 0.0f;
        p->unk_0C = 0.0f;
        p->unk_10 = 0.0f;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1C = 0;
        p->unk_74 = 0;
        p->unk_76 = 0;
        p->unk_78 = 0;
        p->unk_7A = 0;
        p->unk_7C = 0;
        p->unk_7E = 0;
        p->unk_80 = 0;
        p->unk_82 = 0;
        p->unk_84 = 0;
        p->unk_86 = 0;
        p->unk_88 = 0;
        p->unk_8A = 0;
        p->unk_8C = 0.0f;
        p->unk_90 = 0;
        p->unk_94 = 0;
        p->unk_98 = 0;
        p->unk_30 = 0.0f;
        for (j = 0; j < 2; j++) {
            p->mtxCount[j] = 0;
            p->mtx[j] = NULL;
        }
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                p->unk_34[0][j][k] = 0.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_8010CD00_17A690_LightsOut[i] = 0;
    }
    D_8010EC08_17C598_LightsOut = 0;
}

void func_8010C1C8_179B58_LightsOut(void) {
    s16* p = D_8010CD18_17A6A8_LightsOut;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
