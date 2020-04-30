crun: compile run

compile:
	g++ src/awpi.cpp src/asp.cpp src/lexer.cpp src/symbol_check.cpp -o bin/awpi.out

run:
	./bin/awpi.out $(target)
