CC = g++
LIBS = -lm
CFLAGS = -Wall -pedantic -O2 -std=c++17

all: lab1
lab1: main.o histogram.o billing.o
		$(CC) -o lab1 main.o histogram.o billing.o $(CFLAGS) $(LIBS)
		
histogram.o: histogram.cpp billing.hpp
		$(CC) -o histogram.o -c histogram.cpp $(CFLAGS)
		
billing.o: billing.cpp billing.hpp
		$(CC) -o billing.o -c billing.cpp $(CFLAGS)
		
main.o:	main.cpp billing.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o
