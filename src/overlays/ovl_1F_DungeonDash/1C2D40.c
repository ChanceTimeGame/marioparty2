#include "common.h"
#include "ovl_1F.h"

void func_801071C0_1C2D40_DungeonDash(omObjData* obj) {
    obj->func_ptr = func_80107290_1C2E10_DungeonDash;
    func_80026DAC_279AC(0, 0x50, 0x50, 0x50);
    func_80026DAC_279AC(1, 0x80, 0x80, 0x80);
    func_80026E00_27A00(1, -96.0f, 100.0f, 26.0f);
    func_8002C59C_2D19C(0x3B6, 0x3E8, 0, 0, 0);
    func_80020D20_21920(0x40);
    func_80107560_1C30E0_DungeonDash(rand8());
    func_8010764C_1C31CC_DungeonDash();
    D_8010B2BA_1C6E3A_DungeonDash = 1;
    D_8010B2BC_1C6E3C_DungeonDash = 1;
    D_8010B2BE_1C6E3E_DungeonDash = 0;
    D_8010B2D2_1C6E52_DungeonDash = 0;
    D_8010B2D0_1C6E50_DungeonDash = 0;
    D_8010B2A8_1C6E28_DungeonDash = 0;
    D_8010B2A6_1C6E26_DungeonDash = 0;
}

/* Course driver: after 80 frames the race starts; for 120 frames it releases the obstacles. */
void func_80107290_1C2E10_DungeonDash(void) {
    DDObstacle* o;
    u16 i;

    o = D_8010B2E4_1C6E64_DungeonDash;
    func_80108574_1C40F4_DungeonDash();
    func_80108F9C_1C4B1C_DungeonDash();
    if (D_8010ABB0_1C6730_DungeonDash < 80) {
        if (++D_8010ABB0_1C6730_DungeonDash == 80) {
            D_8010B2BA_1C6E3A_DungeonDash = 1;
            D_8010B2BC_1C6E3C_DungeonDash = 0;
        }
    } else if (D_8010ABB4_1C6734_DungeonDash < 120) {
        for (i = 0; i < 5; i++, o++) {
            if (o->unk2 != 0 && o->unk0 != 0) {
                o->unk2 = 0;
            }
        }
        D_8010ABB4_1C6734_DungeonDash++;
    }
}

void func_80107350_1C2ED0_DungeonDash(void) {
}

/* The start banner: x is the split position (320 = full). */
// register allocation only (the D_8010ABB8 load goes to v1 in retail)
#ifdef NON_MATCHING
void func_80107358_1C2ED8_DungeonDash(s16 x) {
    s16* grp;

    if (D_8010B2BE_1C6E3E_DungeonDash != 0) {
        if (D_8010ABB8_1C6738_DungeonDash > 0) {
            if (func_8008F618_90218() == 0) {
                D_8010ABB8_1C6738_DungeonDash--;
            }
        } else if (D_8010ABBA_1C673A_DungeonDash > 0) {
            D_8010ABBA_1C673A_DungeonDash--;
        }
        grp = &D_8010B2B2_1C6E32_DungeonDash[2];
        SprPosSet(*grp, 0, x, 120);
        if (x == 320 && D_8010ABBC_1C673C_DungeonDash == 0) {
            SprAttrSet(*grp, 0, 0x9000);
            D_8010ABBC_1C673C_DungeonDash = 1;
        } else if (x < 320 && D_8010ABBE_1C673E_DungeonDash == 0) {
            SprAttrReset(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x8000);
            D_8010ABBE_1C673E_DungeonDash = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80107358_1C2ED8_DungeonDash);
#endif

s32 func_80107484_1C3004_DungeonDash(void) {
    return D_8010B2D0_1C6E50_DungeonDash != 0;
}

s32 func_80107494_1C3014_DungeonDash(void) {
    if (D_8010B2D0_1C6E50_DungeonDash == 1) {
        D_8010B2D0_1C6E50_DungeonDash = 2;
    }
    return 1;
}

void func_801074BC_1C303C_DungeonDash(void) {
    if (D_8010B2D2_1C6E52_DungeonDash == 0) {
        D_8010B2D2_1C6E52_DungeonDash = 1;
        PlaySound(0x23F);
    }
}

/* The overlay's own random generator (D_8010A7F0). */
u16 func_801074F0_1C3070_DungeonDash(u16 range) {
    D_8010A7F0_1C6370_DungeonDash = (D_8010A7F0_1C6370_DungeonDash * 0x19971204 + 0x19760831) >> 16;
    if (range == 0) {
        return (u16)D_8010A7F0_1C6370_DungeonDash;
    }
    return D_8010A7F0_1C6370_DungeonDash % range;
}

void func_80107560_1C30E0_DungeonDash(u8 seed) {
    D_8010A7F0_1C6370_DungeonDash = seed + seed * D_8010A7F0_1C6370_DungeonDash;
}

void func_80107584_1C3104_DungeonDash(DDObstacle* o) {
    s32 pad[4]; /* retail's 16-byte frame */

    o->unk4 = 3;
    o->unk14 = 15.0f;
}

void func_801075A8_1C3128_DungeonDash(s16 sound, f32 pan) {
    if (sound >= 0) {
        if (pan > 0.0) {
            func_800798F8_7A4F8(sound, 0x60);
        } else {
            func_800798F8_7A4F8(sound, 0x20);
        }
    }
}

u16 func_80107608_1C3188_DungeonDash(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = SprAnimRead(data);
    DataClose(data);
    return ret;
}

void func_8010764C_1C31CC_DungeonDash(void) {
    HuSprite_Unk84_Unk00_Struct* frame;

    D_8010B288_1C6E08_DungeonDash[0] = D_800FC7B0_FD3B0[0] = omAddObj(2, 0, 0, -1, func_801077C8_1C3348_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[0], 0xA0);
    D_8010B288_1C6E08_DungeonDash[0]->work[0] = 1;
    D_8010B288_1C6E08_DungeonDash[0]->work[1] = 0;
    D_8010B288_1C6E08_DungeonDash[1] = D_800FC7B0_FD3B0[1] = omAddObj(3, 0, 0, -1, func_801077C8_1C3348_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[1], 0xA0);
    D_8010B288_1C6E08_DungeonDash[1]->work[0] = 2;
    D_8010B288_1C6E08_DungeonDash[1]->work[1] = 1;
    D_8010B288_1C6E08_DungeonDash[2] = D_800FC7B0_FD3B0[2] = omAddObj(4, 6, 0, -1, func_80107C6C_1C37EC_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[2], 0xA0);
    D_8010B2AC_1C6E2C_DungeonDash[0] = func_80107608_1C3188_DungeonDash(0x2F000A);
    D_8010B2AC_1C6E2C_DungeonDash[1] = func_80107608_1C3188_DungeonDash(0x2F000F);
    frame = D_800F60B0_F6CB0[D_8010B2AC_1C6E2C_DungeonDash[1]]->unk00;
    frame->unk0A = 0;
    frame->unk08 = 0;
    frame->unk06 = frame->unk04;
    D_8010B2C0_1C6E40_DungeonDash[0] = D_8010B2C0_1C6E40_DungeonDash[1] = 0.0;
}

/* A team's curtain sprite (work[0] = camera group, work[1] = team). */
void func_801077C8_1C3348_DungeonDash(omObjData* obj) {
    s32 w;

    obj->func_ptr = func_801078BC_1C343C_DungeonDash;
    obj->trans.x = obj->trans.y = 0.0f;
    w = obj->work[1];
    D_8010B2B2_1C6E32_DungeonDash[(u16)w] = SprCreate(1, 0);
    SprAnimSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, D_8010B2AC_1C6E2C_DungeonDash[1], 0);
    SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 0x103C);
    SprPrioSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, w - 16);
    SprPosSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, (u16)w * 160, 0);
    SprScaleSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 5.0f, 7.5f);
    func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 0x20);
}

/* Fades a team's curtain: closing as its team nears the goal, open for the start, gone at the end. */
// KMC mul fix: retail has no nop between the HuMathSin call's delay slot and the first mul.s
#ifdef NON_MATCHING
void func_801078BC_1C343C_DungeonDash(omObjData* obj) {
    f32* a;
    f32* step;
    s32 t;
    f32 d;
    f32 s;

    t = obj->work[1];
    a = &D_8010ABC0_1C6740_DungeonDash[0][t];
    step = &D_8010ABC0_1C6740_DungeonDash[1][t];
    if (D_8010B2BC_1C6E3C_DungeonDash == 0 && D_8010B2BA_1C6E3A_DungeonDash != 0) {
        d = fabs(D_8010B2C0_1C6E40_DungeonDash[t]) - 3450.0;
        if (d > 0.0) {
            s = HuMathSin(d / 1150.0 * 90.0);
            *a = s * s * s * 128.0f;
            func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[t], 0, (s32)*a);
        }
    } else if (D_8010B2BA_1C6E3A_DungeonDash == 0 && D_8010B2D0_1C6E50_DungeonDash == 0) {
        if (*step == 0.0) {
            *step = 256.0 - *a;
        }
        *a = *a + *step * 0.15;
        if (*a > 256.0) {
            *a = 256.0f;
        }
        if (D_8010ABC0_1C6740_DungeonDash[0][0] >= 256.0 && D_8010ABC0_1C6740_DungeonDash[0][1] >= 256.0) {
            if (++D_8010ABD0_1C6750_DungeonDash >= 31) {
                D_8010B2D0_1C6E50_DungeonDash = 1;
            }
        }
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[t], 0, (s32)*a);
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[2], 0, 256.0 - (s32)*a);
    } else if (D_8010B2D0_1C6E50_DungeonDash == 2 && *a > 0.0) {
        *a = *a - 38.4;
        if (*a < 0.0) {
            *a = 0.0f;
        }
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[0], 0, (s32)*a);
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[1], 0, (s32)*a);
    } else if (D_8010B2D0_1C6E50_DungeonDash == 2) {
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[0], 0, 0x8000);
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[1], 0, 0x8000);
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x8000);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_801078BC_1C343C_DungeonDash);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80107C6C_1C37EC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108054_1C3BD4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108308_1C3E88_DungeonDash);

void func_801083A8_1C3F28_DungeonDash(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_801083B0_1C3F30_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108574_1C40F4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108A14_1C4594_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108B54_1C46D4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108BFC_1C477C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108C8C_1C480C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108F9C_1C4B1C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80109884_1C5404_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80109958_1C54D8_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A340_1C5EC0_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A430_1C5FB0_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A4DC_1C605C_DungeonDash);
