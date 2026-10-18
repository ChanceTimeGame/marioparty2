/* libultra audio/env.c (2.0I), from MP1 src/972D0.c.
   alEnvmixerPull, _frexpf and _getRate stay in asm: their jump table / f64 constants are in the
   unsplit data/rodata asm. The helpers are not static here because the asm calls them. */
#define alEnvmixerPull func_800A9B20_AA720
#define _pullSubFrame func_800AA0F4_AACF4
#define _frexpf func_800AA3C8_AAFC8
#define _ldexpf func_800AA4A8_AB0A8
#define _getRate func_800AA4CC_AB0CC
#define _getVol func_800AA74C_AB34C

#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>
#include "include_asm.h"

#define EQPOWER_LENGTH 128
extern s16 D_800CF250_CFE50[EQPOWER_LENGTH]; /* eqpower */
#define eqpower D_800CF250_CFE50

Acmd* _pullSubFrame(void* filter, s16* inp, s16* outp, s32 outCount, s32 sampleOffset, Acmd* p);
s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);
f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);

INCLUDE_ASM("asm/nonmatchings/AA720", func_800A9B20_AA720);

s32 alEnvmixerParam(void *filter, s32 paramID, void *param)
{
    ALFilter      *f = (ALFilter *) filter;
    ALEnvMixer	*e = (ALEnvMixer *) filter;

    switch (paramID) {

      case (AL_FILTER_ADD_UPDATE):
          if (e->ctrlTail) {
              e->ctrlTail->next = (ALParam *)param;
          } else {
              e->ctrlList = (ALParam *)param;
          }            
          e->ctrlTail = (ALParam *)param;

          break;

      case (AL_FILTER_RESET):
          e->first = 1;
          e->motion = AL_STOPPED;
          e->volume = 1;
          if (f->source)
              (*f->source->setParam)(f->source, AL_FILTER_RESET, param);
          break;

      case (AL_FILTER_START):
          e->motion = AL_PLAYING;
          if (f->source)
              (*f->source->setParam)(f->source, AL_FILTER_START, param);
          break;

      case (AL_FILTER_SET_SOURCE):
          f->source = (ALFilter *) param;
          break;

      default:
          if (f->source)
              (*f->source->setParam)(f->source, paramID, param);
    }
    return 0;
}
Acmd* _pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount,
                    s32 sampleOffset, Acmd *p) 
{
    Acmd        *ptr = p;
    ALEnvMixer	*e = (ALEnvMixer *)filter;
    ALFilter      *source= e->filter.source;

    if (e->motion != AL_PLAYING || !outCount)
        return ptr;

    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, A_MAIN, *inp, AL_MAIN_L_OUT + *outp, outCount<<1);
    aSetBuffer(ptr++, A_AUX, AL_MAIN_R_OUT + *outp, AL_AUX_L_OUT + *outp,
	       AL_AUX_R_OUT + *outp);

    if (e->first){
	e->first = 0;

        e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
        e->lratm = _getRate((f64)e->cvolL, (f64)e->ltgt,
                            e->segEnd, &(e->lratl));
        e->rtgt = (e->volume *
                   eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
        e->rratm = _getRate((f64)e->cvolR, (f64)e->rtgt, e->segEnd,
                            &(e->rratl));

        aSetVolume(ptr++, A_LEFT | A_VOL, e->cvolL, 0, 0);
        aSetVolume(ptr++, A_RIGHT | A_VOL, e->cvolR, 0, 0);
	aSetVolume(ptr++, A_LEFT  | A_RATE, e->ltgt, e->lratm, e->lratl);
	aSetVolume(ptr++, A_RIGHT | A_RATE, e->rtgt, e->rratm, e->rratl);
	aSetVolume(ptr++, A_AUX, e->dryamt, 0, e->wetamt);
	aEnvMixer (ptr++, A_INIT | A_AUX, osVirtualToPhysical(e->state));
    }
    else
	aEnvMixer(ptr++, A_CONTINUE | A_AUX, osVirtualToPhysical(e->state));

    *inp += (outCount<<1);
    e->delta += outCount;

    return ptr;
}

INCLUDE_ASM("asm/nonmatchings/AA720", func_800AA3C8_AAFC8);

f64
_ldexpf(f64 in, s32 ex)
{
    s32 exp;

    if ( ex ) {
	exp = 1 << ex;
	in *= (f64)exp;
    }

    return ( in );
}

INCLUDE_ASM("asm/nonmatchings/AA720", func_800AA4CC_AB0CC);

f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel)
{
    f32	        r, a;
    s32	      	i;

    samples >>=3;
    if (samples == 0){
        return ivol;
    }
    r = ((f32) (ratem<<16) + (f32) ratel)/65536;

    a = 1.0;
    for (i=0; i<32; i++){
	if( samples & 1 )
	    a *= r;
        samples >>= 1;
        if (samples == 0)
            break;
	r *= r;
    }
    ivol *= a;
    return ivol;
}
