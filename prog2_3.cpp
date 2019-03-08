#include "Stack.hpp"
#include "Tokenizer.hpp"
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Takes null terminated string. Returns whether or not
 * it is entirely integer characters
 */
int isTokInt(char *tok);

/* Takes null terminated string. Returns whether or not
 * the first string is any variation is quit and returns
 */
int isQuit(char *stop);

int main (int argc, char **argv)
{
    std::cout << "Assignment #2-3, William Wood, woodw221@gmail.com" << std::endl;
    
    int x;
    Tokenizer toke = Tokenizer();
    std::vector<std::string> *retToke;
	Stack<int> madness = Stack<int>();

    if(argc !=2 )
    {
        std::cout << "ERROR! Program accepts 1 command line argument." << std::endl;
        exit (EXIT_FAILURE);
    }
    
    if ( !isTokInt(argv[1]))
    {
        std::cout << "ERROR! Expected integer argument." << std::endl;
        exit (EXIT_FAILURE);
    }
    else
    {
         x = atoi(argv[1]);
    }

    int count = 0;

    while( count < x)
    {
		/* Retrieves the tokens from the vector pointer and
		 * converts them into formats used to check for the
		 * words push and pop then executes the commands
		 */
        retToke = toke.GetTokens();
		std::string test = retToke->front();
		std::string bTest = retToke->back();
		char *cTest = new char[test.length()+1];
		char *dTest = new char[bTest.length()+1];
		strcpy(cTest, test.c_str());
		strcpy(dTest, bTest.c_str());
		int i = atoi(dTest);
		
		if(!strncmp(cTest, "push", 4))
		{
			madness.Push(i);	
		}
		if(!strncmp(cTest, "pop", 4))
		{		
			madness.Pop();
		}

		count++;
		delete [] cTest;
		delete [] dTest;
    }
    madness.Print();
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
