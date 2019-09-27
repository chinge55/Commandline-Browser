#include <iostream>
#include <fstream>
#include "Lexer.h"
using namespace std;

int main(int argc, char** argv)
{
	const char* filename;
	if(argc!=2)
		exit(0);
	filename = argv[1];
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(!inputfile.is_open())
		exit(0);
	cout <<"File Opened"<<endl;
	char* something;
	//TODO: Need to do something for whitespace, but leave it for now
	Lexer *lexer = new Lexer(something);
	return 0;
}