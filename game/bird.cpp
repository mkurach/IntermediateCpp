#include "bird.hpp"
#include <iostream>

Bird::Bird(float r) : sf::CircleShape(r) { 
    setFillColor(sf::Color::Red);
    setPosition(150, 500);

    velocity0_ = 0;
    sin_ = 0;
    cos_ = 0;
    dt_ = 1.0/20;
    x_ = 0;
    y_ = 0;
    velocity_ = 0;
    velocityX_ = 0;
    velocityY_ = 0;
}

Bird::~Bird() {

}


void Bird::initValues(float x, float y) {
    velocity0_ = sqrt((270-x)*(270-x)+(400-y)*(400-y));
    sin_ = (y-400)/sqrt((y-400)*(y-400)+(270-x)*(270-x));
    cos_ = (270-x)/sqrt((y-400)*(y-400)+(270-x)*(270-x));
    x_ = getPosition().x;
    y_ = getPosition().y;

    velocityX_ = velocity0_ * cos_;
    velocityY_ = velocity0_ * sin_;
    velocity_ = sqrt(velocityX_*velocityX_ + velocityY_*velocityY_);
}

void Bird::updatePosition() {
    x_ += velocityX_ * dt_;

    y_ -= velocityY_ * dt_;
    velocityY_ -= 70.0 * dt_;

    velocity_ = sqrt(velocityX_*velocityX_ + velocityY_*velocityY_);


    setPosition(sf::Vector2f(x_,y_));
}