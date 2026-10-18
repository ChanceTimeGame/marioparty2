/* libultra audio/reverb.c (2.0I), from MP1 src/972D0.c. alFxParamHdl, _loadOutputBuffer and
   _doModFunc stay in asm: their jump table / f64 constants are in the unsplit data+rodata asm. */
#define alFxPull func_800AAC10_AB810
#define alFxParam func_800AAF84_ABB84
#define alFxParamHdl func_800AAF98_ABB98
#define _loadOutputBuffer func_800AB188_ABD88
#define _loadBuffer func_800AB3A0_ABFA0
#define _saveBuffer func_800AB510_AC110
#define _filterBuffer func_800AB680_AC280
#define _doModFunc func_800AB71C_AC31C

#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>
#include "include_asm.h"

#define SWAP(in, out)	\
{			\
     s16 t = out;	\
     out = in;		\
     in = t;		\
}

Acmd *_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, s32 incount, Acmd *p);
Acmd *_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p);
f32  _doModFunc(ALDelay *d, s32 count);


Acmd *alFxPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                     Acmd *p) 
{
    Acmd        *ptr = p;
    ALFx	*r = (ALFx *)filter;
    ALFilter    *source = r->filter.source;
    s16		i, buff1, buff2, input, output;
    s16		*in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay	*d, *pd;

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input  = AL_AUX_L_OUT;
    output = AL_AUX_R_OUT;
    buff1  = AL_TEMP_0;
    buff2  = AL_TEMP_1;

    aSetBuffer(ptr++, 0, 0, 0, outCount<<1);  
    aMix(ptr++, 0, 0xda83, AL_AUX_L_OUT, input); 
    aMix(ptr++, 0, 0x5a82, AL_AUX_R_OUT, input); 

    ptr = _saveBuffer(r, r->input, input, outCount, ptr);

    aClearBuffer(ptr++, output, outCount<<1); 

    for (i = 0; i < r->section_count; i++) {
	d  = &r->delay[i];  
	in_ptr  = &r->input[-d->input];
	out_ptr = &r->input[-d->output];

	if (in_ptr == prev_out_ptr) {
	    SWAP(buff1, buff2);
	} else {  
	    ptr = _loadBuffer(r, in_ptr, buff1, outCount, ptr);
	}
	ptr = _loadOutputBuffer(r, d, buff2, outCount, ptr);

	if (d->ffcoef) {
	    aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
	    if (!d->rs && !d->lp) {
		ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);
	    }
	}

	if (d->fbcoef) {
	    aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
	    ptr = _saveBuffer(r, in_ptr, buff1, outCount, ptr);
	}

	if (d->lp)
	    ptr = _filterBuffer(d->lp, buff2, outCount, ptr);

	if (!d->rs)
	    ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);

	if (d->gain)
	    aMix(ptr++, 0, (u16)d->gain, buff2, output);

	prev_out_ptr = &r->input[d->output];
    }

    r->input += outCount;
    if (r->input > &r->base[r->length])
	r->input -= r->length;

    aDMEMMove(ptr++, output, AL_AUX_L_OUT, outCount<<1);

    return ptr;
}

s32 alFxParam(void *filter, s32 paramID, void *param)
{
    if(paramID == AL_FILTER_SET_SOURCE)
    {
	ALFilter    *f = (ALFilter *) filter;
	f->source = (ALFilter*) param;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/AB810", func_800AAF98_ABB98);

INCLUDE_ASM("asm/nonmatchings/AB810", func_800AB188_ABD88);

Acmd *_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];

#ifdef _DEBUG
    if(curr_ptr > delay_end)
        __osError(ERR_ALMODDELAYOVERFLOW, 1, delay_end - curr_ptr);
#endif

    if (curr_ptr < r->base)
    curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, buff, 0, before_end<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(curr_ptr));
        aSetBuffer(ptr++, 0, buff+(before_end<<1), 0, after_end<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(r->base));
    } else {
        aSetBuffer(ptr++, 0, buff, 0, count<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(curr_ptr));
    }

    aSetBuffer(ptr++, 0, 0, 0, count<<1);

    return ptr;

}

Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base)      
        curr_ptr += r->length;   
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) { 
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, 0, buff, before_end<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
        aSetBuffer(ptr++, 0, 0, buff+(before_end<<1), after_end<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(r->base));
        aSetBuffer(ptr++, 0, 0, 0, count<<1);
    } else {
        aSetBuffer(ptr++, 0, 0, buff, count<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
    }

    return ptr;

}

Acmd *_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p)
{
    Acmd	*ptr = p;

    aSetBuffer(ptr++, 0, buff, buff, count<<1);
    aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
    aPoleFilter(ptr++, lp->first, lp->fgain, osVirtualToPhysical(lp->fstate));
    lp->first = 0;

    return ptr;
}

INCLUDE_ASM("asm/nonmatchings/AB810", func_800AB71C_AC31C);
