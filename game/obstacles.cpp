#include "obstacles.hpp"

Box::Box(int x, int y) : sf::RectangleShape(sf::Vector2f(x, y)) {
    setFillColor(sf::Color::Magenta);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(5);
}

Box::~Box() {

}

Pig::Pig(float r) : sf::CircleShape(r) {
    setFillColor(sf::Color::Green);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(3);
}

Pig::~Pig() {

}

