#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// TODO: YOUR CODE HERE
// INITIALIZE DATA STRUCTURE TO STORE PIDS OF PROCESSES TO KILL LATER

/* Splits the string by space and returns the array of tokens
*
*/
bool var=false;
int x=0;
char **tokenize(char *line) {

    // tokenizer variables
	char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	int i, tokenIndex = 0, tokenNo = 0;

    // loop on length of line
	for(i=x; i < strlen(line); i++){

		if(i==strlen(line)-1){
			var=true;
		}

		if(line[i]=='&' && line[i+1]=='&'){
			x=i+3;
			if(x>=strlen(line)){
				var=true;
			}
			break;
		}

		char readChar = line[i];

        // tokenize on any kind of space
		if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
			token[tokenIndex] = '\0';
			if (tokenIndex != 0) {
				tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
				strcpy(tokens[tokenNo++], token);
				tokenIndex = 0; 
			}
		}
		else {
			token[tokenIndex++] = readChar;
		}
	}
	
	free(token);
	tokens[tokenNo] = NULL ;
	return tokens;
}

void my_term(char* args[]){

	int x = fork();
    if(x==0){
		char *cd = "cd";
		if(*args[0]==*cd){
			chdir(args[1]);
		}
		else{
        	int y=execvp(args[0],args);
			if(y!=0){
				printf("Error\n");
			}
		}
    }
    wait(NULL);

}


// TODO
// MAKE FUNCTIONS AS REQUIRED TO AVOID REPETITIVE WORK

int main(int argc, char* argv[]) {

	char  line[MAX_INPUT_SIZE];            
	char  **tokens;           

	// TODO: YOUR CODE HERE
	// INITIALIZE GLOBAL DATA STRUCTURE OF PIDS TO SOME DEFAULT VALUE  
	// INITIALIZE OTHER VARIABLES AS NEEDED

	while(1) {	

		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");
		scanf("%[^\n]", line);
		getchar();
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		var=false;
		x=0;
		while(x<strlen(line) && !var){
			
			tokens = tokenize(line);
			// You can maintain boolean variables to check which type of command is given by user and then
			// conditionally execute depending on them

			// TODO: YOUR CODE HERE
			my_term(tokens);
			// TODO: YOUR CODE HERE
		
			// freeing the memory
			for(int i=0;tokens[i]!=NULL;i++){
				free(tokens[i]);
			}

			free(tokens);
		}


	}
	return 0;
}


