#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "shellmemory.h"

int interpreter(char *commands[], int numargs); 
int help(char *commands[],int numargs); 
int quit(char *commands[],int numargs); 
int set(char *commands[],int numargs); 
int print(char *commands[],int numargs); 
int run(char *commands[],int numargs); 

int interpreter(char *commands[], int numargs){
	
	int errCode = 0;
      	 
	if(strcmp(commands[0], "help") == 0) errCode = help(commands, numargs);
	else if (strcmp(commands[0], "quit") == 0) errCode = quit(commands, numargs); 
	else if (strcmp(commands[0], "set") == 0) errCode = set(commands, numargs); 
	else if (strcmp(commands[0], "print") == 0) errCode = print(commands, numargs);
	else if (strcmp(commands[0], "run") == 0) errCode = run(commands, numargs); 
	else return 3;

	return errCode; 	
}

int help(char *commands[], int numargs){
	if(numargs > 1) return 2; 

	printf("COMMAND : DESCRIPTION \n"); 
 	printf("help : Displays all the commands \n");
	printf("quit : Exits / terminates the shell with \"Bye!\" \n"); 
	printf("set VAR STRING : Assigns a value to the shell memory \n"); 
	printf("print VAR : Displays the STRING assigned to VAR \n"); 
	printf("run SCRIPT.TXT : Executes the file SCRIPT.TXT \n"); 	
	
	return 0;
}
int quit(char *commands[], int numargs){
	if(numargs > 1) return 2; 

	printf("Bye!\n");
	exit(0); 
 }
int set (char *commands[], int numargs){
	if(numargs != 3) return 2; 

	return setVar(commands[1], commands[2]); 
 }

int print(char *commands[], int numargs){
	if(numargs != 2) return 2; 

	return printVar(commands[1]);	
}


int run(char *commands[], int numargs){
	if(numargs != 2) return 2; 

	int errCode = 0; 
	char line[1000]; 
	FILE *p = fopen(commands[1], "rt"); 

	fgets(line, 999, p); 
	while(!feof(p)){
		line[strlen(line) - 1] = '\0';
		 
		errCode = parse(line);	
		if(errCode != 0) {
			fclose(p); 
			return errCode; 
		}

		fgets(line, 999, 0); 
	}
	fclose(p); 
	return errCode;
}
