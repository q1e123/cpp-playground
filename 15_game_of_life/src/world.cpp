#include "world.h"

World::World(size_t epochs, size_t heigths, size_t width){
    if(width < DEFAULT_SIZE || heigth < DEFAULT_SIZE){
        std::cerr << "ERROR: choose a grid that is at least 20x20" << std::endl;
        exit(1);
    }
    this->width = width;
    this->heigth = heigths;
    this->world_epochs = epochs;

    epoch = 0;
    map = std::vector<std::vector<POPULATION_STATUS>>(heigth, std::vector<POPULATION_STATUS>(width, POPULATION_STATUS::DEAD)); 
}



std::ostream& operator<<(std::ostream& os, const World& world){
    for(auto row : world.map){
        for(auto population : row){
                os << population << " ";
        }
        os << std::endl;
    }
    return os;
}