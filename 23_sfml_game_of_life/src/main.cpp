
#include "SFML/Graphics.hpp"

#include "sfml_app.h"

#include "SimpleIni.h"

#ifdef _WIN32
#include <windows.h>
#endif

void hide_console()
{
#ifdef _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif
}

int main()
{
	hide_console();

	CSimpleIniA ini;
	if (ini.LoadFile("../../data/23_sfml_game_of_life.ini") < 0) {
		std::cerr << "Can't open file" << std::endl;
		exit(1);
	}
	
	size_t preferred_window_size_x = std::stol(ini.GetValue("graphics", "preferred_window_size_x")); 
	size_t preferred_window_size_y = std::stol(ini.GetValue("graphics", "preferred_window_size_y"));
	size_t cell_size_x = std::stol(ini.GetValue("graphics", "cell_size_x")); 
	size_t cell_size_y = std::stol(ini.GetValue("graphics", "cell_size_y"));

	std::pair<unsigned int, unsigned int> preferred_window_size;
	preferred_window_size.first = preferred_window_size_x;
	preferred_window_size.second = preferred_window_size_y;

	std::pair<unsigned int, unsigned int> preferred_cell_size;
	preferred_cell_size.first = cell_size_x;
	preferred_cell_size.second = cell_size_y;

	SfmlApp app(preferred_window_size, preferred_cell_size);
	app.init();
	app.run();
}