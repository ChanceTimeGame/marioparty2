#include "ovl_07.h"

/* .data (0x1139E0-0x113A80, 8010A3D0-8010A470) */
Gfx D_8010A3D0_1139E0_GrabBag[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552048),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList(),
};
Gfx D_8010A418_113A28_GrabBag[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00553078),
    gsDPSetBlendColor(0, 0, 0, 1),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList(),
};
u32 D_8010A468_pad[2] = { 0, 0 };

void func_80104B20_10E130_GrabBag(void) {
    omObjData* obj;

    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    obj = omAddObj(5, 1, 0, -1, func_80104BC0_10E1D0_GrabBag);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    omSetStatBit(obj, 0xA0);
    omSetStatBit(omAddObj(1, 1, 0, -1, func_80105DEC_10F3FC_GrabBag), 0xA0);
}

void func_80104BC0_10E1D0_GrabBag(omObjData* obj) {
    GroundWork* w;

    obj->model[0] = func_80018A30_19630(0x17000C, 0x29D);
    D_8010A7B0_113DC0_GrabBag = func_80104CB8_10E2C8_GrabBag(0x17000D, 0x4000);
    D_8010A7B2_113DC2_GrabBag = func_80104CB8_10E2C8_GrabBag(0x17000E, 0);
    D_8010A824_113E34_GrabBag = 1.0f;
    obj->func_ptr = func_80104D40_10E350_GrabBag;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_08 = 0.5f;
    w->unk_04 = 0;
}

s16 func_80104CB8_10E2C8_GrabBag(s32 file, s32 attr) {
    void* data;
    s16 grp;
    s16 e;

    data = DataReadTemp(file);
    grp = SprAnimRead(data);
    HuMemMemoryFreeTemp(data);
    e = func_8001AAAC_1B6AC(grp, 0, 1);
    SprAttrSet(e, 0, attr);
    espDispOff(e);
    return e;
}

void func_80104D40_10E350_GrabBag(omObjData* obj) {
    func_80104D8C_10E39C_GrabBag(D_8010A7B0_113DC0_GrabBag, D_8010A824_113E34_GrabBag, 0);
    func_801054D4_10EAE4_GrabBag(D_8010A7B2_113DC2_GrabBag, D_8010A824_113E34_GrabBag, 0);
    func_80105D44_10F354_GrabBag(0);
}

/* NON_MATCHING: register allocation (class 4): retail keeps 240.0f in an FP register and the row offset's product out of the x loop (masked ~25; calls and branches agree) */
#ifdef NON_MATCHING
void func_80104D8C_10E39C_GrabBag(s16 idx, f32 scale, s32 cam) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* frame;
    HuCamera* c;
    s16 i;
    s16 y;
    s16 x;
    s32 x0, y0, x1, y1;
    f32 ofs, fx, h, cx, cy, base;

    if (scale < 1.0f) {
        scale = 1.0f;
    } else if (scale > 5.0f) {
        scale = 5.0f;
    }
    spr = func_80082550_83150(D_800F93FC_F9FFC[idx].unk_04, 0);
    frame = &spr->unk_84->unk00[spr->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_8010A3D0_1139E0_GrabBag);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    ofs = (scale - 1.0f) / 2.0f;
    fx = ofs * 320.0f;
    h = scale * 240.0f / 48.0f;
    c = &D_800C9B80_CA780[cam];
    cx = c->screenPos.x - 640.0f;
    cy = c->screenPos.y - 480.0f;
    y1 = 0;
    for (i = 0; i < 48; i++) {
        if (y1 + cy >= 960.0f) {
            break;
        }
        func_8003F710_40310(&D_800FDBCC_FE7CC, (u8*)frame->unk00 + i * 0x640, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 240, 0, 0, 320, 5,
                            0, 2, 2, 0, 0, 0, 0);
        for (y = i * 5; y < 240; y += 240) {
            for (x = 0; x < 320; x += 320) {
                x0 = -fx * 4.0f;
                base = -(ofs * 240.0f);
                y0 = (base + i * h) * 4.0f;
                x1 = (fx + 320.0f) * 4.0f;
                y1 = (base + (i + 1) * h) * 4.0f;
                gSPScisTextureRectangle(D_800FDBCC_FE7CC++, x0 + cx, y0 + cy, x1 + cx, y1 + cy, G_TX_RENDERTILE, 0, 0,
                                        (s32)(1024.0f / scale), (s32)(1024.0f / scale));
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10E130", func_80104D8C_10E39C_GrabBag);
#endif

/* NON_MATCHING: register allocation (class 4), as func_80104D8C (masked ~25; calls and branches agree) */
#ifdef NON_MATCHING
void func_801054D4_10EAE4_GrabBag(s16 idx, f32 scale, s32 cam) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* frame;
    HuCamera* c;
    s16 i;
    s16 y;
    s16 x;
    s32 x0, y0, x1, y1;
    f32 ofs, fx, h, top, cx, cy, base;

    if (scale < 1.0f) {
        scale = 1.0f;
    } else if (scale > 5.0f) {
        scale = 5.0f;
    }
    spr = func_80082550_83150(D_800F93FC_F9FFC[idx].unk_04, 0);
    frame = &spr->unk_84->unk00[spr->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_8010A418_113A28_GrabBag);
    c = &D_800C9B80_CA780[cam];
    gDPSetDepthSource(D_800FDBCC_FE7CC++, G_ZS_PRIM);
    gDPSetPrimDepth(D_800FDBCC_FE7CC++, (u32)(c->screenScale.z * 32.0 * c->screenPos.z), 0);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    ofs = (scale - 1.0f) / 2.0f;
    fx = ofs * 320.0f;
    h = scale * 240.0f / 48.0f;
    top = scale * 240.0f * 3.0f / 4.0f * 4.0f;
    c = &D_800C9B80_CA780[cam];
    cx = c->screenPos.x - 640.0f;
    cy = c->screenPos.y - 480.0f;
    y1 = 0;
    for (i = 0; i < 12; i++) {
        if (y1 + cy >= 960.0f) {
            break;
        }
        func_8003F710_40310(&D_800FDBCC_FE7CC, (u8*)frame->unk00 + i * 0x640, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 240, 0, 0, 320, 5,
                            0, 2, 2, 0, 0, 0, 0);
        for (y = i * 5 + 180; y < 240; y += 240) {
            for (x = 0; x < 320; x += 320) {
                x0 = -fx * 4.0f;
                base = -(ofs * 240.0f);
                y0 = (base + i * h) * 4.0f + top;
                x1 = (fx + 320.0f) * 4.0f;
                y1 = (base + (i + 1) * h) * 4.0f + top;
                gSPScisTextureRectangle(D_800FDBCC_FE7CC++, x0 + cx, y0 + cy, x1 + cx, y1 + cy, G_TX_RENDERTILE, 0, 0,
                                        (s32)(1024.0f / scale), (s32)(1024.0f / scale));
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10E130", func_801054D4_10EAE4_GrabBag);
#endif

void func_80105D44_10F354_GrabBag(s32 cam) {
    Vec scale;
    Vec pos;
    HuCamera* c = &D_800C9B80_CA780[cam];

    scale.x = D_8010A824_113E34_GrabBag * 640.0f;
    scale.y = D_8010A824_113E34_GrabBag * 480.0f;
    scale.z = 511.0f;
    pos.x = c->screenPos.x;
    pos.y = c->screenPos.y;
    pos.z = c->screenPos.z;
    CameraViewportSet(0, &scale, &pos);
}

void func_80105DEC_10F3FC_GrabBag(omObjData* obj) {
    GroundWork* w;

    w = obj->unk_50 = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = 1;
    obj->model[0] = -1;
    obj->func_ptr = func_80102D38_10C348_GrabBag;
}

