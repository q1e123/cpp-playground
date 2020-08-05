#include "boat.h"

Boat::Boat(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Boat::draw(){
    std::vector<std::vector<bool>> shape(3,std::vector<bool>(3));
    shape[0] = {1, 1, 0};
    shape[1] = {1, 0, 1};
    shape[2] = {0, 1, 0};
    return shape;
}