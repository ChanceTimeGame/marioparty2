#include "common.h"
#include "game/malloc.h"
#include "game/board.h"

/* Board label windows, player swap and item helpers. C from MP1 src/467E0.c (func_80045CE4 ..
   func_80045E6C), src/46AE0.c (func_80045EE0 .. func_800466C0), src/3CED0.c (func_8003D20C) and MP3
   ovl_80_shared_board F5E80.c (MBItem*); the rest have no reference and stay asm.
   func_8004CC7C_4D87C (MP1 func_80045D84) stays asm: its "%2d" string is this unit's rodata (D38A0),
   which cannot be carved while func_8004E4FC_4F0FC (no reference) uses D38A8. */

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 mode;
    /* 0x02 */ s16 y;
    /* 0x04 */ omObjData* obj;
    /* 0x08 */ s16 win;
    /* 0x0C */ u8* str;
    /* 0x10 */ char* extra;
} LabelWin;

extern s16 D_800DF710_E0310;
extern s16 D_800DF712_E0312;
extern void (*MBItemSubFunctions[])(void);

s16 GetCurrentPlayerIndex(void);
GW_PLAYER* BoardPlayerGet(s32 playerIndex);
void omDelObj(omObjData*);
void omPrcSetStatBit(Process*, s32);
void MBItemDesc(void);
void func_8004CA60_4D660(LabelWin*);
s32 func_8004CDF8_4D9F8(s16 a, s16 b);
void func_8004CF94_4DB94(void);
void func_8004DF3C_4EB3C(void);
s32 func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
void func_8008CCA8_8D8A8(s16);
void MBDlgWinExec(s32, s32);
void MBDlgResultWinExec(s32);
s32 func_8004CC7C_4D87C(s32, s32, s32);
void func_8004DC0C_4E80C(void);
void func_80046EDC_47ADC(s32);
void func_80046F50_47B50(s32);
void func_80053FAC_54BAC(void);
void func_80053FBC_54BBC(void);
void func_80064F1C_65B1C(void);
extern s32 D_800CC038_CCC38;
void func_800636F8_642F8(s32);
s32 PlaySound(s32);
MBModel* func_80043510_44110(s32, void*);
void MBMotionSet(MBModel*, s16, s32);
void func_800B3170_B3D70(Vec*, Vec*); /* HuVecCopy3F */
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
void MBModelKill(MBModel*);
void SwapPlayerLocationData(s16, s16);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
void func_8005660C_5720C(s16, s16);
void MBPlayerVibrate(s16, s16);
void func_800517C0_523C0(void);
void func_80051788_52388(void);
f32 MBCameraSpeedGet(void);
void MBCameraSpeedSet(f32);
f32 func_80053614_54214(void);
void func_80053608_54208(f32);
void func_800514F0_520F0(void);
void func_80051500_52100(void);
u16 MBDCameraPos3DSet(Vec*);
void func_80063C40_64840(s32, s32);
void func_80056368_56F68(s16, u32, s32, s32, s32, s32, s32);
void MBDlgWinClose(void);
void func_80056168_56D68(void);
void func_8004CDE0_4D9E0(void);
extern u16 ContDStkTrg[4];
extern u16 D_800FC9E0_FD5E0[4];
extern s16 D_800CC074_CCC74[]; /* item help window widths? (MP3 D_80101148) */
extern s32 D_800CC04C_CCC4C[]; /* item description messages (MP3 D_801010F8) */
void func_8008DBE0_8E7E0(s16* arg0, s16 arg1, s16 arg2);
s32 func_8008E73C_8F33C(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5);
void func_8008D530_8E130(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_8008E978_8F578(s16);
void func_8008AD44_8B944(s16);
void func_8008EBE4_8F7E4(s16, s16);
void func_8008EED8_8FAD8(s16, s16);
extern s32 D_800CC03C_CCC3C;
extern s32 D_800CC040_CCC40;
extern s32 D_800CC044_CCC44;
extern s32 D_800CC048_CCC48;


INCLUDE_ASM("asm/nonmatchings/4D660", func_8004CA60_4D660);

void func_8004CBDC_4D7DC(LabelWin* w) {
    func_8008CCA8_8D8A8(w->win);
    HuMemMemoryFreeTemp(w->str);
    w->win = -1;
}

void func_8004CC14_4D814(omObjData* obj) {
    LabelWin* w = obj->unk_50;

    if (w->mode == 1 && D_80102720_103320 != 0) {
        if (w->win >= 0) {
            func_8004CBDC_4D7DC(w);
        }
    } else if (w->win < 0) {
        func_8004CA60_4D660(w);
    }
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004CC7C_4D87C);

void MBHelpWinKill(s32 arg0) {
    LabelWin* w = (LabelWin*)arg0;

    if (w != NULL) {
        w->obj->unk_50 = NULL;
        omDelObj(w->obj);
        if (w->win >= 0) {
            func_8008CCA8_8D8A8(w->win);
            HuMemMemoryFreeTemp(w->str);
            if (w->extra != NULL) {
                HuMemMemoryFreeTemp(w->extra);
            }
        }
        HuMemMemoryFreeTemp(w);
    }
}

void func_8004CDE0_4D9E0(void) {
    D_800DF710_E0310 = -1;
    D_800DF712_E0312 = -1;
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004CDF8_4D9F8);

void func_8004CE08_4DA08(s16 a, s16 b) {
    if (b == GetCurrentPlayerIndex()) {
        D_800DF710_E0310 = b;
        D_800DF712_E0312 = a;
    } else {
        D_800DF710_E0310 = a;
        D_800DF712_E0312 = b;
    }
}

s32 func_8004CE80_4DA80(void) {
    s16 order[4];
    GW_PLAYER* cur;
    s32 i;
    s32 b;
    s32 a;
    u16 tmp;

    cur = BoardPlayerGet(-1);
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    for (i = 0; i < 30; i++) {
        a = rand8() & 3;
        b = rand8() & 3;
        tmp = order[a];
        order[a] = order[b];
        order[b] = tmp;
    }
    for (i = 0; i < 4; i++) {
        a = order[i];
        if ((u8)cur->unk_1C[0] != a && func_8004CDF8_4D9F8((u8)cur->unk_1C[0], a) != 0) {
            break;
        }
    }
    if (i == 4) {
        return 0;
    }
    func_8004CE08_4DA08((u8)cur->unk_1C[0], a);
    return 1;
}

void func_8004CF94_4DB94(void) {
    char str0[16];
    char str1[16];
    GW_PLAYER* p0;
    GW_PLAYER* p1;
    MBModel* o0;
    MBModel* o1;
    MBModel* fx;
    s32 i;
    f32 f;
    f32 g;
    f32 h;
    f32 camA;
    f32 camB;

    func_800636F8_642F8(0);
    p0 = BoardPlayerGet(D_800DF710_E0310);
    p1 = BoardPlayerGet(D_800DF712_E0312);
    p0->flags |= 4;
    p1->flags |= 4;
    o0 = p0->unk_24;
    o1 = p1->unk_24;
    PlaySound(0x32E);
    fx = func_80043510_44110(0x1B, NULL);
    MBMotionSet(fx, -1, 0);
    func_800B3170_B3D70(&fx->pos, &o0->pos);
    for (i = 0; i < 15; i++) {
        f = i / 15.0f;
        g = 1.0f - f;
        h = f + 1.0f;
        o0->scale.x = g;
        o0->scale.y = h;
        o0->scale.z = g;
        o0->jumpY += 6.0f;
        HuPrcVSleep();
    }

    o0->scale.x = 0.0f;
    o0->scale.y = 0.0f;
    o0->scale.z = 0.0f;
    HuPrcVSleep();
    o0->attr &= ~2;
    MBModelDispOff(o0);
    MBModelKill(fx);
    PlaySound(0x32E);
    fx = func_80043510_44110(0x1B, NULL);
    MBMotionSet(fx, -1, 0);
    func_800B3170_B3D70(&fx->pos, &o1->pos);
    for (i = 0; i < 15; i++) {
        f = i / 15.0f;
        g = 1.0f - f;
        h = f + 1.0f;
        o1->scale.x = g;
        o1->scale.y = h;
        o1->scale.z = g;
        o1->jumpY += 6.0f;
        HuPrcVSleep();
    }

    MBModelKill(fx);
    SwapPlayerLocationData(D_800DF710_E0310, D_800DF712_E0312);
    func_8005660C_5720C(D_800DF710_E0310, GetAbsSpaceIndexFromChainSpaceIndex(p0->cur_chain_index, p0->cur_space_index));
    func_8005660C_5720C(D_800DF712_E0312, GetAbsSpaceIndexFromChainSpaceIndex(p1->cur_chain_index, p1->cur_space_index));
    PlaySound(0x32E);
    fx = func_80043510_44110(0x1B, NULL);
    MBMotionSet(fx, -1, 0);
    func_800B3170_B3D70(&fx->pos, &o1->pos);
    for (i = 14; i >= 0; i--) {
        f = i / 15.0f;
        g = 1.0f - f;
        h = f + 1.0f;
        o1->scale.x = g;
        o1->scale.y = h;
        o1->scale.z = g;
        o1->jumpY -= 6.0f;
        HuPrcVSleep();
    }

    MBModelKill(fx);
    MBPlayerVibrate(D_800DF712_E0312, 3);
    InitFadeOut(6, 16);
    HuPrcSleep(16);
    func_800517C0_523C0();
    func_80051788_52388();
    camA = MBCameraSpeedGet();
    MBCameraSpeedSet(-1.0f);
    camB = func_80053614_54214();
    func_80053608_54208(1.0f);
    func_800514F0_520F0();
    MBDCameraPos3DSet(&o0->pos);
    HuPrcVSleep();
    func_80051500_52100();
    func_80053608_54208(camB);
    MBCameraSpeedSet(camA);
    func_80063C40_64840(0, 1);
    func_80063C40_64840(1, 1);
    func_80063C40_64840(2, 1);
    func_80063C40_64840(3, 1);
    InitFadeIn(6, 16);
    HuPrcSleep(16);
    PlaySound(0x32E);
    o0->attr |= 2;
    MBModelDispOn(o0);
    fx = func_80043510_44110(0x1B, NULL);
    MBMotionSet(fx, -1, 0);
    func_800B3170_B3D70(&fx->pos, &o0->pos);
    for (i = 14; i >= 0; i--) {
        /* MP1 has the same two arms; they still steer register allocation */
        if (p0) {
            f = i / 15.0f;
            g = 1.0f - f;
            h = f + 1.0f;
            o0->scale.x = g;
            o0->scale.y = h;
            o0->scale.z = g;
            o0->jumpY -= 6.0f;
            HuPrcVSleep();
        } else {
            f = i / 15.0f;
            g = 1.0f - f;
            h = f + 1.0f;
            o0->scale.x = g;
            o0->scale.y = h;
            o0->scale.z = g;
            o0->jumpY -= 6.0f;
            HuPrcVSleep();
        }
    }

    MBModelKill(fx);
    p0->flags = (u16)p0->flags & ~4;
    p1->flags = (u16)p1->flags & ~4;
    if (D_800DF710_E0310 != GetCurrentPlayerIndex()) {
        HuPrcSleep(15);
        InitFadeOut(6, 16);
        HuPrcSleep(16);
        func_800517C0_523C0();
        func_80051788_52388();
        camA = MBCameraSpeedGet();
        MBCameraSpeedSet(-1.0f);
        camB = func_80053614_54214();
        func_80053608_54208(1.0f);
        func_800514F0_520F0();
        MBDCameraPos3DSet(&((MBModel*)BoardPlayerGet(-1)->unk_24)->pos);
        HuPrcVSleep();
        func_80051500_52100();
        func_80053608_54208(camB);
        MBCameraSpeedSet(camA);
        InitFadeIn(6, 16);
        HuPrcSleep(16);
    }
    HuPrcSleep(15);
    str0[0] = 0x18;
    str0[1] = gPlayers[D_800DF710_E0310].character;
    str0[2] = 0;
    str1[0] = 0x18;
    str1[1] = gPlayers[D_800DF712_E0312].character;
    str1[2] = 0;
    func_80056368_56F68(-1, 0x1E5, (s32)str0, (s32)str1, 0, 0, 0);
    MBDlgWinClose();
    func_80056168_56D68();
    func_800636F8_642F8(1);
    func_8004CDE0_4D9E0();
    omDelPrcObj(NULL);
}

void func_8004D5B0_4E1B0(void) {
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_8004CF94_4DB94, 0x1003, 0, 0));
    HuPrcChildWatch();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D600_4E200);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D60C_4E20C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D620_4E220);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D6A0_4E2A0);

s32 func_8004D734_4E334(void) {
    MBDlgWinExec(9, 0x1DF);
    return 1;
}

s32 MBItemRobBoxExec(void) {
    MBItemSubFunctions[3]();
    return 1;
}

s32 func_8004D780_4E380(void) {
    MBDlgResultWinExec(0x1E4);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D7A0_4E3A0);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D858_4E458);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D8B0_4E4B0);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D944_4E544);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DA2C_4E62C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DAC4_4E6C4);

void func_8004DB1C_4E71C(void) {
    D_800CC038_CCC38 = func_8004CC7C_4D87C(0xE, 0x92, 0);
    D_800CC03C_CCC3C = func_8004CC7C_4D87C(4, 0xA0, 0);
    D_800CC040_CCC40 = func_8004CC7C_4D87C(3, 0xAE, 0);
    D_800CC044_CCC44 = func_8004CC7C_4D87C(0xB, 0xBC, 0);
    D_800CC048_CCC48 = func_8004CC7C_4D87C(0xF, 0xCA, 0);
}

void func_8004DBA8_4E7A8(void) {
    if (D_800CC038_CCC38 != 0) {
        MBHelpWinKill(D_800CC038_CCC38);
        MBHelpWinKill(D_800CC03C_CCC3C);
        MBHelpWinKill(D_800CC040_CCC40);
        MBHelpWinKill(D_800CC044_CCC44);
        MBHelpWinKill(D_800CC048_CCC48);
        D_800CC038_CCC38 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DC0C_4E80C);

void func_8004DE7C_4EA7C(s32 arg0) {
    Process* cur;
    Process* p;

    func_80046EDC_47ADC(arg0);
    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    func_80053FBC_54BBC();
    cur = HuPrcCurrentGet();
    p = omAddPrcObj(func_8004DC0C_4E80C, 0x1005, 0x1000, 0);
    p->user_data = (void*)arg0;
    omPrcSetStatBit(p, 0x80);
    HuPrcChildLink(cur, p);
    HuPrcChildWatch();
    func_80053FAC_54BAC();
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
    func_80046F50_47B50(arg0);
    func_80064F1C_65B1C();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DF3C_4EB3C);

void func_8004E10C_4ED0C(void* arg0) {
    Process* cur;
    Process* p;

    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    cur = HuPrcCurrentGet();
    p = omAddPrcObj(func_8004DF3C_4EB3C, 0x1005, 0, 0);
    p->user_data = arg0;
    omPrcSetStatBit(p, 0x80);
    HuPrcChildLink(cur, p);
    HuPrcChildWatch();
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
}

void MBItemDesc(void) {
    s16 sp18[2];
    s16 temp_v0_2;
    s32 playerNo;
    s8 itemID;
    s32 savedItemID;
    s32 padNo;

    playerNo = (s32)(HuPrcCurrentGet()->user_data);
    padNo = gPlayers[playerNo].port;
    savedItemID = 0;

    itemID = gPlayers[playerNo].item;
    if (itemID != -1) {
        savedItemID = itemID;
    }

    func_8008DBE0_8E7E0(sp18, 0x1FA, 0x204);
    temp_v0_2 = func_8008E73C_8F33C(D_800CC074_CCC74[savedItemID], 0xA0 - (sp18[0] / 2), 0x3C, sp18[0], sp18[1], 0);
    func_8008D530_8E130(temp_v0_2, 0, 0x78, 0);
    func_800890CC_89CCC(temp_v0_2, D_800CC04C_CCC4C[savedItemID], -1, -1);
    func_8008E978_8F578(temp_v0_2);
    D_800CC03C_CCC3C = func_8004CC7C_4D87C(0x10, 0xA0, 0);
    D_800CC040_CCC40 = func_8004CC7C_4D87C(0x11, 0xAE, 0);
    D_800CC044_CCC44 = func_8004CC7C_4D87C(4, 0xBC, 0);

    while (1) {
        if (ContDStkTrg[padNo] & 0x4000) {
            break;
        }
        if (D_800FC9E0_FD5E0[padNo] & 1) {
            savedItemID++;
            savedItemID %= 10;
            func_8008AD44_8B944(temp_v0_2);
            func_800890CC_89CCC(temp_v0_2, D_800CC04C_CCC4C[savedItemID], -1, -1);
            func_8008EBE4_8F7E4(temp_v0_2, D_800CC074_CCC74[savedItemID]);
        }
        if (D_800FC9E0_FD5E0[padNo] & 2) {
            savedItemID -= 1;
            if (savedItemID < 0) {
                savedItemID = 9;
            }
            func_8008AD44_8B944(temp_v0_2);
            func_800890CC_89CCC(temp_v0_2, D_800CC04C_CCC4C[savedItemID], -1, -1);
            func_8008EBE4_8F7E4(temp_v0_2, D_800CC074_CCC74[savedItemID]);
        }
        HuPrcVSleep();
    }

    MBHelpWinKill(D_800CC03C_CCC3C);
    MBHelpWinKill(D_800CC040_CCC40);
    MBHelpWinKill(D_800CC044_CCC44);
    func_8008EED8_8FAD8(temp_v0_2, 0);
    func_8008CCA8_8D8A8(temp_v0_2);
    omDelPrcObj(NULL);
}

void MBItemDescExec(s32 arg0) {
    Process* temp_s2;
    Process* temp_v0;

    temp_s2 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(MBItemDesc, 0x1005, 0, 0);
    temp_v0->user_data = (void*)arg0;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s2, temp_v0);
    HuPrcChildWatch();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004E4FC_4F0FC);

void func_8004E89C_4F49C(void) {
    s32 i = GwSystem.current_player_index;

    if (gPlayers[i].turn_status != 0) {
        MBItemSubFunctions[5]();
        gPlayers[i].turn_status = 0;
    }
}

void func_8004E904_4F504(void) {
    MBItemSubFunctions[8]();
}

void func_8004E928_4F528(void) {
    MBItemSubFunctions[9]();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004E94C_4F54C);

void func_8004E9A8_4F5A8(void) {
    MBItemSubFunctions[10]();
}

void func_8004E9CC_4F5CC(void) {
    MBItemSubFunctions[12]();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004E9F0_4F5F0);

void func_8004EA28_4F628(void) {
    MBItemSubFunctions[13]();
}
