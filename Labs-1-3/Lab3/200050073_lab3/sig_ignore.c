#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
    if (signo == SIGINT){}
        // printf("received SIGINT\n");
    if (signo == SIGTERM){}
        // printf("received signal2\n");

}

int main(){
    int x = getpid();
    printf("My process Id is : %d\n",x);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGTERM,sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGTERM\n");
    while(1){
        sleep(3);
        printf("Waiting...\n");
    }
}