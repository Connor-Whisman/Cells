#include "..\headers\const.h"
#include "..\headers\car.h"



Car::Car(int dir, int R, int G, int B)
{
	this->direction = dir;
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	this->isActive = true;
	this->color(R, G, B);
	
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

Car::Car()
{
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE));
	this->direction = 0;
	this->isActive = true;
}





Cars_Container::Cars_Container()
{
	this->nsLight = true;
	this->ewLight = !this->nsLight;
}
void Cars_Container::changeLight()
{
	this->nsLight = !this->nsLight;
	this->ewLight = !this->nsLight;
}

void Cars_Container::addCar(int dir)
{
	this->allCars.push_back(new Car(dir, 220, 30, 30));
	std::cout << "Car Added. Total = " << this->allCars.size() << std::endl;
}

void Cars_Container::drawCars(sf::RenderWindow &window)
{
	for (Car* car : this->allCars)
	{
		if (car->isActive)
		{
			window.draw(car->shape);
		}
	}
}

void Cars_Container::driveCars()
{
	// ONLY LOOP IF THERES ELEMENTS IN VECTOR
	if (this->allCars.size() > 0)
	{
		for (Car* car : this->allCars)
		{
			if (car->isActive)
			{
				car->currPos = car->shape.getPosition();

				switch (car->direction)
				{
				case 0:		// N TO S
					if (car->currPos.y > (yINIT_SPACE + (INIT_POS * ROWS) - INIT_POS) * 0.5f			&&
						car->currPos.y < (yINIT_SPACE + (INIT_POS * ROWS) + INIT_POS) * 0.5f			&&
						this->nsLight == false)																			// AT NORTH LIGHT
						break;

					car->currPos.y += INIT_POS;
					if (car->currPos.y > yINIT_SPACE + (INIT_POS * ROWS) - INIT_POS)
						car->isActive = false;
					break;

				case 1:		// E TO W
					if (car->currPos.x < xINIT_SPACE + (INIT_POS * (COLS * 0.5f)) + INIT_POS			&& 
						car->currPos.x > xINIT_SPACE + (INIT_POS * (COLS * 0.5f))						&&
						this->ewLight == false)																			// AT EAST LIGHT
						break;

					car->currPos.x -= INIT_POS;
					if (car->currPos.x < xINIT_SPACE)
						car->isActive = false;
					break;

				case 2:		// S TO N
					if (car->currPos.y < yINIT_SPACE + (INIT_POS * (ROWS * 0.5f)) + (INIT_POS * 2)		&&
						car->currPos.y > yINIT_SPACE + (INIT_POS * (ROWS * 0.5f))						&&
						this->nsLight == false)																			// AT SOUTH LIGHT
						break;

					car->currPos.y -= INIT_POS;
					if (car->currPos.y < yINIT_SPACE)
						car->isActive = false;
					break;

				case 3:		// W TO E
					if (car->currPos.x > (xINIT_SPACE + (INIT_POS * COLS)) * 0.5f + INIT_POS			&&
						car->currPos.x < (xINIT_SPACE + (INIT_POS * COLS)) * 0.5f + (INIT_POS  * 2)		&&
						this->ewLight == false)																			// AT WEST LIGHT
						break;

					car->currPos.x += INIT_POS;
					if (car->currPos.x > xINIT_SPACE + (INIT_POS * COLS) - INIT_POS)
						car->isActive = false;																		
					break;
				}

				car->shape.setPosition(car->currPos);
			}
		}
	}
}

void Cars_Container::removeCar()
{
	// ONLY LOOP IF THERES ELEMENTS IN VECTOR
	if (this->allCars.size() > 0)
	{
		std::vector<Car*>::iterator itr = this->allCars.begin();
		for (itr; itr < this->allCars.end(); ++itr) {
			// IF CURRENT CAR IS NOT ACTIVE, ERASE IT
			if (this->allCars[itr - allCars.begin()]->isActive == false)
			{
				std::cout << "Car Removed. Total = " << this->allCars.size() - 1 << std::endl;
				itr = this->allCars.erase(itr);
				break;
			}
		}
	}
}