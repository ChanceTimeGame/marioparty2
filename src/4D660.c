#include "common.h"
#include "game/malloc.h"
#include "game/board.h"

/* Board label windows, player swap and item helpers. C from MP1 src/467E0.c (func_80045CE4 ..
   func_80045E6C), src/46AE0.c (func_80045EE0 .. func_800466C0), src/3CED0.c (func_8003D20C) and MP3
   ovl_80_shared_board F5E80.c (MBItem*); the rest have no reference or differ (near) and stay asm. */

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

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004CF94_4DB94);

void func_8004D5B0_4E1B0(void) {
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_8004CF94_4DB94, 0x1003, 0, 0));
    HuPrcChildWatch();
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D600_4E200);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D60C_4E20C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D620_4E220);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D6A0_4E2A0);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D734_4E334);

s32 MBItemRobBoxExec(void) {
    MBItemSubFunctions[3]();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D780_4E380);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D7A0_4E3A0);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D858_4E458);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D8B0_4E4B0);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004D944_4E544);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DA2C_4E62C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DAC4_4E6C4);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DB1C_4E71C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DBA8_4E7A8);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DC0C_4E80C);

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DE7C_4EA7C);

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

INCLUDE_ASM("asm/nonmatchings/4D660", MBItemDesc);

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

INCLUDE_ASM("asm/nonmatchings/4D660", func_8004E89C_4F49C);

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
