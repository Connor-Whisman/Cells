#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\headers\classes.h"
#include <vector>


const unsigned int SCREEN_WIDTH = 1400;
const unsigned int SCREEN_HEIGHT = 1000;

const unsigned int ROWS = 12;
const unsigned int COLS = 8;

const float CELL_SIZE = 25.f;
const float CELL_SPACE = 50.f;
const int INIT_POS = (CELL_SPACE * 2) + CELL_SIZE;
const int xINIT_SPACE = 55;
const int yINIT_SPACE = 15;

int main()
{
	// INIT WINDOW AND VARIABLES FOR CALCULATING FPS
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TESTING");
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	float fps;

	window.setFramerateLimit(60);

	// DECLARE SINGLE OBJECT
	// Cell cellOne(100.f, 35.f, 250.f, 250.f);
	Cell activeCell(CELL_SIZE, CELL_SIZE, INIT_POS + xINIT_SPACE, INIT_POS + yINIT_SPACE);
	activeCell.color(222, 30, 30);

	// ONE DIMENSIONAL VECTOR OF CELLS
	std::vector<Cell> cellVec;
	// LOOP OVER SCREEN AND ADD CELLS TO VECTOR
	for (int x = 0; x < ROWS; x += 1)
	{
		for (int y = 0; y < COLS; y += 1)
		{
			Cell cell(CELL_SIZE, CELL_SIZE, x * INIT_POS + xINIT_SPACE, y * INIT_POS + yINIT_SPACE);
			cell.color(120, 150, 35);
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


		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		//{
		//	
		//	activeCell.move(1);
		//	
		//}


		// INIT EVENTS
		sf::Event event;
		// CHECK FOR EVENTS
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				// MOVE
				case sf::Keyboard::W:	// N
					activeCell.move(0);
					break;
				case sf::Keyboard::D:	// E
					activeCell.move(1);
					break;
				case sf::Keyboard::S:	// S
					activeCell.move(2);
					break;
				case sf::Keyboard::A:	// W
					activeCell.move(3);
					break;
				default:
					break;
				}
			default:
				break;
			}
		}

		// CLEAR WINDOW, UPDATE ALL LOGIC, AND FINALLY DISPLAY
		window.clear();


		// LOOP THROUGH ONE-DIMENSIONAL VECTOR OF CELL OBJECTS
		float iC = 0;
		for (Cell cell : cellVec)
		{
			iC += 10;
			//cell.shape.setRotation(iC);
			window.draw(cell.shape);
			//cell.draw(window);
		}
		// DRAW ACTIVE CELL ON TOP OF GRID
		window.draw(activeCell.shape);



		window.display();

	}

	return 0;
}