#include "common.h"
#include "game/board.h"
#include "game/hmfman.h"

/* Board overlay-call queue, board teardown and the two save-flag byte arrays (MP1 src/5CDB0.c,
   src/59E80.c, ovl_77 2FADB0.c). MP1's names are anonymous or name MP1-only structures, so MP2's
   are kept. */

typedef struct OvlCallEntry {
    /* 0x00 */ s32 overlay;
    /* 0x04 */ s16 event;
    /* 0x06 */ u16 stat;
} OvlCallEntry; // size 8

extern s16 D_800E20D2_E2CD2;
extern s16 D_800E20D4_E2CD4;
extern OvlCallEntry D_800E20D8_E2CD8[5];
extern s16 D_800E2104_E2D04;
extern s16 D_800E2106_E2D06;
extern s16 D_800E2108_E2D08;
extern s32 D_800E210C_E2D0C;
extern s16 D_800E2110_E2D10;
extern Vec D_800E2114_E2D14;
extern s16 D_800FD2A2_FDEA2;
extern s16 D_800FD840_FE440;
extern s8 D_800FD8AA_FE4AA;
extern u8 D_800FD8AD_FE4AD[];
extern u8 D_800FD425_FE025[];

void func_8007E128_7ED28(void);
void func_8006239C_62F9C(void);
void func_8005E584_5F184(void);
void func_8005E2FC_5EEFC(void);
void func_8004340C_4400C(void);
void func_80054AE8_556E8(void);
void func_8005429C_54E9C(void);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_800740AC_74CAC(void);
void func_8007451C_7511C(void);
s32 func_80075390_75F90(s32 flag);
void func_800753D4_75FD4(s32 flag);
void func_80075424_76024(s32 flag);
s32 func_80075478_76078(s32 flag);
void func_80075144_75D44(void);
void func_80073410_74010(s16 index);
GW_PLAYER* BoardPlayerGet(s32);
s32 func_8008F618_90218(void);
void func_800794A8_7A0A8(s32);
void func_800744C0_750C0(void);
void func_80073EA0_74AA0(s32 overlay, s16 event, u16 stat);

extern s16 D_800E20D0_E2CD0;

extern MBModel* D_800FA618_FB218;
extern s16 D_800FA188_FAD88;
extern s16 D_800FDCC8_FE8C8;
extern HmfModel* D_800FC834_FD434;
extern u8 D_01164160[];
void func_80050A30_51630(u8*);
void func_80050E00_51A00(s32);
void func_80054228_54E28(void);
void MBMasuCreate(s32, s16);
void ChangeSpaceTextures(s16);
void MBModelInit(void);
void func_8005E2B8_5EEB8(void);
void func_8005E2F4_5EEF4(void);
void func_8005E570_5F170(void);
void func_80088640_89240(void);
void func_80062268_62E68(void);
MBModel* func_80043510_44110(s32, void*);
void func_8005E154_5ED54(s16);
void func_80043DAC_449AC(MBModel*);
void func_8005AA48_5B648(MBModel*, const char*, s16);
SpaceData* GetSpaceData(s16);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
void func_80056658_57258(Vec*, Vec*, Vec*);
f32 func_800B1830_B2430(f32); /* sqrtf */
f64 func_800B727C_B7E7C(f64 y, f64 x); /* atan2 in degrees */
void func_800B3870_B4470(f32*, f32);
void func_800734E8_740E8(void);
void func_8005E310_5EF10(void);
void func_8005321C_53E1C(f32, f32);
void func_8005660C_5720C(s16, s16);
void func_800B3170_B3D70(Vec*, Vec*);
void func_800514F0_520F0(void);
void func_80053608_54208(f32);
void MBCameraSpeedSet(f32);
void func_80029708_2A308(s32);
void InitFadeIn(s32, s32);
u16 MBDCameraPos3DSet(Vec*);
s32 func_80011308_11F08(s16);
void func_800498CC_4A4CC(void);
void func_800745FC_751FC(s16);
extern s32 D_800E2100_E2D00;
extern s16 D_800E2112_E2D12;
extern s16 D_800E2120_E2D20;
extern u8 D_800F8C56_F9856;
extern u16 ContBtnTrg[];
extern u16 ContDStkTrg[];
extern const f64 D_800D34D8_D40D8;
void func_80051500_52100(void);
s32 func_800556F4_562F4(s16, s16);
void MBHelpWinKill(s32);
f32 func_80029CE4_2A8E4(s16);
void MBMotionShiftSet(void*, s16, s16, s16, u16);
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
Process* func_80056FD4_57BD4(Vec*, Vec*, Vec*, f32);
Process* func_80056B78_57778(Vec*, Vec*, Vec*, s32);
f32 HuVecDistance(Vec* a, Vec* b);
void MBPlayerVibrate(s16, s16);
void func_800553A8_55FA8(s16);
s32 func_8004CC7C_4D87C(s32, s32, s32);
void func_80073D2C_7492C(s32);
void func_80074638_75238(void);
void func_8007468C_7528C(void);
void func_80074808_75408(void);
void func_80074D28_75928(void);
void func_8007414C_74D4C(void);
extern s8 D_800FD8A9_FE4A9;
/* 274D0's UnkLightData as the light editor reads it: unsigned colours, 1-based lights */
typedef struct LightEditEntry {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 stat;
    /* 0x04 */ s8 x;
    /* 0x05 */ s8 y;
    /* 0x06 */ s8 z;
} LightEditEntry; /* size 7 */
typedef struct LightEditSet {
    /* 0x00 */ s16 count;
    /* 0x02 */ LightEditEntry light[8];
} LightEditSet;
extern LightEditSet* D_800FA620_FB220;
/* the editor object's work[] holds the two window ids as s16s */
#define LIGHTEDIT_WIN(obj) ((s16*)(obj)->work)
typedef struct PfWin {
    /* 0x00 */ u16 activeBool;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 xPosStart;
    /* 0x08 */ s32 yPosStart;
    /* 0x0C */ s32 width;
    /* 0x10 */ s32 height;
    /* 0x14 */ u32 rgba;
} PfWin; /* size 0x18 (7D1D0) */
extern PfWin pfWinData[4];
extern s32 fontcolor;
extern char pfStrBuf[];
extern u16 D_800FD410_FE010[4];
extern u16 D_800FC9E0_FD5E0[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
s16 DrawDebugText(u16 x, u16 y, char* str);
int sprintf(char* s, const char* fmt, ...);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cosine */
s16 pfWinCreate(s32, s32, s32, s32, s32);
void pfWinKill(s16);
void omSetStatBit(omObjData*, u16);
void omDelObj(omObjData*);
void func_80026D50_27950(s16, u8, u8);
void func_80026E00_27A00(s16, f32, f32, f32);
void bcopy(const void*, void*, int);
void func_80075688_76288(omObjData*);
s32 PlaySound(s32);
void HuPrcSleep(s32);
/* .data (0xCDEC0-0xCDF60); D_800CD2C8 and 0xCDF10 on are used only by the unit's asm */
s32 D_800CD2C0_CDEC0 = 1;
s32 D_800CD2C4_CDEC4 = 0;
s32 D_800CD2C8_CDEC8[2] = { 1, 0x000A0253 }; /* model description */
s32 D_800CD2D0_CDED0 = 0;
s32 D_800CD2D4_CDED4[11] = { 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0, 0 }; /* overlay per chapter */
u8 D_800CD300_CDF00[16] = { 9, 13, 18, 22, 27, 33, 39, 45, 51, 0, 0, 0, 0, 0, 0, 0 }; /* first story flag of each chapter */
omObjData* D_800CD310_CDF10 = NULL;
s16 D_800CD314_CDF14 = 1;
s16 D_800CD316_CDF16 = 0;
u8 D_800CD318_CDF18 = 0xF0;
u8 D_800CD319_CDF19 = 0;
s8 D_800CD31A_CDF1A = -1;
extern const char D_800D34E0_D40E0[]; /* "CAME" */
extern const char D_800D34E8_D40E8[];
char* D_800CD31C_CDF1C[2] = { (char*)D_800D34E8_D40E8, (char*)D_800D34E0_D40E0 };
s16 D_800CD324_CDF24[6] = { 0x10, 0x48, 0xE0, 0x58, 0x98, 0xE8 };
s16 D_800CD330_CDF30[6] = { 0x10, 0x10, 0x10, 0x18, 0x18, 0x18 };
s16 D_800CD33C_CDF3C[6] = { 0x38, 0x60, 0x100, 0x70, 0xC0, 0x108 };
s16 D_800CD348_CDF48[6] = { 0x18, 0x18, 0x18, 0x20, 0x20, 0x20 };
extern s16 D_800E2120_E2D20;
extern s8 D_800FD8AB_FE4AB;
extern s8 D_800FD8B4_FE4B4;
extern s8 D_800FD8B5_FE4B5;
extern u16 D_801011FC_101DFC;
#include "game/gamework.h"
/* D_800FD8A8_FE4A8's fields 0x0E-0x11 (Unk_800FD8A8 unk0E-unk11): retail addresses these
   through their own labels in func_80075060_75C60 and func_800751E0_75DE0 */
extern s8 D_800FD8B6_FE4B6;
extern s8 D_800FD8B7_FE4B7;
extern s8 D_800FD8B8_FE4B8;
extern s8 D_800FD8B9_FE4B9;
extern u8 D_800FD420_FE020[0x12];

void func_80073EA0_74AA0(s32 overlay, s16 event, u16 stat) {
    OvlCallEntry* e = &D_800E20D8_E2CD8[D_800E20D4_E2CD4++];

    e->overlay = overlay;
    e->event = event;
    e->stat = stat;
    if (D_800E20D4_E2CD4 >= 5) {
        D_800E20D4_E2CD4 = 4;
    }
}

void func_80073EF8_74AF8(void) {
    _SetFlag(0xC);
    if (func_80075390_75F90(4) != 0 || func_80075478_76078(4) != 0) {
        func_800753D4_75FD4(6);
    } else {
        func_80075424_76024(6);
    }
    D_800E20D0_E2CD0 = 1;
    D_800E20D4_E2CD4 = 0;
    D_800E20D2_E2CD2 = 2;
    if (func_80075478_76078(4) != 0) {
        func_80073EA0_74AA0(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], 4, 0x192);
    }
    if (func_80075390_75F90(6) == 0) {
        func_80073EA0_74AA0(0x6E, 0, 0x192);
        func_80073EA0_74AA0(0x64, 1, 0x192);
    }
    func_8007451C_7511C();
    func_80075424_76024(6);
    _ClearFlag(0x16);
}

void func_80073FE0_74BE0(void) {
    OvlCallEntry* e;

    if (D_800E20D4_E2CD4 != 0) {
        e = &D_800E20D8_E2CD8[--D_800E20D4_E2CD4];
        omOvlCallEx(e->overlay, e->event, e->stat);
        return;
    }
    if (D_800E20D0_E2CD0 != 0) {
        if (func_80075390_75F90(7) != 0) {
            func_80075424_76024(7);
        }
        omOvlCallEx(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], D_800E20D2_E2CD2, 0x192);
        D_800E20D2_E2CD2 = 2;
        return;
    }
    _ClearFlag(0xC);
    omOvlReturnEx(1);
}

void func_800740AC_74CAC(void) {
    D_800E20D0_E2CD0 = 0;
}

void func_800740B8_74CB8(void) {
    s8* savedSlot;
    s32 slot;

    func_80075424_76024(6);
    _ClearFlag(0x16);
    savedSlot = &D_800FD8AA_FE4AA;
    slot = *savedSlot;
    func_8007451C_7511C();
    *savedSlot = slot;
    func_80073EA0_74AA0(D_800CD2D4_CDED4[slot], 1, 0x192);
}

void func_8007411C_74D1C(void) {
    func_8007E128_7ED28();
    D_800FD2A2_FDEA2 = -1;
    D_800FD840_FE440 = -1;
}

void func_8007414C_74D4C(void) {
}

/* .rodata (0xD40C0-0xD4150), beside its asm users in address order */
const char D_800D34C0_D40C0[] = "point2";
const char D_800D34C8_D40C8[] = "point1";
const f64 D_800D34D0_D40D0 = -90.0;

void func_80074154_74D54(s32 boardModel, s32 boardFile) {
    GW_PLAYER* player;
    SpaceData* from;
    SpaceData* to;
    Vec diff;

    func_80050A30_51630(D_01164160);
    if (boardModel >= 0) {
        func_80050E00_51A00(boardModel);
    }
    func_80054228_54E28();
    if ((s16)boardFile >= 0) {
        MBMasuCreate(10, boardFile);
        ChangeSpaceTextures(2);
    }
    gPlayers[0].character = D_800FD8A8_FE4A8.unk00;
    gPlayers[1].character = D_800FD8A8_FE4A8.unk01;
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_8005E2F4_5EEF4();
    func_8005E570_5F170();
    func_80088640_89240();
    func_80062268_62E68();
    D_800FA618_FB218 = func_80043510_44110(0xA9, D_800CD2C8_CDEC8);

    func_8005E154_5ED54(1);
    player = BoardPlayerGet(1);
    ((MBModel*)player->unk_24)->attr |= 1;
    func_80043DAC_449AC(player->unk_24);
    func_8005AA48_5B648(D_800FA618_FB218, D_800D34C0_D40C0, ((MBModel*)player->unk_24)->obj->model[0]);
    ((MBModel*)player->unk_24)->attr |= 2;

    func_8005E154_5ED54(0);
    player = BoardPlayerGet(0);
    ((MBModel*)player->unk_24)->attr |= 1;
    func_80043DAC_449AC(player->unk_24);
    ((MBModel*)player->unk_24)->attr |= 2;
    func_8005AA48_5B648(D_800FA618_FB218, D_800D34C8_D40C8, ((MBModel*)player->unk_24)->obj->model[0]);

    /* Tilt the board model to the slope of the player's current step. */
    if (player->cur_space_index != 0 && D_800CD2C0_CDEC0 != 0) {
        from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index - 1));
        to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
        if (!(to->unk_02 & 1)) {
            func_80056658_57258(&from->coords, &to->coords, &diff);
            func_800B3870_B4470(D_800FC834_FD434[D_800FA618_FB218->obj->model[0]].mtx,
                                func_800B727C_B7E7C(func_800B1830_B2430(diff.x * diff.x + diff.z * diff.z), diff.y) +
                                    D_800D34D0_D40D0);
        }
    }
    if (player->cur_space_index != 0) {
        from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index - 1));
        to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
    } else {
        from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
        to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain_index, player->next_space_index));
    }
    func_80056658_57258(&from->coords, &to->coords, &D_800FA618_FB218->rot);

    omAddObj(1000, 0, 0, -1, func_8007414C_74D4C);
    D_800E2104_E2D04 = -1;
    D_800E2106_E2D06 = 0;
    D_800E2108_E2D08 = 0;
    func_800734E8_740E8();
    func_8005E310_5EF10();
    func_8005321C_53E1C(2000.0f, 4000.0f);
}

void func_800744C0_750C0(void) {
    func_8006239C_62F9C();
    func_8008CE5C_8DA5C();
    func_8005E584_5F184();
    func_8005E2FC_5EEFC();
    func_8004340C_4400C();
    func_80054AE8_556E8();
    func_8005429C_54E9C();
    MBDBackKill();
    func_80050AE0_516E0();
}

void func_8007451C_7511C(void) {
    GW_SYSTEM* sys = &GwSystem;
    s32 i;

    sys->current_player_index = 0;
    sys->chosenMinigameIndex = -1;
    sys->unk_25 = 0;
    func_80075144_75D44();
    func_80073410_74010(-1);
    D_800E2120_E2D20 = -1;
    D_800CD2C0_CDEC0 = 1;
    D_800CD2C4_CDEC4 = 0;
    D_800CD2D0_CDED0 = 0;
    if (func_80075390_75F90(6) == 0) {
        D_800FD8AA_FE4AA = 0;
        D_800FD8B5_FE4B5 = 0;
        D_800FD8AB_FE4AB = 3;
        D_800FD8B4_FE4B4 = 0;
        for (i = 0; i < 0x34; i++) {
            if (i >= 4) {
                func_80075424_76024(i);
            }
        }
        for (i = 0; i < 4; i++) {
            BoardPlayerGet(i)->coins = 0;
        }
    }
}

void func_800745FC_751FC(s16 value) {
    D_800E2112_E2D12 = value;
}

s16 func_80074608_75208(void) {
    return D_800E2112_E2D12;
}

void func_80074614_75214(Vec* pos) {
    D_800E2114_E2D14 = *pos;
}

void func_80074638_75238(void) {
    while (1) {
        MBDCameraPos3DSet(&((MBModel*)gPlayers[GwSystem.current_player_index].unk_24)->pos);
        HuPrcVSleep();
    }
}

void func_8007468C_7528C(void) {
    do {
        HuPrcVSleep();
    } while (func_8008F618_90218() != 0);
    while (1) {
        HuPrcVSleep();
        if (D_801011FC_101DFC == 0 && D_800E2104_E2D04 < 0) {
            continue;
        }
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        if (D_800E2108_E2D08 != 0) {
            func_800794A8_7A0A8(0x5A);
        }
        InitFadeOut(D_800E2106_E2D06, 0x10);
        HuPrcSleep(0x11);
        func_800744C0_750C0();
        if (D_800E2104_E2D04 & 0x10) {
            func_800740AC_74CAC();
        }
        if (D_800E2104_E2D04 & 1) {
            func_80073EA0_74AA0(D_800CD2D4_CDED4[D_800FD8AA_FE4AA], 3, 0x192);
            func_80073EA0_74AA0((s16)func_8003F6F0_402F0(GwSystem.chosenMinigameIndex), 0, 0x94);
        }
        if (D_800E2104_E2D04 & 2) {
            func_80073EA0_74AA0(D_800E210C_E2D0C, D_800E2110_E2D10, 0x192);
        }
        _ClearFlag(0x45);
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

const f64 D_800D34D8_D40D8 = -90.0;
const char D_800D34E0_D40E0[] = "CAME";
const char D_800D34E8_D40E8[] = "STAT";

/* The story walk: A at a space (or a walk-on space) steps to the next one. */
/* register allocation only (masked 0): retail has pos in s1 and target in s2; class: register residue. */
#ifdef NON_MATCHING
void func_80074808_75408(void) {
    GW_SYSTEM* sys;
    GW_PLAYER* player;
    SpaceData* space;
    MBModel* model;
    MBModel* jumper;
    Vec* target;
    Vec* pos;
    Process* walker;
    Process* mover;
    Vec dir;
    s16 index;
    u16 nextChain;
    u16 nextSpace;

    sys = &GwSystem;
    player = BoardPlayerGet(0);
    func_80051500_52100();
    func_80053608_54208(3.0f);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80075424_76024(5);
    D_800FDCC8_FE8C8 = 1;
    while (1) {
        sys->chosenMinigameIndex = -1;
        index = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
        space = GetSpaceData(index);
        D_800E2100_E2D00 = func_800556F4_562F4(index, 1);
        if (D_800E2104_E2D04 >= 0) {
            HuPrcSleep(-1);
        }
        while (1) {
            if ((ContBtnTrg[player->port] & 0x8000) || space->space_type == 3) {
                if (D_800CD2D0_CDED0 != 0) {
                    MBHelpWinKill(D_800CD2D0_CDED0);
                    D_800CD2D0_CDED0 = 0;
                }
                nextChain = player->next_chain_index;
                nextSpace = player->next_space_index;
                if (space->space_type == 2 &&
                    GetAbsSpaceIndexFromChainSpaceIndex(nextChain, nextSpace) != D_800E2120_E2D20) {
                    continue;
                }
                D_800E2120_E2D20 = index;
                index = GetAbsSpaceIndexFromChainSpaceIndex(nextChain, nextSpace);
                space = GetSpaceData(index);
                if (space->unk_02 & 1) {
                    MBMotionShiftSet(D_800FA618_FB218, -1, func_80029CE4_2A8E4(D_800FA618_FB218->obj->model[0]), 1, 2);
                    jumper = D_800FA618_FB218;
                    jumper->jumpVel = 4.0f;
                    jumper->jumpAccel = -0.4f;
                    walker = func_80056D80_57980(
                        &jumper->pos,
                        &GetSpaceData(
                             GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain_index, player->next_space_index))
                             ->coords,
                        &jumper->pos, 20);
                    HuPrcChildLink(HuPrcCurrentGet(), walker);
                    HuPrcChildWatch();
                    MBPlayerVibrate(-1, 2);
                } else {
                    MBMotionShiftSet(D_800FA618_FB218, 0, func_80029CE4_2A8E4(D_800FA618_FB218->obj->model[0]), 1, 2);
                    model = D_800FA618_FB218;
                    pos = &model->pos;
                    target =
                        &GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain_index, player->next_space_index))
                             ->coords;
                    mover = func_80056FD4_57BD4(pos, target, pos, 1.9f);
                    HuPrcChildLink(HuPrcCurrentGet(), mover);
                    func_80056658_57258(pos, target, &dir);
                    func_80056B78_57778(&model->rot, &dir, &model->rot, (s32)HuVecDistance(pos, target) / 1.9f);
                    if (D_800CD2C0_CDEC0 != 0) {
                        func_800B3870_B4470(D_800FC834_FD434[model->obj->model[0]].mtx,
                                            func_800B727C_B7E7C(func_800B1830_B2430(dir.x * dir.x + dir.z * dir.z), dir.y) +
                                                D_800D34D8_D40D8);
                    }
                    HuPrcChildWatch();
                    MBMotionShiftSet(D_800FA618_FB218, -1, func_80029CE4_2A8E4(D_800FA618_FB218->obj->model[0]), 1, 2);
                }
                player->cur_chain_index = player->next_chain_index;
                player->cur_space_index = player->next_space_index;
                player->next_space_index++;
                switch (space->space_type) {
                    case 1:
                    case 2:
                        func_800553A8_55FA8(index);
                        PlaySound(0x315);
                        break;
                    case 0:
                        func_800553A8_55FA8(index);
                        PlaySound(0x371);
                        break;
                }
                switch (space->space_type) {
                    case 0:
                    case 2:
                        MBPlayerVibrate(-1, 0);
                        break;
                }
                func_800753D4_75FD4(5);
                break;
            }
            if (D_800CD2D0_CDED0 == 0) {
                D_800CD2D0_CDED0 = func_8004CC7C_4D87C(0x12, 0xA0, 1);
            }
            HuPrcVSleep();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/74AA0", func_80074808_75408);
#endif

void func_80074D28_75928(void) {
    s32 port;

    while (1) {
        HuPrcVSleep();
        if (func_8008F618_90218() == 0 && D_800FDCC8_FE8C8 != 0 && D_800F8C56_F9856 != 3) {
            port = gPlayers[0].port;
            if (ContDStkTrg[port] & 0x1000) {
                break;
            }
        }
    }
    func_80073D2C_7492C(port);
}

void func_80074DB8_759B8(s32 mode) {
    GW_PLAYER* player;

    player = BoardPlayerGet(0);
    func_8005660C_5720C(0, GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
    func_800B3170_B3D70(&D_800FA618_FB218->pos, &((MBModel*)player->unk_24)->pos);
    func_800514F0_520F0();
    func_80053608_54208(1.0f);
    MBCameraSpeedSet(-1.0f);
    func_80029708_2A308(1);
    InitFadeIn(0xFF, 0x10);
    MBDCameraPos3DSet(&((MBModel*)gPlayers[GwSystem.current_player_index].unk_24)->pos);
    switch (mode) {
        case 0:
            omAddPrcObj(func_80074808_75408, 0xEFFF, 0, 0);
            omAddPrcObj(func_8007468C_7528C, 0x1005, 0, 0);
            omAddPrcObj(func_80074638_75238, 0x1005, 0, 0);
            omPrcSetStatBit(omAddPrcObj(func_80074D28_75928, 0x1005, 0, 0), 0x80);
            D_800FDCC8_FE8C8 = 0;
            func_800745FC_751FC(1);
            if (func_80011308_11F08(D_800FA188_FAD88) < 0x7F) {
                func_800498CC_4A4CC();
            }
            break;
        case 1:
            omAddPrcObj(func_8007468C_7528C, 0x1005, 0, 0);
            omAddPrcObj(func_80074638_75238, 0x1005, 0, 0);
            func_800745FC_751FC(1);
            break;
    }
}

void func_80074F7C_75B7C(s32 overlay, s16 event, s16 fade, s16 music) {
    D_800E210C_E2D0C = overlay;
    D_800E2110_E2D10 = event;
    D_800E2104_E2D04 = 2;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
}

void func_80074FAC_75BAC(s8 map, s16 event, s16 fade, s16 music) {
    D_800E2104_E2D04 = 4;
    D_800FD8AA_FE4AA = map;
    D_800E20D2_E2CD2 = event;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
}

void func_80074FDC_75BDC(s16 fade, s16 music) {
    D_800E2104_E2D04 = 8;
    D_800E2106_E2D06 = fade;
    D_800E2108_E2D08 = music;
    func_800740AC_74CAC();
}

void func_80075010_75C10(s32 value) {
    D_800CD2C0_CDEC0 = value;
}

void func_8007501C_75C1C(void) {
    D_800E2104_E2D04 = 1;
    D_800E2108_E2D08 = 1;
    D_800E2106_E2D06 = 9;
    PlaySound(0x325);
    HuPrcSleep(-1);
}

/* Records player 1's board position and the story chapter reached (the highest chapter-clear
   flag, D_800CD300_CDF00[chapter - 1] - 1) in the saved block D_800FD8A8_FE4A8. */
void func_80075060_75C60(void) {
    Unk_800FD8A8* p = &D_800FD8A8_FE4A8;

    D_800FD8B6_FE4B6 = gPlayers[0].cur_chain_index;
    D_800FD8B7_FE4B7 = gPlayers[0].cur_space_index;
    if (func_80075390_75F90(0x32) != 0) {
        D_800FD8B8_FE4B8 = 9;
    } else {
        if (func_80075390_75F90(0x2C) != 0) {
            p->unk10 = 8;
        } else if (func_80075390_75F90(0x26) != 0) {
            p->unk10 = 7;
        } else if (func_80075390_75F90(0x20) != 0) {
            p->unk10 = 6;
        } else if (func_80075390_75F90(0x1A) != 0) {
            p->unk10 = 5;
        } else if (func_80075390_75F90(0x15) != 0) {
            p->unk10 = 4;
        } else if (func_80075390_75F90(0x11) != 0) {
            p->unk10 = 3;
        } else if (func_80075390_75F90(0xC) != 0) {
            p->unk10 = 2;
        } else {
            p->unk10 = 1;
        }
    }
    p->unk11 = -1;
}

/* Puts player 1 back where func_80075060_75C60 recorded (two characters, the chapter). */
/* Retail addresses every gPlayers field through its own lui (no shared base register), as if
   each were its own symbol; same loads and stores. Class: referent (symbol layout). */
#ifdef NON_MATCHING
void func_80075144_75D44(void) {
    gPlayers[0].cur_chain_index = D_800FD8B6_FE4B6;
    gPlayers[0].cur_space_index = D_800FD8B7_FE4B7;
    gPlayers[0].next_chain_index = D_800FD8B6_FE4B6;
    gPlayers[0].next_space_index = D_800FD8B7_FE4B7 + 1;
    gPlayers[0].character = D_800FD8A8_FE4A8.unk00;
    gPlayers[1].character = D_800FD8A9_FE4A9;
    D_800FD2A2_FDEA2 = D_800FD8B8_FE4B8;
    D_800FD840_FE440 = D_800FD8B9_FE4B9;
}
#else
INCLUDE_ASM("asm/nonmatchings/74AA0", func_80075144_75D44);
#endif

/* As func_80075060_75C60 from the current chapter state (D_800FD2A2_FDEA2/D_800FD840_FE440, -1
   when unknown), then copies the block to D_800FD420_FE020. */
void func_800751E0_75DE0(void) {
    Unk_800FD8A8* p = &D_800FD8A8_FE4A8;

    D_800FD8B6_FE4B6 = gPlayers[0].cur_chain_index;
    D_800FD8B7_FE4B7 = gPlayers[0].cur_space_index;
    D_800FD8B8_FE4B8 = D_800FD2A2_FDEA2;
    D_800FD8B9_FE4B9 = D_800FD840_FE440;
    if (D_800FD2A2_FDEA2 == -1) {
        if (func_80075390_75F90(0x32) != 0) {
            D_800FD8B8_FE4B8 = 9;
        } else if (func_80075390_75F90(0x2C) != 0) {
            p->unk10 = 8;
        } else if (func_80075390_75F90(0x26) != 0) {
            p->unk10 = 7;
        } else if (func_80075390_75F90(0x20) != 0) {
            p->unk10 = 6;
        } else if (func_80075390_75F90(0x1A) != 0) {
            p->unk10 = 5;
        } else if (func_80075390_75F90(0x15) != 0) {
            p->unk10 = 4;
        } else if (func_80075390_75F90(0x11) != 0) {
            p->unk10 = 3;
        } else if (func_80075390_75F90(0xC) != 0) {
            p->unk10 = 2;
        } else {
            p->unk10 = 1;
        }
    }
    if (D_800FD840_FE440 == -1) {
        p->unk11 = 0;
    } else if (func_80075390_75F90(D_800CD300_CDF00[p->unk10 - 1] + p->unk11 - 1) == 0) {
        p->unk11--;
    }
    bcopy(&D_800FD8A8_FE4A8, D_800FD420_FE020, sizeof(D_800FD8A8_FE4A8));
}

/* Loads the saved story block (D_800FD420_FE020) back into D_800FD8A8_FE4A8 and applies it. */
void func_80075354_75F54(void) {
    bcopy(D_800FD420_FE020, &D_800FD8A8_FE4A8, 0x12);
    func_80075144_75D44();
    func_80075424_76024(0);
}

s32 func_80075390_75F90(s32 flag) {
    return (s8)D_800FD8AD_FE4AD[flag / 8] & (1 << (flag % 8));
}

void func_800753D4_75FD4(s32 flag) {
    D_800FD8AD_FE4AD[flag / 8] |= (1 << flag % 8);
}

void func_80075424_76024(s32 flag) {
    D_800FD8AD_FE4AD[flag / 8] &= ~(1 << flag % 8);
}

s32 func_80075478_76078(s32 flag) {
    return (s8)D_800FD425_FE025[flag / 8] & (1 << (flag % 8));
}

void func_800754BC_760BC(s32 flag) {
    D_800FD425_FE025[flag / 8] |= (1 << flag % 8);
}

void func_8007550C_7610C(s32 flag) {
    D_800FD425_FE025[flag / 8] &= ~(1 << flag % 8);
}

/* Debug light editor: two windows (the panel and the cursor) and the object that runs it. */
void func_80075560_76160(void) {
    omObjData* obj;

    D_800CD310_CDF10 = omAddObj(0x7FD0, 0, 0, -1, func_80075688_76288);
    omSetStatBit(D_800CD310_CDF10, 0xA0);
    obj = D_800CD310_CDF10;
    LIGHTEDIT_WIN(obj)[0] = pfWinCreate(14, 14, 0x132, 0x22, 0xDF70);
    LIGHTEDIT_WIN(obj)[1] =
        pfWinCreate(D_800CD324_CDF24[D_800CD316_CDF16], D_800CD330_CDF30[D_800CD316_CDF16],
                    D_800CD33C_CDF3C[D_800CD316_CDF16], D_800CD348_CDF48[D_800CD316_CDF16], (D_800CD318_CDF18 << 24) | 0x80);
    D_800CD319_CDF19 = 0;
}

void func_80075638_76238(void) {
    omObjData* obj = D_800CD310_CDF10;

    if (obj != NULL) {
        pfWinKill(LIGHTEDIT_WIN(obj)[0]);
        pfWinKill(LIGHTEDIT_WIN(obj)[1]);
        omDelObj(D_800CD310_CDF10);
        D_800CD310_CDF10 = NULL;
    }
}

const char D_800D34F0_D40F0[] = "LIGHT%1d DIR%4d,%4d,%4d  STAT %s";
const char D_800D3514_D4114[] = "COLOR    RED %3d GREEN %3d BLUE %3d";
/* The light editor's frame: A on STAT (cursor 1) toggles the stick mode, which turns the light's
   direction; otherwise the cursor (3 x 2 cells) picks LIGHT / STAT / R / G / B and up/down change them. */
void func_80075688_76288(omObjData* object) {
    s16* panel;
    s16* cursor;
    char* stat;
    s16 col;
    s16 row;
    u16 btn;
    f32 x;
    f32 y;
    f32 z;
    f32 yaw;
    f32 pitch;
    f32 sinPitch;
    f32 cosPitch;
    f32 sinYaw;
    f32 cosYaw;

    panel = &LIGHTEDIT_WIN(D_800CD310_CDF10)[0];
    cursor = &LIGHTEDIT_WIN(D_800CD310_CDF10)[1];
    stat = D_800CD31C_CDF1C[(D_800FA620_FB220->light[D_800CD314_CDF14].stat ^ 1) & 1];
    fontcolor = 14;
    sprintf(pfStrBuf, D_800D34F0_D40F0, D_800CD314_CDF14, D_800FA620_FB220->light[D_800CD314_CDF14].x, D_800FA620_FB220->light[D_800CD314_CDF14].y, D_800FA620_FB220->light[D_800CD314_CDF14].z, stat);
    DrawDebugText(16, 16, pfStrBuf);
    sprintf(pfStrBuf, D_800D3514_D4114, D_800FA620_FB220->light[D_800CD314_CDF14].r, D_800FA620_FB220->light[D_800CD314_CDF14].g, D_800FA620_FB220->light[D_800CD314_CDF14].b);
    DrawDebugText(16, 24, pfStrBuf);
    switch (D_800CD319_CDF19) {
        case 0:
            if ((ContBtnTrg[0] & 0x8000) && D_800CD316_CDF16 == 1) {
                pfWinData[*panel].rgba = 0x7070;
                D_800CD318_CDF18 = 0xF0;
                D_800CD31A_CDF1A = -4;
                D_800CD319_CDF19 = 1;
                break;
            }
            D_800CD318_CDF18 += D_800CD31A_CDF1A;
            if (D_800CD31A_CDF1A < 0) {
                if (D_800CD318_CDF18 <= 0x80) {
                    D_800CD31A_CDF1A = 4;
                }
            } else if (D_800CD318_CDF18 >= 0xF0) {
                D_800CD31A_CDF1A = -4;
            }
            btn = D_800FC9E0_FD5E0[0];
            row = D_800CD316_CDF16 / 3;
            col = D_800CD316_CDF16 % 3;
            if (btn & 0x200) {
                if (col == 0) {
                    D_800CD316_CDF16 = row * 3 + 2;
                } else {
                    D_800CD316_CDF16--;
                }
            } else if (btn & 0x100) {
                if (col == 2) {
                    D_800CD316_CDF16 = row * 3;
                } else {
                    D_800CD316_CDF16++;
                }
            } else if (btn & 0x800) {
                if (row == 0) {
                    D_800CD316_CDF16 = col + 3;
                } else {
                    D_800CD316_CDF16 -= 3;
                }
            } else if (btn & 0x400) {
                if (row == 1) {
                    D_800CD316_CDF16 = col;
                } else {
                    D_800CD316_CDF16 += 3;
                }
            }
            switch (D_800CD316_CDF16) {
                case 0:
                    if ((D_800FD410_FE010[0] & 4) && D_800CD314_CDF14 >= 2) {
                        D_800CD314_CDF14--;
                    }
                    if ((D_800FD410_FE010[0] & 8) && D_800CD314_CDF14 < D_800FA620_FB220->count) {
                        D_800CD314_CDF14++;
                    }
                    break;
                case 2:
                    if (D_800FD410_FE010[0] & 0x800C) {
                        if (D_800FA620_FB220->light[D_800CD314_CDF14].stat & 1) {
                            func_80026D50_27950(D_800CD314_CDF14, 1, 0);
                        } else {
                            func_80026D50_27950(D_800CD314_CDF14, 1, 1);
                        }
                    }
                    break;
                case 3:
                    if (D_800FD410_FE010[0] & 4) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].r--;
                    }
                    if (D_800FD410_FE010[0] & 8) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].r++;
                    }
                    if (D_800FD410_FE010[0] & 2) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].r -= 5;
                    }
                    if (D_800FD410_FE010[0] & 1) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].r += 5;
                    }
                    break;
                case 4:
                    if (D_800FD410_FE010[0] & 4) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].g--;
                    }
                    if (D_800FD410_FE010[0] & 8) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].g++;
                    }
                    if (D_800FD410_FE010[0] & 2) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].g -= 5;
                    }
                    if (D_800FD410_FE010[0] & 1) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].g += 5;
                    }
                    break;
                case 5:
                    if (D_800FD410_FE010[0] & 4) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].b--;
                    }
                    if (D_800FD410_FE010[0] & 8) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].b++;
                    }
                    if (D_800FD410_FE010[0] & 2) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].b -= 5;
                    }
                    if (D_800FD410_FE010[0] & 1) {
                        D_800FA620_FB220->light[D_800CD314_CDF14].b += 5;
                    }
                    break;
            }
            break;
        case 1:
            if (ContBtnTrg[0] & 0xC000) {
                D_800CD319_CDF19 = 0;
                pfWinData[*panel].rgba = 0xDF70;
            }
            x = D_800FA620_FB220->light[D_800CD314_CDF14].x;
            y = D_800FA620_FB220->light[D_800CD314_CDF14].y;
            z = D_800FA620_FB220->light[D_800CD314_CDF14].z;
            yaw = -ContStkX[0] / 10;
            if (yaw >= 360.0f) {
                yaw -= 360.0f;
            } else if (yaw < 0.0f) {
                yaw += 360.0f;
            }
            pitch = -ContStkY[0] / 10;
            if (pitch >= 360.0f) {
                pitch -= 360.0f;
            } else if (pitch < 0.0f) {
                pitch += 360.0f;
            }
            sinPitch = HuMathSin(pitch);
            cosPitch = func_800B7890_B8490(pitch);
            sinYaw = HuMathSin(yaw);
            cosYaw = func_800B7890_B8490(yaw);
            x = x * cosYaw - z * sinYaw;
            y = x * sinPitch * sinYaw + y * cosPitch + z * sinPitch * cosYaw;
            z = x * cosPitch * sinYaw - y * sinPitch + z * cosPitch * cosYaw;
            func_80026E00_27A00(D_800CD314_CDF14, x, y, z);
            break;
    }
    pfWinData[*cursor].rgba = (D_800CD318_CDF18 << 24) | 0x80;
    pfWinData[*cursor].xPosStart = D_800CD324_CDF24[D_800CD316_CDF16];
    pfWinData[*cursor].yPosStart = D_800CD330_CDF30[D_800CD316_CDF16];
    pfWinData[*cursor].width = D_800CD33C_CDF3C[D_800CD316_CDF16];
    pfWinData[*cursor].height = D_800CD348_CDF48[D_800CD316_CDF16];
}
