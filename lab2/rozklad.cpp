#include "rozklad.hpp"
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <cmath>


std::unique_ptr <ParametryRozkladu> RozkladGaussa::oblicz () const {
    float srednia = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){srednia += a;});
    srednia /= dane_.size();

    float odchylenie = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){odchylenie += (a-srednia)*(a-srednia);});
    odchylenie = sqrt(odchylenie)/sqrt(dane_.size());

    std::unique_ptr <ParametryRozkladu> par(new ParametryRozkladu{{"srednia",srednia},{"odchylenie",odchylenie}});

    return par;
}

std::unique_ptr <ParametryRozkladu> RozkladLorentza::oblicz () const {
    
    std::vector<float> dane_tmp = dane_;
    std::sort(dane_tmp.begin(),dane_tmp.end());

    float mediana = dane_tmp[dane_tmp.size()/2];
    float q1 = dane_tmp[dane_tmp.size()/4];
    float q3 = dane_tmp[dane_tmp.size()*3/4];

    std::unique_ptr <ParametryRozkladu> par(new ParametryRozkladu{{"mediana",mediana},{"q1",q1},{"q3",q3}});

    return par;
}

std::unique_ptr <ParametryRozkladu> RozkladPoissona::oblicz () const {
    float srednia = 0;
    std::for_each(dane_.begin(),dane_.end(),[&](float a){srednia += a;});
    srednia /= dane_.size();

    float mediana = floor(srednia + (1/3) - (0.02/srednia));

    std::unique_ptr <ParametryRozkladu> par(new ParametryRozkladu{{"srednia",srednia},{"mediana",mediana}});

    return par;
}

Rozklad *RozkladGaussa::kreator (const std::vector <float> &dane) {// Statyczny kreator wybranej klasy (to naprawdę jest takie proste!)
    return new RozkladGaussa (dane);
}

Rozklad *RozkladLorentza::kreator (const std::vector <float> &dane) {
    return new RozkladLorentza (dane);
}
Rozklad *RozkladPoissona::kreator (const std::vector <float> &dane) {
    return new RozkladPoissona (dane);
}

std::map <unsigned, KreatorRozkladu> FabrykaRozkladow::rozklady = {{0,NULL}};
std::map <unsigned, std::string> FabrykaRozkladow::nazwy = {{0,""}};


void FabrykaRozkladow::rejestruj (KreatorRozkladu kr, const std::string &nazwa) {
    unsigned i = ilosc();
    rozklady [i] = kr;
    nazwy [i] = nazwa;
    
}

Rozklad *FabrykaRozkladow::utworz (unsigned typ, const std::vector <float> &dane){ // Statyczna metoda wołająca (choć trudno to zobaczyć) kreator typu o podanym id
    return rozklady [typ] (dane);
}

std::string FabrykaRozkladow::nazwa (unsigned id) {
    return nazwy[id];
}

