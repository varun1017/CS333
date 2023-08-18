#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int fd[2];

    pipe(fd);

    int f1 = fork();
    if (f1 == 0){
        //waitpid(f1, NULL, WUNTRACED);
        // close(fd1[0]);
        int Ax;
        printf("Process A : Input value of x : ");
        scanf("%d",&Ax);
        // printf("HELLO\n");
        write(fd[1], &Ax, sizeof(Ax));
     //   exit;
        close(fd[1]);
        //kill(f1, SIGCONT);
    }
    else{
        //raise(SIGSTOP);
        //wait(NULL);
        int f2 = fork();
        if(f2==0){
            //waitpid(f2, NULL, WUNTRACED);
            // close(fd1[1]);
            int Bx,By;
            //close(fd[1]);
            read(fd[0], &Bx, sizeof(Bx));
            close(fd[0]);

            // close(fd2[0]);           
            // int x = 4;
            printf("Process B : Input value of y : ");
            scanf("%d",&By);
            int Bz;
            Bz = Bx + By;
            write(fd[1],&Bz,sizeof(Bz));
            close(fd[1]);
            //kill(f2, SIGCONT);
            //wait(NULL);
        }

        else{
            wait(NULL);
            //raise(SIGSTOP);
            //close(fd2[1]);
            int z;
            read(fd[0],&z,sizeof(z));
            //int z = Cz-'0'-'0';
            // printf("%d",x);
            // printf("jnefvosbn");
            // close(fd2[0]);
            printf("Process C : Result after addition : %d \n",z);            
        }

    }
    return 0;
}
