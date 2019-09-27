#include <iostream>
#include <fstream>
#include "Lexer.h"
using namespace std;

int main(int argc, char** argv)
{
	const char* filename;
	const int buffer_size = 50;
	if(argc!=2)
		exit(0);
	filename = argv[1];
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(!inputfile.is_open())
		exit(0);
	cout <<"File Opened"<<endl;
	char *something = new char[buffer_size];
	inputfile >> *something;
	cout << *something << endl;

	// cout << something << endl;
	// cout << *something << endl;
	// cout << &something << endl;
	// inputfile >> something;
	// cout << something << endl;

	//TODO: Need to do something for whitespace, but leave it for now
	//Lexer *lexer = new Lexer(something);
	return 0;
}