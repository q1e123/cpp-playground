#include "block.h"
#include <iostream>
Block::Block(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Block::draw(){
    std::vector<std::vector<bool>> shape(2,std::vector<bool>(2));
    for(size_t i = 0; i < shape.size(); ++i){
        for(size_t j = 0; j < shape[i].size(); ++j){
            shape[i][j] = true;
        }
    }
    return shape;
}