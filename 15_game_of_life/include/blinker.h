#ifndef BLINKER_H
#define BLINKER_H

#include "shape.h"

class Blinker : public Shape{
public:
    Blinker(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif