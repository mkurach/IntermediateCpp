#include "histogram.hpp"
#include <algorithm>
#include <math.h>


Histogram::Histogram () {
}

void Histogram::dodaj(float x) {
    dane_.push_back(x);
}

size_t Histogram::rozmiar () const {
    return dane_.size();
}
float Histogram::srednia () const {
    float sr = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){sr += a/rozmiar();});
    srednia_ = sr;
    return sr;

} 

float Histogram::odchylenie () const {
    float licznik = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){licznik += pow(a-srednia_,2);});
    licznik = sqrt(licznik);
    odchylenie_ = licznik/sqrt(rozmiar());
    return licznik/sqrt(rozmiar());

} 

float Histogram::max () const {
    return *std::max_element(dane_.begin(),dane_.end());
}

float Histogram::min () const{
    return *std::min_element(dane_.begin(),dane_.end());
}
