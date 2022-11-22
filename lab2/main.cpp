#include "rozklad.hpp"
#include "dane_stat.hpp"
#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <memory>

int main(int argc, char *argv[]) {

    //REJESTRUJEMY WTYCZKI
    std::vector <std::shared_ptr <DaneStat> > dane;  // wskaźniki do obiektów przechowujących dane
    //CZYTANIE LISTY PLIKOW
    if(argc != 2) {
        std::cout<<"Nie podano listy plikow! :("<<std::endl;
        exit(1);
    }
    else {
        std::ifstream fileIn;
        fileIn.open(argv[1]);
        if (!fileIn) {
            std::cout<<"Nie da się otworzyć1! :("<<std::endl;
            exit(1);
        }
        std::string x;
        while(fileIn >> x)
            dane.push_back (std::shared_ptr<DaneStat> (new DaneStatProxy(x)));
        fileIn.close();
    }

    


    /*FabrykaRozkladow::rejestruj (&RozkladGaussa::kreator, std::string("Rozklad Gaussa"));
    FabrykaRozkladow::rejestruj (&RozkladLorentza::kreator, std::string("Rozklad Lorentza"));
    FabrykaRozkladow::rejestruj (&RozkladPoisson::kreator, std::string("Rozklad Poissona"));

    // Tworzy miziadelko do obliczania statystyk
    std::unique_ptr <Rozklad> rozkl (FabrykaRozkladow::utworz (wybor_r, dane[wybor-1]->dane ()));*/

    //MENU
    bool go = true;
    int option = 0;
    std::cout<<dane.size();
    while(go) {
        std::cout<<"\nWybierz plik, który chcesz przeanalizować: "<<std::endl;
        for(unsigned int i = 0; i < dane.size(); i++) 
            std::cout<<i+1<<" - "<<dane[i]->nazwa()<<std::endl;
        std::cout<<"\n0 - koniec programu\n"<<std::endl;
        std::cin>>option;
        if(option == 0)
            go = false;
        else {
            dane[option-1]->dane();
            
        }

    }



    
    dane.clear();
    return 0;

}
