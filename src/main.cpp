#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\headers\classes.h"
#include <vector>


const unsigned int SCREEN_WIDTH = 1200;
const unsigned int SCREEN_HEIGHT = 800;

const unsigned int rows = 12;
const unsigned int cols = 8;


int main()
{
	// INIT WINDOW AND VARIABLES FOR CALCULATING FPS
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TESTING");
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	float fps;

	// DECLARE SINGLE OBJECT
	// Cell cellOne(100.f, 35.f, 250.f, 250.f);


	// ONE DIMENSIONAL VECTOR OF CELLS
	std::vector<Cell> cellVec;
	// LOOP OVER SCREEN AND ADD CELLS TO VECTOR
	for (int x = 0; x < rows; x += 1)
	{
		for (int y = 0; y < cols; y += 1)
		{
			Cell cell(25.f, 25.f, (x * 100) + 30, (y * 100) + 30);
			cell.shape.setFillColor(sf::Color(120, 150, 35));
			cellVec.push_back(cell);
		}
	}


	while (window.isOpen())
	{
		// CALCULATING FPS
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		std::cout << fps << std::endl;
		previousTime = currentTime;

		// INIT EVENTS
		sf::Event event;

		// CHECK FOR EVENTS
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// CLEAR WINDOW, UPDATE ALL LOGIC, AND FINALLY DISPLAY
		window.clear();

		// SINGLE OBJECT FUNCTIONS
		//cellOne.move(0);
		//window.draw(cellOne.shape);


		// LOOP THROUGH ONE-DIMENSIONAL VECTOR OF CELL OBJECTS
		float iC = 0;
		for (Cell cell : cellVec)
		{
			iC += 10;
			//cell.shape.setRotation(iC);
			window.draw(cell.shape);
		}




		window.display();

	}

	return 0;
}