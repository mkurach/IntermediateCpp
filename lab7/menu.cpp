#include "menu.hpp"

Menu::Menu(const QString tytul) : QMenu(tytul) {
    this->addAction("Red");
    this->addAction("Green");
    this->addAction("Blue");
    this->addAction("Cyan");
    this->addAction("Magenta");
    this->addAction("Yellow");
    this->addAction("Gray");
    this->addAction("Draw regression");

    alreadyOn_ = false;

    QObject::connect(
        this, &Menu::triggered,
        this, &Menu::menuSelection
    );


}
Menu::~Menu() {}

void Menu::setColor(QColor color)
{
    if (color != color_) {
        color_ = color;
        emit colorSelected(color);
    }
}



void Menu::menuSelection(QAction* action)
{

    if(action->text() == "Draw regression") {
        if(!alreadyOn_) {
            alreadyOn_ = true;
            emit addRegression();
        }
        
    }
    else 
        setColor(QColor(action->text()));
}
