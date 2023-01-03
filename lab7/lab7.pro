HEADERS += dane.hpp
HEADERS += plot.hpp
HEADERS += menu.hpp
SOURCES += dane.cpp
SOURCES += plot.cpp
SOURCES += main.cpp
SOURCES += menu.cpp

TARGET = zad7

INCPATH += /usr/include/x86_64-linux-gnu/qt5/QtWidgets
LIBS += -lQt5Core -lQt5Gui -lQt5Widgets -lqwt-qt5