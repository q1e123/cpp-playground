#include "pentadecathlon.h"
#include <iostream>
Pentadecathlon::Pentadecathlon(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Pentadecathlon::draw(){
    std::vector<std::vector<bool>> shape(3,std::vector<bool>(10));
    shape[0] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
    shape[1] = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    shape[2] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
    return shape;
}