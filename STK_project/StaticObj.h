#pragma once
#include "GameObject.h"


class StaticObj :protected GameObject
{
public:
	using GameObject::GameObject;
	virtual ~StaticObj();
	virtual void draw(sf::RenderWindow &window);
};

