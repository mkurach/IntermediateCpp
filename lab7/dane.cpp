#include "dane.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

Dane::Dane(const char* name) {

    std::ifstream file(name);
    double x, y;
    while(file>>x && file>>y) {
        x_.push_back(x);
        y_.push_back(y);
    }
    
    minX_ = *std::min_element(x_.begin(),x_.end());
    minY_ = *std::min_element(y_.begin(),y_.end());

    
    maxX_ = *std::max_element(x_.begin(),x_.end());
    maxY_ = *std::max_element(y_.begin(),y_.end());


}
Dane::~Dane() {}



std::vector<double>& Dane::getX() {
    return x_;
}
std::vector<double>&  Dane::getY() {
    return y_;

}

double Dane::getMinX() {
    return minX_;
}
double Dane::getMinY() {
    return minY_;
}
double Dane::getMaxX(){
    return maxX_;
}
double Dane::getMaxY() {
    return maxY_;
}
