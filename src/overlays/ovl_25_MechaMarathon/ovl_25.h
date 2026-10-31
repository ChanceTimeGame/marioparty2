#ifndef _OVL_25_H
#define _OVL_25_H

/* Overlay 25: Mecha Marathon (4P). Each player mashes A+B in pairs of frames to charge a Mecha
   Fly Guy (the "robot"); after the time limit the robots run down the track on their speed,
   jump and fall, and the longest flight wins. No MP1 ancestor.
   Retail is two files: 1F1540.c and 1F6CA0.c (80107F60, 3-nop pad). .rodata is carved from
   0x1F6F70 (only 1F1540.c has any); .data and .bss stay asm. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API used by 25 (missing from include/) ---- */

typedef struct MMCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ s32 unk_0C; /* the second model file */
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} MMCharData;
extern MMCharData D_800CD438_CE038[];

extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80018E30_19A30(s32);
void func_80018F58_19B58(s32);
void func_80079FF4_7ABF4(omObjData* object);
void func_80079128_79D28(void);
u8 rand8(void);
s32 PlaySound(s32);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32 id, s16 player);
void func_80079848_7A448(s16 arg0); /* stop a sound */
void func_800794A8_7A0A8(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_8006D518_6E118(void);
void func_8006D4D0_6E0D0(s16);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
f64 func_800B75D0_B81D0(f64); /* cos of degrees, in double */
f64 func_800B80D0_B8CD0(f64); /* sin of degrees, in double */
void func_800B1F50_B2B50(void* m, f32 x, f32 y, f32 z); /* guTranslateF */
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void func_80018CCC_198CC(omObjData* obj, u16 idx, s32 file);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);      /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0); /* main: u8; retail re-extends */
f32 func_80029E3C_2AA3C(s16 idx);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029EDC_2AADC(s16, s32);
void func_80029FE4_2ABE4(s16 arg0, f32 arg1);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
s16 func_8003DBE8_3E7E8(HmfData* arg0, u16 arg1, s16 arg2, char* arg3);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E888_3F488(s16 arg0);
void func_8003F57C_4017C(s16 arg0, s16 arg1);
s32 _CheckFlag(s32);
u16 func_800680D4_68CD4(s16 index);
void GWMgRecordSet(s16 arg0, u16 arg1); /* main: s16 */
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
void func_80082488_83088(s16 group, s16 member, u16 a); /* sprite alpha */
s32 func_8008F618_90218(void);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprAttrSet(s16 group, s16 member, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);

int abs(int); /* GCC builtin (a single insn) */

/* ---- overlay types ---- */

/* The overlay's actor table, 0x48 each: D_801085F0_1F7330_MechaMarathon[0-3] players, [4] the host, [5] the track
   (.unk_38-.unk_44: segment positions and the record marker), [6] the crowd, [8] the score
   sprites, [9-12] the robots. Retail clears all 50. */
typedef struct MMActor {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 state;
    /* 0x22 */ u16 unk_22; /* player: speed index; robot: 1 off screen */
    /* 0x24 */ u16 unk_24; /* player: count of the last window; robot: 1 tired */
    /* 0x26 */ u16 unk_26; /* player: frame in the window */
    /* 0x28 */ u16 unk_28; /* player: total pairs; robot: 1 the winner's, 2-4 its fall */
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C; /* player: CPU */
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ s16 unk_30; /* robot: frames to the crash sound */
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ f32 unk_38; /* offset along the track */
    /* 0x3C */ f32 unk_3C; /* robot: where it starts to fall */
    /* 0x40 */ f32 unk_40; /* robot: speed */
    /* 0x44 */ f32 unk_44;
} MMActor;

/* CPU mash timing, one per player. */
typedef struct MMCpu {
    /* 0x0 */ s32 unk_00; /* frames to the next press */
    /* 0x4 */ s32 unk_04; /* press interval */
    /* 0x8 */ s32 unk_08; /* frames to the next interval choice */
} MMCpu;

typedef struct MMFast {
    /* 0x0 */ u16 chance;
    /* 0x2 */ u16 rate;
} MMFast;

/* Robot flight, one per robot. */
typedef struct MMRobot {
    /* 0x00 */ f32 unk_00; /* x offset */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08; /* height speed */
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 unk_14; /* flags */
} MMRobot;

extern const char D_80108290_1F6FD0_MechaMarathon[];

/* ---- .data (1F1540.c, 0x1F6D50-0x1F6F70) ---- */

extern s16 D_80108010_1F6D50_MechaMarathon[6];  /* record sprite x */
extern s16 D_8010801C_1F6D5C_MechaMarathon[10]; /* score sprite x */
extern s16 D_80108030_1F6D70_MechaMarathon[6];  /* record digits; survives between plays */
extern s32 D_8010803C_1F6D7C_MechaMarathon[6];
extern u16 D_80108054_1F6D94_MechaMarathon[4];
extern s32 D_8010805C_1F6D9C_MechaMarathon;
extern u8 D_80108060_1F6DA0_MechaMarathon;
extern s32 D_80108064_1F6DA4_MechaMarathon;
extern s32 D_80108068_1F6DA8_MechaMarathon[6][8]; /* per character motion files */
extern Vec D_80108128_1F6E68_MechaMarathon[4];    /* lanes */
extern f32 D_80108158_1F6E98_MechaMarathon[11];   /* motion speeds */
extern u16 D_80108184_1F6EC4_MechaMarathon[4];
extern s16 D_8010818C_1F6ECC_MechaMarathon;
extern s16 D_80108190_1F6ED0_MechaMarathon[6];
extern u16 D_8010819C_1F6EDC_MechaMarathon[2];
extern const char* D_801081A0_1F6EE0_MechaMarathon[6];
extern s16 D_801081B8_1F6EF8_MechaMarathon;
extern s32 D_801081BC_1F6EFC_MechaMarathon[4];
extern s32 D_801081CC_1F6F0C_MechaMarathon[18];
extern const char* D_80108214_1F6F54_MechaMarathon[3];
extern s16 D_80108220_1F6F60_MechaMarathon;
extern u16 D_80108222_1F6F62_MechaMarathon;
extern s16 D_80108224_1F6F64_MechaMarathon;
extern s16 D_80108226_1F6F66_MechaMarathon;
extern s16 D_80108228_1F6F68_MechaMarathon;

/* ---- .bss (asm) ---- */

extern s16 D_80108460_1F71A0_MechaMarathon; /* message window */
extern s16 D_80108462_1F71A2_MechaMarathon; /* score alpha */
extern u8 D_80108464_1F71A4_MechaMarathon;  /* game state */
extern u8 D_80108465_1F71A5_MechaMarathon;  /* flags: 1 host waiting, 2 result shown, 4 exit, 0x10 players gone */
extern f32 D_80108468_1F71A8_MechaMarathon; /* the track's scroll */
extern s16 D_8010846C_1F71AC_MechaMarathon; /* timer */
extern s16 D_8010846E_1F71AE_MechaMarathon;
extern s16 D_80108470_1F71B0_MechaMarathon; /* robots still going */
extern u8 D_80108472_1F71B2_MechaMarathon[3];
extern s16 D_80108476_1F71B6_MechaMarathon; /* winner */
extern u8 D_80108478_1F71B8_MechaMarathon;  /* the robots run */
extern s16 D_80108480_1F71C0_MechaMarathon[4]; /* score digits */
extern u16 D_80108494_1F71D4_MechaMarathon;    /* record; D_80108495_1F71D5_MechaMarathon is its low byte */
extern u16 D_80108496_1F71D6_MechaMarathon;    /* score */
extern s16 D_80108498_1F71D8_MechaMarathon[4]; /* robot sounds */
extern u8 D_801084A0_1F71E0_MechaMarathon[4][2]; /* host's reaction, 0-1 */
extern u16 D_801084A8_1F71E8_MechaMarathon[4][20]; /* buttons in the window */
extern MMCpu D_80108548_1F7288_MechaMarathon[4];
extern void* D_80108578_1F72B8_MechaMarathon[2];
extern s16 D_80108580_1F72C0_MechaMarathon;
extern MMRobot D_80108588_1F72C8_MechaMarathon[4];
extern MMActor D_801085F0_1F7330_MechaMarathon[50];
extern u16 D_80108610_1F7350_MechaMarathon; /* [0].state, by its own label in retail */
extern f32 D_80108748_1F7488_MechaMarathon; /* [4].unk_38 */
extern u16 D_80108850_1F7590_MechaMarathon; /* [8].state */
extern u16 D_80108852_1F7592_MechaMarathon; /* [8].unk_22 */
extern u16 D_80108854_1F7594_MechaMarathon; /* [8].unk_24 */
/* Fields of D_801085F0_1F7330_MechaMarathon[5], addressed by their own labels in retail: */
extern f32 D_80108790_1F74D0_MechaMarathon; /* [5].unk_38 */
extern f32 D_80108794_1F74D4_MechaMarathon; /* [5].unk_3C */
extern f32 D_80108798_1F74D8_MechaMarathon; /* [5].unk_40 */
extern f32 D_8010879C_1F74DC_MechaMarathon; /* [5].unk_44 */
extern s16 D_80109400_1F8140_MechaMarathon[50];

/* ---- functions ---- */

void func_80102800_1F1540_MechaMarathon(void);
u8 func_8010281C_1F155C_MechaMarathon(u8 n, u64* used);
void func_8010296C_1F16AC_MechaMarathon(s16 sfx, s16 i);
void func_801029E8_1F1728_MechaMarathon(void);
void func_80102D60_1F1AA0_MechaMarathon(omObjData* obj);
void func_801032B8_1F1FF8_MechaMarathon(omObjData* obj);
void func_801036D8_1F2418_MechaMarathon(void);
void func_80103714_1F2454_MechaMarathon(omObjData* obj);
void func_8010384C_1F258C_MechaMarathon(omObjData* obj);
void func_80103BEC_1F292C_MechaMarathon(void);
void func_80103C28_1F2968_MechaMarathon(s32 i);
void func_80103CA8_1F29E8_MechaMarathon(omObjData* obj, u16 mot, s16 start, s16 speed, s16 flags);
void func_80103D34_1F2A74_MechaMarathon(omObjData* obj);
void func_80104104_1F2E44_MechaMarathon(omObjData* obj);
void func_8010489C_1F35DC_MechaMarathon(omObjData* obj);
void func_80104BE0_1F3920_MechaMarathon(void);
void func_80104D08_1F3A48_MechaMarathon(omObjData* obj, u8 k);
void func_80104DC8_1F3B08_MechaMarathon(omObjData* obj);
void func_801052C0_1F4000_MechaMarathon(omObjData* obj);
void func_80105708_1F4448_MechaMarathon(s16 i);
void func_80105754_1F4494_MechaMarathon(omObjData* obj, s16 i);
void func_801057B0_1F44F0_MechaMarathon(omObjData* obj);
void func_801068A8_1F55E8_MechaMarathon(omObjData* obj);
void func_80106CF4_1F5A34_MechaMarathon(void);
void func_80106DC0_1F5B00_MechaMarathon(omObjData* obj);
void func_801070DC_1F5E1C_MechaMarathon(omObjData* obj);
void func_80107524_1F6264_MechaMarathon(void);
void func_80107644_1F6384_MechaMarathon(omObjData* obj);
void func_801076A4_1F63E4_MechaMarathon(omObjData* obj);
void func_80107730_1F6470_MechaMarathon(omObjData* obj);
void func_80107770_1F64B0_MechaMarathon(omObjData* obj);
void func_801077E4_1F6524_MechaMarathon(omObjData* obj);
void func_80107808_1F6548_MechaMarathon(omObjData* obj);
void func_8010789C_1F65DC_MechaMarathon(omObjData* obj);
void func_801078F4_1F6634_MechaMarathon(omObjData* obj);
void func_80107C1C_1F695C_MechaMarathon(omObjData* obj);
void func_80107D0C_1F6A4C_MechaMarathon(void);
void func_80107F60_1F6CA0_MechaMarathon(void);
void func_80107FE4_1F6D24_MechaMarathon(void);

#endif
