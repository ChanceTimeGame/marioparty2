#include "common.h"
#include "game/hmfman.h"

/* Model textures, palettes and texture animation (MP1 src/388E0.c) and texture-load display
   lists (MP1 src/3AC60.c). MP2 adds texture animations defined in the model file ("VX" entries,
   func_8003EF04/func_8003F240) and per-frame palettes. The unit's whole rodata (D2EE0-D2F60) is
   carved. MP2's model structs have MP3's layout; fields are named by their MP2 offset (MP1 offset
   in the comment). */

typedef struct unk388E0Struct40 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} unk388E0Struct40; //sizeof 0xC

typedef struct unk388E0Struct44 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk388E0Struct44; //sizeof 4

/* one step of a sprite animation */
typedef struct unk388E0StructC4 {
    /* 0x00 */ s16 unk_00; /* frame, -1 for none */
    /* 0x02 */ s16 unk_02; /* duration */
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char unk_07;
} unk388E0StructC4; //sizeof 8

typedef struct unk388E0StructC8 {
    /* 0x00 */ s16 unk_00; /* step count */
    /* 0x02 */ s16 unk_02; /* total duration */
    /* 0x04 */ unk388E0StructC4* unk_04;
} unk388E0StructC8; //sizeof 8

/* one sprite frame (MP1 unk388E0StructCC, 0xC bytes there) */
typedef struct unk388E0StructCC {
    /* 0x00 */ s16 unk_00; /* width */
    /* 0x02 */ s16 unk_02; /* height */
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08; /* palette size */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ u16* unk_0C; /* palette */
    /* 0x10 */ void* unk_10; /* image */
} unk388E0StructCC; //sizeof 0x14

typedef struct unk388E0StructC0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ unk388E0StructCC* unk_0C;
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
HmfTex* func_8003CFA0_3DBA0(HmfData*, u8*);
void func_8003D070_3DC70(u8*, HmfData*, HmfTex*);
void func_8003D318_3DF18(HmfData*);
void func_8003D6DC_3E2DC(u8*, HmfData*, HmfPal*);
void func_8003D880_3E480(void);
u8* func_8001EA88_1F688(s32, u8*, u8*);
u8* func_8001EB18_1F718(u8*);
s16 func_8001F380_1FF80(HmfData*, u8*, s16);
s16 func_8001F4AC_200AC(u8*);
s32 func_800B0FD0_B1BD0(void*, void*); /* strcmp */
s16 func_8003DF08_3EB08(void*);
s16 func_8003F4C0_400C0(void);
s16 func_8003F520_40120(void);
s16 func_8003F240_3FE40(HmfData*, u8*);
HmfTex* func_8003CF48_3DB48(HmfData*, s16);

/* HmfData.unkC8 holds a u8* (typed s32 in the shared header; on a 64-bit host it must be retyped) */
#define HMF_TEXANIM(h) (*(u8**) &(h)->unkC8)
void func_800B10E0_B1CE0(void*, void*); /* strcpy */

extern HmfTex* D_800FD89C_FE49C; /* 128 textures */
extern HmfPal* D_800F9568_FA168; /* 128 palettes */
extern u8 D_800F92DD_F9EDD; /* model load flags (1D0B0) */

/* MP1 func_80037CE0 (src/388E0.c) */
void func_8003CAA0_3D6A0(void) {
    s16 i;

    D_800FD89C_FE49C = HuMemAlloc(128 * sizeof(HmfTex));
    D_800F9568_FA168 = HuMemAlloc(128 * sizeof(HmfPal));

    for (i = 0; i < 128; i++) {
        D_800FD89C_FE49C[i].unk24 = 0;
    }

    for (i = 0; i < 128; i++) {
        D_800F9568_FA168[i].unk20 = 0;
    }

    D_800F92DD_F9EDD = 0;
    func_8003D880_3E480();
}

/* MP1 func_80037DA0 (src/388E0.c); MP2 prints and stops when the table is full */
void func_8003CB70_3D770(HmfData* arg0) {
    HmfTex* var_s0;
    s16 temp_s4;
    u8* var_s1;
    u8 sp10[32];
    s16 i;

    func_8003D318_3DF18(arg0);

    for (var_s1 = arg0->unk34; var_s1 < arg0->unk30;) {
        var_s1 = func_8001EA88_1F688(0x424D5031, var_s1, arg0->unk30);
        if (var_s1 == NULL) {
            break;
        }

        temp_s4 = func_8001F380_1FF80(arg0, sp10, (var_s1[8] << 8) + var_s1[9]);
        for (i = 0; i < 128; i++) {
            if (D_800FD89C_FE49C[i].unk24 == temp_s4 && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], sp10) == 0) {
                break;
            }
        }

        if (i == 128) {
            for (i = 0; i < 128; i++) {
                if (D_800FD89C_FE49C[i].unk24 == 0) {
                    break;
                }
            }
            if (i == 128) {
                osSyncPrintf("TEXTURE OVER!\n");
                break;
            }
            var_s0 = &D_800FD89C_FE49C[i];
            var_s0->unk24 = temp_s4;
            func_800B10E0_B1CE0(var_s0, sp10);
            var_s0->unk2C = arg0;
            func_8003D070_3DC70(var_s1, arg0, var_s0);
        } else {
            var_s0 = &D_800FD89C_FE49C[i];
            if (D_800F92DD_F9EDD & 2) {
                func_80027340_27F40(var_s0->unk28);
                var_s0->unk2C = arg0;
                func_8003D070_3DC70(var_s1, arg0, var_s0);
            }
        }

        var_s1 = func_8001EB18_1F718(var_s1 + 4);
    }
}

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

/* MP1 func_8003813C (src/388E0.c) */
HmfTex* func_8003CF48_3DB48(HmfData* arg0, s16 arg1) {
    u8 sp10[32];

    func_8001F380_1FF80(arg0, sp10, arg1);
    return func_8003CFA0_3DBA0(arg0, sp10);
}

/* exact c: marioparty func_800F7310_PaddleBattle (src/overlays/ovl_33_PaddleBattle/2341E0.c) */
/* 274D0 uses the result */
HmfTex* func_8003CF84_3DB84(HmfData* arg0, u8* arg1) {
    return func_8003CFA0_3DBA0(arg0, arg1);
}

/* MP1 func_80038194 (src/388E0.c) */
HmfTex* func_8003CFA0_3DBA0(HmfData* arg0, u8* arg1) {
    u16 temp_s2;
    u16 i;

    temp_s2 = func_8001F4AC_200AC(arg1);

    for (i = 0; i < 128; i++) {
        if (D_800FD89C_FE49C[i].unk24 != 0 && D_800FD89C_FE49C[i].unk24 == temp_s2
            && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], arg1) == 0) {
            break;
        }
    }

    if (i == 128) {
        return NULL;
    }

    return &D_800FD89C_FE49C[i];
}

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

/* MP1 func_800384FC (src/388E0.c) */
void func_8003D318_3DF18(HmfData* arg0) {
    HmfPal* var_s0;
    s16 temp_s4;
    u8* var_s1;
    u8 sp10[32];
    s16 i;

    for (var_s1 = arg0->unk34; var_s1 < arg0->unk30;) {
        var_s1 = func_8001EA88_1F688(0x50414C31, var_s1, arg0->unk30);
        if (var_s1 == NULL) {
            break;
        }

        temp_s4 = func_8001F380_1FF80(arg0, sp10, (var_s1[8] << 8) + var_s1[9]);
        for (i = 0; i < 128; i++) {
            if (D_800F9568_FA168[i].unk20 == temp_s4 && func_800B0FD0_B1BD0(&D_800F9568_FA168[i], sp10) == 0) {
                break;
            }
        }

        if (i == 128) {
            for (i = 0; i < 128; i++) {
                if (D_800F9568_FA168[i].unk20 == 0) {
                    break;
                }
            }
            if (i == 128) {
                break;
            }
            var_s0 = &D_800F9568_FA168[i];
            var_s0->unk20 = temp_s4;
            func_800B10E0_B1CE0(var_s0, sp10);
            var_s0->unk24 = arg0;
            var_s0->unk1C = 1;
            func_8003D6DC_3E2DC(var_s1, arg0, var_s0);
        } else {
            var_s0 = &D_800F9568_FA168[i];
            if (D_800F92DD_F9EDD & 2) {
                func_80027340_27F40(var_s0->unk28);
                var_s0->unk24 = arg0;
                func_8003D6DC_3E2DC(var_s1, arg0, var_s0);
            }
            var_s0->unk1C++;
        }

        var_s1 = func_8001EB18_1F718(var_s1 + 4);
    }
}

/* MP1 func_80038720 (src/388E0.c) */
HmfPal* func_8003D55C_3E15C(HmfData* arg0, s16 arg1) {
    u8 sp10[32];
    u16 id;
    u16 i;

    id = func_8001F380_1FF80(arg0, sp10, arg1);

    for (i = 0; i < 128; i++) {
        if ((u16) D_800F9568_FA168[i].unk20 != 0 && (u16) D_800F9568_FA168[i].unk20 == id
            && func_800B0FD0_B1BD0(&D_800F9568_FA168[i], sp10) == 0) {
            break;
        }
    }

    if (i == 128) {
        return NULL;
    }

    return &D_800F9568_FA168[i];
}

/* MP1 func_800387DC (src/388E0.c) */
void func_8003D628_3E228(HmfData* arg0) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F9568_FA168[i].unk20 != 0 && D_800F9568_FA168[i].unk24 == arg0) {
            func_8003D6B8_3E2B8(&D_800F9568_FA168[i]);
        }
    }
}

/* MP1 func_80038864 (src/388E0.c) */
void func_8003D6B8_3E2B8(HmfPal* arg0) {
    arg0->unk20 = 0;
    arg0->unk24 = NULL;
    func_80027340_27F40(arg0->unk28);
}

/* MP1 func_80038888 (src/388E0.c, NON_MATCHING there) */
void func_8003D6DC_3E2DC(u8* arg0, HmfData* arg1, HmfPal* arg2) {
    u16* tbl;
    s16 count;
    s16 i;
    s32 c;

    arg0 += 0xA;
    count = (arg0[0] << 8) + arg0[1];
    arg2->unk28 = func_80027154_27D54(count * 2, 15000);
    arg2->unk1E = count;
    arg0 += 2;
    tbl = arg2->unk28;
    for (i = 0; i < count; i++) {
        tbl[i] = (c = ((arg0[i * 4 + 0] & 0xF8) << 8) + ((arg0[i * 4 + 1] & 0xF8) << 3) + ((arg0[i * 4 + 2] & 0xF8) >> 2),
                  (arg0[i * 4 + 3] >= 0x80) ? c + 1 : c);
    }
}

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

/* MP1 func_80038A9C (src/388E0.c): start a texture animation (sprite bank arg1) on the texture
   named arg3 in model arg0, or in every model when arg0 is -1 */
s16 func_8003D8F0_3E4F0(HmfData* arg0, void* arg1, s16 arg2, char* arg3) {
    HmfTex* tex;
    s16 id;
    s16 i;
    s16 slot;
    s16 j;

    id = func_8001F4AC_200AC((u8*) arg3);
    for (i = 0; i < 128; i++) {
        if (D_800FD89C_FE49C[i].unk24 == id && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], arg3) == 0) {
            break;
        }
    }
    if (i == 128) {
        osSyncPrintf("Can't Find TextureName! EntryAnimMAn\n");
        return -1;
    }

    for (slot = 0; slot < 128; slot++) {
        if (D_800FD7F8_FE3F8[slot].unk_00 == -1) {
            break;
        }
    }
    if (slot == 128) {
        return -1;
    }

    D_800FD7F8_FE3F8[slot].unk_00 = func_8003DF08_3EB08(arg1);
    D_800FD7F8_FE3F8[slot].unk_04 = arg2;
    D_800FD7F8_FE3F8[slot].unk_02 = 0;
    D_800FD7F8_FE3F8[slot].unk_06 = 0;
    D_800FD7F8_FE3F8[slot].unk_0B = 0x10;
    D_800FD7F8_FE3F8[slot].unk_0A = 0;
    D_800FFDFC_1009FC[D_800FD7F8_FE3F8[slot].unk_00].unk_08 = 1;
    tex = &D_800FD89C_FE49C[i];
    if (arg0 != (HmfData*) -1) {
        for (i = 0; i < arg0->unk12; i++) {
            if (arg0->unk88[i].unk0C == tex) {
                arg0->unk88[i].unk09 = slot;
            }
        }
    } else {
        for (j = 0; j < 128; j++) {
            if (D_800FC834_FD434[j].hmf != NULL && (u8) D_800FC834_FD434[j].unk00 == 0) {
                arg0 = D_800FC834_FD434[j].hmf;
                for (i = 0; i < arg0->unk12; i++) {
                    if (arg0->unk88[i].unk0C == tex) {
                        arg0->unk88[i].unk09 = slot;
                    }
                }
            }
        }
    }
    return slot;
}

/* MP1 func_80038D5C (src/388E0.c): link the texture named arg3 to the sprite bank of
   animation arg1 */
s16 func_8003DBE8_3E7E8(HmfData* arg0, u16 arg1, s16 arg2, char* arg3) {
    HmfTex* tex;
    unk388E0Struct40* p;
    s16 id;
    s16 i;
    s16 slot;
    s16 j;

    id = func_8001F4AC_200AC((u8*) arg3);
    for (i = 0; i < 128; i++) {
        if (D_800FD89C_FE49C[i].unk24 == id && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], arg3) == 0) {
            break;
        }
    }
    if (i == 128) {
        osSyncPrintf("Can't Find TextureName! LinkAnimMAn\n");
        return -1;
    }

    slot = func_8003F4C0_400C0();
    if (slot == -1) {
        return -1;
    }

    p = &D_800FD7F8_FE3F8[slot];
    p->unk_00 = D_800FD7F8_FE3F8[arg1].unk_00;
    p->unk_04 = arg2;
    p->unk_0A = 0;
    p->unk_06 = 0;
    p->unk_02 = 0;
    p->unk_0B = 0x10;
    D_800FFDFC_1009FC[p->unk_00].unk_08++;
    tex = &D_800FD89C_FE49C[i];
    if (arg0 != (HmfData*) -1) {
        for (i = 0; i < arg0->unk12; i++) {
            if (arg0->unk88[i].unk0C == tex) {
                arg0->unk88[i].unk09 = slot;
            }
        }
    } else {
        for (j = 0; j < 128; j++) {
            if (D_800FC834_FD434[j].hmf != NULL && (u8) D_800FC834_FD434[j].unk00 == 0) {
                arg0 = D_800FC834_FD434[j].hmf;
                for (i = 0; i < arg0->unk12; i++) {
                    if (arg0->unk88[i].unk0C == tex) {
                        arg0->unk88[i].unk09 = slot;
                    }
                }
            }
        }
    }
    return slot;
}

/* exact c: marioparty func_80039020 (src/388E0.c) */
void func_8003DEA4_3EAA4(void) {
    s16 i;

    D_800FFDFC_1009FC = HuMemAlloc(32 * sizeof(unk388E0StructC0));

    for (i = 0; i < 32; i++) {
        D_800FFDFC_1009FC[i].unk_0C = 0;
    }
}

// register allocation: retail keeps nframes on the stack and data in s4 (masked 20)
#ifdef NON_MATCHING
/* MP1 func_80039084 (src/388E0.c, NON_MATCHING there): load a sprite bank file into a free slot;
   MP2 frames carry their own palette */
s16 func_8003DF08_3EB08(void* arg) {
    u8* arg0 = arg;
    u8* data;
    s16 nframes;
    unk388E0StructC0* spr;
    s16 w;
    s16 h;
    unk388E0StructCC* fr;
    unk388E0StructC4* af;
    u8* p;
    u8* q;
    s16 bpp;
    s32 npal;
    s16 slot;
    s16 i;
    s16 j;
    s16 n;
    s16 t;
    s16 total;
    s16 d;

    for (slot = 0; slot < 32; slot++) {
        if (D_800FFDFC_1009FC[slot].unk_0C == NULL) {
            break;
        }
    }
    if (slot == 32) {
        return -1;
    }

    spr = &D_800FFDFC_1009FC[slot];
    spr->unk_06 = (arg0[0x18] << 8) + arg0[0x19];
    bpp = spr->unk_06 & 0xFF;
    npal = arg0[0x1A];
    spr->unk_04 = npal;
    p = arg0 + (arg0[0xD] << 16) + (arg0[0xE] << 8) + arg0[0xF];
    if (bpp < 9) {
        if (npal >= 2 && !(spr->unk_06 & 0x8000)) {
            spr->unk_14 = func_80027154_27D54(npal * 2, slot + 20000);
            bcopy(p, spr->unk_14, npal * 2);
        } else {
            spr->unk_04 = 0;
            spr->unk_14 = NULL;
        }
    } else {
        spr->unk_04 = 0;
        spr->unk_14 = NULL;
    }

    nframes = arg0[0x10];
    nframes = (nframes << 8) + arg0[0x11];
    spr->unk_00 = nframes;
    spr->unk_0C = func_80027154_27D54(nframes * sizeof(*spr->unk_0C), slot + 20000);
    p = arg0 + (arg0[1] << 16) + (arg0[2] << 8) + arg0[3];
    for (i = 0; i < nframes; i++) {
        fr = &spr->unk_0C[i];
        data = arg0 + (p[1] << 16) + (p[2] << 8) + p[3];
        w = fr->unk_00 = (p[4] << 8) + p[5];
        h = fr->unk_02 = (p[6] << 8) + p[7];
        fr->unk_04 = (p[8] << 8) + p[9];
        fr->unk_06 = (p[10] << 8) + p[11];
        fr->unk_10 = func_80027154_27D54(w * h * bpp / 8, slot + 20000);
        bcopy(data, fr->unk_10, w * h * bpp / 8);
        fr->unk_0C = spr->unk_14;
        fr->unk_08 = spr->unk_04;
        p += 12;
    }

    spr->unk_02 = n = (arg0[0x12] << 8) + arg0[0x13];
    if (n != 0) {
        spr->unk_10 = func_80027154_27D54(n * sizeof(*spr->unk_10), slot + 20000);
        p = arg0 + (arg0[5] << 16) + (arg0[6] << 8) + arg0[7];
        for (i = 0; i < n; i++) {
            q = arg0 + (p[i * 4 + 1] << 16) + (p[i * 4 + 2] << 8) + p[i * 4 + 3];
            spr->unk_10[i].unk_00 = t = (q[0] << 8) + q[1];
            spr->unk_10[i].unk_04 = func_80027154_27D54(t * sizeof(*spr->unk_10->unk_04), slot + 20000);
            q += 2;
            total = 0;
            for (j = 0; j < t; j++) {
                af = &spr->unk_10[i].unk_04[j];
                af->unk_00 = (q[0] << 8) + q[1];
                af->unk_02 = d = (q[2] << 8) + q[3];
                if (d > 0) {
                    total += d;
                }
                af->unk_04 = q[4];
                af->unk_05 = q[5];
                af->unk_06 = q[6];
                q += 7;
            }
            spr->unk_10[i].unk_02 = total;
        }
    } else {
        spr->unk_02 = 1;
        spr->unk_10 = func_80027154_27D54(sizeof(*spr->unk_10), slot + 20000);
        spr->unk_10->unk_00 = nframes;
        spr->unk_10->unk_04 = func_80027154_27D54(nframes * sizeof(*spr->unk_10->unk_04), slot + 20000);
        for (j = 0; j < nframes; j++) {
            af = &spr->unk_10->unk_04[j];
            af->unk_00 = j;
            af->unk_02 = 1;
            af->unk_05 = 0;
            af->unk_04 = 0;
            af->unk_06 = 0;
        }
        spr->unk_10->unk_02 = nframes;
    }
    return slot;
}
#else
INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003DF08_3EB08);
#endif

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

/* MP1 func_800397AC (src/388E0.c): advance every texture animation by arg0 ticks; MP2 adds
   the pause flag 4 and restarts a looping animation at its first tick */
void func_8003E65C_3F25C(u16 arg0) {
    unk388E0Struct40* p;
    unk388E0StructC8* bank;
    s16 i;
    s16 k;

    for (i = 0; i < 128; i++) {
        if (D_800FD7F8_FE3F8[i].unk_00 == -1) {
            continue;
        }
        if (D_800FD7F8_FE3F8[i].unk_0A & 4) {
            continue;
        }
        p = &D_800FD7F8_FE3F8[i];
        if (p->unk_0A & 1) {
            continue;
        }
        bank = &D_800FFDFC_1009FC[p->unk_00].unk_10[p->unk_04];
        for (k = 0; k < arg0; k++) {
            p->unk_06 += p->unk_0B;
            while (p->unk_06 >= bank->unk_04[p->unk_02].unk_02 * 16) {
                p->unk_06 -= bank->unk_04[p->unk_02].unk_02 * 16;
                p->unk_02++;
                if (bank->unk_00 <= p->unk_02) {
                    if ((p->unk_0A & 2) || bank->unk_04[p->unk_02 - 1].unk_02 != -1) {
                        p->unk_02--;
                    } else {
                        p->unk_02 = 0;
                        p->unk_06 = 0;
                    }
                }
            }
        }
    }
}

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

/* MP1 func_80039BAC (src/388E0.c) */
void func_8003EA44_3F644(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        D_800FD89C_FE49C[i].unk24 = 0;
    }

    for (i = 0; i < 128; i++) {
        D_800F9568_FA168[i].unk20 = 0;
    }

    func_800273A8_27FA8(15000);
}

/* MP1 func_80039C48 (src/388E0.c): the size of the texture named arg0 */
void func_8003EAF0_3F6F0(char* arg0, void* arg1) {
    unk388E0Struct44* out = arg1;
    u16 id;
    u16 i;

    id = func_8001F4AC_200AC((u8*) arg0);

    for (i = 0; i < 128; i++) {
        if (D_800FD89C_FE49C[i].unk24 == id && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], arg0) == 0) {
            break;
        }
    }

    if (i == 128) {
        return;
    }
    out->unk_00 = D_800FD89C_FE49C[i].unk1E;
    out->unk_02 = D_800FD89C_FE49C[i].unk1F;
}

extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */

// register allocation and scheduling of the animation-slot lookup (masked 19), as in MP1
#ifdef NON_MATCHING
/* MP1 func_80039D10 (src/388E0.c, NON_MATCHING there): point each texture's segments at its
   image and palette, or at the current frame of its texture animation */
void func_8003EBC8_3F7C8(HmfData* arg0) {
    unk388E0Struct40* p;
    unk388E0StructC0* spr;
    HmfTex* tex;
    s16 frame;
    s16 i;
    s32 idx;

    for (i = 0; i < arg0->unk12; i++) {
        if (arg0->unk88[i].unk03 == -1) {
            continue;
        }
        idx = arg0->unk88[i].unk09;
        if (!(idx & 0x80)) {
            p = &D_800FD7F8_FE3F8[idx];
            if (p->unk_00 != -1) {
                spr = &D_800FFDFC_1009FC[p->unk_00];
                frame = spr->unk_10[p->unk_04].unk_04[p->unk_02].unk_00;
                if (frame != -1) {
                    gSPSegment(D_800FDBCC_FE7CC++, arg0->unk88[i].unk03,
                               osVirtualToPhysical(spr->unk_0C[frame].unk_10));
                    if (D_800FFDFC_1009FC[p->unk_00].unk_14 != NULL) {
                        gSPSegment(D_800FDBCC_FE7CC++, arg0->unk88[i].unk04,
                                   osVirtualToPhysical(spr->unk_0C[frame].unk_0C));
                    }
                    continue;
                }
            }
        }
        tex = arg0->unk88[i].unk0C;
        gSPSegment(D_800FDBCC_FE7CC++, arg0->unk88[i].unk03, osVirtualToPhysical(tex->unk28));
        if (tex->unk30 != NULL) {
            gSPSegment(D_800FDBCC_FE7CC++, arg0->unk88[i].unk04, osVirtualToPhysical(tex->unk30->unk28));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/3D6A0", func_8003EBC8_3F7C8);
#endif

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

/* start the texture animations a model file defines ("VX" entries of its MTN1 chunks); their
   slots are kept in the model (unkC8, unk28). Returns 0 when it has none */
s32 func_8003EF04_3FB04(HmfData* arg0) {
    u8 sp10[32];
    HmfTexRef* ref;
    HmfTex* tex;
    u8* chunk;
    u8* p;
    u8* e;
    s16 n;
    s16 k;
    s16 cnt;
    s16 slot;
    s16 id;
    s16 i;

    n = 0;
    chunk = arg0->unk34;
    while (TRUE) {
        chunk = func_8001EA88_1F688(0x4D544E31, chunk, arg0->unk30);
        if (chunk == NULL) {
            break;
        }
        p = chunk + 0xD;
        cnt = chunk[0xA];
        for (k = 0; k < cnt; k++) {
            e = p;
            p += (p[0] << 8) + p[1] + 2;
            if (e[2] != 'V' || e[3] != 'X') {
                continue;
            }
            e += 4;
            slot = func_8003F4C0_400C0();
            if (slot == -1) {
                break;
            }
            sp10[n] = slot;
            D_800FD7F8_FE3F8[slot].unk_00 = func_8003F240_3FE40(arg0, e);
            D_800FD7F8_FE3F8[slot].unk_04 = 0;
            D_800FD7F8_FE3F8[slot].unk_02 = 0;
            D_800FD7F8_FE3F8[slot].unk_06 = 0;
            D_800FD7F8_FE3F8[slot].unk_0B = 0x10;
            D_800FD7F8_FE3F8[slot].unk_0A = 4;
            D_800FFDFC_1009FC[D_800FD7F8_FE3F8[slot].unk_00].unk_08 = 1;
            ref = &arg0->unk88[(e[2] << 8) + e[3]];
            id = ref->unk0C->unk24;
            for (i = 0; i < 128; i++) {
                if (D_800FD89C_FE49C[i].unk24 == id && func_800B0FD0_B1BD0(&D_800FD89C_FE49C[i], ref->unk0C) == 0) {
                    break;
                }
            }
            tex = &D_800FD89C_FE49C[i];
            for (i = 0; i < arg0->unk12; i++) {
                if (arg0->unk88[i].unk0C == tex) {
                    arg0->unk88[i].unk09 = slot;
                }
            }
            n++;
        }
        chunk = func_8001EB18_1F718(chunk + 4);
    }
    if (n == 0) {
        HMF_TEXANIM(arg0) = NULL;
        return 0;
    }
    HMF_TEXANIM(arg0) = func_80027154_27D54(n, arg0->unk0E + 1);
    for (i = 0; i < n; i++) {
        HMF_TEXANIM(arg0)[i] = sp10[i];
    }
    arg0->unk28 = n;
    return 1;
}

/* build a sprite bank whose frames are the model's own textures (a "VX" entry at arg1:
   frame count, then texture index and duration per frame); the last step loops */
s16 func_8003F240_3FE40(HmfData* arg0, u8* arg1) {
    unk388E0StructC0* spr;
    unk388E0StructCC* fr;
    unk388E0StructC4* af;
    HmfTex* tex;
    u8* p;
    s16 slot;
    s16 n;
    s16 id;
    s16 i;
    s16 total;

    af = NULL;
    slot = func_8003F520_40120();
    if (slot == -1) {
        return -1;
    }
    spr = &D_800FFDFC_1009FC[slot];
    n = (arg1[4] << 8) + arg1[5];
    spr->unk_00 = n;
    spr->unk_0C = func_80027154_27D54(n * sizeof(*spr->unk_0C), id = slot + 20000);
    p = arg1 + 6;
    spr->unk_06 = (arg1[0x18] << 8) + arg1[0x19];
    spr->unk_02 = 1;
    spr->unk_10 = func_80027154_27D54(sizeof(*spr->unk_10), id);
    spr->unk_10->unk_00 = n + 1;
    spr->unk_10->unk_04 = func_80027154_27D54((n + 1) * sizeof(*spr->unk_10->unk_04), id);
    total = 0;
    for (i = 0; i < n; i++) {
        fr = &spr->unk_0C[i];
        af = &spr->unk_10->unk_04[i];
        tex = func_8003CF48_3DB48(arg0, (p[0] << 8) + p[1]);
        fr->unk_00 = tex->unk1E;
        fr->unk_02 = tex->unk1F;
        fr->unk_06 = 0;
        fr->unk_04 = 0;
        fr->unk_10 = tex->unk28;
        af->unk_00 = i;
        af->unk_02 = (p[2] << 8) + p[3];
        if (af->unk_02 == 0) {
            af->unk_02 = 1;
        }
        if (af->unk_02 > 0) {
            total += af->unk_02;
        }
        af->unk_06 = 0;
        af->unk_05 = 0;
        af->unk_04 = 0;
        if (tex->unk1C == 2) {
            fr->unk_08 = tex->unk30->unk1E;
            fr->unk_0C = tex->unk30->unk28;
        }
        p += 4;
    }
    af++; /* retail writes through NULL + 8 when n is 0 */
    af->unk_00 = 0;
    af->unk_02 = -1;
    spr->unk_10->unk_02 = total;
    spr->unk_04 = spr->unk_0C->unk_08;
    spr->unk_14 = spr->unk_0C->unk_0C;
    return slot;
}

/* a free texture animation slot, or -1 */
s16 func_8003F4C0_400C0(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800FD7F8_FE3F8[i].unk_00 == -1) {
            return i;
        }
    }
    return -1;
}

/* a free sprite bank slot, or -1 */
s16 func_8003F520_40120(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        if (D_800FFDFC_1009FC[i].unk_0C == NULL) {
            return i;
        }
    }
    return -1;
}

/* restart texture animation arg0 and advance it by arg1 ticks (16 per frame unit at speed 1) */
void func_8003F57C_4017C(s16 arg0, s16 arg1) {
    unk388E0Struct40* p;
    unk388E0StructC8* bank;
    s16 k;

    if (D_800FD7F8_FE3F8[arg0].unk_00 == -1) {
        return;
    }
    p = &D_800FD7F8_FE3F8[arg0];
    bank = &D_800FFDFC_1009FC[p->unk_00].unk_10[p->unk_04];
    p->unk_02 = 0;
    p->unk_06 = 0;
    for (k = 0; k < arg1; k++) {
        p->unk_06++;
        while (p->unk_06 >= bank->unk_04[p->unk_02].unk_02) {
            p->unk_06 -= bank->unk_04[p->unk_02].unk_02;
            p->unk_02++;
            if (bank->unk_00 <= p->unk_02) {
                if ((p->unk_0A & 2) || bank->unk_04[p->unk_02 - 1].unk_02 != -1) {
                    p->unk_02--;
                } else {
                    p->unk_02 = 0;
                    p->unk_06 = 0;
                }
            }
        }
    }
}

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

