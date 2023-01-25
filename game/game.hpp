#ifndef _game_hpp_
#define _game_hpp_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include "bird.hpp"
#include "obstacles.hpp"
#include <cstdlib>


class Game {
    public:
        Game();
        virtual ~Game();

        void initZmienne();
        void initWindow();
        void initTextures();
        void initBird();
        void initBoxes(int n);
        void initPigs(int n);

        const bool isRunning() const;
        const bool getEndGame() const;

        void update();
        void updateMouse();
        void updateBird();

        void render();
        void renderObstacles();
        void renderEnd();

        void pollEvents();
        void handleCollision();
        void printResults();

    private:
        std::pair<int,int> size_;
        sf::RenderWindow* window_;
        sf::Sprite background_;
        sf::Vector2f mouse_;

        std::map<std::string, sf::Texture*> textures_;
        Bird *bird_;
        sf::Vertex *lineBack_;
        sf::Vertex *lineFront_;
        std::vector<Box*> boxes_;
        std::vector<Pig*> pigs_;

        sf::Event ev_;
        bool endGame_;
        int phase_;
        int tries_;
        int pigsDown_;

};

/*! @file
* @brief The Game class declaration.
*/

/*! @class Game
*  @brief A Game class, operating the game's engine.
*
* @fn Game::Game()
* @brief Constructor, invoking all the needed initial methods.
*
* @fn virtual Game::~Game()
* @brief Default desctructor.
*
* @fn void Game::initZmienne()
* @brief Initializing all variables.
*
* @fn void Game::initWindow()
* @brief Initializing window and its options.
*
* @fn void Game::initTextures()
* @brief Reading and initializing textures.
*
* @fn void Game::initBird()
* @brief Creating Bird object and initialing its variables.
*
* @fn void Game::initBoxes(int n)
* @brief Creating Box objects.
* @param n number of Box objects to create
* 
* @fn void Game::initPigs(int n)
* @brief Creating Pig objects.
* @param n number of Pig objects to create
*
* @fn const bool Game::isRunning() const
* @brief Checks, if window of the game is still opne.
* @return True, if still open, false if closed.
*
* @fn const bool Game::getEndGame() const
* @brief Get the value of the endGame value.
* @return endGame value
*
* @fn void Game::update()
* @brief Update all elements of the class.
*
* @fn void Game::updateMouse()
* @brief Update mouse position.
*
* @fn void Game::updateBird()
* @brief Update Bird position.
*
* @fn void Game::render()
* @brief Render objects on the window.
*
* @fn void Game::renderObstacles()
* @brief Render obstacles (Pig objects and Box objects)
*
* @fn void Game::renderEnd()
* @brief Render ending window.
*
* @fn void Game::pollEvents()
* @brief Handle  keyboard and window closing events.
*
* @fn void Game::handleCollision()
* @brief Method for handling collision of Bird with Pig object.
*
* @fn void Games::printResults()
* @brief Show results of the game on the standard output.
*/

#endif