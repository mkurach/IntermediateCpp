#ifndef _bird_hpp_
#define _bird_hpp_
#include <SFML/Graphics.hpp>
#include <cmath>


class Bird : public sf::CircleShape {
    public:
        Bird(float r);
        ~Bird();

        void initValues(float x, float y);
        void updatePosition();
    private:
        double velocity0_;
        double velocityX_, velocityY_, velocity_;
        float sin_, cos_;
        double dt_;
        double x_,y_;

};

#endif