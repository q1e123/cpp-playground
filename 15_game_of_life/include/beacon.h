#ifndef BEACON_H
#define BEACON_H

#include "shape.h"

class Beacon : public Shape{
public:
    Beacon(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif