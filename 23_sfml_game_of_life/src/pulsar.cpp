#include "pulsar.h"

Pulsar::Pulsar(size_t x, size_t y):Shape(x,y){
    
}

std::vector<std::vector<bool>> Pulsar::draw(){
    std::vector<std::vector<bool>> shape(15,std::vector<bool>(15));
    shape[0] =  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    shape[1] =  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    shape[2] =  {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    shape[3] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    shape[4] =  {1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    shape[5] =  {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0};
    shape[6] =  {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    shape[7] =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    shape[8] =  {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    shape[9] =  {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0};
    shape[10] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    shape[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    shape[12] = {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    shape[13] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    shape[14] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    return shape;
}