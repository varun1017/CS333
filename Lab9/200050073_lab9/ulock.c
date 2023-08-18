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
    // for(;;) {
    //     if(!s->locked) {
    //         s->locked = 1;
    //         break;
    //     }
    // }
    while (xchg(&s->locked, 1) == 1)
        ;
    
    __sync_synchronize();

}

void 
release_lock(struct lock_t *s) 
{
    /* Your Code */
    // s->locked = 0;
  // The + in "+m" denotes a read-modify-write operand.
  
  asm volatile("movl $0, %0" : "+m" (s->locked) : );

  __sync_synchronize();

}


void 
init_sem(struct sem_t *s, int initval)
{
    /* Your Code */
    s->val = initval;
}

void
up_sem(struct sem_t *s) 
{
    /* Your Code */
    acquire_lock(&s->lk);
    signal_sem(s);
    s->val++;
    release_lock(&s->lk);

}

void 
down_sem(struct sem_t *s) 
{
    /* Your Code */
    acquire_lock(&s->lk);
    while(s->val==0){
        block_sem(s);
    }
    s->val--;
    release_lock(&s->lk);
}
