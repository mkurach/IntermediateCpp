CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
CFLAGS = -Wall -pedantic -std=c++17 

all: projekt
projekt: main.o  game.o 
		$(CC) -o projekt main.o game.o  $(CFLAGS) $(LIBS)

game.o: game.cpp  game.hpp
		$(CC) -o game.o -c game.cpp $(CFLAGS)

clean: rm *.o
