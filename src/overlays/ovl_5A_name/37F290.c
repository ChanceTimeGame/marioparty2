#include "common.h"
#include "game/pad.h"
#include "game/data.h"
#include "game/board.h"

/* Overlay 5A: shows one full-screen sprite (file 0x100019) until a button is pressed, then goes
   to overlay 0x57. */

unk_Struct02* func_8005E688_5F288(s32, s32);
void func_8005E584_5F184(void);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16, s16, s16, s16);
s32 func_800824B4_830B4(s16, s32, s32, s32, s32, s32);
void HuMemDirectFree(void* p);

void func_80102830_37F2C0_name_5A(void) {
    unk_Struct02* spr;
    void* data;

    func_80088640_89240();
    func_8005E570_5F170();
    spr = func_8005E688_5F288(1, 0);
    data = DataRead(0x100019);
    spr->unk0C[0] = SprAnimRead(data);
    SprAnimSet(spr->unk0A, 0, spr->unk0C[0], 0);
    SprPrioSet(spr->unk0A, 0, 10);
    SprAttrSet(spr->unk0A, 0, 0x1000);
    SprPosSet(spr->unk0A, 0, 160, 120);
    func_800824B4_830B4(spr->unk0A, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(data);
    InitFadeIn(0xFF, 8);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    do {
        HuPrcVSleep();
    } while (!((ContBtnTrg[0] | ContBtnTrg[1] | ContBtnTrg[2] | ContBtnTrg[3]) & 0xF00F));
    InitFadeOut(0xFF, 8);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuMemDirectFree(spr);
    func_8005E584_5F184();
    func_8008CE5C_8DA5C();
    omOvlGotoEx(0x57, 0, 0x81);
    omOvlKill();
    HuPrcVSleep();
}

void func_801029C8_37F458_name_5A(void) {
    omInitObjMan(10, 10);
    func_80079128_79D28();
    omAddPrcObj(func_80102830_37F2C0_name_5A, 0x1005, 0, 0);
}
