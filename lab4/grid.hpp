#ifndef _grid_hpp_
#define _grid_hpp_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Grid {
    public:
        Grid(int x, int y);
        ~Grid();
        std::pair<int,int> getSize();
        sf::Image getImage();
        void updateImage();
    private:
        std::vector<std::vector<sf::Color>> grid_;
        std::vector<std::vector<sf::Color>> gridTmp_;
        std::pair<int,int> size_;
        sf::Image image_;

        



};

#endif