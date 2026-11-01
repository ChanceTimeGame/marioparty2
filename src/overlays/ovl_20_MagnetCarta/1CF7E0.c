#include "ovl_20.h"

void func_8010B430_1CF7E0_MagnetCarta(void) {
    MCObj* p = D_8010BDD0_1D0180_MagnetCarta;
    u32 i;
    u32 j;
    u32 k;

    for (i = 0; i < 50; i++, p++) {
        p->obj = NULL;
        p->spr = 0;
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1C = 0;
        p->timer = 0;
        p->state = 0;
        p->dust = 0;
        p->attached = 0;
        p->target = 0;
        p->spin = 0;
        p->cpuWait = 0;
        p->unk_7E = 0;
        p->lift = 0;
        p->unk_82 = 0;
        p->hit = 0;
        p->unk_86 = 0;
        p->size = 0.0f;
        p->unk_8C = 0;
        p->unk_90 = 0;
        p->unk_94 = 0;
        p->unk_2C = 0;
        for (j = 0; j < 2; j++) {
            p->unk_20[j] = 0;
            p->unk_24[j] = 0;
        }
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                p->unk_30[j][k] = 0;
            }
        }
    }
}

void func_8010B524_1CF8D4_MagnetCarta(void) {
    s16* p = D_8010BD68_1D0118_MagnetCarta;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
