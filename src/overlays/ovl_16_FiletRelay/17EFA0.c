#include "ovl_16.h"

void func_801071F0_17EFA0_FiletRelay(void) {
    D_801096A0_181450_FiletRelay.state = 0;
    D_801096A0_181450_FiletRelay.next = 0;
    D_801096A0_181450_FiletRelay.sub = 0;
    D_801096A0_181450_FiletRelay.timer = 0;
}

/* Save the pads. */
void func_8010720C_17EFBC_FiletRelay(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_801096A0_181450_FiletRelay.pad[i].stkX = ContStkX[i];
        D_801096A0_181450_FiletRelay.pad[i].stkY = ContStkY[i];
        D_801096A0_181450_FiletRelay.pad[i].btn = ContBtn[i];
        D_801096A0_181450_FiletRelay.pad[i].trg = ContBtnTrg[i];
    }
}

/* Restore the pads. */
void func_8010729C_17F04C_FiletRelay(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = D_801096A0_181450_FiletRelay.pad[i].stkX;
        ContStkY[i] = D_801096A0_181450_FiletRelay.pad[i].stkY;
        ContBtn[i] = D_801096A0_181450_FiletRelay.pad[i].btn;
        ContBtnTrg[i] = D_801096A0_181450_FiletRelay.pad[i].trg;
    }
}

/* Clear the pads. */
void func_8010732C_17F0DC_FiletRelay(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = ContStkY[i] = 0;
        ContBtnTrg[i] = ContBtn[i] = 0;
    }
}

/* The sprite model object: run each model's function, then place it. */
void func_80107380_17F130_FiletRelay(omObjData* obj) {
    FRSprMdl* m;
    s16 sprite;

    for (m = D_801096E0_181490_FiletRelay.next; m != NULL; m = m->next) {
        if (m->func != NULL && !(m->flags & 1)) {
            m->func(m);
            sprite = D_800F86D8_F92D8[m->sprite].unk00;
            func_80029714_2A314(sprite, m->pos.x, m->pos.y, m->pos.z);
            func_800297E8_2A3E8(sprite, m->scale, m->scale, m->scale);
            func_800211E8_21DE8(m->sprite, m->alpha);
        }
    }
}

void func_80107438_17F1E8_FiletRelay(s16 n) {
    func_80020D20_21920(n);
    D_801096D8_181488_FiletRelay = omAddObj(5, 0, 0, -1, func_80107380_17F130_FiletRelay);
    D_801096E0_181490_FiletRelay.flags = 1;
    D_801096E0_181490_FiletRelay.next = NULL;
    D_801096E0_181490_FiletRelay.prev = NULL;
    D_8010971C_1814CC_FiletRelay = &D_801096E0_181490_FiletRelay;
}

void func_801074A0_17F250_FiletRelay(void) {
    func_80108BCC_18097C_FiletRelay();
    omDelObj(D_801096D8_181488_FiletRelay);
    func_80023124_23D24();
}

/* Game state 0: fade in, music, title message. */
void func_801074D0_17F280_FiletRelay(omObjData* obj) {
    switch (D_801096A0_181450_FiletRelay.sub) {
        case 0:
            D_801096A0_181450_FiletRelay.countdown = 1;
            D_801096A0_181450_FiletRelay.time = 9000;
            D_801096A0_181450_FiletRelay.frame = 0;
            D_801096A0_181450_FiletRelay.sub = 1;
            D_801096A0_181450_FiletRelay.winner[0] = -1;
            D_801096A0_181450_FiletRelay.winner[1] = -1;
            D_801096A0_181450_FiletRelay.winner[2] = -1;
            D_801096A0_181450_FiletRelay.winnerCount = 0;
            D_801096A0_181450_FiletRelay.winTeam = -1;
            InitFadeIn(0, 16);
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_801096A0_181450_FiletRelay.sub++;
            }
            break;
        case 2:
            PlayMusic(0x29);
            func_800691FC_69DFC(0xF);
            D_801096A0_181450_FiletRelay.sub++;
            break;
        case 3:
            if (func_80069538_6A138() == 0) {
                D_801096A0_181450_FiletRelay.sub++;
            }
            break;
        case 4:
            func_8010899C_18074C_FiletRelay(1);
            D_801096A0_181450_FiletRelay.sub = 0;
            break;
    }
}

/* Game state 1: the start countdown. */
void func_801075BC_17F36C_FiletRelay(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (--D_801096A0_181450_FiletRelay.countdown < 0) {
            func_8010899C_18074C_FiletRelay(2);
        }
    }
}

/* Game state 2: play; the clock shows its last thirty seconds, and at zero nobody wins. */
void func_80107618_17F3C8_FiletRelay(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (--D_801096A0_181450_FiletRelay.time == 900) {
            func_800691FC_69DFC(10, 30, 160, 32);
        }
        if (D_801096A0_181450_FiletRelay.time < 900) {
            func_8006D4D0_6E0D0(D_801096A0_181450_FiletRelay.time / 30 + 1);
        }
        if (D_801096A0_181450_FiletRelay.time < 0) {
            func_8006D4D0_6E0D0(0);
            func_8010899C_18074C_FiletRelay(3);
        }
    }
}

/* Game state 3: the result: message, winners' cheer, +10 coins each to the winners. */
void func_801076EC_17F49C_FiletRelay(omObjData* obj) {
    s16 mes;

    switch (D_801096A0_181450_FiletRelay.sub) {
        case 0:
            func_800794A8_7A0A8(45);
            mes = 0x14;
            if (D_801096A0_181450_FiletRelay.time < 0) {
                mes = 0x12;
            }
            func_800691FC_69DFC(mes);
            func_8006D518_6E118();
            D_801096A0_181450_FiletRelay.timer = 60;
            D_801096A0_181450_FiletRelay.sub++;
            break;
        case 1:
            if (_CheckFlag(0xC)) {
                if (--D_801096A0_181450_FiletRelay.timer == -1) {
                    if (D_801096A0_181450_FiletRelay.winTeam >= 0) {
                        if (D_801096A0_181450_FiletRelay.winnerCount == 1) {
                            gPlayers[D_801096A0_181450_FiletRelay.winner[0]].coins_mg_bonus += 10;
                        }
                    }
                    func_8010899C_18074C_FiletRelay(4);
                }
            } else if (func_80069538_6A138() == 0) {
                D_801096A0_181450_FiletRelay.timer = 15;
                D_801096A0_181450_FiletRelay.sub++;
            }
            break;
        case 3:
            if (D_801096A0_181450_FiletRelay.winTeam < 0) {
                PlayMusic(0x57);
                func_800691FC_69DFC(0x13);
                D_801096A0_181450_FiletRelay.timer = 120;
            } else if (D_801096A0_181450_FiletRelay.winnerCount == 1) {
                D_801096A0_181450_FiletRelay.timer = 120;
                PlayMusic(0x51);
                func_800691FC_69DFC(6, gPlayers[D_801096A0_181450_FiletRelay.winner[0]].character);
            } else {
                D_801096A0_181450_FiletRelay.timer = 168;
                PlayMusic(0x52);
                func_800691FC_69DFC(0x15, gPlayers[D_801096A0_181450_FiletRelay.winner[0]].character,
                                    gPlayers[D_801096A0_181450_FiletRelay.winner[1]].character,
                                    gPlayers[D_801096A0_181450_FiletRelay.winner[2]].character);
            }
            D_801096A0_181450_FiletRelay.sub++;
            break;
        case 2:
        case 4:
            if (--D_801096A0_181450_FiletRelay.timer == -1) {
                D_801096A0_181450_FiletRelay.sub++;
            }
            break;
        case 5:
            if (D_801096A0_181450_FiletRelay.winTeam >= 0) {
                if (D_801096A0_181450_FiletRelay.winnerCount == 1) {
                    gPlayers[D_801096A0_181450_FiletRelay.winner[0]].coins_mg_bonus += 10;
                } else {
                    gPlayers[D_801096A0_181450_FiletRelay.winner[0]].coins_mg_bonus += 10;
                    gPlayers[D_801096A0_181450_FiletRelay.winner[1]].coins_mg_bonus += 10;
                    gPlayers[D_801096A0_181450_FiletRelay.winner[2]].coins_mg_bonus += 10;
                }
            }
            func_8010899C_18074C_FiletRelay(4);
            break;
    }
}

/* Game state 4: fade out and leave. */
void func_80107A3C_17F7EC_FiletRelay(omObjData* obj) {
    switch (D_801096A0_181450_FiletRelay.sub) {
        case 0:
            func_800794A8_7A0A8(40);
            InitFadeOut(0, 20);
            D_801096A0_181450_FiletRelay.sub++;
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_801096A0_181450_FiletRelay.sub++;
            }
            break;
        case 2:
            func_80107018_17EDC8_FiletRelay();
            func_80103E44_17BBF4_FiletRelay();
            func_801074A0_17F250_FiletRelay();
            func_8002864C_2924C();
            omOvlReturnEx(1);
            break;
    }
}

/* The game object (before the players): run the state; outside play the pads are saved and
   cleared, so the objects see no input. */
void func_80107AF8_17F8A8_FiletRelay(omObjData* obj) {
    if (D_801011FC_101DFC == 1 && D_801096A0_181450_FiletRelay.state != 4) {
        func_8010899C_18074C_FiletRelay(4);
    }
    D_801096A0_181450_FiletRelay.state = D_801096A0_181450_FiletRelay.next;
    if (D_801096A0_181450_FiletRelay.state != 2) {
        func_8010720C_17EFBC_FiletRelay();
        func_8010732C_17F0DC_FiletRelay();
    }
    D_80109434_1811E4_FiletRelay[D_801096A0_181450_FiletRelay.state](obj);
    D_801096A0_181450_FiletRelay.frame++;
}

/* After the objects: give the pads back. */
void func_80107BAC_17F95C_FiletRelay(omObjData* obj) {
    if (D_801096A0_181450_FiletRelay.state != 2) {
        func_8010729C_17F04C_FiletRelay();
    }
}

void func_80107BDC_17F98C_FiletRelay(FRCam* w) {
    func_800B3170_B3D70(&w->eye, &D_801093C4_181174_FiletRelay[w->cam].eye);
    w->fov = 90.0f;
    w->aspect = 0.675f;
}

void func_80107C44_17F9F4_FiletRelay(FRCam* w) {
    w->mode = 0;
}

/* Invert a rigid transform: the 3x3 by its cofactors, then the translation. */
void func_80107C4C_17F9FC_FiletRelay(Matrix4f in, Matrix4f out) {
    f32 a, b, c, d, e, f, g, h, i;
    f32 det;
    f32 x, y, z;

    det = (in[0][0] * in[1][1] * in[2][2] + in[0][1] * in[1][2] * in[2][0] + in[0][2] * in[1][0] * in[2][1])
        - (in[0][2] * in[1][1] * in[2][0] + in[0][1] * in[1][0] * in[2][2] + in[0][0] * in[1][2] * in[2][1]);
    if (det == 0.0f) {
        det = 1.0f;
    } else {
        det = 1.0f / det;
    }
    out[0][0] = ((e = in[1][1]) * (i = in[2][2]) - (f = in[1][2]) * (h = in[2][1])) * det;
    out[0][1] = -(((b = in[0][1]) * i - (c = in[0][2]) * h) * det);
    out[0][2] = (b * f - c * e) * det;
    out[0][3] = in[0][3];
    out[1][0] = -(((d = in[1][0]) * i - f * (g = in[2][0])) * det);
    out[1][1] = ((a = in[0][0]) * i - c * g) * det;
    out[1][2] = -((a * f - c * d) * det);
    out[1][3] = in[1][3];
    out[2][0] = (d * h - e * g) * det;
    out[2][1] = -((a * h - b * g) * det);
    out[2][2] = (a * e - b * d) * det;
    out[2][3] = in[2][3];
    out[3][0] = -(out[0][0] * (x = in[3][0]) + out[1][0] * (y = in[3][1]) + out[2][0] * (z = in[3][2]));
    out[3][1] = -(out[0][1] * x + out[1][1] * y + out[2][1] * z);
    out[3][2] = -(out[0][2] * x + out[1][2] * y + out[2][2] * z);
    out[3][3] = in[3][3];
}

/* A camera object: mode function, perspective, look from the eye at the ring's head. */
void func_80107EBC_17FC6C_FiletRelay(omObjData* obj) {
    FRCam* w = obj->unk_50;
    HuCamera* cam = &D_800C9B80_CA780[w->cam];
    HuCamMtxs* m = &cam->mtxs[D_800FFFD6_100BD6];

    if (D_80109448_1811F8_FiletRelay[w->mode] != NULL) {
        D_80109448_1811F8_FiletRelay[w->mode](w);
    }
    Hu3DCamSetPerspective(w->cam, w->fov, w->nearZ, w->farZ);
    func_800B1C70_B2870(&m->perspMtx, &cam->perspNorm, cam->fov[0], w->aspect, cam->fov[1], cam->fov[2], 1.0f);
    func_800B2400_B3000(w->view, w->eye.x, w->eye.y, w->eye.z, 1.0f, w->ring[w->head].x, w->ring[w->head].y,
                        w->ring[w->head].z);
    func_80107C4C_17F9FC_FiletRelay(w->view, w->inv);
    func_800B3040_B3C40(w->inv, &m->lookAtMtx);
    D_800FC8F8_FD4F8[w->cam][1] = w->ring[w->head].x;
    D_800FC8F8_FD4F8[w->cam][2] = w->ring[w->head].z;
    D_800FC8F8_FD4F8[w->cam][0] = w->eye.y;
    D_800FC8F8_FD4F8[w->cam][3] = D_801093C0_181170_FiletRelay;
}

void func_801080E0_17FE90_FiletRelay(Vec* v) {
    if (!(HuVecGetLength3F(v) < 0.001f)) {
        func_800B33E0_B3FE0(v);
    }
}

void func_8010812C_17FEDC_FiletRelay(void) {
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_801071F0_17EFA0_FiletRelay();
    func_80107438_17F1E8_FiletRelay(0x1E);
}

/* The two cameras: viewport, scissor, the camera object and its work. */
void func_80108164_17FF14_FiletRelay(void) {
    s32 i;
    s32 j;
    FRCam* w;
    u8 id;

    func_80020070_20C70(2);
    for (i = 0; i < 2; i++) {
        func_80020718_21318(i, func_8002EDA8_2F9A8, D_800FC8F8_FD4F8[i]);
        id = i;
        ViewportSet(id, D_801093C4_181174_FiletRelay[i].vp[0], D_801093C4_181174_FiletRelay[i].vp[1], 511.0f,
                    D_801093C4_181174_FiletRelay[i].vp[2], D_801093C4_181174_FiletRelay[i].vp[3], 511.0f);
        ScissorSet(id, D_801093C4_181174_FiletRelay[i].scissor[0], D_801093C4_181174_FiletRelay[i].scissor[1],
                   D_801093C4_181174_FiletRelay[i].scissor[2], D_801093C4_181174_FiletRelay[i].scissor[3]);
        omSetStatBit(D_801096D0_181480_FiletRelay[i] = omAddObj(0x7FDA, 0, 0, -1, func_80107EBC_17FC6C_FiletRelay), 0xA0);
        w = func_80027154_27D54(sizeof(FRCam), 0x7918);
        if (w == NULL) {
            while (1) {
            }
        }
        func_800B0EF0_B1AF0(w, 0, sizeof(FRCam));
        for (j = 0; j < 8; j++) {
            func_800B3170_B3D70(&w->ring[j], &D_801093C4_181174_FiletRelay[i].start);
        }
        func_800B3170_B3D70(&w->eye, &D_801093C4_181174_FiletRelay[i].eye);
        w->cam = i;
        w->fov = 90.0f;
        w->nearZ = 5.0f;
        w->farZ = 700.0f;
        w->aspect = 0.675f;
        w->mode = 0;
        D_801096D0_181480_FiletRelay[i]->unk_50 = w;
        func_8002C59C_2D19C(0x3D4, 0x3E8, 0x54, 0x60, 0x80);
    }
}

/* The two lights (D_80109414). */
void func_80108458_180208_FiletRelay(void) {
    s32 i;

    func_80026D28_27928(2);
    for (i = 0; i < 2; i++) {
        func_80026E00_27A00(i, D_80109414_1811C4_FiletRelay[i].dir[0], D_80109414_1811C4_FiletRelay[i].dir[1],
                            D_80109414_1811C4_FiletRelay[i].dir[2]);
        func_80026DAC_279AC(i, D_80109414_1811C4_FiletRelay[i].color[0], D_80109414_1811C4_FiletRelay[i].color[1],
                            D_80109414_1811C4_FiletRelay[i].color[2]);
    }
}

/* The game object and the pad-restore object. */
void func_8010860C_1803BC_FiletRelay(void) {
    omSetStatBit(omAddObj(0, 0, 0, -1, func_80107AF8_17F8A8_FiletRelay), 0xA0);
    omSetStatBit(omAddObj(6, 0, 0, -1, func_80107BAC_17F95C_FiletRelay), 0xA0);
}

/* Set port's pad state (CPU input). */
void func_80108678_180428_FiletRelay(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn) {
    ContStkX[port] = stkX;
    ContStkY[port] = stkY;
    ContBtn[port] = btn;
    ContBtnTrg[port] = trg;
}

/* The camera's eye (a mode-1 camera resets it first). */
void func_801086B4_180464_FiletRelay(s32 cam, Vec* out) {
    FRCam* w = D_801096D0_181480_FiletRelay[cam]->unk_50;

    if (w->mode == 1) {
        func_80107BDC_17F98C_FiletRelay(w);
    }
    if (out != NULL) {
        func_800B3170_B3D70(out, &w->eye);
    }
}

/* The camera's newest ring position. */
void func_80108714_1804C4_FiletRelay(s32 cam, Vec* out) {
    FRCam* w = D_801096D0_181480_FiletRelay[cam]->unk_50;
    s32 i;

    if (out != NULL) {
        i = w->head - 1;
        if (i < 0) {
            i = 7;
        }
        func_800B3170_B3D70(out, &w->ring[i]);
    }
}

/* Feed the camera: pos enters the ring (a fresh camera fills it). */
void func_80108770_180520_FiletRelay(s32 cam, Vec* pos, Vec* eye, f32 fov, f32 aspect) {
    FRCam* w = D_801096D0_181480_FiletRelay[cam]->unk_50;
    s32 i;

    if (pos != NULL) {
        if (w->mode != 0) {
            for (i = 0; i < 8; i++) {
                func_800B3170_B3D70(&w->ring[i], pos);
            }
            w->mode = 0;
        } else {
            func_800B3170_B3D70(&w->ring[w->head], pos);
            if (++w->head >= 8) {
                w->head = 0;
            }
        }
    }
    if (eye != NULL) {
        func_800B3170_B3D70(&w->eye, eye);
    }
    if (fov != 0.0f) {
        w->fov = fov;
    }
    if (aspect != 0.0f) {
        w->aspect = aspect;
    }
}

/* Cut the camera: pos fills the ring; mode 1. */
void func_801088A4_180654_FiletRelay(s32 cam, Vec* pos, Vec* eye, f32 fov, f32 aspect) {
    FRCam* w = D_801096D0_181480_FiletRelay[cam]->unk_50;
    s32 i;

    if (pos != NULL) {
        for (i = 0; i < 8; i++) {
            func_800B3170_B3D70(&w->ring[i], pos);
        }
    }
    if (eye != NULL) {
        func_800B3170_B3D70(&w->eye, eye);
    }
    if (fov != 0.0f) {
        w->fov = fov;
    }
    if (aspect != 0.0f) {
        w->aspect = aspect;
    }
    w->mode = 1;
}

u8 func_80108990_180740_FiletRelay(void) {
    return D_801096A0_181450_FiletRelay.state;
}

void func_8010899C_18074C_FiletRelay(u8 state) {
    if (state >= 5) {
        while (1) {
        }
    }
    D_801096A0_181450_FiletRelay.sub = 0;
    D_801096A0_181450_FiletRelay.next = state;
}

void func_801089C8_180778_FiletRelay(s16 team) {
    D_801096A0_181450_FiletRelay.winTeam = team;
}

s16 func_801089D4_180784_FiletRelay(void) {
    return D_801096A0_181450_FiletRelay.winTeam;
}

/* Record a player of the winning team (at most three). */
void func_801089E0_180790_FiletRelay(s16 player) {
    s16 n = D_801096A0_181450_FiletRelay.winnerCount;

    if (n < 3) {
        D_801096A0_181450_FiletRelay.winnerCount = n + 1;
        D_801096A0_181450_FiletRelay.winner[n] = player;
    }
}

/* A new sprite model: at the end of the list. */
FRSprMdl* func_80108A1C_1807CC_FiletRelay(s16 flags, s16 unk, void* func) {
    FRSprMdl* m = func_80027154_27D54(sizeof(FRSprMdl), 0x7918);

    if (m == NULL) {
        return NULL;
    }
    m->flags = flags;
    m->sprite = func_80020EBC_21ABC((void*)-1, 0x284, 8);
    if (m->sprite == -1) {
        HuMemFree(m);
        return NULL;
    }
    D_800F86D8_F92D8[m->sprite].unk02 = unk;
    func_80021160_21D60(m->sprite, 4, 4);
    func_80021250_21E50(m->sprite, 0xFF, 0xFF, 0xFF);
    func_800212A4_21EA4(m->sprite);
    m->func = func;
    m->alpha = 0xFF;
    m->scale = 1.0f;
    HuVecCopyXYZ(&m->pos, 0.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&m->vel, 0.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&m->unk_20, 0.0f, 0.0f, 0.0f);
    m->next = NULL;
    m->prev = D_8010971C_1814CC_FiletRelay;
    D_8010971C_1814CC_FiletRelay->next = m;
    D_8010971C_1814CC_FiletRelay = m;
    return m;
}

void func_80108B6C_18091C_FiletRelay(FRSprMdl* m) {
    func_8002308C_23C8C(m->sprite);
    m->prev->next = m->next;
    if (m->next != NULL) {
        m->next->prev = m->prev;
    } else {
        D_8010971C_1814CC_FiletRelay = m->prev;
    }
    HuMemFree(m);
}

void func_80108BCC_18097C_FiletRelay(void) {
    FRSprMdl* m;

    for (m = D_8010971C_1814CC_FiletRelay; m != &D_801096E0_181490_FiletRelay; m = D_8010971C_1814CC_FiletRelay) {
        func_80108B6C_18091C_FiletRelay(m);
    }
}

s16 func_80108C20_1809D0_FiletRelay(s32 file) {
    void* data = DataReadTemp(file);
    s16 sprite = func_8003DF08_3EB08(data);

    DataCloseTemp(data);
    return sprite;
}

