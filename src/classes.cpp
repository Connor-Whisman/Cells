#include "..\headers\classes.h"



Cell::Cell(float xSize = 25.f, float ySize = 25.f, float xPos = 0.f, float yPos = 0.f)
{
	this->id++;
	this->shape.setSize(sf::Vector2f(xSize, ySize));
	this->shape.setPosition(sf::Vector2f(xPos, yPos));
	std::cout << "Cell ID: " << this->id << "Created." << std::endl;
}

Cell::~Cell()
{
	// CHECK IF THIS IS CORRECT
	//delete(this);
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
	float moveDistance = 125;
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

