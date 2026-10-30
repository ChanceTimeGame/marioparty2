#ifndef _OVL_17_H
#define _OVL_17_H

/* Overlay 17: Archerival. Written by the team that wrote Look Away (ovl_13): its object table,
   sprite table, entry and exit flow are the same code.
   Retail is two files: 181420.c (80102800-801072D8) and 185F00.c from 801072E0 (the two table
   clears; 2-nop text pad). .data (0x185FB0-0x186260) is 181420.c's; .rodata is carved from
   0x186260 (181420.c only).
   N64 offsets are in the comments; the structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* One entry of D_80107920_186540_Archerival[50] (cleared by func_801072E0_185F00_Archerival);
   Look Away's LAObj. */
typedef struct ARObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;       /* sprite group */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 state;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 timer;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 com;
    /* 0x2E */ u16 player;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} ARObj; /* size = 0x48 (N64) */

/* A CPU target candidate (D_801078C8_1864E8_Archerival[5], nearest first). */
typedef struct ARRank {
    /* 0x00 */ u16 dist;
    /* 0x02 */ u16 idx;
} ARRank; /* size = 0x4 */

/* A target's start position (D_80107390_185FB0_Archerival[6]). */
typedef struct ARPos {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
} ARPos; /* size = 0x6 */

/* One file of a character's table (D_801073EC_18600C_Archerival[6][9]); the second word is 0. */
typedef struct ARFile {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 unk_04;
} ARFile; /* size = 0x8 */

/* The node names of a character's bow and arrow (D_80107598_1861B8_Archerival[6]). */
typedef struct ARHook {
    /* 0x00 */ char* node[2];
} ARHook; /* size = 0x8 on N64 */

/* A coin dropped from a broken target (D_80107878_186498_Archerival[5]). */
typedef struct ARCoin {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ u16 delay;
    /* 0x0E */ u8 active;
    /* 0x0F */ char unk_0F;
} ARCoin; /* size = 0x10 */

/* ---- .data (181420.c, 0x185FB0-0x186260) ---- */
extern ARPos D_80107390_185FB0_Archerival[5]; /* target start positions */
extern f32 D_801073B0_185FD0_Archerival[6];   /* arrow offset in x, by character */
extern u8 D_801073C8_185FE8_Archerival[4];  /* CPU: % chance to prefer targets 1-3, by difficulty */
extern u8 D_801073CC_185FEC_Archerival[4];  /* CPU: % chance to prefer an unclaimed target */
extern u8 D_801073D0_185FF0_Archerival[4];  /* CPU: % chance to cancel that preference */
extern u8 D_801073D4_185FF4_Archerival[8];  /* 4 CPU % chance to dodge, by difficulty; 4 coins by target kind */
extern s32 D_801073DC_185FFC_Archerival;  /* camera set up */
extern f32 D_801073E0_186000_Archerival;  /* arrow (title prop) speed */
extern f32 D_801073E4_186004_Archerival;  /* its vertical speed */

extern ARFile D_801073EC_18600C_Archerival[][9]; /* rows 0-4; row 5 is D_80107554 (host: not contiguous) */
extern ARFile D_80107554_186174_Archerival[8];
extern s32 D_80107594_1861B4_Archerival;
extern f32 D_801073E8_186008_Archerival;
extern const char D_80107660_186280_Archerival[], D_80107674_186294_Archerival[], D_80107688_1862A8_Archerival[],
    D_8010769C_1862BC_Archerival[], D_801076B0_1862D0_Archerival[], D_801076C4_1862E4_Archerival[],
    D_801076DC_1862FC_Archerival[], D_801076F0_186310_Archerival[], D_8010770C_18632C_Archerival[],
    D_80107720_186340_Archerival[], D_80107734_186354_Archerival[], D_80107744_186364_Archerival[],
    D_80107754_186374_Archerival[], D_80107760_186380_Archerival[], D_8010776C_18638C_Archerival[],
    D_80107778_186398_Archerival[], D_80107784_1863A4_Archerival[], D_80107790_1863B0_Archerival[]; /* [0-4] motions, [5-6] bow and arrow models, [7-8] win and lose motions */
extern ARHook D_80107598_1861B8_Archerival[6];   /* bow and arrow: the model's node */
extern ARHook D_801075C8_1861E8_Archerival[6];   /* the node they hook to */
extern s16 D_801075F8_186218_Archerival[6];      /* character directory */
extern u16 D_80107604_186224_Archerival[4];      /* the three shared motion files */
extern char* D_8010760C_18622C_Archerival[6]; /* "c00Nl_0_DEF" by character */
extern s16 D_80107624_186244_Archerival;      /* footstep sound, -1 none */
extern s16 D_80107626_186246_Archerival;      /* walk motion state (func_80103D7C) */
extern u8 D_80107628_186248_Archerival;       /* CPU target (D_80107920 index), 0 none */
extern u8 D_80107629_186249_Archerival;       /* CPU feints left */
extern u8 D_8010762A_18624A_Archerival;       /* CPU feint: candidates (2-3 nearest) */
extern u8 D_8010762B_18624B_Archerival;       /* CPU feint: func_801037C4 used mask */
extern s32 D_8010762C_18624C_Archerival;      /* targets placed by func_801061F4 */
extern s16 D_80107630_186250_Archerival;      /* frames until the timer shows */

/* ---- .bss ---- */
extern s16 D_80107870_186490_Archerival;      /* footstep timer */
extern ARCoin D_80107878_186498_Archerival[5];
extern ARCoin D_801077B8_1863D8_Archerival[];    /* = &D_80107878[-12], indexed by slot */
extern ARRank D_801078C8_1864E8_Archerival[5];
extern u16 D_801078CA_1864EA_Archerival[];    /* = &D_801078C8[0].idx, read as [n * 2] */
extern u8 D_801078DC_1864FC_Archerival;       /* func_801037C4 used mask of the start positions */
extern u16 D_801078DE_1864FE_Archerival;      /* game state: 2 play, 3 over */
extern u16 D_801078E0_186500_Archerival;      /* result: 1 won, 2 lost */
extern s16 D_801078E2_186502_Archerival;      /* state timer; game time left */
extern s16 D_801078E4_186504_Archerival;      /* end delay */
extern u8 D_801078E6_186506_Archerival;       /* archer state (func_801040B0); 0-2 bow down */
extern u16 D_801078E8_186508_Archerival;      /* targets hit by the archer */
extern u8 D_801078EA_18650A_Archerival;       /* coins won */
extern u8 D_801078EB_18650B_Archerival;       /* coins dropped */
extern f32 D_801078EC_18650C_Archerival;      /* CPU aim offset in x */
extern u8 D_801078F0_186510_Archerival;
extern HuSprite_Unk84_Struct* D_801078F4_186514_Archerival; /* the banner image */
extern void* D_801078F8_186518_Archerival[3]; /* motion data */
extern s16 D_80107904_186524_Archerival;      /* the player model's current motion */
extern s16 D_80107906_186526_Archerival;      /* win voice delay */
extern ARObj D_80107920_186540_Archerival[50];
extern u16 D_8010794C_18656C_Archerival;         /* = D_80107920[0].com */
extern u16 D_8010794E_18656E_Archerival;         /* = D_80107920[0].player */
extern f32 D_80107958_186578_Archerival;         /* = D_80107920[0].unk_38 */
extern ARObj D_80107A40_186660_Archerival[];     /* = &D_80107920[4] */
extern omObjData* D_80107BA8_1867C8_Archerival;  /* = D_80107920[9].obj */
extern s16 D_80107BAC_1867CC_Archerival;         /* = D_80107920[9].spr */
extern omObjData* D_80107BF0_186810_Archerival;  /* = D_80107920[10].obj */
extern omObjData* D_80107C38_186858_Archerival;  /* = D_80107920[11].obj */
extern u16 D_80107C58_186878_Archerival;         /* = D_80107920[11].state */
extern omObjData* D_80107C80_1868A0_Archerival;  /* = D_80107920[12].obj: the coins, [12-16] */
extern s16 D_80108730_187350_Archerival[50];     /* sprite animations */
extern s16 D_80108732_187352_Archerival;         /* = D_80108730[1] */

/* ---- main ---- */
void func_80029B80_2A780(s16 mdl, s16 mot);
typedef struct ARCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C; /* its model file */
    /* 0x10 */ char unk_10[8];
} ARCharData; /* size = 0x18 */
extern ARCharData D_800CD438_CE038[];
u16 func_80018A30_19630(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_80023DAC_249AC(s16 model, char* part, s16 target, char* targetPart);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
void func_8003E808_3F408(s16 anim, f32 time);
void func_8002CDF0_2D9F0(s16 mdl, s32 r, s32 g, s32 b, s32 a);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8002C628_2D228(s16 mdl, s16 parent, char* hook);
void func_80029BF0_2A7F0(s16 mdl, s16 mot, s16 start, s16 speed, s16 flags);
void func_80029C74_2A874(s16 mdl, f32 time);
f32 func_80029CE4_2A8E4(s16 mdl);
f32 func_80029D0C_2A90C(s16 mdl);
s32 func_80029E14_2AA14(s16 mot);
f32 func_80029E3C_2AA3C(s16 mdl);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_80079848_7A448(s16 sound);
void func_8003E888_3F488(s16);
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern s16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void* SprAnimGet(s16 animIdx);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_80018F58_19B58(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800212A4_21EA4(s16 index);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_8002D4D0_2E0D0(s16 n);
s16 func_8003DF08_3EB08(void*);
void func_8003E888_3F488(s16);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80079518_7A118(s8 arg0);
void func_80079614_7A214(s16 time);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f64 func_800B80D0_B8CD0(f64); /* sin of degrees, in double */
f64 func_800B75D0_B81D0(f64); /* cos of degrees, in double */
f64 func_800B1820_B2420(f64); /* sqrt, in double */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osViBlack(u8 active);

/* ---- overlay functions ---- */

/* 181420.c */
void func_80102800_181420_Archerival(void);
void func_8010281C_18143C_Archerival(u8 player);
void func_801028A0_1814C0_Archerival(void);
void func_801029B8_1815D8_Archerival(void);
void func_801029C0_1815E0_Archerival(omObjData* obj);
void func_80102B78_181798_Archerival(void);
void func_80102BC0_1817E0_Archerival(Gfx** gfxp);
void func_80102EE4_181B04_Archerival(void);
void func_80102EEC_181B0C_Archerival(omObjData* obj);
void func_80102F64_181B84_Archerival(void);
f32 func_80102FA0_181BC0_Archerival(f32 x);
void func_801030F0_181D10_Archerival(Vec* from, Vec* to, Vec* out);
void func_80103458_182078_Archerival(omObjData* obj);
void func_80103660_182280_Archerival(omObjData* obj);
void func_801036C8_1822E8_Archerival(void);
void func_80103704_182324_Archerival(omObjData* obj, u8 motion);
u8 func_801037C4_1823E4_Archerival(u8 n, u8* used);
u8 func_801038B4_1824D4_Archerival(omObjData* obj);
s32 func_80103C1C_18283C_Archerival(omObjData* obj, ARObj* tbl /* unused */, s16* dx, u8* target);
void func_80103CF0_182910_Archerival(omObjData* obj, u16 mot, s16 start, s16 speed, s16 flags);
void func_80103D7C_18299C_Archerival(omObjData* obj, s16 dir, s16* state);
void func_801040B0_182CD0_Archerival(omObjData* obj);
void func_80104AEC_18370C_Archerival(omObjData* obj);
void func_8010506C_183C8C_Archerival(void);
void func_80105180_183DA0_Archerival(f32 x, f32 y, f32 z, u8 n);
void func_8010520C_183E2C_Archerival(omObjData* obj, ARObj* p, s16 dx);
s16 func_8010549C_1840BC_Archerival(omObjData* obj, ARObj* p, s16 dx);
void func_80105878_184498_Archerival(omObjData* obj, ARObj* p);
void func_80105C84_1848A4_Archerival(omObjData* obj, ARObj* p);
void func_80105DD0_1849F0_Archerival(omObjData* obj);
void func_80105E38_184A58_Archerival(omObjData* obj);
void func_80106064_184C84_Archerival(void);
void func_8010618C_184DAC_Archerival(omObjData* obj);
void func_801061F4_184E14_Archerival(omObjData* obj);
void func_801063FC_18501C_Archerival(void);
void func_801064BC_1850DC_Archerival(omObjData* obj);
void func_801066C0_1852E0_Archerival(omObjData* obj);
void func_8010687C_18549C_Archerival(void);
void func_8010691C_18553C_Archerival(omObjData* obj);
void func_8010697C_18559C_Archerival(omObjData* obj);
void func_80106A30_185650_Archerival(omObjData* obj);
void func_80106A70_185690_Archerival(omObjData* obj);
void func_80106AE4_185704_Archerival(void);
void func_80106BDC_1857FC_Archerival(omObjData* obj);
void func_80106C00_185820_Archerival(omObjData* obj);
void func_80106C80_1858A0_Archerival(omObjData* obj);
void func_80106CD8_1858F8_Archerival(omObjData* obj);
void func_80106FCC_185BEC_Archerival(omObjData* obj);
void func_801070A8_185CC8_Archerival(void);

/* 185F00.c */
void func_801072E0_185F00_Archerival(void);
void func_80107364_185F84_Archerival(void);

#endif
