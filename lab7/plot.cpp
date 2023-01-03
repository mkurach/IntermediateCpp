#include "plot.hpp"
#include <iostream>

Plot::Plot(Dane& dane, QwtPlot &wykres ) : wykres_(wykres) {
    //dane_ = dane;
    daneCurv_.setSamples (dane.x_.data(), dane.y_.data(), dane.x_.size()); // twarde kopie danych
    daneCurv_.setStyle (QwtPlotCurve::Dots);// Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
    daneCurv_.setPen (QPen (Qt::blue, 5)); 

    regr_.setSamples (dane.x_.data(), dane.yLin_.data(), dane.x_.size());
    regr_.setStyle (QwtPlotCurve::Lines);// Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
    regr_.setPen (QPen (Qt::red, 5)); 


}

Plot::~Plot() {}

void Plot::setColor(QColor color) {
     daneCurv_.setPen (QPen (color.toRgb(), 5)); 
     wykres_.replot();

}

void Plot::drawRegression() {
    regr_.attach(&wykres_);
    daneCurv_.attach(&wykres_);
    wykres_.replot();
}

