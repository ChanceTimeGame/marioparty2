#include "common.h"

/* Debug print font and windows. Same code as Mario Party 1's src/62140.c (tools/n64xref.py: every
   function an exact match); names follow MP1. DrawDebugText is MP1's print8. */

typedef struct StrLine {
    /* 0x00 */ u16 color;
    /* 0x02 */ u16 x;
    /* 0x04 */ u16 y;
    /* 0x06 */ u16 next;
    /* 0x08 */ u8 str[0x40];
} StrLine; // size 0x48

typedef struct PfWin {
    /* 0x00 */ u16 activeBool;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 xPosStart;
    /* 0x08 */ s32 yPosStart;
    /* 0x0C */ s32 width;
    /* 0x10 */ s32 height;
    /* 0x14 */ u32 rgba;
} PfWin; // size 0x18

typedef struct SaftyFrameColor {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ s8 rStep;
    /* 0x04 */ s8 gStep;
    /* 0x05 */ s8 bStep;
    /* 0x06 */ u8 rMax;
    /* 0x07 */ u8 gMax;
    /* 0x08 */ u8 bMax;
    /* 0x09 */ u8 rMin;
    /* 0x0A */ u8 gMin;
    /* 0x0B */ u8 bMin;
    /* 0x0C */ s8 unk_0C;
} SaftyFrameColor;

extern u8 pfFontTex[];
extern u16 pfFontTlut[16][16];
extern u16 pfFontCurPal;
extern StrLine pfStrLines[0x200];
extern s32 fontcolor;
extern PfWin pfWinData[4];
extern u16 strlinecnt;
extern u16 saftyFrameF;
extern SaftyFrameColor saftyFrameColor;
extern u16 empstrline;
extern u16 emppfwin;

void pfClsScr(void);

void pfInit(void) {
    s32 i;

    fontcolor = 15;
    empstrline = 0;
    for (i = 0; i < 0x200; i++) {
        pfStrLines[i].str[0] = 0;
    }
    pfClsScr();
    emppfwin = 0;
    for (i = 0; i < 4; i++) {
        pfWinData[i].activeBool = 0;
    }
    saftyFrameF = 0;
}

void pfClsScr(void) {
    s32 i;

    empstrline = 0;
    strlinecnt = 0;
    for (i = 0; i < 0x200; i++) {
        pfStrLines[i].next = i + 1;
        if (pfStrLines[i].str[0] != 0) {
            pfStrLines[i].str[0] = 0;
        }
    }
}

void pfClrStrLine(s16 id) {
    if (pfStrLines[id].str[0] != 0 && strlinecnt != 0) {
        strlinecnt--;
        pfStrLines[id].str[0] = 0;
        pfStrLines[id].next = empstrline;
        empstrline = id;
    }
}

s16 DrawDebugText(u16 x, u16 y, char* str) {
    StrLine* line = &pfStrLines[empstrline];
    u8* src;
    u8* dst;
    u16 id;

    if (strlinecnt < 0x200) {
        strlinecnt++;
        id = empstrline;
        empstrline = line->next;
        line->color = fontcolor;
        line->x = x;
        line->y = y;
        src = (u8*)str;
        for (dst = line->str; *src != 0; src++, dst++) {
            *dst = *src;
        }
        *dst = 0;
        return id;
    }
    return -1;
}

s16 pfWinCreate(s32 xPosStart, s32 yPosStart, s32 width, s32 height, s32 rgba) {
    PfWin* win;
    s32 i;

    if (emppfwin >= 4) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        if (pfWinData[i].activeBool == 0) {
            break;
        }
    }

    win = &pfWinData[i];
    win->activeBool = 1;
    win->xPosStart = xPosStart;
    win->yPosStart = yPosStart;
    win->width = width;
    win->height = height;
    win->rgba = rgba;
    emppfwin++;
    return i;
}

void pfWinKill(s16 id) {
    if (emppfwin != 0) {
        pfWinData[id].activeBool = 0;
        emppfwin = emppfwin - 1;
    }
}

void pfWinClose(void) {
    s32 i;
    emppfwin = 0;

    for (i = 0; i < 4; i++) {
        pfWinData[i].activeBool = 0;
    }
}

void saftyFrameSet(s8 r, s8 g, s8 b) {
    saftyFrameColor.r = r;
    saftyFrameColor.g = g;
    saftyFrameColor.b = b;
    saftyFrameColor.rStep = saftyFrameColor.gStep = saftyFrameColor.bStep = 0;
    saftyFrameF = 1;
}

void saftyFrameFlashSet(s8 rStep, s8 gStep, s8 bStep, s8 rMax, u8 gMax, u8 bMax, u8 rMin, u8 gMin, u8 bMin) {
    saftyFrameColor.rStep = rStep;
    saftyFrameColor.gStep = gStep;
    saftyFrameColor.bStep = bStep;
    saftyFrameColor.rMax = rMax;
    saftyFrameColor.gMax = gMax;
    saftyFrameColor.bMax = bMax;
    saftyFrameColor.rMin = rMin;
    saftyFrameColor.gMin = gMin;
    saftyFrameColor.bMin = bMin;
}

void saftyFrameFlashReset(void) {
    saftyFrameColor.rStep = saftyFrameColor.gStep = saftyFrameColor.bStep = 0;
}

void saftyFrameReset(void) {
    saftyFrameF = 0;
}

/* Overwrites a line's text in place (MP1 func_80062524); the null check is retail's. */
void func_8007C9B4_7D5B4(s16 id, u8* str) {
    u8* dst;

    if (&pfStrLines[id].str != NULL) {
        dst = pfStrLines[id].str;
        for (; *str != 0; dst++, str++) {
            *dst = *str;
        }
        *dst = 0;
    }
}

#define RGBA32_R(color) ((color) >> 24)
#define RGBA32_G(color) (((color) >> 16) & 0xFF)
#define RGBA32_B(color) (((color) >> 8) & 0xFF)
#define RGBA32_A(color) ((color) & 0xFF)
#define FILL_COLOR_RGBA5551(r, g, b, a) ((GPACK_RGBA5551(r, g, b, a) << 16) | GPACK_RGBA5551(r, g, b, a))

/* Steps one safety-frame channel toward its bound and bounces at it. */
#define SAFTY_STEP(val, step, max, min)                               \
    if (saftyFrameColor.step != 0) {                                  \
        speed = saftyFrameColor.step;                                 \
        if (speed < 0) {                                              \
            if (saftyFrameColor.val + speed >= saftyFrameColor.min) { \
                saftyFrameColor.val += speed;                         \
            } else {                                                  \
                saftyFrameColor.val = saftyFrameColor.min;            \
                saftyFrameColor.step = -saftyFrameColor.step;         \
            }                                                         \
        } else {                                                      \
            if (saftyFrameColor.val + speed <= saftyFrameColor.max) { \
                saftyFrameColor.val += speed;                         \
            } else {                                                  \
                saftyFrameColor.val = saftyFrameColor.max;            \
                saftyFrameColor.step = -saftyFrameColor.step;         \
            }                                                         \
        }                                                             \
    }

Gfx* pfDrawFonts(Gfx* gfx) {
    u16 count;
    s32 i;
    u16 pal;
    u16 color;
    u16 x;
    u16 y;
    u8* str;
    u8 c;
    s8 speed;

    count = strlinecnt;

    if (emppfwin != 0) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 319, 339);
        gDPPipeSync(gfx++);
        gDPSetTextureLOD(gfx++, G_TL_LOD);
        gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
        for (i = 0; i < 4; i++) {
            if (pfWinData[i].activeBool != 0) {
                if (RGBA32_A(pfWinData[i].rgba) == 0xFF) {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_FILL);
                    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
                    gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(RGBA32_R(pfWinData[i].rgba),
                                                               RGBA32_G(pfWinData[i].rgba),
                                                               RGBA32_B(pfWinData[i].rgba),
                                                               RGBA32_A(pfWinData[i].rgba)));
                } else {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
                    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
                    gDPSetPrimColor(gfx++, 0, 0, RGBA32_R(pfWinData[i].rgba),
                                    RGBA32_G(pfWinData[i].rgba), RGBA32_B(pfWinData[i].rgba),
                                    RGBA32_A(pfWinData[i].rgba));
                }
                gDPFillRectangle(gfx++, pfWinData[i].xPosStart, pfWinData[i].yPosStart,
                                 pfWinData[i].width, pfWinData[i].height);
            }
        }
    }

    if (saftyFrameF != 0) {
        SAFTY_STEP(r, rStep, rMax, rMin)
        SAFTY_STEP(g, gStep, gMax, gMin)
        SAFTY_STEP(b, bStep, bMax, bMin)
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(saftyFrameColor.r, saftyFrameColor.g,
                                                   saftyFrameColor.b, 1));
        gDPFillRectangle(gfx++, 24, 16, 296, 16);
        gDPFillRectangle(gfx++, 24, 224, 296, 224);
        gDPFillRectangle(gfx++, 24, 16, 24, 224);
        gDPFillRectangle(gfx++, 296, 16, 296, 224);
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 319, 339);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_COPY);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetTextureLOD(gfx++, G_TL_LOD);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPSetBlendColor(gfx++, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPLoadTextureBlock_4b(gfx++, pfFontTex, G_IM_FMT_CI, 64, 64, pfFontCurPal,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    for (pal = 0; pal < 16; pal++) {
        gDPLoadTLUT_pal16(gfx++, pal, pfFontTlut[pal]);
    }

    for (i = 0; i < 0x200; i++) {
        if (pfStrLines[i].str[0] != '\0') {
            str = pfStrLines[i].str;
            color = pfStrLines[i].color;
            x = pfStrLines[i].x;
            y = pfStrLines[i].y;
            if (color != pfFontCurPal) {
                pfFontCurPal = color;
                gDPTileSync(gfx++);
                gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, G_TX_RENDERTILE, color, 0, 0, 0, 0, 0, 0);
            }
            for (; *str != '\0'; str++) {
                if (*str >= ' ') {
                    c = *str - ' ';
                    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                                        ((c % 8) * 8) << 5, ((c / 8) * 8) << 5, 4 << 10, 1 << 10);
                    x += 8;
                    if (x >= 320) {
                        x = 0;
                        y += 8;
                    }
                }
            }
            if (--count == 0) {
                break;
            }
        }
    }

    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    return gfx;
}
