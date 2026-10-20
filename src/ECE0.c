#include "common.h"

/* Audio driver. Functions with C come from MP1 src/B980.c (oscillator free list, vibrato depth),
   MP3 src/1140.c (audio command queue) and MP1 ovl_22 (a one-argument wrapper); the rest is asm. */

typedef struct ECE0Osc {
    /* 0x00 */ struct ECE0Osc* next;
} ECE0Osc;

typedef struct {
    /* 0x00 */ s8 cmdType;
    /* 0x01 */ s8 voiceSlot;
    /* 0x04 */ s32 cmdArg;
} AudioCmd; // size 0x8

typedef struct {
    /* 0x00 */ char unk00[0x34];
    /* 0x34 */ s32 unk34;           // write index (wraps at 0x80)
    /* 0x38 */ AudioCmd cmds[0x80];
} UnkAudio;

extern ECE0Osc* D_800D58DC_D64DC;
extern UnkAudio* D_800D58E4_D64E4;

void func_8000EC8C_F88C(s32, s32);
void func_80010E74_11A74(void*, u8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E0E0_ECE0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E1F0_EDF0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E38C_EF8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E3FC_EFFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E930_F530);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E9DC_F5DC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E9E8_F5E8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA34_F634);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA54_F654);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA60_F660);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA68_F668);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA88_F688);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EB1C_F71C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EB3C_F73C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC10_F810);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC64_F864);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC8C_F88C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC94_F894);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000ECB8_F8B8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EDA4_F9A4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EE1C_FA1C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EEA0_FAA0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EF60_FB60);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F634_10234);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F69C_1029C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F744_10344);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F878_10478);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F968_10568);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000FE48_10A48);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000FEFC_10AFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010070_10C70);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800100FC_10CFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010108_10D08);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010114_10D14);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010570_11170);

void func_80010DFC_119FC(ECE0Osc* osc) {
    osc->next = D_800D58DC_D64DC;
    D_800D58DC_D64DC = osc;
}

f32 func_80010E14_11A14(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0f;

    while (depth) {
        if (depth & 1) {
            cents *= x;
        }
        x *= x;
        depth >>= 1;
    }
    return cents;
}

void func_80010E58_11A58(void* obj) {
    func_80010E74_11A74(obj, 0);
}

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010E74_11A74);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011018_11C18);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011064_11C64);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001108C_11C8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800110D8_11CD8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011100_11D00);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011128_11D28);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001122C_11E2C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011308_11F08);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011354_11F54);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001138C_11F8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011430_12030);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800114E8_120E8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011568_12168);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800115B4_121B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800116B4_122B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011738_12338);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800117FC_123FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011938_12538);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011A28_12628);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011AF8_126F8);

/* w1-D */
/* Sound-effect player: voices driven by byte-code scripts, on top of the al sound player. */

typedef struct SndChild {
    /* 0x00 */ s32 slot;   /* voice index */
    /* 0x04 */ u32 serial; /* that voice's serial when it was claimed */
} SndChild; // size 0x8

typedef struct SndMod {
    /* 0x00 */ s16 val;
    /* 0x02 */ s16 type; /* 1 volume, 2 pan, 3 pitch; flag 8 keeps it for one more note */
} SndMod; // size 0x4

typedef struct SndVoice {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 state;    /* 0 free, 1 stopping, 2 paused, 3 starting, 4 running */
    /* 0x08 */ s32 sndState; /* alSndpGetState */
    /* 0x0C */ s16 sndId;    /* al sound id, -1 none */
    /* 0x0E */ s16 defNo;    /* sound definition index */
    /* 0x10 */ u32 serial;
    /* 0x14 */ f32 rateRatio;
    /* 0x18 */ s16 pitch;
    /* 0x1A */ s8 vol;
    /* 0x1B */ s8 pan;
    /* 0x1C */ s8 fxMix;
    /* 0x1D */ u8 priority;
    /* 0x1E */ s8 part;      /* index of this voice's part in the definition */
    /* 0x1F */ s8 numChild;
    /* 0x20 */ SndChild child[4];
    /* 0x40 */ u8* script;
    /* 0x44 */ char unk44[4];
    /* 0x48 */ s16 sampleNo; /* -1: none; bit 15: keep the envelope */
    /* 0x4A */ s16 wait;
    /* 0x4C */ s16 note;
    /* 0x4E */ s16 pitchOfs;
    /* 0x50 */ s8 noteVol;
    /* 0x51 */ s8 noteVolOfs;
    /* 0x52 */ s8 notePan;
    /* 0x53 */ s8 notePanOfs;
    /* 0x54 */ s8 noteFxMix;
    /* 0x55 */ char unk55[3];
    /* 0x58 */ u16 loopPos[3];
    /* 0x5E */ u8 loopCnt[3];
    /* 0x61 */ s8 loopDepth;
    /* 0x62 */ char unk62[2];
    /* 0x64 */ u8* callStack[2];
    /* 0x6C */ s8 callDepth;
    /* 0x6D */ char unk6D[3];
    /* 0x70 */ f32 lfoRand;
    /* 0x74 */ s8 lfoPhase;
    /* 0x75 */ u8 lfoType;
    /* 0x76 */ u8 lfoRate;
    /* 0x77 */ u8 unk77;
    /* 0x78 */ s16 lfoDepth;
    /* 0x7A */ s16 lfoTime;
    /* 0x7C */ s16 lfoPeriod;
    /* 0x7E */ s16 lfoDelay;
    /* 0x80 */ s16 lfoDelay0;
    /* 0x82 */ s8 lfoActive;
    /* 0x83 */ char unk83;
    /* 0x84 */ s8 portFlags;
    /* 0x85 */ s8 portState;
    /* 0x86 */ s16 portDelta;
    /* 0x88 */ s16 portTime;
    /* 0x8A */ s16 portLen;
    /* 0x8C */ u8* penvBase;
    /* 0x90 */ u8* penvPtr;
    /* 0x94 */ f32 penvScale;
    /* 0x98 */ s16 penvDelay0;
    /* 0x9A */ s16 penvDelay;
    /* 0x9C */ s16 penvVal;
    /* 0x9E */ s16 penvAcc;
    /* 0xA0 */ s8 penvCount;
    /* 0xA1 */ char unkA1[3];
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ char unkB0[2];
    /* 0xB2 */ s8 vol2;
    /* 0xB3 */ s8 pan2;
    /* 0xB4 */ f32 pitchMul;
    /* 0xB8 */ s32 randFlags;
    /* 0xBC */ s8 volMax;
    /* 0xBD */ s8 volMin;
    /* 0xBE */ u8 volRate;
    /* 0xBF */ u8 volCnt;
    /* 0xC0 */ s8 panMax;
    /* 0xC1 */ s8 panMin;
    /* 0xC2 */ u8 panRate;
    /* 0xC3 */ u8 panCnt;
    /* 0xC4 */ s16 pitMax;
    /* 0xC6 */ s16 pitMin;
    /* 0xC8 */ u8 pitRate;
    /* 0xC9 */ u8 pitCnt;
    /* 0xCA */ s16 pitVal;
    /* 0xCC */ s32 modMask;
    /* 0xD0 */ SndMod mod[3];
    /* 0xDC */ ALSound sound; /* keyMap holds the sample rate until the sound is allocated */
    /* 0xEC */ ALEnvelope env;
} SndVoice; // size 0xFC

typedef struct SndPart {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 shift; /* low nibble: voice-mask shift step */
    /* 0x02 */ u16 mask;  /* voices this part may use */
    /* 0x04 */ u8* script;
} SndPart; // size 0x8

typedef struct SndDef {
    /* 0x00 */ s8 numParts;
    /* 0x01 */ u8 priority;
    /* 0x02 */ u8 flags;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ SndPart part[1];
} SndDef;

typedef struct SndMgr {
    /* 0x000 */ ALSndPlayer* sndp;
    /* 0x004 */ ALSound* sounds;
    /* 0x008 */ SndVoice* voices;
    /* 0x00C */ SndDef** defs;
    /* 0x010 */ u8** penvs;
    /* 0x014 */ s32 numVoices;
    /* 0x018 */ s32 active;
    /* 0x01C */ u32 serial;
    /* 0x020 */ s32 fadeStep;
    /* 0x024 */ s32 fadeTimer; /* > 0 fading out, < 0 fading in */
    /* 0x028 */ s16 numDefs;
    /* 0x02A */ s16 pitch;
    /* 0x02C */ s8 vol;
    /* 0x02D */ s8 pan;
    /* 0x02E */ s8 fxMix;
    /* 0x02F */ s8 vol2;
    /* 0x030 */ s8 vol3;
    /* 0x031 */ s8 fadeVol;
    /* 0x032 */ s8 pause;
    /* 0x033 */ s8 busy;
    /* 0x034 */ s32 cmdIndex;
    /* 0x038 */ AudioCmd cmds[0x80];
    /* 0x438 */ f32 nearDist;
    /* 0x43C */ f32 farDist;
    /* 0x440 */ f32 panNear;
    /* 0x444 */ f32 panFar;
    /* 0x448 */ s16 angle;
    /* 0x44A */ s16 unk44A;
    /* 0x44C */ f32 unk44C;
    /* 0x450 */ f32 unk450;
} SndMgr; // size 0x454

typedef struct SndPlayParam {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 slot;
    /* 0x08 */ s32 shift;
    /* 0x0C */ s32 vol;
    /* 0x10 */ s32 pitch;
    /* 0x14 */ s32 pan;
    /* 0x18 */ s32 fxMix;
    /* 0x1C */ s32 angle;
    /* 0x20 */ f32 dist;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
} SndPlayParam;

typedef struct SndPosParam {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 angle;
    /* 0x08 */ f32 dist;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
} SndPosParam;

typedef struct SndSlotList {
    /* 0x00 */ s32 n;
    /* 0x04 */ s8 slot[20];
} SndSlotList; // size 0x18

typedef struct SndGlobalParam {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 vol;
    /* 0x08 */ s32 pitch;
    /* 0x0C */ s32 pan;
    /* 0x10 */ s32 fxMix;
} SndGlobalParam;

typedef struct Snd3DParam {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 angle;
    /* 0x08 */ f32 nearDist;
    /* 0x0C */ f32 farDist;
    /* 0x10 */ f32 panNear;
    /* 0x14 */ f32 panFar;
    /* 0x18 */ f32 unk44C;
    /* 0x1C */ f32 unk450;
    /* 0x20 */ s32 unk44A;
} Snd3DParam;

typedef struct SndInitParam {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ void* bank;
    /* 0x10 */ char unk10[0x44];
    /* 0x54 */ s32 numVoices;
    /* 0x58 */ s32 maxEvents;
    /* 0x5C */ char unk5C[0x10];
    /* 0x6C */ void* heap;
} SndInitParam;

typedef struct SndSynCfg {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ s32 outputRate;
} SndSynCfg;

#define SND ((SndMgr*)D_800D58E4_D64E4)

extern u8 D_800F8428_F9028; /* mono flag */

void func_800A0D20_A1920(ALSndPlayer*, s16); /* alSndpSetSound */
void func_8007EEE0_7FAE0(ALSndPlayer*, ALSndpConfig*); /* alSndpNew */
f32 __sinf(f32);
SndSynCfg* func_8000E9DC_F5DC(void);
void func_8000EB3C_F73C(void*, void*, s32, s32);
void* func_8000EC10_F810(s32);
s16 func_8000EC94_F894(s32);
s32 func_800117FC_123FC(void*, void*);
s32 func_80011938_12538(void*, void*);
s32 func_80011A28_12628(void*, void*);
void func_80011AF8_126F8(void);
void func_80012800_13400(SndVoice*);
s32 func_800132A0_13EA0(u8**);
f32 func_800132EC_13EEC(SndVoice*);
void func_80013FD0_14BD0(SndVoice*, s32);
void func_80014768_15368(s32, s32, s32);
SndMgr* func_80014AFC_156FC(void);
s32 func_80014B30_15730(s32, SndPlayParam*);
s32 func_80014D34_15934(s32, s32, s32, s32);
void func_80015148_15D48(s32, s32, u8, SndPlayParam*);
void func_80015B9C_1679C(s32, SndPosParam*);

void func_8001240C_1300C(SndVoice* v) {
    s32 state;

    v->flags = 0;
    v->state = 0;
    if (v->sndId >= 0) {
        func_800A0D20_A1920(SND->sndp, v->sndId);
        state = alSndpGetState(SND->sndp);
        if (state == 1) {
            alSndpStop(SND->sndp);
            v->state = state;
        }
    }
}

void func_8001248C_1308C(SndVoice* v) {
    if (v->sndId >= 0) {
        func_800A0D20_A1920(SND->sndp, v->sndId);
        if ((v->sndState = alSndpGetState(SND->sndp)) == 0) {
            alSndpDeallocate(SND->sndp, v->sndId);
            v->sndId = -1;
        }
    }
}

void func_800124FC_130FC(SndVoice* v) {
    switch (v->state) {
        case 2:
        case 3:
        case 4:
            SND->active++;
            break;
        case 1:
            if (v->sndId < 0) {
                v->state = 0;
            }
            break;
    }
}

void func_80012548_13148(SndVoice* v) {
    SndDef* def;
    SndChild* ch;
    SndVoice* c;
    s32 i;
    s32 n;
    s32 flags;

    if (!(v->flags & 1)) {
        return;
    }
    def = SND->defs[v->defNo];
    if (SND->pause < 0x7F && !(def->flags & 1)) {
        return;
    }
    v->state = 3;
    if (v->sndState == 1) {
        v->env.releaseTime = 4000;
        alSndpStop(SND->sndp);
        return;
    }
    if (v->sndState == 2) {
        return;
    }
    if (v->part > 0) {
        return;
    }
    n = v->numChild;
    ch = v->child;
    if (n != 0) {
        for (i = 0; i < n; i++) {
            c = &SND->voices[ch[i].slot];
            if (c->serial == ch[i].serial && c->sndId >= 0) {
                return;
            }
        }
    }
    flags = 0;
    i = 0;
    if (def->flags & 1) {
        flags |= 4;
    }
    if (def->flags & 2) {
        flags |= 8;
    }
    do {
        v->script = def->part[v->part].script;
        v->wait = 0;
        v->noteVol = 0x7F;
        v->notePan = 0x40;
        v->noteFxMix = 0;
        v->lfoType = 0;
        v->penvBase = NULL;
        v->penvScale = 1.0f;
        v->portFlags = 0;
        v->portState = 0;
        v->loopDepth = 0;
        v->loopCnt[0] = 0;
        v->callDepth = 0;
        v->randFlags = 0;
        v->modMask = 0;
        if (!(v->flags & 0x10)) {
            v->vol = SND->vol;
        }
        if (!(v->flags & 0x20)) {
            v->pan = SND->pan;
        }
        if (!(v->flags & 0x40)) {
            v->pitch = SND->pitch;
        }
        if (!(v->flags & 0x80)) {
            v->fxMix = SND->fxMix;
        }
        if (!(v->flags & 0x100)) {
            v->vol2 = 0x7F;
        }
        if (!(v->flags & 0x200)) {
            v->pan2 = 0x40;
        }
        if (!(v->flags & 0x400)) {
            v->pitchMul = 1.0f;
        }
        v->unkAC = -1.0f;
        v->flags = flags;
        v->state = 4;
        for (; i < n; i++) {
            v = &SND->voices[ch[i].slot];
            if (v->serial == ch[i].serial) {
                break;
            }
        }
        i++;
    } while (i <= n);
}

// register allocation: the note-on loop counter and its sign-extended copy swap a0/a1, and the 0x15/0x17 operand byte lands in a1 (masked 0)
#ifdef NON_MATCHING
void func_80012800_13400(SndVoice* v) {
    u8* p;
    u8* op;
    u8* cnt;
    s32 off;
    s8 j;
    s8 i;
    u16 t;

    if (!(v->flags & 0x1000)) {
        if (v->wait != 0) {
            v->wait--;
        } else {
            p = v->script;
            while (v->wait == 0) {
                op = p++;
                if (!(*op & 0x80)) {
                    v->wait = func_800132A0_13EA0(&p);
                }
                switch (*op & 0x7F) {
                    case 0x02:
                        cnt = &v->loopCnt[v->loopDepth];
                        if (*cnt != 0) {
                            if (((s32)p & 0xFFFF) != v->loopPos[v->loopDepth]) {
                                if (v->loopDepth == 2) {
                                    p += 3;
                                    break;
                                }
                                v->loopDepth++;
                                cnt = &v->loopCnt[v->loopDepth];
                                *cnt = 0;
                            } else if (*cnt == 1) {
                                (*cnt)--;
                                if (v->loopDepth != 0) {
                                    v->loopDepth--;
                                }
                                p += 3;
                                break;
                            } else {
                                (*cnt)--;
                            }
                        }
                        if (*cnt == 0) {
                            if (*p == 0) {
                                p += 3;
                                break;
                            }
                            *cnt = *p;
                            v->loopPos[v->loopDepth] = (u32)p;
                        }
                        p++;
                        p = op + (s16)((p[0] << 8) | p[1]);
                        break;
                    case 0x03:
                        p = op + ((p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]);
                        break;
                    case 0x04:
                        off = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
                        p += 4;
                        if (v->callDepth < 2) {
                            v->callStack[v->callDepth++] = p;
                            p = op + off;
                        }
                        break;
                    case 0x10:
                        if (v->sampleNo < 0 && ((v->flags & 0x1000) || v->sndState != 0)) {
                            p = op;
                            v->wait = 1;
                            break;
                        }
                        v->note = (p[0] << 8) | p[1];
                        p += 2;
                        v->flags |= 0x1000;
                        if (v->portFlags & 8) {
                            v->portFlags &= ~8;
                        } else {
                            v->portState = 0;
                        }
                        if (v->modMask != 0) {
                            for (j = 0; j < 3; j++) {
                                t = 1 << j;
                                if (t & v->modMask) {
                                    if (v->mod[j].type & 8) {
                                        v->mod[j].type &= ~8;
                                    } else {
                                        v->modMask &= ~t;
                                    }
                                }
                            }
                        }
                        break;
                    case 0x11:
                        v->flags |= 0x2000;
                        break;
                    case 0x12:
                        v->sampleNo = (p[0] << 8) | p[1];
                        p += 2;
                        v->flags = (v->flags & 0xFA0FFFFF) | 0x02000000;
                        break;
                    case 0x13:
                        v->sampleNo = (p[0] << 8) | p[1] | 0x8000;
                        p += 2;
                        v->flags = (v->flags & 0xFA0FFFFF) | 0x02000000;
                        break;
                    case 0x14:
                        v->noteVol = *p++ & 0x7F;
                        v->flags |= 0x4000;
                        break;
                    case 0x15:
                        i = *p++;
                        v->noteVol += i;
                        if (v->noteVol < 0) {
                            if (i < 0) {
                                v->noteVol = 0;
                            } else {
                                v->noteVol = 0x7F;
                            }
                        }
                        v->flags |= 0x4000;
                        break;
                    case 0x16:
                        v->notePan = *p++ & 0x7F;
                        v->flags |= 0x8000;
                        break;
                    case 0x17:
                        i = *p++;
                        v->notePan += i;
                        if (v->notePan < 0) {
                            if (i < 0) {
                                v->notePan = 0;
                            } else {
                                v->notePan = 0x7F;
                            }
                        }
                        v->flags |= 0x8000;
                        break;
                    case 0x19:
                        v->note = (p[0] << 8) | p[1];
                        p += 2;
                        v->flags |= 0x20000;
                        break;
                    case 0x1A:
                        v->note += (p[0] << 8) | p[1];
                        p += 2;
                        v->flags |= 0x20000;
                        break;
                    case 0x1B:
                        v->noteFxMix = *p++ & 0x7F;
                        v->flags |= 0x10000;
                        break;
                    case 0x20:
                        v->lfoType = p[0];
                        v->lfoRate = p[1];
                        v->lfoDelay = (p[2] << 8) | p[3];
                        v->lfoDepth = 0;
                        v->unk77 = 0;
                        v->lfoActive = 0;
                        p += 4;
                        break;
                    case 0x21:
                        v->lfoDepth = (p[0] << 8) | p[1];
                        p += 2;
                        break;
                    case 0x22:
                        v->portState = p[0];
                        v->portDelta = (p[1] << 8) | p[2];
                        v->portLen = (p[3] << 8) | p[4];
                        v->portTime = 0;
                        v->portFlags |= 8;
                        p += 5;
                        break;
                    case 0x23:
                        if (SND->penvs != NULL) {
                            v->penvBase = SND->penvs[p[0]];
                            v->penvDelay0 = (p[1] << 8) | p[2];
                            v->penvDelay = -1;
                        }
                        p += 3;
                        break;
                    case 0x24:
                        v->penvScale = ((p[0] << 8) | p[1]) / 100.0f;
                        p += 2;
                        break;
                    case 0x25:
                        v->penvBase = NULL;
                        break;
                    case 0x30:
                        v->env.attackVolume = *p++ & 0x7F;
                        if (v->flags & 0x02000000) {
                            v->flags |= 0x100000;
                        }
                        break;
                    case 0x31:
                        v->env.decayVolume = *p++ & 0x7F;
                        if (v->flags & 0x02000000) {
                            v->flags |= 0x200000;
                        }
                        break;
                    case 0x32:
                        v->env.attackTime = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
                        p += 4;
                        if (v->flags & 0x02000000) {
                            v->flags |= 0x400000;
                        }
                        break;
                    case 0x33:
                        v->env.decayTime = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
                        p += 4;
                        if (v->flags & 0x02000000) {
                            v->flags |= 0x800000;
                        }
                        break;
                    case 0x34:
                        if (v->sampleNo < 0) {
                            v->env.releaseTime = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
                            if (v->flags & 0x02000000) {
                                v->flags |= 0x01000000;
                            }
                        }
                        p += 4;
                        break;
                    case 0x35:
                        t = (p[0] << 8) | p[1];
                        p += 2;
                        v->rateRatio = (f32)t / (f32)func_8000E9DC_F5DC()->outputRate;
                        if (v->flags & 0x02000000) {
                            v->flags |= 0x04000000;
                        }
                        break;
                    case 0x40:
                        v->volMin = p[0];
                        v->volMax = p[1];
                        v->volRate = p[2];
                        v->randFlags |= 1;
                        p += 3;
                        break;
                    case 0x41:
                        v->randFlags &= ~1;
                        break;
                    case 0x42:
                        v->panMin = p[0];
                        v->panMax = p[1];
                        v->panRate = p[2];
                        v->randFlags |= 2;
                        p += 3;
                        break;
                    case 0x43:
                        v->randFlags &= ~2;
                        break;
                    case 0x44:
                        v->pitMin = (p[0] << 8) | p[1];
                        v->pitMax = (p[2] << 8) | p[3];
                        v->pitRate = p[4];
                        v->randFlags |= 4;
                        p += 5;
                        break;
                    case 0x45:
                        v->randFlags &= ~4;
                        break;
                    case 0x50:
                        v->mod[(s8)*p++].val = 0;
                        break;
                    case 0x51:
                        v->mod[(s8)p[0]].val = (p[1] << 8) | p[2];
                        p += 3;
                        break;
                    case 0x52:
                        v->mod[(s8)p[0]].val += (p[1] << 8) | p[2];
                        p += 3;
                        break;
                    case 0x58:
                        i = *p++;
                        v->mod[i].type = 9;
                        v->modMask |= 1 << i;
                        break;
                    case 0x59:
                        i = *p++;
                        v->mod[i].type = 10;
                        v->modMask |= 1 << i;
                        break;
                    case 0x5A:
                        i = *p++;
                        v->mod[i].type = 11;
                        v->modMask |= 1 << i;
                        break;
                    case 0x00:
                        if (v->callDepth != 0) {
                            p = v->callStack[--v->callDepth];
                            v->wait = 0;
                            break;
                        }
                        if (v->sampleNo < 0 && ((v->flags & 0x1000) || v->sndState != 0)) {
                            p = op;
                        } else {
                            v->flags |= 0x40000;
                        }
                        v->wait = 1;
                        break;
                    default:
                        v->flags |= 0x40000;
                        v->wait = 1;
                        break;
                }
            }
            v->script = p;
            v->wait--;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80012800_13400);
#endif

s32 func_800132A0_13EA0(u8** pp) {
    s32 n;
    s32 c;

    c = *(*pp)++;
    n = 0;
    while (c & 0x80) {
        n = ((c & 0x7F) | n) << 7;
        c = *(*pp)++;
    }
    return n + c;
}

f32 func_800132EC_13EEC(SndVoice* v) {
    f32 val;
    f32 half;

    if (v->lfoType == 0) {
        return 0.0f;
    }
    if (v->flags & 0x1000) {
        switch (v->lfoType) {
            case 4:
                v->lfoPhase = 1;
                v->lfoPeriod = 0x105 - v->lfoRate;
                break;
            case 2:
                v->lfoPhase = 0;
            case 1:
            case 3:
                v->lfoPeriod = 0x105 - v->lfoRate;
                break;
            case 5:
                v->lfoPeriod = (0x105 - v->lfoRate) / 2;
                v->lfoRand = 0.0f;
                break;
        }
        v->lfoTime = 0;
        v->lfoDelay0 = v->lfoDelay;
        v->lfoActive = 1;
    }
    if (v->lfoActive == 0) {
        return 0.0f;
    }
    if (v->lfoDelay != 0) {
        v->lfoDelay--;
        return 0.0f;
    }
    switch (v->lfoType) {
        case 1:
            if (v->lfoTime >= v->lfoPeriod) {
                v->lfoTime = 0;
            }
            val = (f32)v->lfoTime / (f32)v->lfoPeriod;
            val = __sinf(val * 6.2831855f);
            break;
        case 2:
            if (v->lfoTime >= v->lfoPeriod / 4) {
                if (++v->lfoPhase >= 4) {
                    v->lfoPhase = 0;
                }
                v->lfoTime = 0;
            }
            val = (f32)v->lfoTime / (f32)(v->lfoPeriod / 4);
            switch (v->lfoPhase) {
                case 1:
                    val = 1.0f - val;
                    break;
                case 2:
                    val = -val;
                    break;
                case 3:
                    val = -(1.0f - val);
                    break;
            }
            break;
        case 3:
            if (v->lfoTime > v->lfoPeriod) {
                v->lfoTime = 0;
            }
            half = (f32)v->lfoPeriod / 2.0f;
            val = ((f32)v->lfoTime - half) / half;
            break;
        case 4:
            if (v->lfoTime >= v->lfoPeriod) {
                v->lfoTime = 0;
                v->lfoPhase *= -1;
            }
            val = v->lfoPhase;
            break;
        case 5:
            if (v->lfoTime >= v->lfoPeriod) {
                v->lfoTime = 0;
                v->lfoRand = (100 - guRandom() % 201) / 100.0f;
            }
            val = v->lfoRand;
            break;
    }
    v->lfoTime += 2;
    return val;
}

void func_80013648_14248(SndVoice* v, f32 lfo) {
    f32 ofs;
    s32 range;
    s32 i;
    u8* p;

    ofs = 0.0f;
    if (v->flags & 0x1000) {
        v->pitchOfs = 0;
    }
    if (v->lfoDepth != 0) {
        ofs = v->lfoDepth * lfo + 0.00001f;
    }
    if (v->portState == 1) {
        if (v->portTime >= v->portLen) {
            v->portState = 0;
            v->note += v->portDelta;
            ofs += 0.00001f;
        } else {
            ofs += (f32)v->portTime / (f32)v->portLen * v->portDelta;
        }
        v->portTime++;
    }
    if (v->penvBase != NULL) {
        if (v->flags & 0x1000) {
            v->penvDelay = v->penvDelay0;
            v->penvPtr = v->penvBase;
            v->penvCount = 0;
            v->penvAcc = 0;
            v->penvVal = 0;
        }
        if (v->penvDelay >= 0) {
            if (v->penvDelay != 0) {
                v->penvDelay--;
            } else {
                if (v->penvCount == 0) {
                    if ((v->penvCount = *v->penvPtr++) == 0) {
                        v->penvPtr = v->penvBase;
                        v->penvCount = *v->penvPtr++;
                        v->penvAcc = 0;
                    }
                    if (v->penvCount == -0x80) {
                        if (v->penvVal == v->penvAcc) {
                            v->note += v->penvVal;
                        } else {
                            v->note += v->penvAcc;
                        }
                        v->penvDelay = -1;
                        v->penvCount = 0;
                    } else {
                        p = v->penvPtr;
                        v->penvVal = ((p[0] << 8) | p[1]) * v->penvScale;
                        v->penvPtr += 2;
                        if (v->penvCount < 0) {
                            v->penvAcc += v->penvVal;
                        }
                        if (v->penvCount > 0) {
                            v->penvAcc = v->penvVal;
                        }
                        if (v->penvCount == 0) {
                            v->penvBase = NULL;
                        }
                    }
                }
                if (v->penvCount > 0) {
                    v->penvCount--;
                    ofs += v->penvVal;
                }
                if (v->penvCount < 0) {
                    v->penvCount++;
                    ofs += v->penvAcc;
                }
                ofs += 0.00001f;
            }
        }
    }
    if (v->randFlags & 4) {
        v->pitCnt--;
        if ((v->flags & 0x1000) || (v->pitCnt == 0 && v->pitRate != 0)) {
            v->pitCnt = v->pitRate;
            range = v->pitMax - v->pitMin + 1;
            v->pitVal = guRandom() % range + v->pitMin;
        }
        ofs += v->pitVal + 0.00001f;
    }
    if (v->modMask != 0) {
        for (i = 0; i < 3; i++) {
            range = 1 << i;
            if (range & v->modMask) {
                if (v->mod[i].type == 3) {
                    ofs += v->mod[i].val + 0.00001f;
                }
            }
        }
    }
    if (ofs != 0.0f) {
        v->pitchOfs = ofs;
        v->flags |= 0x20000;
    }
}

void func_80013A80_14680(SndVoice* v) {
    s32 tmp;
    s32 i;
    s32 sum;
    s32 any;

    sum = 0;
    any = 0;
    if (v->flags & 0x1000) {
        v->notePanOfs = 0;
    }
    if (v->randFlags & 2) {
        v->panCnt--;
        if ((v->flags & 0x1000) || (v->panCnt == 0 && v->panRate != 0)) {
            v->panCnt = v->panRate;
            tmp = v->panMax - v->panMin + 1;
            v->notePan = v->panMin + guRandom() % tmp;
            v->flags |= 0x8000;
        }
    }
    if (v->modMask != 0) {
        for (i = 0; i < 3; i++) {
            tmp = 1 << i;
            if (tmp & v->modMask) {
                if (v->mod[i].type == 2) {
                    sum += v->mod[i].val;
                    any = 1;
                }
            }
        }
    }
    if (any) {
        v->notePanOfs = sum;
        v->flags |= 0x8000;
    }
}

void func_80013BE4_147E4(SndVoice* v) {
    s32 tmp;
    s32 i;
    s32 sum;
    s32 any;

    sum = 0;
    any = 0;
    if (v->flags & 0x1000) {
        v->noteVolOfs = 0;
    }
    if (v->randFlags & 1) {
        v->volCnt--;
        if ((v->flags & 0x1000) || (v->volCnt == 0 && v->volRate != 0)) {
            v->volCnt = v->volRate;
            tmp = v->volMax - v->volMin + 1;
            v->noteVol = v->volMin + guRandom() % tmp;
            v->flags |= 0x4000;
        }
    }
    if (v->modMask != 0) {
        for (i = 0; i < 3; i++) {
            tmp = 1 << i;
            if (tmp & v->modMask) {
                if (v->mod[i].type == 1) {
                    sum += v->mod[i].val;
                    any = 1;
                }
            }
        }
    }
    if (any) {
        v->noteVolOfs = sum;
        v->flags |= 0x4000;
    }
}

void func_80013D44_14944(SndVoice* v) {
    s32 start;
    s32 n; /* the sample index, then the sample n */

    if (v->flags & 0x40000) {
        switch (v->sndState) {
            case 1:
                v->env.releaseTime = 4000;
                alSndpStop(SND->sndp);
            case 2:
                v->state = 1;
                break;
            default:
                v->state = 0;
                break;
        }
        v->flags = 0;
        return;
    }
    start = 0;
    if (v->flags & 0x1000) {
        if (v->sndState == 0) {
            start = 1;
            v->flags &= ~0x1000;
        } else if (v->sampleNo >= 0 && v->sndState == 1) {
            alSndpStop(SND->sndp);
        }
    }
    if (start) {
        if (v->flags & 0x02000000) {
            n = (u16)v->sampleNo & 0x7FFF;
            bcopy(&SND->sounds[n], &v->sound, sizeof(ALSound));
            if (v->flags & 0x01F00000) {
                if (!(v->flags & 0x100000)) {
                    v->env.attackVolume = v->sound.envelope->attackVolume;
                }
                if (!(v->flags & 0x200000)) {
                    v->env.decayVolume = v->sound.envelope->decayVolume;
                }
                if (!(v->flags & 0x400000)) {
                    v->env.attackTime = v->sound.envelope->attackTime;
                }
                if (!(v->flags & 0x800000)) {
                    v->env.decayTime = v->sound.envelope->decayTime;
                }
                if (!(v->flags & 0x01000000)) {
                    v->env.releaseTime = v->sound.envelope->releaseTime;
                }
            } else {
                bcopy(v->sound.envelope, &v->env, sizeof(ALEnvelope));
            }
            v->sound.envelope = &v->env;
            if (v->sampleNo >= 0) {
                v->env.releaseTime = 4000;
            }
            if (!(v->flags & 0x04000000)) {
                /* the bank keeps the sample n in keyMap (pointer-sized field on the host) */
                n = (s32)v->sound.keyMap;
                v->rateRatio = (f32)n / (f32)func_8000E9DC_F5DC()->outputRate;
            }
            v->sound.keyMap = NULL;
            v->flags &= 0xF80FFFFF;
        }
        v->sndId = alSndpAllocate(SND->sndp, &v->sound);
        if (v->sndId >= 0) {
            alSndpSetPriority(SND->sndp, v->sndId, 20);
        }
    }
    func_80013FD0_14BD0(v, start);
}

// scheduling: the pan sum loads pan before pan2 (masked 2)
#ifdef NON_MATCHING
void func_80013FD0_14BD0(SndVoice* v, s32 start) {
    s32 vol;
    s32 pan;
    s32 mix;

    if (v->sndId >= 0) {
        func_800A0D20_A1920(SND->sndp, v->sndId);
        if ((v->flags & 0x4000) || start) {
            vol = v->noteVolOfs + v->noteVol;
            if (vol >= 0x80) {
                vol = 0x7F;
            }
            if (vol < 0) {
                vol = 0;
            }
            vol = vol * SND->fadeVol * v->vol * v->sound.sampleVolume / 2048383;
            vol = vol * SND->vol2 * SND->vol3 * v->vol2 / 2048383;
            if (!(v->flags & 4)) {
                vol = vol * SND->pause / 127;
            }
            alSndpSetVol(SND->sndp, func_8000EC94_F894(vol));
        }
        if ((v->flags & 0x8000) || start) {
            pan = 0x40;
            if (!(D_800F8428_F9028 & 1)) {
                pan = v->notePanOfs + v->notePan;
                mix = v->pan - 0x40;
                mix = v->pan2 + mix;
                pan = mix + (pan - 0x40);
                if (pan < 0) {
                    pan = 0;
                }
                if (pan >= 0x80) {
                    pan = 0x7F;
                }
            }
            alSndpSetPan(SND->sndp, pan);
        }
        if ((v->flags & 0x20000) || start) {
            alSndpSetPitch(SND->sndp, alCents2Ratio(v->pitch + v->pitchOfs + v->note) * v->rateRatio * v->pitchMul);
        }
        if ((v->flags & 0x10000) || start) {
            pan = v->noteFxMix;
            if (pan != 0) {
                mix = pan;
            } else {
                mix = v->fxMix;
            }
            alSndpSetFXMix(SND->sndp, mix);
        }
        if (start && v->sndState == 0) {
            alSndpPlay(SND->sndp);
        }
        if (v->flags & 0x2000) {
            alSndpStop(SND->sndp);
        }
        v->flags &= 0xFFFC1FFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013FD0_14BD0);
#endif

void func_800142C4_14EC4(void) {
    switch (SND->pause) {
        case 0x7E:
            SND->pause = 0x40;
            break;
        case 0x40:
            SND->pause = 0xA;
            break;
        case 0xA:
            SND->pause = 0;
            break;
        case 0:
            SND->pause = -1;
            break;
    }
}

void func_8001434C_14F4C(void) {
    SndVoice* v;
    s32 i;

    if (SND->fadeTimer > 0) {
        if (--SND->fadeTimer != 0) {
            i = (SND->fadeStep * SND->fadeTimer) >> 24;
            if (i != SND->fadeVol) {
                SND->fadeVol = i;
                for (i = 0; i < SND->numVoices; i++) {
                    v = &SND->voices[i];
                    if (v->state == 4) {
                        v->flags |= 0x4000;
                    }
                }
            }
        } else {
            for (i = 0; i < SND->numVoices; i++) {
                func_8001240C_1300C(&SND->voices[i]);
            }
            SND->fadeVol = 0x7F;
        }
    }
    if (SND->fadeTimer < 0) {
        if (++SND->fadeTimer != 0) {
            i = 0x7F - ((-SND->fadeTimer * SND->fadeStep) >> 24);
        } else {
            i = 0x7F;
        }
        if (i != SND->fadeVol) {
            SND->fadeVol = i;
            for (i = 0; i < SND->numVoices; i++) {
                v = &SND->voices[i];
                if (v->state == 4) {
                    v->flags |= 0x4000;
                }
            }
        }
    }
}

// register allocation: the parameter copies come out in another order (masked 0)
#ifdef NON_MATCHING
s32 func_80014520_15120(SndInitParam* cfg, ALHeap* heap, s32 numDefs, s8 vol3) {
    ALSndpConfig sc;
    s32 n; /* the heap pointer, then the voice array size, then a voice index (host: pointer in s32) */

    n = (s32)cfg->heap;
    if (numDefs == 0) {
        D_800D58E4_D64E4 = NULL;
        return 0;
    }
    if ((D_800D58E4_D64E4 = func_8000EC10_F810(sizeof(SndMgr))) == NULL) {
        return 1;
    }
    bzero(D_800D58E4_D64E4, sizeof(SndMgr));
    func_8000EB3C_F73C((void*)n, (u8*)cfg->bank + 0x40, 0x34, 0);
    if (func_800117FC_123FC(cfg->bank, (void*)n) != 0) {
        return 2;
    }
    if (func_80011938_12538(cfg->bank, (void*)n) != 0) {
        return 3;
    }
    if (func_80011A28_12628(cfg->bank, (void*)n) != 0) {
        return 4;
    }
    n = cfg->numVoices * sizeof(SndVoice);
    if ((SND->voices = func_8000EC10_F810(n)) == NULL) {
        return 5;
    }
    bzero(SND->voices, n);
    sc.maxSounds = cfg->numVoices;
    sc.maxEvents = cfg->maxEvents;
    sc.heap = heap;
    if ((SND->sndp = func_8000EC10_F810(sizeof(ALSndPlayer))) == NULL) {
        return 6;
    }
    func_8007EEE0_7FAE0(SND->sndp, &sc);
    SND->numVoices = cfg->numVoices;
    SND->numDefs = numDefs;
    SND->vol3 = vol3;
    SND->pan = 0x40;
    SND->vol2 = SND->fadeVol = SND->pause = SND->vol = 0x7F;
    SND->nearDist = 50.0f;
    SND->farDist = 500.0f;
    SND->unk44A = 10;
    SND->unk44C = 1224.0f;
    SND->unk450 = 1.0f;
    for (n = 0; n < SND->numVoices; n++) {
        SND->voices[n].sndId = -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014520_15120);
#endif

void func_80014768_15368(s32 voiceSlot, s32 cmdType, s32 cmdArg) {
    u32 temp_s3;
    AudioCmd *cmd;

    temp_s3 = osSetIntMask(1);
    cmd = &D_800D58E4_D64E4->cmds[D_800D58E4_D64E4->unk34];
    cmd->cmdType = cmdType;
    cmd->voiceSlot = voiceSlot;
    cmd->cmdArg = cmdArg;
    if (++D_800D58E4_D64E4->unk34 >= 128) {
        func_8000EC8C_F88C(0, 0x200);
        D_800D58E4_D64E4->unk34 = 0;
    }
    osSetIntMask(temp_s3);
}

void func_80014814_15414(s32 voiceSlot, s32 cmdType, f32 cmdArg) {
    u32 mask;
    AudioCmd* cmd;

    mask = osSetIntMask(1);
    cmd = &SND->cmds[SND->cmdIndex];
    cmd->cmdType = cmdType;
    cmd->voiceSlot = voiceSlot;
    *(f32*)&cmd->cmdArg = cmdArg;
    if (++SND->cmdIndex >= 128) {
        func_8000EC8C_F88C(0, 0x200);
        SND->cmdIndex = 0;
    }
    osSetIntMask(mask);
}

void func_800148C4_154C4(void) {
    SndVoice* v;
    s32 i;

    if (SND != NULL && SND->busy == 0) {
        SND->busy = 1;
        SND->active = 0;
        func_80011AF8_126F8();
        func_800142C4_14EC4();
        for (i = 0; i < SND->numVoices; i++) {
            v = &SND->voices[i];
            func_8001248C_1308C(v);
            func_80012548_13148(v);
            func_800124FC_130FC(v);
            if (v->state != 4) {
                if (v->state == 2 && SND->pause >= 0) {
                    v->flags |= 0x4000;
                    func_80013FD0_14BD0(v, 0);
                }
            } else {
                func_80012800_13400(v);
                func_80013648_14248(v, func_800132EC_13EEC(v));
                func_80013A80_14680(v);
                func_80013BE4_147E4(v);
                func_80013D44_14944(v);
                if (v->state < 2) {
                    SND->active--;
                }
            }
        }
        if (SND->pause == 0x7F) {
            func_8001434C_14F4C();
        }
        SND->busy = 0;
    }
}

void func_80014A60_15660(void) {
    SndVoice* v;
    s32 i;

    if (SND != NULL) {
        for (i = 0; i < SND->numVoices; i++) {
            v = &SND->voices[i];
            if (v->sndId >= 0) {
                func_800A0D20_A1920(SND->sndp, v->sndId);
                alSndpStop(SND->sndp);
            }
        }
        alSndpDelete(SND->sndp);
    }
}

SndMgr* func_80014AFC_156FC(void) {
    return SND;
}

void func_80014B08_15708(void) {
    D_800D58E4_D64E4 = NULL;
}

s32 func_80014B14_15714(s32 defNo) {
    return func_80014B30_15730(defNo, NULL);
}

s32 func_80014B30_15730(s32 defNo, SndPlayParam* prm) {
    s32 slots[4]; /* four in retail's frame; parts beyond that would overrun it */
    SndMgr* m;
    SndDef* def;
    SndVoice* v;
    s32 slot;
    s32 shift;
    s32 i;
    s32 n;

    m = func_80014AFC_156FC();
    if (m == NULL) {
        return 0;
    }
    if (defNo >= m->numDefs) {
        return -1;
    }
    def = m->defs[defNo];
    if (def == NULL) {
        return -1;
    }
    slot = -1;
    if (prm != NULL && (prm->flags & 0x100)) {
        slot = prm->slot;
    }
    shift = 0;
    if (prm != NULL) {
        if (prm->flags & 0x200) {
            shift = prm->shift;
        }
    }
    if ((slots[0] = func_80014D34_15934(defNo, 0, slot, shift)) < 0) {
        return -1;
    }
    func_80015148_15D48(defNo, slots[0], 0xFF, prm);
    v = &m->voices[slots[0]];
    n = 0;
    for (i = (s8)def->numParts - 1; i > 0; i--) {
        slot = slots[i] = func_80014D34_15934(defNo, i, -1, shift);
        if (slot >= 0) {
            func_80015148_15D48(defNo, slot, def->priority, prm);
            v->child[n].slot = slot;
            v->child[n].serial = m->voices[slot].serial;
            n++;
        }
    }
    v->priority = def->priority;
    for (i = (s8)def->numParts - 1; i > 0; i--) {
        if (slots[i] >= 0) {
            func_80014768_15368(slots[i], 1, i);
        }
    }
    func_80014768_15368(slots[0], 1, n << 4);
    return slots[0];
}

// register allocation: other t-registers throughout (masked 0)
#ifdef NON_MATCHING
s32 func_80014D34_15934(s32 defNo, s32 partNo, s32 slot, s32 shiftCount) {
    SndSlotList free;
    SndSlotList same;
    SndSlotList other;
    SndMgr* m;
    SndDef* def;
    SndVoice* v;
    u32 mask;
    u32 serial;
    u32 s;
    s32 bit;
    s32 i;
    s32 j;
    s32 n;
    s32 best;
    s8 k;
    s32 tmp;

    m = func_80014AFC_156FC();
    def = m->defs[defNo];
    mask = def->part[partNo].mask;
    if (slot >= 0) {
        if (slot >= m->numVoices) {
            return -1;
        }
        v = &m->voices[slot];
        if (v->state >= 2 && def->priority < v->priority) {
            return -1;
        }
        return slot;
    }
    if (shiftCount != 0) {
        mask <<= (shiftCount - 1) * (def->part[partNo].shift & 0xF);
    }
    free.n = same.n = other.n = 0;
    i = ((mask & 0x1F) == 0) ? 5 : 0;
    n = 0;
    while (i < m->numVoices && mask != 0) {
        bit = 1 << i;
        if (mask & bit) {
            v = &m->voices[i];
            if (v->state >= 2) {
                if (v->defNo == defNo) {
                    same.slot[same.n++] = i;
                } else {
                    other.slot[other.n++] = i;
                }
            } else {
                free.slot[free.n++] = i;
            }
            n++;
            mask &= ~bit;
        }
        i++;
    }
    if (n >= 2) {
        for (j = 0; j < same.n; j++) {
            v = &m->voices[same.slot[j]];
            if (v->state == 3 && v->defNo == defNo) {
                return -1;
            }
        }
    }
    if (free.n != 0) {
        return free.slot[0];
    }
    if (other.n != 0) {
        if (other.n == 1) {
            k = other.slot[0];
            if (def->priority >= m->voices[k].priority) {
                return k;
            }
        } else {
            for (i = 0; i < other.n - 1; i++) {
                serial = m->voices[other.slot[i]].serial;
                for (j = i + 1; j < other.n; j++) {
                    v = &m->voices[other.slot[j]];
                    s = v->serial;
                    if (s < serial) {
                        serial = s;
                        tmp = other.slot[i];
                        other.slot[i] = other.slot[j];
                        other.slot[j] = tmp;
                    }
                }
            }
            for (j = 0; j < other.n; j++) {
                k = other.slot[j];
                if (def->priority >= m->voices[k].priority) {
                    return k;
                }
            }
        }
    }
    if (same.n != 0) {
        serial = m->voices[same.slot[0]].serial;
        best = 0;
        for (j = 1; j < same.n; j++) {
            s = m->voices[same.slot[j]].serial;
            if (s < serial) {
                serial = s;
                best = j;
            }
        }
        return same.slot[best];
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014D34_15934);
#endif

void func_80015148_15D48(s32 defNo, s32 slot, u8 priority, SndPlayParam* prm) {
    SndPosParam pos;
    SndMgr* m;
    SndVoice* v;

    m = func_80014AFC_156FC();
    func_80014768_15368(slot, 0, 0);
    v = &m->voices[slot];
    v->state = 3;
    v->defNo = defNo;
    v->serial = m->serial++;
    v->priority = priority;
    v->numChild = 0;
    v->unkA4 = v->unkA8 = 0.0f;
    if (prm != NULL) {
        if (prm->flags & 1) {
            v->vol = prm->vol;
            func_80014768_15368(slot, 2, prm->vol);
        }
        if (prm->flags & 2) {
            v->pan = prm->pan;
            func_80014768_15368(slot, 7, prm->pan);
        }
        if (prm->flags & 4) {
            v->pitch = prm->pitch;
            func_80014768_15368(slot, 5, prm->pitch);
        }
        if (prm->flags & 8) {
            v->fxMix = prm->fxMix;
            func_80014768_15368(slot, 9, prm->fxMix);
        }
        pos.flags = 0;
        if (prm->flags & 0x20) {
            pos.flags = 2;
            pos.dist = prm->dist;
        }
        if (prm->flags & 0x10) {
            pos.flags |= 1;
            pos.angle = prm->angle;
        }
        if (prm->flags & 0x40) {
            pos.flags |= 0x10;
            pos.unkC = prm->unk24;
        }
        if (prm->flags & 0x80) {
            pos.flags |= 0x20;
            pos.unk10 = prm->unk28;
        }
        if (pos.flags & 0x33) {
            func_80015B9C_1679C(slot, &pos);
        }
    }
}

s16 func_80015334_15F34(void) {
    SndMgr* m = func_80014AFC_156FC();

    if (m == NULL) {
        return 0;
    }
    return m->numDefs;
}

// register allocation: result and manager pointer in swapped registers (masked 3)
#ifdef NON_MATCHING
s32 func_8001535C_15F5C(void) {
    SndMgr* m = func_80014AFC_156FC();
    s32 ret = 0;

    if (m != NULL) {
        ret = m->active;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001535C_15F5C);
#endif

s32 func_80015388_15F88(s32 slot) {
    SndMgr* m = func_80014AFC_156FC();

    if (m == NULL) {
        return 0;
    }
    return m->voices[slot].state;
}

s32 func_800153CC_15FCC(s32 defNo) {
    SndMgr* m = func_80014AFC_156FC();
    SndVoice* v;
    s32 i;

    if (m == NULL) {
        return 0;
    }
    for (i = 0; i < m->numVoices; i++) {
        v = &m->voices[i];
        if (v->state >= 2 && v->defNo == defNo && v->part == 0) {
            return i;
        }
    }
    return -1;
}

u8 func_8001545C_1605C(s32 defNo) {
    SndMgr* m = func_80014AFC_156FC();

    return (m != NULL) ? m->defs[defNo]->unk3 : 0;
}

void func_800154A0_160A0(SndGlobalParam* out) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        out->vol = m->vol;
        out->pitch = m->pitch;
        out->pan = m->pan;
        out->fxMix = m->fxMix;
    }
}

void func_800154F0_160F0(SndGlobalParam* in) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (in->flags & 1) {
            m->vol = in->vol;
        }
        if (in->flags & 4) {
            m->pitch = in->pitch;
        }
        if (in->flags & 2) {
            m->pan = in->pan;
        }
        if (in->flags & 8) {
            m->fxMix = in->fxMix;
        }
    }
}

void func_80015580_16180(s32 arg) {
    if (func_80014AFC_156FC() != NULL) {
        func_80014768_15368(0, 3, arg);
    }
}

void func_800155B8_161B8(s32 slot, s32 vol) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (slot < 0) {
            for (slot = 0; slot < m->numVoices; slot++) {
                m->voices[slot].vol = vol;
            }
            func_80014768_15368(0, 4, vol);
        } else {
            m->voices[slot].vol = vol;
            func_80014768_15368(slot, 2, vol);
        }
    }
}

void func_80015664_16264(s32 slot, s32 pitch) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (slot < 0) {
            for (slot = 0; slot < m->numVoices; slot++) {
                m->voices[slot].pitch = pitch;
            }
            func_80014768_15368(0, 6, pitch);
        } else {
            m->voices[slot].pitch = pitch;
            func_80014768_15368(slot, 5, pitch);
        }
    }
}

void func_80015710_16310(s32 slot, s32 pan) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (slot < 0) {
            for (slot = 0; slot < m->numVoices; slot++) {
                m->voices[slot].pan = pan;
            }
            func_80014768_15368(0, 8, pan);
        } else {
            m->voices[slot].pan = pan;
            func_80014768_15368(slot, 7, pan);
        }
    }
}

void func_800157BC_163BC(s32 slot, s32 fxMix) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (slot < 0) {
            for (slot = 0; slot < m->numVoices; slot++) {
                m->voices[slot].fxMix = fxMix;
            }
            func_80014768_15368(0, 10, fxMix);
        } else {
            m->voices[slot].fxMix = fxMix;
            func_80014768_15368(slot, 9, fxMix);
        }
    }
}

void func_80015868_16468(s32 slot) {
    SndMgr* m = func_80014AFC_156FC();
    SndVoice* v;
    s32 i;

    if (m != NULL) {
        m->busy = 1;
        if (slot < 0) {
            func_80014768_15368(0, 12, 0);
            for (i = 0; i < m->numVoices; i++) {
                v = &m->voices[i];
                if (v->state >= 2) {
                    v->state = 1;
                }
            }
        } else {
            v = &m->voices[slot];
            if (v->state >= 2) {
                func_80014768_15368(slot, 11, 0);
                v->state = 1;
            }
        }
        m->busy = 0;
    }
}

void func_80015950_16550(s32 arg) {
    if (func_80014AFC_156FC() != NULL) {
        func_80014768_15368(0, 13, arg);
    }
}

// register allocation: result and manager pointer in swapped registers (masked 3)
#ifdef NON_MATCHING
s32 func_80015988_16588(void) {
    SndMgr* m;
    s32 ret;

    m = func_80014AFC_156FC();
    ret = 0;
    if (m != NULL) {
        ret = m->fadeTimer;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015988_16588);
#endif

void func_800159B4_165B4(void) {
    SndMgr* m = func_80014AFC_156FC();
    SndVoice* v;
    s32 i;

    if (m != NULL && m->pause >= 0x7F) {
        func_80014768_15368(0, 14, 0);
        m->busy = 1;
        for (i = 0; i < SND->numVoices; i++) {
            v = &SND->voices[i];
            if (v->state >= 2) {
                v->state = 2;
            }
        }
        m->busy = 0;
    }
}

void func_80015A64_16664(s32 arg) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL && m->pause != 0x7F) {
        func_80014768_15368(0, 15, arg);
    }
}

void func_80015AAC_166AC(Snd3DParam* prm) {
    SndMgr* m = func_80014AFC_156FC();

    if (m != NULL) {
        if (prm->flags & 1) {
            m->angle = prm->angle;
        }
        if (prm->flags & 2) {
            m->nearDist = prm->nearDist;
        }
        if (prm->flags & 4) {
            m->farDist = prm->farDist;
        }
        if (prm->flags & 8) {
            m->panNear = prm->panNear;
        }
        if (prm->flags & 0x10) {
            m->panFar = prm->panFar;
        }
        if (prm->flags & 0x20) {
            m->unk44C = prm->unk44C;
        }
        if (prm->flags & 0x40) {
            m->unk450 = prm->unk450;
        }
        if (prm->flags & 0x80) {
            m->unk44A = prm->unk44A;
        }
    }
}

void func_80015B9C_1679C(s32 slot, SndPosParam* pos) {
    SndMgr* m = func_80014AFC_156FC();
    f32 d;
    f32 range;
    s32 val;
    s32 angle;

    if (m != NULL) {
        if (pos->flags & 2) {
            d = pos->dist;
            if (d < 0.0f) {
                d = -d;
            }
            d -= m->nearDist;
            if (d < 0.0f) {
                d = 0.0f;
            }
            range = m->farDist - m->nearDist;
            val = 0;
            if (d <= range) {
                val = (range - d) * 128.0f / range;
                if (val >= 0x80) {
                    val = 0x7F;
                }
            }
            func_80014768_15368(slot, 16, val);
        }
        if (pos->flags & 1) {
            val = m->angle + pos->angle;
            if (val >= 360) {
                val -= 360;
            }
            angle = val << 7;
            if (val >= 181) {
                val = 360 - val;
                angle = val << 7;
            }
            val = angle / 180;
            if (val >= 0x80) {
                val = 0x7F;
            }
            range = m->panFar;
            if (range != 0.0f) {
                d = pos->dist;
                if (d < 0.0f) {
                    d = -d;
                }
                d -= m->panNear;
                if (d < 0.0f) {
                    d = 0.0f;
                }
                if (d < range) {
                    val = 64.0f - (0x40 - val) * (d / range);
                }
            }
            func_80014768_15368(slot, 17, val);
        }
    }
}
