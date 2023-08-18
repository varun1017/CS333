#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int x = fork();
    if(x==0){
        printf("Child : My process id is: %d\n",getpid());
        printf("Child : The parent process id is: %d\n",getppid());
        sleep(5);
        printf("Child : After sleeping for 5 seconds\n");
        printf("Child : My process id is: %d\n",getpid());
        printf("Child : The parent process id is: %d\n",getppid());
        
    }
    else{
        printf("Parent : My process id is: %d\n",getpid());
        printf("Parent : The child process id is: %d\n",x);
    }
}