#include "common.h"
#include "ovl_34.h"
#include "game/pad.h"

/* The block holder's update: a CPU holder walks under each block in turn and jumps (MP1
   func_800F7108). */


/* Retail starts a new file here (0x8010E7C0): the previous one is padded to 16 bytes. */

void func_8010E7C0_2658C0_ChanceTime(omObjData* obj) {
    omObjData* objs[3];
    s32 dead[3];
    CTPlayerWork* work;
    s16 i;
    u16 btn;
    f32 angle;
    s16 port;
    u16 cur;

    btn = 0;
    angle = -1.0f;
    work = CT_PWORK(obj);
    port = work->unk_57;
    /* Dead locals, as in MP1: [2] is D_80110D88 read through D_80110D80, and the word at 0xB0
       lies past an N64 omObjData (host: out of bounds; never used). */
    for (i = 0; i < 3; i++) {
        objs[i] = D_80110D80_267E80_ChanceTime[i];
        dead[i] = *(s32*)((u8*)objs[i] + 0xB0);
    }
    D_80110D5A_267E5A_ChanceTime[port] = ContBtn[port];
    D_80110B10_267C10_ChanceTime[port] = ContStkX[port];
    D_80110D66_267E66_ChanceTime[port] = ContStkY[port];
    D_801109F0_267AF0_ChanceTime[port] = ContBtnTrg[port];
    if (gPlayers[work->unk_59].flags & 1) {
        if (D_801101D0_2672D0_ChanceTime == 0) {
            if (D_80110060_267160_ChanceTime == 0) {
                D_801109D0_267AD0_ChanceTime[2] = 1;
                if ((guRandom() & 0x10) == 0) {
                    D_801109D0_267AD0_ChanceTime[0] = 0;
                    D_801109D0_267AD0_ChanceTime[1] = 2;
                } else {
                    D_801109D0_267AD0_ChanceTime[0] = 2;
                    D_801109D0_267AD0_ChanceTime[1] = 0;
                }
            } else {
                D_801109D0_267AD0_ChanceTime[0] = 0;
                D_801109D0_267AD0_ChanceTime[1] = 1;
            }
            D_801101D0_2672D0_ChanceTime = 1;
        }
        if (D_800F8FD0_F9BD0 == 1) {
            if (D_80110060_267160_ChanceTime == 0) {
                if (D_801101D4_2672D4_ChanceTime == 0) {
                    if (D_801101D6_2672D6_ChanceTime < 3) {
                        angle = (obj->trans.x + 1000.0f > D_80110D80_267E80_ChanceTime[D_801109D0_267AD0_ChanceTime[D_801101D6_2672D6_ChanceTime]]->trans.x + 1000.0f) ? 180.0f : 0.0f;
                        if (abs((s32)((obj->trans.x + 1000.0f) - (D_80110D80_267E80_ChanceTime[D_801109D0_267AD0_ChanceTime[D_801101D6_2672D6_ChanceTime]]->trans.x + 1000.0f))) < 21) {
                            angle = -1.0f;
                            D_801101D4_2672D4_ChanceTime = 1;
                            D_801109D4_267AD4_ChanceTime = 0;
                            D_801109D8_267AD8_ChanceTime = guRandom() % 30 + 60;
                        }
                    }
                    btn = 0;
                }
                if (D_801101D4_2672D4_ChanceTime == 1) {
                    if (D_801109D4_267AD4_ChanceTime++ > D_801109D8_267AD8_ChanceTime) {
                        D_801101D6_2672D6_ChanceTime++;
                        D_801101D4_2672D4_ChanceTime = 0;
                        btn = 0x8000;
                    } else {
                        work->unk_3C = 0.0f;
                    }
                }
            } else {
                if (D_801101D4_2672D4_ChanceTime == 0) {
                    if (D_801101D6_2672D6_ChanceTime < 2) {
                        angle = (obj->trans.x + 1000.0f > D_80110D80_267E80_ChanceTime[D_801109D0_267AD0_ChanceTime[D_801101D6_2672D6_ChanceTime]]->trans.x + 1000.0f) ? 180.0f : 0.0f;
                        if (abs((s32)((obj->trans.x + 1000.0f) - (D_80110D80_267E80_ChanceTime[D_801109D0_267AD0_ChanceTime[D_801101D6_2672D6_ChanceTime]]->trans.x + 1000.0f))) < 21) {
                            angle = -1.0f;
                            D_801101D4_2672D4_ChanceTime = 1;
                            D_801109D4_267AD4_ChanceTime = 0;
                            D_801109D8_267AD8_ChanceTime = guRandom() % 30 + 60;
                        }
                    }
                    btn = 0;
                }
                if (D_801101D4_2672D4_ChanceTime == 1) {
                    if (D_801109D4_267AD4_ChanceTime++ > D_801109D8_267AD8_ChanceTime) {
                        D_801101D6_2672D6_ChanceTime++;
                        D_801101D4_2672D4_ChanceTime = 0;
                        btn = 0x8000;
                    } else {
                        work->unk_3C = 0.0f;
                    }
                }
            }
            cur = btn | (ContBtn[port] & 0x7FFF);
            btn = cur;
            ContBtnTrg[port] = ContBtn[port] = btn;
            ContBtnTrg[port] = cur & (cur ^ D_801101D2_2672D2_ChanceTime);
            D_801101D2_2672D2_ChanceTime = btn;
            if (angle < 0.0f) {
                ContStkY[port] = 0;
                ContStkX[port] = 0;
            } else {
                ContStkX[port] = func_800B7890_B8490(angle) * 40.0f;
                ContStkY[port] = -HuMathSin(angle) * 40.0f;
            }
        }
    }
    if (D_80110068_267168_ChanceTime == 1) {
        ContBtn[port] = D_80110D72_267E72_ChanceTime[port];
        ContStkX[port] = D_80110D56_267E56_ChanceTime[port];
        ContStkY[port] = D_80110D6E_267E6E_ChanceTime[port];
        ContBtnTrg[port] = D_80110B14_267C14_ChanceTime[port];
    }
    func_80007790_8390(obj);
    func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
    if (obj->trans.y <= 10.0f) {
        D_80110061_267161_ChanceTime = 1;
    }
    ContBtn[port] = D_80110D5A_267E5A_ChanceTime[port];
    ContStkX[port] = D_80110B10_267C10_ChanceTime[port];
    ContStkY[port] = D_80110D66_267E66_ChanceTime[port];
    ContBtnTrg[port] = D_801109F0_267AF0_ChanceTime[port];
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010EED0_265FD0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010EF84_266084_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F304_266404_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F4B4_2665B4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F760_266860_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F82C_26692C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F8F8_2669F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010F9C4_266AC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010FC18_266D18_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010FD28_266E28_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010FE50_266F50_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/2658C0", func_8010FF1C_26701C_ChanceTime);
