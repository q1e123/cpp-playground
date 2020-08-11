#ifndef PENTADECATHLON_H
#define PENTADECATHLON_H

#include "shape.h"

class Pentadecathlon : public Shape{
public:
    Pentadecathlon(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif