#ifndef BLOCK_H
#define BLOCK_H

#include "shape.h"

class Block : public Shape{
public:
    Block(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif