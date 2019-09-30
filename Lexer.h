#include <iostream>
class Lexer
{
private:
	std::string inputstr;
	int str_pointer = 0;
public:
	Lexer(std::string &inputstring);
	void evaluate_token();
	void showerror(int err_no);
	// checking start
	void checkfirst();
	void inc_pointer();
	void dec_pointer();
};