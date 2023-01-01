#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "dane.hpp"
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_point_data.h>

int main (int argc, char *arg[]) {

    Dane dane(arg[1]);

    QApplication app (argc, arg);  // Tworzenie okna programu
    QWidget okno;
    okno.setWindowTitle ("Dopasowanie MNK"); // ustawia tytuł okna
    okno.setFixedSize (800, 800); // rozmiar okna 800x800

    QwtPlot wykres (&okno); // Tworzenie wykresu na konkretnym oknie
    
    wykres.setTitle ("Dopasowanie MNK"); // Ustawienie tytułu wykresu

    wykres.setAxisTitle (QwtPlot::xBottom, "Nr kanału"); // Ustawienia tytułów osi: yLeft, yRight, xBottom, xTop
    wykres.setAxisTitle (QwtPlot::yLeft, "Napięcie / V");

    wykres.setFixedSize (775, 775); // Ustawienie rozmiarów wykresu

    wykres.setCanvasBackground(QBrush (QColor (0xff,0xfa, 0x6b))); // Ustawienie koloru tła

    wykres.setAxisScale (QwtPlot::xBottom, dane.getMinX(), dane.getMaxX()); // Ustawienie zakresu osi
    wykres.setAxisScale (QwtPlot::yLeft, dane.getMinY(), dane.getMaxY());

    QwtPlotCurve dane_doswiadczalne;
    dane_doswiadczalne.setSamples (dane.getX().data(), dane.getY().data(), dane.getX().size()); // twarde kopie danych

    dane_doswiadczalne.setStyle (QwtPlotCurve::Dots);// Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots

    dane_doswiadczalne.setPen (QPen (Qt::blue, 3));     // Ustawienie „pióra”: kolor, grubość:

    dane_doswiadczalne.attach (&wykres);     // Dołączenie serii do istniejącego wykresu


    okno.show(); // pokazuje okno
    return app.exec();
}