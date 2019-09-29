#include "Lexer.h"
#include <iostream>
#include <cstring>
using namespace std;
Lexer::Lexer(string &inputstring)
{
	
	this->inputstr = inputstring;
	string* str = &inputstring;
	delete str;
	//cout << (this->inputstr) << endl;
	evaluate_token();
}
void Lexer::inc_pointer()
{
	if(str_pointer>=inputstr.size())
		showerror("pointer maxed");
	else
		str_pointer++;
}
void Lexer::dec_pointer()
{
	if(str_pointer<=0)
		showerror("pointer min");
	else
		str_pointer--;
}
void Lexer::evaluate_token()
{
	switch(inputstr[str_pointer])
	{
		case '<':
			str_pointer++;
			checkfirst();
		default:
			showerror("FIrst value Error");
	}
}
void Lexer::checkfirst()
{
	switch(inputstr[str_pointer])
	{
		case 'h':
			str_pointer++;
			cout << "Correct till now";
			cout << str_pointer << endl;
	}
}