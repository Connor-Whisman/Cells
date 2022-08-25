#pragma once
#include "..\headers\const.h"



class Cell : sf::Drawable
{
private:
	int direction;

public:
	sf::RectangleShape shape;
	sf::Vector2f currPos;

public:
	Cell(float xSize, float ySize, float xPos, float yPos);
	Cell();
	~Cell();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void color(int R, int G, int B);

	void move();

	void switchDir(int direction);
};


