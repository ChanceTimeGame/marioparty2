#include "ovl_32.h"

void func_80106010_251680_SneakNSnore(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 0xA, 0, -1, func_801060F0_251760_SneakNSnore);
    omSetStatBit(D_800FC7B0_FD3B0[0], 0xA0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 1, 0, -1, func_80106570_251BE0_SneakNSnore);
    omAddObj(1, 8, 0, -1, func_80106628_251C98_SneakNSnore);
}

void func_801060F0_251760_SneakNSnore(omObjData* obj) {
    GroundWork* g;

    g = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_08 = 0.5f;
    g->unk_04 = 0;
    g->unk_0C = 10.0f;
    func_8000BEF8_CAF8(obj, 2, 0.0f);
    obj->func_ptr = func_80106418_251A88_SneakNSnore;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->model[0] = func_80018A30_19630(0x42000C, 0x219);
    obj->model[9] = func_80018A30_19630(0x42000D, 0x699);
    func_80029714_2A314(obj->model[9], 0.0f, 0.0f, 0.0f);
    obj->model[1] = func_80018A30_19630(0x420011, 0x899);
    obj->model[2] = func_80018A30_19630(0x420011, 0x899);
    obj->model[3] = func_80018A30_19630(0x420011, 0x899);
    obj->model[4] = func_80018A30_19630(0x420011, 0x899);
    obj->model[5] = func_80018A30_19630(0x420012, 0x899);
    obj->model[6] = func_80018A30_19630(0x420012, 0x899);
    obj->model[7] = func_80018A30_19630(0x420012, 0x899);
    obj->model[8] = func_80018A30_19630(0x420012, 0x899);
    func_80029714_2A314(obj->model[1], -225.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[2], -75.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[3], 75.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[4], 225.0f, 0.0f, 260.0f);
    func_800297E8_2A3E8(obj->model[1], 1.0f, 0.3f, 1.0f);
    func_800297E8_2A3E8(obj->model[2], 1.0f, 0.3f, 1.0f);
    func_800297E8_2A3E8(obj->model[3], 1.0f, 0.3f, 1.0f);
    func_800297E8_2A3E8(obj->model[4], 1.0f, 0.3f, 1.0f);
    func_80029E80_2AA80(obj->model[1], 1, 1);
    func_80029E80_2AA80(obj->model[2], 1, 1);
    func_80029E80_2AA80(obj->model[3], 1, 1);
    func_80029E80_2AA80(obj->model[4], 1, 1);
    func_80029714_2A314(obj->model[5], -225.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[6], -75.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[7], 75.0f, 0.0f, 260.0f);
    func_80029714_2A314(obj->model[8], 225.0f, 0.0f, 260.0f);
}

void func_80106418_251A88_SneakNSnore(omObjData* obj) {
    s32 i;
    s32 j;

    for (i = 0, j = 1; i < 4; i++, j++) {
        if (D_801082F0_253960_SneakNSnore[i] == 1) {
            D_801082F4_253964_SneakNSnore += 0.05f;
            if (D_801082F4_253964_SneakNSnore > 1.0f) {
                D_801082F4_253964_SneakNSnore = 1.0f;
                func_80029E80_2AA80(obj->model[j], 1, 2);
            }
            func_800297E8_2A3E8(obj->model[j], 1.0f, D_801082F4_253964_SneakNSnore, 1.0f);
        } else {
            func_800297E8_2A3E8(obj->model[j], 1.0f, 0.3f, 1.0f);
            func_80029E80_2AA80(obj->model[j], 1, 1);
            func_80029C74_2A874(obj->model[j], 0.0f);
        }
    }
}

void func_80106570_251BE0_SneakNSnore(omObjData* obj) {
    GroundWork* g;

    g = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = 1;
    g->unk_08 = 0.5f;
    g->unk_0C = 10.0f;
    obj->model[0] = -1;
    obj->func_ptr = NULL;
    func_8000BF24_CB24(obj, 0.0f, -350.0f, -500.0f, 350.0f, 350.0f);
    func_8000BFF0_CBF0(obj);
}

void func_80106628_251C98_SneakNSnore(omObjData* obj) {
    obj->func_ptr = func_80106868_251ED8_SneakNSnore;
    obj->model[0] = func_80018A30_19630(0x42000E, 0xA99);
    obj->model[1] = func_80018A30_19630(0x42000E, 0xA99);
    obj->model[2] = func_80018A30_19630(0x42000E, 0xA99);
    obj->model[3] = func_80018A30_19630(0x42000E, 0xA99);
    obj->trans.x = -220.0f;
    obj->trans.y = 200.0f;
    obj->trans.z = -510.0f;
    func_80029714_2A314(obj->model[1], -70.0f, 200.0f, -510.0f);
    func_80029714_2A314(obj->model[2], 70.0f, 200.0f, -510.0f);
    func_80029714_2A314(obj->model[3], 220.0f, 200.0f, -510.0f);
    obj->model[4] = func_80018A30_19630(0x42000F, 0xAD9);
    obj->model[5] = func_80018A30_19630(0x42000F, 0xAD9);
    obj->model[6] = func_80018A30_19630(0x42000F, 0xAD9);
    obj->model[7] = func_80018A30_19630(0x42000F, 0xAD9);
    func_80029714_2A314(obj->model[4], -230.0f, 0.0f, -490.0f);
    func_80029714_2A314(obj->model[5], -75.0f, 0.0f, -490.0f);
    func_80029714_2A314(obj->model[6], 75.0f, 0.0f, -490.0f);
    func_80029714_2A314(obj->model[7], 230.0f, 0.0f, -490.0f);
    func_800297E8_2A3E8(obj->model[4], 1.0f, 1.0f, 1.0f);
    func_800297E8_2A3E8(obj->model[5], 1.0f, 1.0f, 1.0f);
    func_800297E8_2A3E8(obj->model[6], 1.0f, 1.0f, 1.0f);
    func_800297E8_2A3E8(obj->model[7], 1.0f, 1.0f, 1.0f);
}

void func_80106868_251ED8_SneakNSnore(omObjData* obj) {
    s32 i;

    if (D_800F8FD0_F9BD0 == 0) {
        D_80108328_253998_SneakNSnore++;
        if (D_80108328_253998_SneakNSnore >= 21) {
            for (i = 0; i < 4; i++) {
                D_801082F8_253968_SneakNSnore[i] -= 10.0f;
                if (D_801082F8_253968_SneakNSnore[i] < 0.0f) {
                    D_801082F8_253968_SneakNSnore[i] = 0.0f;
                }
            }
            obj->trans.y = D_801082F8_253968_SneakNSnore[0];
            func_80029714_2A314(obj->model[1], -70.0f, D_801082F8_253968_SneakNSnore[1], -510.0f);
            func_80029714_2A314(obj->model[2], 70.0f, D_801082F8_253968_SneakNSnore[2], -510.0f);
            func_80029714_2A314(obj->model[3], 220.0f, D_801082F8_253968_SneakNSnore[3], -510.0f);
            if (obj->trans.y == 0.0f && D_80108330_2539A0_SneakNSnore[0] == 0) {
                PlaySound(0x2BC);
                D_80108330_2539A0_SneakNSnore[0] = D_80108330_2539A0_SneakNSnore[1] = D_80108330_2539A0_SneakNSnore[2] = D_80108330_2539A0_SneakNSnore[3] = 1;
                PlayMusic(0x26);
            }
            if (D_80108328_253998_SneakNSnore >= 26) {
                for (i = 0; i < 4; i++) {
                    D_80108308_253978_SneakNSnore[i] -= 0.06f;
                    if (D_80108308_253978_SneakNSnore[i] < 0.0f) {
                        D_80108308_253978_SneakNSnore[i] = 0.0f;
                    }
                    D_80108318_253988_SneakNSnore[i] -= 0.06f;
                    if (D_80108318_253988_SneakNSnore[i] < 0.0f) {
                        D_80108318_253988_SneakNSnore[i] = 0.0f;
                    }
                }
                func_800297E8_2A3E8(obj->model[4], 1.0f, D_80108308_253978_SneakNSnore[0], D_80108318_253988_SneakNSnore[0]);
                func_800297E8_2A3E8(obj->model[5], 1.0f, D_80108308_253978_SneakNSnore[1], D_80108318_253988_SneakNSnore[1]);
                func_800297E8_2A3E8(obj->model[6], 1.0f, D_80108308_253978_SneakNSnore[2], D_80108318_253988_SneakNSnore[2]);
                func_800297E8_2A3E8(obj->model[7], 1.0f, D_80108308_253978_SneakNSnore[3], D_80108318_253988_SneakNSnore[3]);
            }
            for (i = 0; i < 4; i++) {
                if (D_80108308_253978_SneakNSnore[i] == 0.0f && D_80108318_253988_SneakNSnore[i] == 0.0f) {
                    D_801082F0_253960_SneakNSnore[i] = 1;
                }
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (D_801082F0_253960_SneakNSnore[i] == 2) {
                D_801082F8_253968_SneakNSnore[i] += 10.0f;
                if (D_801082F8_253968_SneakNSnore[i] > 200.0f) {
                    D_801082F8_253968_SneakNSnore[i] = 200.0f;
                    if (D_80108330_2539A0_SneakNSnore[i] == 1) {
                        PlaySound(0x2BC);
                        D_80108330_2539A0_SneakNSnore[i] = 2;
                    }
                }
                D_80108308_253978_SneakNSnore[i] += 0.07f;
                if (D_80108308_253978_SneakNSnore[i] > 1.0f) {
                    D_80108308_253978_SneakNSnore[i] = 1.0f;
                }
                if (D_800F8FD0_F9BD0 == 1) {
                    D_80108318_253988_SneakNSnore[i] += 0.07f;
                    if (D_80108318_253988_SneakNSnore[i] > 1.0f) {
                        D_80108318_253988_SneakNSnore[i] = 1.0f;
                    }
                } else {
                    if ((D_800FFFD8_100BD8[0]->work[0] & 1) || (D_800FFFD8_100BD8[1]->work[0] & 1) || (D_800FFFD8_100BD8[2]->work[0] & 1)
                        || (D_800FFFD8_100BD8[3]->work[0] & 1)) {
                        if (D_8010832C_25399C_SneakNSnore >= 61) {
                            f32 zero;

                            D_80108318_253988_SneakNSnore[i] -= 0.1f;
                            zero = 0.0f;
                            if (D_80108318_253988_SneakNSnore[i] < zero) {
                                D_80108318_253988_SneakNSnore[i] = zero;
                            }
                        }
                    }
                    D_8010832C_25399C_SneakNSnore++;
                }
                func_800297E8_2A3E8(obj->model[i + 4], 1.0f, D_80108308_253978_SneakNSnore[i], D_80108318_253988_SneakNSnore[i]);
            }
        }
        obj->trans.y = D_801082F8_253968_SneakNSnore[0];
        func_80029714_2A314(obj->model[1], -70.0f, D_801082F8_253968_SneakNSnore[1], -510.0f);
        func_80029714_2A314(obj->model[2], 70.0f, D_801082F8_253968_SneakNSnore[2], -510.0f);
        func_80029714_2A314(obj->model[3], 220.0f, D_801082F8_253968_SneakNSnore[3], -510.0f);
    }
}
