#include "Lexer.h"
#include <iostream>
#include <cstring>
using namespace std;
Lexer::Lexer(string &inputstring)
{
	
	this->inputstr = inputstring;
	
	//cout << (this->inputstr) << endl;
	evaluate_token();
}
void Lexer::inc_pointer()
{
	if(str_pointer>=inputstr.size())
		showerror(1);
	else
		str_pointer++;
}
void Lexer::dec_pointer()
{
	if(str_pointer<=0)
		showerror(2);
	else
		str_pointer--;
}
void Lexer::evaluate_token()
{
	switch(inputstr[str_pointer])
	{
		case '<':
			inc_pointer();
			checkfirst();
		default:
			showerror(3);
	}
}
void Lexer::checkfirst()
{
	switch(inputstr[str_pointer])
	{
		case 'h':
			inc_pointer();
			cout << "Correct till now";
			cout << str_pointer << endl;
	}
}
void Lexer::showerror(int err_no)
{

}