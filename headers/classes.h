#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\headers\classes.h"


class Cell : sf::Drawable
{
private:
	int id = 0;

public:
	sf::RectangleShape shape;

public:
	Cell(float xSize, float ySize, float xPos, float yPos);

	~Cell();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void color(int R, int G, int B);

	void move(int direction);

	
};