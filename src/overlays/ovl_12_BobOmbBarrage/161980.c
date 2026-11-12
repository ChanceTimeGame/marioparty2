#include "ovl_12.h"

/* .data (0x167090-0x1673AF; 0x167060-0x16708F is in 160C10.c) */
s32 D_80108D70_167090_BobOmbBarrage[15] = { 0x200D1, 0x200D3, 0x20000, 0x20001, 0x20003, 0x20004, 0x20008, 0x2000E, 0x2006D, 0x2004E, 0x20055, 0x20099, 0x2009A, 0x2009B, -1 };
s32 D_80108DAC_1670CC_BobOmbBarrage[16] = { 0x300D1, 0x300D3, 0x30000, 0x30001, 0x30003, 0x30004, 0x30008, 0x3000E, 0x3006D, 0x3004E, 0x30055, 0x30099, 0x3009A, 0x3009B, 0x30043, -1 };
s32 D_80108DEC_16710C_BobOmbBarrage[16] = { 0x700D1, 0x700D3, 0x70000, 0x70001, 0x70003, 0x70004, 0x70008, 0x7000E, 0x7006D, 0x7004E, 0x70055, 0x70099, 0x7009A, 0x7009B, 0x70043, -1 };
s32 D_80108E2C_16714C_BobOmbBarrage[16] = { 0x400D1, 0x400D3, 0x40000, 0x40001, 0x40003, 0x40004, 0x40008, 0x4000C, 0x4006D, 0x4004E, 0x40055, 0x40099, 0x4009A, 0x4009B, 0x40043, -1 };
s32 D_80108E6C_16718C_BobOmbBarrage[16] = { 0x500D1, 0x500D3, 0x50000, 0x50001, 0x50003, 0x50004, 0x50008, 0x5000E, 0x5006D, 0x5004E, 0x50055, 0x50099, 0x5009A, 0x5009B, 0x50043, -1 };
s32 D_80108EAC_1671CC_BobOmbBarrage[16] = { 0x600D1, 0x600D3, 0x60000, 0x60001, 0x60003, 0x60004, 0x60008, 0x6000E, 0x6006D, 0x6004E, 0x60055, 0x60099, 0x6009A, 0x6009B, 0x60043, -1 };
s32* D_80108EEC_16720C_BobOmbBarrage[7] = { D_80108D70_167090_BobOmbBarrage, D_80108DAC_1670CC_BobOmbBarrage, D_80108DEC_16710C_BobOmbBarrage, D_80108E2C_16714C_BobOmbBarrage, D_80108E6C_16718C_BobOmbBarrage, D_80108EAC_1671CC_BobOmbBarrage, (s32*)-1 };
s32 D_80108F08_167228_BobOmbBarrage[6] = { 0x220000, 0x220001, 0x220002, 0x220003, 0x220006, -1 };
BBStart D_80108F20_167240_BobOmbBarrage[4] = { { { 0.0f, 0.0f, 0.0f }, 0.0f }, { { -300.0f, 200.0f, 700.0f }, 180.0f }, { { 0.0f, 200.0f, 750.0f }, 180.0f }, { { 300.0f, 200.0f, 700.0f }, 180.0f } };
s32 D_80108F60_167280_BobOmbBarrage[4] = { 30, 25, 20, 10 };
s32 D_80108F70_167290_BobOmbBarrage[4] = { 40, 45, 50, 60 };
s32 D_80108F80_1672A0_BobOmbBarrage[4] = { 25, 20, 15, 5 };
s32 D_80108F90_1672B0_BobOmbBarrage[4] = { 15, 10, 5, 0 };
BBScript D_80108FA0_1672C0_BobOmbBarrage[4] = { { { 0.0f, 0.0f, 0.0f }, 0.0f, 0 }, { { 1.0f, 0.0f, 0.0f }, 70.0f, 10 }, { { 0.0f, 1.0f, 0.0f }, 70.0f, 20 }, { { -1.0f, 0.0f, 0.0f }, 70.0f, 10 } };
BBSpin D_80108FF0_167310_BobOmbBarrage[4] = { { 0.0f, 0.0f, 0.0f, { 0 } }, { 0.0f, -30.0f, 10.0f, { 0 } }, { 30.0f, 0.0f, 10.0f, { 0 } }, { 0.0f, 30.0f, 10.0f, { 0 } } };
f32 D_80109030_167350_BobOmbBarrage[4] = { 0.0f, 0.53f, 0.6f, 0.6f };
s32 D_80109040_167360_BobOmbBarrage[4] = { 0, 30, 90, 60 };
s32 D_80109050_167370_BobOmbBarrage[4] = { 65, 45, 30, 25 };
s32 D_80109060_167380_BobOmbBarrage[4] = { 40, 30, 20, 10 };
s32 D_80109070_167390_BobOmbBarrage[4] = { 40, 40, 30, 15 };
s32 D_80109080_1673A0_BobOmbBarrage[4] = { 45, 45, 30, 30 };

void func_80103660_161980_BobOmbBarrage(void) {
    s32 i;

    D_8010A1C4_1684E4_BobOmbBarrage = 0;
    for (i = 0; i < 4; i++) {
        D_80109320_167640_BobOmbBarrage[i].unk_04 = 0;
        D_80109320_167640_BobOmbBarrage[i].done = 0;
    }
}

omObjData* func_801036A0_1619C0_BobOmbBarrage(void) {
    omObjData* obj = omAddObj(6, 0x20, 0, -1, func_801036F0_161A10_BobOmbBarrage);

    func_80108BCC_166EEC_BobOmbBarrage();
    func_801036F0_161A10_BobOmbBarrage(obj);
    return obj;
}

/* NON_MATCHING: register allocation (masked 0, raw 18): i, ch and m sit in s3/s4/s2 where retail has
   s2/s3/s4. The s16 m keeps retail's separate LoadFormFile calls; k reused for i + 8. Declaration
   order and an s32 ch have no effect. */
// decomp-permuter
void func_801036F0_161A10_BobOmbBarrage(omObjData *obj)
{
  s32 i;
  s32 k;
  s16 m;
  u8 ch;
  obj->model[0] = LoadFormFile(D_80108F08_167228_BobOmbBarrage[0], 0x289);
  omSetTra(obj, 0.0f, 0.0f, 0.0f);
  omSetSca(obj, 1.0f, 1.0f, 1.0f);
  omSetRot(obj, 0.0f, 0.0f, 0.0f);
  func_80029714_2A314(obj->model[0], 0.0f, 0.0f, 0.0f);
  func_8002979C_2A39C(obj->model[0], 0.0f, 0.0f, 0.0f);
  func_800297E8_2A3E8(obj->model[0], 1.0f, 1.0f, 1.0f);
  func_800298A4_2A4A4(obj->model[0], 4, 0);
  func_80029EDC_2AADC(obj->model[0], 0xF);
  obj->model[1] = LoadFormFile(D_80108F08_167228_BobOmbBarrage[1], 0x289);
  func_80029714_2A314(obj->model[1], 0.0f, 0.0f, 0.0f);
  func_8002979C_2A39C(obj->model[1], 0.0f, 0.0f, 0.0f);
  func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.0f);
  func_800298A4_2A4A4(obj->model[1], 4, 0);
  func_80029EDC_2AADC(obj->model[1], 0xF);
  obj->model[2] = LoadFormFile(D_80108F08_167228_BobOmbBarrage[2], 0x299);
  func_80029714_2A314(obj->model[2], 0.0f, 0.0f, 0.0f);
  func_8002979C_2A39C(obj->model[2], 0.0f, 0.0f, 0.0f);
  func_800297E8_2A3E8(obj->model[2], 1.0f, 1.0f, 1.0f);
  func_80029F2C_2AB2C(obj->model[2], 0x400);
  func_800298A4_2A4A4(obj->model[2], 4, 0);
  func_80029EDC_2AADC(obj->model[2], 0xF);
  func_8002A00C_2AC0C(obj->model[2]);
  D_80109340_167660_BobOmbBarrage = (D_80109344_167664_BobOmbBarrage = 0.0f);
  obj->model[3] = LoadFormFile(D_80108F08_167228_BobOmbBarrage[3], 0x289);
  func_80029714_2A314(obj->model[3], 0.0f, 0.0f, 0.0f);
  func_8002979C_2A39C(obj->model[3], 0.0f, 0.0f, 0.0f);
  func_800297E8_2A3E8(obj->model[3], 1.0f, 1.0f, 1.0f);
  func_800298A4_2A4A4(obj->model[3], 4, 0);
  func_80029EDC_2AADC(obj->model[3], 0xF);
  HmfModelObjAttrSet(obj->model[3], 0x20000, 0x20000);
  func_80029A8C_2A68C(obj->model[3]);
  func_8002A00C_2AC0C(obj->model[3]);
  for (i = 0; i < 4; i++)
  {
    ch = gPlayers[func_80108D24_167044_BobOmbBarrage(i)].character;
    m = (k = i + 4);
    D_80109370_167690_BobOmbBarrage = &D_801093A0_1676C0_BobOmbBarrage[i];
    if (i == 0)
    {
      obj->model[(s16) k] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][0], 0x299);
    }
    else
    {
      obj->model[(s16) m] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][1], 0x299);
    }
    func_80029714_2A314(obj->model[(s16) m], 0.0f, 0.0f, 0.0f);
    func_8002979C_2A39C(obj->model[(s16) m], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[(s16) m], 1.0f, 1.0f, 1.0f);
    func_800298A4_2A4A4(obj->model[(s16) m], 4, 0);
    func_80029F2C_2AB2C(obj->model[(s16) m], 0x800);
    if (i == 0)
    {
      D_80109370_167690_BobOmbBarrage->mot[0] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][2], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[1] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][3], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[5] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][7], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[6] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][8], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[7] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][9], 0x299);
    }
    else
    {
      D_80109370_167690_BobOmbBarrage->mot[0] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][2], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[1] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][3], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[9] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][11], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[10] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][12], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[11] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][13], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[4] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][6], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[7] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][9], 0x299);
      D_80109370_167690_BobOmbBarrage->mot[8] = LoadFormFile(D_80108EEC_16720C_BobOmbBarrage[ch][10], 0x299);
      k = i + 8;
      obj->model[(s16) k] = LoadFormFile(0xD, 0x299);
      func_80029714_2A314(obj->model[(s16) k], 0.0f, 0.0f, 0.0f);
      func_8002979C_2A39C(obj->model[(s16) k], 0.0f, 0.0f, 0.0f);
      func_800297E8_2A3E8(obj->model[(s16) k], 1.0f, 1.0f, 1.0f);
      func_800298A4_2A4A4(obj->model[(s16) k], 4, 0);
    }
  }

  obj->func_ptr = func_80103D58_162078_BobOmbBarrage;
}

void func_80103D58_162078_BobOmbBarrage(omObjData* obj) {
    func_8002BCA8_2C8A8(obj->model[2], D_80109340_167660_BobOmbBarrage, D_80109344_167664_BobOmbBarrage, 0x20, 0x20);
    D_80109340_167660_BobOmbBarrage += 0.02f;
    D_80109344_167664_BobOmbBarrage += 0.09f;
}

void func_80103DDC_1620FC_BobOmbBarrage(void) {
}

void func_80103DE4_162104_BobOmbBarrage(omObjData* obj) {
    obj->func_ptr = func_80103DDC_1620FC_BobOmbBarrage;
}

omObjData* func_80103DF4_162114_BobOmbBarrage(void) {
    omObjData* obj = omAddObj(6, 0x10, 0, -1, func_80103DE4_162104_BobOmbBarrage);

    func_80103DE4_162104_BobOmbBarrage(obj);
    return obj;
}

omObjData* func_80103E40_162160_BobOmbBarrage(void) {
    omObjData* obj = omAddObj(6, 0x10, 0, -1, func_80103E9C_1621BC_BobOmbBarrage);

    func_80103E9C_1621BC_BobOmbBarrage(obj);
    func_80103660_161980_BobOmbBarrage();
    func_801089B4_166CD4_BobOmbBarrage();
    return obj;
}

void func_80103E9C_1621BC_BobOmbBarrage(omObjData* obj) {
    s32 i;
    s32 j;
    s32 k;
    s16 mdl;
    u16 mot;
    BBBomb* b;
    BBPlayer* p;
    void* data;

    for (i = 0; i < 4; i++) {
        D_8010A1C0_1684E0_BobOmbBarrage = i;
        k = func_80108D24_167044_BobOmbBarrage(i);
        D_80109370_167690_BobOmbBarrage = p = &D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage];
        p->chr = gPlayers[k].character;
        p->port = gPlayers[k].port;
        switch (gPlayers[k].cpu_difficulty) {
        case 0:
            D_80109370_167690_BobOmbBarrage->diff = 0;
            break;
        case 1:
            D_80109370_167690_BobOmbBarrage->diff = 1;
            break;
        case 2:
            D_80109370_167690_BobOmbBarrage->diff = 2;
            break;
        default:
            D_80109370_167690_BobOmbBarrage->diff = 3;
            break;
        }
        D_80109370_167690_BobOmbBarrage->com = gPlayers[k].flags & 1;
        D_80109370_167690_BobOmbBarrage->act.side = (D_8010A1C0_1684E0_BobOmbBarrage != 0) ? -1 : 1;
        D_80109370_167690_BobOmbBarrage->act.t = 0;
        D_80109370_167690_BobOmbBarrage->act.unk_1C = 0;
        D_80109370_167690_BobOmbBarrage->act.state = 0;
        mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
        func_800B3170_B3D70(&D_80109370_167690_BobOmbBarrage->pos, &D_80108F20_167240_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].pos);
        HuVecCopyXYZ(&D_80109370_167690_BobOmbBarrage->vel, 0.0f, 0.0f, 0.0f);
        D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim = D_80109370_167690_BobOmbBarrage->rot = 0.0f;
        func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
        func_8002979C_2A39C(mdl, 0.0f, D_80109370_167690_BobOmbBarrage->rot, 0.0f);
        func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
        if (i != 0) {
            mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 8];
            func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
            func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
        }
        D_80109370_167690_BobOmbBarrage->ai.state = 1;
        D_80109370_167690_BobOmbBarrage->ai.x = D_80109370_167690_BobOmbBarrage->ai.y = 0.0f;
        D_80109370_167690_BobOmbBarrage->ai.t = 0;
        D_80109370_167690_BobOmbBarrage->ai.time = 0x10;
        if (i == 0) {
            D_80109370_167690_BobOmbBarrage->act.held = 1;
            D_80109370_167690_BobOmbBarrage->act.reload = 0;
            D_80109370_167690_BobOmbBarrage->act.timer = 0;
            D_80109348_167668_BobOmbBarrage = 0;
            D_8010934C_16766C_BobOmbBarrage = 0;
            for (j = 0; j < 10; j++) {
                D_80109370_167690_BobOmbBarrage->act.u.dust[j] = mdl = LoadFormFile(0x220007, 0x299);
                func_80029714_2A314(mdl, 0.0f, -20.0f, 0.0f);
                func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_80029F2C_2AB2C(mdl, 0x800);
                func_800298A4_2A4A4(mdl, 4, 4);
                func_80029E80_2AA80(mdl, 2, 0);
            }
        } else {
            D_80109370_167690_BobOmbBarrage->act.held = -1;
            D_80109370_167690_BobOmbBarrage->act.reload = 0;
            for (j = 0; j < 2; j++) {
                b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[j];
                b->state = 1;
                b->fuse = 0;
                b->t = 0;
                HuVecCopyXYZ(&b->pos, D_80109370_167690_BobOmbBarrage->pos.x + 100.0f, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z + 140.0f);
                HuVecCopyXYZ(&b->vel, 0.0f, 0.0f, 0.0f);
                if (i != 1) {
                    mdl = func_80027D3C_2893C(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].mdl);
                } else {
                    mdl = LoadFormFile(0x1C0000, 0x689);
                }
                b->mdl = mdl;
                func_80029714_2A314(mdl, b->pos.x, b->pos.y, b->pos.z);
                func_8002979C_2A39C(mdl, 0.0f, 180.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_80029E80_2AA80(mdl, 2, 2);
                func_80029F2C_2AB2C(mdl, 0x800);
                func_800298A4_2A4A4(mdl, 4, 0);
                mdl = LoadFormFile(0x1C0000, 0x689);
                b->lit = mdl;
                mot = LoadFormFile(0x1C0002, 0x299);
                func_80029714_2A314(mdl, b->pos.x, b->pos.y, b->pos.z);
                func_8002979C_2A39C(mdl, 0.0f, 180.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_80029B80_2A780(mdl, mot);
                func_80029E80_2AA80(mdl, 2, 2);
                func_80029F2C_2AB2C(mdl, 0x800);
                func_800298A4_2A4A4(mdl, 4, 4);
                if (i != 1 && j != 0) {
                    mdl = func_80027D3C_2893C(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].shadow);
                } else {
                    mdl = LoadFormFile(0xD, 0x299);
                }
                b->shadow = mdl;
                func_80029714_2A314(mdl, b->pos.x, b->pos.y, b->pos.z);
                func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_80029F2C_2AB2C(mdl, 0x800);
                func_800298A4_2A4A4(mdl, 4, 0);
                if (i != 1 && j != 0) {
                    mdl = func_80027D3C_2893C(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].blast);
                } else {
                    mdl = LoadFormFile(0x220005, 0x299);
                }
                b->blast = mdl;
                func_80029714_2A314(mdl, b->pos.x, b->pos.y, b->pos.z);
                func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_80029F2C_2AB2C(mdl, 0x800);
                func_800298A4_2A4A4(mdl, 4, 4);
                HmfModelObjAttrSet(mdl, 0x70000000, 0x70000000);
                mdl = LoadFormFile(0x220004, 0x299);
                b->splash = mdl;
                func_80029714_2A314(mdl, 100.0f, 200.0f, 100.0f);
                func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
                func_800298A4_2A4A4(mdl, 4, 4);
                func_80029E80_2AA80(mdl, 2, 0);
                data = DataRead(0x22000D);
                b->fx = func_8003D8F0_3E4F0(D_800FC834_FD434[b->lit].hmf, data, 0, "c104_n0_DEF");
                DataClose(data);
                func_8003E4F4_3F0F4(b->fx, 1, 1);
                func_80029A8C_2A68C(b->lit);
            }
            b = &D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.u.bomb[0];
            b->state = 3;
            HuVecCopyXYZ(&b->pos, D_80109370_167690_BobOmbBarrage->pos.x + 100.0f, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
            func_80029714_2A314(b->mdl, b->pos.x, b->pos.y, b->pos.z);
            func_800298A4_2A4A4(b->mdl, 4, 0);
            func_80029714_2A314(b->shadow, b->pos.x, 200.0f, b->pos.z);
            func_800298A4_2A4A4(b->shadow, 4, 0);
        }
    }
    obj->func_ptr = func_80104778_162A98_BobOmbBarrage;
}

void func_80104778_162A98_BobOmbBarrage(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80104850_162B70_BobOmbBarrage(func_80108D24_167044_BobOmbBarrage(i));
    }
    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 0:
        break;
    case 2: {
        Vec eye = { 0.0f, 500.0f, 477.2727f };
        Vec at = { 0.0f, 1100.0f, 1050.0f };

        if (++D_8010A1C4_1684E4_BobOmbBarrage > 0xA0) {
            D_80109394_1676B4_BobOmbBarrage = 3;
            func_80102C04_160F24_BobOmbBarrage(&eye, &at, 0x3C, 1);
        }
        break;
    }
    }
}

void func_80104850_162B70_BobOmbBarrage(s32 slot) {
    s32 i;

    D_8010A1C0_1684E0_BobOmbBarrage = slot;
    D_80109370_167690_BobOmbBarrage = &D_801093A0_1676C0_BobOmbBarrage[slot];
    switch (D_80109394_1676B4_BobOmbBarrage) {
    case 0:
    case 1:
        break;
    case 2:
        if (D_8010A1C0_1684E0_BobOmbBarrage == 0) {
            func_8010561C_16393C_BobOmbBarrage();
        } else {
            func_801059E4_163D04_BobOmbBarrage();
        }
        for (i = 0; i < 4; i++) {
            if (D_80109320_167640_BobOmbBarrage[i].done == 0) {
                break;
            }
        }
        if (i == 4) {
            D_80109394_1676B4_BobOmbBarrage = 3;
        }
        break;
    case 3:
    case 4:
        if (D_8010A1C0_1684E0_BobOmbBarrage == 0) {
            func_8010561C_16393C_BobOmbBarrage();
        } else {
            func_801059E4_163D04_BobOmbBarrage();
        }
        break;
    case 5:
        if (D_8010A1C0_1684E0_BobOmbBarrage == 0) {
            if (D_80109370_167690_BobOmbBarrage->com != 0) {
                func_80105754_163A74_BobOmbBarrage();
            } else {
                func_801056D4_1639F4_BobOmbBarrage();
            }
        } else if (D_80109370_167690_BobOmbBarrage->com != 0) {
            func_8010684C_164B6C_BobOmbBarrage();
        } else {
            func_80106150_164470_BobOmbBarrage();
        }
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    default:
        if (D_8010A1C0_1684E0_BobOmbBarrage == 0) {
            func_8010561C_16393C_BobOmbBarrage();
        } else {
            func_801059E4_163D04_BobOmbBarrage();
        }
        break;
    }
}

// masked 49: regalloc (loop counter s2 not s1, float temps); case 2 splash address CSEd into s0 where retail reloads it; the bounce divisor recomputes d.x*d.x in retail
#ifdef NON_MATCHING
void func_801049E0_162D00_BobOmbBarrage(f32 x, f32 y, u16 btn) {
    Vec pos;
    Vec d;
    Vec vel;
    Vec rot;
    Vec n;
    Vec v;
    Vec r;
    f32 k;
    f32 s;
    f32 t;
    f32 len;
    f32 f;
    f32 yOfs;
    s16 mdl;
    s16 pl;
    s32 i;
    s32 j;
    BBBomb* b;

    pl = func_80108D24_167044_BobOmbBarrage(0);
    if (D_80109370_167690_BobOmbBarrage->act.held == 0) {
        x = y = vel.x = vel.y = 0.0f;
        switch (D_80109370_167690_BobOmbBarrage->act.state) {
        case 0:
            if (++D_80109370_167690_BobOmbBarrage->act.t > 0x1E) {
                D_80109370_167690_BobOmbBarrage->act.state = 0x12;
                func_800797DC_7A3DC(0x111, pl);
                omVibrate(pl, 0x14, 0, 0x14);
                D_80109370_167690_BobOmbBarrage->act.t = 0;
                mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4];
                func_80029B80_2A780(mdl, D_80109370_167690_BobOmbBarrage->mot[6]);
                func_80029E80_2AA80(mdl, 2, 2);
                func_80108AB0_166DD0_BobOmbBarrage(200.0f, 0x1E);
                D_800CA02C_CAC2C = 0.0f;
                D_80109350_167670_BobOmbBarrage = 0.0f;
                for (i = 1; i < 4; i++) {
                    D_801093A0_1676C0_BobOmbBarrage[i].act.state = 5;
                    func_80029B80_2A780(D_8010A1C8_1684E8_BobOmbBarrage[2]->model[i + 4], D_801093A0_1676C0_BobOmbBarrage[i].mot[0]);
                    for (j = 0; j < 2; j++) {
                        b = &D_801093A0_1676C0_BobOmbBarrage[i].act.u.bomb[j];
                        if (D_801093A0_1676C0_BobOmbBarrage[i].act.held == j) {
                            func_800298A4_2A4A4(b->mdl, 0x4000, 0);
                        }
                        b->state = 0;
                        func_800298A4_2A4A4(b->mdl, 4, 4);
                        func_800298A4_2A4A4(b->lit, 4, 4);
                        func_800298A4_2A4A4(b->shadow, 4, 4);
                        func_800298A4_2A4A4(b->blast, 4, 4);
                        func_800298A4_2A4A4(b->splash, 4, 4);
                    }
                }
                b = &D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0];
                PlaySound(0x1AE);
                func_800298A4_2A4A4(b->blast, 4, 0);
                func_80029714_2A314(b->blast, D_801093A0_1676C0_BobOmbBarrage[0].pos.x, D_801093A0_1676C0_BobOmbBarrage[0].pos.y - 220.0f, D_801093A0_1676C0_BobOmbBarrage[0].pos.z);
                func_8002979C_2A39C(b->blast, 0.0f, 0.0f, 0.0f);
                func_800297E8_2A3E8(b->blast, 4.0f, 4.0f, 4.0f);
                func_80029FE4_2ABE4(b->blast, 1.0f);
                func_80029C74_2A874(b->blast, 0.0f);
            }
            break;
        case 18:
            mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[3];
            D_80109350_167670_BobOmbBarrage += 8.0f;
            if (D_80109350_167670_BobOmbBarrage > 360.0f) {
                D_80109350_167670_BobOmbBarrage -= 360.0f;
                func_800298A4_2A4A4(mdl, 4, 4);
                D_801093A0_1676C0_BobOmbBarrage[0].act.state = 0x13;
                D_801093A0_1676C0_BobOmbBarrage[0].act.side = 2;
            }
            k = D_80109350_167670_BobOmbBarrage / 360.0f;
            f = 1.0f - func_800B1830_B2430(k * 0.5f);
            if (f < 0.0f) {
                f = 0.0f;
            }
            func_8002AC10_2B810(mdl, f, k + 1.0f, 2);
            D_800CA02C_CAC2C += 37.0f;
            D_800CA02C_CAC2C -= (s16)(D_800CA02C_CAC2C / 360.0f) * 360.0f;
            break;
        case 19:
            break;
        }
    }
    if (D_801093A0_1676C0_BobOmbBarrage[0].act.held != 0) {
        func_800B3170_B3D70(&pos, &D_80109370_167690_BobOmbBarrage->pos);
        func_800B3170_B3D70(&vel, &D_80109370_167690_BobOmbBarrage->vel);
        vel.x += x * 0.02f;
        vel.z += y * 0.02f;
        d.x = (pos.x + vel.x) * 0.68 - 0.0;
        d.z = (pos.z - vel.z) - -120.0f;
        if (d.x * d.x + d.z * d.z > 280900.0f) {
            n.x = d.x;
            n.z = d.z;
            v.x = vel.x;
            v.z = -vel.z;
            s = (d.x * v.x + d.z * v.z) / (n.x * n.x + n.z * n.z);
            r.x = s * d.x;
            r.z = s * d.z;
            v.x -= 2.0f * r.x;
            v.z -= 2.0f * r.z;
            vel.x = v.x * 0.89;
            vel.z = -v.z * 0.89;
        }
        vel.x *= 0.89f;
        vel.z *= 0.89f;
        vel.y = 0.0f;
        len = HuVecGetLength3F(&vel);
        if (len > 20.0f) {
            vel.x = vel.x * 20.0f / len;
            vel.z = vel.z * 20.0f / len;
        }
        d.x = (pos.x + vel.x) * 0.68 - 0.0;
        d.z = (pos.z - vel.z) - -120.0f;
        if (d.x * d.x + d.z * d.z <= 280900.0f) {
            D_80109370_167690_BobOmbBarrage->pos.x += vel.x;
            D_80109370_167690_BobOmbBarrage->pos.z -= vel.z;
        } else {
            f = func_800B1830_B2430(vel.x * vel.x + vel.z * vel.z) * 0.5f;
            t = D_80109370_167690_BobOmbBarrage->pos.x;
            D_80109370_167690_BobOmbBarrage->pos.x = (pos.x < 0.0f) ? t + f : t - f;
            t = D_80109370_167690_BobOmbBarrage->pos.z;
            D_80109370_167690_BobOmbBarrage->pos.z = (pos.z < 0.0f) ? t + f : t - f;
        }
        func_800B3170_B3D70(&D_80109370_167690_BobOmbBarrage->vel, &vel);
        if ((x != 0.0f) | (y != 0.0f)) {
            if (D_80109348_167668_BobOmbBarrage >= 7) {
                mdl = D_80109370_167690_BobOmbBarrage->act.u.dust[D_8010934C_16766C_BobOmbBarrage];
                func_80029714_2A314(mdl, D_801093A0_1676C0_BobOmbBarrage[0].pos.x, -20.0f, D_801093A0_1676C0_BobOmbBarrage[0].pos.z);
                func_800298A4_2A4A4(mdl, 4, 0);
                func_80029FE4_2ABE4(mdl, 0.3f);
                func_80029C74_2A874(mdl, 0.0f);
                if (D_8010934C_16766C_BobOmbBarrage == 0xA) {
                    D_8010934C_16766C_BobOmbBarrage = 0;
                } else {
                    D_8010934C_16766C_BobOmbBarrage++;
                }
                D_80109348_167668_BobOmbBarrage = 0;
            } else {
                D_80109348_167668_BobOmbBarrage++;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        mdl = D_80109370_167690_BobOmbBarrage->act.u.dust[i];
        k = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= k) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
    yOfs = 0.0f;
    HuVecCopyXYZ(&rot, 0.0f, 0.0f, 0.0f);
    switch (D_80109378_167698_BobOmbBarrage.state) {
    case 0:
        if (D_80109378_167698_BobOmbBarrage.time >= D_80109378_167698_BobOmbBarrage.t) {
            func_801089E4_166D04_BobOmbBarrage();
            D_80109378_167698_BobOmbBarrage.t++;
        } else {
            D_80109378_167698_BobOmbBarrage.state = -1;
            func_80029B80_2A780(D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4], D_801093A0_1676C0_BobOmbBarrage[0].mot[0]);
        }
        break;
    case 1:
        if (D_80109378_167698_BobOmbBarrage.time >= D_80109378_167698_BobOmbBarrage.t) {
            func_80108AD4_166DF4_BobOmbBarrage();
            D_80109378_167698_BobOmbBarrage.t++;
            yOfs = D_80109378_167698_BobOmbBarrage.y;
            rot.y = 0.0f;
        } else {
            D_80109378_167698_BobOmbBarrage.state = 2;
            yOfs = D_80109378_167698_BobOmbBarrage.y = -80.0f;
            D_80109378_167698_BobOmbBarrage.t = 0;
            D_80109378_167698_BobOmbBarrage.time = 0xA;
            mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4];
            func_80029B80_2A780(mdl, D_801093A0_1676C0_BobOmbBarrage[0].mot[5]);
            func_80029E80_2AA80(mdl, 2, 2);
            func_80079798_7A398(0x1B0, 0);
            func_800298A4_2A4A4(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash, 4, 0);
            func_80029714_2A314(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y + yOfs, D_80109370_167690_BobOmbBarrage->pos.z);
            func_80029C74_2A874(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash, 0.0f);
        }
        break;
    case 2:
        if (D_80109378_167698_BobOmbBarrage.time >= D_80109378_167698_BobOmbBarrage.t) {
            D_80109378_167698_BobOmbBarrage.t++;
            D_80109378_167698_BobOmbBarrage.y = 0.0f;
            D_80109370_167690_BobOmbBarrage->pos.y = -100.0f;
        } else {
            k = func_80029CE4_2A8E4(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash);
            if (func_80029D0C_2A90C(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash) <= k) {
                func_800298A4_2A4A4(D_801093A0_1676C0_BobOmbBarrage[1].act.u.bomb[0].splash, 4, 4);
                D_80109378_167698_BobOmbBarrage.state = -1;
            }
        }
        break;
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4];
    func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, yOfs + D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
    func_8002979C_2A39C(mdl, rot.x + 0.0f, D_80109370_167690_BobOmbBarrage->rot + rot.y, rot.z + 0.0f);
    func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[3];
    func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
    func_8002979C_2A39C(mdl, 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_801049E0_162D00_BobOmbBarrage);
#endif

void func_8010561C_16393C_BobOmbBarrage(void) {
    BBAi* ai = &D_801093A0_1676C0_BobOmbBarrage[0].ai;

    switch (ai->state) {
    case 0:
    case 1:
        func_801049E0_162D00_BobOmbBarrage(0.0f, 0.0f, 0);
        break;
    case 3:
        if (ai->time < ai->t) {
            ai->state = 1;
            ai->t = 0;
            ai->time = 0x14;
            ai->x = ai->y = 0.0f;
        }
        func_801049E0_162D00_BobOmbBarrage(ai->x, ai->y, 0);
        break;
    default:
        func_80105754_163A74_BobOmbBarrage();
        break;
    }
    ai->t++;
}

// decomp-permuter
void func_801056D4_1639F4_BobOmbBarrage(void)
{
  u8 new_var;
  unsigned short new_var2;
  u8 port = gPlayers[func_80108D24_167044_BobOmbBarrage(0)].port;
  new_var2 = ContBtn[port];
  new_var = port;
  func_801049E0_162D00_BobOmbBarrage(ContStkX[new_var], ContStkY[new_var], new_var2);
}

void func_80105754_163A74_BobOmbBarrage(void) {
    f32 ang;
    f32 mag;
    BBAi* ai = &D_801093A0_1676C0_BobOmbBarrage[0].ai;

    switch (ai->state) {
    case 0:
        func_801049E0_162D00_BobOmbBarrage(0.0f, 0.0f, 0);
        return;
    case 1:
        if (ai->time < ai->t) {
            ai->t = 0;
            ai->time = func_801084A4_1667C4_BobOmbBarrage() * 30.0f + 10.0f;
            ai->state = 3;
            ang = func_801084A4_1667C4_BobOmbBarrage() * 360.0f;
            mag = D_80108F60_167280_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff] + D_80108F70_167290_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff] * func_801084A4_1667C4_BobOmbBarrage();
            ai->x = mag * HuMathSin(ang);
            ai->y = mag * func_800B7890_B8490(ang);
        }
        func_801049E0_162D00_BobOmbBarrage(0.0f, 0.0f, 0);
        break;
    case 3:
        if (ai->time < ai->t) {
            ai->t = 0;
            ai->time = D_80108F80_1672A0_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff] * func_801084A4_1667C4_BobOmbBarrage() + D_80108F90_1672B0_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff];
            if (ai->time < 0x14) {
                ai->time = 0;
            } else {
                ai->time -= 0x14;
            }
            ai->state = 1;
            ai->x = ai->y = 0.0f;
        }
        func_801049E0_162D00_BobOmbBarrage(ai->x, ai->y, 0);
        break;
    default:
        func_801049E0_162D00_BobOmbBarrage(0.0f, 0.0f, 0);
        break;
    }
    ai->t++;
}

void func_80105964_163C84_BobOmbBarrage(Vec* dir, f32 speed, s32 time) {
    f32 k;

    D_801093A0_1676C0_BobOmbBarrage->ai.state = 3;
    D_801093A0_1676C0_BobOmbBarrage->ai.time = time;
    D_801093A0_1676C0_BobOmbBarrage->ai.t = 0;
    k = speed * (1.0f / HuVecGetLength3F(dir));
    D_801093A0_1676C0_BobOmbBarrage->ai.x = k * dir->x;
    D_801093A0_1676C0_BobOmbBarrage->ai.y = k * dir->y;
}

// register allocation only (masked 0, raw 56): len/eight swap f22/f26, rotAim load in f0 not f2
#ifdef NON_MATCHING
void func_801059E4_163D04_BobOmbBarrage(void) {
    Vec d;
    f32 len;
    s32 c1;
    s32 c2;
    f32 rot;
    s32 state;
    f32 f;
    f32 eight;
    f32 ang;
    f32 a;
    f32 frame;
    s16 mdl;
    s32 i;
    BBBomb* b;

    rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    state = D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state;
    switch (state) {
    case 2:
        if (D_80109320_167640_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].done == 0) {
            D_80109320_167640_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].done = 1;
            func_8010684C_164B6C_BobOmbBarrage();
            return;
        }
        break;
    case 12:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xD;
        D_80109370_167690_BobOmbBarrage->ai.t = 0;
        D_80109370_167690_BobOmbBarrage->ai.time = D_80109040_167360_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage];
        D_80109370_167690_BobOmbBarrage->ai.power = D_80109030_167350_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage];
        func_80029C74_2A874(mdl, 0.0f);
        break;
    case 13:
    case 14:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        len = func_80029D0C_2A90C(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[10]);
        eight = 8.0f;
        f = D_80109370_167690_BobOmbBarrage->ai.power;
        if (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state != 0xD) {
            if (D_80109370_167690_BobOmbBarrage->ai.t > D_80109370_167690_BobOmbBarrage->ai.time) {
                f = 0.09f;
                func_80105964_163C84_BobOmbBarrage(&D_80108FA0_1672C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].dir, D_80108FA0_1672C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].speed, D_80108FA0_1672C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].time);
                func_801089C4_166CE4_BobOmbBarrage(D_80108FF0_167310_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].from, D_80108FF0_167310_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].to, D_80108FF0_167310_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].time);
                func_80029B80_2A780(D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4], D_801093A0_1676C0_BobOmbBarrage[0].mot[1]);
            } else {
                D_80109370_167690_BobOmbBarrage->ai.t++;
            }
        }
        if (f < 0.1f && D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state != 0xD) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xF;
            D_80109370_167690_BobOmbBarrage->power -= ((f - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.0f;
            ang = D_80109370_167690_BobOmbBarrage->rotAim;
            b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[D_80109370_167690_BobOmbBarrage->act.held];
            D_80109370_167690_BobOmbBarrage->act.held = -1;
            func_800298A4_2A4A4(b->lit, 0x4000, 0);
            func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[11]), 0, 8, 0);
            b->state = 6;
            func_800B3170_B3D70(&b->pos, &D_80109370_167690_BobOmbBarrage->pos);
            b->pos.y = D_80109370_167690_BobOmbBarrage->pos.y + 100.0f;
            b->pos.z = D_80109370_167690_BobOmbBarrage->pos.z - 50.0f;
            b->vel.x = -D_80109370_167690_BobOmbBarrage->power * 10.0f * func_800B7890_B8490(ang);
            b->vel.z = D_80109370_167690_BobOmbBarrage->power * 10.0f * HuMathSin(ang);
            b->vel.y = D_80109370_167690_BobOmbBarrage->power * 1.5f * 10.0f;
            func_800298A4_2A4A4(b->shadow, 4, 0);
            func_80029C74_2A874(mdl, 0.0f);
        } else if (f > 0.1f) {
            D_80109370_167690_BobOmbBarrage->act.state = 0xE;
            D_80109370_167690_BobOmbBarrage->power = ((f - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.0f;
            d.x = D_801093A0_1676C0_BobOmbBarrage[0].pos.x - D_80109370_167690_BobOmbBarrage->pos.x;
            d.z = D_801093A0_1676C0_BobOmbBarrage[0].pos.z - D_80109370_167690_BobOmbBarrage->pos.z;
            a = func_800B75A8_B81A8(d.x, d.z);
            if (a < 0.0f) {
                a += 360.0f;
            }
            a += 90.0f;
            if (a > 360.0f) {
                a -= 360.0f;
            }
            c1 = a >= 180.0f;
            c2 = a < 360.0f;
            if (c1 & c2) {
                D_80109370_167690_BobOmbBarrage->rotShow = a;
                D_80109370_167690_BobOmbBarrage->rotAim = a;
                D_80109370_167690_BobOmbBarrage->rotShow = a;
                rot = a;
            } else {
                rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
            }
            eight = (len - eight) * f + eight;
            func_80029C74_2A874(mdl, eight);
        }
        break;
    default:
        func_8010684C_164B6C_BobOmbBarrage();
        return;
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    rot -= 90.0f;
    if (rot < 0.0f) {
        rot += 360.0f;
    }
    func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
    func_8002979C_2A39C(mdl, 0.0f, rot, 0.0f);
    func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 2; i++) {
        func_80107700_165A20_BobOmbBarrage(i);
        D_80109370_167690_BobOmbBarrage->act.u.bomb[i].fuse = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_801059E4_163D04_BobOmbBarrage);
#endif

// register allocation only (masked 0, raw 48): rot/mag swap f24/f26
#ifdef NON_MATCHING
void func_80106150_164470_BobOmbBarrage(void) {
    s32 c1;
    s32 c2;
    f32 x;
    f32 eight;
    f32 y;
    f32 mag;
    f32 rot;
    f32 ang;
    f32 a;
    f32 len;
    s16 mdl;
    s32 i;
    s32 held;
    u8 port;
    BBBomb* b;

    port = gPlayers[func_80108D24_167044_BobOmbBarrage(D_8010A1C0_1684E0_BobOmbBarrage)].port;
    x = ContStkX[port];
    y = ContStkY[port];
    rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
    mag = func_800B1830_B2430(x * x + y * y) * 0.010101525f;
    ang = func_800B75A8_B81A8(y, x);
    if (ang < 0.0f) {
        ang += 360.0f;
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    switch (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state) {
    case 12:
        if (mag > 0.1f) {
            if ((ang > 180.0f) & (ang < 360.0f)) {
                D_80109370_167690_BobOmbBarrage->rotShow = ang;
                D_80109370_167690_BobOmbBarrage->rotAim = ang;
                D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xD;
                rot = ang;
            }
        } else {
            D_80109370_167690_BobOmbBarrage->rotShow = ang = 270.0f;
            D_80109370_167690_BobOmbBarrage->rotAim = ang;
            rot = ang;
        }
        func_80029C74_2A874(mdl, 0.0f);
        break;
    case 13:
    case 14:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        len = func_80029D0C_2A90C(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[10]);
        eight = 8.0f;
        if (mag < 0.1f && D_80109370_167690_BobOmbBarrage->act.state != 0xD) {
            D_80109370_167690_BobOmbBarrage->act.state = 0xF;
            func_80079798_7A398(0x1B1, (s16)D_8010A1C0_1684E0_BobOmbBarrage);
            D_80109370_167690_BobOmbBarrage->power -= ((mag - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.0f;
            a = D_80109370_167690_BobOmbBarrage->rotAim;
            held = D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.held;
            b = &D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.u.bomb[held];
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.held = -1;
            func_800298A4_2A4A4(b->lit, 0x4000, 0);
            func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[11]), 0, 8, 0);
            b->state = 6;
            func_800B3170_B3D70(&b->pos, &D_80109370_167690_BobOmbBarrage->pos);
            b->pos.y = D_80109370_167690_BobOmbBarrage->pos.y + 100.0f;
            b->pos.z = D_80109370_167690_BobOmbBarrage->pos.z - 50.0f;
            b->vel.x = -D_80109370_167690_BobOmbBarrage->power * 10.0f * func_800B7890_B8490(a);
            b->vel.z = D_80109370_167690_BobOmbBarrage->power * 10.0f * HuMathSin(a);
            b->vel.y = D_80109370_167690_BobOmbBarrage->power * 1.5f * 10.0f;
            func_800298A4_2A4A4(b->shadow, 4, 0);
            func_80029C74_2A874(mdl, 0.0f);
        } else if (mag > 0.1f) {
            D_80109370_167690_BobOmbBarrage->act.state = 0xE;
            D_80109370_167690_BobOmbBarrage->power = ((mag - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.5f;
            c1 = ang >= 180.0f;
            c2 = ang < 360.0f;
            if (c1 & c2) {
                D_80109370_167690_BobOmbBarrage->rotShow = ang;
                D_80109370_167690_BobOmbBarrage->rotAim = ang;
                D_80109370_167690_BobOmbBarrage->rotShow = ang;
                rot = ang;
            } else {
                rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
            }
            mag = (len - eight) * mag + eight;
            func_80029C74_2A874(mdl, mag);
        } else {
            D_80109370_167690_BobOmbBarrage->act.state = 0xD;
            func_80029C74_2A874(mdl, 0.0f);
        }
        break;
    case 0:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 15:
    case 16:
        func_8010684C_164B6C_BobOmbBarrage();
        return;
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    rot -= 90.0f;
    if (rot < 0.0f) {
        rot += 360.0f;
    }
    func_80029714_2A314(mdl, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
    func_8002979C_2A39C(mdl, 0.0f, rot, 0.0f);
    func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 2; i++) {
        func_80107700_165A20_BobOmbBarrage(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_80106150_164470_BobOmbBarrage);
#endif

__asm__(".section .rodata");
const char D_801091A4_1674C4_BobOmbBarrage[] = "item_hook";

// masked 65: scheduling of the (s16)mdl/mot extensions, the random-spread k kept in f2 not f0, float regalloc
#ifdef NON_MATCHING
void func_8010684C_164B6C_BobOmbBarrage(void) {
    f32 rot;
    f32 f;
    f32 len;
    f32 ang;
    f32 a;
    f32 r;
    f32 k;
    Vec d;
    f32 eight;
    s32 c1;
    s32 c2;
    u16 mdl;
    u16 mot;
    s16 m;
    s32 i;
    s32 j;
    s32 h;
    BBBomb* b;

    rot = 180.0f;
    func_80108D24_167044_BobOmbBarrage(D_8010A1C0_1684E0_BobOmbBarrage);
    if (D_80109370_167690_BobOmbBarrage->com == 0) {
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    switch (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state) {
    case 0:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 2;
        break;
    case 2:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        for (j = 0; j < 2; j++) {
            b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[j];
            if (b->state == 3) {
                b->state = 4;
                D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.reload = 1;
                D_80109370_167690_BobOmbBarrage->act.held = j;
                D_80109370_167690_BobOmbBarrage->act.state = 0xA;
                D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim = 180.0f;
                rot = 180.0f;
                func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_80109370_167690_BobOmbBarrage->mot[9]), 0, 8, 0);
                break;
            }
        }
        break;
    case 10:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        if (func_80029E3C_2AA3C(mdl) == -1.0f && (s32)func_80029CE4_2A8E4(mdl) >= 0xF) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xB;
            h = D_80109370_167690_BobOmbBarrage->act.held; b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[h];
            func_8002C628_2D228(b->mdl, mdl, D_801091A4_1674C4_BobOmbBarrage);
            func_800298A4_2A4A4(b->mdl, 0x4000, 0x4000);
            b->state = 4;
        }
        break;
    case 11:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        if (func_80108414_166734_BobOmbBarrage(mdl, D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[9]) != 0) {
            mot = D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[10];
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xC;
            D_80109370_167690_BobOmbBarrage->ai.time = D_80109050_167370_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff] * func_801084A4_1667C4_BobOmbBarrage() + D_80109060_167380_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff];
            D_80109370_167690_BobOmbBarrage->ai.t = 0;
            func_80029B80_2A780(mdl, mot);
            h = D_80109370_167690_BobOmbBarrage->act.held; b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[h];
            b->state = 5;
            D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim = 270.0f;
            rot = 270.0f;
            func_800298A4_2A4A4(b->mdl, 0x4000, 0);
            func_800298A4_2A4A4(b->mdl, 4, 4);
            func_8002C628_2D228(b->lit, mdl, D_801091A4_1674C4_BobOmbBarrage);
            func_800298A4_2A4A4(b->lit, 0x4000, 0x4000);
            func_800298A4_2A4A4(b->lit, 4, 0);
        }
        break;
    case 12:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        if (D_80109370_167690_BobOmbBarrage->ai.t > D_80109370_167690_BobOmbBarrage->ai.time) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xD;
            D_80109370_167690_BobOmbBarrage->ai.t = 0;
            D_80109370_167690_BobOmbBarrage->ai.time = func_801084A4_1667C4_BobOmbBarrage() * 40.0f + 180.0f;
            D_80109370_167690_BobOmbBarrage->ai.power = func_801084A4_1667C4_BobOmbBarrage() * 0.8f + 0.1f;
        } else {
            D_80109370_167690_BobOmbBarrage->ai.t++;
        }
        func_80029C74_2A874(mdl, 0.0f);
        break;
    case 13:
    case 14:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        len = func_80029D0C_2A90C(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[10]);
        eight = 8.0f;
        f = D_80109370_167690_BobOmbBarrage->ai.power;
        f += 0.1f - func_801084A4_1667C4_BobOmbBarrage() * 0.05f;
        if (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state != 0xD) {
            if (D_80109370_167690_BobOmbBarrage->ai.t < D_80109370_167690_BobOmbBarrage->ai.time) {
                f = func_801084A4_1667C4_BobOmbBarrage() * 0.1f;
            } else {
                f = 1.0f;
                D_80109370_167690_BobOmbBarrage->ai.t++;
            }
        }
        if (f < 0.1f && D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state != 0xD) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0xF;
            func_80079798_7A398(0x1B1, (s16)D_8010A1C0_1684E0_BobOmbBarrage);
            D_80109370_167690_BobOmbBarrage->power -= ((f - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.0f;
            if (func_801084A4_1667C4_BobOmbBarrage() < 0.3f) {
                k = func_801084A4_1667C4_BobOmbBarrage();
                r = D_80109070_167390_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff];
            } else {
                k = func_801084A4_1667C4_BobOmbBarrage();
                r = D_80109080_1673A0_BobOmbBarrage[D_80109370_167690_BobOmbBarrage->diff];
            }
            r *= 0.5f - k;
            ang = r + D_80109370_167690_BobOmbBarrage->rotAim;
            if (ang > 360.0f) {
                ang -= 360.0f;
            } else if (ang < 0.0f) {
                ang += 360.0f;
            }
            h = D_80109370_167690_BobOmbBarrage->act.held; b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[h];
            D_80109370_167690_BobOmbBarrage->act.held = -1;
            func_800298A4_2A4A4(b->lit, 0x4000, 0);
            func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[11]), 0, 8, 0);
            b->state = 6;
            func_800B3170_B3D70(&b->pos, &D_80109370_167690_BobOmbBarrage->pos);
            b->pos.y = D_80109370_167690_BobOmbBarrage->pos.y + 100.0f;
            b->pos.z = D_80109370_167690_BobOmbBarrage->pos.z - 50.0f;
            b->vel.x = -D_80109370_167690_BobOmbBarrage->power * 10.0f * func_800B7890_B8490(ang);
            b->vel.z = D_80109370_167690_BobOmbBarrage->power * 10.0f * HuMathSin(ang);
            b->vel.y = D_80109370_167690_BobOmbBarrage->power * 1.5f * 10.0f;
            func_800298A4_2A4A4(b->shadow, 4, 0);
            func_80029C74_2A874(mdl, 0.0f);
        } else if (f > 0.1f) {
            D_80109370_167690_BobOmbBarrage->act.state = 0xE;
            D_80109370_167690_BobOmbBarrage->power = ((f - 0.1f) * 1.1111112f * 0.9f + 0.1f) * 5.0f;
            d.x = D_801093A0_1676C0_BobOmbBarrage[0].pos.x - D_80109370_167690_BobOmbBarrage->pos.x;
            d.z = D_801093A0_1676C0_BobOmbBarrage[0].pos.z - D_80109370_167690_BobOmbBarrage->pos.z;
            a = func_800B75A8_B81A8(d.x, d.z);
            if (a < 0.0f) {
                a += 360.0f;
            }
            a += 90.0f;
            if (a > 360.0f) {
                a -= 360.0f;
            }
            c1 = a >= 180.0f;
            c2 = a < 360.0f;
            rot = a;
            if (c1 & c2) {
                D_80109370_167690_BobOmbBarrage->rotShow = a;
                D_80109370_167690_BobOmbBarrage->rotAim = a;
                D_80109370_167690_BobOmbBarrage->rotShow = a;
            } else {
                rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
            }
            func_80029C74_2A874(mdl, (len - eight) * f + eight);
        }
        break;
    case 15:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        if (func_80108414_166734_BobOmbBarrage(mdl, D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[11]) != 0) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0;
            func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[0]), 0, 8, 2);
        }
        break;
    case 16:
        if (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.timer > 0x28) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0;
            func_80029B80_2A780(mdl, D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[0]);
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.timer = 0;
        } else {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.timer++;
        }
        break;
    case 5:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        break;
    case 6:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 7;
        mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
        func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[7]), 0, 8, 0);
        break;
    case 7:
        rot = D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim;
        if (func_80108414_166734_BobOmbBarrage(mdl, D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[7]) != 0) {
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0x19;
        }
        break;
    case 8:
        D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim = 270.0f;
        D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 9;
        rot = 270.0f;
        break;
    case 25:
    default:
        rot = 270.0f;
        D_80109370_167690_BobOmbBarrage->rotShow = D_80109370_167690_BobOmbBarrage->rotAim = 270.0f;
        break;
    }
    m = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4];
    rot -= 90.0f;
    if (rot < 0.0f) {
        rot += 360.0f;
    }
    func_80029714_2A314(m, D_80109370_167690_BobOmbBarrage->pos.x, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
    func_8002979C_2A39C(m, 0.0f, rot, 0.0f);
    func_800297E8_2A3E8(m, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 2; i++) {
        func_80107700_165A20_BobOmbBarrage(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_8010684C_164B6C_BobOmbBarrage);
#endif

// register allocation only (masked 0, raw 57): state/fuse in s3/s2 swapped, shadow scale in f4 not f0
#ifdef NON_MATCHING
void func_80107700_165A20_BobOmbBarrage(s32 slot) {
    Vec from;
    Vec to;
    Vec d;
    BBStart* st;
    f32 f;
    f32 k;
    f32 y;
    f32 py;
    s32 state;
    s32 fuse;
    s32 hit;
    s32 pl;
    s32 ready;
    s32 len;
    BBBomb* b;

    b = &D_80109370_167690_BobOmbBarrage->act.u.bomb[slot];
    state = b->state;
    fuse = b->fuse;
    switch (state) {
    case 0:
        b->t = 0;
        break;
    case 1:
        if (D_80109370_167690_BobOmbBarrage->act.reload != 0) {
            state = 2;
            b->t = 0;
            D_80109370_167690_BobOmbBarrage->act.reload = 0;
            func_800298A4_2A4A4(b->mdl, 4, 0);
            func_800298A4_2A4A4(b->shadow, 4, 0);
            HuVecCopyXYZ(&b->pos, D_80109370_167690_BobOmbBarrage->pos.x + 100.0f, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z + 140.0f);
        }
        break;
    case 2:
        k = b->t / 20.0f;
        st = &D_80108F20_167240_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage];
        from.x = to.x = st->pos.x + 100.0f;
        from.y = to.y = st->pos.y;
        to.z = st->pos.z;
        from.z = to.z + 140.0f;
        b->pos.x = (to.x - from.x) * k + from.x;
        b->pos.z = from.y;
        b->pos.z = (to.z - from.z) * k + from.z;
        b->t++;
        if (b->t >= 14.0f) {
            state = 3;
            b->t = 0;
        }
        break;
    case 3:
        func_800298A4_2A4A4(b->mdl, 4, 0);
        func_800298A4_2A4A4(b->shadow, 4, 0);
        break;
    case 4:
        state = 5;
        fuse = 0;
        break;
    case 5:
        func_800298A4_2A4A4(b->shadow, 4, 4);
        break;
    case 6:
        f = HuVecGetLength3F(&b->vel);
        if (f > 40.0f && b->vel.y < 0.0f) {
            f = 1.0f / f * 40.0f;
            from.x = f * b->vel.x;
            from.y = f * b->vel.y;
            from.z = f * b->vel.z;
        } else {
            from.x = b->vel.x;
            from.y = b->vel.y;
            from.z = b->vel.z;
        }
        b->pos.x += from.x;
        b->pos.y += from.y;
        b->pos.z += from.z;
        b->vel.y -= 4.0f;
        hit = func_80108114_166434_BobOmbBarrage(b);
        if (hit == 4) {
            func_800794A8_7A0A8(0x4B);
            PlaySound(0x1B3);
            D_80109394_1676B4_BobOmbBarrage = 6;
            D_801093A0_1676C0_BobOmbBarrage[0].act.held = 0;
            D_801093A0_1676C0_BobOmbBarrage[0].act.state = 0;
            b->pos.y = 4.0f;
            state = 0xA;
            func_80108844_166B64_BobOmbBarrage();
        } else if (func_80108308_166628_BobOmbBarrage(b) == 0 && hit != -1) {
            state = 7;
            fuse = 0;
            func_800298A4_2A4A4(b->mdl, 4, 4);
            func_800298A4_2A4A4(b->lit, 4, 4);
            func_800298A4_2A4A4(b->shadow, 4, 4);
            func_800298A4_2A4A4(b->blast, 4, 0);
            func_80029714_2A314(b->blast, b->pos.x, b->pos.y, b->pos.z);
            func_8002979C_2A39C(b->blast, 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(b->blast, 1.0f, 1.0f, 1.0f);
            func_80029FE4_2ABE4(b->blast, 1.0f);
            func_80029C74_2A874(b->blast, 0.0f);
            if (hit == 2) {
                func_800298A4_2A4A4(b->splash, 4, 0);
                func_80029714_2A314(b->splash, b->pos.x, 0.0f, b->pos.z);
                func_80029FE4_2ABE4(b->splash, 1.0f);
                func_80029C74_2A874(b->splash, 0.0f);
                func_80029714_2A314(b->blast, b->pos.x, -10000.0f, b->pos.z);
            }
        }
        py = b->pos.y;
        if (py < -200.0f) {
            state = 7;
        } else if (py > 4000.0f) {
            state = 7;
        }
        break;
    case 7:
        HuVecCopyXYZ(&b->pos, D_80109370_167690_BobOmbBarrage->pos.x + 200.0f, D_80109370_167690_BobOmbBarrage->pos.y, D_80109370_167690_BobOmbBarrage->pos.z);
        state = 8;
        break;
    case 8:
        y = func_80029CE4_2A8E4(b->splash);
        if (func_80029D0C_2A90C(b->splash) <= y) {
            func_800298A4_2A4A4(b->splash, 4, 4);
        }
        len = func_80029D0C_2A90C(b->blast);
        if ((s32)func_80029CE4_2A8E4(b->blast) >= len) {
            func_800298A4_2A4A4(b->blast, 4, 4);
            ready = 1;
        } else {
            ready = 0;
        }
        if (ready != 0) {
            state = 9;
        }
        break;
    case 9:
        if (D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.reload != 0) {
            if (D_80109394_1676B4_BobOmbBarrage == 5) {
                PlaySound(0x1AF);
            }
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.reload = 0;
            state = 2;
            func_800298A4_2A4A4(b->mdl, 4, 0);
            func_800298A4_2A4A4(b->lit, 4, 4);
            func_800298A4_2A4A4(b->shadow, 4, 0);
            func_800B3170_B3D70(&b->pos, &D_80108F20_167240_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].pos);
            b->pos.x += 100.0f;
            b->pos.z += 200.0f;
            b->t = 0;
            fuse = 0;
        }
        break;
    }
    switch (b->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 7:
        break;
    case 4:
    case 5:
    case 6:
        fuse++;
        break;
    }
    if (fuse > 0xF0) {
        fuse = 0;
        state = 7;
        PlaySound(0x1AE);
        if (b->state != 6) {
            pl = func_80108D24_167044_BobOmbBarrage(D_8010A1C0_1684E0_BobOmbBarrage);
            func_800797DC_7A3DC(0x111, pl);
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.state = 0x10;
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.timer = 0;
            func_800298A4_2A4A4(b->lit, 0x4000, 0);
            D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].act.held = -1;
            omVibrate(pl, 0x14, 0, 0x14);
            func_80029B80_2A780(D_8010A1C8_1684E8_BobOmbBarrage[2]->model[D_8010A1C0_1684E0_BobOmbBarrage + 4], D_801093A0_1676C0_BobOmbBarrage[D_8010A1C0_1684E0_BobOmbBarrage].mot[4]);
            func_800B3170_B3D70(&from, &D_80109370_167690_BobOmbBarrage->pos);
            from.y += 50.0f;
            HuVecCopyXYZ(&b->pos, from.x, from.y, from.z);
        }
        func_800298A4_2A4A4(b->lit, 4, 4);
        func_800298A4_2A4A4(b->shadow, 4, 4);
        func_800298A4_2A4A4(b->blast, 4, 0);
        func_80029714_2A314(b->blast, b->pos.x, b->pos.y, b->pos.z);
        func_8002979C_2A39C(b->blast, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(b->blast, 1.0f, 1.0f, 1.0f);
        func_80029FE4_2ABE4(b->blast, 1.0f);
        func_80029C74_2A874(b->blast, 0.0f);
        func_8003E52C_3F12C(b->fx, 0);
    }
    if ((fuse & 8) == 0) {
        if (fuse > 0xC8) {
            func_8003E52C_3F12C(b->fx, 4);
        } else if (fuse > 0xA0) {
            func_8003E52C_3F12C(b->fx, 3);
        } else if (fuse > 0x78) {
            func_8003E52C_3F12C(b->fx, 2);
        } else if (fuse > 0x50) {
            func_8003E52C_3F12C(b->fx, 1);
        } else {
            func_8003E52C_3F12C(b->fx, 0);
        }
    } else {
        func_8003E52C_3F12C(b->fx, 0);
    }
    b->state = state;
    b->fuse = fuse;
    func_80029714_2A314(b->mdl, b->pos.x, b->pos.y, b->pos.z);
    func_80029714_2A314(b->lit, b->pos.x, b->pos.y, b->pos.z);
    d.x = (b->pos.x - 0.0f) * 0.68;
    d.z = b->pos.z - -120.0f;
    if (d.x * d.x + d.z * d.z < 476100.0f) {
        y = 0.0f;
    } else {
        y = 200.0f;
    }
    f = 1.0f - (b->pos.y - y) * 0.001f;
    if (f > 1.0f) {
        f = 1.0f;
    }
    func_800297E8_2A3E8(b->shadow, f, 1.0f, f);
    func_80029714_2A314(b->shadow, b->pos.x, y, b->pos.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_80107700_165A20_BobOmbBarrage);
#endif

s32 func_80108114_166434_BobOmbBarrage(BBBomb* b) {
    Vec d;
    f32 r;
    f32 dist;
    s32 ret;

    if (b->pos.y < 100.0f && b->pos.y > -50.0f) {
        d.x = b->pos.x - D_801093A0_1676C0_BobOmbBarrage->pos.x;
        d.z = b->pos.z - D_801093A0_1676C0_BobOmbBarrage->pos.z;
        dist = d.x * d.x + d.z * d.z;
        if (dist < 16900.0f) {
            return 4;
        }
    }
    r = 630.0f;
    if (b->pos.y < 0.0f) {
        d.x = (b->pos.x - 0.0f) * 0.68;
        d.z = b->pos.z - -120.0f;
        dist = d.x * d.x + d.z * d.z;
        if (dist < 396900.0f) {
            b->pos.y = 0.0f;
            func_80079798_7A398(0x1B0, (s16)D_8010A1C0_1684E0_BobOmbBarrage);
            return 2;
        }
    }
    ret = -1;
    if (b->pos.y < 100.0f) {
        d.x = (b->pos.x - 0.0f) * 0.68;
        d.z = b->pos.z - -120.0f;
        dist = d.x * d.x + d.z * d.z;
        if (dist > r * r) {
            func_80079798_7A398(0x1AD, (s16)D_8010A1C0_1684E0_BobOmbBarrage);
            ret = 0;
        }
    }
    return ret;
}

s32 func_80108308_166628_BobOmbBarrage(BBBomb* b) {
    Vec d;

    if (b->pos.y < 100.0f && b->pos.y > -5.0f) {
        d.x = b->pos.x - D_801093A0_1676C0_BobOmbBarrage->pos.x;
        d.z = b->pos.z - D_801093A0_1676C0_BobOmbBarrage->pos.z;
        if (d.x * d.x + d.z * d.z < 22500.0f && b->vel.y < 0.0f) {
            b->vel.y *= -0.5f;
            b->vel.x *= 0.8f;
            b->vel.z *= 0.8f;
            PlaySound(0x1B2);
        }
    }
    return 0;
}

s32 func_80108414_166734_BobOmbBarrage(s16 mdl, s16 mot) {
    s32 len = func_80029D0C_2A90C(mot);

    if (func_80029E3C_2AA3C(mdl) == -1.0f && (s32)func_80029CE4_2A8E4(mdl) >= len) {
        return 1;
    }
    return 0;
}

f32 func_801084A4_1667C4_BobOmbBarrage(void) {
    return (rand8() & 0xFF) * 0.00390625f;
}

void func_801084E0_166800_BobOmbBarrage(void) {
    s32 i;
    u16 mdl;

    for (i = 1; i < 4; i++) {
        D_801093A0_1676C0_BobOmbBarrage[i].act.state = 8;
        mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[i + 4];
        func_80029B80_2A780(mdl, D_801093A0_1676C0_BobOmbBarrage[i].mot[8]);
    }
    mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[4];
    D_801093A0_1676C0_BobOmbBarrage[0].act.state = 7;
    func_80029B80_2A780(mdl, D_801093A0_1676C0_BobOmbBarrage[0].mot[7]);
    func_800732B0_73EB0(D_80108EEC_16720C_BobOmbBarrage[gPlayers[(s16)func_80108D24_167044_BobOmbBarrage(0)].character][9]);
}

void func_801085DC_1668FC_BobOmbBarrage(void) {
    s32 i;

    for (i = 1; i < 4; i++) {
        D_801093A0_1676C0_BobOmbBarrage[i].act.state = 6;
        func_800732B0_73EB0(D_80108EEC_16720C_BobOmbBarrage[gPlayers[(s16)func_80108D24_167044_BobOmbBarrage(i)].character][9]);
    }
}

void func_8010868C_1669AC_BobOmbBarrage(void) {
    s32 i;
    s32 held;
    u16 mdl;
    s32 j;
    BBBomb* b;

    for (i = 1; i < 4; i++) {
        held = D_801093A0_1676C0_BobOmbBarrage[i].act.held;
        b = &D_801093A0_1676C0_BobOmbBarrage[i].act.u.bomb[held];
        if (held != -1) {
            func_800298A4_2A4A4(b->mdl, 0x4000, 0);
        }
        for (j = 0; j < 2; j++) {
            b = &D_801093A0_1676C0_BobOmbBarrage[i].act.u.bomb[j];
            b->state = 0;
            func_800298A4_2A4A4(b->mdl, 4, 4);
            func_800298A4_2A4A4(b->lit, 4, 4);
            func_800298A4_2A4A4(b->shadow, 4, 4);
            func_800298A4_2A4A4(b->blast, 4, 4);
            func_800298A4_2A4A4(b->splash, 4, 4);
        }
        D_801093A0_1676C0_BobOmbBarrage[i].act.state = 8;
        mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[i + 4];
        func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[i].mot[0]), 0, 0x14, 0);
    }
}

void func_80108844_166B64_BobOmbBarrage(void) {
    s32 i;
    s32 held;
    u16 mdl;
    BBBomb* b;

    for (i = 1; i < 4; i++) {
        held = D_801093A0_1676C0_BobOmbBarrage[i].act.held;
        b = &D_801093A0_1676C0_BobOmbBarrage[i].act.u.bomb[held];
        if (held != -1) {
            func_800298A4_2A4A4(b->mdl, 0x4000, 0);
            func_800298A4_2A4A4(b->mdl, 4, 4);
            func_800298A4_2A4A4(b->lit, 4, 4);
            func_800298A4_2A4A4(b->shadow, 4, 4);
            func_800298A4_2A4A4(b->blast, 4, 4);
            func_800298A4_2A4A4(b->splash, 4, 4);
        }
        D_801093A0_1676C0_BobOmbBarrage[i].act.state = 8;
        mdl = D_8010A1C8_1684E8_BobOmbBarrage[2]->model[i + 4];
        func_80029BF0_2A7F0(mdl, func_80029E14_2AA14(D_801093A0_1676C0_BobOmbBarrage[i].mot[0]), 0, 0x14, 0);
    }
}

void func_80108998_166CB8_BobOmbBarrage(void) {
    func_8010868C_1669AC_BobOmbBarrage();
}

void func_801089B4_166CD4_BobOmbBarrage(void) {
    D_80109378_167698_BobOmbBarrage.state = -1;
}

void func_801089C4_166CE4_BobOmbBarrage(f32 from, f32 to, s32 time) {
    D_80109378_167698_BobOmbBarrage.state = 0;
    D_80109378_167698_BobOmbBarrage.t = 0;
    D_80109378_167698_BobOmbBarrage.time = time;
    D_80109378_167698_BobOmbBarrage.from = from;
    D_80109378_167698_BobOmbBarrage.to = to;
}

// register allocation (masked 0, raw 14; the rest are symbol names for the same addresses): retail keeps
// 1.0f in f4, k in f2, -k in f0. Tried: no `one` local (same), the ratio folded into k (raw 22).
#ifdef NON_MATCHING
void func_801089E4_166D04_BobOmbBarrage(void) {
    f32 one;
    f32 k;
    f32 u;
    f32 a;

    u = (f32)D_80109378_167698_BobOmbBarrage.t / (f32)D_80109378_167698_BobOmbBarrage.time;
    one = 1.0f;
    k = u - one;
    u = -k * k + one;
    if (u < 0.0f) {
        u = 0.0f;
    }
    if (u > 1.0f) {
        u = 1.0f;
    }
    a = (D_80109378_167698_BobOmbBarrage.to - D_80109378_167698_BobOmbBarrage.from) * u + D_80109378_167698_BobOmbBarrage.from;
    if (a < 0.0f) {
        a += 360.0f;
    }
    D_801093A0_1676C0_BobOmbBarrage[0].rot = D_801093A0_1676C0_BobOmbBarrage[0].rotAim = a;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_801089E4_166D04_BobOmbBarrage);
#endif

void func_80108AB0_166DD0_BobOmbBarrage(f32 height, s32 time) {
    D_80109378_167698_BobOmbBarrage.state = 1;
    D_80109378_167698_BobOmbBarrage.t = 0;
    D_80109378_167698_BobOmbBarrage.time = time;
    D_80109378_167698_BobOmbBarrage.y = 0.0f;
    D_80109378_167698_BobOmbBarrage.height = height;
}

// register allocation (masked 0): retail keeps u in f2 and 1.0f in f4 (as func_801089E4_166D04). Tried: no
// `one` local (same), a separate ratio local (raw 26), `one` set before k (masked 5). S3-R11: `k * -k` gives
// retail's registers but mul.s operands swapped; -(u - one) * (u - one) on a reused u, compound forms (same).
#ifdef NON_MATCHING
void func_80108AD4_166DF4_BobOmbBarrage(void) {
    f32 k;
    f32 u;
    f32 one;
    f32 h;

    u = (f32)D_80109378_167698_BobOmbBarrage.t / (f32)D_80109378_167698_BobOmbBarrage.time;
    k = 2.0f * u;
    one = 1.0f;
    k -= one;
    u = -k * k + one;
    if (u < 0.0f) {
        u = 0.0f;
    }
    if (u > 1.0f) {
        u = 1.0f;
    }
    h = u * D_80109378_167698_BobOmbBarrage.height;
    if (h < 0.0f) {
        h = 0.0f;
    }
    D_80109378_167698_BobOmbBarrage.y = h;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/161980", func_80108AD4_166DF4_BobOmbBarrage);
#endif

s32 func_80108B80_166EA0_BobOmbBarrage(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            return i;
        }
    }
    return 0;
}

void func_80108BCC_166EEC_BobOmbBarrage(void) {
    s32 i;
    s32 n;
    s32 c;

    for (i = 0; i < 4; i++) {
        D_80109358_167678_BobOmbBarrage[i] = -1;
    }
    D_80109358_167678_BobOmbBarrage[0] = func_80108B80_166EA0_BobOmbBarrage();
    n = func_801084A4_1667C4_BobOmbBarrage() * 2.9999f;
    for (i = 0, c = 0; i < 4; i++) {
        if (D_80109358_167678_BobOmbBarrage[0] == i) {
            continue;
        }
        if (n == c) {
            break;
        }
        c++;
    }
    D_80109358_167678_BobOmbBarrage[1] = i;
    n = func_801084A4_1667C4_BobOmbBarrage() * 1.9999f;
    for (i = 0, c = 0; i < 4; i++) {
        if (D_80109358_167678_BobOmbBarrage[0] == i || D_80109358_167678_BobOmbBarrage[1] == i) {
            continue;
        }
        if (n == c) {
            break;
        }
        c++;
    }
    D_80109358_167678_BobOmbBarrage[2] = i;
    for (i = 0; i < 4; i++) {
        if (D_80109358_167678_BobOmbBarrage[0] != i && D_80109358_167678_BobOmbBarrage[1] != i && D_80109358_167678_BobOmbBarrage[2] != i) {
            break;
        }
    }
    D_80109358_167678_BobOmbBarrage[3] = i;
}

s32 func_80108D24_167044_BobOmbBarrage(s32 i) {
    return D_80109358_167678_BobOmbBarrage[i];
}
