#include "piec.hpp"
#include <iostream>

Piec::Piec(int t) : temp_(t) {}

Piec::~Piec() {
    
}

void Piec::rampa(int tmin, int tmax, int v) {
    std::cout<<"rampa"<<std::endl;
    std::cout<<tmin<<std::endl;
    std::cout<<tmax<<std::endl;
    std::cout<<v<<std::endl;



}
void Piec::izoterm(int t) {
    std::cout<<"izoterm"<<std::endl;
    std::cout<<t<<std::endl;

}
void Piec::skocz(int t) {
        std::cout<<"skocz"<<std::endl;
    std::cout<<t<<std::endl;

}
void Piec::start(int t) {
        std::cout<<"start"<<std::endl;
    std::cout<<t<<std::endl;

}
void Piec::end() {
        std::cout<<"end"<<std::endl;

}