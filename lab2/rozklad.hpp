#ifndef _rozklad_hpp_
#define _rozklad_hpp_
#include <memory> //do unique_ptr
#include <map>
#include <vector>

/*
typedef std::map <std::string, float> ParametryRozkladu; // mapa przechowujaca obliczone estymatory rozkladu: opis-wartosc
class Rozklad {// ATD - klasa bazowa dla "obliczaczy" estymatorow
    public:
        explicit Rozklad (const std::vector <float> &dane); // ustawia referencje na dane do analizy
        virtual ~Rozklad () {}  // oblicza estymatory i zwraca je w mapie
        virtual std::unique_ptr <ParametryRozkladu> oblicz () const = 0;
    protected:
        const std::vector <float> &dane_; // przechowuje referencje na dane do analizy
};
class RozkladGaussa : public Rozklad {
    public:
        explicit RozkladGaussa (const std::vector <float> &dane);  // nie robi nic sensownego poza wywolaniem konstr. klasy bazowej z odpowiednim parametrem
        virtual ~RozkladGaussa () {}   
        virtual std::auto_ptr <ParametryRozkladu> oblicz () const; // liczy wartosc srednia i odchylenie standardowe
        static Rozklad* kreator (const std::vector <float> &dane);// statyczna met. tworzaca i zwracajaca wskaznik na obiekt wlasnego typu
};

// wskaznik typu KreatorRozkladu do funkcji tworzacej obiekt
// obliczacza rozkladu (pochodna klasy Rozklad)
typedef Rozklad* (*KreatorRozkladu)(const std::vector <float> &);


class FabrykaRozkladow {// FABRYKA! :)
    private:
        static std::map <unsigned, KreatorRozkladu> rozklady; // przechowuje wskaźniki kreatorow (funkcji tworzących!)
        static std::map <unsigned, std::string> nazwy; // przechowuje nazwy rozkladow
    public:
    
    static void rejestruj (KreatorRozkladu kr, const std::string &nazwa); // rejestruje kreator danego rozkladu (id generowane przyrostowo od 1)
    static Rozklad *utworz (unsigned id, const std::vector <float> &dane); // wola kreator dla rozkladu o wybranym id
    static std::string nazwa (unsigned id); // zwraca nazwe rozkladu o identyfikatorze id
    static unsigned ilosc () {return rozklady.size ();} // zwraca liczbe zarejestrowanych rozkladow
};
*/

#endif