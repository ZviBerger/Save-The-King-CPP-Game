#include "StaticObj.h"




StaticObj::~StaticObj()
{
}

void StaticObj::draw(sf::RenderWindow & window)
{
	GameObject::draw(window);
}
