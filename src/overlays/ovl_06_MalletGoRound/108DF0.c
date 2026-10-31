#include "common.h"
#include "ovl_06.h"

__asm__(".section .rodata");
const u32 D_801085B0_10BD70_MalletGoRound[11] = { 0x00140008, 0x00140009, 0x0014000A, 0x0014000C, 0x0014000D, 0x0014000E, 0x0014000F, 0x00140010, 0x00140011, 0x00140012, 0x00140013 };

__asm__(".section .rodata");
const f32 D_801085DC_10BD9C_MalletGoRound[2][6] = {
    { 0.0f, 60.0f, 120.0f, 180.0f, 240.0f, 300.0f },
    { 0.0f, 60.0f, 120.0f, 180.0f, 240.0f, 300.0f },
};

#ifdef NON_MATCHING
/* FP register allocation in the stop-angle test: retail keeps the wrap in $f0 and full in $f6. */
/* The wheel's main: spins the six posts, stops them on a hit. */
void func_80105630_108DF0_MalletGoRound(omObjData* obj) {
    f32 target = 0.0f;
    f32 angle = D_801084B0_10BC70_MalletGoRound;
    f32 a, x, z;
    f32 limit;
    f32 wrap, full, cur, val;
    s8 i;

    for (i = 0; i < 6; i++) {
        a = 220.0f;
        a = angle + a;
        x = func_800B7890_B8490(a) * 210.0f - HuMathSin(a) * 210.0f;
        z = HuMathSin(a) * 210.0f + func_800B7890_B8490(a) * 210.0f;
        D_801086D0_10BE90_MalletGoRound[i].yBase -= 18.0f;
        if (i != 0) {
            switch (D_801086D0_10BE90_MalletGoRound[i].hits) {
            case 0:
                target = -200.0f;
                break;
            case 1:
                target = -100.0f;
                break;
            case 2:
                target = 0.0f;
                break;
            }
        } else {
            switch (D_801086D0_10BE90_MalletGoRound[i].hits) {
            case 0:
                target = -100.0f;
                break;
            case 1:
            case 2:
                target = 0.0f;
                break;
            }
        }
        if (D_801086D0_10BE90_MalletGoRound[i].yBase <= target) {
            D_801086D0_10BE90_MalletGoRound[i].yBase = target;
        }
        func_80029714_2A314(obj->model[i + 1], x + D_801084C0_10BC80_MalletGoRound, D_801086D0_10BE90_MalletGoRound[i].yBase, z + D_801084C4_10BC84_MalletGoRound);
        func_80029714_2A314(obj->model[i + 7], x + D_801084C0_10BC80_MalletGoRound, D_801086D0_10BE90_MalletGoRound[i].yBase, z + D_801084C4_10BC84_MalletGoRound);
        func_8002979C_2A39C(obj->model[i + 1], 0.0f, -angle, 0.0f);
        func_8002979C_2A39C(obj->model[i + 7], 0.0f, -angle, 0.0f);
        angle -= 60.0f;
        if (angle < 0.0f) {
            angle += 360.0f;
        }
    }
    if ((u8)(D_80108454_10BC14_MalletGoRound - 5) < 4) {
        if (D_801084B5_10BC75_MalletGoRound == 0) {
            if (D_801084B4_10BC74_MalletGoRound == 0) {
                if (D_80108457_10BC17_MalletGoRound == 0) {
                    limit = 360.0f / (D_801084CC_10BC8C_MalletGoRound / 2.0f);
                    D_801084C8_10BC88_MalletGoRound += limit / 30.0f;
                    if (limit <= D_801084C8_10BC88_MalletGoRound) {
                        D_801084C8_10BC88_MalletGoRound = limit;
                    }
                    angle += D_801084C8_10BC88_MalletGoRound;
                    if (angle >= 360.0f) {
                        angle -= 360.0f;
                    }
                } else {
                    limit = D_801084CC_10BC8C_MalletGoRound;
                    limit /= 2.0f;
                    D_801084C8_10BC88_MalletGoRound -= (360.0f / limit) / 30.0f;
                    if (D_801084C8_10BC88_MalletGoRound <= -360.0f / limit) {
                        D_801084C8_10BC88_MalletGoRound = -360.0f / limit;
                    }
                    angle += D_801084C8_10BC88_MalletGoRound;
                    if (angle < 0.0f) {
                        angle += 360.0f;
                    }
                }
            } else {
                if ((s16)D_801084BE_10BC7E_MalletGoRound++ > 30.0f) {
                    if (D_80108450_10BC10_MalletGoRound != 1) {
                        D_801084B4_10BC74_MalletGoRound = 0;
                    }
                    D_80108456_10BC16_MalletGoRound = 0;
                    D_801084CC_10BC8C_MalletGoRound = 54.0f;
                    D_801084BE_10BC7E_MalletGoRound = 0;
                }
            }
        }
        if (D_80108456_10BC16_MalletGoRound == 1 && D_801084B4_10BC74_MalletGoRound == 0) {
            if (D_80108457_10BC17_MalletGoRound == 0) {
                if (D_801085DC_10BD9C_MalletGoRound[D_80108457_10BC17_MalletGoRound][D_801087A4_10BF64_MalletGoRound] == 0.0f) {
                    wrap = 0.0f;
                    if (angle > 300.0f) {
                        wrap = 360.0f;
                    }
                } else {
                    wrap = 0.0f;
                }
                val = D_801085DC_10BD9C_MalletGoRound[D_80108457_10BC17_MalletGoRound][D_801087A4_10BF64_MalletGoRound];
                if (wrap + val < angle) {
                    angle = val;
                    D_801084C8_10BC88_MalletGoRound = 0.0f;
                    D_80108457_10BC17_MalletGoRound = 1;
                    D_801084B4_10BC74_MalletGoRound = 1;
                    if (D_80108455_10BC15_MalletGoRound != -1) {
                        D_801084B5_10BC75_MalletGoRound = 1;
                    }
                }
            } else {
                if (D_801085DC_10BD9C_MalletGoRound[D_80108457_10BC17_MalletGoRound][D_801087A4_10BF64_MalletGoRound] == 0.0f) {
                    wrap = 0.0f;
                    if (angle < 60.0f) {
                        wrap = 360.0f;
                    }
                    full = 360.0f;
                    cur = angle + wrap;
                } else {
                    wrap = full = 0.0f;
                    cur = angle + wrap;
                }
                limit = D_801085DC_10BD9C_MalletGoRound[D_80108457_10BC17_MalletGoRound][D_801087A4_10BF64_MalletGoRound];
                if (cur < full + limit) {
                    angle = limit;
                    D_801084C8_10BC88_MalletGoRound = 0.0f;
                    D_80108457_10BC17_MalletGoRound = 0;
                    D_801084B4_10BC74_MalletGoRound = 1;
                    if (D_80108455_10BC15_MalletGoRound != -1) {
                        D_801084B5_10BC75_MalletGoRound = 1;
                    }
                }
            }
        }
        D_801084B0_10BC70_MalletGoRound = angle;
    } else if (D_80108454_10BC14_MalletGoRound >= 6 && D_801084B5_10BC75_MalletGoRound == 0 && D_801084B4_10BC74_MalletGoRound == 0) {
        if (D_80108453_10BC13_MalletGoRound == 0) {
            if (D_80108457_10BC17_MalletGoRound == 0) {
                D_801084C8_10BC88_MalletGoRound -= (360.0f / (D_801084CC_10BC8C_MalletGoRound / 2.0f)) / 30.0f;
                if (D_801084C8_10BC88_MalletGoRound <= 0.0f) {
                    D_801084C8_10BC88_MalletGoRound = 0.0f;
                }
                angle += D_801084C8_10BC88_MalletGoRound;
                if (angle >= 360.0f) {
                    angle -= 360.0f;
                }
                D_801084B0_10BC70_MalletGoRound = angle;
            }
        } else {
            D_801084C8_10BC88_MalletGoRound += (360.0f / (D_801084CC_10BC8C_MalletGoRound / 2.0f)) / 30.0f;
            if (D_801084C8_10BC88_MalletGoRound >= 0.0f) {
                D_801084C8_10BC88_MalletGoRound = 0.0f;
            }
            angle += D_801084C8_10BC88_MalletGoRound;
            if (angle < 0.0f) {
                angle += 360.0f;
            }
            D_801084B0_10BC70_MalletGoRound = angle;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80105630_108DF0_MalletGoRound);
#endif

void func_80105EEC_1096AC_MalletGoRound(omObjData* obj) {
    s8 i;
    f32 angle;
    f32 a, x, z;

    obj->model[0] = -1;
    obj->model[1] = LoadFormFile(0x160001, 0x2B9);
    for (i = 1; i < 6; i++) {
        obj->model[i + 1] = func_80027D3C_2893C(obj->model[1]);
    }
    obj->model[7] = LoadFormFile(0x160002, 0x2B9);
    for (i = 1; i < 6; i++) {
        obj->model[i + 7] = func_80027D3C_2893C(obj->model[7]);
    }
    obj->model[13] = LoadFormFile(0x160004, 0x2A9);
    obj->model[14] = LoadFormFile(0x160005, 0x2A9);
    HmfModelObjAttrSet(obj->model[13], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[13]);
    HmfModelObjAttrSet(obj->model[14], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[14]);
    func_800298A4_2A4A4(obj->model[13], 4, 4);
    func_800298A4_2A4A4(obj->model[14], 4, 4);
    for (i = 1; i < 15; i++) {
        func_800297E8_2A3E8(obj->model[i], 1.9f, 1.9f, 1.9f);
    }
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    angle = D_801084B0_10BC70_MalletGoRound;
    func_800298A4_2A4A4(obj->model[7], 4, 4);
    for (i = 0; i < 6; i++) {
        a = angle + 220.0f;
        x = func_800B7890_B8490(a) * 210.0f - HuMathSin(a) * 210.0f;
        z = HuMathSin(a) * 210.0f + func_800B7890_B8490(a) * 210.0f;
        func_80029714_2A314(obj->model[i + 1], x, 0.0f, z);
        func_80029714_2A314(obj->model[i + 7], x, 0.0f, z);
        func_8002979C_2A39C(obj->model[i + 1], 0.0f, -angle, 0.0f);
        func_8002979C_2A39C(obj->model[i + 7], 0.0f, -angle, 0.0f);
        angle -= 60.0f;
        if (angle < 0.0f) {
            angle += 360.0f;
        }
    }
    D_801086D0_10BE90_MalletGoRound[0].hits = 1;
    for (i = 1; i < 6; i++) {
        D_801086D0_10BE90_MalletGoRound[i].hits = 2;
    }
    for (i = 0; i < 6; i++) {
        D_801086D0_10BE90_MalletGoRound[i].falling = 0;
        D_801086D0_10BE90_MalletGoRound[i].timer = 0;
        D_801086D0_10BE90_MalletGoRound[i].yBase = 0.0f;
    }
    obj->func_ptr = func_80105630_108DF0_MalletGoRound;
}

/* After a win: the slots stay on their pedestals (the i == 0 tests are dead, retail's loop starts
   at 1) and slot 0 hops off towards (800, 150, -500). */
void func_801062EC_109AAC_MalletGoRound(omObjData* obj) {
    f32 target = 0.0f;
    f32 angle;
    f32 a, x, z;
    f32 t;
    s8 i;

    if (D_801084D0_10BC90_MalletGoRound == 0) {
        D_80108690_10BE50_MalletGoRound.x = D_800FC834_FD434[obj->model[1]].pos.x;
        D_80108690_10BE50_MalletGoRound.y = D_800FC834_FD434[obj->model[1]].pos.y;
        D_80108690_10BE50_MalletGoRound.z = D_800FC834_FD434[obj->model[1]].pos.z;
        D_8010869C_10BE5C_MalletGoRound.x = (800.0f - D_80108690_10BE50_MalletGoRound.x) / 60.0f;
        D_8010869C_10BE5C_MalletGoRound.y = (150.0f - D_80108690_10BE50_MalletGoRound.y) / 60.0f;
        D_8010869C_10BE5C_MalletGoRound.z = (-500.0f - D_80108690_10BE50_MalletGoRound.z) / 60.0f;
        D_801084D0_10BC90_MalletGoRound = 1;
    }
    angle = D_801084B0_10BC70_MalletGoRound;
    angle -= 60.0f;
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    for (i = 1; i < 6; i++) {
        D_801086D0_10BE90_MalletGoRound[i].y -= 18.0f;
        switch (D_801086D0_10BE90_MalletGoRound[i].hits) {
        case 0:
            target = 100.0f;
            break;
        case 1:
            target = 200.0f;
            break;
        case 2:
            target = 300.0f;
            break;
        }
        if (D_801086D0_10BE90_MalletGoRound[i].y <= target) {
            D_801086D0_10BE90_MalletGoRound[i].y = target;
        }
        a = angle + 220.0f;
        x = func_800B7890_B8490(a) * 210.0f - HuMathSin(a) * 210.0f;
        z = HuMathSin(a) * 210.0f + func_800B7890_B8490(a) * 210.0f;
        func_80029714_2A314(obj->model[i + 1], x + D_801084D4_10BC94_MalletGoRound,
                            D_801086D0_10BE90_MalletGoRound[i].y + D_801086D0_10BE90_MalletGoRound[i].lift + D_801086D0_10BE90_MalletGoRound[i].unk_18 + D_801086D0_10BE90_MalletGoRound[i].bob,
                            z + D_801084D8_10BC98_MalletGoRound + D_801086D0_10BE90_MalletGoRound[i].z);
        if (i == 0) {
            func_8002979C_2A39C(obj->model[1], 0.0f, -angle + 180.0f, 0.0f);
        }
        if (D_801086D0_10BE90_MalletGoRound[i].y + D_801086D0_10BE90_MalletGoRound[i].lift + D_801086D0_10BE90_MalletGoRound[i].unk_18 - target > 150.0f) {
            func_800298A4_2A4A4(obj->model[i + 7], 4, 4);
        } else {
            t = D_801086D0_10BE90_MalletGoRound[i].y + D_801086D0_10BE90_MalletGoRound[i].lift + D_801086D0_10BE90_MalletGoRound[i].unk_18 - target;
            if (t < 0.0f) {
                t = 0.0f;
            }
            t = (150.0f - t) / 150.0f;
            if (i == 0) {
                t *= 1.5f;
            }
            func_800297E8_2A3E8(obj->model[i + 7], t, t, t);
            func_800298A4_2A4A4(obj->model[i + 7], 4, 0);
            if (i != 0) {
                if (D_801086D0_10BE90_MalletGoRound[i].hits > 0) {
                    func_80029714_2A314(obj->model[i + 7], x + D_801084D4_10BC94_MalletGoRound, D_801086D0_10BE90_MalletGoRound[i].y + D_801086D0_10BE90_MalletGoRound[i].unk_18 + -75.0f, z + D_801084D8_10BC98_MalletGoRound + D_801086D0_10BE90_MalletGoRound[i].z);
                } else if (D_801086D0_10BE90_MalletGoRound[i].falling == 1) {
                    func_80029714_2A314(obj->model[i + 7], x + D_801084D4_10BC94_MalletGoRound, target + -75.0f, z + D_801084D8_10BC98_MalletGoRound + D_801086D0_10BE90_MalletGoRound[i].z);
                } else {
                    func_80029714_2A314(obj->model[i + 7], x + D_801084D4_10BC94_MalletGoRound, D_801086D0_10BE90_MalletGoRound[i].y + D_801086D0_10BE90_MalletGoRound[i].unk_18 + -75.0f, z + D_801084D8_10BC98_MalletGoRound + D_801086D0_10BE90_MalletGoRound[i].z);
                }
            } else {
                func_80029714_2A314(obj->model[i + 7], x + D_801084D4_10BC94_MalletGoRound, target + -75.0f, z + D_801084D8_10BC98_MalletGoRound + D_801086D0_10BE90_MalletGoRound[i].z);
            }
        }
        angle -= 60.0f;
        if (angle < 0.0f) {
            angle += 360.0f;
        }
    }
    if (D_801084EC_10BCAC_MalletGoRound == 0) {
        if (D_801084E0_10BCA0_MalletGoRound > 30) {
            if (D_801084D1_10BC91_MalletGoRound == 0) {
                func_80029B80_2A780(obj->model[1], obj->motion[1]);
                D_801084D1_10BC91_MalletGoRound = 1;
            }
            if (D_801084DC_10BC9C_MalletGoRound < 60) {
                for (i = 0; i < 3; i++) {
                    ((f32*)&D_80108690_10BE50_MalletGoRound)[i] += ((f32*)&D_8010869C_10BE5C_MalletGoRound)[i];
                }
                D_801084E4_10BCA4_MalletGoRound += D_801084E8_10BCA8_MalletGoRound;
                D_801084E8_10BCA8_MalletGoRound -= 3.0f;
                if (D_801084E4_10BCA4_MalletGoRound < 0.0f) {
                    D_801084E4_10BCA4_MalletGoRound = 0.0f;
                    D_801084E8_10BCA8_MalletGoRound *= -1.2f;
                    func_80029B80_2A780(obj->model[1], obj->motion[1]);
                }
                D_801084DC_10BC9C_MalletGoRound++;
            } else {
                D_801084EC_10BCAC_MalletGoRound = 1;
            }
            func_80029714_2A314(obj->model[1], D_80108690_10BE50_MalletGoRound.x, D_80108690_10BE50_MalletGoRound.y + D_801084E4_10BCA4_MalletGoRound, D_80108690_10BE50_MalletGoRound.z);
            t = D_801084E4_10BCA4_MalletGoRound;
            if (t > 150.0f) {
                func_800298A4_2A4A4(obj->model[7], 4, 4);
            } else {
                if (t < 0.0f) {
                    t = 0.0f;
                }
                t = (150.0f - t) / 150.0f * 1.5f;
                func_800297E8_2A3E8(obj->model[7], t, t, t);
                func_80029714_2A314(obj->model[7], D_80108690_10BE50_MalletGoRound.x, D_80108690_10BE50_MalletGoRound.y, D_80108690_10BE50_MalletGoRound.z);
                func_800298A4_2A4A4(obj->model[7], 4, 0);
            }
            D_800FC834_FD434[obj->model[1]].rot.y = func_800B75A8_B81A8(D_8010869C_10BE5C_MalletGoRound.x, -D_8010869C_10BE5C_MalletGoRound.y);
        } else {
            D_801084E0_10BCA0_MalletGoRound++;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80106C7C_10A43C_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_801079EC_10B1AC_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80107F50_10B710_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_801082A8_10BA68_MalletGoRound);

void func_801083D8_10BB98_MalletGoRound(void) {
    D_801086B4_10BE74_MalletGoRound = 0;
    D_801084B8_10BC78_MalletGoRound = 0;
    D_801084BC_10BC7C_MalletGoRound = 1;
}

void func_801083F8_10BBB8_MalletGoRound(void) {
    D_801084BC_10BC7C_MalletGoRound = 0;
}

void func_80108404_10BBC4_MalletGoRound(s16 model, s16 arg1) {
    HmfModel* m = &D_800FC834_FD434[model];

    m->hmf->unk9C->unk08 = arg1;
}
