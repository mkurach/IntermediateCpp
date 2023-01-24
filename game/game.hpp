#ifndef _game_hpp_
#define _game_hpp_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <map>
#include <cmath>
#include "bird.hpp"

class Game{
    public:
        Game();
        virtual ~Game();

        //inity
        void initZmienne();
        void initWindow();
        void initTextures();
        void initBird();

        //logika gry
        const bool isRunning() const;
        const bool getEndGame() const;

        void update();
        void updateMouse();
        void updateBird();

        void render();

        //metody
        void pollEvents();

    private:
        //window stuff
        std::pair<int,int> size_;
        sf::RenderWindow* window_;
        sf::Sprite background_;
        sf::Vector2f mouse_;


        //obiekty
        std::map<std::string, sf::Texture*> textures_;
        sf::Event ev_;
        Bird *bird_;
        sf::Vertex *lineBack_;
        sf::Vertex *lineFront_;


        //zmienne
        bool endGame_;
        double velocityZero_;
        int phase_;



};

#endif