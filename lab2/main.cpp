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

    


    FabrykaRozkladow::rejestruj (&RozkladGaussa::kreator, std::string("Rozklad Gaussa"));
    FabrykaRozkladow::rejestruj (&RozkladLorentza::kreator, std::string("Rozklad Lorentza"));
    FabrykaRozkladow::rejestruj (&RozkladPoissona::kreator, std::string("Rozklad Poissona"));



    //MENU
    unsigned wybor_plik = 0;
    unsigned wybor_rozkl = 0;
    unsigned wybor_end = 0;

    while(true) {

        std::cout<<"\nWybierz plik, który chcesz przeanalizować: "<<std::endl;
        for(unsigned i = 0; i < dane.size(); i++) 
            std::cout<<i+1<<" - "<<dane[i]->nazwa()<<std::endl;
        std::cout<<"\nWybór pliku: ";
        std::cin>>wybor_plik;
        std::cout<<"\n******"<<std::endl;
        if(wybor_plik > dane.size()) {
            std::cout<<"Nie ma takiego numeru :("<<std::endl;
        }
        else {
            std::cout<<"\nWybierz rozkład: "<<std::endl;
            for(unsigned i = 1 ; i < FabrykaRozkladow::ilosc(); i++)
                std::cout<<i<<" - "<<FabrykaRozkladow::nazwa(i)<<std::endl;
            std::cout<<"\nWybór rozkładu: ";
            std::cin>>wybor_rozkl;
            std::cout<<"\n******"<<std::endl;
            if(wybor_rozkl > FabrykaRozkladow::ilosc()) {
                std::cout<<"Nie ma takiego rozkladu :("<<std::endl;
            }
            else {
                std::cout<<"\nLiczę...\n"<<std::endl;
                std::unique_ptr <Rozklad> rozkl (FabrykaRozkladow::utworz (wybor_rozkl, dane[wybor_plik-1]->dane ()));
                std::unique_ptr <ParametryRozkladu> params = rozkl->oblicz();

                for(auto [i,j] : *params)
                    std::cout<<i<<":\t\t "<<j<<std::endl;

                std::cout<<"\n******\n"<<std::endl;
                std::cout<<"1 - kontynuuj"<<std::endl;
                std::cout<<"0 - koniec"<<std::endl;
                std::cin>>wybor_end;

                if(wybor_end == 0)
                    break;

            }



        }
            

    




    }



    
    dane.clear();
    return 0;

}
