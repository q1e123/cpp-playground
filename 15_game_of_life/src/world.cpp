#include "world.h"

World::World(size_t epochs, size_t heigths, size_t width){
    if(width < DEFAULT_SIZE || heigth < DEFAULT_SIZE){
        std::cerr << "ERROR: choose a grid that is at least 20x20" << std::endl;
        exit(1);
    }

    this->epochs = epochs;
    this->heigth = heigths;
    this->width = width;

    std::cout << epochs << " " << heigth <<"x" <<width <<std::endl;
    
    map = std::vector<std::vector<bool>>(heigth, std::vector<bool>(width,false)); 
}

void World::play(){
    std::cout << "Initial state of world: " << std::endl;
    std::cout << *this << std::endl;

    for (size_t i= 0; i < epochs; ++i)
    {
        std::cout << "Epoch " << i << "/" << epochs << ": " << std::endl;
        next_generation();
        std::cout << *this << std::endl;
    }
    
}

void World::next_generation(){
    for(size_t i = 0; i < heigth; ++i){
        for(size_t j = 0; j < width; ++j){
            make_transition(i,j);
        }
    }
}

void World::make_transition(size_t row, size_t column){
    Population_Status status = get_status(row,column);
    switch (status){
        case Population_Status::DYING:
            map[row][column] = 0;
            return;
        case Population_Status::GROWING:
            map[row][column] = 1;
            return;
        // constant population
        default:
            return;
    }
}

Population_Status World::get_status(size_t row, size_t column){
    size_t alive_neighbours = get_alive_neighbours(row, column);
    
    /// population is alive
    if(map[row][column]){
        if(alive_neighbours < 2 || alive_neighbours > 3){
            return Population_Status::DYING;
        }
        return Population_Status::CONSTANT;
    }
    // population is dead
    if(alive_neighbours == 3){
        return Population_Status::GROWING;
    }

    // population is dead and is not growing
    return CONSTANT;
}

size_t World::get_alive_neighbours(size_t row, size_t column){
    size_t alive_neighbours = 0; 
    for (size_t i = -1; i <= 1; ++i){
        for (size_t j = -1; j <= 1; ++j){
            alive_neighbours += map[row + i][column + j];
        } 
    } 

    // I've skipped doing the if in the fors so the population it self was added to the neighbours
    // and now I need to take it out
    alive_neighbours -= map[row][column];
    return alive_neighbours;
}

std::ostream& operator<<(std::ostream& os, const World& world){
    for(size_t i = 0; i < world.heigth; ++i){
        for(size_t j = 0; j < world.width; ++j){
            os << world.map[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}