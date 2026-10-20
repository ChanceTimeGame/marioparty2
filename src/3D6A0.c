#include "common.h"
#include "game/hmfman.h"

/* Model textures and texture animation (MP1 src/388E0.c) and texture-load display lists
   (MP1 src/3AC60.c). Functions without MP1 C stay asm. The rest of the unit's rodata
   (D2EE0-D2F40, strings) belongs to asm functions; only func_8004075C's doubles at its tail are
   carved. MP2's model structs have MP3's layout; fields are named by their MP2 offset
   (MP1 offset in the comment). */

typedef struct unk388E0Struct40 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} unk388E0Struct40; //sizeof 0xC

typedef struct unk388E0StructC8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void* unk_04;
} unk388E0StructC8; //sizeof 8

typedef struct unk388E0StructC0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ unk388E0StructC8* unk_10;
    /* 0x14 */ u16* unk_14;
} unk388E0StructC0; //sizeof 0x18

typedef struct unk3AC60Struct0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
} unk3AC60Struct0;

typedef struct unk3AC60Struct1 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ char unk_08[8];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ char unk_18[0x18];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
} unk3AC60Struct1;

/* an Mtx written as halfwords */
typedef struct unk3AC60Struct2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ char unk_2C[0xC];
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
} unk3AC60Struct2;

extern HmfTex D_800CAD50_CB950;
extern u32 D_800CAFF0_CBBF0[];
extern u32 D_800CB000_CBC00[];
extern s32 D_800CB010_CBC10[];
extern u32 D_800CB020_CBC20[];
extern u32 D_800CB030_CBC30[];
extern unk388E0Struct40* D_800FD7F8_FE3F8;
extern unk388E0StructC0* D_800FFDFC_1009FC;

void bcopy(const void*, void*, int);
void* HuMemAlloc(s32);
void* func_80027154_27D54(s32, s16);
void func_80027340_27F40(void*);
void func_800273A8_27FA8(s16);
HmfPal* func_8003D55C_3E15C(HmfData*, s16);
void func_8003D6B8_3E2B8(HmfPal*);
void func_8003DEA4_3EAA4(void);
void func_8003E8E4_3F4E4(s16);
void func_8003CFA0_3DBA0(void);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003CAA0_3D6A0);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003CB70_3D770);

/* same c: marioparty func_80037FA0 (src/388E0.c) */
void func_8003CDAC_3D9AC(HmfData* arg0) {
    HmfTex* tex;
    HmfData* m;
    s16 i;
    s16 j;
    s16 k;

    if (arg0->unk88 != NULL) {
        for (i = 0; i < arg0->unk12; i++) {
            tex = arg0->unk88[i].unk0C;
            if (tex->unk24 == 0) {
                continue;
            }
            for (j = 0; j < 128; j++) {
                m = D_800FC834_FD434[j].hmf;
                if (m == NULL) {
                    continue;
                }
                if (((u8) D_800FC834_FD434[j].unk00 != 0) | (arg0 == m)) {
                    continue;
                }
                if (m->unk88 == NULL) {
                    continue;
                }
                for (k = 0; k < m->unk12; k++) {
                    if (m->unk88[k].unk0C == tex) {
                        break;
                    }
                }
                if (k != m->unk12) {
                    break;
                }
            }
            if (j == 128) {
                tex->unk24 = 0;
                tex->unk2C = NULL;
                if (tex->unk1C == 2) {
                    func_8003D6B8_3E2B8((HmfPal*) tex->unk30);
                }
                func_80027340_27F40(tex->unk28);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003CF48_3DB48);

/* exact c: marioparty func_800F7310_PaddleBattle (src/overlays/ovl_33_PaddleBattle/2341E0.c) */
void func_8003CF84_3DB84(void) {
    func_8003CFA0_3DBA0();
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003CFA0_3DBA0);

/* same c: marioparty func_80038254 (src/388E0.c) */
void func_8003D070_3DC70(u8 *arg0, HmfData *arg1, HmfTex *arg2)
{
  u16 bpp;
  u16 size;
  u16 i;
  u16 c;
  u8 *dst;
  arg0 += 0xB;
  arg2->unk1E = arg0[3];
  arg2->unk1F = arg0[5];
  if (arg0[0] == 0x28)
  {
    arg2->unk1C = 2;
    arg2->unk30 = (HmfPal *) func_8003D55C_3E15C(arg1, (arg0[6] << 8) + arg0[7]);
    arg2->unk22 = (arg0[8] << 8) + arg0[9];
    arg2->unk1D = 1;
    bpp = 2;
    if (arg2->unk30->unk1E < 0x11)
    {
      bpp = 1;
    }
    arg0 += 4;
  }
  else
  {
    switch (arg0[1])
    {
      case 8:
        arg2->unk1D = (short) 1;
        bpp = 2;
        break;

      case 16:
        arg2->unk1D = 2;
        bpp = 4;
        break;

      case 4:
        arg2->unk1D = 0;
        bpp = 1;
        break;

      case 32:
        arg2->unk1D = 3;
        bpp = 8;
        break;

      default:
        arg2->unk1D = 2;
        bpp = 6;
        break;

    }

    switch (arg0[0])
    {
      case 0x26:
        arg2->unk1C = 0;
        break;

      case 0x27:
        arg2->unk1C = 0;
        break;

      case 0x25:
        arg2->unk1C = 3;
        break;

      default:
        arg2->unk1C = 4;
        break;

    }

  }
  size = (arg0[8] << 8) + arg0[9];
  if (bpp != 6)
  {
    if (((arg2->unk1C == 2) && (size > 0x800)) || (size > 0x1000))
    {
      arg2->unk1F = 0x10;
      arg2->unk1E = 0x10;
    }
    arg2->unk28 = func_80027154_27D54(size, 15000);
    bcopy(arg0 + 0xA, arg2->unk28, size);
  }
  else
  {
    size = (size / 3) * 2;
    if (size > 0x1000)
    {
      arg2->unk1F = 0x10;
      arg2->unk1E = 0x10;
    }
    dst = (arg2->unk28 = func_80027154_27D54(size, 15000));
    arg0 += 0xA;
    for (i = 0; i < size; i += 2)
    {
      if (arg0)
      {
        c = (((((*arg0) & 0xF8) << 8) + (((*arg0) & 0xF8) << 3)) + (((*arg0) & 0xF8) >> 2)) + 1;
        arg0 += 3;
        *(dst++) = c >> 8;
        *(dst++) = c;
      }
      else
      {
        c = (((((*arg0) & 0xF8) << 8) + (((*arg0) & 0xF8) << 3)) + (((*arg0) & 0xF8) >> 2)) + 1;
        arg0 += 3;
        *(dst++) = c >> 8;
        *(dst++) = c;
      }
    }

  }
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D318_3DF18);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D55C_3E15C);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D628_3E228);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D6B8_3E2B8);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D6DC_3E2DC);

/* same c: marioparty func_8003897C (src/388E0.c) */
void func_8003D7D0_3E3D0(HmfTex* arg0) {
    s16 i;
    s16 j;
    HmfData* m;

    for (i = 0; i < 128; i++) {
        if (D_800FC834_FD434[i].hmf != NULL) {
            m = D_800FC834_FD434[i].hmf;
            for (j = 0; j < m->unk12; j++) {
                if (m->unk88[j].unk0C == arg0) {
                    m->unk88[j].unk0C = &D_800CAD50_CB950;
                }
            }
        }
    }
}

/* exact c: marioparty func_80038A2C (src/388E0.c) */
void func_8003D880_3E480(void) {
    s16 i;

    D_800FD7F8_FE3F8 = HuMemAlloc(128 * sizeof(unk388E0Struct40));

    for (i = 0; i < 128; i++) {
        D_800FD7F8_FE3F8[i].unk_00 = -1;
    }

    func_8003DEA4_3EAA4();
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003D8F0_3E4F0);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003DBE8_3E7E8);

/* exact c: marioparty func_80039020 (src/388E0.c) */
void func_8003DEA4_3EAA4(void) {
    s16 i;

    D_800FFDFC_1009FC = HuMemAlloc(32 * sizeof(unk388E0StructC0));

    for (i = 0; i < 32; i++) {
        D_800FFDFC_1009FC[i].unk_0C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003DF08_3EB08);

/* exact c: marioparty func_80039644 (src/388E0.c) */
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2) {
    unk388E0Struct40* p = &D_800FD7F8_FE3F8[arg0];

    p->unk_0A = (p->unk_0A & ~arg1) | arg2;
}

/* exact c: marioparty func_8003967C (src/388E0.c) */
void func_8003E52C_3F12C(s16 arg0, u8 arg1) {
    unk388E0Struct40* p = &D_800FD7F8_FE3F8[arg0];

    p->unk_04 = arg1;
    p->unk_02 = 0;
    p->unk_06 = 0;
}

/* exact c: marioparty func_800396B0 (src/388E0.c) */
void func_8003E560_3F160(s16 arg0, s32 arg1)
{
  unk388E0Struct40 *new_var2;
  unk388E0StructC8 *new_var;
  unk388E0Struct40 *p = &D_800FD7F8_FE3F8[arg0];
  new_var2 = p;
  new_var2->unk_02 = (u8) arg1;
  new_var = p->unk_04 + D_800FFDFC_1009FC[new_var2->unk_00].unk_10;
  if (new_var->unk_00 <= ((u8) arg1))
  {
    p->unk_02 = ((u8) arg1) % new_var->unk_00;
  }
  p->unk_06 = 0;
  p->unk_0B = 0x10;
}

/* exact c: marioparty func_80039758 (src/388E0.c) */
u8 func_8003E608_3F208(s16 arg0)
{
  unk388E0StructC8 *new_var;
  unk388E0Struct40 *p = &D_800FD7F8_FE3F8[arg0];
  new_var = &D_800FFDFC_1009FC[p->unk_00].unk_10[p->unk_04];
  return (*new_var).unk_00;
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003E65C_3F25C);

/* exact c: marioparty func_80039970 (src/388E0.c) */
void func_8003E808_3F408(s16 arg0, f32 arg1) {
    D_800FD7F8_FE3F8[arg0].unk_0B = arg1 * 16.0f;
}

/* exact c: marioparty func_800399F0 (src/388E0.c) */
void func_8003E888_3F488(s16 arg0) {
    unk388E0Struct40* p = &D_800FD7F8_FE3F8[arg0];

    if (p->unk_00 != -1) {
        func_8003E8E4_3F4E4(p->unk_00);
        p->unk_00 = -1;
    }
}

/* exact c: marioparty func_80039A4C (src/388E0.c) */
void func_8003E8E4_3F4E4(s16 arg0) {
    if (D_800FFDFC_1009FC[arg0].unk_0C != 0) {
        if (--D_800FFDFC_1009FC[arg0].unk_08 == 0) {
            func_800273A8_27FA8(arg0 + 20000);
            D_800FFDFC_1009FC[arg0].unk_0C = 0;
        }
    }
}

/* exact c: marioparty func_80039ACC (src/388E0.c) */
void func_8003E964_3F564(s16 arg0) {
    func_8003E888_3F488(arg0);
}

/* exact c: marioparty func_80039AEC (src/388E0.c) */
void func_8003E984_3F584(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        if (D_800FFDFC_1009FC[i].unk_0C != NULL) {
            D_800FFDFC_1009FC[i].unk_0C = NULL;
            func_800273A8_27FA8(i + 20000);
        }
    }

    for (i = 0; i < 128; i++) {
        D_800FD7F8_FE3F8[i].unk_00 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003EA44_3F644);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003EAF0_3F6F0);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003EBC8_3F7C8);

/* same c: marioparty func_80039F9C (src/388E0.c) */
void func_8003EE44_3FA44(HmfData* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk12; i++) {
        if (arg0->unk88[i].unk03 != -1) {
            arg0->unk88[i].unk09 |= 0x80;
        }
    }
}

/* same c: marioparty func_80039FFC (src/388E0.c) */
void func_8003EEA4_3FAA4(HmfData* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk12; i++) {
        if (arg0->unk88[i].unk03 != -1) {
            arg0->unk88[i].unk09 &= 0x7F;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003EF04_3FB04);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003F240_3FE40);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003F4C0_400C0);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003F520_40120);

INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003F57C_4017C);

s32 func_8003F6F0_402F0(s16 overlayID) {
    s32 explanationOverlayID;

    if (overlayID < 30) {
        explanationOverlayID = 0x5F;
    } else {
        explanationOverlayID = 0x60;
    }
    return explanationOverlayID;
}

/* exact c: marioparty func_8003A060 (src/3AC60.c) */
void func_8003F710_40310(Gfx** arg0, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx* gfx = *arg0;

    gDPSetTextureImage(gfx++, fmt, siz, width, timg);
    gDPSetTile(gfx++, fmt, siz, ((lrs - uls + 1) * D_800CB000_CBC00[siz] + 7) >> 3, 0x0000, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadTile(gfx++, G_TX_LOADTILE, uls * 4, ult * 4, lrs * 4, lrt * 4);
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, siz, ((lrs - uls + 1) * D_800CB000_CBC00[siz] + 7) >> 3, 0x0000, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

/* exact c: marioparty func_8003A28C (src/3AC60.c) */
void func_8003F93C_4053C(Gfx** arg0, s32 timg, s32 fmt, s32 siz, s32 width, s32 arg5, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt, s32 rtile, s32 tmem) {
    Gfx* gfx = *arg0;

    gDPSetTextureImage(gfx++, fmt, siz, width, timg);
    gDPSetTile(gfx++, fmt, siz, ((lrs - uls + 1) * D_800CB000_CBC00[siz] + 7) >> 3, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadTile(gfx++, G_TX_LOADTILE, uls * 4, ult * 4, lrs * 4, lrt * 4);
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, siz, ((lrs - uls + 1) * D_800CB000_CBC00[siz] + 7) >> 3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, rtile, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

/* exact c: marioparty func_8003A4EC (src/3AC60.c) */
void func_8003FB9C_4079C(Gfx** arg0, s32 arg1, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx* gfx = *arg0;
    s32 timg = arg1 + ((width * ult) << (siz - 1));

    gDPSetTextureImage(gfx++, fmt, D_800CB010_CBC10[siz], 1, timg);
    gDPSetTile(gfx++, fmt, D_800CB010_CBC10[siz], 0, 0x0000, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, ((width * height + D_800CB020_CBC20[siz]) >> D_800CB030_CBC30[siz]) - 1, CALC_DXT(width, D_800CAFF0_CBBF0[siz]));
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, siz, (width * D_800CB000_CBC00[siz] + 7) >> 3, 0x0000, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

/* exact c: marioparty func_8003A828 (src/3AC60.c) */
void func_8003FED8_40AD8(Gfx** arg0, s32 arg1, s32 fmt, u32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx* gfx = *arg0;
    s32 timg = arg1 + ((width * ult) >> 1);

    gDPSetTextureImage(gfx++, fmt, G_IM_SIZ_16b, 1, timg);
    gDPSetTile(gfx++, fmt, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, CALC_DXT_4b(width));
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, G_IM_SIZ_4b, ((width >> 1) + 7) >> 3, 0x0000, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

/* exact c: marioparty func_8003AA98 (src/3AC60.c) */
void func_80040148_40D48(Gfx** arg0, s32 arg1, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt, s32 rtile, s32 tmem) {
    Gfx* gfx = *arg0;
    s32 timg = arg1 + ((width * ult) << (siz - 1));

    gDPSetTextureImage(gfx++, fmt, D_800CB010_CBC10[siz], 1, timg);
    gDPSetTile(gfx++, fmt, D_800CB010_CBC10[siz], 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, ((width * height + D_800CB020_CBC20[siz]) >> D_800CB030_CBC30[siz]) - 1, CALC_DXT(width, D_800CAFF0_CBBF0[siz]));
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, siz, (width * D_800CB000_CBC00[siz] + 7) >> 3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, rtile, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

/* exact c: marioparty func_8003AE00 (src/3AC60.c) */
void func_800404B0_410B0(Gfx** arg0, s32 arg1, s32 fmt, u32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt, s32 rtile, s32 tmem) {
    Gfx* gfx = *arg0;
    s32 timg = arg1 + ((width * ult) >> 1);

    gDPSetTextureImage(gfx++, fmt, G_IM_SIZ_16b, 1, timg);
    gDPSetTile(gfx++, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, CALC_DXT_4b(width));
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, G_IM_SIZ_4b, ((width >> 1) + 7) >> 3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, rtile, uls * 4, ult * 4, lrs * 4, lrt * 4);

    *arg0 = gfx;
}

f32 __cosf(f32);
f32 __sinf(f32);

/* exact c: marioparty func_8003B0AC (src/3AC60.c); its three doubles are the tail of the unit's
   rodata (D2F40-D2F58), carved on their own */
void func_8004075C_4135C(unk3AC60Struct1* arg0, f64 arg1, f64 arg2, f64 arg3) {
    f32 temp_f20 = (arg3 - ((s32) (arg3 / 360.0) * 360)) * 3.14158999999999988 / 180.0;

    arg0->unk_00 = __cosf(temp_f20);
    arg0->unk_04 = __sinf(temp_f20);
    arg0->unk_10 = -__sinf(temp_f20);
    arg0->unk_14 = __cosf(temp_f20);
    arg0->unk_30 = arg1;
    arg0->unk_34 = arg2;
}

/* exact c: marioparty func_8003B190 (src/3AC60.c) */
void func_80040840_41440(unk3AC60Struct0* arg0, unk3AC60Struct1* arg1, unk3AC60Struct2* arg2) {
    arg1->unk_30 = arg0->unk_00 * arg1->unk_00 + arg1->unk_30 + arg0->unk_04 * arg1->unk_10;
    arg1->unk_34 = arg0->unk_00 * arg1->unk_04 + arg1->unk_34 + arg0->unk_04 * arg1->unk_14;
    arg2->unk_00 = (s32) (arg1->unk_00 * 65536.0f) >> 16;
    arg2->unk_02 = (s32) (arg1->unk_04 * 65536.0f) >> 16;
    arg2->unk_08 = (s32) (arg1->unk_10 * 65536.0f) >> 16;
    arg2->unk_0A = (s32) (arg1->unk_14 * 65536.0f) >> 16;
    arg2->unk_18 = (s32) (arg1->unk_30 * 65536.0f) >> 16;
    arg2->unk_1A = (s32) (arg1->unk_34 * 65536.0f) >> 16;
    arg2->unk_20 = arg1->unk_00 * 65536;
    arg2->unk_22 = arg1->unk_04 * 65536;
    arg2->unk_28 = arg1->unk_10 * 65536;
    arg2->unk_2A = arg1->unk_14 * 65536;
    arg2->unk_38 = arg1->unk_30 * 65536;
    arg2->unk_3A = arg1->unk_34 * 65536;
}

