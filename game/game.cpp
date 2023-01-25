#include "game.hpp"
#include <algorithm>


Game::Game() {

    initZmienne();
    initTextures();
    initWindow();
    initBoxes(10);
    initPigs(4);
    initBird();
}

Game::~Game() {
    boxes_.clear();
    pigs_.clear();
    delete bird_;
    delete window_;
}

void Game::initZmienne() { 
    endGame_ = false;
    phase_ = 0;
    tries_ = 0;
    pigsDown_ = 0;
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
    bird_ = new Bird(20,pigs_,size_);

    lineBack_ = new sf::Vertex[2];
    lineFront_ = new sf::Vertex[2];

    lineBack_[0] = sf::Vertex(sf::Vector2f(150, 500+bird_->getRadius()));
    lineBack_[1] = sf::Vertex(sf::Vector2f(210, 420));

    lineFront_[0] = sf::Vertex(sf::Vector2f(150, 500+bird_->getRadius()));
    lineFront_[1] = sf::Vertex(sf::Vector2f(315, 400));
}


void Game::initBoxes(int n) {
    std::vector<Box*> boxesTmp;
    std::vector<float> yTmp;
    for(int i = 0; i < n; i++) {
        boxesTmp.push_back(new Box(rand()%10+70,rand()%50+50));
        boxesTmp[i]->setPosition(rand()%500+600,rand()%100+450);
        yTmp.push_back(boxesTmp[i]->getPosition().y);
    }

    std::sort(yTmp.begin(),yTmp.end());

    for(auto y : yTmp) {
        for(auto box : boxesTmp){
            if(y==box->getPosition().y)
                boxes_.push_back(box);
        }
    }


}

void Game::initPigs(int n) {
    for (int i = 0; i < n; i++) {
        pigs_.push_back(new Pig(30));
        pigs_[i]->setPosition(boxes_[i]->getPosition().x,boxes_[i]->getPosition().y-2*pigs_[i]->getRadius()-5);
    }

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

    if(pigsDown_ == 4) {
        endGame_ = true;
    }

}


void Game::updateMouse() {
    mouse_ = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
}


void Game::updateBird() {
    if(phase_ == 0) {
        if(mouse_.x>25 && mouse_.x<500 && mouse_.y>420 && mouse_.y<725) {
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

        bird_->checkCollision();
        if(bird_->getCollisionStatus()) 
            phase_ = 2;
        
        bird_->checkBorders();
        if(bird_->getOutStatus()) {
            initBird();
            bird_->setOutStatus(false);
            phase_ = 0;
            tries_++;
            
        }
    }
    else if(phase_ == 2) {
        handleCollision();
        initBird();
        bird_->setCollisionStatus(false);
        phase_ = 0;
        tries_++;
        pigsDown_++;
    }


}

void Game::render() {
    window_->clear();

    window_->draw(background_);

    renderObstacles();

    if(phase_ == 0) window_->draw(lineBack_,2,sf::Lines);
    window_->draw(*bird_);
    if(phase_ == 0) window_->draw(lineFront_,2,sf::Lines);




    window_->display();
}

void Game::renderObstacles() {
    for(size_t i = 0; i < boxes_.size(); i++) {
        if (i < pigs_.size())
            window_->draw(*pigs_[i]);
        window_->draw(*boxes_[i]);
    }

}


void Game::pollEvents() {

	while (window_->pollEvent(ev_))	{
        if(ev_.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            window_->close();
	}
}

void Game::handleCollision() {

    std::vector<Pig*> pigsTmp = pigs_;
    pigs_.clear();
    for(size_t i = 0; i < pigsTmp.size(); i++) {
        if(i != (size_t)bird_->getCollisionPig())
            pigs_.push_back(pigsTmp[i]);
    }
}

