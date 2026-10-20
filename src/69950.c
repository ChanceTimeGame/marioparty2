#include "common.h"

#include "game/malloc.h"
#include "game/data.h"

/* Game message windows (MP3 src/gamemes.c, MP1 src/72D90.c): the functions with no .rodata. The
   others stay asm because asm functions share the unit's rodata (D3D60-D40A8). MP2's names are
   kept. */

#define GMES_MAX 8
#define GMES_MES_TIMER 10
#define GMES_STAT_NONE 0

typedef struct {
    /* 0x00 */ u8 mesNo;
    /* 0x01 */ u8 stat;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s16 strGId[16];
    /* 0x40 */ s16 strSprId[16];
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ s32 unk70;
} GAMEMES; // size 0x74

extern GAMEMES D_800F9570_FA170[GMES_MAX]; /* MP3 gMesData */
extern s8 D_8010002D_100C2D;               /* MP3 gMesTimerId */
extern u8 D_800FD432_FE032;                /* MP1 GMesCloseF */
extern Gfx* D_800FDBCC_FE7CC;
extern u8 D_800FD842_FE442;
extern s16 D_800FDEA2_FEAA2[];
extern s16 D_800FD85C_FE45C[];
extern u8 D_800FC988_FD588;

void func_80068E64_69A64(Gfx**);
void func_80069770_6A370(void);
void func_8006985C_6A45C(GAMEMES* gMes);
s32 func_8006B1BC_6BDBC(void* arg0, s32, s16);
s32 func_8006AA90_6B690(u8*, s32);
void func_8008D4DC_8E0DC(u8*, u8*);
void SprKill(s16);
void SprAnimKill(s16);
s16 SprAnimRead(void*);

INCLUDE_ASM("asm/nonmatchings/69950", func_80068D50_69950);

/* MP1 GMesInit */
void func_80068DAC_699AC(void) {
    s16 i;

    D_800FC988_FD588 = 0;

    for (i = 0; i < GMES_MAX; i++) {
        D_800F9570_FA170[i].mesNo = 0;
    }

    for (i = 0; i < 5; i++) {
        D_800FDEA2_FEAA2[i] = D_800FD85C_FE45C[i] = -1;
    }

    D_800FD432_FE032 = 0;
    D_8010002D_100C2D = -1;
    D_800FD842_FE442 = 0;
}

INCLUDE_ASM("asm/nonmatchings/69950", func_80068E64_69A64);

INCLUDE_ASM("asm/nonmatchings/69950", func_800691FC_69DFC);

s32 func_80069538_6A138(void) {
    s16 stat;
    s16 i;

    for (i = 0, stat = GMES_STAT_NONE; i < GMES_MAX; i++) {
        if (D_800F9570_FA170[i].mesNo != GMES_MES_TIMER) {
            stat |= D_800F9570_FA170[i].stat;
        }
    }
    return stat;
}

INCLUDE_ASM("asm/nonmatchings/69950", func_800695AC_6A1AC);

INCLUDE_ASM("asm/nonmatchings/69950", func_800695D8_6A1D8);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006961C_6A21C);

INCLUDE_ASM("asm/nonmatchings/69950", func_80069654_6A254);

void func_80069698_6A298(void) {
    D_8010002D_100C2D = -1;
    D_800FD432_FE032 = 1;
    func_80068E64_69A64(&D_800FDBCC_FE7CC);
    D_800FD432_FE032 = 0;
    func_80069770_6A370();
    D_800FD842_FE442 = 0;
}

INCLUDE_ASM("asm/nonmatchings/69950", func_800696E4_6A2E4);

INCLUDE_ASM("asm/nonmatchings/69950", func_80069764_6A364);

void func_80069770_6A370(void) {
    s16 i;

    for (i = 0; i < 5; i++) {
        if (i == 2 && D_8010002D_100C2D != -1) {
            continue;
        }
        if (D_800FDEA2_FEAA2[i] != -1) {
            SprAnimKill(D_800FDEA2_FEAA2[i]);
        }
        if (D_800FD85C_FE45C[i] != -1) {
            SprAnimKill(D_800FD85C_FE45C[i]);
        }
        D_800FDEA2_FEAA2[i] = D_800FD85C_FE45C[i] = -1;
    }
}

void func_8006985C_6A45C(GAMEMES* gMes) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (gMes->strGId[i] != -1) {
            SprKill(gMes->strGId[i]);
        }
        if (gMes->strSprId[i] != -1) {
            SprAnimKill(gMes->strSprId[i]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/69950", func_800698F0_6A4F0);

INCLUDE_ASM("asm/nonmatchings/69950", func_80069C20_6A820);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006A018_6AC18);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006A608_6B208);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006A67C_6B27C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006AA90_6B690);

s16 func_8006ADC4_6B9C4(s16 arg0) {
    void* temp_v0 = DataReadTemp(arg0);
    s16 temp_s0 = SprAnimRead(temp_v0);

    DataCloseTemp(temp_v0);
    return temp_s0;
}

void func_8006AE14_6BA14(GAMEMES* gMes) {
    func_8006985C_6A45C(gMes);
    func_80069770_6A370();
}

s32 func_8006AE38_6BA38(void* arg0) {
    return func_8006B1BC_6BDBC(arg0, 0xB00D9, 0xD8);
}

INCLUDE_ASM("asm/nonmatchings/69950", func_8006AE5C_6BA5C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006B1BC_6BDBC);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006B4C4_6C0C4);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006B858_6C458);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006BD2C_6C92C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006BEE8_6CAE8);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006C3F4_6CFF4);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006CB20_6D720);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006CDF0_6D9F0);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006CF9C_6DB9C);

void func_8006D4D0_6E0D0(s16 arg0) {
    if (D_8010002D_100C2D < 0 || arg0 < 0) {
        return;
    }
    D_800F9570_FA170[D_8010002D_100C2D].unk08 = arg0;
}

void func_8006D518_6E118(void) {
    if (D_8010002D_100C2D < 0) {
        return;
    }
    D_800F9570_FA170[D_8010002D_100C2D].unk0A = 2;
    D_800F9570_FA170[D_8010002D_100C2D].unk0C = 0;
}

INCLUDE_ASM("asm/nonmatchings/69950", func_8006D55C_6E15C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006D580_6E180);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006DA60_6E660);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006DA84_6E684);

/* w1-B */
/* GAMEMES.unk70 is the window's rotation (f32); the shared struct still types it s32. */
#define GMES_ROT(g) (*(f32*)&(g)->unk70)
/* func_800708AC_714AC keeps a second timer (f32) in unk18. */
#define GMES_F18(g) (*(f32*)(g)->unk18)
#define GMES_ABSF(x) (((x) < 0.0f) ? -(x) : (x))

extern u8 D_80102708_103308;

s16 func_8006A67C_6B27C(GAMEMES* gMes, char* str, u8 arg2, s16 arg3, s16 arg4);
unsigned int func_800A5610_A6210(const char* s); /* strlen */
s32 PlaySound(s32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* HuMathCos */
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 grpIdx, s16 idx, f32 sx, f32 sy);
void SprRotSet(s16 grpIdx, s16 idx, f32 rot);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void func_8006BD2C_6C92C(GAMEMES* gMes, s32 fileId);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
s32 func_80068D50_69950(void); /* current minigame's index into D_800CCFC8_CDBC8 */
extern s16 D_800CCFC0_CDBC0[]; /* start voice per D_800CCFC8_CDBC8 value */
extern s8 D_800CCFC8_CDBC8[];
extern char* D_800CD028_CDC28[]; /* character names, " MARIO " etc. */
/* "WON\xC4 ": a local char[6] initialiser. The string sits in w1-A's part of the unit's rodata (its
   first user is func_8006BEE8_6CAE8), so these copies name its label until the whole unit is C; then
   write `char won[] = "WON\xC4 ";` and GCC merges the literals. */
typedef struct {
    char s[6];
} GMesStr6;
extern GMesStr6 D_800D330C_D3F0C;

/* "NEW RECORD" banner: the two words scale and spin in, hold, then fade out. */
s32 func_8006DAA8_6E6A8(GAMEMES* gMes) {
    char* str1 = "NEW";
    char* str2 = "RECORD";
    s32 ret;
    s32 len1;
    s32 len2;
    s32 i;
    f32 x;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = 1;
    len1 = func_800A5610_A6210(str1);
    len2 = func_800A5610_A6210(str2);
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str1, 1, -1, -1);
            func_8006A67C_6B27C(gMes, str2, 1, -1, -1);
            gMes->unk68 = gMes->unk6C = 0.5f;
            x = 160.0f - ((f32)((len1 + len2 + 1) * 11) * gMes->unk68 - (f32)(len1 * 11) * gMes->unk6C);
            SprPosSet(gMes->strGId[0], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            gMes->unk03 = 0;
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            x = ((f32)((len1 + len2 + 1) * 11) * gMes->unk68 - (f32)(len2 * 11) * gMes->unk6C) + 160.0f;
            GMES_ROT(gMes) = 0.0f;
            SprPosSet(gMes->strGId[1], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            SprRotSet(gMes->strGId[1], 0, GMES_ROT(gMes));
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            D_80102708_103308 = 1;
            gMes->unk08 = 1;
            gMes->unk10 = 90.0f;
            break;
        case 1:
            gMes->unk10 += 21.0f;
            gMes->unk68 += 0.016666668f;
            gMes->unk6C = 1.0f - HuMathSin(gMes->unk10) * 0.5f;
            x = 160.0f - ((f32)((len1 + len2 + 1) * 11) * gMes->unk68 - (f32)(len1 * 11) * gMes->unk68);
            GMES_ROT(gMes) += 12.0f;
            gMes->unk03 += 8;
            SprPosSet(gMes->strGId[0], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            SprRotSet(gMes->strGId[0], 0, GMES_ROT(gMes));
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            x = ((f32)((len1 + len2 + 1) * 11) * gMes->unk68 - (f32)(len2 * 11) * gMes->unk68) + 160.0f;
            SprPosSet(gMes->strGId[1], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            if (gMes->unk04 >= 30) {
                gMes->stat = 2;
                SprRotSet(gMes->strGId[0], 0, 0.0f);
                for (i = 0; i < len1; i++) {
                    func_80082488_83088(gMes->strGId[0], i + 1, 0xFF);
                }
                for (i = 0; i < len2; i++) {
                    func_80082488_83088(gMes->strGId[1], i + 1, 0xFF);
                }
                gMes->unk0A = 30;
                gMes->unk08 = 2;
            }
            break;
        case 2:
            if (--gMes->unk0A == -1) {
                gMes->unk0A = 0xFF;
                gMes->unk08 = 3;
            }
            break;
        case 3:
            gMes->unk0A -= 16;
            if (gMes->unk0A <= 0) {
                gMes->unk0A = 0;
                gMes->unk08 = 4;
            }
            for (i = 0; i < len1; i++) {
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk0A);
            }
            for (i = 0; i < len2; i++) {
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk0A);
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xD3);
    }
    if (gMes->unk04 >= 31) {
        gMes->stat = 2;
    }
    return ret;
}

/* Picture banner (file 0xB00DB, sound 0xD7): pulses, then fades out near its timer's end. */
s32 func_8006E1C0_6EDC0(GAMEMES* gMes) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 3;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00DB);
            PlaySound(0xD7);
            D_80102708_103308 = 1;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk68 = 1.0f;
            gMes->unk6C = 1.0f;
            gMes->unk03 = 0xFF;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            gMes->unk6C = gMes->unk68 = HuMathSin(gMes->unk10) * 0.2f + 1.0f;
            gMes->unk10 += 15.0f;
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
            }
            if (gMes->unk04 > gMes->unk06 - 10) {
                gMes->stat = 2;
                gMes->unk03 -= 25;
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
                }
            }
            if (gMes->unk04 > gMes->unk06) {
                gMes->unk08 = 3;
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, 0);
                }
            }
            break;
        case 3:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    return ret;
}

/* Picture banner (file 0xB00DD, sound 0xD6): holds for 10 frames, pulses, fades from frame 40. */
s32 func_8006E45C_6F05C(GAMEMES* gMes) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 3;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00DD);
            PlaySound(0xD6);
            D_80102708_103308 = 1;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk68 = 1.0f;
            gMes->unk6C = 1.0f;
            gMes->unk03 = 0xFF;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            if (gMes->unk04 >= 10) {
                gMes->unk08 = 2;
            }
            break;
        case 2:
            gMes->unk6C = gMes->unk68 = HuMathSin(gMes->unk10) * 0.3f + 1.0f;
            gMes->unk10 += 20.0f;
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
            }
            if (gMes->unk04 >= 40) {
                gMes->unk03 -= 51;
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
                }
            }
            if (gMes->unk04 >= gMes->unk06) {
                gMes->stat = 2;
                gMes->unk08 = 3;
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, 0);
                }
            }
            break;
        case 3:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    return ret;
}

/* Picture banner (file 0xB00E1, sound 0xD9): unfolds, wobbles, then flashes until its timer ends. */
s32 func_8006E71C_6F31C(GAMEMES* gMes) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00E1);
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, 0.0f, 2.0f);
            }
            D_80102708_103308 = 1;
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            gMes->unk68 = HuMathSin(gMes->unk10);
            gMes->unk6C = 2.0f - (1.0f - func_800B7890_B8490(gMes->unk10));
            gMes->unk10 += 9.0f;
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
            }
            if (gMes->unk04 < 10) {
                break;
            }
            gMes->unk08 = 2;
            gMes->unk10 = 90.0f;
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, 1.0f, 1.0f);
            }
        case 2:
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
            }
            gMes->unk68 = 1.5f - GMES_ABSF(HuMathSin(gMes->unk10)) * 0.5f;
            gMes->unk6C = GMES_ABSF(HuMathSin(gMes->unk10)) * 0.7f + 0.3f;
            gMes->unk10 += 12.0f;
            if (gMes->unk04 >= 25) {
                for (i = 0; i < 2; i++) {
                }
                gMes->unk08 = 3;
                gMes->unk10 = 0.0f;
            }
            break;
        case 3:
            gMes->unk03 = func_800B7890_B8490(gMes->unk10) * 55.0f + 200.0f;
            gMes->unk10 += 20.0f;
            for (i = 0; i < 2; i++) {
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 4;
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xD9);
    }
    if (gMes->unk04 >= 51) {
        gMes->stat = 2;
    }
    return ret;
}

/* "READY" ... "GO!" start banner; at frame 50 it plays the current minigame's start voice. */
s32 func_8006EB78_6F778(GAMEMES* gMes) {
    char* str1 = "READY";
    char* str2 = "GO\xC4";
    s32 ret;
    s32 len1;
    s32 len2;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 6;
    }
    ret = 1;
    len1 = func_800A5610_A6210(str1);
    len2 = func_800A5610_A6210(str2);
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str1, 1, -1, -1);
            func_8006A67C_6B27C(gMes, str2, 1, -1, -1);
            gMes->unk68 = 0.5f;
            gMes->unk03 = 0;
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            for (i = 0; i < len2; i++) {
                SprAttrSet(gMes->strGId[1], i + 1, 0x8000);
            }
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            gMes->unk08 = 1;
            gMes->unk0C = 0;
            gMes->unk0A = 0;
            break;
        case 1:
            gMes->unk68 += 0.1f;
            gMes->unk03 += 25;
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            if (gMes->unk04 >= 10) {
                for (i = 0; i < len1; i++) {
                    SprScaleSet(gMes->strGId[0], i + 1, 1.5f, 1.5f);
                    func_80082488_83088(gMes->strGId[0], i + 1, 0xFF);
                }
                gMes->unk08 = 2;
            }
            break;
        case 2:
            if (gMes->unk04 >= 35) {
                gMes->unk08 = 3;
            }
            break;
        case 3:
            gMes->unk68 += 0.05f;
            gMes->unk03 -= 51;
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            if (gMes->unk04 >= 40) {
                for (i = 0; i < len1; i++) {
                    func_80082488_83088(gMes->strGId[0], i + 1, 0);
                }
                gMes->unk08 = 4;
            }
            break;
        case 4:
            gMes->unk68 = gMes->unk6C = HuMathSin(gMes->unk0A * 15) * 3.0f;
            for (i = 0; i < len2; i++) {
                SprAttrReset(gMes->strGId[1], i + 1, 0x8000);
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk68, gMes->unk6C);
            }
            gMes->unk0A++;
            if (gMes->unk04 >= 50) {
                if (D_800CCFC8_CDBC8[func_80068D50_69950()] != -1) {
                    PlaySound(D_800CCFC0_CDBC0[D_800CCFC8_CDBC8[func_80068D50_69950()]]);
                }
                gMes->unk08 = 5;
                gMes->unk03 = 0xFF;
            }
            break;
        case 5:
            gMes->stat = 2;
            gMes->unk03 -= 51;
            for (i = 0; i < len2; i++) {
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            gMes->unk0C++;
            if (gMes->unk04 >= 55) {
                for (i = 0; i < len2; i++) {
                    SprAttrSet(gMes->strGId[1], i + 1, 0x8000);
                }
                gMes->unk08 = 6;
            }
            break;
        case 6:
            func_8006985C_6A45C(gMes);
            D_80102708_103308 = 0;
            ret = 0;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xCF);
    }
    if (gMes->unk04 == 35) {
        PlaySound(0xD0);
    }
    return ret;
}

/* "<name> <name>" then "WON!" (unk0C, unk0E: character indices into D_800CD028_CDC28): the names
   bounce down, then "WON!" appears and shakes. */
s32 func_8006F10C_6FD0C(GAMEMES* gMes) {
    GMesStr6 won = D_800D330C_D3F0C;
    s32 ret;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 i;

    len1 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0C]);
    len2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    len3 = func_800A5610_A6210(won.s);
    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0C], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, won.s, 1, -1, -1);
            gMes->unk60 = 85.0f;
            gMes->unk64 = 0.0f;
            gMes->unk68 = gMes->unk6C = 1.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1.0f, 0xFF);
            }
            gMes->unk60 = 220.0f;
            if (gMes->unk0C == 5) {
                gMes->unk60 = 236.0f;
            }
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1.0f, 0xFF);
            }
            for (i = 0.0f; i < len3; i++) {
                SprAttrSet(gMes->strGId[2], i + 1.0f, 0x8000);
            }
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 1.5f;
            break;
        case 1:
            gMes->unk10 += gMes->unk14;
            gMes->unk64 += gMes->unk10;
            gMes->unk60 = 85.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            gMes->unk60 = 220.0f;
            if (gMes->unk0C == 5) {
                gMes->unk60 = 236.0f;
            }
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            if (gMes->unk04 >= 15) {
                gMes->unk08 = 2;
                gMes->unk10 = -12.0f;
                gMes->unk14 = 1.0f;
            }
            break;
        case 2:
            gMes->unk10 += gMes->unk14;
            gMes->unk64 += gMes->unk10;
            gMes->unk60 = 85.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            gMes->unk60 = 220.0f;
            if (gMes->unk0C == 5) {
                gMes->unk60 = 236.0f;
            }
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            if (gMes->unk04 >= 25) {
                gMes->unk08 = 3;
                gMes->unk0A = gMes->unk64;
            }
            break;
        case 3:
            gMes->unk60 = 170.0f;
            gMes->unk64 = 145.0f;
            gMes->unk68 = gMes->unk6C = 1.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[2], i + 1.0f, 0xFF);
                SprAttrReset(gMes->strGId[2], i + 1.0f, 0x8000);
            }
            gMes->unk08 = 4;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 0.0f;
            break;
        case 4:
            gMes->unk60 = HuMathSin(gMes->unk10) + 170.0f;
            gMes->unk64 = HuMathSin(gMes->unk14) + 145.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            gMes->unk10 += 90.0f;
            gMes->unk14 += 45.0f;
            if (gMes->unk10 >= 360.0f) {
                gMes->unk10 = 0.0f;
            }
            if (gMes->unk14 >= 360.0f) {
                gMes->unk14 = 0.0f;
            }
            break;
        case 5:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 >= 51) {
        gMes->stat = 2;
    }
    return ret;
}

/* Picture banner (file 0xB00DF, sound 0xDA): spins and grows in, then flashes until its timer ends. */
s32 func_8006F924_70524(GAMEMES* gMes) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 3;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00DF);
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            D_80102708_103308 = 1;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk68 = gMes->unk6C = 0.5f;
            GMES_ROT(gMes) = 0.0f;
            gMes->unk03 = 0xFF;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            SprRotSet(gMes->strGId[0], 0, GMES_ROT(gMes));
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            gMes->unk08 = 1;
            break;
        case 1:
            gMes->unk6C = gMes->unk68 += 0.05f;
            GMES_ROT(gMes) += 36.0f;
            SprRotSet(gMes->strGId[0], 0, GMES_ROT(gMes));
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
            }
            if (gMes->unk04 >= 10) {
                SprRotSet(gMes->strGId[0], 0, 0.0f);
                for (i = 0; i < 2; i++) {
                    SprScaleSet(gMes->strGId[0], i, 1.0f, 1.0f);
                }
                gMes->unk08 = 2;
                gMes->unk10 = 0.0f;
            }
            break;
        case 2:
            gMes->unk03 = func_800B7890_B8490(gMes->unk10) * 55.0f + 200.0f;
            gMes->unk10 += 20.0f;
            for (i = 0; i < 2; i++) {
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 3;
            }
            break;
        case 3:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 == 30) {
        PlaySound(0xDA);
    }
    if (gMes->unk04 == 50) {
        gMes->stat = 2;
    }
    return ret;
}

/* Three names (unk0A, unk0C, unk0E: character indices) slide together over 30 frames, then
   "WON!" appears and shakes. */
s32 func_8006FCE4_708E4(GAMEMES* gMes) {
    GMesStr6 won = D_800D330C_D3F0C;
    s32 ret;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 len4;
    f32 i;

    len1 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0A]);
    len2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0C]);
    len3 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    len4 = func_800A5610_A6210(won.s);
    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0A], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0C], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, won.s, 1, -1, -1);
            gMes->unk60 = 95.0f;
            gMes->unk64 = 80.0f;
            gMes->unk68 = gMes->unk6C = 0.5f;
            gMes->unk03 = 0;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 210.0f;
            gMes->unk64 = 80.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 155.0f;
            gMes->unk64 = 140.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[2], i + 1.0f, gMes->unk03);
            }
            for (i = 0.0f; i < len4; i++) {
                SprAttrSet(gMes->strGId[3], i + 1.0f, 0x8000);
            }
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            gMes->unk60 = (gMes->unk10 / 30.0f) * 137.0f + 95.0f;
            gMes->unk64 = (gMes->unk10 / 30.0f) * 37.0f + 80.0f;
            gMes->unk68 = gMes->unk6C = (gMes->unk10 / 30.0f) * 0.5f + 0.5f;
            gMes->unk03 += 8;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 210.0f - (gMes->unk10 / 30.0f) * 127.0f;
            gMes->unk64 = (gMes->unk10 / 30.0f) * 37.0f + 80.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 155.0f;
            gMes->unk64 = 140.0f - (gMes->unk10 / 30.0f) * 60.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[2], i + 1.0f, gMes->unk03);
            }
            gMes->unk10 += 1.0f;
            if (gMes->unk04 >= 30) {
                for (i = 0.0f; i < len1; i++) {
                    func_80082488_83088(gMes->strGId[0], i + 1.0f, 0xFF);
                }
                for (i = 0.0f; i < len2; i++) {
                    func_80082488_83088(gMes->strGId[1], i + 1.0f, 0xFF);
                }
                for (i = 0.0f; i < len3; i++) {
                    func_80082488_83088(gMes->strGId[2], i + 1.0f, 0xFF);
                }
                gMes->unk08 = 2;
            }
            break;
        case 2:
            gMes->unk60 = 170.0f;
            gMes->unk64 = 145.0f;
            gMes->unk68 = gMes->unk6C = 1.0f;
            SprPosSet(gMes->strGId[3], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len4; i++) {
                SprScaleSet(gMes->strGId[3], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[3], i + 1.0f, 0xFF);
                SprAttrReset(gMes->strGId[3], i + 1.0f, 0x8000);
            }
            gMes->unk08 = 3;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 0.0f;
            break;
        case 3:
            gMes->unk60 = HuMathSin(gMes->unk10) + 170.0f;
            gMes->unk64 = HuMathSin(gMes->unk14) + 145.0f;
            SprPosSet(gMes->strGId[3], 0, gMes->unk60, gMes->unk64);
            gMes->unk10 += 90.0f;
            gMes->unk14 += 45.0f;
            if (gMes->unk10 >= 360.0f) {
                gMes->unk10 = 0.0f;
            }
            if (gMes->unk14 >= 360.0f) {
                gMes->unk14 = 0.0f;
            }
            break;
        case 5:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 >= 51) {
        gMes->stat = 2;
    }
    return ret;
}

/* Four names (unk08, unk0A, unk0C, unk0E: character indices) move in from the corners, then
   "WON!" appears in the middle and shakes. The state is the f32 unk10 here and the timers are
   unk14 and unk18. */
s32 func_800708AC_714AC(GAMEMES* gMes) {
    GMesStr6 won = D_800D330C_D3F0C;
    s32 ret;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 len4;
    f32 len5;
    f32 i;

    len1 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk08]);
    len2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0A]);
    len3 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0C]);
    len4 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    len5 = func_800A5610_A6210(won.s);
    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk10 = 5.0f;
    }
    ret = 1;
    switch ((s32)gMes->unk10) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk08], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0A], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0C], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, won.s, 1, -1, -1);
            gMes->unk60 = 50.0f;
            gMes->unk64 = 45.0f;
            gMes->unk68 = gMes->unk6C = 0.5f;
            gMes->unk03 = 0;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 260.0f;
            gMes->unk64 = 45.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 50.0f;
            gMes->unk64 = 200.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[2], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 260.0f;
            gMes->unk64 = 200.0f;
            SprPosSet(gMes->strGId[3], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len4; i++) {
                SprScaleSet(gMes->strGId[3], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[3], i + 1.0f, gMes->unk03);
            }
            for (i = 0.0f; i < len5; i++) {
                SprAttrSet(gMes->strGId[4], i + 1.0f, 0x8000);
            }
            gMes->unk10 = 1.0f;
            gMes->unk14 = 0.0f;
            break;
        case 1:
            gMes->unk60 = (gMes->unk14 / 30.0f) * 45.0f + 50.0f;
            gMes->unk64 = (gMes->unk14 / 30.0f) * 50.0f + 45.0f;
            gMes->unk68 = gMes->unk6C = (gMes->unk14 / 30.0f) * 0.5f + 0.5f;
            gMes->unk03 += 8;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 260.0f - (gMes->unk14 / 30.0f) * 45.0f;
            gMes->unk64 = (gMes->unk14 / 30.0f) * 50.0f + 45.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = (gMes->unk14 / 30.0f) * 45.0f + 50.0f;
            gMes->unk64 = 200.0f - (gMes->unk14 / 30.0f) * 50.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[2], i + 1.0f, gMes->unk03);
            }
            gMes->unk60 = 260.0f - (gMes->unk14 / 30.0f) * 45.0f;
            gMes->unk64 = 200.0f - (gMes->unk14 / 30.0f) * 50.0f;
            SprPosSet(gMes->strGId[3], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len4; i++) {
                SprScaleSet(gMes->strGId[3], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[3], i + 1.0f, gMes->unk03);
            }
            gMes->unk14 += 1.0f;
            if (gMes->unk04 >= 30) {
                for (i = 0.0f; i < len1; i++) {
                    func_80082488_83088(gMes->strGId[0], i + 1.0f, 0xFF);
                }
                for (i = 0.0f; i < len2; i++) {
                    func_80082488_83088(gMes->strGId[1], i + 1.0f, 0xFF);
                }
                for (i = 0.0f; i < len3; i++) {
                    func_80082488_83088(gMes->strGId[2], i + 1.0f, 0xFF);
                }
                for (i = 0.0f; i < len4; i++) {
                    func_80082488_83088(gMes->strGId[3], i + 1.0f, 0xFF);
                }
                gMes->unk10 = 2.0f;
            }
            break;
        case 2:
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk68 = gMes->unk6C = 1.0f;
            SprPosSet(gMes->strGId[4], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < len5; i++) {
                SprScaleSet(gMes->strGId[4], i + 1.0f, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[4], i + 1.0f, 0xFF);
                SprAttrReset(gMes->strGId[4], i + 1.0f, 0x8000);
            }
            gMes->unk10 = 3.0f;
            gMes->unk14 = 0.0f;
            break;
        case 3:
            gMes->unk60 = 95.0f - (gMes->unk14 / 10.0f) * 15.0f;
            gMes->unk64 = 95.0f - (gMes->unk14 / 10.0f) * 10.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            gMes->unk60 = (gMes->unk14 / 10.0f) * 15.0f + 215.0f;
            gMes->unk64 = 95.0f - (gMes->unk14 / 10.0f) * 10.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            gMes->unk60 = 95.0f - (gMes->unk14 / 10.0f) * 15.0f;
            gMes->unk64 = (gMes->unk14 / 10.0f) * 10.0f + 150.0f;
            SprPosSet(gMes->strGId[2], 0, gMes->unk60, gMes->unk64);
            gMes->unk60 = (gMes->unk14 / 10.0f) * 15.0f + 215.0f;
            gMes->unk64 = (gMes->unk14 / 10.0f) * 10.0f + 150.0f;
            SprPosSet(gMes->strGId[3], 0, gMes->unk60, gMes->unk64);
            gMes->unk14 += 1.0f;
            if (gMes->unk04 >= 40) {
                gMes->unk10 = 4.0f;
                gMes->unk14 = 0.0f;
                GMES_F18(gMes) = 0.0f;
            }
            break;
        case 4:
            gMes->unk60 = HuMathSin(gMes->unk14) + 160.0f;
            gMes->unk64 = HuMathSin(GMES_F18(gMes)) + 120.0f;
            SprPosSet(gMes->strGId[4], 0, gMes->unk60, gMes->unk64);
            gMes->unk14 += 90.0f;
            GMES_F18(gMes) += 45.0f;
            if (gMes->unk14 >= 360.0f) {
                gMes->unk14 = 0.0f;
            }
            if (GMES_F18(gMes) >= 360.0f) {
                GMES_F18(gMes) = 0.0f;
            }
            break;
        case 5:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 >= 51) {
        gMes->stat = 2;
    }
    return ret;
}

/* "GOT ITEM!" banner: the two words circle in from opposite sides, pulse, then hold. */
s32 func_80071928_72528(GAMEMES* gMes) {
    char* str1 = "GOT";
    char* str2 = "ITEM\xC4";
    s32 ret;
    s32 len1;
    s32 len2;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = 1;
    len1 = func_800A5610_A6210(str1);
    len2 = func_800A5610_A6210(str2);
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str1, 1, -1, -1);
            func_8006A67C_6B27C(gMes, str2, 1, -1, -1);
            gMes->unk68 = gMes->unk6C = 0.5f;
            gMes->unk60 = func_800B7890_B8490(0.0f) * 55.0f + 149.0f;
            gMes->unk64 = HuMathSin(0.0f) * 55.0f + 120.0f;
            gMes->unk03 = 0;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk60 = func_800B7890_B8490(180.0f) * 55.0f + 149.0f;
            gMes->unk64 = HuMathSin(180.0f) * 55.0f + 120.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, 0);
            }
            D_80102708_103308 = 1;
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 180.0f;
            break;
        case 1:
            gMes->unk10 += 12.0f;
            gMes->unk14 += 12.0f;
            gMes->unk6C = gMes->unk68 += 0.033333335f;
            gMes->unk60 = func_800B7890_B8490(gMes->unk10) * 55.0f + 149.0f;
            gMes->unk64 = HuMathSin(gMes->unk10) * 55.0f + 120.0f;
            gMes->unk03 += 17;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk60 = func_800B7890_B8490(gMes->unk14) * 55.0f + 149.0f;
            gMes->unk64 = HuMathSin(gMes->unk14) * 55.0f + 120.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            if (gMes->unk04 >= 15) {
                gMes->unk08 = 2;
                gMes->unk10 = 630.0f;
            }
            break;
        case 2:
            gMes->unk6C = gMes->unk68 = HuMathSin(gMes->unk10) * 0.1f + 1.1f;
            gMes->unk10 += 36.0f;
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
            }
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk68, gMes->unk68);
            }
            if (gMes->unk04 >= 35) {
                for (i = 0; i < len1; i++) {
                    SprScaleSet(gMes->strGId[0], i + 1, 1.0f, 1.0f);
                }
                for (i = 0; i < len2; i++) {
                    SprScaleSet(gMes->strGId[1], i + 1, 1.0f, 1.0f);
                }
                gMes->unk08 = 3;
            }
            break;
        case 3:
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 4;
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 == 1) {
        PlaySound(0xF0);
    }
    if (gMes->unk04 >= 31) {
        gMes->stat = 2;
    }
    return ret;
}

/* "GOT" / "ITEM" / "!" banner: the words swing in from top and bottom, the "!" slides in from the
   right and pulses. unk0A, unk0C are the second and third words' position here. */
s32 func_80071FDC_72BDC(GAMEMES* gMes) {
    char* str1 = "GOT";
    char* str2 = "ITEM";
    char* str3 = "\xC3";
    s32 ret;
    s32 len1;
    s32 len2;
    s32 len3;
    s32 i;

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = 1;
    len1 = func_800A5610_A6210(str1);
    len2 = func_800A5610_A6210(str2);
    len3 = func_800A5610_A6210(str3);
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str1, 1, -1, -1);
            func_8006A67C_6B27C(gMes, str2, 1, -1, -1);
            func_8006A67C_6B27C(gMes, str3, 1, -1, -1);
            gMes->unk68 = gMes->unk6C = 0.5f;
            gMes->unk60 = 99.0f;
            gMes->unk64 = 45.0f;
            gMes->unk03 = 0;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk0A = 189;
            gMes->unk0C = 195;
            SprPosSet(gMes->strGId[1], 0, gMes->unk0A, gMes->unk0C);
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            SprPosSet(gMes->strGId[2], 0, gMes->unk0A, gMes->unk0C);
            for (i = 0; i < len3; i++) {
                /* retail hides member 1 every time, not member i + 1 (one character, so the same) */
                SprAttrSet(gMes->strGId[2], 1, 0x8000);
                SprScaleSet(gMes->strGId[2], i + 1, 1.0f, 1.0f);
                func_80082488_83088(gMes->strGId[2], i + 1, 0xFF);
            }
            D_80102708_103308 = 1;
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            gMes->unk10 += 12.0f;
            gMes->unk6C = gMes->unk68 += 0.033333335f;
            gMes->unk60 = HuMathSin(gMes->unk10) * 20.0f + 94.0f;
            gMes->unk64 += 5.0f;
            gMes->unk03 += 17;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len1; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk68);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk0A = HuMathSin(gMes->unk10) * 20.0f + 194.0f;
            gMes->unk0C -= 5;
            SprPosSet(gMes->strGId[1], 0, gMes->unk0A, gMes->unk0C);
            for (i = 0; i < len2; i++) {
                SprScaleSet(gMes->strGId[1], i + 1, gMes->unk6C, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i + 1, gMes->unk03);
            }
            if (gMes->unk04 >= 15) {
                gMes->unk0A = 330;
                SprPosSet(gMes->strGId[2], 0, gMes->unk0A, gMes->unk0C);
                for (i = 0; i < len1; i++) {
                    SprScaleSet(gMes->strGId[0], i + 1, 1.0f, 1.0f);
                    func_80082488_83088(gMes->strGId[0], i + 1, 0xFF);
                }
                for (i = 0; i < len2; i++) {
                    SprScaleSet(gMes->strGId[1], i + 1, 1.0f, 1.0f);
                    func_80082488_83088(gMes->strGId[1], i + 1, 0xFF);
                }
                for (i = 0; i < len3; i++) {
                    SprAttrReset(gMes->strGId[2], i + 1, 0x8000);
                    SprScaleSet(gMes->strGId[2], i + 1, 1.0f, 1.0f);
                    func_80082488_83088(gMes->strGId[2], i + 1, 0xFF);
                }
                gMes->unk08 = 2;
            }
            break;
        case 2:
            gMes->unk0A -= 16;
            SprPosSet(gMes->strGId[2], 0, gMes->unk0A, gMes->unk0C);
            if (gMes->unk04 >= 20) {
                gMes->unk08 = 3;
                gMes->unk10 = 630.0f;
            }
            break;
        case 3:
            gMes->unk68 = HuMathSin(gMes->unk10) * 0.5f + 1.5f;
            gMes->unk10 += 36.0f;
            for (i = 0; i < len3; i++) {
                SprScaleSet(gMes->strGId[2], i + 1, gMes->unk68, gMes->unk68);
            }
            if (gMes->unk04 >= 40) {
                for (i = 0; i < len3; i++) {
                    SprScaleSet(gMes->strGId[2], i + 1, 1.0f, 1.0f);
                }
                gMes->unk08 = 4;
            }
            break;
        case 4:
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 5;
            }
            break;
        case 5:
            func_8006985C_6A45C(gMes);
            ret = 0;
            break;
    }
    if (gMes->unk04 == 1) {
        PlaySound(0xF1);
    }
    if (gMes->unk04 >= 31) {
        gMes->stat = 2;
    }
    return ret;
}

void func_8007273C_7333C(u8* arg0, u8 arg1) {
    u8* temp_v0;
    u8* var_s1;

    var_s1 = temp_v0 = HuMemMemoryAllocPerm(512);
    func_8008D4DC_8E0DC(temp_v0, arg0);

    for (; *var_s1 != 0; var_s1++) {
        func_8006AA90_6B690(var_s1, arg1);
        if (var_s1[1] == 128 || var_s1[1] == 129) {
            var_s1++;
        }
    }

    D_800FD842_FE442 = 1;
    HuMemMemoryFreePerm(temp_v0);
}
