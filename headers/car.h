#pragma once
#include "..\headers\const.h"


class Car : public Cell
{
private:
	int direction; // RANDOM INT BETWEEN 0 - 3
	

public:
	
	bool isActive;

	Car(int dir, int R, int G, int B);

	void move();

};
