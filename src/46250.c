#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "game/board.h"

/* Board dice blocks and coin/dice processes (MP3 ovl_80_shared_board/EE660.c, MP1 src/3F5B0.c)
   and music fades (MP1 src/42CA0.c). func_80047868, func_80047908 (MP1 func_80041048,
   func_800410E8), func_80047978 and func_800479E4 stay asm: their name strings share this unit's
   rodata piece with asm functions, so it is not carved; functions without C reference stay asm. */

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
extern s8 D_800DF63F_E023F;
extern f32 D_800DF640_E0240;
extern u8 D_800DF644_E0244;
extern u8 D_800DF645_E0245;
extern s8 D_800DF646_E0246;
extern s16 D_800FC734_FD334;

void omDelObj(omObjData*);
s16 PlaySound(s32);
void func_80046F98_47B98(s32);
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
extern s16 D_800CBCC0_CC8C0[][2];
extern u16 ContBtnTrg[4];
s16 Hu3DModelCreate(void*, s32);
void func_80029EDC_2AADC(s16, s32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void HmfModelObjAttrSet(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_8002A00C_2AC0C(s16);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s32, void*);
s16 func_8003DBE8_3E7E8(HmfData*, u16, s32, void*);
void func_800456BC_462BC(omObjData*);
extern s8 D_800DF647_E0247;
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

INCLUDE_ASM("asm/nonmatchings/46250", func_800456BC_462BC);

INCLUDE_ASM("asm/nonmatchings/46250", func_80045B40_46740);

INCLUDE_ASM("asm/nonmatchings/46250", func_80045F54_46B54);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80046308_46F08);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80046918_47518);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80046F98_47B98);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80047868_48468);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047908_48508);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047978_48578);

INCLUDE_ASM("asm/nonmatchings/46250", func_800479E4_485E4);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80047BB8_487B8);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80048860_49460);

/* exact c: marioparty func_800419D8 (src/3F5B0.c) */
Process* func_80048A48_49648(s32 player) {
    Process* process = omAddPrcObj(func_80048860_49460, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80048AA8_496A8);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80048E80_49A80);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_800491F0_49DF0);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_80049470_4A070);

INCLUDE_ASM("asm/nonmatchings/46250", func_8004947C_4A07C);

INCLUDE_ASM("asm/nonmatchings/46250", func_8004948C_4A08C);

/* exact c: marioparty3 func_800DE874_F2494_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80049498_4A098(s32 arg0) {
    UnkDiceRelated* temp_s0 = &D_800DF4C0_E00C0[arg0];

    if (temp_s0->unk28 != -1) {
        func_80079848_7A448(temp_s0->unk28);
        temp_s0->unk28 = -1;
    }
    temp_s0->unk2A = 1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800494FC_4A0FC);

INCLUDE_ASM("asm/nonmatchings/46250", func_800495A8_4A1A8);

/* exact c: marioparty3 func_800DE988_F25A8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800495B4_4A1B4(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].rollValueIdx = arg1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800495D8_4A1D8);

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

INCLUDE_ASM("asm/nonmatchings/46250", func_800496CC_4A2CC);

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

