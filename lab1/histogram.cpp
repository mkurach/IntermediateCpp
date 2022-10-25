#include "histogram.hpp"
#include <algorithm>


Histogram::Histogram () {
    //std::cout<<"Stworzony"<<std::endl;
}

void Histogram::dodaj(float x) {
    dane_.push_back(x);
}

size_t Histogram::rozmiar () const {
    return dane_.size();
}
float Histogram::srednia () const {
    float sr = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){sr+=a/rozmiar();});
    return sr;

} // użyj std::for_each() !

float Histogram::odchylenie () const {

} // użyj std::for_each() !

float Histogram::max () const {

} // użyj std::max_element() !

float Histogram::min () const{

} // użyj std::min_element() !
