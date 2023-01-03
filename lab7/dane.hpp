#ifndef _dane_hpp_
#define _dane_hpp_
#include <vector>
#include <string>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_point_data.h>


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
        void setWykres(QwtPlot &wykres); 
        void setDane(QwtPlotCurve &dane_doswiadczalne);
        void findParameters();
        void makeRegression();
                std::vector<double> x_;
        std::vector<double> y_;
        std::vector<double> yLin_;
    protected:

        double minX_,minY_,maxX_,maxY_;
        double wMin_,wMax_,hMin_,hMax_;
        double m_;
        std::pair<float,float> params_;


};
#endif  