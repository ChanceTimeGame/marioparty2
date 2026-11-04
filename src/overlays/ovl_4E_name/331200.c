#include "ovl_4E.h"

/* .data (0x335070-0x335190, 8010D6B0-8010D7D0) */
u8 D_8010D6B0_335070_name_4E[8] = { 5, 3, 3, 3, 3, 3, 3, 3 };
/* slot rectangles by count (D_8010D760 points at them) */
Ovl4ERect D_8010D6B8_335078_name_4E[1] = { { 0x3C, -124, 0xC8, 0x14 } };
Ovl4ERect D_8010D6C0_335080_name_4E[2] = { { 0x3C, -134, 0xC8, 0x14 }, { 0x3C, -114, 0xC8, 0x14 } };
Ovl4ERect D_8010D6D0_335090_name_4E[3] = { { 0x3C, -144, 0xC8, 0x14 }, { 0x3C, -124, 0xC8, 0x14 }, { 0x3C, -104, 0xC8, 0x14 } };
Ovl4ERect D_8010D6E8_3350A8_name_4E[4] = {
    { 0x3C, -154, 0xC8, 0x14 }, { 0x3C, -134, 0xC8, 0x14 }, { 0x3C, -114, 0xC8, 0x14 }, { 0x3C, -94, 0xC8, 0x14 },
};
Ovl4ERect D_8010D708_3350C8_name_4E[5] = {
    { 0x3C, -164, 0xC8, 0x14 }, { 0x3C, -144, 0xC8, 0x14 }, { 0x3C, -124, 0xC8, 0x14 }, { 0x3C, -104, 0xC8, 0x14 },
    { 0x3C, -84, 0xC8, 0x14 },
};
Ovl4ERect D_8010D730_3350F0_name_4E[6] = {
    { 0x3C, -174, 0xC8, 0x14 }, { 0x3C, -154, 0xC8, 0x14 }, { 0x3C, -134, 0xC8, 0x14 },
    { 0x3C, -114, 0xC8, 0x14 }, { 0x3C, -94, 0xC8, 0x14 },  { 0x3C, -74, 0xC8, 0x14 },
};
Ovl4ERect* D_8010D760_335120_name_4E[7] = {
    D_8010D6B8_335078_name_4E, D_8010D6B8_335078_name_4E, D_8010D6C0_335080_name_4E, D_8010D6D0_335090_name_4E,
    D_8010D6E8_3350A8_name_4E, D_8010D708_3350C8_name_4E, D_8010D730_3350F0_name_4E,
};
u8 D_8010D77C_33513C_name_4E[8] = { 0x0A, 0x0A, 0x14, 0x1E, 0x28, 0x32, 0x3C, 0x00 };
s16 D_8010D784_335144_name_4E[8] = { 0x72, 0x72, 0x68, 0x5E, 0x54, 0x4A, 0x40, 0 };
s8 D_8010D794_335154_name_4E[4][2] = { { 1, 0 }, { 9, 15 }, { 11, 8 }, { 13, 0 } };
s32 D_8010D79C_33515C_name_4E = 0;
u32 D_8010D7A0_335160_name_4E = 0;
u32 D_8010D7A4_335164_name_4E = 0;
u32 D_8010D7A8_335168_name_4E = 0;
u32 D_8010D7AC_33516C_name_4E = 0;
f32 D_8010D7B0_335170_name_4E = 58.0f;
f32 D_8010D7B4_335174_name_4E = 0.0f;
s32 D_8010D7B8_335178_name_4E[6] = { 0x18, 0x23, 0x37, 0x46, 0x47, 0 };


u32 func_80109840_331200_name_4E(u32 param) {
    s32 rand2, rand3;

    if (param == 0) {
        param = rand8();
        param = param ^ osGetCount();
        param ^= 0xD826BC89;
    }

    rand2 = param / 0x1F31D;
    rand3 = param - (rand2 * 0x1F31D);
    param = rand2 * 0xB14;
    param = param - rand3 * 0x41A7;
    return param;
}

s32 func_80109914_3312D4_name_4E(void) {
    return D_8010D79C_33515C_name_4E = func_80109840_331200_name_4E(D_8010D79C_33515C_name_4E);
}

u32 func_8010993C_3312FC_name_4E(u32 arg0) {
    u32 val;

    val = func_80109840_331200_name_4E(D_8010D79C_33515C_name_4E);
    D_8010D79C_33515C_name_4E = val;
    return val % arg0;
}

void func_80109988_331348_name_4E(void) {
    if (D_800FDC6C_FE86C >= (D_8010D7A0_335160_name_4E + 4)) {
        PlaySound(0x324);
        D_8010D7A0_335160_name_4E = D_800FDC6C_FE86C;
    }
}

/* The roulette: slides in (0), spins and stops on work[2] (1), then notes the pick in the recent
   lists and starts it (2). Scale x = speed, y = reversed once, z = phase. */
void func_801099D4_331394_name_4E(omObjData* obj) {
    s32 i;
    s16 base;
    Ovl4EMgSlot* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                func_800896DC_8A2DC(p->win, (s16)(p->x + p->w / 2), (s32)obj->trans.y + p->y + p->h / 2);
            }
            base = D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E];
            SprPosSet(D_8010DC78_335638_name_4E, 0, 160, base + ((s32)obj->trans.y + D_8010DC30_3355F0_name_4E[0].y));
            if (obj->trans.y >= 218.0f) {
                func_80109988_331348_name_4E();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = MBRand(D_8010DC77_335637_name_4E);
                obj->work[3] = 0;
                func_8010A588_331F48_name_4E();
            }
            break;
        case 1:
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= D_8010DC77_335637_name_4E;
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_8010DC77_335637_name_4E - 1;
                    }
                }
                func_80109988_331348_name_4E();
            }
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(p->win, 0, 200, 0);
                    func_80089B2C_8A72C(p->win, 0x100);
                    func_80089A7C_8A67C(p->win, 9000);
                } else {
                    func_8008D530_8E130(p->win, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(p->win, 0);
                    func_80089A7C_8A67C(p->win, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                obj->scale.x -= 0.02;
            }
            if (obj->scale.x <= 0.08f) {
                obj->scale.x = 0.08f;
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((rand8() & 0xF) || obj->scale.y == 1.0f || obj->work[1] == 0) {
                        PlaySound(0x325);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8008AD84_8B984();
                        func_8008AD44_8B944(D_8010DC30_3355F0_name_4E[obj->work[1]].win);
                        func_800890CC_89CCC(D_8010DC30_3355F0_name_4E[obj->work[1]].win, D_8010DC70_335630_name_4E[obj->work[1]] + 0x3D8, -2, 4);
                        switch (D_8010DC70_335630_name_4E[obj->work[1]]) {
                            case 0x19:
                            case 0x24:
                            case 0x38:
                                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 4);
                                break;
                            default:
                                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 1);
                                break;
                        }
                        func_80089DA0_8A9A0(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                        func_8008D530_8E130(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                        func_80089A48_8A648(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0);
                    } else {
                        obj->scale.y = 1.0f;
                        obj->work[2]--;
                        if (obj->work[2] >= 128) {
                            obj->work[2] = D_8010DC77_335637_name_4E - 1;
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                OVL4E_RECENT(D_8010DC76_335636_name_4E)[OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E)] = D_8010DC70_335630_name_4E[obj->work[2]];
                OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E)++;
                OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E) %= D_8010DC77_335637_name_4E;
                func_80067E6C_68A6C(D_8010DC70_335630_name_4E[obj->work[2]]);
                func_8010A300_331CC0_name_4E();
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_8010D794_335154_name_4E + i))[0]); i++) {
        }
        base = D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E];
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, D_8010D794_335154_name_4E[i][1] + 50, base + obj->work[1] * 20);
    }
}

void func_8010A244_331C04_name_4E(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 5; j++) {
            OVL4E_RECENT(i)[j] = -1;
        }
        OVL4E_RECENT_IDX(i) = 0;
    }
}

void func_8010A2A0_331C60_name_4E(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8010DC30_3355F0_name_4E); i++) {
        D_8010DC30_3355F0_name_4E[i].win = -1;
    }

    D_8010DC6C_33562C_name_4E = 0;
    D_8010DC7A_33563A_name_4E = -1;
    D_8010DC78_335638_name_4E = -1;
    D_8010DC7E_33563E_name_4E = -1;
    D_8010DC7C_33563C_name_4E = -1;
}

void func_8010A300_331CC0_name_4E(void) {
    s32 i;
    Ovl4EMgSlot* p;

    for (i = 0; i < ARRAY_COUNT(D_8010DC30_3355F0_name_4E); i++) {
        p = &D_8010DC30_3355F0_name_4E[i];
        if (p->win != -1) {
            func_8008CCA8_8D8A8(p->win);
            p->win = -1;
        }
    }
    if (D_8010DC6C_33562C_name_4E != NULL) {
        omDelObj(D_8010DC6C_33562C_name_4E);
        D_8010DC6C_33562C_name_4E = NULL;
    }
    if (D_8010DC78_335638_name_4E != -1) {
        SprKill(D_8010DC78_335638_name_4E);
        D_8010DC78_335638_name_4E = -1;
    }
    if (D_8010DC7A_33563A_name_4E != -1) {
        SprAnimKill(D_8010DC7A_33563A_name_4E);
        D_8010DC7A_33563A_name_4E = -1;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        SprKill(D_8010DC7C_33563C_name_4E);
        D_8010DC7C_33563C_name_4E = -1;
    }
    if (D_8010DC7E_33563E_name_4E != -1) {
        SprAnimKill(D_8010DC7E_33563E_name_4E);
        D_8010DC7E_33563E_name_4E = -1;
    }
}

void func_8010A438_331DF8_name_4E(s32 arg0) {
    void* temp_s0;

    if (D_8010DC78_335638_name_4E == -1) {
        D_8010DC78_335638_name_4E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA0165);
        D_8010DC7A_33563A_name_4E = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_8010DC78_335638_name_4E, 0, D_8010DC7A_33563A_name_4E, 0);
        SprPrioSet(D_8010DC78_335638_name_4E, 0, 0x3000);
        SprAttrSet(D_8010DC78_335638_name_4E, 0, 0x1000);
        SprPosSet(D_8010DC78_335638_name_4E, 0, 0xA0, D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E] + D_8010DC30_3355F0_name_4E[0].y);
        if (arg0 != 0 && !(rand8() & 1)) {
            func_80082450_83050(D_8010DC78_335638_name_4E, 0, 0xAD, 0x71, 0xFE);
        } else {
            func_80082450_83050(D_8010DC78_335638_name_4E, 0, 0x35, 0x9D, 0xE6);
        }
    }
}

void func_8010A588_331F48_name_4E(void) {
    void* temp_s0;

    if (D_8010DC7C_33563C_name_4E == -1) {
        D_8010DC7C_33563C_name_4E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA001B);
        D_8010DC7E_33563E_name_4E = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_8010DC7C_33563C_name_4E, 0, D_8010DC7E_33563E_name_4E, 0);
        SprPrioSet(D_8010DC7C_33563C_name_4E, 0, 1);
        SprAttrSet(D_8010DC7C_33563C_name_4E, 0, 0x1000);
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, 0x32, D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E]);
    }
}

/* The roulette of category sel: fresh minigames first (the recent list only if too few), shuffled;
   the first slots go on screen. */
/* NON_MATCHING: register allocation (masked 0): retail keeps id in s1, i in s2, n in s3; three attempts at splitting variables swapped them */
// decomp-permuter
void func_8010A660_332020_name_4E(u32 arg0)
{
  s32 sel;
  s16 n;
  s16 cnt;
  s16 *list;
  s16 *p;
  Ovl4ERect *rects;
  s32 id;
  s32 i;
  s32 j;
  s32 k;
  Ovl4EMgSlot *slot;
  omObjData *obj;
  sel = (arg0 < 9) ? (arg0) : (0);
  D_8010DC76_335636_name_4E = sel;
  func_8010CF6C_33492C_name_4E();
  n = D_8010DCA0_335660_name_4E[sel];
  D_8010DC77_335637_name_4E = D_8010D6B0_335070_name_4E[sel];
  if (sel == 0)
  {
    if (D_8010DC77_335637_name_4E > n)
    {
      D_8010DC77_335637_name_4E = 3;
    }
  }
  else
    if (sel == 7)
  {
    if (D_8010DC77_335637_name_4E > n)
    {
      D_8010DC77_335637_name_4E = 2;
    }
  }
  switch (D_8010DC77_335637_name_4E)
  {
    case 2:
      rects = D_8010D6C0_335080_name_4E;
      break;

    case 3:
      rects = D_8010D6D0_335090_name_4E;
      break;

    case 4:

    default:
      rects = D_8010D708_3350C8_name_4E;
      break;

  }

  list = HuMemMemoryAllocPerm(0x100);
  p = list;
  for (i = 0; i < 0x80; i++)
  {
    *p = -1;
    p++;
  }

  cnt = 0;
  p = list;
  for (i = 0; i < n; i++)
  {
    id = D_8010DCC0_335680_name_4E[sel][i];
    if (n > D_8010DC77_335637_name_4E)
    {
      for (j = 0; j < D_8010DC77_335637_name_4E; j++)
      {
        if (id == D_800FD3E4_FDFE4.recent[sel][j])
        {
          break;
        }
      }

      if (j < D_8010DC77_335637_name_4E)
      {
        continue;
      }
    }
    *p = id;
    p++;
    cnt++;
  }

  for (j = 0; cnt < D_8010DC77_335637_name_4E; j++)
  {
    if (j >= D_8010DC77_335637_name_4E)
    {
      break;
    }
    id = D_800FD3E4_FDFE4.recent[sel][j];
    if (id >= 0)
    {
      for (i = 0; i < cnt; i++)
      {
        if (list[i] == id)
        {
          break;
        }
      }

      if (i >= cnt)
      {
        *p = id;
        p++;
        cnt++;
      }
    }
  }

  i = 8000;
  n = cnt;
  for (; i != 0; i--)
  {
    k = func_8010993C_3312FC_name_4E(n);
    id = list[k];
    j = func_8010993C_3312FC_name_4E(n);
    list[k] = list[j];
    list[j] = id;
  }

  for (i = 0; i < D_8010DC77_335637_name_4E; i++)
  {
    slot = &D_8010DC30_3355F0_name_4E[i];
    slot->x = rects[i].x;
    slot->y = rects[i].y;
    slot->w = rects[i].w;
    slot->h = rects[i].h;
    slot->win = func_800888A8_894A8(slot->x + (slot->w / 2), slot->y + (slot->h / 2), slot->w, slot->h, 0, 4);
    func_80089A7C_8A67C(slot->win, 9000);
    func_8008D88C_8E48C(slot->win);
    func_800898F0_8A4F0(slot->win, slot->w / 2, slot->h / 2);
    func_80089B2C_8A72C(slot->win, 0);
    D_8010DC70_335630_name_4E[i] = list[i];
    func_8008AD84_8B984();
    func_800890CC_89CCC(slot->win, D_8010DC70_335630_name_4E[i] + 0x3D8, -2, 4);
    func_80089C78_8A878(slot->win, D_800CBD77_CC977[D_8010DC70_335630_name_4E[i]]);
    func_80089A48_8A648(id = slot->win, 0);
  }

  HuMemMemoryFreePerm(list);
  obj = omAddObj(-0x8000, 0, 0, -1, func_801099D4_331394_name_4E);
  D_8010DC6C_33562C_name_4E = obj;
  obj->work[0] = 3;
  obj->trans.y = 0.0f;
  obj->rot.z = 0.0f;
  func_8010A438_331DF8_name_4E(1);
}

void func_8010AB48_332508_name_4E(void) {
    D_8010DC6C_33562C_name_4E->work[0] = 0;
}

s16 func_8010AB58_332518_name_4E(void) {
    return D_8010DC78_335638_name_4E;
}

/* The player's own choice from category 7's list. */
void func_8010AB64_332524_name_4E(void) {
    Ovl4ERect* rects;
    s32 i;
    Ovl4EMgSlot* slot;
    omObjData* obj;

    D_8010DC76_335636_name_4E = 7;
    func_8010CF6C_33492C_name_4E();
    D_8010DC77_335637_name_4E = (D_8010DCA0_335660_name_4E[D_8010DC76_335636_name_4E] < 7) ? D_8010DCA0_335660_name_4E[D_8010DC76_335636_name_4E] : 6;
    rects = D_8010D760_335120_name_4E[D_8010DC77_335637_name_4E];
    for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
        slot = &D_8010DC30_3355F0_name_4E[i];
        slot->x = rects[i].x;
        slot->y = rects[i].y;
        slot->w = rects[i].w;
        slot->h = rects[i].h;
        slot->win = func_800888A8_894A8(slot->x + slot->w / 2, slot->y + slot->h / 2, slot->w, slot->h, 0, 4);
        func_80089A7C_8A67C(slot->win, 9000);
        func_8008D88C_8E48C(slot->win);
        func_800898F0_8A4F0(slot->win, slot->w / 2, slot->h / 2);
        func_80089B2C_8A72C(slot->win, 0);
        D_8010DC70_335630_name_4E[i] = D_8010DCC0_335680_name_4E[D_8010DC76_335636_name_4E][i];
        func_8008AD84_8B984();
        func_800890CC_89CCC(slot->win, D_8010DC70_335630_name_4E[i] + 0x3D8, -2, 4);
        func_80089C78_8A878(slot->win, D_800CBD77_CC977[D_8010DC70_335630_name_4E[i]]);
        func_80089A48_8A648(slot->win, 0);
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_8010ADE0_3327A0_name_4E);
    D_8010DC6C_33562C_name_4E = obj;
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_8010A438_331DF8_name_4E(0);
}

/* func_801099D4_331394_name_4E with the stick: state 1 moves the cursor (work[1]), A takes it, B leaves
   (unless D_800CD414 & 4); work[2] = stick repeat delay. */
void func_8010ADE0_3327A0_name_4E(omObjData* obj) {
    s32 i;
    s16 base;
    s16 x;
    s16 y;
    Ovl4EMgSlot* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                func_800896DC_8A2DC(p->win, (s16)(p->x + p->w / 2), (s32)obj->trans.y + p->y + p->h / 2);
            }
            base = D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E];
            SprPosSet(D_8010DC78_335638_name_4E, 0, 160, base + ((s32)obj->trans.y + D_8010DC30_3355F0_name_4E[0].y));
            if (obj->trans.y >= 218.0f) {
                func_80109988_331348_name_4E();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = 0;
                obj->work[3] = 0;
                func_8010A588_331F48_name_4E();
            }
            break;
        case 1:
            y = 0;
            if (obj->work[2] == 0) {
                x = ContStkX[D_8010E5F4_335FB4_name_4E];
                y = ContStkY[D_8010E5F4_335FB4_name_4E];
            } else {
                obj->work[2]--;
                x = 0;
            }
            i = 0;
            if (ABS(x) > 30 || ABS(y) > 30) {
                obj->work[2] = 7;
                i++;
                if ((x < 0) | (y < 0)) {
                    obj->work[1]++;
                    if (obj->work[1] >= D_8010DC77_335637_name_4E) {
                        obj->work[1] = 0;
                    }
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_8010DC77_335637_name_4E - 1;
                    }
                }
            }
            if (i != 0) {
                func_80109988_331348_name_4E();
            }
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(p->win, 0, 200, 0);
                    func_80089B2C_8A72C(p->win, 0x100);
                    func_80089A7C_8A67C(p->win, 9000);
                } else {
                    func_8008D530_8E130(p->win, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(p->win, 0);
                    func_80089A7C_8A67C(p->win, 10000);
                }
            }
            if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x8000) {
                PlaySound(0x325);
                obj->work[0] = 2;
                obj->work[3] = 60;
                func_8008AD84_8B984();
                func_8008AD44_8B944(D_8010DC30_3355F0_name_4E[obj->work[1]].win);
                func_800890CC_89CCC(D_8010DC30_3355F0_name_4E[obj->work[1]].win, D_8010DC70_335630_name_4E[obj->work[1]] + 0x3D8, -2, 4);
                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 1);
                func_80089DA0_8A9A0(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                func_8008D530_8E130(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                func_80089A48_8A648(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0);
            }
            if (!(D_800CD414_CE014 & 4) && (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x4000)) {
                func_80067E6C_68A6C(-1);
                func_8010A300_331CC0_name_4E();
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                func_80067E6C_68A6C(D_8010DC70_335630_name_4E[obj->work[1]]);
                func_8010A300_331CC0_name_4E();
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_8010D794_335154_name_4E + i))[0]); i++) {
        }
        base = D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E];
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, D_8010D794_335154_name_4E[i][1] + 50, base + obj->work[1] * 20);
    }
}

void func_8010B480_332E40_name_4E(s16 arg0) {
    D_8010E5E4_335FA4_name_4E = D_800FD474_FE074 = D_8010E144_335B04_name_4E[arg0].pos;
    D_8010274C_10334C = D_8010E144_335B04_name_4E[arg0].unk0C;
    D_800FA610_FB210 = D_8010E144_335B04_name_4E[arg0].unk18;
}

void func_8010B528_332EE8_name_4E(s16 view, s16 frames, s16 mode, void (*cb)(s16*)) {
    Vec drot;
    Vec dat;
    Vec rot0;
    Vec at0;
    s16 arg[2];
    Vec pad[3]; /* unused; retail's frame has it */
    void (*fn)(s16*);
    f32 d;
    f32 t;
    f32 dzoom;
    f32 zoom0;
    s16 i;

    fn = cb;
    d = D_8010E144_335B04_name_4E[view].pos.x - D_800FD474_FE074.x;
    if (ABS(d) > 180.0f) {
        if (D_8010E144_335B04_name_4E[view].pos.x < D_800FD474_FE074.x) {
            drot.x = d + 360.0f;
        } else {
            drot.x = d - 360.0f;
        }
    } else {
        drot.x = d;
    }
    d = D_8010E144_335B04_name_4E[view].pos.y - D_800FD474_FE074.y;
    if (ABS(d) > 180.0f) {
        if (D_8010E144_335B04_name_4E[view].pos.y < D_800FD474_FE074.y) {
            drot.y = d + 360.0f;
        } else {
            drot.y = d - 360.0f;
        }
    } else {
        drot.y = d;
    }
    d = D_8010E144_335B04_name_4E[view].pos.z - D_800FD474_FE074.z;
    if (ABS(d) > 180.0f) {
        if (D_8010E144_335B04_name_4E[view].pos.z < D_800FD474_FE074.z) {
            drot.z = d + 360.0f;
        } else {
            drot.z = d - 360.0f;
        }
    } else {
        drot.z = d;
    }
    dat.x = D_8010E144_335B04_name_4E[view].unk0C.x - D_8010274C_10334C.x;
    dat.y = D_8010E144_335B04_name_4E[view].unk0C.y - D_8010274C_10334C.y;
    dat.z = D_8010E144_335B04_name_4E[view].unk0C.z - D_8010274C_10334C.z;
    dzoom = D_8010E144_335B04_name_4E[view].unk18 - D_800FA610_FB210;
    at0 = D_8010274C_10334C;
    rot0 = D_800FD474_FE074;
    zoom0 = D_800FA610_FB210;
    arg[1] = frames;
    if (mode == 1 || mode == 2) {
        for (i = 0; i < frames; i++) {
            if (mode != 2) {
                t = HuMathSin(i * 90.0f / frames);
            } else if (i <= frames / 2) {
                t = (1.0f - func_800B7890_B8490(i * 180.0f / frames)) * 0.5f;
            } else {
                t = -func_800B7890_B8490(i * 180.0f / frames) * 0.5f + 0.5f;
            }
            D_8010E5E4_335FA4_name_4E.x = D_800FD474_FE074.x = t * drot.x + rot0.x;
            D_8010E5E4_335FA4_name_4E.y = D_800FD474_FE074.y = t * drot.y + rot0.y;
            D_8010E5E4_335FA4_name_4E.z = D_800FD474_FE074.z = t * drot.z + rot0.z;
            D_8010274C_10334C.x = t * dat.x + at0.x;
            D_8010274C_10334C.y = t * dat.y + at0.y;
            D_8010274C_10334C.z = t * dat.z + at0.z;
            D_800FA610_FB210 = t * dzoom + zoom0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    } else {
        for (i = 0; i <= frames; i++) {
            t = 1.0f / frames * i;
            D_8010E5E4_335FA4_name_4E.x = D_800FD474_FE074.x = t * drot.x + rot0.x;
            D_8010E5E4_335FA4_name_4E.y = D_800FD474_FE074.y = t * drot.y + rot0.y;
            D_8010E5E4_335FA4_name_4E.z = D_800FD474_FE074.z = t * drot.z + rot0.z;
            D_8010274C_10334C.x = t * dat.x + at0.x;
            D_8010274C_10334C.y = t * dat.y + at0.y;
            D_8010274C_10334C.z = t * dat.z + at0.z;
            D_800FA610_FB210 = t * dzoom + zoom0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    }
    func_8010B480_332E40_name_4E(view);
}

/* Flies the camera along a path of keys (ended by zoom 0) at speed units per frame: each key's
   arrival time goes in dist, then every frame takes a spline through four keys. */
void func_8010BCB8_333678_name_4E(Ovl4ECamPoint* path, f32 speed, void (*cb)(s16, s16, s16)) {
    f32 keys[4];
    f32 times[4];
    void (*fn)(s16, s16, s16);
    Ovl4ECamPoint* cur;
    Ovl4ECamPoint* prev;
    f32 total;
    f32 d;
    f32 t;
    f32 dx;
    f32 dy;
    f32 dz;
    s16 i;
    s16 seg;
    s32 k;
    s32 l;
    s16 m;

    prev = 0;
    fn = cb;
    total = 0.0f;
    i = 0;
    cur = path;
    while (cur->zoom != 0.0f) {
        cur->pos.x = HuMathSin(cur->rot.y) * func_800B7890_B8490(cur->rot.x) * cur->zoom + cur->at.x;
        cur->pos.y = -HuMathSin(cur->rot.x) * cur->zoom + cur->at.y;
        cur->pos.z = func_800B7890_B8490(cur->rot.y) * func_800B7890_B8490(cur->rot.x) * cur->zoom + cur->at.z;
        if (i > 0) {
            dx = prev->pos.x - cur->pos.x;
            dy = prev->pos.y - cur->pos.y;
            dz = prev->pos.z - cur->pos.z;
            d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (d == 0.0f) {
                d = speed * 10.0f;
            }
            total += d / speed;
            cur->dist = total;
        }
        prev = cur;
        i++;
        cur = &path[i];
    }
    total -= 10.0f;
    seg = 1;
    for (i = 10; i < total; i++) {
        if (i > path[seg + 1].dist) {
            seg++;
        }
        k = seg;
        times[0] = path[k - 1].dist;
        times[1] = path[k].dist;
        times[2] = path[k + 1].dist;
        times[3] = path[k + 2].dist;
        keys[0] = path[k - 1].at.x;
        keys[1] = path[k].at.x;
        keys[2] = path[k + 1].at.x;
        keys[3] = path[k + 2].at.x;
        l = i;
        t = l;
        D_8010274C_10334C.x = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].at.y;
        keys[1] = path[k].at.y;
        keys[2] = path[k + 1].at.y;
        keys[3] = path[k + 2].at.y;
        D_8010274C_10334C.y = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].at.z;
        keys[1] = path[k].at.z;
        keys[2] = path[k + 1].at.z;
        keys[3] = path[k + 2].at.z;
        D_8010274C_10334C.z = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].rot.x;
        keys[1] = path[k].rot.x;
        keys[2] = path[k + 1].rot.x;
        keys[3] = path[k + 2].rot.x;
        D_8010E5E4_335FA4_name_4E.x = D_800FD474_FE074.x = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].rot.y;
        keys[1] = path[k].rot.y;
        keys[2] = path[k + 1].rot.y;
        keys[3] = path[k + 2].rot.y;
        D_8010E5E4_335FA4_name_4E.y = D_800FD474_FE074.y = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].rot.z;
        keys[1] = path[k].rot.z;
        keys[2] = path[k + 1].rot.z;
        keys[3] = path[k + 2].rot.z;
        D_8010E5E4_335FA4_name_4E.z = D_800FD474_FE074.z = func_8002662C_2722C(keys, times, t);
        keys[0] = path[k - 1].zoom;
        keys[1] = path[k].zoom;
        keys[2] = path[k + 1].zoom;
        keys[3] = path[k + 2].zoom;
        D_800FA610_FB210 = func_8002662C_2722C(keys, times, t);
        if (cb != (void*)-1) {
            fn((s16)total, k, l);
        }
        HuPrcVSleep();
    }
    m = seg + 1;
    D_8010E5E4_335FA4_name_4E.x = D_800FD474_FE074.x = path[m].rot.x;
    D_8010E5E4_335FA4_name_4E.y = D_800FD474_FE074.y = path[m].rot.y;
    D_8010E5E4_335FA4_name_4E.z = D_800FD474_FE074.z = path[m].rot.z;
    D_800FA610_FB210 = path[m].zoom;
    D_8010274C_10334C.x = path[m].at.x;
    D_8010274C_10334C.y = path[m].at.y;
    D_8010274C_10334C.z = path[m].at.z;
    D_800F851A_F911A = 0;
}

void func_8010C218_333BD8_name_4E(void) {
    s16 last = -1;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;
    s16* to;

    D_8010E154_335B14_name_4E = 0;
    D_8010E5F0_335FB0_name_4E = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_8010E5F0_335FB0_name_4E, 0x4800);
    espPosSet(D_8010E5F0_335FB0_name_4E, 160, 120);
    espDispOff(D_8010E5F0_335FB0_name_4E);
    D_8010DC84_335644_name_4E = 160;
    D_8010DC86_335646_name_4E = 120;
    D_8010DC88_335648_name_4E = 10;
    omAddPrcObj(func_8010C4AC_333E6C_name_4E, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_8010E154_335B14_name_4E != 0) {
            if (last != D_8010DC8A_33564A_name_4E && D_8010DC8A_33564A_name_4E != -1) {
                x0 = D_8010DC84_335644_name_4E;
                y0 = D_8010DC86_335646_name_4E;
                to = D_8010DC80_335640_name_4E[D_8010DC8A_33564A_name_4E];
                dx = to[0] - x0;
                dy = to[1] - y0;
                for (i = 1; i <= D_8010DC88_335648_name_4E; i++) {
                    s = HuMathSin(90.0f / D_8010DC88_335648_name_4E * i);
                    D_8010DC84_335644_name_4E = x0 + dx * s;
                    D_8010DC86_335646_name_4E = y0 + dy * s;
                    espPosSet(D_8010E5F0_335FB0_name_4E, D_8010DC84_335644_name_4E,
                              D_8010DC86_335646_name_4E);
                    HuPrcVSleep();
                }
                last = D_8010DC8A_33564A_name_4E;
            }
        } else {
            last = D_8010DC8A_33564A_name_4E;
        }
        espPosSet(D_8010E5F0_335FB0_name_4E, D_8010DC84_335644_name_4E, D_8010DC86_335646_name_4E);
    }
}

/* Fades the cursor sprite in or out when D_8010E154_335B14_name_4E changes. */
/* NON_MATCHING: control flow/copy (masked 8): retail tests a copy of active made in the delay slot (one more move) */
#ifdef NON_MATCHING
void func_8010C4AC_333E6C_name_4E(void) {
    s8 last;
    s32 active;
    s32 temp;
    s16 alpha;
    s16 old;
    s16 step;

    last = 0;
    active = 0;
    alpha = 0;
    step = 0;
    while (1) {
        HuPrcVSleep();
        if (last != D_8010E154_335B14_name_4E) {
            last = D_8010E154_335B14_name_4E;
            active = 1;
            if (D_8010E154_335B14_name_4E != 0) {
                step = 0x3F;
            } else {
                step = -0x3F;
            }
        }
        if ((temp = active) != 0) {
            old = alpha;
            alpha += step;
            if (alpha >= 0xFF) {
                active = 0;
                alpha = 0xFF;
            } else if (alpha <= 0) {
                active = 0;
                alpha = 0;
            }
            if (alpha != 0) {
                if (old == 0) {
                    espDispOn(D_8010E5F0_335FB0_name_4E);
                }
                func_8001A6BC_1B2BC(D_8010E5F0_335FB0_name_4E, alpha);
            } else {
                espDispOff(D_8010E5F0_335FB0_name_4E);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C4AC_333E6C_name_4E);
#endif

void func_8010C5BC_333F7C_name_4E(s16 n) {
    D_8010DC84_335644_name_4E = D_8010DC80_335640_name_4E[n][0];
    D_8010DC86_335646_name_4E = D_8010DC80_335640_name_4E[n][1];
    D_8010DC8A_33564A_name_4E = n;
}

void func_8010C5F4_333FB4_name_4E(void* arg0) {
    D_8010DC80_335640_name_4E = arg0;
}

void func_8010C600_333FC0_name_4E(s16 arg0) {
    D_8010DC88_335648_name_4E = arg0;
}

void func_8010C60C_333FCC_name_4E(s16 arg0) {
    D_8010DC8A_33564A_name_4E = arg0;
}

void func_8010C618_333FD8_name_4E(Ovl4EModelDef* defs) {
    Ovl4EModelDef* def;
    s16 i;
    s16 model;

    def = defs;
    for (i = 0; def->file != -1; def++, i++) {
        model = LoadFormFile(def->file, def->attr);
        D_8010DC92_335652_name_4E[i] = model;
        func_8010C708_3340C8_name_4E(defs, i, model);
        D_8010DCB0_335670_name_4E[i] = func_80029E14_2AA14(model);
        if (D_8010DCB0_335670_name_4E[i] != -1) {
            func_80029E80_2AA80(model, -1, def->unk0A);
        }
    }
}

void func_8010C708_3340C8_name_4E(Ovl4EModelDef* defs, s16 i, s16 model) {
    Ovl4EModelDef* def = &defs[i];

    func_80029714_2A314(model, def->pos.x * 5.0f, def->pos.y * 5.0f, def->pos.z * 5.0f);
    func_8002979C_2A39C(model, def->rot.x, def->rot.y, def->rot.z);
    func_800297E8_2A3E8(model, 1.0f, 1.0f, 1.0f);
}

void func_8010C7AC_33416C_name_4E(Ovl4EModelDef* defs, s16 tag) {
    Ovl4EModelDef* def;
    s16 i;

    for (def = defs, i = 0; def->file != -1; def++, i++) {
        if (def->unk0C == tag && !(def->attr & 4)) {
            func_800298A4_2A4A4(D_8010DC92_335652_name_4E[i], 4, 0);
        } else {
            func_800298A4_2A4A4(D_8010DC92_335652_name_4E[i], 4, 4);
        }
    }
}

void func_8010C86C_33422C_name_4E(s16 model, Vec* out, f32 mtx[4][4]) {
    f32 local[4][4];
    f32 world[4][4];
    HmfModel* m;

    m = &D_800FC834_FD434[model];
    func_800B1F50_B2B50(local, m->pos.x, m->pos.y, m->pos.z);
    func_80025884_26484(local, m->rot.x, m->rot.y, m->rot.z);
    func_80025830_26430(local, m->scale.x, m->scale.y, m->scale.z);
    func_80025BA4_267A4(mtx, local, world);
    out->x = world[0][0] + world[1][0] + world[2][0] + world[3][0];
    out->y = world[0][1] + world[1][1] + world[2][1] + world[3][1];
    out->z = world[0][2] + world[1][2] + world[2][2] + world[3][2];
}

void func_8010C96C_33432C_name_4E(s16 model, Vec2f* out, f32 mtx[4][4]) {
    Vec pos;

    func_8010C86C_33422C_name_4E(model, &pos, mtx);
    func_8010C9AC_33436C_name_4E(0, &pos, out);
}

/* Hu3DCam3DToScreen with this overlay's field of view; off-screen behind the camera. */
void func_8010C9AC_33436C_name_4E(s32 cam, Vec* in, Vec2f* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 dz;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 h;

    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    pos.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
    pos.y = -HuMathSin(rx) * D_800FA610_FB210 + D_8010274C_10334C.y;
    pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210 + D_8010274C_10334C.z;
    at = D_8010274C_10334C;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    func_800B1960_B2560(mtx, pos.x, pos.y, pos.z, at.x, at.y, at.z, up.x, up.y, up.z);
    w = in->x;
    h = in->y;
    dz = in->z;
    w -= pos.x;
    h -= pos.y;
    dz -= pos.z;
    x = w * mtx[0][0] + h * mtx[1][0] + dz * mtx[2][0];
    y = w * mtx[0][1] + h * mtx[1][1] + dz * mtx[2][1];
    z = w * mtx[0][2] + h * mtx[1][2] + dz * mtx[2][2];
    w = HuMathSin(D_8010D7B0_335170_name_4E / 2.0f) / func_800B7890_B8490(D_8010D7B0_335170_name_4E / 2.0f) * z * 1.3333334f;
    h = HuMathSin(D_8010D7B0_335170_name_4E / 2.0f) / func_800B7890_B8490(D_8010D7B0_335170_name_4E / 2.0f) * z;
    if (z < 0.0f) {
        out->unk_00 = x * (160.0f / -w) + 160.0f;
        out->unk_04 = y * (120.0f / h) + 120.0f;
    } else {
        out->unk_00 = out->unk_04 = -200.0f;
    }
}

void func_8010CCB4_334674_name_4E(s16 view, f32 depth, Vec2f* scr, Vec* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    Ovl4ECamKey* v;
    f32 rx;
    f32 ry;
    f32 zoom;
    f32 h;
    f32 w;
    f32 x;
    f32 y;
    f32 u;
    f32 v2;

    v = &D_8010E144_335B04_name_4E[view];
    rx = v->pos.x;
    ry = v->pos.y;
    zoom = v->unk18;
    pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * zoom + v->unk0C.x;
    pos.y = -HuMathSin(rx) * zoom + v->unk0C.y;
    pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * zoom + v->unk0C.z;
    at = v->unk0C;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    depth = -depth;
    func_800B1960_B2560(mtx, pos.x, pos.y, pos.z, at.x, at.y, at.z, up.x, up.y, up.z);
    h = HuMathSin(D_8010D7B0_335170_name_4E / 2.0f) / func_800B7890_B8490(D_8010D7B0_335170_name_4E / 2.0f) * depth;
    w = h * 1.3333334f;
    x = 320.0f - scr->unk_00;
    y = 240.0f - scr->unk_04;
    u = x / 320.0f;
    v2 = (240.0f - y) / 240.0f;
    x = (w + w) * u - w;
    y = (h + h) * v2 - h;
    out->x = x * mtx[0][0] + y * mtx[0][1] + depth * mtx[0][2] + pos.x;
    out->y = x * mtx[1][0] + y * mtx[1][1] + depth * mtx[1][2] + pos.y;
    out->z = x * mtx[2][0] + y * mtx[2][1] + depth * mtx[2][2] + pos.z;
}

/* Sorts the minigames into D_8010DCC0_335680_name_4E (usable) and D_8010E160_335B20_name_4E (not) by category. */
void func_8010CF6C_33492C_name_4E(void) {
    s16 i;
    s16 j;
    s32 k;

    for (i = 0; i < 8; i++) {
        D_8010E608_335FC8_name_4E[i] = D_8010E620_335FE0_name_4E[i] = D_8010DCA0_335660_name_4E[i] = 0;
    }
    D_8010DCBA_33567A_name_4E = 0;
    D_8010E5E0_335FA0_name_4E = 0;
    for (i = 0; i < 0x48; i++) {
        for (j = 0; j < 5; j++) {
            if (i == D_8010D7B8_335178_name_4E[j]) {
                break;
            }
        }
        if (j >= 5) {
            k = j = D_800CAD94[i][0];
            if (k != 7) {
                if (func_80068040_68C40(i) != 0) {
                    D_8010DCC0_335680_name_4E[k][D_8010DCA0_335660_name_4E[k]] = i + 1;
                    D_8010DCA0_335660_name_4E[k]++;
                    D_8010DCBA_33567A_name_4E++;
                } else {
                    D_8010E160_335B20_name_4E[j][D_8010E608_335FC8_name_4E[j]] = i + 1;
                    D_8010E608_335FC8_name_4E[j]++;
                    D_8010E5E0_335FA0_name_4E++;
                }
            } else {
                if (func_80067F4C_68B4C(i) != 0) {
                    D_8010DCC0_335680_name_4E[j][D_8010DCA0_335660_name_4E[j]] = i + 1;
                    D_8010DCA0_335660_name_4E[j]++;
                    D_8010DCBA_33567A_name_4E++;
                } else {
                    D_8010E160_335B20_name_4E[j][D_8010E608_335FC8_name_4E[j]] = i + 1;
                    D_8010E608_335FC8_name_4E[j]++;
                    D_8010E5E0_335FA0_name_4E++;
                }
            }
            D_8010E620_335FE0_name_4E[j]++;
        }
    }
}
