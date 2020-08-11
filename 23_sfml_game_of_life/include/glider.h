#ifndef GLIDER_H
#define GLIDER_H

#include "shape.h"

class Glider : public Shape{
public:
    Glider(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif