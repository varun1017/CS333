#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include<time.h>

int account_balance = 0;

pthread_mutex_t m;

struct arg_struct {
    int arg1;
};

void* increment(void *arguments) {
    struct arg_struct *args = (struct arg_struct *)arguments;
    pthread_mutex_lock(&m);
    for (int i = 0; i < args->arg1; i++) {
        
        account_balance++;
        
    }
    pthread_mutex_unlock(&m);
    
}

int main(int argc, char* argv[]) {
    clock_t begin = clock();
    int threadNum = atoi(argv[1]);
    struct arg_struct args;
    args.arg1 = 2048000000/threadNum;
    pthread_t th[threadNum];
    int i;
    for (i = 0; i < threadNum; i++) {
        if (pthread_create(th + i, NULL, &increment,(void *)&args) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        printf("Transaction %d has started\n", i);
    }
    for (i = 0; i < threadNum; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Transaction %d has finished\n", i);
    }
    printf("Account Balance is : %d\n", account_balance);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC);
    printf("Time spent: %f ms\n",1000*time_spent);
    return 0;
}