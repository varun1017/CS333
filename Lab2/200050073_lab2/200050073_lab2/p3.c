#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_LIMIT 50

int main(){

    while(1){
    
        printf(">>> ");

        char str1[MAX_LIMIT+2]="./";


        scanf("%s",&str1[2]);
        

        //int process=getpid();
        int child=fork();

        if(child==0){
            char *args[]={str1,NULL};
            // printf("%s",str1);
            execvp(args[0],args);
            //break;
        }
        else{
            wait(NULL);
        }
  
    }
}