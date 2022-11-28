#include "macierz.hpp"
#include <fstream>

int main(int argc, char *argv[]) {


    if(argc != 2) {
        std::cout<<"Zla ilosc plikow, podaj 2 macierze"<<std::endl;
        exit(1);
    } 
    else {
        std::ifstream  file1(argv[1]);
        Macierz mac1(file1);
        std::cout<<mac1;
    }


    return 0;
}
/*const clockid_t ZegarID = CLOCK_REALTIME;
timespec start, koniec; // Struktury przechowujące czas
std::cout << "Mnozenie macierzy...";
std::cout.flush ();
clock_gettime (ZegarID, &start); // Zapisuje czas początku mnożenia
// Mnoży macierze a i b (liczba oznacza liczbę równoległych wątków)
std::unique_ptr<Macierz> wynik = mnozenie_macierzy (a, b, 2);
clock_gettime (ZegarID, &koniec); // Zapisuje czas końca mnożenia
std::cout << " zajelo " << interwal (start, koniec) << " s" << std::endl;*/