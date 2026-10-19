/* ADEF0: libultra libc/xprintf.c (_Printf, _Putfld), from MP3 src/2.0L/libc/xprintf.c (-O2, signed
   char). Its rodata (D53C0-D5540) is carved out of the data blob. __osGetCause is hand-written asm. */
#define _Putfld func_800AD870_AE470
#define strchr func_800A55D0_A61D0
#define strlen func_800A5610_A6210

#include "PR/ultratypes.h"
#include "lib2.0I/libc/stdarg.h"
#include "include_asm.h"

#ifndef NULL
#define NULL 0
#endif
#define TRUE 1

char *strchr(const char *, int);
unsigned int strlen(const char *);

typedef struct {
    /* 0x0 */ union {
        /* 0x0 */ long long ll;
        /* 0x0 */ double ld;
    } v;
    /* 0x8 */ const char* s;
    /* 0xC */ int n0;
    /* 0x10 */ int nz0;
    /* 0x14 */ int n1;
    /* 0x18 */ int nz1;
    /* 0x1C */ int n2;
    /* 0x20 */ int nz2;
    /* 0x24 */ int prec;
    /* 0x28 */ int width;
    /* 0x2C */ unsigned int nchar;
    /* 0x30 */ unsigned int flags;
    /* 0x34 */ char qual;
} _Pft;

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16
typedef char *outfun(char*,const char*,unsigned int);

int _Printf(outfun prout, char *arg, const char *fmt, va_list args);
void _Litob(_Pft *args, char type);
void _Ldtob(_Pft* args, char type);

#define isdigit(x) ((x >= '0' && x <= '9'))
#define LDSIGN(x) (((unsigned short *)&(x))[0] & 0x8000)

#define ATOI(dst, src)                    \
    for (dst = 0; isdigit(*src); ++src) { \
        if (dst < 999)                    \
            dst = dst * 10 + *src - '0';  \
    }

#define MAX_PAD ((sizeof(spaces) - 1))
#define PAD(s, n)                                             \
    if (0 < (n)) {                                            \
        int i, j = (n);                                       \
        for (; 0 < j; j -= i) {                               \
            i = MAX_PAD < (unsigned int)j ? (int)MAX_PAD : j; \
            PUT(s, i);                                        \
        }                                                     \
    }
#define PUT(s, n)                                \
    if (0 < (n)) {                               \
        if ((arg = (*prout)(arg, s, n)) != NULL) \
            x.nchar += (n);                      \
        else                                     \
            return x.nchar;                      \
    }
/* spaces and zeroes (33 bytes each) stay in the data blob (CFF70, CFF94): the unit's rodata is
   carved, and one object cannot sit in both halves of the blob. */
extern char D_800CF370_CFF70[33]; /* spaces: 32 ' ' */
extern char D_800CF394_CFF94[33]; /* zeroes: 32 '0' */
#define spaces D_800CF370_CFF70
#define zeroes D_800CF394_CFF94

static void _Putfld(_Pft *pf, va_list *pap, char code, char *ac);

int _Printf(outfun prout, char *arg, const char *fmt, va_list args) {
    _Pft x;

    x.nchar = 0;

    while (TRUE) {
        const char *s;
        char c;
        const char *t;
        static const char fchar[] = { ' ', '+', '-', '#', '0', '\0' };
        static const int fbit[] = { FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0 };
        char ac[32];
        s = fmt;

        for (c = *s; c != 0 && c != '%';) {
            c = *++s;
        }

        PUT(fmt, s - fmt);

        if (c == 0) {
            return x.nchar;
        }

        fmt = ++s;

        for (x.flags = 0; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }

        if (*s == '*') {
            x.width = va_arg(args, int);

            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else
            ATOI(x.width, s);

        if (*s != '.') {
            x.prec = -1;
        } else if (*++s == '*') {
            x.prec = va_arg(args, int);
            ++s;
        } else
            for (x.prec = 0; isdigit(*s); s++) {
                if (x.prec < 999)
                    x.prec = x.prec * 10 + *s - '0';
            }

        x.qual = strchr("hlL", *s) ? *s++ : '\0';

        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            ++s;
        }

        _Putfld(&x, &args, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;

        {

            if (!(x.flags & FLAGS_MINUS)) {
                int i, j;
                if (0 < (x.width)) {
                    j = x.width;
                    for (; 0 < j; j -= i) {
                        i = MAX_PAD < (unsigned int)j ? (int)MAX_PAD : j;
                        PUT(spaces, i);
                    }
                }
            }

            PUT(ac, x.n0);
            PAD(zeroes, x.nz0)

            PUT(x.s, x.n1);
            PAD(zeroes, x.nz1);

            PUT(x.s + x.n1, x.n2);
            PAD(zeroes, x.nz2);

            if (x.flags & FLAGS_MINUS) {
                PAD(spaces, x.width);
            }
        }
        fmt = s + 1;
    }
    return 0;
}

static void _Putfld(_Pft *x, va_list *args, char type, char *buff) {
    x->n0 = x->nz0 = x->n1 = x->nz1 = x->n2 =
        x->nz2 = 0;

    switch (type) {
        case 'c':
            buff[x->n0++] = va_arg(*args, int);
            break;
        case 'd':
        case 'i':
            if (x->qual == 'l') {
                x->v.ll = va_arg(*args, int);
            } else if (x->qual == 'L') {
                x->v.ll = va_arg(*args, s64);
            } else {
                x->v.ll = va_arg(*args, int);
            }

            if (x->qual == 'h') {
                x->v.ll = (s16)x->v.ll;
            }

            if (x->v.ll < 0) {
                buff[x->n0++] = '-';
            } else if (x->flags & FLAGS_PLUS) {
                buff[x->n0++] = '+';
            } else if (x->flags & FLAGS_SPACE) {
                buff[x->n0++] = ' ';
            }

            x->s = (const char *)&buff[x->n0];

            _Litob(x, type);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            if (x->qual == 'l') {
                x->v.ll = va_arg(*args, int);
            } else if (x->qual == 'L') {
                x->v.ll = va_arg(*args, s64);
            } else {
                x->v.ll = va_arg(*args, int);
            }

            if (x->qual == 'h') {
                x->v.ll = (u16)x->v.ll;
            } else if (x->qual == 0) {
                x->v.ll = (unsigned int)x->v.ll;
            }

            if (x->flags & FLAGS_HASH) {
                buff[x->n0++] = '0';

                if (type == 'x' || type == 'X') {
                    buff[x->n0++] = type;
                }
            }

            x->s =  (const char *)&buff[x->n0];
            _Litob(x, type);
            break;
        case 'e':
        case 'f':
        case 'g':
        case 'E':
        case 'G':
            //... okay?
            x->v.ld = x->qual == 'L' ? va_arg(*args, f64) : va_arg(*args, f64);

            if (LDSIGN(x->v.ld))
                buff[x->n0++] = '-';
            else if (x->flags & FLAGS_PLUS)
                buff[x->n0++] = '+';
            else if (x->flags & FLAGS_SPACE)
                buff[x->n0++] = ' ';

            x->s =  (const char *)&buff[x->n0];
            _Ldtob(x, type);
            break;

        case 'n':
            if (x->qual == 'h') {
                *(va_arg(*args, u16 *)) = x->nchar;
            } else if (x->qual == 'l') {
                *va_arg(*args, unsigned int *) = x->nchar;
            } else if (x->qual == 'L') {
                *va_arg(*args, u64 *) = x->nchar;
            } else {
                *va_arg(*args, unsigned int *) = x->nchar;
            }

            break;
        case 'p':
            x->v.ll = (long)va_arg(*args, void *);
            x->s =  (const char *)&buff[x->n0];
            _Litob(x, 'x');
            break;
        case 's':
            x->s = va_arg(*args, char *);
            x->n1 = strlen(x->s);

            if (x->prec >= 0 && x->prec < x->n1) {
                x->n1 = x->prec;
            }

            break;
        case '%':
            buff[x->n0++] = '%';
            break;
        default:
            buff[x->n0++] = type;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/ADEF0", __osGetCause);
