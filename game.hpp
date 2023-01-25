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

class Game{
    public:
        Game();
        virtual ~Game();

        //inity
        void initZmienne();
        void initWindow();
        void initTextures();
        void initBird();
        void initBoxes(int n);
        void initPigs(int n);

        //logika gry
        const bool isRunning() const;
        const bool getEndGame() const;

        void update();
        void updateMouse();
        void updateBird();

        void render();
        void renderObstacles();
        void renderEnd();

        //metody
        void pollEvents();
        void handleCollision();
        void printResults();

    private:
        //window stuff
        std::pair<int,int> size_;
        sf::RenderWindow* window_;
        sf::Sprite background_;
        sf::Vector2f mouse_;



        //obiekty
        std::map<std::string, sf::Texture*> textures_;
        Bird *bird_;
        sf::Vertex *lineBack_;
        sf::Vertex *lineFront_;
        std::vector<Box*> boxes_;
        std::vector<Pig*> pigs_;


        //zmienne
        sf::Event ev_;
        bool endGame_;
        int phase_;
        int tries_;
        int pigsDown_;



};

#endif