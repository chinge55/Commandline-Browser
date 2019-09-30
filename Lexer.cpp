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
	if(str_pointer>=inputstr.size()-1)
		showerror("Cannot increase the pointer by 1");
	else
		str_pointer++;
}
void Lexer:: inc_pointer(int value)
{
	if(str_pointer>=inputstr.size()-value)
		showerror("cannot decrease the pointer by "+value);
	else
		str_pointer+=value;
	
}
void Lexer::dec_pointer()
{
	if(str_pointer-1<=0)
		showerror("Cannot decrease the pointer by 1");
	else
		str_pointer--;
}
void Lexer::dec_pointer(int value)
{
	if(str_pointer-value<=0)
		showerror("Cannot Decrease the value by"+value);
	else
		str_pointer-=value;
	
}
void Lexer::evaluate_token()
{
	switch(inputstr[str_pointer])
	{
		case '<':
			inc_pointer();
			checkfirst();
		default:
			showerror("Error in Evaluate_token");
	}
}
void Lexer::checkfirst()
{
	switch(inputstr[str_pointer])
	{
		case 'h':
			inc_pointer();
			checkforh();
		case 't':
			inc_pointer();
			checkfort();
		case 'b':
			inc_pointer();
			checkforb();
		case 'p':
			inc_pointer();
			checkforp();
		case '/':
			// Start deleting from the stack
		default:
			showerror("Error in the first letter");
	}
}
void Lexer::checkforb()
{
	switch(inputstr[str_pointer])
	{
		
	}
}
void Lexer::checkfort()
{
	switch(inputstr[str_pointer])
	{
		case 'i':
			inc_pointer();
			checkfortitle();
		default:
			showerror("Error in checkfort");
	}

}
void Lexer::checkfortitle()
{
	string temp = inputstr.substr(str_pointer,str_pointer+4);
	inc_pointer(4);
	if(temp.compare("tle>"))
	{
		cout << "Title found"<< endl;
		// Push title to the stack
	}

}
void Lexer::checkforh()
{
	int a = (int)inputstr[str_pointer];
	if(a>=49 && a<=57)
	{
		inc_pointer();
		checkforh1();

	}
	else
	{
		switch(inputstr[str_pointer])
		{
			case 'e':
				inc_pointer();
				checkforhead();
			case 't':
				inc_pointer();
				checkforhtml();
			default:
				showerror(1);

		}
		
	}
}
void Lexer::checkforhtml()
{
	string temp = inputstr.substr(str_pointer,str_pointer+3);
	inc_pointer(3);
	if(temp.compare("ml>"))
	{
		cout << "Html Start"<< endl;
		// push html to stack
	}
}
void Lexer:: checkforhead()
{
	string temp = inputstr.substr(str_pointer,str_pointer+3);

	if(temp.compare("ad>"))
	{
		cout << "Head Start" << endl;
		// Push head to the stack
	}

}
void Lexer:: checkforh1()
{
	cout << "h1 found"<< endl;
	// Push h1 to the stack
	// Make arrangements for h>10 and I also don't know whether h1 can be used twice or not
}

void Lexer::showerror(string error)
{

}