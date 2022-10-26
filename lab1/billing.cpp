#include "billing.hpp"
#include "histogram.hpp"
#include <map>
#include <fstream>
#include <iomanip>

std::string Polaczenie::kod() const {
    return nr.substr(0,2);
}

std::istream &operator>>(std::istream &is, Polaczenie &p) {
    is>>p.dzien;
    is>>p.nr;
    is>>p.czas;
    return is;
}

Billing::Billing(std::istream &is) {
    std::cout<<"Podaj nazwe pliku"<<std::endl;
    std::string nazwa;
    is>>nazwa;
    std::ifstream file(nazwa);
    if(!file){
        std::cerr<<"Nie mozna otworzyc pliku :("<<std::endl;
        exit(0);
    }

    Polaczenie polaczenie;
    while(file>>polaczenie) 
        blng_.push_back(polaczenie);

    //for(auto vec : blng_)
      // std::cout<<vec.dzien<<"\t"<<vec.nr<<"\t"<<vec.czas<<"\t"<<vec.kod()<<std::endl;
}

void Billing::statystykaDzienna (std::ostream &os) const {
    std::vector <unsigned> stat (31, 0); 
    for(auto pol : blng_)
        stat[pol.dzien-1]++;

    unsigned N = blng_.size();

    os<<std::fixed<<std::setprecision(2);
    for(unsigned i = 0; i < stat.size(); i++) {
        os<<i+1<<":\t"<<stat[i]<<" ("<<(double)(stat[i]*100)/N<<"%):\t";
        for(unsigned j = 0; j < stat[i]/10; j++)
            os<<"*";
        os<<std::endl;
    }
    os<<"\nWYKONANYCH POLACZEN: "<<N<<std::endl;
}
void Billing::statystykaKrajowa (std::ostream &os) const {
    std::map <std::string, Histogram> stat; // osobna statystyka dla każdego kodu
    for(auto pol : blng_) 
        stat[pol.kod()] = Histogram();

        //stat.insert(std::make_pair(pol.kod(), Histogram()));
        //std::cout<<pol.kod()<<std::endl;

    for(auto pol : blng_) 
        stat[pol.kod()].dodaj(pol.czas);

    std::cout<<"Kraj:\tRozmiar\tSred.\tOdch.\tMin\tMax\t"<<std::endl;
    std::cout<<std::fixed<<std::setprecision(2);
    for(auto const& [i,h] : stat) 
        std::cout<<i<<":\t"<<h.rozmiar()<<"\t"<<h.srednia()<<"\t"<<h.odchylenie()<<"\t"<<h.min()<<"\t"<<h.max()<<"\t"<<std::endl;


}   