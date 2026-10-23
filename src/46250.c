#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "game/board.h"
#include "game/object.h"
#include "game/camera.h"

GW_PLAYER* BoardPlayerGet(s32);
void func_80056754_57354(MBModel*);
ModelEmitterWork* func_80049ED4_4AAD4(Object*, s16);
void func_80049F90_4AB90(ModelEmitterWork*);
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
void func_8005670C_5730C(Vec*);


s32 func_80047E70_48A70(s32);


extern s8 D_800DF63C_E023C;

/* .data (0xCC890-0xCC8D0) */
s32 D_800CBC90_CC890[6] = { 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0001 }; /* dice-block model per unk_0A */
s32 D_800CBCA8_CC8A8[5] = { 0x000A0004, 0x000A0005, 0x000A0173, 0x000A0175, 0x000A0174 }; /* dice-block animation per unk_0A */
s16 D_800CBCBC_CC8BC = 10; /* unreferenced */
s16 D_800CBCBE_CC8BE = 6;  /* unreferenced */
s16 D_800CBCC0_CC8C0[4][2] = { { 0x6E, 0x40 }, { 0xD2, 0x40 }, { 0xA0, 0x40 }, { 0, 0 } };
void func_8003E52C_3F12C(s16, u8);
void func_8003E560_3F160(s16, u8); /* defined (s16, s32) in 3D6A0.c; retail passes a u8 here */

void func_8008221C_82E1C(s16, s16, f32);
void SprAnimSet(s16, s16, s16, u16);
s16 SprCreate(s32, s32);

extern f32 D_800CA02C_CAC2C;
void func_8002AC10_2B810(s16, f32, f32, s32);
void func_80047A50_48650(s32);

/* Board dice blocks and coin/dice processes (MP3 ovl_80_shared_board/EE660.c, MP1 src/3F5B0.c)
   and music fades (MP1 src/42CA0.c). Rodata D3110-D3220 carved. */

#define DICE_TOTAL 3

typedef struct UnkDiceRelated {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 predecidedRollValue[DICE_TOTAL]; // forced roll values, indexed by rollValueIdx
    /* 0x05 */ s8 rollValue[DICE_TOTAL]; // rolled values
    /* 0x08 */ s8 rollValueIdx; // current roll index (0-2)
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s16 sprites[DICE_TOTAL];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16; // model, -1 = none
    /* 0x18 */ s16 unk_18; // model, -1 = none
    /* 0x1A */ s16 unk_1A[6];
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk28; // sound, -1 = none
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ void* unk_30;
    /* 0x34 */ void* dice;
    /* 0x38 */ omObjData* unk_38;
    /* 0x3C */ omObjData* omObj;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
} UnkDiceRelated; /* size = 0x4C */

typedef struct UnkCoinProc {
    /* 0x00 */ s32 playerNo;
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[4];
} UnkCoinProc;

typedef struct DiceProcWork {
    /* 0x00 */ s32 player;
    /* 0x04 */ s32 state;
} DiceProcWork;

extern UnkDiceRelated D_800DF4C0_E00C0[5];
extern u8 D_800DF63D_E023D;
extern s8 D_800DF63E_E023E;
extern u8 D_800DF63F_E023F;
extern f32 D_800DF640_E0240;
extern u8 D_800DF644_E0244;
extern u8 D_800DF645_E0245;
extern u8 D_800DF646_E0246;
extern s16 D_800FC734_FD334;

void omDelObj(omObjData*);
s16 PlaySound(s32);
s16 func_80046F98_47B98(s32);
void func_80047978_48578(s32);
void func_800479E4_485E4(s32);
void func_8004947C_4A07C(void);
void func_80059158_59D58(void*);
void func_80047BB8_487B8(s32);
void func_80046CD8_478D8(s32);
void MBPlayerMotionSet(s32, s16, u16);
void func_80059120_59D20(void*, f32, f32);
void func_8005DDEC_5E9EC(s32, s16, s16, s16, u16);
void MBPlayerVibrate(s16, s16);
void SprScaleSet(s16, s16, f32, f32);
void MBDlgWinExec(s32, s32);
void func_8004CA34_4D634(s32, s32);
void func_800614B4_620B4(s32, s32);
void func_80079718_7A318(s32, s32);
void func_80079428_7A028(s32);
f32 HuMathSin(f32);
extern s16 D_800FA198_FAD98;
extern s16 D_800FA1A4_FADA4;
extern u16 ContBtnTrg[4];
s16 Hu3DModelCreate(void*, s32);
void func_80029EDC_2AADC(s16, s32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void HmfModelObjAttrSet(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_8002A00C_2AC0C(s16);
s16 func_8003DBE8_3E7E8(HmfData*, u16, s32, void*);
void func_800456BC_462BC(omObjData*);
extern u8 D_800DF647_E0247;
void SprPrioSet(s16, s16, u16);
void func_8008225C_82E5C(s16, s16, s32);
void func_800822A8_82EA8(s16, s16, u16, s32);
s16 func_80062CCC_638CC(void);
f32 func_80052E5C_53A5C(void);
void MBDCamera3Dto2D(Vec*, Vec2f*);
void func_80046308_46F08(s32);
void func_800495E4_4A1E4(s32, s32, s32, s32);
void func_80045B40_46740(omObjData*);
void func_80045F54_46B54(omObjData*);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void SprPosSet(s16, s16, s16, s16);
void func_800283DC_28FDC(s16);
void func_800298A4_2A4A4(s16, s32, s32);
void func_8003E964_3F564(s16);
MBModel* func_80043510_44110(s32, void*);
void MBModelKill(void*);
s32 MBRand(f32);
void func_800794F0_7A0F0(s8);
void func_80079848_7A448(s16);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_800B39F0_B45F0(f32*, f32);
s32 func_80046D2C_4792C(s32);
void SprKill(s16);
void SprAnimKill(s16);
void func_80047EC0_48AC0(void);
void func_80048860_49460(void);
void func_80048AA8_496A8(void);
void func_80048E80_49A80(void);
void func_800491F0_49DF0(void);
void func_80049090_49C90(void);
void func_80049760_4A360(void);
void func_80049800_4A400(void);

/* near MP3 func_800DAA40_EE660_shared_board (EE660.c) */
void func_80045650_46250(s32 arg0) {
    UnkDiceRelated* temp_s0;

    temp_s0 = &D_800DF4C0_E00C0[arg0];
    if ((temp_s0->unk28 == -1) && (((omObjData*)temp_s0->dice)->work[0] == 1)) {
        temp_s0->unk28 = PlaySound(0x314);
    }
}

/* Dice-block object (MP3 func_800DAAAC_EE6CC_shared_board): spin-in, hover, then the hit burst. */
void func_800456BC_462BC(omObjData* arg0) {
    UnkDiceRelated* entry;
    f32 base;
    f32 scale;
    f32 decay;
    s32 i;

    entry = &D_800DF4C0_E00C0[arg0->work[3]];
    if (D_800DF63D_E023D == 1) {
        base = 1.0f;
    } else {
        base = 0.1f;
    }

    switch (arg0->work[0]) {
        case 0:
            if (D_800FDC9C_FE89C != 0) {
                return;
            }
            arg0->trans.y = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.y + D_800DF640_E0240;
            scale = (HuMathSin(arg0->work[1] * 2) * entry->unk48 * base) + base;
            arg0->scale.x = arg0->scale.y = arg0->scale.z = scale;
            if (D_800DF647_E0247 == 0) {
                arg0->rot.y += 22.5f;
            } else {
                arg0->rot.y -= 22.5f;
            }
            arg0->work[1] += 25;
            arg0->work[1] %= 180;
            decay = entry->unk48 - 0.05;
            entry->unk48 = decay;
            if (decay <= 0.0f) {
                entry->unk48 = 0.0f;
                arg0->scale.x = arg0->scale.y = arg0->scale.z = base;
                arg0->work[1] = 0;
                arg0->work[0] = 1;
                if (D_800DF63D_E023D == 1) {
                    for (i = 0; i < 4; i++) {
                        if (D_800DF4C0_E00C0[i].unk28 != -1) {
                            break;
                        }
                    }
                    if (i == 4) {
                        if (GwSystem.current_board_index == 8) {
                            entry->unk28 = PlaySound(0x33E);
                        } else {
                            entry->unk28 = PlaySound(0x314);
                        }
                        return;
                    }
                    entry->unk28 = D_800DF4C0_E00C0[i].unk28;
                    return;
                }
                if (entry->unk2A == 0 && D_800DF63D_E023D != 3 && entry->unk_0A != 5 && D_800DF63D_E023D != 4 &&
                    D_800DF644_E0244 != 0) {
                    entry->unk28 = PlaySound(0x314);
                    return;
                }
            }
            break;
        case 1:
            if (D_800FDC9C_FE89C == 0) {
                arg0->trans.y = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.y + D_800DF640_E0240 +
                                (HuMathSin(arg0->work[1] * 2) * 10.0f * base);
                arg0->work[1] += 5;
                arg0->work[1] %= 180;
                return;
            }
            break;
        case 2:
            D_800CA02C_CAC2C = entry->unk48;
            HmfModelObjAttrSet(*arg0->model, 0x22000, 0x20000);
            func_8002AC10_2B810(*arg0->model, entry->unk40, entry->unk44, 2);
            if (D_800FDC9C_FE89C == 0) {
                entry->unk48 += 39.0f;
                entry->unk40 += 0.05f;
                entry->unk44 = ((10.0f - entry->unk44) / 30.0f) + entry->unk44;
                if (entry->unk40 > 1.0f) {
                    func_80047A50_48650(arg0->work[3]);
                }
            }
            break;
    }
}
/* Two-digit roll counter over a player (MP3 func_800DAF1C_EEB3C_shared_board). */
void func_80045B40_46740(omObjData* arg0) {
    UnkDiceRelated* entry;
    Vec pos;
    Vec2f pos2d;
    u32 roll;

    entry = &D_800DF4C0_E00C0[arg0->work[3]];
    if ((arg0->work[0] == 0) && (D_800FDC9C_FE89C == 0)) {
        arg0->scale.x = (HuMathSin(arg0->rot.x) * arg0->scale.z) + 1.0f;
        arg0->rot.x += 20.0f;
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x -= 360.0f;
        }
        arg0->scale.z -= 0.15;
        if (arg0->scale.z <= 0.0f) {
            arg0->scale.x = 1.0f;
            arg0->work[0] = 1;
        }
    }
    SprScaleSet(entry->sprites[arg0->work[1]], 0, arg0->scale.x / 2.0f, arg0->scale.x / 2.0f);
    SprScaleSet(entry->sprites[arg0->work[1]], 1, arg0->scale.x / 2.0f, arg0->scale.x / 2.0f);
    if (entry->unk_00 == 0) {
        roll = arg0->work[1];
        func_800822A8_82EA8(entry->sprites[roll], 0, entry->rollValue[roll] % 10, 0);
        func_8008225C_82E5C(entry->sprites[arg0->work[1]], 0, 1);
        roll = arg0->work[1];
        func_800822A8_82EA8(entry->sprites[roll], 1, entry->rollValue[roll] / 10, 0);
        func_8008225C_82E5C(entry->sprites[arg0->work[1]], 1, 1);
    }
    pos.x = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.x;
    pos.y = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.y + D_800DF640_E0240 + arg0->trans.y;
    pos.z = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.z;
    MBDCamera3Dto2D(&pos, &pos2d);
    SprPosSet(entry->sprites[arg0->work[1]], 0, pos2d.unk_00, pos2d.unk_04 - 8.0f);
    if ((pos2d.unk_00 >= 0.0f) && (pos2d.unk_00 <= 320.0f) && (pos2d.unk_04 >= 0.0f) && (pos2d.unk_04 <= 240.0f)) {
        func_800495E4_4A1E4(arg0->work[3], arg0->work[1], 160, 120 - (s32)(func_80052E5C_53A5C() * 24.0f));
    }
}
void func_80045F54_46B54(omObjData* arg0) {
    UnkDiceRelated* entry;
    Vec pos;
    Vec2f pos2d;
    s8 roll;

    entry = &D_800DF4C0_E00C0[arg0->work[3]];
    if ((arg0->work[0] == 0) && (D_800FDC9C_FE89C == 0)) {
        arg0->scale.x = (HuMathSin(arg0->rot.x) * arg0->scale.z) + 1.0f;
        arg0->rot.x += 20.0f;
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x -= 360.0f;
        }
        arg0->scale.z -= 0.05;
        if (arg0->scale.z <= 0.0f) {
            arg0->scale.x = 1.0f;
            arg0->work[0] = 1;
        }
    }
    SprScaleSet(entry->sprites[entry->rollValueIdx], 0, arg0->scale.x, arg0->scale.x);
    if (entry->unk_00 == 0) {
        roll = entry->rollValueIdx;
        func_800822A8_82EA8(entry->sprites[roll], 0, entry->rollValue[roll], 0);
        func_8008225C_82E5C(entry->sprites[entry->rollValueIdx], 0, 1);
    }
    pos.x = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.x;
    pos.y = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.y + D_800DF640_E0240 + arg0->trans.y;
    pos.z = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.z;
    MBDCamera3Dto2D(&pos, &pos2d);
    SprPosSet(entry->sprites[entry->rollValueIdx], 0, pos2d.unk_00, pos2d.unk_04);
}
/* exact c: marioparty3 func_800DB56C_EF18C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800461C8_46DC8(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < DICE_TOTAL; j++) {
            D_800DF4C0_E00C0[i].rollValue[j] = 0;
            D_800DF4C0_E00C0[i].predecidedRollValue[j] = 0;
        }
    }
    D_800DF646_E0246 = 0;
}

/* near MP3 func_800DB5DC_EF1FC_shared_board (EE660.c): MP2 also clears unk_00. */
void func_80046238_46E38(void) {
    UnkDiceRelated* entry;
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        entry = &D_800DF4C0_E00C0[i];

        for (j = 0; j < DICE_TOTAL; j++) {
            entry->sprites[j] = -1;
            entry->predecidedRollValue[j] = 0;
        }

        entry->rollValueIdx = 0;
        entry->unk_16 = -1;
        entry->unk_18 = -1;
        entry->unk_30 = NULL;
        entry->unk_26 = -1;
        entry->unk_14 = -1;
        entry->unk_0C = 0;
        entry->dice = NULL;
        entry->unk_38 = NULL;
        entry->omObj = NULL;
        entry->unk_0B = 0;
        entry->unk_00 = 0;
        entry->unk28 = -1;
        entry->unk2A = 0;
        entry->unk_09 = -1;
    }

    D_800DF63D_E023D = 0;
    D_800DF63E_E023E = 1;
    D_800DF640_E0240 = 25.0f;
    D_800DF644_E0244 = 1;
    D_800DF645_E0245 = 1;
}

/* Creates the dice-roll counter sprite (MP3 func_800DB6A8_EF2C8_shared_board); unk_00 != 0 picks a
   special digit set from the table. */
void func_80046308_46F08(s32 arg0) {
    s32 ids[9] = { 0xA00DB, 0xA00DC, 0xA0199, 0xA0198, 0xA000B, 0xA000C, 0xA000D, 0xA00DD, 0xA00DC };
    UnkDiceRelated* entry;
    void* data;
    s32 i;

    entry = &D_800DF4C0_E00C0[arg0];
    if (entry->unk_00 != 0) {
        data = DataRead(ids[entry->unk_00 - 1]);
        entry->unk_14 = SprAnimRead(data);
        entry->unk_0C = 1;
        DataClose(data);
    } else if ((arg0 != 0) && (D_800DF4C0_E00C0[0].unk_14 != -1)) {
        entry->unk_14 = D_800DF4C0_E00C0[0].unk_14;
        D_800DF4C0_E00C0[0].unk_0C++;
    } else if ((entry->rollValueIdx == 0) || (D_800DF645_E0245 == 1)) {
        data = DataRead(0xA0008);
        entry->unk_14 = SprAnimRead(data);
        entry->unk_0C = 1;
        DataClose(data);
    }
    entry->sprites[entry->rollValueIdx] = SprCreate(2, 5);
    for (i = 0; i < 2; i++) {
        SprAnimSet(entry->sprites[entry->rollValueIdx], i, entry->unk_14, 0);
        SprPrioSet(entry->sprites[entry->rollValueIdx], i, 0x4000);
        SprAttrSet(entry->sprites[entry->rollValueIdx], i, 0x9000);
        func_8008221C_82E1C(entry->sprites[entry->rollValueIdx], i, 0.0f);
        SprScaleSet(entry->sprites[entry->rollValueIdx], i, 0.0f, 0.0f);
        if (entry->unk_00 == 0) {
            func_800822A8_82EA8(entry->sprites[entry->rollValueIdx], i, 0, 0);
        }
        func_8008225C_82E5C(entry->sprites[entry->rollValueIdx], i, 1);
    }
    entry->unk_0B = 1;
}
/* near MP3 func_800DB884_EF4A4_shared_board (EE660.c): MP2 also shows the block while unk_00 is
   set and follows the player's board model. */
void func_8004655C_4715C(s32 arg0) {
    UnkDiceRelated* entry;
    omObjData* obj;
    Vec pos;
    Vec2f pos2d;
    s8 roll;

    entry = &D_800DF4C0_E00C0[arg0];

    if (entry->rollValue[entry->rollValueIdx] != 0 || entry->unk_00 != 0) {
        if ((entry->dice == NULL) || (((omObjData*)entry->dice)->work[0] == 2)) {
            pos.x = ((MBModel*)gPlayers[arg0].unk_24)->pos.x;
            pos.y = ((MBModel*)gPlayers[arg0].unk_24)->pos.y + D_800DF640_E0240;
            pos.z = ((MBModel*)gPlayers[arg0].unk_24)->pos.z;
            MBDCamera3Dto2D(&pos, &pos2d);

            if (entry->sprites[entry->rollValueIdx] == -1) {
                func_80046308_46F08(arg0);
                entry->unk_0B = 0;
            } else {
                roll = entry->rollValueIdx;
                func_800822A8_82EA8(entry->sprites[roll], 0, entry->rollValue[roll], 0);
                SprPrioSet(entry->sprites[entry->rollValueIdx], 0, 0x4000);
                func_8008225C_82E5C(entry->sprites[entry->rollValueIdx], 0, 1);
            }

            if ((func_80062CCC_638CC() == 0) && (D_800DF63D_E023D == 0)) {
                func_800495E4_4A1E4(arg0, entry->rollValueIdx, pos2d.unk_00, pos2d.unk_04 - 8.0f);
            } else {
                SprPosSet(entry->sprites[entry->rollValueIdx], 0, pos2d.unk_00, pos2d.unk_04);
            }

            if ((pos2d.unk_00 >= 0.0f) && (pos2d.unk_00 <= 320.0f) &&
                (pos2d.unk_04 >= 0.0f) && (pos2d.unk_04 <= 240.0f)) {
                SprPosSet(entry->sprites[entry->rollValueIdx], 0, 160,
                          120 - (s32)(func_80052E5C_53A5C() * 24.0f));
            }

            SprAttrReset(entry->sprites[entry->rollValueIdx], 0, 0x8000);

            if (entry->omObj == NULL) {
                if ((func_80062CCC_638CC() == 0) && (D_800DF63D_E023D == 0)) {
                    obj = omAddObj(-0x8000, 0, 0, -1, func_80045B40_46740);
                    entry->omObj = obj;
                    obj->scale.z = 3.0f;
                    obj->work[1] = entry->rollValueIdx;
                } else {
                    obj = omAddObj(-0x8000, 0, 0, -1, func_80045F54_46B54);
                    entry->omObj = obj;
                    obj->scale.z = 1.0f;
                }
                obj->work[0] = 0;
                obj->work[3] = arg0;
                obj->scale.x = 0.0f;
                obj->rot.x = 270.0f;
                obj->trans.y = 0.0f;
            }
        }
    }
}

/* Rolls the dice block (MP3 func_800DBC2C_EF84C_shared_board). D_800DF63D picks the block: 1 rolls
   1-10 distinct from the other players' rolls, 2-5 are special blocks that set unk_00 (and
   unk_01); otherwise unk_0A decides (5: no roll). */
void func_80046918_47518(s32 arg0) {
    UnkDiceRelated* entry = &D_800DF4C0_E00C0[arg0];
    s32 i;

    if (entry->unk_0B == 0) {
        if (entry->rollValueIdx == 0) {
            func_80046D2C_4792C(arg0);
        }
    }
    entry->unk_0B = 0;
    if (D_800DF63D_E023D == 2) {
        entry->unk_00 = (rand8() % 3) + 1;
        if (entry->unk_00 != 1) {
            entry->unk_00 = 2;
        }
    } else if (D_800DF63D_E023D == 5) {
        entry->unk_00 = (rand8() % 3) + 8;
        if (entry->unk_00 != 9) {
            entry->unk_00 = 8;
        }
    } else if (D_800DF63D_E023D == 3) {
        if (entry->predecidedRollValue[entry->rollValueIdx] != 0) {
            entry->unk_01 = entry->unk_00 = entry->predecidedRollValue[entry->rollValueIdx];
            entry->predecidedRollValue[entry->rollValueIdx] = 0;
        } else {
            entry->unk_01 = entry->unk_00 = (rand8() % 6) + 3;
            if (entry->unk_00 != 3) {
                entry->unk_01 = entry->unk_00 = 4;
            }
        }
    } else if (D_800DF63D_E023D == 4) {
        entry->unk_01 = entry->unk_00 = (rand8() % 3) + 5;
    } else if (D_800DF63D_E023D == 1) {
        do {
            if (entry->predecidedRollValue[entry->rollValueIdx] != 0) {
                entry->rollValue[entry->rollValueIdx] = entry->predecidedRollValue[entry->rollValueIdx];
                entry->predecidedRollValue[entry->rollValueIdx] = 0;
            } else {
                entry->rollValue[entry->rollValueIdx] = (rand8() % 10) + 1;
            }
            for (i = 0; i < 5; i++) {
                if (i == arg0) {
                    continue;
                }
                if (D_800DF4C0_E00C0[i].rollValue[D_800DF4C0_E00C0[i].rollValueIdx] == entry->rollValue[entry->rollValueIdx]) {
                    break;
                }
            }
        } while (i != 5);
    } else {
        switch (entry->unk_0A) {
            case 0:
            case 1:
            case 2:
            case 4:
                if (entry->predecidedRollValue[entry->rollValueIdx] != 0) {
                    entry->rollValue[entry->rollValueIdx] = entry->predecidedRollValue[entry->rollValueIdx];
                    entry->predecidedRollValue[entry->rollValueIdx] = 0;
                } else {
                    entry->rollValue[entry->rollValueIdx] = (rand8() % 10) + 1;
                }
                break;
            case 3:
                entry->rollValue[entry->rollValueIdx] = (rand8() % 3) + 1;
                break;
            case 5:
                entry->rollValue[entry->rollValueIdx] = 0;
                break;
        }
    }
    func_8004655C_4715C(arg0);
}
/* exact c: marioparty3 func_800DBE6C_EFA8C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046CD8_478D8(s32 arg0) {
    UnkDiceRelated* dice = &D_800DF4C0_E00C0[arg0];

    if (dice->omObj != NULL) {
        omDelObj(dice->omObj);
        dice->omObj = NULL;
    }
}

/* near MP3 func_800DBEC0_EFAE0_shared_board (EE660.c): MP2 also clears unk_00. */
s32 func_80046D2C_4792C(s32 arg0) {
    s32 count = 0;
    UnkDiceRelated* entry = &D_800DF4C0_E00C0[arg0];
    s32 i;

    entry->unk_00 = 0;
    for (i = 0; i < DICE_TOTAL; i++) {
        if (entry->sprites[i] != -1) {
            count++;
            SprKill(entry->sprites[i]);
            entry->sprites[i] = -1;
        }
    }

    if (entry->unk_14 != -1) {
        if (entry->unk_0C != 0) {
            entry->unk_0C--;
            if (entry->unk_0C == 0) {
                SprAnimKill(entry->unk_14);
                entry->unk_14 = -1;
            }
        }
        count++;
    }

    if (entry->omObj != NULL) {
        omDelObj(entry->omObj);
        entry->omObj = NULL;
        count++;
    }

    return count;
}

/* exact c: marioparty3 func_800DBFBC_EFBDC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046E2C_47A2C(s32 arg0) {
    UnkDiceRelated* dice = &D_800DF4C0_E00C0[arg0];

    dice->rollValue[dice->rollValueIdx]--;
    if (dice->rollValue[dice->rollValueIdx] <= 0) {
        func_80046D2C_4792C(arg0);
    }
}

/* exact c: marioparty3 func_800DC024_EFC44_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046E94_47A94(s32 arg0) {
    if (D_800DF4C0_E00C0[arg0].unk_16 != -1) {
        func_800298A4_2A4A4(D_800DF4C0_E00C0[arg0].unk_16, 4, 4);
    }
}

/* exact c: marioparty3 func_800DC06C_EFC8C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046EDC_47ADC(s32 arg0) {
    D_800DF644_E0244 = 0;
    func_80046E94_47A94(arg0);
}

/* exact c: marioparty3 func_800DC08C_EFCAC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046EFC_47AFC(s32 arg0) {
    if (D_800DF644_E0244 != 0) {
        if (D_800DF4C0_E00C0[arg0].unk_16 != -1) {
            func_800298A4_2A4A4(D_800DF4C0_E00C0[arg0].unk_16, 4, 0);
        }
    }
}

/* exact c: marioparty3 func_800DC0E0_EFD00_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046F50_47B50(s32 arg0) {
    D_800DF644_E0244 = 1;
    func_80046EFC_47AFC(arg0);
}

/* exact c: marioparty3 func_800DE988_F25A8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046F74_47B74(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].unk_09 = arg1;
}

/* Creates the dice block over a player (MP3 func_800DC128_EFD48_shared_board); returns the sound
   started for a normal block, else -1. */
s16 func_80046F98_47B98(s32 arg0) {
    UnkDiceRelated* entry;
    omObjData* dice;
    f32 chance;
    s8 val;
    s32 rot;
    s32 tile;
    s32 i;
    s16 ret;

    D_800DF647_E0247 = 0;
    entry = &D_800DF4C0_E00C0[arg0];
    if (entry->unk_16 != -1) {
        return -1;
    }
    if (entry->rollValueIdx == 0) {
        func_80046D2C_4792C(arg0);
    }
    if (entry->unk_09 != -1) {
        entry->unk_0A = entry->unk_09;
        entry->unk_09 = -1;
    } else {
        entry->unk_0A = 0;
        if (_CheckFlag(3) != 0) {
            entry->unk_0A = 3;
            _ClearFlag(3);
        }
        if (D_800DF645_E0245 == 2) {
            entry->unk_0A = 2;
        } else if (D_800DF645_E0245 == 3) {
            entry->unk_0A = 4;
            if (entry->rollValueIdx == 0) {
                if (arg0 != 4) {
                    if (D_800DF646_E0246 != 0) {
                        chance = 6.0f;
                    } else {
                        chance = 30.0f;
                    }
                    if (MBRand(chance) == 0) {
                        val = (rand8() % 10) + 1;
                        entry->predecidedRollValue[1] = val;
                        entry->predecidedRollValue[0] = val;
                        D_800DF647_E0247 = 1;
                    }
                }
            }
        }
        if (_CheckFlag(4) != 0) {
            entry->unk_0A = 5;
        }
    }
    entry->unk_16 = Hu3DModelCreate(DataRead(D_800CBC90_CC890[entry->unk_0A]), 0x6A9);
    func_80029EDC_2AADC(entry->unk_16, 1);
    func_800297E8_2A3E8(entry->unk_16, 0.0f, 0.0f, 0.0f);
    HmfModelObjAttrSet(entry->unk_16, 0x20000, 0x20000);
    if (entry->unk_0A != 5) {
        entry->unk_2C = DataRead(D_800CBCA8_CC8A8[entry->unk_0A]);
        entry->unk_1A[0] = func_8003D8F0_3E4F0(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_2C, 0, "tile01_DEF");
        entry->unk_1A[1] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, "tile02_DEF");
        entry->unk_1A[2] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, "tile03_DEF");
        entry->unk_1A[3] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, "tile04_DEF");
        entry->unk_1A[4] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, "tile06_DEF");
        entry->unk_1A[5] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, "tile10_DEF");
        tile = rand8() % 10;
        rot = rand8() & 3;
        for (i = 0; i < 6; i++) {
            if (entry->unk_0A < 3) {
                if (entry->unk_0A >= 0) {
                    func_8003E52C_3F12C(entry->unk_1A[i], rot);
                }
            }
            func_8003E560_3F160(entry->unk_1A[i], tile);
        }
    } else {
        entry->unk_2C = NULL;
        for (i = 0; i < 6; i++) {
            entry->unk_1A[i] = -1;
        }
        func_80029E80_2AA80(entry->unk_16, 0, 2);
    }
    func_80029A8C_2A68C(entry->unk_16);
    func_8002A00C_2AC0C(entry->unk_16);
    dice = omAddObj(-0x8000, 1, 1, -1, func_800456BC_462BC);
    entry->dice = dice;
    *dice->model = entry->unk_16;
    omSetStatBit(dice, 0xA0);
    dice->trans.x = ((MBModel*)gPlayers[arg0].unk_24)->pos.x;
    dice->trans.y = ((MBModel*)gPlayers[arg0].unk_24)->pos.y + D_800DF640_E0240;
    dice->trans.z = ((MBModel*)gPlayers[arg0].unk_24)->pos.z;
    if (D_800DF647_E0247 == 0) {
        dice->rot.y = -90.0f;
    } else {
        dice->rot.y = 90.0f;
    }
    dice->scale.z = dice->scale.y = dice->scale.x = dice->rot.x = dice->rot.z = 0.0f;
    dice->work[0] = 0;
    dice->work[1] = 0x87;
    dice->work[2] = 0;
    dice->work[3] = arg0;
    entry->unk48 = 1.0f;
    entry->unk40 = 0.0f;
    entry->unk44 = 1.0f;
    D_800DF63D_E023D = 0;
    ret = -1;
    switch (entry->unk_0A) {
        case 0:
            if (D_800DF63D_E023D != 4) {
                ret = PlaySound(0x31A);
            } else {
                PlaySound(0x34B);
            }
            break;
        case 1:
            PlaySound(0x31A);
            break;
        case 2:
            PlaySound(0x357);
            break;
        case 3:
            PlaySound(0x31A);
            break;
        case 4:
            PlaySound(0x358);
            break;
        case 5:
            PlaySound(0x356);
            break;
        default:
            PlaySound(0x34B);
            break;
    }
    return ret;
}
/* near MP3 func_800DC718_F0338_shared_board (EE660.c) */
void func_80047580_48180(s32 arg0, s32 arg1, s32 arg2, void* arg3[]) {
    UnkDiceRelated* entry = &D_800DF4C0_E00C0[arg0];
    omObjData* dice;
    s32 i;

    if (entry->unk_16 == -1) {
        if (D_800DF63D_E023D == 1) {
            D_800DF640_E0240 = 250.0f;
        } else {
            D_800DF640_E0240 = 25.0f;
        }

        func_80046D2C_4792C(arg0);
        entry->unk_0A = 0;

        entry->unk_16 = Hu3DModelCreate(DataRead(arg1), 0x6A9);
        func_80029EDC_2AADC(entry->unk_16, 1);
        func_800297E8_2A3E8(entry->unk_16, 0.0f, 0.0f, 0.0f);
        HmfModelObjAttrSet(entry->unk_16, 0x20000, 0x20000);

        if (arg2 != -1) {
            entry->unk_2C = DataRead(arg2);
        } else {
            entry->unk_2C = NULL;
        }

        for (i = 0; i < 6; i++) {
            if (arg3[i] != 0) {
                if (i == 0) {
                    entry->unk_1A[0] = func_8003D8F0_3E4F0(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_2C, 0, arg3[0]);
                } else {
                    entry->unk_1A[1] = func_8003DBE8_3E7E8(D_800FC834_FD434[entry->unk_16].hmf, entry->unk_1A[0], 0, arg3[i]);
                }
            } else {
                entry->unk_1A[i] = -1;
            }
        }

        func_80029A8C_2A68C(entry->unk_16);
        func_8002A00C_2AC0C(entry->unk_16);
        D_800DF647_E0247 = 0;

        dice = omAddObj(-0x8000, 1, 1, -1, func_800456BC_462BC);
        entry->dice = dice;
        dice->model[0] = entry->unk_16;
        omSetStatBit(dice, 0xA0);
        dice->trans.x = ((MBModel*)gPlayers[arg0].unk_24)->pos.x;
        dice->trans.y = ((MBModel*)gPlayers[arg0].unk_24)->pos.y + D_800DF640_E0240;
        dice->trans.z = ((MBModel*)gPlayers[arg0].unk_24)->pos.z;
        dice->rot.y = -90.0f;
        dice->scale.z =
        dice->scale.y =
        dice->scale.x =
        dice->rot.x =
        dice->rot.z = 0.0f;
        dice->work[0] = 0;
        dice->work[1] = 0x87;
        dice->work[2] = 0;
        dice->work[3] = arg0;

        entry->unk48 = 1.0f;
        entry->unk40 = 0.0f;
        entry->unk44 = 1.0f;

        PlaySound(0x34B);
    }
}

/* MP1 func_80041048 (src/3F5B0.c) */
void func_80047868_48468(s32 idx, s32 kind) {
    void* names[6] = { "donkeyxi_DEF", "starxi_DEF", NULL, NULL, NULL, NULL };
    s32 files[2] = { 0xA00D8, 0xA00D9 };

    func_80047580_48180(idx, 0xA00D7, files[kind], names);
    D_800DF63D_E023D = 2;
    D_800DF63C_E023C = kind;
}
void func_80047908_48508(s32 idx) {
    void* names[6] = { "donkeyxi_DEF", "starxi_DEF", NULL, NULL, NULL, NULL };

    func_80047580_48180(idx, 0xA00D7, 0xA00DA, names);
    D_800DF63D_E023D = 5;
}
void func_80047978_48578(s32 arg0) {
    void* anims[6] = { NULL, NULL, NULL, NULL, NULL, NULL };

    func_80047580_48180(arg0, 0xA0193, -1, anims);
    D_800DF63D_E023D = 3;
}
void func_800479E4_485E4(s32 arg0) {
    void* anims[6] = { NULL, NULL, NULL, NULL, NULL, NULL };

    func_80047580_48180(arg0, 0xA0003, -1, anims);
    D_800DF63D_E023D = 4;
}
/* exact c: marioparty3 func_800DCA64_F0684_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047A50_48650(s32 arg0) {
    UnkDiceRelated *entry = &D_800DF4C0_E00C0[arg0];
    s16 id;
    s32 i;

    if (entry->unk_16 != -1) {
        func_800283DC_28FDC(entry->unk_16);
        for (i = 0; i < 6; i++) {
            if (entry->unk_1A[i] != -1) {
                func_8003E964_3F564(entry->unk_1A[i]);
            }
        }
        if (entry->unk_2C != NULL) {
            DataClose(entry->unk_2C);
        }
        omDelObj((omObjData*)entry->dice);
        entry->dice = NULL;
        entry->unk_16 = -1;
    }

    if (entry->unk_18 != -1) {
        func_800283DC_28FDC(entry->unk_18);
        entry->unk_18 = -1;
        if (entry->unk_38 != NULL) {
            omDelObj(entry->unk_38);
            entry->unk_38 = NULL;
        }
    }

    if (entry->unk_26 != -1) {
        func_8003E964_3F564(entry->unk_26);
        entry->unk_26 = -1;
    }

    if (entry->unk_30 != NULL) {
        DataClose(entry->unk_30);
        entry->unk_30 = NULL;
    }
}

/* exact c: marioparty3 func_800DCB8C_F07AC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047B78_48778(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_80047A50_48650(i);
        func_80046D2C_4792C(i);
    }
}

void func_80047BB8_487B8(s32 arg0) {
    UnkDiceRelated* entry;
    s32 count;
    s32 i;

    entry = &D_800DF4C0_E00C0[arg0];
    if (entry->unk_16 != -1) {
        ((omObjData*)entry->dice)->work[0] = 2;
        if (D_800DF63D_E023D != 4) {
            func_80046918_47518(arg0);
        }
        if (D_800DF63D_E023D == 1) {
            count = 0;
            for (i = 0; i < 4; i++) {
                if (D_800DF4C0_E00C0[i].unk28 != -1) {
                    count++;
                }
            }
        } else {
            count = 1;
        }
        if (count == 1) {
            func_80079848_7A448(entry->unk28);
        }
        entry->unk28 = -1;
        entry->unk2A = 0;
        switch (D_800DF63D_E023D) {
            case 3:
                if (func_80047E70_48A70(arg0) == 0) {
                    PlaySound(0xD);
                } else {
                    PlaySound(0xC);
                }
                break;
            case 2:
                break;
            case 4:
            case 5:
                PlaySound(0x342);
                break;
            default:
                if (entry->unk_0A == 5) {
                    PlaySound(0x342);
                } else {
                    PlaySound(0x31B);
                }
                break;
        }
    }
}
/* exact c: marioparty3 func_800DCCE0_F0900_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047D2C_4892C(void) {
    D_800DF63D_E023D = 1;
    D_800DF640_E0240 = 250.0f;
}

/* exact c: marioparty3 func_800DCD00_F0920_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
s32 func_80047D4C_4894C(s32 arg0) {
    if (~D_800DF4C0_E00C0[arg0].unk_16) {
        return 1;
    } else {
        return 0;
    }
}

/* exact c: marioparty3 func_800DCD64_F0984_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047D78_48978(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].rollValue[D_800DF4C0_E00C0[arg0].rollValueIdx] = arg1;
}

/* exact c: marioparty3 func_800DCD64_F0984_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047DB0_489B0(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].predecidedRollValue[D_800DF4C0_E00C0[arg0].rollValueIdx] = arg1;
}

/* exact c: marioparty3 func_800DCD9C_F09BC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
s32 func_80047DE8_489E8(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].rollValue[D_800DF4C0_E00C0[arg0].rollValueIdx];
}

/* near MP3 func_800DE988_F25A8_shared_board (EE660.c): a state byte, offset */
s32 func_80047E20_48A20(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].unk_00 - 1;
}

/* near MP3 func_800DE988_F25A8_shared_board (EE660.c): a state byte, offset */
s32 func_80047E48_48A48(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].unk_00 - 8;
}

/* near MP3 func_800DE988_F25A8_shared_board (EE660.c): a state byte, offset */
s32 func_80047E70_48A70(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].unk_01 - 3;
}

/* near MP3 func_800DE988_F25A8_shared_board (EE660.c): a state byte, offset */
s32 func_80047E98_48A98(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].unk_01 - 5;
}

/* near MP3 func_800DCDD4_F09F4_shared_board (EE660.c): the dice block process. MP2 pays out
   through its own coin and message calls and checks flag 4 rather than board flag 0x11. */
void func_80047EC0_48AC0(void) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f20_10;
    f32 temp_f22;
    f32 temp_f24;
    s32 temp_s0;
    s32 var_s1;
    s32 var_s5;
    s32 i, j;
    DiceProcWork* temp_s3;
    UnkDiceRelated* temp_s4;

    var_s1 = 0;
    temp_s3 = HuPrcCurrentGet()->user_data;
    temp_s4 = &D_800DF4C0_E00C0[temp_s3->player];
    var_s5 = 0;
    while (1) {
        switch (temp_s3->state) {
            case 0:
                D_800DF63E_E023E = 0;
                func_80046F98_47B98(temp_s3->player);
                D_800DF63E_E023E = 1;
                temp_s3->state++;
                HuPrcSleep(0x14);
                break;
            case 1:
                if (((gPlayers[temp_s3->player].flags & 1) || (ContBtnTrg[gPlayers[temp_s3->player].port] & 0x8000)) &&
                    !(D_800FC834_FD434[D_800DF4C0_E00C0[temp_s3->player].unk_16].unk18 & 4) && (_CheckFlag(4) == 0)) {
                    temp_s3->state++;
                    MBPlayerMotionSet(temp_s3->player, 2, 0);
                    func_80059120_59D20(gPlayers[temp_s3->player].unk_24, 2.0f, -0.3f);
                    D_800FA198_FAD98 = 0;
                    D_800FA1A4_FADA4 = 0;
                }
                break;
            case 2:
                if (++var_s1 >= 5) {
                    func_80047BB8_487B8(temp_s3->player);
                    func_8005DDEC_5E9EC(temp_s3->player, -1, 0, 0xA, 2);
                    temp_s3->state++;
                }
                break;
            case 3:
                HuPrcSleep(20);
                var_s5++;
                if (var_s5 != D_800DF645_E0245) {
                    HuPrcSleep(10);
                    var_s1 = 0;
                    func_80046CD8_478D8(temp_s3->player);
                    {
                        s16* temp0 = &D_800CBCC0_CC8C0[var_s5 - 1][0];
                        s16* temp1 = &D_800CBCC0_CC8C0[var_s5 - 1][1];
                        func_800495E4_4A1E4(temp_s3->player, temp_s4->rollValueIdx, *temp0, *temp1);
                    }
                    temp_s4->rollValueIdx++;
                    temp_s3->state = 0;
                } else {
                    if (D_800DF645_E0245 != 1) {
                        HuPrcSleep(10);
                        func_80046CD8_478D8(temp_s3->player);
                        {
                            s16* temp0 = &D_800CBCC0_CC8C0[var_s5 - 1][0];
                            s16* temp1 = &D_800CBCC0_CC8C0[var_s5 - 1][1];
                            func_800495E4_4A1E4(temp_s3->player, temp_s4->rollValueIdx, *temp0, *temp1);
                        }
                        HuPrcSleep(20);
                        if (D_800DF645_E0245 == 2) {
                            if (temp_s4->rollValue[0] != temp_s4->rollValue[1]) {
                            } else {
                                PlaySound(0x378);
                                if (temp_s4->rollValue[0] == 7) {
                                    MBPlayerVibrate(-1, 3);
                                } else {
                                    MBPlayerVibrate(-1, 2);
                                }
                                for (j = 0; j < 37; j++) {
                                    temp_f22 = (f32)(((j * 4) + j) * 4);
                                    temp_f20 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    SprScaleSet(temp_s4->sprites[0], 0, temp_f20, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    temp_f20_2 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    SprScaleSet(temp_s4->sprites[1], 0, temp_f20_2, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    if (temp_s4->rollValue[0] == 0xA) {
                                        temp_f20_3 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        SprScaleSet(temp_s4->sprites[0], 1, temp_f20_3, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                        temp_f20_4 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        SprScaleSet(temp_s4->sprites[1], 1, temp_f20_4, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    }
                                    HuPrcVSleep();
                                }
                                PlaySound(0x11F);
                                if (temp_s4->rollValue[0] == 7) {
                                    MBDlgWinExec(3, 0x232);
                                    func_8004CA34_4D634(temp_s3->player, 20);
                                    func_800614B4_620B4(temp_s3->player, 20);
                                } else {
                                    MBDlgWinExec(3, 0x234);
                                    func_8004CA34_4D634(temp_s3->player, 10);
                                    func_800614B4_620B4(temp_s3->player, 10);
                                }
                                func_80079718_7A318(0x103, gPlayers[temp_s3->player].character);
                                MBPlayerMotionSet(temp_s3->player, 5, 0);
                                HuPrcSleep(0x1E);
                                MBPlayerMotionSet(temp_s3->player, -1, 2);
                            }
                        } else {
                            if (D_800DF645_E0245 == 3) {
                                if ((temp_s3->player != 4) && (temp_s4->rollValue[0] == temp_s4->rollValue[1]) &&
                                    (temp_s4->rollValue[0] == temp_s4->rollValue[2])) {
                                    if (temp_s4->rollValue[0] == 7) {
                                        D_800FC734_FD334 = 0;
                                        func_80079428_7A028(0x60);
                                        MBPlayerVibrate(-1, 4);
                                    } else {
                                        PlaySound(0x378);
                                        MBPlayerVibrate(-1, 3);
                                    }
                                    for (i = 0; i < 73; i++, HuPrcVSleep()) {
                                        var_s1 = i;
                                        temp_s0 = (i * 4) + var_s1;
                                        temp_f24 = (f32)(temp_s0 * 4);
                                        temp_f20_5 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        SprScaleSet(temp_s4->sprites[0], 0, temp_f20_5, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_6 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        SprScaleSet(temp_s4->sprites[1], 0, temp_f20_6, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_7 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        SprScaleSet(temp_s4->sprites[2], 0, temp_f20_7, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        if (temp_s4->rollValue[0] == 0xA) {
                                            temp_f20_8 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            SprScaleSet(temp_s4->sprites[0], 1, temp_f20_8, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_9 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            SprScaleSet(temp_s4->sprites[1], 1, temp_f20_9, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_10 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            SprScaleSet(temp_s4->sprites[2], 1, temp_f20_10, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        }
                                    }
                                    PlaySound(0x11F);
                                    if (temp_s4->rollValue[0] == 7) {
                                        MBDlgWinExec(3, 0x233);
                                        func_8004CA34_4D634(temp_s3->player, 50);
                                        func_800614B4_620B4(temp_s3->player, 50);
                                        D_800DF646_E0246 = 1;
                                    } else {
                                        MBDlgWinExec(3, 0x232);
                                        func_8004CA34_4D634(temp_s3->player, 20);
                                        func_800614B4_620B4(temp_s3->player, 20);
                                    }
                                    func_80079718_7A318(0x103, gPlayers[temp_s3->player].character);
                                    MBPlayerMotionSet(temp_s3->player, 5, 0);
                                    HuPrcSleep(0x1E);
                                    if (temp_s4->rollValue[0] == 7) {
                                        D_800FC734_FD334 = 1;
                                    }
                                    MBPlayerMotionSet(temp_s3->player, -1, 2);
                                }
                            }
                        }
                        for (var_s1 = 0; var_s1 < 50; HuPrcVSleep(), var_s1 += 2) {
                            func_800495E4_4A1E4(temp_s3->player, 0, D_800CBCC0_CC8C0[0][0] + var_s1, D_800CBCC0_CC8C0[0][1] + (var_s1 / 2));
                            func_800495E4_4A1E4(temp_s3->player, 1, D_800CBCC0_CC8C0[1][0] - var_s1, D_800CBCC0_CC8C0[1][1] + (var_s1 / 2));
                            if (D_800DF645_E0245 == 3) {
                                func_800495E4_4A1E4(temp_s3->player, 2, D_800CBCC0_CC8C0[2][0], D_800CBCC0_CC8C0[2][1] + (var_s1 / 2));
                            }
                        }
                        if (D_800DF645_E0245 == 2) {
                            PlaySound(0x368);
                        } else if (D_800DF645_E0245 == 3) {
                            PlaySound(0x346);
                        }
                        D_800DF645_E0245 = 1;
                        temp_s4->rollValueIdx = 0;
                        temp_s4->rollValue[0] += temp_s4->rollValue[1] + temp_s4->rollValue[2];
                        temp_s4->rollValue[2] = 0;
                        temp_s4->rollValue[1] = 0;
                        func_80046D2C_4792C(temp_s3->player);
                        func_8004655C_4715C(temp_s3->player);
                        HuPrcSleep(20);
                    }
                    omDelPrcObj(0);
                }
                break;
        }
        HuPrcVSleep();
    }
}

/* exact c: marioparty func_800419D8 (src/3F5B0.c) */
Process* func_80048800_49400(s32 player) {
    Process* process = omAddPrcObj(func_80047EC0_48AC0, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}

/* near MP1 func_80041A38 (src/3F5B0.c): the second dice block process. */
void func_80048860_49460(void) {
    DiceProcWork* work = HuPrcCurrentGet()->user_data;
    s32 timer = 0;

    while (TRUE) {
        switch (work->state) {
        case 0:
            D_800DF63E_E023E = 0;
            func_80047978_48578(work->player);
            D_800DF63E_E023E = 1;
            work->state++;
            HuPrcSleep(20);
            break;
        case 1:
            if ((gPlayers[work->player].flags & 1) || (ContBtnTrg[gPlayers[work->player].port] & 0x8000)) {
                work->state++;
                MBPlayerMotionSet(work->player, 2, 0);
                func_80059120_59D20(gPlayers[work->player].unk_24, 2.0f, -0.3f);
                D_800FA198_FAD98 = 0;
                D_800FA1A4_FADA4 = 0;
            }
            break;
        case 2:
            if (++timer >= 5) {
                func_80047BB8_487B8(work->player);
                func_8005DDEC_5E9EC(work->player, -1, 0, 10, 2);
                work->state++;
            }
            break;
        case 3:
            HuPrcSleep(5);
            HuPrcSleep(15);
            omDelPrcObj(NULL);
            break;
        }
        HuPrcVSleep();
    }
}

/* exact c: marioparty func_800419D8 (src/3F5B0.c) */
Process* func_80048A48_49648(s32 player) {
    Process* process = omAddPrcObj(func_80048860_49460, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}

void func_80048AA8_496A8(void) {
    Vec target;
    MBModel* parent;
    GW_PLAYER* player;
    MBModel* star;
    ModelEmitterWork* emitter;
    f32 scale;
    f32 rot;
    s32 i;

    parent = HuPrcCurrentGet()->user_data;
    player = BoardPlayerGet(-1);
    PlaySound(0x34C);
    star = func_80043510_44110(0x19, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    HuVecCopyXYZ(&star->pos, parent->pos.x, parent->pos.y + 10.0f, parent->pos.z - 10.0f);
    HuVecCopyXYZ(&target, D_800C9B80_CA780->pos.x, D_800C9B80_CA780->pos.y, D_800C9B80_CA780->pos.z);
    star->jumpY = 15.0f;
    emitter = func_80049ED4_4AAD4((Object*)star, 0);
    emitter->unk18 = 0.1f;
    for (scale = 0.0f, i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    func_8004947C_4A07C();
    while (1) {
        if (D_800DF63F_E023F != 0) {
            HuPrcVSleep();
        } else {
            break;
        }
    }
    PlaySound(0x32C);
    rot = 0.0f;
    HuVecCopyXYZ(&target, ((MBModel*)player->unk_24)->pos.x, ((MBModel*)player->unk_24)->pos.y - 10.0f,
                 ((MBModel*)player->unk_24)->pos.z);
    func_80056D80_57980(&star->pos, &target, &star->pos, 40);
    for (i = 0; i < 40; i++) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    MBModelKill(star);
    func_80049F90_4AB90(emitter);
    MBPlayerVibrate(-1, 5);
    func_80079428_7A028(0x5C);
    gPlayers[GwSystem.current_player_index].stars++;
    func_8005670C_5730C(&((MBModel*)player->unk_24)->rot);
    MBPlayerMotionSet(-1, 6, 0);
    func_80079718_7A318(0xF5, gPlayers[GwSystem.current_player_index].character);
    HuPrcSleep(60);
    omDelPrcObj(NULL);
}
/* exact c: marioparty3 func_800DDBC8_F17E8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80048E0C_49A0C(void* arg0) {
    Process* temp_v0;

    D_800FC734_FD334 = 0;
    temp_v0 = omAddPrcObj(func_80048AA8_496A8, 0x4800U, 0, 0);
    temp_v0->user_data = arg0;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

/* near MP3 func_800DDC3C_F185C_shared_board (EE660.c) */
void func_80048E80_49A80(void) {
    UnkCoinProc* work;
    s32 timer;

    work = HuPrcCurrentGet()->user_data;
    timer = 0;

    while (TRUE) {
        switch (work->state) {
            case 0:
                D_800DF63E_E023E = 0;
                func_800479E4_485E4(work->playerNo);
                D_800DF63E_E023E = 1;
                work->state++;
                HuPrcSleep(20);
                break;

            case 1:
                if (D_800DF63F_E023F == 0) {
                    work->state++;
                    MBPlayerMotionSet(work->playerNo, 2, 0);
                    func_80059120_59D20(gPlayers[work->playerNo].unk_24, 2.0f, -0.3f);
                    D_800FA198_FAD98 = 0;
                    D_800FA1A4_FADA4 = 0;
                }
                break;

            case 2:
                timer++;
                if (timer >= 5) {
                    func_80047BB8_487B8(work->playerNo);
                    func_8005DDEC_5E9EC(work->playerNo, -1, 0, 10, 2);
                    work->state++;
                }
                break;

            case 3:
                func_80048E0C_49A0C(gPlayers[work->playerNo].unk_24);
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

/* exact c: marioparty3 func_800DDDD4_F19F4_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
Process* func_80049028_49C28(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_80048E80_49A80, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_800DF63F_E023F = 0;
    return temp_v0;
}

/* same c: marioparty3 func_800DE48C_F20AC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80049090_49C90(void) {
    MBModel* temp_v0;
    MBModel* temp_s0;
    f32 var_f20;
    s32 i;
    
    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_v0 = func_80043510_44110(0x18, NULL);
    HuVecCopyXYZ(&temp_v0->pos, temp_s0->pos.x, 0.0f, temp_s0->pos.z);
    HuVecCopyXYZ(&temp_v0->scale, 2.0f, 2.0f, 2.0f);
    temp_v0->jumpY = 35.0f;
    var_f20 = (f32) MBRand(360.0f);

    for (i = 0; i < 5; i++) {
        HuPrcVSleep();
        temp_v0->jumpY += 3.0f;
        var_f20 += 40.0f;
        func_800B39F0_B45F0(D_800FC834_FD434[temp_v0->obj->model[0]].mtx, var_f20);
    }

    MBModelKill(temp_v0);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_800F8E80_DKsJungleAdventure (src/overlays/ovl_36_DKsJungleAdventure/2418D0.c) */
Process* func_800491B4_49DB4(void* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_80049090_49C90, 0x4800, 0, 0);
    proc->user_data = arg0;
    return proc;
}

/* near MP3 func_800DE5EC_F220C_shared_board (EE660.c) */
void func_800491F0_49DF0(void) {
    UnkCoinProc* work;
    s32 i;

    work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        switch (work->state) {
            case 0:
                D_800DF63E_E023E = 0;
                func_800479E4_485E4(work->playerNo);
                D_800DF63E_E023E = 1;
                work->state++;
                HuPrcSleep(20);
                break;

            case 1:
                if (D_800DF63F_E023F == 0) {
                    work->state++;
                    D_800FA198_FAD98 = 0;
                    D_800FA1A4_FADA4 = 0;
                }
                break;

            case 2:
                func_8004947C_4A07C();
                for (i = 0; i < 20; i++) {
                    MBPlayerMotionSet(work->playerNo, 2, 0);
                    func_80059120_59D20(gPlayers[work->playerNo].unk_24, 8.0f, -2.4f);
                    HuPrcSleep(2);
                    func_800491B4_49DB4(gPlayers[work->playerNo].unk_24);
                    func_800614B4_620B4(work->playerNo, 1);
                    if (i == 19) {
                        func_80047BB8_487B8(work->playerNo);
                    }
                    func_80059158_59D58(gPlayers[work->playerNo].unk_24);
                }
                func_80079718_7A318(0x103, gPlayers[work->playerNo].character);
                MBPlayerMotionSet(work->playerNo, 5, 0);
                work->state++;
                break;

            case 3:
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

/* exact c: marioparty3 func_800DDDD4_F19F4_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
Process* func_80049408_4A008(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800491F0_49DF0, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_800DF63F_E023F = 0;
    return temp_v0;
}

u8 func_80049470_4A070(void) {
    return D_800DF63F_E023F;
}
void func_8004947C_4A07C(void) {
    D_800DF63F_E023F = 1;
}
void func_8004948C_4A08C(void) {
    D_800DF63F_E023F = 0;
}
/* exact c: marioparty3 func_800DE874_F2494_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80049498_4A098(s32 arg0) {
    UnkDiceRelated* temp_s0 = &D_800DF4C0_E00C0[arg0];

    if (temp_s0->unk28 != -1) {
        func_80079848_7A448(temp_s0->unk28);
        temp_s0->unk28 = -1;
    }
    temp_s0->unk2A = 1;
}

void func_800494FC_4A0FC(s32 arg0) {
    UnkDiceRelated* temp_s0;

    temp_s0 = &D_800DF4C0_E00C0[arg0];
    if ((temp_s0->unk2A == 1) && (temp_s0->unk_16 != -1)) {
        if ((temp_s0->dice != NULL) && (((omObjData*)temp_s0->dice)->work[0] != 2) && (D_800DF63D_E023D != 3) &&
            (temp_s0->unk_0A != 5) && (D_800DF63D_E023D != 4)) {
            temp_s0->unk28 = PlaySound(0x314);
        }
    }
    temp_s0->unk2A = 0;
}
void func_800495A8_4A1A8(s8 arg0) {
    D_800DF63D_E023D = arg0;
}
/* exact c: marioparty3 func_800DE988_F25A8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800495B4_4A1B4(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].rollValueIdx = arg1;
}

void func_800495D8_4A1D8(s32 arg0, s32 arg1) {
    D_800DF645_E0245 = arg1;
}
/* exact c: marioparty3 func_800DE9B8_F25D8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800495E4_4A1E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UnkDiceRelated *entry;

    entry = &D_800DF4C0_E00C0[arg0];

    if (entry->rollValue[arg1] >= 10) {
        SprAttrReset(entry->sprites[arg1], 1, 0x8000);
        SprPosSet(entry->sprites[arg1], 0, arg2 + 10, arg3);
        SprPosSet(entry->sprites[arg1], 1, -0x1C, 0);
    } else {
        SprAttrSet(entry->sprites[arg1], 1, 0x8000);
        SprPosSet(entry->sprites[arg1], 0, arg2, arg3);
    }
}

void func_800496CC_4A2CC(s32 arg0) {
    UnkDiceRelated* temp_a1 = &D_800DF4C0_E00C0[arg0];

    if (temp_a1->dice != NULL) {
        ((omObjData*)temp_a1->dice)->trans.x = ((MBModel*)gPlayers[arg0].unk_24)->pos.x;
        ((omObjData*)temp_a1->dice)->trans.y = ((MBModel*)gPlayers[arg0].unk_24)->pos.y + D_800DF640_E0240;
        ((omObjData*)temp_a1->dice)->trans.z = ((MBModel*)gPlayers[arg0].unk_24)->pos.z;
    }
}
/* exact c: marioparty func_800420A0 (src/42CA0.c) */
void func_80049760_4A360(void) {
    f32 volume = 96.0f;

    func_800794F0_7A0F0(96);
    do {
        HuPrcVSleep();
        volume += 1.9375f;
        if (volume >= 127.0f) {
            volume = 127.0f;
        }
        func_800794F0_7A0F0((s8)volume);
    } while (volume < 127.0f);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_80042140 (src/42CA0.c) */
void func_80049800_4A400(void) {
    f32 volume = 127.0f;

    func_800794F0_7A0F0(127);
    do {
        HuPrcVSleep();
        volume -= 1.9375f;
        if (volume <= 96.0f) {
            volume = 96.0f;
        }
        func_800794F0_7A0F0((s8)volume);
    } while (volume > 96.0f);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_800421E0 (src/42CA0.c) */
void func_800498A0_4A4A0(void) {
    omAddPrcObj(func_80049800_4A400, 0xEFFF, 0, 0);
}

/* exact c: marioparty func_800421E0 (src/42CA0.c) */
void func_800498CC_4A4CC(void) {
    omAddPrcObj(func_80049760_4A360, 0xEFFF, 0, 0);
}

