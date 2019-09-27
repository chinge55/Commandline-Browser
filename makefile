all:
	g++ main.cpp Lexer.h Lexer.cpp
debug:
	g++ -c main.cpp
	g++ -c Lexer.h
	g++ -c Lexer.cpp
	g++ main.o Lexer.o 

clean:
	rm *.o *.gch *.out
	
