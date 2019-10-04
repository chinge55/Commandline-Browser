#include "Lexer.h"
#include <iostream>
#include <cstring>
using namespace std;
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
	{	if(deletion_token!=true)
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
}
void Lexer::checkforstring()
{
	string final_string;
	while(inputstr[str_pointer]!='<')
	{
		//cout << inputstr[str_pointer];
		final_string = final_string+inputstr[str_pointer];
		inc_pointer();
	}	
	stack->push(final_string);
	deletion_token = false;
	cout << final_string << endl;
}
void Lexer::checkfirst()
{
	switch(inputstr[str_pointer])
	{
		case 'h':
			inc_pointer();
			//deletion_token = false;
			checkforh();
			break;
		case 't':
			inc_pointer();
			//deletion_token = false;
			checkfort();
			break;
		case 'b':
			inc_pointer();
			//deletion_token = false;
			checkforb();
			break;
		case 'p':
			inc_pointer();
			//deletion_token = false;
			checkforp();
			break;
		case '/':
			cout <<"Start deletionkfk, everything correct till now"<<endl;
			// exit(0);
			deletion_token= true;
			inc_pointer();
			checkfirst();
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
		inc_pointer();
		cout << "P found "<< endl;
		if(deletion_token ==false)
			stack->push(TAG_P);
		else
			stack->push(TAG_PEND);
		
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_BODY);
		else
			stack->push(TAG_BODYEND);
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_BR);
		else
			stack->push(TAG_BREND);
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_TITLE);
		else
			stack->push(TAG_TITLEEND);
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_HTML);
		else
			stack->push(TAG_HTMLEND);
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_HEAD);
		else
			stack->push(TAG_HEADEND);
		deletion_token = false;
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
		if(deletion_token ==false)
			stack->push(TAG_H);
		else
			stack->push(TAG_HEND);
		deletion_token = false;
	}
	
	// Push h1 to the stack
	// Make arrangements for h>10 and I also don't know whether h1 can be used twice or not
}

void Lexer::showerror(string error)
{
	cout << error << endl;
	exit(0);
}