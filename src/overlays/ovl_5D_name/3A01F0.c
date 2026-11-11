#include "ovl_5D.h"

/* the category messages, in .rodata below */
extern const char D_8010B62C_3A901C_name_5D[];
extern const char D_8010B63C_3A902C_name_5D[];
extern const char D_8010B64C_3A903C_name_5D[];
extern const char D_8010B65C_3A904C_name_5D[];
extern const char D_8010B66C_3A905C_name_5D[];
extern const char D_8010B67C_3A906C_name_5D[];
extern const char D_8010B68C_3A907C_name_5D[];
extern const char D_8010B69C_3A908C_name_5D[];
extern const char D_8010B6AC_3A909C_name_5D[];
extern const char D_8010B6BC_3A90AC_name_5D[];
extern const char D_8010B6CC_3A90BC_name_5D[];
extern const char D_8010B6DC_3A90CC_name_5D[];
extern const char D_8010B6EC_3A90DC_name_5D[];
extern const char D_8010B6FC_3A90EC_name_5D[];
extern const char D_8010B70C_3A90FC_name_5D[];
extern const char D_8010B71C_3A910C_name_5D[];
extern const char D_8010B72C_3A911C_name_5D[];
extern const char D_8010B73C_3A912C_name_5D[];
extern const char D_8010B74C_3A913C_name_5D[];
extern const char D_8010B75C_3A914C_name_5D[];
extern const char D_8010B76C_3A915C_name_5D[];
extern const char D_8010B77C_3A916C_name_5D[];
extern const char D_8010B78C_3A917C_name_5D[];
extern const char D_8010B79C_3A918C_name_5D[];
extern const char D_8010B7AC_3A919C_name_5D[];
extern const char D_8010B7BC_3A91AC_name_5D[];
extern const char D_8010B7CC_3A91BC_name_5D[];
extern const char D_8010B7DC_3A91CC_name_5D[];
extern const char D_8010B7EC_3A91DC_name_5D[];
extern const char D_8010B7FC_3A91EC_name_5D[];
extern const char D_8010B80C_3A91FC_name_5D[];
extern const char D_8010B81C_3A920C_name_5D[];
extern const char D_8010B82C_3A921C_name_5D[];
extern const char D_8010B83C_3A922C_name_5D[];
extern const char D_8010B84C_3A923C_name_5D[];
extern const char D_8010B85C_3A924C_name_5D[];
extern const char D_8010B86C_3A925C_name_5D[];
extern const char D_8010B87C_3A926C_name_5D[];
extern const char D_8010B88C_3A927C_name_5D[];
extern const char D_8010B89C_3A928C_name_5D[];
extern const char D_8010B8AC_3A929C_name_5D[];
extern const char D_8010B8BC_3A92AC_name_5D[];
extern const char D_8010B8CC_3A92BC_name_5D[];
extern const char D_8010B8DC_3A92CC_name_5D[];
extern const char D_8010B8EC_3A92DC_name_5D[];
extern const char D_8010B8FC_3A92EC_name_5D[];
extern const char D_8010B90C_3A92FC_name_5D[];
extern const char D_8010B91C_3A930C_name_5D[];
extern const char D_8010B92C_3A931C_name_5D[];
extern const char D_8010B93C_3A932C_name_5D[];
extern const char D_8010B94C_3A933C_name_5D[];
extern const char D_8010B95C_3A934C_name_5D[];
extern const char D_8010B96C_3A935C_name_5D[];
extern const char D_8010B97C_3A936C_name_5D[];
extern const char D_8010B98C_3A937C_name_5D[];
extern const char D_8010B99C_3A938C_name_5D[];
extern const char D_8010B9AC_3A939C_name_5D[];
extern const char D_8010B9BC_3A93AC_name_5D[];
extern const char D_8010B9CC_3A93BC_name_5D[];
extern const char D_8010B9DC_3A93CC_name_5D[];
extern const char D_8010B9EC_3A93DC_name_5D[];
extern const char D_8010B9FC_3A93EC_name_5D[];
extern const char D_8010BA0C_3A93FC_name_5D[];
extern const char D_8010BA1C_3A940C_name_5D[];

/* .data (0x3A87C0-0x3A9000, 8010ADD0-8010B610) */
/* 8010ADD0 size 0xC */ s16 D_8010ADD0_3A87C0_name_5D[6] = {
    1, 2, 3, 4, 0, 0,
};
Ovl5DCamView D_8010ADDC_3A87CC_name_5D[31] = {
    { { 330.0f, 0.0f, 0.0f }, { 0.0f, 37.0f, -18.300001f }, 4097.0f },
    { { 330.0f, 0.0f, 0.0f }, { 0.0f, 37.0f, -18.300001f }, 5027.0f },
    { { 360.0f, 352.0f, 0.0f }, { 0.0f, 1285.0f, -268.0f }, 5817.0f },
    { { 373.0f, 0.0f, 0.0f }, { -444.0f, 28.0f, 65.0f }, 70.0f },
    { { 355.0f, 356.0f, 0.0f }, { -16.0f, 158.0f, 338.0f }, 1260.0f },
    { { 19.0f, 330.0f, 0.0f }, { 54.0f, 150.0f, 68.0f }, 710.0f },
    { { 351.0f, 0.0f, 0.0f }, { -3.0f, 121.0f, 74.0f }, 150.0f },
    { { 348.0f, 90.0f, 0.0f }, { 0.0f, 109.0f, 0.0f }, 375.0f },
    { { 354.0f, 56.0f, 0.0f }, { -15.0f, 91.0f, 33.0f }, 375.0f },
    { { 0.0f, 176.0f, 0.0f }, { -15.0f, 91.0f, 33.0f }, 375.0f },
    { { 2.0f, 286.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 216.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 144.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 72.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 2.0f, 0.0f, 0.0f }, { -3.0f, 188.0f, -5.0f }, 295.0f },
    { { 68.0f, 0.0f, 0.0f }, { -13.0f, 283.0f, 72.0f }, 385.0f },
    { { 2.0f, 262.0f, 0.0f }, { -9.0f, 182.0f, -121.0f }, 85.0f },
    { { 4.0f, 194.0f, 0.0f }, { 107.0f, 169.0f, 35.0f }, 155.0f },
    { { 2.0f, 122.0f, 0.0f }, { 117.0f, 174.0f, 66.0f }, 25.0f },
    { { 2.0f, 48.0f, 0.0f }, { -203.0f, 184.0f, -38.0f }, 265.0f },
    { { 2.0f, 334.0f, 0.0f }, { -150.0f, 184.0f, -40.0f }, 45.0f },
    { { 350.0f, 286.0f, 0.0f }, { 5.0f, 235.0f, -7.0f }, 35.0f },
    { { 350.0f, 286.0f, 0.0f }, { 352.0f, 90.0f, -115.0f }, 5.0f },
    { { 350.0f, 216.0f, 0.0f }, { 0.0f, 213.0f, -1.0f }, 15.0f },
    { { 350.0f, 216.0f, 0.0f }, { 268.0f, 65.0f, 367.0f }, 65.0f },
    { { 350.0f, 144.0f, 0.0f }, { -9.0f, 243.0f, 3.0f }, 35.0f },
    { { 350.0f, 144.0f, 0.0f }, { -213.6f, 80.0f, 294.0f }, 10.0f },
    { { 350.0f, 70.0f, 0.0f }, { -9.0f, 243.0f, 3.0f }, 35.0f },
    { { 350.0f, 70.0f, 0.0f }, { -439.0f, 71.0f, -147.0f }, 95.0f },
    { { 350.0f, 0.0f, 0.0f }, { 5.0f, 242.0f, -22.0f }, 55.0f },
    { { 350.0f, 0.0f, 0.0f }, { -1.0f, 75.0f, -443.0f }, 75.0f },
};
/* 8010B140 size 0x1B8 */ Ovl5DModelDef D_8010B140_3A8B30_name_5D[11] = {
    { 590031, 1585, 0, 0, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590026, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590027, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590029, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590028, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590030, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590032, 1585, 0, 2, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590033, 1585, 0, 2, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 590034, 1585, 0, 1, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 13, 1585, 0, 0, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { -1, 0, 0, 0, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};
u8 D_8010B2F8_3A8CE8_name_5D[8] = { 5, 1, 2, 4, 3, 0, 0, 0 };
Ovl5DCatMess D_8010B300_3A8CF0_name_5D[5] = {
    { 874, 875, 876, 890, 891, 892 }, { 877, 878, 879, 893, 894, 895 },
    { 880, 881, 882, 896, 897, 898 }, { 886, 887, 888, 902, 903, 904 },
    { 883, 884, 885, 899, 900, 901 },
};
/* 8010B378 size 0xC */ s16 D_8010B378_3A8D68_name_5D[6] = {
    1, 2, 4, 3, 5, 0,
};
char* D_8010B384_3A8D74_name_5D[23] = {
    (char*)D_8010B78C_3A917C_name_5D,
    (char*)D_8010B77C_3A916C_name_5D,
    (char*)D_8010B76C_3A915C_name_5D,
    (char*)D_8010B75C_3A914C_name_5D,
    (char*)D_8010B74C_3A913C_name_5D,
    (char*)D_8010B73C_3A912C_name_5D,
    (char*)D_8010B72C_3A911C_name_5D,
    (char*)D_8010B71C_3A910C_name_5D,
    (char*)D_8010B70C_3A90FC_name_5D,
    (char*)D_8010B6FC_3A90EC_name_5D,
    (char*)D_8010B6EC_3A90DC_name_5D,
    (char*)D_8010B6DC_3A90CC_name_5D,
    (char*)D_8010B6CC_3A90BC_name_5D,
    (char*)D_8010B6BC_3A90AC_name_5D,
    (char*)D_8010B6AC_3A909C_name_5D,
    (char*)D_8010B69C_3A908C_name_5D,
    (char*)D_8010B68C_3A907C_name_5D,
    (char*)D_8010B67C_3A906C_name_5D,
    (char*)D_8010B66C_3A905C_name_5D,
    (char*)D_8010B65C_3A904C_name_5D,
    (char*)D_8010B64C_3A903C_name_5D,
    (char*)D_8010B63C_3A902C_name_5D,
    (char*)D_8010B62C_3A901C_name_5D,
};
char* D_8010B3E0_3A8DD0_name_5D[12] = {
    (char*)D_8010B84C_3A923C_name_5D,
    (char*)D_8010B83C_3A922C_name_5D,
    (char*)D_8010B82C_3A921C_name_5D,
    (char*)D_8010B81C_3A920C_name_5D,
    (char*)D_8010B80C_3A91FC_name_5D,
    (char*)D_8010B7FC_3A91EC_name_5D,
    (char*)D_8010B7EC_3A91DC_name_5D,
    (char*)D_8010B7DC_3A91CC_name_5D,
    (char*)D_8010B7CC_3A91BC_name_5D,
    (char*)D_8010B7BC_3A91AC_name_5D,
    (char*)D_8010B7AC_3A919C_name_5D,
    (char*)D_8010B79C_3A918C_name_5D,
};
char* D_8010B410_3A8E00_name_5D[14] = {
    (char*)D_8010B92C_3A931C_name_5D,
    (char*)D_8010B91C_3A930C_name_5D,
    (char*)D_8010B90C_3A92FC_name_5D,
    (char*)D_8010B8FC_3A92EC_name_5D,
    (char*)D_8010B8EC_3A92DC_name_5D,
    (char*)D_8010B8DC_3A92CC_name_5D,
    (char*)D_8010B8CC_3A92BC_name_5D,
    (char*)D_8010B8BC_3A92AC_name_5D,
    (char*)D_8010B8AC_3A929C_name_5D,
    (char*)D_8010B89C_3A928C_name_5D,
    (char*)D_8010B88C_3A927C_name_5D,
    (char*)D_8010B87C_3A926C_name_5D,
    (char*)D_8010B86C_3A925C_name_5D,
    (char*)D_8010B85C_3A924C_name_5D,
};
char* D_8010B448_3A8E38_name_5D[9] = {
    (char*)D_8010B9BC_3A93AC_name_5D,
    (char*)D_8010B9AC_3A939C_name_5D,
    (char*)D_8010B99C_3A938C_name_5D,
    (char*)D_8010B98C_3A937C_name_5D,
    (char*)D_8010B97C_3A936C_name_5D,
    (char*)D_8010B96C_3A935C_name_5D,
    (char*)D_8010B95C_3A934C_name_5D,
    (char*)D_8010B94C_3A933C_name_5D,
    (char*)D_8010B93C_3A932C_name_5D,
};
char* D_8010B46C_3A8E5C_name_5D[6] = {
    (char*)D_8010BA1C_3A940C_name_5D,
    (char*)D_8010BA0C_3A93FC_name_5D,
    (char*)D_8010B9FC_3A93EC_name_5D,
    (char*)D_8010B9EC_3A93DC_name_5D,
    (char*)D_8010B9DC_3A93CC_name_5D,
    (char*)D_8010B9CC_3A93BC_name_5D,
};
char** D_8010B484_3A8E74_name_5D[5] = { D_8010B384_3A8D74_name_5D, D_8010B3E0_3A8DD0_name_5D, D_8010B410_3A8E00_name_5D, D_8010B448_3A8E38_name_5D, D_8010B46C_3A8E5C_name_5D };
/* 8010B498 size 0xC */ s16 D_8010B498_3A8E88_name_5D[6] = {
    0, 1, 2, 4, 3, 0,
};
Ovl5DSprDef D_8010B4A4_3A8E94_name_5D[10] = {
    { 589842, 10.0f, 147.0f, 1.0f, 1.0f }, { 589841, 25.0f, 130.0f, 0.8f, 0.8f },
    { 589841, 30.0f, 107.0f, 1.0f, 1.0f }, { 589840, 56.0f, 87.0f, 0.8f, 0.8f },
    { 589840, 38.0f, 88.0f, 1.0f, 1.0f }, { 589840, 30.0f, 68.0f, 1.0f, 1.0f },
    { 589843, 59.0f, 60.0f, 0.8f, 0.8f }, { 589843, 72.0f, 77.0f, 1.1f, 1.1f },
    { 589854, 53.0f, 76.0f, 0.45f, 0.45f }, { 0, -1.0f, -1.0f, -1.0f, -1.0f },
};
/* 8010B56C size 0xC */ s16 D_8010B56C_3A8F5C_name_5D[6] = {
    0, -50, 0, 25, 50, -25,
};
/* 8010B578 size 0xC */ s16 D_8010B578_3A8F68_name_5D[6] = {
    -72, -20, 24, 68, 0, 0,
};
/* 8010B584 size 0xC */ s16 D_8010B584_3A8F74_name_5D[6] = {
    0, -50, -25, 25, 50, 0,
};
/* 8010B590 size 0xC */ s16 D_8010B590_3A8F80_name_5D[6] = {
    -70, -26, 26, 70, 0, 0,
};
s16 D_8010B59C_3A8F8C_name_5D[4][4] = { { 0, 1, 2, 3 }, { 1, 0, 2, 3 }, { 2, 0, 1, 3 }, { 3, 0, 1, 2 } };
s16 D_8010B5BC_3A8FAC_name_5D[4][4] = { { 0, 1, 2, 3 }, { 0, 2, 1, 3 }, { 0, 3, 1, 2 }, { 0, 1, 2, 3 } };
s32 D_8010B5DC_3A8FCC_name_5D[6] = {
    590052, 590047, 590048, 590049, 590050, 590051,
};
/* 8010B5F4 size 0x1C */ s32 D_8010B5F4_3A8FE4_name_5D[7] = {
    589972, 589973, 589974, 589975, 589976, 589977, 0,
};

void func_80102800_3A01F0_name_5D(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0x19);
    func_80088640_89240();
    func_80079128_79D28();
    omAddObj(0x2710, 0, 0, -1, func_80107F70_3A5960_name_5D);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 100, 100, 100);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    D_8010CDBC_3AA7AC_name_5D = 8000.0f;
    PlayMusic(0x34);
    D_8010B610_3A9000_name_5D = 49.0f;
    D_8010CDD4_3AA7C4_name_5D = 80.0f;
    omAddPrcObj(func_801029EC_3A03DC_name_5D, 0x3F00, 0x1800, 0);
    Hu3DCamSetPerspective(0, D_8010B610_3A9000_name_5D, D_8010CDD4_3AA7C4_name_5D, D_8010CDBC_3AA7AC_name_5D);
    omPrcSetStatBit(omAddPrcObj(func_80109B68_3A7558_name_5D, 0x1100, 0x800, 0), 0xA0);
    InitFadeIn(0, 0x10);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
    func_8002C59C_2D19C(0x3DE, 0x3E8, 0xFF, 0xFF, 0xFF);
    D_8010CCE8_3AA6D8_name_5D = D_8010ADDC_3A87CC_name_5D;
    _ClearFlag(0xC);
    _ClearFlag(0xE);
    D_8010BA70_3A9460_name_5D = D_800FD80C_FE40C;
    D_8010CDF4_3AA7E4_name_5D = 0;
    D_8010CE28_3AA818_name_5D = 0x73;
    D_8010CDB8_3AA7A8_name_5D = 0;
    D_800CAFEE = -1;
}

// control flow: retail lays the B-button block out after the A block, frame 8 bytes smaller (masked 62)
#ifdef NON_MATCHING
void func_801029EC_3A03DC_name_5D(void) {
    s16 size[4];
    s16 order[5];
    s16 sel;
    s16 n;
    s16 i;
    s16 old;

    sel = 0;
    func_8010A13C_3A7B2C_name_5D(D_8010B140_3A8B30_name_5D);
    func_8010A2FC_3A7CEC_name_5D(D_8010B140_3A8B30_name_5D, 0);
    if (_CheckFlag(0x10) == 0) {
        func_800298A4_2A4A4(D_8010CCD0_3AA6C0_name_5D[D_8010B2FC_3A8CEC_name_5D], 4, 4);
    }
    if (_CheckFlag(0x11) == 0) {
        func_800298A4_2A4A4(D_8010CCD0_3AA6C0_name_5D[D_8010B2FB_3A8CEB_name_5D], 4, 4);
    }
    func_8002CA48_2D648(0xC0, 0xFF, 0xFF);
    func_8010543C_3A2E2C_name_5D();
    omAddPrcObj(func_80109104_3A6AF4_name_5D, 0x3F00, 0x800, 0);
    func_80109520_3A6F10_name_5D(D_8010BA78_3A9468_name_5D);
    omAddPrcObj(func_801034C0_3A0EB0_name_5D, 0x3F00, 0x800, 0);
    func_8002A00C_2AC0C(D_8010CCD0_3AA6C0_name_5D[0]);
    omAddPrcObj(func_801049A8_3A2398_name_5D, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80106CC4_3A46B4_name_5D, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80106468_3A3E58_name_5D, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80106238_3A3C28_name_5D, 0x3F00, 0x800, 0);
    func_801077B8_3A51A8_name_5D();
    D_8010C566_3A9F56_name_5D = D_8010C568_3A9F58_name_5D = D_8010C56A_3A9F5A_name_5D = 0;
    i = D_8010C044_3A9A34_name_5D;
    if (func_80068040_68C40(0x22) != 0) {
        i--;
    }
    if (func_80068040_68C40(0x22) == 0 && D_8010C044_3A9A34_name_5D >= 0x22) {
        D_8010C566_3A9F56_name_5D = D_8010C568_3A9F58_name_5D = 1;
        func_80067F94_68B94(0x22);
    }
    if (func_80068040_68C40(0xF) == 0 && i >= 0x31) {
        D_8010C566_3A9F56_name_5D = D_8010C56A_3A9F5A_name_5D = 1;
        func_80067F94_68B94(0xF);
    }
    func_801077B8_3A51A8_name_5D();
    func_80103FF0_3A19E0_name_5D();
    for (i = 0; i < 4; i++) {
        gPlayers[i].cpu_difficulty = gPlayers[i].cpu_difficulty2;
    }
    if (D_800FFE00_100A00[0xEA] == -1) {
        func_801080C0_3A5AB0_name_5D(0xF);
        func_801082A0_3A5C90_name_5D(0xE, 0x14, 1, func_80103580_3A0F70_name_5D);
        D_8010CE16_3AA806_name_5D = 4;
        for (i = 0; i < 5; i++) {
            D_800FC9BE_FD5BE[5 + i] = 0;
        }
        for (i = 0; i < 4; i++) {
            D_800F9D48_FA948[0x2F8 + i] = i;
        }
    } else {
        func_801080C0_3A5AB0_name_5D(D_800FFE00_100A00[0xEA] + 0xA);
        D_8010CE16_3AA806_name_5D = D_800FFE00_100A00[0xEA];
        func_80104224_3A1C14_name_5D();
    }
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    if (D_8010C566_3A9F56_name_5D != 0) {
        func_80106F5C_3A494C_name_5D();
    }
    func_80107BE0_3A55D0_name_5D();
    D_8010BA78_3A9468_name_5D[0][0] = 160;
    D_8010BA78_3A9468_name_5D[0][1] = 120;
    func_8010952C_3A6F1C_name_5D(3);
    func_801094E8_3A6ED8_name_5D(0);
    n = 0;
    for (i = 0; i < 5; i++) {
        order[n] = i;
        if (i == D_8010CE16_3AA806_name_5D) {
            sel = n;
        }
        n++;
        if (D_8010ADD0_3A87C0_name_5D[i] == 4 && _CheckFlag(0x10) == 0) {
            n--;
        }
        if (D_8010ADD0_3A87C0_name_5D[i] == 3 && _CheckFlag(0x11) == 0) {
            n--;
        }
    }
    func_8008DBE0_8E7E0(size, 0x36A, 0x388);
    D_8010C562_3A9F52_name_5D = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 0xCC, size[0], size[1], 0);
    func_8008D59C_8E19C(D_8010C562_3A9F52_name_5D, 1 << D_8010BA70_3A9460_name_5D);
    func_80089284_89E84(D_8010C562_3A9F52_name_5D, 0x20, 0x20);
    func_8008E978_8F578(D_8010C562_3A9F52_name_5D);
    func_8010336C_3A0D5C_name_5D(D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]);
    D_8010CDF6_3AA7E6_name_5D = 1;
    HuPrcSleep(5);
    while (1) {
        if (ABS(ContStkX[D_8010BA70_3A9460_name_5D]) >= 0x1F) {
            PlaySound(1);
            old = sel;
            if (ContStkX[D_8010BA70_3A9460_name_5D] > 0) {
                sel++;
                sel = (sel < n) ? sel : 0;
            } else {
                if (--sel < 0) {
                    sel = n - 1;
                }
            }
            D_8010CE16_3AA806_name_5D = order[sel];
            func_8008EED8_8FAD8(D_8010C562_3A9F52_name_5D, 0);
            if (order[old] == 1 && order[sel] == 4) {
                D_8010CCE8_3AA6D8_name_5D[D_8010CE16_3AA806_name_5D + 10].rot.y -= 360.0f;
                func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D + 10, 0x14, 1, func_80103580_3A0F70_name_5D);
                D_8010CCE8_3AA6D8_name_5D[D_8010CE16_3AA806_name_5D + 10].rot.y += 360.0f;
            }
            if (order[old] == 4 && order[sel] == 1) {
                D_8010CCE8_3AA6D8_name_5D[D_8010CE16_3AA806_name_5D + 10].rot.y += 360.0f;
                func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D + 10, 0x14, 1, func_80103580_3A0F70_name_5D);
                D_8010CCE8_3AA6D8_name_5D[D_8010CE16_3AA806_name_5D + 10].rot.y -= 360.0f;
            } else {
                func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D + 10, 0xA, 1, func_80103580_3A0F70_name_5D);
            }
            func_80104224_3A1C14_name_5D();
            func_8008AD44_8B944(D_8010C562_3A9F52_name_5D);
            func_8008E978_8F578(D_8010C562_3A9F52_name_5D);
            func_8010336C_3A0D5C_name_5D(D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]);
        }
        if (ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x4000) {
            PlaySound(4);
            func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, 0x379, -1, -1);
            while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
                HuPrcVSleep();
            }
            if (func_8008BB48_8C748(D_8010C562_3A9F52_name_5D, 0, 0) == 0) {
                D_8010CDF4_3AA7E4_name_5D = 0;
                omOvlHisChg(1, 0x5C, 4, 0x11);
                D_8010CDE4_3AA7D4_name_5D = 1;
                func_8008F624_90224(0xFF, 0xFF, 0xFF);
                InitFadeOut(0, 0xA);
                while (1) {
                    HuPrcVSleep();
                }
            }
            func_8010336C_3A0D5C_name_5D(D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]);
        }
        if ((ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x8000) && D_8010C030_3A9A20_name_5D[D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]] != 0) {
            PlaySound(2);
            func_8010359C_3A0F8C_name_5D();
            func_8010336C_3A0D5C_name_5D(D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]);
        }
        func_80104224_3A1C14_name_5D();
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_801029EC_3A03DC_name_5D);
#endif

void func_8010336C_3A0D5C_name_5D(s16 cat) {
    char buf[8];

    if (D_8010C030_3A9A20_name_5D[cat] == 0) {
        func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].locked, -1, -1);
    } else {
        sprintf(buf, "%2d", D_8010C030_3A9A20_name_5D[cat]);
        if (buf[0] == '0') {
            buf[0] = 0x10;
        }
        func_80089308_89F08(D_8010C562_3A9F52_name_5D, buf, 0);
        if (D_8010C030_3A9A20_name_5D[cat] != D_8010C018_3A9A08_name_5D[cat]) {
            func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].some, -1, -1);
        } else {
            func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].all, -1, -1);
        }
    }
    while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
        HuPrcVSleep();
    }
}

void func_801034C0_3A0EB0_name_5D(void) {
    f32 ofs;

    ofs = 0.0f;
    while (1) {
        func_8002BED4_2CAD4(D_8010CCD0_3AA6C0_name_5D[0], 0.0f, -ofs, 0x20, 0x20, "extru1", 0);
        ofs += 0.3f;
        if (ofs > 32.0f) {
            ofs = 0.0f;
        }
        HuPrcVSleep();
    }
}

void func_80103580_3A0F70_name_5D(s16* arg) {
    func_80104224_3A1C14_name_5D();
}

// control flow: retail keeps sp locals where this uses registers, frame 16 bytes larger (masked 193)
#ifdef NON_MATCHING
void func_8010359C_3A0F8C_name_5D(void) {
    s16 cat;
    s16 model;
    s16 mot;
    s16 next;
    s16 ok;
    s16 i;

    cat = D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D];
    model = D_8010CCD0_3AA6C0_name_5D[D_8010B378_3A8D68_name_5D[D_8010CE16_3AA806_name_5D]];
    mot = D_8010CDC0_3AA7B0_name_5D[D_8010B378_3A8D68_name_5D[D_8010CE16_3AA806_name_5D]];
    D_8010CDF6_3AA7E6_name_5D = 0;
    func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D + 0x10, 0x14, 1, func_80103580_3A0F70_name_5D);
    for (i = 0; i < 0x10; i++) {
        func_801045F0_3A1FE0_name_5D(cat, i);
        HuPrcVSleep();
    }
    func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].chosen, -1, -1);
    while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
        HuPrcVSleep();
    }
    D_8010C56C_3A9F5C_name_5D = D_800FC9BE_FD5BE[5 + cat];
    func_801094E8_3A6ED8_name_5D(D_8010C56C_3A9F5C_name_5D);
    D_8010CDF6_3AA7E6_name_5D = 1;
    D_8010C564_3A9F54_name_5D = 0;
    HuPrcSleep(5);
    func_8008D904_8E504(D_8010C562_3A9F52_name_5D, D_8010C050_3A9A40_name_5D[cat][D_8010C56C_3A9F5C_name_5D] + 0x3D9, 0);
    func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].pick, -1, -1);
    while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
        HuPrcVSleep();
    }
    while (1) {
        if (ABS(ContStkX[D_8010BA70_3A9460_name_5D]) >= 0x1F || ABS(ContStkY[D_8010BA70_3A9460_name_5D]) >= 0x1F) {
            next = func_80107C20_3A5610_name_5D(D_8010C56C_3A9F5C_name_5D, D_8010C030_3A9A20_name_5D[cat], -ContStkX[D_8010BA70_3A9460_name_5D], ContStkY[D_8010BA70_3A9460_name_5D]);
            if (next != -1) {
                PlaySound(1);
                func_80109538_3A6F28_name_5D(next);
                HuPrcSleep(6);
                D_8010C56C_3A9F5C_name_5D = next;
                func_8008D904_8E504(D_8010C562_3A9F52_name_5D, D_8010C050_3A9A40_name_5D[cat][next] + 0x3D9, 0);
                func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].pick, -1, -1);
                while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
                    HuPrcVSleep();
                }
            }
        }
        if (ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x4000) {
            PlaySound(4);
            break;
        }
        if (ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x8000) {
            PlaySound(2);
            D_800FC9BE_FD5BE[5 + cat] = D_8010C56C_3A9F5C_name_5D;
            ok = 1;
            if (cat == 1 || cat == 2) {
                ok = func_80105648_3A3038_name_5D();
            }
            if (ok != 0) {
                func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].confirm, -1, -1);
                while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
                    HuPrcVSleep();
                }
                if (func_8008BB48_8C748(D_8010C562_3A9F52_name_5D, 0, 0) == 0) {
                    func_8008EED8_8FAD8(D_8010C562_3A9F52_name_5D, 0);
                    D_8010CDF6_3AA7E6_name_5D = 0;
                    D_8010C564_3A9F54_name_5D = 1;
                    func_8010608C_3A3A7C_name_5D();
                    for (i = 0xF; i >= 0; i--) {
                        func_801045F0_3A1FE0_name_5D(cat, i);
                        HuPrcVSleep();
                    }
                    func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D * 2 + 0x15, 0x14, 0, func_80103580_3A0F70_name_5D);
                    func_80029E80_2AA80(model, 1, 0);
                    func_8002C9C0_2D5C0(model, mot);
                    while (func_80029CE4_2A8E4(model) < 15.0f) {
                        HuPrcVSleep();
                    }
                    func_80029E80_2AA80(model, 1, 1);
                    if (cat != 4) {
                        for (i = 0; i < 4; i++) {
                            if (!(gPlayers[i].flags & 1)) {
                                omVibrate(i, 2, 2, 0x14);
                            }
                        }
                    } else {
                        omVibrate(0, 2, 2, 0x14);
                    }
                    func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D * 2 + 0x16, 0x14, 1, func_80103580_3A0F70_name_5D);
                    func_80103E58_3A1848_name_5D(cat);
                    GwSystem.unk_25 = 0;
                    GwSystem.chosenMinigameIndex = D_8010C050_3A9A40_name_5D[cat][D_8010C56C_3A9F5C_name_5D] + 1;
                    D_800FFE00_100A00[0xEA] = D_8010CE16_3AA806_name_5D;
                    D_8010CDF4_3AA7E4_name_5D = 2;
                    D_8010CE28_3AA818_name_5D = 0x5E;
                    if (GwSystem.chosenMinigameIndex == 0x1A || GwSystem.chosenMinigameIndex == 0x12
                        || (D_800CAD90[GwSystem.chosenMinigameIndex - 1].unk_06 >> 15) != 0) {
                        D_8010CDB8_3AA7A8_name_5D = 0;
                    } else {
                        D_8010CDB8_3AA7A8_name_5D = 1;
                    }
                    omOvlHisChg(0, 0x5D, 5, 0x11);
                    D_8010CDE4_3AA7D4_name_5D = 1;
                    InitFadeOut(0, 0xA);
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                func_8010608C_3A3A7C_name_5D();
            }
            func_8008D904_8E504(D_8010C562_3A9F52_name_5D, D_8010C050_3A9A40_name_5D[cat][D_8010C56C_3A9F5C_name_5D] + 0x3D9, 0);
            func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, D_8010B300_3A8CF0_name_5D[cat].pick, -1, -1);
        }
        HuPrcVSleep();
    }
    D_8010CDF6_3AA7E6_name_5D = 0;
    for (i = 0xF; i >= 0; i--) {
        func_801045F0_3A1FE0_name_5D(cat, i);
        HuPrcVSleep();
    }
    D_8010C564_3A9F54_name_5D = 1;
    func_801082A0_3A5C90_name_5D(D_8010CE16_3AA806_name_5D + 0xA, 0xA, 1, func_80103580_3A0F70_name_5D);
    D_8010BA78_3A9468_name_5D[0][0] = 160;
    D_8010BA78_3A9468_name_5D[0][1] = 120;
    func_801094E8_3A6ED8_name_5D(0);
    D_8010CDF6_3AA7E6_name_5D = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_8010359C_3A0F8C_name_5D);
#endif

// control flow/width (masked 7, 114 of 116): retail keeps an andi 0xff after each rand8() & 3 (in the
// second call's delay slot); u8 j/k indices took it from masked 9, (u8)(rand8() % 4) did nothing.
#ifdef NON_MATCHING
void func_80103E58_3A1848_name_5D(s16 cat) {
    s16 teams[4]; /* never filled: retail's categories stop at 4, so this path never runs */
    s16 i;
    u8 j;
    u8 k;
    s16 tmp;

    D_800F9208_F9E08 = 0;
    if (cat != 1 && cat != 2) {
        if (cat == 0 || cat == 3) {
            for (i = 0; i < 4; i++) {
                gPlayers[i].group = 0;
            }
            return;
        }
        if (cat == 4) {
            GwSystem.current_player_index = 0;
            gPlayers[0].group = 0;
            gPlayers[1].group = gPlayers[2].group = gPlayers[3].group = 1;
            return;
        }
        for (i = 0; i < 20; i++) {
            j = rand8() & 3;
            k = rand8() & 3;
            tmp = teams[j];
            teams[j] = teams[k];
            teams[k] = tmp;
        }
        for (i = 0; i < 4; i++) {
            gPlayers[i].group = teams[i];
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80103E58_3A1848_name_5D);
#endif

void func_80103FF0_3A19E0_name_5D(void) {
    f32 mtx[4][4];
    Vec2f scr;
    s16 model;
    s16 cat;
    s16 i;

    D_8010C56E_3A9F5E_name_5D = func_8001A2F8_1AEF8(0x900C4);
    for (cat = 0; cat < 5; cat++) {
        model = D_8010CCD0_3AA6C0_name_5D[D_8010B2F8_3A8CE8_name_5D[cat]];
        for (i = 0; i < D_8010C018_3A9A08_name_5D[cat]; i++) {
            D_8010C570_3A9F60_name_5D[cat][i] = func_8001AAAC_1B6AC(D_8010C56E_3A9F5E_name_5D, D_8010B498_3A8E88_name_5D[cat], 1);
            func_80023554_24154(model, 0, D_8010B484_3A8E74_name_5D[cat][i], mtx);
            func_8010A3E4_3A7DD4_name_5D(D_8010CCD0_3AA6C0_name_5D[D_8010B2F8_3A8CE8_name_5D[cat]], &D_8010C670_3AA060_name_5D[cat][i], mtx);
            func_8010A524_3A7F14_name_5D(0, &D_8010C670_3AA060_name_5D[cat][i], &scr);
            espPosSet(D_8010C570_3A9F60_name_5D[cat][i], scr.unk_00, scr.unk_04);
        }
    }
}

// register allocation (masked 37)
#ifdef NON_MATCHING
void func_80104224_3A1C14_name_5D(void) {
    Vec2f scr;
    s32 hide;
    s16 row;
    s16 cat;
    s16 i;
    s16* counts;

    row = D_8010CE16_3AA806_name_5D + 2;
    if (row >= 5) {
        row = D_8010CE16_3AA806_name_5D - 2;
    }
    hide = D_8010ADD0_3A87C0_name_5D[row];
    counts = D_8010C018_3A9A08_name_5D;
    for (cat = 0; cat < 5; cat++) {
        if (cat == hide) {
            for (i = 0; i < D_8010C018_3A9A08_name_5D[cat]; i++) {
                espDispOff(D_8010C570_3A9F60_name_5D[cat][i]);
            }
        } else if (cat == 4 && _CheckFlag(0x10) == 0) {
            for (i = 0; i < counts[4]; i++) {
                espDispOff(D_8010C570_3A9F60_name_5D[cat][i]);
            }
        } else if (cat == 3 && _CheckFlag(0x11) == 0) {
            for (i = 0; i < counts[3]; i++) {
                espDispOff(D_8010C570_3A9F60_name_5D[cat][i]);
            }
        } else {
            for (i = 0; i < D_8010C018_3A9A08_name_5D[cat]; i++) {
                if (i < D_8010C030_3A9A20_name_5D[cat]) {
                    espDispOn(D_8010C570_3A9F60_name_5D[cat][i]);
                    func_8010A524_3A7F14_name_5D(0, &D_8010C670_3AA060_name_5D[cat][i], &scr);
                    espPosSet(D_8010C570_3A9F60_name_5D[cat][i], scr.unk_00, scr.unk_04);
                } else {
                    espDispOff(D_8010C570_3A9F60_name_5D[cat][i]);
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80104224_3A1C14_name_5D);
#endif

void func_801045F0_3A1FE0_name_5D(s16 cat, s16 t) {
    f32 base[2];
    f32 s;
    f32 a;
    f32 b;
    f32 x;
    f32 y;
    f32 ft;
    s16 i;

    if (t == 0) {
        for (i = 0; i < D_8010C018_3A9A08_name_5D[cat]; i++) {
            D_8010CCF0_3AA6E0_name_5D[i][0] = D_800F93FC_F9FFC[D_8010C570_3A9F60_name_5D[cat][i]].x;
            D_8010CCF0_3AA6E0_name_5D[i][1] = D_800F93FC_F9FFC[D_8010C570_3A9F60_name_5D[cat][i]].y;
        }
    }
    ft = t;
    s = HuMathSin(ft * 6.0f);
    a = HuMathSin(ft * 12.0f) * 40.0f;
    b = HuMathSin(ft * 12.0f + 180.0f) * 20.0f;
    base[0] = 40.0f;
    base[1] = 24.0f;
    for (i = 0; i < D_8010C018_3A9A08_name_5D[cat]; i++) {
        x = D_8010CCF0_3AA6E0_name_5D[i][0] + (((s16)(i % 5) * 30 + base[0]) - D_8010CCF0_3AA6E0_name_5D[i][0]) * s;
        y = (((s16)(i / 5) * 30 + base[1]) - D_8010CCF0_3AA6E0_name_5D[i][1]) * s + D_8010CCF0_3AA6E0_name_5D[i][1];
        if (D_8010C018_3A9A08_name_5D[cat] == D_8010C030_3A9A20_name_5D[cat]) {
            if (i & 1) {
                x += a;
                y += a;
            } else {
                x += b;
                y += b;
            }
        }
        espPosSet(D_8010C570_3A9F60_name_5D[cat][i], x, y);
        func_80107B8C_3A557C_name_5D(i, D_8010C570_3A9F60_name_5D[cat][i], 0, 0x10);
    }
}

// frame and register allocation: retail keeps counters on the stack; twin of 5B 80106D2C (masked 37)
#ifdef NON_MATCHING
void func_801049A8_3A2398_name_5D(void) {
    s16 grp[16];
    s16 spr[16];
    s16 phase[16];
    f32 pos[16][2];
    f32 scale[16][2];
    Ovl5DSprDef* def;
    f32 sx;
    f32 sy;
    f32 a;
    s16 count;
    s16 prevCat;
    s16 prevSel;
    s16 state;
    s16 i;
    s16 j;
    s16 k;

    count = 0;
    prevCat = -1;
    D_8010C564_3A9F54_name_5D = -1;
    state = -1;
    prevSel = -1;
    while (1) {
        HuPrcVSleep();
        switch (D_8010C564_3A9F54_name_5D) {
        case 0:
            if (state == -1) {
                prevCat = D_8010CE16_3AA806_name_5D;
                for (i = 0, def = D_8010B4A4_3A8E94_name_5D; def->file != 0; i++, def = &D_8010B4A4_3A8E94_name_5D[i]) {
                    if (i == 8) {
                        spr[8] = func_8010AAE4_3A84D4_name_5D();
                        func_8010ABDC_3A85CC_name_5D(D_800CAD90[D_8010C050_3A9A40_name_5D[D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]][D_8010C56C_3A9F5C_name_5D]].unk_06 & 0xFFF);
                    } else {
                        grp[i] = func_8001A2F8_1AEF8(def->file);
                        spr[i] = func_8001AAAC_1B6AC(grp[i], 0, 1);
                    }
                    func_8001A6BC_1B2BC(spr[i], 0x100);
                    espDispOff(spr[i]);
                    pos[i][0] = def->x + 176.0f;
                    pos[i][1] = def->y - 16.0f;
                    scale[i][0] = def->sx;
                    scale[i][1] = def->sy;
                    func_8001A91C_1B51C(spr[i], scale[i][0], scale[i][1]);
                    espPosSet(spr[i], pos[i][0], pos[i][1]);
                    func_8001A96C_1B56C(spr[i], 0xFF, 0xFF, 0xFF);
                    phase[i] = i * 95;
                }
                count = i;
                for (i = 0; i < 3; i++) {
                    def = &D_8010B4A4_3A8E94_name_5D[i];
                    espDispOn(spr[i]);
                    sx = def->sx;
                    sy = def->sy;
                    for (j = 0; j < 3; j++) {
                        scale[i][0] = sx * HuMathSin(j * 45.0f);
                        scale[i][1] = sy * HuMathSin(j * 45.0f);
                        func_8001A91C_1B51C(spr[i], scale[i][0], scale[i][1]);
                        for (k = 0; k < i; k++) {
                            espPosSet(spr[k], pos[k][0] + HuMathSin(phase[k]) * 2.0f,
                                      func_800B7890_B8490(phase[k] * 2) * 2.0f + pos[k][1]);
                            phase[k] += 10;
                            if (phase[k] > 360) {
                                phase[k] -= 360;
                            }
                        }
                        HuPrcVSleep();
                    }
                }
                for (j = 0; j < 6; j++) {
                    for (i = 3; i < count; i++) {
                        def = &D_8010B4A4_3A8E94_name_5D[i];
                        espDispOn(spr[i]);
                        a = j;
                        a *= 18.0f;
                        scale[i][0] = HuMathSin(a) * def->sx;
                        scale[i][1] = HuMathSin(a) * def->sy;
                        func_8001A91C_1B51C(spr[i], scale[i][0], scale[i][1]);
                    }
                    for (k = 0; k < count; k++) {
                        espPosSet(spr[k], pos[k][0] + HuMathSin(phase[k]) * 2.0f,
                                  func_800B7890_B8490(phase[k] * 2) * 2.0f + pos[k][1]);
                        phase[k] += 10;
                        if (phase[k] > 360) {
                            phase[k] -= 360;
                        }
                    }
                    HuPrcVSleep();
                }
            }
            D_8010C564_3A9F54_name_5D = 2;
            state = 2;
            break;
        case 1:
            if (state != -1) {
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < count; j++) {
                        def = &D_8010B4A4_3A8E94_name_5D[j];
                        func_8001A6BC_1B2BC(spr[j], (5 - i) * 51);
                        scale[j][0] = i * 0.2f + def->sx;
                        scale[j][1] = i * 0.2f + def->sy;
                        func_8001A91C_1B51C(spr[j], scale[j][0], scale[j][1]);
                    }
                    HuPrcVSleep();
                }
                for (j = 0; j < count; j++) {
                    if (j == 8) {
                        func_8010AD10_3A8700_name_5D();
                    } else {
                        func_8001AC44_1B844(spr[j]);
                        SprAnimKill(grp[j]);
                    }
                }
            }
            D_8010C564_3A9F54_name_5D = -1;
            state = -1;
            break;
        case 2:
            if (prevCat != D_8010CE16_3AA806_name_5D || D_8010C56C_3A9F5C_name_5D != prevSel) {
                func_8010ABDC_3A85CC_name_5D(D_800CAD90[D_8010C050_3A9A40_name_5D[D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D]][D_8010C56C_3A9F5C_name_5D]].unk_06 & 0xFFF);
                func_8001A6BC_1B2BC(spr[8], 0x100);
                func_8001A91C_1B51C(spr[8], scale[8][0], scale[8][1]);
                espPosSet(spr[8], pos[8][0], pos[8][1]);
            }
            for (k = 0; k < count; k++) {
                espPosSet(spr[k], pos[k][0] + HuMathSin(phase[k]) * 2.0f,
                          func_800B7890_B8490(phase[k] * 2) * 2.0f + pos[k][1]);
                phase[k] += 10;
                if (phase[k] > 360) {
                    phase[k] -= 360;
                }
            }
            prevCat = D_8010CE16_3AA806_name_5D;
            prevSel = D_8010C56C_3A9F5C_name_5D;
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_801049A8_3A2398_name_5D);
#endif

void func_8010543C_3A2E2C_name_5D(void) {
    s16 i;
    s16 grp;
    u16 spr;

    for (i = 0; i < 6; i++) {
        D_8010CC50_3AA640_name_5D[i] = grp = func_8001A2F8_1AEF8(D_8010B5DC_3A8FCC_name_5D[i]);
        D_8010CC5C_3AA64C_name_5D[i] = spr = func_8001AAAC_1B6AC(grp, 0, 1);
        func_8001A788_1B388(spr, 5);
        espDispOff(spr);
    }
    for (i = 0; i < 4; i++) {
        D_8010CC68_3AA658_name_5D[i] = grp = func_8001A2F8_1AEF8(D_8010B5F4_3A8FE4_name_5D[gPlayers[i].character]);
        D_8010CC70_3AA660_name_5D[i] = spr = func_8001AAAC_1B6AC(grp, 0, 1);
        func_8001A788_1B388(spr, 5);
        espDispOff(spr);
        D_8010CC78_3AA668_name_5D[i] = grp = func_8001A2F8_1AEF8(0x90100);
        D_8010CC80_3AA670_name_5D[i] = spr = func_8001AAAC_1B6AC(grp, 0, 1);
        func_8001A788_1B388(spr, 6);
        espDispOff(spr);
    }
    D_8010CC8A_3AA67A_name_5D = func_8001AAAC_1B6AC(D_8010CC88_3AA678_name_5D = func_8001A2F8_1AEF8(0xA0160), 0, 1);
    func_8001A788_1B388(D_8010CC8A_3AA67A_name_5D, 5);
    espDispOff(D_8010CC8A_3AA67A_name_5D);
}

// register allocation (masked 102)
#ifdef NON_MATCHING
u16 func_80105648_3A3038_name_5D(void) {
    s16 sel;
    s16 i;
    s16 j;
    s32 x;
    s16 cat;
    s16 ok;
    s16 stkX;
    s16 stkY;
    u8 loop;
    u8 dir;
    u8 max;
    s16* icons;
    s16* ofs;
    s16* ofs2;
    f32 f;
    u16 spr;

    sel = 0;
    ok = 0;
    loop = 1;
    dir = 1;
    icons = NULL;
    cat = D_8010ADD0_3A87C0_name_5D[D_8010CE16_3AA806_name_5D];
    func_800890CC_89CCC(D_8010C562_3A9F52_name_5D, 0x28, -1, -1);
    while (func_8008BA30_8C630(D_8010C562_3A9F52_name_5D) != 0) {
        HuPrcVSleep();
    }
    func_80106208_3A3BF8_name_5D(0x50, 0xA0, 0xF0, 0xA0);
    if (cat == 1) {
        max = 3;
        ofs = D_8010B56C_3A8F5C_name_5D;
        ofs2 = D_8010B578_3A8F68_name_5D;
    } else {
        max = 2;
        ofs = D_8010B584_3A8F74_name_5D;
        ofs2 = D_8010B590_3A8F80_name_5D;
    }
    while (loop) {
        if (cat == 1) {
            icons = D_8010B59C_3A8F8C_name_5D[sel];
        } else {
            icons = D_8010B5BC_3A8FAC_name_5D[sel];
        }
        for (i = 0; i < 11; i++) {
            if (dir) {
                x = 160.0f - (1.0f - HuMathSin(i * 9.0f)) * 240.0f;
            } else {
                x = 400.0f - HuMathSin(i * 9.0f) * 240.0f;
            }
            spr = D_8010CC5C_3AA64C_name_5D[0];
            espDispOn(spr);
            espPosSet(spr, x, 0xA0);
            func_8001A6BC_1B2BC(spr, 0x100);
            spr = D_8010CC5C_3AA64C_name_5D[5];
            espDispOn(spr);
            espPosSet(spr, x + ofs[5], 0xA0);
            func_8001A6BC_1B2BC(spr, 0x100);
            for (j = 0; j < 4; j++) {
                spr = D_8010CC5C_3AA64C_name_5D[1 + icons[j]];
                espDispOn(spr);
                func_8001A6BC_1B2BC(spr, 0x100);
                espPosSet(spr, x + ofs[1 + j], 0xA0);
                spr = D_8010CC70_3AA660_name_5D[icons[j]];
                espDispOn(spr);
                func_8001A6BC_1B2BC(spr, 0x100);
                espPosSet(spr, x + ofs2[j], 0x7D);
                spr = D_8010CC80_3AA670_name_5D[icons[j]];
                espDispOn(spr);
                func_8001A6BC_1B2BC(spr, 0x100);
                espPosSet(spr, x + ofs2[j], 0x7D);
            }
            HuPrcVSleep();
        }
        D_8010CC4E_3AA63E_name_5D = 1;
        while (1) {
            stkX = ContStkX[D_8010BA70_3A9460_name_5D];
            stkY = ContStkY[D_8010BA70_3A9460_name_5D];
            if (ABS(stkX) >= 31 || ABS(stkY) >= 31) {
                if (stkX > 30 || stkY > 30) {
                    PlaySound(1);
                    sel++;
                    sel = (sel > max) ? 0 : sel;
                    dir = 1;
                } else {
                    PlaySound(1);
                    if (--sel < 0) {
                        sel = max;
                    }
                    dir = 0;
                }
                break;
            }
            if (ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x8000) {
                PlaySound(3);
                ok = 1;
                loop = 0;
                dir = 1;
                break;
            }
            if (ContBtnTrg[D_8010BA70_3A9460_name_5D] & 0x4000) {
                PlaySound(4);
                ok = 0;
                loop = 0;
                break;
            }
            HuPrcVSleep();
        }
        D_8010CC4E_3AA63E_name_5D = 0;
        HuPrcVSleep();
        if (ok == 0) {
            for (i = 0; i < 11; i++) {
                if (dir) {
                    f = (1.0f - HuMathSin((10 - i) * 9.0f)) * 240.0f + 160.0f;
                } else {
                    f = 160.0f - (1.0f - HuMathSin((10 - i) * 9.0f)) * 240.0f;
                }
                x = f;
                espPosSet(D_8010CC5C_3AA64C_name_5D[0], x, 0xA0);
                espPosSet(D_8010CC5C_3AA64C_name_5D[5], x + ofs[5], 0xA0);
                for (j = 0; j < 4; j++) {
                    espPosSet(D_8010CC5C_3AA64C_name_5D[1 + icons[j]], x + ofs[1 + j], 0xA0);
                    spr = D_8010CC70_3AA660_name_5D[icons[j]];
                    espDispOn(spr);
                    espPosSet(spr, x + ofs2[j], 0x7D);
                    spr = D_8010CC80_3AA670_name_5D[icons[j]];
                    espDispOn(spr);
                    espPosSet(spr, x + ofs2[j], 0x7D);
                }
                HuPrcVSleep();
            }
            espDispOff(D_8010CC5C_3AA64C_name_5D[0]);
            espDispOff(D_8010CC5C_3AA64C_name_5D[5]);
            for (j = 0; j < 4; j++) {
                espDispOff(D_8010CC5C_3AA64C_name_5D[1 + icons[j]]);
                espDispOff(D_8010CC70_3AA660_name_5D[j]);
                espDispOff(D_8010CC80_3AA670_name_5D[j]);
            }
        }
    }
    D_8010CC4E_3AA63E_name_5D = 0;
    if (ok) {
        for (j = 0; j < 4; j++) {
            D_800F9D48_FA948[0x2F8 + j] = icons[j];
        }
        switch (cat) {
        case 1:
            for (j = 0; j < 4; j++) {
                gPlayers[j].group = 1;
            }
            gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
            break;
        case 2:
            gPlayers[D_800F9D48_FA948[0x2F8]].group = 0;
            gPlayers[D_800F9D48_FA948[0x2F9]].group = 0;
            gPlayers[D_800F9D48_FA948[0x2FA]].group = 1;
            gPlayers[D_800F9D48_FA948[0x2FB]].group = 1;
            break;
        case 0:
        case 3:
            for (j = 0; j < 4; j++) {
                gPlayers[j].group = j;
            }
            break;
        }
    } else {
        for (j = 0; j < 6; j++) {
            spr = D_8010CC5C_3AA64C_name_5D[j];
            espPosSet(spr, -0x50, 0x78);
            espDispOff(spr);
        }
    }
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80105648_3A3038_name_5D);
#endif

void func_8010608C_3A3A7C_name_5D(void) {
    s16 i;
    s16 j;
    f32 a;

    for (i = 0; i < 6; i++) {
        a = (f32)(5 - i) / 5.0f * 256.0f;
        for (j = 0; j < 6; j++) {
            func_8001A6BC_1B2BC(D_8010CC5C_3AA64C_name_5D[j], a);
        }
        for (j = 0; j < 4; j++) {
            func_8001A6BC_1B2BC(D_8010CC70_3AA660_name_5D[j], a);
            func_8001A6BC_1B2BC(D_8010CC80_3AA670_name_5D[j], a);
        }
        HuPrcVSleep();
    }
}

void func_80106208_3A3BF8_name_5D(s16 x0, s16 y0, s16 x1, s16 y1) {
    D_8010CC8C_3AA67C_name_5D = x0;
    D_8010CC8E_3AA67E_name_5D = x1;
    D_8010CC90_3AA680_name_5D = y0;
    D_8010CC92_3AA682_name_5D = y1;
    D_8010CC4C_3AA63C_name_5D = 1;
}

void func_80106238_3A3C28_name_5D(void) {
    s16 grp0;
    s16 grp1;
    u16 spr0;
    u16 spr1;
    s16 a;
    s16 was;
    s8 shown;
    s8 fading;
    s16 step;

    shown = 0;
    fading = 0;
    D_8010CC4E_3AA63E_name_5D = 0;
    D_8010CC4C_3AA63C_name_5D = 0;
    grp0 = func_8001A2F8_1AEF8(0x900C7);
    grp1 = func_8001A2F8_1AEF8(0x900C8);
    spr0 = func_8001AAAC_1B6AC(grp0, 0, 1);
    spr1 = func_8001AAAC_1B6AC(grp1, 0, 1);
    func_8001A788_1B388(spr0, 0x4800);
    func_8001A788_1B388(spr1, 0x4800);
    espPosSet(spr0, 160, 120);
    espPosSet(spr1, 160, 120);
    espDispOff(spr0);
    espDispOff(spr1);
    a = 0;
    step = 0;
    while (1) {
        HuPrcVSleep();
        if (shown != D_8010CC4E_3AA63E_name_5D) {
            shown = (u8)D_8010CC4E_3AA63E_name_5D;
            fading = 1;
            step = -0x3F;
            if (D_8010CC4E_3AA63E_name_5D != 0) {
                step = 0x3F;
            }
        }
        if (fading != 0) {
            was = a;
            a += step;
            if (a >= 0xFF) {
                fading = 0;
                a = 0xFF;
            } else if (a <= 0) {
                fading = 0;
                a = 0;
            }
            if (a != 0) {
                if (was == 0) {
                    espDispOn(spr0);
                    espDispOn(spr1);
                }
                func_8001A6BC_1B2BC(spr0, a);
                func_8001A6BC_1B2BC(spr1, a);
            } else {
                espDispOff(spr0);
                espDispOff(spr1);
            }
        }
        if (D_8010CC4C_3AA63C_name_5D != 0) {
            espPosSet(spr0, D_8010CC8C_3AA67C_name_5D, D_8010CC90_3AA680_name_5D);
            espPosSet(spr1, D_8010CC8E_3AA67E_name_5D, D_8010CC92_3AA682_name_5D);
            D_8010CC4C_3AA63C_name_5D = 0;
        }
    }
}

// control flow and float locals: hoisted constants and stage order differ (masked 56)
#ifdef NON_MATCHING
void func_80106468_3A3E58_name_5D(void) {
    s16 model;
    s16 ang;
    s16 lift;
    s16 d;
    s16 dx;
    s16 dz;
    s16 cx;
    s16 cz;
    s16 sx;
    s16 sz;
    s16 i;
    f32 t;

    ang = 0;
    model = D_8010CCD0_3AA6C0_name_5D[6];
    func_800297E8_2A3E8(model, 0.4f, 0.4f, 0.4f);
    func_80029714_2A314(model, HuMathSin(0.0f) * 300.0f, HuMathSin(0.0f) * 20.0f + 80.0f, func_800B7890_B8490(0.0f) * 300.0f);
    D_800FC834_FD434[model].rot.y = 90.0f;
    if (D_8010C566_3A9F56_name_5D != 0) {
        D_8010CC94_3AA684_name_5D = 1;
        while (1) {
            dx = HuMathSin(ang) * 300.0f - HuMathSin(224.0f) * 300.0f;
            dz = func_800B7890_B8490(ang) * 300.0f - func_800B7890_B8490(224.0f) * 300.0f;
            d = func_800B1830_B2430(dx * dx + dz * dz);
            if (d > 200) {
                lift = 0;
            } else {
                lift = (200 - d) / 2;
            }
            func_80029714_2A314(model, HuMathSin(ang) * 300.0f, HuMathSin(ang * 4) * 5.0f + 80.0f + lift,
                                func_800B7890_B8490(ang) * 300.0f);
            D_800FC834_FD434[model].rot.y = ang + 90;
            HuPrcVSleep();
            if (d <= 50) {
                break;
            }
            ang += 2;
            if (ang >= 224) {
                break;
            }
        }
        ang -= 90;
        cx = HuMathSin(224.0f) * 300.0f;
        cz = func_800B7890_B8490(224.0f) * 300.0f;
        while (1) {
            func_80029714_2A314(model, cx + HuMathSin(ang) * 50.0f, lift + 80, cz + func_800B7890_B8490(ang) * 50.0f);
            D_800FC834_FD434[model].rot.y = ang + 90;
            if (D_8010CC94_3AA684_name_5D == 0) {
                break;
            }
            ang += 5;
            if (ang > 360) {
                ang -= 360;
            }
            HuPrcVSleep();
        }
        sx = cx + HuMathSin(ang) * 50.0f;
        sz = cz + func_800B7890_B8490(ang) * 50.0f;
        for (i = 0; i <= 10; i++) {
            t = i / 10.0f;
            func_80029714_2A314(model, sx + (cx - sx) * t, HuMathSin(ang * 4) * 5.0f + 80.0f + lift, sz + (cz - sz) * t);
            HuPrcVSleep();
        }
        ang = 224;
        while (D_8010C566_3A9F56_name_5D != 0) {
            if (lift <= 0) {
                lift = 0;
            } else {
                lift -= 2;
            }
            func_80029714_2A314(model, HuMathSin(ang) * 300.0f, HuMathSin(ang * 4) * 20.0f + 80.0f + lift,
                                func_800B7890_B8490(ang) * 300.0f);
            D_800FC834_FD434[model].rot.y = ang + 90;
            ang++;
            if (ang > 280) {
                ang = 280;
            }
            HuPrcVSleep();
        }
    } else {
        lift = 0;
        ang = 135;
    }
    while (1) {
        if (lift <= 0) {
            lift = 0;
        } else {
            lift -= 2;
        }
        func_80029714_2A314(model, HuMathSin(ang) * 300.0f, HuMathSin(ang * 4) * 20.0f + 80.0f + lift,
                            func_800B7890_B8490(ang) * 300.0f);
        D_800FC834_FD434[model].rot.y = ang + 90;
        ang++;
        if (ang > 360) {
            ang -= 360;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80106468_3A3E58_name_5D);
#endif

// register allocation (masked 10)
#ifdef NON_MATCHING
void func_80106CC4_3A46B4_name_5D(void) {
    s16 m0;
    u16 m1;
    s16 ang;
    f32 a;
    f32 r;

    ang = 0;
    m0 = D_8010CCD0_3AA6C0_name_5D[7];
    m1 = D_8010CCD0_3AA6C0_name_5D[9];
    func_800297E8_2A3E8(m0, 0.4f, 0.4f, 0.4f);
    func_800297E8_2A3E8(m1, 0.7f, 0.7f, 0.7f);
    a = 90.0f;
    r = 300.0f;
    func_80029714_2A314(m0, HuMathSin(a) * r, 0.0f, func_800B7890_B8490(a) * r);
    func_80029714_2A314(m1, HuMathSin(a) * r, 0.0f, func_800B7890_B8490(a) * r);
    D_800FC834_FD434[m0].rot.y = 180.0f;
    if (D_8010C566_3A9F56_name_5D != 0) {
        do {
            HuPrcVSleep();
        } while (D_8010C566_3A9F56_name_5D != 0);
        ang = 133;
    }
    if (func_80068040_68C40(0xF) != 0) {
        func_800298A4_2A4A4(m0, 4, 4);
        func_800298A4_2A4A4(m1, 4, 4);
    }
    while (1) {
        a = ang + 90;
        func_80029714_2A314(m0, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
        func_80029714_2A314(m1, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
        D_800FC834_FD434[m0].rot.y = ang + 180;
        ang++;
        if (ang > 360) {
            ang -= 360;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80106CC4_3A46B4_name_5D);
#endif

// register allocation (masked 6)
#ifdef NON_MATCHING
void func_80106F5C_3A494C_name_5D(void) {
    s16 size[4];
    s16 m0;
    u16 m1;
    s16 win;
    s16 i;
    s16 ang;
    s16 d;
    f32 a;

    d = 0;
    m1 = D_8010CCD0_3AA6C0_name_5D[9];
    i = 0;
    m0 = D_8010CCD0_3AA6C0_name_5D[7];
    for (; i < 134; i += 2) {
        d += 2;
        if (d > 360) {
            d -= 360;
        }
        a = i + 90;
        func_80029714_2A314(m0, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
        func_80029714_2A314(m1, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
        D_800FC834_FD434[m0].rot.y = i + 180;
        HuPrcVSleep();
    }
    for (i = 0; i <= 10; i++) {
        D_800FC834_FD434[m0].rot.y = 134.0f + i / 10.0f * 90.0f + 180.0f;
        HuPrcVSleep();
    }
    func_8008DBE0_8E7E0(size, 0x4BB, 0x4BF);
    win = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 0xBE, size[0], size[1], 0);
    func_8008D59C_8E19C(win, 1 << D_8010BA70_3A9460_name_5D);
    func_80089284_89E84(win, 0x20, 0x20);
    func_80089A7C_8A67C(win, 1);
    func_8008E978_8F578(win);
    if (D_8010C568_3A9F58_name_5D != 0 && D_8010C56A_3A9F5A_name_5D != 0) {
        func_800890CC_89CCC(win, 0x4BF, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        func_801075D0_3A4FC0_name_5D(m0, 2);
        func_800890CC_89CCC(win, 0x4C0, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        D_8010CC94_3AA684_name_5D = 0;
        func_801075D0_3A4FC0_name_5D(m0, 1);
        func_800890CC_89CCC(win, 0x4C1, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
    } else if (D_8010C568_3A9F58_name_5D != 0) {
        func_800890CC_89CCC(win, 0x4BB, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        D_8010CC94_3AA684_name_5D = 0;
        func_801075D0_3A4FC0_name_5D(m0, 2);
        func_800890CC_89CCC(win, 0x4BC, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
    } else {
        func_800890CC_89CCC(win, 0x4BD, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        D_8010CC94_3AA684_name_5D = 0;
        func_801075D0_3A4FC0_name_5D(m0, 1);
        func_800890CC_89CCC(win, 0x4BE, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
    }
    ang = 134;
    for (i = 0; i <= 10; i++) {
        D_800FC834_FD434[m0].rot.y = ang + (1.0f - i / 10.0f) * 90.0f + 180.0f;
        HuPrcVSleep();
    }
    if (func_80068040_68C40(0xF) != 0) {
        while (1) {
            a = ang + 90;
            func_80029714_2A314(m0, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
            func_80029714_2A314(m1, HuMathSin(a) * 300.0f, 0.0f, func_800B7890_B8490(a) * 300.0f);
            D_800FC834_FD434[m0].rot.y = ang + 180;
            ang++;
            if (ang >= 171) {
                break;
            }
            HuPrcVSleep();
        }
    }
    func_8008EED8_8FAD8(win, 0);
    func_8008CCA8_8D8A8(win);
    D_8010C566_3A9F56_name_5D = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A01F0", func_80106F5C_3A494C_name_5D);
#endif

void func_801075D0_3A4FC0_name_5D(s16 model, s16 idx) {
    Vec pos;
    Vec from;
    Vec2f scr;
    f32 t;
    f32 s;
    f32 d;
    u16 spr;
    s16 i;

    PlaySound(0xC7);
    spr = func_8001AAAC_1B6AC(D_8010C56E_3A9F5E_name_5D, idx, 1);
    func_80029760_2A360(model, &from);
    for (i = 0; i < 24; i++) {
        d = 0.0f - from.x;
        t = i / 20.0f;
        pos.x = d * t + from.x;
        pos.y = HuMathSin(t * 180.0f) * 200.0f + 100.0f;
        pos.z = (0.0f - from.z) * t + from.z;
        func_8010A524_3A7F14_name_5D(0, &pos, &scr);
        espPosSet(spr, scr.unk_00, scr.unk_04);
        s = 1.0f - func_800B7890_B8490(t * 90.0f) + 0.7f;
        func_8001A91C_1B51C(spr, s, s);
        if (i == 20) {
            func_80088604_89204(D_8010BA70_3A9460_name_5D, 2, 2, 0x14);
        }
        HuPrcVSleep();
    }
    PlaySound(0xC6);
}

void func_801077B8_3A51A8_name_5D(void) {
    s16 cat;
    s16 i;

    for (i = 0; i < 9; i++) {
        D_8010C000_3A99F0_name_5D[i] = D_8010C018_3A9A08_name_5D[i] = D_8010C030_3A9A20_name_5D[i] = 0;
    }
    D_8010C560_3A9F50_name_5D = 0;
    D_8010C046_3A9A36_name_5D = 0;
    D_8010C044_3A9A34_name_5D = 0;
    D_8010C042_3A9A32_name_5D = 0;
    for (i = 0; i < 72; i++) {
        if (D_800CAD90[i].unk_00 == 0 || i == 15) {
            continue;
        }
        if (i == 0x22) {
            continue;
        }
        cat = D_800CAD90[i].unk_04;
        if (func_80067F4C_68B4C(i) != 0) {
            if (func_80068040_68C40(i) != 0) {
                D_8010C050_3A9A40_name_5D[cat][D_8010C030_3A9A20_name_5D[cat]] = i;
                D_8010C030_3A9A20_name_5D[cat]++;
                D_8010C044_3A9A34_name_5D++;
            } else {
                D_8010BAF0_3A94E0_name_5D[cat][D_8010C000_3A99F0_name_5D[cat]] = i;
                D_8010C000_3A99F0_name_5D[cat]++;
                D_8010C042_3A9A32_name_5D++;
            }
            D_8010C560_3A9F50_name_5D++;
        }
        D_8010C046_3A9A36_name_5D++;
        D_8010C018_3A9A08_name_5D[cat]++;
    }
    if (func_80068040_68C40(15) != 0) {
        D_8010C050_3A9A40_name_5D[1][D_8010C030_3A9A20_name_5D[1]] = 15;
        D_8010C030_3A9A20_name_5D[1]++;
        D_8010C044_3A9A34_name_5D++;
        D_8010C560_3A9F50_name_5D++;
        D_8010C046_3A9A36_name_5D++;
        D_8010C018_3A9A08_name_5D[1]++;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_8010C050_3A9A40_name_5D[2][D_8010C030_3A9A20_name_5D[2]] = 0x22;
        D_8010C030_3A9A20_name_5D[2]++;
        D_8010C044_3A9A34_name_5D++;
        D_8010C560_3A9F50_name_5D++;
        D_8010C046_3A9A36_name_5D++;
        D_8010C018_3A9A08_name_5D[2]++;
    }
}

void func_80107B20_3A5510_name_5D(void) {
    func_801077B8_3A51A8_name_5D();
    if (func_80068040_68C40(15) != 0) {
        D_8010C044_3A9A34_name_5D--;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_8010C044_3A9A34_name_5D--;
    }
}

void func_80107B8C_3A557C_name_5D(s16 i, s16 esp, s32 dx, s32 dy) {
    D_8010BA78_3A9468_name_5D[i][0] = D_800F93FC_F9FFC[esp].x + dx;
    D_8010BA78_3A9468_name_5D[i][1] = D_800F93FC_F9FFC[esp].y + dy;
}

void func_80107BE0_3A55D0_name_5D(void) {
    s16 i;

    for (i = 0; i < 30; i++) {
        D_8010CDF8_3AA7E8_name_5D[i] = -1;
    }
}

__asm__(".section .rodata");
const char D_8010B62C_3A901C_name_5D[] = "item_fook_5_23";
const char D_8010B63C_3A902C_name_5D[] = "item_fook_5_22";
const char D_8010B64C_3A903C_name_5D[] = "item_fook_5_21";
const char D_8010B65C_3A904C_name_5D[] = "item_fook_5_16";
const char D_8010B66C_3A905C_name_5D[] = "item_fook_5_20";
const char D_8010B67C_3A906C_name_5D[] = "item_fook_5_4";
const char D_8010B68C_3A907C_name_5D[] = "item_fook_5_15";
const char D_8010B69C_3A908C_name_5D[] = "item_fook_5_12";
const char D_8010B6AC_3A909C_name_5D[] = "item_fook_5_19";
const char D_8010B6BC_3A90AC_name_5D[] = "item_fook_5_5";
const char D_8010B6CC_3A90BC_name_5D[] = "item_fook_5_17";
const char D_8010B6DC_3A90CC_name_5D[] = "item_fook_5_7";
const char D_8010B6EC_3A90DC_name_5D[] = "item_fook_5_18";
const char D_8010B6FC_3A90EC_name_5D[] = "item_fook_5_9";
const char D_8010B70C_3A90FC_name_5D[] = "item_fook_5_1";
const char D_8010B71C_3A910C_name_5D[] = "item_fook_5_11";
const char D_8010B72C_3A911C_name_5D[] = "item_fook_5_8";
const char D_8010B73C_3A912C_name_5D[] = "item_fook_5_6";
const char D_8010B74C_3A913C_name_5D[] = "item_fook_5_14";
const char D_8010B75C_3A914C_name_5D[] = "item_fook_5_2";
const char D_8010B76C_3A915C_name_5D[] = "item_fook_5_13";
const char D_8010B77C_3A916C_name_5D[] = "item_fook_5_10";
const char D_8010B78C_3A917C_name_5D[] = "item_fook_5_3";
const char D_8010B79C_3A918C_name_5D[] = "item_fook_1_12";
const char D_8010B7AC_3A919C_name_5D[] = "item_fook_1_11";
const char D_8010B7BC_3A91AC_name_5D[] = "item_fook_1_5";
const char D_8010B7CC_3A91BC_name_5D[] = "item_fook_1_3";
const char D_8010B7DC_3A91CC_name_5D[] = "item_fook_1_10";
const char D_8010B7EC_3A91DC_name_5D[] = "item_fook_1_9";
const char D_8010B7FC_3A91EC_name_5D[] = "item_fook_1_2";
const char D_8010B80C_3A91FC_name_5D[] = "item_fook_1_8";
const char D_8010B81C_3A920C_name_5D[] = "item_fook_1_4";
const char D_8010B82C_3A921C_name_5D[] = "item_fook_1_7";
const char D_8010B83C_3A922C_name_5D[] = "item_fook_1_6";
const char D_8010B84C_3A923C_name_5D[] = "item_fook_1_1";
const char D_8010B85C_3A924C_name_5D[] = "item_fook_2_14";
const char D_8010B86C_3A925C_name_5D[] = "item_fook_2_13";
const char D_8010B87C_3A926C_name_5D[] = "item_fook_2_12";
const char D_8010B88C_3A927C_name_5D[] = "item_fook_2_11";
const char D_8010B89C_3A928C_name_5D[] = "item_fook_2_5";
const char D_8010B8AC_3A929C_name_5D[] = "item_fook_2_4";
const char D_8010B8BC_3A92AC_name_5D[] = "item_fook_2_7";
const char D_8010B8CC_3A92BC_name_5D[] = "item_fook_2_10";
const char D_8010B8DC_3A92CC_name_5D[] = "item_fook_2_6";
const char D_8010B8EC_3A92DC_name_5D[] = "item_fook_2_2";
const char D_8010B8FC_3A92EC_name_5D[] = "item_fook_2_3";
const char D_8010B90C_3A92FC_name_5D[] = "item_fook_2_9";
const char D_8010B91C_3A930C_name_5D[] = "item_fook_2_8";
const char D_8010B92C_3A931C_name_5D[] = "item_fook_2_1";
const char D_8010B93C_3A932C_name_5D[] = "item_fook_3_9";
const char D_8010B94C_3A933C_name_5D[] = "item_fook_3_8";
const char D_8010B95C_3A934C_name_5D[] = "item_fook_3_2";
const char D_8010B96C_3A935C_name_5D[] = "item_fook_3_7";
const char D_8010B97C_3A936C_name_5D[] = "item_foo_3_6";
const char D_8010B98C_3A937C_name_5D[] = "item_fook_3_3";
const char D_8010B99C_3A938C_name_5D[] = "item_fook_3_5";
const char D_8010B9AC_3A939C_name_5D[] = "item_fook_3_4";
const char D_8010B9BC_3A93AC_name_5D[] = "item_fook_3_1";
const char D_8010B9CC_3A93BC_name_5D[] = "item_fook_4_4";
const char D_8010B9DC_3A93CC_name_5D[] = "item_fook_4_6";
const char D_8010B9EC_3A93DC_name_5D[] = "item_fook_4_2";
const char D_8010B9FC_3A93EC_name_5D[] = "item_fook_4_5";
const char D_8010BA0C_3A93FC_name_5D[] = "item_fook_4_3";
const char D_8010BA1C_3A940C_name_5D[] = "item_fook_4_1";
