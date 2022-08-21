#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\headers\classes.h"


class Cell : sf::Drawable
{
public:
	sf::RectangleShape shape;
public:
	Cell(float xSize, float ySize, float xPos, float yPos);
	~Cell();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void move(int direction);

	
};