#include "common.h"

/* Audio driver (MP3 src/1140.c is the same code, asm there). First half (w1-C): sound system
   init and bank-header loading, the music sequence players and their command queue, the
   oscillators (MP1 src/B980.c), the sound-bank loaders and the sound-effect command processor.
   Host concerns (N64 code kept as is): the bank loaders relocate 32-bit file offsets into pointers
   in place (ALSound/ALWaveTable fields, SndDef and the penv offset tables), and SndConfig.fxd
   holds a ROM address before it holds the loaded table. */

/* Sequence-player oscillator (MP1 B980Osc). */
typedef struct ECE0Osc {
    /* 0x00 */ struct ECE0Osc* next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 stateFlags;
    /* 0x06 */ u16 maxCount;
    /* 0x08 */ u16 curCount;
    /* 0x0C */ union {
        struct { u8 halfdepth; u8 baseVol; } tsin;
        struct { u8 curVal; u8 hiVal; u8 loVal; } tsqr;
        struct { u8 baseVol; u8 depth; } tsaw;
        struct { f32 depthcents; } vsin;
        struct { f32 loRatio; f32 hiRatio; } vsqr;
        struct { s32 cents; s32 centsrange; } vsaw;
    } data;
} ECE0Osc; // size 0x14

typedef struct {
    /* 0x00 */ s8 cmdType;
    /* 0x01 */ s8 voiceSlot;
    /* 0x04 */ s32 cmdArg;
} AudioCmd; // size 0x8

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

/* SndState as func_80014520_15120 reads it: bank is cfg.sbfRom, heap is hdrBuf. */
typedef struct SndInitParam {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ void* bank;
    /* 0x10 */ char unk10[0x44];
    /* 0x54 */ s32 numVoices;
    /* 0x58 */ s32 maxEvents;
    /* 0x5C */ char unk5C[0x10];
    /* 0x6C */ void* heap;
} SndInitParam;

/* w1-C */
/* Sound-system configuration (MP2 1D0B0's UnkSndConfig): bit N of `flags` says field N is set.
   The MBF/SBF/FXD fields are ROM addresses of the music, sound and effect bank headers. */
typedef struct SndConfig {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 loaded;     // bit 0: FXD effect table loaded, bit 1: from the music bank
    /* 0x08 */ u32 mbfRom;     // music bank file ("MBF0")
    /* 0x0C */ u32 sbfRom;     // sound bank file ("SBF0")
    /* 0x10 */ u32 fxdRom;     // effect table file ("FXD0" header + 0x208-byte records)
    /* 0x14 */ u8* heapBase;
    /* 0x18 */ s32 heapSize;
    /* 0x1C */ s32 outputRate; // synthesizer output rate
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 fxdIndex;   // 1-based effect record to load
    /* 0x2C */ void* fxd;      // a ROM address, then the loaded table (host: pointer in a ROM-address slot)
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 seqMaxVoices;
    /* 0x50 */ s32 seqMaxEvents;
    /* 0x54 */ s32 sndMaxVoices;
    /* 0x58 */ s32 sndMaxEvents;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ OSPiHandle* piHandle;
} SndConfig; // size 0x6C

typedef struct SndState {
    /* 0x00 */ SndConfig cfg;
    /* 0x6C */ u8* hdrBuf;     // 0x40-byte header scratch buffer
    /* 0x70 */ s16 fxdCount;
    /* 0x72 */ s16 unk72;
    /* 0x74 */ s16 fxdId;
} SndState;

/* Bank file header at mbfRom/sbfRom (0x40 bytes). */
typedef struct SndBankHdr {
    /* 0x00 */ s32 magic;
    /* 0x04 */ s32 count;      // sequences (MBF) or sounds (SBF)
    /* 0x08 */ char unk08[8];
    /* 0x10 */ s16 maxVoices;
    /* 0x12 */ s16 maxEvents;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 fxdIndex;
    /* 0x1C */ s32 fxdOfs;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s8 unk24;
    /* 0x25 */ s8 unk25;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s8 unk28;
} SndBankHdr;

/* Music: one entry per sequence in the MBF. */
typedef struct SeqEntry {
    /* 0x00 */ u8 flags;       // low nibble: player, high nibble: ...
    /* 0x01 */ u8 vol;
    /* 0x02 */ u8 bank;        // ALBank index in the bank file
    /* 0x03 */ s8 bankFile;    // SeqBankFile index
    /* 0x04 */ u8 fade;
    /* 0x05 */ char unk05[3];
    /* 0x08 */ u32 rom;
    /* 0x0C */ s32 size;
} SeqEntry; // size 0x10

typedef struct SeqBankFile {
    /* 0x00 */ u32 ctlRom;
    /* 0x04 */ s32 ctlSize;
    /* 0x08 */ u32 tblRom;
    /* 0x0C */ char unk0C[4];
} SeqBankFile; // size 0x10

typedef struct SeqPlayer {
    /* 0x00 */ ALSeqPlayer* seqp;
    /* 0x04 */ u8* seqData;
    /* 0x08 */ ALBankFile* bankFile;
    /* 0x0C */ ALCSeq* cseq;
    /* 0x10 */ s32 seqBufSize;
    /* 0x14 */ s32 flags;
    /* 0x18 */ s16 curSeq;
    /* 0x1A */ s16 reqSeq;
    /* 0x1C */ s32 state;      // alCSPGetState
    /* 0x20 */ s32 status;     // 0 idle, 1 stopped, 2 paused, 3 starting, 4 playing
    /* 0x24 */ s32 fadeStep;
    /* 0x28 */ s32 fadeTimer;  // > 0 fading out, < 0 fading in
    /* 0x2C */ s8 fadeVol;
    /* 0x2D */ s8 curBankFile;
    /* 0x2E */ s8 seqVol;
    /* 0x2F */ s8 vol;
    /* 0x30 */ s8 waitPlayer;
    /* 0x31 */ u8 waitFade;    // fade-in frames / 10 once waitPlayer stops
    /* 0x32 */ s8 unk32;
} SeqPlayer; // size 0x34

typedef struct SeqMgr {
    /* 0x000 */ SeqPlayer* players;
    /* 0x004 */ SeqEntry* seqs;
    /* 0x008 */ SeqBankFile* bankFiles;
    /* 0x00C */ s32 busy;
    /* 0x010 */ s8 numPlayers;
    /* 0x011 */ s8 numActive;
    /* 0x012 */ s8 masterVol;
    /* 0x013 */ s8 unk13;
    /* 0x014 */ s16 numSeqs;
    /* 0x016 */ s16 cmdIdx;
    /* 0x018 */ AudioCmd cmds[0x40];
} SeqMgr; // size 0x218

/* Optional arguments of func_80010E74_11A74 (start a sequence). */
typedef struct SeqPlayArgs {
    /* 0x00 */ s32 flags;      // 1: player, 2: exclusive, 4: volume, 8: fade-in frames
    /* 0x04 */ s32 player;
    /* 0x08 */ s32 exclusive;
    /* 0x0C */ s32 vol;
    /* 0x10 */ s32 fadeIn;
} SeqPlayArgs;

/* Channel state read back by func_80011738_12338. */
typedef struct SeqChlInfo {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ s32 program;
    /* 0x08 */ s32 vol;
    /* 0x0C */ s32 pan;
    /* 0x10 */ s32 fxmix;
} SeqChlInfo;

/* Sound bank table header read by func_80014520_15120 (offsets relative to the bank's ROM address). */
typedef struct SndBankInfo {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ s32 numSounds;
    /* 0x08 */ u32 soundsRom;
    /* 0x0C */ s32 soundsSize;
    /* 0x10 */ char unk10[4];
    /* 0x14 */ u32 tblRom;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s32 numGroups;
    /* 0x20 */ u32 groupsRom;
    /* 0x24 */ s32 groupsSize;
    /* 0x28 */ s32 numUnk10;
    /* 0x2C */ u32 unk10Rom;
    /* 0x30 */ s32 unk10Size;
} SndBankInfo;

extern OSMesg D_800D5770_D6370[];
extern OSMesgQueue D_800D5838_D6438;
extern ALHeap D_800D5850_D6450;
extern SndState D_800D5860_D6460;
extern SeqMgr* D_800D58D8_D64D8;
extern ECE0Osc* D_800D58DC_D64DC;
extern ECE0Osc* D_800D58E0_D64E0;
extern SndMgr* D_800D58E4_D64E4;
extern u8 D_800F8428_F9028;

s32 func_8000E3FC_EFFC(SndConfig*);
void func_8000EB3C_F73C(void* dst, u32 rom, s32 size, s32 chunk);
void* func_8000EC10_F810(s32 size);
s32 func_8000F968_10568(SndConfig*, ALHeap*, s32, s32);
s32 func_80014520_15120(SndInitParam*, ALHeap*, s32, s8);
SndMgr* func_80014AFC_156FC(void);
void func_80014A60_15660(void);
void func_80014B08_15708(void);
s32 func_80015DB0_169B0(SndConfig*, ALHeap*);
void func_800160FC_16CFC(SndConfig*);
void func_80016190_16D90(SndConfig*);
s32 func_8009F830_A0430(ALSeqPlayer*);
void func_8009F980_A0580(ALSeqPlayer*, ALSeqpConfig*);
SeqMgr* func_800100FC_10CFC(void);
void func_80010070_10C70(void);
void func_80010108_10D08(void);
s32 func_80010114_10D14(ECE0Osc** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);
s32 func_80010570_11170(void* oscState, f32* updateVal);
f32 func_80010E14_11A14(u8 depth);
f32 __sinf(f32);
void func_80010DFC_119FC(ECE0Osc* osc);
SndState* func_8000E9DC_F5DC(void);
void func_8001240C_1300C(SndVoice*);
s32 func_80010E74_11A74(s32 id, SeqPlayArgs* args);
void func_8000FE48_10A48(s32 player, s32 type, s32 arg);

s32 func_8000EC8C_F88C(s32, s32);


void func_8000E0E0_ECE0(SndBankHdr* hdr, u32 rom) {
    SndState* st = &D_800D5860_D6460;

    if (!(st->cfg.flags & 0x10)) {
        st->cfg.outputRate = hdr->unk14;
    }
    if (!(st->cfg.flags & 0x20)) {
        st->cfg.unk20 = hdr->unk16;
    }
    if (!(st->cfg.flags & 0x40)) {
        st->cfg.unk24 = hdr->unk18;
    }
    if (!(st->cfg.flags & 0x80)) {
        st->cfg.fxdIndex = hdr->fxdIndex;
    }
    if (!(st->cfg.flags & 0x200)) {
        st->cfg.unk30 = hdr->unk20;
    }
    if (!(st->cfg.flags & 0x400)) {
        st->cfg.unk34 = hdr->unk24;
    }
    if (!(st->cfg.flags & 0x800)) {
        st->cfg.unk38 = hdr->unk22;
    }
    if (!(st->cfg.flags & 0x1000)) {
        st->cfg.unk3C = hdr->unk25;
    }
    if (!(st->cfg.flags & 0x8000)) {
        st->cfg.unk48 = hdr->unk26;
    }
    if (!(st->cfg.flags & 0x100)) {
        st->cfg.fxd = NULL;
        if (hdr->fxdOfs != 0) {
            st->cfg.fxd = (void*)(rom + hdr->fxdOfs);
        }
    }
}

// register allocation and two reloads (masked 11)
#ifdef NON_MATCHING
s32 func_8000E1F0_EDF0(void) {
    SndState* st = &D_800D5860_D6460;
    s32* buf = (s32*)D_800D5860_D6460.hdrBuf;
    u32 rom;
    s32 size;

    D_800D5860_D6460.fxdId = 0;
    D_800D5860_D6460.fxdCount = 0;
    st->cfg.loaded &= ~3;
    if (st->cfg.fxdRom != 0) {
        func_8000EB3C_F73C(buf, st->cfg.fxdRom, 0x10, 0);
        if (buf[0] == 'FXD0') {
            D_800D5860_D6460.fxdCount = ((u16*)buf)[3];
        }
    }
    if (st->cfg.flags & 0x100) {
        if (st->cfg.fxd != NULL) {
            st->cfg.loaded |= 3;
            return 0;
        }
    } else {
        rom = (u32)st->cfg.fxd;
        if (rom == 0) {
            goto find;
        }
        st->cfg.loaded |= 1;
        goto load;
    }
find:
    if (D_800D5860_D6460.fxdCount == 0 || st->cfg.fxdIndex == 0) {
        return 0;
    }
    if (D_800D5860_D6460.fxdCount < st->cfg.fxdIndex) {
        return 1;
    }
    rom = (st->cfg.fxdIndex - 1) * 0x208 + 0x10 + st->cfg.fxdRom;
    st->cfg.loaded |= 2;
load:
    func_8000EB3C_F73C(buf, rom, 4, 0);
    D_800D5860_D6460.fxdId = *(s16*)buf;
    buf[0] = ((u8*)buf)[3];
    size = (buf[0] << 5) | 8;
    if ((st->cfg.fxd = func_8000EC10_F810(size)) == NULL) {
        return 2;
    }
    func_8000EB3C_F73C(st->cfg.fxd, rom, size, 0);
    ((s32*)st->cfg.fxd)[0] = ((u8*)st->cfg.fxd)[3];
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E1F0_EDF0);

#endif

void func_8000E38C_EF8C(SndConfig* cfg) {
    osCreateMesgQueue(&D_800D5838_D6438, D_800D5770_D6370, 50);
    bzero(&D_800D5860_D6460, sizeof(SndConfig));
    D_800D5860_D6460.cfg.unk40 = 1;
    D_800D5860_D6460.cfg.unk44 = 60;
    D_800F8428_F9028 = 0;
    func_8000E3FC_EFFC(cfg);
}

s32 func_8000E3FC_EFFC(SndConfig* cfg) {
    SndConfig* st;
    SndBankHdr* hdr;
    s32 mbfCount = 0;
    s32 sbfCount;
    s32 ret;
    s32 mbfArg;
    s32 sbfArg;

    st = &D_800D5860_D6460.cfg;
    sbfCount = 0;

    if (cfg->flags < 0) {
        st->flags = 0;
        cfg->flags &= 0x7FFFFFFF;
    }
    if (cfg->flags & 0x40000000) {
        st->flags &= ~0x184;
        cfg->flags &= 0xBFFFFFFF;
    }
    if (cfg->flags & 8) {
        st->heapBase = cfg->heapBase;
        st->heapSize = cfg->heapSize;
    }
    if (st->heapBase == NULL || st->heapSize == 0) {
        return 1;
    }
    alHeapInit(&D_800D5850_D6450, st->heapBase, st->heapSize);
    if (cfg->flags & 0x800000) {
        st->piHandle = cfg->piHandle;
    } else if (!(st->flags & 0x800000)) {
        st->piHandle = osCartRomInit();
    }
    hdr = func_8000EC10_F810(0x40);
    D_800D5860_D6460.hdrBuf = (u8*)hdr;
    if (hdr == NULL) {
        return 2;
    }
    if (cfg->flags & 1) {
        if ((st->mbfRom = cfg->mbfRom) != 0) {
            st->flags = 0;
        }
    }
    if (cfg->flags & 2) {
        st->sbfRom = cfg->sbfRom;
        if (!(cfg->flags & 1) && st->sbfRom != 0) {
            st->flags = 0;
        }
    }
    if (st->mbfRom == 0 && st->sbfRom == 0) {
        return 3;
    }
    if (st->sbfRom != 0) {
        func_8000EB3C_F73C(hdr, st->sbfRom, 0x40, 0);
        if (hdr->magic == 'SBF0') {
            if (st->mbfRom == 0) {
                func_8000E0E0_ECE0(hdr, st->sbfRom);
            }
            st->sndMaxVoices = hdr->maxVoices;
            st->sndMaxEvents = hdr->maxEvents;
            sbfArg = hdr->unk28;
            sbfCount = hdr->count;
        }
    }
    if (st->mbfRom != 0) {
        func_8000EB3C_F73C(hdr, st->mbfRom, 0x40, 0);
        if (hdr->magic == 'MBF0') {
            func_8000E0E0_ECE0(hdr, st->mbfRom);
            st->seqMaxVoices = hdr->maxVoices;
            st->seqMaxEvents = hdr->maxEvents;
            mbfArg = hdr->unk28;
            mbfCount = hdr->count;
        }
    }
    if (cfg->flags & 4) {
        st->fxdRom = cfg->fxdRom;
    }
    if (cfg->flags & 0x10) {
        st->outputRate = cfg->outputRate;
    }
    if (cfg->flags & 0x20) {
        st->unk20 = cfg->unk20;
    }
    if (cfg->flags & 0x40) {
        st->unk24 = cfg->unk24;
    }
    if (cfg->flags & 0x80) {
        st->fxdIndex = cfg->fxdIndex;
    }
    if (cfg->flags & 0x100) {
        st->fxd = cfg->fxd;
    }
    if (cfg->flags & 0x200) {
        st->unk30 = cfg->unk30;
    }
    if (cfg->flags & 0x400) {
        st->unk34 = cfg->unk34;
    }
    if (cfg->flags & 0x800) {
        st->unk38 = cfg->unk38;
    }
    if (cfg->flags & 0x1000) {
        st->unk3C = cfg->unk3C;
    }
    if (cfg->flags & 0x2000) {
        st->unk40 = cfg->unk40;
    }
    if (cfg->flags & 0x4000) {
        st->unk44 = cfg->unk44;
    }
    if (cfg->flags & 0x8000) {
        st->unk48 = cfg->unk48;
    }
    if (cfg->flags & 0x10000) {
        st->seqMaxVoices = cfg->seqMaxVoices;
    }
    if (cfg->flags & 0x20000) {
        st->seqMaxEvents = cfg->seqMaxEvents;
    }
    if (cfg->flags & 0x40000) {
        st->sndMaxVoices = cfg->sndMaxVoices;
    }
    if (cfg->flags & 0x80000) {
        st->sndMaxEvents = cfg->sndMaxEvents;
    }
    if (cfg->flags & 0x100000) {
        st->unk5C = cfg->unk5C;
    }
    if (cfg->flags & 0x200000) {
        st->unk60 = cfg->unk60;
    }
    if (cfg->flags & 0x400000) {
        st->unk64 = cfg->unk64;
    }
    st->flags |= cfg->flags;
    if ((cfg->flags & 0x100) && cfg->fxd == NULL) {
        st->flags &= ~0x100;
    }
    if ((ret = func_8000E1F0_EDF0()) != 0) {
        return ret + 100;
    }
    if ((ret = func_80015DB0_169B0(st, &D_800D5850_D6450)) != 0) {
        return ret + 200;
    }
    if ((ret = func_8000F968_10568(&D_800D5860_D6460.cfg, &D_800D5850_D6450, mbfCount, mbfArg)) != 0) {
        return ret + 300;
    }
    if ((ret = func_80014520_15120((SndInitParam*)&D_800D5860_D6460, &D_800D5850_D6450, sbfCount, sbfArg)) != 0) {
        return ret + 400;
    }
    func_8000EC8C_F88C(100, 0);
    func_800160FC_16CFC(st);
    return 0;
}

s32 func_8000E930_F530(void) {
    SeqMgr* seq = func_800100FC_10CFC();
    SndMgr* snd;

    if (seq != NULL && seq->numActive != 0) {
        return 1;
    }
    snd = func_80014AFC_156FC();
    if (snd != NULL) {
        if (snd->active != 0) {
            return 1;
        }
        func_80014A60_15660();
    }
    if (seq != NULL) {
        func_80010070_10C70();
    }
    func_80016190_16D90(&func_8000E9DC_F5DC()->cfg);
    if (seq != NULL) {
        func_80010108_10D08();
    }
    if (snd != NULL) {
        func_80014B08_15708();
    }
    return 0;
}

SndState* func_8000E9DC_F5DC(void) {
    return &D_800D5860_D6460;
}

void func_8000E9E8_F5E8(SndConfig* out) {
    u8* src = (u8*)func_8000E9DC_F5DC();
    u32 i;

    for (i = 0; i < sizeof(SndConfig); i++) {
        ((u8*)out)[i] = src[i];
    }
}

s16 func_8000EA34_F634(void) {
    return func_8000E9DC_F5DC()->fxdCount;
}

s32 func_8000EA54_F654(void) {
    return 0x610103;
}

s32 func_8000EA60_F660(void) {
    return 0;
}

s16 func_8000EA68_F668(void) {
    return func_8000E9DC_F5DC()->unk72;
}

void func_8000EA88_F688(s32 mono) {
    SndMgr* snd;
    s32 i;

    D_800F8428_F9028 = mono & 1;
    snd = func_80014AFC_156FC();
    if (snd != NULL) {
        for (i = 0; i < snd->numVoices; i++) {
            if (snd->voices[i].flags & 3) {
                snd->voices[i].flags |= 0x20;
            } else {
                snd->voices[i].flags |= 0x8000;
            }
        }
    }
}

s16 func_8000EB1C_F71C(void) {
    return func_8000E9DC_F5DC()->fxdId;
}

void func_8000EB3C_F73C(void* dst, u32 rom, s32 size, s32 chunk) {
    OSIoMesg mesg;
    u32 r = rom;
    u8* p = dst;
    s32 left = size;
    s32 n;

    if (chunk == 0) {
        chunk = left;
    }
    chunk += chunk & 1;
    while (left != 0) {
        n = left;
        if (chunk < left) {
            n = chunk;
        }
        mesg.hdr.pri = OS_MESG_PRI_NORMAL;
        mesg.hdr.retQueue = &D_800D5838_D6438;
        mesg.dramAddr = p;
        mesg.devAddr = r;
        mesg.size = n;
        osInvalDCache(p, n);
        osEPiStartDma(D_800D5860_D6460.cfg.piHandle, &mesg, OS_READ);
        osRecvMesg(&D_800D5838_D6438, NULL, OS_MESG_BLOCK);
        r += n;
        left -= n;
        p += n;
    }
}

void* func_8000EC10_F810(s32 size) {
    void* p = alHeapDBAlloc(NULL, 0, &D_800D5850_D6450, 1, size);

    if (p == NULL) {
        func_8000EC8C_F88C(0, 1);
    }
    return p;
}

void func_8000EC64_F864(s16 arg0) {
    func_8000E9DC_F5DC()->unk72 = arg0;
}

s32 func_8000EC8C_F88C(s32 arg0, s32 arg1) {
    return 0;
}

s16 func_8000EC94_F894(s32 vol) {
    return (vol > 0) ? ((vol << 8) | 0xFF) : 0;
}

void func_8000ECB8_F8B8(SeqPlayer* p, s8 bankFile, s32 chunk) {
    SeqBankFile* bf;
    SeqPlayer* other;
    s32 i;

    if (p->curBankFile == bankFile) {
        return;
    }
    bf = &D_800D58D8_D64D8->bankFiles[bankFile];
    for (i = 0; i < D_800D58D8_D64D8->numPlayers; i++) {
        other = &D_800D58D8_D64D8->players[i];
        if (other->curBankFile == bankFile) {
            bcopy(other->bankFile, p->bankFile, bf->ctlSize);
            p->curBankFile = bankFile;
            return;
        }
    }
    func_8000EB3C_F73C(p->bankFile, bf->ctlRom, bf->ctlSize, chunk);
    alBnkfNew(p->bankFile, (u8*)bf->tblRom);
    p->curBankFile = bankFile;
}

void func_8000EDA4_F9A4(SeqPlayer* p) {
    SeqEntry* e;

    if (p->curSeq != p->reqSeq) {
        p->curSeq = p->reqSeq;
        e = &D_800D58D8_D64D8->seqs[p->reqSeq];
        func_8000EB3C_F73C(p->seqData, e->rom, e->size, 0x4000);
    }
    alCSeqNew(p->cseq, p->seqData);
    alSeqpSetSeq(p->seqp, (ALSeq*)p->cseq);
}

s32 func_8000EE1C_FA1C(SeqPlayer* p) {
    return D_800D58D8_D64D8->unk13 * p->vol * p->seqVol * p->fadeVol / 2048383 * D_800D58D8_D64D8->masterVol / 127;
}

void func_8000EEA0_FAA0(SeqPlayer* p, s32 frames) {
    s32 flags = p->flags;

    if (!(flags & 0x40)) {
        p->flags = flags & ~8;
        if (!(flags & 1)) {
            if (frames != 0 && p->fadeTimer <= 0) {
                p->fadeTimer = (frames > 0) ? -frames : -1;
                p->fadeStep = 0x7F000000 / -p->fadeTimer;
                p->fadeVol = 0;
                alSeqpSetVol(p->seqp, 0);
            }
            p->flags |= 0x10;
        }
    }
}

void func_8000EF60_FB60(void) {
    AudioCmd* cmd;
    SeqPlayer* p;
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < D_800D58D8_D64D8->cmdIdx; i++) {
        cmd = &D_800D58D8_D64D8->cmds[i];
        p = &D_800D58D8_D64D8->players[cmd->voiceSlot];
        switch (cmd->cmdType) {
            case 0:
                p->flags |= 2;
                break;
            case 1:
                p->flags = (p->flags & ~0x18) | 1;
                p->reqSeq = cmd->cmdArg;
                p->unk32 = 0;
                break;
            case 2:
                p->vol = cmd->cmdArg;
                if (p->flags & 3) {
                    p->flags |= 4;
                } else {
                    alSeqpSetVol(p->seqp, func_8000EC94_F894(func_8000EE1C_FA1C(p)));
                }
                break;
            case 3:
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    p->vol = cmd->cmdArg;
                    if (p->flags & 3) {
                        p->flags |= 4;
                    } else {
                        alSeqpSetVol(p->seqp, func_8000EC94_F894(func_8000EE1C_FA1C(p)));
                    }
                }
                break;
            case 4:
                D_800D58D8_D64D8->masterVol = cmd->cmdArg;
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    p->fadeTimer = 0;
                    p->fadeVol = 0x7F;
                    alSeqpSetVol(p->seqp, func_8000EC94_F894(func_8000EE1C_FA1C(p)));
                }
                break;
            case 6:
                if (!(p->flags & 1)) {
                    alSeqpStop(p->seqp);
                    p->status = 1;
                }
                p->flags = 0;
                break;
            case 7:
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    if (!(p->flags & 1)) {
                        alSeqpStop(p->seqp);
                        p->status = 1;
                    }
                    p->flags = 0;
                }
                break;
            case 8:
                n = cmd->cmdArg;
                if (n <= 0) {
                    n = 1;
                }
                p->fadeTimer = n;
                p->fadeStep = 0x7F000000 / n;
                p->fadeVol = 0x7F;
                break;
            case 9:
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    if (p->status >= 3) {
                        n = cmd->cmdArg;
                        if (n <= 0) {
                            n = 1;
                        }
                        p->fadeTimer = n;
                        p->fadeStep = 0x7F000000 / n;
                        p->fadeVol = 0x7F;
                    }
                }
                break;
            case 10:
                if (!(p->flags & 1)) {
                    alSeqpStop(p->seqp);
                }
                p->flags = (p->flags | 8) & ~0x10;
                break;
            case 11:
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    if (!(p->flags & 1)) {
                        alSeqpStop(p->seqp);
                    }
                    p->flags = (p->flags | 8) & ~0x10;
                }
                break;
            case 12:
                func_8000EEA0_FAA0(p, cmd->cmdArg);
                break;
            case 13:
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    p = &D_800D58D8_D64D8->players[j];
                    if (p->flags & 8) {
                        func_8000EEA0_FAA0(p, cmd->cmdArg);
                    }
                }
                break;
            case 14:
                if (cmd->cmdArg != 0) {
                    p->fadeTimer = (cmd->cmdArg > 0) ? -cmd->cmdArg : -1;
                    p->fadeStep = 0x7F000000 / -p->fadeTimer;
                    p->fadeVol = 0;
                    if (p->flags & 3) {
                        p->flags |= 0x20;
                    } else {
                        alSeqpSetVol(p->seqp, 0);
                    }
                }
                break;
            case 15:
                p->flags = (p->flags & ~0x18) | 1;
                p->reqSeq = cmd->cmdArg;
                p->unk32 = 1;
                for (j = 0; j < D_800D58D8_D64D8->numPlayers; j++) {
                    if (j != cmd->voiceSlot) {
                        p = &D_800D58D8_D64D8->players[j];
                        if (p->status >= 2) {
                            if (p->status == 4) {
                                alSeqpStop(p->seqp);
                            }
                            p->flags = (p->flags | 8) & ~0x10;
                            p->fadeTimer = 0;
                            p->waitPlayer = cmd->voiceSlot;
                            p->waitFade = D_800D58D8_D64D8->seqs[p->reqSeq].fade;
                            p->flags |= 0x40;
                        }
                    }
                }
                break;
        }
    }
    D_800D58D8_D64D8->cmdIdx = 0;
}

void func_8000F634_10234(SeqPlayer* p) {
    s32 state;

    p->state = state = func_8009F830_A0430(p->seqp);
    switch (state) {
        case 1:
            if (p->status != 1) {
                p->status = 4;
            }
            break;
        case 2:
            p->status = 1;
            break;
        default:
            p->status = 0;
            break;
    }
}

void func_8000F69C_1029C(SeqPlayer* p) {
    switch (p->state) {
        case 1:
        case 2:
            if (p->flags & 0x10) {
                p->status = 4;
            }
            if (p->flags & 8) {
                p->status = 2;
            }
            break;
        default:
            if (p->flags & 8) {
                p->status = 2;
            }
            if (p->flags & 0x10) {
                alSeqpPlay(p->seqp);
                p->flags &= ~0x10;
                p->status = 4;
            }
            break;
    }
}

void func_8000F744_10344(SeqPlayer* p) {
    SeqEntry* e;
    s32 vol;
    s32 flags;

    if (p->flags & 1) {
        p->status = 3;
        if (p->state == 1) {
            alSeqpStop(p->seqp);
        } else if (p->state != 2) {
            e = &D_800D58D8_D64D8->seqs[p->reqSeq];
            func_8000ECB8_F8B8(p, e->bankFile, 0x4000);
            alSeqpSetBank(p->seqp, p->bankFile->bankArray[e->bank]);
            func_8000EDA4_F9A4(p);
            p->seqVol = e->vol;
            if (!(p->flags & 4)) {
                p->vol = 0x7F;
            }
            if (!(p->flags & 0x20)) {
                p->fadeVol = 0x7F;
                p->fadeTimer = 0;
                vol = func_8000EE1C_FA1C(p);
            } else {
                vol = 0;
            }
            vol = func_8000EC94_F894(vol);
            alSeqpSetVol(p->seqp, vol);
            flags = p->flags;
            p->flags = flags & ~0x67;
            if (!(flags & 8)) {
                alSeqpPlay(p->seqp);
                p->status = 4;
            }
        }
    }
}

void func_8000F878_10478(SeqPlayer* p) {
    s32 v;

    if (p->fadeTimer > 0) {
        if (--p->fadeTimer != 0) {
            v = (p->fadeStep * p->fadeTimer) >> 24;
            if (v != p->fadeVol) {
                p->fadeVol = v;
                alSeqpSetVol(p->seqp, func_8000EC94_F894(func_8000EE1C_FA1C(p)));
            }
        } else {
            alSeqpStop(p->seqp);
            p->status = 1;
        }
    }
    if (p->fadeTimer < 0) {
        if (++p->fadeTimer != 0) {
            v = 0x7F - ((-p->fadeTimer * p->fadeStep) >> 24);
        } else {
            v = 0x7F;
        }
        if (v != p->fadeVol) {
            p->fadeVol = v;
            alSeqpSetVol(p->seqp, func_8000EC94_F894(func_8000EE1C_FA1C(p)));
        }
    }
}

// register allocation: heap spilled instead of kept in fp, frame 8 bytes larger (masked 38)
#ifdef NON_MATCHING
s32 func_8000F968_10568(SndConfig* cfg, ALHeap* heap, s32 numSeqs, s32 arg3) {
    s32 sizes[5];
    ALSeqpConfig seqc;
    SeqEntry* e;
    SeqBankFile* bf;
    SeqPlayer* p;
    ECE0Osc* osc;
    ALBankFile* bank;
    s32 maxBankFile;
    s32 maxPlayer;
    s32 maxCtl;
    s32 n;
    s32 i;

    if (numSeqs == 0) {
        D_800D58D8_D64D8 = NULL;
        return 0;
    }
    if ((D_800D58D8_D64D8 = func_8000EC10_F810(sizeof(SeqMgr))) == NULL) {
        return 1;
    }
    bzero(sizes, sizeof(sizes));
    n = numSeqs * sizeof(SeqEntry);
    if ((D_800D58D8_D64D8->seqs = func_8000EC10_F810(n)) == NULL) {
        return 2;
    }
    func_8000EB3C_F73C(D_800D58D8_D64D8->seqs, cfg->mbfRom + 0x40, n, 0);
    maxBankFile = 0;
    maxPlayer = 0;
    for (i = 0; i < numSeqs; i++) {
        e = &D_800D58D8_D64D8->seqs[i];
        if (e->rom != 0 && e->size != 0) {
            e->rom += cfg->mbfRom;
            n = e->flags & 0xF;
            if (maxPlayer < n) {
                maxPlayer = n;
            }
            if (sizes[n] < e->size) {
                sizes[n] = e->size;
            }
            if (maxBankFile < e->bankFile) {
                maxBankFile = e->bankFile;
            }
        }
    }
    maxBankFile++;
    maxPlayer++;
    n = maxBankFile * sizeof(SeqBankFile);
    if ((D_800D58D8_D64D8->bankFiles = func_8000EC10_F810(n)) == NULL) {
        return 3;
    }
    func_8000EB3C_F73C(D_800D58D8_D64D8->bankFiles, numSeqs * sizeof(SeqEntry) + 0x40 + cfg->mbfRom, n, 0);
    maxCtl = 0;
    for (i = 0; i < maxBankFile; i++) {
        bf = &D_800D58D8_D64D8->bankFiles[i];
        bf->ctlRom += cfg->mbfRom;
        bf->tblRom += cfg->mbfRom;
        if (maxCtl < bf->ctlSize) {
            maxCtl = bf->ctlSize;
        }
    }
    bank = NULL;
    if (maxBankFile == 1) {
        if ((bank = func_8000EC10_F810(maxCtl)) == NULL) {
            return 4;
        }
        func_8000EB3C_F73C(bank, bf->ctlRom, bf->ctlSize, 0);
        alBnkfNew(bank, (u8*)bf->tblRom);
    }
    seqc.maxVoices = cfg->seqMaxVoices;
    seqc.maxEvents = cfg->seqMaxEvents;
    seqc.maxChannels = 16;
    seqc.debugFlags = 0;
    seqc.heap = heap;
    seqc.initOsc = (ALOscInit)func_80010114_10D14;
    seqc.updateOsc = (ALOscUpdate)func_80010570_11170;
    seqc.stopOsc = (ALOscStop)func_80010DFC_119FC;
    if ((D_800D58D8_D64D8->players = func_8000EC10_F810(maxPlayer * sizeof(SeqPlayer))) == NULL) {
        return 5;
    }
    for (i = 0; i < maxPlayer; i++) {
        p = &D_800D58D8_D64D8->players[i];
        p->flags = 0;
        p->status = 0;
        p->fadeTimer = 0;
        p->curSeq = -1;
        if ((p->seqp = func_8000EC10_F810(0x7C /* the ALCSPlayer */)) == NULL) {
            return 6;
        }
        func_8009F980_A0580(p->seqp, &seqc);
        if ((p->cseq = func_8000EC10_F810(sizeof(ALCSeq))) == NULL) {
            return 7;
        }
        if (sizes[i] & 1) {
            sizes[i]++;
        }
        if ((p->seqData = func_8000EC10_F810(sizes[i])) == NULL) {
            return 8;
        }
        p->seqBufSize = sizes[i];
        if (bank != NULL) {
            p->bankFile = bank;
            p->curBankFile = 0;
        } else {
            if ((p->bankFile = func_8000EC10_F810(maxCtl)) == NULL) {
                return 9;
            }
            p->curBankFile = -1;
            D_800D58D8_D64D8->numPlayers = i;
            func_8000ECB8_F8B8(p, 0, 0);
        }
    }
    n = maxPlayer * cfg->seqMaxVoices;
    if ((D_800D58E0_D64E0 = func_8000EC10_F810(n * 0x14)) == NULL) {
        return 10;
    }
    n--;
    osc = D_800D58E0_D64E0;
    D_800D58DC_D64DC = osc;
    for (i = 0; i < n; i++) {
        osc->next = (ECE0Osc*)((u8*)D_800D58E0_D64E0 + (i + 1) * 0x14);
        osc = osc->next;
    }
    osc->next = NULL;
    D_800D58D8_D64D8->numPlayers = maxPlayer;
    D_800D58D8_D64D8->numSeqs = numSeqs;
    D_800D58D8_D64D8->unk13 = arg3;
    D_800D58D8_D64D8->masterVol = 0x7F;
    D_800D58D8_D64D8->cmdIdx = 0;
    D_800D58D8_D64D8->busy = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F968_10568);

#endif

void func_8000FE48_10A48(s32 player, s32 type, s32 arg) {
    u32 mask;
    AudioCmd* cmd;

    mask = osSetIntMask(1);
    cmd = &D_800D58D8_D64D8->cmds[D_800D58D8_D64D8->cmdIdx];
    cmd->cmdType = type;
    cmd->voiceSlot = player;
    cmd->cmdArg = arg;
    if (++D_800D58D8_D64D8->cmdIdx >= 0x40) {
        func_8000EC8C_F88C(0, 0x100);
        D_800D58D8_D64D8->cmdIdx = 0;
    }
    osSetIntMask(mask);
}

void func_8000FEFC_10AFC(void) {
    SeqPlayer* p;
    s32 i;

    if (D_800D58D8_D64D8 != NULL && D_800D58D8_D64D8->busy == 0) {
        D_800D58D8_D64D8->busy = 1;
        func_8000EF60_FB60();
        D_800D58D8_D64D8->numActive = 0;
        for (i = 0; i < D_800D58D8_D64D8->numPlayers; i++) {
            p = &D_800D58D8_D64D8->players[i];
            func_8000F634_10234(p);
            func_8000F744_10344(p);
            func_8000F69C_1029C(p);
            if ((p->flags & 0x40) && D_800D58D8_D64D8->players[p->waitPlayer].status < 2) {
                p->flags &= ~0x40;
                func_8000EEA0_FAA0(p, p->waitFade * 10);
            }
            if (p->status >= 2) {
                D_800D58D8_D64D8->numActive++;
            }
            if (p->status >= 3) {
                func_8000F878_10478(p);
            }
        }
        D_800D58D8_D64D8->busy = 0;
    }
}

void func_80010070_10C70(void) {
    SeqPlayer* p;
    s32 i;

    if (D_800D58D8_D64D8 != NULL) {
        for (i = 0; i < D_800D58D8_D64D8->numPlayers; i++) {
            p = &D_800D58D8_D64D8->players[i];
            alSeqpStop(p->seqp);
            alSeqpDelete(p->seqp);
        }
    }
}

SeqMgr* func_800100FC_10CFC(void) {
    return D_800D58D8_D64D8;
}

void func_80010108_10D08(void) {
    D_800D58D8_D64D8 = NULL;
}

s32 func_80010114_10D14(ECE0Osc** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
    ECE0Osc* osc;
    s32 deltaTime = 0;
    s32 cents;

    if (D_800D58DC_D64DC != NULL) {
        osc = D_800D58DC_D64DC;
        D_800D58DC_D64DC = osc->next;
        osc->type = oscType;
        *oscState = osc;
        deltaTime = oscDelay << 14;
        switch (oscType) {
            case 1:
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127 - osc->data.tsin.halfdepth;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 2:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                osc->data.tsqr.loVal = 127 - oscDepth;
                osc->data.tsqr.hiVal = 127;
                osc->data.tsqr.curVal = 127;
                *initVal = 127.0f;
                break;
            case 3:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                osc->data.tsaw.depth = oscDepth;
                osc->data.tsaw.baseVol = 127;
                *initVal = 127.0f;
                break;
            case 4:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                osc->data.tsaw.depth = oscDepth;
                osc->data.tsaw.baseVol = 127 - oscDepth;
                *initVal = osc->data.tsaw.baseVol;
                break;
            case 5:
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127 - osc->data.tsin.halfdepth;
                osc->stateFlags = 0;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 6:
            case 7:
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127;
                *initVal = 127.0f;
                break;
            case 8:
            case 9:
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127;
                osc->stateFlags = 0;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 0x80:
            case 0x8A:
                osc->data.vsin.depthcents = func_80010E14_11A14(oscDepth);
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                *initVal = 1.0f;
                break;
            case 0x81:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = osc->data.vsqr.hiRatio;
                break;
            case 0x82:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsaw.cents = cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(osc->data.vsaw.cents);
                break;
            case 0x83:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsaw.cents = -cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(osc->data.vsaw.cents);
                break;
            case 0x84:
                osc->data.vsin.depthcents = func_80010E14_11A14(oscDepth);
                osc->stateFlags = 0;
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                *initVal = 1.0f;
                break;
            case 0x85:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = 1.0f;
                break;
            case 0x86:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 1;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = 1.0f;
                break;
            case 0x87:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsaw.cents = cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = 1.0f;
                break;
            case 0x88:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                cents = func_80010E14_11A14(oscDepth);
                osc->data.vsaw.cents = -cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = 1.0f;
                break;
            case 0x89:
                osc->data.vsin.depthcents = func_80010E14_11A14(oscDepth);
                osc->stateFlags = 2;
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                *initVal = 1.0f;
                break;
            default:
                deltaTime = 0xFF << 14;
                break;
        }
    }
    return deltaTime;
}

s32 func_80010570_11170(void* oscState, f32* updateVal) {
    ECE0Osc* osc = oscState;
    f32 tmpFlt;
    s32 deltaTime = 16000;

    switch (osc->type) {
        case 1:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853f;
            tmpFlt = __sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 2:
            if (osc->stateFlags == 0) {
                *updateVal = (f32)osc->data.tsqr.loVal;
                osc->stateFlags = 1;
            } else {
                *updateVal = (f32)osc->data.tsqr.hiVal;
                osc->stateFlags = 0;
            }
            deltaTime *= osc->maxCount;
            break;
        case 3:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.tsaw.depth;
            *updateVal = (f32)osc->data.tsaw.baseVol - tmpFlt;
            break;
        case 4:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.tsaw.depth;
            *updateVal = (f32)osc->data.tsaw.baseVol + tmpFlt;
            break;
        case 5:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 3;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * (f32)osc->data.tsin.halfdepth;
                    break;
                case 2:
                    tmpFlt = -tmpFlt * (f32)osc->data.tsin.halfdepth;
                    break;
                case 3:
                    tmpFlt = (tmpFlt - 1.0f) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 6:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 3.14159265f;
            tmpFlt = __sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            if (tmpFlt < 0.0f) {
                *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            } else {
                *updateVal = (f32)osc->data.tsin.baseVol - tmpFlt;
            }
            break;
        case 7:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 3.14159265f;
            tmpFlt = __sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            if (tmpFlt < 0.0f) {
                *updateVal = (f32)osc->data.tsin.baseVol - tmpFlt;
            } else {
                *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            }
            break;
        case 8:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 1;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt = -tmpFlt * (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (tmpFlt - 1.0f) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 9:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 1;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 0x80:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853f;
            tmpFlt = __sinf(tmpFlt) * osc->data.vsin.depthcents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x81:
        case 0x85:
        case 0x86:
            if (osc->stateFlags == 0) {
                osc->stateFlags = 1;
                *updateVal = osc->data.vsqr.loRatio;
            } else {
                osc->stateFlags = 0;
                *updateVal = osc->data.vsqr.hiRatio;
            }
            deltaTime *= osc->maxCount;
            break;
        case 0x82:
        case 0x87:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.vsaw.centsrange;
            tmpFlt = (f32)osc->data.vsaw.cents - tmpFlt;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x83:
        case 0x88:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.vsaw.centsrange;
            tmpFlt += (f32)osc->data.vsaw.cents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x84:
        case 0x89:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 3;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= osc->data.vsin.depthcents;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * osc->data.vsin.depthcents;
                    break;
                case 2:
                    tmpFlt = -tmpFlt * osc->data.vsin.depthcents;
                    break;
                case 3:
                    tmpFlt = (tmpFlt - 1.0f) * osc->data.vsin.depthcents;
                    break;
            }
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x8A:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853f;
            tmpFlt = __sinf(tmpFlt) * -osc->data.vsin.depthcents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
    }
    return deltaTime;
}

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

s32 func_80010E58_11A58(s32 id) {
    return func_80010E74_11A74(id, NULL);
}

s32 func_80010E74_11A74(s32 id, SeqPlayArgs* args) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqEntry* e;
    SeqPlayer* p;
    s32 player;
    s32 type;

    if (mgr == NULL) {
        return 0;
    }
    if (id >= mgr->numSeqs) {
        return -1;
    }
    e = &mgr->seqs[id];
    player = e->flags & 0xF;
    type = (e->flags & 0xF0) ? 15 : 1;
    p = &mgr->players[player];
    if (e->size > p->seqBufSize) {
        return -1;
    }
    if (args != NULL) {
        if (args->flags & 1) {
            player = args->player;
            if (player >= mgr->numPlayers) {
                return -1;
            }
            p = &mgr->players[player];
        }
        if (args->flags & 2) {
            type = (args->exclusive != 0) ? 15 : 1;
        }
        func_8000FE48_10A48(player, 0, 0);
        if (args->flags & 4) {
            p->vol = args->vol;
            func_8000FE48_10A48(player, 2, args->vol);
        }
        if (args->flags & 8) {
            func_8000FE48_10A48(player, 14, args->fadeIn);
        }
    }
    mgr->busy = 1;
    func_8000FE48_10A48(player, type, id);
    p->status = 3;
    mgr->busy = 0;
    return player;
}

s32 func_80011018_11C18(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->players[player].status;
}

s16 func_80011064_11C64(void) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->numSeqs;
}

s16 func_8001108C_11C8C(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->players[player].curSeq;
}

s8 func_800110D8_11CD8(void) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->numPlayers;
}

s8 func_80011100_11D00(void) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->numActive;
}

// register allocation: mgr and player swap s2/s3 (masked 0)
#ifdef NON_MATCHING
void func_80011128_11D28(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;
    s32 i;

    if (mgr != NULL) {
        if (player < 0) {
            func_8000FE48_10A48(0, 7, 0);
            mgr->busy = 1;
            for (i = 0; i < mgr->numPlayers; i++) {
                p = &mgr->players[i];
                if (p->status >= 2) {
                    p->status = 1;
                }
            }
            mgr->busy = 0;
        } else {
            p = &mgr->players[player];
            if (p->status >= 2) {
                mgr->busy = 1;
                func_8000FE48_10A48(player, 6, 0);
                p->status = 1;
                mgr->busy = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011128_11D28);

#endif

void func_8001122C_11E2C(s32 player, s32 vol) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;
    s32 i;

    if (mgr == NULL) {
        return;
    }
    if (player < 0) {
        func_8000FE48_10A48(0, 3, vol);
        for (i = 0; i < mgr->numPlayers; i++) {
            p = &mgr->players[i];
            if (p->status >= 2) {
                p->vol = vol;
            }
        }
    } else {
        mgr->players[player].vol = vol;
        func_8000FE48_10A48(player, 2, vol);
    }
}

s8 func_80011308_11F08(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->players[player].vol;
}

void func_80011354_11F54(s32 vol) {
    if (func_800100FC_10CFC() != NULL) {
        func_8000FE48_10A48(0, 4, vol);
    }
}

void func_8001138C_11F8C(s32 player, s32 bpm) {
    SeqMgr* mgr = func_800100FC_10CFC();
    f32 t;

    if (mgr != NULL) {
        if (bpm <= 0) {
            bpm = 1;
        }
        t = 60.0f / bpm * 1000.0f * 1000.0f;
        alSeqpSetTempo(mgr->players[player].seqp, t);
    }
}

s32 func_80011430_12030(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;
    s32 tempo;

    if (mgr == NULL) {
        return 0;
    }
    p = &mgr->players[player];
    if (p->status != 4) {
        return 0;
    }
    tempo = alCSPGetTempo((ALCSPlayer*)p->seqp);
    if (tempo != 0) {
        tempo = 60.0f / (tempo / 1000000.0f);
    }
    return tempo;
}

void func_800114E8_120E8(s32 player, s32 frames) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr != NULL) {
        if (player < 0) {
            func_8000FE48_10A48(0, 9, frames);
        } else if (mgr->players[player].status >= 3) {
            func_8000FE48_10A48(player, 8, frames);
        }
    }
}

s32 func_80011568_12168(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();

    if (mgr == NULL) {
        return 0;
    }
    return mgr->players[player].fadeTimer;
}

// register allocation: mgr and player swap s2/s3 (masked 0)
#ifdef NON_MATCHING
void func_800115B4_121B4(s32 player) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;
    s32 i;

    if (mgr != NULL) {
        if (player < 0) {
            func_8000FE48_10A48(0, 11, 0);
            mgr->busy = 1;
            for (i = 0; i < mgr->numPlayers; i++) {
                p = &mgr->players[i];
                if (p->status >= 3) {
                    p->status = 2;
                }
            }
            mgr->busy = 0;
        } else {
            p = &mgr->players[player];
            if (p->status >= 3) {
                mgr->busy = 1;
                func_8000FE48_10A48(player, 10, 0);
                p->status = 2;
                mgr->busy = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_800115B4_121B4);

#endif

void func_800116B4_122B4(s32 player, s32 frames) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;

    if (mgr == NULL) {
        return;
    }
    if (player < 0) {
        func_8000FE48_10A48(0, 13, frames);
    } else {
        p = &mgr->players[player];
        if (p->status == 2) {
            func_8000FE48_10A48(player, 12, frames);
        }
    }
}

void func_80011738_12338(s32 player, s32 chan, SeqChlInfo* info) {
    SeqMgr* mgr = func_800100FC_10CFC();
    SeqPlayer* p;

    if (mgr == NULL) {
        return;
    }
    p = &mgr->players[player];
    if (p->status == 4) {
        info->program = alSeqpGetChlProgram(p->seqp, chan);
        info->vol = alSeqpGetChlVol(p->seqp, chan);
        info->pan = alSeqpGetChlPan(p->seqp, chan);
        info->fxmix = alSeqpGetChlFXMix(p->seqp, chan);
    }
}

s32 func_800117FC_123FC(u32 rom, SndBankInfo* info) {
    ALSound* snd;
    ALWaveTable* w;
    s32 i;

    if ((D_800D58E4_D64E4->sounds = func_8000EC10_F810(info->soundsSize)) == NULL) {
        return 1;
    }
    info->soundsRom = rom + info->soundsRom;
    func_8000EB3C_F73C(D_800D58E4_D64E4->sounds, info->soundsRom, info->soundsSize, 0);
    info->tblRom = rom + info->tblRom;
    for (i = 0; i < info->numSounds; i++) {
        snd = &D_800D58E4_D64E4->sounds[i];
        if (snd->flags) {
            continue;
        }
        snd->flags = 1;
        snd->envelope = (ALEnvelope*)((u8*)snd->envelope + (u32)D_800D58E4_D64E4->sounds);
        w = snd->wavetable = (ALWaveTable*)((u8*)snd->wavetable + (u32)D_800D58E4_D64E4->sounds);
        if (w->flags) {
            continue;
        }
        w->flags = 1;
        w->base += info->tblRom;
        w->waveInfo.adpcmWave.book = (ALADPCMBook*)((u8*)w->waveInfo.adpcmWave.book + (u32)D_800D58E4_D64E4->sounds);
        if (w->waveInfo.adpcmWave.loop != NULL) {
            w->waveInfo.adpcmWave.loop = (ALADPCMloop*)((u8*)w->waveInfo.adpcmWave.loop + (u32)D_800D58E4_D64E4->sounds);
        }
    }
    return 0;
}

s32 func_80011938_12538(u32 rom, SndBankInfo* info) {
    u32 src;
    SndDef* g;
    s32* ofs;
    s32 i;
    s32 j;

    if ((D_800D58E4_D64E4->defs = func_8000EC10_F810(info->groupsSize)) == NULL) {
        return 1;
    }
    src = rom + info->groupsRom;
    func_8000EB3C_F73C(D_800D58E4_D64E4->defs, src, info->groupsSize, 0);
    for (i = 0; i < info->numGroups; i++) {
        if (D_800D58E4_D64E4->defs[i] != 0) {
            g = D_800D58E4_D64E4->defs[i] = (SndDef*)((u8*)D_800D58E4_D64E4->defs[i] + (s32)D_800D58E4_D64E4->defs);
            for (j = 0; j < g->numParts; j++) {
                g->part[j].script += (s32)D_800D58E4_D64E4->defs;
            }
        }
    }
    return 0;
}

s32 func_80011A28_12628(u32 rom, SndBankInfo* info) {
    s32* ofs;
    s32 i;

    if (info->numUnk10 == 0) {
        D_800D58E4_D64E4->penvs = NULL;
    } else {
        if ((D_800D58E4_D64E4->penvs = func_8000EC10_F810(info->unk10Size)) == NULL) {
            return 1;
        }
        rom += info->unk10Rom;
        func_8000EB3C_F73C(D_800D58E4_D64E4->penvs, rom, info->unk10Size, 0);
        for (i = 0; i < info->numUnk10; i++) {
            if (D_800D58E4_D64E4->penvs[i] != 0) {
                D_800D58E4_D64E4->penvs[i] += (s32)D_800D58E4_D64E4->penvs;
            }
        }
    }
    return 0;
}

void func_80011AF8_126F8(void) {
    AudioCmd* cmd;
    SndVoice* v;
    SndVoice* w;
    s32 i;
    s32 j;

    for (i = 0; i < D_800D58E4_D64E4->cmdIndex; i++) {
        cmd = &D_800D58E4_D64E4->cmds[i];
        v = &D_800D58E4_D64E4->voices[cmd->voiceSlot];
        switch (cmd->cmdType) {
            case 0:
                v->flags |= 2;
                v->state = 3;
                break;
            case 1:
                v->flags |= 1;
                v->part = cmd->cmdArg & 0xF;
                v->numChild = cmd->cmdArg >> 4;
                break;
            case 2:
                v->vol = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x10;
                } else {
                    v->flags |= 0x4000;
                    if (v->numChild != 0) {
                        for (j = 0; j < v->numChild; j++) {
                            w = &D_800D58E4_D64E4->voices[v->child[j].slot];
                            if (w->serial == v->child[j].serial) {
                                w->vol = cmd->cmdArg;
                                w->flags |= 0x4000;
                            }
                        }
                    }
                }
                break;
            case 4:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    w->vol = cmd->cmdArg;
                    if (w->flags & 3) {
                        w->flags |= 0x10;
                    } else {
                        w->flags |= 0x4000;
                    }
                }
                break;
            case 3:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    if (w->state == 4) {
                        w->flags |= 0x4000;
                    }
                }
                D_800D58E4_D64E4->vol2 = cmd->cmdArg;
                D_800D58E4_D64E4->fadeVol = 0x7F;
                D_800D58E4_D64E4->fadeTimer = 0;
                break;
            case 5:
                v->pitch = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x40;
                } else {
                    v->flags |= 0x20000;
                    if (v->numChild != 0) {
                        for (j = 0; j < v->numChild; j++) {
                            w = &D_800D58E4_D64E4->voices[v->child[j].slot];
                            if (w->serial == v->child[j].serial) {
                                w->pitch = cmd->cmdArg;
                                w->flags |= 0x20000;
                            }
                        }
                    }
                }
                break;
            case 6:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    w->pitch = cmd->cmdArg;
                    if (w->flags & 3) {
                        w->flags |= 0x40;
                    } else {
                        w->flags |= 0x20000;
                    }
                }
                break;
            case 7:
                v->pan = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x20;
                } else {
                    v->flags |= 0x8000;
                    if (v->numChild != 0) {
                        for (j = 0; j < v->numChild; j++) {
                            w = &D_800D58E4_D64E4->voices[v->child[j].slot];
                            if (w->serial == v->child[j].serial) {
                                w->pan = cmd->cmdArg;
                                w->flags |= 0x8000;
                            }
                        }
                    }
                }
                break;
            case 8:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    w->pan = cmd->cmdArg;
                    if (w->flags & 3) {
                        w->flags |= 0x20;
                    } else {
                        w->flags |= 0x8000;
                    }
                }
                break;
            case 9:
                v->fxMix = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x80;
                } else {
                    v->flags |= 0x10000;
                    if (v->numChild != 0) {
                        for (j = 0; j < v->numChild; j++) {
                            w = &D_800D58E4_D64E4->voices[v->child[j].slot];
                            if (w->serial == v->child[j].serial) {
                                w->fxMix = cmd->cmdArg;
                                w->flags |= 0x10000;
                            }
                        }
                    }
                }
                break;
            case 10:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    w->fxMix = cmd->cmdArg;
                    if (w->flags & 3) {
                        w->flags |= 0x80;
                    } else {
                        w->flags |= 0x10000;
                    }
                }
                break;
            case 11:
                func_8001240C_1300C(v);
                if (v->numChild != 0) {
                    for (j = 0; j < v->numChild; j++) {
                        w = &D_800D58E4_D64E4->voices[v->child[j].slot];
                        if (w->serial == v->child[j].serial) {
                            func_8001240C_1300C(w);
                        }
                    }
                }
                break;
            case 12:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    func_8001240C_1300C(&D_800D58E4_D64E4->voices[j]);
                }
                break;
            case 13:
                D_800D58E4_D64E4->fadeTimer = (cmd->cmdArg <= 0) ? 1 : cmd->cmdArg;
                D_800D58E4_D64E4->fadeStep = 0x7F000000 / D_800D58E4_D64E4->fadeTimer;
                D_800D58E4_D64E4->fadeVol = 0x7F;
                break;
            case 14:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    if (w->state >= 2) {
                        w->state = 2;
                    }
                    if (w->flags & 8) {
                        func_8001240C_1300C(w);
                    }
                }
                D_800D58E4_D64E4->pause = 0x7E;
                break;
            case 15:
                D_800D58E4_D64E4->pause = 0x7F;
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    if (w->state == 2) {
                        w->state = 4;
                        w->flags |= 0x4000;
                    }
                }
                if (cmd->cmdArg != 0 && D_800D58E4_D64E4->fadeTimer <= 0) {
                    D_800D58E4_D64E4->fadeTimer = -cmd->cmdArg;
                    D_800D58E4_D64E4->fadeStep = 0x7F000000 / cmd->cmdArg;
                    D_800D58E4_D64E4->fadeVol = 0;
                }
                break;
            case 16:
                if (v->flags & 3) {
                    v->flags |= 0x100;
                } else {
                    v->flags |= 0x4000;
                }
                v->vol2 = cmd->cmdArg;
                break;
            case 17:
                if (v->flags & 3) {
                    v->flags |= 0x200;
                } else {
                    v->flags |= 0x8000;
                }
                v->pan2 = cmd->cmdArg;
                break;
            case 18:
                if (v->flags & 3) {
                    v->flags |= 0x400;
                } else {
                    v->flags |= 0x20000;
                }
                v->pitchMul = *(f32*)&cmd->cmdArg;
                break;
        }
    }
    D_800D58E4_D64E4->cmdIndex = 0;
}



void func_800A0D20_A1920(ALSndPlayer*, s16); /* alSndpSetSound */
void func_8007EEE0_7FAE0(ALSndPlayer*, ALSndpConfig*); /* alSndpNew */
s16 func_8000EC94_F894(s32);
void func_80011AF8_126F8(void);
void func_80012800_13400(SndVoice*);
s32 func_800132A0_13EA0(u8**);
f32 func_800132EC_13EEC(SndVoice*);
void func_80013FD0_14BD0(SndVoice*, s32);
void func_80014768_15368(s32, s32, s32);
s32 func_80014B30_15730(s32, SndPlayParam*);
s32 func_80014D34_15934(s32, s32, s32, s32);
void func_80015148_15D48(s32, s32, u8, SndPlayParam*);
void func_80015B9C_1679C(s32, SndPosParam*);

void func_8001240C_1300C(SndVoice* v) {
    s32 state;

    v->flags = 0;
    v->state = 0;
    if (v->sndId >= 0) {
        func_800A0D20_A1920(D_800D58E4_D64E4->sndp, v->sndId);
        state = alSndpGetState(D_800D58E4_D64E4->sndp);
        if (state == 1) {
            alSndpStop(D_800D58E4_D64E4->sndp);
            v->state = state;
        }
    }
}

void func_8001248C_1308C(SndVoice* v) {
    if (v->sndId >= 0) {
        func_800A0D20_A1920(D_800D58E4_D64E4->sndp, v->sndId);
        if ((v->sndState = alSndpGetState(D_800D58E4_D64E4->sndp)) == 0) {
            alSndpDeallocate(D_800D58E4_D64E4->sndp, v->sndId);
            v->sndId = -1;
        }
    }
}

void func_800124FC_130FC(SndVoice* v) {
    switch (v->state) {
        case 2:
        case 3:
        case 4:
            D_800D58E4_D64E4->active++;
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
    def = D_800D58E4_D64E4->defs[v->defNo];
    if (D_800D58E4_D64E4->pause < 0x7F && !(def->flags & 1)) {
        return;
    }
    v->state = 3;
    if (v->sndState == 1) {
        v->env.releaseTime = 4000;
        alSndpStop(D_800D58E4_D64E4->sndp);
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
            c = &D_800D58E4_D64E4->voices[ch[i].slot];
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
            v->vol = D_800D58E4_D64E4->vol;
        }
        if (!(v->flags & 0x20)) {
            v->pan = D_800D58E4_D64E4->pan;
        }
        if (!(v->flags & 0x40)) {
            v->pitch = D_800D58E4_D64E4->pitch;
        }
        if (!(v->flags & 0x80)) {
            v->fxMix = D_800D58E4_D64E4->fxMix;
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
            v = &D_800D58E4_D64E4->voices[ch[i].slot];
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
                        if (D_800D58E4_D64E4->penvs != NULL) {
                            v->penvBase = D_800D58E4_D64E4->penvs[p[0]];
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
                        v->rateRatio = (f32)t / (f32)func_8000E9DC_F5DC()->cfg.outputRate;
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
/* func_80012800_13400's jump table, defined here while that function is asm so the unit's rodata
   stays one carved piece (D2420-D2AA0) */
const u32 jtbl_800D1D00_D2900[] __attribute__((aligned(8), section(".rodata"))) = {
    0x800131EC, 0x80013260, 0x800128B4, 0x800129C8, 0x80012A00, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x80012A68, 0x80012B60,
    0x80012B70, 0x80012B88, 0x80012BC8, 0x80012BE0, 0x80012C2C, 0x80012C44,
    0x8001324C, 0x80012C90, 0x80012CBC, 0x80012CF0, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x80012D14, 0x80012D54, 0x80012D70, 0x80012DBC,
    0x80012E08, 0x80012E48, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C,
    0x80012E50, 0x80012E80, 0x80012EB0, 0x80012F00, 0x80012F50, 0x80012FB4,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x80013010, 0x80013040,
    0x8001304C, 0x8001308C, 0x80013098, 0x800130E8, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C,
    0x8001324C, 0x8001324C, 0x800130FC, 0x8001311C, 0x80013140, 0x8001324C,
    0x8001324C, 0x8001324C, 0x8001324C, 0x8001324C, 0x80013178, 0x80013198,
    0x800131B8,
};
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
                alSndpStop(D_800D58E4_D64E4->sndp);
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
            alSndpStop(D_800D58E4_D64E4->sndp);
        }
    }
    if (start) {
        if (v->flags & 0x02000000) {
            n = (u16)v->sampleNo & 0x7FFF;
            bcopy(&D_800D58E4_D64E4->sounds[n], &v->sound, sizeof(ALSound));
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
                v->rateRatio = (f32)n / (f32)func_8000E9DC_F5DC()->cfg.outputRate;
            }
            v->sound.keyMap = NULL;
            v->flags &= 0xF80FFFFF;
        }
        v->sndId = alSndpAllocate(D_800D58E4_D64E4->sndp, &v->sound);
        if (v->sndId >= 0) {
            alSndpSetPriority(D_800D58E4_D64E4->sndp, v->sndId, 20);
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
        func_800A0D20_A1920(D_800D58E4_D64E4->sndp, v->sndId);
        if ((v->flags & 0x4000) || start) {
            vol = v->noteVolOfs + v->noteVol;
            if (vol >= 0x80) {
                vol = 0x7F;
            }
            if (vol < 0) {
                vol = 0;
            }
            vol = vol * D_800D58E4_D64E4->fadeVol * v->vol * v->sound.sampleVolume / 2048383;
            vol = vol * D_800D58E4_D64E4->vol2 * D_800D58E4_D64E4->vol3 * v->vol2 / 2048383;
            if (!(v->flags & 4)) {
                vol = vol * D_800D58E4_D64E4->pause / 127;
            }
            alSndpSetVol(D_800D58E4_D64E4->sndp, func_8000EC94_F894(vol));
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
            alSndpSetPan(D_800D58E4_D64E4->sndp, pan);
        }
        if ((v->flags & 0x20000) || start) {
            alSndpSetPitch(D_800D58E4_D64E4->sndp, alCents2Ratio(v->pitch + v->pitchOfs + v->note) * v->rateRatio * v->pitchMul);
        }
        if ((v->flags & 0x10000) || start) {
            pan = v->noteFxMix;
            if (pan != 0) {
                mix = pan;
            } else {
                mix = v->fxMix;
            }
            alSndpSetFXMix(D_800D58E4_D64E4->sndp, mix);
        }
        if (start && v->sndState == 0) {
            alSndpPlay(D_800D58E4_D64E4->sndp);
        }
        if (v->flags & 0x2000) {
            alSndpStop(D_800D58E4_D64E4->sndp);
        }
        v->flags &= 0xFFFC1FFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013FD0_14BD0);
#endif

void func_800142C4_14EC4(void) {
    switch (D_800D58E4_D64E4->pause) {
        case 0x7E:
            D_800D58E4_D64E4->pause = 0x40;
            break;
        case 0x40:
            D_800D58E4_D64E4->pause = 0xA;
            break;
        case 0xA:
            D_800D58E4_D64E4->pause = 0;
            break;
        case 0:
            D_800D58E4_D64E4->pause = -1;
            break;
    }
}

void func_8001434C_14F4C(void) {
    SndVoice* v;
    s32 i;

    if (D_800D58E4_D64E4->fadeTimer > 0) {
        if (--D_800D58E4_D64E4->fadeTimer != 0) {
            i = (D_800D58E4_D64E4->fadeStep * D_800D58E4_D64E4->fadeTimer) >> 24;
            if (i != D_800D58E4_D64E4->fadeVol) {
                D_800D58E4_D64E4->fadeVol = i;
                for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
                    v = &D_800D58E4_D64E4->voices[i];
                    if (v->state == 4) {
                        v->flags |= 0x4000;
                    }
                }
            }
        } else {
            for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
                func_8001240C_1300C(&D_800D58E4_D64E4->voices[i]);
            }
            D_800D58E4_D64E4->fadeVol = 0x7F;
        }
    }
    if (D_800D58E4_D64E4->fadeTimer < 0) {
        if (++D_800D58E4_D64E4->fadeTimer != 0) {
            i = 0x7F - ((-D_800D58E4_D64E4->fadeTimer * D_800D58E4_D64E4->fadeStep) >> 24);
        } else {
            i = 0x7F;
        }
        if (i != D_800D58E4_D64E4->fadeVol) {
            D_800D58E4_D64E4->fadeVol = i;
            for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
                v = &D_800D58E4_D64E4->voices[i];
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
    func_8000EB3C_F73C((void*)n, (u32)cfg->bank + 0x40, 0x34, 0);
    if (func_800117FC_123FC((u32)cfg->bank, (SndBankInfo*)n) != 0) {
        return 2;
    }
    if (func_80011938_12538((u32)cfg->bank, (SndBankInfo*)n) != 0) {
        return 3;
    }
    if (func_80011A28_12628((u32)cfg->bank, (SndBankInfo*)n) != 0) {
        return 4;
    }
    n = cfg->numVoices * sizeof(SndVoice);
    if ((D_800D58E4_D64E4->voices = func_8000EC10_F810(n)) == NULL) {
        return 5;
    }
    bzero(D_800D58E4_D64E4->voices, n);
    sc.maxSounds = cfg->numVoices;
    sc.maxEvents = cfg->maxEvents;
    sc.heap = heap;
    if ((D_800D58E4_D64E4->sndp = func_8000EC10_F810(sizeof(ALSndPlayer))) == NULL) {
        return 6;
    }
    func_8007EEE0_7FAE0(D_800D58E4_D64E4->sndp, &sc);
    D_800D58E4_D64E4->numVoices = cfg->numVoices;
    D_800D58E4_D64E4->numDefs = numDefs;
    D_800D58E4_D64E4->vol3 = vol3;
    D_800D58E4_D64E4->pan = 0x40;
    D_800D58E4_D64E4->vol2 = D_800D58E4_D64E4->fadeVol = D_800D58E4_D64E4->pause = D_800D58E4_D64E4->vol = 0x7F;
    D_800D58E4_D64E4->nearDist = 50.0f;
    D_800D58E4_D64E4->farDist = 500.0f;
    D_800D58E4_D64E4->unk44A = 10;
    D_800D58E4_D64E4->unk44C = 1224.0f;
    D_800D58E4_D64E4->unk450 = 1.0f;
    for (n = 0; n < D_800D58E4_D64E4->numVoices; n++) {
        D_800D58E4_D64E4->voices[n].sndId = -1;
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
    cmd = &D_800D58E4_D64E4->cmds[D_800D58E4_D64E4->cmdIndex];
    cmd->cmdType = cmdType;
    cmd->voiceSlot = voiceSlot;
    cmd->cmdArg = cmdArg;
    if (++D_800D58E4_D64E4->cmdIndex >= 128) {
        func_8000EC8C_F88C(0, 0x200);
        D_800D58E4_D64E4->cmdIndex = 0;
    }
    osSetIntMask(temp_s3);
}

void func_80014814_15414(s32 voiceSlot, s32 cmdType, f32 cmdArg) {
    u32 mask;
    AudioCmd* cmd;

    mask = osSetIntMask(1);
    cmd = &D_800D58E4_D64E4->cmds[D_800D58E4_D64E4->cmdIndex];
    cmd->cmdType = cmdType;
    cmd->voiceSlot = voiceSlot;
    *(f32*)&cmd->cmdArg = cmdArg;
    if (++D_800D58E4_D64E4->cmdIndex >= 128) {
        func_8000EC8C_F88C(0, 0x200);
        D_800D58E4_D64E4->cmdIndex = 0;
    }
    osSetIntMask(mask);
}

void func_800148C4_154C4(void) {
    SndVoice* v;
    s32 i;

    if (D_800D58E4_D64E4 != NULL && D_800D58E4_D64E4->busy == 0) {
        D_800D58E4_D64E4->busy = 1;
        D_800D58E4_D64E4->active = 0;
        func_80011AF8_126F8();
        func_800142C4_14EC4();
        for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
            v = &D_800D58E4_D64E4->voices[i];
            func_8001248C_1308C(v);
            func_80012548_13148(v);
            func_800124FC_130FC(v);
            if (v->state != 4) {
                if (v->state == 2 && D_800D58E4_D64E4->pause >= 0) {
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
                    D_800D58E4_D64E4->active--;
                }
            }
        }
        if (D_800D58E4_D64E4->pause == 0x7F) {
            func_8001434C_14F4C();
        }
        D_800D58E4_D64E4->busy = 0;
    }
}

void func_80014A60_15660(void) {
    SndVoice* v;
    s32 i;

    if (D_800D58E4_D64E4 != NULL) {
        for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
            v = &D_800D58E4_D64E4->voices[i];
            if (v->sndId >= 0) {
                func_800A0D20_A1920(D_800D58E4_D64E4->sndp, v->sndId);
                alSndpStop(D_800D58E4_D64E4->sndp);
            }
        }
        alSndpDelete(D_800D58E4_D64E4->sndp);
    }
}

SndMgr* func_80014AFC_156FC(void) {
    return D_800D58E4_D64E4;
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
        for (i = 0; i < D_800D58E4_D64E4->numVoices; i++) {
            v = &D_800D58E4_D64E4->voices[i];
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
