#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseInput(char* userInput); 

void main(){

	char prompt[100] = {'$', ' ', 's', 'H','E','L','L',' ','\0'};
	char userInput[1000];
	int errorCode = 0; 

	printf("Welcome to the Preyansh shell! \n");
	printf("Version 1.0 Created January 2020"); 

	while(1){
		printf("%s", prompt); 
		fgets(userInput, 999, stdin);

		errorCode = parseInput(userInput); 
		
		switch(errorCode){
			case 1: break;
			case 2: printf("Wrong number of arguments entered!");
				break;
			case 3: printf("Command not recognized!"); 
				break;
			case -1: exit(99);
				break;
			default: break; 
		} 
	}
}

int parseInput(char* userInput){
	char _input[1000];
        strcpy(_input, userInput); 
	char *command = strtok(_input, " "); 
	
	// check if valid command, or else through a list error code 3
		
	return 0; 
}
