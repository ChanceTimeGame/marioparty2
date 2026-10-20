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
    /* 0x04 */ char unk04[4];
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
    /* 0x31 */ u8 waitFade;
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

/* Sound effects (func_80014AFC_156FC); only the fields this half uses. */
typedef struct SndMgr {
    /* 0x00 */ char unk00[8];
    /* 0x08 */ s32* voices;    // 0xFC-byte records, first word flags
    /* 0x0C */ char unk0C[8];
    /* 0x14 */ s32 numVoices;
    /* 0x18 */ s32 busy;
} SndMgr;

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
s32 func_80010114_10D14(void* oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);
s32 func_80010570_11170(void* oscState, f32* updateVal);
void func_80010DFC_119FC(ECE0Osc* osc);
SndState* func_8000E9DC_F5DC(void);

s32 func_8000EC8C_F88C(s32, s32);
void func_80010E74_11A74(void*, u8);
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
    SndMgr* snd;

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
    SndMgr* snd;
    s32 i;

    D_800F8428_F9028 = mono & 1;
    snd = func_80014AFC_156FC();
    if (snd != NULL) {
        for (i = 0; i < snd->numVoices; i++) {
            if (snd->voices[i * 0x3F] & 3) {
                snd->voices[i * 0x3F] |= 0x20;
            } else {
                snd->voices[i * 0x3F] |= 0x8000;
            }
        }
    }
}
s16 func_8000EB1C_F71C(void) {
    return func_8000E9DC_F5DC()->fxdId;
}
// argument register copies in another order (masked 0)
#ifdef NON_MATCHING
void func_8000EB3C_F73C(void* dst, u32 rom, s32 size, s32 chunk) {
    OSIoMesg mesg;
    s32 n;

    if (chunk == 0) {
        chunk = size;
    }
    chunk += chunk & 1;
    while (size != 0) {
        n = size;
        if (chunk < size) {
            n = chunk;
        }
        mesg.hdr.pri = OS_MESG_PRI_NORMAL;
        mesg.hdr.retQueue = &D_800D5838_D6438;
        mesg.dramAddr = dst;
        mesg.devAddr = rom;
        mesg.size = n;
        osInvalDCache(dst, n);
        osEPiStartDma(D_800D5860_D6460.cfg.piHandle, &mesg, OS_READ);
        osRecvMesg(&D_800D5838_D6438, NULL, OS_MESG_BLOCK);
        rom += n;
        size -= n;
        dst = (u8*)dst + n;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EB3C_F73C);
#endif
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
