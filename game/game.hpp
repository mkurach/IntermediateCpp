#ifndef _game_hpp_
#define _game_hpp_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <map>

class Game{
    public:
        Game();
        virtual ~Game();

        //inity
        void initZmienne();
        void initWindow();
        void initTextures();

        //logika gry
        const bool isRunning() const;
        const bool getEndGame() const;
        void update();
        void render();

        //metody
        void pollEvents();

    private:
        //window stuff
        std::pair<int,int> size_;
        sf::RenderWindow* window_;
        sf::Sprite background_;


        //obiekty
        std::map<std::string, sf::Texture*> textures_;
        sf::Event ev_;

        //zmienne
        bool endGame_;



};

#endif