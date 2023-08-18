#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void call(int l){
    
    int a = fork();
    if(l==0 && a==0){
        exit(1);
    }
    else if(l>=1 && a==0){
        printf("Child %d is created\n",getpid());
        call(l-1);
        printf("Child %d of parent %d exited\n",getpid(),getppid());
        exit(1);
    }
    else if(a!=0){
        wait(NULL);
    }

    
    
    
}

int main(){
    int n;
    scanf("%d",&n);
    int x = getpid();
    printf("Parent is : %d\n",x);
    printf("Number of children: %d\n",n);
    call(n);
    printf("Parent exited\n");

}