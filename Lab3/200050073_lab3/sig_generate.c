#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
    int pid = atoi(argv[1]);
    sleep(3);
    printf("SIGINT signal sent to pid: %d\n",pid);
    kill(pid,SIGINT);
    sleep(3);
    printf("SIGTERM signal sent to pid: %d\n",pid);
    kill(pid,SIGTERM);
    sleep(3);
    printf("SIGKILL signal sent to pid: %d\n",pid);
    kill(pid,SIGKILL);


}