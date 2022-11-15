CC = g++
LIBS = -lm
CFLAGS = -Wall -pedantic -O2 -std=c++17

all: lab2
lab2: main.o dane_stat.o rozklad.o
		$(CC) -o lab2 main.o dane_stat.o rozklad.o $(CFLAGS) $(LIBS)
		
dane_stat.o: dane_stat.cpp rozklad.hpp
		$(CC) -o dane_stat.o -c dane_stat.cpp $(CFLAGS)
		
rozklad.o: rozklad.cpp rozklad.hpp
		$(CC) -o rozklad.o -c rozklad.cpp $(CFLAGS)
		
main.o:	main.cpp rozklad.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o
