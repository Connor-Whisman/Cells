#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\headers\classes.h"


// WINDOW
const unsigned int SCREEN_WIDTH = 1400;
const unsigned int SCREEN_HEIGHT = 1000;
// GRID
const unsigned int ROWS = 22;
const unsigned int COLS = 34;
// CELLS FOR GRID
const float CELL_SIZE = 25.f;
const float CELL_SPACE = 7.5f;
const int INIT_POS = (CELL_SPACE * 2) + CELL_SIZE;
const int xINIT_SPACE = 10;
const int yINIT_SPACE = 10;



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