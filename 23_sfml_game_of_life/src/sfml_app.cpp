#include "sfml_app.h"

#include <iostream>
#include <thread>
#include <sstream>
#include <array>

#include "shape.h"
#include "block.h"
#include "boat.h"
#include "blinker.h"
#include "beacon.h"
#include "pulsar.h"
#include "pentadecathlon.h"
#include "glider.h"
#include "SimpleIni.h"


SfmlApp::SfmlApp(
	std::pair<unsigned int, unsigned int> window_size,
	std::pair<unsigned int, unsigned int> cell_size
)
	: window_({ window_size.first, window_size.second }, "My window")
	, cell_size_(cell_size)
{
	current_epoch = 0;
}

SfmlApp::~SfmlApp()
{
}

std::string getMessageForActiveStatus(bool active)
{
	if (active)
	{
		return "Simulation is ACTIVE. Press <SPACE> to toggle the simulation. Press <ESC> to exit.";
	}

	return "Simulation is PAUSED. Press <SPACE> to toggle the simulation. Press <ESC> to exit.";
}

void SfmlApp::init()
{
	CSimpleIniA ini;
	if (ini.LoadFile("../../data/23_sfml_game_of_life.ini") < 0) {
		std::cerr << "Can't open file" << std::endl;
		exit(1);
	}
	std::string living_cell_color_string = ini.GetValue("graphics", "living_cell_color_");
	std::string dead_cell_color_string = ini.GetValue("graphics", "dead_cell_color_");

    std::istringstream iss_living_cell(living_cell_color_string);
    std::string amount_string;    
	std::array<size_t, 3> color_living;
	size_t i = 0;
    while (getline(iss_living_cell, amount_string, ',')) {
       color_living[i] = std::stol(amount_string);
		++i;
    }
	std::istringstream iss_dead_cell(dead_cell_color_string);
	std::array<size_t, 3> color_dead;
	i = 0;
    while (getline(iss_dead_cell, amount_string, ',')) {
		color_dead[i] = std::stol(amount_string);
		++i;
    }
	this->living_cell_color_ = sf::Color(color_living[0], color_living[1], color_living[2]);
	this->dead_cell_color_ = sf::Color(color_dead[0], color_dead[1], color_dead[2]);

	if (font_.loadFromFile("../../data/OpenSans-Regular.ttf"))
	{
		gui_text_.setFont(font_);
		gui_text_.setString(getMessageForActiveStatus(true));
		gui_text_.move(10, 2);
		gui_text_.setCharacterSize(24);
		gui_text_.setOutlineColor(sf::Color::White);

		epoch_text.setFont(font_);
		epoch_text.setString("Waiting to start");
		epoch_text.move(10, 30);
		epoch_text.setCharacterSize(12);
		epoch_text.setOutlineColor(sf::Color::White);
	}
	else
	{
		// error...cannot render GUI
	}

	// Note: you can also override the window size after it is initialized.
	// This could be useful to allow changing the resolution and the world size after the initialization
	// but is not really a priority for this exercise.
	//this->window.setSize(sf::Vector2u(1200, 600));

	// Initialize the vertices
	size_t max_width = static_cast<size_t>(window_.getView().getSize().x);
	size_t max_height = static_cast<size_t>(window_.getView().getSize().y);

	// Store the world size for later use.
	std::string epochs_str = ini.GetValue("world", "epochs");
	if(epochs_str == "inf"){
		epochs = -1;
	}else{
	 	epochs = std::stol(epochs_str); 
	}
	size_t size_x = std::stol(ini.GetValue("world", "size_x"));
	size_t size_y = std::stol(ini.GetValue("world", "size_y"));
	duration_in_millis_between_updates = std::stol(ini.GetValue("graphics", "duration_in_millis_between_updates"));


	world_size_.first = size_x;
	world_size_.second = size_y;

	std::cout <<world_size_.first << " " << world_size_.second << std::endl;
	world = new World(25,world_size_.first, world_size_.second);

	Glider *glider = new Glider(2,2);

	std::vector<Shape*> shapes;

	CSimpleIniA::TNamesDepend keys;
	ini.GetAllKeys("initial_state", keys);

	for(auto key:keys){
		Shape *shape;
		size_t x,y;
		std::string shape_str = key.pItem;
		std::string pos = ini.GetValue("initial_state", key.pItem);
		std::istringstream iss_pos(pos);
		std::string tmp_str;
		iss_pos >> tmp_str;
		x = std::stol(tmp_str);
		iss_pos >> tmp_str;
		y = std::stol(tmp_str);

		if(shape_str == "beacon"){
			shape = new Beacon(x,y);
		}else if(shape_str == "blinker"){
			shape = new Blinker(x,y);
		}else if(shape_str == "block"){
			shape = new Block(x,y);
		}else if(shape_str == "boat"){
			shape = new Boat(x,y);
		}else if(shape_str == "glider"){
			shape = new Glider(x,y);
		}else if(shape_str == "pentadecathlon"){
			shape = new Pentadecathlon(x,y);
		}else if(shape_str == "pulsar"){
			shape = new Pulsar(x,y);
		}

		shapes.push_back(shape);
	}

	for(auto shape : shapes){
		world->draw(shape);
	}
	
	// Initialize the world map with vertices.
	for (size_t cell_y = 0; cell_y < max_height / cell_size_.first - 1; cell_y++)
	{
		for (size_t cell_x = 0; cell_x < max_width / cell_size_.second - 1; cell_x++)
		{
			this->addVertexQuad(cell_x, cell_y, cell_size_.first, cell_size_.second);
		}
	}
}

void SfmlApp::run()
{
	unsigned time_elapsed_since_update = 0;
	bool simulation_active(true);
	// TODO: it would be nice to make this configurable in the future.

	// run the program as long as the window is open
	while (window_.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window_.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window_.close();
			}

			// quick close via the ESC key.
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window_.close();
					return;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					// Toggle simulation
					simulation_active = !simulation_active;
					gui_text_.setString(getMessageForActiveStatus(simulation_active));
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					size_t view_width = static_cast<size_t>(window_.getView().getSize().x);
					size_t view_height = static_cast<size_t>(window_.getView().getSize().y);
					size_t win_width = static_cast<size_t>(window_.getSize().x);
					size_t win_height = static_cast<size_t>(window_.getSize().y);

					unsigned clicked_cell_x = event.mouseButton.x * view_width / (cell_size_.first * win_width);
					unsigned clicked_cell_y = event.mouseButton.y * view_height / (cell_size_.second * win_height);

					world->set_cell(clicked_cell_x,clicked_cell_y);
					setCellColor(clicked_cell_x, clicked_cell_y, living_cell_color_);
				}
			}
		}

		if (time_elapsed_since_update > duration_in_millis_between_updates)
		{
			updateWorld();
			time_elapsed_since_update -= duration_in_millis_between_updates;
		}

		// clear the window with black color
		window_.clear(sf::Color::Black);

		render();

		// end the current frame
		window_.display();

		// don't consume too many cpu cycles
		std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(10));
		if (simulation_active)
		{
			time_elapsed_since_update += 10;
		}
	}
}

void SfmlApp::setCellColor(unsigned cell_x, unsigned cell_y, sf::Color color)
{
	auto index = (cell_y * this->world_size_.first + cell_x) * 4;
	if (index >= cell_vertices_.size())
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		cell_vertices_[index + i].color = color;
	}
}

void SfmlApp::addVertexQuad(unsigned cell_x, unsigned cell_y, unsigned width, unsigned height)
{
	sf::Vertex topLeft;
	sf::Vertex topRight;
	sf::Vertex bottomLeft;
	sf::Vertex bottomRight;

	float pixel_x = static_cast<float>(cell_x * width);
	float pixel_y = static_cast<float>(cell_y * height);

	topLeft.position = { pixel_x,			 pixel_y };
	topRight.position = { pixel_x + width,   pixel_y };
	bottomLeft.position = { pixel_x,           pixel_y + height };
	bottomRight.position = { pixel_x + width,   pixel_y + height };

	topLeft.color = dead_cell_color_;
	topRight.color = dead_cell_color_;
	bottomLeft.color = dead_cell_color_;
	bottomRight.color = dead_cell_color_;

	cell_vertices_.push_back(topLeft);
	cell_vertices_.push_back(bottomLeft);
	cell_vertices_.push_back(bottomRight);
	cell_vertices_.push_back(topRight);
}

void SfmlApp::render()
{
	// draw everything here...
	window_.draw(cell_vertices_.data(), cell_vertices_.size(), sf::Quads);

	// Add any GUI info.
	window_.draw(gui_text_);
	window_.draw(epoch_text);
}

void SfmlApp::updateWorld()
{
	if(epochs < 0 || current_epoch <= epochs){
		world->next_generation();
		std::vector<std::vector<bool>> map = world->get_map();
		for(size_t i = 0; i < world_size_.first; ++i){
			for(size_t j = 0; j < world_size_.second; ++j){
				if(map[i][j]){
					setCellColor(i, j + OFFSET, living_cell_color_);
				}else{
					setCellColor(i, j + OFFSET, dead_cell_color_);
				}
			}
			std::string end;
			if(epochs < 0){
				end = "inf";
			}else{
				end = std::to_string(epochs);
			}
			std::string epoch_string = "Epoch " + std::to_string(current_epoch) + "/ " + end;
			epoch_text.setString(epoch_string);

		}
		++current_epoch;
	}
	
}