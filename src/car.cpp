#include "..\headers\const.h"
#include "..\headers\car.h"


Car::Car(int dir)
{
	this->direction = dir;
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	this->isActive = true;
	
	switch (this->direction)
	{
	case 0:		// NORTH MOVING SOUTH
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * (COLS / 2)) - INIT_POS, yINIT_SPACE));
		break;
	case 1:		// EAST MOVING WEST
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * COLS) - INIT_POS, yINIT_SPACE + (INIT_POS * ROWS / 2) - INIT_POS));
		break;
	case 2:		// SOUTH MOVING NORTH
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE + (INIT_POS * (COLS / 2)), yINIT_SPACE + (INIT_POS * ROWS) - INIT_POS));
		break;
	case 3:		// WEST MOVING EAST
		this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE + (INIT_POS * (ROWS / 2))));
		break;
	}
};

void Car::move() 
{
	this->currPos = this->shape.getPosition();
	
	switch (this->direction)
	{
	case 0: // N TO S
		this->currPos.y += INIT_POS;
		break;
	case 1: // E TO W
		this->currPos.x -= INIT_POS;
		break;
	case 2: // S TO N
		this->currPos.y -= INIT_POS;
		break;
	case 3: // W TO E
		this->currPos.x += INIT_POS;
		break;
	}

	this->shape.setPosition(this->currPos);
}

void Car::checkEnd()
{
	this->currPos = this->shape.getPosition();
	switch (this->direction)
	{
	case 0:
		if (this->currPos.y > yINIT_SPACE + (INIT_POS * ROWS) - INIT_POS) // SOUTH BORDER
		{
			std::cout << "Reached End Case 0" << std::endl;
			this->isActive = false;
		}
		break;
	case 1:
		if (this->currPos.x < xINIT_SPACE)
		{
			std::cout << "Reached End Case 1" << std::endl;
			this->isActive = false;
		}
		break;
	case 2:
		if (this->currPos.y < yINIT_SPACE)
		{
			std::cout << "Reached End Case 2" << std::endl;
			this->isActive = false;
		}
	case 3:
		if (this->currPos.x > xINIT_SPACE + (INIT_POS * COLS) - INIT_POS)
		{
			std::cout << "Reached End Case 3" << std::endl;
			this->isActive = false;
		}
	default:
		break;
	}

}