#include "plot.hpp"
#include <iostream>

Plot::Plot(std::vector<double> &x, std::vector<double>& y, QwtPlot &wykres ) : wykres_(wykres) {
    dane_.setSamples (x.data(), y.data(), x.size()); // twarde kopie danych
    dane_.setStyle (QwtPlotCurve::Dots);// Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
    dane_.setPen (QPen (Qt::blue, 3)); 

}

Plot::~Plot() {}

void Plot::setColor(QColor color) {
     dane_.setPen (QPen (color.toRgb(), 3)); 
     wykres_.replot();

}