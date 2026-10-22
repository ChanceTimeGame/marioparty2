#ifndef _OVL_46_H
#define _OVL_46_H

/* Overlay 46 (2F1730.c): board 45's duel scene, 42's flow (ovl_42.h) with a timing game: a target
   of 2-5 seconds is shown, each duelist presses A once and the press nearer the target wins
   (D_80108230: 1 draw, 2 challenger, 3 opponent). The result is left for the board in D_800FC880
   (winner) and D_800F8C5C (loser), -1 both for a draw.
   The unit's .rodata is carved ([0x2F6FB0, .rodata, 2F1730]: the flow's first local initialiser);
   leftovers are defined raw in C by tools/mp2rodefs.py beside their first user. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/malloc.h"
#include "game/camera.h"
#include "game/gamemes.h"
#include "game/hmfman.h"
#include "game/data.h"

/* ---- main-segment API ---- */

#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

/* A path the model walks (func_8005A718_5B318 in 58080); same as ovl_3F.h's. */
typedef struct ModelPathWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 index;
    /* 0x08 */ f32 speed;
    /* 0x0C */ Vec* points;
} ModelPathWork; /* size 0x10 */

extern u16 ContBtn[];
extern u16 ContDStkTrg[];
extern u16 D_801011FC_101DFC;
extern u16 D_800F8FE0_F9BE0;
extern u16 D_800FC87A_FD47A;
extern s16 D_800FA604_FB204;
extern s16 D_800FA606_FB206;
extern BattleTargets D_800F8D1A_F991A;
extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
extern BoardStatus D_80101510_102110[];
extern Vec2f D_800FC990_FD590[];
extern Vec2f D_800FD854_FE454[];
extern s8 D_80102708_103308;
/* The duel's result for the board: the winner and the loser (-1 both for a draw). */
extern s32 D_800FC880_FD480;
extern s32 D_800F8C5C_F985C;

s32 BoardSpaceGet(s32 index, s32 count);
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
f32 __sinf(f32);
f32 __cosf(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
void MBDBackKill(void);
void MBModelDispOff(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerModelCreate(s16, void*, s32);
void MBVsSprCreateY(f32 arg0, f32 arg1);
void MBVsSprKill(void);
s32 PlaySound(s32);
void AdjustPlayerCoins(s32 index, s32 count);
GW_PLAYER* BoardPlayerGet(s32);
void espDispOff(u16);
void espDispOn(u16);
void ShowTextWindow(s32 arg0);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A96C_1B56C(u16, u8, u8, u8); /* sprite colour */
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
void func_80029FE4_2ABE4(s16, f32);
f32 func_80042BE0_437E0(Vec*); /* y angle of a rotation */
void func_80043DAC_449AC(MBModel*);
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_8005762C_5822C(s32 arg0); /* close a window that waited for a press */
void func_80057730_58330(s16, s32);
void func_80057A78_58678(s32, s32, s32); /* both duelists' portraits in a window */
void func_800581A0_58DA0(void);
void func_80059120_59D20(void*, f32, f32); /* jump: velocity, gravity */
void func_80059158_59D58(void*); /* start the jump */
void func_800593C0_59FC0(void);
void func_80059400_5A000(void);
s32 func_8005A7E8_5B3E8(MBModel* model, Vec* target, f32 step); /* turn toward; TRUE when facing */
s32 func_80059FD0_5ABD0(s32 player); /* the player's rank, 0 = first */
ModelPathWork* func_8005A718_5B318(MBModel* model, f32 speed, s16 count, Vec* points);
s32 func_8005A778_5B378(ModelPathWork*); /* path finished */
void func_8005AA48_5B648(MBModel*, char*, s16);
void func_8005AC6C_5B86C(MBModel*, s32);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_8005ACD0_5B8D0(GW_PLAYER*, s16);
void func_8005E2B8_5EEB8(void);
void func_8005FE10_60A10(void);
void func_80060034_60C34(u32, s32);
void func_800600F8_60CF8(s32, s16, s16);
void func_8006135C_61F5C(s32 player, s32 coins, s32);
void func_800614B4_620B4(s32, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_800695D8_6A1D8(s16 mesId, s16 time);
s32 func_80069538_6A138(void);
s32 func_800696E4_6A2E4(void);
void func_80069764_6A364(s16 time);
void func_80069770_6A370(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
/* Defined (u32, s16, s16) in 73BA0.c; retail passes full words here. */
omObjData* func_800732FC_73EFC(u32 arg0, s32 arg1, s32 arg2);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32, s16);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800799A4_7A5A4(s16, s32);
void func_80088640_89240(void);
/* s16 in 58080.c; retail re-extends the result here, as if it were an int. */
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s32); /* window message argument */
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16);
void func_8008CCA8_8D8A8(s16);
void func_8008D88C_8E48C(s16);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
u32 func_800A5610_A6210(char*); /* strlen */
omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
int sprintf(char* dst, const char* fmt, ...);

/* ---- work types (42's) ---- */

/* Status-window layouts (D_80107DD0): four slots as from/to positions, and the frames the move
   takes (ovl_3F.h's Unk3FStatusLayout). */
typedef struct PdStatusLayout {
    /* 0x00 */ s16 pos[4][4]; /* x0, y0, x1, y1; -1 keeps the current value */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 frames;
} PdStatusLayout; /* size 0x24 */

/* func_80105368's shrinking-hat object (ovl_3F.h's Unk3FShrink). */
typedef struct PdShrink {
    /* 0x00 */ s32 timer;
    /* 0x04 */ f32 scaleSpeed;
    /* 0x08 */ f32 rotSpeed;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
} PdShrink; /* size 0x14 */

/* ---- more main-segment API ---- */

extern u16 ContBtnTrg[];
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_80042E44_43A44(Vec* v, f32 angle); /* rotate v about y */
extern u8 D_800FDBE0_FE7E0; /* the frame buffer being drawn */
extern u8 D_800FDBCA_FE7CA; /* number of frame buffers */
s16 func_80027FA4_28BA4(u32, void*, u8);
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_8005AA98_5B698(s16);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y); /* sprite scale */
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y);
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_800794A8_7A0A8(s32);
void MBVecNormalize(Vec*);
void omSetTra(omObjData*, f32, f32, f32);

/* The CPU input script (func_8010675C/func_80106D8C; ovl_3F.h's Unk3FCpuInput): mode 0 presses
   Start, 2 moves the cursor to an opponent and presses A, 3 raises the stake to a target. */
typedef struct PdCpuInput {
    /* 0x00 */ s32 timer;
    /* 0x04 */ s32 cur;    /* the cursor row / the stake now */
    /* 0x08 */ s32 target; /* the row / the stake wanted */
    /* 0x0C */ s32 mode;
} PdCpuInput; /* size 0x10 */





/* Wait for the step flag (D_801081D0) / for the message to finish (3F's WAIT_STEP/WAIT_MESSAGE). */
#define PD_WAIT_STEP()                           \
    while (TRUE) {                               \
        if (D_801081D0_2F7100_name_46 != 0) { \
            break;                               \
        }                                        \
        HuPrcVSleep();                           \
    }

#define PD_WAIT_MESSAGE()                                                     \
    while (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {     \
        HuPrcVSleep();                                                        \
    }

/* ---- 46 data (asm/data/overlays/ovl_46_name/2F6D00.data.s) ---- */

extern PdStatusLayout D_80107DD0_2F6D00_name_46[8];
extern u32* D_80107F98_2F6EC8_name_46[6]; /* per character: motion list (count, files) */
extern s32 D_80107FB0_2F6EE0_name_46;
extern Vec D_80107FB4_2F6EE4_name_46; /* the referee's spot */
extern Vec D_80107FC0_2F6EF0_name_46[1];
extern Vec D_80107FCC_2F6EFC_name_46[3];
extern Vec D_80107FF0_2F6F20_name_46[1];
extern Vec D_80107FFC_2F6F2C_name_46[3];
extern Vec D_80108020_2F6F50_name_46[2]; /* the time panels */
extern Vec D_80108038_2F6F68_name_46[3]; /* the stands */
extern Vec D_8010805C_2F6F8C_name_46[3]; /* the buttons */

/* ---- 46 bss (asm/data/overlays/ovl_46_name/ovl_46_bss.bss.s) ---- */

extern s32 D_801081D0_2F7100_name_46; /* a step finished */
extern s32 D_801081D4_2F7104_name_46; /* the stake */
/* func_80104880's message: window x and y (stored as s32, read as s16), variant, id, the
   player it names. */
extern s32 D_801081D8_2F7108_name_46;
extern s32 D_801081DC_2F710C_name_46;
extern s32 D_801081E0_2F7110_name_46;
extern s32 D_801081E4_2F7114_name_46;
extern s32 D_801081E8_2F7118_name_46;
extern s32 D_801081EC_2F711C_name_46;
extern s32 D_801081F0_2F7120_name_46; /* the challenger */
extern s32 D_801081F4_2F7124_name_46; /* the opponent, -1 until chosen */
extern s32 D_801081F8_2F7128_name_46[4]; /* players in the scene */
extern s32 D_80108208_2F7138_name_46; /* how many */
extern s32 D_80108210_2F7140_name_46[4]; /* opponents to choose from */
extern s32 D_80108220_2F7150_name_46; /* the minimum stake */
extern s32 D_80108224_2F7154_name_46; /* the turn */
extern s32 D_80108234_2F7164_name_46; /* the poorer player's coins */
extern s32 D_80108240_2F7170_name_46[2]; /* cleared by the setup, otherwise unused */
extern s32 D_80108248_2F7178_name_46; /* CPU pad triggers */
extern s32 D_8010826C_2F719C_name_46; /* no referee (flag 0x17 clear) */
extern s32 D_80108298_2F71C8_name_46; /* a number shown by message variant 4 */
extern MBModel* D_80108278_2F71A8_name_46; /* the referee's hat (scaled away) */

/* ---- 46 (D46) ---- */

s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void* data);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 group, s16 member, s32 flag);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3); /* sprite frame */
s32 func_8007975C_7A35C(s16 arg0, s16 arg1);
void func_80079848_7A448(s16 arg0);
void func_80069654_6A254(s16 mesId);
#include "process.h"
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029A8C_2A68C(s16 arg0);
void func_8002A00C_2AC0C(s16 arg0);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_80029E80_2AA80(s16 arg0, s32 arg1, s32 arg2);
extern f32 D_800CA02C_CAC2C;

#define PD_ABS(x) ((x) < 0 ? -(x) : (x))

/* func_80107850's blast (func_80107978): the loser's model grows, then blows up. */
typedef struct Ovl46Blast {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 scale;
    /* 0x08 */ s32 frame;
    /* 0x0C */ s32 side;
    /* 0x10 */ f32 grow;
} Ovl46Blast; /* size 0x14 */

/* func_80107C44's bob (func_80107D00). */
typedef struct Ovl46Bob {
    /* 0x00 */ f32 vel;
    /* 0x04 */ f32 acc;
    /* 0x08 */ s32 side;
} Ovl46Bob; /* size 0x0C */

extern s32 D_80108228_2F7158_name_46[2]; /* each side's CPU press frame (D_8010822C is [1]) */
extern s32 D_8010822C_2F715C_name_46; /* the opponent's CPU press frame */
extern s32 D_80108230_2F7160_name_46; /* the outcome: 1 draw, 2 challenger wins, 3 opponent wins */
extern s32 D_80108238_2F7168_name_46[2]; /* each side's press frame, -1 until pressed */
extern s32 D_8010824C_2F717C_name_46; /* a model (stored as s32, read as s16) */
extern MBModel* D_80108250_2F7180_name_46[2];
extern MBModel* D_80108258_2F7188_name_46[2]; /* each side's stand (D_8010825C is [1]) */
extern MBModel* D_8010825C_2F718C_name_46;
extern MBModel* D_80108260_2F7190_name_46[2]; /* each side's button (D_80108264 is [1]) */
extern MBModel* D_80108264_2F7194_name_46;
extern s16 D_80108268_2F7198_name_46[2]; /* each side's time display */
extern s16 D_80108270_2F71A0_name_46;
extern MBModel* D_80108274_2F71A4_name_46; /* the referee */
extern s16 D_80108272_2F71A2_name_46;
extern s16 D_8010827C_2F71AC_name_46;
extern s16 D_8010827E_2F71AE_name_46[];
extern s16 D_80108288_2F71B8_name_46;
extern s16 D_8010828A_2F71BA_name_46;
extern s16 D_8010828C_2F71BC_name_46;

/* ---- 2F1730.c ---- */

void func_80102800_2F1730_name_46(void);
void func_801029F8_2F1928_name_46(void);
void func_80102C2C_2F1B5C_name_46(omObjData* obj);
void func_80102C80_2F1BB0_name_46(void);
void func_80102D0C_2F1C3C_name_46(void);
void func_80104880_2F37B0_name_46(void);
/* Returns the window id (an s16) as an int: its caller does not re-extend it. */
s32 func_80104C88_2F3BB8_name_46(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
u16 func_80104DF0_2F3D20_name_46(void); /* the duelists' pad triggers */
void func_80104EB0_2F3DE0_name_46(s32 layout);
void func_801051E8_2F4118_name_46(omObjData* obj);
void func_80105280_2F41B0_name_46(void);
void func_801052BC_2F41EC_name_46(omObjData* obj);
void func_80105314_2F4244_name_46(omObjData* obj);
void func_80105368_2F4298_name_46(void);
void func_801053F8_2F4328_name_46(omObjData* obj);
void func_80105488_2F43B8_name_46(void);
void func_80105754_2F4684_name_46(void);
void func_80105FD0_2F4F00_name_46(void);
void func_80106038_2F4F68_name_46(omObjData* obj);
s32 func_80106470_2F53A0_name_46(void);
void func_8010675C_2F568C_name_46(s32 cur, s32 target, s32 mode); /* CPU input script */
void func_80106D8C_2F5CBC_name_46(omObjData* obj);
s32 func_80106F2C_2F5E5C_name_46(void); /* CPU pad triggers (D_80108248) */
void func_80106F38_2F5E68_name_46(void);
void func_801070C8_2F5FF8_name_46(void);
s16 func_80107158_2F6088_name_46(s16 x, s16 y); /* a time display (6 sprites) */
void func_801073EC_2F631C_name_46(s16 group); /* hide a time display */
void func_80107448_2F6378_name_46(s16 group, f32 secs); /* show secs as d.dd */
void func_80107644_2F6574_name_46(s16 group, f32 scale);
void func_801076B4_2F65E4_name_46(void);
void func_80107850_2F6780_name_46(void);
void func_80107978_2F68A8_name_46(omObjData* obj);
void func_80107C44_2F6B74_name_46(s32 side);
void func_80107D00_2F6C30_name_46(omObjData* obj);

#endif
