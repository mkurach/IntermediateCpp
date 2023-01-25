CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
CFLAGS = -Wall -pedantic -std=c++17 

all: projekt
projekt: main.o  game.o bird.o obstacles.o
		$(CC) -o projekt main.o game.o bird.o obstacles.o $(CFLAGS) $(LIBS)

game.o: game.cpp  game.hpp
		$(CC) -o game.o -c game.cpp $(CFLAGS)

bird.o: bird.cpp  bird.hpp
		$(CC) -o bird.o -c bird.cpp $(CFLAGS)

obstacles.o: obstacles.cpp  obstacles.hpp
		$(CC) -o obstacles.o -c obstacles.cpp $(CFLAGS)

clean: rm *.o
