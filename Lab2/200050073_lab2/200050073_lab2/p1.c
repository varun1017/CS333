#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    //int y = getpid();
    int x = fork();
    if(x>0){
        printf("Parent : My process ID is: %d\n",getpid());
        printf("Parent : The child process ID is: %d\n",x);
        printf("Child : My process ID is: %d\n",x);
        printf("Child : The parent process ID is: %d\n",getpid());
    }
    // if(x==0){
    //     printf("-Parent : My process ID is: %d\n",getpid());
    //     printf("-Parent : The child process ID is: %d\n",x);
    //     printf("-Child : My process ID is: %d\n",x);
    //     printf("-Child : The parent process ID is: %d\n",getpid());
    // }

}