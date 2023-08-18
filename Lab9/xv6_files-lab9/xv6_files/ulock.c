#include "ulock.h"
#include "x86.h"
#include "defs.h"

void init_lock(struct lock_t *s) {
    s->locked = 0;
}

void 
acquire_lock(struct lock_t *s) 
{
    /* Your Code */
}

void 
release_lock(struct lock_t *s) 
{
    /* Your Code */
}


void 
init_sem(struct sem_t *s, int initval)
{
    /* Your Code */
}

void
up_sem(struct sem_t *s) 
{
    /* Your Code */
}

void 
down_sem(struct sem_t *s) 
{
    /* Your Code */
}
