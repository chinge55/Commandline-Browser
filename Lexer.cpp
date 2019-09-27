#include "Lexer.h"
#include <sstream>
#include <iostream>
using namespace std;
Lexer::Lexer(char* data)
{
	std::stringstream stream1;
	if(*data =='<')
	{
		data++;
		while(*data!='>')
		{
			stream1 << *data;
			data++;
		}
	}
	string stringfile;
	stream1 >> stringfile;
	cout << stringfile<<endl;
}