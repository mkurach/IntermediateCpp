#include "piec.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <iomanip> 




Piec::Piec(double t) : temp_(t) {
    time_ = 0;

    initscr();
    noecho ();  // nie wyświetla wciśniętego klawisza na ekranie
    start_color(); // uruchamia kolory
    init_pair (1, COLOR_CYAN, COLOR_BLACK); // Tworzy kolor (litera, tło) o indeksie #1
    clear (); // Czyści cały ekran	



}

Piec::~Piec() {
    
}


void Piec::rampa(int tpocz, int tkonc, int v) {
    int sign = tpocz < tkonc ? 1 : -1;
    int i = 0;
    int total = ((tkonc - tpocz)/v) * sign;

    while(i < total) {
        temp_ = temp_ + sign*v;
        showPiec("rampa");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time_++;
        i++;

    }




}
void Piec::izoterm(int t) {
    int i = 0;
    while(i < t) {
        showPiec("izoterma");
        i++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time_++;

    }

}
void Piec::skocz(int t) {
    temp_ = t;
    showPiec("skok");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    time_++;

}
void Piec::start(int t) {
    temp_ = t;
    showPiec("start");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    time_++;

}
void Piec::end() {
    endwin();
}

void Piec::showPiec(char* tryb) {

    mvprintw(4,50,"czas: ");
    mvprintw(8,50,"temp: ");
    mvprintw(12,50,"tryb: ");

    attron (COLOR_PAIR(1));
    mvprintw(4,60,std::to_string(time_).c_str());
    mvprintw(8,60,std::to_string(temp_).c_str());
    mvprintw(12,60,tryb);
    attroff (COLOR_PAIR(1));
    refresh();
}

