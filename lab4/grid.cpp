#include "grid.hpp"
#include <time.h>
#include <cstdlib>
#include <math.h>

Grid::Grid(int x, int y) {

    size_ = std::make_pair(x,y);
    image_.create(x,y);
    heatTransf = 0.25;
    tMax = 100;

    //initialize temperatures and colors
    std::vector<std::vector<double>> vec( x, std::vector<double> (y, -tMax));
    temp_ = vec;


    srand(time(0));
    
    int xS = rand()%x;
    int yS = rand()%y;
    int r = x < y ? x/10 : y/10;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if( (i-xS)*(i-xS) + (j-yS)*(j-yS) < r*r)
                temp_[i][j] = tMax;
            image_.setPixel(i,j,makeCol(temp_[i][j]));
        }
    }
    tempTmp_ = temp_;




}

sf::Color Grid::makeCol(double t) {
    sf::Color col(0,0,0);
    col.r = (int)(1/(1+exp(-t*2.0/tMax))*255);
    col.b = 255 - (int)(1/(1+exp(-t*2.0/tMax))*255);

    return col;
}

void Grid::updateImage() {

    double deltaT = 0;
    for(int x = 0; x < getSize().first; x++) {
        for(int y = 0; y < getSize().second; y++) {
            if (x!=0)  //u góry
                deltaT += (temp_[x][y] - temp_[x-1][y]);
            if(x!=(getSize().first -1)) // u dołu
                deltaT += (temp_[x][y] - temp_[x+1][y]);
            if (y!=0)  //po lewo
                deltaT += (temp_[x][y] - temp_[x][y-1]); 
            if(y!=(getSize().second -1))  // po prawo
                deltaT += (temp_[x][y] - temp_[x][y+1]);

            tempTmp_[x][y] -= heatTransf*deltaT;
            deltaT = 0;        

        }
    }

    temp_ = tempTmp_;

    for(int x = 0; x < getSize().first; x++) {
        for(int y = 0; y < getSize().second; y++) {
            image_.setPixel(x,y,makeCol(temp_[x][y]));

        }
    }

}

Grid::~Grid() {
}

std::pair<int,int> Grid::getSize() {
    return size_;
}

sf::Image Grid::getImage() {
    return image_;
}
