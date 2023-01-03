#ifndef _plot_hpp_
#define _plot_hpp_
#include <QObject>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_point_data.h>
#include <QColor>

class Plot : public QObject {
    Q_OBJECT
    public:
        Plot(std::vector<double> &x, std::vector<double>& y,QwtPlot &wykres );
        virtual ~Plot();
        QwtPlotCurve dane_;
    public slots:
        void setColor(QColor color);
        
    protected:
        QwtPlot &wykres_; 




};

#endif