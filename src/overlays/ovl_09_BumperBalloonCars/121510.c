#include "ovl_09.h"

void func_80108400_121510_BumperBalloonCars(void) {
    BBCObj* p = D_801086E0_1217F0_BumperBalloonCars;
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
        p->stun = 0;
        p->out = 0;
        p->dust = 0;
        p->gone = 0;
        p->shadow = 0;
        p->smoke = 0;
        p->cpuWait = 0;
        p->cpuHold = 0;
        p->lift = 0;
        p->unk_82 = 0;
        p->cpuHit = 0;
        p->rumble = 0;
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

void func_801084F4_121604_BumperBalloonCars(void) {
    s16* p = D_80108658_121768_BumperBalloonCars;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}
