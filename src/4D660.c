#include "common.h"
#include "game/malloc.h"
#include "game/board.h"
#include "game/gamework.h"

/* Board label windows, player swap and item helpers. C from MP1 src/467E0.c (func_80045CE4 ..
   func_80045E6C), src/46AE0.c (func_80045EE0 .. func_800466C0), src/3CED0.c (func_8003D20C) and MP3
   ovl_80_shared_board F5E80.c (MBItem*); the item handlers func_8004D600 .. func_8004DAC4 are fresh.
   This unit's rodata (0xD3430-0xD38AC) is C: the strings below, and its two number formats
   at the end in 4F650.c. */

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 mode;
    /* 0x02 */ s16 y;
    /* 0x04 */ omObjData* obj;
    /* 0x08 */ s16 win;
    /* 0x0C */ u8* str;
    /* 0x10 */ char* extra;
} LabelWin;

typedef struct {
    /* 0x00 */ u8* str;
    /* 0x04 */ s16 len;
} LabelDef;

extern LabelDef D_800CBDF0_CC9F0[]; /* label texts per language (GW_COMMON unk01) */
extern LabelDef D_800CBE90_CCA90[];
extern LabelDef D_800CBF30_CCB30[];
extern LabelDef D_800CBF98_CCB98[];
extern s16 D_8010002A_100C2A;
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_80089308_89F08(s16 win_id, void* arg1, s8 arg2);
void func_80089A7C_8A67C(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008D4DC_8E0DC(u8* arg0, u8* arg1);
void func_80089A48_8A648(s16 winId, s8 arg1);
void func_80089284_89E84(s16, s32, s32);
void func_8004CC14_4D814(omObjData* obj);
extern s16 D_800DF710_E0310;
extern s32 D_80100028_100C28;
void func_8004CA14_4D614(s32 player, s32 coins);
void func_8004CA34_4D634(s32, s32);
void func_800614B4_620B4(s32, s32);
s16 func_800797DC_7A3DC(s32, s16);
s32 func_80046D2C_4792C(s32);
void func_8004655C_4715C(s32);
void func_8005670C_5730C(Vec*);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
void MBKSuitMotionSet(s16 arg0, s32 arg1);
void func_8004E89C_4F49C(void);
extern s32 (*D_800CC010_CCC10[])(void); /* item use handlers, by item */
void MBStatusItemDispSetAll(s32 arg0);
s32 PlayerIsCPU(s16);
void func_80042B38_43738(s32);
void func_80060210_60E10(s32);
s32 func_800609D8_615D8(void);
s32 func_8006286C_6346C(s32 player);
void func_80067C6C_6886C(s32 arg0);
void MBItemDescExec(s32 arg0);
extern s16 D_800F8D16_F9916; /* board work word 0x19 */
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
void func_80056368_56F68(s16, u32, char*, char*, char*, char*, char*); /* message with up to five strings */
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
void func_800890CC_89CCC(s16, void*, s32, s32); /* a message id or a string */
void func_8008E978_8F578(s16);
void func_8008AD44_8B944(s16);
void func_8008EBE4_8F7E4(s16, s16);
void func_8008EED8_8FAD8(s16, s16);
extern s32 D_800CC03C_CCC3C;
extern s32 D_800CC040_CCC40;
extern s32 D_800CC044_CCC44;
extern s32 D_800CC048_CCC48;


/* .rodata (0xD3430-0xD38A0): label strings (SJIS). */
const char D_800D2830_D3430[] = "\203\277\201c\203t\201K\203\215\203b\203N";
const char D_800D2840_D3440[] = "\203\277\201c\202\267\202\267\202\336";
const char D_800D284C_D344C[] = "\207\210\201c\202\334\202\246\202\314\203A\203C\203e\203\200";
const char D_800D2860_D3460[] = "\207\211\201c\202\302\202\253\201J\202\314\203A\203C\203e\203\200";
const char D_800D2878_D3478[] = "\207\205\201c\202\271\202\302\202\337\202\242";
const char D_800D2888_D3488[] = "\203\277\201c\202\302\202\251\202\244";
const char D_800D2894_D3494[] = "\203\300\201c\203A\203C\203e\203\200";
const char D_800D28A4_D34A4[] = "\211E\201c\203P\201J\201[\203\200\202\311\202\340\202\306\201J\202\351";
const char D_800D28BC_D34BC[] = "\203\244\201c\202\271\201J\202\361\202\275\202\242";
const char D_800D28CC_D34CC[] = "\203\277\201c\202\273\202\244\202\263\202\314\202\253\202\350\202\251\202\246";
const char D_800D28E4_D34E4[] = "\203\277\201c\202\273\202\244\202\263\202\360\202\253\202\350\202\251\202\246\202\351";
const char D_800D28FC_D34FC[] = "\203\300\201c\202\334\202\246\202\314\202\251\201J\202\337\202\361\202\311\202\340\202\306\201J\202\351";
const char D_800D291C_D351C[] = "\203\300\201c\203P\201J\201[\203\200\202\360\202\342\202\337\202\351";
const char D_800D2934_D3534[] = "\201m\202\314\202\261\202\350\207@\203}\203X\201n";
const char D_800D2948_D3548[] = "\216n\201c\203P\201J\201[\203\200\202\311\202\340\202\306\201J\202\351";
const char D_800D2960_D3560[] = "\203\300\201c\202\340\202\306\201J\202\351";
const char D_800D2970_D3570[] = "\211E\201c\203}\203b\203t\201K";
const char D_800D2980_D3580[] = "\203\277\201c\203T\203C\203R\203\215";
const char D_800D2990_D3590[] = "\203\277\201c\202\257\202\301\202\304\202\242";
const char D_800D29A0_D35A0[] = "\201\247\201c\202\246\202\347\202\323\201J";
const char D_800D29B0_D35B0[] = "\203\277\201c\202g\202\211\202\224\201@\202a\202\214\202\217\202\203\202\213";
const char D_800D29C8_D35C8[] = "\203\277\201c\202o\202\222\202\217\202\203\202\205\202\205\202\204";
const char D_800D29DC_D35DC[] = "\207\210\201c\202k\202\201\202\223\202\224\201@\202h\202\224\202\205\202\215";
const char D_800D29F4_D35F4[] = "\207\211\201c\202m\202\205\202\230\202\224\201@\202h\202\224\202\205\202\215";
const char D_800D2A0C_D360C[] = "\207\205\201c\202d\202\230\202\220\202\214\202\201\202\216\202\201\202\224\202\211\202\217\202\216";
const char D_800D2A28_D3628[] = "\203\277\201c\202t\202\223\202\205";
const char D_800D2A34_D3634[] = "\203\300\201c\202h\202\224\202\205\202\215";
const char D_800D2A44_D3644[] = "\211E\201c\202b\202\217\202\216\202\224\202\211\202\216\202\225\202\205";
const char D_800D2A5C_D365C[] = "\203\244\201c\202a\202\217\202\201\202\222\202\204";
const char D_800D2A6C_D366C[] = "\203\277\201c\202b\202\217\202\216\202\224\202\222\202\217\202\214\201@\202r\202\205\202\224\202\224\202\211\202\216\202\207\202\223";
const char D_800D2A94_D3694[] = "\203\300\201c\202p\202\225\202\211\202\224";
const char D_800D2AA4_D36A4[] = "\207@\201@\202l\202\217\202\226\202\205\202\223\201@\202k\202\205\202\206\202\224";
const char D_800D2AC0_D36C0[] = "\216n\201c\202b\202\217\202\216\202\224\202\211\202\216\202\225\202\205";
const char D_800D2AD8_D36D8[] = "\203\300\201c\202a\202\201\202\203\202\213";
const char D_800D2AE8_D36E8[] = "\211E\201c\202l\202\201\202\220";
const char D_800D2AF4_D36F4[] = "\203\277\201c\202g\202\211\202\224\201@\202c\202\211\202\203\202\205\201@\202a\202\214\202\217\202\203\202\213";
const char D_800D2B18_D3718[] = "\203\277\201c\202c\202\205\202\203\202\211\202\204\202\205";
const char D_800D2B2C_D372C[] = "\201\247\201c\202r\202\205\202\214\202\205\202\203\202\224";
const char D_800D2B40_D3740[] = "\211E\201@\202o\202\214\202\201\202\216\201@\202f\202\205\202\216\202\205\202\222\202\201\202\214";
const char D_800D2B60_D3760[] = "\203\277\201@\202q\202\205\202\207\202\214\202\201\202\207\202\205\202\223";
const char D_800D2B78_D3778[] = "";
const char D_800D2B7C_D377C[] = "\207@\201@\202b\202\201\202\223\202\205\202\223";
const char D_800D2B8C_D378C[] = "\216n\201@\202q\202\205\202\224\202\217\202\225\202\222";
const char D_800D2BA0_D37A0[] = "\203\300\201@\202q\202\205\202\224\202\217\202\225\202\222";
const char D_800D2BB4_D37B4[] = "\203\300\201@\202b\202\201\202\222\202\224\202\205";
const char D_800D2BC4_D37C4[] = "\203\277\201@\202a\202\214\202\217\202\203";
const char D_800D2BD4_D37D4[] = "\201\247\201@\202b\202\210\202\217\202\211\202\230";
const char D_800D2BE4_D37E4[] = "\211E\201@\202\323\202\202\202\205\202\222\202\223\202\211\202\203\202\210\202\224";
const char D_800D2BFC_D37FC[] = "\203\277\201@\202d\202\211\202\216\202\223\202\224\202\205\202\214\202\214\202\225\202\216\202\207\202\205\202\216";
const char D_800D2C1C_D381C[] = "\207@\201@\202l\202\217\202\226\202\205\202\223";
const char D_800D2C2C_D382C[] = "\216n\201@\202y\202\225\202\222\203t\202\203\202\213\201@\202\232\202\225\202\215\201@\202r\202\220\202\211\202\205\202\214";
const char D_800D2C54_D3854[] = "\203\300\201@\202y\202\225\202\222\203t\202\203\202\213";
const char D_800D2C68_D3868[] = "\203\300\201@\202j\202\201\202\222\202\224\202\205";
const char D_800D2C78_D3878[] = "\203\277\201@\202v\203t\202\222\202\206\202\205\202\214\202\216";
const char D_800D2C8C_D388C[] = "\201\247\201@\202v\203I\202\210\202\214\202\205\202\216";
/* 0xD38A0-0xD38AC (D_800D2CA0_D38A0 "\x03%2d\x08", D_800D2CA8_D38A8 "%2d") is defined in 4F650.c: the
   link (SUBALIGN(8)) cannot start 4F650's piece at its 4-aligned 0xD38AC. */
extern const char D_800D2CA0_D38A0[];
extern const char D_800D2CA8_D38A8[];
void func_80047A50_48650(s32);
void func_800495D8_4A1D8(s32, s32);
s16 func_80046F98_47B98(s32);
s32 func_80064200_64E00(GW_PLAYER* player);
void func_8006508C_65C8C(void);
void func_800558E8_564E8(s16 arg0);
extern BattleTargets D_800F8D1A_F991A;
/* Item use handlers. */
s32 func_8004D620_4E220(void);
s32 func_8004D6A0_4E2A0(void);
s32 func_8004D734_4E334(void);
s32 MBItemRobBoxExec(void);
s32 func_8004D780_4E380(void);
s32 func_8004D7A0_4E3A0(void);
s32 func_8004D858_4E458(void);
s32 func_8004D8B0_4E4B0(void);
s32 func_8004D944_4E544(void);
s32 func_8004DA2C_4E62C(void);
s32 func_8004DAC4_4E6C4(void);

/* .data (0xCC9F0-0xCCC90): label texts per language (0 default, 2, 3, 4). */
LabelDef D_800CBDF0_CC9F0[] = {
    { (u8*)D_800D29A0_D35A0, 5 }, { (u8*)D_800D2990_D3590, 6 }, { (u8*)D_800D2980_D3580, 6 },
    { (u8*)D_800D2970_D3570, 5 }, { (u8*)D_800D2960_D3560, 5 }, { (u8*)D_800D2948_D3548, 9 },
    { (u8*)D_800D2934_D3534, 7 }, { (u8*)D_800D291C_D351C, 9 }, { (u8*)D_800D28FC_D34FC, 12 },
    { (u8*)D_800D28E4_D34E4, 11 }, { (u8*)D_800D28CC_D34CC, 10 }, { (u8*)D_800D28BC_D34BC, 6 },
    { (u8*)D_800D28A4_D34A4, 9 }, { (u8*)D_800D2894_D3494, 6 }, { (u8*)D_800D2888_D3488, 5 },
    { (u8*)D_800D2878_D3478, 6 }, { (u8*)D_800D2860_D3460, 9 }, { (u8*)D_800D284C_D344C, 9 },
    { (u8*)D_800D2840_D3440, 5 }, { (u8*)D_800D2830_D3430, 6 },
};
LabelDef D_800CBE90_CCA90[] = {
    { (u8*)D_800D2B2C_D372C, 4 }, { (u8*)D_800D2B18_D3718, 4 }, { (u8*)D_800D2AF4_D36F4, 7 },
    { (u8*)D_800D2AE8_D36E8, 4 }, { (u8*)D_800D2AD8_D36D8, 4 }, { (u8*)D_800D2AC0_D36C0, 6 },
    { (u8*)D_800D2AA4_D36A4, 7 }, { (u8*)D_800D2A94_D3694, 4 }, { (u8*)D_800D2AD8_D36D8, 4 },
    { (u8*)D_800D2A6C_D366C, 9 }, { (u8*)D_800D2A6C_D366C, 9 }, { (u8*)D_800D2A5C_D365C, 4 },
    { (u8*)D_800D2A44_D3644, 6 }, { (u8*)D_800D2A34_D3634, 4 }, { (u8*)D_800D2A28_D3628, 4 },
    { (u8*)D_800D2A0C_D360C, 6 }, { (u8*)D_800D29F4_D35F4, 6 }, { (u8*)D_800D29DC_D35DC, 6 },
    { (u8*)D_800D29C8_D35C8, 5 }, { (u8*)D_800D29B0_D35B0, 6 },
};
LabelDef D_800CBF30_CCB30[] = {
    { (u8*)D_800D2BD4_D37D4, 3 }, { (u8*)D_800D2BC4_D37C4, 3 }, { (u8*)D_800D2BC4_D37C4, 3 },
    { (u8*)D_800D2BB4_D37B4, 3 }, { (u8*)D_800D2BA0_D37A0, 4 }, { (u8*)D_800D2B8C_D378C, 4 },
    { (u8*)D_800D2B7C_D377C, 4 }, { (u8*)D_800D2B78_D3778, 0 }, { (u8*)D_800D2B78_D3778, 0 },
    { (u8*)D_800D2B60_D3760, 5 }, { (u8*)D_800D2B78_D3778, 0 }, { (u8*)D_800D2B40_D3740, 7 },
    { (u8*)D_800D2B78_D3778, 0 },
};
LabelDef D_800CBF98_CCB98[] = {
    { (u8*)D_800D2C8C_D388C, 4 }, { (u8*)D_800D2C78_D3878, 4 }, { (u8*)D_800D2C78_D3878, 4 },
    { (u8*)D_800D2C68_D3868, 4 }, { (u8*)D_800D2C54_D3854, 4 }, { (u8*)D_800D2C2C_D382C, 9 },
    { (u8*)D_800D2C1C_D381C, 4 }, { (u8*)D_800D2B78_D3778, 0 }, { (u8*)D_800D2B78_D3778, 0 },
    { (u8*)D_800D2BFC_D37FC, 7 }, { (u8*)D_800D2B78_D3778, 0 }, { (u8*)D_800D2BE4_D37E4, 5 },
    { (u8*)D_800D2B78_D3778, 0 },
};
/* Item prices, by item (board overlays' shops). */
u8 D_800CC000[] = { 10, 10, 15, 0, 15, 15, 20, 0, 0, 30 };
s32 (*D_800CC00C_CCC0C)(void) = func_8004D620_4E220; /* unreferenced: the handler before the table */
s32 (*D_800CC010_CCC10[])(void) = {
    func_8004D6A0_4E2A0, func_8004D734_4E334, MBItemRobBoxExec, func_8004D780_4E380,
    func_8004D7A0_4E3A0, func_8004D858_4E458, func_8004D8B0_4E4B0, func_8004D944_4E544,
    func_8004DA2C_4E62C, func_8004DAC4_4E6C4,
};
s32 D_800CC038_CCC38 = 0;
s32 D_800CC03C_CCC3C = 0;
s32 D_800CC040_CCC40 = 0;
s32 D_800CC044_CCC44 = 0;
s32 D_800CC048_CCC48 = 0;
s32 D_800CC04C_CCC4C[] = { 0x1FA, 0x1FB, 0x1FD, 0x1FE, 0x1FF, 0x200, 0x201, 0x202, 0x203, 0x204 };
s16 D_800CC074_CCC74[] = { 11, 9, 13, 14, 15, 16, 12, 17, 18, 19 };


/* MP1 func_80045BE0 (src/467E0.c): MP2 picks the label table by language. */
void func_8004CA60_4D660(LabelWin* w) {
    LabelDef* def;

    switch (D_800F8C60.unk01) {
    case 0:
    default:
        def = &D_800CBDF0_CC9F0[w->type];
        break;
    case 2:
        def = &D_800CBE90_CCA90[w->type];
        break;
    case 3:
        def = &D_800CBF30_CCB30[w->type];
        break;
    case 4:
        def = &D_800CBF98_CCB98[w->type];
        break;
    }
    w->win = func_800888A8_894A8(160 - (def->len * 11 + 16) / 2, w->y, def->len * 11 + 16, 20, 0, 0);
    if (w->extra != NULL) {
        func_80089308_89F08(w->win, w->extra, 0);
    }
    func_80089A7C_8A67C(w->win, 5);
    func_80089B2C_8A72C(w->win, 0);
    w->str = HuMemMemoryAllocTemp(def->len * 2 + 1);
    func_8008D4DC_8E0DC(w->str, def->str);
    func_80089A48_8A648(w->win, 0);
    func_80089284_89E84(w->win, 0, 0x20000);
    func_800890CC_89CCC(w->win, w->str, -1, -1);
}

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

/* MP1 func_80045D84 (src/467E0.c; s16 type, s16 y, s8 mode there): none for player 4. Host: returns
   the work pointer as s32. */
s32 func_8004CC7C_4D87C(s32 type, s32 y, s32 mode) {
    LabelWin* w;

    if (GwSystem.current_player_index == 4) {
        return 0;
    }
    w = HuMemMemoryAllocTemp(sizeof(LabelWin));
    if (w != NULL) {
        w->type = type;
        w->y = y;
        w->mode = mode;
        w->obj = omAddObj(0x100, 0, 0, -1, func_8004CC14_4D814);
        w->obj->unk_50 = w;
        omSetStatBit(w->obj, 0x80);
        w->win = -1;
        if ((s16)type == 6) {
            w->extra = HuMemMemoryAllocTemp(8);
            sprintf(w->extra, D_800D2CA0_D38A0, D_8010002A_100C2A);
        } else {
            w->extra = NULL;
        }
    }
    return (s32)w;
}

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

s32 func_8004CDF8_4D9F8(s16 a, s16 b) {
    return a != b;
}

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
    func_80056368_56F68(-1, 0x1E5, str0, str1, 0, 0, 0);
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

/* The player the item is used on (MP3 func_800E2954). */
s16 func_8004D600_4E200(void) {
    return D_800DF710_E0310;
}

void func_8004D60C_4E20C(s32 index, void (*fn)(void)) {
    MBItemSubFunctions[index] = fn;
}

/* Item 0 handler (before the table): "no item" message with the player's name. */
s32 func_8004D620_4E220(void) {
    char str[16];

    str[0] = 0x18;
    str[1] = gPlayers[GwSystem.current_player_index].character;
    str[2] = 0;
    func_80056368_56F68(-1, 0x1EB, str, 0, 0, 0, 0);
    MBDlgWinClose();
    func_80056168_56D68();
    return 1;
}

/* Mushroom (MP3 MBItemKinokoExec without the reverse checks). */
s32 func_8004D6A0_4E2A0(void) {
    func_80047A50_48650(GwSystem.current_player_index);
    MBItemSubFunctions[6]();
    gPlayers[GwSystem.current_player_index].item = -1;
    func_800495D8_4A1D8(GwSystem.current_player_index, 2);
    MBPlayerVibrate(-1, 2);
    func_80046F98_47B98(GwSystem.current_player_index);
    HuPrcSleep(15);
    return 1;
}

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

/* Dueling glove (item 4; MP3 MBItemKettouExec). */
s32 func_8004D7A0_4E3A0(void) {
    s32 one = 1;

    MBItemSubFunctions[7]();
    gPlayers[GwSystem.current_player_index].item = -1;
    D_800F8D1A_F991A.targets = ~(one << GetCurrentPlayerIndex());
    D_800F8D1A_F991A.attacker = one << GetCurrentPlayerIndex();
    if (func_80064200_64E00(BoardPlayerGet(-1)) != 0) {
        func_8006508C_65C8C();
        func_80078FF8_79BF8();
        HuPrcSleep(-1);
    }
    return 1;
}

/* Warp block (item 5). */
s32 func_8004D858_4E458(void) {
    gPlayers[GwSystem.current_player_index].item = -1;
    func_8006508C_65C8C();
    MBItemSubFunctions[2]();
    return 1;
}

/* Golden mushroom (MP3 MBItemSKinokoExec without the reverse checks). */
s32 func_8004D8B0_4E4B0(void) {
    func_80047A50_48650(GwSystem.current_player_index);
    MBItemSubFunctions[6]();
    gPlayers[GwSystem.current_player_index].item = -1;
    func_800495D8_4A1D8(GwSystem.current_player_index, 3);
    MBPlayerVibrate(-1, 3);
    func_80046F98_47B98(GwSystem.current_player_index);
    HuPrcSleep(15);
    return 1;
}

/* Boo bell (item 7; MP3 MBItemTereBellExec). */
s32 func_8004D944_4E544(void) {
    GW_PLAYER* player = BoardPlayerGet(-1);

    MBItemSubFunctions[7]();
    func_800558E8_564E8(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    MBItemSubFunctions[0]();
    gPlayers[GwSystem.current_player_index].item = -1;
    return 1;
}

/* Bowser suit (item 8; MP3 MBItemKSuitExec). */
s32 func_8004DA2C_4E62C(void) {
    MBItemSubFunctions[6]();
    MBItemSubFunctions[4]();
    gPlayers[GwSystem.current_player_index].turn_status = 1;
    gPlayers[GwSystem.current_player_index].item = -1;
    return 1;
}

/* Magic lamp (item 9). */
s32 func_8004DAC4_4E6C4(void) {
    gPlayers[GwSystem.current_player_index].item = -1;
    func_8006508C_65C8C();
    MBItemSubFunctions[1]();
    return 1;
}

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

/* NON_MATCHING: the order of the pad pointer's address sum (masked 2). */
#ifdef NON_MATCHING
/* Item menu process (func_8004DE7C_4EA7C): A or a CPU uses the item, Z describes it, B closes. */
void func_8004DC0C_4E80C(void) {
    s32 player = (s32)HuPrcCurrentGet()->user_data;
    s32 port = gPlayers[player].port;
    u16* pad;

    func_80060210_60E10(0x19);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(1);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    func_8004DB1C_4E71C();
    pad = &ContDStkTrg[port];
    while (1) {
        if ((*pad & 0x8000) || PlayerIsCPU(player)) {
            func_8004DBA8_4E7A8();
            if (D_800CC010_CCC10[gPlayers[player].item]() != 0) {
                break;
            }
            func_8004DB1C_4E71C();
        }
        if (*pad & 0x4000) {
            break;
        }
        if (*pad & 8) {
            func_8004DBA8_4E7A8();
            MBItemDescExec(player);
            func_8004DB1C_4E71C();
        }
        if (*pad & 0x10) {
            func_8004DBA8_4E7A8();
            func_80067C6C_6886C(port);
            func_8004DB1C_4E71C();
            D_800F851A_F911A = 1;
            func_80078EC8_79AC8();
        }
        if (*pad & 0x2000) {
            func_8004DBA8_4E7A8();
            func_80042B38_43738(port);
            func_8004DB1C_4E71C();
            D_800F851A_F911A = 1;
            func_80078EC8_79AC8();
        }
        HuPrcVSleep();
    }
    func_8004DBA8_4E7A8();
    if (func_8006286C_6346C(0) != 0) {
        func_80060210_60E10(0x19);
        while (func_800609D8_615D8() != 0) {
            HuPrcVSleep();
        }
        MBStatusItemDispSetAll(0);
        func_80060210_60E10(0x1A);
        while (func_800609D8_615D8() != 0) {
            HuPrcVSleep();
        }
    }
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/4D660", func_8004DC0C_4E80C);
#endif

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

/* Item view process (func_8004E10C_4ED0C): Z describes the item, B closes. */
void func_8004DF3C_4EB3C(void) {
    s32 player = (s32)HuPrcCurrentGet()->user_data;
    u8 port = gPlayers[player].port;

    func_80060210_60E10(0x19);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(1);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    D_800CC03C_CCC3C = func_8004CC7C_4D87C(4, 0xA0, 0);
    D_800CC048_CCC48 = func_8004CC7C_4D87C(0xF, 0xAE, 0);
    while (1) {
        if (ContDStkTrg[port] & 0x4000) {
            break;
        }
        if (ContDStkTrg[port] & 8) {
            MBHelpWinKill(D_800CC03C_CCC3C);
            MBHelpWinKill(D_800CC048_CCC48);
            MBItemDescExec(player);
            D_800CC03C_CCC3C = func_8004CC7C_4D87C(4, 0xA0, 0);
            D_800CC048_CCC48 = func_8004CC7C_4D87C(0xF, 0xAE, 0);
        }
        HuPrcVSleep();
    }
    MBHelpWinKill(D_800CC03C_CCC3C);
    MBHelpWinKill(D_800CC048_CCC48);
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

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

/* NON_MATCHING: register allocation; retail rebuilds the 0x18 text code per store (masked 16). */
#ifdef NON_MATCHING
/* Koopa suit: take up to 20 coins from every other player on the current player's space. */
void func_8004E4FC_4F0FC(void) {
    s8 targets[4];
    Vec dir;
    char str0[16];
    char str1[16];
    char str2[16];
    s32 cur;
    GW_PLAYER* player;
    s32 count;
    s32 i;
    s32 coins;
    s32 total;
    s32 suit;

    cur = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    if (gPlayers[cur].turn_status != 0) {
        count = 0;
        for (i = 0; i < 4; i++) {
            if (i == cur) {
                continue;
            }
            if (GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[cur].cur_chain_index, gPlayers[cur].cur_space_index) ==
                GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[i].cur_chain_index, gPlayers[i].cur_space_index)) {
                targets[count++] = i;
            }
        }
        if (count != 0) {
            suit = func_80046D2C_4792C(cur);
            MBKSuitMotionSet(-1, 2);
            func_8005670C_5730C(&dir);
            func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
            HuPrcSleep(8);
            total = 0;
            for (i = 0; i < count;) {
                if (gPlayers[targets[i]].coins != 0) {
                    coins = 20;
                    if (gPlayers[targets[i]].coins < 20) {
                        coins = gPlayers[targets[i]].coins;
                    }
                    str0[0] = 0x18;
                    str0[1] = gPlayers[targets[i]].character;
                    str0[2] = 0;
                    sprintf(str1, D_800D2CA8_D38A8, coins);
                    str2[0] = 0x18;
                    str2[1] = gPlayers[cur].character;
                    str2[2] = 0;
                    func_80056368_56F68(-1, 0x1E7, str0, str1, str2, 0, 0);
                    MBDlgWinClose();
                    total += coins;
                    func_80056168_56D68();
                    func_800797DC_7A3DC(0xFC, targets[i]);
                    func_8004CA14_4D614(targets[i], -coins);
                    func_800614B4_620B4(targets[i], -coins);
                    HuPrcSleep(30);
                    i++;
                } else {
                    str0[0] = 0x18;
                    str0[1] = gPlayers[targets[i]].character;
                    str0[2] = 0;
                    func_80056368_56F68(-1, 0x1E8, str0, 0, 0, 0, 0);
                    i++;
                    MBDlgWinClose();
                    func_80056168_56D68();
                }
            }
            if (total != 0) {
                func_8004CA34_4D634(cur, total);
                func_800614B4_620B4(cur, total);
                HuPrcSleep(30);
            }
            if (suit != 0) {
                func_8004655C_4715C(GwSystem.current_player_index);
            }
            MBKSuitMotionSet(0, 2);
        }
    }
    if (D_80100028_100C28 == 0) {
        func_8004E89C_4F49C();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/4D660", func_8004E4FC_4F0FC);
#endif

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

s32 func_8004E94C_4F54C(void) {
    s32 i;

    if (D_800F8D16_F9916 != 0) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].item == 3) {
            return 1;
        }
    }
    return 0;
}

void func_8004E9A8_4F5A8(void) {
    MBItemSubFunctions[10]();
}

void func_8004E9CC_4F5CC(void) {
    MBItemSubFunctions[12]();
}

void func_8004E9F0_4F5F0(void) {
    if (GwSystem.current_player_index == 4) {
        MBItemSubFunctions[11]();
    }
}

void func_8004EA28_4F628(void) {
    MBItemSubFunctions[13]();
}
