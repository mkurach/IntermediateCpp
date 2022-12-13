#ifndef _piec_hpp_
#define _piec_hpp_

class Piec {
    public:
        Piec(int t);
        ~Piec();
        void rampa(int tmin, int tmax, int v);
        void izoterm(int t);
        void skocz(int t);
        void start(int t);
        void end();

    private:
        int temp_;

};

#endif