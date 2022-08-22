#include "..\headers\const.h"




Cell::Cell(float xSize, float ySize, float xPos, float yPos)
{
	this->shape.setSize(sf::Vector2f(xSize, ySize));
	this->shape.setPosition(sf::Vector2f(xPos, yPos));
}

Cell::Cell()
{
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE));
}

Cell::~Cell()
{
	// FIND OUT IF DESTRUCTOR NEEDS TO BE CUSTOMIZED
}



void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shape);
}


void Cell::color(int R, int G, int B)
{
	this->shape.setFillColor(sf::Color(R, G, B));
}


void Cell::move(int direction)
{
	sf::Vector2f currentPos = this->shape.getPosition();
	float moveDistance = INIT_POS;

	switch (direction)
	{
	case 0: // N
		currentPos.y -= moveDistance;
		break;
	case 1: // E
		currentPos.x += moveDistance;
		break;
	case 2: // S
		currentPos.y += moveDistance;
		break;
	case 3: // W
		currentPos.x -= moveDistance;
		break;
	}
	this->shape.setPosition(currentPos);
}

