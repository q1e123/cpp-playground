#include <iostream>
#include <string>

#include "world.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./15_game_of_life <heigth> <width> <epochs>" << std::endl;
		exit(1);
	}
	
	size_t heigth, width, epochs;
	epochs = std::stol(argv[1]);
	heigth = std::stol(argv[2]);
	width = std::stol(argv[3]);
	World world(epochs, heigth, width);
	world.play();
	return 0;
}
