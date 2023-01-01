#ifndef _dane_hpp_
#define _dane_hpp_
#include <vector>
#include <string>


class Dane{
    public:
        Dane(const char *name);
        ~Dane();
        std::vector<double>& getX();
        std::vector<double>& getY();
        double getMinX();
        double getMinY();
        double getMaxX();
        double getMaxY();
    protected:
        std::vector<double> x_;
        std::vector<double> y_;
        double minX_,minY_,maxX_,maxY_;


};
#endif  