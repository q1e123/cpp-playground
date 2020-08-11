#ifndef PULSAR_H
#define PULSAR_H

#include "shape.h"

class Pulsar : public Shape{
public:
    Pulsar(size_t x, size_t y);
    std::vector<std::vector<bool>> draw(); 
};

#endif