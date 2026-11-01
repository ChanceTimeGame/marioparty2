#include "ovl_12.h"

void func_80102DA0_1610C0_BobOmbBarrage(void) {
    omObjData* obj;

    func_80103628_161948_BobOmbBarrage();
    if (func_8010364C_16196C_BobOmbBarrage() != 0) {
        obj = func_801033A8_1616C8_BobOmbBarrage();
    } else {
        obj = func_80102E14_161134_BobOmbBarrage();
    }
    D_8010A1C8_1684E8_BobOmbBarrage[0] = obj;
    D_8010A1C8_1684E8_BobOmbBarrage[1] = func_801028F0_160C10_BobOmbBarrage();
    D_8010A1C8_1684E8_BobOmbBarrage[2] = func_801036A0_1619C0_BobOmbBarrage();
    D_8010A1C8_1684E8_BobOmbBarrage[3] = func_80103E40_162160_BobOmbBarrage();
    D_8010A1C8_1684E8_BobOmbBarrage[4] = func_80103DF4_162114_BobOmbBarrage();
}

omObjData* func_80102E14_161134_BobOmbBarrage(void) {
    omObjData* obj = omAddObj(6, 0x10, 0, -1, func_80102E60_161180_BobOmbBarrage);

    func_80102E60_161180_BobOmbBarrage(obj);
    return obj;
}

void func_80102E60_161180_BobOmbBarrage(omObjData* obj) {
    D_80109394_1676B4_BobOmbBarrage = 0;
    obj->func_ptr = func_80102EC8_1611E8_BobOmbBarrage;
}

void func_80102E78_161198_BobOmbBarrage(void) {
    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 2:
    case 5:
    case 6:
        if (D_801011FC_101DFC == 1) {
            D_80109394_1676B4_BobOmbBarrage = 0xC;
        }
        break;
    }
}

void func_80102EC8_1611E8_BobOmbBarrage(omObjData* obj) {
    s32 chars[4];
    s32 i;
    s32 k;

    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 0:
    case 1:
        D_80109300_167620_BobOmbBarrage = 0;
        break;
    case 2:
    case 3:
    case 4:
        if (++D_80109300_167620_BobOmbBarrage == 0x30) {
            PlayMusic(0x1D);
        }
        break;
    }
    func_80102E78_161198_BobOmbBarrage();
    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 0:
        D_80109394_1676B4_BobOmbBarrage = 1;
        InitFadeIn(0, 0x10);
        D_8010930C_16762C_BobOmbBarrage = PlaySound(0x4A1);
        break;
    case 1:
        if (func_8008F618_90218() == 0) {
            func_8010359C_1618BC_BobOmbBarrage(0x1E);
            func_8006D4D0_6E0D0(func_801035B4_1618D4_BobOmbBarrage());
            D_80109394_1676B4_BobOmbBarrage = 2;
        }
        break;
    case 2:
        D_80109308_167628_BobOmbBarrage = 0;
        D_80109304_167624_BobOmbBarrage = 0x3C;
        break;
    case 3:
        if (D_80109304_167624_BobOmbBarrage <= D_80109308_167628_BobOmbBarrage) {
            D_80109394_1676B4_BobOmbBarrage = 4;
            func_800691FC_69DFC(0);
            func_80079848_7A448(D_8010930C_16762C_BobOmbBarrage);
        } else {
            D_80109308_167628_BobOmbBarrage++;
        }
        break;
    case 4:
        if (func_80069538_6A138() == 0) {
            D_80109394_1676B4_BobOmbBarrage = 5;
            func_800691FC_69DFC(0xA, func_801035B4_1618D4_BobOmbBarrage(), 0xA0, 0x20);
            D_800FDEAE_FEAAE = 0;
        }
        break;
    case 5:
        func_8006D4D0_6E0D0(func_801035B4_1618D4_BobOmbBarrage());
        if (func_801035B4_1618D4_BobOmbBarrage() == 0) {
            D_80109394_1676B4_BobOmbBarrage = 6;
            D_800FDEAE_FEAAE = 0;
        } else {
            func_801035C0_1618E0_BobOmbBarrage();
        }
        break;
    case 6:
        D_800FDEAE_FEAAE = 0;
        if (D_801093A0_1676C0_BobOmbBarrage[0].act.held == 0) {
            if (D_801093A0_1676C0_BobOmbBarrage[0].act.side == 2) {
                D_80109394_1676B4_BobOmbBarrage = 8;
            }
        } else {
            D_80109394_1676B4_BobOmbBarrage = 7;
        }
        break;
    case 7:
        D_80109394_1676B4_BobOmbBarrage = 9;
        if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
            func_80108998_166CB8_BobOmbBarrage();
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            func_800794A8_7A0A8(0x28);
        }
        break;
    case 8:
        D_80109394_1676B4_BobOmbBarrage = 9;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        break;
    case 9:
        if ((func_80069538_6A138() == 0 || func_80069538_6A138() == 2) && func_800696E4_6A2E4() != 0) {
            if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
                func_801084E0_166800_BobOmbBarrage();
            } else {
                func_801085DC_1668FC_BobOmbBarrage();
            }
            D_80109394_1676B4_BobOmbBarrage = 0xA;
        }
        break;
    case 10:
        D_80109394_1676B4_BobOmbBarrage = 0xB;
        if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
            func_801035F8_161918_BobOmbBarrage(0x78);
            PlayMusic(0x51);
            k = func_80108D24_167044_BobOmbBarrage(0);
            gPlayers[k].coins_mg_bonus += 0xA;
            chars[0] = gPlayers[k].character;
            func_800691FC_69DFC(6, chars[0]);
        } else {
            func_801035F8_161918_BobOmbBarrage(0xA8);
            for (i = 1; i < 4; i++) {
                k = func_80108D24_167044_BobOmbBarrage(i);
                gPlayers[k].coins_mg_bonus += 0xA;
                chars[i] = gPlayers[k].character;
            }
            func_800691FC_69DFC(0x15, chars[1], chars[2], chars[3]);
            PlayMusic(0x52);
        }
        break;
    case 11:
        if (func_80103604_161924_BobOmbBarrage() > 0) {
            func_80103610_161930_BobOmbBarrage();
        } else if ((func_80069538_6A138() == 0 || func_80069538_6A138() == 2) && func_800696E4_6A2E4() != 0) {
            D_80109394_1676B4_BobOmbBarrage = 0xC;
        }
        break;
    case 12:
        D_80109394_1676B4_BobOmbBarrage = 0xF;
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        break;
    case 15:
        if (func_8008F618_90218() == 0) {
            D_80109394_1676B4_BobOmbBarrage = 0x10;
        }
        break;
    case 13:
    case 16:
        func_80079868_7A468();
        omOvlReturnEx(1);
        break;
    }
}

omObjData* func_801033A8_1616C8_BobOmbBarrage(void) {
    omObjData* obj = omAddObj(6, 0x10, 0, -1, func_801033F4_161714_BobOmbBarrage);

    func_801033F4_161714_BobOmbBarrage(obj);
    return obj;
}

void func_801033F4_161714_BobOmbBarrage(omObjData* obj) {
    D_80109394_1676B4_BobOmbBarrage = 0;
    obj->func_ptr = func_8010340C_16172C_BobOmbBarrage;
}

void func_8010340C_16172C_BobOmbBarrage(omObjData* obj) {
    func_80102E78_161198_BobOmbBarrage();
    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 5:
        func_8006D4D0_6E0D0(func_801035B4_1618D4_BobOmbBarrage());
        if (func_801035B4_1618D4_BobOmbBarrage() == 0) {
            D_80109394_1676B4_BobOmbBarrage = 6;
            D_800FDEAE_FEAAE = 0;
        } else {
            func_801035C0_1618E0_BobOmbBarrage();
        }
        break;
    case 6:
        D_800FDEAE_FEAAE = 0;
        if (D_801093A0_1676C0_BobOmbBarrage[0].act.held == 0) {
            if (D_801093A0_1676C0_BobOmbBarrage[0].act.side != 2) {
                break;
            }
        } else {
            func_80108998_166CB8_BobOmbBarrage();
        }
        D_80109394_1676B4_BobOmbBarrage = 8;
        break;
    case 7:
        D_80109394_1676B4_BobOmbBarrage = 9;
        if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
            func_80108998_166CB8_BobOmbBarrage();
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            func_800794A8_7A0A8(0x28);
        }
        break;
    case 8:
        D_80109394_1676B4_BobOmbBarrage = 9;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        break;
    case 9:
        if (func_80069538_6A138() == 0) {
            D_80109394_1676B4_BobOmbBarrage = 0xC;
            if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
                gPlayers[0].coins_mg_bonus += 0xA;
            }
        }
        break;
    default:
        func_80102EC8_1611E8_BobOmbBarrage(obj);
        break;
    }
}

void func_8010359C_1618BC_BobOmbBarrage(s32 seconds) {
    D_80109310_167630_BobOmbBarrage.seconds = seconds;
    D_80109310_167630_BobOmbBarrage.frames = 0x1D;
}

s32 func_801035B4_1618D4_BobOmbBarrage(void) {
    return D_80109310_167630_BobOmbBarrage.seconds;
}

s32 func_801035C0_1618E0_BobOmbBarrage(void) {
    if (--D_80109310_167630_BobOmbBarrage.frames < 0) {
        D_80109310_167630_BobOmbBarrage.frames = 0x1D;
        D_80109310_167630_BobOmbBarrage.seconds--;
    }
    return D_80109310_167630_BobOmbBarrage.seconds;
}

void func_801035F8_161918_BobOmbBarrage(s32 arg0) {
    D_80109318_167638_BobOmbBarrage = arg0;
}

s32 func_80103604_161924_BobOmbBarrage(void) {
    return D_80109318_167638_BobOmbBarrage;
}

void func_80103610_161930_BobOmbBarrage(void) {
    D_80109318_167638_BobOmbBarrage--;
}

void func_80103628_161948_BobOmbBarrage(void) {
    D_8010931C_16763C_BobOmbBarrage = _CheckFlag(0xC);
}

s32 func_8010364C_16196C_BobOmbBarrage(void) {
    return D_8010931C_16763C_BobOmbBarrage;
}
