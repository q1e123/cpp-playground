#ifndef BOAT_H
#define BOAT_H

#include "shape.h"

class Boat : public Shape{
public:
    Boat(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif