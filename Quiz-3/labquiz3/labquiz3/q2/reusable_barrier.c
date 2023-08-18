#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int N, K;
int C;

void increment(int *c){
    C += 1;
}

/*
Output:
N
N
N
....N times
2N
2N
....N times
.
.
. K times

*/

// 


sem_t barrier_sem1;
int rendezvous_completed = 0;
sem_t barrier_sem2;

sem_t lock;

void* worker(void* args){
    int* thread_num = (int*)args;
    for(int ii=0; ii<K; ii++){
        // Wait for all workers to finish previous loop
        
        sem_wait(&lock);
        increment(&C);
        rendezvous_completed+=1;
        if(rendezvous_completed==N){
            for (int l=0;l<N;l++)
                sem_post(&barrier_sem1);
        }
        sem_post(&lock);
        sem_wait(&barrier_sem1);

        // Wait for all workers to finish incrementing
        printf("thread_num: %d, C = %d\n", *thread_num, C);
        sem_wait(&lock);
        rendezvous_completed-=1;
        if(rendezvous_completed==0){
            for (int l=0;l<N;l++)
            sem_post(&barrier_sem2);
        }
        sem_post(&lock);
        sem_wait(&barrier_sem2);
    }
        
    return NULL;
}

int main(int argc, char *argv[]){
    printf("N: ");
    scanf("%d", &N);

    printf("K: ");
    scanf("%d", &K);
    
    int thread_id[N]; // Provide this?
    /*Create threads and other initialization and then join them*/
    sem_init(&barrier_sem1, 0, 0); // Acts as a mutex
    sem_init(&barrier_sem2, 0, 0);
    sem_init(&lock, 0, 1);

    pthread_t threads[N];
    int i;
    for(i=0; i<N; i++){
        thread_id[i] = i;
        // pthread_create(&threads[i], NULL, thread_func, (void *)&thread_id[i]);
        pthread_create(&threads[i], NULL, worker, (void *)&thread_id[i]);
    }
    for(int i=0; i<N; i++){
        pthread_join(threads[i], NULL);
    }
    /**/
    return 0;
}