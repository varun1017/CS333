#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1];

void head(int fd,int numl,char* fn){
    int n;
    int i = 0;
    char* filler = "-----";
    printf(1,"%s",filler);
    printf(1,"%s",fn);
    printf(1,"%s\n",filler);
    while((n = read(fd, buf,1)) > 0 && i<numl) {
        if(buf[0]=='\n'){
            i++;
        }
        if (write(1, buf, 1) != 1) {
            printf(1, "head: write error\n");
            exit();
        }
    }
    if(n < 0){
        printf(1, "head: read error\n");
        exit();
    }
}

int main(int argc, char *argv[]){
    int fd, i;

    if(argc <= 1){
        //head(0,0);
        exit();
    }
    int n = atoi(argv[1]);
    

    for(i = 2; i < argc; i++){
        if((fd = open(argv[i], 0)) < 0){
        printf(1, "head: cannot open %s\n", argv[i]);
        exit();
        }
        head(fd,n,argv[i]);
        close(fd);
    }
    exit();
}
