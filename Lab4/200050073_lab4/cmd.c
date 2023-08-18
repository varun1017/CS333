#include "types.h"
#include "stat.h"
#include "user.h"
#include<stddef.h>

int main(int argc, char *argv[]){
    int x = fork();
    if(x==0){
        exec(argv[1],&argv[1]);        
    }
    else{
        wait();
        exit();
    }
}