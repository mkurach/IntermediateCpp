#ifndef _histogram_hpp_
#define _histogram_hpp_
#include <vector>
#include <iostream>
#include <string>

class Histogram {
    public:
        Histogram ();
        void dodaj (float x);
        size_t rozmiar () const;
        float srednia () const; // użyj std::for_each() !
        float odchylenie () const; // użyj std::for_each() !
        float max () const; // użyj std::max_element() !
        float min () const; // użyj std::min_element() !
    private:
        std::vector<float> dane_;
        mutable bool srednia_akt_;
        mutable bool odchylenie_akt_;
        mutable float srednia_;
        mutable float odchylenie_;
};
#endif