#include "common.h"
#include "process.h"

/* Board-event wrappers; func_80073D2C_7492C is MP1 src/51200.c func_80052934 (runs
   func_80073BF4_747F4 as a child process). The rest has no reference and stays asm. */

extern u8 D_800F851A_F911A;
extern s16 D_800FD2A6_FDEA6;
extern s16 D_800E20C0_E2CC0;

void func_80073BF4_747F4(void);
void func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
s32 HuGetPadInserted(s16 port);
void func_800884AC_890AC(s16);
void func_800794F0_7A0F0(s8);
void func_800794A8_7A0A8(s32);
void func_80028334_28F34(s16, s32);
void func_80029EDC_2AADC(s16, s32);
void omPrcSetStatBit(Process* process, s32 value);
void func_800744C0_750C0(void);
void func_800740AC_74CAC(void);
#include "game/board.h"

extern UnkMBGuideData* D_800E20C4_E2CC4; /* the quit menu's guide */
extern s32 D_800CD2B0_CDEB0[];          /* its model description */
extern s8 D_800FDC9C_FE89C;
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_8008D59C_8E19C(s16 winId, s16 ports);
void func_80089A48_8A648(s16, s16);
s16 func_8008BA30_8C630(s16 winId);
void HuPrcVSleep(void);
unk_Struct02* func_8005E688_5F288(s32, s32);
void* DataRead(s32 dirAndFile);
void DataClose(void* data);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 group, s16 member, u16 prio);
void SprAttrSet(s16 group, s16 member, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_800824B4_830B4(s16, s16, u8, u8, u8, u8);
/* takes the model description's address (the overlays declare it s32) */
UnkMBGuideData* func_80050304_50F04(void*, s32);
void func_8005057C_5117C(UnkMBGuideData*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_80043DAC_449AC(MBModel*);
void func_800298A4_2A4A4(s16, s32, s32);
void func_800505C4_511C4(void*, s16, s32);
void func_8005B424_5C024(UnkMBGuideData* arg0, s16 arg1);
void func_8008E6CC_8F2CC(s16 arg0, s16 arg1);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008DF9C_8EB9C(s32 winId, u16 btn);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008AD44_8B944(s16 win);
void func_800753D4_75FD4(s32 flag);
void func_8007E070_7EC70(void);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void HuMemDirectFree(void*);
s32 omDelPrcObj(void*);
void func_8007388C_7448C(s32 player);

/* Show message mes in the guide's window for player's controller and wait for it to close. */
void func_800737F0_743F0(s32 mes, s32 player) {
    func_800890CC_89CCC(D_800E20C4_E2CC4->amount, mes, -1, -1);
    func_8008D59C_8E19C(D_800E20C4_E2CC4->amount, 1 << player);
    func_80089A48_8A648(D_800E20C4_E2CC4->amount, 0);
    while (func_8008BA30_8C630(D_800E20C4_E2CC4->amount) != 0) {
        HuPrcVSleep();
    }
}

/* The board's quit menu (message 0x5C6 choices): 1 saves and quits (0x5C7 confirm, 0x5C8),
   2 quits without saving (0x5C9 and 0x5CA confirm); D_800E20C0_E2CC0 = 1 when quitting. */
// register allocation: sprite and choice swap s1/s2 (masked 0)
#ifdef NON_MATCHING
void func_8007388C_7448C(s32 player) {
    s32 choice;
    unk_Struct02* sprite;
    void* data;
    s32 ret;

    sprite = func_8005E688_5F288(1, 0);
    data = DataRead(0xA0183);
    sprite->unk0C[0] = SprAnimRead(data);
    SprAnimSet(sprite->unk0A, 0, sprite->unk0C[0], 0);
    SprPrioSet(sprite->unk0A, 0, 7);
    SprAttrSet(sprite->unk0A, 0, 0x1000);
    SprPosSet(sprite->unk0A, 0, 0xA0, 0x50);
    DataClose(data);
    D_800E20C4_E2CC4 = func_80050304_50F04(D_800CD2B0_CDEB0, 0);
    D_800E20C4_E2CC4->obj->pos.x -= 1.0f;
    HuVecCopyXYZ(&D_800E20C4_E2CC4->obj->scale, 0.8f, 0.8f, 0.8f);
    func_80043DAC_449AC(D_800E20C4_E2CC4->obj);
    choice = 0;
    func_800298A4_2A4A4(*D_800E20C4_E2CC4->obj->obj->model, 0x8000, 0x8000);
    D_800E20C4_E2CC4->obj->attr |= 0x10;
    func_800505C4_511C4(D_800E20C4_E2CC4, 0x104, 8);
    func_8005B424_5C024(D_800E20C4_E2CC4, 0x55);
    func_8008E6CC_8F2CC(D_800E20C4_E2CC4->amount, 5);
    func_8008E2DC_8EEDC(D_800E20C4_E2CC4->amount, 1);
loop:
    func_800737F0_743F0(0x5C6, player);
    func_8008DF9C_8EB9C(D_800E20C4_E2CC4->amount, 0x5000);
    choice = func_8008BB48_8C748(D_800E20C4_E2CC4->amount, choice, 0);
    switch (choice) {
        case 1:
            func_8008AD44_8B944(D_800E20C4_E2CC4->amount);
            func_800737F0_743F0(0x5C7, player);
            ret = func_8008BB48_8C748(D_800E20C4_E2CC4->amount, 0, 0);
            func_8008AD44_8B944(D_800E20C4_E2CC4->amount);
            if (ret != 0) {
                goto loop;
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E070_7EC70();
            D_800E20C0_E2CC0 = 1;
            func_800737F0_743F0(0x5C8, player);
            break;
        case 2:
            func_8008AD44_8B944(D_800E20C4_E2CC4->amount);
            func_800737F0_743F0(0x5C9, player);
            ret = func_8008BB48_8C748(D_800E20C4_E2CC4->amount, 1, 0);
            func_8008AD44_8B944(D_800E20C4_E2CC4->amount);
            if (ret != 0) {
                goto loop;
            }
            func_800737F0_743F0(0x5CA, player);
            if (func_8008BB48_8C748(D_800E20C4_E2CC4->amount, 1, 0) != 0) {
                func_8008AD44_8B944(D_800E20C4_E2CC4->amount);
                goto loop;
            }
            D_800E20C0_E2CC0 = 1;
            break;
        case 0:
            break;
    }
    HuMemDirectFree(sprite);
    func_8008E4D0_8F0D0(D_800E20C4_E2CC4->amount, 1);
    func_8005B424_5C024(D_800E20C4_E2CC4, 0x104);
    func_8005057C_5117C(D_800E20C4_E2CC4);
    D_800E20C4_E2CC4 = NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/743F0", func_8007388C_7448C);
#endif

/* MP1 func_800527A0: the quit-menu process (darkened background, then the menu) */
void func_80073BF4_747F4(void) {
    s32 player = (s32)HuPrcCurrentGet()->user_data;
    unk_Struct02* sprite;
    void* data;

    HuPrcVSleep();
    D_800FDC9C_FE89C = 1;
    sprite = func_8005E688_5F288(1, 0);
    data = DataRead(0xA00D6);
    sprite->unk0C[0] = SprAnimRead(data);
    SprAnimSet(sprite->unk0A, 0, sprite->unk0C[0], 0);
    SprPrioSet(sprite->unk0A, 0, 9);
    SprAttrSet(sprite->unk0A, 0, 0x1000);
    SprPosSet(sprite->unk0A, 0, 0xA0, 0x78);
    SprScaleSet(sprite->unk0A, 0, 40.0f, 30.0f);
    func_800824B4_830B4(sprite->unk0A, 0, 0, 0, 0, 0xC0);
    DataClose(data);
    HuPrcVSleep();
    func_8007388C_7448C(player);
    if (D_800E20C0_E2CC0 == 0) {
        D_800FDC9C_FE89C = 0;
    }
    HuMemDirectFree(sprite);
    omDelPrcObj(NULL);
}

void func_80073D2C_7492C(s32 arg0) {
    Process* parent;
    Process* proc;
    s32 i;

    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    for (i = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            func_800884AC_890AC(i);
        }
    }
    func_800794F0_7A0F0(0x60);
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    D_800E20C0_E2CC0 = 0;
    parent = HuPrcCurrentGet();
    proc = omAddPrcObj(func_80073BF4_747F4, 0xEFFF, 0, 0);
    proc->user_data = (void*)arg0;
    omPrcSetStatBit(proc, 0x80);
    HuPrcChildLink(parent, proc);
    HuPrcChildWatch();
    func_80028334_28F34(D_800FD2A6_FDEA6, 6);
    func_800794F0_7A0F0(0x7F);
    if (D_800E20C0_E2CC0 != 0) {
        func_800794A8_7A0A8(0x5A);
        InitFadeOut(0, 0x10);
        HuPrcSleep(0x11);
        func_800744C0_750C0();
        func_800740AC_74CAC();
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
}
