#ifndef _dane_stat_hpp_
#define _dane_stat_hpp_
#include <string>
#include <vector>

class DaneStat {// klasa bazowa
    public:
        DaneStat (const std::string &nazwa): nazwa_(nazwa) {}  
        virtual const std::vector <float> &dane () const = 0; // zwraca referencje na przechowywane dane
        virtual ~DaneStat () {};
        virtual const std::string &nazwa () const; // zwraca nazwę pliku
    protected:
        std::string nazwa_; // nazwa pliku
};


class DaneStatProxy : public DaneStat { // proxy - wczytuje prawdziwy obiekt przy pierwszym użyciu
    private:
        mutable DaneStat *danestat_;
    public: 
        DaneStatProxy (std::string nazwa) : DaneStat(nazwa), danestat_(NULL) {}
        ~DaneStatProxy () {delete danestat_;}
        virtual const std::vector <float> &dane () const;


};


class DaneStatReal : public DaneStat { // "prawdziwy" obiekt przechowujacy dane
    private:
        std::string nazwa_;
        mutable std::vector<float> dane_;
    public:
        DaneStatReal(std::string nazwa);
        virtual const std::vector <float> &dane () const;
        

};
#endif