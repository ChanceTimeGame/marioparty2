#ifndef _GAME_CAMERA_H
#define _GAME_CAMERA_H

#include "ultra64.h"
#include "common_structs.h"

/* MP2's camera (6 of them, 0x2B8 bytes each, allocated by func_80020070_20C70). Close to MP3's
   HuCamera (include/game/camera.h) but 4 bytes shorter before pos, 4 viewports and 4 matrix
   pairs instead of 3, and no unk5C. */
typedef struct {
    /* 0x00 */ Mtx perspMtx;
    /* 0x40 */ Mtx lookAtMtx;
} HuCamMtxs; /* size 0x80 */

typedef struct HuCamera {
    /* 0x000 */ u16 perspNorm;
    /* 0x002 */ s16 unk2;
    /* 0x004 */ char unk04[0x8];
    /* 0x00C */ Vec pos;
    /* 0x018 */ Vec at;
    /* 0x024 */ Vec up;
    /* 0x030 */ Vec screenScale;
    /* 0x03C */ Vec screenPos;
    /* 0x048 */ char unk48[0x4];
    /* 0x04C */ f32 fov[3];
    /* 0x058 */ Vp viewports[4];
    /* 0x098 */ f32 screenLeft;
    /* 0x09C */ f32 screenTop;
    /* 0x0A0 */ f32 screenRight;
    /* 0x0A4 */ f32 screenBottom;
    /* 0x0A8 */ void* unkA8;
    /* 0x0AC */ void* unkAC;
    /* 0x0B0 */ void* unkB0;
    /* 0x0B4 */ void* unkB4;
    /* 0x0B8 */ HuCamMtxs mtxs[4];
} HuCamera; /* size 0x2B8 */

extern HuCamera* D_800C9B80_CA780; /* gCameraList */

#endif
