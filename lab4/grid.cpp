#include "grid.hpp"
#include <time.h>
#include <cstdlib>

Grid::Grid(int x, int y) {

    size_ = std::make_pair(x,y);
    std::vector<std::vector<sf::Color>> vec( x, std::vector<sf::Color> (y, sf::Color::Blue));
    grid_ = vec;


    srand(time(0));
    
    image_.create(x,y);
    int xS = rand()%x;
    int yS = rand()%y;
    int r = x < y ? x/10 : y/10;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if( (i-xS)*(i-xS) + (j-yS)*(j-yS) < r*r)
                grid_[i][j] = sf::Color::Red;
            image_.setPixel(i,j,grid_[i][j]);
        }
    }
    gridTmp_ = grid_;
}

void Grid::updateImage() {
    
    for(int x = 0; x < getSize().first; x++) {
        for(int y = 0; y < getSize().second; y++) {
            if (x!=0) { //u góry
                if(grid_[x-1][y].r != 0) {
                    if (grid_[x-1][y].r != 0) gridTmp_[x-1][y].r--;
                    if (grid_[x-1][y].b != 255) gridTmp_[x-1][y].b++;
                    if(grid_[x][y].r != 255) gridTmp_[x][y].r++;
                    if (grid_[x][y].b != 0) gridTmp_[x][y].b--;
                }
            }

            if(x!=(getSize().first -1)) { // u dołu
                if(grid_[x+1][y].r != 0) {
                    if (grid_[x+1][y].r != 0) gridTmp_[x+1][y].r--;
                    if (grid_[x+1][y].b != 255) gridTmp_[x+1][y].b++;
                    if(grid_[x][y].r != 255) gridTmp_[x][y].r++;
                    if (grid_[x][y].b != 0) gridTmp_[x][y].b--;
                }
            }

            if (y!=0) { //po lewo
                if(grid_[x][y-1].r != 0) {
                    if (grid_[x][y-1].r != 0) gridTmp_[x][y-1].r--;
                    if (grid_[x][y-1].b != 255) gridTmp_[x][y-1].b++;
                    if(grid_[x][y].r != 255) gridTmp_[x][y].r++;
                    if (grid_[x][y].b != 0) gridTmp_[x][y].b--;
                }
            }

            if(y!=(getSize().second -1)) { // po prawo
                if(grid_[x][y+1].r != 0) {
                    if (grid_[x][y+1].r != 0) gridTmp_[x][y+1].r--;
                    if (grid_[x][y+1].b != 255) gridTmp_[x][y+1].b++;
                    if(grid_[x][y].r != 255) gridTmp_[x][y].r++;
                    if (grid_[x][y].b != 0) gridTmp_[x][y].b--;
                }
            }

        }
    }

    grid_ = gridTmp_;

    for(int i = 0; i < getSize().first; i++) {
        for(int j = 0; j < getSize().second; j++) {
            image_.setPixel(i,j,grid_[i][j]);
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
