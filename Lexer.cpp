#include "Lexer.h"
#include <iostream>
#include <cstring>
using namespace std;
//TODO: Create a function that takes in different parameters for different html tags and pushes all of them into the stack
//TODO: Create a similar function to delete them from the stack
Lexer::Lexer(string &inputstring)
{
	
	this->inputstr = inputstring;
	Stack *stack = new Stack();
	this->stack = stack;
	//cout << (this->inputstr) << endl;
	evaluate_token();
	// evaluate_token();
	// evaluate_token();
	
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
	while(str_pointer<=inputstr.size())
	{	
		switch(inputstr[str_pointer])
		{
			case '<':
				inc_pointer();
				checkfirst();
				break;
			case '\n':
				inc_pointer();
				break;
			case ' ':
				inc_pointer();
				break;
			default:
				checkforstring();
				break;
		}
	}
}
void Lexer::checkforstring()
{
	while(inputstr[str_pointer]!='<')
	{
		cout << inputstr[str_pointer];
		inc_pointer();
	}	
}
void Lexer::checkfirst()
{
	switch(inputstr[str_pointer])
	{
		case 'h':
			inc_pointer();
			checkforh();
			break;
		case 't':
			inc_pointer();
			checkfort();
			break;
		case 'b':
			inc_pointer();
			checkforb();
			break;
		case 'p':
			inc_pointer();
			checkforp();
			break;
		case '/':
			cout <<"Start deletionkfk, everything correct till now"<<endl;
			exit(0);
			break;
			// Start deleting from the stack
		default:
			showerror("Error in the first letter");
			break;
	}
}
void Lexer::checkforp()
{
	if(inputstr[str_pointer]=='>')
	{
		cout << "P found "<< endl;
		stack->push(TAG_P);
	}
	else
	{
		showerror("P not found");
	}
}
void Lexer::checkforb()
{
	switch(inputstr[str_pointer])
	{
		case 'o':
			inc_pointer();
			checkforbody();
			break;
		case 'r':
			inc_pointer();
			checkforbr();
			break;
		default:
			showerror("Error in checkforb");
			break;
	}
}
void Lexer::checkforbody()
{
	string temp = inputstr.substr(str_pointer,str_pointer+3);
	inc_pointer(3);
	if(temp.compare("dy>"))
	{
		cout << "Body Found"<< endl;
	}
	else
	{
		showerror("Body not found");
	}	
}
void Lexer::checkforbr()
{
	if(inputstr[str_pointer]=='>')
	{
		cout << "Br found"<< endl;
		stack->push(TAG_BR);
	}
	else
	{
		showerror("Br not found");
	}
	
}

void Lexer::checkfort()
{
	switch(inputstr[str_pointer])
	{
		case 'i':
			inc_pointer();
			checkfortitle();
			break;
		default:
			showerror("Error in checkfort");
			break;
	}

}
void Lexer::checkfortitle()
{
	string temp = inputstr.substr(str_pointer,str_pointer+4);
	inc_pointer(4);
	if(temp.compare("tle>"))
	{
		cout << "Title found"<< endl;
		stack->push(TAG_TITLE);
	}
	else
	{
		showerror("Title Not found");
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
				break;
			case 't':
				inc_pointer();
				checkforhtml();
				break;
			default:
				showerror("Error in h");
				break;

		}
		
	}
}
void Lexer::checkforhtml()
{
	string temp = inputstr.substr(str_pointer,str_pointer+3);
	inc_pointer(3);
	if(temp.compare("ml>"))
	{
		cout << "Html Starts"<< endl;
		// push html to stack
	}
	else
	{
		showerror("Html not found");
	}
	
}
void Lexer:: checkforhead()
{
	string temp = inputstr.substr(str_pointer,str_pointer+3);
	inc_pointer(3);
	if(temp.compare("ad>"))
	{
		cout << "Head Start" << endl;
		// Push head to the stack
	}
	else
	{
		showerror("Head not found");
	}
	

}
void Lexer:: checkforh1()
{

	if(inputstr[str_pointer]=='>')
	{
		inc_pointer();
		cout << "h1 found"<< endl;
	}
	
	// Push h1 to the stack
	// Make arrangements for h>10 and I also don't know whether h1 can be used twice or not
}

void Lexer::showerror(string error)
{
	cout << error << endl;
	exit(0);
}