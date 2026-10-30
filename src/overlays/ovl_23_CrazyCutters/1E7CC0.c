#include "ovl_23.h"

/* Image pixel helpers (MP1 12AFE0.c). A sprite's current frame image is
   spr->unk_84->unk00[spr->unk_90]; its palette spr->unk_84->unk0C, format spr->unk_84->unk18. */

typedef s32 (*CCPixelFunc)(s32, s32, s32, u8*, s32);

/* Converts a sprite frame's image into a one-byte-per-pixel mask (0xFF where opaque). The caller
   frees it. [FC4F0] */
// register allocation and the 8-bit loop's scheduling (masked 6; MP1 masked 9)
#ifdef NON_MATCHING
u8* func_80108870_1E7CC0_CrazyCutters(s16 grpIdx, s16 idx, s32* width, s32* height) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* img;
    u8* buf;
    u8* src;
    u16* pal;
    u32 x;
    u32 y;
    s32 stride;
    u8 c;
    u8* dst;
    u16* pp;
    s32 off;

    spr = func_80082550_83150(grpIdx, idx);
    img = &spr->unk_84->unk00[spr->unk_90];
    buf = func_80027154_27D54(img->unk04 * img->unk06, 0x7918);
    src = img->unk00;
    pal = spr->unk_84->unk0C;
    *width = img->unk04;
    *height = img->unk06;
    switch (spr->unk_84->unk18 & 0xF) {
        case 4:
            stride = (img->unk04 + (img->unk04 & 1)) >> 1;
            for (y = 0; y < img->unk06; y++) {
                for (x = 0; x < img->unk04; x++) {
                    c = (src + stride * y)[x >> 1];
                    if (x & 1) {
                        c &= 0xF;
                    } else {
                        c >>= 4;
                    }
                    pp = pal + c;
                    dst = buf + img->unk04 * y + x;
                    if (*pp >= 0x80) {
                        *dst = 0xFF;
                    } else {
                        *dst = 0;
                    }
                }
            }
            break;
        case 8:
            for (y = 0; y < img->unk06; y++) {
                for (x = 0; x < img->unk04; x++) {
                    off = img->unk04 * y;
                    c = (src + off)[x];
                    if (pal[c] & 1) {
                        *(buf + off + x) = 0xFF;
                    } else {
                        *(buf + off + x) = 0;
                    }
                }
            }
            break;
    }
    return buf;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E7CC0", func_80108870_1E7CC0_CrazyCutters);
#endif

/* Writes the palette's transparent index into the sprite image wherever mask is set, at (x0, y0).
   Returns the number of pixels that changed. [FC70C] */
s32 func_80108A8C_1E7EDC_CrazyCutters(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* img;
    u8* pixels;
    CCPixelFunc fn;
    s32 col;
    s32 x;
    s32 y;
    s32 count;
    s32 px;
    s32 py;
    s32 ww = w;
    s32 hh = h;

    fn = NULL;
    spr = func_80082550_83150(grpIdx, idx);
    col = func_80108DA0_1E81F0_CrazyCutters(spr->unk_84->unk0C, spr->unk_84->unk18);
    img = &spr->unk_84->unk00[spr->unk_90];
    pixels = img->unk00;
    switch (spr->unk_84->unk18 & 0xF) {
        case 4:
            fn = (CCPixelFunc)func_80108D18_1E8168_CrazyCutters;
            break;
        case 8:
            fn = (CCPixelFunc)func_80108D74_1E81C4_CrazyCutters;
            break;
    }
    count = 0;
    for (y = 0; y < hh; y++) {
        for (x = 0; x < ww; x++) {
            px = x + x0;
            py = y + y0;
            if (px < 0) {
                continue;
            }
            if (px >= img->unk04) {
                continue;
            }
            if (py < 0) {
                continue;
            }
            if (py >= img->unk06) {
                continue;
            }
            if ((mask + ww * y)[x] != 0) {
                count += fn(px, py, img->unk04, pixels, col & 0xFF) != 0;
            }
        }
    }
    return count;
}

/* Writes the transparent index at one pixel. [FC8C0] */
s32 func_80108C40_1E8090_CrazyCutters(s16 grpIdx, s16 idx, s32 x, s32 y) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* img;
    u8* pixels;
    s32 col;

    spr = func_80082550_83150(grpIdx, idx);
    col = func_80108DA0_1E81F0_CrazyCutters(spr->unk_84->unk0C, spr->unk_84->unk18);
    img = &spr->unk_84->unk00[spr->unk_90];
    pixels = img->unk00;
    switch (spr->unk_84->unk18 & 0xF) {
        case 4:
            return func_80108D18_1E8168_CrazyCutters(x, y, img->unk04, pixels, col & 0xFF);
        case 8:
            return func_80108D74_1E81C4_CrazyCutters(x, y, img->unk04, pixels, col & 0xFF);
        default:
            return 0;
    }
}

/* 4-bit image: set pixel (x, y) to index c. [FC998] */
s32 func_80108D18_1E8168_CrazyCutters(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4) {
    s32 new_var = arg4;
    s32 var_v0;
    s32 var_v1;
    u8* temp_a3;

    temp_a3 = (arg3 + (((arg2 >> 1) + (arg2 & 1)) * arg1)) + (arg0 >> 1);
    if ((arg0 & 1) != 0) {
        var_v0 = (*temp_a3) & 0xF0;
        var_v1 = arg4 & 0xF;
    } else {
        var_v0 = (*temp_a3) & 0xF;
        var_v1 = arg4 * 0x10;
    }
    *temp_a3 = var_v0 | var_v1;
    var_v1 = new_var & 0xF;
    return 0;
}

/* 8-bit image: set pixel (x, y) to index c; nonzero if it changed. [FC9F4] */
s32 func_80108D74_1E81C4_CrazyCutters(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4) {
    u8 temp_v1;
    u8* temp_a3;

    temp_a3 = arg3 + (arg2 * arg1) + arg0;
    temp_v1 = *temp_a3;
    *temp_a3 = arg4;
    return *temp_a3 != temp_v1;
}

/* Returns the first palette index whose alpha bit is clear; with none, clears one and returns the
   last index. Retail's fallback entry is (n - 1) * n, past the palette (kept as retail). [FCA20] */
s32 func_80108DA0_1E81F0_CrazyCutters(u8* pal, u16 fmt) {
    u16 n;
    u16 i;

    n = 0x100;
    if ((fmt & 0xF) == 4) {
        n = 0x10;
    }
    for (i = 0; i < n; i++) {
        if (!(pal[i * 2 + 1] & 1)) {
            return i;
        }
    }
    pal[(n - 1) * i * 2 + 1] &= ~1;
    return (u16)(n - 1);
}

/* As func_80108A8C_1E7EDC_CrazyCutters, but only counts the masked pixels that differ from the
   transparent index. [FCAAC] */
s32 func_80108E2C_1E827C_CrazyCutters(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* img;
    u8* pixels;
    CCPixelFunc fn;
    s32 col;
    s32 x;
    s32 y;
    s32 count;
    s32 px;
    s32 py;
    s32 ww;
    s32 hh;

    spr = func_80082550_83150(grpIdx, idx);
    ww = w;
    hh = h;
    fn = NULL;
    col = func_80108DA0_1E81F0_CrazyCutters(spr->unk_84->unk0C, spr->unk_84->unk18);
    img = &spr->unk_84->unk00[spr->unk_90];
    pixels = img->unk00;
    switch (spr->unk_84->unk18 & 0xF) {
        case 4:
            fn = (CCPixelFunc)func_80108FE4_1E8434_CrazyCutters;
            break;
        case 8:
            fn = (CCPixelFunc)D_80109044_1E8494_CrazyCutters;
            break;
    }
    count = 0;
    for (y = 0; y < hh; y++) {
        for (x = 0; x < ww; x++) {
            px = x + x0;
            py = y + y0;
            if (px < 0) {
                continue;
            }
            if (px >= img->unk04) {
                continue;
            }
            if (py < 0) {
                continue;
            }
            if (py >= img->unk06) {
                continue;
            }
            if ((mask + ww * y)[x] != 0) {
                count += fn(px, py, img->unk04, pixels, col & 0xFF) != 0;
            }
        }
    }
    return count;
}

/* 4-bit image: nonzero if pixel (x, y) is not index c. [FCC64] */
s32 func_80108FE4_1E8434_CrazyCutters(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4) {
    s32 new_var = arg4;
    s32 var_v0;
    s32 var_v1;
    u8* temp_a3;

    temp_a3 = arg3 + (((arg2 >> 1) + (arg2 & 1)) * arg1) + (arg0 >> 1);
    if ((arg0 & 1) != 0) {
        var_v0 = *temp_a3 & 0xF0;
        var_v1 = arg4 & 0xF;
    } else {
        var_v0 = *temp_a3 & 0xF;
        var_v1 = arg4 * 0x10;
    }
    var_v0 = ((var_v0 | var_v1) ^ arg4) & 0xFF;
    var_v1 = new_var & 0xF;
    return var_v0 != 0;
}

/* Retail has one nop between func_80108FE4 and func_80109048, and func_80108E2C takes the address
   of that nop (D_80109044) as its 8-bit pixel test: running the nop first is harmless. */
__asm__(".globl D_80109044_1E8494_CrazyCutters\n.type D_80109044_1E8494_CrazyCutters,@function\n"
        "D_80109044_1E8494_CrazyCutters:\n.word 0\n");

/* 8-bit image: nonzero if pixel (x, y) is not index c. [FCCC8] */
s32 func_80109048_1E8498_CrazyCutters(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4) {
    return arg4 != *(arg3 + (arg2 * arg1) + arg0);
}
