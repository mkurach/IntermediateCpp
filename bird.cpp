#include "bird.hpp"
#include <iostream>

Bird::Bird(float r, std::vector<Pig*> vec, std::pair<int,int> screen) : sf::CircleShape(r) { 
    setFillColor(sf::Color::Red);
    setPosition(150, 500);

    enemies_ = vec;
    velocity0_ = 0;
    sin_ = 0;
    cos_ = 0;
    dt_ = 1.0/20;
    x_ = 0;
    y_ = 0;
    velocity_ = 0;
    velocityX_ = 0;
    velocityY_ = 0;
    collision_ = false;
    out_ = false;
    collisionInt_ = 0;
    screen_ = screen;

}

Bird::~Bird() {
    enemies_.clear();
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

void Bird::checkCollision() {
    for(size_t i = 0; i < enemies_.size(); i++) {
        if(enemies_[i]->getGlobalBounds().intersects(getGlobalBounds())) {
            collision_ = true;
            collisionInt_ = (int)i;
        }
    }

}
void Bird::checkBorders() {
    if( x_ > screen_.first-50 || y_ > screen_.second-50)
        out_ = true;
    
}

bool Bird::getCollisionStatus() {
    return collision_;
}

bool Bird::getOutStatus() {
    return out_;
}
int Bird::getCollisionPig() {
    return collisionInt_;
}

void Bird::setCollisionStatus(bool i) {
    collision_ = i;
}
void Bird::setOutStatus(bool i) {
    out_ = i;
}
