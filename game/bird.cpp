#include "bird.hpp"

Bird::Bird(float r) : sf::CircleShape(r) { 
    setFillColor(sf::Color::Red);
    setPosition(150, 500);

    velocity_ = 0;
}

Bird::~Bird() {

}

void Bird::setVelocity(double v) {
    velocity_ = v;
}

void Bird::updateValues() {
    

}