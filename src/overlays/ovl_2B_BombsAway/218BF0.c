#include "common.h"
#include "ovl_2B.h"

void func_80102800_218BF0_BombsAway(void) {
    BaPlayer* p;
    BaStage* s;
    void* data;
    s16 i;
    u8 cam;

    func_8002D4D0_2E0D0(10);
    func_8002F290_2FE90(D_800F9D30_FA930, 10);
    func_80020D20_21920(0x30);
    omInitObjMan(0x20, 0);
    i = 0;
    func_80079128_79D28();
    D_8010D948_223D38_BombsAway = _CheckFlag(0xC) != 0;
    D_8010D94A_223D3A_BombsAway = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 45.0f, 80.0f, 4000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800F8FD0_F9BD0 = 0;
    D_8010D940_223D30_BombsAway.unk_00 = 0;
    D_8010D940_223D30_BombsAway.unk_04 = 0;
    D_8010D940_223D30_BombsAway.unk_02 = 0;
    D_8010D940_223D30_BombsAway.unk_06 = 900;
    D_8010DB18_223F08_BombsAway = D_8010DB1C_223F0C_BombsAway = D_8010DB20_223F10_BombsAway = 0;
    D_8010E550_224940_BombsAway = 1;
    D_8010DB10_223F00_BombsAway = D_8010DB14_223F04_BombsAway = 0;
    p = D_8010D950_223D40_BombsAway;
    do {
        func_800B0EF0_B1AF0(p, 0, sizeof(BaPlayer));
        i++;
        p++;
    } while (i < 4);
    s = &D_8010DB28_223F18_BombsAway;
    func_800B0EF0_B1AF0(s, 0, sizeof(BaStage));
    func_800B37C0_B43C0(s->unk_50);
    func_800B37C0_B43C0(s->unk_90);
    func_800B37C0_B43C0(s->unk_D0);
    D_8010DC58_224048_BombsAway = 0; /* = D_8010DB28.unk_130: retail addresses it by its own label */
    /* Retail zeroes columns 1 and 2 of the eight rows unk_50[0..7] (unk_50 and unk_90: the
       identities just set lose their [1][1] and [2][2]) and each weight's x. Host: rows 4..7 are
       unk_90's, an out-of-bounds index of unk_50. */
    for (i = 0; i < 8; i++) {
        s->unk_134[i].unk_00 = s->unk_50[i][1] = s->unk_50[i][2] = 0.0f;
    }
    D_8010DCBC_2240AC_BombsAway = 0;
    for (i = 0; i < 6; i++) {
        D_8010DCBE_2240AE_BombsAway[i] = 0;
    }
    func_800B0EF0_B1AF0(D_8010DD00_2240F0_BombsAway, 0, sizeof(D_8010DD00_2240F0_BombsAway));
    D_8010DF18_224308_BombsAway = -1;
    func_800B0EF0_B1AF0(D_8010DEB8_2242A8_BombsAway, 0, sizeof(D_8010DEB8_2242A8_BombsAway));
    i = 0;
    func_80107918_21DD08_BombsAway();
    func_80102D54_219144_BombsAway();
    D_8010DB24_223F14_BombsAway = func_80018A30_19630(0x3B0005, 0x9D);
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_801060C8_21C4B8_BombsAway);
    omAddObj(20, 0, 0, -1, func_80102DB4_2191A4_BombsAway);
    omAddObj(8, 1, 0, -1, func_80107B28_21DF18_BombsAway);
    omAddObj(8, 1, 0, -1, func_80107B44_21DF34_BombsAway);
    for (; i < 9; i++) {
        D_8010DF20_224310_BombsAway[i] = -1;
    }
    i = 0;
    func_80104284_21A674_BombsAway();
    func_8007273C_7333C((u8*)"\202r\202s\202`\202q\202s", 1); /* "START" in full-width SJIS */
    data = DataRead(0x1001A);
    D_8010DF1A_22430A_BombsAway = SprAnimRead(data);
    DataClose(data);
    D_8010DEB0_2242A0_BombsAway = -1;
    D_8010DEB2_2242A2_BombsAway = 0;
    D_8010DEB4_2242A4_BombsAway = 0;
    D_8010DF1C_22430C_BombsAway = SprCreate(12, 0);
    do {
        SprAnimSet(D_8010DF1C_22430C_BombsAway, i, D_8010DF1A_22430A_BombsAway, 0);
        SprScaleSet(D_8010DF1C_22430C_BombsAway, i, 0.5f, 0.5f);
        func_80082488_83088(D_8010DF1C_22430C_BombsAway, i, 0x100);
        SprAttrSet(D_8010DF1C_22430C_BombsAway, i, 0x9000);
        func_8008225C_82E5C(D_8010DF1C_22430C_BombsAway, i, 0);
        D_8010DDC0_2241B0_BombsAway[i].unk_00 = D_8010DDC0_2241B0_BombsAway[i].unk_02 = 0;
        D_8010DDC0_2241B0_BombsAway[i].unk_04 = D_8010DDC0_2241B0_BombsAway[i].unk_08 =
            D_8010DDC0_2241B0_BombsAway[i].unk_0C = D_8010DDC0_2241B0_BombsAway[i].unk_10 = 0.0f;
        i++;
    } while (i < 12);
    func_80108F40_21F330_BombsAway();
}

void func_80102D54_219144_BombsAway(void) {
    D_8010274C_10334C.x = D_8010274C_10334C.y = D_8010274C_10334C.z = 0.0f;
    D_8010274C_10334C.y = 180.0f;
    D_800FD474_FE074.y = D_800FD474_FE074.z = 0.0f;
    D_800FD474_FE074.x = -21.0f;
    D_800FA610_FB210 = 1400.0f;
}

void func_80102DB4_2191A4_BombsAway(omObjData* obj) {
    obj->func_ptr = func_80102DDC_2191CC_BombsAway;
    omSetStatBit(obj, 0xA0);
}

void func_80102DDC_2191CC_BombsAway(omObjData* obj) {
    s32 chars[4];
    BaPlayer* p;
    s32 i;
    s32 out;
    s32 fallen;
    s32 flag;

    if (D_8010CC98_223088_BombsAway != 0) {
        if (D_8010CC98_223088_BombsAway == 1) {
            func_80109164_21F554_BombsAway();
            omOvlReturnEx(1);
        }
        D_8010CC98_223088_BombsAway--;
    } else if (D_801011FC_101DFC != 0 && D_8010D940_223D30_BombsAway.unk_00 != 2 && func_8008F618_90218() == 0) {
        D_8010CC98_223088_BombsAway = 20;
        InitFadeOut(0, (s16)D_8010CC98_223088_BombsAway);
        func_800794A8_7A0A8((s16)D_8010CC98_223088_BombsAway);
        func_80079614_7A214((s16)D_8010CC98_223088_BombsAway);
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    switch (D_8010D940_223D30_BombsAway.unk_00) {
    case 0:
        func_80108CFC_21F0EC_BombsAway(0);
        if (D_8010D940_223D30_BombsAway.unk_04 == 1) {
            PlaySound(0x4A2);
            InitFadeIn(0, 16);
        } else if (D_8010D940_223D30_BombsAway.unk_04 == 0x80) {
            func_800691FC_69DFC(0);
        } else if (D_8010D940_223D30_BombsAway.unk_04 == 70) {
            PlayMusic(0x1E);
        } else if (D_8010D940_223D30_BombsAway.unk_04 >= 180) {
            func_800691FC_69DFC(10, (s16)(D_8010D940_223D30_BombsAway.unk_06 / 30), 0xA0, 0x20);
            D_8010D940_223D30_BombsAway.unk_00 = 1;
            D_8010D940_223D30_BombsAway.unk_04 = -1;
            D_800F8FD0_F9BD0 = 1;
        }
        break;
    case 1:
        if (--D_8010D940_223D30_BombsAway.unk_06 >= 61) {
            func_80103508_2198F8_BombsAway();
        }
        func_80103BD4_219FC4_BombsAway();
        if ((D_8010DB14_223F04_BombsAway < 2 && D_8010D948_223D38_BombsAway == 0) ||
            D_8010D940_223D30_BombsAway.unk_06 <= 0 || D_8010D94A_223D3A_BombsAway != 0) {
            D_8010D940_223D30_BombsAway.unk_00 = 2;
            D_8010D940_223D30_BombsAway.unk_04 = -1;
            D_8010CC9C_22308C_BombsAway = 0;
            D_8010E550_224940_BombsAway = 0;
            func_8006D518_6E118();
        }
        break;
    case 2:
        switch (D_8010CC9C_22308C_BombsAway) {
        case 0:
            fallen = 0;
            out = 0;
            p = D_8010D950_223D40_BombsAway;
            for (i = 0; i < D_8010DB10_223F00_BombsAway; i++, p++) {
                if (p->unk_02 == 7) {
                    D_8010CC90_223080_BombsAway[out] = i;
                    out++;
                } else {
                    flag = p->unk_00 & 0x10;
                    fallen += flag != 0;
                }
            }
            if (out + fallen >= D_8010DB10_223F00_BombsAway) {
                D_8010DB14_223F04_BombsAway = out;
                if (D_8010D94A_223D3A_BombsAway == 0) {
                    for (i = 0; i < D_8010DB14_223F04_BombsAway; i++) {
                        gPlayers[D_8010CC90_223080_BombsAway[i]].coins_mg_bonus += 10;
                    }
                }
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(90);
                if (D_8010D948_223D38_BombsAway == 0) {
                    D_8010CC9C_22308C_BombsAway++;
                } else {
                    func_80079614_7A214(90);
                    D_8010D940_223D30_BombsAway.unk_00 = 3;
                    D_8010CC9C_22308C_BombsAway = 60;
                }
                D_8010D940_223D30_BombsAway.unk_04 = -1;
            }
            break;
        case 1:
            if (func_80069538_6A138() == 2) {
                for (i = 0; i < D_8010DB14_223F04_BombsAway; i++) {
                    func_800732B0_73EB0(D_8010DF38_224328_BombsAway[D_8010CC90_223080_BombsAway[i]].unk_00);
                    chars[i] = gPlayers[D_8010CC90_223080_BombsAway[i]].character;
                }
                switch (D_8010DB14_223F04_BombsAway) {
                case 1:
                    func_800691FC_69DFC(6, chars[0]);
                    D_8010CC9C_22308C_BombsAway = 120;
                    PlayMusic(0x51);
                    break;
                case 2:
                    func_800691FC_69DFC(0x11, chars[0], chars[1]);
                    D_8010CC9C_22308C_BombsAway = 168;
                    PlayMusic(0x52);
                    break;
                case 3:
                    func_800691FC_69DFC(0x15, chars[0], chars[1], chars[2]);
                    D_8010CC9C_22308C_BombsAway = 168;
                    PlayMusic(0x52);
                    break;
                case 4:
                    func_800691FC_69DFC(0x16, chars[0], chars[1], chars[2], chars[3]);
                    D_8010CC9C_22308C_BombsAway = 168;
                    PlayMusic(0x52);
                    break;
                default:
                    func_800691FC_69DFC(0x13);
                    D_8010CC9C_22308C_BombsAway = 120;
                    PlayMusic(0x57);
                    break;
                }
                D_8010D940_223D30_BombsAway.unk_00 = 3;
                D_8010D940_223D30_BombsAway.unk_04 = -1;
            }
            break;
        }
        break;
    case 3:
        D_800F8FD0_F9BD0 = 2;
        if (D_8010CC9C_22308C_BombsAway <= 0) {
            InitFadeOut(0, 20);
            obj->func_ptr = func_801034B0_2198A0_BombsAway;
        } else {
            D_8010CC9C_22308C_BombsAway--;
        }
        break;
    }
    if (++D_8010D940_223D30_BombsAway.unk_04 >= 0x7800) {
        D_8010D940_223D30_BombsAway.unk_04 -= 0x800;
    }
    if (D_8010D940_223D30_BombsAway.unk_06 >= 0) {
        func_8006D4D0_6E0D0((D_8010D940_223D30_BombsAway.unk_06 + 29) / 30);
    }
    func_801082EC_21E6DC_BombsAway();
    if (D_8010DCBC_2240AC_BombsAway != 0) {
        D_8010DCBC_2240AC_BombsAway--;
    }
}

void func_801034B0_2198A0_BombsAway(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        func_801034E4_2198D4_BombsAway();
        omOvlReturnEx(1);
    }
}

void func_801034E4_2198D4_BombsAway(void) {
    func_80079464_7A064();
    func_80109164_21F554_BombsAway();
}

/* The cannon's schedule (MP1 func_800F723C, now driven by the D_8010CF5C firing patterns): ages
   the landing marks, steps the pattern, and on a shot fires a bomb of the pattern's kind at a
   random point around the platform and adds its landing mark.
   NON_MATCHING: masked 10; newest/newestIdx swap s2/s3, the mark loop hoists newest's extension,
   and one mul-fix nop before the cos product. */
#ifdef NON_MATCHING
void func_80103508_2198F8_BombsAway(void) {
    BaPattern* pat;
    s32 kind;
    s32 i;
    s16 newest;
    s16 newestIdx;
    f32 x;
    f32 z;
    f32 angle;
    f32 dist;

    kind = 0;
    newestIdx = -1;
    newest = -1;
    for (i = 0; i < 8; i++) {
        if (D_8010DEB8_2242A8_BombsAway[i].unk_00 != 0) {
            D_8010DEB8_2242A8_BombsAway[i].unk_00++;
            D_8010DEB8_2242A8_BombsAway[i].unk_02--;
            if (newest < D_8010DEB8_2242A8_BombsAway[i].unk_00) {
                newest = D_8010DEB8_2242A8_BombsAway[i].unk_00;
                newestIdx = i;
            }
        }
    }
    D_8010DF18_224308_BombsAway = newestIdx;
    pat = D_8010CF5C_22334C_BombsAway[D_8010DB1C_223F0C_BombsAway];
    if (D_8010DB1C_223F0C_BombsAway == 0) {
        func_8010392C_219D1C_BombsAway();
        func_80103AC8_219EB8_BombsAway(D_8010CF5C_22334C_BombsAway, 1, 7);
        D_8010DB1C_223F0C_BombsAway++;
    } else if (D_8010DB18_223F08_BombsAway < pat->unk_08) {
        if (pat->unk_60 < pat->unk_5C && D_8010DB18_223F08_BombsAway >= pat->unk_0C[pat->unk_60]) {
            kind = pat->unk_00;
            pat->unk_60++;
        }
        D_8010DB18_223F08_BombsAway++;
    } else {
        D_8010DB1C_223F0C_BombsAway++;
        D_8010DB18_223F08_BombsAway = 0;
    }
    if (kind == 0) {
        goto end;
    }
    switch (kind) {
    case 1:
        if ((rand8() & 7) == 0) {
            dist = (s32)((u32)(BA_RAND16() * 25) >> 13);
        } else {
            dist = (s32)((u32)(BA_RAND16() * 25) >> 14) + 550.0;
        }
        break;
    case 2:
        dist = (s32)((u32)(BA_RAND16() * 25) >> 13);
        break;
    default:
        dist = (BA_RAND16() * 45) >> 14;
        break;
    }
    angle = (BA_RAND16() * 45) >> 13;
    x = D_8010DB28_223F18_BombsAway.unk_38.x + func_800B7890_B8490(angle) * dist;
    z = D_8010DB28_223F18_BombsAway.unk_38.z + HuMathSin(angle) * dist;
    func_8010B6FC_221AEC_BombsAway(x, z, D_8010CF84_223374_BombsAway[kind], kind);
    for (i = 0; i < 8; i++) {
        if (D_8010DEB8_2242A8_BombsAway[i].unk_00 == 0) {
            D_8010DEB8_2242A8_BombsAway[i].unk_00 = 1;
            D_8010DEB8_2242A8_BombsAway[i].unk_02 = (D_8010CF94_223384_BombsAway + kind)->unk_02;
            D_8010DEB8_2242A8_BombsAway[i].unk_04 = x;
            D_8010DEB8_2242A8_BombsAway[i].unk_08 = z;
            if (newest < D_8010DEB8_2242A8_BombsAway[i].unk_00) {
                newestIdx = i;
            }
            break;
        }
    }
end:
    D_8010DF18_224308_BombsAway = newestIdx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80103508_2198F8_BombsAway);
#endif

void func_8010392C_219D1C_BombsAway(void) {
    BaPattern* pat;
    s32 i;

    pat = &D_8010CCA0_223090_BombsAway;
    D_8010CCAC_22309C_BombsAway = 0; /* = pat->unk_0C[0]: retail addresses it by its own label */
    for (i = 1; i < 20; i++) {
        pat->unk_0C[i] = rand8() % 30 + 30.0 + pat->unk_0C[i - 1];
        if (pat->unk_0C[i] >= 105.0) {
            break;
        }
        pat->unk_5C = i;
    }

    pat = &D_8010CD04_2230F4_BombsAway;
    D_8010CD10_223100_BombsAway = 0; /* = pat->unk_0C[0]: retail addresses it by its own label */
    for (i = 1; i < 20; i++) {
        pat->unk_0C[i] = rand8() % 30 + 30.0 + pat->unk_0C[i - 1];
        if (pat->unk_0C[i] >= 105.0) {
            break;
        }
        pat->unk_5C = i;
    }
}

void func_80103AC8_219EB8_BombsAway(BaPattern** list, s32 lo, s32 hi) {
    s32 n;
    s32 range;
    s32 a;
    s32 b;
    BaPattern* tmp;

    n = rand8() + 50;
    range = hi - lo;
    for (; n > 0; n--) {
        a = rand8() % range + lo;
        if (rand8() & 1) {
            b = a + 1;
        } else {
            b = a - 1;
        }
        if (b < lo) {
            b = hi - 1;
        } else if (b > hi - 1) {
            b = lo;
        }
        tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
}

/* Ages the blasts and knocks down every standing player inside one (sphere, or a column whose
   height falls off with distance: func_80103F10).
   NON_MATCHING: masked 0; one register (the (radius + blast radius) sum lands in f4, retail f0). */
#ifdef NON_MATCHING
void func_80103BD4_219FC4_BombsAway(void) {
    s16 ids[8];
    Vec pos;
    s16 n;
    s32 i;
    s32 j;
    BaPlayer* p;
    omObjData* obj;
    BaShock* w;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 r;
    f32 rr;
    f32 d;
    f32 t;

    n = 0;
    for (i = 0; i < 8; i++) {
        if (D_8010DD00_2240F0_BombsAway[i].unk_00 != 0) {
            D_8010DD00_2240F0_BombsAway[i].unk_00--;
            if (D_8010DD00_2240F0_BombsAway[i].unk_00 != 0) {
                pos.x = D_8010DD00_2240F0_BombsAway[i].unk_04;
                pos.y = D_8010DD00_2240F0_BombsAway[i].unk_08;
                pos.z = D_8010DD00_2240F0_BombsAway[i].unk_0C;
                func_80107060_21D450_BombsAway(&pos, &pos);
                D_8010DD00_2240F0_BombsAway[i].unk_08 = pos.y;
            }
            ids[n] = i;
            n++;
        }
    }
    if (n != 0) {
        for (i = 0; i < D_8010DB10_223F00_BombsAway; i++) {
            p = &D_8010D950_223D40_BombsAway[i];
            if (p->unk_00 & 2) {
                continue;
            }
            obj = p->unk_48;
            x = obj->trans.x;
            y = obj->trans.y + p->unk_08;
            z = obj->trans.z;
            for (j = 0; j < n; j++) {
                w = &D_8010DD00_2240F0_BombsAway[ids[j]];
                dx = x - w->unk_04;
                dy = y - w->unk_08;
                dz = z - w->unk_0C;
                rr = p->unk_08;
                rr += r = w->unk_10;
                rr *= rr;
                if (w->unk_14 != 0) {
                    d = dx * dx + dz * dz;
                    if (r > 150.0) {
                        r = 150.0f;
                    }
                    if (d < rr && r + w->unk_08 > obj->trans.y) {
                        t = d - p->unk_08;
                        if (t < 0.0) {
                            t = 0.0f;
                        }
                        if (func_80103F10_21A300_BombsAway(w->unk_10, r, t) + w->unk_08 > obj->trans.y) {
                            break;
                        }
                    }
                } else {
                    d = dx * dx + dy * dy + dz * dz;
                    if (d < rr) {
                        break;
                    }
                }
            }
            if (j < n) {
                p->unk_00 |= 2;
                p->unk_05 = 1;
                p->unk_02 = 9;
                p->unk_3C = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80103BD4_219FC4_BombsAway);
#endif

/* Height of a blast column of radius r and height h at squared distance d (an ellipse).
   NON_MATCHING: only the KMC mul-fix nop after the sqrtf call (retail has one before the final
   mul.s; GCC's output has no blank line between the jal and the mul.s, so KMC as adds none). */
#ifdef NON_MATCHING
f32 func_80103F10_21A300_BombsAway(f32 r, f32 h, f32 d) {
    if (d < 0.0) {
        d = -d;
    }
    if (r < d) {
        return 0.0f;
    }
    d /= r;
    d = 1.0 - d * d;
    return sqrtf(d) * h;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80103F10_21A300_BombsAway);
#endif

void func_80103FC4_21A3B4_BombsAway(s16 time, f32 x, f32 y, f32 z, f32 radius, u16 column) {
    s32 i;

    /* Retail fills every free slot, not just the first. */
    for (i = 0; i < 8; i++) {
        if (D_8010DD00_2240F0_BombsAway[i].unk_00 == 0) {
            D_8010DD00_2240F0_BombsAway[i].unk_00 = time;
            D_8010DD00_2240F0_BombsAway[i].unk_04 = x;
            D_8010DD00_2240F0_BombsAway[i].unk_08 = y;
            D_8010DD00_2240F0_BombsAway[i].unk_0C = z;
            D_8010DD00_2240F0_BombsAway[i].unk_10 = radius;
            D_8010DD00_2240F0_BombsAway[i].unk_14 = column;
        }
    }
}

BaPlayer* func_80104058_21A448_BombsAway(omObjData* obj) {
    BaPlayer* p = D_8010D950_223D40_BombsAway;
    s32 i;

    for (i = 0; i < D_8010DB10_223F00_BombsAway; i++, p++) {
        if (p->unk_48 == obj) {
            break;
        }
    }
    return p;
}

void func_801040A0_21A490_BombsAway(omObjData* obj, s32 motion) {
    s16 cur = func_80018FF0_19BF0(obj);
    BaPlayer* p = func_80104058_21A448_BombsAway(obj);
    u8 idx;

    if (p->unk_36 != cur && p->unk_38 != cur) {
        if (p->unk_34 != 0) {
            p->unk_38 = cur;
        } else {
            p->unk_36 = cur;
        }
        p->unk_34 = 1 - p->unk_34;
    }
    idx = obj->model[0];
    if (func_80019B70_1A770(obj, motion) != 0) {
        D_800FC834_FD434[idx].unk03 |= 2;
    } else {
        D_800FC834_FD434[idx].unk03 &= ~2;
    }
    func_80019B9C_1A79C(obj, (u8)motion);
}

void func_80104198_21A588_BombsAway(omObjData* obj, s32 m1, s32 m2) {
    BaPlayer* p;
    s32 i;

    if (func_80019B70_1A770(obj, m1) != 0 || func_80019B70_1A770(obj, m2) != 0) {
        p = func_80104058_21A448_BombsAway(obj);
        for (i = 0; i < obj->mtncnt; i++) {
            if (obj->motion[i] == -1) {
                continue;
            }
            if (i == (u8)m1) {
                continue;
            }
            if (i == (u8)m2) {
                continue;
            }
            if (i == p->unk_36) {
                continue;
            }
            if (i == p->unk_38) {
                continue;
            }
            func_800283DC_28FDC(obj->motion[i]);
            obj->motion[i] = -1;
            return;
        }
    }
}

void func_80104284_21A674_BombsAway(void) {
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(4, 9, 0x3C, -1, func_801043A8_21A798_BombsAway);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 9, 0x3C, -1, func_801043C4_21A7B4_BombsAway);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(6, 9, 0x3C, -1, func_801043E0_21A7D0_BombsAway);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(7, 9, 0x3C, -1, func_801043FC_21A7EC_BombsAway);
}

void func_801043A8_21A798_BombsAway(omObjData* obj) {
    func_8010488C_21AC7C_BombsAway(obj, 0);
}

void func_801043C4_21A7B4_BombsAway(omObjData* obj) {
    func_8010488C_21AC7C_BombsAway(obj, 1);
}

void func_801043E0_21A7D0_BombsAway(omObjData* obj) {
    func_8010488C_21AC7C_BombsAway(obj, 2);
}

void func_801043FC_21A7EC_BombsAway(omObjData* obj) {
    func_8010488C_21AC7C_BombsAway(obj, 3);
}

/* A player's object each frame (MP1 func_800F7C94): moves it (pad/CPU or scripted), keeps it on
   the platform, and detects falls, ring-outs and corner slots at the finish.
   NON_MATCHING: masked 0; p and the ground work swap s0/s1 (as in MP1). */
#ifdef NON_MATCHING
void func_80104418_21A808_BombsAway(omObjData* obj) {
    Vec pos;
    Vec vel;
    BaGroundWork* gw;
    BaPlayer* p;
    BaPlayerWork* w;
    f32 groundY;
    s16 model;
    s32 corner;
    s32 j;

    p = func_80104058_21A448_BombsAway(obj);
    if (!(p->unk_00 & 0x80)) {
        p->unk_00 |= 0x80;
        return;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    gw = D_800FC7B0_FD3B0[0]->unk_50;
    if (func_80107060_21D450_BombsAway(&pos, &vel) != 0) {
        gw->unk_14 = groundY = vel.y;
        if (vel.y > obj->trans.y) {
            obj->trans.y = vel.y;
        }
    } else {
        gw->unk_14 = groundY = -200.0f;
    }
    if (p->unk_05 == 0) {
        w = obj->unk_50;
        if ((gPlayers[w->unk_59].flags & 1) || D_8010D940_223D30_BombsAway.unk_00 != 1) {
            func_80104CD0_21B0C0_BombsAway(obj);
        }
        func_80007790_8390(obj);
        vel.x = p->unk_0C = obj->trans.x - pos.x;
        vel.y = p->unk_10 = obj->trans.y - pos.y;
        vel.z = p->unk_14 = obj->trans.z - pos.z;
        if (D_8010D940_223D30_BombsAway.unk_00 == 1) {
            vel.y -= 30.0;
        }
    } else {
        func_801055FC_21B9EC_BombsAway(obj);
        vel.x = p->unk_0C;
        vel.y = p->unk_10;
        vel.z = p->unk_14;
    }
    p->unk_6A = 0;
    if (!(p->unk_00 & 2)) {
        w = obj->unk_50;
        if (!(w->unk_5C & 0x220) || (w->unk_50 & 0x80)) {
            func_8010714C_21D53C_BombsAway(&pos, &vel, &pos, 1);
            if (func_80106FC8_21D3B8_BombsAway(&pos) == 0) {
                goto fall;
            }
            obj->trans.x = pos.x;
            obj->trans.y = pos.y;
            obj->trans.z = pos.z;
            func_8010770C_21DAFC_BombsAway(pos.x, pos.z, -1.0f);
            if (p->unk_05 == 0 && D_8010D940_223D30_BombsAway.unk_00 == 2) {
                p->unk_05 = 1;
                p->unk_02 = 7;
                corner = 0;
                if (pos.z < D_8010DB28_223F18_BombsAway.unk_38.z) {
                    corner = 1;
                }
                if (pos.x < D_8010DB28_223F18_BombsAway.unk_38.x) {
                    corner |= 2;
                }
                corner++;
                D_8010DCBE_2240AE_BombsAway[corner] |= 1;
            } else if (D_8010DB28_223F18_BombsAway.unk_2C != 0 && D_8010D940_223D30_BombsAway.unk_00 == 1) {
                p->unk_05 = 1;
                p->unk_02 = 3;
                p->unk_3C = 0;
            }
            if (D_8010DCBC_2240AC_BombsAway == 1) {
                omVibrate(p->unk_06, 2, 3, 10);
            }
        } else {
            func_8010714C_21D53C_BombsAway(&pos, &vel, &pos, 0);
            if (func_80106FC8_21D3B8_BombsAway(&pos) <= 0 && pos.y < 0.0) {
            fall:
                p->unk_00 |= 2;
                p->unk_05 = 1;
                p->unk_02 = 5;
                p->unk_3C = 0;
            } else if (D_8010D940_223D30_BombsAway.unk_00 == 2 && D_8010D940_223D30_BombsAway.unk_04 >= 8) {
                if (!(D_8010D940_223D30_BombsAway.unk_04 & 7)) {
                    for (j = 1; j < 5; j++) {
                        if (!(D_8010DCBE_2240AE_BombsAway[j] & 1)) {
                            break;
                        }
                    }
                    p->unk_68 = j;
                    D_8010DCBE_2240AE_BombsAway[j] |= 2;
                }
                p->unk_6A = 1;
            }
        }
    }
    model = obj->model[1];
    func_80029714_2A314(model, obj->trans.x, groundY, obj->trans.z);
    func_8002979C_2A39C(model, D_8010DB28_223F18_BombsAway.unk_44.x, D_8010DB28_223F18_BombsAway.unk_44.y,
                        D_8010DB28_223F18_BombsAway.unk_44.z);
    if (p->unk_00 & 2) {
        func_800298A4_2A4A4(model, 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80104418_21A808_BombsAway);
#endif

void func_8010488C_21AC7C_BombsAway(omObjData* obj, s16 player) {
    f32 startX[] = { -3.0f, -1.0f, 1.0f, 3.0f };
    s32 waitMotions[] = { 0x4E, 0x4F };
    BaPlayer* p;
    BaPlayerWork* w;
    s32 dir;
    s32 file;
    u8 chr;
    s32 r;
    s32 pad[2]; /* unused: retail's frame is 8 bytes larger */

    D_8010DB14_223F04_BombsAway = ++D_8010DB10_223F00_BombsAway;
    chr = gPlayers[player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    func_8000C460_D060();
    func_8000C6FC_D2FC(obj, dir, file, player, 0x2B9, 0x289);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 15.0f, 0.0f);
    func_8000C2A0_CEA0(obj, 2, 0x10, 0x289, 0);
    if (D_8010DF20_224310_BombsAway[3] < 0) {
        obj->model[3] = D_8010DF20_224310_BombsAway[3] = LoadFormFile(7, 0x68D);
        obj->model[4] = D_8010DF20_224310_BombsAway[4] = LoadFormFile(8, 0x68D);
        obj->model[5] = D_8010DF20_224310_BombsAway[5] = LoadFormFile(10, 0x68D);
    } else {
        obj->model[3] = func_80027D3C_2893C(D_8010DF20_224310_BombsAway[3]);
        obj->model[4] = func_80027D3C_2893C(D_8010DF20_224310_BombsAway[4]);
        obj->model[5] = func_80027D3C_2893C(D_8010DF20_224310_BombsAway[5]);
    }
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 2, 1, 0);
    func_80019E84_1AA84(obj, 6, dir | 4, 1, 0x13);
    func_80019E84_1AA84(obj, 15, dir | 0xA, 1, 0);
    func_80019E84_1AA84(obj, 16, dir | 0xE, 1, 0);
    func_80019E84_1AA84(obj, 17, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 21, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 11, dir | 8, 1, 0);
    r = BA_RAND16() >> 15;
    func_80019E84_1AA84(obj, 13, dir | waitMotions[r], 1, 999);
    D_8010DF38_224328_BombsAway[player].unk_00 = dir | waitMotions[r];
    obj->func_ptr = func_80104418_21A808_BombsAway;
    omSetTra(obj, startX[player] * 100.0, 160.0f, 700.0f);
    func_8000C024_CC24(obj, 0, 2);
    w = obj->unk_50;
    w->unk_50 = 0;
    w->unk_57 = gPlayers[player].port;
    func_800298A4_2A4A4(obj->model[3], 4, 4);
    func_800298A4_2A4A4(obj->model[4], 4, 4);
    p = &D_8010D950_223D40_BombsAway[player];
    p->unk_48 = obj;
    p->unk_00 = 1;
    p->unk_05 = 0;
    p->unk_06 = player;
    p->unk_08 = 50.0f;
    p->unk_44 = 12;
    p->unk_46 = -1;
}

/* CPU control of a player (MP1 func_800F8538): picks a target near the platform (away from the
   newest landing mark, or a corner slot at the finish), presses A to jump, and writes the pad.
   NON_MATCHING: same code, but obj/diff/move/the stage base permute s1/s3/s4/s5, and KMC adds a
   mul-fix nop after the cos call for unk_58 (retail has none). */
#ifdef NON_MATCHING
void func_80104CD0_21B0C0_BombsAway(omObjData* obj) {
    BaPlayer* p;
    s32 port;
    s16 move;
    s32 diff;
    f32 dx;
    f32 dz;
    f32 ang;
    f32 r;
    s32 stick;
    s32 pad;

    p = func_80104058_21A448_BombsAway(obj);
    port = gPlayers[p->unk_06].port;
    diff = gPlayers[p->unk_06].cpu_difficulty;
    move = 0;
    if (D_8010DB28_223F18_BombsAway.unk_1C != 0.0) {
        move = 1;
    }
    if (D_8010DB28_223F18_BombsAway.unk_1C > 0.75) {
        if (!(D_8010D940_223D30_BombsAway.unk_04 & 7)) {
            p->unk_58 = (s32)((u32)(BA_RAND16() * 25) >> 13) + D_8010DB28_223F18_BombsAway.unk_38.x;
            p->unk_60 = (s32)((u32)(BA_RAND16() * 25) >> 13) + D_8010DB28_223F18_BombsAway.unk_38.z;
        }
    } else if (D_8010DF18_224308_BombsAway >= 0) {
        move = 1;
        dx = D_8010DB28_223F18_BombsAway.unk_38.x - D_8010DEB8_2242A8_BombsAway[D_8010DF18_224308_BombsAway].unk_04;
        dz = D_8010DB28_223F18_BombsAway.unk_38.z - D_8010DEB8_2242A8_BombsAway[D_8010DF18_224308_BombsAway].unk_08;
        if (D_8010DEB8_2242A8_BombsAway[D_8010DF18_224308_BombsAway].unk_02 < 2) {
            if ((s32)((u32)(BA_RAND16() * 25) >> 14) < 18 - diff * 5) {
                p->unk_54 = 1;
            } else if (dx * dx + dz * dz < 160000.0 && (s32)((u32)(BA_RAND16() * 25) >> 14) < diff * 20 + 20) {
                p->unk_54 = 1;
            }
        }
        if (!((D_8010DEB8_2242A8_BombsAway[D_8010DF18_224308_BombsAway].unk_00 + p->unk_3E) & 0xF)) {
            ang = func_80108A4C_21EE3C_BombsAway(dx, dz);
            ang += (((BA_RAND16() * 15) >> 13) - 60);
            if (ang >= 360.0f) {
                ang -= 360.0f;
            } else if (ang < 0.0f) {
                ang += 360.0f;
            }
            dx = D_8010DB28_223F18_BombsAway.unk_38.x + func_800B7890_B8490(ang) * 2.0 * 100.0;
            dz = D_8010DB28_223F18_BombsAway.unk_38.z + HuMathSin(ang) * 1.5 * 100.0;
            ang = (BA_RAND16() * 45) >> 13;
            r = ((BA_RAND16() * (s32)((2.5 - diff * 0.5) * 100.0)) >> 16) + 30.0;
            p->unk_58 = dx + func_800B7890_B8490(ang) * r;
            p->unk_60 = dz + HuMathSin(ang) * r * 0.8;
        }
    }
    if (D_8010DB28_223F18_BombsAway.unk_2C != 0) {
        if ((s32)((u32)(BA_RAND16() * 25) >> 14) < diff * 10 + 60) {
            p->unk_54 = 1;
        }
    }
    if (p->unk_6A != 0) {
        move = 1;
        p->unk_58 = D_8010DB28_223F18_BombsAway.unk_38.x + D_8010CFA4_223394_BombsAway[p->unk_68][0];
        p->unk_60 = D_8010DB28_223F18_BombsAway.unk_38.z + D_8010CFA4_223394_BombsAway[p->unk_68][1];
    }
    /* New in MP2: a CPU 400 or more from the platform's centre heads back to it at full tilt. */
    if (move != 0) {
        dx = D_8010DB28_223F18_BombsAway.unk_38.x - obj->trans.x;
        dz = D_8010DB28_223F18_BombsAway.unk_38.z - obj->trans.z;
        if (sqrtf(dx * dx + dz * dz) >= 400.0) {
            p->unk_4C = func_80108A4C_21EE3C_BombsAway(dx, -dz) + 90.0;
            p->unk_50 = 1.0f;
        } else {
            dx = p->unk_58 - obj->trans.x;
            dz = p->unk_60 - obj->trans.z;
            p->unk_4C = func_80108A4C_21EE3C_BombsAway(dx, -dz) + 90.0;
            if (p->unk_4C >= 360.0) {
                p->unk_4C -= 360.0;
            }
            p->unk_50 = sqrtf(dx * dx + dz * dz) / 150.0;
            if (p->unk_50 < 0.2) {
                p->unk_50 = 0.0f;
            }
            if (p->unk_50 > 1.0) {
                p->unk_50 = 1.0f;
            }
        }
    } else {
        dx = D_8010DB28_223F18_BombsAway.unk_38.x - obj->trans.x;
        dz = D_8010DB28_223F18_BombsAway.unk_38.z - obj->trans.z;
        if (sqrtf(dx * dx + dz * dz) >= 400.0) {
            p->unk_4C = func_80108A4C_21EE3C_BombsAway(dx, -dz) + 90.0;
            p->unk_50 = 1.0f;
        } else {
            p->unk_50 = 0.0f;
        }
    }
    ContBtn[port] &= 0x1030;
    ContBtnTrg[port] &= 0x1030;
    if (D_8010D940_223D30_BombsAway.unk_00 == 1 || p->unk_6A != 0) {
        if (p->unk_54 != 0) {
            ContBtnTrg[port] |= 0x8000;
        }
        pad = port;
        ContBtn[pad] = ContBtnTrg[pad];
        stick = HuMathSin(p->unk_4C) * p->unk_50 * 64.0f;
        D_800FC9BE_FD5BE[pad] = stick;
        ContStkX[pad] = stick;
        stick = -func_800B7890_B8490(p->unk_4C) * p->unk_50 * 64.0f;
        D_800FD468_FE068[pad] = stick;
        ContStkY[pad] = stick;
    } else {
        pad = port;
        D_800FC9BE_FD5BE[pad] = 0;
        ContStkX[pad] = 0;
        D_800FD468_FE068[pad] = 0;
        ContStkY[pad] = 0;
    }
    p->unk_54 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80104CD0_21B0C0_BombsAway);
#endif

/* A player's scripted states (MP1 func_800F8D48): 3 stunned, 5 falling into the sea and swept
   back to the edge, 6 out, 7 placed for the results, 9 thrown by a blast. New in MP2: the splash
   voice plays once (unk_42), and the results no longer add 10 coins.
   NON_MATCHING: only KMC's mul-fix nop after the cos and sin calls in case 9 (retail has none). */
#ifdef NON_MATCHING
void func_801055FC_21B9EC_BombsAway(omObjData* obj) {
    Vec d;
    Vec pos;
    Vec vel;
    Matrix4f m1;
    Matrix4f m2;
    BaPlayer* p;
    f32 ang;
    f32 t;
    s16 n;

    p = func_80104058_21A448_BombsAway(obj);
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    vel.x = p->unk_0C;
    vel.y = p->unk_10;
    vel.z = p->unk_14;
    switch (p->unk_02) {
        case 0:
            func_801040A0_21A490_BombsAway(obj, 0);
            if (p->unk_46 >= 0) {
                func_80079848_7A448(p->unk_46);
            }
            p->unk_46 = -1;
            break;
        case 3:
            if (p->unk_3C == 0) {
                p->unk_3A = 0;
                p->unk_3C++;
                omVibrate(p->unk_06, 20, 0, 20);
            }
            func_801040A0_21A490_BombsAway(obj, 11);
            vel.x = vel.z = 0.0f;
            vel.y = -20.0f;
            if (p->unk_3A >= 16) {
                p->unk_05 = 0;
                p->unk_02 = 0;
                if (p->unk_46 >= 0) {
                    func_80079848_7A448(p->unk_46);
                }
                p->unk_46 = -1;
            }
            break;
        case 5:
            ang = func_80106D78_21D168_BombsAway(&pos);
            d.x = func_800B7890_B8490(ang) * 5.5 * 100.0 + D_8010DB60_223F50_BombsAway.x - pos.x;
            d.z = HuMathSin(ang) * 4.5 * 100.0 + D_8010DB60_223F50_BombsAway.z - pos.z;
            func_80108A4C_21EE3C_BombsAway(d.x, d.z);
            sqrtf(d.x * d.x + d.z * d.z);
            switch (p->unk_3C) {
                case 0:
                    p->unk_00 |= 8;
                    vel.y = p->unk_30 = -5.0f;
                    vel.x = vel.z = 0.0f;
                    D_8010DB14_223F04_BombsAway--;
                    p->unk_00 |= 2;
                    if (p->unk_46 >= 0) {
                        func_80079848_7A448(p->unk_46);
                    }
                    p->unk_46 = -1;
                    p->unk_3E = 0;
                    p->unk_3A = 0;
                    p->unk_3C++;
                    break;
                case 1:
                    func_801040A0_21A490_BombsAway(obj, 16);
                    if (p->unk_3E == 0 && pos.y < 0.0) {
                        if (p->unk_42 == 0) {
                            func_80108E98_21F288_BombsAway(func_800797DC_7A3DC(0x111, p->unk_06), &pos);
                            p->unk_42 = 1;
                        }
                        func_8010A198_220588_BombsAway(pos.x, pos.y, pos.z, 0.75f);
                        p->unk_00 |= 0x10;
                        if (D_8010D948_223D38_BombsAway != 0 && gPlayers[p->unk_06].group == 0) {
                            D_8010D94A_223D3A_BombsAway = 1;
                        }
                        p->unk_3E++;
                    }
                    if (vel.y > -50.0) {
                        vel.y += p->unk_30;
                    }
                    ang = (f32)p->unk_3A / 15.0;
                    if (ang > 1.0) {
                        ang = 1.0f;
                    }
                    vel.x = d.x * 0.1 * ang;
                    vel.z = d.z * 0.1 * ang;
                    if (pos.y < -100.0) {
                        p->unk_3C++;
                    }
                    break;
                case 2:
                    func_801040A0_21A490_BombsAway(obj, 16);
                    if (pos.y + vel.y > -50.0) {
                        pos.y = -50.0f;
                        vel.y = 0.0f;
                        p->unk_3C++;
                        func_80107A34_21DE24_BombsAway(obj);
                    } else {
                        vel.y -= p->unk_30;
                    }
                    ang = (f32)p->unk_3A / 15.0;
                    if (ang > 1.0) {
                        ang = 1.0f;
                    }
                    vel.x = d.x * 0.1 * ang;
                    vel.z = d.z * 0.1 * ang;
                    break;
                case 3:
                case 4:
                    vel.x = d.x * 0.1;
                    vel.z = d.z * 0.1;
                    vel.y = 0.0f;
                    pos.y = -50.0f;
                    if (p->unk_3C == 4) {
                        vel.x = vel.z = vel.y;
                        p->unk_02 = 6;
                        func_801040A0_21A490_BombsAway(obj, 15);
                        guMtxIdentF((f32(*)[4])D_800FC834_FD434[obj->model[0]].mtx);
                        p->unk_3C = 0;
                    }
                    break;
            }
            pos.x += vel.x;
            pos.y += vel.y;
            pos.z += vel.z;
            if (p->unk_3C >= 3) {
                func_80104198_21A588_BombsAway(obj, 15, 16);
            }
            break;
        case 6:
            if (p->unk_3C != 0) {
                D_800FC834_FD434[obj->model[0]].unk03 |= 1;
                func_800298A4_2A4A4(obj->model[0], 4, 4);
            }
            func_80104198_21A588_BombsAway(obj, 15, 16);
            break;
        case 7:
            if (p->unk_46 >= 0) {
                func_80079848_7A448(p->unk_46);
            }
            p->unk_46 = -1;
            func_80107060_21D450_BombsAway(&obj->trans, &obj->trans);
            obj->rot.y = 0.0f;
            guMtxIdentF((f32(*)[4])D_800FC834_FD434[obj->model[0]].mtx);
            vel.x = vel.y = vel.z = 0.0f;
            D_800FC834_FD434[obj->model[1]].pos.y = obj->trans.y;
            if (D_8010D940_223D30_BombsAway.unk_00 != 3) {
                func_801040A0_21A490_BombsAway(obj, 0);
            } else if (D_8010D948_223D38_BombsAway == 0) {
                func_801040A0_21A490_BombsAway(obj, 13);
                p->unk_44 = 0;
            } else {
                func_801040A0_21A490_BombsAway(obj, 0);
                p->unk_44 = 0;
            }
            break;
        case 9:
            if (p->unk_3C == 0) {
                p->unk_00 |= 2;
                func_801040A0_21A490_BombsAway(obj, 11);
                if (p->unk_46 >= 0) {
                    func_80079848_7A448(p->unk_46);
                }
                p->unk_46 = -1;
                ang = func_80106D78_21D168_BombsAway(&pos);
                t = (600.0 - func_80106DB0_21D1A0_BombsAway(&pos)) / 30.0;
                vel.x = func_800B7890_B8490(ang) * t;
                vel.y = 60.0f;
                vel.z = HuMathSin(ang) * t;
                p->unk_30 = -4.0f;
                p->unk_3E = ang;
                p->unk_3C++;
                p->unk_3A = 0;
                func_80108E98_21F288_BombsAway(func_800797DC_7A3DC(0x111, p->unk_06), &pos);
                p->unk_42 = 1;
                omVibrate(p->unk_06, 30, 0, 30);
                if (D_8010DEB4_2242A4_BombsAway == 0) {
                    func_80079798_7A398(0x290, p->unk_06);
                    D_8010DEB4_2242A4_BombsAway = 10;
                }
            }
            vel.y += p->unk_30;
            pos.x += vel.x;
            pos.y += vel.y;
            pos.z += vel.z;
            n = p->unk_3A;
            if (n >= 7) {
                p->unk_3A = n - 6;
            }
            func_800B37C0_B43C0(m1);
            func_800B1CC0_B28C0(m1, p->unk_3A * 60.0f, 0.0f, 1.0f, 0.0f);
            m1[3][3] = 1.0f;
            func_80108ACC_21EEBC_BombsAway(&vel, &d);
            func_800B37C0_B43C0(m2);
            func_800B2060_B2C60(m2, d.x + 90.0f, d.y, d.z);
            m2[3][3] = 1.0f;
            func_800B6410_B7010(m1, m2, m2);
            func_80108B54_21EF44_BombsAway(m2, &d);
            obj->rot.x = d.x;
            obj->rot.y = d.y;
            obj->rot.z = d.z;
            if (vel.y < 0.0 && pos.y < -50.0) {
                p->unk_02 = 5;
                p->unk_3C = 0;
                obj->rot.x = obj->rot.z = 0.0f;
            }
            break;
    }
    p->unk_18 = pos.x - obj->trans.x;
    p->unk_1C = pos.y - obj->trans.y;
    p->unk_20 = pos.z - obj->trans.z;
    p->unk_0C = vel.x;
    p->unk_10 = vel.y;
    p->unk_14 = vel.z;
    obj->trans.x = pos.x;
    obj->trans.y = pos.y;
    obj->trans.z = pos.z;
    p->unk_3A++;
    func_80019378_19F78(obj);
    func_80019644_1A244(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_801055FC_21B9EC_BombsAway);
#endif

/* The platform object's setup (MP1 func_800F9824). */
void func_801060C8_21C4B8_BombsAway(omObjData* obj) {
    u8* w;

    obj->func_ptr = func_80106228_21C618_BombsAway;
    obj->model[0] = func_80018A30_19630(0x3B0002, 0x99);
    D_8010DB60_223F50_BombsAway.x = obj->trans.x = 0.0f;
    D_8010DB64_223F54_BombsAway = obj->trans.y = -20.0f;
    D_8010DB68_223F58_BombsAway = obj->trans.z = 670.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    D_8010DB58_223F48_BombsAway = 160.0f;
    D_8010DB5C_223F4C_BombsAway = 0.8f;
    obj->unk_50 = w = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w[3] = 1;
    w[4] = 0;
    func_8000BF24_CB24(obj, 0.0f, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
}

/* The platform's update (MP1 func_800F997C): it slides in at the start, tilts towards the weight
   of the players on it (func_8010770C adds them), bobs and wobbles, shakes after a hit, then
   rebuilds its matrix, inverse and surface plane. New in MP2: it stops at z 70 (MP1 100), and a
   hit strength above 1 decays twice as fast. */
void func_80106228_21C618_BombsAway(omObjData* obj) {
    Matrix4f m;
    f32 p0[3];
    f32 p1[3];
    f32 p2[3];
    f32 out[3];
    BaStage* s = &D_8010DB28_223F18_BombsAway;
    f32 sx;
    f32 sz;
    f32 a;
    f32 t;
    s32 i;
    s32 j;

    if (D_8010D940_223D30_BombsAway.unk_00 == 0 && D_8010D940_223D30_BombsAway.unk_04 >= 61) {
        if (D_8010DB68_223F58_BombsAway > 70.0) {
            D_8010DB68_223F58_BombsAway = obj->trans.z = D_8010DB68_223F58_BombsAway - 10.0;
        }
    }
    if (s->unk_130 != 0) {
        sx = sz = 0.0f;
        for (i = 0; i < s->unk_130; i++) {
            /* Retail adds the weight's z where the plane's c * z belongs. */
            func_801088FC_21ECEC_BombsAway(s->unk_90, s->unk_134[i].unk_00,
                                           -(s->unk_110[0] * s->unk_134[i].unk_00 + s->unk_110[2] +
                                             s->unk_134[i].unk_08 - s->unk_110[3]) /
                                               s->unk_110[1],
                                           s->unk_134[i].unk_08, out);
            t = s->unk_134[i].unk_04 / 4.0;
            sx += t * out[0];
            sz += t * out[2];
        }
        t = func_80108A4C_21EE3C_BombsAway(sx, sz) + 90.0;
        t -= (s32)(t / 360.0f) * 360;
        if (t < 0.0) {
            t += 360.0;
        }
        t -= s->unk_0C;
        if (t >= 0.0f) {
            if (t > 180.0) {
                t -= 360.0;
            }
        } else if (t < -180.0) {
            t += 360.0;
        }
        t = s->unk_0C + t * 0.2;
        if (t >= 360.0) {
            t -= 360.0;
        } else if (t < 0.0) {
            t += 360.0;
        }
        s->unk_0C = t;
        t = sqrtf(sx * sx + sz * sz) / 300.0;
        if (t > 1.0) {
            t = 1.0f;
        } else if (t < -1.0) {
            t = -1.0f;
        }
        s->unk_10 += (t - s->unk_10) * 0.2;
        s->unk_130 = 0;
    } else {
        s->unk_10 -= s->unk_10 * 0.1;
    }
    if (s->unk_20 > 0.0f) {
        s->unk_14 = (f32)(s->unk_14 + 6.0) - (s32)((f32)(s->unk_14 + 6.0) / 360.0f) * 360;
        if (s->unk_14 < 0.0) {
            s->unk_14 += 360.0;
        }
    }
    s->unk_18 = (f32)(s->unk_18 + 5.0) - (s32)((f32)(s->unk_18 + 5.0) / 360.0f) * 360;
    if (s->unk_18 < 0.0) {
        s->unk_18 += 360.0;
    }
    if (s->unk_1C > 1.0) {
        s->unk_1C -= 0.02;
        if (s->unk_1C < 0.0) {
            s->unk_1C = 0.0f;
        }
    } else if (s->unk_1C > 0.0) {
        s->unk_1C -= 0.01;
        if (s->unk_1C < 0.0) {
            s->unk_1C = 0.0f;
        }
    }
    s->unk_28 -= 0.02;
    if (s->unk_28 < 0.0) {
        s->unk_28 = 0.0f;
    }
    if (s->unk_2C != 0) {
        s->unk_2C--;
    }
    s->unk_00 = (f32)(s->unk_00 + 2.0) - (s32)((f32)(s->unk_00 + 2.0) / 360.0f) * 360;
    if (s->unk_00 < 0.0) {
        s->unk_00 += 360.0;
    }
    s->unk_38.y = HuMathSin(s->unk_00) * 20.0 + -20.0;
    obj->trans.y = s->unk_38.y + ((f32)(D_8010D944_223D34_BombsAway & 1) - 0.5) * 0.2 * 100.0 * s->unk_28;
    s->unk_04 += 2.0;
    if (s->unk_04 >= 360.0) {
        s->unk_04 -= 360.0;
    }
    s->unk_08 += 1.0;
    if (s->unk_08 >= 360.0) {
        s->unk_08 -= 360.0;
    }
    a = HuMathSin(s->unk_08) * 2.0;
    func_800B1CC0_B28C0(s->unk_50, a, func_800B7890_B8490(s->unk_04), 0.0f, HuMathSin(s->unk_04));
    s->unk_50[3][3] = 1.0f;
    a = s->unk_10 * 8.0;
    func_800B1CC0_B28C0(m, a, func_800B7890_B8490(s->unk_0C), 0.0f, HuMathSin(s->unk_0C));
    m[3][3] = 1.0f;
    func_800B6410_B7010(m, s->unk_50, s->unk_50);
    a = HuMathSin(s->unk_18) * 20.0;
    func_800B1CC0_B28C0(m, a * s->unk_1C, func_800B7890_B8490(s->unk_14), 0.0f, HuMathSin(s->unk_14));
    m[3][3] = 1.0f;
    func_800B6410_B7010(m, s->unk_50, m);
    func_800B1F50_B2B50((f32*)s->unk_50, obj->trans.x, obj->trans.y, obj->trans.z);
    func_800B6410_B7010(m, s->unk_50, s->unk_50);
    func_80108B54_21EF44_BombsAway(s->unk_50, (Vec*)p0);
    obj->rot.x = s->unk_44.x = p0[0];
    obj->rot.y = s->unk_44.y = p0[1];
    obj->rot.z = s->unk_44.z = p0[2];
    for (j = 0; j < 4; j++) {
        s->unk_D0[j][0] = s->unk_90[j][0];
        s->unk_D0[j][1] = s->unk_90[j][1];
        s->unk_D0[j][2] = s->unk_90[j][2];
        s->unk_D0[j][3] = s->unk_90[j][3];
    }
    func_800B1F50_B2B50((f32*)m, -obj->trans.x, -obj->trans.y, -obj->trans.z);
    func_80025F00_26B00(s->unk_50, s->unk_90);
    func_800B6410_B7010(m, s->unk_90, s->unk_90);
    func_801088FC_21ECEC_BombsAway(s->unk_50, 0.0f, s->unk_30, 0.0f, p0);
    func_801088FC_21ECEC_BombsAway(s->unk_50, 1.0f, s->unk_30, 0.0f, p1);
    func_801088FC_21ECEC_BombsAway(s->unk_50, 0.0f, s->unk_30, 1.0f, p2);
    for (j = 0; j < 3; j++) {
        p1[j] -= p0[j];
        p2[j] = p0[j] - p2[j];
    }
    s->unk_110[0] = p1[1] * p2[2] - p1[2] * p2[1];
    s->unk_110[1] = p1[2] * p2[0] - p1[0] * p2[2];
    s->unk_110[2] = p1[0] * p2[1] - p1[1] * p2[0];
    s->unk_110[3] = p0[0] * s->unk_110[0] + p0[1] * s->unk_110[1] + p0[2] * s->unk_110[2];
    s->unk_120 = 1.0 / sqrtf(s->unk_110[0] * s->unk_110[0] + s->unk_110[1] * s->unk_110[1] +
                             s->unk_110[2] * s->unk_110[2]);
    s->unk_124.x = s->unk_110[0] * s->unk_120;
    s->unk_124.y = s->unk_110[1] * s->unk_120;
    s->unk_124.z = s->unk_110[2] * s->unk_120;
}

/* Direction (degrees) from the platform's centre to pos (MP1 func_800FA47C). */
f32 func_80106D78_21D168_BombsAway(Vec* pos) {
    return func_80108A4C_21EE3C_BombsAway(pos->x - D_8010DB60_223F50_BombsAway.x, pos->z - D_8010DB60_223F50_BombsAway.z);
}

/* Horizontal distance from the platform's centre (MP1 func_800FA4B4). */
f32 func_80106DB0_21D1A0_BombsAway(Vec* pos) {
    f32 dx = pos->x - D_8010DB60_223F50_BombsAway.x;
    f32 dz = pos->z - D_8010DB60_223F50_BombsAway.z;

    return sqrtf(dx * dx + dz * dz);
}

/* pos projected onto the surface plane when it is on or below it (MP1 func_800FA514). */
s32 func_80106E10_21D200_BombsAway(Vec* pos, Vec* out) {
    BaStage* s = &D_8010DB28_223F18_BombsAway;
    f32 d = pos->x * D_8010DC38_224028_BombsAway + pos->y * D_8010DC3C_22402C_BombsAway +
            pos->z * D_8010DC40_224030_BombsAway - D_8010DC44_224034_BombsAway;

    if (d <= 0.0) {
        d *= s->unk_120;
        out->x = pos->x - d * s->unk_124.x;
        out->y = pos->y - d * s->unk_124.y;
        out->z = pos->z - d * s->unk_124.z;
        return 1;
    }
    return 0;
}

/* Whether pos lies within the platform's ellipse, in platform space (MP1 func_800FA5D8). */
s32 func_80106ED4_21D2C4_BombsAway(Vec* pos) {
    f32 out[3];

    func_801088FC_21ECEC_BombsAway(D_8010DBB8_223FA8_BombsAway, pos->x, pos->y, pos->z, out);
    if (out[0] * out[0] + out[2] * 1.35 * out[2] * 1.35 <= 230400.0) {
        return 1;
    }
    return 0;
}

/* func_80107060, plus the platform's rotation in out[1] (zero when off the platform). New in MP2. */
s32 func_80106F60_21D350_BombsAway(Vec* pos, Vec* out) {
    s32 ret;

    if (func_80107060_21D450_BombsAway(pos, out) == 0) {
        out[1].x = out[1].y = out[1].z = 0.0f;
        ret = 0;
    } else {
        out[1].x = D_8010DB6C_223F5C_BombsAway.x;
        out[1].y = D_8010DB6C_223F5C_BombsAway.y;
        out[1].z = D_8010DB6C_223F5C_BombsAway.z;
        ret = 1;
    }
    return ret;
}

/* Whether pos is over the platform and less than 50 above its surface (MP1 func_800FA664). */
s32 func_80106FC8_21D3B8_BombsAway(Vec* pos) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (50.0 <= h) {
        return 0;
    }
    return func_80106ED4_21D2C4_BombsAway(&v);
}

/* pos dropped onto the platform's surface: 1 above it, -1 below, 0 off the platform or 50 or
   more above (MP1 func_800FA6FC). */
s32 func_80107060_21D450_BombsAway(Vec* pos, Vec* out) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);
    s32 ret;

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (func_80106ED4_21D2C4_BombsAway(&v) == 0) {
        return 0;
    }
    if (h < 50.0) {
        out->x = v.x;
        out->y = v.y;
        out->z = v.z;
        ret = -1;
        if (0.0f <= h) {
            ret = 1;
        }
        return ret;
    }
    return 0;
}

/* Moves pos by vel against the platform's surface (MP1 func_800FA7E8): 1 landed or riding on it,
   -1 below it, 0 in the air. onStage: pos rode the platform last frame. */
s32 func_8010714C_21D53C_BombsAway(Vec* pos, Vec* vel, Vec* out, s16 onStage) {
    BaStage* s = &D_8010DB28_223F18_BombsAway;
    Vec next;
    Vec tmp;
    Vec cur;
    f32 t;
    f32 den;
    s32 ret = 0;

    if (onStage != 0) {
        func_801088FC_21ECEC_BombsAway(s->unk_D0, pos->x, pos->y, pos->z, &tmp.x);
        func_801088FC_21ECEC_BombsAway(s->unk_50, tmp.x, tmp.y, tmp.z, &cur.x);
        if (vel->x == 0.0f && vel->y == 0.0f && vel->z == 0.0f) {
            out->x = cur.x;
            out->y = cur.y;
            out->z = cur.z;
            return 1;
        }
        ret = 1;
    } else {
        if (vel->x == 0.0f && vel->y == 0.0f && vel->z == 0.0f) {
            return 0;
        }
        cur.x = pos->x;
        cur.y = pos->y;
        cur.z = pos->z;
    }
    t = -(cur.x * s->unk_110[0] + cur.y * s->unk_110[1] + cur.z * s->unk_110[2] - s->unk_110[3]);
    den = vel->x * s->unk_110[0] + vel->y * s->unk_110[1] + vel->z * s->unk_110[2];
    t /= den;
    if (den < 0.0 && !(t > 1.0)) {
        ret = 1;
    } else {
        t = 1.0f;
    }
    next.x = t * vel->x + cur.x;
    next.y = t * vel->y + cur.y;
    next.z = t * vel->z + cur.z;
    if (func_80106FC8_21D3B8_BombsAway(&next) == 0) {
        out->x = cur.x + vel->x;
        out->y = cur.y + vel->y;
        out->z = cur.z + vel->z;
        ret = 0;
        if (onStage == 0) {
            if (out->y < -50.0) {
                out->y = -50.0f;
                ret = -1;
            }
        } else {
            ret = -1;
        }
        return ret;
    }
    if (ret != 0) {
        cur.x += vel->x;
        cur.y += vel->y;
        cur.z += vel->z;
        if (func_80106E10_21D200_BombsAway(&cur, &tmp) != 0) {
            next.x += (tmp.x - next.x) * s->unk_34;
            next.y += (tmp.y - next.y) * s->unk_34;
            next.z += (tmp.z - next.z) * s->unk_34;
        }
    }
    out->x = next.x;
    out->y = next.y;
    out->z = next.z;
    return ret;
}

/* Where a ray from pos - dir along dir meets the platform (1) or the sea at y 0 (-1)
   (MP1 func_800FAB74). */
s32 func_801074D8_21D8C8_BombsAway(Vec* pos, Vec* dir, Vec* out) {
    BaStage* s = &D_8010DB28_223F18_BombsAway;
    Vec v;
    Vec d;
    f32 t;
    f32 den;
    s32 ok;

    if (dir->y >= 0.0) {
        return 0;
    }
    d.x = pos->x - dir->x;
    d.y = pos->y - dir->y;
    d.z = pos->z - dir->z;
    t = -(d.x * s->unk_110[0] + d.y * s->unk_110[1] + d.z * s->unk_110[2] - s->unk_110[3]);
    den = dir->x * s->unk_110[0] + dir->y * s->unk_110[1] + dir->z * s->unk_110[2];
    t /= den;
    if (den < 0.0) {
        ok = 1;
        if (t > 1.0) {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    if (ok) {
        v.x = t * dir->x + d.x;
        v.y = t * dir->y + d.y;
        v.z = t * dir->z + d.z;
        if (func_80106ED4_21D2C4_BombsAway(&v) != 0) {
            out->x = v.x;
            out->y = v.y;
            out->z = v.z;
            return 1;
        }
    }
    if (pos->y <= 0.0) {
        t = -(d.y - 0.0) / dir->y;
        out->x = t * dir->x + d.x;
        out->y = t * dir->y + d.y;
        out->z = t * dir->z + d.z;
        return -1;
    }
    return 0;
}

/* Adds a weight on the platform for this frame's tilt, up to 8 (MP1 func_800FADA8). */
void func_8010770C_21DAFC_BombsAway(f32 x, f32 z, f32 weight) {
    BaStage* s = &D_8010DB28_223F18_BombsAway;
    s32 n = D_8010DC58_224048_BombsAway;

    if (n < 8) {
        D_8010DC58_224048_BombsAway = n + 1;
        s->unk_134[n].unk_00 = x;
        s->unk_134[n].unk_04 = weight;
        s->unk_134[n].unk_08 = z;
    }
}

/* A bomb hits the platform at (x, z) (MP1 func_800FADF4): it clears the newest landing mark and
   starts the hit wobble; a negative strength is a blast from below. New in MP2: 5 shake frames
   (MP1 15) and a strength up to 2 (MP1 1). */
void func_80107758_21DB48_BombsAway(f32 x, f32 z, f32 dir) {
    BaStage* s;
    f32 a;

    if (D_8010D940_223D30_BombsAway.unk_00 == 1) {
        s = &D_8010DB28_223F18_BombsAway;
        if (D_8010DF18_224308_BombsAway >= 0) {
            D_8010DEB8_2242A8_BombsAway[D_8010DF18_224308_BombsAway].unk_00 = 0;
        }
        a = func_80108A4C_21EE3C_BombsAway(x, z) + 90.0;
        a = a - (s32)(a / 360.0f) * 360;
        s->unk_14 = a;
        if (s->unk_14 < 0.0) {
            s->unk_14 += 360.0;
        }
        if (dir >= 0.0) {
            s->unk_00 = 270.0f;
            s->unk_18 = 180.0f;
            s->unk_20 = 1.0f;
            s->unk_28 = 1.0f;
            s->unk_2C = 5;
        } else {
            s->unk_00 = 0.0f;
            s->unk_18 = 0.0f;
            dir = -dir;
            s->unk_20 = -1.0f;
            s->unk_28 = 0.0f;
            s->unk_2C = 0;
            D_8010DCBC_2240AC_BombsAway = 2;
        }
        if (dir > 2.0) {
            dir = 2.0f;
        }
        s->unk_1C = dir;
    }
}

/* Loads the bomb models and clears the carrier slots (MP1 func_800FAFB4). */
void func_80107918_21DD08_BombsAway(void) {
    u16 ids[] = { 6, 7, 8, 9, 10, 11, 0xFFFF };
    s32 dir = 0x3B0000;
    s32 i;

    for (i = 0; ids[i] != 0xFFFF; i++) {
        D_8010DCD0_2240C0_BombsAway[i] = func_80018A30_19630(dir | ids[i], 0x9D);
    }
    for (i = 0; i < 4; i++) {
        D_8010DCE0_2240D0_BombsAway.unk_00[i] = NULL;
        D_8010DCE0_2240D0_BombsAway.unk_10[i] = NULL;
    }
}

/* Queues a player for a bomb-carrier slot (MP1 func_800FB0D0). */
void func_80107A34_21DE24_BombsAway(omObjData* obj) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010DCE0_2240D0_BombsAway.unk_00[i] == NULL) {
            break;
        }
    }
    if (i < 4) {
        D_8010DCE0_2240D0_BombsAway.unk_00[i] = obj;
    }
}

/* Takes the first waiting player into its slot; the slot index or -1 (MP1 func_800FB120). */
s16 func_80107A84_21DE74_BombsAway(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010DCE0_2240D0_BombsAway.unk_00[i] >= (omObjData*)2) {
            break;
        }
    }
    if (i < 4) {
        D_8010DCE0_2240D0_BombsAway.unk_10[i] = D_8010DCE0_2240D0_BombsAway.unk_00[i];
        D_8010DCE0_2240D0_BombsAway.unk_00[i] = (omObjData*)1;
        return i;
    }
    return -1;
}

/* Frees a slot (MP1 func_800FB19C). */
void func_80107B00_21DEF0_BombsAway(s16 i) {
    D_8010DCE0_2240D0_BombsAway.unk_00[i] = D_8010DCE0_2240D0_BombsAway.unk_10[i] = NULL;
}

void func_80107B28_21DF18_BombsAway(omObjData* obj) {
    func_80107B60_21DF50_BombsAway(obj, 0);
}

void func_80107B44_21DF34_BombsAway(omObjData* obj) {
    func_80107B60_21DF50_BombsAway(obj, 1);
}

/* A bomb-carrier object's setup (MP1 func_800FB1FC); kind 0 or 1. */
void func_80107B60_21DF50_BombsAway(omObjData* obj, u8 kind) {
    obj->func_ptr = func_80107C48_21E038_BombsAway;
    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_80018A30_19630(0x3B0006, 0x99);
    func_8002A00C_2AC0C(obj->model[0]);
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -80.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.8f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->work[0] = 0;
    obj->work[3] = kind;
}

__asm__(".section .rodata");
const u32 D_8010D600_2239F0_BombsAway[8] = { 0xC2480000, 0xC1A00000, 0x447A0000, 0xC2B40000, 0x42480000, 0xC2480000, 0xC47A0000, 0x42B40000 };

__asm__(".section .rodata");
const u32 D_8010D620_223A10_BombsAway[8] = { 0xC4480000, 0x43960000, 0x44480000, 0x43960000, 0xC3480000, 0x43C80000, 0x43480000, 0x43C80000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_80107C48_21E038_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/218BF0", func_801082EC_21E6DC_BombsAway);
