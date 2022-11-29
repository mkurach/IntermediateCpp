#include "mnozenie_macierzy.hpp"
#include <boost/thread.hpp>
#include <vector>
//#include <thread>

KontrolerMnozenia::KontrolerMnozenia(const Macierz &m1, const Macierz &m2, Macierz &m3) : m1_(m1), m2_(m2), m3_(m3), co_policzone_(0) {}

boost::optional <Polozenie> KontrolerMnozenia::coMamLiczyc() {
    blokada_.lock();
    if(co_policzone_ == m3_.rozmiar().first * m3_.rozmiar().second) {
        blokada_.unlock();
        return boost::none;
    }

    Polozenie dopoliczenia = m3_.element2polozenie(co_policzone_);
    co_policzone_++;
    blokada_.unlock();
    return dopoliczenia;
}

std::unique_ptr<Macierz> mnozenie_macierzy (const Macierz &m1, const Macierz &m2, int p) {
    boost::thread_group watki;
    std::unique_ptr<Macierz> wynik(new Macierz(m1.rozmiar().first,m2.rozmiar().second));
    KontrolerMnozenia kontroler(m1,m2,*wynik);
    
    std::vector <MnozycielMacierzy*> mnozyciele;
    for (int i = 0; i < p; i ++) {
        mnozyciele.push_back( new MnozycielMacierzy(kontroler));
    }
    for(int i = 0; i < p; i++) {
        watki.create_thread(std::ref(*mnozyciele[i]));
    }
    watki.join_all();
    return wynik;
}

MnozycielMacierzy::MnozycielMacierzy (KontrolerMnozenia &km) : km_(km) {
    m1_ = &km.czynnik1();
    m2_ = &km.czynnik2();
    m3_ = &km.wynik();

}


void MnozycielMacierzy::operator() () {
    boost::optional<Polozenie> komorka = km_.coMamLiczyc();
    int r, c;
    while(komorka.has_value()) {
        r = komorka->first;
        c = komorka->second;
        m3_->element(r,c) = 0;
        for(int i = 0; i < m1_->rozmiar().second; i++)
            m3_->element(r,c) += m1_->element(r,i) *m2_->element(i,c);
        
        komorka = km_.coMamLiczyc();
    }
    

}