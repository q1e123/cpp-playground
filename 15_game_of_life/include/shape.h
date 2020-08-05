#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

class Shape{
public:
    Shape(size_t x, size_t y);

    size_t get_x();
    size_t get_y();
    // One should never try to draw an abstract shape
    virtual std::vector<std::vector<bool>> draw() = 0; 
protected:
    size_t x, y;
};

#endif