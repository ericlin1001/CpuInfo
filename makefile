all:compile run

compile:main.cpp
	g++ -o main main.cpp

run:main
	./main

clean:
	
