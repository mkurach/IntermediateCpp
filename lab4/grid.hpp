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
        sf::Color makeCol(double t);
        void spray(int x, int y,int lr);
        void addSpray(int i);
        void setColor(char i);
        void printMenu();
    private:
        std::vector<std::vector<double>> temp_;
        std::vector<std::vector<double>> tempTmp_;
        std::pair<int,int> size_;
        sf::Image image_;
        double heatTransf_;
        double tMax_;
        double sprayRadius_;
        char color_;


        



};

#endif