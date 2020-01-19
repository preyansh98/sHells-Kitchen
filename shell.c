#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

int parse(char* userInput); 
void removeNewLine(char *userInput); 

void main(){

	char prompt[100] = {'$',' ','\0'};
	char userInput[1000];
	int errorCode = 0; 

	printf("Welcome to the Preyansh shell! \n");
	printf("Version 1.0 Created January 2020 \n"); 

	while(1){
		printf("%s", prompt); 
		fgets(userInput, 999, stdin);
		removeNewLine(userInput); 

		errorCode = parse(userInput); 
		
		switch(errorCode){
			case 1: break;
			case 2: printf("Wrong number of arguments entered! \n");
				break;
			case 3: printf("Unknown command \n"); 
				break;
			case -1: exit(99);
				break;
			default: break; 
		} 
	}
}

//parser just separates command and arguments and sends it in
int parse(char ui[]){	
	char tmp[200];
	char *words[100];

	int a, b, w = 0; 

	for(a=0; ui[a]==' ' && a<1000; a++);

	while(ui[a] != '\0' && a<1000){

		for(b=0;ui[a]!='\0' && ui[a]!=' ' && a<1000;a++,b++)
			tmp[b] = ui[a]; 

		tmp[b] = '\0';
		words[w] = strdup(tmp);
		a++;w++;
	}
	 
	return interpreter(words,w); 
}

void removeNewLine(char *userInput){
	userInput[strlen(userInput)-1] = '\0';
	strtok(userInput, "\r");
}
