#include "block.h"

Block::Block(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Block::draw(){
    std::vector<std::vector<bool>> shape(2,std::vector<bool>(2));
    shape[0] = {1, 1};
    shape[1] = {1, 1};
    return shape;
}