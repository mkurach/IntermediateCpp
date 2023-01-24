#include "game.hpp"


Game::Game() {

    initZmienne();
    initTextures();
    initWindow();
    initBird();

}

Game::~Game() {
    delete bird_;
    delete window_;
}

void Game::initZmienne() { 
    endGame_ = false;
    velocityZero_ = 0;
    phase_ = 0;
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
    window_->setFramerateLimit(60);

}

void Game::initBird() {
    bird_ = new Bird(20);

    lineBack_ = new sf::Vertex[2];
    lineFront_ = new sf::Vertex[2];

    lineBack_[0] = sf::Vertex(sf::Vector2f(150, 500+bird_->getRadius()));
    lineBack_[1] = sf::Vertex(sf::Vector2f(210, 420));

    lineFront_[0] = sf::Vertex(sf::Vector2f(150, 500+bird_->getRadius()));
    lineFront_[1] = sf::Vertex(sf::Vector2f(315, 400));
}



const bool Game::isRunning() const {
	return window_->isOpen();
}

const bool Game::getEndGame() const {
	return endGame_;
}



void Game::update() {

    pollEvents();

    if(phase_ == 0)
        updateMouse();
        
    updateBird();

    //end game condition
}


void Game::updateMouse() {
    mouse_ = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
}


void Game::updateBird() {
    if(phase_ == 0) {
        if(mouse_.x>50 && mouse_.x<500 && mouse_.y>420 && mouse_.y<700) {
            bird_->setPosition(sf::Vector2f(mouse_.x-bird_->getRadius(),mouse_.y-bird_->getRadius()));
            lineBack_[0] = sf::Vertex(sf::Vector2f(mouse_.x-bird_->getRadius(), mouse_.y));
            lineFront_[0] = sf::Vertex(sf::Vector2f(mouse_.x-bird_->getRadius(), mouse_.y));

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                phase_ = 1;
                bird_->initValues(mouse_.x,mouse_.y);
            }
        }
    }
    else if(phase_ == 1) {
        bird_->updatePosition();
        
    }


}

void Game::render() {
    window_->clear();

    window_->draw(background_);
    if(phase_ == 0) window_->draw(lineBack_,2,sf::Lines);
    window_->draw(*bird_);
    if(phase_ == 0) window_->draw(lineFront_,2,sf::Lines);


    window_->display();
}



void Game::pollEvents() {

	while (window_->pollEvent(ev_))	{
        if(ev_.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            window_->close();
	}
}
