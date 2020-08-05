#include "shape.h"
Shape::Shape(size_t x, size_t y){
    this->x = x;
    this->y = y;
}

size_t Shape::get_x(){
    return x;
}

size_t Shape::get_y(){
    return y;
}
