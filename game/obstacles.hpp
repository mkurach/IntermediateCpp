#ifndef _obstacles_hpp_
#define _obstacles_hpp_
#include <SFML/Graphics.hpp>

class Box : public sf::RectangleShape {
    public:
        Box(int x, int y);
        ~Box();

};


class Pig : public sf::CircleShape {
    public:
        Pig(float r);
        ~Pig();
    
};

/*! @file 
* @brief Contains declarations of Pig and Box classes. 
*/

/*! @class Box
* @brief A Box class, inheritates form sf::RectangleShape.
* 
* @fn Box::Box(int x, int y)
* @brief Constructor for Box object.
* @param x width of the Box object
* @param y height of the Box object
*
* @fn Box::~Box()
* @brief Default destructor.
*/

/*! @class Pig
* @brief A Pig class, inheritates form sf::CircleShape.
* 
* @fn Pig::Pig(float r)
* @brief Constructor for Pig object.
* @param r radius of the Pig object
*
* @fn Pig::~Pig()
* @brief Default destructor.
*/



#endif