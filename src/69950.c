#include "common.h"

#include "game/malloc.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "lib2.0I/libc/stdarg.h"

/* Game message windows (MP3 src/gamemes.c, MP1 src/72D90.c), all in C; rodata D3D60-D40C0 is carved.
   MP2's names are kept. */

#include "game/gamemes.h"

extern s8 D_8010002D_100C2D;               /* MP3 gMesTimerId */
extern u8 D_800FD432_FE032;                /* MP1 GMesCloseF */
extern Gfx* D_800FDBCC_FE7CC;
extern u8 D_800FD842_FE442;
extern s16 D_800FDEA2_FEAA2[];
extern s16 D_800FD85C_FE45C[];
extern u8 D_800FC988_FD588;
extern s16 D_800F9508_FA108;  /* MP1 D_800ED720: GMesWait's countdown */
extern u16 D_801011FC_101DFC;
/* .data (0xCDBC0-0xCDC50) */
s16 D_800CCFC0_CDBC0[4] = { 0x0F, 0x12, 0x13, 0x0E }; /* "START" sounds */
s8 D_800CCFC8_CDBC8[76] = { /* per minigame: index into D_800CCFC0_CDBC0, -1 none */
    3, 3, 3, 3, 3, 3, 3, 1, -1, 1, 0, 0, 3, 1, 1, 3, 1, 3, -1, 3, 1, 1, 3, 0, 3, 3, -1, 0, 0, 0, 3, 0,
    3, 1, 2, 0, -1, 3, 3, 3, 3, 0, 1, 2, 1, 1, 1, 3, 3, 1, 3, 3, 0, 3, 3, 3, 3, 3, 3, 3, 2, 3, 0, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 0, 0,
};
u8 D_800CD014_CDC14[20] = { /* the 19 characters of the 0x90/0xD0 font sheet */
    0x95, 0xA6, 0xAC, 0xAF, 0xD1, 0xD3, 0xD5, 0xD7, 0xD8, 0xD9,
    0xDA, 0xDB, 0xDE, 0xDF, 0xE4, 0xE6, 0xE9, 0xEB, 0xEC, 0x00,
};
extern const char D_800D32D4_D3ED4[];
extern const char D_800D32DC_D3EDC[];
extern const char D_800D32E4_D3EE4[];
extern const char D_800D32EC_D3EEC[];
extern const char D_800D32F4_D3EF4[];
extern const char D_800D32FC_D3EFC[];
extern const char D_800D3304_D3F04[];
char* D_800CD028_CDC28[10] = { /* character names, padded to 7 */
    (char*)D_800D3304_D3F04, (char*)D_800D32FC_D3EFC, (char*)D_800D32F4_D3EF4, (char*)D_800D32EC_D3EEC,
    (char*)D_800D32E4_D3EE4, (char*)D_800D32DC_D3EDC, (char*)D_800D32D4_D3ED4, NULL, NULL, NULL,
};
extern s8 D_80102708_103308;

void func_80068E64_69A64(Gfx**);
s32 func_80069538_6A138(void);
s32 func_800698F0_6A4F0(GAMEMES*, Gfx**);
s32 func_80069C20_6A820(GAMEMES*, Gfx**);
s32 func_8006A018_6AC18(GAMEMES*, Gfx**);
s32 func_8006AE38_6BA38(GAMEMES*, Gfx**);
s32 func_8006B4C4_6C0C4(GAMEMES*, Gfx**);
s32 func_8006B858_6C458(GAMEMES*, Gfx**);
s32 func_8006BEE8_6CAE8(GAMEMES*, Gfx**);
s32 func_8006C3F4_6CFF4(GAMEMES*, Gfx**);
s32 func_8006CB20_6D720(GAMEMES*, Gfx**);
s32 func_8006CDF0_6D9F0(GAMEMES*, Gfx**);
s32 func_8006CF9C_6DB9C(GAMEMES*, Gfx**);
s32 func_8006D55C_6E15C(GAMEMES*, Gfx**);
s32 func_8006D580_6E180(GAMEMES*, char*, s16);
s32 func_8006DA60_6E660(GAMEMES*, Gfx**);
s32 func_8006DA84_6E684(GAMEMES*, Gfx**);
s32 func_8006DAA8_6E6A8(GAMEMES*, Gfx**);
s32 func_8006E1C0_6EDC0(GAMEMES*, Gfx**);
s32 func_8006E45C_6F05C(GAMEMES*, Gfx**);
s32 func_8006E71C_6F31C(GAMEMES*, Gfx**);
s32 func_8006EB78_6F778(GAMEMES*, Gfx**);
s32 func_8006F10C_6FD0C(GAMEMES*, Gfx**);
s32 func_8006F924_70524(GAMEMES*, Gfx**);
s32 func_8006FCE4_708E4(GAMEMES*, Gfx**);
s32 func_800708AC_714AC(GAMEMES*, Gfx**);
s32 func_80071928_72528(GAMEMES*, Gfx**);
s32 func_80071FDC_72BDC(GAMEMES*, Gfx**);
void func_80069770_6A370(void);
void func_8006985C_6A45C(GAMEMES* gMes);
s16 func_8006ADC4_6B9C4(s16);
s32 func_8006B1BC_6BDBC(GAMEMES*, s32, s16);
void func_8006BD2C_6C92C(GAMEMES*, s32 fileId);
void SprRotSet(s16 grpIdx, s16 idx, f32 rot);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
u32 func_8006AA90_6B690(u8*, s32);
void func_8008D4DC_8E0DC(u8*, u8*);
void SprKill(s16);
void SprAnimKill(s16);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprScaleSet(s16, s16, f32, f32);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void func_80082488_83088(s16, s16, u16);
f32 func_800B7890_B8490(f32); /* sin, degrees */
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
s32 func_80089234_89E34(u8*); /* string length in characters */
u32 func_800A5610_A6210(char*); /* strlen */
f32 HuMathSin(f32);
s16 func_8006A67C_6B27C(GAMEMES*, char*, u8, s16, s16);
s16 SprAnimRead(void*);

/* The minigame for the current overlay: the six 0x3F-0x4A overlays give 0x3B-0x40, others
   GwSystem's. */
s32 func_80068D50_69950(void) {
    s32 n = 0;

    switch (D_800FA63C_FB23C) {
        case 0x4A:
            n++;
        case 0x48:
            n++;
        case 0x46:
            n++;
        case 0x44:
            n++;
        case 0x42:
            n++;
        case 0x3F:
            return n + 0x3B;
    }
    return GwSystem.chosenMinigameIndex;
}

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

/* MP3 GMesExec */
void func_80068E64_69A64(Gfx** arg0) {
    s16 result = FALSE;
    s16 i, j;

    if (D_800FDC9C_FE89C != 0 && !D_800FD432_FE032) {
        return;
    }
    for (i = 0; i < GMES_MAX; i++) {
        if (D_800F9570_FA170[i].stat != GMES_STAT_NONE) {
            GAMEMES* gMes = &D_800F9570_FA170[i];

            switch (gMes->mesNo) {
                case 0:
                    result = func_800698F0_6A4F0(gMes, arg0);
                    break;
                case 1:
                    result = func_80069C20_6A820(gMes, arg0);
                    break;
                case 2:
                    result = func_8006A018_6AC18(gMes, arg0);
                    break;
                case 3:
                    result = func_8006AE38_6BA38(gMes, arg0);
                    break;
                case 4:
                    result = func_8006B4C4_6C0C4(gMes, arg0);
                    break;
                case 5:
                    result = func_8006B858_6C458(gMes, arg0);
                    break;
                case 7:
                    result = func_8006C3F4_6CFF4(gMes, arg0);
                    break;
                case 8:
                    result = func_8006CB20_6D720(gMes, arg0);
                    break;
                case 9:
                    result = func_8006CDF0_6D9F0(gMes, arg0);
                    break;
                case GMES_MES_TIMER:
                    result = func_8006CF9C_6DB9C(gMes, arg0);
                    break;
                case 11:
                    result = func_8006D55C_6E15C(gMes, arg0);
                    break;
                case 12:
                    result = func_8006DA60_6E660(gMes, arg0);
                    break;
                case 13:
                    result = func_8006DA84_6E684(gMes, arg0);
                    break;
                case 14:
                    result = func_8006DAA8_6E6A8(gMes, arg0);
                    break;
                case 18:
                    result = func_8006E1C0_6EDC0(gMes, arg0);
                    break;
                case 20:
                    result = func_8006E45C_6F05C(gMes, arg0);
                    break;
                case 16:
                    result = func_8006E71C_6F31C(gMes, arg0);
                    break;
                case 15:
                    result = func_8006EB78_6F778(gMes, arg0);
                    break;
                case 19:
                    result = func_8006F924_70524(gMes, arg0);
                    break;
                case 6:
                    result = func_8006BEE8_6CAE8(gMes, arg0);
                    break;
                case 17:
                    result = func_8006F10C_6FD0C(gMes, arg0);
                    break;
                case 21:
                    result = func_8006FCE4_708E4(gMes, arg0);
                    break;
                case 22:
                    result = func_800708AC_714AC(gMes, arg0);
                    break;
                case 23:
                    result = func_80071928_72528(gMes, arg0);
                    break;
                case 24:
                    result = func_80071FDC_72BDC(gMes, arg0);
                    break;
            }
            gMes->unk04++;
            if (gMes->unk04 >= 0x4000) {
                gMes->unk04 = 0x2000;
            }
            if (result == FALSE) {
                gMes->stat = GMES_STAT_NONE;
                if (D_800FD842_FE442 == 0) {
                    for (j = 0; j < GMES_MAX; j++) {
                        if (D_800F9570_FA170[j].stat != GMES_STAT_NONE && D_800F9570_FA170[j].mesNo != GMES_MES_TIMER) {
                            break;
                        }
                    }
                    if (j == GMES_MAX) {
                        func_80069770_6A370();
                    }
                }
            }
        }
    }
}

/* MP3 GMesCreate */
s16 func_800691FC_69DFC(s16 mesNo, ...) {
    GAMEMES* gMes;
    va_list args;
    s32 chr;
    s16 mesId;
    s16 i;

    va_start(args, mesNo);
    for (mesId = 0; mesId < GMES_MAX; mesId++) {
        if (D_800F9570_FA170[mesId].stat == GMES_STAT_NONE) {
            break;
        }
    }
    if (mesId == GMES_MAX) {
        return -1;
    }
    gMes = &D_800F9570_FA170[mesId];
    gMes->stat = 1;
    gMes->mesNo = mesNo;
    gMes->unk04 = 0;
    gMes->unk60 = 160.0f;
    gMes->unk64 = 120.0f;
    gMes->unk6C = 1.0f;
    gMes->unk68 = 1.0f;
    gMes->unk70 = 0.0f;
    gMes->unk03 = 0xFF;
    gMes->unk06 = 0x3C;
    gMes->unk0E = 0;
    gMes->unk0C = 0;
    gMes->unk0A = 0;
    gMes->unk08 = 0;
    gMes->unk10 = gMes->unk14 = 0.0f;
    for (i = 0; i < 16; i++) {
        gMes->strSprId[i] = gMes->strGId[i] = -1;
    }
    switch (mesNo) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 16:
        case 18:
        case 20:
        case 23:
        case 24:
            gMes->unk06 = 0x2D;
            break;
        case 14:
            gMes->unk60 = 160.0f;
            gMes->unk64 = 200.0f;
            break;
        case 6:
        case 7:
            gMes->unk0E = chr = va_arg(args, s32);
            break;
        case 8:
        case 9:
            gMes->unk1C = va_arg(args, u8*);
            gMes->unk60 = va_arg(args, s32);
            gMes->unk64 = va_arg(args, s32);
            gMes->unk68 = va_arg(args, f64);
            gMes->unk6C = va_arg(args, f64);
            gMes->unk02 = va_arg(args, s32);
            break;
        case GMES_MES_TIMER:
            D_8010002D_100C2D = mesId;
            gMes->unk08 = va_arg(args, s32);
            gMes->unk60 = va_arg(args, s32);
            gMes->unk64 = va_arg(args, s32);
            gMes->unk60 = 160.0f;
            gMes->unk64 = 28.0f;
            break;
        case 17:
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            break;
        case 21:
            gMes->unk0A = chr = va_arg(args, s32);
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            break;
        case 22:
            gMes->unk08 = chr = va_arg(args, s32);
            gMes->unk0A = chr = va_arg(args, s32);
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            break;
    }
    D_800F9508_FA108 = 0x5A;
    va_end(args);
    return mesId;
}

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

/* MP1 GMesStatGet */
u8 func_800695AC_6A1AC(s16 mesId) {
    return D_800F9570_FA170[mesId].stat;
}

/* MP1 GMesMaxTimeGet: -1 is no limit */
void func_800695D8_6A1D8(s16 mesId, s16 time) {
    if (time == -1) {
        time = 0x7FFF;
    }
    D_800F9570_FA170[mesId].unk06 = time;
}

/* MP1 GMesPosSet */
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y) {
    D_800F9570_FA170[mesId].unk60 = x;
    D_800F9570_FA170[mesId].unk64 = y;
}

void func_80069654_6A254(s16 mesId) {
    if (D_800F9570_FA170[mesId].stat != GMES_STAT_NONE) {
        D_800F9570_FA170[mesId].stat = 4;
    }
}

void func_80069698_6A298(void) {
    D_8010002D_100C2D = -1;
    D_800FD432_FE032 = 1;
    func_80068E64_69A64(&D_800FDBCC_FE7CC);
    D_800FD432_FE032 = 0;
    func_80069770_6A370();
    D_800FD842_FE442 = 0;
}

/* MP1 GMesWait */
s32 func_800696E4_6A2E4(void) {
    s32 stat;

    if (D_800FDC9C_FE89C == 0 && D_801011FC_101DFC == 0) {
        stat = func_80069538_6A138();
        if (stat == 0 || stat & 2) {
            if (_CheckFlag(0xC)) {
                return 0;
            }
            D_800F9508_FA108--;
            if (D_800F9508_FA108 < 0) {
                return 0;
            }
        }
    }
    return 1;
}

/* MP1 GMesMaxWaitSet */
void func_80069764_6A364(s16 time) {
    D_800F9508_FA108 = time;
}

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

/* "START" (MP1 func_800763CC) */
// register allocation in the two loops that pass i + 1 twice (masked 22); logic checked
#ifdef NON_MATCHING
s32 func_800698F0_6A4F0(GAMEMES* gMes, Gfx** arg1) {
    s32 n = 5;
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, "START", 1, -1, -1);
            SprPosSet(gMes->strGId[0], 0, 160, 120);
            for (i = 0; i < n; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, 1.0f, 0.0f);
                func_80082488_83088(gMes->strGId[0], i + 1, 0);
            }
            gMes->unk08 = 1;
            break;
        case 1:
            for (i = 0; i < n;) {
                i++;
                SprScaleSet(gMes->strGId[0], i, 1.0f, gMes->unk04 * 0.05f);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk04 * 12);
            }
            if (gMes->unk04 >= 20) {
                gMes->unk08 = 2;
                for (i = 0; i < n;) {
                    i++;
                    func_80082488_83088(gMes->strGId[0], i, 255);
                }
            }
            break;
        case 2:
            if (gMes->unk04 >= 30) {
                gMes->unk08 = 3;
                gMes->unk0A = 0;
            }
            break;
        case 3:
            gMes->stat = 2;
            gMes->unk0A += 6;
            for (i = 0; i < n;) {
                i++;
                SprScaleSet(gMes->strGId[0], i, 1.0f, func_800B7890_B8490(gMes->unk0A));
            }
            if (gMes->unk04 >= gMes->unk06) {
                for (i = 0; i < n;) {
                    i++;
                    SprAttrSet(gMes->strGId[0], i, 0x8000);
                }
                gMes->unk08 = 4;
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            D_80102708_103308 = 0;
            ret = FALSE;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xCE);
    }
    if (gMes->unk04 == 38 && D_800CCFC8_CDBC8[func_80068D50_69950()] != -1) {
        PlaySound(D_800CCFC0_CDBC0[D_800CCFC8_CDBC8[func_80068D50_69950()]]);
    }
    return ret;
}
#else
/* .rodata of the asm functions below: GCC loses track of the section after an INCLUDE_ASM, so it is
   all defined here, before them */
const char D_800D325C_D3E5C[] __attribute__((section(".rodata"))) = "START";
const u32 jtbl_800D3268_D3E68[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80069964, 0x800699EC, 0x80069AB0, 0x80069ACC, 0x80069B74,
};
/* func_8006A018_6AC18's, here so that no INCLUDE_ASM separates it from the others */
const u32 jtbl_800D3280_D3E80[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8006A0A0, 0x8006A180, 0x8006A398, 0x8006A478, 0x8006A534, 0x8006A558,
};
INCLUDE_ASM("asm/nonmatchings/69950", func_800698F0_6A4F0);
#endif

/* "START", bouncing in */
// register allocation in the two loops that pass i + 1 twice (masked 21); logic checked
#ifdef NON_MATCHING
s32 func_80069C20_6A820(GAMEMES* gMes, Gfx** arg1) {
    char* str = "START";
    s32 len = func_800A5610_A6210(str);
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 3;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str, 1, -1, -1);
            gMes->unk6C = gMes->unk68 = 0.3f;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk03 = 0;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, 1.0f, 1.0f);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk08 = 1;
            gMes->unk0A = 0;
            gMes->unk0C = 0;
            gMes->unk0E = 9;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            gMes->unk68 = gMes->unk10 + 0.3f;
            gMes->unk6C = gMes->unk10 + 0.3f;
            gMes->unk64 = 120.0f - HuMathSin(gMes->unk0A) * 20.0f;
            gMes->unk03 += 12;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1, gMes->unk03);
            }
            gMes->unk0A += gMes->unk0E;
            gMes->unk0C += 4;
            gMes->unk10 += 0.035f;
            if (gMes->unk04 >= 20) {
                gMes->unk08 = 2;
                SprPosSet(gMes->strGId[0], 0, 160, 120);
                for (i = 0; i < len;) {
                    i++;
                    func_80082488_83088(gMes->strGId[0], i, 255);
                }
            }
            break;
        case 2:
            gMes->stat = 2;
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 3;
            }
            break;
        case 3:
            func_8006985C_6A45C(gMes);
            D_80102708_103308 = 0;
            ret = FALSE;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xCE);
    }
    if (gMes->unk04 == 38 && D_800CCFC8_CDBC8[func_80068D50_69950()] != -1) {
        PlaySound(D_800CCFC0_CDBC0[D_800CCFC8_CDBC8[func_80068D50_69950()]]);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/69950", func_80069C20_6A820);
#endif

/* "START", dropping in with two bounces */
// register allocation in the loop that passes i + 1 twice (masked 21); logic checked
#ifdef NON_MATCHING
s32 func_8006A018_6AC18(GAMEMES* gMes, Gfx** arg1) {
    char* str = "START";
    s32 len = func_800A5610_A6210(str);
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, str, 1, -1, -1);
            gMes->unk6C = gMes->unk68 = 0.3f;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 40.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len; i++) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i + 1, 0);
            }
            gMes->unk08 = 1;
            gMes->unk0A = 0;
            gMes->unk0C = 0;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 0.0f;
            break;
        case 1:
            gMes->unk68 = gMes->unk10 + 0.3f;
            gMes->unk6C = gMes->unk10 + 0.3f;
            gMes->unk60 = 160.0f;
            gMes->unk64 += gMes->unk14;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < len;) {
                SprScaleSet(gMes->strGId[0], i + 1, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], ++i, HuMathSin(gMes->unk0C) * 255.0f);
            }
            gMes->unk0C += 6;
            gMes->unk10 += 0.046666667f;
            gMes->unk14 += 0.8f;
            if (gMes->unk64 >= 120.0f) {
                gMes->unk64 = 120.0f;
                gMes->unk14 = -5.0f;
                SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
                for (i = 0; i < len;) {
                    i++;
                    func_80082488_83088(gMes->strGId[0], i, 255);
                }
                gMes->unk08 = 2;
            }
            break;
        case 2:
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            gMes->unk64 += gMes->unk14;
            gMes->unk14 += 1.5f;
            if (gMes->unk64 >= 120.0f) {
                gMes->unk64 = 120.0f;
                gMes->unk14 = -3.0f;
                SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
                gMes->unk08 = 3;
            }
            break;
        case 3:
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            gMes->unk64 += gMes->unk14;
            gMes->unk14 += 1.5f;
            if (gMes->unk64 >= 120.0f) {
                gMes->unk64 = 120.0f;
                SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
                gMes->unk08 = 4;
            }
            break;
        case 4:
            gMes->stat = 2;
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 5;
            }
            break;
        case 5:
            func_8006985C_6A45C(gMes);
            D_80102708_103308 = 0;
            ret = FALSE;
            break;
    }
    if (gMes->unk04 == 10) {
        PlaySound(0xCE);
    }
    if (gMes->unk04 == 38 && D_800CCFC8_CDBC8[func_80068D50_69950()] != -1) {
        PlaySound(D_800CCFC0_CDBC0[D_800CCFC8_CDBC8[func_80068D50_69950()]]);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/69950", func_8006A018_6AC18);
#endif

/* MP1 GMesFontMesCreate */
s16 func_8006A608_6B208(GAMEMES* gMes, char* str, u8 flag, s16 x, s16 arg4) {
    s16 i;

    for (i = 0; i < 16; i++) {
        gMes->strGId[i] = -1;
        gMes->strSprId[i] = -1;
    }
    return func_8006A67C_6B27C(gMes, str, flag, x, arg4);
}

/* MP1 GMesFontCreate: a sprite group with one member per character of str; flag bit 0 picks the
   large font. x < 0 is a left offset, -1 centres the string. Returns the strGId slot. */
// register allocation and stack spills (masked 50; retail also loads the unused arg4); logic checked, as MP1 GMesFontCreate
#ifdef NON_MATCHING
s16 func_8006A67C_6B27C(GAMEMES* gMes, char* arg1, u8 flag, s16 x0, s16 arg4) {
    u16 hi;
    s16 id;
    u8* str;
    u8* p;
    s16 i;
    s16 len;
    s16 total;
    s16 x;
    s16 idx;
    u8 w;
    u32 v;

    str = arg1;
    len = func_80089234_89E34(str);

    for (i = 0; i < 16; i++) {
        if (gMes->strSprId[i] == -1 && gMes->strGId[i] == -1) {
            break;
        }
    }

    id = gMes->strGId[i] = SprCreate((u16)(len + 1), 5);

    w = 15;
    if (flag & 1) {
        w = 22;
    }

    p = str;
    for (total = 0; *p != 0; p++) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 0x90 && *p < 0xB0) || (*p >= 0xD0 && *p < 0xF0)) {
            total += 10;
        } else if (*p == '\\') {
            total += (w == 15) ? 4 : 8;
        } else if ((*p == 0x10) | (*p == ' ')) {
            total += (w == 15) ? 8 : 11;
        } else {
            total = w + total;
        }
    }

    x = -x0;
    if (x0 == -1) {
        x = (w >> 1) - total / 2;
    }

    for (idx = 1; *str != 0; idx++) {
        v = func_8006AA90_6B690(str, flag);
        hi = v >> 16;
        SprAnimSet(id, idx, hi, v & 0xFF);
        /* retail tests the 0xD0 range's upper bound on p, which is at the string's end here */
        SprPosSet(id, idx, x, (*str >= 'a' && *str <= 'z') || (*str >= 0x90 && *str < 0xB0) || (*str >= 0xD0 && *p < 0xF0));
        func_80082488_83088(id, idx, 255);
        SprPrioSet(id, idx, 5);
        SprAttrReset(id, idx, 0xFFFF);
        SprAttrSet(id, idx, 0x1008);
        if ((*str >= 'a' && *str <= 'z') || (*str >= 0x90 && *str < 0xB0) || (*str >= 0xD0 && *str < 0xF0)) {
            x += 10;
        } else if (*str == '\\') {
            x += (w != 15) ? 12 : 8;
        } else if ((*str == 0x10) | (*str == ' ')) {
            x += (w == 15) ? 8 : 11;
        } else {
            x = w + x;
        }
        func_800824F4_830F4(id, idx, 0);
        str += ((u8)(str[1] + 0x80) < 2) + 1;
    }

    SprAnimSet(id, 0, hi, 0);
    SprAttrSet(id, 0, 0x8000);
    func_800824F4_830F4(id, 0, -1);
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/69950", func_8006A67C_6B27C);
#endif

/* MP1 func_80076B2C: the font sprite (high half, loaded on first use) and frame (low half) for
   the character at str; flag bit 0 is the large font. Large lower-case characters keep the
   high half unset, as in retail. */
u32 func_8006AA90_6B690(u8* str, s32 flag) {
    u16 frame;
    u16 anim;
    s16 large;
    u8 c;
    u16 i;

    large = flag;
    c = str[0];

    if (c >= 'A' && c <= 'Z') {
        if (large & 1) {
            if (D_800FD85C_FE45C[0] == -1) {
                anim = D_800FD85C_FE45C[0] = func_8006ADC4_6B9C4(0x39);
            } else {
                anim = D_800FD85C_FE45C[0];
            }
        } else {
            if (D_800FDEA2_FEAA2[0] == -1) {
                anim = D_800FDEA2_FEAA2[0] = func_8006ADC4_6B9C4(0x37);
            } else {
                anim = D_800FDEA2_FEAA2[0];
            }
        }
        frame = c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        if (!(large & 1)) {
            if (D_800FDEA2_FEAA2[1] == -1) {
                anim = D_800FDEA2_FEAA2[1] = func_8006ADC4_6B9C4(0x44);
            } else {
                anim = D_800FDEA2_FEAA2[1];
            }
        }
        frame = c - 'a';
    } else if (c >= '0' && c <= '9') {
        if (large & 1) {
            if (D_800FD85C_FE45C[2] == -1) {
                anim = D_800FD85C_FE45C[2] = func_8006ADC4_6B9C4(0x3A);
            } else {
                anim = D_800FD85C_FE45C[2];
            }
        } else {
            if (D_800FDEA2_FEAA2[2] == -1) {
                anim = D_800FDEA2_FEAA2[2] = func_8006ADC4_6B9C4(0x38);
            } else {
                anim = D_800FDEA2_FEAA2[2];
            }
        }
        frame = c - '0';
    } else if ((c >= 0x90 && c < 0xB0) || (c >= 0xD0 && c < 0xF0)) {
        if (large & 1) {
            return 0;
        }
        if (D_800FDEA2_FEAA2[4] == -1) {
            anim = D_800FDEA2_FEAA2[4] = func_8006ADC4_6B9C4(0x41);
        } else {
            anim = D_800FDEA2_FEAA2[4];
        }
        for (i = 0; i < 19; i++) {
            if (c == D_800CD014_CDC14[i]) {
                break;
            }
        }
        frame = i;
    } else {
        if (large & 1) {
            if (D_800FD85C_FE45C[3] == -1) {
                anim = D_800FD85C_FE45C[3] = func_8006ADC4_6B9C4(0x3C);
            } else {
                anim = D_800FD85C_FE45C[3];
            }
        } else {
            if (D_800FDEA2_FEAA2[3] == -1) {
                anim = D_800FDEA2_FEAA2[3] = func_8006ADC4_6B9C4(0x3B);
            } else {
                anim = D_800FDEA2_FEAA2[3];
            }
        }

        switch (c) {
            case 0x85:
                frame = 7;
                break;
            case 0x84:
                frame = 2;
                break;
            case 0xC2:
            case 0xC4:
                frame = 1;
                break;
            case 0xC3:
            case 0xC5:
                frame = 3;
                break;
            case '=':
                frame = 4;
                break;
            case '\\':
                frame = 5;
                break;
            case '}':
                frame = 6;
                break;
            case 0:
            case ' ':
            default:
                frame = 0;
                break;
        }
    }

    return (anim << 16) | frame;
}

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

s32 func_8006AE38_6BA38(GAMEMES* arg0, Gfx** arg1) {
    return func_8006B1BC_6BDBC(arg0, 0xB00D9, 0xD8);
}

/* MP1 func_8007708C: str in the large font, falling away at the end; plays sound on the
   first frame */
s32 func_8006AE5C_6BA5C(GAMEMES* gMes, char* str, s16 sound) {
    f64 var_f2;
    f32 temp_f24;
    f32 temp_f30;
    f32 i;

    var_f2 = func_800A5610_A6210(str);
    temp_f30 = var_f2;

    if (gMes->unk04 == 0) {
        func_8006A67C_6B27C(gMes, str, 1, -1, -1);
        SprPosSet(gMes->strGId[0], 0, 160, gMes->unk64);
        gMes->unk08 = -1000;
        gMes->unk0A = 300;
        PlaySound(sound);
        D_80102708_103308 = 1;
    }

    if (gMes->unk04 > gMes->unk06 || D_800FD432_FE032 != 0 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        return 0;
    }

    if (gMes->unk04 > gMes->unk06 - 10) {
        gMes->stat = 2;
        temp_f24 = gMes->unk04 - (gMes->unk06 - 10);

        for (i = 0.0f; i < temp_f30; i++) {
            SprScaleSet(gMes->strGId[0], i + 1.0f, 1.8f - temp_f24 / 6.0f, 1.8f - temp_f24 / 6.0f);
            func_80082488_83088(gMes->strGId[0], i + 1.0f, 255.0f - temp_f24 * 25.5f);
        }

        gMes->unk08 += gMes->unk0A;
        gMes->unk64 += gMes->unk08 / 100.0f;

        SprPosSet(gMes->strGId[0], 0, 160, gMes->unk64);
    } else {
        for (i = 0.0f; i < temp_f30; i++) {
            SprScaleSet(gMes->strGId[0], i + 1.0f, 1.8f, 1.8f);
        }
    }

    return 1;
}

/* A two-frame picture (file fileId and fileId + 1) that flies off up and right */
s32 func_8006B1BC_6BDBC(GAMEMES* gMes, s32 fileId, s16 sound) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, fileId);
            PlaySound(sound);
            D_80102708_103308 = 1;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            gMes->unk68 = 1.0f;
            gMes->unk6C = 1.0f;
            gMes->unk70 = 0.0f;
            gMes->unk03 = 0xFF;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            SprRotSet(gMes->strGId[0], 0, gMes->unk70);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            gMes->unk08 = 1;
            break;
        case 1:
            if (gMes->unk04 >= 25) {
                gMes->unk08 = 2;
            }
            break;
        case 2:
            gMes->unk60 += 8.0f;
            gMes->unk64 -= 6.0f;
            gMes->unk6C = gMes->unk68 = gMes->unk68 - 0.06f;
            gMes->unk03 -= 17;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            if (gMes->unk04 > gMes->unk06 - 10) {
                gMes->stat = 2;
            }
            if (gMes->unk04 >= 40) {
                gMes->unk08 = 3;
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, 0);
                }
            }
            break;
        case 3:
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 4;
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            ret = FALSE;
            break;
    }
    return ret;
}

/* The two-frame picture 0xB00D9 bobbing and fading */
s32 func_8006B4C4_6C0C4(GAMEMES* gMes, Gfx** arg1) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 4;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00D9);
            PlaySound(0xD8);
            D_80102708_103308 = 1;
            gMes->unk68 = 1.0f;
            gMes->unk6C = 1.0f;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, 255);
            }
            gMes->unk08 = 1;
            gMes->unk0A = 0;
            gMes->unk0C = 0;
            gMes->unk0E = 9;
            gMes->unk10 = 0.0f;
            break;
        case 1:
            if (gMes->unk04 >= 25) {
                gMes->unk08 = 2;
            }
            break;
        case 2:
            gMes->unk68 = 1.0f - gMes->unk10;
            gMes->unk6C = 1.0f - gMes->unk10;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f - HuMathSin(gMes->unk0A) * 50.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, func_800B7890_B8490(gMes->unk0C) * 255.0f);
            }
            gMes->unk0A += gMes->unk0E;
            gMes->unk0C += 4;
            gMes->unk10 += 0.035f;
            if (gMes->unk04 > gMes->unk06 - 10) {
                gMes->stat = 2;
            }
            if (gMes->unk04 >= gMes->unk06) {
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, 0);
                }
                gMes->unk08 = 4;
            }
            break;
        case 4:
            func_8006985C_6A45C(gMes);
            ret = FALSE;
            break;
    }
    return ret;
}

/* The two-frame picture 0xB00D9 bouncing, then shrinking out. Closing jumps to state 5 (hold),
   not 6 (kill), as in retail. */
s32 func_8006B858_6C458(GAMEMES* gMes, Gfx** arg1) {
    s32 ret;
    s32 i;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006BD2C_6C92C(gMes, 0xB00D9);
            PlaySound(0xD8);
            D_80102708_103308 = 1;
            gMes->unk68 = 1.0f;
            gMes->unk6C = 1.0f;
            gMes->unk60 = 160.0f;
            gMes->unk64 = 120.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, 255);
            }
            gMes->unk08 = 1;
            break;
        case 1:
            if (gMes->unk04 >= 10) {
                gMes->unk08 = 2;
                gMes->unk14 = -4.0f;
            }
            break;
        case 2:
            gMes->unk64 += gMes->unk14;
            gMes->unk14 += 1.5f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            if (gMes->unk64 >= 120.0f) {
                gMes->unk64 = 120.0f;
                gMes->unk14 = -6.0f;
                gMes->unk08 = 3;
            }
            break;
        case 3:
            gMes->unk64 += gMes->unk14;
            gMes->unk14 += 1.5f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            if (gMes->unk64 >= 120.0f) {
                gMes->unk64 = 120.0f;
                gMes->unk14 = -10.0f;
                gMes->unk10 = 0.0f;
                gMes->unk08 = 4;
                gMes->unk0A = 0;
                gMes->unk0C = 0;
            }
            break;
        case 4:
            gMes->unk64 += gMes->unk14;
            gMes->unk10 += 0.058333334f;
            gMes->unk68 = 1.0f - gMes->unk10;
            gMes->unk6C = 1.0f - gMes->unk10;
            gMes->unk0C += 7;
            gMes->unk14 += 1.0f;
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, func_800B7890_B8490(gMes->unk0C) * 255.0f);
            }
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            if (gMes->unk04 > gMes->unk06 - 10) {
                gMes->stat = 2;
            }
            if (++gMes->unk0A >= 12) {
                for (i = 0; i < 2; i++) {
                    func_80082488_83088(gMes->strGId[0], i, 0);
                }
                gMes->unk08 = 5;
            }
            break;
        case 5:
            gMes->stat = 2;
            if (gMes->unk04 >= gMes->unk06) {
                gMes->unk08 = 6;
            }
            break;
        case 6:
            func_8006985C_6A45C(gMes);
            D_80102708_103308 = 0;
            ret = FALSE;
            break;
    }
    return ret;
}

/* MP1 func_8007767C: a two-member group from files fileId and fileId + 1 */
void func_8006BD2C_6C92C(GAMEMES* gMes, s32 fileId) {
    void* temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v0_5;

    temp_v0 = DataReadTemp(fileId);
    gMes->strSprId[0] = temp_v0_2 = SprAnimRead(temp_v0);
    DataCloseTemp(temp_v0);

    temp_v0 = DataReadTemp(fileId + 1);
    gMes->strSprId[1] = temp_v0_4 = SprAnimRead(temp_v0);
    DataCloseTemp(temp_v0);

    gMes->strGId[0] = temp_v0_5 = SprCreate(2, 5);

    SprAnimSet(temp_v0_5, 0, temp_v0_2, 0);
    func_80082488_83088(temp_v0_5, 0, 0xFF);
    SprPrioSet(temp_v0_5, 0, 5);
    SprAttrReset(temp_v0_5, 0, 0xFFFF);
    SprAttrSet(temp_v0_5, 0, 0x1008);
    SprPosSet(temp_v0_5, 0, 0xA0, gMes->unk64);
    func_800824F4_830F4(temp_v0_5, 0, -1);
    SprAnimSet(temp_v0_5, 1, temp_v0_4, 0);
    func_80082488_83088(temp_v0_5, 1, 0xFF);
    SprPrioSet(temp_v0_5, 1, 6);
    SprAttrReset(temp_v0_5, 1, 0xFFFF);
    SprAttrSet(temp_v0_5, 1, 0x1008);
    func_80082450_83050(temp_v0_5, 1, 0x45, 2, 0x85);
    func_800824F4_830F4(temp_v0_5, 1, 0);
}

/* Character names for D_800CD028_CDC28 (.data) */
const char D_800D32D4_D3ED4[] = "  ALL  ";
const char D_800D32DC_D3EDC[] = "  DK   ";
const char D_800D32E4_D3EE4[] = " WARIO ";
const char D_800D32EC_D3EEC[] = " YOSHI ";
const char D_800D32F4_D3EF4[] = " PEACH ";
const char D_800D32FC_D3EFC[] = " LUIGI ";
const char D_800D3304_D3F04[] = " MARIO ";

/* "<name> WON": unk0E is the character; the second word wobbles */
s32 func_8006BEE8_6CAE8(GAMEMES* gMes, Gfx** arg1) {
    char sp18[] = "WON\xC4 ";
    f64 var_f4;
    f64 var_f2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 i;
    s32 ret;

    var_f4 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    temp_f24 = var_f4;
    var_f2 = func_800A5610_A6210(sp18);
    temp_f28 = var_f2;

    if (D_800FD432_FE032 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = TRUE;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, sp18, 1, -1, -1);
            temp_f22 = temp_f24 + temp_f28 + 1.0f;
            gMes->unk60 = gMes->unk0A = 160.0f - temp_f22 * 22.0f / 2.0f + temp_f24 * 22.0f / 2.0f;
            gMes->unk64 = 180.0f;
            gMes->unk68 = gMes->unk6C = 1.0f;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < temp_f24;) {
                i++;
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, 255);
            }
            gMes->unk60 = gMes->unk0C =
                160.0f - temp_f22 * 22.0f / 2.0f + temp_f24 * 22.0f / 2.0f + temp_f24 * 22.0f;
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
            for (i = 0.0f; i < temp_f28;) {
                i++;
                SprScaleSet(gMes->strGId[1], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[1], i, 255);
            }
            gMes->unk08 = 1;
            gMes->unk10 = 0.0f;
            gMes->unk14 = 0.0f;
            break;
        case 1:
            gMes->unk64 = HuMathSin(gMes->unk14) + 180.0f;
            gMes->unk60 = gMes->unk0C + HuMathSin(gMes->unk10);
            SprPosSet(gMes->strGId[1], 0, gMes->unk60, gMes->unk64);
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
            ret = FALSE;
            break;
    }
    if (gMes->unk04 >= 51) {
        gMes->stat = 2;
    }
    return ret;
}

/* MP1 func_80077FC4: "<name> LOSES", unk08 the character */
s32 func_8006C3F4_6CFF4(GAMEMES* gMes, Gfx** arg1) {
    char sp18[] = "LOSES";
    f64 var_f2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f2;
    f32 temp_f30;
    s16 i;

    var_f2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk08]);
    temp_f30 = var_f2;

    var_f2 = func_800A5610_A6210(sp18);
    temp_f2 = var_f2;

    if (gMes->unk04 == 0) {
        func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk08], 1, -1, -1);
        func_8006A67C_6B27C(gMes, sp18, 1, -1, -1);

        temp_f20 = (320.0f - (temp_f30 + temp_f2 + 1.0f) * 24.0f) / 2.0f;

        SprPosSet(gMes->strGId[0], 0, temp_f20 + temp_f30 * 24.0f / 2.0f, gMes->unk64 + 40.0f);
        SprPosSet(gMes->strGId[1], 0, (320.0f - temp_f20) - temp_f2 * 24.0f / 2.0f, gMes->unk64 + 40.0f);

        for (i = 0; i < temp_f30; i++) {
            SprAttrSet(gMes->strGId[0], i + 1, 0x8000);
        }

        for (i = 0; i < temp_f2; i++) {
            SprAttrSet(gMes->strGId[1], i + 1, 0x8000);
        }

        gMes->unk0A = 0;
    }

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        return 0;
    }

    if (gMes->unk04 >= 81) {
        gMes->stat = 2;
    }

    if (gMes->unk04 >= 51) {
        gMes->unk0A++;
        if (gMes->unk0A & 0x40) {
            temp_f20_3 = (u16)gMes->unk0A % 32;
            temp_f20_2 = func_800B7890_B8490(temp_f20_3 * (360.0f / 31)) * 55.0f + 200.0f;

            for (i = 0; i < temp_f30; i++) {
                func_80082488_83088(gMes->strGId[0], i + 1, temp_f20_2);
            }

            for (i = 0; i < temp_f2; i++) {
                func_80082488_83088(gMes->strGId[1], i + 1, temp_f20_2);
            }
        }

        return 1;
    }

    temp_f20_3 = gMes->unk04;
    if (temp_f20_3 <= 30.0f) {
        for (i = 0; i < temp_f30; i++) {
            SprAttrReset(gMes->strGId[0], i + 1, 0x8000);
            func_80082488_83088(gMes->strGId[0], i + 1, temp_f20_3 * 8.5f);
        }
    }

    temp_f20_3 = gMes->unk04 - 20;
    if (temp_f20_3 <= 30.0f && temp_f20_3 > 0.0f) {
        for (i = 0; i < temp_f2; i++) {
            SprAttrReset(gMes->strGId[1], i + 1, 0x8000);
            func_80082488_83088(gMes->strGId[1], i + 1, temp_f20_3 * 8.5f);
        }
    }

    return 1;
}

/* MP1 func_800786F0: the message unk1C (decoded into a buffer), popping in */
s32 func_8006CB20_6D720(GAMEMES* gMes, Gfx** arg1) {
    f32 temp_f22;
    f32 i;

    if (gMes->unk04 == 0) {
        u8* temp_v0 = HuMemMemoryAllocPerm(256);

        func_8008D4DC_8E0DC(temp_v0, gMes->unk1C);
        func_8006A67C_6B27C(gMes, temp_v0, gMes->unk02, -1, -1);
        gMes->unk08 = func_800A5610_A6210(temp_v0);
        SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);

        HuMemMemoryFreePerm(temp_v0);
    }

    if (gMes->unk04 > gMes->unk06 || D_800FD432_FE032 != 0 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        return 0;
    }

    if (gMes->unk04 < 14) {
        temp_f22 = HuMathSin(gMes->unk04 * 10.0f) + (1.0f - HuMathSin(130.0f));

        for (i = 0.0f; i < gMes->unk08; i++) {
            SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, temp_f22 * gMes->unk6C);
        }
    }

    if (gMes->unk04 > gMes->unk06 - 10) {
        gMes->stat = 2;
        temp_f22 = func_800B7890_B8490((gMes->unk04 - (gMes->unk06 - 10)) * 9.0f);

        for (i = 0.0f; i < gMes->unk08; i++) {
            SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, temp_f22 * gMes->unk6C);
        }
    }

    return 1;
}

/* MP1 func_800789C0: the message unk1C at unk60/unk64, rotated, scaled and faded by the caller */
s32 func_8006CDF0_6D9F0(GAMEMES* gMes, Gfx** arg1) {
    f32 i;

    if (gMes->unk04 == 0) {
        u8* temp_v0 = HuMemMemoryAllocPerm(256);

        func_8008D4DC_8E0DC(temp_v0, gMes->unk1C);
        func_8006A67C_6B27C(gMes, temp_v0, gMes->unk02, -1, -1);
        gMes->unk08 = func_800A5610_A6210(temp_v0);

        HuMemMemoryFreePerm(temp_v0);
    }

    if (gMes->unk04 > gMes->unk06 || D_800FD432_FE032 != 0 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        return 0;
    }

    SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
    SprRotSet(gMes->strGId[0], 0, gMes->unk70);

    for (i = 0.0f; i < gMes->unk08; i++) {
        SprScaleSet(gMes->strGId[0], i + 1.0f, gMes->unk68, gMes->unk6C);
        func_80082488_83088(gMes->strGId[0], i + 1.0f, gMes->unk03);
    }

    return 1;
}

/* MP3 GMesTimerExec: the two-digit countdown; unk08 is the value */
s32 func_8006CF9C_6DB9C(GAMEMES* gMes, Gfx** arg1) {
    f32 temp_f22;
    u8 temp_s2;
    u8 temp_s0;

    if (gMes->unk04 == 0) {
        func_8006A67C_6B27C(gMes, "99", 0, -1, -1);
        SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
        func_80082488_83088(gMes->strGId[0], 1, 0x100);
        func_80082488_83088(gMes->strGId[0], 2, 0x100);
        gMes->unk0A = 0;
    }
    temp_s2 = gMes->unk08 % 100;
    temp_s0 = temp_s2 / 10;
    if (temp_s0 == 0) {
        SprAttrSet(gMes->strGId[0], 1, 0x8000);
    } else {
        SprAttrReset(gMes->strGId[0], 1, 0x8000);
    }
    func_800822A8_82EA8(gMes->strGId[0], 1, temp_s0, 0);
    func_8008225C_82E5C(gMes->strGId[0], 1, 1);
    temp_s0 = temp_s2 % 10;
    func_800822A8_82EA8(gMes->strGId[0], 2, temp_s0, 0);
    func_8008225C_82E5C(gMes->strGId[0], 2, 1);
    switch (gMes->unk0A) {
        case 0:
            if (gMes->unk04 < 14) {
                temp_f22 = HuMathSin(gMes->unk04 * 10.0f) * 5.0f + (1.0f - HuMathSin(130.0f) * 5.0f);
                SprScaleSet(gMes->strGId[0], 1, temp_f22, temp_f22);
                SprScaleSet(gMes->strGId[0], 2, temp_f22, temp_f22);
            } else {
                gMes->unk0A = 1;
            }
            break;
        case 1:
            if (gMes->unk0E != gMes->unk08 && gMes->unk08 < 6) {
                gMes->unk0C = 0;
                if (gMes->unk08 != 0) {
                    gMes->unk0A = 3;
                    PlaySound(8);
                }
            } else {
                func_80082488_83088(gMes->strGId[0], 1, 0x100);
                func_80082488_83088(gMes->strGId[0], 2, 0x100);
            }
            break;
        case 2:
            if (gMes->unk0C < 10) {
                func_80082488_83088(gMes->strGId[0], 1, 230 - gMes->unk0C * 23);
                func_80082488_83088(gMes->strGId[0], 2, 230 - gMes->unk0C * 23);
            } else {
                gMes->unk0A = 1;
                gMes->stat = 4;
            }
            gMes->unk0C++;
            break;
        case 3:
            if (gMes->unk0C < 11) {
                temp_f22 = 1.0f + HuMathSin(gMes->unk0C * 18.0f);
                SprScaleSet(gMes->strGId[0], 1, temp_f22, temp_f22);
                SprScaleSet(gMes->strGId[0], 2, temp_f22, temp_f22);
                temp_f22 = 230.0f - HuMathSin(gMes->unk0C * 18.0f) * 60.0f;
                func_80082488_83088(gMes->strGId[0], 1, temp_f22);
                func_80082488_83088(gMes->strGId[0], 2, temp_f22);
            } else {
                gMes->unk0A = 1;
            }
            gMes->unk0C++;
            break;
    }
    gMes->unk0E = gMes->unk08;
    if (D_800FD432_FE032 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        D_8010002D_100C2D = -1;
        return FALSE;
    }
    return TRUE;
}

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

/* MP1 func_80079104 */
s32 func_8006D55C_6E15C(GAMEMES* gMes, Gfx** arg1) {
    return func_8006D580_6E180(gMes, "GREAT\xC4", -1);
}

/* MP1 func_80079128: str's letters fly in, then pulse; plays sound (unless -1) on frame 20 */
s32 func_8006D580_6E180(GAMEMES* gMes, char* str, s16 sound) {
    f32 a;
    f32 x;
    f32 y;
    f32 b;
    s16 i;
    u16 t;
    f32 c;
    f32 c2;
    f32 nb;
    f32 y2;

    if (gMes->unk04 == 0) {
        func_8006A67C_6B27C(gMes, str, 1, -1, -1);
        SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
        gMes->unk08 = func_800A5610_A6210(str);
        for (i = 0; i < gMes->unk08; i++) {
            SprAttrSet(gMes->strGId[0], i + 1, 0x8000);
        }
        D_80102708_103308 = 1;
    }

    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        func_8006985C_6A45C(gMes);
        return 0;
    }

    if ((gMes->unk04 == 20) & (sound != -1)) {
        PlaySound(sound);
    }

    if (gMes->unk04 >= 69) {
        gMes->stat = 2;
    }

    if (gMes->unk04 > 20 && gMes->unk04 < 39) {
        t = gMes->unk04 - 20;
        for (i = 0; i < gMes->unk08; i++) {
            SprScaleSet(gMes->strGId[0], i + 1, HuMathSin((s16)t * 10) * 0.5f + 1.0, HuMathSin((s16)t * 10) * 0.5f + 1.0);
        }
    } else if (gMes->unk04 < 16) {
        for (i = 0; i < gMes->unk08; i++) {
            t = gMes->unk04;
            if (t >= 15) {
                SprPosSet(gMes->strGId[0], i + 1, -(gMes->unk08 * 22) / 2 + i * 22 + 12, 0);
            } else {
                a = HuMathSin(i * 10 + 430) * 100.0f;
                c = gMes->unk08 * -11 + 12;
                if (!(i & 1)) {
                    a = -a;
                }
                x = c - a;
                y = -(func_800B7890_B8490(i * 20 + 430) * 50.0f);
                SprAttrReset(gMes->strGId[0], i + 1, 0x8000);
                b = (15 - (s16)t) * 10 + HuMathSin((s16)t * 20 + 130 + i * 10) * 100.0f;
                c2 = x + i * 22;
                if (!(i & 1)) {
                    nb = -b;
                    x = c2 + nb;
                } else {
                    x = c2 + b;
                }
                y2 = y + func_800B7890_B8490((s16)t * 20 + 130 + i * 20) * 50.0f;
                SprPosSet(gMes->strGId[0], i + 1, x, y2);
            }
        }
    }

    return 1;
}

/* MP1 func_80079608 */
s32 func_8006DA60_6E660(GAMEMES* gMes, Gfx** arg1) {
    return func_8006D580_6E180(gMes, "BRAVO\xC4", -1);
}

s32 func_8006DA84_6E684(GAMEMES* gMes, Gfx** arg1) {
    return func_8006D580_6E180(gMes, "STRIKE\xC4", 0xD2);
}

/* w1-B */
#define GMES_ABSF(x) (((x) < 0.0f) ? -(x) : (x))


s16 func_8006A67C_6B27C(GAMEMES* gMes, char* str, u8 arg2, s16 arg3, s16 arg4);
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

/* "NEW RECORD" banner: the two words scale and spin in, hold, then fade out. */
s32 func_8006DAA8_6E6A8(GAMEMES* gMes, Gfx** arg1) {
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
            gMes->unk70 = 0.0f;
            SprPosSet(gMes->strGId[1], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            SprRotSet(gMes->strGId[1], 0, gMes->unk70);
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
            gMes->unk70 += 12.0f;
            gMes->unk03 += 8;
            SprPosSet(gMes->strGId[0], 0, (gMes->unk60 - 160.0f) + x, gMes->unk64);
            SprRotSet(gMes->strGId[0], 0, gMes->unk70);
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
s32 func_8006E1C0_6EDC0(GAMEMES* gMes, Gfx** arg1) {
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
s32 func_8006E45C_6F05C(GAMEMES* gMes, Gfx** arg1) {
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
s32 func_8006E71C_6F31C(GAMEMES* gMes, Gfx** arg1) {
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
s32 func_8006EB78_6F778(GAMEMES* gMes, Gfx** arg1) {
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
s32 func_8006F10C_6FD0C(GAMEMES* gMes, Gfx** arg1) {
    char won[] = "WON\xC4 ";
    s32 ret;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 i;

    len1 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0C]);
    len2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    len3 = func_800A5610_A6210(won);
    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0C], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, won, 1, -1, -1);
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
s32 func_8006F924_70524(GAMEMES* gMes, Gfx** arg1) {
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
            gMes->unk70 = 0.0f;
            gMes->unk03 = 0xFF;
            SprPosSet(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
            SprRotSet(gMes->strGId[0], 0, gMes->unk70);
            for (i = 0; i < 2; i++) {
                SprScaleSet(gMes->strGId[0], i, gMes->unk68, gMes->unk6C);
                func_80082488_83088(gMes->strGId[0], i, gMes->unk03);
            }
            gMes->unk08 = 1;
            break;
        case 1:
            gMes->unk6C = gMes->unk68 += 0.05f;
            gMes->unk70 += 36.0f;
            SprRotSet(gMes->strGId[0], 0, gMes->unk70);
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
s32 func_8006FCE4_708E4(GAMEMES* gMes, Gfx** arg1) {
    char won[] = "WON\xC4 ";
    s32 ret;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 len4;
    f32 i;

    len1 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0A]);
    len2 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0C]);
    len3 = func_800A5610_A6210(D_800CD028_CDC28[gMes->unk0E]);
    len4 = func_800A5610_A6210(won);
    if (D_800FD432_FE032 != 0 || gMes->stat == 4) {
        gMes->unk08 = 5;
    }
    ret = 1;
    switch (gMes->unk08) {
        case 0:
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0A], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0C], 1, -1, -1);
            func_8006A67C_6B27C(gMes, D_800CD028_CDC28[gMes->unk0E], 1, -1, -1);
            func_8006A67C_6B27C(gMes, won, 1, -1, -1);
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
s32 func_800708AC_714AC(GAMEMES* gMes, Gfx** arg1) {
    char won[] = "WON\xC4 ";
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
    len5 = func_800A5610_A6210(won);
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
            func_8006A67C_6B27C(gMes, won, 1, -1, -1);
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
                gMes->unk18 = 0.0f;
            }
            break;
        case 4:
            gMes->unk60 = HuMathSin(gMes->unk14) + 160.0f;
            gMes->unk64 = HuMathSin(gMes->unk18) + 120.0f;
            SprPosSet(gMes->strGId[4], 0, gMes->unk60, gMes->unk64);
            gMes->unk14 += 90.0f;
            gMes->unk18 += 45.0f;
            if (gMes->unk14 >= 360.0f) {
                gMes->unk14 = 0.0f;
            }
            if (gMes->unk18 >= 360.0f) {
                gMes->unk18 = 0.0f;
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
s32 func_80071928_72528(GAMEMES* gMes, Gfx** arg1) {
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
s32 func_80071FDC_72BDC(GAMEMES* gMes, Gfx** arg1) {
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
