#include<stdio.h>    
#include<stdlib.h>

#define MAX_LIMIT 25
    
int main(int argc, char *argv[]){    
    char ch;
    
    FILE *source, *target;    

    source = fopen(argv[1], "r");
    
    if( source == NULL ){
        printf("Error1\n");
        exit(EXIT_FAILURE);
    }
    
    target = fopen(argv[2], "w");
    
    if( target == NULL ){
        fclose(source);        
        printf("Error2\n");        
        exit(EXIT_FAILURE);
    }    
    
    while( ( ch = fgetc(source) ) != EOF ){
        fputc(ch, target);
    }   
    fclose(source);        
    fclose(target);
        
    return 0;
}