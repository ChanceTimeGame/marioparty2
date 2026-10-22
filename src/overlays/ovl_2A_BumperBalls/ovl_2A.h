#ifndef _OVL_2A_H
#define _OVL_2A_H

/* Overlay 2A (2111A0.c): Bumper Balls, descended from MP1's ovl_1E_BumperBalls (191700.c for the
   game, 196300.c for the water mesh). .data stays asm; .rodata is carved
   ([0x218A40, .rodata, 2111A0]). */

#include "common.h"
#include "game/object.h"

/* ---- main-segment API used by 2A ---- */

omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void* DataRead(s32 dirAndFile);
void HuMemMemoryFreePerm(void*);
void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_80020718_21318(s16, void*, void*);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32); /* MP1 func_8005DB44: the object group's list */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8003DF08_3EB08(void*);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80029708_2A308(s32);
void func_8002E544_2F144(void);

extern s32 D_800F9D30_FA930[];
extern s32 D_800FA5B8_FB1B8;
extern u8 D_800FA656; /* minigame variant: 0 plays the music, 2 adds the rescue boats */
extern u8 D_800FD8AC[]; /* CPU difficulty when flag 0xC is set */

/* ---- overlay .bss ---- */

extern s16 D_8010A262_218C02_BumperBalls; /* _CheckFlag(0xC) */
extern s16 D_8010A268_218C08_BumperBalls;
extern s16 D_8010A26A_218C0A_BumperBalls;
extern s16 D_8010A26C_218C0C_BumperBalls;
extern s16 D_8010A26E_218C0E_BumperBalls; /* humans still on the island (MP1 D_800FCD1E) */
extern u16 D_8010A272_218C12_BumperBalls; /* D_800FA656 */
extern s16 D_8010A274_218C14_BumperBalls; /* music handle */
extern omObjData* D_8010A290_218C30_BumperBalls; /* the island */
extern omObjData** D_8010A29C_218C3C_BumperBalls; /* the balls */
extern omObjData** D_8010A2A0_218C40_BumperBalls; /* the boats */
extern u16 D_8010A564_218F04_BumperBalls;

/* ---- overlay functions (fork A: 80102800-80105FB0; fork B: 80106730 on) ---- */

void func_80102800_2111A0_BumperBalls(void);
void func_80102C5C_2115FC_BumperBalls(omObjData* arg0);
void func_80102CB0_211650_BumperBalls(omObjData* arg0);
void func_80102F98_211938_BumperBalls(omObjData* arg0);
void func_80103414_211DB4_BumperBalls(omObjData* arg0);
void func_80103430_211DD0_BumperBalls(omObjData* arg0);
void func_8010351C_211EBC_BumperBalls(omObjData* arg0);
void func_80103558_211EF8_BumperBalls(omObjData* arg0);
void func_80103574_211F14_BumperBalls(omObjData* arg0);
void func_80103590_211F30_BumperBalls(omObjData* arg0);
void func_801035AC_211F4C_BumperBalls(omObjData* arg0, s32 player);
void func_80103D68_212708_BumperBalls(omObjData* arg0);
void func_801046B8_213058_BumperBalls(omObjData* arg0);
void func_80104950_2132F0_BumperBalls(omObjData* arg0);
void func_80104B70_213510_BumperBalls(omObjData* arg0);
void func_80104E04_2137A4_BumperBalls(omObjData* arg0);
void func_8010515C_213AFC_BumperBalls(omObjData* arg0);
void func_80105244_213BE4_BumperBalls(omObjData* arg0);
void func_8010545C_213DFC_BumperBalls(omObjData* arg0);
void func_801054DC_213E7C_BumperBalls(omObjData* arg0);
void func_80105604_213FA4_BumperBalls(omObjData* arg0);
void func_80105690_214030_BumperBalls(omObjData* arg0);
void func_801056AC_21404C_BumperBalls(omObjData* arg0);
void func_801056C8_214068_BumperBalls(omObjData* arg0);
void func_801056E4_214084_BumperBalls(omObjData* arg0);
void func_80105700_2140A0_BumperBalls(omObjData* arg0, s32 player);
void func_80105948_2142E8_BumperBalls(omObjData* arg0);
void func_80105EBC_21485C_BumperBalls(omObjData* arg0);
void func_80105FB0_214950_BumperBalls(omObjData* arg0);
/* fork B (inferred from the asm and MP1's twins: check yours) */
void func_80106730_2150D0_BumperBalls(omObjData* arg0);
u16 func_801067D8_215178_BumperBalls(omObjData* arg0);
void func_80106AD8_215478_BumperBalls(f32 arg0, u16 arg1);
f32 func_80106C88_215628_BumperBalls(s16* arg0, void* arg1, f32 arg2, f32 arg3, f32 arg4);
u16 func_80106E94_215834_BumperBalls(omObjData* arg0);
s32 func_80106FCC_21596C_BumperBalls(s32 arg0, u16* arg1, void* arg2, void* arg3);
s32 func_80106FEC_21598C_BumperBalls(void* arg0, u16* arg1, void* arg2);
u16 func_80107204_215BA4_BumperBalls(void);
void func_80107254_215BF4_BumperBalls(omObjData* arg0);
u16 func_801076A0_216040_BumperBalls(omObjData* arg0);
u16 func_801076D4_216074_BumperBalls(omObjData* arg0, f32 arg1);
void func_80107868_216208_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_801078FC_21629C_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80107C3C_2165DC_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80107DD4_216774_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
void func_80108074_216A14_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY);
f32 func_80108384_216D24_BumperBalls(omObjData* arg0);
void func_80108410_216DB0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_801084C8_216E68_BumperBalls(omObjData* arg0);
void func_80108500_216EA0_BumperBalls(omObjData* arg0);
void func_8010851C_216EBC_BumperBalls(void);
void func_80108C70_217610_BumperBalls(void);
void func_80109868_218208_BumperBalls(void);
void func_80109D80_218720_BumperBalls(omObjData* arg0);

#endif
