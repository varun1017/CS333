#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd1[2];
    int fd2[2];
    int x,y,z = 0;
/*
     fd[0]  fd[1]
     close(fd[1])
*/
    pipe(fd1);
    pipe(fd2);

    int f1 = fork();
    if (f1 != 0){
        //waitpid(f1, NULL, WUNTRACED);
        // close(fd1[0]);
        x = 4;
        printf("Process A : Input value of x : %d\n",x);
        // printf("HELLO\n");
        write(fd1[1], &x, sizeof(x));
     //   exit;
        // close(fd1[1]);
        //kill(f1, SIGCONT);
        wait(NULL);
    }
    else{
        //raise(SIGSTOP);
        //wait(NULL);
        int f2 = fork();
        if(f2!=0){
            //waitpid(f2, NULL, WUNTRACED);
            // close(fd1[1]);
            close(fd1[1]);
            read(fd1[0], &x, sizeof(x));
            // close(fd1[0]);

            // close(fd2[0]);           
            // int x = 4;
            y = 5;
            printf("Process B : Input value of y : %d\n",y);
            z = x + y;
            write(fd2[1],&z,sizeof(z));
            close(fd2[1]);
            //kill(f2, SIGCONT);
            wait(NULL);
        }

        else{
            //wait(NULL);
            //raise(SIGSTOP);
             close(fd2[1]);
            read(fd2[0],&z,sizeof(z));
            // printf("%d",x);
            // printf("jnefvosbn");
            // close(fd2[0]);
            printf("Process C : Result after addition : %d \n",z);            
        }

    }
    return 0;
}

