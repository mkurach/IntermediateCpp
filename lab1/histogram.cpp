#include "histogram.hpp"
#include <algorithm>
#include <math.h>


Histogram::Histogram () {
    srednia_akt_ = false;
    odchylenie_akt_ = false;
}

void Histogram::dodaj(float x) {
    dane_.push_back(x);
}

size_t Histogram::rozmiar () const {
    return dane_.size();
}
float Histogram::srednia () const {
    if(srednia_akt_)
        return srednia_;
    else {
        srednia_ = 0;
        std::for_each(dane_.begin(),dane_.end(),[&](float a){srednia_ += a;});
        srednia_ /= rozmiar();
        srednia_akt_ = true;
        return srednia_;        
    }

} 

float Histogram::odchylenie () const {
    if(odchylenie_akt_ && srednia_akt_)
        return odchylenie_;
    else {
        if (!srednia_akt_)
            srednia();
        odchylenie_ = 0;
        std::for_each(dane_.begin(),dane_.end(),[&](float a){odchylenie_ += (a-srednia_)*(a-srednia_);});
        odchylenie_ = sqrt(odchylenie_)/sqrt(rozmiar());
        odchylenie_akt_ = true;
        return odchylenie_;
    }
    

} 

float Histogram::max () const {
    return *std::max_element(dane_.begin(),dane_.end());
}

float Histogram::min () const{
    return *std::min_element(dane_.begin(),dane_.end());
}
