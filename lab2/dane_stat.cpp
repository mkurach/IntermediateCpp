#include "dane_stat.hpp"
#include <fstream>
#include <iostream>

const std::string& DaneStat::nazwa() const {
    return nazwa_;
}


const std::vector <float>& DaneStatProxy::dane() const {
    if(!danestat_) 
        danestat_ = new DaneStatReal(nazwa_);
    danestat_->dane();
}

const std::vector <float>& DaneStatReal::dane() const {
    std::ifstream fileIn;
    std::vector <float> dane;
    float x;

    fileIn.open(nazwa());
    if (!fileIn) {
        std::cout<<"Nie da się otworzyć ! :("<<std::endl;
        exit(1);
    }
    while(fileIn >> x)
        dane.push_back(x);
    
    return dane;
}






