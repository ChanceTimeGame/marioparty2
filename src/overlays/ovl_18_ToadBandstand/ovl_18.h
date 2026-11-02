#ifndef _OVL_18_H
#define _OVL_18_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Toad Bandstand: one retail file found, 186490.c; .data is asm (0x1906D0: songs, display lists),
   .rodata from 0x190C80. */

/* one player: the CPU's plan for the song's 36 beats */
typedef struct TSPlayer {
    /* 0x00 */ s8 id;
    /* 0x01 */ s8 group;     /* place in the band, 0-3 */
    /* 0x02 */ s8 port;
    /* 0x03 */ s8 character;
    /* 0x04 */ s8 cpu;       /* difficulty, -1 a human */
    /* 0x05 */ s8 press[36]; /* the CPU presses on this beat */
    /* 0x29 */ s8 timing[36];/* frames off the beat */
} TSPlayer; /* size = 0x4D */

/* the song tables, copied to the stack: a struct copy is retail's local aggregate, whose
   initialiser lives in the asm .data */
typedef struct TSBeats { u8 v[2][36]; } TSBeats;
typedef struct TSSteps { s16 v[2][27]; } TSSteps;
typedef struct TSTimes { s16 v[2][6]; } TSTimes;
typedef struct TSBytes4 { s8 v[4]; } TSBytes4;
typedef struct TSFloats4 { f32 v[4]; } TSFloats4;
typedef struct TSDirs { s32 v[6]; } TSDirs;
typedef struct TSPans { s16 v[4]; } TSPans;

/* a step's ease: 0..1 */
#define TS_ARC(t) ((t) * (t) * 0.5 + (t) * 0.5)

/* a float screen position to 10.2, rounded towards zero by hand */
#define TS_FIX(f) ((s32)((f) * 4.0) + ((f) < 0.0f ? 1 : 0))
/* texture step for 41 texels drawn from lo to hi */
#define TS_STEP(hi, lo) ((s32)((41.0 / ((f32)((s32)((hi) * 4.0) + ((hi) < 0.0f ? 1 : 0) - (s32)((lo) * 4.0) - ((lo) < 0.0f ? 1 : 0)) / 4.0)) * 1024.0))

/* ---- main-segment API missing from include/ ---- */
typedef struct TSCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 dir;
    /* 0x08 */ char unk_08[0x10];
} TSCharData; /* size = 0x18 */
extern TSCharData D_800CD438_CE038[];
typedef struct TSEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} TSEspSlot; /* size = 0x24 */
extern TSEspSlot* D_800F93FC_F9FFC;
extern Gfx* D_800FDBCC_FE7CC;
extern HmfModel* D_800FC834_FD434;
extern u16 D_801011FC_101DFC;
extern u8 D_80102708_103308;
extern u16 ContBtnTrg[];
extern u8 D_800FA656;
extern f32 D_800FA5BC_FB1BC[];
extern f32 D_800F8410_F9010;
extern f32 D_80101078_101C78;
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
f32 HuMathSin(f32);
u16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16, s16, s32);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void espDispOff(u16);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s16);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
s16 func_80027D3C_2893C(s16 linkMdlId);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32);
s32 func_80029E14_2AA14(s16 arg0);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_800795D8_7A1D8(s16 sound, s16 volume);
void func_80079614_7A214(s16 time);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
f32 func_800B7890_B8490(f32);

/* ---- .data ---- */
extern u16 D_8010CA40_1906D0_ToadBandstand[8];
extern s32 D_8010CA50_1906E0_ToadBandstand[2][36]; /* sprite per beat */
extern u16 D_8010CB70_190800_ToadBandstand[2];
extern f32 D_8010CB74_190804_ToadBandstand[2];
extern f32 D_8010CB7C_19080C_ToadBandstand[34];
extern u32 D_8010CC04_190894_ToadBandstand[15];
extern s32 D_8010CC40_1908D0_ToadBandstand[15];
extern f32 D_8010CC7C_19090C_ToadBandstand[6];
extern f32 D_8010CC94_190924_ToadBandstand[6];
extern f32 D_8010CCAC_19093C_ToadBandstand[6];
extern f32 D_8010CCC4_190954_ToadBandstand[7];
extern Gfx D_8010CD30_1909C0_ToadBandstand[];
extern u8 D_8010CD80_190A10_ToadBandstand[12];
extern TSBytes4 D_8010CD8C_190A1C_ToadBandstand;
extern TSBytes4 D_8010CD90_190A20_ToadBandstand;
extern TSBeats D_8010CD94_190A24_ToadBandstand;
extern TSBeats D_8010CDDC_190A6C_ToadBandstand;
extern TSSteps D_8010CE24_190AB4_ToadBandstand;
extern TSTimes D_8010CE90_190B20_ToadBandstand;
extern TSBeats D_8010CEA8_190B38_ToadBandstand;
extern TSBeats D_8010CEF0_190B80_ToadBandstand;
extern TSSteps D_8010CF38_190BC8_ToadBandstand;
extern TSTimes D_8010CFA4_190C34_ToadBandstand;
extern TSPans D_8010CFBC_190C4C_ToadBandstand;
extern TSFloats4 D_8010CFC4_190C54_ToadBandstand;
extern TSDirs D_8010CFD4_190C64_ToadBandstand;

/* ---- rodata, shared by name ---- */
extern const char D_8010D17C_190E0C_ToadBandstand[];

/* ---- bss ---- */
extern TSPlayer D_8010D710_1913A0_ToadBandstand[4];
extern TSPlayer* D_8010D848_1914D8_ToadBandstand[4];
extern s16 D_8010D860_1914F0_ToadBandstand[4];
extern s32 D_8010D868_1914F8_ToadBandstand[4];
extern s32 D_8010D878_191508_ToadBandstand[4];
extern f32 D_8010D888_191518_ToadBandstand;
extern s16 D_8010D890_191520_ToadBandstand[2][27];
extern s16 D_8010D8FC_19158C_ToadBandstand;
extern f32 D_8010D900_191590_ToadBandstand;
extern u8 D_8010D904_191594_ToadBandstand;
extern s32 D_8010D908_191598_ToadBandstand[4];
extern s16 D_8010D918_1915A8_ToadBandstand[4];
extern u16 D_8010D920_1915B0_ToadBandstand[13];
extern s16 D_8010D940_1915D0_ToadBandstand[15];
extern s32 D_8010D980_191610_ToadBandstand;
extern s8 D_8010D984_191614_ToadBandstand;
extern s32 D_8010D988_191618_ToadBandstand;
extern u16 D_8010D990_191620_ToadBandstand[15];
extern s32 D_8010D9B0_191640_ToadBandstand;
extern s16 D_8010D9B4_191644_ToadBandstand[4];
extern s32 D_8010D9BC_19164C_ToadBandstand;
extern u8 D_8010D9C0_191650_ToadBandstand[2][36];
extern u16 D_8010DA28_1916B8_ToadBandstand[2][6];
extern u8 D_8010DA40_1916D0_ToadBandstand;
extern s16 D_8010DA42_1916D2_ToadBandstand[2];
extern omObjData* D_8010DA68_1916F8_ToadBandstand;
extern s32 D_8010DA6C_1916FC_ToadBandstand;
extern s32 D_8010DA70_191700_ToadBandstand;
extern omObjData* D_8010DA88_191718_ToadBandstand[4];
extern s16 D_8010DA98_191728_ToadBandstand[4];
extern u16 D_8010DAA0_191730_ToadBandstand;
extern u8 D_8010DAA2_191732_ToadBandstand[4];
extern s8 D_8010DAA6_191736_ToadBandstand;
extern s16 D_8010DAA8_191738_ToadBandstand[2];
extern u8 D_8010DAAC_19173C_ToadBandstand;
extern s8 D_8010DAAD_19173D_ToadBandstand[4];

/* ---- functions ---- */
void func_80102800_186490_ToadBandstand(void);
void func_80102A68_1866F8_ToadBandstand(s16, f32);
void func_80102AA4_186734_ToadBandstand(omObjData*);
void func_8010329C_186F2C_ToadBandstand(void);
void func_80103780_187410_ToadBandstand(void);
void func_80103C64_1878F4_ToadBandstand(omObjData*);
void func_80105480_189110_ToadBandstand(omObjData*);
void func_80105CB8_189948_ToadBandstand(omObjData*);
void func_801070F8_18AD88_ToadBandstand(omObjData*);
void func_8010712C_18ADBC_ToadBandstand(omObjData*);
void func_80107160_18ADF0_ToadBandstand(omObjData*);
void func_80107194_18AE24_ToadBandstand(omObjData*);
void func_801071C8_18AE58_ToadBandstand(omObjData*, s32);
void func_801077B8_18B448_ToadBandstand(omObjData*);
void func_801077D4_18B464_ToadBandstand(omObjData*);
void func_801077F0_18B480_ToadBandstand(omObjData*);
void func_8010780C_18B49C_ToadBandstand(omObjData*);
void func_80107828_18B4B8_ToadBandstand(omObjData*, s8);
void func_80109344_18CFD4_ToadBandstand(s16, s16);
void func_80109388_18D018_ToadBandstand(Gfx**, s32, s32);
void func_8010B6E4_18F374_ToadBandstand(s16);
void func_8010B710_18F3A0_ToadBandstand(s16, f32, f32, f32);
void func_8010C804_190494_ToadBandstand(void);

#endif /* _OVL_18_H */
