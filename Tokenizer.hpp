#include <string>
#include <vector>
#include <iostream>

class Tokenizer 
{
	private:
		std::vector<std::string> tokenized;
		int isTokInt(char *tok);
		int isQuit(char *stop);
		
	public:
		std::vector<std::string>* GetTokens();
};
