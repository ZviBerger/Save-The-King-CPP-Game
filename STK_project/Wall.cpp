#include "Wall.h"


Wall::Wall(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:StaticObj(texture, position, size)
{
	setColor();
	
	
}


Wall::~Wall()
{
}

//===============================================================
//sets wall color
void Wall::setColor()
{
	int color = random(3);
	switch (color)
	{
	case 0:
		setFColor(sf::Color::Color(47, 79, 79, 255));
		break;
	case 1:
		setFColor(sf::Color::White);
		break;
	case 2:
		setFColor(sf::Color::Blue);
		break;
	default:
		break;
	}
}
