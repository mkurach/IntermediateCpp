CC = g++
LIBS = -lm
CFLAGS = -Wall -pedantic -std=c++17
 
all: lab6
lab6: main.o stos.o
		$(CC) -o lab6 main.o stos.o $(CFLAGS) $(LIBS)
		
stos.o: stos.cpp stos.hpp stos_impl.hpp
		$(CC) -o stos.o -c stos.cpp $(CFLAGS)
		
main.o:	main.cpp stos.hpp stos_impl.hpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o
