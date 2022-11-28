#include "mnozenie_macierzy.hpp"
#include <boost/thread.hpp>
#include <vector>
//#include <thread>

KontrolerMnozenia::KontrolerMnozenia(const Macierz &m1, const Macierz &m2, Macierz &m3) : m1_(m1), m2_(m2), m3_(m3) {}

boost::optional <Polozenie> KontrolerMnozenia::coMamLiczyc() {

}

std::unique_ptr<Macierz> mnozenie_macierzy (const Macierz &m1, const Macierz &m2, int p) {
    boost::thread_group watki;
    Macierz wynik(0,0);
    KontrolerMnozenia kontroler(m1,m2,wynik);
    
    std::vector <MnozycielMacierzy*> mnozyciele;
    for (int i = 0; i < p; i ++) {
        mnozyciele.push_back( new MnozycielMacierzy(kontroler));
    }
    for(int i = 0; i < p; i++) {
        watki.create_thread(std::ref(*mnozyciele[i]));
    }
    return NULL;
}

MnozycielMacierzy::MnozycielMacierzy (KontrolerMnozenia &km) : km_(km) {}

void MnozycielMacierzy::operator() () {
    

}