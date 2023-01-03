#ifndef _plot_hpp_
#define _plot_hpp_
#include <QObject>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_point_data.h>
#include <QColor>
#include "dane.hpp"

class Plot : public QObject {
    Q_OBJECT
    public:
        //Plot(std::vector<double> &x, std::vector<double>& y,QwtPlot &wykres );
        Plot(Dane &dane,QwtPlot &wykres );
        virtual ~Plot();
        QwtPlotCurve daneCurv_;
        QwtPlotCurve regr_;
    public slots:
        void setColor(QColor color);
        void drawRegression();
        
    protected:
        QwtPlot &wykres_; 
        //Dane &dane_;




};

#endif