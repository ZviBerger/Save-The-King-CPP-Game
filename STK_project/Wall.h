#pragma once
#include "StaticObj.h"
class Wall :public StaticObj
{
public:
	Wall(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	~Wall();

private:


	void setColor();
};

