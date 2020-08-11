#include "glider.h"

Glider::Glider(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Glider::draw(){
    std::vector<std::vector<bool>> shape(3,std::vector<bool>(3));
    shape[0] = {0, 1, 0};
    shape[1] = {0, 0, 1};
    shape[2] = {1, 1, 1};
    return shape;
}