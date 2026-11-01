#include "ovl_28.h"

void func_80108130_20B4D0_PlatformPeril(u8 port) {
    ContStkX[port] = 0;
    ContStkY[port] = 0;
    ContBtn[port] = 0;
    ContBtnTrg[port] = 0;
}

void func_8010816C_20B50C_PlatformPeril(u16 difficulty, u8 player) {
    if (D_80109126_20C4C6_PlatformPeril == 0) {
        switch (difficulty) {
        case 0:
            D_801093D0_20C770_PlatformPeril[player] = 3;
            D_801093D8_20C778_PlatformPeril[player] = 0.4f;
            break;
        case 1:
            D_801093D0_20C770_PlatformPeril[player] = 8;
            D_801093D8_20C778_PlatformPeril[player] = 0.6f;
            break;
        case 2:
            D_801093D0_20C770_PlatformPeril[player] = 13;
            D_801093D8_20C778_PlatformPeril[player] = 0.8f;
            break;
        case 3:
            D_801093D0_20C770_PlatformPeril[player] = 18;
            D_801093D8_20C778_PlatformPeril[player] = 1.0f;
            break;
        }
    } else {
        D_801093D0_20C770_PlatformPeril[player] = 13;
        D_801093D8_20C778_PlatformPeril[player] = 0.8f;
    }
}

#ifdef NON_MATCHING
void func_8010826C_20B60C_PlatformPeril(omObjData* obj, f32* angle) {
    omObjData* pl;
    s32 d;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (obj->work[0] == i) {
            continue;
        }
        pl = D_800FFFD8_100BD8[i];
        d = abs((s32)(obj->trans.x - pl->trans.x));
        if ((f32)d < 40.0f && pl->trans.z < obj->trans.z && pl->trans.z - obj->trans.z < 80.0f) {
            d = abs((s32)(obj->trans.x));
            if (d < 301) {
                if (obj->trans.x < D_800FFFD8_100BD8[i]->trans.x) {
                    *angle -= (f32)(PP_RAND() % 6) + 15.0f;
                } else {
                    *angle = (f32)(PP_RAND() % 6) + 15.0f + *angle;
                }
            } else if (obj->trans.x < pl->trans.x) {
                *angle = (f32)(PP_RAND() % 6) + 15.0f + *angle;
            } else {
                *angle -= (f32)(PP_RAND() % 6) + 15.0f;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/20B4D0", func_8010826C_20B60C_PlatformPeril);
#endif

void func_801084FC_20B89C_PlatformPeril(omObjData* obj) {
    omObjData* a;
    s32 d;
    f32 dz;
    u8 i;

    for (i = 0; i < D_800FA606_FB206; i++) {
        a = D_800F9CE0_FA8E0[i];
        if (a->work[0] == 1 && ((ColActorWork*)a->unk_50)->unk_54 == a->work[0]) {
            if (PP_RAND() % 3 == 0) {
                dz = obj->trans.z - a->trans.z;
                if (dz < 200.0f && D_801093D8_20C778_PlatformPeril[obj->work[0]] * 100.0f < dz) {
                    d = abs((s32)(obj->trans.x - a->trans.x));
                    if (d < 50.0) {
                        obj->work[1] = 4;
                    }
                }
            }
        }
    }
}

#ifdef NON_MATCHING
void func_801086A8_20BA48_PlatformPeril(omObjData* obj, f32* angle) {
    f32 z;
    f32 x;
    s32 d;
    u8 i;

    for (i = 0; i < 6; i++) {
        z = -(D_801091D4_20C574_PlatformPeril[i] * 100);
        if (z < obj->trans.z && obj->trans.z - 600.0f < z) {
            x = D_801091D0_20C570_PlatformPeril[i] * 100;
            d = abs((s32)(obj->trans.x - x));
            if (d < 100) {
                d = abs((s32)(obj->trans.x));
                if (d < 301) {
                    if ((f32)(D_801091D0_20C570_PlatformPeril[i] * 100) < obj->trans.x) {
                        *angle = (f32)(PP_RAND() % (D_801093D0_20C770_PlatformPeril[obj->work[0]] + 6)) + 55.0f;
                    } else {
                        *angle = 35.0f - (f32)(PP_RAND() % (D_801093D0_20C770_PlatformPeril[obj->work[0]] + 6));
                    }
                } else if (x < obj->trans.x) {
                    *angle = 35.0f - (f32)(PP_RAND() % (D_801093D0_20C770_PlatformPeril[obj->work[0]] + 6));
                } else {
                    *angle = (f32)(PP_RAND() % (D_801093D0_20C770_PlatformPeril[obj->work[0]] + 6)) + 55.0f;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/20B4D0", func_801086A8_20BA48_PlatformPeril);
#endif

#ifdef NON_MATCHING
void func_801089AC_20BD4C_PlatformPeril(omObjData* obj, f32* angle) {
    f32 c;

    switch (D_80109550_20C8F0_PlatformPeril[obj->work[0]].kind) {
    case 2:
        if (D_80109550_20C8F0_PlatformPeril[obj->work[0]].obj->trans.x + 171.42857f < obj->trans.x) {
            *angle = 35.0f - (f32)(PP_RAND() % 11);
        } else if (obj->trans.x < D_80109550_20C8F0_PlatformPeril[obj->work[0]].obj->trans.x - 171.42857f) {
            *angle = (f32)(PP_RAND() % 11) + 55.0f;
        }
        break;
    case 3:
        c = 250.0f;
        if (obj->trans.x < 0.0f) {
            c = -250.0f;
        }
        if (c + 100.0f < obj->trans.x) {
            *angle = 25.0f - (f32)(PP_RAND() % 11);
        } else if (obj->trans.x < c - 100.0f) {
            *angle = (f32)(PP_RAND() % 11) + 65.0f;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/20B4D0", func_801089AC_20BD4C_PlatformPeril);
#endif

#ifdef NON_MATCHING
void func_80108CB0_20C050_PlatformPeril(omObjData* obj, MgWork* w) {
    f32 d;

    switch (obj->work[1]) {
    case 2:
        if (w->unk_53 != -1) {
            d = obj->trans.z - (D_801093F0_20C790_PlatformPeril[w->unk_53].z - D_801093F0_20C790_PlatformPeril[w->unk_53].depth);
            if (d < (f32)(PP_RAND() % 6 + 6) / 10.0f * 100.0f) {
                obj->work[1] = 3;
                obj->work[2] = 0;
            }
            func_801084FC_20B89C_PlatformPeril(obj);
        }
        break;
    case 3:
        obj->work[2]++;
        if (obj->work[2] >= 10) {
            obj->work[2] = 0;
            obj->work[1] = 2;
        } else {
            ContBtn[w->unk_57] |= 0x8000;
            ContBtnTrg[w->unk_57] |= 0x8000;
        }
        break;
    case 4:
        obj->work[2]++;
        if (obj->work[2] >= 2) {
            obj->work[2] = 0;
            obj->work[1] = 2;
        } else {
            ContBtn[w->unk_57] |= 0x8000;
            ContBtnTrg[w->unk_57] |= 0x8000;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/20B4D0", func_80108CB0_20C050_PlatformPeril);
#endif

#ifdef NON_MATCHING
void func_80108E78_20C218_PlatformPeril(omObjData* obj) {
    MgWork* w = obj->unk_50;
    f32 angle = 45.0f;
    s32 r;

    if (obj->work[1] != 6) {
        func_80108130_20B4D0_PlatformPeril(w->unk_57);
        func_801089AC_20BD4C_PlatformPeril(obj, &angle);
        func_801086A8_20BA48_PlatformPeril(obj, &angle);
        func_8010826C_20B60C_PlatformPeril(obj, &angle);
        r = PP_RAND();
        ContStkX[w->unk_57] = (f32)(r % 11 + 50 + D_801093D0_20C770_PlatformPeril[obj->work[0]]) * HuMathSin(angle);
        r = PP_RAND();
        ContStkY[w->unk_57] = (f32)(r % 11 + 50 + D_801093D0_20C770_PlatformPeril[obj->work[0]]) * func_800B7890_B8490(angle);
        func_80108CB0_20C050_PlatformPeril(obj, w);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/20B4D0", func_80108E78_20C218_PlatformPeril);
#endif
