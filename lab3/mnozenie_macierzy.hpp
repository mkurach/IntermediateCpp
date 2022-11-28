#ifndef _mnozenie_macierzy_hpp_
#define _mnozenie_macierzy_hpp_
#include <iostream>
#include "macierz.hpp"
#include <memory>
#include <mutex>
#include <optional>
#include <boost/optional.hpp>

// Kontroluje proces mnożenia macierzy (obiekt współdzielony)
class KontrolerMnozenia {
    public:
        KontrolerMnozenia (const Macierz &m1, const Macierz &m2, Macierz &m3);  // Inicjuje skladowe klasy
        boost::optional <Polozenie> coMamLiczyc (); // Zwraca współrzędne najbliższego elementu do obliczen lub kontener niezainicjowany, gdy obliczenia dobiegły końca
        inline const Macierz &czynnik1 () const {return m1_;}
        inline const Macierz &czynnik2 () const {return m2_;}
        inline Macierz &wynik () const {return m3_;}
        
    private:
        std::mutex blokada_; // blokada
        const Macierz &m1_; // pierwszy czynnik (stała referencja)
        const Macierz &m2_; // drugi czynnik (stała referencja)
        Macierz &m3_; // wynik mnożenia
};

// Funkcja mnożąca macierze m1 i m2 w p wątkach
std::unique_ptr<Macierz> mnozenie_macierzy (const Macierz &m1, const Macierz &m2, int p);

class MnozycielMacierzy { // funktor wykorzystywany w wątkach mnożących macierze
    public:
        MnozycielMacierzy (KontrolerMnozenia &km); // inicjuje składowe klasy
        void operator() (); // metoda wywoływana przy utworzeniu wątku
    private:
        KontrolerMnozenia &km_; // referencja na kontroler danego mnożenia
        const Macierz *m1_; // wskaźnik na pierwszy czynnik
        const Macierz *m2_; // wskaźnik na drugi czynnik
        Macierz *m3_; // wskaźnik na macierz wynikową
};

#endif