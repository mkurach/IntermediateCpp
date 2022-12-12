#include "grid.hpp"
#include <time.h>
#include <cstdlib>
#include <math.h>

Grid::Grid(int x, int y) {

    size_ = std::make_pair(x,y);
    image_.create(x,y);
    heatTransf_ = 0.25;
    tMax_ = 100;
    sprayRadius_ = 0;
    color_ = 'R';

    //initialize temperatures and colors
    std::vector<std::vector<double>> vec( x, std::vector<double> (y, -tMax_));
    temp_ = vec;


    srand(time(0));
    
    int xS = rand()%x;
    int yS = rand()%y;
    int r = x < y ? x/10 : y/10;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if( (i-xS)*(i-xS) + (j-yS)*(j-yS) < r*r)
                temp_[i][j] = tMax_;
            image_.setPixel(i,j,makeCol(temp_[i][j]));
        }
    }
    tempTmp_ = temp_;

}

sf::Color Grid::makeCol(double t) {
    sf::Color col(0,0,0);
    switch(color_) {
        case 'R':
            col.r = (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        case 'O':
            col.b = (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        case 'G':
            col.g = (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        case 'Y':
            col.g = 225;
            col.r = 225;
            col.b = 255 - (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        case 'V':
            col.r = 255;
            col.b = 255;
            col.g = 255 - (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        case 'C':
            col.g = 255;
            col.b = 255;
            col.r = 255 - (int)(1/(1+exp(-t*2.0/tMax_))*255);
            break;
        
    }

    return col;
}

void Grid::setColor(char i) {
    color_ = i;
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

            tempTmp_[x][y] -= heatTransf_*deltaT;
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

void Grid::spray(int x, int y, int lr) {
    int r = getSize().first < getSize().second  ? getSize().first /10 + sprayRadius_ : getSize().second /10 + sprayRadius_;
    for(int i = 0; i < getSize().first; i++) {
        for(int j = 0; j < getSize().second; j++) {
            if( (i-x)*(i-x) + (j-y)*(j-y) < r*r) {
                if (lr == 0)
                    temp_[i][j] = tMax_;
                if (lr == 1)
                    temp_[i][j] = -tMax_;
            }
                
        }
    }
    tempTmp_ = temp_;
    updateImage();
}

void Grid::addSpray(int i) {
    sprayRadius_ += i;
}


Grid::~Grid() {
}

std::pair<int,int> Grid::getSize() {
    return size_;
}

sf::Image Grid::getImage() {
    return image_;
}

void Grid::printMenu() {
    std::cout<<"Instrukcja obslugi: "<<std::endl;
    std::cout<<"Lewy przycisk myszki - dodaj ciepelko "<<std::endl;
    std::cout<<"Prawy przycisk myszki - zabierz ciepelko "<<std::endl;
    std::cout<<"Scroll - zmieniaj promien 'spraya' "<<std::endl;
    std::cout<<"R - czerwony"<<std::endl;
    std::cout<<"G - zielony "<<std::endl;
    std::cout<<"O - niebieski "<<std::endl;
    std::cout<<"Y - żółty "<<std::endl;
    std::cout<<"C - cyan "<<std::endl;
    std::cout<<"V - violet "<<std::endl;

}
