#include <SFML/Graphics.hpp>
#include "grid.hpp"


int main() {

    int width = 800;
    int height = 800;
    sf::RenderWindow window(sf::VideoMode(width,height), "Plytka");


    Grid *grid = new Grid(width,height);
    sf::Image image = grid->getImage();

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,width,height));
    window.setFramerateLimit( 120 ); 
    grid->printMenu();


    while (window.isOpen())  {

        window.clear();
        grid->updateImage();
        image = grid->getImage();
        texture.update(image);
        window.draw(sprite);
        window.display();
        
        sf::Event event;
        while (window.pollEvent(event)) {

            if(sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::R :
                        grid->setColor('R');
                        break;
                    case sf::Keyboard::O :
                        grid->setColor('O');
                        break;
                    case sf::Keyboard::G :
                        grid->setColor('G');
                        break;
                    case sf::Keyboard::V :
                        grid->setColor('V');
                        break;
                    case sf::Keyboard::Y :
                        grid->setColor('Y');
                        break;
                    case sf::Keyboard::C :
                        grid->setColor('C');
                        break;
                }
            }

            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                grid->spray(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y,0);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                grid->spray(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y,1);
            
            if(event.type == sf::Event::MouseWheelMoved )
                grid->addSpray(event.mouseWheel.delta);

        }
    }

    return 0;
}