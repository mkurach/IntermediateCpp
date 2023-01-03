#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "dane.hpp"
#include "menu.hpp"
#include "plot.hpp"
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_point_data.h>
#include <QStringList>
#include <QComboBox>
#include <QMenuBar>
#include <QWidgetAction>
#include <QMenu>
#include <QApplication>

#include <QApplication>
#include<QSlider>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QWidget>
#include<QMenuBar>
#include<QStatusBar>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>

void print(int i) {
    std::cout<<i<<std::endl;
}
int main (int argc, char *arg[]) {

    Dane dane(arg[1]);

    QApplication app (argc, arg);  // Tworzenie okna programu
    QMainWindow *w = new QMainWindow;

    QWidget okno(w);
    w->setCentralWidget(&okno);
    okno.setWindowTitle ("Dopasowanie MNK"); // ustawia tytuł okna
    okno.setFixedSize (800, 800); // rozmiar okna 800x800

    QwtPlot wykres (&okno); // Tworzenie wykresu na konkretnym oknie
    dane.setWykres(wykres);

    /*QwtPlotCurve dane_doswiadczalne;
    dane.setDane(dane_doswiadczalne);
    dane_doswiadczalne.attach (&wykres);     // Dołączenie serii do istniejącego wykresu*/

    Plot *plot = new Plot(dane.getX(),dane.getY(),wykres);
    plot->dane_.attach(&wykres);


    QStringList colors = { "white","red","green","blue","cyan","magenta","yellow","gray","black"};


    QMenuBar *menu = new QMenuBar(&okno);
    //QMenu *colorMenu = new QMenu("&Color");
    Menu *colorMenu = new Menu("&Color");
    //colorMenu->addMenu("Red");
    //colorMenu->addMenu("Green");

    /*QComboBox *comboBox = new QComboBox(colorMenu);
    comboBox->addItems(colors);
    QWidgetAction *checkableAction = new QWidgetAction(colorMenu);
    checkableAction->setDefaultWidget(comboBox);
    colorMenu->addAction(checkableAction);*/
    menu->addMenu(colorMenu);

    //QPushButton *button = new QPushButton("&Download", &okno);

    QObject::connect(colorMenu,&Menu::colorSelected,plot,&Plot::setColor);







    w->show();

 
    return app.exec();
}