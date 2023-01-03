#include "menu.hpp"

Menu::Menu(const QString tytul) : QMenu(tytul) {
    this->addAction("Red");
    this->addAction("Green");
    this->addAction("Blue");

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
  setColor(QColor(action->text()));
}
