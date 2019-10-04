all:
	g++ main.cpp Lexer.h Lexer.cpp Stack.h Stack.cpp 
debug:
	g++ -g main.cpp Lexer.h Lexer.cpp Stack.h Stack.cpp

clean:
	rm *.o *.gch *.out
	
