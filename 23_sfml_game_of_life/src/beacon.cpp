#include "beacon.h"
Beacon::Beacon(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Beacon::draw(){
    std::vector<std::vector<bool>> shape(4,std::vector<bool>(4));
    shape[0] = {1, 1, 0, 0};
    shape[1] = {1, 0, 0, 0};
    shape[2] = {0, 0, 0, 1};
    shape[3] = {0, 0, 1, 1};
    return shape;
}