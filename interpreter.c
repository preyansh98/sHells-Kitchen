#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int interpreter(char *commands[]); 
int help(char *commands[]); 
int quit(char *commands[]); 
int set(char *commands[]); 
int print(char *commands[]); 
int run(char *commands[]); 

int interpreter(char *commands[]){
	
	int errCode = 0; 
	 
	if(strcmp(commands[0], "help") == 0) errCode = help(commands);
	else if (strcmp(commands[0], "quit") == 0) errCode = quit(commands); 
	else if (strcmp(commands[0], "set") == 0) errCode = set(commands); 
	else if (strcmp(commands[0], "print") == 0) errCode = print(commands);
	else if (strcmp(commands[0], "run") == 0) errCode = run(commands); 
	else return 3;

	return errCode; 	
}

int help(char *commands[]){
	       
	return 1;
}
int quit(char *commands[]){return 1; }
int set (char *commands[]){return 1; }
int print(char *commands[]){return 1; }
int run(char *commands[]){return 1; }
