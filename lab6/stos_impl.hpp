#ifndef _stos_impl_hpp_
#define _stos_impl_hpp_
#include <iostream>

template <typename T> Stos<T>::Stos(unsigned n) {
    stos_ = new T[n];
    rozmiar_ = n;
    czypelna_ = false;
    licznik_ = 0;

}

template <typename T> unsigned Stos<T>::rozmiar() const {
    return rozmiar_;
}
template <typename T> unsigned Stos<T>::zajete() const {
    return licznik_;

}

template <typename T> void Stos<T>::printStos(){
    for(unsigned i = 0; i < licznik_; i++)
        std::cout<<"Zmienna nr "<<i<<": "<<stos_[i]<<std::endl;
    

}

template <typename T> void Stos<T>::poloz (const T& a) {

    if(czypelna_) {
        std::cout<<"Juz pelna :("<<std::endl;
    }
    else {
        stos_[licznik_] = a;
        licznik_++;
        if(licznik_ == rozmiar_)
            czypelna_ = true;
    }

}
template <typename T> T Stos<T>::zdejmij () {
    T rzecz = stos_[licznik_];
    licznik_--;
    if(czypelna_)
        czypelna_ = false;
    return rzecz;
}

#endif