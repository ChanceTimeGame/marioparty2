#ifndef _GAME_CAMERA_H
#define _GAME_CAMERA_H

#include "ultra64.h"
#include "common_structs.h"

/* MP3's HuCamera (include/game/camera.h) less 4 bytes before pos: MP2 has pos at 0x0C and
   fov at 0x4C where MP3 has 0x10 and 0x50. Only the fields MP2's units use are named. */
typedef struct HuCamera {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ Vec pos;
    /* 0x18 */ char unk18[0x34];
    /* 0x4C */ f32 fov[3];
    /* 0x58 */ char unk58[0x260];
} HuCamera; /* size = 0x2B8 (7AA60 indexes the camera list) */

extern HuCamera* D_800C9B80_CA780; /* gCameraList */

#endif
