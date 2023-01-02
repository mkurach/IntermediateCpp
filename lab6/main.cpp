#include <iostream>
#include "stos.hpp"
#include "stos_impl.hpp"

int main() {

    Stos<int> stosInt(5);
    Stos<double> stosD(5);

    for(unsigned i = 0; i < 5; i++) {
        stosInt.poloz(i);
        stosD.poloz((double)(i)*0.75);
    }

    stosInt.printStos();
    stosD.printStos();

    stosD.poloz(85.34);
    auto cos = stosD.zdejmij();
    stosD.printStos();
    
    return 0;
}