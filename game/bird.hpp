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
        int getCollisionPig();
        void setCollisionStatus(bool i);
        
        bool getOutStatus();
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

/*! @file 
* @brief The Bird class declaration
*/
/*! @class Bird
* @brief A Bird class, inheritating from sf::CircleShape.
*
* @fn Bird::Bird(float r,std::vector<Pig*> vec, std::pair<int,int> screen)
* @brief Constructor of the Bird object.
* @param r radius of the Bird
* @param vec vector of the Pig objects
* @param screen pair of screen's size values
*
* @fn Bird::~Bird()
* @brief Default destructor.
*
* @fn void Bird::initValues(float x, float y)
* @brief Set initial values for the track of the Bird.
* @param x x position of the mouse in the beginning of the flight
* @param y y position of the mouse in the beginning of the flight
*
* @fn void Bird::updatePosition()
* @brief Update the coordinates of the Bird.
*
* @fn void Bird::checkCollision()
* @brief Checks, whether the Bird collided with the Pig.
*
* @fn void Bird::checkBorders()
* @brief Checks, whether the Bird has gone out of the screen.
*
* @fn bool Bird::getCollisionStatus()
* @brief Get the collision_ value.
* @return collision_ value
*
* @fn bool Bird::getOutStatus()
* @brief Get the out_ value.
* @return out_ value
*
* @fn int Bird::getCollisionPig()
* @brief Get the index of the Pig, with which the Bird collided.
* @return collisionInt_ value
*
* @fn void Bird::setCollisionStatus(bool i)
* @brief Set value of the collision_ variable.
*
* @fn void Bird::setOutStatus(bool i)
* @brief Set the value of the out_ variable.
*
*/


#endif