/* libultra audio/drvrnew.c (2.0I), from MP1 src/96AA0.c. _init_lpfilter and alFxNew stay in asm:
   their f64 constants and alFxNew's jump table are in the unsplit data/rodata asm. */
#define alFilterNew func_800AA7D0_AB3D0
#define alAdpcmPull func_800A8F00_A9B00
#define alResamplePull func_800AA960_AB560
#define alAuxBusPull func_800A9A10_AA610
#define alMainBusPull func_800AA7F0_AB3F0
#define alSavePull func_800AB7B0_AC3B0
#define alEnvmixerPull func_800A9B20_AA720
#define alLoadParam func_800A96E0_AA2E0
#define alResampleParam func_800AAB4C_AB74C
#define alAuxBusParam func_800A9AEC_AA6EC
#define alMainBusParam func_800AA930_AB530
#define alSaveParam func_800AB858_AC458
#define alHeapDBAlloc func_8009EBB0_9F7B0

#include <libaudio.h>
#include "synthInternals.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/A92D0", func_800A86D0_A92D0);

INCLUDE_ASM("asm/nonmatchings/A92D0", func_800A8774_A9374);

void alEnvmixerNew(ALEnvMixer* e, ALHeap* hp) {
    alFilterNew((ALFilter*)e, alEnvmixerPull, alEnvmixerParam, AL_ENVMIX);
    e->state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
    e->first = 1;
    e->motion = AL_STOPPED;
    e->volume = 1;
    e->ltgt = 1;
    e->rtgt = 1;
    e->cvolL = 1;
    e->cvolR = 1;
    e->dryamt = 0;
    e->wetamt = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->delta = 0;
    e->segEnd = 0;
    e->pan = 0;
    e->ctrlList = 0;
    e->ctrlTail = 0;
    e->sources = 0;
}

void alLoadNew(ALLoadFilter* f, ALDMANew dmaNew, ALHeap* hp) {
    s32 i;

    alFilterNew((ALFilter*)f, alAdpcmPull, alLoadParam, AL_ADPCM);
    f->state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->dma = dmaNew(&f->dmaState);
    f->lastsam = 0;
    f->first = 1;
    f->memin = 0;
}

void alResampleNew(ALResampler* r, ALHeap* hp) {
    alFilterNew((ALFilter*)r, alResamplePull, alResampleParam, AL_RESAMPLE);
    r->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
    r->delta = 0.0;
    r->first = 1;
    r->motion = AL_STOPPED;
    r->ratio = 1.0;
    r->upitch = 0;
    r->ctrlList = 0;
    r->ctrlTail = 0;
}

void alAuxBusNew(ALAuxBus* m, void* sources, s32 maxSources) {
    alFilterNew((ALFilter*)m, alAuxBusPull, alAuxBusParam, AL_AUXBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter**)sources;
}

void alMainBusNew(ALMainBus* m, void* sources, s32 maxSources) {
    alFilterNew((ALFilter*)m, alMainBusPull, alMainBusParam, AL_MAINBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter**)sources;
}

void alSaveNew(ALSave* f) {
    alFilterNew((ALFilter*)f, alSavePull, alSaveParam, AL_SAVE);
    f->dramout = 0;
    f->first = 1;
}
