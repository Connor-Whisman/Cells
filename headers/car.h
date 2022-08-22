#pragma once
#include "..\headers\const.h"


class Car : public Cell
{
private:
	int direction; // RANDOM INT BETWEEN 0 - 3
	sf::Vector2f currentPos;

public:
	Car();

	void drive();
};
