#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>

#include "shape.h"
#include "block.h"
#define DEFAULT_SIZE 20

enum Population_Status{
    DYING,
    CONSTANT,
    GROWING
};
class World{
public:
    World(size_t epochs, size_t heigth=DEFAULT_SIZE, size_t width=DEFAULT_SIZE);

    void play();
    void draw(Shape *shape);
    friend std::ostream& operator<<(std::ostream& os, const World& world);

private:
    size_t heigth, width, epochs;
    std::vector<std::vector<bool>> map;

    void next_generation();
    size_t get_alive_neighbours(size_t row, size_t column);
    void make_transition(size_t row, size_t column);    
    Population_Status get_status(size_t row, size_t column);
};

#endif