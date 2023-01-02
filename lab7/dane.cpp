#include "dane.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

Dane::Dane(const char* name) {

    std::ifstream file(name);
    double x, y;
    while(file>>x && file>>y) {
        x_.push_back(x);
        y_.push_back(y);
    }
    
    minX_ = *std::min_element(x_.begin(),x_.end());
    minY_ = *std::min_element(y_.begin(),y_.end());

    
    maxX_ = *std::max_element(x_.begin(),x_.end());
    maxY_ = *std::max_element(y_.begin(),y_.end());

    m_ = 0.1;
    double deltaX = maxX_ - minX_;
    double deltaY = maxY_ - minY_;

    wMin_ = minX_ - m_ * deltaX;
    wMax_ = maxX_ + m_ * deltaX;
    hMin_ = minY_ - m_ * deltaY;
    hMax_ = maxY_ + m_ * deltaY;

    findParameters();
    makeRegression();

}
Dane::~Dane() {}

std::vector<double>& Dane::getX() {
    return x_;
}
std::vector<double>&  Dane::getY() {
    return y_;
}


void Dane::setWykres(QwtPlot &wykres) {

    wykres.setTitle ("Dopasowanie MNK"); // Ustawienie tytułu wykresu
    wykres.setAxisTitle (QwtPlot::xBottom, "Nr kanału"); // Ustawienia tytułów osi: yLeft, yRight, xBottom, xTop
    wykres.setAxisTitle (QwtPlot::yLeft, "Napięcie / V");
    wykres.setFixedSize (775, 775); // Ustawienie rozmiarów wykresu
    wykres.setCanvasBackground(QBrush (QColor (255,255, 255))); 
    wykres.setAxisScale (QwtPlot::xBottom, wMin_, wMax_); // Ustawienie zakresu osi
    wykres.setAxisScale (QwtPlot::yLeft, hMin_, hMax_);
}

void Dane::setDane(QwtPlotCurve &dane_doswiadczalne) {

    dane_doswiadczalne.setSamples (x_.data(), y_.data(), x_.size()); // twarde kopie danych
    dane_doswiadczalne.setStyle (QwtPlotCurve::Dots);// Ustawienie stylu QwtPlotCurve: Lines, Sticks, Steps, Dots
    dane_doswiadczalne.setPen (QPen (Qt::blue, 3));     // Ustawienie „pióra”: kolor, grubość:
}

void Dane::findParameters() {

    float sx = 0, sy = 0, sxx = 0, syy = 0, sxy = 0;
    float x,y;

    for(size_t i = 0; i < x_.size(); i++) {
        x = x_[i];
        y = y_[i];
        sx += x;
        sy += y;
        sxx += x*x;
        syy += y*y;
        sxy += x*y;
    }
    float delta = x_.size()*sxx-sx*sx;

    params_ = std::make_pair((x_.size()*sxy - sx*sy) / delta,(sxx*sy - sx*sxy) / delta);

}

void Dane::makeRegression() {
    for(auto x : x_) 
        yLin_.push_back(params_.first*x+params_.second);

}