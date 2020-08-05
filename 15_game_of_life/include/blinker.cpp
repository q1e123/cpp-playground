#include "blinker.h"
#include <iostream>
Blinker::Blinker(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Blinker::draw(){
    std::vector<std::vector<bool>> shape(1,std::vector<bool>(3));
    shape[0] = {1, 1, 1};
    return shape;
}