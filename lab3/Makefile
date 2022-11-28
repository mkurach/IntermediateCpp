CC = g++
LIBS = -lm
CFLAGS = -Wall -pedantic -O2 -std=c++17 -lboost_system -lboost_thread -lpthread

all: lab3
lab3: main.o macierz.o mnozenie_macierzy.o
		$(CC) -o lab3 main.o macierz.o mnozenie_macierzy.o $(CFLAGS) $(LIBS)
		
macierz.o: macierz.cpp mnozenie_macierzy.hpp
		$(CC) -o macierz.o -c macierz.cpp $(CFLAGS)
		
mnozenie_macierzy.o: mnozenie_macierzy.cpp mnozenie_macierzy.hpp
		$(CC) -o mnozenie_macierzy.o -c mnozenie_macierzy.cpp $(CFLAGS)
		
main.o:	main.cpp mnozenie_macierzy.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o
