#include <iostream>
#include <string>
#include <vector>

#include "world.h"
#include "shape.h"
#include "block.h"
#include "boat.h"
#include "blinker.h"
#include "beacon.h"
#include "pulsar.h"
#include "pentadecathlon.h"
#include "glider.h"


int main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cerr << "Usage: ./15_game_of_life <epochs> <heigth> <width> [-a]" << std::endl;
		exit(1);
	}
	
	size_t heigth, width, epochs;
	epochs = std::stol(argv[1]);
	heigth = std::stol(argv[2]);
	width = std::stol(argv[3]);
	bool animation = false;
	if(argc == 5 && std::string(argv[4]) == "-a"){
		animation = true;
	}

	World world(epochs, heigth, width);

	Block *block = new Block(0,0);
	Boat *boat = new Boat(15,3);
	Blinker *blinker = new Blinker(22, 7);
	Beacon *beacon = new Beacon(4, 5);
	Pulsar *pulsar = new Pulsar(30,20);
	Pentadecathlon *pentadecathlon = new Pentadecathlon(35, 5);
	Glider *glider = new Glider(7,7);

	std::vector<Shape*> shapes;
	shapes.push_back(block);
	shapes.push_back(boat);
	shapes.push_back(blinker);
	shapes.push_back(beacon);
	shapes.push_back(pulsar);
	shapes.push_back(pentadecathlon);
	shapes.push_back(glider);

	for(auto shape : shapes){
		world.draw(shape);
	}
	
	world.play(animation);
	return 0;
}
