#include "ovl_33.h"

void func_80107C50_258ED0_DriversEd(void) {
    DEObj* p = D_80108720_2599A0_DriversEd;
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
        p->unk_70 = 0;
        p->unk_72 = 0;
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
        p->unk_88 = 0.0f;
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

void func_80107D44_258FC4_DriversEd(void) {
    s16* p = D_8010A4D0_25B750_DriversEd;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
