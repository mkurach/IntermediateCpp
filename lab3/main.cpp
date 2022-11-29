#include "macierz.hpp"
#include "mnozenie_macierzy.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <chrono>
#include <ctime>
#include <vector>


int main(int argc, char *argv[]) {


    if(argc != 4) {
        std::cout<<"Zla ilosc plikow, podaj 2 macierze i plik wyjsciowy"<<std::endl;
        exit(1);
    } 
    else {
        std::ifstream file1(argv[1]);
        std::ifstream file2(argv[2]);
        std::ofstream fileout(argv[3]);
        if (!file1 || !file2 || !fileout) {
            std::cout<<"Nie da się otworzyć! :("<<std::endl;
            exit(1);
        }
        Macierz mac1(file1);
        Macierz mac2(file2);

        using namespace std::chrono;
        int threads = 6;
        std::vector< time_point<system_clock> > start, end;
        std::vector<duration<double> > elapsed_seconds;
        std::unique_ptr<Macierz> wynik;
        for(int i = 2; i <= threads; i++ ) {
            start.push_back(system_clock::now());
            wynik = mnozenie_macierzy (mac1, mac2, i);
            end.push_back(system_clock::now());
            elapsed_seconds.push_back(end.back()-start.back());
            std::cout<<"Ile czasu uplynelo na "<<i<<" watkach: "<<elapsed_seconds.back().count()<<"s\n";

        }

        fileout<<*wynik;
    }


    return 0;
}
