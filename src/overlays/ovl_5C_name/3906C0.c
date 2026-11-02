#include "ovl_5C.h"

void func_80102800_3906C0_name_5C(void) {
    void (*prc)(void);

    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0x19);
    func_80088640_89240();
    func_80079128_79D28();
    omAddObj(0x2710, 0, 0, -1, func_80106D70_394C30_name_5C);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 0x64, 0x64, 0x64);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    D_80112F54_3A0E14_name_5C = 8000.0f;
    switch (D_800CD414_CE014) {
    case 0:
    case 2:
    case 4:
        _ClearFlag(0x13);
        if (D_800CD414_CE014 == 2 || D_800CD414_CE014 == 4) {
            func_8007DF5C_7EB5C();
        }
        D_80111C40_39FB00_name_5C = 17.0f;
        D_80112F24_3A0DE4_name_5C = 500.0f;
        if (D_800CD414_CE014 != 2) {
            PlayMusic(0x32);
        }
        prc = func_80102B78_390A38_name_5C;
        omAddPrcObj(prc, 0x3F00, 0x1800, 0);
        break;
    case 1:
        _ClearFlag(0x13);
        D_80111C40_39FB00_name_5C = 49.0f;
        D_80112F24_3A0DE4_name_5C = 80.0f;
        PlayMusic(7);
        prc = func_8010E8CC_39C78C_name_5C;
        omAddPrcObj(prc, 0x3F00, 0x1800, 0);
        break;
    }
    Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, D_80112F24_3A0DE4_name_5C, D_80112F54_3A0E14_name_5C);
    omPrcSetStatBit(omAddPrcObj(func_80108F28_396DE8_name_5C, 0x1100, 0x800, 0), 0xA0);
    InitFadeIn(0, 0x10);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
    func_8002C59C_2D19C(0x3DE, 0x3E8, 0xFF, 0xFF, 0xFF);
    D_801129F0_3A08B0_name_5C = D_801106D8_39E598_name_5C;
    _ClearFlag(0xC);
    _ClearFlag(0xE);
    D_80112A00_3A08C0_name_5C = D_800FD80C_FE40C;
    D_80112420_3A02E0_name_5C = 0;
    D_80112F28_3A0DE8_name_5C = 0x73;
    D_80112426_3A02E6_name_5C = 0;
    D_800CAFEE = -1;
}

void func_80102AB0_390970_name_5C(void) {
    func_8010E2AC_39C16C_name_5C();
    if (D_801124D6_3A0396_name_5C != 0) {
        D_80112368_3A0228_name_5C = 1;
    } else {
        D_80112368_3A0228_name_5C = 0;
    }
    if (D_801124D6_3A0396_name_5C < 0xA) {
        D_80112366_3A0226_name_5C = 0;
    } else {
        D_80112366_3A0226_name_5C = 1;
    }
    if (D_80112428_3A02E8_name_5C[0] == D_80112440_3A0300_name_5C[0] && D_80112428_3A02E8_name_5C[1] == D_80112440_3A0300_name_5C[1] && D_80112428_3A02E8_name_5C[2] == D_80112440_3A0300_name_5C[2]) {
        D_80113028_3A0EE8_name_5C = 1;
    } else {
        D_80113028_3A0EE8_name_5C = 0;
    }
    D_801106D0_39E590_name_5C = 1;
}

/* The Park lobby: the player walks between the six attractions (D_80112476_3A0336_name_5C). */
// register allocation: retail keeps `old` as an unextended lhu, not hoisted (masked 196, mostly a shifted frame)
#ifdef NON_MATCHING
void func_80102B78_390A38_name_5C(void) {
    s16 i;
    s16 n;
    s16 sel;
    s16 cnt;
    s16 told;
    s16 old;

    func_80102AB0_390970_name_5C();
    i = 0;
    func_801094FC_3973BC_name_5C(D_80110F64_39EE24_name_5C);
    func_8002A00C_2AC0C(D_80112F60_3A0E20_name_5C[0]);
    func_8002A00C_2AC0C(D_80112F60_3A0E20_name_5C[0x19]);
    func_8002A00C_2AC0C(D_80112F60_3A0E20_name_5C[0x1B]);
    HmfModelObjAttrSet(D_80112F60_3A0E20_name_5C[0xB], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80112F60_3A0E20_name_5C[0xB]);
    func_80029AFC_2A6FC(D_80112F60_3A0E20_name_5C[0xB]);
    func_800B1E50_B2A50(D_800FC834_FD434[D_80112F60_3A0E20_name_5C[0xB]].mtx, 1.0f, 0.9f, 1.0f);
    func_8002A00C_2AC0C(D_80112F60_3A0E20_name_5C[0xB]);
    HmfModelObjAttrSet(D_80112F60_3A0E20_name_5C[0xC], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80112F60_3A0E20_name_5C[0xC]);
    func_80029AFC_2A6FC(D_80112F60_3A0E20_name_5C[0xC]);
    omAddPrcObj(func_80105688_393548_name_5C, 0x3F00, 0x800, 0);
    do {
        omAddPrcObj(func_80106EB8_394D78_name_5C, 0x3F00, 0x2000, 0);
        omAddPrcObj(func_80106EB8_394D78_name_5C, 0x3F00, 0x2000, 0);
        omAddPrcObj(func_80106EB8_394D78_name_5C, 0x3F00, 0x2000, 0);
        omAddPrcObj(func_80106EB8_394D78_name_5C, 0x3F00, 0x2000, 0);
        i++;
    } while (i < 2);
    func_80107480_395340_name_5C(1);
    omAddPrcObj(func_801084C4_396384_name_5C, 0x3F00, 0x800, 0);
    func_801088E0_3967A0_name_5C((s16(*)[2])D_80112FB0_3A0E70_name_5C);
    D_80112364_3A0224_name_5C = 0;
    for (i = 0; i < 5; i++) {
        D_80112338_3A01F8_name_5C[i] = omAddPrcObj(func_80105DD0_393C90_name_5C, 0x3F00, 0x800, 0);
    }
    omAddPrcObj(func_80106418_3942D8_name_5C, 0x3F00, 0x800, 0);
    D_80112476_3A0336_name_5C = 0;
    if (D_800CD414_CE014 != 2) {
        func_801096BC_39757C_name_5C(D_80110F64_39EE24_name_5C, 0);
        func_80103770_391630_name_5C();
        D_80112332_3A01F2_name_5C = 1;
        if (D_800CD414_CE014 != 4) {
            func_80107660_395520_name_5C(0, 0x14, 1, func_801038A8_391768_name_5C);
        } else {
            func_80107480_395340_name_5C(0);
            while (func_8008F618_90218() != 0) {
                HuPrcVSleep();
            }
        }
        func_80106588_394448_name_5C();
        if (_CheckFlag(0x18) == 0) {
            func_801064D4_394394_name_5C(0x389);
        } else {
            func_801064D4_394394_name_5C(0x38A);
        }
        func_80106500_3943C0_name_5C();
        func_80103B30_3919F0_name_5C();
        func_801088EC_3967AC_name_5C(5);
        func_801088A8_396768_name_5C(0);
        D_80112424_3A02E4_name_5C = 1;
        D_80112330_3A01F0_name_5C = 1;
        func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[0]);
        func_80106500_3943C0_name_5C();
        HuPrcSleep(5);
        _SetFlag(0x18);
    } else {
        func_80107480_395340_name_5C(4);
        func_801096BC_39757C_name_5C(D_80110F64_39EE24_name_5C, 1);
        func_8010A190_398050_name_5C();
        D_80112332_3A01F2_name_5C = 1;
        func_80107F28_395DE8_name_5C(D_80110B44_39EA04_name_5C, 100.0f, func_80103A10_3918D0_name_5C);
        func_80103B30_3919F0_name_5C();
        func_801088A8_396768_name_5C(0);
        func_801088EC_3967AC_name_5C(5);
        D_80112424_3A02E4_name_5C = 1;
        func_80106588_394448_name_5C();
        func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[0]);
        func_80106500_3943C0_name_5C();
        D_80112330_3A01F0_name_5C = 1;
    }
    func_80103B30_3919F0_name_5C();
    func_8010E2AC_39C16C_name_5C();
    old = D_801124D6_3A0396_name_5C;
    while (1) {
        if ((ContStkX[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkX[D_80112A00_3A08C0_name_5C] : ContStkX[D_80112A00_3A08C0_name_5C]) >= 31
            || (ContStkY[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkY[D_80112A00_3A08C0_name_5C] : ContStkY[D_80112A00_3A08C0_name_5C]) >= 31) {
            n = func_801068BC_39477C_name_5C(D_80112476_3A0336_name_5C, 6, -ContStkX[D_80112A00_3A08C0_name_5C], ContStkY[D_80112A00_3A08C0_name_5C]);
            if (n != -1) {
                PlaySound(1);
                func_801088F8_3967B8_name_5C(n);
                HuPrcSleep(6);
                D_80112476_3A0336_name_5C = n;
                func_80105DB0_393C70_name_5C(n);
                func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[D_80112476_3A0336_name_5C]);
                func_80106500_3943C0_name_5C();
            }
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x8000) {
            PlaySound(2);
            D_80112330_3A01F0_name_5C = 0;
            sel = D_80112476_3A0336_name_5C;
            switch (sel) {
            case 0:
                D_80112424_3A02E4_name_5C = 0;
                func_801065AC_39446C_name_5C();
                func_80107F28_395DE8_name_5C(D_80110A3C_39E8FC_name_5C, 100.0f, func_801039A8_391868_name_5C);
                func_800794A8_7A0A8(0x1E);
                D_80112332_3A01F2_name_5C = 0;
                do {
                    func_80079920_7A520();
                } while (D_800CD526_CE126 & 8);
                D_801106D0_39E590_name_5C = 0;
                func_8010A190_398050_name_5C();
                D_801106D0_39E590_name_5C = 1;
                D_80112332_3A01F2_name_5C = 1;
                func_8010E2AC_39C16C_name_5C();
                if (D_801124D6_3A0396_name_5C != 0) {
                    D_80112368_3A0228_name_5C = 1;
                } else {
                    D_80112368_3A0228_name_5C = 0;
                }
                if (D_80112428_3A02E8_name_5C[0] == D_80112440_3A0300_name_5C[0] && D_80112428_3A02E8_name_5C[1] == D_80112440_3A0300_name_5C[1] && D_80112428_3A02E8_name_5C[2] == D_80112440_3A0300_name_5C[2]) {
                    D_80113028_3A0EE8_name_5C = 1;
                } else {
                    D_80113028_3A0EE8_name_5C = 0;
                }
                if ((s16)old < D_801124D6_3A0396_name_5C && (s16)old < 0xA && D_801124D6_3A0396_name_5C >= 0xA) {
                    D_80112366_3A0226_name_5C = 1;
                }
                func_80103770_391630_name_5C();
                func_80107F28_395DE8_name_5C(D_80110B44_39EA04_name_5C, 100.0f, func_80103A10_3918D0_name_5C);
                break;
            case 1:
                if (D_80112368_3A0228_name_5C == 0) {
                    func_801064D4_394394_name_5C(0x398);
                    func_80106500_3943C0_name_5C();
                    func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[D_80112476_3A0336_name_5C]);
                    func_80106500_3943C0_name_5C();
                    break;
                }
                D_80112424_3A02E4_name_5C = 0;
                func_801065AC_39446C_name_5C();
                func_80107F28_395DE8_name_5C(D_80110C4C_39EB0C_name_5C, 100.0f, func_80103A54_391914_name_5C);
                D_801106D4_39E594_name_5C = 1;
                D_801106D2_39E592_name_5C = 1;
                D_800FFE00_100A00[0xEA] = -1;
                _SetFlag(0x13);
                D_80112420_3A02E0_name_5C = 2;
                D_80112F28_3A0DE8_name_5C = 0x58;
                D_80112426_3A02E6_name_5C = 1;
                omOvlHisChg(0, 0x5C, 4, 0x114);
                while (1) {
                    HuPrcVSleep();
                }
            case 2:
                D_80112424_3A02E4_name_5C = 0;
                func_801065AC_39446C_name_5C();
                func_80107F28_395DE8_name_5C(D_80110D54_39EC14_name_5C, 100.0f, func_80103A54_391914_name_5C);
                _ClearFlag(0x13);
                D_801106D4_39E594_name_5C = 1;
                D_801106D2_39E592_name_5C = 1;
                D_800FFE00_100A00[0xEA] = -1;
                D_80112420_3A02E0_name_5C = 2;
                D_80112F28_3A0DE8_name_5C = 0x58;
                D_80112426_3A02E6_name_5C = 2;
                omOvlHisChg(0, 0x5C, 4, 0x114);
                while (1) {
                    HuPrcVSleep();
                }
            case 3:
                D_80112424_3A02E4_name_5C = 0;
                _SetFlag(0x13);
                func_801065AC_39446C_name_5C();
                func_80107F28_395DE8_name_5C(D_80110E5C_39ED1C_name_5C, 100.0f, func_80103A54_391914_name_5C);
                D_801106D4_39E594_name_5C = 1;
                D_801106D2_39E592_name_5C = 1;
                D_80112420_3A02E0_name_5C = 2;
                D_80112F28_3A0DE8_name_5C = 0x58;
                D_80112426_3A02E6_name_5C = 3;
                omOvlHisChg(0, 0x5C, 4, 0x114);
                while (1) {
                    HuPrcVSleep();
                }
            case 4:
                func_80103D08_391BC8_name_5C();
                break;
            case 5:
                D_80112424_3A02E4_name_5C = 0;
                func_801065AC_39446C_name_5C();
                func_80103E1C_391CDC_name_5C();
                break;
            }
            told = 0;
            func_80103B30_3919F0_name_5C();
            func_801088A8_396768_name_5C(sel);
            D_80112476_3A0336_name_5C = sel;
            func_801065F8_3944B8_name_5C();
            func_80106588_394448_name_5C();
            if ((s16)old < D_801124D6_3A0396_name_5C) {
                cnt = 0;
                for (i = 0; i < 0x48; i++) {
                    if (D_800CAD94[i].kind == 7) {
                        if (func_80067F4C_68B4C(i) != 0) {
                            cnt++;
                        }
                    }
                }
                if ((s16)old < 0xA && D_801124D6_3A0396_name_5C >= 0xA) {
                    func_801064D4_394394_name_5C(0x38B);
                    func_80106500_3943C0_name_5C();
                    func_801064D4_394394_name_5C(0x38C);
                    func_80106500_3943C0_name_5C();
                    told = 1;
                } else if (((s16)old < 0x14 && D_801124D6_3A0396_name_5C >= 0x14) || ((s16)old < 0x1E && D_801124D6_3A0396_name_5C >= 0x1E && cnt != 0)) {
                    func_801064D4_394394_name_5C(0x38B);
                    func_80106500_3943C0_name_5C();
                    func_801064D4_394394_name_5C(0x38D);
                    func_80106500_3943C0_name_5C();
                    told = 1;
                }
                if ((s16)old < 0x2A && D_801124D6_3A0396_name_5C >= 0x2A) {
                    if (told == 0) {
                        func_801064D4_394394_name_5C(0x38B);
                        func_80106500_3943C0_name_5C();
                    }
                    func_801064D4_394394_name_5C(0x38E);
                    func_80106500_3943C0_name_5C();
                }
            }
            func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[D_80112476_3A0336_name_5C]);
            func_80106500_3943C0_name_5C();
            D_80112424_3A02E4_name_5C = 1;
            D_80112330_3A01F0_name_5C = 1;
            HuPrcSleep(5);
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x4000) {
            PlaySound(4);
            D_80112424_3A02E4_name_5C = 0;
            func_801064D4_394394_name_5C(0x38F);
            if (func_80106500_3943C0_name_5C() != 0) {
                HuPrcSleep(3);
                D_80112424_3A02E4_name_5C = 1;
                HuPrcSleep(5);
                func_801064D4_394394_name_5C(D_801114D4_39F394_name_5C[D_80112476_3A0336_name_5C]);
                func_80106500_3943C0_name_5C();
            } else {
                func_801064D4_394394_name_5C(0x390);
                func_80106500_3943C0_name_5C();
                D_80112330_3A01F0_name_5C = 0;
                HuPrcSleep(0xA);
                func_801065AC_39446C_name_5C();
                func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
                func_800794A8_7A0A8(0x1E);
                func_80107660_395520_name_5C(1, 0x14, 1, func_8010392C_3917EC_name_5C);
                D_80112420_3A02E0_name_5C = 0;
                omOvlHisChg(1, 0x5B, 1, 0x1014);
                func_8008F624_90224(0xFF, 0xFF, 0xFF);
                D_801106D4_39E594_name_5C = 1;
                D_801106D2_39E592_name_5C = 1;
                _ClearFlag(0x13);
                while (1) {
                    HuPrcVSleep();
                }
            }
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80102B78_390A38_name_5C);
#endif

void func_80103770_391630_name_5C(void) {
    if (D_80112366_3A0226_name_5C == 0) {
        func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[6], 4, 4);
    }
    if (D_80112368_3A0228_name_5C != 0) {
        D_801114D4_39F394_name_5C[1] = 0x394;
    } else {
        D_801114D4_39F394_name_5C[1] = 0x393;
    }
    if (D_80113028_3A0EE8_name_5C == 0) {
        func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[8], 4, 4);
    }
    if (_CheckFlag(0x10) == 0) {
        func_800B1E50_B2A50(func_8002A9F4_2B5F4(D_80112F60_3A0E20_name_5C[4], "item")->unk58, 0.0f, 0.0f, 0.0f);
        func_800B1E50_B2A50(func_8002A9F4_2B5F4(D_80112F60_3A0E20_name_5C[4], "bmerge3")->unk58, 0.0f, 0.0f, 0.0f);
    }
    if (_CheckFlag(0x11) == 0) {
        func_800B1E50_B2A50(func_8002A9F4_2B5F4(D_80112F60_3A0E20_name_5C[4], "battle")->unk58, 0.0f, 0.0f, 0.0f);
        func_800B1E50_B2A50(func_8002A9F4_2B5F4(D_80112F60_3A0E20_name_5C[4], "bmerge4")->unk58, 0.0f, 0.0f, 0.0f);
    }
}

void func_801038A8_391768_name_5C(s16* t) {
    func_8002C59C_2D19C((f32)t[0] / (f32)t[1] * 700.0f + 290.0f, 0x3E8, 0xFF, 0xFF, 0xFF);
}

void func_8010392C_3917EC_name_5C(s16* t) {
    func_8002C59C_2D19C(990.0f - (f32)t[0] / (f32)t[1] * 990.0f, 0x3E8, 0xFF, 0xFF, 0xFF);
}

// register allocation: argument extension order (masked 2)
#ifdef NON_MATCHING
void func_801039A8_391868_name_5C(s16 total, s16 idx, s16 frame) {
    if (total - 5 == frame) {
        InitFadeOut(0, 5);
    }
    if (idx == 3) {
        func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[6], 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801039A8_391868_name_5C);
#endif

void func_80103A10_3918D0_name_5C(s16 total, s16 idx, s16 frame) {
    if (idx == 2 && D_80112366_3A0226_name_5C != 0) {
        func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[6], 4, 0);
    }
}

// register allocation: s0/s1 swapped (masked 3)
#ifdef NON_MATCHING
void func_80103A54_391914_name_5C(s16 total, s16 idx, s16 frame) {
    f32 fov;

    if (total - 5 == frame) {
        InitFadeOut(0, 5);
        func_800794A8_7A0A8(0x1E);
    }
    if (total - frame < 0xA) {
        fov = (s16)(frame + 0xA - total) * -0.7f + 17.0f;
        D_80111C40_39FB00_name_5C = fov;
        Hu3DCamSetPerspective(0, fov, D_80112F24_3A0DE4_name_5C, D_80112F54_3A0E14_name_5C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103A54_391914_name_5C);
#endif

/* Screen positions of the six attractions' models, for the cursor. */
void func_80103B30_3919F0_name_5C(void) {
    s16 models[6] = { 2, 4, 6, 8, 9, 10 };
    Vec ofs[6] = {
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 51.375f, 152.5f },
        { 0.0f, 51.375f, 148.25f },
        { 0.0f, 51.375f, 73.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
    };
    Vec pos;
    Vec2f scr;
    s16 i;

    func_8010687C_39473C_name_5C();
    for (i = 0; i < 6; i++) {
        func_80029760_2A360(D_80112F60_3A0E20_name_5C[models[i]], &pos);
        pos.x += ofs[i].x;
        pos.y += ofs[i].y;
        pos.z += ofs[i].z;
        Hu3DCam3DToScreen(0, &pos, &scr);
        D_80112FB0_3A0E70_name_5C[i].x = scr.unk_00;
        D_80112FB0_3A0E70_name_5C[i].y = scr.unk_04;
    }
    if (D_80112366_3A0226_name_5C == 0) {
        D_80112458_3A0318_name_5C[2] = 0;
    }
    if (D_80113028_3A0EE8_name_5C == 0) {
        D_80112458_3A0318_name_5C[3] = 0;
    }
}

/* Says the coin count (D_800F8C60.coinNum), with 0, repeated 7s and 99999 as their own messages. */
void func_80103D08_391BC8_name_5C(void) {
    char buf[8];
    s16 i;
    s32 mes;
    s32 coin;

    coin = D_800F8C60.coinNum;
    if (coin == 0) {
        mes = 0x39F;
    } else if (coin == 7) {
        mes = 0x39A;
    } else if (coin == 77) {
        mes = 0x39B;
    } else if (coin == 777) {
        mes = 0x39C;
    } else if (coin == 7777) {
        mes = 0x39D;
    } else if (coin == 77777) {
        mes = 0x39E;
    } else if (coin == 99999) {
        mes = 0x3A0;
    } else {
        sprintf(buf, "%5d", coin);
        for (i = 0; i < 4; i++) {
            if (buf[i] != ' ') {
                break;
            }
        }
        func_801065D0_394490_name_5C(&buf[i], 0);
        mes = 0x399;
    }
    func_801064D4_394394_name_5C(mes);
    func_80106500_3943C0_name_5C();
    func_801064D4_394394_name_5C(0x392);
    func_80106500_3943C0_name_5C();
}

/* The record board: the player model swings to the camera, then shows the two result pages. */
// register allocation: float registers, frame 8 bytes smaller (masked 23)
#ifdef NON_MATCHING
void func_80103E1C_391CDC_name_5C(void) {
    Vec2f scr;
    Vec to;
    Vec cur;
    Vec from;
    Vec rot0;
    Vec rot1;
    s16 i;
    f32 t;
    f32 s;
    u16 model;
    u16 other;

    model = D_80112F60_3A0E20_name_5C[0xB];
    other = D_80112F60_3A0E20_name_5C[0xC];
    D_801114B6_39F376_name_5C = -1;
    scr.unk_00 = 160.0f;
    scr.unk_04 = 120.0f;
    func_80109BEC_397AAC_name_5C(0, 260.0f, &scr, &to);
    from.x = D_800FC834_FD434[(s16)model].pos.x;
    from.y = D_800FC834_FD434[(s16)model].pos.y;
    from.z = D_800FC834_FD434[(s16)model].pos.z;
    for (i = 0; i < 11; i++) {
        s = HuMathSin(i * 9.0f) * 70.0f;
        cur.y = s + from.y;
        D_800FC834_FD434[(s16)model].pos.y = cur.y;
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    from.y = D_800FC834_FD434[(s16)model].pos.y;
    rot0 = D_80111138_39EFF8_name_5C;
    if (D_801129F4_3A08B4_name_5C.x > 180.0f) {
        rot1.x = D_801129F4_3A08B4_name_5C.x - 360.0f;
    } else {
        rot1.x = D_801129F4_3A08B4_name_5C.x;
    }
    if (D_801129F4_3A08B4_name_5C.y > 180.0f) {
        rot1.y = D_801129F4_3A08B4_name_5C.y - 360.0f;
    } else {
        rot1.y = D_801129F4_3A08B4_name_5C.y;
    }
    if (D_801129F4_3A08B4_name_5C.z > 180.0f) {
        rot1.z = D_801129F4_3A08B4_name_5C.z - 360.0f;
    } else {
        rot1.z = D_801129F4_3A08B4_name_5C.z;
    }
    PlaySound(0x9F);
    for (i = 0; i < 11; i++) {
        t = i * 0.1f;
        func_8002A15C_2AD5C(model, other, 1.0f - t);
        cur.x = (to.x - from.x) * t + from.x;
        cur.y = (to.y - from.y) * t + from.y;
        cur.z = (to.z - from.z) * t + from.z;
        func_80029714_2A314(model, cur.x, cur.y, cur.z);
        cur.x = (rot1.x - rot0.x) * t + rot0.x;
        cur.y = (rot1.y - rot0.y) * t + rot0.y;
        cur.z = (rot1.z - rot0.z) * t + rot0.z;
        func_8002979C_2A39C(model, cur.x, cur.y, cur.z);
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        func_8002A15C_2AD5C(model, other, 0.0f);
        HuPrcVSleep();
    }
    while (1) {
        if (func_80104484_392344_name_5C() & 0x4000) {
            break;
        }
        HuPrcSleep(5);
        if (func_80104F88_392E48_name_5C() & 0x4000) {
            break;
        }
        HuPrcSleep(5);
    }
    HuPrcSleep(5);
    PlaySound(0x12B);
    for (i = 0; i < 11; i++) {
        t = i * 0.1f;
        func_8002A15C_2AD5C(model, other, t);
        t = 1.0f - t;
        cur.x = (to.x - from.x) * t + from.x;
        cur.y = (to.y - from.y) * t + from.y;
        cur.z = (to.z - from.z) * t + from.z;
        func_80029714_2A314(model, cur.x, cur.y, cur.z);
        cur.x = (rot1.x - rot0.x) * t + rot0.x;
        cur.y = (rot1.y - rot0.y) * t + rot0.y;
        cur.z = (rot1.z - rot0.z) * t + rot0.z;
        func_8002979C_2A39C(model, cur.x, cur.y, cur.z);
        HuPrcVSleep();
    }
    for (i = 0; i < 5; i++) {
        func_8002A15C_2AD5C(model, other, 1.0f);
        HuPrcVSleep();
    }
    for (i = 0; i < 11; i++) {
        cur.y = from.y - HuMathSin(i * 9.0f) * 70.0f;
        D_800FC834_FD434[(s16)model].pos.y = cur.y;
        HuPrcVSleep();
    }
    D_801114B6_39F376_name_5C = 11;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103E1C_391CDC_name_5C);
#endif

__asm__(".section .rodata");
const char D_80112220_3A00E0_name_5C[8] = "\x05" "%d\x05";
__asm__(".section .rodata");
const char D_80112228_3A00E8_name_5C[8] = "\x05" "%02d\x05";

// register allocation and duplicated divisions: 5B-style s16 temporaries, 1% fewer instructions (masked 62)
#ifdef NON_MATCHING
s32 func_80104484_392344_name_5C(void) {
    s16 win[7];
    char buf[21][32];
    u16 grp;
    s16 spr;
    s16 i;
    s16 j;
    s16 t;
    s16 hi;
    s16 rest;
    s16 mid;
    s32 w;
    s16 win1;
    s16 win2;
    s32 btn;
    s32 mask;
    f32 fade;

    grp = func_8001A2F8_1AEF8(0x90052);
    spr = func_8001AAAC_1B6AC(grp, 0, 1);
    espPosSet(spr, 160, 38);
    func_8001A6BC_1B2BC(spr, 0);
    for (i = 0; i < 7; i++) {
        win[i] = w = func_800888A8_894A8(54, i * 17 + 58, 260, 22, 0, 8);
        func_80089A7C_8A67C(w, 5);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089CAC_8A8AC(w, 4, 0, 160, 0);
        func_80089DA0_8A9A0(w, 192, 192, 192);
        if (func_80067F4C_68B4C((s16)D_801114EC_39F3AC_name_5C[i]) == 0) {
            func_800890CC_89CCC(w, (void*)0x3A2, -1, -1);
        } else {
            switch (i) {
            case 0:
                t = func_800680D4_68CD4(1);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 1:
                t = func_800680D4_68CD4(2);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 2:
                t = func_800680D4_68CD4(3);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 3600);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 3600;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 60);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 60;
                rest = rest * (1.0f / 60.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 3:
                t = func_800680D4_68CD4(4);
                if (t == 0) {
                    t = 0x1400;
                }
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, t >> 8);
                func_80089308_89F08(w, buf[i * 3], 0);
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, t & 0xFF);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                break;
            case 4:
                t = func_800680D4_68CD4(5);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 5:
                t = func_800680D4_68CD4(6);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            case 6:
                t = func_800680D4_68CD4(7);
                sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, hi = t / 1800);
                func_80089308_89F08(w, buf[i * 3], 0);
                rest = t - hi * 1800;
                sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, mid = rest / 30);
                func_80089308_89F08(w, buf[i * 3 + 1], 1);
                rest = rest - mid * 30;
                rest = rest * (1.0f / 30.0f) * 100.0f;
                sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, rest);
                func_80089308_89F08(w, buf[i * 3 + 2], 2);
                break;
            }
            func_800890CC_89CCC(w, (void*)i + 0x3A3, -1, -1);
        }
    }
    win1 = func_801054F0_3933B0_name_5C(60, 184);
    win2 = func_801055BC_39347C_name_5C(60, 196);
    HuPrcVSleep();
    if (func_80068040_68C40(0x38) != 0) {
        func_8008D6F0_8E2F0(win1);
        func_8008D6F0_8E2F0(win2);
    }
    for (i = 0; i < 6; i++) {
        fade = i * 51.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 7; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        if (func_80068040_68C40(0x38) != 0) {
            func_80089BBC_8A7BC(win1, (s16)fade);
            func_80089BBC_8A7BC(win2, (s16)fade);
        }
        HuPrcVSleep();
    }
    mask = 0xC000;
    if (func_80068040_68C40(0x38) == 0) {
        mask = 0x4000;
    }
    while (1) {
        btn = ContBtnTrg[D_80112A00_3A08C0_name_5C];
        if (btn & mask) {
            if ((u16)btn == 0x8000) {
                PlaySound(1);
            } else {
                PlaySound(4);
            }
            break;
        }
        HuPrcVSleep();
    }
    for (i = 1; i < 6; i++) {
        fade = i * -50.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 7; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        if (func_80068040_68C40(0x38) != 0) {
            func_80089BBC_8A7BC(win1, (s16)fade);
            func_80089BBC_8A7BC(win2, (s16)fade);
        }
        HuPrcVSleep();
    }
    func_8001AC44_1B844(spr);
    SprAnimKill(grp);
    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8(win[i]);
    }
    func_8008CCA8_8D8A8(win1);
    func_8008CCA8_8D8A8(win2);
    return (s16)btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80104484_392344_name_5C);
#endif

s32 func_80104F88_392E48_name_5C(void) {
    s16 win[5];
    char buf[15][32];
    u16 grp;
    s16 spr;
    s16 i;
    s16 j;
    s16 t;
    s16 w;
    s16 win1;
    s16 win2;
    s32 btn;
    s16 n;
    f32 fade;

    grp = func_8001A2F8_1AEF8(0x90053);
    spr = func_8001AAAC_1B6AC(grp, 0, 1);
    espPosSet(spr, 160, 38);
    func_8001A6BC_1B2BC(spr, 0);
    for (i = 0; i < 5; i++) {
        w = win[i] = func_800888A8_894A8(35, i * 20 + 58, 250, 22, 0, 8);
        func_80089A7C_8A67C(w, 5);
        func_80089284_89E84(w, 0x10020, 0x10020);
        func_80089B2C_8A72C(w, 0);
        func_80089BBC_8A7BC(w, 0);
        func_80089A48_8A648(w, 0);
        func_80089C78_8A878(w, 1);
        func_80089CAC_8A8AC(w, 4, 0, 160, 0);
        func_80089DA0_8A9A0(w, 192, 192, 192);
        t = func_800680D4_68CD4((s16)(i + 8));
        n = t == 0;
        sprintf(buf[i * 3], D_80112220_3A00E0_name_5C, n);
        func_80089308_89F08(w, buf[i * 3], 0);
        n = (t >> 12) * 10 + ((t & 0xF00) >> 8);
        sprintf(buf[i * 3 + 1], D_80112228_3A00E8_name_5C, n);
        func_80089308_89F08(w, buf[i * 3 + 1], 1);
        n = ((t & 0xF0) >> 4) * 10 + (t & 0xF);
        sprintf(buf[i * 3 + 2], D_80112228_3A00E8_name_5C, n);
        func_80089308_89F08(w, buf[i * 3 + 2], 2);
        func_800890CC_89CCC(w, (void*)i + 0x3AA, -1, -1);
    }
    win1 = func_801054F0_3933B0_name_5C(60, 184);
    win2 = func_801055BC_39347C_name_5C(60, 196);
    HuPrcVSleep();
    func_8008D6F0_8E2F0(win1);
    func_8008D6F0_8E2F0(win2);
    for (i = 0; i < 6; i++) {
        fade = i * 51.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 5; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    while (1) {
        btn = ContBtnTrg[D_80112A00_3A08C0_name_5C];
        if (btn & 0xC000) {
            if ((u16)btn == 0x8000) {
                PlaySound(1);
            } else {
                PlaySound(4);
            }
            break;
        }
        HuPrcVSleep();
    }
    for (i = 1; i < 6; i++) {
        fade = i * -50.0f;
        func_8001A6BC_1B2BC(spr, fade);
        for (j = 0; j < 5; j++) {
            func_80089BBC_8A7BC(win[j], (s16)fade);
        }
        func_80089BBC_8A7BC(win1, (s16)fade);
        func_80089BBC_8A7BC(win2, (s16)fade);
        HuPrcVSleep();
    }
    func_8001AC44_1B844(spr);
    SprAnimKill(grp);
    for (i = 0; i < 5; i++) {
        func_8008CCA8_8D8A8(win[i]);
    }
    func_8008CCA8_8D8A8(win1);
    func_8008CCA8_8D8A8(win2);
    return (s16)btn;
}

s16 func_801054F0_3933B0_name_5C(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 32, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_8008D5D8_8E1D8(win);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, (void*)0x3AF, -2, -1);
    return win;
}

s16 func_801055BC_39347C_name_5C(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 20, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_8008D5D8_8E1D8(win);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, (void*)0x535, -2, -1);
    return win;
}

/* Process: scrolls the water, bobs the attractions and pulses the one under the cursor. */
// register allocation: float registers (masked 28)
#ifdef NON_MATCHING
void func_80105688_393548_name_5C(void) {
    s16 n;
    s16 i;
    s16 a;
    u16 base;
    u16 mark;
    f32 scroll;
    f32 bob;
    f32 scale;
    f32 s;

    for (n = 0; D_80111464_39F324_name_5C[n].base != -1; n++) {
        D_80111464_39F324_name_5C[n].t = rand8() & 0xFF;
        if (D_80111464_39F324_name_5C[n].mark != -1) {
            func_8002D124_2DD24(D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[n].mark]);
            func_80029AFC_2A6FC(D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[n].mark]);
        }
    }
    scroll = 0.0f;
    while (1) {
        s = -scroll;
        func_8002BED4_2CAD4(D_80112F60_3A0E20_name_5C[0], 0.0f, s, 0x20, 0x20, "sea_un_a", 0);
        func_8002BED4_2CAD4(D_80112F60_3A0E20_name_5C[0], 0.0f, s, 0x20, 0x20, "sea_un_b", 0);
        func_8002BED4_2CAD4(D_80112F60_3A0E20_name_5C[0], 0.0f, s, 0x20, 0x20, "sea_ov_a", 0);
        func_8002BED4_2CAD4(D_80112F60_3A0E20_name_5C[0], 0.0f, s, 0x20, 0x20, "sea_ov_b", 0);
        func_8002BED4_2CAD4(D_80112F60_3A0E20_name_5C[0x19], 0.0f, s, 0x20, 0x20, "taki", 0);
        scroll += 0.3f;
        if (scroll > 32.0f) {
            scroll = 0.0f;
        }
        for (i = 0; i < n; i++) {
            base = D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[i].base];
            if (D_80111464_39F324_name_5C[i].mark != -1) {
                mark = D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[i].mark];
                a = (s32)((D_80111464_39F324_name_5C[i].t + 90.0f) / 4.0f) % 90;
                if (a >= 80.0f) {
                    if (i != D_80112476_3A0336_name_5C || D_80112330_3A01F0_name_5C == 0) {
                        func_800298A4_2A4A4(mark, 4, 4);
                    }
                }
                if (i == D_80112476_3A0336_name_5C && D_80112330_3A01F0_name_5C != 0) {
                    func_800298A4_2A4A4(mark, 4, 0);
                }
                s = HuMathSin(a) * 0.3f + D_80111464_39F324_name_5C[i].scale;
                func_80029714_2A314(mark, D_800FC834_FD434[(s16)base].pos.x, 50.0f, D_800FC834_FD434[(s16)base].pos.z);
                func_800297E8_2A3E8(mark, s, 1.0f, s);
                func_8002D0A0_2DCA0(mark, (u8)((90 - a) * 2.8333333f));
            }
            if (D_80112332_3A01F2_name_5C != 0) {
                bob = func_800B7890_B8490(D_80111464_39F324_name_5C[i].t) * 5.0f;
            } else {
                bob = 0.0f;
            }
            if (i == D_80112476_3A0336_name_5C && D_80112330_3A01F0_name_5C != 0) {
                scale = func_800B7890_B8490(D_80111464_39F324_name_5C[i].t) * 0.05f + 0.5f;
            } else {
                scale = 0.5f;
            }
            D_80111464_39F324_name_5C[i].t += 15.0f;
            if (D_80111464_39F324_name_5C[i].t > 360.0f) {
                D_80111464_39F324_name_5C[i].t -= 360.0f;
            }
            bob += D_80110F64_39EE24_name_5C[D_80111464_39F324_name_5C[i].base].pos.y * 5.0f * 0.5f;
            D_800FC834_FD434[(s16)base].pos.y = bob;
            func_800297E8_2A3E8(base, scale, scale, scale);
            if (D_80111464_39F324_name_5C[i].b != -1) {
                D_800FC834_FD434[D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[i].b]].pos.y = bob;
                func_800297E8_2A3E8(D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[i].b], scale, scale, scale);
            }
            if (D_80111464_39F324_name_5C[i].c != -1) {
                func_800297E8_2A3E8(D_80112F60_3A0E20_name_5C[D_80111464_39F324_name_5C[i].c], scale, scale, scale);
            }
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80105688_393548_name_5C);
#endif

void func_80105DB0_393C70_name_5C(s16 i) {
    D_80111464_39F324_name_5C[i].t = 270.0f;
}

/* Process: one selection cursor (D_801137D0[n]). While active it fades in, moves between
   its slots with its pad's stick (D_801138A0 records which cursor is on each slot), and
   sets `done` on A; when deactivated it fades out. */
void func_80105DD0_393C90_name_5C(void) {
    Ovl5CCursor* c;
    s16 n;
    s16 id;
    s16 spr;
    s16 shown;
    s16 i;
    s16 sel;
    f32 x0;
    f32 y0;
    f32 dx;
    f32 dy;
    f32 s;

    D_80112350_3A0210_name_5C[n = D_80112364_3A0224_name_5C] = func_80027154_27D54(sizeof(Ovl5CCursor), 0x7918);
    c = D_80112350_3A0210_name_5C[n];
    c->id = id = D_80112364_3A0224_name_5C++;
    shown = 0;
    c->active = 0;
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F9), c->id, 1);
    func_8001A788_1B388(spr, 1);
    espPosSet(spr, 160, 120);
    espDispOff(spr);
    c->x = 160.0f;
    c->y = 120.0f;
    c->done = 0;
    c->sel = 0;
    c->prevSel = 0;
    while (1) {
        HuPrcVSleep();
        espPosSet(spr, c->x, c->y);
        if (shown != 0 && c->active == 0) {
            c->prevSel = c->sel;
            for (i = 0; i < 3; i++) {
                func_8001A6BC_1B2BC(spr, 255.0f - i * 127.5f);
                HuPrcVSleep();
            }
            espDispOff(spr);
            shown = 0;
        }
        if (c->active != 0) {
            if (shown == 0 && c->active != 0) {
                c->done = 0;
                espDispOn(spr);
                for (i = 0; i < 5; i++) {
                    func_8001A6BC_1B2BC(spr, i * 63.75f);
                    HuPrcVSleep();
                }
                shown = 1;
                continue;
            }
            if (ContBtnTrg[c->port] & 0x8000) {
                c->done = 1;
                continue;
            }
            if (c->done != 1) {
                if ((ContStkX[c->port] < 0 ? -ContStkX[c->port] : ContStkX[c->port]) >= 31
                    || (ContStkY[c->port] < 0 ? -ContStkY[c->port] : ContStkY[c->port]) >= 31) {
                    i = func_801068BC_39477C_name_5C(c->sel, c->count, -ContStkX[c->port], ContStkY[c->port]);
                    if (i != -1) {
                        c->sel = i;
                    }
                }
            }
            if (c->prevSel == c->sel) {
                continue;
            }
            if (D_80112458_3A0318_name_5C[c->prevSel] != 16) {
                D_80112458_3A0318_name_5C[c->prevSel] = -1;
            }
            D_80112458_3A0318_name_5C[c->sel] = id;
            x0 = c->x;
            y0 = c->y;
            dx = c->slots[c->sel][0] - x0;
            dy = c->slots[c->sel][1] - y0;
            for (i = 1; i < 6; i++) {
                s = HuMathSin(i * 18.0f);
                c->x = x0 + dx * s;
                c->y = y0 + dy * s;
                espPosSet(spr, c->x, c->y);
                HuPrcVSleep();
            }
        }
        c->prevSel = c->sel;
    }
}

void func_801062AC_39416C_name_5C(s16 cursor, s8 active) {
    D_80112350_3A0210_name_5C[cursor]->active = active;
}

void func_801062C8_394188_name_5C(s16 cursor, s16 slot) {
    Ovl5CCursor* c = D_80112350_3A0210_name_5C[cursor];

    c->x = c->slots[slot][0];
    c->y = c->slots[slot][1];
    c->prevSel = slot;
    c->sel = slot;
    D_80112350_3A0210_name_5C[cursor]->done = 0;
    D_80112458_3A0318_name_5C[slot] = cursor;
}

void func_80106348_394208_name_5C(s16 cursor, s16 slot) {
    D_80112350_3A0210_name_5C[cursor]->sel = slot;
    D_80112458_3A0318_name_5C[slot] = cursor;
}

s16 func_80106378_394238_name_5C(s16 cursor) {
    return D_80112350_3A0210_name_5C[cursor]->done;
}

void func_80106394_394254_name_5C(s16 cursor, s16 done) {
    D_80112350_3A0210_name_5C[cursor]->done = done;
}

s16 func_801063B0_394270_name_5C(s16 cursor) {
    return D_80112350_3A0210_name_5C[cursor]->sel;
}

void func_801063CC_39428C_name_5C(s16 (*slots)[2], s8 count) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_80112350_3A0210_name_5C[i]->slots = slots;
        D_80112350_3A0210_name_5C[i]->count = count;
    }
}

/* Process: the message window. */
void func_80106418_3942D8_name_5C(void) {
    D_8011236A_3A022A_name_5C = func_8008DFC4_8EBC4(0x55, 0x48, 5);
    func_8008D59C_8E19C(D_8011236A_3A022A_name_5C, 1 << D_80112A00_3A08C0_name_5C);
    func_80089284_89E84(D_8011236A_3A022A_name_5C, 0x20, 0x20);
    func_8008E644_8F244(D_8011236A_3A022A_name_5C, 0xC0);
    D_80112336_3A01F6_name_5C = 1;
    while (1) {
        if (D_80112334_3A01F4_name_5C != 0) {
            break;
        }
        HuPrcVSleep();
    }
    func_8008E4D0_8F0D0(D_8011236A_3A022A_name_5C, 1);
    while (1) {
        HuPrcVSleep();
    }
}

void func_801064D4_394394_name_5C(s32 mes) {
    func_800890CC_89CCC(D_8011236A_3A022A_name_5C, (void*)mes, -1, -1);
}

s32 func_80106500_3943C0_name_5C(void) {
    while (func_8008BA30_8C630(D_8011236A_3A022A_name_5C) != 0) {
        HuPrcVSleep();
    }
    if (D_800F920C_F9E0C[D_8011236A_3A022A_name_5C].unk_30 != 0) {
        return func_8008BB48_8C748(D_8011236A_3A022A_name_5C, 0, 0);
    }
    return 0;
}

void func_80106588_394448_name_5C(void) {
    func_8008E2DC_8EEDC(D_8011236A_3A022A_name_5C, 1);
}

void func_801065AC_39446C_name_5C(void) {
    func_8008E4D0_8F0D0(D_8011236A_3A022A_name_5C, 1);
}

void func_801065D0_394490_name_5C(char* str, s32 unused) {
    func_80089308_89F08(D_8011236A_3A022A_name_5C, str, 0);
}

void func_801065F8_3944B8_name_5C(void) {
    func_8008AD44_8B944(D_8011236A_3A022A_name_5C);
}

#ifdef NON_MATCHING
void func_80106618_3944D8_name_5C(s16 model, s32 spr, char* part) {
    f32 mtx[4][4];

    func_80023554_24154(model, func_80029CE4_2A8E4(model), part, mtx);
    func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, mtx);
    espPosSet(spr, D_80112A04_3A08C4_name_5C.unk_00, D_80112A04_3A08C4_name_5C.unk_04);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106618_3944D8_name_5C);
#endif

#ifdef NON_MATCHING
void func_801066D4_394594_name_5C(s32 model, s32 spr, char* part) {
    void* obj;

    if (D_800FC834_FD434[(s16)model].hmf->unk84 != (void*)-1) {
        obj = func_8002A9F4_2B5F4(model, part);
        func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, ((HmfMotionObj*)obj)->unk58);
    } else {
        obj = func_8002A9F4_2B5F4(model, part);
        func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, ((HitXform*)obj)->unk4C);
    }
    espPosSet(spr, D_80112A04_3A08C4_name_5C.unk_00, D_80112A04_3A08C4_name_5C.unk_04);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801066D4_394594_name_5C);
#endif

void func_801067BC_39467C_name_5C(s16 i, s16 esp, s32 dx, s32 dy) {
    D_80112FB0_3A0E70_name_5C[i].x = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[esp].x + dx;
    D_80112FB0_3A0E70_name_5C[i].y = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[esp].y + dy;
}

void func_80106810_3946D0_name_5C(s16 i, Vec2f* pos, s16 dx, s16 dy) {
    D_80112FB0_3A0E70_name_5C[i].x = dx + pos->unk_00;
    D_80112FB0_3A0E70_name_5C[i].y = dy + pos->unk_04;
}

void func_8010687C_39473C_name_5C(void) {
    s16 i;

    for (i = 0; i < 30; i++) {
        D_80112458_3A0318_name_5C[i] = -1;
    }
}

#ifdef NON_MATCHING
s16 func_801068BC_39477C_name_5C(s16 cur, s16 n, s16 dx, s16 dy) {
    Vec2f dir[30];
    f32 dist[30];
    f32 x;
    f32 y;
    f32 len;
    f32 ux;
    f32 uy;
    f32 best;
    s16 i;
    s16 found;

    for (i = 0; i < n; i++) {
        if (i == cur || D_80112458_3A0318_name_5C[i] != -1) {
            dist[i] = -1.0f;
        } else {
            x = D_80112FB0_3A0E70_name_5C[cur].x - D_80112FB0_3A0E70_name_5C[i].x;
            y = D_80112FB0_3A0E70_name_5C[cur].y - D_80112FB0_3A0E70_name_5C[i].y;
            dist[i] = len = func_800B1830_B2430(x * x + y * y);
            dir[i].unk_00 = x / len;
            dir[i].unk_04 = y / len;
        }
    }
    len = func_800B1830_B2430(dx * dx + dy * dy);
    ux = dx / len;
    uy = dy / len;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        x = ux - dir[i].unk_00;
        y = uy - dir[i].unk_04;
        if (func_800B1830_B2430(x * x + y * y) > 0.5f) {
            dist[i] = -1.0f;
        }
    }
    best = 100000.0f;
    found = -1;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        if (dist[i] < best) {
            best = dist[i];
            found = i;
        }
    }
    return found;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801068BC_39477C_name_5C);
#endif

/* Process: a debug crosshair on pad 3; prints its position on A. */
// control flow: retail if-converts the step (sltu/negu/andi/ori) (masked 10)
#ifdef NON_MATCHING
void func_80106C0C_394ACC_name_5C(void) {
    s16 spr;
    s16 x;
    s16 y;
    s32 step;
    u16 btn;

    x = 0xA0;
    y = 0x78;
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900FF), 0, 1);
    espPosSet(spr, 0xA0, 0x78);
    espDispOff(spr);
    while (1) {
        if (ContBtnTrg[2] & 0x2000) {
            break;
        }
        HuPrcVSleep();
    }
    espDispOn(spr);
    while (1) {
        btn = ContBtn[2];
        step = ((btn & 0x2000) != 0) ? 6 : 1;
        if (btn & 0x200) {
            x -= step;
        }
        if (ContBtn[2] & 0x100) {
            x = step + x;
        }
        if (ContBtn[2] & 0x800) {
            y -= step;
        }
        if (ContBtn[2] & 0x400) {
            y = step + y;
        }
        if (ContBtnTrg[2] & 0x8000) {
            osSyncPrintf("XY = %d,%d\n", x, y);
        }
        espPosSet(spr, x, y);
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106C0C_394ACC_name_5C);
#endif

void func_80106D70_394C30_name_5C(omObjData* obj) {
    if (D_801106D2_39E592_name_5C != 0 || D_801011FC_101DFC != 0) {
        if (D_801106D4_39E594_name_5C == 0) {
            InitFadeOut(0, 8);
            func_800794A8_7A0A8(0x1E);
            func_80079614_7A214(0x1E);
        }
        obj->func_ptr = func_80106DE4_394CA4_name_5C;
    }
}

void func_80106DE4_394CA4_name_5C(omObjData* obj) {
    s32 flag;

    if (func_8008F618_90218() == 0) {
        func_8001AC44_1B844(D_80112F38_3A0DF8_name_5C);
        func_8008CE5C_8DA5C();
        flag = 0x100;
        if (D_80112F28_3A0DE8_name_5C == 0x58) {
            flag = 0x1000;
        }
        switch (D_80112420_3A02E0_name_5C) {
        case 0:
            omOvlReturnEx(1);
            break;
        case 2:
            omOvlCallEx(D_80112F28_3A0DE8_name_5C, D_80112426_3A02E6_name_5C, flag | 0x11);
            break;
        case 1:
            omOvlGotoEx(D_80112F28_3A0DE8_name_5C, D_80112426_3A02E6_name_5C, flag | 0x11);
            break;
        }
    }
}

/* Process: a walker on the paths D_80111C24_39FAE4_name_5C, four at a time, each later batch 30 frames on. */
void func_80106EB8_394D78_name_5C(void) {
    s16 model;
    s16 n;
    s16 k;
    f32 total;

    if (D_80111C34_39FAF4_name_5C == 0) {
        model = D_8011236C_3A022C_name_5C = LoadFormFile(0x900B8, 0x299);
    } else {
        model = func_80027D3C_2893C(D_8011236C_3A022C_name_5C);
    }
    n = D_80111C34_39FAF4_name_5C++;
    k = n % 4;
    func_80029E80_2AA80(model, 2, 2);
    func_800297E8_2A3E8(model, 0.3f, 0.3f, 0.3f);
    func_80029714_2A314(model, 0.0f, -100.0f, 0.0f);
    func_8002979C_2A39C(model, 0.0f, 90.0f, 0.0f);
    total = func_80107058_394F18_name_5C(D_80111C24_39FAE4_name_5C[k], 8.0f);
    if (n >= 4) {
        HuPrcSleep(n / 4 * 30);
    }
    while (1) {
        func_801071E4_3950A4_name_5C(D_80111C24_39FAE4_name_5C[k], model, total);
        HuPrcVSleep();
    }
}

/* Fills each path node's arrival time for a speed and returns the last; the list ends at a zero
   position. */
f32 func_80107058_394F18_name_5C(Ovl5CPathNode* path, f32 speed) {
    Ovl5CPathNode* prev = NULL;
    f32 t = 0.0f;
    Ovl5CPathNode* n = path;
    s16 i = 0;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    while (n->pos.x != 0.0f || n->pos.y != 0.0f || n->pos.z != 0.0f) {
        if (i > 0) {
            dx = prev->pos.x - n->pos.x;
            dy = prev->pos.y - n->pos.y;
            dz = prev->pos.z - n->pos.z;
            d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (d == 0.0f) {
                d = speed * 10.0f;
            }
            t += d / speed;
            n->t = t;
        }
        prev = n;
        i++;
        n = &path[i];
    }
    return t;
}

/* Walks a model along a path by Catmull-Rom over the node times. */
// register allocation: path and &pos registers swapped (masked 4)
#ifdef NON_MATCHING
void func_801071E4_3950A4_name_5C(Ovl5CPathNode* path, s16 model, f32 total) {
    f32 p[4];
    f32 tm[4];
    Vec pos;
    Ovl5CPathNode* n;
    f32 end = total - 10.0f;
    s16 i = 1;
    s16 frame = 10;
    f32 x;
    f32 z;

    while (frame < end) {
        if (D_801106D0_39E590_name_5C != 0) {
            func_800298A4_2A4A4(model, 4, 0);
        } else {
            func_800298A4_2A4A4(model, 4, 4);
        }
        if (frame > path[i + 1].t) {
            i++;
        }
        func_80029760_2A360(model, &pos);
        n = i + path;
        tm[0] = n[-1].t;
        tm[1] = n[0].t;
        tm[2] = n[1].t;
        tm[3] = n[2].t;
        p[0] = n[-1].pos.x;
        p[1] = n[0].pos.x;
        p[2] = n[1].pos.x;
        p[3] = n[2].pos.x;
        x = func_8002662C_2722C(p, tm, frame);
        p[0] = n[-1].pos.z;
        p[1] = n[0].pos.z;
        p[2] = n[1].pos.z;
        p[3] = n[2].pos.z;
        z = func_8002662C_2722C(p, tm, frame);
        func_80029714_2A314(model, x, n->pos.y, z);
        func_8002979C_2A39C(model, 0.0f, func_800B75A8_B81A8(x - pos.x, z - pos.z), 0.0f);
        HuPrcVSleep();
        frame++;
    }
    n = &path[i + 1];
    func_80029714_2A314(model, n->pos.x, n->pos.y, n->pos.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801071E4_3950A4_name_5C);
#endif

/* .data (0x39E590-0x39FB00, 801106D0-80111C40) */
s16 D_801106D0_39E590_name_5C = 1;
u16 D_801106D2_39E592_name_5C = 0;
s16 D_801106D4_39E594_name_5C = 0;
/* 801106D8 */
Ovl5CCamView D_801106D8_39E598_name_5C[31] = {
    { { 330.0f, 0.0f, 0.0f }, { 0.0f, 37.0f, -18.300001f }, 4097.0f },
    { { 330.0f, 0.0f, 0.0f }, { 0.0f, 37.0f, -18.300001f }, 5027.0f },
    { { 360.0f, 352.0f, 0.0f }, { 0.0f, 1285.0f, -268.0f }, 5817.0f },
    { { 373.0f, 0.0f, 0.0f }, { -444.0f, 28.0f, 65.0f }, 70.0f },
    { { 355.0f, 356.0f, 0.0f }, { -16.0f, 158.0f, 338.0f }, 1260.0f },
    { { 19.0f, 330.0f, 0.0f }, { 54.0f, 150.0f, 68.0f }, 710.0f },
    { { 351.0f, 0.0f, 0.0f }, { -3.0f, 121.0f, 74.0f }, 150.0f },
    { { 348.0f, 90.0f, 0.0f }, { 0.0f, 109.0f, 0.0f }, 375.0f },
    { { 354.0f, 56.0f, 0.0f }, { -15.0f, 91.0f, 33.0f }, 375.0f },
    { { 0.0f, 176.0f, 0.0f }, { -15.0f, 91.0f, 33.0f }, 375.0f },
    { { 2.0f, 286.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 216.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 144.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 72.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 0.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 68.0f, 0.0f, 0.0f }, { -13.0f, 283.0f, 72.0f }, 385.0f },
    { { 2.0f, 262.0f, 0.0f }, { -9.0f, 182.0f, -121.0f }, 85.0f },
    { { 4.0f, 194.0f, 0.0f }, { 107.0f, 169.0f, 35.0f }, 155.0f },
    { { 2.0f, 122.0f, 0.0f }, { 117.0f, 174.0f, 66.0f }, 25.0f },
    { { 2.0f, 48.0f, 0.0f }, { -203.0f, 184.0f, -38.0f }, 265.0f },
    { { 2.0f, 334.0f, 0.0f }, { -150.0f, 184.0f, -40.0f }, 45.0f },
    { { 350.0f, 286.0f, 0.0f }, { 5.0f, 235.0f, -7.0f }, 35.0f },
    { { 350.0f, 286.0f, 0.0f }, { 352.0f, 90.0f, -115.0f }, 5.0f },
    { { 350.0f, 216.0f, 0.0f }, { 0.0f, 213.0f, -1.0f }, 15.0f },
    { { 350.0f, 216.0f, 0.0f }, { 268.0f, 65.0f, 367.0f }, 65.0f },
    { { 350.0f, 144.0f, 0.0f }, { -9.0f, 243.0f, 3.0f }, 35.0f },
    { { 350.0f, 144.0f, 0.0f }, { -213.6f, 80.0f, 294.0f }, 10.0f },
    { { 350.0f, 70.0f, 0.0f }, { -9.0f, 243.0f, 3.0f }, 35.0f },
    { { 350.0f, 70.0f, 0.0f }, { -439.0f, 71.0f, -147.0f }, 95.0f },
    { { 350.0f, 0.0f, 0.0f }, { 5.0f, 242.0f, -22.0f }, 55.0f },
    { { 350.0f, 0.0f, 0.0f }, { -1.0f, 75.0f, -443.0f }, 75.0f },
};
/* 80110A3C */
Ovl5CCamNode D_80110A3C_39E8FC_name_5C[6] = {
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1697.0f, { -381.0f, 128.0f, -140.0f }, { 320.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 307.0f, { -484.0f, 161.0f, -140.0f }, { 342.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 307.0f, { -484.0f, 161.0f, -140.0f }, { 342.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80110B44 */
Ovl5CCamNode D_80110B44_39EA04_name_5C[6] = {
    { 307.0f, { -484.0f, 161.0f, -140.0f }, { 342.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 307.0f, { -484.0f, 161.0f, -140.0f }, { 342.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1697.0f, { -381.0f, 128.0f, -140.0f }, { 320.0f, 8.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80110C4C */
Ovl5CCamNode D_80110C4C_39EB0C_name_5C[6] = {
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1567.0f, { 0.0f, 72.0f, 114.0f }, { 325.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 500.0f, { 0.0f, 69.0f, 146.0f }, { 275.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 500.0f, { 0.0f, 69.0f, 146.0f }, { 275.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80110D54 */
Ovl5CCamNode D_80110D54_39EC14_name_5C[6] = {
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1447.0f, { -493.0f, 81.0f, 215.0f }, { 316.0f, 12.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 467.0f, { -458.0f, 76.0f, 390.0f }, { 278.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 467.0f, { -458.0f, 76.0f, 390.0f }, { 278.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80110E5C */
Ovl5CCamNode D_80110E5C_39ED1C_name_5C[6] = {
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4097.0f, { 0.0f, 37.0f, -18.0f }, { 330.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 2087.0f, { 0.0f, -199.0f, 191.0f }, { 318.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 857.0f, { 0.0f, -326.0f, 564.0f }, { 280.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 857.0f, { 0.0f, -326.0f, 564.0f }, { 280.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80110F64 */
Ovl5CModelDef D_80110F64_39EE24_name_5C[32] = {
    { 0x900AA, 0x631, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900C1, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BB, 0x631, 0, 0, 0x0, { -204.0f, 0.0f, -154.5f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B1, 0x231, 0, 0, 0x0, { -204.0f, 0.0f, -154.5f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B2, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B7, 0x231, 0, 0, 0x0, { -183.0f, 0.0f, 97.7f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B3, 0x631, 0, 2, 0x0, { -183.0f, 0.0f, 97.7f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B7, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 230.3f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B4, 0x631, 0, 2, 0x0, { 0.0f, 0.0f, 230.3f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B5, 0x231, 0, 2, 0x0, { 201.0f, 0.0f, 67.9f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900D3, 0x231, 0, 0, 0x0, { 100.0f, -15.0f, 150.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900D4, 0x621, 0, 0, 0x0, { 100.0f, -15.0f, 150.0f }, { 0.0f, 90.0f, 0.0f } },
    { 0x900D5, 0x225, 0, 0, 0x0, { 100.0f, 0.0f, 150.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900C2, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900AC, 0x231, 0, 0, 0x0, { -204.0f, 0.0f, -154.5f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900AC, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900AD, 0x231, 0, 0, 0x0, { -183.0f, 0.0f, 97.7f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900AD, 0x231, 0, 0, 0x0, { 0.0f, 0.0f, 230.3f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900AE, 0x231, 0, 2, 0x0, { 201.0f, 0.0f, 67.9f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { -204.0f, 0.0f, -154.5f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { -183.5f, 0.0f, 97.7f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { 0.0f, 0.0f, 230.3f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { 201.0f, 0.0f, 67.9f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B0, 0xA24, 0, 0, 0x0, { 100.0f, 0.0f, 150.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BE, 0x631, 0, 0, 0x1, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BA, 0xA35, 0, 0, 0x1, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BC, 0x631, 0, 2, 0x1, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BD, 0x235, 0, 0, 0x1, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900B9, 0x235, 0, 1, 0x1, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900C3, 0x235, 0, 1, 0x1, { 50.0f, 120.0f, 50.0f }, { 0.0f, 0.0f, 0.0f } },
    { -1, 0x0, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};
/* 80111464 */
Ovl5CAttraction D_80111464_39F324_name_5C[7] = {
    { 3, 2, 14, 19, 0.3f, 0.0f }, { 4, -1, 15, 20, 0.3f, 0.0f }, { 5, 6, 16, 21, 0.3f, 0.0f },
    { 7, 8, 17, 22, 0.3f, 0.0f }, { 9, -1, 18, 23, 0.15f, 0.0f }, { 10, 11, -1, 24, 0.05f, 0.0f },
    { -1, -1, -1, -1, 0.0f, 0.0f },
};
s32 D_801114D4_39F394_name_5C[6] = { 0x391, 0x394, 0x395, 0x396, 0x392, 0x3A1 };
s32 D_801114EC_39F3AC_name_5C[7] = { 0x1A, 0x1B, 0x1E, 0x28, 0x34, 0x34, 0x34 };
/* 80111508 */
Ovl5CPathNode D_80111508_39F3C8_name_5C[10] = {
    { { 265.0f, -57.0f, 45.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 265.0f, -57.0f, 45.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 95.0f, -57.0f, -330.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -230.0f, -57.0f, -295.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -335.0f, -57.0f, -35.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -125.0f, -57.0f, 285.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 165.0f, -57.0f, 240.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 265.0f, -57.0f, 45.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 265.0f, -57.0f, 45.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80111620 */
Ovl5CPathNode D_80111620_39F4E0_name_5C[19] = {
    { { -480.0f, -57.0f, -105.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -480.0f, -57.0f, -105.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -290.0f, -57.0f, -10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -185.0f, -57.0f, 240.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 25.0f, -57.0f, 290.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 225.0f, -57.0f, 200.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 255.0f, -57.0f, -125.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 45.0f, -57.0f, -325.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -240.0f, -57.0f, -245.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -335.0f, -57.0f, -75.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -205.0f, -57.0f, 200.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -300.0f, -57.0f, 440.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -470.0f, -57.0f, 505.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -635.0f, -57.0f, 385.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -710.0f, -57.0f, 135.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -570.0f, -57.0f, -75.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -480.0f, -57.0f, -105.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -480.0f, -57.0f, -105.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 80111834 */
Ovl5CPathNode D_80111834_39F6F4_name_5C[13] = {
    { { 20.0f, -57.0f, -310.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, -57.0f, -310.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 315.0f, -57.0f, -135.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 675.0f, -57.0f, -60.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 695.0f, -57.0f, 225.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 525.0f, -57.0f, 420.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 200.0f, -57.0f, 270.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -175.0f, -57.0f, 235.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -295.0f, -57.0f, -20.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -170.0f, -57.0f, -320.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, -57.0f, -310.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 20.0f, -57.0f, -310.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
/* 801119A0 */
Ovl5CPathNode D_801119A0_39F860_name_5C[23] = {
    { { 0.0f, -57.0f, 315.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, -57.0f, 315.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 190.0f, -57.0f, 285.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 290.0f, -57.0f, 75.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 465.0f, -57.0f, -90.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 720.0f, -57.0f, 125.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 510.0f, -57.0f, 405.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 260.0f, -57.0f, 305.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -175.0f, -57.0f, 250.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -330.0f, -57.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -185.0f, -57.0f, -285.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 5.0f, -57.0f, -335.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 280.0f, -57.0f, -100.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 265.0f, -57.0f, 280.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 335.0f, -57.0f, 495.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 210.0f, -57.0f, 655.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 15.0f, -57.0f, 820.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -225.0f, -57.0f, 640.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -225.0f, -57.0f, 365.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -80.0f, -57.0f, 280.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, -57.0f, 315.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, -57.0f, 315.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
Ovl5CPathNode* D_80111C24_39FAE4_name_5C[4] = {
    D_80111508_39F3C8_name_5C, D_80111620_39F4E0_name_5C, D_80111834_39F6F4_name_5C, D_801119A0_39F860_name_5C,
};
s16 D_80111C34_39FAF4_name_5C = 0;
s16 D_80111C36_39FAF6_name_5C = 0; /* padding */
s32 D_80111C38_39FAF8_name_5C[2] = { 0, 0 };
