#ifndef _bird_hpp_
#define _bird_hpp_
#include <SFML/Graphics.hpp>
#include <cmath>
#include "obstacles.hpp"


class Bird : public sf::CircleShape {
    public:
        Bird(float r,std::vector<Pig*> vec, std::pair<int,int> screen);
        ~Bird();

        void initValues(float x, float y);
        void updatePosition();
        void checkCollision();
        void checkBorders();
        bool getCollisionStatus();
        bool getOutStatus();
        int getCollisionPig();
        void setCollisionStatus(bool i);
        void setOutStatus(bool i);
    private:
        std::pair<int,int> screen_;
        double velocity0_;
        double velocityX_, velocityY_, velocity_;
        float sin_, cos_;
        double dt_;
        double x_,y_;
        std::vector<Pig*> enemies_;
        bool collision_, out_;
        int collisionInt_;

};

#endif