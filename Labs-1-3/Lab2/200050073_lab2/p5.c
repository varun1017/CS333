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
        int Ax;
        printf("Process A : Input value of x : ");
        scanf("%d",&Ax);
        write(fd[1], &Ax, sizeof(Ax));
        close(fd[1]);

    }
    else{
        int f2 = fork();
        if(f2==0){
            int Bx,By;
            read(fd[0], &Bx, sizeof(Bx));
            close(fd[0]);

            printf("Process B : Input value of y : ");
            scanf("%d",&By);
            int Bz;
            Bz = Bx + By;
            write(fd[1],&Bz,sizeof(Bz));
            close(fd[1]);
        }

        else{
            wait(NULL);
            int z;
            read(fd[0],&z,sizeof(z));
            printf("Process C : Result after addition : %d \n",z);            
        }

    }
    return 0;
}
