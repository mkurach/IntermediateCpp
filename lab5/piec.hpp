#ifndef _piec_hpp_
#define _piec_hpp_
//#include <ncurses.h>

class Piec {
    public:
        Piec(double t);
        ~Piec();
        void rampa(int tmin, int tmax, int v);
        void izoterm(int t);
        void skocz(int t);
        void start(int t);
        void end();
        void showPiec(char* tryb);


    private:
        double temp_;
        double time_;
};

#endif