CC = g++ 

CFLAGS = -c -Wall -pedantic -Ofast -march=native -std=c++11 

PROG1 = MazeSolver_test

all: runit

runit: $(PROG1).o Square.o Maze.o MazeSolver.o 
		$(CC) $(PROG1).o Square.o Maze.o MazeSolver.o -o runit

Maze.o: Maze.cpp
		$(CC) $(CFLAGS) Maze.cpp

$(PROG1).o: $(PROG1).cpp
		$(CC) $(CFLAGS) $(PROG1).cpp

Square.o: Square.cpp
		$(CC) $(CFLAGS) Square.cpp

MazeSolver.o: MazeSolver.cpp
		$(CC) $(CFLAGS) MazeSolver.cpp


clean:
		rm -rf *o run


