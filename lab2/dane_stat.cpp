#include "dane_stat.hpp"
#include <fstream>
#include <iostream>

const std::string& DaneStat::nazwa() const {
    return nazwa_;
}

const std::vector <float>& DaneStatProxy::dane() const {
    if(!danestat_)
        danestat_ = new DaneStatReal(nazwa_);
    return danestat_->dane();
}

DaneStatReal::DaneStatReal(std::string nazwa) : DaneStat(nazwa), nazwa_(nazwa) {
    std::ifstream fileIn;
    float x;
    fileIn.open(nazwa_);
    if (!fileIn) {
        std::cout<<"Nie da się otworzyć! :("<<std::endl;
        exit(1);
    }
    while(fileIn >> x)
        dane_.push_back(x);

}

const std::vector <float>& DaneStatReal::dane() const {
    return dane_;

}








