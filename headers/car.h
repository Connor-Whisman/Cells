#pragma once
#include "..\headers\const.h"


class Car : public Cell
{
private:
	 // RANDOM INT BETWEEN 0 - 3
	

public:
	int direction;

	bool isActive;

	Car(int dir, int R, int G, int B);

	Car();

	void move();

};



class Cars_Container : public Car
{
private:
	bool nsLight;
	bool ewLight;

public:
	std::vector<Car*> allCars;

	Cars_Container();

	void addCar(int dir);
	void driveCars();
	
	void drawCars(sf::RenderWindow &window);
	bool checkCollisions(Car* car);
	void removeCar();
	void changeLight();
};