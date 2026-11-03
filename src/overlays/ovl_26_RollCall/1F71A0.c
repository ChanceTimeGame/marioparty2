#include "ovl_26.h"

void func_80102800_1F71A0_RollCall(void) {
    func_80109660_1FE000_RollCall();
}

void func_8010281C_1F71BC_RollCall(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;

    to.x = 680.0f;
    to.y = 0.0f;
    to.z = 2380.0f;
    from.x = 31.0f;
    from.y = 0.0f;
    from.z = 165.0f;
    func_80109994_1FE334_RollCall(&from, &to, &out);
    Hu3DCamSetPerspective(0, 35.0f, 80.0f, 8000.0f);
    D_800FA610_FB210 = out.x;
    D_800FD474_FE074.x = RC_WRAPD(360.0 - out.z - 10.0);
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = from.x;
    D_8010274C_10334C.z = from.z;
    D_8010A52C_1FEECC_RollCall = D_800FD474_FE074.x;
}

void func_80102968_1F7308_RollCall(omObjData* obj) {
    SprPosSet(D_8010A5B0_1FEF50_RollCall[4].sprite, 0, 160, 120);
}

void func_80102994_1F7334_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[4];
    D_8010A540_1FEEE0_RollCall[0] = func_8001A2F8_1AEF8(0x360000);
    p->sprite = SprCreate(1, 0);
    SprAttrReset(p->sprite, 0, -1);
    SprScaleSet(p->sprite, 0, 1.0f, 1.0f);
    SprAnimSet(p->sprite, 0, D_8010A540_1FEEE0_RollCall[0], 0);
    SprBankSet(p->sprite, 0, 0);
    SprAttrSet(p->sprite, 0, 0x5000);
    SprPosSet(p->sprite, 0, 160, 120);
    func_8008225C_82E5C(p->sprite, 0, 0);
    SprPrioSet(p->sprite, 0, 0xFFF0);
    obj->func_ptr = func_80102968_1F7308_RollCall;
}

void func_80102A9C_1F743C_RollCall(void) {
    D_8010A5B0_1FEF50_RollCall[4].obj = omAddObj(10, 1, 0, -1, func_80102994_1F7334_RollCall);
}

void func_80102AD8_1F7478_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[6];
    f32 scale;

    if (D_8010A520_1FEEC0_RollCall == 1) {
        p->unk_22 += 1;
        if (p->unk_22 >= 11) {
            p->unk_22 = 10;
        }
        scale = p->unk_22 * 0.1f;
        SprScaleSet(p->alpha, 0, scale, scale);
        scale = p->unk_22 * 0.1f;
        SprScaleSet(p->alpha, 1, scale, scale);
        if (D_8010A51E_1FEEBE_RollCall < 10) {
            SprBankSet(p->alpha, 0, 10);
        } else {
            SprBankSet(p->alpha, 0, D_8010A51E_1FEEBE_RollCall / 10);
        }
        SprBankSet(p->alpha, 1, D_8010A51E_1FEEBE_RollCall % 10);
    } else {
        SprBankSet(p->alpha, 0, 10);
        SprBankSet(p->alpha, 1, 10);
    }
}

void func_80102C58_1F75F8_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[6];
    p->alpha = SprCreate(2, 5);
    p->unk_20 = func_8001A2F8_1AEF8(0x360004);
    SprPosSet(p->alpha, 0, 152, 32);
    SprAnimSet(p->alpha, 0, (s16)p->unk_20, 0);
    func_8008225C_82E5C(p->alpha, 0, 0);
    SprAttrSet(p->alpha, 0, 0x1000);
    SprAttrSet(p->alpha, 0, 0);
    SprScaleSet(p->alpha, 0, 0.1f, 0.1f);
    func_800824F4_830F4(p->alpha, 1, 0);
    SprPosSet(p->alpha, 1, 20, 0);
    SprAnimSet(p->alpha, 1, (s16)p->unk_20, 0);
    func_8008225C_82E5C(p->alpha, 1, 0);
    SprAttrSet(p->alpha, 1, 0x1000);
    SprAttrSet(p->alpha, 1, 0);
    SprScaleSet(p->alpha, 1, 0.1f, 0.1f);
    obj->func_ptr = func_80102AD8_1F7478_RollCall;
}

void func_80102DD8_1F7778_RollCall(void) {
    D_8010A5B0_1FEF50_RollCall[6].obj = omAddObj(500, 0, 0, -1, func_80102C58_1F75F8_RollCall);
}

void func_80102E14_1F77B4_RollCall(omObjData* obj) {
    if (D_8010A4C8_1FEE68_RollCall > 0) {
        D_8010A4C8_1FEE68_RollCall--;
    } else {
        D_8010A4CB_1FEE6B_RollCall = 1;
        D_8010A4C8_1FEE68_RollCall = 0;
    }
}

/* NM: register allocation (masked 0): the count and the loop index swap a2 and a3. */
// decomp-permuter
void func_80102E54_1F77F4_RollCall(omObjData *obj)
{
  u8 chars[4];
  s16 i;
  s16 n;
  RCSlot *p;
  omObjData *o;
  if (_CheckFlag(0xC) != 0)
  {
    n = 0;
    if (D_8010A4C8_1FEE68_RollCall == 60)
    {
      for (i = 0; i < 4; i++)
      {
        p = &D_8010A5B0_1FEF50_RollCall[i];
        if (p->obj != 0)
        {
          o = p->obj;
          if (p->unk_20 == 2)
          {
            gPlayers[o->work[0]].coins_mg_bonus = 10;
            chars[n] = gPlayers[o->work[0]].character;
            n++;
          }
          else
          {
            gPlayers[o->work[0]].coins_mg_bonus = 0;
          }
        }
      }

    }
  }
  else
  {
    n = 0;
    if (D_8010A4C8_1FEE68_RollCall == 90)
    {
      for (i = 0; i < 4; i++)
      {
        p = &D_8010A5B0_1FEF50_RollCall[i];
        if (p->obj != 0)
        {
          o = p->obj;
          if (p->unk_20 == 2)
          {
            gPlayers[o->work[0]].coins_mg_bonus = 10;
            chars[n] = gPlayers[o->work[0]].character;
            n++;
          }
          else
          {
            gPlayers[o->work[0]].coins_mg_bonus = 0;
          }
        }
      }

      switch (n)
      {
        case 0:
          func_800691FC_69DFC(0x13);
          PlayMusic(0x57);
          D_8010A4C8_1FEE68_RollCall = 120;
          break;

        case 1:
          func_800691FC_69DFC(6, chars[0]);
          PlayMusic(0x51);
          D_8010A4C8_1FEE68_RollCall = 120;
          break;

        case 2:
          func_800691FC_69DFC(0x11, chars[0], chars[1]);
          PlayMusic(0x52);
          D_8010A4C8_1FEE68_RollCall = 168;
          break;

        case 3:
          n = chars[1];
          func_800691FC_69DFC(0x15, chars[0], n, chars[2]);
          PlayMusic(0x52);
          D_8010A4C8_1FEE68_RollCall = 168;
          break;

        default:
          func_800691FC_69DFC(0x16, chars[0], chars[1], chars[2], chars[3]);
          PlayMusic(0x52);
          D_8010A4C8_1FEE68_RollCall = 168;
          break;

      }

    }
  }
  obj->func_ptr = func_80102E14_1F77B4_RollCall;
}

void func_80103168_1F7B08_RollCall(omObjData* obj) {
    if (D_8010A4FE_1FEE9E_RollCall == 1) {
        if (_CheckFlag(0xC) != 0) {
            D_8010A4C8_1FEE68_RollCall = 60;
        } else {
            D_8010A4C8_1FEE68_RollCall = 90;
        }
        obj->func_ptr = func_80102E54_1F77F4_RollCall;
    }
}

void func_801031C0_1F7B60_RollCall(omObjData* obj) {
    if (D_8010A4C8_1FEE68_RollCall > 0) {
        D_8010A4C8_1FEE68_RollCall--;
        if (D_8010A4C8_1FEE68_RollCall == 30) {
            D_8010A520_1FEEC0_RollCall = 1;
        }
    } else {
        D_8010A4CB_1FEE6B_RollCall = 1;
        func_8006D518_6E118();
        obj->func_ptr = func_80103168_1F7B08_RollCall;
    }
}

void func_80103238_1F7BD8_RollCall(omObjData* obj) {
    if (func_80069538_6A138() == 0) {
        D_8010A4C8_1FEE68_RollCall = 60;
        func_8006D518_6E118();
        obj->func_ptr = func_801031C0_1F7B60_RollCall;
    }
}

void func_8010327C_1F7C1C_RollCall(omObjData* obj) {
    if (D_8010A4C8_1FEE68_RollCall > 0) {
        D_8010A4C8_1FEE68_RollCall--;
        func_8006D4D0_6E0D0((D_8010A4C8_1FEE68_RollCall + 29) / 30);
    } else {
        obj->func_ptr = func_80103238_1F7BD8_RollCall;
        D_8010A4CB_1FEE6B_RollCall = 1;
        func_8006D4D0_6E0D0(0);
        if (_CheckFlag(0xC) != 0) {
            func_800691FC_69DFC(3);
        } else {
            func_800691FC_69DFC(3);
        }
    }
}

void func_8010331C_1F7CBC_RollCall(omObjData* obj) {
    func_800691FC_69DFC(10, 30, 160, 28);
    D_8010A4C8_1FEE68_RollCall = 901;
    obj->func_ptr = func_8010327C_1F7C1C_RollCall;
}

void func_80103368_1F7D08_RollCall(omObjData* obj) {
    if (func_80069538_6A138() == 0) {
        D_8010A4CB_1FEE6B_RollCall = 1;
        D_8010A4C8_1FEE68_RollCall = 0;
        PlayMusic(0x1F);
        obj->func_ptr = func_8010331C_1F7CBC_RollCall;
    }
}

void func_801033B8_1F7D58_RollCall(omObjData* obj) {
    if (D_8010A4CA_1FEE6A_RollCall == 1) {
        func_800691FC_69DFC(0);
        obj->func_ptr = func_80103368_1F7D08_RollCall;
    } else if (D_8010A4C8_1FEE68_RollCall >= 30) {
        D_8010A4CB_1FEE6B_RollCall = 1;
    } else {
        D_8010A4C8_1FEE68_RollCall++;
    }
}

/* NM: control flow: this source merges the two "stand still" arms, retail keeps both (masked ~150, a knock-on of that). */
#ifdef NON_MATCHING
void func_80103434_1F7DD4_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    Vec a;
    Vec b;
    Vec out;
    f32 x;
    f32 z;
    s16 i;
    u32 r;
    u8 t;
    omObjData* o;

    if (p->unk_22 == 0) {
        t = rand8() % 30 + 60;
        p->unk_22 = t;
        if (p->unk_24 == 1) {
            p->unk_24 = 0;
            r = rand8() & 3;
            if (r >= 2) {
                obj->work[2] = rand8() & 7;
            } else {
                t = r;
                if (t == 0) {
                    p->unk_24 = 1;
                    t = 30 - rand8() % 15;
                    p->unk_22 = t;
                }
            }
        } else {
            r = rand8() & 3;
            if (r >= 2) {
                if (!(rand8() & 1)) {
                    if (obj->work[2] == 0) {
                        obj->work[2] = 7;
                    } else {
                        obj->work[2]--;
                    }
                } else if (obj->work[2] == 7) {
                    obj->work[2] = 0;
                } else {
                    obj->work[2]++;
                }
            } else {
                t = r;
                if (t == 0) {
                    p->unk_24 = 1;
                    t = 30 - rand8() % 15;
                    p->unk_22 = t;
                }
            }
        }
    } else {
        p->unk_22 = p->unk_22 - 1;
    }
    if (p->unk_24 == 0) {
        x = HuMathSin(obj->work[2] * 45.0f) * 10.0f + obj->trans.x;
        z = func_800B7890_B8490(obj->work[2] * 45.0f) * 10.0f + obj->trans.z;
        for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
            if (obj->work[0] == i) {
                continue;
            }
            o = D_8010A5B0_1FEF50_RollCall[i].obj;
            if (o == NULL) {
                continue;
            }
            a.x = x;
            a.y = 0.0f;
            a.z = z;
            b.x = o->trans.x;
            b.y = 0.0f;
            b.z = o->trans.z;
            func_80109994_1FE334_RollCall(&a, &b, &out);
            if (out.x < 120.0f) {
                goto blocked;
            }
        }
        for (i = 40; i < 43; i++) {
            if (obj->work[0] == i) {
                continue;
            }
            o = D_8010A5B0_1FEF50_RollCall[i].obj;
            if (o == NULL) {
                continue;
            }
            a.x = x;
            a.y = 0.0f;
            a.z = z;
            b.x = o->trans.x;
            b.y = 0.0f;
            b.z = o->trans.z;
            func_80109994_1FE334_RollCall(&a, &b, &out);
            if (out.x < 180.0f) {
                goto blocked;
            }
        }
        if (z > 550.0f || z < -500.0f || x > 620.0f || x < -620.0f) {
        blocked:
            p->unk_24 = 1;
            p->unk_22 = 10;
        } else {
            obj->trans.x = x;
            obj->trans.z = z;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_RollCall/1F71A0", func_80103434_1F7DD4_RollCall);
#endif

void func_80103894_1F8234_RollCall(omObjData* obj) {
    s16 i;
    s8 t;
    RCSlot* p;

    D_8010A5B0_1FEF50_RollCall[obj->work[0]].unk_38 = 20.0f;
    t = 2;
    if (!(obj->trans.x >= 0.0f)) {
        t = 6;
    }
    obj->work[2] = t;
    if (D_8010A51E_1FEEBE_RollCall == D_8010A4D2_1FEE72_RollCall - 3) {
        func_800794A8_7A0A8(0x28);
    }
    D_8010A51E_1FEEBE_RollCall++;
    D_8010A51F_1FEEBF_RollCall = 10;
    if (D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall] == -1) {
        D_8010A4FE_1FEE9E_RollCall = 1;
        for (i = 0; i < 4; i++) {
            p = &D_8010A5B0_1FEF50_RollCall[i];
            if (p->obj != NULL && p->unk_28 == D_8010A51E_1FEEBE_RollCall) {
                D_8010A536_1FEED6_RollCall++;
            }
        }
    } else {
        PlaySound(0x27C);
    }
}

void func_801039E4_1F8384_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    u8 hit = 0;

    obj->trans.x += HuMathSin(obj->work[2] * 45.0f) * 20.0f;
    obj->trans.z += func_800B7890_B8490(obj->work[2] * 45.0f) * 20.0f;
    if (obj->trans.x > 2000.0f) {
        obj->trans.x = 2000.0f;
        hit = 1;
    } else if (obj->trans.x < -2000.0f) {
        obj->trans.x = -2000.0f;
        hit = 1;
    }
    if (!hit && p->unk_36 == 0) {
        p->unk_36 = 1;
        PlaySound(0x274);
    }
}

void func_80103B24_1F84C4_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    switch (D_8010A4CA_1FEE6A_RollCall) {
    case 0:
    case 1:
    case 2:
        func_80103434_1F7DD4_RollCall(obj);
        if (D_8010A524_1FEEC4_RollCall == 0) {
            D_8010A524_1FEEC4_RollCall = D_8010A4D2_1FEE72_RollCall * 15;
            func_80078EA8_79AA8();
        } else {
            D_8010A524_1FEEC4_RollCall--;
        }
        if (p->unk_24 == 1) {
            p->unk_20 = 0;
        }
        if (D_80109E88_1FE828_RollCall[obj->work[2]][p->unk_20 >> 1] == -1) {
            p->unk_20 = 0;
        }
        func_8003F57C_4017C(obj->work[1], D_80109E88_1FE828_RollCall[obj->work[2]][p->unk_20 >> 1]);
        break;
    case 3:
        p->unk_20 = 0;
        if (obj->work[2] != 0) {
            if (obj->work[2] >= 6) {
                obj->work[2]++;
                if (obj->work[2] >= 8) {
                    obj->work[2] = 0;
                }
            } else {
                obj->work[2]--;
            }
        }
        func_8003F57C_4017C(obj->work[1], D_80109E88_1FE828_RollCall[obj->work[2]][0]);
        break;
    case 4:
        if (D_8010A51F_1FEEBF_RollCall == 0 && obj->work[0] == D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall]) {
            func_80103894_1F8234_RollCall(obj);
        }
        if (p->unk_38 == 0.0f) {
            p->unk_20 = 0;
        } else {
            func_801039E4_1F8384_RollCall(obj);
        }
        if (D_80109E88_1FE828_RollCall[obj->work[2]][p->unk_20] == -1) {
            p->unk_20 = 0;
        }
        func_8003F57C_4017C(obj->work[1], D_80109E88_1FE828_RollCall[obj->work[2]][p->unk_20]);
        break;
    case 5:
        p->unk_20 = 0;
        break;
    }
    p->unk_20++;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z);
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
    }
}

__asm__(".section .rodata");
const char D_8010A400_1FEDA0_RollCall[24] = "kinop_dammy_tex_DEF";

void func_80103E98_1F8838_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    void* data;
    u8 r;

    obj->model[0] = LoadFormFile(0x360005, 0x16A9);
    obj->work[2] = rand8() & 7;
    if (obj->work[0] == 10) {
        data = DataRead(0x360006);
        D_8010A4D4_1FEE74_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = D_8010A4D4_1FEE74_RollCall;
        HuMemMemoryFreePerm(data);
        D_8010A524_1FEEC4_RollCall = D_8010A4D2_1FEE72_RollCall * 15;
        p->unk_20 = 0;
    } else {
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4D4_1FEE74_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
        p->unk_20 = 0;
    }
    func_8003F57C_4017C(obj->work[1], D_80109E88_1FE828_RollCall[obj->work[2]][0]);
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    obj->model[1] = func_80018A30_19630(1, 0xA9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[r] != 0) {
        r++;
        if (r >= 30) {
            r = 0;
        }
    }
    D_8010A4E0_1FEE80_RollCall[r] = 1;
    obj->trans.x = D_80109F58_1FE8F8_RollCall[r].unk_00;
    obj->trans.y = 0.0f;
    obj->trans.z = D_80109F58_1FE8F8_RollCall[r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.1f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z);
    obj->func_ptr = func_80103B24_1F84C4_RollCall;
}

void func_801041E0_1F8B80_RollCall(void) {
    RCSlot* q;
    omObjData* o;
    s16 i;

    D_8010A4D2_1FEE72_RollCall = rand8() % 9 + 18;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(400, 2, 0, -1, func_80103E98_1F8838_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_801042EC_1F8C8C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    if (D_8010A4CA_1FEE6A_RollCall >= 3) {
        p->alpha -= 25;
        if (p->alpha < 0) {
            p->alpha = 0;
        }
    }
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
}

void func_8010439C_1F8D3C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    void* data;
    u8 r;

    obj->model[0] = LoadFormFile(0x360005, 0x1689);
    if (obj->work[0] == 40) {
        data = DataRead(0x36000A);
        D_8010A4DA_1FEE7A_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CF_1FEE6F_RollCall = D_8010A4DA_1FEE7A_RollCall;
        HuMemMemoryFreePerm(data);
    } else {
        obj->work[1] = D_8010A4CF_1FEE6F_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4DA_1FEE7A_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
    }
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_8002D124_2DD24(obj->model[0]);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[r] != 0) {
        r++;
        if (r >= 30) {
            r = 0;
        }
    }
    D_8010A4E0_1FEE80_RollCall[r] = 1;
    obj->trans.x = D_80109F58_1FE8F8_RollCall[r].unk_00;
    obj->trans.y = 0.0f;
    obj->trans.z = D_80109F58_1FE8F8_RollCall[r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    p->alpha = 255;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
    obj->func_ptr = func_801042EC_1F8C8C_RollCall;
}

void func_801045E8_1F8F88_RollCall(void) {
    s16 i;
    omObjData* o;
    RCSlot* q;

    for (i = 40; i < 43; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(300, 1, 0, -1, func_8010439C_1F8D3C_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_80104698_1F9038_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    f32 x;
    f32 y;
    f32 z;
    f32 t1;
    f32 t2;

    if (p->unk_28 == 0) {
        if (p->unk_32 > 0) {
            p->unk_32--;
            if (p->unk_20 == 59) {
                p->unk_20 = 0;
            } else {
                p->unk_20++;
            }
        } else if (p->unk_32 < 0) {
            p->unk_32++;
            if (p->unk_20 == 0) {
                p->unk_20 = 59;
            } else {
                p->unk_20--;
            }
        } else {
            p->unk_28 = (u8)(rand8() % 50) + 40;
        }
    } else {
        if (!(rand8() & 1)) {
            p->unk_32 = (u8)(rand8() % 12) + 8;
        } else {
            p->unk_32 = -((u8)(rand8() % 12) + 8);
        }
        p->unk_28--;
    }
    x = obj->trans.x + HuMathSin((p->unk_20 >> 1) * 12.0f) * p->unk_40;
    z = obj->trans.z + func_800B7890_B8490((p->unk_20 >> 1) * 12.0f) * p->unk_40;
    if ((x < 600.0f) & (x > -600.0f)) {
        obj->trans.x = x;
    }
    if ((z < 600.0f) & (z > -500.0f)) {
        obj->trans.z = z;
    }
    t1 = (u8)(rand8() % 30) * 0.1f;
    t2 = (u8)(rand8() % 25) * 0.1f;
    p->unk_38 = RC_WRAP(t1 + p->unk_38);
    y = obj->trans.y + HuMathSin(p->unk_38) * t2;
    if ((y > 100.0f) & (y < 350.0f)) {
        obj->trans.y = y;
    }
    if (p->unk_22 == 0) {
        p->alpha -= 2;
        if (p->alpha < 121) {
            p->alpha = 120;
            if (p->unk_24 == 0) {
                p->unk_22 ^= 1;
                p->unk_24 = (u8)(rand8() % 45) + 15;
            } else {
                p->unk_24--;
            }
        }
    } else {
        p->alpha += 5;
        if (p->alpha >= 255) {
            p->alpha = 255;
            if (p->unk_26 == 0) {
                p->unk_22 ^= 1;
                p->unk_26 = (u8)(rand8() % 60) + 60;
            } else {
                p->unk_26--;
            }
        }
    }
    func_8003F57C_4017C(obj->work[1], D_8010A048_1FE9E8_RollCall[p->unk_20 >> 1]);
}

void func_80104BFC_1F959C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    s16 i;
    RCSlot* q;

    p->unk_2A = 2;
    p->unk_2C = 1;
    if (D_8010A51E_1FEEBE_RollCall == D_8010A4D2_1FEE72_RollCall - 3) {
        func_800794A8_7A0A8(0x28);
    }
    D_8010A51E_1FEEBE_RollCall++;
    D_8010A51F_1FEEBF_RollCall = 10;
    PlaySound(0x277);
    if (D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall] == -1) {
        D_8010A4FE_1FEE9E_RollCall = 1;
        for (i = 0; i < 4; i++) {
            q = &D_8010A5B0_1FEF50_RollCall[i];
            if (q->obj != NULL && q->unk_28 == D_8010A51E_1FEEBE_RollCall) {
                D_8010A536_1FEED6_RollCall++;
            }
        }
    } else {
        PlaySound(0x27C);
    }
}

void func_80104D34_1F96D4_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    if (p->unk_2A != 0) {
        obj->scale.x += 0.3f;
        obj->scale.y += 0.3f;
        obj->scale.z += 0.3f;
        p->unk_2A--;
        return;
    }
    if (obj->scale.x > 0.0f) {
        obj->scale.x -= 0.1f;
        obj->scale.y -= 0.1f;
        obj->scale.z -= 0.1f;
    } else if (obj->scale.x < 0.0f) {
        obj->scale.x = 0.0f;
        obj->scale.y = 0.0f;
        obj->scale.z = 0.0f;
    }
    p->alpha -= 25;
    if (p->alpha < 0) {
        p->alpha = 0;
    }
}

void func_80104E38_1F97D8_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    switch (D_8010A4CA_1FEE6A_RollCall) {
    case 0:
    case 1:
    case 2:
        func_80104698_1F9038_RollCall(obj);
        if (D_8010A526_1FEEC6_RollCall == 0) {
            D_8010A526_1FEEC6_RollCall = D_8010A4D2_1FEE72_RollCall * 30;
            func_80078EA8_79AA8();
        } else {
            D_8010A526_1FEEC6_RollCall--;
        }
        break;
    case 3:
        if (p->unk_2A == 0) {
            p->unk_20 >>= 1;
            p->unk_2A = 1;
        }
        if (p->unk_20 != 0) {
            if (p->unk_20 >= 16) {
                p->unk_20++;
                if (p->unk_20 >= 30) {
                    p->unk_20 = 0;
                }
            } else {
                p->unk_20--;
            }
        }
        func_8003F57C_4017C(obj->work[1], D_8010A048_1FE9E8_RollCall[p->unk_20]);
        if (p->alpha < 255) {
            p->alpha += 10;
            if (p->alpha >= 256) {
                p->alpha = 255;
            }
        }
        p->unk_38 = RC_WRAP(p->unk_38 + 5.0f);
        obj->trans.y += HuMathSin(p->unk_38);
        break;
    case 4:
        if (D_8010A51F_1FEEBF_RollCall == 0 && obj->work[0] == D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall]) {
            func_80104BFC_1F959C_RollCall(obj);
        }
        if (p->unk_2C == 1) {
            func_80104D34_1F96D4_RollCall(obj);
        }
        func_8003F57C_4017C(obj->work[1], D_8010A048_1FE9E8_RollCall[p->unk_20]);
        p->unk_38 = RC_WRAP(p->unk_38 + 5.0f);
        obj->trans.y += HuMathSin(p->unk_38);
        break;
    case 5:
        p->unk_20 = 0;
        p->alpha = 0;
        break;
    }
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
    }
}

void func_8010516C_1F9B0C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    void* data;
    u8 r;

    obj->model[0] = LoadFormFile(0x360007, 0x16A9);
    if (obj->work[0] == 10) {
        data = DataRead(0x360008);
        D_8010A4D4_1FEE74_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = D_8010A4D4_1FEE74_RollCall;
        HuMemMemoryFreePerm(data);
        D_8010A526_1FEEC6_RollCall = D_8010A4D2_1FEE72_RollCall * 30;
    } else {
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4D4_1FEE74_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
    }
    p->unk_20 = (u8)(rand8() % 60);
    func_8003F57C_4017C(obj->work[1], D_8010A048_1FE9E8_RollCall[p->unk_20]);
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_8002D124_2DD24(obj->model[0]);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[r] != 0) {
        r++;
        if (r >= 30) {
            r = 0;
        }
    }
    D_8010A4E0_1FEE80_RollCall[r] = 1;
    obj->trans.x = D_8010A088_1FEA28_RollCall[r].unk_00;
    p->unk_38 = (u8)(rand8() % 36) * 10;
    obj->trans.y = (u8)(rand8() % 25) * 10.0f + 150.0f;
    obj->trans.z = D_8010A088_1FEA28_RollCall[r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3f;
    p->alpha = (u8)(rand8() % 195) + 60;
    p->unk_22 = rand8() & 1;
    p->unk_24 = (u8)(rand8() % 45) + 15;
    p->unk_26 = (u8)(rand8() % 60) + 60;
    p->unk_28 = (u8)(rand8() % 15) + 45;
    p->unk_40 = (u8)(rand8() % 80) * 0.1f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
    obj->func_ptr = func_80104E38_1F97D8_RollCall;
}

void func_8010562C_1F9FCC_RollCall(void) {
    RCSlot* q;
    omObjData* o;
    s16 i;

    D_8010A4D2_1FEE72_RollCall = rand8() % 5 + 16;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(400, 1, 0, -1, func_8010516C_1F9B0C_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_80105738_1FA0D8_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.2f, 1.2f, 1.2f);
    if (D_8010A4CA_1FEE6A_RollCall >= 3) {
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        p->alpha -= 25;
        if (p->alpha < 0) {
            p->alpha = 0;
        }
    }
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
}

/* NM: register allocation (masked 6): retail has the data pointer and r in s0, obj in s1; r is a word with u8 uses. */
#ifdef NON_MATCHING
void func_8010583C_1FA1DC_RollCall(omObjData* obj) {
    void* data;
    RCSlot* p;
    s32 r;
    s16 i;

    p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    obj->model[0] = LoadFormFile(0x360005, 0x1689);
    if (obj->work[0] == 40) {
        data = DataRead(0x36000B);
        D_8010A4DA_1FEE7A_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CF_1FEE6F_RollCall = D_8010A4DA_1FEE7A_RollCall;
        HuMemMemoryFreePerm(data);
    } else if (obj->work[0] == 41) {
        data = DataRead(0x36000C);
        D_8010A4DC_1FEE7C_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4D0_1FEE70_RollCall = D_8010A4DC_1FEE7C_RollCall;
        HuMemMemoryFreePerm(data);
    } else if (obj->work[0] == 42) {
        data = DataRead(0x36000D);
        D_8010A4DE_1FEE7E_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4D1_1FEE71_RollCall = D_8010A4DE_1FEE7E_RollCall;
        HuMemMemoryFreePerm(data);
    } else {
        r = rand8() % 3;
        if ((u8)r == 0) {
            obj->work[1] = D_8010A4CF_1FEE6F_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4DA_1FEE7A_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
        } else if ((u8)r == 1) {
            obj->work[1] = D_8010A4D0_1FEE70_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4DC_1FEE7C_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
        } else {
            obj->work[1] = D_8010A4D1_1FEE71_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4DE_1FEE7E_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
        }
    }
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_8002D124_2DD24(obj->model[0]);
    obj->model[1] = func_80018A30_19630(1, 0xA9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[(u8)r] != 0) {
        r = (u8)(r + 1) < 30 ? r + 1 : 0;
    }
    D_8010A4E0_1FEE80_RollCall[(u8)r] = 1;
    obj->trans.x = D_8010A088_1FEA28_RollCall[(u8)r].unk_00;
    obj->trans.y = 0.0f;
    obj->trans.z = D_8010A088_1FEA28_RollCall[(u8)r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    D_8010A531_1FEED1_RollCall++;
    p->alpha = 255;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.2f, 1.2f, 1.2f);
    obj->func_ptr = func_80105738_1FA0D8_RollCall;
    if (D_8010A531_1FEED1_RollCall >= 5) {
        for (i = 0; i < 30; i++) {
            D_8010A4E0_1FEE80_RollCall[(u8)r] = 0; /* retail: never [i], so only this cell is freed */
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_RollCall/1F71A0", func_8010583C_1FA1DC_RollCall);
#endif

void func_80105D44_1FA6E4_RollCall(void) {
    s16 i;
    omObjData* o;
    RCSlot* q;

    for (i = 40; i < 45; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(300, 2, 0, -1, func_8010583C_1FA1DC_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_80105DF4_1FA794_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    s16 i;
    RCSlot* q;
    omObjData* o;
    f32 t;

    if (p->unk_20 == 1) {
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_80029E80_2AA80(obj->model[0], 1, 0);
        obj->rot.x = D_8010A52C_1FEECC_RollCall;
        func_8002979C_2A39C(obj->model[0], D_8010A52C_1FEECC_RollCall, obj->rot.y, obj->rot.z);
        if (p->unk_2E == 0 && func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            p->unk_2E = 1;
            for (i = 0; i < 4; i++) {
                q = &D_8010A5B0_1FEF50_RollCall[i];
                if (q->obj != NULL) {
                    o = q->obj;
                    PlaySound(0x27B);
                    if (!(gPlayers[o->work[0]].flags & 1)) {
                        if (D_8010A4CA_1FEE6A_RollCall == 2) {
                            omVibrate(o->work[0], 2, 2, 20);
                        } else {
                            omVibrate(o->work[0], 5, 0, 5);
                        }
                    }
                }
            }
        }
        t = func_801079DC_1FC37C_RollCall(obj);
        if (func_80029D0C_2A90C(obj->model[0]) <= t) {
            p->unk_20 = 0;
            p->unk_2E = 0;
        }
    } else {
        func_80029C74_2A874(obj->model[0], 0.0f);
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_80029E80_2AA80(obj->model[0], 1, 1);
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
    }
}

void func_80106078_1FAA18_RollCall(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x3B000E, 0x14B9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 4.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    obj->func_ptr = func_80105DF4_1FA794_RollCall;
}

void func_80106138_1FAAD8_RollCall(void) {
    s16 i;
    omObjData* o;
    RCSlot* q;

    for (i = 45; i < 50; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(450, 2, 0, -1, func_80106078_1FAA18_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

/* NM: control flow, as func_80103434_1F7DD4_RollCall */
#ifdef NON_MATCHING
void func_801061E8_1FAB88_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    Vec a;
    Vec b;
    Vec out;
    f32 x;
    f32 z;
    s16 i;
    u32 r;
    u8 t;
    omObjData* o;
    s32 on;

    if (p->unk_22 == 0) {
        t = rand8() % 30 + 60;
        p->unk_22 = t;
        if (p->unk_24 == 1) {
            p->unk_24 = 0;
            r = rand8() & 3;
            if (r >= 2) {
                obj->work[2] = rand8() & 7;
            } else {
                t = r;
                if (t == 0) {
                    p->unk_24 = 1;
                    t = 30 - rand8() % 15;
                    p->unk_22 = t;
                }
            }
        } else {
            r = rand8() & 3;
            if (r >= 2) {
                if (!(rand8() & 1)) {
                    if (obj->work[2] == 0) {
                        obj->work[2] = 7;
                    } else {
                        obj->work[2]--;
                    }
                } else if (obj->work[2] == 7) {
                    obj->work[2] = 0;
                } else {
                    obj->work[2]++;
                }
            } else {
                t = r;
                if (t == 0) {
                    p->unk_24 = 1;
                    t = 30 - rand8() % 15;
                    p->unk_22 = t;
                }
            }
        }
    } else {
        p->unk_22 = p->unk_22 - 1;
    }
    if (p->unk_24 == 0) {
        x = HuMathSin(obj->work[2] * 45.0f) * 8.0f + obj->trans.x;
        z = func_800B7890_B8490(obj->work[2] * 45.0f) * 8.0f + obj->trans.z;
        for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
            if (obj->work[0] == i) {
                continue;
            }
            o = D_8010A5B0_1FEF50_RollCall[i].obj;
            if (o == NULL) {
                continue;
            }
            if (p->unk_2A != 0) {
                continue;
            }
            a.x = x;
            a.y = 0.0f;
            a.z = z;
            b.x = o->trans.x;
            b.y = 0.0f;
            b.z = o->trans.z;
            func_80109994_1FE334_RollCall(&a, &b, &out);
            if (out.x < 120.0f) {
                goto blocked;
            }
        }
        for (i = 40; i < 43; i++) {
            if (obj->work[0] == i) {
                continue;
            }
            o = D_8010A5B0_1FEF50_RollCall[i].obj;
            if (o == NULL) {
                continue;
            }
            a.x = x;
            a.y = 0.0f;
            a.z = z;
            b.x = o->trans.x;
            b.y = 0.0f;
            b.z = o->trans.z;
            func_80109994_1FE334_RollCall(&a, &b, &out);
            if (out.x < 180.0f) {
                goto blocked;
            }
        }
        if (z > 550.0f || z < -500.0f || x > 620.0f || x < -620.0f) {
        blocked:
            p->unk_24 = 1;
            p->unk_22 = 10;
        } else {
            obj->trans.x = x;
            obj->trans.z = z;
        }
        return;
    }
    if (D_8010A4CA_1FEE6A_RollCall == 2 && func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        switch (D_8010A537_1FEED7_RollCall) {
        case 0:
            on = D_8010A4C8_1FEE68_RollCall >= 151 && D_8010A4C8_1FEE68_RollCall < 750;
            break;
        case 1:
            on = D_8010A4C8_1FEE68_RollCall >= 151 && D_8010A4C8_1FEE68_RollCall < 601;
            break;
        case 2:
            on = D_8010A4C8_1FEE68_RollCall >= 151 && D_8010A4C8_1FEE68_RollCall < 451;
            break;
        case 3:
            on = D_8010A4C8_1FEE68_RollCall >= 151 && D_8010A4C8_1FEE68_RollCall < 301;
            break;
        default:
            on = 0;
            break;
        }
        if (on && (u8)(rand8() % 50) == 30 && (u8)(rand8() % 30) == 25) {
            p->unk_26 = 1;
            D_8010A537_1FEED7_RollCall++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_RollCall/1F71A0", func_801061E8_1FAB88_RollCall);
#endif

void func_801067D0_1FB170_RollCall(omObjData* obj) {
    s16 i;
    RCSlot* p;

    D_8010A5B0_1FEF50_RollCall[obj->work[0]].unk_26 = 1;
    if (D_8010A51E_1FEEBE_RollCall == D_8010A4D2_1FEE72_RollCall - D_8010A522_1FEEC2_RollCall - 3) {
        func_800794A8_7A0A8(0x28);
    }
    D_8010A51E_1FEEBE_RollCall++;
    D_8010A51F_1FEEBF_RollCall = 10;
    if (D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall] == -1) {
        D_8010A4FE_1FEE9E_RollCall = 1;
        for (i = 0; i < 4; i++) {
            p = &D_8010A5B0_1FEF50_RollCall[i];
            if (p->obj != NULL && p->unk_28 == D_8010A51E_1FEEBE_RollCall) {
                D_8010A536_1FEED6_RollCall++;
            }
        }
    } else {
        PlaySound(0x27C);
    }
}

void func_80106900_1FB2A0_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    if (p->unk_28 == 0) {
        p->unk_20 = 0;
        if (obj->work[2] != 0) {
            if (obj->work[2] >= 6) {
                obj->work[2]++;
                if (obj->work[2] >= 8) {
                    obj->work[2] = 0;
                }
            } else {
                obj->work[2]--;
            }
        } else {
            p->unk_28 = 1;
        }
        return;
    }
    if (p->unk_20 >= 21 && p->unk_20 < 28) {
        obj->scale.x += 0.05f;
        obj->scale.y += 0.05f;
        obj->scale.z += 0.05f;
    } else if (p->unk_20 >= 29 && p->unk_20 < 36) {
        obj->scale.x -= 0.02f;
        obj->scale.y -= 0.02f;
        obj->scale.z -= 0.02f;
    } else if (p->unk_20 >= 37 && p->unk_20 < 44) {
        obj->scale.x += 0.05f;
        obj->scale.y += 0.05f;
        obj->scale.z += 0.05f;
    } else if (p->unk_20 >= 45 && p->unk_20 < 52) {
        obj->scale.x -= 0.02f;
        obj->scale.y -= 0.02f;
        obj->scale.z -= 0.02f;
    } else if (p->unk_20 >= 53 && p->unk_20 < 60) {
        obj->scale.x += 0.07f;
        obj->scale.y += 0.07f;
        obj->scale.z += 0.07f;
    } else {
        obj->scale.x += 0.01f;
        obj->scale.y += 0.01f;
        obj->scale.z += 0.01f;
    }
}

void func_80106ADC_1FB47C_RollCall(omObjData* obj) {
    obj->scale.x += 0.08f;
    obj->scale.y += 0.08f;
    obj->scale.z += 0.08f;
}

void func_80106B14_1FB4B4_RollCall(f32 x, f32 y, f32 z, f32 scale) {
    s16 i;
    RCSlot* p;
    omObjData* o;

    for (i = 45; i < 50; i++) {
        p = &D_8010A5B0_1FEF50_RollCall[i];
        if (p->obj != NULL && p->unk_20 == 0) {
            break;
        }
    }
    if (i < 50) {
        o = p->obj;
        o->trans.x = x;
        o->trans.y = y;
        o->trans.z = z;
        o->scale.x = o->scale.y = o->scale.z = scale;
        p->unk_20 = 1;
        if (D_8010A4CA_1FEE6A_RollCall == 2) {
            D_8010A522_1FEEC2_RollCall++;
        }
    }
}

void func_80106BD8_1FB578_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    switch (D_8010A4CA_1FEE6A_RollCall) {
    case 0:
    case 1:
    case 2:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0 && (u8)(rand8() % 60) == 33 && (u8)(rand8() % 20) == 10) {
            PlaySound(0x278);
        }
        if (D_8010A528_1FEEC8_RollCall == 0) {
            D_8010A528_1FEEC8_RollCall = D_8010A4D2_1FEE72_RollCall * 15;
            func_80078EA8_79AA8();
        } else {
            D_8010A528_1FEEC8_RollCall--;
        }
        if (p->unk_26 == 0) {
            func_801061E8_1FAB88_RollCall(obj);
            if (p->unk_24 == 1) {
                p->unk_20 = 0;
            }
            if (D_8010A178_1FEB18_RollCall[obj->work[2]][p->unk_20 >> 1] == -1) {
                p->unk_20 = 0;
            }
            func_8003F57C_4017C(obj->work[1], D_8010A178_1FEB18_RollCall[obj->work[2]][p->unk_20 >> 1]);
        } else if (p->unk_2A == 0) {
            func_80106900_1FB2A0_RollCall(obj);
            if (D_8010A248_1FEBE8_RollCall[p->unk_20] == -1) {
                p->unk_2A = 1;
                func_80106B14_1FB4B4_RollCall(obj->trans.x, obj->trans.y + 200.0f, obj->trans.z, 4.0f);
            }
            func_8003F57C_4017C(obj->work[1], D_8010A248_1FEBE8_RollCall[p->unk_20]);
        }
        break;
    case 3:
        p->unk_20 = 0;
        if (obj->work[2] != 0) {
            if (obj->work[2] >= 6) {
                obj->work[2]++;
                if (obj->work[2] >= 8) {
                    obj->work[2] = 0;
                }
            } else {
                obj->work[2]--;
            }
        }
        func_8003F57C_4017C(obj->work[1], D_8010A178_1FEB18_RollCall[obj->work[2]][0]);
        break;
    case 4:
        if (D_8010A51F_1FEEBF_RollCall == 0 && obj->work[0] == D_8010A500_1FEEA0_RollCall[D_8010A51E_1FEEBE_RollCall]) {
            func_801067D0_1FB170_RollCall(obj);
        }
        if (p->unk_26 != 0) {
            if (p->unk_2A == 0) {
                func_80106ADC_1FB47C_RollCall(obj);
                if (D_8010A2C4_1FEC64_RollCall[p->unk_20] == -1) {
                    p->unk_2A = 1;
                    func_80106B14_1FB4B4_RollCall(obj->trans.x, obj->trans.y + 150.0f, obj->trans.z, 3.0f);
                }
                func_8003F57C_4017C(obj->work[1], D_8010A2C4_1FEC64_RollCall[p->unk_20]);
            }
        } else {
            p->unk_20 = 0;
        }
        break;
    case 5:
        p->unk_20 = 0;
        break;
    }
    p->unk_20++;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    } else if (p->unk_2A == 1) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
    }
}

void func_801070B8_1FBA58_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    void* data;
    u8 r;

    obj->model[0] = LoadFormFile(0x360005, 0x16A9);
    obj->work[2] = rand8() & 7;
    if (obj->work[0] == 10) {
        data = DataRead(0x360009);
        D_8010A4D4_1FEE74_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = D_8010A4D4_1FEE74_RollCall;
        HuMemMemoryFreePerm(data);
        D_8010A528_1FEEC8_RollCall = D_8010A4D2_1FEE72_RollCall * 15;
        p->unk_20 = 0;
    } else {
        obj->work[1] = D_8010A4CC_1FEE6C_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4D4_1FEE74_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
        p->unk_20 = 0;
    }
    func_8003F57C_4017C(obj->work[1], D_8010A178_1FEB18_RollCall[obj->work[2]][0]);
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    obj->model[1] = func_80018A30_19630(1, 0xA9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[r] != 0) {
        r++;
        if (r >= 30) {
            r = 0;
        }
    }
    D_8010A4E0_1FEE80_RollCall[r] = 1;
    obj->trans.x = D_8010A2DC_1FEC7C_RollCall[r].unk_00;
    obj->trans.y = 0.0f;
    obj->trans.z = D_8010A2DC_1FEC7C_RollCall[r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z);
    obj->func_ptr = func_80106BD8_1FB578_RollCall;
}

void func_80107400_1FBDA0_RollCall(void) {
    RCSlot* q;
    omObjData* o;
    s16 i;

    D_8010A4D2_1FEE72_RollCall = (rand8() & 3) + 17;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(400, 2, 0, -1, func_801070B8_1FBA58_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_801074EC_1FBE8C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    if (D_8010A4CA_1FEE6A_RollCall >= 3) {
        p->alpha -= 25;
        if (p->alpha < 0) {
            p->alpha = 0;
        }
    }
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
}

void func_8010759C_1FBF3C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    void* data;
    u8 r;

    obj->model[0] = LoadFormFile(0x360005, 0x1689);
    if (obj->work[0] == 40) {
        data = DataRead(0x36000E);
        D_8010A4DA_1FEE7A_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, (char*)D_8010A400_1FEDA0_RollCall);
        obj->work[1] = D_8010A4CF_1FEE6F_RollCall = D_8010A4DA_1FEE7A_RollCall;
        HuMemMemoryFreePerm(data);
    } else {
        obj->work[1] = D_8010A4CF_1FEE6F_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[0]].hmf, D_8010A4DA_1FEE7A_RollCall, 0, (char*)D_8010A400_1FEDA0_RollCall);
    }
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_8002D124_2DD24(obj->model[0]);
    r = rand8() % 30;
    while (D_8010A4E0_1FEE80_RollCall[r] != 0) {
        r++;
        if (r >= 30) {
            r = 0;
        }
    }
    D_8010A4E0_1FEE80_RollCall[r] = 1;
    obj->trans.x = D_8010A2DC_1FEC7C_RollCall[r].unk_00;
    obj->trans.y = 0.0f;
    obj->trans.z = D_8010A2DC_1FEC7C_RollCall[r].unk_04;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.2f;
    p->alpha = 255;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[0], p->alpha);
    obj->func_ptr = func_801074EC_1FBE8C_RollCall;
}

void func_801077EC_1FC18C_RollCall(void) {
    s16 i;
    omObjData* o;
    RCSlot* q;

    for (i = 40; i < 43; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(300, 2, 0, -1, func_8010759C_1FBF3C_RollCall);
        omSetStatBit(o, 0xA0);
        o->work[0] = i;
        q->obj = o;
    }
}

void func_8010789C_1FC23C_RollCall(s32 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

void func_8010791C_1FC2BC_RollCall(omObjData* obj, u32 motion) {
    if (motion < 4) {
        func_80029B80_2A780(obj->model[0], obj->motion[motion]);
    }
}

void func_80107958_1FC2F8_RollCall(omObjData* obj, u16 motion, s16 arg2, s16 arg3) {
    if (motion < 4) {
        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[motion]), arg2, arg3, 1);
    }
}

f32 func_801079DC_1FC37C_RollCall(omObjData* obj) {
    u8 m = obj->model[0];
    f32 t = func_80029E3C_2AA3C(m);

    if (t == -1.0) {
        t = func_80029CE4_2A8E4(m);
    }
    return t;
}


void func_80107A3C_1FC3DC_RollCall(omObjData* obj) {
    u16 pos[4] = { 0x20, 0x30, 0x50, 0x60 };

    func_8010791C_1FC2BC_RollCall(obj, 2);
    func_80029E80_2AA80(obj->model[0], 1, 0);
    if (D_8010A536_1FEED6_RollCall >= 2) {
        func_800732D4_73ED4(D_80109E68_1FE808_RollCall[gPlayers[obj->work[0]].character] | D_80109E80_1FE820_RollCall[D_8010A4C0_1FEE60_RollCall[obj->work[0]].pose], pos[obj->work[3]]);
    } else {
        func_800732B0_73EB0(D_80109E68_1FE808_RollCall[gPlayers[obj->work[0]].character] | D_80109E80_1FE820_RollCall[D_8010A4C0_1FEE60_RollCall[obj->work[0]].pose]);
    }
}

void func_80107B94_1FC534_RollCall(omObjData* obj) {
    func_8010791C_1FC2BC_RollCall(obj, 3);
    func_80029E80_2AA80(obj->model[0], 1, 0);
}

void func_80107BD0_1FC570_RollCall(omObjData* obj) {
    func_8010791C_1FC2BC_RollCall(obj, 1);
    func_80029E80_2AA80(obj->model[0], 2, 2);
}

void func_80107C0C_1FC5AC_RollCall(omObjData* obj) {
    func_8010791C_1FC2BC_RollCall(obj, 0);
    func_80029E80_2AA80(obj->model[0], 2, 2);
}

void func_80107C48_1FC5E8_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    if (p->unk_28 == p->unk_2C) {
        if (p->unk_32 == 0) {
            p->unk_2C = rand8() % (s32)p->unk_2A + (D_8010A4D2_1FEE72_RollCall - D_8010A522_1FEEC2_RollCall - (p->unk_2A >> 1));
        } else {
            p->unk_32--;
        }
        return;
    }
    if (p->unk_2E == 0) {
        if (p->unk_28 > p->unk_2C) {
            p->unk_28--;
        } else {
            p->unk_28++;
        }
        PlaySound(0x27C);
        if (p->unk_28 == p->unk_2C) {
            p->unk_32 = (u8)(rand8() % 60) + 60;
        }
        p->unk_2E = (u8)(rand8() % 20) + 10;
    } else {
        p->unk_2E--;
    }
}

void func_80107DE4_1FC784_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    if (D_8010A4CA_1FEE6A_RollCall == 2) {
        if (ContBtnTrg[gPlayers[obj->work[0]].port] & 0x8000) {
            p->unk_28++;
            PlaySound(0x27C);
            if (p->unk_28 >= 100) {
                p->unk_28 = 99;
            }
        } else if (ContBtnTrg[gPlayers[obj->work[0]].port] & 0x4000) {
            if (p->unk_28 == 0) {
                p->unk_28 = 0;
            } else {
                p->unk_28--;
                PlaySound(0x27C);
            }
        }
    }
}

void func_80107EFC_1FC89C_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];

    switch (D_8010A4CA_1FEE6A_RollCall) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (p->unk_20 == 0) {
            if (p->unk_24 == 0) {
                func_80107958_1FC2F8_RollCall(obj, 1, 0, (u8)(rand8() % 15 + 15));
                p->unk_24 = 1;
            } else if (func_80029E3C_2AA3C(obj->model[0]) == -1.0) {
                func_80107BD0_1FC570_RollCall(obj);
                p->unk_20 = 1;
                p->unk_24 = 0;
            }
        }
        break;
    case 3:
        if (p->unk_20 == 1) {
            if (p->unk_24 == 0) {
                func_80107958_1FC2F8_RollCall(obj, 0, 0, 20);
                p->unk_24 = 1;
            } else if (func_80029E3C_2AA3C(obj->model[0]) == -1.0) {
                func_80107C0C_1FC5AC_RollCall(obj);
                p->unk_20 = 0;
                p->unk_24 = 0;
            }
        }
        if (p->unk_26 != 0) {
            p->unk_26--;
            obj->rot.y = RC_WRAP(obj->rot.y + 20.0f);
        }
        break;
    case 4:
        if (_CheckFlag(0xC) != 0) {
            if (D_8010A4FE_1FEE9E_RollCall == 1 && p->unk_22 == 0) {
                if (p->unk_28 == D_8010A51E_1FEEBE_RollCall) {
                    p->unk_20 = 2;
                } else {
                    p->unk_20 = 3;
                }
                p->unk_22 = 1;
            }
        } else if (D_8010A4FE_1FEE9E_RollCall == 1 && p->unk_22 == 0) {
            if (p->unk_28 == D_8010A51E_1FEEBE_RollCall) {
                func_80107A3C_1FC3DC_RollCall(obj);
                p->unk_20 = 2;
            } else {
                func_80107B94_1FC534_RollCall(obj);
                p->unk_20 = 3;
            }
            p->unk_22 = 1;
        }
        break;
    case 5:
        break;
    }
}

/* NM: register allocation (masked 0): the count load goes to a1, retail a0. */
// decomp-permuter
void func_801081B8_1FCB58_RollCall(omObjData *obj)
{
  omObjData *new_var;
  short new_var2;
  RCSlot *p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
  switch (D_8010A4CA_1FEE6A_RollCall)
  {
    case 2:
      if (gPlayers[obj->work[0]].flags & 1)
    {
      func_80107C48_1FC5E8_RollCall(obj);
    }
    else
    {
      func_80107DE4_1FC784_RollCall(obj);
    }
      break;

    case 4:
      if ((_CheckFlag(0xC) == 0) && (D_8010A4FE_1FEE9E_RollCall == 1))
    {
      p->alpha -= 12;
      if (p->alpha < 0)
      {
        p->alpha = 0;
      }
    }
      break;

  }

  func_80107EFC_1FC89C_RollCall(obj);
  func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
  func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
  func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
  func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
  func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
  new_var = obj;
  func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
  func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
  func_8002D0A0_2DCA0(obj->model[2], p->alpha);
  func_80029714_2A314(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
  func_800297E8_2A3E8(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
  func_8002D0A0_2DCA0(obj->model[4], p->alpha);
  func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
  func_800297E8_2A3E8(obj->model[3], 1.0f, 1.0f, 1.0f);
  func_800297E8_2A3E8(obj->model[3], obj->scale.x, obj->scale.y, obj->scale.z);
  func_8002D0A0_2DCA0(new_var->model[3], p->alpha);
  if (p->unk_28 < 10)
  {
    func_8003F57C_4017C(new_var2 = obj->work[1], 10);
  }
  else
  {
    func_8003F57C_4017C(obj->work[1], (u8) (p->unk_28 / 10));
  }
  new_var2 = p->unk_28 % 10;
  func_8003F57C_4017C(obj->work[2], (u8) new_var2);
}

__asm__(".section .rodata");
const char D_8010A480_1FEE20_RollCall[] = "0_DEF";

__asm__(".section .rodata");
const char D_8010A488_1FEE28_RollCall[] = "1_DEF";

void func_80108478_1FCE18_RollCall(omObjData* obj) {
    RCSlot* p = &D_8010A5B0_1FEF50_RollCall[obj->work[0]];
    u16 ch = gPlayers[obj->work[0]].character;
    s32 base = D_800CD438_CE038[ch].unk_04;
    void* data;
    s8 r;

    obj->model[0] = LoadFormFile(base | D_800CD438_CE038[ch].unk_08, 0x2B9);
    func_80018CCC_198CC(obj, 0, base | D_80109DC0_1FE760_RollCall[ch][0]);
    func_80018CCC_198CC(obj, 1, base | D_80109DC0_1FE760_RollCall[ch][1]);
    if (!(rand8() & 1)) {
        func_80018CCC_198CC(obj, 2, base | D_80109DC0_1FE760_RollCall[ch][2]);
        D_8010A4C0_1FEE60_RollCall[obj->work[0]].pose = 0;
    } else {
        func_80018CCC_198CC(obj, 2, base | D_80109DC0_1FE760_RollCall[ch][3]);
        D_8010A4C0_1FEE60_RollCall[obj->work[0]].pose = 1;
    }
    func_80018CCC_198CC(obj, 3, base | D_80109DC0_1FE760_RollCall[ch][4]);
    obj->model[1] = func_80018A30_19630(1, 0xA9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    obj->model[2] = LoadFormFile(0x360002, 0x1689);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    func_8002D124_2DD24(obj->model[2]);
    obj->model[3] = LoadFormFile(0x360001, 0x1689);
    func_80029E80_2AA80(obj->model[3], 2, 2);
    obj->model[4] = LoadFormFile(0x360003, 0x1689);
    func_80029E80_2AA80(obj->model[4], 2, 2);
    func_8002D124_2DD24(obj->model[4]);
    if (obj->work[0] == 0) {
        data = DataRead(0x360004);
        D_8010A4D6_1FEE76_RollCall = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[3]].hmf, data, 0, (char*)D_8010A480_1FEE20_RollCall);
        obj->work[1] = D_8010A4CD_1FEE6D_RollCall = D_8010A4D6_1FEE76_RollCall;
        obj->work[2] = D_8010A4CD_1FEE6D_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[3]].hmf, D_8010A4D6_1FEE76_RollCall, 0, (char*)D_8010A488_1FEE28_RollCall);
        HuMemMemoryFreePerm(data);
    } else {
        obj->work[1] = D_8010A4CD_1FEE6D_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[3]].hmf, D_8010A4D6_1FEE76_RollCall, 0, (char*)D_8010A480_1FEE20_RollCall);
        obj->work[2] = D_8010A4CD_1FEE6D_RollCall = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[3]].hmf, D_8010A4D6_1FEE76_RollCall, 0, (char*)D_8010A488_1FEE28_RollCall);
    }
    func_8003F57C_4017C(obj->work[1], 10);
    func_8003F57C_4017C(obj->work[2], 0);
    func_8003E4F4_3F0F4(obj->work[1], 1, 1);
    func_8003E4F4_3F0F4(obj->work[2], 1, 1);
    func_8002D124_2DD24(obj->model[3]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    do {
        r = rand8() & 3;
    } while (D_8010A532_1FEED2_RollCall[(u8)r] != 0);
    obj->work[3] = r;
    D_8010A532_1FEED2_RollCall[(u8)r] = 1;
    obj->trans.x = D_80109E38_1FE7D8_RollCall[(u8)r].x;
    obj->trans.y = D_80109E38_1FE7D8_RollCall[(u8)r].y;
    obj->trans.z = D_80109E38_1FE7D8_RollCall[(u8)r].z;
    obj->rot.y = 180.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3f;
    func_80107C0C_1FC5AC_RollCall(obj);
    p->unk_20 = 0;
    p->alpha = 255;
    p->unk_26 = 9;
    p->unk_28 = 0;
    if (gPlayers[obj->work[0]].flags & 1) {
        switch (gPlayers[obj->work[0]].cpu_difficulty) {
        case 0:
            p->unk_2A = (u8)(rand8() % 6) + 6;
            break;
        case 1:
            p->unk_2A = (rand8() & 3) + 4;
            break;
        case 2:
            p->unk_2A = (u8)(rand8() % 3) + 3;
            break;
        default:
            p->unk_2A = (rand8() & 1) + 2;
            break;
        }
    }
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[2], p->alpha);
    func_80029714_2A314(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[4], p->alpha);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[3], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D0A0_2DCA0(obj->model[3], p->alpha);
    func_8010789C_1FC23C_RollCall(obj->work[0]);
    obj->func_ptr = func_801081B8_1FCB58_RollCall;
}

void func_80108C04_1FD5A4_RollCall(void) {
    s16 i;
    RCSlot* q;
    omObjData* o;
    u8 w;

    for (i = 0; i < 4; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = omAddObj(200, 5, 4, -1, func_80108478_1FCE18_RollCall);
        switch (i) {
        case 0:
            w = 0;
            break;
        case 1:
            w = 1;
            break;
        case 2:
            w = 2;
            break;
        case 3:
            w = 3;
            break;
        default:
            w = 0;
            break;
        }
        o->work[0] = w;
        q->obj = o;
        D_800FC87A_FD47A++;
    }
}

void func_80108D10_1FD6B0_RollCall(void) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80108D34_1FD6D4_RollCall(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_80108D10_1FD6B0_RollCall;
    }
}

void func_80108D6C_1FD70C_RollCall(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80108D34_1FD6D4_RollCall;
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
    }
}

void func_80108DC4_1FD764_RollCall(void) {
    D_8010A4CA_1FEE6A_RollCall += D_8010A4CB_1FEE6B_RollCall;
    D_8010A4CB_1FEE6B_RollCall = 0;
}

void func_80108DEC_1FD78C_RollCall(void) {
    RCSlot* q;
    omObjData* o;
    f32 d;
    f32 x;
    s16 n;
    s16 i;
    s16 j;
    s16 k;

    n = 0;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        q = &D_8010A5B0_1FEF50_RollCall[i];
        o = q->obj;
        d = func_800B1830_B2430(o->trans.x * o->trans.x);
        for (j = 0; j < D_8010A4D2_1FEE72_RollCall; j++) {
            if (D_8010A500_1FEEA0_RollCall[j] == -1) {
                D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                n++;
                break;
            }
            q = &D_8010A5B0_1FEF50_RollCall[D_8010A500_1FEEA0_RollCall[j]];
            x = q->obj->trans.x;
            if (func_800B1830_B2430(x * x) < d) {
                for (k = n; j < k; k--) {
                    D_8010A500_1FEEA0_RollCall[k] = D_8010A500_1FEEA0_RollCall[k - 1];
                }
                D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                n++;
                break;
            }
        }
    }
    D_8010A4FF_1FEE9F_RollCall = 1;
}

void func_80108FEC_1FD98C_RollCall(void) {
    RCSlot* p;
    RCSlot* q;
    omObjData* o;
    s16 n;
    s16 i;
    s16 j;
    s16 k;

    n = 0;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        p = &D_8010A5B0_1FEF50_RollCall[i];
        o = p->obj;
        for (j = 0; j < D_8010A4D2_1FEE72_RollCall; j++) {
            if (p->unk_26 == 0) {
                if (D_8010A500_1FEEA0_RollCall[j] == -1) {
                    D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                    n++;
                    break;
                }
                q = &D_8010A5B0_1FEF50_RollCall[D_8010A500_1FEEA0_RollCall[j]];
                if (o->trans.z < q->obj->trans.z) {
                    for (k = n; j < k; k--) {
                        D_8010A500_1FEEA0_RollCall[k] = D_8010A500_1FEEA0_RollCall[k - 1];
                    }
                    D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                    n++;
                    break;
                }
            }
        }
    }
    D_8010A4FF_1FEE9F_RollCall = 1;
}

void func_80109198_1FDB38_RollCall(void) {
    RCSlot* p;
    RCSlot* q;
    omObjData* o;
    s16 n;
    s16 i;
    s16 j;
    s16 k;

    n = 0;
    for (i = 10; i < D_8010A4D2_1FEE72_RollCall + 10; i++) {
        p = &D_8010A5B0_1FEF50_RollCall[i];
        o = p->obj;
        for (j = 0; j < D_8010A4D2_1FEE72_RollCall; j++) {
            if (D_8010A500_1FEEA0_RollCall[j] == -1) {
                D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                n++;
                break;
            }
            q = &D_8010A5B0_1FEF50_RollCall[D_8010A500_1FEEA0_RollCall[j]];
            if (o->trans.z > q->obj->trans.z) {
                for (k = n; j < k; k--) {
                    D_8010A500_1FEEA0_RollCall[k] = D_8010A500_1FEEA0_RollCall[k - 1];
                }
                D_8010A500_1FEEA0_RollCall[j] = o->work[0];
                n++;
                break;
            }
        }
    }
    D_8010A4FF_1FEE9F_RollCall = 1;
}

void func_80109338_1FDCD8_RollCall(omObjData* obj) {
    if (D_8010A3CC_1FED6C_RollCall == 0) {
        PlaySound(0x4A1);
        D_8010A3CC_1FED6C_RollCall = 1;
    }
    func_80108DC4_1FD764_RollCall();
    switch (D_8010A4CA_1FEE6A_RollCall) {
    case 3:
        if (D_8010A4FF_1FEE9F_RollCall == 0) {
            switch (D_8010A521_1FEEC1_RollCall) {
            case 0:
                func_80108DEC_1FD78C_RollCall();
                break;
            case 1:
                func_80109198_1FDB38_RollCall();
                break;
            default:
                func_80108FEC_1FD98C_RollCall();
                break;
            }
        }
        break;
    case 4:
        if (D_8010A51F_1FEEBF_RollCall != 0) {
            D_8010A51F_1FEEBF_RollCall--;
        }
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80108D34_1FD6D4_RollCall;
        break;
    }
}

void func_8010945C_1FDDFC_RollCall(void) {
    s16 i;

    D_8010A4CB_1FEE6B_RollCall = 0;
    D_8010A4CA_1FEE6A_RollCall = 0;
    D_8010A4FE_1FEE9E_RollCall = 0;
    D_8010A4FF_1FEE9F_RollCall = 0;
    D_8010A51E_1FEEBE_RollCall = 0;
    D_8010A51F_1FEEBF_RollCall = 0;
    D_8010A520_1FEEC0_RollCall = 0;
    D_8010A522_1FEEC2_RollCall = 0;
    D_8010A530_1FEED0_RollCall = 30;
    D_8010A531_1FEED1_RollCall = 0;
    D_8010A536_1FEED6_RollCall = 0;
    for (i = 0; i < 30; i++) {
        D_8010A4E0_1FEE80_RollCall[i] = 0;
        D_8010A500_1FEEA0_RollCall[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        D_8010A532_1FEED2_RollCall[i] = 0;
    }
}

void func_80109538_1FDED8_RollCall(omObjData* obj) {
    func_80109D10_1FE6B0_RollCall();
    func_80109D94_1FE734_RollCall();
    func_8010945C_1FDDFC_RollCall();
    func_80102A9C_1F743C_RollCall();
    func_80108C04_1FD5A4_RollCall();
    func_80102DD8_1F7778_RollCall();
    switch (D_800FA656) {
    case 0:
        func_801045E8_1F8F88_RollCall();
        func_801041E0_1F8B80_RollCall();
        D_8010A521_1FEEC1_RollCall = 0;
        break;
    case 1:
        func_80105D44_1FA6E4_RollCall();
        func_8010562C_1F9FCC_RollCall();
        D_8010A521_1FEEC1_RollCall = 1;
        break;
    default:
        func_801077EC_1FC18C_RollCall();
        func_80107400_1FBDA0_RollCall();
        func_80106138_1FAAD8_RollCall();
        D_8010A521_1FEEC1_RollCall = 2;
        break;
    }
    InitFadeIn(0, 16);
    obj->func_ptr = func_80109338_1FDCD8_RollCall;
    omAddObj(50, 0, 0, -1, func_8010281C_1F71BC_RollCall);
    D_8010A4CA_1FEE6A_RollCall = 0;
    omAddObj(100, 0, 0, -1, func_801033B8_1F7D58_RollCall);
}

__asm__(".section .rodata");
const char D_8010A490_1FEE30_RollCall[] = "\202`\202a\202b";

void func_80109660_1FE000_RollCall(void) {
    s32 c;
    u8 cam;

    func_8002D4D0_2E0D0(0x32);
    func_80020D20_21920(0x134);
    omInitObjMan(0x50, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    c = func_80018E78_19A78();
    cam = c;
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(c, 35.0f, 80.0f, 8000.0f);
    func_80026D28_27928(1);
    func_80026E00_27A00(0, -20.0f, 40.0f, 100.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, -20.0f, 40.0f, 100.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_80109538_1FDED8_RollCall);
    omAddObj(2000, 0, 0, -1, func_80108D6C_1FD70C_RollCall);
    func_8007273C_7333C((u8*)D_8010A490_1FEE30_RollCall, 0);
    func_8007273C_7333C((u8*)D_8010A490_1FEE30_RollCall, 1);
}

f32 func_80109844_1FE1E4_RollCall(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

/* NM: schedule: the 180.0f load sits after the compare in retail (twin of ovl_09). */
#ifdef NON_MATCHING
void func_80109994_1FE334_RollCall(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_80109844_1FE1E4_RollCall(delta.x / delta.z) * 57.29577951308232;
        } else if (delta.z == 0.0f) {
            if (delta.x >= 0.0f) {
                yaw = 90.0f;
            } else {
                yaw = 270.0f;
            }
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_80109844_1FE1E4_RollCall(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_RollCall/1F71A0", func_80109994_1FE334_RollCall);
#endif

void func_80109D10_1FE6B0_RollCall(void) {
    RCSlot* p = D_8010A5B0_1FEF50_RollCall;
    u32 i;

    for (i = 0; i < 100; i++, p++) {
        p->obj = NULL;
        p->sprite = 0;
        p->unk_08 = 0;
        p->unk_0C = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1C = 0;
        p->unk_20 = 0;
        p->unk_22 = 0;
        p->unk_24 = 0;
        p->unk_26 = 0;
        p->unk_28 = 0;
        p->unk_2A = 0;
        p->unk_2C = 0;
        p->unk_2E = 0;
        p->alpha = 0;
        p->unk_32 = 0;
        p->unk_34 = 0;
        p->unk_36 = 0;
        p->unk_38 = 0.0f;
        p->unk_3C = 0.0f;
        p->unk_40 = 0.0f;
        p->unk_44 = 0.0f;
    }
}

void func_80109D94_1FE734_RollCall(void) {
    s16* p = D_8010A540_1FEEE0_RollCall;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}

/* .data (0x1FE760-0x1FED70, 80109DC0-8010A3D0) */
s32 D_80109DC0_1FE760_RollCall[6][5] = {
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
    { 0, 0xA2, 0x4E, 0x4F, 0x55 },
};
Vec D_80109E38_1FE7D8_RollCall[4] = {
    { -400.0f, 0.0f, 1030.0f },
    { -125.0f, 0.0f, 1030.0f },
    { 125.0f, 0.0f, 1030.0f },
    { 400.0f, 0.0f, 1030.0f },
};
s32 D_80109E68_1FE808_RollCall[6] = { 0x20000, 0x30000, 0x70000, 0x40000, 0x50000, 0x60000 };
u16 D_80109E80_1FE820_RollCall[4] = { 0x4E, 0x4F, 0x55, 0x56 };
s16 D_80109E88_1FE828_RollCall[8][13] = {
    { 0x03, 0x02, 0x01, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x05, 0x04, -1 },
    { 0x0A, 0x09, 0x08, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, -1 },
    { 0x11, 0x10, 0x0F, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x13, 0x12, -1 },
    { 0x18, 0x17, 0x16, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1A, 0x19, -1 },
    { 0x1F, 0x1E, 0x1D, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x21, 0x20, -1 },
    { 0x26, 0x25, 0x24, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x28, 0x27, -1 },
    { 0x2D, 0x2C, 0x2B, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x2F, 0x2E, -1 },
    { 0x34, 0x33, 0x32, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x36, 0x35, -1 },
};
Vec2f D_80109F58_1FE8F8_RollCall[30] = {
    { -500.0f, 400.0f },
    { -300.0f, 400.0f },
    { -100.0f, 400.0f },
    { 100.0f, 400.0f },
    { 300.0f, 400.0f },
    { 500.0f, 400.0f },
    { -500.0f, 200.0f },
    { -300.0f, 200.0f },
    { -100.0f, 200.0f },
    { 100.0f, 200.0f },
    { 300.0f, 200.0f },
    { 500.0f, 200.0f },
    { -500.0f, 0.0f },
    { -300.0f, 0.0f },
    { -100.0f, 0.0f },
    { 100.0f, 0.0f },
    { 300.0f, 0.0f },
    { 500.0f, 0.0f },
    { -500.0f, -200.0f },
    { -300.0f, -200.0f },
    { -100.0f, -200.0f },
    { 100.0f, -200.0f },
    { 300.0f, -200.0f },
    { 500.0f, -200.0f },
    { -500.0f, -400.0f },
    { -300.0f, -400.0f },
    { -100.0f, -400.0f },
    { 100.0f, -400.0f },
    { 300.0f, -400.0f },
    { 500.0f, -400.0f },
};
s16 D_8010A048_1FE9E8_RollCall[32] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, -1, 0x00,
};
Vec2f D_8010A088_1FEA28_RollCall[30] = {
    { -500.0f, 400.0f },
    { -300.0f, 400.0f },
    { -100.0f, 400.0f },
    { 100.0f, 400.0f },
    { 300.0f, 400.0f },
    { 500.0f, 400.0f },
    { -500.0f, 200.0f },
    { -300.0f, 200.0f },
    { -100.0f, 200.0f },
    { 100.0f, 200.0f },
    { 300.0f, 200.0f },
    { 500.0f, 200.0f },
    { -500.0f, 0.0f },
    { -300.0f, 0.0f },
    { -100.0f, 0.0f },
    { 100.0f, 0.0f },
    { 300.0f, 0.0f },
    { 500.0f, 0.0f },
    { -500.0f, -200.0f },
    { -300.0f, -200.0f },
    { -100.0f, -200.0f },
    { 100.0f, -200.0f },
    { 300.0f, -200.0f },
    { 500.0f, -200.0f },
    { -500.0f, -400.0f },
    { -300.0f, -400.0f },
    { -100.0f, -400.0f },
    { 100.0f, -400.0f },
    { 300.0f, -400.0f },
    { 500.0f, -400.0f },
};
s16 D_8010A178_1FEB18_RollCall[8][13] = {
    { 0x03, 0x02, 0x01, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x05, 0x04, -1 },
    { 0x0A, 0x09, 0x08, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, -1 },
    { 0x11, 0x10, 0x0F, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x13, 0x12, -1 },
    { 0x18, 0x17, 0x16, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1A, 0x19, -1 },
    { 0x1F, 0x1E, 0x1D, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x21, 0x20, -1 },
    { 0x26, 0x25, 0x24, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x28, 0x27, -1 },
    { 0x2D, 0x2C, 0x2B, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x2F, 0x2E, -1 },
    { 0x34, 0x33, 0x32, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x36, 0x35, -1 },
};
s16 D_8010A248_1FEBE8_RollCall[62] = {
    0x38, 0x38, 0x39, 0x39, 0x38, 0x38, 0x39, 0x39,
    0x38, 0x38, 0x39, 0x39, 0x3A, 0x3A, 0x3B, 0x3B,
    0x3A, 0x3A, 0x3B, 0x3B, 0x3A, 0x3A, 0x3B, 0x3B,
    0x3C, 0x3C, 0x3D, 0x3D, 0x3C, 0x3C, 0x3D, 0x3D,
    0x3C, 0x3C, 0x3D, 0x3D, 0x3E, 0x3E, 0x3F, 0x3F,
    0x3E, 0x3E, 0x3F, 0x3F, 0x3E, 0x3E, 0x3F, 0x3F,
    0x3E, 0x3E, 0x3F, 0x3F, 0x3E, 0x3E, 0x3F, 0x3F,
    0x3E, 0x3E, 0x3F, 0x3F, -1, 0x00,
};
s16 D_8010A2C4_1FEC64_RollCall[12] = {
    0x38, 0x38, 0x3B, 0x3B, 0x3C, 0x3C,
    0x3F, 0x3F, 0x3E, 0x3E, -1, 0x00,
};
Vec2f D_8010A2DC_1FEC7C_RollCall[30] = {
    { -500.0f, 400.0f },
    { -300.0f, 400.0f },
    { -100.0f, 400.0f },
    { 100.0f, 400.0f },
    { 300.0f, 400.0f },
    { 500.0f, 400.0f },
    { -500.0f, 200.0f },
    { -300.0f, 200.0f },
    { -100.0f, 200.0f },
    { 100.0f, 200.0f },
    { 300.0f, 200.0f },
    { 500.0f, 200.0f },
    { -500.0f, 0.0f },
    { -300.0f, 0.0f },
    { -100.0f, 0.0f },
    { 100.0f, 0.0f },
    { 300.0f, 0.0f },
    { 500.0f, 0.0f },
    { -500.0f, -200.0f },
    { -300.0f, -200.0f },
    { -100.0f, -200.0f },
    { 100.0f, -200.0f },
    { 300.0f, -200.0f },
    { 500.0f, -200.0f },
    { -500.0f, -400.0f },
    { -300.0f, -400.0f },
    { -100.0f, -400.0f },
    { 100.0f, -400.0f },
    { 300.0f, -400.0f },
    { 500.0f, -400.0f },
};
u8 D_8010A3CC_1FED6C_RollCall = 0;
