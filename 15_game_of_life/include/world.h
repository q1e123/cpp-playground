#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>

#define DEFAULT_SIZE 20

enum POPULATION_STATUS{
    DEAD = 0,
    CONSTANT,
    DYING,
    GROWTH
};

class World{
public:
    World(size_t epochs, size_t heigth=DEFAULT_SIZE, size_t width=DEFAULT_SIZE);

   friend std::ostream& operator<<(std::ostream& os, const World& world);

private:
    size_t heigth, width, epoch, world_epochs;
    std::vector<std::vector<POPULATION_STATUS>> map;
    
};

#endif