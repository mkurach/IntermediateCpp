#ifndef _box_hpp_
#define _box_hpp_
#include <SFML/Graphics.hpp>

class Box : public sf::RectangleShape {
    public:
        Box(int x, int y);
        ~Box();
    private:

};

#endif