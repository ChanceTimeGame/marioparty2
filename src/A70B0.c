/* A70B0: from Mario Party 1 src/lib/2.0I/os/thread.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "osint.h"

void __osDequeueThread(register OSThread** queue, register OSThread* t) {
    register OSThread* pred;
    register OSThread* succ;

    pred = (OSThread*)queue;
    succ = pred->next;
    while (succ != NULL) {
        if (succ == t) {
            pred->next = t->next;
            return;
        }
        pred = succ;
        succ = pred->next;
    }
}
