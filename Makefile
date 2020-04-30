crun: compile run

compile:
	g++ src/*.cpp -o bin/awpi.out

run:
	./bin/awpi.out $(target)
