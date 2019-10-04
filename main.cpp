#include <iostream>
#include <fstream>
#include "Lexer.h"
using namespace std;

int main(int argc, char** argv)
{
	const char* filename;
	const int buffer_size = 50;
	// if(argc!=2)
	// 	exit(0);
	filename = "testfile";
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(!inputfile.is_open())
		exit(0);
	cout <<"File Opened"<<endl; 
	string str;		// Using string limits the input only upto 65535 bytes(roughly)
	while(!inputfile.eof())
	{
		char sth = inputfile.get();
		str = str + sth;
	}
	Lexer *l = new Lexer(str);
	cout << "Done"<< endl;
	//TODO: Do not start Parsing from the constructor but call evaluate_token from here
	return 0;
}