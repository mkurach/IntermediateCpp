#ifndef _stos_hpp_
#define _stos_hpp_

template <typename T> class Stos {
    public:
        Stos (unsigned n);
        void poloz (const T&);
        T zdejmij ();
        unsigned rozmiar () const;
        unsigned zajete () const;
        void printStos();
    private:
        T *stos_;
        unsigned rozmiar_;
        bool czypelna_;
        unsigned licznik_;
};

#include "stos_impl.hpp"
#endif