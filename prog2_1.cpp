#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Takes null terminated string. Returns whether or not
 * it is entirely integer characters
 */
int isTokInt(char *tok);

/* Takes null terminated string. Returns whether or not
 * the first string is any variation is quit and returns
 */
int isQuit(char *stop);

int main(int argc, char **argv)
{
	printf("Assignment #2-1, William Wood, woodw221@gmail.com\n");
	char input[256];
	char *point;
	char *tokens[8];
	int i = 1;
	int x;
	int z = 0;
	int count = 0;
	
	/* Detects whether or not there are sufficient command line arguments
	 * then checks for an integer for the counter to count to.
	 */
	if(argc != 2){
		printf("ERROR! Program 6 accepts 1 command line argument.\n");
		exit(1);
	}
	else{
		if( !isTokInt(argv[1])){
			printf("ERROR! Expected integer argument.\n");
			exit(1);
		}
		else{
			x = atoi(argv[1]);
		}
	}
	/* Counter begins at 0 and counts up to command line argument
	 * loop always begins with proper formatting before prompting input
	 */
	while (count < x){
		printf("> ");
		while(NULL != fgets(input, 256, stdin)){
			if (strlen(input) <= 66) {
				i = 1;
				z = 0;
				char *test = input;
				point = strtok(input, "\t\n ");
				/* Counts number of time strtok runs to determine number
				 * of tokens inputted
				 */
				while(point){
					tokens[z] = point;
					i++;
					z++;
					point = strtok(NULL, "\t\n ");
				}
				if (i >= 4 || i == 1){
					printf("ERROR! Incorrect number of tokens found.\n");
					count++;
					break;
				}
				else{
					/* if i is 3 there are two tokens and proper formatting
					 * checks are run. Increments count after every condition
					 */
					if( i == 3){
						if( isTokInt(tokens[0])){
							printf("ERROR! Expected STR INT.\n");
							count++;
							break;
						}
						else{
							if( isTokInt(tokens[1])){
								printf("STR INT\n");
								count++;
								break;
							}
							else{
								printf("ERROR! Expected STR INT.\n");
								count++;
								break;
							}
						}
					}
					else{
						/* Checks for just quit, then checks for
						 * STR then displays message and increments.
						 */
						if( isQuit(tokens[0])){
							exit(0);
						}
						if( isTokInt(tokens[0])){
							printf("ERROR! Expected STR.\n");
							count++;
							break;
						}
						else{
							printf("STR\n");
							count++;
							break;
						}
					}
					break;
				}
			}
			else{
				printf("ERROR! Input string too long.\n");
				count++;
				break;
			}
		}
	}

}

int isTokInt(char *tok){
	while(*tok != '\0'){
		if(!isdigit(*tok++)){
			return 0;
		}
	}
	return 1;
}

int isQuit(char *stop ){
	char buffer[66];
	strcpy(buffer, stop);
	for(int i = 0; i <= strlen(stop); i++){
		buffer[i] = tolower(buffer[i]);
	}
	return(!strncmp(buffer, "quit", 4));
}
