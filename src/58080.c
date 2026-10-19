#include "common.h"
#include "game/data.h"

// MP3s UnkBoard8
typedef struct {
    struct BoardPlayer* unk_00; //?
    struct BoardPlayer* unk_04; //?
    s16 unk_08;
    s16 unk_0A;
    s16* unk_0C;
    f32* unk_10;
    f32* unk_14;
    s16* unk_18;
    s16* unk_1C;
} BoardPlayer;

GW_PLAYER* BoardPlayerGet(s32);
s16 SprAnimRead(void*);
s32 SprAnimSet(s16, s16, s16, s32);
s32 SprPosSet(s16, s16, s16, s16);
s32 SprPrioSet(s16, s16, s32);
s32 SprScaleSet(s16, s32, f32, f32);
void SprAttrReset(s16, s16, u16);
void SprAttrSet(s16, s16, u32);
s32 _CheckFlag(s32);
s32 func_8005C8A0_5D4A0(s32);
s32 func_8005C8AC_5D4AC(void*, s16);
void* func_8005C980_5D580(void);
BoardPlayer *func_8005E688_5F288(s32, s32);
s32 PlaySound(s32);
s32 func_80082450_83050(s16, s16, s32, s32, s32);
s32 func_800824B4_830B4(s16, s32, s32, s32, s32, s32);
void MBModelKill(void*);

extern s32 D_800CC754_CD354[6];
extern s32 D_800CC76C_CD36C[6];
extern s32 D_800CC784_CD384[8];
extern s8 D_800CC7A4_CD3A4[8];
extern s8 D_800CC7AC_CD3AC[8];
extern s16 D_800CC7B4_CD3B4[8];
extern s16 D_800CC7BC_CD3BC[8];
extern u16 D_800CC7C4_CD3C4[22][1];
extern s16 *D_800E1CF0_E28F0;
extern u16 ContDStkTrg[]; // unknown size
extern u16 D_8010163C_10223C[]; // unknown size
extern GW_PLAYER gPlayers[];

/* Board players, sprites, effects and pause menu helpers. C from MP1 src/4E530.c, src/51200.c,
   src/53680.c and MP3 ovl_80_shared_board 101840.c / 105D50.c; the rest have no reference or differ
   (near) and stay asm, and func_80059198, func_80059E7C and func_8005ADCC stay asm because their
   rodata (D3A38-D3AE0) is shared with asm functions. */

#define CUR_PLAYER -1

typedef struct unk_Struct04 {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ void* func_ptr;
    /* 0x18 */ Vec pos;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Vec scale;
    /* 0x3C */ u16 mdlcnt;
    /* 0x40 */ s16* unk_40;
} unk_Struct04; /* size = 0x44 */

typedef struct Object {
    /* 0x00 */ struct Object* prev;
    /* 0x04 */ struct Object* next;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ Vec coords;
    /* 0x18 */ Vec unk_18;
    /* 0x24 */ f32 xScale;
    /* 0x28 */ f32 yScale;
    /* 0x2C */ f32 zScale;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ unk_Struct04* unk_3C;
    /* 0x40 */ unk_Struct04* unk_40;
} Object; /* MP1's, first 0x44 bytes */

typedef struct unk1EA70Struct1C unk1EA70Struct1C;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ Object* unk4;
    /* 0x08 */ omObjData* unk8;
} Unk4E530Motion;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
} Unk4E530Sprite;

typedef struct {
    /* 0x00 */ omObjData* unk0;
    /* 0x04 */ unk1EA70Struct1C* unk4;
} Unk4E530Effect;

typedef struct {
    /* 0x00 */ void* unk0;
    /* 0x04 */ s16 unk4;
} Unk4E530Data;

typedef struct unkMallocStruct {
    /* 0x00 */ s32* unk0;
    /* 0x04 */ s16 unk4;
} unkMallocStruct;

typedef struct Unk800F8C60 {
    /* 0x00 */ char pad0[0x76];
    /* 0x76 */ s8 unk_76;
} Unk800F8C60;

typedef struct Unk800FC834 {
    /* 0x00 */ char pad0[0x64];
    /* 0x64 */ void* unk_64;
    /* 0x68 */ char pad68[0x58];
} Unk800FC834; // size 0xC0 (MP1 unk_ovl_2D_struct)

extern s32 D_800CC5F4_CD1F4;
extern omObjData* D_800CC628_CD228;
extern s32 D_800CC62C_CD22C;
extern s32 D_800CC630_CD230;
extern s32 D_800CC640_CD240[];
extern s32 D_800CC65C_CD25C[];
extern s16 D_800CC668_CD268[];
extern s16 D_800CC66C_CD26C[];
extern u8 D_800CC7F0_CD3F0[];
extern u8 D_800CC7F4_CD3F4[];
extern s32 D_800CC8B8_CD4B8[];
extern Unk4E530Sprite D_800E1BA0_E27A0[16];
extern Unk4E530Effect D_800E1BE0_E27E0[16];
extern Unk4E530Data D_800E1C60_E2860[16];
extern s8 D_800E1CE0_E28E0;
extern f32 D_800E1CE4_E28E4;
extern f32 D_800E1CE8_E28E8;
extern s16 D_800E1CF6_E28F6;
extern void* D_800E1CFC_E28FC;
extern Unk800F8C60 D_800F8C60;
extern Unk800FC834* D_800FC834_FD434;
extern s8 D_800FDC9C_FE89C;
extern Unk4E530Motion D_800FDCD8_FE8D8[16];
extern omObjData* D_80101178_101D78[32];
extern GW_SYSTEM GwSystem;

void* HuMemMemoryAlloc(HeapNode* heap, s32 size);
u16 LoadFormFile(s32, s32);
u16 MBMotionCheck(void*);
void MBMotionSet(void* arg0, s16 arg1, u16 arg2);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBKSuitMotionSet(s16 arg0, s32 arg1);
void MBKSuitMotionShiftSet(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void MBPlayerModelCreate(s16, void*, s32);
s32 MBPauseMesNumGet(s32);
u16 MBDCameraPos3DSet(Vec*);
s32 HuGetPadInserted(s16);
s32 HuMemDirectFree(BoardPlayer*);
s32 PlayerIsCPU(s16);
s32 MBPauseDlgMesSet(s16, s32);
s32 func_8005C6DC_5D2DC(GW_PLAYER*, s16);
void func_8005DEB0_5EAB0(s32, u8);
void omDelObj(omObjData*);
void SprKill(s16);
void SprAnimKill(s16);
s16 SprCreate(s32, s32);
void func_80020D20_21920(s16);
unk1EA70Struct1C* func_800240C8_24CC8(s32, s16);
void func_80024234_24E34(unk1EA70Struct1C*);
void func_800242BC_24EBC(unk1EA70Struct1C*);
s16 func_800244F4_250F4(unk1EA70Struct1C*, s16, f32, f32, f32, s16);
void func_800247EC_253EC(unk1EA70Struct1C*, f32, f32, f32);
void func_800283DC_28FDC(s16);
void func_80029A8C_2A68C(s16);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_8002A00C_2AC0C(s16);
s16 func_8003D8F0_3E4F0(void*, void*, s32, char*);
void func_8003E964_3F564(s16);
void func_80057724_58324(s32);
void func_80057768_58368(s32, s32, s32);
void func_80057AB0_586B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80057DDC_589DC(omObjData*, s32);
void func_80058294_58E94(omObjData* arg0);
void func_800585E8_591E8(omObjData* arg0);
void func_80058D18_59918(omObjData* arg0);
void func_80059198_59D98(omObjData*);
s32 func_80059E7C_5AA7C(Vec*, Vec*, f32);
void func_8005ADCC_5B9CC(BoardPlayer*, s32, s32, s32, s32);
void func_8005B56C_5C16C(void);
s16 func_8005D7D4_5E3D4(s16, s32);
s32 func_80061504_62104(void);
void func_80061518_62118(void);
void func_80061584_62184(void);
void func_80062CD8_638D8(s32);
void func_800794F0_7A0F0(s8);
void func_8008221C_82E1C(s16, s16, f32);
void func_8008225C_82E5C(s16, s16, u16);
void func_80082488_83088(s16, s16, u16);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089764_8A364(s16, f32, f32);
void func_800898F0_8A4F0(s16, s32, s32);
void func_800899F4_8A5F4(s16, f32);
void func_8008AD44_8B944(s16);
s16 func_8008BA30_8C630(s16);
void func_8008D07C_8DC7C(s16, s16, s16, s16);
void func_8008D23C_8DE3C(void);
void func_8008D808_8E408(s16, s32);
void func_8008DACC_8E6CC(s32, s16*, s32);

INCLUDE_ASM("asm/nonmatchings/58080", func_80057480_58080);

void ShowTextWindow(s32 arg0) {
    s32 i;

    PlaySound(0x31C);
    func_8008D808_8E408(arg0, 1);
    func_800898F0_8A4F0(arg0, 0, 0);
    func_800899F4_8A5F4(arg0, 180.0f);
    func_80089764_8A364(arg0, 0.0f, 0.0f);
    
    for (i = 0; i < 0xB5; i += 0x14) {
        HuPrcVSleep();
        func_800899F4_8A5F4(arg0, 180.0f - i);
        func_80089764_8A364(arg0, i / 180.0f, i / 180.0f);        
    }
    
    func_8008D808_8E408(arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005762C_5822C);

void func_800576F8_582F8(s32 arg0) {
    D_800CC5F4_CD1F4 = arg0;
    func_80057724_58324(arg0);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80057718_58318);

INCLUDE_ASM("asm/nonmatchings/58080", func_80057724_58324);

void func_80057730_58330(s32 arg0, s32 arg1) {
    func_80057768_58368(arg0, arg1, 0);
}

void func_8005774C_5834C(s32 arg0, s32 arg1) {
    func_80057768_58368(arg0, arg1, 1);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80057768_58368);

void func_80057A78_58678(s32 arg0, s32 arg1, s32 arg2) {
    func_80057AB0_586B0(arg0, arg1, arg2, 0);
}

void func_80057A94_58694(s32 arg0, s32 arg1, s32 arg2) {
    func_80057AB0_586B0(arg0, arg1, arg2, 1);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80057AB0_586B0);

void func_80057DA4_589A4(omObjData* obj) {
    func_80057DDC_589DC(obj, 0);
}

void func_80057DC0_589C0(omObjData* obj) {
    func_80057DDC_589DC(obj, 1);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80057DDC_589DC);

void func_8005812C_58D2C(s32 arg0) {
    func_8008D59C_8E19C(arg0, 0xF);
    func_8008D07C_8DC7C(-1, -1, -1, -1);
    while ((func_8008BA30_8C630(arg0)) != 0) {
        HuPrcVSleep();
    }
    func_8008D23C_8DE3C();
}

void func_800581A0_58DA0(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80101178_101D78); i++) {
        D_80101178_101D78[i] = 0;
    }

}

void func_800581D0_58DD0(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (D_80101178_101D78[i] == NULL) {
            continue;
        }
        if (D_80101178_101D78[i]->func_ptr == func_80058294_58E94 || D_80101178_101D78[i]->func_ptr == func_800585E8_591E8 ||
            D_80101178_101D78[i]->func_ptr == func_80058D18_59918) {
            if (D_80101178_101D78[i]->stat & 4) {
                D_80101178_101D78[i]->unk_50 = NULL;
                omDelObj(D_80101178_101D78[i]);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80058294_58E94);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005845C_5905C);

INCLUDE_ASM("asm/nonmatchings/58080", func_800585E8_591E8);

INCLUDE_ASM("asm/nonmatchings/58080", func_80058B58_59758);

INCLUDE_ASM("asm/nonmatchings/58080", func_80058D18_59918);

INCLUDE_ASM("asm/nonmatchings/58080", func_80058F18_59B18);

INCLUDE_ASM("asm/nonmatchings/58080", func_80059120_59D20);

s32 func_8005912C_59D2C(Object* arg0) {
    if (!(arg0->unk_38 != 0.0f)) {
        return 0;
    } else {
        return 1;
    }
}

void func_80059158_59D58(Object* arg0) {
    while (func_8005912C_59D2C(arg0) != 0) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80059198_59D98);

void func_80059254_59E54(s32 arg0) {
    omObjData* temp_v0;

    D_800CC62C_CD22C = LoadFormFile(0xA0075, 0x2AD);
    func_8002A00C_2AC0C(arg0);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, &func_80059198_59D98);
    D_800CC628_CD228 = temp_v0;
    temp_v0->trans.x = 0.0f;
    temp_v0->mdlcnt = arg0;
    temp_v0->mtncnt = (u16)D_800CC62C_CD22C;
    omSetStatBit(temp_v0, 0xA0);
}

void func_800592E4_59EE4(void) {
    if (D_800CC628_CD228 != NULL) {
        omDelObj(D_800CC628_CD228);
        D_800CC628_CD228 = NULL;
    }
    if (D_800CC62C_CD22C != -1) {
        func_800283DC_28FDC((s16)D_800CC62C_CD22C);
        D_800CC62C_CD22C = -1;
    }
}

u16 func_80059348_59F48(void) {
    return LoadFormFile(0xA0158, 0x2B9);
}

u16 func_80059370_59F70(void) {
    return LoadFormFile(0xA0155, 0x2A9);
}

void func_80059398_59F98(void) {
}

void func_800593A0_59FA0(s32 arg0, s16 arg1) {
    func_80062CD8_638D8(arg1);
}

void func_800593C0_59FC0(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800FDCD8_FE8D8[i].unk4 = NULL;
        D_800FDCD8_FE8D8[i].unk8 = NULL;
    }
}

void func_80059400_5A000(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        Unk4E530Motion* p = &D_800FDCD8_FE8D8[i];
        if (p->unk8 != NULL) {
            omDelObj(p->unk8);
            p->unk8 = NULL;
        }
    }
}

void func_8005946C_5A06C(omObjData* arg0) {
    Unk4E530Motion* p = &D_800FDCD8_FE8D8[arg0->work[0]];

    if (func_80029CE4_2A8E4(*p->unk4->unk_3C->unk_40) == func_80029D0C_2A90C(*p->unk4->unk_3C->unk_40)) {
        MBMotionShiftSet(p->unk4, p->unk0, 0, 0xA, p->unk2);
        p->unk4 = NULL;
        p->unk8 = NULL;
        omDelObj(arg0);
    }
}

s32 func_80059520_5A120(Object *arg0, s32 arg1, s32 arg2)
{
  Unk4E530Motion *p;
  omObjData *obj;
  s32 i;
  for (i = 0; i < 16; i++)
  {
    p = &D_800FDCD8_FE8D8[i];
    if (p->unk8 == 0)
    {
      break;
    }
  }

  if (i == 16)
  {
    if (1)
    {
      return -1;
    }
  }
  obj = omAddObj(0x2000, 0, 0, -1, func_8005946C_5A06C);
  p->unk8 = obj;
  obj->work[0] = i;
  p->unk4 = arg0;
  p->unk0 = arg1;
  arg2++;
  arg2--;
  arg1 = arg2;
  p->unk2 = arg1;
  return i;
}

void func_800595E8_5A1E8(void* arg0, s32 arg1, s32 arg2) {
    MBMotionShiftSet(arg0, arg1, 0, 0xA, arg2);
}

void func_80059618_5A218(void* arg0) {
    while (!(MBMotionCheck(arg0) & 1)) {
        HuPrcVSleep();
    }
}

void func_8005965C_5A25C(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800E1BA0_E27A0[i].unk0 = -1;
        D_800E1BA0_E27A0[i].unk2 = -1;
    }
}

void func_80059698_5A298(s32 arg0) {
    Unk4E530Sprite* p = &D_800E1BA0_E27A0[arg0];

    if (p->unk0 != -1) {
        SprKill(p->unk0);
        p->unk0 = -1;
    }
    if (p->unk2 != -1) {
        SprAnimKill(p->unk2);
        p->unk2 = -1;
    }
}

void func_80059704_5A304(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        func_80059698_5A298(i);
    }
}

s32 func_8005973C_5A33C(s32 arg0, u16 arg1, s16 arg2, s16 arg3) {
    Unk4E530Sprite* p;
    void* data;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800E1BA0_E27A0[i];
        if (p->unk0 == -1) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    p->unk0 = SprCreate(1, 5);
    data = DataRead(arg0);
    p->unk2 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(p->unk0, 0, p->unk2, 0);
    func_8008225C_82E5C(p->unk0, 0, 1);
    SprPrioSet(p->unk0, 0, arg1);
    SprAttrSet(p->unk0, 0, 0x1000);
    SprPosSet(p->unk0, 0, arg2, arg3);
    return i;
}

void func_80059868_5A468(s32 arg0, s16 arg1, s16 arg2) {
    SprPosSet(D_800E1BA0_E27A0[arg0].unk0, 0, arg1, arg2);
}

void func_800598A4_5A4A4(s32 arg0, u8 arg1) {
    func_80082488_83088(D_800E1BA0_E27A0[arg0].unk0, 0, arg1);
}

void func_800598D4_5A4D4(s32 arg0, f32 arg1, f32 arg2) {
    SprScaleSet(D_800E1BA0_E27A0[arg0].unk0, 0, arg1, arg2);
}

void func_80059914_5A514(s32 arg0, s32 arg1) {
    SprAttrSet(D_800E1BA0_E27A0[arg0].unk0, 0, arg1);
}

void func_80059944_5A544(s32 arg0, s32 arg1) {
    /* retail passes arg1 unmasked (the u16 prototype the pause menu needs would mask it) */
    ((void (*)(s16, s16, s32))SprAttrReset)(D_800E1BA0_E27A0[arg0].unk0, 0, arg1);
}

void func_80059974_5A574(s32 arg0, f32 arg1) {
    func_8008221C_82E1C(D_800E1BA0_E27A0[arg0].unk0, 0, arg1);
}

void func_800599AC_5A5AC(s32 arg0, u8 arg1, u8 arg2, u8 arg3) {
    func_80082450_83050(D_800E1BA0_E27A0[arg0].unk0, 0, arg1, arg2, arg3);
}

void func_800599F0_5A5F0(void) {
    s32 i;

    func_80020D20_21920(0x20);
    for (i = 0; i < 16; i++) {
        D_800E1BE0_E27E0[i].unk4 = NULL;
        D_800E1BE0_E27E0[i].unk0 = NULL;
    }
}

void func_80059A3C_5A63C(omObjData* arg0) {
    func_800242BC_24EBC(D_800E1BE0_E27E0[arg0->work[0]].unk4);
}

s32 func_80059A68_5A668(s32 arg0, s32 arg1) {
    Unk4E530Effect* p;
    omObjData* obj;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800E1BE0_E27E0[i];
        if (p->unk4 == NULL) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    p->unk4 = func_800240C8_24CC8(arg0, arg1);
    obj = omAddObj(0x3000, 0, 0, -1, func_80059A3C_5A63C);
    p->unk0 = obj;
    obj->work[0] = i;
    return i;
}

void func_80059B08_5A708(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4) {
    func_800244F4_250F4(D_800E1BE0_E27E0[arg0].unk4, 0, arg1, arg2, arg3, arg4);
}

void func_80059B5C_5A75C(s32 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5) {
    func_800244F4_250F4(D_800E1BE0_E27E0[arg0].unk4, arg1, arg2, arg3, arg4, arg5);
}

void func_80059BA4_5A7A4(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_800247EC_253EC(D_800E1BE0_E27E0[arg0].unk4, arg1, arg2, arg3);
}

void func_80059BCC_5A7CC(s32 arg0) {
    Unk4E530Effect* p = &D_800E1BE0_E27E0[arg0];

    if (p->unk4 != NULL) {
        func_80024234_24E34(p->unk4);
        p->unk4 = NULL;
    }
    if (p->unk0 != NULL) {
        omDelObj(p->unk0);
        p->unk0 = NULL;
    }
}

void func_80059C28_5A828(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800E1C60_E2860[i].unk0 = NULL;
        D_800E1C60_E2860[i].unk4 = -1;
    }
}

void func_80059C64_5A864(s32 arg0) {
    Unk4E530Data* p = &D_800E1C60_E2860[arg0];

    if (p->unk4 != -1) {
        func_8003E964_3F564(p->unk4);
        p->unk4 = -1;
    }
    if (p->unk0 != NULL) {
        DataClose(p->unk0);
        p->unk0 = NULL;
    }
}

void func_80059CC8_5A8C8(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        func_80059C64_5A864(i);
    }
}

s32 func_80059D00_5A900(s32 arg0, s32 arg1, char* arg2) {
    Unk4E530Data* p;
    void* data;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800E1C60_E2860[i];
        if (p->unk0 == NULL) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    data = DataRead(arg0);
    p->unk0 = data;
    p->unk4 = func_8003D8F0_3E4F0(D_800FC834_FD434[arg1].unk_64, data, 0, arg2);
    func_80029A8C_2A68C(arg1);
    return i;
}

void func_80059DC4_5A9C4(omObjData* arg0) {
    Vec pos;

    if (arg0->mdlcnt == 0) {
        arg0->trans.x = arg0->rot.x;
        arg0->trans.y = arg0->rot.y;
        arg0->trans.z = arg0->rot.z;
    } else {
        arg0->trans.x += arg0->scale.x;
        arg0->trans.y += arg0->scale.y;
        arg0->trans.z += arg0->scale.z;
    }
    pos.x = arg0->trans.x;
    pos.y = arg0->trans.y;
    pos.z = arg0->trans.z;
    MBDCameraPos3DSet(&pos);
    if (arg0->mdlcnt == 0) {
        omDelObj(arg0);
    }
    arg0->mdlcnt--;
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80059E7C_5AA7C);

s32 func_80059FB4_5ABB4(Vec* arg0, Vec* arg1) {
    return func_80059E7C_5AA7C(arg0, arg1, 30.0f);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_80059FD0_5ABD0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A084_5AC84);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A0CC_5ACCC);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A1D8_5ADD8);

void func_8005A29C_5AE9C(void) {
    f32 t;

    D_800E1CE4_E28E4 = 0.0f;
    D_800E1CE8_E28E8 = D_800E1CE0_E28E0 / 75.0f;
    while (1) {
        t = D_800E1CE4_E28E4 + D_800E1CE8_E28E8;
        D_800E1CE4_E28E4 = t;
        if (D_800E1CE0_E28E0 <= t) {
            break;
        }
        func_800794F0_7A0F0(t);
        HuPrcVSleep();
    }
    func_800794F0_7A0F0(D_800E1CE0_E28E0);
}

s32 MBRand(f32 arg0) {
    // rand8 returns an unsigned byte
    u8 randomByte1 = rand8();
    u8 randomByte2 = rand8();
    s32 shiftedByte1 = (randomByte1 << 8);

    // Normalize the 16-bit number to the range [0, 1), then multiply by arg0
    s32 scaledRandom = ((randomByte2 | shiftedByte1) / 65536.0f)* arg0;
    
    return scaledRandom;
}

s16 func_8005A3C4_5AFC4(void) {
    s32 id = D_800F8C60.unk_76;

    if (id == -1) {
        id = 6;
    }
    func_8005965C_5A25C();
    if (D_800CC630_CD230 != -1) {
        func_8005A474_5B074();
    }
    D_800CC630_CD230 = func_8005973C_5A33C(D_800CC640_CD240[id - 4], 10, 160, 120);
    SprAttrSet(D_800E1BA0_E27A0[D_800CC630_CD230].unk0, 0, 0x4000);
    return D_800E1BA0_E27A0[D_800CC630_CD230].unk0;
}

void func_8005A474_5B074(void) {
    func_80059698_5A298(D_800CC630_CD230);
    D_800CC630_CD230 = -1;
    func_80059704_5A304();
}

void func_8005A4A4_5B0A4(void) {
    func_80059914_5A514(D_800CC630_CD230, 0x8000);
}

void func_8005A4C8_5B0C8(void) {
    func_80059944_5A544(D_800CC630_CD230, 0x8000);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A4EC_5B0EC);

void func_8005A5E0_5B1E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A5E8_5B1E8);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A608_5B208);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A624_5B224);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A718_5B318);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A778_5B378);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A7E8_5B3E8);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005A950_5B550);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AA48_5B648);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AA98_5B698);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AAC0_5B6C0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AB50_5B750);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005ABC0_5B7C0);

void func_8005AC64_5B864(void) {
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AC6C_5B86C);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005ACD0_5B8D0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AD58_5B958);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005AD84_5B984);

INCLUDE_ASM("asm/nonmatchings/58080", MBPauseMesNumGet);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005ADCC_5B9CC);

BoardPlayer* func_8005AF48_5BB48(s16 arg0) {
    BoardPlayer* temp_s3;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    temp_s3 = func_8005E688_5F288(7, 0);
    temp_v0 = DataRead(D_800CC65C_CD25C[GwSystem.current_game_length]);
    temp_s3->unk_0C[0] = SprAnimRead(temp_v0);
    SprAnimSet(temp_s3->unk_0A, 0, temp_s3->unk_0C[0], 0);
    SprPrioSet(temp_s3->unk_0A, 0, 7);
    SprAttrSet(temp_s3->unk_0A, 0, 0x1000);
    SprPosSet(temp_s3->unk_0A, 0, 0xA0, D_800CC668_CD268[arg0]);
    func_800824B4_830B4(temp_s3->unk_0A, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    temp_v0 = DataRead(0xA00C9);
    temp_s3->unk_0C[1] = SprAnimRead(temp_v0);
    SprAnimSet(temp_s3->unk_0A, 1, temp_s3->unk_0C[1], 0);
    SprPrioSet(temp_s3->unk_0A, 1, 7);
    SprAttrSet(temp_s3->unk_0A, 1, 0x1000);
    SprPosSet(temp_s3->unk_0A, 1, 0x8C, D_800CC66C_CD26C[arg0]);
    func_800824B4_830B4(temp_s3->unk_0A, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    switch (GwSystem.current_game_length) {
    case 1:
        func_8005ADCC_5B9CC(temp_s3, 2, GwSystem.total_turns, 0xCA, D_800CC668_CD268[arg0]);
        break;
    case 0:
    case 2:
        func_8005ADCC_5B9CC(temp_s3, 2, GwSystem.total_turns, 0xAD, D_800CC668_CD268[arg0]);
    }
    func_8005ADCC_5B9CC(temp_s3, 4, GwSystem.current_turn, 0xB6, D_800CC66C_CD26C[arg0]);
    temp_v0 = DataRead(D_800CC640_CD240[GwSystem.current_board_index]);
    temp_s3->unk_0C[6] = SprAnimRead(temp_v0);
    SprAnimSet(temp_s3->unk_0A, 6, temp_s3->unk_0C[6], 0);
    SprPrioSet(temp_s3->unk_0A, 6, 7U);
    SprAttrSet(temp_s3->unk_0A, 6, 0x1000);
    SprPosSet(temp_s3->unk_0A, 6, 0xA0, 0x3C);
    DataClose(temp_v0);
    return temp_s3;
}

void func_8005B248_5BE48(void) {
    /* retail calls it without an argument */
    ((void (*)(void))HuMemDirectFree)();
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B264_5BE64);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B338_5BF38);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B424_5C024);

s32 MBPauseDlgMesSet(s16 arg0, s32 arg1) {
    func_8008AD44_8B944(arg0);
    func_800890CC_89CCC(arg0, MBPauseMesNumGet(arg1), -1, -1);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B56C_5C16C);

Process* func_8005B7A8_5C3A8(s16 arg0, s32* arg1) {
    Process* process;
    unkMallocStruct* processUserData;

    process = omAddPrcObj(&func_8005B56C_5C16C, 0x1005, 0, 0x40);
    processUserData = HuMemMemoryAlloc(process->heap, sizeof(unkMallocStruct));
    process->user_data = processUserData;
    processUserData->unk0 = arg1;
    processUserData->unk4 = arg0;
    return process;
}

s16 MBPauseQuitMesCreate(s32 arg0, s16 arg1) {
    s16 sp18[2];
    s16 temp_v0;

    func_8008DACC_8E6CC(1, sp18, arg0);
    temp_v0 = func_800888A8_894A8(0xA0 - sp18[0] / 2, arg1, sp18[0], sp18[1], 0, 0);
    func_800890CC_89CCC(temp_v0, arg0, -1, -1);
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B8B0_5C4B0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005B9A0_5C5A0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005BF2C_5CB2C);

void func_8005C0B8_5CCB8(void) {
    HuMemDirectFree(D_800E1CFC_E28FC);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C0D8_5CCD8);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C24C_5CE4C);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C3B0_5CFB0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C508_5D108);

s32 func_8005C670_5D270(s16 arg0) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        if (!(player->flags & 1) && player->port == arg0) {
            return 1;
        }
    }
    return 0;
}

s32 func_8005C6DC_5D2DC(GW_PLAYER* arg0, s16 arg1) {
    GW_PLAYER* player;
    u8 port = arg0->port;
    s32 i;

    if (arg1 < 4) {
        for (i = 0; i < 4; i++) {
            player = BoardPlayerGet(i);
            if (player->port == arg1) {
                player->port = port;
                arg0->port = arg1;
                arg0->flags &= ~1;
                return;
            }
        }
    } else {
        arg0->flags |= 1;
    }
}

s32 func_8005C78C_5D38C(GW_PLAYER *arg0, s16 arg1)
{
  s16 step = arg1;
  s32 tries;
  u32 port;
  if (PlayerIsCPU((u8)arg0->unk_1C[0]) != 0)
  {
    tries = 4;
    port = (step > 0) ? (0) : (3);
    do
    {
      if ((func_8005C670_5D270(port) == 0) && (HuGetPadInserted(port) != 0))
      {
        return port;
      }
      port += arg1;
    }
    while ((--tries) != 0);
    return 4;
  }
  if (arg1 > 0)
  {
    port = arg0->port + 1;
  }
  else
  {
    port = arg0->port - 1;
  }
  for (; port < 4; port += arg1)
  {
    if ((func_8005C670_5D270(port) == 0) && (HuGetPadInserted(port) != 0))
    {
      return port;
    }
  }

  return 4;
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C8A0_5D4A0);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C8AC_5D4AC);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005C980_5D580);

s32 func_8005CAD0_5D6D0(s32 arg0) {
    u16 sp1E;
    BoardPlayer *boardPlayer1;
    BoardPlayer *boardPlayer2;
    BoardPlayer* boardPlayer3;
    BoardPlayer* boardPlayer4;
    GW_PLAYER* tempBoardPlayer;
    Process* process;
    s32 sp3C;
    s16 var_a0_2;
    s32 i;
    s32 var_v0;
    s32 var_s1;
    void** mainFSData;

    sp3C = 0;
    sp1E = 0;
    for (i = 0; i < 4; i++) {
        if (PlayerIsCPU(i) == 0 && gPlayers[i].port == arg0) {
            sp1E = i;
            break;
        }
    }
    boardPlayer1 = func_8005E688_5F288(8, 0);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            mainFSData = DataRead(0xA01C8);
            boardPlayer1->unk_0C[0] = SprAnimRead(mainFSData);
            DataClose(mainFSData);
            mainFSData = DataRead(0xA01C9);
            boardPlayer1->unk_0C[4] = SprAnimRead(mainFSData);
            DataClose(mainFSData);
        }
        SprAnimSet(boardPlayer1->unk_0A, i, boardPlayer1->unk_0C[0], 0);
        SprPrioSet(boardPlayer1->unk_0A, i, 8);
        SprAttrSet(boardPlayer1->unk_0A, i, 0x1000U);
        SprPosSet(boardPlayer1->unk_0A, i, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i]);
        func_80082450_83050(boardPlayer1->unk_0A, i, 0, 0, 0xFF);
        SprAnimSet(boardPlayer1->unk_0A, i + 4, boardPlayer1->unk_0C[4], 0);
        SprPrioSet(boardPlayer1->unk_0A, i + 4, 8);
        SprAttrSet(boardPlayer1->unk_0A, i + 4, 0x1000U);
        SprPosSet(boardPlayer1->unk_0A, i + 4, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i]);
    }
    boardPlayer2 = func_8005E688_5F288(8, 0);
    for (i = 0; i < 4; i++) {
        tempBoardPlayer = BoardPlayerGet(i);
        mainFSData = DataRead(D_800CC754_CD354[tempBoardPlayer->character]);
        boardPlayer2->unk_0C[i] = SprAnimRead(mainFSData);
        SprAnimSet(boardPlayer2->unk_0A, i, boardPlayer2->unk_0C[i], 0);
        SprPrioSet(boardPlayer2->unk_0A, i, 7);
        SprAttrSet(boardPlayer2->unk_0A, i, 0x1000U);
        SprPosSet(boardPlayer2->unk_0A, i, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i] - 0x17);
        DataClose(mainFSData);
        mainFSData = DataRead(D_800CC76C_CD36C[tempBoardPlayer->character]);
        boardPlayer2->unk_0C[i + 4] = SprAnimRead(mainFSData);
        SprAnimSet(boardPlayer2->unk_0A, i + 4, boardPlayer2->unk_0C[i + 4], 0);
        SprPrioSet(boardPlayer2->unk_0A, i + 4, 7);
        SprAttrSet(boardPlayer2->unk_0A, i + 4, 0x1000U);
        SprPosSet(boardPlayer2->unk_0A, i + 4, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i] - 7);
        DataClose(mainFSData);
    }
    boardPlayer3 = func_8005E688_5F288(8, 0);
    for (i = 0; i < 8; i++) {
        mainFSData = DataRead(D_800CC784_CD384[i]);
        boardPlayer3->unk_0C[i] = SprAnimRead(mainFSData);
        DataClose(mainFSData);
    }
    for (i = 0; i < 4; i++) {
        if (PlayerIsCPU(i) != 0) {
            SprAnimSet(boardPlayer3->unk_0A, i, boardPlayer3->unk_0C[D_800CC7AC_CD3AC[gPlayers[i].cpu_difficulty2 * 2]], 0);
            SprAnimSet(boardPlayer3->unk_0A, (i + 4), boardPlayer3->unk_0C[D_800CC7AC_CD3AC[(gPlayers[i].cpu_difficulty2 * 2) + 1]], 0);
            SprPosSet(boardPlayer3->unk_0A, i, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i] + 8);
        } else {
            SprAnimSet(boardPlayer3->unk_0A, i, boardPlayer3->unk_0C[D_800CC7A4_CD3A4[gPlayers[i].port * 2]], 0);
            SprAnimSet(boardPlayer3->unk_0A, i + 4, boardPlayer3->unk_0C[D_800CC7A4_CD3A4[gPlayers[i].port * 2]], 0);
            SprPosSet(boardPlayer3->unk_0A, i, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i] + 0x10);
            SprAttrSet(boardPlayer3->unk_0A, i + 4, 0x8000U);
        }
        SprPrioSet(boardPlayer3->unk_0A, i, 7);
        SprAttrSet(boardPlayer3->unk_0A, i, 0x01001000U);
        SprPrioSet(boardPlayer3->unk_0A, i + 4, 7);
        SprAttrSet(boardPlayer3->unk_0A, i + 4, 0x01001000U);
        SprPosSet(boardPlayer3->unk_0A, i + 4, D_800CC7B4_CD3B4[i], D_800CC7BC_CD3BC[i] + 0x18);
    }
    boardPlayer4 = func_8005E688_5F288(3, 0);
    mainFSData = DataRead(0xA001B);
    boardPlayer4->unk_0C[0] = SprAnimRead(mainFSData);
    SprAnimSet(boardPlayer4->unk_0A, 0, boardPlayer4->unk_0C[0], 0);
    SprAttrSet(boardPlayer4->unk_0A, 0, 0x1808U);
    SprPrioSet(boardPlayer4->unk_0A, 0, 8);
    SprScaleSet(boardPlayer4->unk_0A, 0, 0.5f, 0.5f);
    DataClose(mainFSData);
    mainFSData = DataRead(0xA01DF);
    boardPlayer4->unk_0C[1] = SprAnimRead(mainFSData);
    SprAnimSet(boardPlayer4->unk_0A, 1, boardPlayer4->unk_0C[1], 0);
    SprAttrSet(boardPlayer4->unk_0A, 1, 0x9808U);
    SprPrioSet(boardPlayer4->unk_0A, 1, 8);
    func_800824B4_830B4(boardPlayer4->unk_0A, 1, 0xFF, 0, 0, 0x80);
    DataClose(mainFSData);
    mainFSData = DataRead(0xA01DE);
    boardPlayer4->unk_0C[2] = SprAnimRead(mainFSData);
    SprAnimSet(boardPlayer4->unk_0A, 2, boardPlayer4->unk_0C[2], 0);
    SprAttrSet(boardPlayer4->unk_0A, 2, 0x9808U);
    SprPrioSet(boardPlayer4->unk_0A, 2, 8);
    func_800824B4_830B4(boardPlayer4->unk_0A, 2, 0xFF, 0, 0, 0x80);
    DataClose(mainFSData);
    func_8005C8AC_5D4AC(boardPlayer4, sp1E);
    func_8005C8A0_5D4A0(0);
    process = omAddPrcObj(func_8005C980_5D580, 0x1005U, 0, 0);
    process->user_data = boardPlayer4;
    do {
        _CheckFlag(0xD);
        if (sp3C != 0x51B) {
            sp3C = 0x51B;
            MBPauseDlgMesSet(D_800E1CF0_E28F0[4], sp3C);
        }
        HuPrcVSleep();
        var_a0_2 = -1;
        if (ContDStkTrg[arg0] & 0x800) {
            var_a0_2 = 0;
        }
        if (ContDStkTrg[arg0] & 0x400) {
            var_a0_2 = 1;
        }
        if (ContDStkTrg[arg0] & 0x200) {
            var_a0_2 = 2;
        }
        if (ContDStkTrg[arg0] & 0x100) {
            var_a0_2 = 3;
        }
        if (var_a0_2 != -1) {
            sp1E += D_800CC7C4_CD3C4[(s16)sp1E << 2][var_a0_2];
            func_8005C8AC_5D4AC(boardPlayer4, sp1E);
            PlaySound(1);
            continue;
        }

        // wtf? if 0-ed to keep code in "correct" place
        if (0) {
            dummy:
            PlaySound(2);
            ((s32 (*)(s16, u8))func_8005DEB0_5EAB0)(sp1E, var_s1);
            goto bail;
        }
        if (D_8010163C_10223C[arg0] & 0x8000) {
            PlaySound(2);
            tempBoardPlayer = BoardPlayerGet((s16)sp1E);
            func_8005C8A0_5D4A0(1);
            var_s1 = tempBoardPlayer->cpu_difficulty2;
            i = -1;
            if (PlayerIsCPU(sp1E)) {
                i = 4;
            }
            while (1) {
                HuPrcVSleep();
                _CheckFlag(0xD);
                if (sp3C != 0x51C) {
                    sp3C = 0x51C;
                    MBPauseDlgMesSet(D_800E1CF0_E28F0[4], sp3C);
                }
                if (ContDStkTrg[arg0] & 0x200) {
                    if (i != 4 || var_s1 == 0) {
                        i = func_8005C78C_5D38C(tempBoardPlayer, -1);
                        if (i == 4) {
                            var_s1 = 2;
                        }
                    } else {
                        var_s1 -= 1;
                    }
                    ((s32 (*)(s16, u8))func_8005DEB0_5EAB0)(sp1E, var_s1);
                    PlaySound(1);
                } else if (ContDStkTrg[arg0] & 0x100) {
                    if (i != 4 || var_s1 == 2) {
                        i = func_8005C78C_5D38C(tempBoardPlayer, 1);
                        if (i == 4) {
                            var_s1 = 0;
                        } else {
                            var_s1 &= -1;
                        }
                    } else {
                        var_s1 += 1;
                    }
                    ((s32 (*)(s16, u8))func_8005DEB0_5EAB0)(sp1E, var_s1);
                    PlaySound(1);
                }
                if (i >= 0) {
                    func_8005C6DC_5D2DC(tempBoardPlayer, i);
                    if (PlayerIsCPU(sp1E) != 0) {
                        SprAnimSet(boardPlayer3->unk_0A, sp1E, boardPlayer3->unk_0C[D_800CC7AC_CD3AC[gPlayers[(s16)sp1E].cpu_difficulty2 * 2]], 0);
                        SprAnimSet(boardPlayer3->unk_0A, sp1E + 4, boardPlayer3->unk_0C[D_800CC7AC_CD3AC[(gPlayers[(s16)sp1E].cpu_difficulty2) * 2 + 1]], 0);
                        SprPosSet(boardPlayer3->unk_0A, sp1E, D_800CC7B4_CD3B4[(s16)sp1E], D_800CC7BC_CD3BC[(s16)sp1E] + 8);
                        SprAttrReset(boardPlayer3->unk_0A, sp1E + 4, 0x8000U);
                    } else {
                        SprAnimSet(boardPlayer3->unk_0A, sp1E, boardPlayer3->unk_0C[D_800CC7A4_CD3A4[gPlayers[(s16)sp1E].port * 2]], 0);
                        SprPosSet(boardPlayer3->unk_0A, sp1E, D_800CC7B4_CD3B4[(s16)sp1E], D_800CC7BC_CD3BC[(s16)sp1E] + 0x10);
                        SprAttrSet(boardPlayer3->unk_0A, sp1E + 4, 0x8000U);
                    }
                }
                var_v0 = ContDStkTrg[arg0];
                var_v0 &= 0x8000;
                if (var_v0) {
                    goto dummy;
                }

                var_v0 = ContDStkTrg[arg0];
                var_v0 &= 0x4000;
                if (var_v0) {
                    PlaySound(4);
                    break;
                }
            }
            
            bail:
            func_8005C8A0_5D4A0(0);
            HuPrcVSleep();
        }
    } while (!(D_8010163C_10223C[arg0] & 0x4000));
    PlaySound(4);
    omDelPrcObj(process);
    HuMemDirectFree(boardPlayer4);
    HuMemDirectFree(boardPlayer3);
    HuMemDirectFree(boardPlayer2);
    HuMemDirectFree(boardPlayer1);
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005D7D4_5E3D4);

void func_8005D88C_5E48C(void) {
    s32 arg = (s32)HuPrcCurrentGet()->user_data;
    s16 state = 1;
    s16 paused = func_80061504_62104();
    BoardPlayer* sprite;
    void* data;

    if (paused != 0) {
        func_80061518_62118();
    }
    HuPrcVSleep();
    D_800FDC9C_FE89C = 1;
    sprite = func_8005E688_5F288(1, 0);
    data = DataRead(0xA00D6);
    sprite->unk_0C[0] = SprAnimRead(data);
    SprAnimSet(sprite->unk_0A, 0, sprite->unk_0C[0], 0);
    SprPrioSet(sprite->unk_0A, 0, 9);
    SprAttrSet(sprite->unk_0A, 0, 0x1000);
    SprPosSet(sprite->unk_0A, 0, 0xA0, 0x78);
    SprScaleSet(sprite->unk_0A, 0, 40.0f, 30.0f);
    func_800824B4_830B4(sprite->unk_0A, 0, 0, 0, 0, 0xC0);
    DataClose(data);
    do {
        HuPrcVSleep();
        state = func_8005D7D4_5E3D4(state, arg);
    } while (state != 0);
    if (D_800E1CF6_E28F6 == 0) {
        D_800FDC9C_FE89C = 0;
    }
    HuMemDirectFree(sprite);
    if (paused != 0) {
        func_80061584_62184();
    }
    omDelPrcObj(NULL);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005DA20_5E620);

s16 GetCurrentPlayerIndex(void) {
    return GwSystem.current_player_index;
}

INCLUDE_ASM("asm/nonmatchings/58080", BoardPlayerGet);

s16 PlayerIsCurrent(s16 index) {
    return index == GwSystem.current_player_index;
}

s32 PlayerIsCPU(s16 index) {
    return BoardPlayerGet(index)->flags & 1;
}

void AdjustPlayerCoins(s32 index, s32 count) {
    GW_PLAYER* player = BoardPlayerGet(index);
    player->coins += count;
    if (player->coins >= 1000) {
        player->coins = 999;
    }
    if (player->coins < 0) {
        player->coins = 0;
    }

    if (player->coins_max <= player->coins) {
        player->coins_max = player->coins;
    }
}

s32 BoardSpaceGet(s32 index, s32 count) {
    GW_PLAYER* player = BoardPlayerGet(index);
    return player->coins >= count;
}

void MBPlayerMotionSet(s32 playerNo, s16 arg1, u16 arg2) {
    GW_PLAYER *player = BoardPlayerGet(playerNo);

    if (player == BoardPlayerGet(CUR_PLAYER)) {
        MBMotionSet(player->unk_24, arg1, arg2);
        if ((player->turn_status != 0) & (arg1 < 7)) {
            MBKSuitMotionSet(arg1, arg2);
        }
    }
}

void func_8005DDEC_5E9EC(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    GW_PLAYER *player = BoardPlayerGet(playerNo);

    if (player == BoardPlayerGet(CUR_PLAYER)) {
        MBMotionShiftSet(player->unk_24, arg1, arg2, arg3, arg4);
        if ((player->turn_status != 0) & (arg1 < 7)) {
            MBKSuitMotionShiftSet(arg1, arg2, arg3, arg4);
        }
    }
}

void func_8005DEB0_5EAB0(s32 index, u8 b) {
    GW_PLAYER* player = BoardPlayerGet(index);
    player->cpu_difficulty2 = b;
    if (!_CheckFlag(13)) {
        player->cpu_difficulty = D_800CC7F0_CD3F0[b];
    }
    else {
        player->cpu_difficulty = D_800CC7F4_CD3F4[b];
    }
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005DF18_5EB18);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005DF78_5EB78);

INCLUDE_ASM("asm/nonmatchings/58080", MBPlayerModelCreate);

void func_8005E130_5ED30(s16 arg0, u32 *arg1) {
    MBPlayerModelCreate(arg0, arg1, 0);
}

void func_8005E154_5ED54(s16 playerNo) {
    GW_PLAYER *player = BoardPlayerGet(playerNo);

    MBPlayerModelCreate(playerNo, D_800CC8B8_CD4B8[player->character], 0);
}

void func_8005E1A0_5EDA0(s16 playerNo) {
    GW_PLAYER *player = BoardPlayerGet(playerNo); // remnants of a debug build or the below function was changed to take a playerNo

    MBPlayerModelCreate(playerNo, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005E1DC_5EDDC);

INCLUDE_ASM("asm/nonmatchings/58080", func_8005E228_5EE28);

void func_8005E260_5EE60(s16 playerIndex) {
    GW_PLAYER* temp_v0;

    temp_v0 = BoardPlayerGet(playerIndex);
    if (temp_v0->unk_24 != 0) {
        if (temp_v0->unk_20 != 0) {
            omDelPrcObj(temp_v0->unk_20);
        }
        MBModelKill(temp_v0->unk_24);
        temp_v0->unk_24 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005E2B8_5EEB8);

void func_8005E2F4_5EEF4(void) {
}

INCLUDE_ASM("asm/nonmatchings/58080", func_8005E2FC_5EEFC);
