#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int x = getpid();
    printf("Parent is : %d\n",x);
    printf("Number of children: %d\n",n);

    for(int i=0;i<n;i++){
        int y = fork();
        if(y>0){
            // printf("Child %d is created\n",y);
            // arr[i] = y;
            // wait(NULL);
            //printf("%d",arr[i]);
            wait(NULL);
            exit(1); 
        }
        else{
            printf("Child %d is created\n",getpid());
            arr[i] = getpid();
            // exit(1);
        }
        
    }

    for(int i=0;i<n;i++){
        printf("Child %d of parent %d exited\n",arr[i],x);
    }
    printf("Parent exited\n");

}