#include "Tokenizer.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



std::vector<std::string>* Tokenizer::GetTokens()
{
	tokenized.clear();
	int i = 1;
	int x = 1;
	int z = 0;
	char input[256];
	char *token;
	char *point;
	char *tokens[256];
	while (x == 1){
        tokenized.clear();
		printf("> ");
		while(NULL != fgets(input, 256, stdin)){
			if (strlen(input) <= 66) {
				i = 1;
				z = 0;
				point = strtok(input, "\t\n ");
				/* Counts number of time strtok runs to determine number
				 * of tokens inputted
				 */
				while(point){
					tokens[z] = point;
					token = point;
					tokenized.push_back(std::string(token));
					i++;
					z++;
					point = strtok(NULL, "\t\n ");
				}
				if (i >= 4 || i == 1){
					printf("ERROR! Incorrect number of tokens found.\n");
					break;
				}
				else{
					/* if i is 3 there are two tokens and proper formatting
					 * checks are run. Breaks back to beginning for new input
					 */
					
					if( i == 3){
						if( isTokInt(tokens[0])){
						printf("ERROR! Expected STR INT.\n");
						break;
						}
						else{
							if( isTokInt(tokens[1])){
								return &tokenized;
								break;
							}
							else{
								printf("ERROR! Expected STR INT.\n");
								break;
							}
						}	
					}
					else{
						/* Checks for just quit, then checks for
						 * STR then displays message and breaks to beginning.
						 */
						if( isQuit(tokens[0])){
                            return &tokenized;
						}
						if( isTokInt(tokens[0])){
							printf("ERROR! Expected STR.\n");
							break;
						}
						else{
							return &tokenized;
							break;
						}
					}
					break;
				}
			}
		}
	}
}

int Tokenizer::isTokInt(char *tok)
{
	while(*tok != '\0'){
		if(!isdigit(*tok++)){
			return 0;
		}
	}
	return 1;
}

int Tokenizer:: isQuit(char *stop)
{
	char buffer[66];
	strcpy(buffer, stop);
	for(int i = 0; i <= strlen(stop); i++){
		buffer[i] = tolower(buffer[i]);
	}
	return(!strncmp(buffer, "quit", 4));
}
