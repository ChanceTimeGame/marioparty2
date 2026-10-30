#include "common.h"
#include "ovl_14.h"

/* The roller: its spin follows the solo player's input (damped, at most 8.49 degrees a frame);
   the surface speed D_801072C4 carries the players; the roller sound's pitch and volume follow
   it; the crank arm turns with it. */
// register allocation only: retail's int temporary is v0 and the float locals swap f4/f6 (30 diff lines)
#ifdef NON_MATCHING
void func_80105FD0_16EF10_ShockDropOrRoll(omObjData* obj) {
    f32 pitch;
    f32 max;
    s32 v;
    f32 vol;
    f32 y;

    if (D_80106F78_16FEB8_ShockDropOrRoll == 0) {
        D_801072A0_1701E0_ShockDropOrRoll = PlaySound(0x1CA);
        D_80106F78_16FEB8_ShockDropOrRoll = 1;
    }
    if (D_800F8FD0_F9BD0 == 1 || D_80106ED2_16FE12_ShockDropOrRoll == 0) {
        D_80106F70_16FEB0_ShockDropOrRoll *= 0.98;
        D_80106F70_16FEB0_ShockDropOrRoll += D_801072B0_1701F0_ShockDropOrRoll / 100.0f;
        if (D_80106F70_16FEB0_ShockDropOrRoll > 8.492568f) {
            D_80106F70_16FEB0_ShockDropOrRoll = 8.492568f;
        } else if (D_80106F70_16FEB0_ShockDropOrRoll < -8.492568f) {
            D_80106F70_16FEB0_ShockDropOrRoll = -8.492568f;
        }
        D_80106F74_16FEB4_ShockDropOrRoll += D_80106F70_16FEB0_ShockDropOrRoll;
        if (D_80106F74_16FEB4_ShockDropOrRoll >= 360.0f) {
            D_80106F74_16FEB4_ShockDropOrRoll -= 360.0f;
        } else if (D_80106F74_16FEB4_ShockDropOrRoll <= -360.0f) {
            D_80106F74_16FEB4_ShockDropOrRoll += 360.0f;
        }
    }
    if (D_80106ED0_16FE10_ShockDropOrRoll == 0) {
        D_801072C4_170204_ShockDropOrRoll = D_80106F70_16FEB0_ShockDropOrRoll / 360.0f * 1413.0f;
    } else {
        D_801072C4_170204_ShockDropOrRoll = 0.0f;
    }
    v = D_801072C4_170204_ShockDropOrRoll / 33.33333f * (max = 600.0f);
    if (v < 0) {
        v = -v;
    }
    pitch = v;
    if (pitch > max) {
        pitch = max;
    }
    pitch -= 300.0f;
    v = D_801072C4_170204_ShockDropOrRoll / 33.33333f * 32.0f;
    if (v < 0) {
        v = -v;
    }
    vol = v;
    vol *= 4.0f;
    if (vol > 127.0f) {
        vol = 127.0f;
    }
    func_800796F0_7A2F0(D_801072A0_1701E0_ShockDropOrRoll, pitch);
    func_800795D8_7A1D8(D_801072A0_1701E0_ShockDropOrRoll, vol);
    func_8002979C_2A39C(obj->model[1], D_80106F74_16FEB4_ShockDropOrRoll, 0.0f, 0.0f);
    y = func_800B7890_B8490(D_80106F74_16FEB4_ShockDropOrRoll) * 130.0f;
    func_80029714_2A314(obj->model[2], 0.0f, y, HuMathSin(D_80106F74_16FEB4_ShockDropOrRoll) * 130.0f);
    func_8002979C_2A39C(obj->model[2], HuMathSin(D_80106F74_16FEB4_ShockDropOrRoll) * 15.0f + 20.0f, 0.0f, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16EF10", func_80105FD0_16EF10_ShockDropOrRoll);
#endif

/* The roller's ground object: the collision model (hidden), the roller and the crank arm. */
void func_80106394_16F2D4_ShockDropOrRoll(omObjData* obj) {
    GroundWork* g;

    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = 0;
    obj->model[0] = func_80018A30_19630(0x240001, 0x20AB9);
    obj->model[1] = LoadFormFile(0x240000, 0x20AB9);
    obj->model[2] = LoadFormFile(0x240005, 0x20AB9);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.z, obj->trans.z, obj->trans.z);
    func_80029714_2A314(obj->model[2], 0.0f, 0.0f, 0.0f);
    func_8000BEA4_CAA4(obj, 1.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    obj->func_ptr = func_80105FD0_16EF10_ShockDropOrRoll;
}

/* The floor ground object: the stage floor and its two parts, with a box hit area. */
void func_801064B0_16F3F0_ShockDropOrRoll(omObjData* obj) {
    GroundWork* g;

    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = 1;
    obj->model[0] = -1;
    obj->model[1] = LoadFormFile(0x240002, 0x20AB9);
    obj->model[2] = LoadFormFile(0x240003, 0x20699);
    obj->model[3] = LoadFormFile(0x240004, 0x699);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.z, 200.0f, 600.0f);
    func_80029714_2A314(obj->model[2], 0.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[3], 0.0f, 0.0f, 0.0f);
    func_8000BF24_CB24(obj, -300.0f, -420.0f, -400.0f, 420.0f, 400.0f);
    obj->func_ptr = NULL;
}

__asm__(".section .rodata");
const u32 D_80107138_170078_ShockDropOrRoll[24] = { 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000001, 0x00000000, 0x00000001, 0x00000000 };

/* The sparks' update: while the solo player has not won, each spark flashes through its 24-frame
   texture script D_80107138 and its fan spins; once the three have lost the sparks hide. */
void func_801065F0_16F530_ShockDropOrRoll(omObjData* obj) {
    s8 i;
    s8 frame;
    s8 next;
    u8 tex;
    s8 on;

    on = 1;
    if (D_80106ED0_16FE10_ShockDropOrRoll == 1) {
        on = D_80106ED5_16FE15_ShockDropOrRoll != 0;
    }
    if (on == 1) {
        for (i = 0; i < 4; i++) {
            frame = D_80106F8C_16FECC_ShockDropOrRoll[i];
            next = frame + 1;
            D_80106F8C_16FECC_ShockDropOrRoll[i] = next;
            tex = D_80107138_170078_ShockDropOrRoll[frame];
            if (next >= 24) {
                D_80106F8C_16FECC_ShockDropOrRoll[i] = 0;
            }
            func_8003E52C_3F12C(D_801072CC_17020C_ShockDropOrRoll[i], tex);
            func_8002979C_2A39C(obj->model[i + 13], D_80106F7C_16FEBC_ShockDropOrRoll[i], 0.0f, 0.0f);
            D_80106F7C_16FEBC_ShockDropOrRoll[i] += 43.0f;
        }
    } else {
        for (i = 0; i < 4; i++) {
            func_800298A4_2A4A4(obj->model[i + 13], 4, 4);
        }
    }
}

/* The stage dressing: model[1-4] the pylons (0x240008), model[5-12] the wires (0x240007), model[13-16]
   the fans with their spark texture animation (0x240009), model[17-19] the player markers
   (0x24000A, hidden, texture animation D_801072B1). */
void func_80106790_16F6D0_ShockDropOrRoll(omObjData* obj) {
    void* data;
    s16 i;

    obj->model[0] = -1;
    obj->model[1] = LoadFormFile(0x240008, 0x6A9);
    obj->model[2] = func_80027D3C_2893C(obj->model[1]);
    obj->model[3] = func_80027D3C_2893C(obj->model[1]);
    obj->model[4] = func_80027D3C_2893C(obj->model[1]);
    obj->model[5] = LoadFormFile(0x240007, 0x6A9);
    obj->model[6] = func_80027D3C_2893C(obj->model[5]);
    obj->model[7] = func_80027D3C_2893C(obj->model[5]);
    obj->model[8] = func_80027D3C_2893C(obj->model[5]);
    obj->model[9] = func_80027D3C_2893C(obj->model[5]);
    obj->model[10] = func_80027D3C_2893C(obj->model[5]);
    obj->model[11] = func_80027D3C_2893C(obj->model[5]);
    obj->model[12] = func_80027D3C_2893C(obj->model[5]);
    obj->model[13] = LoadFormFile(0x240009, 0x6A9);
    obj->model[14] = func_80027D3C_2893C(obj->model[13]);
    obj->model[15] = func_80027D3C_2893C(obj->model[13]);
    obj->model[16] = func_80027D3C_2893C(obj->model[13]);
    obj->model[17] = LoadFormFile(0x24000A, 0x6A9);
    obj->model[18] = func_80027D3C_2893C(obj->model[17]);
    obj->model[19] = func_80027D3C_2893C(obj->model[17]);
    func_800298A4_2A4A4(obj->model[17], 4, 4);
    func_800298A4_2A4A4(obj->model[18], 4, 4);
    func_800298A4_2A4A4(obj->model[19], 4, 4);
    data = DataRead(0x24000B);
    D_801072CC_17020C_ShockDropOrRoll[0] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[13]].hmf, data, 0, (char*)D_80107228_170168_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x24000B);
    D_801072CC_17020C_ShockDropOrRoll[1] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[14]].hmf, data, 0, (char*)D_80107228_170168_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x24000B);
    D_801072CC_17020C_ShockDropOrRoll[2] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[15]].hmf, data, 0, (char*)D_80107228_170168_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x24000B);
    D_801072CC_17020C_ShockDropOrRoll[3] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[16]].hmf, data, 0, (char*)D_80107228_170168_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    func_8003E4F4_3F0F4(D_801072CC_17020C_ShockDropOrRoll[0], 1, 0);
    func_8003E4F4_3F0F4(D_801072CC_17020C_ShockDropOrRoll[1], 1, 0);
    func_8003E4F4_3F0F4(D_801072CC_17020C_ShockDropOrRoll[2], 1, 0);
    func_8003E4F4_3F0F4(D_801072CC_17020C_ShockDropOrRoll[3], 1, 0);
    func_8003E560_3F160(D_801072CC_17020C_ShockDropOrRoll[0], 0);
    func_8003E560_3F160(D_801072CC_17020C_ShockDropOrRoll[1], 1);
    func_8003E560_3F160(D_801072CC_17020C_ShockDropOrRoll[2], 2);
    func_8003E560_3F160(D_801072CC_17020C_ShockDropOrRoll[3], 3);
    func_80029A8C_2A68C(obj->model[13]);
    func_80029AFC_2A6FC(obj->model[13]);
    data = DataRead(0x24000C);
    D_801072B1_1701F1_ShockDropOrRoll[0] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[17]].hmf, data, 0, (char*)D_80107238_170178_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x24000C);
    D_801072B1_1701F1_ShockDropOrRoll[1] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[18]].hmf, data, 0, (char*)D_80107238_170178_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x24000C);
    D_801072B1_1701F1_ShockDropOrRoll[2] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[19]].hmf, data, 0, (char*)D_80107238_170178_ShockDropOrRoll);
    HuMemMemoryFreePerm(data);
    func_8003E4F4_3F0F4(D_801072B1_1701F1_ShockDropOrRoll[0], 1, 0);
    func_8003E4F4_3F0F4(D_801072B1_1701F1_ShockDropOrRoll[1], 1, 0);
    func_8003E4F4_3F0F4(D_801072B1_1701F1_ShockDropOrRoll[2], 1, 0);
    func_80029A8C_2A68C(obj->model[17]);
    func_80029AFC_2A6FC(obj->model[17]);
    for (i = 0; i < 4; i++) {
        func_80029714_2A314(obj->model[i + 1], D_80107198_1700D8_ShockDropOrRoll[i].x * 5.0f,
                            D_80107198_1700D8_ShockDropOrRoll[i].y * 5.0f, D_80107198_1700D8_ShockDropOrRoll[i].z * 5.0f);
    }
    for (i = 0; i < 8; i++) {
        func_80029714_2A314(obj->model[i + 5], D_801071C8_170108_ShockDropOrRoll[i].x * 5.0f,
                            D_801071C8_170108_ShockDropOrRoll[i].y * 5.0f, D_801071C8_170108_ShockDropOrRoll[i].z * 5.0f);
    }
    for (i = 0; i < 4; i++) {
        func_80029714_2A314(obj->model[i + 13], D_80107198_1700D8_ShockDropOrRoll[i].x * 5.0f,
                            D_80107198_1700D8_ShockDropOrRoll[i].y * 5.0f, D_80107198_1700D8_ShockDropOrRoll[i].z * 5.0f);
        func_8002D1EC_2DDEC(obj->model[i + 13], 1);
        func_8002D274_2DE74(obj->model[i + 13], 0x60, 0x40, 0x40);
        func_8002D2B4_2DEB4(obj->model[i + 13], -25.0f, 116.0f, -14.0f);
    }
    obj->func_ptr = func_801065F0_16F530_ShockDropOrRoll;
}

__asm__(".section .rodata");
/* Divided by the 5.0f scale: the fans and sparks (x, y, z). */
const Vec D_80107198_1700D8_ShockDropOrRoll[4] = { { 5.0f, -30.0f, -85.0f }, { 5.0f, -30.0f, -45.0f }, { 5.0f, -30.0f, 45.0f }, { 5.0f, -30.0f, 85.0f } };

__asm__(".section .rodata");
/* The wires. */
const Vec D_801071C8_170108_ShockDropOrRoll[8] = { { 126.0f, -60.0f, 85.0f }, { 126.0f, -60.0f, 45.0f }, { 126.0f, -60.0f, -45.0f }, { 126.0f, -60.0f, -85.0f }, { -115.0f, -60.0f, 85.0f }, { -115.0f, -60.0f, 45.0f }, { -115.0f, -60.0f, -45.0f }, { -115.0f, -60.0f, -85.0f } };

__asm__(".section .rodata");
const char D_80107228_170168_ShockDropOrRoll[] = "122_denryu1_DEF";

__asm__(".section .rodata");
const char D_80107238_170178_ShockDropOrRoll[24] = "122_denryu2_DEF";
