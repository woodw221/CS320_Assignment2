#include "Tokenizer.hpp"
#include <string>
#include <vector>
#include <iostream>
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
	std::cout << "Assignment #2-2, William Wood, woodw221@gmail.com" << std::endl;

	int count = 0;
	int x;
	Tokenizer toke = Tokenizer();
    std::vector<std::string> *check;
     
     /* Detects whether or not there are sufficient command line arguments
      * then checks for an integer for the counter to count to.
      */
	if(argc != 2){
		std::cout << "ERROR! Program 6 accepts 1 command line argument." << std::endl;
        exit(1);
    }
    else{
        if( !isTokInt(argv[1])){
           std::cout << "ERROR! Expected integer argument." << std::endl;
           exit(1);
        }
        else{
           x = atoi(argv[1]);
        }
	} 
	
	while(count < x)
	{
		check  = toke.GetTokens();
        if( check->size() == 2){
            std::cout << "STR INT" << std::endl;
        }    
        else{
            std::string point = check->front();
            char *t = new char[point.length() + 1];
            strcpy(t, point.c_str());
            if( isQuit(t))
            {
                exit(0);
            }
            delete [] t;
            std::cout << "STR" << std::endl;
        }    
        count++;
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

