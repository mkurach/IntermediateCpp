CC = g++
LIBS = -lm -lQt5Core -lQt5Gui -lQt5Widgets -lqwt-qt5
CFLAGS = -Wall -pedantic -std=c++17 -I/usr/include/x86_64-linux-gnu/qt5/ -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5/QtGui -fPIC -O2
 
all: lab7
lab7: main.o dane.o
		$(CC) -o lab7 main.o dane.o $(CFLAGS) $(LIBS)

dane.o: dane.cpp dane.hpp
		$(CC) -o dane.o -c dane.cpp $(CFLAGS)
		
main.o:	main.cpp
		$(CC) -o main.o -c main.cpp $(CFLAGS)
clean: rm *.o