all:
	bison -d -o parser.cpp parser.y
	flex scanner.lex
	g++ -std=gnu++11 -DWIN32 -c -o ast.o ast.cpp
	g++ -std=gnu++11 -DWIN32 -c -o parser.o parser.cpp
	g++ -std=gnu++11 -DWIN32 -c -o lex.yy.o lex.yy.c
	g++ -std=gnu++11 -DWIN32 -c -o util.o util.cpp
	g++ -std=gnu++11 -DWIN32 -c -o main.o main.cpp
	g++ -o model_parser.exe main.o parser.o lex.yy.o ast.o util.o
	./model_parser.exe <test.tmf