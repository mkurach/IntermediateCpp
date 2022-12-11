CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
CFLAGS = -Wall -pedantic -std=c++17 

all: lab4
lab4: main.o  grid.o
		$(CC) -o lab4 main.o grid.o $(CFLAGS) $(LIBS)

grid.o: grid.cpp  grid.hpp
		$(CC) -o grid.o -c grid.cpp $(CFLAGS)

clean: rm *.o
