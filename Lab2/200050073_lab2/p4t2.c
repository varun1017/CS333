#include<stdio.h>    
#include<stdlib.h>

#define MAX_LIMIT 25
    
    int main(int argc, char *argv[])
    {    
    char ch;
    // , source_file[25], target_file[25];
    
    FILE *source, *target;    
    
    // printf("Enter name of file to copy\n");
    // fgets(source_file, MAX_LIMIT, stdin);    
    // scanf("%s",&source_file[0]);
    
    source = fopen(argv[1], "r");
    
        if( source == NULL )
        {
            printf("Press any key to exit...\n");
            exit(EXIT_FAILURE);
        }
    
    // printf("Enter name of target file\n");
    
    // fgets(target_file, MAX_LIMIT, stdin);
    // scanf("%s",&target_file[0]);
    
    target = fopen(argv[2], "w");
    
    if( target == NULL )
    {
        fclose(source);        
        printf("Press any key to exit...\n");        
        exit(EXIT_FAILURE);
    }    
    
    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);
        
        printf("File copied successfully.\n");        
        fclose(source);        
        fclose(target);
        
        return 0;
}