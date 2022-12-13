CC = g++
LIBS = -lm
CFLAGS = -Wall -pedantic -std=c++17 -lboost_system

all: lab5
lab5: main.o script.o piec.o
		$(CC) -o lab5 main.o script.o piec.o $(CFLAGS) $(LIBS)
		
script.o: script.cpp piec.hpp
		$(CC) -o script.o -c script.cpp $(CFLAGS)
		
piec.o: piec.cpp piec.hpp
		$(CC) -o piec.o -c piec.cpp $(CFLAGS)
		
main.o:	main.cpp piec.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o
