#include "..\headers\const.h"
#include "..\headers\car.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>


int getRandom(int max)
{
	srand(time(NULL));
	return rand() % (max + 1);
}


Car::Car() {
	this->direction = getRandom(3);
	//this->direction = 3;

	//this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE));
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	
	switch (this->direction)
	{
	case 0:		// MOVING NORTH
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * (COLS / 2)), yINIT_SPACE + (INIT_POS * ROWS) - INIT_POS));
		std::cout << "Case 0" << std::endl;
		break;
	case 1:		// MOVING EAST
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE + (INIT_POS * (ROWS / 2))));
		std::cout << "Case 1" << std::endl;
		break;
	case 2:		// MOVING SOUTH
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * (COLS / 2)) - INIT_POS, yINIT_SPACE));
		std::cout << "Case 2" << std::endl;
		break;
	case 3:		// MOVING WEST
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * COLS) - INIT_POS, yINIT_SPACE + (INIT_POS * ROWS / 2) - INIT_POS));
		std::cout << "Case 3" << std::endl;
		break;
	default:
		std::cout << this->direction << std::endl;
		break;
	}
};

void Car::drive() {
	this->currentPos = this->shape.getPosition();
	float moveDistance = INIT_POS;

	
	switch (this->direction)
	{
	case 0: // N
		this->currentPos.y -= moveDistance;
		std::cout << this->direction;
		break;
	case 1: // E
		this->currentPos.x += moveDistance;
		std::cout << this->direction;
		break;
	case 2: // S
		this->currentPos.y += moveDistance;
		std::cout << this->direction;
		break;
	case 3: // W
		this->currentPos.x -= moveDistance;
		std::cout << this->direction;
		break;
	}

	this->shape.setPosition(currentPos);
}