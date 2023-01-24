#include "game.hpp"

Game::Game() {

    initZmienne();
    initTextures();
    initWindow();

}

Game::~Game() {
   delete window_;
}

void Game::initZmienne() { 
    endGame_ = false;
}

void Game::initTextures() {
    
    sf::Image image_;
    image_.loadFromFile("tlo.png");
    textures_["background"] = new sf::Texture();
    textures_["background"]->loadFromImage(image_);
    background_.setTexture(*textures_["background"]);
}


void Game::initWindow() { 

    int width = 1500;
    int height = 750;

    size_ = std::make_pair(width,height);
    window_ = new sf::RenderWindow(sf::VideoMode(width,height), "Game");
    window_->setFramerateLimit(5);

}




const bool Game::isRunning() const {
	return window_->isOpen();
}

const bool Game::getEndGame() const {
	return endGame_;
}

void Game::update() {
    //zupdateuj obiekty
   pollEvents();
    //end game condtion
}

void Game::render() {
    window_->clear();
    //render nowe rzeczy
    window_->draw(background_);


    window_->display();
}

void Game::pollEvents() {

	while (window_->pollEvent(ev_))	{
        if(ev_.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            window_->close();
	}
}
