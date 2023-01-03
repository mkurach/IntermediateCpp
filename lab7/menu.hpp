#ifndef _menu_hpp_
#define _menu_hpp_
#include <QMenu>
#include <QObject>
#include <QString>
#include <QColor>

class Menu : public QMenu {
    Q_OBJECT
    public:
        Menu(const QString tytul);
        ~Menu();
    public slots:
        void menuSelection(QAction *action);
        void setColor(QColor color);

    signals:
        void colorSelected(QColor newColor);
    protected:
            QColor color_;



};


#endif