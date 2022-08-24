#include "..\headers\const.h"




Cell::Cell(float xSize, float ySize, float xPos, float yPos)
{
	this->shape.setSize(sf::Vector2f(xSize, ySize));
	this->shape.setPosition(sf::Vector2f(xPos, yPos));
	this->direction = 0;
}

Cell::Cell()
{
	this->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	this->shape.setPosition(sf::Vector2f(xINIT_SPACE, yINIT_SPACE));
	this->direction = 0;
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


void Cell::move()
{
	this->currPos = this->shape.getPosition();

	switch (this->direction)
	{
	case 0: // N
		this->currPos.y -= INIT_POS;
		break;
	case 1: // E
		this->currPos.x += INIT_POS;
		break;
	case 2: // S
		this->currPos.y += INIT_POS;
		break;
	case 3: // W
		this->currPos.x -= INIT_POS;
		break;
	}
	this->shape.setPosition(this->currPos);
}

void Cell::switchDir(int direction)
{
	this->direction = direction;
}
