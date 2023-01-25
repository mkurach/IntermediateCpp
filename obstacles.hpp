#ifndef _obstacles_hpp_
#define _obstacles_hpp_
#include <SFML/Graphics.hpp>

class Box : public sf::RectangleShape {
    public:
        Box(int x, int y);
        ~Box();
    private:

};


class Pig : public sf::CircleShape {
    public:
        Pig(float r);
        ~Pig();
    private:
    

};

#endif