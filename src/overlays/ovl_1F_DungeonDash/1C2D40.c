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
    D_8010B2AA_1C6E2A_DungeonDash[1] = func_80107608_1C3188_DungeonDash(0x2F000A);
    D_8010B2AA_1C6E2A_DungeonDash[2] = func_80107608_1C3188_DungeonDash(0x2F000F);
    frame = D_800F60B0_F6CB0[D_8010B2AA_1C6E2A_DungeonDash[2]]->unk00;
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
    SprAnimSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, D_8010B2AA_1C6E2A_DungeonDash[2], 0);
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

/* The dungeon scenery: walls, gate, the far glow, six torches, the obstacles and the start banner. */
// FPR allocation only (torch z: f0/f2 swapped); the goto loop keeps GCC from hoisting the 0.0f arguments
#ifdef NON_MATCHING
void func_80107C6C_1C37EC_DungeonDash(omObjData* obj) {
    DDTorch* e;
    u16 i;
    s32 r;

    obj->func_ptr = func_80108054_1C3BD4_DungeonDash;
    obj->model[0] = LoadFormFile(0x2F0000, 0x99);
    obj->model[1] = LoadFormFile(0x2F0001, 0x9D);
    obj->model[2] = LoadFormFile(0x2F0002, 0xBD);
    func_80029714_2A314(obj->model[2], 0.0f, 400.0f, 50.0f);
    obj->model[3] = LoadFormFile(0x2F0003, 0xB9);
    D_8010B2AA_1C6E2A_DungeonDash[0] = func_80107608_1C3188_DungeonDash(0x2F000E);
    obj->model[4] = func_80109958_1C54D8_DungeonDash(D_8010A89C_1C641C_DungeonDash,
                                                     SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[0]), 1);
    func_80029714_2A314(obj->model[4], 0.0f, -20.0f, -4600.0f);
    func_800297E8_2A3E8(obj->model[4], 20.0f, 20.0f, 1.0f);
    obj->model[5] = LoadFormFile(0x2F0008, 0x99);
    func_80029714_2A314(obj->model[5], 0.0f, 3.0f, -700.0f);
    func_800297E8_2A3E8(obj->model[5], 1.0f, 1.0f, 0.4f);
    e = D_8010B29C_1C6E1C_DungeonDash = func_80027154_27D54(0x90, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(e, 0, 0x90);
    D_8010B2AA_1C6E2A_DungeonDash[3] = func_80107608_1C3188_DungeonDash(0x2F0010);
    i = 0;
loop:
    {
        if (i == 0) {
            e->model = func_80109958_1C54D8_DungeonDash(D_8010A93C_1C64BC_DungeonDash,
                                                        SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[3]), 2);
        } else {
            e->model = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B29C_1C6E1C_DungeonDash->model);
        }
        e->unk2 = (rand8() + rand8()) % 360;
        e->unk8 = 5.0f;
        if (i & 1) {
            e->unk4 = -45.0f;
            e->x = 525.0f;
        } else {
            e->unk4 = 45.0f;
            e->x = -525.0f;
        }
        e->y = 425.0f;
        e->z = -550.0 - 1000.0 * ((i + 2) >> 1);
        func_80029714_2A314(e->model, e->x, e->y, e->z);
        i++;
        func_8002979C_2A39C(e->model, 0.0f, e->unk4, 0.0f);
        func_800297E8_2A3E8(e->model, e->unk8, e->unk8, 1.0f);
        e++;
        if (i < 6) {
            goto loop;
        }
    }
    func_801083B0_1C3F30_DungeonDash(2);
    func_80108C8C_1C480C_DungeonDash();
    D_8010B2B2_1C6E32_DungeonDash[2] = SprCreate(1, 0);
    SprAnimSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, D_8010B2AA_1C6E2A_DungeonDash[1], 0);
    SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x1000);
    SprScaleSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 1.0f, 1.0f);
    SprPosSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 160, 120);
    SprPrioSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x7FF0);
    D_8010B2BE_1C6E3E_DungeonDash = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80107C6C_1C37EC_DungeonDash);
#endif

void func_80108054_1C3BD4_DungeonDash(omObjData* obj) {
    DDTorch* e;
    s32 i;

    e = D_8010B29C_1C6E1C_DungeonDash;
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    if (D_8010B2BA_1C6E3A_DungeonDash == 0 && D_8010B2BC_1C6E3C_DungeonDash == 0 && D_8010B2D0_1C6E50_DungeonDash != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        func_800298A4_2A4A4(obj->model[2], 4, 0);
        func_800298A4_2A4A4(obj->model[3], 4, 4);
        func_800298A4_2A4A4(obj->model[4], 4, 4);
        func_800298A4_2A4A4(obj->model[5], 4, 4);
        for (i = 0; i < 6; i++, e++) {
            func_800298A4_2A4A4(e->model, 4, 4);
        }
        if (D_8010B2D2_1C6E52_DungeonDash == 1) {
            if ((D_800FC834_FD434[obj->model[2]].pos.y -= 12.5) < -30.0) {
                D_800FC834_FD434[obj->model[2]].pos.y = -30.0f;
                D_8010B2D2_1C6E52_DungeonDash = 2;
                PlaySound(0x240);
            }
        }
    } else {
        func_8010A340_1C5EC0_DungeonDash(obj->model[4], SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[0]), 0);
        for (i = 0; i < 6; i++, e++) {
            e->unk2 += 30;
            if (e->unk2 >= 360) {
                e->unk2 -= 360;
            }
            e->unk8 = HuMathSin(e->unk2) * 0.3 + 5.0;
            func_800297E8_2A3E8(e->model, e->unk8, e->unk8, 1.0f);
            if (i == 0) {
                func_8010A340_1C5EC0_DungeonDash(e->model, SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[3]), 0);
            } else {
                func_8010A430_1C5FB0_DungeonDash(e->model, D_8010B29C_1C6E1C_DungeonDash->model);
            }
        }
    }
}

/* Records team t's z; 1 when it reached the goal. */
s32 func_80108308_1C3E88_DungeonDash(u16 team, f32 z) {
    if (team >= 2) {
        return 0;
    }
    D_8010B2C0_1C6E40_DungeonDash[team] = z;
    func_80108A14_1C4594_DungeonDash(team, z);
    func_80109884_1C5404_DungeonDash(team, z);
    if (z <= -4600.0) {
        D_8010B2BA_1C6E3A_DungeonDash = 0;
        return 1;
    }
    return 0;
}

void func_801083A8_1C3F28_DungeonDash(void) {
}

void func_801083B0_1C3F30_DungeonDash(u16 n) {
    DDObstacle* o;
    u16 i;

    o = D_8010B2E4_1C6E64_DungeonDash = func_80027154_27D54(0xB4, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(o, 0, 0xB4);
    if (n >= 6) {
        n = 5;
    }
    for (i = 0; i < 5; i++, o++) {
        o->unk0 = 0;
        if (i < n) {
            o->unk0 = 1;
            func_80107584_1C3104_DungeonDash(o);
            o->unk2 = 1;
            o->x = D_8010A7F4_1C6374_DungeonDash[i & 1];
            o->y = 0.0f;
            o->z = -3250.0f;
            if (i == 0) {
                o->unk6 = LoadFormFile(0x800BD, 0x99);
                o->unk8 = LoadFormFile(0x2F0005, 0x499);
            } else {
                o->unk6 = func_80027D3C_2893C(D_8010B2E4_1C6E64_DungeonDash->unk6);
                o->unk8 = func_80027D3C_2893C(D_8010B2E4_1C6E64_DungeonDash->unk8);
            }
            o->unkA = LoadFormFile(0xB, 0x499);
            func_800298A4_2A4A4(o->unkA, 4, 4);
            func_80029EDC_2AADC(o->unk6, 3);
            func_80029EDC_2AADC(o->unk8, 3);
            D_800FC834_FD434[o->unkA].unk44 = 1.0f;
        }
    }
    D_8010B2A6_1C6E26_DungeonDash = 1;
}

/* Moves the obstacles up and down; plays the slam sound for the teams that see one land. */
// MP1 func_800FAFD4's residue: loop-head branch layout (bnez/j where retail has beqzl) and FP constant registers
#ifdef NON_MATCHING
void func_80108574_1C40F4_DungeonDash(void) {
    DDObstacle* o;
    u16 i;
    u16 j;
    f32 v;
    s32 vol;
    s16 h;
    f32 s;
    s16 bit;

    i = 0;
    if (D_8010B2A6_1C6E26_DungeonDash == 0) {
        return;
    }
    o = D_8010B2E4_1C6E64_DungeonDash;
    do {
        if (o->unk0 == 0) {
            i++;
        } else {
        switch (o->unk4) {
            case 2:
                o->y = 0.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 180.0f;
                    o->unk4 = 0;
                }
                break;
            case 0:
                o->y = 440.0f - o->unk14 / 180.0f * 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 30.0f;
                    o->unk4 = 3;
                }
                break;
            case 3:
                o->y = 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 5.0f;
                    o->unk4 = 1;
                }
                if (o->unk2 == 0 && D_8010B2BA_1C6E3A_DungeonDash != 0) {
                    o->unk14 -= 1.0f;
                }
                goto place;
            case 1:
                o->y = o->unk14 / 5.0f * 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->y = 0.0f;
                    o->unk14 = 30.0f;
                    o->unk4 = 2;
                    for (j = 0; j < 2; j++) {
                        if (!(i & 1)) {
                            bit = 1 << j;
                            if (bit & D_800FC834_FD434[o->unk6].unk01) {
                                v = 1.0 - (f32)fabs(D_8010B2C0_1C6E40_DungeonDash[j] + 200.0 - o->z) / 2300.0;
                                if (v > 1.0) {
                                    v = 1.0f;
                                } else if (v < 0.0) {
                                    v = 0.0f;
                                }
                                vol = v * 57.0 + 70.0;
                                if (j == 0) {
                                    h = func_80079798_7A398(0x237, 6);
                                } else {
                                    h = func_80079798_7A398(0x237, 7);
                                }
                                if (h != -1) {
                                    func_800795D8_7A1D8(h, vol);
                                    func_801075A8_1C3128_DungeonDash(h, D_8010A7F4_1C6374_DungeonDash[j & 1]);
                                }
                            }
                        }
                    }
                    func_80108B54_1C46D4_DungeonDash(o->unkA);
                }
                break;
            default:
                goto place;
        }
        if (o->unk2 == 0) {
            o->unk14 -= 1.0f;
        }
    place:
        func_80029714_2A314(o->unk6, o->x, o->y, o->z);
        func_800297E8_2A3E8(o->unk6, 2.0f, 2.0f, 1.0f);
        if (D_8010B2D0_1C6E50_DungeonDash < 2) {
            func_80029714_2A314(o->unk8, o->x, 20.0f, o->z);
            s = 1.0 - o->y / 440.0f / 3.0;
            func_800297E8_2A3E8(o->unk8, 2.0 * s, 1.0f, s);
        } else {
            func_800298A4_2A4A4(o->unk8, 4, 4);
        }
        func_80029714_2A314(o->unkA, o->x, 2.0f, o->z);
        i++;
        func_800297E8_2A3E8(o->unkA, 3.0f, 3.0f, 3.0f);
        func_80108BFC_1C477C_DungeonDash(o->unkA);
        }
        o++;
    } while (i < 5);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108574_1C40F4_DungeonDash);
#endif

/* Hides the obstacles behind team t's camera, shows those ahead (bit t of the model flags). */
// register allocation and where (u16)bit is taken (MP1 func_800FB4F8's residue)
#ifdef NON_MATCHING
void func_80108A14_1C4594_DungeonDash(s32 team, f32 z) {
    DDObstacle* o;
    u16 i;
    s32 bit;
    HmfModel* m;

    o = D_8010B2E4_1C6E64_DungeonDash;
    if (D_8010B2A6_1C6E26_DungeonDash == 0) {
        return;
    }
    i = 0;
    bit = 1 << team;
    for (; i < 5; i++, o++) {
        if (o->unk0 != 0 && D_8010B2BC_1C6E3C_DungeonDash == 0) {
            if (o->z > z + 200.0) {
                m = &D_800FC834_FD434[o->unk6];
                if (m->unk01 & (u16)bit) {
                    m->unk01 ^= bit;
                    D_800FC834_FD434[o->unk8].unk01 ^= bit;
                }
            } else {
                D_800FC834_FD434[o->unk6].unk01 |= bit;
                D_800FC834_FD434[o->unk8].unk01 |= bit;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108A14_1C4594_DungeonDash);
#endif

void func_80108B54_1C46D4_DungeonDash(s16 mdl) {
    f32 end;

    end = func_80029CE4_2A8E4(mdl);
    if (func_80029D0C_2A90C(mdl) <= end) {
        if (D_800FC834_FD434[mdl].hmf->unk9C != NULL) {
            D_800FC834_FD434[mdl].hmf->unk9C->unk08 = 0.0f;
        }
        func_80029C74_2A874(mdl, 0.0f);
    }
    func_800298A4_2A4A4(mdl, 4, 0);
}

void func_80108BFC_1C477C_DungeonDash(s16 mdl) {
    f32 end;

    if (mdl != -1 && !(D_800FC834_FD434[mdl].unk18 & 4)) {
        end = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= end) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
}

/* The two swinging blades (D_8010B2E0). */
void func_80108C8C_1C480C_DungeonDash(void) {
    DDBlock* b;
    u16 i;
    u16 anim0;
    u16 anim1;
    u16 anim2;
    f32 d[2];

    D_8010B2A0_1C6E20_DungeonDash = anim0 = func_80107608_1C3188_DungeonDash(0x2F0011);
    D_8010B2A2_1C6E22_DungeonDash = anim1 = func_80107608_1C3188_DungeonDash(0x2F0009);
    D_8010B2A4_1C6E24_DungeonDash = anim2 = func_80107608_1C3188_DungeonDash(0x2F0012);
    b = D_8010B2E0_1C6E60_DungeonDash = func_80027154_27D54(0x40, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(b, 0, 0x40);
    for (i = 0; i < 2; i++, b++) {
        b->unk0 = 1;
        b->unk2 = 60;
        if (i & 1) {
            b->unk4 = 0;
            b->unk10 = 0.0f;
            b->x = 280.0f;
        } else {
            b->unk4 = 2;
            b->unk10 = 180.0f;
            b->x = -280.0f;
        }
        b->y = -200.0f;
        b->unk1C = -2100.0f;
        if (i == 0) {
            b->unk6 = func_80109958_1C54D8_DungeonDash(D_8010A7FC_1C637C_DungeonDash, SprAnimGet(anim0), 0);
            b->unkA = func_80109958_1C54D8_DungeonDash(D_8010A93C_1C64BC_DungeonDash, SprAnimGet(anim1), 4);
        } else {
            b->unk6 = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B2E0_1C6E60_DungeonDash->unk6);
            b->unkA = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B2E0_1C6E60_DungeonDash->unkA);
        }
        func_800297E8_2A3E8(b->unk6, 2.8f, 2.8f, 1.0f);
        func_800297E8_2A3E8(b->unkA, 4.8f, 4.8f, 1.0f);
        func_8002979C_2A39C(b->unkA, 270.0f, 0.0f, 0.0f);
        b->unk8 = func_80109958_1C54D8_DungeonDash(D_8010A9DC_1C655C_DungeonDash, SprAnimGet(anim2), 5);
        func_800298A4_2A4A4(b->unk8, 4, 4);
        func_800297E8_2A3E8(b->unk8, 7.28f, 7.28f, 1.0f);
        d[0] = func_800B7890_B8490(b->unk10) * (2.2 * 100.0);
        d[1] = HuMathSin(b->unk10) * 350.0;
        func_80029714_2A314(b->unk6, b->x + d[0], b->y + d[1], b->unk1C);
        func_8002979C_2A39C(b->unk6, 90.0f, 0.0f, 0.0f);
    }
    D_8010B2A8_1C6E28_DungeonDash = 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108F9C_1C4B1C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80109884_1C5404_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80109958_1C54D8_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A340_1C5EC0_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A430_1C5FB0_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_8010A4DC_1C605C_DungeonDash);
