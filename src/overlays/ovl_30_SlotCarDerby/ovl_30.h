#ifndef _OVL_30_H
#define _OVL_30_H

/* Overlay 30: Slot Car Derby, MP1's ovl_25_SlotCarDerby (1C1EB0.c) ported to MP2's main API.
   Retail is two files: 2386E0.c (cars, track, camera, course scenery setup) and 23F020.c from
   80109140 (scenery objects, effects, billboards). .data stays asm (243CA0); .rodata is carved
   per file. MP2 has three courses (MP1 two).

   Types from the asm's accesses, MP1's names and offsets (MP1 SlotCarDerby.h); a type is checked
   only where a function using it is C. Records with pointers are reached through their fields. */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/pad.h"

typedef f32 Matrix4f[4][4];

/* ---------------------------------------------------------------------------------------------
   Structs (MP1 names)
   --------------------------------------------------------------------------------------------- */

/* A weighted point the camera frames (func_800FA2C0 adds one to D_80102320; D_80100E00's fixed
   course points). No pointers. */
typedef struct SCDFocus {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 weight;
} SCDFocus; /* size = 0x10 */

/* A slot car (D_80101DF8[4], indexed by the car's track lane obj->work[1]; func_800F70C4 maps an
   object to its car). Zeroed with func_8009B770(car, 0, sizeof). Only unk_7C is a pointer, last,
   so every other offset is the host's too. */
typedef struct SCDCar {
    /* 0x00 */ u8 unk_00; /* flags: 1 in use, 0x10 on the track (pose update), 0x40 crashed out,
                             0x80 crossed the line */
    /* 0x01 */ u8 unk_01; /* player index (GwPlayer) */
    /* 0x02 */ u8 unk_02; /* state: 0 idle, 1 racing, 2 finished, 3 off the track, 4 respawn */
    /* 0x03 */ u8 unk_03; /* 1: a human is driving (stick read this frame) */
    /* 0x04 */ u8 unk_04; /* finishing place, 0 none */
    /* 0x05 */ u8 unk_05; /* cars ahead (func_800FB228) */
    /* 0x06 */ u8 unk_06; /* frames over the corner's speed limit */
    /* 0x07 */ u8 unk_07; /* start-jolt frames */
    /* 0x08 */ u8 unk_08; /* blink frames after a respawn */
    /* 0x09 */ char unk_09;
    /* 0x0A */ s16 unk_0A; /* character, 6 = the extra CPU */
    /* 0x0C */ Vec unk_0C; /* position (world / 10) */
    /* 0x18 */ Vec unk_18; /* velocity when off the track */
    /* 0x24 */ Vec unk_24; /* rotation */
    /* 0x30 */ Vec unk_30; /* track direction */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40; /* yaw */
    /* 0x44 */ f32 unk_44; /* lean */
    /* 0x48 */ f32 unk_48; /* track distance of the lane's start */
    /* 0x4C */ f32 unk_4C; /* distance travelled */
    /* 0x50 */ f32 unk_50; /* speed (0..7) */
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58; /* wheel spin angle */
    /* 0x5C */ f32 unk_5C; /* spin-out angle */
    /* 0x60 */ s16 unk_60; /* braking frames */
    /* 0x62 */ s16 unk_62; /* spin-out frames */
    /* 0x64 */ u16 unk_64; /* frames in the state */
    /* 0x66 */ u16 unk_66;
    /* 0x68 */ s16 unk_68; /* CPU: frames raced */
    /* 0x6A */ s16 unk_6A; /* CPU: random bias */
    /* 0x6C */ s16 unk_6C; /* CPU: target throttle x100 */
    /* 0x6E */ s16 unk_6E; /* CPU: frame counter */
    /* 0x70 */ s16 unk_70; /* CPU: throttle x100 */
    /* 0x72 */ s16 unk_72; /* CPU: overspeed tolerance */
    /* 0x74 */ s16 unk_74; /* engine sound handle, -1 none */
    /* 0x76 */ s16 unk_76; /* frames before the engine sound restarts */
    /* 0x78 */ s16 unk_78;
    /* 0x7A */ char unk_7A[2];
    /* 0x7C */ omObjData* unk_7C; /* the player object (func_800F6F38) */
} SCDCar; /* size = 0x80 (N64) */


/* The race state D_80101DE0 (one object: retail addresses its fields from one base register,
   named after the first field each function touches: D_80101DE2/E6/E8/EA). No pointers. */
typedef struct SCDGame {
    /* 0x00 */ s16 unk_00; /* state: 0 intro, 1 countdown, 2 race, 3 result, 4 leave, 7 time up */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* winning car, -1 none */
    /* 0x06 */ s16 unk_06; /* frames in the state */
    /* 0x08 */ s16 unk_08; /* race frames left (0xE10) */
    /* 0x0A */ s16 unk_0A; /* frames the start-line focus stays */
    /* 0x0C */ s16 unk_0C; /* most cars ahead of a human */
} SCDGame; /* size = 0xE */

/* The background particles D_80102008[16] (func_800FAACC). No pointers. */
typedef struct SCDParticle {
    /* 0x00 */ s16 unk_00; /* 0 off, -0x7FFF unused, 0x8000 bit hidden */
    /* 0x02 */ s16 unk_02; /* sprite */
    /* 0x04 */ s16 unk_04; /* sprite group */
    /* 0x06 */ s16 unk_06; /* index in the group */
    /* 0x08 */ u16 unk_08; /* frames alive */
    /* 0x0A */ s16 unk_0A; /* sway angle */
    /* 0x0C */ f32 unk_0C; /* screen x */
    /* 0x10 */ f32 unk_10; /* screen y */
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* y speed */
    /* 0x1C */ f32 unk_1C; /* x scale */
    /* 0x20 */ f32 unk_20; /* y scale */
    /* 0x24 */ f32 unk_24; /* sway amplitude */
    /* 0x28 */ f32 unk_28; /* scale */
    /* 0x2C */ char unk_2C[4];
} SCDParticle; /* size = 0x30 */

/* One camera pose: retail indexes centre and view as f32[3] (func_800FA3B4). No pointers. */
typedef struct SCDCamPose {
    /* 0x00 */ f32 pos[3];  /* centre */
    /* 0x0C */ f32 view[3]; /* view direction */
    /* 0x18 */ f32 zoom;
} SCDCamPose; /* size = 0x1C */

/* The camera D_80102420 (func_800FA154 sets it, func_800FA3B4 eases cur towards target). */
typedef struct SCDCamera {
    /* 0x00 */ SCDCamPose target;
    /* 0x1C */ SCDCamPose cur;
    /* 0x38 */ char unk_38[8];
} SCDCamera; /* size = 0x40 */

/* A scenery record: D_80102468 (HuMemDirectMalloc(0x600): 16) and D_8010246C (0x300: 8). The
   board (D_80102468[0], func_800FC0BC's object) and the time board (D_80102468[1], func_800FC394's
   object) are reached through omObjData::work (func_800FDD08/func_800FDD28). No pointers. */
typedef struct SCDObj {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 unk_08; /* frame counter */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec unk_10; /* position */
    /* 0x1C */ Vec unk_1C;
    /* 0x28 */ Vec unk_28;
    /* 0x34 */ char unk_34[0xC];
    /* 0x40 */ s16 unk_40[16]; /* billboards (func_800FE2F0), [0]/[1] also an alternating index */
} SCDObj; /* size = 0x60 */

/* An effect slot D_80102470 (HuMemDirectMalloc(0x700): 32, func_800FCD6C). No pointers. */
typedef struct SCDFx {
    /* 0x00 */ s8 unk_00; /* its billboard (func_800FE2F0) */
    /* 0x01 */ s8 unk_01; /* type: 0 smoke billboard, 1 spark, 2 dust sprite; -1 free */
    /* 0x02 */ u16 unk_02; /* frame */
    /* 0x04 */ u16 unk_04; /* frames left */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec unk_08; /* position */
    /* 0x14 */ Vec unk_14; /* rotation */
    /* 0x20 */ f32 unk_20; /* scale x */
    /* 0x24 */ f32 unk_24; /* scale y */
    /* 0x28 */ f32 unk_28; /* scale z */
    /* 0x2C */ Vec unk_2C;
} SCDFx; /* size = 0x38 */

/* A billboard D_80103298[D_8010248C] (func_800FE138; func_800FE2F0 builds its display lists,
   func_800FFD18 draws it). The pointer fields shift every later field on the host: use names,
   never offsets. unk_04/unk_10 hold D_800F37DA (<= 3) per-frame copies. */
typedef struct SCDBillboard {
    /* 0x00 */ Gfx* unk_00;    /* display list, (Gfx*)-1 = free */
    /* 0x04 */ Gfx* unk_04[3]; /* per-frame material lists (D_800F37F0 picks one) */
    /* 0x10 */ Vtx* unk_10[3]; /* per-frame vertices (0x80 bytes) */
    /* 0x1C */ void* unk_1C; /* a pointer: only cleared here; func_800FFD18 reads [2 + frame]
                                   from it when unk_20 is set, which nothing in the overlay does */
    /* 0x20 */ s8 unk_20;
    /* 0x21 */ char unk_21;
    /* 0x22 */ u16 unk_22; /* sprite (D_800EC700 index) */
    /* 0x24 */ s16 unk_24; /* frame */
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ u8 unk_28; /* flags: 1 no animation, 2 hold, 4 hide at end, 0x18 render mode,
                             0x20 hidden, 0x40 free at end, 0x80 no billboard */
    /* 0x29 */ u8 unk_29; /* alpha */
    /* 0x2A */ u8 unk_2A; /* r */
    /* 0x2B */ u8 unk_2B; /* g */
    /* 0x2C */ u8 unk_2C; /* b */
    /* 0x2D */ char unk_2D[3];
    /* 0x30 */ f32 unk_30; /* frame timer */
    /* 0x34 */ f32 unk_34; /* animation speed */
    /* 0x38 */ Vec unk_38; /* position */
    /* 0x44 */ Vec unk_44; /* scale */
    /* 0x50 */ Vec unk_50; /* rotation */
} SCDBillboard; /* size = 0x5C (N64) */

/* omObjData::unk_50 of the car-driver objects (func_800F76E8) and of the board object
   (func_800FC0BC): func_80023684(0xE8), MgWork's layout (src/99E0.c), whose pointers sit at 0xB8,
   0xD8, 0xDC and 0xE4. */
typedef struct SCDPlayerWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57[0x61];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0; /* current motion, 0xFFFF none */
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8; /* motion table: obj->mtncnt * 4 (drivers), * sizeof (board) */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} SCDPlayerWork; /* size = 0xE8 (N64) */

#define SCD_WORK(obj) ((SCDPlayerWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Overlay functions (all 86; MP1 twins' signatures where xref pairs them, else from the asm:
   check any past 80107F48)
   --------------------------------------------------------------------------------------------- */
void func_80102800_2386E0_SlotCarDerby(void);
void func_80102BC0_238AA0_SlotCarDerby(omObjData* obj);
void func_80102BE4_238AC4_SlotCarDerby(omObjData* obj);
void func_80102C98_238B78_SlotCarDerby(void);
void func_80102F6C_238E4C_SlotCarDerby(void);
s32 func_801030B0_238F90_SlotCarDerby(s16 slot); /* main func_80015388_15F88(slot) != 0 (MP1 func_80039ACC) */
void func_801030D4_238FB4_SlotCarDerby(SCDCar* car, s16 sound);
void func_80103154_239034_SlotCarDerby(omObjData* obj);
void func_801032A0_239180_SlotCarDerby(omObjData* obj);
SCDCar* func_801032E0_2391C0_SlotCarDerby(omObjData* obj);
s32 func_801032F8_2391D8_SlotCarDerby(void);
void func_80103650_239530_SlotCarDerby(s16 kind, SCDCar* car);
void func_80103874_239754_SlotCarDerby(s16 model, f32 speed); /* MP1 func_800F7650 */
void func_8010389C_23977C_SlotCarDerby(omObjData* obj);
void func_801038B8_239798_SlotCarDerby(omObjData* obj);
void func_801038D4_2397B4_SlotCarDerby(omObjData* obj);
void func_801038F0_2397D0_SlotCarDerby(omObjData* obj);
void func_8010390C_2397EC_SlotCarDerby(omObjData* obj, s16 player);
void func_80103D00_239BE0_SlotCarDerby(omObjData* obj);
s32 func_80103FE8_239EC8_SlotCarDerby(omObjData* obj);
void func_801048BC_23A79C_SlotCarDerby(omObjData* obj, s32 throttle);
void func_80104E54_23AD34_SlotCarDerby(SCDCar* car, f32 ahead);
void func_80104F3C_23AE1C_SlotCarDerby(omObjData* obj, f32 throttle);
void func_801056FC_23B5DC_SlotCarDerby(omObjData* obj);
void func_801059F0_23B8D0_SlotCarDerby(omObjData* obj);
void func_80105DB4_23BC94_SlotCarDerby(omObjData* obj);
s32 func_80105E60_23BD40_SlotCarDerby(f32 dist);
f32 func_80105F5C_23BE3C_SlotCarDerby(f32 start, f32 dist, f32 step, Vec* pos, Vec* dir);
s32 func_801062B8_23C198_SlotCarDerby(Vec* pos, f32* groundY);
f32 func_8010640C_23C2EC_SlotCarDerby(f32 t, f32 a, f32 b, f32 c);
void func_8010646C_23C34C_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out);
f32 func_80106508_23C3E8_SlotCarDerby(f32 t, f32 a, f32 b, f32 c);
void func_80106560_23C440_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out);
f32 func_801066D0_23C5B0_SlotCarDerby(f32 x, f32 y);
void func_80106750_23C630_SlotCarDerby(Vec* dir, f32* angles); /* angles: a Vec, written through ++ */
void func_801067D8_23C6B8_SlotCarDerby(Matrix4f m, f32 x, f32 y, f32 z, f32* out); /* out: a Vec */
void func_80106874_23C754_SlotCarDerby(Matrix4f m, Vec* angles);
void func_80106A00_23C8E0_SlotCarDerby(void);
void func_80106B74_23CA54_SlotCarDerby(f32* pos, f32 weight); /* pos: a Vec, read through ++ */
void func_80106BE0_23CAC0_SlotCarDerby(s32 x, s32 y, s32 z, s32 weight);
void func_80106C68_23CB48_SlotCarDerby(Vec* centre);
void func_80107708_23D5E8_SlotCarDerby(void);
void func_80107864_23D744_SlotCarDerby(void);
void func_80107AD4_23D9B4_SlotCarDerby(void);
void func_80107C40_23DB20_SlotCarDerby(omObjData* obj);
void func_80107E0C_23DCEC_SlotCarDerby(void);
void func_80107E74_23DD54_SlotCarDerby(void);
void func_80107F48_23DE28_SlotCarDerby(s32 x, s32 y, s32 z);
void func_80108D48_23EC28_SlotCarDerby(void);
void func_80108D6C_23EC4C_SlotCarDerby(void);
void func_80108F14_23EDF4_SlotCarDerby(void);
s32 func_80108FF0_23EED0_SlotCarDerby(f32 x, f32 y, f32 z);
void func_80109140_23F020_SlotCarDerby(s16 state); /* MP1 func_800FBE20? */
s32 func_801091DC_23F0BC_SlotCarDerby(u8 player, s16 crossed);
void func_80109240_23F120_SlotCarDerby(s16 course);
void func_80109468_23F348_SlotCarDerby(omObjData* obj);
void func_801096D4_23F5B4_SlotCarDerby(omObjData* obj);
void func_80109CDC_23FBBC_SlotCarDerby(omObjData* obj);
void func_80109EC0_23FDA0_SlotCarDerby(omObjData* obj);
void func_8010A190_240070_SlotCarDerby(omObjData* obj);
void func_8010A55C_24043C_SlotCarDerby(omObjData* obj);
void func_8010A8CC_2407AC_SlotCarDerby(omObjData* obj);
void func_8010AC5C_240B3C_SlotCarDerby(void);
void func_8010AD94_240C74_SlotCarDerby(s32 type, Vec* pos, Vec* rot);
void func_8010ADB0_240C90_SlotCarDerby(s32 type, Vec* pos, Vec* rot); /* type: SCDFx.unk_01 */
void func_8010B098_240F78_SlotCarDerby(omObjData* obj, SCDObj* rec);
SCDObj* func_8010B0B8_240F98_SlotCarDerby(omObjData* obj);
void func_8010B0E4_240FC4_SlotCarDerby(s32 cam, Vec* pos, Vec* screen);
void func_8010B4D0_2413B0_SlotCarDerby(u8 count);
s16 func_8010B688_241568_SlotCarDerby(s16 sprite, u8 flags); /* callers pass sprite unmasked (lh) */
void func_8010C8D4_2427B4_SlotCarDerby(s16 id, s16 frame);
void func_8010C914_2427F4_SlotCarDerby(s16 id, f32 speed);
void func_8010C954_242834_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_8010C9A4_242884_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_8010C9F4_2428D4_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_8010CA44_242924_SlotCarDerby(s16 id, u8 flags);
void func_8010CA88_242968_SlotCarDerby(s16 id, u8 flags);
void func_8010CAD0_2429B0_SlotCarDerby(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_8010CB1C_2429FC_SlotCarDerby(s16 id);
void func_8010CC3C_242B1C_SlotCarDerby(void);
void func_8010D0B0_242F90_SlotCarDerby(void);
void func_8010D590_243470_SlotCarDerby(void); /* MP1 func_801001F8? */
s16 func_8010D644_243524_SlotCarDerby(void);
void func_8010D68C_24356C_SlotCarDerby(void);
void func_8010D6DC_2435BC_SlotCarDerby(s32, s32);
void func_8010DAD8_2439B8_SlotCarDerby(s32, f32);

/* MG30-A */

#endif
