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

INCLUDE_ASM("asm/nonmatchings/69950", func_8006DAA8_6E6A8);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006E1C0_6EDC0);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006E45C_6F05C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006E71C_6F31C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006EB78_6F778);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006F10C_6FD0C);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006F924_70524);

INCLUDE_ASM("asm/nonmatchings/69950", func_8006FCE4_708E4);

INCLUDE_ASM("asm/nonmatchings/69950", func_800708AC_714AC);

INCLUDE_ASM("asm/nonmatchings/69950", func_80071928_72528);

INCLUDE_ASM("asm/nonmatchings/69950", func_80071FDC_72BDC);

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
