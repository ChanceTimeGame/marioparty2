#include "common.h"
#include "ovl_2B.h"

s16 func_80108620_21EA10_BombsAway(HmfData* model, const char* name) {
    HmfPart* p = model->unk64;
    s32 i;

    for (i = 0; i < model->unk10; i++, p++) {
        if (func_800B0FD0_B1BD0(p->unk12, (void*)name) == 0) {
            return i;
        }
    }
    return -1;
}

HmfMotionObj* func_801086A0_21EA90_BombsAway(HmfData* model, s16 id, s32 idx) {
    HmfMotionObj* n = &model->unk84[idx & 0x7FFF];
    HmfMotionObj* r;
    s32 i;
    s16 c;

    if (n == (HmfMotionObj*)-1) {
        return NULL;
    }
    for (i = 0; i < n->unk00; i++) {
        c = n->unk50[i];
        if (c & 0x8000) {
            if (c != -1) {
                r = func_801086A0_21EA90_BombsAway(model, id, c & 0x7FFF);
                if (r != NULL) {
                    return r;
                }
            }
        } else if (c == id) {
            return n;
        }
    }
    return NULL;
}

HmfMotionObj* func_80108794_21EB84_BombsAway(s16 model, const char* name) {
    HmfData* m = D_800FC834_FD434[model].hmf;
    s16 id = func_80108620_21EA10_BombsAway(m, name);
    HmfMotionObj* n;

    if (id < 0) {
        return NULL;
    }
    n = func_801086A0_21EA90_BombsAway(m, id, 0);
    if (n != NULL) {
        return n;
    }
    return NULL;
}

Vec* func_80108810_21EC00_BombsAway(s16 model, const char* name) {
    HmfMotionObj* n = func_80108794_21EB84_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk34;
}

Vec* func_8010883C_21EC2C_BombsAway(s16 model, const char* name) {
    HmfMotionObj* n = func_80108794_21EB84_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk40;
}

void func_80108868_21EC58_BombsAway(s16 model, s16 src, s16 motion, f32 t) {
    HmfData* m = D_800FC834_FD434[model].hmf;
    HmfVtx* save = m->unk40;

    m->unk40 = D_800FC834_FD434[src].hmf->unk40;
    func_8002A15C_2AD5C(model, motion, t);
    D_800FC834_FD434[model].hmf->unk40 = save;
}

void func_801088FC_21ECEC_BombsAway(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

void func_80108998_21ED88_BombsAway(Vec* v) {
    f32 len = v->x * v->x + v->y * v->y + v->z * v->z;

    len = sqrtf(len);
    if (len != 0.0f) {
        len = 1.0 / len;
        v->x = len * v->x;
        v->y = len * v->y;
        v->z = len * v->z;
    }
}

f32 func_80108A4C_21EE3C_BombsAway(f32 x, f32 z) {
    f32 a = func_800B75A8_B81A8(z, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}

void func_80108ACC_21EEBC_BombsAway(Vec* dir, f32* angles) {
    f32 h = sqrtf(dir->x * dir->x + dir->z * dir->z);

    *angles++ = func_80108A4C_21EE3C_BombsAway(h, -dir->y);
    *angles++ = func_80108A4C_21EE3C_BombsAway(dir->z, dir->x);
    *angles = 0.0f;
}

void func_80108B54_21EF44_BombsAway(Matrix4f m, Vec* r) {
    f32 s;
    f32 c;
    f64 d;

    r->x = func_80108A4C_21EE3C_BombsAway(m[2][2], m[1][2]);
    r->z = func_80108A4C_21EE3C_BombsAway(m[0][0], m[0][1]);
    s = -m[0][2];
    d = 1.0 - s * s;
    if (d < 0.0f) {
        d = -d;
    }
    c = sqrtf(d);
    if (r->x > 90.0 && r->x < 270.0 && r->z > 90.0 && r->z < 270.0) {
        r->x += 180.0;
        if (r->x >= 360.0) {
            r->x -= 360.0;
        }
        r->z += 180.0;
        if (r->z >= 360.0) {
            r->z -= 360.0;
        }
        c = -c;
    }
    r->y = func_80108A4C_21EE3C_BombsAway(c, s);
}

void func_80108CFC_21F0EC_BombsAway(s16 camera) {
    HuCamera* cam = &D_800C9B80_CA780[camera];

    func_800B1960_B2560(D_8010DF80_224370_BombsAway, cam->pos.x, cam->pos.y, cam->pos.z, cam->at.x, cam->at.y,
                        cam->at.z, cam->up.x, cam->up.y, cam->up.z);
    D_8010DFC0_2243B0_BombsAway = HuMathSin(cam->fov[0] * 0.5) / func_800B7890_B8490(cam->fov[0] * 0.5);
}

void func_80108DE0_21F1D0_BombsAway(Vec* pos, Vec* out) {
    f32 v[3];
    f32 d;

    func_801088FC_21ECEC_BombsAway(D_8010DF80_224370_BombsAway, pos->x, pos->y, pos->z, v);
    d = v[2] * D_8010DFC0_2243B0_BombsAway;
    if (d < 0.0f) {
        d = -d;
    }
    out->x = v[0] * 0.75 / d;
    out->y = -v[1] / d;
    out->z = 400.0 / d;
}
/* An unreferenced 0.0 after func_80108DE0_21F1D0's literals (retail's, kept for the layout). */
const f64 D_8010D768_223B58_BombsAway = 0.0;

void func_80108E98_21F288_BombsAway(s16 sound, Vec* pos) {
    Vec o;
    f32 pan;

    func_80108DE0_21F1D0_BombsAway(pos, &o);
    pan = o.x * 32.0f;
    if (pan < -32.0f) {
        pan = -32.0f;
    } else if (pan > 32.0f) {
        pan = 32.0f;
    }
    func_800798F8_7A4F8(sound, (s32)pan + 64);
}

void func_80108F40_21F330_BombsAway(void) {
    void* file;
    s16 image;

    func_8010AC60_221050_BombsAway();
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, 0.0f, 1000.0f, 5000.0f);
    Hu3DCamSetPerspective(0, 45.0f, 80.0f, 6000.0f);
    omAddObj(0x13, 0, 0, -1, func_80109118_21F508_BombsAway);
    omAddObj(0xC, 2, 0, -1, func_8010B214_221604_BombsAway);
    omSetStatBit(omAddObj(0xC, 1, 0, -1, func_8010AA9C_220E8C_BombsAway), 0xA0);
    func_8010A4BC_2208AC_BombsAway();
    func_8010BE7C_22226C_BombsAway();
    func_80109810_21FC00_BombsAway();
    func_8010A1EC_2205DC_BombsAway();
    func_801091F4_21F5E4_BombsAway();
    file = DataRead(0x3B000F);
    image = SprAnimRead(file);
    DataClose(file);
    D_8010E530_224920_BombsAway = SprCreate(1, 0);
    SprAnimSet(D_8010E530_224920_BombsAway, 0, image, 0);
    SprAttrSet(D_8010E530_224920_BombsAway, 0, 0x4000);
    SprPosSet(D_8010E530_224920_BombsAway, 0, 0xA0, 0x78);
    SprScaleSet(D_8010E530_224920_BombsAway, 0, 2.0f, 2.2f);
    SprAttrSet(D_8010E530_224920_BombsAway, 0, 0x503C);
    D_8010DFE0_2243D0_BombsAway = 1;
    D_8010E532_224922_BombsAway = 0;
}

void func_80109118_21F508_BombsAway(omObjData* obj) {
    obj->func_ptr = func_80109128_21F518_BombsAway;
}

void func_80109128_21F518_BombsAway(void) {
    func_80109908_21FCF8_BombsAway();
    func_8010A298_220688_BombsAway();
    func_8010A4CC_2208BC_BombsAway();
    func_8010BFAC_22239C_BombsAway();
    func_8010AD18_221108_BombsAway();
}

void func_80109164_21F554_BombsAway(void) {
    func_8010AC2C_22101C_BombsAway();
}

void func_80109180_21F570_BombsAway(void) {
    D_800FD474_FE074.x = -22.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = -5.0f;
    D_8010274C_10334C.y = 254.5f;
    D_8010274C_10334C.z = 1.0f;
    D_800FA610_FB210 = 1378.0f;
}

void func_801091F4_21F5E4_BombsAway(void) {
    D_800FD474_FE074.x = 3.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = -5.0f;
    D_8010274C_10334C.y = 133.2f;
    D_8010274C_10334C.z = -1000.0f;
    D_800FA610_FB210 = 1200.0f;
}

void func_80109264_21F654_BombsAway(omObjData* obj) {
    f32 t;

    switch (D_8010CFF0_2233E0_BombsAway) {
        case 0:
            D_8010DFF0_2243E0_BombsAway.unk_00.x = D_8010D010_223400_BombsAway[0].x;
            D_8010DFF0_2243E0_BombsAway.unk_0C.x = D_8010D010_223400_BombsAway[2].x;
            D_8010DFF0_2243E0_BombsAway.unk_00.y = D_8010D010_223400_BombsAway[0].y;
            D_8010DFF0_2243E0_BombsAway.unk_0C.y = D_8010D010_223400_BombsAway[2].y;
            D_8010DFF0_2243E0_BombsAway.unk_00.z = D_8010D010_223400_BombsAway[0].z;
            D_8010DFF0_2243E0_BombsAway.unk_0C.z = D_8010D010_223400_BombsAway[2].z;
            D_8010D040_223430_BombsAway = 0x93;
            D_8010CFF4_2233E4_BombsAway = 0;
            D_8010CFF0_2233E0_BombsAway++;
            break;
        case 1:
            D_8010DFF0_2243E0_BombsAway.unk_00.x -= 15.0;
            if (D_8010CFF4_2233E4_BombsAway == 25) {
                func_8010B6FC_221AEC_BombsAway(700.0f, 500.0f, 1.0f, 0);
            }
            if (D_8010CFF4_2233E4_BombsAway == 34) {
                func_8010B6FC_221AEC_BombsAway(700.0f, 500.0f, 1.0f, 0);
            }
            D_8010274C_10334C.z = D_8010DFF0_2243E0_BombsAway.unk_00.z;
            if (D_8010CFF4_2233E4_BombsAway > 30) {
                t = (f32)(D_8010CFF4_2233E4_BombsAway - 30) / 20.0;
                if (t > 1.0) {
                    t = 1.0f;
                }
                D_800FD474_FE074.y = D_800FD474_FE074.y - t * 1.1 * t;
                D_800FA610_FB210 = D_800FA610_FB210 - t * 7.000000000000001; /* retail: 7 + 1 ulp */
                D_8010D040_223430_BombsAway = (f32)(D_8010CFF4_2233E4_BombsAway - 30) / 30.0 * 5.0 + 147.0;
            }
            if (D_8010CFF4_2233E4_BombsAway < 60) {
                t = 1.0 - (f32)D_8010CFF4_2233E4_BombsAway / 60.0;
                if (t < 0.0) {
                    t = 0.0f;
                }
                D_8010274C_10334C.x = D_8010DFF0_2243E0_BombsAway.unk_00.x + t * 300.0 * t;
            } else {
                D_8010274C_10334C.x = D_8010DFF0_2243E0_BombsAway.unk_00.x;
            }
            if (D_8010CFF4_2233E4_BombsAway >= 93) {
                D_8010DFF0_2243E0_BombsAway.unk_00.x = D_8010D010_223400_BombsAway[1].x;
                D_8010DFF0_2243E0_BombsAway.unk_0C.x = D_8010D010_223400_BombsAway[3].x;
                D_8010DFF0_2243E0_BombsAway.unk_00.y = D_8010D010_223400_BombsAway[1].y;
                D_8010DFF0_2243E0_BombsAway.unk_0C.y = D_8010D010_223400_BombsAway[3].y;
                D_8010DFF0_2243E0_BombsAway.unk_00.z = D_8010D010_223400_BombsAway[1].z;
                D_8010DFF0_2243E0_BombsAway.unk_0C.z = D_8010D010_223400_BombsAway[3].z;
                func_80109180_21F570_BombsAway();
                D_800FA610_FB210 = 1000.0f;
                D_8010D040_223430_BombsAway = 0x3A;
                D_8010CFF4_2233E4_BombsAway = 0;
                D_8010CFF0_2233E0_BombsAway++;
            }
            break;
        case 2:
            if (D_8010CFF4_2233E4_BombsAway == 18) {
                func_8010A198_220588_BombsAway(D_8010CFF8_2233E8_BombsAway[0].x, D_8010CFF8_2233E8_BombsAway[0].y,
                                               D_8010CFF8_2233E8_BombsAway[0].z, 1.0f);
                if (D_8010E550_224940_BombsAway != 0) {
                    /* retail pans the first shot's sound at the second shot's place */
                    func_80108E98_21F288_BombsAway(PlaySound(0x28D), &D_8010CFF8_2233E8_BombsAway[1]);
                }
            }
            if (D_8010CFF4_2233E4_BombsAway == 27) {
                func_8010A198_220588_BombsAway(D_8010CFF8_2233E8_BombsAway[1].x, D_8010CFF8_2233E8_BombsAway[1].y,
                                               D_8010CFF8_2233E8_BombsAway[1].z, 1.0f);
                if (D_8010E550_224940_BombsAway != 0) {
                    func_80108E98_21F288_BombsAway(PlaySound(0x28D), &D_8010CFF8_2233E8_BombsAway[1]);
                }
            }
            D_8010D040_223430_BombsAway = (D_800FA610_FB210 - 1000.0) / 378.0 * 9.0 / 1.5 + 58.0;
            if (D_8010D040_223430_BombsAway > 64) {
                D_8010D040_223430_BombsAway = 64;
            }
            if (D_800FA610_FB210 < 1378.0) {
                D_800FA610_FB210 += 12.5;
            }
            if (D_8010CFF4_2233E4_BombsAway >= 30) {
                D_8010D040_223430_BombsAway = 0x40;
                D_8010CFF4_2233E4_BombsAway = 0;
                D_8010CFF0_2233E0_BombsAway++;
            }
            break;
    }
    D_8010CFF4_2233E4_BombsAway++;
    if (D_8010DFF0_2243E0_BombsAway.unk_00.x > 0.0) {
        if (D_8010DFF0_2243E0_BombsAway.unk_00.x < 250.0) {
            D_8010DFF0_2243E0_BombsAway.unk_18 += 0.05;
        }
        if (D_8010DFF0_2243E0_BombsAway.unk_18 < 0.0f) {
            D_8010DFF0_2243E0_BombsAway.unk_00.x += D_8010DFF0_2243E0_BombsAway.unk_18;
        }
    }
    SprPosSet(D_8010E530_224920_BombsAway, 0, 0xA0, D_8010D040_223430_BombsAway + 8);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_80109810_21FC00_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_80109908_21FCF8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_801099C4_21FDB4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_80109A68_21FE58_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A0D0_2204C0_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A198_220588_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A1EC_2205DC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A298_220688_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A350_220740_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A4BC_2208AC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010A4CC_2208BC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010AA9C_220E8C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010AB08_220EF8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010AC2C_22101C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010AC60_221050_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010AD18_221108_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010ADF8_2211E8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010B1AC_22159C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010B214_221604_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010B3B8_2217A8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010B6FC_221AEC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010B7BC_221BAC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010BD44_222134_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010BE7C_22226C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010BFAC_22239C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010C444_222834_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010C8A0_222C90_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_BombsAway/21EA10", func_8010CBF0_222FE0_BombsAway);
