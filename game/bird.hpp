#ifndef _bird_hpp_
#define _bird_hpp_
#include <SFML/Graphics.hpp>
#include <cmath>


class Bird : public sf::CircleShape {
    public:
        Bird(float r);
        ~Bird();

        void setVelocity(double v);
        void updateValues();
    private:
        double velocity_;
        double vX_;
        double vY_;

};

#endif