#include <SFML/Graphics.hpp>
#include "grid.hpp"


int main()
{
    int width = 500;
    int height = 500;
    sf::RenderWindow window(sf::VideoMode(width,height), "Plytka");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    Grid *grid = new Grid(width,height);
    sf::Image image = grid->getImage();

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,width,height));
    window.setFramerateLimit( 120 ); 




    while (window.isOpen())  {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            }
        }


        window.clear();
        grid->updateImage();
        image = grid->getImage();
        texture.update(image);

        window.draw(sprite);
        //window.draw(shape);
        window.display();
    }

    return 0;
}