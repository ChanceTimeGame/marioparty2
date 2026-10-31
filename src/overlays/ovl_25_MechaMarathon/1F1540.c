#include "ovl_25.h"

extern const char D_801082E8_1F7028_MechaMarathon[];
extern const char D_801082F4_1F7034_MechaMarathon[];
extern const char D_80108300_1F7040_MechaMarathon[];
extern const char D_8010830C_1F704C_MechaMarathon[];
extern const char D_80108318_1F7058_MechaMarathon[];
extern const char D_80108324_1F7064_MechaMarathon[];
extern const char D_80108354_1F7094_MechaMarathon[];
extern const char D_8010836C_1F70AC_MechaMarathon[];
extern const char D_80108384_1F70C4_MechaMarathon[];

/* .data (0x1F6D50-0x1F6F70, 80108010-80108230) */
s16 D_80108010_1F6D50_MechaMarathon[6] = { 0x00, 0x0C, 0x1C, 0x28, 0x14, 0x3E };
s16 D_8010801C_1F6D5C_MechaMarathon[10] = { 0x00, 0x10, 0x2C, 0x3C, 0x20, 0x4C, 0x58, 0x64, 0x70, 0x7C };
s16 D_80108030_1F6D70_MechaMarathon[6] = { 2, 0, 0, 0, 0xC, 0xD };
s32 D_8010803C_1F6D7C_MechaMarathon[6] = { 0x20000, 0x30000, 0x70000, 0x40000, 0x50000, 0x60000 };
u16 D_80108054_1F6D94_MechaMarathon[4] = { 0x4E, 0x4F, 0x55, 0x56 };
s32 D_8010805C_1F6D9C_MechaMarathon = 1;
u8 D_80108060_1F6DA0_MechaMarathon = 2;
s32 D_80108064_1F6DA4_MechaMarathon = 0;
s32 D_80108068_1F6DA8_MechaMarathon[6][8] = {
    { 0, 0x22, 2, 0xF, 0x4E, 0x4F, 0x56, 1 },
    { 0, 0x23, 2, 0xF, 0x4E, 0x4F, 0x56, 1 },
    { 0, 0x24, 2, 0xF, 0x4E, 0x4F, 0x55, 1 },
    { 0, 0x25, 2, 0xF, 0x4E, 0x4F, 0x55, 1 },
    { 0, 0x26, 2, 0xF, 0x4E, 0x4F, 0x56, 1 },
    { 0, 0x27, 2, 0xF, 0x4E, 0x4F, 0x56, 1 },
};
Vec D_80108128_1F6E68_MechaMarathon[4] = {
    { 90.0f, 10.0f, 277.5f },
    { 90.0f, 10.0f, 107.5f },
    { 90.0f, 10.0f, -62.5f },
    { 90.0f, 10.0f, -232.5f },
};
f32 D_80108158_1F6E98_MechaMarathon[11] = { 1.0f, 1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 2.0f };
u16 D_80108184_1F6EC4_MechaMarathon[4] = { 0x3C, 0x5A, 0x64, 0x64 };
s16 D_8010818C_1F6ECC_MechaMarathon = 0;
s16 D_8010818E_1F6ECE_MechaMarathon = 0; /* pad */
s16 D_80108190_1F6ED0_MechaMarathon[6] = { 2, 3, 7, 4, 5, 6 };
u16 D_8010819C_1F6EDC_MechaMarathon[2] = { 0xDF, 0xE0 };
const char* D_801081A0_1F6EE0_MechaMarathon[6] = {
    D_80108324_1F7064_MechaMarathon, D_80108318_1F7058_MechaMarathon, D_8010830C_1F704C_MechaMarathon,
    D_80108300_1F7040_MechaMarathon, D_801082F4_1F7034_MechaMarathon, D_801082E8_1F7028_MechaMarathon,
};
s16 D_801081B8_1F6EF8_MechaMarathon = 0;
s16 D_801081BA_1F6EFA_MechaMarathon = 0; /* pad */
s32 D_801081BC_1F6EFC_MechaMarathon[4] = { 0xC, 0xD, 0xE, 0xF };
s32 D_801081CC_1F6F0C_MechaMarathon[18] = { 0x16, 0x1C, 0x10, 0x17, 0x1D, 0x11, 0x18, 0x1E, 0x12,
                                            0x19, 0x1F, 0x13, 0x1A, 0x20, 0x14, 0x1B, 0x21, 0x15 };
const char* D_80108214_1F6F54_MechaMarathon[3] = {
    D_80108384_1F70C4_MechaMarathon, D_8010836C_1F70AC_MechaMarathon, D_80108354_1F7094_MechaMarathon,
};
s16 D_80108220_1F6F60_MechaMarathon = 0;
u16 D_80108222_1F6F62_MechaMarathon = 0;
s16 D_80108224_1F6F64_MechaMarathon = 0;
s16 D_80108226_1F6F66_MechaMarathon = 0;
s16 D_80108228_1F6F68_MechaMarathon = 0xF;
s16 D_8010822A_1F6F6A_MechaMarathon = 0; /* pad */
s16 D_8010822C_1F6F6C_MechaMarathon = 0; /* pad */
s16 D_8010822E_1F6F6E_MechaMarathon = 0; /* pad */

void func_80102800_1F1540_MechaMarathon(void) {
    func_80107D0C_1F6A4C_MechaMarathon();
}

/* Picks a random index below n whose bit in *used is clear, sets the bit and returns it. */
u8 func_8010281C_1F155C_MechaMarathon(u8 n, u64* used) {
    u64 m;
    u8 k;
    u8 i;

    m = *used;
    i = n;
    while (m != 0) {
        if (m & 1) {
            i--;
        }
        m >>= 1;
    }
    k = rand8() % i;
    m = *used;
    for (i = 0; i < n; i++) {
        if (m & 1) {
        } else if (k-- == 0) {
            break;
        }
        m >>= 1;
    }
    i = (i < n) ? i : 0;
    *used |= 1 << i;
    return i;
}

/* Starts sound sfx in slot i, stopping what played there. */
void func_8010296C_1F16AC_MechaMarathon(s16 sfx, s16 i) {
    if (D_80108498_1F71D8_MechaMarathon[i] != -1) {
        func_80079848_7A448(D_80108498_1F71D8_MechaMarathon[i]);
    }
    D_80108498_1F71D8_MechaMarathon[i] = func_80079798_7A398(sfx, i);
}

/* Camera: sets both cameras once; camera 0 follows the host once the result is out. */
void func_801029E8_1F1728_MechaMarathon(void) {
    omObjData* o;
    s32 i;
    f32 s;
    f32 back;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dzoom;

    if (D_8010805C_1F6D9C_MechaMarathon != 0) {
        D_8010805C_1F6D9C_MechaMarathon = 0;
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 24.0f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = 1120.0f;
            D_80102770_103370[i].x = 337.0f;
            D_80102770_103370[i].y = 322.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = -150.0f;
            D_801013B0_101FB0[i].y = 160.0f;
            D_801013B0_101FB0[i].z = 220.0f;
        }
    }
    if (D_80108465_1F71A5_MechaMarathon & 2) {
        o = D_801085F0_1F7330_MechaMarathon[4].obj;
        s = func_800B80D0_B8CD0(23.0) * 100.0;
        back = func_800B75D0_B81D0(23.0) * 100.0 * func_800B80D0_B8CD0(38.0);
        dx = D_801013B0_101FB0[0].x - (o->trans.x - back);
        dy = D_801013B0_101FB0[0].y - (s + o->trans.y);
        dz = D_801013B0_101FB0[0].z - o->trans.z;
        dzoom = D_800F94A8_FA0A8[0] - 700.0f;
        if (abs((s32)dx) > 20.0f) {
            D_801013B0_101FB0[0].x -= dx * 0.07;
        }
        if (abs((s32)dy) > 40.0f) {
            D_801013B0_101FB0[0].y -= dy * 0.07;
        }
        if (abs((s32)dz) > 20.0f) {
            D_801013B0_101FB0[0].z -= dz * 0.07;
        }
        if (abs((s32)dzoom) > 100.0f) {
            D_800F94A8_FA0A8[0] -= dzoom * 0.07;
        }
    }
}

/* The track: three segments wrap around the scroll; the crowd behind them wakes as it passes. */
/* obj->model[], by byte offset. */
#define MDL(o, k) (*(s16*)((u8*)(o)->model + (k)))

#ifdef NON_MATCHING
void func_80102D60_1F1AA0_MechaMarathon(omObjData* obj) {
    MMActor* a = &D_801085F0_1F7330_MechaMarathon[5];
    omObjData* o2 = a[1].obj;
    f32 ofs[3] = { -1500.0f, 0.0f, 1500.0f };
    MMActor* c;
    f32 t;
    f32 y;
    f32 z;
    s32 k;
    f32 base;
    f32 x;
    s16 i;
    f32* p;
    u16* q;

    if (D_80108478_1F71B8_MechaMarathon != 0) {
        x = 0.0f;
        for (i = 0; i < 4; i++) {
            t = (&D_801085F0_1F7330_MechaMarathon[9])[i].unk_38;
            if (t < x) {
                x = t;
            }
        }
        base = D_80108468_1F71A8_MechaMarathon = -x;
        while (base >= 4500.0f) {
            base -= 4500.0f;
        }
        c = &D_801085F0_1F7330_MechaMarathon[6];
        p = &c->unk_38;
        q = &c->unk_22;
        for (i = 0; i < 3; i++) {
            x = base + ofs[i];
            if (i != 0) {
                if (x >= 3000.0f) {
                    x -= 4500.0f;
                }
                k = i * 2;
                y = 0.0f;
                z = -500.0f;
                func_80029714_2A314(MDL(obj, k), x, y, y);
                func_80029714_2A314(MDL(obj, k + 12), x, y, y);
                func_80029714_2A314(MDL(obj, k + 18), x, y, y);
                func_80029714_2A314(MDL(o2, k), x, y, z);
            } else {
                obj->trans.x = x;
                k = i * 2;
                func_80029714_2A314(MDL(obj, k + 12), x, 0.0f, 0.0f);
                func_80029714_2A314(MDL(obj, k + 18), x, 0.0f, 0.0f);
                o2->trans.x = x;
            }
            func_80029714_2A314(MDL(o2, k + 6), x, 0.0f, -500.0f);
            if ((*p > 0.0f) & (x < 0.0f)) {
                if (D_80108060_1F6DA0_MechaMarathon != 0) {
                    D_80108060_1F6DA0_MechaMarathon--;
                } else {
                    *q += 3;
                    if (*q >= 6) {
                        *q = 5;
                        func_800298A4_2A4A4(o2->model[i], 4, 4);
                        func_800298A4_2A4A4(o2->model[i + 3], 4, 4);
                    }
                    func_8003F57C_4017C(D_80108472_1F71B2_MechaMarathon[i], *q);
                }
                func_800298A4_2A4A4(obj->model[i + 6], 4, 4);
                func_800298A4_2A4A4(obj->model[i + 9], 4, 0);
            }
            *p = x;
            p++;
            q++;
        }
        if (D_80108064_1F6DA4_MechaMarathon == 0 && D_80108468_1F71A8_MechaMarathon > 1500.0f) {
            func_800298A4_2A4A4(obj->model[3], 4, 4);
            func_800298A4_2A4A4(obj->model[4], 4, 4);
            D_80108064_1F6DA4_MechaMarathon = 1;
        } else {
            func_80029714_2A314(obj->model[3], D_80108468_1F71A8_MechaMarathon - 60.0f, -2.0f, 0.0f);
            func_80029714_2A314(obj->model[4], D_80108468_1F71A8_MechaMarathon - 60.0f, 0.0f, 0.0f);
        }
        x = D_80108468_1F71A8_MechaMarathon + a->unk_44;
        if ((x > -750.0f) & (x < 1500.0f)) {
            func_80029714_2A314(obj->model[5], x, -2.0f, 0.0f);
            func_800298A4_2A4A4(obj->model[5], 4, 0);
        } else {
            func_800298A4_2A4A4(obj->model[5], 4, 4);
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108270_1F6FB0_MechaMarathon[4] = { 0xC4BB8000, 0x00000000, 0x44BB8000, 0x00000000 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_80102D60_1F1AA0_MechaMarathon);
#endif

void func_801032B8_1F1FF8_MechaMarathon(omObjData* obj) {
    s16 i;

    obj->model[0] = LoadFormFile(0x350000, 0x3699);
    obj->model[1] = LoadFormFile(0x350000, 0x3699);
    obj->model[2] = LoadFormFile(0x350000, 0x3699);
    obj->model[3] = LoadFormFile(0x350004, 0x3699);
    obj->model[4] = LoadFormFile(0x350005, 0x36B9);
    obj->model[5] = LoadFormFile(0x350006, 0x36DD);
    obj->model[6] = LoadFormFile(0x35000B, 0x3699);
    obj->model[7] = LoadFormFile(0x350007, 0x3699);
    obj->model[8] = LoadFormFile(0x350007, 0x3699);
    obj->model[9] = LoadFormFile(0x350008, 0x369D);
    obj->model[10] = LoadFormFile(0x350009, 0x369D);
    obj->model[11] = LoadFormFile(0x35000A, 0x369D);
    D_80108790_1F74D0_MechaMarathon = -1500.0f;
    *(s32*)&D_80108794_1F74D4_MechaMarathon = 0;
    D_80108798_1F74D8_MechaMarathon = 1500.0f;
    D_8010879C_1F74DC_MechaMarathon = (u8)D_80108494_1F71D4_MechaMarathon * -1.5f;
    D_8010879C_1F74DC_MechaMarathon += (D_80108494_1F71D4_MechaMarathon >> 8) * -150.0f;
    obj->trans.x = -1500.0f;
    func_80029714_2A314(obj->model[1], D_80108794_1F74D4_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[2], D_80108798_1F74D8_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[3], -60.0f, -2.0f, 0.0f);
    func_80029714_2A314(obj->model[4], -60.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[5], D_8010879C_1F74DC_MechaMarathon, -2.0f, 0.0f);
    func_80029714_2A314(obj->model[6], D_80108790_1F74D0_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[7], D_80108794_1F74D4_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[8], D_80108798_1F74D8_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[9], D_80108790_1F74D0_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[10], D_80108794_1F74D4_MechaMarathon, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[11], D_80108798_1F74D8_MechaMarathon, 0.0f, 0.0f);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.003f;
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[6], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[7], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[8], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[9], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[10], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[11], obj->scale.x, obj->scale.y, obj->scale.z);
    for (i = 0; i < 12; i++) {
        func_80029EDC_2AADC(obj->model[i], 1);
    }
    obj->func_ptr = func_80102D60_1F1AA0_MechaMarathon;
}

void func_801036D8_1F2418_MechaMarathon(void) {
    D_801085F0_1F7330_MechaMarathon[5].obj = omAddObj(10, 12, 0, -1, func_801032B8_1F1FF8_MechaMarathon);
}

void func_80103714_1F2454_MechaMarathon(omObjData* obj) {
    if (D_80108478_1F71B8_MechaMarathon != 0) {
        if (D_80108468_1F71A8_MechaMarathon < 3000.0f) {
            if (D_80108468_1F71A8_MechaMarathon > 750.0f) {
                func_800298A4_2A4A4(obj->model[0], 4, 0);
                func_800298A4_2A4A4(obj->model[3], 4, 0);
            }
            if (D_80108468_1F71A8_MechaMarathon > 1500.0f) {
                func_800298A4_2A4A4(obj->model[1], 4, 0);
                func_800298A4_2A4A4(obj->model[4], 4, 0);
            }
            if (D_80108468_1F71A8_MechaMarathon > 2250.0) {
                func_800298A4_2A4A4(obj->model[2], 4, 0);
                func_800298A4_2A4A4(obj->model[5], 4, 0);
            }
        }
    }
}

/* The crowd along the track. */
#ifdef NON_MATCHING
void func_8010384C_1F258C_MechaMarathon(omObjData* obj) {
    MMActor* c = &D_801085F0_1F7330_MechaMarathon[6];
    f32* t = &D_801085F0_1F7330_MechaMarathon[5].unk_38;
    s16 frames[3] = { 0, 2, 1 };
    u16* q = &c->unk_22;
    void* data;
    s16 tex;
    s16 i;

    tex = 0;
    for (i = 0; i < 3; i++) {
        obj->model[i] = LoadFormFile(0x350001, 0x3689);
        if (i != 0) {
            D_80108472_1F71B2_MechaMarathon[i] = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[i]].hmf, tex & 0xFF, 0, D_80108290_1F6FD0_MechaMarathon);
        } else {
            data = DataRead(0x350003);
            tex = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[i]].hmf, data, 0, D_80108290_1F6FD0_MechaMarathon);
            D_80108472_1F71B2_MechaMarathon[i] = tex;
            DataClose(data);
        }
        func_80029A8C_2A68C(obj->model[i]);
        func_80029AFC_2A6FC(obj->model[i]);
        func_8003E4F4_3F0F4(D_80108472_1F71B2_MechaMarathon[i], 1, 1);
        func_8003F57C_4017C(D_80108472_1F71B2_MechaMarathon[i], *q++ = frames[i]);
        if (i != 0) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        func_80029EDC_2AADC(obj->model[i], 1);
    }
    for (; i < 6; i++) {
        obj->model[i] = LoadFormFile(0x350002, 0x1699);
        if (i != 3) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        func_80029EDC_2AADC(obj->model[i], 1);
    }
    c->unk_38 = *t++;
    c->unk_3C = t[0];
    c->unk_40 = t[1];
    obj->trans.x = c->unk_38;
    obj->trans.z = -500.0f;
    func_80029714_2A314(obj->model[1], c->unk_3C, 0.0f, -500.0f);
    func_80029714_2A314(obj->model[2], c->unk_40, 0.0f, -500.0f);
    func_80029714_2A314(obj->model[3], c->unk_38, 0.0f, -500.0f);
    func_80029714_2A314(obj->model[4], c->unk_3C, 0.0f, -500.0f);
    func_80029714_2A314(obj->model[5], c->unk_40, 0.0f, -500.0f);
    obj->func_ptr = func_80103714_1F2454_MechaMarathon;
}
#else
__asm__(".section .rodata");
const u32 D_80108288_1F6FC8_MechaMarathon[2] = { 0x00000002, 0x00010000 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_8010384C_1F258C_MechaMarathon);
#endif

__asm__(".section .rodata");
const char D_80108290_1F6FD0_MechaMarathon[] = "147_suji_DEF";

void func_80103BEC_1F292C_MechaMarathon(void) {
    D_801085F0_1F7330_MechaMarathon[6].obj = omAddObj(20, 6, 0, -1, func_8010384C_1F258C_MechaMarathon);
}

/* Clears player i's controller. */
void func_80103C28_1F2968_MechaMarathon(s32 i) {
    ContBtn[gPlayers[i].port] = 0;
    ContBtnTrg[gPlayers[i].port] = 0;
    ContStkX[gPlayers[i].port] = 0;
    ContStkY[gPlayers[i].port] = 0;
}

void func_80103CA8_1F29E8_MechaMarathon(omObjData* obj, u16 mot, s16 start, s16 speed, s16 flags) {
    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[mot]), start, speed, flags);
}

/* Collects the player's (or the CPU's) buttons for a 20-frame window; at its end, counts the
   2-frame slots that held both A and B. */
#ifdef NON_MATCHING
void func_80103D34_1F2A74_MechaMarathon(omObjData* obj) {
    MMActor* a = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    MMCpu* cpu = &D_80108548_1F7288_MechaMarathon[obj->work[0]];
    u16 wait[4] = { 30, 20, 10, 5 };
    u16 rate[4] = { 30, 70, 90, 90 };
    MMFast fast[4] = { { 0x60, 12 }, { 0x40, 12 }, { 0x20, 12 }, { 0x10, 12 } };
    u16 btn;
    s32 d;
    s32 k2;
    u16* wp;
    s16 cnt;
    s16 k;
    s32 j;
    s32 hasA;
    s32 hasB;

    if (a->unk_26 < 20) {
        btn = 0;
        if (a->unk_2C != 0) {
            d = gPlayers[obj->work[0]].cpu_difficulty;
            if (cpu->unk_08 != 0) {
                cpu->unk_08--;
            } else {
                k2 = d;
                cpu->unk_08 = rand8() % 10 + *((wp = wait) + k2);
                if (rand8() < ((MMFast*)(wp + 8))[k2].chance) {
                    cpu->unk_04 = fast[k2].rate;
                } else {
                    cpu->unk_04 = 300 / (rand8() % 70 + rate[d]);
                }
            }
            if (cpu->unk_00 != 0) {
                cpu->unk_00--;
            } else {
                btn = 0xC000;
                cpu->unk_00 = cpu->unk_04;
            }
        } else {
            btn = ContBtnTrg[gPlayers[obj->work[0]].port];
        }
        D_801084A8_1F71E8_MechaMarathon[obj->work[0]][a->unk_26++] = btn;
        cnt = 0;
        if (a->unk_26 >= 20) {
            hasA = 0;
            for (k = 0; k < 20;) {
                hasB = 0;
                for (j = 0; j < 2; j++) {
                    btn = D_801084A8_1F71E8_MechaMarathon[obj->work[0]][k];
                    if (btn & 0x8000) {
                        hasA = 1;
                    }
                    if (btn & 0x4000) {
                        hasB = 1;
                    }
                    D_801084A8_1F71E8_MechaMarathon[obj->work[0]][k] = 0;
                    k++;
                }
                if (hasB & hasA) {
                    cnt++;
                }
                hasA = 0;
            }
            a->unk_28 += cnt;
            a->unk_24 = cnt;
            a->unk_26 = 0;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_801082A0_1F6FE0_MechaMarathon[2] = { 0x001E0014, 0x000A0005 };
const u32 D_801082A8_1F6FE8_MechaMarathon[2] = { 0x001E0046, 0x005A005A };
const u32 D_801082B0_1F6FF0_MechaMarathon[4] = { 0x0060000C, 0x0040000C, 0x0020000C, 0x0010000C };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_80103D34_1F2A74_MechaMarathon);
#endif

/* A player. */
#ifdef NON_MATCHING
void func_80104104_1F2E44_MechaMarathon(omObjData* obj) {
    MMActor* a;
    MMActor* b;
    s32 busy;
    s32 lose;
    s16 max;
    s16 ties;
    s16 i;
    s32 pick;
    u16* cap;
    s32 v;

    a = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    lose = 0;
    switch (a->state) {
    case 0:
        if (D_8010846C_1F71AC_MechaMarathon > 30) {
            func_80103CA8_1F29E8_MechaMarathon(obj, 1, 0, 30, 1);
            a->state = 1;
            PlayMusic(0x22);
        }
        break;
    case 1:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 1, 1);
            if (obj->work[0] == 0) {
                D_8010818C_1F6ECC_MechaMarathon = func_80029D0C_2A90C(obj->model[0]);
            }
            a->state = 2;
        }
        break;
    case 2:
        if (D_80108464_1F71A4_MechaMarathon == 2) {
            func_80103D34_1F2A74_MechaMarathon(obj);
            if (a->unk_24 != 0) {
                a->unk_22 = a->unk_24 - 1;
                func_80029FE4_2ABE4(obj->model[0], D_80108158_1F6E98_MechaMarathon[a->unk_22]);
                func_80029E80_2AA80(obj->model[0], 1, 0);
                a->state = 3;
                func_8010296C_1F16AC_MechaMarathon(a->unk_22 >= 5 ? 0x26D : 0x26C, obj->work[0]);
            }
        } else if (D_80108464_1F71A4_MechaMarathon == 3) {
            a->state = 4;
        }
        break;
    case 3:
        if (func_80029CE4_2A8E4(obj->model[0]) >= D_8010818C_1F6ECC_MechaMarathon) {
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 1, 1);
            a->state = 2;
        }
        func_80103D34_1F2A74_MechaMarathon(obj);
        break;
    case 4:
        if (obj->work[0] == 0) {
            max = -1;
            ties = 0;
            for (i = 0; i < 4; i++) {
                b = &D_801085F0_1F7330_MechaMarathon[i];
                if (b->state != 4) {
                    lose = 1;
                } else if (max < b->unk_28) {
                    max = b->unk_28;
                    ties = 1;
                } else if (max == b->unk_28) {
                    ties++;
                }
            }
            v = lose;
            if (v == 0) {
                a->state = 5;
                if (max != 0) {
                    pick = rand8() % ties;
                    b = D_801085F0_1F7330_MechaMarathon;
                    for (i = 0; i < 4; i++) {
                        if (b[i].unk_28 == max) {
                            if ((s16)pick-- == 0) {
                                (b + 9)[i].unk_28 = 1;
                                break;
                            }
                        }
                    }
                }
            }
        } else if (D_80108610_1F7350_MechaMarathon == 5) {
            a->state = D_80108610_1F7350_MechaMarathon;
        }
        if (a->state == 5) {
            func_80103CA8_1F29E8_MechaMarathon(obj, 3, 0, 10, 1);
            if (a->unk_2C == 0) {
                if (a->unk_28 != 0) {
                    omVibrate(obj->work[0], 20, 0, 20);
                }
            } else {
                cap = &D_80108184_1F6EC4_MechaMarathon[gPlayers[obj->work[0]].cpu_difficulty];
                if (a->unk_28 > *cap) {
                    a->unk_28 = *cap;
                }
            }
        }
        break;
    case 5:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[3]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029E80_2AA80(obj->model[0], 6, 6);
            a->state = 6;
        }
        break;
    case 6:
        a->unk_38 += 4.0f;
        if (a->unk_38 > 190.0f) {
            func_80103CA8_1F29E8_MechaMarathon(obj, 0, 0, 10, 1);
            a->state = 7;
        }
        break;
    case 7:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[0]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            func_80029E80_2AA80(obj->model[0], 4, 0);
            a->state = 8;
            D_80108465_1F71A5_MechaMarathon |= 0x10;
        }
        break;
    case 8:
        if (D_80108468_1F71A8_MechaMarathon > 1500.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            func_80029E80_2AA80(obj->model[0], 1, 1);
            a->state = 9;
        } else if (D_80108464_1F71A4_MechaMarathon == 4) {
            if ((D_80108465_1F71A5_MechaMarathon & 2) && obj->work[0] != D_80108476_1F71B6_MechaMarathon) {
                lose = 1;
            }
        } else if (D_80108464_1F71A4_MechaMarathon == 6) {
            lose = 1;
        }
        v = lose;
        if (v != 0 && _CheckFlag(12) == 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 2, 0);
            a->state = 9;
        }
        break;
    case 9:
        break;
    }
    obj->trans.x = a->unk_38 + D_80108468_1F71A8_MechaMarathon;
    if (a->state >= 6 && a->state < 9) {
        func_80029714_2A314(obj->model[1], obj->trans.x, 9.0f, obj->trans.z + 2.5f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_80104104_1F2E44_MechaMarathon);
#endif

__asm__(".section .rodata");
const char D_801082E8_1F7028_MechaMarathon[] = "c005l_0_DEF";
const char D_801082F4_1F7034_MechaMarathon[] = "c004l_0_DEF";
const char D_80108300_1F7040_MechaMarathon[] = "c003l_0_DEF";
const char D_8010830C_1F704C_MechaMarathon[] = "c002l_0_DEF";
const char D_80108318_1F7058_MechaMarathon[] = "c001l_0_DEF";
const char D_80108324_1F7064_MechaMarathon[] = "c000l_0_DEF";

void func_8010489C_1F35DC_MechaMarathon(omObjData* obj) {
    MMActor* a;
    s32 chr;
    s32 dir;
    s32 dir2;

    a = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    func_800B0EF0_B1AF0(D_801084A8_1F71E8_MechaMarathon, 0, 0x28);
    func_800B0EF0_B1AF0(D_80108548_1F7288_MechaMarathon, 0, 0x30);
    chr = gPlayers[obj->work[0]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    dir2 = 0x350000;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[chr].unk_08, 0x26A9);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80018CCC_198CC(obj, 0, dir | D_80108068_1F6DA8_MechaMarathon[chr][0]);
    func_80018CCC_198CC(obj, 1, D_80108068_1F6DA8_MechaMarathon[chr][1] | dir2);
    func_80018CCC_198CC(obj, 2, dir | D_80108068_1F6DA8_MechaMarathon[chr][6]);
    func_80018CCC_198CC(obj, 3, dir | D_80108068_1F6DA8_MechaMarathon[chr][7]);
    obj->model[1] = func_80018A30_19630(1, 0x14C9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    if (gPlayers[obj->work[0]].flags & 1) {
        a->unk_2C = 1;
    }
    a->unk_38 = obj->trans.x = D_80108128_1F6E68_MechaMarathon[obj->work[1]].x;
    obj->trans.y = D_80108128_1F6E68_MechaMarathon[obj->work[1]].y;
    obj->trans.z = D_80108128_1F6E68_MechaMarathon[obj->work[1]].z;
    obj->rot.y = 270.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, 9.0f, obj->trans.z + 2.5f);
    func_800297E8_2A3E8(obj->model[1], 1.25f, obj->scale.y, 1.25f);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 0);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80103C28_1F2968_MechaMarathon(obj->work[0]);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_80104104_1F2E44_MechaMarathon;
}

#ifdef NON_MATCHING
void func_80104BE0_1F3920_MechaMarathon(void) {
    omObjData* o;
    MMActor* a;
    u64 used;
    s16 i;
    s32 v;

    used = 0;
    for (i = 0; i < 4; i++) {
        a = &D_801085F0_1F7330_MechaMarathon[i];
        o = omAddObj(200, 2, 4, -1, func_8010489C_1F35DC_MechaMarathon);
        switch (i) {
        case 0:
            v = 0;
            break;
        default:
            v = 0;
            break;
        case 3:
            v = 3;
            break;
        case 1:
            v = 1;
            break;
        case 2:
            v = 2;
            break;
        }
        o->work[0] = v;
        o->work[1] = func_8010281C_1F155C_MechaMarathon(4, &used);
        a->obj = o;
        D_800FC87A_FD47A++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_80104BE0_1F3920_MechaMarathon);
#endif

/* Swaps the host's face texture. */
void func_80104D08_1F3A48_MechaMarathon(omObjData* obj, u8 k) {
    s8 chr;

    chr = gPlayers[obj->work[0]].character;
    func_8003E888_3F488(D_80108580_1F72C0_MechaMarathon);
    D_80108580_1F72C0_MechaMarathon = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_80108578_1F72B8_MechaMarathon[k], 0, D_801081A0_1F6EE0_MechaMarathon[chr]);
}

/* The host: runs to the winner's spot, gives the result. */
#ifdef NON_MATCHING
void func_80104DC8_1F3B08_MechaMarathon(omObjData* obj) {
    MMActor* h = &D_801085F0_1F7330_MechaMarathon[4];
    omObjData* r;
    s32 chr;
    s32 c;
    f32 target;
    f32 reach;
    f32 frame;
    s16 i;

    chr = gPlayers[obj->work[0]].character;
    r = (&D_801085F0_1F7330_MechaMarathon[9])[obj->work[0]].obj;
    target = r->trans.x + 90.0f + 50.0f;
    switch (h->state) {
    case 0:
        if (target < obj->trans.x) {
            func_80103CA8_1F29E8_MechaMarathon(obj, 1, 0, 10, 1);
            h->state = 1;
        } else {
            h->state = 4;
        }
        break;
    case 1:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            h->unk_38 = -0.0f;
            h->unk_3C = -0.0f;
            h->state = 2;
            func_8003E4F4_3F0F4(D_80108580_1F72C0_MechaMarathon, 1, 1);
        }
        break;
    case 2:
        h->unk_38 += -0.4f;
        if (h->unk_38 < -4.0f) {
            h->unk_38 = -4.0f;
        }
        h->unk_3C += h->unk_38;
        if (h->unk_3C < -16.0f) {
            h->unk_3C = -16.0f;
        }
        switch (D_801081B8_1F6EF8_MechaMarathon) {
        case 0:
            c = chr;
            reach = 130.0f;
            if (c == 5) {
                reach = 140.0f;
            }
            if (obj->trans.x < target + reach) {
                func_80103CA8_1F29E8_MechaMarathon(obj, 2, 0, chr == 5 ? 10 : 2, 1);
                D_801081B8_1F6EF8_MechaMarathon = 1;
            }
            break;
        case 1:
            if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
                func_80029B80_2A780(obj->model[0], obj->motion[2]);
                func_80029C74_2A874(obj->model[0], 0.0f);
                func_80029E80_2AA80(obj->model[0], 2, 0);
                D_801081B8_1F6EF8_MechaMarathon = 2;
            }
            break;
        }
        obj->trans.x += h->unk_3C;
        if (obj->trans.x < target) {
            obj->trans.x = target;
            h->state = 3;
        }
        break;
    case 3:
        frame = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= frame) {
            func_80103CA8_1F29E8_MechaMarathon(obj, 0, 0, 10, 1);
            func_800794A8_7A0A8(40);
            h->state = 4;
        }
        break;
    case 4:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
            func_80029B80_2A780(obj->model[0], obj->motion[0]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            D_80108465_1F71A5_MechaMarathon |= 1;
            h->state = 5;
        }
        break;
    case 5:
        if (D_80108465_1F71A5_MechaMarathon & 2) {
            func_80104D08_1F3A48_MechaMarathon(obj, 1);
            obj->rot.y = D_80102770_103370[0].y;
            func_80029B80_2A780(obj->model[0], obj->motion[3]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            h->state = 6;
            i = obj->work[0];
            func_800732B0_73EB0(D_80108054_1F6D94_MechaMarathon[D_801084A0_1F71E0_MechaMarathon[i][0]] | D_8010803C_1F6D7C_MechaMarathon[gPlayers[i].character]);
        }
        break;
    case 6:
        break;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 9.0f, obj->trans.z + 2.5f);
    func_800297E8_2A3E8(obj->model[1], 1.25f, obj->scale.y, 1.25f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_80104DC8_1F3B08_MechaMarathon);
#endif

__asm__(".section .rodata");
const char D_80108354_1F7094_MechaMarathon[] = "heiho_mario_head_DEF";
const char D_8010836C_1F70AC_MechaMarathon[] = "heiho_mario_elbow_DEF";
const char D_80108384_1F70C4_MechaMarathon[] = "heiho_mario_body_DEF";

#ifdef NON_MATCHING
void func_801052C0_1F4000_MechaMarathon(omObjData* obj) {
    MMActor* base;
    MMActor* base2;
    omObjData* player;
    omObjData* robot;
    u16 chr;
    s32 dir;
    s32 i;
    s32 k;
    f32 x;
    f32 near;
    f32 lim;

    base = &D_801085F0_1F7330_MechaMarathon[4];
    base2 = &D_801085F0_1F7330_MechaMarathon[4];
    player = (base + obj->work[0] - 4)->obj;
    robot = (base2 + obj->work[0] + 5)->obj;
    chr = gPlayers[obj->work[0]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[chr].unk_0C, 0x26A9);
    for (i = 0; (u16)i < 2; i++) {
        dir = D_80108190_1F6ED0_MechaMarathon[chr] << 16;
        D_80108578_1F72B8_MechaMarathon[(u16)i] = DataRead(dir | D_8010819C_1F6EDC_MechaMarathon[(u16)i]);
    }
    D_80108580_1F72C0_MechaMarathon = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_80108578_1F72B8_MechaMarathon[0], 0, D_801081A0_1F6EE0_MechaMarathon[i = (u16)chr]);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80018CCC_198CC(obj, 0, dir | D_80108068_1F6DA8_MechaMarathon[i][0]);
    func_80018CCC_198CC(obj, 1, dir | D_80108068_1F6DA8_MechaMarathon[i][2]);
    func_80018CCC_198CC(obj, 2, dir | D_80108068_1F6DA8_MechaMarathon[i][3]);
    k = (rand8() & 1) + 4;
    func_80018CCC_198CC(obj, 3, dir | D_80108068_1F6DA8_MechaMarathon[i][k]);
    D_801084A0_1F71E0_MechaMarathon[obj->work[0]][0] = k - 4;
    obj->model[1] = func_80018A30_19630(1, 0x14C9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    lim = 1125.0f;
    x = robot->trans.x;
    if (abs((s32)(x - player->trans.x)) > lim) {
        near = x + lim;
    } else {
        near = player->trans.x;
    }
    D_80108748_1F7488_MechaMarathon = near;
    obj->trans.x = D_801085F0_1F7330_MechaMarathon[4].unk_38;
    obj->trans.y = player->trans.y;
    obj->trans.z = player->trans.z;
    obj->rot.y = player->rot.y;
    func_80029714_2A314(obj->model[1], obj->trans.x, 9.0f, obj->trans.z + 2.5f);
    func_800297E8_2A3E8(obj->model[1], 1.25f, obj->scale.y, 1.25f);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029E80_2AA80(obj->model[0], 1, 0);
    func_80029C74_2A874(obj->model[0], func_80029CE4_2A8E4(player->model[0]));
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_800298A4_2A4A4(player->model[0], 4, 4);
    func_800298A4_2A4A4(player->model[1], 4, 4);
    obj->func_ptr = func_80104DC8_1F3B08_MechaMarathon;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_801052C0_1F4000_MechaMarathon);
#endif

/* The host takes the winner's place. */
void func_80105708_1F4448_MechaMarathon(s16 i) {
    omObjData* o;

    o = omAddObj(100, 2, 4, -1, func_801052C0_1F4000_MechaMarathon);
    o->work[0] = i;
    D_801085F0_1F7330_MechaMarathon[4].obj = o;
}

void func_80105754_1F4494_MechaMarathon(omObjData* obj, s16 i) {
    MMActor* a;

    a = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    if (a->unk_30 != 0) {
        if (--a->unk_30 == 0) {
            func_8010296C_1F16AC_MechaMarathon(0x26F, i);
        }
    }
}

/* A robot. */
#ifdef NON_MATCHING
void func_801057B0_1F44F0_MechaMarathon(omObjData* obj) {
    MMActor* r = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    MMActor* p = &D_801085F0_1F7330_MechaMarathon[obj->work[0] - 9];
    MMRobot* f = &D_80108588_1F72C8_MechaMarathon[obj->work[0] - 9];
    f32 unit[4] = { 1500.0f, 150.0f, 15.0f, 1.5f };
    omObjData* o;
    s16 i;
    s32 busy;
    s32 v;
    f32 best;
    f32 t;
    f32 frame;
    f32 lim;
    s16 j;
    s16 n;
    s32 w;

    busy = 0;
    i = obj->work[0] - 9;
    switch (r->state) {
    case 0:
        if (p->state == 3) {
            func_80029FE4_2ABE4(obj->model[0], D_80108158_1F6E98_MechaMarathon[p->unk_22]);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            r->state = 1;
        } else if (p->state >= 5) {
            if (p->unk_28 != 0) {
                func_80029B80_2A780(obj->model[0], obj->motion[1]);
                func_80029C74_2A874(obj->model[0], 0.0f);
                func_80029E80_2AA80(obj->model[0], 1, 0);
                r->state = 2;
                if (D_80108222_1F6F62_MechaMarathon == 0) {
                    D_80108222_1F6F62_MechaMarathon = 1;
                }
                func_8010296C_1F16AC_MechaMarathon(0x26E, i);
            } else {
                r->state = 6;
                D_80108470_1F71B0_MechaMarathon--;
            }
        }
        break;
    case 1:
        if (func_80029CE4_2A8E4(obj->model[0]) >= D_80108220_1F6F60_MechaMarathon) {
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 1, 1);
            r->state = 0;
        }
        break;
    case 2:
        frame = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= frame) {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            func_80029E80_2AA80(obj->model[0], 1, 0);
            r->unk_3C = -((p->unk_28 * 75) / 1.5);
            if (r->unk_28 != 0) {
                w = rand8() % 15 + 35;
            } else {
                w = rand8() % 50 - 25;
            }
            r->unk_3C -= w;
            func_800797DC_7A3DC(0x103, i);
            D_80108478_1F71B8_MechaMarathon = 1;
            r->state = 4;
        }
        break;
    case 4:
        if (r->unk_38 < r->unk_3C) {
            if ((r->unk_28 != 0) & (r->unk_28 < 4)) {
                switch (r->unk_28) {
                case 4:
                case 5:
                    break;
                case 1:
                    func_80029E80_2AA80(obj->model[0], 2, 0);
                    r->unk_28 = 2;
                    break;
                case 2:
                    if (r->unk_40 > 4.0f) {
                        r->unk_40 -= 0.2f;
                    }
                    if (obj->trans.y < 50.0f) {
                        func_80029E80_2AA80(obj->model[0], 2, 2);
                        r->unk_28 = 3;
                    } else if (f->unk_08 > -2.0f) {
                        f->unk_08 -= 0.2f;
                    }
                    break;
                case 3:
                    if (f->unk_08 < 2.0f) {
                        f->unk_08 += 0.2f;
                    } else {
                        r->unk_28 = 4;
                    }
                    break;
                }
            } else {
                func_80029E80_2AA80(obj->model[0], 2, 0);
                if (r->unk_40 != 0.0f) {
                    r->unk_40 -= r->unk_28 != 0 ? 0.01f : 0.1f;
                    if (r->unk_40 < 0.0f) {
                        r->unk_40 = 0.0f;
                    }
                } else if (r->unk_28 == 0) {
                    if (f->unk_00 != 0.0f) {
                        f->unk_00 -= 0.1f;
                        if (f->unk_00 < 0.0f) {
                            f->unk_00 = 0.0f;
                        }
                    }
                }
                if (f->unk_08 != -4.0f) {
                    f->unk_08 -= 0.2f;
                    if (f->unk_08 < -4.0f) {
                        f->unk_08 = -4.0f;
                    }
                }
            }
        } else {
            if (r->unk_40 != 8.0f) {
                r->unk_40 += 0.2f;
                if (r->unk_40 > 8.0f) {
                    r->unk_40 = 8.0f;
                }
            }
            lim = 75.0f;
            if (r->unk_24 != 0) {
                lim = 100.0f;
            }
            if (f->unk_14 & 0x10) {
                if (!(f->unk_14 & 1)) {
                    if (r->unk_26 != 0) {
                        r->unk_26--;
                    } else {
                        f->unk_08 = -((rand8() % 11 + 5) / 10 + 2.0f);
                        r->unk_26 = rand8() & 0x3C;
                        f->unk_14 = 1;
                    }
                }
            } else if (lim < obj->trans.y) {
                if (f->unk_08 > 0.0f) {
                    f->unk_0C = -0.2f;
                    f->unk_08 += -0.2f;
                    if (f->unk_08 < 0.0f) {
                        r->unk_24 = 1;
                        f->unk_10 = obj->trans.y;
                        f->unk_14 = 0x10;
                    }
                }
            } else if (f->unk_08 != 4.0f) {
                f->unk_0C = 0.2f;
                f->unk_08 += 0.2f;
                if (f->unk_08 > 4.0f) {
                    f->unk_08 = 4.0f;
                }
            }
            if (r->unk_24 != 0) {
                if (!(f->unk_14 & 0x10) && f->unk_08 < 0.0f) {
                    f->unk_04 = 2.0f;
                    f->unk_00 += 2.0f;
                } else {
                    if (f->unk_14 & 0x10) {
                        if (f->unk_14 & 0x20) {
                            f->unk_0C += 0.5f;
                            if (f->unk_0C > 1.0f) {
                                f->unk_0C = 1.0f;
                            }
                            f->unk_08 += f->unk_0C;
                            if (f->unk_08 >= 1.0f) {
                                f->unk_08 = 1.0f;
                            }
                            if (f->unk_10 <= obj->trans.y + f->unk_08) {
                                f->unk_14 ^= 0x20;
                            }
                        } else {
                            f->unk_0C += -0.5f;
                            if (f->unk_0C < -1.0f) {
                                f->unk_0C = -1.0f;
                            }
                            f->unk_08 += f->unk_0C;
                            if (f->unk_08 <= -1.0f) {
                                f->unk_08 = -1.0f;
                            }
                            if (obj->trans.y + f->unk_08 <= f->unk_10) {
                                f->unk_14 ^= 0x20;
                            }
                        }
                    }
                    if (f->unk_14 & 1) {
                        if (f->unk_00 < 0.0f) {
                            f->unk_04 += 0.2f;
                            if (f->unk_04 > 2.0f) {
                                f->unk_04 = 2.0f;
                            }
                            f->unk_00 += f->unk_04;
                            if (f->unk_00 >= 0.0f) {
                                f->unk_14 |= 0x10;
                            }
                        } else {
                            f->unk_04 -= 0.5f;
                            if (f->unk_04 < -3.0f) {
                                f->unk_04 = -3.0f;
                            }
                            f->unk_00 += f->unk_04;
                        }
                    } else if (f->unk_14 & 2) {
                        f->unk_04 += -0.2f;
                        if (f->unk_04 < -1.0f) {
                            f->unk_04 = -1.0f;
                        }
                        f->unk_00 += f->unk_04;
                        if (f->unk_00 < -2.0f) {
                            f->unk_14 ^= 2;
                        }
                    } else {
                        f->unk_04 += 0.2f;
                        if (f->unk_04 > 1.0f) {
                            f->unk_04 = 1.0f;
                        }
                        f->unk_00 += f->unk_04;
                        if (f->unk_00 > 2.0f) {
                            f->unk_14 ^= 2;
                        }
                    }
                }
            }
        }
        r->unk_38 -= r->unk_40;
        obj->trans.y += f->unk_08;
        if (obj->trans.y < 10.0f) {
            if (r->unk_28 != 0) {
                r->unk_2A = 20;
            } else {
                func_80029B80_2A780(obj->model[0], obj->motion[3]);
                func_80029C74_2A874(obj->model[0], 0.0f);
                func_80029E80_2AA80(obj->model[0], 1, 0);
            }
            obj->trans.y = 10.0f;
            r->unk_30 = 9;
            if (D_80108498_1F71D8_MechaMarathon[i] != -1) {
                func_80079848_7A448(D_80108498_1F71D8_MechaMarathon[i]);
            }
            D_80108498_1F71D8_MechaMarathon[i] = func_80079798_7A398(0x270, i);
            func_800298A4_2A4A4(obj->model[2], 4, 0);
            func_80029E80_2AA80(obj->model[2], 1, 0);
            r->state = 5;
        }
        break;
    case 5:
        frame = func_80029CE4_2A8E4(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= frame) {
            if (r->unk_2A != 0) {
                r->unk_2A--;
            } else {
                D_80108470_1F71B0_MechaMarathon--;
                r->state = 6;
            }
        }
        if (r->unk_28 == 0) {
            r->unk_44 -= 1.5f;
        }
        func_80105754_1F4494_MechaMarathon(obj, i);
        break;
    case 6:
        if (D_80108464_1F71A4_MechaMarathon == 4) {
            if (D_80108468_1F71A8_MechaMarathon != 0.0f && obj->work[0] == 9) {
                best = 65535.0f;
                for (j = 0; j < 4; j++) {
                    p = &(&D_801085F0_1F7330_MechaMarathon[9])[j];
                    o = p->obj;
                    if (p->state != 6) {
                        busy = 1;
                        break;
                    }
                    t = o->trans.x - D_80108468_1F71A8_MechaMarathon;
                    if (t < best) {
                        best = t;
                        D_80108476_1F71B6_MechaMarathon = j;
                    }
                }
                v = busy;
                if (v == 0) {
                    if (best < 0.0f) {
                        best = -best;
                    }
                    n = 0;
                    for (j = 0; j < 4; j++) {
                        while (best - unit[j] >= 0.0f) {
                            best -= unit[j];
                            n++;
                        }
                        if (n >= 10) {
                            n = 9;
                        }
                        D_80108480_1F71C0_MechaMarathon[j] = n;
                        n = 0;
                    }
                    D_80108496_1F71D6_MechaMarathon = D_80108480_1F71C0_MechaMarathon[0] * 0xA00;
                    D_80108496_1F71D6_MechaMarathon += D_80108480_1F71C0_MechaMarathon[1] << 8;
                    D_80108496_1F71D6_MechaMarathon += D_80108480_1F71C0_MechaMarathon[2] * 10;
                    D_80108496_1F71D6_MechaMarathon += D_80108480_1F71C0_MechaMarathon[3];
                    if (_CheckFlag(12) == 0) {
                        func_80105708_1F4448_MechaMarathon((u16)D_80108476_1F71B6_MechaMarathon);
                    }
                    r->state = 7;
                }
            }
            func_80105754_1F4494_MechaMarathon(obj, i);
        }
        break;
    case 3:
    case 7:
    case 8:
        break;
    }
    if (r->state == 4) {
        r->unk_34 = obj->trans.y * 10.0f;
        func_800796F0_7A2F0(D_80108498_1F71D8_MechaMarathon[i], r->unk_34);
    }
    if (D_80108478_1F71B8_MechaMarathon != 0) {
        obj->trans.x = r->unk_38 + D_80108468_1F71A8_MechaMarathon + f->unk_00;
        if (r->unk_22 == 0) {
            if (abs((s32)obj->trans.x) > 1500) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                func_800298A4_2A4A4(obj->model[1], 4, 4);
                func_80029E80_2AA80(obj->model[0], 1, 1);
                r->unk_22 = 1;
                return;
            }
            func_80029714_2A314(obj->model[1], obj->trans.x + r->unk_44, 9.0f, obj->trans.z + 2.5f);
            t = 1.0 - obj->trans.y * 0.0025;
            func_800297E8_2A3E8(obj->model[1], t, t, t);
            func_80029714_2A314(obj->model[2], obj->trans.x, 0.0f, obj->trans.z + 2.5f);
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_8010839C_1F70DC_MechaMarathon[5] = { 0x44BB8000, 0x43160000, 0x41700000, 0x3FC00000, 0x00000000 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_801057B0_1F44F0_MechaMarathon);
#endif

void func_801068A8_1F55E8_MechaMarathon(omObjData* obj) {
    MMActor* a;
    omObjData* player;
    s16 i;
    void* data;
    s32 dir;

    a = &D_801085F0_1F7330_MechaMarathon[obj->work[0]];
    player = (D_801085F0_1F7330_MechaMarathon + obj->work[0] - 9)->obj;
    func_800B0EF0_B1AF0(D_80108588_1F72C8_MechaMarathon, 0, 0x60);
    for (i = 0; i < 4; i++) {
        D_80108498_1F71D8_MechaMarathon[i] = -1;
    }
    dir = 0x350000;
    obj->model[0] = LoadFormFile(0x35000C, 0x34A9);
    for (i = 0; i < 3; i++) {
        data = DataRead(dir | D_801081CC_1F6F0C_MechaMarathon[obj->work[1] * 3 + i]);
        func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, D_80108214_1F6F54_MechaMarathon[i]);
        DataClose(data);
    }
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80018CCC_198CC(obj, 0, dir | D_801081BC_1F6EFC_MechaMarathon[0]);
    func_80018CCC_198CC(obj, 1, dir | D_801081BC_1F6EFC_MechaMarathon[1]);
    func_80018CCC_198CC(obj, 2, dir | D_801081BC_1F6EFC_MechaMarathon[2]);
    func_80018CCC_198CC(obj, 3, dir | D_801081BC_1F6EFC_MechaMarathon[3]);
    obj->model[1] = func_80018A30_19630(1, 0x14C9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 5.0f, 0.0f);
    obj->model[2] = func_80018A30_19630(11, 0x14CD);
    HmfModelObjAttrSet(obj->model[2], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[2]);
    func_80029AFC_2A6FC(obj->model[2]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[2]].mtx, 0.0f, 15.0f, 0.0f);
    func_80029E80_2AA80(obj->model[2], 1, 1);
    a->unk_38 = obj->trans.x = player->trans.x - 90.0f;
    obj->trans.y = player->trans.y;
    obj->trans.z = player->trans.z;
    obj->rot.y = player->rot.y;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80029714_2A314(obj->model[1], obj->trans.x, 9.0f, obj->trans.z + 2.5f);
    func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.0f);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 0);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    if (obj->work[0] == 9) {
        D_80108220_1F6F60_MechaMarathon = func_80029D0C_2A90C(obj->model[0]);
    }
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[2], 1);
    a->unk_26 = rand8() & 0x3C;
    obj->func_ptr = func_801057B0_1F44F0_MechaMarathon;
}

void func_80106CF4_1F5A34_MechaMarathon(void) {
    omObjData* o;
    MMActor* a;
    s16 i;

    for (i = 0; i < 4; i++) {
        a = &(&D_801085F0_1F7330_MechaMarathon[9])[i];
        o = omAddObj(300, 3, 4, -1, func_801068A8_1F55E8_MechaMarathon);
        o->work[0] = i + 9;
        o->work[1] = gPlayers[i].character;
        a->obj = o;
    }
}

/* The score: shows the digits, then the record's fanfare. */
void func_80106DC0_1F5B00_MechaMarathon(omObjData* obj) {
    MMActor* a = &D_801085F0_1F7330_MechaMarathon[8];
    s32 unused[1];
    s16 t;
    s16 i;

    switch (D_80108224_1F6F64_MechaMarathon) {
    case 0:
        if (D_80108464_1F71A4_MechaMarathon == 4 && func_80069538_6A138() == 0) {
            D_80108224_1F6F64_MechaMarathon = 1;
            D_80108226_1F6F66_MechaMarathon = 5;
        }
        break;
    case 1:
        if (--D_80108226_1F6F66_MechaMarathon == 0) {
            for (i = 0; i < 10; i++) {
                if (i < 4) {
                    SprBankSet(a->unk_32, i, D_80108480_1F71C0_MechaMarathon[i]);
                }
                if (i != 0 || D_80108480_1F71C0_MechaMarathon[0] != 0) {
                    SprAttrReset(a->unk_32, i, 0x8000);
                }
            }
            if (D_80108496_1F71D6_MechaMarathon > D_80108494_1F71D4_MechaMarathon) {
                D_80108226_1F6F66_MechaMarathon = 10;
                D_80108224_1F6F64_MechaMarathon = 2;
            } else {
                D_80108226_1F6F66_MechaMarathon = 45;
                D_80108224_1F6F64_MechaMarathon = 4;
            }
            D_80108462_1F71A2_MechaMarathon = 0xFF;
        }
        break;
    case 2:
        if (--D_80108226_1F6F66_MechaMarathon == 0) {
            D_80108460_1F71A0_MechaMarathon = func_800691FC_69DFC(14);
            D_80108226_1F6F66_MechaMarathon = 60;
            D_80108224_1F6F64_MechaMarathon = 3;
        }
        break;
    case 3:
        t = D_80108226_1F6F66_MechaMarathon;
        if (t == 0) {
            for (i = 0; i < 10; i++) {
                func_80082488_83088(a->unk_32, i, D_80108462_1F71A2_MechaMarathon);
            }
            t = D_80108462_1F71A2_MechaMarathon;
            if (t == 0) {
                D_80108224_1F6F64_MechaMarathon = 5;
                GWMgRecordSet(4, D_80108496_1F71D6_MechaMarathon);
            } else {
                t -= 16;
                D_80108462_1F71A2_MechaMarathon = t;
                if (t < 0) {
                    D_80108462_1F71A2_MechaMarathon = 0;
                }
            }
        } else {
            D_80108226_1F6F66_MechaMarathon = t - 1;
        }
        break;
    case 4:
        t = D_80108226_1F6F66_MechaMarathon;
        if (t != 0) {
            D_80108226_1F6F66_MechaMarathon = t - 1;
        } else {
            for (i = 0; i < 10; i++) {
                func_80082488_83088(a->unk_32, i, D_80108462_1F71A2_MechaMarathon);
            }
            t = D_80108462_1F71A2_MechaMarathon;
            if (t != 0) {
                t -= 16;
                D_80108462_1F71A2_MechaMarathon = t;
                if (t < 0) {
                    D_80108462_1F71A2_MechaMarathon = 0;
                }
            } else {
                D_80108224_1F6F64_MechaMarathon = 5;
            }
        }
        break;
    case 5:
        if (_CheckFlag(12) != 0) {
            D_80108465_1F71A5_MechaMarathon |= 4;
            D_80108224_1F6F64_MechaMarathon = 6;
        } else if (D_80108465_1F71A5_MechaMarathon & 1) {
            D_80108465_1F71A5_MechaMarathon |= 2;
            D_80108224_1F6F64_MechaMarathon = 6;
        }
        break;
    case 6:
        break;
    }
}

#ifdef NON_MATCHING
void func_801070DC_1F5E1C_MechaMarathon(omObjData* obj) {
    MMActor* m = &D_801085F0_1F7330_MechaMarathon[8];
    s16 pos[2][2] = { { 0x20, 0x16 }, { 0x5C, 0x78 } };
    u16 num[2];
    s16 anim1;
    s16 anim2;
    s16 anim3;
    s16* grp;
    s16 i;
    s16 j;
    s16 g;
    s16 a;
    s32 x;
    s16(*pp)[2];

    num[0] = 6;
    num[1] = 10;
    D_80108850_1F7590_MechaMarathon = func_8001A2F8_1AEF8(0x45);
    D_80108852_1F7592_MechaMarathon = func_8001A2F8_1AEF8(0x38);
    D_80108854_1F7594_MechaMarathon = func_8001A2F8_1AEF8(0x44);
    anim1 = func_8001A2F8_1AEF8(0x350028);
    anim2 = func_8001A2F8_1AEF8(0x350029);
    anim3 = func_8001A2F8_1AEF8(0x35002A);
    pp = pos;
    for (i = 0; i < 2; i++) {
        grp = &m->unk_32;
        if (i == 0) {
            grp = &m->unk_30;
        }
        g = SprCreate((*(u16(*)[2])(pp + 2))[i], 5);
        *grp = g;
        SprPosSet(g, 0, pp[i][0], pp[i][1]);
        SprAnimSet(*grp, 0, i != 0 ? m->unk_22 : m->state, 0);
        func_8008225C_82E5C(*grp, 0, 0);
        SprAttrSet(*grp, 0, 0x1000);
        SprAttrSet(*grp, 0, (i != 0) << 15);
        for (j = 1; j < (*(u16(*)[2])(pp + 2))[i]; j++) {
            func_800824F4_830F4(*grp, j, 0);
            if (i != 0) {
                if (j < 4) {
                    a = m->unk_22;
                } else if (j == 4) {
                    a = anim3;
                } else {
                    a = m->unk_24;
                }
            } else if (j < 4) {
                a = m->state;
            } else {
                a = anim1;
                if (j == 4) {
                    a = anim2;
                }
            }
            SprAnimSet(*grp, j, a, 0);
            func_8008225C_82E5C(*grp, j, 0);
            if (i != 0) {
                x = D_8010801C_1F6D5C_MechaMarathon[j];
            } else {
                x = D_80108010_1F6D50_MechaMarathon[j];
            }
            SprPosSet(*grp, j, x, 0);
            SprAttrSet(*grp, j, 0x1000);
            SprAttrSet(*grp, j, (i != 0) << 15);
            if (i != 0) {
                if (j == 4) {
                    SprBankSet(*grp, 4, 0);
                }
            } else if (j == 4) {
                SprBankSet(*grp, 4, 0);
            }
        }
        if (i != 0) {
            SprBankSet(*grp, 5, 0x18);
            SprBankSet(*grp, 6, 0);
            SprBankSet(*grp, 7, 0x11);
            SprBankSet(*grp, 8, 3);
            SprBankSet(*grp, 9, 0x12);
        } else {
            SprBankSet(*grp, 5, 0);
        }
    }
    for (j = 0; j < 4; j++) {
        SprBankSet(m->unk_30, j, D_80108030_1F6D70_MechaMarathon[j]);
    }
    obj->func_ptr = func_80106DC0_1F5B00_MechaMarathon;
}
#else
__asm__(".section .rodata");
const u32 D_80108424_1F7164_MechaMarathon[3] = { 0x00200016, 0x005C0078, 0x00000000 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_MechaMarathon/1F1540", func_801070DC_1F5E1C_MechaMarathon);
#endif

/* Reads the record into its digits, or sets it from the digits if there is none. */
void func_80107524_1F6264_MechaMarathon(void) {
    u16 r;

    D_80108494_1F71D4_MechaMarathon = r = func_800680D4_68CD4(4);
    if (D_80108494_1F71D4_MechaMarathon != 0) {
        D_80108030_1F6D70_MechaMarathon[0] = (D_80108494_1F71D4_MechaMarathon >> 8) / 10;
        D_80108030_1F6D70_MechaMarathon[1] = (D_80108494_1F71D4_MechaMarathon >> 8) % 10;
        D_80108030_1F6D70_MechaMarathon[2] = (r & 0xFF) / 10;
        D_80108030_1F6D70_MechaMarathon[3] = (r & 0xFF) % 10;
    } else {
        D_80108494_1F71D4_MechaMarathon = D_80108030_1F6D70_MechaMarathon[0] * 0xA00;
        D_80108494_1F71D4_MechaMarathon += D_80108030_1F6D70_MechaMarathon[1] << 8;
        D_80108494_1F71D4_MechaMarathon += D_80108030_1F6D70_MechaMarathon[2] * 10;
        D_80108494_1F71D4_MechaMarathon += D_80108030_1F6D70_MechaMarathon[3];
    }
    D_801085F0_1F7330_MechaMarathon[8].obj = omAddObj(400, 0, 0, -1, func_801070DC_1F5E1C_MechaMarathon);
}

void func_80107644_1F6384_MechaMarathon(omObjData* obj) {
    if (D_80108228_1F6F68_MechaMarathon != 0) {
        if (--D_80108228_1F6F68_MechaMarathon == 0) {
            func_8006D518_6E118();
        }
    }
    if (D_8010846E_1F71AE_MechaMarathon != 0) {
        D_8010846E_1F71AE_MechaMarathon--;
    }
}

void func_801076A4_1F63E4_MechaMarathon(omObjData* obj) {
    if (D_8010846C_1F71AC_MechaMarathon != 0) {
        D_8010846C_1F71AC_MechaMarathon--;
    } else if (D_80108464_1F71A4_MechaMarathon == 3) {
        obj->func_ptr = func_80107644_1F6384_MechaMarathon;
    }
    func_8006D4D0_6E0D0((D_8010846C_1F71AC_MechaMarathon + 29) / 30);
}

void func_80107730_1F6470_MechaMarathon(omObjData* obj) {
    func_800691FC_69DFC(10, 10, 160, 28);
    obj->func_ptr = func_801076A4_1F63E4_MechaMarathon;
}

void func_80107770_1F64B0_MechaMarathon(omObjData* obj) {
    switch (D_80108464_1F71A4_MechaMarathon) {
    case 1:
        if (D_8010846C_1F71AC_MechaMarathon == 0) {
            func_800691FC_69DFC(0);
            D_8010846C_1F71AC_MechaMarathon++;
        }
        break;
    case 2:
        obj->func_ptr = func_80107730_1F6470_MechaMarathon;
        break;
    }
}

void func_801077E4_1F6524_MechaMarathon(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80107808_1F6548_MechaMarathon(omObjData* obj) {
    s16 i;

    if (func_8008F618_90218() == 0) {
        if (D_80108476_1F71B6_MechaMarathon != -1) {
            for (i = 0; i < 2; i++) {
                DataClose(D_80108578_1F72B8_MechaMarathon[i]);
            }
        }
        obj->func_ptr = func_801077E4_1F6524_MechaMarathon;
    }
}

void func_8010789C_1F65DC_MechaMarathon(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_80107808_1F6548_MechaMarathon;
    }
}

void func_801078F4_1F6634_MechaMarathon(omObjData* obj) {
    switch (D_80108464_1F71A4_MechaMarathon) {
    case 0:
        if (D_8010846C_1F71AC_MechaMarathon == 0) {
            PlaySound(0x4A1);
        }
        if (D_8010846C_1F71AC_MechaMarathon++ > 60) {
            D_80108464_1F71A4_MechaMarathon = 1;
            D_8010846C_1F71AC_MechaMarathon = 0;
        }
        break;
    case 1:
        if (func_80069538_6A138() == 0) {
            D_80108464_1F71A4_MechaMarathon = 2;
            D_8010846C_1F71AC_MechaMarathon = 301;
        }
        break;
    case 2:
        if (D_8010846C_1F71AC_MechaMarathon == 0) {
            D_80108464_1F71A4_MechaMarathon = 3;
        }
        break;
    case 3:
        if (D_80108470_1F71B0_MechaMarathon == 0) {
            func_800691FC_69DFC(3);
            if (D_80108468_1F71A8_MechaMarathon != 0.0f) {
                D_80108464_1F71A4_MechaMarathon = 4;
            } else {
                D_80108464_1F71A4_MechaMarathon = 5;
                func_800794A8_7A0A8(40);
            }
            D_8010846E_1F71AE_MechaMarathon = 60;
        }
        break;
    case 4:
        if (D_80108465_1F71A5_MechaMarathon & 4) {
            D_80108464_1F71A4_MechaMarathon = 6;
            D_8010846C_1F71AC_MechaMarathon = 1;
            gPlayers[D_80108476_1F71B6_MechaMarathon].coins_mg_bonus = 10;
        } else if ((D_80108465_1F71A5_MechaMarathon & 2) && D_80108476_1F71B6_MechaMarathon >= 0) {
            func_800691FC_69DFC(6, gPlayers[D_80108476_1F71B6_MechaMarathon].character);
            if (D_80108496_1F71D6_MechaMarathon <= D_80108494_1F71D4_MechaMarathon) {
                PlayMusic(0x51);
                D_8010846C_1F71AC_MechaMarathon = 120;
            } else {
                PlayMusic(0x55);
                D_8010846C_1F71AC_MechaMarathon = 162;
            }
            D_80108464_1F71A4_MechaMarathon = 6;
            gPlayers[D_80108476_1F71B6_MechaMarathon].coins_mg_bonus = 10;
        }
        break;
    case 5:
        if (func_80069538_6A138() == 0) {
            if (_CheckFlag(12) != 0) {
                if (D_8010846E_1F71AE_MechaMarathon == 0) {
                    D_80108464_1F71A4_MechaMarathon = 7;
                }
            } else if (D_80108465_1F71A5_MechaMarathon & 0x10) {
                func_800691FC_69DFC(19);
                PlayMusic(0x57);
                D_80108464_1F71A4_MechaMarathon = 6;
                D_8010846C_1F71AC_MechaMarathon = 120;
            }
        }
        break;
    case 6:
        if (--D_8010846C_1F71AC_MechaMarathon == 0) {
            D_80108464_1F71A4_MechaMarathon = 7;
            if (D_80108465_1F71A5_MechaMarathon & 4) {
                func_800794A8_7A0A8(40);
            }
        }
        break;
    case 7:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80107808_1F6548_MechaMarathon;
        break;
    }
    func_801029E8_1F1728_MechaMarathon();
}

void func_80107C1C_1F695C_MechaMarathon(omObjData* obj) {
    func_80107F60_1F6CA0_MechaMarathon();
    func_80107FE4_1F6D24_MechaMarathon();
    D_80108464_1F71A4_MechaMarathon = 0;
    D_80108465_1F71A5_MechaMarathon = 0;
    D_80108468_1F71A8_MechaMarathon = 0.0f;
    D_8010846C_1F71AC_MechaMarathon = 0;
    D_80108464_1F71A4_MechaMarathon = 0;
    D_80108470_1F71B0_MechaMarathon = 4;
    D_80108476_1F71B6_MechaMarathon = -1;
    func_801036D8_1F2418_MechaMarathon();
    func_80103BEC_1F292C_MechaMarathon();
    func_80104BE0_1F3920_MechaMarathon();
    func_80106CF4_1F5A34_MechaMarathon();
    func_80107524_1F6264_MechaMarathon();
    InitFadeIn(0, 16);
    obj->func_ptr = func_801078F4_1F6634_MechaMarathon;
    omAddObj(5, 0, 0, -1, func_801029E8_1F1728_MechaMarathon);
    D_80108464_1F71A4_MechaMarathon = 0;
    omAddObj(1000, 0, 0, -1, func_80107770_1F64B0_MechaMarathon);
}

__asm__(".section .rodata");
const char D_80108450_1F7190_MechaMarathon[16] = "\202`\202a\202b";

void func_80107D0C_1F6A4C_MechaMarathon(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(30);
    func_80020D20_21920(20);
    omInitObjMan(30, 0);
    func_80079128_79D28();
    func_80026D28_27928(1);
    func_80026E00_27A00(0, -100.0f, 60.0f, 100.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, -100.0f, 60.0f, 100.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 22.386f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 22.386f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(900, 0, 0, -1, func_80107C1C_1F695C_MechaMarathon);
    omAddObj(900, 0, 0, -1, func_8010789C_1F65DC_MechaMarathon);
    func_8007273C_7333C((u8*)D_80108450_1F7190_MechaMarathon, 0);
    func_8007273C_7333C((u8*)D_80108450_1F7190_MechaMarathon, 1);
}
