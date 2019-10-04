#include <iostream>
#include "Stack.h"
class Lexer
{
private:
	std::string inputstr;
	int str_pointer = 0;
	Stack *stack;
	bool deletion_token = false;
	// int var_no[];
	// int var_pointer[];
public:
	Lexer(std::string &inputstring);
	void evaluate_token();
	void showerror(std::string error);
	void inc_pointer();
	void inc_pointer(int value);
	void dec_pointer();
	void dec_pointer(int value);
	Stack* getStack();
	// checking start
	void checkfirst();
		void checkforh();
			void checkforhtml();
			void checkforh1();
			void checkforhead();
		void checkfort();
			void checkfortitle();
		void checkforb();
			void checkforbody();
			void checkforbr();
		void checkforp();
		void checkforstring();


};