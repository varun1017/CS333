#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int n;
    scanf("%d",&n);
    int x = fork();
    //int y = getpid();
    if(x==0){
        for(int i=1;i<=n;i++){
            printf("C %d %d",getpid(),i);
            printf("\n");
        }
    }
    if(x>0){
        wait(NULL);
        for(int j=n+1;j<=2*n;j++){            
            printf("P %d %d",getpid(),j);
            printf("\n");
        }
    }
    
}