#include <iostream>
#include <string>

#include "world.h"
#include "shape.h"
#include "block.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./15_game_of_life <epochs> <heigth> <width>" << std::endl;
		exit(1);
	}
	
	size_t heigth, width, epochs;
	epochs = std::stol(argv[1]);
	heigth = std::stol(argv[2]);
	width = std::stol(argv[3]);
	World world(epochs, heigth, width);
	Block *block = new Block(0,0);
	world.draw(block);
	world.play();
	return 0;
}
