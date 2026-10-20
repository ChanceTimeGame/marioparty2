#include "common.h"

/* Audio driver. Functions with C come from MP1 src/B980.c (oscillator free list, vibrato depth),
   MP3 src/1140.c (audio command queue) and MP1 ovl_22 (a one-argument wrapper); the rest is asm. */

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

/* w1-C: one sound-effect voice (0xFC bytes, array at UnkAudio.voices); only the fields this half uses. */
typedef struct SndVoice {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 state;
    /* 0x08 */ char unk08[8];
    /* 0x10 */ s32 id;
    /* 0x14 */ char unk14[4];
    /* 0x18 */ u16 pitch;
    /* 0x1A */ u8 vol;
    /* 0x1B */ u8 pan;
    /* 0x1C */ u8 fxmix;
    /* 0x1D */ char unk1D;
    /* 0x1E */ s8 unk1E;
    /* 0x1F */ s8 numLinks;
    /* 0x20 */ struct {
        s32 voice;
        s32 id;
    } links[18];
    /* 0xB0 */ char unkB0[2];
    /* 0xB2 */ u8 unkB2;
    /* 0xB3 */ u8 unkB3;
    /* 0xB4 */ f32 unkB4;
    /* 0xB8 */ char unkB8[0x44];
} SndVoice; // size 0xFC

typedef struct {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ ALSound* sounds;     // w1-C: loaded by func_800117FC_123FC
    /* 0x08 */ SndVoice* voices;    // w1-C
    /* 0x0C */ s32* groups;         // w1-C: offset table, func_80011938_12538
    /* 0x10 */ s32* unk10;          // w1-C: offset table, func_80011A28_12628
    /* 0x14 */ s32 numVoices;       // w1-C
    /* 0x18 */ s32 busy;            // w1-C
    /* 0x1C */ char unk1C[4];
    /* 0x20 */ s32 fadeStep;        // w1-C
    /* 0x24 */ s32 fadeTimer;       // w1-C
    /* 0x28 */ char unk28[7];
    /* 0x2F */ s8 vol;              // w1-C
    /* 0x30 */ char unk30;
    /* 0x31 */ s8 fadeVol;          // w1-C
    /* 0x32 */ s8 unk32;            // w1-C
    /* 0x33 */ char unk33;
    /* 0x34 */ s32 unk34;           // write index (wraps at 0x80)
    /* 0x38 */ AudioCmd cmds[0x80];
} UnkAudio;

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
    /* 0x1C */ s32 unk1C;
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

typedef struct SndGroup {
    /* 0x00 */ s8 count;
    /* 0x01 */ char pad01[7];
    /* 0x08 */ struct {
        s32 unk0;
        s32 ofs;           // relocated against the group table
    } entries[1];
} SndGroup;


extern OSMesg D_800D5770_D6370[];
extern OSMesgQueue D_800D5838_D6438;
extern ALHeap D_800D5850_D6450;
extern SndState D_800D5860_D6460;
extern SeqMgr* D_800D58D8_D64D8;
extern ECE0Osc* D_800D58DC_D64DC;
extern ECE0Osc* D_800D58E0_D64E0;
extern UnkAudio* D_800D58E4_D64E4;
extern u8 D_800F8428_F9028;

s32 func_8000E3FC_EFFC(SndConfig*);
void func_8000EB3C_F73C(void* dst, u32 rom, s32 size, s32 chunk);
void* func_8000EC10_F810(s32 size);
s32 func_8000F968_10568(SndConfig*, ALHeap*, s32, s32);
s32 func_80014520_15120(SndConfig*, ALHeap*, s32, s32);
UnkAudio* func_80014AFC_156FC(void);
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

void func_80014B30_15730(void*, u8);

void func_8000E0E0_ECE0(SndBankHdr* hdr, u32 rom) {
    SndState* st = &D_800D5860_D6460;

    if (!(st->cfg.flags & 0x10)) {
        st->cfg.unk1C = hdr->unk14;
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
        st->unk1C = cfg->unk1C;
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
    if ((ret = func_80014520_15120(&D_800D5860_D6460.cfg, &D_800D5850_D6450, sbfCount, sbfArg)) != 0) {
        return ret + 400;
    }
    func_8000EC8C_F88C(100, 0);
    func_800160FC_16CFC(st);
    return 0;
}
s32 func_8000E930_F530(void) {
    SeqMgr* seq = func_800100FC_10CFC();
    UnkAudio* snd;

    if (seq != NULL && seq->numActive != 0) {
        return 1;
    }
    snd = func_80014AFC_156FC();
    if (snd != NULL) {
        if (snd->busy != 0) {
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
    UnkAudio* snd;
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

void func_80010E58_11A58(s32 id) {
    func_80010E74_11A74(id, NULL);
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
    SndGroup* g;
    s32* ofs;
    s32 i;
    s32 j;

    if ((D_800D58E4_D64E4->groups = func_8000EC10_F810(info->groupsSize)) == NULL) {
        return 1;
    }
    src = rom + info->groupsRom;
    func_8000EB3C_F73C(D_800D58E4_D64E4->groups, src, info->groupsSize, 0);
    for (i = 0; i < info->numGroups; i++) {
        if (D_800D58E4_D64E4->groups[i] != 0) {
            g = (SndGroup*)(D_800D58E4_D64E4->groups[i] += (s32)D_800D58E4_D64E4->groups);
            for (j = 0; j < g->count; j++) {
                g->entries[j].ofs += (s32)D_800D58E4_D64E4->groups;
            }
        }
    }
    return 0;
}
s32 func_80011A28_12628(u32 rom, SndBankInfo* info) {
    s32* ofs;
    s32 i;

    if (info->numUnk10 == 0) {
        D_800D58E4_D64E4->unk10 = NULL;
    } else {
        if ((D_800D58E4_D64E4->unk10 = func_8000EC10_F810(info->unk10Size)) == NULL) {
            return 1;
        }
        rom += info->unk10Rom;
        func_8000EB3C_F73C(D_800D58E4_D64E4->unk10, rom, info->unk10Size, 0);
        for (i = 0; i < info->numUnk10; i++) {
            if (D_800D58E4_D64E4->unk10[i] != 0) {
                D_800D58E4_D64E4->unk10[i] += (s32)D_800D58E4_D64E4->unk10;
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

    for (i = 0; i < D_800D58E4_D64E4->unk34; i++) {
        cmd = &D_800D58E4_D64E4->cmds[i];
        v = &D_800D58E4_D64E4->voices[cmd->voiceSlot];
        switch (cmd->cmdType) {
            case 0:
                v->flags |= 2;
                v->state = 3;
                break;
            case 1:
                v->flags |= 1;
                v->unk1E = cmd->cmdArg & 0xF;
                v->numLinks = cmd->cmdArg >> 4;
                break;
            case 2:
                v->vol = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x10;
                } else {
                    v->flags |= 0x4000;
                    if (v->numLinks != 0) {
                        for (j = 0; j < v->numLinks; j++) {
                            w = &D_800D58E4_D64E4->voices[v->links[j].voice];
                            if (w->id == v->links[j].id) {
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
                D_800D58E4_D64E4->vol = cmd->cmdArg;
                D_800D58E4_D64E4->fadeVol = 0x7F;
                D_800D58E4_D64E4->fadeTimer = 0;
                break;
            case 5:
                v->pitch = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x40;
                } else {
                    v->flags |= 0x20000;
                    if (v->numLinks != 0) {
                        for (j = 0; j < v->numLinks; j++) {
                            w = &D_800D58E4_D64E4->voices[v->links[j].voice];
                            if (w->id == v->links[j].id) {
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
                    if (v->numLinks != 0) {
                        for (j = 0; j < v->numLinks; j++) {
                            w = &D_800D58E4_D64E4->voices[v->links[j].voice];
                            if (w->id == v->links[j].id) {
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
                v->fxmix = cmd->cmdArg;
                if (v->flags & 3) {
                    v->flags |= 0x80;
                } else {
                    v->flags |= 0x10000;
                    if (v->numLinks != 0) {
                        for (j = 0; j < v->numLinks; j++) {
                            w = &D_800D58E4_D64E4->voices[v->links[j].voice];
                            if (w->id == v->links[j].id) {
                                w->fxmix = cmd->cmdArg;
                                w->flags |= 0x10000;
                            }
                        }
                    }
                }
                break;
            case 10:
                for (j = 0; j < D_800D58E4_D64E4->numVoices; j++) {
                    w = &D_800D58E4_D64E4->voices[j];
                    w->fxmix = cmd->cmdArg;
                    if (w->flags & 3) {
                        w->flags |= 0x80;
                    } else {
                        w->flags |= 0x10000;
                    }
                }
                break;
            case 11:
                func_8001240C_1300C(v);
                if (v->numLinks != 0) {
                    for (j = 0; j < v->numLinks; j++) {
                        w = &D_800D58E4_D64E4->voices[v->links[j].voice];
                        if (w->id == v->links[j].id) {
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
                D_800D58E4_D64E4->unk32 = 0x7E;
                break;
            case 15:
                D_800D58E4_D64E4->unk32 = 0x7F;
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
                v->unkB2 = cmd->cmdArg;
                break;
            case 17:
                if (v->flags & 3) {
                    v->flags |= 0x200;
                } else {
                    v->flags |= 0x8000;
                }
                v->unkB3 = cmd->cmdArg;
                break;
            case 18:
                if (v->flags & 3) {
                    v->flags |= 0x400;
                } else {
                    v->flags |= 0x20000;
                }
                v->unkB4 = *(f32*)&cmd->cmdArg;
                break;
        }
    }
    D_800D58E4_D64E4->unk34 = 0;
}
INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001240C_1300C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001248C_1308C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800124FC_130FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80012548_13148);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80012800_13400);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800132A0_13EA0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800132EC_13EEC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013648_14248);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013A80_14680);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013BE4_147E4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013D44_14944);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013FD0_14BD0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800142C4_14EC4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001434C_14F4C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014520_15120);

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

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014814_15414);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800148C4_154C4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014A60_15660);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014AFC_156FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014B08_15708);

void func_80014B14_15714(void* obj) {
    func_80014B30_15730(obj, 0);
}

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014B30_15730);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014D34_15934);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015148_15D48);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015334_15F34);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001535C_15F5C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015388_15F88);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800153CC_15FCC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001545C_1605C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800154A0_160A0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800154F0_160F0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015580_16180);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800155B8_161B8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015664_16264);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015710_16310);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800157BC_163BC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015868_16468);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015950_16550);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015988_16588);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800159B4_165B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015A64_16664);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015AAC_166AC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015B9C_1679C);
