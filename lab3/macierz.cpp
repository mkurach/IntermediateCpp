#include "macierz.hpp"

Macierz::Macierz (std::istream &is) {
    is>>n_;
    is>>m_;
    mac_ = new int[n_ * m_];

    int tmp;
    for (int i = 0; i < n_ * m_; i++) {
        is>>tmp;
        mac_[i] = tmp;
    }
}

Macierz::Macierz (int n, int m) : n_(n), m_(m) {
    mac_ = new int [n_ * m_];
}

Macierz::~Macierz() {
    delete mac_;
}

int Macierz::element(int i, int j) const {
    return mac_[i*m_ + j];
}

int& Macierz::element (int i, int j) {
    return mac_[i*m_ +j];
}

RozmiarMacierzy Macierz::rozmiar() const {
    return std::make_pair(n_,m_);
}

std::ostream &operator<< (std::ostream &os, const Macierz &m) {
    os<<m.n_<<" "<<m.m_<<"\n";
    for(int i = 0; i < m.n_; i++) {
        for(int j = 0; j < m.m_; j++) {
            os<<m.element(i,j)<<" ";
        }
        os<<"\n";
    }
    return os;
}

