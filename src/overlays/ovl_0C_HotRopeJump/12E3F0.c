#include "ovl_0C.h"

/* The game's setup: objects, camera, each player's place drawn at random, the motion constants.
   NON_MATCHING: retail hoists only the source table and -1 out of the place-drawing loop and keeps
   D_8010C11C by %lo (GCC hoists its address too; masked 17) */
#ifdef NON_MATCHING
void func_80102800_12E3F0_HotRopeJump(void) {
    s32* tbl;
    u8 cam;
    s16 i;
    s32 r;

    func_8002D4D0_2E0D0(50);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    func_8010781C_13340C_HotRopeJump(1600.0f, 0.0f, 100.0f, 100.0f, -30.0f, -50.0f, 0.0f);
    D_80111318_13CF08_HotRopeJump = 0;
    D_800F8FD0_F9BD0 = 1;
    if ((D_8010C140_137D30_HotRopeJump = _CheckFlag(0xC)) != 0) {
        D_8010C110_137D00_HotRopeJump = 50;
    }
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_80111150_13CD40_HotRopeJump = omAddObj(1, 0, 0, -1, func_80102C10_12E800_HotRopeJump);
    omSetStatBit(D_80111150_13CD40_HotRopeJump, 0xA0);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80102DD0_12E9C0_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80102F18_12EB08_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103060_12EC50_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_801031A8_12ED98_HotRopeJump);
    func_80107FB0_133BA0_HotRopeJump();
    D_80111140_13CD30_HotRopeJump = D_800BF7C0_C03C0;
    D_80111144_13CD34_HotRopeJump = D_800BF7A4_C03A4;
    D_80111148_13CD38_HotRopeJump = D_800BF7A8_C03A8;
    D_8011114C_13CD3C_HotRopeJump = D_800BF7D4_C03D4;
    i = 0;
    tbl = D_8010C12C_137D1C_HotRopeJump;
    do {
        do {
            r = rand8() & 3;
        } while (tbl[r] == -1);
        D_8010C11C_137D0C_HotRopeJump[i] = tbl[r];
        i++;
        tbl[r] = -1;
    } while (i < 4);
    D_80111928_13D518_HotRopeJump = -1;
    D_80111338_13CF28_HotRopeJump = 4;
    D_80111334_13CF24_HotRopeJump = 0;
    D_8011133C_13CF2C_HotRopeJump = 0;
    D_80111340_13CF30_HotRopeJump = 0;
    D_80111348_13CF38_HotRopeJump = 0;
    D_80111344_13CF34_HotRopeJump = 0;
    D_800BF7A4_C03A4 = 1.6f;
    D_800BF7A8_C03A8 = 0.175f;
    InitFadeIn(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80102800_12E3F0_HotRopeJump);
#endif

void func_80102C10_12E800_HotRopeJump(omObjData* obj) {
    void* file;
    s32 sprite;
    s32 i;

    obj->func_ptr = func_80103620_12F210_HotRopeJump;
    func_80105DC0_1319B0_HotRopeJump(48);
    file = DataRead(0x1D0005);
    D_8011131C_13CF0C_HotRopeJump = SprAnimRead(file);
    DataClose(file);
    i = 0;
    func_80107424_133014_HotRopeJump();
    file = DataRead(0x38);
    sprite = SprAnimRead(file);
    DataClose(file);
    D_80111320_13CF10_HotRopeJump = SprCreate(2, 0);
    do {
        SprAnimSet((s16)D_80111320_13CF10_HotRopeJump, i, sprite, 0);
        SprPosSet((s16)D_80111320_13CF10_HotRopeJump, i, (s16)D_8010C1D4_137DC4_HotRopeJump[i][0],
                  (s16)D_8010C1D4_137DC4_HotRopeJump[i][1]);
        SprScaleSet((s16)D_80111320_13CF10_HotRopeJump, i, 1.0f, 1.0f);
        func_80082488_83088((s16)D_80111320_13CF10_HotRopeJump, i, 0x100);
        SprAttrSet((s16)D_80111320_13CF10_HotRopeJump, i, 0x1000);
        func_8008225C_82E5C((s16)D_80111320_13CF10_HotRopeJump, i, 0);
        i++;
    } while (i < 2);
}

void func_80102D84_12E974_HotRopeJump(omObjData* obj) {
    func_80107424_133014_HotRopeJump();
    func_80107B4C_13373C_HotRopeJump(obj);
    if (func_8008F618_90218() == 0) {
        func_80105CD4_1318C4_HotRopeJump();
        omOvlReturnEx(1);
    }
}

void func_80102DD0_12E9C0_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 0);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[0]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[0].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[0].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[0].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[0]] * 100.0;
    D_80111158_13CD48_HotRopeJump[0].speed = 20;
    D_80111158_13CD48_HotRopeJump[0].unk_64 = 0;
    if (!(gPlayers[0].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 0;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[0] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_80102F18_12EB08_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 1);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[1]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[1].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[1].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[1].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[1]] * 100.0;
    D_80111158_13CD48_HotRopeJump[1].speed = 20;
    D_80111158_13CD48_HotRopeJump[1].unk_64 = 0;
    if (!(gPlayers[1].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 1;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[1] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_80103060_12EC50_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 2);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[2]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[2].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[2].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[2].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[2]] * 100.0;
    D_80111158_13CD48_HotRopeJump[2].speed = 20;
    D_80111158_13CD48_HotRopeJump[2].unk_64 = 0;
    if (!(gPlayers[2].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 2;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[2] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_801031A8_12ED98_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 3);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[3]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[3].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[3].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[3].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[3]] * 100.0;
    D_80111158_13CD48_HotRopeJump[3].speed = 20;
    D_80111158_13CD48_HotRopeJump[3].unk_64 = 0;
    if (D_8010C11C_137D0C_HotRopeJump[3] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    if (!(gPlayers[3].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 3;
        }
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

/* Loads a player's model and motions; the win/lose motions are a random pair, kept in
   D_80111350_13CF40_HotRopeJump for func_80104518. */
void func_801032F0_12EEE0_HotRopeJump(omObjData* obj, s32 player) {
    s32 mot[4];
    s32 dir;
    s32 file;
    s32 r;
    MgWork* w;

    mot[0] = 0x4E;
    mot[1] = 0x4F;
    mot[2] = 0x55;
    mot[3] = 0x56;
    dir = D_800CD438_CE038[gPlayers[player].character].dir;
    file = D_800CD438_CE038[gPlayers[player].character].file;
    func_8000C578_D178(0);
    func_8000C6FC_D2FC(obj, dir, file, player, 0x4B9, 0x6B9);
    obj->func_ptr = func_80104518_130108_HotRopeJump;
    w = obj->unk_50;
    w->unk_EC = NULL;
    w->unk_59 = player;
    if (gPlayers[player].flags & 1) {
        D_8010C11A_137D0A_HotRopeJump |= 1 << player;
    }
    obj->model[3] = LoadFormFile(7, 0x68D);
    obj->model[4] = LoadFormFile(8, 0x68D);
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 2, 1, 0);
    func_80019E84_1AA84(obj, 6, dir | 4, 1, 0x13);
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 0xD, dir | mot[r], 1, 999);
    D_80111350_13CF40_HotRopeJump[player][0] = dir | mot[r];
    func_80019E84_1AA84(obj, 0xE, dir | mot[r + 2], 1, 999);
    D_80111350_13CF40_HotRopeJump[player][1] = dir | mot[r + 2];
    func_80019E84_1AA84(obj, 0x11, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019E84_1AA84(obj, 0x27, dir, 2, 0);
    func_8000C35C_CF5C(obj, 0.0f, 0.0f, 0.0f);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    func_80019B9C_1A79C(obj, 2);
    func_80019378_19F78(obj);
    func_8000C024_CC24(obj, 0, 2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80103620_12F210_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80104518_130108_HotRopeJump);

/* A burst of smoke where a hit player lands (MP1 func_800F8968). */
void func_8010515C_130D4C_HotRopeJump(f32 x, f32 y, f32 z) {
    s16 id;

    id = func_80105F80_131B70_HotRopeJump((s16)D_8011131C_13CF0C_HotRopeJump, 0x28);
    if (id != -1) {
        func_8010605C_131C4C_HotRopeJump(id, x, y, z);
        func_8010608C_131C7C_HotRopeJump(id, 3.0f, 3.0f, 1.0f);
        func_801060EC_131CDC_HotRopeJump(id, 0xC0, 0xC0, 0xC0, 0xFF);
        func_80106034_131C24_HotRopeJump(id, 4.0f);
    }
}

/* Starts motion slot `motion` of the player's model as a separate model motion (unk_6C), with the
   model's frame count borrowed from that motion's model. */
void func_80105214_130E04_HotRopeJump(omObjData* obj, s32 motion) {
    HRJPlayer* p;
    u8 save;

    p = func_80105D94_131984_HotRopeJump(obj);
    save = D_800FC834_FD434[obj->model[0]].unk02;
    D_800FC834_FD434[obj->model[0]].unk02 = D_800FC834_FD434[obj->motion[motion]].unk02;
    p->unk_6C = func_800231D8_23DD8(obj->model[0], 2);
    D_800FC834_FD434[obj->model[0]].unk02 = save;
    p->unk_68 = 0;
    p->unk_66 = D_800FC834_FD434[obj->motion[motion]].unk02;
}

/* Advances the separate motion two frames, holding its last frame.
   NON_MATCHING: retail converts the frame to unsigned through a double and loads obj->model[0]
   after the conversion (masked 10 with an f64 temporary) */
#ifdef NON_MATCHING
void func_8010530C_130EFC_HotRopeJump(omObjData* obj, HRJPlayer* p) {
    HmfModel* m;

    m = &D_800FC834_FD434[obj->model[0]];
    if (p->unk_68 == 1 && p->unk_6C != NULL) {
        m->unk40 += 2.0;
        if (p->unk_6C[0] <= m->unk40) {
            m->unk40 = p->unk_6C[0] - 1;
        }
        func_80023A08_24608(obj->model[0], p->unk_6C, (u16)m->unk40);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010530C_130EFC_HotRopeJump);
#endif

/* Copies consecutive matrices from src into the motion objects under hmf->unk84[idx] (nothing
   calls it). Retail passes the same src to a child tree as the parent's next part. */
void func_80105410_131000_HotRopeJump(HmfData* hmf, Vec* src, s16 idx) {
    HmfMotionObj* node;
    s32 i;
    s16 c;

    node = &hmf->unk84[idx];
    for (i = 0; i < node->unk00; i++) {
        c = node->unk50[i];
        if (c & 0x8000) {
            if (c != -1) {
                func_80105410_131000_HotRopeJump(hmf, src, c & 0x7FFF);
            }
        } else {
            func_80030CD4_318D4(node->unk58, (f32 (*)[4])src++);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801054E4_1310D4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105570_131160_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105694_131284_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801057B4_1313A4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105AB8_1316A8_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105CD4_1318C4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105D74_131964_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105D94_131984_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105DC0_1319B0_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105F80_131B70_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80106034_131C24_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010605C_131C4C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010608C_131C7C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801060BC_131CAC_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801060EC_131CDC_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80106124_131D14_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801061B0_131DA0_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107424_133014_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010777C_13336C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010781C_13340C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801078A4_133494_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107928_133518_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107A84_133674_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107AE8_1336D8_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107B4C_13373C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107CA4_133894_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107F54_133B44_HotRopeJump);
