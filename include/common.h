#ifndef _COMMON_H_
#define _COMMON_H_

#define FALSE 0
#define TRUE 1

#ifdef __sgi
// IDO 5.3 (the libleo units): no GCC attributes; asm-processor supplies the INCLUDE_ASM functions
#define __attribute__(x)
#define INCLUDE_ASM_H
#endif

#include <ultra64.h>
#include "common_structs.h"
#include "functions.h"
#include "include_asm.h"
#include "variables.h"
#include "romdata.h"
#include "macros.h"
// #include "enums.h"

#endif
